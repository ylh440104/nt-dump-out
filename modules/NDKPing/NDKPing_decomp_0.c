
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



===== DriverEntry @ 1c0001020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  _DAT_1c000c3c8 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c000c3b0 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  _DAT_1c000c3c0 = 0;
  DAT_1c000c3a8 = &WPP_ThisDir_CTLGUID_RdmaPingGuid;
  _DAT_1c000c3e0 = 0;
  _DAT_1c000c3e8 = 0;
  WppLoadTracingSupport();
  _DAT_1c000c3c0 = 0;
  WppInitKm(param_1,param_2);
  memset((void *)(param_1 + 0x70),0,0xe0);
  *(code **)(param_1 + 0x68) = DriverUnload;
  *(code **)(param_1 + 0x70) = RdmaPingDeviceOpen;
  *(code **)(param_1 + 0x80) = RdmaPingDeviceClose;
  *(code **)(param_1 + 0x100) = DummyIrpHandler;
  *(code **)(param_1 + 0xe0) = RdmaPingDeviceControl;
  RtlInitUnicodeString(&local_28,L"\\Device\\NDKPing");
  pwVar2 = L"\\DosDevices\\NDKPing";
  RtlInitUnicodeString(&local_18);
  iVar1 = WdmlibIoCreateDeviceSecure(param_1,pwVar2,&local_28);
  if (((iVar1 == 0) && (iVar1 = IoCreateSymbolicLink(&local_18,&local_28), iVar1 == 0)) &&
     (Driver = param_1, iVar1 = NdkInitialize(), iVar1 == 0)) {
    return 0;
  }
  DriverUnload(param_1);
  return iVar1;
}



===== DriverUnload @ 1c0001190 =====

void DriverUnload(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  NdkDeInitialize();
  RtlInitUnicodeString(&local_18,L"\\DosDevices\\NDKPing");
  IoDeleteSymbolicLink(&local_18);
  if (DAT_1c000c2c8 != 0) {
    IoDeleteDevice();
    DAT_1c000c2c8 = 0;
  }
  WppCleanupKm(param_1);
  return;
}



===== DummyIrpHandler @ 1c0001210 =====

undefined8 DummyIrpHandler(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== RdmaPingDeviceClose @ 1c0001240 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RdmaPingDeviceClose(undefined8 param_1,longlong param_2)

{
  LOCK();
  _DAT_1c000c2d0 = _DAT_1c000c2d0 + -1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== RdmaPingDeviceControl @ 1c0001280 =====

int RdmaPingDeviceControl(undefined8 param_1,longlong param_2)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = *(short **)(param_2 + 0x18);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (iVar2 == 0x220404) {
    if ((char)psVar1[0x14] == '\0') {
      iVar2 = RdmaTestSendByReceiveTimeClient(psVar1);
    }
    else {
      iVar2 = RdmaTestSendByReceiveTimeServer((longlong)psVar1);
    }
    goto LAB_1c0001353;
  }
  if (iVar2 == 0x220408) {
    if ((char)psVar1[0x14] == '\0') {
      iVar2 = RdmaTestReadByCompletionTimeClient(psVar1);
      goto LAB_1c0001353;
    }
  }
  else if (iVar2 == 0x22040c) {
    if ((char)psVar1[0x14] == '\0') {
      iVar2 = RdmaTestReadByMemoryUpdateTimeClient(psVar1);
      goto LAB_1c0001353;
    }
  }
  else {
    if (iVar2 != 0x220410) {
      if (iVar2 == 0x220414) {
        if ((char)psVar1[0x14] == '\0') {
          iVar2 = RdmaTestWriteByMemoryUpdateTimeClient(psVar1);
        }
        else {
          iVar2 = RdmaTestWriteByMemoryUpdateTimeServer((longlong)psVar1);
        }
      }
      else if (iVar2 == 0x220418) {
        if ((char)psVar1[0x14] == '\0') {
          iVar2 = RdmaHeartbeatClient(psVar1);
        }
        else {
          iVar2 = RdmaHeartbeatServer((longlong)psVar1);
        }
      }
      else {
        iVar2 = -0x3ffffff0;
      }
      goto LAB_1c0001353;
    }
    if ((char)psVar1[0x14] == '\0') {
      iVar2 = RdmaTestWriteByCompletionTimeClient(psVar1);
      goto LAB_1c0001353;
    }
  }
  iVar2 = RdmaTestReadWriteByCompletionTimeServer((longlong)psVar1);
LAB_1c0001353:
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== RdmaPingDeviceOpen @ 1c0001380 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RdmaPingDeviceOpen(undefined8 param_1,longlong param_2)

{
  LOCK();
  _DAT_1c000c2d0 = _DAT_1c000c2d0 + 1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== WppClassicProviderCallback @ 1c00013c0 =====

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



===== CompletionCallback @ 1c0001420 =====

void CompletionCallback(undefined4 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x18) = param_1;
  KeSetEvent(param_2,0,0);
  return;
}



===== RdmaCheckForSqWrErrorCompletions @ 1c000144c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaCheckForSqWrErrorCompletions(longlong param_1)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  iVar4 = 0;
  bVar2 = false;
  while (uVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x28) + 0x20))
                           (*(longlong *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x100),0x80),
        uVar3 != 0) {
    lVar5 = 0;
    uVar6 = (ulonglong)uVar3;
    do {
      iVar1 = *(int *)(lVar5 + *(longlong *)(param_1 + 0x100));
      if ((iVar1 < 0) && (!bVar2)) {
        bVar2 = true;
        RdmaQueueDisconnectWorkItem(param_1,'\0');
        iVar4 = iVar1;
      }
      lVar5 = lVar5 + 0x18;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return iVar4;
}



===== RdmaDoPing @ 1c00014e8 =====

ulonglong RdmaDoPing(longlong param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  longlong *_Dst;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  uint uVar9;
  longlong *plVar10;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar11;
  uint local_58 [2];
  longlong local_50 [3];
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_58[0] = 0;
  local_50[0] = 0;
  cVar1 = KeGetCurrentIrql();
  local_50[2] = 0x10;
  local_50[1] = 1;
  _Dst = (longlong *)ExAllocatePool3(0x40,400000,0x616d6452,local_50 + 1,CONCAT44(uVar11,1));
  if (_Dst == (longlong *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    memset(_Dst,0,400000);
    cVar1 = KfRaiseIrql(2);
    uVar9 = 0;
    plVar10 = _Dst;
    do {
      lVar4 = KeQueryPerformanceCounter(local_50);
      if (*(int *)(param_2 + 0x28) == 2) {
        uVar3 = NdkRead(param_1,param_2,0);
      }
      else {
        uVar3 = NdkWrite(param_1,param_2,0);
      }
      uVar7 = (ulonglong)uVar3;
      if (uVar3 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x13,
                             &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,
                             (char)*(undefined4 *)(param_2 + 0x28),(char)uVar3);
        }
        goto LAB_1c00016f5;
      }
      uVar5 = RdmaPollForCompletionWithTimeout(param_1,(int *)local_58);
      uVar7 = uVar5 & 0xffffffff;
      if (((int)uVar5 != 0) || (uVar7 = (ulonglong)local_58[0], local_58[0] != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00016f5;
        uVar8 = 0x14;
        goto LAB_1c0001686;
      }
      lVar6 = KeQueryPerformanceCounter(0);
      uVar9 = uVar9 + 1;
      lVar4 = (lVar6 - lVar4) * 1000000;
      lVar6 = lVar4 % local_50[0];
      *plVar10 = lVar4 / local_50[0];
      plVar10 = plVar10 + 1;
    } while (uVar9 < 50000);
    KeLowerIrql(cVar1);
    uVar9 = RdmaPrintTestDataToFile(_Dst,lVar6,(ulonglong)param_3,param_4);
    uVar7 = (ulonglong)uVar9;
    if ((uVar9 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar8 = 0x15;
LAB_1c0001686:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar8,
                        &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)uVar7);
    }
  }
LAB_1c00016f5:
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != cVar1) {
    KeLowerIrql(cVar1);
  }
  return uVar7;
}



===== RdmaDoWarmup @ 1c0001738 =====

ulonglong RdmaDoWarmup(undefined8 *param_1,int param_2)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  void *_Dst;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined2 uVar8;
  uint local_res18 [2];
  int *local_res20;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar9;
  undefined4 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_res20 = (int *)0x0;
  local_res18[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_48,0,0);
  local_4c = 0;
  local_50 = 0x10;
  local_58 = 1;
  _Dst = (void *)ExAllocatePool3(0x40,0x400,0x616d6452,&local_58,CONCAT44(uVar9,1));
  if (_Dst == (void *)0x0) {
    return 0xc000009a;
  }
  puVar4 = (undefined8 *)IoAllocateMdl(_Dst,0x400,0,0,0);
  if (puVar4 == (undefined8 *)0x0) {
    uVar6 = 0xc000009a;
    goto LAB_1c00019fe;
  }
  MmBuildMdlForNonPagedPool(puVar4);
  memset(_Dst,0,0x400);
  if (param_2 == 2) {
    uVar5 = RdmaBuildReadWRForOperation
                      ((undefined8 *)param_1[5],puVar4,0x400,*param_1,*(undefined4 *)(param_1 + 1),
                       &local_48,CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
                       &local_res20);
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
LAB_1c00018f1:
      piVar2 = local_res20;
      uVar7 = 0;
      do {
        lVar1 = *(longlong *)(piVar2 + 2);
        if (*(int *)(lVar1 + 0x28) == 2) {
          uVar3 = NdkRead(param_1[5],lVar1,0);
        }
        else {
          uVar3 = NdkWrite(param_1[5],lVar1,0);
        }
        uVar6 = (ulonglong)uVar3;
        if (uVar3 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xf,
                               &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,
                               (char)*(undefined4 *)(*(longlong *)(piVar2 + 2) + 0x28),(char)uVar3);
          }
          break;
        }
        uVar5 = RdmaPollForCompletionWithTimeout(param_1[5],(int *)local_res18);
        uVar6 = uVar5 & 0xffffffff;
        if (((int)uVar5 != 0) || (uVar6 = (ulonglong)local_res18[0], local_res18[0] != 0)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar8 = 0x10;
            goto LAB_1c0001872;
          }
          break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < 1000);
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0xc;
LAB_1c0001872:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar8,
                        &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)uVar6);
    }
  }
  else if (param_2 == 3) {
    uVar5 = RdmaBuildWriteWRForOperation
                      ((undefined8 *)param_1[5],puVar4,0x400,*param_1,*(undefined4 *)(param_1 + 1),
                       &local_48,CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),
                       &local_res20);
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) goto LAB_1c00018f1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0xd;
      goto LAB_1c0001872;
    }
  }
  else {
    uVar6 = 0xc0000001;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00019fe;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xe,
                     &WPP_0095b327a71d387719acd044e1a89c49_Traceguids);
  }
  if (local_res20 != (int *)0x0) {
    RdmaFreeOperation(local_res20);
  }
LAB_1c00019fe:
  ExFreePoolWithTag(_Dst,0x616d6452);
  if (puVar4 != (undefined8 *)0x0) {
    IoFreeMdl(puVar4);
  }
  return uVar6;
}



===== RdmaOpenLogFile @ 1c0001a48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaOpenLogFile(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStackY_2b8 [32];
  undefined8 local_258;
  undefined1 *local_250;
  undefined1 local_248 [528];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2b8;
  local_258 = 0x2080000;
  local_250 = local_248;
  RtlAppendUnicodeToString(&local_258,L"\\DosDevices\\");
  RtlAppendUnicodeToString(&local_258,param_4);
  *param_2 = 0x30;
  *(undefined8 *)(param_2 + 2) = 0;
  param_2[6] = 0x240;
  *(undefined8 **)(param_2 + 4) = &local_258;
  *(undefined8 *)(param_2 + 8) = 0;
  *(undefined8 *)(param_2 + 10) = 0;
  iVar1 = ZwCreateFile(param_1,0xc0000004,param_2,param_3);
  if ((iVar1 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x20,
                      &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== RdmaPollForCompletionWithTimeout @ 1c0001b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RdmaPollForCompletionWithTimeout(longlong param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  *param_2 = 0;
  lVar1 = _DAT_fffff78000000014;
  do {
    if (20000000 < _DAT_fffff78000000014 - lVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0x102;
      }
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x12,
                        &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,2);
      return 0x102;
    }
    iVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x28) + 0x20))
                      (*(longlong *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x100),0x80);
  } while (iVar2 == 0);
  if (iVar2 == 1) {
    if (**(int **)(param_1 + 0x100) < 0) {
      *param_2 = **(int **)(param_1 + 0x100);
    }
  }
  else {
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== RdmaPollForReceive @ 1c0001c6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 RdmaPollForReceive(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  code *pcVar4;
  
  lVar2 = _DAT_fffff78000000014;
  do {
    if (20000000 < _DAT_fffff78000000014 - lVar2) {
      return 0x102;
    }
    lVar1 = *(longlong *)(param_1[6] + 0x28);
    if ((*(byte *)(*param_1 + 0x30) & 2) == 0) {
      pcVar4 = *(code **)(lVar1 + 0x20);
    }
    else {
      pcVar4 = *(code **)(lVar1 + 0x30);
    }
    iVar3 = (*pcVar4)(param_1[6],param_1[0x1f],*(undefined2 *)((longlong)param_1 + 0xdc));
  } while (iVar3 == 0);
  return 0;
}



===== RdmaPrintPingResultsToFile @ 1c0001cfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaPrintPingResultsToFile(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined1 auStackY_188 [32];
  longlong local_130 [9];
  char local_e8 [208];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_188;
  local_130[0] = 0;
  local_130[1] = 0;
  local_130[2] = 0;
  local_130[3] = 0;
  local_130[4] = 0;
  local_130[5] = 0;
  local_130[6] = 0;
  local_130[7] = 0;
  local_130[8] = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    return -0x3ffffe7c;
  }
  iVar2 = RdmaOpenLogFile(local_130,(undefined4 *)(local_130 + 3),local_130 + 1,param_2);
  if (iVar2 < 0) goto LAB_1c0001ebb;
  uVar3 = RtlStringCbPrintfA(local_e8,200,"%d bytes of data successfully transferred\r\n\r\n",0x8000
                            );
  iVar2 = (int)uVar3;
  if (iVar2 == 0) {
    lVar5 = 200;
    pcVar4 = local_e8;
    do {
      if (*pcVar4 == '\0') break;
      pcVar4 = pcVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    if (lVar5 == 0) {
      iVar2 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ebb;
      uVar6 = 0x1e;
    }
    else {
      iVar2 = ZwWriteFile(local_130[0],0,0,0);
      if (iVar2 == 0) {
        memset(local_e8,0,200);
        iVar2 = 0;
        goto LAB_1c0001ebb;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ebb;
      uVar6 = 0x1f;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001ebb;
    uVar6 = 0x1d;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar6,
                    &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)iVar2);
LAB_1c0001ebb:
  if (local_130[0] != 0) {
    ZwClose();
  }
  return iVar2;
}



===== RdmaPrintTestDataToFile @ 1c0001efc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaPrintTestDataToFile(void *param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined1 auStackY_298 [32];
  longlong local_240 [8];
  undefined4 local_200;
  uint local_1f8 [56];
  char local_118 [208];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_298;
  local_240[0] = 0;
  local_240[7] = 0;
  local_200 = 0;
  local_1f8[1] = 0x37;
  local_1f8[0] = 0x19;
  local_1f8[3] = 99;
  local_1f8[4] = 99;
  local_1f8[5] = 99;
  local_1f8[6] = 99;
  local_1f8[7] = 99;
  local_1f8[0xd] = 99;
  local_240[1] = 0;
  local_240[2] = 0;
  local_1f8[2] = 0x4b;
  local_240[3] = 0;
  local_240[4] = 0;
  local_1f8[0xc] = 9;
  local_240[5] = 0;
  local_240[6] = 0;
  local_1f8[0xe] = 999;
  local_1f8[8] = 0;
  local_1f8[9] = 0;
  local_1f8[10] = 0;
  local_1f8[0xb] = 0;
  local_1f8[0xf] = 9999;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    return -0x3ffffe7c;
  }
  iVar2 = RdmaOpenLogFile(local_240,(undefined4 *)(local_240 + 3),local_240 + 1,param_4);
  if (iVar2 == 0) {
    qsort(param_1,50000,8,TimeSamplesCompare);
    local_1f8[0x10] = 0x30d3;
    local_1f8[0x11] = 0;
    local_1f8[0x1c] = 49999;
    local_1f8[0x1d] = 0;
    local_1f8[0x1e] = 49999;
    local_1f8[0x1f] = 0;
    local_1f8[0x12] = 0x6b6b;
    local_1f8[0x13] = 0;
    local_1f8[0x14] = 0x927b;
    local_1f8[0x15] = 0;
    local_1f8[0x16] = 0xc15b;
    local_1f8[0x17] = 0;
    local_1f8[0x18] = 0xc31d;
    local_1f8[0x19] = 0;
    local_1f8[0x1a] = 0xc34a;
    local_1f8[0x1b] = 0;
    uVar3 = RtlStringCbPrintfA(local_118,200,"Transfer size: %d. Number of iterations: %d\r\n\r\n",
                               param_3 & 0xffffffff);
    iVar2 = (int)uVar3;
    if (iVar2 == 0) {
      lVar5 = 200;
      pcVar4 = local_118;
      do {
        if (*pcVar4 == '\0') break;
        pcVar4 = pcVar4 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      if (lVar5 == 0) {
        iVar2 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00022d5;
        uVar8 = 0x18;
      }
      else {
        iVar2 = ZwWriteFile(local_240[0],0,0,0);
        if (iVar2 == 0) {
          memset(local_118,0,200);
          uVar7 = 0;
          lVar5 = 0;
          do {
            uVar3 = RtlStringCbPrintfA(local_118,200,"p%lu.%lu%%: %16llu\r\n",
                                       (ulonglong)*(uint *)((longlong)local_1f8 + lVar5));
            iVar2 = (int)uVar3;
            if (iVar2 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0x1a;
                goto LAB_1c00022ac;
              }
              break;
            }
            lVar6 = 200;
            pcVar4 = local_118;
            do {
              if (*pcVar4 == '\0') break;
              pcVar4 = pcVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
            if (lVar6 == 0) {
              iVar2 = -0x3ffffff3;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0x1b;
                goto LAB_1c00022ac;
              }
              break;
            }
            iVar2 = ZwWriteFile(local_240[0],0,0,0);
            if (iVar2 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0x1c;
                goto LAB_1c00022ac;
              }
              break;
            }
            memset(local_118,0,200);
            uVar7 = uVar7 + 1;
            lVar5 = lVar5 + 4;
          } while (uVar7 < 8);
          goto LAB_1c00022d5;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00022d5;
        uVar8 = 0x19;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00022d5;
      uVar8 = 0x17;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00022d5;
    uVar8 = 0x16;
  }
LAB_1c00022ac:
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar8,
                    &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)iVar2);
LAB_1c00022d5:
  if (local_240[0] != 0) {
    ZwClose();
  }
  return iVar2;
}



===== RdmaRepostReceive @ 1c0002318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaRepostReceive(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  *(undefined4 *)(lVar1 + 0x18) = *(undefined4 *)(param_2 + 4);
  iVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) + 0x20))
                    (*(longlong *)(param_1 + 0x40),lVar1,*(undefined8 *)(lVar1 + 0x10),
                     *(undefined2 *)(lVar1 + 0x1c));
  if (iVar2 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x11,
                        &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)iVar2);
    }
    ExReleaseRundownProtectionEx(param_1 + 0x68,1);
    RdmaFreeLamBuffer(lVar1);
  }
  return iVar2;
}



===== RdmaSendMRInfo @ 1c00023cc =====

ulonglong RdmaSendMRInfo(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  longlong *plVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar9;
  undefined8 uVar8;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  uStack_3c = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,0,0);
  local_4c = 0;
  local_58 = 1;
  local_50 = 0x10;
  puVar2 = (undefined4 *)ExAllocatePool3(0x40,0x14,0x616d6452,&local_58,CONCAT44(uVar9,1));
  if (puVar2 == (undefined4 *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    uVar8 = 0;
    uVar7 = 0;
    puVar3 = (undefined8 *)IoAllocateMdl(puVar2,0x14,0);
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      MmBuildMdlForNonPagedPool(puVar3);
      plVar1 = *(longlong **)(param_1 + 0x28);
      *puVar2 = 0;
      local_res20[0] = 0;
      *(undefined8 *)(puVar2 + 1) = param_2;
      *(ulonglong *)(puVar2 + 3) = CONCAT44(uStack_3c,param_3);
      local_48 = param_2;
      uStack_40 = param_3;
      uVar4 = RdmaSend(plVar1,puVar3,0x14,uVar7,uVar8,&local_38,in_stack_ffffffffffffff98);
      uVar6 = 0;
      if ((int)uVar4 == 0x103) {
        uVar4 = RdmaPollForCompletionWithTimeout(*(longlong *)(param_1 + 0x28),(int *)local_res20);
        uVar6 = local_res20[0];
      }
      uVar5 = uVar4 & 0xffffffff;
      if ((((int)uVar4 != 0) || (uVar5 = (ulonglong)uVar6, uVar6 != 0)) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xb,
                          &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)uVar5);
      }
    }
    ExFreePoolWithTag(puVar2,0x616d6452);
    if (puVar3 != (undefined8 *)0x0) {
      IoFreeMdl(puVar3);
    }
  }
  return uVar5;
}



===== ReceiveCallback @ 1c0002590 =====

void ReceiveCallback(int *param_1,int *param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (3 < param_3) {
    if (*param_2 == 0) {
      uVar1 = *(undefined8 *)(param_2 + 3);
      *(undefined8 *)param_1 = *(undefined8 *)(param_2 + 1);
      *(undefined8 *)(param_1 + 2) = uVar1;
    }
    else if (*param_2 != 1) {
      return;
    }
    KeSetEvent(param_1 + 4,0,0);
  }
  return;
}



===== RtlStringCbPrintfA @ 1c00025d4 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== SendAckMessage @ 1c0002648 =====

ulonglong SendAckMessage(longlong *param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  KeInitializeEvent(&local_28,0,0);
  local_2c = 0;
  local_38 = 1;
  local_30 = 0x10;
  puVar1 = (undefined4 *)ExAllocatePool3(0x40,4,0x616d6452,&local_38,CONCAT44(uVar7,1));
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar6 = 0;
    uVar5 = 0;
    puVar2 = (undefined8 *)IoAllocateMdl(puVar1,4,0);
    if (puVar2 == (undefined8 *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      MmBuildMdlForNonPagedPool(puVar2);
      *puVar1 = 1;
      uVar3 = RdmaSend(param_1,puVar2,4,uVar5,uVar6,&local_28,in_stack_ffffffffffffffb8);
      if ((int)uVar3 == 0x103) {
        KeWaitForSingleObject(&local_28,0,0,0,0);
        uVar3 = uStack_10;
      }
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        uVar4 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,10,
                          &WPP_0095b327a71d387719acd044e1a89c49_Traceguids,(char)uVar3);
      }
    }
    ExFreePoolWithTag(puVar1,0x616d6452);
    if (puVar2 != (undefined8 *)0x0) {
      IoFreeMdl(puVar2);
    }
  }
  return uVar4;
}



===== TimeSamplesCompare @ 1c00027e0 =====

ulonglong TimeSamplesCompare(ulonglong *param_1,ulonglong *param_2)

{
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (ulonglong)(*param_1 != *param_2);
}



===== WPP_RECORDER_SF_ @ 1c0002800 =====

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



===== WPP_RECORDER_SF_d @ 1c00028d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c00029d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== _guard_check_icall @ 1c0002b00 =====

void _guard_check_icall(void)

{
  return;
}



===== RdmaHeartbeatClient @ 1c0002b0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaHeartbeatClient(short *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  char cVar12;
  undefined1 auStackY_e8 [32];
  undefined8 *puVar13;
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  int *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8 = (int *)0x0;
  local_a0 = 0;
  cVar12 = '\0';
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  KeInitializeEvent(&local_58,1);
  uVar10 = 0;
  KeInitializeEvent(&local_88,0);
  iVar3 = RdmaPingEstablishConnectionClient((longlong)&local_68,param_1,uVar10);
  if (iVar3 == 0) {
    (**(code **)(*(longlong *)(plStack_40[6] + 0x28) + 0x18))(plStack_40[6],1);
    (**(code **)(*(longlong *)(plStack_40[7] + 0x28) + 0x18))(plStack_40[7],1);
    local_8c = 0;
    local_98 = 1;
    local_90 = 0x10;
    puVar4 = (undefined4 *)ExAllocatePool3(0x40,0x8000,0x616d6452);
    if (puVar4 == (undefined4 *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      puVar13 = (undefined8 *)0x0;
      uVar10 = 0;
      puVar5 = (undefined8 *)IoAllocateMdl(puVar4,0x8000,0);
      if (puVar5 == (undefined8 *)0x0) {
        iVar3 = -0x3fffff66;
      }
      else {
        MmBuildMdlForNonPagedPool(puVar5);
        uVar7 = 4;
        *puVar4 = 1;
        pcVar9 = (char *)(puVar4 + 1);
        do {
          cVar2 = (char)uVar7;
          uVar7 = uVar7 + 1;
          *pcVar9 = cVar2 + '0';
          pcVar9 = pcVar9 + 1;
        } while (uVar7 < 0x8000);
        cVar2 = ExAcquireRundownProtectionEx(plStack_40 + 0xc,1);
        if (cVar2 == '\0') {
          iVar3 = -0x3fffff1b;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x2e,
                              &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,0xe5);
          }
        }
        else {
          local_a0 = 0xffffffffff676980;
          uVar7 = 0;
          do {
            uVar6 = RdmaBuildSendWRForOperation
                              (plStack_40,puVar5,0x8000,uVar10,puVar13,&local_88,
                               CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),
                               &local_a8);
            piVar1 = local_a8;
            iVar3 = (int)uVar6;
            if (iVar3 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x2f;
LAB_1c0002e2f:
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar11,
                                  &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar3);
              }
              goto LAB_1c0002e58;
            }
            RdmaQueueSQWrs(plStack_40,*(longlong **)(local_a8 + 2),0);
            puVar13 = &local_a0;
            uVar10 = 0;
            puVar8 = &local_58;
            iVar3 = KeWaitForSingleObject(puVar8,0,0);
            if (iVar3 == 0) {
              iVar3 = RdmaPrintPingResultsToFile(puVar8,param_1 + 0x18);
              if (iVar3 != 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar11 = 0x30;
                  goto LAB_1c0002e2f;
                }
                goto LAB_1c0002e58;
              }
            }
            else if (iVar3 == 0x102) {
              cVar12 = cVar12 + '\x01';
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x19);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x31,
                               &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,0x19,cVar12);
          }
          iVar3 = 0;
LAB_1c0002e58:
          ExReleaseRundownProtectionEx(plStack_40 + 0xc,1);
          if (piVar1 != (int *)0x0) {
            RdmaFreeOperation(piVar1);
          }
        }
      }
      ExFreePoolWithTag(puVar4,0x616d6452);
      if (puVar5 != (undefined8 *)0x0) {
        IoFreeMdl(puVar5);
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x2d,
                      &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar3);
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_40);
  }
  return iVar3;
}



===== RdmaPingEstablishConnectionClient @ 1c0002eec =====

int RdmaPingEstablishConnectionClient(longlong param_1,short *param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = RdmaCreateClientSocket
                    (*(NET_IFINDEX *)(param_2 + 0x10),param_2,param_3,param_1,
                     (undefined8 *)(param_1 + 0x28));
  if (iVar1 == 0) {
    iVar1 = RdmaConnect(*(longlong **)(param_1 + 0x28),param_2,param_2 + 8);
    if (iVar1 == 0) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0xb;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 10;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar2,
                    &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar1);
  return iVar1;
}



===== RdmaTestReadByCompletionTimeClient @ 1c0002fa4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaTestReadByCompletionTimeClient(short *param_1)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 auStackY_118 [32];
  undefined8 in_stack_ffffffffffffff18;
  int *local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  longlong *plStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  piVar6 = (int *)0x0;
  local_d8 = (int *)0x0;
  puVar5 = (undefined8 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  lVar4 = 0;
  cVar1 = '\0';
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  KeInitializeEvent(&local_58,0);
  uVar7 = 0;
  KeInitializeEvent(&local_c0,0);
  iVar2 = RdmaPingEstablishConnectionClient((longlong)&local_68,param_1,uVar7);
  if (iVar2 < 0) goto LAB_1c00032b3;
  (**(code **)(*(longlong *)(plStack_40[6] + 0x28) + 0x18))(plStack_40[6],1);
  KeWaitForSingleObject(&local_58,0,0,0);
  KeClearEvent(&local_58);
  cVar1 = ExAcquireRundownProtectionEx(plStack_40 + 0xc,1);
  if (cVar1 == '\0') {
    iVar2 = -0x3fffff1b;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00032b3;
    uVar8 = 0x13;
  }
  else {
    local_98 = local_68;
    uStack_90 = uStack_60;
    local_88 = local_58;
    uStack_80 = uStack_50;
    local_78 = local_48;
    plStack_70 = plStack_40;
    uVar3 = RdmaDoWarmup(&local_98,2);
    iVar2 = (int)uVar3;
    if (iVar2 == 0) {
      uVar9 = 1;
      do {
        piVar6 = (int *)0x0;
        local_c4 = 0;
        local_d0 = 1;
        local_c8 = 0x10;
        lVar4 = ExAllocatePool3(0x40,uVar9,0x616d6452,&local_d0);
        if (lVar4 == 0) {
          puVar5 = (undefined8 *)0x0;
LAB_1c00032ae:
          iVar2 = -0x3fffff66;
          goto LAB_1c00032b3;
        }
        puVar5 = (undefined8 *)IoAllocateMdl(lVar4,uVar9,0,0);
        if (puVar5 == (undefined8 *)0x0) goto LAB_1c00032ae;
        MmBuildMdlForNonPagedPool(puVar5);
        uVar3 = RdmaBuildReadWRForOperation
                          (plStack_40,puVar5,uVar9,local_68,(undefined4)uStack_60,&local_c0,
                           in_stack_ffffffffffffff18,&local_d8);
        piVar6 = local_d8;
        iVar2 = (int)uVar3;
        if (iVar2 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x15,
                              &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar3);
          }
          piVar6 = local_d8;
          goto LAB_1c00032b3;
        }
        uVar3 = RdmaDoPing((longlong)plStack_40,*(longlong *)(local_d8 + 2),uVar9,param_1 + 0x18);
        iVar2 = (int)uVar3;
        if (iVar2 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c00032b3;
          uVar8 = 0x16;
          goto LAB_1c00030bd;
        }
        ExFreePoolWithTag(lVar4,0x616d6452);
        IoFreeMdl(puVar5);
        RdmaFreeOperation(piVar6);
        uVar9 = uVar9 * 2;
        local_d8 = (int *)0x0;
      } while (uVar9 < 0x8000);
      puVar5 = (undefined8 *)0x0;
      lVar4 = 0;
      piVar6 = (int *)0x0;
      goto LAB_1c00032b3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00032b3;
    uVar8 = 0x14;
  }
LAB_1c00030bd:
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar8,
                    &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar2);
LAB_1c00032b3:
  if (plStack_40 != (longlong *)0x0) {
    (**(code **)(*(longlong *)(plStack_40[7] + 0x28) + 0x18))(plStack_40[7],1);
    SendAckMessage(plStack_40);
  }
  if (cVar1 != '\0') {
    ExReleaseRundownProtectionEx(plStack_40 + 0xc,1);
  }
  if (piVar6 != (int *)0x0) {
    RdmaFreeOperation(piVar6);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x616d6452);
  }
  if (puVar5 != (undefined8 *)0x0) {
    IoFreeMdl(puVar5);
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_40);
  }
  return iVar2;
}



===== RdmaTestReadByMemoryUpdateTimeClient @ 1c0003378 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaTestReadByMemoryUpdateTimeClient(short *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  longlong *_Dst;
  void *_Dst_00;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong *plVar11;
  undefined2 uVar12;
  uint uVar13;
  undefined1 auStackY_148 [32];
  undefined8 in_stack_fffffffffffffee8;
  longlong *local_100;
  int local_f8;
  uint local_f4;
  longlong local_f0;
  ulonglong local_e8;
  short *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  longlong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  longlong *plStack_70;
  longlong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_68 = 0;
  uStack_60 = 0;
  puVar5 = (undefined8 *)0x0;
  _Dst_00 = (void *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  plVar11 = (longlong *)0x0;
  local_100 = (longlong *)0x0;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_f0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_f8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_e0 = param_1;
  cVar1 = KeGetCurrentIrql();
  local_d0 = 0x10;
  local_d8 = 1;
  cVar2 = '\0';
  _Dst = (longlong *)ExAllocatePool3(0x40,400000,0x616d6452,&local_d8);
  if (_Dst != (longlong *)0x0) {
    memset(_Dst,0,400000);
    KeInitializeEvent(&local_58,0);
    uVar10 = 0;
    KeInitializeEvent(&local_b8,0);
    iVar4 = RdmaPingEstablishConnectionClient((longlong)&local_68,param_1,uVar10);
    if (iVar4 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003810;
      uVar12 = 0x26;
      cVar2 = '\0';
LAB_1c00034a1:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar12,
                        &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
      goto LAB_1c0003810;
    }
    (**(code **)(*(longlong *)(plStack_40[6] + 0x28) + 0x18))(plStack_40[6],1);
    KeWaitForSingleObject(&local_58,0,0,0);
    KeClearEvent(&local_58);
    local_c0 = 0x10;
    local_c8 = 1;
    _Dst_00 = (void *)ExAllocatePool3(0x40,0x8000,0x616d6452,&local_c8);
    if (_Dst_00 != (void *)0x0) {
      uVar10 = 0x8000;
      puVar5 = (undefined8 *)IoAllocateMdl(_Dst_00,0x8000,0,0);
      if (puVar5 != (undefined8 *)0x0) {
        MmBuildMdlForNonPagedPool(puVar5);
        memset(_Dst_00,(int)CONCAT71((int7)((ulonglong)uVar10 >> 8),0x31),0x8000);
        cVar2 = ExAcquireRundownProtectionEx(plStack_40 + 0xc,1);
        if (cVar2 == '\0') {
          iVar4 = -0x3fffff1b;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003810;
          uVar12 = 0x27;
        }
        else {
          local_98 = local_68;
          uStack_90 = uStack_60;
          local_88 = local_58;
          uStack_80 = uStack_50;
          local_78 = local_48;
          plStack_70 = plStack_40;
          uVar6 = RdmaDoWarmup(&local_98,2);
          iVar4 = (int)uVar6;
          if (iVar4 == 0) {
            uVar6 = 1;
            while( true ) {
              uVar13 = (uint)uVar6;
              uVar7 = RdmaBuildReadWRForOperation
                                (plStack_40,puVar5,uVar13,local_68,(undefined4)uStack_60,&local_b8,
                                 in_stack_fffffffffffffee8,&local_100);
              iVar4 = (int)uVar7;
              if (iVar4 != 0) break;
              cVar1 = KfRaiseIrql(2);
              plVar11 = local_100;
              local_f4 = 0;
              local_e8 = (ulonglong)(uVar13 - 1);
              local_100 = _Dst;
              do {
                *(undefined1 *)(local_e8 + (longlong)_Dst_00) = 0x31;
                lVar8 = KeQueryPerformanceCounter(&local_f0);
                iVar4 = NdkRead((longlong)plStack_40,plVar11[1],0);
                if (iVar4 != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x2a;
LAB_1c00037de:
                    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar12,
                                      &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
                  }
LAB_1c0003807:
                  goto LAB_1c0003810;
                }
                uVar10 = RdmaPollForCompletionWithTimeout((longlong)plStack_40,&local_f8);
                iVar4 = (int)uVar10;
                if (((int)uVar10 != 0) || (iVar4 = local_f8, local_f8 != 0)) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x2b;
                    goto LAB_1c00037de;
                  }
                  goto LAB_1c0003807;
                }
                lVar9 = KeQueryPerformanceCounter(0);
                lVar8 = (lVar9 - lVar8) * 1000000;
                lVar9 = lVar8 % local_f0;
                *local_100 = lVar8 / local_f0;
                local_100 = local_100 + 1;
                local_f4 = local_f4 + 1;
              } while (local_f4 < 50000);
              KeLowerIrql(CONCAT71((int7)((ulonglong)local_100 >> 8),cVar1));
              iVar4 = RdmaPrintTestDataToFile(_Dst,lVar9,uVar6,local_e0 + 0x18);
              if (iVar4 != 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x2c,
                                    &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
                }
                goto LAB_1c0003810;
              }
              RdmaFreeOperation((int *)plVar11);
              plVar11 = (longlong *)0x0;
              uVar6 = (ulonglong)(uVar13 * 2);
              local_100 = (longlong *)0x0;
              if (0x7fff < uVar13 * 2) goto LAB_1c0003810;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x29,
                                &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar7);
            }
            plVar11 = local_100;
            goto LAB_1c0003810;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0003810;
          uVar12 = 0x28;
        }
        goto LAB_1c00034a1;
      }
    }
  }
  iVar4 = -0x3fffff66;
LAB_1c0003810:
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != cVar1) {
    KeLowerIrql(cVar1);
  }
  if (plStack_40 != (longlong *)0x0) {
    (**(code **)(*(longlong *)(plStack_40[7] + 0x28) + 0x18))(plStack_40[7],1);
    SendAckMessage(plStack_40);
  }
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(plStack_40 + 0xc,1);
  }
  if (plVar11 != (longlong *)0x0) {
    RdmaFreeOperation((int *)plVar11);
  }
  if (_Dst_00 != (void *)0x0) {
    ExFreePoolWithTag(_Dst_00,0x616d6452);
  }
  if (puVar5 != (undefined8 *)0x0) {
    IoFreeMdl(puVar5);
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_40);
  }
  return iVar4;
}



===== RdmaTestSendByReceiveTimeClient @ 1c0003958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaTestSendByReceiveTimeClient(short *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  void *_Dst;
  undefined4 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  int *piVar12;
  int *piVar13;
  undefined2 uVar14;
  uint uVar15;
  undefined1 auStackY_108 [32];
  undefined8 uVar16;
  undefined8 in_stack_ffffffffffffff28;
  int *local_b8;
  longlong local_b0;
  short *local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  longlong local_60 [5];
  longlong *plStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_108;
  puVar6 = (undefined4 *)0x0;
  piVar13 = (int *)0x0;
  local_b0 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_b8 = (int *)0x0;
  puVar7 = (undefined8 *)0x0;
  local_60[2] = 0;
  local_60[3] = 0;
  cVar2 = '\0';
  local_60[4] = 0;
  plStack_38 = (longlong *)0x0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_a8 = param_1;
  cVar1 = KeGetCurrentIrql();
  local_94 = 0;
  local_98 = 0x10;
  local_a0 = 1;
  _Dst = (void *)ExAllocatePool3(0x40,400000,0x616d6452,&local_a0);
  cVar3 = '\0';
  if (_Dst == (void *)0x0) {
LAB_1c0003a08:
    cVar2 = cVar3;
    iVar4 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,400000);
    KeInitializeEvent(local_60 + 2,0);
    uVar10 = 0;
    KeInitializeEvent(&local_80,0);
    iVar4 = RdmaPingEstablishConnectionClient((longlong)local_60,param_1,uVar10);
    if (iVar4 == 0) {
      cVar2 = ExAcquireRundownProtectionEx(plStack_38 + 0xc,1);
      if (cVar2 != '\0') {
        local_84 = 0;
        local_90 = 1;
        local_88 = 0x10;
        puVar6 = (undefined4 *)ExAllocatePool3(0x40,4,0x616d6452);
        cVar3 = cVar2;
        if (puVar6 != (undefined4 *)0x0) {
          uVar16 = 0;
          uVar10 = 0;
          puVar7 = (undefined8 *)IoAllocateMdl(puVar6,4,0);
          if (puVar7 != (undefined8 *)0x0) {
            MmBuildMdlForNonPagedPool(puVar7);
            *puVar6 = 1;
            uVar8 = RdmaBuildSendWRForOperation
                              (plStack_38,puVar7,4,uVar10,uVar16,&local_80,in_stack_ffffffffffffff28
                               ,&local_b8);
            iVar4 = (int)uVar8;
            if (iVar4 == 0) {
              cVar1 = KfRaiseIrql(2);
              piVar13 = local_b8;
              uVar15 = 0;
              do {
                lVar9 = KeQueryPerformanceCounter(&local_b0);
                RdmaQueueSQWrs(plStack_38,*(longlong **)(piVar13 + 2),1);
                uVar10 = RdmaPollForReceive(plStack_38);
                if ((int)uVar10 == 0x102) {
                  iVar5 = RdmaCheckForSqWrErrorCompletions((longlong)plStack_38);
                  piVar13[10] = iVar5;
                  iVar4 = 0x102;
                  if ((iVar5 != 0) &&
                     (iVar4 = iVar5,
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    uVar14 = 0xf;
LAB_1c0003e5d:
                    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar14,
                                      &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar5);
                    iVar4 = iVar5;
                  }
                  goto LAB_1c0003d59;
                }
                piVar12 = (int *)plStack_38[0x1f];
                iVar5 = *piVar12;
                if (iVar5 != 0) {
                  iVar4 = iVar5;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar14 = 0x10;
                    goto LAB_1c0003e5d;
                  }
                  goto LAB_1c0003d59;
                }
                lVar11 = KeQueryPerformanceCounter(0);
                if (999 < uVar15) {
                  *(longlong *)((longlong)_Dst + (ulonglong)(uVar15 - 1000) * 8) =
                       (((lVar11 - lVar9) * 1000000) / local_b0) / 2;
                }
                iVar4 = RdmaRepostReceive((longlong)plStack_38,(longlong)piVar12);
                if (iVar4 != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x11,
                                      &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
                  }
                  goto LAB_1c0003d59;
                }
                uVar15 = uVar15 + 1;
              } while (uVar15 < 51000);
              KeLowerIrql(cVar1);
              iVar4 = RdmaPrintTestDataToFile(_Dst,piVar12,4,local_a8 + 0x18);
              if (iVar4 == 0) {
                iVar4 = 0;
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x12,
                                  &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
              }
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xe,
                                  &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar8);
              }
              piVar13 = local_b8;
            }
            goto LAB_1c0003d59;
          }
        }
        goto LAB_1c0003a08;
      }
      iVar4 = -0x3fffff1b;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003d59;
      uVar14 = 0xd;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0003d59;
      uVar14 = 0xc;
      cVar2 = '\0';
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar14,
                      &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar4);
  }
LAB_1c0003d59:
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != cVar1) {
    KeLowerIrql(cVar1);
  }
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(plStack_38 + 0xc,1);
  }
  if (plStack_38 != (longlong *)0x0) {
    (**(code **)(*(longlong *)(plStack_38[6] + 0x28) + 0x18))(plStack_38[6],1);
  }
  if (piVar13 != (int *)0x0) {
    RdmaFreeOperation(piVar13);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x616d6452);
  }
  if (puVar6 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar6,0x616d6452);
  }
  if (puVar7 != (undefined8 *)0x0) {
    IoFreeMdl(puVar7);
  }
  if (plStack_38 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_38);
  }
  return iVar4;
}



===== RdmaTestWriteByCompletionTimeClient @ 1c0003ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaTestWriteByCompletionTimeClient(short *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined8 *puVar7;
  char *pcVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  int *piVar12;
  undefined1 auStackY_118 [32];
  undefined8 in_stack_ffffffffffffff18;
  int *local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  longlong *plStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  piVar12 = (int *)0x0;
  local_d8 = (int *)0x0;
  puVar7 = (undefined8 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  pcVar6 = (char *)0x0;
  cVar2 = '\0';
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  KeInitializeEvent(&local_58,0);
  uVar10 = 0;
  KeInitializeEvent(&local_c0,0);
  iVar3 = RdmaPingEstablishConnectionClient((longlong)&local_68,param_1,uVar10);
  if (iVar3 == 0) {
    (**(code **)(*(longlong *)(plStack_40[6] + 0x28) + 0x18))(plStack_40[6],1);
    KeWaitForSingleObject(&local_58,0,0,0);
    KeClearEvent(&local_58);
    cVar2 = ExAcquireRundownProtectionEx(plStack_40 + 0xc,1);
    if (cVar2 == '\0') {
      iVar3 = -0x3fffff1b;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004205;
      uVar11 = 0x18;
    }
    else {
      local_98 = local_68;
      uStack_90 = uStack_60;
      local_88 = local_58;
      uStack_80 = uStack_50;
      local_78 = local_48;
      plStack_70 = plStack_40;
      uVar5 = RdmaDoWarmup(&local_98,3);
      iVar3 = (int)uVar5;
      if (iVar3 == 0) {
        uVar9 = 1;
        do {
          piVar12 = (int *)0x0;
          local_c4 = 0;
          local_d0 = 1;
          local_c8 = 0x10;
          pcVar6 = (char *)ExAllocatePool3(0x40,uVar9,0x616d6452,&local_d0);
          if (pcVar6 == (char *)0x0) {
            puVar7 = (undefined8 *)0x0;
LAB_1c0004200:
            iVar3 = -0x3fffff66;
            goto LAB_1c0004205;
          }
          puVar7 = (undefined8 *)IoAllocateMdl(pcVar6,uVar9,0,0);
          if (puVar7 == (undefined8 *)0x0) goto LAB_1c0004200;
          MmBuildMdlForNonPagedPool(puVar7);
          uVar4 = 0;
          if (uVar9 != 0) {
            pcVar8 = pcVar6;
            do {
              cVar1 = (char)uVar4;
              uVar4 = uVar4 + 1;
              *pcVar8 = cVar1 + '0';
              pcVar8 = pcVar8 + 1;
            } while (uVar4 < uVar9);
          }
          uVar5 = RdmaBuildWriteWRForOperation
                            (plStack_40,puVar7,uVar9,local_68,(undefined4)uStack_60,&local_c0,
                             in_stack_ffffffffffffff18,&local_d8);
          piVar12 = local_d8;
          iVar3 = (int)uVar5;
          if (iVar3 != 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1a,
                                &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar5);
            }
            piVar12 = local_d8;
            goto LAB_1c0004205;
          }
          uVar5 = RdmaDoPing((longlong)plStack_40,*(longlong *)(local_d8 + 2),uVar9,param_1 + 0x18);
          iVar3 = (int)uVar5;
          if (iVar3 != 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0004205;
            uVar11 = 0x1b;
            goto LAB_1c0003f6e;
          }
          ExFreePoolWithTag(pcVar6,0x616d6452);
          IoFreeMdl(puVar7);
          RdmaFreeOperation(piVar12);
          uVar9 = uVar9 * 2;
          local_d8 = (int *)0x0;
        } while (uVar9 < 0x8000);
        puVar7 = (undefined8 *)0x0;
        pcVar6 = (char *)0x0;
        piVar12 = (int *)0x0;
        goto LAB_1c0004205;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004205;
      uVar11 = 0x19;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0004205;
    uVar11 = 0x17;
    cVar2 = '\0';
  }
LAB_1c0003f6e:
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar11,
                    &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar3);
LAB_1c0004205:
  if (plStack_40 != (longlong *)0x0) {
    (**(code **)(*(longlong *)(plStack_40[7] + 0x28) + 0x18))(plStack_40[7],1);
    SendAckMessage(plStack_40);
  }
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(plStack_40 + 0xc,1);
  }
  if (piVar12 != (int *)0x0) {
    RdmaFreeOperation(piVar12);
  }
  if (pcVar6 != (char *)0x0) {
    ExFreePoolWithTag(pcVar6,0x616d6452);
  }
  if (puVar7 != (undefined8 *)0x0) {
    IoFreeMdl(puVar7);
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_40);
  }
  return iVar3;
}



===== RdmaTestWriteByMemoryUpdateTimeClient @ 1c00042cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int RdmaTestWriteByMemoryUpdateTimeClient(short *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  void *_Dst;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  uint uVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined1 auStackY_168 [32];
  undefined8 in_stack_fffffffffffffec8;
  char local_127;
  longlong *local_110;
  longlong *local_108;
  int local_100 [2];
  longlong local_f8;
  longlong *local_f0;
  ulonglong local_e8;
  short *local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  longlong *plStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  _Dst = (void *)0x0;
  plVar15 = (longlong *)0x0;
  local_f8 = 0;
  plVar14 = (longlong *)0x0;
  local_100[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_108 = (longlong *)0x0;
  puVar5 = (undefined8 *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_110 = (longlong *)0x0;
  cVar2 = '\0';
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_e0 = param_1;
  local_127 = KeGetCurrentIrql();
  local_cc = 0;
  local_d8 = 1;
  local_d0 = 0x10;
  local_f0 = (longlong *)ExAllocatePool3(0x40,400000,0x616d6452,&local_d8);
  if (local_f0 == (longlong *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    memset(local_f0,0,400000);
    KeInitializeEvent(&local_58,0);
    uVar9 = 0;
    KeInitializeEvent(&local_b8,0);
    iVar3 = RdmaPingEstablishConnectionClient((longlong)&local_68,param_1,uVar9);
    if (iVar3 == 0) {
      (**(code **)(*(longlong *)(plStack_40[6] + 0x28) + 0x18))(plStack_40[6],1);
      KeWaitForSingleObject(&local_58,0,0,0);
      KeClearEvent(&local_58);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1d,
                         &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids);
      }
      local_bc = 0;
      local_c0 = 0x10;
      local_c8 = 1;
      _Dst = (void *)ExAllocatePool3(0x40,0x8000,0x616d6452,&local_c8);
      if (_Dst == (void *)0x0) {
        iVar3 = -0x3fffff66;
        cVar2 = '\0';
      }
      else {
        uVar9 = 0x8000;
        puVar5 = (undefined8 *)IoAllocateMdl(_Dst,0x8000,0,0);
        if (puVar5 == (undefined8 *)0x0) {
          iVar3 = -0x3fffff66;
          cVar2 = '\0';
        }
        else {
          MmBuildMdlForNonPagedPool(puVar5);
          uVar11 = 0x8000;
          memset(_Dst,(int)CONCAT71((int7)((ulonglong)uVar9 >> 8),0x31),0x8000);
          uVar6 = RdmaRegisterBuffer(plStack_40,(longlong)puVar5,uVar11,(longlong *)&local_110);
          iVar3 = (int)uVar6;
          if (iVar3 == 0) {
            cVar2 = ExAcquireRundownProtectionEx(plStack_40 + 0xc,1);
            plVar14 = local_110;
            if (cVar2 == '\0') {
              iVar3 = -0x3fffff1b;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1f,
                                  &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,0xe5);
              }
              plVar14 = local_110;
            }
            else {
              local_98 = local_68;
              uStack_90 = uStack_60;
              local_78 = local_48;
              plStack_70 = plStack_40;
              local_88 = local_58;
              uStack_80 = uStack_50;
              uVar6 = RdmaSendMRInfo((longlong)&local_98,local_110[4],(int)local_110[3]);
              iVar3 = (int)uVar6;
              if (iVar3 == 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x21,
                                   &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids);
                }
                uVar6 = 1;
                do {
                  uVar13 = (uint)uVar6;
                  uVar7 = RdmaBuildWriteWRForOperation
                                    (plStack_40,puVar5,uVar13,local_68,(undefined4)uStack_60,
                                     &local_b8,in_stack_fffffffffffffec8,&local_108);
                  iVar3 = (int)uVar7;
                  if (iVar3 != 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x22,
                                        &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar7
                                       );
                    }
                    plVar15 = local_108;
                    goto LAB_1c0004429;
                  }
                  local_127 = KfRaiseIrql(2);
                  plVar15 = local_108;
                  local_e8 = (ulonglong)(uVar13 - 1);
                  local_110 = (longlong *)((ulonglong)local_110 & 0xffffffff00000000);
                  local_108 = local_f0;
                  do {
                    *(undefined1 *)(local_e8 + (longlong)_Dst) = 0x31;
                    lVar8 = KeQueryPerformanceCounter(&local_f8);
                    iVar3 = NdkWrite((longlong)plStack_40,plVar15[1],0);
                    if (iVar3 != 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar12 = 0x23;
LAB_1c0004938:
                        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar12,
                                          &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,
                                          (char)iVar3);
                      }
LAB_1c0004956:
                      goto LAB_1c0004429;
                    }
                    uVar9 = RdmaPollForCompletionWithTimeout((longlong)plStack_40,local_100);
                    iVar3 = (int)uVar9;
                    if (((int)uVar9 != 0) || (iVar3 = local_100[0], local_100[0] != 0)) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar12 = 0x24;
                        goto LAB_1c0004938;
                      }
                      goto LAB_1c0004956;
                    }
                    lVar10 = KeQueryPerformanceCounter(0);
                    lVar8 = ((lVar10 - lVar8) * 1000000) / local_f8;
                    lVar10 = lVar8 >> 0x3f;
                    *local_108 = lVar8 / 2;
                    local_108 = local_108 + 1;
                    uVar4 = (int)local_110 + 1;
                    local_110 = (longlong *)CONCAT44(local_110._4_4_,uVar4);
                  } while (uVar4 < 50000);
                  KeLowerIrql(local_127);
                  iVar3 = RdmaPrintTestDataToFile(local_f0,lVar10,uVar6,local_e0 + 0x18);
                  if (iVar3 != 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x25,
                                        &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar3
                                       );
                    }
                    break;
                  }
                  RdmaFreeOperation((int *)plVar15);
                  plVar15 = (longlong *)0x0;
                  uVar6 = (ulonglong)(uVar13 * 2);
                  local_108 = (longlong *)0x0;
                } while (uVar13 * 2 < 0x8000);
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x20,
                                  &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar6);
              }
            }
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1e,
                                &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)uVar6);
            }
            cVar2 = '\0';
            plVar14 = local_110;
          }
        }
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1c,
                          &WPP_8a6ad2e8bf7e357d1c29e2debf939ba6_Traceguids,(char)iVar3);
      }
      cVar2 = '\0';
    }
  }
LAB_1c0004429:
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != local_127) {
    KeLowerIrql();
  }
  if (plStack_40 != (longlong *)0x0) {
    (**(code **)(*(longlong *)(plStack_40[7] + 0x28) + 0x18))(plStack_40[7],1);
  }
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(plStack_40 + 0xc,1);
  }
  if (plVar14 != (longlong *)0x0) {
    RdmaInvalidateRegisteredBuffer(plStack_40,plVar14);
  }
  if (plVar15 != (longlong *)0x0) {
    RdmaFreeOperation((int *)plVar15);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x616d6452);
  }
  if (puVar5 != (undefined8 *)0x0) {
    IoFreeMdl(puVar5);
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseSocket(plStack_40);
  }
  return iVar3;
}



===== AcceptCallback @ 1c00049b0 =====

undefined8
AcceptCallback(undefined8 param_1,longlong param_2,undefined8 *param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  undefined8 uVar1;
  bool bVar2;
  
  LOCK();
  bVar2 = DAT_1c000c330 == 0;
  if (bVar2) {
    DAT_1c000c330 = param_2;
  }
  UNLOCK();
  if (bVar2) {
    *param_3 = _guard_check_icall;
    *param_4 = ReceiveCallback;
    *param_5 = &ServerSocket;
    KeSetEvent(param_1,0,0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== RdmaHeartbeatServer @ 1c0004a0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaHeartbeatServer(longlong param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  char *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 local_res10;
  int *local_res18 [2];
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar12;
  undefined8 *puVar11;
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  uVar10 = 0;
  local_res18[0] = (int *)0x0;
  local_res10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  plStack_40 = (longlong *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  KeInitializeEvent(&DAT_1c000c318,1,0);
  KeInitializeEvent(&local_78,0,0);
  iVar3 = RdmaPingEstablishConnectionServer((longlong)&local_58,param_1);
  if (iVar3 == 0) {
    (**(code **)(*(longlong *)(DAT_1c000c330[6] + 0x28) + 0x18))(DAT_1c000c330[6],1);
    (**(code **)(*(longlong *)(DAT_1c000c330[7] + 0x28) + 0x18))(DAT_1c000c330[7],1);
    local_80 = 0x10;
    local_88 = 1;
    puVar4 = (undefined4 *)ExAllocatePool3(0x40,0x8000,0x616d6452,&local_88,CONCAT44(uVar12,1));
    if (puVar4 == (undefined4 *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      puVar5 = (undefined8 *)IoAllocateMdl(puVar4,0x8000,0,0,0);
      if (puVar5 == (undefined8 *)0x0) {
        iVar3 = -0x3fffff66;
      }
      else {
        MmBuildMdlForNonPagedPool(puVar5);
        uVar7 = 4;
        *puVar4 = 1;
        pcVar8 = (char *)(puVar4 + 1);
        do {
          cVar2 = (char)uVar7;
          uVar7 = uVar7 + 1;
          *pcVar8 = cVar2 + '0';
          pcVar8 = pcVar8 + 1;
        } while (uVar7 < 0x8000);
        cVar2 = ExAcquireRundownProtectionEx(DAT_1c000c330 + 0xc,1);
        if (cVar2 == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1f,
                              &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,0);
          }
          iVar3 = -0x3fffff1b;
        }
        else {
          local_res10 = 0xfffffffffd050f80;
          do {
            puVar11 = &local_res10;
            uVar9 = 0;
            iVar3 = KeWaitForSingleObject(&DAT_1c000c318,0,0);
            if ((iVar3 == 0x102) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar9 = 0x20;
              puVar11 = (undefined8 *)&WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids;
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x20,
                               &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids);
            }
            uVar6 = RdmaBuildSendWRForOperation
                              (DAT_1c000c330,puVar5,0x8000,uVar9,puVar11,&local_78,
                               in_stack_ffffffffffffff68,local_res18);
            piVar1 = local_res18[0];
            iVar3 = (int)uVar6;
            if (iVar3 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x21,
                                  &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)uVar6);
              }
              break;
            }
            RdmaQueueSQWrs(DAT_1c000c330,*(longlong **)(local_res18[0] + 2),0);
            uVar10 = uVar10 + 1;
          } while (uVar10 < 0x19);
          ExReleaseRundownProtectionEx(DAT_1c000c330 + 0xc,1);
          if (piVar1 != (int *)0x0) {
            RdmaFreeOperation(piVar1);
          }
        }
        IoFreeMdl(puVar5);
      }
      ExFreePoolWithTag(puVar4,0x616d6452);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1e,
                      &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar3);
  }
  if (DAT_1c000c330 != (longlong *)0x0) {
    RdmaCloseSocket(DAT_1c000c330);
    DAT_1c000c330 = (longlong *)0x0;
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseListenSocket(plStack_40);
  }
  return iVar3;
}



===== RdmaPingEstablishConnectionServer @ 1c0004da0 =====

int RdmaPingEstablishConnectionServer(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  longlong local_res8;
  longlong *plVar4;
  
  local_res8 = 0;
  uVar2 = 0;
  KeInitializeEvent(param_1,0,0);
  iVar1 = RdmaCreateListenSocket
                    (*(NET_IFINDEX *)(param_2 + 0x24),uVar2,param_1,(undefined8 *)(param_1 + 0x18));
  if (iVar1 == 0) {
    iVar1 = RdmaListen(*(longlong **)(param_1 + 0x18),(short *)(param_2 + 0x10));
    if (iVar1 == 0) {
      if (*(int *)(param_2 + 0x2c) == 0) {
        plVar4 = (longlong *)0x0;
      }
      else {
        local_res8 = (longlong)(*(int *)(param_2 + 0x2c) * -10000000);
        plVar4 = &local_res8;
      }
      iVar1 = KeWaitForSingleObject(param_1,0,0,0,plVar4);
      if ((iVar1 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xc,
                          &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar1);
      }
      KeClearEvent(param_1);
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0xb;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 10;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar3,
                    &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar1);
  return iVar1;
}



===== RdmaTestReadWriteByCompletionTimeServer @ 1c0004f0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RdmaTestReadWriteByCompletionTimeServer(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  void *_Dst;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  longlong *local_res10;
  longlong local_res18 [2];
  undefined8 in_stack_ffffffffffffff68;
  undefined4 uVar9;
  longlong *plVar8;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  longlong *plStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong *plStack_30;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  local_res10 = (longlong *)0x0;
  local_res18[0] = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  plStack_60 = (longlong *)0x0;
  KeInitializeEvent(&DAT_1c000c318,0,0);
  iVar2 = RdmaPingEstablishConnectionServer((longlong)&local_78,param_1);
  if (iVar2 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0xd,
                        &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar2);
    }
    goto LAB_1c00051c7;
  }
  (**(code **)(*(longlong *)(DAT_1c000c330[6] + 0x28) + 0x18))(DAT_1c000c330[6],1);
  (**(code **)(*(longlong *)(DAT_1c000c330[7] + 0x28) + 0x18))(DAT_1c000c330[7],1);
  local_7c = 0;
  local_88 = 1;
  local_80 = 0x10;
  _Dst = (void *)ExAllocatePool3(0x40,0x8000,0x616d6452,&local_88,CONCAT44(uVar9,1));
  if (_Dst == (void *)0x0) {
    iVar2 = -0x3fffff66;
    goto LAB_1c00051c7;
  }
  uVar5 = 0x8000;
  lVar3 = IoAllocateMdl(_Dst,0x8000,0,0,0);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    MmBuildMdlForNonPagedPool(lVar3);
    uVar6 = 0x8000;
    memset(_Dst,(int)CONCAT71((int7)((ulonglong)uVar5 >> 8),0x30),0x8000);
    uVar4 = RdmaRegisterBuffer(DAT_1c000c330,lVar3,uVar6,(longlong *)&local_res10);
    plVar1 = local_res10;
    iVar2 = (int)uVar4;
    if (iVar2 == 0) {
      local_58 = ServerSocket;
      uStack_50 = _DAT_1c000c310;
      local_48 = _DAT_1c000c318;
      uStack_40 = uRam00000001c000c320;
      local_38 = _DAT_1c000c328;
      plStack_30 = DAT_1c000c330;
      uVar4 = RdmaSendMRInfo((longlong)&local_58,local_res10[4],(int)local_res10[3]);
      iVar2 = (int)uVar4;
      if (iVar2 == 0) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          plVar8 = (longlong *)0x0;
        }
        else {
          local_res18[0] = (longlong)(*(int *)(param_1 + 0x2c) * -10000000);
          plVar8 = local_res18;
        }
        KeWaitForSingleObject(&DAT_1c000c318,0,0,0,plVar8);
        KeClearEvent(&DAT_1c000c318);
        iVar2 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0xf;
        goto LAB_1c00050b8;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0xe;
LAB_1c00050b8:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar7,
                        &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar2);
    }
    if (plVar1 != (longlong *)0x0) {
      RdmaInvalidateRegisteredBuffer(DAT_1c000c330,plVar1);
    }
  }
  ExFreePoolWithTag(_Dst,0x616d6452);
  if (lVar3 != 0) {
    IoFreeMdl(lVar3);
  }
LAB_1c00051c7:
  if (DAT_1c000c330 != (longlong *)0x0) {
    RdmaCloseSocket(DAT_1c000c330);
    DAT_1c000c330 = (longlong *)0x0;
  }
  if (plStack_60 != (longlong *)0x0) {
    RdmaCloseListenSocket(plStack_60);
  }
  return iVar2;
}



===== RdmaTestSendByReceiveTimeServer @ 1c0005210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaTestSendByReceiveTimeServer(longlong param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  int *piVar11;
  uint uVar12;
  int *local_res20;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined8 in_stack_ffffffffffffff68;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  longlong local_58 [3];
  longlong *plStack_40;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  piVar11 = (int *)0x0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_res20 = (int *)0x0;
  local_58[2] = 0;
  plStack_40 = (longlong *)0x0;
  cVar2 = '\0';
  puVar7 = (undefined8 *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  puVar6 = (undefined4 *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  cVar1 = KeGetCurrentIrql();
  KeInitializeEvent(&DAT_1c000c318,0,0);
  iVar4 = RdmaPingEstablishConnectionServer((longlong)local_58,param_1);
  if (iVar4 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x10,
                        &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar4);
      cVar2 = '\0';
    }
    goto LAB_1c000559b;
  }
  KeInitializeEvent(&local_78,0,0);
  cVar2 = ExAcquireRundownProtectionEx(DAT_1c000c330 + 0xc,1);
  if (cVar2 == '\0') {
    iVar4 = -0x3fffff1b;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000559b;
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x11,
                      &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,0xe5);
LAB_1c0005597:
  }
  else {
    local_7c = 0;
    local_88 = 1;
    local_80 = 0x10;
    puVar6 = (undefined4 *)ExAllocatePool3(0x40,4,0x616d6452,&local_88,CONCAT44(uVar14,1));
    if (puVar6 != (undefined4 *)0x0) {
      uVar13 = 0;
      uVar9 = 0;
      puVar7 = (undefined8 *)IoAllocateMdl(puVar6,4,0);
      if (puVar7 != (undefined8 *)0x0) {
        MmBuildMdlForNonPagedPool(puVar7);
        *puVar6 = 1;
        uVar8 = RdmaBuildSendWRForOperation
                          (DAT_1c000c330,puVar7,4,uVar9,uVar13,&local_78,in_stack_ffffffffffffff68,
                           &local_res20);
        iVar4 = (int)uVar8;
        if (iVar4 == 0) {
          cVar1 = KfRaiseIrql(2);
          piVar11 = local_res20;
          uVar12 = 0;
          do {
            uVar9 = RdmaPollForReceive(DAT_1c000c330);
            if ((int)uVar9 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x13,
                                  &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)uVar9);
              }
              if ((int)uVar9 != 0x102) goto LAB_1c00054ca;
              iVar5 = RdmaCheckForSqWrErrorCompletions((longlong)DAT_1c000c330);
              piVar11[10] = iVar5;
              iVar4 = 0x102;
              if ((iVar5 != 0) &&
                 (iVar4 = iVar5, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED
                 )) {
                uVar10 = 0x14;
LAB_1c0005575:
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar10,
                                  &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar5);
                iVar4 = iVar5;
              }
              goto LAB_1c0005597;
            }
LAB_1c00054ca:
            iVar5 = *(int *)DAT_1c000c330[0x1f];
            if (iVar5 != 0) {
              iVar4 = iVar5;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x15;
                goto LAB_1c0005575;
              }
              goto LAB_1c0005597;
            }
            iVar4 = RdmaRepostReceive((longlong)DAT_1c000c330,DAT_1c000c330[0x1f]);
            if (iVar4 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x16;
                iVar5 = iVar4;
                goto LAB_1c0005575;
              }
              goto LAB_1c0005597;
            }
            RdmaQueueSQWrs(DAT_1c000c330,*(longlong **)(piVar11 + 2),1);
            uVar12 = uVar12 + 1;
          } while (uVar12 < 51000);
          KeLowerIrql(cVar1);
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            piVar11 = local_res20;
            goto LAB_1c000559b;
          }
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x12,
                            &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)uVar8);
          piVar11 = local_res20;
        }
        goto LAB_1c0005597;
      }
    }
    iVar4 = -0x3fffff66;
  }
LAB_1c000559b:
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != cVar1) {
    KeLowerIrql(cVar1);
  }
  if (iVar4 == 0) {
    (**(code **)(*(longlong *)(DAT_1c000c330[6] + 0x28) + 0x18))(DAT_1c000c330[6],1);
  }
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(DAT_1c000c330 + 0xc,1);
  }
  if (piVar11 != (int *)0x0) {
    RdmaFreeOperation(piVar11);
  }
  if (puVar6 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar6,0x616d6452);
  }
  if (puVar7 != (undefined8 *)0x0) {
    IoFreeMdl(puVar7);
  }
  if (DAT_1c000c330 != (longlong *)0x0) {
    RdmaCloseSocket(DAT_1c000c330);
    DAT_1c000c330 = (longlong *)0x0;
  }
  if (plStack_40 != (longlong *)0x0) {
    RdmaCloseListenSocket(plStack_40);
  }
  return iVar4;
}



===== RdmaTestWriteByMemoryUpdateTimeServer @ 1c0005680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int RdmaTestWriteByMemoryUpdateTimeServer(longlong param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  void *_Dst;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  longlong *plVar13;
  uint uVar14;
  longlong *local_res10;
  char local_res18;
  int local_res20 [2];
  undefined8 in_stack_ffffffffffffff18;
  undefined4 uVar15;
  undefined8 in_stack_ffffffffffffff28;
  longlong *local_c8;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  longlong local_88 [3];
  longlong *plStack_70;
  longlong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *plStack_40;
  
  uVar15 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  plVar10 = (longlong *)0x0;
  local_res20[0] = 0;
  plVar13 = (longlong *)0x0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_res10 = (longlong *)0x0;
  local_88[2] = 0;
  plStack_70 = (longlong *)0x0;
  local_c8 = (longlong *)0x0;
  puVar6 = (undefined8 *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  _Dst = (void *)0x0;
  cVar3 = '\0';
  local_98 = 0;
  uStack_90 = 0;
  cVar2 = KeGetCurrentIrql();
  KeInitializeEvent(&DAT_1c000c318,0,0);
  KeInitializeEvent(&local_a8,0,0);
  iVar5 = RdmaPingEstablishConnectionServer((longlong)local_88,param_1);
  if (iVar5 == 0) {
    (**(code **)(*(longlong *)(DAT_1c000c330[6] + 0x28) + 0x18))(DAT_1c000c330[6],1);
    local_ac = 0;
    local_b0 = 0x10;
    local_b8 = 1;
    _Dst = (void *)ExAllocatePool3(0x40,0x8000,0x616d6452,&local_b8,CONCAT44(uVar15,1));
    if (_Dst != (void *)0x0) {
      uVar8 = 0x8000;
      puVar6 = (undefined8 *)IoAllocateMdl(_Dst,0x8000,0,0,0);
      if (puVar6 != (undefined8 *)0x0) {
        MmBuildMdlForNonPagedPool(puVar6);
        uVar11 = 0x8000;
        memset(_Dst,(int)CONCAT71((int7)((ulonglong)uVar8 >> 8),0x30),0x8000);
        uVar7 = RdmaRegisterBuffer(DAT_1c000c330,(longlong)puVar6,uVar11,(longlong *)&local_res10);
        plVar13 = local_res10;
        iVar5 = (int)uVar7;
        if (iVar5 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x18,
                              &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)uVar7);
          }
          plVar13 = local_res10;
          goto LAB_1c0005a6e;
        }
        uStack_60 = CONCAT44(uRam00000001c000c314,DAT_1c000c310);
        local_68 = ServerSocket;
        local_48 = _DAT_1c000c328;
        plStack_40 = DAT_1c000c330;
        local_58 = _DAT_1c000c318;
        uStack_50 = uRam00000001c000c320;
        uVar7 = RdmaSendMRInfo((longlong)&local_68,local_res10[4],(int)local_res10[3]);
        iVar5 = (int)uVar7;
        if (iVar5 == 0) {
          KeWaitForSingleObject(&DAT_1c000c318,0,0,0,0);
          KeClearEvent(&DAT_1c000c318);
          cVar3 = ExAcquireRundownProtectionEx(DAT_1c000c330 + 0xc,1);
          local_res10 = (longlong *)CONCAT71(local_res10._1_7_,cVar3);
          if (cVar3 != '\0') {
            uVar9 = 1;
            do {
              uVar7 = RdmaBuildWriteWRForOperation
                                (DAT_1c000c330,puVar6,uVar9,ServerSocket,DAT_1c000c310,&local_a8,
                                 in_stack_ffffffffffffff28,&local_c8);
              iVar5 = (int)uVar7;
              if (iVar5 != 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x1b,
                                    &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)uVar7);
                }
                plVar10 = local_c8;
                break;
              }
              local_res18 = KfRaiseIrql(2);
              plVar10 = local_c8;
              uVar14 = 0;
              local_c0 = (ulonglong)(uVar9 - 1);
              uVar7 = local_c0;
              do {
                do {
                } while (*(char *)(uVar7 + (longlong)_Dst) == '0');
                *(undefined1 *)(uVar7 + (longlong)_Dst) = 0x30;
                iVar5 = NdkWrite((longlong)DAT_1c000c330,plVar10[1],0);
                if (iVar5 != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x1c;
LAB_1c0005a3d:
                    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar12,
                                      &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar5);
                  }
LAB_1c0005a66:
                  cVar2 = local_res18;
                  goto LAB_1c0005a6a;
                }
                uVar8 = RdmaPollForCompletionWithTimeout((longlong)DAT_1c000c330,local_res20);
                iVar5 = local_res20[0];
                cVar2 = local_res18;
                iVar1 = (int)uVar8;
                if (((int)uVar8 != 0) || (iVar1 = local_res20[0], local_res20[0] != 0)) {
                  iVar5 = iVar1;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x1d;
                    goto LAB_1c0005a3d;
                  }
                  goto LAB_1c0005a66;
                }
                uVar14 = uVar14 + 1;
                uVar7 = local_c0;
              } while (uVar14 < 50000);
              KeLowerIrql(local_res18);
              RdmaFreeOperation((int *)plVar10);
              plVar10 = (longlong *)0x0;
              uVar9 = uVar9 * 2;
              local_c8 = (longlong *)0x0;
            } while (uVar9 < 0x8000);
LAB_1c0005a6a:
            cVar3 = (char)local_res10;
            goto LAB_1c0005a6e;
          }
          iVar5 = -0x3fffff1b;
          cVar3 = '\0';
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0005a6e;
          uVar12 = 0x1a;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0005a6e;
          uVar12 = 0x19;
        }
        goto LAB_1c0005732;
      }
    }
    iVar5 = -0x3fffff66;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0005a6e;
    uVar12 = 0x17;
LAB_1c0005732:
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar12,
                      &WPP_0051cab9d2d03ae4b1d9306055b28418_Traceguids,(char)iVar5);
    cVar3 = '\0';
  }
LAB_1c0005a6e:
  cVar4 = KeGetCurrentIrql();
  if (cVar4 != cVar2) {
    KeLowerIrql(cVar2);
  }
  if (iVar5 == 0) {
    (**(code **)(*(longlong *)(DAT_1c000c330[7] + 0x28) + 0x18))(DAT_1c000c330[7],1);
  }
  if (cVar3 != '\0') {
    ExReleaseRundownProtectionEx(DAT_1c000c330 + 0xc,1);
  }
  if (plVar10 != (longlong *)0x0) {
    RdmaFreeOperation((int *)plVar10);
  }
  if (plVar13 != (longlong *)0x0) {
    RdmaInvalidateRegisteredBuffer(DAT_1c000c330,plVar13);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x616d6452);
  }
  if (puVar6 != (undefined8 *)0x0) {
    IoFreeMdl(puVar6);
  }
  if (DAT_1c000c330 != (longlong *)0x0) {
    RdmaCloseSocket(DAT_1c000c330);
    DAT_1c000c330 = (longlong *)0x0;
  }
  if (plStack_70 != (longlong *)0x0) {
    RdmaCloseListenSocket(plStack_70);
  }
  return iVar5;
}



===== NdkCloseFnCompletionCallback @ 1c0005bd0 =====

void NdkCloseFnCompletionCallback(undefined8 param_1)

{
  KeSetEvent(param_1,0,0);
  return;
}



===== NdkCreateFnCompletionCallback @ 1c0005c00 =====

void NdkCreateFnCompletionCallback(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 0x20) = param_3;
  KeSetEvent(param_1,0,0);
  return;
}



===== NdkDisconnectEventCallback @ 1c0005c30 =====

void NdkDisconnectEventCallback(longlong param_1)

{
  RdmaQueueDisconnectWorkItem(param_1,'\0');
  return;
}



===== NdkFnCompletionCallback @ 1c0005c50 =====

void NdkFnCompletionCallback(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  KeSetEvent(param_1,0,0);
  return;
}



===== NdkPauseListener @ 1c0005c74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkPauseListener(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x28) + 0x20))(param_1,1);
  return;
}



===== NdkRead @ 1c0005c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkRead(longlong param_1,longlong param_2,undefined4 param_3)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) + 0x40))
            (*(longlong *)(param_1 + 0x40),param_2,*(undefined8 *)(param_2 + 0x30),
             *(undefined2 *)(param_2 + 0x38),*(undefined8 *)(param_2 + 0x40),
             *(undefined4 *)(param_2 + 0x48),param_3);
  return;
}



===== NdkReceive @ 1c0005cd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkReceive(longlong param_1,longlong param_2)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) + 0x20))
            (*(longlong *)(param_1 + 0x40),param_2,*(undefined8 *)(param_2 + 0x10),
             *(undefined2 *)(param_2 + 0x1c));
  return;
}



===== NdkWrite @ 1c0005d04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkWrite(longlong param_1,longlong param_2,undefined4 param_3)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x28) + 0x48))
            (*(longlong *)(param_1 + 0x40),param_2,*(undefined8 *)(param_2 + 0x30),
             *(undefined2 *)(param_2 + 0x38),*(undefined8 *)(param_2 + 0x40),
             *(undefined4 *)(param_2 + 0x48),param_3);
  return;
}



===== NdkRcqNotificationEventCallback @ 1c0005d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkRcqNotificationEventCallback(longlong *param_1)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong *plVar4;
  char local_res8 [8];
  
  cVar2 = ExAcquireRundownProtectionEx(param_1 + 0xc,1);
  local_res8[0] = cVar2 == '\0';
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x13,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,local_res8[0]);
  }
  if ((*(byte *)(*param_1 + 0x30) & 2) == 0) {
    plVar4 = RdmaProcessReceives((longlong)param_1,local_res8);
  }
  else {
    plVar4 = RdmaProcessReceivesEx((longlong)param_1,local_res8);
  }
  plVar1 = plVar4;
  if (local_res8[0] == '\0') {
    do {
      if (plVar4 == (longlong *)0x0) goto LAB_1c0005ed7;
      plVar1 = (longlong *)*plVar4;
      iVar3 = (**(code **)(*(longlong *)(param_1[8] + 0x28) + 0x20))
                        (param_1[8],plVar4,plVar4[2],*(undefined2 *)((longlong)plVar4 + 0x1c));
      plVar4 = plVar1;
    } while (-1 < iVar3);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x14,
                        &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar3);
    }
    RdmaQueueDisconnectWorkItem((longlong)param_1,'\0');
  }
  while (plVar1 != (longlong *)0x0) {
    plVar4 = (longlong *)*plVar1;
    ExReleaseRundownProtectionEx(param_1 + 0xd,1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x15,
                       &WPP_ca715d96931d395e776a8438613b8a57_Traceguids);
    }
    RdmaFreeLamBuffer((longlong)plVar1);
    plVar1 = plVar4;
  }
LAB_1c0005ed7:
  (**(code **)(*(longlong *)(param_1[6] + 0x28) + 0x18))(param_1[6],1);
  if (cVar2 != '\0') {
    ExReleaseRundownProtectionEx(param_1 + 0xc,1);
  }
  return;
}



===== NdkScqNotificationEventCallback @ 1c0005f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkScqNotificationEventCallback(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  bVar3 = false;
  while (uVar4 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x28) + 0x20))
                           (*(longlong *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x100),0x80),
        uVar4 != 0) {
    lVar5 = 0;
    uVar6 = (ulonglong)uVar4;
    do {
      lVar1 = *(longlong *)(param_1 + 0x100);
      lVar2 = *(longlong *)(lVar5 + 0x10 + lVar1);
      if ((*(int *)(lVar5 + lVar1) < 0) && (!bVar3)) {
        bVar3 = true;
        RdmaQueueDisconnectWorkItem(param_1,'\0');
      }
      (**(code **)(lVar2 + 0x18))(*(undefined4 *)(lVar5 + lVar1));
      lVar5 = lVar5 + 0x18;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x28) + 0x18))
            (*(longlong *)(param_1 + 0x38),1);
  return;
}



===== RdmaCloseSocket @ 1c0005fd8 =====

void RdmaCloseSocket(undefined8 *param_1)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  bool bVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar6 = false;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_28);
  iVar1 = *(int *)(param_1 + 0x10);
  if ((iVar1 == 0) || (iVar1 == 1)) {
LAB_1c000603f:
    *(undefined4 *)(param_1 + 0x10) = 6;
  }
  else if ((iVar1 == 2) || ((iVar1 == 3 || (iVar1 == 4)))) {
    bVar6 = true;
  }
  else if (iVar1 == 5) goto LAB_1c000603f;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (bVar6) {
    RdmaQueueDisconnectWorkItem((longlong)param_1,'\x01');
    KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_28);
    if (*(int *)(param_1 + 0x10) == 5) {
      *(undefined4 *)(param_1 + 0x10) = 6;
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  ExWaitForRundownProtectionRelease(param_1 + 0xd);
  if (param_1[8] != 0) {
    NdkCloseQueuePair(param_1[8]);
    param_1[8] = 0;
  }
  if (param_1[6] != 0) {
    NdkCloseQueuePair(param_1[6]);
    param_1[6] = 0;
  }
  if (param_1[7] != 0) {
    NdkCloseQueuePair(param_1[7]);
    param_1[7] = 0;
  }
  puVar7 = auStack_48;
  plVar4 = param_1 + 0x16;
  while (plVar2 = (longlong *)*plVar4, plVar2 != plVar4) {
    if (((longlong *)plVar2[1] != plVar4) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_1c000614b;
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    RdmaFreeRegisteredBuffer((longlong)plVar2);
  }
  plVar4 = param_1 + 0x18;
  while (plVar2 = (longlong *)*plVar4, plVar2 != plVar4) {
    if (((longlong *)plVar2[1] != plVar4) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_1c000614b;
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    RdmaFreeRegisteredBuffer((longlong)plVar2);
  }
LAB_1c0006152:
  lVar3 = param_1[2];
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0006160;
    NdkCloseQueuePair(lVar3);
    param_1[2] = 0;
  }
  plVar4 = (longlong *)*param_1;
  if (plVar4 != (longlong *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0006172;
    RdmaCloseAdapter(plVar4);
    *param_1 = 0;
  }
  if (param_1[0xe] != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0006186;
    IoFreeWorkItem();
    param_1[0xe] = 0;
  }
  lVar3 = param_1[4];
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c00061a7;
    ExFreePoolWithTag(lVar3,0x616d6452);
    param_1[4] = 0;
  }
  lVar3 = param_1[3];
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c00061c3;
    ExFreePoolWithTag(lVar3,0x616d6452);
    param_1[3] = 0;
  }
  lVar3 = param_1[0x20];
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c00061e2;
    ExFreePoolWithTag(lVar3,0x616d6452);
    param_1[0x20] = 0;
  }
  lVar3 = param_1[0x1f];
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0006204;
    ExFreePoolWithTag(lVar3,0x616d6452);
    param_1[0x1f] = 0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x1c000621d;
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
LAB_1c000614b:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar7 = auStack_40;
  goto LAB_1c0006152;
}



===== RdmaConnect @ 1c000623c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaConnect(longlong *param_1,short *param_2,short *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *plVar6;
  int iVar7;
  size_t _Size;
  uint local_res8 [2];
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar8;
  uint local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  plVar6 = param_1 + 0xc;
  _Size = 0;
  local_40 = 0;
  local_res8[0] = 0;
  local_res20[0] = 0;
  local_68[0] = 0;
  local_50 = 0;
  uStack_48 = 0;
  cVar1 = ExAcquireRundownProtectionEx(plVar6,1);
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffe7c;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x23,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,0x84);
    return -0x3ffffe7c;
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_50);
  if ((int)param_1[0x10] != 1) {
    KeReleaseInStackQueuedSpinLock();
    iVar2 = -0x3ffffe7c;
    goto LAB_1c000630f;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  KeReleaseInStackQueuedSpinLock(&local_50);
  if (param_3 != (short *)0x0) {
    if (*param_3 == 2) {
      _Size = 0x10;
    }
    else {
      _Size = 0x1c;
      if (*param_3 != 0x17) {
        _Size = 0;
      }
    }
  }
  local_58 = 0x10;
  local_60 = 1;
  lVar4 = ExAllocatePool3(0x40,_Size,0x616d6452,&local_60,CONCAT44(uVar8,1));
  param_1[4] = lVar4;
  if (lVar4 == 0) {
LAB_1c0006425:
    iVar2 = -0x3fffff66;
  }
  else {
    if (param_2 == (short *)0x0) {
      local_res8[0] = 0;
    }
    else if (*param_2 == 2) {
      local_res8[0] = 0x10;
    }
    else {
      local_res8[0] = 0x1c;
      if (*param_2 != 0x17) {
        local_res8[0] = 0;
      }
    }
    local_58 = 0x10;
    local_60 = 1;
    lVar4 = ExAllocatePool3(0x40,local_res8[0],0x616d6452,&local_60,1);
    iVar7 = 0;
    param_1[3] = lVar4;
    if (lVar4 == 0) goto LAB_1c0006425;
    memcpy((void *)param_1[4],param_3,_Size);
    memcpy((void *)param_1[3],param_2,(ulonglong)local_res8[0]);
    uVar5 = NdkConnect(param_1);
    iVar2 = (int)uVar5;
    if (-1 < iVar2) {
      if ((int)param_1[0x10] == 2) {
        uVar5 = NdkCompleteConnect((longlong)param_1);
        iVar2 = (int)uVar5;
        if (-1 < iVar2) {
          if ((int)param_1[0x10] != 2) goto LAB_1c00064eb;
          local_68[1] = 0;
          iVar2 = (**(code **)(*(longlong *)(param_1[5] + 0x28) + 0x38))
                            (param_1[5],local_res20,local_68,0,local_68 + 1);
          if (-1 < iVar2) {
            uVar3 = local_res20[0];
            if (0xffff < local_res20[0]) {
              uVar3 = 0xffff;
            }
            *(short *)(param_1 + 0x1c) = (short)uVar3;
            uVar3 = local_68[0];
            if (0xffff < local_68[0]) {
              uVar3 = 0xffff;
            }
            *(short *)((longlong)param_1 + 0xe2) = (short)uVar3;
            iVar2 = (**(code **)(*(longlong *)(param_1[5] + 0x28) + 0x40))
                              (param_1[5],param_1[3],local_res8);
            if (-1 < iVar2) {
              uVar5 = RdmaAllocateAndPostReceives(param_1);
              iVar2 = (int)uVar5;
              if (-1 < iVar2) {
                KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_50);
                if ((int)param_1[0x10] == 2) {
                  *(undefined1 *)((longlong)param_1 + 0xd1) = 1;
                  *(undefined4 *)(param_1 + 0x10) = 3;
                }
                KeReleaseInStackQueuedSpinLock(&local_50);
                goto LAB_1c0006381;
              }
            }
          }
        }
      }
      else {
LAB_1c00064eb:
        iVar2 = -0x3ffffdf4;
      }
    }
  }
LAB_1c000630f:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x24,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar2);
  }
  ExAcquireRundownProtectionEx(param_1 + 0xd,1);
  ExReleaseRundownProtectionEx(plVar6,1);
  RdmaDisconnect((longlong)param_1);
  plVar6 = param_1 + 0xd;
  iVar7 = iVar2;
LAB_1c0006381:
  ExReleaseRundownProtectionEx(plVar6,1);
  return iVar7;
}



===== RdmaDisconnectWorkItem @ 1c00065d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaDisconnectWorkItem(undefined8 param_1,longlong param_2)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  ExWaitForRundownProtectionRelease(param_2 + 0x60);
  (**(code **)(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x28) + 0x10))();
  NdkCloseQueuePair(*(longlong *)(param_2 + 0x28));
  *(undefined8 *)(param_2 + 0x28) = 0;
  if ((*(char *)(param_2 + 0xd1) != '\0') && (*(code **)(param_2 + 0x48) != (code *)0x0)) {
    (**(code **)(param_2 + 0x48))(*(undefined8 *)(param_2 + 0x58));
  }
  KeAcquireInStackQueuedSpinLock(param_2 + 0x78,&local_28);
  *(undefined4 *)(param_2 + 0x80) = 5;
  KeSetEvent(param_2 + 0x88,0,0);
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== RdmaNdkConnectEventCallback @ 1c0006690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaNdkConnectEventCallback(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 local_res8 [2];
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_res8[0] = 0x80;
  local_18 = 1;
  local_10 = 0x10;
  puVar2 = (undefined8 *)ExAllocatePool3(0x40,0x90,0x616d6452,&local_18,1);
  if (puVar2 != (undefined8 *)0x0) {
    iVar1 = (**(code **)(*(longlong *)(param_2 + 0x28) + 0x48))(param_2,puVar2 + 2,local_res8);
    if ((-1 < iVar1) && (lVar3 = IoAllocateWorkItem(Driver), lVar3 != 0)) {
      puVar2[1] = param_2;
      *puVar2 = param_1;
      IoQueueWorkItemEx(lVar3,RdmaNdkConnectEventCallbackWorkItem,1,puVar2);
      return;
    }
    ExFreePoolWithTag(puVar2,0x616d6452);
  }
  (*(code *)**(undefined8 **)(param_2 + 0x28))(param_2,_guard_check_icall,0);
  return;
}



===== RdmaNdkConnectEventCallbackWorkItem @ 1c0006790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaNdkConnectEventCallbackWorkItem(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined2 uVar6;
  uint local_res10 [2];
  uint local_res20 [2];
  undefined4 local_58 [2];
  longlong *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_58[0] = 0;
  lVar1 = *param_2;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  plVar5 = (longlong *)0x0;
  local_50 = (longlong *)0x0;
  iVar2 = (**(code **)(*(longlong *)(param_2[1] + 0x28) + 0x38))
                    (param_2[1],local_res10,local_res20,0,local_58);
  if (iVar2 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,10,
                        &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar2);
    }
    goto LAB_1c0006a3d;
  }
  iVar2 = RdmaCreateServerSocket
                    (*(NET_IFINDEX *)(*(longlong *)(lVar1 + 0x18) + 0x10),param_2[1],
                     (short *)(param_2 + 2),lVar1,&local_50);
  plVar5 = local_50;
  if (iVar2 == 0) {
    *(undefined4 *)(local_50 + 0x10) = 2;
    uVar3 = local_res10[0];
    if (0xffff < local_res10[0]) {
      uVar3 = 0xffff;
    }
    *(short *)(local_50 + 0x1c) = (short)uVar3;
    uVar3 = local_res20[0];
    if (0xffff < local_res20[0]) {
      uVar3 = 0xffff;
    }
    *(short *)((longlong)local_50 + 0xe2) = (short)uVar3;
    ExAcquireRundownProtectionEx(local_50 + 0xc,1);
    uVar4 = NdkAccept((longlong)plVar5);
    iVar2 = (int)uVar4;
    if (iVar2 == 0) {
      if ((int)plVar5[0x10] == 2) {
        uVar4 = RdmaAllocateAndPostReceives(plVar5);
        iVar2 = (int)uVar4;
        if (iVar2 == 0) {
          if ((int)plVar5[0x10] == 2) {
            iVar2 = (**(code **)(lVar1 + 0x10))
                              (*(undefined8 *)(lVar1 + 8),plVar5,plVar5 + 9,plVar5 + 10,plVar5 + 0xb
                              );
            if (iVar2 == 0) {
              KeAcquireInStackQueuedSpinLock(plVar5 + 0xf,&local_48);
              *(undefined1 *)((longlong)plVar5 + 0xd1) = 1;
              if ((int)plVar5[0x10] == 2) {
                *(undefined4 *)(plVar5 + 0x10) = 3;
              }
              KeReleaseInStackQueuedSpinLock(&local_48);
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar6 = 0x10;
              goto LAB_1c0006888;
            }
          }
          else {
            iVar2 = -0x3ffffdf4;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar6 = 0xf;
              iVar2 = -0x3ffffdf4;
              goto LAB_1c0006888;
            }
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0xe;
          goto LAB_1c0006888;
        }
      }
      else {
        iVar2 = -0x3ffffdf4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0xd;
          iVar2 = -0x3ffffdf4;
          goto LAB_1c0006888;
        }
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0xc;
      goto LAB_1c0006888;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar6 = 0xb;
LAB_1c0006888:
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar6,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar2);
  }
  if (plVar5 != (longlong *)0x0) {
    ExReleaseRundownProtectionEx(plVar5 + 0xc,1);
  }
LAB_1c0006a3d:
  if (iVar2 < 0) {
    if (plVar5 == (longlong *)0x0) {
      (*(code *)**(undefined8 **)(param_2[1] + 0x28))(param_2[1],_guard_check_icall,0);
    }
    else {
      RdmaCloseSocket(plVar5);
    }
  }
  ExFreePoolWithTag(param_2,0x616d6452);
  IoFreeWorkItem(param_3);
  return;
}



===== RdmaProcessReceives @ 1c0006ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong * RdmaProcessReceives(longlong param_1,char *param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  plVar4 = (longlong *)0x0;
  do {
    uVar8 = (ulonglong)*(ushort *)(param_1 + 0xdc);
    uVar3 = *(undefined8 *)(param_1 + 0xf8);
    uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x28) + 0x20))();
    uVar6 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      return plVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,uVar8,0x11,
                        CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),(char)uVar2);
    }
    lVar7 = 0;
    plVar5 = plVar4;
    do {
      lVar1 = *(longlong *)(param_1 + 0xf8);
      plVar4 = *(longlong **)(lVar7 + 0x10 + lVar1);
      *(undefined4 *)(plVar4 + 3) = *(undefined4 *)(lVar7 + 4 + lVar1);
      *plVar4 = (longlong)plVar5;
      if (*(int *)(lVar7 + lVar1) < 0) {
        if (*param_2 == '\0') {
          *param_2 = '\x01';
          RdmaQueueDisconnectWorkItem(param_1,'\0');
          goto LAB_1c0006b5a;
        }
      }
      else {
LAB_1c0006b5a:
        if ((*param_2 == '\0') && (*(int *)(param_1 + 0x80) == 3)) {
          in_stack_ffffffffffffffd8 = 0;
          (**(code **)(param_1 + 0x50))(*(undefined8 *)(param_1 + 0x58),plVar4 + 4,(int)plVar4[3],0)
          ;
        }
      }
      lVar7 = lVar7 + 0x18;
      uVar6 = uVar6 - 1;
      plVar5 = plVar4;
    } while (uVar6 != 0);
  } while( true );
}



===== RdmaProcessReceivesEx @ 1c0006bb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong * RdmaProcessReceivesEx(longlong param_1,char *param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  undefined4 in_stack_ffffffffffffffc8;
  undefined4 in_stack_ffffffffffffffcc;
  
  plVar4 = (longlong *)0x0;
  uVar9 = 0;
  uVar10 = 0;
  do {
    uVar7 = (ulonglong)*(ushort *)(param_1 + 0xdc);
    uVar3 = *(undefined8 *)(param_1 + 0xf8);
    uVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x28) + 0x30))();
    uVar8 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      return plVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,uVar7,0x12,
                        CONCAT44(in_stack_ffffffffffffffcc,in_stack_ffffffffffffffc8),(char)uVar2);
    }
    lVar6 = 0;
    plVar5 = plVar4;
    do {
      lVar1 = *(longlong *)(param_1 + 0xf8);
      if (*(int *)(lVar6 + 0x18 + lVar1) == 0x8001) {
        uVar10 = *(undefined4 *)(lVar6 + 0x20 + lVar1);
        uVar9 = 1;
      }
      plVar4 = *(longlong **)(lVar6 + 0x10 + lVar1);
      *(undefined4 *)(plVar4 + 3) = *(undefined4 *)(lVar6 + 4 + lVar1);
      *plVar4 = (longlong)plVar5;
      if (*(int *)(lVar6 + lVar1) < 0) {
        if (*param_2 == '\0') {
          *param_2 = '\x01';
          RdmaQueueDisconnectWorkItem(param_1,'\0');
          goto LAB_1c0006c83;
        }
      }
      else {
LAB_1c0006c83:
        if ((*param_2 == '\0') && (*(int *)(param_1 + 0x80) == 3)) {
          in_stack_ffffffffffffffc8 = uVar10;
          (**(code **)(param_1 + 0x50))
                    (*(undefined8 *)(param_1 + 0x58),plVar4 + 4,(int)plVar4[3],uVar9);
        }
      }
      lVar6 = lVar6 + 0x28;
      uVar8 = uVar8 - 1;
      plVar5 = plVar4;
    } while (uVar8 != 0);
  } while( true );
}



===== RdmaQueueDisconnectWorkItem @ 1c0006ce8 =====

void RdmaQueueDisconnectWorkItem(longlong param_1,char param_2)

{
  int iVar1;
  bool bVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar2 = false;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x78,&local_28);
  iVar1 = *(int *)(param_1 + 0x80);
  if (iVar1 == 1) {
    *(undefined4 *)(param_1 + 0x80) = 5;
    KeSetEvent(param_1 + 0x88,0,0);
  }
  else if ((iVar1 == 2) || (iVar1 == 3)) {
    *(undefined4 *)(param_1 + 0x80) = 4;
    bVar2 = true;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (bVar2) {
    IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0x70),RdmaDisconnectWorkItem,1,param_1);
  }
  if (param_2 != '\0') {
    KeWaitForSingleObject(param_1 + 0x88,0,0,0,0);
  }
  return;
}



===== RdmaQueueSQWrs @ 1c0006ddc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaQueueSQWrs(longlong *param_1,longlong *param_2,uint param_3)

{
  longlong *plVar1;
  byte bVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong ***ppplVar8;
  longlong ***ppplVar9;
  longlong ****pppplVar10;
  byte bVar11;
  uint uVar12;
  longlong ****local_68;
  longlong *plStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_48 = 0;
  local_68 = (longlong ****)0x0;
  plStack_60 = (longlong *)0x0;
  uVar12 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar2 = *(byte *)(*param_1 + 0x30);
  bVar11 = 0;
  cVar6 = ExAcquireRundownProtectionEx(param_1 + 0xc,1);
  if (cVar6 == '\0') {
    do {
      plVar1 = param_2 + 3;
      plVar3 = param_2 + 4;
      param_2 = (longlong *)param_2[2];
      (*(code *)*plVar1)(0xc000020c,*plVar3);
    } while (param_2 != (longlong *)0x0);
  }
  else {
    KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_58);
    plVar1 = param_1 + 0x14;
    do {
      plVar3 = (longlong *)param_1[0x15];
      if ((longlong *)*plVar3 != plVar1) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *param_2 = (longlong)plVar1;
      param_2[1] = (longlong)plVar3;
      *plVar3 = (longlong)param_2;
      param_1[0x15] = (longlong)param_2;
      param_2 = (longlong *)param_2[2];
    } while (param_2 != (longlong *)0x0);
    pppplVar10 = (longlong ****)0x0;
    if ((char)param_1[0x1a] == '\0') {
      *(undefined1 *)(param_1 + 0x1a) = 1;
      do {
        local_68 = (longlong ****)*plVar1;
        plStack_60 = (longlong *)param_1[0x15];
        local_68[1] = (longlong ***)&local_68;
        *plStack_60 = (longlong)&local_68;
        param_1[0x15] = (longlong)plVar1;
        *plVar1 = (longlong)plVar1;
        KeReleaseInStackQueuedSpinLock(&local_58);
        pppplVar10 = local_68;
        if ((longlong *****)local_68 != &local_68) {
          do {
            if ((bVar2 & 4) != 0) {
              if ((bVar11 < 0x10) && ((longlong *****)*pppplVar10 != &local_68)) {
                uVar12 = 0x200;
                bVar11 = bVar11 + 1;
              }
              else {
                uVar12 = 0;
                bVar11 = 0;
              }
            }
            uVar12 = uVar12 | param_3;
            iVar7 = *(int *)(pppplVar10 + 5);
            if (iVar7 == 1) {
              lVar4 = param_1[8];
              if (*(char *)((longlong)pppplVar10 + 0x42) == '\0') {
                iVar7 = (**(code **)(*(longlong *)(lVar4 + 0x28) + 0x18))
                                  (lVar4,pppplVar10,pppplVar10[6],*(undefined2 *)(pppplVar10 + 8),
                                   uVar12);
              }
              else {
                iVar7 = (**(code **)(*(longlong *)(lVar4 + 0x28) + 0x50))
                                  (lVar4,pppplVar10,pppplVar10[6],*(undefined2 *)(pppplVar10 + 8),
                                   uVar12,*(undefined4 *)((longlong)pppplVar10 + 0x3c));
              }
LAB_1c0007040:
              if (iVar7 != 0) goto LAB_1c0007046;
            }
            else {
              if (iVar7 == 2) {
                iVar7 = NdkRead((longlong)param_1,(longlong)pppplVar10,uVar12);
                goto LAB_1c0007040;
              }
              if (iVar7 == 3) {
                iVar7 = NdkWrite((longlong)param_1,(longlong)pppplVar10,uVar12);
                goto LAB_1c0007040;
              }
              if (iVar7 == 4) {
                iVar7 = (**(code **)(*(longlong *)(param_1[8] + 0x28) + 0x30))
                                  (param_1[8],pppplVar10,pppplVar10[6],
                                   *(undefined4 *)(pppplVar10 + 10),pppplVar10[7],0,pppplVar10[9],
                                   pppplVar10[8],uVar12 | 0x38);
                goto LAB_1c0007040;
              }
              if (iVar7 == 5) {
                iVar7 = (**(code **)(*(longlong *)(param_1[8] + 0x28) + 0x38))
                                  (param_1[8],pppplVar10,pppplVar10[6],uVar12);
                goto LAB_1c0007040;
              }
              iVar7 = -0x3ffffff3;
LAB_1c0007046:
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2e,
                                   &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,
                                   (char)*(undefined4 *)(pppplVar10 + 5),(char)iVar7);
              }
              if (iVar7 != 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x2c,
                                    &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar7);
                }
                goto LAB_1c00070e9;
              }
            }
            pppplVar10 = (longlong ****)*pppplVar10;
          } while ((longlong *****)pppplVar10 != &local_68);
        }
        KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_58);
      } while ((longlong *)*plVar1 != plVar1);
      *(undefined1 *)(param_1 + 0x1a) = 0;
    }
    KeReleaseInStackQueuedSpinLock(&local_58);
    iVar7 = 0;
LAB_1c00070e9:
    ExReleaseRundownProtectionEx(param_1 + 0xc,1);
    if (iVar7 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x2d,
                          &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar7);
      }
      ppplVar8 = pppplVar10[3];
      ppplVar9 = pppplVar10[4];
      for (pppplVar10 = (longlong ****)*pppplVar10; (*(code *)ppplVar8)(iVar7,ppplVar9),
          (longlong *****)pppplVar10 != &local_68; pppplVar10 = (longlong ****)*pppplVar10) {
        ppplVar8 = pppplVar10[3];
        iVar7 = -0x3ffffdf4;
        ppplVar9 = pppplVar10[4];
      }
      RdmaQueueDisconnectWorkItem((longlong)param_1,'\0');
    }
  }
  return;
}



===== WPP_RECORDER_SF_L @ 1c00071c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_ca715d96931d395e776a8438613b8a57_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== RdmaAllocateSgl @ 1c0007270 =====

undefined8 * RdmaAllocateSgl(ushort param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_1c = 0;
  local_28 = 1;
  local_20 = 0x10;
  puVar1 = (undefined8 *)ExAllocatePool3(0x40,0x18,0x616d6452,&local_28,1);
  if (puVar1 != (undefined8 *)0x0) {
    local_18 = 1;
    local_c = 0;
    local_10 = 0x10;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    lVar2 = ExAllocatePool3(0x40,(ulonglong)param_1 << 4,0x616d6452,&local_18,1);
    puVar1[1] = lVar2;
    if (lVar2 == 0) {
      ExFreePoolWithTag(puVar1,0x616d6452);
      puVar1 = (undefined8 *)0x0;
    }
  }
  return puVar1;
}



===== RdmaFreeLam @ 1c0007338 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaFreeLam(longlong param_1)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x28) + 0x40))
            (*(longlong *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0x616d6452);
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaFreeLamBuffer @ 1c000738c =====

void RdmaFreeLamBuffer(longlong param_1)

{
  RdmaFreeLam(*(longlong *)(param_1 + 8));
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x10),0x616d6452);
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaFreeLamChain @ 1c00073d4 =====

void RdmaFreeLamChain(longlong *param_1)

{
  longlong *plVar1;
  
  do {
    plVar1 = (longlong *)*param_1;
    RdmaFreeLam((longlong)param_1);
    param_1 = plVar1;
  } while (plVar1 != (longlong *)0x0);
  return;
}



===== RdmaFreeSgl @ 1c00073f8 =====

void RdmaFreeSgl(longlong param_1)

{
  ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0x616d6452);
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaFreeSglChain @ 1c0007438 =====

void RdmaFreeSglChain(longlong *param_1)

{
  longlong *plVar1;
  
  do {
    plVar1 = (longlong *)*param_1;
    ExFreePoolWithTag(param_1[1],0x616d6452);
    ExFreePoolWithTag(param_1,0x616d6452);
    param_1 = plVar1;
  } while (plVar1 != (longlong *)0x0);
  return;
}



===== RdmaGetLBBuffer @ 1c000748c =====

longlong RdmaGetLBBuffer(longlong param_1)

{
  return param_1 + 0x20;
}



===== RdmaGetLamPage @ 1c0007498 =====

undefined8 RdmaGetLamPage(longlong param_1,uint param_2)

{
  return *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10 + (ulonglong)param_2 * 8);
}



===== RdmaBuildReadWRForOperation @ 1c00074ac =====

ulonglong RdmaBuildReadWRForOperation
                    (undefined8 *param_1,undefined8 *param_2,uint param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  piVar2 = (int *)0x0;
  if (*(int *)(param_1 + 0x10) == 3) {
    piVar2 = RdmaAllocateOperation(param_1,2);
    if (piVar2 == (int *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *(code **)(piVar2 + 4) = CompletionCallback;
      *(undefined8 *)(piVar2 + 6) = param_6;
      uVar3 = RdmaAllocateLamChain
                        (*(longlong *)*param_1,param_2,param_3,(undefined8 *)(piVar2 + 0x10));
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        piVar2[0x12] = param_3;
        uVar1 = RdmaBuildReadWorkRequests
                          ((longlong)piVar2,*(undefined4 *)((longlong)param_1 + 0xd4),param_4,
                           param_5);
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar4 = 0;
          goto LAB_1c0007558;
        }
      }
      RdmaFreeOperation(piVar2);
      piVar2 = (int *)0x0;
    }
  }
  else {
    uVar4 = 0xc0000184;
  }
LAB_1c0007558:
  *param_8 = piVar2;
  return uVar4;
}



===== RdmaBuildSendWRForOperation @ 1c0007584 =====

ulonglong RdmaBuildSendWRForOperation
                    (undefined8 *param_1,undefined8 *param_2,uint param_3,undefined8 param_4,
                    undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  piVar2 = (int *)0x0;
  if (*(int *)(param_1 + 0x10) == 3) {
    piVar2 = RdmaAllocateOperation(param_1,1);
    if (piVar2 == (int *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *(code **)(piVar2 + 4) = CompletionCallback;
      *(undefined8 *)(piVar2 + 6) = param_6;
      uVar3 = RdmaAllocateLamChain
                        (*(longlong *)*param_1,param_2,param_3,(undefined8 *)(piVar2 + 0xc));
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        piVar2[0xe] = param_3;
        uVar1 = RdmaBuildSendWorkRequests
                          ((longlong)piVar2,*(undefined4 *)((longlong)param_1 + 0xd4));
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar4 = 0;
          goto LAB_1c0007620;
        }
      }
      RdmaFreeOperation(piVar2);
      piVar2 = (int *)0x0;
    }
  }
  else {
    uVar4 = 0xc0000184;
  }
LAB_1c0007620:
  *param_8 = piVar2;
  return uVar4;
}



===== RdmaBuildWriteWRForOperation @ 1c0007648 =====

ulonglong RdmaBuildWriteWRForOperation
                    (undefined8 *param_1,undefined8 *param_2,uint param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  uint uVar1;
  int *piVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  piVar2 = (int *)0x0;
  if (*(int *)(param_1 + 0x10) == 3) {
    piVar2 = RdmaAllocateOperation(param_1,3);
    if (piVar2 == (int *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      *(code **)(piVar2 + 4) = CompletionCallback;
      *(undefined8 *)(piVar2 + 6) = param_6;
      uVar3 = RdmaAllocateLamChain
                        (*(longlong *)*param_1,param_2,param_3,(undefined8 *)(piVar2 + 0x14));
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        piVar2[0x16] = param_3;
        uVar1 = RdmaBuildWriteWorkRequests
                          ((longlong)piVar2,*(undefined4 *)((longlong)param_1 + 0xd4),param_4,
                           param_5);
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar4 = 0;
          goto LAB_1c00076f1;
        }
      }
      RdmaFreeOperation(piVar2);
      piVar2 = (int *)0x0;
    }
  }
  else {
    uVar4 = 0xc0000184;
  }
LAB_1c00076f1:
  *param_8 = piVar2;
  return uVar4;
}



===== RdmaFreeOperation @ 1c0007720 =====

void RdmaFreeOperation(int *param_1)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    plVar4 = *(longlong **)(param_1 + 0xc);
    if (*(longlong **)(param_1 + 0xc) != (longlong *)0x0) {
      do {
        plVar2 = (longlong *)*plVar4;
        RdmaFreeLam((longlong)plVar4);
        plVar4 = plVar2;
      } while (plVar2 != (longlong *)0x0);
      param_1[0xc] = 0;
      param_1[0xd] = 0;
    }
  }
  else if (iVar1 == 2) {
    plVar4 = *(longlong **)(param_1 + 0x10);
    if (*(longlong **)(param_1 + 0x10) != (longlong *)0x0) {
      do {
        plVar2 = (longlong *)*plVar4;
        RdmaFreeLam((longlong)plVar4);
        plVar4 = plVar2;
      } while (plVar2 != (longlong *)0x0);
      param_1[0x10] = 0;
      param_1[0x11] = 0;
    }
  }
  else if ((iVar1 == 3) &&
          (plVar4 = *(longlong **)(param_1 + 0x14),
          *(longlong **)(param_1 + 0x14) != (longlong *)0x0)) {
    do {
      plVar2 = (longlong *)*plVar4;
      RdmaFreeLam((longlong)plVar4);
      plVar4 = plVar2;
    } while (plVar2 != (longlong *)0x0);
    param_1[0x14] = 0;
    param_1[0x15] = 0;
  }
  while (lVar3 = *(longlong *)(param_1 + 2), lVar3 != 0) {
    *(undefined8 *)(param_1 + 2) = *(undefined8 *)(lVar3 + 0x10);
    RdmaFreeSqWorkRequest(lVar3);
  }
  param_1[0xb] = 0;
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaFreeOperationSqWrList @ 1c00077dc =====

void RdmaFreeOperationSqWrList(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  while (lVar1 != 0) {
    *(undefined8 *)(param_1 + 8) = *(undefined8 *)(lVar1 + 0x10);
    RdmaFreeSqWorkRequest(lVar1);
    lVar1 = *(longlong *)(param_1 + 8);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}



===== RdmaOperationSqWrCompletionCallback @ 1c0007820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaOperationSqWrCompletionCallback(int param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if ((param_1 < 0) &&
     ((*(int *)(param_2 + 0x28) == 0 || (*(int *)(param_2 + 0x28) == -0x3ffffee0)))) {
    *(int *)(param_2 + 0x28) = param_1;
  }
  piVar1 = (int *)(param_2 + 0x2c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = *(int *)(param_2 + 0x28);
    pcVar3 = *(code **)(param_2 + 0x10);
    uVar4 = *(undefined8 *)(param_2 + 0x18);
    if (iVar2 < 0) {
      RdmaQueueDisconnectWorkItem(*(longlong *)(param_2 + 0x20),'\0');
    }
    (*pcVar3)(iVar2,uVar4);
  }
  return;
}



===== RdmaFreeSqWorkRequest @ 1c000788c =====

void RdmaFreeSqWorkRequest(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if ((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 3)) && (*(longlong *)(param_1 + 0x30) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x616d6452);
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== SqGenericCompletionCallback @ 1c00078f0 =====

void SqGenericCompletionCallback(undefined4 param_1,longlong *param_2)

{
  RdmaFreeSqWorkRequest(*param_2);
  *(undefined4 *)(param_2 + 4) = param_1;
  KeSetEvent(param_2 + 1,0,0);
  return;
}



===== RdmaFreeRegisteredBuffer @ 1c0007934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaFreeRegisteredBuffer(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x30) != 0) {
    RdmaFreeSqWorkRequest(*(longlong *)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    RdmaFreeLam(*(longlong *)(param_1 + 0x28));
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 != 0) {
    (*(code *)**(undefined8 **)(lVar1 + 0x28))(lVar1,_guard_check_icall,0);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaInvalidateRegisteredBufferInner @ 1c00079a8 =====

void RdmaInvalidateRegisteredBufferInner(longlong *param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined8 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong local_30 [5];
  
  lVar1 = param_2[6];
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (lVar1 != 0) {
    if (param_3 == '\0') {
      RdmaFreeSqWorkRequest(lVar1);
    }
    else {
      local_30[0] = lVar1;
      KeInitializeEvent(local_30 + 1,0);
      *(longlong *)(param_2[6] + 0x30) = param_2[2];
      *(code **)(param_2[6] + 0x18) = SqGenericCompletionCallback;
      *(longlong **)(param_2[6] + 0x20) = local_30;
      RdmaQueueSQWrs(param_1,(longlong *)param_2[6],0);
      local_58 = 0;
      KeWaitForSingleObject(local_30 + 1,0,0,0);
    }
    param_2[6] = 0;
  }
  if (param_2[5] != 0) {
    RdmaFreeLam(param_2[5]);
    param_2[5] = 0;
  }
  param_2[4] = 0;
  *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_48);
  puVar5 = auStack_78;
  if (param_3 == '\0') {
LAB_1c0007ab9:
    plVar3 = param_1 + 0x16;
    plVar4 = (longlong *)param_1[0x17];
    if ((longlong *)*plVar4 == plVar3) goto LAB_1c0007ad0;
  }
  else {
    lVar1 = *param_2;
    if ((*(longlong **)(lVar1 + 8) == param_2) &&
       (plVar3 = (longlong *)param_2[1], (longlong *)*plVar3 == param_2)) {
      *plVar3 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar3;
      goto LAB_1c0007ab9;
    }
  }
  plVar4 = (longlong *)0x3;
  pcVar2 = (code *)swi(0x29);
  plVar3 = (longlong *)(*pcVar2)();
  puVar5 = auStack_70;
LAB_1c0007ad0:
  param_2[1] = (longlong)plVar4;
  *param_2 = (longlong)plVar3;
  *plVar4 = (longlong)param_2;
  plVar3[1] = (longlong)param_2;
  *(undefined8 *)(puVar5 + -8) = 0x1c0007aea;
  KeReleaseInStackQueuedSpinLock(puVar5 + 0x30);
  return;
}



===== RdmaRegisterBuffer @ 1c0007b08 =====

ulonglong RdmaRegisterBuffer(longlong *param_1,longlong param_2,undefined8 param_3,longlong *param_4
                            )

{
  longlong lVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  void *pvVar5;
  longlong *plVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong *plVar9;
  uint local_res18 [2];
  longlong *local_res20;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  longlong *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_res18[0] = 0;
  local_68 = 0;
  local_40 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = (longlong *)0x0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_res20 = param_4;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf);
  if ((int)param_1[0x10] < 4) {
    plVar9 = param_1 + 0x16;
    plVar8 = (longlong *)*plVar9;
    if (plVar8 == plVar9) {
      KeReleaseInStackQueuedSpinLock(&local_78);
      plVar8 = (longlong *)0x0;
LAB_1c0007ba7:
      uVar7 = 0xc000009a;
    }
    else {
      if (((longlong *)plVar8[1] != plVar9) ||
         (lVar1 = *plVar8, (longlong *)*(longlong *)(lVar1 + 8) != plVar8)) {
LAB_1c0007d62:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        uVar7 = (*pcVar2)();
        return uVar7;
      }
      *plVar9 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar9;
      KeReleaseInStackQueuedSpinLock(&local_78);
      plVar9 = plVar8 + 5;
      uVar4 = RdmaAllocateLam(*(longlong *)*param_1,param_2,0x8000,plVar9);
      uVar7 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        pvVar5 = RdmaAllocateSqWorkRequest(5);
        plVar8[6] = (longlong)pvVar5;
        if ((pvVar5 == (void *)0x0) ||
           (plVar6 = RdmaAllocateSqWorkRequest(4), plVar6 == (longlong *)0x0)) goto LAB_1c0007ba7;
        uVar4 = (ulonglong)*(uint *)(param_2 + 0x2c) + *(longlong *)(param_2 + 0x20) ^
                (ulonglong)plVar6 & 0x7ffffffffffff000;
        local_60 = plVar6;
        KeInitializeEvent(&uStack_58,0);
        plVar6[4] = (longlong)&local_60;
        plVar6[3] = (longlong)SqGenericCompletionCallback;
        plVar6[6] = plVar8[2];
        plVar6[7] = *(longlong *)(*plVar9 + 0x10) + 0x10;
        *(undefined4 *)(plVar6 + 10) = *(undefined4 *)(*(longlong *)(*plVar9 + 0x10) + 8);
        plVar6[9] = 0x8000;
        plVar6[8] = uVar4;
        RdmaQueueSQWrs(param_1,plVar6,0);
        uVar7 = RdmaPollForCompletionWithTimeout((longlong)param_1,(int *)local_res18);
        uVar3 = (uint)uVar7;
        uVar7 = uVar7 & 0xffffffff;
        plVar9 = plVar8;
        if ((uVar3 == 0) &&
           (uVar7 = (ulonglong)local_res18[0], uVar3 = local_res18[0], local_res18[0] == 0)) {
          plVar8[4] = uVar4;
          *(undefined4 *)((longlong)plVar8 + 0x1c) = 0x8000;
          KeAcquireInStackQueuedSpinLock(param_1 + 0xf,&local_78);
          plVar6 = (longlong *)param_1[0x19];
          if ((longlong *)*plVar6 != param_1 + 0x18) goto LAB_1c0007d62;
          *plVar8 = (longlong)(param_1 + 0x18);
          plVar8[1] = (longlong)plVar6;
          *plVar6 = (longlong)plVar8;
          param_1[0x19] = (longlong)plVar8;
          KeReleaseInStackQueuedSpinLock(&local_78);
          goto LAB_1c0007d40;
        }
        if (-1 < (int)uVar3) goto LAB_1c0007d40;
      }
    }
  }
  else {
    KeReleaseInStackQueuedSpinLock(&local_78);
    uVar7 = 0xc000020c;
    plVar8 = (longlong *)0x0;
  }
  RdmaQueueDisconnectWorkItem((longlong)param_1,'\0');
  plVar9 = (longlong *)0;
  if (plVar8 != (longlong *)0x0) {
    RdmaInvalidateRegisteredBufferInner(param_1,plVar8,'\0');
    plVar9 = (longlong *)0;
  }
LAB_1c0007d40:
  *local_res20 = (longlong)plVar9;
  return uVar7;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c0007d70 =====

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



===== __GSHandlerCheck @ 1c0007dc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0007dec =====

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



===== __cpu_features_init @ 1c0007e60 =====

/* WARNING: Removing unreachable block (ram,0x0001c0007eca) */
/* WARNING: Removing unreachable block (ram,0x0001c0007e79) */
/* WARNING: Removing unreachable block (ram,0x0001c0007e6a) */

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



===== __security_check_cookie @ 1c0007f30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007f70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007fa0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007fa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007fd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0008040 =====

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



===== memset @ 1c0008340 =====

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



===== __memset_repmovs @ 1c0008480 =====

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



===== __memset_query @ 1c0008500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0008580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00086c0 =====

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



===== __memset_spec_plain @ 1c0008740 =====

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



===== WppCleanupKm @ 1c000f008 =====

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



===== WppInitKm @ 1c000f0b8 =====

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



===== WppLoadTracingSupport @ 1c000f194 =====

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



===== WppTraceCallback @ 1c000f2e0 =====

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



===== NdkAccept @ 1c000f568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong NdkAccept(longlong param_1)

{
  ulonglong uVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_38,0,0);
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28) + 0x28))
                    (*(longlong *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x40),
                     *(undefined2 *)(param_1 + 0xe0),*(undefined2 *)(param_1 + 0xe2),0,0,
                     NdkDisconnectEventCallback,param_1,NdkFnCompletionCallback,&local_38);
  if ((int)uVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar1 = uStack_20 & 0xffffffff;
  }
  return uVar1;
}



===== NdkBuildLam @ 1c000f630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong NdkBuildLam(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 param_5,undefined8 param_6)

{
  ulonglong uVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_38,0,0);
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x38))
                    (param_1,param_2,param_3,NdkFnCompletionCallback,0,param_4,param_5,param_6);
  if ((int)uVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar1 = uStack_20 & 0xffffffff;
  }
  return uVar1;
}



===== NdkCloseQueuePair @ 1c000f708 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NdkCloseQueuePair(longlong param_1)

{
  int iVar1;
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
  KeInitializeEvent(&local_38,0,0);
  iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x28))
                    (param_1,NdkCloseFnCompletionCallback,&local_38);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
  }
  return;
}



===== NdkCompleteConnect @ 1c000f78c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong NdkCompleteConnect(longlong param_1)

{
  ulonglong uVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,0,0);
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x28) + 0x20))
                    (*(longlong *)(param_1 + 0x28),NdkDisconnectEventCallback,param_1,
                     NdkFnCompletionCallback,&local_38);
  if ((int)uVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar1 = uStack_20 & 0xffffffff;
  }
  return uVar1;
}



===== NdkConnect @ 1c000f824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong NdkConnect(longlong *param_1)

{
  short *psVar1;
  short *psVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,0,0);
  psVar1 = (short *)param_1[4];
  if (psVar1 == (short *)0x0) {
    uVar4 = 0;
  }
  else if (*psVar1 == 2) {
    uVar4 = 0x10;
  }
  else {
    uVar4 = 0x1c;
    if (*psVar1 != 0x17) {
      uVar4 = 0;
    }
  }
  psVar2 = (short *)param_1[3];
  if (psVar2 == (short *)0x0) {
    uVar5 = 0;
  }
  else if (*psVar2 == 2) {
    uVar5 = 0x10;
  }
  else {
    uVar5 = 0x1c;
    if (*psVar2 != 0x17) {
      uVar5 = 0;
    }
  }
  uVar3 = (**(code **)(*(longlong *)(param_1[5] + 0x28) + 0x10))
                    (param_1[5],param_1[8],psVar2,uVar5,psVar1,uVar4,
                     *(undefined2 *)(*param_1 + 0x18),*(undefined2 *)(*param_1 + 0x1a),0,0,
                     NdkFnCompletionCallback,&local_38);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar3 = uStack_20 & 0xffffffff;
  }
  return uVar3;
}



===== NdkCreateCompletionQueue @ 1c000f964 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NdkCreateCompletionQueue
              (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 *param_6)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_38,0,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x10))
                    (param_1,param_2,param_3,param_4,0,NdkCreateFnCompletionCallback,&local_38,
                     param_6);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_6 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_6 = 0;
  }
  return iVar1;
}



===== NdkCreateListener @ 1c000fa58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NdkCreateListener(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_38,0,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x30))
                    (param_1,RdmaNdkConnectEventCallback,param_3,NdkCreateFnCompletionCallback,
                     &local_38,param_4);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_4 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_4 = 0;
  }
  return iVar1;
}



===== NdkCreateQueuePair @ 1c000fb20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NdkCreateQueuePair(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                      undefined8 *param_9)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_38,0,0);
  iVar1 = (**(code **)(*(longlong *)(param_1 + 0x28) + 0x28))
                    (param_1,param_2,param_3,param_4,CONCAT44(uVar2,param_5),param_6,param_7,param_8
                     ,0,NdkCreateFnCompletionCallback,&local_38,param_9);
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    *param_9 = local_18;
    iVar1 = (int)uStack_20;
  }
  if (iVar1 < 0) {
    *param_9 = 0;
  }
  return iVar1;
}



===== NdkDeInitialize @ 1c000fc48 =====

void NdkDeInitialize(void)

{
  if (DAT_1c000c338 != '\0') {
    WskReleaseProviderNPI(&DAT_1c000c350);
    DAT_1c000c338 = '\0';
  }
  if (DAT_1c000c339 != '\0') {
    WskDeregister(&DAT_1c000c350);
    DAT_1c000c339 = '\0';
  }
  return;
}



===== NdkInitialize @ 1c000fca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NdkInitialize(void)

{
  int iVar1;
  undefined8 local_18;
  undefined *local_10;
  
  local_18 = 0;
  local_10 = &DAT_1c000a340;
  iVar1 = WskRegister(&local_18,&DAT_1c000c350);
  if (-1 < iVar1) {
    DAT_1c000c339 = 1;
    iVar1 = WskCaptureProviderNPI(&DAT_1c000c350,0,&DAT_1c000c368);
    if (-1 < iVar1) {
      DAT_1c000c338 = 1;
      iVar1 = (**(code **)(DAT_1c000c370 + 0x18))
                        (DAT_1c000c368,0x4e444b44,0,0,0x10,&DAT_1c000c378,0,0);
      if (-1 < iVar1) {
        return iVar1;
      }
    }
  }
  NdkDeInitialize();
  return iVar1;
}



===== RdmaCloseAdapter @ 1c000fd64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaCloseAdapter(longlong *param_1)

{
  if (*param_1 != 0) {
    (*DAT_1c000c380)(DAT_1c000c368);
  }
  if (param_1[1] != 0) {
    ExFreePoolWithTag(param_1[1],0x616d6452);
  }
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaOpenAdapter @ 1c000fdc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaOpenAdapter(NET_IFINDEX param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  ushort *_Dst;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined4 local_res10 [2];
  NET_LUID local_res18 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_60 = 0x10;
  local_res18[0].Value = 0;
  local_68 = 1;
  plVar4 = (longlong *)ExAllocatePool3(0x40,0x38,0x616d6452,&local_68,1);
  if (plVar4 == (longlong *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    local_50 = 0x10;
    local_58 = 1;
    *plVar4 = 0;
    plVar4[1] = 0;
    plVar4[2] = 0;
    plVar4[3] = 0;
    plVar4[4] = 0;
    plVar4[5] = 0;
    plVar4[6] = 0;
    _Dst = (ushort *)ExAllocatePool3(0x40,0x68,0x616d6452,&local_58,1);
    if (_Dst == (ushort *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      local_res10[0] = 2;
      iVar3 = (*DAT_1c000c378)(DAT_1c000c368,2,param_1,plVar4);
      if (-1 < iVar3) {
        lVar6 = *plVar4;
        local_res10[0] = 0x68;
        memset(_Dst,0,0x68);
        iVar3 = (**(code **)(*(longlong *)(lVar6 + 0x28) + 8))(lVar6,_Dst,local_res10);
        if (-1 < iVar3) {
          if ((*(uint *)(_Dst + 0x2e) & 2) == 0) {
            iVar3 = -0x3fffff45;
          }
          else {
            *(NET_IFINDEX *)(plVar4 + 2) = param_1;
            *(byte *)(plVar4 + 6) =
                 (byte)(*(uint *)(_Dst + 0x2e) >> 2) & 1 | *(byte *)(plVar4 + 6) & 0xfe;
            uVar9 = *(uint *)(_Dst + 0x26);
            uVar2 = uVar9;
            if (0xffff < uVar9) {
              uVar2 = 0xffff;
            }
            if (uVar2 < *(uint *)(_Dst + 0x20)) {
              if (0xffff < uVar9) {
                uVar9 = 0xffff;
              }
            }
            else {
              uVar9 = *(uint *)(_Dst + 0x20);
            }
            *(short *)((longlong)plVar4 + 0x14) = (short)uVar9;
            uVar9 = *(uint *)(_Dst + 0x26);
            uVar2 = uVar9;
            if (0xffff < uVar9) {
              uVar2 = 0xffff;
            }
            if (uVar2 < *(uint *)(_Dst + 0x22)) {
              if (0xffff < uVar9) {
                uVar9 = 0xffff;
              }
            }
            else {
              uVar9 = *(uint *)(_Dst + 0x22);
            }
            *(short *)((longlong)plVar4 + 0x16) = (short)uVar9;
            uVar9 = *(uint *)(_Dst + 0x1c);
            if (0xffff < uVar9) {
              uVar9 = 0xffff;
            }
            *(short *)(plVar4 + 3) = (short)uVar9;
            uVar9 = *(uint *)(_Dst + 0x1e);
            if (0xffff < uVar9) {
              uVar9 = 0xffff;
            }
            *(short *)((longlong)plVar4 + 0x1a) = (short)uVar9;
            uVar9 = *(uint *)(_Dst + 0x10);
            if (0xffff < uVar9) {
              uVar9 = 0xffff;
            }
            *(short *)((longlong)plVar4 + 0x1c) = (short)uVar9;
            uVar9 = *(uint *)(_Dst + 0x14);
            if (0x80 < uVar9) {
              uVar9 = 0x80;
            }
            *(short *)((longlong)plVar4 + 0x22) = (short)uVar9;
            uVar10 = (ulonglong)*(uint *)(_Dst + 0x18);
            uVar8 = *(ulonglong *)(_Dst + 8);
            uVar9 = uVar9 * 0x200000;
            uVar7 = (ulonglong)uVar9;
            if (0x10000 < uVar9) {
              uVar7 = 0x10000;
            }
            uVar5 = uVar10;
            if (uVar8 <= uVar10) {
              uVar5 = uVar8;
            }
            if (uVar7 < uVar5) {
              if (0x10000 < uVar9) {
                uVar9 = 0x10000;
              }
              uVar8 = (ulonglong)uVar9;
            }
            else if (uVar10 < uVar8) {
              uVar8 = uVar10;
            }
            *(int *)((longlong)plVar4 + 0x24) = (int)uVar8;
            uVar9 = *(uint *)(_Dst + 0x12);
            if (0x80 < uVar9) {
              uVar9 = 0x80;
            }
            *(short *)((longlong)plVar4 + 0x1e) = (short)uVar9;
            uVar2 = *(uint *)(_Dst + 0x18);
            uVar8 = *(ulonglong *)(_Dst + 8);
            uVar9 = uVar9 << 0x15;
            uVar1 = uVar9;
            if (uVar2 <= uVar9) {
              uVar1 = uVar2;
            }
            if (uVar1 < uVar8) {
              if (uVar2 <= uVar9) {
                uVar9 = uVar2;
              }
              uVar8 = (ulonglong)uVar9;
            }
            *(int *)(plVar4 + 5) = (int)uVar8;
            uVar9 = *(uint *)(_Dst + 0x16);
            if (0x80 < uVar9) {
              uVar9 = 0x80;
            }
            *(short *)(plVar4 + 4) = (short)uVar9;
            uVar2 = *(uint *)(_Dst + 0x18);
            uVar8 = *(ulonglong *)(_Dst + 8);
            uVar9 = uVar9 << 0x15;
            uVar1 = uVar9;
            if (uVar2 <= uVar9) {
              uVar1 = uVar2;
            }
            if (uVar1 < uVar8) {
              if (uVar2 <= uVar9) {
                uVar9 = uVar2;
              }
              uVar8 = (ulonglong)uVar9;
            }
            *(int *)((longlong)plVar4 + 0x2c) = (int)uVar8;
            if ((1 < *_Dst) || ((*_Dst == 1 && (1 < _Dst[1])))) {
              *(byte *)(plVar4 + 6) = *(byte *)(plVar4 + 6) | 6;
            }
            local_40 = 0x10;
            local_48 = 1;
            lVar6 = ExAllocatePool3(0x40,0x202,0x616d6452,&local_48,1);
            plVar4[1] = lVar6;
            if (lVar6 == 0) {
              iVar3 = -0x3fffff66;
            }
            else {
              iVar3 = ConvertInterfaceIndexToLuid(param_1,local_res18);
              if (-1 < iVar3) {
                iVar3 = ConvertInterfaceLuidToAlias(local_res18,(PWSTR)plVar4[1],0x101);
              }
            }
          }
        }
      }
      ExFreePoolWithTag(_Dst,0x616d6452);
      if (-1 < iVar3) goto LAB_1c00100f2;
    }
    RdmaCloseAdapter(plVar4);
    plVar4 = (longlong *)0x0;
  }
LAB_1c00100f2:
  *param_2 = plVar4;
  return iVar3;
}



===== RdmaAllocateAndPostReceives @ 1c0010118 =====

ulonglong RdmaAllocateAndPostReceives(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined2 uVar7;
  longlong local_res8;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_res8 = 0;
  local_1c = 0;
  uVar1 = *(uint *)((longlong)param_1 + 0xec);
  local_28 = 1;
  local_20 = 0x10;
  lVar3 = ExAllocatePool3(0x40,((-(uint)((*(byte *)(*param_1 + 0x30) & 2) != 0) & 0x10) + 0x18) *
                               (uint)*(ushort *)((longlong)param_1 + 0xdc),0x616d6452,&local_28,1);
  param_1[0x1f] = lVar3;
  if (lVar3 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar6 = 0;
    do {
      uVar4 = RdmaAllocateLamBuffer
                        (*(longlong *)*param_1,*(undefined4 *)((longlong)param_1 + 0xd4),uVar1,
                         *(ushort *)((longlong)param_1 + 0xe4),&local_res8);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001029f;
        uVar7 = 0x16;
LAB_1c0010279:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar7,
                          &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)uVar5);
LAB_1c001029f:
        if (-1 < (int)uVar5) {
          return uVar5;
        }
        if (local_res8 == 0) {
          return uVar5;
        }
        RdmaFreeLamBuffer(local_res8);
        return uVar5;
      }
      uVar2 = NdkReceive((longlong)param_1,local_res8);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001029f;
        uVar7 = 0x17;
        goto LAB_1c0010279;
      }
      uVar6 = uVar6 + 1;
      ExAcquireRundownProtectionEx(param_1 + 0xd,1);
    } while (uVar6 < *(ushort *)((longlong)param_1 + 0xdc));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x18,
                        &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,
                        (char)*(ushort *)((longlong)param_1 + 0xdc));
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== RdmaCloseListenSocket @ 1c00102d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RdmaCloseListenSocket(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*param_1 != 0) {
    NdkPauseListener(*param_1);
    lVar1 = *param_1;
    local_18 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_38,0,0);
    iVar2 = (*(code *)**(undefined8 **)(lVar1 + 0x28))(lVar1,NdkCloseFnCompletionCallback,&local_38)
    ;
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
    }
  }
  if (param_1[4] != 0) {
    ExFreePoolWithTag(param_1[4],0x616d6452);
  }
  if ((longlong *)param_1[3] != (longlong *)0x0) {
    RdmaCloseAdapter((longlong *)param_1[3]);
  }
  ExFreePoolWithTag(param_1,0x616d6452);
  return;
}



===== RdmaCreateClientSocket @ 1c00103ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaCreateClientSocket
              (NET_IFINDEX param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  undefined8 *local_res18;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res18 = (undefined8 *)0x0;
  iVar3 = RdmaCreateSocket(param_1,&local_res18);
  puVar4 = local_res18;
  if (iVar3 == 0) {
    puVar1 = local_res18 + 5;
    local_38 = 0;
    uStack_30 = 0;
    lVar2 = *(longlong *)*local_res18;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_38,0,0);
    iVar3 = (**(code **)(*(longlong *)(lVar2 + 0x28) + 0x28))
                      (lVar2,NdkCreateFnCompletionCallback,&local_38,puVar1);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      *puVar1 = local_18;
      iVar3 = (int)uStack_20;
    }
    if (iVar3 < 0) {
      *puVar1 = 0;
    }
    else if (iVar3 == 0) {
      puVar4[9] = _guard_check_icall;
      puVar4[10] = ReceiveCallback;
      puVar4[0xb] = param_4;
      *(undefined4 *)(puVar4 + 1) = 0;
      iVar3 = 0;
      *(undefined4 *)(puVar4 + 0x10) = 1;
      goto LAB_1c0010519;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x22;
      goto LAB_1c00104b5;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar5 = 0x21;
LAB_1c00104b5:
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar5,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar3);
  }
  if ((iVar3 < 0) && (puVar4 != (undefined8 *)0x0)) {
    RdmaCloseSocket(puVar4);
    puVar4 = (undefined8 *)0x0;
  }
LAB_1c0010519:
  *param_5 = puVar4;
  return iVar3;
}



===== RdmaCreateListenSocket @ 1c0010544 =====

int RdmaCreateListenSocket
              (NET_IFINDEX param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined2 uVar4;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_38 = 1;
  local_30 = 0x10;
  plVar2 = (longlong *)ExAllocatePool3(0x40,0x28,0x616d6452,&local_38,1);
  if (plVar2 == (longlong *)0x0) {
    iVar1 = -0x3fffff66;
    goto LAB_1c0010637;
  }
  plVar3 = plVar2 + 3;
  *plVar2 = 0;
  plVar2[1] = 0;
  plVar2[2] = 0;
  plVar2[3] = 0;
  plVar2[4] = 0;
  iVar1 = RdmaOpenAdapter(param_1,plVar3);
  if (iVar1 == 0) {
    iVar1 = NdkCreateListener(*(longlong *)plVar2[3],plVar3,plVar2,plVar2);
    if (iVar1 == 0) {
      plVar2[1] = param_3;
      plVar2[2] = (longlong)AcceptCallback;
      *param_4 = plVar2;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x26;
      goto LAB_1c0010614;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar4 = 0x25;
LAB_1c0010614:
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar4,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar1);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1c0010637:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x27,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar1);
  }
  if (plVar2 != (longlong *)0x0) {
    RdmaCloseListenSocket(plVar2);
  }
  return iVar1;
}



===== RdmaCreateServerSocket @ 1c00106b0 =====

int RdmaCreateServerSocket
              (NET_IFINDEX param_1,undefined8 param_2,short *param_3,longlong param_4,
              undefined8 *param_5)

{
  short sVar1;
  short *_Src;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  size_t _Size;
  undefined8 *puVar5;
  size_t _Size_00;
  undefined8 *local_28;
  undefined8 local_20;
  
  local_28 = (undefined8 *)0x0;
  iVar2 = RdmaCreateSocket(param_1,&local_28);
  puVar5 = local_28;
  if (-1 < iVar2) {
    _Size = 0x1c;
    if (param_3 == (short *)0x0) {
      uVar4 = 0;
    }
    else if (*param_3 == 2) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = 0x1c;
      if (*param_3 != 0x17) {
        uVar4 = 0;
      }
    }
    local_20 = 0x10;
    local_28 = (undefined8 *)0x1;
    lVar3 = ExAllocatePool3(0x40,uVar4,0x616d6452,&local_28,1);
    puVar5[4] = lVar3;
    if (lVar3 != 0) {
      if (*(short **)(param_4 + 0x20) == (short *)0x0) {
        uVar4 = 0;
      }
      else {
        sVar1 = **(short **)(param_4 + 0x20);
        if (sVar1 == 2) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = 0x1c;
          if (sVar1 != 0x17) {
            uVar4 = 0;
          }
        }
      }
      local_20 = 0x10;
      local_28 = (undefined8 *)0x1;
      lVar3 = ExAllocatePool3(0x40,uVar4,0x616d6452,&local_28,1);
      puVar5[3] = lVar3;
      if (lVar3 != 0) {
        if (param_3 == (short *)0x0) {
          _Size_00 = 0;
        }
        else if (*param_3 == 2) {
          _Size_00 = 0x10;
        }
        else {
          _Size_00 = 0x1c;
          if (*param_3 != 0x17) {
            _Size_00 = 0;
          }
        }
        memcpy((void *)puVar5[4],param_3,_Size_00);
        _Src = *(short **)(param_4 + 0x20);
        if (_Src == (short *)0x0) {
          _Size = 0;
        }
        else if (*_Src == 2) {
          _Size = 0x10;
        }
        else if (*_Src != 0x17) {
          _Size = 0;
        }
        memcpy((void *)puVar5[3],_Src,_Size);
        *(undefined4 *)(puVar5 + 1) = 1;
        iVar2 = 0;
        puVar5[5] = param_2;
        *(undefined4 *)(puVar5 + 0x10) = 1;
        goto LAB_1c0010767;
      }
    }
    iVar2 = -0x3fffff66;
  }
  if (puVar5 != (undefined8 *)0x0) {
    RdmaCloseSocket(puVar5);
    puVar5 = (undefined8 *)0x0;
  }
LAB_1c0010767:
  *param_5 = puVar5;
  return iVar2;
}



===== RdmaCreateSocket @ 1c0010878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaCreateSocket(NET_IFINDEX param_1,undefined8 *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong *_Dst;
  longlong lVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  ushort uVar8;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar10;
  undefined8 uVar9;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  
  local_70 = 0x10;
  local_78 = 1;
  uVar9 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff58 >> 0x20),1);
  _Dst = (longlong *)ExAllocatePool3(0x40,0x108,0x616d6452,&local_78,uVar9);
  uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
  if (_Dst == (longlong *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x108);
    KeInitializeSpinLock(_Dst + 0xf);
    *(undefined4 *)(_Dst + 0x10) = 0;
    KeInitializeEvent(_Dst + 0x11,0,0);
    plVar2 = _Dst + 0x14;
    _Dst[0x15] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    plVar2 = _Dst + 0x16;
    _Dst[0x17] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    plVar2 = _Dst + 0x18;
    _Dst[0x19] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
    ExInitializeRundownProtection(_Dst + 0xc);
    ExInitializeRundownProtection(_Dst + 0xd);
    lVar5 = IoAllocateWorkItem(Driver);
    _Dst[0xe] = lVar5;
    if (lVar5 != 0) {
      local_60 = 0x10;
      local_68 = 1;
      uVar9 = CONCAT44(uVar10,1);
      lVar5 = ExAllocatePool3(0x40,0xc00,0x616d6452,&local_68);
      _Dst[0x20] = lVar5;
      if (lVar5 != 0) {
        iVar4 = RdmaOpenAdapter(param_1,_Dst);
        if (iVar4 < 0) goto LAB_1c00109ba;
        plVar3 = (longlong *)*_Dst;
        plVar2 = _Dst + 2;
        local_38 = 0;
        lVar5 = *plVar3;
        local_58 = 0;
        uStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        KeInitializeEvent(&local_58,0,0);
        iVar4 = (**(code **)(*(longlong *)(lVar5 + 0x28) + 0x18))
                          (lVar5,NdkCreateFnCompletionCallback,&local_58,plVar2);
        if (iVar4 == 0x103) {
          uVar9 = 0;
          KeWaitForSingleObject(&local_58,0,0,0);
          *plVar2 = local_38;
          iVar4 = (int)uStack_40;
        }
        if (iVar4 < 0) {
          *plVar2 = 0;
LAB_1c0010b02:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x19;
LAB_1c0010b23:
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar7,
                              &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar4);
          }
        }
        else {
          if (iVar4 != 0) goto LAB_1c0010b02;
          (**(code **)(*(longlong *)(*plVar2 + 0x28) + 0x38))(*plVar2,(longlong)_Dst + 0xd4);
          uVar8 = *(ushort *)((longlong)plVar3 + 0x14);
          *(ushort *)(_Dst + 0x1b) = uVar8;
          *(undefined2 *)((longlong)_Dst + 0xda) = *(undefined2 *)((longlong)plVar3 + 0x16);
          *(undefined2 *)((longlong)_Dst + 0xde) = *(undefined2 *)((longlong)plVar3 + 0x1c);
          if (0x20 < uVar8) {
            uVar8 = 0x20;
          }
          *(ushort *)((longlong)_Dst + 0xdc) = uVar8;
          uVar8 = 0;
          *(undefined2 *)((longlong)_Dst + 0xe4) = *(undefined2 *)((longlong)plVar3 + 0x22);
          *(undefined2 *)((longlong)_Dst + 0xe6) = *(undefined2 *)((longlong)plVar3 + 0x1e);
          *(short *)(_Dst + 0x1d) = (short)plVar3[4];
          *(undefined4 *)((longlong)_Dst + 0xec) = *(undefined4 *)((longlong)plVar3 + 0x24);
          *(int *)(_Dst + 0x1e) = (int)plVar3[5];
          *(undefined4 *)((longlong)_Dst + 0xf4) = *(undefined4 *)((longlong)plVar3 + 0x2c);
          do {
            uVar6 = RdmaAllocateRegisteredBuffer((longlong)_Dst);
            iVar4 = (int)uVar6;
            if (iVar4 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0010c61;
              uVar7 = 0x1a;
              goto LAB_1c0010b23;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < 0x200);
          plVar2 = _Dst + 6;
          iVar4 = NdkCreateCompletionQueue
                            (*plVar3,(uint)*(ushort *)(_Dst + 0x1b),NdkRcqNotificationEventCallback,
                             _Dst,uVar9,plVar2);
          if (iVar4 == 0) {
            plVar1 = _Dst + 7;
            iVar4 = NdkCreateCompletionQueue
                              (*plVar3,(uint)*(ushort *)((longlong)_Dst + 0xda),
                               NdkScqNotificationEventCallback,_Dst,uVar9,plVar1);
            if (iVar4 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar7 = 0x1c;
                goto LAB_1c0010c38;
              }
              goto LAB_1c0010c61;
            }
            if ((*(byte *)(plVar3 + 6) & 1) != 0) {
              iVar4 = (**(code **)(*(longlong *)(*plVar2 + 0x28) + 0x28))(*plVar2,0x14,0xffffffff);
              if (iVar4 == 0) {
                iVar4 = (**(code **)(*(longlong *)(*plVar1 + 0x28) + 0x28))(*plVar1,0x14,0xffffffff)
                ;
                if (iVar4 == 0) goto LAB_1c0010d36;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar7 = 0x1e;
                  goto LAB_1c0010c38;
                }
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar7 = 0x1d;
                goto LAB_1c0010c38;
              }
              goto LAB_1c0010c61;
            }
LAB_1c0010d36:
            iVar4 = NdkCreateQueuePair(_Dst[2],*plVar2,*plVar1,_Dst,(uint)*(ushort *)(_Dst + 0x1b),
                                       (uint)*(ushort *)((longlong)_Dst + 0xda),
                                       (uint)*(ushort *)((longlong)_Dst + 0xe4),
                                       (uint)*(ushort *)((longlong)_Dst + 0xe6),_Dst + 8);
            if (iVar4 == 0) {
              iVar4 = 0;
              goto LAB_1c00109fa;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c0010c61;
            uVar7 = 0x1f;
            goto LAB_1c0010b23;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x1b;
LAB_1c0010c38:
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,uVar7,
                              &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar4);
          }
        }
LAB_1c0010c61:
        if (-1 < iVar4) goto LAB_1c00109fa;
        goto LAB_1c00109ba;
      }
    }
    iVar4 = -0x3fffff66;
  }
LAB_1c00109ba:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x20,
                       &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)param_1,(char)iVar4);
  }
  if (_Dst != (longlong *)0x0) {
    RdmaCloseSocket(_Dst);
    _Dst = (longlong *)0x0;
  }
LAB_1c00109fa:
  *param_2 = _Dst;
  return iVar4;
}



===== RdmaDisconnect @ 1c0010ddc =====

void RdmaDisconnect(longlong param_1)

{
  RdmaQueueDisconnectWorkItem(param_1,'\x01');
  return;
}



===== RdmaListen @ 1c0010df4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RdmaListen(longlong *param_1,short *param_2)

{
  longlong lVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_2 == (short *)0x0) {
    uVar3 = 0;
  }
  else if (*param_2 == 2) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 0x1c;
    if (*param_2 != 0x17) {
      uVar3 = 0;
    }
  }
  local_40 = 0x10;
  local_48 = 1;
  _Dst = (void *)ExAllocatePool3(0x40,uVar3,0x616d6452,&local_48,1);
  param_1[4] = (longlong)_Dst;
  if (_Dst == (void *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    memcpy(_Dst,param_2,(ulonglong)uVar3);
    lVar1 = *param_1;
    local_18 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_38,0,0);
    iVar2 = (**(code **)(*(longlong *)(lVar1 + 0x28) + 0x10))
                      (lVar1,param_2,uVar3,NdkFnCompletionCallback,&local_38);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      iVar2 = (int)uStack_20;
    }
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x28,
                          &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)iVar2);
      }
      ExFreePoolWithTag(param_1[4],0x616d6452);
      param_1[4] = 0;
    }
  }
  return iVar2;
}



===== RdmaSend @ 1c0010f90 =====

ulonglong RdmaSend(longlong *param_1,undefined8 *param_2,uint param_3,undefined8 param_4,
                  undefined8 param_5,undefined8 param_6,longlong param_7)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe8;
  
  param_7 = 0;
  uVar1 = RdmaBuildSendWRForOperation
                    (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffd8,param_6,
                     in_stack_ffffffffffffffe8,&param_7);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 == 0) {
    RdmaQueueSQWrs(param_1,*(longlong **)(param_7 + 8),0);
    uVar2 = 0x103;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,1,0x29,
                      &WPP_ca715d96931d395e776a8438613b8a57_Traceguids,(char)uVar1);
  }
  return uVar2;
}



===== RdmaAllocateLam @ 1c0011030 =====

ulonglong RdmaAllocateLam(longlong param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_2c = 0;
  local_38 = 1;
  local_30 = 0x10;
  puVar2 = (undefined8 *)ExAllocatePool3(0x40,0x28,0x616d6452,&local_38,1);
  if (puVar2 == (undefined8 *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    *puVar2 = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    local_1c = 0;
    puVar2[1] = param_1;
    local_28 = 1;
    local_20 = 0x10;
    iVar1 = (int)((ulonglong)(*(int *)(param_2 + 0x2c) + *(int *)(param_2 + 0x20) & 0xfff) + 0xfff +
                  (ulonglong)param_3 >> 0xc) * 8 + 0x10;
    *(int *)(puVar2 + 3) = iVar1;
    lVar3 = ExAllocatePool3(0x40,iVar1,0x616d6452,&local_28,1);
    puVar2[2] = lVar3;
    if (lVar3 == 0) {
      uVar5 = 0xc000009a;
    }
    else {
      uVar4 = NdkBuildLam(param_1,param_2,(ulonglong)param_3,lVar3,puVar2 + 3,
                          (longlong)puVar2 + 0x1c);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *(uint *)(puVar2 + 4) = param_3;
        uVar5 = 0;
        goto LAB_1c001115a;
      }
    }
    if (puVar2[2] != 0) {
      ExFreePoolWithTag(puVar2[2],0x616d6452);
    }
    ExFreePoolWithTag(puVar2,0x616d6452);
    puVar2 = (undefined8 *)0x0;
  }
LAB_1c001115a:
  *param_4 = puVar2;
  return uVar5;
}



===== RdmaAllocateLamBuffer @ 1c00111b0 =====

ulonglong RdmaAllocateLamBuffer
                    (longlong param_1,undefined4 param_2,uint param_3,ushort param_4,
                    undefined8 *param_5)

{
  uint uVar1;
  void *_Dst;
  longlong lVar2;
  ulonglong uVar3;
  void *_Dst_00;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_68 [2];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  
  lVar5 = 0;
  local_58 = 0x10;
  local_54 = 0;
  local_68[0] = 0;
  local_68[1] = 1;
  _Dst = (void *)ExAllocatePool3(0x40,param_3 + 0x20,0x616d6452,local_68 + 1,1);
  if (_Dst == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)(param_3 + 0x20));
    *(uint *)((longlong)_Dst + 0x18) = param_3;
    lVar2 = RdmaGetLBBuffer((longlong)_Dst);
    lVar2 = IoAllocateMdl(lVar2,param_3,0,0,0);
    if (lVar2 == 0) {
      uVar4 = 0xc000009a;
    }
    else {
      MmBuildMdlForNonPagedPool(lVar2);
      uVar3 = RdmaAllocateLam(param_1,lVar2,param_3,(undefined8 *)((longlong)_Dst + 8));
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = RdmaBuildSglChainForLamChain
                          (*(longlong **)((longlong)_Dst + 8),param_2,1,param_4,param_3,local_68);
        lVar5 = local_68[0];
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_44 = 0;
          local_50 = 1;
          local_48 = 0x10;
          _Dst_00 = (void *)ExAllocatePool3(0x40,(ulonglong)*(ushort *)(local_68[0] + 0x14) << 4,
                                            0x616d6452,&local_50,1);
          *(void **)((longlong)_Dst + 0x10) = _Dst_00;
          if (_Dst_00 == (void *)0x0) {
            uVar4 = 0xc000009a;
          }
          else {
            memcpy(_Dst_00,*(void **)(lVar5 + 8),(ulonglong)*(ushort *)(lVar5 + 0x14) << 4);
            uVar4 = 0;
            *(undefined2 *)((longlong)_Dst + 0x1c) = *(undefined2 *)(lVar5 + 0x14);
          }
        }
      }
      IoFreeMdl(lVar2);
      if (lVar5 != 0) {
        RdmaFreeSgl(lVar5);
      }
      if (-1 < (int)uVar4) goto LAB_1c0011397;
    }
    if (*(longlong *)((longlong)_Dst + 8) != 0) {
      RdmaFreeLam(*(longlong *)((longlong)_Dst + 8));
    }
    if (*(longlong *)((longlong)_Dst + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)((longlong)_Dst + 0x10),0x616d6452);
    }
    ExFreePoolWithTag(_Dst,0x616d6452);
    _Dst = (void *)0x0;
  }
LAB_1c0011397:
  *param_5 = _Dst;
  return uVar4;
}



===== RdmaAllocateLamChain @ 1c00113c0 =====

ulonglong RdmaAllocateLamChain
                    (longlong param_1,undefined8 *param_2,uint param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong **pplVar5;
  longlong *local_res10;
  
  pplVar5 = &local_res10;
  local_res10 = (longlong *)0x0;
  plVar2 = (longlong *)0x0;
  if (param_3 != 0) {
    do {
      uVar3 = param_3;
      if (*(uint *)(param_2 + 5) <= param_3) {
        uVar3 = *(uint *)(param_2 + 5);
      }
      uVar1 = RdmaAllocateLam(param_1,(longlong)param_2,uVar3,pplVar5);
      uVar4 = uVar1 & 0xffffffff;
      if ((int)uVar1 < 0) {
        if (local_res10 != (longlong *)0x0) {
          RdmaFreeLamChain(local_res10);
          local_res10 = (longlong *)0x0;
        }
        goto LAB_1c0011424;
      }
      pplVar5 = (longlong **)*pplVar5;
      param_2 = (undefined8 *)*param_2;
      param_3 = param_3 - uVar3;
    } while (param_3 != 0);
    plVar2 = local_res10;
  }
  uVar4 = 0;
  local_res10 = plVar2;
LAB_1c0011424:
  *param_4 = local_res10;
  return uVar4;
}



===== RdmaBuildSglChainForLamChain @ 1c0011460 =====

undefined4
RdmaBuildSglChainForLamChain
          (longlong *param_1,undefined4 param_2,ushort param_3,ushort param_4,uint param_5,
          undefined8 *param_6)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong *plVar10;
  longlong *plVar11;
  uint uVar12;
  ulonglong uVar13;
  byte bVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  uint local_54;
  uint local_50;
  
  plVar2 = RdmaAllocateSgl(param_4);
  if (plVar2 == (longlong *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    uVar13 = (ulonglong)param_5;
    uVar19 = 1;
    uVar16 = 1;
    plVar11 = (longlong *)0x0;
    uVar15 = 0;
    uVar17 = 0;
    plVar4 = plVar2;
    do {
      uVar18 = *(uint *)(param_1 + 4);
      local_50 = 0;
      lVar3 = RdmaGetLamPage((longlong)param_1,0);
      local_54 = *(uint *)((longlong)param_1 + 0x1c);
      uVar8 = (ulonglong)local_54;
      plVar10 = plVar4;
      uVar9 = 0x1000 - local_54;
      if (uVar18 <= 0x1000 - local_54) {
        uVar9 = uVar18;
      }
      do {
        uVar12 = (uint)uVar13;
        bVar14 = (byte)uVar15;
        if (uVar9 == 0) {
          local_50 = local_50 + 1;
          lVar3 = RdmaGetLamPage((longlong)param_1,local_50);
          local_54 = 0;
          uVar8 = 0;
          uVar9 = uVar18;
          if (0x1000 < uVar18) {
            uVar9 = 0x1000;
          }
        }
        iVar7 = (int)uVar8;
        uVar15 = (ulonglong)bVar14;
        if (uVar12 == 0) {
          uVar15 = 1;
        }
        if ((uVar17 == 0) || (uVar8 + lVar3 != (ulonglong)*(uint *)(plVar11 + 1) + *plVar11)) {
          uVar16 = 1;
LAB_1c001157b:
          if (*(ushort *)((longlong)plVar10 + 0x14) != param_4) goto LAB_1c0011554;
LAB_1c0011589:
          uVar19 = uVar19 + 1;
          if ((param_3 == 0) || (uVar19 <= param_3)) {
            plVar4 = RdmaAllocateSgl(param_4);
            *plVar10 = (longlong)plVar4;
            if (plVar4 != (longlong *)0x0) {
              uVar15 = 0;
              uVar12 = param_5;
LAB_1c00115c9:
              plVar11 = (longlong *)plVar4[1];
              uVar8 = (ulonglong)local_54;
              goto LAB_1c00115d1;
            }
          }
          uVar6 = 0xc000009a;
          RdmaFreeSglChain(plVar2);
          plVar2 = (longlong *)0x0;
          goto LAB_1c0011660;
        }
        if ((char)uVar16 != '\0') goto LAB_1c001157b;
LAB_1c0011554:
        if ((char)uVar15 != '\0') goto LAB_1c0011589;
        plVar4 = plVar10;
        if ((char)uVar16 != '\0') {
          if (plVar11 == (longlong *)0x0) goto LAB_1c00115c9;
          plVar11 = plVar11 + 2;
LAB_1c00115d1:
          uVar17 = 0x200000;
          *(short *)((longlong)plVar4 + 0x14) = *(short *)((longlong)plVar4 + 0x14) + 1;
          *(undefined4 *)((longlong)plVar11 + 0xc) = param_2;
          iVar7 = (int)uVar8;
          *plVar11 = uVar8 + lVar3;
          *(undefined4 *)(plVar11 + 1) = 0;
          uVar16 = 0;
        }
        uVar5 = uVar12;
        if (uVar17 <= uVar12) {
          uVar5 = uVar17;
        }
        uVar1 = uVar18;
        if (uVar9 <= uVar18) {
          uVar1 = uVar9;
        }
        if ((uVar1 <= uVar5) && (uVar5 = uVar9, uVar18 < uVar9)) {
          uVar5 = uVar18;
        }
        *(uint *)(plVar4 + 2) = (int)plVar4[2] + uVar5;
        local_54 = iVar7 + uVar5;
        uVar8 = (ulonglong)local_54;
        *(uint *)(plVar11 + 1) = (int)plVar11[1] + uVar5;
        uVar13 = (ulonglong)(uVar12 - uVar5);
        uVar17 = uVar17 - uVar5;
        uVar18 = uVar18 - uVar5;
        uVar9 = uVar9 - uVar5;
        uVar6 = 0;
        plVar10 = plVar4;
      } while (uVar18 != 0);
      param_1 = (longlong *)*param_1;
    } while (param_1 != (longlong *)0x0);
  }
LAB_1c0011660:
  *param_6 = plVar2;
  return uVar6;
}



===== RdmaAllocateOperation @ 1c001168c =====

undefined4 * RdmaAllocateOperation(undefined8 param_1,undefined4 param_2)

{
  undefined4 *_Dst;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_18 = 1;
  local_10 = 0x10;
  _Dst = (undefined4 *)ExAllocatePool3(0x40,0x60,0x616d6452,&local_18,1);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x60);
    *(undefined8 *)(_Dst + 8) = param_1;
    *_Dst = param_2;
  }
  return _Dst;
}



===== RdmaBuildReadWorkRequests @ 1c0011710 =====

void RdmaBuildReadWorkRequests
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_28 = 0;
  local_20 = 0;
  local_c = 0;
  local_18 = param_3;
  local_10 = param_4;
  RdmaBuildSqWorkRequests
            (param_1,*(longlong **)(param_1 + 0x40),param_2,
             *(ushort *)(*(longlong *)(param_1 + 0x20) + 0xe8),
             *(uint *)(*(longlong *)(param_1 + 0x20) + 0xf4),2,(longlong)&local_28);
  return;
}



===== RdmaBuildSendWorkRequests @ 1c001176c =====

void RdmaBuildSendWorkRequests(longlong param_1,undefined4 param_2)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RdmaBuildSqWorkRequests
            (param_1,*(longlong **)(param_1 + 0x30),param_2,
             *(ushort *)(*(longlong *)(param_1 + 0x20) + 0xe6),
             *(uint *)(*(longlong *)(param_1 + 0x20) + 0xf0),1,(longlong)&local_28);
  return;
}



===== RdmaBuildSqWorkRequests @ 1c00117c0 =====

int RdmaBuildSqWorkRequests
              (longlong param_1,longlong *param_2,undefined4 param_3,ushort param_4,uint param_5,
              undefined4 param_6,longlong param_7)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  void *pvVar5;
  void *_Dst;
  longlong *plVar6;
  uint uVar7;
  longlong *local_res8;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_res8 = (longlong *)0x0;
  plVar6 = (longlong *)(param_1 + 8);
  uVar7 = 0;
  iVar4 = RdmaBuildSglChainForLamChain(param_2,param_3,0,param_4,param_5,&local_res8);
  plVar3 = local_res8;
  plVar2 = local_res8;
  if (-1 < iVar4) {
    for (; plVar2 != (longlong *)0x0; plVar2 = (longlong *)*plVar2) {
      uVar7 = uVar7 + (int)plVar2[2];
      pvVar5 = RdmaAllocateSqWorkRequest(param_6);
      *plVar6 = (longlong)pvVar5;
      if (pvVar5 == (void *)0x0) {
LAB_1c0011986:
        iVar4 = -0x3fffff66;
        goto LAB_1c0011948;
      }
      local_2c = 0;
      local_38 = 1;
      local_30 = 0x10;
      _Dst = (void *)ExAllocatePool3(0x40,(ulonglong)*(ushort *)((longlong)plVar2 + 0x14) << 4,
                                     0x616d6452,&local_38,1);
      if (_Dst == (void *)0x0) goto LAB_1c0011986;
      memcpy(_Dst,(void *)plVar2[1],(ulonglong)*(ushort *)((longlong)plVar2 + 0x14) << 4);
      iVar4 = *(int *)((longlong)pvVar5 + 0x28);
      *(longlong *)((longlong)pvVar5 + 0x20) = param_1;
      *(code **)((longlong)pvVar5 + 0x18) = RdmaOperationSqWrCompletionCallback;
      if (iVar4 == 1) {
        *(undefined2 *)((longlong)pvVar5 + 0x40) = *(undefined2 *)((longlong)plVar2 + 0x14);
        *(void **)((longlong)pvVar5 + 0x30) = _Dst;
        *(int *)((longlong)pvVar5 + 0x38) = (int)plVar2[2];
        *(undefined1 *)((longlong)pvVar5 + 0x42) = *(undefined1 *)(param_7 + 0x12);
        *(undefined4 *)((longlong)pvVar5 + 0x3c) = *(undefined4 *)(param_7 + 0xc);
      }
      else if ((iVar4 == 2) || (iVar4 == 3)) {
        *(undefined2 *)((longlong)pvVar5 + 0x38) = *(undefined2 *)((longlong)plVar2 + 0x14);
        *(void **)((longlong)pvVar5 + 0x30) = _Dst;
        *(int *)((longlong)pvVar5 + 0x3c) = (int)plVar2[2];
        *(ulonglong *)((longlong)pvVar5 + 0x40) =
             (*(longlong *)(param_7 + 0x10) - (ulonglong)*(uint *)(plVar2 + 2)) + (ulonglong)uVar7;
        *(undefined4 *)((longlong)pvVar5 + 0x48) = *(undefined4 *)(param_7 + 0x18);
      }
      lVar1 = *plVar6;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
      plVar6 = (longlong *)(lVar1 + 0x10);
    }
    iVar4 = 0;
  }
LAB_1c0011948:
  if (plVar3 != (longlong *)0x0) {
    RdmaFreeSglChain(plVar3);
  }
  if (iVar4 < 0) {
    RdmaFreeOperationSqWrList(param_1);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return iVar4;
}



===== RdmaBuildWriteWorkRequests @ 1c0011994 =====

void RdmaBuildWriteWorkRequests
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_28 = 0;
  local_20 = 0;
  local_c = 0;
  local_18 = param_3;
  local_10 = param_4;
  RdmaBuildSqWorkRequests
            (param_1,*(longlong **)(param_1 + 0x50),param_2,
             *(ushort *)(*(longlong *)(param_1 + 0x20) + 0xe6),
             *(uint *)(*(longlong *)(param_1 + 0x20) + 0xf0),3,(longlong)&local_28);
  return;
}



===== RdmaAllocateSqWorkRequest @ 1c00119f0 =====

void * RdmaAllocateSqWorkRequest(undefined4 param_1)

{
  void *_Dst;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0x10;
  local_18 = 1;
  _Dst = (void *)ExAllocatePool3(0x40,0x58,0x616d6452,&local_18,1);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x58);
    *(undefined4 *)((longlong)_Dst + 0x28) = param_1;
  }
  return _Dst;
}



===== RdmaAllocateRegisteredBuffer @ 1c0011a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong RdmaAllocateRegisteredBuffer(longlong param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  ulonglong uVar9;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  longlong local_18;
  
  local_3c = 0;
  local_48 = 1;
  local_40 = 0x10;
  plVar5 = (longlong *)ExAllocatePool3(0x40,0x38,0x616d6452,&local_48,1);
  if (plVar5 == (longlong *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    *plVar5 = 0;
    plVar5[1] = 0;
    plVar5[2] = 0;
    plVar5[3] = 0;
    plVar8 = plVar5 + 2;
    plVar5[4] = 0;
    plVar5[5] = 0;
    plVar5[6] = 0;
    lVar7 = *(longlong *)(param_1 + 0x10);
    local_38 = 0;
    uStack_30 = 0;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_38,0,0);
    uVar6 = (**(code **)(*(longlong *)(lVar7 + 0x28) + 0x10))
                      (lVar7,1,NdkCreateFnCompletionCallback,&local_38,plVar8);
    if ((int)uVar6 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      *plVar8 = local_18;
      uVar6 = uStack_20;
    }
    uVar9 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) {
      *plVar8 = 0;
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0xde);
      lVar7 = *plVar8;
      local_18 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      uStack_20 = 0;
      KeInitializeEvent(&local_38,0,0);
      uVar3 = (**(code **)(*(longlong *)(lVar7 + 0x28) + 0x20))
                        (lVar7,uVar1,1,NdkFnCompletionCallback,&local_38);
      if (uVar3 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
        uVar3 = (uint)uStack_20;
      }
      uVar9 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar4 = (**(code **)(*(longlong *)(plVar5[2] + 0x28) + 0x28))();
        *(undefined4 *)(plVar5 + 3) = uVar4;
        lVar7 = param_1 + 0xb0;
        plVar8 = *(longlong **)(param_1 + 0xb8);
        if (*plVar8 != lVar7) {
          plVar8 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          lVar7 = (*pcVar2)();
        }
        *plVar5 = lVar7;
        plVar5[1] = (longlong)plVar8;
        *plVar8 = (longlong)plVar5;
        *(longlong **)(lVar7 + 8) = plVar5;
        return 0;
      }
    }
    RdmaFreeRegisteredBuffer((longlong)plVar5);
  }
  return uVar9;
}



===== RdmaInvalidateRegisteredBuffer @ 1c0011c58 =====

void RdmaInvalidateRegisteredBuffer(longlong *param_1,longlong *param_2)

{
  RdmaInvalidateRegisteredBufferInner(param_1,param_2,'\x01');
  return;
}



===== WdmlibIoCreateDeviceSecure @ 1c0011c70 =====

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
            (param_1,0,param_3,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,0,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c0011d60 =====

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
    if ((int)uVar5 < 0) goto LAB_1c0011ec0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c0011ec0;
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
LAB_1c0011ec0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c0011ef4 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 1c0011fe4 =====

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



===== SepSddlAddAceToAcl @ 1c00120c4 =====

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



===== SepSddlDaclFromSDDLString @ 1c00121c4 =====

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



===== SepSddlGetAclForString @ 1c00122b0 =====

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
LAB_1c001264b:
              iVar5 = -0x3ffffff3;
LAB_1c001264d:
              lVar7 = *param_2;
              goto LAB_1c0012633;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c001264b;
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
                ppuVar17 = &PTR_u_RC_1c000c010;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_1c000c01c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_1c000c018)[uVar11 * 4];
                    goto LAB_1c001253d;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c001264b;
                uVar15 = (uint)local_res8;
LAB_1c001253d:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c001264d;
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
            if (iVar5 != 0) goto LAB_1c001264d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c00125bb:
              iVar5 = -0x3fffff89;
              goto LAB_1c001264d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c00125bb;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c001264d;
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
LAB_1c0012633:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c0012678 =====

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
  puVar5 = &DAT_1c000c0e4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c000c0dc + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c000c0d8 + uVar7 * 0x18);
      uVar6 = (&DAT_1c000c0e4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c001270f;
      }
      else {
LAB_1c001270f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c000c0d0 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c0012724;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c0012724:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c001274c =====

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
LAB_1c00127cf:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c00127ad;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c00127cf;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c00127ad:
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



===== SepSddlSecurityDescriptorFromSDDLString @ 1c0012858 =====

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
        goto LAB_1c001299d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c001299d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c00129fc =====

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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c000a5a0,0x20019,&local_b0);
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



===== PiRegStateReadStackCreationSettingsFromKey @ 1c0012b98 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c000a520);
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
      if ((int)uVar3 < 0) goto LAB_1c0012d17;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000a538,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012d17;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000a550,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012d17;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000a580,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c0012d17:
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



===== PpRegStateReadCreateClassCreationSettings @ 1c0012d5c =====

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c000a4c0,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c000a4d8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000a4e8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000a508,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c0012ec0 =====

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
                      (local_res20,0x1c000a4c0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
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
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c000a520);
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



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c0013028 =====

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



===== CmRegUtilCreateWstrKey @ 1c0013124 =====

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



===== CmRegUtilOpenExistingWstrKey @ 1c00131f4 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 1c0013288 =====

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
    if (iVar1 < 0) goto LAB_1c00133c0;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c00133c0:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c0013404 =====

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



===== CmRegUtilWstrValueGetDword @ 1c0013550 =====

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



===== CmRegUtilWstrValueSetWstrString @ 1c00135f4 =====

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



===== entry @ 1c0014010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0014044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  char *pcVar1;
  byte bVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte in_DL;
  undefined7 in_register_00000011;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar3 = (code *)swi(0x29);
    pbVar6 = (byte *)(*pcVar3)(6);
    bVar4 = (byte)pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + bVar4;
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *pbVar6 = *pbVar6 + in_DL + CARRY1(bVar2,bVar4);
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    *(uint *)pbVar6 = *(int *)pbVar6 + (int)pbVar6 + (uint)CARRY1(bVar2,bVar4);
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + in_DL;
    bVar4 = bVar4 + *pbVar6 + CARRY1(bVar2,in_DL);
    pbVar7 = (byte *)CONCAT71((int7)((ulonglong)pbVar6 >> 8),bVar4);
    pbVar7[0x12] = pbVar7[0x12] + bVar4;
    bVar2 = *pbVar7;
    *pbVar7 = *pbVar7 + bVar4;
    *(char *)CONCAT71(in_register_00000011,in_DL) =
         *(char *)CONCAT71(in_register_00000011,in_DL) + CARRY1(bVar2,bVar4);
    pbVar6 = pbVar7 + -0x3fffffed;
    bVar2 = *pbVar6;
    *pbVar6 = *pbVar6 + bVar4;
    uVar5 = (int)pbVar7 + *(int *)pbVar7 + (uint)CARRY1(bVar2,bVar4);
    pbVar6 = (byte *)(ulonglong)uVar5;
    bVar2 = *pbVar6;
    bVar4 = (byte)(uVar5 >> 8);
    *pbVar6 = *pbVar6 + bVar4;
    pcVar1 = (char *)((ulonglong)CONCAT31((int3)(uVar5 >> 8),(char)uVar5 + CARRY1(bVar2,bVar4)) -
                     0x1fffffdb);
    *pcVar1 = *pcVar1 + in_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


