
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



===== ivIVCNContextApcKernelRoutine @ 1c0001020 =====

void ivIVCNContextApcKernelRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar1 = WPP_GLOBAL_Control;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_(puVar1,5,param_3,0x1b,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_d(puVar1,5,param_3,0x1c,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0);
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1d,
                         &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
      }
    }
  }
  return;
}



===== ivIVCNContextApcRunDownRoutine @ 1c00010e0 =====

void ivIVCNContextApcRunDownRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar1 = WPP_GLOBAL_Control;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_(puVar1,5,param_3,0x1e,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_d(puVar1,5,param_3,0x1f,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0);
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x20,
                         &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
      }
    }
  }
  return;
}



===== IVFreeIVSRContext @ 1c00011a0 =====

void IVFreeIVSRContext(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x11a0  7  IVFreeIVSRContext */
  if (param_1 != 0) {
    ivFreeSRContext(param_1,param_2,param_3);
  }
  return;
}



===== IVInitialize @ 1c00011c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong IVInitialize(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  CContainerIdList *pCVar5;
  ulonglong uVar6;
  CContainerIdList *_Dst;
  undefined8 *puVar7;
  undefined1 auStackY_68 [32];
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
                    /* 0x11c0  8  IVInitialize */
  local_20 = __security_cookie ^ (ulonglong)auStackY_68;
  local_30 = 0;
  uStack_28 = 0;
  RtlInitUnicodeString(&local_30,L"\\Driver\\Win32kns");
  IoCreateDriver(&local_30,Win32kCreateDriverCallback);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  *param_1 = gbRootPartition;
  _gChannelMap = 0x49cceb25a163c0be;
  uRam00000001c00081b8 = 0x585caf8c7bb33f92;
  _DAT_1c00081c0 = 0x43a233b625326197;
  uRam00000001c00081c8 = 0xbdd946ceb69adba0;
  _DAT_1c00081d0 = 0x4018aa5436b83bf1;
  uRam00000001c00081d8 = 0x2e16994d6299538f;
  _DAT_1c00081e0 = 0x45f412ee5a1e4ab0;
  uRam00000001c00081e8 = 0x4c042306a4c9bba4;
  uVar4 = HviIsAnyHypervisorPresent();
  if ((char)uVar4 != '\0') {
    local_30 = 0;
    uStack_28 = 0;
    HviGetHypervisorFeatures(&local_30);
    gbRootPartition = (uint)((ulonglong)local_30 >> 0x2c) & 1;
    *param_1 = gbRootPartition;
  }
  _gWskClientNpi = 0;
  _DAT_1c00080f8 = &DAT_1c00071c0;
  iVar2 = WskRegister(&gWskClientNpi);
  if (iVar2 < 0) {
LAB_1c00013b8:
    pcVar1 = (code *)swi(3);
    uVar6 = (*pcVar1)();
    return uVar6;
  }
  puVar7 = &gWskProviderNpi;
  uVar4 = 0xffffffff;
  _Dst = (CContainerIdList *)&gWskRegistration;
  iVar2 = WskCaptureProviderNPI();
  if (iVar2 < 0) goto LAB_1c00013b8;
  if (gbRootPartition == 0) {
    uVar3 = ivInitializeChild(_Dst,uVar4,puVar7);
    if ((int)uVar3 < 0) goto LAB_1c00013b8;
  }
  else {
    uVar3 = ivInitializeRoot();
    if ((int)uVar3 < 0) goto LAB_1c00013b9;
  }
  if (gbRootPartition != 0) {
    _Dst = (CContainerIdList *)0x40;
    puVar7 = (undefined8 *)0x76637249;
    pCVar5 = (CContainerIdList *)ExAllocatePool2();
    if (pCVar5 == (CContainerIdList *)0x0) {
      gpContainerList = (CContainerIdList *)0x0;
      uVar3 = 0xc0000017;
    }
    else {
      _Dst = pCVar5 + 0x10;
      puVar7 = (undefined8 *)0x380;
      memset(_Dst,0,0x380);
      gpContainerList = pCVar5;
      *(undefined8 *)(pCVar5 + 0x390) = 0;
      *(undefined8 *)(pCVar5 + 0x398) = 0;
      pCVar5[0x3a0] = (CContainerIdList)0x1;
      *(undefined8 *)pCVar5 = 0;
      *(undefined8 *)(pCVar5 + 8) = 0;
    }
  }
LAB_1c00013b9:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(_Dst,5,puVar7,0xb,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,
                        (char)uVar3);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0xc,
                       &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
  }
  return (ulonglong)uVar3;
}



===== IVRegisterChildLifetimeNotifications @ 1c0001440 =====

undefined8
IVRegisterChildLifetimeNotifications
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined8 *param_5
          )

{
  undefined *puVar1;
  code *pcVar2;
  longlong lVar3;
  bool bVar4;
  
                    /* 0x1440  9  IVRegisterChildLifetimeNotifications */
  if (gbRootPartition == 0) {
    lVar3 = (ulonglong)param_4 * 0x98;
    puVar1 = &DAT_1c0008520;
  }
  else {
    lVar3 = (ulonglong)param_4 * 0xc0;
    puVar1 = &DAT_1c0008238;
  }
  puVar1 = puVar1 + lVar3;
  pcVar2 = ivIVCNContextApcNormalRoutineRoot;
  bVar4 = gbRootPartition == 0;
  *(undefined8 *)(puVar1 + 0x68) = param_3;
  *(uint *)(puVar1 + 0x70) = param_4;
  if (bVar4) {
    pcVar2 = ivIVCNContextApcNormalRoutineChild;
  }
  *(undefined8 *)(puVar1 + 0x58) = param_1;
  *(undefined8 *)(puVar1 + 0x60) = param_2;
  KeInitializeApc(puVar1,param_1,0,ivIVCNContextApcKernelRoutine,ivIVCNContextApcRunDownRoutine,
                  pcVar2,0,puVar1 + 0x58);
  *(undefined4 *)(puVar1 + 0x74) = 1;
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = puVar1;
  }
  return 0;
}



===== IVResolveContainerId @ 1c0001510 =====

uint IVResolveContainerId(CContainerIdList *param_1,CONTAINER_ID *param_2)

{
  bool bVar1;
  uint uVar2;
  
                    /* 0x1510  10  IVResolveContainerId */
  if (gpContainerList == (CContainerIdList *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    bVar1 = CContainerIdList::GetIdForVmId(param_1,(_GUID *)param_1,param_2);
    uVar2 = ~-(uint)bVar1 & 0xc000000d;
  }
  return uVar2;
}



===== IVUninitialize @ 1c0001550 =====

undefined8 IVUninitialize(void)

{
  _DRIVER_OBJECT *p_Var1;
  
                    /* 0x1550  12  IVUninitialize */
  WskReleaseProviderNPI(&gWskRegistration);
  WskDeregister(&gWskRegistration);
  if ((gbRootPartition != 0) && (gpContainerList != (CContainerIdList *)0x0)) {
    ExFreePoolWithTag(gpContainerList,0);
  }
  p_Var1 = nsDriverObject;
  if (nsDriverObject != (_DRIVER_OBJECT *)0x0) {
    if (gNSWPPLog != (RECORDER_LOG__ *)0x0) {
      imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
      gNSWPPLog = (RECORDER_LOG__ *)0x0;
    }
    WppCleanupKm(p_Var1);
  }
  return 0;
}



===== IVUnregisterChildLifetimeNotifications @ 1c00015f0 =====

undefined8 IVUnregisterChildLifetimeNotifications(void)

{
                    /* 0x15f0  13  IVUnregisterChildLifetimeNotifications
                       0x15f0  14  LogUnexpectedCodePathAtDispatchLevel */
  return 0;
}



===== WPP_RECORDER_SF_ @ 1c00015fc =====

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



===== WPP_RECORDER_SF_d @ 1c000168c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = gNSWPPLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(pRVar1,param_2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dq @ 1c0001740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(void)

{
  RECORDER_LOG__ *pRVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  pRVar1 = gNSWPPLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0x10,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(pRVar1,5,1,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0x10,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== ivBuildSRContext @ 1c0001818 =====

longlong ivBuildSRContext(void *param_1,uint param_2,longlong param_3,undefined8 param_4,
                         undefined4 *param_5,undefined8 param_6,undefined4 param_7,
                         undefined4 *param_8,undefined8 param_9)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  void *_Dst;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong _Size;
  ulonglong in_stack_ffffffffffffffc8;
  
  _Size = (ulonglong)param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xf,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  uVar8 = 0x63727349;
  lVar5 = ExAllocatePool2(0x40,200);
  if (lVar5 != 0) {
    uVar8 = 0x646e7349;
    uVar7 = _Size;
    _Dst = (void *)ExAllocatePool2(0x40);
    *(void **)(lVar5 + 0x68) = _Dst;
    if (_Dst != (void *)0x0) {
      if (param_1 != (void *)0x0) {
        uVar8 = _Size;
        memcpy(_Dst,param_1,_Size);
      }
      uVar7 = 0;
      lVar6 = IoAllocateIrp(1);
      *(longlong *)(lVar5 + 0x58) = lVar6;
      if (lVar6 != 0) {
        uVar8 = 0;
        uVar7 = _Size;
        lVar6 = IoAllocateMdl(_Dst,_Size,0,0,lVar6);
        *(longlong *)(lVar5 + 0x60) = lVar6;
        if (lVar6 != 0) {
          MmBuildMdlForNonPagedPool(lVar6);
          *(undefined8 *)(lVar5 + 0xb8) = param_9;
          *(undefined8 *)(lVar5 + 0xa8) = param_6;
          *(undefined4 *)(lVar5 + 0xb0) = param_7;
          *(ulonglong *)(lVar5 + 0x70) = _Size;
          *(longlong *)(lVar5 + 0x80) = param_3;
          *(undefined8 *)(lVar5 + 0x88) = param_4;
          *(undefined4 *)(lVar5 + 0xb4) = *param_8;
          if (param_5 != (undefined4 *)0x0) {
            uVar2 = param_5[1];
            uVar3 = param_5[2];
            uVar4 = param_5[3];
            uVar1 = *(undefined8 *)(param_5 + 4);
            *(undefined4 *)(lVar5 + 0x90) = *param_5;
            *(undefined4 *)(lVar5 + 0x94) = uVar2;
            *(undefined4 *)(lVar5 + 0x98) = uVar3;
            *(undefined4 *)(lVar5 + 0x9c) = uVar4;
            *(undefined8 *)(lVar5 + 0xa0) = uVar1;
          }
          if (param_3 != 0) {
            ObfReferenceObject(param_3);
            uVar8 = 0;
            *(undefined4 *)(lVar5 + 0xc0) = 1;
            KeInitializeApc(lVar5,param_3,0,ivSRContextApcKernelRoutine,ivSRContextApcRunDownRoutine
                            ,ivSRContextApcNormalRoutine,
                            in_stack_ffffffffffffffc8 & 0xffffffffffffff00,
                            (longlong *)(lVar5 + 0x58));
          }
          goto LAB_1c0001a22;
        }
      }
    }
    ivFreeSRContext(lVar5,uVar7,uVar8);
    lVar5 = 0;
  }
LAB_1c0001a22:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_dq();
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar8,0x11,
                       &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
  }
  return lVar5;
}



===== ivFreeSRContext @ 1c0001aa4 =====

void ivFreeSRContext(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xd,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x58) != 0) {
      IoFreeIrp();
    }
    if (*(longlong *)(param_1 + 0x60) != 0) {
      IoFreeMdl();
    }
    if (*(longlong *)(param_1 + 0x68) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x68),0);
    }
    if (*(int *)(param_1 + 0xc0) != 0) {
      ObfDereferenceObject(*(undefined8 *)(param_1 + 0x80));
    }
    ExFreePoolWithTag(param_1,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xe,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  return;
}



===== ivSRContextApcKernelRoutine @ 1c0001bb0 =====

void ivSRContextApcKernelRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar1 = WPP_GLOBAL_Control;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_(puVar1,5,param_3,0x12,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_d(puVar1,5,param_3,0x13,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0);
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x14,
                         &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
      }
    }
  }
  return;
}



===== ivSRContextApcNormalRoutine @ 1c0001c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ivSRContextApcNormalRoutine(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  
  uVar2 = (undefined1)param_2;
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x18,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  (**(code **)(param_1 + 0x60))(param_1 + -0x58);
  lVar1 = param_1 + -0x58;
  ivFreeSRContext(lVar1,CONCAT71(uVar3,uVar2),param_3);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(lVar1,5,param_3,0x19,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                       &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
  }
  return;
}



===== ivSRContextApcRunDownRoutine @ 1c0001d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ivSRContextApcRunDownRoutine(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar1 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x15,
                     &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
  }
  (**(code **)(param_1 + 0xb8))(param_1);
  ivFreeSRContext(param_1,CONCAT71(uVar2,uVar1),param_3);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(param_1,5,param_3,0x16,&WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids,0);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x17,
                       &WPP_d6fdcbb3481b31ad1b232b47d50dbcd7_Traceguids);
    }
  }
  return;
}



===== ForEachChannelOfType<<lambda_d51cabe9ff99696d41c762603c098dfd>_> @ 1c0001e2c =====

long CContainerIdList::ForEachChannelOfType<<lambda_d51cabe9ff99696d41c762603c098dfd>_>
               (undefined8 param_1,int param_2,short *param_3,undefined8 *param_4)

{
  CContainerIdList *pCVar1;
  long lVar2;
  ulonglong uVar3;
  CONTAINER_ID *pCVar4;
  
  pCVar1 = gpContainerList;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(pCVar1,0);
  if (pCVar1[0x3a0] == (CContainerIdList)0x0) {
    for (uVar3 = 0; (uint)uVar3 < 0x10; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      if (((pCVar1[uVar3 + 0x390] != (CContainerIdList)0x0) &&
          (*(_WSK_SOCKET **)(pCVar1 + (uVar3 * 7 + (longlong)param_2) * 8 + 0x28) !=
           (_WSK_SOCKET *)0x0)) &&
         ((pCVar4 = (CONTAINER_ID *)(pCVar1 + uVar3 * 0x38 + 0x10), *(short *)pCVar4 != *param_3 ||
          (*(short *)(pCVar4 + 2) != param_3[1])))) {
        lVar2 = IVSendOverSocket(*(void **)*param_4,*(ulong *)param_4[1],*(_ETHREAD **)param_4[2],
                                 *(ulong *)param_4[3],pCVar4,
                                 *(_WSK_SOCKET **)
                                  (pCVar1 + (uVar3 * 7 + (longlong)param_2) * 8 + 0x28));
        if (lVar2 < 0) goto LAB_1c0001ef4;
      }
    }
  }
  lVar2 = 0;
LAB_1c0001ef4:
  ExReleasePushLockSharedEx(pCVar1,0);
  KeLeaveCriticalRegion();
  return lVar2;
}



===== AcceptComplete @ 1c0001f40 =====

/* long __cdecl AcceptComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void * __ptr64)
    */

long __cdecl AcceptComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  _WSK_SOCKET *p_Var1;
  undefined4 uVar2;
  _IVChildNotificationContext *p_Var3;
  undefined4 local_res10 [2];
  _WSK_SOCKET *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(int *)(param_2 + 0x30) == 0) {
    p_Var1 = *(_WSK_SOCKET **)(param_2 + 0x38);
    local_res10[0] = 0;
    CContainerIdList::AddChannel
              ((CContainerIdList *)param_1,(_GUID *)((longlong)param_3 + 0x14),
               *(IV_CHANNEL_TYPE *)param_3,p_Var1,(CONTAINER_ID *)local_res10);
    uVar2 = local_res10[0];
    if (*(int *)((longlong)param_3 + 0xac) == 1) {
      p_Var3 = (_IVChildNotificationContext *)ExAllocatePool2(0x40,0x18,0x6e636349);
      if (p_Var3 != (_IVChildNotificationContext *)0x0) {
        *(undefined4 *)(p_Var3 + 0x10) = *(undefined4 *)param_3;
        *(undefined4 *)(p_Var3 + 0xc) = uVar2;
        *(undefined4 *)(p_Var3 + 8) = 1;
        InsertNotificationContextIntoAcceptList
                  ((_IVCNContextRoot *)((longlong)param_3 + 0x38),p_Var3);
        KeInsertQueueApc((longlong)param_3 + 0x38,0,0,0);
      }
    }
    local_20 = *(undefined4 *)param_3;
    local_1c = uVar2;
    local_28 = p_Var1;
    if (p_Var1 != (_WSK_SOCKET *)0x0) {
      StartReadOperationOnSocket((_IV_ROOT_CONNECTION_SOCKET_CONTEXT *)&local_28);
    }
    SocketStartAcceptSync(param_3);
  }
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== BindComplete @ 1c0002040 =====

/* long __cdecl BindComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void * __ptr64)
    */

long __cdecl BindComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  if (*(int *)(param_2 + 0x30) == 0) {
    SocketStartAcceptSync(param_3);
  }
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== CreateListeningSocketComplete @ 1c0002080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CreateListeningSocketComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl CreateListeningSocketComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStackY_78 [32];
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  if (*(int *)(param_2 + 0x30) == 0) {
    plVar2 = *(longlong **)(param_2 + 0x38);
    *(longlong **)((longlong)param_3 + 8) = plVar2;
    local_44 = 0;
    uStack_3c = 0;
    local_48 = 0x22;
    lVar1 = (longlong)*(int *)param_3 * 0x10;
    local_34 = *(undefined4 *)(&gChannelMap + lVar1);
    uStack_30 = *(undefined4 *)(lVar1 + 0x1c00081b4);
    uStack_2c = *(undefined4 *)(lVar1 + 0x1c00081b8);
    uStack_28 = *(undefined4 *)(lVar1 + 0x1c00081bc);
    lVar1 = *plVar2;
    lVar5 = IoAllocateIrp(&DAT_1c0008101,0);
    if (lVar5 == 0) {
      return -0x3fffff66;
    }
    lVar3 = *(longlong *)(lVar5 + 0xb8);
    uVar6 = 0;
    *(code **)(lVar3 + -0x10) = BindComplete;
    *(void **)(lVar3 + -8) = param_3;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    iVar4 = (**(code **)(lVar1 + 0x10))(plVar2,&local_48,0,lVar5);
    if ((iVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(&WPP_RECORDER_INITIALIZED,2,uVar6,0xe,
                        &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)iVar4);
    }
  }
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== IVCloseSocket @ 1c00021a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl IVCloseSocket(struct _WSK_SOCKET * __ptr64) */

void __cdecl IVCloseSocket(_WSK_SOCKET *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)param_1;
  lVar3 = IoAllocateIrp(1,0);
  if (lVar3 != 0) {
    lVar2 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar2 + -8) = 0;
    *(code **)(lVar2 + -0x10) = ivCloseIrpCompletionRoutine;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    (**(code **)(lVar1 + 8))(param_1,lVar3);
  }
  return;
}



===== IVDisconnectSocket @ 1c000220c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl IVDisconnectSocket(struct _IV_ROOT_CONNECTION_SOCKET_CONTEXT * __ptr64) */

void __cdecl IVDisconnectSocket(_IV_ROOT_CONNECTION_SOCKET_CONTEXT *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  
  lVar1 = **(longlong **)param_1;
  lVar4 = IoAllocateIrp(1,0);
  if (lVar4 != 0) {
    puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x6c637649);
    if (puVar5 != (undefined8 *)0x0) {
      uVar2 = *(undefined8 *)param_1;
      *(undefined4 *)((longlong)puVar5 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar5 + 1) = *(undefined4 *)(param_1 + 8);
      lVar3 = *(longlong *)(lVar4 + 0xb8);
      *puVar5 = uVar2;
      *(code **)(lVar3 + -0x10) = ivDisconnectIrpCompletionRoutine;
      *(undefined8 **)(lVar3 + -8) = puVar5;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      (**(code **)(lVar1 + 0x40))(uVar2,0,0,lVar4);
    }
  }
  return;
}



===== IVSendOverSocket @ 1c00022b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl IVSendOverSocket(void const * __ptr64,unsigned long,struct _ETHREAD *
   __ptr64,unsigned long,struct CONTAINER_ID const & __ptr64,struct _WSK_SOCKET * __ptr64) */

long __cdecl
IVSendOverSocket(void *param_1,ulong param_2,_ETHREAD *param_3,ulong param_4,CONTAINER_ID *param_5,
                _WSK_SOCKET *param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x15,
                     &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
  }
  uVar6 = 0;
  lVar4 = ivBuildSRContext(param_1,param_2,0,param_3,(undefined4 *)0x0,param_6,param_4,
                           (undefined4 *)param_5,0);
  if (lVar4 == 0) {
    iVar3 = -0x3fffffe9;
  }
  else {
    lVar1 = *(longlong *)param_6;
    local_30 = 0;
    local_28 = *(undefined8 *)(lVar4 + 0x70);
    local_38 = *(undefined8 *)(lVar4 + 0x60);
    lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x58) + 0xb8);
    *(code **)(lVar2 + -0x10) = ivSendIrpCompletionRoutine;
    *(longlong *)(lVar2 + -8) = lVar4;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    puVar5 = &local_38;
    uVar6 = 0;
    iVar3 = (**(code **)(lVar1 + 0x30))(param_6,puVar5,0,*(undefined8 *)(lVar4 + 0x58));
    if (iVar3 < 0) {
      ivFreeSRContext(lVar4,puVar5,uVar6);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(WPP_GLOBAL_Control,5,uVar6,0x16,
                        &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)iVar3);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x17,
                       &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
  }
  return iVar3;
}



===== InsertNotificationContextIntoAcceptList @ 1c000243c =====

/* void __cdecl InsertNotificationContextIntoAcceptList(struct _IVCNContextRoot * __ptr64,struct
   _IVChildNotificationContext * __ptr64) */

void __cdecl
InsertNotificationContextIntoAcceptList
          (_IVCNContextRoot *param_1,_IVChildNotificationContext *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x78);
  *(undefined8 *)param_2 = *(undefined8 *)(param_1 + 0x80);
  *(_IVChildNotificationContext **)(param_1 + 0x80) = param_2;
  KeReleaseSpinLock(param_1 + 0x78,uVar1);
  return;
}



===== SocketStartAcceptSync @ 1c000249c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl SocketStartAcceptSync(struct _WSK_ROOT_LISTENING_SOCKET_CONTEXT * __ptr64) */

void __cdecl SocketStartAcceptSync(_WSK_ROOT_LISTENING_SOCKET_CONTEXT *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 in_R8;
  
  plVar1 = *(longlong **)(param_1 + 8);
  lVar2 = *plVar1;
  lVar5 = IoAllocateIrp(1,0);
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(gNSWPPLog,2,in_R8,0xc,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
  }
  else {
    lVar3 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar3 + -0x10) = AcceptComplete;
    *(_WSK_ROOT_LISTENING_SOCKET_CONTEXT **)(lVar3 + -8) = param_1;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    uVar4 = (**(code **)(lVar2 + 0x18))(plVar1,0,param_1,0,0,param_1 + 0x10,lVar5);
    if (((int)uVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d((ulonglong)uVar4,2,param_1,0xd,
                        &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)uVar4);
    }
  }
  return;
}



===== StartReadOperationOnSocket @ 1c0002590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl StartReadOperationOnSocket(struct _IV_ROOT_CONNECTION_SOCKET_CONTEXT * __ptr64) */

void __cdecl StartReadOperationOnSocket(_IV_ROOT_CONNECTION_SOCKET_CONTEXT *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 in_R8;
  
  lVar2 = **(longlong **)param_1;
  lVar5 = IoAllocateIrp(1,0);
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(gNSWPPLog,2,in_R8,10,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
  }
  else {
    puVar6 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar6 != (undefined8 *)0x0) {
      lVar3 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar3 + -0x10) = ivRootReceiveIrpCompletionRoutine;
      uVar1 = *(undefined4 *)(param_1 + 8);
      *(undefined8 **)(lVar3 + -8) = puVar6;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      uVar7 = *(undefined8 *)param_1;
      *(undefined4 *)(puVar6 + 3) = 0;
      *puVar6 = uVar7;
      *(undefined4 *)(puVar6 + 1) = uVar1;
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      puVar6[4] = 4;
      *(undefined4 *)((longlong)puVar6 + 0xc) = uVar1;
      uVar7 = IoAllocateMdl(puVar6 + 5,4,0,0,lVar5);
      puVar6[2] = uVar7;
      MmBuildMdlForNonPagedPool(uVar7);
      uVar7 = 0;
      uVar4 = (**(code **)(lVar2 + 0x38))(*(undefined8 *)param_1,puVar6 + 2,0,lVar5);
      if (((int)uVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_d((ulonglong)uVar4,2,uVar7,0xb,
                          &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)uVar4);
      }
    }
  }
  return;
}



===== ivCloseIrpCompletionRoutine @ 1c00026f0 =====

/* long __cdecl ivCloseIrpCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl ivCloseIrpCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== ivDisconnectIrpCompletionRoutine @ 1c0002720 =====

/* long __cdecl ivDisconnectIrpCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl ivDisconnectIrpCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  IVCloseSocket(*(_WSK_SOCKET **)param_3);
  ExFreePoolWithTag(param_3,0);
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== ivRootReceiveIrpCompletionRoutine @ 1c0002770 =====

/* long __cdecl ivRootReceiveIrpCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl ivRootReceiveIrpCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  CONTAINER_ID *pCVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  _IVChildNotificationContext *p_Var4;
  longlong lVar5;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    pCVar1 = (CONTAINER_ID *)((longlong)param_3 + 0xc);
    CContainerIdList::RemoveChannel
              ((CContainerIdList *)param_1,pCVar1,*(IV_CHANNEL_TYPE *)((longlong)param_3 + 8));
    lVar5 = (longlong)*(int *)((longlong)param_3 + 8) * 0xc0;
    if ((*(int *)(&DAT_1c00082ac + lVar5) == 1) &&
       (p_Var4 = (_IVChildNotificationContext *)ExAllocatePool2(0x40,0x18,0x6e636349),
       p_Var4 != (_IVChildNotificationContext *)0x0)) {
      *(undefined4 *)(p_Var4 + 0xc) = *(undefined4 *)pCVar1;
      *(undefined4 *)(p_Var4 + 0x10) = *(undefined4 *)((longlong)param_3 + 8);
      *(undefined4 *)(p_Var4 + 8) = 3;
      InsertNotificationContextIntoAcceptList((_IVCNContextRoot *)(&DAT_1c0008238 + lVar5),p_Var4);
      KeInsertQueueApc((_IVCNContextRoot *)(&DAT_1c0008238 + lVar5),0,0,0);
    }
    local_10 = *(undefined4 *)((longlong)param_3 + 8);
    local_c = *(undefined4 *)pCVar1;
    local_18 = *(undefined8 *)param_3;
    IVDisconnectSocket((_IV_ROOT_CONNECTION_SOCKET_CONTEXT *)&local_18);
  }
  else if (*(int *)(param_2 + 0x30) < 0) {
    CContainerIdList::RemoveChannel
              ((CContainerIdList *)param_1,(CONTAINER_ID *)((longlong)param_3 + 0xc),
               *(IV_CHANNEL_TYPE *)((longlong)param_3 + 8));
    IVCloseSocket(*(_WSK_SOCKET **)param_3);
  }
  puVar3 = *(undefined8 **)((longlong)param_3 + 0x10);
  while (puVar3 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar3;
    if ((*(byte *)((longlong)puVar3 + 10) & 2) != 0) {
      MmUnlockPages(puVar3);
    }
    IoFreeMdl(puVar3);
    puVar3 = puVar2;
  }
  *(undefined8 *)((longlong)param_3 + 0x10) = 0;
  ExFreePoolWithTag(param_3,0);
  IoFreeIrp(param_2);
  return -0x3fffffea;
}



===== ivSendIrpCompletionRoutine @ 1c00028e0 =====

undefined8 ivSendIrpCompletionRoutine(undefined8 param_1,longlong param_2,ulonglong param_3)

{
  uint uVar1;
  CContainerIdList *this;
  CONTAINER_ID *pCVar2;
  ulonglong uVar3;
  
  uVar1 = *(uint *)(param_2 + 0x30);
  this = (CContainerIdList *)(ulonglong)uVar1;
  pCVar2 = (CONTAINER_ID *)0x0;
  uVar3 = param_3;
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_d(this,5,param_3,0x14,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,
                        (char)uVar1);
    }
    uVar3 = (ulonglong)*(IV_CHANNEL_TYPE *)(param_3 + 0xb0);
    pCVar2 = (CONTAINER_ID *)(param_3 + 0xb4);
    CContainerIdList::RemoveChannel(this,pCVar2,*(IV_CHANNEL_TYPE *)(param_3 + 0xb0));
    IVCloseSocket(*(_WSK_SOCKET **)(param_3 + 0xa8));
  }
  ivFreeSRContext(param_3,pCVar2,uVar3);
  return 0xc0000016;
}



===== IVBroadcast @ 1c0002970 =====

long IVBroadcast(undefined8 param_1,undefined4 param_2,undefined8 param_3,int param_4,short *param_5
                )

{
  long lVar1;
  undefined8 local_res8;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  int local_res20 [2];
  undefined8 *local_48;
  undefined4 *local_40;
  undefined8 *local_38;
  int *local_30;
  
                    /* 0x2970  4  IVBroadcast */
  local_res8 = param_1;
  local_res10[0] = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1c,
                     &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
  }
  local_48 = &local_res8;
  local_40 = local_res10;
  local_38 = &local_res18;
  local_30 = local_res20;
  lVar1 = CContainerIdList::ForEachChannelOfType<<lambda_d51cabe9ff99696d41c762603c098dfd>_>
                    (local_30,local_res20[0],param_5,&local_48);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(WPP_GLOBAL_Control,5,param_5,0x1d,
                        &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)lVar1);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_5,0x1e,
                       &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
  }
  return lVar1;
}



===== IVSend @ 1c0002a70 =====

long IVSend(CContainerIdList *param_1,ulong param_2,_ETHREAD *param_3,IV_CHANNEL_TYPE param_4,
           CONTAINER_ID *param_5)

{
  bool bVar1;
  long lVar2;
  CContainerIdList *this;
  ulonglong uVar3;
  _WSK_SOCKET *local_38 [2];
  
                    /* 0x2a70  11  IVSend */
  uVar3 = (ulonglong)param_4;
  this = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (this = (CContainerIdList *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    this = *(CContainerIdList **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(this,5,param_3,0x18,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
  }
  local_38[0] = (_WSK_SOCKET *)0x0;
  bVar1 = CContainerIdList::GetSocketForChannel(this,param_5,param_4,local_38);
  if (bVar1) {
    lVar2 = IVSendOverSocket(param_1,param_2,param_3,param_4,param_5,local_38[0]);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_d(WPP_GLOBAL_Control,5,param_3,0x1a,
                          &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,(char)lVar2);
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1b,
                         &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(gNSWPPLog,2,uVar3,0x19,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
    lVar2 = -0x3fffffff;
  }
  return lVar2;
}



===== ivIVCNContextApcNormalRoutineRoot @ 1c0002bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ivIVCNContextApcNormalRoutineRoot(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x11,
                     &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
  }
  while( true ) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
    puVar1 = *(undefined8 **)(param_1 + 0x28);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 *)(param_1 + 0x28) = *puVar1;
    }
    lVar3 = param_1 + 0x20;
    KeReleaseSpinLock(lVar3,uVar2);
    if (puVar1 == (undefined8 *)0x0) break;
    (**(code **)(param_1 + 0x10))(puVar1);
    ExFreePoolWithTag(puVar1,0);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(lVar3,5,param_3,0x12,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,0);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13,
                       &WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
    }
  }
  return;
}



===== ivInitializeRoot @ 1c0002ce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ivInitializeRoot(void)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  _WSK_ROOT_LISTENING_SOCKET_CONTEXT **_Dst;
  undefined8 uVar5;
  undefined8 uVar6;
  
  iVar1 = 0;
  uVar4 = 0;
  while( true ) {
    uVar3 = (uint)uVar4;
    if (3 < uVar3) {
      return iVar1;
    }
    uVar5 = 0xc0;
    _Dst = &gWskRootListeningSocketContext + uVar4 * 0x18;
    memset(_Dst,0,0xc0);
    lVar2 = IoAllocateIrp(1,0);
    if (lVar2 == 0) break;
    *(uint *)_Dst = uVar3;
    lVar2 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar2 + -0x10) = CreateListeningSocketComplete;
    *(_WSK_ROOT_LISTENING_SOCKET_CONTEXT ***)(lVar2 + -8) = _Dst;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar6 = 1;
    uVar5 = gWskProviderNpi;
    iVar1 = (**(code **)(DAT_1c0008138 + 8))();
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(uVar5,2,uVar6,0xf,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids,
                        (char)iVar1);
    }
    uVar4 = (ulonglong)(uVar3 + 1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return -0x3fffff66;
  }
  WPP_RECORDER_SF_(gNSWPPLog,2,uVar5,0x10,&WPP_11a03c5defe032de8c719db7dbc083d1_Traceguids);
  return -0x3fffff66;
}



===== IVRecv @ 1c0002e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl IVRecv(unsigned long,struct _ETHREAD * __ptr64,struct _ETHREAD * __ptr64,struct
   _IVPacketContext,unsigned long,long (__cdecl*)(struct _IVSRContext * __ptr64)) */

long __cdecl
IVRecv(uint param_1,longlong param_2,undefined8 param_3,undefined4 *param_4,uint param_5,
      undefined8 param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  
                    /* 0x2e40  1  IVRecv */
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  lVar6 = (ulonglong)param_5 * 0x98;
  local_48[0] = 0;
  lVar4 = ivBuildSRContext((void *)0x0,param_1,param_2,param_3,param_4,
                           *(undefined8 *)(&DAT_1c0008518 + lVar6),param_5,local_48,param_6);
  if (lVar4 == 0) {
    iVar3 = -0x3fffffe9;
  }
  else {
    local_34 = 0;
    param_2 = 2;
    lVar1 = **(longlong **)(&DAT_1c0008518 + lVar6);
    local_38 = 0;
    local_30 = *(undefined8 *)(lVar4 + 0x70);
    local_40 = *(undefined8 *)(lVar4 + 0x60);
    lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x58) + 0xb8);
    *(code **)(lVar2 + -0x10) = ivChildRecvIrpCompletionRoutine;
    *(longlong *)(lVar2 + -8) = lVar4;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    puVar5 = &local_40;
    iVar3 = (**(code **)(lVar1 + 0x38))
                      (*(undefined8 *)(&DAT_1c0008518 + lVar6),puVar5,2,
                       *(undefined8 *)(lVar4 + 0x58));
    if (iVar3 < 0) {
      ivFreeSRContext(lVar4,puVar5,param_2);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(WPP_GLOBAL_Control,5,param_2,0x14,
                        &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,(char)iVar3);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_2,0x15,
                       &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
    }
  }
  return iVar3;
}



===== ivChildRecvIrpCompletionRoutine @ 1c0003000 =====

undefined8 ivChildRecvIrpCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  _WSK_SOCKET *p_Var1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xe,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  uVar2 = *(ulonglong *)(param_2 + 0x38);
  if (uVar2 == 0) {
    uVar2 = (ulonglong)*(uint *)(param_3 + 0xb0);
    uVar4 = 1;
    p_Var1 = *(_WSK_SOCKET **)(param_3 + 0xa8);
    ivCloseChildSocket(p_Var1,*(uint *)(param_3 + 0xb0),1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = CONCAT71((int7)(uVar2 >> 8),4);
      WPP_RECORDER_SF_d(p_Var1,4,uVar4,0xf,&WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,
                        (char)*(undefined4 *)(param_3 + 0xb0));
    }
    ivFreeSRContext(param_3,uVar2,uVar4);
    return 0xc0000016;
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(uVar2,4,lVar3,0x11,&WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,
                        (char)*(int *)(param_2 + 0x30));
    }
  }
  else if (3 < uVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(uVar2,4,lVar3,0x10,&WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,
                        (char)*(undefined4 *)(param_2 + 0x38));
    }
    IoFreeIrp(*(undefined8 *)(param_3 + 0x58));
    *(undefined8 *)(param_3 + 0x58) = 0;
    uVar4 = 0;
    KeInsertQueueApc(param_3,param_3,0,0);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000016;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
      return 0xc0000016;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x12,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
    return 0xc0000016;
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheck(0x164);
}



===== ivChildSocketInitializeForChannel @ 1c0003198 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ivChildSocketInitializeForChannel(unsigned long) */

long __cdecl ivChildSocketInitializeForChannel(ulong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  longlong lVar6;
  undefined4 in_register_0000000c;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  _WSK_CHILD_LISTENING_SOCKET_CONTEXT **local_b0;
  undefined *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  longlong local_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar7 = (ulonglong)param_1;
  local_68 = 0;
  lVar8 = 0;
  local_78 = 0;
  uStack_70 = 0;
  lVar6 = IoAllocateIrp(CONCAT71((int7)(CONCAT44(in_register_0000000c,param_1) >> 8),1),0);
  if (lVar6 == 0) {
    iVar4 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(&local_78,0,0);
    lVar1 = *(longlong *)(lVar6 + 0xb8);
    local_90 = 0;
    local_98 = 0;
    *(code **)(lVar1 + -0x10) = ivWskSynchronousIrpCompletion;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    *(undefined8 **)(lVar1 + -8) = &local_78;
    lVar1 = DAT_1c0008138;
    local_a0 = 0;
    local_a8 = &gWskClientConnectionDispatch;
    lVar9 = uVar7 * 0x98;
    *(ulong *)(&DAT_1c0008510 + lVar9) = param_1;
    local_b0 = &gWskChildListeningSocketContext + uVar7 * 0x13;
    local_b8 = CONCAT44(local_b8._4_4_,2);
    local_88 = lVar6;
    iVar4 = (**(code **)(lVar1 + 8))(gWskProviderNpi,0x22,1,1);
    if (iVar4 == 0x103) {
      local_b8 = 0;
      KeWaitForSingleObject(&local_78,0,0,0);
      iVar4 = *(int *)(lVar6 + 0x30);
    }
    if (-1 < iVar4) {
      plVar2 = *(longlong **)(lVar6 + 0x38);
      *(longlong **)(&DAT_1c0008518 + lVar9) = plVar2;
      lVar8 = *plVar2;
    }
    IoReuseIrp(lVar6,0x103);
    if (iVar4 < 0) {
      pcVar3 = (code *)swi(3);
      lVar5 = (*pcVar3)();
      return lVar5;
    }
    KeClearEvent(&local_78);
    lVar1 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar1 + -0x10) = ivWskSynchronousIrpCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_78;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    local_5c = 0x4a10dd56e0e16197;
    uStack_54 = 0x38a855a1e75e9591;
    local_60 = 0x22;
    lVar1 = (ulonglong)param_1 * 0x10;
    local_4c = *(undefined4 *)(&gChannelMap + lVar1);
    uStack_48 = *(undefined4 *)(lVar1 + 0x1c00081b4);
    uStack_44 = *(undefined4 *)(lVar1 + 0x1c00081b8);
    uStack_40 = *(undefined4 *)(lVar1 + 0x1c00081bc);
    iVar4 = (**(code **)(lVar8 + 0x10))(*(undefined8 *)(&DAT_1c0008518 + lVar9),&local_60,0,lVar6);
    if (iVar4 == 0x103) {
      local_b8 = 0;
      KeWaitForSingleObject(&local_78,0,0,0);
      iVar4 = *(int *)(lVar6 + 0x30);
    }
    IoReuseIrp(lVar6,0x103);
    if (iVar4 < 0) {
      pcVar3 = (code *)swi(3);
      lVar5 = (*pcVar3)();
      return lVar5;
    }
    KeClearEvent(&local_78);
    lVar1 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar1 + -0x10) = ivWskSynchronousIrpCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_78;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    local_60 = 0x22;
    local_5c = 0x480cd03fa42e7cda;
    uStack_54 = 0x78b8ab20dea4c29c;
    lVar1 = uVar7 * 0x10;
    local_4c = *(undefined4 *)(&gChannelMap + lVar1);
    uStack_48 = *(undefined4 *)(lVar1 + 0x1c00081b4);
    uStack_44 = *(undefined4 *)(lVar1 + 0x1c00081b8);
    uStack_40 = *(undefined4 *)(lVar1 + 0x1c00081bc);
    iVar4 = (**(code **)(lVar8 + 0x18))
                      (*(undefined8 *)(&DAT_1c0008518 + uVar7 * 0x98),&local_60,0,lVar6);
    if (iVar4 == 0x103) {
      local_b8 = 0;
      KeWaitForSingleObject(&local_78,0,0,0);
      iVar4 = *(int *)(lVar6 + 0x30);
    }
    IoReuseIrp(lVar6,0x103);
    IoFreeIrp(lVar6);
  }
  return iVar4;
}



===== ivCloseChildIrpCompletionRoutine @ 1c00034e0 =====

/* long __cdecl ivCloseChildIrpCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl ivCloseChildIrpCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  IoFreeIrp(param_2);
  if (*(int *)((longlong)param_3 + 4) == 1) {
    uVar1 = *(uint *)param_3;
    lVar3 = (ulonglong)uVar1 * 0x98;
    if (*(int *)(&DAT_1c0008594 + lVar3) == 1) {
      lVar2 = ExAllocatePool2(0x40,0x18,0x6e636349);
      if (lVar2 != 0) {
        *(undefined4 *)(lVar2 + 0xc) = 0;
        *(undefined4 *)(lVar2 + 8) = 2;
        *(uint *)(lVar2 + 0x10) = uVar1;
        KeInsertQueueApc(&DAT_1c0008520 + lVar3,lVar2,0,0);
      }
    }
  }
  ExFreePoolWithTag(param_3,0);
  return -0x3fffffea;
}



===== ivCloseChildSocket @ 1c0003594 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ivCloseChildSocket(struct _WSK_SOCKET * __ptr64,unsigned long,enum
   IV_CLOSE_CONTEXT_RECONNECT_STATE) */

void __cdecl
ivCloseChildSocket(_WSK_SOCKET *param_1,ulong param_2,IV_CLOSE_CONTEXT_RECONNECT_STATE param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulong *puVar4;
  
  lVar1 = *(longlong *)param_1;
  lVar3 = IoAllocateIrp(1,0);
  if (lVar3 != 0) {
    puVar4 = (ulong *)ExAllocatePool2(0x40,8,0x6c637649);
    if (puVar4 != (ulong *)0x0) {
      lVar2 = *(longlong *)(lVar3 + 0xb8);
      *puVar4 = param_2;
      puVar4[1] = param_3;
      *(code **)(lVar2 + -0x10) = ivCloseChildIrpCompletionRoutine;
      *(ulong **)(lVar2 + -8) = puVar4;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      (**(code **)(lVar1 + 8))(param_1,lVar3);
    }
  }
  return;
}



===== ivWskSynchronousIrpCompletion @ 1c0003640 =====

undefined8 ivWskSynchronousIrpCompletion(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if (*(char *)(param_2 + 0x41) != '\0') {
    KeSetEvent(param_3,2);
  }
  return 0xc0000016;
}



===== IVChildReInitialize @ 1c0003680 =====

void IVChildReInitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x3680  5  IVChildReInitialize */
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(param_1,4,param_3,0x16,&WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,
                      (char)param_1);
  }
  ivChildSocketInitializeForChannel((ulong)param_1);
  return;
}



===== IVCloseChildChannel @ 1c00036d0 =====

undefined8 IVCloseChildChannel(ulonglong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
                    /* 0x36d0  6  IVCloseChildChannel */
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(param_1,4,param_3,0x17,&WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids,
                      (char)param_1);
  }
  lVar1 = (param_1 & 0xffffffff) * 0x98;
  *(undefined4 *)(&DAT_1c0008594 + lVar1) = 0;
  ivCloseChildSocket(*(_WSK_SOCKET **)(&DAT_1c0008518 + lVar1),(ulong)param_1,0);
  return 0;
}



===== ivIVCNContextApcNormalRoutineChild @ 1c0003740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ivIVCNContextApcNormalRoutineChild(longlong param_1,longlong param_2,undefined8 param_3)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xc,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  (**(code **)(param_1 + 0x10))(param_2);
  if (param_2 != 0) {
    ExFreePoolWithTag(param_2,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xd,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  return;
}



===== ivInitializeChild @ 1c0003808 =====

long ivInitializeChild(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  uint uVar2;
  _WSK_CHILD_LISTENING_SOCKET_CONTEXT **pp_Var3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  uVar2 = 0;
  pp_Var3 = &gWskChildListeningSocketContext;
  do {
    uVar4 = 0x98;
    memset(&gWskChildListeningSocketContext + (ulonglong)uVar2 * 0x13,0,0x98);
    *pp_Var3 = (_WSK_CHILD_LISTENING_SOCKET_CONTEXT *)0x0;
    pp_Var3[1] = (_WSK_CHILD_LISTENING_SOCKET_CONTEXT *)0x0;
    lVar1 = ivChildSocketInitializeForChannel(uVar2);
    if (lVar1 < 0) break;
    uVar2 = uVar2 + 1;
    pp_Var3 = pp_Var3 + 0x13;
  } while (uVar2 < 4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0xb,
                     &WPP_ffcdaa49c7c4385a895d090d3d71229a_Traceguids);
  }
  return lVar1;
}



===== InitializeWppLogging @ 1c00038fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl InitializeWppLogging(struct _DRIVER_OBJECT * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

long __cdecl InitializeWppLogging(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  char local_38 [24];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  _DAT_1c0008188 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0008168 = &WPP_ThisDir_CTLGUID_Win32kNSTraceGuid;
  DAT_1c0008170 = 0;
  _DAT_1c0008180 = 0;
  _DAT_1c00081a0 = 0;
  _DAT_1c00081a8 = 0;
  WppLoadTracingSupport();
  _DAT_1c0008180 = 0;
  WppInitKm(param_1,param_2);
  lVar4 = 0x10;
  uStack_60 = 0x200000002;
  local_68 = 0x10;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_68);
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\0';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  local_58 = 0x38;
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  pcVar3 = local_38;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_48 = 0;
  uStack_40 = 0x1000000000;
  do {
    if ((lVar4 == -0x7fffffee) || (pcVar3[(longlong)"win32kns" - (longlong)local_38] == '\0'))
    break;
    *pcVar3 = pcVar3[(longlong)"win32kns" - (longlong)local_38];
    pcVar3 = pcVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  pcVar2 = pcVar3 + -1;
  if (lVar4 != 0) {
    pcVar2 = pcVar3;
  }
  *pcVar2 = '\0';
  local_38[0x10] = '\x02';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\x02';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  uStack_50 = 0xc800001000;
  iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_58,&gNSWPPLog);
  if (iVar1 < 0) {
    gNSWPPLog = (RECORDER_LOG__ *)0x0;
  }
  return iVar1;
}



===== Win32kCreateDriverCallback @ 1c0003a70 =====

/* long __cdecl Win32kCreateDriverCallback(struct _DRIVER_OBJECT * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

long __cdecl Win32kCreateDriverCallback(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  nsDriverObject = param_1;
  RtlInitUnicodeString
            (&local_18,
             L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Win32knsWPP"
            );
  InitializeWppLogging(param_1,(_UNICODE_STRING *)&local_18);
  return 0;
}



===== WppClassicProviderCallback @ 1c0003ac0 =====

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



===== AddChannel @ 1c0003b1c =====

/* public: bool __cdecl CContainerIdList::AddChannel(struct _GUID const & __ptr64,enum
   IV_CHANNEL_TYPE,struct _WSK_SOCKET const * __ptr64 const,struct CONTAINER_ID * __ptr64) __ptr64
    */

bool __thiscall
CContainerIdList::AddChannel
          (CContainerIdList *this,_GUID *param_1,IV_CHANNEL_TYPE param_2,_WSK_SOCKET *param_3,
          CONTAINER_ID *param_4)

{
  undefined8 uVar1;
  CContainerIdList *this_00;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  ulonglong uVar5;
  CContainerIdList **ppCVar6;
  CContainerIdList *local_res8;
  IV_CHANNEL_TYPE local_res18 [4];
  
  this_00 = gpContainerList;
  local_res8 = this;
  local_res18[0] = param_2;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this_00,0);
  ppCVar6 = &local_res8;
  local_res8 = (CContainerIdList *)((ulonglong)local_res8 & 0xffffffff00000000);
  *(void **)(this_00 + 8) = SystemReserved1[0xf];
  bVar2 = GetIndexForVmId(this_00,param_1,(uint *)ppCVar6);
  bVar3 = true;
  if (bVar2) {
    uVar5 = (ulonglong)local_res8 & 0xffffffff;
  }
  else {
    uVar5 = 0;
    do {
      if (this_00[uVar5 + 0x390] == (CContainerIdList)0x0) break;
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < 0x10);
    if ((int)uVar5 == 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(gNSWPPLog,2,ppCVar6,(short)uVar5 + -5,
                         &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids);
      }
      bVar3 = false;
      goto LAB_1c0003cd5;
    }
    DAT_1c0008778 = DAT_1c0008778 + '\x01';
    local_res8._0_4_ = (uint)CONCAT12(DAT_1c0008778,(short)uVar5);
    *(uint *)(this_00 + uVar5 * 0x38 + 0x10) = (uint)local_res8;
    uVar1 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(this_00 + uVar5 * 0x38 + 0x14) = *(undefined8 *)param_1;
    *(undefined8 *)(this_00 + uVar5 * 0x38 + 0x14 + 8) = uVar1;
    this_00[uVar5 + 0x390] = (CContainerIdList)0x1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd_guid_();
    }
    this_00[0x3a0] = (CContainerIdList)0x0;
  }
  this_00[uVar5 * 0x38 + 0x24] = (CContainerIdList)0x1;
  *(_WSK_SOCKET **)(this_00 + (uVar5 * 7 + (longlong)(int)local_res18[0]) * 8 + 0x28) = param_3;
  *(undefined4 *)param_4 = *(undefined4 *)(this_00 + uVar5 * 0x38 + 0x10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    ChannelTypeToStr((int *)local_res18);
    WPP_RECORDER_SF_sqdd_guid_(gNSWPPLog);
  }
LAB_1c0003cd5:
  *(undefined8 *)(this_00 + 8) = 0;
  ExReleasePushLockExclusiveEx(this_00,0);
  KeLeaveCriticalRegion();
  return bVar3;
}



===== ChannelTypeToStr @ 1c0003d18 =====

char * ChannelTypeToStr(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return "mouse";
  }
  if (iVar1 == 1) {
    return "keyboard";
  }
  if (iVar1 == 2) {
    return "hid";
  }
  if (iVar1 == 3) {
    return "non-input";
  }
  return "";
}



===== GetIdForVmId @ 1c0003d60 =====

/* public: bool __cdecl CContainerIdList::GetIdForVmId(struct _GUID const & __ptr64,struct
   CONTAINER_ID * __ptr64)const __ptr64 */

bool __thiscall
CContainerIdList::GetIdForVmId(CContainerIdList *this,_GUID *param_1,CONTAINER_ID *param_2)

{
  CContainerIdList *this_00;
  bool bVar1;
  CContainerIdList *local_res8;
  
  this_00 = gpContainerList;
  local_res8 = this;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(this_00,0);
  local_res8 = (CContainerIdList *)((ulonglong)local_res8 & 0xffffffff00000000);
  bVar1 = GetIndexForVmId(this_00,param_1,(uint *)&local_res8);
  if (bVar1) {
    *(undefined4 *)param_2 =
         *(undefined4 *)(this_00 + ((ulonglong)local_res8 & 0xffffffff) * 0x38 + 0x10);
  }
  ExReleasePushLockSharedEx(this_00,0);
  KeLeaveCriticalRegion();
  return bVar1;
}



===== GetIndexForId @ 1c0003e0c =====

/* private: bool __cdecl CContainerIdList::GetIndexForId(struct CONTAINER_ID const &
   __ptr64,unsigned int * __ptr64)const __ptr64 */

bool __thiscall
CContainerIdList::GetIndexForId(CContainerIdList *this,CONTAINER_ID *param_1,uint *param_2)

{
  short sVar1;
  bool bVar2;
  longlong lVar3;
  
  sVar1 = *(short *)param_1;
  if ((((sVar1 < 0x10) && (this[(longlong)sVar1 + 0x390] != (CContainerIdList)0x0)) &&
      (lVar3 = (longlong)sVar1 * 0x38, this[lVar3 + 0x24] != (CContainerIdList)0x0)) &&
     (*(short *)(this + lVar3 + 0x12) == *(short *)(param_1 + 2))) {
    *param_2 = (int)sVar1;
    bVar2 = true;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dds();
    }
    bVar2 = false;
  }
  return bVar2;
}



===== GetIndexForVmId @ 1c0003ea4 =====

/* private: bool __cdecl CContainerIdList::GetIndexForVmId(struct _GUID const & __ptr64,unsigned int
   * __ptr64)const __ptr64 */

bool __thiscall
CContainerIdList::GetIndexForVmId(CContainerIdList *this,_GUID *param_1,uint *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (this[0x3a0] == (CContainerIdList)0x0) {
    uVar3 = 0;
    while (uVar2 = (uint)uVar3, uVar2 < 0x10) {
      if ((this[uVar3 + 0x390] != (CContainerIdList)0x0) &&
         (lVar1 = RtlCompareMemory(this + uVar3 * 0x38 + 0x14,param_1,0x10), lVar1 == 0x10)) {
        *param_2 = uVar2;
        return true;
      }
      uVar3 = (ulonglong)(uVar2 + 1);
    }
  }
  return false;
}



===== GetSocketForChannel @ 1c0003f2c =====

/* public: bool __cdecl CContainerIdList::GetSocketForChannel(struct CONTAINER_ID const &
   __ptr64,enum IV_CHANNEL_TYPE,struct _WSK_SOCKET * __ptr64 * __ptr64)const __ptr64 */

bool __thiscall
CContainerIdList::GetSocketForChannel
          (CContainerIdList *this,CONTAINER_ID *param_1,IV_CHANNEL_TYPE param_2,
          _WSK_SOCKET **param_3)

{
  CContainerIdList *this_00;
  bool bVar1;
  char *pcVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  CContainerIdList *local_res8;
  IV_CHANNEL_TYPE local_res18 [2];
  undefined8 in_stack_ffffffffffffffc8;
  
  this_00 = gpContainerList;
  local_res8 = this;
  local_res18[0] = param_2;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(this_00,0);
  bVar3 = false;
  local_res8 = (CContainerIdList *)((ulonglong)local_res8 & 0xffffffff00000000);
  bVar1 = GetIndexForId(this_00,param_1,(uint *)&local_res8);
  if (bVar1) {
    if (*(longlong *)
         (this_00 + (((ulonglong)local_res8 & 0xffffffff) * 7 + (longlong)(int)param_2) * 8 + 0x28)
        != 0) {
      bVar3 = true;
      *param_3 = *(_WSK_SOCKET **)
                  (this_00 + ((longlong)*(short *)param_1 * 7 + (longlong)(int)param_2) * 8 + 0x28);
      goto LAB_1c000402b;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000402b;
    uVar4 = (ulonglong)(uint)(int)*(short *)(param_1 + 2);
    uVar6 = (undefined1)*(undefined2 *)param_1;
    pcVar2 = ChannelTypeToStr((int *)local_res18);
    uVar5 = 0x12;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000402b;
    uVar4 = (ulonglong)(uint)(int)*(short *)(param_1 + 2);
    uVar6 = (undefined1)*(undefined2 *)param_1;
    pcVar2 = ChannelTypeToStr((int *)local_res18);
    uVar5 = 0x11;
  }
  WPP_RECORDER_SF_sdd(gNSWPPLog,2,uVar4,uVar5,in_stack_ffffffffffffffc8,pcVar2,uVar6,(char)uVar4);
LAB_1c000402b:
  ExReleasePushLockSharedEx(this_00,0);
  KeLeaveCriticalRegion();
  return bVar3;
}



===== RemoveChannel @ 1c0004068 =====

/* public: bool __cdecl CContainerIdList::RemoveChannel(struct CONTAINER_ID const & __ptr64,enum
   IV_CHANNEL_TYPE) __ptr64 */

bool __thiscall
CContainerIdList::RemoveChannel
          (CContainerIdList *this,CONTAINER_ID *param_1,IV_CHANNEL_TYPE param_2)

{
  CContainerIdList *this_00;
  bool bVar1;
  longlong lVar2;
  char *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  CContainerIdList *local_res8;
  IV_CHANNEL_TYPE local_res18 [2];
  undefined8 in_stack_ffffffffffffffc8;
  
  this_00 = gpContainerList;
  local_res8 = this;
  local_res18[0] = param_2;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this_00,0);
  local_res8 = (CContainerIdList *)((ulonglong)local_res8 & 0xffffffff00000000);
  *(void **)(this_00 + 8) = SystemReserved1[0xf];
  bVar1 = GetIndexForId(this_00,param_1,(uint *)&local_res8);
  if (bVar1) {
    uVar5 = (ulonglong)local_res8 & 0xffffffff;
    lVar2 = (longlong)(int)local_res18[0] + uVar5 * 7;
    if (*(longlong *)(this_00 + lVar2 * 8 + 0x28) != 0) {
      *(undefined8 *)(this_00 + lVar2 * 8 + 0x28) = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = (ulonglong)(uint)(int)*(short *)(this_00 + uVar5 * 0x38 + 0x12);
        uVar7 = (undefined1)*(undefined2 *)(this_00 + uVar5 * 0x38 + 0x10);
        pcVar3 = ChannelTypeToStr((int *)local_res18);
        WPP_RECORDER_SF_sdd(gNSWPPLog,4,uVar6,0xf,in_stack_ffffffffffffffc8,pcVar3,uVar7,(char)uVar6
                           );
      }
      for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
        if (*(longlong *)(this_00 + ((ulonglong)uVar4 + uVar5 * 7) * 8 + 0x28) != 0)
        goto LAB_1c00041ff;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd();
      }
      this_00[uVar5 * 0x38 + 0x24] = (CContainerIdList)0x0;
LAB_1c00041ff:
      *(undefined8 *)(this_00 + 8) = 0;
      ExReleasePushLockExclusiveEx(this_00,0);
      KeLeaveCriticalRegion();
      return true;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = (ulonglong)(uint)(int)*(short *)(param_1 + 2);
      uVar7 = (undefined1)*(undefined2 *)param_1;
      pcVar3 = ChannelTypeToStr((int *)local_res18);
      WPP_RECORDER_SF_sdd(gNSWPPLog,2,uVar5,0xe,in_stack_ffffffffffffffc8,pcVar3,uVar7,(char)uVar5);
    }
  }
  *(undefined8 *)(this_00 + 8) = 0;
  ExReleasePushLockExclusiveEx(this_00,0);
  KeLeaveCriticalRegion();
  return false;
}



===== WPP_RECORDER_SF_dd @ 1c0004230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(void)

{
  RECORDER_LOG__ *pRVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  pRVar1 = gNSWPPLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0x10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(pRVar1,4,1,&WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0x10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_dd_guid_ @ 1c0004304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd_guid_(void)

{
  RECORDER_LOG__ *pRVar1;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  pRVar1 = gNSWPPLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0xc,&uStack0000000000000030,4,
               &uStack0000000000000038,4);
  }
  WppAutoLogTrace(pRVar1,4,1,&WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0xc,
                  &uStack0000000000000030,4,&uStack0000000000000038,4);
  return;
}



===== WPP_RECORDER_SF_dds @ 1c0004408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dds(void)

{
  RECORDER_LOG__ *pRVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  
  pRVar1 = gNSWPPLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000040[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar4 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar4 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,pcVar4,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(pRVar1,2,1,&WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,in_stack_00000040,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sdd @ 1c000457c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,param_4,pcVar3,lVar2,&param_7,4,
               &param_8,4,0);
  }
  lVar2 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_6[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,param_4,param_6
                  ,lVar1,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sqdd_guid_ @ 1c00046ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqdd_guid_(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0xd,pcVar3,lVar2,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4);
  }
  lVar2 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_4a205b54e8523035b74f602bd8517f64_Traceguids,0xd,in_stack_00000030
                  ,lVar1,&uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048
                  ,4);
  return;
}



===== HviGetHypervisorFeatures @ 1c00048c0 =====

/* WARNING: Removing unreachable block (ram,0x0001c00048d9) */

void HviGetHypervisorFeatures(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar4 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar1 = (undefined4 *)cpuid(0x40000003);
    uVar4 = puVar1[1];
    uVar2 = puVar1[2];
    uVar3 = puVar1[3];
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)((longlong)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar3;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  }
  return;
}



===== HviIsAnyHypervisorPresent @ 1c0004900 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004934) */
/* WARNING: Removing unreachable block (ram,0x0001c0004923) */

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



===== HviIsHypervisorMicrosoftCompatible @ 1c000495c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0004989) */

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



===== _guard_check_icall @ 1c00049c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00049d8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00049fc =====

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



===== __cpu_features_init @ 1c0004a70 =====

/* WARNING: Removing unreachable block (ram,0x0001c0004ada) */
/* WARNING: Removing unreachable block (ram,0x0001c0004a89) */
/* WARNING: Removing unreachable block (ram,0x0001c0004a7a) */

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



===== __security_check_cookie @ 1c0004b40 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004b80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004bb0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004bb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004be0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004c40 =====

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



===== memset @ 1c0004f40 =====

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



===== __memset_repmovs @ 1c0005080 =====

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



===== __memset_query @ 1c0005100 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005180 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00052c0 =====

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



===== __memset_spec_plain @ 1c0005340 =====

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



===== DllUnload @ 1c000b010 =====

undefined8 DllUnload(void)

{
                    /* 0xb010  3  DllUnload */
  return 0;
}



===== WppCleanupKm @ 1c000b01c =====

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



===== WppInitKm @ 1c000b0cc =====

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



===== WppLoadTracingSupport @ 1c000b1a8 =====

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



===== WppTraceCallback @ 1c000b2f0 =====

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



===== entry @ 1c000d010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c000d044 =====

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



===== DllInitialize @ 1c000d080 =====

undefined8 DllInitialize(void)

{
                    /* 0xd080  2  DllInitialize */
  return 0;
}



===== DriverEntry @ 1c000d0a4 =====

undefined8 DriverEntry(void)

{
  return 0;
}


