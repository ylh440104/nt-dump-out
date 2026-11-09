
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== BugCheckSecondaryDumpDataCallback @ 140001030 =====

void BugCheckSecondaryDumpDataCallback
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 param_4)

{
  IptLogPrint(3,"[%s] Entered\n","BugCheckSecondaryDumpDataCallback",param_4);
  if (DAT_1400073f8 == 0) {
    if (DAT_1400073e4 == 2) {
      BugCheckSecondaryDumpDataCollectCoreTraceMetadata(param_3);
    }
    else {
      IptLogPrint(1,"[%s] ThreadCount == %u, CoreTracing == %u, IptCoreTracingControlBlock = %p\n",
                  "BugCheckSecondaryDumpDataCallback",0);
    }
  }
  else {
    BugCheckSecondaryDumpDataCollectThreadTraceMetadata(param_3);
  }
  return;
}



===== BugCheckSecondaryDumpDataCollectCoreTraceMetadata @ 1400010b4 =====

void BugCheckSecondaryDumpDataCollectCoreTraceMetadata(longlong *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  lVar3 = IptCoreTracingControlBlock;
  uVar8 = *(uint *)((longlong)param_1 + 0xc);
  uVar1 = *(uint *)(IptCoreTracingControlBlock + 0x5c);
  if ((uVar8 < 8) || ((ulonglong)uVar8 - 8 < (ulonglong)uVar1)) {
    pcVar6 = "[%s] SecondaryDump->MaximumAllowed == %u, IptSecondaryDumpDataSize = %u\n";
    uVar4 = 1;
  }
  else {
    if (param_1[4] == 0) {
      param_1[4] = *(longlong *)(IptCoreTracingControlBlock + 0x50);
      *(undefined4 *)(param_1 + 5) = *(undefined4 *)(lVar3 + 0x58);
      IptLogPrint(2,"[%s] Size request. SecondaryDump->OutBufferLength = %u\n",
                  "BugCheckSecondaryDumpDataCollectCoreTraceMetadata",
                  (ulonglong)*(uint *)(lVar3 + 0x58));
      return;
    }
    if (param_1[4] != *param_1) {
      return;
    }
    puVar2 = *(undefined4 **)(IptCoreTracingControlBlock + 0x50);
    uVar9 = 8;
    param_1[4] = (longlong)puVar2;
    *(undefined4 *)(param_1 + 2) = 0xc712af3d;
    *(undefined4 *)((longlong)param_1 + 0x14) = 0x46a9ed1e;
    *(undefined4 *)(param_1 + 3) = 0x1e943b8;
    *(undefined4 *)((longlong)param_1 + 0x1c) = 0xeeca294d;
    if (*(uint *)(lVar3 + 0x58) <= uVar8) {
      uVar8 = *(uint *)(lVar3 + 0x58);
    }
    uVar4 = KeGetCurrentProcessorNumberEx(0);
    if ((uVar4 < *(uint *)(IptCoreTracingControlBlock + 0x60)) &&
       (uVar5 = WriteCoreTraceMetadataV1((undefined8 *)(puVar2 + 2),uVar4), -1 < (int)uVar5)) {
      uVar9 = uVar1 + 8;
    }
    uVar7 = 0;
    if (*(int *)(IptCoreTracingControlBlock + 0x60) != 0) {
      do {
        if (uVar8 - uVar9 < uVar1) break;
        if ((uVar7 != uVar4) &&
           (uVar5 = WriteCoreTraceMetadataV1
                              ((undefined8 *)((ulonglong)uVar9 + (longlong)puVar2),uVar7),
           -1 < (int)uVar5)) {
          uVar9 = uVar9 + uVar1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(IptCoreTracingControlBlock + 0x60));
    }
    uVar4 = 2;
    if ((ulonglong)uVar9 - 8 < (ulonglong)uVar1) {
      *(undefined4 *)(param_1 + 5) = 0;
    }
    else {
      *(uint *)(param_1 + 5) = uVar9;
      *puVar2 = 0x20001;
      puVar2[1] = (int)param_1[5] + -8;
    }
    pcVar6 = 
    "[%s] Data request. SecondaryDump->OutBufferLength = %u, SecondaryDump->OutBuffer = %p\n";
    uVar8 = *(uint *)(param_1 + 5);
  }
  IptLogPrint(uVar4,pcVar6,"BugCheckSecondaryDumpDataCollectCoreTraceMetadata",(ulonglong)uVar8);
  return;
}



===== BugCheckSecondaryDumpDataCollectThreadTraceMetadata @ 14000125c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BugCheckSecondaryDumpDataCollectThreadTraceMetadata(longlong *param_1)

{
  if (*(uint *)((longlong)param_1 + 0xc) < 0x2c) {
    IptLogPrint(1,"[%s] SecondaryDump->MaximumAllowed == %u, IptSecondaryDumpDataSize = %u\n",
                "BugCheckSecondaryDumpDataCollectThreadTraceMetadata",
                (ulonglong)*(uint *)((longlong)param_1 + 0xc));
  }
  else {
    *(undefined4 *)(param_1 + 5) = 0x2c;
    if (param_1[4] == 0) {
      param_1[4] = (longlong)&DAT_1400074d0;
      IptLogPrint(2,"[%s] Size request. SecondaryDump->OutBufferLength = %u\n",
                  "BugCheckSecondaryDumpDataCollectThreadTraceMetadata",0x2c);
    }
    else if (param_1[4] == *param_1) {
      param_1[4] = (longlong)&DAT_1400074d0;
      _DAT_1400074e8 = PRatio;
      param_1[2] = 0x46a9ed1ec712af3d;
      param_1[3] = -0x1135d6b2fe16bc48;
      _DAT_1400074f0 = DAT_1400073fc;
      _DAT_1400074f4 = DAT_140007400;
      _DAT_1400074d0 = 0x30001;
      _DAT_1400074d4 = 0x24;
      _DAT_1400074d8 = _IptCapability;
      uRam00000001400074e0 = _DAT_1400075c8;
      _DAT_1400074ec = DAT_1400073f8;
      _DAT_1400074f8 = DAT_140007404;
      IptLogPrint(2,
                  "[%s] Data request.\n    Total number of threads being traced = %u\n    Number of threads with user code being traced = %u\n    Number of threads with kernel code being traced = %u\n    Number of threads with user+kernel code being traced = %u\n"
                  ,"BugCheckSecondaryDumpDataCollectThreadTraceMetadata",(ulonglong)DAT_1400073f8);
    }
  }
  return;
}



===== BugCheckTriageDumpDataCallback @ 140001380 =====

void BugCheckTriageDumpDataCallback(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  void *pvVar9;
  
  if (DAT_1400073e4 != 2) {
    IptLogPrint(1,"[%s] CoreTracing == %u, IptCoreTracingControlBlock = NULL\n",
                "BugCheckTriageDumpDataCallback",(ulonglong)DAT_1400073e4);
    return;
  }
  uVar1 = *(uint *)(IptCoreTracingControlBlock + 0x60);
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  lVar7 = IptCoreTracingControlBlock;
  uVar6 = (ulonglong)uVar2;
  if (uVar2 < uVar1) {
    lVar5 = *(longlong *)(IptCoreTracingControlBlock + 0x68 + uVar6 * 8);
    pvVar9 = *(void **)(lVar5 + 0x28);
    if (((byte)DAT_140007408 & 2) != 0) {
      memmove(*(void **)(lVar5 + 0x30),pvVar9,(ulonglong)*(uint *)(lVar5 + 0x20));
      lVar5 = *(longlong *)(lVar7 + 0x68 + uVar6 * 8);
      pvVar9 = *(void **)(lVar5 + 0x30);
    }
    iVar3 = KeAddTriageDumpDataBlock
                      (*(undefined8 *)(lVar7 + 0x40),pvVar9,*(undefined4 *)(lVar5 + 0x20));
    IptLogPrint(2,"[%s] Add bugcheck owner processor %u\'s IPT trace buffer ( %p, %u ) = %u\n",
                "BugCheckTriageDumpDataCallback",uVar6);
    if (iVar3 < 0) goto LAB_140001523;
  }
  uVar8 = 0;
  if (uVar1 != 0) {
    lVar7 = 0x68;
    do {
      lVar5 = IptCoreTracingControlBlock;
      if (uVar8 != uVar2) {
        lVar4 = *(longlong *)(lVar7 + IptCoreTracingControlBlock);
        pvVar9 = *(void **)(lVar4 + 0x28);
        if (((byte)DAT_140007408 & 2) != 0) {
          memmove(*(void **)(lVar4 + 0x30),pvVar9,(ulonglong)*(uint *)(lVar4 + 0x20));
          lVar4 = *(longlong *)(lVar7 + lVar5);
          pvVar9 = *(void **)(lVar4 + 0x30);
        }
        iVar3 = KeAddTriageDumpDataBlock
                          (*(undefined8 *)(lVar5 + 0x40),pvVar9,*(undefined4 *)(lVar4 + 0x20));
        IptLogPrint(2,"[%s] Add processor %u\'s IPT trace buffer ( %p, %u ) = %u\n",
                    "BugCheckTriageDumpDataCallback",(ulonglong)uVar8);
        if (iVar3 < 0) break;
      }
      uVar8 = uVar8 + 1;
      lVar7 = lVar7 + 8;
    } while (uVar8 < uVar1);
  }
LAB_140001523:
  *param_3 = *(undefined8 *)(IptCoreTracingControlBlock + 0x40);
  return;
}



===== CheckIptOption @ 140001558 =====

ulonglong CheckIptOption(ulonglong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)param_1;
  if (((uVar1 & 0xf) - 1 < 2) && ((uVar1 & 0xf000000) < 0x6000000)) {
    uVar2 = 1 << ((byte)(param_1 >> 0x10) & 0xf) + 0xc;
    if (((DAT_140007440 == 0xffffffff) || (uVar2 <= DAT_140007440)) && (0x1b < uVar2 + 0x1c)) {
      return (ulonglong)((uVar1 & 0xf0) < 0x30);
    }
  }
  return param_1 & 0xffffffffffffff00;
}



===== ComputeIptCtlMsr @ 1400015b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ComputeIptCtlMsr(uint param_1)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = 0x2100;
  if ((IptCapability & 0x10) != 0) {
    uVar1 = 0x3100;
  }
  uVar2 = param_1 >> 0x18 & 0xf;
  if ((param_1 >> 0x18 & 0xf) == 0) {
LAB_1400015fe:
    uVar1 = uVar1 | 8;
  }
  else if (uVar2 == 1) {
LAB_1400015f8:
    uVar1 = uVar1 | 4;
  }
  else if (uVar2 == 2) {
LAB_1400015f2:
    uVar1 = uVar1 | 0xc;
  }
  else {
    if (uVar2 == 3) goto LAB_1400015fe;
    if (uVar2 == 4) goto LAB_1400015f8;
    if (uVar2 == 5) goto LAB_1400015f2;
  }
  uVar2 = param_1 >> 4 & 0xf;
  if (uVar2 == 1) {
    if (((IptCapability & 8) == 0) || ((DAT_1400075c8._2_2_ >> (param_1 >> 8 & 0xf) & 1) == 0))
    goto LAB_1400016b8;
    uVar3 = ((ulonglong)(param_1 & 0xf00) | 0x18) << 6;
  }
  else {
    if ((((uVar2 != 2) || ((IptCapability & 2) == 0)) ||
        ((_DAT_1400075cc & 1 << ((byte)(param_1 >> 0xc) & 0xf) & 0xffffU) == 0)) ||
       (((PRatio == 0 || ((IptCapability & 8) == 0)) ||
        ((DAT_1400075c8._2_2_ >> (param_1 >> 8 & 0xf) & 1) == 0)))) goto LAB_1400016b8;
    uVar3 = ((ulonglong)(param_1 & 0xf000) * 2 | (ulonglong)(param_1 & 0xf00)) << 6 | 0x602;
  }
  uVar1 = uVar1 | uVar3;
LAB_1400016b8:
  return uVar1 | 1;
}



===== Feature_3345721656__private_IsEnabledDeviceUsageNoInline @ 1400016c4 =====

ulonglong Feature_3345721656__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3345721656__private_featureState;
  if ((Feature_3345721656__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3345721656__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3345721656__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3345721656__private_IsEnabledFallback @ 1400016fc =====

void Feature_3345721656__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3345721656__private_descriptor);
  return;
}



===== Feature_72067384__private_IsEnabledDeviceUsageNoInline @ 140001718 =====

ulonglong Feature_72067384__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_72067384__private_featureState;
  if ((Feature_72067384__private_featureState & 0x10) == 0) {
    uVar1 = Feature_72067384__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_72067384__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_72067384__private_IsEnabledFallback @ 140001750 =====

void Feature_72067384__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_72067384__private_descriptor);
  return;
}



===== IptAcquireCoreTracingStopRef @ 14000176c =====

void IptAcquireCoreTracingStopRef(void)

{
  ExAcquireRundownProtection(&DAT_1400073d8);
  return;
}



===== IptDpcRoutine @ 140001790 =====

void IptDpcRoutine(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  KeInsertQueueApc(param_3 + 0xb8,param_3,0,0);
  return;
}



===== IptGetTraceBufferRange @ 1400017c0 =====

undefined8 IptGetTraceBufferRange(uint param_1,undefined8 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  lVar1 = IptCoreTracingControlBlock;
  if (param_2 != (undefined8 *)0x0) {
    if (DAT_1400073e4 != 2) {
      return 0xc0000001;
    }
    if (param_1 < *(uint *)(IptCoreTracingControlBlock + 0x60)) {
      uVar2 = (ulonglong)param_1;
      *param_2 = *(undefined8 *)
                  (*(longlong *)(IptCoreTracingControlBlock + 0x68 + uVar2 * 8) + 0x28);
      if (((byte)DAT_140007408 & 2) != 0) {
        *param_2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x68 + uVar2 * 8) + 0x30);
      }
      param_2[1] = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x68 + uVar2 * 8) + 0x20);
      return 0;
    }
  }
  return 0xc000000d;
}



===== IptGetTriageDumpDataArrayRange @ 140001830 =====

undefined8 IptGetTriageDumpDataArrayRange(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = IptCoreTracingControlBlock;
  if (param_1 == (undefined8 *)0x0) {
    return 0xc000000d;
  }
  if (DAT_1400073e4 == 2) {
    *param_1 = *(undefined8 *)(IptCoreTracingControlBlock + 0x40);
    param_1[1] = (ulonglong)*(uint *)(lVar1 + 0x48);
    return 0;
  }
  return 0xc0000001;
}



===== IptInterruptHandler @ 140001870 =====

void IptInterruptHandler(void)

{
  longlong lVar1;
  
  wrmsr(0x390,0x80000000000000);
  lVar1 = rdmsr(0x580);
  KeInsertQueueDpc(lVar1 + 0x78,lVar1,0);
  return;
}



===== IptIsTracingOn @ 1400018c0 =====

undefined8 IptIsTracingOn(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((DAT_1400073f8 != 0) || (DAT_1400073e4 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}



===== IptLockdown @ 1400018e0 =====

void IptLockdown(char param_1)

{
  if (param_1 == '\0') {
    ExReleasePushLockSharedEx(&DAT_140007450,0);
    KeLeaveCriticalRegion();
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&DAT_140007450,0);
  }
  return;
}



===== IptLogPrint @ 140001938 =====

void IptLogPrint(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
  if (param_1 <= DAT_14000741c) {
    local_res18 = param_3;
    local_res20 = param_4;
    vDbgPrintExWithPrefix("IPT: ",0x4d,param_1,param_2,&local_res18);
  }
  return;
}



===== IptLogTraceOnCurrentCore @ 140001990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IptLogTraceOnCurrentCore(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  bool bVar10;
  undefined1 auStack_58 [48];
  longlong local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = -0x7dfd7dfd7dfd7dfe;
  lStack_20 = -0x7dfd7dfd7dfd7dfe;
  if (param_1 == IptCoreTracingControlBlock) {
    uVar5 = KeGetCurrentProcessorNumberEx(0);
    if (uVar5 < *(uint *)(IptCoreTracingControlBlock + 0x60)) {
      bVar4 = KeGetCurrentIrql();
      bVar10 = bVar4 < 2;
      if (bVar10) {
        bVar4 = KfRaiseIrql();
      }
      uVar3 = rdmsr(0x570);
      uVar8 = uVar3 & 0xffffffff00000000;
      if ((uVar3 & 1) != 0) {
        uVar8 = uVar3 >> 0x20;
        wrmsr(0x570,uVar8 << 0x20 | uVar3 & 0xfffffffe);
      }
      if ((uVar3 & 1) == 0) {
        uVar6 = 0xc0000708;
      }
      else {
        uVar3 = rdmsr(0x571);
        if ((uVar3 & 0x10) == 0) {
          lVar1 = *(longlong *)(IptCoreTracingControlBlock + 0x68 + (ulonglong)uVar5 * 8);
          plVar2 = *(longlong **)(lVar1 + 0x28);
          uVar3 = rdmsr(0x561);
          uVar6 = rdmsr(0x561);
          lVar7 = *plVar2 - local_28;
          if (lVar7 == 0) {
            lVar7 = plVar2[1] - lStack_20;
          }
          iVar9 = *(int *)(lVar1 + 0x20);
          if (lVar7 == 0) {
            iVar9 = ((uint)(uVar3 >> 7) & 0x1ffffff) * *(int *)(lVar1 + 0x1c) +
                    (int)((ulonglong)uVar6 >> 0x20);
          }
          (*(code *)*DAT_140007430)(param_2,plVar2,iVar9);
          uVar6 = 0;
        }
        else {
          uVar6 = 0xc00000e5;
        }
        uVar3 = rdmsr(0x570);
        uVar8 = uVar3 & 0xffffffff00000000;
        if ((uVar3 & 1) == 0) {
          wrmsr(0x561,0);
          wrmsr(0x571,0);
          uVar8 = uVar3 >> 0x20;
          wrmsr(0x570,uVar8 << 0x20 | uVar3 & 0xffffffff | 1);
        }
      }
      if (bVar10) {
        KeLowerIrql(CONCAT71(5,bVar4),uVar8);
      }
    }
    else {
      uVar6 = 0xc0000001;
    }
  }
  else {
    uVar6 = 0xc0000008;
  }
  return uVar6;
}



===== IptReleaseCoreTracingStopRef @ 140001b70 =====

void IptReleaseCoreTracingStopRef(void)

{
  ExReleaseRundownProtection(&DAT_1400073d8);
  return;
}



===== IptTraceCurrentCore @ 140001ba0 =====

undefined8 IptTraceCurrentCore(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  
  if (IptCoreTracingControlBlock != 0) {
    uVar1 = KeGetCurrentProcessorNumberEx(0);
    if (uVar1 < *(uint *)(IptCoreTracingControlBlock + 0x60)) {
      uVar2 = 0;
      uVar4 = 0;
      if (param_1 == 0) {
        wrmsr(0x570,0);
        wrmsr(0x571,0);
        wrmsr(0x560,0);
        uVar3 = 0x561;
      }
      else {
        wrmsr(0x571,0);
        wrmsr(0x560,*(undefined8 *)
                     (*(longlong *)(IptCoreTracingControlBlock + 0x68 + (ulonglong)uVar1 * 8) + 8));
        wrmsr(0x561,0);
        uVar2 = *(ulonglong *)(IptCoreTracingControlBlock + 8);
        uVar3 = 0x570;
        uVar4 = uVar2 >> 0x20;
      }
      wrmsr(uVar3,uVar4 << 0x20 | uVar2 & 0xffffffff);
    }
  }
  return 0;
}



===== WriteCoreTraceMetadataV1 @ 140001c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WriteCoreTraceMetadataV1(undefined8 *param_1,uint param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint local_res18 [2];
  void *local_res20;
  
  local_res20 = (void *)0x0;
  local_res18[0] = 0;
  uVar4 = (ulonglong)param_2;
  iVar2 = (**(code **)(DAT_140007538 + 0x18))(uVar4,&local_res20,local_res18);
  puVar1 = IptCoreTracingControlBlock;
  uVar3 = _DAT_1400075c8;
  if (((iVar2 < 0) || (local_res20 == (void *)0x0)) || (local_res18[0] != IptStateSize)) {
    uVar3 = 0xc0000001;
  }
  else {
    *param_1 = _IptCapability;
    param_1[1] = uVar3;
    param_1[2] = *puVar1;
    *(undefined4 *)(param_1 + 3) = PRatio;
    *(uint *)((longlong)param_1 + 0x1c) = param_2;
    *(undefined2 *)(param_1 + 4) = 1;
    *(short *)((longlong)param_1 + 0x22) = *(short *)(puVar1[uVar4 + 0xd] + 0x18) + -1;
    *(uint *)((longlong)param_1 + 0x24) = IptStateSize;
    uVar3 = *(undefined8 *)(puVar1[uVar4 + 0xd] + 0x28);
    if (((byte)DAT_140007408 & 2) != 0) {
      uVar3 = *(undefined8 *)(puVar1[uVar4 + 0xd] + 0x30);
    }
    param_1[5] = uVar3;
    param_1[6] = (ulonglong)*(uint *)(puVar1[uVar4 + 0xd] + 0x20);
    memmove(param_1 + 7,local_res20,(ulonglong)IptStateSize);
    IptLogPrint(2,
                "[%s] IptCoreTraceMetadata[%u] = { .ProcessorNumber = %u, .NumVARanges = %u, .IptOption = 0x%llx, .TraceBufferVARange.Address = 0x%llx, .TraceBufferVARange.Size = 0x%u }\n"
                ,"WriteCoreTraceMetadataV1",(ulonglong)param_2);
    uVar3 = 0;
  }
  return uVar3;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001d8c =====

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
LAB_140001f95:
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
LAB_140001e67:
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
      if (param_3 == 4) goto LAB_140001f95;
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
        goto LAB_140001e67;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002080 =====

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
      goto LAB_140002151;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140002151;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140002151;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140002151;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140002151;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140002151;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140002151;
    }
  }
  uVar3 = 0xff;
LAB_140002151:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400021a8 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002298 =====

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
LAB_14000234b:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140002379;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000234b;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140002379:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002504 =====

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



===== wil_details_IsEnabledFallback @ 140002568 =====

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



===== wil_details_RecordCachedUsage @ 1400025fc =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002750 =====

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



===== WdmlibRtlInitUnicodeStringEx @ 1400027d4 =====

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



===== HviGetIptFeatures @ 140002820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002898) */
/* WARNING: Removing unreachable block (ram,0x000140002883) */
/* WARNING: Removing unreachable block (ram,0x000140002864) */

uint HviGetIptFeatures(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar5 = HviIsHypervisorMicrosoftCompatible();
  uVar7 = 0;
  if ((char)uVar5 != '\0') {
    uVar6 = HviIsAnyHypervisorPresent();
    if ((char)uVar6 == '\0') {
      uVar5 = (uint)local_38;
    }
    else {
      puVar1 = (uint *)cpuid(0x40000000);
      uVar5 = *puVar1;
    }
    if (0x4000000a < uVar5) {
      uVar5 = HviIsHypervisorMicrosoftCompatible();
      if ((char)uVar5 == '\0') {
      }
      else {
        puVar1 = (uint *)cpuid(0x40000003);
        uVar5 = *puVar1;
        uStack_20._4_4_ = puVar1[2];
      }
      if ((uStack_20._4_4_ >> 0x1b & 1) != 0) {
        puVar1 = (uint *)cpuid(0x4000000b);
        uVar5 = *puVar1;
        uVar2 = puVar1[1];
        uVar3 = puVar1[2];
        uVar4 = puVar1[3];
        *param_1 = uVar5;
        param_1[1] = uVar2;
        param_1[2] = uVar4;
        param_1[3] = uVar3;
        return uVar5;
      }
    }
  }
  *(undefined8 *)param_1 = uVar7;
  *(undefined8 *)(param_1 + 2) = uVar7;
  return uVar5;
}



===== HviIsAnyHypervisorPresent @ 1400028cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002900) */
/* WARNING: Removing unreachable block (ram,0x0001400028ef) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 140002928 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002955) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== _guard_check_icall @ 140002990 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400029a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400029cc =====

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



===== __cpu_features_init @ 140002a40 =====

/* WARNING: Removing unreachable block (ram,0x000140002aaa) */
/* WARNING: Removing unreachable block (ram,0x000140002a59) */
/* WARNING: Removing unreachable block (ram,0x000140002a4a) */

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



===== __security_check_cookie @ 140002b10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002b50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002b80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002bb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002c00 =====

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



===== memset @ 140002f00 =====

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



===== __memset_repmovs @ 140003040 =====

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



===== __memset_query @ 1400030c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003140 =====

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



===== __memset_spec_ermsb_repmovsb @ 140003280 =====

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



===== __memset_spec_plain @ 140003300 =====

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



===== AllocateIptCoreTracingControlBlock @ 14000b008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AllocateIptCoreTracingControlBlock(longlong param_1)

{
  size_t _Size;
  short sVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  void *pvVar5;
  ulonglong uVar6;
  uint uVar7;
  int unaff_R12D;
  undefined1 auStackY_88 [32];
  undefined4 local_58;
  longlong local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  sVar1 = KeQueryHighestNodeNumber();
  uVar2 = KeQueryActiveProcessorCountEx(0xffff);
  _Size = (ulonglong)uVar2 * 8 + 0x68;
  plVar4 = (longlong *)ExAllocatePool2(0x40,_Size,0x43545049);
  if (plVar4 == (longlong *)0x0) {
    IptCoreTracingControlBlock = plVar4;
    return unaff_R12D;
  }
  IptCoreTracingControlBlock = plVar4;
  memset(plVar4,0,_Size);
  *(uint *)(plVar4 + 0xc) = uVar2;
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      if (sVar1 != 0) {
        iVar3 = KeGetProcessorNumberFromIndex(uVar7,&local_58);
        if (iVar3 < 0) goto LAB_14000b238;
        local_50 = 1L << (local_58._2_1_ & 0x3f);
        uStack_48 = CONCAT62(uStack_48._2_6_,(undefined2)local_58);
        KeSetSystemGroupAffinityThread(&local_50);
      }
      iVar3 = AllocateTraceContext
                        (param_1,0,0,0,IptCoreTracingControlBlock + (ulonglong)uVar7 + 0xd);
      if (iVar3 < 0) goto LAB_14000b238;
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar2);
  }
  iVar3 = (uVar2 + 3) * 0x10;
  *(int *)(IptCoreTracingControlBlock + 9) = iVar3;
  pvVar5 = (void *)ExAllocatePool2(0x40,iVar3,0x52545049);
  plVar4 = IptCoreTracingControlBlock;
  IptCoreTracingControlBlock[8] = (longlong)pvVar5;
  if (pvVar5 != (void *)0x0) {
    memset(pvVar5,0,(ulonglong)*(uint *)(plVar4 + 9));
    if (0x37 < IptStateSize + 0x38U) {
      *(uint *)((longlong)plVar4 + 0x5c) = IptStateSize + 0x38U;
    }
    if ((0x37 < IptStateSize + 0x38U) &&
       (uVar6 = (ulonglong)(IptStateSize + 0x38U) * (ulonglong)uVar2, uVar6 < 0x100000000)) {
      uVar2 = (uint)uVar6;
      uVar7 = uVar2 + 8;
      *(uint *)(plVar4 + 0xb) = uVar2;
      if (uVar7 < uVar2) {
        *(undefined4 *)(plVar4 + 0xb) = 0xffffffff;
      }
      else {
        *(uint *)(plVar4 + 0xb) = uVar7;
        pvVar5 = (void *)ExAllocatePool2(0x40,uVar7,0x53545049);
        plVar4 = IptCoreTracingControlBlock;
        IptCoreTracingControlBlock[10] = (longlong)pvVar5;
        if (pvVar5 != (void *)0x0) {
          memset(pvVar5,0,(ulonglong)*(uint *)(plVar4 + 0xb));
          *plVar4 = param_1;
          uVar6 = ComputeIptCtlMsr((uint)param_1);
          plVar4[1] = uVar6;
          goto LAB_14000b23d;
        }
      }
    }
  }
LAB_14000b238:
  FreeIptCoreTracingControlBlock();
LAB_14000b23d:
  if (sVar1 != 0) {
    KeRevertToUserGroupAffinityThread(&local_40);
  }
  return unaff_R12D;
}



===== AllocateProcessContext @ 14000b288 =====

void * AllocateProcessContext
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  int iVar2;
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x100,0x60,0x50545049);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x60);
    iVar2 = ObOpenObjectByPointer(param_1,0x200,0,0x400,0,0,(undefined8 *)((longlong)_Dst + 0x28));
    if (-1 < iVar2) {
      if ((param_4 == 0) ||
         (iVar2 = ObOpenObjectByPointer(param_4,0x200,0,4,0,0,(longlong)_Dst + 0x40), -1 < iVar2)) {
        lVar1 = (longlong)_Dst + 0x10;
        *(void **)((longlong)_Dst + 8) = _Dst;
        *(longlong *)((longlong)_Dst + 0x18) = lVar1;
        *(longlong *)lVar1 = lVar1;
        *(void **)_Dst = _Dst;
        *(undefined4 *)((longlong)_Dst + 0x48) = 0;
        *(undefined8 *)((longlong)_Dst + 0x30) = param_3;
        *(undefined8 *)((longlong)_Dst + 0x20) = param_2;
        ExInitializeRundownProtection((longlong)_Dst + 0x50);
        lVar1 = (longlong)_Dst + 0x58;
        ExInitializeRundownProtection(lVar1);
        ExWaitForRundownProtectionRelease(lVar1);
        ExRundownCompleted(lVar1);
        return _Dst;
      }
      ZwClose(*(undefined8 *)((longlong)_Dst + 0x28));
    }
    ExFreePoolWithTag(_Dst,0x50545049);
  }
  return (void *)0x0;
}



===== AllocateSessionContext @ 14000b400 =====

void * AllocateSessionContext(void *param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  void *_Dst;
  
  if ((param_2 + 0x38 < 0x38) ||
     (_Dst = (void *)ExAllocatePool2(0x100,param_2 + 0x38,0x45545049), _Dst == (void *)0x0)) {
    return (void *)0x0;
  }
  memset(_Dst,0,(ulonglong)param_2 + 0x38);
  *(void **)((longlong)_Dst + 8) = _Dst;
  lVar1 = (longlong)_Dst + 0x10;
  *(longlong *)((longlong)_Dst + 0x18) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(void **)_Dst = _Dst;
  *(undefined8 *)((longlong)_Dst + 0x20) = param_3;
  *(undefined8 *)((longlong)_Dst + 0x28) = 1;
  *(uint *)((longlong)_Dst + 0x30) = param_2;
  memmove((void *)((longlong)_Dst + 0x34),param_1,(ulonglong)param_2);
  return _Dst;
}



===== AllocateTraceBuffer @ 14000b4b4 =====

int AllocateTraceBuffer(longlong *param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  ulonglong *puVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  void *_Dst;
  longlong lVar7;
  char *pcVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  longlong local_res10;
  longlong local_res18;
  undefined8 local_res20;
  ulonglong in_stack_ffffffffffffff98;
  undefined4 uVar16;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar17;
  uint in_stack_ffffffffffffffa8;
  
  uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar16 = (undefined4)(in_stack_ffffffffffffff98 >> 0x20);
  uVar14 = (uint)((ulonglong)param_2 >> 0x10) & 0xf;
  uVar11 = 1 << (sbyte)uVar14 + 0xc;
  local_res18 = param_3;
  local_res20 = param_4;
  if (((byte)DAT_140007408 & 2) == 0) {
    if ((DAT_1400075c4 & 2) == 0) {
      uVar13 = 1;
      uVar15 = uVar14;
    }
    else {
      if (uVar14 < 9) {
        uVar13 = 1 << (sbyte)uVar14;
      }
      else {
        uVar13 = 0x100;
      }
      uVar15 = 0;
      if (8 < uVar14) {
        uVar15 = uVar14 - 8;
      }
    }
    uVar14 = 1 << ((char)uVar15 + 0xcU & 0x1f);
    local_res10 = param_2;
    _Dst = (void *)ExAllocatePool2(0x40,0x1000,0x41504f54);
    *param_1 = (longlong)_Dst;
    if (_Dst == (void *)0x0) {
      PsGetCurrentThreadId();
      uVar5 = PsGetCurrentProcessId();
      pcVar8 = "[%s] ExAllocatePool2: failed to allocate IPT_TOPA for process %u thread %u\n";
      goto LAB_14000b60f;
    }
    memset(_Dst,0,0x1000);
    lVar4 = MmGetPhysicalAddress(*param_1);
    param_1[1] = lVar4;
    uVar2 = KeGetCurrentNodeNumber();
    in_stack_ffffffffffffffa8 = 0;
    uVar10 = (ulonglong)uVar11;
    uVar9 = CONCAT44(uVar16,1);
    lVar4 = MmAllocateNodePagesForMdlEx
                      (0,0xffffffffffffffff,(ulonglong)uVar14,uVar10,uVar9,
                       CONCAT44(uVar17,(uint)uVar2),0x24);
    param_1[8] = lVar4;
    if (lVar4 != 0) {
      if ((*(byte *)(lVar4 + 10) & 5) == 0) {
        uVar10 = 0;
        lVar4 = MmMapLockedPagesSpecifyCache(lVar4,0,1,0,uVar9 & 0xffffffff00000000,0x40000010);
      }
      else {
        lVar4 = *(longlong *)(lVar4 + 0x18);
      }
      param_1[5] = lVar4;
      if (lVar4 != 0) {
        uVar9 = (ulonglong)uVar13;
        lVar12 = 0;
        do {
          lVar7 = MmGetPhysicalAddress(lVar4);
          lVar4 = lVar4 + (ulonglong)uVar14;
          *(ulonglong *)(*param_1 + lVar12) = ((lVar7 >> 0xc) << 6 | (ulonglong)(uVar15 & 0xf)) << 6
          ;
          lVar12 = lVar12 + 8;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        *(ulonglong *)(*param_1 + (ulonglong)uVar13 * 8) = param_1[1] & 0xfffffffffffff000U | 1;
        param_2 = local_res10;
        if (((byte)local_res10 & 0xf) == 2) {
          if (uVar13 < 2) {
            IptLogPrint(1,
                        "[%s]: Invalid IptOption for full trace; #ToPA entries need to be greater than 1\n"
                        ,"AllocateTraceBuffer",uVar10);
            iVar3 = -0x3ffffff3;
            goto LAB_14000b956;
          }
          puVar1 = (ulonglong *)(*param_1 + (ulonglong)(uVar13 - 2) * 8);
          *puVar1 = *puVar1 | 4;
          puVar1 = (ulonglong *)(*param_1 + (ulonglong)(uVar13 - 1) * 8);
          *puVar1 = *puVar1 | 0x10;
        }
        goto LAB_14000b980;
      }
LAB_14000b6c1:
      PsGetCurrentThreadId();
      uVar5 = PsGetCurrentProcessId();
      pcVar8 = 
      "[%s] MmGetSystemAddressForMdlSafe failed to map MappedBuffer for process %u thread %u\n";
      goto LAB_14000b60f;
    }
    PsGetCurrentThreadId();
    PsGetCurrentProcessId();
    IptLogPrint(1,
                "[%s] MmAllocateNodePagesForMdlEx failed to allocate pages for %x bytes (%x bytes each chunk) for process %u thread %u\n"
                ,"AllocateTraceBuffer",(ulonglong)uVar11);
  }
  else {
    local_res10 = 0;
    uVar13 = uVar11 >> 0xc;
    uVar14 = 0x1000;
    if (0x100 < uVar13) {
      iVar3 = -0x3fffffff;
      goto LAB_14000b956;
    }
    iVar3 = WinHvCreateIptBuffers(uVar13,((byte)param_2 & 0xf) == 1,&local_res10);
    if (iVar3 < 0) goto LAB_14000b956;
    param_1[1] = local_res10 << 0xc;
    *(undefined1 *)(param_1 + 7) = 1;
    lVar4 = MmMapIoSpaceEx(local_res10 << 0xc,0x1000,2);
    *param_1 = lVar4;
    if (lVar4 == 0) {
      IptLogPrint(1,"[%s] MmMapIoSpaceEx: failed to map Topa\n","AllocateTraceBuffer",param_4);
      goto LAB_14000b5a2;
    }
    uVar5 = MmSizeOfMdl(0,uVar13 << 0xc);
    puVar6 = (undefined8 *)ExAllocatePool2(0x40,uVar5,0x50505449);
    param_1[8] = (longlong)puVar6;
    if (puVar6 == (undefined8 *)0x0) {
      PsGetCurrentThreadId();
      uVar5 = PsGetCurrentProcessId();
      pcVar8 = "[%s] ExAllocatePool2: failed to allocate MDL for process %u thread %u\n";
    }
    else {
      *puVar6 = 0;
      *(undefined2 *)((longlong)puVar6 + 10) = 0;
      *(short *)(puVar6 + 1) = ((short)uVar13 + 6) * 8;
      puVar6[4] = 0;
      *(undefined4 *)((longlong)puVar6 + 0x2c) = 0;
      *(uint *)(puVar6 + 5) = uVar13 << 0xc;
      lVar4 = param_1[8];
      if (uVar13 != 0) {
        uVar10 = (ulonglong)uVar13;
        lVar12 = 0;
        do {
          *(ulonglong *)(lVar12 + 0x30 + lVar4) = *(ulonglong *)(lVar12 + *param_1) >> 0xc;
          uVar10 = uVar10 - 1;
          lVar12 = lVar12 + 8;
        } while (uVar10 != 0);
      }
      *(ushort *)(param_1[8] + 10) = *(ushort *)(param_1[8] + 10) | 0x2002;
      lVar4 = param_1[8];
      if ((*(byte *)(lVar4 + 10) & 5) == 0) {
        lVar4 = MmMapLockedPagesSpecifyCache
                          (lVar4,0,1,0,in_stack_ffffffffffffff98 & 0xffffffff00000000,
                           CONCAT44(uVar17,0x40000010));
      }
      else {
        lVar4 = *(longlong *)(lVar4 + 0x18);
      }
      param_1[5] = lVar4;
      if (lVar4 == 0) goto LAB_14000b6c1;
      if (2 < ((uint)((ulonglong)param_2 >> 0x18) & 0xf) - 3) {
LAB_14000b980:
        *(uint *)((longlong)param_1 + 0x1c) = uVar14;
        *(uint *)(param_1 + 3) = uVar13;
        *(uint *)(param_1 + 4) = uVar11;
        param_1[2] = param_2;
        if (local_res18 != 0) {
          param_1[0xe] = local_res18;
          KeInitializeDpc(param_1 + 0xf,IptDpcRoutine,0);
          KeInitializeApc(param_1 + 0x17,local_res20,0,IptApcRoutine,0,0,
                          in_stack_ffffffffffffffa8 & 0xffffff00,0);
        }
        return 0;
      }
      lVar4 = ExAllocatePool2(0x40,uVar11,0x4f545049);
      param_1[6] = lVar4;
      if (lVar4 != 0) goto LAB_14000b980;
      PsGetCurrentThreadId();
      uVar5 = PsGetCurrentProcessId();
      pcVar8 = 
      "[%s] ExAllocatePool2: failed to allocate MappedBufferCopy for process %u thread %u\n";
    }
LAB_14000b60f:
    IptLogPrint(1,pcVar8,"AllocateTraceBuffer",uVar5);
  }
LAB_14000b5a2:
  iVar3 = -0x3fffffe9;
LAB_14000b956:
  FreeTraceBuffer(param_1);
  return iVar3;
}



===== AllocateTraceContext @ 14000ba18 =====

int AllocateTraceContext
              (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4,
              undefined8 *param_5)

{
  longlong *plVar1;
  int iVar2;
  longlong *_Dst;
  undefined8 uVar3;
  
  _Dst = (longlong *)ExAllocatePool2(0x40,0x120,0x4e545049);
  if (_Dst == (longlong *)0x0) {
    PsGetCurrentThreadId();
    uVar3 = PsGetCurrentProcessId();
    IptLogPrint(1,
                "[%s] ExAllocatePool2: failed to allocate IPT_TRACE_CONTEXT for process %u thread %u\n"
                ,"AllocateTraceContext",uVar3);
    iVar2 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,0x120);
    iVar2 = AllocateTraceBuffer(_Dst,param_1,param_4,param_2);
    if (iVar2 < 0) {
      FreeTraceBuffer(_Dst);
      ExFreePoolWithTag(_Dst,0x4e545049);
    }
    else {
      plVar1 = _Dst + 10;
      _Dst[9] = param_3;
      _Dst[0xb] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      plVar1 = _Dst + 0xc;
      _Dst[0xd] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      *param_5 = _Dst;
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== ClearIptState @ 14000bb30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ClearIptState(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  uint uVar2;
  
  wrmsr(0x570,0);
  wrmsr(0x561,0);
  wrmsr(0x560,0);
  wrmsr(0x571,0);
  uVar2 = 0;
  if ((DAT_1400075c8 & 7) != 0) {
    param_3 = 0x581;
    do {
      iVar1 = (int)param_3;
      wrmsr(iVar1 + -1,0);
      wrmsr(iVar1,0);
      uVar2 = uVar2 + 1;
      param_3 = (ulonglong)(iVar1 + 2);
    } while (uVar2 < (DAT_1400075c8 & 7));
  }
  (*(code *)*DAT_140007510)(SystemReserved1[0xf],1,param_3);
  return;
}



===== ConfigureThreadAddressFilterRange @ 14000bbc0 =====

ulonglong ConfigureThreadAddressFilterRange(int *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  cVar6 = KeGetCurrentIrql();
  if (cVar6 == '\0') {
    KeEnterGuardedRegion();
  }
  uVar2 = rdmsr(0x570);
  if ((uVar2 & 1) != 0) {
    wrmsr(0x570,uVar2 & 0xfffffffffffffffe);
  }
  uVar3 = rdmsr(0x570);
  piVar1 = param_1 + 1;
  iVar5 = *piVar1 * 2;
  rdmsr(iVar5 + 0x580);
  uVar4 = rdmsr(iVar5 + 0x581);
  wrmsr(iVar5 + 0x580,*(undefined8 *)(param_1 + 4));
  iVar8 = *piVar1 * 2 + 0x581;
  uVar10 = *(ulonglong *)(param_1 + 6);
  uVar9 = uVar10 >> 0x20;
  wrmsr(iVar8,uVar9 << 0x20 | uVar10 & 0xffffffff);
  *param_1 = 0;
  if (-1 < *param_1) {
    bVar7 = (char)*piVar1 * '\x04' + 0x20;
    uVar10 = ~(0xfL << (bVar7 & 0x3f)) & uVar3 | (longlong)param_1[2] << (bVar7 & 0x3f);
    uVar9 = uVar10 >> 0x20;
    iVar8 = 0x570;
    wrmsr(0x570,uVar9 << 0x20 | uVar10 & 0xffffffff);
  }
  if ((uVar2 & 1) != 0) {
    iVar8 = 0x570;
    uVar2 = rdmsr(0x570);
    uVar9 = uVar2 & 0xffffffff00000000;
    uVar10 = uVar2;
    if ((uVar2 & 1) == 0) {
      uVar10 = uVar2 | 1;
      uVar9 = uVar2 >> 0x20;
      wrmsr(0x570,uVar9 << 0x20 | uVar2 & 0xffffffff | 1);
    }
  }
  if (cVar6 == '\0') {
    uVar10 = KeLeaveGuardedRegion(iVar8,uVar9,uVar3,iVar5,uVar4,uVar3,piVar1);
  }
  return uVar10;
}



===== EnterCoreTracingControl @ 14000bd7c =====

undefined1 EnterCoreTracingControl(void)

{
  undefined1 uVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007450,0);
  uVar1 = 0;
  if ((DAT_1400073f0 == 0) && (DAT_1400073ec == 0)) {
    uVar1 = 1;
    DAT_1400073e8 = DAT_1400073e8 + 1;
  }
  ExReleasePushLockExclusiveEx(&DAT_140007450,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== EnterThreadTracingControl @ 14000bdf0 =====

undefined1 EnterThreadTracingControl(void)

{
  undefined1 uVar1;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007450,0);
  uVar1 = 0;
  if ((DAT_1400073e8 == 0) && (DAT_1400073e4 == 0)) {
    uVar1 = 1;
    DAT_1400073ec = DAT_1400073ec + 1;
  }
  ExReleasePushLockExclusiveEx(&DAT_140007450,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== FreeIptCoreTracingControlBlock @ 14000be64 =====

void FreeIptCoreTracingControlBlock(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (IptCoreTracingControlBlock != 0) {
    if (*(longlong *)(IptCoreTracingControlBlock + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(IptCoreTracingControlBlock + 0x40),0x52545049);
    }
    if (*(longlong *)(IptCoreTracingControlBlock + 0x50) != 0) {
      ExFreePoolWithTag(*(longlong *)(IptCoreTracingControlBlock + 0x50),0x53545049);
    }
    uVar3 = 0;
    if (*(int *)(IptCoreTracingControlBlock + 0x60) != 0) {
      do {
        plVar1 = *(longlong **)(IptCoreTracingControlBlock + 0x68 + uVar3 * 8);
        if (plVar1 != (longlong *)0x0) {
          FreeTraceBuffer(plVar1);
          ExFreePoolWithTag(plVar1,0x4e545049);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(IptCoreTracingControlBlock + 0x60));
    }
    ExFreePoolWithTag(IptCoreTracingControlBlock,0x43545049);
    IptCoreTracingControlBlock = 0;
  }
  return;
}



===== FreeProcessContext @ 14000bf28 =====

void FreeProcessContext(longlong param_1)

{
  ExWaitForRundownProtectionRelease(param_1 + 0x50);
  ExRundownCompleted(param_1 + 0x50);
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ZwClose();
  }
  ZwClose(*(undefined8 *)(param_1 + 0x28));
  ExFreePoolWithTag(param_1,0x50545049);
  return;
}



===== FreeTraceBuffer @ 14000bfa0 =====

void FreeTraceBuffer(longlong *param_1)

{
  if (((byte)DAT_140007408 & 2) == 0) {
    if (param_1[8] != 0) {
      if (param_1[5] != 0) {
        MmUnmapLockedPages();
        param_1[5] = 0;
      }
      MmFreePagesFromMdl(param_1[8]);
      ExFreePoolWithTag(param_1[8],0x50505449);
      param_1[8] = 0;
    }
    if (*param_1 != 0) {
      ExFreePoolWithTag(*param_1,0x41504f54);
      *param_1 = 0;
    }
  }
  else {
    if (param_1[6] != 0) {
      ExFreePoolWithTag(param_1[6],0x4f545049);
      param_1[6] = 0;
    }
    if (param_1[5] != 0) {
      MmUnmapLockedPages(param_1[5],param_1[8]);
      param_1[5] = 0;
    }
    if (param_1[8] != 0) {
      ExFreePoolWithTag(param_1[8],0x50505449);
      param_1[8] = 0;
    }
    if (*param_1 != 0) {
      MmUnmapIoSpace(*param_1,0x1000);
      *param_1 = 0;
    }
    if ((char)param_1[7] != '\0') {
      WinHvDeleteIptBuffers(param_1[1] >> 0xc);
      *(undefined1 *)(param_1 + 7) = 0;
    }
  }
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[0xe] = 0;
  return;
}



===== GetIptOption @ 14000c0e4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong GetIptOption(ulonglong *param_1,undefined8 param_2,char param_3)

{
  ulonglong uVar1;
  int local_res8 [2];
  ulonglong local_res20;
  
  local_res8[0] = 0;
  if (param_1 == (ulonglong *)0x0) {
    return 0xc000000d;
  }
  local_res20 = local_res20 & 0xffffffff00000000;
  uVar1 = IptQueryValueKey(param_2,&DAT_140007030,4,&local_res20,4);
  if ((((int)uVar1 + 0x80000000U & 0x80000000) == 0) && ((int)uVar1 != -0x3fffffcc)) {
    return uVar1;
  }
  if (1 < (uint)local_res20) {
    return 0xc000000d;
  }
  if ((uint)local_res20 == 0) {
    local_res20 = 0;
    uVar1 = IptQueryValueKey(param_2,&DAT_1400070b0,0xb,&local_res20,8);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((longlong)local_res20 < _DAT_fffff78000000014) {
      return 0xc0190060;
    }
    uVar1 = IptQueryValueKey(param_2,&DAT_140007060,4,local_res8,4);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (local_res8[0] == 0) {
      return 0xc0000001;
    }
    if ((param_3 != '\0') && (local_res8[0] != -0x1234568)) {
      local_res8[0] = local_res8[0] + -1;
      uVar1 = ZwSetValueKey(param_2,&DAT_140007060,0,4,local_res8,4);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
    }
  }
  uVar1 = IptQueryValueKey(param_2,&DAT_140007020,0xb,param_1,8);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  uVar1 = CheckIptOption(*param_1);
  if ((char)uVar1 == '\0') {
    return 0xc0000001;
  }
  return (ulonglong)(-(uint)(((byte)*param_1 & 0xf) != 1) & 0xc0000001);
}



===== GetIptOptionForTracingCores @ 14000c278 =====

ulonglong GetIptOptionForTracingCores(ulonglong *param_1,char param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar1 = OpenIptServiceKey();
  if (-1 < (int)uVar1) {
    uVar2 = GetIptOption(param_1,0,param_2);
    uVar1 = uVar2 & 0xffffffff;
    if (((-1 < (int)uVar2) && (uVar3 = (uint)*param_1 & 0xf000000, uVar3 != 0x3000000)) &&
       ((uVar3 + 0xfc000000 & 0xfeffffff) != 0)) {
      uVar1 = 0xc0000001;
    }
    ZwClose(0);
  }
  return uVar1;
}



===== GetIptOptionForTracingThreads @ 14000c2fc =====

ulonglong GetIptOptionForTracingThreads
                    (ulonglong *param_1,ushort *param_2,longlong param_3,char param_4)

{
  int iVar1;
  undefined4 extraout_var;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 local_18 [2];
  
  local_18[0] = 0;
  iVar1 = OpenImageIFEOKey(local_18,param_2,param_3,'\0');
  uVar2 = CONCAT44(extraout_var,iVar1);
  if (-1 < iVar1) {
    uVar3 = GetIptOption(param_1,local_18[0],param_4);
    uVar2 = uVar3 & 0xffffffff;
    if (((-1 < (int)uVar3) && (uVar4 = (uint)*param_1 & 0xf000000, uVar4 != 0)) &&
       ((uVar4 - 0x1000000 & 0xfeffffff) != 0)) {
      uVar2 = 0xc0000001;
    }
    ZwClose(local_18[0]);
  }
  return uVar2;
}



===== GetPackageFamilyName @ 14000c37c =====

undefined8 GetPackageFamilyName(short *param_1,uint param_2,short *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  
  uVar3 = 0;
  uVar2 = 0;
  for (psVar4 = param_1; (*psVar4 != 0x5f && (*psVar4 != 0)); psVar4 = psVar4 + 1) {
    uVar2 = uVar2 + 2;
  }
  for (psVar4 = (short *)(((ulonglong)param_2 - 2) + (longlong)param_1);
      (*psVar4 != 0x5f && (psVar4 != param_1)); psVar4 = psVar4 + -1) {
    uVar3 = uVar3 + 2;
  }
  if ((ulonglong)(ushort)param_3[1] < (ulonglong)(uVar3 + uVar2) + 2) {
    uVar1 = 0xc0000023;
  }
  else {
    memmove(*(void **)(param_3 + 4),param_1,(ulonglong)uVar2);
    memmove((void *)(*(longlong *)(param_3 + 4) + (ulonglong)uVar2),psVar4,(ulonglong)uVar3 + 2);
    *param_3 = (short)uVar2 + (short)uVar3;
    uVar1 = 0;
  }
  return uVar1;
}



===== GetProcessFromHandle @ 14000c440 =====

undefined4 GetProcessFromHandle(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 local_res8 [4];
  
  if (param_1 == -1) {
    local_res8[0] = PsGetCurrentProcess();
    uVar1 = 0;
  }
  else {
    local_res8[0] = 0;
    uVar1 = ObReferenceObjectByHandle
                      (param_1,0x10,*(undefined8 *)PsProcessType_exref,1,local_res8,0);
  }
  *param_2 = local_res8[0];
  return uVar1;
}



===== GetThreadFromHandle @ 14000c4b0 =====

undefined4 GetThreadFromHandle(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined8 local_res8 [4];
  
  uVar1 = 0;
  if (param_1 == -2) {
    *param_2 = SystemReserved1[0xf];
  }
  else {
    local_res8[0] = 0;
    uVar1 = ObReferenceObjectByHandle(param_1,8,*(undefined8 *)PsThreadType_exref,1,local_res8,0);
    *param_2 = local_res8[0];
  }
  return uVar1;
}



===== GetTrace @ 14000c520 =====

void GetTrace(longlong *param_1)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  
  if (param_1 != (longlong *)0x0) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 == '\0') {
      KeEnterGuardedRegion();
    }
    uVar3 = PsGetCurrentThreadId();
    uVar3 = IptLookupThread(uVar3);
    if ((uVar3 != 0) && (*(longlong *)(uVar3 + 0x28) != 0)) {
      uVar1 = rdmsr(0x570);
      if ((uVar1 & 1) != 0) {
        wrmsr(0x570,uVar1 & 0xfffffffffffffffe);
      }
      uVar5 = rdmsr(0x571);
      if ((uVar5 & 0x10) == 0) {
        uVar5 = (ulonglong)(*(int *)(uVar3 + 0x20) + 0x1c) + param_1[2];
        param_1[2] = uVar5;
        if ((*param_1 != 0) && (uVar5 <= *(uint *)(param_1 + 1))) {
          puVar6 = (undefined8 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1);
          uVar4 = PsGetCurrentThreadId();
          *puVar6 = uVar4;
          *(uint *)(puVar6 + 1) = *(uint *)(uVar3 + 0x10) >> 4 & 0xf;
          *(uint *)((longlong)puVar6 + 0xc) = *(uint *)(uVar3 + 0x10) >> 8 & 0xf;
          *(undefined4 *)(puVar6 + 2) = PRatio;
          uVar5 = rdmsr(0x561);
          uVar4 = rdmsr(0x561);
          *(uint *)((longlong)puVar6 + 0x14) =
               ((uint)(uVar5 >> 7) & 0x1ffffff) * *(int *)(uVar3 + 0x1c) +
               (int)((ulonglong)uVar4 >> 0x20);
          *(undefined4 *)(puVar6 + 3) = *(undefined4 *)(uVar3 + 0x20);
          memmove((void *)((longlong)puVar6 + 0x1c),*(void **)(uVar3 + 0x28),
                  (ulonglong)*(uint *)(uVar3 + 0x20));
          *(int *)((longlong)param_1 + 0xc) = (int)param_1[2];
        }
      }
      if (((uVar1 & 1) != 0) && (uVar3 = rdmsr(0x570), (uVar3 & 1) == 0)) {
        wrmsr(0x570,uVar3 & 0xffffffff00000000 | uVar3 & 0xffffffff | 1);
      }
    }
    if (cVar2 == '\0') {
      KeLeaveGuardedRegion();
    }
  }
  return;
}



===== InitIFEOKey @ 14000c6e0 =====

bool InitIFEOKey(void)

{
  int iVar1;
  undefined8 local_res20;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res20 = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_28 = &DAT_140007090;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  iVar1 = ZwOpenKey(&local_res20,0xd,&local_38);
  if (-1 < iVar1) {
    DAT_140007420 = local_res20;
  }
  return -1 < iVar1;
}



===== IptAcquireProcessContext @ 14000c75c =====

ulonglong IptAcquireProcessContext(ulonglong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  
  uVar3 = 0;
  if (DAT_1400073f0 == 0) {
    uVar3 = 0;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&DAT_140007438,0);
    plVar4 = (longlong *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007500);
    plVar1 = (longlong *)*plVar4;
    plVar2 = (longlong *)0x0;
    if (plVar1 == plVar4) {
LAB_14000c7d4:
      uVar3 = -(ulonglong)((char)uVar3 != '\0') & (ulonglong)plVar2;
      if (uVar3 != 0) {
        ExAcquireRundownProtection(uVar3 + 0x50);
      }
    }
    else {
      do {
        if (plVar1[4] == param_1) {
          uVar3 = 1;
          plVar2 = plVar1;
          goto LAB_14000c7d4;
        }
        plVar1 = (longlong *)*plVar1;
      } while (plVar1 != plVar4);
    }
    ExReleasePushLockSharedEx(&DAT_140007438,0);
    KeLeaveCriticalRegion();
  }
  return uVar3;
}



===== IptAddProcess @ 14000c824 =====

undefined1 IptAddProcess(ulonglong param_1,longlong *param_2,short *param_3,uint param_4)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  longlong lVar12;
  uint local_res8 [2];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  ulonglong local_38;
  short *psStack_30;
  
  uVar4 = 0;
  uVar11 = 0;
  bVar3 = false;
  if (((((*(uint *)(param_2 + 6) & 0x700000) != 0) && (param_3 != (short *)0x0)) && (param_4 != 0))
     && (*param_3 != 0)) {
    local_res8[0] = 0;
    local_38 = (ulonglong)CONCAT22((short)param_4,(short)param_4);
    psStack_30 = param_3;
    RtlHashUnicodeString(&local_38,0,0,local_res8);
    bVar3 = true;
    uVar11 = local_res8[0] & 0x7fff;
    local_res8[0] = uVar11;
  }
  puVar10 = auStack_58;
  puVar9 = auStack_58;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007438,0);
  lVar12 = (ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10;
  puVar8 = (undefined8 *)(DAT_140007500 + lVar12);
  for (puVar5 = (undefined8 *)*puVar8; puVar5 != puVar8; puVar5 = (undefined8 *)*puVar5) {
    if (puVar5[4] == param_1) {
      if (puVar5 != (undefined8 *)0x0) goto LAB_14000ca0c;
      break;
    }
  }
  puVar10 = auStack_58;
  if (bVar3) {
    plVar6 = IptLookupSessionInternal(param_3,param_4,(ulonglong)uVar11);
    if (plVar6 == (longlong *)0x0) {
      plVar6 = AllocateSessionContext(param_3,param_4,param_2[6]);
      puVar10 = auStack_58;
      if (plVar6 == (longlong *)0x0) goto LAB_14000c9bb;
      plVar7 = (longlong *)((ulonglong)uVar11 * 0x10 + DAT_140007428);
      lVar1 = *plVar7;
      if (*(longlong **)(lVar1 + 8) != plVar7) goto LAB_14000ca4d;
      plVar6[1] = (longlong)plVar7;
      *plVar6 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar6;
      *plVar7 = (longlong)plVar6;
      plVar7 = plVar6 + 2;
      if ((undefined *)*DAT_1400075f8 != &IptSessionList) goto LAB_14000ca4d;
      *plVar7 = (longlong)&IptSessionList;
      plVar6[3] = (longlong)DAT_1400075f8;
      *DAT_1400075f8 = (longlong)plVar7;
      DAT_1400073f4 = DAT_1400073f4 + 1;
      puVar9 = auStack_58;
      DAT_1400075f8 = plVar7;
    }
    else {
      LOCK();
      plVar7 = plVar6 + 5;
      lVar1 = *plVar7;
      *plVar7 = *plVar7 + 1;
      UNLOCK();
      if (lVar1 + 1 < 2) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(0xe);
        puVar9 = auStack_50;
      }
    }
    param_2[7] = (longlong)plVar6;
    puVar10 = puVar9;
  }
LAB_14000c9bb:
  plVar6 = (longlong *)(DAT_140007500 + lVar12);
  lVar12 = *plVar6;
  if (*(longlong **)(lVar12 + 8) == plVar6) {
    *param_2 = lVar12;
    param_2[1] = (longlong)plVar6;
    *(longlong **)(lVar12 + 8) = param_2;
    *plVar6 = (longlong)param_2;
    plVar6 = param_2 + 2;
    if ((undefined8 *)*DAT_1400075e8 == &IptProcessList) {
      *plVar6 = (longlong)&IptProcessList;
      uVar4 = 1;
      param_2[3] = (longlong)DAT_1400075e8;
      *DAT_1400075e8 = (longlong)plVar6;
      DAT_1400073f0 = DAT_1400073f0 + 1;
      DAT_1400075e8 = plVar6;
LAB_14000ca0c:
      *(undefined8 *)(puVar10 + -8) = 0x14000ca1c;
      ExReleasePushLockExclusiveEx(&DAT_140007438,0);
      *(undefined8 *)(puVar10 + -8) = 0x14000ca28;
      KeLeaveCriticalRegion();
      return uVar4;
    }
  }
LAB_14000ca4d:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  uVar4 = (*pcVar2)();
  return uVar4;
}



===== IptAddThread @ 14000ca5c =====

undefined1 IptAddThread(ulonglong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  uVar4 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007518,0);
  plVar7 = (longlong *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007520);
  plVar6 = (longlong *)*plVar7;
  do {
    if (plVar6 == plVar7) {
LAB_14000cace:
      lVar2 = *plVar7;
      plVar6 = (longlong *)(param_2 + 0x50);
      if (*(longlong **)(lVar2 + 8) == plVar7) {
        *plVar6 = lVar2;
        *(longlong **)(param_2 + 0x58) = plVar7;
        *(longlong **)(lVar2 + 8) = plVar6;
        *plVar7 = (longlong)plVar6;
        puVar1 = (undefined8 *)(param_2 + 0x60);
        if ((undefined *)*DAT_1400075a8 == &IptThreadList) {
          *puVar1 = &IptThreadList;
          uVar4 = 1;
          *(undefined8 **)(param_2 + 0x68) = DAT_1400075a8;
          *DAT_1400075a8 = puVar1;
          DAT_1400073f8 = DAT_1400073f8 + 1;
          uVar5 = *(uint *)(param_2 + 0x10) & 0xf000000;
          DAT_1400075a8 = puVar1;
          if (uVar5 == 0) {
            DAT_1400073fc = DAT_1400073fc + 1;
          }
          else if (uVar5 == 0x1000000) {
            DAT_140007400 = DAT_140007400 + 1;
          }
          else if (uVar5 == 0x2000000) {
            DAT_140007404 = DAT_140007404 + 1;
          }
LAB_14000cb4e:
          ExReleasePushLockExclusiveEx(&DAT_140007518,0);
          KeLeaveCriticalRegion();
          return uVar4;
        }
      }
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    if (plVar6[-1] == param_1) {
      if (plVar6 != (longlong *)0x50) goto LAB_14000cb4e;
      goto LAB_14000cace;
    }
    plVar6 = (longlong *)*plVar6;
  } while( true );
}



===== IptApcRoutine @ 14000cb90 =====

ulonglong IptApcRoutine(void)

{
  longlong *plVar1;
  ulonglong uVar2;
  int iVar3;
  longlong *plVar4;
  byte *pbVar5;
  byte *pbVar6;
  ulonglong uVar7;
  undefined8 *in_R9;
  byte local_res20 [8];
  byte local_18;
  byte local_17 [15];
  
  plVar1 = (longlong *)*in_R9;
  pbVar6 = local_17;
  local_18 = 0;
  pbVar5 = &local_18;
  local_res20[0] = 0;
  plVar4 = plVar1;
  iVar3 = WriteTrace((longlong)plVar1,pbVar5,pbVar6,local_res20);
  if ((iVar3 < 0) || (local_res20[0] != 0)) {
    ClearIptState(plVar4,pbVar5,(ulonglong)pbVar6);
    uVar7 = FreeTraceBuffer(plVar1);
  }
  else {
    uVar2 = rdmsr(0x570);
    wrmsr(0x571,0);
    wrmsr(0x561,0);
    uVar7 = uVar2 & 0xfffffffffffffffe | (ulonglong)(local_18 != 0);
    wrmsr(0x570,uVar2 & 0xffffffff00000000 | uVar2 & 0xfffffffe | (ulonglong)(local_18 != 0));
  }
  return uVar7;
}



===== IptCheckPrivilegeForThreadTracing @ 14000cc28 =====

uint IptCheckPrivilegeForThreadTracing(uint param_1)

{
  char cVar1;
  uint uVar2;
  
  if ((param_1 >> 0x18 & 0xf) - 1 < 2) {
    cVar1 = SeSinglePrivilegeCheck
                      (*(undefined8 *)(*(longlong *)SeExports_exref + 0x90),
                       CONCAT71((int7)((ulonglong)SystemReserved1[0xf] >> 8),
                                *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232)));
    uVar2 = ~-(uint)(cVar1 != '\0') & 0xc0000022;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== IptConfigureThreadAddressFilterRange @ 14000cc80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IptConfigureThreadAddressFilterRange
               (longlong param_1,uint param_2,int param_3,ulonglong param_4,ulonglong param_5)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  void *pvVar7;
  undefined1 auStack_a8 [32];
  void *local_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_a8;
  pvVar7 = (void *)0x0;
  local_88 = (void *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_80 = param_1;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    return 0xc0000001;
  }
  if (((IptCapability & 4) == 0) || ((DAT_1400075c8 & 7) <= param_2)) {
    uVar2 = 0xc00000bb;
  }
  else {
    if ((2 < param_3) || (param_5 < param_4)) {
      uVar2 = 0xc000000d;
      goto LAB_14000ce8e;
    }
    uVar2 = GetThreadFromHandle(param_1,&local_88);
    pvVar7 = local_88;
    if (-1 < (int)uVar2) {
      cVar1 = PsIsThreadTerminating(local_88);
      uVar2 = 0xc0000001;
      if (cVar1 == '\0') {
        uVar4 = PsGetThreadProcess(pvVar7);
        uVar5 = PsGetProcessId(uVar4);
        uVar5 = IptAcquireProcessContext(uVar5);
        if (uVar5 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar5 + 0x58);
          if (cVar1 != '\0') {
            if (((byte)*(undefined4 *)(uVar5 + 0x30) & 0xf) != 2) {
              uVar2 = IptCheckPrivilegeForThreadTracing((uint)*(undefined8 *)(uVar5 + 0x30));
              if (-1 < (int)uVar2) {
                uVar6 = Feature_72067384__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar6 == 0) {
                  if (param_3 != 0) {
                    uVar2 = *(uint *)(uVar5 + 0x30) & 0xf000000;
                    if (uVar2 == 0) {
                      if (*(ulonglong *)MmUserProbeAddress_exref <= param_5) goto LAB_14000cdd0;
                    }
                    else if ((uVar2 == 0x1000000) &&
                            (param_4 < *(ulonglong *)MmUserProbeAddress_exref)) {
LAB_14000cdd0:
                      uVar2 = 0xc000000d;
                      goto LAB_14000ce50;
                    }
                  }
                }
                else {
                  uVar3 = *(uint *)(uVar5 + 0x30) & 0xf000000;
                  if (uVar3 == 0) {
                    if (*(ulonglong *)MmUserProbeAddress_exref <= param_5) goto LAB_14000cdd0;
                  }
                  else if ((uVar3 == 0x1000000) &&
                          (param_4 < *(ulonglong *)MmUserProbeAddress_exref)) {
                    uVar2 = 0xc000000d;
                  }
                  if ((int)uVar2 < 0) goto LAB_14000ce50;
                }
                local_78 = CONCAT44(param_2,(uint)local_78);
                uStack_70 = CONCAT44(uStack_70._4_4_,param_3);
                uStack_60 = param_5;
                local_68 = param_4;
                RunOnThread(pvVar7,ConfigureThreadAddressFilterRange,&local_78);
                uVar2 = (uint)local_78;
              }
            }
LAB_14000ce50:
            ExReleaseRundownProtection(uVar5 + 0x58);
          }
          ExReleaseRundownProtection(uVar5 + 0x50);
        }
        param_1 = local_80;
      }
    }
  }
  if ((pvVar7 != (void *)0x0) && (param_1 != -2)) {
    ObfDereferenceObject(pvVar7);
  }
LAB_14000ce8e:
  LeaveThreadTracingControl();
  return uVar2;
}



===== IptDeleteProcess @ 14000cec0 =====

undefined8 * IptDeleteProcess(ulonglong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  if (DAT_1400073f0 == 0) {
    return (undefined8 *)0x0;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007438,0);
  puVar7 = (undefined8 *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007500);
  puVar6 = (undefined8 *)*puVar7;
  do {
    puVar5 = puVar6;
    puVar6 = (undefined8 *)0x0;
    if (puVar5 == puVar7) goto LAB_14000cf2d;
    puVar6 = (undefined8 *)*puVar5;
  } while (puVar5[4] != param_1);
  if (((undefined8 *)puVar6[1] == puVar5) &&
     (puVar7 = (undefined8 *)puVar5[1], (undefined8 *)*puVar7 == puVar5)) {
    *puVar7 = puVar6;
    puVar6[1] = puVar7;
    plVar1 = puVar5 + 2;
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = (longlong *)puVar5[3], (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      DAT_1400073f0 = DAT_1400073f0 + -1;
      puVar6 = puVar5;
      if ((longlong *)puVar5[7] != (longlong *)0x0) {
        IptDerefSession((longlong *)puVar5[7]);
      }
LAB_14000cf2d:
      ExReleasePushLockExclusiveEx(&DAT_140007438,0);
      KeLeaveCriticalRegion();
      return puVar6;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  puVar6 = (undefined8 *)(*pcVar4)();
  return puVar6;
}



===== IptDeleteThread @ 14000cfb8 =====

undefined8 * IptDeleteThread(ulonglong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007518,0);
  puVar9 = (undefined8 *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007520);
  puVar7 = (undefined8 *)*puVar9;
  do {
    puVar5 = puVar7;
    puVar8 = (undefined8 *)0x0;
    if (puVar5 == puVar9) goto LAB_14000d01e;
    puVar7 = (undefined8 *)*puVar5;
    puVar8 = puVar5 + -10;
  } while (puVar5[-1] != param_1);
  if (((undefined8 *)puVar7[1] == puVar5) &&
     (puVar9 = (undefined8 *)puVar5[1], (undefined8 *)*puVar9 == puVar5)) {
    *puVar9 = puVar7;
    plVar1 = puVar5 + 2;
    puVar7[1] = puVar9;
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = (longlong *)puVar5[3], (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      DAT_1400073f8 = DAT_1400073f8 + -1;
      uVar6 = *(uint *)(puVar5 + -8) & 0xf000000;
      if (uVar6 == 0) {
        DAT_1400073fc = DAT_1400073fc + -1;
      }
      else if (uVar6 == 0x1000000) {
        DAT_140007400 = DAT_140007400 + -1;
      }
      else if (uVar6 == 0x2000000) {
        DAT_140007404 = DAT_140007404 + -1;
      }
LAB_14000d01e:
      ExReleasePushLockExclusiveEx(&DAT_140007518,0);
      KeLeaveCriticalRegion();
      return puVar8;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  puVar7 = (undefined8 *)(*pcVar4)();
  return puVar7;
}



===== IptDerefSession @ 14000d0d8 =====

void IptDerefSession(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  
  LOCK();
  plVar2 = param_1 + 5;
  lVar1 = *plVar2;
  *plVar2 = *plVar2 + -1;
  UNLOCK();
  if (lVar1 < 2) {
    if (lVar1 == 1) {
      lVar1 = *param_1;
      if ((*(longlong **)(lVar1 + 8) == param_1) &&
         (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
        *plVar2 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar2;
        plVar2 = param_1 + 2;
        lVar1 = *plVar2;
        if ((*(longlong **)(lVar1 + 8) == plVar2) &&
           (plVar3 = (longlong *)param_1[3], (longlong *)*plVar3 == plVar2)) {
          *plVar3 = lVar1;
          *(longlong **)(lVar1 + 8) = plVar3;
          DAT_1400073f4 = DAT_1400073f4 + -1;
          ExFreePoolWithTag(param_1,0x45545049);
          return;
        }
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(0xe);
  }
  return;
}



===== IptDestroy @ 14000d15c =====

void IptDestroy(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [40];
  undefined1 local_48 [64];
  
  memset(local_48,0,0x40);
  ExWaitForRundownProtectionRelease(&IptDriverState);
  ExRundownCompleted(&IptDriverState);
  ExUnregisterExtension(DAT_140007508);
  if (IptCoreTracingControlBlock != 0) {
    IptStopTraceOnEachCore(IptCoreTracingControlBlock);
  }
  ExUnregisterExtension(DAT_140007448);
  do {
    plVar7 = (longlong *)0x0;
    puVar8 = auStack_78;
    if (DAT_1400073f0 == 0) {
LAB_14000d2b8:
      *(undefined8 *)(puVar8 + -8) = 0x14000d2c6;
      KeDeregisterBugCheckReasonCallback(&DAT_140007460);
      *(undefined8 *)(puVar8 + -8) = 0x14000d2db;
      PsSetCreateProcessNotifyRoutineEx(OnProcessCreate,1);
      *(undefined8 *)(puVar8 + -8) = 0x14000d2ee;
      PsRemoveCreateThreadNotifyRoutine(OnThreadCreate);
      *(undefined8 *)(puVar8 + -8) = 0x14000d301;
      ExUnregisterExtension(DAT_140007530);
      *(undefined8 *)(puVar8 + -8) = 0x14000d30b;
      IptFreeHashTables();
      if (DAT_140007420 != 0) {
        *(undefined8 *)(puVar8 + -8) = 0x14000d31e;
        ZwClose();
        DAT_140007420 = 0;
      }
      *(undefined8 *)(puVar8 + -8) = 0x14000d33e;
      KeInsertQueue(&DAT_140007490,puVar8 + 0x30);
      do {
        *(undefined8 *)(puVar8 + 0x20) = 0;
        *(undefined8 *)(puVar8 + -8) = 0x14000d35f;
        iVar6 = KeWaitForSingleObject(DAT_140007528,0,0,1);
      } while (iVar6 != 0);
      *(undefined8 *)(puVar8 + -8) = 0x14000d376;
      ObfDereferenceObject();
      *(undefined8 *)(puVar8 + -8) = 0x14000d382;
      SetIptInterruptHandler(0);
      return;
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_140007438,0);
    puVar5 = IptProcessList;
    if ((undefined8 **)IptProcessList != &IptProcessList) {
      if (((undefined8 **)IptProcessList[1] == &IptProcessList) &&
         (puVar1 = (undefined8 *)*IptProcessList, (undefined8 *)puVar1[1] == IptProcessList)) {
        plVar7 = IptProcessList + -2;
        IptProcessList = puVar1;
        puVar1[1] = &IptProcessList;
        lVar2 = *plVar7;
        if ((*(longlong **)(lVar2 + 8) == plVar7) &&
           (plVar3 = (longlong *)puVar5[-1], (longlong *)*plVar3 == plVar7)) {
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          DAT_1400073f0 = DAT_1400073f0 + -1;
          plVar3 = (longlong *)puVar5[5];
          if (plVar3 != (longlong *)0x0) {
            IptDerefSession(plVar3);
          }
          goto LAB_14000d268;
        }
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar8 = auStack_70;
      goto LAB_14000d2b8;
    }
LAB_14000d268:
    ExReleasePushLockExclusiveEx(&DAT_140007438,0);
    KeLeaveCriticalRegion();
    puVar8 = auStack_78;
    if (plVar7 == (longlong *)0x0) goto LAB_14000d2b8;
    RunOnEachThread(plVar7[5],StopTrace,1);
    FreeProcessContext((longlong)plVar7);
  } while( true );
}



===== IptFreeHashTables @ 14000d398 =====

void IptFreeHashTables(void)

{
  if (DAT_140007500 != 0) {
    ExFreePoolWithTag(DAT_140007500,0x54545049);
    DAT_140007500 = 0;
  }
  if (DAT_140007428 != 0) {
    ExFreePoolWithTag(DAT_140007428,0x54545049);
    DAT_140007428 = 0;
  }
  if (DAT_140007520 != 0) {
    ExFreePoolWithTag(DAT_140007520,0x54545049);
    DAT_140007520 = 0;
  }
  return;
}



===== IptGetProcessTrace @ 14000d418 =====

int IptGetProcessTrace(longlong param_1,short param_2,ulonglong *param_3,longlong param_4,
                      undefined4 param_5,uint *param_6)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong local_res20;
  longlong local_38;
  undefined4 local_30;
  uint local_2c;
  ulonglong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_res20 = 0;
  local_2c = 0;
  local_28 = 0;
  local_20 = 0;
  local_1c = 0;
  local_30 = param_5;
  local_38 = param_4;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else if (param_2 == 1) {
    iVar2 = GetProcessFromHandle(param_1,&local_res20);
    if (-1 < iVar2) {
      cVar1 = PsGetProcessExitProcessCalled(local_res20);
      iVar2 = -0x3fffffff;
      if (cVar1 == '\0') {
        uVar4 = PsGetProcessId(local_res20);
        uVar4 = IptAcquireProcessContext(uVar4);
        if (uVar4 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar4 + 0x58);
          if (cVar1 != '\0') {
            if ((((byte)*(undefined4 *)(uVar4 + 0x30) & 0xf) == 1) &&
               (uVar3 = IptCheckPrivilegeForThreadTracing((uint)*(undefined8 *)(uVar4 + 0x30)),
               -1 < (int)uVar3)) {
              RunOnEachThread(*(undefined8 *)(uVar4 + 0x28),GetTrace,&local_38);
              *param_3 = local_28;
              if (param_6 != (uint *)0x0) {
                *param_6 = local_2c;
              }
              if ((local_38 == 0) || (local_28 <= local_2c)) {
                iVar2 = 0;
              }
              else {
                iVar2 = -0x3fffffdd;
                if (local_2c != 0) {
                  iVar2 = -0x7ffffffb;
                }
              }
            }
            ExReleaseRundownProtection(uVar4 + 0x58);
          }
          ExReleaseRundownProtection(uVar4 + 0x50);
        }
      }
      if ((local_res20 != 0) && (param_1 != -1)) {
        ObfDereferenceObject(local_res20);
      }
      LeaveThreadTracingControl();
    }
  }
  else {
    iVar2 = -0x3fffff45;
  }
  return iVar2;
}



===== IptInitHashTables @ 14000d5b0 =====

undefined8 IptInitHashTables(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  
  DAT_140007500 = ExAllocatePool2(0x100,0x80000,0x54545049);
  if (((DAT_140007500 == 0) ||
      (DAT_140007428 = ExAllocatePool2(0x100,0x80000,0x54545049), DAT_140007428 == 0)) ||
     (DAT_140007520 = ExAllocatePool2(0x100,0x80000,0x54545049), DAT_140007520 == 0)) {
    IptFreeHashTables();
    return 0xc0000017;
  }
  lVar7 = DAT_140007500 - DAT_140007428;
  lVar8 = DAT_140007520 - DAT_140007428;
  lVar6 = DAT_140007428 - DAT_140007500;
  lVar4 = 0x8000;
  lVar5 = DAT_140007520 - DAT_140007500;
  lVar3 = DAT_140007500;
  do {
    *(longlong *)lVar3 = lVar3;
    lVar1 = lVar6 + lVar3;
    *(longlong *)(lVar7 + 8 + lVar1) = lVar3;
    lVar2 = lVar6 + lVar3;
    *(longlong *)(lVar1 + 8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    lVar2 = lVar5 + lVar3;
    lVar3 = lVar3 + 0x10;
    *(longlong *)(lVar1 + 8 + lVar8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return 0;
}



===== IptLookupProcessEx @ 14000d6ac =====

undefined1 IptLookupProcessEx(ulonglong param_1,undefined8 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  uVar2 = 0;
  if (DAT_1400073f0 == 0) {
    uVar2 = 0;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&DAT_140007438,0);
    bVar1 = 0;
    plVar5 = (longlong *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007500);
    plVar3 = (longlong *)*plVar5;
    plVar4 = (longlong *)0x0;
    if (plVar3 == plVar5) {
LAB_14000d72e:
      if ((-(ulonglong)bVar1 & (ulonglong)plVar4) != 0) {
        if (param_2 != (undefined8 *)0x0) {
          *param_2 = *(undefined8 *)((-(ulonglong)bVar1 & (ulonglong)plVar4) + 0x30);
        }
        uVar2 = 1;
      }
    }
    else {
      do {
        if (plVar3[4] == param_1) {
          bVar1 = 1;
          plVar4 = plVar3;
          goto LAB_14000d72e;
        }
        plVar3 = (longlong *)*plVar3;
      } while (plVar3 != plVar5);
    }
    ExReleasePushLockSharedEx(&DAT_140007438,0);
    KeLeaveCriticalRegion();
  }
  return uVar2;
}



===== IptLookupSession @ 14000d780 =====

bool IptLookupSession(undefined8 param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  bool bVar2;
  uint local_res20 [2];
  ulonglong local_18;
  undefined8 uStack_10;
  
  if (DAT_1400073f4 == 0) {
    bVar2 = false;
  }
  else {
    local_res20[0] = 0;
    local_18 = (ulonglong)CONCAT22((short)param_2,(short)param_2);
    uStack_10 = param_1;
    RtlHashUnicodeString(&local_18,0,0,local_res20);
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&DAT_140007438,0);
    puVar1 = IptLookupSessionInternal(param_1,param_2,(ulonglong)(local_res20[0] & 0x7fff));
    bVar2 = puVar1 != (undefined8 *)0x0;
    if (bVar2) {
      *param_3 = puVar1[4];
    }
    ExReleasePushLockSharedEx(&DAT_140007438,0);
    KeLeaveCriticalRegion();
  }
  return bVar2;
}



===== IptLookupSessionInternal @ 14000d868 =====

undefined8 * IptLookupSessionInternal(undefined8 param_1,uint param_2,ulonglong param_3)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  puVar2 = (undefined8 *)(DAT_140007428 + (param_3 & 0xffffffff) * 0x10);
  puVar3 = (undefined8 *)*puVar2;
  lVar4 = DAT_140007428;
  do {
    if (puVar3 == puVar2) {
      return (undefined8 *)0x0;
    }
    if (*(uint *)(puVar3 + 6) == param_2) {
      uVar1 = RtlCompareMemory((longlong)puVar3 + 0x34,param_1,(ulonglong)param_2);
      if (uVar1 == param_2) {
        return puVar3;
      }
      lVar4 = DAT_140007428;
    }
    puVar3 = (undefined8 *)*puVar3;
    puVar2 = (undefined8 *)(lVar4 + (param_3 & 0xffffffff) * 0x10);
  } while( true );
}



===== IptLookupThread @ 14000d8f8 =====

ulonglong IptLookupThread(ulonglong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 *puVar4;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&DAT_140007518,0);
  cVar3 = '\0';
  puVar4 = (undefined8 *)0x0;
  puVar2 = (undefined8 *)((ulonglong)((uint)(param_1 >> 2) & 0x7fff) * 0x10 + DAT_140007520);
  puVar1 = (undefined8 *)*puVar2;
  do {
    if (puVar1 == puVar2) {
LAB_14000d95c:
      ExReleasePushLockSharedEx(&DAT_140007518,0,-cVar3);
      KeLeaveCriticalRegion();
      return -(ulonglong)(cVar3 != '\0') & (ulonglong)puVar4;
    }
    puVar4 = puVar1 + -10;
    if (puVar1[-1] == param_1) {
      cVar3 = '\x01';
      goto LAB_14000d95c;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== IptPauseThreadTrace @ 14000d998 =====

int IptPauseThreadTrace(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  void *local_res10;
  
  local_res10 = (void *)0x0;
  *param_2 = 0;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = GetThreadFromHandle(param_1,&local_res10);
    if (-1 < iVar2) {
      cVar1 = PsIsThreadTerminating(local_res10);
      iVar2 = -0x3fffffff;
      if (cVar1 == '\0') {
        uVar3 = PsGetThreadProcess(local_res10);
        uVar4 = PsGetProcessId(uVar3);
        uVar4 = IptAcquireProcessContext(uVar4);
        if (uVar4 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar4 + 0x58);
          if (cVar1 != '\0') {
            RunOnThread(local_res10,PauseThreadTrace,param_2);
            iVar2 = 0;
            ExReleaseRundownProtection(uVar4 + 0x58);
          }
          ExReleaseRundownProtection(uVar4 + 0x50);
        }
      }
    }
    if ((local_res10 != (void *)0x0) && (param_1 != -2)) {
      ObfDereferenceObject(local_res10);
    }
    LeaveThreadTracingControl();
  }
  return iVar2;
}



===== IptQueryProcessTrace @ 14000dabc =====

int IptQueryProcessTrace(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong local_res10;
  
  local_res10 = 0;
  *param_2 = 0;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = GetProcessFromHandle(param_1,&local_res10);
    if (-1 < iVar2) {
      cVar1 = PsGetProcessExitProcessCalled(local_res10);
      iVar2 = -0x3fffffff;
      if (cVar1 == '\0') {
        uVar3 = PsGetProcessId(local_res10);
        uVar3 = IptAcquireProcessContext(uVar3);
        if (uVar3 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar3 + 0x58);
          if (cVar1 != '\0') {
            iVar2 = 0;
            *param_2 = *(undefined8 *)(uVar3 + 0x30);
            ExReleaseRundownProtection(uVar3 + 0x58);
          }
          ExReleaseRundownProtection(uVar3 + 0x50);
        }
      }
    }
    if ((local_res10 != 0) && (param_1 != -1)) {
      ObfDereferenceObject(local_res10);
    }
    LeaveThreadTracingControl();
  }
  return iVar2;
}



===== IptQueryThreadAddressFilterRange @ 14000dbc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IptQueryThreadAddressFilterRange
               (longlong param_1,uint param_2,undefined4 *param_3,undefined8 *param_4,
               undefined8 *param_5)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  void *pvVar5;
  undefined1 auStack_a8 [32];
  void *local_88;
  undefined8 *local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_a8;
  pvVar5 = (void *)0x0;
  local_78 = param_5;
  local_88 = (void *)0x0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_80 = param_4;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    uVar2 = 0xc0000001;
  }
  else {
    if (((IptCapability & 4) == 0) || ((DAT_1400075c8 & 7) <= param_2)) {
      uVar2 = 0xc00000bb;
    }
    else {
      uVar2 = GetThreadFromHandle(param_1,&local_88);
      pvVar5 = local_88;
      if (-1 < (int)uVar2) {
        cVar1 = PsIsThreadTerminating(local_88);
        uVar2 = 0xc0000001;
        if (cVar1 == '\0') {
          uVar3 = PsGetThreadProcess(pvVar5);
          uVar4 = PsGetProcessId(uVar3);
          uVar4 = IptAcquireProcessContext(uVar4);
          if (uVar4 != 0) {
            cVar1 = ExAcquireRundownProtection(uVar4 + 0x58);
            if (cVar1 != '\0') {
              if (((byte)*(undefined4 *)(uVar4 + 0x30) & 0xf) != 2) {
                uVar2 = IptCheckPrivilegeForThreadTracing((uint)*(undefined8 *)(uVar4 + 0x30));
                if (-1 < (int)uVar2) {
                  local_70 = CONCAT44(param_2,(uint)local_70);
                  RunOnThread(pvVar5,QueryThreadAddressFilterRange,&local_70);
                  uVar2 = (uint)local_70;
                }
              }
              ExReleaseRundownProtection(uVar4 + 0x58);
            }
            ExReleaseRundownProtection(uVar4 + 0x50);
            if (-1 < (int)uVar2) {
              *param_3 = (undefined4)uStack_68;
              *local_80 = local_60;
              *local_78 = uStack_58;
            }
          }
        }
      }
    }
    if ((pvVar5 != (void *)0x0) && (param_1 != -2)) {
      ObfDereferenceObject(pvVar5);
    }
    LeaveThreadTracingControl();
  }
  return uVar2;
}



===== IptQueryThreadTraceStopRangeEntered @ 14000dd78 =====

uint IptQueryThreadTraceStopRangeEntered(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  void *local_res18;
  undefined8 local_res20;
  
  local_res18 = (void *)0x0;
  local_res20 = 0;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    uVar2 = 0xc0000001;
  }
  else {
    uVar2 = GetThreadFromHandle(param_1,&local_res18);
    if (-1 < (int)uVar2) {
      cVar1 = PsIsThreadTerminating(local_res18);
      uVar2 = 0xc0000001;
      if (cVar1 == '\0') {
        uVar3 = PsGetThreadProcess(local_res18);
        uVar4 = PsGetProcessId(uVar3);
        uVar4 = IptAcquireProcessContext(uVar4);
        if (uVar4 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar4 + 0x58);
          if (cVar1 != '\0') {
            uVar2 = IptCheckPrivilegeForThreadTracing((uint)*(undefined8 *)(uVar4 + 0x30));
            if (-1 < (int)uVar2) {
              RunOnThread(local_res18,QueryThreadTraceStopRangeEntered,&local_res20);
              uVar2 = (uint)local_res20;
              if (-1 < (int)(uint)local_res20) {
                *param_2 = local_res20._4_1_;
              }
            }
            ExReleaseRundownProtection(uVar4 + 0x58);
          }
          ExReleaseRundownProtection(uVar4 + 0x50);
        }
      }
    }
    if ((local_res18 != (void *)0x0) && (param_1 != -2)) {
      ObfDereferenceObject(local_res18);
    }
    LeaveThreadTracingControl();
  }
  return uVar2;
}



===== IptQueryValueKey @ 14000dec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
IptQueryValueKey(undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5)

{
  undefined8 uVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  int *local_40;
  int local_38 [2];
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
    if ((local_30._4_4_ == param_3) && (local_38[0] - 0xcU == param_5)) {
      memmove(param_4,(void *)((longlong)&uStack_28 + 4),(ulonglong)param_5);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== IptResumeThreadTrace @ 14000df74 =====

int IptResumeThreadTrace(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined2 local_res10;
  void *local_res18;
  
  local_res18 = (void *)0x0;
  local_res10 = 0;
  *param_2 = 0;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = GetThreadFromHandle(param_1,&local_res18);
    if (-1 < iVar2) {
      cVar1 = PsIsThreadTerminating(local_res18);
      iVar2 = -0x3fffffff;
      if (cVar1 == '\0') {
        uVar3 = PsGetThreadProcess(local_res18);
        uVar4 = PsGetProcessId(uVar3);
        uVar4 = IptAcquireProcessContext(uVar4);
        if (uVar4 != 0) {
          cVar1 = ExAcquireRundownProtection(uVar4 + 0x58);
          if (cVar1 != '\0') {
            RunOnThread(local_res18,ResumeThreadTrace,&local_res10);
            iVar2 = 0;
            *param_2 = local_res10._1_1_;
            ExReleaseRundownProtection(uVar4 + 0x58);
          }
          ExReleaseRundownProtection(uVar4 + 0x50);
        }
      }
    }
    if ((local_res18 != (void *)0x0) && (param_1 != -2)) {
      ObfDereferenceObject(local_res18);
    }
    LeaveThreadTracingControl();
  }
  return iVar2;
}



===== IptServiceNeededForUserTracing @ 14000e0a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char IptServiceNeededForUserTracing(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  int iVar5;
  undefined1 auStack_4e8 [32];
  undefined4 local_4c8;
  undefined4 *local_4c0;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined8 local_4b0;
  ulonglong local_4a8;
  ushort local_4a0 [8];
  undefined8 local_490;
  longlong lStack_488;
  ushort *local_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 uStack_468;
  undefined8 local_460;
  undefined8 uStack_458;
  undefined1 local_448 [12];
  uint local_43c;
  undefined2 local_438 [256];
  undefined1 local_238 [12];
  uint local_22c;
  undefined2 local_228 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_4e8;
  memset(local_238,0,0x210);
  memset(local_448,0,0x210);
  local_4b4 = 0;
  bVar1 = false;
  local_4a8 = 0;
  local_470 = 0;
  uStack_468 = (ulonglong)uStack_468._4_4_ << 0x20;
  local_4b0 = 0;
  local_4b8 = 0;
  local_4a0[0] = 0;
  local_4a0[1] = 0;
  local_4a0[2] = 0;
  local_4a0[3] = 0;
  local_4a0[4] = 0;
  local_4a0[5] = 0;
  local_4a0[6] = 0;
  local_4a0[7] = 0;
  local_490 = 0;
  lStack_488 = 0;
  local_480 = (ushort *)0x0;
  uStack_478 = 0;
  local_460 = 0;
  uStack_458 = 0;
  if (DAT_140007420 != 0) {
    iVar5 = 0;
    bVar1 = false;
    while( true ) {
      local_4c0 = &local_4b4;
      local_4c8 = 0x210;
      iVar3 = ZwEnumerateKey(DAT_140007420,iVar5);
      if (iVar3 < 0) break;
      local_228[local_22c >> 1] = 0;
      RtlInitUnicodeString(local_4a0,local_228);
      uVar4 = GetIptOptionForTracingThreads(&local_4a8,local_4a0,0,'\0');
      if (-1 < (int)uVar4) {
        bVar1 = true;
        break;
      }
      lStack_488 = DAT_140007420;
      local_480 = local_4a0;
      local_490 = CONCAT44(local_490._4_4_,0x30);
      uStack_478 = CONCAT44(uStack_478._4_4_,0x240);
      local_470 = 0;
      uStack_468 = 0;
      iVar3 = ZwOpenKey(&local_4b0,3);
      if (-1 < iVar3) {
        iVar3 = 0;
        while( true ) {
          local_4c0 = &local_4b8;
          local_4c8 = 0x210;
          iVar2 = ZwEnumerateKey(local_4b0,iVar3);
          if (iVar2 < 0) break;
          local_438[local_43c >> 1] = 0;
          RtlInitUnicodeString(&local_460,local_438);
          uVar4 = GetIptOptionForTracingThreads(&local_4a8,local_4a0,(longlong)&local_460,'\0');
          if (-1 < (int)uVar4) {
            bVar1 = true;
            break;
          }
          iVar3 = iVar3 + 1;
        }
        ZwClose(local_4b0);
        if (bVar1) break;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return bVar1;
}



===== IptSetProcessFaultInformation @ 14000e2f0 =====

undefined8 IptSetProcessFaultInformation(longlong param_1,void *param_2,uint *param_3)

{
  longlong lVar1;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  lVar1 = PsGetCurrentProcess();
  if (((param_1 == lVar1) && (param_2 == SystemReserved1[0xf])) && ((*param_3 & 9) != 0)) {
    IptPauseThreadTrace(-2,local_res8);
  }
  return 0;
}



===== IptStartProcessTrace @ 14000e35c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IptStartProcessTrace(longlong param_1,longlong param_2,ulonglong param_3)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  bool bVar9;
  undefined1 auStack_a8 [32];
  longlong *local_88;
  ulonglong local_80;
  longlong *local_78;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  undefined2 local_50;
  undefined2 uStack_4e;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  local_60 = 0;
  plVar7 = (longlong *)0x0;
  bVar1 = false;
  lVar8 = 0;
  local_68 = param_1;
  cVar2 = EnterThreadTracingControl();
  if (cVar2 == '\0') {
    return 0xc0000001;
  }
  uVar5 = CheckIptOption(param_3);
  if ((char)uVar5 == '\0') {
LAB_14000e67b:
    uVar5 = 0xc000000d;
LAB_14000e50d:
    if ((local_60 != 0) && (param_1 != -1)) {
      ObfDereferenceObject();
    }
    if (bVar1) {
      ExReleaseRundownProtection(plVar7 + 10);
    }
  }
  else {
    if (2 < ((uint)(param_3 >> 0x18) & 0xf)) goto LAB_14000e67b;
    bVar3 = (byte)param_3 & 0xf;
    if (param_2 == 0) {
      if (bVar3 != 1) goto LAB_14000e446;
LAB_14000e45b:
      uVar4 = GetProcessFromHandle(local_68,&local_60);
      uVar5 = (ulonglong)uVar4;
      if (-1 < (int)uVar4) {
        cVar2 = PsGetProcessExitProcessCalled(local_60);
        uVar5 = 0xc0000001;
        if (cVar2 == '\0') {
          uVar6 = PsGetProcessId(local_60);
          plVar7 = (longlong *)IptAcquireProcessContext(uVar6);
          if (plVar7 == (longlong *)0x0) {
            plVar7 = AllocateProcessContext(local_60,uVar6,param_3,lVar8);
            if (plVar7 != (longlong *)0x0) {
              LOCK();
              if ((int)plVar7[9] == 0) {
                *(int *)(plVar7 + 9) = 1;
              }
              UNLOCK();
              ExAcquireRundownProtection(plVar7 + 10);
              cVar2 = IptAddProcess(uVar6,plVar7,(short *)0x0,0);
              if (cVar2 != '\0') goto LAB_14000e5f1;
              ExReleaseRundownProtection(plVar7 + 10);
              FreeProcessContext((longlong)plVar7);
            }
          }
          else {
            bVar1 = true;
            LOCK();
            bVar9 = (int)plVar7[9] == 0;
            if (bVar9) {
              *(int *)(plVar7 + 9) = 1;
            }
            UNLOCK();
            if (!bVar9) goto LAB_14000e509;
            if (lVar8 == 0) {
LAB_14000e57d:
              plVar7[6] = param_3;
LAB_14000e5f1:
              bVar1 = true;
              uVar5 = 0;
              if (plVar7[8] != 0) {
                uStack_4c = 0xffff;
                uStack_4a = 0xffff;
                local_50 = 1;
                uStack_4e = 4;
                uVar6 = IptWriteFile(plVar7[8],&local_50,8);
                uVar5 = uVar6 & 0xffffffff;
                if ((int)uVar6 < 0) {
                  if (plVar7[8] != 0) {
                    ZwClose();
                    plVar7[8] = 0;
                  }
                  goto LAB_14000e500;
                }
              }
              RunOnEachThread(plVar7[5],StartTrace,plVar7);
              ExReInitializeRundownProtection(plVar7 + 0xb);
              LOCK();
              if ((int)plVar7[9] == 1) {
                *(int *)(plVar7 + 9) = 2;
              }
              UNLOCK();
            }
            else {
              local_78 = plVar7 + 8;
              local_80 = local_80 & 0xffffffffffffff00;
              local_88 = (longlong *)0x0;
              uVar4 = ObOpenObjectByPointer(lVar8,0x200,0,4);
              uVar5 = (ulonglong)uVar4;
              if (-1 < (int)uVar4) goto LAB_14000e57d;
LAB_14000e500:
              bVar1 = true;
              LOCK();
              if ((int)plVar7[9] == 1) {
                *(int *)(plVar7 + 9) = 0;
              }
              UNLOCK();
            }
          }
        }
      }
LAB_14000e509:
      param_1 = local_68;
      goto LAB_14000e50d;
    }
    if ((((bVar3 != 2) || ((param_3 & 0xf000000) != 0)) || (((uint)param_3 >> 0x17 & 1) != 0)) ||
       (((param_3 & 0x700000) != 0 || ((param_3 & 0xf0000) == 0)))) {
LAB_14000e446:
      uVar5 = 0xc000000d;
      goto LAB_14000e551;
    }
    local_80 = 0;
    local_58 = 0;
    local_88 = &local_58;
    uVar4 = ObReferenceObjectByHandle(param_2,4,*(undefined8 *)IoFileObjectType_exref,1);
    uVar5 = (ulonglong)uVar4;
    lVar8 = local_58;
    if (-1 < (int)uVar4) goto LAB_14000e45b;
  }
  if (lVar8 != 0) {
    ObfDereferenceObject(lVar8);
  }
LAB_14000e551:
  LeaveThreadTracingControl();
  return uVar5;
}



===== IptStartTraceOnEachCoreForEtw @ 14000e690 =====

void IptStartTraceOnEachCoreForEtw(ulonglong param_1,undefined8 param_2)

{
  IptStartTraceOnEachCoreInternal(param_1,1,param_2);
  return;
}



===== IptStartTraceOnEachCoreForIoctl @ 14000e6ac =====

ulonglong IptStartTraceOnEachCoreForIoctl(void)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  ulonglong local_res8;
  undefined1 local_res10 [24];
  
  local_res8 = 0;
  if (DAT_1400073e4 == 0) {
    uVar2 = GetIptOptionForTracingCores(&local_res8,'\x01');
    if (-1 < (int)uVar2) {
      iVar1 = IptStartTraceOnEachCoreInternal(local_res8,0,local_res10);
      uVar2 = CONCAT44(extraout_var,iVar1);
    }
  }
  else {
    uVar2 = 0xc0000708;
  }
  return uVar2;
}



===== IptStartTraceOnEachCoreInternal @ 14000e6f4 =====

int IptStartTraceOnEachCoreInternal(ulonglong param_1,undefined1 param_2,undefined8 param_3)

{
  longlong lVar1;
  char cVar2;
  int extraout_EAX;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  cVar2 = EnterCoreTracingControl();
  if (cVar2 == '\0') {
    return -0x3ffff8f8;
  }
  uVar5 = (uint)param_1;
  if (((((uVar5 & 0xf000000) == 0x3000000) || ((uVar5 & 0xf000000) == 0x4000000)) ||
      ((uVar5 & 0xf000000) == 0x5000000)) &&
     ((uVar4 = CheckIptOption(param_1), (char)uVar4 != '\0' && (((byte)param_1 & 0xf) == 1)))) {
    LOCK();
    bVar7 = DAT_1400073e4 == 0;
    if (bVar7) {
      DAT_1400073e4 = 1;
    }
    UNLOCK();
    if (bVar7) {
      iVar6 = AllocateIptCoreTracingControlBlock(param_1);
      iVar3 = extraout_EAX;
      if (-1 < extraout_EAX) {
        iVar3 = KeInitializeTriageDumpDataArray
                          (*(undefined8 *)(IptCoreTracingControlBlock + 0x40),
                           *(undefined4 *)(IptCoreTracingControlBlock + 0x48));
        lVar1 = IptCoreTracingControlBlock;
        if (-1 < iVar3) {
          *(undefined1 *)(IptCoreTracingControlBlock + 0x3c) = 0;
          cVar2 = KeRegisterBugCheckReasonCallback
                            (lVar1 + 0x10,BugCheckTriageDumpDataCallback,7,"IPT");
          if (cVar2 != '\0') {
            KeIpiGenericCall(IptTraceCurrentCore,1);
            *(longlong *)CONCAT44((int)((ulonglong)param_3 >> 0x20),iVar6) =
                 IptCoreTracingControlBlock;
            DAT_1400073e0 = param_2;
            ExReInitializeRundownProtection(&DAT_1400073d8);
            LOCK();
            if (DAT_1400073e4 == 1) {
              DAT_1400073e4 = 2;
            }
            UNLOCK();
            iVar3 = 0;
            goto LAB_14000e85a;
          }
          iVar3 = -0x3fffffff;
        }
        FreeIptCoreTracingControlBlock();
      }
      LOCK();
      if (DAT_1400073e4 == 1) {
        DAT_1400073e4 = 0;
      }
      UNLOCK();
    }
    else {
      iVar3 = -0x3ffff8f8;
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
LAB_14000e85a:
  LeaveCoreTracingControl();
  return iVar3;
}



===== IptStopProcessTrace @ 14000e884 =====

int IptStopProcessTrace(longlong param_1)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  bool bVar5;
  longlong local_res10;
  
  local_res10 = 0;
  cVar1 = EnterThreadTracingControl();
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffff;
  }
  else {
    iVar2 = GetProcessFromHandle(param_1,&local_res10);
    lVar4 = local_res10;
    if (-1 < iVar2) {
      cVar1 = PsGetProcessExitProcessCalled(local_res10);
      iVar2 = -0x3fffffff;
      if (cVar1 == '\0') {
        uVar3 = PsGetProcessId(lVar4);
        uVar3 = IptAcquireProcessContext(uVar3);
        if (uVar3 != 0) {
          LOCK();
          bVar5 = *(int *)(uVar3 + 0x48) == 2;
          if (bVar5) {
            *(int *)(uVar3 + 0x48) = 3;
          }
          UNLOCK();
          if (bVar5) {
            ExWaitForRundownProtectionRelease(uVar3 + 0x58);
            ExRundownCompleted(uVar3 + 0x58);
            RunOnEachThread(*(undefined8 *)(uVar3 + 0x28),StopTrace,0);
            if (*(longlong *)(uVar3 + 0x40) != 0) {
              ZwClose();
              *(undefined8 *)(uVar3 + 0x40) = 0;
            }
            LOCK();
            if (*(int *)(uVar3 + 0x48) == 3) {
              *(int *)(uVar3 + 0x48) = 0;
            }
            UNLOCK();
            iVar2 = 0;
          }
          ExReleaseRundownProtection(uVar3 + 0x50);
          lVar4 = local_res10;
        }
      }
    }
    if ((lVar4 != 0) && (param_1 != -1)) {
      ObfDereferenceObject(lVar4);
    }
    LeaveThreadTracingControl();
  }
  return iVar2;
}



===== IptStopTraceOnEachCore @ 14000e9d0 =====

undefined8 IptStopTraceOnEachCore(longlong param_1)

{
  undefined8 uVar1;
  bool bVar2;
  
  if (param_1 == IptCoreTracingControlBlock) {
    LOCK();
    bVar2 = DAT_1400073e4 == 2;
    if (bVar2) {
      DAT_1400073e4 = 3;
    }
    UNLOCK();
    if (bVar2) {
      ExWaitForRundownProtectionRelease(&DAT_1400073d8);
      ExRundownCompleted(&DAT_1400073d8);
      KeIpiGenericCall(IptTraceCurrentCore,0);
      if (*(longlong *)(IptCoreTracingControlBlock + 0x40) != 0) {
        KeDeregisterBugCheckReasonCallback(IptCoreTracingControlBlock + 0x10);
      }
      FreeIptCoreTracingControlBlock();
      DAT_1400073e0 = 0;
      LOCK();
      if (DAT_1400073e4 == 3) {
        DAT_1400073e4 = 0;
      }
      UNLOCK();
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000008;
  }
  return uVar1;
}



===== IptTraceLogThreadEntry @ 14000ea90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IptTraceLogThreadEntry(void)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  ulonglong local_30;
  undefined4 uStack_28;
  uint uStack_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  while( true ) {
    lVar4 = KeRemoveQueue(&DAT_140007490,0,0);
    lVar1 = *(longlong *)(lVar4 + 0x30);
    if (lVar1 == 0) break;
    local_38 = *(undefined8 *)(lVar1 + 0x48);
    local_30 = CONCAT44(*(uint *)(lVar1 + 0x10) >> 8,*(uint *)(lVar1 + 0x10) >> 4) & 0xf0000000f;
    local_20 = *(undefined8 *)(lVar1 + 0x118);
    _uStack_28 = CONCAT44(*(undefined4 *)(lVar1 + 0x110),PRatio);
    uVar3 = IptWriteFile(*(undefined8 *)(lVar4 + 0x28),&local_38,0x20);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      uVar3 = IptWriteFile(*(undefined8 *)(lVar4 + 0x28),*(undefined8 *)(lVar1 + 0x28),uStack_24);
      iVar2 = (int)uVar3;
    }
    *(int *)(lVar4 + 0x38) = iVar2;
    KeSetEvent(lVar4 + 0x10);
  }
  PsTerminateSystemThread(0);
  return;
}



===== IptWriteFile @ 14000eb98 =====

ulonglong IptWriteFile(undefined8 param_1,undefined8 param_2,uint param_3)

{
  ulonglong uVar1;
  ulonglong local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = ZwWriteFile(0,0,0,0,&local_18,param_2,param_3,0,0);
  if ((-1 < (int)uVar1) && (uVar1 = local_18 & 0xffffffff, -1 < (int)local_18)) {
    uVar1 = (ulonglong)(-(uint)((uint)uStack_10 < param_3) & 0xc0000001);
  }
  return uVar1;
}



===== LeaveCoreTracingControl @ 14000ebfc =====

void LeaveCoreTracingControl(void)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007450,0);
  DAT_1400073e8 = DAT_1400073e8 + -1;
  ExReleasePushLockExclusiveEx(&DAT_140007450,0);
  KeLeaveCriticalRegion();
  return;
}



===== LeaveThreadTracingControl @ 14000ec54 =====

void LeaveThreadTracingControl(void)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_140007450,0);
  DAT_1400073ec = DAT_1400073ec + -1;
  ExReleasePushLockExclusiveEx(&DAT_140007450,0);
  KeLeaveCriticalRegion();
  return;
}



===== OnProcessCreate @ 14000ecb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000ee79) */
/* WARNING: Removing unreachable block (ram,0x00014000ee90) */
/* WARNING: Removing unreachable block (ram,0x00014000ee9f) */
/* WARNING: Removing unreachable block (ram,0x00014000eea6) */
/* WARNING: Removing unreachable block (ram,0x00014000eece) */
/* WARNING: Removing unreachable block (ram,0x00014000eee8) */
/* WARNING: Removing unreachable block (ram,0x00014000ef0c) */
/* WARNING: Removing unreachable block (ram,0x00014000ef1a) */
/* WARNING: Removing unreachable block (ram,0x00014000eef7) */
/* WARNING: Removing unreachable block (ram,0x00014000ef00) */

void OnProcessCreate(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  ushort *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  short *psVar9;
  uint uVar10;
  undefined1 auStackY_248 [32];
  ulonglong local_210 [2];
  int local_200 [2];
  undefined8 local_1f8;
  ulonglong local_1f0 [3];
  undefined1 local_1d8 [400];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_248;
  local_1f0[0] = 0;
  local_210[1] = 0;
  local_1f0[1] = 0;
  local_1f0[2] = 0;
  if (param_3 == 0) {
    puVar5 = IptDeleteProcess(param_2);
    if (puVar5 == (undefined8 *)0x0) {
      return;
    }
    FreeProcessContext((longlong)puVar5);
    return;
  }
  cVar2 = ExAcquireRundownProtection(&IptDriverState);
  if (cVar2 == '\0') {
    return;
  }
  cVar2 = EnterThreadTracingControl();
  if (cVar2 == '\0') goto LAB_14000eff5;
  if (*(ushort **)(param_3 + 0x30) == (ushort *)0x0) {
LAB_14000edb8:
    local_210[0] = 0;
    psVar9 = (short *)0x0;
    uVar10 = 0;
    cVar2 = IptLookupProcessEx(*(ulonglong *)(param_3 + 0x10),local_1f0);
    if ((cVar2 == '\0') || (((uint)local_1f0[0] >> 0x17 & 1) == 0)) {
      puVar1 = *(ushort **)(param_3 + 0x30);
      if ((puVar1 == (ushort *)0x0) ||
         (bVar3 = IptLookupSession(*(undefined8 *)(puVar1 + 4),(uint)*puVar1,local_210), !bVar3)) {
        local_210[1] = 0x100;
        uVar6 = PsReferencePrimaryToken(param_1);
        RtlQueryPackageIdentity(uVar6,local_1d8);
        ObfDereferenceObject(uVar6);
        if ((*(ushort **)(param_3 + 0x30) == (ushort *)0x0) ||
           (uVar7 = GetIptOptionForTracingThreads(local_210,*(ushort **)(param_3 + 0x30),0,'\x01'),
           (int)uVar7 < 0)) {
          uVar7 = GetIptOptionForTracingThreads(local_210,(ushort *)&DAT_140007080,0,'\x01');
          if ((int)uVar7 < 0) goto LAB_14000eff0;
        }
        else if (((uint)local_210[0] & 0x700000) == 0x100000) goto LAB_14000ee08;
      }
      else {
LAB_14000ee08:
        psVar9 = *(short **)(*(ushort **)(param_3 + 0x30) + 4);
        uVar10 = (uint)**(ushort **)(param_3 + 0x30);
      }
    }
    else {
      local_210[0] = local_1f0[0];
    }
    if (((byte)local_210[0] & 0xf) == 1) {
      if ((psVar9 == (short *)0x0) || (uVar10 == 0)) {
        local_210[0] = local_210[0] & 0xffffffffff8fffff;
      }
      plVar8 = AllocateProcessContext(param_1,param_2,local_210[0],0);
      if (plVar8 != (longlong *)0x0) {
        LOCK();
        if ((int)plVar8[9] == 0) {
          *(int *)(plVar8 + 9) = 1;
        }
        UNLOCK();
        cVar2 = IptAddProcess(param_2,plVar8,psVar9,uVar10);
        if (cVar2 == '\0') {
          FreeProcessContext((longlong)plVar8);
        }
        else {
          ExReInitializeRundownProtection(plVar8 + 0xb);
          LOCK();
          if ((int)plVar8[9] == 1) {
            *(int *)(plVar8 + 9) = 2;
          }
          UNLOCK();
        }
      }
    }
  }
  else {
    local_1f8 = 0;
    local_200[0] = 0;
    iVar4 = OpenImageIFEOKey(&local_1f8,*(ushort **)(param_3 + 0x30),0,'\0');
    if (iVar4 < 0) goto LAB_14000edb8;
    uVar6 = IptQueryValueKey(local_1f8,&DAT_1400070c0,4,local_200,4);
    ZwClose(local_1f8);
    if (((int)uVar6 < 0) || (local_200[0] == 0)) goto LAB_14000edb8;
  }
LAB_14000eff0:
  LeaveThreadTracingControl();
LAB_14000eff5:
  ExReleaseRundownProtection(&IptDriverState);
  return;
}



===== OnThreadCreate @ 14000f040 =====

void OnThreadCreate(ulonglong param_1,undefined8 param_2,ulonglong param_3)

{
  char cVar1;
  ulonglong uVar2;
  
  if ((char)param_3 == '\0') {
    StopTrace('\x01',param_2,param_3);
  }
  else if (DAT_1400073f0 != 0) {
    cVar1 = ExAcquireRundownProtection(&IptDriverState);
    if (cVar1 != '\0') {
      uVar2 = IptAcquireProcessContext(param_1);
      if (uVar2 != 0) {
        cVar1 = ExAcquireRundownProtection(uVar2 + 0x58);
        if (cVar1 != '\0') {
          StartTrace(uVar2);
          ExReleaseRundownProtection(uVar2 + 0x58);
        }
        ExReleaseRundownProtection(uVar2 + 0x50);
      }
      ExReleaseRundownProtection(&IptDriverState);
    }
  }
  return;
}



===== OpenImageIFEOKey @ 14000f0f8 =====

int OpenImageIFEOKey(undefined8 *param_1,ushort *param_2,longlong param_3,char param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 local_68;
  undefined8 local_60;
  short local_58;
  short local_56;
  undefined4 local_54;
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  longlong local_40;
  short *local_38;
  int local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_68 = 0;
  local_54 = 0;
  local_44 = 0;
  local_2c = 0;
  local_60 = 0;
  if ((DAT_140007420 == 0) &&
     (RtlRunOnceExecuteOnce(&DAT_140007550,InitIFEOKey,0,0), DAT_140007420 == 0)) {
    iVar3 = -0x3fffffff;
  }
  else {
    uVar1 = *param_2;
    uVar2 = uVar1;
    for (local_50 = (ulonglong)uVar1 + *(longlong *)(param_2 + 4);
        (uVar2 != 0 && (*(short *)(local_50 + -2) != 0x5c)); local_50 = local_50 + -2) {
      uVar2 = uVar2 - 2;
    }
    if (uVar1 < uVar2) {
      iVar3 = -0x3fffffdd;
    }
    else {
      local_58 = uVar1 - uVar2;
      local_56 = local_58;
      uVar4 = Feature_3345721656__private_IsEnabledDeviceUsageNoInline();
      local_40 = DAT_140007420;
      local_48 = 0x30;
      local_28 = 0;
      uStack_20 = 0;
      if ((int)uVar4 == 0) {
        local_30 = 0x240;
      }
      else {
        local_30 = (-(uint)(param_4 != '\0') & 0x400) + 0x240;
      }
      local_38 = &local_58;
      if (param_4 == '\0') {
        iVar3 = ZwOpenKey(&local_68,3,&local_48);
      }
      else {
        iVar3 = ZwCreateKey();
      }
      if (-1 < iVar3) {
        if (param_3 == 0) {
          *param_1 = local_68;
        }
        else {
          uVar4 = Feature_3345721656__private_IsEnabledDeviceUsageNoInline();
          local_48 = 0x30;
          local_40 = local_68;
          local_28 = 0;
          uStack_20 = 0;
          if ((int)uVar4 == 0) {
            local_30 = 0x240;
          }
          else {
            local_30 = (-(uint)(param_4 != '\0') & 0x400) + 0x240;
          }
          local_38 = (short *)param_3;
          if (param_4 == '\0') {
            iVar3 = ZwOpenKey(&local_60,3,&local_48);
          }
          else {
            iVar3 = ZwCreateKey();
          }
          ZwClose(local_68);
          if (-1 < iVar3) {
            *param_1 = local_60;
          }
        }
      }
    }
  }
  return iVar3;
}



===== OpenIptServiceKey @ 14000f324 =====

void OpenIptServiceKey(void)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x240;
  local_28 = &DAT_140007010;
  local_18 = 0;
  uStack_10 = 0;
  ZwOpenKey(0,3,&local_38);
  return;
}



===== PauseThreadTrace @ 14000f380 =====

void PauseThreadTrace(undefined1 *param_1)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong uVar3;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    KeEnterGuardedRegion();
  }
  uVar1 = rdmsr(0x570);
  uVar3 = uVar1 & 0xffffffff00000000;
  if (param_1 != (undefined1 *)0x0) {
    uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)uVar1) & 0xffffffffffffff01;
    *param_1 = (char)uVar3;
  }
  if ((uVar1 & 1) != 0) {
    uVar3 = uVar1 >> 0x20;
    wrmsr(0x570,uVar3 << 0x20 | uVar1 & 0xfffffffe);
  }
  if (cVar2 == '\0') {
    KeLeaveGuardedRegion(0x570,uVar3);
  }
  return;
}



===== QueryThreadAddressFilterRange @ 14000f400 =====

void QueryThreadAddressFilterRange(undefined4 *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  
  cVar4 = KeGetCurrentIrql();
  if (cVar4 == '\0') {
    KeEnterGuardedRegion();
  }
  uVar1 = rdmsr(0x570);
  if ((uVar1 & 1) != 0) {
    wrmsr(0x570,uVar1 & 0xfffffffffffffffe);
  }
  uVar2 = rdmsr(0x570);
  iVar5 = param_1[1] * 2;
  param_1[2] = (uint)(uVar2 >> (((char)param_1[1] + '\b') * '\x04' & 0x3fU)) & 0xf;
  uVar3 = rdmsr(iVar5 + 0x580);
  iVar5 = iVar5 + 0x581;
  *(undefined8 *)(param_1 + 4) = uVar3;
  uVar2 = rdmsr(iVar5);
  *param_1 = 0;
  uVar6 = uVar2 & 0xffffffff00000000;
  *(ulonglong *)(param_1 + 6) = uVar2;
  if ((uVar1 & 1) != 0) {
    iVar5 = 0x570;
    uVar1 = rdmsr(0x570);
    uVar6 = uVar1 & 0xffffffff00000000;
    if ((uVar1 & 1) == 0) {
      uVar6 = uVar1 >> 0x20;
      wrmsr(0x570,uVar6 << 0x20 | uVar1 & 0xffffffff | 1);
    }
  }
  if (cVar4 == '\0') {
    KeLeaveGuardedRegion(iVar5,uVar6);
  }
  return;
}



===== QueryThreadTraceStopRangeEntered @ 14000f4f0 =====

void QueryThreadTraceStopRangeEntered(undefined4 *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  cVar3 = KeGetCurrentIrql();
  if (cVar3 == '\0') {
    KeEnterGuardedRegion();
  }
  uVar1 = rdmsr(0x570);
  if ((uVar1 & 1) != 0) {
    wrmsr(0x570,uVar1 & 0xfffffffffffffffe);
  }
  uVar4 = 0x571;
  uVar2 = rdmsr(0x571);
  uVar5 = uVar2 & 0xffffffff00000000;
  if ((uVar2 & 0x20) != 0) {
    *(undefined1 *)(param_1 + 1) = 1;
  }
  *param_1 = 0;
  if ((uVar1 & 1) != 0) {
    uVar4 = 0x570;
    uVar1 = rdmsr(0x570);
    uVar5 = uVar1 & 0xffffffff00000000;
    if ((uVar1 & 1) == 0) {
      uVar5 = uVar1 >> 0x20;
      wrmsr(0x570,uVar5 << 0x20 | uVar1 & 0xffffffff | 1);
    }
  }
  if (cVar3 == '\0') {
    KeLeaveGuardedRegion(uVar4,uVar5);
  }
  return;
}



===== ResumeThreadTrace @ 14000f5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ResumeThreadTrace(char *param_1)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong uVar3;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    KeEnterGuardedRegion();
  }
  uVar3 = (**(code **)(DAT_140007510 + 8))(SystemReserved1[0xf]);
  if ((int)uVar3 == 0) {
    uVar3 = rdmsr(0x571);
    if ((uVar3 & 0x20) != 0) {
      wrmsr(0x571,uVar3 & 0xffffffffffffffdf);
    }
    uVar1 = rdmsr(0x570);
    uVar3 = uVar1;
    if (param_1 + 1 != (char *)0x0) {
      uVar3 = uVar1 & 0xffffffffffffff01;
      param_1[1] = (char)uVar3;
    }
    if ((uVar1 & 1) == 0) {
      if (*param_1 != '\0') {
        wrmsr(0x561,0);
        wrmsr(0x571,0);
      }
      uVar3 = uVar1 | 1;
      wrmsr(0x570,uVar1 & 0xffffffff00000000 | uVar1 & 0xffffffff | 1);
    }
  }
  else {
    param_1[1] = '\0';
  }
  if (cVar2 == '\0') {
    uVar3 = KeLeaveGuardedRegion();
  }
  return uVar3;
}



===== RunOnEachThread @ 14000f698 =====

void RunOnEachThread(undefined8 param_1,undefined *param_2,undefined8 param_3)

{
  void *pvVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res20;
  void **in_stack_ffffffffffffffc8;
  void *local_28 [2];
  
  local_res20 = 0;
  lVar3 = 0;
  while( true ) {
    iVar2 = ZwGetNextThread(param_1,lVar3,0,0x200,
                            (ulonglong)in_stack_ffffffffffffffc8 & 0xffffffff00000000,&local_res20);
    if (lVar3 != 0) {
      ZwClose(lVar3);
    }
    lVar3 = local_res20;
    if (iVar2 < 0) break;
    local_28[0] = (void *)0x0;
    in_stack_ffffffffffffffc8 = local_28;
    iVar2 = ObReferenceObjectByHandle
                      (local_res20,0,*(undefined8 *)PsThreadType_exref,0,in_stack_ffffffffffffffc8,0
                      );
    pvVar1 = local_28[0];
    if (-1 < iVar2) {
      RunOnThread(local_28[0],param_2,param_3);
      ObfDereferenceObject(pvVar1);
    }
  }
  return;
}



===== RunOnThread @ 14000f784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RunOnThread(void *param_1,undefined *param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined2 local_38;
  undefined1 local_36;
  undefined4 local_35;
  undefined1 local_31;
  undefined *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_36 = 0;
  local_35 = 0;
  local_31 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_18 = 0;
  local_30 = param_2;
  if (param_1 == SystemReserved1[0xf]) {
    (*(code *)param_2)(param_3);
  }
  else {
    KeInitializeApc(&local_88,param_1,0,RunOnThreadApc,RunOnThreadApcRundown,0,0,0);
    KeInitializeEvent(&local_28,1);
    cVar1 = KeInsertQueueApc(&local_88,&local_88,param_3,0);
    if (cVar1 != '\0') {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
  }
  return;
}



===== RunOnThreadApc @ 14000f8b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RunOnThreadApc(void)

{
  longlong lVar1;
  longlong *in_R9;
  undefined8 *in_stack_00000028;
  
  lVar1 = *in_R9;
  (**(code **)(lVar1 + 0x58))(*in_stack_00000028);
  KeSetEvent(lVar1 + 0x60,0,0);
  return;
}



===== RunOnThreadApcRundown @ 14000f8f0 =====

void RunOnThreadApcRundown(longlong param_1)

{
  KeSetEvent(param_1 + 0x60,0,0);
  return;
}



===== SetIptInterruptHandler @ 14000f918 =====

int SetIptInterruptHandler(undefined8 param_1)

{
  int iVar1;
  undefined8 local_58;
  undefined8 *local_50;
  int local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  code *local_18;
  undefined8 *local_10;
  
  local_48 = 0;
  local_20 = 0;
  local_44 = 0;
  local_30 = 0;
  local_50 = &local_40;
  local_40 = 0;
  uStack_38 = 0;
  local_58 = param_1;
  KeInitializeEvent(&local_40,1);
  local_28 = 0;
  local_18 = SetIptInterruptHandlerWorker;
  local_10 = &local_58;
  ExQueueWorkItem(&local_28,0);
  iVar1 = KeWaitForSingleObject(&local_40,0,0,0,0);
  if (iVar1 < 0) {
    local_48 = iVar1;
  }
  return local_48;
}



===== SetIptInterruptHandlerWorker @ 14000f9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SetIptInterruptHandlerWorker(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(HalDispatchTable_exref + 0x10))(0x13,8,param_1);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  KeSetEvent(*(undefined8 *)(param_1 + 8),0,0);
  return;
}



===== SetIptOption @ 14000fa1c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SetIptOption(undefined8 param_1,ulonglong param_2,uint param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong local_res10;
  uint local_res18 [4];
  int local_48;
  int local_44;
  longlong local_40;
  longlong local_38 [2];
  
  local_40 = 0;
  local_44 = 0;
  local_res10 = param_2;
  local_res18[0] = param_3;
  uVar3 = CheckIptOption(param_2);
  if ((char)uVar3 != '\0') {
    bVar1 = true;
    if (((byte)local_res10 & 0xf) == 1) {
      if (((((uint)local_res10 & 0xf000000) < 0x2000001) && (DAT_140007440 != 0xffffffff)) &&
         (((byte)DAT_140007408 & 2) == 0)) {
        uVar8 = 0x10000;
        if (DAT_140007440 < 0x10000) {
          uVar8 = DAT_140007440;
        }
        uVar6 = (uint)local_res10 >> 0x10 & 0xf;
        if (uVar8 < (uint)(1 << (char)uVar6 + 0xc)) {
          uVar7 = uVar6 - 1;
          if (0 < (int)uVar7) {
            iVar5 = uVar6 + 0xb;
            do {
              if ((uint)(1 << ((byte)iVar5 & 0x1f)) <= uVar8) break;
              uVar7 = uVar7 - 1;
              iVar5 = iVar5 + -1;
            } while (0 < (int)uVar7);
          }
          local_res10 = CONCAT44(local_res10._4_4_,
                                 (uVar7 & 0xf) << 0x10 | (uint)local_res10 & 0xfff0ffff);
        }
      }
      local_48 = 0;
      uVar4 = IptQueryValueKey(param_1,&DAT_140007050,4,&local_48,4);
      if ((((int)uVar4 + 0x80000000U & 0x80000000) == 0) && ((int)uVar4 != -0x3fffffcc)) {
        return uVar4;
      }
      if (local_48 != 0) {
        return 0xc0000001;
      }
      uVar4 = IptQueryValueKey(param_1,&DAT_140007040,0xb,&local_40,8);
      if ((int)uVar4 < 0) {
        if ((int)uVar4 != -0x3fffffcc) {
          return uVar4;
        }
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      uVar4 = IptQueryValueKey(param_1,&DAT_140007000,4,&local_44,4);
      if ((int)uVar4 < 0) {
        if ((int)uVar4 != -0x3fffffcc) {
          return uVar4;
        }
        bVar1 = false;
      }
      if (((bVar2) && (bVar1)) && ((_DAT_fffff78000000014 <= local_40 && (local_44 != 0)))) {
        if ((param_4 == 0) || (local_res18[0] == 0)) {
          param_4 = 0;
          local_res18[0] = 0;
        }
        else {
          if (local_44 == -0x1234568) {
            return 0xc0000001;
          }
          if (local_res18[0] != 0xfedcba98) {
            return 0xc0000001;
          }
        }
      }
      local_38[0] = (ulonglong)param_4 * 10000000 + _DAT_fffff78000000014;
      uVar4 = ZwSetValueKey(param_1,&DAT_140007040,0,0xb,local_38,8);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      if ((local_res18[0] != 0xfedcba98) && (8 < local_res18[0])) {
        local_res18[0] = 8;
      }
      uVar4 = ZwSetValueKey(param_1,&DAT_140007000,0,4,local_res18,4);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar4 = ZwSetValueKey(param_1,&DAT_1400070d0,0,0xb,&local_res10,8);
      return uVar4;
    }
  }
  return 0xc000000d;
}



===== SetIptOptionForTracingCores @ 14000fcb8 =====

ulonglong SetIptOptionForTracingCores(ulonglong param_1,uint param_2,uint param_3)

{
  char cVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_res8 = 0;
  local_18 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (undefined *)0x0;
  uStack_20 = 0;
  if (((uint)(param_1 >> 0x18) & 0xf) - 3 < 3) {
    uVar2 = Feature_72067384__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      uVar2 = OpenIptServiceKey();
    }
    else {
      cVar1 = ExGetPreviousMode();
      uStack_30 = 0;
      local_38 = CONCAT44(local_38._4_4_,0x30);
      uVar3 = 0x640;
      if (cVar1 != '\x01') {
        uVar3 = 0x240;
      }
      local_28 = &DAT_140007070;
      uStack_20 = CONCAT44(uStack_20._4_4_,uVar3);
      local_18 = 0;
      uStack_10 = 0;
      uVar2 = ZwOpenKey(&local_res8,3,&local_38);
    }
    if (-1 < (int)uVar2) {
      uVar2 = SetIptOption(local_res8,param_1,param_2,param_3);
      uVar2 = uVar2 & 0xffffffff;
      ZwClose(local_res8);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== StartTrace @ 14000fdc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int StartTrace(longlong param_1)

{
  longlong lVar1;
  void *pvVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  longlong *local_res8;
  
  cVar3 = KeGetCurrentIrql();
  if (cVar3 == '\0') {
    KeEnterGuardedRegion();
  }
  if ((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x48) == 3)) {
LAB_14000ff87:
    iVar5 = -0x3fffffff;
  }
  else {
    uVar6 = rdmsr(0x570);
    if ((uVar6 & 1) == 0) {
      cVar4 = PsIsThreadTerminating(SystemReserved1[0xf]);
      if (cVar4 != '\0') goto LAB_14000ff87;
      uVar6 = PsGetCurrentThreadId();
      local_res8 = (longlong *)IptLookupThread(uVar6);
      pvVar2 = SystemReserved1[0xf];
      lVar1 = *(longlong *)(param_1 + 0x40);
      if (local_res8 == (longlong *)0x0) {
        lVar7 = PsGetCurrentThreadId();
        iVar5 = AllocateTraceContext(*(longlong *)(param_1 + 0x30),pvVar2,lVar7,lVar1,&local_res8);
        if (iVar5 < 0) goto LAB_14000ff8c;
        IptAddThread(local_res8[9],(longlong)local_res8);
      }
      else {
        iVar5 = AllocateTraceBuffer(local_res8,*(longlong *)(param_1 + 0x30),lVar1,
                                    SystemReserved1[0xf]);
        if (iVar5 < 0) goto LAB_14000ff8c;
      }
      (*(code *)*DAT_140007510)(SystemReserved1[0xf],0);
      uVar6 = ComputeIptCtlMsr((uint)*(undefined8 *)(param_1 + 0x30));
      uVar8 = 0;
      if ((DAT_1400075c8 & 7) != 0) {
        iVar5 = 0x581;
        do {
          wrmsr(iVar5 + -1,0);
          wrmsr(iVar5,0);
          uVar8 = uVar8 + 1;
          iVar5 = iVar5 + 2;
        } while (uVar8 < (DAT_1400075c8 & 7));
      }
      if (((byte)*(undefined4 *)(param_1 + 0x30) & 0xf) == 2) {
        wrmsr(0x580,local_res8);
      }
      wrmsr(0x571,0);
      wrmsr(0x561,0);
      wrmsr(0x560,local_res8[1]);
      wrmsr(0x570,uVar6);
    }
    iVar5 = 0;
  }
LAB_14000ff8c:
  if (cVar3 == '\0') {
    KeLeaveGuardedRegion();
  }
  return iVar5;
}



===== StopTrace @ 14000ffc0 =====

void StopTrace(char param_1,undefined8 param_2,ulonglong param_3)

{
  ulonglong uVar1;
  char cVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    KeEnterGuardedRegion();
  }
  plVar3 = (longlong *)PsGetCurrentThreadId();
  if (param_1 == '\0') {
    plVar4 = (longlong *)IptLookupThread((ulonglong)plVar3);
  }
  else {
    plVar4 = IptDeleteThread((ulonglong)plVar3);
  }
  if (plVar4 != (longlong *)0x0) {
    if (((byte)plVar4[2] & 0xf) == 2) {
      uVar1 = rdmsr(0x570);
      if ((uVar1 & 1) != 0) {
        wrmsr(0x570,uVar1 & 0xfffffffffffffffe);
      }
      KeRemoveQueueDpcEx(plVar4 + 0xf);
      KeRemoveQueueApc(plVar4 + 0x17);
      param_3 = 0;
      param_2 = 0;
      plVar3 = plVar4;
      WriteTrace((longlong)plVar4,(byte *)0x0,(byte *)0x0,(byte *)0x0);
    }
    ClearIptState(plVar3,param_2,param_3);
    FreeTraceBuffer(plVar4);
    if (param_1 != '\0') {
      ExFreePoolWithTag(plVar4,0x4e545049);
    }
  }
  if (cVar2 == '\0') {
    KeLeaveGuardedRegion();
  }
  return;
}



===== WriteTrace @ 1400100cc =====

undefined4 WriteTrace(longlong param_1,byte *param_2,byte *param_3,byte *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_48 [16];
  undefined1 local_38 [24];
  undefined8 local_20;
  longlong local_18;
  undefined4 local_10;
  
  memset(local_48,0,0x40);
  uVar1 = rdmsr(0x570);
  if (param_2 != (byte *)0x0) {
    *param_2 = (byte)uVar1 & 1;
  }
  if ((uVar1 & 1) != 0) {
    wrmsr(0x570,uVar1 & 0xfffffffffffffffe);
  }
  uVar1 = rdmsr(0x571);
  if (param_3 != (byte *)0x0) {
    *param_3 = (byte)uVar1 >> 5 & 1;
  }
  if (param_4 != (byte *)0x0) {
    *param_4 = (byte)uVar1 >> 4 & 1;
  }
  uVar4 = 0;
  if ((uVar1 & 0x10) == 0) {
    uVar2 = rdmsr(0x561);
    *(ulonglong *)(param_1 + 0x118) = uVar1;
    iVar3 = ((uint)(uVar2 >> 7) & 0x1ffffff) * *(int *)(param_1 + 0x1c) + (int)(uVar2 >> 0x20);
    *(int *)(param_1 + 0x110) = iVar3;
    if (iVar3 != 0) {
      local_20 = *(undefined8 *)(param_1 + 0x70);
      local_18 = param_1;
      KeInitializeEvent(local_38,1,0);
      KeInsertQueue(&DAT_140007490,local_48);
      KeWaitForSingleObject(local_38,0,0,0,0);
      uVar4 = local_10;
    }
  }
  return uVar4;
}



===== IptControl @ 140010230 =====

uint IptControl(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  int *piVar8;
  ulonglong uVar9;
  uint local_res10 [2];
  
  bVar5 = false;
  cVar6 = ExAcquireRundownProtection(&IptDriverState);
  if (cVar6 == '\0') {
    uVar7 = 0xc0000010;
  }
  else {
    bVar5 = true;
    if (*(char *)(param_2 + 0x40) == '\x01') {
      lVar3 = *(longlong *)(param_2 + 0xb8);
      uVar9 = 8;
      uVar7 = *(uint *)(lVar3 + 0x10);
      uVar1 = *(uint *)(lVar3 + 8);
      local_res10[0] = uVar1;
      if ((7 < uVar7) && (uVar1 != 0)) {
        iVar2 = *(int *)(lVar3 + 0x18);
        piVar4 = *(int **)(param_2 + 0x18);
        if (iVar2 == 0x220004) {
          piVar8 = piVar4;
        }
        else {
          if (iVar2 != 0x220006) goto LAB_14001039f;
          lVar3 = *(longlong *)(param_2 + 8);
          if ((*(byte *)(lVar3 + 10) & 5) == 0) {
            piVar8 = (int *)MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000020);
          }
          else {
            piVar8 = *(int **)(lVar3 + 0x18);
          }
          if (piVar8 == (int *)0x0) {
            uVar7 = 0xc000009a;
            goto LAB_1400103a4;
          }
        }
        if (piVar4[1] == 0) {
          if (uVar7 == 8) {
            if (7 < uVar1) {
              uVar7 = 0;
              *piVar8 = 1;
              piVar8[1] = piVar4[1];
              goto LAB_1400103a6;
            }
          }
          else {
            if ((iVar2 == 0x220004) && (uVar7 < uVar1)) {
              memset((void *)((longlong)piVar8 + (ulonglong)uVar7),0,(ulonglong)(uVar1 - uVar7));
            }
            if (*piVar4 != 1) goto LAB_14001027f;
            if ((0x2f < uVar7) && (0x17 < uVar1)) {
              uVar7 = ProcessMsgV1(piVar4 + 2,uVar7 - 8,(undefined8 *)piVar8,(int *)local_res10);
              if ((uVar7 & 0xc0000000) != 0xc0000000) {
                uVar9 = (ulonglong)local_res10[0];
                goto LAB_1400103a6;
              }
              goto LAB_1400103a4;
            }
          }
        }
      }
LAB_14001039f:
      uVar7 = 0xc000000d;
    }
    else {
LAB_14001027f:
      uVar7 = 0xc00000bb;
    }
  }
LAB_1400103a4:
  uVar9 = 0;
LAB_1400103a6:
  *(ulonglong *)(param_2 + 0x38) = uVar9;
  *(uint *)(param_2 + 0x30) = uVar7;
  IofCompleteRequest(param_2,0);
  if (bVar5) {
    ExReleaseRundownProtection(&IptDriverState);
  }
  return uVar7;
}



===== IptCreateClose @ 140010400 =====

undefined8 IptCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== IptDispatchShutdown @ 140010430 =====

undefined8 IptDispatchShutdown(undefined8 param_1,longlong param_2)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong local_res10 [3];
  
  local_res10[0] = 0;
  uVar2 = GetIptOptionForTracingCores(local_res10,'\0');
  if ((int)uVar2 < 0) {
    RemoveIptAutoLogger();
    cVar1 = IptServiceNeededForUserTracing();
    if (cVar1 == '\0') {
      SetIptServiceMode(3);
    }
  }
  IptDestroy();
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== IptUnload @ 1400104a0 =====

void IptUnload(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong local_res8 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = *(longlong *)(param_1 + 8);
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  IoDeleteSymbolicLink(&local_18);
  IoUnregisterShutdownNotification(lVar1);
  if (lVar1 != 0) {
    IoDeleteDevice(lVar1);
  }
  local_res8[0] = 0;
  uVar3 = GetIptOptionForTracingCores(local_res8,'\0');
  if ((int)uVar3 < 0) {
    RemoveIptAutoLogger();
    cVar2 = IptServiceNeededForUserTracing();
    if (cVar2 == '\0') {
      SetIptServiceMode(3);
    }
  }
  IptDestroy();
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



===== ProcessMsgV1 @ 140010588 =====

uint ProcessMsgV1(int *param_1,uint param_2,undefined8 *param_3,int *param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong *puVar10;
  longlong lVar11;
  undefined1 local_res8 [8];
  ulonglong local_res20;
  ulonglong local_58;
  undefined8 local_50;
  ulonglong local_48;
  longlong lStack_40;
  ulonglong local_38;
  int *piStack_30;
  
  iVar7 = *param_4;
  iVar3 = *param_1;
  uVar9 = 0;
  local_50 = 0;
  local_58 = 0;
  local_res20 = local_res20 & 0xffffffff00000000;
  local_res8[0] = 0;
  *param_4 = 0x18;
  local_38 = 0;
  piStack_30 = (int *)0x0;
  local_48 = 0;
  lStack_40 = 0;
  if (iVar3 < 9) {
    if (iVar3 == 8) {
      uVar6 = IptResumeThreadTrace(*(longlong *)(param_1 + 2),local_res8);
      *(undefined1 *)param_3 = local_res8[0];
      return uVar6;
    }
    if (iVar3 == 0) {
      *(undefined2 *)param_3 = 1;
      return 0;
    }
    if (iVar3 == 1) {
      if (*(longlong *)(param_1 + 4) == 0) {
        return 0xc000000d;
      }
      uVar6 = IptGetProcessTrace(*(longlong *)(param_1 + 4),1,&local_58,0,0,(uint *)0x0);
      if ((uVar6 & 0xc0000000) == 0xc0000000) {
        return uVar6;
      }
      *(undefined2 *)param_3 = 1;
      param_3[1] = local_58 + 8;
      return uVar6;
    }
    if (iVar3 == 2) {
      if (*(longlong *)(param_1 + 4) == 0) {
        return 0xc000000d;
      }
      uVar6 = IptGetProcessTrace(*(longlong *)(param_1 + 4),1,&local_58,(longlong)(param_3 + 1),
                                 iVar7 + -8,(uint *)&local_res20);
      if ((uVar6 & 0xc0000000) == 0xc0000000) {
        return uVar6;
      }
      *(int *)((longlong)param_3 + 4) = (int)local_res20;
      *param_4 = (int)local_res20 + 8;
      *(undefined2 *)param_3 = 1;
      *(undefined2 *)((longlong)param_3 + 2) = 1;
      return uVar6;
    }
    if (iVar3 != 3) {
      if (iVar3 == 4) {
        uVar1 = *(ushort *)(param_1 + 6);
        if ((uVar1 & 1) != 0) {
          return 0xc000000d;
        }
        uVar2 = *(ushort *)((longlong)param_1 + 0x1a);
        if ((uVar2 & 1) != 0) {
          return 0xc000000d;
        }
        if ((ulonglong)param_2 < (ulonglong)uVar2 + 0x1c + (ulonglong)uVar1) {
          return 0xc000000d;
        }
        piStack_30 = param_1 + 7;
        puVar10 = (ulonglong *)0x0;
        local_38 = (ulonglong)CONCAT22(uVar1,uVar1);
        if (uVar2 != 0) {
          lStack_40 = (longlong)param_1 + (ulonglong)uVar1 + 0x1c;
          local_48 = (ulonglong)CONCAT22(uVar2,uVar2);
          puVar10 = &local_48;
        }
        uVar8 = *(ulonglong *)(param_1 + 2);
        uVar6 = param_1[5];
        uVar4 = param_1[4];
        local_res20 = 0;
        if (((0x2000000 < ((uint)uVar8 & 0xf000000)) || (uVar1 == 0)) ||
           (iVar7 = OpenImageIFEOKey(&local_res20,(ushort *)&local_38,(longlong)puVar10,'\x01'),
           iVar7 < 0)) {
          return 0xc0000001;
        }
        uVar9 = SetIptOption(local_res20,uVar8,uVar4,uVar6);
        uVar6 = (uint)uVar9;
        ZwClose(local_res20);
        if ((int)uVar6 < 0) {
          return 0xc0000001;
        }
        goto LAB_14001078c;
      }
      if (iVar3 != 5) {
        if (iVar3 != 6) {
          if (iVar3 == 7) {
            uVar6 = IptPauseThreadTrace(*(longlong *)(param_1 + 2),local_res8);
            *(undefined1 *)param_3 = local_res8[0];
            return uVar6;
          }
          return 0xc000000d;
        }
        uVar6 = IptStopProcessTrace(*(longlong *)(param_1 + 2));
        goto LAB_14001078c;
      }
      uVar8 = *(ulonglong *)(param_1 + 4);
      lVar11 = 0;
LAB_140010655:
      uVar8 = IptStartProcessTrace(*(longlong *)(param_1 + 2),lVar11,uVar8);
      uVar6 = (uint)uVar8;
      goto LAB_14001078c;
    }
    uVar8 = SetIptOptionForTracingCores(*(ulonglong *)(param_1 + 2),param_1[4],param_1[5]);
    if (((-1 < (int)uVar8) && (local_res20 = 0, DAT_1400073e4 == 0)) &&
       (uVar8 = GetIptOptionForTracingCores(&local_res20,'\x01'), -1 < (int)uVar8)) {
      uVar6 = IptStartTraceOnEachCoreInternal(local_res20,0,&local_50);
      goto LAB_140010781;
    }
  }
  else {
    if (iVar3 == 9) {
      uVar6 = IptQueryProcessTrace(*(longlong *)(param_1 + 2),&local_50);
      *param_3 = local_50;
      return uVar6;
    }
    if (iVar3 == 10) {
      uVar6 = 0xc0000001;
      cVar5 = EnterCoreTracingControl();
      if (cVar5 != '\0') {
        cVar5 = IptAcquireCoreTracingStopRef();
        if (cVar5 != '\0') {
          uVar6 = 0;
          uVar9 = *IptCoreTracingControlBlock;
          IptReleaseCoreTracingStopRef();
        }
        LeaveCoreTracingControl();
      }
      *param_3 = uVar9;
      return uVar6;
    }
    if (iVar3 != 0xc) {
      if (iVar3 == 0xd) {
        uVar6 = IptConfigureThreadAddressFilterRange
                          (*(longlong *)(param_1 + 2),param_1[4],param_1[5],
                           *(ulonglong *)(param_1 + 6),*(ulonglong *)(param_1 + 8));
        goto LAB_14001078c;
      }
      if (iVar3 == 0xe) {
        uVar6 = IptQueryThreadAddressFilterRange
                          (*(longlong *)(param_1 + 2),param_1[4],(undefined4 *)param_3,param_3 + 1,
                           param_3 + 2);
      }
      else {
        if (iVar3 != 0xf) {
          if (iVar3 != 0x10) {
            return 0xc000000d;
          }
          lVar11 = *(longlong *)(param_1 + 4);
          uVar8 = *(ulonglong *)(param_1 + 6);
          goto LAB_140010655;
        }
        uVar6 = IptQueryThreadTraceStopRangeEntered
                          (*(longlong *)(param_1 + 2),(undefined1 *)param_3);
      }
      if (-1 < (int)uVar6) {
        return uVar6;
      }
      goto LAB_14001078c;
    }
    if (DAT_1400073e0 == '\0') {
      uVar9 = IptStopTraceOnEachCore((longlong)IptCoreTracingControlBlock);
      uVar6 = (uint)uVar9;
LAB_140010781:
      if (-1 < (int)uVar6) goto LAB_14001078c;
    }
  }
  uVar6 = 0xc0000001;
LAB_14001078c:
  *param_4 = 0;
  return uVar6;
}



===== RemoveIptAutoLogger @ 14001099c =====

int RemoveIptAutoLogger(void)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 local_30;
  undefined *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_res8 = 0;
  local_30 = 0;
  local_28 = &DAT_1400070a0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&local_res8,0xf003f,&local_38);
  if (iVar1 < 0) {
    if (iVar1 == -0x3fffffcc) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = ZwDeleteKey(local_res8);
    ZwClose(local_res8);
  }
  return iVar1;
}



===== SetIptServiceMode @ 140010a34 =====

ulonglong SetIptServiceMode(undefined4 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  local_res10 = 0;
  local_res8[0] = param_1;
  uVar2 = OpenIptServiceKey();
  if (-1 < (int)uVar2) {
    uVar1 = ZwSetValueKey(local_res10,&DAT_140007100,0,4,local_res8,4);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_res10);
  }
  return uVar2;
}



===== wil_details_EvaluateFeatureDependencies @ 140010aa4 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_72067384__private_descriptor;
  ppuVar2 = &Feature_72067384__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140010adf;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140010b59:
  while( true ) {
    if (&UNK_140006c47 < ppuVar3) {
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
      if (&UNK_140006c47 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140010adf:
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
      if (&UNK_140006c47 < ppuVar2) goto LAB_140010b59;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140010b59;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140010b94 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140010c2c;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140010c2c;
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
LAB_140010c2c:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140010c80 =====

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
      for (ppuVar2 = &Feature_72067384__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_140006c47 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140010d00 =====

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
  for (ppuVar3 = &Feature_72067384__private_descriptor; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140010dfd;
  }
LAB_140010e06:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140010dfd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140010e06;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140010dce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140010dce;
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
    if (&UNK_140006c47 < ppuVar3) goto LAB_140010e06;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140010dfd;
}



===== WdmlibIoCreateDeviceSecure @ 140010e2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1)

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
            (param_1,0,&DAT_1400070f0,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_RWX_WORLD_R,0,
             in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 140010f10 =====

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
    if ((int)uVar5 < 0) goto LAB_140011070;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140011070;
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
LAB_140011070:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1400110a4 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 140011194 =====

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
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 140011274 =====

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
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 140011374 =====

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



===== SepSddlGetAclForString @ 140011460 =====

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
LAB_1400117fb:
              iVar5 = -0x3ffffff3;
LAB_1400117fd:
              lVar7 = *param_2;
              goto LAB_1400117e3;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1400117fb;
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
                ppuVar17 = &PTR_u_RC_140007110;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_14000711c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_140007118)[uVar11 * 4];
                    goto LAB_1400116ed;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1400117fb;
                uVar15 = (uint)local_res8;
LAB_1400116ed:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1400117fd;
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
            if (iVar5 != 0) goto LAB_1400117fd;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_14001176b:
              iVar5 = -0x3fffff89;
              goto LAB_1400117fd;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_14001176b;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1400117fd;
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
LAB_1400117e3:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140011828 =====

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
  puVar5 = &DAT_1400071e4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1400071dc + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1400071d8 + uVar7 * 0x18);
      uVar6 = (&DAT_1400071e4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1400118bf;
      }
      else {
LAB_1400118bf:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1400071d0 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1400118d4;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1400118d4:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1400118fc =====

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
LAB_14001197f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_14001195d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_14001197f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_14001195d:
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



===== SepSddlSecurityDescriptorFromSDDLString @ 140011a08 =====

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
        goto LAB_140011b4d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_140011b4d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 140011bac =====

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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140005eb0,0x20019,&local_b0);
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



===== PiRegStateReadStackCreationSettingsFromKey @ 140011d48 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x140005e30);
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
      if ((int)uVar3 < 0) goto LAB_140011ec7;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140005e48,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140011ec7;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140005e60,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_140011ec7;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140005e90,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_140011ec7:
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



===== PpRegStateReadCreateClassCreationSettings @ 140011f0c =====

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140005dd0,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x140005de8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x140005df8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x140005e18,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 140012070 =====

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
                      (local_res20,0x140005dd0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
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
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x140005e30);
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



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1400121d8 =====

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



===== CmRegUtilCreateWstrKey @ 1400122d4 =====

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



===== CmRegUtilOpenExistingWstrKey @ 1400123a4 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 140012438 =====

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
    if (iVar1 < 0) goto LAB_140012570;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_140012570:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1400125b4 =====

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
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
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



===== CmRegUtilWstrValueGetDword @ 140012700 =====

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



===== CmRegUtilWstrValueSetWstrString @ 1400127a4 =====

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



===== entry @ 140013010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140013044 =====

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



===== IptInit @ 140013078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong IptInit(undefined8 param_1)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_38;
  undefined4 local_34;
  undefined **local_30;
  undefined8 *local_28;
  undefined8 local_20;
  
  local_res8 = 0;
  _DAT_140007450 = 0;
  _DAT_140007438 = 0;
  _DAT_140007518 = 0;
  ExInitializeRundownProtection(&IptDriverState);
  ExInitializeRundownProtection(&DAT_1400073d8);
  ExWaitForRundownProtectionRelease(&DAT_1400073d8);
  ExRundownCompleted(&DAT_1400073d8);
  KeInitializeQueue(&DAT_140007490,1);
  local_38 = 0x1000b;
  local_30 = &PTR_IptStartTraceOnEachCoreForEtw_140005038;
  local_34 = 0x30000;
  local_28 = &DAT_140007430;
  local_20 = param_1;
  uVar2 = ExRegisterExtension(&DAT_140007508,0x10001,&local_38);
  uVar4 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    local_38 = 0x1000c;
    local_30 = &PTR_IptLockdown_140005008;
    local_34 = 0x60000;
    local_28 = &DAT_140007538;
    local_20 = param_1;
    uVar2 = ExRegisterExtension(&DAT_140007448,0x10001,&local_38);
    uVar4 = (ulonglong)uVar2;
    if (-1 < (int)uVar2) {
      uVar2 = (*(code *)DAT_140007538[2])(&DAT_140007418,&IptStateSize);
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        if (DAT_140007418 == 0) {
          uVar4 = 0xc00000bb;
        }
        else {
          uVar2 = (*(code *)*DAT_140007538)();
          uVar4 = (ulonglong)uVar2;
          if (-1 < (int)uVar2) {
            DAT_1400075e8 = &IptProcessList;
            IptProcessList = &IptProcessList;
            DAT_1400075f8 = &IptSessionList;
            _IptSessionList = &IptSessionList;
            DAT_1400075a8 = &IptThreadList;
            _IptThreadList = &IptThreadList;
            uVar3 = IptInitHashTables();
            uVar4 = uVar3 & 0xffffffff;
            if (-1 < (int)uVar3) {
              local_38 = 0x1000a;
              local_30 = &PTR_IptSetProcessFaultInformation_140005000;
              local_34 = 0x10000;
              local_28 = &DAT_140007510;
              local_20 = param_1;
              uVar2 = ExRegisterExtension(&DAT_140007530,0x10001,&local_38);
              uVar4 = (ulonglong)uVar2;
              if (-1 < (int)uVar2) {
                DAT_14000748c = 0;
                cVar1 = KeRegisterBugCheckReasonCallback
                                  (&DAT_140007460,BugCheckSecondaryDumpDataCallback,2,"IPT");
                if (cVar1 == '\0') {
                  uVar4 = 0xc0000001;
                }
                else {
                  uVar2 = PsSetCreateThreadNotifyRoutineEx(0,OnThreadCreate);
                  if (-1 < (int)uVar2) {
                    uVar2 = PsSetCreateProcessNotifyRoutineEx(OnProcessCreate,0);
                    if (-1 < (int)uVar2) {
                      uVar2 = SetIptInterruptHandler(IptInterruptHandler);
                      if (-1 < (int)uVar2) {
                        uVar2 = PsCreateSystemThread
                                          (&local_res8,0x1fffff,0,0,0,IptTraceLogThreadEntry,0);
                        if (-1 < (int)uVar2) {
                          local_res10 = 0;
                          uVar2 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
                          DAT_140007528 = local_res10;
                          ZwClose();
                          if (-1 < (int)uVar2) {
                            return 0;
                          }
                        }
                        SetIptInterruptHandler(0);
                      }
                      PsSetCreateProcessNotifyRoutineEx(OnProcessCreate,1);
                    }
                    PsRemoveCreateThreadNotifyRoutine(OnThreadCreate);
                  }
                  uVar4 = (ulonglong)uVar2;
                  KeDeregisterBugCheckReasonCallback(&DAT_140007460);
                }
              }
            }
          }
        }
      }
    }
  }
  if (DAT_140007530 != 0) {
    ExUnregisterExtension();
    DAT_140007530 = 0;
  }
  IptFreeHashTables();
  if (DAT_140007448 != 0) {
    ExUnregisterExtension();
    DAT_140007448 = 0;
  }
  if (DAT_140007508 != 0) {
    ExUnregisterExtension();
    DAT_140007508 = 0;
  }
  return uVar4;
}



===== DriverEntry @ 140013478 =====

/* WARNING: Removing unreachable block (ram,0x0001400135b7) */
/* WARNING: Removing unreachable block (ram,0x000140013586) */
/* WARNING: Removing unreachable block (ram,0x000140013569) */
/* WARNING: Removing unreachable block (ram,0x000140013519) */
/* WARNING: Removing unreachable block (ram,0x0001400134d4) */
/* WARNING: Removing unreachable block (ram,0x0001400134c0) */
/* WARNING: Removing unreachable block (ram,0x000140013496) */
/* WARNING: Removing unreachable block (ram,0x000140013665) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar1 = cpuid_basic_info(0);
  if (((*(int *)(lVar1 + 4) == 0x756e6547) && (*(int *)(lVar1 + 0xc) == 0x6c65746e)) &&
     (*(int *)(lVar1 + 8) == 0x49656e69)) {
    piVar2 = (int *)cpuid_basic_info(0);
    iVar4 = *piVar2;
    if (0x13 < iVar4) {
      puVar3 = (uint *)cpuid_Version_info(1);
      uVar6 = *puVar3;
      if (((((byte)(uVar6 >> 8) & 0xf) != 6) ||
          (uVar6 = ((uVar6 >> 8 & 0xf00 | uVar6 & 0xf0) >> 4) - 0x3d, 0x19 < uVar6)) ||
         ((0x2040401U >> (uVar6 & 0x1f) & 1) == 0)) {
        DAT_140007440 = 0xffffffff;
        lVar1 = cpuid_Extended_Feature_Enumeration_info(7);
        if ((*(uint *)(lVar1 + 4) >> 0x19 & 1) == 0) {
          HviGetIptFeatures(&DAT_140007408);
          if ((DAT_140007408 & 0xfffff000) == 0) goto LAB_140013705;
          DAT_140007440 = DAT_140007408 & 0xfffff000;
          if ((DAT_140007408 & 2) != 0) {
            WinHvGetPartitionId(&DAT_140007458);
          }
        }
        piVar2 = (int *)cpuid(0x14);
        IptCapability = piVar2[1];
        DAT_1400075c4 = piVar2[3];
        if (0 < *piVar2) {
          puVar3 = (uint *)cpuid(0x14);
          DAT_1400075c8 = *puVar3;
          _DAT_1400075cc = puVar3[1];
        }
        if (((DAT_1400075c4 & 1) != 0) && ((DAT_1400075c8 & 7) != 0)) {
          if (0x14 < iVar4) {
            piVar2 = (int *)cpuid(0x15);
            if ((*piVar2 != 0) && (piVar2[1] != 0)) {
              PRatio = piVar2[1] / *piVar2;
            }
          }
          wil_InitializeFeatureStaging();
          uVar6 = WdmlibIoCreateDeviceSecure(param_1);
          uVar7 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            uVar6 = IoCreateSymbolicLink(&DAT_1400070e0,&DAT_1400070f0);
            uVar7 = (ulonglong)uVar6;
            if (-1 < (int)uVar6) {
              uVar6 = IoRegisterShutdownNotification(0);
              uVar7 = (ulonglong)uVar6;
              if (-1 < (int)uVar6) {
                uVar5 = IptInit(param_1);
                uVar7 = uVar5 & 0xffffffff;
                if (-1 < (int)uVar5) {
                  *(code **)(param_1 + 0x68) = IptUnload;
                  *(code **)(param_1 + 0x70) = IptCreateClose;
                  *(code **)(param_1 + 0x80) = IptCreateClose;
                  *(code **)(param_1 + 0xe0) = IptControl;
                  *(code **)(param_1 + 0xf0) = IptDispatchShutdown;
                  SetIptServiceMode(0);
                  IptStartTraceOnEachCoreForIoctl();
                  return 0;
                }
                IoUnregisterShutdownNotification(0);
              }
              IoDeleteSymbolicLink(&DAT_1400070e0);
            }
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
          return uVar7;
        }
      }
    }
  }
LAB_140013705:
  SetIptServiceMode(3);
  RemoveIptAutoLogger();
  return 0xc00000bb;
}



===== wil_InitializeFeatureStaging @ 140013738 =====

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
    for (ppuVar3 = &Feature_72067384__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400137bf;
    }
LAB_1400137f9:
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
LAB_1400137bf:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400137f9;
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
    goto LAB_1400137f9;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140006c47 < ppuVar3) goto LAB_1400137f9;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400137bf;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001384c =====

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
  ppuVar4 = &Feature_72067384__private_descriptor;
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
            if (&UNK_140006c47 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140013936;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140013936;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140013936:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140006c47 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


