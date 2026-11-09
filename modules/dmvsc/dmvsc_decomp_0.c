
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



===== McGenControlCallbackV2 @ 140001030 =====

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



===== McGenEventRegister_EtwRegister @ 140001140 =====

void McGenEventRegister_EtwRegister(void)

{
  if (DMVSC_PROVIDER_Context == 0) {
    EtwRegister(&DMVSC_PROVIDER,McGenControlCallbackV2,&DMVSC_PROVIDER_Context,
                &DMVSC_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001180 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (DMVSC_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    DMVSC_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1400011b4 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000b038;
  uVar2 = 0;
  if (DAT_14000b038 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000b038;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(DMVSC_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 140001218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0zq_EtwWriteTransfer @ 14000125c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_20 = 4;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,0,3,local_48);
  return;
}



===== WPP_SF_ @ 1400012f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_DD @ 140001320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_D @ 140001370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400013c0 =====

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



===== FxStubDriverUnloadCommon @ 1400013f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b1d8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14000b1d8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000144d:
      if (ppvVar1 == (void **)0x0) goto LAB_1400014a3;
      if (ppvVar2 <= ppvVar1) goto LAB_1400014bb;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_14000144d;
LAB_1400014a3:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1400014bb:
  WdfVersionUnbind(&DAT_14000b468,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1400014f0 =====

void entry(_WDF_BIND_INFO *param_1,undefined *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140001524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14000b468 = 0x2080000;
    _DAT_14000b470 = &DAT_14000b250;
    RtlCopyUnicodeString(&DAT_14000b468);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000b468,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000b458 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000b468);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b1d8 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 1400016b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000b458 != (code *)0x0) && (DAT_14000b458 != FxStubDriverUnload)) {
    (*DAT_14000b458)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1400016e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140001709) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14000b1cf < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000b1d8 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000186c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140001889) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14000b1ef < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== DmcPowerUpWorkItemRoutine @ 140001940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcPowerUpWorkItemRoutine(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  
  puVar3 = PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  iVar1 = DmcWorkerStart(param_2);
  if ((iVar1 < 0) && ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0))
  {
    McTemplateK0zq_EtwWriteTransfer
              (param_2,&DMCLOG_OPERATION_FAILURE,puVar3,L"Start channel and worker",(char)iVar1);
  }
  KeSetEvent(lVar2 + 0x28,0,0);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 1400019c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,&DMCLOG_PROTOCOL_ACCEPT,param_3,3,local_48);
  return;
}



===== WPP_SF_I @ 140001a38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_I(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_LD @ 140001a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,0x50,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_LdLd @ 140001ad8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LdLd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 0x10;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,0x21,local_res20,4,
             local_18,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dd @ 140001b54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== McTemplateK0ixtttttt_EtwWriteTransfer @ 140001bac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ixtttttt_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  undefined8 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = &local_res20;
  local_90 = 8;
  local_88 = &param_5;
  local_80 = 8;
  local_78 = &param_6;
  local_70 = 4;
  local_68 = &param_7;
  local_58 = &param_8;
  local_48 = &param_9;
  local_38 = &param_10;
  local_28 = &param_11;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DMCLOG_MEMORY_CAPABILITY,param_3,9,local_a8);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 140001c84 =====

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
  McGenEventWrite_EtwWriteTransfer(param_1,&DMCLOG_POWER_CAPABILITIES_FAILURE,param_3,2,local_38);
  return;
}



===== WPP_SF_IId @ 140001ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IId(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0x11,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_dD @ 140001d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dDD @ 140001da8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0x18,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_iD @ 140001e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0x10,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_iIssssssI @ 140001e68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iIssssssI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     undefined1 param_5,char *param_6,char *param_7,char *param_8,char *param_9,
                     char *param_10,char *param_11,undefined1 param_12)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  char *pcVar12;
  char *pcVar13;
  undefined8 local_res20;
  
  if (param_11 == (char *)0x0) {
    lVar11 = 5;
  }
  else {
    lVar10 = -1;
    do {
      lVar11 = lVar10;
      lVar10 = lVar11 + 1;
    } while (param_11[lVar10] != '\0');
    lVar11 = lVar11 + 2;
  }
  pcVar12 = param_11;
  if (param_11 == (char *)0x0) {
    pcVar12 = "NULL";
  }
  if (param_10 == (char *)0x0) {
    lVar10 = 5;
  }
  else {
    lVar9 = -1;
    do {
      lVar10 = lVar9;
      lVar9 = lVar10 + 1;
    } while (param_10[lVar9] != '\0');
    lVar10 = lVar10 + 2;
  }
  pcVar4 = param_10;
  if (param_10 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    lVar9 = 5;
  }
  else {
    lVar8 = -1;
    do {
      lVar9 = lVar8;
      lVar8 = lVar9 + 1;
    } while (param_9[lVar8] != '\0');
    lVar9 = lVar9 + 2;
  }
  pcVar5 = param_9;
  if (param_9 == (char *)0x0) {
    pcVar5 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    lVar8 = 5;
  }
  else {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (param_8[lVar7] != '\0');
    lVar8 = lVar8 + 2;
  }
  pcVar6 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar6 = "NULL";
  }
  if (param_7 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar7 = lVar2;
      lVar2 = lVar7 + 1;
    } while (param_7[lVar2] != '\0');
    lVar7 = lVar7 + 2;
  }
  pcVar3 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar3 = "NULL";
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
  pcVar13 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar13 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0xf,&local_res20,8,
             &param_5,8,pcVar13,lVar1,pcVar3,lVar7,pcVar6,lVar8,pcVar5,lVar9,pcVar4,lVar10,pcVar12,
             lVar11,&param_12,8,0);
  return;
}



===== WPP_SF_IIIIDd @ 140002078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IIIIDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9400fa280a7934e5b8edeb5038407bb5_Traceguids,0x10,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== PkCompleteInsertion @ 140002108 =====

undefined8 PkCompleteInsertion(longlong *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  puVar5 = (undefined4 *)*param_1;
  uVar2 = *(uint *)(param_1 + 2);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *puVar5 = param_2;
  LOCK();
  UNLOCK();
  iVar3 = puVar5[2];
  uVar4 = puVar5[1];
  if ((uVar2 <= uVar4) || ((uVar4 & 7) != 0)) {
    return 0xc0000102;
  }
  *(uint *)((longlong)param_1 + 0x84) = uVar4;
  if (uVar1 == uVar4) {
    if (iVar3 == 0) {
      return 0x214;
    }
    *(longlong *)param_1[0x13] = *(longlong *)param_1[0x13] + 1;
  }
  return 0;
}



===== PkCompleteRemoval @ 140002168 =====

undefined4 PkCompleteRemoval(longlong param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  puVar4 = *(uint **)(param_1 + 0x18);
  uVar1 = *(uint *)(param_1 + 0x28);
  if (((longlong)(int)*puVar4 == (ulonglong)param_2) &&
     ((uint)((*(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x4c)) + *(int *)(param_1 + 0x48)) <
      0x40)) {
    LOCK();
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    UNLOCK();
  }
  iVar2 = *(int *)(param_1 + 0x44);
  uVar7 = 0;
  *(uint *)(param_1 + 0x44) = param_2;
  puVar4[1] = param_2;
  LOCK();
  UNLOCK();
  uVar3 = *puVar4;
  uVar8 = puVar4[3] & 0xfffffff8;
  if ((uVar3 < uVar1) && ((uVar3 & 7) == 0)) {
    *(uint *)(param_1 + 0x40) = uVar3;
    if (uVar8 != 0) {
      uVar6 = (iVar2 - uVar3) - 8;
      if (uVar1 <= uVar6) {
        uVar6 = uVar6 + uVar1;
      }
      uVar5 = (param_2 - uVar3) - 8;
      if (uVar1 <= uVar5) {
        uVar5 = uVar5 + uVar1;
      }
      if ((uVar8 <= uVar5) && (uVar6 < uVar8)) {
        return 0x214;
      }
    }
    if (param_2 == uVar3) {
      uVar7 = 0x213;
    }
  }
  else {
    uVar7 = 0xc0000102;
  }
  return uVar7;
}



===== PkGetReceiveBuffer @ 14000222c =====

undefined8
PkGetReceiveBuffer(longlong param_1,uint *param_2,undefined8 *param_3,uint *param_4,
                  undefined2 *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined2 *puVar12;
  uint uVar13;
  
  uVar11 = *param_2;
  uVar13 = *(uint *)(param_1 + 0x40);
  uVar1 = *(uint *)(param_1 + 0x28);
  if (uVar13 == uVar11) {
    uVar13 = **(uint **)(param_1 + 0x18);
    if (uVar1 <= uVar13) {
      return 0xc0000102;
    }
    if ((uVar13 & 7) != 0) {
      return 0xc0000102;
    }
    *(uint *)(param_1 + 0x40) = uVar13;
    if (uVar13 == uVar11) {
      return 0xc0000011;
    }
  }
  uVar13 = uVar13 - uVar11;
  puVar12 = (undefined2 *)((ulonglong)uVar11 + *(longlong *)(param_1 + 0x20));
  uVar3 = *puVar12;
  uVar4 = puVar12[1];
  uVar5 = puVar12[2];
  uVar6 = puVar12[3];
  uVar7 = puVar12[4];
  uVar8 = puVar12[5];
  uVar9 = puVar12[6];
  uVar10 = puVar12[7];
  uVar2 = (uint)uVar5 * 8;
  if (0xf < uVar2) {
    if (uVar1 <= uVar13) {
      uVar13 = uVar13 + uVar1;
    }
    if (uVar2 + 8 <= uVar13) {
      *param_4 = uVar2;
      uVar11 = uVar2 + 8 + uVar11;
      *param_3 = puVar12;
      uVar13 = uVar11 - uVar1;
      if (uVar11 < uVar1) {
        uVar13 = uVar11;
      }
      *param_2 = uVar13;
      *param_5 = uVar3;
      param_5[1] = uVar4;
      param_5[2] = uVar5;
      param_5[3] = uVar6;
      param_5[4] = uVar7;
      param_5[5] = uVar8;
      param_5[6] = uVar9;
      param_5[7] = uVar10;
      return 0;
    }
  }
  return 0xc0000102;
}



===== PkGetSendBufferEx @ 1400022e8 =====

undefined8
PkGetSendBufferEx(longlong *param_1,uint param_2,int param_3,longlong *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = *(uint *)(param_1 + 2);
  uVar7 = param_3 + 7U & 0xfffffff8;
  lVar3 = param_1[1];
  uVar1 = uVar7 + 8;
  uVar6 = (*(int *)((longlong)param_1 + 0x84) - param_2) - 8;
  if (uVar2 <= uVar6) {
    uVar6 = uVar6 + uVar2;
  }
  if (uVar6 < uVar1) {
    lVar4 = *param_1;
    uVar6 = *(uint *)(lVar4 + 4);
    if ((uVar2 <= uVar6) || ((uVar6 & 7) != 0)) {
      return 0xc0000102;
    }
    *(uint *)((longlong)param_1 + 0x84) = uVar6;
    uVar6 = (uVar6 - param_2) - 8;
    if (uVar2 <= uVar6) {
      uVar6 = uVar6 + uVar2;
    }
    if (uVar6 < uVar1) {
      if (uVar2 <= uVar1) {
        return 0xc000000d;
      }
      if (((int)param_1[0x11] == 0) &&
         ((uint)((*(int *)((longlong)param_1 + 0x8c) - *(int *)((longlong)param_1 + 0x4c)) +
                (int)param_1[9]) < 0x40)) {
        LOCK();
        *(int *)((longlong)param_1 + 0x8c) = *(int *)((longlong)param_1 + 0x8c) + 1;
        UNLOCK();
      }
      uVar6 = param_2 - (int)param_1[0x10];
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      uVar5 = uVar2 - 8;
      if (uVar6 + uVar1 < uVar2) {
        uVar5 = uVar6 + uVar1;
      }
      *(uint *)(lVar4 + 0xc) = uVar5;
      *(uint *)(param_1 + 0x11) = uVar7;
      LOCK();
      UNLOCK();
      uVar6 = *(uint *)(lVar4 + 4);
      if (uVar2 <= uVar6) {
        return 0xc0000102;
      }
      if ((uVar6 & 7) != 0) {
        return 0xc0000102;
      }
      *(uint *)((longlong)param_1 + 0x84) = uVar6;
      uVar6 = (uVar6 - param_2) - 8;
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      if (uVar6 < uVar1) {
        return 0x80000005;
      }
    }
  }
  *param_4 = (ulonglong)param_2 + lVar3;
  *param_5 = uVar6 - 8;
  return 0;
}



===== PkSendPacketSimple @ 140002438 =====

undefined8
PkSendPacketSimple(longlong *param_1,void *param_2,uint param_3,undefined8 param_4,int param_5)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 *local_res20;
  
  local_res20 = (undefined4 *)0x0;
  param_5 = 0;
  uVar3 = param_3 + 0x10;
  if (uVar3 < 0x7fff9) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = PkGetSendBufferEx(param_1,uVar1,uVar3,(longlong *)&local_res20,&param_5);
    if (-1 < (int)uVar2) {
      *local_res20 = 0x20006;
      *(short *)(local_res20 + 1) = (short)((ulonglong)uVar3 + 7 >> 3);
      *(undefined2 *)((longlong)local_res20 + 6) = 0;
      *(undefined8 *)(local_res20 + 2) = 0;
      memcpy(local_res20 + 4,param_2,(ulonglong)param_3);
      uVar3 = PkWritePacketFooter(param_1,uVar1,uVar3);
      uVar2 = PkCompleteInsertion(param_1,uVar3);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PkWritePacketFooter @ 140002508 =====

uint PkWritePacketFooter(longlong *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *puVar4;
  
  uVar1 = *(uint *)(param_1 + 2);
  if ((param_3 & 7) != 0) {
    puVar4 = (ulonglong *)((ulonglong)((param_3 & 0xfffffff8) + param_2) + param_1[1]);
    *puVar4 = (1L << (sbyte)((param_3 & 7) << 3)) - 1U & *puVar4;
    param_3 = param_3 + 7 & 0xfffffff8;
  }
  *(ulonglong *)((ulonglong)(param_2 + param_3) + param_1[1]) = (ulonglong)param_2 << 0x20;
  if ((int)param_1[0x11] != 0) {
    *(undefined4 *)(param_1 + 0x11) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  uVar3 = param_2 + param_3 + 8;
  uVar2 = uVar3 - uVar1;
  if (uVar3 < uVar1) {
    uVar2 = uVar3;
  }
  return uVar2;
}



===== PkpInitRingBufferControl @ 1400025a4 =====

undefined8 PkpInitRingBufferControl(longlong *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)param_1[3];
  uVar2 = *(uint *)(param_1[3] + 4);
  uVar3 = *(uint *)*param_1;
  uVar4 = *(uint *)(*param_1 + 4);
  if (((((*(uint *)(param_1 + 5) <= uVar1) || ((uVar1 & 7) != 0)) ||
       (*(uint *)(param_1 + 5) <= uVar2)) ||
      (((uVar2 & 7) != 0 || (*(uint *)(param_1 + 2) <= uVar3)))) ||
     (((uVar3 & 7) != 0 || ((*(uint *)(param_1 + 2) <= uVar4 || ((uVar4 & 7) != 0)))))) {
    return 0xc0000102;
  }
  *(uint *)((longlong)param_1 + 0x44) = uVar2;
  *(uint *)(param_1 + 8) = uVar1;
  *(uint *)(param_1 + 0x10) = uVar3;
  *(uint *)((longlong)param_1 + 0x84) = uVar4;
  *(undefined4 *)(*param_1 + 0xc) = 0;
  *(undefined4 *)(param_1[3] + 8) = 0;
  *(undefined4 *)(*param_1 + 0x40) = 0;
  *(uint *)(*param_1 + 0x40) = *(uint *)(*param_1 + 0x40) | 1;
  if ((uint)((*(int *)((longlong)param_1 + 0x8c) - *(int *)((longlong)param_1 + 0x4c)) +
            (int)param_1[9]) < 0x40) {
    LOCK();
    *(int *)(param_1 + 9) = (int)param_1[9] + 1;
    UNLOCK();
  }
  if ((uint)((*(int *)((longlong)param_1 + 0x8c) - *(int *)((longlong)param_1 + 0x4c)) +
            (int)param_1[9]) < 0x40) {
    LOCK();
    *(int *)((longlong)param_1 + 0x8c) = *(int *)((longlong)param_1 + 0x8c) + 1;
    UNLOCK();
  }
  return 0;
}



===== PkInitializeRingBuffer @ 140002688 =====

ulonglong PkInitializeRingBuffer
                    (longlong *param_1,longlong param_2,undefined8 param_3,int param_4,
                    longlong param_5,undefined8 param_6,int param_7)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_30 = 0;
  local_38 = 0;
  uVar1 = PkpDoubleMapBuffer(param_3,param_4 << 0xc,&local_30,&local_28);
  lVar2 = 0;
  if (-1 < (int)uVar1) {
    uVar1 = PkpDoubleMapBuffer(param_6,param_7 << 0xc,&local_38,&local_20);
    if (-1 < (int)uVar1) {
      memset(param_1,0,0xc0);
      param_1[4] = local_28;
      *param_1 = param_5;
      param_1[1] = local_20;
      param_1[0x13] = (longlong)(param_1 + 0x12);
      param_1[3] = param_2;
      *(int *)(param_1 + 5) = param_4 << 0xc;
      *(int *)(param_1 + 2) = param_7 << 0xc;
      uVar1 = PkpInitRingBufferControl(param_1);
      if (-1 < (int)uVar1) {
        param_1[6] = local_30;
        param_1[7] = local_38;
        return 0;
      }
    }
    lVar2 = local_38;
  }
  if (local_30 != 0) {
    PkpFreeDoubleMappedBuffer(local_30);
  }
  if (lVar2 != 0) {
    PkpFreeDoubleMappedBuffer(lVar2);
  }
  return uVar1 & 0xffffffff;
}



===== PkUninitializeRingBuffer @ 1400027a8 =====

void PkUninitializeRingBuffer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x30) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  return;
}



===== PkpDoubleMapBuffer @ 1400027e4 =====

undefined8 PkpDoubleMapBuffer(undefined8 param_1,uint param_2,longlong *param_3,undefined8 *param_4)

{
  size_t _Size;
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  uVar5 = 0;
  lVar2 = IoAllocateMdl(param_1,param_2 * 2,0,0,0);
  if (lVar2 != 0) {
    *(uint *)(lVar2 + 0x28) = param_2;
    MmProbeAndLockPages(lVar2,0,2);
    bVar1 = true;
    _Size = (ulonglong)(param_2 >> 0xc) * 8;
    memcpy((void *)(_Size + lVar2 + 0x30),(void *)(lVar2 + 0x30),_Size);
    *(uint *)(lVar2 + 0x28) = param_2 * 2;
    lVar3 = MmMapLockedPagesSpecifyCache
                      (lVar2,0,1,0,uVar5 & 0xffffffff00000000,ExDefaultMdlProtection | 0x40000010);
    if (lVar3 != 0) {
      *param_3 = lVar2;
      *param_4 = *(undefined8 *)(lVar2 + 0x18);
      lVar2 = 0;
      uVar4 = 0;
      goto LAB_1400028d1;
    }
    *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) >> 1;
  }
  uVar4 = 0xc000009a;
LAB_1400028d1:
  if (lVar2 != 0) {
    if (bVar1) {
      MmUnlockPages(lVar2);
    }
    IoFreeMdl(lVar2);
  }
  return uVar4;
}



===== PkpFreeDoubleMappedBuffer @ 14000291c =====

void PkpFreeDoubleMappedBuffer(longlong param_1)

{
  MmUnmapLockedPages(*(undefined8 *)(param_1 + 0x18),param_1);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) >> 1;
  MmUnlockPages(param_1);
  IoFreeMdl(param_1);
  return;
}



===== HviGetEnlightenmentInformation @ 140002968 =====

/* WARNING: Removing unreachable block (ram,0x000140002981) */

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



===== HviGetHypervisorFeatures @ 1400029a8 =====

/* WARNING: Removing unreachable block (ram,0x0001400029c1) */

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



===== HviIsAnyHypervisorPresent @ 1400029e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002a1c) */
/* WARNING: Removing unreachable block (ram,0x000140002a0b) */

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



===== HviIsHypervisorMicrosoftCompatible @ 140002a44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002a71) */

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



===== _guard_check_icall @ 140002ab0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002ac8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140002aec =====

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



===== __cpu_features_init @ 140002b60 =====

/* WARNING: Removing unreachable block (ram,0x000140002bca) */
/* WARNING: Removing unreachable block (ram,0x000140002b79) */
/* WARNING: Removing unreachable block (ram,0x000140002b6a) */

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



===== __security_check_cookie @ 140002c30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002c70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002ca0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002ca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002cd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140002d40 =====

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



===== memset @ 140003040 =====

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



===== __memset_repmovs @ 140003180 =====

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



===== __memset_query @ 140003200 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140003280 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400033c0 =====

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



===== __memset_spec_plain @ 140003440 =====

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



===== DmcEvtChannelSignalArrived @ 140004010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DmcEvtChannelSignalArrived(void)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = VmbChannelGetPointer();
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,uVar1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  uVar1 = KeSetEvent(lVar2 + 8,0,0);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== DmcEvtCommReceive @ 140004090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DmcEvtCommReceive(undefined8 param_1,void *param_2,uint param_3,uint *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint local_28 [2];
  longlong local_20 [3];
  
  local_20[0] = 0;
  local_28[1] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  ExAcquireFastMutex(lVar1 + 0x100);
  if (*(char *)(lVar1 + 0x18) == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
    }
    uVar4 = 0xc0000184;
    goto LAB_1400042e9;
  }
  local_28[0] = *(uint *)(lVar1 + 0x84);
  uVar2 = PkGetReceiveBuffer(lVar1 + 0x40,local_28,local_20,local_28 + 1,
                             (undefined2 *)(local_20 + 1));
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((int)uVar2 == -0x3fffffef) {
      uVar4 = 0xc00000d8;
      goto LAB_1400042e9;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400042e9;
    uVar3 = 0x18;
  }
  else if (*(ushort *)(local_20[0] + 4) < *(ushort *)(local_20[0] + 2)) {
    uVar4 = 0xc000000d;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400042e9;
    uVar3 = 0x19;
  }
  else {
    if (param_4 == (uint *)0x0) {
      uVar5 = uRam0000000000000000;
    }
    else {
      uVar5 = ((uint)*(ushort *)(local_20[0] + 4) - (uint)*(ushort *)(local_20[0] + 2)) * 8;
      *param_4 = uVar5;
    }
    if (param_3 < uVar5) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                  &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,param_3,(char)uVar5);
      }
      uVar4 = 0xc0000023;
      goto LAB_1400042e9;
    }
    memcpy(param_2,(void *)(local_20[0] + (ulonglong)*(ushort *)(local_20[0] + 2) * 8),
           (ulonglong)uVar5);
    uVar5 = PkCompleteRemoval(lVar1 + 0x40,local_28[0]);
    uVar4 = (ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      if (uVar5 == 0x214) {
        VmbChannelSendInterrupt(*(undefined8 *)(lVar1 + 8));
      }
      uVar4 = 0;
      goto LAB_1400042e9;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400042e9;
    uVar3 = 0x1b;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,(int)uVar4);
LAB_1400042e9:
  ExReleaseFastMutex(lVar1 + 0x100);
  return uVar4;
}



===== DmcEvtCommSend @ 140004320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DmcEvtCommSend(undefined8 param_1,void *param_2,uint param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  int in_stack_ffffffffffffffe8;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  ExAcquireFastMutex(lVar2 + 0x100);
  if (*(char *)(lVar2 + 0x18) == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
    }
    uVar3 = 0xc0000184;
  }
  else {
    uVar3 = PkSendPacketSimple((longlong *)(lVar2 + 0x40),param_2,param_3,param_4,
                               in_stack_ffffffffffffffe8);
    iVar1 = (int)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (iVar1 < 0) {
      if (iVar1 == -0x7ffffffb) {
        uVar3 = 0xc00000d8;
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,iVar1);
      }
    }
    else {
      if (iVar1 == 0x214) {
        VmbChannelSendInterrupt(*(undefined8 *)(lVar2 + 8));
      }
      uVar3 = 0;
    }
  }
  ExReleaseFastMutex(lVar2 + 0x100);
  return uVar3;
}



===== DmcEvtDeviceSelfManagedIoRestart @ 140004460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DmcEvtDeviceSelfManagedIoRestart(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_CONTEXT_TYPE_INFO_14000b090);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  iVar2 = VmbChannelEnable(*(undefined8 *)(lVar4 + 8));
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,iVar2);
    }
  }
  else {
    uVar1 = *puVar3;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
    KeClearEvent(lVar4 + 0x28);
    IoQueueWorkItem(*(undefined8 *)(lVar4 + 0x40),DmcPowerUpWorkItemRoutine,1,uVar1);
    iVar2 = 0;
  }
  return iVar2;
}



===== DmcEvtDeviceSelfManagedIoSuspend @ 140004580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DmcEvtDeviceSelfManagedIoSuspend(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_CONTEXT_TYPE_INFO_14000b090);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  KeWaitForSingleObject(lVar3 + 0x28,0,0,0,0);
  if (*(longlong *)(lVar3 + 0x88) != 0) {
    *(undefined4 *)(lVar3 + 0x20) = 1;
    KeSetEvent(lVar3 + 8,0,0);
    KeWaitForSingleObject(*(undefined8 *)(lVar3 + 0x88),0,0,0,0);
    ObfDereferenceObject(*(undefined8 *)(lVar3 + 0x88));
    *(undefined8 *)(lVar3 + 0x88) = 0;
  }
  VmbChannelDisable(*(undefined8 *)(lVar2 + 8));
  return 0;
}



===== DmcEventLoop @ 1400046a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DmcEventLoop(undefined8 *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res8[0] = 0;
  lVar9 = 0;
LAB_1400046c5:
  do {
    while( true ) {
      if ((*(int *)(param_1 + 4) != 0) && (*(char *)(param_1 + 9) == '\0')) {
        return *(int *)((longlong)param_1 + 0x24);
      }
      puVar1 = (ushort *)(param_1 + 0x1c);
      uVar8 = 0x1000;
      iVar4 = (*(code *)param_1[0x13])(*param_1,puVar1,0x1000,local_res8);
      if (iVar4 == -0x3fffff28) break;
      if (iVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar4;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return iVar4;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar4;
        }
        uVar6 = 0x51;
        goto LAB_140004a5c;
      }
      uVar7 = (ulonglong)local_res8[0];
      uVar5 = DmcValidateMessageSize((longlong)puVar1,local_res8[0]);
      if ((int)uVar5 < 0) {
LAB_1400049f3:
        iVar4 = -0x3ffffe7a;
        goto LAB_1400049fb;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_LD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,uVar8,(uint)*puVar1,
                  (char)*(undefined2 *)((longlong)param_1 + 0xe2));
      }
      uVar2 = *puVar1;
      if (uVar2 == 6) {
        if (*(ushort *)((longlong)param_1 + 0xe2) < 0x10) goto LAB_1400049f3;
        iVar4 = DmcProcessBalloonRequest(param_1,(longlong)puVar1);
      }
      else if (uVar2 == 8) {
        if (*(ushort *)((longlong)param_1 + 0xe2) < 0x10) goto LAB_1400049f3;
        iVar4 = DmcProcessUnballoonRequest(param_1,(longlong)puVar1);
      }
      else if (uVar2 == 10) {
        if (*(ushort *)((longlong)param_1 + 0xe2) < 0x10) goto LAB_1400049f3;
        iVar4 = DmcProcessHotAddRequest(param_1,(undefined8 *)puVar1);
      }
      else if (uVar2 == 0xc) {
        if (*(ushort *)((longlong)param_1 + 0xe2) < 0x10) goto LAB_1400049f3;
        uVar8 = DmcProcessInformationMessage((longlong)param_1,(longlong)puVar1);
        iVar4 = (int)uVar8;
      }
      else {
        if ((uVar2 != 0xd) || (*(ushort *)((longlong)param_1 + 0xe2) < 0x18)) goto LAB_1400049f3;
        iVar4 = DmcProcessRemoveRequest(param_1,(longlong)puVar1);
      }
      if (iVar4 < 0) {
LAB_1400049fb:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar6 = 0x52;
LAB_140004a5c:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                   &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar4);
        }
        return iVar4;
      }
    }
    if ((*(char *)((longlong)param_1 + 0x49) != '\0') &&
       (iVar4 = DmcProcessHotAddRequest(param_1,param_1 + 10), iVar4 < 0)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar4;
      }
      uVar6 = 0x53;
      goto LAB_140004a5c;
    }
    if (*(char *)((longlong)param_1 + 0xb1) == '\0') {
      if (*(char *)(param_1 + 0x1a) == '\0') {
        local_res10 = 0;
        local_4c = 0;
        local_60 = 0;
        local_70 = L"\\BaseNamedObjects\\SC_AutoStartComplete";
        local_58 = &local_78;
        local_68 = 0x30;
        local_78 = 0x4e004c;
        local_50 = 0x200;
        local_48 = 0;
        uStack_40 = 0;
        iVar4 = ZwOpenEvent(&local_res10,1,&local_68);
        if (iVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                     &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar4);
          }
        }
        else {
          local_res18 = 0;
          ObReferenceObjectByHandle
                    (local_res10,1,*(undefined8 *)ExEventObjectType_exref,0,&local_res18,0);
          uVar8 = local_res18;
          ZwClose(local_res10);
          iVar4 = KeReadStateEvent(uVar8);
          if (iVar4 != 0) {
            *(undefined1 *)(param_1 + 0x1a) = 1;
          }
          ObfDereferenceObject(uVar8);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                    &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
          }
          if (iVar4 != 0) goto LAB_14000499a;
        }
      }
      else {
LAB_14000499a:
        lVar3 = _DAT_fffff78000000008;
        if (9999999 < (ulonglong)(_DAT_fffff78000000008 - lVar9)) {
          iVar4 = DmcSendStatus(param_1);
          lVar9 = lVar3;
          if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3fffff66)) {
            *(int *)((longlong)param_1 + 0x24) = iVar4;
            *(undefined4 *)(param_1 + 4) = 1;
            goto LAB_1400046c5;
          }
        }
      }
    }
    local_res20 = 0xffffffffff676980;
    KeWaitForSingleObject(param_1 + 1,0,0,0,&local_res20);
  } while( true );
}



===== DmcEvtWorkerCleanup @ 140004a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcEvtWorkerCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  *(undefined4 *)(lVar1 + 0x20) = 1;
  KeSetEvent(lVar1 + 8,0,0);
  return;
}



===== DmcEvtWorkerDestroy @ 140004ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcEvtWorkerDestroy(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  if (*(longlong *)(lVar1 + 0x40) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x40) = 0;
  }
  if (*(longlong *)(lVar1 + 0x88) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(lVar1 + 0x88) = 0;
  }
  if (*(longlong *)(lVar1 + 0xb8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xb8),0x634d4476);
    *(undefined8 *)(lVar1 + 0xb8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x3120) != 0) {
    PcwCloseInstance();
    *(undefined8 *)(lVar1 + 0x3120) = 0;
  }
  if (*(longlong *)(lVar1 + 0x3128) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(lVar1 + 0x3128) = 0;
  }
  PcwUnregister(DmvscPcChannel);
  return;
}



===== DmcNegotiateProtocol @ 140004bcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DmcNegotiateProtocol(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ushort *puVar8;
  uint *puVar9;
  undefined1 auStack_b8 [32];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ushort local_58 [4];
  ulonglong uStack_50;
  ushort local_48 [4];
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  puVar9 = &DAT_1400098b8;
  uVar7 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  uStack_50 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  uStack_40 = 0;
  while( true ) {
    uVar1 = *puVar9;
    local_88 = 0x100001;
    uStack_80 = (ulonglong)uVar1;
    if (uVar7 == 2) {
      uStack_80 = CONCAT44(1,uVar1);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,uVar1 >> 0x10,(char)uVar1);
    }
    iVar2 = DmcSendMessage(param_1,(longlong)&local_88,'\x01');
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar2;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar2;
      }
      uVar5 = 0x17;
      goto LAB_140004f54;
    }
    puVar8 = local_58;
    uVar6 = 2;
    iVar2 = DmcReadMessageSynchronously(param_1,2,puVar8);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar2;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar2;
      }
      uVar5 = 0x18;
      goto LAB_140004f54;
    }
    if ((uStack_50 & 1) != 0) break;
    uVar7 = uVar7 + 1;
    puVar9 = puVar9 + 1;
    if (2 < uVar7) {
LAB_140004cde:
      if (uVar7 == 3) {
        puVar3 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          puVar8 = (ushort *)&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids;
          WPP_SF_(puVar3,0x19,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
        }
        if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
          return -0x3fffffa7;
        }
        McTemplateK0zq_EtwWriteTransfer
                  (puVar3,&DMCLOG_OPERATION_FAILURE,puVar8,L"Protocol negotiation",0x59);
        return -0x3fffffa7;
      }
      puVar3 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar8 = (ushort *)&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids;
        puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        uVar6 = 0x1a;
        WPP_SF_DD(puVar3,0x1a,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,
                  *(uint *)(param_1 + 0x15) >> 0x10,(char)*(uint *)(param_1 + 0x15));
      }
      if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 4) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar3,uVar6,puVar8,*(uint *)(param_1 + 0x15) >> 0x10,
                   (char)*(uint *)(param_1 + 0x15));
      }
      local_78 = 0x200003;
      uVar4 = (-(ulonglong)(*(char *)((longlong)param_1 + 0x79) != '\0') & 2) + 1;
      uStack_70 = -(uint)(*(char *)((longlong)param_1 + 0x7d) != '\0') & 0x80 | uVar4 |
                  (ulonglong)(-(uint)(*(char *)((longlong)param_1 + 0x7a) != '\0') & 0x40);
      if ((uVar4 & 2) != 0) {
        uStack_70 = uStack_70 | 4;
      }
      uStack_60 = param_1[0xd];
      local_68 = param_1[0xe];
      iVar2 = DmcSendMessage(param_1,(longlong)&local_78,'\x01');
      if (iVar2 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return iVar2;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar2;
        }
        uVar5 = 0x1b;
      }
      else {
        iVar2 = DmcReadMessageSynchronously(param_1,4,local_48);
        if (-1 < iVar2) {
          if ((uStack_40 & 1) == 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                      &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
            }
            return -0x3fff5fed;
          }
          if ((uStack_40 & 2) == 0) {
            *(undefined1 *)((longlong)param_1 + 0x7a) = 0;
          }
          if ((uStack_40 & 4) != 0) {
            *(undefined1 *)((longlong)param_1 + 0xb1) = 1;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                    &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
          }
          return 0;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return iVar2;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar2;
        }
        uVar5 = 0x1c;
      }
LAB_140004f54:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
               &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar2);
      return iVar2;
    }
  }
  *(undefined4 *)(param_1 + 0x15) = (undefined4)uStack_80;
  goto LAB_140004cde;
}



===== DmcProcessBalloonRequest @ 140004fa0 =====

int DmcProcessBalloonRequest(undefined8 *param_1,longlong param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint local_res8 [2];
  uint local_res18 [2];
  longlong local_res20;
  
  *(undefined1 *)(param_1 + 9) = 1;
  puVar2 = param_1 + 0x21c;
  local_res8[0] = 0;
  *(uint *)((longlong)param_1 + 0x10ec) = *(uint *)((longlong)param_1 + 0x10ec) | 1;
  local_res18[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
             &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,*(undefined4 *)(param_2 + 8));
  }
  iVar4 = KeReadStateEvent(param_1[0x625]);
  if (iVar4 == 0) {
    local_res20 = DmcRemovePages((longlong)(param_1 + 0xd),*(uint *)(param_2 + 8),0,2);
    if (local_res20 != 0) {
      puVar1 = (ulonglong *)(local_res20 + 0x30);
      uVar8 = *(uint *)(local_res20 + 0x28) >> 0xc;
      lVar3 = local_res20;
      iVar4 = 0;
      while (local_res20 = lVar3, uVar8 != 0) {
        *puVar2 = 0;
        param_1[0x21d] = 0;
        *(undefined4 *)puVar2 = 0x100007;
        *(undefined4 *)((longlong)param_1 + 0x10e4) = *(undefined4 *)(param_2 + 4);
        DmcBuildRangesFromPages
                  (puVar1,uVar8,local_res8,(longlong)(param_1 + 0x21e),0x1fe,local_res18);
        puVar1 = puVar1 + local_res8[0];
        *(short *)((longlong)param_1 + 0x10e2) =
             *(short *)((longlong)param_1 + 0x10e2) + (short)local_res18[0] * 8;
        uVar8 = uVar8 - local_res8[0];
        *(uint *)((longlong)param_1 + 0x10ec) = (uint)(uVar8 != 0) | local_res18[0] * 2;
        puVar7 = puVar2;
        iVar5 = DmcSendMessage(param_1,(longlong)puVar2,'\x01');
        lVar3 = local_res20;
        if (iVar5 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (puVar7 = (undefined8 *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
              (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar7 = (undefined8 *)0x49;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                     &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar5);
          }
          DmcUnballoonPageRanges
                    (param_1 + 0x41c,puVar7,
                     (undefined *)(ulonglong)(*(uint *)((longlong)param_1 + 0x10ec) >> 1),
                     param_1 + 0x21e);
          lVar3 = local_res20;
          iVar4 = iVar5;
        }
      }
      *(undefined1 *)(param_1 + 9) = 0;
      *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
      }
      ExFreePoolWithTag(lVar3,0);
      goto LAB_1400051ff;
    }
    iVar4 = -0x3fffff66;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400051ff;
    uVar6 = 0x48;
  }
  else {
    iVar4 = 0;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1400051ff;
    uVar6 = 0x47;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
          &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
LAB_1400051ff:
  if ((*(uint *)((longlong)param_1 + 0x10ec) & 1) != 0) {
    *puVar2 = 0;
    param_1[0x21d] = 0;
    *(undefined4 *)puVar2 = 0x100007;
    *(undefined4 *)((longlong)param_1 + 0x10e4) = *(undefined4 *)(param_2 + 4);
    *(uint *)((longlong)param_1 + 0x10ec) = *(uint *)((longlong)param_1 + 0x10ec) & 0xfffffffe;
    iVar4 = DmcSendMessage(param_1,(longlong)puVar2,'\x01');
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                 &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar4);
      }
    }
    else {
      *(undefined1 *)(param_1 + 9) = 0;
      *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
    }
  }
  return iVar4;
}



===== DmcProcessHotAddRequest @ 140005290 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DmcProcessHotAddRequest(undefined8 *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_68 [32];
  uint local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0;
  *(undefined1 *)(param_1 + 9) = 1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
             &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,(uint)((ulonglong)param_2[1] >> 0x28))
    ;
  }
  uVar7 = (ulonglong)param_2[1] >> 0x28;
  iVar3 = DmcHotAddPageRange(param_1 + 0xd,param_2[1] & 0xffffffffff,uVar7,local_48);
  if (iVar3 < 0) {
    if (iVar3 == -0x3fffff66) {
      uVar1 = param_2[1];
      if (0x1ff < uVar1 >> 0x29) {
        uVar4 = uVar1 >> 1 & 0x7fffff0000000000 | uVar1 & 0xffffffffff;
        param_2[1] = uVar4;
        uVar6 = (uint)(uVar1 >> 0x29) & 0x1ff;
        if (uVar6 != 0) {
          param_2[1] = (uVar4 - ((ulonglong)uVar6 << 0x28) ^ uVar4) & 0xffffff0000000000 ^ uVar4;
        }
      }
      if (param_2 == param_1 + 10) {
        iVar3 = *(int *)(param_1 + 0xc);
        *(int *)(param_1 + 0xc) = iVar3 + 1;
        if (iVar3 + 1 == 0x3c) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                     &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,0x3c);
          }
          local_3c = *(undefined4 *)((longlong)param_2 + 4);
          local_38 = 0;
          local_34 = 0;
          local_40 = 0x10000b;
          iVar3 = DmcSendMessage(param_1,(longlong)&local_40,'\x01');
          if (-1 < iVar3) {
            *(undefined4 *)(param_1 + 0xc) = 0;
            *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
            *(undefined1 *)((longlong)param_1 + 0x49) = 0;
            *(undefined1 *)(param_1 + 9) = 0;
            return 0;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar3;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return iVar3;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar3;
          }
          uVar5 = 0x35;
          goto LAB_14000547a;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return 0;
        }
        uVar5 = 0x36;
      }
      else {
        uVar2 = param_2[1];
        param_1[10] = *param_2;
        param_1[0xb] = uVar2;
        *(undefined1 *)((longlong)param_1 + 0x49) = 1;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return 0;
        }
        uVar5 = 0x33;
      }
      WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,uVar7,(ulonglong)param_2[1] >> 0x28)
      ;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar3;
    }
    uVar5 = 0x37;
  }
  else {
    local_3c = *(undefined4 *)((longlong)param_2 + 4);
    local_38 = local_48[0];
    local_40 = 0x10000b;
    local_34 = 1;
    iVar3 = DmcSendMessage(param_1,(longlong)&local_40,'\x01');
    if (-1 < iVar3) {
      if (*(char *)((longlong)param_1 + 0x49) != '\0') {
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(undefined1 *)((longlong)param_1 + 0x49) = 0;
      }
      *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
      *(undefined1 *)(param_1 + 9) = 0;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return 0;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
               &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,local_48[0]);
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar3;
    }
    uVar5 = 0x38;
  }
LAB_14000547a:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar3);
  return iVar3;
}



===== DmcProcessInformationMessage @ 1400055dc =====

undefined8 DmcProcessInformationMessage(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong *puVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  uVar5 = *(uint *)(param_2 + 0xc);
  uVar6 = 0;
  if (uVar5 < 0xff1) {
    if (*(ushort *)(param_2 + 2) - 0x10 == uVar5) {
      if (uVar5 != 0) {
        do {
          if (uVar5 - uVar6 < 8) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return 0xc0000004;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
              return 0xc0000004;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return 0xc0000004;
            }
            uVar3 = 0x4e;
LAB_14000573a:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
                    &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
            return 0xc0000004;
          }
          uVar7 = (ulonglong)uVar6;
          uVar6 = uVar6 + 8;
          uVar1 = *(uint *)(uVar7 + 0x14 + param_2);
          if (uVar1 == 0) {
            puVar2 = (ulonglong *)0x0;
          }
          else {
            if (uVar5 - uVar6 < uVar1) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return 0xc0000004;
              }
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
                return 0xc0000004;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return 0xc0000004;
              }
              uVar3 = 0x4f;
              goto LAB_14000573a;
            }
            puVar2 = (ulonglong *)((ulonglong)uVar6 + 0x10 + param_2);
            uVar6 = uVar6 + uVar1;
          }
          if (*(int *)(uVar7 + 0x10 + param_2) == 0) {
            if (uVar1 != 8) {
              return 0xc000000d;
            }
            *(ulonglong *)(param_1 + 0x3118) = *puVar2 >> 8;
          }
          uVar5 = *(uint *)(param_2 + 0xc);
        } while (uVar6 < uVar5);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
      }
      uVar4 = 0xc0000186;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
              &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
    }
    uVar4 = 0xc0000023;
  }
  return uVar4;
}



===== DmcProcessRemoveRequest @ 140005760 =====

int DmcProcessRemoveRequest(undefined8 *param_1,longlong param_2)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  uint local_res8 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  
  *(undefined1 *)(param_1 + 9) = 1;
  local_res18[0] = 0;
  puVar2 = param_1 + 0x21c;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,*(undefined4 *)(param_2 + 0xc),
              (char)*(undefined4 *)(param_2 + 8));
  }
  iVar3 = KeReadStateEvent(param_1[0x625]);
  if ((iVar3 == 0) &&
     (lVar6 = DmcRemovePages((longlong)(param_1 + 0xd),*(uint *)(param_2 + 0xc),
                             *(undefined4 *)(param_2 + 8),*(uint *)(param_2 + 0x10)), lVar6 != 0)) {
    iVar3 = 0;
    puVar1 = (ulonglong *)(lVar6 + 0x30);
    uVar7 = *(uint *)(lVar6 + 0x28) >> 0xc;
    local_res8[0] = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
               &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,uVar7);
    }
    while (uVar7 != 0) {
      *puVar2 = 0;
      param_1[0x21d] = 0;
      param_1[0x21e] = 0;
      *(undefined4 *)puVar2 = 0x18000e;
      *(undefined4 *)((longlong)param_1 + 0x10e4) = *(undefined4 *)(param_2 + 4);
      DmcBuildRangesFromPages(puVar1,uVar7,local_res8,(longlong)(param_1 + 0x21f),0x1fd,local_res18)
      ;
      uVar7 = uVar7 - local_res8[0];
      puVar1 = puVar1 + local_res8[0];
      *(uint *)((longlong)param_1 + 0x10ec) = local_res18[0];
      *(short *)((longlong)param_1 + 0x10e2) =
           *(short *)((longlong)param_1 + 0x10e2) + (short)local_res18[0] * 8;
      *(undefined4 *)(param_1 + 0x21d) = 0;
      param_1[0x21e] = (ulonglong)(uVar7 != 0) | param_1[0x21e] & 0xfffffffffffffffe;
      iVar4 = DmcSendMessage(param_1,(longlong)puVar2,'\x01');
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                   &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar4);
        }
        local_res20[0] = 0;
        iVar5 = DmcHotAddPageRanges(param_1 + 0xd,param_1 + 0x21f,
                                    (undefined *)(ulonglong)*(uint *)((longlong)param_1 + 0x10ec),
                                    (int *)local_res20);
        iVar3 = iVar4;
        if ((((iVar5 < 0) || (local_res20[0] != local_res8[0])) &&
            ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                   &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar5);
        }
      }
    }
    *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
    *(undefined1 *)(param_1 + 9) = 0;
    ExFreePoolWithTag(lVar6,0);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
              &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
    }
    *puVar2 = 0;
    param_1[0x21d] = 0;
    param_1[0x21e] = 0;
    *(undefined4 *)puVar2 = 0x18000e;
    *(undefined4 *)((longlong)param_1 + 0x10e4) = *(undefined4 *)(param_2 + 4);
    param_1[0x21e] = param_1[0x21e] & 0xfffffffffffffffe;
    *(undefined4 *)(param_1 + 0x21d) = 0;
    iVar3 = DmcSendMessage(param_1,(longlong)puVar2,'\x01');
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                 &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar3);
      }
    }
    else {
      *(undefined1 *)(param_1 + 9) = 0;
      *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
    }
  }
  return iVar3;
}



===== DmcProcessUnballoonRequest @ 140005aa4 =====

int DmcProcessUnballoonRequest(undefined8 *param_1,longlong param_2)

{
  ulonglong uVar1;
  int iVar2;
  uint uVar3;
  ulonglong *puVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint local_res10 [2];
  undefined8 local_res18;
  
  local_res18 = 0;
  local_res10[0] = 0;
  if (*(uint *)(param_2 + 0xc) != *(ushort *)(param_2 + 2) - 0x10 >> 3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
              &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
    }
    return -0x3ffffe7a;
  }
  uVar8 = 0;
  *(undefined1 *)(param_1 + 9) = 1;
  lVar7 = param_2;
  if (*(uint *)(param_2 + 0xc) != 0) {
    puVar4 = (ulonglong *)(param_2 + 0x10);
    uVar6 = (ulonglong)*(uint *)(param_2 + 0xc);
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      uVar8 = uVar8 + (uVar1 >> 0x28);
      uVar6 = uVar6 - 1;
      lVar7 = 0;
    } while (uVar6 != 0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar7 = 0x3b;
    WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,8,uVar8);
  }
  if (*(char *)((longlong)param_1 + 0x7a) == '\0') {
    uVar3 = DmcUnballoonPageRanges
                      (param_1 + 0x41c,lVar7,(undefined *)(ulonglong)*(uint *)(param_2 + 0xc),
                       (ulonglong *)(param_2 + 0x10));
LAB_140005c2c:
    if ((*(uint *)(param_2 + 8) & 1) == 0) {
      local_res18 = CONCAT44(*(undefined4 *)(param_2 + 4),0x80009);
      iVar2 = DmcSendMessage(param_1,(longlong)&local_res18,'\x01');
      if (iVar2 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar2;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return iVar2;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar2;
        }
        uVar5 = 0x3e;
        goto LAB_140005bcb;
      }
      *(undefined4 *)((longlong)param_1 + 0xd4) = 0;
      *(undefined1 *)(param_1 + 9) = 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
               &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,uVar3);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = DmcHotAddPageRanges(param_1 + 0xd,(ulonglong *)(param_2 + 0x10),
                                (undefined *)(ulonglong)*(uint *)(param_2 + 0xc),(int *)local_res10)
    ;
    uVar3 = local_res10[0];
    if (-1 < iVar2) {
      if (((local_res10[0] < uVar8) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
      }
      goto LAB_140005c2c;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar2;
    }
    uVar5 = 0x3c;
LAB_140005bcb:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
             &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar2);
  }
  return iVar2;
}



===== DmcReadMessageSynchronously @ 140005cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DmcReadMessageSynchronously(undefined8 *param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffd8;
  
  local_res20[0] = 0;
  do {
    uVar4 = 0x10;
    iVar2 = (*(code *)param_1[0x13])(*param_1,param_3,0x10,local_res20);
    if (iVar2 != -0x3fffff28) {
      if (iVar2 < 0) {
LAB_140005d58:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                   &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar2);
        }
      }
      else {
        uVar3 = DmcValidateMessageSize((longlong)param_3,local_res20[0]);
        if ((int)uVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                     &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,(int)uVar3);
          }
        }
        else {
          uVar1 = param_3[1];
          if ((uVar1 == 0x10) && (*param_3 == param_2)) {
            return 0;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_LdLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar1,uVar4,param_2,
                        in_stack_ffffffffffffffd8,(char)*param_3,(char)uVar1);
          }
        }
        iVar2 = -0x3ffffe7c;
      }
      return iVar2;
    }
    if (*(int *)(param_1 + 4) != 0) {
      iVar2 = -0x3ffffd4a;
      goto LAB_140005d58;
    }
    in_stack_ffffffffffffffd8 = 0;
    KeWaitForSingleObject(param_1 + 1,0,0,0);
  } while( true );
}



===== DmcSendMessage @ 140005e5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcSendMessage(undefined8 *param_1,longlong param_2,char param_3)

{
  int iVar1;
  undefined8 local_res8;
  
  *(int *)(param_1 + 0x622) = *(int *)(param_1 + 0x622) + 1;
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x622);
  while( true ) {
    iVar1 = (*(code *)param_1[0x14])(*param_1,param_2,*(undefined2 *)(param_2 + 2));
    if ((iVar1 != -0x3fffff28) || (param_3 == '\0')) break;
    local_res8 = 0xffffffffff676980;
    KeWaitForSingleObject(param_1 + 1,0,0,0,&local_res8);
  }
  return;
}



===== DmcSendStatus @ 140005eec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DmcSendStatus(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_40 = 0;
  local_48 = 0x300005;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = DmcGeneratePressureReport((longlong)param_1,(longlong)&local_48);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar3 = 0x22;
LAB_140005f6a:
    WPP_SF_D(uVar2,uVar3,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar1);
  }
  else {
    if (*(char *)(param_1 + 0x16) == '\0') {
      *(undefined1 *)(param_1 + 0x16) = 1;
    }
    else {
      iVar1 = DmcSendMessage(param_1,(longlong)&local_48,'\0');
      if (iVar1 < 0) {
        if (iVar1 != -0x3fffff28) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return iVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar1;
          }
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          uVar3 = 0x24;
          goto LAB_140005f6a;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
        }
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== DmcThread @ 140006040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcThread(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  KeWaitForSingleObject(puVar2 + 1,0,0,0,0);
  if (*(int *)(puVar2 + 4) == 0) {
    iVar1 = DmcNegotiateProtocol(puVar2);
    if (-1 < iVar1) {
      iVar1 = DmcEventLoop(puVar2);
      goto LAB_1400060fc;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar1);
    }
  }
  else {
    iVar1 = *(int *)((longlong)puVar2 + 0x24);
LAB_1400060fc:
    if (-1 < iVar1) goto LAB_140006147;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar1);
  }
  if ((code *)puVar2[0x12] != (code *)0x0) {
    (*(code *)puVar2[0x12])(param_1,iVar1);
  }
LAB_140006147:
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,param_1,0,0x693,"onecore\\vm\\dv\\dm\\vsc\\lib\\worker.c");
  PsTerminateSystemThread(iVar1);
  return;
}



===== DmcValidateMessageSize @ 1400061a4 =====

undefined8 DmcValidateMessageSize(longlong param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = 8;
  if (param_2 < 8) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000184;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000184;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000184;
    }
    uVar1 = 0x29;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_1 + 2);
    if (uVar2 <= param_2) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000184;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000184;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000184;
    }
    uVar1 = 0x2a;
  }
  WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,(ulonglong)param_2,uVar2,(char)param_2)
  ;
  return 0xc0000184;
}



===== DmcWorkerIoReady @ 140006230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcWorkerIoReady(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110);
  KeSetEvent(lVar1 + 8,0,0);
  return;
}



===== DmcBuildRangesFromPages @ 14000627c =====

void DmcBuildRangesFromPages
               (ulonglong *param_1,uint param_2,uint *param_3,longlong param_4,uint param_5,
               uint *param_6)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar5 = *param_1;
  uVar4 = 0;
  uVar1 = 1;
  uVar2 = 1;
  if (1 < param_2) {
    do {
      param_1 = param_1 + 1;
      if (*param_1 == uVar1 + uVar5) {
        uVar1 = (ulonglong)((int)uVar1 + 1);
      }
      else {
        *(ulonglong *)(param_4 + uVar4 * 8) = uVar1 << 0x28 | uVar5 & 0xffffffffff;
        uVar3 = (int)uVar4 + 1;
        uVar4 = (ulonglong)uVar3;
        if (uVar3 == param_5) goto LAB_1400062fb;
        uVar5 = *param_1;
        uVar1 = 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  *(ulonglong *)(param_4 + uVar4 * 8) = uVar1 << 0x28 | uVar5 & 0xffffffffff;
  uVar3 = (int)uVar4 + 1;
LAB_1400062fb:
  *param_3 = uVar2;
  *param_6 = uVar3;
  return;
}



===== DmcHotAddPageRange @ 140006324 =====

int DmcHotAddPageRange(longlong *param_1,longlong param_2,ulonglong param_3,uint *param_4)

{
  int iVar1;
  undefined *puVar2;
  longlong *plVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = 0;
  local_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_iD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_2,(char)param_3);
  }
  uVar6 = 0;
  uVar4 = (param_3 & 0xffffffff) * 0x1000;
  if ((param_3 & 0xffffffff) != 0) {
    do {
      local_30 = param_2 * 0x1000 + uVar6 | 1;
      plVar3 = &local_38;
      local_38 = uVar4 - uVar6;
      iVar1 = MmAddPhysicalMemory(&local_30);
      uVar7 = 0xc00000ef;
      if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fffff11)) {
        puVar2 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          WPP_SF_IId(puVar2,plVar3,0xc00000ef,local_30,(char)local_38,(char)iVar1);
        }
        if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
          return iVar1;
        }
        McTemplateK0zq_EtwWriteTransfer
                  (puVar2,&DMCLOG_MEMORY_OPERATION_FAILURE,uVar7,L"Hot add memory range",(char)iVar1
                  );
        return iVar1;
      }
      if (iVar1 == -0x3fffff11) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                   &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0xc00000ef);
        }
        break;
      }
      if (local_38 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
        }
        break;
      }
      uVar6 = uVar6 + local_38;
    } while (uVar6 < uVar4);
  }
  uVar5 = (uint)(uVar6 >> 0xc);
  *param_4 = uVar5;
  if (uVar5 < (uint)param_3) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,(uint)param_3,(char)(uVar6 >> 0xc))
      ;
    }
    if (*param_4 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
      }
      if ((char)param_1[2] == '\0') {
        *(undefined1 *)(param_1 + 2) = 1;
        *param_1 = param_2 + -1;
      }
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,uVar5);
  }
  return 0;
}



===== DmcHotAddPageRanges @ 1400065f4 =====

int DmcHotAddPageRanges(longlong *param_1,ulonglong *param_2,undefined *param_3,int *param_4)

{
  ulonglong uVar1;
  int iVar2;
  undefined *puVar3;
  ulonglong uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_res18 [4];
  undefined1 uVar9;
  
  iVar7 = 0;
  uVar6 = 0;
  uVar8 = (uint)param_3;
  if (uVar8 != 0) {
    do {
      uVar1 = *param_2;
      local_res18[0] = 0;
      param_3 = (undefined *)(uVar1 >> 0x28);
      uVar4 = uVar1 & 0xffffffffff;
      iVar2 = DmcHotAddPageRange(param_1,uVar4,(ulonglong)param_3,local_res18);
      if (iVar2 < 0) {
        uVar9 = (undefined1)(uVar1 >> 0x28);
        if (iVar7 == 0) {
          puVar3 = WPP_GLOBAL_Control;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
            WPP_SF_dD(puVar3,0x17,param_3,iVar2,uVar9);
          }
          if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
            return iVar2;
          }
          puVar5 = &DMCLOG_MEMORY_OPERATION_FAILURE;
          iVar7 = iVar2;
          goto LAB_14000676d;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,param_3,iVar2,uVar9,
                     (char)local_res18[0]);
        }
        break;
      }
      iVar7 = iVar7 + local_res18[0];
      if ((ulonglong)local_res18[0] < *param_2 >> 0x28) break;
      uVar6 = uVar6 + 1;
      param_2 = param_2 + 1;
    } while (uVar6 < uVar8);
  }
  *param_4 = iVar7;
  puVar3 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_3 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
    WPP_SF_D(puVar3,0x19,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,iVar7);
  }
  iVar2 = 0;
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 2) != 0) {
    puVar5 = &DMCLOG_MEMORY_OPERATION_SUCCEEDED;
LAB_14000676d:
    McTemplateK0zq_EtwWriteTransfer(puVar3,puVar5,param_3,L"Hot add memory ranges",(char)iVar7);
  }
  return iVar2;
}



===== DmcRemovePages @ 140006798 =====

longlong DmcRemovePages(longlong param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined *puVar8;
  undefined *puVar9;
  uint uVar10;
  
  lVar2 = 0;
  puVar8 = (undefined *)(ulonglong)param_2;
  uVar10 = param_4 & 4;
  if (uVar10 == 0) {
    puVar5 = (undefined *)((ulonglong)(-(uint)((param_4 & 1) != 0) & 0x1ff) + 1);
  }
  else {
    puVar5 = (undefined *)0x40000;
  }
  if (puVar8 < puVar5) {
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar8 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
      WPP_SF_(puVar4,0x1d,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return 0;
    }
LAB_140006840:
    uVar10 = 0;
    puVar5 = &DMCLOG_MEMORY_OPERATION_FAILURE;
    puVar9 = puVar8;
    goto LAB_140006a76;
  }
  if (param_2 < 0x40000) {
    if (0x1ff < param_2) goto LAB_140006869;
    puVar6 = (undefined *)((-(ulonglong)(param_2 < 0x10) & 0xfffffffffffffff1) + 0x10);
  }
  else if (uVar10 == 0) {
LAB_140006869:
    puVar6 = (undefined *)0x200;
  }
  else {
    puVar6 = (undefined *)0x40000;
  }
  uVar3 = (-(uint)(*(char *)(param_1 + 0x12) != '\0') & 0x100) + 0x11;
  uVar1 = uVar3 | 0x60;
  if (puVar6 < (undefined *)0x2) {
    uVar1 = uVar3;
  }
  uVar3 = uVar1 | 2;
  while( true ) {
    puVar9 = (undefined *)((longlong)puVar6 << 0xc);
    lVar2 = MmAllocateNodePagesForMdlEx
                      (0,0xffffffffffffffff,puVar9,
                       ((longlong)puVar8 - (ulonglong)puVar8 % (ulonglong)puVar6) * 0x1000,1,param_3
                       ,uVar3);
    puVar4 = WPP_GLOBAL_Control;
    if (lVar2 != 0) break;
    uVar7 = uVar3;
    if (puVar6 == (undefined *)0x40000) {
      puVar6 = (undefined *)0x200;
    }
    else if (puVar6 == (undefined *)0x200) {
      if ((uVar3 >> 6 & 1) == 0) {
        puVar6 = (undefined *)0x10;
      }
      uVar7 = uVar3 & 0xffffffbf;
      if ((uVar3 >> 6 & 1) == 0) {
        uVar7 = uVar3 | 0x40;
      }
    }
    else if (puVar6 == (undefined *)0x10) {
      puVar6 = (undefined *)0x1;
      uVar7 = uVar3 & 0xffffff9f;
    }
    else {
      puVar6 = (undefined *)0x0;
    }
    uVar3 = uVar7;
    if (puVar6 < puVar5) {
      if ((((uVar7 & 2) == 0) || ((param_4 & 2) != 0)) || (*(ulonglong *)(param_1 + 0x18) < 2)) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          puVar8 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
          WPP_SF_(puVar4,0x20,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
        }
        if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
          return 0;
        }
        goto LAB_140006840;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
      }
      if (param_2 < 0x40000) {
        if (0x1ff < param_2) goto LAB_1400069c2;
        puVar6 = (undefined *)((-(ulonglong)(param_2 < 0x10) & 0xfffffffffffffff1) + 0x10);
      }
      else if (uVar10 == 0) {
LAB_1400069c2:
        puVar6 = (undefined *)0x200;
      }
      else {
        puVar6 = (undefined *)0x40000;
      }
      uVar3 = uVar1;
    }
  }
  uVar10 = *(uint *)(lVar2 + 0x28) >> 0xc;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar9 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
    WPP_SF_D(puVar4,0x1f,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,uVar10);
  }
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 2) == 0) {
    return lVar2;
  }
  puVar5 = &DMCLOG_MEMORY_OPERATION_SUCCEEDED;
LAB_140006a76:
  McTemplateK0zq_EtwWriteTransfer(puVar4,puVar5,puVar9,L"Remove memory",(char)uVar10);
  return lVar2;
}



===== DmcUnballoonPageRanges @ 140006aa4 =====

int DmcUnballoonPageRanges
              (undefined8 *param_1,undefined8 param_2,undefined *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  undefined *puVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar4 = 0;
  iVar6 = 0;
  if ((int)param_3 != 0) {
    uVar8 = (ulonglong)param_3 & 0xffffffff;
    do {
      uVar7 = uVar8;
      uVar8 = *param_4;
      uVar5 = 0;
      if ((uVar8 & 0xffffff0000000000) != 0) {
        uVar3 = 0;
        do {
          iVar6 = iVar6 + 1;
          uVar1 = (ulonglong)uVar4;
          uVar4 = uVar4 + 1;
          param_1[uVar1 + 6] = (uVar8 & 0xffffffffff) + uVar3;
          if (uVar4 == 0x200) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              param_3 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                       &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,0x200);
            }
            *(undefined4 *)(param_1 + 5) = 0x200000;
            *param_1 = 0;
            *(undefined2 *)(param_1 + 1) = 0x1030;
            *(undefined2 *)((longlong)param_1 + 10) = 0;
            param_1[4] = 0;
            *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
            MmFreePagesFromMdl(param_1);
            uVar4 = 0;
          }
          uVar8 = *param_4;
          uVar5 = uVar5 + 1;
          uVar3 = (ulonglong)uVar5;
        } while (uVar3 < uVar8 >> 0x28);
      }
      param_4 = param_4 + 1;
      uVar8 = uVar7 - 1;
    } while (uVar8 != 0);
    if (uVar4 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar7 + 0x1a,
                 &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,uVar4);
      }
      *(uint *)(param_1 + 5) = uVar4 << 0xc;
      *param_1 = 0;
      *(short *)(param_1 + 1) = ((short)uVar4 + 6) * 8;
      *(undefined2 *)((longlong)param_1 + 10) = 0;
      param_1[4] = 0;
      *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
      MmFreePagesFromMdl(param_1);
    }
  }
  puVar2 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    param_3 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
    WPP_SF_D(puVar2,0x1c,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,iVar6);
  }
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 2) != 0) {
    McTemplateK0zq_EtwWriteTransfer
              (puVar2,&DMCLOG_MEMORY_OPERATION_SUCCEEDED,param_3,L"Unballoon memory",(char)iVar6);
  }
  return iVar6;
}



===== DmcpQueryNumaNodeCount @ 140006ca8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DmcpQueryNumaNodeCount(ulonglong *param_1)

{
  undefined8 uVar1;
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc [57];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  memset(local_fc,0,0xe4);
  if (param_1 == (ulonglong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_108 = 0;
    local_118 = 0xf0;
    local_100 = 0xffffffff;
    local_104 = 0xffffffff;
    uVar1 = ZwManagePartition(0xfffffffffffffffe,0,0,&local_108);
    if (-1 < (int)uVar1) {
      *param_1 = (ulonglong)local_fc[0];
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== DmcGeneratePressureReport @ 140006d44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DmcGeneratePressureReport(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  undefined2 uVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined1 auStackY_2f8 [32];
  undefined4 local_2a8 [4];
  undefined1 local_298 [16];
  int local_288;
  longlong local_258;
  longlong local_250;
  undefined1 local_1a8 [44];
  uint local_17c;
  uint local_178;
  int local_158;
  int local_148;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2f8;
  memset(local_1a8,0,0x178);
  memset(local_298,0,0x40);
  memset(&local_258,0,0xb0);
  lVar2 = *(longlong *)(param_1 + 0xb8);
  local_2a8[0] = 0;
  if (lVar2 == 0) {
    lVar2 = ExAllocatePool2(0x40,0x200,0x634d4476);
    *(longlong *)(param_1 + 0xb8) = lVar2;
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_9400fa280a7934e5b8edeb5038407bb5_Traceguids);
      }
      return -0x3fffff66;
    }
    *(undefined4 *)(param_1 + 0xc0) = 0x200;
  }
  while (iVar1 = NtQuerySystemInformation(0x12,lVar2,*(undefined4 *)(param_1 + 0xc0)), iVar1 < 0) {
    if (iVar1 != -0x3ffffffc) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar1;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar1;
      }
      uVar4 = 0xc;
      goto LAB_140006f32;
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xb8),0x634d4476);
    lVar2 = ExAllocatePool2(0x40,*(int *)(param_1 + 0xc0) + 0x200,0x634d4476);
    *(longlong *)(param_1 + 0xb8) = lVar2;
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_9400fa280a7934e5b8edeb5038407bb5_Traceguids);
      }
      *(undefined4 *)(param_1 + 0xc0) = 0;
      return -0x3fffffe9;
    }
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 0x200;
  }
  puVar3 = *(uint **)(param_1 + 0xb8);
  lVar2 = 0;
  puVar5 = (uint *)((ulonglong)*(uint *)(param_1 + 0xc0) + (longlong)puVar3);
  for (; puVar3 + 8 <= puVar5; puVar3 = (uint *)((longlong)puVar3 + (ulonglong)*puVar3)) {
    lVar2 = lVar2 + (ulonglong)puVar3[2];
    if (*puVar3 == 0) break;
  }
  *(longlong *)(param_2 + 0x18) = lVar2;
  iVar1 = NtQuerySystemInformation(2,local_1a8,0x178,local_2a8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar4 = 0xd;
  }
  else {
    *(ulonglong *)(param_2 + 8) = (ulonglong)local_17c;
    uVar6 = 0x40;
    *(ulonglong *)(param_2 + 0x10) = (ulonglong)local_178;
    *(int *)(param_2 + 0x28) = local_148 - *(int *)(param_1 + 0xc4);
    *(int *)(param_1 + 0xc4) = local_148;
    iVar1 = NtQuerySystemInformation(0x15,local_298,0x40,local_2a8);
    if (-1 < iVar1) {
      *(int *)(param_2 + 0x2c) =
           ((*(int *)(param_1 + 200) - *(int *)(param_1 + 0xcc)) - local_158) + local_288;
      *(int *)(param_1 + 0xcc) = local_288;
      *(int *)(param_1 + 200) = local_158;
      if (*(uint *)(param_1 + 0xac) < 6) {
        local_250 = 0;
      }
      else {
        uVar6 = 0xb0;
        iVar1 = NtQuerySystemInformation(0x50,&local_258,0xb0,local_2a8);
        if (iVar1 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return iVar1;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return iVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return iVar1;
          }
          uVar4 = 0xf;
          goto LAB_140006f32;
        }
        local_250 = local_250 + local_258;
      }
      *(longlong *)(param_2 + 0x20) = local_250;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_IIIIDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),local_250,uVar6,
                      *(undefined8 *)(param_2 + 8),(char)*(undefined8 *)(param_2 + 0x10),
                      (char)*(undefined8 *)(param_2 + 0x18),(char)local_250,
                      (char)*(undefined4 *)(param_2 + 0x28),(char)*(undefined4 *)(param_2 + 0x2c));
      }
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar4 = 0xe;
  }
LAB_140006f32:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_9400fa280a7934e5b8edeb5038407bb5_Traceguids,iVar1);
  return iVar1;
}



===== DmcChannelCreate @ 14000e008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DmcChannelCreate(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  undefined8 local_res8;
  undefined4 local_38;
  undefined4 local_34;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_res8 = 0;
  local_10 = 0;
  local_20 = 0;
  uStack_18 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10))
  ;
  puVar4 = &local_res8;
  iVar1 = VmbChannelAllocate(uVar2,0);
  if (iVar1 < 0) {
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar4 = (undefined8 *)&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids;
      WPP_SF_D(puVar3,0x21,&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,iVar1);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0zq_EtwWriteTransfer
                (puVar3,&DMCLOG_OPERATION_FAILURE,puVar4,L"Create KMCL channel",(char)iVar1);
    }
    DmcChannelDestroy(param_1);
  }
  else {
    VmbChannelInitSuppressQueueManagement(local_res8,DmcEvtChannelSignalArrived);
    VmbClientChannelInitSetRingBufferPageCount(local_res8,2,2);
    local_10 = 0;
    local_30 = DmcEvtChannelOpened;
    local_38 = 1;
    local_28 = DmcEvtChannelClosed;
    local_20 = 0;
    uStack_18 = 0;
    local_34 = 0x30;
    VmbChannelInitSetStateChangeCallbacks(local_res8,&local_38);
    VmbChannelSetPointer(local_res8,param_1);
    *(undefined8 *)(param_1 + 8) = local_res8;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== DmcChannelDestroy @ 14000e1b0 =====

void DmcChannelDestroy(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    VmbChannelDisable();
    VmbChannelCleanup(*(undefined8 *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
  }
  return;
}



===== DmcEvtChannelClosed @ 14000e230 =====

void DmcEvtChannelClosed(void)

{
  longlong lVar1;
  
  lVar1 = VmbChannelGetPointer();
  ExAcquireFastMutex(lVar1 + 0x100);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  ExReleaseFastMutex(lVar1 + 0x100);
  PkUninitializeRingBuffer(lVar1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
            &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
  }
  return;
}



===== DmcEvtChannelOpened @ 14000e2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DmcEvtChannelOpened(undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int local_res10 [2];
  int local_res18 [2];
  longlong local_res20;
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  lVar1 = VmbChannelGetPointer();
  VmbChannelGetRingBuffer(param_1,local_28,local_res18,&local_res20,local_res10);
  uVar2 = PkInitializeRingBuffer
                    ((longlong *)(lVar1 + 0x40),local_28[0],local_28[0] + 0x1000,local_res18[0] + -1
                     ,local_res20,local_res20 + 0x1000,local_res10[0] + -1);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,(int)uVar2);
    }
  }
  else {
    LOCK();
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x18) = 1;
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,lVar1);
    DmcWorkerIoReady(uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== DmcEvtDeviceAdd @ 14000e420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DmcEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined *puVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined1 auStack_168 [32];
  char local_138 [8];
  longlong local_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  code *local_118;
  undefined8 uStack_110;
  longlong local_108;
  undefined8 uStack_100;
  undefined *local_f8;
  undefined8 local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  local_130 = 0;
  local_f8 = (undefined *)((ulonglong)local_f8 & 0xffffffff00000000);
  plVar8 = (longlong *)0x8c;
  local_c4 = 0;
  local_128 = 0;
  uStack_124 = 0;
  uStack_120 = 0;
  uStack_11c = 0;
  local_118 = (code *)0x0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_f0 = param_2;
  memset(&local_c8,0,0x8c);
  local_28 = 0;
  uStack_24 = 0;
  local_20 = 0;
  local_138[0] = '\0';
  local_38 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  if (*(int *)InitSafeBootMode_exref == 0) {
    memset(&local_c8,0,0x90);
    local_80 = DmcEvtDeviceSelfManagedIoInit;
    local_c8 = 0x90;
    local_78 = DmcEvtDeviceSelfManagedIoSuspend;
    local_70 = DmcEvtDeviceSelfManagedIoRestart;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,&local_c8);
    plVar8 = (longlong *)&local_128;
    local_f8 = PTR__WDF_DMC_DEVICE_CONTEXT_TYPE_INFO_14000b090;
    local_118 = (code *)0x0;
    uStack_124 = 0;
    uStack_120 = 0;
    uStack_11c = 0;
    local_128 = 0x38;
    local_108 = 0;
    uStack_100 = 0;
    uStack_110 = 0x100000001;
    uVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_f0,plVar8,&local_130);
    uVar7 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      plVar2 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_130,PTR__WDF_DMC_DEVICE_CONTEXT_TYPE_INFO_14000b090
                         );
      uStack_124 = 0;
      uStack_120 = 0;
      uStack_11c = 0;
      uStack_100 = 0;
      local_118 = DmcEvtDeviceWorkerDestroy;
      local_f8 = PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018;
      local_e0 = DmcEvtCommReceive;
      local_d8 = DmcEvtCommSend;
      local_108 = local_130;
      local_e8 = DmcEvtWorkerFailed;
      local_128 = 0x38;
      uStack_110 = 0x100000001;
      plVar8 = plVar2;
      uVar3 = DmcWorkerCreate((longlong *)&local_e8,(longlong)&local_128,plVar2,local_138);
      uVar7 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        puVar5 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e7d0;
        uVar6 = 0xd;
      }
      else {
        plVar4 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar2);
        plVar4[2] = local_130;
        *plVar4 = *plVar2;
        if (local_138[0] == '\0') {
          local_38 = 0x20000001c;
          uStack_2c = 2;
          local_28 = 2;
          uStack_24 = 2;
          local_20 = 2;
          uStack_30 = 1;
          (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,local_130);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
          }
        }
        plVar4[0x21] = 0;
        *(undefined4 *)(plVar4 + 0x22) = 0;
        plVar8 = (longlong *)0x0;
        *(undefined4 *)(plVar4 + 0x20) = 1;
        KeInitializeEvent(plVar4 + 0x23,1);
        uVar1 = DmcChannelCreate((longlong)plVar4);
        uVar7 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
          }
          return 0;
        }
        puVar5 = WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000e7d0;
        uVar6 = 0xf;
      }
      goto LAB_14000e7bd;
    }
    puVar5 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000e7d0;
    uVar6 = 0xc;
  }
  else {
    uVar7 = 0xc00000bb;
    puVar5 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_14000e7d0;
    uVar6 = 0xb;
LAB_14000e7bd:
    uVar1 = (uint)uVar7;
  }
  puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
  plVar8 = (longlong *)&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids;
  WPP_SF_D(puVar5,uVar6,&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,uVar1);
LAB_14000e7d0:
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
    McTemplateK0zq_EtwWriteTransfer
              (puVar5,&DMCLOG_OPERATION_FAILURE,plVar8,L"Add device",(char)uVar7);
  }
  return uVar7;
}



===== DmcEvtDeviceSelfManagedIoInit @ 14000e860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DmcEvtDeviceSelfManagedIoInit(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  undefined2 uVar5;
  undefined *puVar6;
  
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_CONTEXT_TYPE_INFO_14000b090);
  puVar6 = PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  iVar1 = VmbChannelEnable(*(undefined8 *)(lVar3 + 8));
  if (iVar1 < 0) {
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000e939;
    uVar5 = 0x11;
  }
  else {
    iVar1 = DmcWorkerStart(*puVar2);
    if (-1 < iVar1) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids);
      }
      return 0;
    }
    puVar4 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000e939;
    uVar5 = 0x12;
  }
  puVar4 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
  puVar6 = &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids;
  WPP_SF_D(puVar4,uVar5,&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,iVar1);
LAB_14000e939:
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
    McTemplateK0zq_EtwWriteTransfer
              (puVar4,&DMCLOG_OPERATION_FAILURE,puVar6,L"Start channel and worker",(char)iVar1);
  }
  return iVar1;
}



===== DmcEvtDeviceWorkerDestroy @ 14000e9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcEvtDeviceWorkerDestroy(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  DmcChannelDestroy(lVar1);
  return;
}



===== DmcEvtDriverCleanup @ 14000e9f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcEvtDriverCleanup(undefined8 param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  DmcTracingCleanup();
  return;
}



===== DmcEvtWorkerFailed @ 14000ea30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcEvtWorkerFailed(undefined8 param_1,int param_2)

{
  longlong lVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMC_DEVICE_WORKER_CONTEXT_TYPE_INFO_14000b018
                    );
  puVar4 = (undefined *)0x2;
  (**(code **)(WdfFunctions_01015 + 0x2b8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x10));
  puVar2 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar4 = &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids;
    WPP_SF_D(puVar2,0x16,&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,param_2);
  }
  if (param_2 == -0x3fffffa7) {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return;
    }
    puVar3 = &DMCLOG_REVISION_MISMATCH;
  }
  else if (param_2 == -0x3fffff45) {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return;
    }
    puVar3 = &DMCLOG_UNSUPPORTED_NESTED;
  }
  else if (param_2 == -0x3ffffd4a) {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return;
    }
    puVar3 = &DMCLOG_DEVICE_REMOVED;
  }
  else if (param_2 == -0x3fff5fed) {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return;
    }
    puVar3 = &DMCLOG_UNSUPPORTED_SKU;
  }
  else {
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) == 0) {
      return;
    }
    puVar3 = &DMCLOG_UNEXPECTED_FAILURE;
  }
  McTemplateK0_EtwWriteTransfer(puVar2,puVar3,puVar4);
  return;
}



===== DmcTracingCleanup @ 14000eb48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DmcTracingCleanup(void)

{
  undefined *puVar1;
  
  McGenEventUnregister_EtwUnregister();
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if ((int)WPPTraceSuite == 4) {
      for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
        if (*(longlong *)(puVar1 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar1 + 0x38) = 0;
        }
      }
    }
    else if ((int)WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 14000ebcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(void)

{
  code *pcVar1;
  undefined *puVar2;
  
  puVar2 = &WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if ((int)WPPTraceSuite == 4) {
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if ((int)WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppLoadTracingSupport @ 14000ec5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  _pfnWppGetVersion = (code *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite._0_4_ = 2;
  if (_pfnWppGetVersion != (code *)0x0) {
    (*_pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite._0_4_ = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 14000eda0 =====

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
          bVar13 = (int)WPPTraceSuite != 2;
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



===== DmcEnablePerformanceCounters @ 14000f028 =====

int DmcEnablePerformanceCounters(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_44 = 0;
  local_34 = 0;
  local_18 = 0;
  local_28 = 0;
  local_20 = 0;
  local_40 = &`DmvscPcInitRegistrationInformationChannel'::__l2::Name;
  local_30 = &`DmvscPcInitRegistrationInformationChannel'::__l2::Descriptors;
  local_38 = 1;
  local_48 = 0x100;
  iVar1 = PcwRegister(&DmvscPcChannel,&local_48);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar2 = 0x12;
  }
  else {
    local_58 = param_1 + 0x3118;
    local_50 = 8;
    iVar1 = PcwCreateInstance(param_1 + 0x3120,DmvscPcChannel,&DAT_14000b0d8,1,&local_58);
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar2 = 0x13;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar1);
  return iVar1;
}



===== DmcWorkerCreate @ 14000f16c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DmcWorkerCreate(longlong *param_1,longlong param_2,longlong *param_3,undefined1 *param_4)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  undefined1 auStack_228 [32];
  longlong *local_208;
  undefined8 local_200;
  longlong *local_1f8;
  longlong local_1f0;
  undefined8 local_1e8;
  longlong local_1e0 [2];
  code *pcStack_1d0;
  code *local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined *local_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined *local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined4 local_168;
  undefined4 local_164;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_228;
  local_1f8 = (longlong *)0x0;
  local_1f0 = 0;
  local_1a8 = (undefined *)((ulonglong)local_1a8 & 0xffffffff00000000);
  local_1e0[1] = 0;
  pcStack_1d0 = (code *)0x0;
  local_1c8 = (code *)0x0;
  uStack_1c0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  memset(&local_168,0,0x114);
  local_1e8 = 0;
  *param_3 = 0;
  *param_4 = 0;
  local_180 = 0;
  uStack_178 = (ulonglong)uStack_178._4_4_ << 0x20;
  local_1a0 = 0;
  uStack_198 = 0;
  local_190 = (undefined *)0x0;
  uStack_188 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,param_2,&local_1f0);
  uVar7 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000f619;
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar6 = 10;
  }
  else {
    local_1a8 = PTR__WDF_DMC_WORKER_CONTEXT_TYPE_INFO_14000b110;
    pcStack_1d0 = DmcEvtWorkerCleanup;
    local_1c8 = DmcEvtWorkerDestroy;
    local_1b8 = 0;
    uStack_1b0 = 0;
    local_1e0[1] = 0x38;
    uStack_1c0 = 0x100000001;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                      (WdfDriverGlobals,local_1f0,local_1e0 + 1,&local_1f8);
    uVar7 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14000f619;
      uVar6 = 0xb;
    }
    else {
      KeInitializeEvent(local_1f8 + 1,1,0);
      *local_1f8 = local_1f0;
      local_1f8[0x12] = *param_1;
      local_1f8[0x13] = param_1[1];
      local_1f8[0x14] = param_1[2];
      local_168 = 0x114;
      uVar2 = RtlGetVersion(&local_168);
      uVar7 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000f619;
        uVar6 = 0xc;
      }
      else {
        *(undefined4 *)((longlong)local_1f8 + 0xac) = local_164;
        uVar3 = DmcDetectMemoryCapabilities(local_1f8 + 0xd);
        uVar7 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000f619;
          uVar6 = 0xd;
        }
        else {
          *(undefined1 *)((longlong)local_1f8 + 0xb1) = 0;
          uStack_198 = 0;
          local_190 = &DAT_14000b0e8;
          local_1a0 = CONCAT44(local_1a0._4_4_,0x30);
          uStack_188 = CONCAT44(uStack_188._4_4_,0x240);
          local_180 = 0;
          uStack_178 = 0;
          uVar2 = ZwOpenEvent(&local_1e8,1,&local_1a0);
          plVar1 = local_1f8;
          uVar7 = (ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000f619;
            uVar6 = 0xe;
          }
          else {
            local_200 = 0;
            local_208 = local_1e0;
            local_1e0[0] = 0;
            ObReferenceObjectByHandle(local_1e8,1,0,0);
            plVar1[0x625] = local_1e0[0];
            ZwClose(local_1e8);
            uVar2 = DmcEnablePerformanceCounters((longlong)local_1f8);
            uVar7 = (ulonglong)uVar2;
            if ((int)uVar2 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000f619;
              uVar6 = 0xf;
            }
            else {
              KeInitializeEvent(local_1f8 + 5,1,1);
              uVar4 = (**(code **)(WdfFunctions_01015 + 0x108))
                                (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x20));
              lVar5 = IoAllocateWorkItem(uVar4);
              if (lVar5 != 0) {
                local_1f8[8] = lVar5;
                *param_3 = local_1f0;
                local_1f0 = 0;
                *param_4 = *(undefined1 *)((longlong)local_1f8 + 0x79);
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                          &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
                }
                uVar7 = 0;
                goto LAB_14000f619;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000f619;
              uVar6 = 0x10;
            }
          }
        }
      }
    }
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  WPP_SF_D(uVar4,uVar6,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,(int)uVar7);
LAB_14000f619:
  if (local_1f0 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar7;
}



===== DmcWorkerStart @ 14000f668 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DmcWorkerStart(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res10 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  *(undefined4 *)(lVar2 + 0x20) = 0;
  *(undefined4 *)(lVar2 + 0x24) = 0;
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_1,0,0x2a3,"onecore\\vm\\dv\\dm\\vsc\\lib\\worker.c");
  iVar1 = PsCreateSystemThread(&local_res10,0,0,0,0,DmcThread,param_1);
  if (iVar1 < 0) {
    puVar4 = (undefined *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,param_1,0,0x2b5,"onecore\\vm\\dv\\dm\\vsc\\lib\\worker.c");
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar4 = &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids;
      WPP_SF_D(puVar3,0x14,&WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids,iVar1);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0zq_EtwWriteTransfer
                (puVar3,&DMCLOG_OPERATION_FAILURE,puVar4,L"Create worker thread",(char)iVar1);
    }
  }
  else {
    local_res18[0] = 0;
    ObReferenceObjectByHandle(local_res10,0,*(undefined8 *)PsThreadType_exref,0,local_res18,0);
    ZwClose(local_res10);
    *(undefined8 *)(lVar2 + 0x88) = local_res18[0];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_bda3c2bb15fa3173c01334032bf352c1_Traceguids);
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== DmcDetectMemoryCapabilities @ 14000f84c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DmcDetectMemoryCapabilities(longlong *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  ulonglong uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined1 auStackY_128 [32];
  uint local_c8 [4];
  undefined8 local_b8;
  wchar_t *local_b0;
  undefined8 local_a8;
  wchar_t *local_a0;
  ulonglong local_90 [3];
  undefined1 local_78 [6];
  char local_72;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_128;
  local_a8 = 0x2e002c;
  *param_1 = 0;
  param_1[1] = 0;
  local_b8 = 0x3e003c;
  local_a0 = L"Kernel-MaxPhysicalPage";
  param_1[2] = 0;
  param_1[3] = 0;
  local_b0 = L"Kernel-WindowsMaxMemAllowedx64";
  memset(local_78,0,0x4c);
  local_c8[2] = 0;
  local_c8[0] = 0;
  *(undefined2 *)((longlong)param_1 + 0x13) = 0x101;
  *param_1 = 0xfffffffffffff;
  *(undefined1 *)((longlong)param_1 + 0x15) = 1;
  local_c8[1] = 4;
  iVar1 = ZwQueryLicenseValue(&local_b8,local_c8 + 2,local_c8,4);
  if ((iVar1 < 0) || (uVar4 = (ulonglong)local_c8[0], local_c8[0] == 0)) {
    local_c8[1] = 4;
    iVar1 = ZwQueryLicenseValue(&local_a8,local_c8 + 2,local_c8,4);
    uVar4 = (ulonglong)local_c8[0];
    if ((-1 < iVar1) && (local_c8[0] != 0)) goto LAB_14000f963;
    puVar7 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar4 = *(ulonglong *)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dD(uVar4,10,WPP_GLOBAL_Control,iVar1,(char)local_c8[0]);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0zq_EtwWriteTransfer
                (uVar4,&DMCLOG_OPERATION_FAILURE,puVar7,L"Query license limit",(char)iVar1);
    }
  }
  else {
LAB_14000f963:
    *param_1 = uVar4 * 0x100 + -1;
  }
  *(undefined2 *)((longlong)param_1 + 0x11) = 0;
  puVar7 = (undefined *)0x0;
  uVar4 = 0;
  iVar1 = ZwPowerInformation(4,0,0,local_78);
  if (iVar1 < 0) {
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (uVar4 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
        (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar7 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
      uVar4 = 0xb;
      WPP_SF_D(puVar3,0xb,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,iVar1);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0q_EtwWriteTransfer(puVar3,uVar4,puVar7,iVar1);
    }
  }
  else if (local_72 == '\0') {
    local_90[0] = 0;
    local_90[1] = 0;
    HviGetHypervisorFeatures(local_90);
    if ((local_90[0] >> 0x2c & 1) != 0) {
      local_90[0] = 0;
      local_90[1] = 0;
      HviGetEnlightenmentInformation(local_90);
      if ((local_90[0] & 0x1000) != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar7 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                  &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
        }
        goto LAB_14000faf2;
      }
    }
    *(undefined2 *)((longlong)param_1 + 0x11) = 0x101;
  }
  else {
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar7 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
      WPP_SF_(puVar3,0xc,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 4) != 0) {
      McTemplateK0_EtwWriteTransfer
                (puVar3,&DMCLOG_S4_SYSTEM_STATE_HOT_ADD_REMOVE_UNSUPPORTED,puVar7);
    }
  }
LAB_14000faf2:
  uVar2 = DmcpQueryNumaNodeCount((ulonglong *)(param_1 + 3));
  if ((int)uVar2 < 0) {
    puVar3 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar7 = &WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids;
      WPP_SF_D(puVar3,0xe,&WPP_ac10446a00c73cfee751e9693afb06f4_Traceguids,(int)uVar2);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0zq_EtwWriteTransfer
                (puVar3,&DMCLOG_OPERATION_FAILURE,puVar7,L"Query NUMA node count",(char)uVar2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar6 = "true";
    pcVar11 = "true";
    if (*(char *)((longlong)param_1 + 0x15) == '\0') {
      pcVar11 = "false";
    }
    pcVar10 = "true";
    pcVar9 = "true";
    if (*(char *)((longlong)param_1 + 0x14) == '\0') {
      pcVar10 = "false";
    }
    pcVar8 = "true";
    pcVar5 = "true";
    if (*(char *)((longlong)param_1 + 0x13) == '\0') {
      pcVar9 = "false";
    }
    if (*(char *)((longlong)param_1 + 0x12) == '\0') {
      pcVar8 = "false";
    }
    if (*(char *)((longlong)param_1 + 0x11) == '\0') {
      pcVar5 = "false";
    }
    if ((char)param_1[2] == '\0') {
      pcVar6 = "false";
    }
    WPP_SF_iIssssssI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar5,pcVar8,*param_1,
                     (char)param_1[1],pcVar6,pcVar5,pcVar8,pcVar9,pcVar10,pcVar11,(char)param_1[3]);
  }
  if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 4) != 0) {
    McTemplateK0ixtttttt_EtwWriteTransfer
              ((ulonglong)*(byte *)((longlong)param_1 + 0x14),
               (ulonglong)*(byte *)((longlong)param_1 + 0x13),
               (ulonglong)*(byte *)((longlong)param_1 + 0x12),*param_1,(char)param_1[1],
               (char)param_1[2],*(undefined1 *)((longlong)param_1 + 0x11),
               *(byte *)((longlong)param_1 + 0x12),*(byte *)((longlong)param_1 + 0x13),
               *(byte *)((longlong)param_1 + 0x14),*(undefined1 *)((longlong)param_1 + 0x15));
  }
  return 0;
}



===== __security_init_cookie @ 140010008 =====

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



===== DriverEntry @ 14001003c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 local_res18;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  code *pcStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_68 = 0x20;
  local_res18 = 0;
  local_18 = 0;
  pcStack_40 = DmcEvtDriverCleanup;
  local_38 = 0;
  local_48 = 0x38;
  local_60 = DmcEvtDeviceAdd;
  DAT_14000b488 = &WPP_ThisDir_CTLGUID_DmVscTraceGuid;
  local_28 = 0;
  uStack_20 = 0;
  uStack_30 = 0x100000001;
  local_58 = 0;
  local_50 = 0;
  local_4c = 0x574d4476;
  _WPP_MAIN_CB = 0;
  DAT_14000b490 = 0;
  _DAT_14000b4a0 = 0;
  _DAT_14000b4a8 = 1;
  WppLoadTracingSupport();
  _DAT_14000b4a0 = 0;
  WppInitKm();
  McGenEventRegister_EtwRegister();
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_48,&local_68,&local_res18);
  if (iVar1 < 0) {
    puVar2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      param_2 = &WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids;
      WPP_SF_D(puVar2,10,&WPP_ab82e7143ca83409bf464b3e0bbfcdae_Traceguids,iVar1);
    }
    if ((Microsoft_Windows_Hyper_V_Guest_Drivers_Dynamic_MemoryEnableBits & 1) != 0) {
      McTemplateK0zq_EtwWriteTransfer
                (puVar2,&DMCLOG_OPERATION_FAILURE,param_2,L"Create driver",(char)iVar1);
    }
    DmcTracingCleanup();
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


