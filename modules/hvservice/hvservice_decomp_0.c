
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (longlong param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = *(undefined8 *)(param_1 + 8);
  *(uint *)(param_6 + 1) = (uint)**(ushort **)(param_1 + 8);
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,0,0,param_5,param_6);
  return;
}



===== HbEvtpTracePeriodicTimerDpcRoutine @ 140001110 =====

void HbEvtpTracePeriodicTimerDpcRoutine(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = IoAcquireRemoveLockEx(param_2 + 8,param_2,"",1,0x20);
  if (-1 < iVar2) {
    if (DAT_14000704a != '\0') {
      iVar2 = IoAcquireRemoveLockEx(param_2 + 8,param_2,"",1,0x20);
      if (-1 < iVar2) {
        lVar3 = IoAllocateWorkItem(*param_2);
        if (lVar3 == 0) {
          IoReleaseRemoveLockEx(param_2 + 8,param_2,0x20);
        }
        else {
          IoQueueWorkItemEx(lVar3,HbEvtpPeriodicGlobalSystemEventFlushWorkItemRoutine,1,param_2);
        }
      }
    }
    if (DAT_140007049 != '\0') {
      cVar1 = EtwProviderEnabled(DAT_140007070,0,0);
      if ((cVar1 != '\0') && (DAT_140007049 != '\0')) {
        iVar2 = IoAcquireRemoveLockEx(param_2 + 8,param_2,"",1,0x20);
        if (-1 < iVar2) {
          lVar3 = IoAllocateWorkItem(*param_2);
          if (lVar3 == 0) {
            IoReleaseRemoveLockEx(param_2 + 8,param_2,0x20);
          }
          else {
            IoQueueWorkItemEx(lVar3,HbEvtpSysDiagLogWorkItemRoutine,1,param_2);
          }
        }
      }
    }
    IoReleaseRemoveLockEx(param_2 + 8,param_2,0x20);
  }
  return;
}



===== McGenControlCallbackV2 @ 1400012c0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  
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
      *(undefined8 *)(param_7 + 0x18) = param_5;
      uVar3 = 0;
      *(undefined1 *)(param_7 + 0x28) = param_3;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + (ulonglong)uVar3 * 8);
          if (((*(byte *)(param_7 + 0x28) <
                *(byte *)((ulonglong)uVar3 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (ulonglong)(uVar3 >> 5) * 4);
            *puVar1 = *puVar1 & ~(1 << ((byte)uVar3 & 0x1f));
          }
          else {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (ulonglong)(uVar3 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(ushort *)(param_7 + 0x2a));
        return;
      }
    }
  }
  return;
}



===== HbEvtpGetLogConfiguration @ 1400013e0 =====

undefined8 HbEvtpGetLogConfiguration(int param_1,undefined8 *param_2)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &HbEvtpEventLog;
  }
  else {
    if (param_1 != 1) {
      if (param_1 == 2) {
        *param_2 = &DAT_140007310;
        return 0;
      }
      return 0xc000000d;
    }
    puVar1 = &DAT_140007280;
  }
  *param_2 = puVar1;
  return 0;
}



===== HbEvtpScheduleSystemDiagLogWorkItem @ 140001420 =====

void HbEvtpScheduleSystemDiagLogWorkItem(undefined8 *param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  
  cVar1 = EtwProviderEnabled(DAT_140007070,0,0);
  if (((cVar1 != '\0') && (DAT_140007049 != '\0')) &&
     (iVar2 = IoAcquireRemoveLockEx(param_1 + 8,param_1,"",1,0x20), -1 < iVar2)) {
    lVar3 = IoAllocateWorkItem(*param_1);
    if (lVar3 == 0) {
      IoReleaseRemoveLockEx(param_1 + 8,param_1,0x20);
    }
    else {
      IoQueueWorkItemEx(lVar3,HbEvtpSysDiagLogWorkItemRoutine,1,param_1);
    }
  }
  return;
}



===== HbpPowerSystemIrpReturn @ 1400014f0 =====

undefined8 HbpPowerSystemIrpReturn(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    PoStartNextPowerIrp(param_2);
    return 0;
  }
  uVar1 = 1;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 1) {
    uVar1 = 4;
  }
  PoRequestPowerIrp(param_1,*(undefined1 *)(*(longlong *)(param_2 + 0xb8) + 1),uVar1,
                    HbpPowerOnFinalizedDeviceIrp,param_2,0);
  return 0xc0000016;
}



===== HbpPowerOnFinalizedDeviceIrp @ 140001570 =====

void HbpPowerOnFinalizedDeviceIrp(void)

{
  longlong in_R9;
  undefined4 *in_stack_00000028;
  
  if (in_R9 != 0) {
    *(undefined4 *)(in_R9 + 0x30) = *in_stack_00000028;
    PoStartNextPowerIrp();
    IofCompleteRequest();
  }
  return;
}



===== __report_gsfailure @ 1400015c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400015cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400015cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ext_ms_win_ntos_ksr_l1_1_2_KsrFreePersistedMemory @ 1400015e0 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_2_KsrFreePersistedMemory(void)

{
  return 0;
}



===== HbpTraceFault @ 1400015ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbpTraceFault(undefined4 param_1,char *param_2,char *param_3,undefined8 param_4)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  longlong lVar5;
  longlong lVar4;
  va_list _Args;
  undefined8 local_res20;
  undefined1 auStackY_2d8 [32];
  undefined4 local_2a8 [2];
  undefined8 local_2a0;
  undefined8 local_298 [4];
  undefined4 *local_278;
  undefined4 local_270;
  undefined4 local_26c;
  longlong local_268 [2];
  char *local_258;
  int local_250;
  undefined4 local_24c;
  undefined8 *local_248;
  undefined4 local_240;
  undefined4 local_23c;
  char local_238 [511];
  undefined1 local_39;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_2a0 = 0;
  _Args = (va_list)&local_res20;
  local_res20 = param_4;
  memset(local_238,0,0x200);
  uVar3 = _vsnprintf(local_238,0x1ff,param_3,_Args);
  if ((-1 < (int)uVar3) && (uVar3 < 0x200)) {
    if (uVar3 == 0x1ff) {
      local_39 = 0;
    }
    if ((5 < DAT_140007088) && (cVar2 = _tlgKeywordOn(0x140007088,0x400000000000), cVar2 != '\0')) {
      local_26c = 0;
      local_278 = local_2a8;
      local_270 = 4;
      local_2a8[0] = param_1;
      _tlgCreate1Sz_char(local_268,param_2);
      lVar5 = -1;
      do {
        lVar4 = lVar5 + 1;
        lVar1 = lVar5 + 1;
        lVar5 = lVar4;
      } while (local_238[lVar1] != '\0');
      local_24c = 0;
      local_258 = local_238;
      local_23c = 0;
      local_250 = (int)lVar4 + 1;
      local_248 = &local_2a0;
      local_2a0 = 0x2000000;
      local_240 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(0x140007088,&DAT_140005d41,param_3,_Args,6,local_298);
    }
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000175c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140006d17 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140001784 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400018e0 =====

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



===== HbHvpTransitionDebuggerPower @ 140001970 =====

void HbHvpTransitionDebuggerPower(int param_1)

{
  WinHvSetHvDebugProperty(param_1 == 1);
  return;
}



===== HbEvtpCompletedNotificationRoutine @ 1400019a0 =====

void HbEvtpCompletedNotificationRoutine(uint param_1,uint param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = (longlong)(int)param_1 * 0x90;
  if (param_1 == 2) {
    return;
  }
  cVar1 = ExAcquireRundownProtection(&DAT_140007208 + lVar3);
  if (cVar1 == '\0') {
    HbpTraceFault(1,"HbEvtpCompletedNotificationRoutine",
                  "Couldn\'t acquire rundown for event log type %d",(ulonglong)param_1);
    return;
  }
  if (*(uint *)(&DAT_1400071f8 + lVar3) <= param_2) {
    return;
  }
  if (*(longlong *)(&DAT_140007210 + lVar3) == 0) {
    return;
  }
  if (*(uint *)(&DAT_1400071f8 + lVar3) == 0) {
    return;
  }
  lVar4 = (ulonglong)param_2 * 0x70 + *(longlong *)(&DAT_140007210 + lVar3);
  if ((param_1 != 1) || (lVar2 = ExpInterlockedPushEntrySList(0x1400072f0,lVar4 + 0x60), lVar2 == 0)
     ) {
    KeInsertQueueDpc(lVar4 + 0x10,(longlong)(int)param_1,(ulonglong)param_2);
  }
  ExReleaseRundownProtection(&DAT_140007208 + lVar3);
  return;
}



===== HbEvtpLocalDiagEventsWorkItemRoutine @ 140001aa0 =====

void HbEvtpLocalDiagEventsWorkItemRoutine(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong local_res10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_res10 = 0;
  ExAcquireFastMutex(lVar2 + 0x110);
  cVar4 = ExAcquireRundownProtection(&DAT_140007298);
  if (cVar4 != '\0') {
    uVar5 = HbEvtpGetLogConfiguration(1,&local_res10);
    lVar3 = local_res10;
    if (-1 < (int)uVar5) {
      puVar6 = (undefined8 *)ExpInterlockedFlushSList(local_res10 + 0x70);
      puVar8 = (undefined8 *)0x0;
      while (puVar7 = puVar6, puVar7 != (undefined8 *)0x0) {
        puVar6 = (undefined8 *)*puVar7;
        *puVar7 = puVar8;
        puVar8 = puVar7;
      }
      while (puVar8 != (undefined8 *)0x0) {
        puVar1 = (uint *)((longlong)puVar8 + -0xc);
        puVar8 = (undefined8 *)*puVar8;
        HbEvtpLocalDiagWriteBufferList(lVar2,lVar3,*puVar1);
      }
      puVar6 = *(undefined8 **)(lVar3 + 0x80);
      *(undefined8 *)(lVar3 + 0x80) = 0;
      while (puVar6 != (undefined8 *)0x0) {
        puVar1 = (uint *)((longlong)puVar6 + -0xc);
        puVar6 = (undefined8 *)*puVar6;
        HbEvtpLocalDiagWriteBufferList(lVar2,lVar3,*puVar1);
      }
    }
    if ((lVar3 != 0) && (*(int *)(lVar3 + 0x30) == 1)) {
      KeSetEvent(&HbEvtpCompleteBufferAsyncEvent,0,0);
    }
    ExReleaseRundownProtection(&DAT_140007298);
  }
  ExReleaseFastMutex(lVar2 + 0x110);
  IoFreeWorkItem(param_3);
  IoReleaseRemoveLockEx(lVar2 + 0x40,lVar2,0x20);
  return;
}



===== HbEvtpLocalDiagInsertOutOfOrderBufferInList @ 140001bfc =====

void HbEvtpLocalDiagInsertOutOfOrderBufferInList(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x80);
  if ((plVar1 == (longlong *)0x0) || (*(uint *)(*param_2 + 0x3c) < *(uint *)(plVar1[-0xc] + 0x3c)))
  {
    param_2[0xc] = (longlong)plVar1;
    *(longlong **)(param_1 + 0x80) = param_2 + 0xc;
    return;
  }
  plVar2 = (longlong *)*plVar1;
  while ((plVar2 != (longlong *)0x0 && (*(uint *)(plVar2[-0xc] + 0x3c) < *(uint *)(*param_2 + 0x3c))
         )) {
    plVar1 = plVar2;
    plVar2 = (longlong *)*plVar2;
  }
  param_2[0xc] = *plVar1;
  *plVar1 = (longlong)(param_2 + 0xc);
  return;
}



===== HbEvtpLocalDiagReleaseBufferList @ 140001c60 =====

void HbEvtpLocalDiagReleaseBufferList(longlong param_1,uint param_2)

{
  while (param_2 != 0xffffffff) {
    param_2 = *(uint *)(*(longlong *)((ulonglong)param_2 * 0x70 + *(longlong *)(param_1 + 0x20)) +
                       0x38);
    WinHvReleaseEventLogBuffer(1);
  }
  return;
}



===== HbEvtpLocalDiagWriteBuffer @ 140001cb0 =====

int HbEvtpLocalDiagWriteBuffer(longlong param_1,longlong param_2,undefined8 *param_3)

{
  uint *puVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  piVar3 = (int *)*param_3;
  puVar1 = (uint *)((longlong)param_3 + 0x54);
  uVar6 = HbEvtpTransferBufferOwnershipToEtw((longlong)param_3);
  if ((int)uVar6 < 0) {
    HbpTraceFault(0,"HbEvtpLocalDiagWriteBuffer","Failure to transfer ownership of buffer %d to ETW"
                  ,(ulonglong)*puVar1);
  }
  *piVar3 = *piVar3 + 0x48;
  uVar2 = *(undefined2 *)(param_1 + 0x148);
  piVar3[0xc] = piVar3[0xc] + 0x48;
  *(undefined2 *)((longlong)piVar3 + 0x2a) = uVar2;
  piVar3[0xd] = 0x20;
  piVar3[0xf] = 0;
  uVar4 = KfRaiseIrql(2);
  iVar5 = EtwSendTraceBuffer(*(undefined8 *)(param_1 + 0x148),piVar3,piVar3[2],
                             HbEvtpLocalDiagnosticsBufferCompletedCallback,*puVar1);
  KeLowerIrql(uVar4);
  if (iVar5 < 0) {
    *(undefined4 *)(param_3 + 0xb) = 0;
    ExReleaseRundownProtection(*(longlong *)(param_2 + 0x28) + (ulonglong)*puVar1 * 8);
  }
  return iVar5;
}



===== HbEvtpSystemDiagLogCrashdumpCallback @ 140001dc0 =====

void HbEvtpSystemDiagLogCrashdumpCallback(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong local_res18 [2];
  
  plVar2 = HbEvtpCrashdumpContext;
  uVar7 = 0;
  *(undefined8 *)(param_3 + 0x10) = 0x45c5683300dae7ca;
  *(undefined8 *)(param_3 + 0x18) = 0xd61fb6d7aebd47b1;
  local_res18[0] = 0;
  if ((ulonglong)*(uint *)(param_3 + 0xc) < (ulonglong)plVar2[6]) {
    uVar4 = HbEvtpGetLogConfiguration(2,local_res18);
    plVar2 = HbEvtpCrashdumpContext;
    if ((int)uVar4 < 0) {
      return;
    }
    uVar8 = uVar7 & 0xffffffff;
    if (*(uint *)(local_res18[0] + 8) != 0) {
      plVar5 = *(longlong **)(local_res18[0] + 0x20);
      uVar6 = (ulonglong)*(uint *)(local_res18[0] + 8);
      do {
        uVar1 = *(ulonglong *)(*plVar5 + 0x10);
        if (uVar7 <= uVar1) {
          uVar8 = (ulonglong)*(uint *)(*plVar5 + 4);
          uVar7 = uVar1;
        }
        plVar5 = plVar5 + 0xe;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    *(ulonglong *)(param_3 + 0x20) =
         (uVar8 - 1) * HbEvtpCrashdumpContext[4] + *HbEvtpCrashdumpContext;
    iVar3 = (int)plVar2[4] * 2;
  }
  else {
    *(longlong *)(param_3 + 0x20) = *plVar2;
    iVar3 = (int)plVar2[6];
  }
  *(int *)(param_3 + 0x28) = iVar3;
  return;
}



===== HbEvtpTraceCompletedDpcRoutine @ 140001e70 =====

void HbEvtpTraceCompletedDpcRoutine
               (undefined8 param_1,undefined8 *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  
  iVar2 = IoAcquireRemoveLockEx(param_2 + 8,param_2,"",1,0x20);
  if (iVar2 < 0) {
    return;
  }
  cVar1 = ExAcquireRundownProtection(&DAT_140007208 + (longlong)param_3 * 0x90);
  if (cVar1 == '\0') {
    return;
  }
  if (param_3 == 1) {
    lVar3 = IoAllocateWorkItem(*param_2);
    if (lVar3 == 0) {
LAB_140001f48:
      IoReleaseRemoveLockEx(param_2 + 8,param_2,0x20);
      goto LAB_140001f60;
    }
    pcVar4 = HbEvtpLocalDiagEventsWorkItemRoutine;
  }
  else {
    if (param_3 != 0) goto LAB_140001f60;
    lVar3 = IoAllocateWorkItem(*param_2);
    if (lVar3 == 0) goto LAB_140001f48;
    pcVar4 = HbEvtpGlobalSystemEventsWorkItemRoutine;
  }
  IoQueueWorkItemEx(lVar3,pcVar4,1,param_4);
LAB_140001f60:
  ExReleaseRundownProtection(&DAT_140007208 + (longlong)param_3 * 0x90);
  return;
}



===== HbEvtpTransferBufferOwnershipToEtw @ 140001f94 =====

undefined8 HbEvtpTransferBufferOwnershipToEtw(longlong param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 local_res8;
  
  uVar3 = 0;
  local_res8 = 0xfffffffffff85ee0;
  while( true ) {
    iVar2 = 0;
    LOCK();
    iVar1 = *(int *)(param_1 + 0x58);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x58) = 1;
    }
    else {
      iVar2 = iVar1;
    }
    UNLOCK();
    if (iVar2 != 1) break;
    if (199 < uVar3) {
      HbpTraceFault(0,"HbEvtpTransferBufferOwnershipToEtw",
                    "Timeout waiting for buffer %d to become available",
                    (ulonglong)*(uint *)(param_1 + 0x54));
      return 0x102;
    }
    KeDelayExecutionThread(0,0,&local_res8);
    uVar3 = uVar3 + 1;
  }
  return 0;
}



===== HbEvtpTriageDumpDataCrashdumpCallback @ 140002020 =====

void HbEvtpTriageDumpDataCrashdumpCallback
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  if ((*(uint *)(param_3 + 1) & 1) != 0) {
    KeAddTriageDumpDataBlock(*(undefined8 *)(HbEvtpCrashdumpContext + 0xa8),&DAT_1400073b8,0x18);
    KeAddTriageDumpDataBlock
              (*(undefined8 *)(HbEvtpCrashdumpContext + 0xa8),DAT_1400073b8,DAT_1400073c0);
    KeAddTriageDumpDataBlock(*(undefined8 *)(HbEvtpCrashdumpContext + 0xa8),&DAT_140007310,0x90);
  }
  *param_3 = *(undefined8 *)(HbEvtpCrashdumpContext + 0xa8);
  return;
}



===== HbEvtpWriteEventLog @ 1400020c8 =====

void HbEvtpWriteEventLog(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  if (HvBootDriverControlGuid_Context != 0) {
    EtwWrite(HvBootDriverControlGuid_Context,param_1,0,param_2,param_3);
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 140002104 =====

void McGenEventRegister_EtwRegister(void)

{
  if (HvBootDriverControlGuid_Context == 0) {
    EtwRegister(&HvBootDriverControlGuid,McGenControlCallbackV2,&HvBootDriverControlGuid_Context,
                &HvBootDriverControlGuid_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140002144 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (HvBootDriverControlGuid_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    HvBootDriverControlGuid_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140002178 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140007008;
  uVar2 = 0;
  if (DAT_140007008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140007008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(HvBootDriverControlGuid_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1400021dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,&HV_EVENTLOG_HW_WATCHDOG_REBOOT,param_3,1,local_28);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 140002224 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&HV_EVENTLOG_SECFW_UPDATE_STATUS,param_3,2,local_38);
  return;
}



===== McTemplateK0uIR0iq_EtwWriteTransfer @ 140002288 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uIR0iq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined1 auStackY_a8 [32];
  undefined1 local_78 [16];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = local_78;
  local_78[0] = 2;
  local_48 = param_5;
  local_38 = &param_6;
  local_28 = &param_7;
  local_50 = 1;
  local_40 = 0x10;
  local_30 = 8;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0x_EtwWriteTransfer @ 140002318 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0x_EtwWriteTransfer
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
  McGenEventWrite_EtwWriteTransfer(param_1,&HV_EVENTLOG_SECFW_VERSION,param_3,2,local_38);
  return;
}



===== _tlgDefineProvider_annotation__TlgVmHvTelemetryProviderProv @ 14000237c =====

void _tlgDefineProvider_annotation__TlgVmHvTelemetryProviderProv(void)

{
  return;
}



===== ImageCompareSectionNames @ 140002388 =====

undefined1 ImageCompareSectionNames(longlong param_1)

{
  ulonglong uVar1;
  
  for (uVar1 = 0; ((uint)uVar1 < 9 && (*(char *)(uVar1 + param_1) == ".rdata"[uVar1]));
      uVar1 = (ulonglong)((uint)uVar1 + 1)) {
    if (*(char *)(uVar1 + param_1) == '\0') {
      return 1;
    }
  }
  return 0;
}



===== ImageGetInfo @ 1400023b8 =====

void ImageGetInfo(longlong param_1,ulonglong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  lVar7 = *(longlong *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 4);
  param_2[2] = (ulonglong)*(ushort *)(lVar7 + 6);
  if (iVar1 == 0) {
    uVar8 = *(ulonglong *)(lVar7 + 0x30);
  }
  else {
    uVar8 = (ulonglong)*(uint *)(lVar7 + 0x34);
  }
  uVar2 = *(undefined4 *)(lVar7 + 0x58);
  uVar3 = *(undefined4 *)(lVar7 + 8);
  uVar4 = *(uint *)(lVar7 + 0x50);
  uVar5 = *(undefined4 *)(lVar7 + 0x38);
  uVar6 = *(undefined4 *)(lVar7 + 0x54);
  param_2[1] = (ulonglong)*(uint *)(lVar7 + 0x28);
  param_2[4] = (ulonglong)uVar4;
  *param_2 = uVar8;
  *(undefined4 *)(param_2 + 3) = uVar5;
  *(undefined4 *)((longlong)param_2 + 0x1c) = uVar6;
  *(undefined4 *)(param_2 + 5) = uVar2;
  *(undefined4 *)((longlong)param_2 + 0x2c) = uVar3;
  return;
}



===== ImageGetSectionByIndex @ 14000246c =====

void ImageGetSectionByIndex(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 8) + (ulonglong)*(ushort *)(*(longlong *)(param_1 + 8) + 0x14);
  *param_3 = 0;
  *(undefined1 *)(param_3 + 1) = 0;
  *param_3 = *(undefined8 *)(lVar1 + 0x18 + param_2 * 0x28);
  uVar2 = *(uint *)(lVar1 + 0x20 + param_2 * 0x28);
  uVar3 = *(uint *)(lVar1 + 0x28 + param_2 * 0x28);
  if (uVar2 <= uVar3) {
    uVar3 = uVar2;
  }
  param_3[2] = (ulonglong)uVar3;
  *(undefined4 *)(param_3 + 3) = *(undefined4 *)(lVar1 + 0x2c + param_2 * 0x28);
  param_3[4] = (ulonglong)*(uint *)(lVar1 + 0x20 + param_2 * 0x28);
  param_3[5] = (ulonglong)*(uint *)(lVar1 + 0x24 + param_2 * 0x28);
  *(undefined4 *)(param_3 + 6) = *(undefined4 *)(lVar1 + 0x3c + param_2 * 0x28);
  return;
}



===== ImageValidateAndProcess @ 1400024d0 =====

char ImageValidateAndProcess(short *param_1,ulonglong param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  undefined4 uVar4;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  iVar1 = *param_3;
  uVar4 = 1;
  if (iVar1 == 0) {
    uVar2 = ImagepValidateNtHeader64(param_1,param_2,(longlong)param_3,local_res18);
    cVar3 = (char)uVar2;
LAB_14000250d:
    if (cVar3 != '\0') {
      *(longlong *)(param_4 + 2) = local_res18[0];
      param_4[1] = iVar1;
      goto LAB_140002528;
    }
  }
  else {
    if (iVar1 == 1) {
      uVar2 = ImagepValidateNtHeader32(param_1,param_2,(longlong)param_3,local_res18);
      cVar3 = (char)uVar2;
      goto LAB_14000250d;
    }
    cVar3 = '\0';
  }
  uVar4 = 2;
LAB_140002528:
  *param_4 = uVar4;
  return cVar3;
}



===== ImagepValidateNtHeader32 @ 140002544 =====

ulonglong ImagepValidateNtHeader32
                    (short *param_1,ulonglong param_2,longlong param_3,longlong *param_4)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong local_res20;
  
  uVar8 = 0;
  local_res20 = 0;
  *param_4 = 0;
  uVar3 = ImagepValidateNtHeaderGeneric(param_1,param_2,&local_res20);
  uVar9 = uVar8;
  if ((char)uVar3 != '\0') {
    uVar3 = 0x10b;
    lVar7 = local_res20 + (longlong)param_1;
    if (*(short *)(lVar7 + 0x18) == 0x10b) {
      uVar2 = *(uint *)(param_3 + 4);
      uVar3 = (ulonglong)uVar2;
      if (uVar2 == 1) {
        uVar3 = 0x14c;
      }
      else {
        if (uVar2 != 3) goto LAB_140002635;
        uVar3 = 0x1c4;
      }
      if (*(short *)(lVar7 + 4) == (short)uVar3) {
        uVar1 = *(ushort *)(lVar7 + 0x14);
        uVar3 = 0;
        if (0xdf < uVar1) {
          if (*(uint *)(lVar7 + 0x50) < param_2) {
            if ((*(uint *)(lVar7 + 0x74) < 5) || (*(int *)(lVar7 + 0x98) == (int)uVar8))
            goto LAB_140002635;
            uVar2 = *(uint *)(lVar7 + 0x9c);
            uVar3 = (ulonglong)uVar2;
            if ((uVar2 == 0) || (*(uint *)(lVar7 + 0x50) + uVar2 != param_2)) goto LAB_140002635;
          }
          uVar4 = local_res20 + 0x18 + (ulonglong)uVar1;
          if (uVar4 <= param_2) {
            uVar6 = (ulonglong)*(ushort *)(lVar7 + 6);
            uVar3 = uVar6 * 5;
            if (uVar4 + uVar6 * 0x28 <= param_2) {
              lVar5 = lVar7 + 0x18 + (ulonglong)uVar1;
              for (; uVar8 < uVar6; uVar8 = uVar8 + 1) {
                uVar3 = ImagepValidateSectionHeader(lVar5,param_2);
                if ((char)uVar3 == '\0') goto LAB_140002635;
                lVar5 = lVar5 + 0x28;
              }
              *param_4 = lVar7;
              uVar9 = 1;
            }
          }
        }
      }
    }
  }
LAB_140002635:
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar9);
}



===== ImagepValidateNtHeader64 @ 14000264c =====

ulonglong ImagepValidateNtHeader64
                    (short *param_1,ulonglong param_2,longlong param_3,longlong *param_4)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong local_res20;
  
  uVar8 = 0;
  local_res20 = 0;
  *param_4 = 0;
  uVar3 = ImagepValidateNtHeaderGeneric(param_1,param_2,&local_res20);
  uVar9 = uVar8;
  if ((char)uVar3 != '\0') {
    uVar3 = 0x20b;
    lVar7 = local_res20 + (longlong)param_1;
    if (*(short *)(lVar7 + 0x18) == 0x20b) {
      uVar2 = *(uint *)(param_3 + 4);
      uVar3 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar3 = 0x8664;
      }
      else {
        if (uVar2 != 2) goto LAB_140002743;
        uVar3 = 0xaa64;
      }
      if (*(short *)(lVar7 + 4) == (short)uVar3) {
        uVar1 = *(ushort *)(lVar7 + 0x14);
        uVar3 = 0;
        if (0xef < uVar1) {
          if (*(uint *)(lVar7 + 0x50) < param_2) {
            if ((*(uint *)(lVar7 + 0x84) < 5) || (*(int *)(lVar7 + 0xa8) == (int)uVar8))
            goto LAB_140002743;
            uVar2 = *(uint *)(lVar7 + 0xac);
            uVar3 = (ulonglong)uVar2;
            if ((uVar2 == 0) || (*(uint *)(lVar7 + 0x50) + uVar2 != param_2)) goto LAB_140002743;
          }
          uVar4 = local_res20 + 0x18 + (ulonglong)uVar1;
          if (uVar4 <= param_2) {
            uVar6 = (ulonglong)*(ushort *)(lVar7 + 6);
            uVar3 = uVar6 * 5;
            if (uVar4 + uVar6 * 0x28 <= param_2) {
              lVar5 = lVar7 + 0x18 + (ulonglong)uVar1;
              for (; uVar8 < uVar6; uVar8 = uVar8 + 1) {
                uVar3 = ImagepValidateSectionHeader(lVar5,param_2);
                if ((char)uVar3 == '\0') goto LAB_140002743;
                lVar5 = lVar5 + 0x28;
              }
              *param_4 = lVar7;
              uVar9 = 1;
            }
          }
        }
      }
    }
  }
LAB_140002743:
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar9);
}



===== ImagepValidateNtHeaderGeneric @ 140002758 =====

undefined8 ImagepValidateNtHeaderGeneric(short *param_1,ulonglong param_2,ulonglong *param_3)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  *param_3 = 0;
  if ((((1 < param_2) && (in_RAX = 0x5a4d, *param_1 == 0x5a4d)) &&
      (uVar1 = (ulonglong)*(int *)(param_1 + 0x1e), uVar1 < 0x10000000)) &&
     ((in_RAX = uVar1 + 0x1a, in_RAX <= param_2 && (*(int *)(uVar1 + (longlong)param_1) == 0x4550)))
     ) {
    uVar2 = 1;
    *param_3 = uVar1;
  }
  return CONCAT71((int7)(in_RAX >> 8),uVar2);
}



===== ImagepValidateSectionHeader @ 1400027a0 =====

ulonglong ImagepValidateSectionHeader(longlong param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  
  if (*(uint *)(param_1 + 0x14) < param_2) {
    uVar1 = (ulonglong)*(uint *)(param_1 + 0x10) + (ulonglong)*(uint *)(param_1 + 0x14);
    return CONCAT71((int7)(uVar1 >> 8),uVar1 <= param_2);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== HviGetEnlightenmentInformation @ 1400027c4 =====

/* WARNING: Removing unreachable block (ram,0x0001400027dd) */

void HviGetEnlightenmentInformation(undefined8 *param_1)

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
    puVar1 = (undefined4 *)cpuid(0x40000004);
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



===== HviGetHypervisorFeatures @ 140002804 =====

/* WARNING: Removing unreachable block (ram,0x00014000281d) */

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



===== HviIsAnyHypervisorPresent @ 140002844 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002878) */
/* WARNING: Removing unreachable block (ram,0x000140002867) */

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



===== HviIsHypervisorMicrosoftCompatible @ 1400028a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400028cd) */

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



===== _guard_check_icall @ 140002910 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002928 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000294c =====

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



===== __GSHandlerCheck_SEH @ 1400029b4 =====

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



===== __cpu_features_init @ 140002a50 =====

/* WARNING: Removing unreachable block (ram,0x000140002aba) */
/* WARNING: Removing unreachable block (ram,0x000140002a69) */
/* WARNING: Removing unreachable block (ram,0x000140002a5a) */

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



===== __security_check_cookie @ 140002b20 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002b60 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002b90 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002b90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002bc0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002c40 =====

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



===== memset @ 140002f40 =====

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



===== __memset_repmovs @ 140003080 =====

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



===== __memset_query @ 140003100 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003180 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400032c0 =====

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



===== __memset_spec_plain @ 140003340 =====

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



===== HbEvtpSysDiagLogWorkItemRoutine @ 14000c010 =====

void HbEvtpSysDiagLogWorkItemRoutine
               (undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  HbEvtpProcessSystemDiagLog('\0',param_2,param_3,param_4);
  IoFreeWorkItem(param_3);
  IoReleaseRemoveLockEx(param_2 + 0x40,param_2,0x20);
  return;
}



===== HbEvtpProcessSystemDiagLogBuffer @ 14000c070 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
HbEvtpProcessSystemDiagLogBuffer
          (longlong param_1,longlong *param_2,ulonglong *param_3,undefined8 param_4)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  void *_Src;
  uint uVar6;
  ulonglong *_Size;
  undefined1 local_b8 [32];
  ulonglong local_88 [2];
  undefined8 local_78 [4];
  char *local_58;
  undefined8 local_50;
  ulonglong *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_b8;
  lVar3 = *param_2;
  iVar2 = *(int *)(lVar3 + 0x2c);
  uVar5 = *(ulonglong *)(lVar3 + 0x10);
  uVar6 = *(int *)(lVar3 + 0x30) + 0x48;
  _Size = param_3;
  if (uVar5 == DAT_1400073a0) {
    uVar5 = (ulonglong)DAT_1400073a8;
    do {
      if (uVar6 <= (uint)uVar5) {
        uVar4 = uVar5;
        if ((iVar2 == 3) && (uVar6 <= (uint)uVar5)) {
          uVar5 = *(ulonglong *)
                   (*(longlong *)
                     ((ulonglong)*(uint *)(lVar3 + 0x38) * 0x70 + *(longlong *)(param_1 + 0x20)) +
                   0x10);
          uVar4 = uVar5;
          if (DAT_1400073a0 < uVar5) {
            DAT_1400073a8 = 0x48;
            DAT_1400073a0 = uVar5;
            DAT_1400073ac = *(uint *)(lVar3 + 0x38);
            break;
          }
        }
LAB_14000c152:
        return uVar4 & 0xffffffffffffff00;
      }
      uVar4 = (ulonglong)*(uint *)(param_1 + 4);
      if ((ulonglong)*(uint *)(param_1 + 4) < uVar5 + 0x10) goto LAB_14000c152;
      _Src = (void *)(uVar5 + lVar3);
      uVar1 = *(ushort *)((longlong)_Src + 6);
      uVar4 = (ulonglong)uVar1;
      if (uVar1 == 0) goto LAB_14000c152;
      uVar1 = *(ushort *)((longlong)_Src + 4);
      if (uVar1 < 0x10) goto LAB_14000c152;
      _Size = (ulonglong *)(ulonglong)(uint)uVar1;
      uVar4 = (ulonglong)*(uint *)(param_1 + 4);
      if ((ulonglong)*(uint *)(param_1 + 4) < (ulonglong)DAT_1400073a8 + (ulonglong)uVar1)
      goto LAB_14000c152;
      memmove(DAT_1400073b0,_Src,(size_t)_Size);
      LOCK();
      UNLOCK();
      uVar5 = *(ulonglong *)(lVar3 + 0x10);
      if (uVar5 != DAT_1400073a0) goto LAB_14000c199;
      HbEvtpProcessSystemDiagLogEntry(DAT_1400073a0,_Src,(uint *)_Size);
      *param_3 = *param_3 + 1;
      DAT_1400073a8 = DAT_1400073a8 + (uVar1 + 7 & 0xfffffff8);
      uVar5 = (ulonglong)DAT_1400073a8;
    } while (*param_3 < 500);
  }
  else {
LAB_14000c199:
    DAT_1400073ac = 0xffffffff;
    if (5 < DAT_140007050) {
      local_58 = "Buffer overflow";
      local_48 = local_88;
      local_50 = 0x10;
      local_40 = 8;
      local_88[0] = DAT_1400073a0;
      uVar5 = _tlgWriteTransfer_EtwWriteTransfer
                        (0x140007050,&DAT_140005ed6,_Size,param_4,4,local_78);
    }
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== HvStatspLockExclusive @ 14000c230 =====

void HvStatspLockExclusive(undefined8 param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1,0);
  return;
}



===== HvStatspClientBufferShare @ 14000c270 =====

int HvStatspClientBufferShare
              (longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              longlong *param_5)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [56];
  
  if (param_5 != (longlong *)0x0) {
    *param_5 = 0;
  }
  if (((param_1[3] != 0) || (param_1[4] != 0)) ||
     (plVar2 = HvStatspClientBufferLookupUserInstance(param_1,param_2), plVar2 != (longlong *)0x0))
  {
    return -0x3ffffff3;
  }
  plVar2 = (longlong *)ExAllocatePool2(0x40,0x28,0x74537648);
  puVar7 = auStack_68;
  if (plVar2 == (longlong *)0x0) {
    iVar8 = -0x3fffff66;
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar5 = plVar2 + 1;
    plVar3 = param_1 + 5;
    plVar6 = (longlong *)param_1[6];
    puVar7 = auStack_68;
    if ((longlong *)*plVar6 != plVar3) {
      plVar5 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar1)();
      puVar7 = auStack_60;
    }
    *plVar5 = (longlong)plVar3;
    plVar5[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar5;
    plVar3[1] = (longlong)plVar5;
    *plVar2 = param_2;
    *(undefined8 *)(puVar7 + -8) = 0x14000c334;
    lVar4 = PsGetCurrentProcess();
    plVar2[3] = lVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14000c348;
    ObfReferenceObject(lVar4);
    *(undefined4 *)(puVar7 + 0x28) = 0xc0000010;
    *(undefined4 *)(puVar7 + 0x20) = 0;
    lVar4 = param_1[7];
    *(undefined8 *)(puVar7 + -8) = 0x14000c372;
    lVar4 = MmMapLockedPagesSpecifyCache(lVar4,1,1,0);
    plVar2[4] = lVar4;
    if (plVar2[4] == 0) {
      iVar8 = -0x3fffff66;
    }
    else {
      iVar8 = 0;
      if (param_5 != (longlong *)0x0) {
        *param_5 = plVar2[4];
      }
    }
  }
  if (iVar8 < 0) {
    if (plVar2 != param_1) {
      plVar2 = (longlong *)0x0;
    }
    *(undefined8 *)(puVar7 + -8) = 0x14000c3dd;
    HvStatspClientBufferUnshare(param_1,param_2,plVar2);
  }
  return iVar8;
}



===== HvStatspLookupMapping @ 14000c410 =====

undefined8 * HvStatspLookupMapping(longlong param_1,int param_2,int param_3,short param_4)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 8);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 8)) {
      return (undefined8 *)0x0;
    }
    if (((*(int *)(puVar1 + 3) == param_2) && (*(int *)((longlong)puVar1 + 0x1c) == param_3)) &&
       (*(short *)(puVar1 + 4) == param_4)) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== HvStatspUnlock @ 14000c450 =====

void HvStatspUnlock(undefined8 param_1)

{
  ExReleasePushLockEx(param_1,0);
  KeLeaveCriticalRegion();
  return;
}



===== HbAddDevice @ 14000c480 =====

ulonglong HbAddDevice(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar4 = IoCreateDevice(param_1,0x160,&HbpNameOfHvBootDevice,0x22,0x100,0,local_res18);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  plVar2 = *(longlong **)(local_res18[0] + 0x40);
  plVar2[3] = 0;
  *plVar2 = local_res18[0];
  plVar2[2] = param_2;
  IoInitializeRemoveLockEx(plVar2 + 8,0x6c526248,0,0,0x20);
  *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2000;
  *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 4;
  KeInitializeTimerEx(plVar2 + 0xc,0);
  PoSetPowerState(local_res18[0],1,4);
  lVar5 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
  plVar2[3] = lVar5;
  plVar1 = plVar2 + 6;
  if (lVar5 == 0) {
    uVar4 = 0xc000000e;
  }
  else {
    RtlInitUnicodeString(plVar1,L"\\DosDevices\\HvServiceDevice");
    uVar3 = IoCreateSymbolicLink(plVar1,&HbpNameOfHvBootDevice);
    uVar4 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      return uVar4;
    }
  }
  if (plVar2[7] != 0) {
    IoDeleteSymbolicLink(plVar1);
  }
  if (plVar2[3] != 0) {
    IoDetachDevice();
  }
  if (local_res18[0] != 0) {
    IoDeleteDevice();
  }
  return uVar4;
}



===== HbDriverUnload @ 14000c610 =====

void HbDriverUnload(void)

{
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_UninitializeFeatureStaging @ 14000c628 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14000c680 =====

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
      goto LAB_14000c6dd;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14000c6dd;
    }
  }
  uVar1 = 0x206;
LAB_14000c6dd:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14000c6e8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  plVar1 = (longlong *)&wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000c7a0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14000c7d8 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14000c85a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14000c85a;
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
LAB_14000c85a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000c8b0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      plVar2 = (longlong *)&wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2), plVar2 != (longlong *)0x0)
      {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        plVar2 = plVar2 + 7;
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000c910 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14000c92c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar2 = (longlong *)&wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2);
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
    plVar2 = plVar2 + 7;
  }
  return;
}



===== HbHvInitializeHypervisor @ 14000c9e0 =====

undefined8
HbHvInitializeHypervisor
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  WinHvReportPresentHypervisor();
  if (HbpIsCpuManagementPartition != '\0') {
    HbHvpOpenHypervisorBinaryFileHandles((longlong)param_1);
    WinHvSetEventLogCompletedNotificationRoutine(HbEvtpCompletedNotificationRoutine);
    HbHvpRegisterDebuggerPowerCallback((longlong)param_1);
  }
  HbHvpWithdrawMemory(param_1);
  HbEvtpInitEventLog((longlong)param_1,param_2,param_3,param_4);
  return 0;
}



===== HbHvpCloseHypervisorBinaryFileHandles @ 14000ca40 =====

void HbHvpCloseHypervisorBinaryFileHandles(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 200) = 0;
  }
  if (*(longlong *)(param_1 + 0xc0) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  return;
}



===== HbHvpOpenHypervisorBinaryFileHandles @ 14000ca98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000cb8c) */

int HbHvpOpenHypervisorBinaryFileHandles(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  char local_38 [16];
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_6c = 0;
  local_84 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_58 = 0;
  uStack_50 = 0;
  RtlInitUnicodeString(&local_98,L"\\SystemRoot\\System32\\hvloader.dll");
  local_80 = 0;
  local_78 = &local_98;
  local_a0 = 0x20;
  local_88 = 0x30;
  local_70 = 0x240;
  local_a8 = 5;
  local_68 = 0;
  uStack_60 = 0;
  iVar2 = ZwOpenFile(param_1 + 200,0x80000000,&local_88,&local_58);
  if (iVar2 < 0) goto LAB_14000cc56;
  builtin_strncpy(local_38 + 8,"cAMD",5);
  builtin_strncpy(local_28 + 8,"uine",5);
  puVar1 = (undefined8 *)cpuid_basic_info(0);
  local_48 = *puVar1;
  uStack_40 = puVar1[1];
  builtin_strncpy(local_38,"Authenti",8);
  builtin_strncpy(local_28,"HygonGen",8);
  iVar2 = strncmp((char *)((longlong)&local_48 + 4),local_38,0xc);
  if (iVar2 == 0) {
LAB_14000cbe6:
    pwVar3 = L"\\SystemRoot\\System32\\hvax64.exe";
  }
  else {
    iVar2 = strncmp((char *)((longlong)&local_48 + 4),local_28,0xc);
    pwVar3 = L"\\SystemRoot\\System32\\hvix64.exe";
    if (iVar2 == 0) goto LAB_14000cbe6;
  }
  RtlInitUnicodeString(&local_98,pwVar3);
  local_80 = 0;
  local_78 = &local_98;
  local_a0 = 0x20;
  local_88 = 0x30;
  local_70 = 0x240;
  local_a8 = 5;
  local_68 = 0;
  uStack_60 = 0;
  iVar2 = ZwOpenFile(param_1 + 0xc0,0x80000000,&local_88,&local_58);
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_14000cc56:
  HbHvpCloseHypervisorBinaryFileHandles(param_1);
  return iVar2;
}



===== HbHvpRegisterDebuggerPowerCallback @ 14000cc88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbHvpRegisterDebuggerPowerCallback(longlong param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  *(undefined8 *)(param_1 + 0x158) = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = ZwQuerySystemInformation(0x5b,&local_28,0x10);
  if ((-1 < iVar1) && (local_28._1_1_ != '\0')) {
    KdRegisterPowerHandler(HbHvpTransitionDebuggerPower,0,(undefined8 *)(param_1 + 0x158));
  }
  return;
}



===== HbHvpWithdrawMemory @ 14000cd0c =====

void HbHvpWithdrawMemory(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = IoAcquireRemoveLockEx(param_1 + 8,param_1,"",1,0x20);
  if (-1 < iVar1) {
    lVar2 = IoAllocateWorkItem(*param_1);
    if (lVar2 == 0) {
      HbHvpWithdrawMemoryWorker(*param_1,(longlong)param_1,0);
    }
    else {
      IoQueueWorkItemEx(lVar2,HbHvpWithdrawMemoryWorker,1,param_1);
    }
  }
  return;
}



===== HbHvpWithdrawMemoryWorker @ 14000cda0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbHvpWithdrawMemoryWorker(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = 0;
  local_38 = 0;
  local_28 = 0x4ea26799;
  local_24 = 0x4a1dd0dc;
  local_20 = 0x572fd69a;
  local_1c = 0x9dfca72e;
  iVar1 = WinHvGetPartitionId(&local_38);
  if (-1 < iVar1) {
    KsrFreePersistedMemory(&local_28,0);
    WinHvWaitForWithdrawAllowed();
    WinHvWithdrawMemory(local_38,0xffffffffffffffff,0x80000000,&local_30);
  }
  if (param_3 != 0) {
    IoFreeWorkItem(param_3);
  }
  IoReleaseRemoveLockEx(param_2 + 0x40,param_2,0x20);
  return;
}



===== HbIoDispatchClose @ 14000ce90 =====

undefined8 HbIoDispatchClose(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== HbIoDispatchIoctl @ 14000cec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000d61f) */
/* WARNING: Removing unreachable block (ram,0x00014000d5ff) */

int HbIoDispatchIoctl(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong *plVar12;
  uint *puVar13;
  undefined8 *_Src;
  undefined1 *puVar14;
  undefined8 uVar15;
  undefined1 *puVar16;
  uint *puVar17;
  byte bVar18;
  longlong *_Dst;
  longlong *plVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined1 auStackY_2e8 [32];
  undefined8 local_2b0;
  uint local_2a8;
  undefined4 local_2a4;
  longlong local_2a0;
  longlong local_298;
  longlong local_290;
  longlong local_288;
  longlong local_280;
  undefined8 uStack_278;
  longlong local_270;
  longlong lStack_268;
  longlong local_260;
  longlong lStack_258;
  longlong local_250;
  longlong lStack_248;
  longlong local_240 [65];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2e8;
  local_2a8 = 0;
  uVar21 = 0;
  lVar11 = *(longlong *)(param_2 + 0xb8);
  uVar3 = *(uint *)(lVar11 + 0x10);
  uVar4 = *(uint *)(lVar11 + 8);
  uVar10 = (ulonglong)uVar4;
  if (uVar3 == 0) {
    puVar17 = (uint *)0x0;
  }
  else {
    puVar17 = *(uint **)(param_2 + 0x18);
  }
  if (uVar4 == 0) {
    _Dst = (longlong *)0x0;
  }
  else {
    _Dst = *(longlong **)(param_2 + 0x18);
  }
  uVar5 = *(uint *)(lVar11 + 0x18);
  local_290 = param_2;
  if (uVar5 < 0x22803d) {
    if (uVar5 == 0x22803c) {
      if ((3 < uVar3) && (puVar17 != (uint *)0x0)) {
        uVar20 = 4;
        uVar8 = 10;
        goto LAB_14000d37b;
      }
    }
    else {
      uVar20 = 0x228008;
      if (uVar5 < 0x228009) {
        if (uVar5 != 0x228008) {
          if (uVar5 == 0x223fec) {
            iVar7 = WinHvCommitSecFwSvn();
LAB_14000d165:
            if (-1 < iVar7) {
              HbEvtpLogSecFwStatus();
            }
            goto LAB_14000cff2;
          }
          if (uVar5 == 0x223ff1) {
            uVar21 = 0x10;
            if ((((0xf < uVar3) && (puVar17 != (uint *)0x0)) && (puVar17[3] <= uVar4)) &&
               (uVar4 != 0)) {
              lVar11 = *(longlong *)(param_2 + 8);
              if ((*(byte *)(lVar11 + 10) & 5) == 0) {
                lVar11 = MmMapLockedPagesSpecifyCache(lVar11,0,1);
              }
              else {
                lVar11 = *(longlong *)(lVar11 + 0x18);
              }
              if (lVar11 == 0) goto LAB_14000d13f;
              iVar7 = WinHvUpdateSecFw((char)*puVar17,puVar17[1],puVar17[2]);
              goto LAB_14000d165;
            }
          }
          else {
            if (uVar5 != 0x223ff4) {
              if (uVar5 == 0x223ff8) {
                if ((7 < uVar3) && (puVar17 != (uint *)0x0)) {
                  if (7 < *puVar17 - 1) goto LAB_14000d03f;
                  uVar10 = HvStatsUnmapHvStatsPage
                                     (*(longlong *)(param_1 + 0x40),*(longlong *)(lVar11 + 0x30),
                                      *puVar17,puVar17[1]);
                  iVar7 = (int)uVar10;
                  goto LAB_14000cff2;
                }
              }
              else {
                if (uVar5 != 0x223ffc) goto LAB_14000d689;
                if (((7 < uVar4) && (_Dst != (longlong *)0x0)) &&
                   ((7 < uVar3 && (puVar17 != (uint *)0x0)))) {
                  local_2b0 = 0;
                  if (7 < *puVar17 - 1) goto LAB_14000d03f;
                  iVar7 = HvStatsMapHvStatsPage
                                    (*(longlong *)(param_1 + 0x40),*(longlong *)(lVar11 + 0x30),
                                     *puVar17,puVar17[1],&local_2b0);
                  if (-1 < iVar7) {
                    *_Dst = local_2b0;
                    uVar21 = 8;
                  }
                  goto LAB_14000cff2;
                }
              }
              goto LAB_14000d357;
            }
            if ((3 < uVar4) && (_Dst != (longlong *)0x0)) {
              local_2b0 = (ulonglong)local_2b0._4_4_ << 0x20;
              if (HbpIsCpuManagementPartition == '\0') {
                uVar8 = KeQueryActiveProcessorCountEx(0xffff);
                iVar7 = 0;
              }
              else {
                iVar7 = HvlQueryActiveHypervisorProcessorCount(&local_2b0);
                if (iVar7 < 0) goto LAB_14000cff2;
                uVar8 = (undefined4)local_2b0;
              }
              *(undefined4 *)_Dst = uVar8;
              uVar21 = 4;
              goto LAB_14000cff2;
            }
          }
          goto LAB_14000d2b5;
        }
        if (uVar3 == 8) {
          iVar7 = WinHvConfigureProfiler
                            (**(undefined2 **)(param_2 + 0x18),
                             *(undefined4 *)(*(undefined2 **)(param_2 + 0x18) + 2));
          goto LAB_14000cff2;
        }
      }
      else if (uVar5 == 0x22800c) {
        if ((uVar3 == 0) && (uVar4 == 0)) {
          uVar15 = 1;
          lVar11 = param_2;
          iVar7 = WinHvUpdateHvProcessorFeatures();
          if (-1 < iVar7) {
            HbEvtpLogProcessorFeatures('\x01',uVar15,lVar11,uVar20);
          }
          goto LAB_14000cff2;
        }
      }
      else if (uVar5 == 0x228010) {
        if ((0xf < uVar4) && (_Dst != (longlong *)0x0)) {
          for (bVar18 = 0; bVar18 < 2; bVar18 = bVar18 + 1) {
            local_2b0 = 0;
            iVar7 = WinHvGetPartitionProperty(0xffffffffffffffff,bVar18 + 0x6000a,&local_2b0);
            if (iVar7 < 0) goto LAB_14000cff2;
            _Dst[bVar18] = local_2b0;
          }
          uVar21 = 0x10;
LAB_14000d321:
          iVar7 = 0;
          goto LAB_14000cff2;
        }
      }
      else {
        if (uVar5 == 0x228028) {
          uVar21 = 4;
          if ((3 < uVar4) && (_Dst != (longlong *)0x0)) {
            local_2a4 = 0;
            iVar7 = WinHvGetSystemInformation(1,0,0,&local_2a4);
            if (-1 < iVar7) {
              *(undefined4 *)_Dst = local_2a4;
            }
            goto LAB_14000cff7;
          }
          goto LAB_14000d2b5;
        }
        if (uVar5 == 0x228034) {
          if ((0xf < uVar3) && (puVar17 != (uint *)0x0)) {
            iVar7 = WinHvUpdateHvProcessorFeatures(*puVar17,*(undefined8 *)(puVar17 + 2));
            goto LAB_14000cff2;
          }
        }
        else {
          if (uVar5 != 0x228038) goto LAB_14000d689;
          if ((((3 < uVar3) && (puVar17 != (uint *)0x0)) && (7 < uVar4)) &&
             (_Dst != (longlong *)0x0)) {
            iVar7 = WinHvGetSystemInformation(3,puVar17,4,_Dst);
            if (-1 < iVar7) {
              uVar21 = (ulonglong)local_2a8;
            }
            goto LAB_14000cff7;
          }
        }
      }
    }
LAB_14000d357:
    iVar7 = -0x3ffffff3;
  }
  else {
    if (0x228054 < uVar5) {
      if (uVar5 == 0x228058) {
        local_298 = 0;
        if (((7 < uVar4) && (_Dst != (longlong *)0x0)) &&
           ((0xf < uVar3 && (puVar17 != (uint *)0x0)))) {
          puVar16 = (undefined1 *)((ulonglong)puVar17[1] + (longlong)puVar17);
          uVar4 = *puVar17;
          puVar14 = (undefined1 *)((ulonglong)uVar3 + (longlong)puVar17);
          if ((puVar16 + (ulonglong)uVar4 * 0x10 <= puVar14) &&
             ((undefined1 *)((ulonglong)puVar17[2] + (longlong)puVar17) + (ulonglong)uVar4 * 0x10 <=
              puVar14)) {
            for (puVar14 = puVar16; puVar14 < puVar16 + (ulonglong)uVar4 * 0x10;
                puVar14 = puVar14 + 0x10) {
              if (*(int *)(puVar14 + 4) != 0x10003) goto LAB_14000d03f;
            }
            iVar7 = WinHvSetLogicalProcessorRegisters
                              (uVar4,puVar16,
                               (undefined1 *)((ulonglong)puVar17[2] + (longlong)puVar17),&local_298)
            ;
            if (-1 < iVar7) {
              *_Dst = local_298;
              uVar21 = 8;
            }
            goto LAB_14000cff7;
          }
LAB_14000d03f:
          iVar7 = -0x3ffffff3;
          goto LAB_14000cff2;
        }
      }
      else {
        if (uVar5 != 0x22805c) {
          if (uVar5 != 0x228060) {
            if (uVar5 == 0x22bfe4) {
              uVar20 = 0;
              puVar17 = (uint *)0x0;
              uVar8 = 0x10;
            }
            else {
              if (uVar5 != 0x22bfe8) goto LAB_14000d689;
              if ((uVar3 != 1) || (puVar17 == (uint *)0x0)) goto LAB_14000d357;
              uVar20 = 1;
              uVar8 = 0xf;
            }
LAB_14000d37b:
            iVar7 = WinHvSetSystemInformation(uVar8,puVar17,uVar20);
            goto LAB_14000cff2;
          }
          if ((_Dst != (longlong *)0x0) && (0x2f < uVar4)) {
            local_270 = 0;
            lStack_268 = 0;
            local_260 = 0;
            lStack_258 = 0;
            local_250 = 0;
            lStack_248 = 0;
            iVar7 = WinHvGetSystemInformation(0,0,0,&local_270);
            if (-1 < iVar7) {
              *_Dst = local_270;
              _Dst[1] = lStack_268;
              _Dst[2] = local_260;
              _Dst[3] = lStack_258;
              _Dst[4] = local_250;
              _Dst[5] = lStack_248;
              uVar21 = 0x30;
            }
            goto LAB_14000cff7;
          }
          goto LAB_14000d2b5;
        }
        if ((((0x1f < uVar4) && (_Dst != (longlong *)0x0)) && (0x13 < uVar3)) &&
           (puVar17 != (uint *)0x0)) {
          puVar1 = puVar17 + 1;
          puVar2 = puVar1 + (ulonglong)*puVar17 * 4;
          if (((puVar1 != puVar2) && (puVar2 <= (uint *)((longlong)puVar17 + (ulonglong)uVar3))) &&
             (_Dst + (ulonglong)*puVar17 * 2 + 2 <= (longlong *)((longlong)_Dst + uVar10))) {
            for (puVar13 = puVar1; puVar13 < puVar2; puVar13 = puVar13 + 4) {
              if (puVar13[1] != 0x10003) goto LAB_14000d03f;
            }
            _Src = (undefined8 *)ExAllocatePool2(0x40,uVar10,0x6f496248);
            if (_Src == (undefined8 *)0x0) {
LAB_14000d13f:
              iVar7 = -0x3fffff66;
            }
            else {
              *_Src = 0;
              iVar7 = WinHvGetLogicalProcessorRegisters(*puVar17,puVar1,_Src,_Src + 2);
              if (-1 < iVar7) {
                memmove(_Dst,_Src,uVar10);
                uVar21 = uVar10;
              }
              ExFreePoolWithTag(_Src,0x6f496248);
            }
            goto LAB_14000cff2;
          }
          goto LAB_14000d03f;
        }
      }
      goto LAB_14000d357;
    }
    if (uVar5 == 0x228054) {
      if ((3 < uVar3) && (puVar17 != (uint *)0x0)) {
        uVar3 = *puVar17;
        uVar21 = 8;
        local_2b0 = CONCAT44(local_2b0._4_4_,8);
        if ((7 < uVar4) && (_Dst != (longlong *)0x0)) {
          if ((uVar3 == 0xc0010132) || (uVar3 == 0xc0010133)) {
            puVar17 = (uint *)cpuid(0x80000000);
            local_280 = (ulonglong)puVar17[1] << 0x20;
            uStack_278 = CONCAT44(puVar17[2],puVar17[3]);
            if (0x8000001e < *puVar17) {
              puVar17 = (uint *)cpuid(0x8000001f);
              local_280 = (ulonglong)puVar17[1] << 0x20;
              uStack_278 = CONCAT44(puVar17[2],puVar17[3]);
              if ((*puVar17 & 0x10) != 0) {
                local_288 = rdmsr(uVar3);
                *_Dst = local_288;
                goto LAB_14000d321;
              }
            }
          }
          goto LAB_14000d03f;
        }
LAB_14000d4d7:
        iVar7 = -0x3fffffdd;
        goto LAB_14000cff2;
      }
LAB_14000d2b5:
      iVar7 = -0x3fffffdd;
    }
    else {
      if (uVar5 == 0x228040) {
        local_280 = 0;
        uStack_278 = uStack_278 & 0xffffffff00000000;
        uVar21 = 0xc;
        if ((0xb < uVar4) && (_Dst != (longlong *)0x0)) {
          iVar7 = WinHvGetSystemInformation(10,0,0,&local_280);
          if (-1 < iVar7) {
            *_Dst = local_280;
            *(undefined4 *)(_Dst + 1) = (undefined4)uStack_278;
          }
          goto LAB_14000cff7;
        }
        goto LAB_14000d2b5;
      }
      lVar11 = 4;
      if (uVar5 == 0x228044) {
        local_2a0 = 0;
        uVar21 = 8;
        if ((7 < uVar4) && (_Dst != (longlong *)0x0)) {
          iVar7 = WinHvGetSystemInformation(0xc,0,0,&local_2a0);
          if (-1 < iVar7) {
            *_Dst = local_2a0;
          }
          goto LAB_14000cff7;
        }
        goto LAB_14000d2b5;
      }
      if (uVar5 == 0x228048) {
        uVar21 = 0x208;
        memset(local_240,0,0x208);
        if ((uVar4 < 0x208) || (_Dst == (longlong *)0x0)) goto LAB_14000d4d7;
        iVar7 = WinHvGetSystemInformation(0xb,0,0,local_240);
        if (-1 < iVar7) {
          plVar12 = local_240;
          do {
            lVar6 = plVar12[1];
            *_Dst = *plVar12;
            _Dst[1] = lVar6;
            lVar6 = plVar12[3];
            _Dst[2] = plVar12[2];
            _Dst[3] = lVar6;
            lVar6 = plVar12[5];
            _Dst[4] = plVar12[4];
            _Dst[5] = lVar6;
            lVar6 = plVar12[7];
            _Dst[6] = plVar12[6];
            _Dst[7] = lVar6;
            lVar6 = plVar12[9];
            _Dst[8] = plVar12[8];
            _Dst[9] = lVar6;
            lVar6 = plVar12[0xb];
            _Dst[10] = plVar12[10];
            _Dst[0xb] = lVar6;
            lVar6 = plVar12[0xd];
            _Dst[0xc] = plVar12[0xc];
            _Dst[0xd] = lVar6;
            plVar19 = _Dst + 0x10;
            lVar6 = plVar12[0xf];
            _Dst[0xe] = plVar12[0xe];
            _Dst[0xf] = lVar6;
            plVar12 = plVar12 + 0x10;
            lVar11 = lVar11 + -1;
            _Dst = plVar19;
          } while (lVar11 != 0);
          *plVar19 = *plVar12;
        }
LAB_14000cff2:
        goto LAB_14000cff7;
      }
      if (uVar5 == 0x22804c) {
        if ((0xfff < uVar3 - 1) || (puVar17 == (uint *)0x0)) goto LAB_14000d357;
        iVar7 = WinHvSetHwWatchdogConfig(puVar17,uVar3);
        goto LAB_14000cff2;
      }
      if (uVar5 == 0x228050) {
        iVar7 = WinHvLogHypervisorSystemConfig();
        iVar9 = HbEvtpTraceMinrootConfig();
        if (-1 < iVar7) {
          iVar7 = iVar9;
        }
        goto LAB_14000cff7;
      }
LAB_14000d689:
      iVar7 = -0x3ffffff0;
    }
  }
LAB_14000cff7:
  *(ulonglong *)(param_2 + 0x38) = uVar21;
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return iVar7;
}



===== HbPnpDeleteAllEventLogs @ 14000d8e8 =====

void HbPnpDeleteAllEventLogs(longlong param_1)

{
  KeCancelTimer(param_1 + 0x60);
  KeWaitForSingleObject(param_1 + 0xd0,0,0,0,0);
  *(undefined1 *)(param_1 + 0x108) = 1;
  HbEvtpDeleteEventLog(param_1,0);
  HbEvtpDeleteEventLog(param_1,1);
  HbEvtpDeleteEventLog(param_1,2);
  KeReleaseMutex(param_1 + 0xd0,0);
  return;
}



===== HbPnpFreeResources @ 14000d978 =====

void HbPnpFreeResources(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(param_1 + 0x38) != 0) {
    IoDeleteSymbolicLink(param_1 + 0x30);
  }
  if (HbpIsCpuManagementPartition != '\0') {
    WinHvSetEventLogCompletedNotificationRoutine(0);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    IoSetDeviceInterfaceState(param_1 + 0x20,0);
    RtlFreeUnicodeString(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (HbpIsCpuManagementPartition != '\0') {
    if (*(longlong *)(param_1 + 0x158) != 0) {
      KdDeregisterPowerHandler();
      *(undefined8 *)(param_1 + 0x158) = 0;
    }
    HbHvpCloseHypervisorBinaryFileHandles(param_1);
  }
  puVar6 = auStack_28;
  puVar7 = auStack_28;
  if (*(int *)(param_1 + 0xb8) != 0) {
    while (plVar1 = *(longlong **)(param_1 + 0xa8), plVar1 != (longlong *)(param_1 + 0xa8)) {
      HvStatspUnmap((longlong)plVar1);
      lVar2 = *plVar1;
      if (((longlong *)*(longlong *)(lVar2 + 8) != plVar1) ||
         (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_20;
        break;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(plVar1,0x74537648);
    }
    *(undefined4 *)(param_1 + 0xb8) = 0;
    puVar7 = puVar6;
  }
  if (HbpIsCpuManagementPartition != '\0') {
    *(undefined8 *)(puVar7 + -8) = 0x14000da83;
    McGenEventUnregister_EtwUnregister();
  }
  if (HbEvtpLocalDiagnosticsEventsHandle != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x14000da96;
    EtwUnregister();
    HbEvtpLocalDiagnosticsEventsHandle = 0;
  }
  uVar5 = DAT_140007070;
  if (DAT_140007049 != '\0') {
    DAT_140007070 = 0;
    DAT_140007050 = 0;
    *(undefined8 *)(puVar7 + -8) = 0x14000dac6;
    EtwUnregister(uVar5);
  }
  uVar5 = DAT_1400070a8;
  DAT_1400070a8 = 0;
  DAT_140007088 = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14000dae6;
  EtwUnregister(uVar5);
  return;
}



===== HbPnpStartDevice @ 14000db08 =====

int HbPnpStartDevice(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x140007088,0,0);
  IoForwardIrpSynchronously(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x18),param_2);
  iVar4 = *(int *)(param_2 + 0x30);
  if (-1 < iVar4) {
    KeInitializeMutex(puVar2 + 0x1a,0);
    puVar2[0x23] = 0;
    *(undefined4 *)(puVar2 + 0x24) = 0;
    uVar5 = 1;
    *(undefined1 *)(puVar2 + 0x21) = 0;
    uVar6 = 0;
    *(undefined4 *)(puVar2 + 0x22) = 1;
    KeInitializeEvent(puVar2 + 0x25);
    puVar2[0x29] = 0xffffffffffffffff;
    puVar1 = puVar2 + 0x15;
    puVar2[0x16] = puVar1;
    *puVar1 = puVar1;
    *(undefined4 *)(puVar2 + 0x2a) = 1;
    *(undefined4 *)(puVar2 + 0x17) = 1;
    uVar5 = HbHvInitializeHypervisor(puVar2,uVar5,uVar6,param_4);
    iVar4 = (int)uVar5;
    if (((-1 < iVar4) &&
        (iVar4 = IoRegisterDeviceInterface(puVar2[2],&GUID_DEVINTERFACE_HVBOOT,0,puVar2 + 4),
        -1 < iVar4)) && (iVar4 = IoSetDeviceInterfaceState(puVar2 + 4,1), -1 < iVar4)) {
      PoSetPowerState(*puVar2,1,1);
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(lVar3 + 0x40,param_2,0x20);
  return iVar4;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14000dc80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
              (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = param_2;
  *(undefined8 *)(param_1 + 0x30) = param_3;
  *(undefined8 *)(puVar7 + -8) = 0x14000dce1;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14000dd01;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000dd15;
  return iVar6;
}



===== HvStatsMapHvStatsPage @ 14000dd2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HvStatsMapHvStatsPage
              (longlong param_1,longlong param_2,int param_3,uint param_4,longlong *param_5)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  ushort uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  ulonglong local_60 [4];
  
  local_60[2] = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = param_1 + 0xa0;
  *param_5 = 0;
  bVar3 = false;
  local_60[0] = 0;
  local_60[1] = 0;
  HviGetHypervisorFeatures(local_60);
  puVar9 = auStackY_98;
  if ((local_60[0] >> 0x2c & 1) == 0) {
    if ((param_3 - 3U & 0xfffffffb) != 0) {
      iVar4 = -0x3fffffde;
      goto LAB_14000dea0;
    }
LAB_14000ddae:
    uVar10 = 1;
  }
  else {
    if ((param_3 - 3U & 0xfffffffa) == 0) goto LAB_14000ddae;
    uVar10 = 0;
  }
  HvStatspLockExclusive(lVar1);
  uVar12 = (ulonglong)uVar10;
  uVar11 = (ulonglong)param_4;
  plVar5 = HvStatspLookupMapping(lVar1,param_3,param_4,uVar10);
  if (plVar5 == (longlong *)0x0) {
    bVar3 = true;
    plVar5 = (longlong *)ExAllocatePool2(0x100,0x70,0x74537648);
    if (plVar5 == (longlong *)0x0) {
      iVar4 = -0x3fffff66;
      puVar9 = auStackY_98;
    }
    else {
      *(int *)(plVar5 + 3) = param_3;
      *(uint *)((longlong)plVar5 + 0x1c) = param_4;
      *(ushort *)(plVar5 + 4) = uVar10;
      uVar11 = 0x40;
      memset(plVar5 + 6,0,0x40);
      plVar7 = plVar5 + 0xb;
      plVar5[0xc] = (longlong)plVar7;
      *plVar7 = (longlong)plVar7;
      iVar4 = HvStatspMap((longlong)plVar5);
      if (-1 < iVar4) goto LAB_14000de37;
LAB_14000de7c:
      HvStatspUnmap((longlong)plVar5);
      ExFreePoolWithTag(plVar5,0x74537648);
      puVar9 = auStackY_98;
    }
  }
  else {
LAB_14000de37:
    iVar4 = HvStatspClientBufferShare(plVar5 + 6,param_2,uVar11,uVar12,param_5);
    puVar9 = auStackY_98;
    puVar8 = auStackY_98;
    if (iVar4 < 0) {
      if (bVar3) goto LAB_14000de7c;
    }
    else {
      puVar9 = auStackY_98;
      if (bVar3) {
        lVar6 = param_1 + 0xa8;
        plVar7 = *(longlong **)(param_1 + 0xb0);
        if (*plVar7 != lVar6) {
          plVar7 = (longlong *)0x3;
          pcVar2 = (code *)swi(0x29);
          lVar6 = (*pcVar2)();
          puVar8 = auStackY_90;
        }
        *plVar5 = lVar6;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(lVar6 + 8) = plVar5;
        puVar9 = puVar8;
      }
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x14000dea0;
  HvStatspUnlock(lVar1);
LAB_14000dea0:
  *(undefined8 *)(puVar9 + -8) = 0x14000deaf;
  return iVar4;
}



===== HvStatsUnmapHvStatsPage @ 14000dec8 =====

ulonglong HvStatsUnmapHvStatsPage(longlong param_1,longlong param_2,int param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  lVar1 = param_1 + 0xa0;
  HvStatspLockExclusive(lVar1);
  plVar5 = HvStatspLookupMapping(lVar1,param_3,param_4,(ushort)((param_3 - 3U & 0xfffffffa) == 0));
  if (plVar5 == (longlong *)0x0) {
    uVar7 = 0xc000000d;
  }
  else {
    uVar6 = HvStatspClientBufferUnshare(plVar5 + 6,param_2,(longlong *)0x0);
    uVar7 = uVar6 & 0xffffffff;
    if (-1 < (int)uVar6) {
      if (((plVar5[9] == 0) && (plVar5[10] == 0)) && ((longlong *)plVar5[0xb] == plVar5 + 0xb)) {
        HvStatspUnmap((longlong)plVar5);
        lVar2 = *plVar5;
        if ((*(longlong **)(lVar2 + 8) != plVar5) ||
           (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          uVar6 = (*pcVar4)();
          return uVar6;
        }
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        ExFreePoolWithTag(plVar5,0x74537648);
      }
      uVar7 = 0;
    }
  }
  HvStatspUnlock(lVar1);
  return uVar7;
}



===== HvStatspClientBufferLookupUserInstance @ 14000dfc4 =====

longlong * HvStatspClientBufferLookupUserInstance(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)0x0;
  if (param_2 == 0) {
    if ((param_1[3] != 0) || (param_1[4] != 0)) {
      return param_1;
    }
  }
  else {
    for (plVar2 = (longlong *)param_1[5];
        (plVar1 = (longlong *)0x0, plVar2 != param_1 + 5 &&
        (plVar1 = plVar2 + -1, *plVar1 != param_2)); plVar2 = (longlong *)*plVar2) {
    }
  }
  return plVar1;
}



===== HvStatspClientBufferUnshare @ 14000e004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 HvStatspClientBufferUnshare(longlong *param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 == (longlong *)0x0) {
    if ((param_2 != 0) &&
       (param_3 = HvStatspClientBufferLookupUserInstance(param_1,param_2),
       param_3 != (longlong *)0x0)) {
LAB_14000e07f:
      plVar1 = param_3 + 3;
      if (param_3[4] != 0) {
        KeStackAttachProcess(*plVar1,&local_58);
        MmUnmapLockedPages(param_3[4],param_1[7]);
        KeUnstackDetachProcess(&local_58);
        param_3[4] = 0;
      }
      if (*plVar1 != 0) {
        ObfDereferenceObject();
        *plVar1 = 0;
      }
      if (param_3 == param_1) {
        return 0;
      }
      plVar1 = param_3 + 1;
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) == plVar1) &&
         (plVar3 = (longlong *)param_3[2], (longlong *)*plVar3 == plVar1)) {
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        ExFreePoolWithTag(param_3,0x74537648);
        return 0;
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar5 = (*pcVar4)();
      return uVar5;
    }
  }
  else if ((param_3 == param_1) && (param_2 == 0)) goto LAB_14000e07f;
  return 0xc000000d;
}



===== HvStatspMap @ 14000e12c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HvStatspMap(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_28;
  ulonglong local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  iVar1 = *(int *)(param_1 + 0x18);
  local_20 = 0;
  uStack_18 = 0;
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        local_20 = *(ulonglong *)(param_1 + 0x10);
        uVar3 = 0x10001;
        uStack_18 = (ulonglong)*(ushort *)(param_1 + 0x20) << 0x20;
        goto LAB_14000e1fe;
      }
      if (iVar1 == 4) {
        local_20 = *(ulonglong *)(param_1 + 0x10);
        uVar3 = 0x10001;
        uStack_18 = (ulonglong)*(ushort *)(param_1 + 0x20) << 0x20;
      }
      else {
        if (iVar1 == 5) {
          uVar3 = 2;
          local_20 = (ulonglong)*(uint *)(param_1 + 0x1c);
          goto LAB_14000e1fe;
        }
        if (iVar1 == 6) {
          uVar3 = 2;
          uStack_18 = 0x200000000000000;
          local_20 = (ulonglong)*(uint *)(param_1 + 0x1c);
          goto LAB_14000e1fe;
        }
        local_20 = *(ulonglong *)(param_1 + 0x10);
        uVar3 = 0x10002;
        uStack_18 = (ulonglong)*(uint6 *)(param_1 + 0x1c);
        if (iVar1 == 7) goto LAB_14000e1fe;
      }
      uStack_18 = CONCAT17(2,(undefined7)uStack_18);
      goto LAB_14000e1fe;
    }
    uStack_18 = 0x200000000000000;
  }
  uVar3 = 1;
LAB_14000e1fe:
  iVar1 = WinHvMapStatsPage(uVar3,&local_20,&local_28,param_1 + 0x28);
  if (-1 < iVar1) {
    local_38 = 0;
    lVar2 = IoAllocateMdl(local_28,0x1000,0,0);
    *(longlong *)(param_1 + 0x68) = lVar2;
    if (lVar2 != 0) {
      MmBuildMdlForNonPagedPool(lVar2);
      return 0;
    }
    iVar1 = -0x3fffff66;
  }
  HvStatspUnmap(param_1);
  return iVar1;
}



===== HvStatspUnmap @ 14000e28c =====

void HvStatspUnmap(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)(param_1 + 0x30);
  HvStatspClientBufferUnshare(plVar1,0,plVar1);
  while (plVar2 = *(longlong **)(param_1 + 0x58), plVar2 != (longlong *)(param_1 + 0x58)) {
    HvStatspClientBufferUnshare(plVar1,0,plVar2 + -1);
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x68) = 0;
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    WinHvUnmapStatsPage();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}



===== HbSysCtrlDispatch @ 14000e320 =====

int HbSysCtrlDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x40,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
    IoReleaseRemoveLockEx(lVar1 + 0x40,param_2,0x20);
  }
  return iVar2;
}



===== HbEvtpAllocateAndInitializeEventLogMdl @ 14000e3d4 =====

uint HbEvtpAllocateAndInitializeEventLogMdl(int param_1,longlong *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  if (param_1 - 1U < 0x200) {
    if (DAT_140007048 == '\0') {
      lVar3 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0,param_1 << 0xc,1,4);
      *param_2 = lVar3;
      uVar1 = ~-(uint)(lVar3 != 0) & 0xc000009a;
    }
    else {
      puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x1030,0x75426248);
      *param_2 = (longlong)puVar2;
      if (puVar2 == (undefined8 *)0x0) {
        uVar1 = 0xc000009a;
      }
      else {
        *puVar2 = 0;
        *(undefined2 *)((longlong)puVar2 + 10) = 0;
        *(short *)(puVar2 + 1) = ((short)param_1 + 6) * 8;
        puVar2[4] = 0;
        *(undefined4 *)((longlong)puVar2 + 0x2c) = 0;
        *(int *)(puVar2 + 5) = param_1 << 0xc;
        *(ushort *)(*param_2 + 10) = *(ushort *)(*param_2 + 10) | 0x2002;
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== HbEvtpCreateEventLogBuffer @ 14000e4c0 =====

uint HbEvtpCreateEventLogBuffer
               (undefined8 param_1,undefined4 param_2,uint param_3,int *param_4,undefined8 param_5)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  ushort local_res10 [8];
  undefined8 local_res20;
  undefined8 *puVar7;
  
  uVar1 = (ulonglong)param_3;
  local_res10[0] = 0;
  local_res20 = 0;
  plVar6 = (longlong *)(uVar1 * 0x70 + *(longlong *)(param_4 + 8));
  *(undefined4 *)(plVar6 + 10) = param_2;
  *(uint *)((longlong)plVar6 + 0x54) = param_3;
  uVar2 = HbEvtpAllocateAndInitializeEventLogMdl(*param_4,plVar6 + 1);
  if ((int)uVar2 < 0) {
    HbpTraceFault(0,"HbEvtpCreateEventLogBuffer",
                  "HbEvtpAllocateAndInitializeEventLogMdl failed for %d - ntStatus: %X",uVar1);
  }
  else {
    iVar3 = HvlQueryHypervisorProcessorNodeNumber
                      (uVar1 % (ulonglong)HbEvtpActiveProcessorCount,local_res10);
    if (iVar3 < 0) {
      uVar5 = 0x8000ffff;
    }
    else {
      uVar5 = local_res10[0] | 0x80000000;
    }
    puVar7 = &local_res20;
    uVar2 = WinHvDepositMemory(param_5,*param_4,uVar5,0,puVar7);
    if (-1 < (int)uVar2) {
      KeInitializeDpc(plVar6 + 2,HbEvtpTraceCompletedDpcRoutine,param_1);
      uVar2 = WinHvCreateEventLogBuffer(param_2,uVar1,uVar5);
      if ((int)uVar2 < 0) {
        HbpTraceFault(0,"HbEvtpCreateEventLogBuffer",
                      "WinHvCreateEventLogBuffer failed for %d - ntStatus: %X",uVar1);
      }
      else {
        uVar2 = WinHvMapEventLogBuffer(param_2,uVar1,plVar6[1] + 0x30);
        if ((int)uVar2 < 0) {
          HbpTraceFault(0,"HbEvtpCreateEventLogBuffer",
                        "WinHvMapEventLogBuffer failed for %d - ntStatus: %X",uVar1);
        }
        else {
          lVar4 = MmMapLockedPagesSpecifyCache
                            (plVar6[1],0,1,0,(ulonglong)puVar7 & 0xffffffff00000000,0x40000020);
          *plVar6 = lVar4;
          if (lVar4 != 0) {
            return uVar2;
          }
          uVar2 = 0xc000009a;
          HbpTraceFault(0,"HbEvtpCreateEventLogBuffer","MmMapLockedPagesSpecifyCache failed for %d",
                        uVar1);
          WinHvReleaseEventLogBuffer(param_2,uVar1);
          WinHvUnmapEventLogBuffer(param_2,uVar1);
        }
        WinHvDeleteEventLogBuffer(param_2,uVar1);
      }
    }
  }
  if (DAT_140007048 == '\0') {
    MmFreePagesFromMdl(plVar6[1]);
  }
  if (plVar6[1] != 0) {
    ExFreePoolWithTag(plVar6[1],0x75426248);
    plVar6[1] = 0;
  }
  return uVar2;
}



===== HbEvtpCreateLocalDiagnosticsEventLog @ 14000e6fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HbEvtpCreateLocalDiagnosticsEventLog
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  undefined4 local_78 [2];
  uint local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58 = 0;
  uStack_50 = 0;
  local_78[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  cVar1 = ExAcquireRundownProtection();
  if (cVar1 == '\0') {
    uVar2 = 0xc00000a3;
  }
  else {
    if (*(longlong *)(param_1 + 0x148) == -1) {
      local_88 = param_2;
      uVar2 = WmiQueryTraceInformation(9,&local_58,0x20,local_78);
      if (-1 < (int)uVar2) {
        uVar2 = local_58._4_4_ >> 0xc;
        if (uVar2 == 0) {
          uVar2 = 0xc000000d;
        }
        else {
          local_6c = uVar2 << 0xc;
          local_68 = uStack_50._4_4_;
          local_64 = (undefined4)uStack_40;
          if (uStack_40._4_4_ == 1) {
            local_60 = 2;
          }
          else {
            local_60 = (uint)(uStack_40._4_4_ != 2);
          }
          local_70 = uVar2;
          uVar2 = HbEvtpCreateEventLog(param_1,1,param_3,(int *)&local_70);
        }
      }
    }
    else {
      HbpTraceFault(0,"HbEvtpCreateLocalDiagnosticsEventLog","LoggerId already set",param_4);
      uVar2 = 0xff;
    }
    ExReleaseRundownProtection(&DAT_140007298);
  }
  return uVar2;
}



===== HbEvtpDeleteEventLog @ 14000e830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HbEvtpDeleteEventLog(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  uint local_48 [2];
  longlong local_40;
  uint *local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  local_58 = 0;
  local_38 = (uint *)0x0;
  uStack_30 = 0;
  KeWaitForSingleObject(param_1 + 0xd0,0,0,0);
  uVar2 = (ulonglong)param_2;
  uVar1 = HbEvtpGetLogConfiguration(param_2,&local_40);
  local_48[0] = (uint)uVar1;
  if (-1 < (int)local_48[0]) {
    if (((local_40 == 0) || (*(int *)(local_40 + 8) == 0)) || (*(longlong *)(local_40 + 0x20) == 0))
    {
      local_48[0] = 0;
    }
    else {
      uVar2 = HbEvtpWaitUntilAllBuffersAreFree(uVar2,param_2);
      local_48[0] = (uint)uVar2;
      if ((int)local_48[0] < 0) {
        HbpTraceFault(0,"HbEvtpDeleteEventLog","Failed to wait until buffers are free (0x%x)",
                      uVar2 & 0xffffffff);
      }
      HbEvtpDeleteEventLogWorker(param_1,param_2);
    }
    if (-1 < (int)local_48[0]) goto LAB_14000e928;
  }
  HbpTraceFault(0,"HbEvtpDeleteEventLog","Failed with 0x%x ",(ulonglong)local_48[0]);
  local_38 = local_48;
  uStack_30 = 4;
  HbEvtpWriteEventLog(&HV_EVENTLOG_DELETION_FAILED,1,&local_38);
LAB_14000e928:
  KeReleaseMutex(param_1 + 0xd0,0);
  return local_48[0];
}



===== HbEvtpDeleteEventLogWorker @ 14000e960 =====

void HbEvtpDeleteEventLogWorker(longlong param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  undefined4 *local_res18;
  undefined8 local_res20;
  undefined8 local_48 [2];
  
  local_res18 = (undefined4 *)0x0;
  local_48[0] = 0;
  local_res20 = 0;
  bVar1 = false;
  uVar5 = HbEvtpGetLogConfiguration(param_2,&local_res18);
  puVar2 = local_res18;
  uVar3 = (uint)uVar5;
  if (-1 < (int)uVar3) {
    ExWaitForRundownProtectionRelease(local_res18 + 6);
    bVar1 = true;
    uVar7 = 0;
    if (puVar2[2] != 0) {
      do {
        puVar9 = (undefined8 *)((ulonglong)uVar7 * 0x70 + *(longlong *)(puVar2 + 8));
        ExWaitForRundownProtectionRelease(*(longlong *)(puVar2 + 10) + (ulonglong)uVar7 * 8);
        WinHvReleaseEventLogBuffer(param_2,uVar7);
        uVar3 = WinHvUnmapEventLogBuffer(param_2,uVar7);
        if ((int)uVar3 < 0) {
          pcVar8 = "Error unmapping buffer %d: 0x%x";
LAB_14000eaaf:
          HbpTraceFault(0,"HbEvtpDeleteEventLogWorker",pcVar8,(ulonglong)uVar7);
          goto LAB_14000eb01;
        }
        MmUnmapLockedPages(*puVar9,puVar9[1]);
        *puVar9 = 0;
        if (param_2 != 2) {
          uVar3 = WinHvDeleteEventLogBuffer(param_2,uVar7);
          if ((int)uVar3 < 0) {
            pcVar8 = "Error deleting buffer %d: 0x%x";
            goto LAB_14000eaaf;
          }
        }
        if (puVar9[1] != 0) {
          ExFreePoolWithTag(puVar9[1],0x75426248);
          puVar9[1] = 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)puVar2[2]);
    }
    if (param_2 != 2) {
      uVar3 = WinHvFinalizeEventLogBufferGroup();
      if ((int)uVar3 < 0) {
        HbpTraceFault(0,"HbEvtpDeleteEventLogWorker","Error finalizing event log buffer group: 0x%x"
                      ,(ulonglong)uVar3);
        goto LAB_14000eb01;
      }
    }
    iVar4 = WinHvGetPartitionId();
    if (-1 < iVar4) {
      WinHvWithdrawMemory(local_res20,0xffffffffffffffff,0x80000000,local_48);
    }
  }
LAB_14000eb01:
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[2] = 0;
    *puVar2 = 0;
    if (*(longlong *)(puVar2 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar2 + 8),0x75426248);
      *(undefined8 *)(puVar2 + 8) = 0;
    }
    if (*(longlong *)(puVar2 + 10) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar2 + 10),0x75426248);
      *(undefined8 *)(puVar2 + 10) = 0;
    }
    if (*(longlong *)(puVar2 + 0x22) != 0) {
      ExFreePoolWithTag(*(longlong *)(puVar2 + 0x22),0x75426248);
      *(undefined8 *)(puVar2 + 0x22) = 0;
    }
  }
  if (param_2 == 2) {
    if (DAT_1400073b0 != 0) {
      ExFreePoolWithTag(DAT_1400073b0,0x75426248);
      DAT_1400073b0 = 0;
    }
    if (DAT_1400073b8 != 0) {
      ExFreePoolWithTag(DAT_1400073b8,0x75426248);
      DAT_1400073b8 = 0;
    }
    if (HbEvtpCrashdumpContext != 0) {
      lVar6 = HbEvtpCrashdumpContext;
      if (*(char *)(HbEvtpCrashdumpContext + 0x68) != '\0') {
        KeDeregisterBugCheckReasonCallback(HbEvtpCrashdumpContext + 0x38);
        lVar6 = HbEvtpCrashdumpContext;
        *(undefined1 *)(HbEvtpCrashdumpContext + 0x68) = 0;
      }
      if (*(char *)(lVar6 + 0xa0) != '\0') {
        KeDeregisterBugCheckReasonCallback(lVar6 + 0x70);
        lVar6 = HbEvtpCrashdumpContext;
        *(undefined1 *)(HbEvtpCrashdumpContext + 0xa0) = 0;
      }
      if (*(longlong *)(lVar6 + 8) != 0) {
        MmUnmapLockedPages(*(longlong *)(lVar6 + 8),*(undefined8 *)(lVar6 + 0x10));
      }
      lVar6 = HbEvtpCrashdumpContext;
      if (*(longlong *)(HbEvtpCrashdumpContext + 0x10) != 0) {
        ExFreePoolWithTag(*(longlong *)(HbEvtpCrashdumpContext + 0x10),0x75426248);
        lVar6 = HbEvtpCrashdumpContext;
        *(undefined8 *)(HbEvtpCrashdumpContext + 0x10) = 0;
      }
      if (*(longlong *)(lVar6 + 0xa8) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar6 + 0xa8),0x75426248);
        lVar6 = HbEvtpCrashdumpContext;
        *(undefined8 *)(HbEvtpCrashdumpContext + 0xa8) = 0;
      }
      ExFreePoolWithTag(lVar6,0x75426248);
      HbEvtpCrashdumpContext = 0;
    }
  }
  else if (param_2 == 1) {
    *(undefined8 *)(param_1 + 0x148) = 0xffffffffffffffff;
    *(undefined4 *)(param_1 + 0x150) = 1;
    KeClearEvent();
  }
  if ((bVar1) && (puVar2 != (undefined4 *)0x0)) {
    ExReInitializeRundownProtection();
  }
  if ((int)uVar3 < 0) {
    HbpTraceFault(0,"HbEvtpDeleteEventLogWorker","Routine failed with 0x%x",(ulonglong)uVar3);
    HbEvtpWriteEventLog(&HV_EVENTLOG_ENABLE_ETW_TRACE_FAILED,0,0);
  }
  return;
}



===== HbEvtpFreeEventLogMdl @ 14000ed34 =====

void HbEvtpFreeEventLogMdl(longlong *param_1)

{
  if (DAT_140007048 == '\0') {
    MmFreePagesFromMdl(*param_1);
  }
  if (*param_1 != 0) {
    ExFreePoolWithTag(*param_1,0x75426248);
    *param_1 = 0;
  }
  return;
}



===== HbEvtpGetTlMetadataFromHvBinary @ 14000ed80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HbEvtpGetTlMetadataFromHvBinary(longlong param_1)

{
  char cVar1;
  int iVar2;
  void *_Src;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStack_138 [32];
  longlong *local_118;
  undefined8 local_110;
  longlong local_108;
  short *local_f8;
  longlong local_f0;
  longlong local_e8;
  int local_e0 [2];
  ulonglong local_d8 [8];
  longlong lStack_98;
  uint uStack_94;
  ulonglong local_88 [2];
  ulonglong local_78;
  undefined8 local_48;
  undefined8 uStack_40;
  size_t local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined1 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_138;
  local_d8[1] = 0;
  local_d8[2] = 0;
  memset(local_88,0,0x40);
  local_d8[0] = 0;
  lVar3 = 0;
  local_f0 = 0;
  local_f8 = (short *)0x0;
  local_18 = 0;
  local_d8[7] = 0;
  lStack_98 = (ulonglong)uStack_94 << 0x20;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_d8[6] = 0;
  if (*(longlong *)(param_1 + 0xc0) == 0) {
    iVar2 = -0x3fffff68;
  }
  else {
    local_d8[4] = 0;
    local_d8[5] = 0;
    local_110 = CONCAT44(local_110._4_4_,0x8000000);
    local_d8[3] = 0x30;
    local_d8[6] = 0x200;
    local_118 = (longlong *)CONCAT44(local_118._4_4_,2);
    local_d8[7] = 0;
    lStack_98 = 0;
    local_108 = *(longlong *)(param_1 + 0xc0);
    iVar2 = ZwCreateSection(&local_f0,4,local_d8 + 3);
    if (-1 < iVar2) {
      local_110 = 0;
      local_118 = &local_e8;
      local_e8 = 0;
      iVar2 = ObReferenceObjectByHandle(local_f0,4,0);
      lVar3 = local_e8;
      if ((-1 < iVar2) && (iVar2 = MmMapViewInSystemSpace(local_e8,&local_f8,local_d8), -1 < iVar2))
      {
        local_e0[0] = 0;
        local_e0[1] = 0;
        DAT_1400073b8 = (void *)0x0;
        DAT_1400073c0 = 0;
        cVar1 = ImageValidateAndProcess(local_f8,local_d8[0],local_e0,(undefined4 *)(local_d8 + 1));
        if (cVar1 == '\0') {
          iVar2 = -0x3fffffff;
        }
        else {
          ImageGetInfo((longlong)(local_d8 + 1),local_88);
          uVar4 = 0;
          if (local_78 != 0) {
            do {
              iVar2 = (int)uVar4;
              ImageGetSectionByIndex((longlong)(local_d8 + 1),uVar4,&local_48);
              cVar1 = ImageCompareSectionNames((longlong)&local_48);
              if (cVar1 != '\0') {
                DAT_1400073c0 = local_38;
                _Src = (void *)((uStack_30 & 0xffffffff) + (longlong)local_f8);
                if (_Src != (void *)0x0) {
                  DAT_1400073b8 = (void *)ExAllocatePool2(0x40,local_38,0x75426248);
                  if (DAT_1400073b8 != (void *)0x0) {
                    memmove(DAT_1400073b8,_Src,DAT_1400073c0);
                    iVar2 = 0;
                    DAT_1400073c8 = *(undefined4 *)(local_d8[2] + 8);
                    goto LAB_14000ef6f;
                  }
                  iVar2 = -0x3fffff66;
                  goto LAB_14000ef4a;
                }
                break;
              }
              uVar4 = (ulonglong)(iVar2 + 1);
            } while (uVar4 < local_78);
          }
          iVar2 = -0x3ffffddb;
        }
      }
    }
  }
LAB_14000ef4a:
  if (DAT_1400073b8 != (void *)0x0) {
    ExFreePoolWithTag(DAT_1400073b8,0x75426248);
    DAT_1400073b8 = (void *)0x0;
  }
LAB_14000ef6f:
  if (local_f8 != (short *)0x0) {
    MmUnmapViewInSystemSpace();
  }
  if (lVar3 != 0) {
    ObfDereferenceObject(lVar3);
  }
  if (local_f0 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== HbEvtpGlobalSystemEventsWorkItemRoutine @ 14000f050 =====

void HbEvtpGlobalSystemEventsWorkItemRoutine(longlong param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  bool bVar6;
  char cVar7;
  undefined8 uVar8;
  uint *puVar9;
  uint uVar10;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  bVar3 = false;
  cVar7 = ExAcquireRundownProtection();
  bVar6 = false;
  if (cVar7 != '\0') {
    bVar6 = true;
    bVar4 = true;
    uVar8 = HbEvtpGetLogConfiguration(0,&local_res8);
    lVar5 = local_res8;
    if ((((-1 < (int)uVar8) && (*(longlong *)(local_res8 + 0x20) != 0)) &&
        (HvBootDriverControlGuid_Context != 0)) && (param_2 != 0xffffffff)) {
      do {
        if ((*(uint *)(lVar5 + 8) <= param_2) ||
           (puVar2 = *(uint **)((ulonglong)param_2 * 0x70 + *(longlong *)(lVar5 + 0x20)),
           puVar2 == (uint *)0x0)) break;
        uVar10 = 0;
        puVar9 = puVar2 + 0x12;
        if (puVar2[0xc] != 0) {
          do {
            if ((uint *)((ulonglong)*puVar2 + (longlong)puVar2) <= puVar9) break;
            HbEvtpLogGlobalSystemEvent((longlong)puVar9);
            uVar10 = uVar10 + (ushort)puVar9[1];
            puVar9 = (uint *)((longlong)puVar9 + (ulonglong)(ushort)puVar9[1]);
          } while (uVar10 < puVar2[0xc]);
        }
        WinHvReleaseEventLogBuffer(0,param_2);
        param_2 = puVar2[0xe];
        bVar3 = true;
      } while (param_2 != 0xffffffff);
      if (bVar3) goto LAB_14000f145;
    }
  }
  bVar4 = bVar6;
  WinHvReleaseEventLogBuffer(0,param_2);
LAB_14000f145:
  IoFreeWorkItem(param_3);
  if (bVar4) {
    ExReleaseRundownProtection(&DAT_140007208);
  }
  IoReleaseRemoveLockEx(lVar1 + 0x40,lVar1,0x20);
  return;
}



===== HbEvtpInitEventLog @ 14000f1ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpInitEventLog(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  undefined1 auStack_58 [32];
  int local_38 [6];
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = 0;
  uStack_18 = 0;
  HviGetEnlightenmentInformation(&local_20);
  puVar3 = (undefined4 *)&DAT_140007238;
  DAT_140007048 = ~((byte)((ulonglong)local_20 >> 0x18) >> 2) & 1;
  uVar2 = 0;
  do {
    if ((HbpIsCpuManagementPartition != '\0') || ((int)uVar2 == 2)) {
      ExInitializeRundownProtection(&DAT_140007208 + uVar2 * 0x90);
      *(undefined8 *)(puVar3 + -2) = 0;
      *puVar3 = 0;
      param_3 = 0;
      puVar3[-4] = 1;
      param_2 = 1;
      KeInitializeEvent(puVar3 + 2);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulonglong)uVar1;
    puVar3 = puVar3 + 0x24;
  } while (uVar1 < 3);
  if (HbpIsCpuManagementPartition != '\0') {
    McGenEventRegister_EtwRegister();
    HbEvtpRegisterLocalDiagnosticsEtwProvider(param_1);
    HbEvtpLogProcessorFeatures('\0',param_2,param_3,param_4);
    HbEvtpLogSecFwStatus();
    HbEvtpLogHwWatchdogBootStatus();
    HbEvtpTraceMinrootConfig();
    local_38[4] = 0;
    local_38[2] = 3;
    local_38[0] = 4;
    local_38[1] = 0x4000;
    local_38[3] = 1;
    uVar1 = HbEvtpCreateEventLog(param_1,0,0,local_38);
    if ((int)uVar1 < 0) {
      HbEvtpWriteEventLog(&HV_EVENTLOG_CREATE_GLOBAL_FAILED,0,0);
    }
    else {
      DAT_14000704a = '\x01';
      WinHvSetEventLogGroupSources(0,0xffffffffffffffff);
    }
  }
  HbEvtpInitializeSystemDiagLog(param_1);
  if ((DAT_140007049 != '\0') || (DAT_14000704a != '\0')) {
    KeInitializeDpc(&HbEvtpPeriodicTimerDpc,HbEvtpTracePeriodicTimerDpcRoutine,param_1);
    KeSetTimerEx(param_1 + 0x60,0x3dc5400,30000,&HbEvtpPeriodicTimerDpc);
  }
  return;
}



===== HbEvtpInitializeSystemDiagLog @ 14000f374 =====

ulonglong HbEvtpInitializeSystemDiagLog(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  void *_Dst;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong *plVar15;
  bool bVar16;
  undefined8 local_res10;
  int *local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = (int *)0x0;
  cVar4 = ExAcquireRundownProtection(&DAT_140007328);
  if (cVar4 == '\0') {
    return 0xc00000a3;
  }
  uVar6 = HbEvtpGetLogConfiguration(2,local_res18);
  piVar3 = local_res18[0];
  uVar9 = uVar6 & 0xffffffff;
  if (-1 < (int)uVar6) {
    if (local_res18[0][2] == 0) {
      uVar5 = WinHvGetPartitionProperty(0xffffffffffffffff,0x50026,&local_res10);
      uVar9 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        if ((uint)local_res10 == 0) {
LAB_14000f413:
          uVar9 = 0;
          goto LAB_14000f9f9;
        }
        if ((0x280 < (uint)local_res10) || (0x1ff < local_res10._4_4_ - 1)) goto LAB_14000f909;
        DAT_1400073b0 = ExAllocatePool2(0x102,local_res10._4_4_ << 0xc,0x75426248);
        if (DAT_1400073b0 != 0) {
          lVar7 = ExAllocatePool2(0x100,(local_res10 & 0xffffffff) * 0x70,0x75426248);
          *(longlong *)(piVar3 + 8) = lVar7;
          if (lVar7 != 0) {
            lVar7 = ExAllocatePool2(0x40,(local_res10 & 0xffffffff) << 3,0x75426248);
            *(longlong *)(piVar3 + 10) = lVar7;
            if (lVar7 != 0) {
              uVar10 = 0;
              uVar5 = 0;
              if ((int)local_res10 != 0) {
                do {
                  ExInitializeRundownProtection(*(longlong *)(piVar3 + 10) + (ulonglong)uVar10 * 8);
                  lVar7 = (ulonglong)uVar10 * 0x70;
                  *(undefined4 *)(lVar7 + 0x50 + *(longlong *)(piVar3 + 8)) = 2;
                  *(uint *)(lVar7 + 0x54 + *(longlong *)(piVar3 + 8)) = uVar10;
                  uVar10 = uVar10 + 1;
                  uVar5 = (uint)local_res10;
                } while (uVar10 < uVar5);
              }
              if (HbpIsCpuManagementPartition != '\0') {
                plVar15 = (longlong *)ExAllocatePool2(0x40,0xb0,0x75426248);
                HbEvtpCrashdumpContext = plVar15;
                if (plVar15 != (longlong *)0x0) {
                  memset(plVar15,0,0xb0);
                  plVar15[3] = (ulonglong)local_res10._4_4_;
                  plVar15[4] = (ulonglong)(local_res10._4_4_ << 0xc);
                }
                uVar5 = (uint)local_res10;
              }
              uVar11 = 0;
              uVar10 = 0;
              if (uVar5 != 0) {
                do {
                  uVar5 = HbEvtpMapSystemDiagLogBuffer
                                    ((longlong *)
                                     ((ulonglong)uVar11 * 0x70 + *(longlong *)(piVar3 + 8)),
                                     local_res10._4_4_);
                  plVar15 = HbEvtpCrashdumpContext;
                  uVar9 = (ulonglong)uVar5;
                  if ((int)uVar5 < 0) goto LAB_14000f90e;
                  if (HbEvtpCrashdumpContext != (longlong *)0x0) {
                    plVar1 = HbEvtpCrashdumpContext + 6;
                    plVar2 = HbEvtpCrashdumpContext + 4;
                    HbEvtpCrashdumpContext[5] =
                         HbEvtpCrashdumpContext[3] + HbEvtpCrashdumpContext[5];
                    plVar15[6] = *plVar2 + *plVar1;
                  }
                  uVar11 = uVar11 + 1;
                  uVar10 = (uint)local_res10;
                } while (uVar11 < uVar10);
              }
              DAT_1400073ac = 0xffffffff;
              piVar3[2] = uVar10;
              *piVar3 = local_res10._4_4_;
              bVar16 = HbpIsCpuManagementPartition != '\0';
              piVar3[1] = local_res10._4_4_ << 0xc;
              piVar3[3] = 0;
              piVar3[4] = 2;
              piVar3[0xc] = 1;
              DAT_1400073a0 = 0;
              DAT_1400073a8 = 0;
              if (bVar16) {
                uVar5 = HbEvtpGetTlMetadataFromHvBinary(param_1);
                uVar9 = (ulonglong)uVar5;
                if ((int)uVar5 < 0) goto LAB_14000f90e;
              }
              DAT_140007049 = 1;
              TraceLoggingRegisterEx_EtwRegister_EtwSetInformation
                        (0x140007050,HbEvtpSystemDiagLogTraceLoggingCallback,param_1);
              if (HbEvtpCrashdumpContext != (longlong *)0x0) {
                puVar8 = (undefined8 *)
                         ExAllocatePool2(0x40,(HbEvtpCrashdumpContext[5] + 3) * 0x10,0x75426248);
                plVar15 = HbEvtpCrashdumpContext;
                HbEvtpCrashdumpContext[2] = (longlong)puVar8;
                if (puVar8 != (undefined8 *)0x0) {
                  lVar7 = plVar15[6];
                  lVar14 = 0;
                  *puVar8 = 0;
                  *(int *)(puVar8 + 5) = (int)(lVar7 * 2);
                  *(undefined2 *)((longlong)puVar8 + 10) = 0;
                  puVar8[4] = 0;
                  *(undefined4 *)((longlong)puVar8 + 0x2c) = 0;
                  *(short *)(puVar8 + 1) = ((short)(lVar7 * 2 + 0xfffU >> 0xc) + 6) * 8;
                  *(ushort *)(plVar15[2] + 10) = *(ushort *)(plVar15[2] + 10) | 0x2002;
                  uVar6 = 2;
                  do {
                    uVar9 = uVar6;
                    uVar5 = 0;
                    if ((uint)local_res10 != 0) {
                      do {
                        uVar6 = 0;
                        lVar7 = *(longlong *)(piVar3 + 8);
                        if (local_res10._4_4_ != 0) {
                          lVar12 = lVar14 * 8 + 0x30;
                          lVar13 = 0x30;
                          do {
                            lVar14 = lVar14 + 1;
                            uVar6 = uVar6 + 1;
                            puVar8 = (undefined8 *)
                                     (lVar13 + *(longlong *)((ulonglong)uVar5 * 0x70 + lVar7 + 8));
                            lVar13 = lVar13 + 8;
                            *(undefined8 *)(lVar12 + plVar15[2]) = *puVar8;
                            lVar12 = lVar12 + 8;
                          } while (uVar6 < local_res10._4_4_);
                        }
                        uVar5 = uVar5 + 1;
                      } while (uVar5 < (uint)local_res10);
                    }
                    uVar6 = uVar9 - 1;
                  } while (uVar6 != 0);
                  lVar7 = MmMapLockedPagesSpecifyCache
                                    (plVar15[2],0,uVar9 & 0xffffffff,0,0,0x40000020);
                  plVar15 = HbEvtpCrashdumpContext;
                  HbEvtpCrashdumpContext[1] = lVar7;
                  if (lVar7 != 0) {
                    *plVar15 = lVar7 + plVar15[6];
                    *(undefined1 *)((longlong)plVar15 + 100) = 0;
                    cVar4 = KeRegisterBugCheckReasonCallback
                                      (plVar15 + 7,HbEvtpSystemDiagLogCrashdumpCallback,2,
                                       "HbEvtpSystemDiagLogCrashdump");
                    if (cVar4 != '\0') {
                      *(undefined1 *)(HbEvtpCrashdumpContext + 0xd) = 1;
                      _Dst = (void *)ExAllocatePool2(0x40,0x60,0x75426248);
                      plVar15 = HbEvtpCrashdumpContext;
                      HbEvtpCrashdumpContext[0x15] = (longlong)_Dst;
                      if (_Dst != (void *)0x0) {
                        memset(_Dst,0,0x60);
                        uVar5 = KeInitializeTriageDumpDataArray(plVar15[0x15],0x60);
                        plVar15 = HbEvtpCrashdumpContext;
                        uVar9 = (ulonglong)uVar5;
                        if (-1 < (int)uVar5) {
                          *(undefined1 *)((longlong)HbEvtpCrashdumpContext + 0x9c) = 0;
                          cVar4 = KeRegisterBugCheckReasonCallback
                                            (plVar15 + 0xe,HbEvtpTriageDumpDataCrashdumpCallback,7,
                                             "HbEvtpTriageDumpDataCrashdump");
                          if (cVar4 != '\0') {
                            *(undefined1 *)(HbEvtpCrashdumpContext + 0x14) = 1;
                            goto LAB_14000f9f9;
                          }
                        }
                      }
                    }
                  }
                }
                uVar9 = 0;
                if (HbEvtpCrashdumpContext != (longlong *)0x0) {
                  plVar15 = HbEvtpCrashdumpContext;
                  if ((char)HbEvtpCrashdumpContext[0xd] != '\0') {
                    KeDeregisterBugCheckReasonCallback(HbEvtpCrashdumpContext + 7);
                    plVar15 = HbEvtpCrashdumpContext;
                    *(undefined1 *)(HbEvtpCrashdumpContext + 0xd) = 0;
                  }
                  if ((char)plVar15[0x14] != '\0') {
                    KeDeregisterBugCheckReasonCallback(plVar15 + 0xe);
                    plVar15 = HbEvtpCrashdumpContext;
                    *(undefined1 *)(HbEvtpCrashdumpContext + 0x14) = 0;
                  }
                  if (plVar15[1] != 0) {
                    MmUnmapLockedPages(plVar15[1],plVar15[2]);
                  }
                  plVar15 = HbEvtpCrashdumpContext;
                  if (HbEvtpCrashdumpContext[2] != 0) {
                    ExFreePoolWithTag(HbEvtpCrashdumpContext[2],0x75426248);
                    plVar15 = HbEvtpCrashdumpContext;
                    HbEvtpCrashdumpContext[2] = 0;
                  }
                  if (plVar15[0x15] != 0) {
                    ExFreePoolWithTag(plVar15[0x15],0x75426248);
                    plVar15 = HbEvtpCrashdumpContext;
                    HbEvtpCrashdumpContext[0x15] = 0;
                  }
                  ExFreePoolWithTag(plVar15,0x75426248);
                  HbEvtpCrashdumpContext = (longlong *)0x0;
                }
                goto LAB_14000f9f9;
              }
              goto LAB_14000f413;
            }
          }
        }
        uVar9 = 0xc000009a;
      }
    }
    else {
LAB_14000f909:
      uVar9 = 0xc000000d;
    }
  }
LAB_14000f90e:
  if (HbEvtpCrashdumpContext != (longlong *)0x0) {
    ExFreePoolWithTag(HbEvtpCrashdumpContext,0x75426248);
    HbEvtpCrashdumpContext = (longlong *)0x0;
  }
  if ((piVar3 != (int *)0x0) && (*(longlong *)(piVar3 + 8) != 0)) {
    uVar5 = 0;
    if ((uint)local_res10 != 0) {
      do {
        plVar15 = (longlong *)((ulonglong)uVar5 * 0x70 + *(longlong *)(piVar3 + 8));
        if (*plVar15 == 0) break;
        MmUnmapLockedPages(*plVar15,plVar15[1]);
        WinHvUnmapEventLogBuffer(2,uVar5);
        if (HbpIsCpuManagementPartition == '\0') {
          MmFreePagesFromMdl(plVar15[1]);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_res10);
    }
    if (*(longlong *)(piVar3 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(piVar3 + 8),0x75426248);
      piVar3[8] = 0;
      piVar3[9] = 0;
    }
    piVar3[2] = 0;
  }
  if (DAT_1400073b0 != 0) {
    ExFreePoolWithTag(DAT_1400073b0,0x75426248);
    DAT_1400073b0 = 0;
  }
  if (*(longlong *)(piVar3 + 10) != 0) {
    ExFreePoolWithTag(*(longlong *)(piVar3 + 10),0x75426248);
    piVar3[10] = 0;
    piVar3[0xb] = 0;
  }
LAB_14000f9f9:
  ExReleaseRundownProtection(&DAT_140007328);
  return uVar9;
}



===== HbEvtpLocalDiagWriteBufferList @ 14000fa2c =====

int HbEvtpLocalDiagWriteBufferList(longlong param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  ulonglong uVar6;
  
  iVar4 = 0;
  uVar6 = (ulonglong)param_3;
  if (*(longlong *)(param_1 + 0x148) - 1U < 0xfffffffffffffffe) {
    if ((HbEvtpLocalDiagnosticsDisableSession == '\0') || (*(int *)(param_2 + 0x30) != 1)) {
      while( true ) {
        param_3 = (uint)uVar6;
        if (param_3 == 0xffffffff) {
          return iVar4;
        }
        cVar3 = ExAcquireRundownProtection(*(longlong *)(param_2 + 0x28) + uVar6 * 8);
        if (cVar3 == '\0') break;
        plVar5 = (longlong *)(uVar6 * 0x70 + *(longlong *)(param_2 + 0x20));
        lVar2 = *plVar5;
        uVar1 = *(uint *)(lVar2 + 0x38);
        if ((*(int *)(param_2 + 0x30) == 1) ||
           (*(uint *)(lVar2 + 0x3c) <=
            *(int *)(*(longlong *)(param_2 + 0x88) + (ulonglong)*(ushort *)(lVar2 + 0x28) * 4) + 1U)
           ) {
          *(undefined4 *)(*(longlong *)(param_2 + 0x88) + (ulonglong)*(ushort *)(lVar2 + 0x28) * 4)
               = *(undefined4 *)(lVar2 + 0x3c);
          iVar4 = HbEvtpLocalDiagWriteBuffer(param_1,param_2,plVar5);
          if (iVar4 < 0) break;
        }
        else {
          *(undefined4 *)(lVar2 + 0x38) = 0xffffffff;
          HbEvtpLocalDiagInsertOutOfOrderBufferInList(param_2,plVar5);
          ExReleaseRundownProtection(*(longlong *)(param_2 + 0x28) + uVar6 * 8);
        }
        uVar6 = (ulonglong)uVar1;
      }
      goto LAB_14000fb2e;
    }
  }
  else {
    HbpTraceFault(0,"HbEvtpLocalDiagWriteBufferList","Invalid cached logger ID (0x%x)",
                  *(longlong *)(param_1 + 0x148));
  }
  if (param_3 == 0xffffffff) {
    return 0;
  }
LAB_14000fb2e:
  HbEvtpLocalDiagReleaseBufferList(param_2,param_3);
  return iVar4;
}



===== HbEvtpLocalDiagnosticsBufferCompletedCallback @ 14000fb60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HbEvtpLocalDiagnosticsBufferCompletedCallback
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)((ulonglong)param_3 * 0x70 + _DAT_1400072a0);
  *(undefined4 *)(*plVar1 + 0x2c) = 4;
  WinHvReleaseEventLogBuffer(1,param_3);
  *(undefined4 *)(plVar1 + 0xb) = 0;
  ExReleaseRundownProtection(DAT_1400072a8 + (ulonglong)param_3 * 8);
  return;
}



===== HbEvtpLocalDiagnosticsEtwCallback @ 14000fbd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpLocalDiagnosticsEtwCallback
               (undefined8 param_1,char param_2,ushort *param_3,longlong param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined1 auStack_a8 [32];
  ushort *local_88;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_78 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_88 = param_3;
  iVar3 = WmiQueryTraceInformation(9);
  iVar7 = 0;
  if ((-1 < iVar3) && (iVar7 = 0, (local_58 & 0x400) != 0)) {
    iVar7 = 1;
  }
  local_88 = (ushort *)0x0;
  uVar9 = 0;
  KeWaitForSingleObject(param_4 + 0xd0);
  ExAcquireFastMutex(&DAT_1400072b8);
  cVar2 = ExAcquireRundownProtection();
  if (cVar2 == '\0') goto LAB_14000fe62;
  bVar1 = true;
  if (param_2 == '\x01') {
    if (*(int *)(param_4 + 0x150) == 1) {
      HbEvtpLocalDiagnosticsDisableSession = 0;
      uVar4 = HbEvtpCreateLocalDiagnosticsEventLog(param_4,param_3,iVar7,uVar9);
      if ((int)uVar4 < 0) {
        if (uVar4 == 0xc0000056) goto LAB_14000fe39;
        pcVar8 = "Failed to create local diagnostics log with code 0x%x";
        uVar6 = 0;
      }
      else {
        *(undefined4 *)(param_4 + 0x150) = 2;
LAB_14000fd0b:
        *(ulonglong *)(param_4 + 0x148) = (ulonglong)*param_3;
        uVar4 = HbEvtpSetLocalDiagnosticsEventSources((longlong)param_3);
        if (-1 < (int)uVar4) goto LAB_14000fe4f;
        pcVar8 = "Error 0x%x updating event sources";
        uVar6 = 1;
      }
      HbpTraceFault(uVar6,"HbEvtpLocalDiagnosticsEtwCallback",pcVar8,(ulonglong)uVar4);
    }
    else if (*(int *)(param_4 + 0x150) == 2) goto LAB_14000fd0b;
LAB_14000fe39:
    HbEvtpWriteEventLog(&HV_EVENTLOG_ENABLE_ETW_TRACE_FAILED,0,0);
    if (!bVar1) goto LAB_14000fe62;
  }
  else if (param_2 == '\x02') {
    uVar4 = *(uint *)(param_4 + 0x150);
    if (uVar4 == 2) {
      uVar5 = HbpEvtpFlushEventLog(1);
      iVar3 = (int)uVar5;
      if (iVar3 < 0) goto LAB_14000fe39;
      if (iVar7 == 1) {
        local_88 = (ushort *)&local_70;
        *(undefined4 *)(param_4 + 0x150) = 3;
        local_70 = 0xffffffffee1e5d00;
        KeWaitForSingleObject(&HbEvtpCompleteBufferAsyncEvent,0,0,0);
        *(undefined4 *)(param_4 + 0x150) = 2;
      }
    }
    else {
      if (uVar4 == 1) goto LAB_14000fe4f;
      HbpTraceFault(0,"HbEvtpLocalDiagnosticsEtwCallback","Invalid state for CAPTURE_STATE: %d",
                    (ulonglong)uVar4);
      iVar3 = -0x3ffffe7c;
    }
    if (iVar3 < 0) goto LAB_14000fe39;
  }
  else if (param_2 == '\0') {
    uVar4 = *(uint *)(param_4 + 0x150);
    if (uVar4 == 2) {
      ExReleaseRundownProtection(&DAT_140007298);
      *(undefined4 *)(param_4 + 0x150) = 1;
      bVar1 = false;
      uVar4 = HbEvtpDeleteEventLog(param_4,1);
      if (-1 < (int)uVar4) goto LAB_14000fe62;
      uVar4 = *(uint *)(param_4 + 0x150);
      pcVar8 = "Invalid state for CAPTURE_STATE: %d";
    }
    else {
      if (uVar4 == 1) goto LAB_14000fe4f;
      pcVar8 = "Invalid state for DISABLE_PROVIDER: %d";
    }
    HbpTraceFault(0,"HbEvtpLocalDiagnosticsEtwCallback",pcVar8,(ulonglong)uVar4);
    goto LAB_14000fe39;
  }
LAB_14000fe4f:
  ExReleaseRundownProtection(&DAT_140007298);
LAB_14000fe62:
  KeReleaseMutex(param_4 + 0xd0,0);
  ExReleaseFastMutex(&DAT_1400072b8);
  return;
}



===== HbEvtpLogGlobalSystemEvent @ 14000feac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpLogGlobalSystemEvent(longlong param_1)

{
  short sVar1;
  undefined *puVar2;
  undefined1 auStackY_88 [32];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = (undefined4 *)(param_1 + 0x10);
  sVar1 = *(short *)(param_1 + 6);
  if (sVar1 == 0x2103) {
    puVar2 = &HV_EVENTLOG_PARTITION_CREATION_FAILED;
  }
  else {
    if (sVar1 == 0x3106) {
      HbpLogHypervisorMsrEvent
                (*local_58,*(undefined1 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),
                 *(ushort *)(param_1 + 0x28),*(longlong *)(param_1 + 0x30));
      return;
    }
    if (sVar1 == 0x4101) {
      puVar2 = &HV_EVENTLOG_PARTITION_CREATED;
    }
    else {
      if (sVar1 != 0x4102) {
        return;
      }
      puVar2 = &HV_EVENTLOG_PARTITION_DELETED;
    }
  }
  if ((int)((ulonglong)*(ushort *)(param_1 + 4) - 0x10 >> 3) == 1) {
    local_4c = 0;
    local_50 = 8;
    HbEvtpWriteEventLog(puVar2,1,&local_58);
  }
  return;
}



===== HbEvtpLogHwWatchdogBootStatus @ 14000ff74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpLogHwWatchdogBootStatus(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined1 auStackY_88 [32];
  undefined4 local_58 [2];
  longlong local_50 [6];
  longlong *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  plVar6 = local_50;
  local_50[0] = 0;
  puVar4 = local_58;
  uVar5 = 4;
  local_58[0] = 0x13;
  uVar3 = 3;
  iVar2 = WinHvGetSystemInformation();
  if ((-1 < iVar2) && (local_50[0] != 0)) {
    if ((Microsoft_Windows_Hyper_V_HypervisorEnableBits & 4) != 0) {
      McTemplateK0_EtwWriteTransfer(uVar3,puVar4,uVar5);
    }
    if (5 < DAT_140007088) {
      cVar1 = _tlgKeywordOn(0x140007088,0x400000000000);
      if (cVar1 != '\0') {
        local_14 = 0;
        local_20 = local_50 + 1;
        local_50[1] = 0x1000000;
        local_18 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(0x140007088,&DAT_140005dcb,uVar5,plVar6,3,local_50 + 2);
      }
    }
  }
  return;
}



===== HbEvtpLogProcessorFeatures @ 140010064 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpLogProcessorFeatures
               (char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  byte bVar4;
  longlong *plVar5;
  undefined1 auStackY_78 [32];
  longlong local_38 [6];
  
  local_38[5] = __security_cookie ^ (ulonglong)auStackY_78;
  local_38[0] = 0;
  local_38[2] = 0;
  local_38[1] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  for (bVar4 = 0; bVar4 < 2; bVar4 = bVar4 + 1) {
    iVar1 = WinHvGetPartitionProperty(0xffffffffffffffff,bVar4 + 0x6000a,local_38 + 2);
    if (iVar1 < 0) {
      return;
    }
    local_38[(ulonglong)bVar4 + 3] = local_38[2];
  }
  iVar1 = WinHvGetPartitionProperty(0xffffffffffffffff,0x60003,local_38);
  if (-1 < iVar1) {
    plVar5 = local_38 + 1;
    local_38[0] = local_38[0] << 3;
    uVar2 = 0xffffffffffffffff;
    iVar1 = WinHvGetPartitionProperty(0xffffffffffffffff,0x60002);
    if (-1 < iVar1) {
      if (param_1 == '\0') {
        if ((Microsoft_Windows_Hyper_V_HypervisorEnableBits & 0x40) == 0) {
          return;
        }
        puVar3 = &HV_EVENTLOG_HOST_PROCESSOR_FEATURES_V1;
      }
      else {
        if ((DAT_140007459 & 2) == 0) {
          return;
        }
        puVar3 = &HV_EVENTLOG_RUNTIME_HOST_PROCESSOR_FEATURES_V1;
      }
      McTemplateK0uIR0iq_EtwWriteTransfer
                (uVar2,puVar3,plVar5,param_4,local_38 + 3,(char)local_38[1],(char)local_38[0]);
    }
  }
  return;
}



===== HbEvtpLogSecFwStatus @ 140010190 =====

void HbEvtpLogSecFwStatus(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  
  local_res8[0] = 0xf;
  puVar5 = local_res8;
  local_res10 = 0;
  uVar4 = 4;
  uVar3 = 3;
  iVar1 = WinHvGetSystemInformation();
  if ((-1 < iVar1) && (iVar1 = (int)local_res10, iVar1 != 0)) {
    if ((Microsoft_Windows_Hyper_V_HypervisorEnableBits & 0x10) != 0) {
      McTemplateK0q_EtwWriteTransfer(uVar3,puVar5,uVar4,iVar1);
    }
    uVar6 = 4;
    local_res8[0] = 0xe;
    puVar5 = local_res8;
    uVar4 = 3;
    iVar2 = WinHvGetSystemInformation();
    uVar3 = local_res10;
    if (-1 < iVar2) {
      if ((Microsoft_Windows_Hyper_V_HypervisorEnableBits & 0x10) != 0) {
        McTemplateK0x_EtwWriteTransfer(uVar4,puVar5,uVar6,local_res10);
      }
      HbEvtpSecFwUpdateRegistry(iVar1,uVar3);
    }
  }
  return;
}



===== HbEvtpMapSystemDiagLogBuffer @ 140010258 =====

uint HbEvtpMapSystemDiagLogBuffer(longlong *param_1,uint param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_res8;
  undefined8 *in_stack_ffffffffffffffe8;
  
  local_res8 = 0;
  plVar1 = param_1 + 1;
  uVar2 = HbEvtpAllocateAndInitializeEventLogMdl(param_2,plVar1);
  if ((int)uVar2 < 0) {
    HbpTraceFault(0,"HbEvtpMapSystemDiagLogBuffer",
                  "0x%x - HbEvtpAllocateAndInitializeEventLogMdl failed",(ulonglong)uVar2);
    return uVar2;
  }
  if (DAT_140007048 == '\0') {
    if (0x1fe < param_2) {
      uVar2 = 0xc000000d;
      goto LAB_140010392;
    }
    in_stack_ffffffffffffffe8 = &local_res8;
    uVar2 = WinHvMapPartitionEventLogBuffer
                      (2,*(undefined4 *)((longlong)param_1 + 0x54),param_2,*plVar1 + 0x30,
                       in_stack_ffffffffffffffe8);
    if (-1 < (int)uVar2) goto LAB_140010337;
    pcVar4 = "0x%x - WinHvMapPartitionEventLogBuffer failed";
  }
  else {
    uVar2 = WinHvMapEventLogBuffer(2,*(undefined4 *)((longlong)param_1 + 0x54),*plVar1 + 0x30);
    if (-1 < (int)uVar2) {
LAB_140010337:
      uVar5 = 0;
      lVar3 = MmMapLockedPagesSpecifyCache
                        (*plVar1,0,1,0,(ulonglong)in_stack_ffffffffffffffe8 & 0xffffffff00000000,
                         0x40000020);
      *param_1 = lVar3;
      if (lVar3 != 0) {
        return uVar2;
      }
      HbpTraceFault(0,"HbEvtpMapSystemDiagLogBuffer","MmMapLockedPagesSpecifyCache failed",uVar5);
      uVar2 = 0xc000009a;
      WinHvUnmapEventLogBuffer(2,*(undefined4 *)((longlong)param_1 + 0x54));
      goto LAB_140010392;
    }
    pcVar4 = "0x%x - WinHvMapEventLogBuffer failed";
  }
  HbpTraceFault(0,"HbEvtpMapSystemDiagLogBuffer",pcVar4,(ulonglong)uVar2);
LAB_140010392:
  HbEvtpFreeEventLogMdl(plVar1);
  return uVar2;
}



===== HbEvtpProcessSystemDiagLogEntry @ 1400103b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbEvtpProcessSystemDiagLogEntry(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  ushort uVar1;
  undefined1 auVar2 [16];
  byte *pbVar3;
  uint uVar4;
  undefined1 auStackY_d8 [32];
  uint *local_a8;
  undefined1 local_a0 [16];
  uint *local_90;
  uint local_88;
  undefined4 local_84;
  uint *local_80;
  undefined8 local_78;
  uint *local_70;
  uint local_68;
  undefined4 local_64;
  undefined8 local_58 [4];
  char *local_38;
  undefined8 local_30;
  uint **local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a0 = ZEXT816(0);
  if (0xf < (ushort)DAT_1400073b0[1] - 0x10) {
    local_a0 = *(undefined1 (*) [16])(DAT_1400073b0 + 4);
    local_68 = (ushort)DAT_1400073b0[1] - 0x20;
    local_70 = DAT_1400073b0 + 8;
    uVar4 = (uint)local_a0[2] << 0x10 | local_a0._0_4_ & 0xffff;
    param_3 = (uint *)(ulonglong)uVar4;
    local_88 = *DAT_1400073b0;
    if (uVar4 == 0xffffff) {
      if (local_88 <= local_68) {
        local_68 = local_68 - local_88;
        param_3 = local_70;
        local_70 = (uint *)((longlong)local_70 + (ulonglong)local_88);
LAB_1400104b2:
        local_80 = DAT_1400073b0 + 2;
        local_84 = 1;
        auVar2._13_3_ = 0;
        auVar2._0_13_ = local_a0._3_13_;
        local_a0 = auVar2 << 0x18;
        local_78 = 0x300000008;
        local_64 = 0;
        local_90 = param_3;
        EtwWrite(DAT_140007070,local_a0,0,3);
        return;
      }
    }
    else {
      if (local_88 != DAT_1400073c8) {
        if (DAT_140007050 < 6) {
          return;
        }
        local_30 = 0x1d;
        local_38 = "Event with invalid timestamp";
        pbVar3 = &DAT_140005e86;
        local_a8 = (uint *)CONCAT44(local_a8._4_4_,local_88);
        local_20 = 4;
        goto LAB_140010545;
      }
      if (uVar4 + 4 <= DAT_1400073c0) {
        param_3 = (uint *)(DAT_1400073b8 + (ulonglong)uVar4);
        uVar1 = (ushort)*param_3;
        local_88 = (uint)uVar1;
        if ((3 < uVar1) && ((ulonglong)uVar4 + (ulonglong)uVar1 <= DAT_1400073c0))
        goto LAB_1400104b2;
      }
    }
  }
  if (DAT_140007050 < 6) {
    return;
  }
  local_30 = 0xe;
  local_38 = "Invalid event";
  pbVar3 = &DAT_140005d93;
  local_a8 = DAT_1400073b0;
  local_20 = 8;
LAB_140010545:
  local_28 = &local_a8;
  _tlgWriteTransfer_EtwWriteTransfer(0x140007050,pbVar3,param_3,DAT_1400073b0,4,local_58);
  return;
}



===== HbEvtpRegisterLocalDiagnosticsEtwProvider @ 14001058c =====

void HbEvtpRegisterLocalDiagnosticsEtwProvider(undefined8 param_1)

{
  KeInitializeEvent(&HbEvtpCompleteBufferAsyncEvent,1);
  EtwRegisterClassicProvider
            (&HbEvtpLocalDiagnosticsEventsGuid,0,HbEvtpLocalDiagnosticsEtwCallback,param_1,
             &HbEvtpLocalDiagnosticsEventsHandle);
  EtwSetInformation(HvBootDriverControlGuid_Context,2,
                    &`EnableManifestedProviderForMicrosoftTelemetry'::__l2::Traits,0x16);
  return;
}



===== HbEvtpSecFwUpdateRegistry @ 140010610 =====

int HbEvtpSecFwUpdateRegistry(undefined4 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res10;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined8 local_48;
  undefined8 local_40;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res20 = 0;
  local_2c = 0;
  local_res18[0] = 0;
  local_40 = 0;
  local_48 = 0x30;
  local_38 = &DAT_1400070e0;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0x240;
  local_res10 = param_2;
  iVar1 = ZwCreateKey(&local_res20,0xf003f,&local_48,0,0,0,0);
  if (-1 < iVar1) {
    local_res18[0] = param_1;
    iVar1 = ZwSetValueKey(local_res20,&DAT_140007100,0,4,local_res18,4);
    if (-1 < iVar1) {
      iVar1 = ZwSetValueKey(local_res20,&DAT_1400070f0,0,0xb,&local_res10,8);
    }
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== HbEvtpSetLocalDiagnosticsEventSources @ 14001071c =====

int HbEvtpSetLocalDiagnosticsEventSources(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined4 local_res8 [2];
  longlong local_res10 [2];
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar11;
  undefined8 uVar10;
  undefined4 *puVar12;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  lVar9 = 0;
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = *(undefined8 *)(param_1 + 4);
  lVar5 = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  uVar7 = 0;
  uVar8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (undefined *)0x0;
  uStack_50 = 0;
  if (((uVar1 & 1) == 0) || (((byte)uVar1 & 0xfe) != 6)) {
    iVar3 = WinHvSetEventLogGroupSources(1,uVar2);
    goto LAB_140010955;
  }
  uStack_60 = 0;
  local_58 = &DAT_1400070d0;
  local_68 = 0x30;
  uStack_50 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  iVar3 = ZwOpenKey(local_res10,0x20019,&local_68);
  if (iVar3 < 0) goto LAB_140010955;
  lVar4 = ExAllocatePool2(0x102,0x110,0x75426248);
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
    goto LAB_140010955;
  }
  uVar10 = CONCAT44(uVar11,0x110);
  iVar3 = ZwQueryValueKey(local_res10[0],&DAT_140007110,2,lVar4,uVar10,local_res8);
  uVar11 = (undefined4)((ulonglong)uVar10 >> 0x20);
  if (iVar3 < 0) {
    ExFreePoolWithTag(lVar4,0x75426248);
    lVar4 = 0;
    lVar6 = 0;
LAB_140010857:
    lVar5 = ExAllocatePool2(0x102,0x110,0x75426248);
    if (lVar5 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      puVar12 = local_res8;
      iVar3 = ZwQueryValueKey(local_res10[0],&DAT_1400070c0,2,lVar5,CONCAT44(uVar11,0x110),puVar12);
      uVar11 = (undefined4)((ulonglong)puVar12 >> 0x20);
      if (iVar3 < 0) {
        ExFreePoolWithTag(lVar5,0x75426248);
        lVar5 = 0;
      }
      else {
        if (*(int *)(lVar5 + 4) != 3) {
          iVar3 = -0x3fffffdc;
          goto LAB_14001090b;
        }
        uVar7 = *(undefined4 *)(lVar5 + 8);
        lVar9 = lVar5 + 0xc;
      }
      iVar3 = WinHvSetEventLogGranularSources(1,uVar2,lVar6,uVar8,lVar9,CONCAT44(uVar11,uVar7));
    }
LAB_14001090b:
    if (lVar4 != 0) goto LAB_140010910;
  }
  else {
    if (*(int *)(lVar4 + 4) == 3) {
      uVar8 = *(undefined4 *)(lVar4 + 8);
      lVar6 = lVar4 + 0xc;
      goto LAB_140010857;
    }
    iVar3 = -0x3fffffdc;
LAB_140010910:
    ExFreePoolWithTag(lVar4,0x75426248);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0x75426248);
  }
LAB_140010955:
  if (local_res10[0] != 0) {
    ZwClose();
  }
  return iVar3;
}



===== HbEvtpSystemDiagLogTraceLoggingCallback @ 140010990 =====

void HbEvtpSystemDiagLogTraceLoggingCallback(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined8 *puVar2;
  char *pcVar3;
  ulonglong uVar4;
  undefined8 *in_stack_00000038;
  
  pcVar3 = "";
  uVar4 = 1;
  puVar2 = in_stack_00000038;
  iVar1 = IoAcquireRemoveLockEx(in_stack_00000038 + 8);
  if (-1 < iVar1) {
    if (param_2 == 1) {
      HbEvtpScheduleSystemDiagLogWorkItem(in_stack_00000038);
    }
    else if (param_2 == 2) {
      HbEvtpProcessSystemDiagLog('\x01',puVar2,pcVar3,uVar4);
    }
    IoReleaseRemoveLockEx(in_stack_00000038 + 8,in_stack_00000038,0x20);
  }
  return;
}



===== HbEvtpTraceMinrootConfig @ 140010a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HbEvtpTraceMinrootConfig(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined1 auStackY_108 [32];
  ushort local_d8 [2];
  undefined4 local_d4;
  int local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8 [4];
  undefined4 *local_98;
  undefined8 local_90;
  ushort *local_88;
  undefined8 local_80;
  ushort *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  ulonglong local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d0 = 0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x102,0x4298,0x75426248);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    piVar6 = &local_d0;
    uVar5 = 0x4298;
    iVar2 = ZwQuerySystemInformation(0xea,puVar3);
    if (-1 < iVar2) {
      if (local_d0 == 0x4298) {
        if (5 < DAT_140007088) {
          cVar1 = _tlgKeywordOn(0x140007088,0x400000000000);
          if (cVar1 != '\0') {
            local_d8[0] = *(ushort *)(puVar3 + 2);
            local_cc = *puVar3;
            local_98 = &local_cc;
            local_c8 = puVar3[1];
            local_88 = (ushort *)&local_c8;
            local_78 = local_d8;
            local_68 = (undefined8 *)(puVar3 + 3);
            local_c4 = puVar3[0x23];
            local_58 = &local_c4;
            local_d4 = puVar3[0x24];
            local_48 = &local_d4;
            local_38 = &local_c0;
            local_90 = 4;
            local_80 = 4;
            local_70 = 2;
            local_60 = (ulonglong)((uint)local_d8[0] * 2);
            local_50 = 4;
            local_40 = 4;
            local_c0 = 0x2000000;
            local_30 = 8;
            _tlgWriteTransfer_EtwWriteTransfer(0x140007088,&DAT_140005e06,uVar5,piVar6,9,local_b8);
          }
        }
        if (puVar3[0x25] != 0) {
          uVar4 = 0;
          do {
            if (5 < DAT_140007088) {
              cVar1 = _tlgKeywordOn(0x140007088,0x400000000000);
              if (cVar1 != '\0') {
                local_90 = 4;
                local_80 = 2;
                local_70 = 0x100;
                local_c0 = 0x2000000;
                local_d4 = puVar3[(ulonglong)uVar4 * 0x42 + 0x26];
                local_98 = &local_d4;
                local_d8[0] = 0x20;
                local_88 = local_d8;
                local_78 = (ushort *)(puVar3 + (ulonglong)uVar4 * 0x42 + 0x28);
                local_60 = 8;
                local_68 = &local_c0;
                _tlgWriteTransfer_EtwWriteTransfer
                          (0x140007088,&DAT_140005f14,uVar5,piVar6,6,local_b8);
              }
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)puVar3[0x25]);
        }
      }
      else {
        iVar2 = -0x3ffffdfa;
      }
    }
    ExFreePoolWithTag(puVar3,0x75426248);
  }
  return iVar2;
}



===== HbEvtpWaitUntilAllBuffersAreFree @ 140010cc4 =====

ulonglong HbEvtpWaitUntilAllBuffersAreFree(undefined8 param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong lVar7;
  longlong local_res8;
  undefined8 local_res18;
  
  local_res8 = 0;
  if (param_2 == 2) {
    uVar5 = 0;
  }
  else {
    uVar4 = HbEvtpGetLogConfiguration(param_2,&local_res8);
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      if (param_2 == 1) {
        HbEvtpLocalDiagnosticsDisableSession = 1;
      }
      uVar3 = WinHvSetEventLogGroupSources(param_2,0);
      uVar5 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        uVar5 = HbpEvtpFlushEventLog(param_2);
        lVar2 = local_res8;
        uVar3 = 0;
        uVar4 = 0;
        local_res18 = 0xfffffffffff85ee0;
        uVar5 = uVar5 & 0xffffffff;
        if (*(int *)(local_res8 + 8) != 0) {
          do {
            lVar7 = uVar4 * 0x70;
            iVar1 = *(int *)(*(longlong *)(lVar7 + *(longlong *)(lVar2 + 0x20)) + 0x2c);
            for (; (iVar1 != 1 && (uVar3 < 600)); uVar3 = uVar3 + 1) {
              KeDelayExecutionThread(0,0,&local_res18);
              iVar1 = *(int *)(*(longlong *)(*(longlong *)(lVar2 + 0x20) + lVar7) + 0x2c);
            }
            if ((*(int *)(*(longlong *)(*(longlong *)(lVar2 + 0x20) + lVar7) + 0x2c) != 1) &&
               (HbpTraceFault(0,"HbEvtpWaitUntilAllBuffersAreFree",
                              "Timeout waiting for buffer %d to be freed (owned by ETW: %d)",uVar4),
               *(int *)(*(longlong *)(lVar2 + 0x20) + 0x58 + lVar7) != 0)) {
              ExReleaseRundownProtection(*(longlong *)(local_res8 + 0x28) + uVar4 * 8);
            }
            uVar6 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar6;
          } while (uVar6 < *(uint *)(lVar2 + 8));
        }
      }
    }
  }
  return uVar5;
}



===== HbpEvtpFlushEventLog @ 140010e18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong HbpEvtpFlushEventLog(int param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined1 auStack_48 [32];
  uint local_28 [2];
  uint *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_20 = (uint *)0x0;
  uVar3 = HbEvtpGetLogConfiguration(param_1,&local_20);
  puVar1 = local_20;
  local_28[0] = (uint)uVar3;
  uVar3 = uVar3 & 0xffffffff;
  if (-1 < (int)local_28[0]) {
    if ((local_20[2] == 0) || (*(longlong *)(local_20 + 8) == 0)) {
      uVar3 = 0xc000000d;
      local_28[0] = 0xc000000d;
    }
    else if (local_20[0xc] == 1) {
      local_28[0] = WinHvFlushEventLogBuffer(param_1,0);
      uVar3 = (ulonglong)local_28[0];
    }
    else {
      uVar4 = 0;
      if (local_20[2] != 0) {
        do {
          uVar2 = WinHvFlushEventLogBuffer(param_1);
          uVar3 = 0;
          if (uVar2 != 0xc0350008) {
            uVar3 = (ulonglong)uVar2;
          }
          if ((int)(uint)uVar3 < 0) {
            local_28[0] = (uint)uVar3;
          }
          else {
            uVar3 = (ulonglong)local_28[0];
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < puVar1[2]);
      }
    }
  }
  if ((int)uVar3 < 0) {
    local_14 = 0;
    local_20 = local_28;
    local_18 = 4;
    HbEvtpWriteEventLog(&HV_EVENTLOG_FLUSH_FAILED,1,&local_20);
    uVar3 = (ulonglong)local_28[0];
  }
  return uVar3;
}



===== HbpLogHypervisorMsrAccessGlobalEvent @ 140010f1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbpLogHypervisorMsrAccessGlobalEvent
               (undefined4 param_1,undefined1 param_2,undefined8 param_3,undefined2 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               longlong param_9)

{
  longlong lVar1;
  undefined4 local_res8 [2];
  undefined1 local_res10 [8];
  undefined8 local_res18;
  undefined2 local_res20 [4];
  undefined1 auStack_c8 [32];
  undefined4 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined2 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  longlong local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = local_res8;
  local_98 = local_res10;
  local_a0 = 4;
  local_88 = &local_res18;
  local_78 = local_res20;
  local_68 = &param_5;
  local_58 = &param_6;
  local_48 = &param_7;
  local_38 = &param_8;
  lVar1 = -1;
  local_90 = 1;
  local_80 = 8;
  local_70 = 2;
  local_60 = 8;
  local_50 = 8;
  local_40 = 4;
  local_30 = 4;
  local_28 = param_9;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_9 + lVar1) != '\0');
  local_20 = (int)lVar1 + 1;
  local_1c = 0;
  local_res8[0] = param_1;
  local_res10[0] = param_2;
  local_res18 = param_3;
  local_res20[0] = param_4;
  HbEvtpWriteEventLog(&HV_EVENTLOG_RESTRICTED_MSR_ACCESS,9,&local_a8);
  return;
}



===== HbpLogHypervisorMsrAccessTelemetryEvent @ 14001101c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbpLogHypervisorMsrAccessTelemetryEvent
               (undefined4 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,uint param_7,uint param_8,char *param_9)

{
  char cVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined6 uVar4;
  undefined1 auStackY_148 [32];
  undefined1 local_118 [4];
  undefined2 local_114 [2];
  undefined4 local_110 [2];
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  ulonglong local_f0;
  ulonglong local_e8 [6];
  undefined4 *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined2 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38 [2];
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  uVar3 = (undefined2)param_4;
  uVar4 = (undefined6)((ulonglong)param_4 >> 0x10);
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  if (5 < DAT_140007088) {
    cVar1 = _tlgKeywordOn(0x140007088,0x400000000000);
    if (cVar1 != '\0') {
      local_ac = 0;
      local_b8 = local_110;
      local_9c = 0;
      local_8c = 0;
      uVar2 = 8;
      local_7c = 0;
      local_6c = 0;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_a8 = local_118;
      local_98 = &local_108;
      local_88 = local_114;
      local_100 = param_5;
      local_78 = &local_100;
      local_f8 = param_6;
      local_68 = &local_f8;
      local_f0 = (ulonglong)param_7;
      local_58 = &local_f0;
      local_e8[0] = (ulonglong)param_8;
      local_48 = local_e8;
      local_b0 = 4;
      local_a0 = 1;
      local_90 = 8;
      local_80 = 2;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_118[0] = param_2;
      local_114[0] = uVar3;
      local_110[0] = param_1;
      local_108 = param_3;
      _tlgCreate1Sz_char(local_38,param_9);
      local_1c = 0;
      local_28 = local_e8 + 1;
      local_e8[1] = 0x2000000;
      local_20 = (undefined4)uVar2;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x140007088,&DAT_140005f71,uVar2,CONCAT62(uVar4,uVar3),0xc,local_e8 + 2);
    }
  }
  return;
}



===== HbpLogHypervisorMsrEvent @ 1400111c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbpLogHypervisorMsrEvent
               (undefined4 param_1,undefined1 param_2,undefined8 param_3,ushort param_4,
               longlong param_5)

{
  undefined1 auStackY_1e8 [32];
  longlong local_198 [4];
  undefined8 local_178;
  ushort local_162;
  char local_160 [255];
  undefined1 local_61;
  uint local_60;
  uint local_5c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1e8;
  memset(local_198,0,0x148);
  if (param_5 != 0) {
    local_198[0] = param_5;
    ZwQuerySystemInformation(0xa7,local_198,0x148,0);
  }
  local_61 = 0;
  HbpLogHypervisorMsrAccessGlobalEvent
            (param_1,param_2,param_3,param_4,(char)param_5,(char)local_178,(char)local_60,
             (char)local_5c,(longlong)(local_160 + local_162));
  HbpLogHypervisorMsrAccessTelemetryEvent
            (param_1,param_2,param_3,(ulonglong)param_4,param_5,local_178,local_60,local_5c,
             local_160 + local_162);
  return;
}



===== HbEvtpPeriodicGlobalSystemEventFlushWorkItemRoutine @ 1400112f0 =====

void HbEvtpPeriodicGlobalSystemEventFlushWorkItemRoutine
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  local_res8 = 0;
  cVar3 = ExAcquireRundownProtection();
  if (cVar3 != '\0') {
    uVar4 = HbEvtpGetLogConfiguration(0,&local_res8);
    lVar2 = local_res8;
    if ((-1 < (int)uVar4) && (*(int *)(local_res8 + 8) != 0)) {
      do {
        WinHvFlushEventLogBuffer(0,uVar5);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(lVar2 + 8));
    }
    ExReleaseRundownProtection(&DAT_140007208);
  }
  IoFreeWorkItem(param_3);
  IoReleaseRemoveLockEx(lVar1 + 0x40,lVar1,0x20);
  return;
}



===== HbPowerDispatch @ 1400113c0 =====

undefined8 HbPowerDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((*(char *)(lVar1 + 1) == '\x02') || (*(char *)(lVar1 + 1) == '\x03')) {
    if (*(int *)(lVar1 + 0x10) == 0) {
      lVar2 = *(longlong *)(param_1 + 0x40);
      *(byte *)(lVar1 + 3) = *(byte *)(lVar1 + 3) | 1;
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
      lVar1 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar1 + -0x10) = HbpPowerSystemIrpReturn;
      *(undefined8 *)(lVar1 + -8) = 0;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
      PoCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
      return 0x103;
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar4 = PoCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
  return uVar4;
}



===== _tlgEnableCallback @ 1400114b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = 0x100;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
      else {
        *(undefined8 *)(param_7 + 4) = param_4;
        *param_7 = param_3 + 1;
        *(undefined8 *)(param_7 + 6) = param_5;
      }
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== HbEvtpProcessSystemDiagLog @ 140011550 =====

void HbEvtpProcessSystemDiagLog
               (char param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  ulonglong uVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong local_res10;
  ulonglong local_res18 [2];
  
  local_res10 = 0;
  cVar2 = ExAcquireRundownProtection(&DAT_140007328);
  if (cVar2 == '\0') {
    return;
  }
  if (param_1 == '\0') {
    cVar2 = ExTryToAcquireFastMutex(&DAT_140007348);
    if (cVar2 == '\0') goto LAB_1400116a2;
  }
  else {
    ExAcquireFastMutex();
  }
  uVar3 = HbEvtpGetLogConfiguration(2,&local_res10);
  if (-1 < (int)uVar3) {
    lVar4 = local_res10;
    do {
      local_res18[0] = 0;
      while( true ) {
        if (DAT_1400073ac == 0xffffffff) {
          param_4 = 0;
          uVar7 = 0xffffffffffffffff;
          uVar5 = DAT_1400073ac;
          if (*(int *)(lVar4 + 8) == 0) goto LAB_14001168f;
          do {
            uVar1 = *(ulonglong *)
                     (*(longlong *)(param_4 * 0x70 + *(longlong *)(lVar4 + 0x20)) + 0x10);
            if (DAT_1400073a0 < uVar1) {
              if (uVar1 < uVar7) {
                uVar7 = uVar1;
                uVar5 = (uint)param_4;
              }
            }
            uVar6 = (uint)param_4 + 1;
            param_4 = (ulonglong)uVar6;
          } while (uVar6 < *(uint *)(lVar4 + 8));
          if (uVar5 != 0xffffffff) {
            DAT_1400073a8 = 0x48;
            DAT_1400073a0 = uVar7;
            DAT_1400073ac = uVar5;
          }
          if (DAT_1400073ac == 0xffffffff) goto LAB_14001168f;
          lVar4 = local_res10;
        }
        uVar3 = HbEvtpProcessSystemDiagLogBuffer
                          (lVar4,(longlong *)
                                 ((ulonglong)DAT_1400073ac * 0x70 + *(longlong *)(lVar4 + 0x20)),
                           local_res18,param_4);
        if ((char)uVar3 == '\0') goto LAB_14001168f;
        if (param_1 != '\0') break;
        if (499 < local_res18[0]) goto LAB_14001168f;
      }
    } while( true );
  }
LAB_14001168f:
  ExReleaseFastMutex(&DAT_140007348);
LAB_1400116a2:
  ExReleaseRundownProtection(&DAT_140007328);
  return;
}



===== HbEvtpCreateEventLog @ 1400116d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint HbEvtpCreateEventLog(longlong param_1,uint param_2,int param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  bool bVar4;
  char cVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined *puVar10;
  undefined1 auStackY_a8 [32];
  uint local_78 [2];
  int *local_70;
  undefined8 local_68;
  uint *local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_70 = (int *)0x0;
  local_68 = 0;
  uVar9 = 0;
  uVar8 = 0;
  local_60 = (uint *)0x0;
  uStack_58 = 0;
  KeWaitForSingleObject(param_1 + 0xd0,0,0,0);
  if (*(char *)(param_1 + 0x108) == '\x01') {
    local_78[0] = 0xc0000056;
    goto LAB_1400117c0;
  }
  puVar10 = &DAT_140007208 + (longlong)(int)param_2 * 0x90;
  cVar5 = ExAcquireRundownProtection(puVar10);
  if (cVar5 == '\0') {
    local_78[0] = 0xc00000a3;
    goto LAB_1400117c0;
  }
  uVar6 = HbEvtpGetLogConfiguration(param_2,&local_70);
  piVar2 = local_70;
  local_78[0] = (uint)uVar6;
  if ((int)local_78[0] < 0) {
LAB_14001197e:
    bVar4 = false;
LAB_140011981:
    bVar1 = bVar4;
    if ((int)local_78[0] < 0) {
LAB_140011989:
      if (bVar1) {
        piVar2[2] = uVar8;
        ExReleaseRundownProtection(puVar10);
        HbEvtpDeleteEventLog(param_1,param_2);
        local_60 = local_78;
        uStack_58 = 4;
        HbEvtpWriteEventLog(&HV_EVENTLOG_CREATION_FAILED,1,&local_60);
        goto LAB_1400117c0;
      }
    }
  }
  else if (local_70[2] == 0) {
    local_70[0xc] = param_3;
    lVar7 = ExAllocatePool2(0x40,param_4[2] * 0x70,0x75426248);
    *(longlong *)(piVar2 + 8) = lVar7;
    if (lVar7 != 0) {
      lVar7 = ExAllocatePool2(0x40,param_4[2] << 3,0x75426248);
      *(longlong *)(piVar2 + 10) = lVar7;
      if (lVar7 != 0) {
        uVar8 = 0;
        if (param_4[2] != 0) {
          do {
            ExInitializeRundownProtection(*(longlong *)(piVar2 + 10) + uVar9 * 8);
            uVar8 = (int)uVar9 + 1;
            uVar9 = (ulonglong)uVar8;
          } while (uVar8 < (uint)param_4[2]);
        }
        InitializeSListHead((PSLIST_HEADER)(piVar2 + 0x1c));
        local_78[0] = HvlQueryActiveHypervisorProcessorCount(&HbEvtpActiveProcessorCount);
        if ((int)local_78[0] < 0) goto LAB_14001197e;
        if (param_2 == 1) {
          lVar7 = ExAllocatePool2(0x100,(ulonglong)HbEvtpActiveProcessorCount << 2,0x75426248);
          *(longlong *)(piVar2 + 0x22) = lVar7;
          if (lVar7 == 0) goto LAB_140011971;
        }
        local_78[0] = WinHvGetPartitionId(&local_68);
        if (((int)local_78[0] < 0) ||
           (local_78[0] = WinHvInitializeEventLogBufferGroup(param_2,param_3,param_4[2],param_4[1]),
           (int)local_78[0] < 0)) goto LAB_14001197e;
        uVar8 = 0;
        piVar2[2] = param_4[2];
        bVar1 = true;
        *piVar2 = *param_4;
        piVar2[1] = param_4[1];
        uVar3 = 0;
        bVar4 = true;
        if (piVar2[2] != 0) {
          do {
            uVar8 = uVar3;
            local_78[0] = HbEvtpCreateEventLogBuffer(param_1,param_2,uVar8,piVar2,local_68);
            if ((int)local_78[0] < 0) goto LAB_140011989;
            uVar8 = uVar8 + 1;
            uVar3 = uVar8;
          } while (uVar8 < (uint)piVar2[2]);
        }
        goto LAB_140011981;
      }
    }
LAB_140011971:
    local_78[0] = 0xc000009a;
  }
  else {
    local_78[0] = 0xc000000d;
  }
  ExReleaseRundownProtection(puVar10);
LAB_1400117c0:
  KeReleaseMutex(param_1 + 0xd0,0);
  return local_78[0];
}



===== HbPnpDispatch @ 1400119f0 =====

int HbPnpDispatch(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(lVar2 + 0x18) == 0) {
    return -0x3ffffff0;
  }
  uVar3 = 1;
  iVar1 = IoAcquireRemoveLockEx(lVar2 + 0x40,param_2,"",1,0x20);
  if (iVar1 < 0) {
    *(int *)(param_2 + 0x30) = iVar1;
    IofCompleteRequest(param_2,0);
    return iVar1;
  }
  switch(*(undefined1 *)(*(longlong *)(param_2 + 0xb8) + 1)) {
  case 0:
    iVar1 = HbPnpStartDevice(param_1,param_2,&IMAGE_DOS_HEADER_140000000,uVar3);
    break;
  case 1:
  case 5:
    *(undefined4 *)(param_2 + 0x30) = 0x80000011;
    lVar2 = *(longlong *)(param_1 + 0x40);
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar2 + 0x40,param_2,0x20);
    iVar1 = -0x7fffffef;
    break;
  case 2:
    HbPnpDeleteAllEventLogs(lVar2);
    IoReleaseRemoveLockAndWaitEx(lVar2 + 0x40,param_2,0x20);
    HbPnpFreeResources(lVar2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0;
    iVar1 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
    IoDetachDevice(*(undefined8 *)(lVar2 + 0x18));
    IoDeleteDevice(param_1);
    break;
  case 3:
  case 4:
  case 6:
    *(undefined4 *)(param_2 + 0x30) = 0;
  default:
    lVar2 = *(longlong *)(param_1 + 0x40);
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    goto LAB_140011bad;
  case 0x17:
    IoSetDeviceInterfaceState(lVar2 + 0x20,0);
    RtlFreeUnicodeString(lVar2 + 0x20);
    *(undefined8 *)(lVar2 + 0x28) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    lVar2 = *(longlong *)(param_1 + 0x40);
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_140011bad:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    iVar1 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
    IoReleaseRemoveLockEx(lVar2 + 0x40,param_2,0x20);
  }
  return iVar1;
}



===== entry @ 140012010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140012044 =====

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



===== DriverEntry @ 140012078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  ulonglong local_28 [4];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_48;
  wil_InitializeFeatureStaging();
  local_28[0] = 0;
  local_28[1] = 0;
  HviGetHypervisorFeatures(local_28);
  if ((local_28[0] >> 0x20 & 1) != 0) {
    local_28[0] = 0;
    local_28[1] = 0;
    HviGetHypervisorFeatures(local_28);
    *(code **)(param_1 + 0x68) = HbDriverUnload;
    HbpIsCpuManagementPartition = (byte)(local_28[0] >> 0x2c) & 1;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = HbAddDevice;
    *(code **)(param_1 + 0x148) = HbPnpDispatch;
    *(code **)(param_1 + 0x120) = HbPowerDispatch;
    *(code **)(param_1 + 0x128) = HbSysCtrlDispatch;
    *(code **)(param_1 + 0x70) = HbIoDispatchClose;
    *(code **)(param_1 + 0x100) = HbIoDispatchClose;
    *(code **)(param_1 + 0x80) = HbIoDispatchClose;
    *(code **)(param_1 + 0xe0) = HbIoDispatchIoctl;
    iVar1 = IoReportRootDevice(param_1);
    if (iVar1 < 0) {
      wil_UninitializeFeatureStaging();
      return iVar1;
    }
  }
  return 0;
}



===== wil_InitializeFeatureStaging @ 140012194 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    plVar3 = (longlong *)&wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding(plVar3), plVar3 != (longlong *)0x0) {
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
      plVar3 = plVar3 + 7;
    }
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140012284 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar3 = (longlong *)&wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar3);
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
    plVar3 = plVar2 + 7;
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


