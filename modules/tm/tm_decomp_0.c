
===== TmpNotifyAllCRM @ 140001008 =====

int TmpNotifyAllCRM(undefined8 param_1,undefined8 param_2,void *param_3)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  
  iVar3 = 0;
  uVar2 = 0;
  KeWaitForSingleObject(&TmpAllCRMListMutex);
  for (puVar4 = TmpAllCRMList; (undefined8 **)puVar4 != &TmpAllCRMList;
      puVar4 = (undefined8 *)*puVar4) {
    if (((*(int *)((longlong)puVar4 + -0x13c) == 2) &&
        (iVar1 = TmpSetNotificationResourceManager
                           ((longlong)(puVar4 + -0x2b),uVar2,0,0,0x2000000,0x14,param_3), -1 < iVar3
        )) && (iVar1 < 0)) {
      iVar3 = iVar1;
    }
  }
  KeReleaseMutex(&TmpAllCRMListMutex,0);
  return iVar3;
}



===== WPP_SF__guid__guid_ @ 1400010bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid__guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_26465a38b77537bfc9af1810e91887cd_Traceguids,10,param_4,0x10,param_5,
             0x10,0);
  return;
}



===== WPP_SF_qii @ 140001110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_q_guid_ @ 140001174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f027ff31da0838c658ebe09252abcfce_Traceguids,param_2,&local_res20,8,
             param_5,0x10,0);
  return;
}



===== WPP_SF_qdddd @ 1400011d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,0x1f,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qi @ 140001254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qi(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_q @ 1400012a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qq @ 1400012e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6e9068bbfb213430aec3b8c36d4eb7a8_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qq_guid_i @ 140001340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq_guid_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined8 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6e9068bbfb213430aec3b8c36d4eb7a8_Traceguids,0xd,&local_res20,8,
             &param_5,8,param_6,0x10,&param_7,8,0);
  return;
}



===== WPP_SF_q_guid_d @ 1400013b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f027ff31da0838c658ebe09252abcfce_Traceguids,0x12,&local_res20,8,
             param_5,0x10,&param_6,4,0);
  return;
}



===== TmpCheckForProgressDpcRoutine @ 140001430 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmpCheckForProgressDpcRoutine(void)

{
  _DAT_140008258 = 0;
  _TmpCheckForProgressWorkItem = 0;
  _DAT_140008250 = TmpCheckForProgressWorkRoutine;
  ExQueueWorkItem(&TmpCheckForProgressWorkItem,1);
  return;
}



===== __report_gsfailure @ 140001480 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000148d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000148d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WPP_SF_qD @ 1400014a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qDD @ 1400014f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,0x1b,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLL @ 14000155c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLLLL @ 1400015c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLLLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,0x1a,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qdqiid @ 140001648 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdqiid(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,0x15,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== TmShutdownSystem @ 1400016e0 =====

void TmShutdownSystem(void)

{
                    /* 0x16e0  76  TmShutdownSystem */
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
  }
  TmpShutdownOccurred = 1;
  TmpNamespaceExpire(0x1400084e0);
  TmpNamespaceForEach(0x1400084e0,(undefined *)0x0,TmpShutdownTransactionManager);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
  }
  return;
}



===== TmpReadKtmRmTmId @ 140001778 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmpReadKtmRmTmId(void)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  undefined1 auStackY_128 [32];
  char local_f8 [4];
  int local_f4;
  undefined1 *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  wchar_t *local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  wchar_t *local_d0;
  undefined8 local_c8;
  undefined1 *puStack_c0;
  undefined1 local_b8 [160];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d4 = 0;
  local_f0 = local_b8;
  local_e4 = 0;
  local_f8[0] = '\0';
  local_d0 = L"\\Registry\\Machine\\Software\\Microsoft\\MSDTC\\KtmRm";
  local_f4 = 0x9c;
  local_e0 = L"KtmRmTmIdentifier";
  local_d8 = 0x620060;
  local_c8 = 0;
  puStack_c0 = (undefined1 *)0x0;
  local_e8 = 0x240022;
  uVar2 = TmpQueryValueKey(&local_d8,(longlong)&local_e8,&local_f4,(longlong *)&local_f0,local_f8);
  puVar1 = local_f0;
  if ((int)uVar2 < 0) {
    _TmpKtmRmTmGuid = 0;
    uRam00000001400082a8 = 0;
  }
  else {
    puStack_c0 = local_f0 + *(uint *)(local_f0 + 8);
    local_c8._0_4_ = CONCAT22(*(undefined2 *)(local_f0 + 0xc),*(undefined2 *)(local_f0 + 0xc));
    RtlGUIDFromString(&local_c8,&TmpKtmRmTmGuid);
  }
  if (local_f8[0] != '\0') {
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== WPP_SF_ @ 140001894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1400018c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDD @ 140001908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,0xb,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qd @ 14000196c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400019d0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
    }
    *(undefined8 *)(param_4 + 0x18) = uVar1;
  }
  return;
}



===== TmpStartKtmRm @ 140001a04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpStartKtmRm(void)

{
  undefined1 auStack_58 [32];
  undefined **local_38;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_1c = 0;
  local_28 = &TmpKtmRmServiceStartGuid;
  local_38 = &local_28;
  local_20 = 0x10;
  EtwWrite(TmpTriggerHandle,&KTM_ETW_EVENT_TRIGGER_SVC_START,0,1);
  return;
}



===== TmpTraceTransactionManagerNotAdvancingTail @ 140001a78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpTraceTransactionManagerNotAdvancingTail(longlong param_1,longlong param_2)

{
  undefined1 auStack_b8 [32];
  longlong *local_98;
  ushort local_88 [2];
  ushort local_84 [6];
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  ushort *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (TmpEtwHandle != 0) {
    local_78 = param_1 + 0x70;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_88[0] = *(ushort *)(param_1 + 0x88) >> 1;
    local_68 = local_88;
    local_58 = *(undefined8 *)(param_1 + 0x90);
    local_48 = param_2 + 0xb0;
    local_84[0] = *(ushort *)(param_2 + 0x130) >> 1;
    local_38 = local_84;
    local_28 = *(undefined8 *)(param_2 + 0x138);
    local_98 = &local_78;
    local_50 = (uint)*(ushort *)(param_1 + 0x88);
    local_20 = (uint)*(ushort *)(param_2 + 0x130);
    local_70 = 0x10;
    local_60 = 2;
    local_40 = 0x10;
    local_30 = 2;
    EtwWrite(TmpEtwHandle,&KTM_ETW_EVENT_TRANSACTIONMANAGER_NOT_ADVANCING_TAIL,0,6);
  }
  return;
}



===== TmpTransactionManagerNeededForRecovery @ 140001b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpTransactionManagerNeededForRecovery(undefined8 param_1)

{
  longlong lVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  lVar1 = RtlCompareMemory(0,&local_28,0x10);
  if (lVar1 == 0x10) {
    TmpReadKtmRmTmId();
  }
  else {
    lVar1 = RtlCompareMemory(param_1,&TmpKtmRmTmGuid,0x10);
    if (lVar1 == 0x10) {
      TmpStartKtmRm();
    }
  }
  return;
}



===== WPP_SF_qq_guid_ii @ 140001c08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq_guid_ii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                      undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6e9068bbfb213430aec3b8c36d4eb7a8_Traceguids,param_2,&local_res20,8,
             &param_5,8,param_6,0x10,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_SF_q_guid__guid_ @ 140001c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid__guid_
               (undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_64356b1a6e0c31583d5a1e3b4a774de6_Traceguids,param_2,&local_res20,8,
             param_5,0x10,param_6,0x10,0);
  return;
}



===== WPP_SF_qq_guid_ @ 140001d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq_guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined8 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,param_6,0x10,0);
  return;
}



===== TmpRollbackDpc @ 140001d70 =====

void TmpRollbackDpc(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0x148) = 0;
  *(longlong *)(param_2 + 0x160) = param_2;
  *(code **)(param_2 + 0x158) = TmpRollbackWorkItem;
  ExQueueWorkItem((undefined8 *)(param_2 + 0x148),1);
  return;
}



===== TmpTransactionThawDpcRoutine @ 140001db0 =====

void TmpTransactionThawDpcRoutine(void)

{
  undefined *puVar1;
  
  puVar1 = TmpTransactionThawWorkItemRef;
  LOCK();
  TmpTransactionThawWorkItemRef = (undefined *)0x0;
  UNLOCK();
  if (puVar1 != (undefined *)0x0) {
    *(undefined8 *)(puVar1 + 0x18) = 0;
    *(undefined8 *)puVar1 = 0;
    *(code **)(puVar1 + 0x10) = TmpThawTransactionsWorkRoutine;
    ExQueueWorkItem(puVar1,1);
  }
  return;
}



===== WPP_SF_q_guid_D @ 140001df4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f027ff31da0838c658ebe09252abcfce_Traceguids,param_2,&local_res20,8,
             param_5,0x10,&param_6,4,0);
  return;
}



===== WPP_SF_sqq_guid_d @ 140001e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqq_guid_d(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  
  lVar1 = -1;
  do {
    lVar2 = lVar1;
    lVar1 = lVar2 + 1;
  } while ("TmpTxActionDoRollback"[lVar2 + 1] != '\0');
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_f027ff31da0838c658ebe09252abcfce_Traceguids,0x13,
             "TmpTxActionDoRollback",lVar2 + 2,&uStack0000000000000028,8,&uStack0000000000000030,8);
  return;
}



===== TmpCheckForProgressWorkRoutine @ 140001f10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpCheckForProgressWorkRoutine
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  undefined1 auStackY_58 [32];
  longlong local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  while( true ) {
    uVar1 = TmpNamespaceEnumerateObject(param_1,&local_20,param_3,param_4,&local_28);
    param_1 = local_28;
    if ((int)uVar1 == -0x7fffffe6) break;
    local_20 = *(undefined8 *)(local_28 + 0x70);
    uStack_18 = *(undefined8 *)(local_28 + 0x78);
    TmpCheckForProgressTransactionManager(local_28);
    ObfDereferenceObject();
  }
  return;
}



===== TmpIsOnlineTransactionManager @ 140001f90 =====

bool TmpIsOnlineTransactionManager(longlong param_1)

{
  return *(int *)(param_1 + 0x40) == 3;
}



===== TmpShutdownTransactionManager @ 140001fa0 =====

undefined8 TmpShutdownTransactionManager(longlong param_1)

{
  TmpTmOffline(param_1);
  return 0;
}



===== WPP_SF_DDq @ 140001fb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_aa500d615f02383f20d25780cb696015_Traceguids,0xc,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_Dq @ 140002020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_aa500d615f02383f20d25780cb696015_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qq_guid_D @ 140002078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq_guid_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,undefined8 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_aa500d615f02383f20d25780cb696015_Traceguids,0xe,&local_res20,8,
             &param_5,8,param_6,0x10,&param_7,4,0);
  return;
}



===== WPP_SF_qqi @ 1400020f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_aa500d615f02383f20d25780cb696015_Traceguids,0x10,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqii @ 140002158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_aa500d615f02383f20d25780cb696015_Traceguids,0x11,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== TmpAbandonRequestDpc @ 1400021d0 =====

void TmpAbandonRequestDpc(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(param_2 + 0xa8) = 0;
  *(longlong *)(param_2 + 0xc0) = param_2;
  *(code **)(param_2 + 0xb8) = TmpDelayedPropWorkItem;
  ExQueueWorkItem((undefined8 *)(param_2 + 0xa8),1);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000220c =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140007a87 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140002234 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002390 =====

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



===== _guard_check_icall @ 140002420 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002438 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000245c =====

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



===== __GSHandlerCheck_SEH @ 1400024c4 =====

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



===== _local_unwind @ 140002550 =====

void _local_unwind(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140002550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _local_unwind();
  return;
}



===== __cpu_features_init @ 140002570 =====

/* WARNING: Removing unreachable block (ram,0x0001400025da) */
/* WARNING: Removing unreachable block (ram,0x000140002589) */
/* WARNING: Removing unreachable block (ram,0x00014000257a) */

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



===== __security_check_cookie @ 140002640 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002680 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400026b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400026b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400026e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140002720 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140002763;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400027d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400027d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400027d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400027cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400027d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400027cc;
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
LAB_1400027d4:
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
LAB_140002763:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 140002840 =====

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



===== memset @ 140002b40 =====

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



===== __memset_repmovs @ 140002c80 =====

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



===== __memset_query @ 140002d00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002d80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002ec0 =====

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



===== __memset_spec_plain @ 140002f40 =====

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



===== TmpNotifyAllCRM$fin$0 @ 14000303d =====

void TmpNotifyAllCRM_fin_0(void)

{
  KeReleaseMutex(&TmpAllCRMListMutex,0);
  return;
}



===== TmpPromotionsIncomplete @ 14000d008 =====

undefined1 TmpPromotionsIncomplete(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x100);
  while( true ) {
    if (puVar1 == (undefined8 *)(param_1 + 0x100)) {
      return 0;
    }
    if (puVar1[-2] == 0) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return 1;
}



===== TmpAdvanceBaseLsnRequiredNotification @ 14000d030 =====

undefined8
TmpAdvanceBaseLsnRequiredNotification(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  *(undefined8 *)(param_3 + 0x2e8) = *param_2;
  LOCK();
  *(uint *)(param_3 + 0x84) = *(uint *)(param_3 + 0x84) | 8;
  UNLOCK();
  TmpQueueCheckpointTm(param_3);
  return 0x103;
}



===== TmpCheckpointWorker @ 14000d060 =====

void TmpCheckpointWorker(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  LOCK();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffffe;
  UNLOCK();
  uVar2 = *(uint *)(param_1 + 0x84);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x84);
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *(uint *)(param_1 + 0x84) = uVar2 & 0xfffffff7;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  TmpCheckpoint(param_1,(byte)(uVar2 >> 3) & 1);
  ObfDereferenceObject(param_1);
  return;
}



===== TmpLogFullCompletedWorker @ 14000d0c0 =====

void TmpLogFullCompletedWorker(longlong param_1)

{
  LOCK();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffffd;
  UNLOCK();
  KeSetEvent(param_1 + 0x2b0,0,0);
  ExAcquireResourceExclusiveLite(param_1 + 0x310,1);
  if ((*(uint *)(param_1 + 0x84) & 4) == 0) {
    LOCK();
    *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) & 0xfffffffb;
    UNLOCK();
  }
  ExReleaseResourceLite(param_1 + 0x310);
  ObfDereferenceObject(param_1);
  return;
}



===== TmpLogGrowthCompletedNotification @ 14000d150 =====

void TmpLogGrowthCompletedNotification
               (undefined8 param_1,undefined4 param_2,char param_3,longlong param_4)

{
  *(undefined4 *)(param_4 + 0x37c) = param_2;
  LOCK();
  *(uint *)(param_4 + 0x84) = *(uint *)(param_4 + 0x84) | (-(uint)(param_3 != '\0') & 4) + 2;
  UNLOCK();
  if (param_3 == '\0') {
    LOCK();
    *(uint *)(param_4 + 0x84) = *(uint *)(param_4 + 0x84) & 0xfffffffb;
    UNLOCK();
  }
  *(undefined8 *)(param_4 + 0x2f0) = 0;
  *(code **)(param_4 + 0x300) = TmpLogFullCompletedWorker;
  *(longlong *)(param_4 + 0x308) = param_4;
  ExQueueWorkItem((undefined8 *)(param_4 + 0x2f0),1);
  return;
}



===== TmpLogUnpinnedNotification @ 14000d1c0 =====

void TmpLogUnpinnedNotification(undefined8 param_1,longlong param_2)

{
  ObfReferenceObject(param_2);
  TmpLogGrowthCompletedNotification(param_1,0,'\0',param_2);
  return;
}



===== TmInitSystemPhase2 @ 14000d210 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmInitSystemPhase2(void)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  undefined1 auStackY_128 [32];
  char local_f8 [4];
  int local_f4;
  undefined1 *local_f0;
  undefined8 local_e8;
  wchar_t *local_e0;
  undefined8 local_d8;
  wchar_t *local_d0;
  undefined8 local_c8;
  undefined1 *puStack_c0;
  undefined1 local_b8 [160];
  ulonglong local_18;
  
                    /* 0xd210  55  TmInitSystemPhase2 */
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_f0 = local_b8;
  local_d8 = 0x6e006c;
  local_e8 = 0x3a0038;
  local_d0 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\KTM";
  local_f4 = 0x9c;
  local_e0 = L"TmAdvanceTailWarningInterval";
  local_f8[0] = '\0';
  local_c8 = 0;
  puStack_c0 = (undefined1 *)0x0;
  uVar2 = TmpQueryValueKey(&local_d8,(longlong)&local_e8,&local_f4,(longlong *)&local_f0,local_f8);
  if ((int)uVar2 < 0) {
    TmpTmAdvanceTailWarningInterval = -9000000000;
  }
  else {
    TmpTmAdvanceTailWarningInterval =
         (ulonglong)(uint)-*(int *)(local_f0 + *(uint *)(local_f0 + 8)) * -10000000;
  }
  local_d8 = CONCAT44(local_d8._4_4_,0x620060);
  local_d0 = L"\\Registry\\Machine\\Software\\Microsoft\\MSDTC\\KtmRm";
  local_e8 = CONCAT44(local_e8._4_4_,0x240022);
  local_e0 = L"KtmRmTmIdentifier";
  uVar2 = TmpQueryValueKey(&local_d8,(longlong)&local_e8,&local_f4,(longlong *)&local_f0,local_f8);
  puVar1 = local_f0;
  if ((int)uVar2 < 0) {
    _TmpKtmRmTmGuid = 0;
    uRam00000001400082a8 = 0;
  }
  else {
    puStack_c0 = local_f0 + *(uint *)(local_f0 + 8);
    local_c8._0_4_ = CONCAT22(*(undefined2 *)(local_f0 + 0xc),*(undefined2 *)(local_f0 + 0xc));
    RtlGUIDFromString(&local_c8,&TmpKtmRmTmGuid);
  }
  if (local_f8[0] != '\0') {
    ExFreePoolWithTag(puVar1,0);
  }
  KeInitializeTimer(&TmpCheckForProgressTimer);
  KeInitializeDpc(&TmpCheckForProgressDpc,TmpCheckForProgressDpcRoutine,0);
  KeSetTimer(&TmpCheckForProgressTimer,TmpTmAdvanceTailWarningInterval,&TmpCheckForProgressDpc);
  EtwRegister(&KTM_ETW_PROVIDER,0,0,&TmpEtwHandle);
  EtwRegister(&KTM_ETW_TRIGGER_PROVIDER,0,0,&TmpTriggerHandle);
  _WPP_MAIN_CB = 0;
  DAT_1400082c8 = &WPP_ThisDir_CTLGUID_TmLog;
  DAT_1400082d0 = 0;
  _DAT_1400082e0 = 0;
  _DAT_1400082e8 = 1;
  WppLoadTracingSupport();
  _DAT_1400082e0 = 0;
  WppInitKm();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
  }
  return;
}



===== TmpConstructLogRecordForRecovery @ 14000d4a0 =====

undefined8
TmpConstructLogRecordForRecovery
          (int *param_1,uint param_2,undefined8 *param_3,longlong *param_4,longlong *param_5)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  *param_3 = param_1;
  if (*param_1 == 0x104) {
    if (0x37 < param_2) {
      uVar1 = param_1[9];
      if (((uVar1 < 0x48) || (param_1[0xd] != 0x10000001)) || (0x47 < param_2)) {
        uVar2 = param_1[8];
        lVar4 = 0;
        if ((uVar2 != 0) && ((ulonglong)param_2 < (ulonglong)uVar2 * 0x70 + (ulonglong)uVar1)) {
          return 0xc0190030;
        }
        if ((0x47 < uVar1) &&
           ((param_1[0xd] == 0x10000001 &&
            ((ulonglong)param_2 < (ulonglong)(uint)param_1[0x10] + (ulonglong)uVar2 * 8)))) {
          return 0xc0190030;
        }
        *param_4 = (longlong)param_1 + (ulonglong)uVar1;
        piVar3 = (int *)*param_3;
        if ((*piVar3 == 0x104) && ((0x47 < (uint)piVar3[9] && (0x10000000 < (uint)piVar3[0xd])))) {
          lVar4 = (ulonglong)(uint)piVar3[0x10] + (longlong)param_1;
        }
        *param_5 = lVar4;
        return 0;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      if (((uint)param_1[9] < 0x48) ||
         (uVar5 = (ulonglong)(uint)param_1[0xd], (uint)param_1[0xd] < 0x10000001)) {
        uVar5 = 0;
      }
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,WPP_GLOBAL_Control,0x104,
                 (char)uVar5,(char)param_2);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_3,*param_1);
  }
  return 0xc0190030;
}



===== TmpExtractTmIdentityFromExistingLogFile @ 14000d5e4 =====

int TmpExtractTmIdentityFromExistingLogFile(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined4 uVar5;
  undefined8 in_stack_ffffffffffffff80;
  uint uVar6;
  undefined8 local_50;
  longlong local_48;
  longlong local_40 [2];
  undefined4 local_30;
  undefined4 local_2c;
  longlong local_28;
  
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  local_2c = 0;
  local_50 = 0;
  local_res20 = 0;
  local_40[0] = 0;
  local_res18[0] = 0;
  local_48 = 0;
  local_40[1] = 0;
  local_28 = ExAllocatePoolWithQuotaTag(9,0x1000,0x6e4c6d54);
  if (local_28 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    local_30 = 0x10000000;
    RtlCopyUnicodeString(&local_30,0);
    RtlAppendUnicodeStringToString(&local_30,&TmpLogPrefix);
    RtlAppendUnicodeStringToString(&local_30,param_1);
    uVar5 = 0;
    iVar3 = ClfsCreateLogFile(&local_50,&local_30,0x80000000,3,0,1,8,(ulonglong)uVar6 << 0x20,0,0,0)
    ;
    if (iVar3 < 0) {
      ExFreePoolWithTag();
    }
    else {
      ExFreePoolWithTag(local_28,0);
      local_28 = 0;
      iVar3 = ClfsCreateMarshallingArea(local_50,1,0,0,CONCAT44(uVar5,0x10000),0x14,1,&local_res20);
      if (-1 < iVar3) {
        puVar4 = local_res18;
        iVar3 = ClfsReadRestartArea(local_res20,local_40,puVar4,local_40 + 1,&local_48);
        if (iVar3 == 0x401a000c) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,puVar4,0x401a000c);
          }
          iVar3 = -0x3fe6ffd0;
        }
        if ((-1 < iVar3) && (local_40[0] != 0)) {
          uVar5 = *(undefined4 *)(local_40[0] + 0x10);
          uVar1 = *(undefined4 *)(local_40[0] + 0x14);
          uVar2 = *(undefined4 *)(local_40[0] + 0x18);
          *param_2 = *(undefined4 *)(local_40[0] + 0xc);
          param_2[1] = uVar5;
          param_2[2] = uVar1;
          param_2[3] = uVar2;
        }
      }
      if (local_48 != 0) {
        ClfsTerminateReadLog();
      }
      if (local_res20 != 0) {
        ClfsDeleteMarshallingArea();
      }
      ClfsCloseLogFileObject(local_50);
    }
  }
  return iVar3;
}



===== TmpRecoverAllEnlistmentRecordsInLogRecord @ 14000d850 =====

ulonglong TmpRecoverAllEnlistmentRecordsInLogRecord
                    (int *param_1,uint param_2,longlong param_3,longlong param_4,undefined8 param_5,
                    undefined8 param_6,char param_7,undefined8 param_8,longlong param_9)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong local_res8;
  undefined1 in_stack_ffffffffffffffa0;
  
  lVar2 = param_9;
  uVar1 = param_8;
  uVar4 = 0;
  while( true ) {
    if ((uint)param_1[8] <= (uint)uVar4) {
      return 0;
    }
    local_res8 = 0;
    param_6 = 0;
    puVar5 = (undefined8 *)(uVar4 * 0x70 + param_3);
    uVar3 = TmpRecoverOneEnlistmentRecordFromLogRecord
                      (param_1,param_2,puVar5,(uint *)(param_4 + uVar4 * 8),param_5,
                       in_stack_ffffffffffffffa0,param_7,uVar1,lVar2,&local_res8,&param_6);
    if ((int)uVar3 < 0) break;
    ZwClose(local_res8);
    ZwClose(param_6);
    uVar4 = (ulonglong)((uint)uVar4 + 1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,puVar5,(int)uVar3);
  }
  return uVar3 & 0xffffffff;
}



===== TmpRecoverEnlistmentFromEnlistmentRecord @ 14000d984 =====

ulonglong TmpRecoverEnlistmentFromEnlistmentRecord
                    (longlong param_1,uint param_2,undefined8 *param_3,undefined8 param_4,
                    longlong param_5,undefined8 param_6,longlong param_7,undefined8 param_8,
                    longlong *param_9,undefined1 *param_10)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *local_res18;
  ulonglong in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar8;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  longlong local_38;
  undefined8 uStack_30;
  
  puVar7 = param_10;
  plVar2 = param_9;
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_58 = 0x30;
  local_40 = 0x200;
  *param_9 = 0;
  *param_10 = 0;
  param_7 = 0;
  local_res18 = (longlong *)0x0;
  local_50 = 0;
  local_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar4 = TmpFindEnlistmentResourceManager(param_5,param_3,&local_res18);
  if (-1 < (int)uVar4) {
    uVar4 = ObOpenObjectByPointer
                      (local_res18,0x200,0,0xf001f,TmEnlistmentObjectType,
                       in_stack_ffffffffffffff90 & 0xffffffffffffff00,plVar2);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *puVar7 = 1;
    goto LAB_14000da3e;
  }
  uVar4 = TmpRecoverSecurityDescriptor
                    (param_1,param_2,*(uint *)((longlong)param_3 + 100),*(uint *)(param_3 + 0xc),
                     &param_7);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  local_38 = param_7;
  uVar4 = ZwCreateEnlistment(plVar2,0xf001f,param_4,param_6,&local_58,
                             CONCAT44((int)(in_stack_ffffffffffffff90 >> 0x20),
                                      *(uint *)(param_3 + 10)) & 0xffffffff00000001,
                             CONCAT44(uVar8,(-(uint)((*(uint *)(param_3 + 10) & 1) != 0) &
                                            0x1fffc0ba) + 0x400e),0);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  param_9 = (longlong *)0x0;
  uVar3 = ObReferenceObjectByHandle(*plVar2,2,TmEnlistmentObjectType,0,&param_9,0);
  uVar6 = (ulonglong)uVar3;
  local_res18 = param_9;
  if (-1 < (int)uVar3) {
    uVar3 = TmpNamespaceRename(param_9[0x13] + 0x180,(longlong)param_9,param_3);
    uVar6 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      uVar6 = 0xc0190053;
    }
    else {
      if ((*(uint *)(param_3 + 10) & 0x20) != 0) {
        lVar1 = param_3[5];
        param_9[0x21] = param_3[4];
        param_9[0x22] = lVar1;
        lVar1 = param_3[9];
        param_9[0x23] = param_3[8];
        param_9[0x24] = lVar1;
        lVar1 = param_3[7];
        param_9[0x25] = param_3[6];
        param_9[0x26] = lVar1;
        LOCK();
        *(uint *)((longlong)param_9 + 0xac) = *(uint *)((longlong)param_9 + 0xac) | 0x20;
        UNLOCK();
      }
      if (*(uint *)(param_3 + 0xb) == 0) {
LAB_14000da3e:
        *(undefined4 *)(local_res18 + 0x15) = 0x10c;
        if (-1 < (int)uVar6) goto LAB_14000da67;
      }
      else {
        puVar7 = (undefined1 *)(ulonglong)*(uint *)((longlong)param_3 + 0x5c);
        param_10 = (undefined1 *)0x0;
        uVar4 = TmpRecoverEnlistmentRecoveryInformation
                          (param_1,param_2,*(uint *)((longlong)param_3 + 0x5c),
                           *(uint *)(param_3 + 0xb),(longlong *)&param_10);
        uVar6 = uVar4 & 0xffffffff;
        if ((int)uVar4 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            uVar5 = 0x12;
LAB_14000dc0a:
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,puVar7,(int)uVar6);
          }
        }
        else {
          puVar7 = param_10;
          uVar3 = ZwSetInformationEnlistment(*plVar2,1,param_10,*(undefined4 *)(param_3 + 0xb));
          uVar6 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) goto LAB_14000da3e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            uVar5 = 0x13;
            goto LAB_14000dc0a;
          }
        }
      }
    }
  }
  if (*plVar2 != 0) {
    ZwClose();
    *plVar2 = 0;
  }
LAB_14000da67:
  if (local_res18 != (longlong *)0x0) {
    ObfDereferenceObject();
  }
  return uVar6;
}



===== TmpRecoverEnlistmentRecoveryInformation @ 14000dc70 =====

undefined8
TmpRecoverEnlistmentRecoveryInformation
          (longlong param_1,uint param_2,uint param_3,uint param_4,longlong *param_5)

{
  undefined8 uVar1;
  
  if (((param_2 < param_3 + param_4) || (param_2 < param_3)) || (param_2 < param_4)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
    }
    uVar1 = 0xc0190030;
  }
  else {
    *param_5 = (ulonglong)param_3 + param_1;
    uVar1 = 0;
  }
  return uVar1;
}



===== TmpRecoverOneEnlistmentRecordFromLogRecord @ 14000dcd8 =====

ulonglong TmpRecoverOneEnlistmentRecordFromLogRecord
                    (int *param_1,uint param_2,undefined8 *param_3,uint *param_4,undefined8 param_5,
                    char param_6,char param_7,undefined8 param_8,longlong param_9,longlong *param_10
                    ,undefined8 *param_11)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  char local_28 [8];
  longlong local_20;
  
  puVar1 = param_11;
  local_20 = 0;
  plVar7 = &local_20;
  param_6 = '\0';
  local_28[0] = '\0';
  puVar5 = param_3;
  puVar6 = param_11;
  uVar3 = TmpRecoverResourceManagerFromEnlistmentRecord
                    (param_1,param_2,(longlong)param_3,param_4,param_8,param_9,param_11,plVar7,
                     local_28);
  lVar2 = local_20;
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,puVar5,(int)uVar3);
    }
  }
  else {
    uVar3 = TmpRecoverEnlistmentFromEnlistmentRecord
                      ((longlong)param_1,param_2,param_3,*puVar1,local_20,param_5,(longlong)puVar6,
                       plVar7,param_10,&param_6);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,(int)uVar3);
      }
      ZwClose(*puVar1);
    }
    else {
      if (param_6 == '\0') {
        if (param_7 != '\0') {
          return 0xc0190053;
        }
      }
      else if ((local_28[0] == '\0') || (param_7 == '\0')) {
        return 0xc0190053;
      }
      ObfDereferenceObject(lVar2);
    }
  }
  return uVar4;
}



===== TmpRecoverResourceManagerFromEnlistmentRecord @ 14000de64 =====

ulonglong TmpRecoverResourceManagerFromEnlistmentRecord
                    (int *param_1,uint param_2,longlong param_3,uint *param_4,undefined8 param_5,
                    longlong param_6,undefined8 *param_7,undefined8 *param_8,undefined1 *param_9)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong local_res18 [2];
  ulonglong in_stack_ffffffffffffff70;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar3 = param_9;
  puVar2 = param_8;
  puVar1 = param_7;
  local_68 = 0x30;
  *param_7 = 0;
  *param_8 = 0;
  local_50 = 0x200;
  puVar7 = (undefined8 *)0x0;
  local_res18[0] = 0;
  local_78 = 0;
  uStack_70 = 0;
  *param_9 = 0;
  local_60 = 0;
  local_58 = 0;
  local_40 = 0;
  uVar5 = TmpFindResourceManagerTm(param_6,param_3 + 0x10,param_8);
  if ((int)uVar5 < 0) {
    uVar5 = TmpRecoverSecurityDescriptor
                      ((longlong)param_1,param_2,*(uint *)(param_3 + 0x6c),*(uint *)(param_3 + 0x68)
                       ,local_res18);
    uVar4 = (uint)(in_stack_ffffffffffffff70 >> 0x20);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    local_48 = local_res18[0];
    if ((((*param_1 == 0x104) && (0x47 < (uint)param_1[9])) && (0x10000000 < (uint)param_1[0xd])) &&
       (*param_4 != 0)) {
      uVar5 = TmpRecoverUnicodeString
                        ((longlong)param_1,param_2,param_4[1],*param_4,(undefined2 *)&local_78);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      puVar7 = &local_78;
    }
    uVar5 = ZwCreateResourceManager
                      (puVar1,0x1f007f,param_5,param_3 + 0x10,&local_68,(ulonglong)uVar4 << 0x20,
                       puVar7);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    param_7 = (undefined8 *)0x0;
    uVar4 = ObReferenceObjectByHandle(*puVar1,2,TmResourceManagerObjectType,0,&param_7,0);
    uVar5 = (ulonglong)uVar4;
    *puVar2 = param_7;
    if ((int)uVar4 < 0) {
      ZwClose(*puVar1);
      *puVar1 = 0;
    }
  }
  else {
    uVar6 = ObOpenObjectByPointer
                      (*puVar2,0x200,0,0x1f007f,TmResourceManagerObjectType,
                       in_stack_ffffffffffffff70 & 0xffffffffffffff00,puVar1);
    uVar5 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    *puVar3 = 1;
  }
  return uVar5;
}



===== TmpRecoverSecurityDescriptor @ 14000e048 =====

undefined8
TmpRecoverSecurityDescriptor
          (longlong param_1,uint param_2,uint param_3,uint param_4,longlong *param_5)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  
  if (((param_2 < param_3 + param_4) || (param_2 < param_4)) || (param_2 < param_3)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0190030;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
      return 0xc0190030;
    }
    uVar3 = 0xc;
  }
  else if (param_4 < 0x28) {
    if (param_4 == 0) {
      *param_5 = 0;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0190030;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
      return 0xc0190030;
    }
    uVar3 = 0xd;
  }
  else {
    *param_5 = param_1 + (ulonglong)param_3;
    cVar1 = RtlValidRelativeSecurityDescriptor(param_1 + (ulonglong)param_3,param_4,0);
    if (cVar1 == '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0190030;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return 0xc0190030;
      }
      uVar3 = 0xe;
    }
    else {
      uVar2 = RtlLengthSecurityDescriptor(*param_5);
      if (uVar2 == param_4) {
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0190030;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return 0xc0190030;
      }
      uVar3 = 0xf;
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
  return 0xc0190030;
}



===== TmpRecoverTransactionFromLogRecord @ 14000e17c =====

ulonglong TmpRecoverTransactionFromLogRecord
                    (int *param_1,uint param_2,char param_3,undefined8 param_4,longlong param_5,
                    undefined8 *param_6,undefined1 *param_7)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong local_res8;
  uint in_stack_ffffffffffffff50;
  undefined8 in_stack_ffffffffffffff58;
  longlong local_88 [10];
  
  uVar2 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  local_88[3] = 0x30;
  local_88[6] = 0x200;
  *param_6 = 0;
  *param_7 = 0;
  plVar5 = (longlong *)0x0;
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_res8 = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[7] = 0;
  local_88[8] = 0;
  uVar3 = TmpNamespaceLookup(param_5 + 0xb0,param_1 + 2,&local_res8);
  lVar1 = local_res8;
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if (param_3 == '\x01') {
      uVar3 = TmpRecoverSecurityDescriptor
                        ((longlong)param_1,param_2,param_1[0xb],param_1[10],local_88);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      local_88[7] = local_88[0];
      if ((((*param_1 == 0x104) && (0x47 < (uint)param_1[9])) && (0x10000000 < (uint)param_1[0xd]))
         && (param_1[0xe] != 0)) {
        uVar3 = TmpRecoverUnicodeString
                          ((longlong)param_1,param_2,param_1[0xf],param_1[0xe],
                           (undefined2 *)(local_88 + 1));
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        plVar5 = local_88 + 1;
      }
      uVar2 = ZwCreateTransaction(param_6,0x1f003f,local_88 + 3,param_1 + 2,param_4,0,
                                  (ulonglong)uVar2 << 0x20,0,0,plVar5);
      uVar4 = (ulonglong)uVar2;
    }
  }
  else {
    uVar3 = ObOpenObjectByPointer
                      (local_res8,0x200,0,0x1f003f,TmTransactionObjectType,
                       in_stack_ffffffffffffff50 & 0xffffff00,param_6);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    *param_7 = 1;
  }
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return uVar4;
}



===== TmpRecoverUnicodeString @ 14000e33c =====

undefined8
TmpRecoverUnicodeString(longlong param_1,uint param_2,uint param_3,uint param_4,undefined2 *param_5)

{
  if (((param_2 < param_3 + param_4) || (param_2 < param_4)) || (param_2 < param_3)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
    }
  }
  else {
    *(ulonglong *)(param_5 + 4) = (ulonglong)param_3 + param_1;
    *param_5 = (short)param_4;
    param_5[1] = (short)param_4;
    if ((param_4 & 0xffff) == param_4) {
      return 0;
    }
  }
  return 0xc0190030;
}



===== WppInitKm @ 14000e3b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
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
  }
  return;
}



===== WppLoadTracingSupport @ 14000e448 =====

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
      MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 14000e590 =====

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



===== TmpLogBufferInitialization @ 14000e818 =====

undefined8 TmpLogBufferInitialization(void)

{
  undefined8 uVar1;
  
  uVar1 = ExInitializePagedLookasideList(&TmpLogWriteLookasideList,0,0,0,0x308,0x6c4c6d54,0);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== TmpTraceTransactionBlockedFreeze @ 14000e860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpTraceTransactionBlockedFreeze(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 auStack_b8 [32];
  longlong *local_98;
  ushort local_88 [8];
  longlong local_78 [2];
  ushort *local_68;
  undefined8 local_60;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (TmpEtwHandle != 0) {
    for (puVar2 = *(undefined8 **)(param_1 + 200); puVar2 != (undefined8 *)(param_1 + 200);
        puVar2 = (undefined8 *)*puVar2) {
      if (*(int *)(puVar2 + 6) == 0x105) {
        lVar1 = puVar2[4];
        local_78[0] = param_1 + 0xb0;
        local_50 = (uint)*(ushort *)(param_1 + 0x130);
        local_68 = local_88;
        local_58 = *(undefined8 *)(param_1 + 0x138);
        local_48 = lVar1 + 0x88;
        local_78[1] = 0x10;
        local_60 = 2;
        local_4c = 0;
        local_40 = 0x10;
        local_88[0] = *(ushort *)(lVar1 + 0x170) >> 1;
        local_38 = local_88;
        local_30 = 2;
        local_28 = *(undefined8 *)(lVar1 + 0x178);
        local_98 = local_78;
        local_20 = (uint)*(ushort *)(lVar1 + 0x170);
        local_1c = 0;
        EtwWrite(TmpEtwHandle,&KTM_ETW_EVENT_TRANSACTION_BLOCKED_FREEZE,0,6);
      }
    }
  }
  return;
}



===== TmpTraceTransactionHeuristicCorruption @ 14000e9c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpTraceTransactionHeuristicCorruption(longlong param_1)

{
  longlong lVar1;
  undefined1 auStack_b8 [32];
  longlong *local_98;
  ushort local_88 [2];
  ushort local_84 [6];
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  ushort *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar1 = *(longlong *)(param_1 + 0x200);
  if (TmpEtwHandle != 0) {
    local_78 = param_1 + 0xb0;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_60 = 2;
    local_88[0] = *(ushort *)(param_1 + 0x130) >> 1;
    local_68 = local_88;
    local_58 = *(undefined8 *)(param_1 + 0x138);
    local_48 = lVar1 + 0x70;
    local_50 = (uint)*(ushort *)(param_1 + 0x130);
    local_70 = 0x10;
    local_40 = 0x10;
    local_2c = 0;
    local_84[0] = *(ushort *)(lVar1 + 0x88) >> 1;
    local_38 = local_84;
    local_30 = 2;
    local_28 = *(undefined8 *)(lVar1 + 0x90);
    local_1c = 0;
    local_98 = &local_78;
    local_20 = (uint)*(ushort *)(lVar1 + 0x88);
    EtwWrite(TmpEtwHandle,&KTM_ETW_EVENT_TRANSACTION_HEURISTIC_CORRUPTION,0,6);
  }
  return;
}



===== TmpTraceTransactionRollbackLogError @ 14000ead0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpTraceTransactionRollbackLogError(longlong param_1,undefined4 param_2)

{
  undefined4 local_res10 [6];
  undefined1 auStack_98 [32];
  longlong *local_78;
  ushort local_68 [8];
  longlong local_58 [2];
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if (TmpEtwHandle != 0) {
    local_58[0] = param_1 + 0xb0;
    local_30 = (uint)*(ushort *)(param_1 + 0x130);
    local_68[0] = *(ushort *)(param_1 + 0x130) >> 1;
    local_48 = local_68;
    local_38 = *(undefined8 *)(param_1 + 0x138);
    local_28 = local_res10;
    local_78 = local_58;
    local_58[1] = 0x10;
    local_40 = 2;
    local_2c = 0;
    local_20 = 4;
    local_res10[0] = param_2;
    EtwWrite(TmpEtwHandle,&KTM_ETW_EVENT_TRANSACTION_ROLLBACK_LOG_ERROR,0);
  }
  return;
}



===== TmPrePrepareComplete @ 14000eba0 =====

void TmPrePrepareComplete(longlong param_1,longlong *param_2)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_18;
  undefined4 local_14;
  code *local_10 [2];
  
                    /* 0xeba0  59  TmPrePrepareComplete */
  local_14 = 0x10a;
  local_10[0] = TmpTxActionDoPrePrepareComplete;
  local_18 = 0x111;
  local_res20[0] = 8;
  local_res18[0] = 2;
  TmpProcessNotificationResponse
            (param_1,param_2,1,(longlong)&local_14,(longlong)&local_18,(longlong)local_res20,
             (longlong)local_10,(longlong)local_res18);
  return;
}



===== TmPrepareEnlistment @ 14000ec10 =====

int TmPrepareEnlistment(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  char *pcVar5;
  
                    /* 0xec10  62  TmPrepareEnlistment */
  lVar2 = *(longlong *)(param_1 + 0xa0);
  lVar3 = *(longlong *)(param_1 + 0x98);
  pcVar5 = "KTM:  TmPrepareTransaction for en %lx\n";
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmPrepareTransaction for en %lx\n",param_1);
  plVar1 = (longlong *)(lVar3 + 0x168);
  if ((param_2 != (longlong *)0x0) && (*plVar1 == 0)) {
    return -0x3fe6ffae;
  }
  TmpAdjustVirtualClock(*plVar1,param_2);
  TmpAcquireTransactionMutex(lVar2);
  if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
    iVar4 = -0x3fe6ffcd;
  }
  else if (((*(uint *)(param_1 + 0xb0) & 0x20) == 0) || ((*(uint *)(param_1 + 0xb0) & 0x40) == 0)) {
    iVar4 = -0x3fe6ffa9;
  }
  else {
    if ((*(uint *)(lVar2 + 0xc4) & 2) == 0) {
      if (*(int *)(lVar2 + 0xc0) == 1) {
        LOCK();
        *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) | 4;
        UNLOCK();
        iVar4 = TmpTxActionDoPrePrepare(lVar2,param_2,pcVar5);
        goto LAB_14000ed0b;
      }
      if (*(int *)(lVar2 + 0xc0) == 0xb) {
        iVar4 = TmpTxActionDoPrepare(lVar2,0);
        goto LAB_14000ed0b;
      }
    }
    iVar4 = -0x3fe6ffed;
  }
LAB_14000ed0b:
  KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  return iVar4;
}



===== TmRecoverEnlistment @ 14000ed30 =====

undefined4 TmRecoverEnlistment(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  undefined4 local_res18;
  int iVar5;
  
                    /* 0xed30  66  TmRecoverEnlistment */
  lVar2 = *(longlong *)(param_1 + 0xa0);
  local_res18 = 0;
  TmpAcquireTransactionMutex(lVar2);
  lVar1 = param_1 + 0x40;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  bVar3 = true;
  if ((((*(uint *)(param_1 + 0xac) & 1) == 0) || ((*(uint *)(lVar2 + 0xc4) >> 0xe & 1) == 0)) ||
     ((*(uint *)(lVar2 + 0xc4) >> 0xd & 1) != 0)) {
    *(undefined8 *)(param_1 + 0xb8) = param_2;
    if (((*(int *)(param_1 + 0xa8) - 0x104U & 0xfffffff6) == 0) &&
       (*(int *)(param_1 + 0xa8) != 0x10d)) {
      iVar5 = *(int *)(lVar2 + 0xc0);
      if (*(longlong *)(lVar2 + 0xf0) == param_1) {
        if (iVar5 != 5) goto LAB_14000eeb6;
        KeReleaseMutex(lVar1,0);
        iVar5 = 0x104;
        uVar4 = 0x40;
      }
      else if (iVar5 == 5) {
        KeReleaseMutex(lVar1,0);
        iVar5 = 0x105;
        uVar4 = 4;
      }
      else if (iVar5 == 6) {
        KeReleaseMutex(lVar1,0);
        iVar5 = 0x10d;
        uVar4 = 8;
      }
      else {
        if (1 < iVar5 - 3U) goto LAB_14000eeb6;
        KeReleaseMutex(lVar1,0);
        iVar5 = 0x102;
        uVar4 = 0x4000;
      }
      bVar3 = false;
      TmpNotifyEnlistment(param_1,'\x01',uVar4,'\x01',iVar5);
    }
    else {
      local_res18 = 0xc0190013;
    }
  }
  else {
    local_res18 = TmpForwardCommitTransaction(lVar2);
  }
LAB_14000eeb6:
  if (bVar3) {
    KeReleaseMutex(lVar1,0);
  }
  KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  return local_res18;
}



===== TmRequestOutcomeEnlistment @ 14000ef00 =====

int TmRequestOutcomeEnlistment(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint7 uVar5;
  longlong lVar4;
  undefined *puVar6;
  uint uVar7;
  int local_38;
  uint local_34;
  
                    /* 0xef00  71  TmRequestOutcomeEnlistment */
  lVar1 = *(longlong *)(param_1 + 0xa0);
  iVar3 = -0x3fe6ffed;
  local_38 = -0x3fe6ffed;
  local_34 = 0;
  lVar2 = *(longlong *)(param_1 + 0x98);
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmRollbackEnlistmentExt for tx %lx\n",lVar1);
  if ((param_2 == (longlong *)0x0) || (*(longlong *)(lVar2 + 0x168) != 0)) {
    TmpAdjustVirtualClock(*(longlong *)(lVar2 + 0x168),param_2);
    TmpAcquireTransactionMutex(lVar1);
    puVar6 = (undefined *)0x0;
    lVar4 = 0;
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
    uVar7 = *(uint *)(*(longlong *)(lVar1 + 0x200) + 0x80) & 0x40;
    if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
      do {
        local_34 = local_34 + 1;
        if (*(int *)(param_1 + 0xa8) - 0x102U < 2) {
          if (((*(code **)(lVar2 + 0x128) != TmpInternalCrmNotification) &&
              ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            puVar6 = (undefined *)(*(longlong *)(param_1 + 0xa0) + 0xb0);
            lVar4 = 0;
            WPP_SF_q_guid__guid_
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,puVar6,lVar1,puVar6,
                       lVar2 + 0x88);
          }
          uVar5 = (uint7)((ulonglong)lVar4 >> 8);
          if ((uVar7 == 0) || (local_34 < 2)) {
            lVar4 = (ulonglong)uVar5 << 8;
          }
          else {
            lVar4 = CONCAT71(uVar5,1);
          }
          local_38 = TmpRequestOutcomeTransaction(lVar1,lVar4,puVar6);
        }
        iVar3 = local_38;
      } while ((uVar7 != 0) && (local_34 < 2));
    }
    KeReleaseMutex(param_1 + 0x40,0);
    KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  }
  else {
    iVar3 = -0x3fe6ffae;
  }
  return iVar3;
}



===== TmSinglePhaseReject @ 14000f0c0 =====

undefined8 TmSinglePhaseReject(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
                    /* 0xf0c0  77  TmSinglePhaseReject */
  lVar2 = *(longlong *)(param_1 + 0xa0);
  lVar3 = *(longlong *)(param_1 + 0x98);
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmRollbackCompleteExt for tx %lx\n",lVar2);
  plVar1 = (longlong *)(lVar3 + 0x168);
  uVar4 = 0;
  if ((param_2 == (longlong *)0x0) || (*plVar1 != 0)) {
    TmpAdjustVirtualClock(*plVar1,param_2);
    TmpAcquireTransactionMutex(lVar2);
    uVar6 = 0;
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
    uVar5 = 0;
    if (*(int *)(param_1 + 0xa8) == 0x108) {
      *(undefined4 *)(param_1 + 0xa8) = 0x100;
      *(int *)(lVar2 + 0xec) = *(int *)(lVar2 + 0xec) + -1;
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) & 0xfffffdff;
      KeReleaseMutex(param_1 + 0x40);
      if ((*(uint *)(*(longlong *)(lVar2 + 0x200) + 0x80) & 0x10) != 0) {
        LOCK();
        *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) | 0x10000;
        UNLOCK();
      }
      LOCK();
      *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) | 4;
      UNLOCK();
      *(undefined4 *)(lVar2 + 0xc0) = 1;
      TmpTxActionDoPrePrepare(lVar2,uVar5,uVar6);
    }
    else {
      KeReleaseMutex();
      uVar4 = 0xc0190014;
    }
    KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  }
  else {
    uVar4 = 0xc0190052;
  }
  return uVar4;
}



===== TmpFindSinglePhaseEnlistment @ 14000f20c =====

longlong TmpFindSinglePhaseEnlistment(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 200);
  lVar2 = lVar1 + -0x78;
  if (((*(uint *)(lVar1 + 0x38) >> 9 & 1) == 0) ||
     ((*(int *)(param_1 + 0xe8) == 1 && ((*(uint *)(lVar1 + 0x34) & 0x10) == 0)))) {
    lVar2 = 0;
  }
  return lVar2;
}



===== TmpRequestOutcomeTransaction @ 14000f244 =====

int TmpRequestOutcomeTransaction(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc0);
  if (iVar1 != 2) {
    if (((char)param_2 == '\0') || (1 < iVar1 - 3U)) {
      if ((*(longlong *)(param_1 + 0xf0) == 0) || (1 < iVar1 - 3U)) {
        return -0x3fe6ffed;
      }
      iVar1 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x20000000,'\0',0);
      return iVar1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      param_3 = &WPP_64356b1a6e0c31583d5a1e3b4a774de6_Traceguids;
      param_2 = 0xb;
      WPP_SF_qq_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                      &WPP_64356b1a6e0c31583d5a1e3b4a774de6_Traceguids,
                      *(undefined8 *)(param_1 + 0x200),(char)param_1,param_1 + 0xb0);
    }
    TmpTraceTransactionHeuristicCorruption(param_1);
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x8000000;
    UNLOCK();
  }
  iVar1 = TmpTxActionDoRollback(param_1,param_2,param_3);
  return iVar1;
}



===== TmGetTransactionId @ 14000f310 =====

void TmGetTransactionId(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0xf310  53  TmGetTransactionId */
  uVar1 = *(undefined8 *)(param_1 + 0xb8);
  *param_2 = *(undefined8 *)(param_1 + 0xb0);
  param_2[1] = uVar1;
  return;
}



===== TmIsKTMCommitCoordinator @ 14000f330 =====

bool TmIsKTMCommitCoordinator(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  
                    /* 0xf330  57  TmIsKTMCommitCoordinator */
  TmpAcquireTransactionMutex(param_1);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x58) + 0xf0);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x58) + 0xc4);
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return (uVar1 >> 10 & 1) == 0 && lVar2 == 0;
}



===== TmSetCurrentTransaction @ 14000f3a0 =====

undefined8 TmSetCurrentTransaction(undefined8 param_1)

{
  undefined8 uVar1;
  
                    /* 0xf3a0  75  TmSetCurrentTransaction */
  uVar1 = 0;
  if (((*(uint *)((longlong)SystemReserved1[0xf] + 0x74) & 0x400) == 0) &&
     (*(longlong *)((longlong)SystemReserved1[0xf] + 0xf0) != 0)) {
    *(undefined8 *)(*(longlong *)((longlong)SystemReserved1[0xf] + 0xf0) + 0x17b8) = param_1;
  }
  else {
    uVar1 = 0xc0000001;
  }
  return uVar1;
}



===== TmThawTransactions @ 14000f3e0 =====

undefined4 TmThawTransactions(void)

{
  undefined4 uVar1;
  
                    /* 0xf3e0  78  TmThawTransactions */
  KeSetEvent(&TmpTransactionFreezeCancelEvent,0,0);
  KeWaitForSingleObject(&TmpFreezeMutex,0,0,0,0);
  KeSetEvent(&TmpTransactionFreezeCancelEvent,0,0);
  if (TmpTransactionsFreezeCancelled == '\0') {
    if (TmpTransactionsFrozen == '\0') {
      uVar1 = 0xc0190045;
    }
    else {
      KeSetEvent(&TmpTransactionThawEvent,0,0);
      KeCancelTimer(&TmpTransactionThawTimer);
      KeResetEvent(&TmpTransactionFreezeCompleteEvent);
      TmpTransactionsFrozen = '\0';
      uVar1 = TmpNamespaceForEach(0x1400084e0,(undefined *)0x0,TmpFreezeThawTransactionManager);
      TmpTransactionsCommittedActive = 0;
    }
  }
  else {
    TmpTransactionsFreezeCancelled = '\0';
    uVar1 = 0;
  }
  KeReleaseMutex(&TmpFreezeMutex,0);
  return uVar1;
}



===== TmpAreAllSubordinatesAvailableTransaction @ 14000f518 =====

undefined1 TmpAreAllSubordinatesAvailableTransaction(longlong param_1)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  uVar3 = 1;
  for (puVar2 = *(undefined8 **)(param_1 + 200); puVar2 != (undefined8 *)(param_1 + 200);
      puVar2 = (undefined8 *)*puVar2) {
    KeWaitForSingleObject(puVar2 + -7,0,0,0,0);
    uVar1 = 0;
    if (*(int *)(puVar2 + 6) != 0x10c) {
      uVar1 = uVar3;
    }
    uVar3 = uVar1;
    KeReleaseMutex(puVar2 + -7);
  }
  return uVar3;
}



===== TmpFinalizeTransactionForcefully @ 14000f5a8 =====

undefined8 TmpFinalizeTransactionForcefully(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  TmpAcquireTransactionMutex(param_1);
  while (plVar2 = *(longlong **)(param_1 + 200), plVar2 != (longlong *)(param_1 + 200)) {
    lVar1 = (longlong)(plVar2 + -0xf);
    ObfReferenceObject(lVar1);
    KeWaitForSingleObject(plVar2 + -7,0,0,0,0);
    TmpFinalizeEnlistment(lVar1);
    KeReleaseMutex(plVar2 + -7);
    ObfDereferenceObject(lVar1);
  }
  TmpFinalizeTransaction(param_1);
  KeSetEvent(param_1,0,0);
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return 0;
}



===== TmpForwardCommitTransaction @ 14000f684 =====

undefined4 TmpForwardCommitTransaction(longlong param_1)

{
  bool bVar1;
  char cVar2;
  longlong lVar3;
  longlong local_res10;
  longlong *local_res18;
  undefined4 local_14;
  
  local_14 = 0xc0190013;
  bVar1 = false;
  TmpAcquireTransactionMutex(param_1);
  if ((*(uint *)(param_1 + 0xc4) >> 0xd & 1) == 0) {
    if (*(int *)(param_1 + 0xc0) == 1) {
      if ((*(uint *)(param_1 + 0xc4) >> 8 & 1) == 0) {
        local_res10 = *(longlong *)(param_1 + 0x110);
      }
      else {
        local_res10 = param_1;
      }
      if (((*(uint *)(local_res10 + 0xc4) >> 8 & 1) != 0) &&
         ((*(uint *)(local_res10 + 0xc4) >> 10 & 1) != 0)) {
        lVar3 = local_res10;
        cVar2 = TmpPromotionsIncomplete(local_res10);
        if (cVar2 != '\0') {
          LOCK();
          *(uint *)(lVar3 + 0xc4) = *(uint *)(lVar3 + 0xc4) | 0x4000;
          UNLOCK();
          local_14 = 0x103;
          goto LAB_14000f7a1;
        }
      }
      local_res18 = (longlong *)(local_res10 + 0x100);
      do {
        if ((local_res18[-2] != 0) && ((*(uint *)(local_res18[-2] + 0xb0) >> 0x1a & 1) != 0)) {
          bVar1 = true;
          local_14 = TmpNotifyEnlistment(local_res18[-2],'\x01',0x4000000,'\x01',0x106);
        }
        local_res18 = (longlong *)*local_res18;
      } while (local_res18 != (longlong *)(local_res10 + 0x100));
      if (bVar1) goto LAB_14000f7a1;
    }
    TmRollbackTransaction(param_1,'\0');
  }
  local_14 = 0xc0190013;
LAB_14000f7a1:
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return local_14;
}



===== TmpFreezeThawTransaction @ 14000f7d0 =====

undefined8 TmpFreezeThawTransaction(longlong param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  
  TmpAcquireTransactionMutex(param_1);
  if (*param_2 == '\0') {
    if (((*(uint *)(param_1 + 0xc4) >> 0x10 & 1) != 0) &&
       ((*(uint *)(param_1 + 0xc4) >> 0x11 & 1) != 0)) {
      TmpTraceTransactionBlockedFreeze(param_1);
    }
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffeffff;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffdffff;
    UNLOCK();
  }
  else if ((*(uint *)(param_1 + 0xc4) & 0x10000) == 0) {
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x10000;
    UNLOCK();
    if (*(int *)(param_1 + 0xc0) == 5) {
      cVar3 = TmpAreAllSubordinatesAvailableTransaction(param_1);
      if (cVar3 != '\0') {
        LOCK();
        *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x20000;
        UNLOCK();
        piVar2 = *(int **)(param_2 + 8);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        if (iVar1 == 0) {
          KeResetEvent(*(undefined8 *)(param_2 + 0x10));
        }
      }
    }
  }
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return 0;
}



===== TmpPromoteTransaction @ 14000f8a8 =====

int TmpPromoteTransaction(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  longlong local_res20;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  longlong local_20;
  
  local_20 = 0;
  local_res20 = 0;
  iVar3 = TmpCreateInternalCrmTransaction(param_1,'\0',param_2,&local_res20,&local_20);
  lVar5 = local_res20;
  puVar8 = auStackY_58;
  if (iVar3 < 0) goto LAB_14000fa78;
  *(longlong *)(local_res20 + 0x2b0) = local_20;
  TmpAcquireTransactionMutex(param_1);
  TmpAcquireTransactionMutex(lVar5);
  if ((*(uint *)(param_1 + 0xc4) >> 10 & 1) == 0) {
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x400;
    UNLOCK();
    if (*(longlong *)(param_1 + 0xf0) != 0) goto LAB_14000f9aa;
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x1000;
    UNLOCK();
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x200;
    UNLOCK();
    *(int *)(param_1 + 0x2b8) = *(int *)(param_1 + 0x2b8) + 1;
    KeResetEvent(param_1 + 0x2c0);
    uVar4 = TmpSendPromotionRequest(param_1);
    puVar8 = auStackY_58;
    if (-1 < (int)uVar4) goto LAB_14000f9aa;
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffdff;
    UNLOCK();
  }
  else {
LAB_14000f9aa:
    lVar2 = local_res20;
    puVar8 = auStackY_58;
    plVar7 = (longlong *)(local_res20 + 0x100);
    lVar5 = param_1 + 0x100;
    plVar6 = *(longlong **)(param_1 + 0x108);
    if (*plVar6 != lVar5) {
      plVar6 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      lVar5 = (*pcVar1)();
      puVar8 = auStackY_50;
    }
    *plVar7 = lVar5;
    plVar7[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar7;
    *(longlong **)(lVar5 + 8) = plVar7;
    *(undefined8 *)(puVar8 + -8) = 0x14000f9e5;
    ObfReferenceObject(lVar2);
    puVar8[0x31] = 1;
    *(longlong *)(lVar2 + 0x110) = param_1;
    *(undefined8 *)(puVar8 + -8) = 0x14000fa00;
    ObfReferenceObject(param_1);
    puVar8[0x30] = 1;
    LOCK();
    *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) | 0x200;
    UNLOCK();
    *(int *)(*(longlong *)(lVar2 + 0x110) + 0x2b8) =
         *(int *)(*(longlong *)(lVar2 + 0x110) + 0x2b8) + 1;
    lVar5 = *(longlong *)(lVar2 + 0x110);
    *(undefined8 *)(puVar8 + -8) = 0x14000fa3f;
    KeResetEvent(lVar5 + 0x2c0);
    LOCK();
    *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) | 0x400;
    UNLOCK();
    *(undefined8 *)(puVar8 + -8) = 0x14000fa59;
    uVar4 = TmpSendPromotionRequest(*(longlong *)(puVar8 + 0x78));
    *(uint *)(puVar8 + 0x34) = uVar4;
    if (-1 < (int)uVar4) {
      iVar3 = 0;
      *(undefined4 *)(puVar8 + 0x34) = 0;
      goto LAB_14000fa78;
    }
    LOCK();
    *(uint *)(lVar2 + 0xc4) = *(uint *)(lVar2 + 0xc4) & 0xfffffdff;
    UNLOCK();
  }
  iVar3 = *(int *)(puVar8 + 0x34);
LAB_14000fa78:
  if (iVar3 < 0) {
    if (puVar8[0x30] != '\0') {
      *(undefined8 *)(puVar8 + -8) = 0x14000fa8d;
      ObfDereferenceObject(param_1);
    }
    if (puVar8[0x31] != '\0') {
      *(undefined8 *)(puVar8 + -8) = 0x14000faa5;
      ObfDereferenceObject(*(undefined8 *)(puVar8 + 0x78));
    }
    if (*(longlong *)(puVar8 + 0x78) != 0) {
      *(undefined8 *)(*(longlong *)(puVar8 + 0x78) + 0x2b0) = 0;
    }
    if (*(longlong *)(puVar8 + 0x38) != 0) {
      *(undefined8 *)(puVar8 + -8) = 0x14000facc;
      ZwClose();
    }
  }
  if (puVar8[0x32] != '\0') {
    lVar5 = *(longlong *)(param_1 + 0x58);
    *(undefined8 *)(puVar8 + -8) = 0x14000fae9;
    KeReleaseMutex(lVar5 + 0x20,0);
  }
  if (puVar8[0x33] != '\0') {
    lVar5 = *(longlong *)(*(longlong *)(puVar8 + 0x78) + 0x58);
    *(undefined8 *)(puVar8 + -8) = 0x14000fb0b;
    KeReleaseMutex(lVar5 + 0x20,0);
  }
  if (-1 < iVar3) {
    *param_3 = *(undefined8 *)(puVar8 + 0x78);
  }
  return iVar3;
}



===== TmpRollbackWorkItem @ 14000fb40 =====

void TmpRollbackWorkItem(longlong param_1)

{
  TmRollbackTransaction(param_1,'\0');
  ObfDereferenceObject(param_1);
  return;
}



===== TmpScheduleRollback @ 14000fb6c =====

undefined8 TmpScheduleRollback(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  
  if (*(longlong *)(param_1 + 0x128) == 0) {
    if (((*(uint *)(param_1 + 0xc4) & 0x20) != 0) &&
       ((cVar2 = KeCancelTimer(param_1 + 0x1a8), cVar2 == '\x01' ||
        (cVar2 = KeRemoveQueueDpc(param_1 + 0x168), cVar2 == '\x01')))) {
      ObfDereferenceObject(param_1);
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xffffffdf;
      UNLOCK();
    }
  }
  else {
    lVar1 = param_1 + 0x1a8;
    if ((*(uint *)(param_1 + 0xc4) & 0x10) == 0) {
      KeInitializeTimer(lVar1);
      KeInitializeDpc(param_1 + 0x168,TmpRollbackDpc,param_1);
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x10;
      UNLOCK();
    }
    if ((*(uint *)(param_1 + 0xc4) & 0x20) != 0) {
      cVar2 = KeCancelTimer(lVar1);
      if (cVar2 == '\0') {
        return 0xc019003c;
      }
      ObfDereferenceObject(param_1);
    }
    ObfReferenceObject(param_1);
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x20;
    UNLOCK();
    KeSetTimer(lVar1,*(undefined8 *)(param_1 + 0x128),param_1 + 0x168);
  }
  return 0;
}



===== TmpSetTransactionProperties @ 14000fc9c =====

int TmpSetTransactionProperties(longlong param_1,int *param_2,uint param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 local_40;
  longlong lStack_38;
  undefined8 local_30;
  int *local_28;
  
  local_30 = 0;
  local_28 = (int *)0x0;
  local_40 = 0;
  lStack_38 = 0;
  if ((((param_3 < 0x20) ||
       (uVar2 = param_2[5],
       ((ulonglong)param_3 - 1) + (longlong)param_2 < (longlong)param_2 + (ulonglong)uVar2 + 0x17))
      || (param_3 < uVar2 + 0x18)) || (0x80 < uVar2)) {
    iVar4 = -0x3ffffff3;
  }
  else {
    lVar5 = TmIsTransactionActive(param_1);
    if (((char)lVar5 == '\0') && (*(int *)(param_1 + 0xc0) != 10)) {
      iVar4 = -0x3fe6fffd;
    }
    else {
      if (uVar2 != 0) {
        local_30._0_4_ = CONCAT22((short)param_2[5],(short)param_2[5]);
        local_28 = param_2 + 6;
      }
      TmpAcquireTransactionMutex(param_1);
      bVar3 = true;
      puVar1 = (undefined8 *)(param_1 + 0x130);
      local_40 = *puVar1;
      lStack_38 = *(longlong *)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = 0;
      iVar4 = RtlDuplicateUnicodeString(0,&local_30,puVar1);
      if (-1 < iVar4) {
        if (lStack_38 != 0) {
          RtlFreeUnicodeString(&local_40);
        }
        bVar3 = false;
        if (*(longlong *)(param_2 + 2) != 0) {
          *(longlong *)(param_1 + 0x128) = *(longlong *)(param_2 + 2);
        }
        uVar6 = TmpScheduleRollback(param_1);
        iVar4 = (int)uVar6;
        if (-1 < iVar4) {
          if (*param_2 != 0) {
            *(int *)(param_1 + 0x120) = *param_2;
          }
          if (param_2[1] != 0) {
            *(int *)(param_1 + 0x124) = param_2[1];
          }
        }
      }
      if (iVar4 < 0) {
        if (bVar3) {
          if (*(longlong *)(param_1 + 0x138) != 0) {
            RtlFreeUnicodeString(puVar1);
          }
          *puVar1 = local_40;
          *(longlong *)(param_1 + 0x138) = lStack_38;
        }
      }
      else if ((bVar3) && (lStack_38 != 0)) {
        RtlFreeUnicodeString(&local_40);
      }
      KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
    }
  }
  return iVar4;
}



===== TmpThawTransactionsWorkRoutine @ 14000fe90 =====

void TmpThawTransactionsWorkRoutine(void)

{
  LOCK();
  TmpTransactionThawWorkItemRef = (undefined *)&TmpTransactionThawWorkItemStatic;
  UNLOCK();
  TmThawTransactions();
  return;
}



===== TmpTxActionDoRollbackComplete @ 14000fec0 =====

undefined4 TmpTxActionDoRollbackComplete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc0) == 7) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,param_3,param_1,param_1 + 0xb0)
      ;
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0xc0) = 6;
    *(undefined4 *)(param_1 + 0x1f8) = 3;
    KeSetEvent(param_1,0);
    TmpNotifyAllEnlistmentsTransaction(param_1,8,uVar2,0x10d);
    if (*(longlong *)(param_1 + 0xf0) != 0) {
      uVar1 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x80,'\x01',0x107);
    }
  }
  return uVar1;
}



===== TmpWaitForTransactionOutcome @ 14000ff88 =====

ulonglong TmpWaitForTransactionOutcome(longlong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = KeWaitForSingleObject(param_1,6,1,0,0);
  if (((int)uVar2 == 0) && (iVar1 = *(int *)(param_1 + 0x1f8), iVar1 != param_2)) {
    if (iVar1 == 3) {
      uVar2 = 0xc0190015;
    }
    else if (iVar1 == 2) {
      uVar2 = 0xc0190016;
    }
    else {
      uVar2 = uVar2 & 0xffffffff;
      if (iVar1 == 4) {
        uVar2 = 0xc0190032;
      }
    }
  }
  return uVar2;
}



===== TmpBindResourceManagerCompletionPort @ 14000fff8 =====

ulonglong TmpBindResourceManagerCompletionPort
                    (longlong param_1,undefined1 param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = ObReferenceObjectByHandle
                    (*param_3,1,*(undefined8 *)IoCompletionObjectType_exref,param_2,local_res18,0);
  if (-1 < (int)uVar2) {
    KeWaitForSingleObject(param_1 + 0x28,0,0,0,0);
    if ((*(uint *)(param_1 + 0x20) & 0x10) == 0) {
      *(undefined8 *)(param_1 + 0x238) = local_res18[0];
      *(undefined8 *)(param_1 + 0x248) = param_4;
      *(undefined8 *)(param_1 + 0x240) = param_3[1];
      lVar1 = param_1 + 0x228;
      *(longlong *)(param_1 + 0x230) = lVar1;
      *(longlong *)lVar1 = lVar1;
      LOCK();
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10;
      UNLOCK();
      KeReleaseMutex(param_1 + 0x28,0);
      uVar2 = uVar2 & 0xffffffff;
    }
    else {
      KeReleaseMutex();
      ObfDereferenceObject(local_res18[0]);
      uVar2 = 0xc0000184;
    }
  }
  return uVar2;
}



===== TmpCaptureOrRequeueNotification @ 1400100fc =====

int TmpCaptureOrRequeueNotification
              (longlong param_1,undefined8 param_2,longlong param_3,void *param_4,uint param_5,
              uint *param_6)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = *(int *)(param_3 + 0x30) + 0x20;
  if (param_5 < uVar2) {
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar2;
    }
    iVar1 = -0x3fffffdd;
  }
  else {
    memcpy(param_4,(void *)(param_3 + 0x18),(ulonglong)uVar2);
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar2;
    }
  }
  if (iVar1 < 0) {
    KeInsertHeadQueue(param_1 + 0x98,param_3);
    KeSetEvent(param_1,0,0);
  }
  return iVar1;
}



===== TmpCompleteNotificationRequestApc @ 1400101d0 =====

void TmpCompleteNotificationRequestApc
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  
  lVar1 = *param_4;
  TmpCompleteNotificationRequestPacket(param_1 + -0x40,lVar1);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(lVar1 + 0x10) = 0;
    }
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== TmpCompleteNotificationRequestPacket @ 140010224 =====

void TmpCompleteNotificationRequestPacket(longlong param_1,longlong param_2)

{
  if (*(int *)(param_1 + 0x1c) == 0) {
    memcpy(*(void **)(param_1 + 0x10),(void *)(param_2 + 0x18),
           (ulonglong)(*(int *)(param_2 + 0x30) + 0x20));
  }
  IoSetIoCompletion(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0xa8),
                    *(undefined8 *)(param_1 + 0xa0),*(int *)(param_1 + 0x1c),
                    *(undefined4 *)(param_1 + 0x20),1);
  ObDereferenceObjectDeferDelete(*(undefined8 *)(param_1 + 0x38));
  ObDereferenceObjectDeferDelete(*(undefined8 *)(param_1 + 0x30));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== TmpGetNotificationResourceManager @ 1400102dc =====

ulonglong TmpGetNotificationResourceManager
                    (longlong param_1,undefined8 param_2,void *param_3,uint param_4,
                    undefined8 param_5,uint *param_6)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  bVar1 = false;
  uVar3 = KeRemoveQueue(param_1 + 0x98,param_2,param_5);
  uVar4 = 0;
  KeWaitForSingleObject(param_1 + 0xd8,0,0,0,0);
  if (*(longlong **)(param_1 + 0xb0) == (longlong *)(param_1 + 0xb0)) {
    KeResetEvent(param_1);
  }
  uVar5 = uVar3;
  if (((uVar3 != 0x102) && (uVar3 != 0xc0)) && (uVar3 != 0x80)) {
    uVar2 = TmpCaptureOrRequeueNotification(param_1,uVar4,uVar3,param_3,param_4,param_6);
    uVar5 = (ulonglong)uVar2;
    uVar6 = uVar3;
    if (-1 < (int)uVar2) {
      bVar1 = true;
    }
  }
  KeReleaseMutex(param_1 + 0xd8,0);
  if (bVar1) {
    if (*(longlong *)(uVar6 + 0x10) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(uVar6 + 0x10) = 0;
    }
    ExFreePoolWithTag(uVar6,0);
  }
  return uVar5 & 0xffffffff;
}



===== TmpGetNotificationResourceManagerAsync @ 140010410 =====

int TmpGetNotificationResourceManagerAsync
              (longlong param_1,undefined1 param_2,longlong param_3,void *param_4,uint param_5,
              uint *param_6)

{
  longlong lVar1;
  byte bVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  longlong *plVar11;
  undefined8 local_res8;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  lVar7 = param_1 + 0x28;
  KeWaitForSingleObject(lVar7,0,0,0);
  lVar1 = param_1 + 0xd8;
  KeWaitForSingleObject(lVar1,0,0,0);
  if (((*(uint *)(param_1 + 0x20) & 0x10) == 0) ||
     (lVar6 = PsGetCurrentProcess(), lVar6 != *(longlong *)(param_1 + 0x248))) {
    KeReleaseMutex(lVar1,0);
    KeReleaseMutex(lVar7,0);
    return -0x3ffffe7c;
  }
  lVar6 = *(longlong *)(param_1 + 0x238);
  ObfReferenceObject(lVar6);
  lVar3 = *(longlong *)(param_1 + 0x240);
  uVar9 = 0;
  KeReleaseMutex(lVar7,0);
  iVar5 = KeReadStateQueue(param_1 + 0x98);
  if (iVar5 == 0) {
    plVar8 = (longlong *)ExAllocatePoolWithQuotaTag(0x208,0xb8,0x524e6d54);
    if (plVar8 != (longlong *)0x0) {
      plVar8[0x14] = param_3;
      bVar2 = *(byte *)((longlong)SystemReserved1[0xf] + 0x24a);
      plVar8[0x16] = 0;
      *(uint *)(plVar8 + 0x13) = (uint)bVar2;
      *(uint *)(plVar8 + 3) = param_5;
      plVar8[2] = (longlong)param_4;
      plVar8[0x15] = lVar3;
      ObfReferenceObject(SystemReserved1[0xf]);
      puVar10 = auStackY_58;
      plVar11 = (longlong *)(param_1 + 0x228);
      plVar8[6] = (longlong)SystemReserved1[0xf];
      plVar8[7] = lVar6;
      lVar7 = *plVar11;
      if (*(longlong **)(lVar7 + 8) != plVar11) {
        pcVar4 = (code *)swi(0x29);
        lVar7 = (*pcVar4)(3);
        puVar10 = auStackY_50;
      }
      *plVar8 = lVar7;
      plVar8[1] = (longlong)plVar11;
      *(longlong **)(lVar7 + 8) = plVar8;
      *plVar11 = (longlong)plVar8;
      *(undefined8 *)(puVar10 + -8) = 0x140010680;
      KeReleaseMutex(lVar1,0);
      return 0x103;
    }
    iVar5 = -0x3fffff66;
  }
  else {
    local_res8 = 0;
    uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),param_2);
    lVar7 = KeRemoveQueue(param_1 + 0x98,uVar9,&local_res8);
    if (*(longlong **)(param_1 + 0xb0) == (longlong *)(param_1 + 0xb0)) {
      KeResetEvent(param_1);
    }
    if (((lVar7 == 0x102) || (lVar7 == 0xc0)) || (lVar7 == 0x80)) {
      iVar5 = (int)lVar7;
    }
    else {
      iVar5 = TmpCaptureOrRequeueNotification(param_1,uVar9,lVar7,param_4,param_5,param_6);
      if (-1 < iVar5) {
        if (*(longlong *)(lVar7 + 0x10) != 0) {
          ObfDereferenceObject();
          *(undefined8 *)(lVar7 + 0x10) = 0;
        }
        ExFreePoolWithTag(lVar7,0);
      }
    }
  }
  KeReleaseMutex(lVar1,0);
  ObfDereferenceObject(lVar6);
  return iVar5;
}



===== TmpNotifyResourceManagerTmOnline @ 1400106e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 TmpNotifyResourceManagerTmOnline(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  uint local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar1 = 0;
  local_28 = 0;
  uVar2 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeWaitForSingleObject(param_1 + 8);
  if (*(int *)(param_1 + 0x40) == 3) {
    local_38 = *(undefined8 *)(param_1 + 0x70);
    uStack_30 = *(undefined8 *)(param_1 + 0x78);
    local_28 = *(uint *)(param_1 + 0x80) >> 8 & 1;
    uVar1 = TmpSetNotificationResourceManager(param_2,uVar2,0,0,0x2000000,0x14,&local_38);
  }
  KeReleaseMutex(param_1 + 8,0);
  return uVar1;
}



===== TmpQueueCompletionNotificationRequest @ 1400107b0 =====

void TmpQueueCompletionNotificationRequest
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  KeInitializeApc(param_1 + 0x40,*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x98),
                  TmpCompleteNotificationRequestApc,0,0,0,0);
  KeInsertQueueApc(param_1 + 0x40,param_3,0,0);
  return;
}



===== TmpRundownResourceManagerNotificationRequests @ 140010828 =====

void TmpRundownResourceManagerNotificationRequests(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  local_18 = 0;
  KeWaitForSingleObject(param_1 + 0xd8,0,0,0);
  puVar5 = auStack_38;
  plVar4 = (longlong *)(param_1 + 0x228);
  do {
    plVar1 = (longlong *)*plVar4;
    if (plVar1 == plVar4) {
LAB_140010895:
      *(undefined8 *)(puVar5 + -8) = 0x1400108a1;
      KeReleaseMutex(param_1 + 0xd8,0);
      return;
    }
    if (((longlong *)plVar1[1] != plVar4) ||
       (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar5 = auStack_30;
      goto LAB_140010895;
    }
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    *(undefined4 *)((longlong)plVar1 + 0x1c) = 0xc0000120;
    TmpCompleteNotificationRequestPacket((longlong)plVar1,0);
  } while( true );
}



===== NtCommitComplete @ 1400108c0 =====

int NtCommitComplete(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x108c0  3  NtCommitComplete */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmCommitComplete(local_res18[0],local_18);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtCommitEnlistment @ 140010990 =====

int NtCommitEnlistment(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x10990  4  NtCommitEnlistment */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,0x10,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmCommitEnlistment(local_res18[0],local_18);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtOpenEnlistment @ 140010a60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140010b68) */

ulonglong NtOpenEnlistment(undefined8 *param_1,int param_2,undefined8 param_3,undefined8 *param_4,
                          longlong param_5)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_d8 [32];
  longlong *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  char local_98;
  uint local_94;
  longlong local_90;
  longlong local_88;
  undefined4 local_80;
  undefined8 local_78;
  longlong local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x10a60  13  NtOpenEnlistment */
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  local_90 = CONCAT44(local_90._4_4_,param_2);
  local_58 = 0;
  uStack_50 = 0;
  local_70 = 0;
  local_88 = 0;
  local_78 = 0;
  local_94 = 0;
  uVar5 = 0;
  local_80 = 0;
  if ((param_2 == 0) || (param_4 == (undefined8 *)0x0)) {
    uVar3 = 0xc000000d;
  }
  else {
    cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    local_98 = cVar1;
    local_68 = param_1;
    local_60 = param_3;
    if (cVar1 == '\0') {
      local_58 = *param_4;
      uStack_50 = param_4[1];
      if (param_5 != 0) {
        uVar5 = *(undefined4 *)(param_5 + 0x18);
      }
    }
    else {
      puVar4 = param_1;
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
        puVar4 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      *puVar4 = *puVar4;
      if (((ulonglong)param_4 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_58 = *param_4;
      uStack_50 = param_4[1];
    }
    local_90 = 0;
    local_b0 = 0;
    local_b8 = &local_90;
    local_94 = ObReferenceObjectByHandle(param_3,1,TmResourceManagerObjectType,cVar1);
    lVar2 = local_90;
    uVar3 = (ulonglong)local_94;
    local_70 = local_90;
    if (-1 < (int)local_94) {
      uVar3 = TmpFindEnlistmentResourceManager(local_90,&local_58,&local_88);
      local_94 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (-1 < (int)local_94) {
        local_a8 = &local_78;
        local_b0 = CONCAT71(local_b0._1_7_,cVar1);
        local_b8 = TmEnlistmentObjectType;
        local_94 = ObOpenObjectByPointer(local_88,uVar5,0,param_2);
        uVar3 = (ulonglong)local_94;
        if (-1 < (int)local_94) {
          *param_1 = local_78;
        }
      }
    }
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
    }
    if (local_88 != 0) {
      ObfDereferenceObject();
    }
  }
  return uVar3;
}



===== NtPrePrepareComplete @ 140010ca0 =====

int NtPrePrepareComplete(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  longlong local_30;
  longlong local_28;
  longlong *local_20;
  code *local_18 [2];
  
                    /* 0x10ca0  17  NtPrePrepareComplete */
  local_30 = 0;
  local_20 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_30 = *param_2;
    local_20 = &local_30;
  }
  local_28 = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),&local_28,0);
  lVar1 = local_28;
  if (-1 < iVar2) {
    local_38[0] = 0x10a;
    local_res20[0] = 0x111;
    local_res18[0] = 8;
    local_18[0] = TmpTxActionDoPrePrepareComplete;
    local_res10[0] = 2;
    iVar2 = TmpProcessNotificationResponse
                      (local_28,local_20,1,(longlong)local_38,(longlong)local_res20,
                       (longlong)local_res18,(longlong)local_18,(longlong)local_res10);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtPrePrepareEnlistment @ 140010de0 =====

int NtPrePrepareEnlistment(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x10de0  18  NtPrePrepareEnlistment */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,0x10,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmPrePrepareEnlistment(local_res18[0],local_18);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtPrepareComplete @ 140010eb0 =====

int NtPrepareComplete(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  longlong local_30;
  longlong local_28;
  longlong *local_20;
  code *local_18 [2];
  
                    /* 0x10eb0  19  NtPrepareComplete */
  local_30 = 0;
  local_20 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_30 = *param_2;
    local_20 = &local_30;
  }
  local_28 = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),&local_28,0);
  lVar1 = local_28;
  if (-1 < iVar2) {
    local_38[0] = 0x101;
    local_res20[0] = 0x102;
    local_res18[0] = 2;
    local_18[0] = TmpTxActionDoPrepareComplete;
    local_res10[0] = 0;
    iVar2 = TmpProcessNotificationResponse
                      (local_28,local_20,1,(longlong)local_38,(longlong)local_res20,
                       (longlong)local_res18,(longlong)local_18,(longlong)local_res10);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtPrepareEnlistment @ 140010ff0 =====

int NtPrepareEnlistment(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x10ff0  20  NtPrepareEnlistment */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,0x10,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmPrepareEnlistment(local_res18[0],local_18);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtQueryInformationEnlistment @ 1400110c0 =====

int NtQueryInformationEnlistment
              (undefined8 param_1,uint param_2,undefined8 *param_3,uint param_4,undefined4 *param_5)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int iVar10;
  longlong local_68;
  longlong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
                    /* 0x110c0  23  NtQueryInformationEnlistment */
  local_60 = 0;
  uStack_58 = 0;
  if (param_2 < 3) {
    if (((param_2 == 0) && (param_4 != 0x30)) || ((param_2 == 2 && (param_4 != 0x30)))) {
      iVar7 = -0x3ffffffc;
    }
    else {
      cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
      if ((cVar1 != '\0') && (ProbeForWrite(param_3,param_4,4), param_5 != (undefined4 *)0x0)) {
        puVar8 = param_5;
        if (*(undefined4 **)MmUserProbeAddress_exref <= param_5) {
          puVar8 = *(undefined4 **)MmUserProbeAddress_exref;
        }
        *puVar8 = *puVar8;
      }
      local_68 = 0;
      uVar9 = 0;
      iVar7 = ObReferenceObjectByHandle(param_1,1,TmEnlistmentObjectType,cVar1,&local_68,0);
      lVar6 = local_68;
      if (-1 < iVar7) {
        local_60 = local_68 + 0x40;
        iVar10 = iVar7;
        KeWaitForSingleObject(local_60,0,0,0,0,uVar9,iVar7,local_68);
        if (param_2 == 0) {
          uVar9 = *(undefined8 *)(lVar6 + 0x38);
          uVar2 = *(undefined8 *)(*(longlong *)(lVar6 + 0xa0) + 0xb0);
          uVar3 = *(undefined8 *)(*(longlong *)(lVar6 + 0xa0) + 0xb8);
          uVar4 = *(undefined8 *)(*(longlong *)(lVar6 + 0x98) + 0x88);
          uVar5 = *(undefined8 *)(*(longlong *)(lVar6 + 0x98) + 0x90);
          *param_3 = *(undefined8 *)(lVar6 + 0x30);
          param_3[1] = uVar9;
          param_3[2] = uVar2;
          param_3[3] = uVar3;
          param_3[4] = uVar4;
          param_3[5] = uVar5;
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = 0x30;
          }
        }
        else if (param_2 == 1) {
          if (param_4 < *(uint *)(lVar6 + 0xd0)) {
            iVar7 = -0x3fffffdd;
          }
          else {
            memcpy(param_3,*(void **)(lVar6 + 200),(ulonglong)*(uint *)(lVar6 + 0xd0));
          }
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = *(undefined4 *)(lVar6 + 0xd0);
          }
        }
        else if (param_2 == 2) {
          local_50 = 0;
          uStack_48 = 0;
          local_40 = 0;
          uStack_38 = 0;
          local_30 = 0;
          uStack_28 = 0;
          if ((*(uint *)(lVar6 + 0xac) & 0x20) != 0) {
            local_50 = *(undefined8 *)(lVar6 + 0x118);
            uStack_48 = *(undefined8 *)(lVar6 + 0x120);
            local_40 = *(undefined8 *)(lVar6 + 0x128);
            uStack_38 = *(undefined8 *)(lVar6 + 0x130);
            local_30 = *(undefined8 *)(lVar6 + 0x108);
            uStack_28 = *(undefined8 *)(lVar6 + 0x110);
          }
          *param_3 = local_50;
          param_3[1] = uStack_48;
          param_3[2] = local_40;
          param_3[3] = uStack_38;
          param_3[4] = local_30;
          param_3[5] = uStack_28;
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = 0x30;
          }
          iVar7 = iVar10;
        }
        KeReleaseMutex(local_60,0);
        ObfDereferenceObject(lVar6);
      }
    }
  }
  else {
    iVar7 = -0x3ffffffd;
  }
  return iVar7;
}



===== NtReadOnlyEnlistment @ 140011360 =====

ulonglong NtReadOnlyEnlistment(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x11360  27  NtReadOnlyEnlistment */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  uVar3 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < (int)uVar3) {
    uVar2 = TmReadOnlyEnlistment(local_res18[0],local_18);
    uVar3 = (ulonglong)uVar2;
    ObfDereferenceObject(lVar1);
  }
  return uVar3;
}



===== NtRecoverEnlistment @ 140011430 =====

ulonglong NtRecoverEnlistment(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res18 [2];
  
                    /* 0x11430  28  NtRecoverEnlistment */
  local_res18[0] = 0;
  uVar3 = ObReferenceObjectByHandle
                    (param_1,4,TmEnlistmentObjectType,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < (int)uVar3) {
    uVar2 = TmRecoverEnlistment(local_res18[0],param_2);
    ObfDereferenceObject(lVar1);
    uVar3 = (ulonglong)uVar2;
  }
  return uVar3;
}



===== NtRollbackComplete @ 1400114c0 =====

ulonglong NtRollbackComplete(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x114c0  33  NtRollbackComplete */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  uVar3 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < (int)uVar3) {
    uVar2 = TmRollbackComplete(local_res18[0],local_18);
    uVar3 = (ulonglong)uVar2;
    ObfDereferenceObject(lVar1);
  }
  return uVar3;
}



===== NtRollbackEnlistment @ 140011590 =====

int NtRollbackEnlistment(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x11590  34  NtRollbackEnlistment */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmRollbackEnlistment(local_res18[0],local_18);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== NtSetInformationEnlistment @ 140011660 =====

int NtSetInformationEnlistment(undefined8 param_1,int param_2,void *param_3,uint param_4)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  void *_Dst;
  undefined4 in_register_0000008c;
  longlong local_30;
  longlong local_28;
  
                    /* 0x11660  37  NtSetInformationEnlistment */
  bVar3 = false;
  bVar2 = false;
  local_28 = 0;
  if (param_2 != 1) {
    return -0x3ffffffd;
  }
  if (param_4 == 0) {
    return -0x3ffffff3;
  }
  if (0x10000 < param_4) {
    return -0x3ffffbf0;
  }
  local_30 = 0;
  iVar5 = ObReferenceObjectByHandle
                    (param_1,2,TmEnlistmentObjectType,
                     CONCAT71((int7)(CONCAT44(in_register_0000008c,param_4) >> 8),
                              *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232)),&local_30,0);
  lVar4 = local_30;
  if (-1 < iVar5) {
    lVar1 = *(longlong *)(local_30 + 0xa0);
    local_28 = lVar1;
    TmpAcquireTransactionMutex(lVar1);
    bVar2 = true;
    KeWaitForSingleObject(lVar4 + 0x40,0,0,0,0);
    bVar3 = true;
    lVar6 = TmIsTransactionActive(lVar1);
    if (((char)lVar6 == '\0') && (*(int *)(lVar1 + 0xc0) != 10)) {
      iVar5 = -0x3fe6fffd;
    }
    else {
      if (*(longlong *)(lVar4 + 200) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar4 + 200),0);
        *(undefined8 *)(lVar4 + 200) = 0;
        *(undefined4 *)(lVar4 + 0xd0) = 0;
      }
      _Dst = (void *)ExAllocatePoolWithQuotaTag(9,(ulonglong)param_4,0x69526d54);
      *(void **)(lVar4 + 200) = _Dst;
      if (_Dst == (void *)0x0) {
        iVar5 = -0x3fffff66;
      }
      else {
        *(uint *)(lVar4 + 0xd0) = param_4;
        memcpy(_Dst,param_3,(ulonglong)param_4);
      }
    }
  }
  if (bVar2) {
    KeReleaseMutex(*(longlong *)(local_28 + 0x58) + 0x20,0);
  }
  if (bVar3) {
    KeReleaseMutex(lVar4 + 0x40,0);
  }
  if (lVar4 != 0) {
    ObfDereferenceObject(lVar4);
  }
  return iVar5;
}



===== NtSinglePhaseReject @ 1400118d0 =====

ulonglong NtSinglePhaseReject(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x118d0  41  NtSinglePhaseReject */
  local_res10 = 0;
  local_18 = param_2;
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) != '\0') && (param_2 != (longlong *)0x0)) {
    if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
      param_2 = *(longlong **)MmUserProbeAddress_exref;
    }
    local_res10 = *param_2;
    local_18 = &local_res10;
  }
  local_res18[0] = 0;
  uVar2 = ObReferenceObjectByHandle
                    (param_1,8,TmEnlistmentObjectType,
                     *(char *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < (int)uVar2) {
    uVar2 = TmSinglePhaseReject(local_res18[0],local_18);
    uVar2 = uVar2 & 0xffffffff;
    ObfDereferenceObject(lVar1);
  }
  return uVar2;
}



===== NtGetNotificationResourceManager @ 1400119a0 =====

int NtGetNotificationResourceManager
              (undefined8 param_1,void *param_2,uint param_3,undefined8 *param_4,uint *param_5,
              int param_6,longlong param_7)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined8 *local_38;
  undefined8 local_30;
  longlong local_28 [2];
  
                    /* 0x119a0  12  NtGetNotificationResourceManager */
  local_30 = 0;
  local_38 = (undefined8 *)0x0;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (cVar1 == '\0') {
    local_38 = (undefined8 *)0x0;
    if (param_4 != (undefined8 *)0x0) {
      local_38 = param_4;
    }
  }
  else {
    ProbeForWrite(param_2,param_3,8);
    if (param_4 != (undefined8 *)0x0) {
      local_38 = &local_30;
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_4) {
        param_4 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      local_30 = *param_4;
    }
    if (param_5 != (uint *)0x0) {
      puVar5 = param_5;
      if (*(uint **)MmUserProbeAddress_exref <= param_5) {
        puVar5 = *(uint **)MmUserProbeAddress_exref;
      }
      *puVar5 = *puVar5;
    }
  }
  local_28[0] = 0;
  uVar6 = 0;
  iVar3 = ObReferenceObjectByHandle(param_1,0x10,TmResourceManagerObjectType,cVar1,local_28,0);
  lVar2 = local_28[0];
  if (-1 < iVar3) {
    if (param_6 == 0) {
      uVar4 = TmpGetNotificationResourceManager
                        (local_28[0],CONCAT71((int7)((ulonglong)uVar6 >> 8),cVar1),param_2,param_3,
                         local_38,param_5);
      iVar3 = (int)uVar4;
    }
    else {
      iVar3 = TmpGetNotificationResourceManagerAsync
                        (local_28[0],cVar1,param_7,param_2,param_3,param_5);
    }
    ObfDereferenceObject(lVar2);
  }
  return iVar3;
}



===== NtOpenResourceManager @ 140011b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NtOpenResourceManager
                    (undefined8 *param_1,int param_2,undefined8 param_3,undefined8 *param_4,
                    longlong param_5)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined1 auStack_b8 [32];
  longlong *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  uint local_78;
  longlong local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
                    /* 0x11b20  14  NtOpenResourceManager */
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  local_60 = 0;
  local_58 = 0;
  local_70 = 0;
  uVar7 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if ((param_2 == 0) || (param_4 == (undefined8 *)0x0)) {
    uVar6 = 0xc000000d;
  }
  else {
    cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    if (cVar1 == '\0') {
      local_50 = *param_4;
      uStack_48 = param_4[1];
      if (param_5 != 0) {
        uVar7 = *(undefined4 *)(param_5 + 0x18);
      }
    }
    else {
      puVar5 = param_1;
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
        puVar5 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      *puVar5 = *puVar5;
      if (((ulonglong)param_4 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_50 = *param_4;
      uStack_48 = param_4[1];
    }
    local_68 = 0;
    local_90 = 0;
    local_98 = &local_68;
    local_78 = ObReferenceObjectByHandle(param_3,1,TmTransactionManagerObjectType,cVar1);
    lVar2 = local_68;
    uVar6 = (ulonglong)local_78;
    local_58 = local_68;
    if (-1 < (int)local_78) {
      lVar4 = local_68;
      bVar3 = TmpIsOnlineTransactionManager(local_68);
      if (bVar3) {
        uVar6 = TmpFindResourceManagerTm(lVar4,&local_50,&local_70);
        local_78 = (uint)uVar6;
        uVar6 = uVar6 & 0xffffffff;
        if (-1 < (int)local_78) {
          local_88 = &local_60;
          local_90 = CONCAT71(local_90._1_7_,cVar1);
          local_98 = TmResourceManagerObjectType;
          local_78 = ObOpenObjectByPointer(local_70,uVar7,0,param_2);
          uVar6 = (ulonglong)local_78;
          if (-1 < (int)local_78) {
            *param_1 = local_60;
          }
        }
      }
      else {
        uVar6 = 0xc0190052;
        local_78 = 0xc0190052;
      }
    }
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
    }
    if (local_70 != 0) {
      ObfDereferenceObject();
    }
  }
  return uVar6;
}



===== NtQueryInformationResourceManager @ 140011d30 =====

ulonglong NtQueryInformationResourceManager
                    (undefined8 param_1,int param_2,undefined8 *param_3,uint param_4,uint *param_5)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong local_38;
  longlong local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x11d30  24  NtQueryInformationResourceManager */
  local_30 = 0;
  uStack_28 = 0;
  uVar9 = 0;
  if (param_2 == 0) {
    cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    if ((cVar1 != '\0') && (ProbeForWrite(param_3,param_4,4), param_5 != (uint *)0x0)) {
      puVar6 = param_5;
      if (*(uint **)MmUserProbeAddress_exref <= param_5) {
        puVar6 = *(uint **)MmUserProbeAddress_exref;
      }
      *puVar6 = *puVar6;
    }
    local_38 = 0;
    uVar8 = 0;
    uVar4 = ObReferenceObjectByHandle(param_1,1,TmResourceManagerObjectType,cVar1,&local_38,0);
    lVar2 = local_38;
    uVar7 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      local_30 = local_38 + 0x28;
      KeWaitForSingleObject(local_30,0,0,0,0,uVar8,uVar9,local_38);
      if (param_4 < 0x18) {
        uVar4 = 0xc0000023;
      }
      else {
        local_20 = *(undefined8 *)(lVar2 + 0x88);
        uStack_18 = *(undefined8 *)(lVar2 + 0x90);
        local_10 = (ulonglong)*(ushort *)(lVar2 + 0x170);
        *param_3 = local_20;
        param_3[1] = uStack_18;
        param_3[2] = local_10;
        uVar5 = *(ushort *)(lVar2 + 0x170) + 0x14;
        uVar9 = uVar5;
        if (uVar5 < 0x18) {
          uVar9 = 0x18;
        }
        if (param_4 < uVar5) {
          uVar7 = 0x80000005;
        }
        uVar3 = param_4 - 0x14;
        if (param_4 >= uVar5) {
          uVar3 = (uint)*(ushort *)(lVar2 + 0x170);
        }
        memcpy((void *)((longlong)param_3 + 0x14),*(void **)(lVar2 + 0x178),(ulonglong)uVar3);
        uVar4 = uVar7;
      }
      KeReleaseMutex(local_30,0);
      ObfDereferenceObject(lVar2);
      if (param_5 != (uint *)0x0) {
        *param_5 = uVar9;
      }
    }
  }
  else {
    uVar4 = 0xc0000003;
  }
  return uVar4;
}



===== NtSetInformationResourceManager @ 140011f30 =====

ulonglong NtSetInformationResourceManager
                    (undefined8 param_1,int param_2,undefined8 *param_3,int param_4)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong local_58;
  undefined8 *local_50;
  undefined8 *local_48;
  ulonglong local_40;
  ulonglong local_38;
  
                    /* 0x11f30  38  NtSetInformationResourceManager */
  local_48 = (undefined8 *)0x0;
  local_50 = (undefined8 *)0x0;
  local_58 = local_58 & 0xffffffff00000000;
  if (param_2 == 1) {
    if (param_4 == 0x10) {
      cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
      if (cVar1 == '\0') {
        local_48 = param_3;
      }
      else {
        local_50 = TmpProbeAndCaptureBuffer(param_3,0x10,4);
        local_48 = local_50;
        if ((int)local_58 < 0) {
          return local_58 & 0xffffffff;
        }
      }
      puVar4 = local_48;
      puVar3 = local_50;
      local_58 = 0;
      uVar6 = ObReferenceObjectByHandle(param_1,0x10,TmResourceManagerObjectType,cVar1,&local_58,0);
      uVar2 = local_58;
      uVar7 = (ulonglong)uVar6;
      local_38 = local_58;
      if (-1 < (int)uVar6) {
        KeWaitForSingleObject(local_58 + 0x28,0,0,0,0);
        local_40 = 0;
        uVar6 = ObReferenceObjectByHandle
                          (param_1,0x10,TmResourceManagerObjectType,cVar1,&local_40,0);
        uVar5 = local_40;
        uVar7 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
          if (local_40 == uVar2) {
            uVar8 = PsGetCurrentProcess();
            uVar7 = TmpBindResourceManagerCompletionPort(uVar2,cVar1,puVar4,uVar8);
            uVar7 = uVar7 & 0xffffffff;
            ObfDereferenceObject(uVar5);
          }
          else {
            ObfDereferenceObject(local_40);
            uVar7 = 0xc0000008;
          }
        }
        KeReleaseMutex(uVar2 + 0x28,0);
        ObfDereferenceObject(uVar2);
      }
      if (puVar3 != (undefined8 *)0x0) {
        ExFreePoolWithTag(puVar3,0);
      }
    }
    else {
      uVar7 = 0xc0000004;
    }
  }
  else {
    uVar7 = 0xc0000003;
  }
  return uVar7;
}



===== TmRenameTransactionManager @ 140012140 =====

int TmRenameTransactionManager(ushort *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res8 [4];
  undefined4 local_res18 [2];
  longlong local_res20;
  longlong *plVar3;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined4 uVar8;
  undefined8 in_stack_ffffffffffffff80;
  uint uVar9;
  undefined8 local_50;
  longlong local_48;
  longlong local_40 [3];
  undefined2 local_28;
  short local_26;
  undefined4 local_24;
  longlong local_20;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
                    /* 0x12140  70  TmRenameTransactionManager */
  uVar9 = (uint)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  local_24 = 0;
  local_50 = 0;
  local_res20 = 0;
  local_48 = 0;
  local_res8[0] = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_res18[0] = 0;
  local_40[2] = *(longlong *)CLFS_LSN_NULL_exref;
  if ((uint)*param_1 + (uint)TmpLogPrefix < 0x10000) {
    local_28 = 0;
    local_26 = *param_1 + TmpLogPrefix;
    local_20 = ExAllocatePoolWithQuotaTag(9,local_26,0x6e4c6d54);
    if (local_20 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      RtlCopyUnicodeString(&local_28,0);
      RtlAppendUnicodeStringToString(&local_28,&TmpLogPrefix);
      RtlAppendUnicodeStringToString(&local_28,param_1);
      uVar6 = CONCAT44(uVar7,8);
      uVar4 = CONCAT44(uVar5,1);
      uVar5 = 0;
      iVar1 = ClfsCreateLogFile(&local_50,&local_28,0xc0000000,1,0,uVar4,uVar6,
                                (ulonglong)uVar9 << 0x20,0,0,0);
      uVar7 = (undefined4)((ulonglong)uVar4 >> 0x20);
      uVar8 = (undefined4)((ulonglong)uVar6 >> 0x20);
      if (iVar1 < 0) {
        ExFreePoolWithTag();
      }
      else {
        ExFreePoolWithTag(local_20,0);
        local_20 = 0;
        iVar1 = ClfsCreateMarshallingArea
                          (local_50,1,0,0,CONCAT44(uVar5,0x10000),CONCAT44(uVar7,0x14),
                           CONCAT44(uVar8,1),&local_res20);
        if (-1 < iVar1) {
          plVar3 = local_40;
          iVar1 = ClfsReadRestartArea(local_res20,&local_48,local_res8,local_40 + 1,plVar3);
          if (iVar1 == 0x401a000c) {
            iVar1 = -0x3fe6ffd0;
          }
          if ((-1 < iVar1) && (local_48 != 0)) {
            lVar2 = *(longlong *)(local_48 + 0xc) - *param_2;
            if (lVar2 == 0) {
              lVar2 = *(longlong *)(local_48 + 0x14) - param_2[1];
            }
            if (lVar2 == 0) {
              ExUuidCreate(local_48 + 0xc);
              iVar1 = ClfsWriteRestartArea
                                (local_res20,local_48,0x20,0,(ulonglong)plVar3 & 0xffffffff00000000,
                                 local_res18,local_40 + 2);
            }
            else {
              iVar1 = -0x3fe6ffa4;
            }
          }
        }
        if (local_40[0] != 0) {
          ClfsTerminateReadLog();
        }
        if (local_res20 != 0) {
          ClfsDeleteMarshallingArea();
        }
        ClfsCloseLogFileObject(local_50);
      }
    }
  }
  else {
    iVar1 = -0x7ffffffb;
  }
  return iVar1;
}



===== TmpCheckForProgressTransactionManager @ 140012428 =====

undefined8 TmpCheckForProgressTransactionManager(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  
  ExAcquireResourceExclusiveLite(param_1 + 0x310,1);
  cVar2 = ClfsLsnGreater((undefined8 *)(param_1 + 0x288),(undefined8 *)(param_1 + 0x388));
  if (cVar2 == '\0') {
    plVar1 = *(longlong **)(param_1 + 0x238);
    if (plVar1 != (longlong *)(param_1 + 0x238)) {
      TmpTraceTransactionManagerNotAdvancingTail(param_1,(longlong)(plVar1 + -0x3d));
    }
  }
  else {
    *(undefined8 *)(param_1 + 0x388) = *(undefined8 *)(param_1 + 0x288);
  }
  ExReleaseResourceLite(param_1 + 0x310);
  KeReleaseMutex(param_1 + 8,0);
  return 0;
}



===== TmpCreateInternalCrmTransaction @ 1400124e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpCreateInternalCrmTransaction
              (longlong param_1,char param_2,longlong param_3,longlong *param_4,longlong *param_5)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_108 [32];
  longlong *local_e8;
  ulonglong local_e0;
  longlong **local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  short *local_c0;
  undefined1 local_b8 [4];
  int local_b4;
  longlong local_b0;
  longlong *local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  local_60 = local_60 & 0xffffffff00000000;
  local_a8 = (longlong *)0x0;
  local_b4 = 0;
  local_a0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_b8[0] = 0;
  lVar2 = 0;
  local_98 = 0;
  local_b0 = 0;
  iVar1 = ObGetObjectSecurity(0,&local_a0,local_b8);
  local_b4 = iVar1;
  if (-1 < iVar1) {
    local_d8 = &local_a8;
    local_e0 = local_e0 & 0xffffffffffffff00;
    local_e8 = TmTransactionManagerObjectType;
    iVar1 = ObOpenObjectByPointer(param_3,0x200,0,0xf003f);
    local_b4 = iVar1;
    if (-1 < iVar1) {
      local_88 = CONCAT44(local_88._4_4_,0x30);
      uStack_80 = 0;
      uStack_70 = CONCAT44(uStack_70._4_4_,0x200);
      local_78 = 0;
      local_68 = local_a0;
      local_60 = 0;
      if (param_2 == '\0') {
        local_58 = *(undefined8 *)(param_1 + 0xb0);
        uStack_50 = *(undefined8 *)(param_1 + 0xb8);
      }
      else {
        ExUuidCreate(&local_58);
      }
      local_c0 = (short *)(param_1 + 0x130);
      if (*local_c0 == 0) {
        local_c0 = (short *)0x0;
      }
      local_c8 = 0;
      local_d0 = 0;
      local_d8 = (longlong **)((ulonglong)local_d8 & 0xffffffff00000000);
      local_e0 = local_e0 & 0xffffffff00000000;
      local_e8 = local_a8;
      iVar1 = ZwCreateTransaction(&local_b0,0x1f003f,&local_88,&local_58);
      local_b4 = iVar1;
      if (-1 < iVar1) {
        local_90 = 0;
        local_e0 = 0;
        local_e8 = &local_90;
        iVar1 = ObReferenceObjectByHandle(local_b0,0,TmTransactionObjectType,0);
        lVar2 = local_90;
        local_98 = local_90;
        local_b4 = iVar1;
        if ((-1 < iVar1) && (*(longlong *)(local_90 + 0x2b0) = local_b0, param_2 != '\0')) {
          TmpNamespaceReplace(param_3 + 0xb0,param_3,param_1,local_90);
          *(undefined8 *)(param_1 + 0x200) = 0;
        }
      }
    }
  }
  if (local_a0 != 0) {
    ObReleaseObjectSecurity();
  }
  if (local_a8 != (longlong *)0x0) {
    ZwClose();
    local_a8 = (longlong *)0x0;
  }
  if (iVar1 < 0) {
    if (local_b0 != 0) {
      ZwClose();
      local_b0 = 0;
    }
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
      lVar2 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  *param_5 = local_b0;
  *param_4 = lVar2;
  return iVar1;
}



===== TmpEnlistSuperiorSubordinateTm @ 1400127ac =====

int TmpEnlistSuperiorSubordinateTm
              (longlong param_1,longlong param_2,longlong *param_3,longlong *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong local_50;
  longlong local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_38 = 0;
  local_50 = 0;
  local_30 = 0;
  local_48 = 0;
  local_28 = 0;
  local_40 = 0;
  lVar3 = 0;
  if (*param_3 == 0) {
    local_20 = 0;
    iVar2 = TmpCreateInternalCrmTransaction(*param_4,'\x01',param_2,&local_20,&local_40);
    lVar1 = local_20;
    if (-1 < iVar2) {
      local_38 = local_20;
      *param_3 = *param_4;
      *param_4 = local_20;
      iVar2 = TmpNamespaceInsert(param_1 + 0xb0,param_1,*param_3);
      lVar3 = lVar1;
      if (-1 < iVar2) {
        *(longlong *)(*param_3 + 0x200) = param_1;
        TmpMigrateEnlistments(*param_3,*param_4);
        iVar2 = TmpCreateInternalCrmEnlistment(*param_3,param_1,0,0,0,0,&local_50,&local_48);
        if (-1 < iVar2) {
          iVar2 = TmpCreateInternalCrmEnlistment
                            (*param_4,param_2,1,local_50,local_48,local_40,&local_30,&local_28);
          if (-1 < iVar2) {
            *(undefined8 *)(*param_4 + 0x58) = *(undefined8 *)(*param_3 + 0x58);
            ObfReferenceObject(*(undefined8 *)(*param_4 + 0x58));
            LOCK();
            *(uint *)(*param_4 + 0xc4) = *(uint *)(*param_4 + 0xc4) & 0xfffffeff;
            UNLOCK();
            ObfDereferenceObject(*param_4);
            lVar3 = local_38;
          }
        }
      }
    }
  }
  else {
    iVar2 = TmpCreateInternalCrmTransaction(*param_3,'\0',param_2,param_4,&local_40);
    if (-1 < iVar2) {
      lVar3 = *param_4;
      local_38 = lVar3;
      iVar2 = TmpCreateInternalCrmEnlistment(*param_3,param_1,0,0,0,0,&local_50,&local_48);
      if (-1 < iVar2) {
        iVar2 = TmpCreateInternalCrmEnlistment
                          (*param_4,param_2,1,local_50,local_48,local_40,&local_30,&local_28);
        if (-1 < iVar2) {
          *(undefined8 *)(*param_4 + 0x58) = *(undefined8 *)(*param_3 + 0x58);
          ObfReferenceObject(*(undefined8 *)(*param_4 + 0x58));
        }
      }
    }
  }
  if (iVar2 < 0) {
    if (lVar3 != 0) {
      ObfDereferenceObject(lVar3);
    }
    if (local_50 != 0) {
      ObfDereferenceObject();
    }
    if (local_48 != 0) {
      ZwClose();
    }
    if (local_30 != 0) {
      ObfDereferenceObject();
    }
    if (local_28 != 0) {
      ZwClose();
    }
    if (local_40 != 0) {
      ZwClose();
    }
  }
  return iVar2;
}



===== TmpForgetAllEnlistmentsTransaction @ 140012ad0 =====

void TmpForgetAllEnlistmentsTransaction(longlong param_1)

{
  TmRollbackTransaction(param_1,'\0');
  TmpFinalizeTransactionForcefully(param_1);
  return;
}



===== TmpForgetTransaction @ 140012af8 =====

int TmpForgetTransaction(longlong param_1,char param_2,char param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong local_18 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x200);
  iVar3 = 0;
  if (param_3 != '\0') {
    iVar2 = TmpLogTransaction(param_1,4,0);
    iVar3 = 0;
    if (param_2 == '\0') {
      iVar3 = iVar2;
    }
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x18 & 1) != 0) {
    local_18[0] = -*(longlong *)(param_1 + 0x208);
    iVar3 = ClfsReserveAndAppendLog(*(undefined8 *)(lVar1 + 0xa0),0,0,0,0,1,local_18,0,0);
    *(undefined8 *)(param_1 + 0x208) = 0;
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfeffffff;
    UNLOCK();
  }
  LOCK();
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x400000;
  UNLOCK();
  TmpFinalizeTransactionForcefully(param_1);
  if ((param_3 == '\0') && ((*(uint *)(param_1 + 0xc4) >> 0x19 & 1) != 0)) {
    local_18[0] = -0x48;
    iVar3 = ClfsReserveAndAppendLog(*(undefined8 *)(lVar1 + 0xa0),0,0,0,0,1,local_18,0,0);
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfdffffff;
    UNLOCK();
  }
  return iVar3;
}



===== TmpHeuristicAbortTransaction @ 140012c50 =====

undefined8 TmpHeuristicAbortTransaction(longlong param_1)

{
  TmpAcquireTransactionMutex(param_1);
  if (*(int *)(param_1 + 0xc0) - 3U < 2) {
    TmpTraceTransactionHeuristicCorruption(param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_qq_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_aa500d615f02383f20d25780cb696015_Traceguids,
                      *(undefined8 *)(param_1 + 0x200),(char)param_1,param_1 + 0xb0);
    }
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x8000000;
    UNLOCK();
    TmpForgetTransaction(param_1,'\x01','\x01');
  }
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return 0;
}



===== TmpHeuristicAbortTransactionAfterCheckpoint @ 140012d00 =====

undefined8
TmpHeuristicAbortTransactionAfterCheckpoint(longlong param_1,undefined8 param_2,undefined *param_3)

{
  char cVar1;
  int iVar2;
  undefined **ppuVar3;
  
  TmpAcquireTransactionMutex(param_1);
  if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0) {
    cVar1 = ClfsLsnLess(param_1 + 0xf8);
    if (cVar1 != '\0') {
      iVar2 = TmpRequestOutcomeTransaction(param_1,0,param_3);
      if (iVar2 < 0) {
        TmpTraceTransactionHeuristicCorruption(param_1);
        ppuVar3 = &WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (ppuVar3 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
           (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_qq_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),ppuVar3,param_3,
                           *(undefined8 *)(param_1 + 0x200),(char)param_1,param_1 + 0xb0,(char)iVar2
                          );
        }
        LOCK();
        *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x8000000;
        UNLOCK();
        TmpTxActionDoRollback(param_1,ppuVar3,param_3);
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_qq_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                        &WPP_aa500d615f02383f20d25780cb696015_Traceguids,
                        *(undefined8 *)(param_1 + 0x200),(char)param_1,param_1 + 0xb0);
      }
    }
  }
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return 0;
}



===== TmpInternalCrmLinkEnlistment @ 140012e24 =====

void TmpInternalCrmLinkEnlistment(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *(longlong *)(param_1 + 0xf0) = param_2;
  *(undefined8 *)(param_1 + 0xf8) = param_3;
  LOCK();
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 0x20;
  UNLOCK();
  uVar2 = *(undefined8 *)(param_2 + 0x38);
  *(undefined8 *)(param_1 + 0x108) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(param_1 + 0x110) = uVar2;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x98) + 0x168);
  uVar2 = *(undefined8 *)(lVar1 + 0x78);
  *(undefined8 *)(param_1 + 0x118) = *(undefined8 *)(lVar1 + 0x70);
  *(undefined8 *)(param_1 + 0x120) = uVar2;
  uVar2 = *(undefined8 *)(*(longlong *)(param_2 + 0x98) + 0x90);
  *(undefined8 *)(param_1 + 0x128) = *(undefined8 *)(*(longlong *)(param_2 + 0x98) + 0x88);
  *(undefined8 *)(param_1 + 0x130) = uVar2;
  return;
}



===== TmpIsLogWritableTransactionManager @ 140012e80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpIsLogWritableTransactionManager(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_68 [4];
  undefined4 local_64;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar1 = param_1 + 8;
  local_74 = 0;
  local_b8 = (undefined8 *)0x0;
  local_88 = *(undefined8 *)CLFS_LSN_NULL_exref;
  KeWaitForSingleObject(lVar1,0,0,0);
  if ((*(uint *)(param_1 + 0x80) & 1) == 0) {
    if (*(int *)(param_1 + 0x40) != 4) {
      if (((*(longlong *)(param_1 + 0x98) == 0) || (*(longlong *)(param_1 + 0xa0) == 0)) ||
         (*(int *)(param_1 + 0x40) != 3)) {
        KeReleaseMutex(lVar1,0);
        return -0x3fe6ffae;
      }
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(param_1 + 0x310);
      KeReleaseMutex(lVar1);
      memset(local_68,0,0x48);
      local_80 = local_68;
      local_90 = 0;
      local_98 = 2;
      local_a0 = 0;
      local_b0 = &local_88;
      local_a8 = 0;
      local_b8 = &local_88;
      local_64 = 7;
      local_78 = 0x48;
      iVar2 = ClfsReserveAndAppendLogAligned(*(undefined8 *)(param_1 + 0xa0),&local_80,1,8);
      ExReleaseResourceLite(param_1 + 0x310);
      KeLeaveCriticalRegion();
      iVar3 = 0;
      if (iVar2 != -0x3fe5ffe3) {
        iVar3 = iVar2;
      }
      return iVar3;
    }
    iVar3 = -0x3fe6fffc;
  }
  else {
    iVar3 = -0x3fe6ffc5;
  }
  KeReleaseMutex(lVar1,0);
  return iVar3;
}



===== TmpIsTransactionTreeRoot @ 140013060 =====

ulonglong TmpIsTransactionTreeRoot(longlong param_1)

{
  ulonglong in_RAX;
  
  if (*(longlong *)(param_1 + 0x58) == param_1) {
    return (ulonglong)(uint3)((uint)*(undefined4 *)(param_1 + 0xc4) >> 8) & 0xffffffffffffff01;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== TmpMigrateEnlistments @ 140013080 =====

void TmpMigrateEnlistments(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  longlong *plVar11;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x200) + 0x2a8);
  plVar11 = *(longlong **)(param_1 + 200);
  while( true ) {
    while( true ) {
      if (plVar11 == (longlong *)(param_1 + 200)) {
        return;
      }
      plVar5 = plVar11 + -0xf;
      plVar2 = (longlong *)*plVar11;
      if (plVar11[4] != lVar1) break;
      lVar3 = plVar11[0xf];
      uVar10 = *(undefined8 *)(*(longlong *)(param_1 + 0x200) + 0x78);
      *(undefined8 *)(lVar3 + 0x118) = *(undefined8 *)(*(longlong *)(param_1 + 0x200) + 0x70);
      *(undefined8 *)(lVar3 + 0x120) = uVar10;
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x200) + 0x2a8);
      lVar4 = plVar11[0xf];
      uVar7 = *(undefined4 *)(lVar3 + 0x8c);
      uVar8 = *(undefined4 *)(lVar3 + 0x90);
      uVar9 = *(undefined4 *)(lVar3 + 0x94);
      *(undefined4 *)(lVar4 + 0x128) = *(undefined4 *)(lVar3 + 0x88);
      *(undefined4 *)(lVar4 + 300) = uVar7;
      *(undefined4 *)(lVar4 + 0x130) = uVar8;
      *(undefined4 *)(lVar4 + 0x134) = uVar9;
      KeWaitForSingleObject(plVar11[4] + 0x28,0,0,0,0);
      ObfDereferenceObject(plVar11[4]);
      TmpRemoveEnlistmentResourceManager((longlong)plVar5);
      KeReleaseMutex(plVar11[4] + 0x28,0);
      TmpInsertEnlistmentResourceManager
                ((longlong)plVar5,*(longlong *)(*(longlong *)(param_1 + 0x200) + 0x2a8));
      ObfReferenceObject(plVar11[4]);
      plVar11 = plVar2;
    }
    TmpRemoveTransactionEnlistmentCounts((longlong)plVar5);
    TmpAcquireTransactionMutex(param_2);
    KeWaitForSingleObject(plVar11 + -7,0,0,0,0);
    plVar11[5] = param_2;
    TmpAddTransactionEnlistmentCounts((longlong)plVar5);
    ObfDereferenceObject(param_1);
    ObfReferenceObject(param_2);
    lVar3 = *plVar11;
    if ((*(longlong **)(lVar3 + 8) != plVar11) ||
       (plVar5 = (longlong *)plVar11[1], (longlong *)*plVar5 != plVar11)) break;
    *plVar5 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar5;
    plVar5 = *(longlong **)(param_2 + 0xd0);
    if (*plVar5 != param_2 + 200) break;
    plVar11[1] = (longlong)plVar5;
    *plVar11 = param_2 + 200;
    *plVar5 = (longlong)plVar11;
    *(longlong **)(param_2 + 0xd0) = plVar11;
    KeReleaseMutex(plVar11 + -7);
    KeReleaseMutex(*(longlong *)(param_2 + 0x58) + 0x20);
    plVar11 = plVar2;
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== TmpOfflineWorker @ 140013290 =====

void TmpOfflineWorker(longlong param_1)

{
  LOCK();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xffffffef;
  UNLOCK();
  TmpTmOffline(param_1);
  ObfDereferenceObject(param_1);
  return;
}



===== TmpQueueCheckpointTm @ 1400132c4 =====

void TmpQueueCheckpointTm(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x40) == 3) {
    uVar2 = *(uint *)(param_1 + 0x84);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x84);
      bVar3 = uVar2 == uVar1;
      if (bVar3) {
        *(uint *)(param_1 + 0x84) = uVar2 | 1;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar3);
    if ((uVar2 & 1) == 0) {
      *(undefined8 *)(param_1 + 0x2c8) = 0;
      *(code **)(param_1 + 0x2d8) = TmpCheckpointWorker;
      *(longlong *)(param_1 + 0x2e0) = param_1;
      ObfReferenceObject();
      ExQueueWorkItem((undefined8 *)(param_1 + 0x2c8),1);
    }
  }
  return;
}



===== TmpQueueOfflineTm @ 140013340 =====

void TmpQueueOfflineTm(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x84);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x84);
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *(uint *)(param_1 + 0x84) = uVar2 | 0x10;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  if ((uVar2 & 0x10) == 0) {
    *(undefined8 *)(param_1 + 0x3a0) = 0;
    *(code **)(param_1 + 0x3b0) = TmpOfflineWorker;
    *(longlong *)(param_1 + 0x3b8) = param_1;
    ObfReferenceObject();
    ExQueueWorkItem((undefined8 *)(param_1 + 0x3a0),1);
  }
  return;
}



===== TmpReacquireReservationTransaction @ 1400133c0 =====

undefined8
TmpReacquireReservationTransaction(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar4;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  TmpAcquireTransactionMutex(param_1);
  lVar1 = *(longlong *)(param_1 + 0x200);
  if (*(int *)(param_1 + 0xc0) == 4) {
    uVar3 = *(undefined8 *)(param_1 + 0x208);
    local_10 = 0x48;
    local_18 = uVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qqii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,uVar3,lVar1,(char)param_1,
                  (char)uVar3,0x48);
      uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);
    }
    iVar2 = ClfsReserveAndAppendLog
                      (*(undefined8 *)(lVar1 + 0xa0),0,0,0,0,CONCAT44(uVar4,2),&local_18,0,0);
    if (iVar2 < 0) {
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfdffffff;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfeffffff;
      UNLOCK();
      *(undefined8 *)(param_1 + 0x208) = 0;
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x2000000;
      UNLOCK();
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x1000000;
      UNLOCK();
    }
  }
  else if (*(int *)(param_1 + 0xc0) == 5) {
    uVar3 = 0x48;
    local_18 = uVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_qqi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,param_3,lVar1,(char)param_1,0x48);
      uVar4 = (undefined4)((ulonglong)uVar3 >> 0x20);
    }
    iVar2 = ClfsReserveAndAppendLog
                      (*(undefined8 *)(lVar1 + 0xa0),0,0,0,0,CONCAT44(uVar4,1),&local_18,0,0);
    if (iVar2 < 0) {
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfdffffff;
      UNLOCK();
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x2000000;
      UNLOCK();
    }
  }
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  return 0;
}



===== NtEnumerateTransactionObject @ 140013580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NtEnumerateTransactionObject
                    (longlong param_1,int param_2,undefined8 *param_3,uint param_4,int *param_5)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  int *piVar4;
  undefined *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStackY_a8 [32];
  int local_78;
  uint local_74;
  int *local_70;
  longlong local_68;
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x13580  10  NtEnumerateTransactionObject */
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_70 = param_5;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  puVar5 = (undefined *)0x0;
  lVar7 = 0;
  uVar6 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  if ((3 < param_2) || (param_4 < 0x24)) {
    return 0xc000000d;
  }
  local_74 = param_4;
  local_60 = param_1;
  if (cVar1 == '\0') {
    local_58 = *param_3;
    uStack_50 = param_3[1];
  }
  else {
    ProbeForWrite(param_3,param_4);
    if (((ulonglong)param_3 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    piVar4 = local_70;
    if (*(int **)MmUserProbeAddress_exref <= local_70) {
      piVar4 = *(int **)MmUserProbeAddress_exref;
    }
    *piVar4 = *piVar4;
    local_58 = *param_3;
    uStack_50 = param_3[1];
  }
  if (param_2 == 0) {
    if (local_60 == 0) {
      puVar5 = &TmpTransactionsNamespace;
      goto LAB_1400136d8;
    }
LAB_1400136c3:
    lVar7 = TmTransactionManagerObjectType;
  }
  else {
    if (param_2 == 1) {
      puVar5 = &TmpTmNamespace;
      goto LAB_1400136d8;
    }
    if (param_2 == 2) goto LAB_1400136c3;
    if (param_2 != 3) {
      return 0xc000000d;
    }
    lVar7 = TmResourceManagerObjectType;
  }
  uVar6 = 1;
LAB_1400136d8:
  lVar8 = 0;
  if (lVar7 != 0) {
    local_68 = 0;
    uVar3 = ObReferenceObjectByHandle(local_60,uVar6,lVar7,cVar1);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    lVar8 = local_68;
    if (param_2 == 0) {
      puVar5 = (undefined *)(local_68 + 0xb0);
    }
    else if (param_2 == 2) {
      puVar5 = (undefined *)(local_68 + 0x158);
    }
    else if (param_2 == 3) {
      puVar5 = (undefined *)(local_68 + 0x180);
    }
  }
  uVar2 = TmpNamespaceEnumerate
                    ((longlong)puVar5,&local_58,(undefined4 *)param_3,local_74,&local_78,cVar1);
  if (lVar8 != 0) {
    local_74 = uVar2;
    ObfDereferenceObject(lVar8);
  }
  if (cVar1 == '\0') {
    *local_70 = local_78;
  }
  else {
    *local_70 = local_78;
  }
  return (ulonglong)uVar2;
}



===== NtFreezeTransactions @ 1400137d0 =====

uint NtFreezeTransactions(undefined8 *param_1,undefined8 *param_2)

{
  char cVar1;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  uint local_38;
  undefined8 *local_30;
  undefined8 *local_28;
  
                    /* 0x137d0  11  NtFreezeTransactions */
  local_38 = 0;
  local_res10 = 0;
  local_res18[0] = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (undefined8 *)0x0)) {
    local_38 = 0xc000000d;
  }
  else {
    cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    local_30 = param_2;
    local_28 = param_1;
    if ((cVar1 != '\0') && (local_38 = TmpFreezeThawPrivilegeCheck(), -1 < (int)local_38)) {
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
        param_1 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      local_res10 = *param_1;
      local_28 = &local_res10;
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_2) {
        param_2 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      local_res18[0] = *param_2;
      local_30 = local_res18;
    }
    if (-1 < (int)local_38) {
      local_38 = TmFreezeTransactions(local_28,local_30,cVar1);
    }
  }
  return local_38;
}



===== NtOpenTransaction @ 1400138b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtOpenTransaction(undefined8 *param_1,int param_2,longlong param_3,undefined8 *param_4,
                     longlong param_5)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined1 auStack_d8 [32];
  longlong *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  int local_98;
  longlong local_90;
  longlong local_88;
  int local_80;
  undefined8 *local_78;
  longlong local_70;
  undefined8 local_68 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x138b0  15  NtOpenTransaction */
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  local_68[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = (undefined8 *)0x0;
  local_88 = 0;
  local_90 = 0;
  uVar8 = 0;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if ((param_2 == 0) || (param_4 == (undefined8 *)0x0)) {
    return -0x3ffffff3;
  }
  local_80 = param_2;
  if (cVar1 == '\0') {
    local_78 = param_4;
    if (param_3 != 0) {
      uVar8 = *(undefined4 *)(param_3 + 0x18);
    }
  }
  else {
    puVar6 = param_1;
    if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
      puVar6 = *(undefined8 **)MmUserProbeAddress_exref;
    }
    *puVar6 = *puVar6;
    if (((ulonglong)param_4 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_58 = *param_4;
    uStack_50 = param_4[1];
    local_78 = &local_58;
  }
  puVar6 = local_78;
  if (param_5 != 0) {
    local_70 = 0;
    local_b0 = 0;
    local_b8 = &local_70;
    iVar3 = ObReferenceObjectByHandle(param_5,1,TmTransactionManagerObjectType,cVar1);
    local_88 = local_70;
    lVar7 = local_70;
    local_98 = iVar3;
    if (iVar3 < 0) goto LAB_140013ab2;
  }
  lVar7 = local_88;
  if (local_88 == 0) {
    puVar5 = &TmpTransactionsNamespace;
  }
  else {
    bVar2 = TmpIsOnlineTransactionManager(local_88);
    if (!bVar2) {
      iVar3 = -0x3fe6ffae;
      local_98 = -0x3fe6ffae;
      goto LAB_140013ab2;
    }
    puVar5 = (undefined *)(lVar7 + 0xb0);
  }
  uVar4 = TmpNamespaceLookup((longlong)puVar5,puVar6,&local_90);
  iVar3 = (int)uVar4;
  local_98 = iVar3;
  if (-1 < iVar3) {
    local_a8 = local_68;
    local_b0 = CONCAT71(local_b0._1_7_,cVar1);
    local_b8 = TmTransactionObjectType;
    iVar3 = ObOpenObjectByPointer(local_90,uVar8,0,local_80);
    local_98 = iVar3;
    if (lVar7 != 0) {
      ObfDereferenceObject(lVar7);
      lVar7 = 0;
      local_88 = 0;
    }
    if (-1 < iVar3) {
      *param_1 = local_68[0];
    }
  }
LAB_140013ab2:
  if (local_90 != 0) {
    ObfDereferenceObject();
  }
  if (lVar7 != 0) {
    ObfDereferenceObject(lVar7);
  }
  if (iVar3 == -0x3fffffcc) {
    iVar3 = -0x3fe6ffb2;
  }
  return iVar3;
}



===== NtRollbackTransaction @ 140013b20 =====

ulonglong NtRollbackTransaction(undefined8 param_1,char param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res18 [2];
  
                    /* 0x13b20  35  NtRollbackTransaction */
  local_res18[0] = 0;
  uVar2 = ObReferenceObjectByHandle
                    (param_1,(-(uint)(param_2 != '\0') & 0x100000) + 0x10,TmTransactionObjectType,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  uVar3 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar3 = TmRollbackTransaction(local_res18[0],param_2);
    uVar3 = uVar3 & 0xffffffff;
    ObfDereferenceObject(lVar1);
  }
  return uVar3;
}



===== NtSetInformationTransaction @ 140013bc0 =====

int NtSetInformationTransaction(undefined8 param_1,int param_2,int *param_3,ulonglong param_4)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  void *_Dst;
  int unaff_EBX;
  uint uVar6;
  undefined8 uVar7;
  ulonglong _Size;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
                    /* 0x13bc0  39  NtSetInformationTransaction */
  uVar6 = (uint)param_4;
  _Size = param_4 & 0xffffffff;
  iVar4 = 0;
  if ((param_2 != 1) && (1 < param_2 - 4U)) {
    return unaff_EBX;
  }
  if (param_2 == 1) {
    if (uVar6 < 0x20) {
      return unaff_EBX;
    }
  }
  else {
    if (param_2 != 4) {
      if (param_2 == 5) {
        if (0x400 < uVar6) {
          return unaff_EBX;
        }
        if (uVar6 == 0) {
          return unaff_EBX;
        }
        iVar4 = 1;
      }
      goto LAB_140013c5d;
    }
    if (uVar6 != 8) {
      return unaff_EBX;
    }
  }
  iVar4 = 4;
LAB_140013c5d:
  cVar2 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (cVar2 == '\0') {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = TmpProbeAndCaptureBuffer(param_3,uVar6,iVar4);
    param_3 = piVar5;
  }
  local_40 = 0;
  uVar7 = CONCAT71((int7)(param_4 >> 8),cVar2);
  iVar4 = ObReferenceObjectByHandle(param_1,2,TmTransactionObjectType,uVar7,&local_40,0);
  lVar3 = local_40;
  local_38 = local_40;
  if (-1 < iVar4) {
    if (param_2 == 1) {
      TmpSetTransactionProperties(local_40,param_3,uVar6,uVar7);
    }
    else if (param_2 == 4) {
      local_38 = 0;
      iVar4 = ObReferenceObjectByHandle
                        (*(undefined8 *)param_3,0x20,TmTransactionManagerObjectType,cVar2,&local_38,
                         0);
      lVar1 = local_38;
      if (-1 < iVar4) {
        TmpAcquireTxTableTransactionManager(local_38);
        TmpAcquireTransactionMutex(lVar3);
        if (*(longlong *)(lVar3 + 0x200) == 0) {
          TmpInsertTxTransactionManager(lVar1,lVar3);
        }
        KeReleaseMutex(*(longlong *)(lVar3 + 0x58) + 0x20,0);
        TmpReleaseTxTableTransactionManager(lVar1);
        ObfDereferenceObject(lVar1);
      }
    }
    else if (param_2 == 5) {
      lVar1 = local_40 + 0x278;
      local_30 = lVar1;
      KeWaitForSingleObject(lVar1,0,0,0,0);
      if (*(longlong *)(lVar3 + 0x268) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar3 + 0x268),0);
        *(undefined8 *)(lVar3 + 0x268) = 0;
        *(undefined4 *)(lVar3 + 0x270) = 0;
      }
      _Dst = (void *)ExAllocatePoolWithQuotaTag(9,_Size,0x69526d54);
      *(void **)(lVar3 + 0x268) = _Dst;
      if (_Dst != (void *)0x0) {
        *(uint *)(lVar3 + 0x270) = uVar6;
        memcpy(_Dst,param_3,_Size);
      }
      KeReleaseMutex(lVar1,0);
    }
    ObfDereferenceObject(lVar3);
  }
  if (piVar5 != (int *)0x0) {
    ExFreePoolWithTag(piVar5,0);
  }
  return unaff_EBX;
}



===== NtThawTransactions @ 140013ef0 =====

void NtThawTransactions(void)

{
  uint uVar1;
  
                    /* 0x13ef0  42  NtThawTransactions */
  if ((*(char *)((longlong)SystemReserved1[0xf] + 0x232) == '\x01') &&
     (uVar1 = TmpFreezeThawPrivilegeCheck(), (int)uVar1 < 0)) {
    return;
  }
  TmThawTransactions();
  return;
}



===== TmpFreezeThawPrivilegeCheck @ 140013f20 =====

uint TmpFreezeThawPrivilegeCheck(void)

{
  char cVar1;
  
  cVar1 = SeSinglePrivilegeCheck(*(undefined8 *)(*(longlong *)SeExports_exref + 0x80),1);
  return ~-(uint)(cVar1 != '\0') & 0xc0000061;
}



===== NtOpenTransactionManager @ 140013f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtOpenTransactionManager
              (undefined8 *param_1,int param_2,longlong param_3,undefined8 *param_4,
              undefined8 *param_5)

{
  longlong lVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  void *_Dst;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  char local_b8;
  int local_b4;
  undefined8 *local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  void *pvStack_98;
  undefined8 local_90;
  void *local_88;
  longlong local_80;
  void *local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x13f60  16  NtOpenTransactionManager */
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  local_90 = 0;
  local_a0 = 0;
  pvStack_98 = (void *)0x0;
  local_88 = (void *)0x0;
  local_a8 = (undefined8 *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_b0 = (undefined8 *)0x0;
  cVar2 = PsIsComponentEnabled(1);
  if (cVar2 == '\0') {
    return -0x3fffffde;
  }
  if (param_2 == 0) {
    iVar4 = -0x3ffffff3;
LAB_14001400c:
    local_b4 = iVar4;
  }
  else {
    local_78 = SystemReserved1[0xf];
    local_b8 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    if (local_b8 == '\0') {
      local_b0 = param_5;
      local_a8 = param_4;
    }
    else {
      puVar6 = param_1;
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
        puVar6 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      *puVar6 = *puVar6;
      if (param_4 != (undefined8 *)0x0) {
        if (*(undefined8 **)MmUserProbeAddress_exref <= param_4) {
          param_4 = *(undefined8 **)MmUserProbeAddress_exref;
        }
        local_a0 = CONCAT44(local_a0._4_4_,*(undefined4 *)param_4);
        pvStack_98 = (void *)param_4[1];
        sVar3 = (short)*(undefined4 *)param_4;
        if (sVar3 != 0) {
          local_a0._0_4_ = CONCAT22(sVar3,sVar3);
          if (((ulonglong)pvStack_98 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
            ExRaiseDatatypeMisalignment();
          }
          _Dst = (void *)ExAllocatePoolWithQuotaTag(1,sVar3,0x73436d54);
          local_88 = _Dst;
          memcpy(_Dst,pvStack_98,local_a0 & 0xffff);
          local_a8 = &local_a0;
          pvStack_98 = _Dst;
        }
      }
      if (param_5 != (undefined8 *)0x0) {
        if (((ulonglong)param_5 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        local_68 = *param_5;
        uStack_60 = param_5[1];
        local_b0 = &local_68;
      }
    }
    cVar2 = local_b8;
    if (local_a8 == (undefined8 *)0x0) {
      if (local_b0 != (undefined8 *)0x0) goto LAB_1400141e0;
      local_c8 = &local_90;
      local_d0 = 0;
      local_d8 = CONCAT44(local_d8._4_4_,param_2);
      iVar4 = ObOpenObjectByName(param_3,TmTransactionManagerObjectType,local_b8,0);
      local_b4 = iVar4;
    }
    else {
      if (local_b0 == (undefined8 *)0x0) {
        iVar4 = TmpExtractTmIdentityFromExistingLogFile(local_a8,(undefined4 *)&local_58);
        local_b4 = iVar4;
        if (iVar4 < 0) goto LAB_14001427b;
        puVar6 = &local_58;
      }
      else {
LAB_1400141e0:
        puVar6 = local_b0;
      }
      local_80 = 0;
      TmpNamespaceLookup(0x1400084e0,puVar6,&local_80);
      lVar1 = local_80;
      if (local_80 == 0) {
        iVar4 = -0x3fffffcc;
        goto LAB_14001400c;
      }
      if ((cVar2 == '\0') && (param_3 != 0)) {
        uVar5 = *(undefined4 *)(param_3 + 0x18);
      }
      else {
        uVar5 = 0;
      }
      local_c8 = &local_90;
      local_d0 = CONCAT71(local_d0._1_7_,cVar2);
      local_d8 = TmTransactionManagerObjectType;
      iVar4 = ObOpenObjectByPointer(local_80,uVar5,0,param_2);
      local_b4 = iVar4;
      ObfDereferenceObject(lVar1);
    }
    if (-1 < iVar4) {
      *param_1 = local_90;
    }
  }
LAB_14001427b:
  if (local_88 != (void *)0x0) {
    ExFreePoolWithTag(local_88,0);
  }
  if (iVar4 == -0x3fffffcc) {
    iVar4 = -0x3fe6ffaf;
  }
  return iVar4;
}



===== NtRenameTransactionManager @ 1400142c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtRenameTransactionManager(ushort *param_1,undefined4 *param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  void *_Dst;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  void *pvStack_40;
  ushort *local_38;
  void *local_30;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  ulonglong local_10;
  
                    /* 0x142c0  32  NtRenameTransactionManager */
  local_28 = auStack_68;
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  local_30 = (void *)0x0;
  local_38 = (ushort *)0x0;
  cVar1 = PsIsComponentEnabled(1);
  if (cVar1 == '\0') {
    iVar3 = -0x3fffffde;
  }
  else {
    if (*(char *)((longlong)SystemReserved1[0xf] + 0x232) == '\0') {
      local_20 = *param_2;
      uStack_1c = param_2[1];
      uStack_18 = param_2[2];
      uStack_14 = param_2[3];
      local_38 = param_1;
    }
    else {
      if (*(ushort **)MmUserProbeAddress_exref <= param_1) {
        param_1 = *(ushort **)MmUserProbeAddress_exref;
      }
      local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)param_1);
      pvStack_40 = *(void **)(param_1 + 4);
      sVar2 = (short)*(undefined4 *)param_1;
      if (sVar2 != 0) {
        local_48._0_4_ = CONCAT22(sVar2,sVar2);
        if (((ulonglong)pvStack_40 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        _Dst = (void *)ExAllocatePoolWithQuotaTag(1,sVar2,0x73436d54);
        local_30 = _Dst;
        memcpy(_Dst,pvStack_40,local_48 & 0xffff);
        local_38 = (ushort *)&local_48;
        pvStack_40 = _Dst;
      }
      if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_20 = *param_2;
      uStack_1c = param_2[1];
      uStack_18 = param_2[2];
      uStack_14 = param_2[3];
    }
    if (local_38 == (ushort *)0x0) {
      _local_unwind(local_28,0x140014452);
      iVar3 = -0x3ffffff3;
    }
    else {
      iVar3 = TmRenameTransactionManager(local_38,(longlong *)&local_20);
      if (local_30 != (void *)0x0) {
        ExFreePoolWithTag(local_30,0);
      }
    }
  }
  return iVar3;
}



===== NtRollforwardTransactionManager @ 140014490 =====

int NtRollforwardTransactionManager
              (undefined8 param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong *plVar4;
  undefined7 uVar5;
  longlong local_res10;
  longlong local_res18 [2];
  longlong *local_18;
  
                    /* 0x14490  36  NtRollforwardTransactionManager */
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  local_res10 = 0;
  cVar2 = PsIsComponentEnabled(1);
  if (cVar2 == '\0') {
    iVar3 = -0x3fffffde;
  }
  else {
    cVar2 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
    local_18 = param_2;
    if ((cVar2 != '\0') && (param_2 != (longlong *)0x0)) {
      if (*(longlong **)MmUserProbeAddress_exref <= param_2) {
        param_2 = *(longlong **)MmUserProbeAddress_exref;
      }
      local_res10 = *param_2;
      local_18 = &local_res10;
    }
    local_res18[0] = 0;
    plVar4 = TmTransactionManagerObjectType;
    iVar3 = ObReferenceObjectByHandle(param_1,4,TmTransactionManagerObjectType,cVar2,local_res18,0);
    lVar1 = local_res18[0];
    if (-1 < iVar3) {
      iVar3 = TmRecoverTransactionManager(local_res18[0],local_18,plVar4,CONCAT71(uVar5,cVar2));
      ObfDereferenceObject(lVar1);
    }
  }
  return iVar3;
}



===== NtSetInformationTransactionManager @ 140014580 =====

int NtSetInformationTransactionManager
              (undefined8 param_1,int param_2,undefined8 param_3,int param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong local_18 [2];
  
                    /* 0x14580  40  NtSetInformationTransactionManager */
  cVar2 = PsIsComponentEnabled(1);
  if (cVar2 == '\0') {
    iVar3 = -0x3fffffde;
  }
  else if (param_2 == 3) {
    if (param_4 == 0) {
      local_18[0] = 0;
      iVar3 = ObReferenceObjectByHandle
                        (param_1,2,TmTransactionManagerObjectType,
                         *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),local_18,0);
      lVar1 = local_18[0];
      if (-1 < iVar3) {
        iVar3 = TmpIsLogWritableTransactionManager(local_18[0]);
        ObfDereferenceObject(lVar1);
      }
    }
    else {
      iVar3 = -0x3ffffffc;
    }
  }
  else {
    iVar3 = -0x3ffffffd;
  }
  return iVar3;
}



===== NtPropagationComplete @ 140014660 =====

int NtPropagationComplete(undefined8 param_1,int param_2,uint param_3,void *param_4)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  void *local_28;
  longlong local_20;
  void *local_18;
  
                    /* 0x14660  21  NtPropagationComplete */
  local_28 = (void *)0x0;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (cVar1 != '\0') {
    if (param_3 != 0) {
      local_28 = TmpProbeAndCaptureBuffer(param_4,param_3,1);
    }
    local_18 = local_28;
    param_4 = local_28;
  }
  local_20 = 0;
  iVar3 = ObReferenceObjectByHandle(param_1,0x40,TmResourceManagerObjectType,cVar1,&local_20,0);
  lVar2 = local_20;
  if (-1 < iVar3) {
    iVar3 = TmPropagationComplete(local_20,param_2,param_3,param_4);
    ObfDereferenceObject(lVar2);
  }
  if (local_28 != (void *)0x0) {
    ExFreePoolWithTag(local_28,0);
  }
  return iVar3;
}



===== NtPropagationFailed @ 140014770 =====

ulonglong NtPropagationFailed(undefined8 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong local_res20;
  
                    /* 0x14770  22  NtPropagationFailed */
  local_res20 = 0;
  uVar2 = ObReferenceObjectByHandle
                    (param_1,0x40,TmResourceManagerObjectType,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),&local_res20,0,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232));
  lVar1 = local_res20;
  uVar3 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar3 = TmPropagationFailed(local_res20,param_2);
    uVar3 = uVar3 & 0xffffffff;
    ObfDereferenceObject(lVar1);
  }
  return uVar3;
}



===== NtRegisterProtocolAddressInformation @ 140014820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtRegisterProtocolAddressInformation
              (undefined8 param_1,longlong *param_2,uint param_3,void *param_4,uint param_5)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_e8 [32];
  longlong *local_c8;
  undefined8 local_c0;
  undefined *local_b8;
  undefined1 local_b0;
  undefined4 *local_a8;
  int *local_a0;
  char local_98;
  int local_94;
  int local_90 [2];
  void *local_88;
  undefined4 local_80 [2];
  longlong local_78;
  void *local_70;
  longlong *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  longlong local_40;
  longlong lStack_38;
  ulonglong local_30;
  
                    /* 0x14820  31  NtRegisterProtocolAddressInformation */
  local_30 = __security_cookie ^ (ulonglong)auStack_e8;
  local_94 = 0;
  local_40 = 0;
  lStack_38 = 0;
  local_88 = (void *)0x0;
  local_98 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (local_98 == '\0') {
    local_70 = param_4;
    local_68 = param_2;
  }
  else {
    if (((ulonglong)param_2 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    if (param_3 != 0) {
      local_88 = TmpProbeAndCaptureBuffer(param_4,param_3,1);
    }
    local_70 = local_88;
    local_40 = *param_2;
    lStack_38 = param_2[1];
    local_68 = &local_40;
  }
  plVar1 = local_68;
  if (param_5 < 4) {
    lVar4 = RtlCompareMemory(local_68,&TmpPromotingProtocolId,0x10);
    lVar5 = RtlCompareMemory(plVar1,&TmpOleTxProtocolId,0x10);
    if ((lVar4 == 0x10) || (lVar5 == 0x10)) {
      local_80[0] = 0;
      local_90[0] = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_50 = 0;
      uStack_48 = 0;
      SeCaptureSubjectContext(&local_60);
      local_a0 = local_90;
      local_a8 = local_80;
      local_b0 = 1;
      local_b8 = &TmpResourceManagerMapping;
      local_c0 = 0;
      local_c8 = (longlong *)((ulonglong)local_c8 & 0xffffffff00000000);
      cVar2 = SeAccessCheck(TmpKtmRmDescriptor,&local_60,0,0x20);
      SeReleaseSubjectContext(&local_60);
      if (cVar2 == '\0') {
        iVar3 = local_90[0];
        goto LAB_140014a8f;
      }
    }
    if (((param_5 & 1) == 0) && ((param_5 & 2) == 0)) {
      local_78 = 0;
      local_c0 = 0;
      local_c8 = &local_78;
      iVar3 = ObReferenceObjectByHandle(param_1,0x20,TmResourceManagerObjectType,local_98);
      local_94 = iVar3;
      if (-1 < iVar3) {
        iVar3 = TmRegisterProtocolAddressInformation(local_78,local_68,param_3,local_70);
        local_94 = iVar3;
        ObfDereferenceObject(local_78);
      }
      goto LAB_140014a93;
    }
    iVar3 = -0x3fffff45;
  }
  else {
    iVar3 = -0x3ffffff3;
  }
LAB_140014a8f:
  local_94 = iVar3;
LAB_140014a93:
  if ((iVar3 < 0) && (local_88 != (void *)0x0)) {
    ExFreePoolWithTag(local_88,0);
  }
  return iVar3;
}



===== TmpProbeAndCaptureBuffer @ 140014ad8 =====

void * TmpProbeAndCaptureBuffer(void *param_1,uint param_2,int param_3)

{
  void *_Dst;
  
  if ((param_2 != 0) && (((ulonglong)param_1 & (ulonglong)(param_3 - 1)) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  _Dst = (void *)ExAllocatePoolWithQuotaTag(1,param_2,0x62436d54);
  memcpy(_Dst,param_1,(ulonglong)param_2);
  return _Dst;
}



===== TmCancelPropagationRequest @ 140014b90 =====

void TmCancelPropagationRequest(longlong param_1)

{
                    /* 0x14b90  43  TmCancelPropagationRequest */
  TmpPropagationComplete(param_1,0,(void *)0x0,-0x3ffffee0);
  return;
}



===== TmEndPropagationRequest @ 140014bb0 =====

undefined8 TmEndPropagationRequest(longlong param_1)

{
  longlong lVar1;
  
                    /* 0x14bb0  51  TmEndPropagationRequest */
  lVar1 = param_1 + 0x70;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  if (*(char *)(param_1 + 0x180) == '\0') {
    TmpPropagationComplete(param_1,0,(void *)0x0,-0x3ffffee0);
    KeReleaseMutex(lVar1,0);
  }
  else {
    KeReleaseMutex(lVar1);
    TmpDereferencePropagateRequest(param_1);
  }
  return 0;
}



===== TmPropagationComplete @ 140014c40 =====

int TmPropagationComplete(longlong param_1,int param_2,uint param_3,void *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  
                    /* 0x14c40  63  TmPropagationComplete */
  puVar2 = TmpFindPropagationRequest(param_1,param_2);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fffffcc;
  }
  else {
    iVar1 = TmpPropagationComplete((longlong)puVar2,param_3,param_4,0);
    TmpDereferencePropagateRequest((longlong)puVar2);
  }
  return iVar1;
}



===== TmPropagationFailed @ 140014ca0 =====

undefined8 TmPropagationFailed(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
                    /* 0x14ca0  64  TmPropagationFailed */
  puVar1 = TmpFindPropagationRequest(param_1,param_2);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc0000034;
  }
  else {
    KeWaitForSingleObject(puVar1 + 0xe,0,0,0,0);
    TmpDispatchPropagateRequest((longlong)puVar1);
    KeReleaseMutex(puVar1 + 0xe,0);
    TmpDereferencePropagateRequest((longlong)puVar1);
    uVar2 = 0;
  }
  return uVar2;
}



===== TmRegisterProtocolAddressInformation @ 140014d14 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TmRegisterProtocolAddressInformation
              (longlong param_1,longlong *param_2,int param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined8 *_Dst;
  longlong lVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined8 local_58;
  undefined1 local_48;
  undefined4 local_44;
  undefined8 *local_40;
  
  _Dst = (undefined8 *)0x0;
  local_40 = (undefined8 *)0x0;
  bVar6 = false;
  local_48 = 0;
  iVar9 = 0;
  local_44 = 0;
  local_58 = 0;
  KeWaitForSingleObject(param_1 + 0x28,0,0,0);
  local_58 = 0;
  KeWaitForSingleObject(&TmpAllProtocolsListMutex,0,0,0);
  if (*(int *)(param_1 + 0x1c) == 2) {
    puVar10 = auStack_78;
    if ((TmpAllProtocolsStaticInfoLength <= TmpAllProtocolsStaticInfoLength + param_3) &&
       (puVar10 = auStack_78, TmpAllProtocolsStaticInfoLength < 0x80000000)) {
      for (puVar8 = TmpAllProtocolsList; (undefined8 **)puVar8 != &TmpAllProtocolsList;
          puVar8 = (undefined8 *)*puVar8) {
        _Dst = puVar8 + -0xc;
        lVar7 = puVar8[-0xb] - *param_2;
        if (lVar7 == 0) {
          lVar7 = puVar8[-10] - param_2[1];
        }
        local_40 = _Dst;
        if (lVar7 == 0) {
          iVar9 = -0x3fe6fff1;
          puVar10 = auStack_78;
          goto LAB_140014f29;
        }
      }
      bVar6 = true;
      local_48 = 1;
      _Dst = (undefined8 *)ExAllocatePoolWithQuotaTag(0x208,0x88,0x72506d54);
      puVar10 = auStack_78;
      local_40 = _Dst;
      if (_Dst != (undefined8 *)0x0) {
        memset(_Dst,0,0x88);
        *(undefined4 *)_Dst = 0xb00b0005;
        *(undefined4 *)((longlong)_Dst + 4) = 1;
        uVar4 = *(undefined4 *)((longlong)param_2 + 4);
        lVar7 = param_2[1];
        uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
        *(int *)(_Dst + 1) = (int)*param_2;
        *(undefined4 *)((longlong)_Dst + 0xc) = uVar4;
        *(int *)(_Dst + 2) = (int)lVar7;
        *(undefined4 *)((longlong)_Dst + 0x14) = uVar5;
        KeInitializeMutex(_Dst + 3,0);
        *(int *)(_Dst + 0xf) = param_3;
        if (param_3 != 0) {
          _Dst[0x10] = param_4;
        }
        _Dst[0xe] = param_1;
        ObfReferenceObject(param_1);
        plVar1 = _Dst + 10;
        plVar2 = *(longlong **)(param_1 + 0x140);
        if (*plVar2 == param_1 + 0x138) {
          *plVar1 = param_1 + 0x138;
          _Dst[0xb] = plVar2;
          *plVar2 = (longlong)plVar1;
          *(longlong **)(param_1 + 0x140) = plVar1;
          puVar8 = _Dst + 0xc;
          if ((undefined8 **)*DAT_140008348 == &TmpAllProtocolsList) {
            *puVar8 = &TmpAllProtocolsList;
            _Dst[0xd] = DAT_140008348;
            *DAT_140008348 = puVar8;
            _TmpAllProtocolsListCount = _TmpAllProtocolsListCount + 1;
            TmpAllProtocolsStaticInfoLength = TmpAllProtocolsStaticInfoLength + param_3;
            DAT_140008348 = puVar8;
            lVar7 = RtlCompareMemory(_Dst + 1,&TmpPromotingProtocolId,0x10);
            puVar10 = auStack_78;
            if (lVar7 == 0x10) {
              puVar10 = auStack_78;
              TmpPromotingProtocolRegistered = _Dst;
            }
            goto LAB_140014f2d;
          }
        }
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar10 = auStack_70;
      }
    }
    iVar9 = -0x3fffff66;
  }
  else {
    iVar9 = -0x3fffffff;
    puVar10 = auStack_78;
  }
LAB_140014f29:
  *(int *)(puVar10 + 0x34) = iVar9;
LAB_140014f2d:
  *(undefined8 *)(puVar10 + -8) = 0x140014f3d;
  KeReleaseMutex(&TmpAllProtocolsListMutex,0);
  *(undefined8 *)(puVar10 + -8) = 0x140014f4e;
  KeReleaseMutex(param_1 + 0x28,0);
  if (((iVar9 < 0) && (bVar6)) && (_Dst != (undefined8 *)0x0)) {
    *(undefined8 *)(puVar10 + -8) = 0x140014f6d;
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar9;
}



===== TmpAllocateAndDispatchPropagateRequest @ 140014f98 =====

uint TmpAllocateAndDispatchPropagateRequest
               (longlong *param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined4 in_stack_00000048;
  undefined8 in_stack_00000058;
  
  uVar2 = TmpAllocatePropagateRequest(param_1,param_3);
  if ((int)uVar2 < 0) {
    *param_1 = 0;
  }
  else {
    LOCK();
    *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + 1;
    UNLOCK();
    lVar1 = *param_1;
    *(undefined4 *)(lVar1 + 0x58) = in_stack_00000048;
    KeWaitForSingleObject(lVar1 + 0x70,0,0,0,0);
    uVar2 = TmpDispatchPropagateRequest(*param_1);
    if ((uVar2 == 0x103) && (lVar1 = *param_1, *(char *)(lVar1 + 0x180) == '\0')) {
      *(code **)(lVar1 + 0x60) = TmpPromotionRequestTail;
      *(undefined8 *)(lVar1 + 0x68) = in_stack_00000058;
      LOCK();
      *(int *)(lVar1 + 8) = *(int *)(lVar1 + 8) + 1;
      UNLOCK();
    }
    else if ((*(char *)(*param_1 + 0x180) != '\0') && (uVar2 == 0x103)) {
      uVar2 = 0;
    }
    KeReleaseMutex(*param_1 + 0x70,0);
  }
  return uVar2;
}



===== TmpAllocatePropagateRequest @ 140015094 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TmpAllocatePropagateRequest(undefined8 param_1,undefined4 *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  undefined8 *in_stack_00000030;
  undefined8 *in_stack_00000038;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined4 local_18;
  undefined4 *local_10;
  
  local_10 = (undefined4 *)0x0;
  local_18 = 0;
  *in_stack_00000038 = 0;
  puVar8 = (undefined4 *)ExAllocatePoolWithQuotaTag(0x208,0x188,0x71526d54);
  puVar12 = puVar8;
  local_10 = puVar8;
  if (puVar8 != (undefined4 *)0x0) {
    memset(puVar8,0,0x188);
    puVar12 = local_10;
    *puVar8 = 0xb00b0006;
    LOCK();
    UNLOCK();
    iVar7 = NextRmCookie + 1;
    NextRmCookie = NextRmCookie + 1;
    local_10[1] = iVar7;
    local_10[2] = 0;
    local_10[0xc] = 0;
    *(undefined8 *)(local_10 + 0x10) = 0;
    uVar3 = param_2[1];
    uVar4 = param_2[2];
    uVar5 = param_2[3];
    local_10[0x12] = *param_2;
    local_10[0x13] = uVar3;
    local_10[0x14] = uVar4;
    local_10[0x15] = uVar5;
    *(undefined8 *)(local_10 + 0xe) = 0;
    *(code **)(local_10 + 0x2e) = TmpDelayedPropWorkItem;
    *(undefined4 **)(local_10 + 0x30) = local_10;
    *(undefined8 *)(local_10 + 0x2a) = 0;
    KeInitializeTimer(local_10 + 0x42);
    KeInitializeDpc(puVar12 + 0x32,TmpAbandonRequestDpc,puVar12);
    KeInitializeMutex(puVar12 + 0x1c,0);
    puVar12[0x54] = 1;
    puVar8 = (undefined4 *)ExAllocatePoolWithQuotaTag(9,0x10,0x78506d54);
    *(undefined4 **)(puVar12 + 0x56) = puVar8;
    uVar5 = uRam000000014000807c;
    uVar4 = uRam0000000140008078;
    uVar3 = uRam0000000140008074;
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = _TmpPromotingProtocolId;
      puVar8[1] = uVar3;
      puVar8[2] = uVar4;
      puVar8[3] = uVar5;
      puVar12[0x58] = 0xdc;
      puVar9 = (undefined8 *)ExAllocatePoolWithQuotaTag(9,0xdc,0x62506d54);
      *(undefined8 **)(puVar12 + 0x5a) = puVar9;
      if (puVar9 != (undefined8 *)0x0) {
        uVar6 = in_stack_00000030[1];
        *puVar9 = *in_stack_00000030;
        puVar9[1] = uVar6;
        uVar6 = in_stack_00000030[3];
        puVar9[2] = in_stack_00000030[2];
        puVar9[3] = uVar6;
        uVar6 = in_stack_00000030[5];
        puVar9[4] = in_stack_00000030[4];
        puVar9[5] = uVar6;
        uVar6 = in_stack_00000030[7];
        puVar9[6] = in_stack_00000030[6];
        puVar9[7] = uVar6;
        uVar6 = in_stack_00000030[9];
        puVar9[8] = in_stack_00000030[8];
        puVar9[9] = uVar6;
        uVar6 = in_stack_00000030[0xb];
        puVar9[10] = in_stack_00000030[10];
        puVar9[0xb] = uVar6;
        uVar6 = in_stack_00000030[0xd];
        puVar9[0xc] = in_stack_00000030[0xc];
        puVar9[0xd] = uVar6;
        uVar6 = in_stack_00000030[0xf];
        puVar9[0xe] = in_stack_00000030[0xe];
        puVar9[0xf] = uVar6;
        uVar6 = in_stack_00000030[0x11];
        puVar9[0x10] = in_stack_00000030[0x10];
        puVar9[0x11] = uVar6;
        uVar6 = in_stack_00000030[0x13];
        puVar9[0x12] = in_stack_00000030[0x12];
        puVar9[0x13] = uVar6;
        uVar6 = in_stack_00000030[0x15];
        puVar9[0x14] = in_stack_00000030[0x14];
        puVar9[0x15] = uVar6;
        uVar3 = *(undefined4 *)((longlong)in_stack_00000030 + 0xb4);
        uVar4 = *(undefined4 *)(in_stack_00000030 + 0x17);
        uVar5 = *(undefined4 *)((longlong)in_stack_00000030 + 0xbc);
        *(undefined4 *)(puVar9 + 0x16) = *(undefined4 *)(in_stack_00000030 + 0x16);
        *(undefined4 *)((longlong)puVar9 + 0xb4) = uVar3;
        *(undefined4 *)(puVar9 + 0x17) = uVar4;
        *(undefined4 *)((longlong)puVar9 + 0xbc) = uVar5;
        uVar3 = *(undefined4 *)((longlong)in_stack_00000030 + 0xc4);
        uVar4 = *(undefined4 *)(in_stack_00000030 + 0x19);
        uVar5 = *(undefined4 *)((longlong)in_stack_00000030 + 0xcc);
        *(undefined4 *)(puVar9 + 0x18) = *(undefined4 *)(in_stack_00000030 + 0x18);
        *(undefined4 *)((longlong)puVar9 + 0xc4) = uVar3;
        *(undefined4 *)(puVar9 + 0x19) = uVar4;
        *(undefined4 *)((longlong)puVar9 + 0xcc) = uVar5;
        puVar9[0x1a] = in_stack_00000030[0x1a];
        *(undefined4 *)(puVar9 + 0x1b) = *(undefined4 *)(in_stack_00000030 + 0x1b);
        puVar12[0x5c] = 0;
        *(undefined8 *)(puVar12 + 0x5e) = 0;
        local_28 = 0;
        KeWaitForSingleObject(&TmpAllPropReqsListMutex,0,0,0);
        puVar13 = auStack_48;
        puVar9 = (undefined8 *)(puVar12 + 8);
        puVar11 = &TmpAllPropReqsList;
        puVar10 = DAT_1400083a8;
        if ((undefined *)*DAT_1400083a8 != &TmpAllPropReqsList) {
          puVar10 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          puVar9 = (undefined8 *)(*pcVar2)();
          puVar13 = auStack_40;
        }
        *puVar9 = puVar11;
        puVar9[1] = puVar10;
        *puVar10 = puVar9;
        *(undefined8 *)(puVar13 + -8) = 0x1400152fa;
        DAT_1400083a8 = puVar9;
        KeReleaseMutex(&TmpAllPropReqsListMutex,0);
        iVar7 = *(int *)(puVar13 + 0x30);
        goto LAB_140015303;
      }
    }
  }
  puVar13 = auStack_48;
  iVar7 = -0x3fffff66;
  local_18 = 0xc000009a;
LAB_140015303:
  if (iVar7 < 0) {
    if (puVar12 != (undefined4 *)0x0) {
      lVar1 = *(longlong *)(puVar12 + 0x56);
      if (lVar1 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x140015326;
        ExFreePoolWithTag(lVar1,0);
        *(undefined8 *)(puVar12 + 0x56) = 0;
      }
      lVar1 = *(longlong *)(puVar12 + 0x5a);
      if (lVar1 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x140015347;
        ExFreePoolWithTag(lVar1,0);
        *(undefined8 *)(puVar12 + 0x5a) = 0;
      }
      if (*(longlong *)(puVar12 + 0x10) != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x140015363;
        ObfDereferenceObject();
        *(undefined8 *)(puVar12 + 0x10) = 0;
      }
      *(undefined8 *)(puVar13 + -8) = 0x140015378;
      ExFreePoolWithTag(puVar12,0);
    }
  }
  else {
    *in_stack_00000038 = puVar12;
  }
  return iVar7;
}



===== TmpDelayedPropWorkItem @ 1400153a0 =====

void TmpDelayedPropWorkItem(longlong param_1)

{
  KeWaitForSingleObject(param_1 + 0x70,0,0,0,0);
  TmpDispatchPropagateRequest(param_1);
  KeReleaseMutex(param_1 + 0x70,0);
  TmpDereferencePropagateRequest(param_1);
  return;
}



===== TmpDeletePropagateRequest @ 140015400 =====

void TmpDeletePropagateRequest(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  KeWaitForSingleObject(&TmpAllPropReqsListMutex,0,0,0,0);
  plVar1 = (longlong *)(param_1 + 0x20);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_1 + 0x28), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  KeReleaseMutex(&TmpAllPropReqsListMutex,0);
  if (*(longlong *)(param_1 + 0x158) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x158),0);
    *(undefined8 *)(param_1 + 0x158) = 0;
  }
  if (*(longlong *)(param_1 + 0x168) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x168),0);
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  if (*(longlong *)(param_1 + 0x178) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x178),0);
    *(undefined8 *)(param_1 + 0x178) = 0;
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== TmpDeleteProtocol @ 14001550c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmpDeleteProtocol(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  if (param_1 == TmpPromotingProtocolRegistered) {
    TmpPromotingProtocolRegistered = 0;
  }
  plVar1 = (longlong *)(param_1 + 0x50);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x58), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    plVar1 = (longlong *)(param_1 + 0x60);
    *(longlong **)(lVar2 + 8) = plVar3;
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_1 + 0x68), (longlong *)*plVar3 == plVar1)) {
      _TmpAllProtocolsListCount = _TmpAllProtocolsListCount + -1;
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      TmpAllProtocolsStaticInfoLength = TmpAllProtocolsStaticInfoLength - *(int *)(param_1 + 0x78);
      ObfDereferenceObject(*(undefined8 *)(param_1 + 0x70));
      if (*(longlong *)(param_1 + 0x80) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x80),0);
        *(undefined8 *)(param_1 + 0x80) = 0;
      }
      ExFreePoolWithTag(param_1,0);
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== TmpDereferencePropagateRequest @ 1400155cc =====

void TmpDereferencePropagateRequest(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  
  lVar4 = *(longlong *)(param_1 + 0x38);
  if (lVar4 != 0) {
    ObfReferenceObject(lVar4);
    KeWaitForSingleObject(lVar4 + 0x28,0,0,0,0);
    LOCK();
    piVar1 = (int *)(param_1 + 8);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      plVar2 = (longlong *)(param_1 + 0x10);
      lVar5 = *plVar2;
      if ((*(longlong **)(lVar5 + 8) != plVar2) ||
         (plVar6 = *(longlong **)(param_1 + 0x18), (longlong *)*plVar6 != plVar2)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      ObfDereferenceObject(lVar4);
      *(undefined8 *)(param_1 + 0x38) = 0;
      TmpDeletePropagateRequest(param_1);
    }
    KeReleaseMutex(lVar4 + 0x28,0);
    ObfDereferenceObject(lVar4);
  }
  return;
}



===== TmpDispatchPropagateRequest @ 1400156a0 =====

uint TmpDispatchPropagateRequest(longlong param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong *plVar8;
  undefined4 *puVar9;
  longlong lVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  longlong *plVar15;
  int iVar16;
  longlong lVar17;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  
  plVar8 = (longlong *)0x0;
  local_48 = 0;
  lVar17 = 0;
  KeWaitForSingleObject(&TmpAllProtocolsListMutex);
  puVar13 = auStack_68;
  uVar7 = *(uint *)(param_1 + 0x30);
  uVar2 = *(uint *)(param_1 + 0x150);
  while (uVar7 < uVar2) {
    if ((undefined8 **)TmpAllProtocolsList != &TmpAllProtocolsList) {
      puVar11 = TmpAllProtocolsList;
      do {
        if ((*(longlong *)(*(longlong *)(param_1 + 0x158) + (ulonglong)uVar7 * 0x10) ==
             puVar11[-0xb]) &&
           (*(longlong *)(*(longlong *)(param_1 + 0x158) + 8 + (ulonglong)uVar7 * 0x10) ==
            puVar11[-10])) {
          if ((puVar11 != (undefined8 *)0x60) &&
             (plVar8 = TmpFindProtocolHeader(puVar11 + -0xb,param_1), plVar8 != (longlong *)0x0)) {
            lVar17 = puVar11[2];
            ObfReferenceObject(lVar17);
            goto LAB_14001576d;
          }
          break;
        }
        puVar11 = (undefined8 *)*puVar11;
      } while ((undefined8 **)puVar11 != &TmpAllProtocolsList);
    }
    uVar7 = *(int *)(param_1 + 0x30) + 1;
    *(uint *)(param_1 + 0x30) = uVar7;
  }
LAB_14001576d:
  KeReleaseMutex(&TmpAllProtocolsListMutex);
  if ((*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x150)) || (plVar8 == (longlong *)0x0)) {
    iVar16 = -0x3fe6fff0;
    goto LAB_140015969;
  }
  iVar16 = (int)plVar8[2] + 0x28;
  puVar9 = (undefined4 *)ExAllocatePoolWithQuotaTag(9,iVar16,0x61506d54);
  if (puVar9 == (undefined4 *)0x0) {
    ObfDereferenceObject(lVar17);
    TmpSchedulePropagateRequest(param_1);
    return 0x103;
  }
  plVar12 = (longlong *)(param_1 + 0x38);
  puVar9[9] = (int)plVar8[2];
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  plVar14 = (longlong *)*plVar12;
  if (plVar14 == (longlong *)0x0) {
LAB_140015868:
    plVar14 = (longlong *)(param_1 + 0x38);
    local_48 = 0;
    *plVar12 = lVar17;
    KeWaitForSingleObject(lVar17 + 0x28,0,0);
    lVar10 = lVar17 + 0x148;
    plVar12 = *(longlong **)(lVar17 + 0x150);
    puVar13 = auStack_68;
    if (*plVar12 != lVar10) goto LAB_140015899;
  }
  else {
    local_48 = 0;
    KeWaitForSingleObject(plVar14 + 5,0,0);
    plVar15 = (longlong *)(param_1 + 0x10);
    lVar10 = *plVar15;
    if ((*(longlong **)(lVar10 + 8) == plVar15) &&
       (plVar4 = *(longlong **)(param_1 + 0x18), (longlong *)*plVar4 == plVar15)) {
      *plVar4 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar4;
      *plVar12 = 0;
      KeReleaseMutex(plVar14 + 5,0);
      ObfDereferenceObject(plVar14);
      goto LAB_140015868;
    }
LAB_140015899:
    plVar12 = (longlong *)0x3;
    pcVar5 = (code *)swi(0x29);
    lVar10 = (*pcVar5)();
    puVar13 = auStack_60;
  }
  plVar15 = (longlong *)(param_1 + 0x10);
  *(longlong **)(param_1 + 0x18) = plVar12;
  *plVar15 = lVar10;
  *plVar12 = (longlong)plVar15;
  *(longlong **)(lVar10 + 8) = plVar15;
  *(undefined8 *)(puVar13 + -8) = 0x1400158bb;
  KeReleaseMutex(lVar17 + 0x28,0);
  lVar17 = *(longlong *)(param_1 + 0x40);
  if (lVar17 == 0) {
    lVar17 = *(longlong *)(param_1 + 0x168);
    uVar6 = *(undefined8 *)(lVar17 + 0x18);
    *(undefined8 *)(puVar9 + 1) = *(undefined8 *)(lVar17 + 0x10);
    *(undefined8 *)(puVar9 + 3) = uVar6;
    uVar6 = *(undefined8 *)(lVar17 + 0x28);
    *(undefined8 *)(puVar9 + 5) = *(undefined8 *)(lVar17 + 0x20);
    *(undefined8 *)(puVar9 + 7) = uVar6;
  }
  else {
    uVar6 = *(undefined8 *)(lVar17 + 0xb8);
    *(undefined8 *)(puVar9 + 1) = *(undefined8 *)(lVar17 + 0xb0);
    *(undefined8 *)(puVar9 + 3) = uVar6;
  }
  plVar8 = plVar8 + 4;
  uVar7 = puVar9[9];
  *puVar9 = *(undefined4 *)(param_1 + 4);
  *(undefined8 *)(puVar13 + -8) = 0x140015906;
  memcpy(puVar9 + 10,plVar8,(ulonglong)uVar7);
  uVar3 = *(undefined4 *)(param_1 + 0x58);
  lVar17 = *plVar14;
  *(undefined4 **)(puVar13 + 0x30) = puVar9;
  *(int *)(puVar13 + 0x28) = iVar16;
  *(undefined4 *)(puVar13 + 0x20) = uVar3;
  *(undefined8 *)(puVar13 + -8) = 0x140015926;
  iVar16 = TmpSetNotificationResourceManager
                     (lVar17,plVar8,0,0,*(int *)(puVar13 + 0x20),*(uint *)(puVar13 + 0x28),
                      *(void **)(puVar13 + 0x30));
  *(undefined8 *)(puVar13 + -8) = 0x140015934;
  ExFreePoolWithTag(puVar9);
  if (-1 < iVar16) {
    cVar1 = *(char *)(param_1 + 0x180);
    *(undefined8 *)(puVar13 + -8) = 0x14001595c;
    TmpSchedulePropagateRequest(param_1);
    return ~-(uint)(cVar1 != '\0') & 0x103;
  }
LAB_140015969:
  *(undefined8 *)(puVar13 + -8) = 0x140015973;
  TmpPropagationComplete(param_1,0,(void *)0x0,iVar16);
  return 0;
}



===== TmpFindPropagationRequest @ 14001599c =====

undefined8 * TmpFindPropagationRequest(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)0x0;
  KeWaitForSingleObject(param_1 + 0x28,0,0,0,0);
  puVar1 = *(undefined8 **)(param_1 + 0x148);
  do {
    if (puVar1 == (undefined8 *)(param_1 + 0x148)) {
LAB_1400159f7:
      KeReleaseMutex(param_1 + 0x28,0);
      return puVar2;
    }
    if (*(int *)((longlong)puVar1 + -0xc) == param_2) {
      puVar2 = puVar1 + -2;
      LOCK();
      *(int *)(puVar1 + -1) = *(int *)(puVar1 + -1) + 1;
      UNLOCK();
      goto LAB_1400159f7;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== TmpFindProtocolHeader @ 140015a28 =====

longlong * TmpFindProtocolHeader(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  
  lVar4 = *(longlong *)(param_2 + 0x168);
  uVar3 = *(uint *)(lVar4 + 8);
  if (uVar3 == 0) {
LAB_140015abe:
    plVar6 = (longlong *)0x0;
  }
  else {
    uVar7 = 0;
    lVar5 = 0x10;
    if (*(int *)(param_2 + 0x58) != 0x10000) {
      lVar5 = 0xbc;
    }
    plVar6 = (longlong *)(lVar5 + lVar4);
    for (; uVar7 < uVar3; uVar7 = uVar7 + 1) {
      plVar1 = (longlong *)(lVar4 + (ulonglong)*(uint *)(param_2 + 0x160));
      if (plVar1 < plVar6 + 4) goto LAB_140015abe;
      plVar2 = (longlong *)((ulonglong)*(uint *)(plVar6 + 2) + (longlong)(plVar6 + 4));
      if ((plVar1 < plVar2) || (0x7fffffff < *(uint *)(plVar6 + 2))) goto LAB_140015abe;
      lVar5 = *plVar6 - *param_1;
      if (lVar5 == 0) {
        lVar5 = plVar6[1] - param_1[1];
      }
      if (lVar5 == 0) goto LAB_140015ac0;
      plVar6 = plVar2;
    }
    if (uVar7 == uVar3) {
      plVar6 = (longlong *)0x0;
    }
  }
LAB_140015ac0:
  return plVar6;
}



===== TmpPromotionRequestTail @ 140015ae0 =====

undefined4 TmpPromotionRequestTail(longlong param_1,longlong param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar2 = false;
  TmpAcquireTransactionMutex(param_2);
  lVar3 = param_2;
  if ((*(uint *)(param_2 + 0xc4) >> 8 & 1) == 0) {
    lVar3 = *(longlong *)(param_2 + 0x110);
  }
  if ((*(uint *)(param_2 + 0xc4) >> 9 & 1) != 0) {
    piVar1 = (int *)(lVar3 + 0x2b8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      KeSetEvent(lVar3 + 0x2c0,0,0);
    }
  }
  LOCK();
  *(uint *)(param_2 + 0xc4) = *(uint *)(param_2 + 0xc4) & 0xfffffdff;
  UNLOCK();
  *(undefined8 *)(param_2 + 0x118) = 0;
  TmEndPropagationRequest(param_1);
  if ((*(longlong *)(param_2 + 0xf0) == 0) || (param_3 < 0)) {
    bVar2 = true;
  }
  KeReleaseMutex(*(longlong *)(param_2 + 0x58) + 0x20);
  if (bVar2) {
    TmRollbackTransaction(param_2,'\0');
    uVar4 = 0;
    if (-1 < param_3) {
      uVar4 = 0xc0190013;
    }
  }
  ObfDereferenceObject(param_2);
  return uVar4;
}



===== TmpPropagationComplete @ 140015be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TmpPropagationComplete(longlong param_1,uint param_2,void *param_3,int param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  longlong lVar4;
  int local_44;
  int local_40;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_44 = 0;
  local_40 = 0;
  bVar1 = false;
  if (((param_1 == 0) || (param_4 == 0x103)) || ((param_2 != 0 && (param_3 == (void *)0x0)))) {
    return -0x3ffffff3;
  }
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  KeWaitForSingleObject(param_1 + 0x70,0,0,0,0);
  if (*(char *)(param_1 + 0x180) == '\x01') {
    bVar1 = true;
    local_44 = -0x3fffffff;
  }
  else {
    *(int *)(param_1 + 0x5c) = param_4;
    *(uint *)(param_1 + 0x170) = param_2;
    if (param_2 != 0) {
      lVar4 = ExAllocatePoolWithQuotaTag(9);
      *(longlong *)(param_1 + 0x178) = lVar4;
      if (lVar4 == 0) {
        local_44 = -0x3fffff66;
        goto LAB_140015d64;
      }
    }
    if (param_2 != 0) {
      memcpy(*(void **)(param_1 + 0x178),param_3,(ulonglong)param_2);
    }
    *(undefined1 *)(param_1 + 0x180) = 1;
    if (*(code **)(param_1 + 0x60) != (code *)0x0) {
      local_28 = *(undefined4 *)(param_1 + 0x48);
      uStack_24 = *(undefined4 *)(param_1 + 0x4c);
      uStack_20 = *(undefined4 *)(param_1 + 0x50);
      uStack_1c = *(undefined4 *)(param_1 + 0x54);
      local_40 = (**(code **)(param_1 + 0x60))
                           (param_1,*(undefined8 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x5c),
                            &local_28);
    }
    cVar2 = KeCancelTimer(param_1 + 0x108);
    cVar3 = KeRemoveQueueDpc(param_1 + 200);
    if (cVar2 != '\0') {
      TmpDereferencePropagateRequest(param_1);
    }
    if (cVar3 != '\0') {
      TmpDereferencePropagateRequest(param_1);
    }
  }
LAB_140015d64:
  if ((local_44 < 0) && (!bVar1)) {
    if (*(longlong *)(param_1 + 0x178) != 0) {
      ExFreePoolWithTag();
      *(undefined8 *)(param_1 + 0x178) = 0;
    }
    *(undefined4 *)(param_1 + 0x170) = 0;
    TmpPropagationComplete(param_1,0,(void *)0x0,local_44);
  }
  KeReleaseMutex(param_1 + 0x70,0);
  TmpDereferencePropagateRequest(param_1);
  if ((-1 < local_44) && (local_40 < 0)) {
    local_44 = local_40;
  }
  return local_44;
}



===== TmpPullTransaction @ 140015df8 =====

uint TmpPullTransaction(undefined8 *param_1,longlong *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  longlong *plVar3;
  int *in_stack_00000040;
  longlong local_28 [2];
  
  local_28[0] = 0;
  plVar3 = param_2;
  uVar2 = TmpValidatePropagationBlob(param_1,param_2,in_stack_00000040);
  if ((int)uVar2 < 0) {
    uVar1 = 0xc0190017;
  }
  else {
    uVar1 = TmpAllocateAndDispatchPropagateRequest(local_28,plVar3,in_stack_00000040 + 4);
    if (-1 < (int)uVar1) {
      if (uVar1 == 0x103) {
        *param_2 = local_28[0];
      }
      else {
        uVar2 = *(undefined8 *)(in_stack_00000040 + 6);
        uVar1 = *(uint *)(local_28[0] + 0x5c);
        *param_1 = *(undefined8 *)(in_stack_00000040 + 4);
        param_1[1] = uVar2;
      }
    }
    if (local_28[0] != 0) {
      TmpDereferencePropagateRequest(local_28[0]);
    }
  }
  return uVar1;
}



===== TmpSchedulePropagateRequest @ 140015e98 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmpSchedulePropagateRequest(longlong param_1)

{
  char cVar1;
  char cVar2;
  
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  cVar1 = KeCancelTimer(param_1 + 0x108);
  cVar2 = KeRemoveQueueDpc(param_1 + 200);
  if (cVar1 != '\0') {
    TmpDereferencePropagateRequest(param_1);
  }
  if (cVar2 != '\0') {
    TmpDereferencePropagateRequest(param_1);
  }
  *(undefined8 *)(param_1 + 0x148) = _DAT_fffff78000000014;
  KeSetTimer(param_1 + 0x108,0xffffffffca5b1700,param_1 + 200);
  return;
}



===== TmpSendPromotionRequest @ 140015f50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TmpSendPromotionRequest(longlong param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)ExAllocatePoolWithTag(1,0xdc,0x72506d54);
  if (puVar7 == (undefined4 *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    memset(puVar7 + 3,0,0xd0);
    puVar7[2] = 1;
    *puVar7 = 1;
    puVar7[1] = 1;
    uVar5 = *(undefined8 *)(param_1 + 0xb8);
    *(undefined8 *)(puVar7 + 4) = *(undefined8 *)(param_1 + 0xb0);
    *(undefined8 *)(puVar7 + 6) = uVar5;
    lVar1 = *(longlong *)(param_1 + 0x200);
    uVar2 = *(undefined4 *)(lVar1 + 0x74);
    uVar3 = *(undefined4 *)(lVar1 + 0x78);
    uVar4 = *(undefined4 *)(lVar1 + 0x7c);
    puVar7[8] = *(undefined4 *)(lVar1 + 0x70);
    puVar7[9] = uVar2;
    puVar7[10] = uVar3;
    puVar7[0xb] = uVar4;
    uVar4 = uRam000000014000807c;
    uVar3 = uRam0000000140008078;
    uVar2 = uRam0000000140008074;
    puVar7[0x2f] = _TmpPromotingProtocolId;
    puVar7[0x30] = uVar2;
    puVar7[0x31] = uVar3;
    puVar7[0x32] = uVar4;
    ObfReferenceObject(param_1);
    uVar6 = TmpPullTransaction((undefined8 *)(param_1 + 0xb0),(longlong *)(param_1 + 0x118));
    ExFreePoolWithTag(puVar7,0);
  }
  return uVar6;
}



===== TmpValidatePropagationBlob @ 140016054 =====

undefined8 TmpValidatePropagationBlob(undefined8 param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  if ((((*param_3 == 1) && (param_3[1] == 1)) && (param_3[2] != 0)) &&
     (piVar4 = param_3 + 0x2f, param_3 <= piVar4)) {
    uVar6 = 0xbc;
    for (uVar7 = 0; uVar7 < (uint)param_3[2]; uVar7 = uVar7 + 1) {
      if ((0xdc < uVar6 + 0x20) || (uVar2 = (uint)uVar6 + 0x20, uVar2 < (uint)uVar6))
      goto LAB_1400160dd;
      if (((ulonglong)piVar4 & 3) != 0) {
        return 0x80000002;
      }
      uVar1 = piVar4[4];
      if ((0x7fffffff < uVar1) || (piVar4 + 8 < param_3)) goto LAB_1400160dd;
      uVar5 = uVar1 + uVar2;
      uVar6 = (ulonglong)uVar5;
      if ((0xdc < uVar5) || (uVar5 < uVar2)) goto LAB_1400160dd;
      piVar4 = (int *)((longlong)(piVar4 + 8) + (ulonglong)uVar1);
    }
    uVar3 = 0;
  }
  else {
LAB_1400160dd:
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== TmpFindEnlistmentResourceManager @ 1400160f0 =====

ulonglong TmpFindEnlistmentResourceManager(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = TmpNamespaceLookup(param_1 + 0x180,param_2,param_3);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 == -0x3fffffcc) {
    uVar2 = 0xc0190050;
  }
  return uVar2;
}



===== TmpFindResourceManagerTm @ 14001611c =====

ulonglong TmpFindResourceManagerTm(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = TmpNamespaceLookup(param_1 + 0x158,param_2,param_3);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 == -0x3fffffcc) {
    uVar2 = 0xc019004f;
  }
  return uVar2;
}



===== TmpNamespaceActivate @ 140016148 =====

void TmpNamespaceActivate(longlong param_1)

{
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  *(undefined1 *)(param_1 + 0xa4) = 0;
  KeReleaseMutex(param_1 + 0x68,0);
  return;
}



===== TmpNamespaceEnumerate @ 1400161a0 =====

undefined4
TmpNamespaceEnumerate
          (longlong param_1,undefined8 param_2,undefined4 *param_3,int param_4,int *param_5,
          char param_6)

{
  longlong *plVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_5c;
  longlong *local_58;
  undefined8 local_50;
  char *local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_50 = 0;
  local_5c = 0;
  uVar7 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_40 = param_1 + 0x68;
  KeWaitForSingleObject(local_40,0,0,0,0);
  *param_5 = 0;
  uVar8 = param_4 - 0x14U >> 4;
  plVar1 = (longlong *)(param_1 + 0x60);
  if (uVar8 == 0) {
    uVar6 = 0xc000000d;
  }
  else {
    uStack_30 = CONCAT44(uStack_30._4_4_,1);
    *plVar1 = (longlong)&local_38;
    *param_5 = *param_5 + 0x14;
    local_58 = plVar1;
    local_38 = param_2;
    while (uVar7 < uVar8) {
      local_48 = (char *)0x0;
      pcVar5 = (char *)RtlEnumerateGenericTableLikeADirectory
                                 (param_1,0,0,1,&local_50,&local_5c,param_2);
      if (pcVar5 == (char *)0x0) break;
      local_48 = pcVar5 + ((ulonglong)*(ushort *)(param_1 + 0xa2) -
                          (ulonglong)*(ushort *)(param_1 + 0xa0)) + -0x20;
      if (*pcVar5 == '\0') {
        if (param_6 == '\0') {
          uVar6 = *(undefined4 *)(local_48 + 4);
          uVar3 = *(undefined4 *)(local_48 + 8);
          uVar4 = *(undefined4 *)(local_48 + 0xc);
          puVar2 = param_3 + (ulonglong)uVar7 * 4 + 5;
          *puVar2 = *(undefined4 *)local_48;
          puVar2[1] = uVar6;
          puVar2[2] = uVar3;
          puVar2[3] = uVar4;
        }
        else {
          uVar6 = *(undefined4 *)(local_48 + 4);
          uVar3 = *(undefined4 *)(local_48 + 8);
          uVar4 = *(undefined4 *)(local_48 + 0xc);
          puVar2 = param_3 + (ulonglong)uVar7 * 4 + 5;
          *puVar2 = *(undefined4 *)local_48;
          puVar2[1] = uVar6;
          puVar2[2] = uVar3;
          puVar2[3] = uVar4;
        }
        uVar7 = uVar7 + 1;
        *param_5 = *param_5 + 0x10;
      }
    }
    if (uVar7 == 0) {
      uVar6 = 0x8000001a;
      *param_5 = 0;
    }
    else {
      if (param_6 == '\0') {
        param_3[4] = uVar7;
        puVar2 = param_3 + (ulonglong)(uVar7 - 1) * 4 + 5;
        uVar6 = puVar2[1];
        uVar3 = puVar2[2];
        uVar4 = puVar2[3];
        *param_3 = *puVar2;
        param_3[1] = uVar6;
        param_3[2] = uVar3;
        param_3[3] = uVar4;
      }
      else {
        param_3[4] = uVar7;
        puVar2 = param_3 + (ulonglong)(uVar7 - 1) * 4 + 5;
        uVar6 = puVar2[1];
        uVar3 = puVar2[2];
        uVar4 = puVar2[3];
        *param_3 = *puVar2;
        param_3[1] = uVar6;
        param_3[2] = uVar3;
        param_3[3] = uVar4;
      }
      uVar6 = 0;
      if (uVar7 < uVar8) {
        uVar6 = 0x8000001a;
      }
    }
  }
  *plVar1 = 0;
  KeReleaseMutex(local_40,0);
  return uVar6;
}



===== TmpNamespaceReplace @ 1400163fc =====

int TmpNamespaceReplace(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ushort uVar3;
  ushort uVar4;
  undefined8 uVar5;
  int iVar6;
  
  uVar3 = *(ushort *)(param_1 + 0xa2);
  uVar4 = *(ushort *)(param_1 + 0xa0);
  if (param_2 != 0) {
    ObfReferenceObject(param_2);
  }
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  TmpNamespaceRemove(param_1,param_2,param_3);
  if (*(longlong *)((ulonglong)uVar4 + param_4) != 0) {
    TmpNamespaceRemove(param_1,param_2,param_4);
  }
  puVar1 = (undefined8 *)((ulonglong)uVar3 + param_3);
  uVar5 = puVar1[1];
  puVar2 = (undefined8 *)((ulonglong)uVar3 + param_4);
  *puVar2 = *puVar1;
  puVar2[1] = uVar5;
  iVar6 = TmpNamespaceInsert(param_1,param_2,param_4);
  KeReleaseMutex(param_1 + 0x68,0);
  if (param_2 != 0) {
    ObfDereferenceObject(param_2);
  }
  return iVar6;
}



===== DllInitialize @ 140016500 =====

undefined8 DllInitialize(void)

{
                    /* 0x16500  1  DllInitialize */
  wil_InitializeFeatureStaging();
  return 0;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140016518 =====

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
      goto LAB_140016575;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140016575;
    }
  }
  uVar1 = 0x206;
LAB_140016575:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140016580 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_z)
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
  plVar1 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140016638 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140016670 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400166f2;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400166f2;
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
LAB_1400166f2:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140016740 =====

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
      plVar2 = (longlong *)&wil_details_featureDescriptors_z;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400167a0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400167bc =====

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
  plVar2 = (longlong *)&wil_details_featureDescriptors_z;
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



===== TmCurrentTransaction @ 140016870 =====

undefined8 TmCurrentTransaction(longlong *param_1)

{
  void *pvVar1;
  char cVar2;
  longlong lVar3;
  
                    /* 0x16870  48  TmCurrentTransaction */
  pvVar1 = SystemReserved1[0xf];
  lVar3 = *(longlong *)((longlong)SystemReserved1[0xf] + 0xf0);
  cVar2 = KeIsAttachedProcess();
  if ((cVar2 == '\0') && ((*(uint *)((longlong)pvVar1 + 0x74) & 0x400) == 0)) {
    if ((lVar3 == 0) || (lVar3 = *(longlong *)(lVar3 + 0x17b8), lVar3 == 0)) {
      lVar3 = 0;
    }
  }
  else {
    lVar3 = 0;
  }
  *param_1 = lVar3;
  return 0;
}



===== TmIsTransactionActive @ 140016910 =====

longlong TmIsTransactionActive(longlong param_1)

{
  uint uVar1;
  uint7 uVar2;
  
                    /* 0x16910  58  TmIsTransactionActive */
  uVar1 = *(uint *)(param_1 + 0xc0);
  uVar2 = (uint7)(uint3)(uVar1 >> 8);
  if ((uVar1 < 0xc) && ((0x902U >> (uVar1 & 0x1f) & 1) != 0)) {
    return CONCAT71(uVar2,1);
  }
  return (ulonglong)uVar2 << 8;
}



===== TmpPromptRecoveryAllTransactionManagers @ 140016934 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmpPromptRecoveryAllTransactionManagers
               (longlong param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStackY_58 [32];
  longlong local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  while( true ) {
    uVar2 = TmpNamespaceEnumerateObject(param_1,&local_20,param_3,param_4,&local_28);
    param_1 = local_28;
    if ((int)uVar2 == -0x7fffffe6) break;
    local_20 = *(undefined8 *)(local_28 + 0x70);
    uStack_18 = *(undefined8 *)(local_28 + 0x78);
    lVar1 = *(longlong *)(local_28 + 0x2a8);
    if (lVar1 != 0) {
      ObfReferenceObject(lVar1);
    }
    KeReleaseMutex(param_1 + 8,0);
    if (lVar1 != 0) {
      TmRecoverResourceManager(lVar1);
      ObfDereferenceObject(lVar1);
    }
    ObfDereferenceObject();
  }
  return;
}



===== TmpNamespaceEnumerateObject @ 140016a04 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
TmpNamespaceEnumerateObject
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4,
          longlong *param_5)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_res18;
  ulonglong local_res20;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18 = 0;
  local_res20 = param_4 & 0xffffffff00000000;
  lVar3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeWaitForSingleObject(&DAT_140008548,0,0,0,0);
  uStack_20 = CONCAT44(uStack_20._4_4_,1);
  _DAT_140008540 = &local_28;
  local_28 = param_2;
  while (lVar2 = RtlEnumerateGenericTableLikeADirectory
                           (&TmpTmNamespace,0,0,1,&local_res18,&local_res20,param_2), lVar2 != 0) {
    lVar3 = (lVar2 - (ulonglong)DAT_140008580) + -0x20;
    if (*(char *)((ulonglong)DAT_140008580 + 0x20 + lVar3) == '\0') {
      ObfReferenceObject(lVar3);
      bVar1 = TmpFilterTransactionManagerOnlineAndLock(lVar3);
      if (bVar1) break;
      ObfDereferenceObject(lVar3);
    }
  }
  if (lVar2 == 0) {
    uVar4 = 0x8000001a;
  }
  else {
    *param_5 = lVar3;
    uVar4 = 0;
  }
  _DAT_140008540 = (undefined8 *)0x0;
  KeReleaseMutex(&DAT_140008548,0);
  return uVar4;
}



===== TmRecoverResourceManager @ 140016b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 TmRecoverResourceManager(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  int iVar7;
  undefined1 auStackY_a8 [32];
  undefined8 *local_60;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
                    /* 0x16b60  67  TmRecoverResourceManager */
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar6 = 0;
  KeWaitForSingleObject(param_1 + 0x28);
  if (*(int *)(param_1 + 0x1c) == 1) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
  }
  if ((*(longlong *)(param_1 + 0x168) == 0) ||
     (*(int *)(*(longlong *)(param_1 + 0x168) + 0x40) != 3)) {
LAB_140016e8d:
    uVar4 = 0xc0190052;
  }
  else {
    puVar1 = (undefined8 *)(param_1 + 0x110);
    puVar5 = (undefined8 *)*puVar1;
    while (puVar5 != puVar1) {
      puVar2 = (undefined8 *)*puVar5;
      if ((*(uint *)((longlong)puVar5 + 0x24) & 4) == 0) {
        KeWaitForSingleObject(puVar5 + -9);
        LOCK();
        *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) | 0x80;
        UNLOCK();
        uVar6 = 0;
        KeReleaseMutex(puVar5 + -9);
      }
      puVar5 = puVar2;
    }
    local_60 = (undefined8 *)*puVar1;
    while (local_60 != puVar1) {
      iVar7 = 0;
      puVar5 = local_60 + -0x11;
      if ((*(uint *)((longlong)local_60 + 0x24) & 4) == 0) {
        ObfReferenceObject(puVar5);
        KeWaitForSingleObject(local_60 + -9);
        bVar3 = false;
        if ((char)*(undefined4 *)((longlong)local_60 + 0x24) < '\0') {
          if (((*(uint *)((longlong)local_60 + 0x24) & 1) == 0) ||
             (1 < *(int *)(local_60[3] + 0xc0) - 3U)) {
            if ((((*(uint *)((longlong)local_60 + 0x24) & 1) == 0) &&
                (*(int *)(local_60[3] + 0xc0) == 5)) ||
               (bVar3 = false, *(int *)(local_60[3] + 0xc0) - 3U < 2)) {
              iVar7 = 0x100;
              goto LAB_140016d58;
            }
          }
          else {
            iVar7 = 0x800;
LAB_140016d58:
            bVar3 = true;
          }
          LOCK();
          *(uint *)((longlong)local_60 + 0x24) = *(uint *)((longlong)local_60 + 0x24) & 0xffffff7f;
          UNLOCK();
        }
        local_40 = local_60[-0xb];
        uStack_38 = local_60[-10];
        local_30 = *(undefined8 *)(local_60[3] + 0xb0);
        uStack_28 = *(undefined8 *)(local_60[3] + 0xb8);
        uVar6 = 0;
        KeReleaseMutex(local_60 + -9);
        if (!bVar3) {
          ObfDereferenceObject(puVar5);
          goto LAB_140016c98;
        }
        uVar6 = 0;
        KeReleaseMutex(param_1 + 0x28);
        uVar4 = TmpSetNotificationResourceManager
                          (param_1,uVar6,(longlong)puVar5,0,iVar7,0x20,&local_40);
        ObfDereferenceObject(puVar5);
        uVar6 = 0;
        KeWaitForSingleObject(param_1 + 0x28);
        if (*(int *)(param_1 + 0x1c) != 2) goto LAB_140016e92;
        if ((*(longlong *)(param_1 + 0x168) == 0) ||
           (*(int *)(*(longlong *)(param_1 + 0x168) + 0x40) != 3)) goto LAB_140016e8d;
        local_60 = *(undefined8 **)(param_1 + 0x110);
      }
      else {
LAB_140016c98:
        local_60 = (undefined8 *)*local_60;
      }
    }
    uVar4 = TmpSetNotificationResourceManager(param_1,uVar6,0,0,0x2000,0,(void *)0x0);
  }
LAB_140016e92:
  KeReleaseMutex(param_1 + 0x28,0);
  return uVar4;
}



===== TmpFilterTransactionManagerOnlineAndLock @ 140016ed8 =====

bool TmpFilterTransactionManagerOnlineAndLock(longlong param_1)

{
  bool bVar1;
  
  KeWaitForSingleObject(param_1 + 8,0,0,0,0);
  bVar1 = *(int *)(param_1 + 0x40) != 3;
  if (bVar1) {
    KeReleaseMutex(param_1 + 8,0);
  }
  return !bVar1;
}



===== TmpNamespaceCompareGuids @ 140016f40 =====

undefined8 TmpNamespaceCompareGuids(longlong param_1,void *param_2,void *param_3)

{
  void *pvVar1;
  int iVar2;
  undefined8 uVar3;
  void *_Buf1;
  void *_Buf2;
  
  _Buf2 = (void *)0x0;
  if ((int)(*(longlong **)(param_1 + 0x60))[1] == 1) {
    pvVar1 = (void *)**(longlong **)(param_1 + 0x60);
    _Buf1 = param_2;
    if (pvVar1 != param_2) {
      _Buf1 = (void *)0x0;
    }
    _Buf2 = param_3;
    if (pvVar1 != param_3) {
      _Buf2 = (void *)0x0;
    }
    if (_Buf1 != (void *)0x0) goto LAB_140016f93;
  }
  _Buf1 = (void *)(((ulonglong)*(ushort *)(param_1 + 0xa2) - (ulonglong)*(ushort *)(param_1 + 0xa0))
                   + -0x20 + (longlong)param_2);
LAB_140016f93:
  if (_Buf2 == (void *)0x0) {
    _Buf2 = (void *)((longlong)param_3 +
                    ((ulonglong)*(ushort *)(param_1 + 0xa2) - (ulonglong)*(ushort *)(param_1 + 0xa0)
                    ) + -0x20);
  }
  iVar2 = memcmp(_Buf1,_Buf2,0x10);
  if (iVar2 < 1) {
    uVar3 = 2;
    if (iVar2 < 0) {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



===== TmpInternalCrmNotification @ 140016ff0 =====

int TmpInternalCrmNotification
              (longlong param_1,longlong *param_2,ulonglong *param_3,uint param_4,longlong *param_5,
              undefined8 param_6,undefined4 param_7)

{
  longlong *plVar1;
  int iVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined4 local_res8 [2];
  ulonglong local_res10;
  undefined4 *puVar11;
  code **ppcVar12;
  ulonglong *puVar13;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58 [2];
  ulonglong local_50;
  ulonglong local_48;
  code *local_40;
  code *local_38;
  ulonglong local_30;
  
  iVar2 = 0;
  uVar8 = 0;
  local_50 = 0;
  uVar10 = 0;
  local_res10 = 0;
  lVar9 = 0;
  if (param_1 != 0) {
    ObfReferenceObject();
    lVar6 = *(longlong *)(param_1 + 0xf0);
    if (lVar6 != 0) {
      ObfReferenceObject(lVar6);
      lVar9 = lVar6;
    }
  }
  if (((param_4 == 0x2000) ||
      (((param_4 == 0x100 || (param_4 == 0x800)) && (*(longlong *)(param_1 + 0xf0) != 0)))) ||
     ((((param_4 != 0x100 && (param_4 != 0x800)) && (param_4 != 0x2000000)) &&
      (*(longlong *)(param_1 + 0xf0) == 0)))) goto LAB_140017454;
  param_2 = (longlong *)0x80;
  if (param_4 < 0x81) {
    if (param_4 == 0x80) {
      param_5 = (longlong *)0x0;
      iVar2 = TmRollbackComplete(*(longlong *)(param_1 + 0xf0),(longlong *)0x0);
    }
    else if (param_4 == 1) {
      iVar2 = TmPrePrepareEnlistment(*(longlong *)(param_1 + 0xf0),param_5);
    }
    else {
      if (param_4 == 2) {
        iVar2 = TmPrepareEnlistment(*(longlong *)(param_1 + 0xf0),param_5);
        param_2 = param_5;
        if (iVar2 < 0) {
          param_2 = (longlong *)0x0;
          TmRollbackEnlistment(param_1,(longlong *)0x0);
        }
        goto LAB_140017454;
      }
      param_2 = (longlong *)0x2;
      if (param_4 == 4) goto LAB_140017279;
      if (param_4 == 8) {
        iVar2 = TmRollbackEnlistment(*(longlong *)(param_1 + 0xf0),param_5);
      }
      else {
        if (param_4 == 0x10) {
          lVar6 = *(longlong *)(param_1 + 0xf0);
          local_58[0] = 0x10a;
          local_5c = 0x111;
          local_60 = 8;
          local_38 = TmpTxActionDoPrePrepareComplete;
          local_64 = 2;
          puVar13 = (ulonglong *)&local_64;
          ppcVar12 = &local_38;
          puVar11 = &local_60;
          puVar3 = &local_5c;
          puVar7 = local_58;
        }
        else {
          if (param_4 != 0x20) {
            if (param_4 != 0x40) goto LAB_14001725e;
            param_5 = (longlong *)0x0;
            iVar2 = TmCommitComplete(*(longlong *)(param_1 + 0xf0),(longlong *)0x0);
            goto LAB_140017287;
          }
          lVar6 = *(longlong *)(param_1 + 0xf0);
          local_68 = 0x101;
          param_7 = 0x102;
          local_res8[0] = 2;
          local_40 = TmpTxActionDoPrepareComplete;
          local_res10 = local_res10 & 0xffffffff00000000;
          puVar13 = &local_res10;
          ppcVar12 = &local_40;
          puVar11 = local_res8;
          puVar3 = &param_7;
          puVar7 = &local_68;
        }
        param_5 = (longlong *)0x0;
        param_3 = (ulonglong *)0x1;
        iVar2 = TmpProcessNotificationResponse
                          (lVar6,(longlong *)0x0,1,(longlong)puVar7,(longlong)puVar3,
                           (longlong)puVar11,(longlong)ppcVar12,(longlong)puVar13);
      }
    }
  }
  else {
    if (param_4 == 0x100) {
LAB_14001728e:
      local_48 = 0;
      plVar1 = (longlong *)(param_1 + 0x118);
      param_3 = &local_48;
      param_2 = plVar1;
      TmpNamespaceLookup(0x1400084e0,plVar1,param_3);
      uVar8 = local_48;
      local_30 = local_48;
      if (local_48 == 0) {
        TmpTransactionManagerNeededForRecovery(plVar1);
        goto LAB_140017454;
      }
      param_2 = (longlong *)(param_1 + 0x128);
      param_3 = &local_50;
      uVar4 = TmpFindResourceManagerTm(local_48,param_2,param_3);
      iVar2 = (int)uVar4;
      if (iVar2 < 0) goto LAB_140017454;
      param_2 = (longlong *)(param_1 + 0x108);
      param_3 = &local_res10;
      uVar4 = TmpFindEnlistmentResourceManager(local_50,param_2,param_3);
      uVar10 = local_res10;
      iVar2 = (int)uVar4;
      if (iVar2 == -0x3fe6ffb0) {
        TmRecoverEnlistment(param_1,0);
        param_2 = (longlong *)0x0;
        if (param_4 == 0x100) {
          TmCommitComplete(param_1,(longlong *)0x0);
        }
        else {
          TmRollbackEnlistment(param_1,(longlong *)0x0);
        }
        uVar10 = local_res10;
      }
      else {
        if (iVar2 < 0) goto LAB_140017454;
        lVar6 = local_res10 + 0x40;
        KeWaitForSingleObject(lVar6,0,0,0,0);
        param_3 = (ulonglong *)0x10;
        lVar5 = RtlCompareMemory(uVar10 + 0x108);
        if (lVar5 == 0x10) {
          param_3 = (ulonglong *)0x10;
          lVar5 = RtlCompareMemory(uVar10 + 0x128);
          if (lVar5 == 0x10) {
            param_3 = (ulonglong *)0x10;
            lVar5 = RtlCompareMemory(uVar10 + 0x118);
            if (lVar5 == 0x10) {
              *(ulonglong *)(param_1 + 0xf0) = uVar10;
              ObfReferenceObject(uVar10);
              *(longlong *)(uVar10 + 0xf0) = param_1;
              ObfReferenceObject(param_1);
              KeReleaseMutex(lVar6);
              TmRecoverEnlistment(param_1,0);
              param_2 = (longlong *)0x0;
              TmRecoverEnlistment(uVar10,0);
              goto LAB_140017452;
            }
          }
        }
        param_2 = (longlong *)0x0;
        KeReleaseMutex(lVar6);
      }
LAB_140017452:
      iVar2 = 0;
      goto LAB_140017454;
    }
    if (param_4 == 0x200) {
LAB_140017279:
      param_5 = (longlong *)0x0;
      iVar2 = TmCommitEnlistment(*(longlong *)(param_1 + 0xf0),(longlong *)0x0);
    }
    else {
      if (param_4 == 0x800) goto LAB_14001728e;
      if (param_4 == 0x4000) goto LAB_140017454;
      if (param_4 == 0x1000000) {
        TmpRmDisconnectTransaction(*(longlong *)(param_1 + 0xf0));
        goto LAB_140017454;
      }
      if (param_4 != 0x20000000) {
LAB_14001725e:
        iVar2 = -0x3fffffff;
        goto LAB_140017454;
      }
      param_5 = (longlong *)0x0;
      iVar2 = TmRequestOutcomeEnlistment(*(longlong *)(param_1 + 0xf0),(longlong *)0x0);
    }
  }
LAB_140017287:
  param_2 = param_5;
LAB_140017454:
  if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
    WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,iVar2,(char)param_4,
               (char)param_1);
  }
  if (lVar9 != 0) {
    ObDereferenceObjectDeferDelete(lVar9);
  }
  if (param_1 != 0) {
    ObDereferenceObjectDeferDelete(param_1);
  }
  if (uVar10 != 0) {
    ObDereferenceObjectDeferDelete(uVar10);
  }
  if (uVar8 != 0) {
    ObDereferenceObjectDeferDelete(uVar8);
  }
  if (local_50 != 0) {
    ObDereferenceObjectDeferDelete();
  }
  return iVar2;
}



===== TmpFreezeThawTransactionManager @ 140017580 =====

undefined4 TmpFreezeThawTransactionManager(longlong param_1,char *param_2)

{
  undefined4 uVar1;
  
  KeWaitForSingleObject(param_1 + 8,0,0,0,0);
  if (*param_2 == '\0') {
    LOCK();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xffffffef;
    UNLOCK();
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x10;
    UNLOCK();
  }
  uVar1 = TmpNamespaceForEach(param_1 + 0xb0,TmpIsTransactionTreeRoot,TmpFreezeThawTransaction);
  KeReleaseMutex(param_1 + 8,0);
  return uVar1;
}



===== TmpNamespaceForEach @ 140017618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TmpNamespaceForEach(longlong param_1,undefined *param_2,undefined *param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  uVar2 = 0;
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  uVar4 = 1;
  while (pcVar3 = (char *)RtlEnumerateGenericTableAvl(param_1,uVar4), pcVar3 != (char *)0x0) {
    pcVar5 = pcVar3 + (-0x20 - (ulonglong)*(ushort *)(param_1 + 0xa0));
    if (*pcVar3 == '\0') {
      ObfReferenceObject(pcVar5);
      if ((param_2 == (undefined *)0x0) || (cVar1 = (*(code *)param_2)(pcVar5), cVar1 != '\0')) {
        uVar2 = (*(code *)param_3)(pcVar5);
      }
      ObfDereferenceObject(pcVar5);
    }
    uVar4 = 0;
  }
  KeReleaseMutex(param_1 + 0x68,0);
  return uVar2;
}



===== TmpExpireNamespaceResourceManager @ 140017720 =====

undefined8 TmpExpireNamespaceResourceManager(longlong param_1)

{
  TmpNamespaceExpire(param_1 + 0x180);
  return 0;
}



===== TmpNamespaceExpire @ 140017740 =====

void TmpNamespaceExpire(longlong param_1)

{
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  *(undefined1 *)(param_1 + 0xa4) = 1;
  KeReleaseMutex(param_1 + 0x68,0);
  return;
}



===== TmpRecover @ 140017798 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TmpRecover(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 *puVar8;
  char cVar9;
  uint uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined1 *puVar17;
  undefined8 *puVar18;
  undefined **ppuVar19;
  undefined8 uStack_1b0;
  undefined1 auStack_1a8 [32];
  undefined1 local_180 [8];
  undefined1 local_178 [8];
  undefined1 local_170 [24];
  byte local_158 [80];
  undefined8 local_108 [2];
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  longlong *local_d0;
  undefined1 *local_c8 [18];
  ulonglong local_38;
  
  local_c8[0] = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_e0 = 0;
  local_e8 = 0;
  local_108[0] = 0;
  local_f0 = 0;
  local_f8 = 0;
  local_d0 = param_2;
  uVar12 = ObOpenObjectByPointer(param_1,0x200,0,0xf003f);
  puVar17 = auStack_1a8;
  if ((int)uVar12 < 0) goto LAB_1400180e5;
  ppuVar19 = &WPP_GLOBAL_Control;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_1,
              (char)*(undefined8 *)(param_1 + 0x290));
  }
  plVar15 = (longlong *)(param_1 + 0x290);
  puVar18 = (undefined8 *)0x3;
  uVar10 = ClfsReadLogRecord(*(undefined8 *)(param_1 + 0xa0),plVar15,3,local_108);
  puVar17 = auStack_1a8;
  uVar12 = (ulonglong)uVar10;
  if (uVar10 == 0) {
    ppuVar19 = (undefined **)&TmpLogPrefix;
    do {
      plVar16 = (longlong *)0x0;
      if ((puVar17[0x50] & 2) == 0) {
LAB_140017a83:
        *(undefined8 *)(puVar17 + 0x60) = 0;
        *(undefined8 *)(puVar17 + 0x98) = 0;
        *(undefined1 **)(puVar17 + 0x20) = puVar17 + 0xb0;
        puVar18 = (undefined8 *)(puVar17 + 0x90);
        plVar15 = (longlong *)(ulonglong)*(uint *)(puVar17 + 0x5c);
        *(undefined8 *)(puVar17 + -8) = 0x140017abe;
        uVar14 = TmpConstructLogRecordForRecovery
                           (*(int **)(puVar17 + 0xa0),*(uint *)(puVar17 + 0x5c),puVar18,
                            (longlong *)(puVar17 + 0xb8),*(longlong **)(puVar17 + 0x20));
        uVar12 = uVar14 & 0xffffffff;
        *(int *)(puVar17 + 0x54) = (int)uVar14;
        if ((int)uVar14 < 0) {
          *(undefined4 *)(puVar17 + 0x88) = 1;
          goto LAB_140018088;
        }
        if ((param_2 != (longlong *)0x0) &&
           (*param_2 < *(longlong *)(*(longlong *)(puVar17 + 0x90) + 0x18))) goto LAB_140018088;
        *(undefined8 *)(param_1 + 0x298) = *(undefined8 *)(param_1 + 0x290);
        piVar3 = *(int **)(puVar17 + 0x90);
        iVar1 = piVar3[1];
        puVar18 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar18 >> 8),iVar1 != 4);
        *(undefined1 **)(puVar17 + 0x30) = puVar17 + 0x58;
        *(undefined1 **)(puVar17 + 0x28) = puVar17 + 0x60;
        *(longlong *)(puVar17 + 0x20) = param_1;
        plVar15 = (longlong *)(ulonglong)*(uint *)(puVar17 + 0x5c);
        *(undefined8 *)(puVar17 + -8) = 0x140017b3c;
        uVar14 = TmpRecoverTransactionFromLogRecord
                           (piVar3,*(uint *)(puVar17 + 0x5c),iVar1 != 4,
                            *(undefined8 *)(puVar17 + 0x80),*(longlong *)(puVar17 + 0x20),
                            *(undefined8 **)(puVar17 + 0x28),*(undefined1 **)(puVar17 + 0x30));
        uVar12 = uVar14 & 0xffffffff;
        *(int *)(puVar17 + 0x54) = (int)uVar14;
        if (iVar1 == 4) {
          if ((int)uVar14 == -0x3fffffcc) {
            uVar12 = 0;
          }
          *(int *)(puVar17 + 0x54) = (int)uVar12;
        }
        if ((int)uVar12 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_140018088;
          plVar15 = (longlong *)0x19;
          goto LAB_140017a6e;
        }
        if (*(longlong *)(puVar17 + 0x60) != 0) {
          *(undefined8 *)(puVar17 + 0xd0) = 0;
          *(undefined8 *)(puVar17 + 0x28) = 0;
          *(undefined1 **)(puVar17 + 0x20) = puVar17 + 0xd0;
          plVar15 = (longlong *)0x0;
          *(undefined8 *)(puVar17 + -8) = 0x140017bbf;
          puVar18 = TmTransactionObjectType;
          uVar10 = ObReferenceObjectByHandle();
          uVar12 = (ulonglong)uVar10;
          plVar16 = *(longlong **)(puVar17 + 0xd0);
          *(longlong **)(puVar17 + 0x98) = plVar16;
          *(uint *)(puVar17 + 0x54) = uVar10;
          if ((int)uVar10 < 0) goto LAB_140018088;
          *(undefined8 *)(puVar17 + -8) = 0x140017bec;
          ObfDereferenceObject(plVar16);
        }
        if (plVar16 != (longlong *)0x0) {
          if (plVar16[0x40] == 0) {
            *(undefined8 *)(puVar17 + -8) = 0x140017c11;
            plVar15 = plVar16;
            uVar10 = TmpInsertTxTransactionManager(param_1,(longlong)plVar16);
            uVar12 = (ulonglong)uVar10;
            *(uint *)(puVar17 + 0x54) = uVar10;
LAB_140017c17:
            if (plVar16[0x40] != 0) {
              plVar15 = (longlong *)(param_1 + 0x290);
              *(undefined8 *)(puVar17 + -8) = 0x140017c2f;
              TmpInsertTransactionLsnList((longlong)plVar16,plVar15);
              LOCK();
              *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 0x100;
              UNLOCK();
              uVar12 = (ulonglong)*(uint *)(puVar17 + 0x54);
              plVar16 = *(longlong **)(puVar17 + 0x98);
            }
            *(undefined4 *)(plVar16 + 0x18) = 10;
            goto LAB_140017c51;
          }
          if (plVar16[0x40] == param_1) goto LAB_140017c17;
          uVar12 = 0xc0190053;
LAB_140017cc3:
          *(int *)(puVar17 + 0x54) = (int)uVar12;
          goto LAB_140018088;
        }
LAB_140017c51:
        iVar1 = piVar3[1];
        if (iVar1 == 2) {
          LOCK();
          *(uint *)((longlong)plVar16 + 0xc4) = *(uint *)((longlong)plVar16 + 0xc4) | 0x100000;
          UNLOCK();
          *(int *)(puVar17 + 0x70) = *(int *)(puVar17 + 0x70) + 1;
          if (puVar17[0x58] == '\x01') {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
              plVar15 = (longlong *)0x1a;
              puVar18 = (undefined8 *)&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids;
              uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar17 + -8) = 0x140017e89;
              WPP_SF_(uVar6,0x1a,&WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids);
            }
            uVar12 = 0xc0190030;
            *(undefined4 *)(puVar17 + 0x54) = 0xc0190030;
            goto LAB_140018088;
          }
          *(longlong *)(puVar17 + 0x40) = param_1;
          *(undefined8 *)(puVar17 + 0x38) = *(undefined8 *)(puVar17 + 0x80);
          puVar17[0x30] = puVar17[0x58];
          *(undefined8 *)(puVar17 + 0x20) = *(undefined8 *)(puVar17 + 0x60);
          puVar18 = *(undefined8 **)(puVar17 + 0xb8);
          plVar15 = (longlong *)(ulonglong)*(uint *)(puVar17 + 0x5c);
          *(undefined8 *)(puVar17 + -8) = 0x140017ed8;
          uVar14 = TmpRecoverAllEnlistmentRecordsInLogRecord
                             (*(int **)(puVar17 + 0x90),*(uint *)(puVar17 + 0x5c),(longlong)puVar18,
                              *(longlong *)(puVar17 + 0xb0),*(undefined8 *)(puVar17 + 0x20),
                              *(undefined8 *)(puVar17 + 0x28),puVar17[0x30],
                              *(undefined8 *)(puVar17 + 0x38),*(longlong *)(puVar17 + 0x40));
          uVar12 = uVar14 & 0xffffffff;
          *(int *)(puVar17 + 0x54) = (int)uVar14;
          if ((int)uVar14 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_140018088;
            plVar15 = (longlong *)0x1b;
            goto LAB_140017f11;
          }
          *(undefined4 *)(plVar16 + 0x18) = 4;
          *(ulonglong *)(*(longlong *)(puVar17 + 0x98) + 0x208) =
               (ulonglong)*(uint *)(puVar17 + 0x5c);
        }
        else if (iVar1 == 3) {
          LOCK();
          *(uint *)((longlong)plVar16 + 0xc4) = *(uint *)((longlong)plVar16 + 0xc4) | 0x200000;
          UNLOCK();
          *(int *)(puVar17 + 0x74) = *(int *)(puVar17 + 0x74) + 1;
          piVar3 = *(int **)(puVar17 + 0x90);
          *(undefined8 *)(param_1 + 0x248) = *(undefined8 *)(piVar3 + 6);
          if (puVar17[0x58] == '\0') {
            *(longlong *)(puVar17 + 0x40) = param_1;
            *(undefined8 *)(puVar17 + 0x38) = *(undefined8 *)(puVar17 + 0x80);
            puVar17[0x30] = 0;
            *(undefined8 *)(puVar17 + 0x20) = *(undefined8 *)(puVar17 + 0x60);
            puVar18 = *(undefined8 **)(puVar17 + 0xb8);
            plVar15 = (longlong *)(ulonglong)*(uint *)(puVar17 + 0x5c);
            *(undefined8 *)(puVar17 + -8) = 0x140017d6c;
            uVar14 = TmpRecoverAllEnlistmentRecordsInLogRecord
                               (piVar3,*(uint *)(puVar17 + 0x5c),(longlong)puVar18,
                                *(longlong *)(puVar17 + 0xb0),*(undefined8 *)(puVar17 + 0x20),
                                *(undefined8 *)(puVar17 + 0x28),puVar17[0x30],
                                *(undefined8 *)(puVar17 + 0x38),*(longlong *)(puVar17 + 0x40));
            uVar12 = uVar14 & 0xffffffff;
            *(int *)(puVar17 + 0x54) = (int)uVar14;
            if ((int)uVar14 < 0) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_140018088;
              plVar15 = (longlong *)0x1c;
              goto LAB_140017f11;
            }
          }
          else {
            uVar12 = (ulonglong)*(uint *)(puVar17 + 0x54);
          }
          *(undefined4 *)(plVar16 + 0x18) = 5;
          lVar4 = *(longlong *)(puVar17 + 0x98);
          lVar5 = *(longlong *)(lVar4 + 0xf0);
          if (lVar5 != 0) {
            *(undefined8 *)(puVar17 + -8) = 0x140017dcf;
            ObfReferenceObject(lVar5);
            *(undefined8 *)(puVar17 + 0x20) = 0;
            puVar18 = (undefined8 *)0x0;
            *(undefined8 *)(puVar17 + -8) = 0x140017dee;
            KeWaitForSingleObject(lVar5 + 0x40,0,0,0);
            *(undefined8 *)(puVar17 + -8) = 0x140017dfb;
            TmpFinalizeEnlistment(lVar5);
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(puVar17 + -8) = 0x140017e08;
            KeReleaseMutex(lVar5 + 0x40);
            *(undefined8 *)(puVar17 + -8) = 0x140017e17;
            ObfDereferenceObject(lVar5);
          }
          *(undefined4 *)(lVar4 + 0xec) = *(undefined4 *)(lVar4 + 0xd8);
          *(undefined4 *)(lVar4 + 0x1f8) = 2;
          *(undefined8 *)(lVar4 + 0x208) = 0;
        }
        else if (iVar1 == 4) {
          *(int *)(puVar17 + 0x6c) = *(int *)(puVar17 + 0x6c) + 1;
          if (*(longlong *)(puVar17 + 0x60) != 0) {
            plVar16[0x41] = 0;
            puVar18 = (undefined8 *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(puVar17 + -8) = 0x140017cf0;
            uVar10 = TmpForgetTransaction((longlong)plVar16,'\0','\0');
            uVar12 = (ulonglong)uVar10;
            *(uint *)(puVar17 + 0x54) = uVar10;
            if ((int)uVar10 < 0) goto LAB_140018088;
            *(int *)(puVar17 + 0x68) = *(int *)(puVar17 + 0x68) + 1;
          }
        }
        else if (((iVar1 != 7) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          plVar15 = (longlong *)0x1d;
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar17 + -8) = 0x140017ca9;
          WPP_SF_D(uVar6,0x1d,puVar18,iVar1);
        }
        if ((int)uVar12 == 0) {
          param_2 = *(longlong **)(puVar17 + 0xd8);
          goto LAB_14001799f;
        }
        goto LAB_140018088;
      }
      puVar18 = (undefined8 *)0x72526d54;
      *(undefined8 *)(puVar17 + -8) = 0x140017956;
      puVar13 = (undefined8 *)ExAllocatePoolWithTag(1,0x18);
      if (puVar13 == (undefined8 *)0x0) {
        plVar15 = (longlong *)&DAT_140018113;
        *(undefined8 *)(puVar17 + -8) = 0x140017a4b;
        _local_unwind(*(undefined8 *)(puVar17 + 0xe0));
        goto LAB_140017a4b;
      }
      *puVar13 = *(undefined8 *)(param_1 + 0x290);
      plVar15 = puVar13 + 1;
      plVar2 = *(longlong **)(param_1 + 0x398);
      if (*plVar2 != param_1 + 0x390) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3);
        puVar17 = puVar17 + 8;
        goto LAB_140017a83;
      }
      *plVar15 = param_1 + 0x390;
      puVar13[2] = plVar2;
      *plVar2 = (longlong)plVar15;
      *(longlong **)(param_1 + 0x398) = plVar15;
      LOCK();
      *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffeff;
      UNLOCK();
LAB_14001799f:
      plVar16 = (longlong *)(param_1 + 0x290);
      if (*(longlong *)(puVar17 + 0x60) != 0) {
        *(undefined8 *)(puVar17 + -8) = 0x140017f64;
        ZwClose();
        *(undefined8 *)(puVar17 + 0x60) = 0;
      }
      puVar17[0x50] = 3;
      *(longlong **)(puVar17 + 0x38) = plVar16;
      *(undefined1 **)(puVar17 + 0x30) = puVar17 + 0xc0;
      *(undefined1 **)(puVar17 + 0x28) = puVar17 + 200;
      *(undefined8 *)(puVar17 + 0x20) = 0;
      puVar18 = (undefined8 *)(puVar17 + 0x5c);
      plVar15 = (longlong *)(puVar17 + 0xa0);
      *(undefined8 *)(puVar17 + -8) = 0x1400179f4;
      uVar10 = ClfsReadNextLogRecord(*(undefined8 *)(puVar17 + 0x78),plVar15,puVar18,puVar17 + 0x50)
      ;
      uVar12 = (ulonglong)uVar10;
      *(uint *)(puVar17 + 0x54) = uVar10;
      if (uVar10 == 0xc0000011) goto LAB_140018088;
      if (uVar10 == 0xc01a0013) {
        *(undefined8 *)(puVar17 + -8) = 0x140017f8a;
        memset(puVar17 + 0xf0,0,0x78);
        *(undefined4 *)(puVar17 + 0xa8) = 0x78;
        *(undefined8 *)(puVar17 + -8) = 0x140017f9d;
        ClfsTerminateReadLog(*(undefined8 *)(puVar17 + 0x78));
        *(undefined8 *)(puVar17 + 0x78) = 0;
        puVar18 = (undefined8 *)(puVar17 + 0xa8);
        uVar6 = *(undefined8 *)(param_1 + 0x98);
        *(undefined8 *)(puVar17 + -8) = 0x140017fc5;
        uVar11 = ClfsGetLogFileInformation(uVar6,puVar17 + 0xf0);
        *(undefined4 *)(puVar17 + 0x54) = uVar11;
        *(undefined8 *)(param_1 + 0x290) = *(undefined8 *)(puVar17 + 0x138);
        plVar15 = (longlong *)(puVar17 + 0x148);
        *(undefined8 *)(puVar17 + -8) = 0x140017fef;
        cVar9 = ClfsLsnEqual(plVar16);
        if (cVar9 != '\0') {
          uVar12 = 0xc0000011;
          goto LAB_140017cc3;
        }
        *(undefined1 **)(puVar17 + 0x40) = puVar17 + 0x78;
        *(undefined1 **)(puVar17 + 0x38) = puVar17 + 0xc0;
        *(undefined1 **)(puVar17 + 0x30) = puVar17 + 200;
        *(undefined1 **)(puVar17 + 0x28) = puVar17 + 0x50;
        *(undefined1 **)(puVar17 + 0x20) = puVar17 + 0x5c;
        puVar18 = (undefined8 *)0x3;
        uVar6 = *(undefined8 *)(param_1 + 0xa0);
        *(undefined8 *)(puVar17 + -8) = 0x140018051;
        uVar10 = ClfsReadLogRecord(uVar6,plVar16,3,puVar17 + 0xa0);
        uVar12 = (ulonglong)uVar10;
        *(uint *)(puVar17 + 0x54) = uVar10;
        plVar15 = plVar16;
        if ((int)uVar10 < 0) goto LAB_140018088;
      }
    } while ((int)uVar12 == 0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      plVar15 = (longlong *)0x1e;
LAB_140017f11:
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar17 + -8) = 0x140017f1d;
      WPP_SF_D(uVar6,(short)plVar15,puVar18,(int)uVar12);
    }
  }
  else {
    puVar17 = auStack_1a8;
    puVar8 = auStack_1a8;
    if (uVar10 != 0xc0000011) {
LAB_140017a4b:
      puVar8 = puVar17;
      if ((undefined **)WPP_GLOBAL_Control != ppuVar19) {
        ppuVar19 = (undefined **)0x8;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) {
          plVar15 = (longlong *)0x18;
LAB_140017a6e:
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar17 + -8) = 0x140017a7a;
          WPP_SF_D(uVar6,(short)plVar15,puVar18,(int)uVar12);
        }
        goto LAB_140018088;
      }
    }
    puVar17 = puVar8;
    ppuVar19 = (undefined **)0x8;
  }
LAB_140018088:
  if (*(longlong *)(puVar17 + 0x60) != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x140018121;
    ZwClose();
    *(undefined8 *)(puVar17 + 0x60) = 0;
  }
  if (*(longlong *)(puVar17 + 0x78) != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x140018137;
    ClfsTerminateReadLog();
  }
  *(undefined8 *)(puVar17 + -8) = 0x1400180b5;
  ZwClose(*(undefined8 *)(puVar17 + 0x80));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((byte)((byte)ppuVar19 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) != 0)) {
    *(undefined4 *)(puVar17 + 0x38) = *(undefined4 *)(puVar17 + 0x68);
    *(undefined4 *)(puVar17 + 0x30) = *(undefined4 *)(puVar17 + 0x6c);
    *(undefined4 *)(puVar17 + 0x28) = *(undefined4 *)(puVar17 + 0x70);
    *(undefined4 *)(puVar17 + 0x20) = *(undefined4 *)(puVar17 + 0x74);
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar17 + -8) = 0x140018179;
    WPP_SF_qdddd(uVar6,plVar15,puVar18,param_1,puVar17[0x20],puVar17[0x28],puVar17[0x30],
                 puVar17[0x38]);
  }
  uVar10 = *(uint *)(puVar17 + 0x88);
  if (((uVar10 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((byte)((byte)ppuVar19 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) != 0)) {
    *(uint *)(puVar17 + 0x20) = uVar10;
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar17 + -8) = 0x1400181b0;
    WPP_SF_qd(uVar6,0x20,(ulonglong)uVar10,param_1,puVar17[0x20]);
  }
  if (((int)uVar12 == -0x3fe6ffab) && (TmpShutdownOccurred != '\0')) {
    uVar12 = 0xc00002eb;
  }
LAB_1400180e5:
  *(undefined8 *)(puVar17 + -8) = 0x1400180f5;
  return uVar12;
}



===== TmpDeleteTransaction @ 1400181d0 =====

void TmpDeleteTransaction(longlong param_1)

{
  longlong lVar1;
  
  LOCK();
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x80000000;
  UNLOCK();
  if (*(int *)(param_1 + 0xc0) != 0) {
    if ((*(longlong *)(param_1 + 0x88) != 0) && (lVar1 = *(longlong *)(param_1 + 0x200), lVar1 != 0)
       ) {
      TmpNamespaceRemove(lVar1 + 0xb0,lVar1,param_1);
      *(undefined8 *)(param_1 + 0x200) = 0;
    }
    if (*(longlong *)(param_1 + 0x60) != 0) {
      TmpNamespaceRemove(0x140008420,0,param_1);
    }
    if (*(longlong *)(param_1 + 0x138) != 0) {
      RtlFreeUnicodeString(param_1 + 0x130);
    }
    if (*(longlong *)(param_1 + 0x58) != param_1) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    if (*(longlong *)(param_1 + 0x268) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x268),0);
      *(undefined8 *)(param_1 + 0x268) = 0;
      *(undefined4 *)(param_1 + 0x270) = 0;
    }
    if (*(longlong *)(param_1 + 0x110) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x110) = 0;
    }
  }
  return;
}



===== TmpRemoveEnlistmentResourceManager @ 1400182cc =====

void TmpRemoveEnlistmentResourceManager(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
  TmpNamespaceRemove(*(longlong *)(param_1 + 0x98) + 0x180,*(longlong *)(param_1 + 0x98),param_1);
  plVar1 = (longlong *)(param_1 + 0x88);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x90), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    piVar2 = (int *)(*(longlong *)(param_1 + 0x98) + 0x120);
    *piVar2 = *piVar2 + -1;
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== TmpNamespaceRemove @ 14001832c =====

void TmpNamespaceRemove(longlong param_1,longlong param_2,longlong param_3)

{
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  local_10 = 0;
  *(longlong **)(param_1 + 0x60) = &local_18;
  local_18 = param_3;
  RtlDeleteElementGenericTableAvl(param_1,param_3 + 0x20 + (ulonglong)*(ushort *)(param_1 + 0xa0));
  *(undefined8 *)(param_1 + 0x60) = 0;
  KeReleaseMutex(param_1 + 0x68,0);
  if (param_2 != 0) {
    ObfDereferenceObject(param_2);
  }
  return;
}



===== TmpRegisterForLogManagement @ 1400183e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpRegisterForLogManagement(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStack_c8 [32];
  undefined8 local_90;
  undefined8 local_88;
  code *pcStack_80;
  longlong local_78;
  code *pcStack_70;
  longlong local_68;
  code *pcStack_60;
  longlong local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_90 = 0;
  local_50 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  plVar1 = (longlong *)(param_1 + 0xa8);
  *plVar1 = 0;
  local_88 = 1;
  pcStack_80 = TmpAdvanceBaseLsnRequiredNotification;
  pcStack_70 = TmpLogGrowthCompletedNotification;
  pcStack_60 = TmpLogUnpinnedNotification;
  local_78 = param_1;
  local_68 = param_1;
  local_58 = param_1;
  local_48 = param_1;
  iVar2 = ClfsMgmtRegisterManagedClient(*(undefined8 *)(param_1 + 0x98),&local_88,plVar1);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_1400186e9;
    uVar3 = 0x2b;
  }
  else {
    local_40 = 0x1800000001;
    uStack_38 = CONCAT44(1,(undefined4)uStack_38);
    local_30 = CONCAT44(local_30._4_4_,2);
    iVar2 = ClfsMgmtInstallPolicy(*(undefined8 *)(param_1 + 0x98),&local_40,0x18);
    if (iVar2 == -0x3fe5ffec) {
      iVar2 = 0;
    }
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_1400186e9;
      uVar3 = 0x2c;
    }
    else {
      local_40 = 0x1800000001;
      uStack_38 = 0;
      local_30 = 10;
      iVar2 = ClfsMgmtInstallPolicy(*(undefined8 *)(param_1 + 0x98),&local_40,0x18);
      if (iVar2 == -0x3fe5ffec) {
        iVar2 = 0;
      }
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_1400186e9;
        uVar3 = 0x2d;
      }
      else {
        local_40 = 0x1800000001;
        uStack_38 = 0x200000000;
        local_30 = 0x80000;
        iVar2 = ClfsMgmtInstallPolicy(*(undefined8 *)(param_1 + 0x98),&local_40,0x18);
        if (iVar2 == -0x3fe5ffec) {
          iVar2 = 0;
        }
        if (-1 < iVar2) {
          local_90 = 0;
          iVar2 = ClfsMgmtSetLogFileSize(*(undefined8 *)(param_1 + 0x98),&local_90,&local_50,0);
          goto LAB_1400186e9;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_1400186e9;
        uVar3 = 0x2e;
      }
    }
  }
  WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
            &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_1,(char)iVar2);
LAB_1400186e9:
  if ((iVar2 < 0) && (*plVar1 != 0)) {
    ClfsMgmtDeregisterManagedClient();
    *plVar1 = 0;
  }
  return iVar2;
}



===== NtCreateTransaction @ 140018740 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140018bc7) */

int NtCreateTransaction(undefined8 *param_1,uint param_2,undefined8 param_3,undefined8 *param_4,
                       longlong param_5,uint param_6,undefined4 param_7,undefined4 param_8,
                       undefined8 *param_9,uint *param_10)

{
  char cVar1;
  short sVar2;
  int iVar3;
  void *_Dst;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStackY_108 [32];
  undefined8 uVar7;
  uint *local_a8;
  longlong local_a0;
  undefined8 local_98;
  void *pvStack_90;
  undefined8 local_88;
  void *local_80;
  undefined8 local_78;
  longlong local_70;
  undefined8 *local_68;
  void *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x18740  8  NtCreateTransaction */
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_a0 = 0;
  local_88 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  local_98 = 0;
  pvStack_90 = (void *)0x0;
  local_a8 = (uint *)0x0;
  local_80 = (void *)0x0;
  local_60 = SystemReserved1[0xf];
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  puVar6 = param_4;
  local_68 = param_4;
  if (cVar1 == '\0') {
    if (param_4 != (undefined8 *)0x0) {
      local_58 = *param_4;
      uStack_50 = param_4[1];
    }
    local_a8 = param_10;
  }
  else {
    puVar4 = param_1;
    if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
      puVar4 = *(undefined8 **)MmUserProbeAddress_exref;
    }
    *puVar4 = *puVar4;
    if (param_9 != (undefined8 *)0x0) {
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_9) {
        param_9 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      local_78 = *param_9;
      param_9 = &local_78;
    }
    if (param_4 != (undefined8 *)0x0) {
      if (((ulonglong)param_4 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
        ExRaiseDatatypeMisalignment();
      }
      local_58 = *param_4;
      uStack_50 = param_4[1];
    }
    if (param_10 != (uint *)0x0) {
      if (*(uint **)MmUserProbeAddress_exref <= param_10) {
        param_10 = *(uint **)MmUserProbeAddress_exref;
      }
      local_98 = (ulonglong)*param_10;
      pvStack_90 = *(void **)(param_10 + 2);
      sVar2 = (short)*param_10;
      if (sVar2 != 0) {
        local_98 = (ulonglong)CONCAT22(sVar2,sVar2);
        if (((ulonglong)pvStack_90 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        _Dst = (void *)ExAllocatePoolWithQuotaTag(1,sVar2,0x73436d54);
        local_80 = _Dst;
        memcpy(_Dst,pvStack_90,local_98 & 0xffff);
        local_a8 = (uint *)&local_98;
        pvStack_90 = _Dst;
      }
    }
  }
  if (((param_6 < 2) && (param_2 != 0)) && ((local_a8 == (uint *)0x0 || ((ushort)*local_a8 < 0x81)))
     ) {
    if (param_5 != 0) {
      if (cVar1 != '\0') goto LAB_140018b27;
      if (param_5 != 0) {
        local_70 = 0;
        iVar3 = ObReferenceObjectByHandle
                          (param_5,1,TmTransactionManagerObjectType,
                           (ulonglong)puVar6 & 0xffffffffffffff00);
        local_a0 = local_70;
        if (iVar3 < 0) goto LAB_140018bbd;
      }
    }
    uVar7 = 0;
    iVar3 = ObCreateObject(cVar1,TmTransactionObjectType,param_3,cVar1);
    if (-1 < iVar3) {
      uRam00000000000000c0 = 0;
      if (param_4 == (undefined8 *)0x0) {
        ExUuidCreate(&local_58);
      }
      iVar3 = TmInitializeTransaction
                        (0,local_a0,(undefined4 *)&local_58,param_6,uVar7,param_7,param_8,param_9,
                         (longlong)local_a8);
      if (-1 < iVar3) {
        ObfReferenceObject(0);
        uVar5 = (ulonglong)param_2;
        uVar7 = 0;
        iVar3 = ObInsertObject(0,0,uVar5,0);
        if (iVar3 < 0) {
          (**(code **)(TmTransactionObjectType + 0x80))(0,0,1);
        }
        else {
          if (cVar1 == '\0') {
            *param_1 = local_88;
          }
          else {
            *param_1 = local_88;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF__guid__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar5,param_4,
                                &local_58);
          }
        }
      }
    }
  }
  else {
LAB_140018b27:
    iVar3 = -0x3ffffff3;
  }
LAB_140018bbd:
  if (local_80 != (void *)0x0) {
    ExFreePoolWithTag(local_80,0);
  }
  if (local_a0 != 0) {
    ObfDereferenceObject();
  }
  return iVar3;
}



===== TmInitializeTransaction @ 140018c38 =====

int TmInitializeTransaction
              (longlong param_1,longlong param_2,undefined4 *param_3,uint param_4,undefined8 param_5
              ,undefined4 param_6,undefined4 param_7,undefined8 *param_8,longlong param_9)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  
  KeInitializeEvent(param_1,0,0);
  *(undefined4 *)(param_1 + 0x18) = 0xb00b0001;
  ObfReferenceObject(param_1);
  *(undefined8 *)(param_1 + 0xc0) = 1;
  *(undefined4 *)(param_1 + 0x1f8) = 1;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined1 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined1 *)(param_1 + 0x80) = 0;
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = param_3[3];
  *(undefined4 *)(param_1 + 0xb0) = *param_3;
  *(undefined4 *)(param_1 + 0xb4) = uVar2;
  *(undefined4 *)(param_1 + 0xb8) = uVar3;
  *(undefined4 *)(param_1 + 0xbc) = uVar4;
  KeInitializeMutex(param_1 + 0x20,0);
  lVar1 = param_1 + 200;
  *(longlong *)(param_1 + 0x58) = param_1;
  *(longlong *)(param_1 + 0xd0) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0x2b8) = 0;
  KeInitializeEvent(param_1 + 0x2c0,0,0);
  pcVar5 = CLFS_LSN_NULL_exref;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  lVar1 = param_1 + 0x1e8;
  *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)pcVar5;
  *(longlong *)(param_1 + 0x1f0) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined4 *)(param_1 + 0x120) = param_6;
  *(undefined4 *)(param_1 + 0x124) = param_7;
  *(undefined4 *)(param_1 + 0x260) = 0;
  *(undefined8 *)(param_1 + 0x138) = 0;
  *(undefined2 *)(param_1 + 0x130) = 0;
  *(undefined2 *)(param_1 + 0x132) = 0;
  if (param_9 != 0) {
    RtlDuplicateUnicodeString(0);
  }
  if ((param_4 & 1) != 0) {
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x800;
    UNLOCK();
  }
  LOCK();
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x100;
  UNLOCK();
  lVar1 = param_1 + 0x100;
  *(undefined8 *)(param_1 + 0x140) = 0;
  *(longlong *)(param_1 + 0x108) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x208) = 0;
  *(undefined8 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  KeInitializeMutex(param_1 + 0x278);
  *(undefined8 *)(param_1 + 0x2b0) = 0;
  *(undefined8 *)(param_1 + 0x200) = 0;
  if (param_2 == 0) {
    iVar6 = TmpNamespaceInsert(0x140008420,0,param_1);
  }
  else {
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffeff;
    UNLOCK();
    TmpAcquireTxTableTransactionManager(param_2);
    iVar6 = TmpInsertTxTransactionManager(param_2,param_1);
    TmpReleaseTxTableTransactionManager(param_2);
  }
  if (iVar6 < 0) {
    *(undefined1 *)(param_1 + 0xa8) = 1;
    *(undefined1 *)(param_1 + 0x80) = 1;
    ObfDereferenceObject(param_1);
  }
  else {
    if (param_8 == (undefined8 *)0x0) {
      *(undefined8 *)(param_1 + 0x128) = 0;
    }
    else {
      *(undefined8 *)(param_1 + 0x128) = *param_8;
      TmpScheduleRollback(param_1);
    }
    iVar6 = 0;
  }
  return iVar6;
}



===== TmpInsertResourceManagerTm @ 140018ea8 =====

void TmpInsertResourceManagerTm(longlong param_1,longlong param_2)

{
  int iVar1;
  
  *(longlong *)(param_1 + 0x168) = param_2;
  iVar1 = TmpNamespaceInsert(param_2 + 0x158,param_2,param_1);
  if (iVar1 < 0) {
    *(undefined8 *)(param_1 + 0x168) = 0;
  }
  return;
}



===== TmpInsertEnlistmentResourceManager @ 140018ee4 =====

void TmpInsertEnlistmentResourceManager(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = TmpNamespaceInsert(param_2 + 0x180,param_2,param_1);
  if (-1 < iVar4) {
    *(longlong *)(param_1 + 0x98) = param_2;
    plVar1 = (longlong *)(param_1 + 0x88);
    *(int *)(param_2 + 0x120) = *(int *)(param_2 + 0x120) + 1;
    plVar2 = *(longlong **)(param_2 + 0x118);
    if (*plVar2 != param_2 + 0x110) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar1 = param_2 + 0x110;
    *(longlong **)(param_1 + 0x90) = plVar2;
    *plVar2 = (longlong)plVar1;
    *(longlong **)(param_2 + 0x118) = plVar1;
  }
  return;
}



===== TmpNamespaceInsert @ 140018f54 =====

int TmpNamespaceInsert(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  char local_res8 [8];
  longlong local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_res8[0] = '\0';
  if (param_2 != 0) {
    ObfReferenceObject(param_2);
  }
  lVar1 = param_1 + 0x68;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  if (*(char *)(param_1 + 0xa4) == '\0') {
    local_10 = 0;
    *(longlong **)(param_1 + 0x60) = &local_18;
    local_18 = param_3;
    RtlInsertElementGenericTableAvl
              (param_1,(ulonglong)*(ushort *)(param_1 + 0xa0) + 0x20 + param_3,0,local_res8);
    *(undefined8 *)(param_1 + 0x60) = 0;
    KeReleaseMutex(lVar1,0);
    if (local_res8[0] == '\0') {
      if (param_2 != 0) {
        ObfDereferenceObject(param_2);
      }
      iVar2 = -0x3fffffcb;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    KeReleaseMutex(lVar1,0);
    if (param_2 != 0) {
      ObfDereferenceObject(param_2);
    }
    iVar2 = (-(uint)(TmpShutdownOccurred != '\0') & 0xffe70296) + 0xc0190055;
  }
  return iVar2;
}



===== TmRollbackComplete @ 140019080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmRollbackComplete(longlong param_1,longlong *param_2)

{
  undefined1 auStackY_a8 [32];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  code *local_28;
  code *local_20;
  code *local_18;
  ulonglong local_10;
  
                    /* 0x19080  72  TmRollbackComplete */
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_64 = 0;
  local_60 = 0;
  local_34 = 0x10d;
  local_30 = 0x10d;
  local_48 = 0x107;
  local_44 = 0x107;
  local_40 = 0x107;
  local_28 = TmpTxActionDoRollbackComplete;
  local_20 = TmpTxActionDoRollbackComplete;
  local_18 = TmpTxActionDoRollbackComplete;
  local_38 = 0x108;
  local_58 = 7;
  local_54 = 6;
  local_50 = 9;
  local_68 = 1;
  TmpProcessNotificationResponse
            (param_1,param_2,3,(longlong)&local_38,(longlong)&local_48,(longlong)&local_58,
             (longlong)&local_28,(longlong)&local_68);
  return;
}



===== TmReadOnlyEnlistment @ 140019140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TmReadOnlyEnlistment(longlong param_1,longlong *param_2)

{
  undefined1 auStackY_b8 [32];
  code *local_78;
  code *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x19140  65  TmReadOnlyEnlistment */
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = 0;
  local_60 = 0;
  local_78 = TmpTxActionDoPrePrepareComplete;
  local_70 = TmpTxActionDoPrepareComplete;
  local_28 = 0x1010000010a;
  uStack_20 = 0x10000000111;
  local_38 = 0x10e0000010e;
  uStack_30 = 0x10e0000010e;
  local_48 = 0x200000008;
  uStack_40 = 0x10000000b;
  local_58 = 0x100000001;
  uStack_50 = 0x100000001;
  TmpProcessNotificationResponse
            (param_1,param_2,4,(longlong)&local_28,(longlong)&local_38,(longlong)&local_48,
             (longlong)&local_78,(longlong)&local_58);
  return;
}



===== TmCommitComplete @ 140019200 =====

void TmCommitComplete(longlong param_1,longlong *param_2)

{
  undefined4 local_res18;
  undefined4 local_res1c;
  undefined4 local_res20;
  undefined4 local_res24;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  code *local_18;
  code *local_10;
  
                    /* 0x19200  44  TmCommitComplete */
  local_20 = 0x108;
  local_28 = 0x104;
  local_24 = 0x104;
  local_1c = 0x105;
  local_18 = TmpTxActionDoCommitComplete;
  local_10 = TmpTxActionDoCommitComplete;
  local_res18 = 1;
  local_res1c = 1;
  local_res20 = 7;
  local_res24 = 5;
  TmpProcessNotificationResponse
            (param_1,param_2,2,(longlong)&local_20,(longlong)&local_28,(longlong)&local_res20,
             (longlong)&local_18,(longlong)&local_res18);
  return;
}



===== TmPrepareComplete @ 140019290 =====

void TmPrepareComplete(longlong param_1,longlong *param_2)

{
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_18;
  undefined4 local_14;
  code *local_10 [2];
  
                    /* 0x19290  61  TmPrepareComplete */
  local_res18[0] = 0;
  local_10[0] = TmpTxActionDoPrepareComplete;
  local_14 = 0x101;
  local_18 = 0x102;
  local_res20[0] = 2;
  TmpProcessNotificationResponse
            (param_1,param_2,1,(longlong)&local_14,(longlong)&local_18,(longlong)local_res20,
             (longlong)local_10,(longlong)local_res18);
  return;
}



===== TmpProcessNotificationResponse @ 1400192fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
TmpProcessNotificationResponse
          (longlong param_1,longlong *param_2,uint param_3,longlong param_4,longlong param_5,
          longlong param_6,longlong param_7,longlong param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  char local_48;
  uint local_44;
  undefined4 local_40;
  longlong local_38;
  undefined1 *local_30;
  
  local_30 = auStack_78;
  lVar2 = *(longlong *)(param_1 + 0xa0);
  local_40 = 0;
  lVar3 = *(longlong *)(param_1 + 0x98);
  local_38 = lVar2;
  ObfReferenceObject(lVar2);
  ObfReferenceObject(param_1);
  TmpAcquireTransactionMutex(lVar2);
  local_58 = 0;
  KeWaitForSingleObject(param_1 + 0x40,0,0,0);
  local_48 = '\x01';
  if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
    local_44 = 0;
    while( true ) {
      uVar5 = (ulonglong)local_44;
      lVar1 = uVar5 * 4;
      if ((param_3 <= local_44) ||
         ((*(int *)(lVar2 + 0xc0) == *(int *)(lVar1 + param_6) &&
          (*(int *)(param_1 + 0xa8) == *(int *)(lVar1 + param_4))))) break;
      local_44 = local_44 + 1;
    }
    if (local_44 != param_3) {
      if ((param_2 != (longlong *)0x0) && (*(longlong *)(lVar3 + 0x168) == 0)) {
        _local_unwind(local_30,0x14001940d);
        return 0xc0190052;
      }
      TmpAdjustVirtualClock(*(longlong *)(lVar3 + 0x168),param_2);
      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(lVar1 + param_5);
      if ((*(int *)(lVar1 + param_8) == 1) ||
         ((*(int *)(lVar1 + param_8) == 2 && ((*(uint *)(param_1 + 0xb0) & 4) == 0)))) {
        TmpFinalizeEnlistment(param_1);
      }
      KeReleaseMutex(param_1 + 0x40,0);
      local_48 = '\0';
      if ((*(longlong *)(param_7 + uVar5 * 8) != 0) &&
         (iVar4 = *(int *)(lVar2 + 0xec) + -1, *(int *)(lVar2 + 0xec) = iVar4, iVar4 == 0)) {
        local_40 = (**(code **)(param_7 + (ulonglong)local_44 * 8))(lVar2,0);
      }
      goto LAB_1400194c1;
    }
  }
  local_40 = 0xc0190014;
LAB_1400194c1:
  if (local_48 != '\0') {
    KeReleaseMutex(param_1 + 0x40,0);
  }
  KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  ObfDereferenceObject(lVar2);
  ObfDereferenceObject(param_1);
  return local_40;
}



===== TmDereferenceEnlistmentKey @ 140019520 =====

undefined8 TmDereferenceEnlistmentKey(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
                    /* 0x19520  49  TmDereferenceEnlistmentKey */
  uVar2 = 0;
  KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
  if (*(int *)(param_1 + 0xc0) == 0) {
    uVar2 = 0xc0000001;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc0) + -1;
    *(int *)(param_1 + 0xc0) = iVar1;
    if (param_2 != 0) {
      *(bool *)param_2 = iVar1 == 0;
    }
  }
  KeReleaseMutex(param_1 + 0x40,0);
  return uVar2;
}



===== TmEnableCallbacks @ 1400195b0 =====

undefined4 TmEnableCallbacks(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *plVar5;
  
                    /* 0x195b0  50  TmEnableCallbacks */
  uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0xc0000001;
  }
  else {
    KeWaitForSingleObject(param_1 + 0x28,0,0,0,0);
    *(longlong *)(param_1 + 0x128) = param_2;
    if (param_3 != 0) {
      *(longlong *)(param_1 + 0x130) = param_3;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    KeWaitForSingleObject(param_1 + 0xd8,0,0,0,0);
    plVar3 = (longlong *)KeRundownQueue(param_1 + 0x98);
    KeInitializeQueue(param_1 + 0x98);
    KeResetEvent(param_1);
    KeReleaseMutex(param_1 + 0x28);
    KeReleaseMutex(param_1 + 0xd8);
    if (plVar3 != (longlong *)0x0) {
      plVar5 = plVar3;
      do {
        uVar4 = -(ulonglong)(*(uint *)(plVar5 + 6) != 0) & (ulonglong)(plVar5 + 7);
        uVar2 = TmpSetNotificationResourceManager
                          (param_1,uVar4,plVar5[2],plVar5[3],(int)plVar5[4],*(uint *)(plVar5 + 6),
                           (void *)uVar4);
        if (plVar5[2] != 0) {
          ObfDereferenceObject();
          plVar5[2] = 0;
        }
        plVar1 = (longlong *)*plVar5;
        ExFreePoolWithTag(plVar5);
        plVar5 = plVar1;
      } while (plVar3 != plVar1);
    }
  }
  return uVar2;
}



===== TmpSetNotificationResourceManager @ 140019738 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
TmpSetNotificationResourceManager
          (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,int param_5,
          uint param_6,void *param_7)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  char cVar7;
  undefined4 uVar8;
  void *_Dst;
  longlong *plVar9;
  undefined1 *puVar10;
  uint7 uVar11;
  ulonglong _Size;
  void *pvVar12;
  longlong local_res8;
  undefined8 local_res10;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong *local_68;
  uint local_60;
  void *local_58;
  
  local_68 = (longlong *)0x0;
  _Size = param_1 + 0x28;
  local_res10 = param_2;
  KeWaitForSingleObject(_Size,0,0,0);
  puVar10 = auStack_88;
  if (*(longlong *)(param_1 + 0x168) == 0) {
LAB_140019afd:
    *(undefined8 *)(puVar10 + -8) = 0x140019b09;
    KeReleaseMutex(_Size,0);
    return 0xc0190051;
  }
  ExAcquireFastMutex(*(longlong *)(param_1 + 0x168) + 0x250);
  local_res8 = *(longlong *)(*(longlong *)(param_1 + 0x168) + 0x248);
  ExReleaseFastMutex(*(longlong *)(param_1 + 0x168) + 0x250);
  KeReleaseMutex(_Size,0);
  lVar3 = local_res8;
  if ((*(code **)(param_1 + 0x128) != (code *)0x0) && ((*(uint *)(param_1 + 0x20) & 1) == 0)) {
    local_68 = &local_res8;
    local_58 = param_7;
    local_60 = param_6;
    uVar8 = (**(code **)(param_1 + 0x128))(param_3,*(undefined8 *)(param_1 + 0x130),param_4,param_5)
    ;
    if (lVar3 == local_res8) {
      return uVar8;
    }
    local_68 = (longlong *)0x0;
    KeWaitForSingleObject(_Size,0,0,0);
    TmpAdjustVirtualClock(*(longlong *)(param_1 + 0x168),&local_res8);
    KeReleaseMutex(_Size,0);
    return uVar8;
  }
  _Size = (ulonglong)param_6;
  if (0xffffdffe < param_6) {
    return 0xc000000d;
  }
  _Dst = (void *)0x0;
  local_res10 = CONCAT44(local_res10._4_4_,param_6 + 0x20);
  if (param_3 == 0) {
LAB_140019945:
    _Dst = (void *)ExAllocatePoolWithTag(0x200,param_6 + 0x38,0x6f4e6d54);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)(param_6 + 0x38));
    if (param_3 != 0) goto LAB_140019986;
  }
  else {
    if ((*(uint *)(param_3 + 0xac) & 1) == 0) {
      if ((param_5 - 4U & 0xfffffffb) == 0) goto LAB_1400198f8;
      goto LAB_140019945;
    }
    if ((param_5 == 0x40) || (param_5 == 8)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (!bVar5) goto LAB_140019945;
LAB_1400198f8:
    local_68 = (longlong *)0x0;
    KeWaitForSingleObject(param_3 + 0x40,0,0,0);
    if ((*(uint *)(param_3 + 0xac) & 8) == 0) {
      _Dst = *(void **)(param_3 + 0xe8);
      LOCK();
      *(uint *)(param_3 + 0xac) = *(uint *)(param_3 + 0xac) | 8;
      UNLOCK();
    }
    KeReleaseMutex(param_3 + 0x40,0);
    if (_Dst == (void *)0x0) goto LAB_140019945;
LAB_140019986:
    if (*(longlong *)(param_1 + 0x128) != 0) {
      *(longlong *)((longlong)_Dst + 0x10) = param_3;
      ObfReferenceObject(param_3);
      goto LAB_1400199aa;
    }
  }
  *(undefined8 *)((longlong)_Dst + 0x10) = 0;
LAB_1400199aa:
  *(undefined8 *)((longlong)_Dst + 0x18) = param_4;
  *(int *)((longlong)_Dst + 0x20) = param_5;
  *(longlong *)((longlong)_Dst + 0x28) = local_res8;
  *(uint *)((longlong)_Dst + 0x30) = param_6;
  memcpy((void *)((longlong)_Dst + 0x38),param_7,_Size);
  local_68 = (longlong *)0x0;
  KeWaitForSingleObject(param_1 + 0xd8,0,0,0);
  uVar6 = (uint)local_res10;
  plVar1 = (longlong *)(param_1 + 0x228);
  do {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
LAB_140019ab4:
      KeInsertQueue(param_1 + 0x98,_Dst);
      KeSetEvent(param_1,0,0);
LAB_140019ade:
      KeReleaseMutex(param_1 + 0xd8,0);
      return 0x103;
    }
    plVar9 = plVar2;
    do {
      uVar11 = (uint7)(_Size >> 8);
      if (uVar6 <= *(uint *)(plVar9 + 3)) {
        if (plVar9 != (longlong *)0x0) {
          lVar3 = *plVar9;
          if ((*(longlong **)(lVar3 + 8) != plVar9) ||
             (plVar2 = (longlong *)plVar9[1], (longlong *)*plVar2 != plVar9)) goto LAB_140019af6;
          *plVar2 = lVar3;
          *(longlong **)(lVar3 + 8) = plVar2;
          uVar8 = 0;
          _Size = (ulonglong)uVar11 << 8;
          goto LAB_140019a80;
        }
        break;
      }
      plVar9 = (longlong *)*plVar9;
    } while (plVar9 != plVar1);
    lVar3 = *plVar2;
    if (((longlong *)*(longlong *)(lVar3 + 8) != plVar2) ||
       (plVar9 = (longlong *)plVar2[1], (longlong *)*plVar9 != plVar2)) {
LAB_140019af6:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar10 = auStack_80;
      goto LAB_140019afd;
    }
    *plVar9 = lVar3;
    uVar8 = 0xc0000023;
    *(longlong **)(lVar3 + 8) = plVar9;
    _Size = CONCAT71(uVar11,1);
    plVar9 = plVar2;
LAB_140019a80:
    pvVar12 = (void *)0x0;
    if ((char)_Size == '\0') {
      pvVar12 = _Dst;
    }
    cVar7 = TmpQueueCompletionNotificationRequest((longlong)plVar9,uVar8,pvVar12,uVar6);
    if (cVar7 != '\0') {
      if ((char)_Size == '\0') goto LAB_140019ade;
      goto LAB_140019ab4;
    }
    *(undefined4 *)((longlong)plVar9 + 0x1c) = 0xc0000120;
    TmpCompleteNotificationRequestPacket((longlong)plVar9,0);
  } while( true );
}



===== TmpDelegateDisconnect @ 140019b34 =====

undefined8 TmpDelegateDisconnect(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0xa0);
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmpDelegateDisconnect for tx %lx\n",lVar1);
  ObfReferenceObject(lVar1);
  ObfReferenceObject(param_1);
  TmpAcquireTransactionMutex(lVar1);
  uVar3 = 0;
  KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
  *(undefined4 *)(param_1 + 0xa8) = 0x109;
  TmpFinalizeEnlistment(param_1);
  *(int *)(lVar1 + 0xec) = *(int *)(lVar1 + 0xec) + -1;
  uVar2 = 0;
  KeReleaseMutex(param_1 + 0x40);
  TmpTxActionDoDelegateDisconnect(lVar1,uVar2,uVar3);
  KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  ObfDereferenceObject(lVar1);
  ObfDereferenceObject(param_1);
  return 0;
}



===== TmpFinalizeEnlistment @ 140019c30 =====

undefined8 TmpFinalizeEnlistment(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  code *pcVar8;
  undefined8 uVar9;
  
  lVar2 = *(longlong *)(param_1 + 0xa0);
  lVar3 = *(longlong *)(param_1 + 0x98);
  if ((*(uint *)(param_1 + 0xac) & 4) == 0) {
    LOCK();
    *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 4;
    UNLOCK();
    KeReleaseMutex(param_1 + 0x40,0);
    TmpAcquireTransactionMutex(lVar2);
    lVar3 = lVar3 + 0x28;
    KeWaitForSingleObject(lVar3,0,0,0,0);
    TmpRemoveTransactionEnlistmentCounts(param_1);
    if ((*(uint *)(param_1 + 0xac) & 1) != 0) {
      *(undefined8 *)(lVar2 + 0xf0) = 0;
    }
    plVar1 = (longlong *)(param_1 + 0x78);
    lVar4 = *plVar1;
    if ((*(longlong **)(lVar4 + 8) != plVar1) ||
       (plVar5 = *(longlong **)(param_1 + 0x80), (longlong *)*plVar5 != plVar1)) {
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)(3);
      pcVar8 = (code *)swi(3);
      uVar9 = (*pcVar8)();
      return uVar9;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    TmpRemoveEnlistmentResourceManager(param_1);
    ObfDereferenceObject(param_1);
    ObfDereferenceObject(param_1);
    if (((*(uint *)(param_1 + 0xac) & 0x20) != 0) &&
       (lVar4 = *(longlong *)(param_1 + 0xf0), lVar4 != 0)) {
      lVar6 = *(longlong *)(lVar4 + 0xf8);
      lVar7 = *(longlong *)(param_1 + 0xf8);
      uVar9 = *(undefined8 *)(lVar4 + 0xf0);
      *(undefined8 *)(lVar4 + 0xf0) = 0;
      *(undefined8 *)(*(longlong *)(param_1 + 0xf0) + 0xf8) = 0;
      *(undefined8 *)(param_1 + 0xf0) = 0;
      *(undefined8 *)(param_1 + 0xf8) = 0;
      if (lVar7 != 0) {
        ZwClose();
      }
      if (lVar6 != 0) {
        ZwClose(lVar6);
      }
      ObfDereferenceObject(lVar4);
      ObfDereferenceObject(uVar9);
    }
    if (*(longlong *)(param_1 + 0x100) != 0) {
      ZwClose();
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    KeReleaseMutex(lVar3,0);
    KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
    ObfDereferenceObject(param_1);
  }
  return 0;
}



===== TmpAcquireTransactionMutex @ 140019e54 =====

void TmpAcquireTransactionMutex(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  while( true ) {
    KeWaitForSingleObject(lVar1 + 0x20,0,0,0,0);
    if (*(longlong *)(lVar1 + 0x58) == lVar1) break;
    KeReleaseMutex(lVar1 + 0x20);
    lVar1 = *(longlong *)(lVar1 + 0x58);
  }
  return;
}



===== TmpTxActionDoDelegateDisconnect @ 140019ec0 =====

int TmpTxActionDoDelegateDisconnect(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,param_1,param_1 + 0xb0);
  }
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 4;
  KeSetEvent(param_1,0);
  iVar1 = TmpNotifyAllEnlistmentsTransaction(param_1,0x1000000,uVar2,0x10f);
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    iVar1 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x1000000,'\x01',0x10f);
  }
  *(undefined4 *)(param_1 + 0xc0) = 9;
  TmpFinalizeTransaction(param_1);
  return iVar1;
}



===== TmpFinalizeTransaction @ 140019f84 =====

undefined8 TmpFinalizeTransaction(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  longlong *unaff_RBX;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  
  bVar3 = false;
  if ((*(uint *)(param_1 + 0xc4) & 0x10000000) == 0) {
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x10000000;
    UNLOCK();
    if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0) {
      local_28 = 0;
      KeWaitForSingleObject(*(longlong *)(param_1 + 0x200) + 0x200,0,0,0);
      if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0) {
        plVar9 = (longlong *)(param_1 + 0x1e8);
        if (*(longlong **)(*(longlong *)(param_1 + 0x200) + 0x238) == plVar9) {
          uVar4 = ClfsLsnContainer(*(longlong *)(param_1 + 0x200) + 0x288);
          unaff_RBX = (longlong *)(ulonglong)uVar4;
          uVar5 = ClfsLsnContainer(param_1 + 0xf8);
          bVar3 = false;
          if (uVar4 < uVar5) {
            bVar3 = true;
          }
        }
        lVar1 = *plVar9;
        if ((*(longlong **)(lVar1 + 8) != plVar9) ||
           (plVar6 = *(longlong **)(param_1 + 0x1f0), (longlong *)*plVar6 != plVar9)) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          puVar7 = auStack_40;
          goto LAB_14001a0c7;
        }
        *plVar6 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar6;
        *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)CLFS_LSN_NULL_exref;
        LOCK();
        *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xff7fffff;
        UNLOCK();
      }
      KeReleaseMutex(*(longlong *)(param_1 + 0x200) + 0x200,0);
    }
    puVar7 = auStack_48;
    puVar8 = auStack_48;
    if (((*(uint *)(param_1 + 0xc4) >> 8 & 1) != 0) &&
       (puVar8 = auStack_48, (*(uint *)(param_1 + 0xc4) >> 10 & 1) != 0)) {
      plVar9 = (longlong *)(param_1 + 0x100);
      plVar6 = (longlong *)*plVar9;
      while (unaff_RBX = plVar6, puVar8 = puVar7, plVar6 != plVar9) {
LAB_14001a0c7:
        plVar6 = (longlong *)*unaff_RBX;
        if (unaff_RBX[0x36] != 0) {
          *(undefined8 *)(puVar7 + -8) = 0x14001a0e4;
          ZwClose();
          unaff_RBX[0x36] = 0;
        }
        *(undefined8 *)(puVar7 + -8) = 0x14001a0fb;
        ObfDereferenceObject(unaff_RBX + -0x20);
      }
    }
    lVar1 = *(longlong *)(param_1 + 0x200);
    if (lVar1 != 0) {
      *(undefined1 *)(param_1 + 0xa8) = 1;
    }
    *(undefined1 *)(param_1 + 0x80) = 1;
    if ((bVar3) && (lVar1 != 0)) {
      *(undefined8 *)(puVar8 + -8) = 0x14001a134;
      TmpQueueCheckpointTm(lVar1);
    }
    *(undefined8 *)(puVar8 + -8) = 0x14001a13e;
    ObfDereferenceObject(param_1);
  }
  return 0;
}



===== TmpNotifyAllEnlistmentsTransaction @ 14001a168 =====

int TmpNotifyAllEnlistmentsTransaction(longlong param_1,uint param_2,undefined8 param_3,int param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  longlong *plVar8;
  
  iVar3 = *(int *)(param_1 + 0xc0);
  plVar2 = (longlong *)(param_1 + 200);
  plVar8 = (longlong *)*plVar2;
  iVar7 = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  if (plVar8 != plVar2) {
    do {
      if (((*(uint *)((longlong)plVar8 + 0x34) & 1) == 0) &&
         ((*(uint *)(plVar8 + 7) & param_2) != 0)) {
        *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar2);
    plVar8 = (longlong *)*plVar2;
  }
  plVar6 = (longlong *)0x0;
  if (plVar8 != plVar2) {
    do {
      if (plVar6 != (longlong *)0x0) {
        ObfDereferenceObject(plVar6);
      }
      plVar6 = plVar8 + -0xf;
      ObfReferenceObject(plVar6);
      if (((*(uint *)((longlong)plVar8 + 0x34) & 1) == 0) &&
         ((param_2 & *(uint *)(plVar8 + 7)) != 0)) {
        plVar1 = plVar8 + -7;
        KeWaitForSingleObject(plVar1,0,0,0,0);
        *(int *)(plVar8 + 6) = param_4;
        *(uint *)((longlong)plVar8 + (ulonglong)*(uint *)(plVar8 + 0x18) * 8 + 0xc4) = param_2;
        *(int *)(plVar8 + (ulonglong)*(uint *)(plVar8 + 0x18) + 0x19) = param_4;
        *(int *)(plVar8 + 0x18) = (int)plVar8[0x18] + 1;
        if (0x13 < *(uint *)(plVar8 + 0x18)) {
          *(undefined4 *)(plVar8 + 0x18) = 0;
        }
        KeReleaseMutex(plVar1,0);
        uVar5 = 0x80000020;
        DbgPrintEx(0x6c,0x80000020,"KTM:  Notifying RM of %d for tx %lx\n",param_2,plVar8[5]);
        iVar4 = TmpSetNotificationResourceManager
                          (plVar8[4],uVar5,(longlong)plVar6,plVar8[8],param_2,0,(void *)0x0);
        if (iVar4 < 0) {
          if (-1 < iVar7) {
LAB_14001a2fd:
            iVar7 = iVar4;
          }
        }
        else if (iVar7 == 0) goto LAB_14001a2fd;
        if ((param_4 - 0x10dU & 0xfffffffd) == 0) {
          KeWaitForSingleObject(plVar1);
          TmpFinalizeEnlistment((longlong)plVar6);
          KeReleaseMutex(plVar1);
        }
        else if (*(int *)(param_1 + 0xc0) != iVar3) break;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar2);
    if (plVar6 != (longlong *)0x0) {
      ObfDereferenceObject(plVar6);
    }
  }
  return iVar7;
}



===== TmpIsClusteredTransactionManager @ 14001a390 =====

int TmpIsClusteredTransactionManager(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 local_res8 [8];
  longlong local_res20;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res20 = 0;
  local_28 = 0;
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  ClfsPrivGetBaseLogFileFromFileObjectPointer(*(undefined8 *)(param_1 + 0x98),&local_res20);
  lVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res20 + 8));
  KeInitializeEvent(&local_38,0,0);
  lVar3 = IoBuildDeviceIoControlRequest(0x700f8,lVar2,0,0,local_res8,8,0,&local_38,&local_48);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(lVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_38,0,0,0,0);
      iVar1 = (int)local_48;
    }
    if (iVar1 == -0x3ffffff0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_aa500d615f02383f20d25780cb696015_Traceguids);
      }
      local_res8[0] = 0;
      iVar1 = 0;
    }
    else if (iVar1 < 0) goto LAB_14001a46f;
    *param_2 = local_res8[0];
  }
LAB_14001a46f:
  if (lVar2 != 0) {
    ObfDereferenceObject(lVar2);
  }
  return iVar1;
}



===== NtCommitTransaction @ 14001a510 =====

int NtCommitTransaction(undefined8 param_1,char param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res18 [2];
  
                    /* 0x1a510  5  NtCommitTransaction */
  local_res18[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,(-(uint)(param_2 != '\0') & 0x100000) + 8,TmTransactionObjectType,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    iVar2 = TmCommitTransaction(local_res18[0],param_2);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== TmCommitTransaction @ 14001a5b0 =====

int TmCommitTransaction(longlong param_1,char param_2)

{
  int iVar1;
  ulonglong uVar2;
  char *pcVar3;
  char *pcVar4;
  char local_res18 [16];
  
                    /* 0x1a5b0  46  TmCommitTransaction */
  iVar1 = -0x3fe6ffed;
  pcVar4 = "KTM:  TmCommitTransactionExt for tx %lx\n";
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmCommitTransactionExt for tx %lx\n",param_1);
  TmpAcquireTransactionMutex(param_1);
  if (((*(longlong *)(param_1 + 0xf0) != 0) && ((*(uint *)(param_1 + 0xc4) & 2) == 0)) &&
     ((*(uint *)(param_1 + 0xc4) >> 0xc & 1) == 0)) {
    iVar1 = -0x3fe6ffee;
    goto LAB_14001a747;
  }
  if (*(int *)(param_1 + 0x1f8) != 3) {
    if (*(int *)(param_1 + 0x1f8) == 2) {
      iVar1 = -0x3fe6ffea;
      goto LAB_14001a747;
    }
    if (((*(uint *)(param_1 + 0xc4) >> 0xc & 1) != 0) && ((*(uint *)(param_1 + 0xc4) & 2) == 0)) {
      iVar1 = TmpForwardCommitTransaction(param_1);
      goto LAB_14001a747;
    }
    LOCK();
    *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 2;
    UNLOCK();
    if (*(int *)(param_1 + 0xc0) != 1) goto LAB_14001a747;
    local_res18[0] = '\0';
    if (*(longlong *)(param_1 + 0x200) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,pcVar4,param_1,param_1 + 0xb0);
      }
      *(undefined4 *)(param_1 + 0xc0) = 9;
      *(undefined4 *)(param_1 + 0x1f8) = 2;
      KeSetEvent(param_1,0,0);
      TmpFinalizeTransaction(param_1);
      iVar1 = 0;
      goto LAB_14001a747;
    }
    pcVar3 = local_res18;
    iVar1 = TmpTxActionTrySinglePhase(param_1,pcVar3,pcVar4);
    if (iVar1 < 0) goto LAB_14001a747;
    if (local_res18[0] == '\0') {
      LOCK();
      *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 4;
      UNLOCK();
      iVar1 = TmpTxActionDoPrePrepare(param_1,pcVar3,pcVar4);
    }
    if ((*(int *)(param_1 + 0xc0) != 6) && (*(int *)(param_1 + 0x1f8) != 3)) goto LAB_14001a747;
  }
  iVar1 = -0x3fe6ffeb;
LAB_14001a747:
  if ((iVar1 != 0x103) || (param_2 == '\0')) {
    *(undefined4 *)(param_1 + 0x210 + (ulonglong)(*(uint *)(param_1 + 0x260) % 10) * 8) = 1;
    *(int *)(param_1 + 0x214 + (ulonglong)(*(uint *)(param_1 + 0x260) % 10) * 8) = iVar1;
    *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
  }
  KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  if ((iVar1 == 0x103) && (param_2 != '\0')) {
    uVar2 = TmpWaitForTransactionOutcome(param_1,2);
    iVar1 = (int)uVar2;
    TmpAcquireTransactionMutex(param_1);
    *(undefined4 *)(param_1 + 0x210 + (ulonglong)(*(uint *)(param_1 + 0x260) % 10) * 8) = 1;
    *(int *)(param_1 + 0x214 + (ulonglong)(*(uint *)(param_1 + 0x260) % 10) * 8) = iVar1;
    *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
    KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  }
  return iVar1;
}



===== TmpTxActionTrySinglePhase @ 14001a848 =====

int TmpTxActionTrySinglePhase(longlong param_1,undefined1 *param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  *param_2 = 0;
  if (*(int *)(param_1 + 0xe4) == 1) {
    lVar3 = param_1;
    lVar2 = TmpFindSinglePhaseEnlistment(param_1);
    if (lVar2 == 0) {
      iVar1 = 0;
    }
    else {
      *(undefined4 *)(lVar3 + 0xc0) = 7;
      LOCK();
      *(uint *)(lVar3 + 0xc4) = *(uint *)(lVar3 + 0xc4) & 0xfffeffff;
      UNLOCK();
      iVar1 = TmpNotifyAllEnlistmentsTransaction(lVar3,0x200,param_3,0x108);
      *param_2 = 1;
      if (iVar1 < 0) {
        TmRollbackTransaction(param_1,'\0');
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== NtQueryInformationTransaction @ 14001a8d0 =====

ulonglong NtQueryInformationTransaction
                    (undefined8 param_1,uint param_2,uint *param_3,uint param_4,uint *param_5)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint *puVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  uint local_128;
  uint local_124;
  longlong local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  ulonglong local_f0;
  ulonglong uStack_e8;
  undefined8 *local_e0;
  undefined8 *local_d8;
  longlong local_d0;
  undefined8 uStack_c8;
  uint *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  
                    /* 0x1a8d0  25  NtQueryInformationTransaction */
  local_d0 = 0;
  uStack_c8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_128 = 0;
  local_124 = 0;
  if ((3 < param_2) && (param_2 != 5)) {
    return 0xc0000003;
  }
  if (param_2 == 0) {
    if (param_4 != 0x18) {
      return 0xc0000004;
    }
LAB_14001a983:
    uVar13 = 4;
  }
  else {
    if ((param_2 == 1) || (param_2 == 2)) goto LAB_14001a983;
    if (param_2 == 3) {
      if (param_4 != 0x20) {
        return 0xc0000004;
      }
      uVar13 = 4;
    }
    else {
      uVar13 = 0;
      if (param_2 == 5) {
        uVar13 = 1;
      }
    }
  }
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if ((cVar1 != '\0') && (ProbeForWrite(param_3,(ulonglong)param_4,uVar13), param_5 != (uint *)0x0))
  {
    puVar11 = param_5;
    if (*(uint **)MmUserProbeAddress_exref <= param_5) {
      puVar11 = *(uint **)MmUserProbeAddress_exref;
    }
    *puVar11 = *puVar11;
  }
  local_108 = 0;
  uVar9 = ObReferenceObjectByHandle(param_1,1,TmTransactionObjectType,cVar1,&local_108,0);
  lVar7 = local_108;
  uVar12 = uVar9 & 0xffffffff;
  if ((int)uVar9 < 0) {
    return uVar9;
  }
  if (param_2 != 5) {
    TmpAcquireTransactionMutex(local_108);
  }
  if (param_2 == 0) {
    local_d0 = *(longlong *)(lVar7 + 0xb0);
    uStack_c8 = *(undefined8 *)(lVar7 + 0xb8);
    uVar10 = *(uint *)(lVar7 + 0x1f8);
    *(longlong *)param_3 = local_d0;
    *(undefined8 *)(param_3 + 2) = uStack_c8;
    param_3[4] = 1;
    param_3[5] = uVar10;
    local_128 = 0x18;
    goto LAB_14001ae43;
  }
  if (param_2 == 1) {
    if (0x1f < param_4) {
      local_100 = *(undefined8 *)(lVar7 + 0x120);
      uStack_f8 = *(undefined8 *)(lVar7 + 0x128);
      local_f0 = (ulonglong)CONCAT24(*(undefined2 *)(lVar7 + 0x130),*(undefined4 *)(lVar7 + 0x1f8));
      uStack_e8 = uStack_e8 & 0xffffffffffff0000;
      *(undefined8 *)param_3 = local_100;
      *(undefined8 *)(param_3 + 2) = uStack_f8;
      *(ulonglong *)(param_3 + 4) = local_f0;
      *(ulonglong *)(param_3 + 6) = uStack_e8;
      uVar10 = *(ushort *)(lVar7 + 0x130) + 0x18;
      local_128 = uVar10;
      if (uVar10 < 0x20) {
        local_128 = 0x20;
      }
      if (param_4 < uVar10) {
        uVar12 = 0x80000005;
      }
      uVar8 = param_4 - 0x18;
      if (param_4 >= uVar10) {
        uVar8 = (uint)*(ushort *)(lVar7 + 0x130);
      }
      memcpy(param_3 + 6,*(void **)(lVar7 + 0x138),(ulonglong)uVar8);
      goto LAB_14001ae43;
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        if (*(longlong *)(lVar7 + 0xf0) == 0) {
          uVar12 = 0xc019005f;
        }
        else {
          KeWaitForSingleObject(*(longlong *)(lVar7 + 0xf0) + 0x40,0,0,0,0);
          lVar2 = *(longlong *)(lVar7 + 0xf0);
          uVar13 = *(undefined8 *)(lVar2 + 0x30);
          uVar4 = *(undefined8 *)(lVar2 + 0x38);
          uVar5 = *(undefined8 *)(*(longlong *)(lVar2 + 0x98) + 0x88);
          uVar6 = *(undefined8 *)(*(longlong *)(lVar2 + 0x98) + 0x90);
          local_b8 = uVar13;
          uStack_b0 = uVar4;
          local_a8 = uVar5;
          uStack_a0 = uVar6;
          KeReleaseMutex(lVar2 + 0x40,0);
          *(undefined8 *)param_3 = uVar13;
          *(undefined8 *)(param_3 + 2) = uVar4;
          *(undefined8 *)(param_3 + 4) = uVar5;
          *(undefined8 *)(param_3 + 6) = uVar6;
          local_128 = 0x20;
        }
      }
      else if (param_2 == 5) {
        KeWaitForSingleObject(lVar7 + 0x278,0,0,0,0);
        if (param_4 < *(uint *)(lVar7 + 0x270)) {
          uVar12 = 0xc0000023;
        }
        else {
          memcpy(param_3,*(void **)(lVar7 + 0x268),(ulonglong)*(uint *)(lVar7 + 0x270));
        }
        local_128 = *(uint *)(lVar7 + 0x270);
        KeReleaseMutex(lVar7 + 0x278,0);
      }
      goto LAB_14001ae43;
    }
    if (0x23 < param_4) {
      uStack_70 = 0;
      uVar10 = *(uint *)(lVar7 + 0xd8) - 1;
      if (*(longlong *)(lVar7 + 0xf0) == 0) {
        uVar10 = *(uint *)(lVar7 + 0xd8);
      }
      local_78 = (ulonglong)uVar10;
      *param_3 = uVar10;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
      param_3[8] = 0;
      if (uVar10 == 0) {
        local_128 = 0x24;
      }
      else {
        local_128 = uVar10 * 0x20 + 4;
      }
      if (param_4 < local_128) {
        uVar12 = 0x80000005;
      }
      puVar11 = param_3 + 1;
      local_e0 = *(undefined8 **)(lVar7 + 200);
      puVar14 = local_e0;
      local_c0 = puVar11;
      while (puVar14 != (undefined8 *)(lVar7 + 200)) {
        local_d8 = puVar14 + -0xf;
        puVar3 = (undefined8 *)*puVar14;
        local_e0 = puVar3;
        if (local_d8 != *(undefined8 **)(lVar7 + 0xf0)) {
          local_d0 = (ulonglong)local_124 * 0x20;
          if ((ulonglong)param_4 <
              (ulonglong)((longlong)puVar11 + (local_d0 - (longlong)param_3) + 0x20)) {
            uVar12 = 0x80000005;
            break;
          }
          KeWaitForSingleObject(puVar14 + -7,0,0,0,0);
          uVar13 = local_d8[6];
          uVar4 = local_d8[7];
          uVar5 = *(undefined8 *)(local_d8[0x13] + 0x88);
          uVar6 = *(undefined8 *)(local_d8[0x13] + 0x90);
          local_98 = uVar13;
          uStack_90 = uVar4;
          local_88 = uVar5;
          uStack_80 = uVar6;
          KeReleaseMutex(puVar14 + -7,0);
          local_124 = local_124 + 1;
          *(undefined8 *)(local_d0 + (longlong)local_c0) = uVar13;
          ((undefined8 *)(local_d0 + (longlong)local_c0))[1] = uVar4;
          puVar14 = (undefined8 *)(local_d0 + 0x10 + (longlong)local_c0);
          *puVar14 = uVar5;
          puVar14[1] = uVar6;
          puVar11 = local_c0;
        }
        puVar14 = puVar3;
      }
      goto LAB_14001ae43;
    }
  }
  uVar12 = 0xc0000023;
LAB_14001ae43:
  if (param_2 != 5) {
    KeReleaseMutex(*(longlong *)(lVar7 + 0x58) + 0x20,0);
  }
  ObfDereferenceObject(lVar7);
  if (param_5 != (uint *)0x0) {
    *param_5 = local_128;
  }
  return uVar12;
}



===== TmpCloseTransactionManager @ 14001aea0 =====

void TmpCloseTransactionManager
               (undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_4 != 1) {
    return;
  }
  TmpTmOffline(param_2);
  KeWaitForSingleObject(param_2 + 8,0,0,0,0);
  lVar1 = *(longlong *)(param_2 + 0x2a0);
  lVar2 = 0;
  if (lVar1 != 0) {
    *(undefined8 *)(param_2 + 0x2a0) = 0;
    lVar2 = lVar1;
  }
  lVar1 = *(longlong *)(param_2 + 0x2a8);
  lVar3 = 0;
  if (lVar1 != 0) {
    *(undefined8 *)(param_2 + 0x2a8) = 0;
    lVar3 = lVar1;
  }
  KeReleaseMutex(param_2 + 8,0);
  if (lVar2 != 0) {
    ZwClose(lVar2);
  }
  if (lVar3 != 0) {
    ObfDereferenceObject(lVar3);
  }
  return;
}



===== TmpTmOffline @ 14001af74 =====

undefined8 TmpTmOffline(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  KeEnterCriticalRegion();
  lVar1 = param_1 + 8;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  if (*(int *)(param_1 + 0x40) == 5) {
    KeReleaseMutex(lVar1,0);
    KeLeaveCriticalRegion();
  }
  else {
    if ((*(uint *)(param_1 + 0x80) & 1) == 0) {
      TmpCheckpoint(param_1,'\0');
    }
    *(undefined4 *)(param_1 + 0x40) = 5;
    if ((*(uint *)(param_1 + 0x80) & 4) != 0) {
      LOCK();
      DAT_140008200 = 0;
      UNLOCK();
    }
    if ((*(uint *)(param_1 + 0x80) & 2) != 0) {
      LOCK();
      DAT_140008204 = 0;
      UNLOCK();
    }
    TmpNamespaceExpire(param_1 + 0x158);
    TmpNamespaceForEach(param_1 + 0x158,(undefined *)0x0,TmpExpireNamespaceResourceManager);
    TmpNamespaceForEach(param_1 + 0xb0,(undefined *)0x0,TmpForgetAllEnlistmentsTransaction);
    ExAcquireResourceExclusiveLite(param_1 + 0x310);
    lVar2 = *(longlong *)(param_1 + 0xa8);
    lVar3 = 0;
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0xa8) = 0;
      lVar3 = lVar2;
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      ClfsDeleteMarshallingArea();
      *(undefined8 *)(param_1 + 0xa0) = 0;
    }
    if (*(longlong *)(param_1 + 0x98) != 0) {
      ClfsCloseLogFileObject();
      *(undefined8 *)(param_1 + 0x98) = 0;
    }
    ExReleaseResourceLite(param_1 + 0x310);
    lVar2 = *(longlong *)(param_1 + 0x48);
    KeReleaseMutex(lVar1);
    KeLeaveCriticalRegion();
    if (lVar2 != 0) {
      TmpNamespaceRemove(0x1400084e0,0,param_1);
    }
    if (lVar3 != 0) {
      ClfsMgmtDeregisterManagedClient(lVar3);
    }
  }
  return 0;
}



===== TmpNamespaceInitialize @ 14001b144 =====

undefined8 TmpNamespaceInitialize(longlong param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0xa0) = param_2;
  *(undefined2 *)(param_1 + 0xa2) = param_3;
  *(undefined1 *)(param_1 + 0xa4) = 0;
  KeInitializeMutex(param_1 + 0x68,0);
  RtlInitializeGenericTableAvl
            (param_1,TmpNamespaceCompareGuids,TmpNamespaceAllocateEntry,TmpNamespaceFreeEntry,0);
  return 0;
}



===== NtCreateEnlistment @ 14001b1b0 =====

/* WARNING: Removing unreachable block (ram,0x00014001b27c) */

int NtCreateEnlistment(undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,uint param_6,uint param_7,undefined8 param_8)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined4 local_48;
  
                    /* 0x1b1b0  6  NtCreateEnlistment */
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_90 = 0;
  local_88 = 0;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (cVar1 != '\0') {
    puVar4 = param_1;
    if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
      puVar4 = *(undefined8 **)MmUserProbeAddress_exref;
    }
    *puVar4 = *puVar4;
  }
  local_a0 = 0;
  iVar3 = ObReferenceObjectByHandle(param_3,8,TmResourceManagerObjectType,cVar1,&local_a0,0);
  lVar2 = local_a0;
  if (-1 < iVar3) {
    local_98 = (undefined8 *)0x0;
    iVar3 = ObReferenceObjectByHandle(param_4,4,TmTransactionObjectType,cVar1,&local_98,0);
    puVar4 = local_98;
    if (-1 < iVar3) {
      iVar3 = TmCreateEnlistment(param_1,cVar1,param_2,param_5,lVar2,local_98,param_6,param_7,
                                 param_8);
      ObfDereferenceObject(puVar4);
    }
    ObfDereferenceObject(lVar2);
  }
  return iVar3;
}



===== TmCreateEnlistment @ 14001b390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TmCreateEnlistment(undefined8 *param_1,char param_2,undefined4 param_3,undefined8 param_4,
                      longlong param_5,undefined8 *param_6,uint param_7,uint param_8,
                      undefined8 param_9)

{
  int iVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
                    /* 0x1b390  47  TmCreateEnlistment */
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_7 < 2) && ((param_8 & 0xc0000000) == 0)) {
    iVar1 = ObCreateObject(param_2,TmEnlistmentObjectType,param_4);
    if (-1 < iVar1) {
      uRam00000000000000a8 = 0;
      ExUuidCreate(&local_58);
      iVar1 = TmpInitializeEnlistment
                        ((undefined4 *)0x0,param_5,param_6,(undefined4 *)&local_58,param_7,param_8,
                         param_9);
      if (-1 < iVar1) {
        ObfReferenceObject(0);
        iVar1 = ObInsertObject(0,0,param_3,0);
        if (iVar1 < 0) {
          (**(code **)(TmEnlistmentObjectType + 0x80))(0,0,1,1);
        }
        else {
          LOCK();
          uRam00000000000000ac = uRam00000000000000ac | 0x100;
          UNLOCK();
          if (param_2 == '\0') {
            *param_1 = 0;
          }
          else {
            *param_1 = 0;
          }
        }
      }
      ObfDereferenceObject(0);
    }
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== TmReferenceEnlistmentKey @ 14001b5a0 =====

undefined8 TmReferenceEnlistmentKey(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
                    /* 0x1b5a0  69  TmReferenceEnlistmentKey */
  uVar2 = 0;
  if (param_2 == (undefined8 *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
    iVar1 = *(int *)(param_1 + 0xc0);
    if (iVar1 == 0) {
      uVar2 = 0xc0000001;
    }
    else if (iVar1 == -1) {
      uVar2 = 0xc000009a;
    }
    else {
      *(int *)(param_1 + 0xc0) = iVar1 + 1;
      *param_2 = *(undefined8 *)(param_1 + 0xb8);
    }
    KeReleaseMutex(param_1 + 0x40,0);
  }
  return uVar2;
}



===== NtRecoverTransactionManager @ 14001b650 =====

int NtRecoverTransactionManager
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined7 uVar5;
  
                    /* 0x1b650  30  NtRecoverTransactionManager */
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  cVar1 = PsIsComponentEnabled(1);
  if (cVar1 == '\0') {
    iVar2 = -0x3fffffde;
  }
  else {
    uVar4 = *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232);
    plVar3 = TmTransactionManagerObjectType;
    iVar2 = ObReferenceObjectByHandle(param_1);
    if (-1 < iVar2) {
      iVar2 = TmRecoverTransactionManager(0,(longlong *)0x0,plVar3,CONCAT71(uVar5,uVar4));
      ObfDereferenceObject(0);
    }
  }
  return iVar2;
}



===== TmRecoverTransactionManager @ 14001b700 =====

int TmRecoverTransactionManager
              (longlong param_1,longlong *param_2,longlong *param_3,ulonglong param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *plVar5;
  bool bVar6;
  longlong local_res18 [2];
  
                    /* 0x1b700  68  TmRecoverTransactionManager */
  local_res18[0] = 0;
  local_res18[1] = 0;
  bVar6 = false;
  plVar5 = param_2;
  TmpAcquireTxTableTransactionManager(param_1);
  if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
    iVar1 = -0x3fe6ffc5;
    param_2 = plVar5;
    goto LAB_14001b847;
  }
  bVar6 = (*(uint *)(param_1 + 0x80) & 0x80) != 0;
  if (*(int *)(param_1 + 0x40) == 3) {
    iVar1 = 0;
    param_2 = plVar5;
  }
  else if (*(int *)(param_1 + 0x40) == 2) {
    uVar2 = TmpRecover(param_1,param_2);
    iVar1 = (int)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if ((iVar1 != 0) && (iVar1 != -0x3fffffef)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        param_2 = (longlong *)0x2f;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,param_3,iVar1);
        param_4 = uVar2;
      }
      goto LAB_14001b847;
    }
    if (iVar1 != -0x3fffffef) goto LAB_14001b847;
    TmpNamespaceForEach(param_1 + 0xb0,(undefined *)0x0,TmpReacquireReservationTransaction);
    local_res18[0] = 2;
    param_4 = 0;
    param_3 = local_res18 + 1;
    param_2 = local_res18;
    ClfsMgmtSetLogFileSize(*(undefined8 *)(param_1 + 0x98));
    uVar3 = TmpTmOnline(param_1,param_2);
    iVar1 = (int)uVar3;
  }
  else {
    iVar1 = -0x3fffffff;
    param_2 = plVar5;
  }
LAB_14001b847:
  if ((*(int *)(param_1 + 0x40) == 2) && (iVar1 < 0)) {
    *(int *)(param_1 + 0x40) = 4;
    *(int *)(param_1 + 0x380) = iVar1;
  }
  lVar4 = param_1;
  TmpReleaseTxTableTransactionManager(param_1);
  TmpPromptRecoveryAllTransactionManagers(lVar4,param_2,param_3,param_4);
  if (bVar6) {
    TmpNamespaceForEach(param_1 + 0xb0,(undefined *)0x0,TmpHeuristicAbortTransaction);
  }
  return iVar1;
}



===== TmpCloseEnlistment @ 14001b8a0 =====

void TmpCloseEnlistment(undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4)

{
  if (param_4 == 1) {
    ObfReferenceObject(param_2);
    TmpRmDisconnectTransaction(param_2);
    *(undefined4 *)(param_2 + 0xa8) = 0x10c;
    ObfDereferenceObject(param_2);
    return;
  }
  return;
}



===== TmpRmDisconnectTransaction @ 14001b8f0 =====

undefined8 TmpRmDisconnectTransaction(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xa0);
  TmpAcquireTransactionMutex(lVar1);
  bVar2 = (*(uint *)(param_1 + 0xac) & 1) != 0;
  if (bVar2) {
    LOCK();
    *(uint *)(lVar1 + 0xc4) = *(uint *)(lVar1 + 0xc4) | 0x80;
    UNLOCK();
  }
  if (((*(uint *)(param_1 + 0xac) & 1) == 0) || (1 < *(int *)(lVar1 + 0xc0) - 3U)) {
    if (*(int *)(param_1 + 0xa8) == 0x108) {
      TmpDelegateDisconnect(param_1);
    }
    else {
      TmRollbackEnlistment(param_1,(longlong *)0x0);
    }
  }
  else {
    *(undefined4 *)(lVar1 + 0xc0) = 4;
  }
  if (bVar2) {
    LOCK();
    *(uint *)(lVar1 + 0xc4) = *(uint *)(lVar1 + 0xc4) & 0xffffff7f;
    UNLOCK();
  }
  KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  return 0;
}



===== TmFreezeTransactions @ 14001b9b0 =====

int TmFreezeTransactions(undefined8 param_1,undefined8 *param_2,undefined1 param_3)

{
  bool bVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  int *piVar7;
  undefined *puVar8;
  
                    /* 0x1b9b0  52  TmFreezeTransactions */
  puVar3 = (undefined8 *)0x0;
  bVar1 = false;
  KeWaitForSingleObject(&TmpFreezeMutex,0,0,0,0);
  if (TmpTransactionsFrozen == '\0') {
    puVar3 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x10,0x41576d54);
    if (puVar3 == (undefined8 *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      puVar5 = puVar3;
      KeResetEvent(&TmpTransactionThawEvent);
      KeResetEvent(&TmpTransactionFreezeCompleteEvent);
      KeResetEvent(&TmpTransactionFreezeCancelEvent);
      TmpTransactionsFrozen = '\x01';
      TmpTransactionsFreezeCancelled = 0;
      bVar1 = true;
      uVar4 = 1;
      TmpTransactionsCommittedActive = 0;
      uVar6 = 1;
      piVar7 = &TmpTransactionsCommittedActive;
      puVar8 = &TmpTransactionFreezeCompleteEvent;
      iVar2 = TmpNamespaceForEach(0x1400084e0,(undefined *)0x0,TmpFreezeThawTransactionManager);
      if (-1 < iVar2) {
        if (*piVar7 != 0) {
          *puVar3 = &TmpTransactionFreezeCompleteEvent;
          puVar3[1] = &TmpTransactionFreezeCancelEvent;
          iVar2 = KeWaitForMultipleObjects
                            (2,puVar3,1,6,param_3,0,param_1,0,uVar4,puVar5,uVar6,piVar7,puVar8);
          if (iVar2 != 0) {
            if (iVar2 == 1) {
              iVar2 = -0x3ffffee0;
              TmpTransactionsFreezeCancelled = 1;
            }
            goto LAB_14001bb91;
          }
        }
        KeSetTimer(&TmpTransactionThawTimer,*param_2,&TmpTransactionThawDpc);
      }
    }
  }
  else {
    iVar2 = -0x3fe6ffba;
  }
LAB_14001bb91:
  if ((bVar1) && (iVar2 != 0)) {
    TmThawTransactions();
  }
  KeReleaseMutex(&TmpFreezeMutex,0);
  if (puVar3 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar3,0);
  }
  return iVar2;
}



===== TmpNamespaceRename @ 14001bbf0 =====

int TmpNamespaceRename(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  
  puVar6 = (undefined8 *)((ulonglong)*(ushort *)(param_1 + 0xa2) + param_2);
  plVar5 = (longlong *)((ulonglong)*(ushort *)(param_1 + 0xa0) + param_2);
  if ((*plVar5 == 0) || ((char)plVar5[4] != '\0')) {
    uVar1 = param_3[1];
    *puVar6 = *param_3;
    puVar6[1] = uVar1;
    iVar4 = 0;
  }
  else {
    KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
    TmpNamespaceRemove(param_1,0,param_2);
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    uVar3 = param_3[1];
    *puVar6 = *param_3;
    puVar6[1] = uVar3;
    iVar4 = TmpNamespaceInsert(param_1,0,param_2);
    if (iVar4 < 0) {
      *puVar6 = uVar1;
      puVar6[1] = uVar2;
      TmpNamespaceInsert(param_1,0,param_2);
    }
    KeReleaseMutex(param_1 + 0x68,0);
  }
  return iVar4;
}



===== TmpReleaseTxTableTransactionManager @ 14001bce0 =====

void TmpReleaseTxTableTransactionManager(longlong param_1)

{
  KeReleaseMutex(param_1 + 0x118,0);
  KeReleaseMutex(param_1 + 8,0);
  return;
}



===== TmpTxActionDoPrePrepare @ 14001bd20 =====

int TmpTxActionDoPrePrepare(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xc0) = 8;
  plVar1 = *(longlong **)(param_1 + 200);
  if ((plVar1 == (longlong *)(param_1 + 200)) ||
     (((*(longlong *)(param_1 + 0xf0) != 0 && (plVar1 == (longlong *)*(longlong *)(param_1 + 0xd0)))
      || (*(int *)(param_1 + 0xe0) == 0)))) {
    iVar2 = TmpTxActionDoPrePrepareComplete(param_1,0);
  }
  else {
    iVar2 = TmpNotifyAllEnlistmentsTransaction(param_1,1,param_3,0x10a);
    if (iVar2 < 0) {
      TmRollbackTransaction(param_1,'\0');
    }
  }
  return iVar2;
}



===== TmpTxActionDoPrePrepareComplete @ 14001bdb0 =====

void TmpTxActionDoPrePrepareComplete(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  
  *(undefined4 *)(param_1 + 0xc0) = 0xb;
  if ((*(uint *)(param_1 + 0xc4) & 4) == 0) {
    if ((*(uint *)(param_1 + 0xc4) >> 10 & 1) != 0) {
      lVar1 = param_1;
      if ((*(uint *)(param_1 + 0xc4) >> 8 & 1) == 0) {
        lVar1 = *(longlong *)(param_1 + 0x110);
      }
      KeWaitForSingleObject(lVar1 + 0x2c0,0,0,0,0);
    }
    TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x10,'\x01',0x111);
  }
  else {
    *(undefined4 *)(param_1 + 0xc0) = 0xb;
    TmpTxActionDoPrepare(param_1,param_2);
  }
  return;
}



===== TmpCreateOrOpenLogTransactionManager @ 14001be50 =====

void TmpCreateOrOpenLogTransactionManager(longlong param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x40) = 2;
  iVar1 = TmpCreateLogFile(param_1);
  if ((*(int *)(param_1 + 0x40) == 2) && (iVar1 < 0)) {
    *(undefined4 *)(param_1 + 0x40) = 4;
  }
  return;
}



===== TmpCreateLogFile @ 14001be94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpCreateLogFile(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ushort uVar3;
  longlong lVar4;
  int iVar5;
  undefined2 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined1 auStack_188 [32];
  int local_128;
  char local_124;
  char local_123;
  undefined1 local_122;
  char local_121;
  undefined2 local_120;
  short local_11e;
  undefined4 local_11c;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  longlong local_f0 [7];
  undefined1 local_b8 [72];
  undefined8 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  local_11c = 0;
  local_f0[0] = 0;
  local_fc = 0;
  local_110 = 0;
  local_f0[2] = 0;
  local_f0[1] = 0;
  local_f0[6] = param_1;
  memset(local_b8,0,0x78);
  local_100 = 0x78;
  local_108 = 0;
  local_121 = '\0';
  local_124 = '\0';
  local_123 = '\0';
  uVar3 = *(ushort *)(param_1 + 0x88);
  if (0xffff < (uint)uVar3 + (uint)TmpLogPrefix) {
    return -0x7ffffffb;
  }
  local_120 = 0;
  local_11e = uVar3 + TmpLogPrefix;
  local_118 = ExAllocatePoolWithQuotaTag(9,local_11e,0x6e4c6d54);
  if (local_118 == 0) {
    return -0x3fffff66;
  }
  RtlCopyUnicodeString(&local_120,0);
  RtlAppendUnicodeStringToString(&local_120,&TmpLogPrefix);
  local_128 = RtlAppendUnicodeStringToString(&local_120,(ushort *)(param_1 + 0x88));
  if (local_128 < 0) goto LAB_14001c526;
  puVar1 = (undefined8 *)(param_1 + 0x98);
  puVar8 = (undefined8 *)0xc0000000;
  local_128 = ClfsCreateLogFile(puVar1,&local_120,0xc0000000,3);
  if (local_128 == -0x3fffffcc) {
    local_123 = '\x01';
    puVar8 = (undefined8 *)0xc0000000;
    local_128 = ClfsCreateLogFile(puVar1,&local_120,0xc0000000,3);
    if (local_128 == 0) goto LAB_14001c10f;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_14001c526;
    uVar6 = 0x21;
  }
  else if (local_128 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_14001c526;
    uVar6 = 0x22;
  }
  else {
LAB_14001c10f:
    local_128 = TmpIsClusteredTransactionManager(param_1,&local_124);
    if (local_128 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,puVar8,local_128);
      }
      goto LAB_14001c526;
    }
    if (local_124 != '\0') {
      LOCK();
      *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x100;
      UNLOCK();
      TmpStartKtmRm();
    }
    local_128 = TmpRegisterForLogManagement(param_1);
    if (local_128 == -0x3fffffcb) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                  &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_1,0x35);
      }
      local_128 = -0x3fe6ffd0;
    }
    if (local_128 < 0) goto LAB_14001c526;
    puVar2 = (undefined8 *)(param_1 + 0xa0);
    puVar8 = (undefined8 *)0x0;
    local_128 = ClfsCreateMarshallingArea(*puVar1,1,0,0);
    if (local_128 != 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_14001c526;
      uVar6 = 0x25;
      goto LAB_14001c519;
    }
    local_f0[1] = 0x20;
    uVar7 = 0;
    iVar5 = ClfsReserveAndAppendLog(*puVar2,0,0,0);
    if (iVar5 == 0) {
      LOCK();
      *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) | 2;
      UNLOCK();
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,uVar7,param_1,(char)iVar5);
    }
    if (local_123 == '\0') {
      ClfsGetLogFileInformation(*puVar1,local_b8,&local_100);
      *(undefined8 *)(param_1 + 0x290) = local_70;
      *(undefined8 *)(param_1 + 0x288) = local_70;
      puVar8 = (undefined8 *)&local_fc;
      local_128 = ClfsReadRestartArea(*puVar2,local_f0,puVar8,local_f0 + 2);
      if (local_128 == 0x401a000c) {
        local_f0[4] = 0;
        local_f0[3] = 0;
        local_f0[5] = 0;
        local_f8 = 0;
        local_122 = 3;
        local_128 = ClfsReadLogRecord(*puVar2,(undefined8 *)(param_1 + 0x290),3,local_f0 + 5);
        if ((local_128 != -0x3fe5ffed) && (local_128 != -0x3fffffef)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            uVar6 = 0x27;
LAB_14001c421:
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                      &WPP_f6ef95d1a8f137d176da5c2f75e5cc4c_Traceguids,param_1,(char)local_128);
          }
LAB_14001c434:
          local_128 = -0x3fe6ffd0;
          goto LAB_14001c526;
        }
        puVar8 = (undefined8 *)0x0;
        local_128 = TmpWriteRestartArea(param_1,(undefined8 *)0x0,'\0');
        if (local_128 < 0) goto LAB_14001c526;
        LOCK();
        *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xffffffdf;
        UNLOCK();
      }
      else {
        if (local_128 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
            uVar6 = 0x28;
            goto LAB_14001c421;
          }
          goto LAB_14001c434;
        }
        local_121 = '\x01';
      }
      if (local_121 != '\0') {
        if ((*(uint *)(param_1 + 0x80) & 0x20) == 0) {
          if ((*(longlong *)(local_f0[0] + 0xc) != *(longlong *)(param_1 + 0x70)) ||
             (*(longlong *)(local_f0[0] + 0x14) != *(longlong *)(param_1 + 0x78))) {
            local_128 = -0x3fe6ffb6;
            goto LAB_14001c526;
          }
        }
        else {
          puVar8 = (undefined8 *)(local_f0[0] + 0xc);
          local_128 = TmpNamespaceRename(0x1400084e0,param_1,puVar8);
          if (local_128 < 0) goto LAB_14001c526;
          LOCK();
          *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xffffffdf;
          UNLOCK();
        }
      }
    }
    else {
      puVar8 = (undefined8 *)0x0;
      local_128 = TmpWriteRestartArea(param_1,(undefined8 *)0x0,'\0');
      if (local_128 < 0) goto LAB_14001c526;
    }
    if (((local_128 == 0) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_14001c526;
    uVar6 = 0x29;
  }
LAB_14001c519:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar8,local_128);
LAB_14001c526:
  if (local_118 != 0) {
    ExFreePoolWithTag(local_118,0);
    local_118 = 0;
  }
  if (local_110 != 0) {
    ClfsTerminateReadLog();
  }
  if (local_128 < 0) {
    lVar4 = *(longlong *)(param_1 + 0xa8);
    if (lVar4 != 0) {
      *(undefined8 *)(param_1 + 0xa8) = 0;
      local_108 = lVar4;
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      ClfsDeleteMarshallingArea();
      *(undefined8 *)(param_1 + 0xa0) = 0;
    }
    if (*(longlong *)(param_1 + 0x98) != 0) {
      ClfsCloseLogFileObject();
      *(undefined8 *)(param_1 + 0x98) = 0;
    }
    if (local_108 != 0) {
      ClfsMgmtDeregisterManagedClient();
    }
  }
  return local_128;
}



===== TmpAcquireTxTableTransactionManager @ 14001c5dc =====

void TmpAcquireTxTableTransactionManager(longlong param_1)

{
  KeWaitForSingleObject(param_1 + 8,0,0,0,0);
  KeWaitForSingleObject(param_1 + 0x118,0,0,0,0);
  return;
}



===== TmpCloseTransaction @ 14001c640 =====

void TmpCloseTransaction(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  if ((param_4 == 1) || (param_3 == 1)) {
    TmRollbackTransaction(param_2,'\0');
  }
  return;
}



===== TmpNamespaceFreeEntry @ 14001c670 =====

void TmpNamespaceFreeEntry(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  return;
}



===== TmpNamespaceAllocateEntry @ 14001c690 =====

longlong TmpNamespaceAllocateEntry(longlong param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 0xa0) + **(longlong **)(param_1 + 0x60);
}



===== NtQueryInformationTransactionManager @ 14001c6b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtQueryInformationTransactionManager
              (undefined8 param_1,int param_2,uint *param_3,ulonglong param_4,undefined4 *param_5)

{
  longlong lVar1;
  ushort uVar2;
  longlong *plVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  char cVar8;
  int iVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined1 auStack_178 [32];
  longlong *local_158;
  undefined8 local_150;
  char local_148;
  int local_144;
  undefined4 local_140;
  longlong local_138;
  undefined4 local_130 [2];
  undefined4 *local_128;
  ulonglong local_120 [4];
  undefined8 local_100;
  uint *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined1 local_c8 [104];
  uint local_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  ulonglong local_48;
  
                    /* 0x1c6b0  26  NtQueryInformationTransactionManager */
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  uVar12 = param_4 & 0xffffffff;
  local_128 = param_5;
  local_e0 = 0;
  uStack_d8 = 0;
  local_120[3] = 0;
  local_120[2] = 0;
  local_148 = '\0';
  memset(local_c8,0,0x78);
  local_130[0] = 0;
  local_120[0] = 0;
  local_120[1] = 0;
  local_100 = 0;
  local_f8 = (uint *)0x0;
  local_140 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  cVar8 = PsIsComponentEnabled(1);
  if (cVar8 == '\0') {
    iVar9 = -0x3fffffde;
  }
  else if (((param_2 == 3) || (param_2 < 0)) || (5 < param_2)) {
    iVar9 = -0x3ffffffd;
  }
  else {
    iVar9 = (int)param_4;
    if (((((param_2 == 0) && (iVar9 != 0x18)) || ((param_2 == 1 && (iVar9 != 0x10)))) ||
        ((param_2 == 4 && (iVar9 != 8)))) || ((param_2 == 5 && (iVar9 != 0x10)))) {
      iVar9 = -0x3ffffffc;
    }
    else {
      cVar8 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
      if ((cVar8 != '\0') && (ProbeForWrite(param_3,uVar12), param_5 != (undefined4 *)0x0)) {
        puVar11 = param_5;
        if (*(undefined4 **)MmUserProbeAddress_exref <= param_5) {
          puVar11 = *(undefined4 **)MmUserProbeAddress_exref;
        }
        *puVar11 = *puVar11;
      }
      local_138 = 0;
      local_150 = 0;
      local_158 = &local_138;
      iVar9 = ObReferenceObjectByHandle(param_1,1,TmTransactionManagerObjectType,cVar8);
      lVar7 = local_138;
      local_120[2] = local_138;
      local_144 = iVar9;
      if (-1 < iVar9) {
        local_158 = (longlong *)0x0;
        KeWaitForSingleObject(local_138 + 8,0,0,0);
        local_148 = '\x01';
        if (param_2 == 0) {
          uVar4 = *(uint *)(lVar7 + 0x74);
          local_e0 = *(undefined8 *)(lVar7 + 0x70);
          uVar5 = *(uint *)(lVar7 + 0x78);
          uVar6 = *(uint *)(lVar7 + 0x7c);
          uStack_d8 = *(undefined8 *)(lVar7 + 0x78);
          local_120[3] = *(longlong *)(lVar7 + 0x248);
          *param_3 = *(uint *)(lVar7 + 0x70);
          param_3[1] = uVar4;
          param_3[2] = uVar5;
          param_3[3] = uVar6;
          *(ulonglong *)(param_3 + 4) = local_120[3];
          local_140 = 0x18;
        }
        else if (param_2 == 1) {
          local_130[0] = 0x78;
          iVar9 = ClfsGetLogFileInformation(*(undefined8 *)(lVar7 + 0x98),local_c8,local_130);
          local_144 = iVar9;
          if (-1 < iVar9) {
            *param_3 = local_60;
            param_3[1] = uStack_5c;
            param_3[2] = uStack_58;
            param_3[3] = uStack_54;
            local_140 = 0x10;
          }
        }
        else if (param_2 == 2) {
          iVar9 = RtlDuplicateUnicodeString(0,lVar7 + 0x88,local_120);
          local_144 = iVar9;
          if (-1 < iVar9) {
            uVar10 = (local_120[0] & 0xffff) + 8;
            local_140 = (undefined4)uVar10;
            if (uVar12 < uVar10) {
              RtlFreeUnicodeString(local_120);
              iVar9 = -0x3fffffdd;
              local_144 = -0x3fffffdd;
            }
            else {
              local_f8 = param_3 + 1;
              local_100._0_4_ = CONCAT22((short)uVar12 + -6,(undefined2)local_100);
              *param_3 = 0;
              RtlCopyUnicodeString(&local_100,local_120);
              uVar2 = local_100._2_2_;
              if ((ushort)local_120[0] < local_100._2_2_) {
                uVar2 = (ushort)local_120[0];
              }
              *param_3 = (uint)uVar2;
              RtlFreeUnicodeString(local_120);
            }
          }
        }
        else if (param_2 == 4) {
          *(undefined8 *)param_3 = *(undefined8 *)(lVar7 + 0x298);
          local_140 = 8;
        }
        else if (param_2 == 5) {
          KeReleaseMutex(lVar7 + 8,0);
          local_148 = '\0';
          lVar1 = lVar7 + 0x200;
          local_158 = (longlong *)0x0;
          local_120[3] = lVar1;
          KeWaitForSingleObject(lVar1,0,0,0);
          plVar3 = *(longlong **)(lVar7 + 0x238);
          if (plVar3 != (longlong *)(lVar7 + 0x238)) {
            local_f0 = plVar3[-0x27];
            uStack_e8 = plVar3[-0x26];
          }
          *param_3 = (uint)local_f0;
          param_3[1] = local_f0._4_4_;
          param_3[2] = (uint)uStack_e8;
          param_3[3] = uStack_e8._4_4_;
          local_140 = 0x10;
          KeReleaseMutex(lVar1,0);
        }
      }
      if (local_148 != '\0') {
        KeReleaseMutex(lVar7 + 8,0);
      }
      if (lVar7 != 0) {
        ObfDereferenceObject(lVar7);
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = local_140;
      }
    }
  }
  return iVar9;
}



===== NtRecoverResourceManager @ 14001cb50 =====

int NtRecoverResourceManager(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10 [3];
  
                    /* 0x1cb50  29  NtRecoverResourceManager */
  local_res10[0] = 0;
  iVar2 = ObReferenceObjectByHandle
                    (param_1,4,TmResourceManagerObjectType,
                     *(undefined1 *)((longlong)SystemReserved1[0xf] + 0x232),local_res10,0);
  lVar1 = local_res10[0];
  if (-1 < iVar2) {
    iVar2 = TmRecoverResourceManager(local_res10[0]);
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== TmpOpenTransactionManager @ 14001cbd0 =====

undefined8 TmpOpenTransactionManager(void)

{
  return 0;
}



===== TmpAdjustVirtualClock @ 14001cbdc =====

void TmpAdjustVirtualClock(longlong param_1,longlong *param_2)

{
  if ((param_1 != 0) && (param_2 != (longlong *)0x0)) {
    ExAcquireFastMutex(param_1 + 0x250);
    if (*(longlong *)(param_1 + 0x248) < *param_2) {
      *(longlong *)(param_1 + 0x248) = *param_2;
    }
    ExReleaseFastMutex(param_1 + 0x250);
  }
  return;
}



===== TmpNamespaceLookup @ 14001cc4c =====

undefined8 TmpNamespaceLookup(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  ushort uVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  KeWaitForSingleObject(param_1 + 0x68,0,0,0,0);
  if (*(char *)(param_1 + 0xa4) == '\0') {
    local_10 = 1;
    *(undefined8 **)(param_1 + 0x60) = &local_18;
    local_18 = param_2;
    pcVar2 = (char *)RtlLookupElementGenericTableAvl(param_1,param_2);
    *(undefined8 *)(param_1 + 0x60) = 0;
    if ((pcVar2 == (char *)0x0) || (uVar1 = *(ushort *)(param_1 + 0xa0), *pcVar2 != '\0')) {
      *param_3 = 0;
      uVar3 = 0xc0000034;
    }
    else {
      *param_3 = pcVar2 + (-0x20 - (ulonglong)uVar1);
      ObfReferenceObject(pcVar2 + (-0x20 - (ulonglong)uVar1));
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xc0000008;
  }
  KeReleaseMutex(param_1 + 0x68,0);
  return uVar3;
}



===== TmpWriteRestartArea @ 14001cd34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpWriteRestartArea(longlong param_1,undefined8 *param_2,char param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined8 *puVar11;
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  uint local_78;
  undefined4 *local_70;
  undefined8 *local_68;
  undefined4 local_58 [2];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_34 = 0;
  local_44 = *(undefined8 *)(param_1 + 0x70);
  uStack_3c = *(undefined8 *)(param_1 + 0x78);
  local_58[0] = 0;
  local_50 = *(undefined8 *)CLFS_LSN_NULL_exref;
  local_48 = 0x104;
  puVar6 = (undefined8 *)ExAllocatePoolWithTag(1,0x18,0x72526d54);
  puVar10 = auStack_98;
  if (puVar6 == (undefined8 *)0x0) {
    iVar5 = -0x3fffff66;
  }
  else {
    plVar1 = puVar6 + 1;
    *puVar6 = *(undefined8 *)CLFS_LSN_INVALID_exref;
    puVar6[2] = plVar1;
    *plVar1 = (longlong)plVar1;
    cVar4 = ClfsLsnInvalid(param_2);
    local_70 = local_58;
    puVar11 = param_2;
    if (cVar4 != '\0') {
      puVar11 = (undefined8 *)0x0;
    }
    local_78 = -(uint)(param_3 != '\0') & 4;
    local_68 = puVar6;
    iVar5 = ClfsWriteRestartArea(*(undefined8 *)(param_1 + 0xa0),&local_50,0x20,puVar11);
    if (iVar5 < 0) {
      ExFreePoolWithTag(puVar6,0);
      puVar10 = auStack_98;
      if ((iVar5 != -0x3fe5ffe3) || (puVar10 = auStack_98, param_3 == '\0')) goto LAB_14001cf2e;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
      }
      puVar9 = auStack_98;
    }
    else {
      if (param_3 != '\0') {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                   &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
        }
        LOCK();
        *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) & 0xfffffffd;
        UNLOCK();
      }
      puVar9 = auStack_98;
      lVar7 = param_1 + 0x390;
      plVar8 = *(longlong **)(param_1 + 0x398);
      if (*plVar8 != lVar7) {
        plVar8 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        lVar7 = (*pcVar3)();
        puVar9 = auStack_90;
      }
      *plVar1 = lVar7;
      puVar6[2] = plVar8;
      *plVar8 = (longlong)plVar1;
      *(longlong **)(lVar7 + 8) = plVar1;
      LOCK();
      *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffeff;
      UNLOCK();
      *(undefined8 *)(puVar9 + -8) = 0x14001ceb3;
      cVar4 = ClfsLsnInvalid(param_2);
      puVar10 = puVar9;
      if (cVar4 == '\0') goto LAB_14001cf2e;
      param_2 = puVar6;
    }
    uVar2 = *(undefined8 *)(param_1 + 0xa0);
    *(undefined8 *)(puVar9 + -8) = 0x14001cf25;
    iVar5 = ClfsAdvanceLogBase(uVar2,param_2,0);
    puVar10 = puVar9;
  }
LAB_14001cf2e:
  *(undefined8 *)(puVar10 + -8) = 0x14001cf3b;
  return iVar5;
}



===== TmpCheckpoint @ 14001cf5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TmpCheckpoint(longlong param_1,char param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  longlong *plVar13;
  ulonglong *puVar14;
  undefined8 uVar15;
  undefined4 *puVar16;
  undefined1 auStackY_168 [32];
  ulonglong local_110;
  uint local_108;
  undefined4 local_104;
  ulonglong *local_100;
  undefined8 local_f8;
  ulonglong local_f0;
  ulonglong local_e8 [3];
  longlong *local_d0;
  ulonglong *local_c8;
  undefined1 local_b8 [8];
  undefined1 local_b0;
  ulonglong local_70 [7];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  local_110 = *(ulonglong *)CLFS_LSN_INVALID_exref;
  local_f0 = *(ulonglong *)CLFS_LSN_INVALID_exref;
  local_100 = (ulonglong *)0x0;
  local_e8[2] = param_1;
  memset(local_b8,0,0x78);
  local_104 = 0;
  local_e8[1] = 0;
  local_f8 = *(undefined8 *)CLFS_LSN_NULL_exref;
  local_e8[0] = 0;
  bVar6 = false;
  bVar8 = false;
  bVar7 = false;
  bVar4 = false;
  if ((*(uint *)(param_1 + 0x80) & 1) != 0) {
    return 0xc019003b;
  }
  KeEnterCriticalRegion();
  KeWaitForSingleObject(param_1 + 8,0,0,0);
  bVar5 = true;
  if (*(int *)(param_1 + 0x40) != 3) {
    local_108 = 0xc0000001;
    goto LAB_14001d946;
  }
  ExAcquireResourceExclusiveLite(param_1 + 0x310);
  bVar6 = true;
  KeReleaseMutex(param_1 + 8);
  bVar5 = false;
  if ((*(uint *)(param_1 + 0x378) & 2) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
    }
    local_e8[1] = 0x20;
    local_108 = ClfsReserveAndAppendLog(*(undefined8 *)(param_1 + 0xa0),0,0,&local_f8);
    if ((int)local_108 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1,(char)local_108);
      }
      if (param_2 == '\0') goto LAB_14001d946;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
      }
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) | 2;
      UNLOCK();
    }
  }
  local_104 = 0x78;
  local_108 = ClfsGetLogFileInformation(*(undefined8 *)(param_1 + 0x98),local_b8,&local_104);
  if ((int)local_108 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1,(char)local_108);
    }
    goto LAB_14001d946;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_qii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,(ulonglong)local_108,param_1,
               (char)_local_b0,local_b8[0]);
  }
  uVar15 = 0;
  KeWaitForSingleObject(param_1 + 0x200,0,0,0);
  plVar13 = *(longlong **)(param_1 + 0x238);
  if (plVar13 != (longlong *)(param_1 + 0x238)) {
    local_110 = plVar13[-0x1e];
  }
  puVar11 = (ulonglong *)0x0;
  KeReleaseMutex(param_1 + 0x200);
  cVar9 = ClfsLsnInvalid(&local_110);
  if (cVar9 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      puVar11 = (ulonglong *)0x11;
      WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,uVar15,param_1,(char)local_110,
                 (char)(local_110 >> 0x20));
    }
    local_f0 = *(ulonglong *)CLFS_LSN_NULL_exref;
    for (puVar12 = *(undefined8 **)(param_1 + 0x390); puVar12 != (undefined8 *)(param_1 + 0x390);
        puVar12 = (undefined8 *)*puVar12) {
      puVar14 = puVar12 + -1;
      local_f0 = *puVar14;
      puVar11 = &local_110;
      cVar9 = ClfsLsnGreater(&local_f0);
      if (cVar9 != '\0') break;
      local_100 = puVar14;
    }
    if (local_100 != (ulonglong *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        puVar11 = (ulonglong *)0x12;
        WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,local_100,param_1,
                   (char)*local_100,(char)*(undefined4 *)((longlong)local_100 + 4));
      }
      if (param_2 == '\0') {
        puVar11 = local_70;
        cVar9 = ClfsLsnEqual(local_100);
        if (cVar9 != '\0') {
          if ((*(uint *)(param_1 + 0x84) >> 8 & 1) == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              puVar11 = (ulonglong *)0x13;
              goto LAB_14001d498;
            }
          }
          else {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              puVar11 = (ulonglong *)0x14;
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                       &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
            }
            bVar4 = true;
          }
        }
      }
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x84) >> 8 & 1) == 0) {
      puVar11 = local_70;
      cVar9 = ClfsLsnEqual(*(longlong *)(param_1 + 0x398) + -8);
      if (cVar9 == '\0') goto LAB_14001d334;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001d4a7;
      puVar11 = (ulonglong *)0x10;
    }
    else {
LAB_14001d334:
      bVar4 = true;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001d4a7;
      puVar11 = (ulonglong *)0xf;
    }
LAB_14001d498:
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)puVar11,
             &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
  }
LAB_14001d4a7:
  if (local_100 != (ulonglong *)0x0) {
    local_110 = *local_100;
  }
  puVar14 = local_100;
  if (param_2 == '\0') {
    if (local_100 == (ulonglong *)0x0) {
      cVar9 = '\x01';
    }
    else {
      puVar11 = local_70;
      cVar9 = ClfsLsnEqual(&local_110);
    }
    if ((cVar9 != '\0') && (!bVar4)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_qdqiid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar11,puVar14,param_1,0,
                      (char)local_100,(char)local_110,(char)local_70[0],0);
      }
      goto LAB_14001d946;
    }
    local_e8[0] = local_70[0];
  }
  else {
    local_e8[0] = *(ulonglong *)(param_1 + 0x2e8);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      puVar14 = (ulonglong *)&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids;
      WPP_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1,(char)local_e8[0]);
    }
  }
  cVar9 = ClfsLsnLess(&local_110);
  if (cVar9 != '\0') {
    if ((*(uint *)(param_1 + 0x80) & 0x40) == 0) {
      if (param_2 != '\0') {
        ClfsMgmtTailAdvanceFailure(*(undefined8 *)(param_1 + 0xa8));
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
      }
      goto LAB_14001d946;
    }
    local_f0 = *(ulonglong *)CLFS_LSN_NULL_exref;
    for (puVar12 = *(undefined8 **)(param_1 + 0x390); puVar12 != (undefined8 *)(param_1 + 0x390);
        puVar12 = (undefined8 *)*puVar12) {
      puVar11 = puVar12 + -1;
      local_f0 = *puVar11;
      cVar9 = ClfsLsnGreater(puVar11,local_e8);
      if (cVar9 != '\0') {
        local_110 = *puVar11;
        bVar8 = true;
        local_100 = puVar11;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,puVar14,param_1,(char)*puVar11,
                     (char)*(undefined4 *)((longlong)puVar12 + -4));
        }
        break;
      }
    }
    cVar9 = ClfsLsnLess(&local_110,local_e8);
    if (cVar9 != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        puVar14 = (ulonglong *)&WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
      }
      local_110 = *(ulonglong *)CLFS_LSN_INVALID_exref;
      bVar8 = true;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_qLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),local_110 >> 0x20,puVar14,param_1,
                 (char)*(undefined4 *)(param_1 + 0x288),(char)*(undefined4 *)(param_1 + 0x28c),
                 (char)local_110,(char)(local_110 >> 0x20));
  }
  uVar15 = CONCAT71((int7)((ulonglong)puVar14 >> 8),param_2);
  puVar11 = &local_110;
  local_108 = TmpWriteRestartArea(param_1,puVar11,param_2);
  if ((int)local_108 < 0) {
    if (param_2 != '\0') {
      puVar11 = (ulonglong *)(ulonglong)local_108;
      ClfsMgmtTailAdvanceFailure(*(undefined8 *)(param_1 + 0xa8));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar11,uVar15,param_1,(char)local_108,
                 param_2);
    }
  }
  else {
    bVar7 = true;
    cVar9 = ClfsLsnInvalid(&local_110);
    if (cVar9 != '\0') {
      local_110 = *(ulonglong *)(*(longlong *)(param_1 + 0x398) + -8);
    }
    *(ulonglong *)(param_1 + 0x288) = local_110;
    local_d0 = *(longlong **)(param_1 + 0x390);
    plVar13 = local_d0;
    while( true ) {
      puVar11 = (ulonglong *)(plVar13 + -1);
      local_c8 = puVar11;
      if ((local_100 != (ulonglong *)0x0) && (puVar11 == local_100)) break;
      cVar9 = ClfsLsnLess(puVar11,&local_110);
      if (cVar9 == '\0') break;
      plVar1 = (longlong *)*plVar13;
      plVar2 = (longlong *)plVar13[1];
      local_d0 = plVar1;
      if (((longlong *)plVar1[1] != plVar13) || ((longlong *)*plVar2 != plVar13)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar10 = (*pcVar3)();
        return uVar10;
      }
      *plVar2 = (longlong)plVar1;
      plVar1[1] = (longlong)plVar2;
      ExFreePoolWithTag(puVar11,0);
      plVar13 = plVar1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_2e4a34b3f042375557bfd8166beaca42_Traceguids,param_1);
    }
    local_e8[1] = 0x20;
    local_108 = ClfsReserveAndAppendLog(*(undefined8 *)(param_1 + 0xa0),0,0,&local_f8);
    if (-1 < (int)local_108) {
      LOCK();
      *(uint *)(param_1 + 0x378) = *(uint *)(param_1 + 0x378) | 2;
      UNLOCK();
    }
    local_104 = 0x78;
    puVar16 = &local_104;
    local_108 = ClfsGetLogFileInformation(*(undefined8 *)(param_1 + 0x98));
    if (-1 < (int)local_108) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_qii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,puVar16,param_1,local_b0,
                   local_b8[0]);
      }
      local_108 = 0;
    }
  }
LAB_14001d946:
  if (bVar5) {
    KeReleaseMutex(param_1 + 8);
  }
  if (bVar6) {
    ExReleaseResourceLite(param_1 + 0x310);
  }
  KeLeaveCriticalRegion();
  if ((bVar7) && (bVar8)) {
    TmpNamespaceForEach(param_1 + 0xb0,(undefined *)0x0,TmpHeuristicAbortTransactionAfterCheckpoint)
    ;
  }
  return (ulonglong)local_108;
}



===== TmpInsertTransactionLsnList @ 14001da00 =====

void TmpInsertTransactionLsnList(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  char cVar4;
  longlong lVar5;
  undefined1 *puVar6;
  longlong *plVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x200);
  local_18 = 0;
  KeWaitForSingleObject(lVar1 + 0x200,0,0,0);
  puVar6 = auStack_38;
  if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) == 0) {
LAB_14001da75:
    plVar7 = (longlong *)(lVar1 + 0x238);
    *(longlong *)(param_1 + 0xf8) = *param_2;
    param_2 = plVar7;
    if ((longlong *)*plVar7 != plVar7) {
      param_2 = *(longlong **)(lVar1 + 0x240);
      do {
        cVar4 = ClfsLsnGreater(param_2 + -0x1e,(longlong *)(param_1 + 0xf8));
        if (cVar4 == '\0') break;
        param_2 = (longlong *)param_2[1];
      } while (param_2 != plVar7);
    }
    lVar5 = *param_2;
    plVar7 = (longlong *)(param_1 + 0x1e8);
    if (*(longlong **)(lVar5 + 8) == param_2) goto LAB_14001dacf;
  }
  else {
    plVar7 = (longlong *)(param_1 + 0x1e8);
    lVar5 = *plVar7;
    if ((*(longlong **)(lVar5 + 8) == plVar7) &&
       (plVar2 = *(longlong **)(param_1 + 0x1f0), (longlong *)*plVar2 == plVar7)) {
      *plVar2 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar2;
      goto LAB_14001da75;
    }
  }
  lVar5 = 3;
  pcVar3 = (code *)swi(0x29);
  plVar7 = (longlong *)(*pcVar3)();
  puVar6 = auStack_30;
LAB_14001dacf:
  *plVar7 = lVar5;
  plVar7[1] = (longlong)param_2;
  *(longlong **)(lVar5 + 8) = plVar7;
  *param_2 = (longlong)plVar7;
  LOCK();
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x800000;
  UNLOCK();
  *(undefined8 *)(puVar6 + -8) = 0x14001daf4;
  KeReleaseMutex(lVar1 + 0x200,0);
  return;
}



===== TmpLogTransaction @ 14001db1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TmpLogTransaction(longlong param_1,int param_2,int param_3)

{
  ulonglong uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  longlong lVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  ulonglong uVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined4 *puVar19;
  ulonglong uVar20;
  longlong *plVar21;
  undefined1 auStackY_1d8 [32];
  undefined1 uVar22;
  longlong *in_stack_fffffffffffffe58;
  int local_180;
  uint local_17c;
  int local_178;
  uint local_174;
  uint local_170;
  uint local_16c;
  uint local_164;
  uint local_160;
  uint local_158;
  longlong *local_150;
  longlong *local_148;
  longlong *local_140;
  uint local_128;
  longlong *local_120;
  longlong local_108;
  longlong *local_100;
  int local_f8;
  undefined8 *local_f0;
  ulonglong local_e8;
  longlong *local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  ulonglong local_c8;
  longlong *local_c0;
  undefined8 *local_b8;
  longlong *local_b0;
  ulonglong local_a8;
  uint local_a0;
  ulonglong local_98;
  longlong local_90;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  uint local_68;
  undefined8 local_64;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_f8 = param_3;
  memset(&local_88,0,0x48);
  local_120 = (longlong *)0x0;
  local_148 = (longlong *)0x0;
  bVar6 = false;
  local_170 = 0;
  local_90 = *(longlong *)CLFS_LSN_NULL_exref;
  local_b0 = (longlong *)0x0;
  iVar10 = 0;
  lVar3 = *(longlong *)(param_1 + 0x200);
  if ((lVar3 == 0) || ((*(uint *)(lVar3 + 0x80) & 1) != 0)) {
    return 0;
  }
  if (*(int *)(lVar3 + 0x40) == 4) {
    return -0x3fe6fffc;
  }
  if (((*(longlong *)(lVar3 + 0x98) == 0) || (*(longlong *)(lVar3 + 0xa0) == 0)) ||
     (*(int *)(lVar3 + 0x40) != 3)) {
    return -0x3fe6ffae;
  }
  if ((*(uint *)(param_1 + 0xdc) == 0) && (param_2 != 4)) {
    return 0;
  }
  uVar11 = 0;
  if (param_2 != 4) {
    uVar11 = (ulonglong)*(uint *)(param_1 + 0xdc);
  }
  uVar17 = (uint)uVar11;
  uVar20 = uVar11 * 5;
  if ((uVar20 < 0x100000000) && (uVar14 = (uint)uVar20, uVar14 <= uVar14 + 4)) {
    iVar8 = 0;
    if (uVar14 + 4 < uVar14) {
LAB_14001dc79:
      uVar16 = 0xffffffff;
      iVar8 = -0x3fffff6b;
    }
    else {
      uVar16 = (ulonglong)(uVar14 + 4) * 0x10;
      local_d0 = uVar16;
      if (0xffffffff < uVar16) goto LAB_14001dc79;
    }
    local_a8 = uVar20;
    if (iVar8 < 0) goto LAB_14001e993;
    uVar20 = uVar11 * 0x70;
    local_98 = uVar20;
    if (0xffffffff < uVar20) goto LAB_14001e993;
    uVar1 = uVar11 * 8;
    if (0xffffffff < uVar1) goto LAB_14001e993;
    iVar8 = 0;
    local_d8 = uVar11 * 2;
    if (local_d8 < 0x100000000) {
      uVar14 = (uint)local_d8 + 1;
      if (uVar14 < (uint)local_d8) goto LAB_14001dcf5;
      plVar12 = (longlong *)((ulonglong)uVar14 * 0x10);
      local_e0 = plVar12;
      if ((longlong *)0xffffffff < plVar12) goto LAB_14001dcf5;
    }
    else {
LAB_14001dcf5:
      plVar12 = (longlong *)0xffffffff;
      iVar8 = -0x3fffff6b;
    }
    if (iVar8 < 0) goto LAB_14001e993;
    if (3 < uVar17) {
      bVar6 = false;
      uVar14 = (uint)uVar16 + (int)uVar20;
      if ((uint)uVar16 <= uVar14) {
        uVar15 = (int)uVar1 + uVar14;
        if (uVar14 <= uVar15) {
          uVar14 = uVar15 + (int)plVar12;
          if (uVar15 <= uVar14) {
            local_a0 = uVar14;
            local_148 = (longlong *)ExAllocatePoolWithTag(1,uVar14,0x6f4c6d54);
            goto LAB_14001dd6e;
          }
        }
      }
      goto LAB_14001e993;
    }
    bVar6 = true;
    local_148 = (longlong *)ExAllocateFromPagedLookasideList(&TmpLogWriteLookasideList);
LAB_14001dd6e:
    if (local_148 != (longlong *)0x0) {
      uVar16 = uVar16 & 0xffffffff;
      local_c8 = uVar16 + (longlong)local_148;
      local_140 = (longlong *)(uVar16 + (uVar20 & 0xffffffff) + (longlong)local_148);
      local_120 = (longlong *)
                  ((uVar1 & 0xffffffff) + uVar16 + (uVar20 & 0xffffffff) + (longlong)local_148);
      local_80 = *(undefined4 *)(param_1 + 0xb0);
      uStack_7c = *(undefined4 *)(param_1 + 0xb4);
      uStack_78 = *(undefined4 *)(param_1 + 0xb8);
      uStack_74 = *(undefined4 *)(param_1 + 0xbc);
      local_64 = CONCAT44(local_64._4_4_,0x48);
      local_88 = 0x104;
      local_58 = *(undefined4 *)(param_1 + 0xc4);
      local_50 = CONCAT44(local_50._4_4_,(uint)*(ushort *)(param_1 + 0x130));
      local_54 = 0x10000001;
      local_48 = 0;
      *local_148 = (longlong)&local_88;
      *(undefined4 *)(local_148 + 1) = 0x48;
      uVar18 = 1;
      local_158 = 1;
      uVar22 = (undefined1)param_1;
      uVar14 = local_170;
      local_e8 = (ulonglong)local_140;
      local_d0 = (ulonglong)local_140;
      local_a8 = local_c8;
      local_84 = param_2;
      local_68 = uVar17;
      if (param_2 == 4) {
        if ((*(uint *)(param_1 + 0xc4) >> 0x18 & 1) != 0) {
          local_108 = -*(longlong *)(param_1 + 0x208);
          in_stack_fffffffffffffe58 = &local_108;
          uVar18 = 0;
          iVar8 = ClfsReserveAndAppendLog(*(undefined8 *)(lVar3 + 0xa0),0,0,0);
          if (iVar8 < 0) goto LAB_14001e99a;
          LOCK();
          *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfeffffff;
          UNLOCK();
          *(undefined8 *)(param_1 + 0x208) = 0;
        }
        local_64 = 0;
        local_5c = 0;
        local_50 = 0;
        local_128 = 1;
        local_160 = *(uint *)(param_1 + 0xc4) >> 0x19 & 1;
        local_178 = 0;
        if (local_160 != 0) {
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,uVar18,lVar3,uVar22);
            }
          }
        }
      }
      else {
        uVar15 = uVar17 * 0x78 + 0x48;
        iVar8 = ObGetObjectSecurity(param_1,local_120,(longlong)local_120 + 0xc);
        if (iVar8 < 0) goto LAB_14001e99a;
        if (*local_120 == 0) {
          *(undefined4 *)(local_120 + 1) = 0;
        }
        else {
          uVar9 = RtlLengthSecurityDescriptor();
          *(undefined4 *)(local_120 + 1) = uVar9;
        }
        local_170 = 1;
        local_64 = CONCAT44((int)local_120[1],(undefined4)local_64);
        lVar7 = local_120[1];
        uVar14 = (int)lVar7 + 7U & 0xfffffff8;
        local_174 = uVar14 + uVar15;
        local_5c = uVar15;
        if (local_174 < uVar15) goto LAB_14001e993;
        local_148[(ulonglong)(uVar17 + 2) * 2] = *local_120;
        *(int *)(local_148 + (ulonglong)(uVar17 + 2) * 2 + 1) = (int)lVar7;
        local_180 = uVar14 + 0x48;
        local_17c = uVar17 + 3;
        local_150 = (longlong *)0x1;
        local_16c = 1;
        if ((int)local_50 == 0) {
          local_50 = local_50 & 0xffffffff;
        }
        else {
          local_50 = CONCAT44(local_174,(int)local_50);
          uVar2 = *(ushort *)(param_1 + 0x130);
          uVar14 = uVar2 + 7 & 0xfffffff8;
          uVar15 = local_174 + uVar14;
          if (uVar15 < local_174) goto LAB_14001e993;
          local_148[(ulonglong)local_17c * 2] = *(longlong *)(param_1 + 0x138);
          *(uint *)(local_148 + (ulonglong)local_17c * 2 + 1) = (uint)uVar2;
          local_180 = local_180 + uVar14;
          local_17c = uVar17 + 4;
          local_174 = uVar15;
        }
        uVar11 = 0;
        local_164 = 0;
        puVar13 = *(undefined8 **)(param_1 + 200);
        while( true ) {
          local_128 = local_17c;
          uVar14 = local_170;
          local_b8 = puVar13;
          if (puVar13 == (undefined8 *)(param_1 + 200)) break;
          local_f0 = puVar13 + -0xf;
          if (((*(uint *)((longlong)puVar13 + 0x34) & 4) == 0) &&
             ((*(uint *)((longlong)puVar13 + 0x34) & 2) != 0)) {
            if ((*(uint *)((longlong)puVar13 + 0x34) >> 8 & 1) != 0) {
              local_c0 = local_120 + (ulonglong)local_16c * 2;
              iVar8 = ObGetObjectSecurity(local_f0,local_c0,(longlong)local_c0 + 0xc);
              if (-1 < iVar8) {
                local_140 = local_120 + (longlong)local_150 * 2 + 1;
                if (*local_c0 == 0) {
                  *(undefined4 *)local_140 = 0;
                  local_140 = local_c0 + 1;
                }
                else {
                  uVar9 = RtlLengthSecurityDescriptor(local_120[(longlong)local_150 * 2]);
                  *(undefined4 *)local_140 = uVar9;
                }
                plVar12 = local_140;
                uVar17 = local_16c + 1;
                local_e0 = local_120 + (ulonglong)uVar17 * 2;
                iVar8 = ObGetObjectSecurity(puVar13[4],local_e0,(longlong)local_e0 + 0xc);
                uVar14 = local_170 + 1;
                if (-1 < iVar8) {
                  local_150 = local_120 + (ulonglong)uVar17 * 2 + 1;
                  if (*local_e0 == 0) {
                    *(undefined4 *)local_150 = 0;
                    local_150 = local_e0 + 1;
                  }
                  else {
                    uVar9 = RtlLengthSecurityDescriptor(local_120[(ulonglong)uVar17 * 2]);
                    *(undefined4 *)local_150 = uVar9;
                  }
                  local_16c = local_16c + 2;
                  local_170 = local_170 + 2;
                  KeWaitForSingleObject(puVar13 + -7,0,0,0);
                  local_d8 = (ulonglong)local_164;
                  puVar19 = (undefined4 *)(local_d8 * 0x70 + local_a8);
                  uVar9 = *(undefined4 *)((longlong)puVar13 + -0x44);
                  uVar4 = *(undefined4 *)(puVar13 + -8);
                  uVar5 = *(undefined4 *)((longlong)puVar13 + -0x3c);
                  *puVar19 = *(undefined4 *)(puVar13 + -9);
                  puVar19[1] = uVar9;
                  puVar19[2] = uVar4;
                  puVar19[3] = uVar5;
                  lVar7 = puVar13[4];
                  uVar9 = *(undefined4 *)(lVar7 + 0x8c);
                  uVar4 = *(undefined4 *)(lVar7 + 0x90);
                  uVar5 = *(undefined4 *)(lVar7 + 0x94);
                  puVar19[4] = *(undefined4 *)(lVar7 + 0x88);
                  puVar19[5] = uVar9;
                  puVar19[6] = uVar4;
                  puVar19[7] = uVar5;
                  if ((*(uint *)((longlong)puVar13 + 0x34) & 0x20) != 0) {
                    uVar18 = local_f0[0x22];
                    *(undefined8 *)(puVar19 + 8) = local_f0[0x21];
                    *(undefined8 *)(puVar19 + 10) = uVar18;
                    uVar9 = *(undefined4 *)((longlong)local_f0 + 0x11c);
                    uVar4 = *(undefined4 *)(local_f0 + 0x24);
                    uVar5 = *(undefined4 *)((longlong)local_f0 + 0x124);
                    puVar19[0x10] = *(undefined4 *)(local_f0 + 0x23);
                    puVar19[0x11] = uVar9;
                    puVar19[0x12] = uVar4;
                    puVar19[0x13] = uVar5;
                    uVar9 = *(undefined4 *)((longlong)local_f0 + 300);
                    uVar4 = *(undefined4 *)(local_f0 + 0x26);
                    uVar5 = *(undefined4 *)((longlong)local_f0 + 0x134);
                    puVar19[0xc] = *(undefined4 *)(local_f0 + 0x25);
                    puVar19[0xd] = uVar9;
                    puVar19[0xe] = uVar4;
                    puVar19[0xf] = uVar5;
                  }
                  puVar19[0x14] = *(undefined4 *)((longlong)puVar13 + 0x34);
                  puVar19[0x16] = *(undefined4 *)(local_f0 + 0x1a);
                  puVar19[0x18] = (int)*local_140;
                  puVar19[0x1a] = (int)*local_150;
                  local_140 = (longlong *)local_e8;
                  *(uint *)(local_e8 + local_d8 * 8) = (uint)*(ushort *)(puVar13[4] + 0x170);
                  local_148[(ulonglong)local_158 * 2] = (longlong)puVar19;
                  *(undefined4 *)(local_148 + (ulonglong)local_158 * 2 + 1) = 0x70;
                  local_180 = local_180 + 0x70;
                  local_158 = local_158 + 1;
                  if (puVar19[0x16] == 0) {
                    *(undefined4 *)(uVar11 * 0x70 + 0x5c + local_c8) = 0;
LAB_14001e47c:
                    puVar19[0x19] = local_174;
                    lVar7 = *plVar12;
                    uVar14 = (int)lVar7 + 7U & 0xfffffff8;
                    uVar17 = uVar14 + local_174;
                    if (local_174 <= uVar17) {
                      local_148[(ulonglong)local_17c * 2] = *local_c0;
                      *(int *)(local_148 + (ulonglong)local_17c * 2 + 1) = (int)lVar7;
                      puVar19[0x1b] = uVar17;
                      lVar7 = *local_150;
                      uVar15 = (int)lVar7 + 7U & 0xfffffff8;
                      local_174 = uVar15 + uVar17;
                      if (uVar17 <= local_174) {
                        local_148[(ulonglong)(local_17c + 1) * 2] = *local_e0;
                        *(int *)(local_148 + (ulonglong)(local_17c + 1) * 2 + 1) = (int)lVar7;
                        local_180 = local_180 + uVar14 + uVar15;
                        uVar17 = local_17c + 2;
                        if (*(int *)(local_e8 + local_d8 * 8) == 0) {
                          *(undefined4 *)(local_d0 + 4 + uVar11 * 8) = 0;
                          local_17c = uVar17;
                        }
                        else {
                          *(uint *)(local_d0 + 4 + uVar11 * 8) = local_174;
                          uVar2 = *(ushort *)(puVar13[4] + 0x170);
                          uVar14 = uVar2 + 7 & 0xfffffff8;
                          uVar15 = uVar14 + local_174;
                          if (uVar15 < local_174) goto LAB_14001e40f;
                          local_148[(ulonglong)uVar17 * 2] = *(longlong *)(puVar13[4] + 0x178);
                          *(uint *)(local_148 + (ulonglong)uVar17 * 2 + 1) = (uint)uVar2;
                          local_180 = local_180 + uVar14;
                          local_17c = local_17c + 3;
                          local_174 = uVar15;
                        }
                        KeReleaseMutex(puVar13 + -7,0);
                        local_164 = local_164 + 1;
                        goto LAB_14001e606;
                      }
                    }
                  }
                  else {
                    *(uint *)(uVar11 * 0x70 + 0x5c + local_c8) = local_174;
                    iVar10 = *(int *)(local_f0 + 0x1a);
                    uVar14 = iVar10 + 7U & 0xfffffff8;
                    uVar17 = uVar14 + local_174;
                    if (local_174 <= uVar17) {
                      local_148[(ulonglong)local_17c * 2] = local_f0[0x19];
                      *(int *)(local_148 + (ulonglong)local_17c * 2 + 1) = iVar10;
                      local_180 = local_180 + uVar14;
                      local_17c = local_17c + 1;
                      local_174 = uVar17;
                      goto LAB_14001e47c;
                    }
                  }
LAB_14001e40f:
                  iVar8 = -0x3fffff6b;
                  KeReleaseMutex(puVar13 + -7,0);
                  uVar14 = local_170;
                }
              }
              goto LAB_14001e99a;
            }
            iVar8 = -0x3fe6ff9e;
            goto LAB_14001e996;
          }
          local_140 = (longlong *)local_e8;
LAB_14001e606:
          uVar11 = (ulonglong)local_164;
          puVar13 = (undefined8 *)*local_b8;
          local_150 = (longlong *)(ulonglong)local_16c;
        }
        uVar20 = (ulonglong)local_158;
        local_148[uVar20 * 2] = (longlong)local_140;
        iVar10 = (int)(uVar11 << 3);
        *(int *)(local_148 + uVar20 * 2 + 1) = iVar10;
        uVar17 = local_180 + iVar10;
        plVar12 = (longlong *)(ulonglong)uVar17;
        local_48 = (int)local_98 + 0x48;
        if (param_2 == 3) {
          if ((*(uint *)(param_1 + 0xc4) >> 0x18 & 1) == 0) {
            local_160 = 0;
            local_178 = 0;
            if ((*(uint *)(param_1 + 0xc4) >> 0x19 & 1) == 0) {
              local_178 = 1;
              local_108 = 0x48;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                in_stack_fffffffffffffe58 = (longlong *)0x48;
                WPP_SF_qq_guid_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar20 * 2,0x48,lVar3,
                                 uVar22,param_1 + 0xb0,0x48);
              }
            }
          }
          else {
            plVar21 = (longlong *)(ulonglong)uVar17;
            plVar12 = *(longlong **)(param_1 + 0x208);
            if (plVar12 != plVar21) {
              local_108 = -(longlong)plVar12;
              local_100 = plVar21;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                WPP_SF_qq_guid_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,plVar12,lVar3,
                                  uVar22,param_1 + 0xb0,(char)plVar12,(char)uVar17);
              }
              in_stack_fffffffffffffe58 = &local_108;
              plVar12 = (longlong *)0x0;
              iVar8 = ClfsReserveAndAppendLog(*(undefined8 *)(lVar3 + 0xa0),0,0,0);
              if (iVar8 < 0) goto LAB_14001e99a;
              *(longlong **)(param_1 + 0x208) = plVar21;
            }
            local_160 = 1;
            local_178 = 0;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,plVar12,lVar3,uVar22);
            }
          }
          iVar10 = local_178;
        }
        else {
          local_160 = 0;
          local_178 = 2;
          local_108 = 0x48;
          local_100 = plVar12;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            in_stack_fffffffffffffe58 = plVar12;
            WPP_SF_qq_guid_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,0x48,lVar3,uVar22,
                              param_1 + 0xb0,(char)uVar17,0x48);
          }
          iVar10 = 1;
          local_b0 = plVar12;
        }
      }
      plVar12 = &local_108;
      if (local_178 == 0) {
        plVar12 = (longlong *)0x0;
      }
      iVar8 = TmpWriteLog(param_1,local_148,local_128,&local_70,local_f8,local_160,
                          in_stack_fffffffffffffe58,local_178,(ulonglong)plVar12,&local_90);
      uVar14 = local_170;
      if (-1 < iVar8) {
        if (local_b0 != (longlong *)0x0) {
          *(longlong **)(param_1 + 0x208) = local_b0;
          LOCK();
          *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x1000000;
          UNLOCK();
        }
        if (iVar10 != 0) {
          LOCK();
          *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) | 0x2000000;
          UNLOCK();
        }
        if (local_160 != 0) {
          if (param_2 == 3) {
            *(undefined8 *)(param_1 + 0x208) = 0;
            LOCK();
            *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfeffffff;
            UNLOCK();
          }
          else if (param_2 == 4) {
            LOCK();
            *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfdffffff;
            UNLOCK();
          }
        }
      }
      goto LAB_14001e99a;
    }
    iVar8 = -0x3fffff66;
  }
  else {
LAB_14001e993:
    iVar8 = -0x3fffff6b;
  }
LAB_14001e996:
  uVar14 = local_170;
LAB_14001e99a:
  local_170 = uVar14;
  if (local_170 != 0) {
    uVar11 = (ulonglong)local_170;
    do {
      if (*local_120 != 0) {
        ObReleaseObjectSecurity(*local_120,*(undefined1 *)((longlong)local_120 + 0xc));
      }
      local_120 = local_120 + 2;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  if (local_148 != (longlong *)0x0) {
    if (bVar6) {
      ExFreeToPagedLookasideList(&TmpLogWriteLookasideList,local_148);
    }
    else {
      ExFreePoolWithTag(local_148,0);
    }
  }
  if (iVar8 == -0x3fffffdd) {
    iVar8 = -0x3fe6ffa8;
  }
  return iVar8;
}



===== TmpWriteLog @ 14001ea64 =====

int TmpWriteLog(longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 *param_4,
               int param_5,int param_6,undefined8 param_7,undefined4 param_8,ulonglong param_9,
               longlong *param_10)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_res18;
  undefined8 *local_res20;
  ulonglong in_stack_ffffffffffffff78;
  ulonglong in_stack_ffffffffffffff80;
  undefined4 uVar7;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 *puVar8;
  undefined4 uVar9;
  ulonglong in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar10;
  uint local_50;
  longlong *local_48;
  
  local_res8 = 0;
  bVar3 = false;
  local_50 = 0;
  local_48 = (longlong *)0x0;
  lVar2 = *(longlong *)(param_1 + 0x200);
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  KeEnterCriticalRegion();
  lVar1 = lVar2 + 0x310;
  do {
    uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
    uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
    local_50 = local_50 + 1;
    if ((((*(uint *)(lVar2 + 0x378) & 4) != 0) || (bVar3)) && (param_6 == 0)) {
      if ((*(uint *)(lVar2 + 0x84) & 4) == 0) {
        local_48 = (longlong *)ExAllocatePoolWithTag(0x200,0x10,0x41576d54);
        if (local_48 == (longlong *)0x0) {
          iVar6 = -0x3fffff66;
        }
        else {
          *local_48 = lVar2 + 0x2b0;
          local_48[1] = param_1;
          in_stack_ffffffffffffff90 = 0;
          uVar9 = 0;
          in_stack_ffffffffffffff80 = in_stack_ffffffffffffff80 & 0xffffffffffffff00;
          iVar6 = KeWaitForMultipleObjects
                            (2,local_48,1,6,in_stack_ffffffffffffff78 & 0xffffffffffffff00,
                             in_stack_ffffffffffffff80,0,0);
          if (iVar6 == 1) {
            iVar6 = -0x3ffffee0;
          }
          else {
            if ((*(uint *)(lVar2 + 0x84) & 4) != 0) goto LAB_14001eaf2;
            iVar6 = *(int *)(lVar2 + 0x37c);
            if (-1 < iVar6) goto LAB_14001eba3;
          }
        }
      }
      else {
LAB_14001eaf2:
        iVar6 = -0x3fe5ffd4;
      }
      bVar4 = false;
LAB_14001ee8f:
      if (bVar4) {
        ExReleaseResourceLite(lVar1);
      }
      KeLeaveCriticalRegion();
      if (local_48 != (longlong *)0x0) {
        ExFreePoolWithTag(local_48,0);
      }
      return iVar6;
    }
LAB_14001eba3:
    uVar7 = (undefined4)(in_stack_ffffffffffffff80 >> 0x20);
    ExAcquireFastMutex(lVar2 + 0x250);
    *param_4 = *(undefined8 *)(lVar2 + 0x248);
    ExReleaseFastMutex(lVar2 + 0x250);
    if ((*(uint *)(lVar2 + 0x378) & 2) == 0) {
      ExAcquireResourceExclusiveLite(lVar2 + 0x310,1);
      bVar4 = true;
      if ((*(uint *)(lVar2 + 0x378) & 2) == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_6e9068bbfb213430aec3b8c36d4eb7a8_Traceguids,lVar2);
        }
        local_res8 = 0x20;
        uVar10 = 0;
        puVar8 = &local_res8;
        iVar6 = ClfsReserveAndAppendLog
                          (*(undefined8 *)(lVar2 + 0xa0),0,0,0,0,CONCAT44(uVar7,1),puVar8,
                           in_stack_ffffffffffffff90 & 0xffffffff00000000,0);
        uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);
        if (iVar6 < 0) goto LAB_14001ee8f;
        LOCK();
        *(uint *)(lVar2 + 0x378) = *(uint *)(lVar2 + 0x378) | 2;
        UNLOCK();
      }
      ExReleaseResourceLite(lVar2 + 0x310);
      param_4 = local_res20;
    }
    ExAcquireResourceSharedLite();
    bVar4 = true;
    in_stack_ffffffffffffff98 =
         CONCAT44(uVar10,-(uint)(param_5 != 0) & 2 | -(uint)(param_6 != 0) & 4);
    in_stack_ffffffffffffff88 = CONCAT44(uVar9,param_8);
    in_stack_ffffffffffffff80 = 0;
    in_stack_ffffffffffffff78 = 0;
    in_stack_ffffffffffffff90 = param_9;
    iVar6 = ClfsReserveAndAppendLogAligned
                      (*(undefined8 *)(lVar2 + 0xa0),local_res10,local_res18,8,0,0,
                       in_stack_ffffffffffffff88,param_9,in_stack_ffffffffffffff98,param_10);
    if (-1 < iVar6) {
      cVar5 = ClfsLsnGreater(param_10,lVar2 + 0x288);
      if (cVar5 == '\0') {
        iVar6 = -0x3fe6ffa5;
      }
      else {
        TmpInsertTransactionLsnList(param_1,param_10);
        LOCK();
        *(uint *)(lVar2 + 0x84) = *(uint *)(lVar2 + 0x84) | 0x100;
        UNLOCK();
      }
      goto LAB_14001ee8f;
    }
    if ((iVar6 == -0x3fffff66) && (local_50 < 10)) {
      ExReleaseResourceLite(lVar1);
    }
    else {
      if (iVar6 != -0x3fe5ffe3) goto LAB_14001ee8f;
      bVar3 = true;
      ExReleaseResourceLite(lVar1);
      ExAcquireResourceExclusiveLite(lVar1,1);
      if ((*(uint *)(lVar2 + 0x378) & 4) == 0) {
        LOCK();
        *(uint *)(lVar2 + 0x378) = *(uint *)(lVar2 + 0x378) | 4;
        UNLOCK();
        KeResetEvent(lVar2 + 0x2b0);
        ObfReferenceObject(lVar2);
        ExReleaseResourceLite(lVar1);
        iVar6 = ClfsMgmtHandleLogFileFull(*(undefined8 *)(lVar2 + 0xa8));
        if (iVar6 != 0x103) {
          TmpLogGrowthCompletedNotification(*(undefined8 *)(lVar2 + 0x98),iVar6,'\0',lVar2);
        }
      }
      else {
        ExReleaseResourceLite(lVar1);
      }
    }
  } while( true );
}



===== TmCommitEnlistment @ 14001eee0 =====

int TmCommitEnlistment(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined8 uVar6;
  int local_res8;
  
                    /* 0x1eee0  45  TmCommitEnlistment */
  lVar3 = *(longlong *)(param_1 + 0xa0);
  local_res8 = -0x3fe6ffed;
  lVar4 = *(longlong *)(param_1 + 0x98);
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmCommitTransactionExt for tx %lx\n",lVar3);
  plVar1 = (longlong *)(lVar4 + 0x168);
  if ((param_2 != (longlong *)0x0) && (*plVar1 == 0)) {
    return -0x3fe6ffae;
  }
  TmpAdjustVirtualClock(*plVar1,param_2);
  TmpAcquireTransactionMutex(lVar3);
  ObfReferenceObject(lVar3);
  puVar2 = (uint *)(param_1 + 0xac);
  if ((*puVar2 & 1) == 0) {
    iVar5 = -0x3fe6ffcd;
  }
  else if ((*(uint *)(param_1 + 0xb0) & 0x40) == 0) {
    iVar5 = -0x3fe6ffa9;
  }
  else {
    iVar5 = -0x3fe6ffed;
    if ((*(uint *)(lVar3 + 0xc4) & 2) == 0) {
      iVar5 = *(int *)(lVar3 + 0xc0);
      if (iVar5 == 1) {
        LOCK();
        *(uint *)(lVar3 + 0xc4) = *(uint *)(lVar3 + 0xc4) | 2;
        UNLOCK();
        KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
        if ((*puVar2 & 2) != 0) {
          LOCK();
          *puVar2 = *puVar2 & 0xfffffffd;
          UNLOCK();
          *(int *)(lVar3 + 0xdc) = *(int *)(lVar3 + 0xdc) + -1;
        }
        KeReleaseMutex(param_1 + 0x40);
        local_res8 = TmCommitTransaction(lVar3,'\0');
      }
      else if ((iVar5 == 3) || (iVar5 == 4)) {
        uVar6 = 0;
        KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
        if ((*(uint *)(param_1 + 0xac) & 2) != 0) {
          LOCK();
          *puVar2 = *puVar2 & 0xfffffffd;
          UNLOCK();
          *(int *)(lVar3 + 0xdc) = *(int *)(lVar3 + 0xdc) + -1;
        }
        KeReleaseMutex(param_1 + 0x40);
        local_res8 = TmpTxActionDoCommit(lVar3,0,uVar6);
      }
      else if (iVar5 == 7) {
        iVar5 = -0x3fe6fffd;
        goto LAB_14001f0ca;
      }
      if ((*(uint *)(lVar3 + 0xc4) >> 0x1b & 1) == 0) {
        if ((*(int *)(lVar3 + 0xc0) == 6) || (iVar5 = local_res8, *(int *)(lVar3 + 0x1f8) == 3)) {
          iVar5 = -0x3fe6ffeb;
        }
      }
      else {
        iVar5 = 0x40190001;
      }
    }
  }
LAB_14001f0ca:
  KeReleaseMutex(*(longlong *)(lVar3 + 0x58) + 0x20,0);
  ObfDereferenceObject(lVar3);
  return iVar5;
}



===== TmPrePrepareEnlistment @ 14001f100 =====

int TmPrePrepareEnlistment(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  char *pcVar5;
  
                    /* 0x1f100  60  TmPrePrepareEnlistment */
  lVar2 = *(longlong *)(param_1 + 0xa0);
  lVar3 = *(longlong *)(param_1 + 0x98);
  pcVar5 = "KTM:  TmPrepareTransaction for en %lx\n";
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmPrepareTransaction for en %lx\n",param_1);
  plVar1 = (longlong *)(lVar3 + 0x168);
  if ((param_2 == (longlong *)0x0) || (*plVar1 != 0)) {
    TmpAdjustVirtualClock(*plVar1,param_2);
    TmpAcquireTransactionMutex(lVar2);
    if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
      iVar4 = -0x3fe6ffcd;
    }
    else if ((*(uint *)(param_1 + 0xb0) & 0x10) == 0) {
      iVar4 = -0x3fe6ffa9;
    }
    else if (*(int *)(lVar2 + 0xc0) == 1) {
      iVar4 = TmpTxActionDoPrePrepare(lVar2,param_2,pcVar5);
    }
    else {
      iVar4 = -0x3fe6ffed;
    }
    KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  }
  else {
    iVar4 = -0x3fe6ffae;
  }
  return iVar4;
}



===== TmRollbackEnlistment @ 14001f1f0 =====

int TmRollbackEnlistment(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  
                    /* 0x1f1f0  73  TmRollbackEnlistment */
  lVar1 = *(longlong *)(param_1 + 0xa0);
  lVar2 = *(longlong *)(param_1 + 0x98);
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmRollbackEnlistmentExt for tx %lx\n",lVar1);
  if ((param_2 == (longlong *)0x0) || (*(longlong *)(lVar2 + 0x168) != 0)) {
    TmpAdjustVirtualClock(*(longlong *)(lVar2 + 0x168),param_2);
    TmpAcquireTransactionMutex(lVar1);
    lVar6 = 0;
    KeWaitForSingleObject(param_1 + 0x40,0,0,0,0);
    bVar3 = false;
    if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
      iVar4 = *(int *)(param_1 + 0xa8);
      if ((iVar4 - 0x100U < 0x12) && ((0x20503U >> (iVar4 - 0x100U & 0x1f) & 1) != 0)) {
        bVar3 = true;
      }
      else if ((iVar4 == 0x102) || (iVar4 == 0x105)) {
        LOCK();
        *(uint *)(lVar1 + 0xc4) = *(uint *)(lVar1 + 0xc4) | 0x8000000;
        UNLOCK();
      }
    }
    else if (((*(uint *)(lVar1 + 0xc0) < 0xc) &&
             ((0x91eU >> (*(uint *)(lVar1 + 0xc0) & 0x1f) & 1) != 0)) &&
            (bVar3 = true, -1 < (char)*(undefined4 *)(lVar1 + 0xc4))) {
      LOCK();
      *(uint *)(lVar1 + 0xc4) = *(uint *)(lVar1 + 0xc4) | 0x40;
      UNLOCK();
    }
    if (bVar3) {
      if (((*(code **)(lVar2 + 0x128) != TmpInternalCrmNotification) &&
          ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        lVar6 = *(longlong *)(param_1 + 0xa0) + 0xb0;
        WPP_SF_q_guid__guid_
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,lVar6,lVar1,lVar6,lVar2 + 0x88);
      }
      uVar5 = 0;
      KeReleaseMutex(param_1 + 0x40);
      bVar3 = false;
      iVar4 = TmpTxActionDoRollback(lVar1,uVar5,lVar6);
    }
    else {
      iVar4 = -0x3fe6ffed;
      bVar3 = true;
    }
    if (bVar3) {
      KeReleaseMutex(param_1 + 0x40,0);
    }
    KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  }
  else {
    iVar4 = -0x3fe6ffae;
  }
  return iVar4;
}



===== TmpDeleteEnlistment @ 14001f3f0 =====

void TmpDeleteEnlistment(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0xa0);
  uVar2 = *(undefined8 *)(param_1 + 0x98);
  LOCK();
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 0x80000000;
  UNLOCK();
  if (*(int *)(param_1 + 0xa8) != 0) {
    if (((*(uint *)(param_1 + 0xac) & 8) == 0) && (*(longlong *)(param_1 + 0xe8) != 0)) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xe8),0);
      *(undefined8 *)(param_1 + 0xe8) = 0;
    }
    if (*(longlong *)(param_1 + 200) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 200),0);
      *(undefined8 *)(param_1 + 200) = 0;
    }
    ObfDereferenceObject(uVar1);
    ObfDereferenceObject(uVar2);
  }
  return;
}



===== TmpInitializeEnlistment @ 14001f4a8 =====

undefined4
TmpInitializeEnlistment
          (undefined4 *param_1,longlong param_2,undefined8 *param_3,undefined4 *param_4,uint param_5
          ,uint param_6,undefined8 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined8 *local_res18;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  longlong local_48;
  longlong local_40;
  undefined8 *local_38;
  undefined8 *local_30;
  
  local_38 = (undefined8 *)0x0;
  bVar6 = false;
  local_48 = 0;
  local_40 = 0;
  if ((param_5 & 1) == 0) {
    if ((((((param_6 & 8) != 0) && ((param_6 & 0x60000f0) == 0)) &&
         (((param_6 & 2) == 0 || ((param_6 & 4) != 0)))) &&
        (((param_6 >> 9 & 1) == 0 || ((param_6 & 2) != 0)))) &&
       (((param_6 & 4) != 0 || ((param_6 & 1) != 0)))) goto LAB_14001f555;
    bVar5 = false;
LAB_14001f55c:
    if (bVar5) {
      *(undefined8 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 10) = 0;
      puVar10 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x38,0x4e466d54);
      puVar17 = auStackY_98;
      local_30 = puVar10;
      if (puVar10 == (undefined8 *)0x0) goto LAB_14001fc0d;
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      puVar10[5] = 0;
      puVar10[6] = 0;
      param_1[0x2a] = 0x112;
      *param_1 = 0xb00b0003;
      *(longlong *)(param_1 + 0x26) = param_2;
      ObfReferenceObject(param_2);
      *(undefined8 **)(param_1 + 0x28) = param_3;
      ObfReferenceObject(param_3);
      *(undefined8 *)(param_1 + 0x2e) = param_7;
      param_1[0x30] = 1;
      param_1[0x2c] = param_6;
      param_1[0x2b] = 0;
      *(undefined8 **)(param_1 + 0x3a) = puVar10;
      if (param_4 == (undefined4 *)0x0) {
        ExUuidCreate(param_1 + 0xc);
      }
      else {
        uVar2 = param_4[1];
        uVar3 = param_4[2];
        uVar4 = param_4[3];
        param_1[0xc] = *param_4;
        param_1[0xd] = uVar2;
        param_1[0xe] = uVar3;
        param_1[0xf] = uVar4;
      }
      *(undefined8 *)(param_1 + 0x32) = 0;
      param_1[0x34] = 0;
      KeInitializeMutex(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x3c) = 0;
      *(undefined8 *)(param_1 + 0x3e) = 0;
      *(undefined8 *)(param_1 + 0x40) = 0;
      param_1[0x4e] = 0;
      memset(param_1 + 0x4f,0,0xa0);
      KeWaitForSingleObject(param_2 + 0x28,0,0,0);
      lVar14 = *(longlong *)(param_2 + 0x168);
      if ((lVar14 != 0) &&
         ((ObfReferenceObject(), *(int *)(param_2 + 0x1c) != 1 || (*(int *)(lVar14 + 0x40) == 2))))
      {
        KeReleaseMutex(param_2 + 0x28);
        if (param_3[0x40] != lVar14) {
          local_40 = lVar14;
        }
        do {
          lVar11 = local_40;
          puVar17 = auStackY_98;
          if (bVar6) {
            KeReleaseMutex(param_3[0xb] + 0x20);
          }
          if (local_48 != 0) {
            TmpReleaseTxTableTransactionManager(local_48);
            ObfDereferenceObject(local_48);
            local_48 = 0;
          }
          if (lVar11 != 0) {
            ObfReferenceObject(lVar11);
            TmpAcquireTxTableTransactionManager(lVar11);
            local_40 = 0;
            local_48 = lVar11;
            if (*(int *)(lVar11 + 0x40) == 5) goto LAB_14001fc05;
          }
          TmpAcquireTransactionMutex((longlong)param_3);
          bVar6 = true;
          lVar11 = TmIsTransactionActive((longlong)param_3);
          if (((char)lVar11 == '\0') && (*(int *)(param_3 + 0x18) != 10)) goto LAB_14001f7ed;
          if ((*(int *)(param_3 + 0x18) != 1) && ((param_6 & 1) != 0)) goto LAB_14001fc0d;
          local_res18 = param_3;
          if (param_3[0x40] == 0) {
            iVar9 = TmpInsertTxTransactionManager(lVar14,(longlong)param_3);
            puVar17 = auStackY_98;
            if (iVar9 < 0) goto LAB_14001fc0d;
            goto LAB_14001f849;
          }
          if (((((param_5 & 1) != 0) && ((*(uint *)((longlong)param_3 + 0xc4) >> 8 & 1) != 0)) &&
              ((*(uint *)((longlong)param_3 + 0xc4) >> 10 & 1) != 0)) && (param_3[0x40] != lVar14))
          {
            puVar10 = (undefined8 *)param_3[0x20];
            goto LAB_14001f8e5;
          }
          if ((param_3[0x40] == lVar14) ||
             (*(code **)(param_2 + 0x128) == TmpInternalCrmNotification)) goto LAB_14001f849;
          lVar11 = param_3[0xb];
          uVar12 = TmpEnlistMultiTm(lVar14,param_3[0x40],local_48,(longlong)param_3,
                                    (longlong *)&local_38,&local_40);
          puVar10 = local_38;
        } while ((int)uVar12 == -0x3fffffe2);
        if ((int)uVar12 < 0) {
          puVar17 = auStackY_98;
          goto LAB_14001fc0d;
        }
        local_res18 = local_38;
        KeReleaseMutex(lVar11 + 0x20);
        ObfDereferenceObject(param_3);
        TmpAcquireTransactionMutex((longlong)puVar10);
        *(undefined8 **)(param_1 + 0x28) = puVar10;
        lVar11 = TmIsTransactionActive((longlong)puVar10);
        cVar7 = (char)lVar11;
LAB_14001f978:
        if (cVar7 == '\0') {
LAB_14001f7ed:
          puVar17 = auStackY_98;
          goto LAB_14001fc0d;
        }
LAB_14001f849:
        puVar17 = auStackY_98;
        puVar16 = auStackY_98;
        if ((param_5 & 1) != 0) {
          if (local_res18[0x1e] != 0) {
            puVar17 = auStackY_98;
            goto LAB_14001fc0d;
          }
          if (((*(uint *)(param_2 + 0x20) & 4) != 0) &&
             ((*(uint *)(local_res18[0x40] + 0x80) & 1) == 0)) goto LAB_14001fc0d;
        }
        KeWaitForSingleObject(param_2 + 0x28,0,0,0);
        if ((*(int *)(param_2 + 0x1c) != 1) || (*(int *)(lVar14 + 0x40) == 2)) {
          iVar9 = TmpInsertEnlistmentResourceManager((longlong)param_1,param_2);
          puVar17 = auStackY_98;
          if (-1 < iVar9) {
            param_1[0x2a] = 0x100;
            if ((param_5 & 1) != 0) {
              LOCK();
              param_1[0x2b] = param_1[0x2b] | 1;
              UNLOCK();
              local_res18[0x1e] = param_1;
              if (((*(uint *)((longlong)local_res18 + 0xc4) & 0x100) != 0) &&
                 ((param_6 >> 0x1a & 1) != 0)) {
                LOCK();
                *(uint *)((longlong)local_res18 + 0xc4) =
                     *(uint *)((longlong)local_res18 + 0xc4) | 0x1000;
                UNLOCK();
              }
            }
            if ((local_48 != 0) && ((*(uint *)(lVar14 + 0x80) & 0x10) != 0)) {
              LOCK();
              *(uint *)((longlong)local_res18 + 0xc4) =
                   *(uint *)((longlong)local_res18 + 0xc4) | 0x10000;
              UNLOCK();
            }
            if ((*(uint *)(param_2 + 0x20) & 4) == 0) {
              LOCK();
              param_1[0x2b] = param_1[0x2b] | 2;
              UNLOCK();
            }
            ObfReferenceObject(param_1);
            TmpAddTransactionEnlistmentCounts((longlong)param_1);
            plVar15 = (longlong *)(param_1 + 0x1e);
            plVar13 = local_res18 + 0x19;
            if (((uint)param_1[0x2c] >> 9 & 1) == 0) {
              puVar10 = (undefined8 *)local_res18[0x1a];
              if ((longlong *)*puVar10 != plVar13) {
                puVar10 = (undefined8 *)0x3;
                pcVar1 = (code *)swi(0x29);
                plVar13 = (longlong *)(*pcVar1)();
                puVar16 = auStackY_90;
              }
              *plVar15 = (longlong)plVar13;
              plVar15[1] = (longlong)puVar10;
              *puVar10 = plVar15;
              plVar13[1] = (longlong)plVar15;
            }
            else {
              lVar14 = *plVar13;
              puVar16 = auStackY_98;
              if (*(longlong **)(lVar14 + 8) != plVar13) {
                lVar14 = 3;
                pcVar1 = (code *)swi(0x29);
                plVar13 = (longlong *)(*pcVar1)();
                puVar16 = auStackY_90;
              }
              *plVar15 = lVar14;
              plVar15[1] = (longlong)plVar13;
              *(longlong **)(lVar14 + 8) = plVar15;
              *plVar13 = (longlong)plVar15;
            }
            *(undefined8 *)(puVar16 + -8) = 0x14001fbef;
            ObfReferenceObject(param_1);
            *(undefined8 *)(puVar16 + -8) = 0x14001fbfe;
            ObfReferenceObject(param_1);
            puVar17 = puVar16;
          }
          goto LAB_14001fc0d;
        }
      }
LAB_14001fc05:
      puVar17 = auStackY_98;
      goto LAB_14001fc0d;
    }
  }
  else if (((param_6 & 8) != 0) && ((param_6 & 0x207) == 0)) {
LAB_14001f555:
    bVar5 = true;
    goto LAB_14001f55c;
  }
LAB_14001f564:
  puVar17 = auStackY_98;
LAB_14001fc0d:
  lVar14 = *(longlong *)(puVar17 + 0x50);
  if (lVar14 != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x14001fc1f;
    TmpReleaseTxTableTransactionManager(lVar14);
    *(undefined8 *)(puVar17 + -8) = 0x14001fc29;
    ObfDereferenceObject(lVar14);
  }
  if (puVar17[0x30] != '\0') {
    lVar14 = *(longlong *)(*(longlong *)(puVar17 + 0xb0) + 0x58);
    *(undefined8 *)(puVar17 + -8) = 0x14001fc4e;
    KeReleaseMutex(lVar14 + 0x20);
  }
  if (puVar17[0x31] != '\0') {
    *(undefined8 *)(puVar17 + -8) = 0x14001fc67;
    KeReleaseMutex(param_2 + 0x28);
  }
  if (*(longlong *)(puVar17 + 0x48) != 0) {
    *(undefined8 *)(puVar17 + -8) = 0x14001fc7d;
    ObfDereferenceObject();
  }
  if ((-1 < *(int *)(puVar17 + 0x34)) && ((*(uint *)(puVar17 + 0xc0) & 1) != 0)) {
    lVar14 = *(longlong *)(*(longlong *)(puVar17 + 0xb0) + 0x110);
    if (lVar14 == 0) {
      uVar8 = *(uint *)(*(longlong *)(puVar17 + 0xb0) + 0xc4);
    }
    else {
      uVar8 = *(uint *)(lVar14 + 0xc4);
    }
    if ((uVar8 >> 0xe & 1) != 0) {
      lVar14 = *(longlong *)(param_1 + 0x28);
      *(undefined8 *)(puVar17 + -8) = 0x14001fcc8;
      iVar9 = TmpForwardCommitTransaction(lVar14);
      if (iVar9 < 0) {
        lVar14 = *(longlong *)(param_1 + 0x28);
        *(undefined8 *)(puVar17 + -8) = 0x14001fcda;
        TmRollbackTransaction(lVar14,'\0');
      }
    }
  }
  return *(undefined4 *)(puVar17 + 0x34);
LAB_14001f8e5:
  if (puVar10 == param_3 + 0x20) goto LAB_14001f564;
  local_res18 = puVar10 + -0x20;
  if ((puVar10[0x20] == lVar14) && (puVar10[-2] == 0)) {
    ObfReferenceObject(local_res18);
    KeReleaseMutex(param_3[0xb] + 0x20);
    ObfDereferenceObject(param_3);
    TmpAcquireTransactionMutex((longlong)local_res18);
    *(undefined8 **)(param_1 + 0x28) = local_res18;
    lVar11 = TmIsTransactionActive((longlong)local_res18);
    cVar7 = (char)lVar11;
    goto LAB_14001f978;
  }
  puVar10 = (undefined8 *)*puVar10;
  goto LAB_14001f8e5;
}



===== TmRollbackTransaction @ 14001fd00 =====

ulonglong TmRollbackTransaction(longlong param_1,char param_2)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  char *pcVar5;
  
                    /* 0x1fd00  74  TmRollbackTransaction */
  pcVar5 = "KTM:  TmRollbackTransactionExt for tx %lx\n";
  DbgPrintEx(0x6c,0x80000020,"KTM:  TmRollbackTransactionExt for tx %lx\n",param_1);
  TmpAcquireTransactionMutex(param_1);
  bVar2 = true;
  if (((*(uint *)(param_1 + 0xc4) >> 10 & 1) == 0) || ((*(uint *)(param_1 + 0xc4) >> 8 & 1) != 0)) {
    uVar3 = *(uint *)(param_1 + 0xc0);
    if (((uVar3 < 0xc) && ((0x906U >> (uVar3 & 0x1f) & 1) != 0)) ||
       ((uVar3 == 3 && ((*(uint *)(param_1 + 0xc4) & 2) != 0)))) {
      if (*(longlong *)(param_1 + 0x200) != 0) {
        uVar3 = TmpTxActionDoRollback(param_1,0xb,pcVar5);
        goto LAB_14001fd8b;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,pcVar5,param_1,param_1 + 0xb0)
        ;
      }
      *(undefined4 *)(param_1 + 0xc0) = 9;
      *(undefined4 *)(param_1 + 0x1f8) = 3;
      KeSetEvent(param_1,0,0);
      TmpFinalizeTransaction(param_1);
    }
    else if ((*(int *)(param_1 + 0xc0) != 6) && (*(int *)(param_1 + 0x1f8) != 3)) {
      if ((*(int *)(param_1 + 0xc0) == 5) || (*(int *)(param_1 + 0x1f8) == 2)) {
        uVar4 = 0xc0190016;
      }
      else {
        uVar4 = 0xc0190013;
      }
      goto LAB_14001fe71;
    }
    uVar4 = 0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x110);
    KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20);
    bVar2 = false;
    uVar4 = TmRollbackTransaction(lVar1,'\0');
    uVar3 = (uint)uVar4;
LAB_14001fd8b:
    uVar4 = (ulonglong)uVar3;
  }
LAB_14001fe71:
  if (bVar2) {
    KeReleaseMutex(*(longlong *)(param_1 + 0x58) + 0x20,0);
  }
  if (((int)uVar4 == 0x103) && (param_2 != '\0')) {
    uVar4 = TmpWaitForTransactionOutcome(param_1,3);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}



===== TmpNotifyEnlistment @ 14001fec4 =====

undefined4 TmpNotifyEnlistment(longlong param_1,char param_2,uint param_3,char param_4,int param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  bool bVar4;
  
  uVar2 = 0;
  bVar4 = false;
  if ((param_3 & *(uint *)(param_1 + 0xb0)) == 0) {
    uVar2 = 0;
  }
  else {
    ObfReferenceObject();
    lVar1 = param_1 + 0x40;
    if (param_4 != '\0') {
      KeWaitForSingleObject(lVar1,0,0,0,0);
      *(int *)(param_1 + 0xa8) = param_5;
      if ((*(uint *)(param_1 + 0xac) & 1) == 0) {
        bVar4 = (param_5 - 0x10dU & 0xfffffffd) == 0;
      }
      else if ((param_5 - 0x104U < 0xc) && ((0xa01U >> (param_5 - 0x104U & 0x1f) & 1) != 0)) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      *(uint *)(param_1 + 0x13c + (ulonglong)*(uint *)(param_1 + 0x138) * 8) = param_3;
      *(int *)(param_1 + 0x140 + (ulonglong)*(uint *)(param_1 + 0x138) * 8) = param_5;
      *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
      if (0x13 < *(uint *)(param_1 + 0x138)) {
        *(undefined4 *)(param_1 + 0x138) = 0;
      }
      KeReleaseMutex(lVar1,0);
    }
    if (param_2 != '\0') {
      uVar3 = 0x80000020;
      DbgPrintEx(0x6c,0x80000020,"KTM:  Notifying RM of %d for tx %lx\n",param_3,
                 *(undefined8 *)(param_1 + 0xa0));
      uVar2 = TmpSetNotificationResourceManager
                        (*(longlong *)(param_1 + 0x98),uVar3,param_1,*(undefined8 *)(param_1 + 0xb8)
                         ,param_3,0,(void *)0x0);
    }
    if (bVar4) {
      KeWaitForSingleObject(lVar1,0,0,0,0);
      TmpFinalizeEnlistment(param_1);
      KeReleaseMutex(lVar1,0);
    }
    ObfDereferenceObject(param_1);
  }
  return uVar2;
}



===== TmpTxActionDoCommit @ 140020090 =====

int TmpTxActionDoCommit(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  uint *puVar3;
  int iVar4;
  
  ExAcquireFastMutex(*(longlong *)(param_1 + 0x200) + 0x250);
  *(longlong *)(*(longlong *)(param_1 + 0x200) + 0x248) =
       *(longlong *)(*(longlong *)(param_1 + 0x200) + 0x248) + 1;
  ExReleaseFastMutex(*(longlong *)(param_1 + 0x200) + 0x250);
  plVar2 = (longlong *)(param_1 + 200);
  if (((longlong *)*plVar2 != plVar2) &&
     ((*(longlong *)(param_1 + 0xf0) == 0 ||
      ((longlong *)*plVar2 != (longlong *)*(longlong *)(param_1 + 0xd0))))) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x58) + 0xc4) >> 0x10 & 1) != 0) {
      KeWaitForSingleObject(&TmpTransactionThawEvent,0,0,0,0);
      LOCK();
      puVar3 = (uint *)(*(longlong *)(param_1 + 0x58) + 0xc4);
      *puVar3 = *puVar3 & 0xfffeffff;
      UNLOCK();
    }
    param_3 = 1;
    iVar4 = TmpLogTransaction(param_1,3,1);
    if (iVar4 != 0) {
      if ((*(uint *)(param_1 + 0xc4) & 2) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          WPP_SF_q_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,param_1 + 0xb0,param_1,
                          param_1 + 0xb0,(char)iVar4);
        }
        TmpTraceTransactionRollbackLogError(param_1,iVar4);
        TmRollbackTransaction(param_1,'\0');
        if (iVar4 != -0x3fe6ffa5) {
          return iVar4;
        }
        if (*(int *)(param_1 + 0xc0) - 3U < 2) {
          TmpForgetTransaction(param_1,'\x01','\x01');
          return -0x3fe6ffa5;
        }
        return -0x3fe6ffa5;
      }
      if (iVar4 != -0x3ffffee0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
          lVar1 = *(longlong *)(param_1 + 0x200) + 0x70;
          WPP_SF_q_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,lVar1,
                          *(longlong *)(param_1 + 0x200),lVar1,(char)iVar4);
        }
        TmpQueueOfflineTm(*(longlong *)(param_1 + 0x200));
        return iVar4;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffee0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) {
        return -0x3ffffee0;
      }
      WPP_SF_q_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,param_3,param_1,param_1 + 0xb0,
                      0x20);
      return -0x3ffffee0;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,param_3,param_1,param_1 + 0xb0);
  }
  *(undefined4 *)(param_1 + 0xc0) = 5;
  *(undefined4 *)(param_1 + 0x1f8) = 2;
  if (((longlong *)*plVar2 == plVar2) ||
     ((*(longlong *)(param_1 + 0xf0) != 0 && ((longlong *)*plVar2 == *(longlong **)(param_1 + 0xd0))
      ))) {
    iVar4 = TmpTxActionDoCommitComplete(param_1,param_2,param_3);
  }
  else {
    iVar4 = TmpNotifyAllEnlistmentsTransaction(param_1,4,param_3,0x105);
  }
  return iVar4;
}



===== TmpTxActionDoCommitComplete @ 140020370 =====

undefined4 TmpTxActionDoCommitComplete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xc0) == 7) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,param_3,param_1,param_1 + 0xb0)
      ;
    }
    *(undefined4 *)(param_1 + 0xc0) = 5;
    *(undefined4 *)(param_1 + 0x1f8) = 2;
    TmpNotifyAllEnlistmentsTransaction(param_1,4,param_3,0x105);
  }
  else if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0) {
    TmpLogTransaction(param_1,4,0);
  }
  KeSetEvent(param_1,0,0);
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    uVar2 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x40,'\x01',0x104);
  }
  if (((*(uint *)(*(longlong *)(param_1 + 0x58) + 0xc4) >> 0x11 & 1) != 0) &&
     (*(longlong *)(param_1 + 0x58) == param_1)) {
    LOCK();
    iVar1 = TmpTransactionsCommittedActive + -1;
    UNLOCK();
    bVar3 = TmpTransactionsCommittedActive == 1;
    TmpTransactionsCommittedActive = iVar1;
    if (bVar3) {
      KeSetEvent(&TmpTransactionFreezeCompleteEvent,0,0);
    }
  }
  *(undefined4 *)(param_1 + 0xc0) = 9;
  TmpFinalizeTransaction(param_1);
  return uVar2;
}



===== TmpTxActionDoPrepare @ 1400204a0 =====

int TmpTxActionDoPrepare(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  
  if ((((*(uint *)(param_1 + 0xc4) >> 8 & 1) == 0) || ((*(uint *)(param_1 + 0xc4) >> 10 & 1) == 0))
     || (cVar2 = TmpPromotionsIncomplete(param_1), cVar2 == '\0')) {
    *(undefined4 *)(param_1 + 0xc0) = 2;
    plVar1 = *(longlong **)(param_1 + 200);
    if (((plVar1 == (longlong *)(param_1 + 200)) ||
        ((*(longlong *)(param_1 + 0xf0) != 0 &&
         (plVar1 == (longlong *)*(longlong *)(param_1 + 0xd0))))) || (*(int *)(param_1 + 0xe4) == 0)
       ) {
      iVar3 = TmpTxActionDoPrepareComplete(param_1,param_2,param_2);
      return iVar3;
    }
    iVar3 = TmpNotifyAllEnlistmentsTransaction(param_1,2,param_2,0x101);
    if (-1 < iVar3) {
      return iVar3;
    }
  }
  else {
    iVar3 = -0x3fe6ffed;
  }
  TmRollbackTransaction(param_1,'\0');
  return iVar3;
}



===== TmpTxActionDoPrepareComplete @ 140020550 =====

int TmpTxActionDoPrepareComplete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  
  if ((*(longlong *)(param_1 + 0xf0) == 0) || ((*(uint *)(param_1 + 0xc4) & 2) != 0)) {
    *(undefined4 *)(param_1 + 0xc0) = 3;
    iVar2 = TmpTxActionDoCommit(param_1,param_2,param_3);
  }
  else {
    plVar1 = *(longlong **)(param_1 + 200);
    if ((plVar1 != (longlong *)(param_1 + 200)) &&
       (((*(longlong *)(param_1 + 0xf0) == 0 ||
         (plVar1 != (longlong *)*(longlong *)(param_1 + 0xd0))) &&
        (iVar2 = TmpLogTransaction(param_1,2,1), iVar2 < 0)))) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
        WPP_SF_q_guid_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_1 + 0xb0,param_1,
                        param_1 + 0xb0,(char)iVar2);
      }
      TmpTraceTransactionRollbackLogError(param_1,iVar2);
      TmRollbackTransaction(param_1,'\0');
      return iVar2;
    }
    *(undefined4 *)(param_1 + 0xc0) = 3;
    iVar2 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),'\x01',0x20,'\x01',0x102);
  }
  return iVar2;
}



===== TmpTxActionDoRollback @ 140020654 =====

int TmpTxActionDoRollback(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  iVar3 = 0;
  if ((*(int *)(param_1 + 0xc0) - 3U < 2) && ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0)) {
    param_3 = 0;
    iVar3 = TmpLogTransaction(param_1,4,0);
  }
  *(void **)(param_1 + 0x140) = SystemReserved1[0xf];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_q_guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0xb0,param_3,param_1,
                    param_1 + 0xb0,(char)*(undefined4 *)(param_1 + 0xd8));
  }
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0xc0) = 6;
  *(undefined4 *)(param_1 + 0x1f8) = 3;
  KeSetEvent(param_1);
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    uVar1 = *(uint *)(param_1 + 0xc4);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_sqq_guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
    }
    uVar5 = 8;
    iVar3 = TmpNotifyEnlistment(*(longlong *)(param_1 + 0xf0),~(byte)(uVar1 >> 6) & 1,8,'\x01',0x10d
                               );
  }
  plVar2 = *(longlong **)(param_1 + 200);
  if ((plVar2 != (longlong *)(param_1 + 200)) &&
     ((*(longlong *)(param_1 + 0xf0) == 0 || (plVar2 != (longlong *)*(longlong *)(param_1 + 0xd0))))
     ) {
    iVar3 = TmpNotifyAllEnlistmentsTransaction(param_1,8,uVar5,0x10d);
  }
  if (((*(uint *)(param_1 + 0xc4) >> 8 & 1) != 0) && ((*(uint *)(param_1 + 0xc4) >> 10 & 1) != 0)) {
    for (puVar4 = *(undefined8 **)(param_1 + 0x100); puVar4 != (undefined8 *)(param_1 + 0x100);
        puVar4 = (undefined8 *)*puVar4) {
      iVar3 = TmpTxActionDoRollback((longlong)(puVar4 + -0x20),0,uVar5);
    }
  }
  *(undefined4 *)(param_1 + 0xc0) = 9;
  TmpFinalizeTransaction(param_1);
  return iVar3;
}



===== TmInitializeResourceManager @ 14002082c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
TmInitializeResourceManager(longlong param_1,undefined4 *param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  
  *(undefined4 *)(param_1 + 0x18) = 0xb00b0002;
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x20) = 1;
  if ((param_3 & 1) == 0) {
    if (param_4 != 0) {
      local_28 = 0;
      KeWaitForSingleObject(param_4 + 8,0,0,0);
      uVar2 = *(uint *)(param_4 + 0x80);
      KeReleaseMutex(param_4 + 8,0);
      if ((uVar2 & 1) != 0) {
        return 0xc019003b;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 5;
  }
  puVar11 = auStack_48;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined1 *)(param_1 + 0x80) = 0;
  uVar7 = TmpNamespaceInitialize(param_1 + 0x180,8,0x30);
  if (-1 < (int)uVar7) {
    if (param_2 == (undefined4 *)0x0) {
      ExUuidCreate((undefined4 *)(param_1 + 0x88));
    }
    else {
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      uVar6 = param_2[3];
      *(undefined4 *)(param_1 + 0x88) = *param_2;
      *(undefined4 *)(param_1 + 0x8c) = uVar4;
      *(undefined4 *)(param_1 + 0x90) = uVar5;
      *(undefined4 *)(param_1 + 0x94) = uVar6;
    }
    *(undefined4 *)(param_1 + 0x120) = 0;
    KeInitializeEvent(param_1,0,0);
    KeInitializeQueue(param_1 + 0x98,0);
    KeInitializeMutex(param_1 + 0xd8,0);
    KeInitializeMutex(param_1 + 0x28,0);
    *(undefined8 *)(param_1 + 0x238) = 0;
    lVar1 = param_1 + 0x110;
    *(longlong *)(param_1 + 0x118) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = param_1 + 0x138;
    *(longlong *)(param_1 + 0x140) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = param_1 + 0x148;
    *(longlong *)(param_1 + 0x150) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = param_1 + 0x228;
    *(longlong *)(param_1 + 0x230) = lVar1;
    *(longlong *)lVar1 = lVar1;
    if (param_4 == 0) {
      *(undefined8 *)(param_1 + 0x168) = 0;
    }
    else {
      uVar7 = TmpInsertResourceManagerTm(param_1,param_4);
      if ((int)uVar7 < 0) {
        return uVar7;
      }
    }
    if ((param_3 & 2) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 8;
      local_28 = 0;
      KeWaitForSingleObject(&TmpAllCRMListMutex,0,0,0);
      puVar10 = &TmpAllCRMList;
      puVar8 = (undefined8 *)(param_1 + 0x158);
      puVar9 = DAT_140008408;
      puVar11 = auStack_48;
      if ((undefined8 *)*DAT_140008408 != &TmpAllCRMList) {
        puVar9 = (undefined8 *)0x3;
        pcVar3 = (code *)swi(0x29);
        puVar8 = (undefined8 *)(*pcVar3)();
        puVar11 = auStack_40;
      }
      _TmpAllCRMListCount = _TmpAllCRMListCount + 1;
      *puVar8 = puVar10;
      puVar8[1] = puVar9;
      *puVar9 = puVar8;
      *(undefined8 *)(puVar11 + -8) = 0x140020a43;
      DAT_140008408 = puVar8;
      KeReleaseMutex(&TmpAllCRMListMutex,0);
    }
    lVar1 = *(longlong *)(puVar11 + 0x70);
    *(undefined8 *)(param_1 + 0x178) = 0;
    *(undefined2 *)(param_1 + 0x170) = 0;
    *(undefined2 *)(param_1 + 0x172) = 0;
    if (lVar1 != 0) {
      *(undefined8 *)(puVar11 + -8) = 0x140020a75;
      RtlDuplicateUnicodeString(0);
    }
    *(undefined4 *)(param_1 + 0x1c) = 2;
    uVar7 = 0;
  }
  return uVar7;
}



===== TmpCloseResourceManager @ 140020ab0 =====

void TmpCloseResourceManager(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  bool bVar5;
  char cVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  
  lVar1 = param_2 + 0x28;
  lVar9 = 0;
  bVar5 = false;
  KeWaitForSingleObject(lVar1,0,0,0,0);
  if (((param_3 == 1) && ((*(uint *)(param_2 + 0x20) & 0x10) != 0)) &&
     (*(longlong *)(param_2 + 0x248) == param_1)) {
    TmpRundownResourceManagerNotificationRequests(param_2);
    ObfDereferenceObject(*(undefined8 *)(param_2 + 0x238));
    LOCK();
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xffffffef;
    UNLOCK();
  }
  if (param_4 == 1) {
    plVar2 = (longlong *)(param_2 + 0x110);
    plVar8 = (longlong *)*plVar2;
    if (plVar8 != plVar2) {
      plVar7 = (longlong *)0x0;
      do {
        plVar3 = plVar8 + -0x11;
        if ((*(uint *)((longlong)plVar8 + 0x24) & 4) == 0) {
          ObfReferenceObject(plVar3);
          KeReleaseMutex(lVar1,0);
          TmpRmDisconnectTransaction((longlong)plVar3);
          KeWaitForSingleObject(lVar1,0,0,0,0);
          if ((plVar7 != (longlong *)0x0) && ((*(uint *)((longlong)plVar7 + 0xac) & 4) != 0)) {
            ObfDereferenceObject(plVar7);
            plVar7 = (longlong *)0x0;
          }
          if ((*(uint *)((longlong)plVar8 + 0x24) & 4) == 0) {
            if (plVar7 != (longlong *)0x0) {
              ObfDereferenceObject(plVar7);
            }
            ObfReferenceObject(plVar3);
            plVar7 = plVar3;
          }
          if (plVar7 == (longlong *)0x0) {
            plVar8 = (longlong *)*plVar2;
          }
          else {
            plVar8 = (longlong *)plVar7[0x11];
          }
          ObfDereferenceObject(plVar3);
        }
        else {
          plVar8 = (longlong *)*plVar8;
        }
      } while (plVar8 != plVar2);
      if (plVar7 != (longlong *)0x0) {
        ObfDereferenceObject(plVar7);
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = 1;
    TmpNamespaceExpire(param_2 + 0x180);
    cVar6 = RtlIsGenericTableEmptyAvl(param_2 + 0x180);
    bVar5 = false;
    if (cVar6 != '\0') {
      lVar4 = *(longlong *)(param_2 + 0x168);
      *(undefined1 *)(param_2 + 0x80) = 1;
      if (lVar4 != 0) {
        *(undefined8 *)(param_2 + 0x168) = 0;
        bVar5 = true;
        lVar9 = lVar4;
      }
    }
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 1;
    plVar2 = (longlong *)(param_2 + 0x138);
    *(undefined8 *)(param_2 + 0x128) = 0;
    *(undefined8 *)(param_2 + 0x130) = 0;
    if ((longlong *)*plVar2 != plVar2) {
      KeWaitForSingleObject(&TmpAllProtocolsListMutex,0,0,0,0);
      while ((longlong *)*plVar2 != plVar2) {
        TmpDeleteProtocol((longlong)((longlong *)*plVar2 + -10));
      }
      KeReleaseMutex(&TmpAllProtocolsListMutex,0);
    }
  }
  KeReleaseMutex(lVar1,0);
  if (bVar5) {
    TmpNamespaceRemove(lVar9 + 0x158,lVar9,param_2);
  }
  return;
}



===== TmpDeleteResourceManager @ 140020d40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TmpDeleteResourceManager(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    KeWaitForSingleObject(param_1 + 0x28,0,0,0,0);
    if ((*(uint *)(param_1 + 0x20) & 8) != 0) {
      KeWaitForSingleObject(&TmpAllCRMListMutex,0,0,0,0);
      plVar4 = (longlong *)(param_1 + 0x158);
      lVar1 = *plVar4;
      if ((*(longlong **)(lVar1 + 8) != plVar4) ||
         (plVar5 = *(longlong **)(param_1 + 0x160), (longlong *)*plVar5 != plVar4)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _TmpAllCRMListCount = _TmpAllCRMListCount + -1;
      *plVar5 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar5;
      KeReleaseMutex(&TmpAllCRMListMutex,0);
      LOCK();
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff7;
      UNLOCK();
    }
    KeWaitForSingleObject(param_1 + 0xd8,0,0,0,0);
    plVar4 = (longlong *)KeRundownQueue(param_1 + 0x98);
    KeInitializeQueue(param_1 + 0x98,0);
    KeResetEvent(param_1);
    KeReleaseMutex(param_1 + 0xd8,0);
    lVar1 = *(longlong *)(param_1 + 0x168);
    lVar6 = 0;
    if (lVar1 != 0) {
      *(undefined8 *)(param_1 + 0x168) = 0;
      lVar6 = lVar1;
    }
    if (*(longlong *)(param_1 + 0x178) != 0) {
      RtlFreeUnicodeString(param_1 + 0x170);
    }
    KeReleaseMutex(param_1 + 0x28,0);
    if (lVar1 != 0) {
      TmpNamespaceRemove(lVar6 + 0x158,lVar6,param_1);
    }
    if (plVar4 != (longlong *)0x0) {
      plVar5 = plVar4;
      do {
        if (plVar5[2] != 0) {
          ObfDereferenceObject();
          plVar5[2] = 0;
        }
        plVar2 = (longlong *)*plVar5;
        ExFreePoolWithTag(plVar5,0);
        plVar5 = plVar2;
      } while (plVar4 != plVar2);
    }
  }
  return;
}



===== TmpOpenResourceManager @ 140020f40 =====

undefined4 TmpOpenResourceManager(void)

{
  uint uVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong in_R9;
  
  plVar4 = (longlong *)0x0;
  uVar3 = 0;
  KeWaitForSingleObject(in_R9 + 0x28,0,0,0,0);
  if (*(int *)(in_R9 + 0x1c) == 1) {
    KeWaitForSingleObject(in_R9 + 0xd8,0,0,0,0);
    plVar4 = (longlong *)KeRundownQueue(in_R9 + 0x98);
    KeInitializeQueue(in_R9 + 0x98);
    KeResetEvent();
    KeReleaseMutex(in_R9 + 0xd8);
    TmpNamespaceActivate(in_R9 + 0x180);
  }
  uVar1 = *(uint *)(in_R9 + 0x20);
  KeReleaseMutex(in_R9 + 0x28);
  if ((uVar1 & 8) != 0) {
    uVar3 = TmpNamespaceForEach(0x1400084e0,(undefined *)0x0,TmpNotifyResourceManagerTmOnline);
  }
  if (plVar4 != (longlong *)0x0) {
    plVar5 = plVar4;
    do {
      if (plVar5[2] != 0) {
        ObfDereferenceObject();
        plVar5[2] = 0;
      }
      plVar2 = (longlong *)*plVar5;
      ExFreePoolWithTag(plVar5,0);
      plVar5 = plVar2;
    } while (plVar4 != plVar2);
  }
  return uVar3;
}



===== NtCreateResourceManager @ 1400210a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NtCreateResourceManager
              (undefined8 *param_1,undefined4 param_2,longlong param_3,undefined8 *param_4,
              undefined8 param_5,uint param_6,uint *param_7)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  void *_Dst;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong local_88;
  longlong local_80;
  uint *local_78;
  void *local_70;
  undefined8 local_68;
  void *pvStack_60;
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
                    /* 0x210a0  7  NtCreateResourceManager */
  local_80 = 0;
  local_88 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_68 = 0;
  pvStack_60 = (void *)0x0;
  local_78 = (uint *)0x0;
  local_70 = (void *)0x0;
  bVar2 = false;
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  if (cVar1 == '\0') {
    local_78 = param_7;
    local_48 = *param_4;
    uStack_40 = param_4[1];
  }
  else {
    puVar6 = param_1;
    if (*(undefined8 **)MmUserProbeAddress_exref <= param_1) {
      puVar6 = *(undefined8 **)MmUserProbeAddress_exref;
    }
    *puVar6 = *puVar6;
    if (param_7 != (uint *)0x0) {
      if (*(uint **)MmUserProbeAddress_exref <= param_7) {
        param_7 = *(uint **)MmUserProbeAddress_exref;
      }
      local_68 = (ulonglong)*param_7;
      pvStack_60 = *(void **)(param_7 + 2);
      sVar3 = (short)*param_7;
      if (sVar3 != 0) {
        local_68 = (ulonglong)CONCAT22(sVar3,sVar3);
        if (((ulonglong)pvStack_60 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        _Dst = (void *)ExAllocatePoolWithQuotaTag(1,sVar3,0x73436d54);
        local_70 = _Dst;
        memcpy(_Dst,pvStack_60,local_68 & 0xffff);
        local_78 = (uint *)&local_68;
        pvStack_60 = _Dst;
      }
    }
    if (((ulonglong)param_4 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseDatatypeMisalignment();
    }
    local_48 = *param_4;
    uStack_40 = param_4[1];
  }
  if (param_6 < 4) {
    if ((param_3 == -2) && (cVar1 != '\0')) {
      iVar4 = -0x3ffffff8;
      goto LAB_140021475;
    }
    if ((local_78 == (uint *)0x0) || ((ushort)*local_78 < 0x81)) {
      if (param_3 == -2) {
        local_80 = 0;
      }
      else {
        local_50 = 0;
        iVar4 = ObReferenceObjectByHandle
                          (param_3,0x10,TmTransactionManagerObjectType,cVar1,&local_50,0);
        local_80 = local_50;
        if (iVar4 < 0) goto LAB_140021475;
      }
      iVar4 = ObCreateObject(cVar1,TmResourceManagerObjectType,param_5,cVar1,0,0x250,0,0,&local_88);
      if (-1 < iVar4) {
        *(undefined4 *)(local_88 + 0x1c) = 0;
        uVar5 = TmInitializeResourceManager(local_88,(undefined4 *)&local_48,param_6,local_80);
        iVar4 = (int)uVar5;
        if (iVar4 < 0) {
          ObfDereferenceObject();
        }
        else {
          ObfReferenceObject(local_88);
          bVar2 = true;
          iVar4 = ObInsertObject(local_88,0,param_2,0,0,&local_58);
          if (iVar4 < 0) {
            (**(code **)(TmResourceManagerObjectType + 0x80))(0,local_88,1);
          }
          else if (cVar1 == '\0') {
            *param_1 = local_58;
          }
          else {
            *param_1 = local_58;
          }
        }
      }
      goto LAB_140021475;
    }
  }
  iVar4 = -0x3ffffff3;
LAB_140021475:
  if (bVar2) {
    ObfDereferenceObject(local_88);
  }
  if (local_80 != 0) {
    ObfDereferenceObject();
  }
  if (local_70 != (void *)0x0) {
    ExFreePoolWithTag(local_70,0);
  }
  return iVar4;
}



===== TmInitializeTransactionManager @ 1400214c0 =====

ulonglong TmInitializeTransactionManager
                    (undefined4 *param_1,undefined8 param_2,undefined8 *param_3,uint param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffff80;
  undefined4 uVar10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
                    /* 0x214c0  56  TmInitializeTransactionManager */
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  *param_1 = 0xb00b0004;
  local_48 = 0;
  uStack_40 = uStack_40 & 0xffffffff00000000;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  KeInitializeMutex(param_1 + 2,0);
  param_1[0x10] = 1;
  *(undefined8 *)(param_1 + 0x20) = 0;
  param_1[0xde] = 0;
  puVar1 = (undefined8 *)(param_1 + 0x1c);
  *(undefined8 *)(param_1 + 0x26) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x2a) = 0;
  *(undefined8 *)(param_1 + 0x24) = 0;
  *(undefined2 *)(param_1 + 0x22) = 0;
  *(undefined2 *)((longlong)param_1 + 0x8a) = 0;
  *(undefined8 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  if (param_3 == (undefined8 *)0x0) {
    LOCK();
    param_1[0x20] = param_1[0x20] | 0x20;
    UNLOCK();
    ExUuidCreate(puVar1);
  }
  else {
    uVar8 = param_3[1];
    *puVar1 = *param_3;
    *(undefined8 *)(param_1 + 0x1e) = uVar8;
  }
  uVar7 = TmpNamespaceInitialize((longlong)(param_1 + 0x2c),0x88,0xb0);
  uVar9 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_14002183c;
  uVar7 = TmpNamespaceInitialize((longlong)(param_1 + 0x56),0x60,0x88);
  uVar9 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_14002183c;
  *(undefined8 *)(param_1 + 0x96) = 0;
  param_1[0x94] = 1;
  param_1[0x98] = 0;
  KeInitializeEvent(param_1 + 0x9a,1,0);
  pcVar5 = CLFS_LSN_NULL_exref;
  plVar2 = (longlong *)(param_1 + 0xa8);
  *(undefined8 *)(param_1 + 0x92) = 1;
  *(undefined8 *)(param_1 + 0xa2) = *(undefined8 *)pcVar5;
  *(undefined8 *)(param_1 + 0xa4) = *(undefined8 *)pcVar5;
  *(undefined8 *)(param_1 + 0xe2) = *(undefined8 *)pcVar5;
  *(undefined8 *)(param_1 + 0xa6) = *(undefined8 *)pcVar5;
  *plVar2 = 0;
  *(undefined8 *)(param_1 + 0xaa) = 0;
  KeInitializeMutex(param_1 + 0x80);
  puVar3 = param_1 + 0x8e;
  *(undefined4 **)(param_1 + 0x90) = puVar3;
  uVar8 = 0;
  *(undefined4 **)puVar3 = puVar3;
  KeInitializeEvent(param_1 + 0xac,0,1);
  ExInitializeResourceLite(param_1 + 0xc4);
  puVar3 = param_1 + 0xe4;
  *(undefined8 *)(param_1 + 0xdf) = 0;
  *(undefined4 **)(param_1 + 0xe6) = puVar3;
  *(undefined4 **)puVar3 = puVar3;
  iVar4 = DAT_140008204;
  if ((param_4 & 2) == 0) {
LAB_1400216c9:
    iVar4 = DAT_140008200;
    if ((param_4 & 4) != 0) {
      LOCK();
      DAT_140008200 = 1;
      UNLOCK();
      if (iVar4 != 0) goto LAB_1400216b7;
      LOCK();
      param_1[0x20] = param_1[0x20] | 4;
      UNLOCK();
    }
    if ((param_4 & 8) != 0) {
      LOCK();
      param_1[0x20] = param_1[0x20] | 8;
      UNLOCK();
    }
    if ((param_4 & 0x10) != 0) {
      LOCK();
      param_1[0x20] = param_1[0x20] | 0x80;
      UNLOCK();
    }
    if ((param_4 & 0x20) != 0) {
      LOCK();
      param_1[0x20] = param_1[0x20] | 0x40;
      UNLOCK();
    }
    if ((param_4 & 1) == 0) {
      uVar6 = RtlDuplicateUnicodeString(0,param_2,param_1 + 0x22);
      uVar9 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) goto LAB_14002183c;
    }
    else {
      LOCK();
      param_1[0x20] = param_1[0x20] | 1;
      UNLOCK();
      param_2 = uVar8;
    }
    if ((param_1[0x20] & 1) == 0) {
      uVar6 = TmpCreateOrOpenLogTransactionManager((longlong)param_1);
    }
    else {
      uVar8 = TmpTmOnline((longlong)param_1,param_2);
      uVar6 = (uint)uVar8;
    }
    uVar9 = (ulonglong)uVar6;
    if (-1 < (int)uVar6) {
      local_68 = CONCAT44(local_68._4_4_,0x30);
      uStack_60 = 0;
      uStack_50 = CONCAT44(uStack_50._4_4_,0x200);
      local_58 = 0;
      local_48 = 0;
      uStack_40 = 0;
      uVar6 = ZwCreateResourceManager
                        (plVar2,0x1f007f,0xfffffffffffffffe,puVar1,&local_68,
                         CONCAT44(uVar10,param_1[0x20]) & 0xffffffff00000001,0);
      uVar9 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        local_res8 = 0;
        uVar6 = ObReferenceObjectByHandle(*plVar2,0,TmResourceManagerObjectType,0,&local_res8,0);
        uVar9 = (ulonglong)uVar6;
        *(longlong *)(param_1 + 0xaa) = local_res8;
        if (-1 < (int)uVar6) {
          TmEnableCallbacks(local_res8,0x140016ff0,*plVar2);
          TmpInsertResourceManagerTm(*(longlong *)(param_1 + 0xaa),(longlong)param_1);
          uVar6 = TmpNamespaceInsert(0x1400084e0,0,(longlong)param_1);
          uVar9 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            return uVar9;
          }
        }
      }
    }
  }
  else {
    LOCK();
    DAT_140008204 = 1;
    UNLOCK();
    if (iVar4 == 0) {
      LOCK();
      param_1[0x20] = param_1[0x20] | 2;
      UNLOCK();
      goto LAB_1400216c9;
    }
LAB_1400216b7:
    uVar9 = 0xc000000d;
  }
LAB_14002183c:
  param_1[0x10] = 4;
  if (*(longlong *)(param_1 + 0xa8) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  if (*(longlong *)(param_1 + 0xaa) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0xaa) = 0;
  }
  return uVar9;
}



===== TmpAddTransactionEnlistmentCounts @ 1400218a4 =====

void TmpAddTransactionEnlistmentCounts(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xa0);
  if ((*(uint *)(param_1 + 0xb0) & 2) != 0) {
    *(int *)(lVar1 + 0xe4) = *(int *)(lVar1 + 0xe4) + 1;
  }
  if ((*(uint *)(param_1 + 0xac) & 2) != 0) {
    *(int *)(lVar1 + 0xdc) = *(int *)(lVar1 + 0xdc) + 1;
  }
  if ((*(uint *)(param_1 + 0xb0) & 1) != 0) {
    *(int *)(lVar1 + 0xe0) = *(int *)(lVar1 + 0xe0) + 1;
  }
  if ((((*(uint *)(param_1 + 0xb0) & 4) != 0) && ((*(uint *)(param_1 + 0xb0) >> 0x18 & 1) == 0)) ||
     ((*(uint *)(param_1 + 0xac) & 0x10) != 0)) {
    *(int *)(lVar1 + 0xe8) = *(int *)(lVar1 + 0xe8) + 1;
    LOCK();
    *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | 0x10;
    UNLOCK();
  }
  *(int *)(lVar1 + 0xd8) = *(int *)(lVar1 + 0xd8) + 1;
  return;
}



===== TmpCreateInternalCrmEnlistment @ 140021924 =====

int TmpCreateInternalCrmEnlistment
              (undefined8 param_1,longlong param_2,uint param_3,longlong param_4,longlong param_5,
              undefined8 param_6,longlong *param_7,longlong *param_8)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffff80;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong local_60;
  longlong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  local_28 = local_28 & 0xffffffff00000000;
  local_60 = 0;
  *param_8 = 0;
  *param_7 = 0;
  iVar1 = ObOpenObjectByPointer
                    (0,0x200,0,0x1f003f,TmTransactionObjectType,
                     in_stack_ffffffffffffff80 & 0xffffffffffffff00,&local_60);
  if (-1 < iVar1) {
    local_50 = CONCAT44(local_50._4_4_,0x30);
    uStack_48 = 0;
    uStack_38 = CONCAT44(uStack_38._4_4_,0x200);
    local_40 = 0;
    local_30 = *(undefined8 *)SeSystemDefaultSd_exref;
    local_28 = 0;
    uVar3 = 0;
    uVar2 = (ulonglong)((-(uint)((param_3 & 1) != 0) & 0x20fffe69) + 0x20f);
    iVar1 = ZwCreateEnlistment(param_8,0xf001f,*(undefined8 *)(param_2 + 0x2a0),local_60,&local_50,
                               param_3,uVar2,0,iVar1);
    if (-1 < iVar1) {
      local_58 = 0;
      iVar1 = ObReferenceObjectByHandle
                        (*param_8,0,TmEnlistmentObjectType,0,&local_58,0,uVar2,uVar3,iVar1);
      *param_7 = local_58;
      if ((-1 < iVar1) && (param_5 != 0)) {
        TmpInternalCrmLinkEnlistment(local_58,param_4,param_5);
        TmpInternalCrmLinkEnlistment(param_4,*param_7,*param_8);
        if (((*(uint *)(*param_7 + 0xac) & 2) == 0) && ((*(uint *)(param_4 + 0xac) & 2) != 0)) {
          LOCK();
          *(uint *)(param_4 + 0xac) = *(uint *)(param_4 + 0xac) & 0xfffffffd;
          UNLOCK();
          *(int *)(*(longlong *)(param_4 + 0xa0) + 0xdc) =
               *(int *)(*(longlong *)(param_4 + 0xa0) + 0xdc) + -1;
        }
        if (((*(uint *)(*param_7 + 0xac) & 2) != 0) && ((*(uint *)(param_4 + 0xac) & 2) == 0)) {
          LOCK();
          *(uint *)(*param_7 + 0xac) = *(uint *)(*param_7 + 0xac) & 0xfffffffd;
          UNLOCK();
          *(int *)(*(longlong *)(*param_7 + 0xa0) + 0xdc) =
               *(int *)(*(longlong *)(*param_7 + 0xa0) + 0xdc) + -1;
        }
        if ((param_3 & 1) == 0) {
          *(undefined8 *)(param_4 + 0x100) = param_6;
        }
        else {
          *(undefined8 *)(*param_7 + 0x100) = param_6;
        }
      }
    }
  }
  if (local_60 != 0) {
    ZwClose();
  }
  if (iVar1 < 0) {
    if (*param_7 != 0) {
      ObfDereferenceObject();
      *param_7 = 0;
    }
    if (*param_8 != 0) {
      ZwClose();
      *param_8 = 0;
    }
  }
  return iVar1;
}



===== TmpDeleteTransactionManager @ 140021bd0 =====

void TmpDeleteTransactionManager(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  if (*(int *)(param_1 + 0x40) != 0) {
    LOCK();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x80000000;
    UNLOCK();
    TmpTmOffline(param_1);
    lVar1 = *(longlong *)(param_1 + 0xa8);
    lVar5 = 0;
    if (lVar1 != 0) {
      *(undefined8 *)(param_1 + 0xa8) = 0;
      lVar5 = lVar1;
    }
    if (*(longlong *)(param_1 + 0xa0) != 0) {
      ClfsDeleteMarshallingArea();
      *(undefined8 *)(param_1 + 0xa0) = 0;
    }
    if (*(longlong *)(param_1 + 0x98) != 0) {
      ClfsCloseLogFileObject();
      *(undefined8 *)(param_1 + 0x98) = 0;
    }
    if (lVar5 != 0) {
      ClfsMgmtDeregisterManagedClient(lVar5);
    }
    if (((*(uint *)(param_1 + 0x80) & 1) == 0) && (*(longlong *)(param_1 + 0x90) != 0)) {
      RtlFreeUnicodeString(param_1 + 0x88);
    }
    puVar6 = *(undefined8 **)(param_1 + 0x390);
    while (puVar6 != (undefined8 *)(param_1 + 0x390)) {
      puVar2 = (undefined8 *)*puVar6;
      if (((undefined8 *)puVar2[1] != puVar6) ||
         (puVar3 = (undefined8 *)puVar6[1], (undefined8 *)*puVar3 != puVar6)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *puVar3 = puVar2;
      puVar2[1] = puVar3;
      ExFreePoolWithTag(puVar6 + -1,0);
      puVar6 = puVar2;
    }
    ExDeleteResourceLite(param_1 + 0x310);
  }
  return;
}



===== TmpEnlistMultiTm @ 140021d00 =====

ulonglong TmpEnlistMultiTm(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                          longlong *param_5,longlong *param_6)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  byte bVar4;
  byte bVar5;
  undefined2 uVar6;
  byte bVar7;
  longlong *plVar8;
  longlong local_res20;
  
  *param_5 = 0;
  local_res20 = param_4;
  uVar3 = TmpNamespaceLookup(param_1 + 0xb0,param_4 + 0xb0,param_5);
  if (-1 < (int)uVar3) {
    return uVar3;
  }
  bVar7 = 1;
  bVar5 = (byte)((uint)*(undefined4 *)(param_1 + 0x80) >> 8) & 1;
  if ((*(uint *)(*(longlong *)(local_res20 + 0x200) + 0x80) >> 8 & 1) != 0) {
    bVar5 = 1;
  }
  bVar4 = 0;
  if ((*(uint *)(param_1 + 0x80) & 1) == 0) {
    bVar4 = bVar5;
  }
  if (bVar4 != 0) {
    if ((*(uint *)(local_res20 + 0xc4) >> 0xb & 1) == 0) {
      iVar1 = TmpPromoteTransaction(local_res20,param_1,param_5);
      return CONCAT44(extraout_var,iVar1);
    }
    return 0xc0190043;
  }
  if ((*(uint *)(param_2 + 0x80) & 2) == 0) {
    if ((*(uint *)(param_2 + 0x80) & 4) == 0) {
      if (((*(uint *)(param_2 + 0x80) & 8) == 0) || ((*(uint *)(param_2 + 0x80) & 1) != 0)) {
        bVar5 = (-((*(uint *)(param_2 + 0x80) & 1) != 0) & 2U) + 2;
      }
      else {
        bVar5 = 3;
      }
    }
    else {
      bVar5 = 1;
    }
  }
  else {
    bVar5 = 0;
  }
  if ((*(uint *)(param_1 + 0x80) & 2) == 0) {
    if ((*(uint *)(param_1 + 0x80) & 4) == 0) {
      if (((*(uint *)(param_1 + 0x80) & 8) == 0) || ((*(uint *)(param_1 + 0x80) & 1) != 0)) {
        bVar7 = (-((*(uint *)(param_1 + 0x80) & 1) != 0) & 2U) + 2;
      }
      else {
        bVar7 = 3;
      }
    }
  }
  else {
    bVar7 = 0;
  }
  if (bVar7 < bVar5) {
    if (*(longlong *)(local_res20 + 0xf0) != 0) {
      return 0xc0190012;
    }
    if (param_3 != param_2) {
      *param_6 = param_2;
      return 0xc000001e;
    }
    plVar8 = param_5;
    uVar2 = TmpEnlistSuperiorSubordinateTm(param_1,param_2,param_5,&local_res20);
    if (-1 < (int)uVar2) {
      ObfReferenceObject(*param_5);
      goto LAB_140021f28;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_140021f28;
    uVar6 = 0xb;
  }
  else {
    plVar8 = &local_res20;
    uVar2 = TmpEnlistSuperiorSubordinateTm(param_2,param_1,plVar8,param_5);
    if (((-1 < (int)uVar2) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) goto LAB_140021f28;
    uVar6 = 10;
  }
  WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,plVar8,uVar2,(char)local_res20);
LAB_140021f28:
  return (ulonglong)uVar2;
}



===== TmpInsertTxTransactionManager @ 140021f48 =====

int TmpInsertTxTransactionManager(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x40) == 5) {
    iVar1 = -0x3fe6ffae;
  }
  else {
    iVar1 = TmpNamespaceInsert(param_1 + 0xb0,param_1,param_2);
    if (-1 < iVar1) {
      *(longlong *)(param_2 + 0x200) = param_1;
      iVar1 = 0;
      if ((*(uint *)(param_1 + 0x80) & 0x10) != 0) {
        LOCK();
        *(uint *)(param_2 + 0xc4) = *(uint *)(param_2 + 0xc4) | 0x10000;
        UNLOCK();
      }
    }
  }
  return iVar1;
}



===== TmpRemoveTransactionEnlistmentCounts @ 140021fb0 =====

void TmpRemoveTransactionEnlistmentCounts(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xa0);
  if ((*(uint *)(param_1 + 0xac) & 2) != 0) {
    *(int *)(lVar1 + 0xdc) = *(int *)(lVar1 + 0xdc) + -1;
  }
  if ((*(uint *)(param_1 + 0xb0) & 2) != 0) {
    *(int *)(lVar1 + 0xe4) = *(int *)(lVar1 + 0xe4) + -1;
  }
  if ((*(uint *)(param_1 + 0xb0) & 1) != 0) {
    *(int *)(lVar1 + 0xe0) = *(int *)(lVar1 + 0xe0) + -1;
  }
  if ((*(uint *)(param_1 + 0xac) & 0x10) != 0) {
    *(int *)(lVar1 + 0xe8) = *(int *)(lVar1 + 0xe8) + -1;
  }
  *(int *)(lVar1 + 0xd8) = *(int *)(lVar1 + 0xd8) + -1;
  return;
}



===== TmpTmOnline @ 140022010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 TmpTmOnline(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (*(int *)(param_1 + 0x40) == 5) {
    uVar1 = 0xc0000001;
  }
  else {
    local_28 = *(undefined8 *)(param_1 + 0x70);
    uStack_20 = *(undefined8 *)(param_1 + 0x78);
    *(undefined4 *)(param_1 + 0x40) = 3;
    local_18 = *(uint *)(param_1 + 0x80) >> 8 & 1;
    TmpNotifyAllCRM(param_1,param_2,&local_28);
    uVar1 = 0;
  }
  return uVar1;
}



===== NtCreateTransactionManager @ 140022090 =====

ulonglong NtCreateTransactionManager
                    (undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4,
                    uint param_5)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined7 uVar8;
  undefined8 *puVar7;
  ulonglong uVar9;
  undefined8 *local_60;
  undefined4 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *puStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
                    /* 0x22090  9  NtCreateTransactionManager */
  local_58 = (undefined4 *)0x0;
  local_50 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  puStack_38 = (undefined8 *)0x0;
  local_60 = (undefined8 *)0x0;
  local_48 = (undefined8 *)0x0;
  uVar6 = 0;
  cVar1 = PsIsComponentEnabled(1);
  if (cVar1 == '\0') {
    return 0xc0000022;
  }
  cVar1 = *(char *)((longlong)SystemReserved1[0xf] + 0x232);
  uVar8 = (undefined7)((ulonglong)uVar6 >> 8);
  if (cVar1 == '\0') {
    local_60 = param_4;
  }
  else {
    puVar7 = *(undefined8 **)MmUserProbeAddress_exref;
    puVar4 = param_1;
    if (puVar7 <= param_1) {
      puVar4 = puVar7;
    }
    *puVar4 = *puVar4;
    if (param_4 != (undefined8 *)0x0) {
      if (*(undefined8 **)MmUserProbeAddress_exref <= param_4) {
        param_4 = *(undefined8 **)MmUserProbeAddress_exref;
      }
      local_40 = CONCAT44(local_40._4_4_,*(undefined4 *)param_4);
      puVar7 = (undefined8 *)param_4[1];
      sVar2 = (short)*(undefined4 *)param_4;
      puStack_38 = puVar7;
      if (sVar2 != 0) {
        local_40._0_4_ = CONCAT22(sVar2,sVar2);
        if (((ulonglong)puVar7 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
          ExRaiseDatatypeMisalignment();
        }
        puVar4 = (undefined8 *)ExAllocatePoolWithQuotaTag(1,sVar2,0x73436d54);
        puVar7 = puVar4;
        local_48 = puVar4;
        memcpy(puVar4,puStack_38,local_40 & 0xffff);
        local_60 = &local_40;
        puStack_38 = puVar4;
      }
    }
    uVar8 = (undefined7)((ulonglong)puVar7 >> 8);
  }
  if ((param_5 < 0x40) && ((cVar1 != '\x01' || ((param_5 & 6) == 0)))) {
    if ((param_5 & 1) == 0) {
      if (local_60 == (undefined8 *)0x0) {
LAB_140022257:
        if ((param_5 & 1) == 0) goto LAB_14002221e;
      }
      uVar3 = ObCreateObject(CONCAT71(uVar8,cVar1),TmTransactionManagerObjectType,param_3,cVar1,0,
                             0x3c0,0,0,&local_58);
      uVar9 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        local_58[0x10] = 0;
        uVar5 = TmInitializeTransactionManager(local_58,local_60,(undefined8 *)0x0,param_5);
        uVar9 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) {
          ObfDereferenceObject();
        }
        else {
          uVar3 = ObInsertObject(local_58,0,param_2,0,0,&local_50);
          uVar9 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            if (cVar1 == '\0') {
              *param_1 = local_50;
            }
            else {
              *param_1 = local_50;
            }
          }
        }
      }
      goto LAB_14002233b;
    }
    if (local_60 == (undefined8 *)0x0) goto LAB_140022257;
  }
LAB_14002221e:
  uVar9 = 0xc000000d;
LAB_14002233b:
  if (local_48 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_48,0);
  }
  return uVar9;
}



===== DllUnload @ 140022370 =====

undefined8 DllUnload(void)

{
                    /* 0x22370  2  DllUnload */
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return 0;
}



===== TmpNamespaceEnumerateObject$fin$0 @ 1400223c9 =====

void TmpNamespaceEnumerateObject_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x40);
  *(undefined8 *)(lVar1 + 0x60) = 0;
  KeReleaseMutex(lVar1 + 0x68,0);
  return;
}



===== TmRecoverResourceManagerExt$fin$0 @ 1400223fb =====

void TmRecoverResourceManagerExt_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(param_2 + 0x60) + 0x28,0);
  return;
}



===== TmpInternalCrmNotification$fin$0 @ 140022428 =====

void TmpInternalCrmNotification_fin_0(void)

{
  return;
}



===== TmpRecover$fin$0 @ 14002243e =====

void TmpRecover_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ZwClose();
    *(undefined8 *)(param_2 + 0x60) = 0;
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ClfsTerminateReadLog();
  }
  ZwClose(*(undefined8 *)(param_2 + 0x80));
  return;
}



===== TmpRegisterForLogManagement$fin$0 @ 140022498 =====

void TmpRegisterForLogManagement_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((*(int *)(param_2 + 0x30) < 0) &&
     (lVar1 = *(longlong *)(param_2 + 0x80), *(longlong *)(lVar1 + 0xa8) != 0)) {
    ClfsMgmtDeregisterManagedClient(*(undefined8 *)(lVar1 + 0xa8));
    *(undefined8 *)(lVar1 + 0xa8) = 0;
  }
  return;
}



===== NtCreateTransactionExt$filt$1 @ 1400224e2 =====

void NtCreateTransactionExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateTransactionExt$filt$0 @ 1400224ff =====

void NtCreateTransactionExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateTransactionExt$fin$2 @ 14002251c =====

void NtCreateTransactionExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x58) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x88) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x88),0);
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== TmpProcessNotificationResponse$fin$0 @ 140022579 =====

void TmpProcessNotificationResponse_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x30) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0x80) + 0x40,0);
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  ObfDereferenceObject(lVar1);
  ObfDereferenceObject(*(undefined8 *)(param_2 + 0x80));
  return;
}



===== TmCommitTransactionExt$fin$0 @ 1400225f1 =====

void TmCommitTransactionExt_fin_0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = *(int *)(param_2 + 0x30);
  if ((iVar1 == 0x103) && (*(char *)(param_2 + 0x68) != '\0')) {
    lVar2 = *(longlong *)(param_2 + 0x60);
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0x60);
    *(undefined4 *)(lVar2 + 0x210 + (ulonglong)(*(uint *)(lVar2 + 0x260) % 10) * 8) = 1;
    *(int *)(lVar2 + 0x214 + (ulonglong)(*(uint *)(lVar2 + 0x260) % 10) * 8) = iVar1;
    *(int *)(lVar2 + 0x260) = *(int *)(lVar2 + 0x260) + 1;
  }
  KeReleaseMutex(*(longlong *)(lVar2 + 0x58) + 0x20,0);
  return;
}



===== NtQueryInformationTransactionExt$filt$0 @ 14002268f =====

void NtQueryInformationTransactionExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$7 @ 1400226ac =====

void NtQueryInformationTransactionExt_filt_7(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$6 @ 1400226c9 =====

void NtQueryInformationTransactionExt_filt_6(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$5 @ 1400226e6 =====

void NtQueryInformationTransactionExt_filt_5(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$4 @ 140022703 =====

void NtQueryInformationTransactionExt_filt_4(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$3 @ 140022720 =====

void NtQueryInformationTransactionExt_filt_3(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$2 @ 14002273d =====

void NtQueryInformationTransactionExt_filt_2(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$filt$1 @ 14002275a =====

void NtQueryInformationTransactionExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionExt$fin$9 @ 140022777 =====

void NtQueryInformationTransactionExt_fin_9(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x168) != 0) {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x38) + 0x58) + 0x20,0);
  }
  ObfDereferenceObject(*(undefined8 *)(param_2 + 0x38));
  return;
}



===== NtQueryInformationTransactionExt$filt$8 @ 1400227bc =====

void NtQueryInformationTransactionExt_filt_8(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateEnlistmentExt$filt$0 @ 1400227df =====

void NtCreateEnlistmentExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmCreateEnlistmentExt$filt$0 @ 140022802 =====

void TmCreateEnlistmentExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmRecoverTransactionManagerExt$fin$0 @ 140022825 =====

void TmRecoverTransactionManagerExt_fin_0
               (longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(param_2 + 0x60);
  if ((*(int *)(lVar2 + 0x40) == 2) && (iVar1 = *(int *)(param_2 + 0x34), iVar1 < 0)) {
    *(undefined4 *)(lVar2 + 0x40) = 4;
    *(int *)(lVar2 + 0x380) = iVar1;
  }
  lVar3 = param_2;
  if (*(char *)(param_2 + 0x31) != '\0') {
    *(undefined1 *)(param_2 + 0x31) = 0;
    param_1 = lVar2;
    TmpReleaseTxTableTransactionManager(lVar2);
  }
  TmpPromptRecoveryAllTransactionManagers(param_1,lVar3,param_3,param_4);
  if (*(char *)(param_2 + 0x30) != '\0') {
    TmpNamespaceForEach(lVar2 + 0xb0,(undefined *)0x0,TmpHeuristicAbortTransaction);
  }
  return;
}



===== TmpRmDisconnectTransaction$fin$0 @ 140022892 =====

void TmpRmDisconnectTransaction_fin_0(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  
  if (*(char *)(param_2 + 0x20) != '\0') {
    LOCK();
    puVar1 = (uint *)(*(longlong *)(param_2 + 0x40) + 0xc4);
    *puVar1 = *puVar1 & 0xffffff7f;
    UNLOCK();
  }
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58) + 0x20,0);
  return;
}



===== TmFreezeTransactionsExt$fin$0 @ 1400228d8 =====

void TmFreezeTransactionsExt_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(char *)(param_2 + 0x40) != '\0') && (*(int *)(param_2 + 0x44) != 0)) {
    TmThawTransactions();
    *(undefined1 *)(param_2 + 0x40) = 0;
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    KeReleaseMutex(&TmpFreezeMutex,0);
    *(undefined1 *)(param_2 + 0x41) = 0;
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x48),0);
  }
  return;
}



===== TmpNamespaceRename$fin$0 @ 14002293a =====

void TmpNamespaceRename_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(param_2 + 0x70) + 0x68,0);
  return;
}



===== TmpCreateOrOpenLogTransactionManager$fin$0 @ 140022967 =====

void TmpCreateOrOpenLogTransactionManager_fin_0(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(*(longlong *)(param_2 + 0x40) + 0x40) == 2) && (*(int *)(param_2 + 0x20) < 0)) {
    *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x40) = 4;
  }
  return;
}



===== TmpCreateLogFile$fin$0 @ 140022994 =====

ulonglong TmpCreateLogFile_fin_0(byte param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_1;
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
    *(undefined8 *)(param_2 + 0x70) = 0;
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ClfsTerminateReadLog();
  }
  if (param_1 != 0) {
    uVar2 = (ulonglong)*(uint *)(param_2 + 0x60);
    if (-1 < (int)*(uint *)(param_2 + 0x60)) {
      uVar2 = 0xc0000001;
    }
    *(int *)(param_2 + 0x60) = (int)uVar2;
  }
  if (*(int *)(param_2 + 0x60) < 0) {
    lVar1 = *(longlong *)(param_2 + 200);
    if (*(longlong *)(lVar1 + 0xa8) != 0) {
      uVar2 = *(ulonglong *)(lVar1 + 0xa8);
      *(ulonglong *)(param_2 + 0x80) = uVar2;
      *(undefined8 *)(lVar1 + 0xa8) = 0;
    }
    if (*(longlong *)(lVar1 + 0xa0) != 0) {
      uVar2 = ClfsDeleteMarshallingArea(*(undefined8 *)(lVar1 + 0xa0));
      *(undefined8 *)(lVar1 + 0xa0) = 0;
    }
    if (*(longlong *)(lVar1 + 0x98) != 0) {
      uVar2 = ClfsCloseLogFileObject(*(undefined8 *)(lVar1 + 0x98));
      *(undefined8 *)(lVar1 + 0x98) = 0;
    }
    if (*(longlong *)(param_2 + 0x80) != 0) {
      uVar2 = ClfsMgmtDeregisterManagedClient();
    }
  }
  return uVar2;
}



===== NtQueryInformationTransactionManagerExt$filt$0 @ 140022a8b =====

void NtQueryInformationTransactionManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$5 @ 140022aa8 =====

void NtQueryInformationTransactionManagerExt_filt_5(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$3 @ 140022ac5 =====

void NtQueryInformationTransactionManagerExt_filt_3(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$4 @ 140022ae2 =====

void NtQueryInformationTransactionManagerExt_filt_4(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$2 @ 140022aff =====

void NtQueryInformationTransactionManagerExt_filt_2(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$1 @ 140022b1c =====

void NtQueryInformationTransactionManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationTransactionManagerExt$fin$7 @ 140022b39 =====

void NtQueryInformationTransactionManagerExt_fin_7(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0x68) + 8,0);
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_2 + 0x68) = 0;
  }
  return;
}



===== NtQueryInformationTransactionManagerExt$filt$6 @ 140022b83 =====

void NtQueryInformationTransactionManagerExt_filt_6(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpCheckpoint$fin$0 @ 140022ba6 =====

void TmpCheckpoint_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x50) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0x90) + 8,0);
    *(undefined1 *)(param_2 + 0x50) = 0;
  }
  if (*(char *)(param_2 + 0x51) != '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0x90) + 0x310);
    *(undefined1 *)(param_2 + 0x51) = 0;
  }
  KeLeaveCriticalRegion();
  return;
}



===== TmpExtractTmIdentityFromExistingLogFile$fin$0 @ 140022c10 =====

void TmpExtractTmIdentityFromExistingLogFile_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ClfsTerminateReadLog();
  }
  if (*(longlong *)(param_2 + 0xd8) != 0) {
    ClfsDeleteMarshallingArea();
  }
  ClfsCloseLogFileObject(*(undefined8 *)(param_2 + 0x68));
  return;
}



===== TmpLogTransaction$fin$0 @ 140022c66 =====

void TmpLogTransaction_fin_0(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  uVar1 = *(uint *)(param_2 + 0x68);
  if (uVar1 != 0) {
    plVar3 = *(longlong **)(param_2 + 0xb8);
    do {
      if (*plVar3 != 0) {
        ObReleaseObjectSecurity(*plVar3,*(undefined1 *)((longlong)plVar3 + 0xc));
      }
      uVar4 = uVar4 + 1;
      plVar3 = plVar3 + 2;
    } while (uVar4 < uVar1);
    *(uint *)(param_2 + 0x6c) = uVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0x90);
  if (lVar2 != 0) {
    if (*(char *)(param_2 + 0x54) == '\0') {
      ExFreePoolWithTag(lVar2,0);
    }
    else {
      ExFreeToPagedLookasideList(&TmpLogWriteLookasideList,lVar2);
    }
  }
  return;
}



===== TmpWriteLog$fin$0 @ 140022cf9 =====

void TmpWriteLog_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x50) != '\0') {
    ExReleaseResourceLite(*(longlong *)(param_2 + 0xe0) + 0x310);
    *(undefined1 *)(param_2 + 0x50) = 0;
  }
  KeLeaveCriticalRegion();
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x60),0);
  }
  return;
}



===== TmCommitEnlistmentExt$fin$0 @ 140022d57 =====

void TmCommitEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x58);
  KeReleaseMutex(*(longlong *)(lVar1 + 0x58) + 0x20,0);
  ObfDereferenceObject(lVar1);
  return;
}



===== TmPrePrepareEnlistmentExt$fin$0 @ 140022d99 =====

void TmPrePrepareEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x58) + 0x20,0);
  return;
}



===== TmPrepareEnlistmentExt$fin$0 @ 140022dca =====

void TmPrepareEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x30) + 0x58) + 0x20,0);
  return;
}



===== TmRecoverEnlistmentExt$fin$0 @ 140022dfb =====

void TmRecoverEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x40) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0x70) + 0x40,0);
    *(undefined1 *)(param_2 + 0x40) = 0;
  }
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x88) + 0x58) + 0x20,0);
  return;
}



===== TmRequestOutcomeEnlistmentExt$fin$0 @ 140022e4f =====

void TmRequestOutcomeEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(param_2 + 0x70) + 0x40,0);
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x78) + 0x58) + 0x20,0);
  return;
}



===== TmRollbackEnlistmentExt$fin$0 @ 140022e96 =====

void TmRollbackEnlistmentExt_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x31) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0x60) + 0x40,0);
  }
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x68) + 0x58) + 0x20,0);
  return;
}



===== TmpInitializeEnlistment$fin$0 @ 140022ee4 =====

void TmpInitializeEnlistment_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x50);
  if (lVar1 != 0) {
    TmpReleaseTxTableTransactionManager(lVar1);
    ObfDereferenceObject(lVar1);
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  if (*(char *)(param_2 + 0x30) != '\0') {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0xb0) + 0x58) + 0x20,0);
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  if (*(char *)(param_2 + 0x31) != '\0') {
    KeReleaseMutex(*(longlong *)(param_2 + 0xa8) + 0x28,0);
    *(undefined1 *)(param_2 + 0x31) = 0;
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_2 + 0x48) = 0;
  }
  return;
}



===== TmRollbackTransactionExt$fin$0 @ 140022f85 =====

void TmRollbackTransactionExt_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x50) + 0x58) + 0x20,0);
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  return;
}



===== TmThawTransactionsExt$fin$0 @ 140022fbf =====

void TmThawTransactionsExt_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x30) != '\0') {
    KeReleaseMutex(&TmpFreezeMutex,0);
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  return;
}



===== TmpForwardCommitTransaction$fin$0 @ 140022ff4 =====

void TmpForwardCommitTransaction_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x60) + 0x58) + 0x20,0);
  return;
}



===== TmpPromoteTransaction$fin$0 @ 140023025 =====

void TmpPromoteTransaction_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x34) < 0) {
    if (*(char *)(param_2 + 0x30) != '\0') {
      ObfDereferenceObject(*(undefined8 *)(param_2 + 0x60));
      *(undefined1 *)(param_2 + 0x30) = 0;
    }
    if (*(char *)(param_2 + 0x31) != '\0') {
      ObfDereferenceObject(*(undefined8 *)(param_2 + 0x78));
      *(undefined1 *)(param_2 + 0x31) = 0;
    }
    if (*(longlong *)(param_2 + 0x78) != 0) {
      *(undefined8 *)(*(longlong *)(param_2 + 0x78) + 0x2b0) = 0;
    }
    if (*(longlong *)(param_2 + 0x38) != 0) {
      ZwClose();
    }
  }
  if (*(char *)(param_2 + 0x32) != '\0') {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x60) + 0x58) + 0x20,0);
    *(undefined1 *)(param_2 + 0x32) = 0;
  }
  if (*(char *)(param_2 + 0x33) != '\0') {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x78) + 0x58) + 0x20,0);
    *(undefined1 *)(param_2 + 0x33) = 0;
  }
  return;
}



===== TmpSetTransactionProperties$fin$0 @ 1400230e4 =====

void TmpSetTransactionProperties_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_2 + 0x24) < 0) {
    if (*(char *)(param_2 + 0x20) != '\0') {
      if (*(longlong *)(*(longlong *)(param_2 + 0x70) + 0x138) != 0) {
        RtlFreeUnicodeString(*(longlong *)(param_2 + 0x70) + 0x130);
      }
      uVar2 = *(undefined8 *)(param_2 + 0x30);
      lVar1 = *(longlong *)(param_2 + 0x70);
      *(undefined8 *)(lVar1 + 0x130) = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(lVar1 + 0x138) = uVar2;
    }
  }
  else if ((*(char *)(param_2 + 0x20) != '\0') && (*(longlong *)(param_2 + 0x30) != 0)) {
    RtlFreeUnicodeString(param_2 + 0x28);
  }
  if (*(char *)(param_2 + 0x21) != '\0') {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x70) + 0x58) + 0x20,0);
    *(undefined1 *)(param_2 + 0x21) = 0;
  }
  return;
}



===== TmpTxActionDoCommit$fin$0 @ 14002317c =====

void TmpTxActionDoCommit_fin_0(void)

{
  return;
}



===== TmpCaptureOrRequeueNotification$filt$0 @ 140023192 =====

void TmpCaptureOrRequeueNotification_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpCaptureOrRequeueNotification$filt$1 @ 1400231af =====

void TmpCaptureOrRequeueNotification_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpCaptureOrRequeueNotification$fin$2 @ 1400231cc =====

void TmpCaptureOrRequeueNotification_fin_2(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(int *)(param_2 + 0x20) < 0) {
    lVar1 = *(longlong *)(param_2 + 0x50);
    KeInsertHeadQueue(lVar1 + 0x98,*(undefined8 *)(param_2 + 0x60));
    KeSetEvent(lVar1,0,0);
  }
  return;
}



===== TmpCompleteNotificationRequestPacket$filt$0 @ 14002321a =====

void TmpCompleteNotificationRequestPacket_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenEnlistmentExt$filt$0 @ 14002323d =====

void NtOpenEnlistmentExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenEnlistmentExt$filt$1 @ 14002325a =====

void NtOpenEnlistmentExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenEnlistmentExt$fin$2 @ 140023277 =====

void NtOpenEnlistmentExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== NtPrePrepareCompleteExt$filt$0 @ 1400232b9 =====

void NtPrePrepareCompleteExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationEnlistmentExt$filt$0 @ 1400232dc =====

void NtQueryInformationEnlistmentExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationEnlistmentExt$filt$3 @ 1400232f9 =====

void NtQueryInformationEnlistmentExt_filt_3(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationEnlistmentExt$filt$1 @ 140023316 =====

void NtQueryInformationEnlistmentExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationEnlistmentExt$filt$2 @ 140023333 =====

void NtQueryInformationEnlistmentExt_filt_2(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtSetInformationEnlistmentExt$filt$0 @ 140023356 =====

void NtSetInformationEnlistmentExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtSetInformationEnlistmentExt$filt$1 @ 140023373 =====

void NtSetInformationEnlistmentExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtSetInformationEnlistmentExt$fin$2 @ 140023390 =====

void NtSetInformationEnlistmentExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x34) != 0) {
    KeReleaseMutex(*(longlong *)(*(longlong *)(param_2 + 0x50) + 0x58) + 0x20,0);
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    KeReleaseMutex(*(longlong *)(param_2 + 0x40) + 0x40,0);
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== NtCreateResourceManagerExt$filt$0 @ 1400233fa =====

void NtCreateResourceManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateResourceManagerExt$filt$1 @ 140023417 =====

void NtCreateResourceManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateResourceManagerExt$fin$2 @ 140023434 =====

void NtCreateResourceManagerExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0x50) != '\0') {
    ObfDereferenceObject(*(undefined8 *)(param_2 + 0x60));
  }
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
  }
  return;
}



===== NtOpenResourceManagerExt$filt$0 @ 14002348f =====

void NtOpenResourceManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenResourceManagerExt$filt$1 @ 1400234ac =====

void NtOpenResourceManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenResourceManagerExt$fin$2 @ 1400234c9 =====

void NtOpenResourceManagerExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== NtQueryInformationResourceManagerExt$filt$0 @ 14002350b =====

void NtQueryInformationResourceManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationResourceManagerExt$filt$2 @ 140023528 =====

void NtQueryInformationResourceManagerExt_filt_2(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationResourceManagerExt$filt$1 @ 140023545 =====

void NtQueryInformationResourceManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtQueryInformationResourceManagerExt$fin$4 @ 140023562 =====

void NtQueryInformationResourceManagerExt_fin_4(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  KeReleaseMutex(lVar1 + 0x28,0);
  ObfDereferenceObject(lVar1);
  return;
}



===== NtQueryInformationResourceManagerExt$filt$3 @ 14002359a =====

void NtQueryInformationResourceManagerExt_filt_3(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtSetInformationResourceManagerExt$filt$0 @ 1400235bd =====

void NtSetInformationResourceManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtSetInformationResourceManagerExt$fin$1 @ 1400235da =====

void NtSetInformationResourceManagerExt_fin_1(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x50);
  KeReleaseMutex(lVar1 + 0x28,0);
  ObfDereferenceObject(lVar1);
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
  }
  return;
}



===== TmRenameTransactionManagerExt$fin$0 @ 14002362f =====

void TmRenameTransactionManagerExt_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ClfsTerminateReadLog();
  }
  if (*(longlong *)(param_2 + 0xd8) != 0) {
    ClfsDeleteMarshallingArea();
  }
  ClfsCloseLogFileObject(*(undefined8 *)(param_2 + 0x68));
  return;
}



===== TmpCreateInternalCrmEnlistment$fin$0 @ 140023685 =====

void TmpCreateInternalCrmEnlistment_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ZwClose();
  }
  if (*(int *)(param_2 + 0x40) < 0) {
    plVar1 = *(longlong **)(param_2 + 0xe0);
    if (*plVar1 != 0) {
      ObfDereferenceObject(*plVar1);
      *plVar1 = 0;
    }
    plVar1 = *(longlong **)(param_2 + 0xe8);
    if (*plVar1 != 0) {
      ZwClose(*plVar1);
      *plVar1 = 0;
    }
  }
  return;
}



===== TmpCreateInternalCrmTransaction$fin$0 @ 1400236f9 =====

void TmpCreateInternalCrmTransaction_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x68) != 0) {
    ObReleaseObjectSecurity(*(longlong *)(param_2 + 0x68),*(undefined1 *)(param_2 + 0x50));
  }
  if (*(longlong *)(param_2 + 0x60) != 0) {
    ZwClose();
    *(undefined8 *)(param_2 + 0x60) = 0;
  }
  if (*(int *)(param_2 + 0x54) < 0) {
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ZwClose();
      *(undefined8 *)(param_2 + 0x58) = 0;
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_2 + 0x70) = 0;
    }
  }
  return;
}



===== TmpEnlistSuperiorSubordinateTm$fin$0 @ 14002377c =====

void TmpEnlistSuperiorSubordinateTm_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(int *)(param_2 + 0x40) < 0) {
    if (*(longlong *)(param_2 + 0x60) != 0) {
      ObfDereferenceObject();
    }
    if (*(longlong *)(param_2 + 0x48) != 0) {
      ObfDereferenceObject();
    }
    if (*(longlong *)(param_2 + 0x50) != 0) {
      ZwClose();
    }
    if (*(longlong *)(param_2 + 0x68) != 0) {
      ObfDereferenceObject();
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      ZwClose();
    }
    if (*(longlong *)(param_2 + 0x58) != 0) {
      ZwClose();
    }
  }
  return;
}



===== NtEnumerateTransactionObjectExt$filt$0 @ 140023820 =====

void NtEnumerateTransactionObjectExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtEnumerateTransactionObjectExt$filt$1 @ 14002383d =====

void NtEnumerateTransactionObjectExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtFreezeTransactionsExt$filt$0 @ 140023860 =====

void NtFreezeTransactionsExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenTransactionExt$filt$0 @ 140023883 =====

void NtOpenTransactionExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenTransactionExt$filt$1 @ 1400238a0 =====

void NtOpenTransactionExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenTransactionExt$fin$2 @ 1400238bd =====

void NtOpenTransactionExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== NtCreateTransactionManagerExt$filt$0 @ 1400238ff =====

void NtCreateTransactionManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateTransactionManagerExt$filt$1 @ 14002391c =====

void NtCreateTransactionManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtCreateTransactionManagerExt$fin$2 @ 140023939 =====

void NtCreateTransactionManagerExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
  }
  return;
}



===== NtOpenTransactionManagerExt$filt$0 @ 140023967 =====

void NtOpenTransactionManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenTransactionManagerExt$filt$1 @ 140023984 =====

void NtOpenTransactionManagerExt_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtOpenTransactionManagerExt$fin$2 @ 1400239a1 =====

void NtOpenTransactionManagerExt_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
  }
  return;
}



===== NtRenameTransactionManagerExt$filt$0 @ 1400239cf =====

void NtRenameTransactionManagerExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtRenameTransactionManagerExt$fin$1 @ 1400239ec =====

void NtRenameTransactionManagerExt_fin_1(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
  }
  return;
}



===== NtRegisterProtocolAddressInformationExt$filt$0 @ 140023a1a =====

void NtRegisterProtocolAddressInformationExt_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== NtRegisterProtocolAddressInformationExt$fin$1 @ 140023a37 =====

void NtRegisterProtocolAddressInformationExt_fin_1(undefined8 param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x54) < 0) && (*(longlong *)(param_2 + 0x60) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x60),0);
  }
  return;
}



===== TmRegisterProtocolAddressInformation$fin$0 @ 140023a6b =====

void TmRegisterProtocolAddressInformation_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseMutex(&TmpAllProtocolsListMutex,0);
  KeReleaseMutex(*(longlong *)(param_2 + 0x80) + 0x28,0);
  if (((*(int *)(param_2 + 0x34) < 0) && (*(char *)(param_2 + 0x30) != '\0')) &&
     (*(longlong *)(param_2 + 0x38) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
  }
  return;
}



===== TmpAllocateAndDispatchPropagateRequest$fin$0 @ 140023ad3 =====

void TmpAllocateAndDispatchPropagateRequest_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x48),0);
  }
  return;
}



===== TmpAllocatePropagateRequest$fin$0 @ 140023b01 =====

void TmpAllocatePropagateRequest_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    lVar1 = *(longlong *)(param_2 + 0x38);
    if (lVar1 != 0) {
      if (*(longlong *)(lVar1 + 0x158) != 0) {
        ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x158),0);
        *(undefined8 *)(lVar1 + 0x158) = 0;
      }
      if (*(longlong *)(lVar1 + 0x168) != 0) {
        ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x168),0);
        *(undefined8 *)(lVar1 + 0x168) = 0;
      }
      if (*(longlong *)(lVar1 + 0x40) != 0) {
        ObfDereferenceObject(*(undefined8 *)(lVar1 + 0x40));
        *(undefined8 *)(lVar1 + 0x40) = 0;
      }
      ExFreePoolWithTag(lVar1,0);
    }
  }
  else {
    **(undefined8 **)(param_2 + 0x80) = *(undefined8 *)(param_2 + 0x38);
  }
  return;
}



===== TmpPropagationComplete$filt$0 @ 140023bb7 =====

void TmpPropagationComplete_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpPropagationComplete$fin$1 @ 140023bd4 =====

void TmpPropagationComplete_fin_1(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((*(int *)(param_2 + 0x34) < 0) && (*(char *)(param_2 + 0x30) == '\0')) {
    lVar1 = *(longlong *)(param_2 + 0x80);
    if (*(longlong *)(lVar1 + 0x178) != 0) {
      ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x178));
      *(undefined8 *)(lVar1 + 0x178) = 0;
    }
    *(undefined4 *)(lVar1 + 0x170) = 0;
    TmpPropagationComplete(lVar1,0,(void *)0x0,*(int *)(param_2 + 0x34));
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x80);
  }
  if (*(char *)(param_2 + 0x31) != '\0') {
    KeReleaseMutex(lVar1 + 0x70,0);
    *(undefined1 *)(param_2 + 0x31) = 0;
  }
  TmpDereferencePropagateRequest(lVar1);
  return;
}



===== TmpNamespaceEnumerate$filt$0 @ 140023c6c =====

void TmpNamespaceEnumerate_filt_0(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpNamespaceEnumerate$filt$1 @ 140023c89 =====

void TmpNamespaceEnumerate_filt_1(void)

{
  ExSystemExceptionFilter();
  return;
}



===== TmpNamespaceEnumerate$fin$2 @ 140023ca6 =====

void TmpNamespaceEnumerate_fin_2(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0xb0);
  *(undefined8 *)(lVar1 + 0x60) = 0;
  KeReleaseMutex(lVar1 + 0x68,0);
  return;
}



===== entry @ 140025010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140025044 =====

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



===== TmInitSystem @ 140025080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TmInitSystem(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  byte bVar10;
  byte bVar11;
  
                    /* 0x25080  54  TmInitSystem */
  if ((((param_1 == (undefined8 *)0x0) || (param_2 == (undefined8 *)0x0)) ||
      (param_3 == (undefined8 *)0x0)) || (param_4 == (undefined8 *)0x0)) {
    uVar5 = 0xc000000d;
  }
  else {
    uVar6 = TmpTransactionManagerInitialization();
    bVar1 = TmpTransactionInitialization();
    bVar2 = TmpResourceManagerInitialization();
    bVar3 = TmpEnlistmentInitialization();
    uVar7 = TmpLogBufferInitialization();
    KeInitializeMutex(&TmpAllProtocolsListMutex,0);
    _TmpAllProtocolsListCount = 0;
    DAT_140008348 = &TmpAllProtocolsList;
    TmpAllProtocolsList = &TmpAllProtocolsList;
    KeInitializeMutex(&TmpAllPropReqsListMutex,0);
    DAT_1400083a8 = &TmpAllPropReqsList;
    _TmpAllPropReqsList = &TmpAllPropReqsList;
    KeInitializeMutex(&TmpAllCRMListMutex,0);
    _TmpAllCRMListCount = 0;
    DAT_140008408 = &TmpAllCRMList;
    TmpAllCRMList = &TmpAllCRMList;
    uVar8 = TmpNamespaceInitialize(0x1400084e0,0x48,0x70);
    uVar9 = TmpNamespaceInitialize(0x140008420,0x60,0xb0);
    KeInitializeEvent(&TmpTransactionFreezeCompleteEvent,0,0);
    KeInitializeEvent(&TmpTransactionThawEvent,0,0);
    KeInitializeMutex(&TmpFreezeMutex,0);
    KeInitializeEvent(&TmpTransactionFreezeCancelEvent,0,0);
    KeInitializeTimer(&TmpTransactionThawTimer);
    KeInitializeDpc(&TmpTransactionThawDpc,TmpTransactionThawDpcRoutine,0);
    bVar4 = TmpInitializeKtmRmSecurityDescriptor();
    TmpShutdownOccurred = 0;
    *param_1 = TmResourceManagerObjectType;
    *param_2 = TmEnlistmentObjectType;
    *param_3 = TmTransactionManagerObjectType;
    *param_4 = TmTransactionObjectType;
    bVar10 = 0;
    if (-1 < (int)uVar8) {
      bVar10 = -((char)uVar7 != '\0') & -bVar3 & -bVar2 & -bVar1 & (char)uVar6 != '\0';
    }
    bVar11 = 0;
    if (-1 < (int)uVar9) {
      bVar11 = bVar10;
    }
    uVar5 = ~-(uint)((-bVar4 & bVar11) != 0) & 0xc0000001;
  }
  return uVar5;
}



===== TmpQueryValueKey @ 1400252f0 =====

ulonglong TmpQueryValueKey(undefined8 param_1,longlong param_2,int *param_3,longlong *param_4,
                          char *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 local_res8 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_68 = 0;
  local_res8[0] = 0;
  local_44 = 0;
  local_58 = 0;
  local_60 = 0x30;
  local_40 = 0;
  uStack_38 = 0;
  local_48 = 0x240;
  local_50 = param_1;
  uVar2 = ZwOpenKey(&local_68,0x20019,&local_60);
  if (-1 < (int)uVar2) {
    if (param_2 == 0) {
      ZwClose(local_68);
      uVar2 = 0;
    }
    else {
      iVar4 = *param_3;
      while( true ) {
        uVar1 = ZwQueryValueKey(local_68,param_2,1,*param_4,iVar4,local_res8);
        uVar2 = (ulonglong)uVar1;
        if (uVar1 != 0x80000005) break;
        if (*param_5 != '\0') {
          ExFreePoolWithTag(*param_4,0);
          *param_3 = 0;
          *param_4 = 0;
          *param_5 = '\0';
        }
        iVar4 = iVar4 + 0x100;
        lVar3 = ExAllocatePoolWithQuotaTag(9,iVar4,0x78706d54);
        if (lVar3 == 0) {
          return 0xc0000017;
        }
        *param_4 = lVar3;
        *param_3 = iVar4;
        *param_5 = '\x01';
      }
      ZwClose(local_68);
      if ((-1 < (int)uVar1) && (*(int *)(*param_4 + 0xc) == 0)) {
        uVar2 = 0xc0000034;
      }
    }
  }
  return uVar2;
}



===== TmpEnlistmentInitialization @ 14002545c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool TmpEnlistmentInitialization(void)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined2 local_98;
  byte local_96;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  code *local_58;
  code *local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = 0;
  uStack_a0 = 0;
  RtlInitUnicodeString(&local_a8);
  memset(&local_98,0,0x78);
  local_96 = local_96 | 8;
  local_58 = TmpCloseEnlistment;
  local_98 = 0x78;
  local_50 = TmpDeleteEnlistment;
  local_90 = 0x100;
  local_74 = 0x200;
  local_8c = 0x20001;
  uStack_88 = 0x2001e;
  uStack_84 = 0x2001c;
  uStack_80 = 0xf001f;
  local_6c = 0x18;
  local_7c = 0xf001f;
  iVar1 = ObCreateObjectType(&local_a8,&local_98,0,&TmEnlistmentObjectType);
  return -1 < iVar1;
}



===== TmpResourceManagerInitialization @ 14002553c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool TmpResourceManagerInitialization(void)

{
  int iVar1;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined2 local_98;
  byte local_96;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  code *local_60;
  code *local_58;
  code *local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = 0;
  uStack_a0 = 0;
  RtlInitUnicodeString(&local_a8);
  memset(&local_98,0,0x78);
  local_96 = local_96 | 0x18;
  local_60 = TmpOpenResourceManager;
  local_98 = 0x78;
  local_58 = TmpCloseResourceManager;
  local_90 = 0x100;
  local_50 = TmpDeleteResourceManager;
  local_74 = 0x200;
  local_8c = 0x120001;
  uStack_88 = 0x12007e;
  uStack_84 = 0x12005c;
  uStack_80 = 0x1f007f;
  local_6c = 0x18;
  local_7c = 0x1f007f;
  iVar1 = ObCreateObjectType(&local_a8,&local_98,0,&TmResourceManagerObjectType);
  return -1 < iVar1;
}



===== TmpTransactionInitialization @ 140025628 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool TmpTransactionInitialization(void)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined2 local_98;
  byte local_96;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  code *local_58;
  code *local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = 0;
  uStack_a0 = 0;
  RtlInitUnicodeString(&local_a8,L"TmTx");
  _DAT_140008228 = 0;
  iVar1 = RtlDuplicateUnicodeString(0,&local_a8,&TmpTransactionTypeName);
  if (iVar1 < 0) {
    bVar2 = false;
  }
  else {
    memset(&local_98,0,0x78);
    local_96 = local_96 | 8;
    local_58 = TmpCloseTransaction;
    local_98 = 0x78;
    local_50 = TmpDeleteTransaction;
    local_90 = 0x100;
    local_74 = 0x200;
    local_8c = 0x120001;
    uStack_88 = 0x12003e;
    uStack_84 = 0x120018;
    uStack_80 = 0x1f007f;
    local_6c = 0x2d8;
    local_7c = 0x1f007f;
    iVar1 = ObCreateObjectType(&TmpTransactionTypeName,&local_98,0,&TmTransactionObjectType);
    bVar2 = -1 < iVar1;
  }
  return bVar2;
}



===== TmpTransactionManagerInitialization @ 140025738 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TmpTransactionManagerInitialization(void)

{
  ulonglong uVar1;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined2 local_98;
  undefined1 local_96;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  code *local_60;
  code *local_58;
  code *local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8 = 0;
  uStack_a0 = 0;
  RtlInitUnicodeString(&local_a8);
  memset(&local_98,0,0x78);
  local_96 = 10;
  local_60 = TmpOpenTransactionManager;
  local_98 = 0x78;
  local_58 = TmpCloseTransactionManager;
  local_90 = 0x100;
  local_50 = TmpDeleteTransactionManager;
  local_74 = 0x200;
  local_8c = 0x20001;
  uStack_88 = 0x2001e;
  uStack_84 = 0x20000;
  uStack_80 = 0xf003f;
  local_6c = 0x3c0;
  local_7c = 0xf003f;
  uVar1 = ObCreateObjectType(&local_a8,&local_98,0,&TmTransactionManagerObjectType);
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = uVar1 >> 0x1f & 1 ^ 1;
  }
  return uVar1;
}



===== TmpInitializeKtmRmSecurityDescriptor @ 14002582c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool TmpInitializeKtmRmSecurityDescriptor(void)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  ushort uVar7;
  short sVar8;
  undefined1 auStack_c8 [32];
  longlong local_a8;
  undefined *local_a0;
  undefined4 local_98;
  int local_88;
  longlong local_80;
  undefined1 *local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined2 local_3c;
  undefined4 local_38 [6];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_c8;
  local_38[0] = 0x50;
  local_38[1] = 0xa7fcb950;
  local_38[2] = 0xc9e28599;
  local_38[3] = 0xee712ad6;
  local_38[4] = 0x1470a9d4;
  local_38[5] = 0x83b0ffb;
  lVar4 = 0;
  local_70 = 0;
  puVar6 = (undefined1 *)0x0;
  local_78 = (undefined1 *)0x0;
  local_40 = 0;
  local_3c = 0x500;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  local_80 = 0;
  lVar3 = ExAllocatePoolWithTag(1,0x20,0x63536d54);
  local_80 = lVar3;
  if (lVar3 != 0) {
    SeCaptureSubjectContext(lVar3);
    uVar1 = RtlLengthRequiredSid(6);
    lVar4 = ExAllocatePoolWithTag(1,uVar1,0x73526d54);
    local_70 = lVar4;
    if (lVar4 != 0) {
      iVar2 = RtlInitializeSid(lVar4,&local_40,6);
      local_88 = iVar2;
      if (iVar2 < 0) goto LAB_140025aad;
      for (uVar7 = 0; uVar7 < 6; uVar7 = uVar7 + 1) {
        puVar5 = (undefined4 *)RtlSubAuthoritySid(lVar4,uVar7);
        *puVar5 = local_38[uVar7];
      }
      sVar8 = (*(byte *)(lVar4 + 1) + 7) * 4;
      puVar6 = (undefined1 *)ExAllocatePoolWithTag(1,sVar8,0x644e6d54);
      local_78 = puVar6;
      if (puVar6 != (undefined1 *)0x0) {
        iVar2 = RtlCreateAcl(puVar6,sVar8,2);
        local_88 = iVar2;
        if (-1 < iVar2) {
          iVar2 = RtlAddAccessAllowedAce(puVar6,*puVar6,0x1f007f,lVar4);
          local_88 = iVar2;
          if (-1 < iVar2) {
            iVar2 = RtlCreateSecurityDescriptor(&local_68,1);
            local_88 = iVar2;
            if (-1 < iVar2) {
              iVar2 = RtlSetDaclSecurityDescriptor(&local_68,1,puVar6,0);
              local_88 = iVar2;
              if (-1 < iVar2) {
                local_98 = 1;
                local_a0 = &TmpResourceManagerMapping;
                local_a8 = lVar3;
                iVar2 = SeAssignSecurity(0,&local_68,&TmpKtmRmDescriptor,0);
                local_88 = iVar2;
                if (-1 < iVar2) {
                  RtlLengthSecurityDescriptor(TmpKtmRmDescriptor);
                }
              }
            }
          }
        }
        goto LAB_140025aad;
      }
    }
  }
  iVar2 = -0x3fffff66;
  local_88 = -0x3fffff66;
LAB_140025aad:
  if (lVar3 != 0) {
    SeReleaseSubjectContext(lVar3);
    ExFreePoolWithTag(lVar3,0);
  }
  if (puVar6 != (undefined1 *)0x0) {
    ExFreePoolWithTag(puVar6,0);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return -1 < iVar2;
}



===== DriverEntry @ 140025b3c =====

undefined8 DriverEntry(void)

{
  return 0xc0000001;
}



===== wil_InitializeFeatureStaging @ 140025b4c =====

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
    plVar3 = (longlong *)&wil_details_featureDescriptors_z;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140025c3c =====

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
  plVar3 = (longlong *)&wil_details_featureDescriptors_z;
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



===== TmpInitializeKtmRmSecurityDescriptor$fin$0 @ 140025d24 =====

void TmpInitializeKtmRmSecurityDescriptor_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x48);
  if (lVar1 != 0) {
    SeReleaseSubjectContext(lVar1);
    ExFreePoolWithTag(lVar1,0);
  }
  if (*(longlong *)(param_2 + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x50),0);
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x58),0);
  }
  return;
}


