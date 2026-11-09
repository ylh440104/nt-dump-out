
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001010 =====

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
  *param_6 = PTR_DAT_14002a4d0;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14002a4d0;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14002a4e8,&local_18,0,0,param_5,param_6);
  return;
}



===== _tlgKeywordOn @ 1400010c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_14002a4d8 & 0x400000000000) == 0) ||
     (in_RAX = DAT_14002a4e0 & 0x400000000000, in_RAX != DAT_14002a4e0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== __report_gsfailure @ 140001100 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== memcpy_s @ 140001110 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_14000112d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_14000116f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_14000112d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_14000116f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== __cpu_features_init @ 1400011b0 =====

/* WARNING: Removing unreachable block (ram,0x00014000121a) */
/* WARNING: Removing unreachable block (ram,0x0001400011c9) */
/* WARNING: Removing unreachable block (ram,0x0001400011ba) */

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



===== DriverEntry @ 140001278 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,uint *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  undefined4 local_res10 [2];
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  uVar4 = 0;
  PoSetHiberRange(0,0x10000,lVar1,0x4970,0x74644453);
  if (*(longlong *)(lVar1 + 0x388) != 0) {
    PoSetHiberRange(0,0x10000,*(longlong *)(lVar1 + 0x388),*(undefined4 *)(lVar1 + 0x380),0x74644453
                   );
  }
  *(code **)(param_2 + 0xe) = SdDumpOpen;
  *(code **)(param_2 + 0x10) = SdDumpWrite;
  *(code **)(param_2 + 0x20) = SdDumpWritePending;
  *(code **)(param_2 + 0x28) = SdDumpRead;
  *(code **)(param_2 + 0x12) = SdDumpFinish;
  if (0xff < *param_2) {
    *(code **)(param_2 + 0x3e) = SdDumpGetTransferSizes;
  }
  if (0x107 < *param_2) {
    *(code **)(param_2 + 0x40) = SdDumpNotify;
  }
  param_2[0x1b] = *(uint *)(lVar1 + 0x16f8);
  memset(&DAT_14002a5d8,0,0xf0);
  _DAT_14002a5d8 = *(undefined8 *)(param_2 + 0xc);
  _DAT_14002a5e0 = *(undefined8 *)(param_2 + 4);
  _DAT_14002a5e8 = *(undefined8 *)(param_2 + 6);
  _DAT_14002a5f0 = *(undefined8 *)(param_2 + 8);
  _DAT_14002a5f8 = *(undefined8 *)(param_2 + 10);
  _DAT_14002a620 = param_2[0x1c];
  DAT_14002a6c0 = (undefined1)param_2[0x1a];
  DAT_14002a6c1 = *(undefined1 *)((longlong)param_2 + 0x69);
  _PollTimerInterval = *(undefined4 *)(lVar1 + 0x4920);
  SdMemCardInitTimeout = *(undefined4 *)(lVar1 + 0x4924);
  SdIoCardInitTimeout = *(undefined4 *)(lVar1 + 0x4928);
  SdCommandTimeout = *(undefined4 *)(lVar1 + 0x492c);
  SdTransferTimeout = *(undefined4 *)(lVar1 + 0x4930);
  g_DumpExtension = lVar1;
  KeInitializeSpinLock(lVar1 + 0x20);
  KeInitializeSpinLock(lVar1 + 0x2b58);
  KeInitializeSpinLock(lVar1 + 0x2cd0);
  KeInitializeSpinLock(lVar1 + 0x3b0);
  *(undefined1 *)(lVar1 + 0x173c) = 0;
  *(undefined1 *)(lVar1 + 0xdc) = 0;
  if (*(int *)(lVar1 + 0x2d8) - 3U < 2) {
    local_res10[0] = 0;
    if (DAT_14002a6c2 == '\0') {
      lVar3 = *(longlong *)(lVar1 + 0x2e0);
      *(undefined8 *)(lVar1 + 0x308) = 0;
      iVar5 = (uint)((*(uint *)(lVar1 + 0x16f8) & 0xfff) != 0) + (*(uint *)(lVar1 + 0x16f8) >> 0xc);
      if (lVar3 == 0) {
        lVar3 = *(longlong *)(lVar1 + 0x2f0);
      }
      iVar2 = HalDmaAllocateCrashDumpRegistersEx
                        (lVar3,iVar5,0,(undefined8 *)(lVar1 + 0x308),local_res10);
      uVar4 = (ulonglong)iVar2;
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0x80000002,uVar4,iVar5,local_res10[0]);
      }
      if (*(longlong *)(lVar1 + 0x2e0) == 0) {
        *(undefined4 *)(lVar1 + 0x2fc) = local_res10[0];
        *(undefined4 *)(lVar1 + 0x300) = local_res10[0];
      }
      else {
        *(undefined4 *)(lVar1 + 0x364) = local_res10[0];
      }
      DAT_14002a6c2 = '\x01';
    }
  }
  else {
    DAT_14002a6c2 = '\0';
  }
  return uVar4 & 0xffffffff;
}



===== DumpPreInitialize @ 140001540 =====

void DumpPreInitialize(void)

{
                    /* 0x1540  1  DumpPreInitialize */
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 140001560 =====

void DumpUninitialize(void)

{
                    /* 0x1560  2  DumpUninitialize */
  wil_UninitializeFeatureStaging();
  return;
}



===== SdDumpFinish @ 140001580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdDumpFinish(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  
  lVar3 = g_DumpExtension;
  lVar5 = g_DumpExtension + 0x3b0;
  puVar1 = (undefined4 *)(g_DumpExtension + 0x1754);
  puVar2 = (undefined4 *)(g_DumpExtension + 0x558);
  lVar7 = g_DumpExtension + 0x40c0;
  if (DAT_14002a6c3 != '\0') {
    SdbusInitializeWorkPacket
              ((undefined8 *)(g_DumpExtension + 0x4888),0x38,g_DumpExtension + 8,lVar7,0,0);
    SdbusWorkerPrepareForNewPacket(lVar5,(undefined8 *)(lVar3 + 0x4888));
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(lVar3 + 0x4888) + 8) + 0x28);
    (**(code **)(lVar4 + 0x68))
              (*(longlong *)(lVar3 + 0x4888),CONCAT71((int7)((ulonglong)lVar4 >> 8),1));
    *puVar1 = 0;
    plVar6 = (longlong *)(lVar3 + 0x4888);
    *(undefined4 *)(lVar3 + 0x3fc) = 0;
    *(undefined4 *)(lVar3 + 0x3f8) = 0;
    *puVar2 = 1;
    *(undefined4 *)(lVar3 + 0x3c8) = 1;
    *(longlong *)(lVar3 + 0x3c0) = lVar3 + 8;
    lVar4 = lVar5;
    _SdDumpProcessBusRequest('\0',lVar5,plVar6,lVar7);
    _SdDumpDebugPrint("Write cache flushed.\r\n",lVar4,plVar6,lVar7);
  }
  SdbusInitializeWorkPacket((undefined8 *)(lVar3 + 0x4888),0x11,lVar3 + 8,lVar3 + 0x40c0,0,0);
  SdbusWorkerPrepareForNewPacket(lVar5,(undefined8 *)(lVar3 + 0x4888));
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(lVar3 + 0x4888) + 8) + 0x28);
  (**(code **)(lVar7 + 0x68))(*(longlong *)(lVar3 + 0x4888),1);
  *puVar1 = 0;
  plVar6 = (longlong *)(lVar3 + 0x4888);
  *puVar2 = 1;
  *(undefined4 *)(lVar3 + 0x3c8) = 1;
  *(undefined8 *)(lVar3 + 0x3f8) = 0;
  *(longlong *)(lVar3 + 0x3c0) = lVar3 + 8;
  _SdDumpProcessBusRequest('\0',lVar5,plVar6,lVar7);
  _SdDumpDebugPrint("Powering down dump device.\r\n",lVar5,plVar6,lVar7);
  if ((((DAT_14002a6c0 != '\0') && (DAT_14002a6c2 != '\0')) && (lVar3 != 0)) &&
     (*(int *)(lVar3 + 0x2d8) - 3U < 2)) {
    lVar4 = *(longlong *)(lVar3 + 0x2e0);
    if (lVar4 == 0) {
      lVar4 = *(longlong *)(lVar3 + 0x2f0);
    }
    lVar5 = 0;
    HalDmaFreeCrashDumpRegistersEx(lVar4);
    DAT_14002a6c2 = '\0';
  }
  _SdDumpDebugPrint("DUMP finish.\r\n",lVar5,plVar6,lVar7);
  return;
}



===== SdDumpGetTransferSizes @ 140001770 =====

void SdDumpGetTransferSizes(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0x200;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(g_DumpExtension + 0x16f8);
  }
  return;
}



===== SdDumpNotify @ 1400017a0 =====

void SdDumpNotify(int param_1)

{
  longlong lVar1;
  
  if (((param_1 == 2) &&
      (((DAT_14002a6c0 == '\0' || (DAT_14002a6c1 != '\0')) && (DAT_14002a6c2 != '\0')))) &&
     ((g_DumpExtension != 0 && (*(int *)(g_DumpExtension + 0x2d8) - 3U < 2)))) {
    lVar1 = *(longlong *)(g_DumpExtension + 0x2e0);
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(g_DumpExtension + 0x2f0);
    }
    HalDmaFreeCrashDumpRegistersEx(lVar1,0);
    DAT_14002a6c2 = '\0';
  }
  return;
}



===== SdDumpOpen @ 140001820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte SdDumpOpen(undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = g_DumpExtension;
  _SdDumpDebugPrint("DUMP open.\r\n",param_2,param_3,param_4);
  uVar4 = 0x1000;
  memset((void *)(lVar3 + 0x1980),0,0x1000);
  *(undefined4 *)(lVar3 + 0x2b8) = 0;
  *(undefined8 *)(lVar3 + 0x2c8) = 0;
  *(longlong *)(lVar3 + 0x2d0) = lVar3 + 0x2960;
  *(undefined4 *)(lVar3 + 700) = 0x7f;
  *(void **)(lVar3 + 0x2c0) = (void *)(lVar3 + 0x1980);
  DAT_14002a600 = param_1;
  *(undefined **)(*(longlong *)(lVar3 + 0x10) + 0x28) =
       (&SocFunctionBlocks)[*(uint *)(*(longlong *)(lVar3 + 0x10) + 0x20)];
  if (*(char *)(*(longlong *)(lVar3 + 0x10) + 0x45) == '\n') {
    *(code **)(*(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x28) + 0x90) = SdhcQcExecuteRetuning;
  }
  lVar2 = *(longlong *)(lVar3 + 0x10);
  if ((*(char *)(lVar2 + 0x45) == '\x06') && (*(char *)(lVar2 + 0x46) == '\x01')) {
    *(code **)(*(longlong *)(lVar2 + 0x28) + 0x90) = SdhcNvT40ExecuteRetuning;
  }
  lVar2 = lVar3 + 8;
  lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x28);
  (**(code **)(lVar3 + 0x28))();
  uVar1 = _SdDumpResetHostAndCard(lVar2,lVar3,uVar4,param_4);
  return (byte)((uint)uVar1 >> 0x1f) ^ 1;
}



===== SdDumpRead @ 140001920 =====

uint SdDumpRead(int param_1,longlong *param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong local_res10 [3];
  
  uVar2 = DAT_14002a600 + *param_2;
  local_res10[0] = uVar2;
  if (param_1 == 0) {
    SdbusDebugPrint(0x100000,"Dump READ action=%d, offset=0x%I64x, mdl=%p, length=0x%x",0,uVar2);
    uVar1 = _SdDumpReadWriteRequestSync(local_res10,param_3,'\0',uVar2);
  }
  else {
    if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 3)) {
      return 0;
    }
    uVar1 = _SdDumpReadWriteRequestAsync(param_1,local_res10,param_3,0);
  }
  return uVar1;
}



===== SdDumpWrite @ 1400019b0 =====

void SdDumpWrite(longlong *param_1,longlong param_2)

{
  SdDumpWritePending(0,param_1,param_2);
  return;
}



===== SdDumpWritePending @ 1400019d0 =====

uint SdDumpWritePending(int param_1,longlong *param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong local_res10 [3];
  
  uVar2 = DAT_14002a600 + *param_2;
  local_res10[0] = uVar2;
  if (param_1 == 0) {
    SdbusDebugPrint(0x100000,"Dump WRITE action=%d, offset=0x%I64x, mdl=%p, length=0x%x",0,uVar2);
    uVar1 = _SdDumpReadWriteRequestSync(local_res10,param_3,'\x01',uVar2);
  }
  else {
    if (((param_1 != 1) && (param_1 != 2)) && (param_1 != 3)) {
      return 0;
    }
    uVar1 = _SdDumpReadWriteRequestAsync(param_1,local_res10,param_3,CONCAT71((int7)(uVar2 >> 8),1))
    ;
  }
  return uVar1;
}



===== _SdDumpBusWorker @ 140001a54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _SdDumpBusWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  code *pcVar8;
  char *pcVar9;
  longlong *plVar10;
  ulonglong uVar11;
  
  SdbusDebugPrint(0x100000,"wp  %p _SdDumpBusWorker enter",param_2,param_4);
  piVar1 = (int *)(param_1 + 0x18);
  puVar2 = (uint *)(param_1 + 0x1d0);
  do {
    uVar6 = 0;
    SdbusDebugPrint(0x100000,"wp  %p cur evts=0x%08x; req evts=0x%08x; delay=%d; retries=%d",param_2
                    ,(ulonglong)*(uint *)(param_1 + 0x48));
    if ((*(uint *)(param_1 + 0x48) >> 0xc & 1) == 0) {
      uVar5 = uVar6;
      if (*puVar2 == 0) {
        if (*(uint *)(param_1 + 0x1d4) != 0) {
          SdbusDebugPrint(0x400,"wp  %p Go delay: delay=%d",param_2,
                          (ulonglong)*(uint *)(param_1 + 0x1d4));
          (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x120))();
LAB_140001c45:
          _SdDumpBusWorkerSetTimer(param_1);
          *piVar1 = 3;
        }
      }
      else {
        (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x120))();
        uVar4 = *puVar2;
        uVar11 = (ulonglong)uVar4;
        if ((*(uint *)(param_1 + 0x48) & uVar4) == uVar4) {
          SdbusDebugPrint(0x400,"wp  %p Events have fired: cur evts=0x%08x, req evts=0x%08x",param_2
                          ,(ulonglong)*(uint *)(param_1 + 0x48));
          uVar4 = *puVar2;
          *puVar2 = 0;
          *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & ~uVar4;
          *(undefined8 *)(param_1 + 0x1d4) = 0;
        }
        else if (*(int *)(param_1 + 0x1d4) == 0) {
          SdbusDebugPrint(0x400,"wp  %p Go waiting infinitely for events: req evts=0x%08x",param_2,
                          uVar11);
          *piVar1 = 4;
        }
        else {
          if (*(int *)(param_1 + 0x1d8) != 0) {
            SdbusDebugPrint(0x400,"wp  %p Go waiting for events: req evts=0x%08x, retries=%d",
                            param_2,uVar11);
            *(int *)(param_1 + 0x1d8) = *(int *)(param_1 + 0x1d8) + -1;
            goto LAB_140001c45;
          }
          SdbusDebugPrint(2,"wp  %p Missing: req evts=0x%x, cur evts=0x%08x",param_2,uVar11);
          SdbusAddDbgLog(*param_2,0x4572546f,(ulonglong)*puVar2,*param_2,0);
          uVar5 = 0x11;
        }
      }
    }
    else {
      SdbusDebugPrint(2,"wp  %p err evts: 0x%x, cur evts=0x%08x",param_2,
                      (ulonglong)*(uint *)(param_1 + 0x4c));
      SdbusAddDbgLog(*param_2,0x45724877,*param_2,(ulonglong)*(uint *)(param_1 + 0x48),
                     (ulonglong)*(uint *)(param_1 + 0x4c));
      *(undefined8 *)(param_1 + 0x48) = 0;
      uVar5 = *(uint *)(param_1 + 0x4c);
    }
    if (*piVar1 != 2) {
      return;
    }
    if (uVar5 != 0) {
      *(uint *)(param_2 + 7) = uVar5;
      SdbusControllerErrorToNtStatus(uVar5,(int *)((longlong)param_2 + 0x3c));
      *(undefined8 *)(param_1 + 0x1d4) = 0;
      *puVar2 = 0;
      if (*(int *)(param_1 + 0x1a8) == 2) {
        if (1 < *(int *)(param_1 + 0x200) - 6U) goto LAB_140001ca1;
      }
      else {
        if (*(int *)(param_1 + 0x1a8) != 3) {
LAB_140001ca1:
          if (*(int *)(param_1 + 0x1ac) != 3) {
            if (*(int *)(param_1 + 0x1b8) == 0) {
              pcVar7 = (char *)0xc0000185;
            }
            else {
              *(int *)(param_1 + 0x1b4) = *(int *)(param_1 + 0x1b8);
              *(undefined4 *)(param_1 + 0x1b8) = 0;
              uVar5 = (*(code *)param_2[6])(param_1,param_2);
              pcVar7 = (char *)(ulonglong)uVar5;
              if (uVar5 == 0xc0000016) goto LAB_140001cee;
            }
            uVar6 = (uint)pcVar7;
            SdbusDebugPrint(1,"wp  %p Unhandled error: error status: %08x",param_2,pcVar7);
            break;
          }
        }
        *(undefined8 *)(param_1 + 0x1a8) = 3;
      }
    }
LAB_140001cee:
    pcVar7 = SdbusDbgLookupString((int *)&SdbusDbgWPFunctionStringMap,(int)param_2[5]);
    pcVar9 = "wp  %p start - func %s phase %d";
    plVar10 = param_2;
    SdbusDebugPrint(0x100000,"wp  %p start - func %s phase %d",param_2,pcVar7);
    puVar3 = (uint *)(param_1 + 0x1a8);
    uVar5 = *puVar3;
    if (uVar5 == 1) {
      pcVar8 = (code *)param_2[6];
      if (pcVar8 != (code *)0x0) {
LAB_140001e53:
        uVar6 = (*pcVar8)(param_1,param_2);
      }
    }
    else if (uVar5 == 2) {
      uVar6 = SdbusCommandEngineWorker(puVar2,(uint *)(param_1 + 0x200));
      if (uVar6 != 0xc0000016) {
        if (((-1 < (int)uVar6) && ((*(uint *)(*param_2 + 0x48) & 0x10) != 0)) &&
           (*(uint *)(param_1 + 0x48) != 0)) {
          SdbusDebugPrint(2,"wp  %p Events cleared: evts=0x%x",param_2,
                          (ulonglong)*(uint *)(param_1 + 0x48));
          *(undefined4 *)(param_1 + 0x48) = 0;
        }
        uVar5 = *puVar3;
        if (uVar5 == *(uint *)(param_1 + 0x1ac)) {
          SdbusDebugPrint(1,"wp  %p invalid state switch(%d)!",param_2,(ulonglong)uVar5);
          uVar6 = 0xc0000001;
        }
        else {
          SdbusDebugPrint(0x100000,"wp  %p STATE SWITCH %d => %d",param_2,(ulonglong)uVar5);
          *(undefined4 *)(param_1 + 0x1a8) = *(undefined4 *)(param_1 + 0x1ac);
          *(undefined4 *)(param_1 + 0x1ac) = 0;
          if ((int)uVar6 < 0) {
            if ((*(int *)(param_1 + 0x1b8) != 0) && (param_2[6] != 0)) {
              *(uint *)((longlong)param_2 + 0x3c) = uVar6;
              *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0x1b8);
              *(undefined4 *)(param_1 + 0x1b8) = 0;
              pcVar8 = (code *)param_2[6];
              goto LAB_140001e53;
            }
          }
          else {
            uVar6 = 0xc0000016;
          }
        }
      }
    }
    else if (uVar5 == 3) {
      uVar6 = SdbusErrorRecoveryWorker(param_2,pcVar9,plVar10,pcVar7);
      if (-1 < (int)uVar6) {
        *puVar3 = 1;
        uVar6 = 0xc0000016;
        SdbusDebugPrint(0x100000,"wp  %p STATE SWITCH error=>normal",param_2,pcVar7);
      }
    }
    else {
      uVar6 = 0xc0000001;
    }
    pcVar7 = SdbusDbgLookupString((int *)&SdbusDbgWPFunctionStringMap,(int)param_2[5]);
    SdbusDebugPrint(0x100000,"wp  %p end - func %s; phase %d; status=0x%x",param_2,pcVar7);
  } while (uVar6 == 0xc0000016);
  *(uint *)(param_2 + 10) = uVar6;
  SdbusDebugPrint(0x100000,"wp  %p _SdDumpBusWorker exit processing",param_2,pcVar7);
  pcVar7 = SdbusDbgLookupString((int *)&SdbusDbgWPFunctionStringMap,(int)param_2[5]);
  SdbusDebugPrint(4,"wp  %p Worker %s - COMPLETE 0x%08x",param_2,pcVar7);
  (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x68))(*param_2,0);
  (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x120))();
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



===== _SdDumpBusWorkerSetTimer @ 140001f88 =====

void _SdDumpBusWorkerSetTimer(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  lVar1 = KeQueryPerformanceCounter(local_res8);
  lVar2 = (longlong)((ulonglong)*(uint *)(param_1 + 0x1d4) * local_res8[0]) / 1000000;
  if (lVar2 == 0) {
    lVar2 = 1;
  }
  DAT_14002a6b8 = lVar2 + lVar1;
  return;
}



===== _SdDumpCheckEventsAndTimeout @ 140001ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 _SdDumpCheckEventsAndTimeout(longlong param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  
  iVar1 = 0;
  if ((param_2 != '\0') && (lVar4 = KeQueryPerformanceCounter(0), DAT_14002a6b8 <= lVar4)) {
    return 2;
  }
  uVar6 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
  uVar6 = uVar6 & *(uint *)(param_1 + 0x3a0);
  if ((uVar6 >> 0xc & 1) != 0) {
    iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
  }
  if ((uVar6 == *(uint *)(param_1 + 0x3f0)) && (iVar1 == *(int *)(param_1 + 0x3f4))) {
    uVar5 = 0;
  }
  else {
    KeStallExecutionProcessor(1);
    uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
    uVar6 = (uVar6 | uVar2) & *(uint *)(param_1 + 0x3a0);
    *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | uVar6;
    if ((uVar6 >> 0xc & 1) != 0) {
      uVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
      *(undefined4 *)(param_1 + 0x3f4) = uVar3;
    }
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf8))
              (param_1,uVar6 & 0xfffffeff);
    uVar5 = 1;
  }
  return uVar5;
}



===== _SdDumpDebugPrint @ 140002110 =====

void _SdDumpDebugPrint(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if (g_EnableDbgPrint != '\0') {
    local_res10 = param_2;
    local_res18 = param_3;
    local_res20 = param_4;
    vDbgPrintExWithPrefix("DUMPSD: ",5,0,param_1,&local_res10);
  }
  return;
}



===== _SdDumpInitializeReadWriteRequest @ 140002164 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SdDumpInitializeReadWriteRequest(ulonglong *param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  lVar5 = g_DumpExtension;
  lVar1 = g_DumpExtension + 8;
  lVar2 = g_DumpExtension + 0x3b0;
  plVar3 = (longlong *)(g_DumpExtension + 0x4888);
  lVar4 = g_DumpExtension + 0x40c0;
  memset(&DAT_14002a648,0,0x68);
  _DAT_14002a6b0 = *param_1;
  if (*(char *)(lVar5 + 0x1168) != '\0') {
    _DAT_14002a6b0 = _DAT_14002a6b0 >> 9;
  }
  _DAT_14002a648 = 2;
  _DAT_14002a668 = 0;
  if (param_3 == '\0') {
    puVar6 = (undefined8 *)&DAT_140021f98;
    if (*(int *)(param_2 + 0x28) != 0x200) {
      puVar6 = (undefined8 *)&DAT_140021fb0;
    }
    _DAT_14002a688 = *puVar6;
    uRam000000014002a690 = puVar6[1];
    _DAT_14002a698 = *(undefined4 *)(puVar6 + 2);
    if (DAT_14002a610 == 0xffffffffffffffff) {
      DAT_14002a610 = 0;
    }
    DAT_14002a638 =
         (DAT_14002a638 * DAT_14002a610 + (ulonglong)*(uint *)(param_2 + 0x28)) /
         (DAT_14002a610 + 1);
    DAT_14002a610 = DAT_14002a610 + 1;
  }
  else {
    puVar6 = (undefined8 *)&DAT_140021f68;
    if (*(int *)(param_2 + 0x28) != 0x200) {
      puVar6 = (undefined8 *)&DAT_140021f80;
    }
    _DAT_14002a688 = *puVar6;
    uRam000000014002a690 = puVar6[1];
    _DAT_14002a698 = *(undefined4 *)(puVar6 + 2);
    if (DAT_14002a618 == 0xffffffffffffffff) {
      DAT_14002a618 = 0;
    }
    DAT_14002a640 =
         (DAT_14002a640 * DAT_14002a618 + (ulonglong)*(uint *)(param_2 + 0x28)) /
         (DAT_14002a618 + 1);
    DAT_14002a618 = DAT_14002a618 + 1;
  }
  _DAT_14002a69c = DAT_14002a6b0;
  _DAT_14002a6a8 = *(undefined4 *)(param_2 + 0x28);
  _DAT_14002a6a0 = param_2;
  SdbusInitializeWorkPacket(plVar3,0x13,lVar1,lVar4,0,0);
  SdbusWorkerPrepareForNewPacket(lVar2,plVar3);
  lVar2 = *(longlong *)(*(longlong *)(*plVar3 + 8) + 0x28);
  (**(code **)(lVar2 + 0x68))(*plVar3,CONCAT71((int7)((ulonglong)lVar2 >> 8),1));
  *(undefined4 *)(lVar5 + 0x1754) = 0;
  *(longlong *)(lVar5 + 0x3c0) = lVar1;
  *(undefined8 *)(lVar5 + 0x3f8) = 0;
  *(undefined4 *)(lVar5 + 0x558) = 1;
  *(undefined4 *)(lVar5 + 0x3c8) = 1;
  *(undefined **)(lVar5 + 0x4918) = &DAT_14002a648;
  return;
}



===== _SdDumpPollEventUntilChange @ 14000237c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _SdDumpPollEventUntilChange
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  longlong local_res8;
  
  uVar6 = *(uint *)(param_1 + 0x3f0);
  uVar2 = *(uint *)(param_1 + 0x3f4);
  local_res8 = 0;
  lVar4 = KeQueryPerformanceCounter(&local_res8);
  lVar1 = local_res8 * 5;
  do {
    if ((uVar6 != *(uint *)(param_1 + 0x3f0)) || (uVar2 != *(uint *)(param_1 + 0x3f4)))
    goto LAB_14000245b;
    uVar6 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
    uVar6 = (uVar6 | *(uint *)(param_1 + 0x3f0)) & *(uint *)(param_1 + 0x3a0);
    if ((uVar6 >> 0xc & 1) != 0) {
      uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
    }
    lVar5 = KeQueryPerformanceCounter(0);
  } while (lVar5 < lVar4 + lVar1);
  _SdDumpDebugPrint("TIMEOUT failure offset 0x%I64x try %d.\r\n",_DAT_14002a6b0,
                    (ulonglong)DAT_14002a634,param_4);
  *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
  *(undefined4 *)(param_1 + 0x3f4) = 0x11;
LAB_14000245b:
  KeStallExecutionProcessor(1);
  uVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
  uVar6 = (uVar6 | uVar3) & *(uint *)(param_1 + 0x3a0);
  if ((uVar6 >> 0xc & 1) != 0) {
    uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
  }
  *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | uVar6;
  *(uint *)(param_1 + 0x3f4) = *(uint *)(param_1 + 0x3f4) | uVar2;
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf8))(param_1,uVar6 & 0xfffffeff)
  ;
  return;
}



===== _SdDumpPollEventUntilChangeOrTimeout @ 1400024f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 _SdDumpPollEventUntilChangeOrTimeout(longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x3f0);
  iVar1 = *(int *)(param_1 + 0x3f4);
  uVar4 = 1;
  do {
    if ((uVar5 != *(uint *)(param_1 + 0x3f0)) || (iVar1 != *(int *)(param_1 + 0x3f4)))
    goto LAB_140002594;
    uVar5 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
    uVar5 = (uVar5 | *(uint *)(param_1 + 0x3f0)) & *(uint *)(param_1 + 0x3a0);
    if ((uVar5 >> 0xc & 1) != 0) {
      iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
    }
    if ((uVar5 == *(uint *)(param_1 + 0x578)) && (uVar5 != 0)) goto LAB_140002594;
    lVar3 = KeQueryPerformanceCounter(0);
  } while (lVar3 < DAT_14002a6b8);
  uVar4 = 2;
LAB_140002594:
  KeStallExecutionProcessor(1);
  uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf0))(param_1);
  uVar5 = (uVar5 | uVar2) & *(uint *)(param_1 + 0x3a0);
  if ((uVar5 >> 0xc & 1) != 0) {
    iVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xb8))(param_1);
  }
  *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | uVar5;
  *(int *)(param_1 + 0x3f4) = iVar1;
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0xf8))(param_1,uVar5 & 0xfffffeff)
  ;
  return uVar4;
}



===== _SdDumpProcessBusRequest @ 14000262c =====

void _SdDumpProcessBusRequest(char param_1,longlong param_2,longlong *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  plVar3 = param_3;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            iVar1 = *(int *)(param_2 + 0x18);
            if (iVar1 == 0) {
              return;
            }
            if (iVar1 != 1) break;
            *(undefined4 *)(param_2 + 0x18) = 2;
          }
          if (iVar1 != 2) break;
          _SdDumpBusWorker(param_2,param_3,plVar3,param_4);
        }
        if (iVar1 != 3) break;
        if (param_1 == '\0') {
          uVar2 = _SdDumpPollEventUntilChangeOrTimeout(*(longlong *)(param_2 + 0x10));
          iVar1 = (int)uVar2;
        }
        else {
          uVar2 = _SdDumpCheckEventsAndTimeout(*(longlong *)(param_2 + 0x10),'\x01');
          iVar1 = (int)uVar2;
          if (1 < iVar1 - 1U) {
            return;
          }
        }
        *(undefined4 *)(param_2 + 0x18) = 1;
        if ((iVar1 == 2) && (*(int *)(param_2 + 0x1d0) == 0)) {
          *(undefined4 *)(param_2 + 0x1d4) = 0;
        }
      }
    } while (iVar1 != 4);
    if (param_1 == '\0') {
      _SdDumpPollEventUntilChange(*(longlong *)(param_2 + 0x10),1,plVar3,param_4);
    }
    else {
      uVar2 = _SdDumpCheckEventsAndTimeout(*(longlong *)(param_2 + 0x10),'\0');
      if ((int)uVar2 != 1) {
        return;
      }
    }
    *(undefined4 *)(param_2 + 0x18) = 1;
  } while( true );
}



===== _SdDumpProcessReadWriteFailure @ 140002710 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _SdDumpProcessReadWriteFailure(char param_1,uint param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar4 = (ulonglong)DAT_14002a634;
  uVar1 = 0;
  uVar5 = (ulonglong)param_2;
  uVar3 = _DAT_14002a6b0;
  if (param_1 == '\0') {
    pcVar2 = "READ failure offset 0x%I64x try %d status 0x%x.\r\n";
    _SdDumpDebugPrint("READ failure offset 0x%I64x try %d status 0x%x.\r\n",_DAT_14002a6b0,uVar4,
                      uVar5);
    _DAT_14002a624 = _DAT_14002a624 + 1;
  }
  else {
    pcVar2 = "WRITE failure offset 0x%I64x try %d status 0x%x.\r\n";
    _SdDumpDebugPrint("WRITE failure offset 0x%I64x try %d status 0x%x.\r\n",_DAT_14002a6b0,uVar4,
                      uVar5);
    _DAT_14002a628 = _DAT_14002a628 + 1;
  }
  DAT_14002a634 = DAT_14002a634 + 1;
  if (DAT_14002a634 == 2) {
    uVar1 = _SdDumpResetHostAndCard(pcVar2,uVar3,uVar4,uVar5);
  }
  return uVar1;
}



===== _SdDumpReadWriteRequestAsync @ 14000277c =====

uint _SdDumpReadWriteRequestAsync
               (int param_1,ulonglong *param_2,longlong param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong *plVar7;
  char cVar8;
  
  lVar3 = g_DumpExtension;
  cVar8 = (char)param_4;
  uVar6 = 0;
  plVar1 = (longlong *)(g_DumpExtension + 0x4888);
  lVar2 = g_DumpExtension + 0x3b0;
  SdbusDebugPrint(0x200,"wp  %p _SdDumpReadWriteRequestAsync enter",plVar1,param_4);
  if (param_1 == 1) {
    DAT_14002a634 = 0;
    while (DAT_14002a634 < 3) {
      _SdDumpInitializeReadWriteRequest(param_2,param_3,cVar8);
      plVar7 = plVar1;
      _SdDumpProcessBusRequest('\x01',lVar2,plVar1,param_4);
      if (*(int *)(lVar3 + 0x3c8) - 3U < 2) goto LAB_1400028f5;
      uVar6 = *(uint *)(lVar3 + 0x48d8);
      if (-1 < (int)uVar6) break;
      uVar5 = (ulonglong)uVar6;
      uVar4 = _SdDumpProcessReadWriteFailure(cVar8,uVar6);
      if (uVar4 != 0) goto LAB_1400028f1;
      _SdDumpDebugPrint("DUMPSD will retry.\r\n",uVar5,plVar7,param_4);
    }
  }
  else if (param_1 == 2) {
    while (DAT_14002a634 < 3) {
      plVar7 = plVar1;
      _SdDumpProcessBusRequest('\x01',lVar2,plVar1,param_4);
      if (*(int *)(lVar3 + 0x3c8) - 3U < 2) goto LAB_1400028f5;
      uVar6 = *(uint *)(lVar3 + 0x48d8);
      if (-1 < (int)uVar6) break;
      uVar5 = (ulonglong)uVar6;
      uVar4 = _SdDumpProcessReadWriteFailure(cVar8,uVar6);
      if (uVar4 != 0) goto LAB_1400028f1;
      _SdDumpDebugPrint("DUMPSD will retry.\r\n",uVar5,plVar7,param_4);
      _SdDumpInitializeReadWriteRequest(param_2,param_3,cVar8);
    }
  }
  else if (param_1 == 3) {
    while (DAT_14002a634 < 3) {
      plVar7 = plVar1;
      _SdDumpProcessBusRequest('\0',lVar2,plVar1,param_4);
      uVar6 = *(uint *)(lVar3 + 0x48d8);
      if (-1 < (int)uVar6) break;
      uVar5 = (ulonglong)uVar6;
      uVar4 = _SdDumpProcessReadWriteFailure(cVar8,uVar6);
      if (uVar4 != 0) goto LAB_1400028f1;
      _SdDumpDebugPrint("DUMPSD will retry.\r\n",uVar5,plVar7,param_4);
      _SdDumpInitializeReadWriteRequest(param_2,param_3,cVar8);
    }
  }
LAB_1400028fa:
  SdbusDebugPrint(0x200,"wp  %p _SdDumpReadWriteRequestAsync exit %x",plVar1,(ulonglong)uVar6);
  return uVar6;
LAB_1400028f5:
  uVar6 = 0x103;
  goto LAB_1400028fa;
LAB_1400028f1:
  uVar6 = uVar4;
  goto LAB_1400028fa;
}



===== _SdDumpReadWriteRequestSync @ 14000293c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _SdDumpReadWriteRequestSync(ulonglong *param_1,longlong param_2,char param_3,ulonglong param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  char *pcVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  
  lVar3 = g_DumpExtension;
  uVar4 = 0;
  DAT_14002a634 = 0;
  plVar1 = (longlong *)(g_DumpExtension + 0x4888);
  lVar2 = g_DumpExtension + 0x3b0;
  SdbusDebugPrint(0x200,"wp  %p _SdDumpReadWriteRequestSync enter",plVar1,param_4);
  while (DAT_14002a634 < 3) {
    _SdDumpInitializeReadWriteRequest(param_1,param_2,param_3);
    _SdDumpProcessBusRequest('\0',lVar2,plVar1,param_4);
    uVar4 = *(uint *)(lVar3 + 0x48d8);
    if (-1 < (int)uVar4) break;
    uVar7 = (ulonglong)DAT_14002a634;
    param_4 = (ulonglong)uVar4;
    uVar6 = _DAT_14002a6b0;
    if (param_3 == '\0') {
      pcVar5 = "READ failure offset 0x%I64x try %d status 0x%x.\r\n";
      _SdDumpDebugPrint("READ failure offset 0x%I64x try %d status 0x%x.\r\n",_DAT_14002a6b0,uVar7,
                        param_4);
      _DAT_14002a624 = _DAT_14002a624 + 1;
    }
    else {
      pcVar5 = "WRITE failure offset 0x%I64x try %d status 0x%x.\r\n";
      _SdDumpDebugPrint("WRITE failure offset 0x%I64x try %d status 0x%x.\r\n",_DAT_14002a6b0,uVar7,
                        param_4);
      _DAT_14002a628 = _DAT_14002a628 + 1;
    }
    DAT_14002a634 = DAT_14002a634 + 1;
    if (DAT_14002a634 == 2) {
      uVar4 = _SdDumpResetHostAndCard(pcVar5,uVar6,uVar7,param_4);
      if ((int)uVar4 < 0) break;
    }
    _SdDumpDebugPrint("DUMPSD will retry.\r\n",uVar6,uVar7,param_4);
  }
  SdbusDebugPrint(0x200,"wp  %p _SdDumpReadWriteRequestSync exit %x",plVar1,(ulonglong)uVar4);
  return uVar4;
}



===== _SdDumpResetHostAndCard @ 140002a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_SdDumpResetHostAndCard(undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  ulonglong uVar11;
  int *piVar12;
  int *piVar13;
  uint local_res8;
  int *local_res10;
  
  lVar5 = g_DumpExtension;
  local_res10 = &g_wfBringHardwareUpPhase2_Default;
  local_res8 = 5;
  lVar2 = g_DumpExtension + 0x3b0;
  lVar1 = g_DumpExtension + 8;
  plVar3 = (longlong *)(g_DumpExtension + 0x4888);
  lVar6 = g_DumpExtension + 0x40c0;
  _SdDumpDebugPrint("RESET activation.\r\n",param_2,param_3,param_4);
  (**(code **)(*(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x28) + 0x128))(lVar1);
  do {
    uVar8 = 0;
    _DAT_14002a62c = _DAT_14002a62c + 1;
    if ((((*(char *)(lVar5 + 0x16a1) == '\x01') && (*(int *)(lVar5 + 0x1144) != 0)) &&
        (*(char *)(lVar5 + 0x1137) != '\0')) && (*(int *)(lVar5 + 0x1184) != 3)) {
      *(uint *)(lVar5 + 0x50) = *(uint *)(lVar5 + 0x50) & 0xefffffff;
    }
    if (*(char *)(*(longlong *)(lVar5 + 0x10) + 0x45) == '\n') {
      *(undefined4 *)(lVar5 + 0x168c) = *(undefined4 *)(lVar5 + 0x1154);
      if (*(int *)(lVar5 + 0x1184) == 2) {
        *(uint *)(lVar5 + 0x50) = *(uint *)(lVar5 + 0x50) | 0x10000000;
        *(undefined2 *)(lVar5 + 0x1131) = 0;
        *(undefined2 *)(lVar5 + 0x1661) = 0;
        *(undefined1 *)(lVar5 + 0x1133) = 0;
        *(undefined1 *)(lVar5 + 0x1663) = 0;
        *(undefined1 *)(lVar5 + 0x1660) = 1;
      }
      else {
        if ((*(char *)(lVar5 + 0x1665) == '\0') && (*(char *)(lVar5 + 0x1666) == '\0'))
        goto LAB_140002ba5;
        *(undefined2 *)(lVar5 + 0x1134) = 0;
        *(undefined2 *)(lVar5 + 0x1665) = 0;
        *(undefined1 *)(lVar5 + 0x1663) = 1;
      }
      *(undefined4 *)(lVar5 + 0x1680) = 50000;
      *(undefined4 *)(lVar5 + 0x1190) = 50000;
    }
LAB_140002ba5:
    if (*(char *)(*(longlong *)(lVar5 + 0x10) + 0x45) != '\x06') {
      *(undefined1 *)(lVar5 + 0x16a1) = 0;
    }
    *(undefined4 *)(lVar5 + 0x16a4) = 0;
    *(undefined1 *)(lVar5 + 0x63c) = 0;
    if ((*(char *)(*(longlong *)(lVar5 + 0x10) + 0x45) == '\n') &&
       (1 < *(byte *)(*(longlong *)(lVar5 + 0x10) + 0x46))) {
      *(undefined1 *)(lVar5 + 0x16ab) = 0;
    }
    *(undefined8 *)(lVar5 + 0x17cc) = 0;
    piVar12 = &g_wfBringHardwareUp;
    uVar11 = (ulonglong)local_res8;
    do {
      SdbusDebugPrint(0x40,"RESET activation stage %d",uVar8,param_4);
      SdbusInitializeWorkPacket(plVar3,*piVar12,lVar1,lVar6,0,0);
      SdbusWorkerPrepareForNewPacket(lVar2,plVar3);
      lVar4 = *(longlong *)(*(longlong *)(*plVar3 + 8) + 0x28);
      (**(code **)(lVar4 + 0x68))(*plVar3,CONCAT71((int7)((ulonglong)lVar4 >> 8),1));
      *(undefined4 *)(lVar5 + 0x1754) = 0;
      *(undefined4 *)(lVar5 + 0x558) = 1;
      *(undefined4 *)(lVar5 + 0x3c8) = 1;
      *(longlong *)(lVar5 + 0x3c0) = lVar1;
      *(undefined8 *)(lVar5 + 0x3f8) = 0;
      param_4 = uVar11;
      SdbusAddDbgLog(*plVar3,0x41435449,uVar8,uVar11,
                     (ulonglong)(*(byte *)(*(longlong *)(lVar5 + 0x238) + 0x28) >> 5 & 1));
      plVar10 = plVar3;
      _SdDumpProcessBusRequest('\0',lVar2,plVar3,param_4);
      _SdDumpDebugPrint("Data bus using 8-bit: %d\n",
                        (ulonglong)(*(byte *)(*(longlong *)(lVar5 + 0x238) + 0x28) >> 5 & 1),plVar10
                        ,param_4);
      if (*(int *)(lVar5 + 0x48d8) < 0) break;
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
      piVar12 = &g_wfBringHardwareUp + uVar7;
    } while (*piVar12 != 0);
    uVar8 = uVar11;
    SdbusAddDbgLog(*plVar3,0x41435449,0xffff,uVar11,(longlong)*(int *)(lVar5 + 0x44));
    if (*(int *)(lVar5 + 0x48d8) < 0) break;
    if (*(char *)(lVar5 + 0x1666) == '\0') {
      piVar12 = &g_wfBringHardwareUpPhase2_HS200;
      if (*(char *)(lVar5 + 0x1665) == '\0') {
        piVar12 = local_res10;
      }
    }
    else {
      piVar12 = &g_wfBringHardwareUpPhase2_HS400;
    }
    uVar9 = 0;
    if (*piVar12 != 0) {
      piVar13 = piVar12;
      do {
        SdbusDebugPrint(0x40,"RESET activation stage phase 2 %d",uVar9,uVar8);
        SdbusInitializeWorkPacket(plVar3,*piVar13,lVar1,lVar6,0,0);
        SdbusWorkerPrepareForNewPacket(lVar2,plVar3);
        lVar4 = *(longlong *)(*(longlong *)(*plVar3 + 8) + 0x28);
        (**(code **)(lVar4 + 0x68))(*plVar3,CONCAT71((int7)((ulonglong)lVar4 >> 8),1));
        *(undefined4 *)(lVar5 + 0x1754) = 0;
        *(undefined4 *)(lVar5 + 0x558) = 1;
        *(undefined4 *)(lVar5 + 0x3c8) = 1;
        *(longlong *)(lVar5 + 0x3c0) = lVar1;
        *(undefined8 *)(lVar5 + 0x3f8) = 0;
        uVar8 = uVar11;
        SdbusAddDbgLog(*plVar3,0x41435449,uVar9,uVar11,(longlong)*(int *)(lVar5 + 0x44));
        _SdDumpProcessBusRequest('\0',lVar2,plVar3,uVar8);
        if (*piVar13 == 0x37) {
          if ((*(char *)(lVar5 + 0x16ab) == '\0') || (*(char *)(lVar5 + 0x48e0) == '\0')) {
            DAT_14002a6c3 = 0;
          }
          else {
            DAT_14002a6c3 = 1;
          }
        }
        if (*(int *)(lVar5 + 0x48d8) < 0) break;
        uVar9 = (ulonglong)((int)uVar9 + 1);
        piVar13 = piVar12 + uVar9;
      } while (*piVar13 != 0);
    }
    SdbusAddDbgLog(*plVar3,0x41435449,0xffff,uVar11,(longlong)*(int *)(lVar5 + 0x44));
    if (-1 < *(int *)(lVar5 + 0x48d8)) break;
    _DAT_14002a630 = _DAT_14002a630 + 1;
    local_res8 = local_res8 - 1;
    SdbusDebugPrint(0x40,"SDDUMP RESET activation FAILED tries left %d",(ulonglong)local_res8,uVar11
                   );
    _SdDumpDebugPrint("RESET activation failed tries left %d status 0x%x.\r\n",(ulonglong)local_res8
                      ,(ulonglong)*(uint *)(lVar5 + 0x48d8),uVar11);
    KeStallExecutionProcessor(50000);
    param_4 = uVar11;
    local_res10 = piVar12;
  } while (local_res8 != 0);
  return *(undefined4 *)(lVar5 + 0x48d8);
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140002f08 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140029bff < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140002f34 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140003090 =====

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



===== DebugDumpBuffer @ 140003114 =====

void DebugDumpBuffer(longlong param_1,uint param_2,uint param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return;
    }
    if (param_3 == 1) {
      SdbusDebugPrint(0x10000,"%05x: %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 2) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 3) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 4) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 5) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 6) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    if (param_3 == 7) break;
    if (param_3 == 8) {
      SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x %02x %02x %02x %02x",(ulonglong)param_2,
                      (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
      return;
    }
    SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x %02x %02x %02x %02x- ...",(ulonglong)param_2,
                    (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
    if (param_3 < 0x11) {
      return;
    }
    param_2 = (param_2 - 1) + param_3 & 0xfffffff0;
    param_3 = param_3 - param_2;
    if (0x10 < param_3) {
      return;
    }
  }
  SdbusDebugPrint(0x10000,"%05x: %02x %02x %02x %02x %02x %02x %02x",(ulonglong)param_2,
                  (ulonglong)*(byte *)((ulonglong)param_2 + param_1));
  return;
}



===== DebugDumpCardStatus @ 1400034a0 =====

void DebugDumpCardStatus(uint param_1)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = ", AppCmd";
  if ((param_1 & 0x20) == 0) {
    pcVar3 = "";
  }
  uVar1 = param_1 & 0x1e00;
  if (uVar1 == 0) {
    pcVar2 = "idle";
  }
  else if (uVar1 == 0x200) {
    pcVar2 = "ready";
  }
  else if (uVar1 == 0x400) {
    pcVar2 = "ident";
  }
  else if (uVar1 == 0x600) {
    pcVar2 = "stby";
  }
  else if (uVar1 == 0x800) {
    pcVar2 = "tran";
  }
  else if (uVar1 == 0xa00) {
    pcVar2 = "data";
  }
  else if (uVar1 == 0xc00) {
    pcVar2 = "rcv";
  }
  else if (uVar1 == 0xe00) {
    pcVar2 = "prg";
  }
  else {
    pcVar2 = "dis";
    if (uVar1 != 0x1000) {
      pcVar2 = "???";
    }
  }
  SdbusDebugPrint(0x2000,"SD_RESP           prevState=%s%s%s",pcVar2,pcVar3);
  return;
}



===== DebugDumpSdResponse @ 140003590 =====

void DebugDumpSdResponse(byte *param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  ulonglong uVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 1) {
    SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== none",(ulonglong)*param_1,param_4);
    return;
  }
  if ((iVar1 == 2) || (iVar1 == 3)) {
    uVar2 = *param_2;
    SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== R1 Card Status = 0x%08x",(ulonglong)*param_1,
                    (ulonglong)uVar2);
LAB_1400037fd:
    DebugDumpCardStatus(uVar2);
  }
  else {
    if (iVar1 == 4) {
      uVar2 = *param_2;
      uVar7 = (ulonglong)*param_1;
      pcVar6 = "SD_RESP CMD%d <== R2 0x%08x 0x%08x 0x%08x 0x%08x";
    }
    else {
      if (iVar1 != 5) {
        if (iVar1 == 6) {
          SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== R4 Io OCR 0x%08x",(ulonglong)*param_1,
                          (ulonglong)*param_2);
          return;
        }
        if (iVar1 == 7) {
          SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== R5 0x%08x state=%d%s%s%s%s%s",
                          (ulonglong)*param_1,(ulonglong)*param_2);
          return;
        }
        if (iVar1 != 9) {
          return;
        }
        SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== R6 RCA+Status 0x%08x",(ulonglong)*param_1,
                        (ulonglong)*param_2);
        uVar2 = *param_2 & 0x7ffff;
        goto LAB_1400037fd;
      }
      SdbusDebugPrint(0x2000,"SD_RESP CMD%d <== R3 Mem OCR 0x%08x",(ulonglong)*param_1,
                      (ulonglong)*param_2);
      uVar2 = *param_2 >> 4;
      uVar3 = uVar2 & 0xfffff;
      if (uVar3 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 0x10;
        uVar4 = 1;
        uVar5 = uVar2 & 1;
        while (uVar5 == 0) {
          uVar8 = (uint)(ushort)((short)uVar8 + 1);
          uVar4 = uVar4 * 2;
          uVar5 = uVar3 & uVar4;
        }
        uVar5 = 0x80000;
        uVar2 = uVar2 & 0x80000;
        while (uVar2 == 0) {
          uVar5 = uVar5 >> 1;
          uVar2 = uVar3 & uVar5;
        }
      }
      uVar2 = uVar8 % 10;
      uVar7 = (ulonglong)uVar8 / 10;
      pcVar6 = "SD_RESP           %d.%dV - %d.%dV, %s";
    }
    SdbusDebugPrint(0x2000,pcVar6,uVar7,(ulonglong)uVar2);
  }
  return;
}



===== SdbusAddDbgLog @ 140003830 =====

void SdbusAddDbgLog(longlong param_1,uint param_2,ulonglong param_3,ulonglong param_4,
                   ulonglong param_5)

{
  int *piVar1;
  int iVar2;
  ulonglong *puVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x2b0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar3 = (ulonglong *)
           ((ulonglong)(*(uint *)(param_1 + 0x2b4) & iVar2 - 1U) * 0x20 +
           *(longlong *)(param_1 + 0x2b8));
  *(ulonglong **)(param_1 + 0x2c0) = puVar3;
  puVar3[1] = param_3;
  puVar3[3] = param_5;
  *puVar3 = (ulonglong)
            ((param_2 & 0xff00 | param_2 << 0x10) << 8 | (param_2 & 0xff0000 | param_2 >> 0x10) >> 8
            );
  puVar3[2] = param_4;
  return;
}



===== SdbusAddFxDbgLog @ 1400038a4 =====

void SdbusAddFxDbgLog(longlong param_1,uint param_2,ulonglong param_3,ulonglong param_4,
                     ulonglong param_5)

{
  int *piVar1;
  int iVar2;
  ulonglong *puVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x218);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  puVar3 = (ulonglong *)
           ((ulonglong)(*(uint *)(param_1 + 0x21c) & iVar2 - 1U) * 0x20 +
           *(longlong *)(param_1 + 0x220));
  *(ulonglong **)(param_1 + 0x228) = puVar3;
  puVar3[1] = param_3;
  puVar3[3] = param_5;
  *puVar3 = (ulonglong)
            ((param_2 & 0xff00 | param_2 << 0x10) << 8 | (param_2 & 0xff0000 | param_2 >> 0x10) >> 8
            );
  puVar3[2] = param_4;
  return;
}



===== SdbusDbgDumpEventString @ 140003918 =====

void SdbusDbgDumpEventString(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  uint uVar2;
  longlong lVar3;
  
  uVar2 = 1;
  lVar3 = 0x20;
  do {
    if ((param_1 & uVar2) != 0) {
      pcVar1 = SdbusDbgLookupString((int *)&SdbusDbgEventStringMap,uVar2);
      SdbusDebugPrint(0x40000,"    %s",pcVar1,param_4);
    }
    uVar2 = uVar2 * 2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== SdbusDbgLookupString @ 140003978 =====

char * SdbusDbgLookupString(int *param_1,int param_2)

{
  while( true ) {
    if (*param_1 == -1) {
      return "** UNKNOWN **";
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 4;
  }
  return *(char **)(param_1 + 2);
}



===== SdbusDebugPrint @ 1400039a0 =====

void SdbusDebugPrint(undefined4 param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(0x4d,param_1,param_2,&local_res18);
  pcVar1 = strstr(param_2,"\n");
  if (pcVar1 == (char *)0x0) {
    DbgPrintEx(0x4d,param_1,"\r\n");
  }
  return;
}



===== Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline @ 140003a14 =====

ulonglong Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_SupportForSDUltraCapacity__private_featureState;
  if ((Feature_SupportForSDUltraCapacity__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SupportForSDUltraCapacity__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SupportForSDUltraCapacity__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SupportForSDUltraCapacity__private_IsEnabledFallback @ 140003a4c =====

void Feature_SupportForSDUltraCapacity__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== GetPciConfigSpace @ 140003a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint GetPciConfigSpace(longlong param_1,undefined1 param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(code **)(param_1 + 0x2c0) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x2c0))
                      (*(undefined8 *)(param_1 + 0x290),0,param_3,param_2,param_4);
  }
  return -(uint)(iVar1 != param_4) & 0xc0000001;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003aac =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14002a488;
  uVar2 = 0;
  if (DAT_14002a488 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14002a488;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(SDBUS_DIAG_TRACE_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0ix_EtwWriteTransfer @ 140003b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ix_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(8,param_2,param_3,3,local_48);
  return;
}



===== PlSystemDmaControl @ 140003b80 =====

undefined8
PlSystemDmaControl(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  *(undefined8 *)(param_4 + 0x300) = param_3;
  SdbusWorkerPushEvents(param_4,0x20000,0,'\x01','\0');
  return 1;
}



===== SdhcAcknowledgeEvent @ 140003bc0 =====

void SdhcAcknowledgeEvent(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  
  if ((param_2 >> 0xc & 1) != 0) {
    SdbusWriteRegisterUshort(param_1,0x3c,0xffff);
    SdbusWriteRegisterUshort(param_1,0x3c,0);
    SdbusWriteRegisterUshort(param_1,0x32,0xffff);
    param_2 = param_2 & 0xffffefff;
    SdbusDebugPrint(2,"skt %p SDHOST: Clean error status",param_1,param_4);
  }
  uVar1 = SdhcEventMaskToHardwareMask(param_2);
  SdbusWriteRegisterUshort(param_1,0x30,uVar1);
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
     (*(uint *)(param_1 + 0x167c) < 0x191)) {
    KeStallExecutionProcessor(0x28);
  }
  return;
}



===== SdhcAmdResetDll @ 140003c70 =====

void SdhcAmdResetDll(longlong param_1)

{
  if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\f') {
    SdbusWriteRegisterUshort(param_1,0x908,0x3232);
    SdbusWriteRegisterUshort(param_1,0x90a,0x4000);
    KeStallExecutionProcessor(0x1e);
    *(undefined1 *)(param_1 + 0x16a6) = 0;
  }
  return;
}



===== Pl180ArmWakeInterrupt @ 140003cd0 =====

undefined8 Pl180ArmWakeInterrupt(void)

{
  return 0;
}



===== SdhcCalcClockFrequency @ 140003ce0 =====

void SdhcCalcClockFrequency(longlong param_1,uint param_2,uint param_3,uint *param_4,short *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  short sVar3;
  ulonglong uVar4;
  uint uVar5;
  
  *param_4 = 0;
  *param_5 = 0;
  if ((*(uint *)(param_1 + 0x20) & 0x1000000) == 0) {
    uVar5 = 1;
    uVar2 = param_2;
    if (*(byte *)(param_1 + 0x1154) < 2) {
      while ((param_3 < uVar2 && (uVar5 < 0x100))) {
        uVar5 = uVar5 * 2;
        uVar2 = param_2 / uVar5;
      }
      *param_4 = param_2 / uVar5;
      sVar3 = (short)(uVar5 >> 1) << 8;
      goto LAB_140003e03;
    }
    uVar5 = (uint)((ulonglong)param_2 / (ulonglong)param_3 >> 1);
    if ((param_3 < param_2) && (uVar5 * param_3 * 2 != param_2)) {
      uVar5 = uVar5 + 1;
    }
    uVar2 = 0x3ff;
    if ((uVar5 < 0x400) && (uVar2 = uVar5, uVar5 == 0)) {
      *param_4 = param_2;
      if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
         (*(char *)(param_1 + 0x165b) != '\0')) {
        uVar2 = 1;
        *param_4 = param_2 >> 1;
      }
    }
    else {
      *param_4 = (uint)((ulonglong)param_2 / (ulonglong)uVar2 >> 1);
    }
    uVar4 = (ulonglong)(ushort)((ushort)(uVar2 >> 8) & 3 | (short)uVar2 << 2);
  }
  else {
    uVar1 = 96000 / (ulonglong)param_3;
    uVar4 = (ulonglong)((int)uVar1 + 1);
    if ((uint)(96000 / uVar1) <= param_3) {
      uVar4 = uVar1;
    }
    *param_4 = (uint)(96000 / uVar4);
  }
  sVar3 = (short)uVar4 << 6;
LAB_140003e03:
  *param_5 = sVar3;
  return;
}



===== SdhcCreateDescriptorTable @ 140003e24 =====

undefined8 SdhcCreateDescriptorTable(longlong param_1,int *param_2,int *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint *puVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  longlong *plVar8;
  int iVar9;
  
  iVar9 = *param_2;
  plVar8 = (longlong *)(param_2 + 4);
  puVar3 = *(uint **)(param_1 + 0x370);
  puVar7 = (uint *)0x0;
  *param_3 = 0;
  if (iVar9 != 0) {
    do {
      uVar6 = *(uint *)(plVar8 + 1);
      lVar1 = *plVar8;
      if (uVar6 != 0) {
        iVar5 = *param_3;
        do {
          puVar7 = puVar3;
          puVar3 = puVar7 + 1;
          uVar2 = 0xf000;
          if (uVar6 < 0xf000) {
            uVar2 = (ulonglong)uVar6;
          }
          *puVar7 = 0x21;
          iVar5 = iVar5 + (int)uVar2;
          *(short *)((longlong)puVar7 + 2) = (short)uVar2;
          uVar6 = uVar6 - (int)uVar2;
          *param_3 = iVar5;
          if (*(char *)(param_1 + 0x1127) == '\0') {
            *puVar3 = (uint)lVar1;
            lVar4 = 4;
          }
          else {
            *(longlong *)puVar3 = lVar1;
            lVar4 = 8;
          }
          puVar3 = (uint *)((longlong)puVar3 + lVar4);
          lVar1 = lVar1 + uVar2;
        } while (uVar6 != 0);
      }
      plVar8 = plVar8 + 3;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *puVar7 = *puVar7 | 2;
  }
  return 0;
}



===== _guard_check_icall @ 140003ee0 =====

void _guard_check_icall(void)

{
  return;
}



===== SdhcDetectCardInSocket @ 140003ef0 =====

ushort SdhcDetectCardInSocket(longlong param_1)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined8 in_RAX;
  undefined7 uVar4;
  
  cVar1 = *(char *)(*(longlong *)(param_1 + 8) + 0x45);
  uVar4 = (undefined7)((ulonglong)in_RAX >> 8);
  if ((cVar1 == '\x06') && (*(longlong *)(param_1 + 0x1f8) == 0xc8000400)) {
    uVar2 = (short)((ulonglong)in_RAX >> 8) << 8;
  }
  else if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x380) == 0) {
    if ((cVar1 == '\x05') || (*(char *)(param_1 + 0x16e8) != '\0')) {
      uVar2 = (ushort)CONCAT71(uVar4,1);
    }
    else {
      uVar3 = SdbusReadRegisterUlong(param_1,0x24);
      uVar2 = (ushort)((uint)uVar3 >> 0x10) & 0xff01;
    }
  }
  else {
    uVar2 = (ushort)CONCAT71(uVar4,*(undefined1 *)(param_1 + 0x1654));
  }
  return uVar2;
}



===== SdhcDisableAllHostControllerInterrupts @ 140003f50 =====

void SdhcDisableAllHostControllerInterrupts(longlong param_1)

{
  SdbusWriteRegisterUshort(param_1,0x3a,0);
  SdbusWriteRegisterUshort(param_1,0x38,0);
  return;
}



===== SdhcEventMaskToHardwareMask @ 140003f84 =====

ushort SdhcEventMaskToHardwareMask(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = -(ushort)((param_1 & 1) != 0) & 0xc0;
  uVar2 = uVar1 | 1;
  if ((param_1 & 4) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 2;
  if ((param_1 & 8) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x10;
  if ((param_1 & 0x10) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x20;
  if ((param_1 & 0x20) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x100;
  if ((param_1 & 0x100) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 8;
  if ((param_1 & 0x40) == 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}



===== SdhcExecuteRetuning @ 140004010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhcExecuteRetuning(undefined8 *param_1,longlong param_2,undefined8 *param_3,longlong *param_4)

{
  longlong *plVar1;
  undefined8 *puVar2;
  byte bVar3;
  longlong lVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  char cVar9;
  byte bVar10;
  ushort uVar11;
  ushort uVar12;
  byte bVar13;
  ulonglong uVar14;
  byte *pbVar15;
  ulonglong uVar16;
  undefined8 local_res10;
  
  iVar5 = *(int *)(param_2 + 0x174c);
  local_res10 = 0;
  if (iVar5 == 0) {
    SdbusDebugPrint(1,"skt %p: Start retuning procedure",param_2,param_4);
    uVar7 = SdbusReadRegisterUshort(param_2,0x3e);
    LOCK();
    *(int *)(param_2 + 0x2aa0) = *(int *)(param_2 + 0x2aa0) + 1;
    UNLOCK();
    if ((Microsoft_Windows_SdbusEnableBits & 4) != 0) {
      McTemplateK0ix_EtwWriteTransfer
                ((longlong)*(int *)(param_2 + 0x2aa0),&Retune,4,*(undefined8 *)(param_2 + 0x208),
                 (char)*(int *)(param_2 + 0x2aa0));
    }
    (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0x140))(param_2,param_2 + 0xd8);
    SdbusDisableEvents(param_2,0x105d);
    *(longlong *)(param_2 + 0x17cc) = _DAT_fffff78000000320;
    *(undefined1 *)(param_2 + 0x17d4) = 0xff;
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\x06') {
      if ((uVar7 & 0x40) == 0) {
        SdbusWriteRegisterUshort(param_2,0x3e,(ushort)uVar7 | 0x40);
      }
      goto LAB_140004818;
    }
    *(undefined4 *)(param_2 + 0x17d5) = 0xff0000;
    *(undefined4 *)(param_2 + 0x174c) = 1;
LAB_140004776:
    puVar2 = (undefined8 *)(param_2 + 0x17dc);
    *puVar2 = 0;
    *(undefined8 *)(param_2 + 0x17e4) = 0;
    *(undefined8 *)(param_2 + 0x17ec) = 0;
    *(undefined8 *)(param_2 + 0x17f4) = 0;
    *(undefined8 *)(param_2 + 0x17fc) = 0;
    *(undefined8 *)(param_2 + 0x1804) = 0;
    *(undefined8 *)(param_2 + 0x180c) = 0;
    *(undefined8 *)(param_2 + 0x1814) = 0;
    *(undefined4 *)(param_2 + 0x181c) = 0;
    *(undefined4 *)puVar2 = 2;
    *(undefined1 *)(param_2 + 0x17e0) = 1;
    PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                     &GUID_NVPEP_SD_POWER_CONTROL,puVar2,0x20,(undefined8 *)(param_2 + 0x17fc),0x24,
                     &local_res10);
    *param_1 = 0x200000;
    *(undefined4 *)(param_2 + 0x174c) = 2;
    return -0x3fffffea;
  }
  if (iVar5 == 1) goto LAB_140004776;
  if (iVar5 == 2) {
    if (*(int *)(param_2 + 0x17fc) < 0) {
      uVar11 = 0x2c;
      uVar7 = SdbusReadRegisterUshort(param_2,0x2c);
      SdbusWriteRegisterUshort(param_2,uVar11,(ushort)uVar7 & 0xfffb);
      *(undefined1 *)((longlong)param_1 + 0xc) = 1;
      *(undefined4 *)((longlong)param_1 + 4) = 0x32;
      *(undefined4 *)(param_2 + 0x174c) = 5;
      return -0x3fffffea;
    }
  }
  else if (iVar5 != 3) {
    if (iVar5 != 4) {
      if (iVar5 == 5) {
        uVar11 = 0x2c;
        uVar7 = SdbusReadRegisterUshort(param_2,0x2c);
        SdbusWriteRegisterUshort(param_2,uVar11,uVar11 - 0x28 | (ushort)uVar7);
        *(undefined4 *)((longlong)param_1 + 4) = *(undefined4 *)(param_2 + 0x170c);
        *(undefined4 *)(param_2 + 0x174c) = 6;
        return -0x3fffffea;
      }
      if (iVar5 != 6) {
        if (iVar5 == 7) {
          cVar9 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
          if (cVar9 == '\v') {
            SdbusWriteRegisterUchar(param_2,0x2f,4);
            *(undefined1 *)(param_2 + 0x17d4) = 0;
            *(undefined4 *)((longlong)param_1 + 4) = 10000;
            *(undefined4 *)(param_2 + 0x174c) = 8;
            return -0x3fffffea;
          }
          if (cVar9 == '\x06') {
            param_3 = (undefined8 *)(param_2 + 0x17dc);
            *param_3 = 0;
            *(undefined8 *)(param_2 + 0x17e4) = 0;
            param_4 = (longlong *)0x20;
            *(undefined8 *)(param_2 + 0x17ec) = 0;
            *(undefined8 *)(param_2 + 0x17f4) = 0;
            *(undefined8 *)(param_2 + 0x17fc) = 0;
            *(undefined8 *)(param_2 + 0x1804) = 0;
            *(undefined8 *)(param_2 + 0x180c) = 0;
            *(undefined8 *)(param_2 + 0x1814) = 0;
            *(undefined4 *)(param_2 + 0x181c) = 0;
            *(uint *)(param_2 + 0x17e4) = (uint)*(byte *)(param_2 + 0x17d7);
            *(uint *)(param_2 + 0x17e8) = (uint)*(byte *)(param_2 + 0x17d8);
            *(uint *)(param_2 + 0x17ec) = (uint)*(byte *)(param_2 + 0x17d6);
            *(undefined4 *)param_3 = 2;
            *(undefined1 *)(param_2 + 0x17e0) = 0;
            PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                             &GUID_NVPEP_SD_POWER_CONTROL,param_3,0x20,
                             (undefined8 *)(param_2 + 0x17fc),0x24,&local_res10);
          }
        }
        else {
          if (iVar5 != 8) goto LAB_140004090;
          if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\v') {
            iVar5 = -0x3fffff45;
            goto LAB_14000462c;
          }
          iVar5 = 0x2f;
          uVar7 = SdbusReadRegisterUchar(param_2,0x2f);
          param_3 = (undefined8 *)(ulonglong)(iVar5 - 0x2bU);
          if ((byte)((byte)(iVar5 - 0x2bU) & (byte)uVar7) != 0) {
            *(char *)(param_2 + 0x17d4) = *(char *)(param_2 + 0x17d4) + '\x01';
            if (*(uint *)(param_2 + 0x17c8) < 100) {
              if (*(uint *)(param_2 + 0x17c8) == 1) {
                *(undefined1 *)((longlong)param_1 + 0xc) = 1;
                iVar5 = iVar5 + 3;
              }
              else {
                iVar5 = 10000;
              }
              *(int *)((longlong)param_1 + 4) = iVar5;
              return -0x3fffffea;
            }
            iVar5 = -0x3fffff5d;
            goto LAB_14000462c;
          }
          uVar6 = SdbusReadRegisterUlong(param_2,0x840);
          *(byte *)(param_2 + 0x16a7) = (byte)uVar6 & 0x1f;
        }
      }
      iVar5 = 0;
      goto LAB_14000462c;
    }
    uVar11 = 0x3e;
    uVar7 = SdbusReadRegisterUshort(param_2,0x3e);
    uVar12 = (ushort)uVar7;
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x06') {
      param_4 = *(longlong **)(param_2 + 0x568);
      plVar1 = param_4 + 7;
      if (((byte)(uVar7 & 0xffff) & 0xc0) == 0x80) {
        if ((int)*plVar1 != 0) {
LAB_1400042d8:
          *(int *)plVar1 = 0;
          goto LAB_1400042f5;
        }
        if (*(char *)(param_2 + 0x17d6) != '\0') goto LAB_14000426e;
        bVar3 = *(byte *)(param_2 + 0x17d5);
        bVar13 = *(byte *)(param_2 + 0x17d7);
        if (bVar3 < *(byte *)(param_2 + 0x17d7)) {
          *(byte *)(param_2 + 0x17d7) = bVar3;
          bVar13 = bVar3;
        }
        bVar10 = *(byte *)(param_2 + 0x17d8);
        if (*(byte *)(param_2 + 0x17d8) < bVar3) {
          *(byte *)(param_2 + 0x17d8) = bVar3;
          bVar10 = bVar3;
        }
        if (bVar3 != 0) goto LAB_140004818;
LAB_1400042bc:
        cVar9 = (char)((uint)bVar13 + (uint)bVar10 >> 1);
        *(char *)(param_2 + 0x17d6) = cVar9;
        *(char *)(param_2 + 0x17d5) = cVar9 + '\x01';
LAB_140004818:
        *(undefined4 *)(param_2 + 0x174c) = 3;
        return -0x3fffffea;
      }
      if ((int)*plVar1 != 0) goto LAB_1400042d8;
      param_4 = (longlong *)*param_4;
      SdbusAddDbgLog((longlong)param_4,0x45724877,(ulonglong)(uVar7 & 0xffff),(ulonglong)param_4,0);
LAB_1400042f5:
      (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0xf8))(param_2,0xffffffff);
      param_3 = (undefined8 *)(ulonglong)(uVar12 & 0xff3f);
      SdbusWriteRegisterUshort(param_2,0x3e,uVar12 & 0xff3f);
      if (*(char *)(param_2 + 0x17d6) == '\0') {
        bVar10 = *(byte *)(param_2 + 0x17d7);
        bVar13 = *(byte *)(param_2 + 0x17d8);
        if (bVar10 <= bVar13) goto LAB_1400042bc;
        if (*(char *)(param_2 + 0x17d5) != '\0') goto LAB_140004818;
      }
    }
    else {
      if ((uVar7 & 0x40) != 0) {
        iVar5 = KeQueryTimeIncrement();
        if ((0x28 < *(byte *)(param_2 + 0x17d4)) ||
           ((longlong)(150000000 / (ulonglong)(uint)(iVar5 * 100)) <
            _DAT_fffff78000000320 - *(longlong *)(param_2 + 0x17cc))) {
          SdbusDebugPrint(1,"skt %p: Retuning timed out, stop retuning procedure",param_2,param_4);
          SdbusWriteRegisterUshort(param_2,0x3e,uVar12 & 0xff3f);
LAB_14000426e:
          *(undefined4 *)((longlong)param_1 + 4) = 100000;
          *(undefined4 *)(param_2 + 0x174c) = 7;
          return -0x3fffffea;
        }
        goto LAB_140004818;
      }
      if ((uVar7 & 0x80) != 0) goto LAB_14000426e;
      param_3 = (undefined8 *)(ulonglong)(uVar12 & 0xffbf);
      SdbusWriteRegisterUshort(param_2,uVar11,uVar12 & 0xffbf);
    }
LAB_140004090:
    iVar5 = -0x3fffffff;
    goto LAB_14000462c;
  }
  bVar13 = *(char *)(param_2 + 0x17d4) + 1;
  *(byte *)(param_2 + 0x17d4) = bVar13;
  bVar10 = *(char *)(param_2 + 0x17d5) - 1;
  if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\x06') {
    bVar10 = *(char *)(param_2 + 0x17d5) + 1;
  }
  *(byte *)(param_2 + 0x17d5) = bVar10;
  if ((*(char *)(param_2 + 0x165d) == '\0') && (*(char *)(param_2 + 0x165e) == '\0')) {
    pbVar15 = &CmdDescSendTuningBlock;
    uVar16 = 0x40;
    uVar14 = 0x13;
  }
  else {
    uVar16 = 0x80;
    pbVar15 = &CmdDescSendTuningBlockMmc;
    uVar14 = 0x15;
  }
  if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x06') {
    bVar13 = bVar10;
  }
  SdbusAddDbgLog(param_2,0x434d4420,(longlong)(*(int *)(pbVar15 + 4) << 0x10) | uVar14,
                 (ulonglong)bVar13,uVar16);
  param_3 = (undefined8 *)0x0;
  param_4 = (longlong *)0x1;
  uVar8 = SdhcInitializeTransfer(param_2,(ushort)uVar16,0,1,1,param_2 + 0x1834,0,'\0');
  iVar5 = (int)uVar8;
  if (-1 < iVar5) {
    if (((*(uint *)(param_2 + 0x48) & 0x40000000) == 0) &&
       (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\v')) {
      iVar5 = KeQueryTimeIncrement();
      lVar4 = _DAT_fffff78000000320;
      do {
        uVar7 = SdbusReadRegisterUlong(param_2,0x24);
        if ((longlong)(10000000 / (ulonglong)(uint)(iVar5 * 100)) < _DAT_fffff78000000320 - lVar4) {
          *(uint *)(param_2 + 0x3f0) = *(uint *)(param_2 + 0x3f0) | 0x1000;
          *(undefined4 *)(param_2 + 0x3f4) = 0x11;
          break;
        }
      } while (((uVar7 & 1) != 0) || ((uVar7 & 2) != 0));
    }
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x06') {
      uVar11 = 0x100;
      uVar7 = SdbusReadRegisterUlong(param_2,0x100);
      SdbusWriteRegisterUlong
                (param_2,uVar11,(uint)*(byte *)(param_2 + 0x17d5) << 0x10 | uVar7 & 0xff00ffff);
      uVar11 = 0x3e;
      uVar7 = SdbusReadRegisterUshort(param_2,0x3e);
      SdbusWriteRegisterUshort(param_2,uVar11,(ushort)uVar7 | 0x40);
    }
    param_4 = (longlong *)0x0;
    param_3 = (undefined8 *)0x0;
    uVar8 = SdhcSendCommand(param_2,pbVar15,0,0);
    uVar7 = SdTransferTimeout;
    iVar5 = (int)uVar8;
    if (-1 < iVar5) {
      *(undefined4 *)((longlong)param_1 + 4) = 1000;
      *(uint *)(param_1 + 1) = uVar7 / 100;
      *(undefined4 *)param_1 = 0x20;
      *(undefined4 *)(param_2 + 0x174c) = 4;
      return -0x3fffffea;
    }
  }
  if (iVar5 == -0x3fffffea) {
    return -0x3fffffea;
  }
LAB_14000462c:
  SdhcAcknowledgeEvent(param_2,0xfffffeff,param_3,param_4);
  SdbusEnableEvents(param_2,(*(uint *)(param_2 + 0x20) & 0x200000 | 0x20fa000) >> 0xd);
  *(undefined1 *)(param_2 + 0x1699) = 1;
  if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\x06') ||
     (*(int *)(param_2 + 0x169c) = *(int *)(param_2 + 0x17fc), -1 < *(int *)(param_2 + 0x17fc))) {
    *(int *)(param_2 + 0x169c) = iVar5;
  }
  *(undefined4 *)(param_2 + 0x174c) = 0;
  uVar7 = SdbusReadRegisterUshort(param_2,0x3e);
  *(short *)(param_2 + 0x1759) = (short)uVar7;
  (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0x140))(param_2,param_2 + 0x15c);
  return iVar5;
}



===== SdhcGetCmdDatInhibit @ 140004850 =====

void SdhcGetCmdDatInhibit(longlong param_1,byte *param_2,byte *param_3)

{
  uint uVar1;
  
  if ((*(int *)(*(longlong *)(param_1 + 8) + 0x20) == 0) &&
     ((param_2 != (byte *)0x0 || (param_3 != (byte *)0x0)))) {
    uVar1 = SdbusReadRegisterUlong(param_1,0x24);
    if (param_2 != (byte *)0x0) {
      *param_2 = (byte)uVar1 & 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = (byte)(uVar1 >> 1) & 1;
    }
  }
  return;
}



===== SdhcGetErrorStates @ 1400048b0 =====

uint SdhcGetErrorStates(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  uVar1 = SdbusReadRegisterUshort(param_1,0x32);
  uVar1 = uVar1 & 0xffff;
  uVar2 = uVar1;
  if (uVar1 != 0) {
    uVar6 = (ulonglong)uVar1;
    SdbusDebugPrint(1,"skt %p SDHOST: hwErrorStatus = %08x",param_1,uVar6);
    if ((uVar1 >> 8 & 1) != 0) {
      uVar2 = SdbusReadRegisterUshort(param_1,0x3c);
      uVar6 = (ulonglong)(uVar2 & 0xffff);
      uVar2 = uVar1 | uVar2 << 0x10;
      SdbusDebugPrint(2,"skt %p SDHOST: Auto Cmd12 Error Status = %08x",param_1,uVar6);
    }
    if ((uVar2 >> 9 & 1) != 0) {
      uVar3 = SdbusReadRegisterUshort(param_1,0x54);
      uVar6 = (ulonglong)(uVar3 & 0xffff);
      SdbusDebugPrint(2,"skt %p SDHOST: ADMA Error Status = %08x",param_1,uVar6);
    }
    uVar3 = 1;
    lVar5 = 0x20;
    do {
      if ((uVar3 & uVar1) != 0) {
        pcVar4 = SdbusDbgLookupString((int *)&SdbusDbgErrorStatusStringMap,uVar3);
        SdbusDebugPrint(2,"    %s",pcVar4,uVar6);
      }
      uVar3 = uVar3 * 2;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  if (((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x06') &&
      (*(char *)(*(longlong *)(param_1 + 8) + 0x46) != '\0')) && ((uVar2 & 0x22) != 0)) {
    uVar1 = SdbusReadRegisterUlong(param_1,0x100);
    SdbusAddDbgLog(param_1,0x43524354,param_1,
                   (ulonglong)*(uint *)(*(longlong *)(param_1 + 8) + 0x13c),
                   (ulonglong)(uVar1 >> 0x10 & 0xff));
  }
  return uVar2;
}



===== SdhcGetPendingEvents @ 140004a00 =====

ulonglong SdhcGetPendingEvents(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  uVar1 = SdbusReadRegisterUshort(param_1,0x30);
  if ((short)uVar1 != -1) {
    uVar3 = (uint)CONCAT71((int7)(uVar4 >> 8),(uVar1 & 0xc0) != 0);
    uVar2 = uVar3 | 4;
    if ((uVar1 & 1) == 0) {
      uVar2 = uVar3;
    }
    uVar3 = uVar2 | 8;
    if ((uVar1 & 2) == 0) {
      uVar3 = uVar2;
    }
    uVar2 = uVar3 | 0x10;
    if ((uVar1 & 0x10) == 0) {
      uVar2 = uVar3;
    }
    uVar3 = uVar2 | 0x20;
    if ((uVar1 & 0x20) == 0) {
      uVar3 = uVar2;
    }
    uVar2 = uVar3 | 0x100;
    if ((uVar1 & 0x100) == 0) {
      uVar2 = uVar3;
    }
    uVar3 = uVar2 | 0x40;
    if ((uVar1 & 8) == 0) {
      uVar3 = uVar2;
    }
    uVar2 = uVar3 | 0x1000;
    if (-1 < (short)uVar1) {
      uVar2 = uVar3;
    }
    uVar4 = (ulonglong)(uVar2 | 0x200);
    if ((uVar1 & 0x1000) == 0) {
      uVar4 = (ulonglong)uVar2;
    }
  }
  return uVar4 & 0xffffffff;
}



===== SdhcGetResponse @ 140004ab0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 SdhcGetResponse(longlong param_1,longlong param_2,uint param_3,void *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined4 *_Src;
  byte bVar4;
  undefined8 uVar5;
  undefined1 auStack_78 [32];
  undefined1 local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_78;
  uVar5 = 0x10;
  if (param_3 < 0x11) {
    bVar4 = 0;
    if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
      if (param_3 != 0) {
        do {
          uVar1 = SdbusReadRegisterUchar(param_1,(ushort)bVar4 + (short)uVar5);
          uVar3 = (ulonglong)bVar4;
          bVar4 = bVar4 + 1;
          *(char *)(uVar3 + (longlong)param_4) = (char)uVar1;
        } while (bVar4 < param_3);
      }
    }
    else {
      if (param_3 >> 2 != 0) {
        do {
          uVar2 = SdbusReadRegisterUlong(param_1,(bVar4 + 4) * 4);
          uVar3 = (ulonglong)bVar4;
          bVar4 = bVar4 + 1;
          *(undefined4 *)((longlong)local_58 + uVar3 * 4) = uVar2;
        } while ((uint)bVar4 < param_3 >> 2);
      }
      if (((*(uint *)(param_1 + 0x20) & 0x1000000) == 0) || (*(int *)(param_2 + 0x10) != 4)) {
        _Src = (undefined4 *)local_58;
      }
      else {
        _Src = (undefined4 *)((longlong)local_58 + 1);
        param_3 = param_3 - 1;
      }
      memcpy(param_4,_Src,(ulonglong)param_3);
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== SdhcInitializeCard @ 140004ba0 =====

void SdhcInitializeCard(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"sdhc - SdhcInitializeCard",param_3,param_4);
  return;
}



===== SdhcInitializeController @ 140004bd0 =====

void SdhcInitializeController
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 local_res8 [4];
  
  SdbusDebugPrint(0x4000,"sdhc - SdhcInitializeController",param_3,param_4);
  if (*(char *)(param_1 + 0x45) == '\x02') {
    local_res8[0] = 0;
    GetPciConfigSpace(param_1,0x10,local_res8,4);
    lVar1 = MmMapIoSpaceEx(local_res8[0],0x80,0x204);
    if (lVar1 != 0) {
      *(uint *)(lVar1 + 0x4c) = *(uint *)(lVar1 + 0x4c) | 0x41;
      LOCK();
      UNLOCK();
      MmUnmapIoSpace(lVar1,0x80);
    }
  }
  return;
}



===== SdhcInitializeFunction @ 140004c60 =====

void SdhcInitializeFunction
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"sdhc - SdhcInitializeFunction(%d)",(ulonglong)*(byte *)(param_2 + 0xc4),
                  param_4);
  return;
}



===== SdhcInitializePciConfigSpace @ 140004c90 =====

void SdhcInitializePciConfigSpace(longlong param_1)

{
  longlong lVar1;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x4c) + -0x11d0b510c8ebdfb0;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x54) + 0x1cbdda365fff1a80;
  }
  if ((lVar1 == 0) && (*(short *)(param_1 + 0x3c) == 0x1217)) {
    GetPciConfigSpace(param_1,0xd0,local_res8,4);
    local_res8[0] = local_res8[0] & 0x7fffffff;
    SetPciConfigSpace(param_1,0xd0,local_res8);
    GetPciConfigSpace(param_1,0xf8,local_res8,4);
    local_res8[0] = local_res8[0] | 0x80000000;
    SetPciConfigSpace(param_1,0xf8,local_res8);
    GetPciConfigSpace(param_1,0xf0,local_res8,4);
    local_res8[0] = local_res8[0] & 0xfe1fffff;
    SetPciConfigSpace(param_1,0xf0,local_res8);
    GetPciConfigSpace(param_1,0x60,local_res8,4);
    local_res8[0] = local_res8[0] & 0xffffdfff | 0x1000;
    SetPciConfigSpace(param_1,0x60,local_res8);
    GetPciConfigSpace(param_1,0xe8,local_res8,4);
    local_res8[0] = local_res8[0] | 0x100000;
    SetPciConfigSpace(param_1,0xe8,local_res8);
    GetPciConfigSpace(param_1,0x74,local_res8,4);
    local_res8[0] = local_res8[0] | 0x7800;
    SetPciConfigSpace(param_1,0x74,local_res8);
    GetPciConfigSpace(param_1,0xd0,local_res8,4);
    local_res8[0] = local_res8[0] | 0x80000000;
    SetPciConfigSpace(param_1,0xd0,local_res8);
  }
  return;
}



===== SdhcInitializeSignaling @ 140004e00 =====

undefined8 SdhcInitializeSignaling(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ushort uVar2;
  
  if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') {
    uVar2 = 0x10c;
    uVar1 = SdbusReadRegisterUlong(param_2,0x10c);
    SdbusWriteRegisterUlong(param_2,uVar2,uVar1 & 0xfffffffd);
  }
  return 0;
}



===== SdhcInitializeSocket @ 140004e40 =====

void SdhcInitializeSocket(ulonglong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  uint *puVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  char *pcVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  ushort local_res8 [4];
  
  local_res8[0] = 0;
  SdbusDebugPrint(0x4000,"sdhc - SdhcInitializeSocket",param_3,param_4);
  uVar11 = 3;
  if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x03') {
    uVar4 = SdbusReadRegisterUlong(param_1,0x3028);
    SdbusDebugPrint(0x4000,"sdhc - SdhcInitializeSocket: Global value 0x%x",(ulonglong)uVar4,param_4
                   );
  }
  uVar4 = SdbusReadRegisterUshort(param_1,0xfe);
  lVar9 = *(longlong *)(param_1 + 8);
  if (*(char *)(lVar9 + 0x45) == '\n') {
    bVar3 = (byte)(uVar4 >> 8);
    if (0x48 < bVar3) {
      *(undefined1 *)(lVar9 + 0x46) = 1;
      lVar9 = *(longlong *)(param_1 + 8);
    }
    if (0x6b < bVar3) {
      *(undefined1 *)(lVar9 + 0x46) = 2;
      lVar9 = *(longlong *)(param_1 + 8);
    }
    if (0x71 < bVar3) {
      *(undefined1 *)(lVar9 + 0x46) = 3;
    }
  }
  uVar12 = (ulonglong)(uVar4 & 0xff);
  *(char *)(param_1 + 0x1154) = (char)uVar4;
  SdbusDebugPrint(0x4000,"sdhc - controller version=%d",uVar12,param_4);
  lVar9 = *(longlong *)(param_1 + 8);
  if ((*(longlong *)(lVar9 + 0x4c) == 0x4942001ad7b46895) &&
     (*(longlong *)(lVar9 + 0x54) == 0x43a81066d4a71f89)) {
    if (*(char *)(lVar9 + 0x45) == '\x04') {
      uVar4 = SdbusReadRegisterUlong(param_1,0x40);
      iVar5 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 0x228));
      if (iVar5 == 0x4809c100) {
        puVar1 = (uint *)(*(longlong *)(param_1 + 8) + 0x38);
        *puVar1 = *puVar1 | 8;
        uVar4 = uVar4 | 0x6000000;
      }
      else {
        uVar4 = uVar4 & 0xfdffffff | 0x4000000;
      }
      uVar12 = (ulonglong)(uVar4 & 0xfeffffff);
    }
    else {
      if (*(char *)(lVar9 + 0x45) != '\x05') goto LAB_140004fd9;
      iVar5 = MmGetPhysicalAddress(*(undefined8 *)(param_1 + 0x218));
      if (((iVar5 == 0x4809c000) || (iVar5 == 0x480b4000)) ||
         (uVar12 = 0x4000000, iVar5 == 0x480d5000)) {
        uVar12 = 0x6000000;
      }
      if ((iVar5 == 0x4809c000) || (iVar5 == 0x480b4000)) {
        uVar12 = (ulonglong)((uint)uVar12 | 0x40000);
      }
    }
    SdbusWriteRegisterUlong(param_1,0x40,(int)uVar12);
  }
LAB_140004fd9:
  uVar6 = SdbusReadRegisterUlong(param_1,0x40);
  *(undefined4 *)(param_1 + 0x1750) = uVar6;
  uVar6 = SdbusReadRegisterUlong(param_1,0x44);
  *(undefined4 *)(param_1 + 0x1754) = uVar6;
  *(undefined2 *)(param_1 + 0x1148) = 0xffff;
  *(short *)(param_1 + 0x1146) = 0x200 << ((byte)(*(uint *)(param_1 + 0x1750) >> 0x10) & 3);
  *(uint *)(param_1 + 0x114c) = (uint)*(byte *)(param_1 + 0x1751) * 1000;
  if ((*(uint *)(param_1 + 0x1750) >> 0x16 & 1) != 0) {
    SdbusDebugPrint(0x4000,"sdhc - Support DMA",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1125) = 1;
  }
  if ((*(uint *)(param_1 + 0x1750) >> 0x13 & 1) == 0) {
    uVar11 = 1;
  }
  else {
    SdbusDebugPrint(0x4000,"sdhc - Support ADMA2",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1126) = 1;
  }
  *(undefined4 *)(param_1 + 0x1150) = uVar11;
  uVar4 = *(uint *)(param_1 + 0x1750);
  if ((uVar4 >> 0x1c & 1) != 0) {
    SdbusDebugPrint(0x4000,"sdhc - Support 64 bit bus",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1127) = 1;
    uVar4 = *(uint *)(param_1 + 0x1750);
    if ((uVar4 >> 0x13 & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1150) = 7;
    }
  }
  if ((uVar4 >> 0x12 & 1) != 0) {
    SdbusDebugPrint(0x4000,"sdhc - Support 8 bit bus width",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1128) = 1;
  }
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x05') &&
     (*(longlong *)(param_1 + 0x1f8) == 0x480b4000)) {
    *(undefined1 *)(param_1 + 0x1128) = 1;
  }
  if ((*(uint *)(param_1 + 0x1750) & 0x200000) != 0) {
    SdbusDebugPrint(0x4000,"sdhc - Support high speed",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1124) = 1;
  }
  if (((*(byte *)(param_1 + 0x1754) & 1) != 0) && ((*(uint *)(param_1 + 0x48) & 0x2000000) == 0)) {
    SdbusDebugPrint(0x4000,"sdhc - Support SDR50",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x1129) = 1;
  }
  if (((*(byte *)(param_1 + 0x1754) & 2) != 0) && ((*(uint *)(param_1 + 0x48) >> 0x18 & 1) == 0)) {
    SdbusDebugPrint(0x4000,"sdhc - Support SDR104",uVar12,param_4);
    lVar9 = *(longlong *)(param_1 + 8);
    *(undefined1 *)(param_1 + 0x112a) = 1;
    if (*(char *)(lVar9 + 0x45) == '\n') {
      *(undefined1 *)(param_1 + 0x112c) = 1;
    }
    if (*(char *)(lVar9 + 0x45) == '\v') {
      *(undefined1 *)(param_1 + 0x112c) = 1;
    }
    if ((*(char *)(lVar9 + 0x45) == '\x06') && (*(char *)(lVar9 + 0x46) == '\x01')) {
      *(undefined1 *)(param_1 + 0x112c) = 1;
    }
  }
  if ((((*(byte *)(param_1 + 0x1754) & 4) != 0) && ((*(uint *)(param_1 + 0x48) >> 0xb & 1) == 0)) ||
     ((*(uint *)(param_1 + 0x48) >> 0x16 & 1) != 0)) {
    SdbusDebugPrint(0x4000,"sdhc - Support DDR50",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x112b) = 1;
  }
  lVar9 = *(longlong *)(param_1 + 8);
  if ((*(char *)(lVar9 + 0x45) - 6U & 0xfb) == 0) {
    *(undefined1 *)(param_1 + 0x113a) = 1;
  }
  if (*(char *)(lVar9 + 0x45) == '\f') {
    *(undefined2 *)(param_1 + 0x112c) = 0x101;
    cVar2 = '\x01';
  }
  else {
    cVar2 = *(char *)(param_1 + 0x112d);
  }
  if ((*(char *)(lVar9 + 0x45) == '\n') && (*(char *)(lVar9 + 0x46) != '\0')) {
    *(undefined1 *)(param_1 + 0x112c) = 1;
    if (cVar2 != '\0') {
      *(undefined4 *)(param_1 + 0x114c) = 400000;
LAB_140005216:
      *(undefined1 *)(param_1 + 0x112c) = 1;
    }
  }
  else if (cVar2 != '\0') goto LAB_140005216;
  if ((*(uint *)(param_1 + 0x1750) & 0x20000000) != 0) {
    *(undefined1 *)(param_1 + 0x1139) = 1;
  }
  uVar4 = *(uint *)(param_1 + 0x1754);
  if ((uVar4 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0x1130) = 1;
  }
  *(undefined1 *)(param_1 + 0x1131) = 1;
  if ((uVar4 & 0x20) != 0) {
    *(undefined1 *)(param_1 + 0x1132) = 1;
  }
  if ((uVar4 >> 0xd & 1) != 0) {
    SdbusDebugPrint(0x4000,"sdhc - Use tuning for SDR50",uVar12,param_4);
    *(undefined1 *)(param_1 + 0x112e) = 1;
  }
  uVar4 = *(uint *)(param_1 + 0x1754);
  uVar8 = uVar4 >> 8 & 0xf;
  if (uVar8 != 0) {
    param_4 = *(longlong *)(param_1 + 8);
    cVar2 = *(char *)(param_4 + 0x45);
    uVar12 = CONCAT71((int7)(uVar12 >> 8),cVar2);
    if (cVar2 == '\n') {
      uVar4 = uVar4 & 0xfffff0ff;
      uVar12 = (ulonglong)uVar4;
      *(uint *)(param_1 + 0x1754) = uVar4;
      SdbusWriteRegisterUlong(param_1,0x40,uVar4);
    }
    else if ((cVar2 == '\x06') && (*(char *)(param_4 + 0x46) == '\x01')) {
      *(uint *)(param_1 + 0x1754) = uVar4 & 0xfffff0ff;
    }
    else {
      *(int *)(param_1 + 0x113c) = 10000000 << ((char)uVar8 - 1U & 0x1f);
    }
  }
  if ((*(uint *)(param_1 + 0x1754) & 0xc000) == 0) {
    uVar12 = param_1;
    SdbusDebugPrint(0x4000,"socket %p - needs software retuning",param_1,param_4);
    *(undefined1 *)(param_1 + 0x112f) = 0;
  }
  uVar7 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
  uVar4 = *(uint *)(param_1 + 0x48) & 0x8000000;
  if ((int)uVar7 == 0) {
    if ((uVar4 == 0) && (*(char *)(param_1 + 0x1154) == '\x02')) {
      *(undefined1 *)(param_1 + 0x1138) = 1;
    }
  }
  else if (((uVar4 == 0) && (*(char *)(param_1 + 0x1154) == '\x02')) &&
          (*(char *)(param_1 + 0x1161) == '\0')) {
    *(undefined1 *)(param_1 + 0x1138) = 1;
  }
  *(undefined4 *)(param_1 + 0x1140) = 0;
  if ((*(uint *)(param_1 + 0x48) & 0x4000) == 0) {
    if ((*(uint *)(param_1 + 0x1750) & 0x4000000) != 0) {
      SdbusDebugPrint(0x4000,"sdhc - Support 1.8v (low voltage)",uVar12,param_4);
      *(uint *)(param_1 + 0x1140) = *(uint *)(param_1 + 0x1140) | 0x80;
    }
    if ((*(uint *)(param_1 + 0x1750) & 0x2000000) != 0) {
      SdbusDebugPrint(0x4000,"sdhc - Support 3.0v",uVar12,param_4);
      *(uint *)(param_1 + 0x1140) = *(uint *)(param_1 + 0x1140) | 0x40000;
    }
    if ((*(uint *)(param_1 + 0x1750) >> 0x18 & 1) == 0) goto LAB_1400053e8;
    pcVar10 = "sdhc - Support 3.3v";
  }
  else {
    SdbusDebugPrint(0x4000,"sdhc - HACKFLAG LIE Support 1.8v (low voltage)",uVar12,param_4);
    *(uint *)(param_1 + 0x1140) = *(uint *)(param_1 + 0x1140) | 0x80;
    SdbusDebugPrint(0x4000,"sdhc - HACKFLAG LIE Support 3.0v",uVar12,param_4);
    *(uint *)(param_1 + 0x1140) = *(uint *)(param_1 + 0x1140) | 0x40000;
    pcVar10 = "sdhc - HACKFLAG LIE Support 3.3v";
  }
  SdbusDebugPrint(0x4000,pcVar10,uVar12,param_4);
  *(uint *)(param_1 + 0x1140) = *(uint *)(param_1 + 0x1140) | 0x200000;
LAB_1400053e8:
  *(ushort *)(param_1 + 0x1144) = (-(ushort)(*(char *)(param_1 + 0x1127) != '\0') & 4) + 8;
  lVar9 = *(longlong *)(param_1 + 8);
  if (*(char *)(lVar9 + 0x45) == '\x01') {
    *(undefined1 *)(param_1 + 0x1125) = 0;
  }
  if (*(char *)(lVar9 + 0x45) == '\v') {
    uVar4 = SdbusAcpiQueryDsmFunctionsSupported(lVar9);
    pcVar10 = "CompatType: %d; _DSM Query: 0x%02X";
    *(uint *)(param_1 + 0x1158) = uVar4;
    uVar7 = (ulonglong)uVar4;
    uVar12 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 8) + 0x45);
    SdbusDebugPrint(0x4000,"CompatType: %d; _DSM Query: 0x%02X",uVar12,uVar7);
    if ((*(uint *)(param_1 + 0x1158) >> 8 & 1) != 0) {
      bVar3 = SdbusAcpiDsmGetHighSpeedCapabilities
                        (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x18));
      pcVar10 = "_DSM High Speed Capabilities: 0x%02X";
      uVar12 = (ulonglong)bVar3;
      SdbusDebugPrint(0x4000,"_DSM High Speed Capabilities: 0x%02X",uVar12,uVar7);
      if ((bVar3 & 1) == 0) {
        *(undefined1 *)(param_1 + 0x1124) = 0;
      }
      if ((bVar3 & 2) == 0) {
        *(undefined1 *)(param_1 + 0x112b) = 0;
      }
      if ((bVar3 & 4) == 0) {
        *(undefined1 *)(param_1 + 0x1129) = 0;
      }
      if ((bVar3 & 8) == 0) {
        *(undefined1 *)(param_1 + 0x112a) = 0;
      }
    }
    if (*(char *)(*(longlong *)(param_1 + 8) + 0x46) == '\x01') {
      if ((*(uint *)(param_1 + 0x1158) >> 6 & 1) != 0) {
        uVar7 = SdbusEvalHostCapabilitiesDsm(param_1,pcVar10,uVar12,6,local_res8);
        if (-1 < (int)uVar7) {
          *(undefined1 *)(param_1 + 0x112d) = 1;
          *(undefined1 *)(param_1 + 0x113a) = 1;
        }
        *(undefined1 *)(param_1 + 0x16a5) = 0;
        if (((*(uint *)(param_1 + 0x1158) >> 9 & 1) != 0) &&
           (uVar12 = SdbusEvalHostCapabilitiesDsm(param_1,pcVar10,uVar12,9,local_res8),
           -1 < (int)uVar12)) {
          *(undefined1 *)(param_1 + 0x16a5) = (undefined1)local_res8[0];
        }
      }
      if ((*(char *)(*(longlong *)(param_1 + 8) + 0x46) == '\x01') &&
         (*(char *)(param_1 + 0x112d) != '\0')) {
        *(undefined1 *)(param_1 + 0x112f) = 0;
      }
    }
  }
  if (SdDisableHS200Support != 0) {
    *(undefined1 *)(param_1 + 0x112c) = 0;
  }
  if (SdDisableHS400Support == 0) {
    if (*(int *)(param_1 + 0x48) < 0) {
      *(undefined2 *)(param_1 + 0x112c) = 0x101;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x112d) = 0;
  }
  *(undefined4 *)(param_1 + 0x1684) = *(undefined4 *)(param_1 + 0x114c);
  return;
}



===== SdhcInitializeSocketDma @ 1400055a0 =====

undefined8
SdhcInitializeSocketDma(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (*(int *)(param_1 + 0x2d0) == 2) {
    if (*(int *)(param_1 + 0x364) != 0) {
      SdbusDebugPrint(1,"SdhcInitializeSocketDma: can\'t handle > 4GB dma physical addresses!",
                      param_3,param_4);
      return 0xc000000d;
    }
    uVar6 = *(uint *)(param_1 + 0x368) >> 1;
    *(uint *)(param_1 + 0x1764) = uVar6;
    uVar1 = *(uint *)(param_1 + 0x360);
    *(ulonglong *)(param_1 + 0x175c) = (ulonglong)((uVar1 - uVar1 % uVar6) + uVar6);
    uVar7 = (ulonglong)*(uint *)(param_1 + 0x175c);
    *(ulonglong *)(param_1 + 0x176c) =
         (ulonglong)(uVar6 - uVar1 % uVar6) + *(longlong *)(param_1 + 0x370);
    SdbusDebugPrint(0x4000,
                    "sdhc - DB DMA: physical=0x%08x, DBDMA physical=0x%08x, DBDMA length=0x%08x",
                    (ulonglong)uVar1,uVar7);
    iVar4 = 0x1000;
    for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
      if (iVar4 == *(int *)(param_1 + 0x1764)) {
        *(ushort *)(param_1 + 0x1774) = uVar2;
        goto LAB_140005665;
      }
      iVar4 = iVar4 * 2;
    }
    if (uVar2 == 8) {
      SdbusDebugPrint(1,"SdhcInitializeSocketDma - Invalid DmaBufferSize: %d",
                      (ulonglong)*(uint *)(param_1 + 0x1764),uVar7);
      return 0xc0000001;
    }
  }
LAB_140005665:
  bVar5 = *(byte *)(param_1 + 0x1758) & 0xe7;
  if (*(int *)(param_1 + 0x2d0) == 3) {
    bVar3 = (-(*(char *)(param_1 + 0x1127) != '\0') & 8U) + 0x10;
    *(byte *)(param_1 + 0x175b) = bVar3;
    bVar5 = bVar5 | bVar3;
  }
  else if (*(int *)(param_1 + 0x2d0) == 2) {
    *(undefined1 *)(param_1 + 0x175b) = 0;
  }
  if (bVar5 != *(byte *)(param_1 + 0x1758)) {
    *(byte *)(param_1 + 0x1758) = bVar5;
    SdbusWriteRegisterUchar(param_1,0x28,bVar5);
  }
  return 0;
}



===== SdhcInitializeTransfer @ 1400056f0 =====

undefined8
SdhcInitializeTransfer
          (longlong param_1,ushort param_2,ushort param_3,int param_4,int param_5,ulonglong param_6,
          longlong param_7,char param_8)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  if (param_4 == 0) {
    param_4 = *(int *)(param_1 + 0x2d0);
  }
  if (param_3 != 0) {
    uVar2 = (uint)param_2 * (uint)param_3;
  }
  if (param_4 == 3) {
    if ((param_7 != 0) && ((param_6 & 7) == 0)) goto LAB_140005755;
    param_4 = 1;
  }
  else if (param_4 != 1) goto LAB_140005755;
  if (param_6 == 0) {
    return 0xc000000d;
  }
LAB_140005755:
  *(undefined4 *)(param_1 + 0x174c) = 0;
  *(int *)(param_1 + 0x17a0) = param_4;
  *(ulonglong *)(param_1 + 0x177c) = param_6;
  *(int *)(param_1 + 0x17a4) = param_5;
  *(char *)(param_1 + 0x17a8) = param_8;
  *(ushort *)(param_1 + 0x179e) = param_3;
  *(ushort *)(param_1 + 0x179c) = param_2;
  *(uint *)(param_1 + 0x1798) = uVar2;
  *(longlong *)(param_1 + 0x1784) = param_7;
  uVar1 = SdhcSetTransferParameters(param_1,param_5,param_2,param_3,param_8,param_4);
  return uVar1;
}



===== SdhcIntelSoftwareRetuning @ 1400057d0 =====

int SdhcIntelSoftwareRetuning
              (undefined4 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  char cVar10;
  char cVar11;
  undefined8 uVar12;
  byte bVar13;
  byte bVar14;
  ulonglong uVar15;
  byte bVar16;
  byte *pbVar17;
  byte bVar18;
  byte local_res10;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  uStack_50 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_54 = 0;
  local_48 = 0;
  uStack_44 = 0;
  RtlInitializeBitMap(&local_48,param_2 + 0x16ac,0x28);
  uVar9 = 0x80;
  uVar12 = 0x80;
  RtlInitializeBitMap(&local_58,param_2 + 0x16b7);
  iVar4 = *(int *)(param_2 + 0x174c);
  if (iVar4 == 0) {
    SdbusDebugPrint(0x4000000,"skt %p: Start retuning procedure",param_2,param_4);
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\v') {
      return -0x3ffffff0;
    }
    RtlSetAllBits(&local_58);
    RtlClearAllBits(&local_48);
    uVar8 = 0x3e;
    uVar5 = SdbusReadRegisterUshort(param_2,0x3e);
    SdbusWriteRegisterUshort(param_2,uVar8,(ushort)uVar5 & 0xff7f);
    *(undefined1 *)(param_2 + 0x1834) = 0;
    *(undefined1 *)(param_2 + 0x17d5) = 0;
    *(undefined4 *)(param_2 + 0x174c) = 1;
  }
  else if (iVar4 != 1) {
    if (iVar4 == 2) {
      pbVar17 = &CmdDescSendTuningBlockMmc;
      if (*(int *)(param_2 + 0x1120) != 3) {
        pbVar17 = &CmdDescSendTuningBlock;
      }
      bVar18 = *(byte *)(param_2 + 0x17d5);
      *(byte *)(param_2 + 0x17d5) = bVar18 + 1;
      lVar2 = *(longlong *)(param_2 + 0x568);
      if (*(int *)(lVar2 + 0x38) == 0) {
        SdbusAddDbgLog(param_2,0x50415353,
                       (longlong)(*(int *)(pbVar17 + 4) << 0x10) | (ulonglong)*pbVar17,
                       (ulonglong)bVar18,0);
        iVar4 = (-(uint)(*(byte *)(param_2 + 0x17d5) < 0x80) & 0xfffffffe) + 3;
LAB_140005a1a:
        *(int *)(param_2 + 0x174c) = iVar4;
        return -0x3fffffea;
      }
      RtlClearBit(&local_58);
      SdhcAcknowledgeEvent(param_2,0xffffffff,uVar12,param_4);
      SdbusWriteRegisterUchar(param_2,0x2f,6);
      SdbusAddDbgLog(param_2,0x4641494c,
                     (longlong)(*(int *)(pbVar17 + 4) << 0x10) | (ulonglong)*pbVar17,
                     (ulonglong)bVar18,(ulonglong)*(uint *)(lVar2 + 0x38));
      *(undefined4 *)(lVar2 + 0x38) = 0;
LAB_140005a6e:
      *(undefined4 *)(param_2 + 0x174c) = 4;
      return -0x3fffffea;
    }
    if (iVar4 == 3) {
      SdbusWriteRegisterUchar(param_2,0x2f,4);
      goto LAB_140005a6e;
    }
    if (iVar4 == 4) {
      uVar5 = SdbusReadRegisterUchar(param_2,0x2f);
      if ((uVar5 & 6) == 0) {
        if (0x7f < *(byte *)(param_2 + 0x17d5)) {
          *(char *)(param_2 + 0x1834) = *(char *)(param_2 + 0x1834) + '\x01';
          *(undefined1 *)(param_2 + 0x17d5) = 0;
        }
        iVar4 = (-(uint)(*(byte *)(param_2 + 0x1834) < 3) & 0xfffffffc) + 5;
        goto LAB_140005a1a;
      }
      *(char *)(param_2 + 0x17d4) = *(char *)(param_2 + 0x17d4) + '\x01';
      if (*(uint *)(param_2 + 0x17c8) < 100) {
        if (*(uint *)(param_2 + 0x17c8) == 1) {
          *(undefined1 *)(param_1 + 3) = 1;
          uVar3 = 0x32;
        }
        else {
          uVar3 = 10000;
        }
        param_1[1] = uVar3;
        return -0x3fffffea;
      }
      iVar4 = -0x3fffff5d;
    }
    else if (iVar4 == 5) {
      *(undefined2 *)(param_2 + 0x16b4) = 0;
      *(undefined1 *)(param_2 + 0x16b6) = 0;
      uVar3 = SdbusReadRegisterUlong(param_2,0x834);
      cVar10 = '\0';
      local_res10 = 0;
      bVar18 = 0;
      cVar11 = '\0';
      bVar13 = (byte)((uint)uVar3 >> 8) & 0x3f;
      uVar15 = (ulonglong)(uint3)((uint)uVar3 >> 8) & 0x3f;
      bVar14 = 0;
      bVar16 = 0;
      do {
        lVar2 = (longlong)uVar15 >> 3;
        if (((bVar18 != 0) ||
            (((*(byte *)(CONCAT44(uStack_4c,uStack_50) + lVar2) >> (uVar15 & 7) & 1) != 0 &&
             (bVar18 = bVar16, bVar16 != 0)))) &&
           ((bVar16 == 0x27 ||
            ((*(byte *)(CONCAT44(uStack_4c,uStack_50) + lVar2) >> (uVar15 & 7) & 1) == 0)))) {
          bVar7 = bVar16;
          if ((*(byte *)(CONCAT44(uStack_4c,uStack_50) + lVar2) >> (uVar15 & 7) & 1) == 0) {
            bVar7 = bVar16 - 1;
          }
          cVar10 = ((byte)(bVar7 - bVar18) >> 1) + bVar18;
          if (cVar11 == '\0') {
            cVar11 = cVar10;
            local_res10 = bVar18;
            bVar14 = bVar7;
          }
          *(byte *)(param_2 + 0x16b5) = bVar18;
          bVar18 = 0;
          *(char *)(param_2 + 0x16b4) = cVar10;
          *(byte *)(param_2 + 0x16b6) = bVar7;
        }
        RtlSetBit(&local_48,bVar16);
        uVar15 = (ulonglong)(byte)((char)uVar15 + 2);
        bVar16 = bVar16 + 1;
      } while (bVar16 < 0x28);
      bVar18 = *(char *)(param_2 + 0x16a7) - cVar11;
      bVar16 = (char)bVar18 >> 7;
      if ((char)((bVar18 ^ bVar16) - bVar16) < '\x03') {
        *(byte *)(param_2 + 0x16b5) = local_res10;
        *(byte *)(param_2 + 0x16b6) = bVar14;
        cVar10 = cVar11;
      }
      *(char *)(param_2 + 0x16b4) = cVar10;
      *(byte *)(param_2 + 0x16a8) = *(char *)(param_2 + 0x16a7) * '\x02' + bVar13;
      *(byte *)(param_2 + 0x16aa) = *(char *)(param_2 + 0x16b5) * '\x02' + bVar13;
      *(byte *)(param_2 + 0x16a9) = cVar10 * '\x02' + bVar13;
      *(byte *)(param_2 + 0x16ab) = *(char *)(param_2 + 0x16b6) * '\x02' + bVar13;
      iVar4 = 0;
    }
    else {
      iVar4 = -0x3fffffff;
    }
    goto LAB_140005c94;
  }
  iVar1 = *(int *)(param_2 + 0x1120);
  uVar12 = 0;
  if (iVar1 != 3) {
    uVar9 = 0x40;
  }
  param_4 = 1;
  uVar6 = SdhcInitializeTransfer(param_2,uVar9,0,1,1,param_2 + 0x1834,0,'\0');
  iVar4 = (int)uVar6;
  if (-1 < iVar4) {
    uVar9 = 0x834;
    uVar5 = SdbusReadRegisterUlong(param_2,0x834);
    SdbusWriteRegisterUlong(param_2,uVar9,(uint)*(byte *)(param_2 + 0x17d5) | uVar5 & 0xffffff80);
    pbVar17 = &CmdDescSendTuningBlockMmc;
    if (iVar1 != 3) {
      pbVar17 = &CmdDescSendTuningBlock;
    }
    param_4 = 0;
    uVar12 = 0;
    uVar6 = SdhcSendCommand(param_2,pbVar17,0,0);
    uVar5 = SdTransferTimeout;
    iVar4 = (int)uVar6;
    if (-1 < iVar4) {
      param_1[1] = 1000;
      param_1[2] = uVar5 / 100;
      *param_1 = 0x20;
      *(undefined4 *)(param_2 + 0x174c) = 2;
      return -0x3fffffea;
    }
  }
  if (iVar4 == -0x3fffffea) {
    return -0x3fffffea;
  }
LAB_140005c94:
  SdhcAcknowledgeEvent(param_2,0xfffffeff,uVar12,param_4);
  *(undefined4 *)(param_2 + 0x174c) = 0;
  *(undefined1 *)(param_2 + 0x17d5) = 0xff;
  *(undefined8 *)(param_2 + 0x3f0) = 0;
  *(undefined1 *)(param_2 + 0x1699) = 1;
  *(int *)(param_2 + 0x169c) = iVar4;
  uVar9 = 0x834;
  uVar5 = SdbusReadRegisterUlong(param_2,0x834);
  SdbusWriteRegisterUlong(param_2,uVar9,(uint)*(byte *)(param_2 + 0x16a8) | uVar5 & 0xffffff80);
  return iVar4;
}



===== SdhcIsWriteProtected @ 140005d10 =====

ulonglong SdhcIsWriteProtected(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x388) == 0) {
    uVar1 = SdbusReadRegisterUlong(param_1,0x24);
    bVar3 = (uVar1 & 0x80000) == 0;
    if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x01') {
      bVar3 = (uVar1 & 0x80000) != 0;
    }
    uVar2 = (ulonglong)bVar3;
    if ((*(uint *)(param_1 + 0x20) & 0x2000000) != 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 8) >> 8),
                     *(undefined1 *)(param_1 + 0x1179));
  }
  return uVar2;
}



===== SdhcNvT40ExecuteRetuning @ 140005d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdhcNvT40ExecuteRetuning
              (undefined8 *param_1,undefined4 *param_2,undefined4 *param_3,ulonglong param_4)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  byte *pbVar12;
  undefined8 uVar13;
  ushort uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  undefined4 *puVar18;
  uint uVar19;
  bool bVar20;
  uint local_res10 [2];
  undefined8 local_res18;
  ulonglong local_res20;
  
  puVar1 = param_2 + 0x5d3;
  uVar19 = param_2[0x7e] + 0x88000000 >> 9;
  uVar16 = (ulonglong)uVar19;
  local_res18 = 0;
  uVar7 = *puVar1;
  local_res10[0] = uVar19;
  if (uVar7 < 6) {
    if (uVar7 == 5) {
LAB_140005e15:
      uVar7 = SdbusReadRegisterUchar((longlong)param_2,0x2f);
      if ((uVar7 & 6) != 0) {
        *(char *)(param_2 + 0x5f5) = *(char *)(param_2 + 0x5f5) + '\x01';
        if ((uint)param_2[0x5f2] < 100) {
          if (param_2[0x5f2] == 1) {
            *(undefined1 *)((longlong)param_1 + 0xc) = 1;
            uVar8 = 0x32;
          }
          else {
            uVar8 = 10000;
          }
          *(undefined4 *)((longlong)param_1 + 4) = uVar8;
          return -0x3fffffea;
        }
        goto LAB_14000673a;
      }
      *puVar1 = 6;
      goto LAB_140005e2e;
    }
    if (uVar7 == 0) {
      uVar13 = 0x4000000;
      puVar18 = param_2;
      SdbusDebugPrint(0x4000000,"skt %p: Start retuning procedure",param_2,param_4);
      LOCK();
      param_2[0xaa8] = param_2[0xaa8] + 1;
      UNLOCK();
      if ((Microsoft_Windows_SdbusEnableBits & 4) != 0) {
        McTemplateK0ix_EtwWriteTransfer
                  (uVar13,&Retune,puVar18,*(undefined8 *)(param_2 + 0x82),(char)param_2[0xaa8]);
      }
      SdbusReadRegisterUshort((longlong)param_2,0x3e);
      SdbusDisableEvents((longlong)param_2,0x107d);
      *(undefined2 *)(param_2 + 0x5f5) = 0xffff;
      param_2[0x608] = 0xffffff;
      *(undefined1 *)(param_2 + 0x609) = 0;
      param_2[0x60c] = 0;
      *puVar1 = 1;
LAB_14000620d:
      KeAcquireSpinLockAtDpcLevel(&NvSdmmcTuningLock);
      bVar20 = true;
      for (uVar7 = 0; uVar7 < 4; uVar7 = uVar7 + 1) {
        if (((uVar7 != uVar19) && (1 < *(uint *)(&NvSdmmcPStateCount + (ulonglong)uVar7 * 4))) &&
           ((&NvSdmmcTuningInProgress)[uVar7] != '\0')) goto LAB_140006291;
      }
      (&NvSdmmcTuningInProgress)[uVar16] = 1;
      for (uVar7 = 0; uVar7 < 4; uVar7 = uVar7 + 1) {
        uVar15 = (ulonglong)uVar7;
        if ((((&NvSdmmcTuningComplete)[uVar15] != '\0') &&
            (*(int *)(&NvSdmmcPStateCurrent + uVar15 * 4) !=
             *(int *)(&NvSdmmcPStateCount + uVar15 * 4) + -1)) &&
           (*(int *)(&NvSdmmcPStateRequested + uVar15 * 4) !=
            *(int *)(&NvSdmmcPStateCount + uVar15 * 4) + -1)) goto LAB_140006291;
      }
      goto LAB_140006294;
    }
    if (uVar7 == 1) goto LAB_14000620d;
    if (uVar7 != 2) {
      if (uVar7 == 3) {
        bVar6 = *(char *)((longlong)param_2 + 0x17d5) + 1;
        *(byte *)((longlong)param_2 + 0x17d5) = bVar6;
        if (*(char *)((longlong)param_2 + 0x1833) != '\0') {
          bVar6 = *(byte *)(param_2 + 0x608);
          *(byte *)((longlong)param_2 + 0x17d5) = bVar6;
        }
        cVar2 = *(char *)((longlong)param_2 + 0x165d);
        pbVar12 = &CmdDescSendTuningBlockMmc;
        if (cVar2 == '\0') {
          pbVar12 = &CmdDescSendTuningBlock;
        }
        SdbusAddDbgLog((longlong)param_2,0x54554e20,
                       (longlong)(*(int *)(pbVar12 + 4) << 0x10) |
                       (ulonglong)(-(uint)(cVar2 != '\0') & 2) + 0x13,(ulonglong)bVar6,
                       (ulonglong)*(byte *)(param_2 + 0x609));
        SdhcSetTransferParameters
                  ((longlong)param_2,1,(-(ushort)(cVar2 != '\0') & 0x40) + 0x40,0,'\0',1);
        uVar7 = KeQueryTimeIncrement();
        lVar3 = _DAT_fffff78000000320;
        local_res20 = 200000 / (ulonglong)uVar7;
        do {
          uVar7 = SdbusReadRegisterUlong((longlong)param_2,0x24);
          lVar5 = _DAT_fffff78000000320;
          if ((longlong)local_res20 < _DAT_fffff78000000320 - lVar3) {
            uVar19 = KeQueryTimeIncrement();
            SdbusAddDbgLog((longlong)param_2,0x45724877,(ulonglong)uVar7,
                           (ulonglong)(uint)((int)lVar5 - (int)lVar3),(ulonglong)uVar19);
            *puVar1 = 8;
            break;
          }
        } while (((uVar7 & 1) != 0) || ((uVar7 & 2) != 0));
        uVar14 = 0x100;
        uVar7 = SdbusReadRegisterUlong((longlong)param_2,0x100);
        SdbusWriteRegisterUlong
                  ((longlong)param_2,uVar14,
                   (uint)*(byte *)((longlong)param_2 + 0x17d5) << 0x10 | uVar7 & 0xff00ffff);
        uVar14 = 0x3e;
        uVar7 = SdbusReadRegisterUshort((longlong)param_2,0x3e);
        SdbusWriteRegisterUshort((longlong)param_2,uVar14,(ushort)uVar7 | 0x40);
        uVar15 = 0;
        uVar16 = 0;
        SdhcSendCommand((longlong)param_2,pbVar12,0,0);
        uVar7 = KeQueryTimeIncrement();
        lVar3 = _DAT_fffff78000000320;
        do {
          uVar10 = SdhcGetPendingEvents((longlong)param_2);
          lVar5 = _DAT_fffff78000000320;
          uVar17 = uVar10 & 0xffffffff;
          if (((uint)uVar10 >> 0xc & 1) != 0) {
            lVar3 = *(longlong *)(param_2 + 0x15a);
            uVar7 = SdhcGetErrorStates((longlong)param_2);
            *(uint *)(lVar3 + 0x38) = uVar7;
            break;
          }
          if ((uVar10 & 0x20) != 0) break;
          if ((longlong)(200000 / (ulonglong)uVar7) < _DAT_fffff78000000320 - lVar3) {
            lVar4 = *(longlong *)(param_2 + 0x15a);
            uVar7 = KeQueryTimeIncrement();
            uVar15 = (ulonglong)(uint)((int)lVar5 - (int)lVar3);
            SdbusAddDbgLog((longlong)param_2,0x45724877,uVar17,uVar15,(ulonglong)uVar7);
            *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x10;
            uVar16 = uVar17;
            break;
          }
        } while ((uVar10 & 0x1020) == 0);
        SdhcAcknowledgeEvent((longlong)param_2,0xfffffeff,uVar16,uVar15);
        uVar16 = (ulonglong)local_res10[0];
        goto LAB_1400060c6;
      }
      if (uVar7 != 4) goto LAB_14000645a;
      SdbusWriteRegisterUchar((longlong)param_2,0x2f,6);
      *(undefined1 *)(param_2 + 0x5f5) = 0;
      *puVar1 = 5;
      goto LAB_140005e15;
    }
    goto LAB_1400062b6;
  }
  if (uVar7 == 6) {
LAB_140005e2e:
    uVar19 = SdbusReadRegisterUshort((longlong)param_2,0x3e);
    lVar3 = *(longlong *)(param_2 + 0x15a);
    uVar7 = *(uint *)(lVar3 + 0x38);
    if (uVar7 == 0) {
      SdbusAddDbgLog((longlong)param_2,0x45724877,(ulonglong)(uVar19 & 0xffff),(ulonglong)param_2,0)
      ;
    }
    else {
      SdbusAddDbgLog((longlong)param_2,0x45724877,(ulonglong)uVar7,(ulonglong)param_2,0);
      *(undefined4 *)(lVar3 + 0x38) = 0;
    }
    (**(code **)(*(longlong *)(*(longlong *)(param_2 + 2) + 0x28) + 0xf8))(param_2,0xffffffff);
    SdbusWriteRegisterUshort((longlong)param_2,0x3e,(ushort)uVar19 & 0xff3f);
    if (*(char *)(param_2 + 0x60c) == '\0') {
      SdbusAddDbgLog((longlong)param_2,0x524554,(ulonglong)*(byte *)((longlong)param_2 + 0x17d5),
                     (ulonglong)*(byte *)(param_2 + 0x609),0);
      *(char *)((longlong)param_2 + 0x17d5) = *(char *)((longlong)param_2 + 0x17d5) + -1;
      *(undefined1 *)(param_2 + 0x60c) = 1;
      goto LAB_1400067e0;
    }
    SdbusDebugPrint(0x4000000,
                    "skt %p: Tuning Failure! TAP_VAL: %3d, Phase: %d, Frequency: %6dkHz, Voltage: %4dmV"
                    ,param_2,(ulonglong)*(byte *)((longlong)param_2 + 0x17d5));
    *(undefined1 *)(param_2 + 0x60c) = 0;
    if ((*(char *)((longlong)param_2 + 0x1821) != -1) &&
       (*(char *)((longlong)param_2 + 0x1832) == '\0')) {
      *(undefined1 *)((longlong)param_2 + 0x1832) = 1;
    }
    if (*(byte *)((longlong)param_2 + 0x1823) == 0) {
LAB_14000688a:
      bVar20 = *(char *)((longlong)param_2 + 0x17d5) == -1;
    }
    else {
      if (*(char *)((longlong)param_2 + 0x1831) != '\0') goto LAB_1400067e0;
      if ((uint)*(byte *)((longlong)param_2 + 0x1823) - (uint)*(byte *)((longlong)param_2 + 0x1822)
          <= SdNvFullWindowMinSize) {
        *(undefined2 *)((longlong)param_2 + 0x1822) = 0xff;
        goto LAB_14000688a;
      }
      *(undefined1 *)((longlong)param_2 + 0x1831) = 1;
      bVar20 = SdNvScanAllTapVal == 0;
    }
    if (bVar20) {
LAB_14000673a:
      *puVar1 = 8;
      return -0x3fffffea;
    }
LAB_1400067e0:
    *puVar1 = 3;
    return -0x3fffffea;
  }
  if (uVar7 == 7) {
LAB_1400060c6:
    uVar7 = SdbusReadRegisterUshort((longlong)param_2,0x3e);
    if ((((byte)uVar7 & 0xc0) != 0x80) || (*(int *)(*(longlong *)(param_2 + 0x15a) + 0x38) != 0)) {
      uVar7 = 4;
      goto LAB_1400063e0;
    }
    *(undefined1 *)(param_2 + 0x60c) = 0;
    if (*(char *)((longlong)param_2 + 0x1833) == '\0') {
      SdbusDebugPrint(0x4000000,
                      "skt %p: Tuning Success! TAP_VAL: %3d, Phase: %d, Frequency: %6dkHz, Voltage: %4dmV"
                      ,param_2,(ulonglong)*(byte *)((longlong)param_2 + 0x17d5));
      bVar6 = *(byte *)((longlong)param_2 + 0x17d5);
      if (*(char *)((longlong)param_2 + 0x1831) == '\0') {
        if (*(char *)((longlong)param_2 + 0x1832) == '\0') {
          *(byte *)((longlong)param_2 + 0x1821) = bVar6;
        }
        else {
          if (bVar6 < *(byte *)((longlong)param_2 + 0x1822)) {
            *(byte *)((longlong)param_2 + 0x1822) = bVar6;
          }
          if ((*(byte *)((longlong)param_2 + 0x1823) < bVar6) &&
             (*(byte *)((longlong)param_2 + 0x1823) = bVar6, bVar6 == 0xff)) {
            *(undefined1 *)((longlong)param_2 + 0x1831) = 1;
            goto LAB_14000673a;
          }
        }
      }
      else if (bVar6 == 0xff) goto LAB_14000673a;
      uVar7 = 3;
      goto LAB_1400063e0;
    }
    SdbusAddDbgLog((longlong)param_2,0x4f5054,0x13,(ulonglong)*(byte *)((longlong)param_2 + 0x17d5),
                   (ulonglong)*(byte *)(param_2 + 0x609));
    param_4 = (ulonglong)*(byte *)((longlong)param_2 + 0x17d5);
    param_3 = param_2;
    SdbusDebugPrint(0x4000000,"skt %p: Optimal Tap Tuning Success! TAP_VAL: %d, Phase: %d",param_2,
                    param_4);
    *param_1 = 0x1000000;
    *(undefined8 *)(*(longlong *)(param_2 + 2) + 0x160) = 0;
    lVar3 = *(longlong *)(param_2 + 2);
    if (*(longlong *)(lVar3 + 0x170) == 0) {
      local_res10[0] = 0;
    }
    else {
      local_res10[0] = *(int *)(lVar3 + 0x16c) - 1;
    }
    iVar9 = SdbusRequestPState(lVar3,(int *)local_res10);
    if (iVar9 == -0x3fffffea) {
      *puVar1 = 9;
      return -0x3fffffea;
    }
    goto LAB_14000645f;
  }
  if (uVar7 != 8) {
    if (uVar7 == 9) {
      iVar9 = 0;
      goto LAB_14000645f;
    }
LAB_14000645a:
    iVar9 = -0x3fffffff;
    goto LAB_14000645f;
  }
  uVar7 = 3;
  *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x609) + 0xe8 + (longlong)puVar1) =
       *(undefined1 *)((longlong)param_2 + 0x1821);
  *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x609) + 0xec + (longlong)puVar1) =
       *(undefined1 *)((longlong)param_2 + 0x1822);
  *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x609) + 0xf0 + (longlong)puVar1) =
       *(undefined1 *)((longlong)param_2 + 0x1823);
  if (*(char *)((longlong)param_2 + 0x1831) == '\0') {
    iVar9 = -0x3fffffff;
LAB_14000656b:
    uVar11 = 1;
  }
  else {
    cVar2 = *(char *)(param_2 + 0x609);
    if ((cVar2 == '\x03') || ((*(char *)((longlong)param_2 + 0x165a) != '\0' && (cVar2 == '\x02'))))
    {
      iVar9 = 0;
      goto LAB_14000656b;
    }
    *puVar1 = 2;
    *(char *)(param_2 + 0x609) = cVar2 + '\x01';
    iVar9 = -0x3fffffea;
    uVar11 = 0;
  }
  param_3 = param_2 + 0x5f7;
  param_4 = 0x20;
  *(undefined1 *)((longlong)param_2 + 0x17e1) = uVar11;
  *(undefined1 *)(param_2 + 0x5f8) = 0;
  *param_3 = 3;
  param_2[0x5fa] = param_2[0x60a];
  param_2[0x5fb] = param_2[0x60b];
  param_2[0x5fc] = (uint)*(byte *)((longlong)param_2 + 0x1821);
  param_2[0x5fd] = (uint)*(byte *)((longlong)param_2 + 0x1822);
  param_2[0x5fe] = (uint)*(byte *)((longlong)param_2 + 0x1823);
  param_2[0x5f9] = (-(uint)(*(char *)((longlong)param_2 + 0x165a) != '\0') & 0xfffe7960) + 200000;
  PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 2) + 0x120),&GUID_NVPEP_SD_POWER_CONTROL,
                   param_3,0x20,param_2 + 0x5ff,0x24,&local_res18);
  if (-1 < iVar9) {
    *(undefined1 *)((longlong)param_2 + 0x1833) = 1;
    uVar8 = SdbusReadRegisterUlong((longlong)param_2,0x100);
    *(char *)(param_2 + 0x608) = (char)((uint)uVar8 >> 0x10);
    goto LAB_1400063e0;
  }
  param_2[0x608] = 0xffffff;
  *(undefined1 *)((longlong)param_2 + 0x17d5) = 0xff;
  *(undefined2 *)((longlong)param_2 + 0x1831) = 0;
  *(undefined1 *)((longlong)param_2 + 0x1833) = 0;
  goto LAB_140006682;
LAB_140006291:
  bVar20 = false;
LAB_140006294:
  KeReleaseSpinLockFromDpcLevel();
  if (!bVar20) {
    *(undefined4 *)((longlong)param_1 + 4) = 100000;
    *puVar1 = 1;
    return -0x3fffffea;
  }
  *puVar1 = 2;
LAB_1400062b6:
  param_3 = param_2 + 0x5f7;
  *(undefined2 *)(param_2 + 0x5f8) = 1;
  uVar7 = 3;
  *param_3 = 3;
  param_2[0x5f9] = (-(uint)(*(char *)((longlong)param_2 + 0x165a) != '\0') & 0xfffe7960) + 200000;
  cVar2 = *(char *)(param_2 + 0x609);
  if (cVar2 == '\0') {
    param_2[0x60a] = 50000;
LAB_140006365:
    param_2[0x60b] = 0x4e2;
  }
  else {
    if (cVar2 == '\x01') {
      param_2[0x60a] = (-(uint)(*(char *)((longlong)param_2 + 0x165d) != '\0') & 50000) + 100000;
      goto LAB_140006365;
    }
    if (cVar2 == '\x02') {
      param_2[0x60b] = 0x44c;
      param_2[0x60a] = (-(uint)(*(char *)((longlong)param_2 + 0x165d) != '\0') & 50000) + 100000;
    }
    else if (cVar2 == '\x03') {
      param_2[0x60a] = 200000;
      goto LAB_140006365;
    }
  }
  param_2[0x5fa] = param_2[0x60a];
  param_2[0x5fb] = param_2[0x60b];
  *param_1 = 0x200000;
  param_4 = 0x20;
  iVar9 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 2) + 0x120),
                           &GUID_NVPEP_SD_POWER_CONTROL,param_3,0x20,param_2 + 0x5ff,0x24,
                           &local_res18);
  if (-1 < iVar9) {
LAB_1400063e0:
    *puVar1 = uVar7;
    return -0x3fffffea;
  }
  *(undefined4 *)param_1 = 0;
LAB_140006682:
  if (iVar9 == -0x3fffffea) {
    return -0x3fffffea;
  }
LAB_14000645f:
  SdhcAcknowledgeEvent((longlong)param_2,0xfffffeff,param_3,param_4);
  SdbusEnableEvents((longlong)param_2,(param_2[8] & 0x200000 | 0x20fa000) >> 0xd);
  *(undefined1 *)((longlong)param_2 + 0x1699) = 1;
  param_2[0x5a7] = param_2[0x5ff];
  if (-1 < (int)param_2[0x5ff]) {
    param_2[0x5a7] = iVar9;
  }
  *puVar1 = 0;
  uVar7 = SdbusReadRegisterUshort((longlong)param_2,0x3e);
  *(short *)((longlong)param_2 + 0x1759) = (short)uVar7;
  (&NvSdmmcTuningInProgress)[uVar16] = 0;
  (&NvSdmmcTuningComplete)[uVar16] = 1;
  return iVar9;
}



===== SdhcNvT40ResetTuningState @ 1400068c0 =====

void SdhcNvT40ResetTuningState(longlong param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = SdbusReadRegisterUlong(param_1,0x100);
  iVar1 = *(int *)(param_1 + 0x1f8);
  uVar2 = uVar2 & 0xff00ffff;
  if ((iVar1 == 0x78000000) || (iVar1 == 0x78000200)) {
    uVar2 = uVar2 | 0x20000;
  }
  else if (iVar1 == 0x78000400) {
    uVar2 = uVar2 | 0x30000;
  }
  else if (iVar1 == 0x78000600) {
    uVar2 = uVar2 | 0x50000;
  }
  SdbusWriteRegisterUlong(param_1,0x100,uVar2);
  return;
}



===== SdhcNvT40SetSavedTapValue @ 140006930 =====

void SdhcNvT40SetSavedTapValue(longlong param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 0x100;
  uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  SdbusWriteRegisterUlong
            (param_1,uVar2,(uint)*(byte *)(param_1 + 0x1820) << 0x10 | uVar1 & 0xff00ffff);
  return;
}



===== SdhcPrepareAdmaTransfer @ 140006970 =====

undefined8 SdhcPrepareAdmaTransfer(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  int local_res10 [6];
  
  local_res10[0] = 0;
  if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x05') {
    *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) =
         *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) | 0x100000;
    LOCK();
    UNLOCK();
  }
  uVar1 = SdhcCreateDescriptorTable(param_2,*(int **)(param_2 + 0x1784),local_res10);
  if (-1 < (int)uVar1) {
    SdbusWriteRegisterUlong(param_2,0x58,*(undefined4 *)(param_2 + 0x360));
    if (*(char *)(param_2 + 0x1127) != '\0') {
      SdbusWriteRegisterUlong(param_2,0x5c,*(undefined4 *)(param_2 + 0x364));
    }
    *(undefined4 *)(param_2 + 0x174c) = 0;
    uVar1 = 0;
  }
  return uVar1;
}



===== SdhcPrepareDmaTransfer @ 140006a10 =====

undefined8 SdhcPrepareDmaTransfer(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x1764);
  if (*(uint *)(param_2 + 0x1798) <= *(uint *)(param_2 + 0x1764)) {
    uVar1 = *(uint *)(param_2 + 0x1798);
  }
  *(uint *)(param_2 + 0x17ac) = uVar1;
  if (*(int *)(param_2 + 0x17a4) == 2) {
    memcpy(*(void **)(param_2 + 0x176c),*(void **)(param_2 + 0x177c),(ulonglong)uVar1);
    DebugDumpBuffer(*(longlong *)(param_2 + 0x177c),0,*(uint *)(param_2 + 0x17ac));
  }
  SdbusWriteRegisterUlong(param_2,0,*(undefined4 *)(param_2 + 0x175c));
  return 0;
}



===== SdhcPreparePioTransfer @ 140006a90 =====

undefined8 SdhcPreparePioTransfer(undefined8 param_1,longlong param_2)

{
  if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x05') {
    *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) =
         *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) & 0xffefffff;
    LOCK();
    UNLOCK();
  }
  return 0;
}



===== SdhcPrepareSystemDmaTransfer @ 140006ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SdhcPrepareSystemDmaTransfer(undefined4 *param_1,longlong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  
  if (*(int *)(param_2 + 0x174c) == 0) {
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x05') {
      *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) =
           *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) & 0xffefffff;
      LOCK();
      UNLOCK();
    }
    if (*(longlong *)(param_2 + 0x308) == 0) {
      *(undefined8 *)(param_2 + 0x17b4) = 0;
      *(undefined4 *)(param_2 + 0x17a0) = 1;
      return 0;
    }
    if ((*(longlong *)(param_2 + 0x2e0) == 0) ||
       (lVar5 = *(longlong *)(param_2 + 0x2e8), lVar5 == 0)) {
      lVar5 = *(longlong *)(param_2 + 0x2d8);
      *(undefined4 *)(param_2 + 0x2f0) = *(undefined4 *)(param_2 + 0x35c);
      *(undefined8 *)(param_2 + 0x178c) = *(undefined8 *)(param_2 + 0x380);
      uVar1 = *(undefined4 *)(param_2 + 0x378);
    }
    else {
      bVar7 = *(int *)(param_2 + 0x17a4) != 1;
      if (bVar7) {
        uVar1 = *(undefined4 *)(param_2 + 0x2f8);
      }
      else {
        uVar1 = *(undefined4 *)(param_2 + 0x2f4);
        lVar5 = *(longlong *)(param_2 + 0x2e0);
      }
      *(undefined4 *)(param_2 + 0x2f0) = uVar1;
      if (bVar7) {
        uVar4 = *(undefined8 *)(param_2 + 0x340);
      }
      else {
        uVar4 = *(undefined8 *)(param_2 + 0x330);
      }
      *(undefined8 *)(param_2 + 0x178c) = uVar4;
      if (bVar7) {
        uVar1 = *(undefined4 *)(param_2 + 0x338);
      }
      else {
        uVar1 = *(undefined4 *)(param_2 + 0x32c);
      }
    }
    *(undefined4 *)(param_2 + 0x1794) = uVar1;
    *(undefined8 *)(param_2 + 0x370) = *(undefined8 *)(param_2 + 0x918);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x1798);
    *(uint *)(param_2 + 0x17ac) = *(uint *)(param_2 + 0x1798);
    lVar6 = (*(longlong *)(param_2 + 0x370) -
            (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x308) + 0x2c)) -
            *(longlong *)(*(longlong *)(param_2 + 0x308) + 0x20);
    *(longlong *)(param_2 + 0x17b4) = lVar6;
    local_24 = 0;
    uStack_1c = 0;
    local_28 = 1;
    (**(code **)(*(longlong *)(lVar5 + 8) + 0x88))
              (lVar5,*(undefined8 *)(param_2 + 0x308),lVar6,uVar3,*(int *)(param_2 + 0x17a4) == 2,
               &local_28);
    if (*(uint *)(param_2 + 0x2f0) < (uint)local_24) {
      *(uint *)(param_2 + 0x17ac) =
           *(uint *)(param_2 + 0x2f0) * 0x1000 - *(int *)(*(longlong *)(param_2 + 0x308) + 0x2c);
    }
    else {
      *(uint *)(param_2 + 0x2f0) = (uint)local_24;
    }
    uVar2 = (**(code **)(*(longlong *)(lVar5 + 8) + 0x90))(lVar5,*(undefined8 *)(param_2 + 0x318));
    if ((int)uVar2 < 0) {
      SdbusDebugPrint(0x4000,
                      "SDHC[%p] SdhcPrepareSystemDmaTransfer: Unable to initialize DMA transfer context"
                      ,param_2,uVar3);
      return (ulonglong)uVar2;
    }
    *(longlong *)(param_2 + 0x2a28) = *(longlong *)(param_2 + 0x2a28) + 1;
    uVar3 = (**(code **)(*(longlong *)(lVar5 + 8) + 0xa0))
                      (lVar5,*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x68),
                       *(undefined8 *)(param_2 + 0x318),*(undefined4 *)(param_2 + 0x2f0),0,
                       PlSystemDmaControl,param_2,0);
    if (-1 < (int)uVar3) {
      param_1[1] = 0;
      *param_1 = 0x20000;
      *(undefined4 *)(param_2 + 0x174c) = 1;
      return 0xc0000016;
    }
    if ((int)uVar3 == -0x3fffffea) {
      return uVar3;
    }
  }
  else if (*(int *)(param_2 + 0x174c) == 1) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000001;
  }
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return uVar3;
}



===== SdhcPrepareTransfer @ 140006d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhcPrepareTransfer(undefined8 param_1,longlong param_2)

{
  (**(code **)(&SdhcTransferHandlers + (ulonglong)*(uint *)(param_2 + 0x17a0) * 0x10))();
  return;
}



===== SdhcQcConfigureDll @ 140006d9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SdhcQcConfigureDll(longlong param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ushort uVar5;
  
  uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  uVar1 = uVar1 & 0xfff9ffff | 0x7090000;
  if (2 < *(byte *)(*(longlong *)(param_1 + 8) + 0x46)) {
    lVar3 = SdhcQcIsCadmusDevice(param_1);
    SdbusWriteRegisterUlong(param_1,0x2e8,(-(uint)((char)lVar3 != '\0') & 0xdcfffec0) + 0x2c010800);
  }
  SdbusWriteRegisterUlong(param_1,0x100,uVar1);
  uVar2 = KeQueryTimeIncrement();
  lVar3 = _DAT_fffff78000000320;
  uVar4 = ((ulonglong)uVar2 + 999999) / (ulonglong)uVar2;
  do {
    if ((longlong)uVar4 < _DAT_fffff78000000320 - lVar3) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x15a,uVar1,param_1,0,0x102);
    }
    uVar5 = 0x100;
    uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  } while ((uVar1 >> 0x12 & 1) != 0);
  uVar1 = uVar1 ^ (param_2 << 0x14 ^ uVar1) & 0xf00000;
  SdbusWriteRegisterUlong(param_1,uVar5,uVar1);
  uVar1 = uVar1 | 0x40000;
  SdbusWriteRegisterUlong(param_1,uVar5,uVar1);
  lVar3 = _DAT_fffff78000000320;
  do {
    if ((longlong)uVar4 < _DAT_fffff78000000320 - lVar3) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x15a,uVar1,param_1,0,0x102);
    }
    uVar5 = 0x100;
    uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  } while ((uVar1 >> 0x12 & 1) == 0);
  SdbusWriteRegisterUlong(param_1,uVar5,uVar1 & 0xfff7ffff);
  if ((*(char *)(param_1 + 0x165e) != '\0') && (*(char *)(param_1 + 0x1699) != '\0')) {
    SdhcQcHS400ConfigureDll(param_1);
  }
  return;
}



===== SdhcQcDisableDll @ 140006f48 =====

void SdhcQcDisableDll(longlong param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 0x100;
  uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1 & 0xfffbffff);
  uVar2 = 0x1b4;
  uVar1 = SdbusReadRegisterUlong(param_1,0x1b4);
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1 | 0x200000);
  uVar2 = 0x100;
  uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1 | 0x40000000);
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1 | 0x60000000);
  uVar2 = 0x10c;
  uVar1 = SdbusReadRegisterUlong(param_1,0x10c);
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1 & 0xffd7ffff | 0x100000);
  if ((*(char *)(param_1 + 0x24) != '\0') ||
     ((*(char *)(param_1 + 0x165e) != '\0' && (*(char *)(param_1 + 0x1699) != '\0')))) {
    SdhcQcSetPwrsaveDll(param_1,'\0');
    uVar2 = 0x100;
    uVar1 = SdbusReadRegisterUlong(param_1,0x100);
    SdbusWriteRegisterUlong(param_1,uVar2,uVar1 & 0xfffffffe);
    uVar2 = 0x1b4;
    uVar1 = SdbusReadRegisterUlong(param_1,0x1b4);
    SdbusWriteRegisterUlong(param_1,uVar2,uVar1 & 0xfffffffe);
  }
  return;
}



===== SdhcQcExecuteRetuning @ 140007050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdhcQcExecuteRetuning
                    (undefined4 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  undefined4 uVar7;
  byte bVar8;
  ushort uVar9;
  int iVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte *pbVar16;
  uint uVar17;
  undefined1 auStackY_98 [32];
  byte local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  puVar1 = (uint *)(param_2 + 0x174c);
  uVar6 = *puVar1;
  uVar17 = 2;
  if (uVar6 < 6) {
    if (uVar6 != 5) {
      if (uVar6 == 0) {
        LOCK();
        *(int *)(param_2 + 0x2aa0) = *(int *)(param_2 + 0x2aa0) + 1;
        UNLOCK();
        if ((Microsoft_Windows_SdbusEnableBits & 4) != 0) {
          McTemplateK0ix_EtwWriteTransfer
                    (param_1,&Retune,param_3,*(undefined8 *)(param_2 + 0x208),
                     (char)*(undefined4 *)(param_2 + 0x2aa0));
        }
        *(undefined8 *)(param_2 + 0x18b5) = 0;
        *(undefined8 *)(param_2 + 0x18bd) = 0;
        *(undefined2 *)(param_2 + 0x18c5) = 0;
        *(undefined1 *)(param_2 + 0x18b4) = 0;
        *(undefined1 *)(param_2 + 0x18c8) = 0;
        *puVar1 = 1;
        if ((*(char *)(param_2 + 0x1699) == '\0') || (*(char *)(param_2 + 0x165e) == '\0'))
        goto LAB_140007212;
        param_4 = 0;
        uVar11 = SdhcSendCommand(param_2,&CmdDescSwitchFunction,0x3b90200,0);
        uVar6 = SdTransferTimeout;
        uVar12 = uVar11 & 0xffffffff;
        if (-1 < (int)uVar11) {
          param_1[1] = 100000;
          param_1[2] = uVar6 / 100;
          *param_1 = 0xc;
          return 0xc0000016;
        }
      }
      else {
        if (uVar6 == 1) {
LAB_140007212:
          SdhcQcSetPwrsave(param_2,'\0');
          SdhcQcInitDll(param_2);
          *(undefined1 *)(param_2 + 0x18c6) = 0;
          *(undefined1 *)(param_2 + 0x18b4) = 0;
          *(undefined1 *)(param_2 + 0x18c8) = 0;
          *puVar1 = 2;
LAB_14000723c:
          bVar5 = *(byte *)(param_2 + 0x18b4);
          iVar10 = -0x3fffffea;
          if (bVar5 == 0x10) {
            bVar5 = *(byte *)(param_2 + 0x18c6);
            if (bVar5 == 0) {
              if (((*(char *)(param_2 + 0x165e) != '\0') || (*(char *)(param_2 + 0x165d) != '\0'))
                 && (*(byte *)(param_2 + 0x16a5) < 4)) {
                bVar5 = *(byte *)(param_2 + 0x16a5) + 1;
                *(byte *)(param_2 + 0x16a5) = bVar5;
                SdhcSendCommand(param_2,&CmdDescMmcSwitch,(uint)bVar5 << 0xc | 0x3b90200,0);
                param_1[1] = 100000;
                *param_1 = 0xc;
                param_1[2] = SdTransferTimeout / 100;
LAB_1400072ce:
                *(undefined1 *)(param_2 + 0x18c6) = 0;
                *(undefined1 *)(param_2 + 0x18b4) = 0;
                *(undefined1 *)(param_2 + 0x18c8) = 0;
                *puVar1 = 2;
                return 0xc0000016;
              }
            }
            else if ((bVar5 == 0x10) && (*(byte *)(param_2 + 0x18c7) < 2)) {
              *(byte *)(param_2 + 0x18c7) = *(byte *)(param_2 + 0x18c7) + 1;
              goto LAB_1400072ce;
            }
            *(undefined1 *)((ulonglong)bVar5 + 0x169 + (longlong)puVar1) =
                 *(undefined1 *)(param_2 + 0x18b5);
            bVar15 = 0;
            bVar5 = *(byte *)(param_2 + 0x18c6);
            bVar13 = 0;
            bVar14 = 0;
            local_58[0] = 0;
            local_58[1] = 0;
            local_58[2] = 0;
            local_58[3] = 0;
            local_58[4] = 0;
            local_58[5] = 0;
            local_58[6] = 0;
            local_58[7] = 0;
            local_58[8] = 0;
            local_58[9] = 0;
            local_58[10] = 0;
            local_58[0xb] = 0;
            local_58[0xc] = 0;
            local_58[0xd] = 0;
            local_58[0xe] = 0;
            local_58[0xf] = 0;
            if (bVar5 == 0) {
              bVar5 = 0xe;
            }
            else {
              pbVar16 = local_58;
              do {
                bVar2 = pbVar16[(longlong)puVar1 + (0x16a - (longlong)local_58)];
                bVar3 = pbVar16[(longlong)puVar1 + (0x169 - (longlong)local_58)];
                bVar8 = (bVar2 - bVar3) - 1;
                *pbVar16 = bVar8;
                if ((char)bVar8 < '\0') {
                  bVar8 = (bVar2 - bVar3) + 0xf;
                  *pbVar16 = bVar8;
                }
                if ((int)(uint)bVar13 < (int)(char)bVar8) {
                  bVar13 = bVar8;
                  bVar15 = bVar14;
                }
                bVar14 = bVar14 + 1;
                pbVar16 = pbVar16 + 1;
              } while (bVar14 < bVar5);
              bVar5 = (char)((longlong)(((char)local_58[bVar15] + 1) * 3) / 4) +
                      *(char *)((ulonglong)bVar15 + 0x169 + (longlong)puVar1) & 0xf;
            }
            *(byte *)(param_2 + 0x18b4) = bVar5;
            iVar10 = 0;
          }
          SdhcQcConfigureDll(param_2,(uint)(byte)(&DAT_140023cd8)[bVar5]);
          uVar6 = SdTransferTimeout;
          if (-1 < iVar10) {
            param_1[1] = 100000;
            param_1[2] = uVar6 / 100;
            *param_1 = 0;
            *puVar1 = 10;
            return 0xc0000016;
          }
          *puVar1 = 3;
        }
        else {
          if (uVar6 == 2) goto LAB_14000723c;
          if (uVar6 != 3) {
            if (uVar6 == 4) {
              if (*(int *)(*(longlong *)(param_2 + 0x568) + 0x38) == 0) {
                SdhcReadDataPort(param_2,*(undefined4 **)(param_2 + 0x177c),
                                 (ulonglong)*(uint *)(param_2 + 0x1798));
                uVar6 = SdTransferTimeout;
                param_1[1] = 100000;
                param_1[2] = uVar6 / 100;
                *param_1 = 8;
              }
              else {
                *(undefined4 *)(*(longlong *)(param_2 + 0x568) + 0x38) = 0;
                (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0xf8))
                          (param_2,0xffffffff);
                *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x18c6) + 0x169 + (longlong)puVar1) =
                     *(undefined1 *)(param_2 + 0x18b4);
                *(char *)(param_2 + 0x18c6) = *(char *)(param_2 + 0x18c6) + '\x01';
                *(char *)(param_2 + 0x18b4) = *(char *)(param_2 + 0x18b4) + '\x01';
                *(undefined1 *)(param_2 + 0x18c8) = 1;
                *(undefined1 *)(param_2 + 0x17d4) = 0;
              }
              *puVar1 = 5;
              return 0xc0000016;
            }
            goto LAB_140007547;
          }
        }
        if ((*(char *)(param_2 + 0x165e) == '\0') && (*(char *)(param_2 + 0x165d) == '\0')) {
          uVar11 = 0x40;
          pbVar16 = &CmdDescSendTuningBlock;
          uVar12 = 0x13;
        }
        else {
          uVar11 = 0x80;
          pbVar16 = &CmdDescSendTuningBlockMmc;
          uVar12 = 0x15;
        }
        SdbusAddDbgLog(param_2,0x54554e20,(longlong)(*(int *)(pbVar16 + 4) << 0x10) | uVar12,
                       (ulonglong)*(byte *)(param_2 + 0x18b4),uVar11);
        param_4 = 1;
        uVar11 = SdhcInitializeTransfer(param_2,(ushort)uVar11,0,1,1,param_2 + 0x1834,0,'\0');
        uVar12 = uVar11 & 0xffffffff;
        if (-1 < (int)uVar11) {
          param_4 = 0;
          uVar11 = SdhcSendCommand(param_2,pbVar16,0,0);
          uVar6 = SdCommandTimeout;
          uVar12 = uVar11 & 0xffffffff;
          if (-1 < (int)uVar11) {
            param_1[1] = 100000;
            param_1[2] = uVar6 / 100;
            *param_1 = 0x24;
            *puVar1 = 4;
            return 0xc0000016;
          }
        }
      }
      if ((int)uVar12 == -0x3fffffea) {
        return uVar12;
      }
      goto LAB_1400076b7;
    }
    param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),2);
    SdbusWriteRegisterUchar(param_2,0x2f,2);
    *(undefined1 *)(param_2 + 0x17d4) = 0;
    *puVar1 = 6;
LAB_1400074ea:
    uVar6 = SdbusReadRegisterUchar(param_2,0x2f);
    if ((uVar6 & 2) == 0) {
      *puVar1 = 7;
LAB_14000765a:
      param_3 = CONCAT71((int7)((ulonglong)param_3 >> 8),4);
      SdbusWriteRegisterUchar(param_2,0x2f,4);
      *(undefined1 *)(param_2 + 0x17d4) = 0;
      *puVar1 = 8;
      goto LAB_140007674;
    }
  }
  else {
    if (uVar6 == 6) goto LAB_1400074ea;
    if (uVar6 == 7) goto LAB_14000765a;
    if (uVar6 != 8) {
      if (uVar6 == 9) {
        lVar4 = *(longlong *)(param_2 + 0x568);
        if (*(int *)(lVar4 + 0x38) == 0) {
          if ((*(char *)(param_2 + 0x165e) == '\0') && (*(char *)(param_2 + 0x165d) == '\0')) {
            for (bVar5 = 0; bVar5 < 0x10; bVar5 = bVar5 + 1) {
              if ((&DAT_140023cf0)[bVar5] != *(int *)(param_2 + 0x1834 + (ulonglong)bVar5 * 4))
              goto LAB_140007609;
            }
          }
          else {
            for (bVar5 = 0; bVar5 < 0x20; bVar5 = bVar5 + 1) {
              if ((&DAT_140023d30)[bVar5] != *(int *)(param_2 + 0x1834 + (ulonglong)bVar5 * 4))
              goto LAB_140007609;
            }
          }
        }
        else {
          (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0xf8))(param_2,0xffffffff)
          ;
          *(undefined4 *)(lVar4 + 0x38) = 0;
          *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x18c6) + 0x169 + (longlong)puVar1) =
               *(undefined1 *)(param_2 + 0x18b4);
          *(char *)(param_2 + 0x18c6) = *(char *)(param_2 + 0x18c6) + '\x01';
        }
        goto LAB_14000759b;
      }
      if (uVar6 == 10) {
        uVar12 = 0;
        goto LAB_1400076b7;
      }
LAB_140007547:
      uVar12 = 0xc000000d;
      goto LAB_1400076b7;
    }
LAB_140007674:
    uVar6 = SdbusReadRegisterUchar(param_2,0x2f);
    if ((uVar6 & 4) == 0) {
      SdhcAcknowledgeEvent(param_2,0xfffffeff,param_3,param_4);
      *(undefined8 *)(param_2 + 0x3f0) = 0;
      if (*(char *)(param_2 + 0x18c8) == '\0') {
        uVar17 = 9;
      }
      else {
        *(undefined1 *)(param_2 + 0x18c8) = 0;
      }
      *puVar1 = uVar17;
      uVar7 = *(undefined4 *)(param_2 + 0x1700);
      goto LAB_14000770f;
    }
  }
  *(char *)(param_2 + 0x17d4) = *(char *)(param_2 + 0x17d4) + '\x01';
  if (*(uint *)(param_2 + 0x17c8) < 100) {
    if (*(uint *)(param_2 + 0x17c8) == 1) {
      *(undefined1 *)(param_1 + 3) = 1;
      uVar7 = 0x32;
    }
    else {
      uVar7 = 10000;
    }
LAB_14000770f:
    param_1[1] = uVar7;
    return 0xc0000016;
  }
  uVar12 = 0xc00000a3;
LAB_1400076b7:
  uVar9 = 0x10c;
  uVar6 = SdbusReadRegisterUlong(param_2,0x10c);
  uVar11 = (ulonglong)(uVar6 | 2);
  SdbusWriteRegisterUlong(param_2,uVar9,uVar6 | 2);
  SdhcAcknowledgeEvent(param_2,0xfffffeff,uVar11,param_4);
  *(undefined8 *)(param_2 + 0x3f0) = 0;
  *(undefined1 *)(param_2 + 0x1699) = 1;
  *(int *)(param_2 + 0x169c) = (int)uVar12;
  *(undefined2 *)(param_2 + 0x18c7) = 0;
  *puVar1 = 0;
  return uVar12;
LAB_140007609:
  *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x18c6) + 0x169 + (longlong)puVar1) =
       *(undefined1 *)(param_2 + 0x18b4);
  *(char *)(param_2 + 0x18c6) = *(char *)(param_2 + 0x18c6) + '\x01';
  SdbusAddDbgLog(param_2,0x42414420,(ulonglong)*(byte *)(param_2 + 0x18b4),0,0);
LAB_14000759b:
  *(char *)(param_2 + 0x18b4) = *(char *)(param_2 + 0x18b4) + '\x01';
  *puVar1 = 2;
  return 0xc0000016;
}



===== SdhcQcHS400ConfigureDll @ 140007744 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SdhcQcHS400ConfigureDll(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = 0x100;
  uVar2 = SdbusReadRegisterUlong(param_1,0x100);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar2 | 1);
  SdbusWriteRegisterUlong
            (param_1,0x1b8,
             (-(uint)(*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2) & 0xffffffe0) + 0x80040873);
  uVar4 = 0x1b4;
  uVar2 = SdbusReadRegisterUlong(param_1,0x1b4);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar2 | 1);
  uVar2 = KeQueryTimeIncrement();
  lVar1 = _DAT_fffff78000000320;
  do {
    uVar3 = SdbusReadRegisterUlong(param_1,0x108);
    if ((longlong)(((ulonglong)uVar2 + 999999) / (ulonglong)uVar2) < _DAT_fffff78000000320 - lVar1)
    {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x15a,uVar3,param_1,0,0x102);
    }
  } while ((uVar3 & 1) == 0);
  return;
}



===== SdhcQcInitDll @ 140007838 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SdhcQcInitDll(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = 0x100;
  uVar1 = SdbusReadRegisterUlong(param_1,0x100);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar1 | 0x40000000);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar1 | 0x60000000);
  uVar1 = uVar1 | 0x67000000;
  SdbusWriteRegisterUlong(param_1,uVar4,uVar1);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar1 & 0xbfffffff);
  uVar5 = uVar1 & 0x9fffffff;
  SdbusWriteRegisterUlong(param_1,uVar4,uVar5);
  if (2 < *(byte *)(*(longlong *)(param_1 + 8) + 0x46)) {
    lVar3 = SdhcQcIsCadmusDevice(param_1);
    SdbusWriteRegisterUlong(param_1,0x2e8,(-(uint)((char)lVar3 != '\0') & 0xdcfffec0) + 0x2c010800);
  }
  uVar4 = 0x100;
  SdbusWriteRegisterUlong(param_1,0x100,uVar5 | 0x10000);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar5 | 0x50000);
  uVar1 = uVar1 & 0x9ffdffff | 0x50000;
  SdbusWriteRegisterUlong(param_1,uVar4,uVar1);
  lVar3 = SdhcQcIsCadmusDevice(param_1);
  if ((char)lVar3 != '\0') {
    uVar4 = 0x1b4;
    uVar5 = SdbusReadRegisterUlong(param_1,0x1b4);
    uVar5 = uVar5 & 0xfffc03ff;
    if ((*(char *)(param_1 + 0x165a) == '\0') || (*(char *)(param_1 + 0x112e) == '\0')) {
      if (*(char *)(param_1 + 0x1659) != '\0') {
        uVar5 = uVar5 | 0xa800;
      }
    }
    else {
      uVar5 = uVar5 | 0x5400;
    }
    SdbusWriteRegisterUlong(param_1,uVar4,uVar5 & 0xfff7ffff);
    if (2 < *(byte *)(*(longlong *)(param_1 + 8) + 0x46)) {
      uVar4 = 600;
      uVar5 = SdbusReadRegisterUlong(param_1,600);
      if ((*(char *)(param_1 + 0x165a) == '\0') || (*(char *)(param_1 + 0x112e) == '\0')) {
        if (*(char *)(param_1 + 0x1659) != '\0') {
          uVar5 = uVar5 | 0x10;
        }
      }
      else {
        uVar5 = uVar5 | 8;
      }
      SdbusWriteRegisterUlong(param_1,uVar4,uVar5);
    }
  }
  uVar4 = 0x1b4;
  uVar5 = SdbusReadRegisterUlong(param_1,0x1b4);
  SdbusWriteRegisterUlong(param_1,uVar4,uVar5 & 0xffdfffff);
  uVar5 = KeQueryTimeIncrement();
  lVar3 = _DAT_fffff78000000320;
  while (((*(char *)(param_1 + 0x16e8) == '\0' || (*(int *)(param_1 + 0x117c) == 0)) ||
         (_DAT_fffff78000000320 - lVar3 <=
          (longlong)(((ulonglong)uVar5 + 999999) / (ulonglong)uVar5)))) {
    uVar2 = SdbusReadRegisterUlong(param_1,0x108);
    if ((char)uVar2 < '\0') {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x15a,uVar1,param_1,0,0x102);
}



===== SdhcQcInitializeSdcdc @ 140007a70 =====

void SdhcQcInitializeSdcdc(longlong param_1)

{
  if (((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
      (((*(char *)(param_1 + 0x165e) != '\0' || (*(char *)(param_1 + 0x165d) != '\0')) ||
       (*(char *)(param_1 + 0x1659) != '\0')))) &&
     ((99999 < *(uint *)(param_1 + 0x1684) && (*(char *)(param_1 + 0x16a6) != '\0')))) {
    SdhcQcSetPwrsave(param_1,'\0');
    SdhcQcInitDll(param_1);
    SdhcQcConfigureDll(param_1,(uint)(byte)(&DAT_140023cd8)[*(byte *)(param_1 + 0x18b4)]);
    SdhcQcSetPwrsave(param_1,'\x01');
  }
  return;
}



===== SdhcQcIsCadmusDevice @ 140007af4 =====

longlong SdhcQcIsCadmusDevice(longlong param_1)

{
  int iVar1;
  uint7 uVar2;
  
  iVar1 = *(int *)(*(longlong *)(param_1 + 8) + 0x48);
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 8) >> 8);
  if ((iVar1 == 0x88) || (iVar1 == 0x9a)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}



===== SdhcQcSetPwrsave @ 140007b1c =====

void SdhcQcSetPwrsave(longlong param_1,char param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = 0x10c;
  uVar1 = SdbusReadRegisterUlong(param_1,0x10c);
  uVar3 = uVar1 | 2;
  if (param_2 == '\0') {
    uVar3 = uVar1 & 0xfffffffd;
  }
  SdbusWriteRegisterUlong(param_1,uVar2,uVar3);
  SdhcQcSetPwrsaveDll(param_1,param_2);
  return;
}



===== SdhcQcSetPwrsaveDll @ 140007b6c =====

void SdhcQcSetPwrsaveDll(longlong param_1,char param_2)

{
  undefined4 uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  
  if (((*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2) &&
      (((uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0x8b0),
        (byte)((uint)uVar1 >> 0x1c) != 1 || ((byte)uVar1 < 0x42)) &&
       (*(char *)(param_1 + 0x165e) != '\0')))) && (*(char *)(param_1 + 0x1699) != '\0')) {
    uVar3 = 0x1b0;
    uVar2 = SdbusReadRegisterUlong(param_1,0x1b0);
    uVar4 = uVar2 | 8;
    if (param_2 == '\0') {
      uVar4 = uVar2 & 0xfffffff7;
    }
    SdbusWriteRegisterUlong(param_1,uVar3,uVar4);
  }
  return;
}



===== SdhcQueryTransferMode @ 140007bf0 =====

int SdhcQueryTransferMode(longlong param_1,byte param_2,char *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2d0);
  if (iVar2 == 3) {
    iVar1 = *(int *)(param_1 + 0x1150);
    if (((iVar1 == 7) || (iVar1 == 3)) && (((byte)iVar1 & param_2) != 0)) {
      iVar2 = 1;
    }
    else if (*param_3 == '*') {
      iVar2 = 1;
    }
  }
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x05') && (param_4 < 0x100)) {
    iVar2 = 1;
  }
  return iVar2;
}



===== SdhcReadDataPort @ 140007c50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SdhcReadDataPort(longlong param_1,undefined4 *param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  size_t _Size;
  uint uVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 auStack_288 [32];
  char local_268;
  undefined4 local_264;
  undefined4 *local_260;
  undefined4 local_248 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_288;
  lVar3 = *(longlong *)(param_1 + 0x228);
  puVar8 = (undefined4 *)(lVar3 + 0x20);
  _Size = param_3 & 0xffffffff;
  uVar5 = (uint)param_3;
  if ((*(uint *)(param_1 + 0x20) & 0x1000000) == 0) {
    if (3 < uVar5) {
      uVar2 = _Size >> 2;
      puVar9 = param_2;
      do {
        uVar5 = (int)_Size - 4;
        _Size = (size_t)uVar5;
        param_2 = puVar9 + 1;
        puVar7 = puVar8;
        for (lVar4 = 1; lVar4 != 0; lVar4 = lVar4 + -1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        uVar2 = uVar2 - 1;
        puVar9 = param_2;
      } while (uVar2 != 0);
    }
    puVar7 = param_2;
    puVar9 = puVar8;
    if (1 < uVar5) {
      puVar7 = (undefined4 *)((longlong)param_2 + 2);
      uVar5 = uVar5 - 2;
      puVar9 = (undefined4 *)(lVar3 + 0x22);
      for (lVar3 = 1; lVar3 != 0; lVar3 = lVar3 + -1) {
        *(undefined2 *)param_2 = *(undefined2 *)puVar8;
        puVar8 = (undefined4 *)((longlong)puVar8 + 2);
        param_2 = (undefined4 *)((longlong)param_2 + 2);
      }
    }
    if (uVar5 == 0) {
      return;
    }
    for (lVar3 = 1; lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((longlong)puVar9 + 1);
      puVar7 = (undefined4 *)((longlong)puVar7 + 1);
    }
    return;
  }
  local_260 = (undefined4 *)0x0;
  local_264 = 0;
  if (((ulonglong)param_2 & 3) == 0) {
    cVar6 = '\x01';
    local_268 = '\x01';
    puVar9 = param_2;
LAB_140007cd9:
    uVar2 = param_3 >> 2 & 0x3fffffff;
    if ((int)uVar2 == 0) goto LAB_140007d16;
  }
  else {
    cVar6 = '\0';
    local_268 = '\0';
    puVar9 = local_248;
    local_260 = param_2;
    if (uVar5 < 0x201) goto LAB_140007cd9;
    _Size = 0x200;
    uVar2 = 0x80;
  }
  uVar5 = 0;
  puVar7 = puVar9;
  do {
    do {
      uVar1 = SdbusReadRegisterUlong(param_1,0x24);
    } while ((uVar1 >> 0xb & 1) == 0);
    uVar5 = uVar5 + 1;
    *puVar7 = *puVar8;
    puVar7 = puVar7 + 1;
  } while (uVar5 < (uint)uVar2);
  cVar6 = local_268;
LAB_140007d16:
  if ((_Size & 3) != 0) {
    puVar7 = &local_264;
    for (lVar3 = 1; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar7 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 1;
    }
    memcpy(puVar9 + uVar2,&local_264,(ulonglong)((uint)_Size & 3));
  }
  if (cVar6 == '\0') {
    memcpy(local_260,puVar9,_Size);
  }
  return;
}



===== SdhcResetHost @ 140007de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdhcResetHost(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint *puVar10;
  ushort uVar11;
  short sVar12;
  ushort uVar13;
  ulonglong uVar14;
  char cVar15;
  int iVar16;
  uint local_res10 [2];
  
  iVar1 = *(int *)(param_2 + 0x17c4);
  cVar15 = (char)(param_3 & 0xffffffff);
  iVar16 = (int)param_3;
  if (iVar1 == 0) {
    if (((*(uint *)(param_2 + 0x48) & 0x200000) != 0) ||
       (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\a')) {
      uVar3 = SdbusReadRegisterUshort(param_2,0x2c);
      local_res10[0] = CONCAT22(local_res10[0]._2_2_,(short)uVar3);
      if (((byte)uVar3 & 5) != 5) {
        SdhcCalcClockFrequency
                  (param_2,*(uint *)(param_2 + 0x1684),400,(uint *)(param_2 + 0x167c),
                   (short *)local_res10);
        SdbusWriteRegisterUshort(param_2,0x2c,(ushort)local_res10[0] | 1);
        *(undefined1 *)(param_1 + 0xc) = 1;
        *(undefined4 *)(param_1 + 4) = 0x32;
        *(undefined4 *)(param_2 + 0x17c8) = 0;
        *(undefined4 *)(param_2 + 0x17c4) = 5;
        return 0xc0000016;
      }
      *(undefined4 *)(param_2 + 0x17c4) = 1;
    }
  }
  else if (iVar1 != 1) {
    if (iVar1 == 2) {
      if ((*(uint *)(*(longlong *)(param_2 + 0x228) + -0xec) & 1) != 0) {
        *(undefined1 *)(param_1 + 0xc) = 1;
        *(undefined4 *)(param_1 + 4) = 0x32;
        *(undefined4 *)(param_2 + 0x17c8) = 0;
        *(undefined4 *)(param_2 + 0x174c) = 3;
        return 0xc0000016;
      }
      uVar3 = *(int *)(param_2 + 0x17c8) + 1;
      *(uint *)(param_2 + 0x17c8) = uVar3;
    }
    else {
      if (iVar1 == 3) {
        uVar3 = SdbusReadRegisterUchar(param_2,0x2f);
        if ((uVar3 & 7) == 0) {
          *(undefined4 *)(param_2 + 0x17c4) = 4;
          return 0xc0000016;
        }
      }
      else {
        if (iVar1 == 4) {
          SdbusWriteRegisterUchar
                    (param_2,0x2e,(*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') + 0xe);
          if (iVar16 == 0) {
            if ((*(char *)(param_2 + 0xd4) != cVar15) &&
               (lVar9 = *(longlong *)(param_2 + 0x10), lVar9 != 0)) {
              for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x18)) {
                lVar9 = *(longlong *)(lVar9 + 0x40);
                if ((*(int *)(lVar9 + 0x20) == 1) && (*(int *)(lVar9 + 0x38) == 3)) {
                  if (*(char *)(param_2 + 0x16a4) == '\0') {
                    (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0x148))
                              (param_2,param_2 + 0x50);
                  }
                  break;
                }
              }
            }
            uVar4 = 0xffffeff;
            if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) != '\x01') {
              uVar4 = 0xfffffeff;
            }
            SdbusWriteRegisterUlong(param_2,0x34,uVar4);
            SdbusWriteRegisterUshort(param_2,0x30,0xffff);
            if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x04') {
              *(undefined4 *)(*(longlong *)(param_2 + 0x228) + -0xf0) = 9;
              LOCK();
              UNLOCK();
            }
            if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x05') {
              if ((*(uint *)(*(longlong *)(param_2 + 0x228) + -0x1fc) & 1) != 0) {
                *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) =
                     *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) | 0x100000;
                LOCK();
                UNLOCK();
              }
              puVar10 = (uint *)(*(longlong *)(param_2 + 0x228) + -0xf0);
              uVar3 = *puVar10 & 0xfffffcff | 0x301d;
              *puVar10 = uVar3;
              LOCK();
              UNLOCK();
              *(uint *)(param_2 + 0xb4) = uVar3;
              *(uint *)(*(longlong *)(param_2 + 0x228) + -0x1f0) =
                   *(uint *)(*(longlong *)(param_2 + 0x228) + -0x1f0) & 0xffffccfe | 0x3c;
              LOCK();
              UNLOCK();
              if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x05') &&
                 (*(longlong *)(param_2 + 0x1f8) == 0x480d5000)) {
                uVar11 = 0x28;
                uVar3 = SdbusReadRegisterUlong(param_2,0x28);
                SdbusWriteRegisterUlong(param_2,uVar11,uVar3 | 0x1080000);
                *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) | 8;
                *(byte *)(param_2 + 0x7f) = *(byte *)(param_2 + 0x7f) | 1;
                puVar10 = (uint *)(*(longlong *)(param_2 + 0x228) + -0xd4);
                uVar3 = *puVar10 | 0x800;
                *puVar10 = uVar3;
                LOCK();
                UNLOCK();
                *(uint *)(param_2 + 0xb8) = uVar3;
                puVar10 = (uint *)(*(longlong *)(param_2 + 0x228) + -0xf0);
                uVar3 = *puVar10 | 4;
                *puVar10 = uVar3;
                LOCK();
                UNLOCK();
                *(uint *)(param_2 + 0xb4) = uVar3;
              }
            }
            if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\x06') {
              SdbusWriteRegisterUlong(param_2,0x100,*(undefined4 *)(param_2 + 0xb4));
              SdbusWriteRegisterUlong(param_2,0x11c,*(undefined4 *)(param_2 + 0xb8));
              SdbusWriteRegisterUlong(param_2,0x120,*(undefined4 *)(param_2 + 0xbc));
              SdbusWriteRegisterUlong(param_2,0x1e0,*(undefined4 *)(param_2 + 0xc0));
              SdbusWriteRegisterUlong(param_2,0x1e4,*(undefined4 *)(param_2 + 0xc4));
              SdbusWriteRegisterUlong(param_2,0x1e8,*(undefined4 *)(param_2 + 200));
            }
          }
          uVar11 = 0x28;
          uVar3 = SdbusReadRegisterUchar(param_2,0x28);
          bVar2 = (byte)uVar3 & 0xe7 | *(byte *)(param_2 + 0x175b);
          *(byte *)(param_2 + 0x1758) = bVar2;
          SdbusWriteRegisterUchar(param_2,uVar11,bVar2);
          if (((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') &&
              (*(int *)(param_2 + 0x117c) == 3)) && (*(char *)(param_2 + 0x24) != '\0')) {
            uVar4 = 0xa0c;
            if (*(byte *)(*(longlong *)(param_2 + 8) + 0x46) < 2) {
              uVar4 = 0xa1c;
            }
            SdbusWriteRegisterUlong(param_2,0x10c,uVar4);
          }
          uVar8 = 0;
          goto LAB_1400081f6;
        }
        if (iVar1 != 5) {
          uVar8 = 0xc0000001;
          goto LAB_1400081f6;
        }
        SdbusDebugPrint(0x4000,"sdhc - clock is stable, enable clock",param_3,param_4);
        uVar11 = 0x2c;
        uVar3 = SdbusReadRegisterUshort(param_2,0x2c);
        if ((uVar3 & 2) != 0) {
          uVar13 = (ushort)uVar3 | 4;
          uVar14 = (ulonglong)uVar13;
          SdbusWriteRegisterUshort(param_2,uVar11,uVar13);
          SdbusDebugPrint(0x4000,"sdhc - wait for clock to be enabled",uVar14,param_4);
          *(undefined1 *)(param_1 + 0xc) = 1;
          *(undefined4 *)(param_1 + 4) = 0x32;
          *(undefined4 *)(param_2 + 0x17c4) = 1;
          return 0xc0000016;
        }
      }
      uVar3 = *(int *)(param_2 + 0x17c8) + 1;
      *(uint *)(param_2 + 0x17c8) = uVar3;
    }
    if (uVar3 < 100) {
      if (uVar3 == 1) {
        *(undefined1 *)(param_1 + 0xc) = 1;
        uVar4 = 0x32;
      }
      else {
        uVar4 = 10000;
      }
      *(undefined4 *)(param_1 + 4) = uVar4;
      return 0xc0000016;
    }
    uVar8 = 0xc00000a3;
LAB_1400081f6:
    *(undefined4 *)(param_2 + 0x17c4) = 0;
    return uVar8;
  }
  uVar4 = 2;
  if (iVar16 == 0) {
    if ((*(char *)(param_2 + 0xd4) != cVar15) && (lVar9 = *(longlong *)(param_2 + 0x10), lVar9 != 0)
       ) {
      for (; lVar9 != 0; lVar9 = *(longlong *)(lVar9 + 0x18)) {
        lVar9 = *(longlong *)(lVar9 + 0x40);
        if ((*(int *)(lVar9 + 0x20) == 1) && (*(int *)(lVar9 + 0x38) == 3)) {
          (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0x140))
                    (param_2,param_2 + 0x50);
          break;
        }
      }
    }
    cVar15 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
    if ((cVar15 == '\x04') || (cVar15 == '\x05')) {
      *(uint *)(*(longlong *)(param_2 + 0x228) + -0xf0) =
           *(uint *)(*(longlong *)(param_2 + 0x228) + -0xf0) | 2;
    }
    else {
      if (cVar15 == '\x06') {
        uVar7 = SdbusReadRegisterUlong(param_2,0x100);
        *(undefined4 *)(param_2 + 0xb4) = uVar7;
        uVar7 = SdbusReadRegisterUlong(param_2,0x11c);
        *(undefined4 *)(param_2 + 0xb8) = uVar7;
        uVar7 = SdbusReadRegisterUlong(param_2,0x120);
        *(undefined4 *)(param_2 + 0xbc) = uVar7;
        uVar7 = SdbusReadRegisterUlong(param_2,0x1e0);
        *(undefined4 *)(param_2 + 0xc0) = uVar7;
        uVar7 = SdbusReadRegisterUlong(param_2,0x1e4);
        *(undefined4 *)(param_2 + 0xc4) = uVar7;
        uVar7 = SdbusReadRegisterUlong(param_2,0x1e8);
        *(undefined4 *)(param_2 + 200) = uVar7;
        goto LAB_1400084dd;
      }
      if (cVar15 != '\n') {
        bVar2 = 1;
        goto LAB_1400084d0;
      }
      if (*(char *)(*(longlong *)(param_2 + 8) + 0x46) != '\0') {
        SdbusWriteRegisterUshort(param_2,0x2c,0);
        uVar11 = 0x29;
        uVar3 = SdbusReadRegisterUchar(param_2,0x29);
        SdbusWriteRegisterUchar(param_2,uVar11,(byte)uVar3 | 1);
        SdbusWriteRegisterUchar(param_2,0x2f,1);
        SdbusWriteRegisterUlong(param_2,0x1a4,0);
        uVar3 = SdbusReadRegisterUlong(param_2,0x1a0);
        local_res10[0] = uVar3 & 0xc;
        uVar5 = SdbusReadRegisterUlong(param_2,0x1a8);
        sVar12 = 6;
        do {
          SdbusWriteRegisterUlong(param_2,0x1a8,uVar5 | uVar3 | 1);
          uVar6 = SdbusReadRegisterUlong(param_2,0x1a0);
          sVar12 = sVar12 + -1;
          if (sVar12 == 0) break;
        } while ((uVar6 & 0xd) != 0);
        SdbusWriteRegisterUlong(param_2,0x1a4,0xf);
        uVar11 = 0x1ac;
        uVar5 = SdbusReadRegisterUlong(param_2,0x1ac);
        uVar3 = uVar5 | 4;
        if (local_res10[0] == 0) {
          uVar3 = uVar5;
        }
        SdbusWriteRegisterUlong(param_2,uVar11,uVar3 | 1);
        goto LAB_1400084dd;
      }
      SdbusWriteRegisterUchar(param_2,0x2f,1);
      uVar11 = 0x10c;
      uVar5 = SdbusReadRegisterUlong(param_2,0x10c);
      uVar3 = *(uint *)(*(longlong *)(param_2 + 0x228) + -0x818);
      SdbusWriteRegisterUlong(param_2,uVar11,uVar5 | 2);
      do {
      } while ((*(uint *)(*(longlong *)(param_2 + 0x228) + -0x894) & 1) != 0);
      *(uint *)(*(longlong *)(param_2 + 0x228) + -0x818) = uVar3 | 5;
    }
    LOCK();
    UNLOCK();
  }
  else {
    if (iVar16 == 1) {
      bVar2 = 2;
    }
    else {
      if (iVar16 != 2) {
        return 0xc0000001;
      }
      bVar2 = 4;
    }
LAB_1400084d0:
    SdbusWriteRegisterUchar(param_2,0x2f,bVar2);
  }
LAB_1400084dd:
  SdbusDebugPrint(0x4000,"sdhc - SdhcResetHost - reset issued type %d",param_3 & 0xffffffff,param_4)
  ;
  *(undefined1 *)(param_1 + 0xc) = 1;
  *(undefined4 *)(param_1 + 4) = 0x32;
  *(undefined4 *)(param_2 + 0x17c8) = 0;
  if ((1 < (byte)(*(char *)(*(longlong *)(param_2 + 8) + 0x45) - 4U)) || (iVar16 != 0)) {
    uVar4 = 3;
  }
  *(undefined4 *)(param_2 + 0x17c4) = uVar4;
  return 0xc0000016;
}



===== SdhcRestoreContext @ 1400085b0 =====

void SdhcRestoreContext(longlong param_1,char *param_2)

{
  char cVar1;
  
  if (*param_2 == '\0') {
    return;
  }
  if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\x05') {
    SdbusWriteRegisterUlong(param_1,0x40,*(undefined4 *)(param_2 + 0x44));
    SdbusWriteRegisterUlong
              (param_1,0x28,
               (uint)(byte)param_2[0x2d] * 0x100 + (uint)(byte)param_2[0x2f] * 0x1000000 +
               (uint)(byte)param_2[0x2e] * 0x10000 + (uint)(byte)param_2[0x2c]);
    SdbusWriteRegisterUlong(param_1,0x2c,(uint)*(uint3 *)(param_2 + 0x30));
    SdbusWriteRegisterUlong(param_1,0x34,*(undefined4 *)(param_2 + 0x38));
  }
  else {
    *(char *)(param_1 + 0x1758) = param_2[0x2c];
    SdbusWriteRegisterUchar(param_1,0x28,param_2[0x2c]);
    SdbusWriteRegisterUchar(param_1,0x2a,param_2[0x2e]);
    SdbusWriteRegisterUchar(param_1,0x2b,param_2[0x2f]);
  }
  SdbusWriteRegisterUshort(param_1,0x32,0xffff);
  SdbusWriteRegisterUshort(param_1,0x30,0xffff);
  SdbusWriteRegisterUshort(param_1,0x34,*(ushort *)(param_2 + 0x38));
  SdbusWriteRegisterUshort(param_1,0x36,*(ushort *)(param_2 + 0x3a));
  SdbusWriteRegisterUshort(param_1,0x3a,*(ushort *)(param_2 + 0x3e));
  SdbusWriteRegisterUshort(param_1,0x3e,*(ushort *)(param_2 + 0x42));
  cVar1 = *(char *)(*(longlong *)(param_1 + 8) + 0x45);
  if (cVar1 == '\x06') {
    SdbusWriteRegisterUlong(param_1,0x100,*(undefined4 *)(param_2 + 100));
    SdbusWriteRegisterUlong(param_1,0x11c,*(undefined4 *)(param_2 + 0x68));
    SdbusWriteRegisterUlong(param_1,0x120,*(undefined4 *)(param_2 + 0x6c));
    SdbusWriteRegisterUlong(param_1,0x1e0,*(undefined4 *)(param_2 + 0x70));
    SdbusWriteRegisterUlong(param_1,0x1e4,*(undefined4 *)(param_2 + 0x74));
    SdbusWriteRegisterUlong(param_1,0x1e8,*(undefined4 *)(param_2 + 0x78));
  }
  else {
    if (cVar1 == '\x05') {
      *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0xf0) = *(undefined4 *)(param_2 + 100);
      LOCK();
      UNLOCK();
      *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0xd4) = *(undefined4 *)(param_2 + 0x68);
    }
    else {
      if (cVar1 != '\n') goto LAB_1400087dc;
      if (*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2) {
        *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0x820) = *(undefined4 *)(param_2 + 100);
        LOCK();
        UNLOCK();
      }
      *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x104) = *(undefined4 *)(param_2 + 0x6c);
      LOCK();
      UNLOCK();
      *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x10c) = *(undefined4 *)(param_2 + 0x70);
    }
    LOCK();
    UNLOCK();
  }
LAB_1400087dc:
  *param_2 = '\0';
  return;
}



===== SdhcSaveContext @ 140008800 =====

void SdhcSaveContext(longlong param_1,undefined1 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  memset(param_2,0,0x84);
  uVar2 = SdbusReadRegisterUlong(param_1,0);
  *(undefined4 *)(param_2 + 4) = uVar2;
  uVar3 = SdbusReadRegisterUshort(param_1,4);
  *(short *)(param_2 + 8) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,6);
  *(short *)(param_2 + 10) = (short)uVar3;
  uVar2 = SdbusReadRegisterUlong(param_1,8);
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  uVar3 = SdbusReadRegisterUshort(param_1,0xc);
  *(short *)(param_2 + 0x10) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0xe);
  *(short *)(param_2 + 0x12) = (short)uVar3;
  uVar2 = SdbusReadRegisterUlong(param_1,0x10);
  *(undefined4 *)(param_2 + 0x14) = uVar2;
  uVar2 = SdbusReadRegisterUlong(param_1,0x14);
  *(undefined4 *)(param_2 + 0x18) = uVar2;
  uVar2 = SdbusReadRegisterUlong(param_1,0x18);
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  uVar2 = SdbusReadRegisterUlong(param_1,0x1c);
  *(undefined4 *)(param_2 + 0x20) = uVar2;
  uVar2 = SdbusReadRegisterUlong(param_1,0x24);
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  uVar3 = SdbusReadRegisterUchar(param_1,0x28);
  param_2[0x2c] = (char)uVar3;
  uVar3 = SdbusReadRegisterUchar(param_1,0x29);
  param_2[0x2d] = (char)uVar3;
  uVar3 = SdbusReadRegisterUchar(param_1,0x2a);
  param_2[0x2e] = (char)uVar3;
  uVar3 = SdbusReadRegisterUchar(param_1,0x2b);
  param_2[0x2f] = (char)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x2c);
  *(short *)(param_2 + 0x30) = (short)uVar3;
  uVar3 = SdbusReadRegisterUchar(param_1,0x2e);
  param_2[0x32] = (char)uVar3;
  uVar3 = SdbusReadRegisterUchar(param_1,0x2f);
  param_2[0x33] = (char)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x30);
  *(short *)(param_2 + 0x34) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x32);
  *(short *)(param_2 + 0x36) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x34);
  *(short *)(param_2 + 0x38) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x36);
  *(short *)(param_2 + 0x3a) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x38);
  *(short *)(param_2 + 0x3c) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x3a);
  *(short *)(param_2 + 0x3e) = (short)uVar3;
  uVar3 = SdbusReadRegisterUshort(param_1,0x3e);
  *(short *)(param_2 + 0x42) = (short)uVar3;
  uVar2 = SdbusReadRegisterUlong(param_1,0x40);
  *(undefined4 *)(param_2 + 0x44) = uVar2;
  cVar1 = *(char *)(*(longlong *)(param_1 + 8) + 0x45);
  if (cVar1 == '\x06') {
    uVar2 = SdbusReadRegisterUlong(param_1,0x100);
    *(undefined4 *)(param_2 + 100) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x11c);
    *(undefined4 *)(param_2 + 0x68) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x120);
    *(undefined4 *)(param_2 + 0x6c) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x1e0);
    *(undefined4 *)(param_2 + 0x70) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x1e4);
    *(undefined4 *)(param_2 + 0x74) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x1e8);
    *(undefined4 *)(param_2 + 0x78) = uVar2;
  }
  else if (cVar1 == '\x05') {
    *(undefined4 *)(param_2 + 100) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0xf0);
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0xd4);
  }
  else if (cVar1 == '\n') {
    if (*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2) {
      *(undefined4 *)(param_2 + 100) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -0x820);
    }
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x100);
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x104);
    *(undefined4 *)(param_2 + 0x70) = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x10c);
  }
  else if ((cVar1 == '\v') &&
          (((*(char *)(param_1 + 0x112d) != '\0' || (*(char *)(param_1 + 0x112c) != '\0')) ||
           (*(char *)(param_1 + 0x112a) != '\0')))) {
    uVar2 = SdbusReadRegisterUlong(param_1,0x80c);
    *(undefined4 *)(param_2 + 100) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x820);
    *(undefined4 *)(param_2 + 0x68) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x824);
    *(undefined4 *)(param_2 + 0x6c) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x828);
    *(undefined4 *)(param_2 + 0x70) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x82c);
    *(undefined4 *)(param_2 + 0x74) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x830);
    *(undefined4 *)(param_2 + 0x78) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x834);
    *(undefined4 *)(param_2 + 0x7c) = uVar2;
    uVar2 = SdbusReadRegisterUlong(param_1,0x840);
    *(undefined4 *)(param_2 + 0x80) = uVar2;
  }
  *param_2 = 1;
  return;
}



===== SdhcSendCommand @ 140008b80 =====

undefined8 SdhcSendCommand(longlong param_1,byte *param_2,undefined4 param_3,ushort param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  ushort uVar6;
  ushort uVar7;
  
  SdbusWriteRegisterUlong(param_1,8,param_3);
  bVar1 = *param_2;
  iVar3 = *(int *)(param_2 + 0x10);
  uVar7 = (ushort)bVar1 << 8;
  if (iVar3 == 1) goto LAB_140008c17;
  if (iVar3 != 2) {
    if (iVar3 == 3) {
LAB_140008c0d:
      uVar7 = uVar7 | 0x1b;
      goto LAB_140008c17;
    }
    if (iVar3 == 4) {
      uVar7 = uVar7 | 9;
      goto LAB_140008c17;
    }
    if ((iVar3 == 5) || (iVar3 == 6)) {
      uVar7 = uVar7 | 2;
      goto LAB_140008c17;
    }
    if (iVar3 != 7) {
      if (iVar3 == 8) goto LAB_140008c0d;
      if (iVar3 != 9) {
        return 0xc0000001;
      }
    }
  }
  uVar7 = uVar7 | 0x1a;
LAB_140008c17:
  cVar2 = *(char *)(*(longlong *)(param_1 + 8) + 0x45);
  if ((cVar2 == '\f') && (bVar1 == 0x15)) {
    uVar7 = uVar7 & 0xfff7;
  }
  bVar4 = false;
  if (*(int *)(param_2 + 0xc) == 1) {
    *(undefined2 *)(param_1 + 0x23c) = 0;
    uVar6 = 0xc;
    uVar5 = SdbusReadRegisterUshort(param_1,0xc);
    SdbusWriteRegisterUshort(param_1,uVar6,(ushort)uVar5 & 0xfff2);
  }
  else {
    uVar7 = uVar7 | 0x20;
    if (cVar2 == '\n') {
      if ((*(int *)(param_2 + 8) == 1) &&
         ((((*(char *)(param_1 + 0x165e) != '\0' || (*(char *)(param_1 + 0x165d) != '\0')) ||
           (*(char *)(param_1 + 0x1659) != '\0')) &&
          ((*(char *)(param_1 + 0x1699) != '\0' && ((byte)(bVar1 - 0x11) < 2)))))) {
        uVar6 = 0x100;
        uVar5 = SdbusReadRegisterUlong(param_1,0x100);
        SdbusWriteRegisterUlong(param_1,uVar6,uVar5 | 0x20000);
        bVar4 = true;
      }
      if (((*(int *)(param_1 + 0x17a0) == 1) && (*(ushort *)(param_1 + 0x179c) < 0x41)) &&
         (*(ushort *)(param_1 + 0x179e) < 2)) {
        uVar6 = 0x10c;
        uVar5 = SdbusReadRegisterUlong(param_1,0x10c);
        SdbusWriteRegisterUlong(param_1,uVar6,uVar5 | 0x400);
      }
    }
  }
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') && (!bVar4)) {
    uVar6 = 0x100;
    uVar5 = SdbusReadRegisterUlong(param_1,0x100);
    SdbusWriteRegisterUlong(param_1,uVar6,uVar5 & 0xfffdffff);
    uVar6 = 0x10c;
    uVar5 = SdbusReadRegisterUlong(param_1,0x10c);
    SdbusWriteRegisterUlong(param_1,uVar6,uVar5 & 0xfffffbff);
  }
  SdbusDebugPrint(0x4000,"sdhc - skt %p SEND: Cmd%d (0x%04x) arg = 0x%08x",param_1,
                  (ulonglong)*param_2);
  if (((*(uint *)(param_1 + 0x20) & 0x400000) == 0) && (*(short *)(param_1 + 0x23c) == 0)) {
    SdbusWriteRegisterUshort(param_1,0xe,uVar7 | param_4);
  }
  else {
    SdbusWriteRegisterUlong(param_1,0xc,CONCAT22(uVar7 | param_4,*(undefined2 *)(param_1 + 0x23c)));
  }
  return 0;
}



===== SdhcSetBlockGapInterruptRequest @ 140008de0 =====

void SdhcSetBlockGapInterruptRequest(longlong param_1)

{
  SdbusReadRegisterUchar(param_1,0x2a);
  return;
}



===== SdhcSetBusWidth @ 140008e00 =====

void SdhcSetBusWidth(longlong param_1,char param_2)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  byte bVar5;
  
  bVar5 = *(byte *)(param_1 + 0x1758) & 0xdd;
  *(byte *)(param_1 + 0x1758) = bVar5;
  if ((*(uint *)(param_1 + 0x20) & 0x1000000) != 0) {
    lVar1 = *(longlong *)(param_1 + 0x228);
    uVar3 = *(uint *)(lVar1 + -0xd4) & 0xffffffdf;
    if (((param_2 != '\0') && (*(char *)(param_1 + 0x1177) != '\0')) &&
       (*(char *)(param_1 + 0x1128) != '\0')) {
      *(uint *)(lVar1 + -0xd4) = uVar3 | 0x20;
      LOCK();
      UNLOCK();
      SdbusWriteRegisterUchar(param_1,0x28,*(byte *)(param_1 + 0x1758));
      return;
    }
    *(uint *)(lVar1 + -0xd4) = uVar3;
    LOCK();
    UNLOCK();
    bVar5 = *(byte *)(param_1 + 0x1758);
  }
  if (param_2 != '\0') {
    if ((*(char *)(param_1 + 0x1177) == '\0') || (*(char *)(param_1 + 0x1128) == '\0')) {
      bVar5 = bVar5 | 2;
    }
    else {
      bVar5 = bVar5 | 0x20;
    }
    *(byte *)(param_1 + 0x1758) = bVar5;
  }
  SdbusWriteRegisterUchar(param_1,0x28,bVar5);
  if (*(char *)(param_1 + 0x1677) != '\0') {
    uVar4 = 0x3e;
    uVar3 = SdbusReadRegisterUshort(param_1,0x3e);
    uVar2 = (ushort)uVar3 | 0x4000;
    *(ushort *)(param_1 + 0x1759) = uVar2;
    SdbusWriteRegisterUshort(param_1,uVar4,uVar2);
  }
  return;
}



===== SdhcSetBusWidthExplicit @ 140008f00 =====

void SdhcSetBusWidthExplicit(longlong param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x1758) & 0xdd;
  *(byte *)(param_1 + 0x1758) = bVar1;
  if (param_2 == 4) {
    bVar1 = bVar1 | 2;
  }
  else {
    if (param_2 != 8) goto LAB_140008f6b;
    if ((*(uint *)(param_1 + 0x20) & 0x1000000) != 0) {
      if (*(char *)(param_1 + 0x1128) != '\0') {
        *(uint *)(*(longlong *)(param_1 + 0x228) + -0xd4) =
             *(uint *)(*(longlong *)(param_1 + 0x228) + -0xd4) | 0x20;
        LOCK();
        UNLOCK();
      }
      goto LAB_140008f6b;
    }
    if (*(char *)(param_1 + 0x1128) == '\0') goto LAB_140008f6b;
    bVar1 = bVar1 | 0x20;
  }
  *(byte *)(param_1 + 0x1758) = bVar1;
LAB_140008f6b:
  SdbusWriteRegisterUchar(param_1,0x28,*(byte *)(param_1 + 0x1758));
  return;
}



===== SdhcSetClock @ 140008f90 =====

undefined8
SdhcSetClock(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4,uint param_5)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  ushort local_res10 [4];
  
  iVar4 = *(int *)(param_2 + 0x174c);
  uVar8 = param_4 & 0xffffffff;
  local_res10[0] = 0;
  if (iVar4 == 0) {
    SdbusDebugPrint(0x4000,"sdhc - turning off clock",param_3,param_4);
    uVar1 = 0x2c;
    uVar3 = SdbusReadRegisterUshort(param_2,0x2c);
    SdbusWriteRegisterUshort(param_2,uVar1,(ushort)uVar3 & 0xfffa);
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 4) = 0x32;
    *(uint *)(param_2 + 0x174c) = (-(uint)((char)param_3 != '\0') & 0xfffffffe) + 3;
  }
  else {
    uVar3 = (uint)param_4;
    if (iVar4 != 1) {
      if (iVar4 == 2) {
        SdbusDebugPrint(0x4000,"sdhc - clock is stable, enable clock",param_3,param_4);
        iVar4 = 0x2c;
        uVar3 = SdbusReadRegisterUshort(param_2,0x2c);
        if ((uVar3 & 2) != 0) {
          uVar1 = (ushort)uVar3 | 4;
          uVar8 = (ulonglong)uVar1;
          SdbusWriteRegisterUshort(param_2,(ushort)iVar4,uVar1);
          SdbusDebugPrint(0x4000,"sdhc - wait for clock to be enabled",uVar8,param_4);
          if ((((*(char *)(*(longlong *)(param_2 + 8) + 0x45) - 7U & 0xfb) == 0) ||
              (*(int *)(param_2 + 0x117c) != 3)) || (*(char *)(param_2 + 0x16e8) == '\0')) {
            uVar5 = *(undefined4 *)(param_2 + 0x170c);
          }
          else {
            *(undefined1 *)(param_1 + 0xc) = 1;
            uVar5 = 0x32;
          }
          *(undefined4 *)(param_1 + 4) = uVar5;
          *(undefined4 *)(param_2 + 0x174c) = 3;
          return 0xc0000016;
        }
        uVar3 = *(int *)(param_2 + 0x17c8) + 1;
        *(uint *)(param_2 + 0x17c8) = uVar3;
        if (uVar3 < 100) {
          if (uVar3 == iVar4 - 0x2bU) {
            *(char *)(param_1 + 0xc) = (char)(iVar4 - 0x2bU);
            iVar4 = iVar4 + 6;
          }
          else {
            iVar4 = 10000;
          }
          *(int *)(param_1 + 4) = iVar4;
          return 0xc0000016;
        }
        uVar6 = 0xc00000a3;
      }
      else {
        if (iVar4 != 3) {
          return 0xc0000001;
        }
        SdbusDebugPrint(0x4000,"sdhc - clock ready",param_3,param_4);
        if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') {
          if ((*(char *)(param_2 + 0x165e) != '\0') || (*(char *)(param_2 + 0x165d) != '\0')) {
            uVar1 = 0x10c;
            uVar2 = SdbusReadRegisterUlong(param_2,0x10c);
            uVar7 = 0x300;
            if (uVar3 < 0x30d41) {
              uVar7 = 0x200;
            }
            SdbusWriteRegisterUlong(param_2,uVar1,uVar7 | uVar2 & 0xfffffcff);
          }
          if (*(char *)(param_2 + 0x1699) != '\0') {
            if (*(uint *)(param_2 + 0x1684) < 100000) {
              SdhcQcDisableDll(param_2);
            }
            else {
              SdhcQcInitializeSdcdc(param_2);
            }
          }
        }
        uVar6 = 0;
      }
      *(undefined4 *)(param_2 + 0x174c) = 0;
      return uVar6;
    }
    if (((*(char *)(param_2 + 0x24) != '\0') &&
        (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n')) && (uVar3 == 400)) {
      SdhcQcDisableDll(param_2);
    }
    SdhcCalcClockFrequency(param_2,param_5,uVar3,(uint *)(param_2 + 0x167c),(short *)local_res10);
    SdbusWriteRegisterUshort(param_2,0x2c,local_res10[0] | 1);
    lVar9 = param_2;
    SdbusDebugPrint(0x4000,
                    "sdhc - skt %p SdhcSetClock - target=%d, base=%d, actual=%d, divisor=%d, register value=0x%x"
                    ,param_2,uVar8);
    SdbusDebugPrint(0x4000,"sdhc - wait for clock to be stable",lVar9,uVar8);
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 4) = 0x32;
    *(undefined4 *)(param_2 + 0x174c) = 2;
  }
  *(undefined4 *)(param_2 + 0x177c) = 0;
  return 0xc0000016;
}



===== SdhcSetEventMask @ 140009280 =====

void SdhcSetEventMask(longlong param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  SdbusDebugPrint(0x40000,"skt %p SetEventMask:  new=%08x, changed=%08x",param_1,(ulonglong)param_2)
  ;
  if ((param_3 >> 0xc & 1) == 0) goto LAB_1400092e6;
  if ((param_2 >> 0xc & 1) == 0) {
    uVar1 = 0;
LAB_1400092d0:
    SdbusWriteRegisterUshort(param_1,0x3a,uVar1);
  }
  else if (*(char *)(param_1 + 0x24) == '\0') {
    uVar1 = 0xffff;
    goto LAB_1400092d0;
  }
  param_2 = param_2 & 0xffffefff;
  param_3 = param_3 & 0xffffefff;
LAB_1400092e6:
  if ((param_3 >> 8 & 1) != 0) {
    if ((param_2 >> 8 & 1) == 0) {
      uVar2 = 0xfffffeff;
    }
    else {
      uVar2 = 0xffffffff;
    }
    SdbusWriteRegisterUlong(param_1,0x34,uVar2);
  }
  if ((param_3 != 0) && (*(char *)(param_1 + 0x24) == '\0')) {
    uVar1 = SdhcEventMaskToHardwareMask(param_2);
    SdbusWriteRegisterUshort(param_1,0x38,uVar1);
  }
  return;
}



===== SdhcSetHighSpeed @ 140009350 =====

void SdhcSetHighSpeed(longlong param_1,char param_2)

{
  byte bVar1;
  
  if (1 < (byte)(*(char *)(*(longlong *)(param_1 + 8) + 0x45) - 5U)) {
    bVar1 = *(byte *)(param_1 + 0x1758) | 4;
    if (param_2 == '\0') {
      bVar1 = *(byte *)(param_1 + 0x1758) & 0xfb;
    }
    *(byte *)(param_1 + 0x1758) = bVar1;
    SdbusWriteRegisterUchar(param_1,0x28,bVar1);
  }
  return;
}



===== Pl180SetHostAccessMode @ 1400093a0 =====

void Pl180SetHostAccessMode(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1120) = param_2;
  return;
}



===== SdhcSetInterruptAtBlockGap @ 1400093b0 =====

void SdhcSetInterruptAtBlockGap(longlong param_1,char param_2)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  
  if ((*(char *)(param_1 + 0x117a) != '\0') && ((*(byte *)(param_1 + 0x11c9) & 0x10) != 0)) {
    uVar2 = 0x2a;
    uVar1 = SdbusReadRegisterUchar(param_1,0x2a);
    bVar3 = (byte)uVar1 | 8;
    if (param_2 == '\0') {
      bVar3 = (byte)uVar1 & 0xf7;
    }
    SdbusWriteRegisterUchar(param_1,uVar2,bVar3);
  }
  return;
}



===== SdhcSetLed @ 140009400 =====

void SdhcSetLed(longlong param_1,char param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x1758) | 1;
  if (param_2 == '\0') {
    bVar1 = *(byte *)(param_1 + 0x1758) & 0xfe;
  }
  *(byte *)(param_1 + 0x1758) = bVar1;
  SdbusWriteRegisterUchar(param_1,0x28,bVar1);
  return;
}



===== SdhcSetPower @ 140009440 =====

undefined8 SdhcSetPower(longlong param_1,longlong param_2,ulonglong param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  char *pcVar5;
  undefined1 uVar6;
  int iVar7;
  sbyte sVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  
  uVar2 = (uint)param_3;
  uVar9 = 0xc0000001;
  cVar1 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
  uVar11 = 0x32;
  iVar7 = *(int *)(param_2 + 0x174c);
  uVar3 = 5;
  if (cVar1 == '\v') {
    uVar3 = 0x32;
  }
  if (iVar7 == 0) {
    uVar10 = param_3;
    if ((cVar1 == '\n') && (*(int *)(*(longlong *)(param_2 + 0x568) + 0x28) == 4)) {
      uVar4 = 0x10c;
      uVar3 = SdbusReadRegisterUlong(param_2,0x10c);
      uVar10 = (ulonglong)(uVar3 & 0xffff7fff);
      SdbusWriteRegisterUlong(param_2,uVar4,uVar3 & 0xffff7fff);
    }
    if (uVar2 != 0) {
      uVar2 = uVar2 & *(uint *)(param_2 + 0x1140);
      if ((uVar2 & 0x200000) == 0) {
        if ((uVar2 & 0x40000) == 0) {
          if (-1 < (char)uVar2) {
            return 0xc0000001;
          }
          *(undefined1 *)(param_2 + 0x177c) = 10;
          uVar2 = 0xff0000;
          *(undefined4 *)(param_2 + 0x1690) = 0x80;
          sVar8 = 0x10;
        }
        else {
          *(undefined1 *)(param_2 + 0x177c) = 0xc;
          uVar2 = 0xff00;
          *(undefined4 *)(param_2 + 0x1690) = 0x40000;
          sVar8 = 8;
        }
      }
      else {
        *(undefined1 *)(param_2 + 0x177c) = 0xe;
        uVar2 = 0xff;
        *(undefined4 *)(param_2 + 0x1690) = 0x200000;
        sVar8 = 0;
      }
      iVar7 = 0x48;
      uVar3 = SdbusReadRegisterUlong(param_2,0x48);
      iVar7 = iVar7 + -0x47;
      uVar2 = ((uVar3 & uVar2) >> sVar8) << 2;
      uVar6 = (undefined1)iVar7;
      if (uVar2 < 800) {
        if (599 < uVar2) goto LAB_140009793;
        if (399 < uVar2) goto LAB_1400097a2;
        if (uVar2 < 200) goto LAB_1400097b7;
      }
      else {
        *(undefined1 *)(param_2 + 0x1137) = uVar6;
LAB_140009793:
        *(undefined1 *)(param_2 + 0x1136) = uVar6;
LAB_1400097a2:
        *(undefined1 *)(param_2 + 0x1135) = uVar6;
      }
      *(undefined1 *)(param_2 + 0x1134) = uVar6;
LAB_1400097b7:
      SdbusDebugPrint(0x4000,"sdhc - set voltage: reg=%x",(ulonglong)*(byte *)(param_2 + 0x177c),
                      param_4);
      *(undefined4 *)(param_2 + 0x1780) = 0;
      SdbusWriteRegisterUchar(param_2,0x29,*(byte *)(param_2 + 0x177c));
      uVar2 = SdbusReadRegisterUchar(param_2,0x29);
      if (((byte)uVar2 & 0xe) == *(byte *)(param_2 + 0x177c)) {
        iVar7 = 2;
      }
      else {
        *(undefined4 *)(param_1 + 4) = 10000;
      }
      *(int *)(param_2 + 0x174c) = iVar7;
      return 0xc0000016;
    }
    SdbusDebugPrint(0x4000,"sdhc - Power off",uVar10,param_4);
    if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) - 7U & 0xfb) == 0) {
      uVar4 = (short)param_3 + 0x2c;
      uVar2 = SdbusReadRegisterUshort(param_2,uVar4);
      SdbusWriteRegisterUshort(param_2,uVar4,(ushort)uVar2 & 0xfffb);
    }
    SdbusWriteRegisterUchar(param_2,0x29,0);
    *(undefined4 *)(param_2 + 0x44) = 0;
    if (((*(int *)(param_2 + 0x117c) - 1U & 0xfffffffd) != 0) ||
       (*(char *)(param_2 + 0x16e8) == '\0')) {
      uVar11 = *(undefined4 *)(param_2 + 0x1708);
      goto LAB_1400095c9;
    }
  }
  else {
    if (iVar7 == 1) {
      SdbusWriteRegisterUchar(param_2,0x29,*(byte *)(param_2 + 0x177c));
      uVar2 = SdbusReadRegisterUchar(param_2,0x29);
      if (((byte)uVar2 & 0xe) == *(byte *)(param_2 + 0x177c)) {
        SdbusDebugPrint(0x4000,"sdhc - set voltage retried %d times before success",
                        (ulonglong)*(uint *)(param_2 + 0x1780),param_4);
        goto LAB_14000963e;
      }
      uVar2 = *(uint *)(param_2 + 0x1780) + 1;
      *(uint *)(param_2 + 0x1780) = uVar2;
      if (uVar2 < uVar3) {
LAB_1400094e3:
        *(undefined4 *)(param_1 + 4) = 10000;
        return 0xc0000016;
      }
      pcVar5 = "sdhc - failed to set voltage: reg=%x";
LAB_1400094f6:
      SdbusDebugPrint(0x4000,pcVar5,(ulonglong)uVar2,param_4);
      uVar9 = 0xc00000a3;
LAB_14000963e:
      *(undefined4 *)(param_2 + 0x174c) = 0;
      return uVar9;
    }
    if (iVar7 != 2) {
      if (iVar7 != 3) goto LAB_14000963e;
      if (uVar2 != 0) {
        uVar4 = 0x29;
        uVar2 = SdbusReadRegisterUchar(param_2,0x29);
        if (((byte)uVar2 & 0xf) != *(byte *)(param_2 + 0x177c)) {
          uVar2 = *(int *)(param_2 + 0x1780) + 1;
          *(uint *)(param_2 + 0x1780) = uVar2;
          if (uVar2 < uVar3) {
            SdbusWriteRegisterUchar(param_2,uVar4,*(byte *)(param_2 + 0x177c));
            goto LAB_1400094e3;
          }
          pcVar5 = "sdhc - failed to enable bus power: reg=%x";
          goto LAB_1400094f6;
        }
        *(undefined4 *)(param_2 + 0x44) = 1;
      }
      SdbusDebugPrint(0x4000,"sdhc - power stable",param_3,param_4);
      uVar9 = 0;
      goto LAB_14000963e;
    }
    SdbusDebugPrint(0x4000,"sdhc - enable bus power: reg=%x",(ulonglong)*(byte *)(param_2 + 0x177c),
                    param_4);
    *(undefined4 *)(param_2 + 0x1780) = 0;
    *(byte *)(param_2 + 0x177c) = *(byte *)(param_2 + 0x177c) | 1;
    SdbusWriteRegisterUchar(param_2,0x29,*(byte *)(param_2 + 0x177c));
    if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') &&
       (*(byte *)(*(longlong *)(param_2 + 8) + 0x46) < 2)) {
      do {
      } while ((*(uint *)(*(longlong *)(param_2 + 0x228) + -0x894) & 1) != 0);
      *(uint *)(*(longlong *)(param_2 + 0x228) + -0x818) =
           *(uint *)(*(longlong *)(param_2 + 0x228) + -0x818) | 5;
      LOCK();
      UNLOCK();
    }
    if ((*(int *)(param_2 + 0x117c) != 3) || (*(char *)(param_2 + 0x16e8) == '\0')) {
      uVar11 = *(undefined4 *)(param_2 + 0x1704);
      goto LAB_1400095c9;
    }
  }
  *(undefined1 *)(param_1 + 0xc) = 1;
LAB_1400095c9:
  *(undefined4 *)(param_1 + 4) = uVar11;
  *(undefined4 *)(param_2 + 0x174c) = 3;
  return 0xc0000016;
}



===== SdhcSetPresetValue @ 140009840 =====

void SdhcSetPresetValue(longlong param_1,char param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x1759);
  if (param_2 == '\0') {
    if (-1 < (short)uVar1) {
      return;
    }
    uVar1 = uVar1 & 0x7fff;
  }
  else {
    if ((short)uVar1 < 0) {
      return;
    }
    uVar1 = uVar1 | 0x8000;
  }
  *(ushort *)(param_1 + 0x1759) = uVar1;
  SdbusWriteRegisterUshort(param_1,0x3e,uVar1);
  return;
}



===== SdhcSetSignaling @ 140009890 =====

int SdhcSetSignaling(undefined8 *param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  undefined4 uVar9;
  ushort uVar10;
  undefined8 local_res10;
  
  uVar6 = *(uint *)(param_2 + 0x174c);
  local_res10 = 0;
  if (uVar6 < 6) {
    if (uVar6 == 5) {
      *(undefined4 *)(param_2 + 0x1788) = 0;
      *(uint *)(param_2 + 0x178c) = (param_3 != '\0') + 0x14;
      iVar5 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                               &GUID_POWER_CHANGE_P_STATE,(undefined4 *)(param_2 + 0x1788),8,
                               param_2 + 0x177c,0xc,&local_res10);
      if (-1 < iVar5) {
        *param_1 = 0x80000;
        *(undefined4 *)(param_2 + 0x174c) = 6;
        return -0x3fffffea;
      }
    }
    else {
      if (uVar6 == 0) {
        uVar10 = 0x2c;
        uVar6 = SdbusReadRegisterUshort(param_2,0x2c);
        SdbusWriteRegisterUshort(param_2,uVar10,(ushort)uVar6 & 0xfffb);
        uVar9 = 1;
        cVar4 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
        if (((byte)(cVar4 - 6U) < 2) || ((byte)(cVar4 - 10U) < 3)) {
          uVar9 = 2;
        }
        *(undefined4 *)(param_2 + 0x174c) = uVar9;
        *(undefined4 *)((longlong)param_1 + 4) = *(undefined4 *)(param_2 + 0x170c);
        return -0x3fffffea;
      }
      if (uVar6 == 1) {
        uVar6 = SdbusReadRegisterUlong(param_2,0x24);
        if ((uVar6 & 0xf00000) == 0) {
          *(undefined4 *)(param_2 + 0x174c) = 2;
          return -0x3fffffea;
        }
      }
      else {
        if (uVar6 == 2) {
          uVar8 = 0x3e;
          uVar6 = SdbusReadRegisterUshort(param_2,0x3e);
          uVar10 = (ushort)uVar6 | 8;
          if (param_3 == '\0') {
            uVar10 = (ushort)uVar6 & 0xfff7;
          }
          *(ushort *)(param_2 + 0x1759) = uVar10;
          SdbusWriteRegisterUshort(param_2,uVar8,uVar10);
          cVar4 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
          if (cVar4 == '\x06') {
            *(undefined4 *)(param_2 + 0x174c) = 3;
            return -0x3fffffea;
          }
          if (cVar4 == '\n') {
            *(undefined4 *)(param_2 + 0x174c) = 5;
            return -0x3fffffea;
          }
          if (cVar4 == '\v') {
            if (param_3 == '\0') {
              uVar6 = *(uint *)(param_2 + 0x1158) >> 4;
            }
            else {
              uVar6 = *(uint *)(param_2 + 0x1158) >> 3;
            }
            if ((uVar6 & 1) != 0) {
              *(undefined4 *)(param_2 + 0x174c) = 7;
              return -0x3fffffea;
            }
          }
          goto LAB_140009d56;
        }
        if (uVar6 == 3) {
          *(undefined8 *)(param_2 + 0x1784) = 0;
          *(undefined8 *)(param_2 + 0x178c) = 0;
          *(undefined8 *)(param_2 + 0x1794) = 0;
          *(undefined8 *)(param_2 + 0x179c) = 0;
          *(undefined8 *)(param_2 + 0x17a4) = 0;
          *(undefined8 *)(param_2 + 0x17ac) = 0;
          *(undefined8 *)(param_2 + 0x17b4) = 0;
          *(undefined4 *)(param_2 + 0x17bc) = 0;
          *(undefined4 *)(param_2 + 0x177c) = 0;
          *(uint *)(param_2 + 0x1780) = -(uint)(param_3 != '\0') & 2;
          *param_1 = 0x100000;
          iVar5 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                                   &GUID_NVPEP_SD_POWER_CONTROL,(undefined4 *)(param_2 + 0x177c),
                                   0x20,(undefined8 *)(param_2 + 0x179c),0x24,&local_res10);
          if (-1 < iVar5) {
            *(undefined4 *)(param_2 + 0x174c) = 4;
            return -0x3fffffea;
          }
          *(undefined4 *)param_1 = 0;
          goto LAB_140009bcd;
        }
        if (uVar6 == 4) goto LAB_1400098f3;
      }
    }
  }
  else {
    if (uVar6 == 6) {
      if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') {
        uVar10 = 0x10c;
        uVar7 = SdbusReadRegisterUlong(param_2,0x10c);
        uVar6 = uVar7 | 0x18000;
        if (param_3 == '\0') {
          uVar6 = uVar7 & 0xfffe7fff;
        }
        SdbusWriteRegisterUlong(param_2,uVar10,uVar6);
        uVar10 = 0x1ac;
        uVar6 = SdbusReadRegisterUlong(param_2,0x1ac);
        SdbusWriteRegisterUlong(param_2,uVar10,uVar6 | 5);
      }
LAB_140009d56:
      *(undefined4 *)((longlong)param_1 + 4) = 5000;
      *(undefined4 *)(param_2 + 0x174c) = 9;
      return -0x3fffffea;
    }
    if (uVar6 == 7) {
      puVar1 = *(undefined8 **)(param_2 + 0x2a8);
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      *(undefined4 *)(puVar1 + 3) = 0;
      puVar2 = *(undefined4 **)(param_2 + 0x2a8);
      *puVar2 = 0xf6c13ea5;
      puVar2[1] = 0x461f65cd;
      puVar2[2] = 0xf7297aab;
      puVar2[3] = 0x61bdd5e8;
      *(undefined4 *)(*(longlong *)(param_2 + 0x2a8) + 0x18) = 0x100000;
      if (param_3 == '\0') {
        *(undefined4 *)(*(longlong *)(param_2 + 0x2a8) + 0x14) = 4;
      }
      else {
        *(undefined4 *)(*(longlong *)(param_2 + 0x2a8) + 0x14) = 3;
      }
      *(undefined4 *)(*(longlong *)(param_2 + 0x2a8) + 0x10) = 0;
      uVar3 = *(undefined8 *)(param_2 + 0x2a0);
      if ((*(int *)(*(longlong *)(param_2 + 8) + 0x280) == 0) ||
         (cVar4 = IoTryQueueWorkItem(uVar3,SdbusAcpiEvalDsmWorker,1,param_2), cVar4 == '\0')) {
        IoQueueWorkItemEx(uVar3,SdbusAcpiEvalDsmWorker,1,param_2);
      }
      *param_1 = 0x100000;
      *(undefined4 *)(param_2 + 0x174c) = 8;
      return -0x3fffffea;
    }
    if (uVar6 == 8) {
LAB_1400098f3:
      *(undefined4 *)((longlong)param_1 + 4) = 5000;
      *(undefined4 *)(param_2 + 0x174c) = 9;
      return -0x3fffffea;
    }
    if (uVar6 == 9) {
      uVar6 = SdbusReadRegisterUshort(param_2,0x3e);
      if (param_3 == '\0') {
        if ((uVar6 & 8) == 0) goto LAB_140009bf6;
      }
      else if ((uVar6 & 8) != 0) {
LAB_140009bf6:
        uVar10 = 0x2c;
        uVar6 = SdbusReadRegisterUshort(param_2,0x2c);
        SdbusWriteRegisterUshort(param_2,uVar10,uVar10 - 0x28 | (ushort)uVar6);
        *(undefined4 *)((longlong)param_1 + 4) = *(undefined4 *)(param_2 + 0x170c);
        *(undefined4 *)(param_2 + 0x174c) = 10;
        return -0x3fffffea;
      }
    }
    else if (uVar6 == 10) {
      iVar5 = 0;
      cVar4 = *(char *)(*(longlong *)(param_2 + 8) + 0x45);
      if ((1 < (byte)(cVar4 - 6U)) && (1 < (byte)(cVar4 - 0xbU))) {
        uVar6 = SdbusReadRegisterUlong(param_2,0x24);
        iVar5 = 0;
        if ((uVar6 & 0xf00000) != 0xf00000) {
          iVar5 = -0x3fffffff;
        }
      }
      if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\n') {
        uVar10 = 0x10c;
        uVar6 = SdbusReadRegisterUlong(param_2,0x10c);
        SdbusWriteRegisterUlong(param_2,uVar10,uVar6 | 2);
      }
LAB_140009bcd:
      if (iVar5 == -0x3fffffea) {
        return -0x3fffffea;
      }
      goto LAB_140009c35;
    }
  }
  iVar5 = -0x3fffffff;
LAB_140009c35:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return iVar5;
}



===== SdhcSetTransferParameters @ 140009d88 =====

undefined8
SdhcSetTransferParameters
          (longlong param_1,int param_2,ushort param_3,ushort param_4,char param_5,int param_6)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  *(undefined2 *)(param_1 + 0x23c) = 0;
  if ((0x800 < param_3) || (1 < param_2 - 1U)) {
    return 0xc000000d;
  }
  uVar1 = 0;
  if (param_5 == '\0') goto LAB_140009e47;
  if ((*(char *)(param_1 + 0x11bc) == '\0') || (*(int *)(param_1 + 0x1120) == 1)) {
LAB_140009e43:
    uVar1 = 4;
  }
  else if ((*(char *)(param_1 + 0x1138) == '\0') || (param_6 != 3)) {
    if (((*(char *)(param_1 + 0x165e) == '\0') && (*(char *)(param_1 + 0x165d) == '\0')) &&
       (*(char *)(param_1 + 0x1659) == '\0')) goto LAB_140009e43;
  }
  else {
    if (((*(char *)(param_1 + 0x165e) == '\0') && (*(char *)(param_1 + 0x165d) == '\0')) &&
       (*(char *)(param_1 + 0x1659) == '\0')) goto LAB_140009e43;
    uVar1 = 8;
  }
LAB_140009e47:
  if (param_4 == 0) {
    if (((*(uint *)(param_1 + 0x48) & 4) == 0) || (param_6 != 2)) goto LAB_140009e54;
    param_4 = 1;
    uVar1 = uVar1 | 3;
  }
  else {
    uVar1 = uVar1 | 0x22;
LAB_140009e54:
    if (((param_6 != 3) && (uVar2 = 0, param_6 != 2)) && (param_6 != 4)) goto LAB_140009e82;
    uVar2 = 0;
    uVar1 = uVar1 | 1;
    if ((param_6 - 2U & 0xfffffffd) != 0) goto LAB_140009e82;
  }
  uVar2 = *(short *)(param_1 + 0x1774) << 0xc;
LAB_140009e82:
  uVar3 = uVar1 | 0x10;
  if (param_2 != 1) {
    uVar3 = uVar1;
  }
  SdbusWriteRegisterUlong(param_1,0,(uint)param_4);
  SdbusWriteRegisterUshort(param_1,4,uVar2 | param_3);
  SdbusWriteRegisterUshort(param_1,6,param_4);
  if (((*(uint *)(param_1 + 0x20) & 0x400000) == 0) &&
     ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) != '\x06' || ((uVar3 & 8) == 0)))) {
    SdbusWriteRegisterUshort(param_1,0xc,uVar3);
  }
  else {
    *(ushort *)(param_1 + 0x23c) = uVar3;
  }
  return 0;
}



===== SdhcSetUhsMode @ 140009f40 =====

ulonglong SdhcSetUhsMode(longlong param_1,longlong param_2,ushort param_3,char param_4)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort uVar7;
  
  iVar2 = *(int *)(param_2 + 0x174c);
  if (iVar2 == 0) {
    uVar6 = 0;
    uVar5 = SdbusReadRegisterUshort(param_2,0x3e);
    *(ushort *)(param_2 + 0x1759) = (ushort)uVar5;
    if (((ushort)uVar5 & 7) == param_3) goto LAB_140009f94;
    if (param_3 != 0) {
      if (param_3 == 1) {
        if (*(char *)(param_2 + 0x1124) != '\0') goto LAB_14000a382;
        uVar6 = 0xc000000d;
      }
      else {
        if (param_3 == 2) {
          cVar4 = *(char *)(param_2 + 0x1129);
        }
        else if (param_3 == 3) {
          cVar4 = *(char *)(param_2 + 0x112a);
        }
        else {
          uVar6 = 0xc000000d;
          if (param_3 == 4) {
            cVar4 = *(char *)(param_2 + 0x112b);
          }
          else if (param_3 == 5) {
            cVar4 = *(char *)(param_2 + 0x112c);
          }
          else {
            if (param_3 != 6) goto LAB_140009f94;
            cVar4 = *(char *)(param_2 + 0x112d);
          }
        }
        uVar5 = ~-(uint)(cVar4 != '\0') & 0xc000000d;
        uVar6 = (ulonglong)uVar5;
        if (-1 < (int)uVar5) goto LAB_14000a382;
      }
LAB_140009f94:
      *(undefined4 *)(param_2 + 0x174c) = 0;
      goto LAB_140009f9b;
    }
LAB_14000a382:
    if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\f') && (param_3 != 6)) {
      SdhcAmdResetDll(param_2);
    }
    uVar7 = 0x2c;
    uVar5 = SdbusReadRegisterUshort(param_2,0x2c);
    SdbusWriteRegisterUshort(param_2,uVar7,(ushort)uVar5 & 0xfffb);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x170c);
    *(undefined4 *)(param_2 + 0x174c) = 1;
  }
  else if (iVar2 == 1) {
    if ((*(uint *)(param_2 + 0x20) & 0x1000000) == 0) {
      if (6 < param_3) goto LAB_140009f8e;
      plVar1 = (longlong *)(param_2 + 8);
      *(ushort *)(param_2 + 0x1759) = *(ushort *)(param_2 + 0x1759) & 0xfff8;
      *(undefined1 *)(param_2 + 0x16a6) = 1;
      lVar3 = *plVar1;
      if ((param_3 - 3 & 0xfffd) == 0) {
        cVar4 = *(char *)(lVar3 + 0x45);
        if ((((cVar4 == '\x06') || (cVar4 == '\n')) || (cVar4 == '\v')) || (cVar4 == '\f')) {
          param_3 = 3;
        }
        if (cVar4 == '\n') {
          uVar5 = SdbusReadRegisterUlong(param_2,0x10c);
          uVar5 = (-(uint)(*(char *)(param_2 + 0x165e) != '\0') & 0x40000) + 0x200000 |
                  uVar5 & 0xffe7ffff;
          uVar7 = 0x10c;
LAB_14000a250:
          SdbusWriteRegisterUlong(param_2,uVar7,uVar5);
        }
        else if (cVar4 == '\f') {
          *(ushort *)(param_2 + 0x1759) = *(ushort *)(param_2 + 0x1759) | 0x10;
        }
      }
      else if (param_3 == 6) {
        cVar4 = *(char *)(lVar3 + 0x45);
        if (cVar4 == '\n') {
          uVar7 = 0x10c;
          uVar5 = SdbusReadRegisterUlong(param_2,0x10c);
          uVar5 = uVar5 & 0xfff7ffff | 0x340000;
          goto LAB_14000a250;
        }
        if (cVar4 == '\v') {
          param_3 = 5;
        }
        else if (cVar4 == '\f') {
          *(ushort *)(param_2 + 0x1759) = *(ushort *)(param_2 + 0x1759) | 0x10;
          param_3 = 5;
          SdhcSetHighSpeed(param_2,'\x01');
          if (((*(ushort *)(param_2 + 0x1759) & 0x80) == 0) && (*(char *)(param_2 + 0x1699) != '\0')
             ) {
            *(ushort *)(param_2 + 0x1759) = *(ushort *)(param_2 + 0x1759) | 0x80;
          }
        }
      }
      else {
        *(undefined1 *)(param_2 + 0x16a6) = 0;
        if (*(char *)(lVar3 + 0x45) == '\n') {
          if (*(char *)(param_2 + 0x165e) != '\0') {
            uVar7 = 0x10c;
            uVar5 = SdbusReadRegisterUlong(param_2,0x10c);
            SdbusWriteRegisterUlong(param_2,uVar7,uVar5 & 0xffd7ffff | 0x140000);
          }
          SdhcQcDisableDll(param_2);
        }
        else if (*(char *)(lVar3 + 0x45) == '\f') {
          *(ushort *)(param_2 + 0x1759) = *(ushort *)(param_2 + 0x1759) & 0xff6f;
        }
      }
      uVar7 = *(ushort *)(param_2 + 0x1759) & 0xfff8;
      *(ushort *)(param_2 + 0x1759) = uVar7;
      if ((*(char *)(*plVar1 + 0x45) != '\n') || (param_3 != 6)) {
        uVar7 = uVar7 | param_3;
        *(ushort *)(param_2 + 0x1759) = uVar7;
      }
      SdbusWriteRegisterUshort(param_2,0x3e,uVar7);
      if (((*(short *)(*plVar1 + 0x3c) == 0x1217) && (*(int *)(param_2 + 0x1120) == 3)) &&
         (param_3 == 4)) {
        uVar7 = 0x150;
        uVar5 = SdbusReadRegisterUlong(param_2,0x150);
        SdbusWriteRegisterUlong(param_2,uVar7,uVar5 | 0x800);
      }
      *(undefined2 *)(param_2 + 0x92) = *(undefined2 *)(param_2 + 0x1759);
    }
    else if (*(char *)(param_2 + 0x112b) != '\0') {
      *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) =
           *(uint *)(*(longlong *)(param_2 + 0x228) + -0xd4) | 0x80000;
      LOCK();
      UNLOCK();
    }
    *(undefined4 *)(param_2 + 0x174c) = 2;
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        if (((param_4 != '\0') && ((param_3 - 2 & 0xfffc) == 0)) && (param_3 != 4)) {
          SdhcQcInitializeSdcdc(param_2);
        }
        if (((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\f') && (param_3 == 6)) &&
           ((*(char *)(param_2 + 0x165e) != '\0' &&
            ((SdhcAmdResetDll(param_2), *(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\f' &&
             (*(char *)(param_2 + 0x165e) != '\0')))))) {
          SdbusWriteRegisterUshort(param_2,0x90a,0x4003);
          KeStallExecutionProcessor(0x32);
          *(undefined1 *)(param_2 + 0x16a6) = 1;
        }
        uVar6 = 0;
      }
      else {
LAB_140009f8e:
        uVar6 = 0xc0000001;
      }
      goto LAB_140009f94;
    }
    uVar7 = 0x2c;
    uVar5 = SdbusReadRegisterUshort(param_2,0x2c);
    SdbusWriteRegisterUshort(param_2,uVar7,uVar7 - 0x28 | (ushort)uVar5);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x170c);
    *(undefined4 *)(param_2 + 0x174c) = 3;
  }
  uVar6 = 0xc0000016;
LAB_140009f9b:
  return uVar6 & 0xffffffff;
}



===== SdhcStartAdmaTransfer @ 14000a3f0 =====

uint SdhcStartAdmaTransfer(undefined4 *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_2 + 0x174c) == 0) {
    *param_1 = 8;
    uVar1 = *(uint *)(param_2 + 0x1798);
    uVar3 = 0xc0000016;
    uVar2 = SdTransferTimeout / 100;
    uVar4 = 2;
    param_1[1] = 100000;
    param_1[2] = ((uVar1 >> 0x12) + 5) * uVar2;
  }
  else {
    uVar3 = -(uint)(*(int *)(param_2 + 0x174c) != 2) & 0xc0000001;
  }
  *(undefined4 *)(param_2 + 0x174c) = uVar4;
  return uVar3;
}



===== SdhcStartController @ 14000a460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 SdhcStartController(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  byte local_res8 [8];
  
  if (*(int *)(param_1 + 0x3e4) == 0) {
    lVar2 = *(longlong *)(param_1 + 0x4c) + -0x4942001ad7b46895;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0x54) + -0x43a81066d4a71f89;
    }
    if (lVar2 != 0) {
      lVar2 = *(longlong *)(param_1 + 0x4c) + -0x11d0b510c8ebdfb0;
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0x54) + 0x1cbdda365fff1a80;
      }
      if (lVar2 == 0) {
        local_res8[0] = 0;
        GetPciConfigSpace(param_1,0x40,local_res8,1);
        uVar3 = (local_res8[0] >> 4) + 1;
        (**(code **)(*(longlong *)(param_1 + 0x28) + 8))(param_1);
        uVar1 = 0;
        if (uVar3 < 7) {
          uVar1 = uVar3;
        }
        *(uint *)(param_1 + 0x3e4) = uVar1;
        if (uVar1 == 0) {
          return 0xc0000001;
        }
        return 0;
      }
    }
    *(undefined4 *)(param_1 + 0x3e4) = 1;
  }
  return 0;
}



===== SdhcStartDmaTransfer @ 14000a530 =====

undefined8 SdhcStartDmaTransfer(undefined4 *param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  void *_Src;
  uint uVar4;
  
  if (*(int *)(param_2 + 0x174c) == 0) {
    if (*(uint *)(param_2 + 0x17ac) < *(uint *)(param_2 + 0x1798)) {
      *param_1 = 0x40;
    }
    else if ((*(uint *)(param_2 + 0x17ac) < *(uint *)(param_2 + 0x1764)) ||
            ((*(uint *)(param_2 + 0x48) & 2) != 0)) {
      *param_1 = 8;
    }
    else {
      *param_1 = 0x48;
    }
    uVar2 = SdTransferTimeout;
    param_1[1] = 100000;
    param_1[2] = uVar2 / 100;
    *(undefined4 *)(param_2 + 0x174c) = 1;
LAB_14000a66b:
    uVar3 = 0xc0000016;
  }
  else {
    if (*(int *)(param_2 + 0x174c) == 1) {
      puVar1 = (uint *)(param_2 + 0x17ac);
      if (*(int *)(param_2 + 0x17a4) == 1) {
        memcpy(*(void **)(param_2 + 0x177c),*(void **)(param_2 + 0x176c),(ulonglong)*puVar1);
        DebugDumpBuffer(*(longlong *)(param_2 + 0x177c),0,*puVar1);
      }
      uVar4 = *(int *)(param_2 + 0x1798) - *puVar1;
      _Src = (void *)(*(longlong *)(param_2 + 0x177c) + (ulonglong)*puVar1);
      *(uint *)(param_2 + 0x1798) = uVar4;
      *(void **)(param_2 + 0x177c) = _Src;
      uVar2 = *(uint *)(param_2 + 0x1764);
      if (uVar4 <= *(uint *)(param_2 + 0x1764)) {
        uVar2 = uVar4;
      }
      *puVar1 = uVar2;
      if (uVar4 != 0) {
        if (*(int *)(param_2 + 0x17a4) == 2) {
          memcpy(*(void **)(param_2 + 0x176c),_Src,(ulonglong)uVar2);
          DebugDumpBuffer(*(longlong *)(param_2 + 0x177c),0,*puVar1);
        }
        uVar2 = 0;
        SdbusWriteRegisterUlong(param_2,0,*(undefined4 *)(param_2 + 0x175c));
        *(uint *)(param_2 + 0x174c) = *(uint *)(param_2 + 0x174c) & uVar2;
        goto LAB_14000a66b;
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0xc0000001;
    }
    *(undefined4 *)(param_2 + 0x174c) = 0;
  }
  return uVar3;
}



===== SdhcStartPioTransfer @ 14000a690 =====

undefined8
SdhcStartPioTransfer(undefined4 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(param_2 + 0x174c);
  if (iVar1 == 0) {
    uVar3 = 0x10;
    if (*(int *)(param_2 + 0x17a4) != 2) {
      uVar3 = 0x20;
    }
    *param_1 = uVar3;
    uVar2 = SdTransferTimeout;
    param_1[1] = 100000;
    param_1[2] = uVar2 / 100;
    *(undefined4 *)(param_2 + 0x174c) = 1;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0xc0000001;
      }
      *(undefined4 *)(param_2 + 0x174c) = 0;
      return uVar4;
    }
    if (*(int *)(param_2 + 0x17a4) == 1) {
      SdhcReadDataPort(param_2,*(undefined4 **)(param_2 + 0x177c),
                       (ulonglong)(uint)*(ushort *)(param_2 + 0x179c));
    }
    else {
      SdhcWriteDataPort(param_2,*(undefined4 **)(param_2 + 0x177c),
                        (uint)*(ushort *)(param_2 + 0x179c));
    }
    SdbusDebugPrint(0x10000,"skt %p pio transfer: complete one block of data",param_2,param_4);
    DebugDumpBuffer(*(longlong *)(param_2 + 0x177c),0,(uint)*(ushort *)(param_2 + 0x179c));
    uVar2 = SdTransferTimeout;
    if (*(ushort *)(param_2 + 0x179e) < 2) {
      param_1[1] = 100000;
      param_1[2] = uVar2 / 100;
      *param_1 = 8;
      *(undefined4 *)(param_2 + 0x174c) = 2;
    }
    else {
      *(ushort *)(param_2 + 0x179e) = *(ushort *)(param_2 + 0x179e) - 1;
      *(longlong *)(param_2 + 0x177c) =
           *(longlong *)(param_2 + 0x177c) + (ulonglong)*(ushort *)(param_2 + 0x179c);
      uVar3 = 0x10;
      if (*(int *)(param_2 + 0x17a4) != 2) {
        uVar3 = 0x20;
      }
      *param_1 = uVar3;
      uVar2 = SdTransferTimeout;
      param_1[1] = 100000;
      param_1[2] = uVar2 / 100;
    }
  }
  return 0xc0000016;
}



===== SdhcStartSocket @ 14000a800 =====

undefined8 SdhcStartSocket(longlong param_1,longlong param_2)

{
  longlong *_Buf1;
  char cVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  char *pcVar10;
  int iVar11;
  bool bVar12;
  byte local_res8 [8];
  
  lVar3 = *(longlong *)(param_1 + 8);
  local_res8[0] = 0;
  iVar11 = 0;
  _Buf1 = (longlong *)(lVar3 + 0x4c);
  lVar5 = *_Buf1 + -0x11d0b510c8ebdfb0;
  if (lVar5 == 0) {
    lVar5 = *(longlong *)(lVar3 + 0x54) + 0x1cbdda365fff1a80;
  }
  if (lVar5 == 0) {
    GetPciConfigSpace(lVar3,0x40,local_res8,1);
    bVar4 = local_res8[0] & 7;
    local_res8[0] = bVar4;
    if (5 < bVar4) {
      return 0xc0000001;
    }
  }
  else {
    memcmp(_Buf1,&GUID_BUS_TYPE_ACPI,0x10);
    bVar4 = 0;
  }
  pcVar10 = (char *)(param_2 + 0x14);
  uVar2 = *(uint *)(param_2 + 0x10);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      if ((*pcVar10 == '\x03') &&
         (bVar12 = iVar11 == (uint)*(ushort *)(param_1 + 0x4c) + (uint)bVar4, iVar11 = iVar11 + 1,
         bVar12)) break;
      uVar7 = uVar7 + 1;
      pcVar10 = pcVar10 + 0x14;
    } while (uVar7 < uVar2);
    if (uVar7 < uVar2) {
      lVar5 = *(longlong *)(pcVar10 + 4);
      *(longlong *)(param_1 + 0x1f8) = lVar5;
      iVar11 = *(int *)(pcVar10 + 0xc);
      *(int *)(param_1 + 0x200) = iVar11;
      *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(pcVar10 + 4);
      *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(pcVar10 + 0xc);
      if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
         (*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2)) {
        *(longlong *)(param_1 + 0x1f8) = lVar5 + -0x900;
        iVar11 = iVar11 + 0x91c;
        *(int *)(param_1 + 0x200) = iVar11;
      }
      lVar5 = MmMapIoSpaceEx(*(undefined8 *)(param_1 + 0x1f8),iVar11,0x204);
      iVar11 = *(int *)(param_1 + 0x200);
      *(longlong *)(param_1 + 0x218) = lVar5;
      *(int *)(param_1 + 0x220) = iVar11;
      if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
         (*(byte *)(*(longlong *)(param_1 + 8) + 0x46) < 2)) {
        *(int *)(param_1 + 0x238) = *(int *)(param_1 + 0x238) + -0x91c;
        lVar6 = lVar5 + 0x900;
      }
      else {
        *(int *)(param_1 + 0x238) = iVar11;
        lVar6 = lVar5;
      }
      *(longlong *)(param_1 + 0x228) = lVar6;
      *(longlong *)(param_1 + 0x230) = lVar6;
      *(undefined1 *)(param_1 + 0x310) = 0;
      lVar6 = *_Buf1 + -0x4942001ad7b46895;
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(lVar3 + 0x54) + -0x43a81066d4a71f89;
      }
      if (lVar6 == 0) {
        uVar2 = *(uint *)(param_1 + 0x20);
        *(uint *)(param_1 + 0x20) = uVar2 | 0x800000;
        cVar1 = *(char *)(lVar3 + 0x45);
        if (cVar1 != '\x04') {
          if (cVar1 != '\x05') {
            if (cVar1 == '\x06') {
              *(uint *)(param_1 + 0x20) = uVar2 | 0x2800000;
              if (*(char *)(lVar3 + 0x46) == '\x01') {
                if ((*(longlong *)(param_1 + 0x1f8) - 0x78000000U & 0xfffffffffffffbff) == 0) {
                  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x80000;
                }
                *(code **)(*(longlong *)(lVar3 + 0x28) + 0x90) = SdhcNvT40ExecuteRetuning;
                *(code **)(*(longlong *)(lVar3 + 0x28) + 0x160) = SdhcNvT40ResetTuningState;
                *(code **)(*(longlong *)(lVar3 + 0x28) + 0x168) = SdhcNvT40SetSavedTapValue;
              }
            }
            else if (cVar1 == '\n') {
              *(code **)(*(longlong *)(lVar3 + 0x28) + 0x90) = SdhcQcExecuteRetuning;
            }
            goto LAB_14000aaad;
          }
          *(longlong *)(param_1 + 0x228) = lVar5 + 0x200;
          *(longlong *)(param_1 + 0x230) = lVar5 + 0x200;
          *(int *)(param_1 + 0x238) = iVar11 + -0x200;
        }
        *(undefined2 *)(param_1 + 0x23c) = 0;
        *(uint *)(param_1 + 0x20) = uVar2 | 0x3c00000;
      }
LAB_14000aaad:
      lVar3 = *(longlong *)(param_1 + 8);
      if ((*(short *)(lVar3 + 0x3c) == 0x102f) || (*(short *)(lVar3 + 0x3c) == 0x1179)) {
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
      }
      puVar9 = (uint *)(param_1 + 0x48);
      if (*(short *)(lVar3 + 0x3c) == 0x1180) {
        *puVar9 = *puVar9 | 4;
      }
      if (*(short *)(lVar3 + 0x3c) == 0x1106) {
        *puVar9 = *puVar9 | 0x2000;
      }
      puVar8 = (uint *)(param_1 + 0x48);
      if (*(char *)(lVar3 + 0x45) == '\x03') {
        *puVar8 = *puVar9 | 0x3a;
      }
      if (*(char *)(lVar3 + 0x45) == '\x04') {
        *puVar8 = *puVar8 | 0x42;
      }
      puVar9 = (uint *)(param_1 + 0x48);
      if ((*(char *)(lVar3 + 0x45) == '\x06') &&
         ((*(longlong *)(param_1 + 0x1f8) == 0x78000400 ||
          (*(longlong *)(param_1 + 0x1f8) == 0x78000000)))) {
        *puVar9 = *puVar9 | 0x8000;
      }
      if (*(char *)(lVar3 + 0x45) == '\n') {
        *puVar9 = *puVar9 | 0x20000000;
      }
      if (SdEnableEmmcSleep != 0) {
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x100000;
      }
      SdbusDebugPrint(4,"SdbusStartDevice: Host Register Base at %p, size %x",
                      *(undefined8 *)(param_1 + 0x228),(ulonglong)*(uint *)(param_1 + 0x238));
      return 0;
    }
  }
  return 0xc0000001;
}



===== SdhcStartSystemDmaTransfer @ 14000abb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SdhcStartSystemDmaTransfer(undefined4 *param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  longlong lVar8;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 *local_b0;
  undefined1 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  code *local_90;
  longlong local_88;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar5 = 0;
  local_68 = 0;
  local_38 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((*(longlong *)(param_2 + 0x2e0) == 0) || (*(longlong *)(param_2 + 0x2e8) == 0)) {
    lVar8 = *(longlong *)(param_2 + 0x2d8);
  }
  else {
    lVar8 = *(longlong *)(param_2 + 0x2e8);
    if (*(int *)(param_2 + 0x17a4) == 1) {
      lVar8 = *(longlong *)(param_2 + 0x2e0);
    }
  }
  iVar2 = *(int *)(param_2 + 0x174c);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      piVar1 = (int *)(param_2 + 0x1798);
      *piVar1 = *piVar1 - *(uint *)(param_2 + 0x17ac);
      if (*piVar1 == 0) {
        *(longlong *)(param_2 + 0x2a30) = *(longlong *)(param_2 + 0x2a30) + 1;
        (**(code **)(*(longlong *)(lVar8 + 8) + 0x30))(lVar8);
        *(undefined1 *)(param_2 + 0x359) = 0;
        uVar7 = SdTransferTimeout;
        param_1[1] = 10000000;
        uVar5 = 2;
        param_1[2] = uVar7 / 100;
        *param_1 = 8;
      }
      else {
        *(longlong *)(param_2 + 0x370) =
             *(longlong *)(param_2 + 0x370) + (ulonglong)*(uint *)(param_2 + 0x17ac);
        local_b0 = &local_60;
        *(ulonglong *)(param_2 + 0x17b4) =
             (*(longlong *)(param_2 + 0x370) -
             (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x308) + 0x2c)) -
             *(longlong *)(*(longlong *)(param_2 + 0x308) + 0x20);
        *(undefined4 *)(param_2 + 0x17ac) = *(undefined4 *)(param_2 + 0x1798);
        local_5c = 0;
        uStack_54 = 0;
        local_60 = 1;
        local_b8 = CONCAT31(local_b8._1_3_,*(int *)(param_2 + 0x17a4) == 2);
        (**(code **)(*(longlong *)(lVar8 + 8) + 0x88))(lVar8,*(undefined8 *)(param_2 + 0x308));
        if (*(uint *)(param_2 + 0x2f0) < (uint)local_5c) {
          *(uint *)(param_2 + 0x17ac) =
               *(uint *)(param_2 + 0x2f0) * 0x1000 - *(int *)(*(longlong *)(param_2 + 0x308) + 0x2c)
          ;
        }
        else {
          *(uint *)(param_2 + 0x2f0) = (uint)local_5c;
        }
      }
      *(undefined4 *)(param_2 + 0x174c) = uVar5;
      return 0xc0000016;
    }
    if (iVar2 == 2) {
      *param_1 = 0;
      uVar7 = 0;
    }
    else {
      uVar7 = 0xc0000001;
    }
    goto LAB_14000af00;
  }
  lVar3 = *(longlong *)(param_2 + 8);
  if (*(char *)(lVar3 + 0x45) == '\x05') {
    uStack_40._4_4_ = 0;
    if (*(int *)(param_2 + 0x17a4) == 1) {
      uVar5 = 0x6002;
    }
    else {
      uStack_40._4_4_ = 0x800000;
      uVar5 = 0xc2;
    }
    local_38 = 0x20;
    uStack_40 = CONCAT44(uStack_40._4_4_,(uint)(*(ushort *)(param_2 + 0x179c) >> 2)) | 0x2000000000;
    if (*(int *)(param_2 + 0x17a4) == 2) {
      uVar6 = *(undefined4 *)(lVar3 + 0x3c4);
    }
    else {
      uVar6 = *(undefined4 *)(lVar3 + 0x39c);
    }
    local_48 = CONCAT44(uVar5,uVar6);
    uVar7 = (**(code **)(*(longlong *)(lVar8 + 8) + 0xa8))(lVar8,0x80000000,&local_48);
    if (-1 < (int)uVar7) goto LAB_14000ae08;
    SdbusDebugPrint(0x4000,
                    "SDHC[%p] SdhcStartSystemDmaTransfer: ConfigureAdapterChannel failed: %08X",
                    param_2,(ulonglong)uVar7);
  }
  else {
LAB_14000ae08:
    *(longlong *)(param_2 + 0x29f0) = *(longlong *)(param_2 + 0x29f0) + 1;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350,&local_78);
    *(undefined1 *)(param_2 + 0x349) = 1;
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
    local_a8 = *(int *)(param_2 + 0x17a4) == 2;
    local_b0 = (undefined4 *)(param_2 + 0x17ac);
    local_90 = SdhcSystemDmaCompletionRoutine;
    local_98 = *(undefined4 *)(param_2 + 0x1794);
    local_a0 = *(undefined8 *)(param_2 + 0x178c);
    local_b8 = 0x20;
    local_88 = param_2;
    uVar7 = (**(code **)(*(longlong *)(lVar8 + 8) + 0xb8))
                      (lVar8,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),
                       *(undefined8 *)(param_2 + 0x17b4));
    uVar4 = SdTransferTimeout;
    if (-1 < (int)uVar7) {
      param_1[1] = 10000000;
      param_1[2] = uVar4 / 100;
      *param_1 = 0x40;
      *(undefined4 *)(param_2 + 0x174c) = 1;
      return 0xc0000016;
    }
    SdbusDebugPrint(0x4000,"SDHC[%p] SdhcStartSystemDmaTransfer: MapTransferEx failed: %08X",param_2
                    ,(ulonglong)uVar7);
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350,&local_78);
  *(undefined1 *)(param_2 + 0x349) = 0;
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_78);
  if (uVar7 == 0xc0000016) {
    return 0xc0000016;
  }
LAB_14000af00:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return uVar7;
}



===== SdhcStartTransfer @ 14000af70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhcStartTransfer(undefined8 param_1,longlong param_2)

{
  (**(code **)(&DAT_140021008 + (ulonglong)*(uint *)(param_2 + 0x17a0) * 0x10))();
  return;
}



===== SdhcSystemDmaCompletionRoutine @ 14000afa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdhcSystemDmaCompletionRoutine
               (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  SdbusDebugPrint(0x4000,"SDHC[%p] SdhcDmaCompletionRoutine\r\n",param_3,param_4);
  *(longlong *)(param_3 + 0x29f8) = *(longlong *)(param_3 + 0x29f8) + 1;
  (**(code **)(*(longlong *)(param_1 + 8) + 0xd0))
            (param_1,*(undefined8 *)(param_3 + 0x308),*(undefined8 *)(param_3 + 0x300),
             *(undefined8 *)(param_3 + 0x17b4),*(undefined4 *)(param_3 + 0x17ac),
             *(int *)(param_3 + 0x17a4) == 2);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_3 + 0x350,&local_28);
  *(undefined1 *)(param_3 + 0x349) = 0;
  if (*(char *)(param_3 + 0x348) == '\0') {
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
    if ((int)param_4 == 0) {
      uVar1 = 0x40;
      uVar2 = 0;
      goto LAB_14000b0c1;
    }
    *(longlong *)(param_3 + 0x2a30) = *(longlong *)(param_3 + 0x2a30) + 1;
    (**(code **)(*(longlong *)(param_1 + 8) + 0x30))(param_1);
    uVar1 = 0x1000;
    uVar2 = 0x20000000;
  }
  else {
    *(undefined1 *)(param_3 + 0x348) = 0;
    KeReleaseInStackQueuedSpinLockFromDpcLevel();
    *(longlong *)(param_3 + 0x2a30) = *(longlong *)(param_3 + 0x2a30) + 1;
    (**(code **)(*(longlong *)(param_1 + 8) + 0x30))(param_1);
    uVar1 = 0x40000;
    uVar2 = 0;
  }
  *(undefined1 *)(param_3 + 0x359) = 0;
LAB_14000b0c1:
  SdbusWorkerPushEvents(param_3,uVar1,uVar2,'\x01','\0');
  return;
}



===== SdhcWriteDataPort @ 14000b0f0 =====

void SdhcWriteDataPort(longlong param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x228);
  puVar4 = (undefined4 *)(lVar3 + 0x20);
  if (3 < param_3) {
    uVar7 = (ulonglong)(param_3 >> 2);
    do {
      if ((*(uint *)(param_1 + 0x20) & 0x400000) != 0) {
        do {
          uVar1 = SdbusReadRegisterUlong(param_1,0x24);
        } while ((uVar1 >> 10 & 1) == 0);
      }
      puVar5 = param_2;
      puVar6 = puVar4;
      for (lVar2 = 1; lVar2 != 0; lVar2 = lVar2 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      LOCK();
      UNLOCK();
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  if (1 < param_3) {
    puVar5 = param_2;
    for (lVar2 = 1; lVar2 != 0; lVar2 = lVar2 + -1) {
      *(undefined2 *)puVar4 = *(undefined2 *)puVar5;
      puVar5 = (undefined4 *)((longlong)puVar5 + 2);
      puVar4 = (undefined4 *)((longlong)puVar4 + 2);
    }
    LOCK();
    UNLOCK();
    param_2 = (undefined4 *)((longlong)param_2 + 2);
    param_3 = param_3 - 2;
    puVar4 = (undefined4 *)(lVar3 + 0x22);
  }
  if (param_3 != 0) {
    for (lVar3 = 1; lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((longlong)param_2 + 1);
      puVar4 = (undefined4 *)((longlong)puVar4 + 1);
    }
    LOCK();
    UNLOCK();
  }
  return;
}



===== SetPciConfigSpace @ 14000b1c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint SetPciConfigSpace(longlong param_1,undefined1 param_2,undefined8 param_3)

{
  uint uVar1;
  
  if (*(code **)(param_1 + 0x2b8) == (code *)0x0) {
    uVar1 = 0xc00000bb;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x2b8))(*(undefined8 *)(param_1 + 0x290),0,param_3,param_2,4);
    uVar1 = -(uint)(uVar1 < 4) & 0xc0000001;
  }
  return uVar1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000b210 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000b2e8 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000b3cc =====

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
LAB_14000b524:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000b517:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_14000b524;
      if (uVar5 == 5) goto LAB_14000b517;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000b54c =====

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
              (0x3374177,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000b5c8 =====

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
                     (local_50,(uint *)&Feature_SupportForSDUltraCapacity__private_reporting,param_3
                      ,(uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3374177,param_3 & 0xffffffff,1,
               &Feature_SupportForSDUltraCapacity__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3374177);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000b6b4 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000b7c4 =====

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
  if ((Feature_SupportForSDUltraCapacity__private_featureState & 2) != 0) {
    uVar1 = Feature_SupportForSDUltraCapacity__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_SupportForSDUltraCapacity__private_featureState;
      if (bVar3) {
        Feature_SupportForSDUltraCapacity__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_SupportForSDUltraCapacity__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14000b818 =====

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



===== wil_details_IsEnabledFallback @ 14000b978 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_SupportForSDUltraCapacity__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_SupportForSDUltraCapacity__private_featureState,
                             (ulonglong)param_1,0x140029b58);
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



===== wil_details_MapReportingKind @ 14000ba08 =====

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



===== McTemplateK0i_EtwWriteTransfer @ 14000baa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0i_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0iqqqqq_EtwWriteTransfer @ 14000bb04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0iqqqqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  undefined8 local_res20;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  undefined8 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = &local_res20;
  local_70 = 8;
  local_68 = &param_5;
  local_60 = 4;
  local_58 = &param_6;
  local_50 = 4;
  local_48 = &param_7;
  local_38 = &param_8;
  local_28 = &param_9;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&SdbusPStateUtilization,param_3,7,local_88);
  return;
}



===== McTemplateK0iqx_EtwWriteTransfer @ 14000bbbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0iqx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 4;
  local_28 = &param_6;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0iuix_EtwWriteTransfer @ 14000bc38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0iuix_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 1;
  local_38 = &param_6;
  local_28 = &param_7;
  local_30 = 8;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== SdbusBuildWorkPacket @ 14000bcc8 =====

undefined8
SdbusBuildWorkPacket
          (undefined8 param_1,int param_2,longlong param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 *param_7)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  puVar5 = (undefined8 *)ExAllocateFromLookasideListEx();
  if (puVar5 == (undefined8 *)0x0) {
    if (param_2 == 6) {
      plVar1 = (longlong *)(param_3 + 0xa88);
      plVar2 = (longlong *)*plVar1;
      if (plVar2 != plVar1) {
        if (((longlong *)plVar2[1] == plVar1) &&
           (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) == plVar2)) {
          *plVar1 = lVar3;
          puVar5 = plVar2 + -0xe;
          *(longlong **)(lVar3 + 8) = plVar1;
          goto LAB_14000bd3d;
        }
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
      }
    }
    uVar6 = 0xc000009a;
  }
  else {
    *(undefined1 *)((longlong)puVar5 + 0x82) = 0;
LAB_14000bd3d:
    SdbusInitializeWorkPacket(puVar5,param_2,param_3,param_4,param_5,param_6);
    *param_7 = puVar5;
    uVar6 = 0;
  }
  return uVar6;
}



===== SdbusCancelPStateTimer @ 14000bd88 =====

void SdbusCancelPStateTimer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x150) != 0) {
    KeCancelTimer(param_1 + 0x178);
  }
  return;
}



===== SdbusCommandEngineDisablePolling @ 14000bdb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdbusCommandEngineDisablePolling(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (*(char *)(*(longlong *)(param_2 + 0x10) + 0x24) == '\0') {
    lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 8);
    uVar2 = KfRaiseIrql(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x90)));
    KeAcquireSpinLockAtDpcLevel(*(longlong *)(*(longlong *)(param_2 + 0x10) + 8) + 0x88);
    if (*(char *)(param_2 + 0x58) != '\0') {
      *(undefined1 *)(param_2 + 0x58) = 0;
      *(undefined1 *)(param_1 + 0xd) = 0;
      lVar1 = *(longlong *)(param_2 + 0x10);
      if ((*(uint *)(lVar1 + 0x3a0) & 0x100) == 0) {
        uVar4 = 0xfffffeff;
        pcVar3 = *(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0xe8);
      }
      else {
        pcVar3 = *(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0xe8);
        uVar4 = 0xffffffff;
      }
      (*pcVar3)(lVar1,0xffffffff,uVar4);
    }
    KeReleaseSpinLockFromDpcLevel(*(longlong *)(*(longlong *)(param_2 + 0x10) + 8) + 0x88);
    KeLowerIrql(uVar2);
  }
  return;
}



===== SdbusCommandEngineEnablePolling @ 14000bea4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdbusCommandEngineEnablePolling(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  int *piVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  if (*(char *)(lVar1 + 0x24) != '\0') {
    return;
  }
  if (*(char *)(lVar1 + 0x16a0) == '\0') {
    *(undefined1 *)(param_2 + 0x58) = 0;
    return;
  }
  uVar2 = KfRaiseIrql(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 8) >> 8),
                               *(undefined1 *)(*(longlong *)(lVar1 + 8) + 0x90)));
  KeAcquireSpinLockAtDpcLevel(*(longlong *)(*(longlong *)(param_2 + 0x10) + 8) + 0x88);
  if (*(char *)(param_2 + 0x30) == '4') {
LAB_14000bf57:
    *(undefined1 *)(param_2 + 0x58) = 1;
    *(undefined1 *)(param_1 + 0xd) = 1;
    (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 8) + 0x28) + 0xe8))
              (*(longlong *)(param_2 + 0x10),0,0xffffffff);
    piVar4 = (int *)(*(longlong *)(param_2 + 0x10) + 0x2994);
  }
  else {
    if (*(char *)(param_2 + 0x30) == '5') {
      uVar3 = (uint)*(ushort *)(param_2 + 0x2c);
      if (*(ushort *)(param_2 + 0x2e) != 0) {
        uVar3 = *(ushort *)(param_2 + 0x2e) * uVar3;
      }
      if (uVar3 <= SdPollTransferThreshold) goto LAB_14000bf57;
    }
    piVar4 = (int *)(*(longlong *)(param_2 + 0x10) + 0x2998);
  }
  LOCK();
  *piVar4 = *piVar4 + 1;
  UNLOCK();
  KeReleaseSpinLockFromDpcLevel(*(longlong *)(*(longlong *)(param_2 + 0x10) + 8) + 0x88);
  KeLowerIrql(uVar2);
  return;
}



===== SdbusCommandEngineWorker @ 14000bff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdbusCommandEngineWorker(uint *param_1,uint *param_2)

{
  uint *puVar1;
  longlong *plVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 uVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined7 uVar15;
  ulonglong uVar14;
  uint7 uVar16;
  int iVar17;
  uint *puVar18;
  uint local_res10 [2];
  int local_res18 [2];
  undefined8 local_res20;
  ulonglong in_stack_ffffffffffffff78;
  undefined4 uVar19;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  uVar14 = (ulonglong)*param_2;
  puVar1 = param_2 + 0xc;
  puVar18 = (uint *)(ulonglong)(byte)*puVar1;
  local_res20 = 0;
  iVar10 = 0;
  local_res18[0] = 0;
  SdbusDebugPrint(0x100000,"SendCmdAsync ph(%d): CMD%d",uVar14,puVar18);
  uVar9 = *param_2;
  if (uVar9 < 0xb) {
    if (uVar9 == 10) {
LAB_14000ca64:
      uVar14 = (ulonglong)*(ushort *)((longlong)param_2 + 0x2e);
      in_stack_ffffffffffffff78 = CONCAT44((int)(in_stack_ffffffffffffff78 >> 0x20),param_2[0xe]);
      iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) +
                           0x108))(*(longlong *)(param_2 + 4),(short)param_2[0xb],uVar14,param_2[10]
                                   ,in_stack_ffffffffffffff78,*(undefined8 *)(param_2 + 6),
                                   *(undefined8 *)(param_2 + 8),param_2[0xf] == 3);
      if (iVar10 < 0) goto LAB_14000d001;
      *param_2 = 0xb;
    }
    else {
      if (uVar9 < 6) {
        if (uVar9 == 5) {
          lVar4 = *(longlong *)(param_2 + 4);
          if (*(char *)(lVar4 + 0x165d) == '\0') {
            if (*(char *)(lVar4 + 0x165e) != '\0') {
              uVar14 = 6;
              goto LAB_14000c460;
            }
            if (*(char *)(lVar4 + 0x1659) != '\0') {
              uVar14 = 3;
              goto LAB_14000c460;
            }
          }
          else {
            uVar14 = 5;
LAB_14000c460:
            if (*(uint *)(lVar4 + 0x1684) < 0x186a1) {
              uVar14 = 0;
            }
            else if (100000 < *(uint *)(lVar4 + 0x1680)) goto LAB_14000c49b;
            iVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x88))
                               (param_1,lVar4,uVar14,1);
            if (iVar10 < 0) goto LAB_14000d001;
          }
LAB_14000c49b:
          *param_2 = 3;
        }
        else {
          if (uVar9 == 0) {
            if ((Microsoft_Windows_SdbusEnableBits & 0x10) != 0) {
              in_stack_ffffffffffffff78 =
                   CONCAT71((int7)(in_stack_ffffffffffffff78 >> 8),(byte)*puVar1);
              McTemplateK0iuix_EtwWriteTransfer
                        ((ulonglong)param_2[1],&SdbusCommandIssued,uVar14,
                         *(undefined8 *)(*(longlong *)(param_2 + 4) + 0x208),(byte)*puVar1,
                         (char)param_2[1],
                         (char)param_2[0xb] * (char)*(undefined2 *)((longlong)param_2 + 0x2e));
            }
            lVar4 = *(longlong *)(param_2 + 4);
            lVar13 = *(longlong *)(lVar4 + 0x568);
            uVar14 = *(ulonglong *)(lVar4 + 8);
            if ((((*(byte *)(lVar13 + 0x80) & 1) == 0) && ((char)param_2[0xc] != '\x17')) &&
               ((char)param_2[0x11] != '\x17')) {
              uVar6 = 0;
            }
            else {
              uVar6 = 1;
            }
            *(undefined1 *)((longlong)param_2 + 0x59) = uVar6;
            if (*(int *)(lVar13 + 0x18) != 3) {
              *(undefined1 *)(lVar4 + 0x16a1) = 0;
            }
            if (((*(char *)(uVar14 + 0x168) == '\0') ||
                (*(char *)(*(longlong *)(param_2 + 4) + 0x24) != '\0')) ||
               ((*(int *)(lVar13 + 0x18) != 3 || (*(char *)((longlong)param_2 + 0x59) != '\0')))) {
              if (((*(char *)(*(longlong *)(param_2 + 4) + 0x16a1) != '\0') &&
                  (*(longlong *)(lVar13 + 8) != 0)) &&
                 (*(int *)(*(longlong *)(lVar13 + 8) + 0x20) == 1)) {
                *param_2 = 1;
                *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x16a1) = 0;
              }
            }
            else {
              param_1[0] = 0x1000000;
              param_1[1] = 0;
              iVar10 = SdbusRequestPState(uVar14,(int *)0x0);
              if (iVar10 == -0x3fffffea) {
                *param_2 = 1;
                iVar10 = -0x3fffffea;
                goto LAB_14000d001;
              }
              *param_1 = 0;
            }
LAB_14000c2bb:
            if (*param_2 == 1) {
              lVar4 = *(longlong *)(param_2 + 4);
              uVar14 = *(ulonglong *)(lVar4 + 8);
              uVar15 = (undefined7)(uVar14 >> 8);
              uVar19 = (undefined4)(in_stack_ffffffffffffff78 >> 0x20);
              if (*(char *)(uVar14 + 0x45) == '\n') {
                if (*(char *)(lVar4 + 0x165e) == '\0') {
                  *param_2 = 5;
                  return -0x3fffffea;
                }
                if ((*(uint *)(lVar4 + 0x1684) < 100000) || (*(uint *)(lVar4 + 0x1680) < 100000)) {
                  uVar9 = *(uint *)(lVar4 + 0x1188);
                  in_stack_ffffffffffffff78 = CONCAT44(uVar19,*(uint *)(lVar4 + 0x1684));
                  if (50000 < uVar9) {
                    uVar9 = 50000;
                  }
                  plVar2 = (longlong *)(uVar14 + 0x28);
                  uVar14 = CONCAT71(uVar15,1);
                  iVar10 = (**(code **)(*plVar2 + 0x50))(param_1,lVar4,uVar14,uVar9);
                  if (-1 < iVar10) {
                    uVar9 = (-(uint)(*(uint *)(*(longlong *)(param_2 + 4) + 0x1684) < 100000) & 2) +
                            2;
LAB_14000c132:
                    *param_2 = uVar9;
                    return -0x3fffffea;
                  }
                  goto LAB_14000d001;
                }
              }
              else if ((((*(char *)(uVar14 + 0x45) == '\x06') &&
                        (*(char *)(uVar14 + 0x46) == '\x01')) &&
                       (lVar13 = *(longlong *)(uVar14 + 0x170), lVar13 != 0)) &&
                      ((*(uint *)(lVar4 + 0x1188) <
                        *(uint *)(lVar13 + 4 + (ulonglong)*(uint *)(uVar14 + 0x140) * 0x14) ||
                       (*(uint *)(lVar4 + 0x1188) <
                        *(uint *)(lVar13 + 4 + (ulonglong)*(uint *)(uVar14 + 0x13c) * 0x14))))) {
                plVar2 = (longlong *)(uVar14 + 0x28);
                uVar14 = CONCAT71(uVar15,1);
                in_stack_ffffffffffffff78 = CONCAT44(uVar19,*(undefined4 *)(lVar4 + 0x1684));
                iVar10 = (**(code **)(*plVar2 + 0x50))(param_1);
                if (iVar10 < 0) goto LAB_14000d001;
              }
            }
            uVar11 = KeQueryInterruptTimePrecise(&local_res20);
            *(undefined8 *)(*(longlong *)(param_2 + 4) + 0x2aa8) = uVar11;
            *param_2 = 6;
            goto LAB_14000cffe;
          }
          if (uVar9 == 1) goto LAB_14000c2bb;
          if (uVar9 == 2) {
            lVar4 = *(longlong *)(param_2 + 4);
            if (*(uint *)(lVar4 + 0x1684) < 100000) {
              uVar9 = 0x3b70200;
LAB_14000c15e:
              in_stack_ffffffffffffff78 = 0;
              SdbusAddDbgLog(lVar4,0x434d4420,6,(ulonglong)uVar9,0);
              uVar14 = (ulonglong)uVar9;
              iVar10 = (**(code **)(*(longlong *)
                                     (*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) + 0xc0))
                                 (*(longlong *)(param_2 + 4),&CmdDescMmcSwitch,uVar14,0);
              uVar9 = SdTransferTimeout;
              if (iVar10 < 0) goto LAB_14000d001;
              param_1[1] = 100000;
              param_1[2] = uVar9 / 100;
              *param_1 = 0xc;
            }
            else if (*(uint *)(lVar4 + 0x1680) < 100000) {
              uVar9 = 0x3b70600;
              goto LAB_14000c15e;
            }
            uVar9 = (*(uint *)(*(longlong *)(param_2 + 4) + 0x1684) < 100000) + 4;
            goto LAB_14000c132;
          }
          if (uVar9 != 3) {
            if (uVar9 != 4) goto LAB_14000c9d8;
            lVar4 = *(longlong *)(param_2 + 4);
            if (*(uint *)(lVar4 + 0x1684) < 100000) {
              uVar9 = 0x3b90100;
LAB_14000c0bc:
              in_stack_ffffffffffffff78 = 0;
              SdbusAddDbgLog(lVar4,0x434d4420,6,(ulonglong)uVar9,0);
              uVar14 = (ulonglong)uVar9;
              iVar10 = (**(code **)(*(longlong *)
                                     (*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) + 0xc0))
                                 (*(longlong *)(param_2 + 4),&CmdDescMmcSwitch,uVar14,0);
              uVar9 = SdTransferTimeout;
              if (iVar10 < 0) goto LAB_14000d001;
              param_1[1] = 100000;
              param_1[2] = uVar9 / 100;
              *param_1 = 0xc;
            }
            else if (*(uint *)(lVar4 + 0x1680) < 100000) {
              uVar9 = 0x3b90300;
              goto LAB_14000c0bc;
            }
            uVar9 = (-(uint)(*(uint *)(*(longlong *)(param_2 + 4) + 0x1684) < 100000) & 0xfffffffd)
                    + 5;
            goto LAB_14000c132;
          }
        }
        lVar4 = *(longlong *)(param_2 + 4);
        uVar9 = *(uint *)(lVar4 + 0x1684);
        uVar14 = (ulonglong)uVar9;
        if ((uVar9 < 100000) || (*(uint *)(lVar4 + 0x1680) < 100000)) {
          in_stack_ffffffffffffff78 = CONCAT44((int)(in_stack_ffffffffffffff78 >> 0x20),uVar9);
          uVar14 = CONCAT71((uint7)(uint3)(uVar9 >> 8),1);
          iVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x50))
                             (param_1,lVar4,uVar14,*(undefined4 *)(lVar4 + 0x1188));
          if (iVar10 < 0) goto LAB_14000d001;
        }
        uVar11 = KeQueryInterruptTimePrecise(&local_res20);
        *(undefined8 *)(*(longlong *)(param_2 + 4) + 0x2aa8) = uVar11;
        *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x16a1) = 0;
        *param_2 = 6;
      }
      else if (uVar9 != 6) {
        if (uVar9 == 7) {
          lVar4 = *(longlong *)(*(longlong *)(param_2 + 4) + 8);
          if (((*(char *)(lVar4 + 0x45) != '\v') || (*(char *)(lVar4 + 0x46) != '\x01')) ||
             (iVar10 = (**(code **)(*(longlong *)(lVar4 + 0x28) + 0x170))(param_1),
             iVar10 != -0x3fffffea)) goto LAB_14000c941;
        }
        else if (uVar9 == 8) {
          uVar14 = *(ulonglong *)(param_2 + 4);
          uVar11 = CONCAT44(uVar19,param_2[0x10]);
          in_stack_ffffffffffffff78 = CONCAT44((int)(in_stack_ffffffffffffff78 >> 0x20),param_2[1]);
          if (param_2[0xd] == 1) {
            SdbusDebugPrint(0x1000,"skt %p SD_SEND ACMD%d ==> arg=%08x, rt=%d",uVar14,
                            (ulonglong)(byte)*puVar1);
            in_stack_ffffffffffffff78 = (ulonglong)(int)param_2[0x10];
            SdbusAddDbgLog(*(longlong *)(param_2 + 4),0x41434d44,
                           (longlong)(int)(param_2[0xd] << 0x10) | (ulonglong)(byte)*puVar1,
                           (ulonglong)param_2[1],in_stack_ffffffffffffff78);
            (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) + 0x120
                        ))();
            lVar4 = *(longlong *)(param_2 + 4);
            uVar14 = (ulonglong)*(uint *)(lVar4 + 0x168c);
            iVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xc0))
                               (lVar4,&CmdDescApp,uVar14,0,in_stack_ffffffffffffff78,uVar11);
            uVar9 = SdCommandTimeout;
            if (-1 < iVar10) {
              param_1[1] = 100000;
              iVar10 = -0x3fffffea;
              param_1[2] = uVar9 / 100;
              *param_1 = 4;
            }
            if (iVar10 != -0x3fffffea) goto LAB_14000d001;
          }
          else {
            SdbusDebugPrint(0x1000,"skt  %p SD_SEND CMD%d ==> arg=%08x, rt=%d",uVar14,
                            (ulonglong)(byte)*puVar1);
            iVar10 = -0x3fffffea;
          }
          if (param_2[0xf] == 1) {
            *param_2 = 0xc;
          }
          else {
            uVar14 = *(ulonglong *)(param_2 + 4);
            if ((*(char *)(uVar14 + 0x310) != '\0') && (param_2[10] == 4)) {
              uVar9 = *(int *)(*(longlong *)(*(longlong *)(uVar14 + 8) + 0x68) + 0x98) + 1;
              if (((uint)(ushort)param_2[0xb] % uVar9 == 0) &&
                 (*(ulonglong *)(param_2 + 6) % (ulonglong)uVar9 == 0)) {
                param_2[10] = 4;
              }
              else {
                param_2[10] = 1;
              }
            }
            if (((*(int *)(uVar14 + 0x1120) == 1) || (*(char *)(uVar14 + 0x11bc) == '\0')) ||
               (param_2[0xf] != 3)) {
              uVar12 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar12 == 0) {
                *param_2 = 10;
              }
              else {
                cVar7 = SdbusRequiresUpperAddress
                                  (*(longlong *)(param_2 + 4),(char *)(param_2 + 0xc));
                *param_2 = (-(uint)(cVar7 != '\0') & 10) + 10;
              }
            }
            else {
              if ((((*(char *)(uVar14 + 0x1138) != '\0') && (param_2[10] == 3)) ||
                  ((*(char *)(uVar14 + 0x165e) == '\0' &&
                   ((*(char *)(uVar14 + 0x165d) == '\0' && (*(char *)(uVar14 + 0x1659) == '\0'))))))
                 || (uVar9 = 9, *(char *)(*(longlong *)(uVar14 + 8) + 0x45) == '\t')) {
                uVar12 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar12 == 0) {
                  uVar9 = 10;
                }
                else {
                  cVar7 = SdbusRequiresUpperAddress
                                    (*(longlong *)(param_2 + 4),(char *)(param_2 + 0xc));
                  uVar9 = (-(uint)(cVar7 != '\0') & 10) + 10;
                }
              }
              *param_2 = uVar9;
            }
          }
        }
        else {
          if (uVar9 != 9) {
LAB_14000c9d8:
            iVar10 = -0x3fffffff;
            goto LAB_14000d00a;
          }
          in_stack_ffffffffffffff78 =
               (ulonglong)
               (int)((uint)(ushort)param_2[0xb] * (uint)*(ushort *)((longlong)param_2 + 0x2e));
          SdbusAddDbgLog(*(longlong *)(param_2 + 4),0x434d4420,0x17,
                         (ulonglong)*(ushort *)((longlong)param_2 + 0x2e),in_stack_ffffffffffffff78)
          ;
          uVar14 = (ulonglong)*(ushort *)((longlong)param_2 + 0x2e);
          iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28)
                               + 0xc0))(*(longlong *)(param_2 + 4),&CmdDescSetBlockCount,uVar14,0);
          if (-1 < iVar10) {
            *param_2 = 10;
            uVar9 = SdCommandTimeout;
            param_1[1] = 100000;
            param_1[2] = uVar9 / 100;
            *param_1 = 4;
            uVar12 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar12 == 0) {
              return -0x3fffffea;
            }
            cVar7 = SdbusRequiresUpperAddress(*(longlong *)(param_2 + 4),(char *)(param_2 + 0xc));
            if (cVar7 == '\0') {
              return -0x3fffffea;
            }
            *param_2 = 0x14;
            iVar10 = -0x3fffffea;
          }
        }
        goto LAB_14000d001;
      }
      lVar4 = *(longlong *)(param_2 + 4);
      uVar16 = (uint7)(uVar14 >> 8);
      uVar14 = (ulonglong)uVar16 << 8;
      if ((((*(char *)(lVar4 + 0x165e) != '\0') || (*(char *)(lVar4 + 0x165d) != '\0')) ||
          (*(char *)(lVar4 + 0x1659) != '\0')) ||
         ((*(char *)(lVar4 + 0x165a) != '\0' && (*(char *)(lVar4 + 0x112e) != '\0')))) {
        uVar14 = CONCAT71(uVar16,1);
      }
      if (((*(byte *)(*(longlong *)(lVar4 + 0x568) + 0x80) & 1) == 0) ||
         (cVar7 = '\x01', *(char *)(lVar4 + 0x16a4) != '\0')) {
        cVar7 = '\0';
      }
      *(char *)((longlong)param_2 + 0x59) = cVar7;
      if ((((*(char *)(lVar4 + 0x634) == '\0') || (cVar7 != '\0')) ||
          ((*(uint *)(lVar4 + 0x48) & 0x1000) != 0)) ||
         (((char)uVar14 == '\0' || (*(char *)(lVar4 + 0x8b8) == '\x17')))) {
        *(undefined1 *)(lVar4 + 0x634) = 0;
LAB_14000c941:
        *param_2 = 8;
        return -0x3fffffea;
      }
      iVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x90))(param_1);
      if (iVar10 == -0x3fffffea) goto LAB_14000d001;
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x634) = 0;
      lVar4 = *(longlong *)(param_2 + 4);
      if (((*(int *)(lVar4 + 0x113c) != 0) && (*(char *)(lVar4 + 0x112f) != '\0')) &&
         (*(char *)(lVar4 + 0x24) == '\0')) {
        SdbusSetRetuningTimer(lVar4 + 0x3a8);
      }
      lVar4 = *(longlong *)(param_2 + 4);
      if (((*(char *)(*(longlong *)(lVar4 + 8) + 0x45) == '\v') &&
          (*(char *)(*(longlong *)(lVar4 + 8) + 0x46) == '\x01')) &&
         ((*(char *)(lVar4 + 0x165e) != '\0' ||
          ((*(char *)(lVar4 + 0x165d) != '\0' || (*(char *)(lVar4 + 0x1659) != '\0')))))) {
        *param_2 = 7;
        return -0x3fffffea;
      }
      lVar4 = *(longlong *)(param_2 + 4);
      lVar13 = KeQueryInterruptTimePrecise(&local_res20);
      *(longlong *)(lVar4 + 0x2aa8) = lVar13 - *(longlong *)(lVar4 + 0x2aa8);
      *param_2 = 8;
    }
LAB_14000cffe:
    iVar10 = -0x3fffffea;
    goto LAB_14000d001;
  }
  if (uVar9 == 0xb) {
    iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) +
                         0x110))(param_1);
    if (-1 < iVar10) {
      *param_2 = 0xc;
      goto LAB_14000cffe;
    }
    goto LAB_14000d001;
  }
  if (uVar9 == 0xc) {
    if (SdEnablePollingCmdResp == 0) {
      LOCK();
      *(int *)(*(longlong *)(param_2 + 4) + 0x2998) =
           *(int *)(*(longlong *)(param_2 + 4) + 0x2998) + 1;
      UNLOCK();
    }
    else {
      SdbusCommandEngineEnablePolling((longlong)param_1,(longlong)param_2);
    }
    *param_2 = 0xd;
LAB_14000cd6f:
    uVar11 = KeQueryInterruptTimePrecise(&local_res20);
    *(undefined8 *)(param_2 + 0x1c) = uVar11;
    puVar18 = param_2 + 4;
    (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)puVar18 + 8) + 0x28) + 0x120))();
    in_stack_ffffffffffffff78 =
         (longlong)(int)((uint)*(ushort *)((longlong)param_2 + 0x2e) << 0x10) |
         (ulonglong)(ushort)param_2[0xb];
    SdbusAddDbgLog(*(longlong *)puVar18,0x434d4420,
                   (longlong)(int)(param_2[0xd] << 0x10) | (ulonglong)(byte)*puVar1,
                   (ulonglong)param_2[1],in_stack_ffffffffffffff78);
    *(byte *)(*(longlong *)puVar18 + 0x8b8) = (byte)*puVar1;
    uVar14 = (ulonglong)param_2[1];
    iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)puVar18 + 8) + 0x28) + 0xc0))
                       (*(longlong *)puVar18,puVar1,uVar14,0);
    uVar9 = SdCommandTimeout;
    if (-1 < iVar10) {
      param_1[1] = 100000;
      uVar9 = uVar9 / 100;
      param_1[2] = uVar9;
      *param_1 = 4;
      uVar5 = SdTransferTimeout;
      if (((param_2[0x10] == 3) || (param_2[0x10] == 8)) &&
         ((*(uint *)(*(longlong *)(param_2 + 4) + 0x48) & 8) == 0)) {
        *param_1 = 0xc;
        uVar9 = uVar5 / 100;
        param_1[2] = uVar9;
      }
      if (((*(int *)(*(longlong *)(param_2 + 4) + 0x1120) == 3) && ((char)param_2[0xc] == '\x06'))
         && (param_2[1] == 0x3200100)) {
        uVar9 = (SdTransferTimeout / 100) * 0x3c;
        param_1[2] = uVar9;
      }
      lVar4 = *(longlong *)(param_2 + 4);
      if ((*(int *)(lVar4 + 0x1120) != 3) || ((char)param_2[0xc] != '&')) goto LAB_14000cf4d;
      uVar14 = (ulonglong)*(byte *)(lVar4 + 0x798) << 10;
      lVar13 = *(longlong *)(*(longlong *)(lVar4 + 0x568) + 0x90);
      iVar10 = *(int *)(lVar13 + 0x40);
      iVar17 = (((int)(*(uint *)(lVar13 + 0x48) / uVar14) - (int)(*(uint *)(lVar13 + 0x44) / uVar14)
                ) + 1) * (uint)*(byte *)(lVar4 + 0x797);
      if (iVar10 == -0x80000000) {
        bVar8 = *(byte *)(lVar4 + 0x79e);
LAB_14000cf3e:
        iVar17 = iVar17 * (uint)bVar8;
      }
      else if ((iVar10 == -0x7fffffff) || (iVar10 == -0x7fff8000)) {
        bVar8 = *(byte *)(lVar4 + 0x79d);
        goto LAB_14000cf3e;
      }
      uVar9 = iVar17 * 3;
      param_1[2] = uVar9;
LAB_14000cf4d:
      if ((*(int *)(*(longlong *)(param_2 + 4) + 0x117c) == 3) &&
         ((cVar7 = *(char *)(*(longlong *)(param_2 + 4) + 0x1192), cVar7 == -0x70 || (cVar7 == 'p'))
         )) {
        param_1[2] = uVar9 << 5;
      }
      if ((char)param_2[0x16] != '\0') {
        param_1[4] = SdEnablePollingCmdTimeout;
      }
      if (param_2[0xf] == 1) {
        *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x909) = 1;
      }
      if ((*(byte *)(*(longlong *)(*(longlong *)(param_2 + 4) + 0x568) + 0x80) & 2) != 0) {
        if (param_1[2] < 3000) {
          param_1[2] = 3000;
        }
        *param_1 = *param_1 | 0x2000000;
      }
      *param_2 = 0xe;
      return -0x3fffffea;
    }
LAB_14000cfca:
    SdbusCommandEngineDisablePolling((longlong)param_1,(longlong)param_2);
  }
  else {
    if (uVar9 == 0xd) goto LAB_14000cd6f;
    if (uVar9 != 0xe) {
      if (uVar9 == 0xf) {
        in_stack_ffffffffffffff78 = 0;
        SdbusAddDbgLog(*(longlong *)(param_2 + 4),0x434d4420,0xd,
                       (ulonglong)*(uint *)(*(longlong *)(param_2 + 4) + 0x168c),0);
        lVar4 = *(longlong *)(param_2 + 4);
        uVar14 = (ulonglong)*(uint *)(lVar4 + 0x168c);
        iVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xc0))
                           (lVar4,&CmdDescSendStatus,uVar14,0);
        uVar9 = SdCommandTimeout;
        if (-1 < iVar10) {
          param_1[1] = 100000;
          param_1[2] = uVar9 / 100;
          *param_1 = 4;
          *param_2 = 0x10;
          goto LAB_14000cffe;
        }
        goto LAB_14000d001;
      }
      if (uVar9 != 0x10) {
        if (uVar9 == 0x12) goto LAB_14000cc7c;
        if (uVar9 == 0x13) {
          uVar14 = 2;
          iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28)
                               + 0x48))(param_1);
        }
        else {
          if (uVar9 != 0x14) goto LAB_14000c9d8;
          uVar14 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar14 == 0) goto LAB_14000ca64;
          in_stack_ffffffffffffff78 = (ulonglong)param_2[1];
          SdbusAddDbgLog(*(longlong *)(param_2 + 4),0x434d4420,0x16,(ulonglong)param_2[2],
                         in_stack_ffffffffffffff78);
          uVar14 = (ulonglong)param_2[2];
          iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28)
                               + 0xc0))(*(longlong *)(param_2 + 4),&CmdDescSetUpperAddress,uVar14,0)
          ;
          if (-1 < iVar10) {
            *param_2 = 10;
            uVar9 = SdCommandTimeout;
            param_1[1] = 100000;
            param_1[2] = uVar9 / 100;
            *param_1 = 4;
            goto LAB_14000cffe;
          }
        }
        goto LAB_14000d001;
      }
      local_res10[0] = 0;
      uVar14 = 4;
      (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) + 200))
                (*(longlong *)(param_2 + 4),&CmdDescSendStatus,4,local_res10);
      if (local_res10[0] >> 0x13 != 0) {
        SdbusCardErrorToNtStatus(local_res10[0] >> 0x13,local_res18);
        iVar10 = local_res18[0];
        goto LAB_14000d001;
      }
      if (param_2[0xf] != 1) {
        *param_2 = 0x12;
        goto LAB_14000cffe;
      }
      goto LAB_14000cfca;
    }
    if (param_2[0xf] == 1) {
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x909) = 0;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(*(longlong *)(param_2 + 4) + 0x3a8,&local_58);
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x908) = 0;
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
    }
    puVar3 = param_2 + 0x17;
    puVar3[0] = 0;
    puVar3[1] = 0;
    param_2[0x19] = 0;
    param_2[0x1a] = 0;
    bVar8 = SdbusComputeResponseLength((longlong)puVar1);
    *(byte *)(param_2 + 0x1b) = bVar8;
    if (bVar8 != 0) {
      uVar14 = (ulonglong)bVar8;
      puVar18 = puVar3;
      (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) + 200))
                (*(longlong *)(param_2 + 4),puVar1);
    }
    DebugDumpSdResponse((byte *)puVar1,puVar3,uVar14,puVar18);
    if (param_2[0xf] == 1) {
      SdbusCommandEngineDisablePolling((longlong)param_1,(longlong)param_2);
      goto LAB_14000d00a;
    }
    *param_2 = 0x12;
LAB_14000cc7c:
    iVar10 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x28) +
                         0x118))();
    if (iVar10 == -0x3fffffea) {
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x909) = 1;
      if (((char)param_2[0x16] != '\0') && (*param_1 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xd) = 1;
        param_1[4] = SdEnablePollingCmdTimeout;
      }
    }
    else {
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x909) = 0;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(*(longlong *)(param_2 + 4) + 0x3a8,&local_58);
      *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x908) = 0;
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
      SdbusCommandEngineDisablePolling((longlong)param_1,(longlong)param_2);
      if ((-1 < iVar10) && (*(char *)(*(longlong *)(*(longlong *)(param_2 + 4) + 8) + 0x45) == '\n')
         ) {
        *param_2 = 0x13;
        goto LAB_14000cffe;
      }
    }
  }
LAB_14000d001:
  if (iVar10 == -0x3fffffea) {
    return -0x3fffffea;
  }
LAB_14000d00a:
  if ((Microsoft_Windows_SdbusEnableBits & 0x10) != 0) {
    in_stack_ffffffffffffff78 = CONCAT71((int7)(in_stack_ffffffffffffff78 >> 8),(char)param_2[0xc]);
    McTemplateK0iuix_EtwWriteTransfer
              ((ulonglong)param_2[1],&SdbusCommandCompleted,uVar14,
               *(undefined8 *)(*(longlong *)(param_2 + 4) + 0x208),(char)param_2[0xc],
               (char)param_2[1],(char)param_2[0xb] * (char)*(undefined2 *)((longlong)param_2 + 0x2e)
              );
  }
  SdbusTelemetryCollectPerfData((longlong)param_2);
  if (((-1 < iVar10) && (*(char *)((longlong)param_2 + 0x59) == '\0')) &&
     (lVar4 = *(longlong *)(param_2 + 4), *(char *)(lVar4 + 0x16a2) != '\0')) {
    lVar13 = *(longlong *)(lVar4 + 8);
    *(undefined1 *)(lVar4 + 0x16a2) = 0;
    *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x165d) = 1;
    *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x165b) = 0;
    *(undefined1 *)(*(longlong *)(param_2 + 4) + 0x1658) = 0;
    *(undefined4 *)(*(longlong *)(param_2 + 4) + 0x1678) = 200000;
    uVar9 = *(uint *)(lVar13 + 0x13c);
    *(undefined4 *)(*(longlong *)(param_2 + 4) + 0x1684) =
         *(undefined4 *)(*(longlong *)(lVar13 + 0x170) + 4 + (ulonglong)uVar9 * 0x14);
    lVar4 = *(longlong *)(param_2 + 4);
    *(undefined4 *)(lVar4 + 0x114c) = *(undefined4 *)(lVar4 + 0x1684);
    SdbusFxComponentActive(lVar13,0,lVar4,(ulonglong)uVar9 * 5);
    SdbusActivateSocket(*(longlong *)(param_2 + 4),5,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 4) + 0x10) + 0x40),
                        (undefined *)0x0,in_stack_ffffffffffffff78);
    SdbusActivateSocket(*(longlong *)(param_2 + 4),4,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 4) + 0x10) + 0x40),
                        SdbusNvReinitCompletion,in_stack_ffffffffffffff78);
  }
  *(undefined8 *)(param_2 + 0x11) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_2 + 0x13) = *(undefined8 *)(param_2 + 0xe);
  param_2[0x15] = param_2[0x10];
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  return iVar10;
}



===== SdbusCompletePStateRequest @ 14000d15c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusCompletePStateRequest(longlong param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ushort uVar5;
  int iVar6;
  longlong lVar7;
  undefined2 local_res10 [4];
  
  uVar1 = *(undefined4 *)(param_1 + 0x13c);
  *(uint *)(param_1 + 0x13c) = param_2;
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x140) = uVar1;
  local_res10[0] = 0;
  uVar4 = 0x2000000;
  lVar7 = param_1;
  SdbusDebugPrint(0x2000000,"fdoext %p P-state completed: P-state = %u\n",param_1,(ulonglong)param_2
                 );
  LOCK();
  *(longlong *)(param_1 + 0x15d8) = *(longlong *)(param_1 + 0x15d8) + 1;
  UNLOCK();
  if ((Microsoft_Windows_SdbusEnableBits & 0x10) != 0) {
    McTemplateK0iqx_EtwWriteTransfer
              (uVar4,&SdbusPStateCompletion,lVar7,*(undefined8 *)(param_1 + 0x120),
               (char)*(undefined4 *)(param_1 + 0x13c),(char)*(undefined8 *)(param_1 + 0x15d8));
  }
  SdbusUpdateAllChildrenCrashdumpReadyState(param_1);
  lVar7 = *(longlong *)(param_1 + 1000);
  SdbusAddDbgLog(lVar7,0x50536370,(ulonglong)*(uint *)(param_1 + 0x13c),
                 (ulonglong)*(uint *)(param_1 + 0x140),(ulonglong)*(uint *)(param_1 + 0x16c));
  if ((*(char *)(param_1 + 0x45) - 7U & 0xfb) != 0) {
    *(undefined4 *)(lVar7 + 0x1680) = *(undefined4 *)(lVar7 + 0x1684);
    *(undefined4 *)(lVar7 + 0x1684) =
         *(undefined4 *)
          (*(longlong *)(param_1 + 0x170) + 4 + (ulonglong)*(uint *)(param_1 + 0x13c) * 0x14);
  }
  if ((0 < *(int *)(param_1 + 0x42c)) && (*(int *)(lVar7 + 0x1678) != 0)) {
    (**(code **)(*(longlong *)(*(longlong *)(lVar7 + 8) + 0x28) + 0x158))
              (lVar7,*(undefined4 *)(lVar7 + 0x1684),*(int *)(lVar7 + 0x1678),lVar7 + 0x167c,
               local_res10);
  }
  if (*(char *)(param_1 + 0x45) == '\x06') {
    if (*(char *)(param_1 + 0x46) == '\x01') {
      uVar5 = 0x100;
      uVar1 = SdbusReadRegisterUlong(lVar7,0x100);
      *(undefined4 *)(lVar7 + 0xb4) = uVar1;
      uVar1 = SdbusReadRegisterUlong(lVar7,uVar5);
      *(undefined4 *)(lVar7 + 0xb4) = uVar1;
      if (*(longlong *)(param_1 + 0x170) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x16c) + -1;
      }
      if (*(int *)(param_1 + 0x13c) != iVar2) {
        PoFxSetComponentLatency(*(undefined8 *)(param_1 + 0x120),0,0);
        PoFxSetComponentResidency(*(undefined8 *)(param_1 + 0x120),0,0);
      }
    }
  }
  else if (*(char *)(param_1 + 0x45) == '\n') {
    *(undefined1 *)(lVar7 + 0x16a1) = 1;
  }
  if (((*(int *)(param_1 + 0x108) != 4) || (*(int *)(param_1 + 0x104) != 1)) ||
     (*(int *)(lVar7 + 0x3c0) == 6)) {
    if (*(int *)(lVar7 + 0x3c0) == 6) {
      if (*(longlong *)(param_1 + 0x170) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(param_1 + 0x16c) - 1;
      }
      if (*(uint *)(param_1 + 0x13c) < uVar3) {
        SdbusSetPStateTimer(param_1);
      }
    }
    if ((*(char *)(param_1 + 0x45) == '\x06') && (*(char *)(param_1 + 0x46) == '\x01')) {
      iVar2 = *(int *)(param_1 + 0x13c);
      *(int *)(&NvSdmmcPStateCurrent + (ulonglong)(*(int *)(lVar7 + 0x1f8) + 0x88000000U >> 9) * 4)
           = iVar2;
      if (*(longlong *)(param_1 + 0x170) != 0) {
        iVar6 = *(int *)(param_1 + 0x16c) + -1;
      }
      if (iVar2 == iVar6) {
        SdbusCancelPStateTimer(param_1);
        PoFxSetComponentLatency(*(undefined8 *)(param_1 + 0x120),0,10);
        PoFxSetComponentResidency(*(undefined8 *)(param_1 + 0x120),0,10);
      }
    }
  }
  return 0;
}



===== SdbusErrorRecoveryReinitCompletion @ 14000d3f0 =====

void SdbusErrorRecoveryReinitCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  LOCK();
  *(int *)(param_1 + 0x2a38) = *(int *)(param_1 + 0x2a38) + 1;
  UNLOCK();
  SdbusFxComponentIdle(*(longlong *)(param_1 + 8),param_2,param_3,param_4);
  uVar1 = KeQueryPerformanceCounter(0);
  *(undefined8 *)(param_1 + 0x2a48) = uVar1;
  *(undefined1 *)(param_1 + 0x16a4) = 0;
  if (((*(int *)(param_1 + 0x1120) == 3) && (*(char *)(param_1 + 0x16e8) != '\0')) &&
     ((int)param_3 < 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x15a,*(undefined8 *)(param_1 + 0x568),param_1,0,0);
  }
  return;
}



===== SdbusErrorRecoveryWorker @ 14000d478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdbusErrorRecoveryWorker
              (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  uint uVar10;
  longlong lVar11;
  char local_res8 [8];
  char local_res10 [8];
  int local_res18 [2];
  undefined8 in_stack_ffffffffffffff98;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  lVar11 = param_1[1];
  lVar3 = param_1[2];
  lVar4 = *param_1;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((lVar11 == 0) || (*(int *)(lVar11 + 0x20) != 1)) ||
     (bVar5 = true, *(int *)(lVar11 + 0x38) != 1)) {
    bVar5 = false;
  }
  bVar1 = *(byte *)(lVar3 + 0x284);
  if (bVar1 < 7) {
    if (bVar1 == 6) {
      if (*(int *)(lVar11 + 200) - 2U < 2) {
        if ((*(int *)(lVar3 + 0x23c) != 3) || ((*(uint *)(lVar3 + 0x288) & 0x40000270) == 0)) {
LAB_14000d805:
          *(undefined4 *)(lVar3 + 0x1d4) = *(undefined4 *)(lVar4 + 0x1724);
          *(undefined1 *)(lVar3 + 0x284) = 7;
          return -0x3fffffea;
        }
        SdbusDebugPrint(0x8000,"ErrorRecoveryWorker: Sending CMD12",param_3,param_4);
        SdbusAddDbgLog(lVar4,0x53544f50,0xc,0,0xc0);
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xc0))
                          (lVar4,&CmdDescStopTransmission,0,0xc0);
        if (-1 < iVar7) goto LAB_14000d805;
      }
      else {
        uVar10 = *(byte *)(lVar11 + 0xc4) | 0x80000c00;
        SdbusAddDbgLog(lVar4,0x41425254,0x34,(ulonglong)uVar10,0xc0);
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xc0))
                          (lVar4,&CmdDescWriteIoDirect,uVar10,0xc0);
        if (-1 < iVar7) {
          uVar6 = *(undefined4 *)(lVar4 + 0x172c);
LAB_14000d57d:
          *(undefined4 *)(lVar3 + 0x1d4) = uVar6;
LAB_14000d583:
          *(undefined1 *)(lVar3 + 0x284) = 8;
          return -0x3fffffea;
        }
      }
    }
    else {
      if (bVar1 == 0) {
        SdbusDisableEvents(lVar4,(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x380) != 0) - 2);
        lVar11 = lVar4;
        SdbusAddDbgLog(lVar4,0x45725265,(ulonglong)*(uint *)(param_1 + 7),lVar4,0);
        *(int *)(lVar3 + 0x288) = (int)param_1[7];
        SdbusDebugPrint(0x8000,"ErrorRecoveryWorker: err evts=0x%08x",
                        (ulonglong)*(uint *)(param_1 + 7),lVar11);
        if ((*(uint *)(param_1 + 7) & 0x20f) != 0) {
          *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) & 0xfffffdf0;
          *(undefined1 *)(lVar3 + 0x284) = 1;
LAB_14000d655:
          *(undefined4 *)(lVar4 + 0x174c) = 0;
          return -0x3fffffea;
        }
LAB_14000d693:
        *(undefined1 *)(lVar3 + 0x284) = 2;
        return -0x3fffffea;
      }
      if (bVar1 == 1) {
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x48))
                          (lVar3 + 0x1d0,lVar4,1);
        if (-1 < iVar7) {
          *(undefined4 *)(lVar4 + 0x174c) = 0;
          goto LAB_14000d693;
        }
      }
      else {
        if (bVar1 == 2) {
          if (((*(uint *)(param_1 + 7) & 0x40000270) != 0) || ((int)param_1[5] == 0x13)) {
            *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) & 0xbffffd8f;
            *(undefined1 *)(lVar3 + 0x284) = 3;
            goto LAB_14000d655;
          }
          goto LAB_14000d583;
        }
        if (bVar1 == 3) {
          if (*(char *)(*(longlong *)(lVar4 + 8) + 0x45) == '\v') {
            if (*(char *)(lVar4 + 0x24) == '\0') {
              if ((*(ulonglong *)(lVar3 + 0x278) <= _DAT_fffff78000000008) &&
                 (_DAT_fffff78000000008 - *(ulonglong *)(lVar3 + 0x278) < 0x500)) {
                *(undefined4 *)(lVar3 + 0x1d4) = 0x80;
                *(undefined1 *)(lVar3 + 0x284) = 4;
                return -0x3fffffea;
              }
            }
            else {
              KeStallExecutionProcessor(0x80);
            }
          }
          *(undefined1 *)(lVar3 + 0x284) = 4;
        }
        else if (bVar1 != 4) {
          if (bVar1 == 5) {
            uVar10 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xb8))(lVar4);
            if (uVar10 != 0) {
              (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xf8))(lVar4,0x1000);
              SdbusControllerErrorToNtStatus(uVar10,(int *)((longlong)param_1 + 0x3c));
            }
            *(undefined4 *)(lVar4 + 0x174c) = 0;
            if ((lVar11 != 0) && ((*(uint *)(lVar3 + 0x280) & 1) == 0)) {
              *(undefined1 *)(lVar3 + 0x284) = 6;
              return -0x3fffffea;
            }
            uVar6 = *(undefined4 *)(lVar4 + 0x1700);
            goto LAB_14000d57d;
          }
          goto LAB_14000d853;
        }
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x48))
                          (lVar3 + 0x1d0,lVar4,2);
        if (-1 < iVar7) {
          *(undefined4 *)(lVar4 + 0x174c) = 0;
          *(undefined1 *)(lVar3 + 0x284) = 5;
          return -0x3fffffea;
        }
      }
    }
    if (iVar7 == -0x3fffffea) {
      return -0x3fffffea;
    }
LAB_14000d858:
    if (*(char *)(lVar4 + 0x16e8) == '\0') {
      return iVar7;
    }
    if (0 < *(int *)(param_1[1] + 0xc0)) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x15a,param_1,lVar4,(longlong)iVar7,*(undefined1 *)(lVar3 + 0x284));
    }
    return iVar7;
  }
  uVar9 = 7;
  if (bVar1 == 7) {
    local_res8[0] = '\0';
    local_res10[0] = '\0';
    (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xd0))
              (lVar4,local_res8,local_res10);
    if (((local_res8[0] == '\0') && (local_res10[0] == '\0')) || (0x31 < *(byte *)(lVar3 + 0x286)))
    {
      uVar9 = 8;
    }
    else {
      *(undefined4 *)(lVar3 + 0x1d4) = 15000;
      *(byte *)(lVar3 + 0x286) = *(byte *)(lVar3 + 0x286) + 1;
    }
    *(undefined1 *)(lVar3 + 0x284) = uVar9;
    return -0x3fffffea;
  }
  if (bVar1 != 8) {
    if (bVar1 == 9) {
      cVar2 = *(char *)(*(longlong *)(lVar4 + 8) + 0x45);
      if (((cVar2 - 7U & 0xfa) == 0) && (cVar2 != '\b')) {
        if (*(char *)(lVar4 + 0x165e) == '\0') {
          if ((*(char *)(lVar4 + 0x165d) != '\0') || (*(char *)(lVar4 + 0x1659) != '\0')) {
            *(undefined1 *)(lVar4 + 0x1699) = 0;
            *(undefined1 *)(lVar3 + 0x28c) = 1;
          }
        }
        else {
          *(undefined1 *)(lVar4 + 0x16a4) = 1;
          SdbusFxComponentActive(*(longlong *)(lVar4 + 8),0,param_3,param_4);
          *(undefined1 *)(lVar4 + 0x1699) = 0;
          SdbusActivateSocket(lVar4,0x13,param_1[1],SdbusErrorRecoveryReinitCompletion,
                              in_stack_ffffffffffffff98);
        }
      }
LAB_14000d9a1:
      (**(code **)(*(longlong *)(*(longlong *)(*param_1 + 8) + 0x28) + 0x120))();
      return 0;
    }
    if (bVar1 == 10) goto LAB_14000d9a1;
    if (bVar1 == 0xb) {
      *(undefined1 *)(lVar3 + 0x284) = 0xc;
      if (((*(char *)(lVar4 + 0x1659) != '\0') || (*(char *)(lVar4 + 0x165d) != '\0')) ||
         (*(char *)(lVar4 + 0x165e) != '\0')) {
        *(undefined8 *)(lVar3 + 0x1d0) = 0x1000000;
        local_res18[0] = 0;
        iVar7 = SdbusRequestPState(*(longlong *)(lVar4 + 8),local_res18);
        if (iVar7 == -0x3fffffea) {
          return -0x3fffffea;
        }
        *(undefined4 *)(lVar3 + 0x1d0) = 0;
      }
LAB_14000d8f0:
      *(undefined1 *)(lVar4 + 0x16a4) = 1;
      SdbusFxComponentActive(*(longlong *)(lVar4 + 8),0,param_3,param_4);
      SdbusActivateSocket(lVar4,5,param_1[1],(undefined *)0x0,in_stack_ffffffffffffff98);
      SdbusActivateSocket(lVar4,4,param_1[1],SdbusErrorRecoveryReinitCompletion,
                          in_stack_ffffffffffffff98);
      return 0;
    }
    if (bVar1 == 0xc) goto LAB_14000d8f0;
LAB_14000d853:
    iVar7 = -0x3fffffff;
    goto LAB_14000d858;
  }
  (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0x120))(lVar4);
  if (bVar5) {
    if (((SdResetEmmcOnError != 0) && (0 < *(int *)(lVar11 + 0xc0))) && ((int)param_1[5] == 0x13)) {
      if ((*(uint *)(lVar3 + 0x288) & 0x1c006e) != 0) {
        *(undefined1 *)(lVar3 + 0x284) = 9;
        goto LAB_14000da70;
      }
      cVar2 = *(char *)(*(longlong *)(lVar4 + 8) + 0x45);
      if (cVar2 == '\a') {
LAB_14000da28:
        *(undefined1 *)(lVar3 + 0x284) = 0xc;
      }
      else {
        if (cVar2 == '\n') {
          *(undefined1 *)(lVar4 + 0x1699) = 0;
        }
        else if ((cVar2 == '\v') || (cVar2 == '\f')) goto LAB_14000da28;
LAB_14000da60:
        *(undefined1 *)(lVar3 + 0x284) = 0xb;
      }
      goto LAB_14000da70;
    }
    if (((*(char *)(*(longlong *)(lVar4 + 8) + 0x45) == '\n') && (*(int *)(lVar4 + 0x117c) == 2)) &&
       (((int)param_1[5] == 0x13 && ((*(uint *)(lVar3 + 0x288) & 0x20011) != 0))))
    goto LAB_14000da60;
  }
  *(undefined1 *)(lVar3 + 0x284) = 10;
LAB_14000da70:
  *(undefined4 *)(param_1 + 7) = 0;
  *(undefined8 *)(lVar3 + 0x48) = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar4 + 0x18);
  uVar8 = 0xffffffff;
  (**(code **)(*(longlong *)(*(longlong *)(lVar4 + 8) + 0x28) + 0xf8))(lVar4);
  SdbusWorkerClearHpi(lVar3,uVar8,param_3,param_4);
  if (((*(uint *)(lVar4 + 0x20) & 0x200000) == 0) || (uVar10 = 0x117d, *(int *)(lVar4 + 0x38) != 0))
  {
    uVar10 = 0x107d;
  }
  SdbusEnableEvents(lVar4,uVar10);
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
  *(undefined4 *)(lVar3 + 0x1d4) = *(undefined4 *)(lVar4 + 0x1700);
  return -0x3fffffea;
}



===== SdbusExecuteWorkSynchronousWithParameter @ 14000db6c =====

ulonglong SdbusExecuteWorkSynchronousWithParameter
                    (int param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  char *pcVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res10 = (longlong *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  plVar4 = param_4;
  pcVar2 = SdbusDbgLookupString((int *)&SdbusDbgWPFunctionStringMap,param_1);
  SdbusDebugPrint(0x100000,"ExecuteWorkSynchronous: %s",pcVar2,plVar4);
  KeInitializeEvent(&local_28,0,0);
  uVar3 = SdbusBuildWorkPacket
                    (*(longlong *)(param_2 + 8) + 0x4e0,param_1,param_2,param_3,
                     SdbusSynchronousWorkCompletion,&local_28,&local_res10);
  plVar4 = local_res10;
  if (-1 < (int)uVar3) {
    if (param_4 != (longlong *)0x0) {
      local_res10[0xb] = *param_4;
    }
    SdbusWorkerQueuePacket(param_2 + 0x3a8,local_res10,0,2);
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar1 = *(uint *)(plVar4 + 10);
    if (param_4 != (longlong *)0x0) {
      *param_4 = plVar4[0xb];
    }
    ExFreeToLookasideListEx(*(longlong *)(param_2 + 8) + 0x4e0,plVar4);
    uVar3 = (ulonglong)uVar1;
  }
  return uVar3;
}



===== SdbusFxComponentActive @ 14000dca4 =====

void SdbusFxComponentActive(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(longlong *)(param_1 + 0x120) != 0) {
    SdbusDebugPrint(0x10,"fdo %p SdbusFxComponentActive",*(undefined8 *)(param_1 + 0x68),param_4);
    SdbusAddFxDbgLog(param_1,0x41635265,(ulonglong)*(uint *)(param_1 + 300),(ulonglong)param_2,
                     (longlong)*(int *)(param_1 + 0x108));
    LOCK();
    *(int *)(param_1 + 0x156c) = *(int *)(param_1 + 0x156c) + 1;
    UNLOCK();
    PoFxActivateComponent(*(undefined8 *)(param_1 + 0x120),0,param_2);
  }
  return;
}



===== SdbusFxComponentIdle @ 14000dd28 =====

void SdbusFxComponentIdle(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(longlong *)(param_1 + 0x120) != 0) {
    SdbusDebugPrint(0x10,"fdo  %p SdbusFxComponentIdle",*(undefined8 *)(param_1 + 0x68),param_4);
    SdbusAddFxDbgLog(param_1,0x49645265,(ulonglong)*(uint *)(param_1 + 300),
                     (ulonglong)*(uint *)(param_1 + 0x134),(longlong)*(int *)(param_1 + 0x108));
    LOCK();
    *(int *)(param_1 + 0x1570) = *(int *)(param_1 + 0x1570) + 1;
    UNLOCK();
    PoFxIdleComponent(*(undefined8 *)(param_1 + 0x120),0,0);
  }
  return;
}



===== SdbusGetMiniprocRoutine @ 14000dda4 =====

undefined * SdbusGetMiniprocRoutine(int param_1)

{
  if (param_1 < 0x1e) {
    if (param_1 == 0x1d) {
      return SdbusBusWidthWorker;
    }
    if (param_1 < 0x10) {
      if (param_1 != 0xf) {
        if (param_1 < 9) {
          if (param_1 != 8) {
            if (param_1 == 1) {
              return SdbusStopSocketWorker;
            }
            if (param_1 == 2) {
              return SdbusSocketResetWorker;
            }
            if (((param_1 == 3) || (param_1 == 4)) || (param_1 == 5)) {
              return SdbusSetPowerWorker;
            }
            if (param_1 == 6) {
              return SdbusActivateSocketWorker;
            }
            if (param_1 != 7) {
              return (undefined *)0x0;
            }
          }
          return SdbusGetSocketCardDataWorker;
        }
        if (param_1 == 9) {
          return SdbusReadDeviceConfigWorker;
        }
        if (param_1 == 10) {
          return SdbusDetectFrequencyWorker;
        }
        if (param_1 == 0xb) {
          return SdbusDetectBusWidthWorker;
        }
        if ((param_1 == 0xc) || (param_1 == 0xd)) {
          return SdbusInitializeCardWorker;
        }
        if (param_1 != 0xe) {
          return (undefined *)0x0;
        }
      }
      return SdbusSelectCardWorker;
    }
    if (param_1 < 0x17) {
      if (param_1 == 0x16) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x10) {
        return SdbusStartFunctionWorker;
      }
      if (param_1 == 0x11) {
        return SdbusStopFunctionWorker;
      }
      if (param_1 == 0x12) {
        return SdbusBasicCommandWorker;
      }
      if (param_1 == 0x13) {
        return SdbusDataCommandWorker;
      }
      if (param_1 == 0x14) {
        return SdbusEraseCommandWorker;
      }
      if (param_1 == 0x15) {
        return SdbusQueryCardInterruptsWorker;
      }
    }
    else {
      if (param_1 == 0x17) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x18) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x19) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x1a) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x1b) {
        return SdbusBusClockWorker;
      }
      if (param_1 == 0x1c) {
        return SdbusBusWidthWorker;
      }
    }
  }
  else {
    if (param_1 < 0x2d) {
      if (param_1 == 0x2c) {
        return SdbusFunctionBlockLengthWorker;
      }
      if (param_1 < 0x26) {
        if (param_1 != 0x25) {
          if (param_1 == 0x1e) {
            return SdbusBusWidthWorker;
          }
          if (param_1 == 0x1f) {
            return SdbusHighSpeedDetectionWorker;
          }
          if (param_1 == 0x20) {
            return SdbusHighSpeedWorker;
          }
          if (param_1 == 0x21) {
            return SdbusHS400Worker;
          }
          if (param_1 == 0x22) {
            return SdbusHS400TuningWorker;
          }
          if ((param_1 != 0x23) && (param_1 != 0x24)) {
            return (undefined *)0x0;
          }
        }
      }
      else if (param_1 != 0x26) {
        if (param_1 == 0x27) {
          return SdbusFunctionBlockLengthWorker;
        }
        if (param_1 == 0x28) {
          return SdbusFunctionBlockLengthWorker;
        }
        if (param_1 == 0x29) {
          return SdbusFunctionBlockLengthWorker;
        }
        if (param_1 == 0x2a) {
          return SdbusFunctionBlockLengthWorker;
        }
        if (param_1 == 0x2b) {
          return SdbusFunctionBlockLengthWorker;
        }
        return (undefined *)0x0;
      }
      return SdbusIntEnableWorker;
    }
    if (param_1 < 0x34) {
      if (param_1 != 0x33) {
        if ((param_1 == 0x2d) || (param_1 == 0x2e)) {
          return SdbusBusInterfaceControlWorker;
        }
        if (param_1 == 0x2f) {
          return SdbusSdioResetWorker;
        }
        if (param_1 == 0x30) {
          return SdbusMmcSleepWorker;
        }
        if (param_1 == 0x31) {
          return SdbusMmcWakeWorker;
        }
        if (param_1 != 0x32) {
          return (undefined *)0x0;
        }
      }
      return SdbusArmWakeInterrupt;
    }
    if (param_1 == 0x34) {
      return SdbusMmcSoftResetWorker;
    }
    if (param_1 == 0x35) {
      return SdbusMmcSetWriteGroupDef;
    }
    if (param_1 == 0x36) {
      return SdbusMmcCheckWriteCacheWorker;
    }
    if (param_1 == 0x37) {
      return SdbusMmcEnableWriteCacheWorker;
    }
    if (param_1 == 0x38) {
      return SdbusMmcFlushWriteCacheWorker;
    }
    if (param_1 == 0x39) {
      return Pl180ArmWakeInterrupt;
    }
  }
  return (undefined *)0x0;
}



===== SdbusInitializeWorkPacket @ 14000e03c =====

void SdbusInitializeWorkPacket
               (undefined8 *param_1,int param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined *puVar1;
  
  if (*(char *)((longlong)param_1 + 0x82) == '\0') {
    memset(param_1,0,0x98);
  }
  else {
    memset(param_1,0,0x98);
    *(undefined1 *)((longlong)param_1 + 0x82) = 1;
  }
  *(int *)(param_1 + 5) = param_2;
  puVar1 = SdbusGetMiniprocRoutine(param_2);
  *(undefined4 *)(param_1 + 7) = 0;
  param_1[6] = puVar1;
  param_1[8] = param_5;
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[9] = param_6;
  *(undefined4 *)((longlong)param_1 + 0x3c) = 0xc0000185;
  return;
}



===== SdbusNvReinitCompletion @ 14000e0d0 =====

void SdbusNvReinitCompletion
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (param_2 == 0) {
    lVar2 = *(longlong *)(param_1 + 8);
    lVar3 = 0;
    uVar4 = param_3;
  }
  else {
    uVar4 = param_3;
    cVar1 = KeGetCurrentIrql();
    if (cVar1 != '\0') {
      SdbusFxComponentIdle(*(longlong *)(param_1 + 8),param_2,uVar4,param_4);
      *(undefined4 *)(param_1 + 0x298) = 0x37;
      IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x290),SdbusSystemPacketWorker,1,param_1);
      goto LAB_14000e153;
    }
    param_4 = 0;
    uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x40);
    lVar3 = param_1;
    SdbusExecuteWorkSynchronousWithParameter(0x37,param_1,uVar4,(longlong *)0x0);
    lVar2 = *(longlong *)(param_1 + 8);
  }
  SdbusFxComponentIdle(lVar2,lVar3,uVar4,param_4);
LAB_14000e153:
  *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x1f8) = 1;
  if (((*(int *)(param_1 + 0x1120) == 3) && (*(char *)(param_1 + 0x16e8) != '\0')) &&
     ((int)param_3 < 0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x15a,*(longlong *)(param_1 + 0x568),param_1,
                 *(undefined8 *)(*(longlong *)(param_1 + 0x568) + 0x90),0);
  }
  return;
}



===== SdbusRequestPState @ 14000e1b0 =====

int SdbusRequestPState(longlong param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  IMAGE_DOS_HEADER *pIVar12;
  uint *puVar13;
  ulonglong uVar14;
  int local_res8 [2];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  uVar5 = (ulonglong)*(uint *)(param_1 + 0x13c);
  local_50 = 0;
  pIVar12 = &IMAGE_DOS_HEADER_140000000;
  bVar3 = false;
  iVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x170);
  uVar11 = *(uint *)(*(longlong *)(param_1 + 1000) + 0x1188);
  local_58 = 0;
  local_res8[0] = -0x3fffffff;
  if ((*(char *)(param_1 + 0x45) == '\x06') && (*(char *)(param_1 + 0x46) == '\x01')) {
    for (uVar8 = 0; uVar8 < 4; uVar8 = uVar8 + 1) {
      if ((&NvSdmmcTuningInProgress)[uVar8] != '\0') {
        bVar3 = true;
        break;
      }
    }
  }
  for (uVar8 = 0; uVar8 < *(uint *)(param_1 + 0x3e4); uVar8 = uVar8 + 1) {
    pIVar12 = *(IMAGE_DOS_HEADER **)(param_1 + 1000 + (ulonglong)uVar8 * 8);
    if ((*(longlong *)(pIVar12[10].e_program + 0x28) != 0) && (pIVar12[0xc].e_magic[1] != '\0')) {
      return -0x7fffffef;
    }
  }
  uVar14 = *(ulonglong *)(param_1 + 0x160);
  uVar2 = *(ulonglong *)(param_1 + 0x158);
  *(undefined8 *)(param_1 + 0x160) = 0;
  if (uVar2 < uVar14) {
    uVar14 = uVar2;
  }
  if (uVar14 == 0) {
    uVar8 = 0;
  }
  else {
    uVar6 = (uVar2 * 100) / uVar14;
    uVar8 = (uint)(10000 / uVar6);
    pIVar12 = (IMAGE_DOS_HEADER *)(10000 % uVar6);
  }
  local_48 = KeQueryInterruptTimePrecise(&local_58,pIVar12);
  if ((((*(char *)(param_1 + 0x45) == '\x06') && (*(char *)(param_1 + 0x46) == '\x01')) &&
      (*(char *)(param_1 + 0x564) != '\0')) || (*(uint *)(param_1 + 0x16c) < 2)) goto LAB_14000e543;
  if (bVar3) {
    uVar11 = -(uint)(*(longlong *)(param_1 + 0x170) != 0) & *(uint *)(param_1 + 0x16c) - 1;
    *(uint *)(param_1 + 0x144) = uVar11;
    if ((uVar11 == *(uint *)(param_1 + 0x13c)) && (param_2 == (int *)0x0)) goto LAB_14000e52f;
  }
  else if (param_2 == (int *)0x0) {
    puVar13 = (uint *)(param_1 + 0x144);
    if (*(uint *)(lVar1 + 0xc + uVar5 * 0x14) < uVar8) {
      uVar9 = *(int *)(lVar1 + uVar5 * 0x14) - 1;
      *puVar13 = uVar9;
      if ((*(char *)(param_1 + 0x45) == '\n') &&
         (*(char *)(*(longlong *)(param_1 + 1000) + 0x165b) != '\0')) {
        uVar11 = uVar11 * 2;
      }
      if (uVar11 < *(uint *)(*(longlong *)(param_1 + 0x170) + 4 + (ulonglong)uVar9 * 0x14)) {
LAB_14000e52f:
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x13c);
        goto LAB_14000e543;
      }
    }
    else {
      if (*(uint *)(lVar1 + 0x10 + uVar5 * 0x14) <= uVar8) {
        *puVar13 = *(uint *)(param_1 + 0x13c);
        goto LAB_14000e52f;
      }
      *puVar13 = *(int *)(lVar1 + uVar5 * 0x14) + 1;
    }
  }
  else {
    if (*param_2 == *(int *)(param_1 + 0x13c)) goto LAB_14000e52f;
    *(int *)(param_1 + 0x144) = *param_2;
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0x3e4) != 0) {
    do {
      for (lVar7 = *(longlong *)(*(longlong *)(param_1 + 1000 + uVar6 * 8) + 0x10); lVar7 != 0;
          lVar7 = *(longlong *)(lVar7 + 0x18)) {
        lVar7 = *(longlong *)(lVar7 + 0x40);
        *(undefined1 *)(lVar7 + 0x5f0) = 0;
      }
      uVar11 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar11;
    } while (uVar11 < *(uint *)(param_1 + 0x3e4));
  }
  puVar13 = (uint *)(param_1 + 0x144);
  iVar4 = PoFxPowerControl(*(undefined8 *)(param_1 + 0x120),&GUID_SDBUS_PSTATE_REQUEST,puVar13,4,
                           local_res8,4,&local_50);
  if (-1 < iVar4) {
    uVar10 = 0x2000000;
    lVar7 = param_1;
    SdbusDebugPrint(0x2000000,
                    "fdoext %p P-state change: current = %u, requested = %u, active percent = %u%%, active time = %ums, sample duration = %ums\n"
                    ,param_1,(ulonglong)*(uint *)(lVar1 + uVar5 * 0x14));
    LOCK();
    *(longlong *)(param_1 + 0x15d0) = *(longlong *)(param_1 + 0x15d0) + 1;
    UNLOCK();
    if ((Microsoft_Windows_SdbusEnableBits & 0x10) != 0) {
      McTemplateK0iqx_EtwWriteTransfer
                (uVar10,&SdbusPStateRequest,lVar7,*(undefined8 *)(param_1 + 0x120),(char)*puVar13,
                 (char)*(undefined8 *)(param_1 + 0x15d0));
    }
    iVar4 = -0x3fffffea;
    if (-1 < local_res8[0]) {
      uVar10 = SdbusCompletePStateRequest(param_1,*puVar13);
      iVar4 = (int)uVar10;
    }
  }
  SdbusAddDbgLog(*(longlong *)(param_1 + 1000),0x50735265,(ulonglong)*puVar13,
                 (ulonglong)*(uint *)(param_1 + 0x13c),(longlong)iVar4);
LAB_14000e543:
  if ((*(char *)(param_1 + 0x45) == '\x06') && (*(char *)(param_1 + 0x46) == '\x01')) {
    *(undefined4 *)
     (&NvSdmmcPStateRequested +
     (ulonglong)(*(int *)(*(longlong *)(param_1 + 1000) + 0x1f8) + 0x88000000U >> 9) * 4) =
         *(undefined4 *)(param_1 + 0x144);
  }
  if ((Microsoft_Windows_SdbusEnableBits & 0x10) != 0) {
    McTemplateK0iqqqqq_EtwWriteTransfer
              (uVar2 / 10000,uVar14 / 10000,(ulonglong)*(uint *)(param_1 + 0x144) * 5,
               *(undefined8 *)(param_1 + 0x120),(char)uVar8,(char)(uVar14 / 10000),
               (char)(uVar2 / 10000),
               (char)*(undefined4 *)
                      (*(longlong *)(param_1 + 0x170) + 4 +
                      (ulonglong)*(uint *)(param_1 + 0x13c) * 0x14),
               (char)*(undefined4 *)
                      (*(longlong *)(param_1 + 0x170) + 4 +
                      (ulonglong)*(uint *)(param_1 + 0x144) * 0x14));
  }
  *(undefined1 *)(param_1 + 0x168) = 0;
  if (*(longlong *)(param_1 + 0x150) != 0) {
    *(undefined8 *)(param_1 + 0x150) = local_48;
  }
  return iVar4;
}



===== SdbusRequiresUpperAddress @ 14000e620 =====

undefined1 SdbusRequiresUpperAddress(longlong param_1,char *param_2)

{
  char cVar1;
  
  if ((*(char *)(param_1 + 0x1161) == '\0') ||
     ((((cVar1 = *param_2, cVar1 != '\x11' && (cVar1 != '\x12')) && (cVar1 != '\x18')) &&
      (((cVar1 != '\x19' && (cVar1 != ' ')) && (cVar1 != '!')))))) {
    return 0;
  }
  return 1;
}



===== SdbusSetPStateTimer @ 14000e658 =====

void SdbusSetPStateTimer(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar2 = KeQueryInterruptTimePrecise(&local_res8);
  uVar3 = lVar2 - *(longlong *)(param_1 + 0x150);
  uVar4 = -(ulonglong)(uVar3 < *(ulonglong *)(param_1 + 0x148)) &
          *(ulonglong *)(param_1 + 0x148) - uVar3;
  uVar1 = KeQueryTimeIncrement();
  uVar3 = (ulonglong)uVar1;
  if (uVar1 <= uVar4) {
    uVar3 = uVar4;
  }
  if (*(ulonglong *)(param_1 + 0x148) <= uVar3) {
    uVar3 = *(ulonglong *)(param_1 + 0x148);
  }
  KeSetCoalescableTimer(param_1 + 0x178,-uVar3,0,0x32,param_1 + 0x1b8);
  return;
}



===== SdbusSetRetuningTimer @ 14000e6fc =====

void SdbusSetRetuningTimer(longlong param_1)

{
  SdbusDebugPrint(0x100000,"socket  %p SdbusWorkerSetRetuningTimer 0x%08x",
                  *(longlong *)(param_1 + 0x10),
                  (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x113c));
  KeSetTimer(param_1 + 0x290,(longlong)-*(int *)(*(longlong *)(param_1 + 0x10) + 0x113c),
             param_1 + 0x2d0);
  return;
}



===== SdbusStopSocketWorker @ 14000e760 =====

undefined8 SdbusStopSocketWorker(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    SdbusWorkerDisableIo(param_1);
  }
  else {
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== SdbusSynchronousWorkCompletion @ 14000e790 =====

void SdbusSynchronousWorkCompletion(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x50) = param_2;
  KeSetEvent(*(undefined8 *)(param_1 + 0x48),0,0);
  return;
}



===== SdbusUpdateAllChildrenCrashdumpReadyState @ 14000e7b8 =====

void SdbusUpdateAllChildrenCrashdumpReadyState(longlong param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x3e4) != 0) {
    do {
      for (lVar2 = *(longlong *)(*(longlong *)(param_1 + 1000 + (ulonglong)uVar3 * 8) + 0x10);
          lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x18)) {
        lVar2 = *(longlong *)(lVar2 + 0x40);
        if ((((SdForceCrashdumpNotReady != 0) || (*(int *)(param_1 + 0x108) != 1)) ||
            ((*(int *)(param_1 + 0x16c) != 0 && (*(int *)(param_1 + 0x13c) != 0)))) ||
           ((*(int *)(param_1 + 0x134) != 0 ||
            (uVar1 = 1, (*(int *)(lVar2 + 0x38) - 1U & 0xfffffffd) != 0)))) {
          uVar1 = 0;
        }
        *(undefined1 *)(lVar2 + 0x5f0) = uVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x3e4));
  }
  return;
}



===== SdbusWorkerClearHpi @ 14000e840 =====

void SdbusWorkerClearHpi(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(char *)(param_1 + 0x519) != '\0') &&
     (*(char *)(*(longlong *)(param_1 + 0x10) + 0x24) == '\0')) {
    KeAcquireInStackQueuedSpinLockAtDpcLevel(0,&local_28);
    if (*(char *)(param_1 + 0x562) != '\0') {
      *(undefined1 *)(param_1 + 0x562) = 0;
      SdbusDebugPrint(0x1000000,"Hpi triggered state cleared",param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0x563) = 0;
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  return;
}



===== SdbusWorkerDisableIo @ 14000e8c4 =====

void SdbusWorkerDisableIo(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(0,&local_28);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  return;
}



===== SdbusWorkerPrepareForNewPacket @ 14000e910 =====

void SdbusWorkerPrepareForNewPacket(longlong param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  
  param_2[2] = param_1;
  *(undefined8 *)(param_1 + 0x1c8) = *param_2;
  *(undefined8 *)(param_1 + 0x1a8) = 0;
  *(undefined8 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined1 *)(param_1 + 0x1dc) = 0;
  *(undefined8 **)(param_1 + 0x1c0) = param_2;
  uVar1 = SdbusValidateHpiCmd(param_1,(longlong)param_2);
  *(undefined1 *)(param_1 + 0x560) = uVar1;
  return;
}



===== SdbusWorkerPushEvents @ 14000e970 =====

void SdbusWorkerPushEvents(longlong param_1,uint param_2,uint param_3,char param_4,char param_5)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1 + 0x3a8,&local_28);
  SdbusWorkerPushEventsSpinlockHeld(param_1,param_2,param_3,param_4,param_5);
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  return;
}



===== SdbusWorkerPushEventsSpinlockHeld @ 14000e9fc =====

void SdbusWorkerPushEventsSpinlockHeld
               (longlong param_1,uint param_2,uint param_3,char param_4,char param_5)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  pcVar2 = SdbusDbgLookupString((int *)&SdbusDbgWorkerStateStringMap,*(int *)(param_1 + 0x3c0));
  uVar4 = *(undefined8 *)(param_1 + 0x568);
  pcVar3 = "wp  %p PushEvent entered: engine state=%s, pending evts=0x%08x, new evts=0x%08x";
  SdbusDebugPrint(0x100000,
                  "wp  %p PushEvent entered: engine state=%s, pending evts=0x%08x, new evts=0x%08x",
                  uVar4,pcVar2);
  SdbusDbgDumpEventString(param_2,pcVar3,uVar4,pcVar2);
  iVar1 = *(int *)(param_1 + 0x3c0);
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x48) & 0x2000) == 0) {
      SdbusDebugPrint(2,"we %p unexpected evts occurred: evts=0x%08x, err evts=0x%08x",
                      param_1 + 0x3a8,(ulonglong)param_2);
    }
  }
  else {
    *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | param_2;
    *(uint *)(param_1 + 0x3f4) = *(uint *)(param_1 + 0x3f4) | param_3;
    if ((*(char *)(param_1 + 0x24) == '\0') && (param_4 != '\0')) {
      if (iVar1 == 3) {
        KeCancelTimer(param_1 + 0x3f8);
      }
      else if (iVar1 != 4) {
        return;
      }
      *(undefined4 *)(param_1 + 0x3c0) = 1;
      if (param_5 == '\0') {
        KeInsertQueueDpc(param_1 + 0x478,*(undefined8 *)(param_1 + 0x568),0);
      }
    }
  }
  return;
}



===== SdbusWorkerQueuePacket @ 14000eb08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdbusWorkerQueuePacket(longlong param_1,longlong *param_2,undefined8 param_3,byte param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  char *local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar3 = (uint)param_4;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(0,&local_28);
  if ((param_4 == 1) && (iVar4 = SdbusWorkerValidateDeviceState(param_2[1]), iVar4 < 0)) {
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
    (*(code *)param_2[8])(param_2,iVar4);
    return iVar4;
  }
  local_38 = SdbusDbgLookupString((int *)&SdbusDbgWorkerStateStringMap,*(int *)(param_1 + 0x18));
  SdbusDebugPrint(0x100000,"wp  %p SdbusWorkerQueuePacket enter: irp %p engine state=%s",param_2,0);
  puVar7 = auStack_58;
  puVar8 = auStack_58;
  iVar4 = *(int *)(param_1 + 0x18);
  if (param_2 != (longlong *)0x0) {
    *(uint *)(param_2 + 3) = uVar3;
  }
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
    SdbusWorkerPrepareForNewPacket(param_1,param_2);
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
    (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x68))(*param_2,1);
    KeInsertQueueDpc(param_1 + 0xd0,param_2,0);
    return 0x103;
  }
  if (uVar3 == 1) {
    if (((int)param_2[5] == 6) && (*(int *)(param_2[9] + 0x10) == 1)) {
      for (puVar5 = *(undefined8 **)(param_1 + 0x20); puVar5 != (undefined8 *)(param_1 + 0x20);
          puVar5 = (undefined8 *)*puVar5) {
        if ((*(int *)(puVar5 + -7) == 6) && (*(int *)(puVar5[-3] + 0x10) == 1)) {
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
          (*(code *)param_2[8])(param_2,0);
          return 0;
        }
      }
    }
    puVar5 = *(undefined8 **)(param_1 + 0x28);
    puVar6 = (undefined8 *)(param_1 + 0x20);
    plVar9 = param_2 + 0xc;
    if ((undefined8 *)*puVar5 != puVar6) goto LAB_14000ece4;
  }
  else {
    if (uVar3 != 2) {
      if (uVar3 == 3) {
        *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
        if (*(uint *)(param_1 + 0x44) < *(uint *)(param_1 + 0x40)) {
          *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x40);
        }
        puVar6 = (undefined8 *)(param_1 + 0x30);
        *(byte *)(_DAT_000000b8 + 3) = *(byte *)(_DAT_000000b8 + 3) | 1;
        puVar5 = *(undefined8 **)(param_1 + 0x38);
        plVar9 = param_2;
        if ((undefined8 *)*puVar5 == puVar6) {
          _DAT_000000a8 = puVar6;
          _DAT_000000b0 = puVar5;
          *puVar5 = 0xa8;
          *(undefined8 *)(param_1 + 0x38) = 0xa8;
          goto LAB_14000ecf9;
        }
        goto LAB_14000ece4;
      }
      puVar8 = auStack_58;
      if (uVar3 != 4) goto LAB_14000ecf9;
    }
    puVar6 = (undefined8 *)(param_1 + 0x20);
    for (puVar5 = (undefined8 *)*puVar6; (puVar5 != puVar6 && (*(int *)(puVar5 + -9) == 4));
        puVar5 = (undefined8 *)*puVar5) {
    }
    puVar1 = (undefined8 *)puVar5[1];
    plVar9 = param_2 + 0xc;
    if ((undefined8 *)*puVar1 == puVar5) {
      *plVar9 = (longlong)puVar5;
      param_2[0xd] = (longlong)puVar1;
      *puVar1 = plVar9;
      puVar5[1] = plVar9;
      puVar8 = auStack_58;
      goto LAB_14000ecf9;
    }
LAB_14000ece4:
    pcVar2 = (code *)swi(0x29);
    puVar5 = (undefined8 *)(*pcVar2)(3);
    puVar7 = auStack_50;
  }
  *plVar9 = (longlong)puVar6;
  plVar9[1] = (longlong)puVar5;
  *puVar5 = plVar9;
  puVar6[1] = plVar9;
  puVar8 = puVar7;
LAB_14000ecf9:
  *(undefined8 *)(puVar8 + -8) = 0x14000ed05;
  KeReleaseInStackQueuedSpinLockFromDpcLevel(puVar8 + 0x30);
  return 0x103;
}



===== SdbusWorkerSetStateCmdExecWithFlags @ 14000ed84 =====

void SdbusWorkerSetStateCmdExecWithFlags
               (longlong param_1,undefined8 param_2,undefined8 *param_3,undefined4 param_4,
               undefined2 param_5,undefined2 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,byte param_10)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = param_3[1];
  *(undefined8 *)(param_1 + 0x230) = *param_3;
  *(undefined8 *)(param_1 + 0x238) = uVar2;
  uVar1 = *(undefined4 *)(param_3 + 2);
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x240) = uVar1;
  *(undefined2 *)(param_1 + 0x22c) = param_5;
  *(undefined2 *)(param_1 + 0x22e) = param_6;
  *(undefined4 *)(param_1 + 0x228) = param_9;
  *(undefined8 *)(param_1 + 0x218) = param_7;
  *(undefined8 *)(param_1 + 0x220) = param_8;
  *(undefined8 *)(param_1 + 0x210) = param_2;
  *(byte *)(param_1 + 0x259) = param_10 & 1;
  *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(param_1 + 0x1a8) = 2;
  *(undefined4 *)(param_1 + 0x204) = param_4;
  *(undefined1 *)(param_1 + 600) = 0;
  return;
}



===== SdbusWorkerValidateDeviceState @ 14000ee1c =====

undefined4 SdbusWorkerValidateDeviceState(longlong param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x28) & 1) != 0) {
    return 0xc00002b6;
  }
  if ((*(uint *)(param_1 + 0x28) & 4) != 0) {
    return 0xc000009e;
  }
  if (*(int *)(param_1 + 0x20) == 5) {
    return 0xc0000056;
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x20) == 6) {
    uVar1 = 0xc00002b6;
  }
  return uVar1;
}



===== SdbusAcpiDsmGetHighSpeedCapabilities @ 14000ee68 =====

undefined1 SdbusAcpiDsmGetHighSpeedCapabilities(undefined8 param_1)

{
  ulonglong uVar1;
  undefined1 uVar2;
  longlong local_res10 [3];
  
  local_res10[0] = 0;
  uVar2 = 0;
  uVar1 = SdbusAcpiEvalDsm(param_1,&GUID_INTEL_SDHC_DSM,0,8,local_res10);
  if (((-1 < (int)uVar1) && (*(short *)(local_res10[0] + 0xc) == 2)) &&
     (*(short *)(local_res10[0] + 0xe) == 1)) {
    uVar2 = *(undefined1 *)(local_res10[0] + 0x10);
  }
  if (local_res10[0] != 0) {
    ExFreePoolWithTag(local_res10[0],0x69416453);
  }
  return uVar2;
}



===== SdbusAcpiEvalDsm @ 14000eed4 =====

ulonglong SdbusAcpiEvalDsm(undefined8 param_1,void *param_2,undefined4 param_3,undefined4 param_4,
                          undefined8 *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  int *piVar5;
  undefined8 in_stack_ffffffffffffffc8;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x48,0x69416453);
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    piVar2 = (int *)ExAllocatePool2(0x40,0x1000,0x69416453);
    if (piVar2 == (int *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *puVar1 = 0x43696541;
      puVar1[1] = 0x4d53445f;
      puVar1[2] = 0x48;
      puVar1[3] = 4;
      puVar1[4] = 0x100002;
      memcpy_s(puVar1 + 5,0x10,param_2,0x10);
      uVar3 = (ulonglong)*(ushort *)((longlong)puVar1 + 0x12);
      if (*(ushort *)((longlong)puVar1 + 0x12) < 4) {
        uVar3 = 4;
      }
      *(undefined4 *)((longlong)puVar1 + uVar3 + 0x14) = 0x40000;
      *(undefined4 *)((longlong)puVar1 + uVar3 + 0x18) = param_3;
      *(undefined4 *)((longlong)puVar1 + uVar3 + 0x1c) = 0x40000;
      *(undefined4 *)((longlong)puVar1 + uVar3 + 0x20) = param_4;
      *(undefined8 *)((longlong)puVar1 + uVar3 + 0x24) = 0x40003;
      uVar3 = SdbusEvalAcpiMethod(param_1,4,param_2,puVar1,in_stack_ffffffffffffffc8,piVar2);
      uVar4 = uVar3 & 0xffffffff;
      piVar5 = (int *)0x0;
      if (-1 < (int)uVar3) {
        piVar5 = piVar2;
      }
      *param_5 = piVar5;
    }
    ExFreePoolWithTag(puVar1,0x69416453);
    if (((int)uVar4 < 0) && (piVar2 != (int *)0x0)) {
      ExFreePoolWithTag(piVar2,0x69416453);
    }
  }
  return uVar4;
}



===== SdbusAcpiEvalDsmWorker @ 14000f050 =====

void SdbusAcpiEvalDsmWorker(undefined8 param_1,longlong param_2)

{
  void *pvVar1;
  ulonglong uVar2;
  undefined8 local_res10 [3];
  
  pvVar1 = *(void **)(param_2 + 0x2a8);
  local_res10[0] = 0;
  uVar2 = SdbusAcpiEvalDsm(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x18),pvVar1,
                           *(undefined4 *)((longlong)pvVar1 + 0x10),
                           *(undefined4 *)((longlong)pvVar1 + 0x14),local_res10);
  if (-1 < (int)uVar2) {
    ExFreePoolWithTag(local_res10[0],0x69416453);
  }
  SdbusWorkerPushEvents(param_2,*(uint *)((longlong)pvVar1 + 0x18),0,'\x01','\0');
  return;
}



===== SdbusAcpiQueryDsmFunctionsSupported @ 14000f0d0 =====

uint SdbusAcpiQueryDsmFunctionsSupported(longlong param_1)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  longlong local_res8;
  
  uVar4 = 0;
  uVar3 = 0;
  local_res8 = 0;
  uVar2 = SdbusAcpiEvalDsm(*(undefined8 *)(param_1 + 0x18),&GUID_INTEL_SDHC_DSM,0,0,&local_res8);
  if ((int)uVar2 < 0) {
    *(undefined1 *)(param_1 + 0x565) = 0;
    goto LAB_14000f159;
  }
  if (*(short *)(local_res8 + 0xc) != 2) goto LAB_14000f159;
  sVar1 = *(short *)(local_res8 + 0xe);
  if (sVar1 == 1) {
LAB_14000f144:
    uVar4 = uVar3 | *(byte *)(local_res8 + 0x10);
  }
  else {
    if (sVar1 == 2) {
LAB_14000f13b:
      uVar3 = uVar3 | (uint)*(byte *)(local_res8 + 0x11) << 8;
      goto LAB_14000f144;
    }
    if (sVar1 == 3) {
LAB_14000f132:
      uVar3 = uVar3 | (uint)*(byte *)(local_res8 + 0x12) << 0x10;
      goto LAB_14000f13b;
    }
    if (sVar1 == 4) {
      uVar3 = (uint)*(byte *)(local_res8 + 0x13) << 0x18;
      goto LAB_14000f132;
    }
  }
  *(undefined1 *)(param_1 + 0x565) = 1;
LAB_14000f159:
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0x69416453);
  }
  return uVar4;
}



===== SdbusCardErrorToNtStatus @ 14000f184 =====

void SdbusCardErrorToNtStatus(uint param_1,int *param_2)

{
  if (param_1 != 0) {
    if ((param_1 & 0xf15) == 0) {
      if ((param_1 & 2) != 0) {
        *param_2 = -0x3ffffe7b;
        return;
      }
      if ((param_1 & 8) != 0) {
        *param_2 = -0x3fffff51;
        return;
      }
      if ((param_1 & 0x60) != 0) {
        *param_2 = -0x3fffffde;
        return;
      }
      if ((param_1 >> 0xc & 1) == 0) {
        *param_2 = (-(uint)((param_1 & 0x80) != 0) & 0xffffff1d) + 0xc0000185;
        return;
      }
      *param_2 = -0x3ffffff3;
      return;
    }
    *param_2 = -0x3ffffe7a;
  }
  return;
}



===== SdbusClockRateCodeToValue @ 14000f1e8 =====

int SdbusClockRateCodeToValue(byte param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = 10;
  uVar2 = (ulonglong)(param_1 & 7);
  if ((param_1 & 7) != 0) {
    do {
      iVar1 = iVar1 * 10;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return (uint)(byte)(&DAT_1400241b0)[param_1 >> 3 & 0xf] * iVar1;
}



===== SdbusComputeResponseLength @ 14000f220 =====

undefined1 SdbusComputeResponseLength(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 1) {
    return 0;
  }
  if ((iVar1 != 2) && (iVar1 != 3)) {
    if (iVar1 == 4) {
      return 0x10;
    }
    if ((((iVar1 != 5) && (iVar1 != 6)) && (iVar1 != 7)) && ((iVar1 != 8 && (iVar1 != 9)))) {
      return 0;
    }
  }
  return 4;
}



===== SdbusControllerErrorToNtStatus @ 14000f268 =====

void SdbusControllerErrorToNtStatus(uint param_1,int *param_2)

{
  if (param_1 != 0) {
    if ((param_1 & 0x11) != 0) {
      *param_2 = -0x3fffff4b;
      return;
    }
    if ((param_1 & 0x22) != 0) {
      *param_2 = -0x3fffffc1;
      return;
    }
    if ((param_1 & 0x44) != 0) {
      *param_2 = -0x3fffff64;
      return;
    }
    if ((param_1 & 8) != 0) {
      *param_2 = -0x3ffffe7a;
      return;
    }
    *param_2 = (-(uint)((param_1 & 0x80) != 0) & 0xffffff19) + 0xc0000185;
  }
  return;
}



===== SdbusEvalAcpiMethod @ 14000f2bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SdbusEvalAcpiMethod(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                             undefined8 param_4,undefined8 param_5,int *param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStack_1a8 [32];
  int *local_188;
  undefined4 local_180;
  undefined1 local_178;
  undefined8 *local_170;
  ulonglong *local_168;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong local_140 [3];
  undefined1 local_128 [272];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(local_128,0,0x104);
  local_148 = 0;
  local_140[0] = 0;
  local_140[1] = 0;
  local_158 = 0;
  uStack_150 = 0;
  KeInitializeEvent(&local_158,1,0);
  local_168 = local_140;
  local_170 = &local_158;
  local_178 = 0;
  local_180 = 0x1000;
  local_188 = param_6;
  lVar1 = IoBuildDeviceIoControlRequest(0x32c004,param_1,param_4,0x48);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      local_188 = (int *)0x0;
      uVar2 = KeWaitForSingleObject(&local_158,0,0,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = local_140[0] & 0xffffffff;
    }
    if (-1 < (int)uVar2) {
      if (*param_6 == 0x426f6541) {
        uVar2 = uVar2 & 0xffffffff;
        if (param_6[2] == 0) {
          uVar2 = 0xc014000f;
        }
      }
      else {
        uVar2 = 0xc014000f;
      }
    }
  }
  return uVar2;
}



===== SdbusEvalHostCapabilitiesDsm @ 14000f40c =====

ulonglong SdbusEvalHostCapabilitiesDsm
                    (longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,
                    ushort *param_5)

{
  short sVar1;
  ulonglong uVar2;
  ushort uVar3;
  longlong local_res10 [3];
  
  if ((*(byte *)(param_1 + 0x1158 + ((longlong)(int)param_4 >> 3)) >> (param_4 & 7) & 1) == 0) {
    return 0xc0000010;
  }
  local_res10[0] = 0;
  uVar2 = SdbusAcpiEvalDsm(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x18),&GUID_INTEL_SDHC_DSM,0
                           ,param_4,local_res10);
  if ((-1 < (int)uVar2) && (*(short *)(local_res10[0] + 0xc) == 2)) {
    uVar3 = 0;
    sVar1 = *(short *)(local_res10[0] + 0xe);
    *param_5 = 0;
    if (sVar1 != 1) {
      if (sVar1 != 2) goto LAB_14000f499;
      uVar3 = (ushort)*(byte *)(local_res10[0] + 0x11) << 8;
    }
    *param_5 = *(byte *)(local_res10[0] + 0x10) | uVar3;
  }
LAB_14000f499:
  if (local_res10[0] != 0) {
    ExFreePoolWithTag(local_res10[0],0x69416453);
  }
  return uVar2 & 0xffffffff;
}



===== SdbusReadRegisterCooked @ 14000f4c4 =====

uint SdbusReadRegisterCooked(longlong param_1,ushort param_2,int param_3)

{
  uint uVar1;
  
  if (param_3 == 1) {
    uVar1 = param_2 & 3;
  }
  else {
    uVar1 = param_2 & 2;
  }
  return *(uint *)(((ulonglong)param_2 & 0xfffffffc) + *(longlong *)(param_1 + 0x228)) >>
         (sbyte)(uVar1 << 3);
}



===== SdbusReadRegisterUchar @ 14000f4f8 =====

uint SdbusReadRegisterUchar(longlong param_1,ushort param_2)

{
  uint uVar1;
  undefined8 in_RAX;
  
  if (*(longlong *)(param_1 + 0x228) == 0) {
    uVar1 = (uint)CONCAT71((int7)((ulonglong)in_RAX >> 8),0xff);
  }
  else if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
    uVar1 = (uint)CONCAT11((char)(param_2 >> 8),
                           *(undefined1 *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x228)));
  }
  else {
    uVar1 = SdbusReadRegisterCooked(param_1,param_2,1);
  }
  return uVar1;
}



===== SdbusReadRegisterUlong @ 14000f538 =====

undefined4 SdbusReadRegisterUlong(longlong param_1,ushort param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(longlong *)(param_1 + 0x228) == 0) {
    return 0xff;
  }
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
     (bVar1 = *(byte *)(*(longlong *)(param_1 + 8) + 0x46), 1 < bVar1)) {
    uVar2 = ~-(uint)(param_2 < 0x100) & 0x100;
    if (0x183 < param_2) {
      uVar2 = 0xa0;
    }
    uVar3 = uVar2 + 4;
    if (param_2 != 0x1b8) {
      uVar3 = uVar2;
    }
    if ((2 < bVar1) && (param_2 == 600)) {
      uVar3 = 0;
    }
  }
  return *(undefined4 *)((ulonglong)(param_2 + uVar3) + *(longlong *)(param_1 + 0x228));
}



===== SdbusReadRegisterUshort @ 14000f5bc =====

uint SdbusReadRegisterUshort(longlong param_1,ushort param_2)

{
  uint uVar1;
  
  if (*(longlong *)(param_1 + 0x228) == 0) {
    uVar1 = 0xff;
  }
  else if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
    uVar1 = (uint)*(ushort *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x228));
  }
  else {
    uVar1 = SdbusReadRegisterCooked(param_1,param_2,2);
  }
  return uVar1;
}



===== SdbusSystemPacketWorker @ 14000f600 =====

void SdbusSystemPacketWorker
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  SdbusFxComponentActive(lVar1,1,param_3,param_4);
  uVar3 = 0;
  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x40);
  SdbusExecuteWorkSynchronousWithParameter(*(int *)(param_2 + 0x298),param_2,uVar2,(longlong *)0x0);
  SdbusFxComponentIdle(lVar1,param_2,uVar2,uVar3);
  return;
}



===== SdbusWait @ 14000f654 =====

void SdbusWait(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  longlong local_res10 [3];
  
  bVar1 = KeGetCurrentIrql();
  if (0x32 < param_1) {
    if (bVar1 < 2) {
      SdbusDebugPrint(4,"SdbusWait: wait %d\n",(ulonglong)param_1,param_4);
      local_res10[0] = (longlong)(int)(param_1 * -10);
      KeWaitForSingleObject(&SdbusDelayTimerEvent,0,0,0,local_res10);
      return;
    }
    SdbusDebugPrint(4,"SdbusWait: STALL %d\n",(ulonglong)param_1,param_4);
  }
  KeStallExecutionProcessor(param_1);
  return;
}



===== SdbusWriteRegisterCooked @ 14000f6e0 =====

void SdbusWriteRegisterCooked(longlong param_1,ushort param_2,int param_3,int param_4)

{
  int iVar1;
  sbyte sVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_2 < 0x4d) {
    puVar4 = (uint *)(((ulonglong)param_2 & 0xfffffffc) + *(longlong *)(param_1 + 0x228));
    if (param_3 == 1) {
      uVar3 = param_2 & 3;
      iVar1 = 0xff;
    }
    else {
      uVar3 = param_2 & 2;
      iVar1 = 0xffff;
    }
    sVar2 = (sbyte)(uVar3 << 3);
    *puVar4 = ~(iVar1 << sVar2 |
               *(uint *)(&SdbusUnsafeRegisterWrites + (ulonglong)(param_2 >> 2 & 0x3f) * 4)) &
              *puVar4 | param_4 << sVar2;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdbusWriteRegisterUchar @ 14000f758 =====

void SdbusWriteRegisterUchar(longlong param_1,ushort param_2,byte param_3)

{
  if (*(longlong *)(param_1 + 0x228) != 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
      *(byte *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x228)) = param_3;
      LOCK();
      UNLOCK();
    }
    else {
      SdbusWriteRegisterCooked(param_1,param_2,1,(uint)param_3);
    }
  }
  return;
}



===== SdbusWriteRegisterUlong @ 14000f79c =====

void SdbusWriteRegisterUlong(longlong param_1,ushort param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = 0;
  if (*(longlong *)(param_1 + 0x228) != 0) {
    if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') &&
       (bVar1 = *(byte *)(*(longlong *)(param_1 + 8) + 0x46), 1 < bVar1)) {
      uVar3 = ~-(ushort)(param_2 < 0x100) & 0x100;
      if (0x183 < param_2) {
        uVar3 = 0xa0;
      }
      uVar2 = uVar3 + 4;
      if (param_2 != 0x1b8) {
        uVar2 = uVar3;
      }
      if ((2 < bVar1) && (param_2 == 600)) {
        uVar2 = 0;
      }
    }
    *(undefined4 *)((ulonglong)(ushort)(uVar2 + param_2) + *(longlong *)(param_1 + 0x228)) = param_3
    ;
    LOCK();
    UNLOCK();
  }
  return;
}



===== SdbusWriteRegisterUshort @ 14000f828 =====

void SdbusWriteRegisterUshort(longlong param_1,ushort param_2,ushort param_3)

{
  if (*(longlong *)(param_1 + 0x228) != 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x400000) == 0) {
      *(ushort *)((ulonglong)param_2 + *(longlong *)(param_1 + 0x228)) = param_3;
      LOCK();
      UNLOCK();
    }
    else {
      SdbusWriteRegisterCooked(param_1,param_2,2,(uint)param_3);
    }
  }
  return;
}



===== ClearStatusFlags @ 14000f86c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ClearStatusFlags(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = KeQueryTimeIncrement();
  lVar2 = _DAT_fffff78000000320;
  do {
    SdbusWriteRegisterUlong(param_1,0x38,0x58007ff);
    uVar4 = SdbusReadRegisterUlong(param_1,0x34);
    lVar1 = (longlong)((_DAT_fffff78000000320 - lVar2) * (ulonglong)(uint)(iVar3 * 100)) / 1000;
    if ((uVar4 & 0x58007ff) == 0) {
      if (lVar1 < 0x1a) {
        return 0;
      }
      SdbusDebugPrint(0x4000,"QC_SDHC[%p] ClearStatusFlags cleared in %lld usec\r\n",param_1,lVar1);
      return 0;
    }
  } while (lVar1 < 20000);
  SdbusDebugPrint(0x4000,
                  "QC_SDHC[%p] ClearStatusFlags could not clear status flags in %lld usec (%8.8x)\r\n"
                  ,param_1,lVar1);
  return 0xc00000b5;
}



===== PlAcknowledgeEvent @ 14000f970 =====

void PlAcknowledgeEvent(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = PlEventMaskToHardwareMask(param_2);
  uVar2 = param_2 & 0xffffffcf;
  SdbusWriteRegisterUlong(param_1,0x38,uVar1 & 0x58007ff);
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlAcknowledgeEvent(sw=%8.8x -> hw=%8.8x)\r\n",param_1,
                  (ulonglong)uVar2);
  PlSetEventMask(param_1,uVar2,uVar2);
  return;
}



===== PlDebugDumpRegs @ 14000f9f0 =====

void PlDebugDumpRegs(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  SdbusDebugPrint(0x200000,"           *----------------- [%p] -------------------*",param_1,param_4
                 );
  SdbusReadRegisterUlong(param_1,8);
  uVar1 = SdbusReadRegisterUlong(param_1,4);
  uVar2 = SdbusReadRegisterUlong(param_1,0);
  SdbusDebugPrint(0x200000,"           MCI_POWER=0x%x MCI_CLK=0x%x MCI_ARGUMENT=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x14);
  uVar1 = SdbusReadRegisterUlong(param_1,0x10);
  uVar2 = SdbusReadRegisterUlong(param_1,0xc);
  SdbusDebugPrint(0x200000,"           MCI_CMD=0x%x MCI_RESPONSE_CMD=0x%x MCI_RESPONSE0=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x20);
  uVar1 = SdbusReadRegisterUlong(param_1,0x1c);
  uVar2 = SdbusReadRegisterUlong(param_1,0x18);
  SdbusDebugPrint(0x200000,"           MCI_RESPONSE1=0x%x MCI_RESPONSE2=0x%x MCI_RESPONSE3=0x%x\r\n"
                  ,(ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x2c);
  uVar1 = SdbusReadRegisterUlong(param_1,0x28);
  uVar2 = SdbusReadRegisterUlong(param_1,0x24);
  SdbusDebugPrint(0x200000,
                  "           MCI_DATA_TIMER=0x%x MCI_DATA_LENGTH=0x%x MCI_DATA_CONTROL=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x40);
  uVar1 = SdbusReadRegisterUlong(param_1,0x3c);
  uVar2 = SdbusReadRegisterUlong(param_1,0x34);
  uVar3 = (ulonglong)uVar2;
  uVar4 = (ulonglong)uVar1;
  SdbusDebugPrint(0x200000,"           MCI_STATUS=0x%x MCI_INTERRUPT0=0x%x MCI_INTERRUPT1=0x%x\r\n",
                  uVar3,uVar4);
  SdbusDebugPrint(0x200000,"          *------------------------------------------*",uVar3,uVar4);
  return;
}



===== PlDetectCardInSocket @ 14000fba0 =====

undefined8
PlDetectCardInSocket(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined7 uVar2;
  undefined8 uVar1;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlDetectCardInSocket",param_1,param_4);
  uVar2 = (undefined7)((ulonglong)*(longlong *)(param_1 + 8) >> 8);
  uVar1 = CONCAT71(uVar2,1);
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x380) != 0) {
    uVar1 = CONCAT71(uVar2,*(undefined1 *)(param_1 + 0x1654));
  }
  return uVar1;
}



===== PlDisableAllHostControllerInterrupts @ 14000fbe0 =====

void PlDisableAllHostControllerInterrupts
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlDisableAllHostControllerInterrupts\r\n",param_1,param_4);
  SdbusWriteRegisterUlong(param_1,0x3c,0);
  SdbusWriteRegisterUlong(param_1,0x40,0);
  return;
}



===== PlDmaCompletionRoutine @ 14000fc30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PlDmaCompletionRoutine(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlDmaCompletionRoutine\r\n",param_3,param_4);
  *(longlong *)(param_3 + 0x29f8) = *(longlong *)(param_3 + 0x29f8) + 1;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(*(longlong *)(param_1 + 8) + 0xd0))
            (param_1,*(undefined8 *)(param_3 + 0x308),*(undefined8 *)(param_3 + 0x300),
             *(undefined8 *)(param_3 + 0x179c),*(undefined4 *)(param_3 + 0x1794),
             *(int *)(param_3 + 0x178c) == 2);
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_3 + 0x350,&local_28);
  *(undefined1 *)(param_3 + 0x349) = 0;
  if (*(char *)(param_3 + 0x348) == '\0') {
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
    if ((int)param_4 == 0) {
      if ((SdTestErrorRecovery == 0) ||
         (*(int *)(param_3 + 0x2a3c) = *(int *)(param_3 + 0x2a3c) + 1,
         *(int *)(param_3 + 0x2a3c) < *(int *)(param_3 + 0x2a40))) {
        uVar1 = 0x400000;
        uVar2 = 0;
      }
      else {
        *(longlong *)(param_3 + 0x2a30) = *(longlong *)(param_3 + 0x2a30) + 1;
        *(undefined4 *)(param_3 + 0x2a3c) = 0;
        (**(code **)(*(longlong *)(param_1 + 8) + 0x30))(param_1);
        uVar1 = 0x1000;
        uVar2 = 0x11;
      }
      goto LAB_14000fda4;
    }
    *(longlong *)(param_3 + 0x2a30) = *(longlong *)(param_3 + 0x2a30) + 1;
    (**(code **)(*(longlong *)(param_1 + 8) + 0x30))(param_1);
    uVar1 = 0x1000;
    uVar2 = 0x20000000;
  }
  else {
    *(undefined1 *)(param_3 + 0x348) = 0;
    KeReleaseInStackQueuedSpinLockFromDpcLevel();
    *(longlong *)(param_3 + 0x2a30) = *(longlong *)(param_3 + 0x2a30) + 1;
    (**(code **)(*(longlong *)(param_1 + 8) + 0x30))(param_1);
    uVar1 = 0x40000;
    uVar2 = 0;
  }
  *(undefined1 *)(param_3 + 0x359) = 0;
LAB_14000fda4:
  SdbusWorkerPushEvents(param_3,uVar1,uVar2,'\x01','\0');
  return;
}



===== PlEventMaskToHardwareMask @ 14000fdcc =====

uint PlEventMaskToHardwareMask(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = -(uint)((param_1 & 4) != 0) & 0xc0;
  uVar2 = uVar1 | 0x800000;
  if ((param_1 & 8) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x23f;
  if ((param_1 >> 0xc & 1) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x2000000;
  if ((param_1 & 0x100) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x100;
  if ((param_1 & 0x40) == 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}



===== PlExecuteRetuning @ 14000fe30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PlExecuteRetuning(undefined4 *param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  byte bVar7;
  ushort uVar8;
  byte *pbVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  undefined8 uVar14;
  undefined1 auStackY_98 [32];
  byte local_58 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  bVar11 = 0;
  piVar1 = (int *)(param_2 + 0x174c);
  iVar4 = *piVar1;
  if (iVar4 == 0) {
    *(undefined8 *)(param_2 + 0x17ed) = 0;
    *(undefined8 *)(param_2 + 0x17f5) = 0;
    *(undefined1 *)(param_2 + 0x17fd) = 0;
    SdbusDisableEvents(param_2,0x1051);
    uVar8 = 4;
    uVar5 = SdbusReadRegisterUlong(param_2,4);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 & 0xfffffdff);
    do {
      uVar5 = SdbusReadRegisterUlong(param_2,0x6c);
    } while ((uVar5 & 1) != 0);
    uVar8 = 0x60;
    uVar5 = SdbusReadRegisterUlong(param_2,0x60);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 | 0x40000000);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 | 0x60000000);
    uVar5 = uVar5 | 0x67000000;
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 & 0xbfffffff);
    uVar5 = uVar5 & 0x9fffffff;
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 | 0x10000);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 | 0x50000);
    do {
      uVar3 = SdbusReadRegisterUlong(param_2,0x68);
    } while (-1 < (char)uVar3);
    *(undefined1 *)(param_2 + 0x17fe) = 0;
    *(undefined1 *)(param_2 + 0x17ec) = 0;
    *piVar1 = 1;
LAB_140010065:
    bVar11 = *(byte *)(param_2 + 0x17ec);
    iVar4 = -0x3fffffea;
    if (bVar11 == 0x10) {
      bVar10 = 0;
      bVar12 = 0;
      bVar13 = 0;
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x17fe) + 0xa1 + (longlong)piVar1) =
           *(undefined1 *)(param_2 + 0x17ed);
      bVar11 = *(byte *)(param_2 + 0x17fe);
      if (bVar11 == 0) {
        bVar11 = 0;
      }
      else {
        pbVar9 = local_58;
        do {
          bVar7 = pbVar9[(longlong)piVar1 + (0xa2 - (longlong)local_58)] -
                  pbVar9[(longlong)piVar1 + (0xa1 - (longlong)local_58)];
          *pbVar9 = bVar7;
          if (bVar7 == 0) {
            bVar7 = 0x10;
            *pbVar9 = 0x10;
          }
          if (bVar12 < bVar7) {
            bVar12 = bVar7;
            bVar10 = bVar13;
          }
          bVar13 = bVar13 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar13 < bVar11);
        bVar11 = (char)((ulonglong)((uint)local_58[bVar10] * 3) / 4) +
                 *(char *)((ulonglong)bVar10 + 0x17ed + param_2);
        *(byte *)(param_2 + 0x17ec) = bVar11;
        bVar11 = bVar11 & 0xf;
      }
      *(byte *)(param_2 + 0x17ec) = bVar11;
      iVar4 = 0;
    }
    bVar11 = (&DAT_140024bf0)[bVar11];
    do {
      uVar3 = SdbusReadRegisterUlong(param_2,0x68);
    } while (-1 < (char)uVar3);
    uVar8 = 0x60;
    uVar5 = SdbusReadRegisterUlong(param_2,0x60);
    SdbusWriteRegisterUlong(param_2,uVar8,uVar5 & 0xfff9ffff | 0x7090000);
    do {
      uVar5 = SdbusReadRegisterUlong(param_2,0x60);
    } while ((uVar5 >> 0x12 & 1) != 0);
    uVar6 = 0x60;
    uVar5 = uVar5 | (bVar11 & 0xf) << 0x14;
    SdbusWriteRegisterUlong(param_2,0x60,uVar5);
    SdbusWriteRegisterUlong(param_2,(ushort)uVar6,uVar5 | 0x40000);
    do {
      uVar5 = SdbusReadRegisterUlong(param_2,(ushort)uVar6);
    } while ((uVar5 & 0x40000) == 0);
    SdbusWriteRegisterUlong(param_2,(ushort)uVar6,uVar5 & 0xfff7ffff | 0x20000);
    if (iVar4 < 0) {
      *piVar1 = 2;
      goto LAB_1400101d3;
    }
  }
  else {
    if (iVar4 == 1) goto LAB_140010065;
    if (iVar4 != 2) {
      if (iVar4 == 3) {
        if (*(int *)(*(longlong *)(param_2 + 0x568) + 0x38) == 0) {
          ReadDataPortInternal
                    (param_2,*(undefined4 **)(param_2 + 0x176c),*(uint *)(param_2 + 0x1780));
          uVar5 = SdTransferTimeout;
          param_1[1] = 100000;
          param_1[2] = uVar5 / 100;
          *param_1 = 0x40;
          *piVar1 = 4;
          return -0x3fffffea;
        }
        *(undefined4 *)(*(longlong *)(param_2 + 0x568) + 0x38) = 0;
        (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0xf8))(param_2,0xffffffff);
      }
      else {
        if (iVar4 != 4) {
          iVar4 = -0x3ffffff3;
          goto LAB_14001027f;
        }
        lVar2 = *(longlong *)(param_2 + 0x568);
        if (*(int *)(lVar2 + 0x38) == 0) {
          for (; bVar11 < 0x10; bVar11 = bVar11 + 1) {
            if ((&DAT_140024c00)[bVar11] != *(int *)(param_2 + 0x17ac + (ulonglong)bVar11 * 4))
            goto LAB_14000fec7;
          }
          goto LAB_14000fee1;
        }
        (**(code **)(*(longlong *)(*(longlong *)(param_2 + 8) + 0x28) + 0xf8))(param_2,0xffffffff);
        *(undefined4 *)(lVar2 + 0x38) = 0;
      }
LAB_14000fec7:
      *(undefined1 *)((ulonglong)*(byte *)(param_2 + 0x17fe) + 0xa1 + (longlong)piVar1) =
           *(undefined1 *)(param_2 + 0x17ec);
      *(char *)(param_2 + 0x17fe) = *(char *)(param_2 + 0x17fe) + '\x01';
LAB_14000fee1:
      *(char *)(param_2 + 0x17ec) = *(char *)(param_2 + 0x17ec) + '\x01';
      *piVar1 = 1;
      return -0x3fffffea;
    }
LAB_1400101d3:
    SdbusAddDbgLog(param_2,0x54554e20,0x13,(ulonglong)*(byte *)(param_2 + 0x17ec),0x40);
    uVar14 = 1;
    uVar6 = PlInitializeTransfer(param_2,0x40,0,1,1,param_2 + 0x17ac,0,0);
    iVar4 = (int)uVar6;
    if (-1 < iVar4) {
      uVar6 = SendCommand(param_2,&CmdDescSendTuningBlock,0,uVar14,'\0');
      uVar5 = SdCommandTimeout;
      iVar4 = (int)uVar6;
      if (-1 < iVar4) {
        param_1[1] = 100000;
        param_1[2] = uVar5 / 100;
        *param_1 = 0x40;
        *piVar1 = 3;
        return -0x3fffffea;
      }
    }
  }
  if (iVar4 == -0x3fffffea) {
    return -0x3fffffea;
  }
LAB_14001027f:
  uVar8 = 4;
  uVar5 = SdbusReadRegisterUlong(param_2,4);
  SdbusWriteRegisterUlong(param_2,uVar8,uVar5 | 0x200);
  do {
    uVar5 = SdbusReadRegisterUlong(param_2,0x6c);
  } while ((uVar5 & 1) != 0);
  PlAcknowledgeEvent(param_2,0xfffffeff);
  SdbusEnableEvents(param_2,(*(uint *)(param_2 + 0x20) & 0x200000 | 0x20fa000) >> 0xd);
  *(undefined1 *)(param_2 + 0x1699) = 1;
  *(int *)(param_2 + 0x169c) = iVar4;
  *piVar1 = 0;
  return iVar4;
}



===== PlGetErrorStates @ 140010310 =====

uint PlGetErrorStates(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = SdbusReadRegisterUlong(param_1,0x34);
  uVar2 = (uVar1 & 1) * 2;
  uVar3 = uVar2 | 0x20;
  if ((uVar1 & 2) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 1;
  if ((uVar1 & 4) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 0x10;
  if ((uVar1 & 8) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 0x40000000;
  if ((uVar1 & 0x230) == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}



===== PlGetPendingEvents @ 140010370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PlGetPendingEvents(ulonglong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar1 = SdbusReadRegisterUlong(param_1,0x34);
  if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\b') && ((uVar1 & 0x800000) != 0)) {
    uVar2 = SdbusReadRegisterUlong(param_1,0xc);
    if ((uVar2 >> 0xb & 1) == 0) {
      uVar1 = uVar1 & 0xff7fffff;
      SdbusWriteRegisterUlong(param_1,0x38,0x800000);
    }
  }
  if (*(int *)(param_1 + 0x1120) != 1) {
    uVar1 = uVar1 & 0xfdbfffff;
    SdbusWriteRegisterUlong(param_1,0x38,0x400000);
  }
  if ((((uVar1 & 1) != 0) && (*(uint *)(param_1 + 0x1750) < 0x2a)) &&
     ((0x20000000022U >> ((ulonglong)*(uint *)(param_1 + 0x1750) & 0x3f) & 1) != 0)) {
    uVar1 = uVar1 & 0xfffffffe | 0x40;
    SdbusWriteRegisterUlong(param_1,0x38,1);
    param_4 = (ulonglong)*(uint *)(param_1 + 0x1750);
    SdbusDebugPrint(0x4000,
                    "QC_SDHC[%p] PlGetPendingEvents(HW mask changed for CMD%d, new=%8.8x)\r\n",
                    param_1,param_4);
  }
  uVar3 = -(uint)((uVar1 & 0xc0) != 0) & 4;
  uVar2 = uVar3 | 8;
  if ((uVar1 & 0x800000) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 0x1000;
  if ((uVar1 & 0x23f) == 0) {
    uVar3 = uVar2;
  }
  uVar6 = (ulonglong)uVar3;
  pcVar4 = (char *)0x100;
  uVar2 = uVar3 | 0x100;
  if ((uVar1 >> 0x19 & 1) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 0x40;
  if ((uVar1 & 0x100) == 0) {
    uVar3 = uVar2;
  }
  if (((*(char *)(param_1 + 0x24) != '\0') && (*(int *)(param_1 + 0x1788) == 4)) &&
     (((*(uint *)(param_1 + 0x578) & 0x40) != 0 && ((*(uint *)(param_1 + 0x3f0) & 0x40) == 0)))) {
    if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\t') {
      if (*(int *)(param_1 + 0x178c) == 2) {
        lVar5 = *(longlong *)(param_1 + 0x2e8);
      }
      else {
        lVar5 = *(longlong *)(param_1 + 0x2e0);
      }
    }
    else {
      lVar5 = *(longlong *)(param_1 + 0x2d8);
    }
    uVar2 = (**(code **)(*(longlong *)(lVar5 + 8) + 0x50))(lVar5);
    param_4 = (ulonglong)uVar2;
    pcVar4 = "QC_SDHC[%p] PlGetPendingEvents(ReadDmaCounter 0x%x)\r\n";
    uVar6 = param_1;
    SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlGetPendingEvents(ReadDmaCounter 0x%x)\r\n",param_1,param_4
                   );
    if ((uVar2 == 0) && ((uVar3 & 0x40) != 0)) {
      param_4 = 0;
      pcVar4 = *(char **)(*(longlong *)(param_1 + 8) + 0x10);
      uVar6 = param_1;
      PlDmaCompletionRoutine(lVar5,pcVar4,param_1,0);
    }
  }
  if ((uVar3 >> 0xc != 0) && (*(int *)(param_1 + 0x1750) - 0x10U < 10)) {
    PlDebugDumpRegs(param_1,pcVar4,uVar6,param_4);
  }
  uVar7 = (ulonglong)uVar1;
  pcVar4 = "QC_SDHC[%p] PlGetPendingEvents(hw=%8.8x -> sw=%8.8x)\r\n";
  uVar6 = param_1;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlGetPendingEvents(hw=%8.8x -> sw=%8.8x)\r\n",param_1,uVar7);
  if (*(char *)(param_1 + 0x24) == '\x01') {
    SdbusWait(500,pcVar4,uVar6,uVar7);
  }
  return uVar3;
}



===== PlGetResponse @ 1400105a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 PlGetResponse(longlong param_1,byte *param_2,uint param_3,void *param_4)

{
  undefined4 *_Src;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  uint local_50;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = *(undefined4 *)(param_2 + 0x10);
  local_50 = param_3;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlGetResponse CMD%2d (type 0x%x, len=%d)\r\n",param_1,
                  (ulonglong)*param_2);
  if (*(int *)(param_2 + 0x10) == 4) {
    local_48 = (undefined1  [4])SdbusReadRegisterUlong(param_1,0x20);
    local_44 = SdbusReadRegisterUlong(param_1,0x1c);
    local_40 = SdbusReadRegisterUlong(param_1,0x18);
    local_3c = SdbusReadRegisterUlong(param_1,0x14);
    _Src = (undefined4 *)((longlong)local_48 + 1);
    param_3 = param_3 - 1;
  }
  else {
    local_48 = (undefined1  [4])SdbusReadRegisterUlong(param_1,0x14);
    _Src = (undefined4 *)local_48;
  }
  memcpy(param_4,_Src,(ulonglong)param_3);
  return 0;
}



===== PlInitializeCard @ 140010680 =====

void PlInitializeCard(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlInitializeCard)",param_1,param_4);
  return;
}



===== PlInitializeFunction @ 1400106b0 =====

void PlInitializeFunction
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlInitializeFunction",param_1,param_4);
  return;
}



===== PlInitializeSignaling @ 1400106e0 =====

undefined8 PlInitializeSignaling(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = 4;
  uVar1 = SdbusReadRegisterUlong(param_2,4);
  SdbusWriteRegisterUlong(param_2,uVar2,uVar1 & 0xfffffdff);
  return 0;
}



===== PlInitializeSocket @ 140010720 =====

void PlInitializeSocket(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlInitializeSocket",param_1,param_4);
  *(undefined4 *)(param_1 + 0x2a40) = 10000;
  *(undefined1 *)(param_1 + 0x1154) = 0;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x800;
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x1150) = 0;
  *(undefined4 *)(param_1 + 0x1146) = 0x8000200;
  *(undefined2 *)(param_1 + 0x1127) = 0x100;
  *(undefined2 *)(param_1 + 0x1124) = 0x101;
  *(undefined4 *)(param_1 + 0x1140) = 0x80000;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p - PlSetHighSpeed(set=%d)",param_1,0);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x800000;
  SdbusWriteRegisterUlong(param_1,0x3c,0);
  SdbusWriteRegisterUlong(param_1,0x40,0);
  uVar2 = 0x7ffffff;
  uVar1 = 0x38;
  SdbusWriteRegisterUlong(param_1,0x38,0x7ffffff);
  PlDebugDumpRegs(param_1,uVar1,uVar2,uVar3);
  return;
}



===== PlInitializeSocketDma @ 1400107f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PlInitializeSocketDma(longlong param_1)

{
  longlong lVar1;
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  if ((*(char *)(param_1 + 0x24) != '\0') &&
     ((byte)(*(char *)(*(longlong *)(param_1 + 8) + 0x45) - 8U) < 2)) {
    lVar1 = *(longlong *)(param_1 + 0x2d8);
    if (lVar1 != 0) {
      (**(code **)(*(longlong *)(lVar1 + 8) + 0xa8))(lVar1,0x10010000,local_res8);
    }
    lVar1 = *(longlong *)(param_1 + 0x2e0);
    if (lVar1 != 0) {
      (**(code **)(*(longlong *)(lVar1 + 8) + 0xa8))(lVar1,0x10010000,local_res8);
    }
    lVar1 = *(longlong *)(param_1 + 0x2e8);
    if (lVar1 != 0) {
      (**(code **)(*(longlong *)(lVar1 + 8) + 0xa8))(lVar1,0x10010000,local_res8);
    }
  }
  return 0;
}



===== PlInitializeTransfer @ 1400108a0 =====

undefined8
PlInitializeTransfer
          (longlong param_1,ushort param_2,ushort param_3,undefined4 param_4,int param_5,
          undefined8 param_6,undefined8 param_7,undefined1 param_8)

{
  uint uVar1;
  undefined8 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_5 == 1) {
    pcVar6 = "Read";
  }
  else {
    pcVar6 = "Write";
    if (param_5 != 2) {
      pcVar6 = "Unspecified";
    }
  }
  uVar7 = (uint)param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlInitializeTransfer: DIR=%s METHOD=%d, BLOCKS=%d x %d\r\n",
                  param_1,pcVar6);
  uVar3 = 0x2c;
  uVar1 = SdbusReadRegisterUlong(param_1,0x2c);
  if (param_5 == 0) {
    SdbusWriteRegisterUlong(param_1,uVar3,uVar1 & 0xfffffff6);
LAB_140010941:
    uVar2 = 0;
  }
  else {
    if (((param_3 != 0) || (param_2 != 0)) && (param_2 < 0x1001)) {
      if (param_3 == 0) {
        uVar5 = uVar7;
        uVar8 = 0;
      }
      else {
        uVar5 = param_3 * uVar7;
        uVar8 = uVar5;
      }
      if ((uVar5 & 3) == 0) {
        if (uVar5 < 0x2000000) {
          uVar4 = uVar1 & 0xfffffffb;
          if (param_5 == 1) {
            uVar4 = uVar4 | 2;
LAB_1400109d0:
            SdbusWriteRegisterUlong(param_1,0x24,0xffffffff);
          }
          else if (param_5 == 2) {
            uVar4 = uVar1 & 0xfffffff9;
            goto LAB_1400109d0;
          }
          SdbusWriteRegisterUlong(param_1,0x28,uVar5);
          SdbusWriteRegisterUlong
                    (param_1,0x2c,((uint)param_2 << 4 | uVar4 & 0xffff000f) & 0xfff7ffff);
          *(undefined4 *)(param_1 + 0x1788) = param_4;
          *(undefined1 *)(param_1 + 0x1790) = param_8;
          if (param_3 != 0) {
            uVar7 = uVar8;
          }
          *(undefined8 *)(param_1 + 0x176c) = param_6;
          *(uint *)(param_1 + 0x1780) = uVar7;
          *(undefined4 *)(param_1 + 0x174c) = 0;
          *(int *)(param_1 + 0x178c) = param_5;
          *(ushort *)(param_1 + 0x1786) = param_3;
          *(ushort *)(param_1 + 0x1784) = param_2;
          goto LAB_140010941;
        }
      }
      else {
        SdbusDebugPrint(0x4000,
                        "QC_SDHC[%p] PlInitializeTransfer: transfer size must be multiple of 4\r\n",
                        param_1,pcVar6);
      }
    }
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PlIsWriteProtected @ 140010a80 =====

longlong PlIsWriteProtected(longlong param_1,undefined8 param_2,undefined8 param_3,
                           undefined8 param_4)

{
  uint7 uVar2;
  longlong lVar1;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlIsWriteProtected",param_1,param_4);
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 8) >> 8);
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x388) == 0) {
    lVar1 = (ulonglong)uVar2 << 8;
  }
  else {
    lVar1 = CONCAT71(uVar2,*(undefined1 *)(param_1 + 0x1179));
  }
  return lVar1;
}



===== PlPrepareTransfer @ 140010ad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140010e1d) */

int PlPrepareTransfer(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  longlong lVar7;
  ulonglong uVar8;
  bool bVar9;
  undefined1 auStack_b8 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  local_48 = 0;
  uStack_40 = 0;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlPrepareTransfer: phase %d\r\n",param_2,
                  (ulonglong)*(uint *)(param_2 + 0x174c));
  if (*(int *)(param_2 + 0x174c) == 0) {
    *(undefined1 *)(param_2 + 0x17a8) = 0;
    *(undefined1 *)(param_2 + 0x358) = 0;
    if (*(char *)(param_2 + 0x24) == '\0') {
      *(undefined8 *)(param_2 + 0x300) = 0;
    }
    if (*(int *)(param_2 + 0x1788) == 4) {
      if (*(int *)(param_2 + 0x178c) == 1) {
        uVar6 = 0x2c;
        uVar3 = SdbusReadRegisterUlong(param_2,0x2c);
        SdbusWriteRegisterUlong(param_2,uVar6,uVar3 | 8);
      }
      if (*(int *)(param_2 + 0x1788) == 4) {
        if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') {
          bVar9 = *(int *)(param_2 + 0x178c) == 2;
          if (bVar9) {
            *(undefined4 *)(param_2 + 0x17a4) = *(undefined4 *)(param_2 + 0x2f8);
            *(undefined8 *)(param_2 + 0x1774) = *(undefined8 *)(param_2 + 0x340);
            *(undefined4 *)(param_2 + 0x177c) = *(undefined4 *)(param_2 + 0x338);
            lVar7 = *(longlong *)(param_2 + 0x2e8);
          }
          else {
            *(undefined4 *)(param_2 + 0x17a4) = *(undefined4 *)(param_2 + 0x2f4);
            *(undefined8 *)(param_2 + 0x1774) = *(undefined8 *)(param_2 + 0x330);
            *(undefined4 *)(param_2 + 0x177c) = *(undefined4 *)(param_2 + 0x32c);
            lVar7 = *(longlong *)(param_2 + 0x2e0);
          }
          uStack_40 = CONCAT44(CONCAT31(uStack_40._5_3_,bVar9),*(undefined4 *)(param_2 + 0x1780));
          local_48 = CONCAT44((uint)*(ushort *)(param_2 + 0x1784),0x10);
          (**(code **)(*(longlong *)(lVar7 + 8) + 0xa8))(lVar7,0x10050000,&local_48);
          if (*(int *)(param_2 + 0x178c) == 1) {
            uVar3 = SdbusReadRegisterUlong(param_2,0x2c);
            do {
              uVar4 = SdbusReadRegisterUlong(param_2,0x6c);
            } while ((uVar4 & 1) != 0);
            SdbusWriteRegisterUlong(param_2,0x2c,uVar3 | 1);
          }
        }
        else {
          lVar7 = *(longlong *)(param_2 + 0x2d8);
          *(undefined4 *)(param_2 + 0x17a4) = *(undefined4 *)(param_2 + 0x35c);
          *(undefined8 *)(param_2 + 0x1774) = *(undefined8 *)(param_2 + 0x380);
          *(undefined4 *)(param_2 + 0x177c) = *(undefined4 *)(param_2 + 0x378);
        }
        lVar1 = *(longlong *)(param_2 + 0x308);
        if (lVar1 == 0) {
          if (*(char *)(param_2 + 0x24) != '\0') {
            puVar2 = *(undefined8 **)(param_2 + 800);
            *(undefined8 **)(param_2 + 0x308) = puVar2;
            uVar8 = *(ulonglong *)(param_2 + 0x176c);
            uVar3 = *(uint *)(param_2 + 0x1780);
            *puVar2 = 0;
            *(undefined2 *)((longlong)puVar2 + 10) = 0;
            *(uint *)(puVar2 + 5) = uVar3;
            puVar2[4] = uVar8 & 0xfffffffffffff000;
            *(short *)(puVar2 + 1) =
                 ((short)((uVar8 & 0xfff) + 0xfff + (ulonglong)uVar3 >> 0xc) + 6) * 8;
            *(uint *)((longlong)puVar2 + 0x2c) = (uint)uVar8 & 0xfff;
            MmBuildMdlForNonPagedPool(*(undefined8 *)(param_2 + 0x308));
            *(ulonglong *)(param_2 + 0x370) =
                 (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x308) + 0x2c) +
                 *(longlong *)(*(longlong *)(param_2 + 0x308) + 0x20);
            *(undefined8 *)(param_2 + 0x179c) = 0;
          }
        }
        else {
          *(longlong *)(param_2 + 0x370) = *(longlong *)(param_2 + 0x918);
          *(ulonglong *)(param_2 + 0x179c) =
               (*(longlong *)(param_2 + 0x918) - (ulonglong)*(uint *)(lVar1 + 0x2c)) -
               *(longlong *)(lVar1 + 0x20);
        }
        uVar3 = *(uint *)(param_2 + 0x1780);
        uVar8 = (ulonglong)uVar3;
        *(uint *)(param_2 + 0x1794) = uVar3;
        (**(code **)(*(longlong *)(lVar7 + 8) + 0x88))(lVar7);
        if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') &&
           (*(int *)(param_2 + 0x178c) == 2)) {
          *(undefined1 *)(param_2 + 0x17a8) = 1;
          *(undefined1 *)(param_2 + 0x358) = 1;
        }
        *(undefined4 *)(param_2 + 0x17a4) = 0;
        iVar5 = (**(code **)(*(longlong *)(lVar7 + 8) + 0x90))
                          (lVar7,*(undefined8 *)(param_2 + 0x318));
        if (iVar5 < 0) {
          SdbusDebugPrint(0x4000,
                          "QC_SDHC[%p] PlPrepareTransfer: Unable to initialize DMA transfer context"
                          ,param_2,uVar8);
        }
        else {
          if (*(char *)(param_2 + 0x24) == '\0') {
            *(longlong *)(param_2 + 0x2a28) = *(longlong *)(param_2 + 0x2a28) + 1;
            iVar5 = (**(code **)(*(longlong *)(lVar7 + 8) + 0xa0))
                              (lVar7,*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x68),
                               *(undefined8 *)(param_2 + 0x318),*(undefined4 *)(param_2 + 0x17a4));
            if (iVar5 < 0) goto LAB_140010ef5;
          }
          else {
            SdbusWorkerPushEvents(param_2,0x20000,0,'\x01','\0');
          }
          *param_1 = 0x20000;
          iVar5 = -0x3fffffea;
          *(undefined4 *)(param_2 + 0x174c) = 1;
        }
      }
      else {
        iVar5 = -0x3ffffff3;
      }
LAB_140010ef5:
      if (iVar5 == -0x3fffffea) {
        return -0x3fffffea;
      }
      goto LAB_140010f37;
    }
    if (*(int *)(param_2 + 0x178c) == 1) {
      uVar3 = SdbusReadRegisterUlong(param_2,0x2c);
      do {
        uVar4 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar4 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,0x2c,uVar3 | 1);
    }
  }
  else {
    if (*(int *)(param_2 + 0x174c) != 1) {
      iVar5 = -0x3fffffff;
      goto LAB_140010f37;
    }
    *(undefined1 *)(param_2 + 0x359) = 1;
  }
  iVar5 = 0;
LAB_140010f37:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return iVar5;
}



===== PlQueryTransferMode @ 140010f80 =====

undefined4 PlQueryTransferMode(longlong param_1)

{
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlQueryTransferMode = %d",param_1,
                  (ulonglong)*(uint *)(param_1 + 0x2d0));
  return *(undefined4 *)(param_1 + 0x2d0);
}



===== PlReadDataPort @ 140010fc0 =====

void PlReadDataPort(longlong param_1,undefined4 *param_2,uint param_3)

{
  ReadDataPortInternal(param_1,param_2,param_3);
  return;
}



===== PlResetHost @ 140010fe0 =====

undefined8 PlResetHost(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  bool bVar9;
  
  pcVar5 = "QC_SDHC[%p] - PlResetHost";
  lVar7 = param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlResetHost",param_2,param_4);
  if (*(longlong *)(param_2 + 0x175c) != 0) goto LAB_1400110e9;
  lVar7 = 0x204;
  pcVar5 = (char *)0x4000;
  lVar4 = MmMapIoSpaceEx(0x900000);
  *(longlong *)(param_2 + 0x175c) = lVar4;
  if (lVar4 == 0) {
    return 0xc00000e5;
  }
  iVar1 = MmGetPhysicalAddress(*(undefined8 *)(param_2 + 0x228));
  if (iVar1 == 0x12140000) {
LAB_1400110df:
    *(undefined4 *)(param_2 + 0x1764) = 2;
  }
  else {
    if (iVar1 == 0x12180000) {
LAB_1400110d3:
      *(undefined4 *)(param_2 + 0x1764) = 3;
      goto LAB_1400110e9;
    }
    if (iVar1 != 0x121c0000) {
      if (iVar1 == 0x12200000) {
        *(undefined4 *)(param_2 + 0x1764) = 5;
        goto LAB_1400110e9;
      }
      if ((iVar1 == 0x12400000) || (iVar1 == -0x67dc000)) {
        *(undefined4 *)(param_2 + 0x1764) = 1;
        goto LAB_1400110e9;
      }
      if (iVar1 == -0x679c000) goto LAB_1400110df;
      if (iVar1 == -0x675c000) goto LAB_1400110d3;
      if (iVar1 != -0x671c000) {
        *(undefined4 *)(param_2 + 0x1764) = 0;
        return 0xc00000e5;
      }
    }
    *(undefined4 *)(param_2 + 0x1764) = 4;
  }
LAB_1400110e9:
  if (param_3 - 1U < 2) {
    do {
      uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
    } while ((uVar2 & 1) != 0);
    SdbusWriteRegisterUlong(param_2,0xc,0);
    do {
      uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
    } while ((uVar2 & 1) != 0);
    uVar6 = 0x2c;
    uVar8 = 0;
    SdbusWriteRegisterUlong(param_2,0x2c,0);
    uVar2 = (int)uVar6 + 6;
  }
  else {
    if (param_3 == 0) {
      uVar2 = SdbusReadRegisterUlong(param_2,0xc);
      do {
        uVar3 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar3 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,0xc,uVar2 & 0xfffffbff);
      do {
        uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar2 & 1) != 0);
      pcVar5 = (char *)0x2c;
      lVar7 = 0;
      SdbusWriteRegisterUlong(param_2,0x2c,0);
      SdbusWait((int)pcVar5 + 6,pcVar5,lVar7,param_4);
    }
    lVar4 = *(longlong *)(param_2 + 0x175c);
    uVar3 = (*(int *)(param_2 + 0x1764) + -1) * 0x20;
    uVar2 = *(uint *)((ulonglong)uVar3 + 0x2830 + lVar4);
    *(uint *)((ulonglong)uVar3 + 0x2830 + lVar4) = uVar2 | 1;
    LOCK();
    UNLOCK();
    SdbusWait(10000,pcVar5,lVar7,param_4);
    *(uint *)((ulonglong)uVar3 + 0x2830 + lVar4) = uVar2 & 0xfffffffe;
    LOCK();
    UNLOCK();
    SdbusWriteRegisterUlong(param_2,0x3c,0);
    SdbusWriteRegisterUlong(param_2,0x40,0);
    SdbusWriteRegisterUlong(param_2,0x38,0x7ffffff);
    if (*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') {
      uVar2 = SdbusReadRegisterUlong(param_2,0x70);
      bVar9 = (uVar2 & 0x7800000) == 0x4000000;
      if (bVar9) {
        *(undefined1 *)(param_2 + 0x112b) = 1;
      }
      *(bool *)(param_2 + 0x1128) = bVar9;
      if ((uVar2 & 1) != 0) {
        *(undefined2 *)(param_2 + 0x1129) = 0x101;
        *(undefined1 *)(param_2 + 0x112b) = 1;
      }
    }
    SdbusWriteRegisterUlong(param_2,4,0x9300);
    do {
      uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
    } while ((uVar2 & 1) != 0);
    uVar8 = 3;
    SdbusWriteRegisterUlong(param_2,0,3);
    do {
      uVar6 = 0x6c;
      uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
    } while ((uVar2 & 1) != 0);
    uVar2 = 10000;
  }
  SdbusWait(uVar2,uVar6,uVar8,param_4);
  return 0;
}



===== PlSelectPState @ 1400112d0 =====

char PlSelectPState(longlong param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  if (9999 < param_2) {
    iVar1 = *(int *)(param_1 + 0x1120);
    if ((iVar1 == 1) || (iVar1 == 2)) {
      if (*(char *)(param_1 + 0x1659) == '\0') {
        if (*(char *)(param_1 + 0x165a) == '\0') {
          if (*(char *)(param_1 + 0x165b) == '\0') {
            if (*(char *)(param_1 + 0x1658) == '\0') {
              cVar2 = (*(char *)(param_1 + 0x165c) != '\0') + '\x01';
            }
            else {
              cVar2 = (*(char *)(param_1 + 0x165c) != '\0') + '\x04';
            }
          }
          else {
            cVar2 = '\x06';
          }
        }
        else {
          cVar2 = '\t';
        }
      }
      else {
        cVar2 = '\v';
      }
    }
    else if (iVar1 == 3) {
      if (*(char *)(param_1 + 0x165b) == '\0') {
        cVar2 = (-(*(char *)(param_1 + 0x1658) != '\0') & 4U) + 3;
      }
      else {
        cVar2 = '\b';
      }
    }
  }
  return cVar2;
}



===== PlSendCommand @ 140011380 =====

void PlSendCommand(longlong param_1,byte *param_2,int param_3,undefined8 param_4)

{
  SendCommand(param_1,param_2,param_3,param_4,'\0');
  return;
}



===== PlSetBusWidth @ 1400113a0 =====

void PlSetBusWidth(longlong param_1,byte param_2)

{
  uint uVar1;
  ushort uVar2;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlSetBusWidth(wide=%d)",param_1,(ulonglong)param_2);
  uVar2 = 4;
  uVar1 = SdbusReadRegisterUlong(param_1,4);
  uVar1 = uVar1 & 0xfffff3ff;
  if (param_2 != 0) {
    if ((*(char *)(param_1 + 0x1177) == '\0') || (*(char *)(param_1 + 0x1128) == '\0')) {
      uVar1 = uVar1 | 0x800;
    }
    else {
      uVar1 = uVar1 | 0xc00;
    }
  }
  SdbusWriteRegisterUlong(param_1,uVar2,uVar1);
  return;
}



===== PlSetBusWidthExplicit @ 140011420 =====

void PlSetBusWidthExplicit(longlong param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlSetBusWidthExplicit(width=%d)",param_1,(ulonglong)param_2)
  ;
  iVar2 = 4;
  uVar1 = SdbusReadRegisterUlong(param_1,4);
  uVar1 = uVar1 & 0xfffff3ff;
  if (param_2 != 1) {
    if (param_2 == 4) {
      uVar1 = uVar1 | 0x800;
    }
    else if (param_2 - 4 == iVar2) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  SdbusWriteRegisterUlong(param_1,(ushort)iVar2,uVar1);
  return;
}



===== PlSetClock @ 140011490 =====

undefined4 PlSetClock(undefined8 *param_1,ulonglong param_2,byte param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined7 extraout_var;
  uint *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  
  pcVar6 = "QC_SDHC[%p] PlSetClock(enable=%d, Freq=%d khz)\r\n";
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlSetClock(enable=%d, Freq=%d khz)\r\n",param_2,
                  (ulonglong)param_3);
  uVar7 = 1;
  if ((byte)(*(char *)(*(longlong *)(param_2 + 8) + 0x45) - 8U) < 2) {
    if (*(int *)(param_2 + 0x174c) == 0) {
      if (*(char *)(param_2 + 0x24) == '\0') {
        puVar14 = (undefined4 *)(param_2 + 0x177c);
        *puVar14 = 0;
        cVar1 = PlSelectPState(param_2,param_4);
        *(int *)(param_2 + 0x1780) = (int)CONCAT71(extraout_var,cVar1);
        *(undefined4 *)(param_2 + 6000) = 0;
        pcVar6 = &GUID_POWER_CHANGE_P_STATE;
        iVar2 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                                 &GUID_POWER_CHANGE_P_STATE,puVar14);
        if (-1 < iVar2) {
          *param_1 = 0x80000;
          uVar8 = 0xc0000016;
          goto LAB_1400117d0;
        }
      }
      if (param_4 < 10000) {
        puVar5 = &DAT_140024c44;
        piVar13 = &DAT_140024c48;
        puVar12 = &DAT_140024c54;
        piVar9 = &DAT_140024c50;
        puVar14 = &DAT_140024c4c;
        puVar15 = &DAT_140024c40;
      }
      else if (param_4 < 40000) {
        puVar5 = (uint *)&DAT_140024c5c;
        piVar13 = (int *)&DAT_140024c60;
        puVar12 = (uint *)&DAT_140024c6c;
        piVar9 = (int *)&DAT_140024c68;
        puVar14 = (undefined4 *)&DAT_140024c64;
        puVar15 = (undefined4 *)&DAT_140024c58;
      }
      else {
        puVar5 = (uint *)&DAT_140024c74;
        piVar13 = (int *)&DAT_140024c78;
        puVar12 = (uint *)&DAT_140024c84;
        piVar9 = (int *)&DAT_140024c80;
        puVar14 = (undefined4 *)&DAT_140024c7c;
        puVar15 = (undefined4 *)&DAT_140024c70;
      }
      uVar11 = *(ulonglong *)(param_2 + 0x175c);
      uVar4 = (*(int *)(param_2 + 0x1764) + -1) * 0x20;
      uVar10 = (ulonglong)uVar4;
      *(uint *)(uVar10 + 0x282c + uVar11) =
           *(uint *)((ulonglong)uVar4 + 0x282c + uVar11) & 0xfffff4ff;
      LOCK();
      UNLOCK();
      if (param_3 == 1) {
        *(uint *)(uVar10 + 0x282c + uVar11) = *(uint *)(uVar10 + 0x282c + uVar11) | 0x80;
        LOCK();
        UNLOCK();
        uVar3 = ((*(uint *)(uVar10 + 0x282c + uVar11) & 0xfffffff8 | *puVar5) & 0xffffffe7 |
                *piVar13 << 3) & 0xffffff9f;
        uVar4 = uVar3 | 0x40;
        if (*puVar12 == 0) {
          uVar4 = uVar3;
        }
        *(uint *)(uVar10 + 0x282c + uVar11) = uVar4 & 0xff00ffff | *piVar9 << 0x10;
        LOCK();
        UNLOCK();
        *(undefined4 *)(uVar10 + 0x2828 + uVar11) = *puVar14;
        LOCK();
        UNLOCK();
        *(uint *)(uVar10 + 0x282c + uVar11) = *(uint *)(uVar10 + 0x282c + uVar11) & 0xffffff7f;
        LOCK();
        UNLOCK();
        *(uint *)(uVar10 + 0x282c + uVar11) =
             (*puVar12 | 10) << 8 | *(uint *)(uVar10 + 0x282c + uVar11) & 0xfffffeff;
        LOCK();
        UNLOCK();
        *(uint *)(uVar10 + 0x2820 + uVar11) = *(uint *)(uVar10 + 0x2820 + uVar11) | 0x10;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_2 + 0x167c) = *puVar15;
        pcVar6 = 
        "QC_SDHC[%p] PlSetClock(Freq=%d Khz -> HCLK_CTL=%8.8x, CLK_MD=%8.8x, CLK_NS=%8.8x)\r\n";
        uVar11 = (ulonglong)*(uint *)(param_2 + 0x167c);
        uVar10 = param_2;
        SdbusDebugPrint(0x4000,
                        "QC_SDHC[%p] PlSetClock(Freq=%d Khz -> HCLK_CTL=%8.8x, CLK_MD=%8.8x, CLK_NS=%8.8x)\r\n"
                        ,param_2,uVar11);
      }
      SdbusWait(10000,pcVar6,uVar10,uVar11);
    }
    else {
      if (*(int *)(param_2 + 0x174c) != 1) {
        uVar8 = 0xc000000d;
        goto LAB_1400117cd;
      }
      *(undefined4 *)(param_2 + 0x167c) = *(undefined4 *)(param_2 + 0x1678);
    }
    uVar8 = 0;
    uVar3 = SdbusReadRegisterUlong(param_2,4);
    uVar4 = uVar3 & 0xfffffeff | 0x100;
    if (param_3 == 0) {
      uVar4 = uVar3 & 0xfffffeff;
    }
    if (uVar4 != uVar3) {
      do {
        uVar4 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar4 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,4,uVar3);
    }
  }
  else {
    uVar8 = 0xc0000010;
  }
LAB_1400117cd:
  uVar7 = 0;
LAB_1400117d0:
  *(undefined4 *)(param_2 + 0x174c) = uVar7;
  return uVar8;
}



===== PlSetEventMask @ 140011800 =====

void PlSetEventMask(longlong param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlSetEventMask(new=%8.8x, changed=%8.8x)\r\n",param_1,uVar4);
  uVar1 = PlEventMaskToHardwareMask(param_3);
  if (uVar1 != 0) {
    if (*(char *)(param_1 + 0x24) == '\x01') {
      SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlSetEventMask: ignored in crash dump mode\r\n",param_1,
                      uVar4);
    }
    else {
      uVar2 = SdbusReadRegisterUlong(param_1,0x3c);
      uVar2 = uVar2 & ~uVar1;
      uVar3 = PlEventMaskToHardwareMask(param_2);
      uVar2 = uVar2 | uVar3 & uVar1;
      uVar1 = uVar2 & 0xffbfffff;
      if ((uVar2 >> 0x16 & 1) == 0) {
        uVar1 = uVar2;
      }
      uVar2 = uVar1 & 0xfdffffff;
      if (*(int *)(param_1 + 0x1120) == 1) {
        uVar2 = uVar1;
      }
      SdbusDebugPrint(0x4000,"QC_SDHC PlSetEventMask(hwmask=%8.8x)\r\n",
                      (ulonglong)(uVar2 & 0x7ffffff),(ulonglong)uVar1);
      SdbusWriteRegisterUlong(param_1,0x3c,uVar2 & 0x7ffffff);
    }
  }
  return;
}



===== PlSetHighSpeed @ 1400118f0 =====

void PlSetHighSpeed(undefined8 param_1,byte param_2)

{
  SdbusDebugPrint(0x4000,"QC_SDHC[%p - PlSetHighSpeed(set=%d)",param_1,(ulonglong)param_2);
  return;
}



===== PlSetPower @ 140011920 =====

undefined8 PlSetPower(undefined8 param_1,longlong param_2,uint param_3)

{
  *(undefined4 *)(param_2 + 0x1690) = 0x80000;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - PlSetPower voltage profile=0%x",param_2,(ulonglong)param_3);
  return 0;
}



===== PlSetSignaling @ 140011960 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PlSetSignaling(undefined8 *param_1,longlong param_2,char param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 local_res10;
  
  uVar6 = 0;
  uVar8 = CONCAT71((int7)((ulonglong)param_4 >> 8),param_3);
  local_res10 = 0;
  uVar9 = 0;
  if (*(int *)(param_2 + 0x174c) == 0) {
    *(undefined4 *)(param_2 + 0x177c) = 0;
    *(uint *)(param_2 + 0x1780) = (param_3 != '\0') + 0x14;
    iVar4 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(param_2 + 8) + 0x120),
                             &GUID_POWER_CHANGE_P_STATE,(undefined4 *)(param_2 + 0x177c),8,
                             param_2 + 6000,0xc,&local_res10);
    if (iVar4 < 0) {
LAB_140011b26:
      uVar6 = 0xc0000001;
    }
    else {
      *param_1 = 0x80000;
      uVar6 = 0xc0000016;
      *(undefined4 *)(param_2 + 0x174c) = 1;
    }
  }
  else if (*(int *)(param_2 + 0x174c) == 1) {
    if (param_3 != '\0') {
      uVar2 = SdbusReadRegisterUlong(param_2,4);
      do {
        uVar3 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar3 & 1) != 0);
      uVar5 = 4;
      uVar7 = (ulonglong)(uVar2 | 0x200000);
      SdbusWriteRegisterUlong(param_2,4,uVar2 | 0x200000);
      SdbusWait(5000,uVar5,uVar7,uVar8);
      uVar2 = uVar2 | 0x200200;
      do {
        uVar3 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar3 & 1) != 0);
      uVar5 = 4;
      uVar7 = (ulonglong)uVar2;
      SdbusWriteRegisterUlong(param_2,4,uVar2);
      SdbusWait(5000,uVar5,uVar7,uVar8);
      do {
        uVar3 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar3 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,4,uVar2 & 0xfffffdff);
      iVar4 = KeQueryTimeIncrement();
      lVar1 = _DAT_fffff78000000320;
      do {
        uVar3 = SdbusReadRegisterUlong(param_2,0xd4);
        uVar9 = uVar9 | uVar3;
        if ((longlong)(ulonglong)((int)(10000000 / (ulonglong)(uint)(iVar4 * 100)) + 1) <
            _DAT_fffff78000000320 - lVar1) goto LAB_140011b26;
      } while ((((byte)uVar9 & 0x1e) != 0x1e) || ((uVar9 & 0x20) == 0));
      do {
        uVar9 = SdbusReadRegisterUlong(param_2,0x6c);
      } while ((uVar9 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,4,uVar2 & 0xfffffdff | 0x200);
    }
  }
  else {
    uVar6 = 0xc000000d;
  }
  return uVar6;
}



===== PlSetUhsMode @ 140011b70 =====

undefined8 PlSetUhsMode(undefined8 param_1,longlong param_2,short param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = SdbusReadRegisterUlong(param_2,4);
  if (param_3 == 2) {
    if (*(char *)(param_2 + 0x1129) != '\0') {
      uVar1 = uVar1 & 0xffffbfff | 0x8000;
    }
  }
  else if (param_3 == 3) {
    if (*(char *)(param_2 + 0x112a) != '\0') {
      uVar1 = uVar1 & 0xffff3fff | 0x10000;
    }
  }
  else {
    if (param_3 != 4) {
      return 0xc000000d;
    }
    uVar2 = uVar1 | 0xc000;
    if (*(char *)(param_2 + 0x112b) == '\0') {
      uVar2 = uVar1;
    }
    uVar1 = uVar2;
  }
  do {
    uVar2 = SdbusReadRegisterUlong(param_2,0x6c);
  } while ((uVar2 & 1) != 0);
  SdbusWriteRegisterUlong(param_2,4,uVar1);
  return 0;
}



===== PlStartTransfer @ 140011c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PlStartTransfer(undefined4 *param_1,longlong param_2)

{
  longlong *plVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  short sVar10;
  ushort uVar11;
  undefined8 uVar12;
  byte bVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  byte *pbVar17;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  uVar15 = (ulonglong)*(uint *)(param_2 + 0x174c);
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlStartTransfer: phase %d\r\n",param_2,uVar15);
  uVar4 = SdCommandTimeout;
  plVar1 = (longlong *)(param_2 + 8);
  piVar2 = (int *)(param_2 + 0x178c);
  if (*(char *)(*plVar1 + 0x45) == '\t') {
    if (*piVar2 == 2) {
      lVar14 = *(longlong *)(param_2 + 0x2e8);
    }
    else {
      lVar14 = *(longlong *)(param_2 + 0x2e0);
    }
  }
  else {
    lVar14 = *(longlong *)(param_2 + 0x2d8);
  }
  iVar8 = *(int *)(param_2 + 0x174c);
  if (iVar8 == 0) {
    if (*(int *)(param_2 + 0x1788) != 1) {
      if (*(int *)(param_2 + 0x1788) != 4) {
        uVar15 = 0xc000000d;
        goto LAB_14001248e;
      }
      *(longlong *)(param_2 + 0x29f0) = *(longlong *)(param_2 + 0x29f0) + 1;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350,&local_40);
      *(undefined1 *)(param_2 + 0x349) = 1;
      KeReleaseInStackQueuedSpinLockFromDpcLevel();
      if ((*(char *)(param_2 + 0x24) == '\0') && (*(char *)(param_2 + 0x17a8) == '\0')) {
        uVar4 = (**(code **)(*(longlong *)(lVar14 + 8) + 0xb8))
                          (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),
                           *(undefined8 *)(param_2 + 0x179c),0x80,param_2 + 0x1794,*piVar2 == 2,
                           *(undefined8 *)(param_2 + 0x1774),*(undefined4 *)(param_2 + 0x177c),
                           PlDmaCompletionRoutine,param_2);
        if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') && (*piVar2 == 2)) {
          uVar11 = 0x2c;
          uVar7 = SdbusReadRegisterUlong(param_2,0x2c);
          SdbusWriteRegisterUlong(param_2,uVar11,uVar7 | 1);
        }
        uVar5 = 0x400040;
      }
      else {
        uVar4 = (**(code **)(*(longlong *)(lVar14 + 8) + 0xb8))
                          (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),
                           *(undefined8 *)(param_2 + 0x179c),0x80,param_2 + 0x1794,*piVar2 == 2,
                           *(undefined8 *)(param_2 + 0x1774),*(undefined4 *)(param_2 + 0x177c),0,0);
        if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') && (*piVar2 == 2)) {
          uVar11 = 0x2c;
          uVar7 = SdbusReadRegisterUlong(param_2,0x2c);
          SdbusWriteRegisterUlong(param_2,uVar11,uVar7 | 9);
        }
        uVar5 = 0x40;
        if (*(char *)(param_2 + 0x24) != '\0') {
          uVar5 = 0x400040;
        }
      }
      uVar7 = SdTransferTimeout;
      if (-1 < (int)uVar4) {
        param_1[1] = 100000000;
        param_1[2] = uVar7 / 100;
        *param_1 = uVar5;
        *(undefined4 *)(param_2 + 0x174c) = 1;
        return 0xc0000016;
      }
      goto LAB_140012414;
    }
    iVar8 = 0;
    if (*(int *)(param_2 + 0x1120) != 1) {
      uVar11 = 0x3c;
      iVar8 = SdbusReadRegisterUlong(param_2,0x3c);
      SdbusWriteRegisterUlong(param_2,uVar11,0);
    }
    if ((*(char *)(*(longlong *)(param_2 + 8) + 0x45) == '\t') && (*piVar2 == 2)) {
      uVar11 = 0x2c;
      uVar4 = SdbusReadRegisterUlong(param_2,0x2c);
      SdbusWriteRegisterUlong(param_2,uVar11,uVar4 | 1);
    }
    if (*(int *)(param_2 + 0x178c) == 2) {
      uVar12 = WriteDataPortInternal
                         (param_2,*(undefined4 **)(param_2 + 0x176c),*(uint *)(param_2 + 0x1780));
      uVar4 = (uint)uVar12;
    }
    else {
      uVar12 = ReadDataPortInternal
                         (param_2,*(undefined4 **)(param_2 + 0x176c),*(uint *)(param_2 + 0x1780));
      uVar4 = (uint)uVar12;
    }
    uVar15 = (ulonglong)uVar4;
    if (iVar8 != 0) {
      SdbusWriteRegisterUlong(param_2,0x3c,iVar8);
    }
    if (-1 < (int)uVar4) {
      *param_1 = 0;
      uVar15 = 0xc0000016;
      *(undefined4 *)(param_2 + 0x174c) = 2;
    }
  }
  else if (iVar8 == 1) {
    puVar3 = (uint *)(param_2 + 0x1794);
    uVar5 = 1;
    uVar4 = *(int *)(param_2 + 0x1780) - *puVar3;
    *(uint *)(param_2 + 0x1780) = uVar4;
    if (uVar4 == 0) {
      if (*(char *)(param_2 + 0x24) == '\0') {
        if (*(char *)(param_2 + 0x17a8) != '\0') {
          *(longlong *)(param_2 + 0x29f8) = *(longlong *)(param_2 + 0x29f8) + 1;
          uVar15 = *(ulonglong *)(param_2 + 0x179c);
          (**(code **)(*(longlong *)(lVar14 + 8) + 0xd0))
                    (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),uVar15
                     ,*puVar3,*piVar2 == 2);
          KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350,&local_40);
          *(undefined1 *)(param_2 + 0x349) = 0;
          KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_40);
          SdbusReadRegisterUlong(param_2,0x30);
        }
        *(longlong *)(param_2 + 0x2a30) = *(longlong *)(param_2 + 0x2a30) + 1;
        (**(code **)(*(longlong *)(lVar14 + 8) + 0x30))(lVar14);
        *(undefined1 *)(param_2 + 0x359) = 0;
      }
      sVar10 = 0xc;
      uVar4 = SdbusReadRegisterUlong(param_2,0xc);
      do {
        uVar7 = SdbusReadRegisterUlong(param_2,sVar10 + 0x60U);
      } while ((uVar7 & 1) != 0);
      SdbusWriteRegisterUlong(param_2,0xc,uVar4 & 0xfffffbff);
      do {
        uVar4 = SdbusReadRegisterUlong(param_2,sVar10 + 0x60U);
      } while ((uVar4 & 1) != 0);
      uVar12 = 0x2c;
      uVar16 = 0;
      SdbusWriteRegisterUlong(param_2,0x2c,0);
      SdbusWait((int)uVar12 + 6,uVar12,uVar16,uVar15);
      uVar6 = 0;
      uVar5 = 3;
LAB_140012197:
      *param_1 = uVar6;
      *(undefined4 *)(param_2 + 0x174c) = uVar5;
      return 0xc0000016;
    }
    *(longlong *)(param_2 + 0x179c) = *(longlong *)(param_2 + 0x179c) + (ulonglong)*puVar3;
    *puVar3 = uVar4;
    *(longlong *)(param_2 + 0x370) = *(longlong *)(param_2 + 0x370) + (ulonglong)uVar4;
    local_54 = 0;
    uStack_4c = 0;
    local_58 = 1;
    (**(code **)(*(longlong *)(lVar14 + 8) + 0x88))
              (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x179c),
               *(undefined4 *)(param_2 + 0x1780),*piVar2 == 2,&local_58);
    if (*(char *)(*plVar1 + 0x45) == '\t') {
      if (*piVar2 == 2) {
        uVar4 = *(uint *)(param_2 + 0x2f8);
      }
      else {
        uVar4 = *(uint *)(param_2 + 0x2f4);
      }
    }
    else {
      uVar4 = *(uint *)(param_2 + 0x35c);
    }
    *(uint *)(param_2 + 0x17a4) = uVar4;
    if (uVar4 < (uint)local_54) {
      *puVar3 = uVar4 << 0xc;
    }
    else {
      if ((*(char *)(*plVar1 + 0x45) == '\t') && (*piVar2 == 2)) {
        *(undefined1 *)(param_2 + 0x17a8) = 1;
        *(undefined1 *)(param_2 + 0x358) = 1;
      }
      *(uint *)(param_2 + 0x17a4) = (uint)local_54;
    }
    *(longlong *)(param_2 + 0x29f0) = *(longlong *)(param_2 + 0x29f0) + 1;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350,&local_40);
    *(undefined1 *)(param_2 + 0x349) = 1;
    KeReleaseInStackQueuedSpinLockFromDpcLevel();
    if ((*(char *)(param_2 + 0x24) == '\0') && (*(char *)(param_2 + 0x17a8) == '\0')) {
      uVar4 = (**(code **)(*(longlong *)(lVar14 + 8) + 0xb8))
                        (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),
                         *(undefined8 *)(param_2 + 0x179c),0x80,puVar3,*piVar2 == 2,
                         *(undefined8 *)(param_2 + 0x1774),*(undefined4 *)(param_2 + 0x177c),
                         PlDmaCompletionRoutine,param_2);
      uVar6 = 0x400040;
    }
    else {
      uVar4 = (**(code **)(*(longlong *)(lVar14 + 8) + 0xb8))
                        (lVar14,*(undefined8 *)(param_2 + 0x308),*(undefined8 *)(param_2 + 0x300),
                         *(undefined8 *)(param_2 + 0x179c),0x80,puVar3,*piVar2 == 2,
                         *(undefined8 *)(param_2 + 0x1774),*(undefined4 *)(param_2 + 0x177c),0,0);
      uVar6 = 0x40;
      if (*(char *)(param_2 + 0x24) != '\0') {
        uVar6 = 0x400040;
      }
    }
    uVar7 = SdTransferTimeout;
    if (-1 < (int)uVar4) {
      param_1[1] = 100000000;
      param_1[2] = uVar7 / 100;
      goto LAB_140012197;
    }
LAB_140012414:
    uVar15 = (ulonglong)uVar4;
    SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlStartTransfer: MapTransferEx failed: %08X",param_2,uVar15)
    ;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x350);
    *(undefined1 *)(param_2 + 0x349) = 0;
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_40);
  }
  else {
    if (iVar8 == 2) {
      param_1[1] = 2000000;
      param_1[2] = uVar4 / 100;
      *param_1 = 0x40;
      *(undefined4 *)(param_2 + 0x174c) = 3;
      return 0xc0000016;
    }
    if (iVar8 != 3) {
      if (iVar8 != 4) {
        uVar15 = 0xc0000001;
        goto LAB_14001248e;
      }
      goto LAB_140011d48;
    }
    uVar4 = *(uint *)(param_2 + 0x1750);
    iVar8 = 0;
    if ((uVar4 < 0x33) && ((0x4000001001000U >> ((ulonglong)uVar4 & 0x3f) & 1) != 0)) {
      iVar8 = *(int *)(param_2 + 0x168c);
      pbVar17 = &CmdDescSendStatus;
    }
    else if (uVar4 == 0x35) {
      pbVar17 = &CmdDescReadIoDirect;
      iVar8 = 0;
      if (*(int *)(param_2 + 0x178c) != 2) {
        pbVar17 = (byte *)0x0;
      }
      if (pbVar17 == (byte *)0x0) goto LAB_140011d48;
    }
    else {
      if (*(char *)(param_2 + 0x1790) == '\0') {
LAB_140011d48:
        sVar10 = 0xc;
        uVar4 = SdbusReadRegisterUlong(param_2,0xc);
        bVar13 = (char)sVar10 - 0xb;
        do {
          uVar5 = SdbusReadRegisterUlong(param_2,sVar10 + 0x60U);
        } while ((bVar13 & (byte)uVar5) != 0);
        SdbusWriteRegisterUlong(param_2,0xc,uVar4 & 0xfffffbff);
        do {
          uVar5 = SdbusReadRegisterUlong(param_2,sVar10 + 0x60U);
        } while ((bVar13 & (byte)uVar5) != 0);
        uVar12 = 0x2c;
        uVar16 = 0;
        SdbusWriteRegisterUlong(param_2,0x2c,0);
        SdbusWait((int)uVar12 + 6,uVar12,uVar16,uVar15);
        uVar15 = 0;
        goto LAB_14001248e;
      }
      pbVar17 = &CmdDescStopTransmission;
    }
    uVar9 = SendCommand(param_2,pbVar17,iVar8,uVar15,'\x01');
    uVar4 = SdCommandTimeout;
    uVar15 = uVar9 & 0xffffffff;
    if (-1 < (int)uVar9) {
      param_1[1] = 2000000;
      param_1[2] = uVar4 / 100;
      *param_1 = 0xc;
      if ((*pbVar17 == 0x34) || (*pbVar17 == 0xd)) {
        *(undefined4 *)(param_2 + 0x174c) = 4;
      }
      uVar15 = 0xc0000016;
    }
  }
  if ((int)uVar15 == -0x3fffffea) {
    return uVar15;
  }
LAB_14001248e:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  *(undefined1 *)(param_2 + 0x17a8) = 0;
  *(undefined1 *)(param_2 + 0x358) = 0;
  return uVar15;
}



===== PlWriteDataPort @ 1400124d0 =====

void PlWriteDataPort(longlong param_1,undefined4 *param_2,uint param_3)

{
  WriteDataPortInternal(param_1,param_2,param_3);
  return;
}



===== ReadDataPortInternal @ 1400124e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ReadDataPortInternal(longlong param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  
  lVar6 = param_1;
  puVar7 = param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlReadDataPort (buff=%p, len=%d)\r\n",param_1,param_2);
  if ((param_3 & 3) == 0) {
    iVar1 = KeQueryTimeIncrement();
    lVar6 = _DAT_fffff78000000320;
    for (uVar5 = 0; uVar5 < param_3 >> 2; uVar5 = uVar5 + 1) {
      do {
        uVar2 = SdbusReadRegisterUlong(param_1,0x34);
        if ((longlong)((1000000000 / (ulonglong)(uint)(iVar1 * 100)) * 10) <
            _DAT_fffff78000000320 - lVar6) {
          uVar2 = uVar2 | 0x2a;
          *(undefined4 *)(param_1 + 0x3f4) = 0x11;
          *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
          break;
        }
      } while ((uVar2 & 0x20002a) == 0);
      if ((uVar2 & 0x2a) != 0) {
        SdbusDebugPrint(1,"PlReadDataPort - ERROR! Stop Reading Data Error! Status(0x%x)\r\n",
                        (ulonglong)uVar2,puVar7);
        return 0xc0000001;
      }
      uVar3 = SdbusReadRegisterUlong(param_1,0x80);
      *param_2 = uVar3;
      param_2 = param_2 + 1;
    }
    uVar4 = 0;
  }
  else {
    SdbusDebugPrint(1,"ERROR: length must be a multiple of 4 bytes\r\n",lVar6,puVar7);
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== SendCommand @ 140012618 =====

undefined8 SendCommand(longlong param_1,byte *param_2,int param_3,undefined8 param_4,char param_5)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] SendCommand CMD%2d (Argument 0x%x)\r\n",param_1,
                  (ulonglong)*param_2);
  uVar3 = ClearStatusFlags(param_1);
  if (-1 < (int)uVar3) {
    iVar2 = *(int *)(param_2 + 0x10);
    bVar1 = *param_2;
    uVar4 = 0x440;
    if (iVar2 == 1) {
      uVar4 = 0x400;
    }
    uVar4 = uVar4 | bVar1 & 0x3f;
    if (iVar2 == 4) {
      uVar4 = uVar4 | 0x80;
    }
    uVar6 = uVar4 | 0x1000;
    if (*(int *)(param_2 + 0xc) == 1) {
      uVar6 = uVar4;
    }
    if ((iVar2 == 3) || (param_5 == '\x01')) {
      uVar6 = uVar6 | 0x800;
    }
    if ((bVar1 == 7) && (param_3 == 0)) {
      uVar6 = uVar6 & 0xfffff7ff;
    }
    if ((*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\b') && (1 < (byte)(bVar1 - 0x34))) {
      uVar5 = 0x3c;
      uVar4 = SdbusReadRegisterUlong(param_1,0x3c);
      if ((*(char *)(param_1 + 0x24) == '\0') && ((uVar4 & 0xc0) != 0)) {
        uVar7 = uVar4 & 0xff7fffff | 0x800000;
        if ((uVar6 >> 0xb & 1) == 0) {
          uVar7 = uVar4 & 0xff7fffff;
        }
        SdbusWriteRegisterUlong(param_1,uVar5,uVar7);
      }
    }
    *(uint *)(param_1 + 0x1750) = (uint)*param_2;
    *(int *)(param_1 + 0x1754) = param_3;
    SdbusWriteRegisterUlong(param_1,8,param_3);
    SdbusWriteRegisterUlong(param_1,0xc,uVar6);
    uVar3 = 0;
  }
  return uVar3;
}



===== WriteDataPortInternal @ 140012748 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 WriteDataPortInternal(longlong param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  
  lVar5 = param_1;
  puVar6 = param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] PlWriteDataPort (buff=%p, len=%d)\r\n",param_1,param_2);
  if ((param_3 & 3) == 0) {
    iVar1 = KeQueryTimeIncrement();
    lVar5 = _DAT_fffff78000000320;
    for (uVar4 = 0; uVar4 < param_3 >> 2; uVar4 = uVar4 + 1) {
      do {
        uVar2 = SdbusReadRegisterUlong(param_1,0x34);
        if ((longlong)((1000000000 / (ulonglong)(uint)(iVar1 * 100)) * 10) <
            _DAT_fffff78000000320 - lVar5) {
          uVar2 = uVar2 | 0x2a;
          *(undefined4 *)(param_1 + 0x3f4) = 0x11;
          *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
          break;
        }
      } while ((uVar2 & 0x1001a) == 0x10000);
      if ((uVar2 & 0x1a) != 0) goto LAB_14001283c;
      SdbusWriteRegisterUlong(param_1,0x80,*param_2);
      param_2 = param_2 + 1;
    }
    uVar2 = SdbusReadRegisterUlong(param_1,0x34);
    if ((uVar2 & 0x1a) == 0) {
      uVar3 = 0;
    }
    else {
LAB_14001283c:
      SdbusDebugPrint(1,"PlWriteDataPort - ERROR! Stop Writing Data Error! Status(0x%x)\r\n",
                      (ulonglong)uVar2,puVar6);
      uVar3 = 0xc0000001;
    }
  }
  else {
    SdbusDebugPrint(1,"ERROR: length must be a multiple of 4 bytes\r\n",lVar5,puVar6);
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== Pl180AcknowledgeEvent @ 140012890 =====

void Pl180AcknowledgeEvent(longlong param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = Pl180EventMaskToHardwareMask(param_2);
  SdbusWriteRegisterUlong(param_1,0x38,uVar1 & 0x7ff);
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180AcknowledgeEvent(sw=%8.8x -> hw=%8.8x)\r\n",param_1,
                  (ulonglong)param_2);
  Pl180SetEventMask(param_1,param_2 & 0xffffffcf,param_2);
  return;
}



===== Pl180CalcClockFrequency @ 140012910 =====

void Pl180CalcClockFrequency
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4,
               undefined2 *param_5)

{
  *param_4 = param_3;
  *param_5 = 0;
  return;
}



===== Pl180ClearStatusFlags @ 140012928 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Pl180ClearStatusFlags(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = KeQueryTimeIncrement();
  lVar2 = _DAT_fffff78000000320;
  do {
    SdbusWriteRegisterUlong(param_1,0x38,0x7ff);
    uVar4 = SdbusReadRegisterUlong(param_1,0x34);
    lVar1 = (longlong)((_DAT_fffff78000000320 - lVar2) * (ulonglong)(uint)(iVar3 * 100)) / 1000;
    if ((uVar4 & 0x7ff) == 0) {
      if (lVar1 < 0x1a) {
        return 0;
      }
      SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180ClearStatusFlags cleared in %lld usec\r\n",param_1
                      ,lVar1);
      return 0;
    }
  } while (lVar1 < 20000);
  SdbusDebugPrint(0x4000,
                  "PL180_SDHC[%p] Pl180ClearStatusFlags could not clear status flags in %lld usec (%8.8x)\r\n"
                  ,param_1,lVar1);
  return 0xc00000b5;
}



===== Pl180DebugDumpRegs @ 140012a20 =====

void Pl180DebugDumpRegs(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  SdbusDebugPrint(0x200000,"           *----------------- [%p] -------------------*",param_1,param_4
                 );
  SdbusReadRegisterUlong(param_1,8);
  uVar1 = SdbusReadRegisterUlong(param_1,4);
  uVar2 = SdbusReadRegisterUlong(param_1,0);
  SdbusDebugPrint(0x200000,"           MCI_POWER=0x%x MCI_CLK=0x%x MCI_ARGUMENT=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x14);
  uVar1 = SdbusReadRegisterUlong(param_1,0x10);
  uVar2 = SdbusReadRegisterUlong(param_1,0xc);
  SdbusDebugPrint(0x200000,"           MCI_CMD=0x%x MCI_RESPONSE_CMD=0x%x MCI_RESPONSE0=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x20);
  uVar1 = SdbusReadRegisterUlong(param_1,0x1c);
  uVar2 = SdbusReadRegisterUlong(param_1,0x18);
  SdbusDebugPrint(0x200000,"           MCI_RESPONSE1=0x%x MCI_RESPONSE2=0x%x MCI_RESPONSE3=0x%x\r\n"
                  ,(ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x2c);
  uVar1 = SdbusReadRegisterUlong(param_1,0x28);
  uVar2 = SdbusReadRegisterUlong(param_1,0x24);
  SdbusDebugPrint(0x200000,
                  "           MCI_DATA_TIMER=0x%x MCI_DATA_LENGTH=0x%x MCI_DATA_CONTROL=0x%x\r\n",
                  (ulonglong)uVar2,(ulonglong)uVar1);
  SdbusReadRegisterUlong(param_1,0x48);
  SdbusReadRegisterUlong(param_1,0x40);
  uVar1 = SdbusReadRegisterUlong(param_1,0x3c);
  uVar2 = SdbusReadRegisterUlong(param_1,0x34);
  uVar3 = (ulonglong)uVar2;
  uVar4 = (ulonglong)uVar1;
  SdbusDebugPrint(0x200000,
                  "           MCI_STATUS=0x%x MCI_INTERRUPT0=0x%x MCI_INTERRUPT1=0x%x MCI_FIFO_COUNT=0x%x\r\n"
                  ,uVar3,uVar4);
  SdbusDebugPrint(0x200000,"          *------------------------------------------*",uVar3,uVar4);
  return;
}



===== Pl180DetectCardInSocket @ 140012bf0 =====

undefined8
Pl180DetectCardInSocket(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined7 uVar2;
  undefined8 uVar1;
  
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180DetectCardInSocket",param_1,param_4);
  uVar2 = (undefined7)((ulonglong)*(longlong *)(param_1 + 8) >> 8);
  uVar1 = CONCAT71(uVar2,1);
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x380) != 0) {
    uVar1 = CONCAT71(uVar2,*(undefined1 *)(param_1 + 0x1654));
  }
  return uVar1;
}



===== Pl180DisableAllHostControllerInterrupts @ 140012c30 =====

void Pl180DisableAllHostControllerInterrupts
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180DisableAllHostControllerInterrupts\r\n",param_1,
                  param_4);
  SdbusWriteRegisterUlong(param_1,0x3c,0);
  SdbusWriteRegisterUlong(param_1,0x40,0);
  return;
}



===== Pl180EventMaskToHardwareMask @ 140012c7c =====

uint Pl180EventMaskToHardwareMask(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = -(uint)((param_1 & 4) != 0) & 0xc0;
  uVar2 = uVar1 | 0x23f;
  if ((param_1 >> 0xc & 1) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x100;
  if ((param_1 & 0x40) == 0) {
    uVar1 = uVar2;
  }
  uVar2 = uVar1 | 0x28000;
  if ((param_1 & 0x20) == 0) {
    uVar2 = uVar1;
  }
  uVar1 = uVar2 | 0x44000;
  if ((param_1 & 0x10) == 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}



===== Pl180GetErrorStates @ 140012ce0 =====

uint Pl180GetErrorStates(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = SdbusReadRegisterUlong(param_1,0x34);
  uVar2 = (uVar1 & 1) * 2;
  uVar3 = uVar2 | 0x20;
  if ((uVar1 & 2) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 1;
  if ((uVar1 & 4) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 0x10;
  if ((uVar1 & 8) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 0x11;
  if ((uVar1 & 0x230) == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}



===== Pl180GetPendingEvents @ 140012d40 =====

uint Pl180GetPendingEvents(longlong param_1,undefined8 param_2,longlong param_3,ulonglong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  uVar1 = SdbusReadRegisterUlong(param_1,0x34);
  if ((((uVar1 & 1) != 0) && (*(uint *)(param_1 + 0x1750) < 0x2a)) &&
     ((0x20000000022U >> ((ulonglong)*(uint *)(param_1 + 0x1750) & 0x3f) & 1) != 0)) {
    uVar1 = uVar1 & 0xfffffffe | 0x40;
    SdbusWriteRegisterUlong(param_1,0x38,1);
    param_4 = (ulonglong)*(uint *)(param_1 + 0x1750);
    param_3 = param_1;
    SdbusDebugPrint(0x4000,
                    "PL180_SDHC[%p] Pl180GetPendingEvents(HW mask changed for CMD%d, new=%8.8x)\r\n"
                    ,param_1,param_4);
  }
  uVar2 = -(uint)((uVar1 & 0xc0) != 0) & 4;
  uVar3 = uVar2 | 0x1000;
  if ((uVar1 & 0x23f) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 0x40;
  if ((uVar1 >> 8 & 1) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 0x20;
  if ((uVar1 & 0x28000) == 0) {
    uVar3 = uVar2;
  }
  pcVar4 = (char *)(ulonglong)uVar3;
  uVar2 = uVar3 | 0x10;
  if ((uVar1 & 0x44000) == 0) {
    uVar2 = uVar3;
  }
  if (((*(char *)(param_1 + 0x24) != '\0') && (*(int *)(param_1 + 0x178c) == 4)) &&
     (((*(uint *)(param_1 + 0x578) & 0x40) != 0 && ((*(uint *)(param_1 + 0x3f0) & 0x40) == 0)))) {
    pcVar4 = "PL180_SDHC[%p] DMA not supported)\r\n";
    param_3 = param_1;
    SdbusDebugPrint(0x4000,"PL180_SDHC[%p] DMA not supported)\r\n",param_1,param_4);
  }
  if ((uVar2 >> 0xc != 0) && (*(int *)(param_1 + 0x1750) - 0x10U < 10)) {
    Pl180DebugDumpRegs(param_1,pcVar4,param_3,param_4);
  }
  uVar6 = (ulonglong)uVar1;
  pcVar4 = "PL180_SDHC[%p] Pl180GetPendingEvents(hw=%8.8x -> sw=%8.8x)\r\n";
  lVar5 = param_1;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180GetPendingEvents(hw=%8.8x -> sw=%8.8x)\r\n",param_1,
                  uVar6);
  if (*(char *)(param_1 + 0x24) == '\x01') {
    SdbusWait(500,pcVar4,lVar5,uVar6);
  }
  return uVar2;
}



===== Pl180GetResponse @ 140012e90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 Pl180GetResponse(longlong param_1,byte *param_2,uint param_3,void *param_4)

{
  undefined4 *_Src;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  uint local_50;
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = *(undefined4 *)(param_2 + 0x10);
  local_50 = param_3;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180GetResponse CMD%2d (type 0x%x, len=%d)\r\n",param_1,
                  (ulonglong)*param_2);
  if (*(int *)(param_2 + 0x10) == 4) {
    local_48 = (undefined1  [4])SdbusReadRegisterUlong(param_1,0x20);
    local_44 = SdbusReadRegisterUlong(param_1,0x1c);
    local_40 = SdbusReadRegisterUlong(param_1,0x18);
    local_3c = SdbusReadRegisterUlong(param_1,0x14);
    _Src = (undefined4 *)((longlong)local_48 + 1);
    param_3 = param_3 - 1;
  }
  else {
    local_48 = (undefined1  [4])SdbusReadRegisterUlong(param_1,0x14);
    _Src = (undefined4 *)local_48;
  }
  memcpy(param_4,_Src,(ulonglong)param_3);
  return 0;
}



===== Pl180InitializeCard @ 140012f70 =====

void Pl180InitializeCard(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180InitializeCard)",param_1,param_4);
  return;
}



===== Pl180InitializeFunction @ 140012fa0 =====

void Pl180InitializeFunction
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180InitializeFunction",param_1,param_4);
  return;
}



===== Pl180InitializeSocket @ 140012fd0 =====

void Pl180InitializeSocket
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  bool bVar4;
  
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180InitializeSocket",param_1,param_4);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x808;
  uVar3 = 0;
  *(undefined1 *)(param_1 + 0x1154) = 0;
  *(undefined2 *)(param_1 + 0x1127) = 0;
  *(undefined4 *)(param_1 + 0x1150) = 0;
  *(undefined2 *)(param_1 + 0x1148) = 1;
  *(undefined2 *)(param_1 + 0x1124) = 1;
  *(undefined2 *)(param_1 + 0x1146) = *(undefined2 *)(param_1 + 0x1744);
  *(undefined4 *)(param_1 + 0x1140) = 0x80000;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p - Pl180SetHighSpeed(set=%d)",param_1,0);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x800000;
  SdbusWriteRegisterUlong(param_1,0x3c,0);
  SdbusWriteRegisterUlong(param_1,0x40,0);
  uVar2 = 0x7ff;
  SdbusWriteRegisterUlong(param_1,0x38,0x7ff);
  uVar1 = SdbusReadRegisterUlong(param_1,0xfec);
  bVar4 = (char)uVar1 != '\x01';
  uVar1 = 0x80;
  if (bVar4) {
    uVar1 = 0x10;
  }
  *(undefined4 *)(param_1 + 0x1768) = uVar1;
  uVar1 = 0x40;
  if (bVar4) {
    uVar1 = 8;
  }
  *(undefined4 *)(param_1 + 0x176c) = uVar1;
  Pl180DebugDumpRegs(param_1,0x10,uVar2,uVar3);
  return;
}



===== Pl180InitializeTransfer @ 1400130d0 =====

undefined8
Pl180InitializeTransfer
          (longlong param_1,ushort param_2,ushort param_3,int param_4,int param_5,undefined8 param_6
          ,undefined8 param_7,undefined1 param_8)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  
  if (param_5 == 1) {
    pcVar7 = "Read";
  }
  else {
    pcVar7 = "Write";
    if (param_5 != 2) {
      pcVar7 = "Unspecified";
    }
  }
  uVar4 = (uint)param_2;
  SdbusDebugPrint(0x4000,
                  "PL180_SDHC[%p] Pl180InitializeTransfer: DIR=%s METHOD=%d, BLOCKS=%d x %d\r\n",
                  param_1,pcVar7);
  uVar2 = 0x2c;
  uVar1 = SdbusReadRegisterUlong(param_1,0x2c);
  if (param_5 == 0) {
    uVar6 = (ulonglong)(uVar1 & 0xfffffff6);
    SdbusWriteRegisterUlong(param_1,(ushort)uVar2,uVar1 & 0xfffffff6);
    SdbusWait((int)uVar2 - 0x22,uVar2,uVar6,pcVar7);
LAB_14001317a:
    uVar2 = 0;
  }
  else {
    if ((((param_3 != 0) || (param_2 != 0)) && ((ushort)(param_2 - 1) < 0x800)) &&
       ((uVar4 & param_2 - 1) == 0)) {
      if (param_3 == 0) {
        uVar8 = 0;
        uVar5 = (uint)param_2;
      }
      else {
        uVar8 = param_3 * uVar4;
        uVar5 = uVar8;
      }
      if ((uVar5 & 3) == 0) {
        if (uVar5 < 0x10000) {
          uVar3 = uVar1 & 0xfffffffb;
          if (param_5 == 1) {
            uVar3 = uVar3 | 2;
LAB_14001320f:
            SdbusWriteRegisterUlong(param_1,0x24,0xffffffff);
          }
          else if (param_5 == 2) {
            uVar3 = uVar1 & 0xfffffff9;
            goto LAB_14001320f;
          }
          iVar9 = 0x1f;
          if (uVar4 != 0) {
            for (; param_2 >> iVar9 == 0; iVar9 = iVar9 + -1) {
            }
          }
          uVar3 = uVar3 & 0xffffff0f | iVar9 << 4;
          SdbusWriteRegisterUlong(param_1,0x28,uVar5);
          uVar2 = 0x2c;
          uVar1 = uVar3 | 1;
          if (param_5 != 1) {
            uVar1 = uVar3;
          }
          uVar6 = (ulonglong)uVar1;
          SdbusWriteRegisterUlong(param_1,0x2c,uVar1);
          SdbusWait((int)uVar2 - 0x22,uVar2,uVar6,pcVar7);
          *(ushort *)(param_1 + 0x1788) = param_2;
          iVar9 = 1;
          if (param_4 != 4) {
            iVar9 = param_4;
          }
          *(undefined1 *)(param_1 + 0x1794) = param_8;
          if (param_3 != 0) {
            uVar4 = uVar8;
          }
          *(uint *)(param_1 + 0x1784) = uVar4;
          *(undefined4 *)(param_1 + 0x174c) = 0;
          *(int *)(param_1 + 0x1790) = param_5;
          *(int *)(param_1 + 0x178c) = iVar9;
          *(ushort *)(param_1 + 0x178a) = param_3;
          *(undefined8 *)(param_1 + 0x1774) = param_6;
          goto LAB_14001317a;
        }
      }
      else {
        SdbusDebugPrint(0x4000,
                        "PL180_SDHC[%p] Pl180InitializeTransfer: transfer size must be multiple of 4\r\n"
                        ,param_1,pcVar7);
      }
    }
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== Pl180IsWriteProtected @ 1400132e0 =====

longlong Pl180IsWriteProtected
                   (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint7 uVar2;
  longlong lVar1;
  
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180IsWriteProtected",param_1,param_4);
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 8) >> 8);
  if (*(longlong *)(*(longlong *)(param_1 + 8) + 0x388) == 0) {
    lVar1 = (ulonglong)uVar2 << 8;
  }
  else {
    lVar1 = CONCAT71(uVar2,*(undefined1 *)(param_1 + 0x1179));
  }
  return lVar1;
}



===== Pl180PrepareTransfer @ 140013330 =====

undefined8 Pl180PrepareTransfer(undefined4 *param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint local_res10 [6];
  
  uVar5 = (ulonglong)*(uint *)(param_2 + 0x174c);
  local_res10[0] = 0;
  lVar4 = param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180PrepareTransfer phase %d\r\n",param_2,uVar5);
  iVar2 = *(int *)(param_2 + 0x174c);
  if (iVar2 == 0) {
    if (*(char *)(param_2 + 0x24) == '\0') {
      *(undefined8 *)(param_2 + 0x300) = 0;
    }
    if (*(int *)(param_2 + 0x178c) == 4) {
      SdbusDebugPrint(0x4000,"DMA not supported",lVar4,uVar5);
    }
    *(undefined4 *)(param_2 + 0x178c) = 1;
    if ((*(int *)(param_2 + 0x1750) != 0x37) && (*(int *)(param_2 + 0x1750) != 0xd)) {
LAB_1400133bb:
      *(undefined4 *)(param_2 + 0x174c) = 1;
      iVar2 = KeQueryTimeIncrement();
      param_1[1] = (uint)(iVar2 * 2) / 10;
      return 0xc0000016;
    }
  }
  else {
    if (iVar2 == 1) {
      uVar3 = Pl180SendCommand(param_2,&CmdDescSendStatus,*(undefined4 *)(param_2 + 0x168c));
      uVar1 = SdCommandTimeout;
      if (-1 < (int)uVar3) {
        param_1[1] = 100000000;
        uVar3 = 0xc0000016;
        param_1[2] = uVar1 / 100;
        *param_1 = 4;
        *(undefined4 *)(param_2 + 0x174c) = 2;
      }
LAB_140013436:
      if ((int)uVar3 == -0x3fffffea) {
        return uVar3;
      }
      goto LAB_140013487;
    }
    if (iVar2 == 2) {
      uVar3 = Pl180GetResponse(param_2,&CmdDescSendStatus,4,local_res10);
      if ((int)uVar3 < 0) goto LAB_140013436;
      if ((local_res10[0] & 0x100) == 0) goto LAB_1400133bb;
    }
    else if (iVar2 != 3) {
      uVar3 = 0xc0000001;
      goto LAB_140013487;
    }
  }
  uVar3 = 0;
LAB_140013487:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return uVar3;
}



===== Pl180QueryTransferMode @ 1400134a0 =====

undefined4 Pl180QueryTransferMode(longlong param_1)

{
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180QueryTransferMode = %d",param_1,
                  (ulonglong)*(uint *)(param_1 + 0x2d0));
  return *(undefined4 *)(param_1 + 0x2d0);
}



===== Pl180ReadDataPortInternal @ 1400134d8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Pl180ReadDataPortInternal(longlong param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  uint *puVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  
  lVar6 = param_1;
  puVar9 = param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] PlReadDataPort (buff=%p, len=%d)\r\n",param_1,param_2);
  if ((param_3 & 3) == 0) {
    iVar2 = KeQueryTimeIncrement();
    lVar6 = _DAT_fffff78000000320;
    while (*(uint *)(param_1 + 0x1798) < *(uint *)(param_1 + 0x179c)) {
      do {
        uVar3 = SdbusReadRegisterUlong(param_1,0x34);
        puVar7 = (uint *)(param_1 + 0x176c);
        if (((longlong)(100000000 / (ulonglong)(uint)(iVar2 * 100)) < _DAT_fffff78000000320 - lVar6)
           && (*(int *)(param_1 + 0x1798) + *puVar7 < *(uint *)(param_1 + 0x179c))) {
          return 0xc0000016;
        }
      } while ((uVar3 & 0x20802a) == 0);
      if ((uVar3 & 0x2a) != 0) {
        SdbusDebugPrint(1,"Pl180ReadDataPort - ERROR! Stop Reading Data Error! Status(0x%x)\r\n",
                        (ulonglong)uVar3,puVar9);
        *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
        uVar3 = Pl180GetErrorStates(param_1);
        *(uint *)(param_1 + 0x3f4) = *(uint *)(param_1 + 0x3f4) | uVar3;
        return 0xc0000001;
      }
      if ((uVar3 >> 0xf & 1) == 0) {
        if ((uVar3 & 0x200100) == 0x200100) {
          uVar1 = *(uint *)(param_1 + 0x1798);
          puVar9 = (undefined4 *)(ulonglong)uVar1;
          uVar3 = *(uint *)(param_1 + 0x1768);
          if (*(uint *)(param_1 + 0x179c) < *(uint *)(param_1 + 0x1768) + uVar1) {
            uVar3 = 1;
            if (*puVar7 + uVar1 <= *(uint *)(param_1 + 0x179c)) {
              uVar3 = *puVar7;
            }
          }
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        if ((uVar3 >> 0x11 & 1) != 0) {
          puVar7 = (uint *)(param_1 + 0x1768);
        }
        uVar3 = *puVar7;
      }
      if ((*(longlong *)(param_1 + 0x228) != 0) && (uVar3 != 0)) {
        uVar8 = (ulonglong)uVar3;
        puVar5 = param_2;
        do {
          *puVar5 = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x80);
          puVar5 = puVar5 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      *(int *)(param_1 + 0x1798) = *(int *)(param_1 + 0x1798) + uVar3;
      param_2 = param_2 + uVar3;
    }
    uVar4 = 0;
  }
  else {
    SdbusDebugPrint(1,"ERROR: length must be a multiple of 4 bytes\r\n",lVar6,puVar9);
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== Pl180ResetHost @ 1400136b0 =====

undefined8 Pl180ResetHost(undefined8 param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  ushort uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180ResetHost",param_2,param_4);
  if (*(longlong *)(param_2 + 0x175c) == 0) {
    *(undefined4 *)(param_2 + 0x1764) = 1;
  }
  if (param_3 < 2) {
    uVar2 = 0xc;
    uVar1 = SdbusReadRegisterUlong(param_2,0xc);
    SdbusWriteRegisterUlong(param_2,uVar2,uVar1 & 0xfffffbff);
    uVar5 = 0;
    uVar3 = 8;
    SdbusWriteRegisterUlong(param_2,8,0);
    SdbusWait((int)uVar3 + 2,uVar3,uVar5,param_4);
  }
  if ((param_3 & 0xfffffffd) == 0) {
    SdbusWriteRegisterUlong(param_2,0x2c,0);
    SdbusWriteRegisterUlong(param_2,0x28,0);
    uVar5 = 0;
    uVar3 = 0x24;
    SdbusWriteRegisterUlong(param_2,0x24,0);
    SdbusWait((int)uVar3 - 0x1a,uVar3,uVar5,param_4);
  }
  SdbusWriteRegisterUlong(param_2,0x3c,0);
  SdbusWriteRegisterUlong(param_2,0x40,0);
  SdbusWriteRegisterUlong(param_2,0x38,0x7ff);
  uVar3 = 4;
  uVar1 = SdbusReadRegisterUlong(param_2,4);
  uVar4 = (ulonglong)(uVar1 | 0x300);
  SdbusWriteRegisterUlong(param_2,(ushort)uVar3,uVar1 | 0x300);
  SdbusWait((int)uVar3 + 6,uVar3,uVar4,param_4);
  uVar3 = 0;
  uVar5 = 0xbf;
  SdbusWriteRegisterUlong(param_2,0,0xbf);
  SdbusWait(10000,uVar3,uVar5,param_4);
  return 0;
}



===== Pl180SendCommand @ 1400137f0 =====

undefined8 Pl180SendCommand(longlong param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)*param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180SendCommand CMD%2d (Argument 0x%x)\r\n",param_1,uVar5)
  ;
  uVar2 = Pl180ClearStatusFlags(param_1);
  if (-1 < (int)uVar2) {
    bVar1 = *param_2;
    if (bVar1 == 0x29) {
      SdbusDebugPrint(0x4000,
                      "PL180_SDHC[%p] Pl180SendCommand CMD%2d (Argument 0x%x) to start SD CARD not supported\r\n"
                      ,param_1,0x29);
      uVar2 = 0xc00000b5;
    }
    else {
      uVar3 = 0x440;
      if (*(int *)(param_2 + 0x10) == 1) {
        uVar3 = 0x400;
      }
      uVar3 = uVar3 | bVar1 & 0x3f;
      if (*(int *)(param_2 + 0x10) == 4) {
        uVar3 = uVar3 | 0x80;
      }
      *(uint *)(param_1 + 0x1750) = (uint)bVar1;
      *(undefined4 *)(param_1 + 0x1754) = param_3;
      SdbusWriteRegisterUlong(param_1,8,param_3);
      uVar4 = (ulonglong)uVar3;
      uVar2 = 0xc;
      SdbusWriteRegisterUlong(param_1,0xc,uVar3);
      SdbusWait((int)uVar2 - 2,uVar2,uVar4,uVar5);
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== Pl180SetBusWidth @ 1400138d0 =====

void Pl180SetBusWidth(longlong param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180SetBusWidth(wide=%d)",param_1,uVar5);
  uVar3 = 4;
  uVar2 = SdbusReadRegisterUlong(param_1,4);
  uVar1 = uVar2 & 0xfffff7ff | 0x800;
  if (param_2 == 0) {
    uVar1 = uVar2 & 0xfffff7ff;
  }
  uVar4 = (ulonglong)uVar1;
  SdbusWriteRegisterUlong(param_1,(ushort)uVar3,uVar1);
  SdbusWait(10000,uVar3,uVar4,uVar5);
  return;
}



===== Pl180SetBusWidthExplicit @ 140013940 =====

void Pl180SetBusWidthExplicit(longlong param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)param_2;
  SdbusDebugPrint(0x4000,"QC_SDHC[%p] - Pl180SetBusWidthExplicit(width=%d)",param_1,uVar4);
  uVar2 = 4;
  uVar1 = SdbusReadRegisterUlong(param_1,4);
  uVar1 = uVar1 & 0xfffff7ff;
  if ((param_2 != 1) && (param_2 == 4)) {
    uVar1 = uVar1 | 0x800;
  }
  uVar3 = (ulonglong)uVar1;
  SdbusWriteRegisterUlong(param_1,(ushort)uVar2,uVar1);
  SdbusWait(10000,uVar2,uVar3,uVar4);
  return;
}



===== Pl180SetClock @ 1400139b0 =====

undefined8 Pl180SetClock(undefined8 param_1,longlong param_2,byte param_3,uint param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_3;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180SetClock(enable=%d, Freq=%d khz)\r\n",param_2,uVar5);
  if (param_4 < 1000) {
    uVar3 = 0;
  }
  else if (*(int *)(param_2 + 0x1740) == -1) {
    uVar3 = 1;
    if (9999 < param_4) {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 4;
  }
  uVar4 = (ulonglong)uVar3;
  if (param_3 == 1) {
    *(undefined4 *)(param_2 + 0x167c) = (&DAT_140025528)[uVar4 * 3];
  }
  uVar1 = SdbusReadRegisterUlong(param_2,4);
  if (uVar3 == 4) {
    uVar3 = uVar1 & 0xfffffa00 | *(uint *)(param_2 + 0x1740);
  }
  else {
    uVar1 = uVar1 & 0xfffffa00 | (&DAT_140025530)[uVar4 * 3];
    uVar3 = uVar1 | 0x400;
    if ((&DAT_14002552c)[uVar4 * 0xc] == '\0') {
      uVar3 = uVar1;
    }
  }
  uVar1 = uVar3 | 0x100;
  if (param_3 == 0) {
    uVar1 = uVar3;
  }
  uVar4 = (ulonglong)uVar1;
  uVar2 = 4;
  SdbusWriteRegisterUlong(param_2,4,uVar1);
  SdbusWait(10000,uVar2,uVar4,uVar5);
  return 0;
}



===== Pl180SetEventMask @ 140013ad0 =====

void Pl180SetEventMask(longlong param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180SetEventMask(new=%8.8x, changed=%8.8x)\r\n",param_1,
                  uVar4);
  uVar1 = Pl180EventMaskToHardwareMask(param_3);
  if (uVar1 != 0) {
    if (*(char *)(param_1 + 0x24) == '\x01') {
      SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180SetEventMask: ignored in crash dump mode\r\n",
                      param_1,uVar4);
    }
    else {
      uVar2 = SdbusReadRegisterUlong(param_1,0x3c);
      uVar3 = Pl180EventMaskToHardwareMask(param_2);
      uVar1 = (uVar2 & ~uVar1 | uVar3 & uVar1) & 0x3fffff;
      SdbusDebugPrint(0x4000,"PL180_SDHC Pl180SetEventMask(hwmask=%8.8x)\r\n",(ulonglong)uVar1,uVar4
                     );
      SdbusWriteRegisterUlong(param_1,0x3c,uVar1);
    }
  }
  return;
}



===== Pl180SetHighSpeed @ 140013ba0 =====

void Pl180SetHighSpeed(undefined8 param_1,byte param_2)

{
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p - Pl180SetHighSpeed(set=%d)",param_1,(ulonglong)param_2);
  return;
}



===== Pl180SetPower @ 140013bd0 =====

undefined8 Pl180SetPower(undefined8 param_1,longlong param_2,uint param_3)

{
  *(undefined4 *)(param_2 + 0x1690) = 0x80000;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] - Pl180SetPower voltage profile=0%x",param_2,
                  (ulonglong)param_3);
  return 0;
}



===== Pl180SetSignaling @ 140013c10 =====

uint Pl180SetSignaling(undefined8 param_1,undefined8 param_2,char param_3)

{
  return -(uint)(param_3 != '\0') & 0xc000000d;
}



===== Pl180SetUhsMode @ 140013c30 =====

undefined8 Pl180SetUhsMode(void)

{
  return 0xc000000d;
}



===== Pl180StartSocket @ 140013c40 =====

undefined8 Pl180StartSocket(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = *(uint *)(param_2 + 0x10);
  pcVar4 = (char *)(param_2 + 0x14);
  uVar5 = 0;
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if ((*pcVar4 == '\x03') &&
         (bVar6 = uVar3 == *(ushort *)(param_1 + 0x4c), uVar3 = uVar3 + 1, bVar6)) break;
      uVar5 = uVar5 + 1;
      pcVar4 = pcVar4 + 0x14;
    } while (uVar5 < uVar1);
    if (uVar5 < uVar1) {
      *(undefined8 *)(param_1 + 0x1f8) = *(undefined8 *)(pcVar4 + 4);
      *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(pcVar4 + 0xc);
      uVar2 = MmMapIoSpaceEx(*(undefined8 *)(pcVar4 + 4),*(undefined4 *)(pcVar4 + 0xc),0x204);
      *(undefined8 *)(param_1 + 0x218) = uVar2;
      *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(pcVar4 + 0xc);
      *(undefined8 *)(param_1 + 0x228) = uVar2;
      uVar1 = *(uint *)(pcVar4 + 0xc);
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x800000;
      *(uint *)(param_1 + 0x238) = uVar1;
      *(undefined8 *)(param_1 + 0x230) = uVar2;
      *(undefined1 *)(param_1 + 0x310) = 0;
      SdbusDebugPrint(4,"Pl180StartDevice: Host Register Base at %p, size %x",uVar2,(ulonglong)uVar1
                     );
      SdbusWriteRegisterUlong(param_1,0x3c,0);
      SdbusWriteRegisterUlong(param_1,0x40,0);
      SdbusWriteRegisterUlong(param_1,0x38,0x7ff);
      return 0;
    }
  }
  return 0xc0000001;
}



===== Pl180StartTransfer @ 140013d50 =====

ulonglong Pl180StartTransfer(uint *param_1,longlong param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ushort uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  byte *pbVar10;
  uint local_res10 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x174c);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_res10[0] = 0;
  uVar8 = 0xc0000001;
  lVar9 = param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180StartTransfer phase %d\r\n",param_2,uVar4);
  KeAcquireInStackQueuedSpinLockAtDpcLevel(param_2 + 0x3a8,&local_38);
  *(uint *)(param_2 + 0x3f0) = *(uint *)(param_2 + 0x3f0) & 0xffffffcf;
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_38);
  uVar3 = SdCommandTimeout;
  iVar2 = *(int *)(param_2 + 0x174c);
  if (iVar2 == 0) {
    if (*(int *)(param_2 + 0x178c) == 1) {
      if (*(int *)(param_2 + 0x1790) == 2) {
        uVar5 = 0x2c;
        uVar3 = SdbusReadRegisterUlong(param_2,0x2c);
        uVar8 = (ulonglong)(uVar3 | 1);
        SdbusWriteRegisterUlong(param_2,(ushort)uVar5,uVar3 | 1);
        SdbusWait((int)uVar5 - 0x22,uVar5,uVar8,uVar4);
      }
      *(uint *)(param_2 + 0x179c) = *(uint *)(param_2 + 0x1784) >> 2;
      *(undefined4 *)(param_2 + 0x1798) = 0;
      *param_1 = 0;
LAB_140013fd3:
      *(undefined4 *)(param_2 + 0x174c) = 1;
      return 0xc0000016;
    }
    if (*(int *)(param_2 + 0x178c) == 4) {
      SdbusDebugPrint(0x4000,"DMA not supported",lVar9,uVar4);
    }
    goto LAB_140014115;
  }
  if (iVar2 == 1) {
    iVar2 = 0;
    if (*(int *)(param_2 + 0x1120) != 1) {
      uVar6 = 0x3c;
      iVar2 = SdbusReadRegisterUlong(param_2,0x3c);
      SdbusWriteRegisterUlong(param_2,uVar6,0);
    }
    puVar1 = (undefined4 *)
             (*(longlong *)(param_2 + 0x1774) + (ulonglong)*(uint *)(param_2 + 0x1798) * 4);
    if (*(int *)(param_2 + 0x1790) == 2) {
      uVar5 = Pl180WriteDataPortInternal(param_2,puVar1,*(uint *)(param_2 + 0x1784));
      uVar3 = (uint)uVar5;
    }
    else {
      uVar5 = Pl180ReadDataPortInternal(param_2,puVar1,*(uint *)(param_2 + 0x1784));
      uVar3 = (uint)uVar5;
    }
    uVar8 = (ulonglong)uVar3;
    if (iVar2 != 0) {
      SdbusWriteRegisterUlong(param_2,0x3c,iVar2);
    }
    if (uVar3 == 0xc0000016) {
      *param_1 = 0;
      iVar2 = KeQueryTimeIncrement();
      param_1[1] = (uint)(iVar2 * 2) / 10;
      *(undefined4 *)(param_2 + 0x174c) = 2;
      return 0xc0000016;
    }
    if ((int)uVar3 < 0) goto LAB_140014115;
    *param_1 = 0;
    *(undefined4 *)(param_2 + 0x174c) = 3;
LAB_14001409d:
    uVar8 = 0xc0000016;
  }
  else {
    if (iVar2 == 2) {
      uVar3 = 0x10;
      if (*(int *)(param_2 + 0x1790) != 2) {
        uVar3 = 0x20;
      }
      *param_1 = uVar3;
      Pl180SetEventMask(param_2,uVar3,uVar3);
      param_1[1] = 2000000;
      param_1[2] = SdCommandTimeout / 100;
      goto LAB_140013fd3;
    }
    if (iVar2 == 3) {
      param_1[1] = 2000000;
      param_1[2] = uVar3 / 100;
      *param_1 = 0x40;
      *(undefined4 *)(param_2 + 0x174c) = 4;
      return 0xc0000016;
    }
    if (iVar2 != 4) {
      if (iVar2 != 5) goto LAB_140014115;
      if (*(int *)(param_2 + 0x1750) == 0xd) {
        uVar4 = Pl180GetResponse(param_2,&CmdDescSendStatus,4,local_res10);
        uVar8 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) goto LAB_1400140a2;
        if ((local_res10[0] & 0x100) == 0) {
          *(undefined4 *)(param_2 + 0x174c) = 4;
          iVar2 = KeQueryTimeIncrement();
          param_1[1] = (uint)(iVar2 * 2) / 10;
          return 0xc0000016;
        }
      }
      uVar8 = 0;
      goto LAB_140014115;
    }
    uVar7 = 0;
    if ((*(int *)(param_2 + 0x1790) == 1) &&
       (*(uint *)(param_2 + 0x1798) < *(uint *)(param_2 + 0x179c))) {
      Pl180ReadDataPortInternal
                (param_2,(undefined4 *)
                         (*(longlong *)(param_2 + 0x1774) +
                         (ulonglong)*(uint *)(param_2 + 0x1798) * 4),*(uint *)(param_2 + 0x1784));
    }
    uVar3 = *(uint *)(param_2 + 0x1750);
    if ((uVar3 < 0x33) && ((0x4000001003000U >> ((ulonglong)uVar3 & 0x3f) & 1) != 0)) {
      uVar7 = *(undefined4 *)(param_2 + 0x168c);
      pbVar10 = &CmdDescSendStatus;
LAB_140013f0f:
      uVar4 = Pl180SendCommand(param_2,pbVar10,uVar7);
      uVar3 = SdCommandTimeout;
      uVar8 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        param_1[1] = 100000000;
        param_1[2] = uVar3 / 100;
        *param_1 = 4;
        if ((*pbVar10 == 0x34) || (*pbVar10 == 0xd)) {
          *(undefined4 *)(param_2 + 0x174c) = 5;
        }
        goto LAB_14001409d;
      }
    }
    else {
      if (uVar3 != 0x35) {
        if (*(char *)(param_2 + 0x1794) == '\0') goto LAB_140013ef7;
        pbVar10 = &CmdDescStopTransmission;
        goto LAB_140013f0f;
      }
      pbVar10 = &CmdDescReadIoDirect;
      if (*(int *)(param_2 + 0x1790) != 2) {
        pbVar10 = (byte *)0x0;
      }
      if (pbVar10 != (byte *)0x0) goto LAB_140013f0f;
LAB_140013ef7:
      uVar8 = 0;
    }
  }
LAB_1400140a2:
  if ((int)uVar8 == -0x3fffffea) {
    return uVar8;
  }
LAB_140014115:
  *(undefined4 *)(param_2 + 0x174c) = 0;
  return uVar8;
}



===== Pl180WriteDataPortInternal @ 140014140 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 Pl180WriteDataPortInternal(longlong param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  
  lVar4 = param_1;
  puVar6 = param_2;
  SdbusDebugPrint(0x4000,"PL180_SDHC[%p] Pl180WriteDataPort (buff=%p, len=%d)\r\n",param_1,param_2);
  if ((param_3 & 3) == 0) {
    iVar1 = KeQueryTimeIncrement();
    lVar4 = _DAT_fffff78000000320;
    while (*(uint *)(param_1 + 0x1798) < *(uint *)(param_1 + 0x179c)) {
      uVar2 = SdbusReadRegisterUlong(param_1,0x34);
      if ((uVar2 & 0x1a) != 0) goto LAB_14001425e;
      if ((longlong)(100000000 / (ulonglong)(uint)(iVar1 * 100)) < _DAT_fffff78000000320 - lVar4) {
        return 0xc0000016;
      }
      uVar2 = 0x80;
      if (*(uint *)(param_1 + 0x179c) < *(int *)(param_1 + 0x1798) + 0x80U) {
        uVar2 = *(uint *)(param_1 + 0x179c) - *(int *)(param_1 + 0x1798);
      }
      if ((*(longlong *)(param_1 + 0x228) != 0) && (uVar2 != 0)) {
        uVar7 = (ulonglong)uVar2;
        puVar5 = param_2;
        do {
          *(undefined4 *)(*(longlong *)(param_1 + 0x228) + 0x80) = *puVar5;
          LOCK();
          UNLOCK();
          puVar5 = puVar5 + 1;
          uVar7 = uVar7 - 1;
          puVar6 = (undefined4 *)0x0;
        } while (uVar7 != 0);
      }
      *(int *)(param_1 + 0x1798) = *(int *)(param_1 + 0x1798) + uVar2;
      param_2 = param_2 + uVar2;
    }
    uVar2 = SdbusReadRegisterUlong(param_1,0x34);
    if ((uVar2 & 0x1a) == 0) {
      uVar2 = SdbusReadRegisterUlong(param_1,0x48);
      if (uVar2 == 0) {
        return 0;
      }
      *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
      *(undefined4 *)(param_1 + 0x3f4) = 0x11;
      SdbusDebugPrint(1,
                      "Pl180WriteDataPort - ERROR! We did overrun the FIFO! FifoCount left(0x%x)\r\n"
                      ,(ulonglong)uVar2,puVar6);
    }
    else {
LAB_14001425e:
      SdbusDebugPrint(1,"Pl180WriteDataPort - ERROR! Stop Writing Data Error! Status(0x%x)\r\n",
                      (ulonglong)uVar2,puVar6);
      *(uint *)(param_1 + 0x3f0) = *(uint *)(param_1 + 0x3f0) | 0x1000;
      uVar2 = Pl180GetErrorStates(param_1);
      *(uint *)(param_1 + 0x3f4) = *(uint *)(param_1 + 0x3f4) | uVar2;
    }
    uVar3 = 0xc0000001;
  }
  else {
    SdbusDebugPrint(1,"ERROR: length must be a multiple of 4 bytes\r\n",lVar4,puVar6);
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== SdbusDisableEvents @ 1400142f8 =====

undefined8 SdbusDisableEvents(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_28 [2];
  uint local_18;
  undefined4 local_14;
  
  lVar1 = *(longlong *)(param_1 + 8);
  local_28[1] = 0;
  local_14 = 0;
  if ((*(uint *)(lVar1 + 0x38) & 0x40000) == 0) {
    local_28[0] = param_1;
    local_18 = param_2;
    if (*(char *)(param_1 + 0x24) == '\0') {
      KeSynchronizeExecution
                (*(undefined8 *)(lVar1 + 0x98),SdbusInterruptSynchronizeDisable,local_28);
      if (((param_2 & 1) != 0) && (*(longlong *)(lVar1 + 0xb0) != 0)) {
        KeSynchronizeExecution
                  (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0xb0),
                   SdbusInterruptSynchronizeDisable,local_28);
      }
    }
    else {
      SdbusInterruptSynchronizeDisable(local_28);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000184;
  }
  return uVar2;
}



===== SdbusEnableEvents @ 1400143b0 =====

undefined8 SdbusEnableEvents(longlong param_1,uint param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_28 [2];
  uint local_18;
  undefined4 local_14;
  
  lVar1 = *(longlong *)(param_1 + 8);
  local_28[1] = 0;
  local_14 = 0;
  if ((*(uint *)(lVar1 + 0x38) & 0x40000) == 0) {
    local_28[0] = param_1;
    local_18 = param_2;
    if (*(char *)(param_1 + 0x24) == '\0') {
      KeSynchronizeExecution(*(undefined8 *)(lVar1 + 0x98),SdbusInterruptSynchronizeEnable,local_28)
      ;
      if (((param_2 & 1) != 0) && (*(longlong *)(lVar1 + 0xb0) != 0)) {
        KeSynchronizeExecution
                  (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0xb0),
                   SdbusInterruptSynchronizeEnable,local_28);
      }
    }
    else {
      SdbusInterruptSynchronizeEnable(local_28);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000184;
  }
  return uVar2;
}



===== SdbusInterruptSynchronizeDisable @ 140014470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusInterruptSynchronizeDisable(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *param_1;
  *(uint *)(lVar1 + 0x3a0) = *(uint *)(lVar1 + 0x3a0) & ~*(uint *)(param_1 + 2);
  uVar2 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0xe8))
                    (lVar1,*(undefined4 *)(lVar1 + 0x3a0),(int)param_1[2]);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== SdbusInterruptSynchronizeEnable @ 1400144c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusInterruptSynchronizeEnable(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *param_1;
  *(uint *)(lVar1 + 0x3a0) = *(uint *)(lVar1 + 0x3a0) | *(uint *)(param_1 + 2);
  uVar2 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0xe8))
                    (lVar1,*(undefined4 *)(lVar1 + 0x3a0),(int)param_1[2]);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== SdbusQueryCardInterruptsWorker @ 140014510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusQueryCardInterruptsWorker(longlong param_1,longlong *param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar2 = *param_2;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    if ((*(int *)(*(longlong *)(lVar2 + 8) + 0x104) == 1) &&
       ((*(uint *)(lVar2 + 0x20) & 0x200000) != 0)) {
      if (*(char *)(lVar2 + 0x117a) != '\0') {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar2,(undefined8 *)&CmdDescReadIoDirect,0xa00,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        return 0xc0000016;
      }
    }
    else {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar2 + 0x18,&local_38);
      if (*(int *)(lVar2 + 0x38) == 0) {
        KeSetEvent(lVar2 + 0x260,0,0);
      }
      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_38);
    }
  }
  else if (*(int *)(param_1 + 0x1b4) == 1) {
    bVar1 = *(byte *)(param_1 + 0x25c);
    uVar10 = (ulonglong)bVar1;
    SdbusDebugPrint(0x800,"QueryCardInterrupts: skt %p pending_ints=%x, reg_cb=%x, cb_in_service=%x"
                    ,lVar2,uVar10);
    uVar7 = (ulonglong)bVar1;
    uVar9 = 0;
    SdbusAddDbgLog(lVar2,0x51434920,uVar7,0,0);
    lVar8 = *(longlong *)(lVar2 + 0x10);
    do {
      if (lVar8 == 0) {
        if ((char)uVar10 != '\0') {
          return 0;
        }
        LOCK();
        *(int *)(lVar2 + 0x297c) = *(int *)(lVar2 + 0x297c) + 1;
        UNLOCK();
        KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar2 + 0x18,&local_38);
        if (*(int *)(lVar2 + 0x38) == 0) {
          KeSetEvent(lVar2 + 0x260,0,0);
          SdbusEnableEvents(lVar2,0x100);
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_38);
        return 0;
      }
      lVar3 = *(longlong *)(lVar8 + 0x40);
      if (((uint)uVar10 >> (*(byte *)(lVar3 + 0xc4) & 0x1f) & 1) != 0) {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar2 + 0x18,&local_38);
        if ((*(uint *)(lVar3 + 0x28) & 0x50000) == 0x50000) {
          if ((*(uint *)(lVar3 + 0x30) & 2) == 0) {
            LOCK();
            *(int *)(lVar2 + 0x2980) = *(int *)(lVar2 + 0x2980) + 1;
            UNLOCK();
            *(uint *)(lVar2 + 0x38) =
                 *(uint *)(lVar2 + 0x38) | 1 << (*(byte *)(lVar3 + 0xc4) & 0x1f);
            if ((*(uint *)(lVar3 + 0x28) & 0x20000) == 0) {
              uVar4 = *(uint *)(lVar3 + 0x30) | 1;
            }
            else {
              uVar4 = *(uint *)(lVar3 + 0x30) | 2;
            }
            puVar5 = &local_38;
            *(uint *)(lVar3 + 0x30) = uVar4;
            KeReleaseInStackQueuedSpinLockFromDpcLevel();
            if ((*(uint *)(lVar3 + 0x28) & 0x20000) == 0) {
              if ((Microsoft_Windows_SdbusEnableBits & 2) != 0) {
                uVar9 = *(ulonglong *)(lVar2 + 0x208);
                McTemplateK0i_EtwWriteTransfer(puVar5,&CallbackRoutineScheduled,uVar7,uVar9);
              }
              uVar7 = 0;
              KeSetEvent(lVar2 + 0x248,0);
            }
            else {
              uVar6 = 0x800;
              SdbusDebugPrint(0x800,"QueryCardInterrupts: CallBack: pdo=%p context=%p",lVar8,
                              *(undefined8 *)(lVar3 + 0xd8));
              if ((Microsoft_Windows_SdbusEnableBits & 2) != 0) {
                McTemplateK0i_EtwWriteTransfer
                          (uVar6,&CallbackRoutineEnter,lVar8,*(undefined8 *)(lVar2 + 0x208));
              }
              uVar9 = (ulonglong)*(uint *)(lVar2 + 0x30);
              uVar7 = (ulonglong)*(uint *)(lVar3 + 0x28);
              SdbusAddDbgLog(lVar2,0x49464943,uVar7,uVar9,0);
              LOCK();
              *(int *)(lVar2 + 0x298c) = *(int *)(lVar2 + 0x298c) + 1;
              UNLOCK();
              LOCK();
              *(int *)(lVar3 + 0x5f4) = *(int *)(lVar3 + 0x5f4) + 1;
              UNLOCK();
              (**(code **)(lVar3 + 0xd0))(*(undefined8 *)(lVar3 + 0xd8),0);
            }
            goto LAB_140014723;
          }
          LOCK();
          *(int *)(lVar2 + 0x2988) = *(int *)(lVar2 + 0x2988) + 1;
          UNLOCK();
          uVar7 = *(ulonglong *)(lVar3 + 8);
          SdbusDebugPrint(4,"QueryCardInterrupts: pdo %p int still in service",uVar7,uVar9);
        }
        else {
          LOCK();
          *(int *)(lVar2 + 0x2984) = *(int *)(lVar2 + 0x2984) + 1;
          UNLOCK();
          uVar10 = (ulonglong)((uint)uVar10 & ~(1 << (*(byte *)(lVar3 + 0xc4) & 0x1f)));
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_38);
      }
LAB_140014723:
      lVar8 = *(longlong *)(lVar3 + 0x18);
    } while( true );
  }
  return 0xc0000001;
}



===== SdbusArmWakeInterrupt @ 140014870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SdbusArmWakeInterrupt(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar1 = *param_2;
  if (*(int *)(param_1 + 0x1b4) == 0) {
    SdbusDebugPrint(0x40,"wp  %p SdbusArmWakeInterrupt Entered",param_2,param_4);
    if ((int)param_2[5] == 0x32) {
      lVar2 = *(longlong *)(*(longlong *)(lVar1 + 8) + 0x28);
      pcVar3 = *(code **)(lVar2 + 0x150);
      uVar4 = CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
    }
    else {
      if ((int)param_2[5] != 0x33) goto LAB_1400148d8;
      uVar4 = 0;
      pcVar3 = *(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x150);
    }
    uVar4 = (*pcVar3)(lVar1,uVar4);
  }
  else {
LAB_1400148d8:
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



===== SdbusBusClockWorker @ 1400148f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdbusBusClockWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  lVar1 = *param_2;
  if (*(int *)(param_1 + 0x1b4) != 0) {
    if (*(int *)(param_1 + 0x1b4) != 1) {
      return -0x3fffffff;
    }
    iVar2 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x50))
                      (param_1 + 0x1d0,lVar1,*(undefined1 *)((longlong)param_2 + 0x94),
                       (int)param_2[0x12],*(undefined4 *)(lVar1 + 0x1684));
    if (iVar2 < 0) {
      return iVar2;
    }
    if ((int)param_2[5] == 0x17) {
      *(int *)(lVar1 + 0x1678) = (int)param_2[0x12];
    }
    SdbusDebugPrint(0x40,"wp  %p bus clock set, freq=%d",param_2,
                    (ulonglong)*(uint *)(lVar1 + 0x167c));
    return iVar2;
  }
  SdbusDebugPrint(0x40,"wp  %p SetBusClock Entered",param_2,param_4);
  iVar2 = (int)param_2[5];
  if (iVar2 == 0x16) {
    param_2[0xb] = (ulonglong)*(uint *)(lVar1 + 0x167c);
    SdbusDebugPrint(0x40,"wp  %p returning current clock frequency at %dKHz",param_2,
                    (ulonglong)*(uint *)(lVar1 + 0x167c));
    return 0;
  }
  if (iVar2 == 0x18) {
    uVar3 = 400;
LAB_140014a26:
    *(int *)(param_2 + 0x12) = (int)uVar3;
  }
  else {
    if ((iVar2 == 0x19) || (iVar2 == 0x1a)) {
      if ((*(char *)(*(longlong *)(param_1 + 0x10) + 0x1699) == '\0') ||
         (*(char *)(*(longlong *)(param_1 + 0x10) + 0x113a) == '\0')) {
        *(undefined1 *)(param_1 + 0x28c) = 1;
      }
      uVar3 = (ulonglong)*(uint *)(lVar1 + 0x1678);
      goto LAB_140014a26;
    }
    if (iVar2 == 0x1b) {
      *(undefined4 *)(param_2 + 0x12) = 0;
      uVar3 = 0;
LAB_140014a3e:
      *(undefined1 *)((longlong)param_2 + 0x94) = 0;
      goto LAB_140014a46;
    }
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x12);
    if (*(uint *)(param_2 + 0x12) == 0) goto LAB_140014a3e;
  }
  *(undefined1 *)((longlong)param_2 + 0x94) = 1;
LAB_140014a46:
  SdbusDebugPrint(0x40,"wp  %p Will set clock frequency at %dKHz enable %d",param_2,uVar3);
  *(undefined4 *)(lVar1 + 0x174c) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 1;
  return -0x3fffffea;
}



===== SdbusBusInterfaceControlWorker @ 140014ab0 =====

undefined8 SdbusBusInterfaceControlWorker(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    if (*(int *)(param_2[1] + 200) - 2U < 2) {
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0xe00,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        return 0;
      }
      return 0xc0000001;
    }
    if (*(int *)(param_2 + 5) == 0x2d) {
      param_2[0xb] = (ulonglong)*(byte *)(param_1 + 0x25c) & 0xfffffffffffffffc;
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,*param_2,(undefined8 *)&CmdDescWriteIoDirect,
               *(byte *)(param_2 + 0xb) & 0xfc | *(byte *)(param_1 + 0x25c) & 3 | 0x80000e00,0,0,0,0
               ,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  return 0xc0000016;
}



===== SdbusBusWidthWorker @ 140014bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdbusBusWidthWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  longlong lVar6;
  int iVar7;
  
  uVar3 = *(uint *)(param_1 + 0x1b4);
  lVar1 = *param_2;
  if (uVar3 < 9) {
    if (uVar3 == 8) {
      bVar5 = *(byte *)(param_1 + 0x25c);
      SdbusDebugPrint(0x40,"wp  %p Current CCCR_BUS_CONTROL vale:%x",param_2,(ulonglong)bVar5);
      bVar5 = bVar5 & 0xfc;
      bVar2 = bVar5 | 2;
      if ((char)param_2[0x12] == '\0') {
        bVar2 = bVar5;
      }
      bVar5 = bVar2 & 0xf7;
      if ((*(uint *)(lVar1 + 0x48) & 0x400) != 0) {
        bVar5 = bVar2;
      }
      SdbusDebugPrint(0x40,"wp  %p Set wide bus for sdio function. bus width=%d, new BC=%x",param_2,
                      (ulonglong)((-(uint)((char)param_2[0x12] != '\0') & 3) + 1));
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar1,(undefined8 *)&CmdDescWriteIoDirect,bVar5 | 0x80000e00,0,0,0,0,0,0);
      if ((*(char *)(lVar1 + 0x11cb) == '\0') || (uVar4 = 9, *(char *)(lVar1 + 0x1139) == '\0')) {
        uVar4 = 10;
      }
      *(undefined4 *)(param_1 + 0x1b4) = uVar4;
    }
    else {
      if (uVar3 == 0) {
        lVar6 = lVar1;
        SdbusDebugPrint(0x40,"wp  %p skt %p BusWidthWorker entered",param_2,lVar1);
        iVar7 = (int)param_2[5];
        if (iVar7 != 0x1c) {
          if (*(int *)(lVar1 + 0x117c) == 3) {
            if (iVar7 == 0x1e) {
              if (*(char *)(lVar1 + 0x165f) == '\0') goto LAB_140015353;
            }
            else if ((char)param_2[0x12] != '\x01') {
              return -0x3ffffff3;
            }
          }
          if (*(char *)(lVar1 + 0x1178) != '\0') {
            SdbusDebugPrint(0x40,"wp  %p Error: cannot set bus width if card is locked",param_2,
                            lVar6);
            if ((int)param_2[5] == 0x1d) {
              return -0x3fffffff;
            }
            return 0;
          }
          if (iVar7 == 0x1e) {
            *(undefined1 *)(param_2 + 0x12) = *(undefined1 *)(lVar1 + 0x165f);
          }
          else if (((char)param_2[0x12] != '\0') && (*(char *)(lVar1 + 0x1176) == '\0')) {
            SdbusDebugPrint(1,"wp  %p Error: the card does not support wide bus",param_2,lVar6);
            return -0x3ffffff3;
          }
          if (*(int *)(lVar1 + 0x117c) == 2) {
            *(undefined4 *)(param_1 + 0x1b4) = 1;
          }
          else {
            if (*(char *)(lVar1 + 0x117a) != '\0') goto LAB_140014f70;
            if (*(int *)(lVar1 + 0x117c) != 3) {
              return -0x3fffffff;
            }
            *(undefined4 *)(param_1 + 0x1b4) = 4;
          }
          goto LAB_140014fe6;
        }
        param_2[0xb] = (ulonglong)(-(uint)(*(char *)(lVar1 + 0x165f) != '\0') & 3) + 1;
        if (*(char *)(lVar1 + 0x1660) != '\0') {
          param_2[0xb] = 8;
        }
        goto LAB_140015353;
      }
      if (uVar3 == 1) {
        lVar6 = param_2[0x12];
        SdbusDebugPrint(0x40,"wp  %p Set wide bus for memory function. bus width=%d",param_2,
                        (ulonglong)((-(uint)((char)lVar6 != '\0') & 3) + 1));
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescSetBusWidth,-(uint)((char)lVar6 != '\0') & 2,
                   0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 2;
        goto LAB_140014fe6;
      }
      if (uVar3 == 2) {
        if ((*(uint *)(lVar1 + 0x48) & 0x400) == 0) {
          *(undefined4 *)(param_1 + 0x1b8) = 3;
          SdbusDebugPrint(0x40,"wp  %p Disable pull-up resistor for memory card",param_2,param_4);
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,lVar1,(undefined8 *)&CmdDescSetClrCardDetect,0,0,0,0,0,0,0);
        }
      }
      else {
        if (uVar3 != 3) {
          if (uVar3 == 4) {
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,lVar1,(undefined8 *)&CmdDescSendExtCsd,
                       *(undefined4 *)(lVar1 + 0x168c),0x200,0,param_1 + 0x310,0,1,0);
            *(undefined4 *)(param_1 + 0x1b4) = 5;
            goto LAB_140014fe6;
          }
          if (uVar3 == 5) {
            *(ulonglong *)(lVar1 + 0x11b0) = (ulonglong)*(uint *)(param_1 + 0x3e4) << 9;
            *(uint *)(lVar1 + 0x11c0) = (uint)*(byte *)(param_1 + 0x407) * 10;
            if ((*(char *)(lVar1 + 0x165d) != '\0') || (*(char *)(lVar1 + 0x165e) != '\0')) {
              uVar3 = 0;
              lVar6 = lVar1 + 0x1171;
              do {
                bVar5 = (byte)uVar3;
                uVar3 = uVar3 + 1;
                *(bool *)lVar6 = (*(byte *)(param_1 + 0x3d5) & (byte)(1 << (bVar5 & 0x1f))) != 0;
                lVar6 = lVar6 + 1;
              } while (uVar3 < 5);
            }
            if ((*(char *)(lVar1 + 0x1177) == '\0') || (*(char *)(lVar1 + 0x1128) == '\0')) {
              if (*(char *)(lVar1 + 0x165d) != '\0') {
                uVar3 = (uint)*(byte *)(param_1 + 0x3fd);
                goto LAB_140014d70;
              }
              if (*(char *)(lVar1 + 0x165b) != '\0') goto LAB_140014d68;
              if (*(char *)(param_1 + 0x3d4) == '\x01') {
                bVar5 = *(byte *)(param_1 + 0x3db);
              }
              else {
                bVar5 = *(byte *)(param_1 + 0x3da);
              }
              uVar3 = bVar5 & 0xf;
LAB_140014d9c:
              uVar3 = uVar3 << 8;
            }
            else {
              if ((*(char *)(lVar1 + 0x165e) != '\0') || (*(char *)(lVar1 + 0x165d) != '\0')) {
                uVar3 = (uint)*(byte *)(param_1 + 0x3fd);
                goto LAB_140014d9c;
              }
              if (*(char *)(lVar1 + 0x165b) == '\0') {
                if (*(char *)(param_1 + 0x3d4) == '\x01') {
                  uVar3 = (uint)*(byte *)(param_1 + 0x3db);
                }
                else {
                  uVar3 = (uint)*(byte *)(param_1 + 0x3da);
                }
              }
              else {
LAB_140014d68:
                uVar3 = (uint)*(byte *)(param_1 + 0x3ff);
              }
LAB_140014d70:
              uVar3 = (uVar3 & 0xffffff0) << 4;
            }
            if (uVar3 != 0) {
              SdbusWorkerSetStateCmdExecWithFlags
                        (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,uVar3 | 0x3bb0000,0,0,0,0,0,0
                        );
              *(undefined4 *)(param_1 + 0x1b4) = 6;
              goto LAB_140014fe6;
            }
            *(undefined4 *)(param_1 + 0x1b4) = 6;
          }
          else if (uVar3 != 6) {
            if (uVar3 != 7) {
              return -0x3fffffff;
            }
            if (*(char *)(lVar1 + 0x117a) == '\0') {
              *(undefined4 *)(param_1 + 0x1b4) = 10;
            }
            else {
              *(undefined4 *)(param_1 + 0x1b8) = 0;
              SdbusWorkerSetStateCmdExecWithFlags
                        (param_1,lVar1,(undefined8 *)&CmdDescReadIoDirect,0xe00,0,0,0,0,0,0);
              *(undefined4 *)(param_1 + 0x1b4) = 8;
            }
            goto LAB_140014fe6;
          }
          if ((*(char *)(lVar1 + 0x1177) == '\0') || (*(char *)(lVar1 + 0x1128) == '\0')) {
            iVar7 = (-(uint)(*(char *)(lVar1 + 0x165b) != '\0') & 0x400) + 0x3b70100;
          }
          else {
            *(undefined1 *)(lVar1 + 0x1660) = 1;
            iVar7 = (-(uint)(*(char *)(lVar1 + 0x165b) != '\0') & 0x400) + 0x3b70200;
          }
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,iVar7,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 10;
          goto LAB_140014fe6;
        }
        SdbusDebugPrint(2,"wp  %p Disable pull-up resistor error!",param_2,param_4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      }
LAB_140014f70:
      *(undefined4 *)(param_1 + 0x1b4) = 7;
    }
LAB_140014fe6:
    iVar7 = -0x3fffffea;
  }
  else {
    if (uVar3 == 9) {
      *(undefined4 *)(param_1 + 0x1b4) = 10;
      if ((char)param_2[0x12] != '\0') {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescWriteIoDirect,0x80002c02,0,0,0,0,0,0);
        *(undefined1 *)(lVar1 + 0x1677) = 1;
        return -0x3fffffea;
      }
LAB_1400153c0:
      if ((int)param_2[5] == 0x1d) {
        *(char *)(lVar1 + 0x165f) = (char)param_2[0x12];
      }
      (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x58))
                (lVar1,(char)param_2[0x12]);
      if ((*(int *)(lVar1 + 0x117c) == 2) && (*(char *)(lVar1 + 0x1168) != '\0')) {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescSendScr,*(undefined4 *)(lVar1 + 0x168c),8,0,
                   param_1 + 0x570,0,1,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0xb;
        *(undefined4 *)(param_1 + 0x1b8) = 0xc;
        return -0x3fffffea;
      }
      if (*(char *)(lVar1 + 0x165b) != '\0') {
        *(undefined4 *)(param_1 + 0x1b4) = 0xe;
        return -0x3fffffea;
      }
    }
    else {
      if (uVar3 == 10) goto LAB_1400153c0;
      if (uVar3 != 0xb) {
        if (uVar3 == 0xc) {
          SdbusDebugPrint(1,"wp  %p SdbusBusWidthWorker: UHS-I Read SCR Error!",param_2,param_4);
          *(undefined1 *)(param_1 + 0x284) = 0;
          *(undefined4 *)(param_1 + 0x280) = 0;
          *(undefined1 *)(param_1 + 0x286) = 0;
          *(undefined4 *)(param_1 + 0x1a8) = 3;
          *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
          *(undefined4 *)(param_1 + 0x1b4) = 0xd;
          return -0x3fffffea;
        }
        if (uVar3 == 0xd) {
          return -0x3fffffff;
        }
        if (uVar3 != 0xe) {
          if (uVar3 != 0xf) {
            return -0x3fffffff;
          }
          iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x48))
                            (param_1 + 0x1d0,lVar1,0);
          if (iVar7 < 0) {
            return iVar7;
          }
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          return -0x3fffffff;
        }
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar1,4,0);
        if (-1 < iVar7) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          goto LAB_140015353;
        }
        if (iVar7 != -0x3fffffff) {
          return iVar7;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 0xf;
        goto LAB_140014fe6;
      }
      *(byte *)(lVar1 + 0x1190) = *(byte *)(param_1 + 0x570) & 0xf;
      *(byte *)(lVar1 + 0x1176) = *(byte *)(param_1 + 0x571) >> 2 & 1;
      *(byte *)(lVar1 + 0x11bc) = *(byte *)(param_1 + 0x573) >> 1 & 1;
      *(byte *)(lVar1 + 0x1191) = *(byte *)(param_1 + 0x572) >> 7;
    }
    SdbusDebugPrint(0x40,"wp  %p SetBusWidth Complete",param_2,param_4);
LAB_140015353:
    iVar7 = 0;
  }
  return iVar7;
}



===== SdbusFunctionBlockLengthWorker @ 140015480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SdbusFunctionBlockLengthWorker
          (longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  lVar4 = *param_2;
  lVar5 = param_2[1];
  iVar3 = *(int *)(param_1 + 0x1b4);
  if (iVar3 == 0) {
    SdbusDebugPrint(0x40,"wp  %p FunctionBlockLength enter",param_2,param_4);
    iVar3 = (int)param_2[5];
    uVar7 = 0;
    if (iVar3 - 0x27U < 3) {
      uVar7 = *(undefined1 *)(lVar5 + 0xc4);
    }
    *(undefined1 *)((longlong)param_2 + 0x92) = uVar7;
    if ((iVar3 == 0x27) || (iVar3 == 0x2a)) {
      param_2[0xb] = (ulonglong)*(ushort *)(lVar4 + 0x1664 + (ulonglong)*(byte *)(lVar5 + 0xc4) * 2)
      ;
      return 0;
    }
    if ((iVar3 == 0x29) || (iVar3 == 0x2c)) {
      lVar6 = *(longlong *)(lVar4 + 8);
      if (((*(char *)(lVar6 + 0x45) == '\x06') && (*(char *)(lVar6 + 0x46) == '\x01')) &&
         (*(char *)(lVar4 + 0x1699) != '\0')) {
        (**(code **)(*(longlong *)(lVar6 + 0x28) + 0x168))(lVar4);
      }
      *(undefined2 *)(param_2 + 0x12) =
           *(undefined2 *)(lVar4 + 0x1664 + (ulonglong)*(byte *)(lVar5 + 0xc4) * 2);
    }
    else {
      uVar1 = *(ushort *)(param_2 + 0x12);
      if (uVar1 == 0) {
        pcVar9 = "wp  %p Error: trying to set the block size to 0";
LAB_1400156d3:
        SdbusDebugPrint(1,pcVar9,param_2,param_4);
        return 0xc000000d;
      }
      if (*(ushort *)(lVar4 + 0x1146) < uVar1) {
        pcVar9 = "wp  %p Error: the new block size is larger than the controller\'s cap";
        goto LAB_1400156d3;
      }
      uVar2 = *(ushort *)(lVar4 + 0x11d2 + (ulonglong)*(byte *)(lVar5 + 0xc4) * 0x90);
      if ((uVar2 != 0) && (uVar2 < uVar1)) {
        SdbusDebugPrint(1,"wp  %p Error: the new block size is larger than the card\'s cap",param_2,
                        param_4);
      }
      if ((*(char *)((longlong)param_2 + 0x92) == '\b') && ((short)param_2[0x12] != 0x200)) {
        pcVar9 = "wp  %p Error: memory block size should always be 512";
        goto LAB_1400156d3;
      }
    }
    uVar8 = 3;
    if (1 < *(int *)(lVar5 + 200) - 2U) {
      uVar8 = 1;
    }
    *(undefined4 *)(param_1 + 0x1b4) = uVar8;
  }
  else if (iVar3 == 1) {
    SdbusDebugPrint(0x40,"wp  %p SetFunctionBlockLen(sdio) = %d",param_2,
                    (ulonglong)*(ushort *)(param_2 + 0x12));
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar4,(undefined8 *)&CmdDescWriteIoDirect,
               (uint)*(byte *)((longlong)param_2 + 0x92) * 0x20000 + 0x2000 |
               (uint)*(byte *)(param_2 + 0x12) | 0x80000000,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else if (iVar3 == 2) {
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar4,(undefined8 *)&CmdDescWriteIoDirect,
               (uint)*(byte *)((longlong)param_2 + 0x92) * 0x20000 + 0x2200 |
               (uint)*(byte *)((longlong)param_2 + 0x91) | 0x80000000,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 4;
  }
  else {
    if (iVar3 != 3) {
      if (iVar3 != 4) {
        return 0xc0000001;
      }
      if (((int)param_2[5] == 0x28) || ((int)param_2[5] == 0x2b)) {
        *(short *)(lVar4 + 0x1664 + (ulonglong)*(byte *)(lVar5 + 0xc4) * 2) = (short)param_2[0x12];
        return 0;
      }
      return 0;
    }
    SdbusDebugPrint(0x40,"wp  %p SetFunctionBlockLen(mem) = %d",param_2,
                    (ulonglong)*(ushort *)(param_2 + 0x12));
    if ((*(char *)(lVar4 + 0x165b) == '\0') && (*(char *)(lVar4 + 0x165e) == '\0')) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar4,(undefined8 *)&CmdDescSetBlocklen,(uint)*(ushort *)(param_2 + 0x12),0
                 ,0,0,0,0,0);
    }
    else {
      *(undefined2 *)(lVar4 + 0x1664 + (ulonglong)*(byte *)(lVar5 + 0xc4) * 2) = 0x200;
    }
    *(undefined4 *)(param_1 + 0x1b4) = 4;
  }
  return 0xc0000016;
}



===== SdbusHS400TuningWorker @ 1400157f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusHS400TuningWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  
  lVar1 = *param_2;
  uVar4 = *(uint *)(param_1 + 0x1b4);
  if (uVar4 < 8) {
    if (uVar4 == 7) {
      *(undefined4 *)(param_1 + 0x574) = 0xd;
      *(undefined4 *)(param_1 + 0x570) = 0;
      uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x88))
                        (param_1 + 0x1d0,lVar1,1,0);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      *(undefined4 *)(lVar1 + 0x174c) = 0;
      *(undefined4 *)(param_1 + 0x1b4) = 8;
      return 0xc0000016;
    }
    if (uVar4 == 0) {
      uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x50))
                        (param_1 + 0x1d0,lVar1,1,50000,*(undefined4 *)(lVar1 + 0x1684));
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      SdbusDebugPrint(0x40,"wp %p HS200 -> High speed bus clock set, freq=%d",param_2,
                      (ulonglong)*(uint *)(lVar1 + 0x167c));
      *(undefined4 *)(param_1 + 0x570) = 0;
      *(undefined4 *)(param_1 + 0x574) = 0xe;
      *(uint *)(param_1 + 0x1b4) = (*(char *)(*(longlong *)(lVar1 + 8) + 0x45) != '\n') + 1;
      return 0xc0000016;
    }
    if (uVar4 == 1) {
      *(undefined4 *)(param_1 + 0x570) = 0;
      *(undefined4 *)(param_1 + 0x574) = 0xe;
      uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x88))
                        (param_1 + 0x1d0,lVar1,1,1);
      if ((int)uVar3 == -0x3fffffea) {
        return uVar3;
      }
      if ((int)uVar3 < 0) {
        *(undefined4 *)(param_1 + 0x1b4) = 0xd;
        return 0xc0000016;
      }
      *(undefined4 *)(lVar1 + 0x174c) = 0;
      *(undefined4 *)(param_1 + 0x1b4) = 2;
      return 0xc0000016;
    }
    if (uVar4 == 2) {
      if ((4 < *(uint *)(param_1 + 0x570)) && (*(int *)(param_1 + 0x574) == 2)) {
        return 0xc0000184;
      }
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,
                 (uint)*(byte *)(lVar1 + 0x16a5) << 0xc | 0x3b90100,0,0,0,0,0,0);
      uVar2 = *(undefined4 *)(param_1 + 0x1b4);
      *(undefined4 *)(param_1 + 0x1b4) = 3;
    }
    else {
      if (uVar4 == 3) {
        *(undefined4 *)(param_1 + 0x570) = 0;
        *(undefined4 *)(param_1 + 0x574) = 0xe;
        uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar1,4,0);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 5;
        return 0xc0000016;
      }
      if (uVar4 == 5) {
        if ((4 < *(uint *)(param_1 + 0x570)) && (*(int *)(param_1 + 0x574) == 5)) {
          return 0xc0000184;
        }
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,
                   (*(byte *)(param_1 + 0x40d) & 0xffffff0) << 4 | 0x3bb0000,0,0,0,0,0,0);
        uVar2 = *(undefined4 *)(param_1 + 0x1b4);
        *(undefined4 *)(param_1 + 0x1b4) = 6;
      }
      else {
        if (uVar4 != 6) {
          return 0xc0000001;
        }
        if ((4 < *(uint *)(param_1 + 0x570)) && (*(int *)(param_1 + 0x574) == 6)) {
          return 0xc0000184;
        }
        *(undefined4 *)(param_1 + 0x570) = 0;
        *(undefined4 *)(param_1 + 0x574) = 0xe;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,0x3b70200,0,0,0,0,0,0);
        uVar2 = *(undefined4 *)(param_1 + 0x1b4);
        *(undefined4 *)(param_1 + 0x1b4) = 7;
      }
    }
  }
  else {
    if (uVar4 != 8) {
      if (uVar4 == 9) {
        *(undefined4 *)(param_1 + 0x574) = 0xd;
        *(undefined4 *)(param_1 + 0x570) = 0;
        uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar1,5,1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 10;
        return 0xc0000016;
      }
      if (uVar4 != 10) {
        if (uVar4 == 0xb) {
          SdbusDebugPrint(0x40,"wp  %p SdbusHS400RetuningWorker completed",param_2,param_4);
          *(undefined1 *)(param_1 + 0x28c) = 1;
        }
        else {
          if (uVar4 != 0xc) {
            return 0xc0000001;
          }
          SdbusDebugPrint(1,"wp  %p Set HS400 failed",param_2,param_4);
          *(undefined4 *)(param_1 + 0x280) = 1;
          *(undefined1 *)(param_1 + 0x284) = 0;
          *(undefined1 *)(param_1 + 0x286) = 0;
          *(undefined4 *)(param_1 + 0x1a8) = 3;
          *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
          if (*(uint *)(param_1 + 0x574) < 0xd) {
            *(uint *)(param_1 + 0x1b4) = *(uint *)(param_1 + 0x574);
            *(undefined4 *)(param_1 + 0x570) = 0;
            *(undefined4 *)(param_1 + 0x574) = 0xd;
            return 0xc0000016;
          }
        }
        return 0;
      }
      uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x50))
                        (param_1 + 0x1d0,lVar1,1,200000,*(undefined4 *)(lVar1 + 0x1684));
      if ((int)uVar3 == -0x3fffffea) {
        return uVar3;
      }
      if ((int)uVar3 < 0) {
        *(undefined4 *)(param_1 + 0x1b4) = 0xd;
        return 0xc0000016;
      }
      SdbusDebugPrint(0x40,"wp  %p DDR50 -> HS400 bus clock set, freq=%d",param_2,
                      (ulonglong)*(uint *)(lVar1 + 0x167c));
      *(undefined4 *)(param_1 + 0x1b4) = 0xb;
      return 0xc0000016;
    }
    if ((4 < *(uint *)(param_1 + 0x570)) && (*(int *)(param_1 + 0x574) == 8)) {
      return 0xc0000184;
    }
    if (*(char *)(*(longlong *)(lVar1 + 8) + 0x45) == '\f') {
      uVar4 = 0x3b91200;
    }
    else {
      uVar4 = (uint)*(byte *)(lVar1 + 0x16a5) << 0xc | 0x3b90200;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,uVar4,0,0,0,0,0,0);
    uVar2 = *(undefined4 *)(param_1 + 0x1b4);
    *(undefined4 *)(param_1 + 0x1b4) = 9;
  }
  *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
  *(undefined4 *)(param_1 + 0x1b8) = 0xc;
  *(undefined4 *)(param_1 + 0x574) = uVar2;
  return 0xc0000016;
}



===== SdbusHS400Worker @ 140015d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SdbusHS400Worker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  char cVar7;
  
  lVar2 = *param_2;
  puVar1 = (uint *)(param_1 + 0x1b4);
  uVar4 = *puVar1;
  if (uVar4 < 8) {
    if (uVar4 == 7) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,
                 (*(byte *)(param_1 + 0x40d) | 0x3bb00) << 8,0,0,0,0,0,0);
      *puVar1 = 8;
      goto LAB_1400163e1;
    }
    if (uVar4 != 0) {
      if (uVar4 == 1) {
        uVar4 = *(uint *)(param_1 + 0x25c) >> 0x13;
        if (uVar4 != 0) {
          SdbusDebugPrint(1,"wp %p SdbusHS400Worker Status Error %x",param_2,(ulonglong)uVar4);
          SdbusCardErrorToNtStatus(uVar4,(int *)((longlong)param_2 + 0x3c));
          *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 0x40000000;
          *puVar1 = 0xd;
          return 0xc0000016;
        }
      }
      else if (uVar4 != 2) {
        if (uVar4 == 3) {
          uVar4 = 4;
          *(undefined8 *)(lVar2 + 0x16c7) = *(undefined8 *)(lVar2 + 0x7c6);
          *(undefined8 *)(lVar2 + 0x16cf) = *(undefined8 *)(lVar2 + 0x7ce);
          *(undefined8 *)(lVar2 + 0x16d7) = *(undefined8 *)(lVar2 + 0x7d6);
          *(undefined8 *)(lVar2 + 0x16df) = *(undefined8 *)(lVar2 + 0x7de);
          *puVar1 = 4;
        }
        else if (uVar4 != 4) {
          if (uVar4 == 5) {
            *(undefined4 *)(param_1 + 0x570) = 0;
            *(undefined4 *)(param_1 + 0x574) = 0xe;
            uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x88))
                              (param_1 + 0x1d0,lVar2,1,1);
            if ((int)uVar3 == -0x3fffffea) {
              return uVar3;
            }
            if (-1 < (int)uVar3) {
              *(undefined4 *)(lVar2 + 0x174c) = 0;
              uVar4 = 8;
              if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\f') {
                uVar4 = 6;
              }
              goto LAB_140015eec;
            }
          }
          else {
            if (uVar4 != 6) {
              return 0xc0000001;
            }
            uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x50))
                              (param_1 + 0x1d0,lVar2,1,50000,*(undefined4 *)(lVar2 + 0x1684));
            if ((int)uVar3 == -0x3fffffea) {
              return uVar3;
            }
            if (-1 < (int)uVar3) {
              SdbusDebugPrint(0x40,"wp %p HS200 -> High speed bus clock set, freq=%d",param_2,
                              (ulonglong)*(uint *)(lVar2 + 0x167c));
              uVar4 = 5;
              if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\f') {
                uVar4 = 7;
              }
LAB_140015eec:
              *puVar1 = uVar4;
              return 0xc0000016;
            }
          }
LAB_140015ebe:
          *puVar1 = 0xd;
          return 0xc0000016;
        }
        uVar6 = 5;
        if ((4 < *(uint *)(param_1 + 0x570)) && (*(uint *)(param_1 + 0x574) == uVar4)) {
          return 0xc0000184;
        }
        *(undefined4 *)(param_1 + 0x570) = 0;
        *(undefined4 *)(param_1 + 0x574) = 0xe;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,
                   (uint)*(byte *)(lVar2 + 0x16a5) << 0xc | 0x3b90100,0,0,0,0,0,0);
        *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
        *(uint *)(param_1 + 0x574) = *puVar1;
        if ((*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\f') &&
           (uVar6 = 8, *(char *)(lVar2 + 0x1192) != 'p')) {
          uVar6 = 6;
        }
        *(undefined4 *)(param_1 + 0x1b4) = uVar6;
        goto LAB_1400163e1;
      }
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescSendExtCsd,0x53454852,0x200,0,lVar2 + 0x6b8,0,1
                 ,0);
      *puVar1 = 3;
      goto LAB_1400163e1;
    }
    SdbusDebugPrint(0x40,"wp  %p SdbusHS400Worker entered",param_2,param_4);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescSendStatus,*(undefined4 *)(lVar2 + 0x168c),0,0,0,
               0,0,0);
    *(undefined4 *)(param_1 + 0x570) = 0;
    *(undefined4 *)(param_1 + 0x574) = 0xe;
    uVar4 = 2;
    if (*(char *)(lVar2 + 0x1192) != -0x70) {
      uVar4 = 4;
    }
  }
  else {
    if (uVar4 == 8) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,0x3b70600,0,0,0,0,0,0);
      *puVar1 = 9;
      goto LAB_1400163e1;
    }
    if (uVar4 != 9) {
      if (uVar4 == 10) {
        *(undefined4 *)(param_1 + 0x574) = 0xe;
        *(undefined4 *)(param_1 + 0x570) = 0;
        uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar2,6,1);
        if ((int)uVar3 == -0x3fffffea) {
          return uVar3;
        }
        if (-1 < (int)uVar3) {
          *(undefined4 *)(lVar2 + 0x174c) = 0;
          *puVar1 = 0xc - (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\f');
          return 0xc0000016;
        }
      }
      else {
        if (uVar4 != 0xb) {
          if (uVar4 == 0xc) {
            SdbusDebugPrint(0x40,"wp  %p SdbusHS400Worker completed",param_2,param_4);
            return 0;
          }
          if (uVar4 != 0xd) {
            return 0xc0000001;
          }
          SdbusDebugPrint(1,"wp  %p Set HS400 failed",param_2,param_4);
          *(undefined4 *)(param_1 + 0x280) = 1;
          *(undefined1 *)(param_1 + 0x284) = 0;
          *(undefined1 *)(param_1 + 0x286) = 0;
          *(undefined4 *)(param_1 + 0x1a8) = 3;
          *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
          if (*(uint *)(param_1 + 0x574) < 0xe) {
            *puVar1 = *(uint *)(param_1 + 0x574);
            *(undefined4 *)(param_1 + 0x570) = 0;
            *(undefined4 *)(param_1 + 0x574) = 0xe;
            return 0xc0000016;
          }
          return (ulonglong)(-(uint)(*(char *)(lVar2 + 0x165e) != '\0') & 0xc0000001);
        }
        uVar5 = 400000;
        if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\n') {
          uVar5 = 200000;
        }
        uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x50))
                          (param_1 + 0x1d0,lVar2,1,uVar5,*(undefined4 *)(lVar2 + 0x1684));
        if ((int)uVar3 == -0x3fffffea) {
          return uVar3;
        }
        if (-1 < (int)uVar3) {
          SdbusDebugPrint(0x40,"wp  %p DDR50 -> HS400 bus clock set, freq=%d",param_2,
                          (ulonglong)*(uint *)(lVar2 + 0x167c));
          *(undefined4 *)(lVar2 + 0x174c) = 0;
          uVar4 = 10;
          if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\f') {
            uVar4 = 0xc;
          }
          *puVar1 = uVar4;
          return 0xc0000016;
        }
      }
      goto LAB_140015ebe;
    }
    if ((4 < *(uint *)(param_1 + 0x570)) && (*(int *)(param_1 + 0x574) == 9)) {
      return 0xc0000184;
    }
    *(undefined4 *)(param_1 + 0x574) = 0xe;
    *(undefined4 *)(param_1 + 0x570) = 0;
    cVar7 = '\f';
    if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\f') {
      uVar4 = 0x3b91300;
    }
    else {
      uVar4 = (uint)*(byte *)(lVar2 + 0x16a5) << 0xc | 0x3b90300;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,uVar4,0,0,0,0,0,0);
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
    *(uint *)(param_1 + 0x574) = *puVar1;
    uVar4 = 0xb - (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != cVar7);
  }
  *puVar1 = uVar4;
LAB_1400163e1:
  *(undefined4 *)(param_1 + 0x1b8) = 0xd;
  return 0xc0000016;
}



===== SdbusHighSpeedDetectionWorker @ 140016420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusHighSpeedDetectionWorker
          (longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  void *_Dst;
  undefined4 uVar7;
  
  lVar2 = *param_2;
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    SdbusDebugPrint(0x40,"wp  %p HighSpeedDetection entered",param_2,param_4);
    if (*(int *)(lVar2 + 0x3c) != 1) {
      return 0;
    }
    *(undefined2 *)(lVar2 + 0x1166) = 0;
    *(undefined2 *)(lVar2 + 0x1163) = 0;
    *(undefined1 *)(lVar2 + 0x1165) = 0;
    *(undefined1 *)(lVar2 + 0x1162) = 0;
    if (*(int *)(lVar2 + 0x117c) == 3) {
      if (3 < *(byte *)(lVar2 + 0x1190)) {
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        return 0xc0000016;
      }
      pcVar3 = "wp  %p High Speed is not supported: MMC card";
LAB_1400169bf:
      SdbusDebugPrint(0x40,pcVar3,param_2,param_4);
      *(undefined1 *)(lVar2 + 0x1162) = 0;
      *(undefined1 *)(lVar2 + 0x1658) = 0;
      return 0;
    }
    if ((*(uint *)(lVar2 + 0x48) & 0x40) != 0) {
      pcVar3 = "wp  %p High Speed is not supported: disabled (forced)";
      goto LAB_1400169bf;
    }
    if (*(char *)(lVar2 + 0x1178) != '\0') {
      SdbusDebugPrint(0x40,"wp  %p Card is locked, switching to high speed is illegal",param_2,
                      param_4);
      return 0;
    }
    if (*(char *)(lVar2 + 0x117a) != '\0') {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescReadIoDirect,0x2600,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 5;
      *(undefined4 *)(param_1 + 0x1b8) = 7;
      return 0xc0000016;
    }
    _Dst = (void *)(param_1 + 0x570);
    memset(_Dst,0,0x40);
    puVar4 = (undefined8 *)&CmdDescSwitchFunction;
    uVar7 = 1;
    uVar5 = 0;
    uVar6 = 0x40;
  }
  else {
    if (iVar1 == 1) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescSendExtCsd,*(undefined4 *)(lVar2 + 0x168c),
                 0x200,0,param_1 + 0x310,0,1,0);
      goto LAB_140016ab7;
    }
    if (iVar1 != 5) {
      if (iVar1 != 6) {
        if (iVar1 == 7) {
          SdbusDebugPrint(0x40,"wp  %p HighSpeedDetection Failed",param_2,param_4);
          *(undefined2 *)(lVar2 + 0x1659) = 0;
          *(undefined1 *)(lVar2 + 0x165b) = 0;
          *(undefined1 *)(lVar2 + 0x1162) = 0;
          *(undefined1 *)(lVar2 + 0x1658) = 0;
          *(undefined1 *)(param_1 + 0x284) = 0;
          *(undefined4 *)(param_1 + 0x280) = 1;
          *(undefined1 *)(param_1 + 0x286) = 0;
          *(undefined4 *)(param_1 + 0x1a8) = 3;
          *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
          *(undefined4 *)(param_1 + 0x1b4) = 8;
          return 0xc0000016;
        }
        if (iVar1 == 8) {
          return 0;
        }
        return 0xc0000001;
      }
      if (*(char *)(lVar2 + 0x117a) != '\0') {
        if ((*(byte *)(param_1 + 0x25c) & 1) != 0) {
          *(undefined1 *)(lVar2 + 0x1164) = 1;
        }
        if ((*(byte *)(param_1 + 0x25c) & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x1163) = 1;
        }
        if ((*(byte *)(param_1 + 0x25c) & 4) != 0) {
          *(undefined1 *)(lVar2 + 0x1165) = 1;
        }
      }
      if (*(int *)(lVar2 + 0x117c) == 2) {
        if ((*(byte *)(param_1 + 0x57d) & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x1162) = 1;
        }
        if ((*(byte *)(param_1 + 0x57d) & 4) != 0) {
          *(undefined1 *)(lVar2 + 0x1164) = 1;
        }
        if ((*(byte *)(param_1 + 0x57d) & 8) != 0) {
          *(undefined1 *)(lVar2 + 0x1163) = 1;
        }
        if ((*(byte *)(param_1 + 0x57d) & 0x10) != 0) {
          *(undefined1 *)(lVar2 + 0x1165) = 1;
        }
        if ((*(byte *)(param_1 + 0x579) & 1) != 0) {
          *(undefined1 *)(lVar2 + 0x116a) = 1;
        }
        if ((*(byte *)(param_1 + 0x579) & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x1169) = 1;
        }
        if ((*(byte *)(param_1 + 0x579) & 4) != 0) {
          *(undefined1 *)(lVar2 + 0x116b) = 1;
        }
        if ((*(byte *)(param_1 + 0x579) & 8) != 0) {
          *(undefined1 *)(lVar2 + 0x116c) = 1;
        }
        if ((*(byte *)(param_1 + 0x577) & 1) != 0) {
          *(undefined1 *)(lVar2 + 0x116d) = 1;
        }
        if ((*(byte *)(param_1 + 0x577) & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x116e) = 1;
        }
        if ((*(byte *)(param_1 + 0x577) & 4) != 0) {
          *(undefined1 *)(lVar2 + 0x116f) = 1;
        }
        if ((*(byte *)(param_1 + 0x577) & 8) != 0) {
          *(undefined1 *)(lVar2 + 0x1170) = 1;
        }
      }
      else if ((*(int *)(lVar2 + 0x117c) == 3) && (3 < *(byte *)(lVar2 + 0x1190))) {
        if ((*(byte *)(param_1 + 0x3d4) & 0xc0) != 0) {
          *(undefined1 *)(lVar2 + 0x1167) = 1;
        }
        if ((*(byte *)(param_1 + 0x3d4) & 0x30) != 0) {
          *(undefined1 *)(lVar2 + 0x1166) = 1;
        }
        if ((*(byte *)(param_1 + 0x3d4) & 0xc) != 0) {
          *(undefined1 *)(lVar2 + 0x1165) = 1;
        }
        if ((*(byte *)(param_1 + 0x3d4) & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x1162) = 1;
        }
        if ((*(uint *)(lVar2 + 0x48) & 0x40) == 0) {
          if ((*(char *)(lVar2 + 0x1167) == '\0') || (*(char *)(lVar2 + 0x112d) == '\0')) {
            if ((*(char *)(lVar2 + 0x1166) != '\0') && (*(char *)(lVar2 + 0x112c) != '\0')) {
              *(undefined1 *)(lVar2 + 0x165d) = 1;
              if ((*(char *)(*(longlong *)(lVar2 + 8) + 0x45) != '\x06') ||
                 (*(char *)(*(longlong *)(lVar2 + 8) + 0x46) != '\x01')) goto LAB_1400166ae;
              *(undefined1 *)(lVar2 + 0x165d) = 0;
            }
            if ((*(char *)(lVar2 + 0x1165) == '\0') || (*(char *)(lVar2 + 0x112b) == '\0')) {
              if ((*(char *)(lVar2 + 0x1162) == '\0') || (*(char *)(lVar2 + 0x1124) == '\0'))
              goto LAB_1400166a7;
              *(undefined1 *)(lVar2 + 0x1658) = 1;
            }
            else {
              *(undefined1 *)(lVar2 + 0x165b) = 1;
            }
          }
          else {
            *(undefined1 *)(lVar2 + 0x165e) = 1;
          }
        }
        else {
          SdbusDebugPrint(0x40,"wp  %p MMC High Speed is not supported: disabled (forced)",param_2,
                          param_4);
LAB_1400166a7:
          *(undefined1 *)(lVar2 + 0x1658) = 0;
        }
LAB_1400166ae:
        if ((*(byte *)(param_1 + 0x507) & 1) == 0) {
          *(undefined2 *)(param_1 + 0x518) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x518) = 1;
          *(uint *)(param_1 + 0x51c) = 2 - (uint)((*(byte *)(param_1 + 0x507) & 2) != 0);
          *(uint *)(param_1 + 0x520) = (uint)*(byte *)(param_1 + 0x3d6) * 10;
          *(undefined1 *)(param_1 + 0x519) = *(undefined1 *)(lVar2 + 0x173c);
          if (*(int *)(lVar2 + 0x2d0) != 3) {
            *(undefined1 *)(param_1 + 0x519) = 0;
          }
        }
        goto LAB_14001689f;
      }
      *(undefined2 *)(lVar2 + 0x1659) = 0;
      *(undefined1 *)(lVar2 + 0x165b) = 0;
      *(undefined1 *)(lVar2 + 0x1658) = 0;
      if ((*(char *)(lVar2 + 0x112a) == '\0') || (*(char *)(lVar2 + 0x1163) == '\0')) {
        if ((*(char *)(lVar2 + 0x112b) == '\0') || (*(char *)(lVar2 + 0x1165) == '\0')) {
          if ((*(char *)(lVar2 + 0x1129) == '\0') || (*(char *)(lVar2 + 0x1164) == '\0')) {
            if ((*(char *)(lVar2 + 0x1124) != '\0') && (*(char *)(lVar2 + 0x1162) != '\0')) {
              *(undefined1 *)(lVar2 + 0x1658) = 1;
            }
          }
          else {
            *(undefined1 *)(lVar2 + 0x165a) = 1;
          }
        }
        else {
          *(undefined1 *)(lVar2 + 0x165b) = 1;
        }
      }
      else {
        *(undefined1 *)(lVar2 + 0x1659) = 1;
      }
      if (((*(char *)(lVar2 + 0x165c) == '\0') && (*(char *)(lVar2 + 0x16e8) != '\0')) &&
         (*(int *)(lVar2 + 0x1120) == 1)) {
        *(undefined2 *)(lVar2 + 0x1659) = 0;
        *(undefined1 *)(lVar2 + 0x165b) = 0;
        if ((*(char *)(lVar2 + 0x1124) != '\0') && (*(char *)(lVar2 + 0x1162) != '\0')) {
          *(undefined1 *)(lVar2 + 0x1658) = 1;
        }
      }
      *(undefined4 *)(lVar2 + 0x1694) = 200;
      if ((*(char *)(lVar2 + 0x1137) == '\0') || (*(char *)(lVar2 + 0x1170) == '\0')) {
        if ((*(char *)(lVar2 + 0x1136) == '\0') || (*(char *)(lVar2 + 0x116f) == '\0')) {
          if ((*(char *)(lVar2 + 0x1135) != '\0') && (*(char *)(lVar2 + 0x116e) != '\0')) {
            *(undefined4 *)(lVar2 + 0x1694) = 400;
          }
        }
        else {
          *(undefined4 *)(lVar2 + 0x1694) = 600;
        }
      }
      else {
        *(undefined4 *)(lVar2 + 0x1694) = 800;
      }
LAB_14001689f:
      SdbusDebugPrint(0x40,"wp  %p HighSpeedDetection Complete: support=%d, enabled=%d",param_2,
                      (ulonglong)*(byte *)(lVar2 + 0x1162));
      return 0;
    }
    if ((*(char *)(lVar2 + 0x117a) != '\0') && ((*(byte *)(param_1 + 0x25c) & 1) != 0)) {
      *(undefined1 *)(lVar2 + 0x1162) = 1;
    }
    puVar4 = (undefined8 *)&CmdDescReadIoDirect;
    uVar7 = 0;
    uVar5 = 0x2800;
    _Dst = (void *)0x0;
    uVar6 = 0;
  }
  SdbusWorkerSetStateCmdExecWithFlags(param_1,lVar2,puVar4,uVar5,uVar6,0,_Dst,0,uVar7,0);
  *(undefined4 *)(param_1 + 0x1b8) = 7;
LAB_140016ab7:
  *(undefined4 *)(param_1 + 0x1b4) = 6;
  return 0xc0000016;
}



===== SdbusHighSpeedWorker @ 140016af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SdbusHighSpeedWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  code *pcVar5;
  char *pcVar6;
  short sVar7;
  undefined8 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  undefined2 uVar12;
  void *_Dst;
  undefined4 uVar13;
  
  lVar2 = *param_2;
  iVar4 = *(int *)(param_1 + 0x1b4);
  if (iVar4 != 0) {
    uVar11 = 2;
    if (iVar4 == 2) {
      SdbusDebugPrint(1,"wp  %p SetHighSpeed failed",param_2,param_4);
LAB_140016b80:
      *(undefined1 *)(lVar2 + 0x1658) = 0;
      return 0;
    }
    if (iVar4 == 3) {
      SdbusDebugPrint(0x40,"wp  %p SetHighSpeed Failed",param_2,param_4);
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      if ((char)*(undefined4 *)(lVar2 + 0x48) < '\0') {
        SdbusDebugPrint(0x40,"wp  %p Force to set high speed",param_2,param_4);
        uVar11 = 4;
      }
      goto LAB_1400170a8;
    }
    if (iVar4 != 4) {
      if (iVar4 != 5) {
        return -0x3fffffff;
      }
LAB_140016d17:
      if ((*(uint *)(lVar2 + 0x48) & 0x20000000) != 0) {
        return 0;
      }
      lVar3 = *(longlong *)(lVar2 + 8);
      if ((*(char *)(lVar3 + 0x45) == '\x06') && (*(char *)(lVar3 + 0x46) == '\x01')) {
        return 0;
      }
      (**(code **)(*(longlong *)(lVar3 + 0x28) + 0x98))(lVar2,1);
      *(undefined1 *)(lVar2 + 0x1661) = 1;
      return 0;
    }
    if (((*(int *)(lVar2 + 0x117c) == 2) && (*(char *)(param_1 + 0x570) == '\0')) &&
       (*(char *)(param_1 + 0x571) == '\0')) {
      *(undefined2 *)(lVar2 + 0x1659) = 0;
      *(undefined1 *)(lVar2 + 0x165b) = 0;
      goto LAB_140016b80;
    }
    if ((param_2[0x11] != 0) && (*(int *)(param_2[9] + 0x10) == 6)) {
      return 0;
    }
    if (*(int *)(lVar2 + 0x117c) == 3) {
      if ((*(char *)(lVar2 + 0x165d) != '\0') || (*(char *)(lVar2 + 0x165e) != '\0')) {
        iVar4 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar2,5,0);
        if (-1 < iVar4) {
          *(undefined4 *)(lVar2 + 0x174c) = 0;
          return iVar4;
        }
LAB_140016c22:
        if (iVar4 == -0x3fffffff) {
          *(undefined4 *)(lVar2 + 0x174c) = 0;
          *(undefined4 *)(param_1 + 0x1b4) = 3;
          return -0x3fffffea;
        }
        return iVar4;
      }
      if ((*(char *)(lVar2 + 0x165b) == '\0') && (*(char *)(lVar2 + 0x1658) == '\0')) {
        return 0;
      }
      pcVar5 = *(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x70);
    }
    else {
      sVar7 = 0;
      if (*(char *)(lVar2 + 0x1659) == '\0') {
        if (*(char *)(lVar2 + 0x165a) == '\0') {
          if (*(char *)(lVar2 + 0x165b) != '\0') {
            sVar7 = 4;
          }
        }
        else {
          sVar7 = 2;
        }
      }
      else {
        sVar7 = 3;
      }
      if (sVar7 != 0) {
        if (((*(uint *)(lVar2 + 0x48) >> 0x1d & 1) == 0) &&
           ((lVar3 = *(longlong *)(lVar2 + 8), *(char *)(lVar3 + 0x45) != '\x06' ||
            (*(char *)(lVar3 + 0x46) != '\x01')))) {
          (**(code **)(*(longlong *)(lVar3 + 0x28) + 0x98))(lVar2,1);
          *(undefined1 *)(lVar2 + 0x1661) = 1;
        }
        iVar4 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x88))
                          (param_1 + 0x1d0,lVar2,sVar7,0);
        if (-1 < iVar4) {
          *(undefined4 *)(lVar2 + 0x174c) = 0;
          if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\t') {
            return iVar4;
          }
          *(undefined4 *)(param_1 + 0x1b4) = 5;
          return -0x3fffffea;
        }
        goto LAB_140016c22;
      }
      if (((-1 < (char)*(uint *)(lVar2 + 0x48)) && (*(char *)(lVar2 + 0x117a) == '\0')) &&
         ((*(byte *)(param_1 + 0x580) & 0xf) != 1)) goto LAB_140016d17;
      pcVar5 = *(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x70);
    }
    (*pcVar5)(lVar2,1);
    pcVar6 = "wp  %p SetHighSpeed succeeded";
LAB_140016e7b:
    SdbusDebugPrint(0x40,pcVar6,param_2,param_4);
    return 0;
  }
  SdbusDebugPrint(0x40,"wp  %p SdbusHighSpeedWorker entered",param_2,param_4);
  *(undefined1 *)(lVar2 + 0x1661) = 0;
  if (((((*(char *)(lVar2 + 0x165e) == '\0') && (*(char *)(lVar2 + 0x165d) == '\0')) &&
       (*(char *)(lVar2 + 0x1658) == '\0')) &&
      ((*(char *)(lVar2 + 0x1659) == '\0' && (*(char *)(lVar2 + 0x165a) == '\0')))) &&
     (*(char *)(lVar2 + 0x165b) == '\0')) {
    return 0;
  }
  if (*(char *)(lVar2 + 0x1178) != '\0') {
    pcVar6 = "wp  %p card locked, cannot switch to high speed";
    goto LAB_140016e7b;
  }
  *(undefined4 *)(param_1 + 0x1b8) = 3;
  uVar11 = 4;
  if (*(char *)(lVar2 + 0x117a) != '\0') {
    if (*(char *)(lVar2 + 0x1659) == '\0') {
      if (*(char *)(lVar2 + 0x165a) == '\0') {
        if (*(char *)(lVar2 + 0x165b) == '\0') {
          uVar9 = 0x2600;
          if (*(char *)(lVar2 + 0x1658) != '\0') {
            uVar9 = 0x2602;
          }
        }
        else {
          uVar9 = 0x2608;
        }
      }
      else {
        uVar9 = 0x2604;
      }
    }
    else {
      uVar9 = 0x2606;
    }
    uVar10 = (ulonglong)(uVar9 | 0x80000000);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescWriteIoDirect,uVar9 | 0x80000000,0,0,0,0,0,0);
    SdbusDebugPrint(0x40,"wp  %p SDIO SetHighSpeed init",param_2,uVar10);
    goto LAB_1400170a8;
  }
  if ((*(int *)(lVar2 + 0x117c) == 3) && (3 < *(byte *)(lVar2 + 0x1190))) {
    if ((*(char *)(lVar2 + 0x165e) == '\0') && (*(char *)(lVar2 + 0x165d) == '\0')) {
      if ((*(char *)(lVar2 + 0x165b) == '\0') && (*(char *)(lVar2 + 0x1658) == '\0'))
      goto LAB_1400170a8;
      uVar9 = 0x3b90100;
    }
    else if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\f') {
      uVar9 = 0x3b91200;
    }
    else {
      uVar9 = (uint)*(byte *)(lVar2 + 0x16a5) << 0xc | 0x3b90200;
    }
    puVar8 = (undefined8 *)&CmdDescMmcSwitch;
    uVar13 = 0;
    _Dst = (void *)0x0;
    uVar12 = 0;
  }
  else {
    uVar9 = 0xffffff;
    if (*(char *)(lVar2 + 0x1659) == '\0') {
      if (*(char *)(lVar2 + 0x165a) != '\0') {
        uVar9 = 0xfffff2;
        goto LAB_140017007;
      }
      if (*(char *)(lVar2 + 0x165b) != '\0') {
        uVar9 = 0xfffff4;
        goto LAB_140017007;
      }
      if (*(char *)(lVar2 + 0x1658) != '\0') {
        uVar9 = 0xfffff1;
      }
    }
    else {
      uVar9 = 0xfffff3;
LAB_140017007:
      uVar1 = *(uint *)(lVar2 + 0x1694);
      if (uVar1 < 800) {
        if (uVar1 < 600) {
          if (uVar1 < 400) {
            if (199 < uVar1) {
              uVar9 = uVar9 & 0xff0fff;
            }
          }
          else {
            uVar9 = uVar9 & 0xff1fff;
          }
        }
        else {
          uVar9 = uVar9 & 0xff2fff;
        }
      }
      else {
        uVar9 = uVar9 & 0xff3fff;
      }
    }
    _Dst = (void *)(param_1 + 0x570);
    memset(_Dst,0,0x40);
    puVar8 = (undefined8 *)&CmdDescSwitchFunction;
    uVar13 = 1;
    uVar9 = uVar9 | 0x80000000;
    uVar12 = 0x40;
  }
  SdbusWorkerSetStateCmdExecWithFlags(param_1,lVar2,puVar8,uVar9,uVar12,0,_Dst,0,uVar13,0);
LAB_1400170a8:
  *(undefined4 *)(param_1 + 0x1b4) = uVar11;
  return -0x3fffffea;
}



===== SdbusInitializeCardWorker @ 1400170e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusInitializeCardWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  
  uVar10 = *(uint *)(param_1 + 0x1b4);
  lVar1 = *param_2;
  if (0x13 < uVar10) {
    if (uVar10 < 0x1e) {
      if (uVar10 == 0x1d) {
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x40))
                          (param_1 + 0x1d0,lVar1,(int)param_2[0x12]);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(uint *)(param_2 + 0x12) = *(uint *)(param_2 + 0x12) | 0x80;
        uVar11 = *(undefined4 *)(lVar1 + 0x171c);
        *(undefined4 *)(param_1 + 0x1b4) = 0x1e;
LAB_1400184bb:
        *(undefined4 *)(param_1 + 0x1d4) = uVar11;
        return 0xc0000016;
      }
      if (uVar10 == 0x14) {
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x78))
                          (param_1 + 0x1d0,lVar1);
        if (-1 < (int)uVar6) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,lVar1,(undefined8 *)&CmdDescSendVoltageSwitch,0,0,0,0,0,0,0);
          goto LAB_140017b47;
        }
LAB_140017fbe:
        if ((int)uVar6 == -0x3fffffff) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          *(undefined4 *)(param_1 + 0x1b4) = 0x16;
          return 0xc0000016;
        }
        return uVar6;
      }
      if (uVar10 == 0x15) {
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x80))
                          (param_1 + 0x1d0,lVar1,1);
        if (-1 < (int)uVar6) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          *(undefined1 *)(lVar1 + 0x165c) = 1;
          goto LAB_140017b82;
        }
        goto LAB_140017fbe;
      }
      if (uVar10 == 0x16) {
LAB_140017798:
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x48))
                          (param_1 + 0x1d0,lVar1,0);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        return 0xc0000001;
      }
      if (uVar10 == 0x17) {
        SdbusDebugPrint(1,"wp  %p INIT_SD_MEM error handler!",param_2,param_4);
        *(undefined4 *)(param_1 + 0x578) = 0;
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        if (((*(char *)(lVar1 + 0x16e8) == '\0') ||
            (((*(char *)(lVar1 + 0x112b) == '\0' && (*(char *)(lVar1 + 0x112c) == '\0')) &&
             (*(char *)(lVar1 + 0x112d) == '\0')))) ||
           ((cVar8 = *(char *)(*(longlong *)(lVar1 + 8) + 0x45), cVar8 != '\f' &&
            ((cVar8 != '\v' || (-1 < (char)*(undefined4 *)(lVar1 + 0x1140))))))) goto LAB_140017c05;
        goto LAB_140017bfb;
      }
      if (uVar10 == 0x18) {
        if (*(char *)(param_1 + 0x574) == '\0') {
          SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b8) = 0x21;
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,*param_2,(undefined8 *)&CmdDescGoIdleState,0,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 0x1a;
          return 0xc0000016;
        }
        SdbusDebugPrint(1,"wp  %p SD Combo card failed to initilize memory function!",param_2,
                        param_4);
        goto LAB_1400177ff;
      }
      if (uVar10 == 0x19) {
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x80))
                          (param_1 + 0x1d0,lVar1,1);
        if (-1 < (int)uVar6) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          *(undefined1 *)(lVar1 + 0x165c) = 1;
          *(undefined4 *)(param_1 + 0x1b4) = 0x18;
          return 0xc0000016;
        }
        if ((int)uVar6 == -0x3fffffea) {
          return uVar6;
        }
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 0x21;
        return 0xc0000016;
      }
      if (uVar10 == 0x1a) {
        *(undefined4 *)(param_1 + 0x570) = 0;
        SdbusDebugPrint(0x40,"wp  %p mmc OCR: volt range=0x%08x, volt prof=0x%08x",param_2,
                        (ulonglong)*(uint *)(lVar1 + 0x1690));
LAB_140017d53:
        *(undefined4 *)(param_1 + 0x1b4) = 0x1b;
        return 0xc0000016;
      }
      if (uVar10 == 0x1b) {
        SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM - send CMD1",param_2,param_4);
        uVar11 = 0x40ff8080;
        if (*(char *)(*(longlong *)(lVar1 + 8) + 0x45) != '\f') {
          uVar11 = 0x40ff8000;
        }
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescMmcSendOpCond,uVar11,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0x1c;
        return 0xc0000016;
      }
      if (uVar10 != 0x1c) {
        return 0xc0000001;
      }
      uVar10 = *(uint *)(param_1 + 0x25c);
      if ((int)uVar10 < 0) {
        *(bool *)(param_1 + 0x57d) = (uVar10 & 0x60000000) == 0x40000000;
        uVar9 = 0xff8000;
        goto LAB_140017cb7;
      }
      *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
      if (*(uint *)(param_1 + 0x570) <= SdMemCardInitTimeout) {
        SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM - retry sequence after delay",param_2,param_4);
        *(undefined4 *)(param_1 + 0x1d4) = 1000;
        goto LAB_140017d53;
      }
    }
    else {
      if (uVar10 == 0x1e) {
        uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x40))
                          (param_1 + 0x1d0,lVar1,(int)param_2[0x12]);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        uVar11 = *(undefined4 *)(lVar1 + 0x171c);
        *(undefined4 *)(lVar1 + 0x174c) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 0x1f;
        goto LAB_1400184bb;
      }
      if (uVar10 == 0x1f) {
        SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM - send CMD1 for low voltage",param_2,param_4);
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescMmcSendOpCond,0x40000080,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0x20;
        return 0xc0000016;
      }
      if (uVar10 != 0x20) {
        if (uVar10 != 0x21) {
          if (uVar10 == 0x22) {
            *(undefined4 *)(param_1 + 0x1b8) = 0x25;
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,*param_2,(undefined8 *)&CmdDescAllSendCid,0,0,0,0,0,0,0);
            *(undefined4 *)(param_1 + 0x1b4) = 0x23;
            return 0xc0000016;
          }
          if (uVar10 == 0x23) {
            uVar11 = 0xcccc0000;
            if (*(int *)(param_1 + 0x578) != 3) {
              uVar11 = 0;
            }
            *(undefined4 *)(lVar1 + 0x168c) = uVar11;
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,*param_2,(undefined8 *)&CmdDescSendRelativeAddr,uVar11,0,0,0,0,0,0);
            *(undefined4 *)(param_1 + 0x1b4) = 0x24;
            return 0xc0000016;
          }
          if (uVar10 != 0x24) {
            if (uVar10 == 0x25) {
              SdbusDebugPrint(1,"wp  %p InitializeCard ABORT!",param_2,param_4);
              return 0xc0000001;
            }
            return 0xc0000001;
          }
          if (*(int *)(param_1 + 0x578) != 3) {
            *(uint *)(lVar1 + 0x168c) = *(uint *)(param_1 + 0x25c) & 0xffff0000;
          }
          SdbusDebugPrint(0x40,"wp  %p InitializeCard COMPLETE, rca=0x%08x",param_2,
                          (ulonglong)*(uint *)(lVar1 + 0x168c));
          (**(code **)(*(longlong *)(*(longlong *)(*param_2 + 8) + 0x28) + 0x30))();
          if ((int)param_2[5] == 0xd) {
            uVar5 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar5 == 0) {
              if ((((*(int *)(lVar1 + 0x3c) != 1) &&
                   (cVar8 = *(char *)(lVar1 + 0x117a), *(char *)(param_1 + 0x574) == cVar8)) &&
                  (iVar4 = *(int *)(lVar1 + 0x117c), *(int *)(param_1 + 0x578) == iVar4)) &&
                 (*(char *)(param_1 + 0x57d) == *(char *)(lVar1 + 0x1160))) goto LAB_140018286;
              *(undefined4 *)(lVar1 + 0x3c) = 1;
              cVar8 = *(char *)(param_1 + 0x574);
              *(char *)(lVar1 + 0x117a) = cVar8;
              iVar4 = *(int *)(param_1 + 0x578);
              *(int *)(lVar1 + 0x117c) = iVar4;
              *(undefined1 *)(lVar1 + 0x1160) = *(undefined1 *)(param_1 + 0x57d);
            }
            else {
              if (((*(int *)(lVar1 + 0x3c) != 1) &&
                  (cVar8 = *(char *)(lVar1 + 0x117a), *(char *)(param_1 + 0x574) == cVar8)) &&
                 ((iVar4 = *(int *)(lVar1 + 0x117c), *(int *)(param_1 + 0x578) == iVar4 &&
                  ((*(char *)(param_1 + 0x57d) == *(char *)(lVar1 + 0x1160) &&
                   (*(char *)(param_1 + 0x57e) == *(char *)(lVar1 + 0x1161)))))))
              goto LAB_140018286;
              *(undefined4 *)(lVar1 + 0x3c) = 1;
              cVar8 = *(char *)(param_1 + 0x574);
              *(char *)(lVar1 + 0x117a) = cVar8;
              iVar4 = *(int *)(param_1 + 0x578);
              *(int *)(lVar1 + 0x117c) = iVar4;
              *(undefined1 *)(lVar1 + 0x1160) = *(undefined1 *)(param_1 + 0x57d);
              *(undefined1 *)(lVar1 + 0x1161) = *(undefined1 *)(param_1 + 0x57e);
            }
            *(undefined4 *)(lVar1 + 0x1180) = *(undefined4 *)(param_1 + 0x584);
          }
          else {
            cVar8 = *(char *)(lVar1 + 0x117a);
            if (*(char *)(param_1 + 0x574) != cVar8) {
              return 0xc0000001;
            }
            iVar4 = *(int *)(lVar1 + 0x117c);
            if (*(int *)(param_1 + 0x578) != iVar4) {
              return 0xc0000001;
            }
            if (*(int *)(param_1 + 0x584) != *(int *)(lVar1 + 0x1180)) {
              return 0xc0000001;
            }
            if ((*(int *)(param_1 + 0x578) != 3) &&
               (*(char *)(param_1 + 0x57d) != *(char *)(lVar1 + 0x1160))) {
              return 0xc0000001;
            }
          }
LAB_140018286:
          if ((*(char *)(lVar1 + 0x16e8) != '\0') && (*(char *)(lVar1 + 0x1734) != '\0')) {
            if ((cVar8 == '\0') && ((iVar4 != 3 || (*(byte *)(lVar1 + 0x1190) < 4)))) {
              *(undefined1 *)(lVar1 + 0xd4) = 0;
            }
            else {
              *(undefined1 *)(lVar1 + 0xd4) = 1;
            }
          }
          return 0;
        }
        SdbusDebugPrint(1,"wp  %p INIT_MMC_MEM error handler!",param_2,param_4);
        *(undefined4 *)(param_1 + 0x578) = 0;
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        goto LAB_140017d29;
      }
      uVar10 = *(uint *)(param_1 + 0x25c);
      if ((int)uVar10 < 0) {
        *(bool *)(param_1 + 0x57d) = (uVar10 & 0x60000000) == 0x40000000;
        uVar9 = 0xff8080;
LAB_140017cb7:
        if ((uVar10 & uVar9) != uVar9) {
          *(undefined4 *)(param_1 + 0x1b4) = 0x21;
        }
        uVar10 = *(uint *)(lVar1 + 0x1690);
        *(undefined4 *)(param_1 + 0x578) = 3;
        *(uint *)(param_1 + 0x584) = uVar10 & 0xffffff;
        SdbusDebugPrint(0x40,"wp  %p MMC card returns initialized",param_2,param_4);
LAB_140017b82:
        *(undefined4 *)(param_1 + 0x1b4) = 0x22;
        return 0xc0000016;
      }
      *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
      if (*(uint *)(param_1 + 0x570) <= SdMemCardInitTimeout) {
        SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM - retry sequence after delay",param_2,param_4);
        *(undefined4 *)(param_1 + 0x1d4) = 1000;
        *(undefined4 *)(param_1 + 0x1b4) = 0x1f;
        return 0xc0000016;
      }
    }
    SdbusDebugPrint(1,"wp  %p enumerate MMC card fails",param_2,param_4);
    *(undefined4 *)(param_1 + 0x578) = 0;
LAB_140017d29:
    *(undefined4 *)(param_1 + 0x1b4) = 0x25;
    return 0xc0000016;
  }
  if (uVar10 == 0x13) {
    uVar10 = *(uint *)(param_1 + 0x25c);
    if ((int)uVar10 < 0) {
      *(undefined4 *)(param_1 + 0x578) = 2;
      if (*(char *)(param_1 + 0x57c) != '\0') {
        if ((uVar10 >> 0x1e & 1) == 0) {
          *(undefined1 *)(param_1 + 0x57d) = 0;
          uVar5 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar5 != 0) {
            *(undefined1 *)(param_1 + 0x57e) = 0;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x57d) = 1;
          SdbusDebugPrint(0x40,"wp  %p card is High Capacity Card: %d",param_2,1);
          uVar5 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar5 != 0) && ((uVar10 >> 0x1b & 1) != 0)) {
            *(undefined1 *)(param_1 + 0x57e) = 1;
            SdbusDebugPrint(0x40,"wp  %p card is Ultra Capacity Card: %d",param_2,1);
          }
          if ((((SdDisableUhsSupport == 0) && ((*(uint *)(lVar1 + 0x48) & 0x10000000) == 0)) &&
              ((uVar10 >> 0x18 & 1) != 0)) &&
             (((*(char *)(lVar1 + 0x112a) != '\0' || (*(char *)(lVar1 + 0x1129) != '\0')) ||
              (*(char *)(lVar1 + 0x112b) != '\0')))) {
            *(undefined1 *)(lVar1 + 0x1168) = 1;
            *(undefined4 *)(param_1 + 0x1b4) = 0x14;
            return 0xc0000016;
          }
        }
        if (((*(char *)(lVar1 + 0x1168) != '\0') &&
            (*(char *)(*(longlong *)(lVar1 + 8) + 0x45) == '\x06')) ||
           ((*(char *)(*(longlong *)(lVar1 + 8) + 0x45) == '\v' &&
            (((*(char *)(lVar1 + 0x1659) != '\0' || (*(char *)(lVar1 + 0x165a) != '\0')) ||
             (*(char *)(lVar1 + 0x165b) != '\0')))))) {
LAB_140017b47:
          *(undefined4 *)(param_1 + 0x1b4) = 0x15;
          return 0xc0000016;
        }
        *(undefined1 *)(lVar1 + 0x165c) = 0;
      }
      goto LAB_140017b82;
    }
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
    if (*(uint *)(param_1 + 0x570) <= SdMemCardInitTimeout / 0x32) {
      SdbusDebugPrint(0x40,"wp  %p INIT_SD_MEM - retry after delay",param_2,param_4);
      *(undefined4 *)(param_1 + 0x1d4) = 50000;
LAB_1400176c7:
      *(undefined4 *)(param_1 + 0x1b4) = 0x12;
      return 0xc0000016;
    }
    SdbusDebugPrint(1,"wp  %p enumerate MEM card fails",param_2,param_4);
    *(undefined4 *)(param_1 + 0x578) = 0;
    if (((-1 < (char)*(undefined4 *)(lVar1 + 0x1140)) ||
        (1 < (byte)(*(char *)(*(longlong *)(lVar1 + 8) + 0x45) - 0xbU))) ||
       ((*(char *)(lVar1 + 0x112b) == '\0' &&
        ((*(char *)(lVar1 + 0x112c) == '\0' && (*(char *)(lVar1 + 0x112d) == '\0')))))) {
LAB_140017c05:
      iVar4 = 0x18;
      goto LAB_140017274;
    }
LAB_140017bfb:
    iVar4 = 0x19;
LAB_140017274:
    *(int *)(param_1 + 0x1b4) = iVar4;
    return 0xc0000016;
  }
  if (uVar10 < 10) {
    if (uVar10 == 9) {
      uVar10 = *(uint *)(param_1 + 0x25c);
      bVar7 = (byte)(uVar10 >> 0x1c) & 7;
      *(byte *)(param_1 + 0x574) = bVar7;
      if ((uVar10 >> 0x1b & 1) != 0) {
        *(undefined4 *)(param_1 + 0x578) = 2;
      }
      SdbusDebugPrint(0x40,"wp  %p CMD5 Response: #func=%d, ioOCR=%08x",param_2,(ulonglong)bVar7);
      if (*(char *)(param_1 + 0x574) == '\0') {
        *(undefined4 *)(param_1 + 0x1d0) = 0;
        *(undefined4 *)(param_1 + 0x1b4) = 0x10;
        return 0xc0000016;
      }
      *(undefined4 *)(param_1 + 0x570) = 0;
      *(uint *)(param_1 + 0x584) = uVar10 & 0xffffff;
      *(undefined4 *)(param_1 + 0x1d4) = 1000;
      *(undefined4 *)(param_1 + 0x1b4) = 10;
      return 0xc0000016;
    }
    if (uVar10 == 0) {
      SdbusDebugPrint(0x40,"wp  %p skt %p InitializeCardWorker: ICW_START",param_2,lVar1);
      *(undefined8 *)(param_1 + 0x570) = 0;
      *(undefined8 *)(param_1 + 0x578) = 0;
      *(undefined8 *)(param_1 + 0x580) = 0;
      if ((((*(uint *)(lVar1 + 0x48) & 0x80000) == 0) || ((int)param_2[5] != 0xc)) ||
         (*(char *)(lVar1 + 0x117a) == '\0')) {
        iVar4 = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x1b8) = 1;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar1,(undefined8 *)&CmdDescWriteIoDirect,0x80000c08,0,0,0,0,0,0);
        iVar4 = (-(uint)(*(int *)(lVar1 + 0x117c) != 0) & 0xfffffffe) + 4;
      }
    }
    else {
      if (uVar10 == 1) {
        SdbusDebugPrint(4,"wp  %p io card reset error handler!",param_2,param_4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 2;
        return 0xc0000016;
      }
      if (uVar10 == 2) {
        *(undefined4 *)(param_1 + 0x1b8) = 3;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescGoIdleState,0,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 4;
        return 0xc0000016;
      }
      if (uVar10 == 3) {
        SdbusDebugPrint(4,"wp  %p mem card reset error handler!",param_2,param_4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 4;
        return 0xc0000016;
      }
      if (uVar10 == 4) {
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(lVar1 + 0x1718);
        *(undefined4 *)(param_1 + 0x1b4) = 5;
        return 0xc0000016;
      }
      if (uVar10 == 5) {
        SdbusDebugPrint(0x40,"wp  %p ICW_SEND_CMD8 - send CMD8",param_2,param_4);
        *(undefined4 *)(param_1 + 0x1b8) = 7;
        *(undefined1 *)(param_1 + 0x580) = 0xaa;
        *(undefined1 *)(param_1 + 0x57c) = 0;
        if ((char)*(undefined4 *)(lVar1 + 0x1690) < '\0') {
          uVar10 = *(uint *)(param_1 + 0x580) & 0xfffff2ff | 0x200;
        }
        else {
          uVar10 = *(uint *)(param_1 + 0x580) & 0xfffff1ff | 0x100;
        }
        *(uint *)(param_1 + 0x580) = uVar10;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescSendIfCond,uVar10,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 6;
        return 0xc0000016;
      }
      if (uVar10 == 6) {
        if (((char)*(uint *)(param_1 + 0x580) == (char)*(uint *)(param_1 + 0x25c)) &&
           (((*(uint *)(param_1 + 0x580) ^ *(uint *)(param_1 + 0x25c)) & 0xf00) == 0)) {
          *(undefined1 *)(param_1 + 0x57c) = 1;
          SdbusDebugPrint(0x40,"wp  %p CMD8 succeeded. It is a 2.0 card",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b4) = 8;
          return 0xc0000016;
        }
        return 0xc00000bb;
      }
      if (uVar10 != 7) {
        if (uVar10 != 8) {
          return 0xc0000001;
        }
        if ((*(uint *)(lVar1 + 0x48) >> 8 & 1) == 0) {
          SdbusDebugPrint(0x40,"wp  %p INIT_IO - send CMD5",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b8) = 0xf;
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,*param_2,(undefined8 *)&CmdDescIoSendOpCond,0,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 9;
          return 0xc0000016;
        }
        SdbusDebugPrint(0x40,"wp  %p SDIO is disabled on this controller",param_2,param_4);
        goto LAB_140017191;
      }
      SdbusDebugPrint(4,"wp  %p ICW_CMD8_ERROR error handler!",param_2,param_4);
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      if ((*(int *)(lVar1 + 0x117c) == 2) && ((*(uint *)(param_1 + 0x580) & 0x200) != 0)) {
        *(uint *)(lVar1 + 0x1690) = *(uint *)(lVar1 + 0x1690) & 0xffffff7f;
        *(uint *)(lVar1 + 0x1140) = *(uint *)(lVar1 + 0x1140) & 0xffffff7f;
        iVar4 = 5;
      }
      else {
        iVar4 = 8;
      }
    }
    goto LAB_140017274;
  }
  if (uVar10 == 10) {
    uVar10 = *(uint *)(lVar1 + 0x1690);
    if (uVar10 == 0x80) {
      uVar10 = 0x100;
    }
    if ((SdDisableUhsSupport == 0) && ((*(uint *)(lVar1 + 0x48) & 0x10000000) == 0)) {
      uVar10 = uVar10 | 0x1000000;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar1,(undefined8 *)&CmdDescIoSendOpCond,uVar10,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 0xb;
    return 0xc0000016;
  }
  if (uVar10 != 0xb) {
    if (uVar10 == 0xc) {
      uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x78))
                        (param_1 + 0x1d0,lVar1);
      if ((int)uVar6 < 0) {
LAB_14001780e:
        if ((int)uVar6 == -0x3fffffff) {
          *(undefined4 *)(lVar1 + 0x174c) = 0;
          *(undefined4 *)(param_1 + 0x1b4) = 0xe;
          return 0xc0000016;
        }
        return uVar6;
      }
      *(undefined4 *)(lVar1 + 0x174c) = 0;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar1,(undefined8 *)&CmdDescSendVoltageSwitch,0,0,0,0,0,0,0);
      goto LAB_140017887;
    }
    if (uVar10 != 0xd) {
      if (uVar10 == 0xe) goto LAB_140017798;
      if (uVar10 != 0xf) {
        if (uVar10 == 0x10) {
          SdbusDebugPrint(0x40,"wp  %p INIT_SD_MEM",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b8) = 0x17;
          *(undefined4 *)(param_1 + 0x570) = 0;
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,lVar1,(undefined8 *)&CmdDescSendOpCond,0,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 0x11;
          return 0xc0000016;
        }
        if (uVar10 != 0x11) {
          if (uVar10 != 0x12) {
            return 0xc0000001;
          }
          SdbusDebugPrint(0x40,"wp  %p INIT_SD_MEM - start setting operation condition",param_2,
                          param_4);
          if (*(char *)(param_1 + 0x57c) == '\0') {
            uVar10 = *(uint *)(lVar1 + 0x1690);
          }
          else {
            uVar5 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
            uVar10 = (-(uint)((int)uVar5 != 0) & 0x8000000) + 0x50000000 | *(uint *)(lVar1 + 0x1690)
            ;
          }
          if ((SdDisableUhsSupport == 0) && ((*(uint *)(lVar1 + 0x48) & 0x10000000) == 0)) {
            uVar10 = uVar10 | 0x1000000;
          }
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,*param_2,(undefined8 *)&CmdDescSendOpCond,uVar10,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 0x13;
          return 0xc0000016;
        }
        *(uint *)(param_1 + 0x584) = *(uint *)(param_1 + 0x25c) & 0xffffff;
        SdbusDebugPrint(0x40,"wp  %p card returns memory OCR: ocr=0x%08x, volt prof=0x%08x",param_2,
                        (ulonglong)*(uint *)(param_1 + 0x25c));
        goto LAB_1400176c7;
      }
      SdbusDebugPrint(0x40,"wp  %p IO init FAILURE",param_2,param_4);
      *(undefined1 *)(param_1 + 0x574) = 0;
      *(undefined4 *)(param_1 + 0x578) = 0;
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      goto LAB_140017191;
    }
    uVar6 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x28) + 0x80))
                      (param_1 + 0x1d0,lVar1,1);
    if ((int)uVar6 < 0) goto LAB_14001780e;
    *(undefined4 *)(lVar1 + 0x174c) = 0;
    *(undefined1 *)(lVar1 + 0x165c) = 1;
    goto LAB_1400177ff;
  }
  uVar10 = *(uint *)(param_1 + 0x25c);
  if (-1 < (int)uVar10) {
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
    if (*(uint *)(param_1 + 0x570) <= SdIoCardInitTimeout) {
      *(undefined4 *)(param_1 + 0x1d4) = 1000;
      *(undefined4 *)(param_1 + 0x1b4) = 10;
      return 0xc0000016;
    }
    SdbusDebugPrint(0x40,"wp  %p IO init TIMEOUT",param_2,param_4);
    *(undefined1 *)(param_1 + 0x574) = 0;
    *(undefined4 *)(param_1 + 0x578) = 0;
    goto LAB_140017191;
  }
  SdbusDebugPrint(0x40,"wp  %p card returns IO_READY",param_2,param_4);
  if ((SdDisableUhsSupport != 0) || ((*(uint *)(lVar1 + 0x48) & 0x10000000) != 0)) {
    uVar10 = 0;
  }
  bVar2 = false;
  *(undefined1 *)(lVar1 + 0x165c) = 0;
  if (*(char *)(lVar1 + 0x1168) != '\0') {
    cVar8 = *(char *)(*(longlong *)(lVar1 + 8) + 0x45);
    if (cVar8 == '\x06') {
      *(undefined1 *)(lVar1 + 0x165c) = 1;
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if ((cVar8 != '\a') && (cVar8 != '\v')) goto LAB_140017936;
    }
    bVar2 = bVar3;
    cVar8 = *(char *)(*(longlong *)(lVar1 + 8) + 0x565);
    if (((cVar8 != '\0') &&
        (((*(uint *)(lVar1 + 0x1158) >> 3 & 1) != 0 && ((*(uint *)(lVar1 + 0x1158) >> 4 & 1) != 0)))
        ) || (cVar8 == '\0')) {
      bVar2 = true;
      *(undefined1 *)(lVar1 + 0x165c) = 1;
    }
  }
LAB_140017936:
  if (((uVar10 >> 0x18 & 1) != 0) &&
     (((*(char *)(lVar1 + 0x112a) != '\0' || (*(char *)(lVar1 + 0x1129) != '\0')) ||
      (*(char *)(lVar1 + 0x112b) != '\0')))) {
    *(undefined1 *)(lVar1 + 0x1168) = 1;
  }
  if (*(int *)(param_1 + 0x578) == 2) {
LAB_140017191:
    *(undefined4 *)(param_1 + 0x1b4) = 0x10;
    return 0xc0000016;
  }
  if (bVar2) {
LAB_140017887:
    *(undefined4 *)(param_1 + 0x1b4) = 0xd;
    return 0xc0000016;
  }
  if (*(char *)(lVar1 + 0x1168) != '\0') {
    *(undefined4 *)(param_1 + 0x1b4) = 0xc;
    return 0xc0000016;
  }
  *(undefined1 *)(lVar1 + 0x165c) = 0;
LAB_1400177ff:
  *(undefined4 *)(param_1 + 0x1b4) = 0x23;
  return 0xc0000016;
}



===== SdbusIntEnableWorker @ 1400184f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusIntEnableWorker(longlong param_1,longlong *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  char *pcVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar4 = param_2[1];
  lVar5 = *param_2;
  iVar2 = *(int *)(param_1 + 0x1b4);
  bVar1 = *(byte *)(lVar4 + 0xc4);
  if (iVar2 == 0) {
    SdbusDebugPrint(0x40,"wp  %p skt %p IntEnableWorker entered",param_2,lVar5);
    if (*(int *)(lVar4 + 200) - 2U < 2) {
      return 0;
    }
    if ((int)param_2[5] == 0x25) {
      *(byte *)(lVar5 + 0x1676) = *(byte *)(lVar5 + 0x1676) & 1 << (bVar1 & 0x1f) != 0;
      param_2[0xb] = (ulonglong)*(byte *)(lVar5 + 0x1676);
      return 0;
    }
    (**(code **)(*(longlong *)(*(longlong *)(lVar5 + 8) + 0x28) + 0x130))(lVar5,1);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar5,(undefined8 *)&CmdDescReadIoDirect,0x800,0,0,0,0,0,0);
    *(int *)(param_1 + 0x1b4) = 1;
    return 0xc0000016;
  }
  if (iVar2 == 1) {
    if ((int)param_2[5] == 0x26) {
      bVar6 = *(byte *)(lVar5 + 0x1676) & '\x01' << (bVar1 & 0x1f) |
              *(byte *)(param_1 + 0x25c) & ~(byte)(1 << (bVar1 & 0x1f));
    }
    else {
      bVar6 = *(byte *)(param_1 + 0x25c) & ~(byte)(1 << (bVar1 & 0x1f));
      if (((int)param_2[5] == 0x23) && ((*(uint *)(lVar4 + 0x28) & 0x10000) != 0)) {
        bVar6 = bVar6 | 1 | (byte)(1 << (bVar1 & 0x1f));
      }
    }
    *(byte *)(param_1 + 0x570) = bVar6;
    if (bVar6 == 1) {
      *(byte *)(param_1 + 0x570) = 0;
    }
    SdbusDebugPrint(0x40,
                    "wp  %p skt %p IntEnableWorker: workstat=0x%08x, cur mask=0x%08x, tar=0x%08x",
                    param_2,lVar5);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar5,(undefined8 *)&CmdDescWriteIoDirect,
               *(byte *)(param_1 + 0x570) | 0x80000800,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
    return 0xc0000016;
  }
  if (iVar2 != 2) {
    return 0xc0000001;
  }
  if ((int)param_2[5] - 0x23U < 2) {
    *(undefined1 *)(lVar5 + 0x1676) = *(undefined1 *)(param_1 + 0x570);
    SdbusDebugPrint(0x40,"wp  %p skt %p update workstat: 0x%08x",param_2,lVar5);
  }
  if ((int)param_2[5] == 0x23) {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar5 + 0x18,&local_48);
    uVar3 = *(uint *)(lVar5 + 0x20);
    if (*(char *)(lVar5 + 0x1676) == '\0') {
      *(uint *)(lVar5 + 0x20) = uVar3 & 0xffdfffff;
      SdbusDisableEvents(lVar5,0x100);
      goto LAB_14001865c;
    }
    if ((uVar3 & 0x200000) != 0) goto LAB_14001865c;
    *(uint *)(lVar5 + 0x20) = uVar3 | 0x200000;
    SdbusEnableEvents(lVar5,0x100);
    pcVar7 = "wp  %p skt %p enable card interrupt event";
  }
  else {
    if ((int)param_2[5] != 0x24) {
      return 0;
    }
    if (*(char *)(lVar5 + 0x1676) != '\0') {
      return 0;
    }
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar5 + 0x18,&local_48);
    *(uint *)(lVar5 + 0x20) = *(uint *)(lVar5 + 0x20) & 0xffdfffff;
    SdbusDisableEvents(lVar5,0x100);
    pcVar7 = "wp  %p skt %p disable card interrupt event";
  }
  SdbusDebugPrint(0x40,pcVar7,param_2,lVar5);
LAB_14001865c:
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_48);
  return 0;
}



===== SdbusMmcCheckWriteCacheWorker @ 140018840 =====

undefined8 SdbusMmcCheckWriteCacheWorker(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar1 + 0x1120) == 3) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x1b4) == 0) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar1,(undefined8 *)&CmdDescSendExtCsd,*(undefined4 *)(lVar1 + 0x168c),
                 0x200,0,param_1 + 0x310,0,1,0);
      *(undefined4 *)(param_1 + 0x1b4) = 1;
      uVar3 = 0xc0000016;
    }
    else if (*(int *)(param_1 + 0x1b4) == 1) {
      uVar2 = *(byte *)(param_1 + 0x331) & 1;
      *(ulonglong *)(param_2 + 0x58) = (ulonglong)uVar2;
      *(char *)(lVar1 + 0x16a3) = (char)uVar2;
    }
    else {
      uVar3 = 0xc0000001;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== SdbusMmcEnableWriteCacheWorker @ 1400188f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SdbusMmcEnableWriteCacheWorker(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar2 + 0x1120) != 3) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1b8) = 3;
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescSendExtCsd,*(undefined4 *)(lVar2 + 0x168c),0x200,
               0,param_1 + 0x310,0,1,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else if (iVar1 == 1) {
    iVar1 = *(int *)(param_1 + 0x409);
    *(ulonglong *)(param_2 + 0x58) = (ulonglong)(iVar1 != 0);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(char *)(*(longlong *)(param_1 + 0x10) + 0x16a3) == '\0') {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else if (iVar1 == 2) {
    *(undefined4 *)(param_1 + 0x1b8) = 3;
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,0x3210100,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 5;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 == 4) {
        return *(undefined4 *)(param_2 + 0x3c);
      }
      if (iVar1 == 5) {
        return 0;
      }
      return 0xc0000001;
    }
    *(undefined1 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x280) = 1;
    *(undefined1 *)(param_1 + 0x286) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 3;
    *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
    *(undefined4 *)(param_1 + 0x1b4) = 4;
  }
  return 0xc0000016;
}



===== SdbusMmcFlushWriteCacheWorker @ 140018a80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SdbusMmcFlushWriteCacheWorker(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 3;
  if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x1120) == 3) {
    iVar1 = *(int *)(param_1 + 0x1b4);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1b8) = 1;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*(longlong *)(param_1 + 0x10),(undefined8 *)&CmdDescMmcSwitch,0x3200100,0,0
                 ,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = uVar2;
    }
    else {
      if (iVar1 != 1) {
        if (iVar1 == 2) {
          return *(undefined4 *)(param_2 + 0x3c);
        }
        if (iVar1 == 3) {
          return 0;
        }
        return 0xc0000001;
      }
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      *(undefined4 *)(param_1 + 0x1b4) = 2;
    }
    uVar2 = 0xc0000016;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== SdbusMmcSetWriteGroupDef @ 140018b70 =====

undefined8 SdbusMmcSetWriteGroupDef(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *param_2;
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    *(undefined2 *)(lVar2 + 0x11c4) = 0;
    *(undefined1 *)(lVar2 + 0x11c6) = 0;
    *(undefined1 *)(lVar2 + 0x1698) = 0;
    if (*(int *)(lVar2 + 0x117c) != 3) {
      return 0;
    }
    if (*(char *)(lVar2 + 0x1190) != '\x04') {
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescSendExtCsd,*(undefined4 *)(lVar2 + 0x168c),0x200,
               0,param_1 + 0x310,0,1,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        *(undefined1 *)(lVar2 + 0x1698) = 1;
        return 0;
      }
      return 0xc0000001;
    }
    *(undefined1 *)(lVar2 + 0x11c4) = *(undefined1 *)(param_1 + 0x3f0);
    *(undefined1 *)(lVar2 + 0x11c5) = *(undefined1 *)(param_1 + 0x3ed);
    if (*(char *)(param_1 + 0x3f0) == '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x3ed) == '\0') {
      return 0;
    }
    *(undefined1 *)(lVar2 + 0x11c6) = 1;
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,0x3af0100,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  return 0xc0000016;
}



===== SdbusMmcSleepWorker @ 140018cb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusMmcSleepWorker(longlong param_1,longlong *param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 local_res8;
  
  lVar1 = *param_2;
  local_res8 = 0;
  iVar4 = *(int *)(param_1 + 0x1b4);
  if (iVar4 == 0) {
    SdbusDebugPrint(0x40,"wp  %p MMC Sleep Initiated",param_2,param_4);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar1,(undefined8 *)&CmdDescMmcSwitch,0x3220400,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    uVar5 = *(int *)(lVar1 + 0x11c0) * 1000;
    *(undefined4 *)(param_1 + 0x1b8) = 3;
  }
  else {
    if (iVar4 == 1) {
      *(undefined1 *)(lVar1 + 0x1662) = 0;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar1,(undefined8 *)&CmdDescDeselectCard,0,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 2;
      *(undefined4 *)(param_1 + 0x1b8) = 3;
      *(undefined1 *)(param_1 + 0x1dc) = 1;
      *(undefined4 *)(param_1 + 0x1d4) = 0x32;
      return 0xc0000016;
    }
    if (iVar4 != 2) {
      if (iVar4 == 3) {
        SdbusDebugPrint(0x40,"wp  %p MMC Sleep Failed",param_2,param_4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 5;
        return 0xc0000016;
      }
      if (iVar4 == 4) {
        *(undefined4 *)(param_1 + 0x1b4) = 5;
        lVar2 = *(longlong *)(lVar1 + 8);
        if (*(char *)(lVar2 + 0x45) == '\n') {
          *(undefined8 *)(lVar2 + 0x244) = 0;
          *(undefined4 *)(lVar2 + 0x248) = 0x17;
          lVar3 = *(longlong *)(lVar1 + 8);
          puVar6 = (undefined8 *)(lVar3 + 0x238);
          *puVar6 = 0;
          *(undefined4 *)(lVar3 + 0x240) = 0;
          iVar4 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x120),
                                   &GUID_POWER_CHANGE_P_STATE,lVar2 + 0x244,8,puVar6,0xc,&local_res8
                                  );
          param_4 = (ulonglong)*(uint *)(lVar2 + 0x248);
          SdbusAddDbgLog(lVar1,0x51435072,(ulonglong)*(uint *)(lVar2 + 0x244),param_4,0);
          if (-1 < iVar4) {
            *(undefined8 *)(param_1 + 0x1d0) = 0x80000;
            return 0xc0000016;
          }
        }
      }
      else if (iVar4 != 5) {
        return 0xc0000001;
      }
      SdbusDebugPrint(0x40,"wp  %p MMC Sleep Complete",param_2,param_4);
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar1,(undefined8 *)&CmdDescSleepAwake,*(uint *)(lVar1 + 0x168c) | 0x8000,0,0
               ,0,0,0,0);
    uVar5 = (uint)*(byte *)(param_1 + 0x3e9);
    *(undefined4 *)(param_1 + 0x1b4) = 4;
  }
  *(uint *)(param_1 + 0x1d4) = uVar5;
  return 0xc0000016;
}



===== SdbusMmcSoftResetWorker @ 140018f90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusMmcSoftResetWorker(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,*param_2,(undefined8 *)&CmdDescGoIdleState,0,0,0,0,0,0,0);
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        *(undefined4 *)(lVar2 + 0x1658) = 0;
        *(undefined1 *)(lVar2 + 0x165c) = 0;
        *(undefined2 *)(lVar2 + 0x165f) = 0;
        *(undefined1 *)(lVar2 + 0x1661) = 0;
        *(undefined4 *)(param_1 + 0x570) = 0;
        *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(lVar2 + 0x1718);
      }
      else {
        if (iVar1 == 3) {
          SdbusDebugPrint(0x40,"wp  %p INIT_MMC_MEM - send CMD1",param_2,param_4);
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,*param_2,(undefined8 *)&CmdDescMmcSendOpCond,0x40ff8000,0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = 4;
          return 0xc0000016;
        }
        if (iVar1 != 4) {
          if (iVar1 == 5) {
            *(undefined4 *)(param_1 + 0x1b8) = 8;
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,*param_2,(undefined8 *)&CmdDescAllSendCid,0,0,0,0,0,0,0);
            *(undefined4 *)(param_1 + 0x1b4) = 6;
            return 0xc0000016;
          }
          if (iVar1 == 6) {
            *(undefined4 *)(lVar2 + 0x168c) = 0xcccc0000;
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,*param_2,(undefined8 *)&CmdDescSendRelativeAddr,0xcccc0000,0,0,0,0,0,
                       0);
            *(undefined4 *)(param_1 + 0x1b4) = 7;
            return 0xc0000016;
          }
          if (iVar1 == 7) {
            SdbusDebugPrint(0x40,"wp  %p SdbusMmcSoftResetWorker COMPLETE, rca=0x%08x",param_2,
                            (ulonglong)*(uint *)(lVar2 + 0x168c));
            return 0;
          }
          if (iVar1 == 8) {
            SdbusDebugPrint(1,"wp  %p MmcSoftReset ABORT!",param_2,param_4);
          }
          return 0xc0000001;
        }
        if ((int)*(uint *)(param_1 + 0x25c) < 0) {
          if ((*(uint *)(param_1 + 0x25c) & 0xff8000) != 0xff8000) {
            *(undefined4 *)(param_1 + 0x1b4) = 0x21;
          }
          SdbusDebugPrint(0x40,"wp  %p MMC card returns initialized",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b4) = 5;
          return 0xc0000016;
        }
        *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
        if (SdMemCardInitTimeout < *(uint *)(param_1 + 0x570)) {
          SdbusDebugPrint(1,"wp  %p soft reset MMC card fails",param_2,param_4);
          *(undefined4 *)(param_1 + 0x1b4) = 8;
          return 0xc0000016;
        }
        SdbusDebugPrint(0x40,"wp  %p MSR_CMD1_LOOP_RESPONSE - retry sequence after delay",param_2,
                        param_4);
        *(undefined4 *)(param_1 + 0x1d4) = 1000;
      }
      *(undefined4 *)(param_1 + 0x1b4) = 3;
      return 0xc0000016;
    }
    SdbusDebugPrint(4,"wp  %p mem card reset error handler!",param_2,param_4);
    *(undefined1 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x280) = 1;
    *(undefined1 *)(param_1 + 0x286) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 3;
    *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
  }
  *(undefined4 *)(param_1 + 0x1b4) = 2;
  return 0xc0000016;
}



===== SdbusMmcWakeWorker @ 1400192a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusMmcWakeWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 local_res8;
  
  lVar1 = *param_2;
  local_res8 = 0;
  iVar4 = *(int *)(param_1 + 0x1b4);
  if (iVar4 == 0) {
    SdbusDebugPrint(0x40,"wp  %p MMC Wake Initiated",param_2,param_4);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    lVar2 = *(longlong *)(lVar1 + 8);
    if (*(char *)(lVar2 + 0x45) == '\n') {
      *(undefined8 *)(lVar2 + 0x244) = 0;
      *(undefined4 *)(lVar2 + 0x248) = 0x16;
      lVar3 = *(longlong *)(lVar1 + 8);
      puVar6 = (undefined8 *)(lVar3 + 0x238);
      *puVar6 = 0;
      *(undefined4 *)(lVar3 + 0x240) = 0;
      iVar4 = PoFxPowerControl(*(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x120),
                               &GUID_POWER_CHANGE_P_STATE,lVar2 + 0x244,8,puVar6,0xc,&local_res8);
      SdbusAddDbgLog(lVar1,0x51435072,(ulonglong)*(uint *)(lVar2 + 0x244),
                     (ulonglong)*(uint *)(lVar2 + 0x248),0);
      if (-1 < iVar4) {
        *(undefined8 *)(param_1 + 0x1d0) = 0x80000;
        return 0xc0000016;
      }
    }
  }
  else if (iVar4 != 1) {
    if (iVar4 != 2) {
      if (iVar4 == 3) {
        SdbusDebugPrint(0x40,"wp  %p MMC Wake Failed",param_2,param_4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 4;
        return 0xc0000016;
      }
      if (iVar4 == 4) {
        SdbusDebugPrint(0x40,"wp  %p MMC Wake Complete",param_2,param_4);
        *(undefined1 *)(lVar1 + 0x1662) = 1;
        return 0;
      }
      return 0xc0000001;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar1,(undefined8 *)&CmdDescSelectCard,*(undefined4 *)(lVar1 + 0x168c),0,0,0,
               0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 4;
    uVar5 = *(uint *)(lVar1 + 0x1728);
    goto LAB_1400194d1;
  }
  SdbusWorkerSetStateCmdExecWithFlags
            (param_1,lVar1,(undefined8 *)&CmdDescSleepAwake,*(undefined4 *)(lVar1 + 0x168c),0,0,0,0,
             0,0);
  uVar5 = (uint)*(byte *)(param_1 + 0x3e9);
  *(undefined4 *)(param_1 + 0x1b4) = 2;
  *(undefined4 *)(param_1 + 0x1b8) = 3;
LAB_1400194d1:
  *(uint *)(param_1 + 0x1d4) = uVar5;
  return 0xc0000016;
}



===== SdbusSdioResetWorker @ 140019500 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusSdioResetWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *param_2;
  if ((*(char *)(lVar2 + 0x117a) == '\0') ||
     (((lVar3 = param_2[1], lVar3 != 0 && ((*(uint *)(lVar3 + 0x44) & 0x2000) != 0)) &&
      (*(int *)(lVar3 + 0x38) == 4)))) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    SdbusDebugPrint(0x40,"wp  %p SDIO Reset Initiated",param_2,param_4);
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescWriteIoDirect,0x80000c08,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    *(undefined4 *)(param_1 + 0x1d4) = SdCommandTimeout;
  }
  else {
    if ((iVar1 != 1) && (iVar1 == 2)) {
      SdbusDebugPrint(0x40,"wp  %p SDIO Reset Complete",param_2,param_4);
      return 0;
    }
    SdbusDebugPrint(0x40,"wp  %p SDIO Reset Failed",param_2,param_4);
    *(undefined1 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x280) = 1;
    *(undefined1 *)(param_1 + 0x286) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 3;
    *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  return 0xc0000016;
}



===== SdbusSelectCardWorker @ 140019650 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusSelectCardWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  
  lVar2 = *param_2;
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    if ((int)param_2[5] == 0xe) {
      SdbusDebugPrint(0x40,"wp  %p SelectCard Entered",param_2,param_4);
      uVar4 = *(undefined4 *)(lVar2 + 0x168c);
      puVar3 = (undefined8 *)&CmdDescSelectCard;
    }
    else {
      SdbusDebugPrint(0x40,"wp  %p DeselectCard Entered",param_2,param_4);
      puVar3 = (undefined8 *)&CmdDescDeselectCard;
      uVar4 = 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags(param_1,lVar2,puVar3,uVar4,0,0,0,0,0,0);
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 != 2) {
        return 0xc0000001;
      }
      if ((*(uint *)(param_1 + 0x25c) & 0x2000000) != 0) {
        *(undefined1 *)(lVar2 + 0x1178) = 1;
      }
      SdbusDebugPrint(0x40,"wp  %p Select/Deselect Card Complete",param_2,param_4);
      return 0;
    }
    SdbusDebugPrint(0x40,"wp  %p Select/Deselect Handle Command Timeout",param_2,param_4);
    *(undefined1 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x280) = 1;
    *(undefined1 *)(param_1 + 0x286) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 3;
    *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
  }
  *(undefined4 *)(param_1 + 0x1b4) = 2;
  return 0xc0000016;
}



===== SdbusSetPowerWorker @ 1400197a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SdbusSetPowerWorker(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int local_res8 [2];
  
  lVar2 = *param_2;
  iVar5 = *(int *)(param_1 + 0x1b4);
  if (iVar5 == 0) {
    SdbusDebugPrint(0x40,"wp  %p skt %p SetPowerWorker entered",param_2,lVar2);
    if (*(char *)(lVar2 + 0xd4) == '\0') {
      *(undefined4 *)(lVar2 + 0x168c) = 0;
      *(undefined1 *)(lVar2 + 0x1688) = 0;
    }
    iVar5 = (int)param_2[5];
    if ((iVar5 == 4) || ((*(uint *)(lVar2 + 0x48) & 0x200) != 0)) {
      uVar6 = *(uint *)(lVar2 + 0x1140);
    }
    else if (iVar5 == 3) {
      uVar4 = *(uint *)(lVar2 + 0x1180);
      uVar6 = 1;
      if (((*(int *)(lVar2 + 0x1120) == 1) && ((uVar4 >> 8 & 1) != 0)) &&
         (*(int *)(lVar2 + 0x1140) == 0x80)) {
        uVar4 = uVar4 | 0x80;
      }
      uVar4 = uVar4 & *(uint *)(lVar2 + 0x1140);
      if (uVar4 == 0) {
        return -0x3fffffff;
      }
      do {
        if ((uVar4 & uVar6) != 0) break;
        uVar6 = uVar6 * 2;
      } while (uVar6 != 0);
    }
    else {
      uVar6 = 0;
    }
    *(uint *)(param_2 + 0x12) = uVar6;
    if (iVar5 - 3U < 2) {
      lVar3 = *(longlong *)(lVar2 + 8);
      if (((*(char *)(lVar3 + 0x45) == '\x06') && (*(longlong *)(lVar3 + 0x170) != 0)) &&
         ((*(int *)(lVar2 + 0x1120) != 3 &&
          ((*(char *)(lVar3 + 0x46) == '\x01' && (*(int *)(lVar2 + 0x1f8) != 0x78000600)))))) {
        *(undefined8 *)(param_1 + 0x1d0) = 0x1000000;
        lVar3 = *(longlong *)(lVar2 + 8);
        if (*(longlong *)(lVar3 + 0x170) == 0) {
          local_res8[0] = 0;
        }
        else {
          local_res8[0] = *(int *)(lVar3 + 0x16c) + -1;
        }
        iVar5 = SdbusRequestPState(lVar3,local_res8);
        if (((iVar5 + 0x80000000U & 0x80000000) == 0) && (iVar5 != -0x3fffffea)) goto LAB_140019a7f;
      }
      if ((*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\n') &&
         ((*(longlong *)(*(longlong *)(lVar2 + 8) + 0x170) != 0 && (*(int *)(lVar2 + 0x1120) != 3)))
         ) {
        *(undefined8 *)(param_1 + 0x1d0) = 0x1000000;
        local_res8[0] = 0;
        iVar5 = SdbusRequestPState(*(longlong *)(lVar2 + 8),local_res8);
        if (iVar5 < 0) {
          if (iVar5 != -0x3fffffea) {
LAB_140019a7f:
            *(undefined4 *)(param_1 + 0x1d0) = 0;
            return iVar5;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x1d0) = 0;
        }
      }
    }
    SdbusDebugPrint(0x40,"wp  %p skt %p SetPowerWorker: parameter=0x%08x",param_2,lVar2);
    *(undefined4 *)(lVar2 + 0x174c) = 0;
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else {
    if (iVar5 != 2) {
      if (iVar5 != 3) {
        return -0x3fffffff;
      }
      iVar5 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x80))
                        (param_1 + 0x1d0,lVar2,0);
      if (iVar5 == -0x3fffffea) {
        return -0x3fffffea;
      }
      *(undefined4 *)(lVar2 + 0x174c) = 0;
      *(undefined1 *)(lVar2 + 0x165c) = 0;
      return iVar5;
    }
    if (((int)param_2[5] == 4) && (*(char *)(lVar2 + 0x1699) == '\0')) {
      (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x160))(lVar2);
    }
    iVar5 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x40))
                      (param_1 + 0x1d0,lVar2,(int)param_2[0x12]);
    if (iVar5 < 0) {
      return iVar5;
    }
    *(undefined4 *)(lVar2 + 0x174c) = 0;
    SdbusDebugPrint(0x40,"wp  %p skt %p Socket now %s",param_2,lVar2);
    if ((int)param_2[5] != 5) {
      return iVar5;
    }
    if (*(char *)(lVar2 + 0x1699) != '\0') {
      (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x160))(lVar2);
    }
    if (*(char *)(lVar2 + 0x165c) == '\0') {
      return iVar5;
    }
    cVar1 = *(char *)(*(longlong *)(lVar2 + 8) + 0x45);
    if (cVar1 != '\x06') {
      if (cVar1 == '\t') {
        if (*(longlong *)(lVar2 + 0x1f8) != 0x12180000) {
          return iVar5;
        }
      }
      else if (cVar1 == '\n') {
        if ((*(longlong *)(lVar2 + 0x1f8) != 0xf98a4000) &&
           (*(char *)(*(longlong *)(lVar2 + 8) + 0x46) == '\0')) {
          return iVar5;
        }
      }
      else if (cVar1 == '\v') {
        if ((*(uint *)(lVar2 + 0x1158) >> 3 & 1) == 0) {
          return iVar5;
        }
        if ((*(uint *)(lVar2 + 0x1158) >> 4 & 1) == 0) {
          return iVar5;
        }
      }
      else if (cVar1 != '\f') {
        return iVar5;
      }
    }
    *(undefined4 *)(param_1 + 0x1b4) = 3;
  }
  return -0x3fffffea;
}



===== SdbusSocketResetWorker @ 140019b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SdbusSocketResetWorker(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x1b4);
  lVar2 = *param_2;
  if (iVar1 == 0) {
    SdbusDebugPrint(0x40,"wp  %p skt %p SocketResetWorker entered, type %d",param_2,lVar2);
    SdbusDebugPrint(0x40,"Host DeviceID %04x.%04x.%02x\n",
                    (ulonglong)*(ushort *)(*(longlong *)(lVar2 + 8) + 0x3c),
                    (ulonglong)*(ushort *)(*(longlong *)(lVar2 + 8) + 0x3e));
    *(undefined4 *)(lVar2 + 0x174c) = 0;
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        SdbusDebugPrint(0x40,"wp  %p skt %p SocketReset complete",param_2,lVar2);
        return 0;
      }
      return 0xc0000001;
    }
    uVar3 = (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x48))
                      (param_1 + 0x1d0,lVar2,(int)param_2[0x12]);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    *(undefined4 *)(lVar2 + 0x174c) = 0;
    SdbusDebugPrint(0x40,"wp  %p skt %p SocketReset complete",param_2,lVar2);
    if ((int)param_2[0x12] == 0) {
      SdbusEnableEvents(lVar2,0x107d);
    }
    (**(code **)(*(longlong *)(*(longlong *)(lVar2 + 8) + 0x28) + 0x120))(lVar2);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  return 0xc0000016;
}



===== SdbusStartFunctionWorker @ 140019c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SdbusStartFunctionWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = *param_2;
  iVar2 = *(int *)(param_1 + 0x1b4);
  lVar4 = param_2[1];
  if (iVar2 == 0) {
    (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0x38))(lVar3,lVar4);
    SdbusDebugPrint(0x40,"wp  %p skt %p StartFunctionWorker: func type=%d",param_2,lVar3);
    if (*(int *)(lVar4 + 200) - 2U < 2) {
      if (*(int *)(lVar3 + 0x117c) != 3) {
        return 0;
      }
      if (*(byte *)(lVar3 + 0x1190) < 4) {
        return 0;
      }
      if (*(int *)(lVar3 + 0x11c0) == 0) {
        return 0;
      }
      if (*(char *)(lVar3 + 0x1662) == '\0') {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar3,(undefined8 *)&CmdDescMmcSwitch,0x3220100,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        return 0xc0000016;
      }
      return 0;
    }
    if ((*(uint *)(lVar4 + 0x2c) & 1) != 0) {
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar3,(undefined8 *)&CmdDescWriteIoDirect,
               (uint)*(byte *)(lVar3 + 0x1688) | 1 << (*(byte *)(lVar4 + 0xc4) & 0x1f) & 0xffU |
               0x80000400,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x570) = 2000;
  }
  else {
    if (iVar2 == 1) {
      SdbusDebugPrint(0x40,"wp  %p skt %p SdbusStartFunctionWorker enabled power off notifications",
                      param_2,lVar3);
      *(undefined1 *)(lVar3 + 0x1662) = 1;
      return 0;
    }
    if (iVar2 == 4) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar3,(undefined8 *)&CmdDescReadIoDirect,0x600,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 5;
      return 0xc0000016;
    }
    if (iVar2 != 5) {
      if (iVar2 == 6) {
        *(byte *)(lVar3 + 0x1688) =
             *(byte *)(lVar3 + 0x1688) | (byte)(1 << (*(byte *)(lVar4 + 0xc4) & 0x1f));
        SdbusDebugPrint(0x40,"wp  %p skt %p SdbusStartFunctionWorker succeeded: enabled func=0x%08x"
                        ,param_2,lVar3);
        return 0;
      }
      return 0xc0000001;
    }
    if ((*(byte *)(param_1 + 0x25c) & (byte)(1 << (*(byte *)(lVar4 + 0xc4) & 0x1f))) != 0) {
      *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(lVar4 + 0x5e0);
      *(undefined4 *)(param_1 + 0x1b4) = 6;
      return 0xc0000016;
    }
    piVar1 = (int *)(param_1 + 0x570);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      SdbusDebugPrint(1,"skt %p IO enable TIMEOUT",lVar3,param_4);
      return 0xc0000001;
    }
    *(undefined4 *)(param_1 + 0x1d4) = 1000;
  }
  *(undefined4 *)(param_1 + 0x1b4) = 4;
  return 0xc0000016;
}



===== SdbusStopFunctionWorker @ 140019f30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SdbusStopFunctionWorker(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *param_2;
  iVar1 = *(int *)(param_1 + 0x1b4);
  lVar3 = param_2[1];
  if (iVar1 == 0) {
    if (*(int *)(lVar3 + 200) - 2U < 2) {
      if (*(int *)(lVar2 + 0x117c) != 3) {
        return 0;
      }
      if (*(byte *)(lVar2 + 0x1190) < 4) {
        return 0;
      }
      if (*(char *)(lVar2 + 0x1662) == '\0') {
        return 0;
      }
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar2,(undefined8 *)&CmdDescMmcSwitch,0x3220300,0,0,0,0,0,0);
      iVar1 = *(int *)(lVar2 + 0x11c0);
      *(undefined4 *)(param_1 + 0x1b8) = 2;
      *(int *)(param_1 + 0x1d4) = iVar1 * 1000;
      goto LAB_14001a105;
    }
    if ((*(uint *)(lVar3 + 0x2c) & 1) != 0) {
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar2,(undefined8 *)&CmdDescWriteIoDirect,
               (uint)*(byte *)(lVar2 + 0x1688) & ~(1 << (*(byte *)(lVar3 + 0xc4) & 0x1f)) |
               0x80000400,0,0,0,0,0,0);
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 != 2) {
        if (iVar1 != 5) {
          return 0xc0000001;
        }
        if (*(int *)(lVar3 + 200) - 2U < 2) {
          return 0;
        }
        *(byte *)(lVar2 + 0x1688) =
             *(byte *)(lVar2 + 0x1688) & ~(byte)(1 << (*(byte *)(lVar3 + 0xc4) & 0x1f));
        SdbusDebugPrint(0x40,"wp  %p skt %p StopFunctionWorker succeeded",param_2,lVar2);
        return 0;
      }
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
LAB_14001a105:
      *(undefined4 *)(param_1 + 0x1b4) = 1;
      return 0xc0000016;
    }
    SdbusDebugPrint(0x40,"wp  %p skt %p SdbusStartFunctionWorker sent power off notification",
                    param_2,lVar2);
    *(undefined1 *)(lVar2 + 0x1662) = 0;
    if (*(char *)(lVar2 + 0x1192) != -0x70) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x1d4) = 10000;
  }
  *(undefined4 *)(param_1 + 0x1b4) = 5;
  return 0xc0000016;
}



===== SdbusActivateSocket @ 14001a130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdbusActivateSocket(longlong param_1,uint param_2,undefined8 param_3,undefined *param_4,
                        longlong *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  param_5 = (longlong *)0x0;
  SdbusDebugPrint(0x20,"skt %p ActivateSocket START type(%d)",param_1,(ulonglong)param_2);
  plVar4 = (longlong *)ExAllocatePool2(0x40,0x40,0x63416453);
  plVar1 = (longlong *)(param_1 + 0xb18);
  if (plVar4 == (longlong *)0x0) {
    plVar4 = (longlong *)*plVar1;
    if (plVar4 == plVar1) {
      if (param_4 == (undefined *)0x0) {
        return;
      }
      (*(code *)param_4)(param_1,0,0xc000009a);
      return;
    }
    if (((longlong *)plVar4[1] == plVar1) && (lVar2 = *plVar4, *(longlong **)(lVar2 + 8) == plVar4))
    {
      *plVar1 = lVar2;
      plVar4 = plVar4 + -5;
      *(longlong **)(lVar2 + 8) = plVar1;
      goto LAB_14001a1e9;
    }
  }
  else {
    *(undefined1 *)(plVar4 + 7) = 0;
LAB_14001a1e9:
    plVar4[1] = 0;
    *(undefined4 *)((longlong)plVar4 + 0x14) = 0;
    *(undefined4 *)(plVar4 + 3) = 0;
    *(undefined4 *)((longlong)plVar4 + 0x1c) = 0;
    *plVar4 = (longlong)param_4;
    *(uint *)(plVar4 + 2) = param_2;
    plVar4[4] = param_1;
    uVar5 = SdbusBuildWorkPacket
                      (*(longlong *)(param_1 + 8) + 0x4e0,6,param_1,param_3,
                       SdbusActivateSocketComplete,plVar4,&param_5);
    if (-1 < (int)uVar5) {
      LOCK();
      *(int *)(param_1 + 0x29c0) = *(int *)(param_1 + 0x29c0) + 1;
      UNLOCK();
      KeClearEvent(param_1 + 0x1e0);
      SdbusWorkerQueuePacket(param_1 + 0x3a8,param_5,0,1);
      return;
    }
    if (param_4 != (undefined *)0x0) {
      (*(code *)param_4)(param_1,0,uVar5 & 0xffffffff);
    }
    if ((char)plVar4[7] == '\0') {
      ExFreePoolWithTag(plVar4,0x63416453);
      return;
    }
    plVar6 = *(longlong **)(param_1 + 0xb20);
    plVar4 = plVar4 + 5;
    if ((longlong *)*plVar6 == plVar1) goto LAB_14001a271;
  }
  pcVar3 = (code *)swi(0x29);
  plVar6 = (longlong *)(*pcVar3)(3);
LAB_14001a271:
  *plVar4 = (longlong)plVar1;
  plVar4[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar4;
  *(longlong **)(param_1 + 0xb20) = plVar4;
  return;
}



===== SdbusActivateSocketComplete @ 14001a2f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SdbusActivateSocketComplete(ulonglong *param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  uint uVar7;
  ulonglong *puVar8;
  char *pcVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar3 = *param_1;
  plVar4 = (longlong *)param_1[9];
  uVar10 = (ulonglong)(int)param_2;
  SdbusDebugPrint(4,"skt %p ActivateSocketComplete: status=0x%X",uVar3,(ulonglong)param_2);
  *(uint *)(plVar4 + 3) = param_2;
  if (param_1[0x11] == 0) {
    pcVar9 = (char *)0x41435449;
    uVar11 = (longlong)((int)plVar4[2] << 0x10) | 0xffff;
    SdbusAddDbgLog(*param_1,0x41435449,uVar11,uVar10,(longlong)*(int *)(uVar3 + 0x3c));
    *(int *)((longlong)plVar4 + 0x1c) = *(int *)((longlong)plVar4 + 0x1c) + 1;
    if (((int)plVar4[2] - 7U & 0xfffffff7) == 0) {
      if ((*(int *)(uVar3 + 0x113c) != 0) && (*(char *)(uVar3 + 0x112f) != '\0')) {
        KeCancelTimer(uVar3 + 0x638);
      }
      if (*(char *)(*(longlong *)(uVar3 + 8) + 0x45) != '\x06') {
        *(undefined1 *)(uVar3 + 0x1699) = 0;
      }
      *(undefined4 *)(uVar3 + 0x169c) = 0;
      *(undefined1 *)(uVar3 + 0x634) = 0;
    }
    uVar7 = *(uint *)(plVar4 + 2);
    if ((int)param_2 < 0) {
      if (uVar7 == 6) {
        uVar10 = (ulonglong)*(uint *)((longlong)plVar4 + 0x1c);
        if (*(uint *)((longlong)plVar4 + 0x1c) < *(uint *)(*param_1 + 0x1720)) {
          SdbusDebugPrint(4,
                          "skt %p ActivateSocketComplete: verify socket failed and will retry: retry=%d"
                          ,*param_1,uVar10);
          if (*(int *)(uVar3 + 0x3c) == 1) {
            memset((void *)(uVar3 + 0x1160),0,0x4f0);
          }
          LOCK();
          *(int *)(*param_1 + 0x29cc) = *(int *)(*param_1 + 0x29cc) + 1;
          UNLOCK();
          *(undefined4 *)(plVar4 + 2) = 1;
LAB_14001a4bc:
          *(undefined8 *)((longlong)plVar4 + 0x14) = 0;
          SdbusInitializeWorkPacket(param_1,6,uVar3,param_1[1],param_1[8],param_1[9]);
          SdbusWorkerQueuePacket(uVar3 + 0x3a8,(longlong *)param_1,0,2);
          return;
        }
LAB_14001a56c:
        local_res8 = (longlong *)0x0;
        SdbusDebugPrint(1,"Will attempt to power off (%x)",(ulonglong)param_2,uVar10);
        uVar12 = 0;
        uVar11 = SdbusBuildWorkPacket
                           (*(longlong *)(uVar3 + 8) + 0x4e0,5,uVar3,0,
                            SdbusActivateSocketPowerOffCompletion,0,&local_res8);
        if ((int)uVar11 < 0) {
          pcVar9 = "Failed (%x) to build power off work packet for %p";
          uVar11 = uVar11 & 0xffffffff;
          uVar10 = uVar3;
          SdbusDebugPrint(1,"Failed (%x) to build power off work packet for %p",uVar11,uVar3);
        }
        else {
          uVar10 = CONCAT71((int7)((ulonglong)uVar12 >> 8),2);
          uVar11 = 0;
          pcVar9 = (char *)local_res8;
          SdbusWorkerQueuePacket(uVar3 + 0x3a8,local_res8,0,2);
        }
      }
      else {
        if (((uVar7 - 8 < 9) && ((uVar7 - 8 & 1) == 0)) &&
           (uVar10 = (ulonglong)*(uint *)((longlong)plVar4 + 0x1c),
           *(uint *)((longlong)plVar4 + 0x1c) < *(uint *)(param_1[1] + 0x5e8))) {
          SdbusDebugPrint(4,
                          "skt %p ActivateSocketComplete: start PDO failed and will retry: retry=%d, pdo=%p, type=%d"
                          ,uVar3,uVar10);
          LOCK();
          *(int *)(uVar3 + 0x29cc) = *(int *)(uVar3 + 0x29cc) + 1;
          UNLOCK();
          *(undefined1 *)(uVar3 + 0x1699) = 0;
          goto LAB_14001a4bc;
        }
        if ((uVar7 < 0x12) && ((0x3cc80U >> (uVar7 & 0x1f) & 1) != 0)) goto LAB_14001a56c;
      }
      if ((int)plVar4[2] == 6) {
        *(undefined4 *)(uVar3 + 0x3c) = 0;
        SdbusSetSocketCardChanged(uVar3,pcVar9,uVar11,uVar10);
      }
    }
    else {
      if (uVar7 == 6) {
        *(undefined4 *)(uVar3 + 0x1650) = 0;
      }
      if ((((int)plVar4[2] - 10U & 0xfffffff9) == 0) && ((int)plVar4[2] != 0xc)) {
        uVar10 = param_1[2];
        local_38 = 0;
        local_48 = 0;
        uStack_40 = 0;
        KeAcquireInStackQueuedSpinLockAtDpcLevel(uVar10,&local_48);
        puVar1 = (uint *)(uVar10 + 8);
        *puVar1 = *puVar1 | 1;
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_48);
      }
      uVar7 = (int)plVar4[2] - 8;
      if (((uVar7 < 9) && ((uVar7 & 1) == 0)) && ((*(uint *)(param_1[1] + 0x28) & 0x80000) == 0)) {
        *(int *)(uVar3 + 0x40) = *(int *)(uVar3 + 0x40) + 1;
        *(uint *)(param_1[1] + 0x28) = *(uint *)(param_1[1] + 0x28) | 0x80000;
      }
    }
    KeSetEvent(*param_1 + 0x1e0,0,0);
    LOCK();
    piVar2 = (int *)((ulonglong)((int)param_2 >> 0x1f & 4) + 0x29c4 + *param_1);
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    if (*plVar4 == 0) {
      LOCK();
      piVar2 = (int *)(*param_1 + 0x29d8);
      *piVar2 = *piVar2 + 1;
      UNLOCK();
    }
    else {
      LOCK();
      piVar2 = (int *)(*param_1 + 0x29d4);
      *piVar2 = *piVar2 + 1;
      UNLOCK();
      (*(code *)*plVar4)(*param_1,plVar4[1],param_2);
    }
    if ((char)plVar4[7] == '\0') {
      ExFreePoolWithTag(plVar4,0x63416453);
      goto LAB_14001a6a5;
    }
    plVar13 = plVar4 + 5;
    plVar5 = *(longlong **)(uVar3 + 0xb20);
    uVar10 = uVar3;
    if (*plVar5 == uVar3 + 0xb18) {
      *plVar13 = uVar3 + 0xb18;
      plVar4[6] = (longlong)plVar5;
      *plVar5 = (longlong)plVar13;
      *(longlong **)(uVar3 + 0xb20) = plVar13;
      goto LAB_14001a6a5;
    }
  }
  else {
LAB_14001a6a5:
    if (*(char *)((longlong)param_1 + 0x82) == '\0') {
      ExFreeToLookasideListEx(*(longlong *)(uVar3 + 8) + 0x4e0,param_1);
      return;
    }
    uVar10 = uVar3 + 0xa88;
    param_1 = param_1 + 0xe;
    puVar8 = *(ulonglong **)(uVar3 + 0xa90);
    if (*puVar8 == uVar10) goto LAB_14001a6c9;
  }
  pcVar6 = (code *)swi(0x29);
  puVar8 = (ulonglong *)(*pcVar6)(3);
LAB_14001a6c9:
  *param_1 = uVar10;
  param_1[1] = (ulonglong)puVar8;
  *puVar8 = (ulonglong)param_1;
  *(ulonglong **)(uVar10 + 8) = param_1;
  return;
}



===== SdbusActivateSocketPowerOffCompletion @ 14001a720 =====

void SdbusActivateSocketPowerOffCompletion
               (longlong *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if ((int)param_2 < 0) {
    SdbusDebugPrint(1,"Failed (%x) to power off socket %p",(ulonglong)param_2,lVar1);
  }
  else {
    SdbusDebugPrint(1,"Socket %p powered off\n",lVar1,param_4);
  }
  ExFreeToLookasideListEx(*(longlong *)(lVar1 + 8) + 0x4e0,param_1);
  return;
}



===== SdbusActivateSocketWorker @ 14001a790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SdbusActivateSocketWorker(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  ulonglong uVar9;
  undefined *puVar10;
  longlong lVar11;
  char *pcVar12;
  bool bVar13;
  longlong local_res18;
  
  lVar2 = param_2[9];
  lVar3 = *param_2;
  local_res18 = 0;
  uVar1 = *(uint *)(lVar2 + 0x18);
  if ((int)uVar1 < 0) {
    SdbusDebugPrint(4,"skt %p ActivateSocketWorker error exit, status=%X",lVar3,(ulonglong)uVar1);
    return (ulonglong)uVar1;
  }
  iVar6 = *(int *)(lVar2 + 0x10);
  if ((iVar6 == 0) || (iVar6 == 1)) {
    if (*(int *)(lVar2 + 0x14) == 0) {
      SdbusAddDbgLog(lVar3,0x41435449,(longlong)(iVar6 << 0x10) | 0xaaaa,
                     (ulonglong)*(uint *)(lVar2 + 0x1c),(longlong)*(int *)(lVar3 + 0x3c));
      if (*(int *)(lVar2 + 0x10) == 0) {
        uVar7 = *(undefined4 *)(lVar3 + 0x1714);
      }
      else {
        uVar7 = *(undefined4 *)(lVar3 + 0x1710);
      }
      *(undefined4 *)(param_1 + 0x1d4) = uVar7;
      SdbusDebugPrint(4,"skt %p ActivateSocket delaying(%d) for VERIFY_CARD_STATE",*param_2,
                      (ulonglong)*(uint *)(param_2[2] + 0x1d4));
      *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + 1;
      return 0xc0000016;
    }
    cVar4 = (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0xa8))(lVar3);
    lVar11 = *param_2;
    pcVar12 = "TRUE";
    pcVar8 = "skt %p cardInSocket=%s";
    if (cVar4 == '\0') {
      pcVar12 = "FALSE";
    }
    SdbusDebugPrint(4,"skt %p cardInSocket=%s",lVar11,pcVar12);
    if (cVar4 != '\0') {
      if (*(int *)(lVar2 + 0x10) == 1) {
        *(undefined4 *)(lVar3 + 0x3c) = 1;
        SdbusSetSocketCardChanged(lVar3,pcVar8,lVar11,(ulonglong)pcVar12);
      }
      else {
        if (1 < *(uint *)(lVar3 + 0x1650)) {
          return 0;
        }
        *(uint *)(lVar3 + 0x1650) = *(uint *)(lVar3 + 0x1650) + 1;
        if (*(int *)(lVar3 + 0x3c) == 0) {
          *(undefined4 *)(lVar3 + 0x3c) = 1;
        }
      }
      uVar7 = 6;
      goto LAB_14001acef;
    }
    if (*(int *)(lVar3 + 0x3c) != 0) {
      uVar7 = *(undefined4 *)(lVar3 + 0x1684);
      *(undefined4 *)(lVar3 + 0x3c) = 0;
      SdbusSetSocketCardChanged(lVar3,pcVar8,lVar11,(ulonglong)pcVar12);
      if (((*(char *)(lVar3 + 0x1699) != '\0') &&
          (lVar11 = *(longlong *)(lVar3 + 8), *(char *)(lVar11 + 0x45) == '\x06')) &&
         (*(char *)(lVar11 + 0x46) == '\x01')) {
        iVar6 = *(int *)(lVar3 + 0x1f8);
        (**(code **)(*(longlong *)(lVar11 + 0x28) + 0x160))(lVar3);
        *(undefined1 *)(lVar3 + 0x1699) = 0;
        (&NvSdmmcTuningComplete)[iVar6 + 0x88000000U >> 9] = 0;
        SdbusCancelPStateTimer(*(longlong *)(lVar3 + 8));
      }
      if (*(char *)(lVar3 + 0x165c) == '\0') {
        memset((void *)(lVar3 + 0x1658),0,0x90);
        goto LAB_14001ace3;
      }
      memset((void *)(lVar3 + 0x1658),0,0x90);
      cVar4 = *(char *)(*(longlong *)(lVar3 + 8) + 0x45);
      if ((cVar4 == '\x06') || (cVar4 == '\t')) {
LAB_14001acd5:
        *(undefined1 *)(lVar3 + 0x165c) = 1;
      }
      else if (cVar4 == '\v') {
        if (((*(uint *)(lVar3 + 0x1158) >> 3 & 1) != 0) &&
           ((*(uint *)(lVar3 + 0x1158) >> 4 & 1) != 0)) goto LAB_14001acd5;
      }
      else if (cVar4 == '\f') goto LAB_14001acd5;
LAB_14001ace3:
      *(undefined4 *)(lVar3 + 0x1684) = uVar7;
    }
    uVar7 = 7;
LAB_14001acef:
    *(undefined4 *)(lVar2 + 0x10) = uVar7;
    *(undefined4 *)(lVar2 + 0x14) = 0;
    return 0xc0000016;
  }
  if (iVar6 == 2) {
LAB_14001a937:
    SdbusDebugPrint(4,"pdo %p ActivateSocket RequestFunctionStart, activecount=%d",param_2[1],
                    (ulonglong)*(uint *)(lVar3 + 0x40));
    SdbusAddDbgLog(*param_2,0x41435449,(longlong)(*(int *)(lVar2 + 0x10) << 0x10) | 0xaaaa,
                   (ulonglong)*(uint *)(lVar2 + 0x1c),(longlong)*(int *)(lVar3 + 0x3c));
    if ((*(uint *)(param_2[1] + 0x28) & 1) != 0) {
      return 0xc00000c0;
    }
    if ((*(char *)(lVar3 + 0xd4) == '\0') && (*(int *)(lVar2 + 0x10) == 2)) {
      *(undefined4 *)(lVar2 + 0x10) = 4;
    }
    iVar6 = *(int *)(lVar2 + 0x10);
    if (iVar6 == 4) {
      iVar5 = 0xe;
      iVar6 = 0xc;
    }
    else {
      if (iVar6 != 2) goto LAB_14001a9fb;
      if ((((*(int *)(lVar3 + 0x117c) == 3) && (3 < *(byte *)(lVar3 + 0x1190))) &&
          (*(int *)(lVar3 + 0x40) == 0)) && (*(int *)(param_2[1] + 0x20) == 1)) {
        iVar6 = 0x10;
        goto LAB_14001a906;
      }
      iVar5 = 10;
      iVar6 = 8;
    }
    if (*(int *)(lVar3 + 0x40) == 0) {
      iVar6 = iVar5;
    }
LAB_14001a9f7:
    *(int *)(lVar2 + 0x10) = iVar6;
LAB_14001a9fb:
    if ((iVar6 != 0xb) && (iVar6 != 0xf)) goto LAB_14001aa13;
  }
  else {
    if (iVar6 != 3) {
      if (iVar6 == 4) goto LAB_14001a937;
      if (iVar6 == 5) goto LAB_14001a81d;
      goto LAB_14001a9fb;
    }
LAB_14001a81d:
    SdbusDebugPrint(4,"pdo %p ActivateSocket RequestFunctionStop, activecount=%d",param_2[1],
                    (ulonglong)*(uint *)(lVar3 + 0x40));
    SdbusAddDbgLog(*param_2,0x41435449,(longlong)(*(int *)(lVar2 + 0x10) << 0x10) | 0xaaaa,
                   (ulonglong)*(uint *)(lVar2 + 0x1c),(longlong)*(int *)(lVar3 + 0x3c));
    uVar1 = *(uint *)(param_2[1] + 0x28);
    if ((uVar1 & 1) != 0) {
      *(uint *)(param_2[1] + 0x28) = uVar1 & 0xfff7ffff;
      return 0;
    }
    if ((uVar1 >> 0x13 & 1) != 0) {
      *(int *)(lVar3 + 0x40) = *(int *)(lVar3 + 0x40) + -1;
      *(uint *)(param_2[1] + 0x28) = *(uint *)(param_2[1] + 0x28) & 0xfff7ffff;
    }
    if ((*(char *)(lVar3 + 0xd4) == '\0') && (*(int *)(lVar2 + 0x10) == 3)) {
      *(undefined4 *)(lVar2 + 0x10) = 5;
    }
    iVar6 = *(int *)(lVar2 + 0x10);
    if (iVar6 == 5) {
      if (*(int *)(lVar3 + 0x40) == 0) {
        SdbusWorkerDisableIo(param_1);
        iVar6 = 0xf;
      }
      else {
        iVar6 = 0xd;
      }
      goto LAB_14001a9f7;
    }
    if (iVar6 != 3) goto LAB_14001a9fb;
    if ((*(int *)(lVar3 + 0x117c) == 3) && (3 < *(byte *)(lVar3 + 0x1190))) {
      bVar13 = false;
      if (*(int *)(lVar3 + 0x40) == 0) {
        if (*(int *)(param_2[1] + 0x20) != 1) goto LAB_14001a90f;
        SdbusWorkerDisableIo(param_1);
        iVar6 = 0x11;
        goto LAB_14001a906;
      }
    }
    else {
LAB_14001a90f:
      bVar13 = *(int *)(lVar3 + 0x40) == 0;
    }
    if (!bVar13) {
      iVar6 = 9;
LAB_14001a906:
      *(int *)(lVar2 + 0x10) = iVar6;
      goto LAB_14001aa13;
    }
    SdbusWorkerDisableIo(param_1);
    iVar6 = 0xb;
    *(undefined4 *)(lVar2 + 0x10) = 0xb;
  }
  if (*(int *)(lVar3 + 0x44) == 0) {
    return 0;
  }
LAB_14001aa13:
  iVar5 = SdbusGetNextActivateFunction(lVar2);
  if (iVar5 == 0) {
    return 0xc0000001;
  }
  SdbusAddDbgLog(*param_2,0x41435449,(ulonglong)(iVar6 << 0x10 | *(uint *)(lVar2 + 0x14)),
                 (ulonglong)*(uint *)(lVar2 + 0x1c),(longlong)*(int *)(lVar3 + 0x3c));
  *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + 1;
  pcVar8 = SdbusDbgLookupString((int *)&SdbusDbgWPFunctionStringMap,iVar5);
  SdbusDebugPrint(4,"skt %p activateSocketWorker switch to: %s",*param_2,pcVar8);
  pcVar8 = SdbusDbgLookupString((int *)&SdbusDbgSocketCardStateStringMap,*(int *)(lVar3 + 0x3c));
  SdbusDebugPrint(4,"skt %p activateSocketWorker card state: %s",*param_2,pcVar8);
  iVar6 = SdbusGetNextActivateFunction(lVar2);
  if (iVar6 != 0) {
    uVar9 = SdbusBuildWorkPacket
                      (*(longlong *)(*param_2 + 8) + 0x4e0,6,*param_2,param_2[1],
                       SdbusActivateSocketComplete,lVar2,&local_res18);
    if ((int)uVar9 < 0) {
      return uVar9;
    }
    *(int *)(local_res18 + 0x18) = (int)param_2[3];
    param_2[0x11] = local_res18;
  }
  *(int *)(param_2 + 5) = iVar5;
  puVar10 = SdbusGetMiniprocRoutine(iVar5);
  param_2[6] = (longlong)puVar10;
  return 0xc0000016;
}



===== SdbusGetNextActivateFunction @ 14001ad1c =====

undefined4 SdbusGetNextActivateFunction(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
  bool bVar7;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (0xd < iVar1) {
    if (iVar1 == 0xe) {
      lVar2 = *(longlong *)(param_1 + 0x20);
      if (*(int *)(lVar2 + 0x1120) != 3) {
        puVar5 = &DAT_140026d38;
        goto LAB_14001af6a;
      }
      if (*(char *)(lVar2 + 0x165e) != '\0') {
        puVar5 = &DAT_14002a580;
        goto LAB_14001af6a;
      }
      bVar7 = *(char *)(lVar2 + 0x165d) == '\0';
      puVar5 = &DAT_140026da0;
      puVar6 = &DAT_140026d68;
    }
    else {
      if (iVar1 == 0xf) {
        puVar5 = &DAT_140026d18;
        goto LAB_14001af6a;
      }
      if (iVar1 == 0x10) {
        cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
        if (cVar3 == '\b') {
          puVar5 = &DAT_140026c98;
          goto LAB_14001af6a;
        }
        if (cVar3 == '\t') {
          puVar5 = &DAT_140026c88;
          goto LAB_14001af6a;
        }
        uVar4 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0x48) & 0x100000;
        if (cVar3 == '\x05') {
          puVar6 = &DAT_140026c68;
          puVar5 = &DAT_140026c78;
        }
        else {
          puVar5 = &DAT_140026c50;
          puVar6 = &DAT_140026c40;
        }
      }
      else {
        if (iVar1 != 0x11) {
          if (iVar1 == 0x12) {
            puVar5 = &DAT_140026bd8;
          }
          else {
            if (iVar1 != 0x13) {
              return 0;
            }
            puVar5 = &DAT_140026bc8;
          }
          goto LAB_14001af6a;
        }
        cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
        if (cVar3 == '\b') {
          puVar5 = &DAT_140026c38;
          goto LAB_14001af6a;
        }
        if (cVar3 == '\t') {
          puVar5 = &DAT_140026c30;
          goto LAB_14001af6a;
        }
        uVar4 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0x48) & 0x100000;
        if (cVar3 == '\x05') {
          puVar6 = &DAT_140026c10;
          puVar5 = &DAT_140026c20;
        }
        else {
          puVar5 = &DAT_140026c00;
          puVar6 = &DAT_140026bf8;
        }
      }
      bVar7 = uVar4 == 0;
    }
    if (bVar7) {
      puVar5 = puVar6;
    }
    goto LAB_14001af6a;
  }
  if (iVar1 == 0xd) {
    puVar5 = &DAT_140026dd8;
    goto LAB_14001af6a;
  }
  if (iVar1 == 6) {
    puVar5 = &DAT_140026e10;
    goto LAB_14001af6a;
  }
  if (iVar1 == 7) {
    puVar5 = &DAT_140026df8;
    goto LAB_14001af6a;
  }
  if (iVar1 == 8) {
    puVar6 = &DAT_140026d08;
    cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
    puVar5 = &DAT_140026d10;
LAB_14001adff:
    bVar7 = cVar3 == '\x05';
  }
  else {
    if (iVar1 == 9) {
      puVar6 = &DAT_140026cf8;
      cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
      puVar5 = &DAT_140026d00;
      goto LAB_14001adff;
    }
    if (iVar1 == 10) {
      cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
      if (cVar3 == '\x05') {
        puVar5 = &DAT_140026ce0;
        goto LAB_14001af6a;
      }
      puVar6 = &DAT_140026cc0;
    }
    else {
      if (iVar1 != 0xb) {
        if (iVar1 != 0xc) {
          return 0;
        }
        puVar5 = &DAT_140026de8;
        goto LAB_14001af6a;
      }
      cVar3 = *(char *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 8) + 0x45);
      if (cVar3 == '\x05') {
        puVar5 = &DAT_140026cb0;
        goto LAB_14001af6a;
      }
      puVar6 = &DAT_140026ca0;
    }
    puVar5 = &DAT_140026cd0;
    bVar7 = cVar3 == '\t';
  }
  if (!bVar7) {
    puVar5 = puVar6;
  }
LAB_14001af6a:
  return *(undefined4 *)(puVar5 + (ulonglong)*(uint *)(param_1 + 0x14) * 4);
}



===== SdbusSetSocketCardChanged @ 14001af80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SdbusSetSocketCardChanged
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined8 local_res8;
  
  local_res8 = 0;
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(longlong *)(param_1 + 0x1960) != 0) {
    SdbusTelemetryIOErrorBatched
              (_DAT_fffff78000000008 - *(longlong *)(param_1 + 0x1968),
               *(longlong *)(param_1 + 0x1960),param_1 + 0x1160,param_4);
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  while (lVar4 != 0) {
    uVar2 = *(ulonglong *)(lVar4 + 0x40);
    *(uint *)(uVar2 + 0x28) = *(uint *)(uVar2 + 0x28) | 1;
    uVar3 = KeQueryInterruptTimePrecise(&local_res8);
    SdbusAddDbgLog(param_1,0x49445220,(longlong)*(int *)(param_1 + 0x3c),uVar2,uVar3);
    uVar3 = KeQueryInterruptTimePrecise(&local_res8);
    param_4 = uVar2;
    SdbusAddFxDbgLog(lVar1,0x49445220,(longlong)*(int *)(param_1 + 0x3c),uVar2,uVar3);
    lVar4 = *(longlong *)(uVar2 + 0x18);
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  uVar5 = 0x4f0;
  memset((void *)(param_1 + 0x1160),0,0x4f0);
  *(undefined8 *)(param_1 + 0x1950) = 0;
  *(undefined8 *)(param_1 + 0x1958) = 0;
  *(undefined8 *)(param_1 + 0x1960) = 0;
  *(undefined8 *)(param_1 + 0x1968) = 0;
  *(undefined8 *)(param_1 + 0x1970) = 0;
  *(undefined1 *)(param_1 + 0x1970) = 1;
  LOCK();
  *(int *)(param_1 + 0x29d0) = *(int *)(param_1 + 0x29d0) + 1;
  UNLOCK();
  if (*(char *)(*(longlong *)(param_1 + 8) + 0x45) == '\n') {
    *(undefined1 *)(param_1 + 0x1699) = 0;
  }
  LOCK();
  bVar6 = *(int *)(lVar1 + 0x390) == 0;
  if (bVar6) {
    *(int *)(lVar1 + 0x390) = 1;
  }
  UNLOCK();
  if (bVar6) {
    SdbusFxComponentActive(lVar1,0,uVar5,param_4);
  }
  IoInvalidateDeviceRelations(*(undefined8 *)(lVar1 + 0x10),0);
  return;
}



===== SdbusDetectBusWidthWorker @ 14001b0e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
SdbusDetectBusWidthWorker(longlong param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  lVar3 = *param_2;
  uVar2 = *(uint *)(param_2[2] + 0x1b4);
  if (uVar2 < 8) {
    if (uVar2 == 7) {
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      *(undefined4 *)(param_1 + 0x1b4) = 8;
      return 0xc0000016;
    }
    if (uVar2 == 0) {
      if (*(int *)(lVar3 + 0x3c) != 1) {
        return 0;
      }
      *(undefined1 *)(lVar3 + 0x1176) = 0;
      if (*(char *)(lVar3 + 0x1178) == '\0') {
        if (*(char *)(lVar3 + 0x117a) != '\0') {
          *(bool *)(lVar3 + 0x1176) = (*(byte *)(lVar3 + 0x11c9) & 0xc0) != 0x40;
          SdbusDebugPrint(0x80,"wp  %p SdbusDetectBusWidthWorker: sdio card caps %x",param_2,
                          (ulonglong)*(byte *)(lVar3 + 0x11c9));
          goto LAB_14001b36c;
        }
        if (*(int *)(lVar3 + 0x117c) != 3) {
          if ((*(int *)(lVar3 + 0x117c) != 2) || (*(char *)(lVar3 + 0x1168) == '\0')) {
            *(undefined4 *)(param_1 + 0x1b8) = 0xc;
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,lVar3,(undefined8 *)&CmdDescSendScr,*(undefined4 *)(lVar3 + 0x168c),8
                       ,0,param_1 + 0x570,0,1,0);
            *(undefined4 *)(param_1 + 0x1b4) = 0xb;
            return 0xc0000016;
          }
          *(undefined1 *)(lVar3 + 0x1190) = 2;
          *(undefined1 *)(lVar3 + 0x1176) = 1;
          goto LAB_14001b36c;
        }
        if (3 < *(byte *)(lVar3 + 0x1190)) {
          *(undefined1 *)(lVar3 + 0x1176) = 1;
          if ((*(uint *)(lVar3 + 0x48) & 0x8000) != 0) {
            SdbusDebugPrint(0x80,"wp  %p hackflag disables 8-bit bus!",param_2,param_4);
            *(undefined2 *)(lVar3 + 0x1176) = 1;
            return 0xc0000016;
          }
          *(undefined1 *)(lVar3 + 0x1177) = 1;
          *(undefined8 *)(param_1 + 0x570) = 0xaa55;
          *(undefined4 *)(param_1 + 0x578) = 0x5a;
          if ((*(char *)(lVar3 + 0x1177) == '\0') || (*(char *)(lVar3 + 0x1128) == '\0')) {
            (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0x60))(lVar3);
            uVar5 = 6;
          }
          else {
            (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0x60))(lVar3,8);
            uVar5 = 1;
          }
          *(undefined4 *)(param_1 + 0x1b4) = uVar5;
          uVar5 = 0xd;
          cVar1 = *(char *)(*(longlong *)(lVar3 + 8) + 0x45);
          if (((byte)(cVar1 - 8U) < 3) || (cVar1 == '\x06')) {
            *(undefined2 *)(lVar3 + 0x1176) = 0x101;
            *(undefined4 *)(param_1 + 0x1b4) = 0xd;
          }
          if (*(char *)(*(longlong *)(lVar3 + 8) + 0x45) != '\x05') {
            return 0xc0000016;
          }
          if (*(longlong *)(lVar3 + 0x1f8) != 0x480b4000) {
            return 0xc0000016;
          }
          *(undefined2 *)(lVar3 + 0x1176) = 0x101;
          goto LAB_14001b23d;
        }
        pcVar6 = "wp  %p SdbusDetectBusWidthWorker: non-MMC 4.x memory card";
      }
      else {
        pcVar6 = "wp  %p SdbusDetectBusWidthWorker: card is locked, unable to read SCR";
      }
      SdbusDebugPrint(0x80,pcVar6,param_2,param_4);
LAB_14001b36c:
      *(undefined4 *)(param_1 + 0x1b4) = 0xd;
      return 0xc0000016;
    }
    if (uVar2 == 1) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar3,(undefined8 *)&CmdDescBusTestWrite,*(undefined4 *)(lVar3 + 0x168c),8,
                 0,param_1 + 0x570,0,1,0);
      *(undefined4 *)(param_1 + 0x1b4) = 3;
      *(undefined4 *)(param_1 + 0x1b8) = 2;
      return 0xc0000016;
    }
    if (uVar2 == 2) {
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      *(undefined4 *)(param_1 + 0x1b4) = 3;
      return 0xc0000016;
    }
    if (uVar2 == 3) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar3,(undefined8 *)&CmdDescBusTestRead,*(undefined4 *)(lVar3 + 0x168c),8,0
                 ,param_1 + 0x570,0,1,0);
      *(undefined4 *)(param_1 + 0x1b4) = 4;
      *(undefined4 *)(param_1 + 0x1b8) = 5;
      return 0xc0000016;
    }
    if (uVar2 != 4) {
      if (uVar2 == 5) {
        SdbusDebugPrint(1,"wp  %p SdbusDetectBusWidthWorker: BUSTEST 8 Error!",param_2,param_4);
        *(undefined1 *)(lVar3 + 0x1177) = 0;
        (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0x60))(lVar3,4);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 0;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 6;
        return 0xc0000016;
      }
      if (uVar2 == 6) {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar3,(undefined8 *)&CmdDescBusTestWrite,*(undefined4 *)(lVar3 + 0x168c),
                   4,0,param_1 + 0x578,0,1,0);
        *(undefined4 *)(param_1 + 0x1b4) = 8;
        *(undefined4 *)(param_1 + 0x1b8) = 7;
        return 0xc0000016;
      }
      return 0xc0000001;
    }
    if ((short)*(undefined4 *)(param_1 + 0x570) != 0x55aa) {
      uVar5 = 5;
      goto LAB_14001b23d;
    }
    *(undefined2 *)(lVar3 + 0x1176) = 0x101;
  }
  else {
    if (uVar2 == 8) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar3,(undefined8 *)&CmdDescBusTestRead,*(undefined4 *)(lVar3 + 0x168c),4,0
                 ,param_1 + 0x578,0,1,0);
      *(undefined4 *)(param_1 + 0x1b4) = 9;
      *(undefined4 *)(param_1 + 0x1b8) = 10;
      return 0xc0000016;
    }
    if (uVar2 != 9) {
      if (uVar2 == 10) {
        SdbusDebugPrint(1,"wp  %p SdbusDetectBusWidthWorker: BUSTEST 4 Error!",param_2,param_4);
        *(undefined2 *)(lVar3 + 0x1176) = 0;
        (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0x60))(lVar3,1);
      }
      else {
        if (uVar2 == 0xb) {
          *(byte *)(lVar3 + 0x1190) = *(byte *)(param_1 + 0x570) & 0xf;
          *(byte *)(lVar3 + 0x1176) = *(byte *)(param_1 + 0x571) >> 2 & 1;
          *(byte *)(lVar3 + 0x11bc) = *(byte *)(param_1 + 0x573) >> 1 & 1;
          *(byte *)(lVar3 + 0x1191) = *(byte *)(param_1 + 0x572) >> 7;
          goto LAB_14001b36c;
        }
        if (uVar2 != 0xc) {
          if (uVar2 != 0xd) {
            return 0xc0000001;
          }
          *(undefined1 *)(lVar3 + 0x165f) = *(undefined1 *)(lVar3 + 0x1176);
          uVar4 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
          if (*(int *)(lVar3 + 0x117c) == 3) {
            if ((int)uVar4 == 0) {
              if (*(byte *)(lVar3 + 0x1190) < 4) goto LAB_14001b609;
            }
            else if ((*(byte *)(lVar3 + 0x1190) < 4) || (*(char *)(lVar3 + 0x1161) != '\0'))
            goto LAB_14001b609;
            *(undefined1 *)(lVar3 + 0x11bc) = 1;
          }
LAB_14001b609:
          SdbusDebugPrint(0x80,"wp  %p SD spec version=%d, support wide bus=%d, enable wide bus=%d",
                          param_2,(ulonglong)*(byte *)(lVar3 + 0x1190));
          return 0;
        }
        SdbusDebugPrint(1,"wp  %p SdbusDetectBusWidthWorker: Read SCR Error!",param_2,param_4);
        *(undefined2 *)(lVar3 + 0x1176) = 0;
      }
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 0;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      goto LAB_14001b36c;
    }
    if ((char)*(undefined4 *)(param_1 + 0x578) != -0x5b) {
      uVar5 = 10;
      goto LAB_14001b23d;
    }
    *(undefined2 *)(lVar3 + 0x1176) = 1;
  }
  uVar5 = 0xd;
LAB_14001b23d:
  *(undefined4 *)(param_1 + 0x1b4) = uVar5;
  return 0xc0000016;
}



===== SdbusDetectFrequencyWorker @ 14001b7b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SdbusDetectFrequencyWorker(longlong param_1,longlong *param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  
  lVar2 = *param_2;
  iVar6 = *(int *)(param_2[2] + 0x1b4);
  if (iVar6 != 0) {
    if (iVar6 != 1) {
      if (iVar6 != 2) {
        return 0xc0000001;
      }
      SdbusDebugPrint(1,"wp  %p Read CSD Error!",param_2,1);
      if ((char)*(undefined4 *)(lVar2 + 0x48) < '\0') {
        *(uint *)(lVar2 + 0x1678) = *(uint *)(lVar2 + 0x1188);
      }
      else {
        *(undefined1 *)(lVar2 + 0x1658) = 0;
      }
      SdbusDebugPrint(0x80,"wp  %p cur fre=%d",param_2,(ulonglong)*(uint *)(lVar2 + 0x1678));
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
      *(undefined4 *)(param_1 + 0x1b4) = 3;
      return 0xc0000016;
    }
    iVar6 = *(int *)(lVar2 + 0x117c);
    uVar3 = SdbusClockRateCodeToValue((byte)((uint)*(undefined4 *)(param_1 + 0x264) >> 0x18));
    puVar1 = (uint *)(lVar2 + 0x1188);
    if (iVar6 == 2) {
      *puVar1 = uVar3;
      if (*(char *)(lVar2 + 0x165b) != '\0') {
        *puVar1 = uVar3 >> 1;
      }
LAB_14001b8f1:
      uVar3 = *puVar1;
    }
    else {
      if (*(byte *)(lVar2 + 0x1190) < 4) {
        *puVar1 = uVar3;
      }
      else {
        *(uint *)(lVar2 + 0x1184) = uVar3;
      }
      if (((iVar6 != 3) || (*(char *)(lVar2 + 0x165d) != '\0')) ||
         (uVar3 = 50000, *(char *)(lVar2 + 0x165e) != '\0')) goto LAB_14001b8f1;
    }
    *(uint *)(lVar2 + 0x1678) = uVar3;
    pcVar5 = "wp  %p max high freq=%d, cur fre=%d";
    uVar3 = *puVar1;
    goto LAB_14001ba0b;
  }
  if (*(int *)(lVar2 + 0x3c) != 1) {
    return 0;
  }
  if (*(char *)(lVar2 + 0x117a) == '\0') {
    uVar3 = SdbusClockRateCodeToValue(*(byte *)(lVar2 + 0x11ba));
    uVar8 = (ulonglong)uVar3;
    if (25000 < uVar3) {
      uVar8 = 25000;
    }
    *(int *)(lVar2 + 0x1184) = (int)uVar8;
    if (*(int *)(lVar2 + 0x117c) == 3) {
      if ((*(char *)(lVar2 + 0x1167) != '\0') && (*(char *)(lVar2 + 0x112d) != '\0')) {
        *(undefined4 *)(lVar2 + 0x1188) = 200000;
        if (*(char *)(*(longlong *)(lVar2 + 8) + 0x45) == '\n') {
          *(undefined4 *)(lVar2 + 0x1188) = 400000;
        }
        goto LAB_14001badd;
      }
      if ((*(char *)(lVar2 + 0x1166) != '\0') && (*(char *)(lVar2 + 0x112c) != '\0')) {
        *(undefined4 *)(lVar2 + 0x1188) = 200000;
        goto LAB_14001badd;
      }
    }
    else {
      if ((*(char *)(lVar2 + 0x1163) != '\0') && (*(char *)(lVar2 + 0x112a) != '\0')) {
        *(undefined4 *)(lVar2 + 0x1188) = 0x32c80;
        goto LAB_14001badd;
      }
      if ((*(char *)(lVar2 + 0x1164) != '\0') && (*(char *)(lVar2 + 0x1129) != '\0')) {
        *(undefined4 *)(lVar2 + 0x1188) = 100000;
        goto LAB_14001badd;
      }
    }
    *(undefined4 *)(lVar2 + 0x1188) = 50000;
LAB_14001badd:
    *(int *)(lVar2 + 0x1678) = (int)uVar8;
    SdbusDebugPrint(0x80,"wp  %p max norm freq=%d",param_2,uVar8);
    if ((((*(char *)(lVar2 + 0x165e) == '\0') && (*(char *)(lVar2 + 0x165d) == '\0')) &&
        (*(char *)(lVar2 + 0x1658) == '\0')) &&
       (((*(char *)(lVar2 + 0x1659) == '\0' && (*(char *)(lVar2 + 0x165a) == '\0')) &&
        (*(char *)(lVar2 + 0x165b) == '\0')))) {
      SdbusDebugPrint(0x80,"wp  %p high speed and UHS are not enabled. max high freq=%d",param_2,
                      (ulonglong)*(uint *)(lVar2 + 0x1188));
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,*param_2,(undefined8 *)&CmdDescSendCsd,*(undefined4 *)(lVar2 + 0x168c),0,0,0,
               0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    return 0xc0000016;
  }
  if (*(byte *)(lVar2 + 0x11ca) == 0) {
    uVar3 = 50000;
LAB_14001b94b:
    uVar4 = uVar3;
  }
  else {
    uVar3 = SdbusClockRateCodeToValue(*(byte *)(lVar2 + 0x11ca));
    if (uVar3 < 0xc351) goto LAB_14001b94b;
    uVar4 = 50000;
  }
  *(uint *)(lVar2 + 0x1188) = uVar4;
  uVar7 = uVar3;
  if (25000 < uVar3) {
    uVar7 = 25000;
  }
  *(uint *)(lVar2 + 0x1184) = uVar7;
  if ((*(byte *)(lVar2 + 0x11c9) & 0x40) != 0) {
    uVar7 = uVar3;
    if (400 < uVar3) {
      uVar7 = 400;
    }
    *(uint *)(lVar2 + 0x1184) = uVar7;
  }
  if (*(char *)(lVar2 + 0x1659) == '\0') {
    if (*(char *)(lVar2 + 0x165a) == '\0') {
      if ((*(char *)(lVar2 + 0x165b) != '\0') || (*(char *)(lVar2 + 0x1658) != '\0')) {
        *(undefined4 *)(lVar2 + 0x1188) = 50000;
        uVar4 = 50000;
      }
    }
    else {
      uVar4 = 100000;
      *(undefined4 *)(lVar2 + 0x1188) = 100000;
    }
    if (((*(char *)(lVar2 + 0x165a) != '\0') || (*(char *)(lVar2 + 0x165b) != '\0')) ||
       (*(char *)(lVar2 + 0x1658) != '\0')) goto LAB_14001b9e9;
  }
  else {
    uVar4 = 0x32c80;
    *(undefined4 *)(lVar2 + 0x1188) = 0x32c80;
LAB_14001b9e9:
    uVar7 = uVar4;
  }
  *(uint *)(lVar2 + 0x1678) = uVar7;
  pcVar5 = "wp  %p sdio card: max norm freq=%d, max high freq=%d";
  uVar3 = *(uint *)(lVar2 + 0x1184);
LAB_14001ba0b:
  SdbusDebugPrint(0x80,pcVar5,param_2,(ulonglong)uVar3);
  return 0;
}



===== SdbusGetSocketCardDataWorker @ 14001bbb0 =====

undefined8 SdbusGetSocketCardDataWorker(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  
  lVar1 = *param_2;
  if ((int)param_2[5] == 8) {
    if (*(int *)(lVar1 + 0x3c) != 1) {
      param_2[0xb] = 0;
      return 0;
    }
    *(undefined4 *)(lVar1 + 0x3c) = 2;
  }
  else if ((param_2[1] != 0) && ((*(uint *)(param_2[1] + 0x28) & 1) != 0)) {
    return 0xc00000c0;
  }
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x4f0,0x61436453);
  if (puVar5 == (undefined8 *)0x0) {
    param_2[0xb] = 0;
    return 0xc000009a;
  }
  lVar8 = 9;
  puVar3 = puVar5;
  puVar4 = (undefined8 *)(lVar1 + 0x1160);
  do {
    puVar7 = puVar4;
    puVar6 = puVar3;
    uVar2 = puVar7[1];
    *puVar6 = *puVar7;
    puVar6[1] = uVar2;
    uVar2 = puVar7[3];
    puVar6[2] = puVar7[2];
    puVar6[3] = uVar2;
    uVar2 = puVar7[5];
    puVar6[4] = puVar7[4];
    puVar6[5] = uVar2;
    uVar2 = puVar7[7];
    puVar6[6] = puVar7[6];
    puVar6[7] = uVar2;
    uVar2 = puVar7[9];
    puVar6[8] = puVar7[8];
    puVar6[9] = uVar2;
    uVar2 = puVar7[0xb];
    puVar6[10] = puVar7[10];
    puVar6[0xb] = uVar2;
    uVar2 = puVar7[0xd];
    puVar6[0xc] = puVar7[0xc];
    puVar6[0xd] = uVar2;
    uVar2 = puVar7[0xf];
    puVar6[0xe] = puVar7[0xe];
    puVar6[0xf] = uVar2;
    lVar8 = lVar8 + -1;
    puVar3 = puVar6 + 0x10;
    puVar4 = puVar7 + 0x10;
  } while (lVar8 != 0);
  uVar2 = puVar7[0x11];
  puVar6[0x10] = puVar7[0x10];
  puVar6[0x11] = uVar2;
  uVar2 = puVar7[0x13];
  puVar6[0x12] = puVar7[0x12];
  puVar6[0x13] = uVar2;
  uVar2 = puVar7[0x15];
  puVar6[0x14] = puVar7[0x14];
  puVar6[0x15] = uVar2;
  uVar2 = puVar7[0x17];
  puVar6[0x16] = puVar7[0x16];
  puVar6[0x17] = uVar2;
  uVar2 = puVar7[0x19];
  puVar6[0x18] = puVar7[0x18];
  puVar6[0x19] = uVar2;
  uVar2 = puVar7[0x1b];
  puVar6[0x1a] = puVar7[0x1a];
  puVar6[0x1b] = uVar2;
  uVar2 = puVar7[0x1d];
  puVar6[0x1c] = puVar7[0x1c];
  puVar6[0x1d] = uVar2;
  param_2[0xb] = (longlong)puVar5;
  return 0;
}



===== SdbusIsCardEqual @ 14001bce0 =====

ulonglong SdbusIsCardEqual(longlong param_1,longlong param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  undefined3 uVar4;
  ulonglong in_RAX;
  ulonglong uVar5;
  bool bVar6;
  
  if (param_1 == param_2) {
LAB_14001bd73:
    uVar5 = CONCAT71((int7)(in_RAX >> 8),1);
  }
  else {
    if ((param_1 != 0) && (param_2 != 0)) {
      uVar3 = *(uint *)(param_2 + 0x1c);
      in_RAX = (ulonglong)uVar3;
      if (*(uint *)(param_1 + 0x1c) == uVar3) {
        cVar1 = *(char *)(param_1 + 0x1a);
        uVar4 = (undefined3)(uVar3 >> 8);
        in_RAX = (ulonglong)CONCAT31(uVar4,cVar1);
        if (cVar1 == *(char *)(param_2 + 0x1a)) {
          if (cVar1 == '\0') {
            in_RAX = (ulonglong)CONCAT31(uVar4,*(char *)(param_2 + 0x32));
            if (*(char *)(param_1 + 0x32) == *(char *)(param_2 + 0x32)) {
              uVar2 = *(ushort *)(param_2 + 0x34);
              in_RAX = (ulonglong)uVar2;
              if ((*(ushort *)(param_1 + 0x34) == uVar2) &&
                 (in_RAX = (ulonglong)CONCAT11((char)(uVar2 >> 8),*(char *)(param_2 + 0x36)),
                 *(char *)(param_1 + 0x36) == *(char *)(param_2 + 0x36))) {
                uVar3 = *(uint *)(param_2 + 0x44);
                bVar6 = *(uint *)(param_1 + 0x44) == uVar3;
LAB_14001bd6d:
                in_RAX = (ulonglong)uVar3;
                if (bVar6) goto LAB_14001bd73;
              }
            }
          }
          else {
            in_RAX = (ulonglong)*(ushort *)(param_2 + 0x6e);
            if (*(ushort *)(param_1 + 0x6e) == *(ushort *)(param_2 + 0x6e)) {
              in_RAX = RtlCompareMemory(param_1 + 0x79,param_2 + 0x79,0x40);
              if ((in_RAX == 0x40) &&
                 (in_RAX = 0, *(char *)(param_1 + 0x6c) == *(char *)(param_2 + 0x6c))) {
                uVar3 = *(uint *)(param_2 + 0x74);
                bVar6 = *(uint *)(param_1 + 0x74) == uVar3;
                goto LAB_14001bd6d;
              }
            }
          }
        }
      }
    }
    uVar5 = in_RAX & 0xffffffffffffff00;
  }
  return uVar5;
}



===== SdbusProcessTupleChain @ 14001bd88 =====

ulonglong SdbusProcessTupleChain(longlong param_1,longlong *param_2)

{
  uint *puVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  
  cVar2 = *(char *)(param_1 + 0x574);
  lVar5 = *param_2;
  puVar1 = (uint *)(lVar5 + 0x1018);
  if (cVar2 == '\0') {
    uVar9 = *puVar1;
    *puVar1 = uVar9 + 1;
    if ((uVar9 & 0x1ffff) - 0x1000 < 0x17000) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar5,(undefined8 *)&CmdDescReadIoDirect,(uVar9 & 0x1ffff) << 9,0,0,0,0,0,0
                );
      *(undefined1 *)(param_1 + 0x574) = 1;
      return 0xc0000016;
    }
LAB_14001bfd9:
    uVar7 = 1;
LAB_14001bfe1:
    SdbusDebugPrint(uVar7,"wp  %p INVALID cisPtr=%.06x",param_2,(ulonglong)uVar9);
  }
  else {
    if (cVar2 == '\x01') {
      bVar4 = *(byte *)(param_1 + 0x25c);
      *(byte *)(lVar5 + 0x101c) = bVar4;
      if ((bVar4 == 0xff) || (bVar4 == 0)) {
        SdbusDebugPrint(0x80,"CIS %.06x code=%.02x - END OF CHAIN",(ulonglong)(*puVar1 - 1),
                        (ulonglong)bVar4);
        uVar8 = 0;
        goto LAB_14001bff5;
      }
      uVar9 = *puVar1;
      *puVar1 = uVar9 + 1;
      if ((uVar9 & 0x1ffff) - 0x1000 < 0x17000) {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar5,(undefined8 *)&CmdDescReadIoDirect,(uVar9 & 0x1ffff) << 9,0,0,0,0,0
                   ,0);
        *(undefined1 *)(param_1 + 0x574) = 2;
        return 0xc0000016;
      }
      goto LAB_14001bfd9;
    }
    if (cVar2 == '\x02') {
      uVar3 = *(undefined1 *)(param_1 + 0x25c);
      *(undefined1 *)(lVar5 + 0x101d) = uVar3;
      *(undefined1 *)(lVar5 + 0x101e) = uVar3;
      *(undefined1 *)(lVar5 + 0x101f) = 0;
      memset((void *)(lVar5 + 0x1020),0,0x100);
LAB_14001bdf5:
      *(undefined1 *)(param_1 + 0x574) = 3;
      return 0xc0000016;
    }
    if (cVar2 == '\x03') {
      if (*(char *)(lVar5 + 0x101e) == '\0') {
        uVar6 = SdbusProcessTuplePacket(lVar5 + 0xb28,(int *)puVar1,*(uint *)(param_1 + 0x570));
        uVar8 = uVar6 & 0xffffffff;
        if (-1 < (int)uVar6) {
          *puVar1 = *puVar1 + (uint)*(byte *)(lVar5 + 0x101d);
          *(undefined1 *)(param_1 + 0x574) = 0;
          return 0xc0000016;
        }
        SdbusDebugPrint(1,"wp  %p ProcessTuplePacket returns 0x%08x",param_2,uVar6 & 0xffffffff);
        if ((int)uVar6 == -0x3fffffea) {
          return uVar8;
        }
        goto LAB_14001bff5;
      }
      uVar9 = (uint)*(byte *)(lVar5 + 0x101f) + *puVar1;
      uVar10 = uVar9 * 0x200 & 0x3fffe00;
      if ((uVar10 >> 9) - 0x1000 < 0x17000) {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar5,(undefined8 *)&CmdDescReadIoDirect,uVar10,0,0,0,0,0,0);
        *(undefined1 *)(param_1 + 0x574) = 4;
        return 0xc0000016;
      }
      uVar7 = 0x80;
      goto LAB_14001bfe1;
    }
    if (cVar2 == '\x04') {
      *(undefined1 *)((ulonglong)*(byte *)(lVar5 + 0x101f) + 8 + (longlong)puVar1) =
           *(undefined1 *)(param_1 + 0x25c);
      *(char *)(lVar5 + 0x101f) = *(char *)(lVar5 + 0x101f) + '\x01';
      *(char *)(lVar5 + 0x101e) = *(char *)(lVar5 + 0x101e) + -1;
      goto LAB_14001bdf5;
    }
  }
  uVar8 = 0xc0000001;
LAB_14001bff5:
  SdbusDebugPrint(0x80,"wp  %p ProcessTupleChain COMPLETE %08x",param_2,uVar8);
  return uVar8;
}



===== SdbusProcessTuplePacket @ 14001c02c =====

undefined8 SdbusProcessTuplePacket(longlong param_1,int *param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  byte bVar5;
  char *pcVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  char cVar10;
  longlong lVar11;
  
  uVar9 = (ulonglong)*(byte *)(param_2 + 1);
  uVar3 = (ulonglong)param_3;
  SdbusDebugPrint(0x80,"CIS %.06x code=%.02x link=%.02x",(ulonglong)(*param_2 - 2),uVar9);
  if (7 < param_3) {
    return 0xc000000d;
  }
  cVar10 = (char)param_2[1];
  if (cVar10 == '\x15') {
    bVar1 = *(byte *)((longlong)param_2 + 5);
    cVar10 = *(char *)((longlong)param_2 + 10);
    uVar9 = uVar9 & 0xffffffffffffff00;
    uVar8 = 3;
    while( true ) {
      bVar5 = (byte)uVar9;
      if (cVar10 == '\0') break;
      if ((uint)bVar1 < (uint)uVar8) {
        pcVar6 = "CISTPL_VERS_1 MfgText longer than Link";
        goto LAB_14001c27f;
      }
      if (0x40 < bVar5) goto LAB_14001c26f;
      if ((byte)(cVar10 - 0x20U) < 0x5f) {
        uVar4 = uVar9 & 0xff;
        uVar9 = CONCAT71((int7)(uVar9 >> 8),bVar5 + 1);
        *(char *)(uVar4 + 0x79 + uVar3 * 0x90 + param_1) = cVar10;
      }
      cVar10 = *(char *)(uVar8 + 8 + (longlong)param_2);
      uVar8 = (ulonglong)((uint)uVar8 + 1);
    }
    if (bVar5 < 0x41) {
      bVar5 = 0;
      lVar11 = uVar3 * 0x90;
      *(undefined1 *)((uVar9 & 0xff) + lVar11 + 0x79 + param_1) = 0;
      cVar10 = *(char *)(uVar8 + 8 + (longlong)param_2);
      while( true ) {
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
        if (cVar10 == '\0') break;
        if (bVar1 < uVar7) {
          pcVar6 = "CISTPL_VERS_1 ProductText longer than Link";
          goto LAB_14001c27f;
        }
        if (0x40 < bVar5) goto LAB_14001c2e4;
        if ((byte)(cVar10 - 0x20U) < 0x5f) {
          uVar4 = (ulonglong)bVar5;
          bVar5 = bVar5 + 1;
          *(char *)(uVar4 + lVar11 + 0xba + param_1) = cVar10;
        }
        cVar10 = *(char *)(uVar8 + 8 + (longlong)param_2);
      }
      if (bVar5 < 0x41) {
        *(undefined1 *)((ulonglong)bVar5 + 0xba + uVar3 * 0x90 + param_1) = 0;
        SdbusDebugPrint(0x80,"CISTPL_VERS_1 fn(%d) %s %s",uVar3,param_1 + 0x79 + lVar11);
        return 0;
      }
LAB_14001c2e4:
      pcVar6 = "CISTPL_VERS_1 MfgText longer than MAX_IDENT_LENGTH";
    }
    else {
LAB_14001c26f:
      pcVar6 = "CISTPL_VERS_1 MfgText longer than MAX_MANFID_LENGTH";
    }
LAB_14001c27f:
    SdbusDebugPrint(1,pcVar6,uVar8,uVar9);
  }
  else {
    if (cVar10 == ' ') {
      uVar7 = (uint)*(byte *)((longlong)param_2 + 5);
      if (3 < *(byte *)((longlong)param_2 + 5)) {
        *(undefined1 *)(param_1 + 0x6d + uVar3 * 0x90) = 1;
        uVar2 = *(ushort *)(param_2 + 2);
        *(ushort *)(param_1 + 0x6e + uVar3 * 0x90) = uVar2;
        *(undefined2 *)(param_1 + 0x70 + uVar3 * 0x90) = *(undefined2 *)((longlong)param_2 + 10);
        SdbusDebugPrint(0x80,"CISTPL_MANFID fn(%d) code=%x, inf=%x",uVar3,(ulonglong)uVar2);
        return 0;
      }
      pcVar6 = "CISTPL_MANFID invalid link %x";
    }
    else if (cVar10 == '!') {
      uVar7 = (uint)*(byte *)((longlong)param_2 + 5);
      if (*(byte *)((longlong)param_2 + 5) == 2) {
        uVar7 = (uint)*(byte *)(param_2 + 2);
        if (*(byte *)(param_2 + 2) == 0xc) {
          return 0;
        }
        pcVar6 = "CISTPL_FUNCID invalid id %x\n";
      }
      else {
        pcVar6 = "CISTPL_FUNCID invalid link %x\n";
      }
    }
    else {
      if (cVar10 != '\"') {
        return 0;
      }
      bVar1 = *(byte *)(param_2 + 2);
      uVar7 = (uint)bVar1;
      if (param_3 != 0) {
        if (bVar1 == 1) {
          uVar7 = (uint)*(byte *)((longlong)param_2 + 5);
          if (0xd < *(byte *)((longlong)param_2 + 5)) {
            bVar1 = *(byte *)((longlong)param_2 + 9);
            *(byte *)(param_1 + 0x78 + uVar3 * 0x90) = bVar1;
            *(undefined4 *)(param_1 + 0x74 + uVar3 * 0x90) =
                 *(undefined4 *)((longlong)param_2 + 0xb);
            *(short *)(param_1 + 0x72 + uVar3 * 0x90) = (short)param_2[5];
            SdbusDebugPrint(0x80,"CISTPL_FUNCE (%d) FuncInfo %02x blksize %04x PSN %08x",uVar3,
                            (ulonglong)bVar1);
            return 0;
          }
          pcVar6 = "CISTPL_FUNCE link %x not big enough for function %d";
        }
        else {
          pcVar6 = "CISTPL_FUNCE TPLFE_TYPE(%x) does not match for function %d";
        }
        SdbusDebugPrint(1,pcVar6,(ulonglong)uVar7,uVar3);
        return 0xc0000001;
      }
      if (bVar1 == 0) {
        uVar7 = (uint)*(byte *)((longlong)param_2 + 5);
        if (3 < *(byte *)((longlong)param_2 + 5)) {
          uVar2 = *(ushort *)((longlong)param_2 + 9);
          *(ushort *)(param_1 + 0x72) = uVar2;
          bVar1 = *(byte *)((longlong)param_2 + 0xb);
          *(byte *)(param_1 + 0x6a) = bVar1;
          SdbusDebugPrint(0x80,"CISTPL_FUNCE (0) blksize %04x transpeed %02x",(ulonglong)uVar2,
                          (ulonglong)bVar1);
          return 0;
        }
        pcVar6 = "CISTPL_FUNCE link %x not big enough for function 0";
      }
      else {
        pcVar6 = "CISTPL_FUNCE TPLFE_TYPE(%x) does not match for function 0";
      }
    }
    SdbusDebugPrint(1,pcVar6,(ulonglong)uVar7,uVar9);
  }
  return 0xc0000001;
}



===== SdbusReadDeviceConfigWorker @ 14001c370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SdbusReadDeviceConfigWorker
                    (longlong param_1,longlong *param_2,ulonglong param_3,ulonglong param_4)

{
  undefined8 *_Dst;
  uint *_Dst_00;
  byte bVar1;
  char cVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  byte bVar10;
  short sVar11;
  char *pcVar12;
  longlong lVar13;
  char *pcVar14;
  ulonglong uVar15;
  ushort uVar16;
  uint uVar17;
  ulonglong uVar18;
  longlong *plVar19;
  longlong lVar20;
  undefined4 uVar21;
  byte bVar22;
  undefined1 auStackY_a8 [32];
  byte local_58;
  undefined4 uStack_57;
  undefined1 uStack_53;
  char cStack_52;
  uint uStack_51;
  undefined1 uStack_4d;
  undefined2 local_4c;
  undefined1 local_4a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar3 = *param_2;
  uVar17 = *(uint *)(param_1 + 0x1b4);
  _Dst = (undefined8 *)(lVar3 + 0xb28);
  _Dst_00 = (uint *)(lVar3 + 0x1018);
  if (uVar17 < 0xc) {
    if (uVar17 == 0xb) {
      *_Dst_00 = *_Dst_00 | (uint)*(byte *)(param_1 + 0x25c) << 8;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x1600,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 0xc;
      return 0xc0000016;
    }
    uVar21 = 5;
    if (uVar17 < 6) {
      if (uVar17 == 5) {
        (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0xa0))(lVar3,1);
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 6;
        return 0xc0000016;
      }
      if (uVar17 == 0) {
        SdbusDebugPrint(0x80,"wp  %p GetDeviceConfig Entered",param_2,param_4);
        if ((*(char *)(lVar3 + 0x117a) == '\0') && (1 < *(int *)(lVar3 + 0x117c) - 2U)) {
          return 0xc0000001;
        }
        lVar20 = 9;
        puVar4 = (undefined8 *)(lVar3 + 0x1160);
        do {
          puVar8 = puVar4;
          lVar13 = lVar20;
          puVar6 = _Dst;
          uVar7 = puVar8[1];
          *puVar6 = *puVar8;
          puVar6[1] = uVar7;
          uVar7 = puVar8[3];
          puVar6[2] = puVar8[2];
          puVar6[3] = uVar7;
          uVar7 = puVar8[5];
          puVar6[4] = puVar8[4];
          puVar6[5] = uVar7;
          uVar7 = puVar8[7];
          puVar6[6] = puVar8[6];
          puVar6[7] = uVar7;
          uVar7 = puVar8[9];
          puVar6[8] = puVar8[8];
          puVar6[9] = uVar7;
          uVar7 = puVar8[0xb];
          puVar6[10] = puVar8[10];
          puVar6[0xb] = uVar7;
          uVar7 = puVar8[0xd];
          puVar6[0xc] = puVar8[0xc];
          puVar6[0xd] = uVar7;
          uVar7 = puVar8[0xf];
          puVar6[0xe] = puVar8[0xe];
          puVar6[0xf] = uVar7;
          lVar20 = lVar13 + -1;
          _Dst = puVar6 + 0x10;
          puVar4 = puVar8 + 0x10;
        } while (lVar20 != 0);
        uVar7 = puVar8[0x11];
        puVar6[0x10] = puVar8[0x10];
        puVar6[0x11] = uVar7;
        uVar7 = puVar8[0x13];
        puVar6[0x12] = puVar8[0x12];
        puVar6[0x13] = uVar7;
        uVar7 = puVar8[0x15];
        puVar6[0x14] = puVar8[0x14];
        puVar6[0x15] = uVar7;
        uVar7 = puVar8[0x17];
        puVar6[0x16] = puVar8[0x16];
        puVar6[0x17] = uVar7;
        uVar7 = puVar8[0x19];
        puVar6[0x18] = puVar8[0x18];
        puVar6[0x19] = uVar7;
        uVar7 = puVar8[0x1b];
        puVar6[0x1a] = puVar8[0x1a];
        puVar6[0x1b] = uVar7;
        uVar7 = puVar8[0x1d];
        puVar6[0x1c] = puVar8[0x1c];
        puVar6[0x1d] = uVar7;
        *(undefined4 *)(param_1 + 0x1b8) = 0x14;
        iVar5 = 1;
        if (1 < *(int *)(lVar3 + 0xb44) - 2U) {
          iVar5 = (int)lVar13 + 3;
        }
        *(int *)(param_1 + 0x1b4) = iVar5;
        return 0xc0000016;
      }
      if (uVar17 == 1) {
        (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x28) + 0xa0))
                  (lVar3,*(undefined1 *)(lVar3 + 0xb42));
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescSendCid,*(undefined4 *)(lVar3 + 0x168c),0,
                   0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 2;
        return 0xc0000016;
      }
      if (uVar17 != 2) {
        if (uVar17 == 3) {
          uVar15 = *(ulonglong *)(param_1 + 0x25c);
          uVar21 = *(undefined4 *)(param_1 + 0x264);
          uStack_53 = (undefined1)(uVar15 >> 0x28);
          cStack_52 = (char)(uVar15 >> 0x30);
          uStack_51._0_1_ = (undefined1)(uVar15 >> 0x38);
          uStack_51._1_3_ = (undefined3)uVar21;
          uStack_4d = (undefined1)((uint)uVar21 >> 0x18);
          bVar10 = (byte)((uint)uVar21 >> 8);
          uVar16 = (ushort)((uint)uVar21 >> 8);
          if (*(int *)(lVar3 + 0xb44) == 2) {
            bVar1 = *(byte *)(param_1 + 0x26a);
            bVar22 = bVar1 >> 6;
            if (bVar22 == 0) {
              *(undefined1 *)(lVar3 + 0xb82) = uStack_4d;
              *(ushort *)(lVar3 + 0xb70) = uVar16 >> 4;
              lVar20 = 1L << ((byte)((uint)((uVar15 & 0xffffffffffffff) >> 0x18) >> 0xf) & 7) + 2;
              uVar18 = (ulonglong)
                       ((uStack_51 & 0x3ff) << 2 | (uint)((uVar15 & 0xffffffffffffff) >> 0x36));
              uVar15 = 1L << (bVar10 & 0xf);
            }
            else {
              uVar15 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
              uVar16 = (ushort)(uStack_51 >> 0x10);
              if ((int)uVar15 == 0) {
                uVar15 = 0x400;
                *(undefined1 *)(lVar3 + 0xb82) = uStack_4d;
                lVar20 = 0x200;
                *(ushort *)(lVar3 + 0xb70) = uVar16 >> 4;
                uVar18 = (ulonglong)
                         ((uStack_51 & 0x3f) << 0x10 | (uint)CONCAT11(cStack_52,uStack_53));
              }
              else {
                if (bVar22 == 1) {
                  uVar17 = uStack_51 & 0x3f;
                }
                else {
                  if (bVar22 != 2) {
                    SdbusDebugPrint(0x80,"Unsupported CSD version: %d",(ulonglong)(bVar1 >> 6),
                                    param_4);
                    return 0xc0000001;
                  }
                  uVar17 = uStack_51 & 0xfff;
                }
                *(undefined1 *)(lVar3 + 0xb82) = uStack_4d;
                lVar20 = 0x200;
                uVar15 = 0x400;
                uVar18 = (ulonglong)(uVar17 << 0x10 | (uint)CONCAT11(cStack_52,uStack_53));
                *(ushort *)(lVar3 + 0xb70) = uVar16 >> 4;
              }
            }
          }
          else {
            *(byte *)(lVar3 + 0xb58) = *(byte *)(param_1 + 0x26a) >> 2 & 0xf;
            *(undefined1 *)(lVar3 + 0xb82) = uStack_4d;
            *(ushort *)(lVar3 + 0xb70) = uVar16 >> 4;
            uVar18 = (ulonglong)
                     ((uint)(ushort)(((ushort)uStack_51 & 0x3ff) << 2) |
                     (uint)((uVar15 & 0xffffffffffffff) >> 0x36));
            lVar20 = 1L << ((byte)((uint)((uVar15 & 0xffffffffffffff) >> 0x18) >> 0xf) & 7) + 2;
            uVar15 = (ulonglong)(ushort)(1 << (bVar10 & 0xf));
          }
          *(short *)(lVar3 + 0xb80) = (short)uVar15;
          *(ulonglong *)(lVar3 + 0xb78) = ((int)uVar18 + 1) * uVar15 * lVar20;
          SdbusDebugPrint(0x80,"------------------------CSD----------------------",uVar18,lVar20);
          SdbusDebugPrint(0x80,
                          "max trans rate=0x%x\tclasses=0x%x\tdevice cap=%I64u\tmax block len=%d",
                          (ulonglong)*(byte *)(lVar3 + 0xb82),(ulonglong)*(ushort *)(lVar3 + 0xb70))
          ;
          *(uint *)(param_1 + 0x1b4) =
               (-(uint)(*(char *)(lVar3 + 0xb42) != '\0') & 0xffffffee) + 0x16;
          return 0xc0000016;
        }
        if (uVar17 == 4) {
          SdbusWorkerSetStateCmdExecWithFlags
                    (param_1,lVar3,(undefined8 *)&CmdDescSelectCard,*(undefined4 *)(lVar3 + 0x168c),
                     0,0,0,0,0,0);
          *(undefined4 *)(param_1 + 0x1b4) = uVar21;
          return 0xc0000016;
        }
        return 0xc0000001;
      }
      pcVar14 = (char *)(lVar3 + 0xb63);
      uVar7 = *(undefined8 *)(param_1 + 0x25c);
      local_58 = (byte)uVar7;
      uStack_57 = (undefined4)((ulonglong)uVar7 >> 8);
      uStack_53 = (undefined1)((ulonglong)uVar7 >> 0x28);
      cStack_52 = (char)((ulonglong)uVar7 >> 0x30);
      uStack_51._0_1_ = (undefined1)((ulonglong)uVar7 >> 0x38);
      uStack_51._1_3_ = (undefined3)*(undefined4 *)(param_1 + 0x264);
      uStack_4d = (undefined1)((uint)*(undefined4 *)(param_1 + 0x264) >> 0x18);
      if (*(int *)(lVar3 + 0xb44) == 2) {
        local_4c = *(ushort *)(param_1 + 0x268);
        local_4a = *(undefined1 *)(param_1 + 0x26a);
        uVar17 = 0;
        pcVar12 = pcVar14;
        do {
          cVar2 = *(char *)((longlong)&uStack_51 + (ulonglong)(4 - uVar17));
          param_4 = CONCAT71((int7)(param_4 >> 8),cVar2);
          if (0x5e < (byte)(cVar2 - 0x21U)) break;
          *pcVar12 = cVar2;
          uVar17 = uVar17 + 1;
          pcVar12 = pcVar12 + 1;
        } while (uVar17 < 5);
        uStack_57._0_1_ = (byte)((ulonglong)uVar7 >> 8);
        uVar16 = (((byte)uStack_57 & 0xf) + 0x7d) * 0x10 + (ushort)(local_58 >> 4);
        param_3 = (ulonglong)uVar16;
        *(char *)(lVar3 + 0xb5e) = cStack_52;
        bVar10 = local_58 & 0xf;
        *(int *)(lVar3 + 0xb6c) = (int)((ulonglong)uVar7 >> 0x10);
        *(ushort *)(lVar3 + 0xb60) = uVar16;
        *(undefined1 *)(lVar3 + 0xb5a) = local_4a;
        *(ushort *)(lVar3 + 0xb5c) = local_4c;
      }
      else {
        uVar16 = *(ushort *)(param_1 + 0x268);
        local_4a = *(undefined1 *)(param_1 + 0x26a);
        param_4 = CONCAT71((int7)(param_4 >> 8),local_4a);
        uVar17 = 0;
        pcVar12 = pcVar14;
        do {
          cVar2 = (&cStack_52)[5 - uVar17];
          param_3 = CONCAT71((int7)(param_3 >> 8),cVar2);
          if (0x5e < (byte)(cVar2 - 0x21U)) break;
          *pcVar12 = cVar2;
          uVar17 = uVar17 + 1;
          pcVar12 = pcVar12 + 1;
        } while (uVar17 < 6);
        *(undefined1 *)(lVar3 + 0xb5a) = local_4a;
        bVar10 = local_58 >> 4;
        *(ushort *)(lVar3 + 0xb5c) = uVar16 & 0xff;
        *(undefined1 *)(lVar3 + 0xb5e) = uStack_53;
        *(undefined4 *)(lVar3 + 0xb6c) = uStack_57;
        local_4c._1_1_ = (byte)(uVar16 >> 8);
        *(ushort *)(lVar3 + 0xb60) = (local_58 & 0xf) + 0x7cd;
        *(byte *)(lVar3 + 0xb83) = local_4c._1_1_ & 3;
        local_4c = uVar16;
      }
      *(byte *)(lVar3 + 0xb62) = bVar10;
      SdbusDebugPrint(0x80,"------------------------CID----------------------",param_3,param_4);
      SdbusDebugPrint(0x80,"ManufacturerId=%02x OEMId=%04x Rev=%02x PSN=%08x",
                      (ulonglong)*(byte *)(lVar3 + 0xb5a),(ulonglong)*(ushort *)(lVar3 + 0xb5c));
      uVar15 = (ulonglong)*(byte *)(lVar3 + 0xb62);
      SdbusDebugPrint(0x80,"ProductName=%s\tManufacturerDate=%02d/%04d",pcVar14,uVar15);
      SdbusDebugPrint(0x80,"-------------------------------------------------",pcVar14,uVar15);
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescSendCsd,*(undefined4 *)(lVar3 + 0x168c),0,0,
                 0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 3;
      return 0xc0000016;
    }
    if (uVar17 == 6) {
      bVar10 = *(byte *)(param_1 + 0x25c) >> 4;
      *(byte *)(lVar3 + 0xb90) = bVar10;
      SdbusDebugPrint(0x80,"wp  %p SDIO card sdio spec revision=%x",param_2,(ulonglong)bVar10);
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x2600,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 7;
      return 0xc0000016;
    }
    if (uVar17 == 7) {
      bVar10 = *(byte *)(param_1 + 0x25c) & 1;
      *(byte *)(lVar3 + 0xb2a) = bVar10;
      SdbusDebugPrint(0x80,"wp  %p SDIO card support high speed=%x",param_2,(ulonglong)bVar10);
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x2c00,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 8;
      return 0xc0000016;
    }
    if (uVar17 == 8) {
      bVar10 = *(byte *)(param_1 + 0x25c) & 1;
      *(byte *)(lVar3 + 0xb93) = bVar10;
      SdbusDebugPrint(0x80,"wp  %p SDIO card support async interrupt=%x",param_2,(ulonglong)bVar10);
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x1000,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 9;
      return 0xc0000016;
    }
    if (uVar17 != 9) {
      if (uVar17 == 10) {
        *_Dst_00 = (uint)*(byte *)(param_1 + 0x25c);
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x1400,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0xb;
        return 0xc0000016;
      }
      return 0xc0000001;
    }
    bVar10 = *(byte *)(param_1 + 0x25c);
    *(byte *)(lVar3 + 0xb91) = bVar10;
    SdbusDebugPrint(0x80,"wp  %p SDIO card capabilities=%x",param_2,(ulonglong)bVar10);
    if ((*(uint *)(lVar3 + 0x48) & 0x40000) == 0) {
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,0x1200,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 10;
      return 0xc0000016;
    }
    *(undefined4 *)(param_1 + 0x570) = 8;
  }
  else if (uVar17 < 0x12) {
    if (uVar17 == 0x11) {
      iVar5 = *(int *)(param_1 + 0x570);
      *_Dst_00 = *_Dst_00 | (uint)*(byte *)(param_1 + 0x25c) << 8;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,
                 iVar5 * 0x20000 + 0x1600U & 0x3fffe00,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 0x12;
      return 0xc0000016;
    }
    if (uVar17 == 0xc) {
      uVar17 = (uint)*(byte *)(param_1 + 0x25c) << 0x10 | *_Dst_00;
      *_Dst_00 = uVar17;
      SdbusDebugPrint(0x80,"wp  %p SDIO Process COMMON tuple chain: CCCR cisPtr=%.06x",param_2,
                      (ulonglong)uVar17);
      *(undefined4 *)(param_1 + 0x1b4) = 0xd;
      *(undefined4 *)(param_1 + 0x570) = 0;
LAB_14001d1c9:
      *(undefined1 *)(param_1 + 0x574) = 0;
      return 0xc0000016;
    }
    if (uVar17 != 0xd) {
      if (uVar17 == 0xe) {
        if ((uint)*(byte *)(lVar3 + 0xb42) < *(uint *)(param_1 + 0x570)) {
          memset(_Dst_00,0,0x108);
          *(undefined4 *)(param_1 + 0x1b4) = 0x15;
          return 0xc0000016;
        }
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar3,(undefined8 *)&CmdDescReadIoDirect,
                   (*(uint *)(param_1 + 0x570) & 0x1ff) << 0x11,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0xf;
        return 0xc0000016;
      }
      if (uVar17 == 0xf) {
        uVar17 = *(uint *)(param_1 + 0x570);
        *(byte *)(lVar3 + 0xb94 + (ulonglong)uVar17 * 0x90) = *(byte *)(param_1 + 0x25c) & 0xf;
        SdbusDebugPrint(0x80,"wp  %p SDIO fn(%d) IoDeviceInterface=%x",param_2,(ulonglong)uVar17);
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,
                   uVar17 * 0x20000 + 0x1200 & 0x3fffe00,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0x10;
        return 0xc0000016;
      }
      if (uVar17 == 0x10) {
        iVar5 = *(int *)(param_1 + 0x570);
        *_Dst_00 = (uint)*(byte *)(param_1 + 0x25c);
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,*param_2,(undefined8 *)&CmdDescReadIoDirect,
                   iVar5 * 0x20000 + 0x1400U & 0x3fffe00,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0x11;
        return 0xc0000016;
      }
      return 0xc0000001;
    }
    uVar15 = SdbusProcessTupleChain(param_1,param_2);
    iVar5 = (int)uVar15;
    if (iVar5 < 0) {
LAB_14001ce50:
      if (iVar5 == -0x3fffffea) {
        return uVar15 & 0xffffffff;
      }
      *(int *)((longlong)param_2 + 0x3c) = iVar5;
      *(undefined4 *)(param_1 + 0x1b4) = 0x14;
      return 0xc0000016;
    }
    *(undefined4 *)(param_1 + 0x570) = 1;
  }
  else {
    if (uVar17 == 0x12) {
      *_Dst_00 = (uint)*(byte *)(param_1 + 0x25c) << 0x10 | *_Dst_00;
      SdbusDebugPrint(0x80,"wp  %p SDIO Process FUNCTION(%d) Tuple Chain: cisPtr=%.06x",param_2,
                      (ulonglong)*(uint *)(param_1 + 0x570));
      *(undefined4 *)(param_1 + 0x1b4) = 0x13;
      goto LAB_14001d1c9;
    }
    if (uVar17 != 0x13) {
      if (uVar17 == 0x14) {
        uVar17 = *(uint *)((longlong)param_2 + 0x3c);
        if (_Dst != (undefined8 *)0x0) {
          memset(_Dst,0,0x4f0);
        }
        if (_Dst_00 != (uint *)0x0) {
          memset(_Dst_00,0,0x108);
        }
        param_2[0xb] = 0;
        return (ulonglong)uVar17;
      }
      if (uVar17 == 0x15) {
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar3,(undefined8 *)&CmdDescDeselectCard,0,0,0,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1b4) = 0x16;
        return 0xc0000016;
      }
      if (uVar17 != 0x16) {
        return 0xc0000001;
      }
      if ((*(int *)(lVar3 + 0x3c) == 2) &&
         (uVar7 = SdbusIsCardEqual((longlong)_Dst,lVar3 + 0x1160), (char)uVar7 != '\0')) {
        SdbusDebugPrint(0x80,"wp  %p CardData is already in socket - known card",param_2,param_4);
        memset(_Dst,0,0x4f0);
      }
      else {
        if ((*(int *)(lVar3 + 0x117c) == 0) && (*(char *)(lVar3 + 0x117a) == '\0')) {
          return 0xc0000185;
        }
        pcVar14 = "wp  %p New CardData - invalidating old card data";
        plVar19 = param_2;
        SdbusDebugPrint(0x80,"wp  %p New CardData - invalidating old card data",param_2,param_4);
        *(undefined4 *)(lVar3 + 0x3c) = 1;
        SdbusSetSocketCardChanged(lVar3,pcVar14,plVar19,param_4);
        lVar20 = 9;
        puVar4 = (undefined8 *)(lVar3 + 0x1160);
        puVar6 = _Dst;
        do {
          puVar9 = puVar6;
          puVar8 = puVar4;
          uVar7 = puVar9[1];
          *puVar8 = *puVar9;
          puVar8[1] = uVar7;
          uVar7 = puVar9[3];
          puVar8[2] = puVar9[2];
          puVar8[3] = uVar7;
          uVar7 = puVar9[5];
          puVar8[4] = puVar9[4];
          puVar8[5] = uVar7;
          uVar7 = puVar9[7];
          puVar8[6] = puVar9[6];
          puVar8[7] = uVar7;
          uVar7 = puVar9[9];
          puVar8[8] = puVar9[8];
          puVar8[9] = uVar7;
          uVar7 = puVar9[0xb];
          puVar8[10] = puVar9[10];
          puVar8[0xb] = uVar7;
          uVar7 = puVar9[0xd];
          puVar8[0xc] = puVar9[0xc];
          puVar8[0xd] = uVar7;
          uVar7 = puVar9[0xf];
          puVar8[0xe] = puVar9[0xe];
          puVar8[0xf] = uVar7;
          lVar20 = lVar20 + -1;
          puVar4 = puVar8 + 0x10;
          puVar6 = puVar9 + 0x10;
        } while (lVar20 != 0);
        uVar7 = puVar9[0x11];
        puVar8[0x10] = puVar9[0x10];
        puVar8[0x11] = uVar7;
        uVar7 = puVar9[0x13];
        puVar8[0x12] = puVar9[0x12];
        puVar8[0x13] = uVar7;
        uVar7 = puVar9[0x15];
        puVar8[0x14] = puVar9[0x14];
        puVar8[0x15] = uVar7;
        uVar7 = puVar9[0x17];
        puVar8[0x16] = puVar9[0x16];
        puVar8[0x17] = uVar7;
        uVar7 = puVar9[0x19];
        puVar8[0x18] = puVar9[0x18];
        puVar8[0x19] = uVar7;
        uVar7 = puVar9[0x1b];
        puVar8[0x1a] = puVar9[0x1a];
        puVar8[0x1b] = uVar7;
        uVar7 = puVar9[0x1d];
        puVar8[0x1c] = puVar9[0x1c];
        puVar8[0x1d] = uVar7;
        memset(_Dst,0,0x4f0);
        *(undefined8 *)(lVar3 + 0x1664) = 0;
        *(undefined8 *)(lVar3 + 0x166c) = 0;
        *(undefined2 *)(lVar3 + 0x1674) = 0;
        bVar10 = 0;
        do {
          uVar15 = (ulonglong)bVar10;
          sVar11 = *(short *)(lVar3 + 0x11d2 + uVar15 * 0x90);
          if (sVar11 == 0) {
            SdbusDebugPrint(2,"wp  %p func(%d) didn\'t provide block size limit, uses 64 by default"
                            ,param_2,(ulonglong)bVar10);
            sVar11 = 0x40;
          }
          bVar10 = bVar10 + 1;
          *(short *)(uVar15 * 2 + 0x1664 + lVar3) = sVar11;
        } while (bVar10 <= *(byte *)(lVar3 + 0x117a));
        *(undefined1 *)(lVar3 + 0x165f) = *(undefined1 *)(lVar3 + 0x1176);
        *(undefined2 *)(lVar3 + 0x1674) = 0x200;
        *(undefined1 *)(lVar3 + 0x1676) = 0;
      }
      return 0;
    }
    uVar15 = SdbusProcessTupleChain(param_1,param_2);
    iVar5 = (int)uVar15;
    if (iVar5 < 0) goto LAB_14001ce50;
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + 1;
  }
  *(undefined4 *)(param_1 + 0x1b4) = 0xe;
  return 0xc0000016;
}



===== SdbusBasicCommandWorker @ 14001d210 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SdbusBasicCommandWorker(longlong param_1,longlong *param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined4 uVar9;
  longlong lVar10;
  
  lVar10 = param_2[0x12];
  puVar8 = &SdCmdFlags;
  lVar5 = *param_2;
  if (*(int *)(lVar10 + 0x44) != 0) {
    puVar8 = &SdAppCmdFlags;
  }
  iVar4 = *(int *)(param_1 + 0x1b4);
  bVar1 = puVar8[*(byte *)(lVar10 + 0x40)];
  if (iVar4 == 0) {
    SdbusDebugPrint(0x200,"wp  %p BasicCommand START",param_2,lVar10);
    uVar6 = ValidateDeviceCommand((longlong)param_2);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    if ((bVar1 & 8) != 0) {
      *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(lVar5 + 0x1718);
      *(undefined4 *)(param_1 + 0x1b8) = 4;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar5,(undefined8 *)&CmdDescDeselectCard,0,0,0,0,0,0,0);
    }
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else if (iVar4 == 1) {
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    if ((bVar1 & 0x10) == 0) {
      uVar9 = *(undefined4 *)(lVar10 + 0x54);
    }
    else {
      uVar9 = *(undefined4 *)(lVar5 + 0x168c);
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,lVar5,(undefined8 *)(lVar10 + 0x40),uVar9,0,0,0,0,0,bVar1 >> 3 & 1);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else {
    if (iVar4 == 2) {
      bVar3 = *(byte *)(param_1 + 0x26c);
      *(byte *)(lVar10 + 0x38) = bVar3;
      memcpy((void *)(lVar10 + 0x28),(void *)(param_1 + 0x25c),(ulonglong)bVar3);
      if ((bVar1 & 8) != 0) {
        *(undefined4 *)(param_1 + 0x1b8) = 5;
        SdbusWorkerSetStateCmdExecWithFlags
                  (param_1,lVar5,(undefined8 *)&CmdDescSelectCard,*(undefined4 *)(lVar5 + 0x168c),0,
                   0,0,0,0,1);
      }
    }
    else {
      if (iVar4 == 3) {
        pcVar7 = "wp  %p BasicCommand COMPLETE";
        SdbusDebugPrint(0x200,"wp  %p BasicCommand COMPLETE",param_2,lVar10);
        cVar2 = *(char *)(param_1 + 0x564);
        SdbusWorkerClearHpi(param_1,pcVar7,param_2,lVar10);
        return (ulonglong)(-(uint)(cVar2 != '\0') & 0xc0510001);
      }
      if (iVar4 == 4) {
        SdbusDebugPrint(0x200,"wp  %p BasicCommand: deselect command timed out",param_2,lVar10);
        *(undefined1 *)(param_1 + 0x284) = 0;
        *(undefined4 *)(param_1 + 0x280) = 1;
        *(undefined1 *)(param_1 + 0x286) = 0;
        *(undefined4 *)(param_1 + 0x1a8) = 3;
        *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        return 0xc0000016;
      }
      if (iVar4 != 5) {
        return 0xc0000001;
      }
      SdbusDebugPrint(2,"wp  %p BasicCommand: select command timed out",param_2,lVar10);
      *(undefined1 *)(param_1 + 0x284) = 0;
      *(undefined4 *)(param_1 + 0x280) = 1;
      *(undefined1 *)(param_1 + 0x286) = 0;
      *(undefined4 *)(param_1 + 0x1a8) = 3;
      *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
    }
    *(undefined4 *)(param_1 + 0x1b4) = 3;
  }
  return 0xc0000016;
}



===== SdbusDataCommandWorker @ 14001d4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint SdbusDataCommandWorker(longlong param_1,longlong *param_2,undefined8 param_3,ulonglong param_4)

{
  int *piVar1;
  longlong *plVar2;
  uint *puVar3;
  int *piVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined8 uVar11;
  int *piVar12;
  ulonglong uVar13;
  int iVar14;
  uint uVar15;
  char *pcVar16;
  void *_Src;
  longlong lVar17;
  uint uVar18;
  longlong lVar19;
  int *piVar20;
  longlong local_res8;
  int *local_res10;
  ulonglong in_stack_ffffffffffffff58;
  undefined4 local_68;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar8 = (uint)(in_stack_ffffffffffffff58 >> 0x20);
  local_res8 = param_2[1];
  plVar2 = (longlong *)(param_1 + 0x570);
  piVar4 = (int *)param_2[0x12];
  lVar17 = *param_2;
  iVar14 = *(int *)(param_1 + 0x1b4);
  local_58 = 0;
  piVar1 = piVar4 + 0x10;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  local_res10 = piVar4;
  if (iVar14 == 0) {
    SdbusDebugPrint(0x200,"wp  %p ======== SdbusDataCommandWorker: begin I/O ========",param_2,
                    param_4);
    uVar11 = ValidateDeviceCommand((longlong)param_2);
    piVar20 = local_res10;
    if ((int)(uint)uVar11 < 0) {
      return (uint)uVar11;
    }
    if (local_res10[0x18] == 0) {
      SdbusDebugPrint(4,"wp  %p DataTransfer zero length!",param_2,param_4);
      return 0;
    }
    param_2[0xb] = 0;
    *(undefined8 *)(param_1 + 0x580) = 0;
    *(undefined8 *)(param_1 + 0x578) = 0;
    *plVar2 = (ulonglong)*(uint *)(*(longlong *)(local_res10 + 0x16) + 0x2c) +
              *(longlong *)(*(longlong *)(local_res10 + 0x16) + 0x20);
    *(int *)(param_1 + 0x5a4) = local_res10[0x18];
    *(undefined4 *)(param_1 + 0x59c) = 0;
    *(undefined8 *)(lVar17 + 0x308) = *(undefined8 *)(local_res10 + 0x16);
    if (((piVar4[0x11] == 0) && ((char)*piVar1 == '5')) &&
       (*(uint *)(param_1 + 0x5a4) <= SdPioTransferThreshold)) {
      *(undefined4 *)(param_1 + 0x59c) = 1;
    }
    *(undefined1 *)(param_1 + 0x5ad) = 0;
    if ((piVar4[0x11] == 0) && ((char)*piVar1 == '5')) {
      uVar18 = local_res10[0x15];
      *(uint *)(param_1 + 0x594) = uVar18 >> 9 & 0x1ffff;
      *(byte *)(param_1 + 0x5ac) = (byte)(uVar18 >> 0x1a) & 1;
      if ((uVar18 >> 0x1b & 1) == 0) {
        *(undefined4 *)(param_1 + 0x590) = 0x200;
        uVar18 = 0;
      }
      else {
        if ((uVar18 & 0x70000000) == 0) {
          uVar7 = *(ushort *)(lVar17 + 0x1664);
        }
        else {
          uVar7 = *(ushort *)(lVar17 + 0x1664 + (ulonglong)*(byte *)(local_res8 + 0xc4) * 2);
        }
        uVar18 = 0x1ff;
        *(uint *)(param_1 + 0x590) = (uint)uVar7;
        if (*(ushort *)(lVar17 + 0x1148) < 0x200) {
          uVar18 = (uint)*(ushort *)(lVar17 + 0x1148);
        }
      }
    }
    else {
      *(int *)(param_1 + 0x594) = local_res10[0x15];
      uVar13 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
      uVar18 = 0;
      if (((int)uVar13 != 0) && (*piVar20 == 6)) {
        *(int *)(param_1 + 0x598) = piVar20[0x19];
      }
      *(undefined1 *)(param_1 + 0x5ac) = 1;
      *(undefined4 *)(param_1 + 0x590) = 0x200;
      if (piVar4[0x13] - 3U < 2) {
        uVar18 = (uint)*(ushort *)(lVar17 + 0x1148);
      }
    }
    *(uint *)(param_1 + 0x588) = uVar18;
    *(undefined4 *)(param_1 + 0x1b8) = 7;
    uVar13 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
    param_4 = (ulonglong)*(uint *)(param_1 + 0x5a4);
    if ((int)uVar13 == 0) {
      in_stack_ffffffffffffff58 = (ulonglong)uVar8 << 0x20;
      SdbusDebugPrint(0x200,"wp  %p   Overall transfer info: length=%d\t\taddress=0x%08x",param_2,
                      param_4);
    }
    else {
      in_stack_ffffffffffffff58 = (ulonglong)uVar8 << 0x20;
      SdbusDebugPrint(0x200,
                      "wp  %p   Overall transfer info: length=%d\t\taddress=0x%08x\t\tUpperAddress=0x%08x"
                      ,param_2,param_4);
    }
    if (((*(int *)(local_res8 + 200) != 1) && ((*(uint *)(lVar17 + 0x48) & 0x20) != 0)) &&
       ((char)*piVar1 != '*')) {
LAB_14001dd28:
      *(undefined4 *)(param_1 + 0x5a8) = 0;
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar17,(undefined8 *)&CmdDescSendStatus,*(undefined4 *)(lVar17 + 0x168c),0,
                 0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1b4) = 6;
      return 0xc0000016;
    }
    *(undefined4 *)(param_1 + 0x1b4) = 1;
LAB_14001df72:
    iVar14 = 1;
    if (*(int *)(param_1 + 0x59c) != 1) {
      param_4 = (ulonglong)*(uint *)(param_1 + 0x5a4);
      iVar14 = (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 8) + 0x28) + 0x100))
                         (lVar17,*plVar2,piVar1);
      *(int *)(param_1 + 0x59c) = iVar14;
    }
    uVar8 = *(uint *)(param_1 + 0x588);
    if (uVar8 == 0) {
      if (iVar14 != 3) goto LAB_14001dfc7;
    }
    else if (iVar14 == 3) {
      uVar18 = *(uint *)(lVar17 + 0x16f0) / *(uint *)(param_1 + 0x590);
      if (uVar18 < uVar8) {
        uVar8 = uVar18;
      }
      *(uint *)(param_1 + 0x588) = uVar8;
    }
    else {
LAB_14001dfc7:
      if (((iVar14 != 4) && (*(longlong *)(param_1 + 0x578) == 0)) &&
         (*(char *)(param_1 + 0x5ad) == '\0')) {
        lVar19 = *(longlong *)(piVar20 + 0x16);
        if ((*(byte *)(lVar19 + 10) & 5) == 0) {
          param_4 = 0;
          in_stack_ffffffffffffff58 = in_stack_ffffffffffffff58 & 0xffffffff00000000;
          lVar19 = MmMapLockedPagesSpecifyCache(lVar19,0,1,0,in_stack_ffffffffffffff58,0x40000020);
        }
        else {
          lVar19 = *(longlong *)(lVar19 + 0x18);
        }
        *(longlong *)(param_1 + 0x578) = lVar19;
        if (lVar19 == 0) {
          SdbusDebugPrint(1,"wp  %p Can\'t map memory. Switch to low memory mode",param_2,param_4);
          *(undefined1 *)(param_1 + 0x5ad) = 1;
          *(undefined4 *)(param_1 + 0x59c) = 1;
        }
      }
    }
    uVar10 = (uint)(in_stack_ffffffffffffff58 >> 0x20);
    uVar8 = *(uint *)(param_1 + 0x5a4);
    uVar18 = *(uint *)(param_1 + 0x590);
    *(uint *)(param_1 + 0x5a0) = uVar8;
    if (*(int *)(param_1 + 0x588) == 0) {
      uVar13 = 0;
      uVar15 = uVar8;
      if (uVar18 <= uVar8) {
        uVar15 = uVar18;
      }
      *(uint *)(param_1 + 0x590) = uVar15;
    }
    else if (uVar8 < uVar18) {
      if ((piVar4[0x11] != 0) || ((char)*piVar1 != '5')) {
        SdbusDebugPrint(1,"wp  %p transfer length is not correct",param_2,param_4);
        return 0xc000000d;
      }
      *(undefined4 *)(param_1 + 0x588) = 0;
      uVar13 = 0;
      uVar15 = 0x200;
      if (uVar8 < 0x200) {
        uVar15 = uVar8;
      }
      *(uint *)(param_1 + 0x590) = uVar15;
    }
    else {
      if (*(int *)(param_1 + 0x59c) == 3) {
        local_68 = 1;
        uStack_64 = 0;
        uStack_60 = 0;
        uStack_5c = 0;
        local_58 = 0;
        uVar11 = CONCAT71((int7)(in_stack_ffffffffffffff58 >> 8),piVar4[0x12] == 2);
        (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0x88))
                  (*(longlong *)(lVar17 + 0x2d8),*(undefined8 *)(lVar17 + 0x308),0,uVar8,uVar11,
                   &local_68);
        uVar10 = (uint)((ulonglong)uVar11 >> 0x20);
        if (*(uint *)(lVar17 + 0x35c) < uStack_64) {
          *(uint *)(param_1 + 0x5a0) =
               *(uint *)(lVar17 + 0x35c) * 0x1000 - *(int *)(*(longlong *)(lVar17 + 0x308) + 0x2c);
        }
      }
      uVar13 = (ulonglong)*(uint *)(param_1 + 0x5a0) / (ulonglong)*(uint *)(param_1 + 0x590);
      if (*(uint *)(param_1 + 0x588) <= (uint)uVar13) {
        uVar13 = (ulonglong)*(uint *)(param_1 + 0x588);
      }
      uVar15 = (int)uVar13 * *(uint *)(param_1 + 0x590);
    }
    piVar12 = (int *)(param_1 + 0x58c);
    *piVar12 = (int)uVar13;
    *(uint *)(param_1 + 0x5a0) = uVar15;
    if (*(int *)(param_1 + 0x59c) == 3) {
      if (*(char *)(lVar17 + 0x24) == '\0') {
        *(longlong *)(lVar17 + 0x29e0) = *(longlong *)(lVar17 + 0x29e0) + 1;
        iVar14 = *(int *)(param_1 + 0x590);
        if (*piVar12 != 0) {
          iVar14 = iVar14 * *piVar12;
        }
        uVar8 = (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0x70))
                          (*(longlong *)(lVar17 + 0x2d8),
                           *(undefined8 *)(*(longlong *)(lVar17 + 8) + 0x10),
                           *(undefined8 *)(piVar20 + 0x16),*plVar2,CONCAT44(uVar10,iVar14),
                           SdbusScatterGatherListControl,param_2,piVar4[0x12] == 2,
                           *(undefined8 *)(lVar17 + 0x380),*(undefined4 *)(lVar17 + 0x378));
      }
      else {
        iVar14 = *(int *)(param_1 + 0x590);
        if (*piVar12 != 0) {
          iVar14 = iVar14 * *piVar12;
        }
        *(longlong *)(lVar17 + 0x29f0) = *(longlong *)(lVar17 + 0x29f0) + 1;
        local_res8 = CONCAT44(local_res8._4_4_,iVar14);
        uVar9 = (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0xb8))
                          (*(longlong *)(lVar17 + 0x2d8),*(undefined8 *)(piVar20 + 0x16),
                           *(undefined8 *)(lVar17 + 0x300),0,(ulonglong)uVar10 << 0x20,&local_res8,
                           piVar4[0x12] == 2,*(undefined8 *)(lVar17 + 0x380),
                           *(undefined4 *)(lVar17 + 0x378),0,0);
        uVar11 = *(undefined8 *)(lVar17 + 0x380);
        local_res10 = (int *)CONCAT44(local_res10._4_4_,uVar9);
        *(longlong *)(*param_2 + 0x29e8) = *(longlong *)(*param_2 + 0x29e8) + 1;
        *(undefined8 *)(param_2[2] + 0x580) = uVar11;
        SdbusWorkerPushEvents(*param_2,0x10000,0,'\x01','\0');
        uVar8 = (uint)local_res10;
      }
      if (-1 < (int)uVar8) {
        *(undefined8 *)(param_1 + 0x1d0) = 0x10000;
        *(undefined4 *)(param_1 + 0x1b4) = 2;
        return 0xc0000016;
      }
      uVar13 = (ulonglong)uVar8;
      SdbusDebugPrint(1,"wp  %p  GetScatterGatherList failed, transitioning to low memory mode 0x%x"
                      ,param_2,uVar13);
      *(undefined1 *)(param_1 + 0x5ad) = 1;
      *(undefined8 *)(param_1 + 0x580) = 0;
      *(undefined4 *)(param_1 + 0x59c) = 1;
    }
    if (*(char *)(param_1 + 0x5ad) != '\0') {
      SdbusDebugPrint(0x200,"wp  %p  enter low mem mode",param_2,uVar13);
      puVar3 = (uint *)(*(longlong *)(lVar17 + 8) + 0x548);
      *puVar3 = *puVar3 | 2;
      if (*(int *)(param_1 + 0x58c) != 0) {
        uVar8 = *(uint *)(param_1 + 0x590);
        uVar18 = *(uint *)(lVar17 + 0x16f4) / uVar8;
        if (*(uint *)(param_1 + 0x588) <= uVar18) {
          uVar18 = *(uint *)(param_1 + 0x588);
        }
        uVar10 = *(uint *)(param_1 + 0x5a0) / uVar8;
        *(uint *)(param_1 + 0x588) = uVar18;
        if (uVar10 < uVar18) {
          uVar18 = uVar10;
        }
        *(uint *)(param_1 + 0x58c) = uVar18;
        *(uint *)(param_1 + 0x5a0) = uVar18 * uVar8;
      }
      IoBuildPartialMdl(*(undefined8 *)(piVar20 + 0x16),*(undefined8 *)(lVar17 + 0x390),*plVar2);
      uVar11 = 0;
      lVar19 = MmMapLockedPagesWithReservedMapping
                         (*(undefined8 *)(lVar17 + 0x388),0x704d6453,*(undefined8 *)(lVar17 + 0x390)
                         );
      *(longlong *)(param_1 + 0x578) = lVar19;
      if (lVar19 == 0) {
        SdbusDebugPrint(1,"wp  %p  Mapping address failed in low mem mode",param_2,uVar11);
        lVar17 = *(longlong *)(lVar17 + 0x390);
        if ((*(byte *)(lVar17 + 10) & 0x20) != 0) {
          MmUnmapLockedPages(*(undefined8 *)(lVar17 + 0x18),lVar17);
        }
        return 0xc000009a;
      }
    }
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else {
    piVar20 = piVar4;
    if (iVar14 == 1) goto LAB_14001df72;
    if (iVar14 != 2) {
      if (iVar14 == 3) {
        if (*(char *)(param_1 + 0x564) != '\0') {
          *(undefined4 *)(param_1 + 0x402) = 0;
          if (*(char *)(param_1 + 0x566) != '\0') {
            SdbusDebugPrint(0x1000000,"Hpi Query EXT_CSD",0x1ff,param_4);
            SdbusAddDbgLog(lVar17,0x48706951,(ulonglong)param_2,0,0);
            SdbusWorkerSetStateCmdExecWithFlags
                      (param_1,lVar17,(undefined8 *)&CmdDescSendExtCsd,
                       *(undefined4 *)(lVar17 + 0x168c),0x200,0,param_1 + 0x310,0,1,0);
            *(undefined4 *)(param_1 + 0x1b4) = 4;
            return 0xc0000016;
          }
          SdbusDebugPrint(0x1000000,"Hpi do not query EXT_CSD",0x1ff,param_4);
          SdbusAddDbgLog(lVar17,0x48706959,(ulonglong)param_2,0,0);
          *(undefined1 *)(param_1 + 0x567) = 0;
          *(undefined4 *)(param_1 + 0x568) = 0;
          goto LAB_14001dab7;
        }
        param_2[0xb] = param_2[0xb] + (ulonglong)*(uint *)(param_1 + 0x5a0);
        *(int *)(param_1 + 0x5a4) = *(int *)(param_1 + 0x5a4) - *(int *)(param_1 + 0x5a0);
        *(undefined4 *)(param_1 + 0x1b4) = 5;
      }
      else {
        if (iVar14 == 4) {
          *(uint *)(param_1 + 0x568) = *(uint *)(param_1 + 0x402);
          *(undefined1 *)(param_1 + 0x567) = 1;
          SdbusDebugPrint(0x1000000,"Hpi EXT_CSD received: correct sector count %d",
                          (ulonglong)*(uint *)(param_1 + 0x402),param_4);
          SdbusAddDbgLog(lVar17,0x48706971,(ulonglong)param_2,(ulonglong)*(uint *)(param_1 + 0x568),
                         0);
          param_2[0xb] = param_2[0xb] +
                         (ulonglong)(uint)(*(int *)(param_1 + 0x568) * *(int *)(param_1 + 0x590));
          *(int *)(param_1 + 0x5a4) =
               *(int *)(param_1 + 0x5a4) - *(int *)(param_1 + 0x568) * *(int *)(param_1 + 0x590);
LAB_14001dab7:
          *(undefined4 *)(param_1 + 0x1b4) = 5;
          return 0xc0000016;
        }
        if (iVar14 != 5) {
          if (iVar14 != 6) {
            if (iVar14 != 7) {
              if (iVar14 != 8) {
                return 0xc0000001;
              }
              if ((*(longlong *)(param_1 + 0x578) != 0) && (*(char *)(param_1 + 0x5ad) != '\0')) {
                MmUnmapReservedMapping
                          (*(longlong *)(param_1 + 0x578),0x704d6453,*(undefined8 *)(lVar17 + 0x390)
                          );
                lVar19 = *(longlong *)(lVar17 + 0x390);
                if ((*(byte *)(lVar19 + 10) & 0x20) != 0) {
                  MmUnmapLockedPages(*(undefined8 *)(lVar19 + 0x18),lVar19);
                }
                *(undefined8 *)(param_1 + 0x578) = 0;
              }
              *(undefined8 *)(lVar17 + 0x308) = 0;
              pcVar16 = "wp  %p DataCommandWorker I/O error(0x%08x)! Info=0x%x";
              *(undefined4 *)(lVar17 + 0x174c) = 0;
              uVar8 = *(uint *)((longlong)param_2 + 0x3c);
              uVar13 = (ulonglong)uVar8;
              SdbusDebugPrint(1,"wp  %p DataCommandWorker I/O error(0x%08x)! Info=0x%x",param_2,
                              uVar13);
              SdbusWorkerClearHpi(param_1,pcVar16,param_2,uVar13);
              return uVar8;
            }
            *(undefined1 *)(param_1 + 0x284) = 0;
            *(undefined4 *)(param_1 + 0x280) = 0;
            *(undefined1 *)(param_1 + 0x286) = 0;
            *(undefined4 *)(param_1 + 0x1a8) = 3;
            *(undefined8 *)(param_1 + 0x278) = _DAT_fffff78000000008;
            if (*(longlong *)(param_1 + 0x580) != 0) {
              if (*(char *)(lVar17 + 0x24) == '\x01') {
                *(longlong *)(lVar17 + 0x29f8) = *(longlong *)(lVar17 + 0x29f8) + 1;
                if (*(char *)(*(longlong *)(lVar17 + 8) + 0x45) == '\t') {
                  if (piVar4[0x12] == 2) {
                    lVar19 = *(longlong *)(lVar17 + 0x2e8);
                  }
                  else {
                    lVar19 = *(longlong *)(lVar17 + 0x2e0);
                  }
                }
                else {
                  lVar19 = *(longlong *)(lVar17 + 0x2d8);
                }
                iVar14 = *(int *)(param_1 + 0x590);
                if (*(int *)(param_1 + 0x58c) != 0) {
                  iVar14 = iVar14 * *(int *)(param_1 + 0x58c);
                }
                uVar11 = CONCAT44(uVar8,iVar14);
                (**(code **)(*(longlong *)(lVar19 + 8) + 0xd0))
                          (lVar19,*(undefined8 *)(lVar17 + 0x308),*(undefined8 *)(lVar17 + 0x300),0,
                           uVar11,piVar4[0x12] == 2);
                uVar8 = (uint)((ulonglong)uVar11 >> 0x20);
              }
              else {
                *(longlong *)(lVar17 + 0x2a00) = *(longlong *)(lVar17 + 0x2a00) + 1;
                (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0x60))
                          (*(longlong *)(lVar17 + 0x2d8),*(undefined8 *)(param_1 + 0x580),
                           CONCAT71(1,piVar4[0x12] == 2));
              }
              *(undefined8 *)(param_1 + 0x580) = 0;
            }
            if (*(int *)(param_1 + 0x59c) == 4) {
              cVar6 = *(char *)(*(longlong *)(lVar17 + 8) + 0x45);
              if (cVar6 == '\b') {
                lVar19 = *(longlong *)(lVar17 + 0x2d8);
              }
              else if ((cVar6 == '\t') || (cVar6 == '\x05')) {
                if (piVar4[0x12] == 2) {
                  lVar19 = *(longlong *)(lVar17 + 0x2e8);
                }
                else {
                  lVar19 = *(longlong *)(lVar17 + 0x2e0);
                }
              }
              else {
                lVar19 = 0;
              }
              if ((*(char *)(lVar17 + 0x24) == '\0') && (*(char *)(lVar17 + 0x359) != '\0')) {
                *(longlong *)(lVar17 + 0x2a08) = *(longlong *)(lVar17 + 0x2a08) + 1;
                cVar6 = (**(code **)(*(longlong *)(lVar19 + 8) + 0xb0))
                                  (lVar19,*(undefined8 *)(*(longlong *)(lVar17 + 8) + 0x68),
                                   *(undefined8 *)(lVar17 + 0x318));
                if (cVar6 == '\0') {
                  if ((*(uint *)(param_2 + 7) & 0x20000000) == 0) {
                    local_40 = 0;
                    local_50 = 0;
                    uStack_48 = 0;
                    KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar17 + 0x350,&local_50);
                    if ((*(char *)(lVar17 + 0x358) == '\0') || (*(char *)(lVar17 + 0x349) == '\0'))
                    {
                      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
                      *(longlong *)(lVar17 + 0x2a18) = *(longlong *)(lVar17 + 0x2a18) + 1;
                      iVar14 = (**(code **)(*(longlong *)(lVar19 + 8) + 0xe0))
                                         (lVar19,*(undefined8 *)(lVar17 + 0x318));
                      if (iVar14 < 0) goto LAB_14001d75d;
                      KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar17 + 0x350,&local_50);
                      if (*(char *)(lVar17 + 0x349) != '\0') {
                        *(undefined1 *)(lVar17 + 0x348) = 1;
                        KeReleaseInStackQueuedSpinLockFromDpcLevel();
                        *(undefined8 *)(param_1 + 0x1d0) = 0x40000;
                        goto LAB_14001d75d;
                      }
                      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
                    }
                    else {
                      *(undefined1 *)(lVar17 + 0x349) = 0;
                      KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_50);
                      *(longlong *)(lVar17 + 0x29f8) = *(longlong *)(lVar17 + 0x29f8) + 1;
                      iVar14 = *(int *)(param_1 + 0x590);
                      if (*(int *)(param_1 + 0x58c) != 0) {
                        iVar14 = iVar14 * *(int *)(param_1 + 0x58c);
                      }
                      (**(code **)(*(longlong *)(lVar19 + 8) + 0xd0))
                                (lVar19,*(undefined8 *)(lVar17 + 0x308),
                                 *(undefined8 *)(lVar17 + 0x300),0,CONCAT44(uVar8,iVar14),
                                 piVar4[0x12] == 2);
                    }
                    *(longlong *)(lVar17 + 0x2a30) = *(longlong *)(lVar17 + 0x2a30) + 1;
                    (**(code **)(*(longlong *)(lVar19 + 8) + 0x30))(lVar19);
                    *(undefined1 *)(lVar17 + 0x359) = 0;
                  }
                }
                else {
                  *(longlong *)(lVar17 + 0x2a10) = *(longlong *)(lVar17 + 0x2a10) + 1;
                }
              }
            }
LAB_14001d75d:
            *(undefined4 *)(param_1 + 0x1b4) = 8;
            return 0xc0000016;
          }
          uVar8 = *(uint *)(param_1 + 0x25c);
          uVar18 = uVar8 >> 0x13;
          if ((char)*piVar1 == '*') {
            bVar5 = (byte)uVar18 & 0x40;
            *(byte *)(lVar17 + 0x1178) = bVar5;
            SdbusDebugPrint(0x200,
                            "wp  %p DataCommandWorker card status reported card lock state is %x",
                            param_2,(ulonglong)bVar5);
            SdbusDebugPrint(0x200,"wp  %p DataCommandWorker COMPLETE, Info=0x%x",param_2,
                            (ulonglong)*(uint *)(param_2 + 0xb));
            return -(uint)((uVar18 & 0x20) != 0) & 0xc0000001;
          }
          if (uVar18 != 0) {
            SdbusDebugPrint(1,"wp %p DataCommandWorker CardStatus Reported Error %x",param_2,
                            (ulonglong)uVar18);
            SdbusCardErrorToNtStatus(uVar18,(int *)((longlong)param_2 + 0x3c));
            *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 1;
LAB_14001d998:
            *(undefined4 *)(param_1 + 0x1b4) = 7;
            return 0xc0000016;
          }
          if (((uVar8 & 0x1e00) != 0x800) || ((uVar8 >> 8 & 1) == 0)) {
            uVar18 = *(uint *)(param_1 + 0x5a8);
            *(uint *)(param_1 + 0x5a8) = uVar18 + 1;
            if (uVar18 < 3) {
              SdbusWorkerSetStateCmdExecWithFlags
                        (param_1,lVar17,(undefined8 *)&CmdDescSendStatus,
                         *(undefined4 *)(lVar17 + 0x168c),0,0,0,0,0,0);
              *(undefined4 *)(param_1 + 0x1b4) = 6;
              *(undefined4 *)(param_1 + 0x1d4) = 500000;
              return 0xc0000016;
            }
            SdbusDebugPrint(0x200,"wp  %p DataCommandWorker TIMEOUT on card in transfer state %x",
                            param_2,(ulonglong)uVar8);
            *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 0x10;
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x80000011;
            goto LAB_14001d998;
          }
          goto LAB_14001d9be;
        }
      }
      if (*(longlong *)(param_1 + 0x580) != 0) {
        if (*(char *)(lVar17 + 0x24) == '\0') {
          *(longlong *)(lVar17 + 0x2a00) = *(longlong *)(lVar17 + 0x2a00) + 1;
          (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0x60))
                    (*(longlong *)(lVar17 + 0x2d8),*(undefined8 *)(param_1 + 0x580),
                     CONCAT71(1,piVar4[0x12] == 2));
        }
        else {
          *(longlong *)(lVar17 + 0x29f8) = *(longlong *)(lVar17 + 0x29f8) + 1;
          iVar14 = *(int *)(param_1 + 0x590);
          if (*(int *)(param_1 + 0x58c) != 0) {
            iVar14 = iVar14 * *(int *)(param_1 + 0x58c);
          }
          param_4 = 0;
          (**(code **)(*(longlong *)(*(longlong *)(lVar17 + 0x2d8) + 8) + 0xd0))
                    (*(longlong *)(lVar17 + 0x2d8),*(undefined8 *)(lVar17 + 0x308),
                     *(undefined8 *)(lVar17 + 0x300),0,CONCAT44(uVar8,iVar14),piVar4[0x12] == 2);
        }
        *(undefined8 *)(param_1 + 0x580) = 0;
      }
      if (*(char *)(param_1 + 0x5ad) != '\0') {
        MmUnmapReservedMapping
                  (*(undefined8 *)(param_1 + 0x578),0x704d6453,*(undefined8 *)(lVar17 + 0x390));
        lVar19 = *(longlong *)(lVar17 + 0x390);
        if ((*(byte *)(lVar19 + 10) & 0x20) != 0) {
          MmUnmapLockedPages(*(undefined8 *)(lVar19 + 0x18),lVar19);
        }
        *(undefined8 *)(param_1 + 0x578) = 0;
      }
      if ((*(int *)(param_1 + 0x5a4) != 0) && (*(char *)(param_1 + 0x564) == '\0')) {
        if (*(char *)(param_1 + 0x5ac) != '\0') {
          if ((*(char *)(lVar17 + 0x1160) == '\0') ||
             ((((cVar6 = (char)*piVar1, cVar6 != '\x11' && (cVar6 != '\x12')) && (cVar6 != '\x18'))
              && (cVar6 != '\x19')))) {
            uVar8 = *(uint *)(param_1 + 0x5a0);
          }
          else {
            uVar8 = *(uint *)(param_1 + 0x5a0) >> 9;
          }
          *(int *)(param_1 + 0x594) = *(int *)(param_1 + 0x594) + uVar8;
        }
        *plVar2 = *plVar2 + (ulonglong)*(uint *)(param_1 + 0x5a0);
        if ((*(char *)(param_1 + 0x5ad) == '\0') && (1 < *(int *)(param_1 + 0x59c) - 3U)) {
          *(longlong *)(param_1 + 0x578) =
               *(longlong *)(param_1 + 0x578) + (ulonglong)*(uint *)(param_1 + 0x5a0);
        }
LAB_14001d9be:
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        return 0xc0000016;
      }
      _Src = (void *)(param_1 + 0x25c);
      uVar13 = (ulonglong)*(byte *)(param_1 + 0x26c);
      *(byte *)(piVar4 + 0xe) = *(byte *)(param_1 + 0x26c);
      memcpy(piVar4 + 10,_Src,uVar13);
      *(undefined8 *)(lVar17 + 0x308) = 0;
      if ((char)*piVar1 != '*') {
        cVar6 = *(char *)(param_1 + 0x564);
        SdbusWorkerClearHpi(param_1,_Src,uVar13,param_4);
        SdbusDebugPrint(0x200,"wp  %p DataCommandWorker COMPLETE, Info=0x%x",param_2,
                        (ulonglong)*(uint *)(param_2 + 0xb));
        return -(uint)(cVar6 != '\0') & 0xc0510001;
      }
      goto LAB_14001dd28;
    }
  }
  if ((piVar4[0x11] == 0) && ((char)*piVar1 == '5')) {
    uVar8 = piVar20[0x15];
    if (*(uint *)(param_1 + 0x58c) == 0) {
      uVar8 = -(uint)(*(uint *)(param_1 + 0x5a0) < 0x200) & *(uint *)(param_1 + 0x5a0) & 0x1ff |
              uVar8 & 0xf7fffe00;
    }
    else {
      uVar8 = (*(uint *)(param_1 + 0x58c) ^ uVar8) & 0x1ff ^ uVar8 | 0x8000000;
    }
    uVar8 = (*(int *)(param_1 + 0x594) << 9 ^ uVar8) & 0x3fffe00 ^ uVar8;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x594);
  }
  uVar13 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar13 == 0) {
    SdbusDebugPrint(0x200,"wp  %p  next tran: len=%d\taddr=0x%05x\tbcnt=%d\tbsz=%d\ttm=%d\tmbcnt=%d"
                    ,param_2,(ulonglong)*(uint *)(param_1 + 0x5a0));
  }
  else {
    SdbusDebugPrint(0x200,
                    "wp  %p  next tran: len=%d\taddr=0x%05x\tupperaddr=0x%05x\tbcnt=%d\tbsz=%d\ttm=%d\tmbcnt=%d"
                    ,param_2,(ulonglong)*(uint *)(param_1 + 0x5a0));
  }
  uVar13 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar13 == 0) {
    lVar17 = *param_2;
  }
  else {
    lVar17 = *param_2;
    cVar6 = SdbusRequiresUpperAddress(lVar17,(char *)piVar1);
    if ((cVar6 != '\0') && ((piVar4[0x11] != 0 || ((char)*piVar1 != '5')))) {
      uVar9 = *(undefined4 *)(param_1 + 0x598);
      SdbusWorkerSetStateCmdExecWithFlags
                (param_1,lVar17,(undefined8 *)piVar1,uVar8,*(undefined2 *)(param_1 + 0x590),
                 *(undefined2 *)(param_1 + 0x58c),*(undefined8 *)(param_1 + 0x578),
                 *(undefined8 *)(param_1 + 0x580),*(undefined4 *)(param_1 + 0x59c),
                 (byte)param_2[0x10]);
      *(undefined4 *)(param_1 + 0x208) = uVar9;
      goto LAB_14001e568;
    }
  }
  SdbusWorkerSetStateCmdExecWithFlags
            (param_1,lVar17,(undefined8 *)piVar1,uVar8,*(undefined2 *)(param_1 + 0x590),
             *(undefined2 *)(param_1 + 0x58c),*(undefined8 *)(param_1 + 0x578),
             *(undefined8 *)(param_1 + 0x580),*(undefined4 *)(param_1 + 0x59c),(byte)param_2[0x10]);
LAB_14001e568:
  *(undefined4 *)(param_1 + 0x1b4) = 3;
  return 0xc0000016;
}



===== SdbusEraseCommandWorker @ 14001e5a0 =====

undefined8 SdbusEraseCommandWorker(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = param_2[0x12];
  uVar3 = *param_2;
  iVar1 = *(int *)(param_1 + 0x1b4);
  if (iVar1 == 0) {
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,uVar3,(undefined8 *)&CmdDescSendEraseStart,*(undefined4 *)(lVar2 + 0x44),0,0,
               0,0,0,0);
    *(undefined4 *)(param_1 + 0x1b4) = 1;
  }
  else if (iVar1 == 1) {
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,uVar3,(undefined8 *)&CmdDescSendEraseEnd,*(undefined4 *)(lVar2 + 0x48),0,0,0,
               0,0,1);
    *(undefined4 *)(param_1 + 0x1b4) = 2;
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    SdbusWorkerSetStateCmdExecWithFlags
              (param_1,uVar3,(undefined8 *)&CmdDescSendErase,*(undefined4 *)(lVar2 + 0x40),0,0,0,0,0
               ,1);
    *(undefined4 *)(param_1 + 0x1b4) = 3;
  }
  return 0xc0000016;
}



===== SdbusScatterGatherListControl @ 14001e6a0 =====

void SdbusScatterGatherListControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  *(longlong *)(*param_4 + 0x29e8) = *(longlong *)(*param_4 + 0x29e8) + 1;
  *(undefined8 *)(param_4[2] + 0x580) = param_3;
  SdbusWorkerPushEvents(*param_4,0x10000,0,'\x01','\0');
  return;
}



===== ValidateDeviceCommand @ 14001e6e0 =====

undefined8 ValidateDeviceCommand(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  lVar1 = *(longlong *)(param_1 + 8);
  lVar2 = *(longlong *)(param_1 + 0x90);
  if ((*(uint *)(lVar1 + 0x28) & 1) != 0) {
    SdbusDebugPrint(1,"wp  %p ValidateDeviceCommand - invalid pdo state!",param_1,param_1);
    return 0xc0000184;
  }
  if ((*(uint *)(lVar1 + 0x34) & 2) == 0) {
    return 0;
  }
  if (*(int *)(lVar2 + 0x44) != 0) {
    return 0;
  }
  if (*(char *)(lVar2 + 0x40) == '5') {
    uVar4 = *(uint *)(lVar2 + 0x54) >> 0x1c & 7;
    if (uVar4 == *(byte *)(lVar1 + 0xc4)) {
      return 0;
    }
    if ((uVar4 != 0) || ((*(uint *)(lVar2 + 0x54) & 0x3fffe00) < 0x100000)) goto LAB_14001e7df;
    bVar5 = *(uint *)(lVar2 + 0x60) < 0x1f800;
    bVar6 = *(uint *)(lVar2 + 0x60) == 0x1f800;
  }
  else {
    if (*(char *)(lVar2 + 0x40) != '4') {
      return 0;
    }
    uVar4 = *(uint *)(lVar2 + 0x54);
    uVar3 = uVar4 >> 0x1c & 7;
    if (uVar3 == *(byte *)(lVar1 + 0xc4)) {
      return 0;
    }
    if (uVar3 != 0) goto LAB_14001e7df;
    uVar3 = uVar4 >> 9 & 0x1ffff;
    if ((0xef < uVar3) && (0x6ff < uVar3 - 0x100)) {
      return 0;
    }
    if (uVar3 < 0x100) {
      if (-1 < (int)uVar4) {
        return 0;
      }
      if ((*(uint *)(lVar1 + 0x34) & 1) != 0) {
        return 0;
      }
      goto LAB_14001e7df;
    }
    uVar4 = (uint)*(byte *)(lVar1 + 0xc4) * 0x100;
    if (uVar3 < uVar4) goto LAB_14001e7df;
    uVar4 = uVar4 + 0xff;
    bVar5 = uVar3 < uVar4;
    bVar6 = uVar3 == uVar4;
  }
  if (bVar5 || bVar6) {
    return 0;
  }
LAB_14001e7df:
  SdbusDebugPrint(1,"wp  %p ValidateDeviceCommand - cmd blocked!",param_1,param_1);
  return 0xc0000022;
}



===== SdbusValidateHpiCmd @ 14001e800 =====

undefined1 SdbusValidateHpiCmd(undefined8 param_1,longlong param_2)

{
  char cVar1;
  int *piVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (*(int *)(param_2 + 0x18) != 3) {
    return 0;
  }
  piVar2 = *(int **)(param_2 + 0x90);
  uVar3 = Feature_SupportForSDUltraCapacity__private_IsEnabledDeviceUsageNoInline();
  if (*piVar2 != 2) {
    if ((int)uVar3 == 0) {
      return 0;
    }
    if (*piVar2 != 6) {
      return 0;
    }
  }
  cVar1 = (char)piVar2[0x10];
  if (cVar1 == '\x06') {
    uVar4 = (uint)piVar2[0x15] >> 0x10 & 0xff;
    if (uVar4 == 0x20) {
      return 1;
    }
    if (uVar4 == 0x21) {
      return 0;
    }
    if (uVar4 == 0x22) {
      bVar5 = (char)((uint)piVar2[0x15] >> 8) == '\x03';
    }
    else {
      if (uVar4 == 0xa4) {
        return 1;
      }
      bVar5 = uVar4 == 0xa5;
    }
  }
  else {
    if (cVar1 == '\x18') {
      return 1;
    }
    if (cVar1 == '\x19') {
      return 1;
    }
    bVar5 = cVar1 == '&';
  }
  if (bVar5) {
    return 1;
  }
  return 0;
}



===== SdbusTelemetryCollectPerfData @ 14001e890 =====

undefined8 SdbusTelemetryCollectPerfData(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (((byte)(*(char *)(param_1 + 0x30) - 0x11U) < 2) ||
     ((byte)(*(char *)(param_1 + 0x30) - 0x18U) < 2)) {
    iVar2 = *(int *)(param_1 + 0x38);
    lVar3 = KeQueryInterruptTimePrecise(&local_res8);
    uVar9 = lVar3 - *(longlong *)(param_1 + 0x70);
    uVar6 = 0;
    do {
      if (uVar9 < (ulonglong)(&LatencyBucketLevels)[uVar6]) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 5);
    uVar8 = 0;
    uVar10 = (ulonglong)((uint)*(ushort *)(param_1 + 0x2c) * (uint)*(ushort *)(param_1 + 0x2e));
    do {
      if (uVar10 < (ulonglong)(&SizeBucketLevels)[uVar8]) break;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 3);
    if (((*(longlong *)(param_1 + 0x10) != 0) &&
        (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x568), lVar3 != 0)) &&
       (lVar3 = *(longlong *)(lVar3 + 8), lVar3 != 0)) {
      if (iVar2 == 1) {
        lVar4 = 0x1a0;
        lVar7 = 0x198;
      }
      else if (iVar2 == 2) {
        lVar4 = 400;
        lVar7 = 0x188;
      }
      else {
        lVar4 = 0x1b0;
        lVar7 = 0x1a8;
      }
      LOCK();
      plVar1 = (longlong *)(lVar7 + 0x600 + lVar3);
      *plVar1 = *plVar1 + uVar10;
      UNLOCK();
      LOCK();
      plVar1 = (longlong *)(lVar4 + 0x600 + lVar3);
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      LOCK();
      plVar1 = (longlong *)(lVar3 + 0x600 + ((ulonglong)(iVar2 != 1) + (uVar8 + uVar6 * 4) * 2) * 8)
      ;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      uVar5 = (uint)(uVar9 / 10000);
      if (*(uint *)(lVar3 + 0x780) < uVar5) {
        LOCK();
        if (*(uint *)(lVar3 + 0x780) == *(uint *)(lVar3 + 0x780)) {
          *(uint *)(lVar3 + 0x780) = uVar5;
        }
        UNLOCK();
      }
    }
  }
  return 0;
}



===== SdbusTelemetryGetCorrelationId @ 14001e9c0 =====

undefined4 SdbusTelemetryGetCorrelationId(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) - 2U < 2) {
    uVar1 = *(undefined4 *)(param_1 + 0x44);
  }
  else if (*(int *)(param_1 + 0x1c) == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x74);
  }
  return uVar1;
}



===== SdbusTelemetryIOErrorBatched @ 14001e9e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SdbusTelemetryIOErrorBatched
          (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined8 uVar3;
  undefined1 auStackY_c8 [32];
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar3 = param_2;
  SdbusDebugPrint(4,"tl                   SDBus_BatchedIOError: UnloggedErrorCount:%llu",param_2,
                  param_4);
  if (5 < DAT_14002a4c8) {
    uVar2 = _tlgKeywordOn();
    if ((char)uVar2 != '\0') {
      local_58 = &local_98;
      local_48 = &local_90;
      local_50 = 8;
      local_40 = 8;
      local_98 = param_1;
      local_90 = param_2;
      uVar1 = SdbusTelemetryGetCorrelationId(param_3);
      local_88[0] = CONCAT44(extraout_var,uVar1);
      local_38 = local_88;
      local_30 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(param_3,&DAT_140027f11,uVar3,param_4,5,local_78);
    }
  }
  return 0;
}



===== _tlgDefineProvider_annotation__TlgSdbusTelemetryProviderProv @ 14001eac4 =====

void _tlgDefineProvider_annotation__TlgSdbusTelemetryProviderProv(void)

{
  return;
}



===== __GSHandlerCheck @ 14001ead8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001eafc =====

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



===== __security_check_cookie @ 14001eb70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001ebb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001ebe0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001ebe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001ec10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 14001ec80 =====

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



===== memset @ 14001ef80 =====

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



===== __memset_repmovs @ 14001f0c0 =====

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



===== __memset_query @ 14001f140 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001f1c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001f300 =====

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



===== __memset_spec_plain @ 14001f380 =====

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



===== memcmp @ 14001f4a0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14001f4e3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14001f554;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14001f550:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f554;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001f54c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f550;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001f54c;
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
LAB_14001f554:
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
LAB_14001f4e3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== wil_UninitializeFeatureStaging @ 14002d008 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14002d060 =====

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
      goto LAB_14002d0bd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14002d0bd;
    }
  }
  uVar1 = 0x206;
LAB_14002d0bd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14002d0c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_SupportForSDUltraCapacity__private_descriptor);
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
  ppuVar2 = &Feature_SupportForSDUltraCapacity__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14002d180 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14002d1b8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002d23a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002d23a;
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
LAB_14002d23a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14002d290 =====

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
      ppuVar3 = &Feature_SupportForSDUltraCapacity__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14002d2f0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002d30c =====

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
  ppuVar3 = &Feature_SupportForSDUltraCapacity__private_descriptor;
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



===== wil_RtlStagingConfig_QueryFeatureState @ 14002d3c0 =====

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



===== entry @ 14002f010 =====

void entry(undefined8 param_1,uint *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002f044 =====

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



===== wil_InitializeFeatureStaging @ 14002f078 =====

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
    ppuVar4 = &Feature_SupportForSDUltraCapacity__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002f168 =====

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
  ppuVar3 = &Feature_SupportForSDUltraCapacity__private_descriptor;
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


