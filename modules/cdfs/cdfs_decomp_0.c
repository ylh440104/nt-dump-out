
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_140008028;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140008028;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140008040,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400010cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== CdFreePool @ 1400010e0 =====

void CdFreePool(longlong *param_1)

{
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0);
    *param_1 = 0;
  }
  return;
}



===== CdRaiseStatusEx @ 140001110 =====

void CdRaiseStatusEx(longlong param_1,undefined4 param_2,char param_3,int param_4,uint param_5)

{
  if (param_3 != '\0') {
    param_2 = FsRtlNormalizeNtstatus(param_2,0xc00000e9);
  }
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(uint *)(param_1 + 0x1c) = param_4 << 0x10 | param_5;
                    /* WARNING: Subroutine does not return */
  ExRaiseStatus(param_2);
}



===== CdCompleteRequest @ 14000115c =====

void CdCompleteRequest(undefined8 *param_1,longlong param_2,uint param_3)

{
  if (param_1 != (undefined8 *)0x0) {
    CdCleanupIrpContext(param_1,'\0');
  }
  if (param_2 != 0) {
    if (((param_3 & 0xc0000000) == 0xc0000000) && ((*(uint *)(param_2 + 0x10) & 0x40) != 0)) {
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    *(uint *)(param_2 + 0x30) = param_3;
    IofCompleteRequest(param_2,1);
  }
  return;
}



===== CdExceptionFilter @ 1400011bc =====

undefined8 CdExceptionFilter(longlong param_1,longlong *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  piVar1 = (int *)*param_2;
  iVar3 = *piVar1;
  if ((iVar3 == -0x3ffffffa) && (2 < (uint)piVar1[6])) {
    iVar3 = piVar1[0xc];
  }
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x18) != 0) {
      return 1;
    }
    *(int *)(param_1 + 0x18) = iVar3;
  }
  cVar2 = FsRtlIsNtstatusExpected();
  if (cVar2 == '\0') {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x26,0x40264,*param_2,param_2[1],*(undefined8 *)(*param_2 + 0x10));
  }
  return 1;
}



===== CdFsdDispatch @ 140001240 =====

uint CdFsdDispatch(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  ushort *puVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar4 = (ushort *)0x0;
  KeEnterCriticalRegion();
  do {
    if (puVar4 == (ushort *)0x0) {
      if (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) == 0) {
        cVar2 = '\x01';
      }
      else {
        cVar2 = IoIsOperationSynchronous(param_2);
      }
      puVar4 = (ushort *)CdCreateIrpContext(param_2,cVar2);
      CdSetThreadContext((longlong)puVar4,(undefined4 *)&local_28);
    }
    else {
      *(uint *)(puVar4 + 0x10) = *(uint *)(puVar4 + 0x10) | 2;
      CdCleanupIrpContext((undefined8 *)puVar4,'\0');
    }
    bVar1 = (byte)puVar4[0x20];
    if (bVar1 < 0xd) {
      if (bVar1 == 0xc) {
        uVar3 = CdCommonDirControl((undefined8 *)puVar4,param_2);
      }
      else if (bVar1 == 0) {
        uVar6 = CdCommonCreate(puVar4,param_2);
        uVar3 = (uint)uVar6;
      }
      else if (bVar1 == 2) {
        uVar5 = CdCommonClose((short *)puVar4,param_2);
        uVar3 = (uint)uVar5;
      }
      else if (bVar1 == 3) {
        if ((*(byte *)((longlong)puVar4 + 0x41) & 4) == 0) {
          uVar3 = CdCommonRead((short *)puVar4,param_2);
        }
        else {
          uVar5 = CdCompleteMdl((undefined8 *)puVar4,param_2);
          uVar3 = (uint)uVar5;
        }
      }
      else if (bVar1 == 4) {
        uVar3 = CdCommonWrite((short *)puVar4,param_2);
      }
      else if (bVar1 == 5) {
        uVar3 = CdCommonQueryInfo((undefined8 *)puVar4,param_2);
      }
      else if (bVar1 == 6) {
        uVar3 = CdCommonSetInfo((undefined8 *)puVar4,param_2);
      }
      else {
        if (bVar1 != 10) goto LAB_1400013bc;
        uVar3 = CdCommonQueryVolInfo((undefined8 *)puVar4,param_2);
      }
    }
    else if (bVar1 == 0xd) {
      uVar3 = CdCommonFsControl((short *)puVar4,param_2,param_3,param_4);
    }
    else if (bVar1 == 0xe) {
      uVar3 = CdCommonDevControl((undefined8 *)puVar4,param_2);
    }
    else if (bVar1 == 0x10) {
      uVar5 = CdCommonShutdown((short *)puVar4,param_2);
      uVar3 = (uint)uVar5;
    }
    else if (bVar1 == 0x11) {
      uVar6 = CdCommonLockControl((undefined8 *)puVar4,param_2);
      uVar3 = (uint)uVar6;
    }
    else if (bVar1 == 0x12) {
      uVar5 = CdCommonCleanup((short *)puVar4,param_2);
      uVar3 = (uint)uVar5;
    }
    else if (bVar1 == 0x1b) {
      uVar3 = CdCommonPnp((short *)puVar4,param_2);
    }
    else {
LAB_1400013bc:
      uVar3 = 0xc0000010;
      param_3 = 0xc0000010;
      CdCompleteRequest((undefined8 *)puVar4,param_2,0xc0000010);
    }
    if (uVar3 != 0xc00000d8) {
      KeLeaveCriticalRegion();
      return uVar3;
    }
  } while( true );
}



===== CdProcessException @ 140001478 =====

ulonglong CdProcessException(short *param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  uint uVar2;
  void *pvVar3;
  char cVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  void *pvVar8;
  undefined8 uVar9;
  uint local_res18;
  
  uVar5 = param_3 & 0xffffffff;
  if (param_1 == (short *)0x0) goto LAB_140001548;
  local_res18 = *(uint *)(param_1 + 0xc);
  uVar5 = (ulonglong)local_res18;
  if (local_res18 == 0xc00000d8) {
    if ((*(uint *)(param_1 + 0x10) & 8) != 0) {
LAB_1400014dc:
      uVar5 = CdFsdPostRequest(param_1,param_2);
      local_res18 = (uint)uVar5;
      uVar5 = uVar5 & 0xffffffff;
    }
  }
  else if (((local_res18 == 0x80000016) && ((*(uint *)(param_1 + 0x10) & 0x10) != 0)) &&
          (cVar4 = KeAreAllApcsDisabled(), cVar4 != '\0')) goto LAB_1400014dc;
  iVar7 = (int)uVar5;
  if (iVar7 == 0x103) {
    return uVar5;
  }
  if (iVar7 == -0x3fffff28) {
    return uVar5;
  }
  uVar2 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) = uVar2 & 0xfffffffd;
  if ((uVar2 & 0x10) != 0) {
    *(int *)(param_2 + 0x30) = iVar7;
    if (((iVar7 + 0x3fffff5eU < 2) || (iVar7 == -0x3fffff4b)) || (iVar7 + 0x3fffffeeU < 3)) {
      if (iVar7 == -0x7fffffea) goto LAB_140001568;
      if ((*(uint *)(param_1 + 0x10) & 0x200) == 0) {
        lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
        if (lVar6 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = *(undefined8 *)(lVar6 + 0x10);
        }
        pvVar8 = *(void **)(param_2 + 0x98);
        lVar6 = IoGetDeviceToVerify(pvVar8);
        pvVar3 = SystemReserved1[0xf];
        if (lVar6 == 0) {
          lVar6 = IoGetDeviceToVerify(SystemReserved1[0xf]);
          uVar5 = (ulonglong)local_res18;
          pvVar8 = pvVar3;
        }
        if (*(longlong *)(param_1 + 8) != 0) {
          lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 8) + 0x10);
        }
        if (lVar6 != 0) {
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          IoRaiseHardError(param_2,uVar9,lVar6);
          IoSetDeviceToVerify(pvVar8);
          CdCleanupIrpContext((undefined8 *)param_1,'\0');
          return 0x103;
        }
      }
    }
    else if (iVar7 == -0x7fffffea) {
LAB_140001568:
      lVar6 = IoGetDeviceToVerify(*(undefined8 *)(param_2 + 0x98));
      IoSetDeviceToVerify(*(undefined8 *)(param_2 + 0x98),0);
      if (lVar6 == 0) {
        lVar6 = IoGetDeviceToVerify(SystemReserved1[0xf]);
        IoSetDeviceToVerify(SystemReserved1[0xf],0);
      }
      if (*(longlong *)(param_1 + 8) != 0) {
        lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 8) + 0x10);
      }
      if (lVar6 != 0) {
        uVar5 = CdPerformVerify(param_1,param_2,lVar6);
        return uVar5;
      }
      uVar5 = 0xc0000183;
    }
  }
  param_3 = uVar5;
LAB_140001548:
  CdCompleteRequest((undefined8 *)param_1,param_2,(uint)param_3);
  return uVar5;
}



===== wil_details_RecordCachedUsage @ 1400016c0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001820 =====

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



===== CdCommonCleanup @ 1400018a4 =====

undefined8 CdCommonCleanup(short *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  int iVar8;
  undefined1 uVar9;
  bool bVar10;
  undefined1 local_res8 [16];
  longlong local_res18;
  void *local_res20;
  
  local_res18 = 0;
  local_res20 = (void *)0x0;
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 8) == 0) goto LAB_140001cc5;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  iVar8 = CdDecodeFileObject(param_1,lVar2,&local_res18,(ulonglong *)&local_res20);
  lVar5 = local_res18;
  if (iVar8 < 2) goto LAB_140001cc5;
  lVar3 = *(longlong *)(local_res18 + 0x78);
  CdAcquireResource((longlong)param_1,*(ulonglong *)(local_res18 + 8),'\0',0);
  *(uint *)(lVar2 + 0x50) = *(uint *)(lVar2 + 0x50) | 0x4000;
  ExReleaseResourceLite(*(undefined8 *)(lVar5 + 8));
  uVar9 = 2;
  if (iVar8 == 2) {
    if ((*(uint *)((longlong)local_res20 + 4) & 0x10) == 0) {
      if ((*(uint *)(lVar2 + 0x50) & 0x1000) != 0) {
        CdHijackIrpAndFlushDevice
                  ((ulonglong)*(uint *)((longlong)local_res20 + 4),param_2,
                   *(undefined8 *)(lVar3 + 0x10));
        CdMarkDevForVerifyIfVcbMounted(lVar3);
      }
    }
    else {
      ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
      CdCheckForDismount((longlong)param_1,lVar3,'\x01');
      ExReleaseResourceLite(&DAT_1400083d0);
    }
  }
  CdAcquireResource((longlong)param_1,*(longlong *)(lVar5 + 200) + 0x20,'\0',0);
  if (iVar8 != 2) {
    if (iVar8 == 3) {
      FsRtlNotifyCleanup(*(undefined8 *)(lVar3 + 400),lVar3 + 0x198);
    }
    else {
      if (iVar8 != 4) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x26,0x6010f,(longlong)iVar8);
      }
      FsRtlCheckOplock(lVar5 + 0x58,param_2,param_1,0,0);
      if (*(longlong *)(lVar5 + 0x1d8) != 0) {
        IoGetRequestorProcess(param_2);
        FsRtlFastUnlockAll(*(undefined8 *)(lVar5 + 0x1d8),lVar2);
      }
      CcUninitializeCacheMap(lVar2,0);
      lVar6 = local_res18;
      local_res20 = SystemReserved1[0xf];
      if (SystemReserved1[0xf] != *(void **)(local_res18 + 0xb8)) {
        ExAcquireFastMutex(*(longlong *)(lVar5 + 200) + 0x88);
        *(void **)(lVar6 + 0xb8) = local_res20;
      }
      *(int *)(lVar6 + 0xc0) = *(int *)(lVar6 + 0xc0) + 1;
      if (*(int *)(*(longlong *)(lVar5 + 0x78) + 0x34) == 2) {
        cVar7 = FsRtlOplockIsFastIoPossible(lVar5 + 0x58);
        if (cVar7 == '\0') goto LAB_140001af6;
        if ((*(longlong *)(lVar5 + 0x1d8) == 0) ||
           (*(char *)(*(longlong *)(lVar5 + 0x1d8) + 0x10) == '\0')) {
          uVar9 = 1;
        }
      }
      else {
LAB_140001af6:
        uVar9 = 0;
      }
      *(undefined1 *)(lVar6 + 5) = uVar9;
      piVar1 = (int *)(lVar6 + 0xc0);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined8 *)(lVar6 + 0xb8) = 0;
        ExReleaseFastMutex(*(longlong *)(lVar6 + 200) + 0x88);
      }
    }
  }
  ExAcquireFastMutex(lVar3 + 0x150);
  lVar5 = local_res18;
  *(void **)(lVar3 + 0x188) = SystemReserved1[0xf];
  *(int *)(local_res18 + 0xa0) = *(int *)(local_res18 + 0xa0) + -1;
  *(int *)(*(longlong *)(local_res18 + 0x78) + 0x38) =
       *(int *)(*(longlong *)(local_res18 + 0x78) + 0x38) + -1;
  if ((*(int *)(lVar3 + 0x38) == 0) && (*(int *)(lVar3 + 0x34) == 0)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  bVar10 = lVar2 == *(longlong *)(lVar3 + 0x18);
  if (bVar10) {
    IoAcquireVpbSpinLock(local_res8);
    *(ushort *)(*(longlong *)(lVar3 + 8) + 4) = *(ushort *)(*(longlong *)(lVar3 + 8) + 4) & 0xfffd;
    *(uint *)(lVar3 + 0x30) = *(uint *)(lVar3 + 0x30) & 0xffffffef;
    *(undefined8 *)(lVar3 + 0x18) = 0;
    IoReleaseVpbSpinLock(CONCAT71(0xff,local_res8[0]));
  }
  *(undefined8 *)(lVar3 + 0x188) = 0;
  ExReleaseFastMutex(lVar3 + 0x150);
  IoRemoveShareAccess(lVar2,lVar5 + 0xd0);
  ExReleaseResourceLite(*(longlong *)(lVar5 + 200) + 0x20);
  if (bVar10) {
    FsRtlNotifyVolumeEvent(lVar2,5);
  }
  if (bVar4) {
    ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
    CdAcquireResource((longlong)param_1,lVar3 + 0x80U,'\0',0);
    CdPurgeVolume(param_1,lVar3,'\0');
    ExReleaseResourceLite(lVar3 + 0x80U);
    ExReleaseResourceLite(&DAT_1400083d0);
  }
LAB_140001cc5:
  CdCompleteRequest((undefined8 *)param_1,param_2,0);
  return 0;
}



===== Feature_2054323513__private_IsEnabledDeviceUsageNoInline @ 140001cec =====

ulonglong Feature_2054323513__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2054323513__private_featureState;
  if ((Feature_2054323513__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2054323513__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2054323513__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2054323513__private_IsEnabledFallback @ 140001d24 =====

void Feature_2054323513__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001d40 =====

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
LAB_140001f49:
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
LAB_140001e1b:
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
      if (param_3 == 4) goto LAB_140001f49;
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
        goto LAB_140001e1b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002034 =====

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
      goto LAB_140002105;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140002105;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140002105;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140002105;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140002105;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140002105;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140002105;
    }
  }
  uVar3 = 0xff;
LAB_140002105:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000215c =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000224c =====

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
LAB_1400022ff:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000232d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400022ff;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000232d:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400024b8 =====

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



===== wil_details_IsEnabledFallback @ 14000251c =====

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



===== CdDevCtrlCompletionRoutine @ 1400025b0 =====

undefined8 CdDevCtrlCompletionRoutine(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  return 0;
}



===== CdMultiAsyncCompletionRoutine @ 1400025d0 =====

undefined8 CdMultiAsyncCompletionRoutine(undefined8 param_1,longlong param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    LOCK();
    param_3[4] = *(int *)(param_2 + 0x30);
    UNLOCK();
  }
  LOCK();
  iVar2 = *param_3;
  *param_3 = *param_3 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    pbVar1 = (byte *)(*(longlong *)(*(longlong *)(param_3 + 2) + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(int *)(*(longlong *)(param_3 + 2) + 0x30) = param_3[4];
    *(undefined8 *)(*(longlong *)(param_3 + 2) + 0x38) = 0;
    if (-1 < *(int *)(*(longlong *)(param_3 + 2) + 0x30)) {
      *(ulonglong *)(*(longlong *)(param_3 + 2) + 0x38) = (ulonglong)(uint)param_3[10];
    }
    ExReleaseResourceForThreadLite(*(undefined8 *)(param_3 + 6),*(undefined8 *)(param_3 + 8));
    ExFreePoolWithTag(param_3,0);
    uVar3 = 0;
  }
  else {
    IoFreeMdl(*(undefined8 *)(param_2 + 8));
    IoFreeIrp(param_2);
    uVar3 = 0xc0000016;
  }
  return uVar3;
}



===== CdMultiSyncCompletionRoutine @ 140002690 =====

undefined8 CdMultiSyncCompletionRoutine(undefined8 param_1,longlong param_2,int *param_3)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    LOCK();
    param_3[4] = *(int *)(param_2 + 0x30);
    UNLOCK();
    *(undefined8 *)(*(longlong *)(param_3 + 2) + 0x38) = 0;
  }
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(param_2);
  LOCK();
  iVar1 = *param_3;
  *param_3 = *param_3 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    *(int *)(*(longlong *)(param_3 + 2) + 0x30) = param_3[4];
    KeSetEvent(param_3 + 6,0,0);
  }
  return 0xc0000016;
}



===== CdSingleAsyncCompletionRoutine @ 140002730 =====

undefined8 CdSingleAsyncCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (-1 < *(int *)(param_2 + 0x30)) {
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(param_3 + 0x28);
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  ExReleaseResourceForThreadLite(*(undefined8 *)(param_3 + 0x18),*(undefined8 *)(param_3 + 0x20));
  ExFreePoolWithTag(param_3,0);
  return 0;
}



===== CdSingleSyncCompletionRoutine @ 140002790 =====

undefined8 CdSingleSyncCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  if (*(int *)(param_2 + 0x30) < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  KeSetEvent(param_3 + 0x18,0,0);
  return 0xc0000016;
}



===== CdSyncCompletionRoutine @ 1400027d0 =====

undefined8 CdSyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== Feature_719217978__private_IsEnabledDeviceUsageNoInline @ 1400027fc =====

ulonglong Feature_719217978__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_719217978__private_featureState;
  if ((Feature_719217978__private_featureState & 0x10) == 0) {
    uVar1 = Feature_719217978__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_719217978__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_719217978__private_IsEnabledFallback @ 140002834 =====

void Feature_719217978__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_719217978__private_descriptor);
  return;
}



===== CdInvalidateVolumes @ 140002850 =====

uint CdInvalidateVolumes(short *param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 *_Dst;
  char cVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined1 local_res18 [8];
  undefined4 local_res20;
  undefined4 uStackX_24;
  longlong local_48 [2];
  
  local_48[0] = 0;
  lVar6 = *(longlong *)(param_2 + 0xb8);
  uStackX_24 = 0;
  local_res18[0] = 0;
  local_res20 = 7;
  if (*(longlong *)(lVar6 + 0x28) != DAT_140008350) {
    uVar5 = 0xc0000010;
    goto LAB_1400028a0;
  }
  cVar4 = SeSinglePrivilegeCheck(7,*(undefined1 *)(param_2 + 0x40));
  if (cVar4 == '\0') {
    uVar5 = 0xc0000061;
    goto LAB_1400028a0;
  }
  cVar4 = IoIs32bitProcess(param_2);
  iVar2 = *(int *)(lVar6 + 0x10);
  if (cVar4 == '\0') {
    if (iVar2 != 8) goto LAB_140002904;
    lVar6 = **(longlong **)(param_2 + 0x18);
  }
  else {
    if (iVar2 != 4) {
LAB_140002904:
      uVar5 = 0xc000000d;
      goto LAB_1400028a0;
    }
    lVar6 = (longlong)**(int **)(param_2 + 0x18);
  }
  uVar5 = ObReferenceObjectByHandle(lVar6,0,*(undefined8 *)IoFileObjectType_exref,0,local_48,0);
  if (-1 < (int)uVar5) {
    lVar6 = *(longlong *)(local_48[0] + 8);
    ObfDereferenceObject();
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffff7 | 4;
    ExAcquireResourceExclusiveLite(&DAT_1400083d0);
    puVar7 = DAT_140008330;
    if ((undefined8 **)DAT_140008330 != &DAT_140008330) {
      do {
        puVar3 = (undefined8 *)*puVar7;
        puVar1 = puVar7 + 0x26;
        ExAcquireFastMutex(puVar1);
        puVar7[0x2d] = SystemReserved1[0xf];
        if (*(longlong *)(puVar7[-3] + 0x10) == lVar6) {
          IoAcquireVpbSpinLock(local_res18);
          if (*(longlong *)(lVar6 + 0x38) == puVar7[-3]) {
            _Dst = (undefined4 *)puVar7[0x42];
            memset(_Dst,0,0x60);
            *_Dst = 0x60000a;
            *(longlong *)(_Dst + 4) = lVar6;
            *(ushort *)(_Dst + 1) = *(ushort *)(*(longlong *)(lVar6 + 0x38) + 4) & 8;
            *(undefined4 **)(lVar6 + 0x38) = _Dst;
            puVar7[0x42] = 0;
          }
          IoReleaseVpbSpinLock(local_res18[0]);
          if (*(int *)((longlong)puVar7 + 0x14) != 4) {
            *(undefined4 *)((longlong)puVar7 + 0x14) = 3;
          }
          puVar7[0x2d] = 0;
          ExReleaseFastMutex(puVar1);
          CdAcquireResource((longlong)param_1,(ulonglong)(puVar7 + 0xc),'\0',0);
          CdPurgeVolume(param_1,(longlong)(puVar7 + -4),'\0');
          cVar4 = CdCheckForDismount((longlong)param_1,(longlong)(puVar7 + -4),'\0');
          if (cVar4 != '\0') {
            ExReleaseResourceLite(puVar7 + 0xc);
          }
        }
        else {
          puVar7[0x2d] = 0;
          ExReleaseFastMutex(puVar1);
        }
        puVar7 = puVar3;
      } while ((undefined8 **)puVar3 != &DAT_140008330);
    }
    ExReleaseResourceLite(&DAT_1400083d0);
    CdCompleteRequest((undefined8 *)param_1,param_2,0);
    return 0;
  }
LAB_1400028a0:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar5);
  return uVar5;
}



===== CdLockVolumeInternal @ 140002b10 =====

int CdLockVolumeInternal(short *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  iVar3 = (-(uint)(param_3 != 0) & 0x40000011) + 0x80000011;
  CdPurgeVolume(param_1,param_2,'\0');
  ExReleaseResourceLite(param_2 + 0x80U);
  iVar2 = CcWaitForCurrentLazyWriterActivity();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 4;
  CdAcquireResource((longlong)param_1,param_2 + 0x80U,'\0',0);
  if (iVar2 < 0) {
    iVar3 = iVar2;
  }
  else {
    CdFspClose(param_2);
    IoAcquireVpbSpinLock(local_res8);
    lVar1 = *(longlong *)(param_2 + 8);
    if ((((*(byte *)(lVar1 + 4) & 2) == 0) && (*(uint *)(param_2 + 0x38) == (uint)(param_3 != 0)))
       && (*(int *)(param_2 + 0x40) == (param_3 != 0) + 3)) {
      *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 0x10;
      *(ushort *)(lVar1 + 4) = *(ushort *)(lVar1 + 4) | 2;
      iVar3 = 0;
      *(longlong *)(param_2 + 0x18) = param_3;
    }
    IoReleaseVpbSpinLock(CONCAT71((int7)((ulonglong)lVar1 >> 8),local_res8[0]));
  }
  return iVar3;
}



===== CdReMountOldVcb @ 140002c14 =====

void CdReMountOldVcb(ulonglong param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffffffffff00;
  ObfDereferenceObject(*(undefined8 *)(param_2 + 0x10));
  IoAcquireVpbSpinLock(&local_res8);
  *(undefined8 *)(*(longlong *)(*(longlong *)(param_3 + 8) + 0x10) + 0x38) =
       *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10) =
       *(undefined8 *)(*(longlong *)(param_3 + 8) + 0x10);
  *(undefined8 *)(param_2 + 0x10) = param_4;
  *(undefined4 *)(param_2 + 0x34) = 2;
  uVar1 = *(undefined4 *)(param_3 + 0x220);
  *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffdff;
  *(undefined4 *)(param_2 + 0x220) = uVar1;
  lVar2 = *(longlong *)(param_3 + 0x238);
  *(longlong *)(param_2 + 0x238) = lVar2;
  *(undefined8 *)(param_3 + 0x238) = 0;
  lVar4 = 0;
  if (lVar2 != 0) {
    puVar3 = (undefined4 *)(param_2 + 0x240);
    lVar5 = 4;
    lVar4 = lVar2;
    do {
      *puVar3 = 0xffffffff;
      *(longlong *)(puVar3 + 2) = lVar4;
      puVar3 = puVar3 + 4;
      lVar4 = lVar4 + 0xc000;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  IoReleaseVpbSpinLock(CONCAT71((int7)((ulonglong)lVar4 >> 8),(undefined1)local_res8));
  return;
}



===== CdUnlockVolumeInternal @ 140002cf8 =====

undefined8 CdUnlockVolumeInternal(ulonglong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffffffffff00;
  uVar2 = 0xc000002a;
  IoAcquireVpbSpinLock(&local_res8);
  lVar1 = *(longlong *)(param_2 + 8);
  if (((*(byte *)(lVar1 + 4) & 2) != 0) && (param_3 == *(longlong *)(param_2 + 0x18))) {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xffffffef;
    *(ushort *)(lVar1 + 4) = *(ushort *)(lVar1 + 4) & 0xfffd;
    *(undefined8 *)(param_2 + 0x18) = 0;
    uVar2 = 0;
  }
  IoReleaseVpbSpinLock(CONCAT71((int7)((ulonglong)lVar1 >> 8),(undefined1)local_res8));
  return uVar2;
}



===== CdFspDispatch @ 140002d80 =====

void CdFspDispatch(ushort *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  longlong *plVar2;
  byte bVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong lVar8;
  longlong lVar9;
  int iVar10;
  longlong local_res20;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  lVar9 = *(longlong *)(param_1 + 4);
  lVar8 = 0;
  puVar7 = auStack_68;
  if (*(longlong *)(*(longlong *)(lVar9 + 0xb8) + 0x30) != 0) {
    lVar8 = *(longlong *)(*(longlong *)(lVar9 + 0xb8) + 0x28);
    puVar7 = auStack_68;
  }
LAB_140002dcc:
  puVar1 = (uint *)(param_1 + 0x10);
  *(uint **)(puVar7 + 0x88) = puVar1;
  *puVar1 = *puVar1 | 0x74;
  *(undefined8 *)(puVar7 + -8) = 0x140002de3;
  KeEnterCriticalRegion();
  *(undefined8 *)(puVar7 + -8) = 0x140002df5;
  CdSetThreadContext((longlong)param_1,(undefined4 *)(puVar7 + 0x28));
  do {
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    iVar10 = 0;
    *(undefined4 *)(puVar7 + 0x20) = 0;
    *(undefined4 *)(lVar9 + 0x30) = 0;
    *(undefined8 *)(lVar9 + 0x38) = 0;
    bVar3 = (byte)param_1[0x20];
    if (bVar3 < 0xd) {
      if (bVar3 == 0xc) {
        *(undefined8 *)(puVar7 + -8) = 0x140002e95;
        CdCommonDirControl((undefined8 *)param_1,lVar9);
      }
      else if (bVar3 == 0) {
        *(undefined8 *)(puVar7 + -8) = 0x140002e85;
        CdCommonCreate(param_1,lVar9);
      }
      else if (bVar3 != 2) {
        if (bVar3 == 3) {
          *(undefined8 *)(puVar7 + -8) = 0x140002e75;
          CdCommonRead((short *)param_1,lVar9);
        }
        else if (bVar3 == 5) {
          *(undefined8 *)(puVar7 + -8) = 0x140002e65;
          CdCommonQueryInfo((undefined8 *)param_1,lVar9);
        }
        else if (bVar3 == 6) {
          *(undefined8 *)(puVar7 + -8) = 0x140002e55;
          CdCommonSetInfo((undefined8 *)param_1,lVar9);
        }
        else {
          if (bVar3 != 10) goto LAB_140002eb0;
          *(undefined8 *)(puVar7 + -8) = 0x140002e45;
          CdCommonQueryVolInfo((undefined8 *)param_1,lVar9);
        }
      }
    }
    else if (bVar3 == 0xd) {
      *(undefined8 *)(puVar7 + -8) = 0x140002f0a;
      CdCommonFsControl((short *)param_1,lVar9,param_3,param_4);
    }
    else if (bVar3 == 0xe) {
      *(undefined8 *)(puVar7 + -8) = 0x140002efd;
      CdCommonDevControl((undefined8 *)param_1,lVar9);
    }
    else if (bVar3 == 0x11) {
      *(undefined8 *)(puVar7 + -8) = 0x140002ef0;
      CdCommonLockControl((undefined8 *)param_1,lVar9);
    }
    else if (bVar3 == 0x12) {
      *(undefined8 *)(puVar7 + -8) = 0x140002ee3;
      CdCommonCleanup((short *)param_1,lVar9);
    }
    else if (bVar3 == 0x1b) {
      *(undefined8 *)(puVar7 + -8) = 0x140002ed6;
      CdCommonPnp((short *)param_1,lVar9);
    }
    else {
LAB_140002eb0:
      iVar10 = -0x3ffffff0;
      *(undefined4 *)(puVar7 + 0x20) = 0xc0000010;
      param_3 = 0xc0000010;
      *(undefined8 *)(puVar7 + -8) = 0x140002ec9;
      CdCompleteRequest((undefined8 *)param_1,lVar9,0xc0000010);
    }
    if (iVar10 != -0x3fffff28) break;
    *puVar1 = *puVar1 | 2;
    *(undefined8 *)(puVar7 + -8) = 0x140002ff4;
    CdCleanupIrpContext((undefined8 *)param_1,'\0');
  } while( true );
  *(undefined8 *)(puVar7 + -8) = 0x140002f4f;
  KeLeaveCriticalRegion();
  if (lVar8 == 0) {
    return;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140002f6e;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8 + 0x168);
  if (*(int *)(lVar8 + 0x154) != 0) {
    *(int *)(lVar8 + 0x154) = *(int *)(lVar8 + 0x154) + -1;
    plVar2 = (longlong *)(lVar8 + 0x158);
    plVar6 = (longlong *)*plVar2;
    lVar9 = *plVar6;
    if (((longlong *)plVar6[1] == plVar2) && (*(longlong **)(lVar9 + 8) == plVar6)) {
      *plVar2 = lVar9;
      *(longlong **)(lVar9 + 8) = plVar2;
      goto LAB_140002fb6;
    }
    pcVar4 = (code *)swi(0x29);
    uVar5 = (*pcVar4)(3);
    puVar7 = puVar7 + 8;
  }
  *(int *)(lVar8 + 0x150) = *(int *)(lVar8 + 0x150) + -1;
  plVar6 = (longlong *)0x0;
LAB_140002fb6:
  *(undefined8 *)(puVar7 + -8) = 0x140002fc2;
  KeReleaseSpinLock(lVar8 + 0x168,uVar5);
  if (plVar6 == (longlong *)0x0) {
    return;
  }
  param_1 = (ushort *)(plVar6 + -10);
  *(ushort **)(puVar7 + 0x70) = param_1;
  lVar9 = plVar6[-9];
  *(longlong *)(puVar7 + 0x80) = lVar9;
  goto LAB_140002dcc;
}



===== Feature_1787009338__private_IsEnabledDeviceUsageNoInline @ 14000300c =====

ulonglong Feature_1787009338__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1787009338__private_featureState;
  if ((Feature_1787009338__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1787009338__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1787009338__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1787009338__private_IsEnabledFallback @ 140003044 =====

void Feature_1787009338__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1787009338__private_descriptor);
  return;
}



===== CdCheckForDismount @ 140003060 =====

char CdCheckForDismount(longlong param_1,longlong param_2,char param_3)

{
  char cVar1;
  longlong lVar2;
  undefined1 local_res10 [24];
  
  local_res10[0] = 0;
  cVar1 = '\x01';
  CdAcquireResource(param_1,param_2 + 0x80U,'\0',0);
  CdFspClose(param_2);
  lVar2 = param_2 + 0x150;
  ExAcquireFastMutex(lVar2);
  *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
  if (*(int *)(param_2 + 0x34) == 4) {
    if (*(int *)(param_2 + 0x3c) == 0) {
      IoAcquireVpbSpinLock(local_res10);
      if (*(int *)(*(longlong *)(param_2 + 8) + 0x1c) == 1) {
        IoReleaseVpbSpinLock();
        *(undefined8 *)(param_2 + 0x188) = 0;
        ExReleaseFastMutex();
        CdDeleteVcb(lVar2,param_2);
        return '\0';
      }
      IoReleaseVpbSpinLock(local_res10[0]);
    }
  }
  else if ((*(uint *)(param_2 + 0x40) < 4) || (param_3 != '\0')) {
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar2);
    cVar1 = CdDismountVcb((short *)param_1,param_2);
    if (cVar1 == '\0') {
      return '\0';
    }
    goto LAB_140003181;
  }
  *(undefined8 *)(param_2 + 0x188) = 0;
  ExReleaseFastMutex(lVar2);
LAB_140003181:
  ExReleaseResourceLite(param_2 + 0x80U);
  return cVar1;
}



===== CdDismountVcb @ 1400031ac =====

undefined1 CdDismountVcb(short *param_1,longlong param_2)

{
  ushort *puVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  void *pvVar5;
  undefined7 uVar7;
  longlong lVar6;
  undefined1 local_res10 [8];
  
  lVar6 = param_2 + 0x150;
  local_res10[0] = 0;
  ExAcquireFastMutex(lVar6);
  *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
  *(undefined4 *)(param_2 + 0x34) = 4;
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
    *(undefined8 *)(param_2 + 0x70) = 0;
    *(undefined8 *)(param_2 + 0x78) = 0;
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    piVar2 = (int *)(*(longlong *)(param_2 + 0x50) + 0xa4);
    *piVar2 = *piVar2 + -1;
    piVar2 = (int *)(*(longlong *)(param_2 + 0x50) + 0xa8);
    *piVar2 = *piVar2 + -1;
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    piVar2 = (int *)(*(longlong *)(param_2 + 0x58) + 0xa4);
    *piVar2 = *piVar2 + -1;
    piVar2 = (int *)(*(longlong *)(param_2 + 0x58) + 0xa8);
    *piVar2 = *piVar2 + -1;
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    piVar2 = (int *)(*(longlong *)(param_2 + 0x48) + 0xa4);
    *piVar2 = *piVar2 + -1;
    piVar2 = (int *)(*(longlong *)(param_2 + 0x48) + 0xa8);
    *piVar2 = *piVar2 + -1;
  }
  *(undefined8 *)(param_2 + 0x188) = 0;
  ExReleaseFastMutex(lVar6);
  CdPurgeVolume(param_1,param_2,'\x01');
  CdFspClose(param_2);
  lVar3 = *(longlong *)(param_2 + 8);
  ExAcquireFastMutex(lVar6);
  pvVar5 = SystemReserved1[0xf];
  *(int *)(param_2 + 0x3c) = *(int *)(param_2 + 0x3c) + -1;
  *(void **)(param_2 + 0x188) = pvVar5;
  IoAcquireVpbSpinLock(local_res10);
  piVar2 = (int *)(lVar3 + 0x1c);
  if ((*(int *)(param_2 + 0x3c) != 0) || (bVar4 = true, *piVar2 != 1)) {
    bVar4 = false;
  }
  uVar7 = (undefined7)((ulonglong)piVar2 >> 8);
  if (*(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x38) == lVar3) {
    if (bVar4) {
      *piVar2 = *piVar2 + -1;
      *(undefined8 *)(lVar3 + 8) = 0;
      puVar1 = (ushort *)(*(longlong *)(param_2 + 8) + 4);
      *puVar1 = *puVar1 & 0xfffe;
      puVar1 = (ushort *)(*(longlong *)(param_2 + 8) + 4);
      *puVar1 = *puVar1 & 0xfffd;
      *(undefined8 *)(param_2 + 8) = 0;
      IoReleaseVpbSpinLock(CONCAT71(0xff,local_res10[0]));
LAB_1400033c8:
      lVar6 = param_2 + 0x150;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex();
      CdDeleteVcb(lVar6,param_2);
      return 0;
    }
    **(undefined2 **)(param_2 + 0x230) = 10;
    *(undefined2 *)(*(longlong *)(param_2 + 0x230) + 2) = 0x60;
    *(undefined8 *)(*(longlong *)(param_2 + 0x230) + 0x10) = *(undefined8 *)(lVar3 + 0x10);
    *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x230) + 0x10) + 0x38) =
         *(longlong *)(param_2 + 0x230);
    *(ushort *)(*(longlong *)(param_2 + 0x230) + 4) = *(ushort *)(lVar3 + 4) & 8;
    IoReleaseVpbSpinLock(CONCAT71(uVar7,local_res10[0]));
    *(undefined8 *)(param_2 + 0x230) = 0;
  }
  else {
    if (bVar4) {
      *piVar2 = *piVar2 + -1;
      IoReleaseVpbSpinLock(CONCAT71(uVar7,local_res10[0]));
      goto LAB_1400033c8;
    }
    IoReleaseVpbSpinLock(CONCAT71(uVar7,local_res10[0]));
  }
  *(undefined8 *)(param_2 + 0x188) = 0;
  ExReleaseFastMutex(param_2 + 0x150);
  return 1;
}



===== CdMarkDevForVerifyIfVcbMounted @ 140003434 =====

bool CdMarkDevForVerifyIfVcbMounted(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  IoAcquireVpbSpinLock(local_res8);
  lVar1 = *(longlong *)(param_1 + 8);
  lVar2 = *(longlong *)(lVar1 + 0x10);
  bVar3 = *(longlong *)(lVar2 + 0x38) != lVar1;
  if (bVar3) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x200;
  }
  else {
    *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) | 2;
  }
  IoReleaseVpbSpinLock(CONCAT71((int7)((ulonglong)lVar2 >> 8),local_res8[0]));
  return !bVar3;
}



===== CdPerformVerify @ 140003498 =====

ulonglong CdPerformVerify(short *param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  
  if (((char)param_1[0x20] == '\r') && ((byte)(*(char *)((longlong)param_1 + 0x41) - 1U) < 2)) {
    uVar5 = CdFsdPostRequest(param_1,param_2);
    return uVar5;
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(lVar1 + 0x28);
  if ((((char)param_1[0x20] != '\0') ||
      (lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 4) + 0xb8) + 0x30),
      *(short *)(lVar3 + 0x58) != 0)) || (uVar7 = 1, *(longlong *)(lVar3 + 0x40) != 0)) {
    uVar7 = 0;
  }
  iVar4 = IoVerifyVolume(param_3,uVar7);
  CdAcquireResource((longlong)param_1,lVar2 + 0x1f0,'\0',1);
  if ((iVar4 == -0x3fffffee) && (*(int *)(lVar2 + 0x1a4) == 2)) {
    iVar4 = 0;
  }
  else if ((iVar4 == 0) && (*(int *)(lVar2 + 0x1a4) != 2)) {
    iVar4 = -0x3fffffee;
  }
  if (((*(int *)(lVar2 + 0x1a4) == 0) || (*(int *)(lVar2 + 0x1a4) - 3U < 2)) &&
     (*(uint *)(lVar2 + 0x1ac) < 7)) {
    ExReleaseResourceLite(lVar2 + 0x1f0);
    ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
    CdCheckForDismount((longlong)param_1,lVar2 + 0x170,'\0');
    puVar6 = &DAT_1400083d0;
  }
  else {
    puVar6 = (undefined *)(lVar2 + 0x1f0);
  }
  ExReleaseResourceLite(puVar6);
  if ((((char)param_1[0x20] == '\0') && (*(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x40) == 0)) &&
     ((iVar4 == 0 || (iVar4 == -0x3fffffee)))) {
    *(undefined8 *)(param_2 + 0x38) = 1;
    uVar5 = 0x104;
    CdCompleteRequest((undefined8 *)param_1,param_2,0x104);
  }
  else {
    if (iVar4 < 0) {
      if (((iVar4 + 0x3fffff5eU < 2) || (iVar4 == -0x3fffff4b)) ||
         ((iVar4 + 0x3fffffeeU < 3 || (iVar4 == -0x7fffffea)))) {
        IoSetHardErrorOrVerifyDevice(param_2,param_3);
      }
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,iVar4,'\x01',0x1b0000,0xce);
    }
    uVar5 = CdFsdPostRequest(param_1,param_2);
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}



===== CdAddToWorkque @ 1400036c0 =====

void CdAddToWorkque(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) != 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x28);
    lVar1 = lVar2 + 0x168;
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    puVar7 = auStack_28;
    if (2 < *(uint *)(lVar2 + 0x150)) {
      lVar5 = lVar2 + 0x158;
      plVar8 = (longlong *)(param_1 + 0x50);
      plVar6 = *(longlong **)(lVar2 + 0x160);
      if (*plVar6 != lVar5) {
        lVar5 = 3;
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)();
        puVar7 = auStack_20;
      }
      *plVar8 = lVar5;
      *(longlong **)(param_1 + 0x58) = plVar6;
      *plVar6 = (longlong)plVar8;
      *(longlong **)(lVar5 + 8) = plVar8;
      *(int *)(lVar2 + 0x154) = *(int *)(lVar2 + 0x154) + 1;
      *(undefined8 *)(puVar7 + -8) = 0x140003748;
      KeReleaseSpinLock(lVar1,uVar4);
      return;
    }
    *(uint *)(lVar2 + 0x150) = *(uint *)(lVar2 + 0x150) + 1;
    KeReleaseSpinLock(lVar1,uVar4);
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(code **)(param_1 + 0x60) = CdFspDispatch;
  *(longlong *)(param_1 + 0x68) = param_1;
  ExQueueWorkItem((undefined8 *)(param_1 + 0x50),0);
  return;
}



===== _tlgDefineProvider_annotation__TlgCdTelemetryProviderProv @ 1400037a8 =====

void _tlgDefineProvider_annotation__TlgCdTelemetryProviderProv(void)

{
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



===== __GSHandlerCheck_SEH @ 140003864 =====

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



===== __cpu_features_init @ 140003900 =====

/* WARNING: Removing unreachable block (ram,0x00014000396a) */
/* WARNING: Removing unreachable block (ram,0x000140003919) */
/* WARNING: Removing unreachable block (ram,0x00014000390a) */

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



===== __security_check_cookie @ 1400039d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140003a10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140003a40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140003a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140003a70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140003aa0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140003ae3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140003b54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140003b50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140003b54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140003b4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140003b50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140003b4c;
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
LAB_140003b54:
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
LAB_140003ae3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140003bc0 =====

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



===== memset @ 140003ec0 =====

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



===== __memset_repmovs @ 140004000 =====

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



===== __memset_query @ 140004080 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140004100 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004240 =====

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



===== __memset_spec_plain @ 1400042c0 =====

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



===== CdFsdDispatch$filt$0 @ 1400043bd =====

void CdFsdDispatch_filt_0(longlong *param_1,longlong param_2)

{
  CdExceptionFilter(*(longlong *)(param_2 + 0x28),param_1);
  return;
}



===== CdProcessException$filt$0 @ 1400043e0 =====

void CdProcessException_filt_0(longlong *param_1,longlong param_2)

{
  CdExceptionFilter(*(longlong *)(param_2 + 0x50),param_1);
  return;
}



===== CdCommonCleanup$fin$1 @ 140004403 =====

void CdCommonCleanup_fin_1(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0xa0) + 200) + 0x20);
  if (*(char *)(param_2 + 0x30) != '\0') {
    FsRtlNotifyVolumeEvent(*(undefined8 *)(param_2 + 0x40),5);
  }
  return;
}



===== CdCommonCleanup$fin$0 @ 14000444d =====

void CdCommonCleanup_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x31) != '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0x38) + 0x80);
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  return;
}



===== CdFspDispatch$filt$0 @ 140004492 =====

void CdFspDispatch_filt_0(longlong *param_1,longlong param_2)

{
  CdExceptionFilter(*(longlong *)(param_2 + 0x70),param_1);
  return;
}



===== CdPerformVerify$filt$0 @ 1400044b5 =====

void CdPerformVerify_filt_0(longlong *param_1,longlong param_2)

{
  CdExceptionFilter(*(longlong *)(param_2 + 0x70),param_1);
  return;
}



===== CdAddAllocationFromDirent @ 14000c008 =====

void CdAddAllocationFromDirent
               (longlong param_1,longlong param_2,uint param_3,longlong param_4,longlong param_5)

{
  longlong *plVar1;
  void *_Dst;
  longlong lVar2;
  ulonglong uVar3;
  
  if (*(uint *)(param_2 + 0x118) <= param_3) {
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x118) * 0x50;
    if (0xffffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc00000e9,'\0',0x20000,0x19a);
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x411,uVar3 & 0xffffffff,0x616d6443);
    memmove(_Dst,*(void **)(param_2 + 0x120),(ulonglong)*(uint *)(param_2 + 0x118) * 0x28);
    if ((*(int *)(param_2 + 0x118) != 1) && (*(longlong *)(param_2 + 0x120) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x120),0);
    }
    *(void **)(param_2 + 0x120) = _Dst;
    *(int *)(param_2 + 0x118) = *(int *)(param_2 + 0x118) * 2;
  }
  plVar1 = (longlong *)(*(longlong *)(param_2 + 0x120) + (ulonglong)param_3 * 0x28);
  *plVar1 = (ulonglong)*(uint *)(param_5 + 8) <<
            ((byte)*(undefined4 *)(*(longlong *)(param_2 + 0x78) + 0x1b0) & 0x3f);
  uVar3 = (ulonglong)*(uint *)(param_5 + 0xc);
  plVar1[1] = uVar3;
  if (-1 < *(char *)(param_5 + 0x18)) {
    uVar3 = (ulonglong)
            (*(int *)(*(longlong *)(param_2 + 0x78) + 0x1b8) + (int)plVar1[1] &
            *(uint *)(*(longlong *)(param_2 + 0x78) + 0x1bc));
    plVar1[1] = uVar3;
  }
  plVar1[2] = param_4;
  if (*(uint *)(param_5 + 0x1c) == 0) {
    plVar1[3] = uVar3;
  }
  else {
    lVar2 = (ulonglong)*(uint *)(param_5 + 0x1c) <<
            ((byte)*(undefined4 *)(*(longlong *)(param_2 + 0x78) + 0x1b0) & 0x3f);
    plVar1[3] = lVar2;
    uVar3 = ((ulonglong)*(uint *)(param_5 + 0x20) <<
            ((byte)*(undefined4 *)(*(longlong *)(param_2 + 0x78) + 0x1b0) & 0x3f)) + lVar2;
  }
  plVar1[4] = uVar3;
  *(uint *)(param_2 + 0x11c) = param_3 + 1;
  return;
}



===== CdLookupAllocation @ 14000c190 =====

void CdLookupAllocation(void *param_1,longlong param_2,longlong param_3,longlong *param_4,
                       undefined4 *param_5)

{
  int *piVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  void *pvVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined4 uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  uint local_130;
  longlong local_128;
  longlong local_118;
  longlong local_f8 [4];
  int local_d8 [6];
  byte local_c0;
  byte local_bf;
  longlong local_98;
  
  bVar4 = true;
  local_128 = 0;
  bVar3 = false;
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  memset(local_d8,0,0xc0);
  if (param_2 == *(longlong *)(*(longlong *)(param_2 + 0x78) + 0x48)) {
    *param_4 = param_3;
    return;
  }
  do {
    pvVar5 = SystemReserved1[0xf];
    if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
      *(void **)(param_2 + 0xb8) = pvVar5;
    }
    *(int *)(param_2 + 0xc0) = *(int *)(param_2 + 0xc0) + 1;
    lVar13 = *(longlong *)(param_2 + 0x120);
    for (uVar10 = 0; uVar10 < *(uint *)(param_2 + 0x11c); uVar10 = uVar10 + 1) {
      if (param_3 < *(longlong *)(lVar13 + 0x10) + *(longlong *)(lVar13 + 8)) {
        if (uVar10 < *(uint *)(param_2 + 0x11c)) {
          uVar7 = (ulonglong)uVar10;
          lVar13 = *(longlong *)(param_2 + 0x120);
          lVar14 = param_3 - *(longlong *)(lVar13 + 0x10 + uVar7 * 0x28);
          lVar12 = *(longlong *)(lVar13 + 8 + uVar7 * 0x28);
          lVar2 = *(longlong *)(lVar13 + 0x18 + uVar7 * 0x28);
          lVar8 = *(longlong *)(lVar13 + uVar7 * 0x28);
          if (lVar12 == lVar2) {
            *param_4 = lVar8 + lVar14;
          }
          else {
            for (lVar12 = lVar2; lVar12 <= lVar14; lVar12 = lVar12 + lVar2) {
              lVar8 = lVar8 + *(longlong *)(lVar13 + 0x20 + uVar7 * 0x28);
            }
            *param_4 = (lVar2 - lVar12) + lVar8 + lVar14;
            lVar13 = *(longlong *)(lVar13 + 8 + uVar7 * 0x28);
            if (lVar13 < lVar12) {
              lVar12 = lVar13;
            }
          }
          uVar11 = (undefined4)(lVar12 - lVar14);
          if (0xffffffff < lVar12 - lVar14) {
            uVar11 = 0xffffffff;
          }
          *param_5 = uVar11;
          if (bVar3) {
            ExReleaseResourceLite(*(undefined8 *)(local_128 + 8));
            if (local_f8[2] != 0) {
              CcUnpinData();
              local_f8[2] = 0;
            }
            if (((local_bf & 1) != 0) && (local_98 != 0)) {
              ExFreePoolWithTag(local_98,0);
            }
          }
          piVar1 = (int *)(param_2 + 0xc0);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(undefined8 *)(param_2 + 0xb8) = 0;
            ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
            return;
          }
          return;
        }
        break;
      }
      lVar13 = lVar13 + 0x28;
    }
    if (!bVar4) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc0000032,'\0',0x20000,0xd9);
    }
    piVar1 = (int *)(param_2 + 0xc0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(param_2 + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
    }
    local_f8[0] = 0;
    local_f8[1] = 0;
    local_f8[2] = 0;
    local_f8[3] = 0;
    memset(local_d8,0,0xc0);
    local_128 = *(longlong *)(param_2 + 0x80);
    CdAcquireResource((longlong)param_1,*(ulonglong *)(local_128 + 8),'\0',1);
    bVar3 = true;
    if (*(longlong *)(local_128 + 0x1d8) == 0) {
      CdCreateInternalStream
                (param_1,*(longlong *)(local_128 + 0x78),local_128,(undefined4 *)(local_128 + 0x158)
                );
    }
    local_118 = 0;
    local_130 = 0;
    lVar13 = local_128;
    CdLookupDirent((longlong)param_1,local_128,*(uint *)(param_2 + 0x98) & 0x7fffffff,local_f8);
    while( true ) {
      CdUpdateDirentFromRawDirent((longlong)param_1,lVar13,local_f8,local_d8);
      pvVar5 = SystemReserved1[0xf];
      if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
        ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
        *(void **)(param_2 + 0xb8) = pvVar5;
      }
      *(int *)(param_2 + 0xc0) = *(int *)(param_2 + 0xc0) + 1;
      if (*(uint *)(param_2 + 0x11c) <= local_130) {
        CdAddAllocationFromDirent((longlong)param_1,param_2,local_130,local_118,(longlong)local_d8);
      }
      iVar6 = *(int *)(param_2 + 0xc0) + -1;
      *(int *)(param_2 + 0xc0) = iVar6;
      if (iVar6 == 0) {
        *(undefined8 *)(param_2 + 0xb8) = 0;
        ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
      }
      if ((local_c0 & 0x80) == 0) break;
      lVar13 = local_128;
      uVar9 = CdLookupNextDirent((longlong)param_1,local_128,(longlong)local_f8,local_f8);
      if ((char)uVar9 == '\0') {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc0000032,'\0',0x20000,0x12e);
      }
      local_118 = local_118 +
                  *(longlong *)(*(longlong *)(param_2 + 0x120) + 8 + (ulonglong)local_130 * 0x28);
      local_130 = local_130 + 1;
    }
    bVar4 = false;
  } while( true );
}



===== CdCompleteMdl @ 14000c618 =====

undefined8 CdCompleteMdl(undefined8 *param_1,longlong param_2)

{
  CcMdlReadComplete(*(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x30),
                    *(undefined8 *)(param_2 + 8));
  *(undefined8 *)(param_2 + 8) = 0;
  CdCompleteRequest(param_1,param_2,0);
  return 0;
}



===== CdCreateInternalStream @ 14000c66c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CdCreateInternalStream(void *param_1,longlong param_2,longlong param_3,undefined4 *param_4)

{
  ulonglong *puVar1;
  int *piVar2;
  longlong *plVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  bool bVar10;
  void *pvVar11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  undefined1 auStackY_188 [32];
  longlong local_130 [5];
  int local_108 [2];
  uint local_100;
  int local_fc;
  char *local_f8;
  byte local_f0;
  byte local_ef;
  undefined *local_c8;
  short local_48;
  short sStack_46;
  short sStack_44;
  short sStack_42;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  bVar10 = false;
  memset(local_108,0,0xc0);
  pvVar11 = SystemReserved1[0xf];
  local_130[0] = 0;
  local_130[1] = 0;
  local_130[2] = 0;
  local_130[3] = 0;
  plVar3 = (longlong *)(param_3 + 200);
  if (SystemReserved1[0xf] != *(void **)(param_3 + 0xb8)) {
    ExAcquireFastMutex(*plVar3 + 0x88);
    *(void **)(param_3 + 0xb8) = pvVar11;
  }
  iVar6 = *(int *)(param_3 + 0xc0);
  *(int *)(param_3 + 0xc0) = iVar6 + 1;
  if (*(longlong *)(param_3 + 0x1d8) == 0) {
    lVar13 = IoCreateStreamFileObjectLite(0,*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10));
    if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0x30000,0x76);
    }
    *(undefined2 *)(lVar13 + 0x4a) = 1;
    *(undefined1 *)(lVar13 + 0x4c) = 0;
    *(longlong *)(lVar13 + 0x28) = *plVar3 + 8;
    *(longlong *)(lVar13 + 0x18) = param_3;
    *(undefined8 *)(lVar13 + 0x20) = 0;
    *(undefined8 *)(lVar13 + 0x20) = 1;
    *(undefined8 *)(lVar13 + 0x10) = *(undefined8 *)(*(longlong *)(param_3 + 0x78) + 8);
    uVar7 = param_4[1];
    uVar8 = param_4[2];
    uVar9 = param_4[3];
    *(undefined4 *)(lVar13 + 0x58) = *param_4;
    *(undefined4 *)(lVar13 + 0x5c) = uVar7;
    *(undefined4 *)(lVar13 + 0x60) = uVar8;
    *(undefined4 *)(lVar13 + 100) = uVar9;
    lVar4 = param_2 + 0x150;
    ExAcquireFastMutex(lVar4);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    *(int *)(param_3 + 0xa4) = *(int *)(param_3 + 0xa4) + 2;
    *(undefined4 *)(param_3 + 0xa8) = *(undefined4 *)(param_3 + 0xa8);
    *(int *)(*(longlong *)(param_3 + 0x78) + 0x3c) =
         *(int *)(*(longlong *)(param_3 + 0x78) + 0x3c) + 2;
    *(undefined4 *)(*(longlong *)(param_3 + 0x78) + 0x40) =
         *(undefined4 *)(*(longlong *)(param_3 + 0x78) + 0x40);
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar4);
    puVar1 = (ulonglong *)(param_3 + 0x18);
    CcInitializeCacheMap(lVar13,puVar1,1,&DAT_140008438);
    *(longlong *)(param_3 + 0x1d8) = lVar13;
    if ((*(uint *)(param_3 + 0xac) & 1) == 0) {
      lVar13 = param_3;
      CdLookupDirent((longlong)param_1,param_3,*(uint *)(param_3 + 0x1e0),local_130);
      CdUpdateDirentFromRawDirent((longlong)param_1,lVar13,local_130,local_108);
      CdUpdateDirentName(param_1,(longlong)local_108,0);
      if (local_c8 != &CdUnicodeSelfArray) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0x30000,0xdb);
      }
      uVar12 = *(int *)(param_2 + 0x1b8) + *(int *)(param_3 + 0x1e0) + local_fc &
               *(uint *)(param_2 + 0x1bc);
      if (uVar12 == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0x30000,0xe7);
      }
      uVar14 = (ulonglong)uVar12;
      if (uVar14 != *(ulonglong *)(param_3 + 0x20)) {
        *(ulonglong *)(param_3 + 0x28) = uVar14;
        *(ulonglong *)(param_3 + 0x20) = uVar14;
        *puVar1 = uVar14;
        CcSetFileSizes(*(undefined8 *)(param_3 + 0x1d8),puVar1);
        uVar12 = 0;
        for (lVar13 = *(longlong *)(param_3 + 0x120);
            (uVar12 < *(uint *)(param_3 + 0x11c) &&
            (*(longlong *)(lVar13 + 0x10) + *(longlong *)(lVar13 + 8) < 1)); lVar13 = lVar13 + 0x28)
        {
          uVar12 = uVar12 + 1;
        }
        *(uint *)(param_3 + 0x11c) = uVar12;
        plVar3 = *(longlong **)(param_3 + 0x120);
        lVar13 = (ulonglong)local_100 <<
                 ((byte)*(undefined4 *)(*(longlong *)(param_3 + 0x78) + 0x1b0) & 0x3f);
        *plVar3 = lVar13;
        *plVar3 = lVar13 - (ulonglong)*(uint *)(param_3 + 0x1e0);
        plVar3[1] = uVar14;
        plVar3[2] = 0;
        plVar3[4] = uVar14;
        plVar3[3] = uVar14;
        *(undefined4 *)(param_3 + 0x11c) = 1;
        bVar10 = true;
      }
      if ((local_f0 & 1) != 0) {
        *(uint *)(param_3 + 0xb0) = *(uint *)(param_3 + 0xb0) | 2;
      }
      _local_48 = CONCAT26((short)local_f8[3],
                           CONCAT24((short)local_f8[2],
                                    CONCAT22((short)local_f8[1],*local_f8 + 0x76c)));
      uStack_40 = (ulonglong)CONCAT22((short)local_f8[5],(short)local_f8[4]);
      plVar3 = (longlong *)(param_3 + 0x1d0);
      RtlTimeFieldsToTime(&local_48,plVar3);
      if ((*(uint *)(*(longlong *)((longlong)param_1 + 0x10) + 0x30) & 1) == 0) {
        cVar5 = local_f8[6];
        if ((cVar5 != '\0') && ((byte)(cVar5 + 0x30U) < 0x65)) {
          *plVar3 = *plVar3 + (longlong)-(int)cVar5 * 9000000000;
        }
      }
      *(uint *)(param_3 + 0xac) = *(uint *)(param_3 + 0xac) | 1;
      if (local_130[2] != 0) {
        CcUnpinData();
        local_130[2] = 0;
      }
      if (((local_ef & 1) != 0) && (local_c8 != (undefined *)0x0)) {
        ExFreePoolWithTag(local_c8,0);
        local_c8 = (undefined *)0x0;
      }
      if (bVar10) {
        CcPurgeCacheSection(*(longlong *)(param_3 + 200) + 8,0,0,0);
      }
    }
    ExAcquireFastMutex(lVar4);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    *(int *)(param_3 + 0xa4) = *(int *)(param_3 + 0xa4) + -1;
    piVar2 = (int *)(*(longlong *)(param_3 + 0x78) + 0x3c);
    *piVar2 = *piVar2 + -1;
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar4);
    piVar2 = (int *)(param_3 + 0xc0);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 != 0) {
      return;
    }
    lVar13 = *(longlong *)(param_3 + 200);
  }
  else {
    *(int *)(param_3 + 0xc0) = iVar6;
    if (iVar6 != 0) {
      return;
    }
    lVar13 = *plVar3;
  }
  *(undefined8 *)(param_3 + 0xb8) = 0;
  ExReleaseFastMutex(lVar13 + 0x88);
  return;
}



===== CdDeleteInternalStream @ 14000cbfc =====

void CdDeleteInternalStream(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  void *pvVar3;
  
  pvVar3 = SystemReserved1[0xf];
  if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
    ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
    *(void **)(param_2 + 0xb8) = pvVar3;
  }
  iVar1 = *(int *)(param_2 + 0xc0);
  lVar2 = *(longlong *)(param_2 + 0x1d8);
  *(undefined8 *)(param_2 + 0x1d8) = 0;
  *(int *)(param_2 + 0xc0) = iVar1;
  if (iVar1 == 0) {
    *(undefined8 *)(param_2 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
  }
  if (lVar2 != 0) {
    if (*(longlong *)(lVar2 + 0x30) != 0) {
      CcUninitializeCacheMap(lVar2,0,0);
    }
    *(undefined8 *)(lVar2 + 0x60) = 0;
    *(undefined4 *)(lVar2 + 0x58) = 0;
    ObfDereferenceObject(lVar2);
  }
  return;
}



===== CdPurgeVolume @ 14000ccd8 =====

int CdPurgeVolume(short *param_1,longlong param_2,char param_3)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  undefined8 local_res10;
  undefined1 local_res18 [16];
  
  iVar4 = 0;
  local_res10 = 0;
  CdFspClose(param_2);
  CdAcquireResource((longlong)param_1,param_2 + 0xe8,'\0',0);
  psVar5 = (short *)0x0;
  while( true ) {
    ExAcquireFastMutex(param_2 + 0x150);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    lVar2 = RtlEnumerateGenericTableWithoutSplaying(param_2 + 0x1c0,&local_res10);
    psVar6 = (short *)0x0;
    if (lVar2 != 0) {
      psVar6 = *(short **)(lVar2 + 8);
    }
    if (psVar6 != (short *)0x0) {
      *(int *)(psVar6 + 0x52) = *(int *)(psVar6 + 0x52) + 1;
    }
    if (psVar5 == (short *)0x0) {
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex(param_2 + 0x150);
    }
    else {
      *(int *)(psVar5 + 0x52) = *(int *)(psVar5 + 0x52) + -1;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex();
      CdTeardownStructures(param_1,psVar5,local_res18);
    }
    if (psVar6 == (short *)0x0) break;
    if (*(longlong *)(*(longlong *)(psVar6 + 100) + 0x18) != 0) {
      MmFlushImageSection(*(longlong *)(psVar6 + 100) + 8,1);
    }
    plVar3 = (longlong *)(*(longlong *)(psVar6 + 100) + 8);
    if (*plVar3 != 0) {
      cVar1 = CcPurgeCacheSection(plVar3,0);
      if ((cVar1 == '\0') && (iVar4 == 0)) {
        iVar4 = -0x3fffffe5;
      }
    }
    psVar5 = psVar6;
    if (((param_3 != '\0') && (*psVar6 != 0x305)) && (*(longlong *)(psVar6 + 0xec) != 0)) {
      CdDeleteInternalStream(plVar3,(longlong)psVar6);
    }
  }
  if (param_3 != '\0') {
    psVar5 = *(short **)(param_2 + 0x58);
    if (psVar5 != (short *)0x0) {
      LOCK();
      *(int *)(psVar5 + 0x52) = *(int *)(psVar5 + 0x52) + 1;
      UNLOCK();
      plVar3 = (longlong *)(*(longlong *)(psVar5 + 100) + 8);
      if (*plVar3 != 0) {
        cVar1 = CcPurgeCacheSection(plVar3,0,0,0);
        if ((cVar1 == '\0') && (iVar4 == 0)) {
          iVar4 = -0x3fffffe5;
        }
      }
      CdDeleteInternalStream(plVar3,(longlong)psVar5);
      LOCK();
      *(int *)(psVar5 + 0x52) = *(int *)(psVar5 + 0x52) + -1;
      UNLOCK();
      CdTeardownStructures(param_1,psVar5,local_res18);
    }
    psVar5 = *(short **)(param_2 + 0x48);
    if (psVar5 != (short *)0x0) {
      LOCK();
      *(int *)(psVar5 + 0x52) = *(int *)(psVar5 + 0x52) + 1;
      UNLOCK();
      if (*(longlong *)(*(longlong *)(psVar5 + 100) + 8) != 0) {
        cVar1 = CcPurgeCacheSection((longlong *)(*(longlong *)(psVar5 + 100) + 8),0,0,0);
        if ((cVar1 == '\0') && (iVar4 == 0)) {
          iVar4 = -0x3fffffe5;
        }
      }
      LOCK();
      *(int *)(psVar5 + 0x52) = *(int *)(psVar5 + 0x52) + -1;
      UNLOCK();
      CdTeardownStructures(param_1,psVar5,local_res18);
    }
  }
  ExReleaseResourceLite(param_2 + 0xe8);
  return iVar4;
}



===== CdFastIoCheckIfPossible @ 14000cf50 =====

bool CdFastIoCheckIfPossible
               (longlong param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
               undefined4 param_5,char param_6,undefined4 *param_7)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  ulonglong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  if ((((byte)*(undefined4 *)(param_1 + 0x20) & 7) == 4) && (param_6 != '\0')) {
    local_res8 = param_3 & 0xffffffff;
    if (*(longlong *)(lVar1 + 0x1d8) != 0) {
      uVar3 = IoGetCurrentProcess();
      cVar2 = FsRtlFastCheckLockForRead
                        (*(undefined8 *)(lVar1 + 0x1d8),param_2,&local_res8,param_5,param_1,uVar3);
      return cVar2 != '\0';
    }
  }
  else {
    *param_7 = 0xc000000d;
  }
  return true;
}



===== CdSetThreadContext @ 14000cfec =====

void CdSetThreadContext(longlong param_1,undefined4 *param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  
  piVar3 = (int *)IoGetTopLevelIrp();
  puVar1 = (uint *)(param_1 + 0x20);
  if (piVar3 == (int *)0x0) {
    *puVar1 = *puVar1 | 0x10;
  }
  if ((*puVar1 & 0x10) == 0) {
    iVar2 = IoWithinStackLimits(piVar3,0x18);
    if (((iVar2 != 0) && (((ulonglong)piVar3 & 3) == 0)) && (*piVar3 == 0x53464443)) {
      lVar4 = *(longlong *)(piVar3 + 4);
      goto LAB_14000d07b;
    }
  }
  *param_2 = 0x53464443;
  *(int **)(param_2 + 2) = piVar3;
  *(longlong *)(param_2 + 4) = param_1;
  IoSetTopLevelIrp(param_2);
  *puVar1 = *puVar1 | 0x20;
  *(undefined4 **)(param_1 + 0x48) = param_2;
  lVar4 = param_1;
LAB_14000d07b:
  *(longlong *)(param_1 + 0x38) = lVar4;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000d09c =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000d0d7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000d151:
  while( true ) {
    if (&UNK_1400079c7 < ppuVar3) {
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
      if (&UNK_1400079c7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000d0d7:
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
      if (&UNK_1400079c7 < ppuVar2) goto LAB_14000d151;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000d151;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000d18c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000d224;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000d224;
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
LAB_14000d224:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000d270 =====

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
              if (&UNK_1400079c7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000d2f0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000d3ed;
  }
LAB_14000d3f6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000d3ed:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000d3f6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000d3be:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000d3be;
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
    if (&UNK_1400079c7 < ppuVar3) goto LAB_14000d3f6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000d3ed;
}



===== CdCloseWorker @ 14000d420 =====

void CdCloseWorker(void)

{
  CdFspClose(0);
  return;
}



===== CdCommonClose @ 14000d438 =====

undefined8 CdCommonClose(short *param_1,longlong param_2)

{
  longlong lVar1;
  short *psVar2;
  longlong lVar3;
  bool bVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = 0;
  bVar4 = false;
  if (*(longlong *)(param_1 + 8) == 0) {
LAB_14000d59c:
    CdCompleteRequest((undefined8 *)param_1,param_2,0);
    return 0;
  }
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  uVar9 = *(uint *)(lVar1 + 0x20) & 7;
  if (uVar9 == 0) goto LAB_14000d59c;
  psVar2 = *(short **)(lVar1 + 0x18);
  lVar3 = *(longlong *)(psVar2 + 0x3c);
  uVar6 = *(ulonglong *)(lVar1 + 0x20) & 0xfffffffffffffff8;
  if (uVar6 != 0) {
    iVar8 = 1;
    if (*(longlong *)(uVar6 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(uVar6 + 0x20),0);
      *(undefined8 *)(uVar6 + 0x20) = 0;
    }
    ExFreePoolWithTag(uVar6,0);
  }
  if (((*(int *)(lVar3 + 0x34) == 2) && (*(int *)(psVar2 + 0x52) == 1)) && (uVar9 - 3 < 2)) {
    cVar7 = '\x01';
  }
  else {
    if ((*(int *)(lVar3 + 0x38) == 0) && (*(int *)(lVar3 + 0x34) != 2)) {
      ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
      if ((*(int *)(lVar3 + 0x38) == 0) &&
         ((1 < *(int *)(lVar3 + 0x34) - 1U && ((*(uint *)(param_1 + 0x10) & 0x20) != 0)))) {
        bVar4 = true;
      }
      else {
        ExReleaseResourceLite(&DAT_1400083d0);
      }
    }
    uVar5 = CdCommonClosePrivate(param_1,lVar3,psVar2,iVar8,'\x01');
    if ((char)uVar5 != '\0') {
      if (bVar4) {
        CdCheckForDismount((longlong)param_1,lVar3,'\0');
      }
      goto LAB_14000d578;
    }
    cVar7 = '\0';
  }
  CdQueueClose((undefined8 *)param_1,psVar2,iVar8,cVar7);
  param_1 = (short *)0x0;
LAB_14000d578:
  CdCompleteRequest((undefined8 *)param_1,param_2,0);
  if (bVar4) {
    ExReleaseResourceLite(&DAT_1400083d0);
    return 0;
  }
  return 0;
}



===== CdCommonClosePrivate @ 14000d5cc =====

ulonglong CdCommonClosePrivate
                    (short *param_1,longlong param_2,short *param_3,int param_4,char param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char local_res10 [8];
  
  uVar1 = param_2 + 0x80;
  local_res10[0] = '\0';
  uVar2 = CdAcquireResource((longlong)param_1,uVar1,param_5,1);
  if ((char)uVar2 != '\0') {
    uVar2 = CdAcquireResource((longlong)param_1,*(longlong *)(param_3 + 100) + 0x20,param_5,0);
    if ((char)uVar2 != '\0') {
      ExAcquireFastMutex();
      *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
      *(int *)(param_3 + 0x52) = *(int *)(param_3 + 0x52) + -1;
      *(int *)(param_3 + 0x54) = *(int *)(param_3 + 0x54) - param_4;
      *(int *)(*(longlong *)(param_3 + 0x3c) + 0x3c) =
           *(int *)(*(longlong *)(param_3 + 0x3c) + 0x3c) + -1;
      *(int *)(*(longlong *)(param_3 + 0x3c) + 0x40) =
           *(int *)(*(longlong *)(param_3 + 0x3c) + 0x40) - param_4;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex(param_2 + 0x150);
      CdTeardownStructures(param_1,param_3,local_res10);
      if (local_res10[0] == '\0') {
        ExReleaseResourceLite(*(longlong *)(param_3 + 100) + 0x20);
      }
      uVar3 = ExReleaseResourceLite(uVar1);
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    uVar2 = ExReleaseResourceLite(uVar1);
  }
  return uVar2 & 0xffffffffffffff00;
}



===== CdFspClose @ 14000d704 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdFspClose(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  short *psVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  longlong lVar10;
  uint uVar11;
  int iVar12;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [24];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined4 local_98 [4];
  undefined8 local_88;
  uint local_78;
  longlong local_70;
  undefined1 local_58;
  
  memset(local_98,0,0x70);
  uVar11 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  lVar10 = 0;
  KeEnterCriticalRegion();
  puVar8 = auStack_e8;
  do {
    plVar9 = (longlong *)0x0;
    ExAcquireFastMutex(&DAT_140008398);
    _DAT_140008390 = SystemReserved1[0xf];
    plVar6 = DAT_140008358;
    plVar7 = plVar9;
    if ((longlong **)DAT_140008358 == &DAT_140008358) {
LAB_14000d7e1:
      if ((param_1 != 0) || ((DAT_14000836d != '\0' && (DAT_140008388 < DAT_140008380))))
      goto LAB_14000d7fd;
LAB_14000d857:
      _DAT_14000836c = 0;
    }
    else {
      do {
        plVar7 = plVar6 + -10;
        if ((param_1 == 0) || (plVar6[-8] == param_1)) {
          lVar2 = *plVar6;
          if ((*(longlong **)(lVar2 + 8) != plVar6) ||
             (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) goto LAB_14000da25;
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          _DAT_140008368 = _DAT_140008368 + -1;
          if (plVar7 == (longlong *)0x0) goto LAB_14000d7e1;
          goto LAB_14000d84d;
        }
        plVar6 = (longlong *)*plVar6;
        plVar7 = plVar9;
      } while ((longlong **)plVar6 != &DAT_140008358);
LAB_14000d7fd:
      plVar6 = DAT_140008370;
      if ((longlong **)DAT_140008370 == &DAT_140008370) {
LAB_14000d84d:
        if ((param_1 == 0) && (plVar7 == (longlong *)0x0)) goto LAB_14000d857;
      }
      else {
        do {
          if ((param_1 == 0) || (*(longlong *)(plVar6[-1] + 0x78) == param_1)) {
            lVar2 = *plVar6;
            if ((*(longlong **)(lVar2 + 8) != plVar6) ||
               (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) goto LAB_14000da25;
            *plVar3 = lVar2;
            plVar7 = plVar6 + -2;
            *(longlong **)(lVar2 + 8) = plVar3;
            DAT_140008380 = DAT_140008380 - 1;
            goto LAB_14000d84d;
          }
          plVar6 = (longlong *)*plVar6;
        } while ((longlong **)plVar6 != &DAT_140008370);
      }
    }
    _DAT_140008390 = (void *)0x0;
    ExReleaseFastMutex(&DAT_140008398);
    if (plVar7 == (longlong *)0x0) goto LAB_14000da2c;
    psVar4 = (short *)plVar7[1];
    if ((short)*plVar7 == 0x308) {
      iVar12 = (int)plVar7[3];
      *(undefined4 *)(plVar7 + 3) = 0;
      plVar7[1] = 0;
    }
    else {
      iVar12 = (int)plVar7[4];
      memset(local_98,0,0x70);
      local_98[0] = 0x700308;
      local_70 = plVar7[5];
      local_88 = *(undefined8 *)(plVar7[1] + 0x78);
      local_78 = local_78 | 5;
      local_58 = 2;
      ExFreePoolWithTag(plVar7,0);
      plVar7 = (longlong *)local_98;
    }
    uVar1 = *(uint *)(plVar7 + 4);
    *(uint *)(plVar7 + 4) = uVar1 | 0x74;
    if (param_1 != 0) {
      *(uint *)(plVar7 + 4) = (uVar1 | 0x74) & 0xffffffcf;
    }
    CdSetThreadContext((longlong)plVar7,(undefined4 *)&local_b8);
    if (((param_1 == 0) && (1 < *(int *)(*(longlong *)(psVar4 + 0x3c) + 0x34) - 1U)) &&
       (*(int *)(*(longlong *)(psVar4 + 0x3c) + 0x38) == 0)) {
      plVar9 = (longlong *)0x1;
LAB_14000d923:
      if (lVar10 != 0) {
        ExReleaseResourceLite(lVar10 + 0x80);
      }
      if ((char)plVar9 != '\0') {
        ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
        if (((param_1 == 0) && (1 < *(int *)(*(longlong *)(psVar4 + 0x3c) + 0x34) - 1U)) &&
           (*(int *)(*(longlong *)(psVar4 + 0x3c) + 0x38) == 0)) {
          plVar9 = (longlong *)0x1;
        }
        else {
          plVar9 = (longlong *)0x0;
          ExReleaseResourceLite(&DAT_1400083d0);
        }
      }
      lVar10 = *(longlong *)(psVar4 + 0x3c);
      CdAcquireResource((longlong)plVar7,lVar10 + 0x80,'\0',1);
      uVar11 = 0;
    }
    else {
      if ((DAT_140008388 < uVar11) || (*(longlong *)(psVar4 + 0x3c) != lVar10)) goto LAB_14000d923;
      uVar11 = uVar11 + 1;
    }
    CdCommonClosePrivate((short *)plVar7,lVar10,psVar4,iVar12,'\0');
    if ((char)plVar9 != '\0') {
      ExReleaseResourceLite(lVar10 + 0x80);
      CdCheckForDismount((longlong)plVar7,lVar10,'\0');
      lVar10 = 0;
      ExReleaseResourceLite(&DAT_1400083d0);
    }
    CdCompleteRequest(plVar7,0,0);
  } while( true );
LAB_14000da25:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar8 = auStack_e0;
LAB_14000da2c:
  if (lVar10 != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x14000da3f;
    ExReleaseResourceLite(lVar10 + 0x80);
  }
  *(undefined8 *)(puVar8 + -8) = 0x14000da4b;
  KeLeaveCriticalRegion();
  return;
}



===== CdQueueClose @ 14000da78 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdQueueClose(undefined8 *param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  bool bVar5;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar2 = (undefined4 *)0x0;
  bVar5 = false;
  if (param_4 != '\0') {
    puVar2 = (undefined4 *)ExAllocatePoolWithTag(0x600,0x30);
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  CdCleanupIrpContext(param_1,'\x01');
  ExAcquireFastMutex(&DAT_140008398);
  puVar4 = auStack_38;
  _DAT_140008390 = SystemReserved1[0xf];
  if (puVar2 == (undefined4 *)0x0) {
    param_1[1] = param_2;
    puVar3 = &DAT_140008358;
    *(undefined4 *)(param_1 + 3) = param_3;
    param_1 = param_1 + 10;
    if ((undefined8 *)*DAT_140008360 != &DAT_140008358) goto LAB_14000dbb7;
  }
  else {
    *puVar2 = 0x300309;
    *(undefined8 *)(puVar2 + 2) = param_2;
    puVar2[8] = param_3;
    *(undefined8 *)(puVar2 + 10) = param_1[5];
    puVar3 = (undefined8 *)(puVar2 + 4);
    if ((undefined8 *)*DAT_140008378 == &DAT_140008370) {
      *(undefined8 **)(puVar2 + 6) = DAT_140008378;
      *puVar3 = &DAT_140008370;
      *DAT_140008378 = puVar3;
      DAT_140008380 = DAT_140008380 + 1;
      if ((DAT_140008384 < DAT_140008380) && (DAT_14000836d = 1, DAT_14000836c == '\0')) {
        DAT_14000836c = '\x01';
        bVar5 = true;
      }
      _DAT_140008390 = (void *)0x0;
      DAT_140008378 = puVar3;
      ExReleaseFastMutex(&DAT_140008398);
      CdCompleteRequest(param_1,0,0);
      puVar4 = auStack_38;
      goto LAB_14000dc03;
    }
LAB_14000dbb7:
    puVar3 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    DAT_140008360 = (undefined8 *)(*pcVar1)();
    puVar4 = auStack_30;
  }
  *param_1 = puVar3;
  param_1[1] = DAT_140008360;
  *DAT_140008360 = param_1;
  _DAT_140008368 = _DAT_140008368 + 1;
  bVar5 = DAT_14000836c == '\0';
  if (bVar5) {
    DAT_14000836c = '\x01';
  }
  _DAT_140008390 = (void *)0x0;
  *(undefined8 *)(puVar4 + -8) = 0x14000dbfe;
  DAT_140008360 = param_1;
  ExReleaseFastMutex(&DAT_140008398);
LAB_14000dc03:
  if (bVar5) {
    *(undefined8 *)(puVar4 + -8) = 0x14000dc23;
    IoQueueWorkItem(DAT_140008478,CdCloseWorker,0,0);
  }
  return;
}



===== CdCommonCreate @ 14000dc48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdCommonCreate(ushort *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  short *psVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  ushort *puVar14;
  undefined1 **_Dst;
  byte bVar15;
  char cVar16;
  uint uVar17;
  uint uVar18;
  undefined1 auStackY_508 [32];
  ushort *puVar19;
  short *local_4a8;
  undefined1 local_4a0;
  ushort *local_498;
  short *local_490;
  ushort *local_488;
  longlong local_480;
  ushort *local_478;
  longlong local_470;
  ushort *local_468;
  ushort local_460 [4];
  ushort *puStack_458;
  ulonglong local_450;
  undefined8 uStack_448;
  longlong local_440;
  longlong local_438;
  ushort local_430 [20];
  ushort *local_408 [2];
  ushort *local_3f8;
  char local_3ec;
  undefined4 local_3e8 [8];
  byte local_3c8;
  ushort local_3c0;
  ushort *local_3b8;
  undefined1 *local_338;
  undefined1 *local_330;
  undefined1 *local_328;
  ushort local_310 [4];
  undefined1 *local_308;
  undefined1 local_2f0 [24];
  undefined1 local_2d8 [224];
  undefined1 local_1f8 [224];
  undefined1 local_118 [224];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_508;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_478 = param_1;
  local_470 = param_2;
  local_440 = param_2;
  memset(local_408,0,200);
  bVar7 = false;
  memset(&local_338,0,0x300);
  bVar6 = false;
  bVar5 = false;
  uVar18 = 0;
  local_498 = (ushort *)0x0;
  local_4a8 = (short *)0x0;
  puVar14 = (ushort *)0x0;
  local_430[0] = 0;
  local_430[1] = 0;
  local_430[2] = 0;
  local_430[3] = 0;
  local_430[4] = 0;
  local_430[5] = 0;
  local_430[6] = 0;
  local_430[7] = 0;
  local_430[8] = 0;
  local_430[9] = 0;
  local_430[10] = 0;
  local_430[0xb] = 0;
  local_430[0xc] = 0;
  local_430[0xd] = 0;
  local_430[0xe] = 0;
  local_430[0xf] = 0;
  local_460[0] = 0;
  local_460[1] = 0;
  local_460[2] = 0;
  local_460[3] = 0;
  puStack_458 = (ushort *)0x0;
  local_450 = 0;
  uStack_448 = 0;
  local_488 = (ushort *)0x0;
  local_480 = *(longlong *)(param_1 + 8);
  if (local_480 == 0) {
    CdCompleteRequest((undefined8 *)param_1,param_2,0);
    return 0;
  }
  uVar17 = *(uint *)(lVar2 + 0x10) & 0x2000;
  bVar15 = -((char)~*(byte *)(lVar2 + 2) >> 7);
  cVar1 = *(char *)(lVar2 + 0x13);
  if ((((*(byte *)(lVar2 + 2) & 6) != 0) || (*(int *)(lVar2 + 0x20) != 0)) || (cVar1 == '\x02')) {
    uVar18 = 0xc0000022;
    goto LAB_14000e6fd;
  }
  if ((*(uint *)(lVar2 + 0x10) >> 0x10 & 1) != 0) {
LAB_14000e6ee:
    uVar18 = 0xc000000d;
    goto LAB_14000e6fd;
  }
  local_490 = *(short **)(local_480 + 0x50);
  lVar3 = *(longlong *)(lVar2 + 0x30);
  local_468 = (ushort *)(lVar3 + 0x58);
  lVar4 = *(longlong *)(lVar3 + 0x40);
  local_438 = local_480;
  if ((lVar4 != 0) && (uVar17 == 0)) {
    *(undefined8 *)(lVar3 + 0x10) = *(undefined8 *)(lVar4 + 0x10);
    uVar18 = *(uint *)(lVar4 + 0x20) & 7;
    if (uVar18 == 0) {
      local_498 = (ushort *)0x0;
      local_490 = (short *)0x0;
    }
    else {
      local_490 = *(short **)(lVar4 + 0x18);
      local_498 = (ushort *)(*(ulonglong *)(lVar4 + 0x20) & 0xfffffffffffffff8);
    }
    if (uVar18 < 2) goto LAB_14000e6ee;
    puVar14 = (ushort *)(lVar4 + 0x58);
  }
  uVar12 = CdNormalizeFileNames
                     (param_1,local_480,uVar17 != 0,bVar15,uVar18,local_498,puVar14,local_468,
                      local_430);
  lVar3 = local_480;
  if ((int)(uint)uVar12 < 0) {
    CdCompleteRequest((undefined8 *)param_1,local_440,(uint)uVar12);
    return uVar12 & 0xffffffff;
  }
  if (((*local_468 == 0) && (uVar18 < 3)) && (uVar17 == 0)) {
    bVar5 = true;
    iVar11 = 0;
  }
  else {
    iVar11 = 1;
  }
  local_468 = (ushort *)(local_480 + 0x80);
  CdAcquireResource((longlong)param_1,(ulonglong)local_468,'\0',iVar11);
  puVar14 = param_1;
  CdVerifyVcb((longlong)param_1,lVar3);
  psVar8 = local_490;
  if ((*(uint *)(lVar3 + 0x30) & 0x10) == 0) {
    puVar14 = (ushort *)0x0;
    if (uVar17 == 0) {
      if (!bVar5) {
        CdAcquireResource((longlong)param_1,*(longlong *)(local_490 + 100) + 0x20,'\0',0);
        local_4a8 = psVar8;
        if (local_430[0] == 0) {
LAB_14000dfc1:
          puVar14 = (ushort *)0x305;
          puVar19 = local_498;
          if (*local_4a8 == 0x305) {
            if (((*(uint *)(param_1 + 0x10) & 0x20000000) == 0) &&
               ((*(uint *)(lVar2 + 0x10) & 1) == 0)) {
              if ((cVar1 - 1U & 0xfd) == 0) {
                iVar11 = 4;
                goto LAB_14000df50;
              }
LAB_14000dfea:
              uVar18 = 0xc0000022;
            }
            else {
              uVar18 = 0xc0000103;
            }
            goto LAB_14000e538;
          }
          if ((*(uint *)(lVar2 + 0x10) & 0x40) == 0) {
            if ((cVar1 - 1U & 0xfd) != 0) goto LAB_14000dfea;
            iVar11 = 3;
            goto LAB_14000df50;
          }
        }
        else {
          CdFindPrefix((longlong)param_1,(longlong *)&local_4a8,local_430,bVar15);
          if (local_430[0] == 0) goto LAB_14000dfc1;
          puVar14 = (ushort *)(ulonglong)*(uint *)(local_4a8 + 0x58);
          if ((*(uint *)(local_4a8 + 0x58) & 0x10) == 0) {
            uVar18 = 0xc000003a;
            goto LAB_14000e538;
          }
          if ((*(uint *)(param_1 + 0x10) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
            CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0x80000,0x260);
          }
          local_450 = local_450 & 0xffffffffffff0000;
LAB_14000e075:
          cVar16 = '\0';
          local_4a0 = 0;
          CdDissectName(puVar14,local_430,(short *)local_460);
          memset(local_408,0,200);
          bVar7 = true;
          puVar14 = param_1;
          uVar13 = CdFindPathEntry((longlong)param_1,(longlong)local_4a8,local_460,bVar15,
                                   (longlong *)local_408);
          if ((char)uVar13 == '\0') {
            iVar11 = CdShortNameDirentOffset(puVar14,local_460);
            local_490 = (short *)CONCAT44(local_490._4_4_,iVar11);
            cVar10 = '\0';
            cVar16 = '\0';
            if (iVar11 == -1) {
LAB_14000e2b9:
              if (cVar10 != '\0') goto LAB_14000e493;
              cVar9 = '\0';
              if (local_430[0] != 0) {
LAB_14000e3d4:
                uVar18 = 0xc000003a;
                goto LAB_14000e538;
              }
            }
            else {
              if (bVar6) {
                CdCleanupFileContext(puVar14,(longlong)&local_338);
              }
              memset(&local_338,0,0x300);
              local_338 = local_2d8;
              local_330 = local_1f8;
              local_328 = local_118;
              local_310[1] = 0x18;
              local_308 = local_2f0;
              bVar6 = true;
              puVar14 = param_1;
              uVar13 = CdFindFileByShortName
                                 (param_1,(longlong)local_4a8,local_460,bVar15,(uint)local_490,
                                  &local_338);
              cVar9 = (char)uVar13;
              cVar10 = '\0';
              cVar16 = '\0';
              if (cVar9 == '\0') goto LAB_14000e2b9;
              local_4a0 = 1;
              if ((local_330[0x38] & 2) != 0) {
                if (local_3f8 != (ushort *)0x0) {
                  CcUnpinData();
                  local_3f8 = (ushort *)0x0;
                }
                if ((local_3ec != '\0') && (local_408[0] != (ushort *)0x0)) {
                  ExFreePoolWithTag();
                  local_408[0] = (ushort *)0x0;
                }
                if (((local_3c8 & 1) != 0) && (local_3b8 != (ushort *)0x0)) {
                  ExFreePoolWithTag();
                  local_3b8 = (ushort *)0x0;
                }
                memset(local_408,0,200);
                puVar14 = param_1;
                uVar13 = CdFindPathEntry((longlong)param_1,(longlong)local_4a8,
                                         (ushort *)(local_330 + 0x78),bVar15,(longlong *)local_408);
                cVar10 = (char)uVar13;
                if (cVar10 == '\0') {
                    /* WARNING: Subroutine does not return */
                  CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0x80000,700);
                }
                cVar16 = '\x01';
                if (bVar15 != 0) {
                  CdUpcaseName(puVar14,local_460,local_460);
                }
                goto LAB_14000e2b9;
              }
              if (local_430[0] != 0) goto LAB_14000e3d4;
              local_488 = local_310;
            }
            if (cVar9 == '\0') {
              if (bVar6) {
                CdCleanupFileContext(puVar14,(longlong)&local_338);
              }
              _Dst = &local_338;
              memset(_Dst,0,0x300);
              local_338 = local_2d8;
              local_330 = local_1f8;
              local_328 = local_118;
              local_310[1] = 0x18;
              local_308 = local_2f0;
              bVar6 = true;
              CdConvertNameToCdName(_Dst,local_460);
              puVar14 = param_1;
              uVar13 = CdFindFile(param_1,(longlong)local_4a8,local_460,bVar15,&local_338,&local_488
                                 );
              if ((char)uVar13 == '\0') {
                if ((cVar1 != '\x01') && (cVar1 != '\x04')) goto LAB_14000deae;
                uVar18 = 0xc0000034;
                goto LAB_14000e538;
              }
            }
            puVar19 = local_488;
            if ((local_330[0x39] & 2) != 0) {
                    /* WARNING: Subroutine does not return */
              CdRaiseStatusEx((longlong)param_1,0xc0000032,'\0',0x80000,0x372);
            }
            if (((*(uint *)(param_1 + 0x10) & 0x20000000) != 0) ||
               ((*(uint *)(lVar2 + 0x10) & 1) != 0)) goto LAB_14000df16;
            if ((cVar1 - 1U & 0xfd) != 0) goto LAB_14000dfea;
            if (bVar15 != 0) {
              memmove(puStack_458,*(void **)(local_488 + 4),(ulonglong)*local_488);
            }
            puVar14 = param_1;
            uVar18 = CdOpenFileFromFileContext
                               ((short *)param_1,lVar2,local_480,(longlong *)&local_4a8,local_460,
                                bVar15,puVar19 == local_310,(longlong)&local_338,(longlong)local_498
                               );
            goto LAB_14000e538;
          }
LAB_14000e493:
          if ((bVar15 != 0) && (cVar16 == '\0')) {
            puVar14 = puStack_458;
            memmove(puStack_458,local_3b8,(ulonglong)local_3c0);
          }
          if (local_430[0] != 0) {
            CdOpenDirectoryFromPathEntry
                      ((short *)param_1,lVar2,local_480,(longlong *)&local_4a8,local_460,bVar15,
                       cVar16,local_3e8,'\0',0);
            puVar14 = local_3f8;
            if (local_3f8 != (ushort *)0x0) {
              CcUnpinData();
              local_3f8 = (ushort *)0x0;
            }
            if ((local_3ec != '\0') && (puVar14 = local_408[0], local_408[0] != (ushort *)0x0)) {
              ExFreePoolWithTag(local_408[0],0);
              local_408[0] = (ushort *)0x0;
            }
            if (((local_3c8 & 1) != 0) && (puVar14 = local_3b8, local_3b8 != (ushort *)0x0)) {
              ExFreePoolWithTag(local_3b8,0);
              local_3b8 = (ushort *)0x0;
            }
            goto LAB_14000e075;
          }
          if ((*(uint *)(lVar2 + 0x10) & 0x40) == 0) {
            if ((cVar1 == '\x01') || (cVar1 == '\x03')) {
              puVar14 = param_1;
              uVar18 = CdOpenDirectoryFromPathEntry
                                 ((short *)param_1,lVar2,local_480,(longlong *)&local_4a8,local_460,
                                  bVar15,cVar16,local_3e8,'\x01',(longlong)local_498);
              goto LAB_14000e538;
            }
            goto LAB_14000dfea;
          }
        }
        uVar18 = 0xc00000ba;
      }
      else {
        if ((cVar1 - 1U & 0xfd) != 0) goto LAB_14000deae;
        if ((*(uint *)(lVar2 + 0x10) & 1) != 0) {
LAB_14000df16:
          uVar18 = 0xc0000103;
          goto LAB_14000e538;
        }
        local_4a8 = *(short **)(lVar3 + 0x48);
        CdAcquireResource((longlong)param_1,*(longlong *)(local_4a8 + 100) + 0x20,'\0',0);
        bVar15 = 0;
        iVar11 = 2;
        puVar19 = (ushort *)0x0;
LAB_14000df50:
        puVar14 = param_1;
        uVar18 = CdOpenExistingFcb((short *)param_1,lVar2,(longlong *)&local_4a8,iVar11,bVar15,
                                   (longlong)puVar19);
      }
    }
    else if ((char)*(uint *)(lVar3 + 0x30) < '\0') {
      uVar18 = 0xc0000010;
    }
    else {
      if ((cVar1 - 1U & 0xfd) != 0) goto LAB_14000deae;
      if ((*(uint *)(param_1 + 0x10) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0x80000,0x1b9);
      }
      puVar14 = param_1;
      uVar18 = CdOpenByFileId((longlong *)param_1,lVar2,lVar3,(longlong *)&local_4a8);
    }
  }
  else {
LAB_14000deae:
    uVar18 = 0xc0000022;
  }
LAB_14000e538:
  if (bVar7) {
    puVar14 = local_3f8;
    if (local_3f8 != (ushort *)0x0) {
      CcUnpinData();
      local_3f8 = (ushort *)0x0;
    }
    if ((local_3ec != '\0') && (puVar14 = local_408[0], local_408[0] != (ushort *)0x0)) {
      ExFreePoolWithTag(local_408[0],0);
      local_408[0] = (ushort *)0x0;
    }
    if (((local_3c8 & 1) != 0) && (puVar14 = local_3b8, local_3b8 != (ushort *)0x0)) {
      ExFreePoolWithTag(local_3b8,0);
      local_3b8 = (ushort *)0x0;
    }
  }
  if (bVar6) {
    CdCleanupFileContext(puVar14,(longlong)&local_338);
  }
  if (uVar18 == 0x103) {
    param_1 = (ushort *)0x0;
    param_2 = 0;
  }
  else {
    param_2 = local_440;
  }
  if (local_4a8 != (short *)0x0) {
    ExReleaseResourceLite(*(longlong *)(local_4a8 + 100) + 0x20);
  }
  ExReleaseResourceLite(local_468);
LAB_14000e6fd:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar18);
  return (ulonglong)uVar18;
}



===== CdCompleteFcbOpen @ 14000e7b8 =====

int CdCompleteFcbOpen(short *param_1,longlong param_2,longlong param_3,longlong *param_4,int param_5
                     ,undefined4 param_6,uint param_7)

{
  longlong lVar1;
  uint *puVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  void *pvVar7;
  char cVar8;
  int iVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined1 uVar12;
  code *in_stack_ffffffffffffffb8;
  int local_38;
  undefined8 local_30;
  
  lVar4 = *param_4;
  local_38 = 0;
  bVar6 = false;
  uVar12 = 2;
  if (param_7 == 0x2000000) {
    param_7 = ~(-(uint)(param_5 != 2) & 0x116 | 0x50040) & 0x1f01ff;
  }
  if ((param_5 < 3) && ((*(byte *)(param_2 + 0x1a) & 1) == 0)) {
    if (*(int *)(param_3 + 0x38) != 0) {
      return -0x3fffffbd;
    }
    if ((*(uint *)(param_1 + 0x10) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0x80000,0xae4);
    }
    bVar6 = true;
    iVar9 = CdPurgeVolume(param_1,param_3,'\0');
    if (iVar9 != 0) {
      return iVar9;
    }
    CdFspClose(param_3);
    if (3 < *(uint *)(param_3 + 0x40)) {
      return -0x3fffffbd;
    }
  }
  local_30 = 1;
  if (*(int *)(lVar4 + 0xa0) != 0) {
    if (param_5 == 4) {
      *(longlong **)(param_1 + 0x18) = param_4;
      lVar1 = lVar4 + 0x58;
      local_30 = 1;
      cVar8 = FsRtlCurrentBatchOplock(lVar1);
      if (cVar8 != '\0') {
        in_stack_ffffffffffffffb8 = CdPrePostIrp;
        local_30 = 9;
        iVar9 = FsRtlCheckOplock(lVar1,*(undefined8 *)(param_1 + 4),param_1,CdOplockComplete,
                                 CdPrePostIrp);
        if (iVar9 == 0x103) {
          return 0x103;
        }
      }
      iVar9 = IoCheckShareAccess(param_7,*(undefined2 *)(param_2 + 0x1a),
                                 *(undefined8 *)(param_2 + 0x30),lVar4 + 0xd0,
                                 (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
      if (iVar9 < 0) {
        return iVar9;
      }
      local_38 = FsRtlCheckOplock(lVar1,*(undefined8 *)(param_1 + 4),param_1,CdOplockComplete,
                                  CdPrePostIrp);
      if (local_38 == 0x103) {
        return 0x103;
      }
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      param_1[0x1a] = 0;
      param_1[0x1b] = 0;
    }
    else {
      iVar9 = IoCheckShareAccess(param_7,*(undefined2 *)(param_2 + 0x1a),
                                 *(undefined8 *)(param_2 + 0x30),lVar4 + 0xd0,
                                 (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
      local_30 = 1;
      if (iVar9 < 0) {
        return iVar9;
      }
    }
  }
  puVar10 = (undefined8 *)ExAllocatePoolWithTag(0x411,0x38,0x63636443);
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar10[3] = 0;
  puVar10[4] = 0;
  puVar10[5] = 0;
  puVar10[6] = 0;
  *(undefined4 *)puVar10 = 0x380307;
  *(undefined4 *)((longlong)puVar10 + 4) = param_6;
  puVar10[1] = lVar4;
  if (*(int *)(lVar4 + 0xa0) == 0) {
    IoSetShareAccess(param_7,*(undefined2 *)(param_2 + 0x1a),*(undefined8 *)(param_2 + 0x30),
                     lVar4 + 0xd0);
  }
  else {
    IoUpdateShareAccess(*(undefined8 *)(param_2 + 0x30),lVar4 + 0xd0);
  }
  lVar1 = *(longlong *)(param_2 + 0x30);
  if (param_5 == 0) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
    *(undefined8 *)(lVar1 + 0x18) = 0;
  }
  else {
    *(longlong *)(lVar1 + 0x18) = lVar4;
    *(ulonglong *)(lVar1 + 0x20) = (longlong)param_5 | (ulonglong)puVar10;
    *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)(*(longlong *)(lVar4 + 0x78) + 8);
    if (param_5 == 4) {
      uVar11 = *(uint *)(*(longlong *)(param_2 + 0x30) + 0x50);
      if ((*(uint *)(param_2 + 0x10) & 8) == 0) {
        uVar11 = uVar11 | 0x40;
      }
      else {
        uVar11 = uVar11 | 8;
      }
      *(uint *)(*(longlong *)(param_2 + 0x30) + 0x50) = uVar11;
    }
    else if (param_5 == 2) {
      puVar2 = (uint *)(*(longlong *)(param_2 + 0x30) + 0x50);
      *puVar2 = *puVar2 | 8;
    }
  }
  ExAcquireFastMutex(param_3 + 0x150);
  *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
  *(int *)(lVar4 + 0xa0) = *(int *)(lVar4 + 0xa0) + 1;
  piVar3 = (int *)(*(longlong *)(lVar4 + 0x78) + 0x38);
  *piVar3 = *piVar3 + 1;
  *(int *)(lVar4 + 0xa4) = *(int *)(lVar4 + 0xa4) + 1;
  *(int *)(lVar4 + 0xa8) = *(int *)(lVar4 + 0xa8) + 1;
  piVar3 = (int *)(*(longlong *)(lVar4 + 0x78) + 0x3c);
  *piVar3 = *piVar3 + 1;
  piVar3 = (int *)(*(longlong *)(lVar4 + 0x78) + 0x40);
  *piVar3 = *piVar3 + 1;
  if (bVar6) {
    uVar5 = *(undefined8 *)(param_2 + 0x30);
    *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) | 0x10;
    *(undefined8 *)(param_3 + 0x18) = uVar5;
  }
  *(undefined8 *)(param_3 + 0x188) = 0;
  ExReleaseFastMutex(param_3 + 0x150);
  pvVar7 = SystemReserved1[0xf];
  if (SystemReserved1[0xf] != *(void **)(lVar4 + 0xb8)) {
    ExAcquireFastMutex(*(longlong *)(lVar4 + 200) + 0x88);
    *(void **)(lVar4 + 0xb8) = pvVar7;
  }
  *(int *)(lVar4 + 0xc0) = *(int *)(lVar4 + 0xc0) + 1;
  if (param_5 == 4) {
    if ((*(int *)(*(longlong *)(lVar4 + 0x78) + 0x34) == 2) &&
       (cVar8 = FsRtlOplockIsFastIoPossible(lVar4 + 0x58), cVar8 != '\0')) {
      if ((*(longlong *)(lVar4 + 0x1d8) == 0) ||
         (*(char *)(*(longlong *)(lVar4 + 0x1d8) + 0x10) == '\0')) {
        uVar12 = 1;
      }
    }
    else {
      uVar12 = 0;
    }
  }
  else {
    uVar12 = 0;
  }
  *(undefined1 *)(lVar4 + 5) = uVar12;
  piVar3 = (int *)(lVar4 + 0xc0);
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    *(undefined8 *)(lVar4 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(lVar4 + 200) + 0x88);
  }
  *(undefined8 *)(*(longlong *)(param_1 + 4) + 0x38) = local_30;
  *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x28) = *(longlong *)(lVar4 + 200) + 8;
  return local_38;
}



===== CdNormalizeFileNames @ 14000ec18 =====

undefined8
CdNormalizeFileNames
          (ushort *param_1,longlong param_2,char param_3,char param_4,int param_5,ushort *param_6,
          ushort *param_7,ushort *param_8,ushort *param_9)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  ushort *_Dst;
  ushort *_Dst_00;
  short sVar4;
  ulonglong _Size;
  ushort uVar5;
  size_t _Size_00;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool local_48;
  uint local_44;
  
  local_44 = 0;
  iVar8 = 0;
  if ((*(uint *)(param_1 + 0x10) & 0x10000000) == 0) {
    uVar5 = *param_8;
    if (param_3 == '\0') {
      _Dst_00 = param_1;
      if (2 < uVar5) {
        _Dst_00 = *(ushort **)(param_8 + 4);
        if ((_Dst_00[1] == 0x5c) && (*_Dst_00 == 0x5c)) {
          if ((4 < uVar5) && (_Dst_00[2] == 0x5c)) {
            return 0xc0000033;
          }
          *param_8 = uVar5 - 2;
          memmove(_Dst_00,_Dst_00 + 1,(ulonglong)(ushort)(uVar5 - 2));
        }
      }
      _Size_00 = 0;
      uVar5 = *param_8;
      if ((2 < uVar5) || ((_Size = (ulonglong)uVar5, uVar5 == 2 && (param_5 == 3)))) {
        _Size = (ulonglong)uVar5;
        _Dst_00 = (ushort *)(ulonglong)(uVar5 >> 1);
        if (*(short *)(*(longlong *)(param_8 + 4) + -2 + (longlong)_Dst_00 * 2) == 0x5c) {
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20000000;
          *param_8 = *param_8 - 2;
          _Size = (ulonglong)*param_8;
        }
      }
      sVar4 = (short)_Size;
      if (param_5 == 0) {
        if (sVar4 != 0) {
          if (**(short **)(param_8 + 4) != 0x5c) {
            return 0xc000000d;
          }
          _Size = (ulonglong)((int)_Size - 2);
          iVar8 = 2;
        }
      }
      else {
        if (sVar4 != 0) {
          if (param_5 < 3) {
            return 0xc000000d;
          }
          if (**(short **)(param_8 + 4) == 0x5c) {
            return 0xc000000d;
          }
          if (param_5 == 4) {
            return 0xc000003a;
          }
        }
        _Dst_00 = param_6;
        if ((*(uint *)(param_6 + 2) & 1) == 0) {
          if ((sVar4 != 0) && (*(longlong *)(param_6 + 4) != *(longlong *)(param_2 + 0x50))) {
            iVar8 = 2;
          }
          _Size_00 = (size_t)*param_7;
          local_44 = (uint)*param_7;
        }
      }
      uVar6 = (int)_Size_00 + iVar8;
      iVar1 = (int)_Size;
      uVar9 = uVar6 + iVar1;
      if (0xffff < uVar9) {
        return 0xc000000d;
      }
      bVar10 = uVar9 <= param_8[1];
      if (bVar10) {
        uVar9 = (uint)param_8[1];
        _Dst = *(ushort **)(param_8 + 4);
      }
      else {
        _Dst_00 = (ushort *)0x411;
        _Dst = (ushort *)ExAllocatePoolWithTag(0x411,uVar9);
        _Size_00 = (size_t)local_44;
      }
      local_48 = !bVar10;
      bVar10 = !bVar10;
      uVar5 = (ushort)_Size;
      if ((int)_Size_00 != 0) {
        if (iVar1 != 0) {
          memmove((void *)((ulonglong)uVar6 + (longlong)_Dst),*(void **)(param_8 + 4),_Size);
          _Size_00 = (size_t)local_44;
        }
        memmove(_Dst,*(void **)(param_7 + 4),_Size_00);
        if (iVar8 != 0) {
          *(undefined2 *)((ulonglong)local_44 + (longlong)_Dst) = 0x5c;
        }
        puVar7 = param_8 + 4;
        _Dst_00 = *(ushort **)(param_8 + 4);
        bVar10 = local_48;
        if (_Dst != _Dst_00) {
          if (_Dst_00 != (ushort *)0x0) {
            ExFreePoolWithTag(_Dst_00,0);
            puVar7[0] = 0;
            puVar7[1] = 0;
            puVar7[2] = 0;
            puVar7[3] = 0;
          }
          *(ushort **)puVar7 = _Dst;
          _Dst = (ushort *)0x0;
          param_8[1] = (ushort)uVar9;
          bVar10 = false;
        }
        *param_8 = (short)iVar8 + (short)local_44 + uVar5;
      }
      if ((bVar10) && (_Dst != (ushort *)0x0)) {
        ExFreePoolWithTag(_Dst,0);
        _Dst_00 = _Dst;
      }
      *param_9 = uVar5;
      param_9[1] = uVar5;
      param_9[8] = 0;
      *(ulonglong *)(param_9 + 4) = (ulonglong)(iVar8 + local_44) + *(longlong *)(param_8 + 4);
      if ((param_4 != '\0') && (iVar1 != 0)) {
        CdUpcaseName(_Dst_00,param_9,param_9);
      }
      cVar3 = FsRtlDoesNameContainWildCards(param_9);
      if (cVar3 != '\0') {
        return 0xc0000033;
      }
    }
    else if (uVar5 != 8) {
      return 0xc000000d;
    }
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x10000000;
  }
  else {
    uVar2 = *(undefined8 *)(param_8 + 4);
    *(undefined8 *)param_9 = *(undefined8 *)param_8;
    *(undefined8 *)(param_9 + 4) = uVar2;
    uVar5 = *param_9;
    param_9[8] = 0;
    if (uVar5 != 0) {
      if ((param_5 != 0) &&
         (param_1 = (ushort *)(ulonglong)*(uint *)(param_6 + 2), (*(uint *)(param_6 + 2) & 1) == 0))
      {
        *(ulonglong *)(param_9 + 4) = *(longlong *)(param_9 + 4) + (ulonglong)*param_7;
        uVar5 = uVar5 - *param_7;
        *param_9 = uVar5;
        param_1 = param_7;
      }
      if ((uVar5 != 0) && (**(short **)(param_9 + 4) == 0x5c)) {
        uVar5 = uVar5 - 2;
        *(short **)(param_9 + 4) = *(short **)(param_9 + 4) + 1;
        param_9[1] = param_9[1] - 2;
        *param_9 = uVar5;
      }
    }
    if ((param_4 != '\0') && (uVar5 != 0)) {
      CdUpcaseName(param_1,param_9,param_9);
    }
  }
  return 0;
}



===== CdOpenByFileId @ 14000efd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CdOpenByFileId(longlong *param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *_Dst;
  longlong *plVar7;
  longlong lVar8;
  uint uVar9;
  undefined1 auStackY_498 [32];
  int local_454;
  undefined8 local_450;
  int local_448;
  uint uStack_434;
  longlong local_418 [2];
  longlong local_408;
  char local_3fc;
  int local_3f8;
  uint local_3f4;
  byte local_3d8;
  longlong local_3c8;
  undefined1 *local_348;
  longlong *local_340;
  undefined1 *local_338;
  undefined2 local_31e;
  undefined1 *local_318;
  undefined1 local_300 [24];
  undefined1 local_2e8 [224];
  longlong local_208 [28];
  undefined1 local_128 [224];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_498;
  local_448 = -0x3fffffde;
  memset(&local_348,0,0x300);
  bVar2 = false;
  _Dst = local_418;
  memset(_Dst,0,200);
  bVar3 = false;
  uVar5 = **(ulonglong **)(*(longlong *)(param_2 + 0x30) + 0x60);
  if ((int)(uint)uVar5 < 0) {
    local_454 = 3;
    if ((uVar5 & 0x7fffffff) == 0) goto LAB_14000f098;
  }
  else {
    local_454 = 4;
LAB_14000f098:
    _Dst = (longlong *)(param_3 + 0x150);
    plVar7 = _Dst;
    ExAcquireFastMutex();
    *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
    bVar1 = true;
    lVar4 = CdLookupFcbTable(plVar7,param_3,uVar5);
    if (lVar4 != 0) {
      uVar9 = *(uint *)(param_2 + 0x10);
      plVar7 = (longlong *)(ulonglong)uVar9;
      if ((*(uint *)(lVar4 + 0xb0) & 0x10) == 0) {
        if ((uVar9 & 1) != 0) {
          local_448 = -0x3ffffefd;
          goto LAB_14000f480;
        }
      }
      else if ((uVar9 & 0x40) != 0) {
        local_448 = -0x3fffff46;
        goto LAB_14000f480;
      }
      bVar1 = false;
      if (*param_4 != 0) {
        ExReleaseResourceLite(*(longlong *)(*param_4 + 200) + 0x20);
      }
      uVar5 = CdAcquireResource((longlong)param_1,*(longlong *)(lVar4 + 200) + 0x20,'\x01',0);
      if ((char)uVar5 == '\0') {
        *(int *)(lVar4 + 0xa4) = *(int *)(lVar4 + 0xa4) + 1;
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex();
        CdAcquireResource((longlong)param_1,*(longlong *)(lVar4 + 200) + 0x20,'\0',0);
        ExAcquireFastMutex(_Dst);
        *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
        *(int *)(lVar4 + 0xa4) = *(int *)(lVar4 + 0xa4) + -1;
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex(_Dst);
      }
      else {
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex(_Dst);
      }
      *param_4 = lVar4;
      uVar9 = *(uint *)(*(longlong *)(param_2 + 8) + 0x10);
      plVar7 = (longlong *)(ulonglong)uVar9;
      if ((uVar9 & 0x50156) == 0) {
        local_448 = CdCompleteFcbOpen((short *)param_1,param_2,param_3,param_4,local_454,1,uVar9);
        plVar7 = param_1;
      }
      goto LAB_14000f480;
    }
    uStack_434 = (uint)(uVar5 >> 0x20);
    local_450 = CONCAT44(uStack_434,0x80000000);
    lVar4 = CdLookupFcbTable(plVar7,param_3,local_450);
    if (lVar4 == 0) {
      *(undefined8 *)(param_3 + 0x188) = 0;
      ExReleaseFastMutex();
      if (uStack_434 <= *(uint *)(*(longlong *)(param_3 + 0x58) + 0x20)) {
        bVar3 = true;
        CdLookupPathEntry((longlong)param_1,*(uint *)(*(longlong *)(param_3 + 0x58) + 0x1e0),1,
                          '\x01',local_418);
        do {
          _Dst = param_1;
          uVar5 = CdLookupNextPathEntry((longlong)param_1,local_418,&local_3f8);
          if ((char)uVar5 == '\0') break;
        } while (local_3f4 <= uStack_434);
      }
    }
    else {
      uVar6 = CdAcquireResource((longlong)param_1,*(longlong *)(lVar4 + 200) + 0x20,'\x01',0);
      if ((char)uVar6 == '\0') {
        *(int *)(lVar4 + 0xa4) = *(int *)(lVar4 + 0xa4) + 1;
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex();
        CdAcquireResource((longlong)param_1,*(longlong *)(lVar4 + 200) + 0x20,'\0',0);
        ExAcquireFastMutex(_Dst);
        *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
        *(int *)(lVar4 + 0xa4) = *(int *)(lVar4 + 0xa4) + -1;
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex();
      }
      else {
        *(undefined8 *)(param_3 + 0x188) = 0;
        ExReleaseFastMutex();
      }
      *param_4 = lVar4;
      uVar9 = (uint)uVar5 & 0x7fffffff;
      if (*(longlong *)(lVar4 + 0x1d8) == 0) {
        _Dst = param_1;
        CdCreateInternalStream
                  (param_1,*(longlong *)(lVar4 + 0x78),lVar4,(undefined4 *)(lVar4 + 0x158));
      }
      if (uVar9 <= *(uint *)(lVar4 + 0x20)) {
        local_348 = local_2e8;
        local_340 = local_208;
        local_338 = local_128;
        local_31e = 0x18;
        local_318 = local_300;
        lVar8 = lVar4;
        CdLookupDirent((longlong)param_1,lVar4,*(uint *)(lVar4 + 0x1e0),local_208);
        CdUpdateDirentFromRawDirent((longlong)param_1,lVar8,local_340,(int *)(local_340 + 4));
        bVar2 = true;
        do {
          _Dst = param_1;
          uVar5 = CdLookupNextInitialFileDirent((longlong)param_1,lVar4,&local_348);
          if ((char)uVar5 == '\0') break;
        } while (*(uint *)(local_340 + 4) <= uVar9);
      }
    }
  }
  bVar1 = false;
  local_448 = -0x3ffffff3;
  plVar7 = _Dst;
LAB_14000f480:
  if (bVar1) {
    *(undefined8 *)(param_3 + 0x188) = 0;
    plVar7 = (longlong *)(param_3 + 0x150);
    ExReleaseFastMutex();
  }
  if (bVar2) {
    CdCleanupFileContext(plVar7,(longlong)&local_348);
  }
  if (bVar3) {
    if (local_408 != 0) {
      CcUnpinData();
      local_408 = 0;
    }
    if ((local_3fc != '\0') && (local_418[0] != 0)) {
      ExFreePoolWithTag(local_418[0],0);
      local_418[0] = 0;
    }
    if (((local_3d8 & 1) != 0) && (local_3c8 != 0)) {
      ExFreePoolWithTag(local_3c8,0);
    }
  }
  return local_448;
}



===== CdOpenDirectoryFromPathEntry @ 14000f55c =====

int CdOpenDirectoryFromPathEntry
              (short *param_1,longlong param_2,longlong param_3,longlong *param_4,ushort *param_5,
              char param_6,char param_7,undefined4 *param_8,char param_9,longlong param_10)

{
  longlong lVar1;
  ushort *puVar2;
  ulonglong uVar3;
  short *psVar4;
  longlong lVar5;
  char cVar6;
  char local_47 [3];
  uint local_44;
  int local_40;
  undefined8 local_38;
  longlong local_30;
  
  local_44 = 0;
  local_47[0] = '\0';
  local_30 = 0;
  local_40 = 0;
  if ((param_9 != '\0') && ((*(uint *)(*(longlong *)(param_2 + 8) + 0x10) & 0x50156) != 0)) {
    return -0x3fffffde;
  }
  if ((param_10 != 0) && (local_44 = 0, (*(byte *)(param_10 + 4) & 3) != 0)) {
    local_44 = 2;
  }
  if (param_6 != '\0') {
    local_44 = local_44 | 4;
  }
  local_38 = (ushort *)CONCAT44(param_8[1],0x80000000);
  ExAcquireFastMutex(param_3 + 0x150);
  *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
  psVar4 = param_1;
  puVar2 = CdCreateFcb((longlong)param_1,local_38,0x304,(ushort **)local_47);
  local_38 = puVar2;
  if (local_47[0] == '\0') {
    CdInitializeFcbFromPathEntry(psVar4,(longlong)puVar2,*param_4,param_8);
  }
  uVar3 = CdAcquireResource((longlong)param_1,*(longlong *)(puVar2 + 100) + 0x20,'\x01',0);
  lVar5 = param_3 + 0x150;
  if ((char)uVar3 == '\0') {
    *(int *)(puVar2 + 0x52) = *(int *)(puVar2 + 0x52) + 1;
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex();
    ExReleaseResourceLite(*(longlong *)(*param_4 + 200) + 0x20);
    CdAcquireResource((longlong)param_1,*(longlong *)(puVar2 + 100) + 0x20,'\0',0);
    CdAcquireResource((longlong)param_1,*(longlong *)(*param_4 + 200) + 0x20,'\0',0);
    lVar5 = param_3 + 0x150;
    ExAcquireFastMutex(lVar5);
    *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
    *(int *)(puVar2 + 0x52) = *(int *)(puVar2 + 0x52) + -1;
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex();
    puVar2 = local_38;
  }
  else {
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex();
  }
  lVar1 = *param_4;
  *param_4 = (longlong)puVar2;
  local_30 = lVar1;
  if (param_7 == '\0') {
    CdInsertPrefix(lVar5,(longlong)puVar2,(ushort *)(param_8 + 10),'\0','\0',lVar1);
    if (param_6 == '\0') goto LAB_14000f7f2;
    param_5 = (ushort *)(param_8 + 0x12);
    cVar6 = '\0';
  }
  else {
    CdInsertPrefix(lVar5,(longlong)puVar2,param_5,'\0','\x01',lVar1);
    if (param_6 == '\0') goto LAB_14000f7f2;
    cVar6 = '\x01';
  }
  CdInsertPrefix(lVar5,(longlong)puVar2,param_5,'\x01',cVar6,lVar1);
LAB_14000f7f2:
  ExReleaseResourceLite(*(longlong *)(lVar1 + 200) + 0x20);
  local_30 = 0;
  if (param_9 != '\0') {
    local_40 = CdCompleteFcbOpen(param_1,param_2,param_3,param_4,3,local_44,
                                 *(uint *)(*(longlong *)(param_2 + 8) + 0x10));
  }
  return local_40;
}



===== CdOpenExistingFcb @ 14000f860 =====

int CdOpenExistingFcb(short *param_1,longlong param_2,longlong *param_3,int param_4,char param_5,
                     longlong param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = -0x3fffffde;
  uVar1 = *(uint *)(*(longlong *)(param_2 + 8) + 0x10);
  if ((uVar1 & (-(uint)(param_4 != 2) & 0x116 | 0x50040)) == 0) {
    uVar3 = -(uint)(param_5 != '\0') & 4;
    if ((param_6 != 0) &&
       (uVar3 = uVar3 | *(uint *)(param_6 + 4) & 8, (*(uint *)(param_6 + 4) & 3) != 0)) {
      uVar3 = uVar3 | 2;
    }
    iVar2 = CdCompleteFcbOpen(param_1,param_2,*(longlong *)(*param_3 + 0x78),param_3,param_4,uVar3,
                              uVar1);
  }
  return iVar2;
}



===== CdOpenFileFromFileContext @ 14000f914 =====

int CdOpenFileFromFileContext
              (short *param_1,longlong param_2,longlong param_3,longlong *param_4,ushort *param_5,
              char param_6,char param_7,longlong param_8,longlong param_9)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  ushort *puVar4;
  longlong lVar5;
  char cVar6;
  char local_57 [3];
  uint local_54;
  ushort *local_50;
  longlong local_48;
  
  local_57[0] = '\0';
  local_48 = 0;
  if ((*(uint *)(*(longlong *)(param_2 + 8) + 0x10) & 0x50156) != 0) {
    return -0x3fffffde;
  }
  local_54 = 0;
  if (param_5[8] != 0) {
    local_54 = 8;
  }
  if ((param_9 != 0) && ((*(uint *)(param_9 + 4) & 3) != 0)) {
    local_54 = local_54 | 2;
  }
  if (param_6 != '\0') {
    local_54 = local_54 | 4;
  }
  local_50 = (ushort *)((ulonglong)*(uint *)(*param_4 + 0x9c) << 0x20);
  uVar3 = Feature_2054323513__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) && (*(int *)(*(longlong *)(param_8 + 8) + 0x20) < 0)) {
    return -0x3fffffce;
  }
  local_50 = (ushort *)CONCAT44(local_50._4_4_,*(undefined4 *)(*(longlong *)(param_8 + 8) + 0x20));
  ExAcquireFastMutex(param_3 + 0x150);
  *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
  puVar4 = CdCreateFcb((longlong)param_1,local_50,0x305,(ushort **)local_57);
  local_50 = puVar4;
  if (local_57[0] == '\0') {
    CdInitializeFcbFromFileContext((longlong)param_1,(longlong)puVar4,*param_4,param_8);
  }
  uVar3 = CdAcquireResource((longlong)param_1,*(longlong *)(puVar4 + 100) + 0x20,'\x01',0);
  if ((char)uVar3 == '\0') {
    *(int *)(puVar4 + 0x52) = *(int *)(puVar4 + 0x52) + 1;
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex(param_3 + 0x150);
    ExReleaseResourceLite(*(longlong *)(*param_4 + 200) + 0x20);
    CdAcquireResource((longlong)param_1,*(longlong *)(puVar4 + 100) + 0x20,'\0',0);
    CdAcquireResource((longlong)param_1,*(longlong *)(*param_4 + 200) + 0x20,'\0',0);
    lVar5 = param_3 + 0x150;
    ExAcquireFastMutex(lVar5);
    *(void **)(param_3 + 0x188) = SystemReserved1[0xf];
    *(int *)(puVar4 + 0x52) = *(int *)(puVar4 + 0x52) + -1;
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex();
    puVar4 = local_50;
  }
  else {
    *(undefined8 *)(param_3 + 0x188) = 0;
    lVar5 = param_3 + 0x150;
    ExReleaseFastMutex();
  }
  lVar1 = *param_4;
  *param_4 = (longlong)puVar4;
  local_48 = lVar1;
  if (param_7 == '\0') {
    if ((param_5[8] != 0) ||
       (CdInsertPrefix(lVar5,(longlong)puVar4,(ushort *)(*(longlong *)(param_8 + 8) + 0x58),'\0',
                       '\0',lVar1), param_6 == '\0')) goto LAB_14000fbe0;
    param_5 = (ushort *)(*(longlong *)(param_8 + 8) + 0x78);
    cVar6 = '\0';
  }
  else {
    CdInsertPrefix(lVar5,(longlong)puVar4,param_5,'\0','\x01',lVar1);
    if (param_6 == '\0') goto LAB_14000fbe0;
    cVar6 = '\x01';
  }
  CdInsertPrefix(lVar5,(longlong)puVar4,param_5,'\x01',cVar6,lVar1);
LAB_14000fbe0:
  ExReleaseResourceLite(*(longlong *)(lVar1 + 200) + 0x20);
  local_48 = 0;
  iVar2 = CdCompleteFcbOpen(param_1,param_2,param_3,param_4,4,local_54,
                            *(uint *)(*(longlong *)(param_2 + 8) + 0x10));
  return iVar2;
}



===== CdCommonDevControl @ 14000fc40 =====

uint CdCommonDevControl(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  uVar7 = *(uint *)(puVar1[6] + 0x20) & 7;
  if ((uVar7 == 0) || (lVar2 = *(longlong *)(puVar1[6] + 0x18), uVar7 != 2)) {
    uVar7 = 0xc000000d;
LAB_14000fd55:
    CdCompleteRequest(param_1,param_2,uVar7);
  }
  else {
    if (*(int *)(puVar1 + 3) == 0x24000) {
      CdVerifyVcb((longlong)param_1,*(longlong *)(lVar2 + 0x78));
    }
    else if (*(int *)(puVar1 + 3) == 0x20040) {
      CdVerifyVcb((longlong)param_1,*(longlong *)(lVar2 + 0x78));
      if (3 < *(uint *)(puVar1 + 1)) {
        **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(*(longlong *)(lVar2 + 0x78) + 0x218);
        *(undefined8 *)(param_2 + 0x38) = 4;
        CdCompleteRequest(param_1,param_2,0);
        return 0;
      }
      uVar7 = 0xc0000023;
      goto LAB_14000fd55;
    }
    lVar2 = *(longlong *)(param_2 + 0xb8);
    uVar6 = puVar1[1];
    *(undefined8 *)(lVar2 + -0x48) = *puVar1;
    *(undefined8 *)(lVar2 + -0x40) = uVar6;
    uVar6 = puVar1[3];
    *(undefined8 *)(lVar2 + -0x38) = puVar1[2];
    *(undefined8 *)(lVar2 + -0x30) = uVar6;
    uVar6 = puVar1[5];
    *(undefined8 *)(lVar2 + -0x28) = puVar1[4];
    *(undefined8 *)(lVar2 + -0x20) = uVar6;
    uVar3 = *(undefined4 *)((longlong)puVar1 + 0x34);
    uVar4 = *(undefined4 *)(puVar1 + 7);
    uVar5 = *(undefined4 *)((longlong)puVar1 + 0x3c);
    *(undefined4 *)(lVar2 + -0x18) = *(undefined4 *)(puVar1 + 6);
    *(undefined4 *)(lVar2 + -0x14) = uVar3;
    *(undefined4 *)(lVar2 + -0x10) = uVar4;
    *(undefined4 *)(lVar2 + -0xc) = uVar5;
    *(undefined8 *)(lVar2 + -8) = puVar1[8];
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar2 + -8) = 0;
    *(code **)(lVar2 + -0x10) = CdDevCtrlCompletionRoutine;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar7 = IofCallDriver(*(undefined8 *)(param_1[2] + 0x10));
    CdCompleteRequest(param_1,0,0);
  }
  return uVar7;
}



===== CdCreateUserMdl @ 14000fd7c =====

undefined8 CdCreateUserMdl(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = -0x3fffff66;
  lVar1 = IoAllocateMdl(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x70),param_2,0,0,
                        *(longlong *)(param_1 + 8));
  if (lVar1 != 0) {
    MmProbeAndLockPages(lVar1,CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 8) >> 8),
                                       *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x40)));
    iVar2 = 0;
  }
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,iVar2,'\0',0xa0000,0x52c);
  }
  return 0;
}



===== CdFinishBuffers @ 14000fe58 =====

undefined1 CdFinishBuffers(longlong param_1,longlong param_2,int param_3,char param_4,char param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  puVar3 = (undefined8 *)((ulonglong)(param_3 - 1) * 0x40 + param_2);
  if (param_3 != 0) {
    do {
      if (*(uint *)(puVar3 + 4) != 0) {
        if (param_4 == '\0') {
          memmove((void *)puVar3[2],
                  (void *)((ulonglong)*(uint *)((longlong)puVar3 + 0x24) + puVar3[3]),
                  (ulonglong)*(uint *)(puVar3 + 4));
          uVar4 = 1;
        }
        if (puVar3[5] != *(longlong *)(*(longlong *)(param_1 + 8) + 8)) {
          if (puVar3[5] != 0) {
            IoFreeMdl();
          }
          if (puVar3[3] != 0) {
            if (param_5 == '\0') {
              ExFreePoolWithTag(puVar3[3],0);
              puVar3[3] = 0;
            }
            else {
              lVar1 = *(longlong *)(param_1 + 0x10);
              ExAcquireFastMutex(lVar1 + 0x150);
              *(void **)(lVar1 + 0x188) = SystemReserved1[0xf];
              if (*(longlong *)(lVar1 + 0x70) != 0) {
                ExFreePoolWithTag();
                *(undefined8 *)(lVar1 + 0x70) = 0;
              }
              param_5 = '\0';
              *(undefined8 *)(lVar1 + 0x70) = puVar3[3];
              uVar2 = *puVar3;
              *(undefined8 *)(lVar1 + 0x188) = 0;
              *(undefined8 *)(lVar1 + 0x78) = uVar2;
              ExReleaseFastMutex(lVar1 + 0x150);
            }
          }
        }
      }
      if (puVar3[7] != 0) {
        if (*(longlong *)(puVar3[7] + 8) != 0) {
          IoFreeMdl();
        }
        IoFreeIrp(puVar3[7]);
      }
      puVar3 = puVar3 + -8;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar4;
}



===== CdHijackIrpAndFlushDevice @ 14000ffdc =====

int CdHijackIrpAndFlushDevice(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  puVar1[-5] = puVar1[4];
  puVar1[-4] = puVar1[5];
  *(undefined4 *)(puVar1 + -3) = *(undefined4 *)(puVar1 + 6);
  *(undefined4 *)((longlong)puVar1 + -0x14) = *(undefined4 *)((longlong)puVar1 + 0x34);
  *(undefined4 *)(puVar1 + -2) = *(undefined4 *)(puVar1 + 7);
  *(undefined4 *)((longlong)puVar1 + -0xc) = *(undefined4 *)((longlong)puVar1 + 0x3c);
  puVar1[-1] = puVar1[8];
  *(undefined2 *)(puVar1 + -9) = 9;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = CdSyncCompletionRoutine;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  iVar3 = IofCallDriver(param_3,param_2);
  if (iVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar3 = *(int *)(param_2 + 0x30);
  }
  iVar4 = 0;
  if (iVar3 != -0x3ffffff0) {
    iVar4 = iVar3;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  return iVar4;
}



===== CdMultipleAsync @ 1400100cc =====

void CdMultipleAsync(longlong param_1,short *param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong *plVar9;
  code *pcVar10;
  ulonglong *puVar11;
  
  pcVar10 = CdMultiAsyncCompletionRoutine;
  uVar7 = (ulonglong)param_3;
  if ((*(uint *)(param_1 + 0x20) & 4) != 0) {
    pcVar10 = CdMultiSyncCompletionRoutine;
  }
  if (((*param_2 == 0x304) && (*(longlong *)(*(longlong *)(param_2 + 0x3c) + 0x238) != 0)) &&
     (*(int *)(*(longlong *)(param_1 + 0x10) + 0x34) == 2)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  lVar1 = *(longlong *)(param_1 + 8);
  uVar5 = 0;
  if (param_3 != 0) {
    do {
      uVar8 = (uint)uVar5;
      puVar11 = (ulonglong *)(param_4 + uVar5 * 0x40);
      if (bVar3) {
        cVar4 = CdReadDirDataThroughCache(param_1,puVar11);
        uVar8 = uVar8 & -(uint)(cVar4 != '\0');
        bVar3 = (bool)(bVar3 & cVar4 != '\0');
      }
      else {
        uVar5 = IoMakeAssociatedIrp(lVar1,*(char *)(*(longlong *)
                                                     (*(longlong *)(param_1 + 0x10) + 0x10) + 0x4c)
                                          + '\x01');
        puVar11[7] = uVar5;
        if (uVar5 == 0) {
          *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xb74);
        }
        lVar6 = IoAllocateMdl(puVar11[6],(int)puVar11[1],0,0,uVar5);
        if (lVar6 == 0) {
          *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xb84);
        }
        IoBuildPartialMdl(puVar11[5],lVar6);
        *(char *)(uVar5 + 0x43) = *(char *)(uVar5 + 0x43) + -1;
        lVar6 = *(longlong *)(uVar5 + 0xb8);
        *(undefined1 **)(uVar5 + 0xb8) = (undefined1 *)(lVar6 + -0x48);
        *(undefined1 *)(lVar6 + -0x48) = 3;
        *(int *)(lVar6 + -0x40) = (int)puVar11[1];
        *(ulonglong *)(lVar6 + -0x30) = *puVar11;
        uVar2 = *(undefined8 *)(param_1 + 0x30);
        lVar6 = *(longlong *)(uVar5 + 0xb8);
        *(code **)(lVar6 + -0x10) = pcVar10;
        *(undefined8 *)(lVar6 + -8) = uVar2;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        lVar6 = *(longlong *)(uVar5 + 0xb8);
        *(undefined1 *)(lVar6 + -0x48) = 3;
        *(int *)(lVar6 + -0x40) = (int)puVar11[1];
        *(ulonglong *)(lVar6 + -0x30) = *puVar11;
      }
      uVar5 = (ulonglong)(uVar8 + 1);
    } while (uVar8 + 1 < param_3);
  }
  if (bVar3) {
    if ((*(uint *)(param_1 + 0x20) & 4) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30) = 0;
      KeSetEvent(*(longlong *)(param_1 + 0x30) + 0x18,0,0);
    }
  }
  else {
    **(uint **)(param_1 + 0x30) = param_3;
    *(longlong *)(*(longlong *)(param_1 + 0x30) + 8) = lVar1;
    *(undefined4 *)(lVar1 + 0x18) = 1;
    if (((byte)*(undefined4 *)(param_1 + 0x20) & 0x14) == 0x10) {
      *(ulonglong *)(*(ulonglong *)(param_1 + 0x30) + 0x20) = *(ulonglong *)(param_1 + 0x30) | 3;
      ExSetResourceOwnerPointer
                (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x18),
                 *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x20));
    }
    if (param_3 != 0) {
      plVar9 = (longlong *)(param_4 + 0x38);
      do {
        lVar1 = *plVar9;
        *plVar9 = 0;
        if (lVar1 != 0) {
          IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10));
        }
        plVar9 = plVar9 + 8;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
  }
  return;
}



===== CdMultipleXAAsync @ 140010364 =====

void CdMultipleXAAsync(longlong param_1,uint param_2,longlong param_3,longlong param_4,uint param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 in_register_00000014;
  ulonglong uVar8;
  uint *puVar9;
  undefined8 *puVar10;
  uint *puVar11;
  uint local_res10;
  
  lVar7 = CONCAT44(in_register_00000014,param_2);
  local_res10 = 0;
  lVar4 = *(longlong *)(param_1 + 8);
  uVar8 = (ulonglong)param_2;
  if (param_2 != 0) {
    puVar11 = (uint *)(param_4 + 8);
    puVar9 = (uint *)(param_3 + 8);
    do {
      lVar6 = IoMakeAssociatedIrp(lVar4,CONCAT71((int7)((ulonglong)lVar7 >> 8),
                                                 *(char *)(*(longlong *)
                                                            (*(longlong *)(param_1 + 0x10) + 0x10) +
                                                          0x4c) + '\x01'));
      *(longlong *)(puVar9 + 0xc) = lVar6;
      if (lVar6 == 0) {
        *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xc62);
      }
      lVar7 = IoAllocateMdl(*(undefined8 *)(puVar9 + 10),(*puVar9 >> 0xb) * 0x930,0,0,lVar6);
      if (lVar7 == 0) {
        *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xc7b);
      }
      IoBuildPartialMdl(*(undefined8 *)(puVar9 + 8),lVar7);
      *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
      lVar7 = *(longlong *)(lVar6 + 0xb8);
      *(undefined1 **)(lVar6 + 0xb8) = (undefined1 *)(lVar7 + -0x48);
      local_res10 = local_res10 + 1;
      *(undefined1 *)(lVar7 + -0x48) = 3;
      *(uint *)(lVar7 + -0x40) = *puVar9;
      *(undefined8 *)(lVar7 + -0x30) = *(undefined8 *)(puVar9 + -2);
      lVar7 = *(longlong *)(lVar6 + 0xb8);
      *(undefined8 *)(lVar7 + -8) = *(undefined8 *)(param_1 + 0x30);
      *(code **)(lVar7 + -0x10) = CdMultiSyncCompletionRoutine;
      *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      puVar2 = puVar11 + -2;
      lVar7 = *(longlong *)(lVar6 + 0xb8);
      *(undefined8 *)puVar2 = *(undefined8 *)(puVar9 + -2);
      *puVar11 = *puVar9 >> 0xb;
      puVar11[1] = param_5;
      *(undefined1 *)(lVar7 + -0x48) = 0xe;
      uVar3 = *puVar11;
      puVar11 = puVar11 + 4;
      *(uint *)(lVar7 + -0x40) = uVar3 * 0x930;
      puVar1 = puVar9 + 10;
      puVar9 = puVar9 + 0x10;
      *(undefined8 *)(lVar6 + 0x70) = *(undefined8 *)puVar1;
      *(undefined4 *)(lVar7 + -0x38) = 0x10;
      *(uint **)(lVar7 + -0x28) = puVar2;
      *(undefined4 *)(lVar7 + -0x30) = 0x2403e;
    } while (local_res10 < param_2);
  }
  **(uint **)(param_1 + 0x30) = param_2;
  *(longlong *)(*(longlong *)(param_1 + 0x30) + 8) = lVar4;
  *(undefined4 *)(lVar4 + 0x18) = 1;
  if (param_2 != 0) {
    puVar10 = (undefined8 *)(param_3 + 0x38);
    do {
      uVar5 = *puVar10;
      *puVar10 = 0;
      IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),uVar5);
      puVar10 = puVar10 + 8;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return;
}



===== CdNonCachedRead @ 140010580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CdNonCachedRead(void *param_1,short *param_2,longlong param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined1 auStackY_228 [32];
  uint local_1d4;
  undefined1 local_1d0;
  uint local_1cc;
  uint local_1c8;
  int local_1c4;
  uint local_1c0 [2];
  longlong local_1b8;
  uint local_1b0;
  uint local_1ac;
  void *local_1a8;
  longlong local_1a0;
  undefined8 *local_198;
  ulonglong local_188 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_228;
  local_1d4 = 0;
  uVar4 = 0;
  local_1c8 = 0;
  local_1c0[0] = 0;
  local_1cc = local_1cc & 0xffffff00;
  bVar2 = true;
  local_1b8 = param_3;
  local_1a8 = param_1;
  if (*(longlong *)(*(longlong *)((longlong)param_1 + 8) + 8) == 0) {
    CdCreateUserMdl((longlong)param_1,(ulonglong)param_4);
  }
  lVar1 = *(longlong *)(*(longlong *)((longlong)param_1 + 8) + 8);
  if (lVar1 == 0) {
    puVar9 = *(undefined8 **)(*(longlong *)((longlong)param_1 + 8) + 0x70);
  }
  else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    puVar9 = (undefined8 *)MmMapLockedPagesSpecifyCache();
  }
  else {
    puVar9 = *(undefined8 **)(lVar1 + 0x18);
  }
  if (puVar9 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0xa0000,0x17a);
  }
  if (((char)*(undefined4 *)(*(longlong *)(param_2 + 0x3c) + 0x30) < '\0') &&
     ((ushort)(*param_2 - 0x303U) < 2)) {
    CdReadAudioSystemFile((longlong)param_1,param_2,param_3,param_4,puVar9);
    return 0;
  }
  if ((((*param_2 == 0x304) && (*(longlong *)(*(longlong *)(param_2 + 0x3c) + 0x238) != 0)) &&
      (*(int *)(*(longlong *)((longlong)param_1 + 0x10) + 0x34) == 2)) &&
     ((*(uint *)((longlong)param_1 + 0x20) & 4) == 0)) {
    KeInitializeEvent(*(longlong *)((longlong)param_1 + 0x30) + 0x18,0,0);
    *(uint *)((longlong)param_1 + 0x20) = *(uint *)((longlong)param_1 + 0x20) | 4;
  }
  do {
    memset(local_188,0,0x140);
    cVar3 = CdPrepareBuffers(param_1,*(longlong *)((longlong)param_1 + 8),(longlong)param_2,
                             (longlong)puVar9,uVar4,param_3,param_4,(longlong)local_188,
                             (int *)&local_1d4,(int *)local_1c0);
    uVar4 = local_1c0[0];
    uVar6 = local_1d4;
    uVar8 = (ulonglong)local_1c0[0];
    if ((local_1c0[0] < param_4) && ((*(uint *)((longlong)param_1 + 0x20) & 4) == 0)) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0xa0000,0x1cb);
    }
    if (((local_1d4 == 1) && (cVar3 == '\0')) && (bVar2)) {
      CdSingleAsync((longlong)param_1,local_188,param_2);
      local_1d4 = 0;
      if ((*(uint *)((longlong)param_1 + 0x20) & 4) == 0) {
        *(uint *)((longlong)param_1 + 0x20) = *(uint *)((longlong)param_1 + 0x20) & 0xfffffeff;
        goto LAB_1400108a9;
      }
      CdWaitSync((longlong)param_1);
      iVar7 = *(int *)(*(longlong *)((longlong)param_1 + 8) + 0x30);
LAB_1400108ae:
      uVar6 = 0;
      local_1c4 = iVar7;
      goto LAB_1400108b2;
    }
    CdMultipleAsync((longlong)param_1,param_2,local_1d4,(longlong)local_188);
    if ((*(uint *)((longlong)param_1 + 0x20) & 4) == 0) {
      *(uint *)((longlong)param_1 + 0x20) = *(uint *)((longlong)param_1 + 0x20) & 0xfffffeff;
LAB_1400108a9:
      local_1d4 = 0;
      iVar7 = 0x103;
      goto LAB_1400108ae;
    }
    CdWaitSync((longlong)param_1);
    iVar7 = *(int *)(*(longlong *)((longlong)param_1 + 8) + 0x30);
    local_1c4 = iVar7;
    if (iVar7 < 0) goto LAB_1400108b2;
    if (cVar3 == '\0') {
      uVar5 = (ulonglong)local_1cc;
    }
    else {
      cVar3 = CdFinishBuffers((longlong)param_1,(longlong)local_188,uVar6,'\0','\0');
      uVar5 = (ulonglong)(local_1cc & 0xff);
      if (cVar3 != '\0') {
        uVar5 = 1;
      }
      local_1cc = (uint)uVar5;
      local_1d0 = (undefined1)uVar5;
    }
    uVar6 = 0;
    local_1d4 = 0;
    param_4 = param_4 - uVar4;
    param_3 = local_1b8 + uVar8;
    puVar9 = (undefined8 *)((longlong)puVar9 + uVar8);
    uVar4 = local_1c8 + uVar4;
    bVar2 = false;
    local_1c8 = uVar4;
    local_1b8 = param_3;
    local_1b0 = param_4;
    local_1ac = uVar4;
    local_1a0 = param_3;
    local_198 = puVar9;
  } while (param_4 != 0);
  if ((char)uVar5 != '\0') {
    KeFlushIoBuffers(*(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 8),
                     CONCAT71((int7)(uVar5 >> 8),1),0);
  }
LAB_1400108b2:
  if (uVar6 != 0) {
    CdFinishBuffers((longlong)param_1,(longlong)local_188,uVar6,'\x01','\0');
  }
  return iVar7;
}



===== CdNonCachedXARead @ 140010920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CdNonCachedXARead(void *param_1,longlong param_2,ulonglong param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong _Size;
  longlong lVar9;
  void *_Dst;
  int iVar10;
  undefined1 auStackY_2a8 [32];
  undefined4 local_254;
  uint local_250;
  uint local_24c;
  ulonglong local_248;
  ulonglong local_240;
  uint local_238;
  int local_234;
  uint local_230;
  uint local_22c;
  int local_228;
  ulonglong local_220;
  void *local_218;
  void *local_210;
  undefined8 local_208;
  undefined8 uStack_200;
  ulonglong local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined4 local_1e0;
  undefined1 local_1dc [4];
  undefined1 local_1d8 [80];
  longlong local_188 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2a8;
  uVar5 = param_4 & 0xffffffff;
  local_234 = 0;
  local_208 = 0;
  uStack_200 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_1e8 = 0;
  local_1e0 = 0;
  local_24c = 0;
  local_248 = local_248 & 0xffffffff00000000;
  uVar8 = 0;
  local_250 = 0;
  bVar3 = false;
  lVar9 = *(longlong *)((longlong)param_1 + 8);
  local_210 = param_1;
  if (*(longlong *)(lVar9 + 8) == 0) {
    CdCreateUserMdl((longlong)param_1,uVar5);
    lVar9 = *(longlong *)((longlong)param_1 + 8);
  }
  iVar10 = (int)param_3;
  if (*(longlong *)(param_2 + 0x20) < (longlong)(param_3 + uVar5)) {
    uVar5 = (ulonglong)(uint)(*(int *)(param_2 + 0x20) - iVar10);
  }
  lVar2 = *(longlong *)(lVar9 + 8);
  if (lVar2 == 0) {
    _Dst = *(void **)(lVar9 + 0x70);
  }
  else if ((*(byte *)(lVar2 + 10) & 5) == 0) {
    _Dst = (void *)MmMapLockedPagesSpecifyCache();
  }
  else {
    _Dst = *(void **)(lVar2 + 0x18);
  }
  if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0xa0000,0x2ac);
  }
  if (0x2b < param_3) goto LAB_140010dc4;
  if ((*(uint *)(param_2 + 0xac) & 0x10) == 0) {
    uStack_200 = CONCAT44(uRam00000001400080a4,uRam00000001400080a0);
    local_1f8 = _DAT_1400080a8;
    local_1e8 = DAT_1400080b8;
    local_208 = CONCAT44(iRam000000014000809c + *(int *)(param_2 + 0x20),_CdXAFileHeader);
    local_1e0 = DAT_1400080c0 + *(int *)(param_2 + 0x20);
    uStack_1f0 = CONCAT62((int6)((ulonglong)uRam00000001400080b0 >> 0x10),
                          *(undefined2 *)(param_2 + 0xb4));
    uVar4 = uStack_1f0;
    uStack_1f0._5_3_ = (undefined3)((ulonglong)uRam00000001400080b0 >> 0x28);
    uStack_1f0._0_5_ = CONCAT14(*(undefined1 *)(param_2 + 0xb6),(int)uVar4);
    uVar7 = 0x2c - iVar10;
    _Size = (ulonglong)uVar7;
    uVar8 = (ulonglong)uVar7;
    local_250 = uVar7;
    local_240 = _Size;
    memmove(_Dst,local_1dc + -_Size,_Size);
LAB_140010d9d:
    local_248 = _Size;
  }
  else {
    lVar9 = *(longlong *)(param_2 + 0x78);
    if (-1 < (char)*(undefined4 *)(lVar9 + 0x30)) {
      uStack_200 = CONCAT44(uRam00000001400080d4,uRam00000001400080d0);
      local_1f8 = _DAT_1400080d8;
      uStack_1f0 = uRam00000001400080e0;
      local_1e8 = DAT_1400080e8;
      local_208 = CONCAT44(iRam00000001400080cc + *(int *)(param_2 + 0x20),_CdXAAudioPhileHeader);
      local_1e0 = DAT_1400080f0 + *(int *)(param_2 + 0x20);
      uVar7 = 0x2c - iVar10;
      _Size = (ulonglong)uVar7;
      uVar8 = (ulonglong)uVar7;
      local_250 = uVar7;
      local_240 = uVar8;
      memmove(_Dst,local_1dc + -uVar8,(ulonglong)uVar7);
      goto LAB_140010d9d;
    }
    uVar8 = (ulonglong)*(byte *)(param_2 + 0xb6);
    lVar2 = *(longlong *)(lVar9 + 0x208);
    local_208 = _CdAudioPlayHeader;
    uStack_200 = uRam0000000140008100;
    local_1f8._0_6_ = (undefined6)_DAT_140008108;
    local_1f8 = (ulonglong)CONCAT16(*(undefined1 *)(lVar2 + 6 + uVar8 * 8),(undefined6)local_1f8);
    local_254 = CONCAT13(*(undefined1 *)(lVar2 + 8 + uVar8 * 8),
                         CONCAT12(*(undefined1 *)(lVar2 + 9 + uVar8 * 8),
                                  CONCAT11(*(undefined1 *)(lVar2 + 10 + uVar8 * 8),
                                           *(undefined1 *)(lVar2 + 0xb + uVar8 * 8))));
    uVar7 = local_254 + 0x96;
    uVar6 = uVar7 / 0x4b;
    local_1e8._7_1_ = (undefined1)((ulonglong)DAT_140008118 >> 0x38);
    uVar7 = CONCAT13(local_1e8._7_1_,
                     CONCAT12((char)(uVar6 / 0x3c),
                              CONCAT11((char)uVar6 + (char)((ulonglong)uVar6 / 0x3c) * -0x3c,
                                       (char)uVar7 + (char)((ulonglong)uVar7 / 0x4b) * -0x4b)));
    uStack_1f0._0_5_ =
         CONCAT14(*(undefined1 *)(lVar2 + 0xb + uVar8 * 8),
                  *(undefined4 *)(*(longlong *)(lVar9 + 8) + 0x18));
    uStack_1f0 = CONCAT17(*(undefined1 *)(lVar2 + 8 + uVar8 * 8),
                          CONCAT16(*(undefined1 *)(lVar2 + 9 + uVar8 * 8),
                                   CONCAT15(*(undefined1 *)(lVar2 + 10 + uVar8 * 8),
                                            (undefined5)uStack_1f0)));
    lVar9 = *(longlong *)(lVar9 + 0x208);
    local_1e8._0_4_ =
         CONCAT13(*(undefined1 *)(lVar9 + 0x10 + uVar8 * 8),
                  CONCAT12(*(undefined1 *)(lVar9 + 0x11 + uVar8 * 8),
                           CONCAT11(*(undefined1 *)(lVar9 + 0x12 + uVar8 * 8),
                                    *(undefined1 *)(lVar9 + 0x13 + uVar8 * 8))));
    if ((uint)local_1e8 < uStack_1f0._4_4_) {
      local_1e8 = (ulonglong)uVar7 << 0x20;
      uVar6 = 0;
    }
    else {
      uVar6 = (uint)local_1e8 - uStack_1f0._4_4_;
      local_1e8 = CONCAT44(uVar7,uVar6);
    }
    uVar7 = uVar6 / 0x4b;
    local_240 = CONCAT44((int)(local_240 >> 0x20),uVar7 / 0x3c);
    local_1e0._3_1_ = (undefined1)((uint)DAT_140008120 >> 0x18);
    local_1e0._0_3_ =
         CONCAT12((char)(uVar7 / 0x3c),
                  CONCAT11((char)uVar7 + (char)((ulonglong)uVar7 / 0x3c) * -0x3c,
                           (char)uVar6 + (char)((ulonglong)uVar6 / 0x4b) * -0x4b));
    uVar7 = 0x2c - iVar10;
    _Size = (ulonglong)uVar7;
    uVar8 = (ulonglong)uVar7;
    local_250 = uVar7;
    local_248 = _Size;
    memmove(_Dst,local_1dc + -_Size,_Size);
  }
  _Dst = (void *)((longlong)_Dst + (ulonglong)uVar7);
  local_22c = (uint)_Size;
  param_3 = param_3 + _Size;
  local_230 = (int)uVar5 - local_22c;
  uVar5 = (ulonglong)local_230;
  local_220 = param_3;
  local_218 = _Dst;
LAB_140010dc4:
  if ((*(uint *)(param_2 + 0xac) & 4) == 0) {
    uVar7 = (*(uint *)(param_2 + 0xac) & 0xff) >> 3 & 2;
  }
  else {
    uVar7 = 1;
  }
  local_238 = uVar7;
LAB_140010de7:
  do {
    uVar6 = (uint)uVar5;
    if (uVar6 == 0) {
      KeFlushIoBuffers(*(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 8),1,0);
LAB_140010f88:
      if (local_24c != 0) {
        CdFinishBuffers((longlong)param_1,(longlong)local_188,local_24c,'\x01','\0');
      }
      return local_234;
    }
    if (!bVar3) {
      memset(local_188,0,0x140);
      memset(local_1d8,0,0x50);
      CdPrepareXABuffers(param_1,*(longlong *)((longlong)param_1 + 8),param_2,_Dst,(uint)local_248,
                         param_3,uVar6,local_188,(int *)&local_24c,(int *)&local_250);
      uVar8 = (ulonglong)local_250;
    }
    if (local_24c != 0) {
      local_240 = CONCAT44(local_240._4_4_,local_24c);
      CdMultipleXAAsync((longlong)param_1,local_24c,(longlong)local_188,(longlong)local_1d8,uVar7);
      CdWaitSync((longlong)param_1);
      local_234 = *(int *)(*(longlong *)((longlong)param_1 + 8) + 0x30);
      local_228 = local_234;
      if (local_234 < 0) {
        if ((bVar3) || ((*(uint *)(param_2 + 0xac) & 4) == 0)) goto LAB_140010f88;
        bVar3 = true;
        uVar7 = 0;
        local_238 = 0;
        *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x30) + 0x10) = 0;
        goto LAB_140010de7;
      }
      local_24c = 0;
      if (bVar3) {
        uVar1 = *(uint *)(param_2 + 0xac);
        *(uint *)(param_2 + 0xac) = uVar1 | 8;
        *(uint *)(param_2 + 0xac) = uVar1 & 0xfffffffb | 8;
        bVar3 = false;
      }
      CdFinishBuffers((longlong)param_1,(longlong)local_188,(int)local_240,'\0','\x01');
    }
    local_230 = uVar6 - (int)uVar8;
    uVar5 = (ulonglong)local_230;
    param_3 = param_3 + uVar8;
    _Dst = (void *)((longlong)_Dst + uVar8);
    local_22c = (int)local_248 + (int)uVar8;
    local_248 = (ulonglong)local_22c;
    local_220 = param_3;
    local_218 = _Dst;
  } while( true );
}



===== CdPerformDevIoCtrl @ 140010ff8 =====

void CdPerformDevIoCtrl(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                       undefined4 param_5,undefined8 param_6,char param_7,uint *param_8)

{
  undefined8 in_stack_ffffffffffffffe0;
  
  CdPerformDevIoCtrlEx
            (param_1,param_2,param_3,0,0,param_4,param_5,in_stack_ffffffffffffffe0,param_7,param_8);
  return;
}



===== CdPerformDevIoCtrlEx @ 140011040 =====

ulonglong CdPerformDevIoCtrlEx
                    (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,
                    char param_9,uint *param_10)

{
  byte *pbVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar4 = local_38;
  if (param_10 != (uint *)0x0) {
    puVar4 = param_10;
  }
  *puVar4 = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,param_3,param_4,param_5,param_6,param_7,0,&local_28,puVar4);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    if (param_9 != '\0') {
      pbVar1 = (byte *)(*(longlong *)(lVar2 + 0xb8) + -0x46);
      *pbVar1 = *pbVar1 | 2;
    }
    uVar3 = IofCallDriver(param_3,lVar2);
    if ((int)uVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar3 = (ulonglong)*puVar4;
    }
  }
  return uVar3;
}



===== CdPrepareBuffers @ 140011168 =====

undefined1
CdPrepareBuffers(void *param_1,longlong param_2,longlong param_3,longlong param_4,uint param_5,
                longlong param_6,uint param_7,longlong param_8,int *param_9,int *param_10)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  ulonglong local_res20;
  
  piVar2 = param_10;
  uVar8 = 0;
  puVar9 = (uint *)(param_8 + 8);
  *param_9 = 0;
  *param_10 = 0;
  local_res20 = 0;
  uVar10 = param_7;
  do {
    *param_9 = *param_9 + 1;
    *(longlong *)(puVar9 + 2) = param_4;
    CdLookupAllocation(param_1,param_3,param_6,(longlong *)&local_res20,&param_7);
    uVar7 = param_7;
    if (uVar10 < param_7) {
      uVar7 = uVar10;
    }
    if (((local_res20 & 0x7ff) == 0) && (((uVar7 & 0x7ff) == 0 || (0x7ff < uVar7)))) {
      *(ulonglong *)(puVar9 + -2) = local_res20;
      uVar7 = uVar7 & 0xfffff800;
      *puVar9 = uVar7;
      *(longlong *)(puVar9 + 4) = param_4;
      *(undefined8 *)(puVar9 + 8) = *(undefined8 *)(param_2 + 8);
      *(ulonglong *)(puVar9 + 10) = (ulonglong)param_5 + *(longlong *)(param_2 + 0x70);
      param_7 = uVar7;
    }
    else {
      param_7 = uVar7;
      if ((*(uint *)((longlong)param_1 + 0x20) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0xa0000,0x66e);
      }
      puVar9[7] = (uint)local_res20 & 0x7ff;
      *(ulonglong *)(puVar9 + -2) = local_res20 & 0xfffffffffffff800;
      uVar3 = Feature_719217978__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        uVar6 = puVar9[7] + 0x7ff + uVar7 & 0xfffff800;
        *puVar9 = uVar6;
        if (0x1000 < uVar6) {
          *puVar9 = 0x1000;
        }
      }
      else {
        uVar3 = (ulonglong)puVar9[7] + 0x7ff + (ulonglong)uVar7;
        uVar6 = (uint)uVar3 & 0xfffff800;
        if (0x1000 < (uVar3 & 0xfffffffffffff800)) {
          uVar6 = 0x1000;
        }
        *puVar9 = uVar6;
      }
      uVar3 = Feature_719217978__private_IsEnabledDeviceUsageNoInline();
      uVar6 = *puVar9;
      uVar1 = puVar9[7];
      if ((int)uVar3 == 0) {
        bVar11 = uVar1 + uVar7 < uVar6;
        bVar12 = uVar1 + uVar7 == uVar6;
      }
      else {
        uVar3 = (ulonglong)uVar7 + (ulonglong)uVar1;
        bVar11 = uVar3 < uVar6;
        bVar12 = uVar3 == uVar6;
      }
      if (!bVar11 && !bVar12) {
        uVar7 = uVar6 - uVar1;
        param_7 = uVar7;
      }
      puVar9[6] = uVar7;
      uVar4 = ExAllocatePoolWithTag(0x610,0x1000);
      *(undefined8 *)(puVar9 + 4) = uVar4;
      lVar5 = IoAllocateMdl(uVar4,0x1000,0,0,0);
      *(undefined8 *)(puVar9 + 10) = *(undefined8 *)(puVar9 + 4);
      *(longlong *)(puVar9 + 8) = lVar5;
      if (lVar5 == 0) {
        *(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0xa0000,0x6d1);
      }
      MmBuildMdlForNonPagedPool(lVar5);
      uVar8 = 1;
    }
    *piVar2 = *piVar2 + uVar7;
    uVar10 = uVar10 - uVar7;
    if ((uVar10 == 0) || (*param_9 == 5)) {
      return uVar8;
    }
    puVar9 = puVar9 + 0x10;
    param_5 = param_5 + uVar7;
    param_4 = param_4 + (ulonglong)uVar7;
    param_6 = param_6 + (ulonglong)uVar7;
  } while( true );
}



===== CdPrepareXABuffers @ 140011408 =====

void CdPrepareXABuffers(void *param_1,longlong param_2,longlong param_3,void *param_4,uint param_5,
                       longlong param_6,uint param_7,longlong *param_8,int *param_9,int *param_10)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  void *local_res20;
  
  uVar4 = param_7;
  lVar3 = param_6;
  param_6 = 0;
  uVar7 = lVar3 - 0x2c;
  param_7 = 0;
  if ((int)(uVar7 >> 0x20) == 0) {
    iVar10 = (int)((uVar7 & 0xffffffff) / 0x930);
    uVar8 = (ulonglong)(uint)(iVar10 << 0xb);
  }
  else {
    uVar8 = ((longlong)uVar7 / 0x930) * 0x800;
    iVar10 = (int)((longlong)uVar7 / 0x930);
  }
  uVar9 = ((int)lVar3 + iVar10 * -0x930) - 0x2c;
  uVar7 = (ulonglong)uVar9;
  *param_9 = 0;
  *param_10 = 0;
  plVar5 = param_8;
  local_res20 = param_4;
  param_8._0_4_ = (uint)((ulonglong)(uVar4 + 0x92f + uVar9) * 0xdee95c4d >> 0x20) & 0xfffff800;
  do {
    *param_9 = *param_9 + 1;
    plVar5[2] = (longlong)local_res20;
    CdLookupAllocation(param_1,param_3,uVar8,&param_6,&param_7);
    iVar10 = (int)uVar7;
    lVar3 = param_6;
    uVar9 = uVar4;
    if (param_6 == *(longlong *)(*(longlong *)(param_3 + 0x78) + 0x78)) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 0x78) + 0x150);
      lVar3 = param_6;
      *(void **)(*(longlong *)(param_3 + 0x78) + 0x188) = SystemReserved1[0xf];
      lVar1 = *(longlong *)(param_3 + 0x78);
      if ((param_6 != *(longlong *)(lVar1 + 0x78)) || (*(longlong *)(lVar1 + 0x70) == 0)) {
        *(undefined8 *)(lVar1 + 0x188) = 0;
        ExReleaseFastMutex(*(longlong *)(param_3 + 0x78) + 0x150);
        goto LAB_1400115bc;
      }
      if (0x930U - iVar10 <= uVar4) {
        uVar9 = 0x930U - iVar10;
      }
      memmove(local_res20,(void *)(uVar7 + *(longlong *)(lVar1 + 0x70)),(ulonglong)uVar9);
      *(undefined8 *)(*(longlong *)(param_3 + 0x78) + 0x188) = 0;
      ExReleaseFastMutex(*(longlong *)(param_3 + 0x78) + 0x150);
      param_7 = 0x800;
      *param_9 = *param_9 + -1;
      plVar5 = plVar5 + -8;
LAB_14001179a:
      uVar2 = 0x800;
    }
    else {
LAB_1400115bc:
      *plVar5 = lVar3;
      if ((uint)param_8 < param_7) {
        param_7 = (uint)param_8;
      }
      *(int *)((longlong)plVar5 + 0x24) = iVar10;
      if ((iVar10 != 0) || (uVar4 < 0x930)) {
        uVar9 = 0x930 - iVar10;
        *(undefined4 *)(plVar5 + 1) = 0x800;
        param_7 = 0x800;
        *(uint *)(plVar5 + 4) = uVar9;
        if (uVar4 < uVar9) {
          *(uint *)(plVar5 + 4) = uVar4;
          uVar9 = uVar4;
        }
        lVar3 = ExAllocatePoolWithTag(0x610,0x1000);
        plVar5[3] = lVar3;
        lVar3 = IoAllocateMdl(lVar3,0x1000,0,0,0);
        plVar5[6] = plVar5[3];
        plVar5[5] = lVar3;
        if (lVar3 == 0) {
          *(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0xa0000,0x8aa);
        }
        MmBuildMdlForNonPagedPool(lVar3);
        goto LAB_14001179a;
      }
      uVar2 = *(uint *)(*(longlong *)(param_3 + 0x78) + 0x224);
      if (uVar2 * 0x800 < param_7) {
        param_7 = uVar2 * 0x800;
      }
      else {
        uVar2 = param_7 + 0x7ff >> 0xb;
      }
      uVar11 = (ulonglong)*(uint *)(*(longlong *)(param_3 + 0x78) + 0x228);
      uVar2 = uVar2 * 0x930;
      uVar7 = (ulonglong)((uint)local_res20 & 0xfff);
      uVar6 = uVar2 + 0x92f;
      if (uVar11 < uVar7 + 0xfff + (ulonglong)((uVar6 / 0x930) * 0x930) >> 0xc) {
        do {
          param_7 = param_7 - 0x800;
          uVar2 = uVar2 - 0x930;
          uVar6 = uVar6 - 0x930;
        } while (uVar11 < (ulonglong)((uVar6 / 0x930) * 0x930) + 0xfff + uVar7 >> 0xc);
      }
      uVar6 = uVar2 + 0x92f;
      if (uVar4 < (uVar6 / 0x930) * 0x930) {
        do {
          param_7 = param_7 - 0x800;
          uVar2 = uVar2 - 0x930;
          uVar6 = uVar6 - 0x930;
        } while (uVar4 < (uVar6 / 0x930) * 0x930);
      }
      *(uint *)(plVar5 + 1) = param_7 + 0x7ff & 0xfffff800;
      plVar5[3] = (longlong)local_res20;
      plVar5[5] = *(longlong *)(param_2 + 8);
      plVar5[6] = (ulonglong)param_5 + *(longlong *)(param_2 + 0x70);
      if (uVar2 <= uVar4) {
        uVar9 = uVar2;
      }
      uVar2 = param_7;
    }
    *param_10 = *param_10 + uVar9;
    uVar4 = uVar4 - uVar9;
    if ((uVar4 == 0) || (*param_9 == 5)) {
      return;
    }
    param_8._0_4_ = (uint)param_8 - uVar2;
    local_res20 = (void *)((longlong)local_res20 + (ulonglong)uVar9);
    param_5 = param_5 + uVar9;
    plVar5 = plVar5 + 8;
    uVar8 = uVar8 + uVar2;
    uVar7 = 0;
  } while( true );
}



===== CdReadAudioSystemFile @ 140011830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CdReadAudioSystemFile
               (longlong param_1,short *param_2,longlong param_3,uint param_4,undefined8 *param_5)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 *_Dst;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_98 [32];
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined1 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_6c = param_4;
  local_68 = param_1;
  if (*param_2 == 0x303) {
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    local_38 = 0;
    local_34 = 0;
    local_60 = 0x1000000000001;
    uVar6 = param_4;
    if (9 < param_4) {
      uVar6 = 10;
    }
    uStack_58 = 0;
    memmove(param_5,&local_60,(ulonglong)uVar6);
  }
  else {
    uVar6 = 0;
    if (param_3 == 0) {
      local_78 = 2;
      local_74 = 0x44;
      *param_5 = 0;
      param_5[1] = 0;
      param_5[2] = 0;
      param_5[3] = 0;
      *(byte *)((longlong)param_5 + 0x19) = *(byte *)((longlong)param_5 + 0x19) | 2;
      *(undefined1 *)param_5 = 0x22;
      *(undefined2 *)(param_5 + 4) = 1;
      *(undefined2 *)((longlong)param_5 + 0x12) = 0x15f;
      *(undefined1 *)((longlong)param_5 + 0x14) = 1;
      *(undefined8 *)((longlong)param_5 + 0x23) = 0;
      *(undefined8 *)((longlong)param_5 + 0x2b) = 0;
      *(undefined8 *)((longlong)param_5 + 0x33) = 0;
      *(undefined8 *)((longlong)param_5 + 0x3b) = 0;
      *(byte *)((longlong)param_5 + 0x3b) = *(byte *)((longlong)param_5 + 0x3b) | 2;
      *(undefined1 *)((longlong)param_5 + 0x22) = 0x22;
      *(undefined2 *)((longlong)param_5 + 0x42) = 0x101;
      *(undefined2 *)((longlong)param_5 + 0x34) = 0x15f;
      *(undefined1 *)((longlong)param_5 + 0x36) = 1;
    }
    else {
      lVar5 = 0;
      do {
        uVar7 = uVar6;
        lVar5 = lVar5 + 0x800;
        uVar6 = uVar7 + 0x23;
      } while (lVar5 < param_3);
      uVar6 = uVar7 + 0x21;
      local_74 = 0;
      local_78 = 0;
    }
    local_70 = 0x800;
    do {
      lVar5 = local_68;
      uVar7 = local_74;
      do {
        uVar4 = CdAudioDirentSize;
        if (*(uint *)(*(longlong *)(lVar5 + 0x10) + 0x214) <= uVar6) break;
        lVar2 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x208);
        _Dst = (undefined1 *)((ulonglong)uVar7 + (longlong)param_5);
        memset(_Dst,0,(ulonglong)CdAudioDirentSize);
        *_Dst = (char)uVar4;
        _Dst[0x20] = 0xb;
        uVar7 = uVar7 + uVar4;
        *(undefined8 *)(_Dst + 0x21) = CdAudioFileName;
        *(undefined2 *)(_Dst + 0x29) = DAT_140008130;
        _Dst[0x2b] = DAT_140008132;
        *(undefined2 *)(_Dst + 0x12) = 0x15f;
        _Dst[0x14] = 1;
        bVar1 = *(byte *)(lVar2 + 6 + (ulonglong)uVar6 * 8);
        uVar3 = (ulonglong)bVar1 / 10;
        _Dst[0x26] = (char)uVar3 + (char)(uVar3 / 10) * -10 + '0';
        local_78 = local_78 + 1;
        _Dst[0x27] = bVar1 % 10 + 0x30;
        _Dst[0x34] = (char)uVar6;
        uVar6 = uVar6 + 1;
        *(undefined4 *)(_Dst + 0x30) = 0x41580040;
      } while (local_78 < 0x23);
      memset((void *)((ulonglong)uVar7 + (longlong)param_5),0,(ulonglong)(0x800 - uVar7));
      local_70 = local_70 + 0x800;
      local_78 = 0;
      param_5 = param_5 + 0x100;
      local_74 = 0;
    } while (local_70 <= local_6c);
  }
  return;
}



===== CdReadDirDataThroughCache @ 140011a9c =====

undefined1 CdReadDirDataThroughCache(longlong param_1,ulonglong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 local_res10;
  undefined4 local_res18;
  uint local_98;
  uint local_94;
  void *local_80;
  undefined8 local_48;
  undefined8 uStack_40;
  
  plVar1 = (longlong *)(param_1 + 0x10);
  lVar3 = *plVar1;
  uVar11 = *param_2 >> 0xb;
  local_98 = (uint)uVar11;
  local_94 = (uint)param_2[1] >> 0xb;
  local_80 = (void *)param_2[3];
  local_48 = 0;
  uStack_40 = 0;
  local_res10 = 0;
  ExAcquireResourceSharedLite(lVar3 + 0x2a8,1);
  if (*(longlong *)(lVar3 + 0x238) == 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0x80000016,'\0',0xa0000,0xa12);
  }
  while (local_94 != 0) {
    uVar5 = 0;
    while( true ) {
      uVar10 = (uint)uVar11;
      puVar8 = (uint *)0x0;
      if (3 < uVar5) break;
      puVar8 = (uint *)(((ulonglong)uVar5 + 0x24) * 0x10 + lVar3);
      uVar9 = *puVar8;
      if (((uVar9 != 0xffffffff) && (uVar9 <= uVar10)) && (uVar10 < uVar9 + 0x18)) break;
      uVar5 = uVar5 + 1;
    }
    if (puVar8 == (uint *)0x0) {
      ExReleaseResourceLite(*plVar1 + 0x2a8);
      ExAcquireResourceExclusiveLite(*plVar1 + 0x2a8,1);
      puVar8 = (uint *)(((ulonglong)*(uint *)(lVar3 + 0x280) + 0x24) * 0x10 + lVar3);
      uVar9 = uVar10 - (uVar10 - 0x10) % 0x18;
      lVar4 = *(longlong *)(lVar3 + 0x208);
      lVar7 = (ulonglong)*(byte *)(lVar4 + 3) - (ulonglong)*(byte *)(lVar4 + 2);
      local_res18 = CONCAT13(*(undefined1 *)(lVar4 + 0x10 + lVar7 * 8),
                             CONCAT12(*(undefined1 *)(lVar4 + 0x11 + lVar7 * 8),
                                      CONCAT11(*(undefined1 *)(lVar4 + 0x12 + lVar7 * 8),
                                               *(undefined1 *)(lVar4 + 0x13 + lVar7 * 8))));
      uVar5 = local_res18 - uVar9;
      if (0x18 < uVar5) {
        uVar5 = 0x18;
      }
      if ((uVar5 == 0) || (uVar10 < 0x10)) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000000d,'\0',0xa0000,0xa6d);
      }
      plVar2 = (longlong *)(lVar3 + 0x288);
      IoReuseIrp(*plVar2,0);
      lVar4 = lVar3 + 0x290;
      KeClearEvent(lVar4);
      *(void **)(*plVar2 + 0x98) = SystemReserved1[0xf];
      lVar7 = *(longlong *)(*plVar2 + 0xb8);
      *(undefined1 *)(lVar7 + -0x48) = 3;
      IoAllocateMdl(*(undefined8 *)(puVar8 + 2),uVar5 << 0xb,0,0,*plVar2);
      if (*(longlong *)(*plVar2 + 8) == 0) {
        *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x38) = 0;
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xa8e);
      }
      MmProbeAndLockPages();
      if (*(longlong *)(*plVar2 + 8) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0xaa5);
      }
      *puVar8 = 0xffffffff;
      *(uint *)(lVar7 + -0x40) = uVar5 << 0xb;
      *(ulonglong *)(lVar7 + -0x30) = (ulonglong)uVar9 << 0xb;
      lVar7 = *(longlong *)(*plVar2 + 0xb8);
      *(code **)(lVar7 + -0x10) = CdSyncCompletionRoutine;
      *(longlong *)(lVar7 + -8) = lVar4;
      *(undefined1 *)(lVar7 + -0x45) = 0;
      *(undefined1 *)(lVar7 + -0x45) = 0x40;
      *(undefined1 *)(lVar7 + -0x45) = 0xc0;
      *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      *(undefined8 **)(*plVar2 + 0x48) = &local_48;
      iVar6 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),*plVar2);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(lVar4,0,0,0,0);
        iVar6 = *(int *)(*plVar2 + 0x30);
      }
      *(undefined8 *)(*plVar2 + 0x48) = 0;
      MmUnlockPages(*(undefined8 *)(*(longlong *)(lVar3 + 0x288) + 8));
      IoFreeMdl(*(undefined8 *)(*(longlong *)(lVar3 + 0x288) + 8));
      *(undefined8 *)(*(longlong *)(lVar3 + 0x288) + 8) = 0;
      if (iVar6 < 0) goto LAB_140011eec;
      *puVar8 = uVar9;
      *(uint *)(lVar3 + 0x280) = *(int *)(lVar3 + 0x280) + 1U & 3;
      ExConvertExclusiveToSharedLite();
    }
    else {
      uVar5 = 0x18 - (uVar10 - *puVar8);
      local_98 = local_94;
      if (uVar5 < local_94) {
        local_98 = uVar5;
      }
      memmove(local_80,(void *)((ulonglong)((uVar10 - *puVar8) * 0x800) + *(longlong *)(puVar8 + 2))
              ,(ulonglong)(local_98 << 0xb));
      local_94 = local_94 - local_98;
      local_80 = (void *)((longlong)local_80 + (ulonglong)(local_98 << 0xb));
      local_98 = uVar10 + local_98;
    }
    uVar11 = (ulonglong)local_98;
  }
  local_res10 = 1;
LAB_140011eec:
  ExReleaseResourceLite(*(longlong *)(param_1 + 0x10) + 0x2a8);
  return local_res10;
}



===== CdReadSectors @ 140011fa8 =====

ulonglong CdReadSectors(longlong param_1,undefined8 param_2,undefined8 param_3,char param_4,
                       undefined8 param_5,undefined8 param_6)

{
  byte *pbVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_res10 [3];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_res10[0] = param_2;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildSynchronousFsdRequest
                    (3,param_6,param_5,0x800,local_res10,&local_28,*(longlong *)(param_1 + 8) + 0x30
                    );
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc000009a,'\0',0xa0000,0x48c);
  }
  pbVar1 = (byte *)(*(longlong *)(lVar2 + 0xb8) + -0x46);
  *pbVar1 = *pbVar1 | 2;
  uVar3 = IofCallDriver(param_6,lVar2);
  if ((int)uVar3 == 0x103) {
    uVar3 = KeWaitForSingleObject(&local_28,0,0,0,0);
    if ((int)uVar3 < 0) goto LAB_140012085;
    uVar3 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 8) + 0x30);
  }
  if (-1 < (int)uVar3) {
    return CONCAT71((int7)(uVar3 >> 8),1);
  }
LAB_140012085:
  if (param_4 == '\0') {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,(int)uVar3,'\x01',0xa0000,0x4ba);
  }
  return uVar3 & 0xffffffffffffff00;
}



===== CdSingleAsync @ 1400120e0 =====

void CdSingleAsync(longlong param_1,ulonglong *param_2,short *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  char cVar3;
  code *pcVar4;
  
  if ((((*param_3 == 0x304) && (*(longlong *)(*(longlong *)(param_3 + 0x3c) + 0x238) != 0)) &&
      (*(int *)(*(longlong *)(param_1 + 0x10) + 0x34) == 2)) &&
     (cVar3 = CdReadDirDataThroughCache(param_1,param_2), cVar3 != '\0')) {
    if ((*(uint *)(param_1 + 0x20) & 4) == 0) {
      return;
    }
    *(undefined4 *)(*(longlong *)(param_1 + 8) + 0x30) = 0;
    KeSetEvent(*(longlong *)(param_1 + 0x30) + 0x18,0,0);
    return;
  }
  if ((*(uint *)(param_1 + 0x20) & 4) == 0) {
    pcVar4 = CdSingleAsyncCompletionRoutine;
    if ((*(uint *)(param_1 + 0x20) & 0x10) != 0) {
      *(ulonglong *)(*(ulonglong *)(param_1 + 0x30) + 0x20) = *(ulonglong *)(param_1 + 0x30) | 3;
      ExSetResourceOwnerPointer
                (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x18),
                 *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x20));
    }
  }
  else {
    pcVar4 = CdSingleSyncCompletionRoutine;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xb8);
  *(code **)(lVar2 + -0x10) = pcVar4;
  *(undefined8 *)(lVar2 + -8) = uVar1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 8) + 0xb8);
  *(undefined1 *)(lVar2 + -0x48) = *(undefined1 *)(param_1 + 0x40);
  *(int *)(lVar2 + -0x40) = (int)param_2[1];
  *(ulonglong *)(lVar2 + -0x30) = *param_2;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),*(undefined8 *)(param_1 + 8));
  return;
}



===== CdWaitSync @ 1400121fc =====

void CdWaitSync(longlong param_1)

{
  KeWaitForSingleObject(*(longlong *)(param_1 + 0x30) + 0x18,0,0,0,0);
  KeClearEvent(*(longlong *)(param_1 + 0x30) + 0x18);
  return;
}



===== CdCommonDirControl @ 140012248 =====

uint CdCommonDirControl(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(lVar1 + 0x30);
  uVar3 = *(uint *)(lVar2 + 0x20) & 7;
  if (uVar3 != 0) {
    uVar5 = *(ulonglong *)(lVar2 + 0x20) & 0xfffffffffffffff8;
    if (uVar3 == 3) {
      if (*(char *)(lVar1 + 1) == '\x01') {
        uVar3 = CdQueryDirectory(param_1,param_2,lVar1,*(longlong *)(lVar2 + 0x18),uVar5);
        return uVar3;
      }
      if (*(char *)(lVar1 + 1) == '\x02') {
        uVar4 = CdNotifyChangeDirectory(param_1,param_2,lVar1,uVar5);
        return (uint)uVar4;
      }
      uVar3 = 0xc0000010;
      goto LAB_1400122b5;
    }
  }
  uVar3 = 0xc000000d;
LAB_1400122b5:
  CdCompleteRequest(param_1,param_2,uVar3);
  return uVar3;
}



===== CdEnumerateIndex @ 1400122cc =====

undefined1 CdEnumerateIndex(void *param_1,longlong param_2,undefined8 *param_3,char param_4)

{
  ushort uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  void *_Buf1;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  char local_res20;
  undefined8 local_38;
  undefined8 uStack_30;
  
  puVar8 = (uint *)0x0;
  _Buf1 = param_1;
  puVar6 = (uint *)(param_3[1] + 0x20);
  local_res20 = param_4;
LAB_140012305:
  do {
    if (local_res20 == '\0') {
      local_res20 = '\x01';
      puVar7 = puVar6;
    }
    else {
      uVar5 = CdLookupNextInitialFileDirent((longlong)param_1,*(longlong *)(param_2 + 8),param_3);
      if ((char)uVar5 == '\0') {
        return 0;
      }
      lVar2 = param_3[1];
      _Buf1 = param_1;
      CdUpdateDirentName(param_1,lVar2 + 0x20,*(uint *)(param_2 + 4) & 4);
      puVar7 = (uint *)(lVar2 + 0x20);
      puVar8 = puVar6;
    }
    puVar6 = puVar7;
  } while ((((*(byte *)((longlong)puVar7 + 0x19) & 2) != 0) &&
           ((*(uint *)(param_2 + 4) & 0x400000) != 0)) || ((puVar7[6] & 4) != 0));
  if ((puVar8 != (uint *)0x0) && (*(short *)(param_2 + 0x28) == 0)) {
    uVar1 = (ushort)puVar7[0x16];
    _Buf1 = (void *)(ulonglong)uVar1;
    if (((ushort)puVar8[0x16] == uVar1) && ((puVar8[6] & 4) == 0)) {
      _Buf1 = *(void **)(puVar8 + 0x18);
      iVar4 = memcmp(_Buf1,*(void **)(puVar7 + 0x18),(ulonglong)uVar1);
      if (iVar4 == 0) goto LAB_140012305;
    }
  }
  if (((*(uint *)(param_2 + 4) >> 0x12 & 1) != 0) ||
     (cVar3 = CdIsNameInExpression
                        (_Buf1,(ushort *)(puVar7 + 0x16),(ushort *)(param_2 + 0x18),
                         *(uint *)(param_2 + 4),'\x01'), cVar3 != '\0')) {
    *(undefined2 *)(param_3 + 5) = 0;
    goto LAB_140012458;
  }
  if ((*(short *)(param_2 + 0x28) == 0) && ((*(byte *)((longlong)puVar7 + 0x19) & 2) == 0)) {
    local_38 = *(undefined8 *)(puVar7 + 0xe);
    uStack_30 = *(undefined8 *)(puVar7 + 0x10);
    uVar5 = CdIs8dot3Name(_Buf1,(uint *)&local_38);
    if ((char)uVar5 == '\0') {
      _Buf1 = param_1;
      CdGenerate8dot3Name((longlong)param_1,puVar7 + 0x16,*puVar7,(short *)param_3[6],
                          (short *)(param_3 + 5));
      cVar3 = CdIsNameInExpression
                        (_Buf1,(ushort *)(param_3 + 5),(ushort *)(param_2 + 0x18),
                         *(uint *)(param_2 + 4),'\0');
      if (cVar3 != '\0') {
LAB_140012458:
        CdLookupLastFileDirent((longlong)param_1,*(longlong *)(param_2 + 8),(longlong)param_3);
        return 1;
      }
    }
  }
  goto LAB_140012305;
}



===== CdInitializeEnumeration @ 140012494 =====

void CdInitializeEnumeration
               (void *param_1,longlong param_2,longlong param_3,longlong param_4,longlong *param_5,
               byte *param_6,undefined1 *param_7,undefined1 *param_8)

{
  int *piVar1;
  uint uVar2;
  ulonglong *puVar3;
  short *psVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  ulonglong uVar8;
  uint uVar9;
  void *pvVar10;
  longlong lVar11;
  longlong *plVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 local_78;
  void *pvStack_70;
  undefined8 local_68;
  longlong lStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  short *psStack_40;
  
  pvVar10 = SystemReserved1[0xf];
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  psStack_40 = (short *)0x0;
  local_78 = 0;
  pvStack_70 = (void *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((*(byte *)(param_2 + 2) & 1) != 0) {
    if (SystemReserved1[0xf] != *(void **)(param_3 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 200) + 0x88);
      *(void **)(param_3 + 0xb8) = pvVar10;
    }
    *(int *)(param_3 + 0xc0) = *(int *)(param_3 + 0xc0) + 1;
    if ((*(short **)(param_2 + 0x10) != (short *)0x0) && (**(short **)(param_2 + 0x10) != 0)) {
      if (((*(uint *)(param_4 + 4) & 0x40000) == 0) && (*(longlong *)(param_4 + 0x20) != 0)) {
        ExFreePoolWithTag(*(longlong *)(param_4 + 0x20),0);
        *(undefined8 *)(param_4 + 0x20) = 0;
      }
      *(uint *)(param_4 + 4) = *(uint *)(param_4 + 4) & 0xffdaffff;
    }
    piVar1 = (int *)(param_3 + 0xc0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(param_3 + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(param_3 + 200) + 0x88);
    }
  }
  pvVar10 = SystemReserved1[0xf];
  if ((*(uint *)(param_4 + 4) & 0x200000) == 0) {
    puVar3 = *(ulonglong **)(param_2 + 0x10);
    if ((((puVar3 == (ulonglong *)0x0) || (psVar4 = (short *)puVar3[1], psVar4 == (short *)0x0)) ||
        ((ushort)*puVar3 == 0)) || (((ushort)*puVar3 == 2 && (*psVar4 == 0x2a)))) {
      uVar14 = 0x40000;
    }
    else {
      local_58 = *puVar3;
      uStack_50 = puVar3[1];
      CdConvertNameToCdName(psVar4,(ushort *)&local_58);
      if ((short)local_58 == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc000000d,'\0',0xb0000,0x40b);
      }
      cVar6 = FsRtlDoesNameContainWildCards(&local_58);
      uVar15 = -(uint)(cVar6 != '\0') & 0x10000;
      uVar14 = uVar15;
      if (((short)local_48 != 0) &&
         (cVar6 = FsRtlDoesNameContainWildCards(&local_48), cVar6 != '\0')) {
        uVar14 = uVar15 | 0x20000;
        if (((short)local_48 == 2) && (*psStack_40 == 0x2a)) {
          uVar14 = uVar15 | 0xa0000;
        }
      }
      pvStack_70 = (void *)ExAllocatePoolWithTag(0x411,(ushort)*puVar3,0x65656443);
      local_78._0_4_ = CONCAT22((ushort)*puVar3,(undefined2)local_78);
      if ((*(uint *)(param_4 + 4) & 4) == 0) {
        memmove(pvStack_70,(void *)puVar3[1],(ulonglong)(ushort)*puVar3);
      }
      else {
        RtlUpcaseUnicodeString(&local_78,puVar3,0);
      }
      local_68._0_4_ = (undefined4)local_48;
      local_78 = CONCAT62(local_78._2_6_,(short)local_58);
      lStack_60 = (longlong)pvStack_70 + (local_58 & 0xffff) + 2;
    }
    pvVar10 = SystemReserved1[0xf];
    uVar15 = uVar14 | 0x400000;
    if (param_3 != *(longlong *)(*(longlong *)(param_3 + 0x78) + 0x50)) {
      uVar15 = uVar14;
    }
    if (SystemReserved1[0xf] != *(void **)(param_3 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 200) + 0x88);
      *(void **)(param_3 + 0xb8) = pvVar10;
    }
    *(int *)(param_3 + 0xc0) = *(int *)(param_3 + 0xc0) + 1;
    if ((*(uint *)(param_4 + 4) & 0x200000) == 0) {
      *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(param_3 + 0x1e0);
      *(uint *)(param_4 + 4) = *(uint *)(param_4 + 4) | uVar15 | 0x200000;
      *(undefined8 *)(param_4 + 0x18) = local_78;
      *(void **)(param_4 + 0x20) = pvStack_70;
      *(undefined8 *)(param_4 + 0x28) = local_68;
      *(longlong *)(param_4 + 0x30) = lStack_60;
    }
    else if (((uVar15 >> 0x12 & 1) == 0) && (pvStack_70 != (void *)0x0)) {
      ExFreePoolWithTag(pvStack_70,0);
      pvStack_70 = (void *)0x0;
    }
  }
  else {
    if (SystemReserved1[0xf] != *(void **)(param_3 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(param_3 + 200) + 0x88);
      *(void **)(param_3 + 0xb8) = pvVar10;
    }
    *(int *)(param_3 + 0xc0) = *(int *)(param_3 + 0xc0) + 1;
  }
  if ((*(byte *)(param_2 + 2) & 4) == 0) {
    bVar5 = true;
    if ((*(byte *)(param_2 + 2) & 1) == 0) {
      uVar14 = *(uint *)(param_4 + 0x10);
      bVar7 = (byte)(*(uint *)(param_4 + 4) >> 0x14) & 1;
      bVar5 = true;
    }
    else {
      uVar14 = *(uint *)(param_3 + 0x1e0);
      bVar7 = 0;
    }
  }
  else {
    uVar14 = *(uint *)(param_2 + 0x20);
    bVar7 = 1;
    bVar5 = false;
  }
  *param_6 = bVar7;
  piVar1 = (int *)(param_3 + 0xc0);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined8 *)(param_3 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(param_3 + 200) + 0x88);
  }
  *param_8 = 0;
  if ((uVar14 == *(uint *)(param_3 + 0x1e0)) && (*param_6 == 0)) {
    *param_8 = 1;
  }
  if (*(longlong *)(param_3 + 0x1d8) == 0) {
    CdCreateInternalStream
              (param_1,*(longlong *)(param_3 + 0x78),param_3,(undefined4 *)(param_3 + 0x158));
  }
  plVar12 = (longlong *)param_5[1];
  if (!bVar5) {
    uVar15 = *(uint *)(param_3 + 0x1e0);
    uVar13 = 1;
    lVar11 = param_3;
    CdLookupDirent((longlong)param_1,param_3,uVar15,plVar12);
    CdUpdateDirentFromRawDirent
              ((longlong)param_1,lVar11,(longlong *)param_5[1],(int *)((longlong *)param_5[1] + 4));
    if (uVar14 < uVar15) {
      *param_6 = 0;
      goto LAB_140012895;
    }
    do {
      uVar2 = *(uint *)(param_5[1] + 0x20);
      pvVar10 = (void *)(ulonglong)uVar2;
      if (uVar14 < uVar2) break;
      uVar9 = *(int *)(param_5[1] + 0x24) + uVar2;
      pvVar10 = (void *)(ulonglong)uVar9;
      uVar15 = uVar2;
      if (uVar14 < uVar9) {
        if ((char)uVar13 != '\0') goto LAB_140012895;
        break;
      }
      pvVar10 = param_1;
      uVar8 = CdLookupNextInitialFileDirent((longlong)param_1,param_3,param_5);
      uVar13 = uVar8 & 0xff;
    } while ((char)uVar8 != '\0');
    uVar14 = uVar15;
    CdCleanupFileContext(pvVar10,(longlong)param_5);
    memset(param_5,0,0x300);
    *param_5 = (longlong)(param_5 + 0xc);
    plVar12 = param_5 + 0x28;
    param_5[1] = (longlong)plVar12;
    param_5[2] = (longlong)(param_5 + 0x44);
    *(undefined2 *)((longlong)param_5 + 0x2a) = 0x18;
    param_5[6] = (longlong)(param_5 + 9);
  }
  CdLookupDirent((longlong)param_1,param_3,uVar14,plVar12);
  CdUpdateDirentFromRawDirent
            ((longlong)param_1,param_3,(longlong *)param_5[1],(int *)((longlong *)param_5[1] + 4));
LAB_140012895:
  *(undefined2 *)(param_5 + 5) = 0;
  if ((*param_6 == 0) || (*(short *)(param_4 + 0x28) == 0)) {
    CdUpdateDirentName(param_1,param_5[1] + 0x20,*(uint *)(param_4 + 4) & 4);
  }
  *param_7 = 0;
  if ((*(byte *)(param_2 + 2) & 2) != 0) {
    *param_7 = 1;
  }
  return;
}



===== CdNotifyChangeDirectory @ 1400129a0 =====

undefined8
CdNotifyChangeDirectory(undefined8 *param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  CdAcquireResource((longlong)param_1,param_1[2] + 0x80,'\0',1);
  CdVerifyVcb((longlong)param_1,param_1[2]);
  FsRtlNotifyFullChangeDirectory
            (*(undefined8 *)(param_1[2] + 400),param_1[2] + 0x198,param_4,
             *(longlong *)(param_3 + 0x30) + 0x58,*(byte *)(param_3 + 2) & 1,0,
             *(undefined4 *)(param_3 + 0x10),param_2,0,0);
  ExReleaseResourceLite(param_1[2] + 0x80);
  CdCompleteRequest(param_1,0,0);
  return 0x103;
}



===== CdQueryDirectory @ 140012a84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CdQueryDirectory(undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4,
                     longlong param_5)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  void *pvVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  uint uVar14;
  undefined1 auStackY_428 [32];
  byte local_3e8 [4];
  uint local_3e4;
  uint local_3e0;
  int local_3dc;
  uint local_3d8;
  void *local_3d0;
  longlong local_3c8;
  longlong local_3c0;
  uint local_3b8;
  uint local_3b4;
  longlong local_3b0;
  undefined8 *local_3a8;
  uint *local_3a0;
  longlong local_398;
  longlong local_390;
  uint local_388;
  undefined8 *local_380;
  longlong local_378;
  longlong local_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined1 *local_358;
  undefined1 *local_350;
  undefined1 *local_348;
  longlong local_338;
  ushort local_330 [4];
  undefined1 *local_328;
  undefined1 local_310 [24];
  undefined1 local_2f8 [224];
  undefined1 local_218 [224];
  undefined1 local_138 [224];
  short local_58;
  short sStack_56;
  short sStack_54;
  short sStack_52;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_428;
  local_3c0 = param_5;
  local_390 = param_5;
  local_3e4 = 0;
  local_3d8 = 0;
  local_3b4 = 0;
  local_3c8 = param_3;
  local_3b0 = param_2;
  local_3a8 = param_1;
  local_398 = param_4;
  local_380 = param_1;
  local_378 = param_2;
  memset(&local_358,0,0x300);
  local_3a0 = (uint *)0x0;
  local_3e8[3] = '\0';
  local_3e8[0] = 0;
  local_3e8[2] = '\0';
  local_3e8[1] = 0;
  lVar13 = 0;
  iVar12 = *(int *)(param_3 + 0x18);
  if (iVar12 == 1) {
    iVar12 = 0x40;
  }
  else if (iVar12 == 2) {
    iVar12 = 0x44;
  }
  else if (iVar12 == 3) {
    iVar12 = 0x5e;
  }
  else if (iVar12 == 0xc) {
    iVar12 = 0xc;
  }
  else if (iVar12 == 0x25) {
    iVar12 = 0x68;
  }
  else {
    if (iVar12 != 0x26) {
      CdCompleteRequest(param_1,local_3b0,0xc0000003);
      return 0xc0000003;
    }
    iVar12 = 0x50;
  }
  lVar2 = *(longlong *)(param_1[1] + 8);
  if (lVar2 == 0) {
    local_3d0 = *(void **)(param_1[1] + 0x70);
  }
  else if ((*(byte *)(lVar2 + 10) & 5) == 0) {
    local_3d0 = (void *)MmMapLockedPagesSpecifyCache(lVar2,0);
  }
  else {
    local_3d0 = *(void **)(lVar2 + 0x18);
  }
  if (local_3d0 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0xb0000,0x11e);
  }
  local_358 = local_2f8;
  local_350 = local_218;
  local_348 = local_138;
  local_330[1] = 0x18;
  local_328 = local_310;
  CdAcquireResource((longlong)param_1,*(ulonglong *)(param_4 + 8),'\0',1);
  CdVerifyFcbOperation((longlong)param_1,param_4);
  puVar8 = param_1;
  CdInitializeEnumeration
            (param_1,local_3c8,param_4,param_5,(longlong *)&local_358,local_3e8,local_3e8 + 2,
             local_3e8 + 3);
  local_3a0 = (uint *)(local_350 + 0x20);
  uVar6 = 0;
  do {
    uVar14 = uVar6;
    if ((uVar14 != 0) && (local_3e8[2] != '\0')) goto LAB_140012ce9;
    puVar8 = param_1;
    cVar4 = CdEnumerateIndex(param_1,param_5,&local_358,local_3e8[0]);
    puVar3 = local_350;
    local_3e8[0] = 1;
    if (cVar4 == '\0') {
      if (uVar14 == 0) {
        puVar8 = (undefined8 *)0xc000000f;
        local_3e4 = 0x80000006;
        if (local_3e8[3] != '\0') {
          local_3e4 = 0xc000000f;
        }
      }
      goto LAB_140012ce9;
    }
    puVar10 = (uint *)(local_350 + 0x20);
    local_3e0 = 0;
    iVar11 = 0;
    local_3dc = 0;
    local_3b8 = (uint)*(ushort *)(local_350 + 0x58);
    if (((*(short *)(local_3c0 + 0x28) != 0) || ((local_350[0x38] & 2) != 0)) &&
       (*(ushort *)(local_350 + 0x68) != 0)) {
      iVar11 = 2;
      local_3dc = 2;
      local_3e0 = (uint)*(ushort *)(local_350 + 0x68);
    }
    uVar6 = *(uint *)(local_3c8 + 8);
    local_3a0 = puVar10;
    if (uVar6 < uVar14) goto LAB_140012d9c;
    uVar6 = uVar6 - uVar14 & 0xfffffffe;
    if (uVar6 < iVar12 + local_3e0 + iVar11 + local_3b8) {
      if (uVar14 != 0) {
LAB_140012d9c:
        puVar8 = (undefined8 *)(ulonglong)uVar6;
        local_3e8[0] = 0;
        local_3e4 = 0;
        param_1 = local_3a8;
LAB_140012ce9:
        lVar2 = local_3b0;
        lVar13 = local_3c0;
        local_3e8[1] = 1;
        CdCleanupFileContext(puVar8,(longlong)&local_358);
        pvVar9 = SystemReserved1[0xf];
        if ((local_3e4 & 0xc0000000) != 0xc0000000) {
          if (SystemReserved1[0xf] != *(void **)(param_4 + 0xb8)) {
            ExAcquireFastMutex(*(longlong *)(param_4 + 200) + 0x88);
            *(void **)(param_4 + 0xb8) = pvVar9;
          }
          *(int *)(param_4 + 0xc0) = *(int *)(param_4 + 0xc0) + 1;
          *(uint *)(lVar13 + 0x10) = *local_3a0;
          uVar6 = *(uint *)(lVar13 + 4) & 0xffefffff;
          *(uint *)(lVar13 + 4) = uVar6;
          if (local_3e8[0] != 0) {
            *(uint *)(lVar13 + 4) = uVar6 | 0x100000;
          }
          piVar1 = (int *)(param_4 + 0xc0);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(undefined8 *)(param_4 + 0xb8) = 0;
            ExReleaseFastMutex(*(longlong *)(param_4 + 200) + 0x88);
          }
        }
        ExReleaseResourceLite(*(undefined8 *)(param_4 + 8));
        *(ulonglong *)(lVar2 + 0x38) = (ulonglong)local_3d8;
        CdCompleteRequest(param_1,lVar2,local_3e4);
        return local_3e4;
      }
      if (uVar6 < iVar12 + local_3b8) {
        local_3b8 = uVar6 - iVar12;
      }
      local_3dc = 0;
      local_3e0 = 0;
      local_3e4 = 0x80000005;
      local_3e8[2] = '\x01';
    }
    uVar6 = local_3b8;
    memset((void *)((ulonglong)local_3d8 + (longlong)local_3d0),0,
           (ulonglong)((iVar12 - local_3d8) + uVar14));
    iVar11 = *(int *)(local_3c8 + 0x18);
    if (((iVar11 == 1) || (iVar11 == 2)) || (iVar11 == 3)) {
LAB_140012e44:
      lVar13 = (ulonglong)uVar14 + (longlong)local_3d0;
      _local_58 = CONCAT26((short)*(char *)(*(longlong *)(local_350 + 0x30) + 3),
                           CONCAT24((short)*(char *)(*(longlong *)(local_350 + 0x30) + 2),
                                    CONCAT22((short)*(char *)(*(longlong *)(local_350 + 0x30) + 1),
                                             **(char **)(local_350 + 0x30) + 0x76c)));
      uStack_50 = (ulonglong)
                  CONCAT22((short)*(char *)(*(longlong *)(local_350 + 0x30) + 5),
                           (short)*(char *)(*(longlong *)(local_350 + 0x30) + 4));
      local_370 = lVar13;
      RtlTimeFieldsToTime(&local_58,lVar13 + 8);
      if ((*(uint *)(local_3a8[2] + 0x30) & 1) == 0) {
        cVar4 = *(char *)(*(longlong *)(local_350 + 0x30) + 6);
        if ((cVar4 != '\0') && ((byte)(cVar4 + 0x30U) < 0x65)) {
          *(longlong *)(lVar13 + 8) = *(longlong *)(lVar13 + 8) + (longlong)-(int)cVar4 * 9000000000
          ;
        }
      }
      *(undefined8 *)(lVar13 + 0x20) = *(undefined8 *)(lVar13 + 8);
      *(undefined8 *)(lVar13 + 0x18) = *(undefined8 *)(lVar13 + 8);
      if ((puVar3[0x38] & 2) == 0) {
        *(longlong *)(lVar13 + 0x28) = local_338;
        *(ulonglong *)(lVar13 + 0x30) = local_338 + 0x7ffU & 0xfffffffffffff800;
        uVar5 = *(uint *)(lVar13 + 0x38) | 1;
      }
      else {
        *(undefined8 *)(lVar13 + 0x30) = 0;
        *(undefined8 *)(lVar13 + 0x28) = 0;
        uVar5 = *(uint *)(lVar13 + 0x38) | 0x10;
      }
      *(uint *)(lVar13 + 0x38) = uVar5;
      if ((puVar3[0x38] & 1) != 0) {
        *(uint *)(lVar13 + 0x38) = uVar5 | 2;
      }
      *(uint *)(lVar13 + 4) = *puVar10;
      *(uint *)(lVar13 + 0x3c) = local_3e0 + local_3dc + uVar6;
    }
    else if (iVar11 == 0xc) {
      *(uint *)((ulonglong)uVar14 + 4 + (longlong)local_3d0) = *puVar10;
      *(uint *)((ulonglong)uVar14 + 8 + (longlong)local_3d0) = local_3e0 + local_3dc + uVar6;
    }
    else if ((iVar11 == 0x25) || (iVar11 == 0x26)) goto LAB_140012e44;
    uVar5 = *(int *)(local_3c8 + 0x18) - 0x25;
    pvVar9 = (void *)(ulonglong)uVar5;
    if (uVar5 == 0) {
      pvVar9 = (void *)(ulonglong)uVar14;
      *(undefined4 *)((longlong)pvVar9 + 100U + (longlong)local_3d0) =
           *(undefined4 *)(param_4 + 0x9c);
      uVar5 = *puVar10;
      *(uint *)((longlong)pvVar9 + 0x60U + (longlong)local_3d0) = uVar5;
      if ((puVar3[0x38] & 2) != 0) {
        *(uint *)((longlong)pvVar9 + 0x60U + (longlong)local_3d0) = uVar5 | 0x80000000;
      }
    }
    else if (uVar5 == 1) {
      pvVar9 = (void *)(ulonglong)uVar14;
      *(undefined4 *)((longlong)pvVar9 + 0x4cU + (longlong)local_3d0) =
           *(undefined4 *)(param_4 + 0x9c);
      uVar5 = *puVar10;
      *(uint *)((longlong)pvVar9 + 0x48U + (longlong)local_3d0) = uVar5;
      if ((puVar3[0x38] & 2) != 0) {
        *(uint *)((longlong)pvVar9 + 0x48U + (longlong)local_3d0) = uVar5 | 0x80000000;
      }
    }
    if (uVar6 != 0) {
      pvVar9 = (void *)((ulonglong)(iVar12 + uVar14) + (longlong)local_3d0);
      memmove(pvVar9,*(void **)(puVar3 + 0x60),(ulonglong)uVar6);
      if (local_3dc != 0) {
        uVar7 = (ulonglong)(iVar12 + uVar6 + uVar14);
        *(undefined2 *)(uVar7 + (longlong)local_3d0) = 0x3b;
        pvVar9 = local_3d0;
        if (local_3e0 != 0) {
          pvVar9 = (void *)((longlong)local_3d0 + uVar7 + 2);
          memmove(pvVar9,*(void **)(puVar3 + 0x70),(ulonglong)local_3e0);
        }
      }
    }
    if (((local_3e4 == 0) &&
        (((*(int *)(local_3c8 + 0x18) == 3 || (*(int *)(local_3c8 + 0x18) == 0x25)) &&
         (*(short *)(local_3c0 + 0x28) == 0)))) && ((puVar3[0x39] & 2) == 0)) {
      if (local_330[0] == 0) {
        local_368 = *(undefined8 *)(puVar3 + 0x58);
        uStack_360 = *(undefined8 *)(puVar3 + 0x60);
        uVar7 = CdIs8dot3Name(pvVar9,(uint *)&local_368);
        if ((char)uVar7 != '\0') goto LAB_140013121;
        CdGenerate8dot3Name((longlong)local_3a8,puVar3 + 0x78,*puVar10,(short *)(lVar13 + 0x46),
                            (short *)local_330);
      }
      else {
        memmove((void *)(lVar13 + 0x46),local_328,(ulonglong)local_330[0]);
      }
      *(undefined1 *)(lVar13 + 0x44) = (undefined1)local_330[0];
    }
LAB_140013121:
    local_3b8 = uVar6 + local_3e0 + local_3dc;
    local_3d8 = iVar12 + local_3b8 + uVar14;
    puVar8 = (undefined8 *)(ulonglong)(uVar14 - local_3b4);
    *(uint *)((ulonglong)local_3b4 + (longlong)local_3d0) = uVar14 - local_3b4;
    local_3e8[3] = '\0';
    local_388 = local_3d8 + 7 & 0xfffffff8;
    param_5 = local_3c0;
    param_1 = local_3a8;
    uVar6 = local_388;
    local_3b4 = uVar14;
  } while( true );
}



===== CdCheckRawDirentBounds @ 1400132b0 =====

uint CdCheckRawDirentBounds(longlong param_1,longlong *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  pbVar2 = (byte *)((ulonglong)*(uint *)(param_2 + 3) + *param_2);
  bVar1 = *pbVar2;
  uVar4 = 0;
  if (bVar1 != 0) {
    uVar5 = *(int *)((longlong)param_2 + 0xc) - *(uint *)(param_2 + 3);
    if (((uVar5 < bVar1) || (bVar1 < 0x22)) || (uVar3 = (uint)bVar1, uVar3 < pbVar2[0x20] + 0x21)) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x6e6);
    }
    uVar4 = 0;
    if (uVar3 != uVar5) {
      uVar4 = uVar3;
    }
  }
  return uVar4;
}



===== CdCleanupFileContext @ 14001331c =====

void CdCleanupFileContext(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  bool bVar3;
  
  plVar1 = (longlong *)(param_2 + 0x230);
  iVar2 = 2;
  do {
    if (*plVar1 != 0) {
      CcUnpinData();
      *plVar1 = 0;
    }
    if (((*(byte *)((longlong)plVar1 + 0x29) & 1) != 0) && (plVar1[10] != 0)) {
      ExFreePoolWithTag(plVar1[10],0);
      plVar1[10] = 0;
    }
    plVar1 = plVar1 + -0x1c;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}



===== CdFindDirectory @ 140013390 =====

undefined8
CdFindDirectory(void *param_1,longlong param_2,ushort *param_3,undefined8 param_4,
               undefined8 *param_5)

{
  char cVar1;
  undefined7 extraout_var;
  ulonglong uVar2;
  void *pvVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  if (*(longlong *)(param_2 + 0x1d8) == 0) {
    CdCreateInternalStream
              (param_1,*(longlong *)(param_2 + 0x78),param_2,(undefined4 *)(param_2 + 0x158));
  }
  lVar4 = param_2;
  CdLookupDirent((longlong)param_1,param_2,*(uint *)(param_2 + 0x1e0),(longlong *)param_5[1]);
  CdUpdateDirentFromRawDirent
            ((longlong)param_1,lVar4,(longlong *)param_5[1],(int *)((longlong *)param_5[1] + 4));
  do {
    lVar4 = param_5[1];
    if (((*(byte *)(lVar4 + 0x38) & 2) != 0) &&
       (pvVar3 = param_1, CdUpdateDirentName(param_1,lVar4 + 0x20,1),
       (*(byte *)(lVar4 + 0x39) & 2) == 0)) {
      cVar1 = CdIsNameInExpression(pvVar3,(ushort *)(lVar4 + 0x78),param_3,0,'\x01');
      uVar2 = CONCAT71(extraout_var,cVar1);
      if (cVar1 != '\0') {
        uVar5 = 1;
        break;
      }
    }
    uVar2 = CdLookupNextInitialFileDirent((longlong)param_1,param_2,param_5);
  } while ((char)uVar2 != '\0');
  return CONCAT71((int7)(uVar2 >> 8),uVar5);
}



===== CdFindFile @ 140013470 =====

undefined8
CdFindFile(void *param_1,longlong param_2,ushort *param_3,byte param_4,undefined8 *param_5,
          undefined8 *param_6)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 uVar6;
  ushort *puVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar6 = 0;
  pvVar4 = param_1;
  if (*(longlong *)(param_2 + 0x1d8) == 0) {
    CdCreateInternalStream
              (param_1,*(longlong *)(param_2 + 0x78),param_2,(undefined4 *)(param_2 + 0x158));
  }
  uVar2 = CdShortNameDirentOffset(pvVar4,param_3);
  lVar5 = param_2;
  CdLookupDirent((longlong)param_1,param_2,*(uint *)(param_2 + 0x1e0),(longlong *)param_5[1]);
  CdUpdateDirentFromRawDirent
            ((longlong)param_1,lVar5,(longlong *)param_5[1],(int *)((longlong *)param_5[1] + 4));
  do {
    lVar5 = param_5[1];
    if (((*(byte *)(lVar5 + 0x38) & 6) == 0) &&
       (pvVar4 = param_1, CdUpdateDirentName(param_1,lVar5 + 0x20,(uint)param_4),
       (*(byte *)(lVar5 + 0x39) & 2) == 0)) {
      puVar7 = (ushort *)(lVar5 + 0x78);
      cVar1 = CdIsNameInExpression(pvVar4,puVar7,param_3,0,'\x01');
      if (cVar1 != '\0') {
LAB_1400135c0:
        *param_6 = puVar7;
        uVar6 = 1;
        uVar3 = CdLookupLastFileDirent((longlong)param_1,param_2,(longlong)param_5);
        break;
      }
      if ((*(uint *)(lVar5 + 0x20) >> 5 == uVar2) && (param_3[8] == 0)) {
        local_48 = *(undefined8 *)(lVar5 + 0x58);
        uStack_40 = *(undefined8 *)(lVar5 + 0x60);
        uVar3 = CdIs8dot3Name(pvVar4,(uint *)&local_48);
        if ((char)uVar3 == '\0') {
          puVar7 = (ushort *)(param_5 + 5);
          pvVar4 = param_1;
          CdGenerate8dot3Name((longlong)param_1,lVar5 + 0x78,*(uint *)(lVar5 + 0x20),
                              (short *)param_5[6],(short *)puVar7);
          cVar1 = CdIsNameInExpression(pvVar4,puVar7,param_3,0,'\0');
          if (cVar1 != '\0') goto LAB_1400135c0;
        }
      }
    }
    uVar3 = CdLookupNextInitialFileDirent((longlong)param_1,param_2,param_5);
  } while ((char)uVar3 != '\0');
  return CONCAT71((int7)(uVar3 >> 8),uVar6);
}



===== CdFindFileByShortName @ 1400135f4 =====

undefined8
CdFindFileByShortName
          (void *param_1,longlong param_2,ushort *param_3,byte param_4,uint param_5,
          undefined8 *param_6)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined7 extraout_var;
  void *pvVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar6 = 0;
  if (*(longlong *)(param_2 + 0x1d8) == 0) {
    CdCreateInternalStream
              (param_1,*(longlong *)(param_2 + 0x78),param_2,(undefined4 *)(param_2 + 0x158));
  }
  lVar5 = param_2;
  CdLookupDirent((longlong)param_1,param_2,*(uint *)(param_2 + 0x1e0),(longlong *)param_6[1]);
  CdUpdateDirentFromRawDirent
            ((longlong)param_1,lVar5,(longlong *)param_6[1],(int *)((longlong *)param_6[1] + 4));
  while( true ) {
    lVar5 = param_6[1];
    uVar2 = *(uint *)(lVar5 + 0x20) >> 5;
    uVar3 = (ulonglong)uVar2;
    if (param_5 < uVar2) break;
    if (uVar2 == param_5) {
      if ((*(byte *)(lVar5 + 0x38) & 4) == 0) {
        pvVar4 = param_1;
        CdUpdateDirentName(param_1,lVar5 + 0x20,(uint)param_4);
        local_28 = *(undefined8 *)(lVar5 + 0x58);
        uStack_20 = *(undefined8 *)(lVar5 + 0x60);
        uVar3 = CdIs8dot3Name(pvVar4,(uint *)&local_28);
        if ((char)uVar3 == '\0') {
          pvVar4 = param_1;
          CdGenerate8dot3Name((longlong)param_1,lVar5 + 0x78,*(uint *)(lVar5 + 0x20),
                              (short *)param_6[6],(short *)(param_6 + 5));
          cVar1 = CdIsNameInExpression(pvVar4,param_3,(ushort *)(param_6 + 5),0,'\0');
          uVar3 = CONCAT71(extraout_var,cVar1);
          if (cVar1 != '\0') {
            uVar6 = 1;
            uVar3 = CdLookupLastFileDirent((longlong)param_1,param_2,(longlong)param_6);
          }
        }
      }
      break;
    }
    uVar3 = CdLookupNextInitialFileDirent((longlong)param_1,param_2,param_6);
    if ((char)uVar3 == '\0') break;
  }
  return CONCAT71((int7)(uVar3 >> 8),uVar6);
}



===== CdLookupDirent @ 140013738 =====

void CdLookupDirent(longlong param_1,longlong param_2,uint param_3,longlong *param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong local_res10 [3];
  
  iVar1 = 0x800;
  *(undefined4 *)((longlong)param_4 + 0xc) = 0x800;
  uVar2 = param_3 & 0xfffff800;
  local_res10[0] = (ulonglong)uVar2;
  *(uint *)(param_4 + 1) = uVar2;
  *(uint *)(param_4 + 3) = param_3 & 0x7ff;
  if ((longlong)(*(longlong *)(param_2 + 0x20) - local_res10[0]) < 0x800) {
    iVar1 = *(int *)(param_2 + 0x20) - uVar2;
    *(int *)((longlong)param_4 + 0xc) = iVar1;
  }
  CcMapData(*(undefined8 *)(param_2 + 0x1d8),local_res10,iVar1,1,param_4 + 2,param_4);
  uVar2 = CdCheckRawDirentBounds(param_1,param_4);
  *(uint *)((longlong)param_4 + 0x1c) = uVar2;
  return;
}



===== CdLookupLastFileDirent @ 1400137dc =====

void CdLookupLastFileDirent(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  int iVar9;
  
  plVar8 = *(longlong **)(param_3 + 8);
  iVar9 = 0;
  bVar2 = true;
  do {
    uVar6 = *(uint *)((longlong)plVar8 + 0x44);
    if ((uVar6 == 0) || ((*(uint *)(*(longlong *)(param_2 + 0x78) + 0x30) & 0x40) == 0)) {
LAB_1400138e4:
      if ((!bVar2) && (iVar9 != (int)plVar8[0x13])) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x626);
      }
      uVar3 = (ulonglong)*(uint *)((longlong)plVar8 + 0x2c);
    }
    else {
      iVar5 = 0;
      if ((0xd < *(int *)((longlong)plVar8 + 0x24) - uVar6) &&
         (lVar7 = (ulonglong)*(uint *)(plVar8 + 3) + (ulonglong)uVar6 + *plVar8,
         *(short *)(lVar7 + 6) == 0x4158)) {
        uVar1 = *(ushort *)(lVar7 + 4);
        if ((uVar1 & 0x40) == 0) {
          if ((uVar1 & 0x10) != 0) {
            iVar5 = 1;
          }
        }
        else {
          iVar5 = 2;
        }
        *(ushort *)(plVar8 + 9) = uVar1;
        *(undefined1 *)((longlong)plVar8 + 0x4a) = *(undefined1 *)(lVar7 + 8);
      }
      *(int *)(plVar8 + 0x13) = iVar5;
      if (iVar5 == 0) goto LAB_1400138e4;
      if ((!bVar2) && (iVar9 != iVar5)) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x5e5);
      }
      if (*(int *)(*(longlong *)(param_2 + 0x78) + 0x1a8) != 0x800) {
        uVar6 = *(int *)(*(longlong *)(param_2 + 0x78) + 0x1b4) - 1;
        if (((*(uint *)(plVar8 + 5) & uVar6) != 0) ||
           ((*(uint *)((longlong)plVar8 + 0x2c) & uVar6) != 0)) {
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x5fb);
        }
        if ((*(uint *)((longlong)plVar8 + 0x3c) != 0) &&
           (((uVar6 & *(uint *)((longlong)plVar8 + 0x3c)) != 0 ||
            ((*(uint *)(plVar8 + 8) & uVar6) != 0)))) {
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x607);
        }
      }
      if (bVar2) {
        *(undefined8 *)(param_3 + 0x20) = 0x2c;
      }
      uVar3 = (ulonglong)(*(uint *)((longlong)plVar8 + 0x2c) >> 0xb) * 0x930;
    }
    *(longlong *)(param_3 + 0x20) = *(longlong *)(param_3 + 0x20) + uVar3;
    if (-1 < (char)plVar8[7]) {
      return;
    }
    iVar9 = (int)plVar8[0x13];
    lVar7 = param_2;
    uVar4 = CdLookupNextDirent(param_1,param_2,(longlong)plVar8,*(longlong **)(param_3 + 0x10));
    if ((char)uVar4 == '\0') {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x64e);
    }
    plVar8 = *(longlong **)(param_3 + 0x10);
    bVar2 = false;
    CdUpdateDirentFromRawDirent(param_1,lVar7,plVar8,(int *)(plVar8 + 4));
    *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 1;
  } while( true );
}



===== CdLookupNextDirent @ 140013a04 =====

undefined8 CdLookupNextDirent(longlong param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  undefined1 uVar6;
  ulonglong local_res18 [2];
  
  local_res18[0] = (ulonglong)*(uint *)(param_3 + 8);
  plVar1 = param_4 + 2;
  uVar4 = *(uint *)(param_4 + 1);
  uVar6 = 0;
  if ((*(uint *)(param_3 + 8) != uVar4) || (*plVar1 == 0)) {
    if (*plVar1 != 0) {
      CcUnpinData();
      *plVar1 = 0;
    }
    CcMapData(*(undefined8 *)(param_2 + 0x1d8),local_res18,*(undefined4 *)(param_3 + 0xc),1,plVar1,
              param_4);
    *(undefined4 *)((longlong)param_4 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    uVar4 = *(uint *)(param_3 + 8);
    *(uint *)(param_4 + 1) = uVar4;
  }
  iVar2 = *(int *)(param_3 + 0x18);
  *(int *)(param_4 + 3) = iVar2;
  if (*(int *)(param_3 + 0x1c) == 0) {
    local_res18[0] = (ulonglong)(*(int *)((longlong)param_4 + 0xc) + uVar4);
    if (*plVar1 != 0) {
      CcUnpinData();
      *plVar1 = 0;
    }
  }
  else {
    *(int *)(param_4 + 3) = iVar2 + *(int *)(param_3 + 0x1c);
  }
  while( true ) {
    if (*plVar1 == 0) {
      uVar3 = *(int *)(param_2 + 0x20) - (int)local_res18[0];
      uVar5 = (ulonglong)uVar3;
      uVar4 = 0x800;
      if ((uVar3 < 0x800) && (uVar4 = uVar3, uVar3 == 0)) goto LAB_140013b72;
      CcMapData(*(undefined8 *)(param_2 + 0x1d8),local_res18,uVar4,1,plVar1,param_4);
      *(int *)(param_4 + 1) = (int)local_res18[0];
      *(uint *)((longlong)param_4 + 0xc) = uVar4;
      *(undefined4 *)(param_4 + 3) = 0;
    }
    if (*(char *)((ulonglong)*(uint *)(param_4 + 3) + *param_4) != '\0') break;
    local_res18[0] = (ulonglong)(uint)(*(int *)((longlong)param_4 + 0xc) + (int)param_4[1]);
    if (*plVar1 != 0) {
      CcUnpinData();
      *plVar1 = 0;
    }
  }
  uVar6 = 1;
  uVar4 = CdCheckRawDirentBounds(param_1,param_4);
  uVar5 = CONCAT44(extraout_var,uVar4);
  *(uint *)((longlong)param_4 + 0x1c) = uVar4;
LAB_140013b72:
  return CONCAT71((int7)(uVar5 >> 8),uVar6);
}



===== CdLookupNextInitialFileDirent @ 140013b94 =====

ulonglong CdLookupNextInitialFileDirent(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  byte bVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *plVar6;
  
  plVar1 = (longlong *)*param_3;
  plVar6 = (longlong *)param_3[1];
  *param_3 = plVar6;
  param_3[1] = plVar1;
  if ((*(uint *)(param_3 + 3) & 1) != 0) {
    plVar6 = (longlong *)param_3[2];
  }
  *(undefined4 *)(param_3 + 3) = 0;
  param_3[4] = 0;
  *(undefined2 *)(param_3 + 5) = 0;
  while( true ) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
      bVar2 = *(byte *)((ulonglong)*(uint *)(plVar6 + 3) + *plVar6 + 0x19);
    }
    else {
      bVar2 = *(byte *)((ulonglong)*(uint *)(plVar6 + 3) + *plVar6 + 0x18);
    }
    lVar5 = param_2;
    uVar4 = CdLookupNextDirent(param_1,param_2,(longlong)plVar6,plVar1);
    cVar3 = (char)uVar4;
    if (cVar3 == '\0') break;
    uVar4 = CdUpdateDirentFromRawDirent(param_1,lVar5,plVar1,(int *)(param_3[1] + 0x20));
    if ((bVar2 & 0x80) == 0) break;
    plVar6 = plVar1;
  }
  return CONCAT71((int7)((ulonglong)uVar4 >> 8),cVar3);
}



===== CdUpdateDirentFromRawDirent @ 140013c64 =====

void CdUpdateDirentFromRawDirent(longlong param_1,undefined8 param_2,longlong *param_3,int *param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  
  pbVar6 = (byte *)((ulonglong)*(uint *)(param_3 + 3) + *param_3);
  *param_4 = (int)param_3[1] + (int)param_3[3];
  bVar2 = *pbVar6;
  param_4[1] = (uint)bVar2;
  iVar4 = *(int *)(pbVar6 + 2);
  param_4[2] = iVar4;
  param_4[2] = (uint)pbVar6[1] + iVar4;
  param_4[3] = *(int *)(pbVar6 + 10);
  *(byte **)(param_4 + 4) = pbVar6 + 0x12;
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
    bVar5 = pbVar6[0x19];
  }
  else {
    bVar5 = pbVar6[0x18];
  }
  *(byte *)(param_4 + 6) = bVar5;
  param_4[7] = 0;
  param_4[8] = 0;
  if (pbVar6[0x1a] != 0) {
    param_4[7] = (uint)pbVar6[0x1a];
    param_4[8] = (uint)pbVar6[0x1b];
  }
  bVar3 = pbVar6[0x20];
  if (bVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc0000102,'\0',0xc0000,0x200);
  }
  param_4[0xb] = (uint)bVar3;
  *(undefined2 *)(param_4 + 10) = 0;
  *(byte **)(param_4 + 0xc) = pbVar6 + 0x21;
  *(undefined1 *)((longlong)param_4 + 0x2a) = 0;
  param_4[0x1e] = 0;
  param_4[9] = 0;
  if (((bVar5 & 2) == 0) && (uVar1 = bVar3 + 0x22, uVar1 <= bVar2 && bVar2 != uVar1)) {
    param_4[9] = uVar1 & 0xfffffffe;
  }
  return;
}



===== CdUpdateDirentName @ 140013d44 =====

void CdUpdateDirentName(void *param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ushort uVar5;
  uint uVar6;
  void *pvVar7;
  void *pvVar8;
  ushort *puVar9;
  ushort *puVar10;
  uint local_res10 [2];
  
  uVar6 = *(uint *)(param_2 + 0x2c);
  local_res10[0] = 0;
  if (((uVar6 == 1) && ((*(byte *)(param_2 + 0x18) & 2) != 0)) &&
     (bVar2 = **(byte **)(param_2 + 0x30), bVar2 < 2)) {
    if ((*(byte *)(param_2 + 0x19) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0xc0000,0x25a);
    }
    *(undefined2 *)(param_2 + 0x48) = 0;
    *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 2;
    lVar1 = (ulonglong)bVar2 * 0x10;
    uVar4 = *(undefined8 *)(&CdUnicodeDirectoryNames + lVar1);
    uVar3 = *(undefined8 *)(&UNK_140006020 + lVar1);
    *(undefined8 *)(param_2 + 0x38) = uVar4;
    *(undefined8 *)(param_2 + 0x40) = uVar3;
    *(undefined8 *)(param_2 + 0x58) = uVar4;
    *(undefined8 *)(param_2 + 0x60) = uVar3;
    *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(param_2 + 0x50);
  }
  else {
    bVar2 = *(byte *)(param_2 + 0x19);
    *(byte *)(param_2 + 0x19) = bVar2 & 0xfd;
    local_res10[0] = uVar6;
    if (param_3 != 0) {
      local_res10[0] = uVar6 * 2;
    }
    if ((*(uint *)(*(longlong *)((longlong)param_1 + 0x10) + 0x30) & 4) == 0) {
      local_res10[0] = local_res10[0] * 2;
    }
    if (((bVar2 & 1) == 0) && (uVar6 = 0x40, local_res10[0] < 0x41)) {
      *(undefined2 *)(param_2 + 0x3a) = 0x40;
      *(longlong *)(param_2 + 0x40) = param_2 + 0x7c;
    }
    else {
      uVar6 = (uint)*(ushort *)(param_2 + 0x3a);
      if (*(ushort *)(param_2 + 0x3a) < local_res10[0]) {
        if ((bVar2 & 1) != 0) {
          if (*(longlong *)(param_2 + 0x40) != 0) {
            ExFreePoolWithTag(*(longlong *)(param_2 + 0x40),0);
            *(undefined8 *)(param_2 + 0x40) = 0;
          }
          *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xfe;
        }
        uVar4 = ExAllocatePoolWithTag(0x411,local_res10[0],0x6e646443);
        *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 1;
        *(undefined8 *)(param_2 + 0x40) = uVar4;
        uVar6 = local_res10[0] & 0xffff;
        *(short *)(param_2 + 0x3a) = (short)local_res10[0];
      }
    }
    pvVar7 = *(void **)(param_2 + 0x40);
    puVar9 = (ushort *)(param_2 + 0x38);
    if ((*(uint *)(*(longlong *)((longlong)param_1 + 0x10) + 0x30) & 4) == 0) {
      RtlOemToUnicodeN(pvVar7,uVar6,local_res10,*(undefined1 **)(param_2 + 0x30),
                       *(uint *)(param_2 + 0x2c));
      pvVar8 = pvVar7;
      uVar5 = (ushort)local_res10[0];
    }
    else {
      pvVar8 = param_1;
      CdConvertBigToLittleEndian
                ((longlong)param_1,*(undefined1 **)(param_2 + 0x30),*(uint *)(param_2 + 0x2c),pvVar7
                );
      uVar5 = *(ushort *)(param_2 + 0x2c);
    }
    *puVar9 = uVar5;
    CdConvertNameToCdName(pvVar8,puVar9);
    uVar5 = *puVar9;
    if (uVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0xc0000,0x2ee);
    }
    lVar1 = *(longlong *)(param_2 + 0x40);
    if (*(short *)(lVar1 + ((ulonglong)uVar5 - 2 & 0xfffffffffffffffe)) == 0x2e) {
      if (*(ushort *)(param_2 + 0x48) != 0) {
        pvVar7 = (void *)((ulonglong)uVar5 + lVar1);
        memmove((void *)((longlong)pvVar7 + -2),pvVar7,(ulonglong)*(ushort *)(param_2 + 0x48) + 2);
        *(void **)(param_2 + 0x50) = pvVar7;
      }
      *puVar9 = *puVar9 - 2;
      uVar5 = *puVar9;
    }
    puVar9 = *(ushort **)(param_2 + 0x40);
    puVar10 = (ushort *)((ulonglong)uVar5 + (longlong)puVar9);
    for (; puVar9 < puVar10; puVar9 = puVar9 + 1) {
      uVar5 = *puVar9;
      if (((uVar5 < 0xff) && (-1 < (char)*puVar9)) &&
         (((*(byte *)((ulonglong)uVar5 + *(longlong *)FsRtlLegalAnsiCharacterArray_exref) & 2) == 0
          && (((0x3e < uVar5 || ((0x5000000400000000U >> ((ulonglong)uVar5 & 0x3f) & 1) == 0)) &&
              (uVar5 != 0x7c)))))) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc0000102,'\0',0xc0000,799);
      }
    }
    if (param_3 == 0) {
      *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_2 + 0x38);
      *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_2 + 0x40);
      *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_2 + 0x48);
      *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(param_2 + 0x50);
    }
    else {
      uVar5 = *(ushort *)(param_2 + 0x3a) >> 1;
      *(ulonglong *)(param_2 + 0x60) =
           (ulonglong)(*(ushort *)(param_2 + 0x3a) >> 1) + *(longlong *)(param_2 + 0x40);
      *(ushort *)(param_2 + 0x5a) = uVar5;
      CdUpcaseName((ulonglong)uVar5,(ushort *)(param_2 + 0x38),(ushort *)(param_2 + 0x58));
    }
  }
  return;
}



===== CdCommonQueryInfo @ 14001403c =====

uint CdCommonQueryInfo(undefined8 *param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  void *_Src;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  bool bVar13;
  uint local_res18 [2];
  longlong local_res20;
  
  uVar6 = 0;
  local_res20 = *(longlong *)(param_2 + 0xb8);
  bVar5 = false;
  uVar9 = *(uint *)(local_res20 + 8);
  iVar2 = *(int *)(local_res20 + 0x10);
  puVar8 = *(uint **)(param_2 + 0x18);
  lVar11 = *(longlong *)(local_res20 + 0x30);
  uVar7 = *(uint *)(lVar11 + 0x20) & 7;
  if (uVar7 == 0) {
    lVar12 = 0;
    uVar10 = 0;
  }
  else {
    lVar12 = *(longlong *)(lVar11 + 0x18);
    uVar10 = *(ulonglong *)(lVar11 + 0x20) & 0xfffffffffffffff8;
  }
  local_res18[0] = uVar9;
  if ((uVar7 != 3) && (uVar7 != 4)) goto LAB_1400140b0;
  bVar5 = true;
  CdAcquireResource((longlong)param_1,*(ulonglong *)(lVar12 + 8),'\0',1);
  if (((*(uint *)(lVar12 + 0xac) & 1) == 0) && (*(longlong *)(lVar12 + 0x1d8) == 0)) {
    CdCreateInternalStream
              (param_1,*(longlong *)(lVar12 + 0x78),lVar12,(undefined4 *)(lVar12 + 0x158));
  }
  CdVerifyFcbOperation((longlong)param_1,lVar12);
  lVar11 = local_res20;
  if (iVar2 == 4) {
    uVar3 = *(undefined8 *)(lVar12 + 0x1d0);
    *(undefined8 *)(puVar8 + 6) = uVar3;
    *(undefined8 *)puVar8 = uVar3;
    *(undefined8 *)(puVar8 + 4) = uVar3;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar8[8] = *(uint *)(lVar12 + 0xb0);
    uVar9 = uVar9 - 0x28;
LAB_1400143dd:
    local_res18[0] = uVar9;
LAB_1400143e4:
  }
  else {
    if (iVar2 == 5) {
      puVar8[4] = 1;
      *(undefined1 *)(puVar8 + 5) = 0;
      if ((*(uint *)(lVar12 + 0xb0) & 0x10) == 0) {
        *(undefined8 *)puVar8 = *(undefined8 *)(lVar12 + 0x18);
        *(undefined8 *)(puVar8 + 2) = *(undefined8 *)(lVar12 + 0x20);
        *(undefined1 *)((longlong)puVar8 + 0x15) = 0;
      }
      else {
        puVar8[2] = 0;
        puVar8[3] = 0;
        puVar8[0] = 0;
        puVar8[1] = 0;
        *(undefined1 *)((longlong)puVar8 + 0x15) = 1;
      }
      uVar9 = uVar9 - 0x18;
      goto LAB_1400143dd;
    }
    if (iVar2 == 6) {
      *(undefined8 *)puVar8 = *(undefined8 *)(lVar12 + 0x98);
      uVar9 = uVar9 - 8;
      goto LAB_1400143dd;
    }
    if (iVar2 == 7) {
      *puVar8 = 0;
      uVar9 = uVar9 - 4;
      goto LAB_1400143dd;
    }
    if (iVar2 == 9) {
      if ((*(uint *)(uVar10 + 4) & 1) != 0) {
        uVar6 = 0xc000000d;
        goto LAB_1400143f4;
      }
      lVar4 = *(longlong *)(local_res20 + 0x30);
      uVar1 = *(ushort *)(lVar4 + 0x58);
      *puVar8 = (uint)uVar1;
      local_res18[0] = uVar9 - 4;
      uVar9 = (uint)uVar1;
      uVar7 = local_res18[0];
      if (uVar1 < local_res18[0] || uVar9 == local_res18[0]) {
        uVar7 = uVar9;
      }
      bVar13 = local_res18[0] < uVar9;
      puVar8 = puVar8 + 1;
      _Src = *(void **)(lVar4 + 0x60);
LAB_1400142e6:
      uVar9 = local_res18[0];
      uVar6 = -(uint)bVar13 & 0x80000005;
      memmove(puVar8,_Src,(ulonglong)uVar7);
      uVar9 = uVar9 - uVar7;
LAB_1400142fc:
      local_res18[0] = uVar9;
      goto LAB_1400143f4;
    }
    if (iVar2 == 0xe) {
      *(undefined8 *)puVar8 = *(undefined8 *)(*(longlong *)(local_res20 + 0x30) + 0x68);
      uVar9 = uVar9 - 8;
      goto LAB_1400142fc;
    }
    if (iVar2 == 0x12) {
      if ((*(uint *)(uVar10 + 4) & 1) == 0) {
        uVar3 = *(undefined8 *)(lVar12 + 0x1d0);
        *(undefined8 *)(puVar8 + 6) = uVar3;
        *(undefined8 *)puVar8 = uVar3;
        *(undefined8 *)(puVar8 + 4) = uVar3;
        puVar8[2] = 0;
        puVar8[3] = 0;
        puVar8[8] = *(uint *)(lVar12 + 0xb0);
        puVar8[0xe] = 1;
        *(undefined1 *)(puVar8 + 0xf) = 0;
        if ((*(uint *)(lVar12 + 0xb0) & 0x10) == 0) {
          *(undefined8 *)(puVar8 + 10) = *(undefined8 *)(lVar12 + 0x18);
          *(undefined8 *)(puVar8 + 0xc) = *(undefined8 *)(lVar12 + 0x20);
          *(undefined1 *)((longlong)puVar8 + 0x3d) = 0;
        }
        else {
          puVar8[0xc] = 0;
          puVar8[0xd] = 0;
          puVar8[10] = 0;
          puVar8[0xb] = 0;
          *(undefined1 *)((longlong)puVar8 + 0x3d) = 1;
        }
        *(undefined8 *)(puVar8 + 0x10) = *(undefined8 *)(lVar12 + 0x98);
        puVar8[0x12] = 0;
        *(undefined8 *)(puVar8 + 0x14) = *(undefined8 *)(*(longlong *)(local_res20 + 0x30) + 0x68);
        lVar4 = *(longlong *)(local_res20 + 0x30);
        uVar1 = *(ushort *)(lVar4 + 0x58);
        puVar8[0x18] = (uint)uVar1;
        local_res18[0] = uVar9 - 100;
        uVar9 = (uint)uVar1;
        uVar7 = local_res18[0];
        if (uVar1 < local_res18[0] || uVar9 == local_res18[0]) {
          uVar7 = uVar9;
        }
        bVar13 = local_res18[0] < uVar9;
        puVar8 = puVar8 + 0x19;
        _Src = *(void **)(lVar4 + 0x60);
        goto LAB_1400142e6;
      }
LAB_1400140b0:
      uVar6 = 0xc000000d;
      goto LAB_1400143e4;
    }
    if (iVar2 != 0x15) {
      if (iVar2 == 0x22) {
        uVar3 = *(undefined8 *)(lVar12 + 0x1d0);
        *(undefined8 *)(puVar8 + 6) = uVar3;
        *(undefined8 *)puVar8 = uVar3;
        *(undefined8 *)(puVar8 + 4) = uVar3;
        puVar8[2] = 0;
        puVar8[3] = 0;
        puVar8[0xc] = *(uint *)(lVar12 + 0xb0);
        if ((*(uint *)(lVar12 + 0xb0) & 0x10) == 0) {
          *(undefined8 *)(puVar8 + 8) = *(undefined8 *)(lVar12 + 0x18);
          *(undefined8 *)(puVar8 + 10) = *(undefined8 *)(lVar12 + 0x20);
        }
        else {
          puVar8[10] = 0;
          puVar8[0xb] = 0;
          puVar8[8] = 0;
          puVar8[9] = 0;
        }
        uVar9 = uVar9 - 0x38;
        goto LAB_1400143dd;
      }
      goto LAB_1400140b0;
    }
    if ((*(uint *)(uVar10 + 4) & 1) == 0) {
      uVar6 = CdQueryAlternateNameInfo(param_1,lVar12,uVar10,puVar8,local_res18);
      uVar9 = local_res18[0];
    }
    else {
      uVar6 = 0xc000000d;
    }
  }
  lVar11 = local_res20;
LAB_1400143f4:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)(*(int *)(lVar11 + 8) - uVar9);
  if (bVar5) {
    ExReleaseResourceLite(*(undefined8 *)(lVar12 + 8));
  }
  CdCompleteRequest(param_1,param_2,uVar6);
  return uVar6;
}



===== CdCommonSetInfo @ 140014444 =====

uint CdCommonSetInfo(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  uint *puVar3;
  void *pvVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  
  uVar7 = 0xc000000d;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar5 = *(uint *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 7;
  if (uVar5 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18);
  }
  if ((uVar5 == 4) && (*(int *)(lVar2 + 0x10) == 0xe)) {
    CdAcquireResource((longlong)param_1,*(ulonglong *)(lVar6 + 8),'\0',1);
    CdVerifyFcbOperation((longlong)param_1,lVar6);
    pvVar4 = SystemReserved1[0xf];
    puVar3 = *(uint **)(param_2 + 0x18);
    if (((*(uint *)(*(longlong *)(lVar2 + 0x30) + 0x50) & 8) == 0) ||
       (uVar7 = 0xc000000d, (*puVar3 & *(uint *)(*(longlong *)(lVar6 + 0x78) + 0x1b8)) == 0)) {
      if (SystemReserved1[0xf] != *(void **)(lVar6 + 0xb8)) {
        ExAcquireFastMutex(*(longlong *)(lVar6 + 200) + 0x88);
        *(void **)(lVar6 + 0xb8) = pvVar4;
      }
      *(int *)(lVar6 + 0xc0) = *(int *)(lVar6 + 0xc0) + 1;
      *(undefined8 *)(*(longlong *)(lVar2 + 0x30) + 0x68) = *(undefined8 *)puVar3;
      piVar1 = (int *)(lVar6 + 0xc0);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined8 *)(lVar6 + 0xb8) = 0;
        ExReleaseFastMutex(*(longlong *)(lVar6 + 200) + 0x88);
      }
      uVar7 = 0;
    }
    ExReleaseResourceLite(*(undefined8 *)(lVar6 + 8));
  }
  CdCompleteRequest(param_1,param_2,uVar7);
  return uVar7;
}



===== CdFastQueryBasicInfo @ 140014590 =====

bool CdFastQueryBasicInfo
               (longlong param_1,undefined1 param_2,undefined8 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined7 in_register_00000011;
  bool bVar6;
  
  KeEnterCriticalRegion();
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 0x20) & 7;
  if (((uVar4 != 4) && ((uVar4 != 3 || ((*(uint *)(lVar1 + 0xac) & 1) == 0)))) ||
     (cVar3 = ExAcquireResourceSharedLite
                        (*(undefined8 *)(lVar1 + 8),CONCAT71(in_register_00000011,param_2)),
     cVar3 == '\0')) {
    KeLeaveCriticalRegion();
    return false;
  }
  uVar5 = CdVerifyFcbOperation(0,lVar1);
  bVar6 = (char)uVar5 != '\0';
  if (bVar6) {
    uVar2 = *(undefined8 *)(lVar1 + 0x1d0);
    param_3[3] = uVar2;
    param_3[2] = uVar2;
    *param_3 = uVar2;
    param_3[1] = 0;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(lVar1 + 0xb0);
    *param_4 = 0;
    *(undefined8 *)(param_4 + 2) = 0x28;
  }
  ExReleaseResourceLite(*(undefined8 *)(lVar1 + 8));
  KeLeaveCriticalRegion();
  return bVar6;
}



===== CdFastQueryNetworkInfo @ 140014690 =====

undefined1
CdFastQueryNetworkInfo(longlong param_1,undefined1 param_2,undefined8 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined7 in_register_00000011;
  undefined1 uVar6;
  
  uVar6 = 0;
  KeEnterCriticalRegion();
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 0x20) & 7;
  if (((uVar4 != 4) && ((uVar4 != 3 || ((*(uint *)(lVar1 + 0xac) & 1) == 0)))) ||
     (cVar3 = ExAcquireResourceSharedLite
                        (*(undefined8 *)(lVar1 + 8),CONCAT71(in_register_00000011,param_2)),
     cVar3 == '\0')) {
    KeLeaveCriticalRegion();
    return 0;
  }
  uVar5 = CdVerifyFcbOperation(0,lVar1);
  if ((char)uVar5 != '\0') {
    uVar2 = *(undefined8 *)(lVar1 + 0x1d0);
    param_3[3] = uVar2;
    param_3[2] = uVar2;
    *param_3 = uVar2;
    param_3[1] = 0;
    *(undefined4 *)(param_3 + 6) = *(undefined4 *)(lVar1 + 0xb0);
    if ((*(uint *)(lVar1 + 0xb0) & 0x10) == 0) {
      param_3[4] = *(undefined8 *)(lVar1 + 0x18);
      param_3[5] = *(undefined8 *)(lVar1 + 0x20);
    }
    else {
      param_3[5] = 0;
      param_3[4] = 0;
    }
    *param_4 = 0;
    *(undefined8 *)(param_4 + 2) = 0x38;
    uVar6 = 1;
  }
  ExReleaseResourceLite(*(undefined8 *)(lVar1 + 8));
  KeLeaveCriticalRegion();
  return uVar6;
}



===== CdFastQueryStdInfo @ 1400147b0 =====

undefined1
CdFastQueryStdInfo(longlong param_1,undefined1 param_2,undefined8 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined7 in_register_00000011;
  undefined1 uVar5;
  
  uVar5 = 0;
  KeEnterCriticalRegion();
  lVar1 = *(longlong *)(param_1 + 0x18);
  uVar3 = *(uint *)(param_1 + 0x20) & 7;
  if (((uVar3 != 4) && ((uVar3 != 3 || ((*(uint *)(lVar1 + 0xac) & 1) == 0)))) ||
     (cVar2 = ExAcquireResourceSharedLite
                        (*(undefined8 *)(lVar1 + 8),CONCAT71(in_register_00000011,param_2)),
     cVar2 == '\0')) {
    KeLeaveCriticalRegion();
    return 0;
  }
  uVar4 = CdVerifyFcbOperation(0,lVar1);
  if ((char)uVar4 != '\0') {
    if ((*(uint *)(lVar1 + 0xb0) & 0x10) == 0) {
      *param_3 = *(undefined8 *)(lVar1 + 0x18);
      param_3[1] = *(undefined8 *)(lVar1 + 0x20);
      *(undefined1 *)((longlong)param_3 + 0x15) = 0;
    }
    else {
      param_3[1] = 0;
      *param_3 = 0;
      *(undefined1 *)((longlong)param_3 + 0x15) = 1;
    }
    *(undefined4 *)(param_3 + 2) = 1;
    *(undefined1 *)((longlong)param_3 + 0x14) = 0;
    *param_4 = 0;
    *(undefined8 *)(param_4 + 2) = 0x18;
    uVar5 = 1;
  }
  ExReleaseResourceLite(*(undefined8 *)(lVar1 + 8));
  KeLeaveCriticalRegion();
  return uVar5;
}



===== CdQueryAlternateNameInfo @ 1400148c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CdQueryAlternateNameInfo
              (void *param_1,longlong param_2,longlong param_3,uint *param_4,uint *param_5)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  void *pvVar7;
  longlong lVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined1 auStackY_558 [32];
  ushort local_524 [2];
  longlong local_520;
  longlong local_518 [4];
  undefined8 local_4f8;
  undefined8 uStack_4f0;
  longlong local_4e8 [2];
  longlong local_4d8;
  char local_4cc;
  undefined1 local_4c8 [32];
  byte local_4a8;
  longlong local_498;
  ushort local_480 [52];
  undefined1 *local_418;
  undefined1 *local_410;
  undefined1 *local_408;
  undefined2 local_3ee;
  undefined1 *local_3e8;
  undefined1 local_3d0 [24];
  undefined1 local_3b8 [224];
  undefined1 local_2d8 [224];
  undefined1 local_1f8 [224];
  uint local_118 [6];
  byte local_ff;
  longlong local_d8;
  undefined8 local_c0 [13];
  short local_58 [12];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_558;
  iVar9 = 0;
  local_518[0] = 0;
  local_518[1] = 0;
  local_518[2] = 0;
  local_518[3] = 0;
  memset(local_118,0,0xc0);
  memset(local_4e8,0,200);
  memset(&local_418,0,0x300);
  bVar2 = false;
  bVar3 = false;
  local_524[0] = 0;
  *param_4 = 0;
  if ((param_2 == *(longlong *)(*(longlong *)(param_2 + 0x78) + 0x50)) ||
     ((*(uint *)(param_3 + 4) & 8) != 0)) {
    iVar9 = -0x3fffffcc;
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x80);
    local_520 = lVar1;
    CdAcquireResource((longlong)param_1,*(ulonglong *)(lVar1 + 8),'\0',1);
    if (*(longlong *)(lVar1 + 0x1d8) == 0) {
      CdCreateInternalStream
                (param_1,*(longlong *)(lVar1 + 0x78),lVar1,(undefined4 *)(lVar1 + 0x158));
    }
    pvVar7 = param_1;
    if ((int)*(uint *)(param_2 + 0x98) < 0) {
      local_418 = local_3b8;
      local_410 = local_2d8;
      local_408 = local_1f8;
      local_3ee = 0x18;
      local_3e8 = local_3d0;
      bVar3 = true;
      uVar5 = 0;
      CdLookupPathEntry((longlong)param_1,*(uint *)(param_2 + 0x9c),*(undefined4 *)(param_2 + 0x1f8)
                        ,'\0',local_4e8);
      CdUpdatePathEntryName((longlong)param_1,(longlong)local_4c8,'\x01');
      uVar5 = CdFindDirectory(param_1,lVar1,local_480,uVar5,&local_418);
      if ((char)uVar5 == '\0') {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc0000032,'\0',0xd0000,0x554);
      }
      puVar10 = (undefined8 *)(local_410 + 0x78);
      uVar4 = *(uint *)(local_410 + 0x20);
    }
    else {
      bVar2 = true;
      lVar8 = lVar1;
      CdLookupDirent((longlong)param_1,lVar1,*(uint *)(param_2 + 0x98) & 0x7fffffff,local_518);
      CdUpdateDirentFromRawDirent((longlong)param_1,lVar8,local_518,(int *)local_118);
      CdUpdateDirentName(param_1,(longlong)local_118,1);
      puVar10 = local_c0;
      uVar4 = local_118[0];
    }
    local_4f8 = *puVar10;
    uStack_4f0 = puVar10[1];
    uVar6 = CdIs8dot3Name(pvVar7,(uint *)&local_4f8);
    if ((char)uVar6 == '\0') {
      CdGenerate8dot3Name((longlong)param_1,puVar10,uVar4,local_58,(short *)local_524);
      uVar4 = (uint)local_524[0];
      *param_4 = (uint)local_524[0];
      if (*param_5 < local_524[0] + 4) {
        uVar4 = *param_5 - 4;
        *param_4 = uVar4;
        iVar9 = -0x7ffffffb;
      }
      memmove(param_4 + 1,local_58,(ulonglong)uVar4);
    }
    else {
      iVar9 = -0x3fffffcc;
    }
    if (bVar2) {
      if (local_518[2] != 0) {
        CcUnpinData();
        local_518[2] = 0;
      }
      if (((local_ff & 1) != 0) && (local_d8 != 0)) {
        ExFreePoolWithTag(local_d8,0);
        local_d8 = 0;
      }
    }
    else if (bVar3) {
      lVar8 = local_4d8;
      if (local_4d8 != 0) {
        CcUnpinData();
        local_4d8 = 0;
      }
      if ((local_4cc != '\0') && (lVar8 = local_4e8[0], local_4e8[0] != 0)) {
        ExFreePoolWithTag(local_4e8[0],0);
        local_4e8[0] = 0;
      }
      if (((local_4a8 & 1) != 0) && (lVar8 = local_498, local_498 != 0)) {
        ExFreePoolWithTag(local_498,0);
        local_498 = 0;
      }
      CdCleanupFileContext(lVar8,(longlong)&local_418);
    }
    ExReleaseResourceLite(*(undefined8 *)(lVar1 + 8));
    if (iVar9 != -0x3fffffcc) {
      *param_5 = *param_5 + (-4 - *param_4);
    }
  }
  return iVar9;
}



===== CdDecodeFileObject @ 140014cc4 =====

void CdDecodeFileObject(undefined8 param_1,longlong param_2,undefined8 *param_3,ulonglong *param_4)

{
  if ((*(uint *)(param_2 + 0x20) & 7) == 0) {
    *param_3 = 0;
    *param_4 = 0;
    return;
  }
  *param_3 = *(undefined8 *)(param_2 + 0x18);
  *param_4 = *(ulonglong *)(param_2 + 0x20) & 0xfffffffffffffff8;
  return;
}



===== CdCommonFsControl @ 140014cf0 =====

uint CdCommonFsControl(short *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 == '\0') {
    uVar2 = CdUserFsctl(param_1,param_2,0,param_4);
  }
  else if (cVar1 == '\x01') {
    uVar2 = CdMountVolume(param_1,param_2);
  }
  else {
    if (cVar1 != '\x02') {
      CdCompleteRequest((undefined8 *)param_1,param_2,0xc0000010);
      return 0xc0000010;
    }
    uVar2 = CdVerifyVolume(param_1,param_2);
  }
  return uVar2;
}



===== CdDismountVolume @ 140014d48 =====

uint CdDismountVolume(undefined8 *param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  uVar5 = *(uint *)(lVar2 + 0x20) & 7;
  if (uVar5 != 0) {
    uVar3 = *(ulonglong *)(lVar2 + 0x20);
    if (uVar5 == 2) {
      lVar4 = *(longlong *)(*(longlong *)(lVar2 + 0x18) + 0x78);
      FsRtlNotifyVolumeEvent(lVar2,1);
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
      ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
      CdAcquireResource((longlong)param_1,lVar4 + 0x80U,'\0',0);
      if (*(int *)(lVar4 + 0x34) == 2) {
        ExAcquireFastMutex(lVar4 + 0x150);
        if (*(int *)(lVar4 + 0x34) != 4) {
          *(undefined4 *)(lVar4 + 0x34) = 3;
        }
        *(uint *)(lVar4 + 0x30) = *(uint *)(lVar4 + 0x30) | 0x800;
        uVar5 = 0;
        *(undefined8 *)(lVar4 + 0x188) = 0;
        ExReleaseFastMutex(lVar4 + 0x150);
        puVar1 = (uint *)((uVar3 & 0xfffffffffffffff8) + 4);
        *puVar1 = *puVar1 | 0x10;
      }
      else {
        uVar5 = 0xc000026e;
      }
      ExReleaseResourceLite(lVar4 + 0x80U);
      ExReleaseResourceLite(&DAT_1400083d0);
      FsRtlDismountComplete(*(undefined8 *)(lVar4 + 0x10),uVar5);
      CdCompleteRequest(param_1,param_2,uVar5);
      return uVar5;
    }
  }
  CdCompleteRequest(param_1,param_2,0xc000000d);
  return 0xc000000d;
}



===== CdFindActiveVolDescriptor @ 140014eac =====

void CdFindActiveVolDescriptor(longlong param_1,longlong param_2,char *param_3,char param_4)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_res10 [2];
  undefined4 local_res20 [2];
  
  local_res10[0] = 0;
  if (((*(uint *)(param_2 + 0x30) & 2) != 0) || (param_4 != '\0')) {
    if (CdNoJoliet == '\0') {
      iVar6 = *(int *)(param_2 + 0x60);
      iVar8 = 0x10;
      pcVar5 = param_3;
      while ((((CdReadSectors(param_1,(ulonglong)(uint)(iVar6 + iVar8) << 0xb,pcVar5,'\0',param_3,
                              *(undefined8 *)(param_2 + 0x10)), CdIsoId == *(int *)(param_3 + 1) &&
               (DAT_140008154 == param_3[5])) && (param_3[6] == '\x01')) && (*param_3 != -1))) {
        if ((*param_3 == '\x02') &&
           ((((*(short *)(param_3 + 0x58) == 0x2f25 && (param_3[0x5a] == '@')) ||
             ((*(short *)(param_3 + 0x58) == 0x2f25 && (param_3[0x5a] == 'C')))) ||
            ((*(short *)(param_3 + 0x58) == 0x2f25 && (param_3[0x5a] == 'E')))))) {
          if (param_4 != '\0') {
            return;
          }
          *(int *)(param_2 + 100) = iVar8;
          *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xfffffffd | 4;
          goto LAB_140014fca;
        }
        iVar6 = *(int *)(param_2 + 0x60);
        iVar8 = iVar8 + 1;
      }
      memmove(param_3,param_3 + 0x800,0x800);
    }
    if (param_4 != '\0') {
      return;
    }
  }
LAB_140014fca:
  local_res20[0] = 0;
  uVar7 = 0;
  pcVar5 = param_3;
  iVar6 = 0x800;
  do {
    iVar8 = iVar6;
    cVar2 = *pcVar5;
    uVar7 = uVar7 - 1;
    pcVar5 = pcVar5 + 1;
    pcVar1 = (char *)((longlong)local_res20 + (ulonglong)(uVar7 & 3));
    *pcVar1 = *pcVar1 + cVar2;
    iVar6 = iVar8 + -1;
  } while (iVar6 != 0);
  *(undefined4 *)(*(longlong *)(param_2 + 8) + 0x18) = local_res20[0];
  if ((*(uint *)(param_2 + 0x30) & 4) == 0) {
    *(undefined2 *)(*(longlong *)(param_2 + 8) + 6) = 0;
    iVar6 = RtlOemToUnicodeN(*(longlong *)(param_2 + 8) + 0x20,iVar8 + 0x3f,local_res10,
                             param_3 + ((ulonglong)(*(uint *)(param_2 + 0x30) & 1) + 5) * 8,0x20);
    if (-1 < iVar6) {
      *(undefined2 *)(*(longlong *)(param_2 + 8) + 6) = (undefined2)local_res10[0];
    }
  }
  else {
    CdConvertBigToLittleEndian
              (param_1,param_3 + ((ulonglong)(*(uint *)(param_2 + 0x30) & 1) + 5) * 8,0x20,
               (void *)(*(longlong *)(param_2 + 8) + 0x20));
    *(undefined2 *)(*(longlong *)(param_2 + 8) + 6) = 0x40;
  }
  lVar3 = *(longlong *)(param_2 + 8);
  uVar7 = (uint)(*(ushort *)(lVar3 + 6) >> 1);
  do {
    uVar4 = uVar7;
    if (uVar4 == 0) break;
    uVar7 = uVar4 - 1;
  } while ((*(ushort *)(lVar3 + 0x20 + (ulonglong)(uVar4 - 1) * 2) & 0xffdf) == 0);
  *(short *)(lVar3 + 6) = (short)uVar4 * 2;
  return;
}



===== CdFindPrimaryVd @ 1400150dc =====

char CdFindPrimaryVd(longlong param_1,longlong param_2,char *param_3,uint param_4,char param_5,
                    char param_6)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char local_res10;
  undefined8 in_stack_ffffffffffffff80;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  longlong local_58;
  uint *local_50;
  undefined1 *local_48;
  
  uVar10 = 1;
  local_res10 = '\0';
  if ((char)*(undefined4 *)(param_2 + 0x30) < '\0') {
    local_res10 = '\0';
  }
  else {
    for (; (local_res10 == '\0' && (uVar10 < 3)); uVar10 = uVar10 + 1) {
      uVar12 = 0;
      local_68 = 0;
      if (uVar10 == 1) {
        local_58 = 0;
        uVar6 = 0x411;
        lVar4 = ExAllocatePoolWithTag(0x411,0x554,0x63746443);
        local_58 = lVar4;
        iVar2 = CdPerformDevIoCtrl(uVar6,0x24038,*(undefined8 *)(param_2 + 0x10),lVar4,0x554,
                                   in_stack_ffffffffffffff80,'\x01',(uint *)0x0);
        if (iVar2 == -0x3fffff66) {
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc000009a,'\0',0xf0000,0xb50);
        }
        if ((iVar2 < 0) || (*(char *)(lVar4 + 2) == *(char *)(lVar4 + 3))) {
          uVar10 = 2;
          local_60 = 2;
          uVar12 = 0;
        }
        else {
          iVar2 = 4;
          puVar7 = (undefined1 *)(lVar4 + 0xb);
          puVar9 = &local_68;
          do {
            *(undefined1 *)puVar9 = *puVar7;
            puVar9 = (uint *)((longlong)puVar9 + 1);
            puVar7 = puVar7 + -1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          local_68 = local_68 / param_4;
          local_64 = 0;
          uVar12 = local_68;
          local_50 = puVar9;
          local_48 = puVar7;
        }
        if (lVar4 != 0) {
          ExFreePoolWithTag(lVar4,0);
        }
      }
      iVar2 = 0x10;
      uVar3 = 0;
      uVar11 = uVar12 + 0x10;
      while( true ) {
        if ((uVar10 == 1) || (param_5 != '\0')) {
          cVar1 = '\x01';
        }
        else {
          cVar1 = '\0';
        }
        in_stack_ffffffffffffff80 = *(undefined8 *)(param_2 + 0x10);
        uVar6 = CdReadSectors(param_1,(ulonglong)uVar11 << 0xb,param_1,cVar1,param_3,
                              in_stack_ffffffffffffff80);
        if ((char)uVar6 == '\0') goto LAB_14001531e;
        if ((CdIsoId == *(int *)(param_3 + 1)) && (DAT_140008154 == param_3[5])) {
          uVar8 = 2;
        }
        else {
          if ((CdHsgId != *(int *)(param_3 + 9)) || (DAT_14000815c != param_3[0xd]))
          goto LAB_14001531e;
          uVar8 = 1;
        }
        uVar3 = uVar8 | uVar3;
        uVar8 = uVar3 & 1;
        if (uVar8 == 0) {
          cVar1 = param_3[6];
        }
        else {
          cVar1 = param_3[0xe];
        }
        if (cVar1 != '\x01') goto LAB_14001531e;
        pcVar5 = param_3 + 8;
        if (uVar8 == 0) {
          pcVar5 = param_3;
        }
        if (*pcVar5 == -1) goto LAB_14001531e;
        pcVar5 = param_3 + 8;
        if (uVar8 == 0) {
          pcVar5 = param_3;
        }
        if (*pcVar5 == '\x01') break;
        iVar2 = iVar2 + 1;
        uVar11 = uVar11 + 1;
      }
      if (param_6 == '\0') {
        *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | uVar3;
        *(uint *)(param_2 + 0x60) = uVar12;
        *(int *)(param_2 + 100) = iVar2;
        *(int *)(param_2 + 0x68) = iVar2;
      }
      local_res10 = '\x01';
LAB_14001531e:
    }
  }
  return local_res10;
}



===== CdIsRemount @ 140015370 =====

undefined8 CdIsRemount(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  void *_Buf1;
  void *_Buf2;
  undefined8 *puVar5;
  undefined1 uVar6;
  
  lVar2 = param_2[1];
  uVar6 = 0;
  puVar5 = DAT_140008330;
  do {
    if ((undefined8 **)puVar5 == &DAT_140008330) {
LAB_140015475:
      return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),uVar6);
    }
    register0x00000020 = (BADSPACEBASE *)(puVar5 + -4);
    *param_3 = register0x00000020;
    if ((((param_2 != (undefined8 *)register0x00000020) && (lVar3 = puVar5[-3], lVar3 != lVar2)) &&
        (register0x00000020 = *(BADSPACEBASE **)(lVar2 + 0x10),
        *(undefined8 **)(lVar3 + 0x10) == (undefined8 *)register0x00000020)) &&
       (*(int *)((longlong)puVar5 + 0x14) == 0)) {
      if ((char)*(undefined4 *)(param_2 + 6) < '\0') {
        register0x00000020 = (BADSPACEBASE *)(ulonglong)*(uint *)(puVar5 + 2);
        if ((char)*(uint *)(puVar5 + 2) < '\0') {
          uVar1 = *(uint *)(param_2 + 0x42);
          register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar1;
          if (uVar1 == *(uint *)(puVar5 + 0x3e)) {
            if (uVar1 != 0) {
              _Buf2 = (void *)puVar5[0x3d];
              _Buf1 = (void *)param_2[0x41];
LAB_140015458:
              iVar4 = memcmp(_Buf1,_Buf2,(size_t)register0x00000020);
              register0x00000020 = (BADSPACEBASE *)CONCAT44(extraout_var_00,iVar4);
              if (iVar4 != 0) goto LAB_140015464;
            }
            uVar6 = 1;
            goto LAB_140015475;
          }
        }
      }
      else {
        register0x00000020 = (BADSPACEBASE *)(ulonglong)*(uint *)(lVar2 + 0x18);
        if (*(uint *)(lVar3 + 0x18) == *(uint *)(lVar2 + 0x18)) {
          uVar1 = *(uint *)(param_2 + 0x42);
          register0x00000020 = (BADSPACEBASE *)(ulonglong)uVar1;
          if (uVar1 == *(uint *)(puVar5 + 0x3e)) {
            if (uVar1 != 0) {
              iVar4 = memcmp((void *)param_2[0x41],(void *)puVar5[0x3d],(ulonglong)uVar1);
              register0x00000020 = (BADSPACEBASE *)CONCAT44(extraout_var,iVar4);
              if (iVar4 != 0) goto LAB_140015464;
            }
            register0x00000020 = (BADSPACEBASE *)(ulonglong)*(ushort *)(lVar2 + 6);
            if (*(ushort *)(lVar2 + 6) == *(ushort *)(lVar3 + 6)) {
              _Buf2 = (void *)(lVar2 + 0x20);
              _Buf1 = (void *)(lVar3 + 0x20);
              goto LAB_140015458;
            }
          }
        }
      }
    }
LAB_140015464:
    puVar5 = (undefined8 *)*puVar5;
  } while( true );
}



===== CdLockVolume @ 1400154a0 =====

uint CdLockVolume(short *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(lVar1 + 0x30);
  uVar3 = *(uint *)(lVar2 + 0x20) & 7;
  if (uVar3 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = *(longlong *)(lVar2 + 0x18);
  }
  if (uVar3 == 2) {
    FsRtlNotifyVolumeEvent(lVar2,3,param_3,param_4,0);
    lVar2 = *(longlong *)(lVar4 + 0x78);
    CdAcquireResource((longlong)param_1,lVar2 + 0x80U,'\0',0);
    CdVerifyVcb((longlong)param_1,lVar2);
    uVar3 = CdLockVolumeInternal(param_1,lVar2,*(longlong *)(lVar1 + 0x30));
    ExReleaseResourceLite(lVar2 + 0x80U);
    if ((int)uVar3 < 0) {
      FsRtlNotifyVolumeEvent(*(undefined8 *)(lVar1 + 0x30),4);
    }
  }
  else {
    uVar3 = 0xc000000d;
  }
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar3);
  return uVar3;
}



===== CdMountVolume @ 140015594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140015ddb) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CdMountVolume(short *param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  ulonglong uVar7;
  short *_Src;
  undefined8 uVar8;
  short *psVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 *puVar12;
  uint *puVar13;
  uint *puVar14;
  short *psVar15;
  undefined1 auStackY_158 [32];
  uint *puVar16;
  undefined8 in_stack_fffffffffffffee0;
  char local_108;
  uint local_104;
  undefined4 local_ec;
  uint local_e8;
  undefined1 *local_e0;
  longlong local_d8;
  uint local_d0 [4];
  short *local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  short *local_a0;
  undefined8 local_98;
  longlong local_90;
  short *local_88;
  uint local_80 [2];
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  uint local_60 [6];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_158;
  lVar11 = 0;
  local_b8 = 0;
  local_a8 = 0;
  local_108 = '\0';
  puVar14 = *(uint **)(*(longlong *)(param_2 + 0xb8) + 0x10);
  local_d8 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  psVar15 = (short *)0x0;
  local_a0 = (short *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_60[5] = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  lStack_78 = 0;
  _Src = (short *)0x0;
  local_c0 = (short *)0x0;
  local_e0 = (undefined1 *)0x0;
  local_d0[2] = 0;
  local_d0[1] = 0;
  local_d0[0] = 0;
  local_ec = 0;
  local_70 = 0;
  uStack_68 = 0;
  lVar2 = *(longlong *)(local_d8 + 0x10);
  *(longlong *)(param_1 + 0x14) = lVar2;
  bVar1 = *(byte *)(lVar2 + 0x30);
  local_90 = local_d8;
  local_88 = param_1;
  if (CdDisable != '\0') {
    local_104 = 0xc000014f;
    goto LAB_14001567d;
  }
  if ((DAT_14000836e & 1) != 0) {
    CdCompleteRequest((undefined8 *)param_1,param_2,0xc00002eb);
    return 0xc00002eb;
  }
  uVar7 = CdPerformDevIoCtrlEx
                    (0,0x24800,puVar14,0,0,&local_ec,4,in_stack_fffffffffffffee0,'\x01',local_80);
  local_104 = (uint)uVar7;
  if ((int)local_104 < 0) goto LAB_14001567d;
  if (lStack_78 != 4) {
    local_ec = 0;
  }
  uVar7 = CdPerformDevIoCtrlEx
                    (0,0x2404c,puVar14,0,0,&local_48,0x18,in_stack_fffffffffffffee0,'\x01',
                     (uint *)0x0);
  local_104 = 0xc000009a;
  if ((int)uVar7 == -0x3fffff66) goto LAB_14001567d;
  local_e8 = 1;
  if ((-1 < (int)uVar7) && (local_38._4_4_ - 1 < 0x7ff)) {
    local_e8 = (uint)(0x800 / (ulonglong)local_38._4_4_);
  }
  ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
  local_e0 = (undefined1 *)ExAllocatePoolWithTag(0x411,0x554);
  puVar10 = DAT_140008330;
  while (puVar12 = puVar10, (undefined8 **)puVar12 != &DAT_140008330) {
    puVar10 = (undefined8 *)*puVar12;
    if ((*(int *)((longlong)puVar12 + 0x14) - 3U < 2) ||
       ((*(int *)((longlong)puVar12 + 0x14) == 0 && (*(uint *)((longlong)puVar12 + 0x1c) < 7)))) {
      CdCheckForDismount((longlong)param_1,(longlong)(puVar12 + -4),'\0');
    }
  }
  puVar13 = (uint *)0x3;
  local_104 = IoCreateDevice(DAT_140008328,0x340,0);
  if (-1 < (int)local_104) {
    if (uRam0000000000000098 < puVar14[0x26]) {
      uRam0000000000000098 = puVar14[0x26];
    }
    bVar4 = (char)puVar14[0x13] + 1;
    uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
    uRam0000000000000154 = 0;
    uRam0000000000000160 = 0x158;
    uRam0000000000000158 = 0x158;
    uRam0000000000000150 = 0;
    uVar8 = 0x168;
    bRam000000000000004c = bVar4;
    KeInitializeSpinLock();
    puVar16 = local_d0;
    puVar13 = local_d0 + 2;
    uVar7 = CdProcessToc(uVar8,puVar14,local_e0,(int *)puVar13,(int *)(local_d0 + 1),puVar16);
    uVar3 = local_d0[0];
    local_104 = (uint)uVar7;
    if (local_104 == 0) {
      *(undefined8 *)(local_d8 + 8) = 0;
      uVar7 = CONCAT44((int)((ulonglong)puVar16 >> 0x20),local_d0[2]);
      CdInitializeVcb(local_d8,(undefined4 *)0x170,puVar14,local_d8);
      lVar11 = 0x170;
      local_d8 = 0;
      local_90 = 0;
      local_e0 = (undefined1 *)0x0;
      local_b8 = lVar11;
      iVar6 = FsRtlVolumeDeviceToCorrelationId(uRam0000000000000180,&local_70);
      if (-1 < iVar6) {
        uRam0000000000000480 = local_70;
        uRam0000000000000488 = uStack_68;
      }
      param_1[8] = 0x170;
      param_1[9] = 0;
      param_1[10] = 0;
      param_1[0xb] = 0;
      puVar13 = (uint *)0x0;
      CdAcquireResource((longlong)param_1,0x1f0,'\0',0);
      *(int *)(lRam0000000000000178 + 0x1c) = *(int *)(lRam0000000000000178 + 0x1c) + 1;
      psVar9 = *(short **)(lRam0000000000000178 + 0x10);
      *(uint *)(psVar9 + 0x18) = *(uint *)(psVar9 + 0x18) & 0xfffffffd;
      if (-1 < (char)uRam00000000000001a0) {
        _Src = (short *)ExAllocatePoolWithTag(0x610,0x1000,0x64766443);
        uVar7 = uVar7 & 0xffffffffffffff00;
        puVar13 = (uint *)(ulonglong)local_e8;
        psVar9 = param_1;
        local_c0 = _Src;
        local_108 = CdFindPrimaryVd((longlong)param_1,0x170,(char *)_Src,local_e8,'\x01','\0');
        if (local_108 == '\0') {
          if (((uVar3 & 1) == 0) || ((*(byte *)((longlong)psRam0000000000000378 + 5) & 4) != 0)) {
            local_104 = 0xc000014f;
            goto LAB_140015d49;
          }
          uRam00000000000001a0 = uRam00000000000001a0 | 0xc0;
          psVar9 = psRam0000000000000378;
          if (_Src != (short *)0x0) {
            ExFreePoolWithTag(_Src,0);
            psVar9 = _Src;
          }
          _Src = (short *)0x0;
          local_c0 = (short *)0x0;
        }
      }
      if (local_108 != '\0') {
        memmove(_Src + 0x400,_Src,0x800);
        puVar13 = (uint *)0x0;
        psVar9 = param_1;
        CdFindActiveVolDescriptor((longlong)param_1,0x170,(char *)_Src,'\0');
      }
      if ((-1 < (char)uRam00000000000001a0) &&
         (*(char *)((longlong)psRam0000000000000378 + 3) == (char)psRam0000000000000378[1])) {
        local_d0[3] = 0;
        local_b0 = 0;
        local_b0 = ExAllocatePoolWithTag(0x411,0x30000,0x73666443);
        lRam00000000000003a8 = local_b0;
        for (local_d0[3] = 0; local_d0[3] < 4; local_d0[3] = local_d0[3] + 1) {
          *(longlong *)((ulonglong)local_d0[3] * 0x10 + 0x3b8) = local_b0;
          *(undefined4 *)(((ulonglong)local_d0[3] + 0x24) * 0x10 + 0x170) = 0xffffffff;
          local_b0 = local_b0 + 0xc000;
        }
        lRam00000000000003f8 = IoAllocateIrp(bVar4,0);
        if (lRam00000000000003f8 == 0) {
          local_104 = 0xc000009a;
          goto LAB_140015d49;
        }
        IoInitializeIrp(lRam00000000000003f8,((ushort)bVar4 * 8 + (ushort)bVar4) * 8 + 0xd0,bVar4);
        KeInitializeEvent(0x400,1);
        psVar9 = (short *)0x418;
        ExInitializeResourceLite();
      }
      uVar8 = CdIsRemount(psVar9,(undefined8 *)0x170,&local_a8);
      lVar2 = local_a8;
      if ((char)uVar8 == '\0') {
        psVar9 = param_1;
        CdUpdateVcbFromVolDescriptor(param_1,0x170,(longlong)_Src);
        if (lRam00000000000001c0 != 0) {
          psVar15 = *(short **)(lRam00000000000001c0 + 0x1d8);
          psVar9 = psVar15;
          local_a0 = psVar15;
          ObfReferenceObject();
        }
        puVar13 = local_60;
        iVar6 = CdPerformDevIoCtrl(psVar9,0x41010,puVar14,puVar13,0x18,uVar7,'\x01',(uint *)0x0);
        if (iVar6 < 0) {
          uRam0000000000000394 = 0x1b;
          uRam0000000000000398 = 0x10;
        }
        else {
          uRam0000000000000394 = local_60[1] / 0x930;
          uRam0000000000000398 = local_60[2];
        }
        iRam00000000000001ac = iRam00000000000001ac + -6;
        ObfDereferenceObject(uRam0000000000000180);
        uRam00000000000001a4 = 2;
        ExReleaseResourceLite(0x1f0);
        lVar11 = 0;
        local_b8 = 0;
      }
      else {
        CdReMountOldVcb((ulonglong)psVar9,local_a8,0x170,puVar14);
        puVar13 = puVar14;
        if ((*(uint *)(lVar2 + 0x30) >> 8 & 1) != 0) {
          *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) & 0xfffffeff;
          psVar15 = *(short **)(*(longlong *)(lVar2 + 0x50) + 0x1d8);
          local_a0 = psVar15;
          ObfReferenceObject(psVar15);
          puVar13 = puVar14;
        }
      }
      local_104 = 0;
    }
  }
LAB_140015d49:
  if (local_e0 != (undefined1 *)0x0) {
    ExFreePoolWithTag(local_e0,0);
  }
  if (_Src != (short *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  if ((local_104 != 0) && ((bVar1 >> 1 & 1) != 0)) {
    *(uint *)(*(longlong *)(param_1 + 0x14) + 0x30) =
         *(uint *)(*(longlong *)(param_1 + 0x14) + 0x30) | 2;
  }
  if (local_d8 != 0) {
    *(undefined8 *)(local_d8 + 8) = 0;
  }
  if (lVar11 != 0) {
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    *(int *)(lVar11 + 0x3c) = *(int *)(lVar11 + 0x3c) + -6;
    cVar5 = CdDismountVcb(param_1,lVar11);
    if (cVar5 != '\0') {
      ExReleaseResourceLite(lVar11 + 0x80);
    }
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  if (psVar15 != (short *)0x0) {
    FsRtlNotifyVolumeEvent(psVar15,6);
    ObfDereferenceObject(psVar15);
  }
  if (5 < DAT_140008020) {
    local_98 = 0;
    local_d8 = 0;
    puVar10 = &local_98;
    IoGetStackLimits(&local_d8);
    if ((ulonglong)((longlong)local_80 + (-0x18 - local_d8)) < 0x800) {
      LOCK();
      _CdTelemetryData = _CdTelemetryData + 1;
      UNLOCK();
    }
    else {
      CdTelemetryMount(&local_70,puVar10,lVar11,puVar13);
    }
  }
LAB_14001567d:
  CdCompleteRequest((undefined8 *)param_1,param_2,local_104);
  return local_104;
}



===== CdOplockRequest @ 140015ea0 =====

uint CdOplockRequest(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  void *pvVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 uVar10;
  
  uVar8 = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar7 = *(uint *)(*(longlong *)(lVar3 + 0x30) + 0x20) & 7;
  if (uVar7 == 0) {
    lVar9 = 0;
  }
  else {
    lVar9 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
  }
  if (uVar7 != 4) {
LAB_14001608d:
    CdCompleteRequest(param_1,param_2,0xc000000d);
    return 0xc000000d;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffff7 | 4;
  iVar2 = *(int *)(lVar3 + 0x18);
  if (((iVar2 != 0x90000) && (iVar2 != 0x90004)) && (iVar2 != 0x90008)) {
    if (((iVar2 == 0x9000c) || (iVar2 == 0x90010)) || ((iVar2 == 0x90014 || (iVar2 == 0x90050)))) {
      CdAcquireResource((longlong)param_1,*(longlong *)(lVar9 + 200) + 0x20,'\0',1);
      goto LAB_140015f92;
    }
    if (iVar2 != 0x9005c) goto LAB_14001608d;
  }
  CdAcquireResource((longlong)param_1,*(longlong *)(lVar9 + 200) + 0x20,'\0',0);
  if (*(int *)(lVar3 + 0x18) == 0x90004) {
    if (*(longlong *)(lVar9 + 0x1d8) != 0) {
      bVar5 = FsRtlAreThereCurrentOrInProgressFileLocks();
      uVar8 = (uint)bVar5;
    }
  }
  else {
    uVar8 = *(uint *)(lVar9 + 0xa0);
  }
LAB_140015f92:
  CdVerifyFcbOperation((longlong)param_1,lVar9);
  uVar8 = FsRtlOplockFsctrl(lVar9 + 0x58,param_2,uVar8);
  pvVar4 = SystemReserved1[0xf];
  if (SystemReserved1[0xf] != *(void **)(lVar9 + 0xb8)) {
    ExAcquireFastMutex(*(longlong *)(lVar9 + 200) + 0x88);
    *(void **)(lVar9 + 0xb8) = pvVar4;
  }
  *(int *)(lVar9 + 0xc0) = *(int *)(lVar9 + 0xc0) + 1;
  uVar10 = 2;
  if ((*(int *)(*(longlong *)(lVar9 + 0x78) + 0x34) == 2) &&
     (cVar6 = FsRtlOplockIsFastIoPossible(lVar9 + 0x58), cVar6 != '\0')) {
    if ((*(longlong *)(lVar9 + 0x1d8) == 0) ||
       (*(char *)(*(longlong *)(lVar9 + 0x1d8) + 0x10) == '\0')) {
      uVar10 = 1;
    }
  }
  else {
    uVar10 = 0;
  }
  *(undefined1 *)(lVar9 + 5) = uVar10;
  piVar1 = (int *)(lVar9 + 0xc0);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined8 *)(lVar9 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(lVar9 + 200) + 0x88);
  }
  ExReleaseResourceLite(*(longlong *)(lVar9 + 200) + 0x20);
  CdCompleteRequest(param_1,0,uVar8);
  return uVar8;
}



===== CdUnlockVolume @ 1400160c4 =====

uint CdUnlockVolume(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar4 = *(uint *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 7;
  if ((uVar4 == 0) || (uVar4 != 2)) {
    uVar4 = 0xc000000d;
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18) + 0x78);
    uVar1 = lVar3 + 0x80;
    puVar6 = param_1;
    CdAcquireResource((longlong)param_1,uVar1,'\0',0);
    uVar5 = CdUnlockVolumeInternal((ulonglong)puVar6,lVar3,*(longlong *)(lVar2 + 0x30));
    uVar4 = (uint)uVar5;
    ExReleaseResourceLite(uVar1);
    if (-1 < (int)uVar4) {
      FsRtlNotifyVolumeEvent(*(undefined8 *)(lVar2 + 0x30),5);
    }
  }
  CdCompleteRequest(param_1,param_2,uVar4);
  return uVar4;
}



===== CdUserFsctl @ 14001618c =====

uint CdUserFsctl(short *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar3 = *(uint *)(lVar2 + 0x18);
  if (uVar3 < 0x90021) {
    if (uVar3 == 0x90020) {
      uVar3 = CdDismountVolume((undefined8 *)param_1,param_2);
      return uVar3;
    }
    if (((((uVar3 == 0x90000) || (uVar3 == 0x90004)) || (uVar3 == 0x90008)) ||
        ((uVar3 == 0x9000c || (uVar3 == 0x90010)))) || (uVar3 == 0x90014)) goto LAB_1400162ed;
    if (uVar3 == 0x90018) {
      uVar3 = CdLockVolume(param_1,param_2,param_3,param_4);
      return uVar3;
    }
    if (uVar3 == 0x9001c) {
      uVar3 = CdUnlockVolume((undefined8 *)param_1,param_2);
      return uVar3;
    }
LAB_140016261:
    uVar3 = 0xc0000010;
  }
  else {
    if (uVar3 == 0x90028) {
      if (((*(uint *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 7) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18), lVar2 != 0)) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x200;
        CdVerifyVcb((longlong)param_1,*(longlong *)(lVar2 + 0x78));
      }
      uVar3 = 0;
      goto LAB_140016338;
    }
    if (uVar3 == 0x9002c) {
      CdCompleteRequest((undefined8 *)param_1,param_2,0);
      return 0;
    }
    if (uVar3 == 0x90050) {
LAB_1400162ed:
      uVar3 = CdOplockRequest((undefined8 *)param_1,param_2);
      return uVar3;
    }
    if (uVar3 == 0x90054) {
      uVar3 = CdInvalidateVolumes(param_1,param_2);
      return uVar3;
    }
    if (uVar3 == 0x9005c) goto LAB_1400162ed;
    if (uVar3 == 0x90078) {
      uVar3 = 0;
      if (*(undefined4 **)(param_2 + 0x18) == (undefined4 *)0x0) {
        uVar3 = 0xc00000e8;
        goto LAB_140016338;
      }
      if (3 < *(uint *)(lVar2 + 8)) {
        **(undefined4 **)(param_2 + 0x18) = 0;
        uVar4 = *(uint *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 7;
        if ((uVar4 != 0) && (uVar4 == 2)) {
          if (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x18) + 0x78) +
                      0x34) == 2) {
            *(undefined8 *)(param_2 + 0x38) = 4;
          }
          else {
            uVar3 = 0xc000026e;
          }
          goto LAB_140016338;
        }
      }
    }
    else {
      if (uVar3 != 0x90083) goto LAB_140016261;
      uVar3 = *(uint *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 7;
      if ((uVar3 != 0) && (uVar3 == 2)) {
        puVar1 = (uint *)((*(ulonglong *)(*(longlong *)(lVar2 + 0x30) + 0x20) & 0xfffffffffffffff8)
                         + 4);
        *puVar1 = *puVar1 | 0x20;
        uVar3 = 0;
        goto LAB_140016338;
      }
    }
    uVar3 = 0xc000000d;
  }
LAB_140016338:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar3);
  return uVar3;
}



===== CdVerifyVolume @ 14001635c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CdVerifyVolume(short *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ushort uVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  char *_Src;
  uint uVar10;
  short *psVar11;
  uint uVar12;
  longlong lVar13;
  char *pcVar14;
  longlong lVar15;
  undefined1 auStackY_148 [32];
  undefined8 in_stack_fffffffffffffee0;
  uint local_100;
  int local_fc;
  uint local_f8 [2];
  longlong local_f0;
  int local_e8 [2];
  undefined1 *local_e0;
  uint local_d8;
  char *local_d0;
  undefined8 local_c8;
  char *pcStack_c0;
  undefined8 local_b8;
  ushort *puStack_b0;
  char *local_a8;
  ulonglong local_a0;
  longlong local_98;
  longlong local_90;
  uint local_88 [2];
  longlong lStack_80;
  ushort local_78 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  lVar15 = *(longlong *)(param_2 + 0xb8);
  lVar1 = *(longlong *)(lVar15 + 8);
  lVar2 = *(longlong *)(lVar15 + 0x10);
  lVar13 = lVar2 + 0x170;
  _Src = (char *)0x0;
  local_d0 = (char *)0x0;
  local_e0 = (undefined1 *)0x0;
  local_100 = 0;
  local_e8[0] = 0;
  local_f8[0] = 0;
  local_fc = *(int *)(lVar2 + 0x390);
  local_f0 = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  lStack_80 = 0;
  local_c8 = 0;
  pcStack_c0 = (char *)0x0;
  local_b8 = 0;
  puStack_b0 = (ushort *)0x0;
  *(undefined8 *)(param_1 + 0x14) = *(undefined8 *)(lVar1 + 0x10);
  cVar6 = '\x01';
  local_98 = param_2;
  local_90 = lVar13;
  ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
  local_a0 = lVar2 + 0x1f0;
  psVar11 = param_1;
  CdAcquireResource((longlong)param_1,local_a0,'\0',0);
  if (*(int *)(lVar2 + 0x1a4) - 3U < 2) {
LAB_14001648e:
    uVar7 = 0xc0000012;
  }
  else {
    uVar7 = CdPerformDevIoCtrl(psVar11,0x24800,*(undefined8 *)(lVar2 + 0x180),&local_fc,4,
                               in_stack_fffffffffffffee0,'\x01',local_88);
    if ((int)uVar7 < 0) {
      if ((*(byte *)(lVar15 + 2) & 1) != 0) goto LAB_14001648e;
    }
    else {
      if (lStack_80 != 4) {
        local_fc = 0;
      }
      if ((local_fc == 0) || (*(int *)(lVar2 + 0x390) != local_fc)) {
        local_e0 = (undefined1 *)ExAllocatePoolWithTag(0x411,0x554,0x63746443);
        uVar9 = CdProcessToc(local_e8,*(undefined8 *)(lVar2 + 0x180),local_e0,(int *)&local_100,
                             local_e8,local_f8);
        uVar7 = (uint)uVar9;
        if (uVar7 == 0) {
          if ((((*(uint *)(lVar2 + 0x380) == local_100) && (*(int *)(lVar2 + 900) == local_e8[0]))
              && (*(uint *)(lVar2 + 0x388) == local_f8[0])) &&
             (iVar8 = memcmp(local_e0,*(void **)(lVar2 + 0x378),(ulonglong)local_100), iVar8 == 0))
          {
            if ((char)*(undefined4 *)(lVar2 + 0x1a0) < '\0') goto LAB_140016765;
            _Src = (char *)ExAllocatePoolWithTag(0x610,0x1000,0x64766443);
            local_d0 = _Src;
            cVar5 = CdFindPrimaryVd((longlong)param_1,lVar13,_Src,*(uint *)(lVar2 + 0x38c),
                                    *(byte *)(lVar15 + 2) & 1,'\x01');
            if (cVar5 != '\0') {
              memmove(_Src + 0x800,_Src,0x800);
              CdFindActiveVolDescriptor((longlong)param_1,lVar13,_Src,'\x01');
              local_a8 = _Src;
              local_100 = 0;
              pcVar14 = _Src;
              uVar10 = 0x800;
              while( true ) {
                uVar12 = uVar10 - 1;
                local_d8 = uVar12;
                if (uVar10 == 0) break;
                *(char *)((longlong)local_f8 + ((ulonglong)(uVar12 & 3) - 8)) =
                     *(char *)((longlong)local_f8 + ((ulonglong)(uVar12 & 3) - 8)) + *pcVar14;
                pcVar14 = pcVar14 + 1;
                local_a8 = pcVar14;
                uVar10 = uVar12;
              }
              local_a8 = pcVar14;
              if (*(uint *)(lVar1 + 0x18) == local_100) {
                uVar10 = *(uint *)(lVar2 + 0x1a0) & 1;
                if ((*(uint *)(lVar2 + 0x1a0) & 4) == 0) {
                  pcStack_c0 = _Src + (ulonglong)uVar10 * 8 + 0x28;
                  local_c8 = CONCAT44(local_c8._4_4_,0x200020);
                  local_b8._0_4_ = CONCAT22(0x40,(ushort)local_b8);
                  puStack_b0 = local_78;
                  uVar10 = 0;
                  iVar8 = RtlOemStringToCountedUnicodeString(&local_b8,&local_c8,0);
                  if (-1 < iVar8) {
                    uVar10 = (uint)(ushort)local_b8;
                  }
                }
                else {
                  pcVar14 = _Src + 0x30;
                  if (uVar10 == 0) {
                    pcVar14 = _Src + 0x28;
                  }
                  uVar10 = 0x20;
                  CdConvertBigToLittleEndian((longlong)param_1,pcVar14,0x20,local_78);
                }
                local_f8[0] = uVar10 >> 1;
                uVar9 = (ulonglong)local_f8[0];
                while ((int)uVar9 != 0) {
                  uVar10 = local_f8[0] - 1;
                  uVar9 = (ulonglong)uVar10;
                  if ((local_78[uVar9] & 0xffdf) != 0) break;
                  local_f8[0] = uVar10;
                }
                uVar4 = (short)local_f8[0] * 2;
                if ((*(ushort *)(lVar1 + 6) == uVar4) &&
                   (iVar8 = memcmp((void *)(lVar1 + 0x20),local_78,(ulonglong)uVar4), iVar8 == 0))
                goto LAB_140016765;
              }
            }
          }
        }
        else if ((uVar7 == 0xc00000a3) || (uVar7 == 0xc0000013)) goto LAB_140016497;
        goto LAB_14001648e;
      }
LAB_140016765:
      *(undefined4 *)(lVar2 + 0x1a4) = 2;
      *(uint *)(*(longlong *)(lVar1 + 0x10) + 0x30) =
           *(uint *)(*(longlong *)(lVar1 + 0x10) + 0x30) & 0xfffffffd;
      if ((*(uint *)(lVar2 + 0x1a0) >> 8 & 1) != 0) {
        *(uint *)(lVar2 + 0x1a0) = *(uint *)(lVar2 + 0x1a0) & 0xfffffeff;
        lVar15 = *(longlong *)(*(longlong *)(lVar2 + 0x1c0) + 0x1d8);
        ObfReferenceObject(lVar15);
        goto LAB_14001649c;
      }
    }
  }
LAB_140016497:
  lVar15 = local_f0;
LAB_14001649c:
  *(int *)(lVar2 + 0x390) = local_fc;
  if (*(int *)(lVar2 + 0x1a4) == 0) {
    uVar7 = 0xc0000012;
  }
  else if ((*(int *)(lVar2 + 0x1a4) == 2) && (uVar7 == 0xc0000012)) {
    *(undefined4 *)(lVar2 + 0x1a4) = 0;
    if (*(longlong *)(lVar2 + 0x1e0) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar2 + 0x1e0),0);
      *(undefined8 *)(lVar2 + 0x1e0) = 0;
      *(undefined8 *)(lVar2 + 0x1e8) = 0;
    }
    if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x238) != 0) {
      ExAcquireResourceExclusiveLite(*(longlong *)(param_1 + 8) + 0x2a8,1);
      lVar1 = *(longlong *)(param_1 + 8);
      lVar3 = *(longlong *)(lVar1 + 0x238);
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0);
        *(undefined8 *)(lVar1 + 0x238) = 0;
      }
      ExReleaseResourceLite(*(longlong *)(param_1 + 8) + 0x2a8);
    }
    if ((*(int *)(lVar2 + 0x1a8) == 0) && (iVar8 = CdPurgeVolume(param_1,lVar13,'\0'), -1 < iVar8))
    {
      cVar6 = CdCheckForDismount((longlong)param_1,lVar13,'\0');
    }
  }
  if (local_e0 != (undefined1 *)0x0) {
    ExFreePoolWithTag(local_e0,0);
  }
  if (_Src != (char *)0x0) {
    ExFreePoolWithTag(_Src,0);
  }
  if (cVar6 != '\0') {
    ExReleaseResourceLite(local_a0);
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  if (lVar15 != 0) {
    FsRtlNotifyVolumeEvent(lVar15,6);
    ObfDereferenceObject(lVar15);
  }
  CdCompleteRequest((undefined8 *)param_1,local_98,uVar7);
  return uVar7;
}



===== CdCommonLockControl @ 140016944 =====

ulonglong CdCommonLockControl(undefined8 *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  uVar5 = *(uint *)(lVar2 + 0x20) & 7;
  if ((uVar5 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x18), uVar5 != 4)) {
    CdCompleteRequest(param_1,param_2,0xc000000d);
    return 0xc000000d;
  }
  uVar6 = FsRtlCheckOplock(lVar2 + 0x58,param_2,param_1,CdOplockComplete,0);
  if ((int)uVar6 != 0) {
    return uVar6;
  }
  CdVerifyFcbOperation((longlong)param_1,lVar2);
  if (*(longlong *)(lVar2 + 0x1d8) == 0) {
    CdCreateFileLock((longlong)param_1,lVar2,'\x01');
  }
  uVar5 = FsRtlProcessFileLock(*(undefined8 *)(lVar2 + 0x1d8),param_2,0);
  pvVar3 = SystemReserved1[0xf];
  if (SystemReserved1[0xf] != *(void **)(lVar2 + 0xb8)) {
    ExAcquireFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
    *(void **)(lVar2 + 0xb8) = pvVar3;
  }
  uVar7 = 2;
  *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + 1;
  if ((*(int *)(*(longlong *)(lVar2 + 0x78) + 0x34) == 2) &&
     (cVar4 = FsRtlOplockIsFastIoPossible(lVar2 + 0x58), cVar4 != '\0')) {
    if ((*(longlong *)(lVar2 + 0x1d8) == 0) ||
       (*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0')) {
      uVar7 = 1;
    }
  }
  else {
    uVar7 = 0;
  }
  piVar1 = (int *)(lVar2 + 0xc0);
  *piVar1 = *piVar1 + -1;
  *(undefined1 *)(lVar2 + 5) = uVar7;
  if (*piVar1 == 0) {
    *(undefined8 *)(lVar2 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
  }
  CdCompleteRequest(param_1,0,uVar5);
  return (ulonglong)uVar5;
}



===== CdFastLock @ 140016ae0 =====

ulonglong CdFastLock(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5,undefined1 param_6,undefined1 param_7,undefined4 *param_8)

{
  int *piVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  char local_28;
  
  local_28 = '\0';
  *(undefined8 *)(param_8 + 2) = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar5 = (ulonglong)*(uint *)(param_1 + 0x20) & 0xffffffffffffff07;
  if ((char)uVar5 != '\x04') {
    *param_8 = 0xc000000d;
    return CONCAT71((int7)(uVar5 >> 8),1);
  }
  uVar5 = CdVerifyFcbOperation(0,lVar2);
  if ((char)uVar5 == '\0') {
    return uVar5;
  }
  KeEnterCriticalRegion();
  cVar4 = FsRtlOplockIsFastIoPossible();
  if ((cVar4 != '\0') &&
     ((((*(longlong *)(lVar2 + 0x1d8) != 0 ||
        (cVar4 = CdCreateFileLock(0,lVar2,'\0'), cVar4 != '\0')) &&
       (local_28 = FsRtlPrivateLock(*(undefined8 *)(lVar2 + 0x1d8),param_1,param_2,param_3,param_4,
                                    param_5,param_6,param_7,param_8,0,0,0),
       pvVar3 = SystemReserved1[0xf], local_28 != '\0')) && (*(char *)(lVar2 + 5) == '\x01')))) {
    if (SystemReserved1[0xf] != *(void **)(lVar2 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
      *(void **)(lVar2 + 0xb8) = pvVar3;
    }
    *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + 1;
    uVar7 = 2;
    if ((*(int *)(*(longlong *)(lVar2 + 0x78) + 0x34) == 2) &&
       (cVar4 = FsRtlOplockIsFastIoPossible(lVar2 + 0x58), cVar4 != '\0')) {
      if ((*(longlong *)(lVar2 + 0x1d8) == 0) ||
         (*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0')) {
        uVar7 = 1;
      }
    }
    else {
      uVar7 = 0;
    }
    *(undefined1 *)(lVar2 + 5) = uVar7;
    piVar1 = (int *)(lVar2 + 0xc0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(lVar2 + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
    }
  }
  uVar6 = KeLeaveCriticalRegion();
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),local_28);
}



===== CdFastUnlockAll @ 140016cd0 =====

ulonglong CdFastUnlockAll(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  int *piVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 local_18;
  
  local_18 = 0;
  *(undefined8 *)(param_3 + 2) = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar6 = (ulonglong)*(uint *)(param_1 + 0x20) & 0xffffffffffffff07;
  if ((char)uVar6 == '\x04') {
    uVar6 = CdVerifyFcbOperation(0,lVar2);
    if ((char)uVar6 == '\0') {
      return uVar6;
    }
    if (*(longlong *)(lVar2 + 0x1d8) != 0) {
      KeEnterCriticalRegion();
      cVar4 = FsRtlOplockIsFastIoPossible();
      if ((cVar4 != '\0') &&
         ((*(longlong *)(lVar2 + 0x1d8) != 0 ||
          (cVar4 = CdCreateFileLock(0,lVar2,'\0'), cVar4 != '\0')))) {
        local_18 = 1;
        uVar5 = FsRtlFastUnlockAll(*(undefined8 *)(lVar2 + 0x1d8),param_1,param_2,0);
        *param_3 = uVar5;
        pvVar3 = SystemReserved1[0xf];
        if (SystemReserved1[0xf] != *(void **)(lVar2 + 0xb8)) {
          ExAcquireFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
          *(void **)(lVar2 + 0xb8) = pvVar3;
        }
        *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + 1;
        uVar8 = 2;
        if ((*(int *)(*(longlong *)(lVar2 + 0x78) + 0x34) == 2) &&
           (cVar4 = FsRtlOplockIsFastIoPossible(lVar2 + 0x58), cVar4 != '\0')) {
          if ((*(longlong *)(lVar2 + 0x1d8) == 0) ||
             (*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0')) {
            uVar8 = 1;
          }
        }
        else {
          uVar8 = 0;
        }
        *(undefined1 *)(lVar2 + 5) = uVar8;
        piVar1 = (int *)(lVar2 + 0xc0);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined8 *)(lVar2 + 0xb8) = 0;
          ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
        }
      }
      uVar7 = KeLeaveCriticalRegion();
      return CONCAT71((int7)((ulonglong)uVar7 >> 8),local_18);
    }
    *param_3 = 0xc000007e;
  }
  else {
    *param_3 = 0xc000000d;
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== CdFastUnlockAllByKey @ 140016e80 =====

ulonglong CdFastUnlockAllByKey
                    (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 local_18;
  
  local_18 = 0;
  *(undefined8 *)(param_4 + 2) = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar6 = (ulonglong)*(uint *)(param_1 + 0x20) & 0xffffffffffffff07;
  if ((char)uVar6 == '\x04') {
    uVar6 = CdVerifyFcbOperation(0,lVar2);
    if ((char)uVar6 == '\0') {
      return uVar6;
    }
    if (*(longlong *)(lVar2 + 0x1d8) != 0) {
      KeEnterCriticalRegion();
      cVar4 = FsRtlOplockIsFastIoPossible();
      if ((cVar4 != '\0') &&
         ((*(longlong *)(lVar2 + 0x1d8) != 0 ||
          (cVar4 = CdCreateFileLock(0,lVar2,'\0'), cVar4 != '\0')))) {
        local_18 = 1;
        uVar5 = FsRtlFastUnlockAllByKey(*(undefined8 *)(lVar2 + 0x1d8),param_1,param_2,param_3,0);
        *param_4 = uVar5;
        pvVar3 = SystemReserved1[0xf];
        if (SystemReserved1[0xf] != *(void **)(lVar2 + 0xb8)) {
          ExAcquireFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
          *(void **)(lVar2 + 0xb8) = pvVar3;
        }
        *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + 1;
        uVar8 = 2;
        if ((*(int *)(*(longlong *)(lVar2 + 0x78) + 0x34) == 2) &&
           (cVar4 = FsRtlOplockIsFastIoPossible(lVar2 + 0x58), cVar4 != '\0')) {
          if ((*(longlong *)(lVar2 + 0x1d8) == 0) ||
             (*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0')) {
            uVar8 = 1;
          }
        }
        else {
          uVar8 = 0;
        }
        *(undefined1 *)(lVar2 + 5) = uVar8;
        piVar1 = (int *)(lVar2 + 0xc0);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          *(undefined8 *)(lVar2 + 0xb8) = 0;
          ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
        }
      }
      uVar7 = KeLeaveCriticalRegion();
      return CONCAT71((int7)((ulonglong)uVar7 >> 8),local_18);
    }
    *param_4 = 0xc000007e;
  }
  else {
    *param_4 = 0xc000000d;
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== CdFastUnlockSingle @ 140017040 =====

ulonglong CdFastUnlockSingle(longlong param_1,undefined8 param_2,undefined8 param_3,
                            undefined8 param_4,undefined4 param_5,undefined4 *param_6)

{
  int *piVar1;
  longlong lVar2;
  void *pvVar3;
  char cVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 local_28;
  
  local_28 = 0;
  *(undefined8 *)(param_6 + 2) = 0;
  lVar2 = *(longlong *)(param_1 + 0x18);
  uVar6 = (ulonglong)*(uint *)(param_1 + 0x20) & 0xffffffffffffff07;
  if ((char)uVar6 == '\x04') {
    uVar6 = CdVerifyFcbOperation(0,lVar2);
    if ((char)uVar6 == '\0') {
      return uVar6;
    }
    if (*(longlong *)(lVar2 + 0x1d8) != 0) {
      KeEnterCriticalRegion();
      cVar4 = FsRtlOplockIsFastIoPossible();
      if ((cVar4 != '\0') &&
         ((*(longlong *)(lVar2 + 0x1d8) != 0 ||
          (cVar4 = CdCreateFileLock(0,lVar2,'\0'), cVar4 != '\0')))) {
        local_28 = 1;
        uVar5 = FsRtlFastUnlockSingle
                          (*(undefined8 *)(lVar2 + 0x1d8),param_1,param_2,param_3,param_4,param_5,0,
                           0);
        *param_6 = uVar5;
        pvVar3 = SystemReserved1[0xf];
        if ((*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0') &&
           (*(char *)(lVar2 + 5) != '\x01')) {
          if (SystemReserved1[0xf] != *(void **)(lVar2 + 0xb8)) {
            ExAcquireFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
            *(void **)(lVar2 + 0xb8) = pvVar3;
          }
          *(int *)(lVar2 + 0xc0) = *(int *)(lVar2 + 0xc0) + 1;
          uVar8 = 2;
          if ((*(int *)(*(longlong *)(lVar2 + 0x78) + 0x34) == 2) &&
             (cVar4 = FsRtlOplockIsFastIoPossible(lVar2 + 0x58), cVar4 != '\0')) {
            if ((*(longlong *)(lVar2 + 0x1d8) == 0) ||
               (*(char *)(*(longlong *)(lVar2 + 0x1d8) + 0x10) == '\0')) {
              uVar8 = 1;
            }
          }
          else {
            uVar8 = 0;
          }
          *(undefined1 *)(lVar2 + 5) = uVar8;
          piVar1 = (int *)(lVar2 + 0xc0);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(undefined8 *)(lVar2 + 0xb8) = 0;
            ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
          }
        }
      }
      uVar7 = KeLeaveCriticalRegion();
      return CONCAT71((int7)((ulonglong)uVar7 >> 8),local_28);
    }
    *param_6 = 0xc000007e;
  }
  else {
    *param_6 = 0xc000000d;
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== CdConvertBigToLittleEndian @ 140017230 =====

void CdConvertBigToLittleEndian(longlong param_1,undefined1 *param_2,uint param_3,void *param_4)

{
  undefined1 *puVar1;
  
  if ((param_3 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc0000032,'\0',0x120000,0xa3);
  }
  memmove(param_4,param_2 + 1,(ulonglong)(param_3 - 1));
  if (param_3 != 0) {
    puVar1 = param_2;
    do {
      puVar1[(longlong)param_4 + (1 - (longlong)param_2)] = *puVar1;
      puVar1 = puVar1 + 2;
      param_3 = param_3 - 2;
    } while (param_3 != 0);
  }
  return;
}



===== CdConvertNameToCdName @ 1400172a8 =====

void CdConvertNameToCdName(undefined8 param_1,ushort *param_2)

{
  short *psVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  uVar3 = 0;
  psVar1 = *(short **)(param_2 + 4);
  if (uVar2 != 0) {
    do {
      if (*psVar1 == 0x3b) break;
      psVar1 = psVar1 + 1;
      uVar3 = uVar3 + 2;
    } while (uVar3 < uVar2);
  }
  param_2[8] = 0;
  if ((ulonglong)uVar3 + 2 < (ulonglong)uVar2) {
    uVar2 = (uVar2 - (ushort)uVar3) - 2;
    param_2[8] = uVar2;
    *(ulonglong *)(param_2 + 0xc) = (longlong)*(short **)(param_2 + 4) + (ulonglong)uVar3 + 2;
    param_2[9] = uVar2;
  }
  *param_2 = (ushort)uVar3;
  return;
}



===== CdDissectName @ 140017314 =====

void CdDissectName(undefined8 param_1,ushort *param_2,short *param_3)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  psVar1 = *(short **)(param_2 + 4);
  if (*param_2 != 0) {
    do {
      if (*psVar1 == 0x5c) break;
      uVar3 = uVar3 + 2;
      psVar1 = psVar1 + 1;
    } while (uVar3 < *param_2);
  }
  *(short **)(param_3 + 4) = *(short **)(param_2 + 4);
  sVar2 = (short)uVar3;
  *param_3 = sVar2;
  param_3[1] = sVar2;
  if (uVar3 != *param_2) {
    param_2[1] = param_2[1] + (-2 - sVar2);
    *(ulonglong *)(param_2 + 4) = *(longlong *)(param_2 + 4) + (ulonglong)uVar3 + 2;
    uVar4 = (*param_2 - sVar2) - 2;
  }
  *param_2 = uVar4;
  return;
}



===== CdFullCompareNames @ 14001738c =====

int CdFullCompareNames(undefined8 param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  
  uVar1 = *param_2;
  uVar3 = (uint)uVar1;
  uVar2 = *param_3;
  if (uVar2 < uVar1) {
    iVar4 = 1;
    uVar3 = (uint)uVar2;
  }
  else {
    iVar4 = -1;
    if (uVar1 == uVar2) {
      iVar4 = 0;
    }
  }
  uVar5 = RtlCompareMemory(*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_3 + 4),uVar3);
  if (uVar5 < uVar3) {
    iVar4 = (-(uint)(*(ushort *)(*(longlong *)(param_2 + 4) + (uVar5 >> 1) * 2) <
                    *(ushort *)(*(longlong *)(param_3 + 4) + (uVar5 >> 1) * 2)) & 0xfffffffe) + 1;
  }
  return iVar4;
}



===== CdGenerate8dot3Name @ 140017424 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CdGenerate8dot3Name(longlong param_1,undefined8 param_2,uint param_3,short *param_4,
                        short *param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  short sVar7;
  short sVar8;
  short *_Dst;
  ushort uVar9;
  ulonglong *puVar11;
  ulonglong *puVar10;
  short *_Src;
  undefined1 auStackY_108 [32];
  undefined8 local_d0;
  undefined8 *puStack_c8;
  short *local_c0;
  short *local_b8;
  short *local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  short local_44 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b0 = param_5;
  local_60 = 0;
  puStack_c8 = &local_70;
  local_d0 = 0x180000;
  bVar1 = false;
  local_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_c0 = param_4;
  RtlGenerate8dot3Name(param_2,1,&local_98,&local_d0);
  uVar6 = (ulonglong)(param_3 >> 5);
  iVar3 = RtlUnicodeStringToOemString(&local_a8,&local_d0);
  puVar10 = &local_40;
  sVar8 = 0;
  if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,iVar3,'\0',0x120000,0x2a8);
  }
  do {
    sVar7 = sVar8;
    puVar11 = puVar10;
    puVar10 = (ulonglong *)((longlong)puVar11 + -2);
    uVar4 = (ushort)uVar6 & 0xf;
    sVar8 = 0x30;
    if (9 < uVar4) {
      sVar8 = 0x37;
    }
    uVar6 = uVar6 >> 4;
    *(ushort *)puVar10 = sVar8 + uVar4;
    sVar8 = sVar7 + 2;
  } while ((int)uVar6 != 0);
  _Src = (short *)((longlong)puVar11 + -4);
  uVar4 = sVar7 + 4;
  uVar5 = 0;
  sVar8 = 0;
  *_Src = 0x7e;
  uVar9 = 0;
  _Dst = local_c0;
  if ((ushort)local_d0 != 0) {
    bVar2 = false;
    do {
      sVar7 = *(short *)((longlong)puStack_c8 + (ulonglong)(uVar5 >> 1) * 2);
      if (sVar7 == 0x2e) break;
      if (sVar7 == 0x7e) {
        bVar1 = true;
      }
      if (((*(byte *)((ulonglong)uVar9 + lStack_a0) < 0x80) ||
          (*NlsMbOemCodePageTag_exref == (code)0x0)) ||
         (*(short *)(*(longlong *)NlsOemLeadByteInfo_exref +
                    (ulonglong)*(byte *)((ulonglong)uVar9 + lStack_a0) * 2) == 0)) {
        uVar9 = uVar9 + 1;
      }
      else {
        uVar9 = uVar9 + 2;
        if (8 < (ulonglong)(uVar4 >> 1) + (ulonglong)uVar9) {
          bVar2 = true;
        }
      }
      if (((!bVar1) && (!bVar2)) && (uVar5 < 0x10 - uVar4)) {
        sVar8 = sVar8 + 2;
        *_Dst = sVar7;
        _Dst = _Dst + 1;
      }
      uVar5 = uVar5 + 2;
    } while (uVar5 < (ushort)local_d0);
  }
  local_b8 = _Src;
  RtlFreeOemString(&local_a8);
  memmove(_Dst,_Src,(ulonglong)uVar4);
  sVar8 = sVar8 + uVar4;
  if (uVar5 != (ushort)local_d0) {
    memmove(_Dst + (uVar4 >> 1),(void *)((longlong)puStack_c8 + (ulonglong)(uVar5 >> 1) * 2),
            (ulonglong)((ushort)local_d0 - uVar5));
    sVar8 = sVar8 + ((ushort)local_d0 - (short)uVar5);
  }
  *local_b0 = sVar8;
  return;
}



===== CdIs8dot3Name @ 1400176a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CdIs8dot3Name(undefined8 param_1,uint *param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  ulonglong uVar4;
  ushort uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = *param_2;
  uStack_44 = param_2[1];
  uStack_40 = param_2[2];
  uStack_3c = param_2[3];
  puVar7 = *(ushort **)(param_2 + 2);
  bVar2 = false;
  uVar5 = (ushort)local_48;
  uVar4 = local_10;
  if (uVar5 < 0x19) {
    uVar6 = 0;
    do {
      uVar1 = *puVar7;
      uVar4 = (ulonglong)uVar1;
      if (uVar1 == 0x20) goto LAB_140017777;
      if (uVar1 == 0x2e) {
        if ((bVar2) || (0x10 < uVar6)) goto LAB_140017777;
        bVar2 = true;
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      uVar6 = uVar6 + 2;
      puVar7 = puVar7 + 1;
    } while (uVar6 < (local_48 & 0xffff));
    if (bVar3) {
      uVar6 = local_48 >> 0x10;
      local_48 = CONCAT22((short)uVar6,uVar5 - 2);
    }
    uStack_50 = local_28;
    local_58 = 0x180000;
    uVar4 = RtlUnicodeStringToCountedOemString(&local_58,&local_48,0);
    if (-1 < (int)uVar4) {
      local_38 = (undefined4)local_58;
      uStack_34 = local_58._4_4_;
      uStack_30 = (undefined4)uStack_50;
      uStack_2c = uStack_50._4_4_;
      uVar4 = FsRtlIsFatDbcsLegal(&local_38,0,0,0);
      return uVar4;
    }
  }
LAB_140017777:
  return uVar4 & 0xffffffffffffff00;
}



===== CdIsNameInExpression @ 140017794 =====

char CdIsNameInExpression
               (undefined8 param_1,ushort *param_2,ushort *param_3,uint param_4,char param_5)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = '\x01';
  if ((param_4 >> 0x10 & 1) == 0) {
    if (*param_2 != *param_3) {
      return '\0';
    }
    iVar3 = memcmp(*(void **)(param_2 + 4),*(void **)(param_3 + 4),(ulonglong)*param_2);
    if (iVar3 != 0) {
      return '\0';
    }
  }
  else {
    cVar2 = FsRtlIsNameInExpression(param_3,param_2,0,0);
    if (cVar2 == '\0') {
      return '\0';
    }
  }
  if (param_5 == '\0') {
    return cVar2;
  }
  uVar1 = param_3[8];
  if (uVar1 == 0) {
    return cVar2;
  }
  if ((param_4 >> 0x13 & 1) != 0) {
    return cVar2;
  }
  if ((param_4 >> 0x11 & 1) != 0) {
    cVar2 = FsRtlIsNameInExpression(param_3 + 8,param_2 + 8,0,0);
    return cVar2;
  }
  if ((param_2[8] == uVar1) &&
     (iVar3 = memcmp(*(void **)(param_2 + 0xc),*(void **)(param_3 + 0xc),(ulonglong)param_2[8]),
     iVar3 == 0)) {
    return cVar2;
  }
  return '\0';
}



===== CdShortNameDirentOffset @ 140017870 =====

int CdShortNameDirentOffset(undefined8 param_1,ushort *param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_2;
  puVar4 = *(ushort **)(param_2 + 4);
  bVar2 = false;
  iVar3 = -1;
  if (*param_2 != 0) {
    do {
      uVar1 = *puVar4;
      if (uVar1 == 0x2e) {
        return iVar3;
      }
      if (bVar2) {
        if ((0x16 < (ushort)(uVar1 - 0x30)) || ((ushort)(uVar1 - 0x3a) < 7)) {
          return -1;
        }
        iVar3 = (iVar3 * 0x10 - ((-(uint)(uVar1 < 0x41) & 0xfffffff9) + 0x37)) + (uint)uVar1;
      }
      else if (uVar1 == 0x7e) {
        bVar2 = true;
        iVar3 = 0;
      }
      puVar4 = puVar4 + 1;
      uVar5 = uVar5 - 2;
    } while (uVar5 != 0);
  }
  return iVar3;
}



===== CdUpcaseName @ 1400178e0 =====

void CdUpcaseName(undefined8 param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  
  if (param_2 != param_3) {
    param_3[8] = 0;
    uVar1 = param_2[8];
    if (uVar1 != 0) {
      param_3[8] = uVar1;
      param_3[9] = uVar1;
      uVar1 = *param_2;
      *(undefined2 **)(param_3 + 0xc) =
           (undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)uVar1);
      *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)uVar1) = 0x3b;
      *(longlong *)(param_3 + 0xc) = *(longlong *)(param_3 + 0xc) + 2;
    }
  }
  RtlUpcaseUnicodeString(param_3,param_2,0);
  if (param_2[8] != 0) {
    RtlUpcaseUnicodeString(param_3 + 8,param_2 + 8,0);
  }
  return;
}



===== CdFindPathEntry @ 140017974 =====

undefined8
CdFindPathEntry(longlong param_1,longlong param_2,ushort *param_3,char param_4,longlong *param_5)

{
  uint *puVar1;
  longlong *plVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  void *pvVar7;
  char cVar8;
  undefined7 extraout_var;
  ulonglong uVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined1 uVar12;
  bool bVar13;
  uint local_58;
  uint local_54;
  
  pvVar7 = SystemReserved1[0xf];
  local_54 = *(uint *)(param_2 + 0x9c);
  local_58 = *(uint *)(param_2 + 0x1f8);
  uVar12 = 0;
  bVar6 = true;
  if (0xffff < local_58) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc0000032,'\0',0x130000,0x179);
  }
  plVar2 = (longlong *)(param_2 + 0xb8);
  if (SystemReserved1[0xf] != (void *)*plVar2) {
    ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
    *plVar2 = (longlong)pvVar7;
  }
  plVar11 = (longlong *)(param_2 + 0xb8);
  piVar3 = (int *)(param_2 + 0xc0);
  iVar4 = *piVar3;
  *piVar3 = iVar4 + 1;
  if (*(uint *)(param_2 + 0x1fc) == 0) {
    if (param_2 != *(longlong *)(*(longlong *)(param_2 + 0x78) + 0x50)) goto LAB_140017a6d;
  }
  else {
    local_58 = *(uint *)(param_2 + 0x200);
    local_54 = *(uint *)(param_2 + 0x1fc);
  }
  bVar6 = false;
LAB_140017a6d:
  *piVar3 = iVar4;
  if (iVar4 == 0) {
    *plVar2 = 0;
    ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
  }
  CdLookupPathEntry(param_1,local_54,local_58,'\0',param_5);
  uVar5 = *(uint *)(param_5 + 6);
  bVar13 = uVar5 == *(uint *)(param_2 + 0x1f8);
  if (uVar5 <= *(uint *)(param_2 + 0x1f8)) {
    puVar1 = (uint *)(param_5 + 4);
    piVar3 = (int *)(param_2 + 0xc0);
    do {
      pvVar7 = SystemReserved1[0xf];
      if (bVar13) {
        if (bVar6) {
          if (SystemReserved1[0xf] != (void *)*plVar11) {
            ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
            *plVar11 = (longlong)pvVar7;
          }
          iVar4 = *piVar3;
          *piVar3 = iVar4 + 1;
          *(undefined4 *)(param_2 + 0x1fc) = *(undefined4 *)((longlong)param_5 + 0x24);
          *(uint *)(param_2 + 0x200) = *puVar1;
          *piVar3 = iVar4;
          if (iVar4 == 0) {
            *plVar11 = 0;
            ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
          }
          bVar6 = false;
        }
        lVar10 = param_1;
        CdUpdatePathEntryName(param_1,(longlong)puVar1,param_4);
        cVar8 = CdIsNameInExpression(lVar10,(ushort *)(param_5 + 0xd),param_3,0,'\0');
        uVar9 = CONCAT71(extraout_var,cVar8);
        if (cVar8 != '\0') {
          uVar12 = 1;
          goto LAB_140017c6c;
        }
      }
      local_54 = *(uint *)((longlong)param_5 + 0x24);
      local_58 = *puVar1;
      uVar9 = CdLookupNextPathEntry(param_1,param_5,(int *)puVar1);
      if ((char)uVar9 == '\0') goto LAB_140017c6c;
      uVar5 = *(uint *)(param_5 + 6);
      bVar13 = uVar5 == *(uint *)(param_2 + 0x1f8);
    } while (uVar5 <= *(uint *)(param_2 + 0x1f8));
  }
  pvVar7 = SystemReserved1[0xf];
  uVar9 = (ulonglong)uVar5;
  if (bVar6) {
    if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
      *(undefined8 *)(param_2 + 0xb8) = pvVar7;
    }
    iVar4 = *(int *)(param_2 + 0xc0);
    *(uint *)(param_2 + 0x1fc) = local_54;
    uVar9 = (ulonglong)local_58;
    *(uint *)(param_2 + 0x200) = local_58;
    *(int *)(param_2 + 0xc0) = iVar4 + 1;
    *(int *)(param_2 + 0xc0) = iVar4;
    if (iVar4 == 0) {
      *(undefined8 *)(param_2 + 0xb8) = 0;
      uVar9 = ExReleaseFastMutex(*(longlong *)(param_2 + 200) + 0x88);
    }
  }
LAB_140017c6c:
  return CONCAT71((int7)(uVar9 >> 8),uVar12);
}



===== CdLookupNextPathEntry @ 140017cac =====

ulonglong CdLookupNextPathEntry(longlong param_1,longlong *param_2,int *param_3)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  uint uVar2;
  
  uVar2 = param_3[3] + (int)param_2[3];
  *(uint *)(param_2 + 3) = uVar2;
  if (*(char *)((longlong)param_2 + 0x1d) == '\0') {
    if (0x7ff < uVar2) {
      CdMapPathTableBlock(0x800,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x58),
                          (ulonglong)((int)param_2[1] + 0x800),param_2);
      *(int *)(param_2 + 3) = (int)param_2[3] + -0x800;
    }
  }
  else if (*(uint *)((longlong)param_2 + 0xc) <= uVar2) {
    return in_RAX & 0xffffffffffffff00;
  }
  uVar1 = CdUpdatePathEntryFromRawPathEntry(param_1,*param_3 + 1,'\x01',param_2,param_3);
  return uVar1;
}



===== CdLookupPathEntry @ 140017d34 =====

void CdLookupPathEntry(longlong param_1,uint param_2,undefined4 param_3,char param_4,
                      longlong *param_5)

{
  CdMapPathTableBlock(param_1,*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x58),
                      (ulonglong)param_2 & 0xfffff800,param_5);
  *(uint *)(param_5 + 3) = param_2 - (int)param_5[1];
  CdUpdatePathEntryFromRawPathEntry(param_1,param_3,param_4,param_5,(undefined4 *)(param_5 + 4));
  return;
}



===== CdMapPathTableBlock @ 140017dbc =====

void CdMapPathTableBlock(undefined8 param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  size_t _Size;
  void *local_res8;
  longlong local_res18;
  
  local_res8 = (void *)0x0;
  uVar2 = *(int *)(param_2 + 0x20) - (int)param_3;
  uVar5 = 0x1000;
  if (uVar2 < 0x1001) {
    *(undefined1 *)((longlong)param_4 + 0x1d) = 1;
    uVar5 = uVar2;
  }
  plVar1 = param_4 + 2;
  *(int *)(param_4 + 1) = (int)param_3;
  *(uint *)((longlong)param_4 + 0xc) = uVar5;
  local_res18 = param_3;
  if (*plVar1 != 0) {
    CcUnpinData();
    *plVar1 = 0;
  }
  if ((uVar5 < 0x801) || (((uint)local_res18 & 0x3ffff) != 0x3f800)) {
    if (*(char *)((longlong)param_4 + 0x1c) != '\0') {
      if (*param_4 != 0) {
        ExFreePoolWithTag(*param_4,0);
        *param_4 = 0;
      }
      *(undefined1 *)((longlong)param_4 + 0x1c) = 0;
    }
    CcMapData(*(undefined8 *)(param_2 + 0x1d8),&local_res18,uVar5,1,plVar1,param_4);
  }
  else {
    _Size = 0x800;
    lVar3 = ExAllocatePoolWithTag(0x411,uVar5,0x70736443);
    lVar6 = 0;
    *(undefined1 *)((longlong)param_4 + 0x1c) = 1;
    *param_4 = lVar3;
    iVar4 = 2;
    do {
      CcMapData(*(undefined8 *)(param_2 + 0x1d8),&local_res18,_Size,1,plVar1,&local_res8);
      memmove((void *)(*param_4 + lVar6),local_res8,_Size);
      if (*plVar1 != 0) {
        CcUnpinData();
        *plVar1 = 0;
      }
      _Size = (size_t)(uVar5 - 0x800);
      local_res18 = local_res18 + 0x800;
      lVar6 = 0x800;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



===== CdUpdatePathEntryFromRawPathEntry @ 140017f58 =====

ulonglong CdUpdatePathEntryFromRawPathEntry
                    (longlong param_1,undefined4 param_2,char param_3,longlong *param_4,
                    undefined4 *param_5)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  ulonglong uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  
  pbVar7 = (byte *)((ulonglong)*(uint *)(param_4 + 3) + *param_4);
  uVar5 = Feature_1787009338__private_IsEnabledDeviceUsageNoInline();
  if (((((int)uVar5 == 0) || (*(char *)((longlong)param_4 + 0x1d) == '\0')) || (param_3 == '\0')) ||
     (8 < *(uint *)((longlong)param_4 + 0xc) - (int)param_4[3])) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
      bVar3 = *pbVar7;
    }
    else {
      bVar3 = pbVar7[5];
    }
    param_5[5] = (uint)bVar3;
    if (bVar3 != 0) {
      if (((*(char *)((longlong)param_4 + 0x1d) == '\0') || (param_3 == '\0')) ||
         (uVar8 = *(int *)((longlong)param_4 + 0xc) - (int)param_4[3], 0x107 < uVar8)) {
LAB_14001804a:
        *param_5 = param_2;
        param_5[1] = (int)param_4[1] + (int)param_4[3];
        pbVar6 = pbVar7;
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
          pbVar6 = pbVar7 + 2;
        }
        iVar1 = *(int *)pbVar6;
        param_5[2] = iVar1;
        lVar2 = *(longlong *)(param_1 + 0x10);
        if ((*(uint *)(lVar2 + 0x30) & 1) == 0) {
          bVar4 = pbVar7[1];
        }
        else {
          bVar4 = pbVar7[4];
        }
        param_5[2] = (uint)bVar4 + iVar1;
        *(undefined2 *)(param_5 + 4) = *(undefined2 *)(pbVar7 + 6);
        param_5[3] = bVar3 + 9 & 0xfffffffe;
        *(byte **)(param_5 + 6) = pbVar7 + 8;
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
      }
      if (8 < uVar8) {
        if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
          bVar4 = *pbVar7;
        }
        else {
          bVar4 = pbVar7[5];
        }
        if (bVar4 + 8 <= uVar8) goto LAB_14001804a;
      }
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000032,'\0',0x130000,0x305);
    }
    if ((*(char *)((longlong)param_4 + 0x1d) == '\0') ||
       (uVar5 = *(ulonglong *)(param_1 + 0x10),
       (*(uint *)((longlong)param_4 + 0xc) & *(uint *)(uVar5 + 0x1b8)) != 0)) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000032,'\0',0x130000,0x2e6);
    }
  }
  else {
    uVar5 = *(ulonglong *)(param_1 + 0x10);
    if ((*(uint *)(uVar5 + 0x1b8) & *(uint *)((longlong)param_4 + 0xc)) != 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000032,'\0',0x130000,0x2cf);
    }
  }
  return uVar5 & 0xffffffffffffff00;
}



===== CdUpdatePathEntryName @ 14001812c =====

void CdUpdatePathEntryName(longlong param_1,longlong param_2,char param_3)

{
  ushort *puVar1;
  undefined8 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint local_res10 [2];
  
  if ((**(char **)(param_2 + 0x18) == '\0') && (*(int *)(param_2 + 0x14) == 1)) {
    *(undefined2 *)(param_2 + 0x38) = 0;
    *(undefined8 *)(param_2 + 0x28) = 0x20002;
    *(undefined **)(param_2 + 0x30) = &CdUnicodeSelfArray;
    *(undefined8 *)(param_2 + 0x48) = 0x20002;
    *(undefined **)(param_2 + 0x50) = &CdUnicodeSelfArray;
    *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_2 + 0x38);
    *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_2 + 0x40);
  }
  else {
    local_res10[0] = *(uint *)(param_2 + 0x14);
    if (param_3 != '\0') {
      local_res10[0] = local_res10[0] * 2;
    }
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 4) == 0) {
      local_res10[0] = local_res10[0] * 2;
    }
    uVar5 = *(uint *)(param_2 + 0x20) & 1;
    if ((uVar5 == 0) && (uVar4 = 0x40, local_res10[0] < 0x41)) {
      *(undefined2 *)(param_2 + 0x2a) = 0x40;
      *(longlong *)(param_2 + 0x30) = param_2 + 0x68;
    }
    else {
      uVar4 = (uint)*(ushort *)(param_2 + 0x2a);
      if (*(ushort *)(param_2 + 0x2a) < local_res10[0]) {
        if (uVar5 != 0) {
          if (*(longlong *)(param_2 + 0x30) != 0) {
            ExFreePoolWithTag(*(longlong *)(param_2 + 0x30),0);
            *(undefined8 *)(param_2 + 0x30) = 0;
          }
          *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffffe;
        }
        uVar2 = ExAllocatePoolWithTag(0x411,local_res10[0],0x6e506443);
        *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 1;
        *(undefined8 *)(param_2 + 0x30) = uVar2;
        uVar4 = local_res10[0] & 0xffff;
        *(short *)(param_2 + 0x2a) = (short)local_res10[0];
      }
    }
    puVar1 = (ushort *)(param_2 + 0x28);
    if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 4) == 0) {
      RtlOemToUnicodeN(*(void **)(param_2 + 0x30),uVar4,local_res10,*(undefined1 **)(param_2 + 0x18)
                       ,*(uint *)(param_2 + 0x14));
      *puVar1 = (ushort)local_res10[0];
      uVar5 = local_res10[0];
    }
    else {
      CdConvertBigToLittleEndian
                (param_1,*(undefined1 **)(param_2 + 0x18),*(uint *)(param_2 + 0x14),
                 *(void **)(param_2 + 0x30));
      *puVar1 = *(ushort *)(param_2 + 0x14);
      uVar5 = (uint)*(ushort *)(param_2 + 0x14);
    }
    *(undefined2 *)(param_2 + 0x58) = 0;
    *(undefined2 *)(param_2 + 0x38) = 0;
    if (*(short *)(*(longlong *)(param_2 + 0x30) +
                  ((ulonglong)(uVar5 & 0xffff) - 2 & 0xfffffffffffffffe)) == 0x2e) {
      *puVar1 = (short)uVar5 - 2;
    }
    if (param_3 == '\0') {
      *(undefined8 *)(param_2 + 0x48) = *(undefined8 *)puVar1;
      *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_2 + 0x30);
      *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_2 + 0x38);
      *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_2 + 0x40);
    }
    else {
      uVar3 = *(ushort *)(param_2 + 0x2a) >> 1;
      *(ushort *)(param_2 + 0x4a) = uVar3;
      *(ulonglong *)(param_2 + 0x50) =
           (ulonglong)(*(ushort *)(param_2 + 0x2a) >> 1) + *(longlong *)(param_2 + 0x30);
      CdUpcaseName((ulonglong)uVar3,puVar1,(ushort *)(param_2 + 0x48));
    }
  }
  return;
}



===== CdCommonPnp @ 140018310 =====

uint CdCommonPnp(short *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  short *psVar7;
  uint uVar8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(lVar2 + 0x28);
  ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
  if (((*(short *)(lVar3 + 2) != 0x490) ||
      (psVar7 = (short *)(lVar3 + 0x170), psVar7 == (short *)0x0)) || (*psVar7 != 0x302)) {
    ExReleaseResourceLite(&DAT_1400083d0);
    uVar4 = 0xc000000d;
    uVar8 = 0xc000000d;
    goto LAB_140018460;
  }
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 4;
  if (*(longlong *)(lVar3 + 0x178) == 0) {
LAB_140018408:
    puVar6 = &DAT_1400083d0;
  }
  else {
    cVar1 = *(char *)(lVar2 + 1);
    if (cVar1 == '\x01') {
      uVar4 = CdPnpQueryRemove(param_1,param_2,(longlong)psVar7);
      return uVar4;
    }
    if (cVar1 == '\x02') {
      uVar4 = CdPnpRemove((undefined8 *)param_1,param_2,(longlong)psVar7);
      return uVar4;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x17') {
        uVar4 = CdPnpSurpriseRemove((undefined8 *)param_1,param_2,(longlong)psVar7);
        return uVar4;
      }
      goto LAB_140018408;
    }
    puVar6 = (undefined *)(lVar3 + 0x1f0);
    CdAcquireResource((longlong)param_1,(ulonglong)puVar6,'\0',0);
    puVar5 = &DAT_1400083d0;
    ExReleaseResourceLite();
    CdUnlockVolumeInternal((ulonglong)puVar5,(longlong)psVar7,0);
  }
  ExReleaseResourceLite(puVar6);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar4 = IofCallDriver(*(undefined8 *)(lVar3 + 0x180));
  uVar8 = 0;
  param_2 = 0;
LAB_140018460:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar8);
  return uVar4;
}



===== CdPnpQueryRemove @ 140018488 =====

uint CdPnpQueryRemove(short *param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char cVar4;
  uint uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar1 = param_3 + 0x80;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  CdAcquireResource((longlong)param_1,uVar1,'\0',0);
  lVar2 = param_3 + 0x150;
  ExAcquireFastMutex(lVar2);
  *(int *)(param_3 + 0x3c) = *(int *)(param_3 + 0x3c) + 1;
  *(undefined8 *)(param_3 + 0x188) = 0;
  ExReleaseFastMutex(lVar2);
  ExReleaseResourceLite(&DAT_1400083d0);
  uVar5 = CdLockVolumeInternal(param_1,param_3,0);
  ExReleaseResourceLite(uVar1);
  ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
  CdAcquireResource((longlong)param_1,uVar1,'\0',0);
  ExAcquireFastMutex(lVar2);
  *(int *)(param_3 + 0x3c) = *(int *)(param_3 + 0x3c) + -1;
  *(undefined8 *)(param_3 + 0x188) = 0;
  ExReleaseFastMutex(lVar2);
  if (-1 < (int)uVar5) {
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
    *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
    *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
    *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    KeInitializeEvent(&local_38,0,0);
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar2 + -0x10) = CdSyncCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_38;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar5 = IofCallDriver(*(undefined8 *)(param_3 + 0x10),param_2);
    if (uVar5 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      uVar5 = *(uint *)(param_2 + 0x30);
    }
    if (-1 < (int)uVar5) {
      cVar4 = CdCheckForDismount((longlong)param_1,param_3,'\x01');
      if (cVar4 == '\0') goto LAB_140018655;
      if (*(int *)(param_3 + 0x3c) != 0) {
        uVar5 = 0x80000011;
      }
    }
  }
  ExReleaseResourceLite(uVar1);
LAB_140018655:
  ExReleaseResourceLite(&DAT_1400083d0);
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar5);
  return uVar5;
}



===== CdPnpRemove @ 14001869c =====

uint CdPnpRemove(undefined8 *param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar5 = param_1;
  CdAcquireResource((longlong)param_1,param_3 + 0x80U,'\0',0);
  uVar4 = CdUnlockVolumeInternal((ulonglong)puVar5,param_3,0);
  if ((int)uVar4 < 0) {
    ExAcquireFastMutex(param_3 + 0x150);
    if (*(int *)(param_3 + 0x34) != 4) {
      *(undefined4 *)(param_3 + 0x34) = 3;
    }
    *(undefined8 *)(param_3 + 0x188) = 0;
    ExReleaseFastMutex(param_3 + 0x150);
  }
  puVar5 = *(undefined8 **)(param_2 + 0xb8);
  puVar5[-9] = *puVar5;
  puVar5[-8] = puVar5[1];
  puVar5[-7] = puVar5[2];
  puVar5[-6] = puVar5[3];
  *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
  *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
  *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
  *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
  puVar5[-3] = puVar5[6];
  *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = CdSyncCompletionRoutine;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar3 = IofCallDriver(*(undefined8 *)(param_3 + 0x10),param_2);
  if (uVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar3 = *(uint *)(param_2 + 0x30);
  }
  cVar2 = CdCheckForDismount((longlong)param_1,param_3,'\x01');
  if (cVar2 != '\0') {
    ExReleaseResourceLite(param_3 + 0x80U);
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  CdCompleteRequest(param_1,param_2,uVar3);
  return uVar3;
}



===== CdPnpSurpriseRemove @ 140018830 =====

uint CdPnpSurpriseRemove(undefined8 *param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  CdAcquireResource((longlong)param_1,param_3 + 0x80U,'\0',0);
  ExAcquireFastMutex(param_3 + 0x150);
  if (*(int *)(param_3 + 0x34) != 4) {
    *(undefined4 *)(param_3 + 0x34) = 3;
  }
  *(undefined8 *)(param_3 + 0x188) = 0;
  ExReleaseFastMutex(param_3 + 0x150);
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
  KeInitializeEvent(&local_28,0,0);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = CdSyncCompletionRoutine;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar4 = IofCallDriver(*(undefined8 *)(param_3 + 0x10),param_2);
  if (uVar4 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar4 = *(uint *)(param_2 + 0x30);
  }
  cVar3 = CdCheckForDismount((longlong)param_1,param_3,'\x01');
  if (cVar3 != '\0') {
    ExReleaseResourceLite(param_3 + 0x80U);
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  CdCompleteRequest(param_1,param_2,uVar4);
  return uVar4;
}



===== CdFindNameLink @ 1400189b4 =====

longlong CdFindNameLink(undefined8 param_1,longlong *param_2,ushort *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *param_2;
  while( true ) {
    while( true ) {
      if (lVar3 == 0) {
        return 0;
      }
      iVar1 = CdFullCompareNames(param_1,(ushort *)(lVar3 + 0x18),param_3);
      if (iVar1 != 1) break;
      lVar3 = *(longlong *)(lVar3 + 8);
    }
    if (iVar1 != -1) break;
    lVar3 = *(longlong *)(lVar3 + 0x10);
  }
  lVar2 = RtlSplay(lVar3);
  *param_2 = lVar2;
  return lVar3;
}



===== CdFindPrefix @ 140018a24 =====

void CdFindPrefix(longlong param_1,longlong *param_2,ushort *param_3,char param_4)

{
  short *psVar1;
  ushort uVar2;
  char cVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 local_38;
  void *pvStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_28 = *(undefined4 *)param_3;
  uStack_24 = *(undefined4 *)(param_3 + 2);
  uStack_20 = *(undefined4 *)(param_3 + 4);
  uStack_1c = *(undefined4 *)(param_3 + 6);
  local_38 = 0;
  pvStack_30 = (void *)0x0;
  lVar4 = param_1;
  uVar2 = *param_3;
  while( true ) {
    if ((uVar2 == 0) || (psVar1 = (short *)*param_2, *psVar1 != 0x304)) {
      return;
    }
    CdDissectName(lVar4,(ushort *)&local_28,(short *)&local_38);
    if (param_4 == '\0') {
      lVar4 = CdFindNameLink(lVar4,(longlong *)(psVar1 + 0x104),(ushort *)&local_38);
      plVar5 = (longlong *)(lVar4 + -0x10);
    }
    else {
      lVar4 = CdFindNameLink(lVar4,(longlong *)(psVar1 + 0x108),(ushort *)&local_38);
      plVar5 = (longlong *)(lVar4 + -0x38);
    }
    if (lVar4 == 0) break;
    if (param_4 != '\0') {
      memmove(pvStack_30,(void *)plVar5[6],(ulonglong)*(ushort *)(plVar5 + 5));
    }
    *(undefined4 *)param_3 = local_28;
    *(undefined4 *)(param_3 + 2) = uStack_24;
    *(undefined4 *)(param_3 + 4) = uStack_20;
    *(undefined4 *)(param_3 + 6) = uStack_1c;
    cVar3 = ExAcquireResourceExclusiveLite(*(longlong *)(*plVar5 + 200) + 0x20,0);
    if (cVar3 == '\0') {
      if ((*(uint *)(param_1 + 0x20) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc00000d8,'\0',0x150000,0x1bb);
      }
      ExAcquireFastMutex(*(longlong *)(param_1 + 0x10) + 0x150);
      *(void **)(*(longlong *)(param_1 + 0x10) + 0x188) = SystemReserved1[0xf];
      *(int *)(*plVar5 + 0xa4) = *(int *)(*plVar5 + 0xa4) + 1;
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x188) = 0;
      ExReleaseFastMutex(*(longlong *)(param_1 + 0x10) + 0x150);
      ExReleaseResourceLite(*(longlong *)(*param_2 + 200) + 0x20);
      CdAcquireResource(param_1,*(longlong *)(*plVar5 + 200) + 0x20,'\0',0);
      ExAcquireFastMutex(*(longlong *)(param_1 + 0x10) + 0x150);
      *(void **)(*(longlong *)(param_1 + 0x10) + 0x188) = SystemReserved1[0xf];
      *(int *)(*plVar5 + 0xa4) = *(int *)(*plVar5 + 0xa4) + -1;
      *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x188) = 0;
      lVar4 = *(longlong *)(param_1 + 0x10) + 0x150;
      ExReleaseFastMutex();
    }
    else {
      lVar4 = *(longlong *)(*param_2 + 200) + 0x20;
      ExReleaseResourceLite();
    }
    *param_2 = *plVar5;
    uVar2 = (ushort)local_28;
  }
  return;
}



===== CdInsertPrefix @ 140018c60 =====

void CdInsertPrefix(undefined8 param_1,longlong param_2,ushort *param_3,char param_4,char param_5,
                   longlong param_6)

{
  ushort uVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  void *_Dst;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  plVar3 = (longlong *)(param_2 + 0x130);
  if ((param_5 != '\0') && (plVar3 = *(longlong **)(param_2 + 0x128), plVar3 == (longlong *)0x0)) {
    plVar3 = (longlong *)ExAllocatePoolWithTag(0x401,0xa0,0x65706443);
    *(longlong **)(param_2 + 0x128) = plVar3;
    if (plVar3 == (longlong *)0x0) {
      return;
    }
  }
  uVar9 = (ulonglong)(-(uint)(param_4 != '\0') & 8);
  plVar7 = (longlong *)((ulonglong)(-(uint)(param_4 != '\0') & 0x28) + 0x10 + (longlong)plVar3);
  uVar6 = (param_4 != '\0') + 1;
  if ((*(uint *)(plVar3 + 1) & 3) == 0) {
    plVar4 = plVar3 + 0xc;
    if ((0x20 < *param_3) &&
       (plVar4 = (longlong *)ExAllocatePoolWithTag(0x401,(ulonglong)*param_3 * 2,0x6e706443),
       plVar4 == (longlong *)0x0)) {
      return;
    }
    plVar3[6] = (longlong)plVar4;
    plVar3[0xb] = (ulonglong)*param_3 + (longlong)plVar4;
    uVar1 = *param_3;
    *(ushort *)(plVar3 + 5) = uVar1;
    *(ushort *)((longlong)plVar3 + 0x2a) = uVar1;
    *(ushort *)(plVar3 + 10) = uVar1;
    *(ushort *)((longlong)plVar3 + 0x52) = uVar1;
  }
  if ((*(uint *)(plVar3 + 1) & uVar6) == 0) {
    _Dst = (void *)plVar7[4];
    memmove(_Dst,*(void **)(param_3 + 4),(ulonglong)*param_3);
    plVar7[1] = 0;
    plVar7[2] = 0;
    *plVar7 = (longlong)plVar7;
    lVar8 = *(longlong *)(uVar9 + 0x208 + param_6);
    if (lVar8 == 0) {
      *(longlong **)(uVar9 + 0x208 + param_6) = plVar7;
    }
    else {
      while (iVar2 = CdFullCompareNames(_Dst,(ushort *)(lVar8 + 0x18),(ushort *)(plVar7 + 3)),
            iVar2 != 0) {
        if (iVar2 == 1) {
          lVar5 = *(longlong *)(lVar8 + 8);
          if (lVar5 == 0) {
            *(longlong **)(lVar8 + 8) = plVar7;
LAB_140018dc3:
            *plVar7 = lVar8;
            break;
          }
        }
        else {
          lVar5 = *(longlong *)(lVar8 + 0x10);
          if (lVar5 == 0) {
            *(longlong **)(lVar8 + 0x10) = plVar7;
            goto LAB_140018dc3;
          }
        }
        lVar8 = lVar5;
      }
    }
    *(uint *)(plVar3 + 1) = *(uint *)(plVar3 + 1) | uVar6;
    *plVar3 = param_2;
  }
  return;
}



===== CdCommonRead @ 140018df4 =====

uint CdCommonRead(short *param_1,longlong param_2)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  uint local_res18;
  code *in_stack_ffffffffffffff38;
  ulonglong local_a8;
  longlong local_a0;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  longlong local_88;
  longlong local_80;
  code *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 uStack_48;
  
  uVar5 = 0;
  local_80 = *(longlong *)(param_2 + 0xb8);
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (*(int *)(local_80 + 8) == 0) {
    CdCompleteRequest((undefined8 *)param_1,param_2,0);
    return 0;
  }
  lVar7 = *(longlong *)(local_80 + 0x30);
  uVar13 = *(uint *)(lVar7 + 0x20) & 7;
  if (uVar13 == 0) {
    local_78 = (code *)0x0;
  }
  else {
    pcVar2 = *(code **)(lVar7 + 0x18);
    uVar12 = *(ulonglong *)(lVar7 + 0x20) & 0xfffffffffffffff8;
    local_78 = pcVar2;
    if (uVar13 != 3) {
      uVar9 = *(uint *)(param_1 + 0x10) & 4;
      uVar10 = *(uint *)(param_2 + 0x10) & 2;
      local_90 = *(uint *)(lVar7 + 0x50) & 2;
      local_a8 = *(ulonglong *)(local_80 + 0x18);
      local_94 = *(uint *)(local_80 + 8);
      uVar11 = (ulonglong)local_94;
      local_a0 = local_a8 + uVar11;
      local_98 = 1;
      if (uVar13 != 2) {
        local_98 = *(uint *)(param_2 + 0x10) & 1;
      }
      local_8c = local_94;
      local_88 = local_a0;
      CdAcquireResource((longlong)param_1,*(ulonglong *)(pcVar2 + 8),'\0',(uVar10 != 0) + 1);
      bVar3 = true;
      if (((uVar13 != 2) || (uVar12 == 0)) || ((*(uint *)(uVar12 + 4) & 0x10) == 0)) {
        CdVerifyFcbOperation((longlong)param_1,(longlong)pcVar2);
      }
      if (((uVar9 == 0) && (local_98 != 0)) && ((*(uint *)(pcVar2 + 0xac) & 0x1c) != 0)) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 8;
LAB_140018f53:
        uVar5 = 0xc00000d8;
      }
      else if (uVar13 == 4) {
        in_stack_ffffffffffffff38 = CdPrePostIrp;
        uVar5 = FsRtlCheckOplock(pcVar2 + 0x58,param_2,param_1,CdOplockComplete,CdPrePostIrp);
        if (uVar5 == 0) {
          if (((uVar10 != 0) || (*(longlong *)(pcVar2 + 0x1d8) == 0)) ||
             (cVar4 = FsRtlCheckLockForReadAccess(*(longlong *)(pcVar2 + 0x1d8),param_2),
             cVar4 != '\0')) goto LAB_140018fd7;
          uVar5 = 0xc0000054;
        }
        else {
          param_2 = 0;
          param_1 = (short *)0x0;
        }
      }
      else {
LAB_140018fd7:
        lVar7 = local_80;
        if ((uVar13 != 2) || ((*(uint *)(uVar12 + 4) & 0x20) == 0)) {
          lVar8 = *(longlong *)(pcVar2 + 0x20);
          if (lVar8 <= (longlong)local_a8) {
            uVar5 = 0xc0000011;
            goto LAB_1400193d1;
          }
          if (lVar8 < local_a0) {
            local_94 = *(int *)(pcVar2 + 0x20) - (uint)local_a8;
            uVar11 = (ulonglong)local_94;
            local_a0 = lVar8;
            local_88 = lVar8;
          }
        }
        lVar8 = local_a0;
        uVar13 = (uint)uVar11;
        if (local_98 == 0) {
          if (*(longlong *)(*(longlong *)(local_80 + 0x30) + 0x30) == 0) {
            in_stack_ffffffffffffff38 = pcVar2;
            CcInitializeCacheMap
                      (*(longlong *)(local_80 + 0x30),pcVar2 + 0x18,0,&DAT_140008438,pcVar2);
            CcSetReadAheadGranularity(*(undefined8 *)(lVar7 + 0x30),0x10000);
          }
          if ((*(byte *)((longlong)param_1 + 0x41) & 2) == 0) {
            lVar8 = *(longlong *)(*(longlong *)(param_1 + 4) + 8);
            if (lVar8 == 0) {
              lVar8 = *(longlong *)(*(longlong *)(param_1 + 4) + 0x70);
            }
            else if ((*(byte *)(lVar8 + 10) & 5) == 0) {
              lVar8 = MmMapLockedPagesSpecifyCache
                                (lVar8,0,1,0,
                                 (ulonglong)in_stack_ffffffffffffff38 & 0xffffffff00000000,
                                 0x40000010);
            }
            else {
              lVar8 = *(longlong *)(lVar8 + 0x18);
            }
            if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
              CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0x160000,0x1ee);
            }
            cVar4 = CcCopyRead(*(undefined8 *)(lVar7 + 0x30),&local_a8,uVar11,uVar9 != 0,lVar8,
                               (int *)(param_2 + 0x30));
            if (cVar4 == '\0') goto LAB_140018f53;
            iVar1 = *(int *)(param_2 + 0x30);
            if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
              CdRaiseStatusEx((longlong)param_1,iVar1,'\x01',0x160000,0x204);
            }
          }
          else {
            CcMdlRead(*(undefined8 *)(lVar7 + 0x30),&local_a8,uVar11,param_2 + 8,
                      (uint *)(param_2 + 0x30));
            uVar5 = *(uint *)(param_2 + 0x30);
          }
          if (((local_90 != 0) && (uVar10 == 0)) && (-1 < (int)uVar5)) {
            *(longlong *)(*(longlong *)(lVar7 + 0x30) + 0x68) = local_a0;
          }
        }
        else {
          local_res18 = *(int *)(*(longlong *)(pcVar2 + 0x78) + 0x1b8) + uVar13 &
                        *(uint *)(*(longlong *)(pcVar2 + 0x78) + 0x1bc);
          if (((((uint)local_a8 | local_res18) & 0x7ff) != 0) || (local_8c < local_res18)) {
            if (uVar9 == 0) {
                    /* WARNING: Subroutine does not return */
              CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0x160000,0x13e);
            }
            local_res18 = uVar13;
          }
          puVar6 = *(undefined8 **)(param_1 + 0x18);
          if ((puVar6 == (undefined8 *)0x0) || ((*(uint *)(param_1 + 0x10) & 0x100) == 0)) {
            if (uVar9 == 0) {
              puVar6 = (undefined8 *)ExAllocatePoolWithTag(0x610,0x30,0x6f696443);
              *(undefined8 **)(param_1 + 0x18) = puVar6;
              *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100;
            }
            else {
              *(undefined8 **)(param_1 + 0x18) = &local_70;
              *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffeff;
              puVar6 = &local_70;
            }
          }
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          puVar6[3] = 0;
          puVar6[4] = 0;
          puVar6[5] = 0;
          *(byte *)(*(longlong *)(param_1 + 0x18) + 0x14) =
               (byte)((uint)*(undefined4 *)(param_1 + 0x10) >> 8) & 1;
          if (uVar9 == 0) {
            *(void **)(*(longlong *)(param_1 + 0x18) + 0x20) = SystemReserved1[0xf];
            *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x18) = *(undefined8 *)(pcVar2 + 8);
            *(uint *)(*(longlong *)(param_1 + 0x18) + 0x28) = local_94;
            local_a0 = local_88;
            lVar8 = local_88;
            uVar13 = local_94;
          }
          else {
            KeInitializeEvent(*(longlong *)(param_1 + 0x18) + 0x18,0,0);
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res18;
          if ((*(uint *)(pcVar2 + 0xac) & 0x1c) == 0) {
            uVar5 = CdNonCachedRead(param_1,(short *)pcVar2,local_a8,local_res18);
          }
          else {
            uVar5 = CdNonCachedXARead(param_1,(longlong)pcVar2,local_a8,(ulonglong)local_res18);
          }
          if (uVar5 == 0x103) {
            param_2 = 0;
            bVar3 = false;
          }
          else {
            if ((int)uVar5 < 0) {
              *(undefined8 *)(param_2 + 0x38) = 0;
              if ((((uVar5 + 0x3fffff5e < 2) || (uVar5 == 0xc00000b5)) || (uVar5 + 0x3fffffee < 3))
                 || (uVar5 == 0x80000016)) {
                    /* WARNING: Subroutine does not return */
                CdRaiseStatusEx((longlong)param_1,uVar5,'\0',0x160000,0x1ab);
              }
              uVar5 = FsRtlNormalizeNtstatus(uVar5,0xc00000e9);
            }
            else if (local_res18 != uVar13) {
              lVar7 = *(longlong *)(*(longlong *)(param_1 + 4) + 8);
              if (lVar7 == 0) {
                lVar7 = *(longlong *)(*(longlong *)(param_1 + 4) + 0x70);
              }
              else if ((*(byte *)(lVar7 + 10) & 5) == 0) {
                lVar7 = MmMapLockedPagesSpecifyCache();
              }
              else {
                lVar7 = *(longlong *)(lVar7 + 0x18);
              }
              if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0x160000,0x1b6);
              }
              memset((void *)(lVar7 + (ulonglong)uVar13),0,(ulonglong)(local_res18 - uVar13));
              *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar13;
              lVar8 = local_a0;
            }
            if (((local_90 != 0) && (uVar10 == 0)) && (-1 < (int)uVar5)) {
              *(longlong *)(*(longlong *)(local_80 + 0x30) + 0x68) = lVar8;
            }
          }
        }
      }
LAB_1400193d1:
      if (bVar3) {
        ExReleaseResourceLite(*(undefined8 *)(pcVar2 + 8));
      }
      if (uVar5 == 0xc00000d8) {
        CdPrePostIrp(param_1,param_2);
        CdAddToWorkque((longlong)param_1,param_2);
        return 0x103;
      }
      goto LAB_140019412;
    }
  }
  uVar5 = 0xc0000010;
LAB_140019412:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar5);
  return uVar5;
}



===== CdAcquireForCache @ 1400194f0 =====

void CdAcquireForCache(longlong param_1,undefined1 param_2)

{
  IoSetTopLevelIrp(2);
  ExAcquireResourceSharedLite(*(undefined8 *)(param_1 + 8),param_2);
  return;
}



===== CdAcquireResource @ 140019534 =====

ulonglong CdAcquireResource(longlong param_1,ulonglong param_2,char param_3,int param_4)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  uVar1 = param_2 & 0xffffffffffffff00;
  if (param_3 == '\0') {
    in_RAX = 0;
    uVar1 = 0;
    if ((*(byte *)(param_1 + 0x20) & 4) != 0) {
      uVar1 = 1;
    }
  }
  if (param_4 == 0) {
    uVar1 = ExAcquireResourceExclusiveLite(param_2,uVar1);
  }
  else if (param_4 == 1) {
    uVar1 = ExAcquireResourceSharedLite(param_2);
  }
  else {
    if (param_4 != 2) {
      uVar1 = in_RAX & 0xffffffffffffff00;
      goto LAB_1400195a7;
    }
    uVar1 = ExAcquireSharedStarveExclusive(param_2);
  }
  if ((char)uVar1 != '\0') {
    return uVar1;
  }
LAB_1400195a7:
  if (param_3 == '\0') {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc00000d8,'\0',0x180000,0x86);
  }
  return uVar1;
}



===== CdFilterCallbackAcquireForCreateSection @ 1400195e0 =====

undefined8 CdFilterCallbackAcquireForCreateSection(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  ExAcquireResourceExclusiveLite(*(longlong *)(*(longlong *)(lVar1 + 0x18) + 200) + 0x20,1);
  ExAcquireSharedStarveExclusive(*(undefined8 *)(*(longlong *)(lVar1 + 0x18) + 8),1);
  uVar2 = 0x126;
  if (*(int *)(param_1 + 0x18) == 1) {
    uVar2 = 0x12a;
  }
  return uVar2;
}



===== CdNoopAcquire @ 140019650 =====

undefined1 CdNoopAcquire(void)

{
  return 1;
}



===== CdNoopRelease @ 140019660 =====

void CdNoopRelease(void)

{
  return;
}



===== CdReleaseForCreateSection @ 140019670 =====

void CdReleaseForCreateSection(longlong param_1)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_1 + 0x18) + 200) + 0x20);
  ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  return;
}



===== CdReleaseFromCache @ 1400196c0 =====

void CdReleaseFromCache(longlong param_1)

{
  IoSetTopLevelIrp(0);
  ExReleaseResourceLite(*(undefined8 *)(param_1 + 8));
  return;
}



===== CdAllocateFcbTable @ 140019700 =====

void CdAllocateFcbTable(undefined8 param_1,undefined4 param_2)

{
  ExAllocatePoolWithTag(0x411,param_2,0x74666443);
  return;
}



===== CdCleanupIrpContext @ 14001972c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdCleanupIrpContext(undefined8 *param_1,char param_2)

{
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
      *(undefined4 *)param_1[9] = 0;
      IoSetTopLevelIrp(*(undefined8 *)(param_1[9] + 8));
      param_1[9] = 0;
    }
    if (((*(uint *)(param_1 + 4) & 0x100) != 0) && (param_1[6] != 0)) {
      ExFreePoolWithTag(param_1[6],0);
      param_1[6] = 0;
    }
    if ((*(uint *)(param_1 + 4) & 1) == 0) {
      if (DAT_140008340 < DAT_140008344) {
        ExAcquireFastMutex(&DAT_140008398);
        *param_1 = DAT_140008348;
        DAT_140008340 = DAT_140008340 + 1;
        _DAT_140008390 = 0;
        DAT_140008348 = param_1;
        ExReleaseFastMutex(&DAT_140008398);
      }
      else {
        ExFreePoolWithTag(param_1,0);
      }
    }
  }
  else if (param_2 == '\0') {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffd7d;
  }
  else {
    if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
      *(undefined4 *)param_1[9] = 0;
      IoSetTopLevelIrp(*(undefined8 *)(param_1[9] + 8));
      param_1[9] = 0;
    }
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffd01;
  }
  return;
}



===== CdCreateFcb @ 140019844 =====

ushort * CdCreateFcb(longlong param_1,undefined8 param_2,ushort param_3,ushort **param_4)

{
  ushort *puVar1;
  longlong lVar2;
  uint uVar3;
  ushort *_Dst;
  undefined4 *puVar4;
  ulonglong uVar5;
  ushort **ppuVar6;
  ushort *local_res8;
  ushort *local_res20;
  
  uVar3 = (uint)param_3;
  ppuVar6 = &local_res8;
  if (param_4 != (ushort **)0x0) {
    ppuVar6 = param_4;
  }
  _Dst = (ushort *)CdLookupFcbTable(param_1,*(longlong *)(param_1 + 0x10),param_2);
  if (_Dst == (ushort *)0x0) {
    if ((uVar3 == 0x303) || (uVar3 == 0x304)) {
      _Dst = (ushort *)ExAllocatePoolWithTag(0x411,0x218,0x69666443);
      local_res20 = _Dst;
      memset(_Dst,0,0x218);
      puVar1 = _Dst + 0xf4;
      _Dst[1] = 0x218;
      *(ushort **)(_Dst + 0xf8) = puVar1;
      *(ushort **)puVar1 = puVar1;
    }
    else {
      if (uVar3 != 0x305) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x26,0x190439,0,0,0);
      }
      _Dst = (ushort *)ExAllocatePoolWithTag(0x411,0x1e0,0x64666443);
      local_res20 = _Dst;
      memset(_Dst,0,0x1e0);
      _Dst[1] = 0x1e0;
    }
    *_Dst = param_3;
    *(undefined8 *)(_Dst + 0x3c) = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(_Dst + 0x4c) = param_2;
    _Dst[0x8c] = 1;
    _Dst[0x8d] = 0;
    _Dst[0x8e] = 0;
    _Dst[0x8f] = 0;
    *(ushort **)(_Dst + 0x90) = _Dst + 0x78;
    local_res8 = _Dst;
    puVar4 = (undefined4 *)ExAllocatePoolWithTag(0x600);
    if (puVar4 != (undefined4 *)0x0) {
      memset(puVar4 + 1,0,0xf4);
      *puVar4 = 0xf80306;
      ExInitializeResourceLite(puVar4 + 8);
      puVar4[0x22] = 1;
      *(undefined8 *)(puVar4 + 0x24) = 0;
      puVar4[0x26] = 0;
      KeInitializeEvent(puVar4 + 0x28,1);
    }
    *(undefined4 **)(_Dst + 100) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      CdFreePool((longlong *)&local_res20);
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc000009a,'\0',0x190000,0x455);
    }
    *(undefined1 *)ppuVar6 = 0;
    lVar2 = *(longlong *)(_Dst + 100);
    *(undefined4 *)(lVar2 + 0xc0) = 1;
    *(undefined8 *)(lVar2 + 200) = 0;
    *(undefined4 *)(lVar2 + 0xd0) = 0;
    KeInitializeEvent(lVar2 + 0xd8,1,0);
    *(byte *)(_Dst + 2) = (byte)_Dst[2] | 0x40;
    *(byte *)(_Dst + 3) = (byte)_Dst[3] | 2;
    *(byte *)((longlong)_Dst + 7) = *(byte *)((longlong)_Dst + 7) & 0xf | 0x50;
    puVar1 = _Dst + 0x1c;
    *(ushort **)(_Dst + 0x20) = puVar1;
    *(ushort **)puVar1 = puVar1;
    if (*(longlong *)(_Dst + 100) + 0xc0 != 0) {
      *(longlong *)(_Dst + 0x18) = *(longlong *)(_Dst + 100) + 0xc0;
    }
    _Dst[0x24] = 0;
    _Dst[0x25] = 0;
    _Dst[0x26] = 0;
    _Dst[0x27] = 0;
    _Dst[0x28] = 0;
    _Dst[0x29] = 0;
    _Dst[0x2a] = 0;
    _Dst[0x2b] = 0;
    _Dst[0x2c] = 0;
    _Dst[0x2d] = 0;
    _Dst[0x2e] = 0;
    _Dst[0x2f] = 0;
    _Dst[0x30] = 0;
    _Dst[0x31] = 0;
    _Dst[0x32] = 0;
    _Dst[0x33] = 0;
    _Dst[0x34] = 0;
    _Dst[0x35] = 0;
    _Dst[0x38] = 0;
    _Dst[0x39] = 0;
    _Dst[0x3a] = 0;
    _Dst[0x3b] = 0;
    if (param_3 == 0x305) {
      FsRtlInitializeOplock();
    }
  }
  else {
    uVar5 = Feature_2054323513__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 != 0) && ((int)(short)*_Dst != uVar3)) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000032,'\0',0x190000,0x475);
    }
    *(undefined1 *)ppuVar6 = 1;
  }
  return _Dst;
}



===== CdCreateFileLock @ 140019b1c =====

undefined1 CdCreateFileLock(longlong param_1,longlong param_2,char param_3)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 uVar6;
  
  pvVar4 = SystemReserved1[0xf];
  plVar1 = (longlong *)(param_2 + 200);
  uVar6 = 1;
  if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
    ExAcquireFastMutex(*plVar1 + 0x88);
    *(void **)(param_2 + 0xb8) = pvVar4;
  }
  iVar3 = *(int *)(param_2 + 0xc0);
  *(int *)(param_2 + 0xc0) = iVar3 + 1;
  if (*(longlong *)(param_2 + 0x1d8) == 0) {
    lVar5 = FsRtlAllocateFileLock(0,0);
    piVar2 = (int *)(param_2 + 0xc0);
    *piVar2 = *piVar2 + -1;
    *(longlong *)(param_2 + 0x1d8) = lVar5;
    if (*piVar2 == 0) {
      *(undefined8 *)(param_2 + 0xb8) = 0;
      ExReleaseFastMutex(*plVar1 + 0x88);
    }
    if (lVar5 == 0) {
      if (param_3 != '\0') {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc000009a,'\0',0x190000,0x62b);
      }
      uVar6 = 0;
    }
  }
  else {
    *(int *)(param_2 + 0xc0) = iVar3;
    if (iVar3 == 0) {
      *(undefined8 *)(param_2 + 0xb8) = 0;
      ExReleaseFastMutex(*plVar1 + 0x88);
    }
  }
  return uVar6;
}



===== CdCreateIrpContext @ 140019c50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * CdCreateIrpContext(longlong param_1,char param_2)

{
  byte *pbVar1;
  undefined8 *_Dst;
  
  pbVar1 = *(byte **)(param_1 + 0xb8);
  if (((*(longlong *)(pbVar1 + 0x28) == DAT_140008350) && (*(longlong *)(pbVar1 + 0x30) != 0)) &&
     (((*pbVar1 & 0xed) != 0 || (*pbVar1 == 0x10)))) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc0000010);
  }
  if (DAT_140008340 != 0) {
    ExAcquireFastMutex(&DAT_140008398);
    _Dst = DAT_140008348;
    if (DAT_140008348 != (undefined8 *)0x0) {
      DAT_140008348 = (undefined8 *)*DAT_140008348;
      DAT_140008340 = DAT_140008340 + -1;
    }
    _DAT_140008390 = 0;
    ExReleaseFastMutex(&DAT_140008398);
    if (_Dst != (undefined8 *)0x0) goto LAB_140019d33;
  }
  _Dst = (undefined8 *)ExAllocatePoolWithTag(0x210,0x70,0x63696443);
LAB_140019d33:
  memset(_Dst,0,0x70);
  *(undefined4 *)_Dst = 0x700308;
  _Dst[1] = param_1;
  if (*(longlong *)(pbVar1 + 0x30) != 0) {
    _Dst[5] = *(undefined8 *)(*(longlong *)(pbVar1 + 0x30) + 8);
  }
  if (*(longlong *)(pbVar1 + 0x28) != DAT_140008350) {
    _Dst[2] = *(longlong *)(pbVar1 + 0x28) + 0x170;
  }
  *(byte *)(_Dst + 8) = *pbVar1;
  *(byte *)((longlong)_Dst + 0x41) = pbVar1[1];
  *(uint *)(_Dst + 4) = *(uint *)(_Dst + 4) | (-(uint)(param_2 != '\0') & 0xfffffffc) + 8;
  return _Dst;
}



===== CdDeallocateFcbTable @ 140019db0 =====

void CdDeallocateFcbTable(undefined8 param_1,longlong param_2)

{
  if (param_2 != 0) {
    ExFreePoolWithTag(param_2,0);
  }
  return;
}



===== CdDeleteVcb @ 140019ddc =====

void CdDeleteVcb(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  if (*(longlong *)(param_2 + 0x230) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x230),0);
    *(undefined8 *)(param_2 + 0x230) = 0;
  }
  if (*(longlong *)(param_2 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 8),0);
    *(undefined8 *)(param_2 + 8) = 0;
  }
  if (*(longlong *)(param_2 + 0x10) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
    *(undefined8 *)(param_2 + 0x70) = 0;
  }
  if (*(longlong *)(param_2 + 0x238) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x238),0);
    *(undefined8 *)(param_2 + 0x238) = 0;
  }
  if (*(longlong *)(param_2 + 0x288) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_2 + 0x288) = 0;
    ExDeleteResourceLite(param_2 + 0x2a8);
  }
  plVar1 = (longlong *)(param_2 + 0x20);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_2 + 0x28), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  ExDeleteResourceLite(param_2 + 0x80);
  ExDeleteResourceLite(param_2 + 0xe8);
  if (*(longlong *)(param_2 + 0x208) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x208),0);
    *(undefined8 *)(param_2 + 0x208) = 0;
  }
  if (*(longlong *)(param_2 + 400) != 0) {
    FsRtlNotifyUninitializeSync();
  }
  IoDeleteDevice(param_2 + -0x170);
  return;
}



===== CdFcbTableCompare @ 140019f60 =====

char CdFcbTableCompare(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  if (*param_2 < *param_3) {
    return '\0';
  }
  return (*param_2 <= *param_3) + '\x01';
}



===== CdInitializeFcbFromFileContext @ 140019f84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CdInitializeFcbFromFileContext
               (longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  code *pcVar4;
  void *pvVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined1 *puVar11;
  longlong lVar12;
  uint uVar13;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  short local_50;
  short sStack_4e;
  short sStack_4c;
  short sStack_4a;
  undefined8 uStack_48;
  ulonglong local_40;
  
  pvVar5 = SystemReserved1[0xf];
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar12 = *(longlong *)(param_4 + 8);
  if (SystemReserved1[0xf] != *(void **)(param_2 + 0xb8)) {
    ExAcquireFastMutex(*(longlong *)(param_2 + 200) + 0x88);
    *(void **)(param_2 + 0xb8) = pvVar5;
  }
  *(int *)(param_2 + 0xc0) = *(int *)(param_2 + 0xc0) + 1;
  *(longlong *)(param_2 + 8) = *(longlong *)(param_1 + 0x10) + 0xe8;
  uVar7 = *(undefined8 *)(param_4 + 0x20);
  *(undefined8 *)(param_2 + 0x28) = uVar7;
  *(undefined8 *)(param_2 + 0x20) = uVar7;
  *(ulonglong *)(param_2 + 0x18) =
       (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x78) + 0x1b8) + *(longlong *)(param_4 + 0x20) &
       (longlong)*(int *)(*(longlong *)(param_2 + 0x78) + 0x1bc);
  uVar13 = *(uint *)(param_2 + 0xb0);
  *(uint *)(param_2 + 0xb0) = uVar13 | 1;
  if ((*(byte *)(lVar12 + 0x38) & 1) != 0) {
    *(uint *)(param_2 + 0xb0) = uVar13 | 3;
  }
  pcVar3 = *(char **)(lVar12 + 0x30);
  _local_50 = CONCAT26((short)pcVar3[3],
                       CONCAT24((short)pcVar3[2],CONCAT22((short)pcVar3[1],*pcVar3 + 0x76c)));
  uVar13 = 0;
  uStack_48 = (ulonglong)CONCAT22((short)pcVar3[5],(short)pcVar3[4]);
  plVar9 = (longlong *)(param_2 + 0x1d0);
  RtlTimeFieldsToTime(&local_50,plVar9);
  puVar11 = auStackY_a8;
  if ((*(uint *)(*(longlong *)(param_1 + 0x10) + 0x30) & 1) == 0) {
    cVar2 = *(char *)(*(longlong *)(lVar12 + 0x30) + 6);
    if ((cVar2 != '\0') && ((byte)(cVar2 + 0x30U) < 0x65)) {
      *plVar9 = *plVar9 + (longlong)-(int)cVar2 * 9000000000;
    }
  }
  if (*(int *)(lVar12 + 0x98) != 0) {
    if (*(int *)(lVar12 + 0x98) == 1) {
      uVar6 = *(uint *)(param_2 + 0xac) | 4;
    }
    else {
      uVar6 = *(uint *)(param_2 + 0xac) | 0x10;
    }
    *(uint *)(param_2 + 0xac) = uVar6;
    *(undefined2 *)(param_2 + 0xb4) = *(undefined2 *)(lVar12 + 0x48);
    *(undefined1 *)(param_2 + 0xb6) = *(undefined1 *)(lVar12 + 0x4a);
  }
  plVar9 = *(longlong **)(param_4 + 8);
  lVar12 = 0;
  while( true ) {
    CdAddAllocationFromDirent(param_1,param_2,uVar13,lVar12,(longlong)(plVar9 + 4));
    if (-1 < (char)plVar9[7]) {
      *(uint *)(param_2 + 0xac) = *(uint *)(param_2 + 0xac) | 1;
      *(longlong *)(param_2 + 0x80) = param_3;
      plVar9 = (longlong *)(param_2 + 0x88);
      lVar12 = param_3 + 0x1e8;
      plVar8 = *(longlong **)(param_3 + 0x1f0);
      if (*plVar8 != lVar12) {
        plVar8 = (longlong *)0x3;
        pcVar4 = (code *)swi(0x29);
        lVar12 = (*pcVar4)();
        puVar11 = auStackY_a0;
      }
      *plVar9 = lVar12;
      plVar9[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar9;
      *(longlong **)(lVar12 + 8) = plVar9;
      *(int *)(param_3 + 0xa4) = *(int *)(param_3 + 0xa4) + 1;
      *(int *)(param_3 + 0xa8) = *(int *)(param_3 + 0xa8) + 1;
      *(int *)(*(longlong *)(param_3 + 0x78) + 0x3c) =
           *(int *)(*(longlong *)(param_3 + 0x78) + 0x3c) + 1;
      *(int *)(*(longlong *)(param_3 + 0x78) + 0x40) =
           *(int *)(*(longlong *)(param_3 + 0x78) + 0x40) + 1;
      *(undefined8 *)(puVar11 + 0x48) = 0;
      *(undefined8 *)(puVar11 + 0x50) = 0;
      *(longlong *)(puVar11 + 0x50) = param_2;
      *(undefined8 *)(puVar11 + 0x48) = *(undefined8 *)(param_2 + 0x98);
      lVar12 = *(longlong *)(param_2 + 0x78);
      *(undefined8 *)(puVar11 + -8) = 0x14001a20d;
      RtlInsertElementGenericTable(lVar12 + 0x1c0,puVar11 + 0x48,0x10);
      *(uint *)(param_2 + 0xac) = *(uint *)(param_2 + 0xac) | 2;
      piVar1 = (int *)(param_2 + 0xc0);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined8 *)(param_2 + 0xb8) = 0;
        lVar12 = *(longlong *)(param_2 + 200);
        *(undefined8 *)(puVar11 + -8) = 0x14001a23f;
        ExReleaseFastMutex(lVar12 + 0x88);
      }
      *(undefined8 *)(puVar11 + -8) = 0x14001a251;
      return;
    }
    lVar12 = lVar12 + (ulonglong)*(uint *)((longlong)plVar9 + 0x2c);
    uVar13 = uVar13 + 1;
    lVar10 = param_3;
    uVar7 = CdLookupNextDirent(param_1,param_3,(longlong)plVar9,*(longlong **)(param_4 + 0x10));
    if ((char)uVar7 == '\0') break;
    plVar9 = *(longlong **)(param_4 + 0x10);
    CdUpdateDirentFromRawDirent(param_1,lVar10,plVar9,(int *)(plVar9 + 4));
  }
                    /* WARNING: Subroutine does not return */
  CdRaiseStatusEx(param_1,0xc0000102,'\0',0x190000,0x566);
}



===== CdInitializeFcbFromPathEntry @ 14001a2c8 =====

void CdInitializeFcbFromPathEntry
               (undefined8 param_1,longlong param_2,longlong param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  puVar8 = auStack_38;
  lVar6 = *(longlong *)(param_2 + 0x78);
  plVar5 = *(longlong **)(param_2 + 0x120);
  *(uint *)(param_2 + 0x1e0) =
       (*(int *)(lVar6 + 0x1b4) - 1U & param_4[2]) << ((byte)*(undefined4 *)(lVar6 + 0x1b0) & 0x1f);
  *(undefined4 *)(param_2 + 0x1f8) = *param_4;
  *(longlong *)(param_2 + 8) = lVar6 + 0xe8;
  *(undefined8 *)(param_2 + 0x28) = 0x800;
  *(undefined8 *)(param_2 + 0x20) = 0x800;
  *(undefined8 *)(param_2 + 0x18) = 0x800;
  lVar6 = (ulonglong)(uint)param_4[2] << ((byte)*(undefined4 *)(lVar6 + 0x1b0) & 0x3f);
  *plVar5 = lVar6;
  uVar2 = *(uint *)(param_2 + 0x1e0);
  plVar5[2] = 0;
  *plVar5 = lVar6 - (ulonglong)uVar2;
  plVar5[1] = 0x800;
  plVar5[4] = 0x800;
  plVar5[3] = 0x800;
  *(uint *)(param_2 + 0xb0) = *(uint *)(param_2 + 0xb0) | 0x10;
  *(undefined4 *)(param_2 + 0x11c) = 1;
  puVar9 = auStack_38;
  if (param_3 != 0) {
    lVar6 = param_3 + 0x1e8;
    *(longlong *)(param_2 + 0x80) = param_3;
    plVar7 = *(longlong **)(param_3 + 0x1f0);
    plVar5 = (longlong *)(param_2 + 0x88);
    if (*plVar7 != lVar6) {
      plVar5 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      lVar6 = (*pcVar4)();
      puVar8 = auStack_30;
    }
    *plVar5 = lVar6;
    plVar5[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(lVar6 + 8) = plVar5;
    *(int *)(param_3 + 0xa4) = *(int *)(param_3 + 0xa4) + 1;
    *(int *)(param_3 + 0xa8) = *(int *)(param_3 + 0xa8) + 1;
    piVar1 = (int *)(*(longlong *)(param_3 + 0x78) + 0x3c);
    *piVar1 = *piVar1 + 1;
    piVar1 = (int *)(*(longlong *)(param_3 + 0x78) + 0x40);
    *piVar1 = *piVar1 + 1;
    puVar9 = puVar8;
  }
  lVar6 = *(longlong *)(param_2 + 0x78);
  uVar3 = *(undefined8 *)(param_2 + 0x98);
  *(longlong *)(puVar9 + 0x28) = param_2;
  *(undefined8 *)(puVar9 + 0x20) = uVar3;
  *(undefined8 *)(puVar9 + -8) = 0x14001a3e7;
  RtlInsertElementGenericTable(lVar6 + 0x1c0,puVar9 + 0x20);
  *(uint *)(param_2 + 0xac) = *(uint *)(param_2 + 0xac) | 2;
  return;
}



===== CdInitializeVcb @ 14001a408 =====

void CdInitializeVcb(undefined8 param_1,undefined4 *param_2,undefined8 param_3,longlong param_4)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  memset(param_2,0,800);
  *param_2 = 0x3200302;
  puVar1 = param_2 + 0x66;
  *(undefined4 **)(param_2 + 0x68) = puVar1;
  *(undefined4 **)puVar1 = puVar1;
  FsRtlNotifyInitializeSync(param_2 + 100);
  uVar4 = ExAllocatePoolWithTag(0x610,0x60,0x70766443);
  *(undefined8 *)(param_2 + 0x8c) = uVar4;
  ExInitializeResourceLite(param_2 + 0x20);
  ExInitializeResourceLite(param_2 + 0x3a);
  param_2[0x54] = 1;
  *(undefined8 *)(param_2 + 0x56) = 0;
  param_2[0x58] = 0;
  KeInitializeEvent(param_2 + 0x5a,1,0);
  puVar8 = auStack_38;
  plVar5 = (longlong *)(param_2 + 8);
  puVar7 = &DAT_140008330;
  lVar6 = (longlong)DAT_140008330;
  if ((longlong **)*(undefined8 **)((longlong)DAT_140008330 + 8) != &DAT_140008330) {
    lVar6 = 3;
    pcVar3 = (code *)swi(0x29);
    plVar5 = (longlong *)(*pcVar3)();
    puVar8 = auStack_30;
  }
  *plVar5 = lVar6;
  plVar5[1] = (longlong)puVar7;
  *(longlong **)(lVar6 + 8) = plVar5;
  *(undefined8 *)(puVar8 + -8) = 0x14001a51a;
  DAT_140008330 = plVar5;
  ObfReferenceObject(param_3);
  *(undefined8 *)(param_2 + 4) = param_3;
  *(longlong *)(param_2 + 2) = param_4;
  if ((*(uint *)(*(longlong *)(param_4 + 0x10) + 0x34) & 1) != 0) {
    param_2[0xc] = param_2[0xc] | 0x20;
  }
  *(undefined8 *)(puVar8 + 0x20) = 0;
  *(undefined8 *)(puVar8 + -8) = 0x14001a560;
  RtlInitializeGenericTable
            (param_2 + 0x70,CdFcbTableCompare,CdAllocateFcbTable,CdDeallocateFcbTable);
  param_2[0xd] = 1;
  param_2[0xf] = 7;
  *(undefined8 *)(param_2 + 0x82) = *(undefined8 *)(puVar8 + 0x60);
  param_2[0x84] = *(undefined4 *)(puVar8 + 0x68);
  param_2[0x85] = *(undefined4 *)(puVar8 + 0x70);
  iVar2 = *(int *)(puVar8 + 0x78);
  param_2[0x86] = iVar2;
  if (iVar2 == 1) {
    param_2[0xc] = param_2[0xc] | 0xc0;
  }
  param_2[0x87] = *(undefined4 *)(puVar8 + 0x80);
  param_2[0x88] = *(undefined4 *)(puVar8 + 0x88);
  return;
}



===== CdLookupFcbTable @ 14001a5e0 =====

undefined8 CdLookupFcbTable(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar2 = 0;
  local_10 = 0;
  local_18 = param_3;
  lVar1 = RtlLookupElementGenericTable(param_2 + 0x1c0,&local_18);
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}



===== CdProcessToc @ 14001a624 =====

ulonglong CdProcessToc(undefined8 param_1,undefined8 param_2,undefined1 *param_3,int *param_4,
                      int *param_5,uint *param_6)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_res8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 local_38 [2];
  uint local_30 [2];
  ulonglong uStack_28;
  
  uVar7 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  uStack_28 = 0;
  bVar1 = false;
  local_38[0] = 0;
  while( true ) {
    uVar4 = CdPerformDevIoCtrlEx
                      (param_1,(-(uint)bVar1 & 0xffffffac) + 0x24054,param_2,local_38,4,param_3,
                       0x554,in_stack_ffffffffffffffb0,'\x01',local_30);
    iVar3 = (int)uVar4;
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < iVar3) break;
    if (bVar1) {
      return uVar4;
    }
    if ((iVar3 != -0x3ffffff0) && (iVar3 != -0x3ffffff3)) {
      return uVar4;
    }
    bVar1 = true;
  }
  uVar9 = ((uint)(byte)param_3[3] - (uint)(byte)param_3[2]) + 1;
  if ((uStack_28 < uVar9 * 8 + 0xc) || ((byte)param_3[3] < (byte)param_3[2])) {
    uVar5 = 0xc0000032;
  }
  else {
    do {
      if ((param_3[uVar7 * 8 + 5] & 4) == 0) {
        uVar8 = 1;
      }
      else {
        if (((byte)*param_6 & 3) == 1) {
          param_3[3] = param_3[3] + -1;
          local_res8 = CONCAT13(param_3[uVar7 * 8 + 8],
                                CONCAT12(param_3[uVar7 * 8 + 9],
                                         CONCAT11(param_3[uVar7 * 8 + 10],param_3[uVar7 * 8 + 0xb]))
                               );
          local_res8 = local_res8 + -0x2bf2;
          param_3[uVar7 * 8 + 6] = 0xaa;
          param_3[uVar7 * 8 + 8] = (char)((uint)local_res8 >> 0x18);
          param_3[uVar7 * 8 + 9] = (char)((uint)local_res8 >> 0x10);
          param_3[uVar7 * 8 + 0xb] = (undefined1)local_res8;
          param_3[uVar7 * 8 + 10] = (char)((uint)local_res8 >> 8);
          *param_6 = *param_6 | 2;
          break;
        }
        uVar8 = 2;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      *param_6 = *param_6 | uVar8;
    } while (uVar6 < uVar9);
    *param_5 = (int)uVar7;
    iVar3 = (int)uVar7 * 8 + 0xc;
    *param_4 = iVar3;
    sVar2 = (short)iVar3 + -2;
    param_3[1] = (char)sVar2;
    *param_3 = (char)((ushort)sVar2 >> 8);
  }
  return uVar5;
}



===== CdTeardownStructures @ 14001a7f0 =====

void CdTeardownStructures(short *param_1,short *param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  short *psVar9;
  short *psVar10;
  undefined1 *puVar11;
  longlong lVar12;
  short *psVar13;
  longlong local_res10 [3];
  undefined8 uStack_90;
  undefined1 auStack_88 [32];
  char local_68 [8];
  short *local_60 [5];
  
  puVar11 = auStack_88;
  lVar2 = *(longlong *)(param_2 + 0x3c);
  local_60[0] = param_2;
  local_68[0] = 0;
  *param_3 = 0;
  uVar8 = *(uint *)(*(longlong *)(param_1 + 0x1c) + 0x20);
  if (-1 < (char)uVar8) {
    *(uint *)(*(longlong *)(param_1 + 0x1c) + 0x20) = uVar8 | 0x80;
    psVar10 = param_1;
    psVar13 = param_2;
    do {
      lVar7 = 0;
      if (((*psVar13 != 0x305) && (*(int *)(psVar13 + 0x54) == 0)) &&
         (*(longlong *)(psVar13 + 0xec) != 0)) {
        *(undefined8 *)(puVar11 + -8) = 0x14001a861;
        CdDeleteInternalStream(psVar10,(longlong)psVar13);
      }
      if (*(int *)(psVar13 + 0x52) != 0) break;
      lVar3 = *(longlong *)(psVar13 + 0x40);
      *(longlong *)(puVar11 + 0x98) = lVar3;
      if (lVar3 != 0) {
        lVar12 = *(longlong *)(lVar3 + 200);
        *(undefined8 *)(puVar11 + -8) = 0x14001a89e;
        CdAcquireResource((longlong)param_1,lVar12 + 0x20,'\0',0);
      }
      lVar12 = lVar2 + 0x150;
      *(undefined8 *)(puVar11 + -8) = 0x14001a8af;
      ExAcquireFastMutex(lVar12);
      *(void **)(lVar2 + 0x188) = SystemReserved1[0xf];
      if (*(int *)(psVar13 + 0x52) != 0) {
        *(undefined8 *)(lVar2 + 0x188) = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14001a8de;
        ExReleaseFastMutex(lVar12);
        if (*(longlong *)(puVar11 + 0x98) != 0) {
          lVar2 = *(longlong *)(lVar3 + 200);
          *(undefined8 *)(puVar11 + -8) = 0x14001a8fb;
          ExReleaseResourceLite(lVar2 + 0x20);
        }
        psVar13 = *(short **)(puVar11 + 0x28);
        break;
      }
      psVar13 = *(short **)(puVar11 + 0x98);
      psVar9 = *(short **)(puVar11 + 0x28);
      if (psVar13 == (short *)0x0) {
LAB_14001aa73:
        if ((*(uint *)(psVar9 + 0x56) & 2) != 0) {
          *(undefined8 *)(puVar11 + 0x38) = 0;
          *(undefined8 *)(puVar11 + 0x40) = 0;
          *(undefined8 *)(puVar11 + 0x38) = *(undefined8 *)(psVar9 + 0x4c);
          lVar3 = *(longlong *)(psVar9 + 0x3c);
          *(undefined8 *)(puVar11 + -8) = 0x14001aaa8;
          RtlDeleteElementGenericTable(lVar3 + 0x1c0);
          *(uint *)(psVar9 + 0x56) = *(uint *)(psVar9 + 0x56) & 0xfffffffd;
        }
        *(undefined8 *)(lVar2 + 0x188) = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14001aac5;
        ExReleaseFastMutex(lVar12);
        *(undefined8 *)(puVar11 + 0x30) = 0;
        *(undefined8 *)(puVar11 + -8) = 0x14001aadc;
        FsRtlTeardownPerStreamContexts(psVar9);
        if ((1 < *(uint *)(psVar9 + 0x8c)) && (*(longlong *)(psVar9 + 0x90) != 0)) {
          *(undefined8 *)(puVar11 + -8) = 0x14001aaff;
          ExFreePoolWithTag();
          psVar9[0x90] = 0;
          psVar9[0x91] = 0;
          psVar9[0x92] = 0;
          psVar9[0x93] = 0;
        }
        lVar3 = *(longlong *)(psVar9 + 100);
        *(undefined8 *)(puVar11 + -8) = 0x14001ab1d;
        ExDeleteResourceLite(lVar3 + 0x20);
        if (lVar3 != 0) {
          *(undefined8 *)(puVar11 + -8) = 0x14001ab33;
          ExFreePoolWithTag(lVar3);
        }
        if ((*(short **)(psVar9 + 0xb0) != psVar9 + 200) &&
           (*(short **)(psVar9 + 0xb0) != (short *)0x0)) {
          *(undefined8 *)(puVar11 + -8) = 0x14001ab5c;
          ExFreePoolWithTag();
          psVar9[0xb0] = 0;
          psVar9[0xb1] = 0;
          psVar9[0xb2] = 0;
          psVar9[0xb3] = 0;
        }
        if (*(longlong *)(psVar9 + 0x94) != 0) {
          *(undefined8 *)(puVar11 + -8) = 0x14001ab7d;
          ExFreePoolWithTag();
          psVar9[0x94] = 0;
          psVar9[0x95] = 0;
          psVar9[0x96] = 0;
          psVar9[0x97] = 0;
        }
        lVar12 = lVar7;
        if (*psVar9 == 0x303) goto LAB_14001abdd;
        uVar8 = (int)*psVar9 - 0x304;
        if (uVar8 == 0) goto LAB_14001abdd;
        psVar10 = (short *)(ulonglong)uVar8;
        if (uVar8 == 1) {
          if (*(longlong *)(psVar9 + 0xec) != 0) {
            *(undefined8 *)(puVar11 + -8) = 0x14001abb1;
            FsRtlFreeFileLock();
          }
          *(undefined8 *)(puVar11 + -8) = 0x14001abc1;
          FsRtlUninitializeOplock(psVar9 + 0x2c);
          lVar7 = *(longlong *)(psVar9 + 0x3c);
          if (psVar9 != *(short **)(lVar7 + 0x48)) goto LAB_14001abff;
          *(undefined8 *)(lVar7 + 0x48) = 0;
          goto LAB_14001abf7;
        }
      }
      else {
        lVar3 = *(longlong *)(psVar9 + 0x94);
        if (lVar3 != 0) {
          if ((*(uint *)(lVar3 + 8) & 2) != 0) {
            *(undefined8 *)(puVar11 + -8) = 0x14001a93e;
            uVar6 = RtlDelete(lVar3 + 0x38);
            *(undefined8 *)(*(longlong *)(psVar9 + 0x40) + 0x210) = uVar6;
          }
          lVar3 = *(longlong *)(psVar9 + 0x94);
          if ((*(uint *)(lVar3 + 8) & 1) != 0) {
            *(undefined8 *)(puVar11 + -8) = 0x14001a96a;
            uVar6 = RtlDelete(lVar3 + 0x10);
            *(undefined8 *)(*(longlong *)(psVar9 + 0x40) + 0x208) = uVar6;
          }
          *(uint *)(*(longlong *)(psVar9 + 0x94) + 8) =
               *(uint *)(*(longlong *)(psVar9 + 0x94) + 8) & 0xfffffffc;
        }
        if ((*(uint *)(psVar9 + 0x9c) & 2) != 0) {
          *(undefined8 *)(puVar11 + -8) = 0x14001a9a5;
          uVar6 = RtlDelete(psVar9 + 0xb4);
          *(undefined8 *)(*(longlong *)(psVar9 + 0x40) + 0x210) = uVar6;
        }
        if ((*(uint *)(psVar9 + 0x9c) & 1) != 0) {
          *(undefined8 *)(puVar11 + -8) = 0x14001a9d0;
          uVar6 = RtlDelete(psVar9 + 0xa0);
          *(undefined8 *)(*(longlong *)(psVar9 + 0x40) + 0x208) = uVar6;
        }
        *(uint *)(psVar9 + 0x9c) = *(uint *)(psVar9 + 0x9c) & 0xfffffffc;
        psVar10 = *(short **)(psVar9 + 0xb0);
        if ((psVar10 != psVar9 + 200) && (psVar10 != (short *)0x0)) {
          *(undefined8 *)(puVar11 + -8) = 0x14001aa0b;
          ExFreePoolWithTag(psVar10,0);
          psVar9[0xb0] = 0;
          psVar9[0xb1] = 0;
          psVar9[0xb2] = 0;
          psVar9[0xb3] = 0;
        }
        plVar1 = (longlong *)(psVar9 + 0x44);
        lVar3 = *plVar1;
        plVar4 = *(longlong **)(psVar9 + 0x48);
        if ((*(longlong **)(lVar3 + 8) == plVar1) && ((longlong *)*plVar4 == plVar1)) {
          *plVar4 = lVar3;
          *(longlong **)(lVar3 + 8) = plVar4;
          *(int *)(psVar13 + 0x52) = *(int *)(psVar13 + 0x52) + -1;
          *(int *)(psVar13 + 0x54) = *(int *)(psVar13 + 0x54) + -1;
          *(int *)(*(longlong *)(psVar13 + 0x3c) + 0x3c) =
               *(int *)(*(longlong *)(psVar13 + 0x3c) + 0x3c) + -1;
          *(int *)(*(longlong *)(psVar13 + 0x3c) + 0x40) =
               *(int *)(*(longlong *)(psVar13 + 0x3c) + 0x40) + -1;
          goto LAB_14001aa73;
        }
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar11 = puVar11 + 8;
LAB_14001abdd:
        lVar7 = *(longlong *)(psVar9 + 0x3c);
        if (psVar9 == *(short **)(lVar7 + 0x50)) {
          *(undefined8 *)(lVar7 + 0x50) = 0;
LAB_14001abf7:
          *(longlong *)(puVar11 + 0x30) = lVar7;
          lVar12 = lVar7;
        }
        else if (psVar9 == *(short **)(lVar7 + 0x58)) {
          *(undefined8 *)(lVar7 + 0x58) = 0;
          goto LAB_14001abf7;
        }
LAB_14001abff:
        *(undefined8 *)(puVar11 + -8) = 0x14001ac0b;
        ExFreePoolWithTag();
        psVar10 = psVar9;
      }
      if (lVar12 != 0) {
        LOCK();
        *(int *)(lVar12 + 0x3c) = *(int *)(lVar12 + 0x3c) + -1;
        UNLOCK();
        LOCK();
        *(int *)(lVar12 + 0x40) = *(int *)(lVar12 + 0x40) + -1;
        UNLOCK();
        psVar13 = *(short **)(puVar11 + 0x98);
      }
      *(short **)(puVar11 + 0x28) = psVar13;
      puVar11[0x20] = 1;
    } while (psVar13 != (short *)0x0);
    if ((puVar11[0x20] != '\0') && (psVar13 != (short *)0x0)) {
      lVar2 = *(longlong *)(psVar13 + 100);
      *(undefined8 *)(puVar11 + -8) = 0x14001ac56;
      ExReleaseResourceLite(lVar2 + 0x20);
    }
    *(uint *)(*(longlong *)(param_1 + 0x1c) + 0x20) =
         *(uint *)(*(longlong *)(param_1 + 0x1c) + 0x20) & 0xffffff7f;
    *(bool *)*(undefined8 *)(puVar11 + 0xa0) = psVar13 != param_2;
  }
  return;
}



===== CdTocSerial @ 14001ac8c =====

uint CdTocSerial(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  longlong lVar5;
  undefined4 local_res8;
  undefined4 local_res10;
  undefined4 local_res18;
  
  lVar5 = param_2 + 4;
  local_res10 = 0;
  lVar1 = param_2 + 0xc +
          ((ulonglong)*(byte *)(param_2 + 3) - (ulonglong)*(byte *)(param_2 + 2)) * 8;
  if ((int)((uint)*(byte *)(param_2 + 3) - (uint)*(byte *)(param_2 + 2)) < 2) {
    local_res8._0_2_ = CONCAT11(*(undefined1 *)(lVar1 + 6),*(undefined1 *)(lVar1 + 7));
    local_res8._0_3_ = CONCAT12(*(undefined1 *)(lVar1 + 5),(undefined2)local_res8);
    local_res8 = CONCAT13(*(undefined1 *)(lVar1 + 4),(undefined3)local_res8);
    uVar4 = (local_res8 + 0x96U) / 0x4b;
    cVar2 = (char)uVar4;
    cVar3 = (char)((ulonglong)uVar4 / 0x3c);
    local_res10._0_2_ = CONCAT11(cVar2 + cVar3 * -0x3c,(char)(local_res8 + 0x96U) + cVar2 * -0x4b);
    local_res10 = (uint)CONCAT12(cVar3,(undefined2)local_res10);
  }
  else {
    for (; lVar5 != lVar1; lVar5 = lVar5 + 8) {
      local_res8._0_2_ = CONCAT11(*(undefined1 *)(lVar5 + 6),*(undefined1 *)(lVar5 + 7));
      local_res8._0_3_ = CONCAT12(*(undefined1 *)(lVar5 + 5),(undefined2)local_res8);
      local_res8 = CONCAT13(*(undefined1 *)(lVar5 + 4),(undefined3)local_res8);
      uVar4 = (local_res8 + 0x96U) / 0x4b;
      cVar2 = (char)uVar4;
      cVar3 = (char)((ulonglong)uVar4 / 0x3c);
      local_res18._0_2_ = CONCAT11(cVar2 + cVar3 * -0x3c,(char)(local_res8 + 0x96U) + cVar2 * -0x4b)
      ;
      local_res18 = (uint)CONCAT12(cVar3,(undefined2)local_res18);
      local_res10 = local_res10 + local_res18;
    }
  }
  return local_res10;
}



===== CdUpdateVcbFromVolDescriptor @ 14001adbc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdUpdateVcbFromVolDescriptor(void *param_1,longlong param_2,longlong param_3)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  void *pvVar9;
  ushort uVar10;
  uint uVar11;
  ushort *puVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined4 local_d8;
  uint local_d4;
  int local_d0;
  
  memset(&local_d8,0,0xa8);
  puVar1 = (uint *)(param_2 + 0x30);
  if (param_3 == 0) {
    uVar11 = 0x800;
  }
  else {
    if ((*puVar1 & 1) == 0) {
      uVar10 = *(ushort *)(param_3 + 0x80);
    }
    else {
      uVar10 = *(ushort *)(param_3 + 0x88);
    }
    uVar11 = (uint)uVar10;
  }
  *(uint *)(param_2 + 0x1a8) = uVar11;
  if (uVar11 != 0x800) {
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx((longlong)param_1,0xc0000032,'\0',0x190000,0x1fb);
  }
  *(undefined4 *)(param_2 + 0x1b4) = 1;
  *(undefined4 *)(param_2 + 0x1b8) = 0x7ff;
  *(undefined4 *)(param_2 + 0x1bc) = 0xfffff800;
  *(undefined4 *)(param_2 + 0x1ac) = 0;
  *(undefined4 *)(param_2 + 0x1b0) = 0xb;
  if (param_3 == 0) {
    if ((char)*puVar1 < '\0') {
      lVar2 = param_2 + 0x150;
      ExAcquireFastMutex(lVar2);
      *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
      puVar12 = CdCreateFcb((longlong)param_1,0,0x303,(ushort **)0x0);
      *(ushort **)(param_2 + 0x58) = puVar12;
      *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
      *(int *)(*(longlong *)(param_2 + 0x58) + 0xa8) =
           *(int *)(*(longlong *)(param_2 + 0x58) + 0xa8) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x78);
      *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x78);
      *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex(lVar2);
      *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x20) = 10;
      *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x28) =
           *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x20);
      *(ulonglong *)(*(longlong *)(param_2 + 0x58) + 0x18) =
           *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x20) + 0x7ffU & 0xfffffffffffff800;
      *(longlong *)(*(longlong *)(param_2 + 0x58) + 8) = param_2 + 0xe8;
      *(uint *)(*(longlong *)(param_2 + 0x58) + 0xac) =
           *(uint *)(*(longlong *)(param_2 + 0x58) + 0xac) | 1;
      CdCreateInternalStream
                (param_1,param_2,*(longlong *)(param_2 + 0x58),(undefined4 *)&CdInternalStreamNames)
      ;
      ExAcquireFastMutex(lVar2);
      *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
      puVar12 = CdCreateFcb((longlong)param_1,0,0x304,(ushort **)0x0);
      *(ushort **)(param_2 + 0x50) = puVar12;
      *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
      *(int *)(*(longlong *)(param_2 + 0x50) + 0xa8) =
           *(int *)(*(longlong *)(param_2 + 0x50) + 0xa8) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x78);
      *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x78);
      *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex(lVar2);
      *(undefined4 *)(*(longlong *)(param_2 + 0x50) + 0x9c) =
           *(undefined4 *)(*(longlong *)(param_2 + 0x58) + 0x1e0);
      *(uint *)(*(longlong *)(param_2 + 0x50) + 0x98) =
           *(uint *)(*(longlong *)(param_2 + 0x50) + 0x98) | 0x80000000;
      local_d8 = 1;
      local_d4 = *(uint *)(*(longlong *)(param_2 + 0x58) + 0x1e0);
      CdInitializeFcbFromPathEntry((ulonglong)local_d4,*(longlong *)(param_2 + 0x50),0,&local_d8);
      uVar13 = (ulonglong)
               ((*(int *)(param_2 + 0x214) + 2) * CdAudioDirentSize + 0x7ffU & 0xfffff800);
      *(ulonglong *)(*(longlong *)(param_2 + 0x50) + 0x20) = uVar13;
      *(ulonglong *)(*(longlong *)(param_2 + 0x50) + 0x28) = uVar13;
      *(ulonglong *)(*(longlong *)(param_2 + 0x50) + 0x18) = uVar13;
      *(uint *)(*(longlong *)(param_2 + 0x50) + 0xac) =
           *(uint *)(*(longlong *)(param_2 + 0x50) + 0xac) | 1;
      CdCreateInternalStream
                (param_1,param_2,*(longlong *)(param_2 + 0x50),(undefined4 *)&DAT_140008010);
      ExAcquireFastMutex(lVar2);
      *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
      puVar12 = CdCreateFcb((longlong)param_1,0,0x305,(ushort **)0x0);
      *(ushort **)(param_2 + 0x48) = puVar12;
      *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
      *(int *)(*(longlong *)(param_2 + 0x48) + 0xa8) =
           *(int *)(*(longlong *)(param_2 + 0x48) + 0xa8) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x48) + 0x78);
      *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
      lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x48) + 0x78);
      *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
      *(undefined8 *)(param_2 + 0x188) = 0;
      ExReleaseFastMutex(lVar2);
      *(longlong *)(*(longlong *)(param_2 + 0x48) + 8) = param_2 + 0xe8;
      *(undefined4 *)(*(longlong *)(param_2 + 0x48) + 0xb0) = 1;
      *(uint *)(*(longlong *)(param_2 + 0x48) + 0xac) =
           *(uint *)(*(longlong *)(param_2 + 0x48) + 0xac) | 1;
      *(undefined2 *)(*(longlong *)(param_2 + 8) + 6) = 0x10;
      uVar8 = uRam0000000140008140;
      lVar2 = *(longlong *)(param_2 + 8);
      *(undefined8 *)(lVar2 + 0x20) = _CdAudioLabel;
      *(undefined8 *)(lVar2 + 0x28) = uVar8;
      uVar11 = CdTocSerial(0x10,*(longlong *)(param_2 + 0x208));
      *(uint *)(*(longlong *)(param_2 + 8) + 0x18) = uVar11;
      *puVar1 = *puVar1 | 2;
    }
  }
  else {
    lVar2 = param_2 + 0x150;
    ExAcquireFastMutex(lVar2);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    puVar12 = CdCreateFcb((longlong)param_1,0,0x303,(ushort **)0x0);
    *(ushort **)(param_2 + 0x58) = puVar12;
    *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
    *(int *)(*(longlong *)(param_2 + 0x58) + 0xa8) =
         *(int *)(*(longlong *)(param_2 + 0x58) + 0xa8) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x78);
    *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x78);
    *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar2);
    if ((*puVar1 & 1) == 0) {
      uVar11 = *(uint *)(param_3 + 0x8c);
      iVar3 = *(int *)(param_3 + 0x84);
    }
    else {
      uVar11 = *(uint *)(param_3 + 0x94);
      iVar3 = *(int *)(param_3 + 0x8c);
    }
    *(uint *)(*(longlong *)(param_2 + 0x58) + 0x1e0) =
         (*(int *)(param_2 + 0x1b4) - 1U & uVar11) <<
         ((byte)*(undefined4 *)(param_2 + 0x1b0) & 0x1f);
    *(ulonglong *)(*(longlong *)(param_2 + 0x58) + 0x20) =
         (ulonglong)(uint)(*(int *)(*(longlong *)(param_2 + 0x58) + 0x1e0) + iVar3);
    *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x28) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0x20);
    *(ulonglong *)(*(longlong *)(param_2 + 0x58) + 0x18) =
         *(longlong *)(*(longlong *)(param_2 + 0x58) + 0x20) + 0x7ffU & 0xfffffffffffff800;
    pvVar9 = SystemReserved1[0xf];
    if (SystemReserved1[0xf] != *(void **)(*(longlong *)(param_2 + 0x58) + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(*(longlong *)(param_2 + 0x58) + 200) + 0x88);
      *(void **)(*(longlong *)(param_2 + 0x58) + 0xb8) = pvVar9;
    }
    *(int *)(*(longlong *)(param_2 + 0x58) + 0xc0) =
         *(int *)(*(longlong *)(param_2 + 0x58) + 0xc0) + 1;
    lVar4 = *(longlong *)(param_2 + 0x58);
    lVar5 = *(longlong *)(lVar4 + 0x18);
    plVar6 = *(longlong **)(lVar4 + 0x120);
    lVar14 = (ulonglong)uVar11 <<
             ((byte)*(undefined4 *)(*(longlong *)(lVar4 + 0x78) + 0x1b0) & 0x3f);
    *plVar6 = lVar14;
    *plVar6 = lVar14 - (ulonglong)*(uint *)(lVar4 + 0x1e0);
    plVar6[1] = lVar5;
    plVar6[2] = 0;
    plVar6[4] = lVar5;
    plVar6[3] = lVar5;
    *(undefined4 *)(lVar4 + 0x11c) = 1;
    *(int *)(*(longlong *)(param_2 + 0x58) + 0xc0) =
         *(int *)(*(longlong *)(param_2 + 0x58) + 0xc0) + -1;
    if (*(int *)(*(longlong *)(param_2 + 0x58) + 0xc0) == 0) {
      *(undefined8 *)(*(longlong *)(param_2 + 0x58) + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(*(longlong *)(param_2 + 0x58) + 200) + 0x88);
    }
    *(longlong *)(*(longlong *)(param_2 + 0x58) + 8) = param_2 + 0xe8;
    *(uint *)(*(longlong *)(param_2 + 0x58) + 0xac) =
         *(uint *)(*(longlong *)(param_2 + 0x58) + 0xac) | 1;
    CdCreateInternalStream
              (param_1,param_2,*(longlong *)(param_2 + 0x58),(undefined4 *)&CdInternalStreamNames);
    ExAcquireFastMutex(lVar2);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    puVar12 = CdCreateFcb((longlong)param_1,0,0x304,(ushort **)0x0);
    *(ushort **)(param_2 + 0x50) = puVar12;
    *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
    *(int *)(*(longlong *)(param_2 + 0x50) + 0xa8) =
         *(int *)(*(longlong *)(param_2 + 0x50) + 0xa8) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x78);
    *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x78);
    *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar2);
    *(undefined4 *)(*(longlong *)(param_2 + 0x50) + 0x9c) =
         *(undefined4 *)(*(longlong *)(param_2 + 0x58) + 0x1e0);
    *(uint *)(*(longlong *)(param_2 + 0x50) + 0x98) =
         *(uint *)(*(longlong *)(param_2 + 0x50) + 0x98) | 0x80000000;
    local_d0 = (uint)*(byte *)((ulonglong)(-(uint)((*puVar1 & 1) != 0) & 0x18) + 0x9d + param_3) +
               *(int *)((ulonglong)(-(uint)((*puVar1 & 1) != 0) & 0x18) + 0x9e + param_3);
    local_d8 = 1;
    local_d4 = *(uint *)(*(longlong *)(param_2 + 0x58) + 0x1e0);
    CdInitializeFcbFromPathEntry((ulonglong)local_d4,*(longlong *)(param_2 + 0x50),0,&local_d8);
    CdCreateInternalStream
              (param_1,param_2,*(longlong *)(param_2 + 0x50),(undefined4 *)&DAT_140008010);
    ExAcquireFastMutex(lVar2);
    *(void **)(param_2 + 0x188) = SystemReserved1[0xf];
    puVar12 = CdCreateFcb((longlong)param_1,0,0x305,(ushort **)0x0);
    *(ushort **)(param_2 + 0x48) = puVar12;
    *(int *)(puVar12 + 0x52) = *(int *)(puVar12 + 0x52) + 1;
    *(int *)(*(longlong *)(param_2 + 0x48) + 0xa8) =
         *(int *)(*(longlong *)(param_2 + 0x48) + 0xa8) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x48) + 0x78);
    *(int *)(lVar4 + 0x3c) = *(int *)(lVar4 + 0x3c) + 1;
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x48) + 0x78);
    *(int *)(lVar4 + 0x40) = *(int *)(lVar4 + 0x40) + 1;
    *(undefined8 *)(param_2 + 0x188) = 0;
    ExReleaseFastMutex(lVar2);
    if ((*puVar1 & 1) == 0) {
      uVar11 = *(uint *)(param_3 + 0x50);
    }
    else {
      uVar11 = *(uint *)(param_3 + 0x58);
    }
    *(ulonglong *)(*(longlong *)(param_2 + 0x48) + 0x20) =
         (ulonglong)uVar11 << ((byte)*(undefined4 *)(param_2 + 0x1b0) & 0x3f);
    *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x28) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x20);
    *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x18) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x28);
    pvVar9 = SystemReserved1[0xf];
    if (SystemReserved1[0xf] != *(void **)(*(longlong *)(param_2 + 0x48) + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(*(longlong *)(param_2 + 0x48) + 200) + 0x88);
      *(void **)(*(longlong *)(param_2 + 0x48) + 0xb8) = pvVar9;
    }
    *(int *)(*(longlong *)(param_2 + 0x48) + 0xc0) =
         *(int *)(*(longlong *)(param_2 + 0x48) + 0xc0) + 1;
    puVar7 = *(undefined8 **)(*(longlong *)(param_2 + 0x48) + 0x120);
    *puVar7 = 0;
    puVar7[2] = 0;
    uVar8 = *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x18);
    puVar7[1] = uVar8;
    puVar7[4] = uVar8;
    puVar7[3] = uVar8;
    *(undefined4 *)(*(longlong *)(param_2 + 0x48) + 0x11c) = 1;
    *(int *)(*(longlong *)(param_2 + 0x48) + 0xc0) =
         *(int *)(*(longlong *)(param_2 + 0x48) + 0xc0) + -1;
    if (*(int *)(*(longlong *)(param_2 + 0x48) + 0xc0) == 0) {
      *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(*(longlong *)(param_2 + 0x48) + 200) + 0x88);
    }
    *(longlong *)(*(longlong *)(param_2 + 0x48) + 8) = param_2 + 0xe8;
    *(undefined4 *)(*(longlong *)(param_2 + 0x48) + 0xb0) = 1;
    *(uint *)(*(longlong *)(param_2 + 0x48) + 0xac) =
         *(uint *)(*(longlong *)(param_2 + 0x48) + 0xac) | 1;
    if (((*puVar1 & 6) != 0) && (CdXaId == *(longlong *)(param_3 + 0x400))) {
      *puVar1 = *puVar1 | 0x40;
    }
  }
  return;
}



===== CdVerifyFcbOperation @ 14001b768 =====

ulonglong CdVerifyFcbOperation(longlong param_1,longlong param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  ulonglong uVar7;
  
  lVar4 = *(longlong *)(param_2 + 0x78);
  lVar5 = *(longlong *)(*(longlong *)(lVar4 + 8) + 0x10);
  if (param_1 != 0) {
    pcVar6 = *(char **)(*(longlong *)(param_1 + 8) + 0xb8);
    if ((((*(longlong *)(pcVar6 + 0x30) != 0) &&
         ((*(uint *)(*(longlong *)(pcVar6 + 0x30) + 0x50) & 0x4000) != 0)) &&
        ((*(uint *)(*(longlong *)(param_1 + 8) + 0x10) & 2) == 0)) &&
       (((cVar2 = *pcVar6, cVar2 != '\x02' && (cVar2 != '\x05')) &&
        ((cVar2 != '\x03' || ((pcVar6[1] & 4U) == 0)))))) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000128,'\0',0x1b0000,0x2aa);
    }
  }
  iVar3 = *(int *)(lVar4 + 0x34);
  uVar7 = (ulonglong)(iVar3 - 3U);
  if (iVar3 - 3U < 2) {
    if (param_1 != 0) {
      if ((*(uint *)(lVar4 + 0x30) & 0x800) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc0000098,'\0',0x1b0000,0x2bf);
      }
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc000026e,'\0',0x1b0000,699);
    }
  }
  else {
    uVar7 = (ulonglong)*(uint *)(lVar5 + 0x30);
    if ((*(uint *)(lVar5 + 0x30) & 2) == 0) {
      uVar1 = iVar3 - 1;
      uVar7 = (ulonglong)uVar1;
      if (1 < uVar1) {
        if (param_1 == 0) goto LAB_14001b811;
        if (iVar3 == 0) {
          IoSetHardErrorOrVerifyDevice(*(undefined8 *)(param_1 + 8),lVar5);
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx(param_1,0xc0000012,'\0',0x1b0000,0x2f0);
        }
      }
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
    if (param_1 != 0) {
      IoSetHardErrorOrVerifyDevice(*(undefined8 *)(param_1 + 8),lVar5);
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0x80000016,'\0',0x1b0000,0x2d1);
    }
  }
LAB_14001b811:
  return uVar7 & 0xffffffffffffff00;
}



===== CdVerifyVcb @ 14001b8d0 =====

void CdVerifyVcb(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  int local_res10 [2];
  undefined8 in_stack_ffffffffffffffc0;
  uint local_28 [2];
  longlong lStack_20;
  
  iVar5 = 0;
  local_res10[0] = 0;
  bVar3 = false;
  iVar1 = *(int *)(param_2 + 0x34);
  local_28[0] = 0;
  local_28[1] = 0;
  lStack_20 = 0;
  if ((iVar1 == 3) || ((iVar1 == 4 && (*(char *)(param_1 + 0x40) != '\0')))) {
    if ((*(uint *)(param_2 + 0x30) & 0x800) == 0) {
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc0000098,'\0',0x1b0000,0x1d3);
    }
                    /* WARNING: Subroutine does not return */
    CdRaiseStatusEx(param_1,0xc000026e,'\0',0x1b0000,0x1cf);
  }
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x10);
  uVar6 = *(uint *)(lVar2 + 0x30) & 2;
  bVar7 = uVar6 != 0;
  if (((*(uint *)(param_2 + 0x30) & 0x20) == 0) || (uVar6 != 0)) {
LAB_14001ba1b:
    if (bVar7) goto LAB_14001ba8d;
LAB_14001ba20:
    if (-1 < iVar5) {
      iVar1 = *(int *)(param_2 + 0x34);
      if (iVar1 == 0) {
        IoSetHardErrorOrVerifyDevice
                  (*(undefined8 *)(param_1 + 8),*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10));
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc0000012,'\0',0x1b0000,599);
      }
      if ((iVar1 != 3) && (iVar1 != 4)) {
        return;
      }
      if ((*(uint *)(param_2 + 0x30) & 0x800) == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx(param_1,0xc0000098,'\0',0x1b0000,0x263);
      }
                    /* WARNING: Subroutine does not return */
      CdRaiseStatusEx(param_1,0xc000026e,'\0',0x1b0000,0x25f);
    }
  }
  else {
    iVar5 = 0;
    if (iVar1 == 1) {
LAB_14001b9eb:
      if (((*(char *)(param_1 + 0x40) != '\0') ||
          (*(longlong *)
            (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xb8) + 0x30) + 0x40) != 0))
         || ((*(uint *)(param_2 + 0x34) & 0xfffffffb) != 0)) goto LAB_14001ba20;
    }
    else {
      uVar4 = CdPerformDevIoCtrlEx
                        (lVar2,0x24800,*(undefined8 *)(param_2 + 0x10),0,0,local_res10,4,
                         in_stack_ffffffffffffffc0,'\0',local_28);
      iVar5 = (int)uVar4;
      if (lStack_20 != 4) {
        local_res10[0] = 0;
      }
      if (((*(int *)(param_2 + 0x34) != 2) || ((iVar5 != -0x3fffff5d && (iVar5 != -0x3fffffed)))) &&
         (iVar5 != -0x7fffffea)) {
        if (iVar5 < 0) goto LAB_14001ba1b;
        if (*(int *)(param_2 + 0x220) == local_res10[0]) goto LAB_14001b9eb;
      }
      if ((*(uint *)(param_2 + 0x30) & 0x200) == 0) {
        bVar7 = CdMarkDevForVerifyIfVcbMounted(param_2);
      }
    }
    bVar3 = true;
  }
LAB_14001ba8d:
  IoSetHardErrorOrVerifyDevice
            (*(undefined8 *)(param_1 + 8),*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x10));
  if ((bVar3) || (bVar7 != false)) {
    iVar5 = -0x7fffffea;
  }
                    /* WARNING: Subroutine does not return */
  CdRaiseStatusEx(param_1,iVar5,'\0',0x1b0000,0x249);
}



===== CdCommonQueryVolInfo @ 14001bb5c =====

uint CdCommonQueryVolInfo(undefined8 *param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  uVar9 = 0xc000000d;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar12 = *(int *)(lVar3 + 8);
  if ((*(uint *)(*(longlong *)(lVar3 + 0x30) + 0x20) & 7) == 0) goto LAB_14001bba6;
  lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x18);
  CdAcquireResource((longlong)param_1,*(longlong *)(lVar4 + 0x78) + 0x80,'\0',1);
  CdVerifyVcb((longlong)param_1,*(longlong *)(lVar4 + 0x78));
  iVar2 = *(int *)(lVar3 + 0x10);
  if (iVar2 == 1) {
    puVar7 = *(undefined8 **)(param_2 + 0x18);
    lVar8 = *(longlong *)(lVar4 + 0x78);
    *puVar7 = *(undefined8 *)(*(longlong *)(lVar8 + 0x48) + 0x1d0);
    *(undefined4 *)(puVar7 + 1) = *(undefined4 *)(*(longlong *)(lVar8 + 8) + 0x18);
    *(undefined1 *)(puVar7 + 2) = 0;
    uVar11 = iVar12 - 0x12;
    uVar1 = *(ushort *)(*(longlong *)(lVar8 + 8) + 6);
    uVar9 = -(uint)(uVar11 < uVar1) & 0x80000005;
    uVar10 = (uint)uVar1;
    if (uVar11 < uVar1) {
      uVar10 = uVar11;
    }
    *(uint *)((longlong)puVar7 + 0xc) = uVar10;
    if (uVar10 != 0) {
      memmove((void *)((longlong)puVar7 + 0x12),(void *)(*(longlong *)(lVar8 + 8) + 0x20),
              (ulonglong)uVar10);
    }
    iVar12 = uVar11 - uVar10;
  }
  else {
    if (iVar2 == 3) {
      plVar6 = *(longlong **)(param_2 + 0x18);
      *plVar6 = *(longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0x78) + 0x48) + 0x18) >> 0xb;
      plVar6[1] = 0;
      *(undefined4 *)(plVar6 + 2) = 1;
      *(undefined4 *)((longlong)plVar6 + 0x14) = 0x800;
      iVar12 = iVar12 + -0x18;
    }
    else {
      if (iVar2 != 4) {
        if (iVar2 == 5) {
          puVar5 = *(undefined4 **)(param_2 + 0x18);
          *puVar5 = 0x1080001;
          if ((*(uint *)(param_1[2] + 0x30) & 4) == 0) {
            puVar5[1] = 0xdd;
          }
          else {
            *puVar5 = 0x1080005;
            puVar5[1] = 0x6e;
          }
          uVar11 = iVar12 - 0xcU & 0xfffffffe;
          uVar10 = uVar11;
          if (uVar11 >= 8) {
            uVar10 = 8;
          }
          uVar9 = -(uint)(uVar11 < 8) & 0x80000005;
          iVar12 = uVar11 - uVar10;
          puVar5[2] = uVar10;
          memmove(puVar5 + 3,L"CDFS",(ulonglong)uVar10);
        }
        else if (iVar2 == 0xb) {
          uVar9 = FsRtlGetSectorSizeInformation
                            (*(undefined8 *)(*(longlong *)(*(longlong *)(lVar4 + 0x78) + 8) + 0x10),
                             *(undefined8 *)(param_2 + 0x18));
          iVar2 = iVar12 + -0x1c;
          if ((int)uVar9 < 0) {
            iVar2 = iVar12;
          }
          iVar12 = iVar2;
        }
        goto LAB_14001bd5b;
      }
      puVar5 = *(undefined4 **)(param_2 + 0x18);
      puVar5[1] = *(undefined4 *)(*(longlong *)(*(longlong *)(lVar4 + 0x78) + 0x10) + 0x34);
      *puVar5 = 2;
      iVar12 = iVar12 + -8;
    }
    uVar9 = 0;
  }
LAB_14001bd5b:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uint)(*(int *)(lVar3 + 8) - iVar12);
  ExReleaseResourceLite(*(longlong *)(lVar4 + 0x78) + 0x80);
LAB_14001bba6:
  CdCompleteRequest(param_1,param_2,uVar9);
  return uVar9;
}



===== CdFsdPostRequest @ 14001bd8c =====

undefined8 CdFsdPostRequest(short *param_1,longlong param_2)

{
  CdPrePostIrp(param_1,param_2);
  CdAddToWorkque((longlong)param_1,param_2);
  return 0x103;
}



===== CdOplockComplete @ 14001bdd0 =====

void CdOplockComplete(short *param_1,longlong param_2)

{
  char local_res10 [24];
  
  local_res10[0] = '\0';
  if (*(uint *)(param_2 + 0x30) == 0) {
    if (((char)param_1[0x20] == '\0') && (*(undefined8 **)(param_1 + 0x18) != (undefined8 *)0x0)) {
      CdTeardownStructures(param_1,(short *)**(undefined8 **)(param_1 + 0x18),local_res10);
      if (local_res10[0] == '\0') {
        ExReleaseResourceLite(*(longlong *)(**(longlong **)(param_1 + 0x18) + 200) + 0x20);
      }
      **(undefined8 **)(param_1 + 0x18) = 0;
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      param_1[0x1a] = 0;
      param_1[0x1b] = 0;
    }
    CdAddToWorkque((longlong)param_1,param_2);
  }
  else {
    CdCompleteRequest((undefined8 *)param_1,param_2,*(uint *)(param_2 + 0x30));
  }
  return;
}



===== CdPrePostIrp @ 14001be60 =====

void CdPrePostIrp(short *param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  short *psVar3;
  bool bVar4;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  cVar2 = (char)param_1[0x20];
  if (cVar2 == '\0') {
    if ((*(undefined8 **)(param_1 + 0x18) != (undefined8 *)0x0) &&
       (psVar3 = (short *)**(undefined8 **)(param_1 + 0x18), psVar3 != (short *)0x0)) {
      CdTeardownStructures(param_1,psVar3,local_res8);
      if (local_res8[0] == '\0') {
        ExReleaseResourceLite(*(longlong *)(**(longlong **)(param_1 + 0x18) + 200) + 0x20);
      }
      **(undefined8 **)(param_1 + 0x18) = 0;
      param_1[0x18] = 0;
      param_1[0x19] = 0;
      param_1[0x1a] = 0;
      param_1[0x1b] = 0;
    }
  }
  else {
    if ((cVar2 == '\x03') || (cVar2 == '\x04')) {
      bVar4 = (*(byte *)((longlong)param_1 + 0x41) & 2) == 0;
    }
    else {
      if (cVar2 != '\f') goto LAB_14001bf07;
      bVar4 = *(char *)((longlong)param_1 + 0x41) == '\x01';
    }
    if ((bVar4) && (*(longlong *)(*(longlong *)(param_1 + 4) + 8) == 0)) {
      CdCreateUserMdl((longlong)param_1,(ulonglong)*(uint *)(*(longlong *)(param_2 + 0xb8) + 8));
    }
  }
LAB_14001bf07:
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 2;
  CdCleanupIrpContext((undefined8 *)param_1,'\x01');
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  return;
}



===== CdCommonWrite @ 14001bf34 =====

uint CdCommonWrite(short *param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  short *psVar11;
  uint local_res18;
  uint local_res20;
  longlong local_e0;
  longlong local_d0;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined4 uStack_88;
  ulonglong local_78;
  uint local_70;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  uVar4 = *(uint *)(lVar1 + 8);
  if (uVar4 == 0) {
    CdCompleteRequest((undefined8 *)param_1,param_2,0);
    return 0;
  }
  lVar6 = *(longlong *)(lVar1 + 0x30);
  uVar8 = *(uint *)(lVar6 + 0x20) & 7;
  if (uVar8 == 0) {
    psVar11 = (short *)0x0;
    uVar9 = 0;
  }
  else {
    psVar11 = *(short **)(lVar6 + 0x18);
    uVar9 = *(ulonglong *)(lVar6 + 0x20) & 0xfffffffffffffff8;
  }
  if (uVar8 != 2) {
    uVar4 = 0xc0000010;
    goto LAB_14001bfde;
  }
  uVar10 = *(uint *)(param_1 + 0x10) & 4;
  uVar8 = *(uint *)(lVar6 + 0x50);
  uVar2 = *(ulonglong *)(lVar1 + 0x18);
  local_d0 = uVar2 + uVar4;
  CdAcquireResource((longlong)param_1,*(ulonglong *)(psVar11 + 4),'\0',1);
  bVar3 = true;
  if ((*(uint *)(uVar9 + 4) & 0x10) == 0) {
    CdVerifyFcbOperation((longlong)param_1,(longlong)psVar11);
  }
  local_res18 = uVar4;
  if ((*(uint *)(uVar9 + 4) & 0x20) == 0) {
    lVar6 = *(longlong *)(psVar11 + 0x10);
    if ((longlong)uVar2 < lVar6) {
      if (lVar6 < local_d0) {
        local_res18 = *(int *)(psVar11 + 0x10) - (uint)uVar2;
        local_d0 = lVar6;
      }
      goto LAB_14001c087;
    }
    uVar4 = 0xc0000011;
  }
  else {
LAB_14001c087:
    local_res20 = *(int *)(*(longlong *)(psVar11 + 0x3c) + 0x1b8) + local_res18 &
                  *(uint *)(*(longlong *)(psVar11 + 0x3c) + 0x1bc);
    if (((((uint)uVar2 | local_res20) & 0x7ff) != 0) || (uVar4 < local_res20)) {
      if (uVar10 == 0) {
                    /* WARNING: Subroutine does not return */
        CdRaiseStatusEx((longlong)param_1,0xc00000d8,'\0',0x170000,0xd7);
      }
      local_res20 = local_res18;
    }
    puVar5 = *(undefined8 **)(param_1 + 0x18);
    if ((puVar5 == (undefined8 *)0x0) || ((*(uint *)(param_1 + 0x10) & 0x100) == 0)) {
      if (uVar10 == 0) {
        puVar5 = (undefined8 *)ExAllocatePoolWithTag(0x610,0x30,0x6f696443);
        *(undefined8 **)(param_1 + 0x18) = puVar5;
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100;
      }
      else {
        *(undefined8 **)(param_1 + 0x18) = &local_b0;
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffeff;
        puVar5 = &local_b0;
      }
    }
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    *(byte *)(*(longlong *)(param_1 + 0x18) + 0x14) =
         (byte)((uint)*(undefined4 *)(param_1 + 0x10) >> 8) & 1;
    if (uVar10 == 0) {
      *(void **)(*(longlong *)(param_1 + 0x18) + 0x20) = SystemReserved1[0xf];
      *(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x18) = *(undefined8 *)(psVar11 + 4);
      *(uint *)(*(longlong *)(param_1 + 0x18) + 0x28) = local_res18;
      local_e0 = local_d0;
    }
    else {
      KeInitializeEvent(*(longlong *)(param_1 + 0x18) + 0x18,0,0);
      local_e0 = local_d0;
    }
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res20;
    *(uint *)(*(longlong *)(lVar1 + 0x30) + 0x50) =
         *(uint *)(*(longlong *)(lVar1 + 0x30) + 0x50) | 0x1000;
    if (*(longlong *)(*(longlong *)(param_1 + 4) + 8) == 0) {
      CdCreateUserMdl((longlong)param_1,(ulonglong)local_res20);
    }
    memset(&local_78,0,0x40);
    local_78 = uVar2;
    local_70 = local_res20;
    CdSingleAsync((longlong)param_1,&local_78,psVar11);
    if ((*(uint *)(param_1 + 0x10) & 4) == 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffeff;
      uVar4 = 0x103;
    }
    else {
      CdWaitSync((longlong)param_1);
      uVar4 = *(uint *)(*(longlong *)(param_1 + 4) + 0x30);
    }
    if (uVar4 == 0x103) {
      param_2 = 0;
      bVar3 = false;
    }
    else {
      if ((int)uVar4 < 0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        if ((((uVar4 + 0x3fffff5e < 2) || (uVar4 == 0xc00000b5)) || (uVar4 + 0x3fffffee < 3)) ||
           (uVar4 == 0x80000016)) {
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx((longlong)param_1,uVar4,'\0',0x170000,0x146);
        }
        uVar4 = FsRtlNormalizeNtstatus(uVar4,0xc00000e9);
      }
      else if (local_res20 != local_res18) {
        lVar6 = *(longlong *)(*(longlong *)(param_1 + 4) + 8);
        if (lVar6 == 0) {
          lVar6 = *(longlong *)(*(longlong *)(param_1 + 4) + 0x70);
        }
        else if ((*(byte *)(lVar6 + 10) & 5) == 0) {
          lVar6 = MmMapLockedPagesSpecifyCache();
        }
        else {
          lVar6 = *(longlong *)(lVar6 + 0x18);
        }
        if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
          CdRaiseStatusEx((longlong)param_1,0xc000009a,'\0',0x170000,0x151);
        }
        memset((void *)((ulonglong)local_res18 + lVar6),0,(ulonglong)(local_res20 - local_res18));
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res18;
      }
      if (((uVar8 & 2) != 0) && (-1 < (int)uVar4)) {
        *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x68) = local_e0;
      }
    }
  }
  if (bVar3) {
    ExReleaseResourceLite(*(undefined8 *)(psVar11 + 4));
  }
  if (uVar4 == 0xc00000d8) {
    uVar7 = CdFsdPostRequest(param_1,param_2);
    return (uint)uVar7;
  }
LAB_14001bfde:
  CdCompleteRequest((undefined8 *)param_1,param_2,uVar4);
  return uVar4;
}



===== CdCommonShutdown @ 14001c3e8 =====

undefined8 CdCommonShutdown(short *param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x200;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeInitializeEvent(&local_38,0);
  DAT_14000836e = DAT_14000836e | 1;
  ExAcquireResourceExclusiveLite(&DAT_1400083d0,1);
  puVar1 = DAT_140008330;
  while (puVar5 = puVar1, (undefined8 **)puVar5 != &DAT_140008330) {
    puVar1 = (undefined8 *)*puVar5;
    if (((*(uint *)(puVar5 + 2) & 0x400) == 0) && (*(int *)((longlong)puVar5 + 0x14) == 2)) {
      CdAcquireResource((longlong)param_1,(ulonglong)(puVar5 + 0xc),'\0',0);
      CdPurgeVolume(param_1,(longlong)(puVar5 + -4),'\0');
      lVar4 = IoBuildSynchronousFsdRequest(0x10,puVar5[-2],0,0,0,&local_38,&local_48);
      if (lVar4 != 0) {
        iVar3 = IofCallDriver(puVar5[-2],lVar4);
        if (iVar3 == 0x103) {
          KeWaitForSingleObject(&local_38,0,0,0,0);
        }
        KeClearEvent(&local_38);
      }
      *(uint *)(puVar5 + 2) = *(uint *)(puVar5 + 2) | 0x400;
      cVar2 = CdCheckForDismount((longlong)param_1,(longlong)(puVar5 + -4),'\0');
      if (cVar2 != '\0') {
        ExReleaseResourceLite(puVar5 + 0xc);
      }
    }
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  IoUnregisterFileSystem(DAT_140008350);
  IoDeleteDevice(DAT_140008350);
  CdCompleteRequest((undefined8 *)param_1,param_2,0);
  return 0;
}



===== CdTelemetryMount @ 14001c5c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdTelemetryMount(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  bool bVar1;
  undefined8 uVar2;
  byte *pbVar3;
  undefined1 auStackY_a8 [32];
  undefined4 uVar4;
  undefined4 local_78;
  int local_74 [3];
  undefined8 local_68 [4];
  undefined8 local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  int *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_3 == 0) {
    if (DAT_140008020 < 6) {
      return;
    }
    if (((_DAT_140008030 & 0x200000000000) == 0) ||
       (bVar1 = true, (DAT_140008038 & 0x200000000000) != DAT_140008038)) {
      bVar1 = false;
    }
    if (!bVar1) {
      return;
    }
    pbVar3 = &DAT_140006349;
    uVar4 = 4;
    uVar2 = 4;
  }
  else {
    if (DAT_140008020 < 6) {
      return;
    }
    if (((_DAT_140008030 & 0x200000000000) == 0) ||
       (bVar1 = true, (DAT_140008038 & 0x200000000000) != DAT_140008038)) {
      bVar1 = false;
    }
    if (!bVar1) {
      return;
    }
    pbVar3 = &DAT_140006311;
    local_74[0] = *(int *)(param_3 + 0x1b4) * *(int *)(param_3 + 0x1a8);
    local_20 = 4;
    local_28 = local_74;
    uVar4 = 5;
    uVar2 = param_1;
  }
  local_30 = 4;
  local_38 = &local_78;
  local_40 = 0x10;
  local_78 = 0;
  local_48 = param_1;
  _tlgWriteTransfer_EtwWriteTransfer(uVar2,pbVar3,param_3,param_4,uVar4,local_68);
  return;
}



===== _tlgEnableCallback @ 14001c710 =====

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



===== CdLookupAllocation$fin$0 @ 14001c78a =====

void CdLookupAllocation_fin_0(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  
  if (*(char *)(param_2 + 0x31) != '\0') {
    ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8));
    if (*(longlong *)(param_2 + 0x80) != 0) {
      CcUnpinData();
      *(undefined8 *)(param_2 + 0x80) = 0;
    }
    if (((*(byte *)(param_2 + 0xa9) & 1) != 0) && (*(longlong *)(param_2 + 0xd0) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0xd0),0);
    }
  }
  if (*(char *)(param_2 + 0x30) != '\0') {
    lVar2 = *(longlong *)(param_2 + 0x178);
    piVar1 = (int *)(lVar2 + 0xc0);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined8 *)(lVar2 + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
    }
  }
  return;
}



===== CdCreateInternalStream$fin$0 @ 14001c837 =====

void CdCreateInternalStream_fin_0(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (*(char *)(param_2 + 0x30) != '\0') {
    if (*(longlong *)(param_2 + 0x68) != 0) {
      CcUnpinData();
      *(undefined8 *)(param_2 + 0x68) = 0;
    }
    if (((*(byte *)(param_2 + 0x99) & 1) != 0) && (*(longlong *)(param_2 + 0xc0) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0xc0),0);
      *(undefined8 *)(param_2 + 0xc0) = 0;
    }
  }
  lVar3 = *(longlong *)(param_2 + 0x38);
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_2 + 0x50);
  }
  else {
    *(undefined8 *)(lVar3 + 0x60) = 0;
    *(undefined4 *)(lVar3 + 0x58) = 0;
    ObfDereferenceObject();
    lVar3 = *(longlong *)(param_2 + 0x50);
    *(undefined8 *)(lVar3 + 0x1d8) = 0;
  }
  if (*(char *)(param_2 + 0x32) != '\0') {
    lVar2 = *(longlong *)(param_2 + 0x40);
    ExAcquireFastMutex(lVar2 + 0x150);
    *(void **)(lVar2 + 0x188) = SystemReserved1[0xf];
    *(int *)(lVar3 + 0xa4) = *(int *)(lVar3 + 0xa4) + -1;
    *(int *)(*(longlong *)(lVar3 + 0x78) + 0x3c) = *(int *)(*(longlong *)(lVar3 + 0x78) + 0x3c) + -1
    ;
    *(undefined8 *)(lVar2 + 0x188) = 0;
    ExReleaseFastMutex(lVar2 + 0x150);
  }
  piVar1 = (int *)(lVar3 + 0xc0);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined8 *)(lVar3 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(lVar3 + 200) + 0x88);
  }
  return;
}



===== CdCommonCreate$fin$0 @ 14001c954 =====

void CdCommonCreate_fin_0(longlong param_1,longlong param_2)

{
  short *psVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = (char)param_1;
  if (*(char *)(param_2 + 0x59) != '\0') {
    param_1 = *(longlong *)(param_2 + 0x110);
    if (param_1 != 0) {
      CcUnpinData();
      *(undefined8 *)(param_2 + 0x110) = 0;
    }
    if ((*(char *)(param_2 + 0x11c) != '\0') &&
       (param_1 = *(longlong *)(param_2 + 0x100), param_1 != 0)) {
      ExFreePoolWithTag(param_1,0);
      *(undefined8 *)(param_2 + 0x100) = 0;
    }
    if (((*(byte *)(param_2 + 0x140) & 1) != 0) &&
       (param_1 = *(longlong *)(param_2 + 0x150), param_1 != 0)) {
      ExFreePoolWithTag(param_1,0);
      *(undefined8 *)(param_2 + 0x150) = 0;
    }
  }
  if (*(char *)(param_2 + 0x50) != '\0') {
    CdCleanupFileContext(param_1,param_2 + 0x1d0);
  }
  if (cVar2 == '\0') {
    uVar3 = *(uint *)(param_2 + 0x54);
    if (uVar3 != 0x103) goto LAB_14001ca4e;
  }
  else {
    psVar1 = *(short **)(param_2 + 0x60);
    if ((psVar1 != (short *)0x0) && (psVar1 != *(short **)(*(longlong *)(param_2 + 0xd0) + 0x48))) {
      *(undefined1 *)(param_2 + 0x58) = 0;
      CdTeardownStructures(*(short **)(param_2 + 0x90),psVar1,(undefined1 *)(param_2 + 0x58));
      if (*(char *)(param_2 + 0x58) != '\0') {
        *(undefined8 *)(param_2 + 0x60) = 0;
      }
    }
    uVar3 = *(uint *)(param_2 + 0x54);
  }
  *(undefined8 *)(param_2 + 0x90) = 0;
  *(undefined8 *)(param_2 + 0x98) = 0;
LAB_14001ca4e:
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x60) + 200) + 0x20);
  }
  ExReleaseResourceLite(*(longlong *)(param_2 + 0xd0) + 0x80);
  CdCompleteRequest(*(undefined8 **)(param_2 + 0x90),*(longlong *)(param_2 + 0x98),uVar3);
  return;
}



===== CdOpenByFileId$fin$0 @ 14001caab =====

void CdOpenByFileId_fin_0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x40) != '\0') {
    lVar1 = *(longlong *)(param_2 + 0x78);
    *(undefined8 *)(lVar1 + 0x188) = 0;
    param_1 = lVar1 + 0x150;
    ExReleaseFastMutex();
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    CdCleanupFileContext(param_1,param_2 + 0x150);
  }
  if (*(char *)(param_2 + 0x42) != '\0') {
    if (*(longlong *)(param_2 + 0x90) != 0) {
      CcUnpinData();
      *(undefined8 *)(param_2 + 0x90) = 0;
    }
    if ((*(char *)(param_2 + 0x9c) != '\0') && (*(longlong *)(param_2 + 0x80) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
      *(undefined8 *)(param_2 + 0x80) = 0;
    }
    if (((*(byte *)(param_2 + 0xc0) & 1) != 0) && (*(longlong *)(param_2 + 0xd0) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0xd0),0);
    }
  }
  return;
}



===== CdOpenDirectoryFromPathEntry$fin$0 @ 14001cb6f =====

void CdOpenDirectoryFromPathEntry_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x40) != '\0') {
    lVar1 = *(longlong *)(param_2 + 0xa0);
    *(undefined8 *)(lVar1 + 0x188) = 0;
    ExReleaseFastMutex(lVar1 + 0x150);
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x58) + 200) + 0x20);
  }
  return;
}



===== CdOpenFileFromFileContext$fin$0 @ 14001cbcf =====

void CdOpenFileFromFileContext_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x40) != '\0') {
    lVar1 = *(longlong *)(param_2 + 0xb0);
    *(undefined8 *)(lVar1 + 0x188) = 0;
    ExReleaseFastMutex(lVar1 + 0x150);
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x50) + 200) + 0x20);
  }
  return;
}



===== CdNonCachedRead$fin$0 @ 14001cc2f =====

void CdNonCachedRead_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x54) != 0) {
    CdFinishBuffers(*(longlong *)(param_2 + 0x80),param_2 + 0xa0,*(int *)(param_2 + 0x54),'\x01',
                    '\0');
  }
  return;
}



===== CdNonCachedXARead$fin$0 @ 14001cc6a =====

void CdNonCachedXARead_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x5c) != 0) {
    CdFinishBuffers(*(longlong *)(param_2 + 0x98),param_2 + 0x120,*(int *)(param_2 + 0x5c),'\x01',
                    '\0');
  }
  return;
}



===== CdReadDirDataThroughCache$fin$0 @ 14001cca5 =====

void CdReadDirDataThroughCache_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0xd0) + 0x10) + 0x2a8);
  return;
}



===== CdNotifyChangeDirectory$fin$0 @ 14001ccda =====

void CdNotifyChangeDirectory_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x60) + 0x10) + 0x80);
  return;
}



===== CdQueryDirectory$fin$0 @ 14001cd09 =====

void CdQueryDirectory_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  CdCleanupFileContext(param_1,param_2 + 0xd0);
  pvVar2 = SystemReserved1[0xf];
  if ((*(char *)(param_2 + 0x41) == '\0') ||
     ((*(uint *)(param_2 + 0x44) & 0xc0000000) == 0xc0000000)) {
    lVar5 = *(longlong *)(param_2 + 0x90);
  }
  else {
    lVar5 = *(longlong *)(param_2 + 0x90);
    if (SystemReserved1[0xf] != *(void **)(lVar5 + 0xb8)) {
      ExAcquireFastMutex(*(longlong *)(lVar5 + 200) + 0x88);
      *(void **)(lVar5 + 0xb8) = pvVar2;
    }
    *(int *)(lVar5 + 0xc0) = *(int *)(lVar5 + 0xc0) + 1;
    lVar1 = *(longlong *)(param_2 + 0x98);
    *(undefined4 *)(lVar1 + 0x10) = **(undefined4 **)(param_2 + 0x88);
    uVar3 = *(uint *)(lVar1 + 4) & 0xffefffff;
    *(uint *)(lVar1 + 4) = uVar3;
    if (*(char *)(param_2 + 0x40) != '\0') {
      *(uint *)(lVar1 + 4) = uVar3 | 0x100000;
    }
    iVar4 = *(int *)(lVar5 + 0xc0) + -1;
    *(int *)(lVar5 + 0xc0) = iVar4;
    if (iVar4 == 0) {
      *(undefined8 *)(lVar5 + 0xb8) = 0;
      ExReleaseFastMutex(*(longlong *)(lVar5 + 200) + 0x88);
    }
  }
  ExReleaseResourceLite(*(undefined8 *)(lVar5 + 8));
  return;
}



===== CdCommonQueryInfo$fin$0 @ 14001ce03 =====

void CdCommonQueryInfo_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x38) + 8));
  }
  return;
}



===== CdCommonSetInfo$fin$0 @ 14001ce34 =====

void CdCommonSetInfo_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 8));
  return;
}



===== CdFastQueryBasicInfo$fin$0 @ 14001ce5f =====

void CdFastQueryBasicInfo_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8));
  KeLeaveCriticalRegion();
  return;
}



===== CdQueryAlternateNameInfo$fin$0 @ 14001ce96 =====

void CdQueryAlternateNameInfo_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x30) == '\0') {
    if (*(char *)(param_2 + 0x31) != '\0') {
      lVar1 = *(longlong *)(param_2 + 0x80);
      if (lVar1 != 0) {
        CcUnpinData();
        *(undefined8 *)(param_2 + 0x80) = 0;
      }
      if ((*(char *)(param_2 + 0x8c) != '\0') && (lVar1 = *(longlong *)(param_2 + 0x70), lVar1 != 0)
         ) {
        ExFreePoolWithTag(lVar1,0);
        *(undefined8 *)(param_2 + 0x70) = 0;
      }
      if (((*(byte *)(param_2 + 0xb0) & 1) != 0) &&
         (lVar1 = *(longlong *)(param_2 + 0xc0), lVar1 != 0)) {
        ExFreePoolWithTag(lVar1,0);
        *(undefined8 *)(param_2 + 0xc0) = 0;
      }
      CdCleanupFileContext(lVar1,param_2 + 0x140);
    }
  }
  else {
    if (*(longlong *)(param_2 + 0x50) != 0) {
      CcUnpinData();
      *(undefined8 *)(param_2 + 0x50) = 0;
    }
    if (((*(byte *)(param_2 + 0x459) & 1) != 0) && (*(longlong *)(param_2 + 0x480) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x480),0);
      *(undefined8 *)(param_2 + 0x480) = 0;
    }
  }
  if (*(char *)(param_2 + 0x32) != '\0') {
    ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x38) + 8));
  }
  return;
}



===== CdFindPrimaryVd$fin$0 @ 14001cfa2 =====

void CdFindPrimaryVd_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0);
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  return;
}



===== CdLockVolume$fin$0 @ 14001cfd4 =====

undefined8 CdLockVolume_fin_0(char param_1,longlong param_2)

{
  undefined8 uVar1;
  
  ExReleaseResourceLite(*(longlong *)(param_2 + 0x58) + 0x80);
  if ((param_1 != '\0') || (uVar1 = 0, *(int *)(param_2 + 0x20) < 0)) {
    uVar1 = FsRtlNotifyVolumeEvent(*(undefined8 *)(*(longlong *)(param_2 + 0x60) + 0x30),4);
  }
  return uVar1;
}



===== CdMountVolume$fin$0 @ 14001d029 =====

void CdMountVolume_fin_0(char param_1,longlong param_2)

{
  longlong lVar1;
  short *psVar2;
  char cVar3;
  
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
    *(undefined8 *)(param_2 + 0x78) = 0;
  }
  if (*(longlong *)(param_2 + 0x98) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x98),0);
    *(undefined8 *)(param_2 + 0x98) = 0;
  }
  if (((param_1 != '\0') || (*(int *)(param_2 + 0x54) != 0)) && (*(char *)(param_2 + 0x51) != '\0'))
  {
    lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xd0) + 0x28);
    *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 2;
  }
  if (*(longlong *)(param_2 + 200) != 0) {
    *(undefined8 *)(*(longlong *)(param_2 + 200) + 8) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0xa0);
  if (lVar1 == 0) {
    if (*(longlong *)(param_2 + 0x60) != 0) {
      IoDeleteDevice();
    }
  }
  else {
    psVar2 = *(short **)(param_2 + 0xd0);
    psVar2[8] = 0;
    psVar2[9] = 0;
    psVar2[10] = 0;
    psVar2[0xb] = 0;
    *(int *)(lVar1 + 0x3c) = *(int *)(lVar1 + 0x3c) + -6;
    cVar3 = CdDismountVcb(psVar2,lVar1);
    if (cVar3 != '\0') {
      ExReleaseResourceLite(lVar1 + 0x80);
    }
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  return;
}



===== CdOplockRequest$fin$0 @ 14001d120 =====

void CdOplockRequest_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x60) + 200) + 0x20);
  return;
}



===== CdVerifyVolume$fin$0 @ 14001d152 =====

void CdVerifyVolume_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x68),0);
    *(undefined8 *)(param_2 + 0x68) = 0;
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
    *(undefined8 *)(param_2 + 0x78) = 0;
  }
  if (*(char *)(param_2 + 0x40) != '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0xb8) + 0x80);
  }
  ExReleaseResourceLite(&DAT_1400083d0);
  return;
}



===== CdFastLock$fin$0 @ 14001d1d2 =====

void CdFastLock_fin_0(void)

{
  KeLeaveCriticalRegion();
  return;
}



===== CdFastUnlockAll$fin$0 @ 14001d1f5 =====

void CdFastUnlockAll_fin_0(void)

{
  KeLeaveCriticalRegion();
  return;
}



===== CdFastUnlockAllByKey$fin$0 @ 14001d218 =====

void CdFastUnlockAllByKey_fin_0(void)

{
  KeLeaveCriticalRegion();
  return;
}



===== CdFastUnlockSingle$fin$0 @ 14001d23b =====

void CdFastUnlockSingle_fin_0(void)

{
  KeLeaveCriticalRegion();
  return;
}



===== CdCommonRead$fin$0 @ 14001d25e =====

void CdCommonRead_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x70) + 8));
  }
  return;
}



===== CdInitializeFcbFromFileContext$fin$0 @ 14001d28f =====

void CdInitializeFcbFromFileContext_fin_0(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  piVar1 = (int *)(lVar2 + 0xc0);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined8 *)(lVar2 + 0xb8) = 0;
    ExReleaseFastMutex(*(longlong *)(lVar2 + 200) + 0x88);
  }
  return;
}



===== CdInitializeVcb$fin$0 @ 14001d2d5 =====

void CdInitializeVcb_fin_0(char param_1,longlong param_2)

{
  if (param_1 != '\0') {
    FsRtlNotifyUninitializeSync(*(longlong *)(param_2 + 0x48) + 400);
  }
  return;
}



===== CdTeardownStructures$fin$0 @ 14001d307 =====

void CdTeardownStructures_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((*(char *)(param_2 + 0x20) != '\0') && (*(longlong *)(param_2 + 0x28) != 0)) {
    ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x28) + 200) + 0x20);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x90) + 0x38);
  *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) & 0xffffff7f;
  return;
}



===== CdUpdateVcbFromVolDescriptor$fin$0 @ 14001d359 =====

void CdUpdateVcbFromVolDescriptor_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x30) != '\0') {
    lVar1 = *(longlong *)(param_2 + 0x128);
    *(undefined8 *)(lVar1 + 0x188) = 0;
    ExReleaseFastMutex(lVar1 + 0x150);
  }
  return;
}



===== CdCommonQueryVolInfo$fin$0 @ 14001d398 =====

void CdCommonQueryVolInfo_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseResourceLite(*(longlong *)(*(longlong *)(param_2 + 0x58) + 0x78) + 0x80);
  return;
}



===== CdCommonWrite$fin$0 @ 14001d3c7 =====

void CdCommonWrite_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    ExReleaseResourceLite(*(undefined8 *)(*(longlong *)(param_2 + 0x58) + 8));
  }
  return;
}



===== entry @ 14001e010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001e044 =====

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



===== CdInitializeGlobalData @ 14001e078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CdInitializeGlobalData(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  memset(&CdFastIoDispatch,0,0xe0);
  _DAT_140008278 = 0;
  _DAT_140008228 = CdFastIoCheckIfPossible;
  _DAT_140008230 = FsRtlCopyRead_exref;
  _CdFastIoDispatch = 0xe0;
  _DAT_140008240 = CdFastQueryBasicInfo;
  _DAT_140008248 = CdFastQueryStdInfo;
  _DAT_140008250 = CdFastLock;
  _DAT_140008258 = CdFastUnlockSingle;
  _DAT_140008260 = CdFastUnlockAll;
  _DAT_140008268 = CdFastUnlockAllByKey;
  _DAT_140008280 = CdReleaseForCreateSection;
  _DAT_140008290 = CdFastQueryNetworkInfo;
  _DAT_1400082a0 = FsRtlMdlReadDev_exref;
  _DAT_1400082a8 = FsRtlMdlReadCompleteDev_exref;
  _DAT_1400082b0 = FsRtlPrepareMdlWriteDev_exref;
  _DAT_1400082b8 = FsRtlMdlWriteCompleteDev_exref;
  memset(&CdData,0,0x160);
  _CdData = 0x1600301;
  _DAT_140008338 = &DAT_140008330;
  DAT_140008330 = &DAT_140008330;
  DAT_140008328 = param_1;
  DAT_140008350 = param_2;
  ExInitializeResourceLite(&DAT_1400083d0);
  _DAT_1400083a0 = 0;
  _DAT_1400083a8 = 0;
  _DAT_140008438 = CdAcquireForCache;
  _DAT_140008448 = CdAcquireForCache;
  _DAT_140008440 = CdReleaseFromCache;
  _DAT_140008450 = CdReleaseFromCache;
  _DAT_140008458 = CdNoopAcquire;
  _DAT_140008468 = CdNoopAcquire;
  _DAT_140008460 = CdNoopRelease;
  _DAT_140008470 = CdNoopRelease;
  _DAT_140008398 = 1;
  KeInitializeEvent(&DAT_1400083b0,1,0);
  DAT_140008360 = &DAT_140008358;
  DAT_140008358 = &DAT_140008358;
  DAT_140008378 = &DAT_140008370;
  DAT_140008370 = &DAT_140008370;
  DAT_140008478 = IoAllocateWorkItem(param_2);
  if (DAT_140008478 == 0) {
    ExDeleteResourceLite(&DAT_1400083d0);
    uVar2 = 0xc000009a;
  }
  else {
    iVar1 = MmQuerySystemSize();
    if (iVar1 == 0) {
      DAT_140008344 = 4;
      DAT_140008384 = 8;
      DAT_140008388 = 2;
    }
    else if (iVar1 == 1) {
      DAT_140008344 = 8;
      DAT_140008384 = 0x18;
      DAT_140008388 = 6;
    }
    else if (iVar1 == 2) {
      DAT_140008344 = 0x20;
      DAT_140008384 = 0x48;
      DAT_140008388 = 0x12;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== DriverEntry @ 14001e340 =====

ulonglong DriverEntry(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_res18;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88 [2];
  code *local_80;
  
  local_98 = 0;
  uStack_90 = 0;
  local_res18 = 0;
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&local_98);
  uVar1 = IoCreateDevice(param_1,0,&local_98,3,0,0,&local_res18);
  if (-1 < (int)uVar1) {
    *(code **)(param_1 + 0xf0) = CdFsdDispatch;
    *(code **)(param_1 + 0x148) = CdFsdDispatch;
    *(code **)(param_1 + 0x100) = CdFsdDispatch;
    *(code **)(param_1 + 0xf8) = CdFsdDispatch;
    *(code **)(param_1 + 0xe0) = CdFsdDispatch;
    *(code **)(param_1 + 0xd8) = CdFsdDispatch;
    *(code **)(param_1 + 0xd0) = CdFsdDispatch;
    *(code **)(param_1 + 0xc0) = CdFsdDispatch;
    *(code **)(param_1 + 0xa0) = CdFsdDispatch;
    *(code **)(param_1 + 0x98) = CdFsdDispatch;
    *(code **)(param_1 + 0x90) = CdFsdDispatch;
    *(code **)(param_1 + 0x88) = CdFsdDispatch;
    *(code **)(param_1 + 0x80) = CdFsdDispatch;
    *(code **)(param_1 + 0x70) = CdFsdDispatch;
    *(undefined **)(param_1 + 0x50) = &CdFastIoDispatch;
    memset(local_88,0,0x78);
    local_88[0] = 0x78;
    local_80 = CdFilterCallbackAcquireForCreateSection;
    uVar1 = FsRtlRegisterFileSystemFilterCallbacks(param_1,local_88);
    if (-1 < (int)uVar1) {
      uVar2 = CdInitializeGlobalData(param_1,local_res18);
      if (-1 < (int)uVar2) {
        *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | 0x10000;
        IoRegisterFileSystem(local_res18);
        ObfReferenceObject(local_res18);
        CdInitializeTelemetry();
        return 0;
      }
      IoDeleteDevice(local_res18);
      if (g_wil_details_featureChangeNotification != 0) {
        RtlUnregisterFeatureConfigurationChangeNotification();
        g_wil_details_featureChangeNotification = 0;
      }
      if (g_wil_details_featureUsageProvider != 0) {
        RtlUnregisterFeatureUsageProvider();
        g_wil_details_featureUsageProvider = 0;
      }
      g_wil_details_isFeatureStagingInitialized = 0;
      return uVar2 & 0xffffffff;
    }
    IoDeleteDevice(local_res18);
  }
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return (ulonglong)uVar1;
}



===== wil_InitializeFeatureStaging @ 14001e580 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e607;
    }
LAB_14001e641:
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
LAB_14001e607:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e641;
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
    goto LAB_14001e641;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400079c7 < ppuVar3) goto LAB_14001e641;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e607;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001e694 =====

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
            if (&UNK_1400079c7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001e77e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001e77e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001e77e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400079c7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== CdInitializeTelemetry @ 14001e810 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CdInitializeTelemetry(void)

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
  _CdTelemetryData = 0;
  uRam0000000140008318 = 0;
  _DAT_140008308 = _DAT_fffff78000000014;
  _DAT_140008310 = _DAT_fffff78000000320;
  local_28 = *(undefined4 *)(PTR_DAT_140008028 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140008028 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140008028 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140008028 + -4);
  if (DAT_140008040 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140008048 = 0;
  uRam0000000140008050 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14001e8aa;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140008020,&DAT_140008040);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140008028;
    *(undefined8 *)(puVar4 + -8) = 0x14001e8cf;
    EtwSetInformation(DAT_140008040,2,PTR_DAT_140008028,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001e8e1;
  return;
}


