
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



===== __report_rangecheckfailure @ 140001020 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000102d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000102d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== SetXdvKernelUtilities @ 140001040 =====

void SetXdvKernelUtilities
               (undefined8 *param_1,undefined8 *param_2,undefined1 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
                    /* 0x1040  2  SetXdvKernelUtilities */
  VfOptionFlags = (undefined4)param_4;
  XdvRuleClasses = *param_2;
  puVar2 = &DAT_14003245c;
  lVar3 = 3;
  XdvGetDriverName = *param_1;
  XdvGetDriverSigningLevel = param_1[1];
  XdvIsBootDriver = param_1[2];
  XdvGetPristineDriverUnloadRoutine = param_1[5];
  DifIsRuleClassEnabled = param_1[8];
  DifIsRunningInXBox = param_1[9];
  CarDeletePluginRuleViolations = param_1[10];
  DifGetVerifiedDriverCount = param_1[0xb];
  DifGetDriverImageSize = param_1[0xc];
  DifGetDriverBaseAddress = param_1[0xd];
  DifCallPluginEntry = param_1[0xf];
  CarIsOnecheckEnabled = param_1[0x10];
  XdvStateSeparationEnabled = param_3;
  do {
    uVar1 = CarRegisterDefaultRuleClassConfiguration(puVar2[-2],puVar2[-3]);
    if ((int)uVar1 < 0) {
      XdvUtilDbgPrint("Failed to register rule class %d for reporting. NTSTATUS code: 0x%x",
                      (ulonglong)XdvRules,(ulonglong)uVar1,param_4);
    }
    else {
      CarSetCustomRuleIdRange(puVar2[-3],puVar2[-1],*puVar2);
    }
    puVar2 = puVar2 + 4;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== XdvHibernationNotification @ 140001160 =====

void XdvHibernationNotification(undefined1 param_1)

{
                    /* 0x1160  3  XdvHibernationNotification */
  XdvHiberState = param_1;
  return;
}



===== XdvIsTipOn @ 140001170 =====

uint XdvIsTipOn(void)

{
  return XdvVerifierOptions & 0x10000;
}



===== XdvQueryDispatchTable @ 140001190 =====

undefined * XdvQueryDispatchTable(int param_1,uint param_2)

{
  undefined *puVar1;
  
                    /* 0x1190  5  XdvQueryDispatchTable */
  puVar1 = (undefined *)0x0;
  if (param_1 == 2) {
    puVar1 = &VfNdisDispatchTable;
    if (DAT_140032014 < param_2) {
      puVar1 = (undefined *)0x0;
    }
  }
  else if ((param_1 == 4) && (param_2 <= DAT_140032004)) {
    return &DifHvciDispatchTable;
  }
  return puVar1;
}



===== XdvControlPlugins @ 1400011d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 XdvControlPlugins(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong *plVar7;
  
  uVar6 = 0;
  uVar4 = 0xc0000010;
  if (DifIsRuleClassEnabled == (code *)0x0) {
    uVar4 = 0xc00000bb;
  }
  else {
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (uVar1 == 0x10002004) {
      uVar5 = 0;
      if (((*(char *)(param_2 + 0x40) == '\0') &&
          (*(undefined8 **)(param_2 + 0x18) != (undefined8 *)0x0)) &&
         (7 < *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10))) {
        uVar4 = 0;
        *(undefined **)**(undefined8 **)(param_2 + 0x18) = &XdvExportTable;
        uVar5 = 8;
      }
      *(undefined4 *)(param_2 + 0x30) = uVar4;
      *(undefined8 *)(param_2 + 0x38) = uVar5;
      IofCompleteRequest(param_2,0);
    }
    else {
      plVar7 = &DAT_1400320e0;
      do {
        if (((DifIsRuleClassEnabled != (code *)0x0) &&
            (cVar3 = (*DifIsRuleClassEnabled)((int)plVar7[-1]), cVar3 != '\0')) &&
           ((lVar2 = *plVar7, lVar2 != 0 &&
            ((*(code **)(lVar2 + 0x10) != (code *)0x0 && (*(uint *)(lVar2 + 0x20) == uVar1 >> 0x10))
            )))) {
          uVar4 = (**(code **)(lVar2 + 0x10))(param_2);
          break;
        }
        uVar6 = uVar6 + 1;
        plVar7 = plVar7 + 5;
      } while (uVar6 < 0xc);
    }
  }
  return uVar4;
}



===== XdvDispatchCreate @ 1400012e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint XdvDispatchCreate(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  short sVar5;
  undefined1 local_18 [16];
  
  local_18 = *(undefined1 (*) [16])(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x58);
  sVar5 = local_18._0_2_;
  if (sVar5 != 0) {
    if (*(short *)local_18._8_8_ != 0x5c) {
      uVar4 = 0xc000003b;
      goto LAB_1400013e2;
    }
    if (sVar5 != 2) {
      plVar2 = &DAT_1400320e0;
      local_18._8_8_ = (short *)(local_18._8_8_ + 2);
      lVar3 = 0;
      uVar4 = 0;
      local_18._0_2_ = sVar5 + -2;
      do {
        if (DifIsRuleClassEnabled != (code *)0x0) {
          cVar1 = (*DifIsRuleClassEnabled)((int)plVar2[-1]);
          if (cVar1 != '\0') {
            cVar1 = RtlEqualUnicodeString
                              (local_18,&PluginEntryCollection + (ulonglong)uVar4 * 0x28,1);
            if (cVar1 != '\0') {
              lVar3 = *plVar2;
            }
          }
        }
        uVar4 = uVar4 + 1;
        plVar2 = plVar2 + 5;
      } while (uVar4 < 0xc);
      uVar4 = ~-(uint)(lVar3 != 0) & 0xc0000225;
      goto LAB_1400013e2;
    }
  }
  uVar4 = 0;
  *(undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) =
       *(undefined8 *)(param_1 + 0x40);
LAB_1400013e2:
  *(uint *)(param_2 + 0x30) = uVar4;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== XdvInsertPluginObject @ 140001420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvInsertPluginObject(int param_1,undefined8 param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ((DifIsRunningInXBox != (code *)0x0) && (cVar1 = (*DifIsRunningInXBox)(), cVar1 == '\0')) {
    piVar2 = &DAT_1400320d8;
    do {
      if (param_1 == *piVar2) {
        (&DAT_1400320e0)[(ulonglong)uVar3 * 5] = param_2;
        return;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 10;
    } while (uVar3 < 0xc);
  }
  return;
}



===== XdvLoadDifPlugins @ 140001490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 XdvLoadDifPlugins(void)

{
  char cVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
                    /* 0x1490  4  XdvLoadDifPlugins */
  if ((((DifIsRunningInXBox == (code *)0x0) || (cVar1 = (*DifIsRunningInXBox)(), cVar1 != '\0')) ||
      (DifIsRuleClassEnabled == (code *)0x0)) || (DifCallPluginEntry == (code *)0x0)) {
    return 0xc00000bb;
  }
  puVar2 = &DAT_1400320d8;
  lVar3 = 0xc;
  do {
    if ((DifIsRuleClassEnabled != (code *)0x0) &&
       (cVar1 = (*DifIsRuleClassEnabled)(*puVar2), cVar1 != '\0')) {
      (*DifCallPluginEntry)(*puVar2,*(undefined8 *)(puVar2 + -2));
    }
    puVar2 = puVar2 + 10;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return 0;
}



===== XdvRemovePluginObject @ 140001520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 XdvRemovePluginObject(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar5 = 0;
  uVar3 = 0;
  if ((DifIsRunningInXBox == (code *)0x0) || (cVar1 = (*DifIsRunningInXBox)(), cVar1 != '\0')) {
    uVar3 = 0;
  }
  else {
    piVar2 = &DAT_1400320d8;
    do {
      if (param_1 == *piVar2) {
        uVar3 = (&DAT_1400320e0)[uVar5 * 5];
        (&DAT_1400320e0)[uVar5 * 5] = 0;
        break;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      piVar2 = piVar2 + 10;
    } while (uVar4 < 0xc);
  }
  return uVar3;
}



===== XdvCleanup @ 140001594 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvCleanup(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  longlong *plVar3;
  undefined4 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  DAT_1400323d0 = DAT_1400323d0 + 1;
  uVar6 = (ulonglong)DAT_1400323d0;
  if (DAT_1400323d0 == DAT_1400323d4) {
    DAT_1400323d4 = DAT_1400323d4 * 2;
    param_2 = PTR_s_XdvTimedCleanup_1400323d8;
    XdvUtilDbgPrint("Driver Verifier: Counter: %s: %d\n",PTR_s_XdvTimedCleanup_1400323d8,uVar6,
                    param_4);
  }
  uVar2 = 0;
  do {
    cVar1 = XdvTimedStopExtension(uVar2);
    if (cVar1 == '\0') {
      param_2 = (undefined *)(ulonglong)uVar2;
      XdvUtilDbgPrint("Driver Verifier: Failed to stop XdvTimed extension: %d\n",param_2,uVar6,
                      param_4);
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 5);
  KeFlushQueuedDpcs();
  if (XdvTimerWorkItem != 0) {
    IoUninitializeWorkItem(XdvTimerWorkItem);
    IoFreeWorkItem(XdvTimerWorkItem);
    XdvTimerWorkItem = 0;
  }
  XdvUtilDbgPrint("Driver Verifier: XdvTimed extension stopped.\n",param_2,uVar6,param_4);
  plVar3 = &DAT_1400320e0;
  lVar5 = 0xc;
  do {
    if (*plVar3 != 0) {
      (**(code **)(*plVar3 + 0x18))();
      *plVar3 = 0;
    }
    plVar3 = plVar3 + 5;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  McGenEventUnregister_EtwUnregister();
  puVar4 = &XdvRules;
  lVar5 = 3;
  do {
    CarDeregisterRuleClassConfiguration(*puVar4);
    puVar4 = puVar4 + 4;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if (XdvLookasideStore != 0) {
    ExFreePoolWithTag();
    XdvLookasideStore = 0;
  }
  if (DAT_140032a08 != 0) {
    ExFreePoolWithTag();
    DAT_140032a08 = 0;
  }
  if (DAT_140032a28 != 0) {
    ExFreePoolWithTag();
  }
  memset(&XdvRegistryKeys,0,0x50);
  return;
}



===== XdvInitialize @ 140001724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong XdvInitialize(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ushort uVar8;
  longlong *plVar9;
  undefined2 *_Dst;
  uint uVar10;
  longlong lVar11;
  wchar_t *_Src;
  code *pcVar12;
  undefined1 auStack_118 [32];
  undefined8 local_d8;
  undefined8 uStack_d0;
  wchar_t local_c8 [88];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  builtin_wcsncpy(local_c8,
                  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management"
                  ,0x55);
  uVar7 = 0;
  _Src = local_c8;
  iVar3 = RtlGetPersistedStateLocation(L"DriverVerifier",0);
  if (iVar3 < 0) {
    _Src = local_c8;
    wcscpy_s((wchar_t *)&XdvRegistryRoot,0x104,_Src);
  }
  if ((DifIsRunningInXBox != (code *)0x0) && (cVar2 = (*DifIsRunningInXBox)(), cVar2 == '\0')) {
    plVar9 = &DAT_1400320e0;
    lVar11 = 0xc;
    do {
      if ((((DifIsRuleClassEnabled != (code *)0x0) &&
           (cVar2 = (*DifIsRuleClassEnabled)(), cVar2 != '\0')) && (*plVar9 != 0)) &&
         (pcVar12 = *(code **)(*plVar9 + 8), pcVar12 != (code *)0x0)) {
        (*pcVar12)();
      }
      plVar9 = plVar9 + 5;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
  }
  if (XdvDispatch == 0) {
    uVar6 = 0x20;
    XdvDispatch = VfQueryDispatchTable();
    if (XdvDispatch == 0) {
      XdvUtilDbgPrint("Driver Verifier: Failed to query dispatch table!\n",uVar6,_Src,uVar7);
    }
  }
  XdvReadRegistry();
  local_d8 = 0;
  uStack_d0 = 0;
  uVar8 = (ushort)(XdvVerifierOptions >> 0xc) & 0xf;
  if ((XdvVerifierOptions >> 0xc & 0xf) != 0) {
    if (uVar8 == 1) goto LAB_140001944;
    uVar8 = uVar8 - 1;
    uVar10 = XdvVerifierOptions >> 0x18 & 0x3f;
    if (uVar8 == 1) {
      RtlInitUnicodeString(&local_d8,L"VerifierOptions");
      bVar1 = XdvWriteRegistryKeyDword((longlong)&local_d8,DAT_140032a14 & 0x801 | 0x10);
      if (!bVar1) goto LAB_140001944;
    }
    if ((XdvVerifierOptions & 0x80) == 0) {
      if (uVar10 == 0) {
        cVar2 = '\0';
        uVar10 = 0;
      }
      else {
        cVar2 = '\x01';
      }
LAB_14000193b:
      cVar2 = XdvUpdateRegistryWithDurationAndBootCount(uVar10,uVar8,cVar2);
      if (cVar2 != '\0') goto LAB_140001979;
    }
    else if (DAT_140032a44 == 0) {
      if (1 < uVar10) {
        uVar10 = uVar10 - 1;
        cVar2 = '\x01';
        goto LAB_14000193b;
      }
    }
    else {
      uVar10 = (uint)(_DAT_fffff78000000014 / 600000000);
      if ((uVar10 < DAT_140032a44) && (uVar10 = DAT_140032a44 - uVar10, 0x59f < uVar10)) {
        uVar10 = uVar10 / 0x5a0;
        cVar2 = '\0';
        goto LAB_14000193b;
      }
    }
LAB_140001944:
    RtlInitUnicodeString(&local_d8,L"VerifierOptions");
    XdvWriteRegistryKeyDword((longlong)&local_d8,0x10);
    XdvTipCleanRegistry(XdvVerifierOptions._2_1_ & 1);
  }
LAB_140001979:
  XdvTimedFactor = DAT_140032a34;
  if ((XdvVerifierOptions >> 0x10 & 1) == 0) {
    if (DAT_140032a34 == 0) goto LAB_140001a2a;
  }
  else {
    XdvTimedFactor = 0x442;
  }
  XdvMultiplyTimedFactor();
LAB_140001a2a:
  XdvLookasideStore = (void *)ExAllocatePool2(0x40,0x200,0x55766458);
  if (XdvLookasideStore == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    memset(XdvLookasideStore,0,0x200);
    XdvExportTableInitialize();
    if ((DAT_140032a28 != (wchar_t *)0x0) && (DAT_140032a30 != 0)) {
      XdvParseSuppressionKey(DAT_140032a28);
    }
    if ((_XdvRegistryKeys & 0x200000) != 0) {
      XdvDefaultSuppression(0x9400b);
    }
    if ((_XdvRegistryKeys >> 0x10 & 1) != 0) {
      XdvDefaultSuppression(0x82001);
      XdvDefaultSuppression(0x82002);
      XdvDefaultSuppression(0x82003);
      XdvDefaultSuppression(0x82004);
      XdvDefaultSuppression(0x82005);
    }
    _Dst = &AutofailSavedRegistryString;
    if (XdvDeviceObject != 0) {
      XdvTimerWorkItem = IoAllocateWorkItem();
    }
    do {
      _Dst = _Dst + -0xd0;
      pcVar12 = (code *)0x1a0;
      uVar7 = 0;
      puVar5 = _Dst;
      memset(_Dst,0,0x1a0);
    } while (_Dst != (undefined2 *)&XdvTimedExtensions);
    if (((uint)XdvRuleClasses & 0x220000) != 0) {
      pcVar12 = XdvNdisTimedCallback;
      uVar7 = 1000;
      puVar5 = (undefined2 *)0x2;
      XdvTimedStartExtension(2,1000,0x14000c250,XdvRuleId2TimedLimit,0);
    }
    uVar4 = McGenEventRegister_EtwRegister();
    if (-1 < (int)uVar4) {
      if ((Microsoft_Windows_Kernel_XDVEnableBits & 1) == 0) {
        uVar4 = 0;
      }
      else {
        uVar10 = McTemplateK0_EtwWriteTransfer(puVar5,uVar7,pcVar12);
        uVar4 = (ulonglong)uVar10;
      }
      if ((-1 < (int)uVar4) && (DifCallPluginEntry != (code *)0x0)) {
        (*DifCallPluginEntry)(0xf,DifPowerDelayPluginEntry);
        (*DifCallPluginEntry)(0x17,DifSyncDelayPluginEntry);
      }
    }
  }
  return uVar4;
}



===== XdvUpdateRegistryWithDurationAndBootCount @ 140001be4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void XdvUpdateRegistryWithDurationAndBootCount(int param_1,ushort param_2,char param_3)

{
  uint uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar1 = (uint)param_2 << 0xc | XdvVerifierOptions & 0xffff0fff;
  local_18 = 0;
  uStack_10 = 0;
  if (param_3 != '\0') {
    uVar1 = uVar1 | 0x80;
    DAT_140032a44 = (int)(_DAT_fffff78000000014 / 600000000) + param_1 * 0x5a0;
    RtlInitUnicodeString(&local_18,L"XdvTipStopTime");
    XdvWriteRegistryKeyDword((longlong)&local_18,DAT_140032a44);
  }
  if (param_1 - 1U < 0x3f) {
    uVar1 = uVar1 & 0xc0ffffff | param_1 << 0x18;
  }
  RtlInitUnicodeString(&local_18,L"XdvVerifierOptions");
  XdvWriteRegistryKeyDword((longlong)&local_18,uVar1);
  return;
}



===== wil_details_RecordCachedUsage @ 140001cbc =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001e10 =====

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



===== SLIC_StatefulAbort @ 140001ea0 =====

void SLIC_StatefulAbort(undefined8 param_1,uint param_2,int *param_3,longlong *param_4,
                       longlong *param_5,uint param_6)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong *local_98 [2];
  undefined8 local_88;
  int *local_80;
  longlong *local_78;
  
  uVar9 = 0;
  uVar5 = 0;
  lVar8 = 0;
  uVar7 = 0x58;
  memset(&local_88,0,0x58);
  iVar3 = CarInitializeRuleViolationDetails(&local_88);
  if (iVar3 < 0) {
    return;
  }
  if (param_3 != (int *)0x0) {
    uVar9 = *(undefined8 *)(param_3 + 4);
  }
  if ((param_5 != (longlong *)0x0) && (param_4 != (longlong *)0x0)) {
    lVar8 = param_4[3];
  }
  uVar6 = 4;
  if ((((byte)DAT_140032a4c & 4) != 0) &&
     (uVar5 = param_1, uVar7 = uVar9, uVar4 = XdvDoTimedDebug(param_2,param_1,uVar9,lVar8),
     (char)uVar4 != '\0')) {
    return;
  }
  local_88 = param_1;
  local_80 = param_3;
  local_78 = param_4;
  uVar4 = XdvQueryRuleSuppression(param_2,uVar5,uVar7);
  bVar2 = true;
  if ((char)uVar4 == '\0') {
    if (*(int *)(*(longlong *)(param_3 + 2) + 0x10) == 2) {
      if (param_2 < 0x40004) {
LAB_140002151:
        uVar6 = 0;
      }
      else if (param_2 < 0x92012) {
        if (param_2 == 0x92011) {
          uVar6 = 0x80;
        }
        else if (param_2 < 0x91003) {
          if (param_2 == 0x91002) {
            uVar6 = 2;
          }
          else {
            if ((((param_2 == 0x40007) || (param_2 == 0x4000a)) || (param_2 == 0x4100b)) ||
               ((param_2 == 0x43006 || (param_2 != 0x91001)))) goto LAB_140002151;
            uVar6 = 1;
          }
        }
        else if (param_2 != 0x9100e) {
          if (param_2 == 0x92003) {
            uVar6 = 8;
          }
          else if (param_2 == 0x9200d) {
            uVar6 = 0x10;
          }
          else if (param_2 == 0x9200f) {
            uVar6 = 0x20;
          }
          else {
            if (param_2 != 0x92010) goto LAB_140002151;
            uVar6 = 0x40;
          }
        }
      }
      else if (param_2 < 0x94008) {
        if (param_2 == 0x94007) {
          uVar6 = 0x2000;
        }
        else if (param_2 == 0x92012) {
          uVar6 = 0x100;
        }
        else if (param_2 == 0x93004) {
          uVar6 = 0x200;
        }
        else if (param_2 == 0x93005) {
          uVar6 = 0x400;
        }
        else if (param_2 == 0x93006) {
          uVar6 = 0x800;
        }
        else {
          if (param_2 != 0x93101) goto LAB_140002151;
          uVar6 = 0x1000;
        }
      }
      else if (param_2 == 0x94008) {
        uVar6 = 0x4000;
      }
      else if (param_2 == 0x94009) {
        uVar6 = 0x8000;
      }
      else if (param_2 == 0x9400b) {
        uVar6 = 0x10000;
      }
      else {
        if (param_2 != 0x9400c) goto LAB_140002151;
        uVar6 = 0x20000;
      }
      if ((*(ulonglong *)(*(longlong *)(param_3 + 2) + 0x50) & uVar6) != 0) goto LAB_140002182;
    }
    bVar1 = false;
    bVar2 = false;
    if ((XdvVerifierOptions & 8) == 0) goto LAB_1400021d5;
  }
LAB_140002182:
  bVar1 = bVar2;
  local_98[0] = param_4;
  if (param_4 != (longlong *)0x0) {
    if (param_5 == (longlong *)0x0) {
      if (param_6 != 0) {
        if (*param_3 == 2) {
          XdvNdisCleanStateQueueFields(param_2,param_4);
        }
        memset(param_4,0,(ulonglong)param_6);
      }
    }
    else {
      FreeWatchedState((longlong *)local_98,*(uint *)(param_4 + 2),param_5);
    }
  }
LAB_1400021d5:
  param_3[0xc] = 0;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  param_3[0xf] = 0;
  param_3[0x10] = 0;
  param_3[0x11] = 0;
  if (bVar1) {
    XdvUtilDbgPrint("Driver Verifier: Bugcheck suppressed with Error Code: 0x%X Error String: \'%s\'\nContext Object (IRP or Miniport): 0x%p\nTracked Object (OID, Port number, IRP, etc.): 0x%p\n"
                    ,(ulonglong)param_2,param_1,uVar9);
  }
  else {
    XdvUtilDbgPrint("Driver Verifier: Violation reported with Error Code: 0x%X Error String: \'%s\'\nContext Object (IRP or Miniport): 0x%p\nTracked Object (OID, Port number, IRP, etc.): 0x%p\n"
                    ,(ulonglong)param_2,param_1,uVar9);
    CarReportDifPluginRuleViolation(0x40,param_2,0,&local_88,lVar8);
  }
  return;
}



===== XdvIsRuleIdInXdvDebugRules @ 140002250 =====

ulonglong XdvIsRuleIdInXdvDebugRules(uint param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(DAT_140032a48 >> 8);
  if (DAT_140032a48 != 0) {
    if (param_1 == DAT_140032a48) {
      return CONCAT71((uint7)uVar1,1);
    }
    if ((DAT_140032a48 & 0xfff) == 0) {
      return (ulonglong)CONCAT31(uVar1,((param_1 ^ DAT_140032a48) & 0xff000) == 0);
    }
  }
  return (ulonglong)(uint7)uVar1 << 8;
}



===== XdvNdisCleanStateQueueFields @ 140002280 =====

void XdvNdisCleanStateQueueFields(int param_1,longlong *param_2)

{
  longlong *plVar1;
  
  if ((param_1 == 0x9200d) || (param_1 == 0x9200f)) {
    plVar1 = param_2 + 2;
  }
  else {
    if ((param_1 != 0x92011) && (param_1 != 0x92012)) {
      return;
    }
    XdvNdisDataClean(param_2);
    plVar1 = param_2 + 1;
  }
  XdvNdisDataClean(plVar1);
  return;
}



===== XdvReadRegistry @ 1400022c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong XdvReadRegistry(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint *puVar5;
  int iVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"VerifyDriverLevel");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,(undefined4 *)&XdvRegistryKeys);
  iVar6 = 0;
  if ((char)uVar3 == '\0') {
    _XdvRegistryKeys = 0;
  }
  RtlInitUnicodeString(&local_18,L"VerifyDrivers");
  uVar3 = XdvReadRegistryKeyString((longlong)&local_18,&DAT_140032a08,(int *)&DAT_140032a10);
  if ((char)uVar3 == '\0') {
    _DAT_140032a10 = 0;
    DAT_140032a08 = 0;
  }
  RtlInitUnicodeString(&local_18,L"VerifierOptions");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a14);
  if ((char)uVar3 == '\0') {
    DAT_140032a14 = 0;
  }
  RtlInitUnicodeString(&local_18,L"VerifierTriageContext");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,(undefined4 *)&DAT_140032a18);
  if ((char)uVar3 == '\0') {
    _DAT_140032a18 = 1;
  }
  RtlInitUnicodeString(&local_18,L"XdvVerifierOptions");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a20);
  if ((char)uVar3 == '\0') {
    DAT_140032a20 = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvExtensionOption");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a1c);
  if ((char)uVar3 == '\0') {
    DAT_140032a1c = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvTimedFactor");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a34);
  if ((char)uVar3 == '\0') {
    DAT_140032a34 = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvPersistDisableRule");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,(undefined4 *)&DAT_140032a38);
  if ((char)uVar3 == '\0') {
    _DAT_140032a38 = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvRuleSuppress");
  uVar3 = XdvReadRegistryKeyString((longlong)&local_18,&DAT_140032a28,&DAT_140032a30);
  if ((char)uVar3 == '\0') {
    DAT_140032a30 = 0;
    DAT_140032a28 = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvTipTag");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,(undefined4 *)&DAT_140032a3c);
  if ((char)uVar3 == '\0') {
    _DAT_140032a3c = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvTipPerformanceControl");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a40);
  if ((char)uVar3 == '\0') {
    DAT_140032a40 = 0;
  }
  RtlInitUnicodeString(&local_18,L"XdvDebugControl");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a4c);
  if ((char)uVar3 == '\0') {
    DAT_140032a4c = 0;
  }
  else {
    XdvWriteRegistryKeyDword((longlong)&local_18,0);
  }
  RtlInitUnicodeString(&local_18,L"XdvDebugRules");
  uVar3 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a48);
  if ((char)uVar3 == '\0') {
    DAT_140032a48 = 0;
  }
  else {
    XdvWriteRegistryKeyDword((longlong)&local_18,0);
    if (DAT_140032a34 != 0) {
      RtlInitUnicodeString(&local_18);
      XdvWriteRegistryKeyDword((longlong)&local_18,0);
    }
  }
  XdvVerifierOptions = DAT_140032a20;
  uVar4 = (ulonglong)(DAT_140032a20 & 0x10080);
  if ((DAT_140032a20 & 0x10080) == 0x10080) {
    RtlInitUnicodeString(&local_18,L"XdvTipStopTime");
    uVar4 = XdvReadRegistryKeyDword((longlong)&local_18,&DAT_140032a44);
    if ((char)uVar4 == '\0') {
      DAT_140032a44 = 0;
    }
  }
  uVar1 = DAT_140032a40;
  if (DAT_140032a40 != 0) {
    puVar5 = &XdvTooLongBarHitCount;
    do {
      uVar2 = uVar1 >> ((byte)iVar6 & 0x1f);
      if ((uVar2 & 1) != 0) {
        LOCK();
        uVar2 = *puVar5;
        *puVar5 = 0xfffe;
        UNLOCK();
      }
      uVar4 = (ulonglong)uVar2;
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar6 < 5);
  }
  return uVar4;
}



===== XdvTipCleanRegistry @ 140002648 =====

undefined1 XdvTipCleanRegistry(char param_1)

{
  bool bVar1;
  undefined1 uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvExtensionOption");
  RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvRuleSuppress");
  RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvTipPerformanceControl");
  RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvDebugRules");
  RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvTipStopTime");
  if (param_1 == '\0') {
LAB_14000278d:
    uVar2 = 1;
  }
  else {
    RtlInitUnicodeString(&local_18,L"VerifyDriverLevel");
    bVar1 = XdvWriteRegistryKeyDword((longlong)&local_18,0x400000);
    if (bVar1) {
      RtlInitUnicodeString(&local_18,L"XdvVerifierOptions");
      bVar1 = XdvWriteRegistryKeyDword((longlong)&local_18,XdvVerifierOptions & 1 | 0x10000);
      if (bVar1) goto LAB_14000278d;
    }
    RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"VerifyDriverLevel");
    RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"VerifierSettingState");
    RtlDeleteRegistryValue(0,&XdvRegistryRoot,L"XdvVerifierOptions");
    uVar2 = 0;
  }
  return uVar2;
}



===== XdvUtilDbgPrint @ 1400027a4 =====

void XdvUtilDbgPrint(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintEx(0x65,0,param_1,&local_res10);
  return;
}



===== CreateWatchedState @ 1400027e0 =====

void CreateWatchedState(longlong *param_1,uint param_2,longlong param_3,char param_4,
                       undefined8 *param_5)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *_Dst;
  undefined1 *puVar4;
  ulonglong _Size;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong local_48;
  undefined4 local_40;
  undefined2 local_38;
  
  _Size = (ulonglong)param_2;
  *param_5 = 0;
  if ((((param_4 == '\0') || (param_3 != 0)) && (_Dst = (longlong *)0x0, param_2 != 0)) &&
     (XdvLookasideStore != 0)) {
    if (_Size < 0x101) {
      plVar3 = (longlong *)(XdvLookasideStore + (_Size - 1 >> 2) * 8);
      while (*plVar3 == 0) {
        ExAcquireSpinLockExclusive(&XdvLookasideLock);
        if (*plVar3 == 0) {
          lVar2 = ExAllocatePool2(0x40,0x80,0x4c766458);
          if (lVar2 == 0) {
            ExReleaseSpinLockExclusive(&XdvLookasideLock);
            goto LAB_140002960;
          }
          local_38 = 0;
          local_40 = 0x53766458;
          local_48 = ((longlong)plVar3 - XdvLookasideStore >> 3) * 4 + 4;
          ExInitializeNPagedLookasideList(lVar2,0,0,0x200);
          LOCK();
          *plVar3 = lVar2;
          UNLOCK();
        }
        ExReleaseSpinLockExclusive(&XdvLookasideLock);
      }
      _Dst = (longlong *)ExAllocateFromNPagedLookasideList(*plVar3);
    }
    else {
      _Dst = (longlong *)ExAllocatePool2(0x40,_Size,0x4d766458);
    }
LAB_140002960:
    puVar4 = auStack_68;
    if (_Dst != (longlong *)0x0) {
      memset(_Dst,0,_Size);
      *(uint *)(_Dst + 2) = param_2;
      _Dst[3] = param_3;
      *param_5 = _Dst;
      lVar2 = *param_1;
      if (lVar2 == 0) {
        _Dst[1] = (longlong)_Dst;
        *_Dst = (longlong)_Dst;
        *param_1 = (longlong)_Dst;
        puVar4 = auStack_68;
      }
      else {
        plVar3 = *(longlong **)(lVar2 + 8);
        if (*plVar3 != lVar2) {
          plVar3 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          lVar2 = (*pcVar1)();
          puVar4 = auStack_60;
        }
        *_Dst = lVar2;
        _Dst[1] = (longlong)plVar3;
        *plVar3 = (longlong)_Dst;
        *(longlong **)(lVar2 + 8) = _Dst;
      }
      *(undefined8 *)(puVar4 + -8) = 0x1400029c5;
      RtlWalkFrameChain(_Dst + 4,10,0x100);
    }
  }
  return;
}



===== EndCriticalSectionNdisGroup @ 1400029f0 =====

void EndCriticalSectionNdisGroup(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  if ((param_1 != 0) && (local_res8[0] = 0, param_2 != 0)) {
    if (((XdvVerifierOptions & 0x10000) != 0) && (param_3 == '\0')) {
      lVar1 = KeQueryPerformanceCounter(local_res8);
      *(longlong *)(param_2 + 0x48) =
           *(longlong *)(param_2 + 0x48) +
           ((lVar1 - *(longlong *)(param_2 + 0x40)) * 1000000) / local_res8[0];
    }
    ExReleaseSpinLockExclusive(param_2 + 0x14,*(undefined1 *)(param_2 + 0x18));
  }
  return;
}



===== FindCreateWatchedState @ 140002a70 =====

void FindCreateWatchedState
               (longlong *param_1,undefined8 param_2,longlong param_3,char param_4,longlong *param_5
               )

{
  FindWatchedState((longlong *)*param_1,param_2,param_3,'\x01',param_4,param_5);
  if (*param_5 == 0) {
    CreateWatchedState(param_1,(uint)param_2,param_3,param_4,param_5);
  }
  return;
}



===== FindWatchedState @ 140002af0 =====

void FindWatchedState(longlong *param_1,undefined8 param_2,longlong param_3,char param_4,
                     char param_5,undefined8 *param_6)

{
  longlong *plVar1;
  
  *param_6 = 0;
  if ((param_1 != (longlong *)0x0) && ((plVar1 = param_1, param_5 == '\0' || (param_3 != 0)))) {
    do {
      if (param_3 == plVar1[3]) {
        *param_6 = plVar1;
        if (param_4 == '\0') {
          return;
        }
        RtlWalkFrameChain(plVar1 + 4,10,0x100);
        return;
      }
      plVar1 = (longlong *)*plVar1;
    } while (param_1 != plVar1);
  }
  return;
}



===== FreeWatchedList @ 140002b50 =====

void FreeWatchedList(longlong *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)*param_1;
  while (plVar1 != (longlong *)0x0) {
    plVar1 = FreeWatchedState(param_1,*(uint *)(plVar1 + 2),param_1);
    *param_1 = (longlong)plVar1;
  }
  return;
}



===== FreeWatchedState @ 140002b90 =====

longlong * FreeWatchedState(longlong *param_1,uint param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong *plVar6;
  
  if ((param_1 == (longlong *)0x0) || (plVar1 = (longlong *)*param_1, plVar1 == (longlong *)0x0)) {
LAB_140002c58:
    plVar4 = (longlong *)0x0;
  }
  else {
    plVar4 = (longlong *)*plVar1;
    if (plVar4 == plVar1) {
      plVar4 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
    }
    else {
      plVar6 = (longlong *)*param_3;
      if ((longlong *)*param_3 == plVar1) {
        plVar6 = plVar4;
      }
      if (((longlong *)plVar4[1] != plVar1) ||
         (plVar2 = (longlong *)plVar1[1], (longlong *)*plVar2 != plVar1)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        goto LAB_140002c58;
      }
      *plVar2 = (longlong)plVar4;
      plVar4[1] = (longlong)plVar2;
    }
    if ((param_2 != 0) && (XdvLookasideStore != 0)) {
      if ((ulonglong)param_2 < 0x101) {
        uVar5 = (ulonglong)param_2 - 1 >> 2;
        if (*(longlong *)(XdvLookasideStore + uVar5 * 8) != 0) {
          ExFreeToNPagedLookasideList(*(undefined8 *)(XdvLookasideStore + uVar5 * 8),*param_1);
        }
      }
      else {
        ExFreePoolWithTag(*param_1,0x4d766458);
      }
    }
    *param_1 = 0;
    *param_3 = (longlong)plVar6;
  }
  return plVar4;
}



===== GetFirstWatchedState @ 140002c80 =====

void GetFirstWatchedState(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = param_1;
  return;
}



===== GetNextWatchedState @ 140002c90 =====

void GetNextWatchedState(longlong param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  *param_4 = 0;
  if (param_1 != 0) {
    if (param_2 == (longlong *)0x0) {
      *param_4 = param_1;
      return;
    }
    if (*param_2 != param_1) {
      *param_4 = *param_2;
    }
  }
  return;
}



===== SLIC_abort @ 140002cc0 =====

void SLIC_abort(char *param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  char *local_50;
  
  uVar4 = 0;
  uVar5 = 0x58;
  memset(&local_68,0,0x58);
  if ((XdvDeviceObject != 0) && (-1 < (char)*(undefined4 *)(XdvDeviceObject + 0x30))) {
    iVar1 = CarInitializeRuleViolationDetails(&local_68);
    if (-1 < iVar1) {
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      if (param_1 == (char *)0x0) {
        param_1 = "DRIVER VERIFIER DETECTED VIOLATION";
      }
      local_50 = param_1;
      uVar3 = XdvQueryRuleSuppression(param_2,uVar4,uVar5);
      if ((char)uVar3 == '\0') {
        uVar4 = 0;
        puVar6 = &local_68;
        uVar2 = CarReportDifPluginRuleViolation(0x40);
        if ((int)uVar2 < 0) {
          XdvUtilDbgPrint("Driver Verifier: Rule reporting failed with NTSTATUS code 0x%X\n",
                          (ulonglong)uVar2,uVar4,puVar6);
        }
      }
      else {
        XdvUtilDbgPrint("Driver Verifier: Bugcheck suppressed with Error Code: 0x%X Error String: \'%s\'\n"
                        ,(ulonglong)param_2,param_1,param_4);
      }
    }
  }
  return;
}



===== StartCriticalSectionNdisGroup @ 140002d98 =====

void StartCriticalSectionNdisGroup(longlong *param_1,longlong param_2,char param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
  if ((*param_1 != 0) && (param_2 != 0)) {
    if (((XdvVerifierOptions & 0x10000) == 0) ||
       ((param_3 != '\0' || (*(int *)(param_2 + 0x38) == 0)))) {
      uVar3 = ExAcquireSpinLockExclusive(param_2 + 0x14);
      uVar1 = XdvVerifierOptions & 0x10000;
      *(undefined1 *)(param_2 + 0x18) = uVar3;
      if ((uVar1 != 0) && (param_3 == '\0')) {
        if (*(int *)(param_2 + 0x38) == 0) {
          uVar2 = KeQueryPerformanceCounter(0);
          *(undefined8 *)(param_2 + 0x40) = uVar2;
        }
        else {
          *param_1 = 0;
          ExReleaseSpinLockExclusive(param_2 + 0x14,uVar3);
        }
      }
    }
    else {
      *param_1 = 0;
    }
  }
  return;
}



===== XdvAllocatePool @ 140002e50 =====

void * XdvAllocatePool(ulonglong param_1,char param_2)

{
  longlong *plVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  
  if (param_2 == '\0') {
    uVar3 = 0x4e766458;
  }
  else {
    _Dst = (void *)0x0;
    if (param_1 == 0) {
      return (void *)0x0;
    }
    if (XdvLookasideStore == 0) goto LAB_140002fa6;
    if (param_1 < 0x101) {
      plVar1 = (longlong *)(XdvLookasideStore + (param_1 - 1 >> 2) * 8);
      while (*plVar1 == 0) {
        ExAcquireSpinLockExclusive(&XdvLookasideLock);
        if (*plVar1 == 0) {
          lVar2 = ExAllocatePool2(0x40,0x80,0x4c766458);
          if (lVar2 == 0) {
            ExReleaseSpinLockExclusive(&XdvLookasideLock);
            goto LAB_140002fa6;
          }
          ExInitializeNPagedLookasideList
                    (lVar2,0,0,0x200,((longlong)plVar1 - XdvLookasideStore >> 3) * 4 + 4,0x53766458,
                     0);
          LOCK();
          *plVar1 = lVar2;
          UNLOCK();
        }
        ExReleaseSpinLockExclusive(&XdvLookasideLock);
      }
      _Dst = (void *)ExAllocateFromNPagedLookasideList(*plVar1);
      goto LAB_140002fa6;
    }
    uVar3 = 0x4d766458;
  }
  _Dst = (void *)ExAllocatePool2(0x40,param_1,uVar3);
LAB_140002fa6:
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



===== XdvCreateState @ 140002fe0 =====

undefined8
XdvCreateState(int param_1,uint param_2,longlong param_3,undefined8 param_4,longlong *param_5)

{
  undefined8 *_Dst;
  void *_Dst_00;
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_5 == (longlong *)0x0) || (*param_5 != 0)) {
    uVar1 = 0xc0000001;
  }
  else {
    *param_5 = 0;
    _Dst = (undefined8 *)ExAllocatePool2(0x40,0x160,0x4e766458);
    if (_Dst != (undefined8 *)0x0) {
      memset(_Dst,0,0x160);
      *(int *)(_Dst + 2) = param_1;
      _Dst_00 = (void *)ExAllocatePool2(0x40,(ulonglong)param_2,0x4e766458);
      _Dst[6] = _Dst_00;
      if (_Dst_00 != (void *)0x0) {
        memset(_Dst_00,0,(ulonglong)param_2);
        *(uint *)(_Dst + 5) = param_2;
        *(int *)_Dst[6] = param_1;
        *(longlong *)(_Dst[6] + 0x18) = param_3;
        if (param_3 != 0) {
          uVar1 = *(undefined8 *)(param_3 + 8);
        }
        *(undefined8 *)(_Dst[6] + 0x20) = uVar1;
        *(undefined8 *)(_Dst[6] + 0x10) = param_4;
        *(undefined8 **)(_Dst[6] + 8) = _Dst;
        XdvTimedRegisterContext(param_1,_Dst);
        *param_5 = (longlong)_Dst;
        return 0;
      }
      if (XdvLookasideStore != 0) {
        ExFreePoolWithTag(_Dst,0x4d766458);
      }
    }
    uVar1 = 0xc000009a;
  }
  return uVar1;
}



===== XdvEndCriticalSection @ 140003120 =====

void XdvEndCriticalSection(longlong param_1)

{
  if (param_1 != 0) {
    ExReleaseSpinLockExclusive(param_1 + 0x14,*(undefined1 *)(param_1 + 0x18));
  }
  return;
}



===== XdvExportTableInitialize @ 14000314c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void XdvExportTableInitialize(void)

{
  _DAT_140079438 = CreateWatchedState;
  _DAT_140079470 = XdvEndCriticalSection;
  _DAT_140079440 = FindWatchedState;
  _DAT_140079448 = FindCreateWatchedState;
  _XdvExportTable = XdvCreateState;
  _DAT_140079430 = XdvFreeState;
  _DAT_140079460 = FreeWatchedState;
  _DAT_140079450 = GetFirstWatchedState;
  _DAT_140079458 = GetNextWatchedState;
  _DAT_140079428 = XdvLoadState;
  _DAT_140079468 = XdvStartCriticalSection;
  _DAT_140079478 = SLIC_StatefulAbort;
  _DAT_140079480 = SLIC_abort;
  _DAT_140079488 = XdvTimedStartExtension;
  _DAT_140079490 = XdvTimedStopExtension;
  _DAT_140079498 = XdvTimedGetCurrentTimeTick;
  _DAT_1400794a0 = XdvGetCurrentIrql;
  _DAT_1400794a8 = XdvAllocatePool;
  _DAT_1400794b0 = XdvFreePool;
  _DAT_1400794b8 = XdvReadExtensionConfiguration;
  _DAT_1400794c0 = XdvGetPluginExportTable;
  _DAT_1400794c8 = XdvReadRegistryKeyDword;
  return;
}



===== XdvFreePool @ 140003290 =====

void XdvFreePool(undefined8 param_1,ulonglong param_2,char param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  if (param_3 == '\0') {
    uVar1 = 0x4e766458;
  }
  else {
    if (param_2 == 0) {
      return;
    }
    if (XdvLookasideStore == 0) {
      return;
    }
    if (param_2 < 0x101) {
      uVar2 = param_2 - 1 >> 2;
      if (*(longlong *)(XdvLookasideStore + uVar2 * 8) == 0) {
        return;
      }
      ExFreeToNPagedLookasideList(*(undefined8 *)(XdvLookasideStore + uVar2 * 8),param_1);
      return;
    }
    uVar1 = 0x4d766458;
  }
  ExFreePoolWithTag(param_1,uVar1);
  return;
}



===== XdvFreeState @ 140003300 =====

void XdvFreeState(int param_1,longlong *param_2)

{
  longlong lVar1;
  char cVar2;
  
  if (param_2 != (longlong *)0x0) {
    cVar2 = XdvIsTimedExtensionStarted(param_1);
    if (cVar2 != '\0') {
      XdvTimedRemoveContext(param_1,param_2);
    }
    lVar1 = param_2[6];
    if (lVar1 != 0) {
      if (*(int *)(lVar1 + 0x28) != 0) {
        *(undefined4 *)(lVar1 + 0x28) = 2;
        return;
      }
      ExFreePoolWithTag(lVar1,0x4e766458);
      param_2[6] = 0;
    }
    ExFreePoolWithTag(param_2,0x4e766458);
  }
  return;
}



===== XdvGetCurrentIrql @ 140003380 =====

undefined1 XdvGetCurrentIrql(longlong param_1)

{
  undefined1 uVar1;
  
  if (param_1 == 0) {
    uVar1 = KeGetCurrentIrql();
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x18);
  }
  return uVar1;
}



===== XdvGetPluginExportTable @ 1400033b0 =====

undefined ** XdvGetPluginExportTable(int param_1)

{
  if (param_1 == 1) {
    return &XdvAutofailExported;
  }
  return (undefined **)0x0;
}



===== XdvLoadState @ 1400033d0 =====

undefined8 XdvLoadState(longlong param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined8 *)(param_1 + 0x30);
}



===== XdvNdisDataClean @ 1400033e8 =====

void XdvNdisDataClean(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if ((param_1 != (longlong *)0x0) && (puVar1 = (undefined8 *)*param_1, puVar1 != (undefined8 *)0x0)
     ) {
    puVar2 = (undefined8 *)*puVar1;
    while (puVar2 != puVar1) {
      if (puVar2 == (undefined8 *)0x0) goto LAB_140003472;
      puVar2 = (undefined8 *)*puVar2;
      if ((XdvLookasideStore != 0) && (*(longlong *)(XdvLookasideStore + 0x38) != 0)) {
        ExFreeToNPagedLookasideList(*(undefined8 *)(XdvLookasideStore + 0x38));
      }
    }
    if (((puVar2 != (undefined8 *)0x0) && (XdvLookasideStore != 0)) &&
       (*(longlong *)(XdvLookasideStore + 0x38) != 0)) {
      ExFreeToNPagedLookasideList(*(undefined8 *)(XdvLookasideStore + 0x38));
    }
LAB_140003472:
    *param_1 = 0;
  }
  return;
}



===== XdvNdisDataComplete @ 140003490 =====

undefined1 XdvNdisDataComplete(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  char *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 uVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [56];
  
  puVar7 = auStack_48;
  puVar8 = auStack_48;
  uVar10 = 1;
  if (((param_2 == (longlong *)0x0) || (param_1 == (longlong *)0x0)) ||
     (plVar5 = (longlong *)*param_1, plVar5 == (longlong *)0x0)) {
LAB_1400035bd:
    uVar10 = 0;
  }
  else {
    plVar6 = plVar5;
    do {
      if (plVar5 == (longlong *)0x0) {
LAB_140003591:
        puVar9 = puVar7;
        if (((DAT_140032a4c & 1) != 0) && ((Microsoft_Windows_Kernel_XDVEnableBits & 4) != 0)) {
          pcVar4 = "XDV Internal problem 1.1. Data cleanup.";
          puVar8 = puVar7;
LAB_1400035ab:
          *(char **)(puVar8 + 0x20) = pcVar4;
          *(undefined8 *)(puVar8 + -8) = 0x1400035b5;
          McTemplateK0dszud_EtwWriteTransfer();
          puVar9 = puVar8;
        }
LAB_1400035b5:
        *(undefined8 *)(puVar9 + -8) = 0x1400035bd;
        XdvNdisDataClean(param_1);
        goto LAB_1400035bd;
      }
      if ((longlong *)plVar5[3] == param_2) {
        if (plVar5 != plVar6) goto LAB_1400034f4;
LAB_140003506:
        if ((longlong *)plVar5[3] == param_2) goto LAB_1400034f4;
        uVar10 = 0;
      }
      else {
        do {
          plVar5 = (longlong *)*plVar5;
          if (plVar5 == (longlong *)0x0) {
            puVar9 = auStack_48;
            if (((DAT_140032a4c & 1) == 0) ||
               (puVar9 = auStack_48, (Microsoft_Windows_Kernel_XDVEnableBits & 4) == 0))
            goto LAB_1400035b5;
            pcVar4 = "XDV Internal problem 1.2. Data cleanup.";
            goto LAB_1400035ab;
          }
          if (plVar5 == plVar6) goto LAB_140003506;
        } while ((longlong *)plVar5[3] != param_2);
LAB_1400034f4:
        if ((longlong *)*plVar5 == plVar5) {
          *param_1 = 0;
          plVar5 = (longlong *)0x0;
        }
        else {
          if (plVar5 == plVar6) {
            plVar6 = (longlong *)*plVar6;
            *param_1 = (longlong)plVar6;
          }
          lVar1 = *plVar5;
          if ((*(longlong **)(lVar1 + 8) != plVar5) ||
             (plVar2 = (longlong *)plVar5[1], (longlong *)*plVar2 != plVar5)) {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            puVar7 = auStack_40;
            goto LAB_140003591;
          }
          *plVar2 = lVar1;
          *(longlong **)(lVar1 + 8) = plVar2;
          plVar5 = plVar6;
        }
        if ((XdvLookasideStore != 0) && (*(longlong *)(XdvLookasideStore + 0x38) != 0)) {
          ExFreeToNPagedLookasideList(*(undefined8 *)(XdvLookasideStore + 0x38));
        }
        plVar6 = plVar5;
      }
      param_2 = (longlong *)*param_2;
    } while (param_2 != (longlong *)0x0);
  }
  return uVar10;
}



===== XdvNdisDataSendReceive @ 1400035dc =====

ulonglong XdvNdisDataSendReceive
                    (longlong *param_1,undefined4 param_2,longlong *param_3,undefined4 param_4)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined8 *in_RAX;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  
  if ((param_3 != (longlong *)0x0) && (param_1 != (longlong *)0x0)) {
    puVar6 = (undefined8 *)*param_1;
    if (puVar6 != (undefined8 *)0x0) goto LAB_14000373e;
    in_RAX = (undefined8 *)0x0;
    if (XdvLookasideStore != 0) {
      plVar1 = (longlong *)(XdvLookasideStore + 0x38);
      while (*plVar1 == 0) {
        uVar3 = ExAcquireSpinLockExclusive(&XdvLookasideLock);
        if (*plVar1 == 0) {
          lVar4 = ExAllocatePool2(0x40,0x80,0x4c766458);
          if (lVar4 == 0) goto LAB_140003726;
          ExInitializeNPagedLookasideList
                    (lVar4,0,0,0x200,((longlong)plVar1 - XdvLookasideStore >> 3) * 4 + 4,0x53766458,
                     0);
          LOCK();
          *plVar1 = lVar4;
          UNLOCK();
        }
        ExReleaseSpinLockExclusive(&XdvLookasideLock,uVar3);
      }
      in_RAX = (undefined8 *)ExAllocateFromNPagedLookasideList(*plVar1);
    }
    if (in_RAX != (undefined8 *)0x0) {
      *param_1 = (longlong)in_RAX;
      in_RAX[1] = in_RAX;
      *in_RAX = in_RAX;
      in_RAX[3] = param_3;
      *(undefined4 *)(in_RAX + 2) = param_2;
      *(undefined4 *)((longlong)in_RAX + 0x14) = param_4;
      puVar6 = in_RAX;
      while( true ) {
        param_3 = (longlong *)*param_3;
        if (param_3 == (longlong *)0x0) {
          return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
        }
LAB_14000373e:
        lVar4 = XdvLookasideStore;
        if (XdvLookasideStore == 0) goto LAB_14000388f;
        while (*(longlong *)(lVar4 + 0x38) == 0) {
          uVar3 = ExAcquireSpinLockExclusive(&XdvLookasideLock);
          if (*(longlong *)(lVar4 + 0x38) == 0) {
            lVar5 = ExAllocatePool2(0x40,0x80,0x4c766458);
            if (lVar5 == 0) goto LAB_140003726;
            ExInitializeNPagedLookasideList
                      (lVar5,0,0,0x200,((lVar4 + 0x38) - XdvLookasideStore >> 3) * 4 + 4,0x53766458,
                       0);
            LOCK();
            *(longlong *)(lVar4 + 0x38) = lVar5;
            UNLOCK();
          }
          ExReleaseSpinLockExclusive(&XdvLookasideLock,uVar3);
        }
        in_RAX = (undefined8 *)ExAllocateFromNPagedLookasideList(*(undefined8 *)(lVar4 + 0x38));
        if (in_RAX == (undefined8 *)0x0) goto LAB_14000388f;
        *in_RAX = 0;
        in_RAX[1] = 0;
        in_RAX[3] = param_3;
        *(undefined4 *)(in_RAX + 2) = param_2;
        *(undefined4 *)((longlong)in_RAX + 0x14) = param_4;
        puVar2 = (undefined8 *)puVar6[1];
        if ((puVar2 == (undefined8 *)0x0) || ((undefined8 *)*puVar2 != puVar6)) break;
        *in_RAX = puVar6;
        in_RAX[1] = puVar2;
        *puVar2 = in_RAX;
        puVar6[1] = in_RAX;
      }
      if (((DAT_140032a4c & 1) != 0) && ((Microsoft_Windows_Kernel_XDVEnableBits & 4) != 0)) {
        McTemplateK0dszud_EtwWriteTransfer();
      }
      in_RAX = (undefined8 *)XdvNdisDataClean(param_1);
    }
  }
LAB_14000388f:
  return (ulonglong)in_RAX & 0xffffffffffffff00;
LAB_140003726:
  in_RAX = (undefined8 *)ExReleaseSpinLockExclusive(&XdvLookasideLock,uVar3);
  goto LAB_14000388f;
}



===== XdvReadExtensionConfiguration @ 1400038c0 =====

undefined4 XdvReadExtensionConfiguration(void)

{
  return DAT_140032a1c;
}



===== XdvStartCriticalSection @ 1400038d0 =====

void XdvStartCriticalSection(longlong param_1)

{
  undefined1 uVar1;
  
  if (param_1 != 0) {
    uVar1 = ExAcquireSpinLockExclusive(param_1 + 0x14);
    *(undefined1 *)(param_1 + 0x18) = uVar1;
  }
  return;
}



===== XdvDefaultSuppression @ 140003900 =====

void XdvDefaultSuppression(uint param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  if ((XdvVerifierOptions >> 0x10 & 1) != 0) {
    return;
  }
  if ((XdvVerifierOptions & 0x10) != 0) {
    return;
  }
  iVar1 = 4;
  if (param_1 < 0x40004) {
    if (param_1 == 0x40003) {
      uVar2 = 0x1c;
      goto LAB_140003e83;
    }
    if (param_1 < 0x20011) {
      if (param_1 == 0x20010) {
        uVar2 = 0xe;
        goto LAB_140003e83;
      }
      if (param_1 < 0x2000a) {
        if (param_1 == 0x20009) {
          uVar2 = 7;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20002) {
          uVar2 = 0;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20003) {
          uVar2 = 1;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20004) {
          uVar2 = 2;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20005) {
          uVar2 = 3;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20006) {
          uVar2 = 4;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20007) {
          uVar2 = 5;
          goto LAB_140003e83;
        }
        if (param_1 == 0x20008) {
          uVar2 = 6;
          goto LAB_140003e83;
        }
      }
      else {
        if (param_1 == 0x2000a) {
          uVar2 = 8;
          goto LAB_140003e83;
        }
        if (param_1 == 0x2000b) {
          uVar2 = 9;
          goto LAB_140003e83;
        }
        if (param_1 == 0x2000c) {
          uVar2 = 10;
          goto LAB_140003e83;
        }
        if (param_1 == 0x2000d) {
          uVar2 = 0xb;
          goto LAB_140003e83;
        }
        if (param_1 == 0x2000e) {
          uVar2 = 0xc;
          goto LAB_140003e83;
        }
        if (param_1 == 0x2000f) {
          uVar2 = 0xd;
          goto LAB_140003e83;
        }
      }
    }
    else if (param_1 < 0x2001d) {
      if (param_1 == 0x2001c) {
        uVar2 = 0x15;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20011) {
        uVar2 = 0xf;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20015) {
        uVar2 = 0x10;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20016) {
        uVar2 = 0x11;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20019) {
        uVar2 = 0x12;
        goto LAB_140003e83;
      }
      if (param_1 == 0x2001a) {
        uVar2 = 0x13;
        goto LAB_140003e83;
      }
      if (param_1 == 0x2001b) {
        uVar2 = 0x14;
        goto LAB_140003e83;
      }
    }
    else {
      if (param_1 == 0x2001e) {
        uVar2 = 0x16;
        goto LAB_140003e83;
      }
      if (param_1 == 0x2001f) {
        uVar2 = 0x17;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20022) {
        uVar2 = 0x18;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20023) {
        uVar2 = 0x19;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20024) {
        uVar2 = 0x1a;
        goto LAB_140003e83;
      }
      if (param_1 == 0x20025) {
        uVar2 = 0x1b;
        goto LAB_140003e83;
      }
    }
LAB_140003ba2:
    if (param_1 == 0x81001) {
      iVar1 = 0;
    }
    else if (param_1 == 0x81002) {
      iVar1 = 1;
    }
    else if (param_1 == 0x81003) {
      iVar1 = 2;
    }
    else if (param_1 == 0x81004) {
      iVar1 = 3;
    }
    else if (param_1 != 0x81005) {
      if (param_1 != 0x81006) {
        if (param_1 < 0x71008) {
          if (param_1 == 0x71007) {
            uVar2 = 0x49;
          }
          else if (param_1 == 0x71001) {
            uVar2 = 0x44;
          }
          else if (param_1 == 0x71003) {
            uVar2 = 0x45;
          }
          else if (param_1 == 0x71004) {
            uVar2 = 0x46;
          }
          else if (param_1 == 0x71005) {
            uVar2 = 0x47;
          }
          else {
            if (param_1 != 0x71006) {
              return;
            }
            uVar2 = 0x48;
          }
          goto LAB_140003e83;
        }
        goto LAB_140003e16;
      }
      iVar1 = 5;
    }
  }
  else {
    if (param_1 < 0x92012) {
      if (param_1 == 0x92011) {
        uVar2 = 0x28;
        goto LAB_140003e83;
      }
      if (param_1 < 0x91003) {
        if (param_1 == 0x91002) {
          uVar2 = 0x22;
          goto LAB_140003e83;
        }
        if (param_1 == 0x40007) {
          uVar2 = 0x1d;
          goto LAB_140003e83;
        }
        if (param_1 == 0x4000a) {
          uVar2 = 0x1e;
          goto LAB_140003e83;
        }
        if (param_1 == 0x4100b) {
          uVar2 = 0x1f;
          goto LAB_140003e83;
        }
        if (param_1 == 0x43006) {
          uVar2 = 0x20;
          goto LAB_140003e83;
        }
        if (param_1 == 0x91001) {
          uVar2 = 0x21;
          goto LAB_140003e83;
        }
        if (param_1 < 0x82002) {
          if (param_1 == 0x82001) {
            iVar1 = 0xc;
          }
          else if (param_1 < 0x81008) {
            if (param_1 != 0x81007) goto LAB_140003ba2;
            iVar1 = 6;
          }
          else if (param_1 == 0x81008) {
            iVar1 = 7;
          }
          else if (param_1 == 0x81009) {
            iVar1 = 8;
          }
          else if (param_1 == 0x8100a) {
            iVar1 = 9;
          }
          else if (param_1 == 0x8100b) {
            iVar1 = 10;
          }
          else {
            if (param_1 != 0x8100c) goto LAB_140003e16;
            iVar1 = 0xb;
          }
          goto LAB_140003e64;
        }
      }
      else {
        if (param_1 == 0x9100e) {
          uVar2 = 0x23;
          goto LAB_140003e83;
        }
        if (param_1 == 0x92003) {
          uVar2 = 0x24;
          goto LAB_140003e83;
        }
        if (param_1 == 0x9200d) {
          uVar2 = 0x25;
          goto LAB_140003e83;
        }
        if (param_1 == 0x9200f) {
          uVar2 = 0x26;
          goto LAB_140003e83;
        }
        if (param_1 == 0x92010) {
          uVar2 = 0x27;
          goto LAB_140003e83;
        }
      }
    }
    else if (param_1 < 0x94008) {
      if (param_1 == 0x94007) {
        uVar2 = 0x2e;
        goto LAB_140003e83;
      }
      if (param_1 == 0x92012) {
        uVar2 = 0x29;
        goto LAB_140003e83;
      }
      if (param_1 == 0x93004) {
        uVar2 = 0x2a;
        goto LAB_140003e83;
      }
      if (param_1 == 0x93005) {
        uVar2 = 0x2b;
        goto LAB_140003e83;
      }
      if (param_1 == 0x93006) {
        uVar2 = 0x2c;
        goto LAB_140003e83;
      }
      if (param_1 == 0x93101) {
        uVar2 = 0x2d;
        goto LAB_140003e83;
      }
    }
    else {
      if (param_1 == 0x94008) {
        uVar2 = 0x2f;
        goto LAB_140003e83;
      }
      if (param_1 == 0x94009) {
        uVar2 = 0x30;
        goto LAB_140003e83;
      }
      if (param_1 == 0x9400b) {
        uVar2 = 0x31;
        goto LAB_140003e83;
      }
      if (param_1 == 0x9400c) {
        uVar2 = 0x32;
        goto LAB_140003e83;
      }
    }
    if (param_1 == 0x82002) {
      iVar1 = 0xd;
    }
    else if (param_1 == 0x82003) {
      iVar1 = 0xe;
    }
    else if (param_1 == 0x82004) {
      iVar1 = 0xf;
    }
    else {
      if (param_1 != 0x82005) {
LAB_140003e16:
        if (param_1 == 0x71008) {
          uVar2 = 0x4a;
        }
        else if (param_1 == 0x71009) {
          uVar2 = 0x4b;
        }
        else if (param_1 == 0x7100a) {
          uVar2 = 0x4c;
        }
        else {
          if (param_1 != 0x72001) {
            return;
          }
          uVar2 = 0x4d;
        }
        goto LAB_140003e83;
      }
      iVar1 = 0x10;
    }
  }
LAB_140003e64:
  uVar2 = (ulonglong)(iVar1 + 0x33);
LAB_140003e83:
  if ((uint)uVar2 < 0x4e) {
    LOCK();
    (&XdvRuleSuppression)[uVar2] = 1;
    UNLOCK();
  }
  return;
}



===== XdvParseSuppressionKey @ 140003e9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint XdvParseSuppressionKey(wchar_t *param_1)

{
  wchar_t wVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  uint *puVar8;
  longlong lVar9;
  uint uVar10;
  undefined1 auStack_198 [32];
  wchar_t *local_178 [2];
  uint local_168 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_198;
  uVar10 = 0;
  local_178[0] = param_1;
  memset(local_168,0,0x138);
  lVar9 = 0x4e;
  _DAT_140079400 = 0xffffffffffffffff;
  _XdvSelectedCoreRules = 0xffffffffffffffff;
  uRam00000001400793e8 = 0xffffffffffffffff;
  _DAT_1400793f0 = 0xffffffffffffffff;
  uRam00000001400793f8 = 0xffffffffffffffff;
joined_r0x000140003f12:
  while( true ) {
    if ((param_1 == (wchar_t *)0x0) || (wVar1 = *param_1, wVar1 == L'\0')) goto LAB_140004546;
    if ((wVar1 != L' ') && (wVar1 != L'\t')) break;
    param_1 = param_1 + 1;
    local_178[0] = param_1;
  }
  if (wVar1 == L'*') {
    puVar8 = local_168;
    for (lVar6 = 0x4e; lVar6 != 0; lVar6 = lVar6 + -1) {
      *puVar8 = 1;
      puVar8 = puVar8 + 1;
    }
LAB_140004546:
    puVar8 = local_168;
    puVar7 = &XdvRuleSuppression;
    if ((XdvVerifierOptions & 0x10) == 0) {
      do {
        uVar2 = *puVar8;
        puVar8 = puVar8 + 1;
        LOCK();
        uVar10 = *puVar7;
        *puVar7 = uVar2;
        UNLOCK();
        puVar7 = puVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    else {
      do {
        uVar2 = *puVar8;
        puVar8 = puVar8 + 1;
        LOCK();
        uVar10 = *puVar7;
        *puVar7 = (uint)(uVar2 == 0);
        UNLOCK();
        puVar7 = puVar7 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    return uVar10;
  }
  uVar3 = wcstoul(param_1,local_178,0);
  if (param_1 == local_178[0]) {
    param_1 = local_178[0] + 1;
    local_178[0] = param_1;
    goto joined_r0x000140003f12;
  }
  param_1 = local_178[0];
  if (((XdvVerifierOptions & 0x10000) != 0) &&
     ((((uVar3 & 0xfff00000) != 0 || (uVar3 < 0x20000)) && (uVar10 < 10)))) {
    uVar5 = (ulonglong)uVar10;
    XdvAreAllCoreRulesSelected = 0;
    uVar10 = uVar10 + 1;
    LOCK();
    (&XdvSelectedCoreRules)[uVar5] = uVar3;
    UNLOCK();
    goto joined_r0x000140003f12;
  }
  if (uVar3 < 0x40004) {
    if (uVar3 == 0x40003) {
      uVar5 = 0x1c;
      goto LAB_140004519;
    }
    if (uVar3 < 0x20011) {
      if (uVar3 == 0x20010) {
        uVar5 = 0xe;
      }
      else if (uVar3 < 0x2000a) {
        if (uVar3 == 0x20009) {
          uVar5 = 7;
        }
        else if (uVar3 == 0x20002) {
          uVar5 = 0;
        }
        else if (uVar3 == 0x20003) {
          uVar5 = 1;
        }
        else if (uVar3 == 0x20004) {
          uVar5 = 2;
        }
        else if (uVar3 == 0x20005) {
          uVar5 = 3;
        }
        else if (uVar3 == 0x20006) {
          uVar5 = 4;
        }
        else if (uVar3 == 0x20007) {
          uVar5 = 5;
        }
        else {
          if (uVar3 != 0x20008) goto LAB_140004232;
          uVar5 = 6;
        }
      }
      else if (uVar3 == 0x2000a) {
        uVar5 = 8;
      }
      else if (uVar3 == 0x2000b) {
        uVar5 = 9;
      }
      else if (uVar3 == 0x2000c) {
        uVar5 = 10;
      }
      else if (uVar3 == 0x2000d) {
        uVar5 = 0xb;
      }
      else if (uVar3 == 0x2000e) {
        uVar5 = 0xc;
      }
      else {
        if (uVar3 != 0x2000f) goto LAB_140004232;
        uVar5 = 0xd;
      }
      goto LAB_140004519;
    }
    if (uVar3 < 0x2001d) {
      if (uVar3 == 0x2001c) {
        uVar5 = 0x15;
      }
      else if (uVar3 == 0x20011) {
        uVar5 = 0xf;
      }
      else if (uVar3 == 0x20015) {
        uVar5 = 0x10;
      }
      else if (uVar3 == 0x20016) {
        uVar5 = 0x11;
      }
      else if (uVar3 == 0x20019) {
        uVar5 = 0x12;
      }
      else if (uVar3 == 0x2001a) {
        uVar5 = 0x13;
      }
      else {
        if (uVar3 != 0x2001b) goto LAB_140004232;
        uVar5 = 0x14;
      }
      goto LAB_140004519;
    }
    if (uVar3 == 0x2001e) {
      uVar5 = 0x16;
      goto LAB_140004519;
    }
    if (uVar3 == 0x2001f) {
      uVar5 = 0x17;
      goto LAB_140004519;
    }
    if (uVar3 == 0x20022) {
      uVar5 = 0x18;
      goto LAB_140004519;
    }
    if (uVar3 == 0x20023) {
      uVar5 = 0x19;
      goto LAB_140004519;
    }
    if (uVar3 == 0x20024) {
      uVar5 = 0x1a;
      goto LAB_140004519;
    }
    if (uVar3 == 0x20025) {
      uVar5 = 0x1b;
      goto LAB_140004519;
    }
LAB_140004232:
    if (uVar3 == 0x81001) {
      iVar4 = 0;
    }
    else if (uVar3 == 0x81002) {
      iVar4 = 1;
    }
    else if (uVar3 == 0x81003) {
      iVar4 = 2;
    }
    else if (uVar3 == 0x81004) {
      iVar4 = 3;
    }
    else {
      if (uVar3 != 0x81005) {
        if (uVar3 == 0x81006) {
          iVar4 = 5;
          goto LAB_1400044fa;
        }
        if (0x71007 < uVar3) goto LAB_1400044a6;
        if (uVar3 == 0x71007) {
          uVar5 = 0x49;
        }
        else if (uVar3 == 0x71001) {
          uVar5 = 0x44;
        }
        else if (uVar3 == 0x71003) {
          uVar5 = 0x45;
        }
        else if (uVar3 == 0x71004) {
          uVar5 = 0x46;
        }
        else {
          if (uVar3 != 0x71005) {
            if (uVar3 == 0x71006) {
              uVar5 = 0x48;
              goto LAB_140004519;
            }
            goto joined_r0x000140003f12;
          }
          uVar5 = 0x47;
        }
        goto LAB_140004519;
      }
      iVar4 = 4;
    }
  }
  else {
    if (uVar3 < 0x92012) {
      if (uVar3 == 0x92011) {
        uVar5 = 0x28;
      }
      else if (uVar3 < 0x91003) {
        if (uVar3 == 0x91002) {
          uVar5 = 0x22;
        }
        else if (uVar3 == 0x40007) {
          uVar5 = 0x1d;
        }
        else if (uVar3 == 0x4000a) {
          uVar5 = 0x1e;
        }
        else if (uVar3 == 0x4100b) {
          uVar5 = 0x1f;
        }
        else if (uVar3 == 0x43006) {
          uVar5 = 0x20;
        }
        else {
          if (uVar3 != 0x91001) {
            if (uVar3 < 0x82002) {
              if (uVar3 == 0x82001) {
                iVar4 = 0xc;
              }
              else if (uVar3 < 0x81008) {
                if (uVar3 != 0x81007) goto LAB_140004232;
                iVar4 = 6;
              }
              else if (uVar3 == 0x81008) {
                iVar4 = 7;
              }
              else if (uVar3 == 0x81009) {
                iVar4 = 8;
              }
              else if (uVar3 == 0x8100a) {
                iVar4 = 9;
              }
              else if (uVar3 == 0x8100b) {
                iVar4 = 10;
              }
              else {
                if (uVar3 != 0x8100c) goto LAB_1400044a6;
                iVar4 = 0xb;
              }
              goto LAB_1400044fa;
            }
            goto LAB_14000448e;
          }
          uVar5 = 0x21;
        }
      }
      else if (uVar3 == 0x9100e) {
        uVar5 = 0x23;
      }
      else if (uVar3 == 0x92003) {
        uVar5 = 0x24;
      }
      else if (uVar3 == 0x9200d) {
        uVar5 = 0x25;
      }
      else if (uVar3 == 0x9200f) {
        uVar5 = 0x26;
      }
      else {
        if (uVar3 != 0x92010) goto LAB_14000448e;
        uVar5 = 0x27;
      }
      goto LAB_140004519;
    }
    if (uVar3 < 0x94008) {
      if (uVar3 == 0x94007) {
        uVar5 = 0x2e;
      }
      else if (uVar3 == 0x92012) {
        uVar5 = 0x29;
      }
      else if (uVar3 == 0x93004) {
        uVar5 = 0x2a;
      }
      else if (uVar3 == 0x93005) {
        uVar5 = 0x2b;
      }
      else if (uVar3 == 0x93006) {
        uVar5 = 0x2c;
      }
      else {
        if (uVar3 != 0x93101) goto LAB_14000448e;
        uVar5 = 0x2d;
      }
      goto LAB_140004519;
    }
    if (uVar3 == 0x94008) {
      uVar5 = 0x2f;
      goto LAB_140004519;
    }
    if (uVar3 == 0x94009) {
      uVar5 = 0x30;
      goto LAB_140004519;
    }
    if (uVar3 == 0x9400b) {
      uVar5 = 0x31;
      goto LAB_140004519;
    }
    if (uVar3 == 0x9400c) {
      uVar5 = 0x32;
      goto LAB_140004519;
    }
LAB_14000448e:
    if (uVar3 == 0x82002) {
      iVar4 = 0xd;
    }
    else if (uVar3 == 0x82003) {
      iVar4 = 0xe;
    }
    else if (uVar3 == 0x82004) {
      iVar4 = 0xf;
    }
    else {
      if (uVar3 != 0x82005) {
LAB_1400044a6:
        if (uVar3 == 0x71008) {
          uVar5 = 0x4a;
        }
        else if (uVar3 == 0x71009) {
          uVar5 = 0x4b;
        }
        else {
          if (uVar3 != 0x7100a) {
            if (uVar3 == 0x72001) {
              uVar5 = 0x4d;
              goto LAB_140004519;
            }
            goto joined_r0x000140003f12;
          }
          uVar5 = 0x4c;
        }
        goto LAB_140004519;
      }
      iVar4 = 0x10;
    }
  }
LAB_1400044fa:
  uVar5 = (ulonglong)(iVar4 + 0x33);
LAB_140004519:
  if ((uint)uVar5 < 0x4e) {
    local_168[uVar5] = 1;
  }
  goto joined_r0x000140003f12;
}



===== XdvQueryRuleSuppression @ 1400045bc =====

ulonglong XdvQueryRuleSuppression(uint param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  if (((param_1 & 0xfff00000) != 0) || (param_1 < 0x20000)) {
    iVar5 = 0;
    if (XdvAreAllCoreRulesSelected == '\0') {
      puVar4 = &XdvSelectedCoreRules;
      do {
        uVar3 = *puVar4;
        if (param_1 == uVar3) goto LAB_140004b8e;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while ((longlong)puVar4 < 0x140079408);
      iVar5 = -1;
LAB_140004b8e:
      return (ulonglong)CONCAT31((int3)(uVar3 >> 8),iVar5 == -1);
    }
    goto LAB_140004b61;
  }
  uVar3 = 4;
  if (param_1 < 0x40004) {
    if (param_1 == 0x40003) {
      uVar3 = 0x1c;
    }
    else if (param_1 < 0x20011) {
      if (param_1 == 0x20010) {
        uVar3 = 0xe;
      }
      else if (param_1 < 0x2000a) {
        if (param_1 == 0x20009) {
          uVar3 = 7;
        }
        else if (param_1 == 0x20002) {
          uVar3 = 0;
        }
        else if (param_1 == 0x20003) {
          uVar3 = 1;
        }
        else if (param_1 == 0x20004) {
          uVar3 = 2;
        }
        else if (param_1 == 0x20005) {
          uVar3 = 3;
        }
        else if (param_1 != 0x20006) {
          if (param_1 == 0x20007) {
            uVar3 = 5;
          }
          else {
            if (param_1 != 0x20008) goto LAB_14000484c;
            uVar3 = 6;
          }
        }
      }
      else if (param_1 == 0x2000a) {
        uVar3 = 8;
      }
      else if (param_1 == 0x2000b) {
        uVar3 = 9;
      }
      else if (param_1 == 0x2000c) {
        uVar3 = 10;
      }
      else if (param_1 == 0x2000d) {
        uVar3 = 0xb;
      }
      else if (param_1 == 0x2000e) {
        uVar3 = 0xc;
      }
      else {
        if (param_1 != 0x2000f) goto LAB_14000484c;
        uVar3 = 0xd;
      }
    }
    else if (param_1 < 0x2001d) {
      if (param_1 == 0x2001c) {
        uVar3 = 0x15;
      }
      else if (param_1 == 0x20011) {
        uVar3 = 0xf;
      }
      else if (param_1 == 0x20015) {
        uVar3 = 0x10;
      }
      else if (param_1 == 0x20016) {
        uVar3 = 0x11;
      }
      else if (param_1 == 0x20019) {
        uVar3 = 0x12;
      }
      else if (param_1 == 0x2001a) {
        uVar3 = 0x13;
      }
      else {
        if (param_1 != 0x2001b) goto LAB_14000484c;
        uVar3 = 0x14;
      }
    }
    else if (param_1 == 0x2001e) {
      uVar3 = 0x16;
    }
    else if (param_1 == 0x2001f) {
      uVar3 = 0x17;
    }
    else if (param_1 == 0x20022) {
      uVar3 = 0x18;
    }
    else if (param_1 == 0x20023) {
      uVar3 = 0x19;
    }
    else if (param_1 == 0x20024) {
      uVar3 = 0x1a;
    }
    else {
      if (param_1 != 0x20025) {
LAB_14000484c:
        if (param_1 == 0x81001) {
          uVar3 = 0;
        }
        else if (param_1 == 0x81002) {
          uVar3 = 1;
        }
        else if (param_1 == 0x81003) {
          uVar3 = 2;
        }
        else if (param_1 == 0x81004) {
          uVar3 = 3;
        }
        else if (param_1 != 0x81005) {
          if (param_1 != 0x81006) {
            if (0x71007 < param_1) goto LAB_140004aba;
            if (param_1 == 0x71007) {
              uVar3 = 0x49;
            }
            else if (param_1 == 0x71001) {
              uVar3 = 0x44;
            }
            else if (param_1 == 0x71003) {
              uVar3 = 0x45;
            }
            else if (param_1 == 0x71004) {
              uVar3 = 0x46;
            }
            else if (param_1 == 0x71005) {
              uVar3 = 0x47;
            }
            else {
              if (param_1 != 0x71006) goto LAB_140004b45;
              uVar3 = 0x48;
            }
            goto LAB_140004b29;
          }
          uVar3 = 5;
        }
        goto LAB_140004b0a;
      }
      uVar3 = 0x1b;
    }
LAB_140004b29:
    if (uVar3 < 0x4e) {
      uVar2 = 0;
      LOCK();
      uVar1 = (&XdvRuleSuppression)[(int)uVar3];
      if (uVar1 == 0) {
        (&XdvRuleSuppression)[(int)uVar3] = 0;
      }
      else {
        uVar2 = (ulonglong)uVar1;
      }
      UNLOCK();
      return CONCAT71((int7)(uVar2 >> 8),uVar1 != 0);
    }
  }
  else {
    if (param_1 < 0x92012) {
      if (param_1 == 0x92011) {
        uVar3 = 0x28;
      }
      else if (param_1 < 0x91003) {
        if (param_1 == 0x91002) {
          uVar3 = 0x22;
        }
        else if (param_1 == 0x40007) {
          uVar3 = 0x1d;
        }
        else if (param_1 == 0x4000a) {
          uVar3 = 0x1e;
        }
        else if (param_1 == 0x4100b) {
          uVar3 = 0x1f;
        }
        else if (param_1 == 0x43006) {
          uVar3 = 0x20;
        }
        else {
          if (param_1 != 0x91001) {
            if (param_1 < 0x82002) {
              if (param_1 == 0x82001) {
                uVar3 = 0xc;
              }
              else if (param_1 < 0x81008) {
                if (param_1 != 0x81007) goto LAB_14000484c;
                uVar3 = 6;
              }
              else if (param_1 == 0x81008) {
                uVar3 = 7;
              }
              else if (param_1 == 0x81009) {
                uVar3 = 8;
              }
              else if (param_1 == 0x8100a) {
                uVar3 = 9;
              }
              else if (param_1 == 0x8100b) {
                uVar3 = 10;
              }
              else {
                if (param_1 != 0x8100c) goto LAB_140004aba;
                uVar3 = 0xb;
              }
              goto LAB_140004b0a;
            }
            goto LAB_140004aa2;
          }
          uVar3 = 0x21;
        }
      }
      else if (param_1 == 0x9100e) {
        uVar3 = 0x23;
      }
      else if (param_1 == 0x92003) {
        uVar3 = 0x24;
      }
      else if (param_1 == 0x9200d) {
        uVar3 = 0x25;
      }
      else if (param_1 == 0x9200f) {
        uVar3 = 0x26;
      }
      else {
        if (param_1 != 0x92010) goto LAB_140004aa2;
        uVar3 = 0x27;
      }
      goto LAB_140004b29;
    }
    if (param_1 < 0x94008) {
      if (param_1 == 0x94007) {
        uVar3 = 0x2e;
      }
      else if (param_1 == 0x92012) {
        uVar3 = 0x29;
      }
      else if (param_1 == 0x93004) {
        uVar3 = 0x2a;
      }
      else if (param_1 == 0x93005) {
        uVar3 = 0x2b;
      }
      else if (param_1 == 0x93006) {
        uVar3 = 0x2c;
      }
      else {
        if (param_1 != 0x93101) goto LAB_140004aa2;
        uVar3 = 0x2d;
      }
      goto LAB_140004b29;
    }
    if (param_1 == 0x94008) {
      uVar3 = 0x2f;
      goto LAB_140004b29;
    }
    if (param_1 == 0x94009) {
      uVar3 = 0x30;
      goto LAB_140004b29;
    }
    if (param_1 == 0x9400b) {
      uVar3 = 0x31;
      goto LAB_140004b29;
    }
    if (param_1 == 0x9400c) {
      uVar3 = 0x32;
      goto LAB_140004b29;
    }
LAB_140004aa2:
    if (param_1 == 0x82002) {
      uVar3 = 0xd;
LAB_140004b0a:
      uVar3 = uVar3 + 0x33;
      goto LAB_140004b29;
    }
    if (param_1 == 0x82003) {
      uVar3 = 0xe;
      goto LAB_140004b0a;
    }
    if (param_1 == 0x82004) {
      uVar3 = 0xf;
      goto LAB_140004b0a;
    }
    if (param_1 == 0x82005) {
      uVar3 = 0x10;
      goto LAB_140004b0a;
    }
LAB_140004aba:
    if (param_1 == 0x71008) {
      uVar3 = 0x4a;
      goto LAB_140004b29;
    }
    if (param_1 == 0x71009) {
      uVar3 = 0x4b;
      goto LAB_140004b29;
    }
    if (param_1 == 0x7100a) {
      uVar3 = 0x4c;
      goto LAB_140004b29;
    }
    if (param_1 == 0x72001) {
      uVar3 = 0x4d;
      goto LAB_140004b29;
    }
  }
LAB_140004b45:
  in_RAX = XdvUtilDbgPrint("Driver Verifier: XdvQueryRuleSuppression: wrong rule ID: %d\n",
                           (ulonglong)param_1,param_3,0);
LAB_140004b61:
  return in_RAX & 0xffffffffffffff00;
}



===== XdvReadRegistryKeyDword @ 140004bb0 =====

ulonglong XdvReadRegistryKeyDword(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  ulonglong uVar2;
  void *_Dst;
  uint local_res8 [2];
  longlong local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18 = 0;
  uVar2 = 0;
  local_2c = 0;
  local_res8[0] = 0;
  local_44 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((param_1 != 0) && (uVar2 = KeGetCurrentIrql(), (char)uVar2 == '\0')) {
    RtlInitUnicodeString(&local_58,&XdvRegistryRoot);
    local_40 = 0;
    local_38 = &local_58;
    local_48 = 0x30;
    local_30 = 0x240;
    local_28 = 0;
    uStack_20 = 0;
    uVar2 = ZwOpenKey(&local_res18,0x20019,&local_48);
    if (-1 < (int)uVar2) {
      uVar2 = ZwQueryValueKey(local_res18,param_1,2,0,0,local_res8);
      iVar1 = (int)uVar2;
      if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
        _Dst = (void *)ExAllocatePool2(0x40,local_res8[0],0x4e766458);
        if (_Dst == (void *)0x0) {
          iVar1 = -0x3fffff66;
          uVar2 = 0;
        }
        else {
          memset(_Dst,0,(ulonglong)local_res8[0]);
          iVar1 = ZwQueryValueKey(local_res18,param_1,2,_Dst,local_res8[0],local_res8);
          if (-1 < iVar1) {
            if (*(int *)((longlong)_Dst + 8) == 4) {
              *param_2 = *(undefined4 *)((longlong)_Dst + 0xc);
            }
            else {
              iVar1 = -0x3fffffff;
            }
          }
          uVar2 = ExFreePoolWithTag(_Dst,0x4e766458);
        }
      }
      if (local_res18 != 0) {
        uVar2 = ZwClose();
      }
      if (-1 < iVar1) {
        return CONCAT71((int7)(uVar2 >> 8),1);
      }
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== XdvReadRegistryKeyString @ 140004d64 =====

ulonglong XdvReadRegistryKeyString(longlong param_1,longlong *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  ulonglong in_RAX;
  void *_Dst;
  longlong lVar3;
  uint local_res8 [2];
  longlong local_res20;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res20 = 0;
  local_54 = 0;
  local_3c = 0;
  local_res8[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((param_1 != 0) && (param_2 != (longlong *)0x0)) && (param_3 != (int *)0x0)) &&
     (in_RAX = KeGetCurrentIrql(), (char)in_RAX == '\0')) {
    *param_2 = 0;
    *param_3 = 0;
    RtlInitUnicodeString(&local_68,&XdvRegistryRoot);
    local_48 = &local_68;
    local_58 = 0x30;
    local_50 = 0;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    in_RAX = ZwOpenKey(&local_res20,0x20019,&local_58);
    if (-1 < (int)in_RAX) {
      in_RAX = ZwQueryValueKey(local_res20,param_1,2,0,0,local_res8);
      iVar1 = (int)in_RAX;
      if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
        _Dst = (void *)ExAllocatePool2(0x40,local_res8[0],0x4e766458);
        if (_Dst == (void *)0x0) {
          iVar1 = -0x3fffff66;
          in_RAX = 0;
        }
        else {
          memset(_Dst,0,(ulonglong)local_res8[0]);
          iVar1 = ZwQueryValueKey(local_res20,param_1,2,_Dst,local_res8[0],local_res8);
          if (-1 < iVar1) {
            if (*(int *)((longlong)_Dst + 8) == 0) {
              iVar1 = -0x3fffffff;
            }
            else {
              iVar2 = *(int *)((longlong)_Dst + 8) + 2;
              *param_3 = iVar2;
              lVar3 = ExAllocatePool2(0x40,iVar2,0x4e766458);
              *param_2 = lVar3;
              if (lVar3 == 0) {
                iVar1 = -0x3fffff66;
              }
              else {
                *(undefined2 *)(lVar3 + (ulonglong)(*(uint *)((longlong)_Dst + 8) >> 1) * 2) = 0;
                memcpy((void *)*param_2,(void *)((longlong)_Dst + 0xc),
                       (ulonglong)*(uint *)((longlong)_Dst + 8));
              }
            }
          }
          in_RAX = ExFreePoolWithTag(_Dst,0x4e766458);
        }
      }
      if (local_res20 != 0) {
        in_RAX = ZwClose();
      }
      if (-1 < iVar1) {
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== XdvWriteRegistryKeyDword @ 140004f88 =====

bool XdvWriteRegistryKeyDword(longlong param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  longlong local_res8;
  undefined4 local_res10 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  bVar3 = false;
  local_res8 = 0;
  local_34 = 0;
  local_1c = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_1 != 0) {
    local_res10[0] = param_2;
    cVar1 = KeGetCurrentIrql();
    if (cVar1 == '\0') {
      RtlInitUnicodeString(&local_48,&XdvRegistryRoot);
      local_28 = &local_48;
      local_38 = 0x30;
      local_30 = 0;
      local_20 = 0x240;
      local_18 = 0;
      uStack_10 = 0;
      iVar2 = ZwOpenKey(&local_res8,0xf003f,&local_38);
      if (-1 < iVar2) {
        iVar2 = ZwSetValueKey(local_res8,param_1,0,4,local_res10,4);
        if (local_res8 != 0) {
          ZwClose();
        }
        bVar3 = -1 < iVar2;
      }
    }
  }
  return bVar3;
}



===== McGenControlCallbackV2 @ 140005090 =====

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



===== McGenEventRegister_EtwRegister @ 1400051a0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (EtwProvider_Context == 0) {
    EtwRegister(&EtwProvider,McGenControlCallbackV2,&EtwProvider_Context,&EtwProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1400051e0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (EtwProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    EtwProvider_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140005214 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1400322d8;
  uVar2 = 0;
  if (DAT_1400322d8 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1400322d8;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(EtwProvider_Context,param_2,&EtwProvider,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 14000527c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,&XdvLoad,param_3,1,local_28);
  return;
}



===== McTemplateK0dszud_EtwWriteTransfer @ 1400052c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0dszud_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_stack_00000028;
  undefined1 auStackY_c8 [32];
  undefined1 local_98 [8];
  undefined4 local_90 [2];
  undefined4 local_88 [4];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_68 = local_90;
  local_88[0] = 0;
  local_98[0] = 0;
  local_90[0] = 0;
  local_60 = 4;
  if (in_stack_00000028 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != '\0');
    local_50 = (int)lVar1 + 1;
  }
  local_4c = 0;
  local_48 = L"VerifierExt";
  local_38 = local_98;
  local_40 = 0x18;
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  local_28 = local_88;
  local_30 = 1;
  local_20 = 4;
  local_58 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&BugCheckEvent,0,6,local_78);
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 1400053a4 =====

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



===== DifPowerDelayPluginEntry @ 1400053f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifPowerDelayPluginEntry(void)

{
  int iVar1;
  undefined1 auStack_1f8 [32];
  char *local_1d8;
  undefined4 local_1d0;
  code *local_1c8;
  code *local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  code *local_1a0;
  char *local_198;
  undefined4 local_190;
  code *local_188;
  code *local_180;
  char *local_178;
  undefined4 local_170;
  code *local_168;
  code *local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  code *local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  code *local_120;
  char *local_118;
  undefined4 local_110;
  code *local_108;
  code *local_100;
  char *local_f8;
  undefined4 local_f0;
  code *local_e8;
  code *local_e0;
  char *local_d8;
  undefined4 local_d0;
  code *local_c8;
  code *local_c0;
  char *local_b8;
  undefined4 local_b0;
  code *local_a8;
  code *local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  code *local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  code *local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  code *local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1f8;
  local_1d0 = 0xc0;
  local_1d8 = "PoFxCompleteDevicePowerNotRequired";
  local_1c8 = PoFxCompleteDevicePowerNotRequired_delay_entry;
  local_1c0 = PoFxCompleteDevicePowerNotRequired_delay_entry;
  local_1b8 = "PoFxCompleteIdleCondition";
  local_1a8 = PoFxCompleteIdleCondition_delay_exit;
  local_1a0 = PoFxCompleteIdleCondition_delay_exit;
  local_198 = "PoFxCompleteIdleState";
  local_188 = PoFxCompleteIdleState_delay_exit;
  local_180 = PoFxCompleteIdleState_delay_exit;
  local_178 = "PoFxIdleComponent";
  local_168 = PoFxIdleComponent_delay_entry;
  local_160 = PoFxIdleComponent_delay_entry;
  local_158 = "PoFxNotifySurprisePowerOn";
  local_148 = PoFxNotifySurprisePowerOn_delay_exit;
  local_140 = PoFxNotifySurprisePowerOn_delay_exit;
  local_138 = "PoFxPowerControl";
  local_128 = PoFxPowerControl_delay_exit;
  local_120 = PoFxPowerControl_delay_exit;
  local_118 = "PoFxRegisterDevice";
  local_108 = PoFxRegisterDevice_delay_entry;
  local_100 = PoFxRegisterDevice_delay_entry;
  local_f8 = "PoFxReportDevicePoweredOn";
  local_e8 = PoFxReportDevicePoweredOn_delay_entry;
  local_e0 = PoFxReportDevicePoweredOn_delay_entry;
  local_d8 = "PoFxSetComponentLatency";
  local_c8 = PoFxSetComponentLatency_delay_entry;
  local_c0 = PoFxSetComponentLatency_delay_entry;
  local_b8 = "PoFxSetComponentResidency";
  local_a8 = PoFxSetComponentResidency_delay_exit;
  local_a0 = PoFxSetComponentResidency_delay_exit;
  local_98 = "PoFxSetComponentWake";
  local_88 = PoFxSetComponentWake_delay_exit;
  local_80 = PoFxSetComponentWake_delay_exit;
  local_78 = "PoFxSetDeviceIdleTimeout";
  local_1b0 = 0xbf;
  local_190 = 0xbe;
  local_170 = 0xbd;
  local_150 = 0xbc;
  local_130 = 0xbb;
  local_110 = 0xba;
  local_f0 = 0xb9;
  local_d0 = 0xb8;
  local_b0 = 0xb7;
  local_90 = 0xb6;
  local_70 = 0xb5;
  local_68 = PoFxSetDeviceIdleTimeout_delay_entry;
  local_50 = 0xb4;
  local_30 = 0xb3;
  local_60 = PoFxSetDeviceIdleTimeout_delay_entry;
  local_58 = "PoFxStartDevicePowerManagement";
  local_48 = PoFxStartDevicePowerManagement_delay_exit;
  local_40 = PoFxStartDevicePowerManagement_delay_exit;
  local_38 = "PoFxUnregisterDevice";
  local_28 = PoFxUnregisterDevice_delay_entry;
  local_20 = PoFxUnregisterDevice_delay_entry;
  iVar1 = DifRegisterPlugin(&local_1d8,0xe,0xf);
  if (-1 < iVar1) {
    LOCK();
    DAT_140032614 = DAT_140032614 + -1;
    UNLOCK();
  }
  return;
}



===== PoFxCompleteDevicePowerNotRequired_delay_entry @ 1400056c0 =====

void PoFxCompleteDevicePowerNotRequired_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xc0);
  return;
}



===== PoFxCompleteIdleCondition_delay_exit @ 1400056e0 =====

void PoFxCompleteIdleCondition_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xbf);
  return;
}



===== PoFxCompleteIdleState_delay_exit @ 140005700 =====

void PoFxCompleteIdleState_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xbe);
  return;
}



===== PoFxIdleComponent_delay_entry @ 140005720 =====

void PoFxIdleComponent_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xbd);
  return;
}



===== PoFxNotifySurprisePowerOn_delay_exit @ 140005740 =====

void PoFxNotifySurprisePowerOn_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xbc);
  return;
}



===== PoFxPowerControl_delay_exit @ 140005760 =====

void PoFxPowerControl_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xbb);
  return;
}



===== PoFxRegisterDevice_delay_entry @ 140005780 =====

void PoFxRegisterDevice_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xba);
  return;
}



===== PoFxReportDevicePoweredOn_delay_entry @ 1400057a0 =====

void PoFxReportDevicePoweredOn_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb9);
  return;
}



===== PoFxSetComponentLatency_delay_entry @ 1400057c0 =====

void PoFxSetComponentLatency_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb8);
  return;
}



===== PoFxSetComponentResidency_delay_exit @ 1400057e0 =====

void PoFxSetComponentResidency_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb7);
  return;
}



===== PoFxSetComponentWake_delay_exit @ 140005800 =====

void PoFxSetComponentWake_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb6);
  return;
}



===== PoFxSetDeviceIdleTimeout_delay_entry @ 140005820 =====

void PoFxSetDeviceIdleTimeout_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb5);
  return;
}



===== PoFxStartDevicePowerManagement_delay_exit @ 140005840 =====

void PoFxStartDevicePowerManagement_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb4);
  return;
}



===== PoFxUnregisterDevice_delay_entry @ 140005860 =====

void PoFxUnregisterDevice_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0,0xb3);
  return;
}



===== DifSyncDelayPluginEntry @ 140005880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifSyncDelayPluginEntry(void)

{
  int iVar1;
  undefined1 auStack_5b8 [32];
  char *local_598;
  undefined4 local_590;
  code *local_588;
  code *local_580;
  char *local_578;
  undefined4 local_570;
  code *local_568;
  code *local_560;
  char *local_558;
  undefined4 local_550;
  code *local_548;
  code *local_540;
  char *local_538;
  undefined4 local_530;
  code *local_528;
  code *local_520;
  char *local_518;
  undefined4 local_510;
  code *local_508;
  code *local_500;
  char *local_4f8;
  undefined4 local_4f0;
  code *local_4e8;
  code *local_4e0;
  char *local_4d8;
  undefined4 local_4d0;
  code *local_4c8;
  code *local_4c0;
  char *local_4b8;
  undefined4 local_4b0;
  code *local_4a8;
  code *local_4a0;
  char *local_498;
  undefined4 local_490;
  code *local_488;
  code *local_480;
  char *local_478;
  undefined4 local_470;
  code *local_468;
  code *local_460;
  char *local_458;
  undefined4 local_450;
  code *local_448;
  code *local_440;
  char *local_438;
  undefined4 local_430;
  code *local_428;
  code *local_420;
  char *local_418;
  undefined4 local_410;
  code *local_408;
  code *local_400;
  char *local_3f8;
  undefined4 local_3f0;
  code *local_3e8;
  code *local_3e0;
  char *local_3d8;
  undefined4 local_3d0;
  code *local_3c8;
  code *local_3c0;
  char *local_3b8;
  undefined4 local_3b0;
  code *local_3a8;
  code *local_3a0;
  char *local_398;
  undefined4 local_390;
  code *local_388;
  code *local_380;
  char *local_378;
  undefined4 local_370;
  code *local_368;
  code *local_360;
  char *local_358;
  undefined4 local_350;
  code *local_348;
  code *local_340;
  char *local_338;
  undefined4 local_330;
  code *local_328;
  code *local_320;
  char *local_318;
  undefined4 local_310;
  code *local_308;
  code *local_300;
  char *local_2f8;
  undefined4 local_2f0;
  code *local_2e8;
  code *local_2e0;
  char *local_2d8;
  undefined4 local_2d0;
  code *local_2c8;
  code *local_2c0;
  char *local_2b8;
  undefined4 local_2b0;
  code *local_2a8;
  code *local_2a0;
  char *local_298;
  undefined4 local_290;
  code *local_288;
  code *local_280;
  char *local_278;
  undefined4 local_270;
  code *local_268;
  code *local_260;
  char *local_258;
  undefined4 local_250;
  code *local_248;
  code *local_240;
  char *local_238;
  undefined4 local_230;
  code *local_228;
  code *local_220;
  char *local_218;
  undefined4 local_210;
  code *local_208;
  code *local_200;
  char *local_1f8;
  undefined4 local_1f0;
  code *local_1e8;
  code *local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  code *local_1c8;
  code *local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  code *local_1a0;
  char *local_198;
  undefined4 local_190;
  code *local_188;
  code *local_180;
  char *local_178;
  undefined4 local_170;
  code *local_168;
  code *local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  code *local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  code *local_120;
  char *local_118;
  undefined4 local_110;
  code *local_108;
  code *local_100;
  char *local_f8;
  undefined4 local_f0;
  code *local_e8;
  code *local_e0;
  char *local_d8;
  undefined4 local_d0;
  code *local_c8;
  code *local_c0;
  char *local_b8;
  undefined4 local_b0;
  code *local_a8;
  code *local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  code *local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  code *local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  code *local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_5b8;
  local_590 = 0x10000004;
  local_598 = "IRP_MJ_WRITE";
  local_588 = IRP_MJ_WRITE_delay_entry;
  local_580 = IRP_MJ_WRITE_delay_entry;
  local_578 = "IRP_MJ_SYSTEM_CONTROL";
  local_568 = IRP_MJ_SYSTEM_CONTROL_delay_entry;
  local_560 = IRP_MJ_SYSTEM_CONTROL_delay_entry;
  local_558 = "IRP_MJ_SHUTDOWN";
  local_548 = IRP_MJ_SHUTDOWN_delay_entry;
  local_540 = IRP_MJ_SHUTDOWN_delay_entry;
  local_538 = "IRP_MJ_SET_VOLUME_INFORMATION";
  local_528 = IRP_MJ_SET_VOLUME_INFORMATION_delay_entry;
  local_520 = IRP_MJ_SET_VOLUME_INFORMATION_delay_entry;
  local_518 = "IRP_MJ_SET_SECURITY";
  local_508 = IRP_MJ_SET_SECURITY_delay_entry;
  local_500 = IRP_MJ_SET_SECURITY_delay_entry;
  local_4f8 = "IRP_MJ_SET_QUOTA";
  local_4e8 = IRP_MJ_SET_QUOTA_delay_exit;
  local_4e0 = IRP_MJ_SET_QUOTA_delay_exit;
  local_4d8 = "IRP_MJ_SET_INFORMATION";
  local_4c8 = IRP_MJ_SET_INFORMATION_delay_exit;
  local_4c0 = IRP_MJ_SET_INFORMATION_delay_exit;
  local_4b8 = "IRP_MJ_SET_EA";
  local_4a8 = IRP_MJ_SET_EA_delay_exit;
  local_4a0 = IRP_MJ_SET_EA_delay_exit;
  local_498 = "IRP_MJ_READ";
  local_488 = IRP_MJ_READ_delay_exit;
  local_480 = IRP_MJ_READ_delay_exit;
  local_478 = "IRP_MJ_QUERY_VOLUME_INFORMATION";
  local_468 = IRP_MJ_QUERY_VOLUME_INFORMATION_delay_exit;
  local_460 = IRP_MJ_QUERY_VOLUME_INFORMATION_delay_exit;
  local_458 = "IRP_MJ_QUERY_SECURITY";
  local_448 = IRP_MJ_QUERY_SECURITY_delay_exit;
  local_440 = IRP_MJ_QUERY_SECURITY_delay_exit;
  local_438 = "IRP_MJ_QUERY_QUOTA";
  local_570 = 0x10000017;
  local_550 = 0x10000010;
  local_530 = 0x1000000b;
  local_510 = 0x10000015;
  local_4f0 = 0x1000001a;
  local_4d0 = 0x10000006;
  local_4b0 = 0x10000008;
  local_490 = 0x10000003;
  local_470 = 0x1000000a;
  local_450 = 0x10000014;
  local_430 = 0x10000019;
  local_428 = IRP_MJ_QUERY_QUOTA_delay_entry;
  local_420 = IRP_MJ_QUERY_QUOTA_delay_entry;
  local_418 = "IRP_MJ_QUERY_INFORMATION";
  local_408 = IRP_MJ_QUERY_INFORMATION_delay_entry;
  local_400 = IRP_MJ_QUERY_INFORMATION_delay_entry;
  local_3f8 = "IRP_MJ_QUERY_EA";
  local_3e8 = IRP_MJ_QUERY_EA_delay_entry;
  local_3e0 = IRP_MJ_QUERY_EA_delay_entry;
  local_3d8 = "IRP_MJ_POWER";
  local_3c8 = IRP_MJ_POWER_delay_exit;
  local_3c0 = IRP_MJ_POWER_delay_exit;
  local_3b8 = "IRP_MJ_PNP";
  local_3a8 = IRP_MJ_PNP_delay_entry;
  local_3a0 = IRP_MJ_PNP_delay_entry;
  local_398 = "IRP_MJ_LOCK_CONTROL";
  local_388 = IRP_MJ_LOCK_CONTROL_delay_exit;
  local_380 = IRP_MJ_LOCK_CONTROL_delay_exit;
  local_378 = "IRP_MJ_INTERNAL_DEVICE_CONTROL";
  local_368 = IRP_MJ_INTERNAL_DEVICE_CONTROL_delay_entry;
  local_360 = IRP_MJ_INTERNAL_DEVICE_CONTROL_delay_entry;
  local_358 = "IRP_MJ_FLUSH_BUFFERS";
  local_348 = IRP_MJ_FLUSH_BUFFERS_delay_entry;
  local_340 = IRP_MJ_FLUSH_BUFFERS_delay_entry;
  local_338 = "IRP_MJ_FILE_SYSTEM_CONTROL";
  local_328 = IRP_MJ_FILE_SYSTEM_CONTROL_delay_exit;
  local_320 = IRP_MJ_FILE_SYSTEM_CONTROL_delay_exit;
  local_318 = "IRP_MJ_DIRECTORY_CONTROL";
  local_308 = IRP_MJ_DIRECTORY_CONTROL_delay_entry;
  local_300 = IRP_MJ_DIRECTORY_CONTROL_delay_entry;
  local_2f8 = "IRP_MJ_DEVICE_CONTROL";
  local_2e8 = IRP_MJ_DEVICE_CONTROL_delay_exit;
  local_2e0 = IRP_MJ_DEVICE_CONTROL_delay_exit;
  local_2d8 = "IRP_MJ_DEVICE_CHANGE";
  local_2c8 = IRP_MJ_DEVICE_CHANGE_delay_entry;
  local_2c0 = IRP_MJ_DEVICE_CHANGE_delay_entry;
  local_410 = 0x10000005;
  local_3f0 = 0x10000007;
  local_3d0 = 0x10000016;
  local_3b0 = 0x1000001b;
  local_390 = 0x10000011;
  local_370 = 0x1000000f;
  local_350 = 0x10000009;
  local_330 = 0x1000000d;
  local_310 = 0x1000000c;
  local_2f0 = 0x1000000e;
  local_2d0 = 0x10000018;
  local_2b8 = "IRP_MJ_CREATE_NAMED_PIPE";
  local_2a8 = IRP_MJ_CREATE_NAMED_PIPE_delay_exit;
  local_2a0 = IRP_MJ_CREATE_NAMED_PIPE_delay_exit;
  local_298 = "IRP_MJ_CREATE_MAILSLOT";
  local_288 = IRP_MJ_CREATE_MAILSLOT_delay_entry;
  local_280 = IRP_MJ_CREATE_MAILSLOT_delay_entry;
  local_278 = "IRP_MJ_CREATE";
  local_268 = IRP_MJ_CREATE_delay_entry;
  local_260 = IRP_MJ_CREATE_delay_entry;
  local_258 = "IRP_MJ_CLOSE";
  local_248 = IRP_MJ_CLOSE_delay_entry;
  local_240 = IRP_MJ_CLOSE_delay_entry;
  local_238 = "IRP_MJ_CLEANUP";
  local_228 = IRP_MJ_CLEANUP_delay_entry;
  local_220 = IRP_MJ_CLEANUP_delay_entry;
  local_218 = "KeAcquireInStackQueuedSpinLock";
  local_208 = KeAcquireInStackQueuedSpinLock_delay_entry;
  local_200 = KeAcquireInStackQueuedSpinLock_delay_entry;
  local_1f8 = "KeAcquireInStackQueuedSpinLockAtDpcLevel";
  local_1e8 = KeAcquireInStackQueuedSpinLockAtDpcLevel_delay_exit;
  local_1e0 = KeAcquireInStackQueuedSpinLockAtDpcLevel_delay_exit;
  local_1d8 = "KeAcquireInStackQueuedSpinLockForDpc";
  local_1c8 = KeAcquireInStackQueuedSpinLockForDpc_delay_exit;
  local_1c0 = KeAcquireInStackQueuedSpinLockForDpc_delay_exit;
  local_1b8 = "KeAcquireQueuedSpinLock";
  local_1a8 = KeAcquireQueuedSpinLock_delay_entry;
  local_1a0 = KeAcquireQueuedSpinLock_delay_entry;
  local_198 = "KeAcquireSpinLockAtDpcLevel";
  local_188 = KeAcquireSpinLockAtDpcLevel_delay_exit;
  local_180 = KeAcquireSpinLockAtDpcLevel_delay_exit;
  local_178 = "KeAcquireSpinLockRaiseToDpc";
  local_168 = KeAcquireSpinLockRaiseToDpc_delay_entry;
  local_160 = KeAcquireSpinLockRaiseToDpc_delay_entry;
  local_158 = "KeReleaseSpinLock";
  local_148 = KeReleaseSpinLock_delay_exit;
  local_2b0 = 0x10000001;
  local_290 = 0x10000013;
  local_270 = 0x10000000;
  local_250 = 0x10000002;
  local_230 = 0x10000012;
  local_210 = 0x12a;
  local_1f0 = 0x129;
  local_1d0 = 0x128;
  local_1b0 = 0x126;
  local_190 = 0x124;
  local_170 = 0x123;
  local_150 = 0x102;
  local_130 = 0x101;
  local_140 = KeReleaseSpinLock_delay_exit;
  local_110 = 0x108;
  local_138 = "KeReleaseSpinLockFromDpcLevel";
  local_f0 = 0x107;
  local_128 = KeReleaseSpinLockFromDpcLevel_delay_exit;
  local_120 = KeReleaseSpinLockFromDpcLevel_delay_exit;
  local_118 = "KeReleaseInStackQueuedSpinLock";
  local_d0 = 0x106;
  local_108 = KeReleaseInStackQueuedSpinLock_delay_exit;
  local_b0 = 0x105;
  local_100 = KeReleaseInStackQueuedSpinLock_delay_exit;
  local_f8 = "KeReleaseInStackQueuedSpinLockForDpc";
  local_e8 = KeReleaseInStackQueuedSpinLockForDpc_delay_exit;
  local_e0 = KeReleaseInStackQueuedSpinLockForDpc_delay_exit;
  local_d8 = "KeReleaseInStackQueuedSpinLockFromDpcLevel";
  local_c8 = KeReleaseInStackQueuedSpinLockFromDpcLevel_delay_exit;
  local_c0 = KeReleaseInStackQueuedSpinLockFromDpcLevel_delay_exit;
  local_b8 = "KeReleaseMutant";
  local_a8 = KeReleaseMutant_delay_exit;
  local_a0 = KeReleaseMutant_delay_exit;
  local_98 = "KeReleaseMutex";
  local_88 = KeReleaseMutex_delay_entry;
  local_80 = KeReleaseMutex_delay_entry;
  local_78 = "KeReleaseQueuedSpinLock";
  local_68 = KeReleaseQueuedSpinLock_delay_exit;
  local_60 = KeReleaseQueuedSpinLock_delay_exit;
  local_58 = "KeTryToAcquireQueuedSpinLock";
  local_48 = KeTryToAcquireQueuedSpinLock_delay_exit;
  local_40 = KeTryToAcquireQueuedSpinLock_delay_exit;
  local_38 = "KeTryToAcquireSpinLockAtDpcLevel";
  local_28 = KeTryToAcquireSpinLockAtDpcLevel_delay_entry;
  local_20 = KeTryToAcquireSpinLockAtDpcLevel_delay_entry;
  local_90 = 0x104;
  local_70 = 0x103;
  local_50 = 0xf4;
  local_30 = 0xf2;
  iVar1 = DifRegisterPlugin(&local_598,0x2c,0x17);
  if (-1 < iVar1) {
    LOCK();
    DAT_140032614 = DAT_140032614 + -1;
    UNLOCK();
  }
  return;
}



===== IRP_MJ_CLEANUP_delay_entry @ 140006160 =====

void IRP_MJ_CLEANUP_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffee);
  return;
}



===== IRP_MJ_CLOSE_delay_entry @ 140006190 =====

void IRP_MJ_CLOSE_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffffe);
  return;
}



===== IRP_MJ_CREATE_MAILSLOT_delay_entry @ 1400061c0 =====

void IRP_MJ_CREATE_MAILSLOT_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffed);
  return;
}



===== IRP_MJ_CREATE_NAMED_PIPE_delay_exit @ 1400061f0 =====

void IRP_MJ_CREATE_NAMED_PIPE_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffff);
  return;
}



===== IRP_MJ_CREATE_delay_entry @ 140006220 =====

void IRP_MJ_CREATE_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0);
  return;
}



===== IRP_MJ_DEVICE_CHANGE_delay_entry @ 140006240 =====

void IRP_MJ_DEVICE_CHANGE_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffe8);
  return;
}



===== IRP_MJ_DEVICE_CONTROL_delay_exit @ 140006270 =====

void IRP_MJ_DEVICE_CONTROL_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff2);
  return;
}



===== IRP_MJ_DIRECTORY_CONTROL_delay_entry @ 1400062a0 =====

void IRP_MJ_DIRECTORY_CONTROL_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff4);
  return;
}



===== IRP_MJ_FILE_SYSTEM_CONTROL_delay_exit @ 1400062d0 =====

void IRP_MJ_FILE_SYSTEM_CONTROL_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff3);
  return;
}



===== IRP_MJ_FLUSH_BUFFERS_delay_entry @ 140006300 =====

void IRP_MJ_FLUSH_BUFFERS_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff7);
  return;
}



===== IRP_MJ_INTERNAL_DEVICE_CONTROL_delay_entry @ 140006330 =====

void IRP_MJ_INTERNAL_DEVICE_CONTROL_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff1);
  return;
}



===== IRP_MJ_LOCK_CONTROL_delay_exit @ 140006360 =====

void IRP_MJ_LOCK_CONTROL_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffef);
  return;
}



===== IRP_MJ_PNP_delay_entry @ 140006390 =====

void IRP_MJ_PNP_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffe5);
  return;
}



===== IRP_MJ_POWER_delay_exit @ 1400063c0 =====

void IRP_MJ_POWER_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffea);
  return;
}



===== IRP_MJ_QUERY_EA_delay_entry @ 1400063f0 =====

void IRP_MJ_QUERY_EA_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff9);
  return;
}



===== IRP_MJ_QUERY_INFORMATION_delay_entry @ 140006420 =====

void IRP_MJ_QUERY_INFORMATION_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffffb);
  return;
}



===== IRP_MJ_QUERY_QUOTA_delay_entry @ 140006450 =====

void IRP_MJ_QUERY_QUOTA_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffe7);
  return;
}



===== IRP_MJ_QUERY_SECURITY_delay_exit @ 140006480 =====

void IRP_MJ_QUERY_SECURITY_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffec);
  return;
}



===== IRP_MJ_QUERY_VOLUME_INFORMATION_delay_exit @ 1400064b0 =====

void IRP_MJ_QUERY_VOLUME_INFORMATION_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff6);
  return;
}



===== IRP_MJ_READ_delay_exit @ 1400064e0 =====

void IRP_MJ_READ_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffffd);
  return;
}



===== IRP_MJ_SET_EA_delay_exit @ 140006510 =====

void IRP_MJ_SET_EA_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff8);
  return;
}



===== IRP_MJ_SET_INFORMATION_delay_exit @ 140006540 =====

void IRP_MJ_SET_INFORMATION_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffffa);
  return;
}



===== IRP_MJ_SET_QUOTA_delay_exit @ 140006570 =====

void IRP_MJ_SET_QUOTA_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffe6);
  return;
}



===== IRP_MJ_SET_SECURITY_delay_entry @ 1400065a0 =====

void IRP_MJ_SET_SECURITY_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffeb);
  return;
}



===== IRP_MJ_SET_VOLUME_INFORMATION_delay_entry @ 1400065d0 =====

void IRP_MJ_SET_VOLUME_INFORMATION_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff5);
  return;
}



===== IRP_MJ_SHUTDOWN_delay_entry @ 140006600 =====

void IRP_MJ_SHUTDOWN_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffff0);
  return;
}



===== IRP_MJ_SYSTEM_CONTROL_delay_entry @ 140006630 =====

void IRP_MJ_SYSTEM_CONTROL_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xffffffe9);
  return;
}



===== IRP_MJ_WRITE_delay_entry @ 140006660 =====

void IRP_MJ_WRITE_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xfffffffc);
  return;
}



===== KeAcquireInStackQueuedSpinLockAtDpcLevel_delay_exit @ 140006690 =====

void KeAcquireInStackQueuedSpinLockAtDpcLevel_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x129);
  return;
}



===== KeAcquireInStackQueuedSpinLockForDpc_delay_exit @ 1400066c0 =====

void KeAcquireInStackQueuedSpinLockForDpc_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x128);
  return;
}



===== KeAcquireInStackQueuedSpinLock_delay_entry @ 1400066f0 =====

void KeAcquireInStackQueuedSpinLock_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x12a);
  return;
}



===== KeAcquireQueuedSpinLock_delay_entry @ 140006720 =====

void KeAcquireQueuedSpinLock_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x126);
  return;
}



===== KeAcquireSpinLockAtDpcLevel_delay_exit @ 140006750 =====

void KeAcquireSpinLockAtDpcLevel_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x124);
  return;
}



===== KeAcquireSpinLockRaiseToDpc_delay_entry @ 140006780 =====

void KeAcquireSpinLockRaiseToDpc_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x123);
  return;
}



===== KeReleaseInStackQueuedSpinLockForDpc_delay_exit @ 1400067b0 =====

void KeReleaseInStackQueuedSpinLockForDpc_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x107);
  return;
}



===== KeReleaseInStackQueuedSpinLockFromDpcLevel_delay_exit @ 1400067e0 =====

void KeReleaseInStackQueuedSpinLockFromDpcLevel_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x106);
  return;
}



===== KeReleaseInStackQueuedSpinLock_delay_exit @ 140006810 =====

void KeReleaseInStackQueuedSpinLock_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x108);
  return;
}



===== KeReleaseMutant_delay_exit @ 140006840 =====

void KeReleaseMutant_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x105);
  return;
}



===== KeReleaseMutex_delay_entry @ 140006870 =====

void KeReleaseMutex_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x104);
  return;
}



===== KeReleaseQueuedSpinLock_delay_exit @ 1400068a0 =====

void KeReleaseQueuedSpinLock_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x103);
  return;
}



===== KeReleaseSpinLockFromDpcLevel_delay_exit @ 1400068d0 =====

void KeReleaseSpinLockFromDpcLevel_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x101);
  return;
}



===== KeReleaseSpinLock_delay_exit @ 140006900 =====

void KeReleaseSpinLock_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0x102);
  return;
}



===== KeTryToAcquireQueuedSpinLock_delay_exit @ 140006930 =====

void KeTryToAcquireQueuedSpinLock_delay_exit(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xf4);
  return;
}



===== KeTryToAcquireSpinLockAtDpcLevel_delay_entry @ 140006960 =====

void KeTryToAcquireSpinLockAtDpcLevel_delay_entry(undefined8 param_1,undefined8 param_2)

{
  CuzzSchedule(param_1,param_2,0x10000,0xf2);
  return;
}



===== CuzzInit @ 140006984 =====

/* WARNING: Removing unreachable block (ram,0x0001400069c3) */
/* WARNING: Removing unreachable block (ram,0x0001400069cd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool CuzzInit(undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar5;
  char *pcVar6;
  
  if (CuzzStateInfo == 2) {
    bVar2 = true;
  }
  else if (CuzzStateInfo == 0) {
    LOCK();
    CuzzStateInfo = 1;
    UNLOCK();
    if (CuzzOpts == 0) {
      CuzzOpts = _DAT_fffff78000000008;
    }
    lVar5 = CuzzOpts;
    CuzzSRand((int)CuzzOpts);
    TinfoTableInit();
    _CuzzStats = 0;
    _DAT_1400793ac = 0;
    _DAT_1400793b0 = 0;
    _DAT_1400793b8 = 0;
    if (DAT_14003289c == 0) {
      DAT_14003289c = 3;
    }
    if (DAT_14003289c - 3U < 2) {
      PCTInit(lVar5,param_2,param_3,param_4);
    }
    cVar1 = '{';
    pcVar4 = &DAT_14003af20;
    do {
      *pcVar4 = cVar1;
      pcVar6 = pcVar4 + 1;
      cVar1 = pcVar4[-0x1a20b];
      pcVar4 = pcVar6;
    } while (cVar1 != '\0');
    pcVar4 = "CuzzRandomSeed=";
    cVar1 = 'C';
    do {
      pcVar4 = pcVar4 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar4;
    } while (cVar1 != '\0');
    iVar3 = cuzz_itoa(CuzzOpts,pcVar6);
    pcVar4 = "}}";
    pcVar6 = pcVar6 + iVar3;
    cVar1 = '}';
    do {
      pcVar4 = pcVar4 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar4;
    } while (cVar1 != '\0');
    _DAT_140032620 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
    if (DAT_140032868 != 0) {
      LOCK();
      DAT_140032614 = DAT_140032614 + 1;
      UNLOCK();
    }
    LOCK();
    CuzzStateInfo = 2;
    UNLOCK();
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



===== CuzzSchedule @ 140006af4 =====

ulonglong CuzzSchedule(undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  uint uVar1;
  bool bVar2;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  ulonglong uVar3;
  uint *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar6 = param_4;
  uVar5 = param_3;
  if (CuzzStateInfo != 2) {
    bVar2 = CuzzInit(param_1,param_2,param_3,param_4);
    if ((int)CONCAT71(extraout_var,bVar2) == 0) {
      return CONCAT71(extraout_var,bVar2);
    }
  }
  uVar3 = (ulonglong)DAT_140032614;
  if ((int)DAT_140032614 < 1) {
    bVar2 = NativeCuzzEnabledForCurrentContext();
    uVar3 = CONCAT71(extraout_var_00,bVar2);
    if ((int)uVar3 != 0) {
      uVar3 = NativeGetCurrentTaskId();
      puVar4 = TinfoTableGetTinfo(uVar3 & 0xffffffff);
      uVar3 = 0;
      if (puVar4 != (uint *)0x0) {
        LOCK();
        uVar1 = *puVar4;
        if (uVar1 == 2) {
          *puVar4 = 1;
        }
        UNLOCK();
        if (uVar1 != 2) {
          uVar3 = 0;
          LOCK();
          uVar1 = *puVar4;
          if (uVar1 == 0) {
            *puVar4 = 1;
          }
          else {
            uVar3 = (ulonglong)uVar1;
          }
          UNLOCK();
          if (uVar1 != 0) {
            return uVar3;
          }
          CuzzTaskBegin((longlong)puVar4,param_2,uVar5,uVar6);
        }
        uVar3 = CuzzScheduleInternal2((ulonglong)puVar4,param_2,uVar5,param_3 & 0xffffffff,param_4);
        LOCK();
        *puVar4 = 2;
        UNLOCK();
      }
    }
  }
  return uVar3;
}



===== CuzzScheduleInternal2 @ 140006b98 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CuzzScheduleInternal2
               (ulonglong param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4,
               ulonglong param_5)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 in_stack_ffffffffffffffe8;
  
  uVar6 = param_4 << 0x38 ^ param_5;
  uVar2 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  *(undefined8 *)(param_1 + 0x20) = uVar2;
  uVar4 = 1;
  uVar3 = (*(longlong *)(param_1 + 0x20) - *(longlong *)(param_1 + 0x28)) * 1000000;
  uVar5 = uVar3 % CuzzLastKnownFrequency;
  *(longlong *)(param_1 + 0x38) = *(longlong *)(param_1 + 0x38) + uVar3 / CuzzLastKnownFrequency;
  if ((param_4 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 1;
  }
  if ((param_4 & 2) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  _CuzzStats = _CuzzStats + 1;
  if (1 < DAT_140032618) {
    _DAT_1400793a4 = _DAT_1400793a4 + 1;
  }
  if (DAT_14003289c != 1) {
    if (DAT_14003289c == 2) {
      if (DAT_1400328a0 != 0) {
        uVar1 = CuzzRand();
        uVar5 = (ulonglong)uVar1 % (ulonglong)DAT_1400328a0;
        if (((int)uVar5 == 0) && (DAT_1400328a4 != 0)) {
          uVar1 = CuzzRand();
          uVar5 = (ulonglong)uVar1 % (ulonglong)DAT_1400328a4;
          if (0 < (int)uVar5) {
            uVar1 = (int)uVar5 * 1000;
            uVar4 = (ulonglong)uVar1;
            NativeSleep(uVar1);
          }
        }
      }
    }
    else if (DAT_14003289c - 3U < 2) {
      uVar4 = param_1;
      PCTStep(param_1,uVar5,param_3,(char *)(param_4 & 0xffffffff),in_stack_ffffffffffffffe8,uVar6);
    }
  }
  if (DAT_140032648 != 0) {
    logSyncOp(uVar4,uVar5,param_4 & 0xffffffff,param_1,uVar6);
  }
  uVar2 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  *(undefined8 *)(param_1 + 0x28) = uVar2;
  *(longlong *)(param_1 + 0x30) =
       *(longlong *)(param_1 + 0x30) +
       (ulonglong)((*(longlong *)(param_1 + 0x28) - *(longlong *)(param_1 + 0x20)) * 1000000) /
       CuzzLastKnownFrequency;
  return;
}



===== CuzzTaskBegin @ 140006cf0 =====

void CuzzTaskBegin(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  iVar1 = DAT_140032618;
  LOCK();
  DAT_140032618 = DAT_140032618 + 1;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(int *)(param_1 + 8) = iVar1 + 1;
  *(undefined4 *)(param_1 + 0x18) = 1;
  uVar2 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x28) = uVar2;
  *(undefined8 *)(param_1 + 0x20) = uVar2;
  *(undefined8 *)(param_1 + 0x38) = 1;
  if (DAT_140032648 != 0) {
    logPrefix(param_1,param_2,param_3,param_4);
    cuzz_write_cstr(" begin tid: ",param_2,param_3,param_4);
    uVar3 = NativeGetCurrentTaskId();
    cuzz_write_int(uVar3 & 0xffffffff,param_2,param_3,param_4);
    cuzz_write_cstr(" hash: ",param_2,param_3,param_4);
    cuzz_write_int((longlong)*(int *)(param_1 + 0xc),param_2,param_3,param_4);
    cuzz_write_cstr("\n",param_2,param_3,param_4);
  }
  return;
}



===== StarvPolicyStarvationFactor @ 140006da0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong StarvPolicyStarvationFactor(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar2 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  if (0 < DAT_140032878) {
    uVar5 = *(longlong *)(param_1 + 0x30) + *(longlong *)(param_1 + 0x38);
    uVar3 = NativeCurrentCuzzInterruptLevel();
    iVar1 = DAT_14003287c;
    if ((int)uVar3 < 1) {
      iVar1 = DAT_140032878;
    }
    lVar4 = (longlong)iVar1 * *(longlong *)(param_1 + 0x38);
    if (lVar4 < (longlong)uVar5) goto LAB_140006dfb;
    if (lVar4 != 0) goto LAB_140006e11;
  }
  if (DAT_140032870 < 1) {
    return 0;
  }
  uVar5 = (ulonglong)((lVar2 - *(longlong *)(param_1 + 0x20)) * 1000000) / CuzzLastKnownFrequency;
  lVar4 = DAT_140032870;
  if ((longlong)uVar5 <= DAT_140032870) {
LAB_140006e11:
    return (longlong)(uVar5 * 100) / lVar4;
  }
LAB_140006dfb:
  _DAT_1400793b8 = _DAT_1400793b8 + 1;
  return 100;
}



===== NativeCurrentCuzzInterruptLevel @ 140006e64 =====

undefined8 NativeCurrentCuzzInterruptLevel(void)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = KeGetCurrentIrql();
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    uVar2 = 0;
  }
  else if (cVar1 == '\x02') {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}



===== NativeCuzzEnabledForCurrentContext @ 140006ea4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool NativeCuzzEnabledForCurrentContext(void)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  ulonglong local_8;
  
  local_8 = (ulonglong)(in_NT & 1) * 0x4000 | (ulonglong)(in_OF & 1) * 0x800 |
            (ulonglong)(in_IF & 1) * 0x200 | (ulonglong)(in_TF & 1) * 0x100 |
            (ulonglong)(in_SF & 1) * 0x80 | (ulonglong)(in_ZF & 1) * 0x40 |
            (ulonglong)(in_AF & 1) * 0x10 | (ulonglong)(in_PF & 1) * 4 | (ulonglong)(in_CF & 1) |
            (ulonglong)(in_ID & 1) * 0x200000 | (ulonglong)(in_VIP & 1) * 0x100000 |
            (ulonglong)(in_VIF & 1) * 0x80000 | (ulonglong)(in_AC & 1) * 0x40000;
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar3 = NativeCurrentCuzzInterruptLevel();
  if (((int)uVar3 == 2) || (((uint)local_8 >> 9 & 1) == 0)) {
LAB_140006f2d:
    bVar1 = false;
  }
  else {
    iVar2 = KeQueryDpcWatchdogInformation(&local_28);
    if (-1 < iVar2) {
      if (((local_28._4_4_ != 0) && ((uint)local_28 != 0)) &&
         ((uint)(local_28._4_4_ << 2) < (uint)local_28)) goto LAB_140006f2d;
      if ((uStack_20._4_4_ != 0) && ((uint)uStack_20 != 0)) {
        return (uint)uStack_20 <= (uint)(uStack_20._4_4_ << 2);
      }
    }
    bVar1 = true;
  }
  return bVar1;
}



===== NativeGetCurrentTaskId @ 140006f4c =====

ulonglong NativeGetCurrentTaskId(void)

{
  byte bVar1;
  byte bVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar3 = NativeCurrentCuzzInterruptLevel();
  bVar1 = SystemReserved1[0xe]._4_1_;
  if ((int)uVar3 == 0) {
    uVar4 = PsGetCurrentThreadId();
  }
  else {
    bVar2 = KeGetCurrentIrql();
    uVar4 = (ulonglong)((uint)bVar2 << 0x18 | (uint)bVar1);
  }
  return uVar4;
}



===== NativeSleep @ 140006f98 =====

ulonglong NativeSleep(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong local_res10 [3];
  
  bVar1 = NativeCuzzEnabledForCurrentContext();
  uVar3 = CONCAT71(extraout_var,bVar1);
  if ((int)uVar3 != 0) {
    uVar3 = NativeCurrentCuzzInterruptLevel();
    if ((int)uVar3 != 2) {
      if (((int)uVar3 == 0) && (iVar2 = KeIsExecutingDpc(), iVar2 == 0)) {
        local_res10[0] = (ulonglong)param_1 * -10;
        uVar4 = KeDelayExecutionThread(0,0,local_res10);
      }
      else {
        uVar4 = KeStallExecutionProcessor((ulonglong)param_1);
      }
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== LogPriorityChange @ 140007008 =====

void LogPriorityChange(longlong param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  
  if (DAT_140032648 != 0) {
    pcVar1 = param_2;
    logPrefix(param_1,param_2,param_3,param_4);
    cuzz_write_cstr(" pri change: ",pcVar1,param_3,param_4);
    cuzz_write_int((ulonglong)*(uint *)(param_1 + 0x10),pcVar1,param_3,param_4);
    cuzz_write_cstr(" phs: ",pcVar1,param_3,param_4);
    cuzz_write_int((ulonglong)*(uint *)(param_1 + 0x14),pcVar1,param_3,param_4);
    cuzz_write_cstr(" reason: ",pcVar1,param_3,param_4);
    cuzz_write_cstr(param_2,pcVar1,param_3,param_4);
    cuzz_write_cstr("\r\n",pcVar1,param_3,param_4);
  }
  return;
}



===== LogYield @ 140007080 =====

void LogYield(longlong param_1,undefined8 param_2,longlong param_3,char *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  char *pcVar4;
  
  if (DAT_14003264c != 0) {
    uVar2 = param_2;
    lVar3 = param_3;
    pcVar4 = param_4;
    logPrefix(param_1,param_2,param_3,param_4);
    cuzz_write_cstr(" yield ",uVar2,lVar3,pcVar4);
    cuzz_write_int(param_3,uVar2,lVar3,pcVar4);
    cuzz_write_cstr(" musecs, reason: ",uVar2,lVar3,pcVar4);
    cuzz_write_cstr(param_4,uVar2,lVar3,pcVar4);
    cuzz_write_cstr("\n",uVar2,lVar3,pcVar4);
  }
  LOCK();
  UNLOCK();
  uVar1 = DAT_140032dc8 & 0xfff;
  DAT_140032dc8 = DAT_140032dc8 + 2;
  *(undefined8 *)(&DAT_140032f10 + (ulonglong)uVar1 * 8) = param_2;
  *(longlong *)(&DAT_140032f10 + (ulonglong)(uVar1 + 1) * 8) = param_3;
  return;
}



===== cuzz_itoa @ 140007118 =====

int cuzz_itoa(longlong param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  pcVar4 = param_2;
  lVar3 = -param_1;
  iVar6 = 0;
  if (-param_1 < 0) {
    lVar3 = param_1;
  }
  do {
    iVar5 = iVar6;
    iVar6 = iVar5 + 1;
    lVar2 = lVar3 / 10;
    *pcVar4 = (char)lVar3 + (char)lVar2 * -10 + '0';
    pcVar4 = pcVar4 + 1;
    if (lVar2 < 1) break;
    lVar3 = lVar2;
  } while (iVar6 < 99);
  if ((param_1 < 0) && (iVar6 < 99)) {
    lVar3 = (longlong)iVar6;
    iVar6 = iVar5 + 2;
    param_2[lVar3] = '-';
  }
  if (iVar6 < 100) {
    param_2[iVar6] = '\0';
  }
  if (0 < (longlong)iVar6 + -1) {
    pcVar4 = param_2 + (longlong)iVar6 + -1;
    lVar3 = -(longlong)param_2;
    do {
      cVar1 = *param_2;
      *param_2 = *pcVar4;
      param_2 = param_2 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + -1;
    } while (lVar3 + (longlong)param_2 < lVar3 + (longlong)pcVar4);
  }
  return iVar6;
}



===== cuzz_write_cstr @ 1400071dc =====

void cuzz_write_cstr(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*param_1 != '\0') {
    pcVar1 = param_1;
    do {
      pcVar1 = pcVar1 + 1;
      uVar2 = (ulonglong)((int)uVar2 + 1);
    } while (*pcVar1 != '\0');
  }
  XdvUtilDbgPrint(param_1,uVar2,param_3,param_4);
  return;
}



===== cuzz_write_int @ 140007204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void cuzz_write_int(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined1 auStack_a8 [32];
  char local_88 [112];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  uVar2 = 100;
  memset(local_88,0,100);
  pcVar1 = local_88;
  cuzz_itoa(param_1,pcVar1);
  cuzz_write_cstr(local_88,pcVar1,uVar2,param_4);
  return;
}



===== logPrefix @ 14000726c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void logPrefix(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  
  cuzz_write_cstr("usec:",param_2,param_3,param_4);
  lVar1 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  uVar2 = (lVar1 - _DAT_140032620) * 1000000;
  uVar3 = uVar2 % CuzzLastKnownFrequency;
  cuzz_write_int(uVar2 / CuzzLastKnownFrequency,uVar3,param_3,param_4);
  cuzz_write_cstr(" ",uVar3,param_3,param_4);
  cuzz_write_cstr(": ",uVar3,param_3,param_4);
  if ((*(int *)(param_1 + 8) < 6) && (iVar4 = 1, 1 < *(int *)(param_1 + 8))) {
    do {
      cuzz_write_cstr("   ",uVar3,param_3,param_4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 8));
  }
  cuzz_write_cstr("[",uVar3,param_3,param_4);
  cuzz_write_int((longlong)*(int *)(param_1 + 8),uVar3,param_3,param_4);
  cuzz_write_cstr("]",uVar3,param_3,param_4);
  return;
}



===== logSyncOp @ 140007328 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void logSyncOp(undefined8 param_1,undefined8 param_2,ulonglong param_3,longlong param_4,
              longlong param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_48 [32];
  undefined1 local_28 [16];
  undefined1 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = param_3;
  lVar3 = param_4;
  logPrefix(param_4,param_2,param_3,param_4);
  cuzz_write_cstr(" step var:",param_2,uVar1,lVar3);
  local_18 = 0;
  lVar2 = 0xf;
  do {
    local_28[lVar2] = 0x30;
    lVar2 = lVar2 + -1;
  } while (-1 < lVar2);
  uVar1 = 0x10;
  XdvUtilDbgPrint(local_28,0x10,lVar2,lVar3);
  cuzz_write_cstr(" sop:",uVar1,lVar2,lVar3);
  cuzz_write_int(0,uVar1,lVar2,lVar3);
  if ((int)param_3 != 0) {
    cuzz_write_cstr(" f:",uVar1,lVar2,lVar3);
    if ((param_3 & 1) != 0) {
      cuzz_write_cstr("B",uVar1,lVar2,lVar3);
    }
    if ((param_3 & 2) != 0) {
      cuzz_write_cstr("E",uVar1,lVar2,lVar3);
    }
    if ((param_3 & 4) != 0) {
      cuzz_write_cstr("N",uVar1,lVar2,lVar3);
    }
    if ((param_3 & 8) != 0) {
      cuzz_write_cstr("R",uVar1,lVar2,lVar3);
    }
    if ((param_3 & 0x10) != 0) {
      cuzz_write_cstr("Y",uVar1,lVar2,lVar3);
    }
  }
  cuzz_write_cstr(" tin:",uVar1,lVar2,lVar3);
  cuzz_write_int(*(longlong *)(param_4 + 0x30),uVar1,lVar2,lVar3);
  cuzz_write_cstr(" tout:",uVar1,lVar2,lVar3);
  cuzz_write_int(*(longlong *)(param_4 + 0x38),uVar1,lVar2,lVar3);
  if (DAT_14003265c == 2) {
    cuzz_write_cstr(" bt:",uVar1,lVar2,lVar3);
    uVar1 = param_5 % (longlong)DAT_1400328ac;
    cuzz_write_int(uVar1 & 0xffffffff,uVar1,lVar2,lVar3);
  }
  cuzz_write_cstr("\r\n",uVar1,lVar2,lVar3);
  return;
}



===== TinfoTableGetTinfo @ 140007490 =====

undefined4 * TinfoTableGetTinfo(ulonglong param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar5 = 0;
  lVar6 = 4;
  do {
    uVar4 = param_1 & 0xff;
    param_1 = (ulonglong)(uint)((int)param_1 >> 8);
    uVar5 = uVar5 ^ (&DAT_140058f20)[uVar4];
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar2 = NativeCurrentCuzzInterruptLevel();
  if ((int)uVar2 == 0) {
    puVar3 = &DAT_140044f20;
    uVar5 = uVar5 & 0x3ff;
  }
  else {
    if ((int)uVar2 != 1) {
      pcVar1 = (code *)swi(3);
      puVar3 = (undefined4 *)(*pcVar1)();
      return puVar3;
    }
    uVar5 = uVar5 & 0xff;
    puVar3 = &DAT_14003ff20;
  }
  return puVar3 + (ulonglong)uVar5 * 0x14;
}



===== TinfoTableInit @ 1400074fc =====

void TinfoTableInit(void)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint *puVar6;
  longlong lVar7;
  
  iVar1 = 0;
  piVar4 = &DAT_140044f2c;
  puVar5 = &DAT_140044f20;
  lVar7 = 0x400;
  do {
    *piVar4 = iVar1;
    iVar1 = iVar1 + 1;
    *puVar5 = 0;
    puVar5 = puVar5 + 0x14;
    piVar4 = piVar4 + 0x14;
  } while (iVar1 < 0x400);
  iVar1 = 0;
  piVar4 = &DAT_14003ff2c;
  puVar5 = &DAT_14003ff20;
  do {
    *piVar4 = iVar1;
    iVar1 = iVar1 + 1;
    *puVar5 = 0;
    puVar5 = puVar5 + 0x14;
    piVar4 = piVar4 + 0x14;
  } while (iVar1 < 0x100);
  puVar6 = &DAT_140058f20;
  do {
    uVar2 = CuzzRand();
    *puVar6 = uVar2;
    puVar6 = puVar6 + 1;
  } while ((longlong)puVar6 < 0x140059320);
  puVar3 = &DAT_14003bf28;
  puVar5 = &DAT_14003bf20;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 2;
    *puVar5 = 0;
    puVar5 = puVar5 + 4;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  return;
}



===== CuzzRand @ 1400075bc =====

uint CuzzRand(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  LOCK();
  iVar1 = mersenneIndex + 1;
  UNLOCK();
  iVar4 = mersenneIndex + 1;
  iVar3 = (int)((ulonglong)((longlong)iVar4 * 0x2df2df2d) >> 0x20) - iVar4;
  iVar4 = iVar4 + ((iVar3 >> 9) - (iVar3 >> 0x1f)) * 0x270;
  mersenneIndex = iVar1;
  if (iVar4 == 0) {
    GenerateMersenneTable();
  }
  uVar2 = (&MT)[iVar4] ^ (uint)(&MT)[iVar4] >> 0xb;
  uVar2 = uVar2 ^ (uVar2 & 0xff3a58ad) << 7;
  uVar2 = uVar2 ^ (uVar2 & 0xffffdf8c) << 0xf;
  return uVar2 >> 0x12 ^ uVar2;
}



===== CuzzSRand @ 140007634 =====

void CuzzSRand(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  
  piVar2 = &DAT_1400789e4;
  iVar4 = 1;
  MT = param_1;
  do {
    iVar1 = ((uint)piVar2[-1] >> 0x1e ^ piVar2[-1]) * 0x6c078965 + iVar4;
    iVar4 = iVar4 + 1;
    *piVar2 = iVar1;
    piVar2 = piVar2 + 1;
  } while ((longlong)piVar2 < 0x1400793a0);
  lVar3 = 100;
  do {
    GenerateMersenneTable();
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



===== GenerateMersenneTable @ 140007694 =====

void GenerateMersenneTable(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  longlong lVar5;
  
  iVar4 = 0x18d;
  puVar3 = &MT;
  lVar5 = 0x270;
  do {
    uVar2 = ((&MT)[(iVar4 + -0x18c) % 0x270] & 0x7fffffff) - ((int)*puVar3 >> 0x1f);
    uVar1 = uVar2 >> 1 ^ (&MT)[iVar4 % 0x270];
    *puVar3 = uVar1;
    if ((uVar2 & 1) != 0) {
      *puVar3 = uVar1 ^ 0x9908b0df;
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}



===== PCTInit @ 140007744 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PCTInit(undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  pctPhase = 0;
  if (DAT_14003265c == 2) {
    uVar5 = DAT_1400328ac;
    if (0x400 < DAT_1400328ac) {
      DAT_140077840 = 0x400;
      goto LAB_140007793;
    }
  }
  else {
    uVar5 = 0;
  }
  DAT_140077840 = uVar5;
LAB_140007793:
  DAT_140077844 = DAT_1400328b0;
  DAT_140077880 = DAT_140032664;
  if (uVar5 != 0) {
    _DAT_140077864 = 0;
    uVar1 = 0;
    _DAT_140077868 = 0;
    _DAT_14007786c = 0;
    _DAT_140077870 = 0;
    _DAT_140077874 = 0;
    _DAT_140077878 = 0;
    _DAT_14007787c = 0;
    if (DAT_140077840 != 0) {
      do {
        (&scState)[uVar1] = 0xffffffff;
        uVar5 = (int)uVar1 + 1;
        uVar1 = (ulonglong)uVar5;
      } while (uVar5 < DAT_140077840);
    }
    lVar8 = 10;
    lVar7 = 10;
    uVar1 = ((ulonglong)DAT_140077844 - 1 << 0x20) / (ulonglong)DAT_140077844;
    uVar6 = 0xffffffff;
    uVar2 = (uVar1 * uVar1) / 0xffffffff;
    uVar3 = (((uVar2 * uVar2) / 0xffffffff) * uVar1) / 0xffffffff;
    param_3 = (uVar3 * uVar3) / 0xffffffff;
    do {
      uVar6 = (uVar6 * param_3) / 0xffffffff;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    uVar4 = 0xffffffff;
    do {
      uVar4 = (uVar4 * uVar6) / 0xffffffff;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    DAT_14007784c = (undefined4)uVar1;
    DAT_140077850 = (undefined4)uVar2;
    DAT_140077854 = (undefined4)uVar3;
    DAT_140077858 = (undefined4)param_3;
    DAT_14007785c = (undefined4)uVar6;
    DAT_140077860 = (undefined4)uVar4;
    param_4 = 0;
  }
  PCTStateReset(pctPhase,DAT_140032664,param_3,param_4);
  uVar5 = pctPhase & 0x80000001;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
  }
  *(undefined4 *)(&DAT_140078128 + (longlong)(int)uVar5 * 0x8a0) = 0;
  return;
}



===== PCTIsLowestPriority @ 1400078f4 =====

undefined8 PCTIsLowestPriority(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_2 + 0x808);
  iVar6 = 0;
  do {
    iVar5 = 0x20;
    if (DAT_1400328a8 < 0x20) {
      iVar5 = DAT_1400328a8;
    }
    if (iVar5 <= iVar6) {
      return 0;
    }
    uVar4 = *puVar7;
    uVar3 = *(uint *)(param_1 + 0x10);
    if (uVar4 == uVar3) {
      return 1;
    }
    if (uVar3 < uVar4) {
      do {
        puVar1 = (uint *)(param_2 + 0x808 + (longlong)iVar6 * 4);
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar3;
          uVar2 = uVar4;
        }
        else {
        }
        UNLOCK();
        if (uVar4 < uVar2) {
          return 0;
        }
        if (uVar2 == uVar4) {
          return 1;
        }
        uVar3 = *(uint *)(param_1 + 0x10);
      } while ((uVar3 <= uVar2) && (uVar4 = uVar2, uVar3 < uVar2));
    }
    iVar6 = iVar6 + 1;
    puVar7 = puVar7 + 1;
  } while( true );
}



===== PCTStateReset @ 140007970 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PCTStateReset(int param_1,int param_2,ulonglong param_3,ulonglong param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  bool bVar13;
  
  iVar9 = DAT_140032640;
  uVar2 = param_1 + 1U & 0x80000001;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
  }
  lVar12 = (longlong)(int)uVar2 * 0x8a0;
  puVar1 = (uint *)(&pctState + lVar12);
  uVar2 = DAT_14003263c;
  if (DAT_14003263c == 0) {
    uVar2 = DAT_140077880;
    if (DAT_140032660 != 0) {
      uVar2 = DAT_140032660;
    }
    if (param_2 != 0) {
      DAT_140077880 = param_2 + DAT_140077880 * 3 >> 2;
    }
    if (DAT_140032664 < uVar2) {
      uVar8 = DAT_140032664 >> 1;
      uVar3 = CuzzRand();
      uVar2 = uVar3 % (uVar2 - uVar8) + uVar8;
    }
  }
  if (iVar9 == 0) {
    uVar3 = CuzzRand();
    if (uVar3 % 3 < 2) {
      iVar9 = uVar3 % 3 + 1;
    }
    else {
      iVar9 = 3;
      uVar3 = CuzzRand();
      if ((uVar3 & 1) == 0) goto LAB_140007a47;
      do {
        iVar9 = iVar9 + 1;
        uVar3 = CuzzRand();
      } while ((uVar3 & 1) != 0);
    }
    iVar6 = 0;
    if (iVar9 == 0) goto LAB_140007a4c;
  }
LAB_140007a47:
  iVar6 = 2;
LAB_140007a4c:
  ResetWeights(puVar1);
  *puVar1 = 0;
  *(uint *)(&DAT_1400778a4 + lVar12) = uVar2;
  uVar3 = DAT_140032664;
  if (uVar2 == 0) {
    *(uint *)(&DAT_1400778a4 + lVar12) = DAT_140032664;
    uVar2 = uVar3;
  }
  uVar3 = iVar6 - 1;
  *(uint *)(&DAT_1400778a8 + lVar12) = uVar3;
  if (0xfe < uVar3) {
    uVar3 = 0xfe;
    *(undefined4 *)(&DAT_1400778a8 + lVar12) = 0xfe;
  }
  uVar7 = 0;
  *(undefined4 *)(&DAT_1400780a4 + lVar12) = 0;
  if ((uVar3 + 1 <= uVar2) && (uVar3 != 0)) {
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        uVar3 = CuzzRand();
        uVar2 = uVar2 + 1;
        param_4 = (ulonglong)uVar2;
        uVar3 = uVar3 % *(uint *)(&DAT_1400778a4 + lVar12);
        param_3 = 0;
        uVar8 = (uint)uVar7;
        if (uVar8 != 0) {
          puVar4 = (uint *)(&DAT_1400778ac + lVar12);
          do {
            if (uVar3 <= *puVar4) break;
            uVar10 = (int)param_3 + 1;
            param_3 = (ulonglong)uVar10;
            puVar4 = puVar4 + 2;
          } while (uVar10 < uVar8);
        }
        uVar10 = (uint)param_3;
        if (uVar10 == uVar8) {
LAB_140007b09:
          uVar7 = (ulonglong)(uVar8 + 1);
          *(uint *)(&DAT_1400778ac + param_3 * 8 + lVar12) = uVar3;
LAB_140007b10:
          *(uint *)(&DAT_1400778b0 + param_3 * 8 + lVar12) = uVar2;
        }
        else {
          if (*(uint *)(&DAT_1400778ac + param_3 * 8 + lVar12) != uVar3) {
            if (uVar10 < uVar8) {
              puVar4 = puVar1 + uVar7 * 2 + 3;
              do {
                uVar11 = (int)uVar7 - 1;
                uVar7 = (ulonglong)uVar11;
                *(undefined8 *)puVar4 = *(undefined8 *)(&DAT_1400778ac + uVar7 * 8 + lVar12);
                puVar4 = puVar4 + -2;
              } while (uVar10 < uVar11);
            }
            goto LAB_140007b09;
          }
          if (uVar2 < *(uint *)(&DAT_1400778b0 + param_3 * 8 + lVar12)) goto LAB_140007b10;
        }
      } while (uVar2 < *(uint *)(&DAT_1400778a8 + lVar12));
    }
    *(int *)(&DAT_1400780a4 + lVar12) = (int)uVar7;
  }
  uVar7 = 0;
  while( true ) {
    iVar9 = 0x20;
    if (DAT_1400328a8 < 0x20) {
      iVar9 = DAT_1400328a8;
    }
    iVar6 = (int)uVar7;
    if (iVar9 <= iVar6) break;
    uVar7 = (ulonglong)(iVar6 + 1);
    *(undefined4 *)(&DAT_1400780a8 + lVar12 + (longlong)iVar6 * 4) = 0xffffffff;
  }
  uVar5 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
  *(undefined4 *)(&DAT_140078128 + lVar12) = 0;
  _DAT_1400793ac = _DAT_1400793ac + 1;
  bVar13 = DAT_140032650 != 0;
  *(undefined8 *)(&DAT_140078130 + lVar12) = uVar5;
  *(undefined4 *)(&DAT_140078138 + lVar12) = 1;
  if (bVar13) {
    cuzz_write_cstr("RESET: ",uVar7,param_3,param_4);
    cuzz_write_int((longlong)param_1 + 1,uVar7,param_3,param_4);
    cuzz_write_cstr("\n",uVar7,param_3,param_4);
  }
  LOCK();
  pctPhase = param_1 + 1U;
  UNLOCK();
  return;
}



===== PCTStep @ 140007be4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PCTStep(longlong param_1,undefined8 param_2,ulonglong param_3,char *param_4,
                 undefined8 param_5,longlong param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 extraout_var;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  uint *puVar13;
  int iVar14;
  char *pcVar15;
  int iVar16;
  uint local_res18;
  
  lVar12 = (((ulonglong)param_4 & 0xffffffff) >> 0x10 & 1) * 0x10;
  iVar1 = *(int *)(&DAT_1400328c4 + lVar12);
  iVar2 = *(int *)(&CuzzContextParameters + lVar12);
  local_res18 = *(uint *)(&DAT_1400328bc + lVar12);
  pcVar15 = param_4;
  uVar6 = NativeCurrentCuzzInterruptLevel();
  if (0 < (int)uVar6) {
    local_res18 = *(uint *)(&DAT_1400328c0 + lVar12);
  }
  iVar14 = 0;
  iVar16 = iVar14;
  do {
    uVar10 = pctPhase;
    iVar16 = iVar16 + 1;
    uVar4 = pctPhase & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    lVar12 = (longlong)(int)uVar4 * 0x8a0;
    puVar13 = (uint *)(&pctState + lVar12);
    uVar4 = StepcounterRecordStep(puVar13,param_6);
    uVar8 = CONCAT44(extraout_var,uVar4);
    if (uVar4 != 0xfffffffe) {
      if (uVar4 == 0xffffffff) {
        uVar3 = *puVar13;
        lVar7 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
        uVar8 = (ulonglong)((lVar7 - *(longlong *)(&DAT_140078130 + lVar12)) * 1000000) /
                CuzzLastKnownFrequency;
        uVar5 = 0;
        if (0 < (longlong)uVar8) {
          uVar5 = (uint)(((longlong)iVar1 * (ulonglong)uVar3) / uVar8);
        }
LAB_140007d61:
        uVar8 = PCTStateReset(uVar10,uVar5,param_3,(ulonglong)pcVar15);
      }
      else {
        if ((0xff < DAT_140077880) && (uVar8 = (ulonglong)*puVar13, (char)*puVar13 != -1)) break;
        lVar7 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
        uVar8 = (ulonglong)((lVar7 - *(longlong *)(&DAT_140078130 + lVar12)) * 1000000) /
                CuzzLastKnownFrequency;
        if ((longlong)uVar8 <= (longlong)iVar1) break;
        uVar8 = (ulonglong)*(uint *)(&DAT_140078138 + lVar12);
        if (*(uint *)(&DAT_140078138 + lVar12) == 1) {
          uVar8 = 1;
          LOCK();
          uVar5 = *(uint *)(&DAT_140078138 + lVar12);
          if (uVar5 == 1) {
            *(uint *)(&DAT_140078138 + lVar12) = 0;
          }
          else {
            uVar8 = (ulonglong)uVar5;
          }
          UNLOCK();
          if (uVar5 == 1) {
            uVar5 = *puVar13;
            goto LAB_140007d61;
          }
        }
      }
    }
  } while (iVar16 < 10);
  if (9 < iVar16) {
    return uVar8;
  }
  if (*(uint *)(param_1 + 0x14) != uVar10) {
    uVar5 = CuzzRand();
    *(uint *)(param_1 + 0x10) = (uVar5 & 0x7fffffff) + DAT_140032640;
    *(uint *)(param_1 + 0x14) = uVar10;
    uVar8 = LogPriorityChange(param_1,"new phase init",param_3,pcVar15);
  }
  if (uVar4 != 0) {
    *(uint *)(param_1 + 0x14) = uVar10;
    *(uint *)(param_1 + 0x10) = uVar4 - 1;
    uVar8 = LogPriorityChange(param_1,"change point",param_3,pcVar15);
  }
  if (DAT_14003289c != 3) {
    return uVar8;
  }
  uVar8 = PCTIsLowestPriority(param_1,(longlong)puVar13);
  if ((int)uVar8 == 0) {
LAB_140007fc6:
    LOCK();
    *(undefined4 *)(&DAT_140078128 + lVar12) = 0;
    UNLOCK();
  }
  else {
    if (((byte)param_4 & 10) == 10) {
      lVar7 = *(longlong *)(param_1 + 0x20);
      lVar9 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
      pcVar15 = "waitforvar";
      param_3 = (ulonglong)((lVar9 - lVar7) * 1000000) / CuzzLastKnownFrequency;
      LogYield(param_1,lVar9,param_3,"waitforvar");
      uVar8 = PCTIsLowestPriority(param_1,(longlong)puVar13);
      if ((int)uVar8 == 0) goto LAB_140007fc6;
    }
    if (*(int *)(&DAT_140078128 + lVar12) < 4) {
      lVar7 = StarvPolicyStarvationFactor(param_1);
      uVar8 = 1;
      uVar10 = (uint)((int)lVar7 < 0x60);
      uVar11 = (ulonglong)uVar10;
      if ((DAT_140032648 == 0) || (uVar10 != 0)) {
        if (uVar10 != 0) {
          LOCK();
          _CuzzYieldCount = _CuzzYieldCount + 1;
          UNLOCK();
          *(undefined4 *)(param_1 + 0x18) = 2;
          LOCK();
          *(int *)(&DAT_140078128 + lVar12) = *(int *)(&DAT_140078128 + lVar12) + 1;
          UNLOCK();
          lVar7 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
          if (0 < iVar2) {
            do {
              NativeSleep(local_res18);
              lVar9 = StarvPolicyStarvationFactor(param_1);
              if ((int)lVar9 == 100) {
                LOCK();
                _CuzzYieldAbortStarvationDuring = _CuzzYieldAbortStarvationDuring + 1;
                UNLOCK();
                break;
              }
              uVar6 = PCTIsLowestPriority(param_1,(longlong)puVar13);
              if ((int)uVar6 == 0) {
                LOCK();
                *(undefined4 *)(&DAT_140078128 + lVar12) = 0;
                UNLOCK();
                break;
              }
              lVar9 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
              if ((longlong)(int)(local_res18 * iVar2) <
                  (longlong)((ulonglong)((lVar9 - lVar7) * 1000000) / CuzzLastKnownFrequency)) {
                LOCK();
                _CuzzYieldAbortTimeout = _CuzzYieldAbortTimeout + 1;
                UNLOCK();
                break;
              }
              iVar14 = iVar14 + 1;
            } while (iVar14 < iVar2);
          }
          lVar12 = KeQueryPerformanceCounter(&CuzzLastKnownFrequency);
          uVar8 = LogYield(param_1,lVar12,
                           (ulonglong)((lVar12 - lVar7) * 1000000) / CuzzLastKnownFrequency,"lowpri"
                          );
          *(undefined4 *)(param_1 + 0x18) = 1;
        }
      }
      else {
        LOCK();
        _CuzzYieldAbortStarvationPre = _CuzzYieldAbortStarvationPre + 1;
        UNLOCK();
        cuzz_write_int((longlong)*(int *)(param_1 + 8),0,param_3,pcVar15);
        cuzz_write_cstr(" has high starvation: ",uVar11,param_3,pcVar15);
        cuzz_write_int((longlong)(int)lVar7,uVar11,param_3,pcVar15);
        uVar8 = cuzz_write_cstr(" not yielding\n",uVar11,param_3,pcVar15);
      }
    }
  }
  return uVar8;
}



===== ResetWeights @ 140007fe4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ResetWeights(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (DAT_140077840 == 0) {
    _DAT_140077864 = _DAT_140077864 + *param_1;
    return *param_1;
  }
  uVar1 = *param_1 * 0x10624dd3;
  _DAT_140077864 = _DAT_140077864 + *param_1 / 1000;
  if (DAT_140077840 != 0) {
    do {
      uVar1 = (&scState)[uVar3];
      if (DAT_140077860 < uVar1) {
        if (DAT_14007785c < uVar1) {
          if (DAT_140077858 < uVar1) {
            if (DAT_140077854 < uVar1) {
              if (DAT_140077850 < uVar1) {
                if (uVar1 <= DAT_14007784c) {
                  _DAT_140077868 = _DAT_140077868 + 1;
                }
              }
              else {
                _DAT_14007786c = _DAT_14007786c + 1;
              }
            }
            else {
              _DAT_140077870 = _DAT_140077870 + 1;
            }
          }
          else {
            _DAT_140077874 = _DAT_140077874 + 1;
          }
        }
        else {
          _DAT_140077878 = _DAT_140077878 + 1;
        }
      }
      else {
        _DAT_14007787c = _DAT_14007787c + 1;
      }
      (&scState)[uVar3] = 0xffffffff;
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < DAT_140077840);
  }
  return uVar1;
}



===== StepcounterRecordStep @ 14000809c =====

uint StepcounterRecordStep(uint *param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  if (DAT_140077840 == 0) {
    LOCK();
    uVar1 = *param_1;
    *param_1 = *param_1 + 1;
    UNLOCK();
    uVar4 = uVar1 + 1;
  }
  else {
    uVar3 = param_2 % (longlong)(ulonglong)DAT_140077840 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    *param_1 = *param_1;
    UNLOCK();
    uVar4 = uVar4 / 1000;
    (&scState)[uVar3] =
         (int)(((ulonglong)(uint)(&scState)[uVar3] * (ulonglong)DAT_14007784c) / 0xffffffff);
    uVar1 = uVar4;
  }
  if (param_1[0x201] != 0) {
    puVar2 = param_1 + 3;
    do {
      if ((uVar1 < *puVar2) && (*puVar2 <= uVar4)) {
        return param_1[uVar6 * 2 + 4];
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      puVar2 = puVar2 + 2;
    } while (uVar5 < param_1[0x201]);
  }
  uVar5 = param_1[1];
  if ((uVar1 < uVar5) && (uVar5 <= uVar4)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = -(uint)(uVar5 < uVar4) & 0xfffffffe;
  }
  return uVar1;
}



===== AutoFailInitialize @ 14000816c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AutoFailInitialize(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  longlong lVar4;
  longlong lVar5;
  
  memset(&AutofailStackData,0,0x10100);
  puVar3 = &DAT_14005af00;
  lVar5 = 0x20;
  do {
    lVar4 = lVar5;
    KeInitializeSpinLock(puVar3);
    puVar3 = puVar3 + 0x808;
    lVar5 = lVar4 + -1;
  } while (lVar5 != 0);
  DAT_14007682c = 0;
  iVar1 = (int)lVar4;
  DAT_140076828 = iVar1 + 0x13;
  _DAT_140076830 = 0;
  AutofailDrivers = ExAllocatePool2(iVar1 + 0x3f,DAT_140076828 * 0x18,0x66617664);
  if (AutofailDrivers == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    memset(&AutofailStackHistory,0,0xc008);
    memset(&AutofailExemptedStacks,0,0x808);
    uVar2 = 0;
    _AutofailConfig = 0;
    _DAT_14005a6e8 = 0;
    _DAT_14005a6f0 = 0;
  }
  return uVar2;
}



===== AutoFailInject @ 140008250 =====

ulonglong AutoFailInject(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  ulonglong uVar1;
  bool bVar2;
  
                    /* 0x8250  1  AutoFailInject */
  uVar1 = 0;
  LOCK();
  bVar2 = DAT_14005a6e4 == 0;
  if (bVar2) {
    DAT_14005a6e4 = 0;
  }
  else {
    uVar1 = (ulonglong)DAT_14005a6e4;
  }
  UNLOCK();
  if ((!bVar2) && (uVar1 = AutofailInjectStack(), (char)uVar1 != '\0')) {
    if (AutofailConfig != 2) {
      if (DAT_14005a6f4 != '\0') {
        uVar1 = XdvUtilDbgPrint("VerifierExt!%s: injecting failure for function %s\n",
                                "AutoFailInject",param_1,param_4);
      }
      return CONCAT71((int7)(uVar1 >> 8),1);
    }
    if (DAT_14005a6f4 != '\0') {
      uVar1 = XdvUtilDbgPrint("VerifierExt!%s: would have injected failure for function %s\n",
                              "AutoFailInject",param_1,param_4);
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



===== AutofailAddDriver @ 1400082d4 =====

void AutofailAddDriver(ulonglong param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong *_Src;
  undefined4 uVar1;
  undefined1 uVar2;
  void *_Dst;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  
  uVar1 = DAT_140032de4;
  uVar4 = 0;
  uVar6 = (char)param_4;
  if (DAT_14005a6f5 != '\0') {
    uVar6 = 0;
  }
  uVar2 = ExAcquireSpinLockExclusive(&DAT_140076830);
  if (DAT_14007682c == DAT_140076828) {
    uVar3 = DAT_140076828 + 0x14;
    uVar5 = 0x66617664;
    _Dst = (void *)ExAllocatePool2(0x40);
    if (_Dst == (void *)0x0) {
      XdvUtilDbgPrint("VerifierExt!%s: unable to allocate additional resources for driver list\n",
                      "AutofailAddDriver",uVar5,param_4);
      goto LAB_140008458;
    }
    memset(_Dst,0,(ulonglong)uVar3 * 0x18);
    memcpy(_Dst,AutofailDrivers,(ulonglong)DAT_140076828 * 0x18);
    ExFreePoolWithTag(AutofailDrivers,0);
    AutofailDrivers = _Dst;
    DAT_140076828 = uVar3;
  }
  if (DAT_14007682c != 0) {
    do {
      _Src = (ulonglong *)((longlong)AutofailDrivers + uVar4 * 0x18);
      uVar3 = (int)uVar4 + 1;
      if (param_1 < *_Src) {
        memcpy((void *)((longlong)AutofailDrivers + (ulonglong)uVar3 * 0x18),_Src,
               (ulonglong)((DAT_14007682c - (int)uVar4) * 0x18));
        break;
      }
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < DAT_14007682c);
  }
  *(ulonglong *)((longlong)AutofailDrivers + uVar4 * 0x18) = param_1;
  *(ulonglong *)((longlong)AutofailDrivers + uVar4 * 0x18 + 8) = (param_2 & 0xffffffff) + param_1;
  *(undefined4 *)((longlong)AutofailDrivers + uVar4 * 0x18 + 0x10) = uVar1;
  *(undefined1 *)((longlong)AutofailDrivers + uVar4 * 0x18 + 0x14) = uVar6;
  DAT_14007682c = DAT_14007682c + 1;
LAB_140008458:
  ExReleaseSpinLockExclusive(&DAT_140076830,uVar2);
  return;
}



===== AutofailInjectStack @ 140008494 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AutofailInjectStack(void)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  int *piVar7;
  longlong lVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  int iVar14;
  char cVar15;
  undefined1 auStack_278 [48];
  ulonglong local_248 [44];
  int local_e8;
  int aiStack_e4 [47];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_278;
  cVar15 = '\0';
  memset(local_248,0,0x160);
  uVar3 = RtlCaptureStackBackTrace(2,0x2c,local_248);
  uVar11 = (uint)uVar3;
  puVar9 = (ulonglong *)0x0;
  iVar14 = 0;
  memset(&local_e8,0,0xb4);
  ExAcquireSpinLockShared(&DAT_140076830);
  uVar12 = (uint)uVar3;
  if (uVar12 == 0) {
LAB_1400085dc:
    uVar6 = ExReleaseSpinLockShared(&DAT_140076830);
    if (local_e8 != 0) {
      uVar11 = iVar14 * 4 + 4;
      uVar6 = (ulonglong)uVar11;
      uVar10 = 0x811c9dc5;
      if (0 < (int)uVar11) {
        lVar8 = 0;
        do {
          lVar13 = lVar8 + 0x160;
          lVar8 = lVar8 + 1;
          uVar10 = uVar10 * 0x1000193 ^ (ulonglong)*(byte *)((longlong)local_248 + lVar13);
        } while (lVar8 < (int)uVar11);
      }
      if (uVar10 != 0) {
        lVar13 = (ulonglong)((uint)uVar10 & 0x1f) * 0x808;
        puVar9 = (ulonglong *)(&AutofailStackData + lVar13);
        uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_14005af00 + lVar13);
        lVar8 = 0;
        do {
          if (*puVar9 == uVar10) break;
          if (*puVar9 == 0) {
            *puVar9 = uVar10;
            cVar15 = '\x01';
            break;
          }
          lVar8 = lVar8 + 1;
          puVar9 = puVar9 + 1;
        } while (lVar8 < 0x100);
        KeReleaseSpinLock(&DAT_14005af00 + lVar13,uVar1);
        uVar11 = DAT_140076800;
        if (cVar15 == '\0') {
          piVar7 = &DAT_14005a6f0;
        }
        else {
          LOCK();
          UNLOCK();
          uVar12 = DAT_140076800 & 0x8000007f;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xffffff80) + 1;
          }
          lVar8 = (longlong)(int)uVar12 * 0x180;
          DAT_140076800 = DAT_140076800 + 1;
          memcpy((void *)(lVar8 + 0x14006a820),local_248,0x160);
          bVar2 = KeGetCurrentIrql();
          *(uint *)(&DAT_14006a814 + lVar8) = (uint)bVar2;
          uVar5 = PsGetCurrentProcessId();
          *(undefined4 *)(&DAT_14006a80c + lVar8) = uVar5;
          uVar5 = PsGetCurrentThreadId();
          *(undefined4 *)(&DAT_14006a810 + lVar8) = uVar5;
          *(undefined4 *)(&DAT_14006a804 + lVar8) = DAT_14005a6ec;
          piVar7 = &DAT_14005a6e8;
          *(uint *)(&AutofailStackHistory + lVar8) = uVar11;
          *(ulonglong *)(&DAT_14006a818 + lVar8) = uVar10;
          *(uint *)(&DAT_14006a808 + lVar8) = (uint)uVar3;
        }
        LOCK();
        *piVar7 = *piVar7 + 1;
        UNLOCK();
        return CONCAT71((int7)((ulonglong)piVar7 >> 8),cVar15);
      }
    }
    return uVar6 & 0xffffffffffffff00;
  }
  lVar13 = 0;
  lVar8 = 0;
LAB_140008549:
  uVar6 = local_248[lVar13];
  if (puVar9 != (ulonglong *)0x0) {
    if ((*puVar9 <= uVar6) && (uVar6 <= puVar9[1])) {
LAB_14000855e:
      iVar14 = iVar14 + 1;
      aiStack_e4[lVar8] = (int)uVar6 - (int)*puVar9;
      lVar8 = lVar8 + 1;
      if (lVar8 == 0x2c) goto LAB_1400085dc;
      goto LAB_1400085ca;
    }
    uVar11 = uVar12;
    if (local_e8 != 0) {
      if (DAT_14005a6f6 != '\0') goto LAB_140008593;
      goto LAB_1400085dc;
    }
    if (2 < (int)uVar12) {
      uVar11 = 2;
    }
  }
LAB_140008593:
  uVar4 = 0;
  puVar9 = AutofailDrivers;
  if (DAT_14007682c != 0) {
    do {
      if (uVar6 < *puVar9) break;
      if (uVar6 <= puVar9[1]) {
        if (puVar9 == (ulonglong *)0x0) goto LAB_1400085c4;
        if ((*(char *)((longlong)puVar9 + 0x14) == '\0') && (local_e8 == 0)) {
          local_e8 = (int)puVar9[2];
        }
        goto LAB_14000855e;
      }
      puVar9 = puVar9 + 3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_14007682c);
  }
  puVar9 = (ulonglong *)0x0;
LAB_1400085c4:
  uVar11 = uVar11 - 1;
  if ((int)uVar11 < 1) goto LAB_1400085dc;
LAB_1400085ca:
  uVar12 = uVar12 - 1;
  lVar13 = lVar13 + 1;
  if ((longlong)(ulonglong)uVar3 <= lVar13) goto LAB_1400085dc;
  goto LAB_140008549;
}



===== AutofailRemoveDriver @ 1400087b4 =====

void AutofailRemoveDriver(longlong param_1)

{
  longlong *_Dst;
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar1 = ExAcquireSpinLockExclusive(&DAT_140076830);
  uVar3 = 0;
  if (DAT_14007682c != 0) {
    do {
      _Dst = (longlong *)(AutofailDrivers + uVar3 * 0x18);
      uVar2 = (int)uVar3 + 1;
      if (param_1 == *_Dst) {
        memcpy(_Dst,(void *)(AutofailDrivers + (ulonglong)uVar2 * 0x18),
               (ulonglong)((DAT_14007682c - (int)uVar3) * 0x18 - 0x18));
        DAT_14007682c = DAT_14007682c - 1;
        break;
      }
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < DAT_14007682c);
  }
  ExReleaseSpinLockExclusive(&DAT_140076830,uVar1);
  return;
}



===== XdvIsAutofailOn @ 140008860 =====

uint XdvIsAutofailOn(void)

{
  return CONCAT31((uint3)((uint)XdvRuleClasses >> 0x1a),(char)((uint)XdvRuleClasses >> 0x12)) &
         0xffffff01;
}



===== AutoFailDllInitialize_entry @ 140008880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AutoFailDllInitialize_entry
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  wchar_t *_Str1;
  undefined7 uVar4;
  
  uVar4 = (undefined7)((ulonglong)param_4 >> 8);
  uVar3 = (*DifGetDriverImageSize)(*param_1);
  if (uVar3 != 0) {
    _Str1 = (wchar_t *)(*XdvGetDriverName)(*param_1);
    if (_Str1 != (wchar_t *)0x0) {
      iVar1 = _wcsicmp(_Str1,L"wdf01000.sys");
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = _wcsicmp(_Str1,L"ndis.sys");
      }
      DAT_140032de4 = DAT_140032de4 + 1;
      AutofailAddDriver(param_1[2],uVar3 & 0xffffffff,param_3,CONCAT71(uVar4,iVar2 == 0));
    }
  }
  return;
}



===== AutoFailDllUnload_entry @ 140008920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AutoFailDllUnload_entry(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = (*DifGetDriverBaseAddress)(*param_1);
  AutofailRemoveDriver(lVar1);
  return;
}



===== AutoFailDriverEntry_entry @ 140008950 =====

void AutoFailDriverEntry_entry
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  undefined7 uVar5;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  uVar3 = 1;
  iVar1 = RtlCompareUnicodeString(*(longlong *)(param_1 + 0x10) + 0x38,&WdfLibName);
  iVar2 = 0;
  if (iVar1 != 0) {
    uVar3 = 1;
    iVar2 = RtlCompareUnicodeString(*(longlong *)(param_1 + 0x10) + 0x38,&NdisLibName);
  }
  DAT_140032de4 = DAT_140032de4 + 1;
  AutofailAddDriver(*(ulonglong *)(*(longlong *)(param_1 + 0x10) + 0x18),
                    (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20),CONCAT71(uVar4,uVar3)
                    ,CONCAT71(uVar5,iVar2 == 0));
  return;
}



===== AutoFailDriverUnload_entry @ 1400089d0 =====

void AutoFailDriverUnload_entry(longlong param_1)

{
  AutofailRemoveDriver(*(longlong *)(*(longlong *)(param_1 + 8) + 0x18));
  return;
}



===== AutofailCleanup @ 1400089f0 =====

void AutofailCleanup(void)

{
  longlong lVar1;
  
  if (AutofailDrivers != 0) {
    ExFreePoolWithTag(AutofailDrivers,0);
    AutofailDrivers = 0;
  }
  lVar1 = XdvRemovePluginObject(0x12);
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== AutofailControl @ 140008a50 =====

undefined4 AutofailControl(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *_Dst;
  longlong lVar7;
  longlong *plVar8;
  
  lVar7 = *(longlong *)(param_1 + 0xb8);
  puVar3 = *(uint **)(param_1 + 0x18);
  uVar5 = 0xc0000002;
  uVar1 = *(uint *)(lVar7 + 0x18);
  uVar2 = *(uint *)(lVar7 + 0x10);
  if (uVar1 == 0x10014000) {
    if (uVar2 < 8) {
LAB_140008b33:
      uVar5 = 0xc0000023;
    }
    else {
      lVar7 = *(longlong *)puVar3;
      if (lVar7 - 1U < 2) {
        LOCK();
        UNLOCK();
        AutofailConfig = (undefined4)lVar7;
        LOCK();
        DAT_14005a6e4 = 1;
        UNLOCK();
        goto LAB_140008ca0;
      }
      uVar5 = 0xc000000d;
      XdvUtilDbgPrint("VerifierExt!%s: Unrecognized stack fail type: %x\n","AutofailControl",lVar7,
                      (ulonglong)uVar2);
    }
LAB_140008cbc:
    uVar4 = 0;
  }
  else {
    if (uVar1 == 0x10014004) {
      LOCK();
      DAT_14005a6e4 = 0;
      UNLOCK();
    }
    else if (uVar1 == 0x10014008) {
      uVar4 = 0;
      if (DAT_14005a6e4 != 0) {
        uVar5 = 0xc000000d;
        goto LAB_140008cbe;
      }
      _Dst = &AutofailStackData;
      LOCK();
      DAT_14005a6e8 = 0;
      UNLOCK();
      lVar7 = 0x20;
      LOCK();
      DAT_14005a6ec = 0;
      UNLOCK();
      LOCK();
      DAT_14005a6f0 = 0;
      UNLOCK();
      do {
        memset(_Dst,0,0x100);
        _Dst = _Dst + 0x808;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      iVar6 = 0;
      if (0 < (int)DAT_14005a6c0) {
        plVar8 = &AutofailExemptedStacks;
        do {
          StoreStackExemption(*plVar8,'\0');
          iVar6 = iVar6 + 1;
          plVar8 = plVar8 + 1;
        } while (iVar6 < (int)DAT_14005a6c0);
      }
    }
    else {
      if (uVar1 == 0x1001400c) {
        uVar4 = 0;
        if (*(uint *)(lVar7 + 8) < 0x20) {
          uVar5 = 0xc000009a;
        }
        else {
          uVar5 = 0;
          *(longlong *)puVar3 = (longlong)DAT_14005a6e8;
          uVar4 = 0x20;
          *(longlong *)(puVar3 + 4) = (longlong)DAT_14005a6f0;
          *(longlong *)(puVar3 + 2) = (longlong)DAT_14005a6ec;
          *(longlong *)(puVar3 + 6) = (longlong)(int)DAT_140076800;
        }
        goto LAB_140008cbe;
      }
      if (uVar1 == 0x10014010) {
        LOCK();
        DAT_14005a6ec = DAT_14005a6ec + 1;
        UNLOCK();
      }
      else {
        if (uVar1 != 0x10014014) {
          if (uVar1 != 0x10014018) {
            XdvUtilDbgPrint("VerifierExt!%s: invalid IOCTL received: 0x%0x\n","AutofailControl",
                            (ulonglong)uVar1,(ulonglong)uVar2);
            goto LAB_140008cbc;
          }
          if ((7 < uVar2) && (7 < *(uint *)(lVar7 + 8))) {
            uVar1 = *puVar3;
            if ((uVar1 < DAT_140076800) &&
               ((DAT_140076800 < 0x80 || (DAT_140076800 - uVar1 < 0x81)))) {
              uVar4 = *(undefined8 *)(&DAT_14006a818 + (ulonglong)(uVar1 & 0x7f) * 0x180);
            }
            else {
              uVar4 = 0;
            }
            uVar5 = 0;
            *(undefined8 *)puVar3 = uVar4;
            uVar4 = 8;
            goto LAB_140008cbe;
          }
          goto LAB_140008b33;
        }
        uVar4 = 0;
        if (uVar2 < 8) {
          uVar5 = 0xc0000023;
          goto LAB_140008cbe;
        }
        lVar7 = *(longlong *)puVar3;
        if ((lVar7 != 0) && (DAT_14005a6c0 < 0x100)) {
          (&AutofailExemptedStacks)[DAT_14005a6c0] = lVar7;
          DAT_14005a6c0 = DAT_14005a6c0 + 1;
        }
        StoreStackExemption(lVar7,'\x01');
      }
    }
LAB_140008ca0:
    uVar4 = 0;
    uVar5 = 0;
  }
LAB_140008cbe:
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  *(undefined8 *)(param_1 + 0x38) = uVar4;
  IofCompleteRequest(param_1,0);
  return uVar5;
}



===== AutofailReadConfig @ 140008d00 =====

uint AutofailReadConfig(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  short *psVar5;
  undefined *puVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 local_res8;
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  undefined2 *puStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_58 = 0x8000000;
  local_48 = 0;
  puStack_40 = (undefined2 *)0x0;
  local_50 = ExAllocatePool2(0x40,0x800,0x61467541);
  if (local_50 == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    puVar6 = &XdvExtensionsRegistryPathStateSeparated;
    if (XdvStateSeparationEnabled == '\0') {
      puVar6 = &XdvExtensionsRegistryPath;
    }
    uVar2 = RtlAppendUnicodeStringToString(&local_58,puVar6);
    if ((-1 < (int)uVar2) &&
       (uVar2 = RtlAppendUnicodeStringToString(&local_58,&AutofailString), -1 < (int)uVar2)) {
      if (((local_58 & 1) == 0) && ((local_58 & 0x10000) == 0)) {
        if ((((ushort)local_58 <= local_58._2_2_) && (local_58._2_2_ != 0xffff)) &&
           ((local_50 != 0 || (((ushort)local_58 == 0 && (local_58._2_2_ == 0)))))) {
          lVar9 = 0x80;
          puVar7 = &AutofailSavedRegistryString;
          do {
            if (((ulonglong)((ushort)local_58 >> 1) - 0x80) + lVar9 == 0) break;
            *puVar7 = *(undefined2 *)(local_50 + -0x140059dc0 + (longlong)puVar7);
            puVar7 = puVar7 + 1;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
          puVar4 = puVar7 + -1;
          if (lVar9 != 0) {
            puVar4 = puVar7;
          }
          *puVar4 = 0;
          uVar2 = ~-(uint)(lVar9 != 0) & 0x80000005;
          if (lVar9 != 0) {
            psVar5 = &AutofailSavedRegistryString;
            lVar9 = 0x7fff;
            do {
              if (*psVar5 == 0) break;
              psVar5 = psVar5 + 1;
              lVar9 = lVar9 + -1;
            } while (lVar9 != 0);
            uVar2 = ~-(uint)(lVar9 != 0) & 0xc000000d;
            if (lVar9 != 0) {
              puStack_40 = &AutofailSavedRegistryString;
              sVar1 = (0x7fff - (short)lVar9) * 2;
              local_48._0_4_ = CONCAT22(sVar1 + 2,sVar1);
            }
            if (-1 < (int)uVar2) {
              local_28 = &local_48;
              uVar11 = 0;
              puVar10 = &local_38;
              uVar8 = 0x20019;
              local_38 = 0x30;
              local_20 = 0x240;
              local_18 = 0;
              uStack_10 = 0;
              local_res8 = 0;
              local_30 = 0;
              iVar3 = ZwCreateKey(&local_res8);
              if (iVar3 == 0) {
                GetRegistryInformation(local_res8,uVar8,puVar10,uVar11);
                ZwClose(local_res8);
              }
              uVar2 = 0;
            }
          }
          goto LAB_140008f1e;
        }
      }
      uVar2 = 0xc000000d;
      AutofailSavedRegistryString = 0;
    }
  }
LAB_140008f1e:
  if (local_50 != 0) {
    ExFreePoolWithTag(local_50,0x61467541);
  }
  return uVar2;
}



===== DifAutoFailPluginEntry @ 140008f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DifAutoFailPluginEntry(void)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 auStack_258 [32];
  char *local_238;
  undefined4 local_230;
  undefined8 local_228;
  undefined8 local_220;
  char *local_218;
  undefined4 local_210;
  undefined8 local_208;
  undefined8 local_200;
  char *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  char *local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined8 local_180;
  char *local_178;
  undefined4 local_170;
  undefined8 local_168;
  undefined8 local_160;
  char *local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined8 local_140;
  char *local_138;
  undefined4 local_130;
  undefined8 local_128;
  undefined8 local_120;
  char *local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined8 local_100;
  char *local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  char *local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  char *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_258;
  lVar2 = ExAllocatePool2(0x40,0x28,0x66617664);
  if (lVar2 == 0) {
    uVar4 = 0xc0000017;
  }
  else {
    *(undefined4 *)(lVar2 + 0x20) = 0x1001;
    *(code **)(lVar2 + 8) = AutofailReadConfig;
    *(code **)(lVar2 + 0x10) = AutofailControl;
    *(code **)(lVar2 + 0x18) = AutofailCleanup;
    XdvInsertPluginObject(0x12,lVar2);
    uVar3 = AutoFailInitialize();
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      local_230 = 0x19f;
      local_238 = "ExAllocatePoolWithTagPriority";
      local_218 = "ExAllocatePoolWithTag";
      local_1f8 = "ExAllocatePool";
      local_1d8 = "ExAllocatePool2";
      local_1b8 = "ExAllocatePool3";
      local_198 = "IoAllocateIrp";
      local_178 = "IoAllocateMdl";
      local_158 = "IoAllocateWorkItem";
      local_138 = "MmAllocateContiguousMemory";
      local_118 = "MmAllocateContiguousMemorySpecifyCache";
      local_f8 = "MmAllocatePagesForMdl";
      local_d8 = "MmMapIoSpace";
      local_b8 = "MmMapLockedPagesSpecifyCache";
      local_98 = "DriverEntry";
      local_88 = AutoFailDriverEntry_entry;
      local_78 = "DllInitialize";
      local_68 = AutoFailDllInitialize_entry;
      local_58 = "DriverUnload";
      local_228 = 0;
      local_220 = 0;
      local_210 = 0x19e;
      local_208 = 0;
      local_200 = 0;
      local_1f0 = 0x19d;
      local_1e8 = 0;
      local_1e0 = 0;
      local_1d0 = 0x1a3;
      local_1c8 = 0;
      local_1c0 = 0;
      local_1b0 = 0x1a2;
      local_1a8 = 0;
      local_1a0 = 0;
      local_190 = 0x16e;
      local_188 = 0;
      local_180 = 0;
      local_170 = 0x16d;
      local_168 = 0;
      local_160 = 0;
      local_150 = 0x16c;
      local_148 = 0;
      local_140 = 0;
      local_130 = 0xee;
      local_128 = 0;
      local_120 = 0;
      local_110 = 0xec;
      local_108 = 0;
      local_100 = 0;
      local_f0 = 0xe6;
      local_e8 = 0;
      local_e0 = 0;
      local_d0 = 0xdd;
      local_c8 = 0;
      local_c0 = 0;
      local_b0 = 0xdb;
      local_a8 = 0;
      local_a0 = 0;
      local_90 = 0x1000001c;
      local_80 = 0;
      local_70 = 0x80000000;
      local_60 = 0;
      local_50 = 0x1000001f;
      local_48 = AutoFailDriverUnload_entry;
      local_40 = 0;
      local_30 = 0x80000001;
      local_38 = "DllUnload";
      local_28 = AutoFailDllUnload_entry;
      local_20 = 0;
      uVar1 = DifRegisterPlugin(&local_238,0x11,0x12);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        return uVar4;
      }
    }
  }
  AutofailCleanup();
  return uVar4;
}



===== GetRegistryInformation @ 140009288 =====

void GetRegistryInformation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  void *pvVar4;
  ushort uVar5;
  longlong lVar6;
  byte bVar7;
  ushort *puVar8;
  ushort *puVar9;
  ulonglong uVar10;
  int iVar11;
  
  pvVar4 = ReadRegistryData(param_1);
  if (pvVar4 != (void *)0x0) {
    puVar8 = (ushort *)((ulonglong)*(uint *)((longlong)pvVar4 + 8) + (longlong)pvVar4);
    uVar5 = *puVar8;
    while (uVar5 != 0) {
      uVar10 = 0;
      bVar1 = false;
      param_4 = 0;
      puVar9 = puVar8;
      do {
        puVar9 = puVar9 + 1;
        iVar11 = (int)param_4;
        if (iVar11 == 0) {
          if (uVar5 != 0x30) {
            bVar1 = true;
          }
        }
        else if (iVar11 == 1) {
          if ((uVar5 - 0x58 & 0xffdf) != 0) {
            bVar1 = true;
          }
        }
        else {
          if ((ushort)(uVar5 - 0x30) < 10) {
            uVar3 = uVar5 - 0x30;
          }
          else if ((ushort)(uVar5 - 0x61) < 6) {
            uVar3 = uVar5 - 0x57;
          }
          else if ((ushort)(uVar5 - 0x41) < 6) {
            uVar3 = uVar5 - 0x37;
          }
          else {
            bVar1 = true;
            uVar3 = 0;
          }
          uVar10 = uVar10 << 4 | (ulonglong)uVar3;
        }
        uVar5 = *puVar9;
        param_4 = (ulonglong)(iVar11 + 1);
      } while (uVar5 != 0);
      if (bVar1) {
        XdvUtilDbgPrint("VerifierExt!%s: registry data format error: %s\n","StringToULong64",puVar8,
                        param_4);
        uVar10 = 0;
      }
      puVar8 = puVar8 + (int)((longlong)puVar9 + (2 - (longlong)puVar8) >> 1);
      if (uVar10 != 0) {
        if (DAT_14005a6c0 < 0x100) {
          (&AutofailExemptedStacks)[DAT_14005a6c0] = uVar10;
          DAT_14005a6c0 = DAT_14005a6c0 + 1;
        }
        StoreStackExemption(uVar10,'\0');
      }
      uVar5 = *puVar8;
    }
    ExFreePoolWithTag(pvVar4,0);
  }
  pvVar4 = ReadRegistryData(param_1);
  if (pvVar4 != (void *)0x0) {
    lVar6 = 0;
    if ((*(int *)((longlong)pvVar4 + 0xc) == 8) &&
       ((lVar6 = *(longlong *)((ulonglong)*(uint *)((longlong)pvVar4 + 8) + (longlong)pvVar4),
        lVar6 < 0 || (2 < lVar6)))) {
      XdvUtilDbgPrint("VerifierExt!%s: FailureMode value from registry is invalid {%d} \n",
                      "GetRegistryInformation",lVar6,param_4);
    }
    else {
      AutofailConfig = (undefined4)lVar6;
      if (lVar6 != 0) {
        LOCK();
        DAT_14005a6e4 = 1;
        UNLOCK();
      }
    }
    ExFreePoolWithTag(pvVar4,0);
  }
  pvVar4 = ReadRegistryData(param_1);
  if (pvVar4 != (void *)0x0) {
    bVar7 = (byte)*(undefined8 *)((ulonglong)*(uint *)((longlong)pvVar4 + 8) + (longlong)pvVar4);
    DAT_14005a6f4 = bVar7 & 1;
    DAT_14005a6f5 = bVar7 >> 1 & 1;
    DAT_14005a6f6 = bVar7 >> 2 & 1;
    ExFreePoolWithTag(pvVar4,0);
    if (DAT_14005a6f5 != 0) {
      uVar2 = ExAcquireSpinLockExclusive(&DAT_140076830);
      uVar10 = 0;
      if (DAT_14007682c != 0) {
        do {
          uVar3 = (int)uVar10 + 1;
          *(undefined1 *)(AutofailDrivers + 0x14 + uVar10 * 0x18) = 0;
          uVar10 = (ulonglong)uVar3;
        } while (uVar3 < DAT_14007682c);
      }
      ExReleaseSpinLockExclusive(&DAT_140076830,uVar2);
    }
  }
  return;
}



===== ReadRegistryData @ 140009534 =====

void * ReadRegistryData(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  uint local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  iVar2 = ZwQueryValueKey(param_1,&local_18,1,0,0,local_res18);
  uVar1 = local_res18[0];
  if (((iVar2 == -0x3fffffdd) || (iVar2 == -0x7ffffffb)) &&
     (_Dst = (void *)ExAllocatePool2(0x40,local_res18[0],0x66617664), _Dst != (void *)0x0)) {
    memset(_Dst,0,(ulonglong)uVar1);
    iVar2 = ZwQueryValueKey(param_1,&local_18,1,_Dst,uVar1,local_res18);
    if ((iVar2 == 0) && (local_res18[0] == uVar1)) {
      return _Dst;
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return (void *)0x0;
}



===== StoreStackExemption @ 140009630 =====

void StoreStackExemption(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  uVar5 = 0;
  lVar4 = (ulonglong)((uint)param_1 & 0x1f) * 0x808;
  plVar3 = (longlong *)(&AutofailStackData + lVar4);
  if (param_2 != '\0') {
    uVar5 = KeAcquireSpinLockRaiseToDpc();
  }
  lVar2 = 0;
  do {
    lVar1 = *plVar3;
    if (lVar1 == 0) {
      *plVar3 = param_1;
      break;
    }
    if (lVar1 == param_1) break;
    lVar2 = lVar2 + 1;
    plVar3 = plVar3 + 1;
  } while (lVar2 < 0x100);
  if (param_2 != '\0') {
    KeReleaseSpinLock(&DAT_14005af00 + lVar4,CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar5));
  }
  return;
}



===== DifLoggingPluginEntry @ 1400096f0 =====

void DifLoggingPluginEntry(void)

{
  char *local_48;
  undefined4 local_40;
  code *local_38;
  undefined8 local_30;
  char *local_28;
  undefined4 local_20;
  code *local_18;
  undefined8 local_10;
  
  local_48 = "DriverEntry";
  local_40 = 0x1000001c;
  local_30 = 0;
  local_38 = LogDriverEntry_entry;
  local_28 = "DriverUnload";
  local_20 = 0x1000001f;
  local_10 = 0;
  local_18 = LogDriverUnload_entry;
  DifRegisterPlugin(&local_48,2,0x16);
  return;
}



===== LogDriverEntry_entry @ 140009770 =====

void LogDriverEntry_entry(void)

{
  undefined8 in_R9;
  
  DAT_1400323c0 = DAT_1400323c0 + 1;
  if (DAT_1400323c0 == DAT_1400323c4) {
    DAT_1400323c4 = DAT_1400323c4 * 2;
    XdvUtilDbgPrint("Driver Verifier: Counter: %s: %d\n",PTR_s_LogDriverEntry_entry_1400323c8,
                    (ulonglong)DAT_1400323c0,in_R9);
  }
  return;
}



===== LogDriverUnload_entry @ 1400097c0 =====

void LogDriverUnload_entry(void)

{
  undefined8 in_R9;
  
  DAT_1400323b0 = DAT_1400323b0 + 1;
  if (DAT_1400323b0 == DAT_1400323b4) {
    DAT_1400323b4 = DAT_1400323b4 * 2;
    XdvUtilDbgPrint("Driver Verifier: Counter: %s: %d\n",PTR_s_LogDriverUnload_entry_1400323b8,
                    (ulonglong)DAT_1400323b0,in_R9);
  }
  return;
}



===== NdisPerformanceControl_OnTimer @ 140009808 =====

void NdisPerformanceControl_OnTimer(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  longlong local_res8;
  longlong local_res10;
  
  puVar5 = (undefined8 *)0x0;
  uVar7 = 0;
  uVar8 = 0;
  uVar2 = ExAcquireSpinLockExclusive();
  puVar6 = DAT_140059908;
  if ((undefined8 **)DAT_140059908 != &DAT_140059908) {
    do {
      iVar1 = *(int *)(puVar6 + 0x2b);
      uVar9 = (uint)puVar6[9];
      *(uint *)((longlong)puVar6 + (longlong)iVar1 * 4 + 0x58) = uVar9;
      iVar4 = 0;
      if (iVar1 != 0x3f) {
        iVar4 = iVar1 + 1;
      }
      LOCK();
      *(int *)(puVar6 + 0x2b) = iVar4;
      UNLOCK();
      puVar3 = puVar6;
      if (uVar9 <= uVar8) {
        puVar3 = puVar5;
      }
      uVar7 = uVar7 + uVar9;
      if (100000 < uVar7) break;
      puVar6 = (undefined8 *)*puVar6;
      if (uVar9 <= uVar8) {
        uVar9 = uVar8;
      }
      uVar8 = uVar9;
      puVar5 = puVar3;
    } while ((undefined8 **)puVar6 != &DAT_140059908);
    if ((puVar3 != (undefined8 *)0x0) && (100000 < uVar7)) {
      local_res8 = puVar3[6];
      StartCriticalSectionNdisGroup(&local_res8,(longlong)puVar3,'\x01');
      if (local_res8 != 0) {
        XdvPerformanceControlForNdisRules(local_res8,(longlong)puVar3);
        *(undefined4 *)(puVar3 + 7) = 1;
        XdvNdisTicksToPause = (DAT_140032df0 + 1) * 300;
        LOCK();
        UNLOCK();
        bVar10 = 0xfffd < DAT_140032df0;
        DAT_140032df0 = DAT_140032df0 + 1;
        if (bVar10) {
          DAT_140032df0 = 0xfffe;
        }
        LOCK();
        UNLOCK();
      }
      EndCriticalSectionNdisGroup(local_res8,(longlong)puVar3,'\x01');
    }
  }
  if ((0 < XdvNdisTicksToPause) && ((int)DAT_140032df0 < 0xfffe)) {
    iVar1 = XdvNdisTicksToPause + -1;
    XdvNdisTicksToPause = 0;
    if (0 < iVar1) {
      XdvNdisTicksToPause = iVar1;
    }
    LOCK();
    UNLOCK();
  }
  iVar1 = XdvNdisTicksToPause;
  for (puVar6 = DAT_140059908; (undefined8 **)puVar6 != &DAT_140059908;
      puVar6 = (undefined8 *)*puVar6) {
    if (puVar6 == (undefined8 *)0x0) {
      local_res10 = 0;
    }
    else {
      local_res10 = puVar6[6];
    }
    StartCriticalSectionNdisGroup(&local_res10,(longlong)puVar6,'\x01');
    if (local_res10 != 0) {
      puVar6[9] = 0;
    }
    EndCriticalSectionNdisGroup(local_res10,(longlong)puVar6,'\x01');
    if (iVar1 < 1) {
      *(undefined4 *)(puVar6 + 7) = 0;
    }
  }
  ExReleaseSpinLockExclusive(&DAT_140059904,uVar2);
  return;
}



===== Ndis_OnTimerExpire @ 1400099c8 =====

void Ndis_OnTimerExpire(void)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  int *piVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  undefined8 *puVar11;
  int iVar12;
  int *local_res8;
  
  if (NdisTimedOidComplete_Counter < 2) {
    NdisTimedOidComplete_Counter = 1;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = *(longlong **)(local_res8 + 0x58);
        if (plVar4 != (longlong *)0x0) {
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          if (XDV_NDISOIDCOMPLETE_TIMELIMIT < (int)DAT_1400598f0 - (int)plVar4[0xe]) {
            SLIC_StatefulAbort("Timeout on completing an NDIS OID request.",0x92003,local_res8,
                               plVar4,(longlong *)(local_res8 + 0x58),0x78);
          }
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisTimedOidComplete_Counter = NdisTimedOidComplete_Counter - 1;
  }
  if (NdisTimedDataSend_Counter < 2) {
    NdisTimedDataSend_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = (longlong *)(local_res8 + 0x16);
        lVar2 = *(longlong *)(local_res8 + 0x1a);
        if (lVar2 != 0) {
          local_res8[0x1f] = *(int *)(lVar2 + 0x10);
          local_res8[0x1e] = *(int *)(lVar2 + 0x14);
          *(undefined8 *)(local_res8 + 0x1c) = *(undefined8 *)(lVar2 + 0x18);
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          iVar12 = (int)DAT_1400598f0 - local_res8[0x1f];
          local_res8[0x18] = iVar12;
          if (XDV_NDISDATASEND_TIMELIMIT <= iVar12) {
            if ((XdvVerifierOptions >> 0x10 & 1) == 0) {
              pcVar9 = "0: Timeout on sending a NET_BUFFER_LIST by MiniportSendNetBufferLists.";
            }
            else {
              uVar10 = XdvVerifierOptions >> 1 & 3;
              iVar8 = 1;
              if (uVar10 < 3) {
                iVar8 = uVar10 + 1;
              }
              if (iVar8 * XDV_NDISDATASEND_TIMELIMIT <= iVar12) {
                local_res8[0xe] = iVar12;
                local_res8[0xf] = (int)*plVar4;
                *(undefined8 *)(local_res8 + 0xc) = *(undefined8 *)(local_res8 + 0x1c);
                *(undefined1 *)(local_res8 + 0x10) = 0;
                SLIC_StatefulAbort("2: Timeout on sending a NET_BUFFER_LIST by MiniportSendNetBufferLists."
                                   ,0x9200d,local_res8,plVar4,(longlong *)0x0,0x28);
              }
              if (piVar5[0x17] != 0) goto LAB_140009c38;
              lVar2 = *plVar4;
              piVar5[0x17] = 1;
              piVar5[0xe] = piVar5[0x18];
              pcVar9 = "1: Timeout on sending a NET_BUFFER_LIST by MiniportSendNetBufferLists.";
              *(undefined8 *)(piVar5 + 0xc) = *(undefined8 *)(piVar5 + 0x1c);
              piVar5[0xf] = (int)lVar2;
              *(undefined1 *)(piVar5 + 0x10) = 1;
            }
            SLIC_StatefulAbort(pcVar9,0x9200d,piVar5,plVar4,(longlong *)0x0,0x28);
          }
        }
      }
LAB_140009c38:
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisTimedDataSend_Counter = NdisTimedDataSend_Counter - 1;
  }
  if (NdisTimedDataHang_Counter < 2) {
    NdisTimedDataHang_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = (longlong *)(local_res8 + 0x20);
        lVar2 = *(longlong *)(local_res8 + 0x24);
        if (lVar2 != 0) {
          local_res8[0x2a] = *(int *)(lVar2 + 0x10);
          local_res8[0x28] = *(int *)(lVar2 + 0x14);
          *(undefined8 *)(local_res8 + 0x26) = *(undefined8 *)(lVar2 + 0x18);
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          iVar12 = (int)DAT_1400598f0 - local_res8[0x29];
          local_res8[0x22] = iVar12;
          if (XDV_NDISDATAHANG_TIMELIMIT <= iVar12) {
            if ((XdvVerifierOptions >> 0x10 & 1) == 0) {
              pcVar9 = "0: The miniport driver hasn\'t processed any NBL in the past 22 seconds.";
            }
            else {
              uVar10 = XdvVerifierOptions >> 1 & 3;
              iVar8 = 1;
              if (uVar10 < 3) {
                iVar8 = uVar10 + 1;
              }
              if (iVar12 < iVar8 * XDV_NDISDATAHANG_TIMELIMIT) {
                if (local_res8[0x21] != 0) goto LAB_140009dc9;
                uVar7 = *(undefined8 *)(local_res8 + 0x26);
                local_res8[0x21] = 1;
                local_res8[0xf] = (int)*plVar4;
                pcVar9 = "1: The miniport driver hasn\'t processed any NBL in the past 22 seconds.";
                *(undefined1 *)(local_res8 + 0x10) = 1;
              }
              else {
                uVar7 = *(undefined8 *)(local_res8 + 0x26);
                local_res8[0xf] = (int)*plVar4;
                pcVar9 = "2: The miniport driver hasn\'t processed any NBL in the past 22+ seconds."
                ;
                *(undefined1 *)(local_res8 + 0x10) = 0;
              }
              local_res8[0xe] = iVar12;
              *(undefined8 *)(local_res8 + 0xc) = uVar7;
            }
            SLIC_StatefulAbort(pcVar9,0x9200f,local_res8,plVar4,(longlong *)0x0,0x30);
          }
        }
      }
LAB_140009dc9:
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisTimedDataHang_Counter = NdisTimedDataHang_Counter - 1;
  }
  if (NdisFilterTimedPauseComplete_Counter < 2) {
    NdisFilterTimedPauseComplete_Counter = 2;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if ((local_res8 != (int *)0x0) &&
         (plVar4 = (longlong *)(local_res8 + 0x3f), (int)*plVar4 != 0)) {
        LOCK();
        if (DAT_1400598f0 == 0) {
          DAT_1400598f0 = 0;
        }
        UNLOCK();
        if (XDV_NDISFILTERPAUSECOMPLETE_TIMELIMIT <= (int)DAT_1400598f0 - (int)*plVar4) {
          SLIC_StatefulAbort("The filter driver failed to complete FilterPause within 10 seconds.",
                             0x92010,local_res8,plVar4,(longlong *)0x0,4);
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisFilterTimedPauseComplete_Counter = NdisFilterTimedPauseComplete_Counter - 1;
  }
  if (NdisFilterTimedDataSend_Counter < 2) {
    NdisFilterTimedDataSend_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        lVar2 = *(longlong *)(local_res8 + 0x42);
        piVar1 = local_res8 + 0x4b;
        if (lVar2 != 0) {
          *piVar1 = *(int *)(lVar2 + 0x10);
          local_res8[0x49] = *(int *)(lVar2 + 0x14);
          *(undefined8 *)(local_res8 + 0x46) = *(undefined8 *)(lVar2 + 0x18);
        }
        lVar3 = *(longlong *)(local_res8 + 0x40);
        if (lVar3 != 0) {
          local_res8[0x4a] = *(int *)(lVar3 + 0x10);
          local_res8[0x48] = *(int *)(lVar3 + 0x14);
          *(undefined8 *)(local_res8 + 0x44) = *(undefined8 *)(lVar3 + 0x18);
        }
        if (lVar2 != 0) {
          if (lVar3 == 0) {
            LOCK();
            if (DAT_1400598f0 == 0) {
              DAT_1400598f0 = 0;
            }
            UNLOCK();
            if ((int)DAT_1400598f0 - *piVar1 < XDV_NDISFILTERDATASEND_TIMELIMIT) goto LAB_14000a002;
            pcVar9 = "Timeout on sending a NET_BUFFER_LIST by NdisFilterSendNetBufferLists.";
          }
          else {
            if (local_res8[0x4a] - *piVar1 <= XDV_NDISFILTERDATASEND_TIMELIMIT) {
              LOCK();
              if (DAT_1400598f0 == 0) {
                DAT_1400598f0 = 0;
              }
              UNLOCK();
              if ((int)DAT_1400598f0 - *piVar1 <= XDV_NDISFILTERDATASEND_TIMELIMIT * 2)
              goto LAB_14000a002;
            }
            pcVar9 = 
            "Timeout on sending a NET_BUFFER_LIST by NdisFilterSendNetBufferLists (check the lower edge)."
            ;
          }
          SLIC_StatefulAbort(pcVar9,0x92011,local_res8,(longlong *)(local_res8 + 0x40),
                             (longlong *)0x0,0x30);
        }
      }
LAB_14000a002:
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisFilterTimedDataSend_Counter = NdisFilterTimedDataSend_Counter - 1;
  }
  if (NdisFilterTimedDataReceive_Counter < 2) {
    NdisFilterTimedDataReceive_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        lVar2 = *(longlong *)(local_res8 + 0x4e);
        piVar1 = local_res8 + 0x57;
        if (lVar2 != 0) {
          *piVar1 = *(int *)(lVar2 + 0x10);
          local_res8[0x55] = *(int *)(lVar2 + 0x14);
          *(undefined8 *)(local_res8 + 0x52) = *(undefined8 *)(lVar2 + 0x18);
        }
        lVar3 = *(longlong *)(local_res8 + 0x4c);
        if (lVar3 != 0) {
          local_res8[0x56] = *(int *)(lVar3 + 0x10);
          local_res8[0x54] = *(int *)(lVar3 + 0x14);
          *(undefined8 *)(local_res8 + 0x50) = *(undefined8 *)(lVar3 + 0x18);
        }
        if (lVar2 != 0) {
          if (lVar3 == 0) {
            LOCK();
            if (DAT_1400598f0 == 0) {
              DAT_1400598f0 = 0;
            }
            UNLOCK();
            if ((int)DAT_1400598f0 - *piVar1 < XDV_NDISFILTERDATARECEIVE_TIMELIMIT)
            goto LAB_14000a165;
            pcVar9 = "Timeout on receiving a NET_BUFFER_LIST by FilterReceiveNetBufferLists.";
          }
          else {
            if (local_res8[0x56] - *piVar1 <= XDV_NDISFILTERDATARECEIVE_TIMELIMIT) {
              LOCK();
              if (DAT_1400598f0 == 0) {
                DAT_1400598f0 = 0;
              }
              UNLOCK();
              if ((int)DAT_1400598f0 - *piVar1 <= XDV_NDISFILTERDATARECEIVE_TIMELIMIT * 2)
              goto LAB_14000a165;
            }
            pcVar9 = 
            "Timeout on receiving a NET_BUFFER_LIST by FilterReceiveNetBufferLists (in the upper driver)."
            ;
          }
          SLIC_StatefulAbort(pcVar9,0x92012,local_res8,(longlong *)(local_res8 + 0x4c),
                             (longlong *)0x0,0x30);
        }
      }
LAB_14000a165:
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    NdisFilterTimedDataReceive_Counter = NdisFilterTimedDataReceive_Counter - 1;
  }
  if (WlanTimedAssociation_Counter < 2) {
    WlanTimedAssociation_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = *(longlong **)(local_res8 + 0x5c);
        if (plVar4 != (longlong *)0x0) {
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          if (XDV_WLAN_ASSOCIATION_TIMELIMIT <= (int)DAT_1400598f0 - (int)plVar4[0xe]) {
            SLIC_StatefulAbort("Timeout on NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION after NDIS_STATUS_DOT11_ASSOCIATION_START."
                               ,0x94007,local_res8,plVar4,(longlong *)(local_res8 + 0x5c),0x78);
          }
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    WlanTimedAssociation_Counter = WlanTimedAssociation_Counter - 1;
  }
  if (WlanTimedConnectionRoaming_Counter < 2) {
    WlanTimedConnectionRoaming_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = *(longlong **)(local_res8 + 0x5e);
        if (plVar4 != (longlong *)0x0) {
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          if (XDV_WLAN_CONNECTION_ROAMING_TIMELIMIT <= (int)DAT_1400598f0 - (int)plVar4[0xe]) {
            SLIC_StatefulAbort("Timeout on NDIS_STATUS_DOT11_CONNECTION_COMPLETION/NDIS_STATUS_DOT11_ROAMING_COMPLETION after NDIS_STATUS_DOT11_CONNECTION_START/NDIS_STATUS_DOT11_ROAMING_START."
                               ,0x94008,local_res8,plVar4,(longlong *)(local_res8 + 0x5e),0x78);
          }
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    WlanTimedConnectionRoaming_Counter = WlanTimedConnectionRoaming_Counter - 1;
  }
  if (WlanTimedConnectRequest_Counter < 2) {
    WlanTimedConnectRequest_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if ((local_res8 != (int *)0x0) &&
         (plVar4 = (longlong *)(local_res8 + 0x3a), (int)*plVar4 != 0)) {
        LOCK();
        if (DAT_1400598f0 == 0) {
          DAT_1400598f0 = 0;
        }
        UNLOCK();
        if (XDV_WLAN_CONNECT_TIMELIMIT <= (int)DAT_1400598f0 - (int)*plVar4) {
          SLIC_StatefulAbort("Timeout on NDIS_STATUS_DOT11_CONNECTION_START after OID_DOT11_CONNECT_REQUEST."
                             ,0x94009,local_res8,plVar4,(longlong *)0x0,8);
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    WlanTimedConnectRequest_Counter = WlanTimedConnectRequest_Counter - 1;
  }
  if (WlanTimedLinkQuality_Counter < 2) {
    WlanTimedLinkQuality_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (((local_res8 != (int *)0x0) && (local_res8[0x3e] != 0)) &&
         ((char)*(longlong *)(local_res8 + 0x3c) != '\x01')) {
        LOCK();
        if (DAT_1400598f0 == 0) {
          DAT_1400598f0 = 0;
        }
        UNLOCK();
        if (XDV_WLAN_LINKQUALITY_TIMELIMIT <= (int)DAT_1400598f0 - local_res8[0x3e]) {
          SLIC_StatefulAbort("Timeout on NDIS_STATUS_DOT11_LINK_QUALITY after NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION."
                             ,0x9400b,local_res8,(longlong *)(local_res8 + 0x3c),(longlong *)0x0,0xc
                            );
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    WlanTimedLinkQuality_Counter = WlanTimedLinkQuality_Counter - 1;
  }
  if (WlanTimedScan_Counter < 2) {
    WlanTimedScan_Counter = 5;
    uVar6 = ExAcquireSpinLockShared(&DAT_140059904);
    for (puVar11 = DAT_140059908; (undefined8 **)puVar11 != &DAT_140059908;
        puVar11 = (undefined8 *)*puVar11) {
      local_res8 = (int *)0x0;
      if (puVar11 != (undefined8 *)0x0) {
        local_res8 = (int *)puVar11[6];
      }
      StartCriticalSectionNdisGroup((longlong *)&local_res8,(longlong)puVar11,'\0');
      piVar5 = local_res8;
      if (local_res8 != (int *)0x0) {
        plVar4 = *(longlong **)(local_res8 + 0x60);
        if ((plVar4 != (longlong *)0x0) && (*(char *)((longlong)plVar4 + 0x74) == '\x03')) {
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          if (XDV_WLANSCAN_TIMELIMIT < (int)DAT_1400598f0 - (int)plVar4[0xe]) {
            SLIC_StatefulAbort("Timeout on NDIS_STATUS_DOT11_SCAN_CONFIRM after OID_DOT11_SCAN_REQUEST."
                               ,0x9400c,local_res8,plVar4,(longlong *)(local_res8 + 0x60),0x78);
          }
        }
      }
      EndCriticalSectionNdisGroup((longlong)piVar5,(longlong)puVar11,'\0');
    }
    ExReleaseSpinLockShared(&DAT_140059904,uVar6);
  }
  else {
    WlanTimedScan_Counter = WlanTimedScan_Counter - 1;
  }
  return;
}



===== XdvDoTimedDebug @ 14000a62c =====

ulonglong XdvDoTimedDebug(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  int *piVar7;
  int iVar8;
  undefined8 uVar9;
  char local_res8 [8];
  
  iVar8 = 7;
  uVar6 = 0x40003;
  uVar4 = 4;
  iVar5 = 0xd;
  uVar9 = 10;
  if (param_1 < 0x40004) {
    if (param_1 == 0x40003) {
      uVar4 = 0x1c;
    }
    else {
      uVar6 = 0x20010;
      if (param_1 < 0x20011) {
        if (param_1 == 0x20010) {
          uVar4 = 0xe;
        }
        else {
          uVar6 = 0x20009;
          if (param_1 < 0x2000a) {
            if (param_1 == 0x20009) {
              uVar4 = 7;
            }
            else if (param_1 == 0x20002) {
              uVar4 = 0;
              uVar6 = 0;
            }
            else if (param_1 == 0x20003) {
              uVar4 = 1;
              uVar6 = 0;
            }
            else if (param_1 == 0x20004) {
              uVar4 = 2;
              uVar6 = 0;
            }
            else if (param_1 == 0x20005) {
              uVar4 = 3;
              uVar6 = 0;
            }
            else {
              uVar6 = (ulonglong)(param_1 - 0x20006);
              if (param_1 - 0x20006 != 0) {
                uVar3 = param_1 - 0x20007;
                uVar6 = (ulonglong)uVar3;
                if (uVar3 == 0) {
                  uVar4 = 5;
                }
                else {
                  if (uVar3 != 1) goto LAB_14000a8d8;
                  uVar4 = 6;
                }
              }
            }
          }
          else if (param_1 == 0x2000a) {
            uVar4 = 8;
            uVar6 = 0;
          }
          else if (param_1 == 0x2000b) {
            uVar4 = 9;
            uVar6 = 0;
          }
          else if (param_1 == 0x2000c) {
            uVar4 = 10;
            uVar6 = 0;
          }
          else if (param_1 == 0x2000d) {
            uVar4 = 0xb;
            uVar6 = 0;
          }
          else {
            uVar3 = param_1 - 0x2000e;
            uVar6 = (ulonglong)uVar3;
            if (uVar3 == 0) {
              uVar4 = 0xc;
            }
            else {
              if (uVar3 != 1) goto LAB_14000a8d8;
              uVar4 = 0xd;
            }
          }
        }
      }
      else {
        uVar6 = 0x2001c;
        if (param_1 < 0x2001d) {
          if (param_1 == 0x2001c) {
            uVar4 = 0x15;
          }
          else if (param_1 == 0x20011) {
            uVar4 = 0xf;
            uVar6 = 0;
          }
          else if (param_1 == 0x20015) {
            uVar4 = 0x10;
            uVar6 = 0;
          }
          else if (param_1 == 0x20016) {
            uVar4 = 0x11;
            uVar6 = 0;
          }
          else if (param_1 == 0x20019) {
            uVar4 = 0x12;
            uVar6 = 0;
          }
          else {
            uVar3 = param_1 - 0x2001a;
            uVar6 = (ulonglong)uVar3;
            if (uVar3 == 0) {
              uVar4 = 0x13;
            }
            else {
              if (uVar3 != 1) goto LAB_14000a8d8;
              uVar4 = 0x14;
            }
          }
        }
        else if (param_1 == 0x2001e) {
          uVar4 = 0x16;
          uVar6 = 0;
        }
        else if (param_1 == 0x2001f) {
          uVar4 = 0x17;
          uVar6 = 0;
        }
        else if (param_1 == 0x20022) {
          uVar4 = 0x18;
          uVar6 = 0;
        }
        else if (param_1 == 0x20023) {
          uVar4 = 0x19;
          uVar6 = 0;
        }
        else {
          uVar3 = param_1 - 0x20024;
          uVar6 = (ulonglong)uVar3;
          if (uVar3 == 0) {
            uVar4 = 0x1a;
          }
          else {
            if (uVar3 != 1) {
LAB_14000a8d8:
              if (param_1 == 0x81001) {
                uVar4 = 0;
                uVar6 = 0;
              }
              else if (param_1 == 0x81002) {
                uVar4 = 1;
                uVar6 = 0;
              }
              else if (param_1 == 0x81003) {
                uVar4 = 2;
                uVar6 = 0;
              }
              else if (param_1 == 0x81004) {
                uVar4 = 3;
                uVar6 = 0;
              }
              else {
                uVar3 = param_1 - 0x81005;
                uVar6 = (ulonglong)uVar3;
                if (uVar3 != 0) {
                  if (uVar3 != 1) {
                    uVar6 = 0x71007;
                    if (0x71007 < param_1) goto LAB_14000ab38;
                    if (param_1 == 0x71007) {
                      uVar4 = 0x49;
                    }
                    else if (param_1 == 0x71001) {
                      uVar4 = 0x44;
                      uVar6 = 0;
                    }
                    else if (param_1 == 0x71003) {
                      uVar4 = 0x45;
                      uVar6 = 0;
                    }
                    else if (param_1 == 0x71004) {
                      uVar4 = 0x46;
                      uVar6 = 0;
                    }
                    else {
                      uVar4 = param_1 - 0x71005;
                      uVar6 = (ulonglong)uVar4;
                      if (uVar4 == 0) {
                        uVar4 = 0x47;
                      }
                      else {
                        if (uVar4 != 1) goto LAB_14000aede;
                        uVar4 = 0x48;
                      }
                    }
                    goto LAB_14000aba9;
                  }
                  uVar4 = 5;
                }
              }
              goto LAB_14000ab8a;
            }
            uVar4 = 0x1b;
          }
        }
      }
    }
LAB_14000aba9:
    if (uVar4 < 0x4e) {
      if (uVar4 < 0x1a) {
        if (uVar4 != 0x19) {
          if (uVar4 < 0xd) {
            if (uVar4 != 0xc) {
              if (uVar4 < 7) {
                if (uVar4 != 6) {
                  uVar3 = uVar4;
                  goto LAB_14000abca;
                }
              }
              else if (((uVar4 != 7) && (uVar4 != 8)) && (uVar4 != 9)) {
                iVar8 = uVar4 - 10;
                goto joined_r0x00014000ac08;
              }
            }
          }
          else if (uVar4 < 0x14) {
            if (uVar4 != 0x13) {
              uVar3 = uVar4 - 0xd;
LAB_14000abca:
              if (uVar3 != 0) {
                iVar8 = uVar3 - 1;
                goto LAB_14000abcf;
              }
            }
          }
          else {
            iVar8 = uVar4 - 0x14;
LAB_14000abcf:
            if (((iVar8 != 0) && (iVar8 != 1)) && (iVar8 != 2)) {
              iVar8 = iVar8 + -3;
joined_r0x00014000ac08:
              if (iVar8 != 0) goto LAB_14000abe3;
            }
          }
        }
LAB_14000abe9:
        iVar8 = 0;
LAB_14000ac7f:
        iVar5 = iVar8;
      }
      else {
        if (uVar4 < 0x27) {
          if (uVar4 != 0x26) {
            if (uVar4 < 0x21) {
              if (((uVar4 == 0x20) || (uVar4 == 0x1a)) || (uVar4 == 0x1b)) goto LAB_14000abe9;
              if (((uVar4 == 0x1c) || (uVar4 == 0x1d)) || (iVar8 = uVar4 - 0x1e, iVar8 == 0)) {
                iVar8 = 1;
                goto LAB_14000ac7f;
              }
LAB_14000abe3:
              if (iVar8 == 1) goto LAB_14000abe9;
              goto LAB_14000ade1;
            }
            if (((uVar4 == 0x21) || (uVar4 == 0x22)) || (uVar4 == 0x23)) goto LAB_14000ac7f;
            if ((uVar4 != 0x24) && (uVar4 != 0x25)) goto LAB_14000ade1;
          }
LAB_14000ac7c:
          iVar8 = 8;
          goto LAB_14000ac7f;
        }
        if (uVar4 < 0x2e) {
          if (uVar4 == 0x2d) {
            iVar8 = 6;
          }
          else {
            if (((uVar4 == 0x27) || (uVar4 == 0x28)) || (uVar4 == 0x29)) goto LAB_14000ac7c;
            if (((uVar4 != 0x2a) && (uVar4 != 0x2b)) && (uVar4 != 0x2c)) goto LAB_14000ade1;
          }
          goto LAB_14000ac7f;
        }
        if (((uVar4 == 0x2e) || (uVar4 == 0x2f)) ||
           ((uVar4 == 0x30 || ((uVar4 == 0x31 || (uVar4 == 0x32)))))) goto LAB_14000ac7c;
LAB_14000ade1:
        if ((int)(uVar4 - 0x33) < 9) {
          if (uVar4 - 0x33 == 8) {
LAB_14000ae30:
            uVar9 = 9;
          }
          else if ((uVar4 != 0x33) && (uVar4 != 0x34)) {
            if (uVar4 == 0x35) goto LAB_14000ae30;
            if (uVar4 != 0x36) {
              if (uVar4 == 0x37) goto LAB_14000ae30;
              if (((uVar4 != 0x38) && (uVar4 != 0x39)) && (uVar4 != 0x3a)) goto LAB_14000ae62;
            }
          }
LAB_14000aeba:
          iVar5 = (int)uVar9;
        }
        else {
          if (((uVar4 == 0x3c) || (uVar4 == 0x3d)) || (uVar4 == 0x3e)) goto LAB_14000aeba;
          if (((uVar4 == 0x3f) || (uVar4 == 0x40)) ||
             ((uVar4 == 0x41 || ((uVar4 == 0x42 || (uVar4 == 0x43)))))) {
            uVar9 = 0xb;
            goto LAB_14000aeba;
          }
LAB_14000ae62:
          if ((int)(uVar4 - 0x44) < 6) {
            if (((uVar4 - 0x44 == 5) || (uVar4 == 0x44)) || (uVar4 == 0x45)) goto LAB_14000aeaf;
            if (((uVar4 != 0x46) && (uVar4 != 0x47)) && (uVar4 != 0x48)) goto LAB_14000aeec;
          }
          else if (((uVar4 == 0x4a) || (uVar4 == 0x4b)) || (uVar4 == 0x4c)) {
LAB_14000aeaf:
            iVar5 = 0xc;
          }
          else {
            if (uVar4 != 0x4d) goto LAB_14000aeec;
            iVar5 = 0xe;
          }
        }
      }
      if (((((iVar5 == 2) || (iVar5 == 5)) || (iVar5 == 8)) || ((iVar5 == 0xb || (iVar5 == 0xe))))
         && ((byte)(&XdvTimedRuleExtension)[(int)uVar4] < 3)) {
        piVar7 = (int *)XdvGetRuleTimedLimit(param_1);
        uVar6 = 0;
        if (piVar7 != (int *)0x0) {
          if ((&XdvTimedRuleExtension)[(int)uVar4] == '\0') {
            (&XdvTimedRuleExtension)[(int)uVar4] = 1;
          }
          iVar5 = XdvGetRuleTimedUnit(param_1);
          XdvUtilDbgPrint("\n*** Driver Verifier rule 0x%X is violated on the time limit of %d milliseconds ***\n\n*** Choose to either :\n"
                          ,(ulonglong)param_1,(ulonglong)(uint)(iVar5 * *piVar7),uVar9);
          do {
            uVar6 = DbgPrompt("    (B)reak to investigate, \n    (C)ontinue to bugcheck, \n    (E)xtend the timelimit and continue? "
                              ,local_res8,2);
            if (local_res8[0] == 'B') {
LAB_14000aec2:
              XdvUtilDbgPrint("\nMore debugging info: \n    Error String: \'%s\' \n    Context Object (IRP or Miniport): 0x%p \n    Tracked Object (OID, Port number, IRP, etc.): 0x%p \n\n"
                              ,param_2,param_3,param_4);
              pcVar2 = (code *)swi(3);
              uVar6 = (*pcVar2)();
              return uVar6;
            }
            if (local_res8[0] == 'C') goto LAB_14000aeec;
            if (local_res8[0] == 'E') break;
            if (local_res8[0] == 'b') goto LAB_14000aec2;
            if (local_res8[0] == 'c') goto LAB_14000aeec;
          } while (local_res8[0] != 'e');
          iVar5 = *piVar7;
          bVar1 = (&XdvTimedRuleExtension)[(int)uVar4];
          iVar5 = (iVar5 / (int)(uint)bVar1 - iVar5 % (int)(uint)bVar1) + iVar5;
          *piVar7 = iVar5;
          (&XdvTimedRuleExtension)[(int)uVar4] = bVar1 + 1;
          return CONCAT71((uint7)(uint3)((uint)iVar5 >> 8),1);
        }
      }
      goto LAB_14000aeec;
    }
  }
  else {
    uVar6 = 0x92011;
    if (param_1 < 0x92012) {
      if (param_1 == 0x92011) {
        uVar4 = 0x28;
      }
      else {
        uVar6 = 0x91002;
        if (param_1 < 0x91003) {
          if (param_1 == 0x91002) {
            uVar4 = 0x22;
          }
          else if (param_1 == 0x40007) {
            uVar4 = 0x1d;
            uVar6 = 0;
          }
          else if (param_1 == 0x4000a) {
            uVar4 = 0x1e;
            uVar6 = 0;
          }
          else if (param_1 == 0x4100b) {
            uVar4 = 0x1f;
            uVar6 = 0;
          }
          else {
            uVar3 = param_1 - 0x43006;
            uVar6 = (ulonglong)uVar3;
            if (uVar3 == 0) {
              uVar4 = 0x20;
            }
            else {
              if (uVar3 != 0x4dffb) {
                uVar6 = 0x82001;
                if (param_1 < 0x82002) {
                  if (param_1 == 0x82001) {
                    uVar4 = 0xc;
                  }
                  else {
                    uVar6 = 0x81007;
                    if (param_1 < 0x81008) {
                      if (param_1 != 0x81007) goto LAB_14000a8d8;
                      uVar4 = 6;
                    }
                    else if (param_1 == 0x81008) {
                      uVar4 = 7;
                      uVar6 = 0;
                    }
                    else if (param_1 == 0x81009) {
                      uVar4 = 8;
                      uVar6 = 0;
                    }
                    else if (param_1 == 0x8100a) {
                      uVar4 = 9;
                      uVar6 = 0;
                    }
                    else {
                      uVar4 = param_1 - 0x8100b;
                      uVar6 = (ulonglong)uVar4;
                      if (uVar4 == 0) {
                        uVar4 = 10;
                      }
                      else {
                        if (uVar4 != 1) goto LAB_14000ab38;
                        uVar4 = 0xb;
                      }
                    }
                  }
                  goto LAB_14000ab8a;
                }
                goto LAB_14000ab20;
              }
              uVar4 = 0x21;
            }
          }
        }
        else if (param_1 == 0x9100e) {
          uVar4 = 0x23;
          uVar6 = 0;
        }
        else if (param_1 == 0x92003) {
          uVar4 = 0x24;
          uVar6 = 0;
        }
        else if (param_1 == 0x9200d) {
          uVar4 = 0x25;
          uVar6 = 0;
        }
        else {
          uVar4 = param_1 - 0x9200f;
          uVar6 = (ulonglong)uVar4;
          if (uVar4 == 0) {
            uVar4 = 0x26;
          }
          else {
            if (uVar4 != 1) goto LAB_14000ab20;
            uVar4 = 0x27;
          }
        }
      }
      goto LAB_14000aba9;
    }
    uVar6 = 0x94007;
    if (param_1 < 0x94008) {
      if (param_1 == 0x94007) {
        uVar4 = 0x2e;
      }
      else if (param_1 == 0x92012) {
        uVar4 = 0x29;
        uVar6 = 0;
      }
      else if (param_1 == 0x93004) {
        uVar4 = 0x2a;
        uVar6 = 0;
      }
      else if (param_1 == 0x93005) {
        uVar4 = 0x2b;
        uVar6 = 0;
      }
      else {
        uVar4 = param_1 - 0x93006;
        uVar6 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          uVar4 = 0x2c;
        }
        else {
          if (uVar4 != 0xfb) goto LAB_14000ab20;
          uVar4 = 0x2d;
        }
      }
      goto LAB_14000aba9;
    }
    if (param_1 == 0x94008) {
      uVar4 = 0x2f;
      uVar6 = 0;
      goto LAB_14000aba9;
    }
    if (param_1 == 0x94009) {
      uVar4 = 0x30;
      uVar6 = 0;
      goto LAB_14000aba9;
    }
    uVar4 = param_1 - 0x9400b;
    uVar6 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      uVar4 = 0x31;
      goto LAB_14000aba9;
    }
    if (uVar4 == 1) {
      uVar4 = 0x32;
      goto LAB_14000aba9;
    }
LAB_14000ab20:
    if (param_1 == 0x82002) {
      uVar4 = 0xd;
      uVar6 = 0;
LAB_14000ab8a:
      uVar4 = uVar4 + 0x33;
      goto LAB_14000aba9;
    }
    if (param_1 == 0x82003) {
      uVar4 = 0xe;
      uVar6 = 0;
      goto LAB_14000ab8a;
    }
    uVar4 = param_1 - 0x82004;
    uVar6 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      uVar4 = 0xf;
      goto LAB_14000ab8a;
    }
    if (uVar4 == 1) {
      uVar4 = 0x10;
      goto LAB_14000ab8a;
    }
LAB_14000ab38:
    if (param_1 == 0x71008) {
      uVar4 = 0x4a;
      uVar6 = 0;
      goto LAB_14000aba9;
    }
    if (param_1 == 0x71009) {
      uVar4 = 0x4b;
      uVar6 = 0;
      goto LAB_14000aba9;
    }
    uVar4 = param_1 - 0x7100a;
    uVar6 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      uVar4 = 0x4c;
      goto LAB_14000aba9;
    }
    if (uVar4 == 0xff7) {
      uVar4 = 0x4d;
      goto LAB_14000aba9;
    }
  }
LAB_14000aede:
  uVar6 = XdvUtilDbgPrint("Driver Verifier: XdvQueryRuleSuppression: wrong rule ID: %d\n",
                          (ulonglong)param_1,1,10);
LAB_14000aeec:
  return uVar6 & 0xffffffffffffff00;
}



===== XdvGetRuleTimedLimit @ 14000af14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 XdvGetRuleTimedLimit(uint param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar5 = 1;
  iVar8 = 0xd;
  uVar6 = 4;
  iVar4 = 4;
  iVar7 = 10;
  if (0x40003 < param_1) {
    if (param_1 < 0x92012) {
      if (param_1 == 0x92011) {
        uVar6 = 0x28;
      }
      else if (param_1 < 0x91003) {
        if (param_1 == 0x91002) {
          uVar6 = 0x22;
        }
        else if (param_1 == 0x40007) {
          uVar6 = 0x1d;
        }
        else if (param_1 == 0x4000a) {
          uVar6 = 0x1e;
        }
        else if (param_1 == 0x4100b) {
          uVar6 = 0x1f;
        }
        else if (param_1 == 0x43006) {
          uVar6 = 0x20;
        }
        else {
          if (param_1 != 0x91001) {
            if (param_1 < 0x82002) {
              if (param_1 == 0x82001) {
                iVar4 = 0xc;
              }
              else if (param_1 < 0x81008) {
                if (param_1 != 0x81007) goto LAB_14000b1a6;
                iVar4 = 6;
              }
              else if (param_1 == 0x81008) {
                iVar4 = 7;
              }
              else if (param_1 == 0x81009) {
                iVar4 = 8;
              }
              else if (param_1 == 0x8100a) {
                iVar4 = 9;
              }
              else if (param_1 == 0x8100b) {
                iVar4 = 10;
              }
              else {
                if (param_1 != 0x8100c) goto LAB_14000b414;
                iVar4 = 0xb;
              }
              goto LAB_14000b4c7;
            }
            goto LAB_14000b3ee;
          }
          uVar6 = 0x21;
        }
      }
      else if (param_1 == 0x9100e) {
        uVar6 = 0x23;
      }
      else if (param_1 == 0x92003) {
        uVar6 = 0x24;
      }
      else if (param_1 == 0x9200d) {
        uVar6 = 0x25;
      }
      else if (param_1 == 0x9200f) {
        uVar6 = 0x26;
      }
      else {
        if (param_1 != 0x92010) goto LAB_14000b3ee;
        uVar6 = 0x27;
      }
      goto LAB_14000b4e6;
    }
    if (param_1 < 0x94008) {
      if (param_1 == 0x94007) {
        uVar6 = 0x2e;
      }
      else if (param_1 == 0x92012) {
        uVar6 = 0x29;
      }
      else if (param_1 == 0x93004) {
        uVar6 = 0x2a;
      }
      else if (param_1 == 0x93005) {
        uVar6 = 0x2b;
      }
      else if (param_1 == 0x93006) {
        uVar6 = 0x2c;
      }
      else {
        if (param_1 != 0x93101) goto LAB_14000b3ee;
        uVar6 = 0x2d;
      }
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x94008) {
      uVar6 = 0x2f;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x94009) {
      uVar6 = 0x30;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x9400b) {
      uVar6 = 0x31;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x9400c) {
      uVar6 = 0x32;
      goto LAB_14000b4e6;
    }
LAB_14000b3ee:
    if (param_1 == 0x82002) {
      iVar4 = 0xd;
LAB_14000b4c7:
      uVar6 = iVar4 + 0x33;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x82003) {
      iVar4 = 0xe;
      goto LAB_14000b4c7;
    }
    if (param_1 == 0x82004) {
      iVar4 = 0xf;
      goto LAB_14000b4c7;
    }
    if (param_1 == 0x82005) {
      iVar4 = 0x10;
      goto LAB_14000b4c7;
    }
LAB_14000b414:
    if (param_1 == 0x71008) {
      uVar6 = 0x4a;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x71009) {
      uVar6 = 0x4b;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x7100a) {
      uVar6 = 0x4c;
      goto LAB_14000b4e6;
    }
    if (param_1 == 0x72001) {
      uVar6 = 0x4d;
      goto LAB_14000b4e6;
    }
LAB_14000b431:
    uVar6 = 0xffffffff;
    goto LAB_14000b434;
  }
  if (param_1 == 0x40003) {
    uVar6 = 0x1c;
  }
  else if (param_1 < 0x20011) {
    if (param_1 == 0x20010) {
      uVar6 = 0xe;
    }
    else if (param_1 < 0x2000a) {
      if (param_1 == 0x20009) {
        uVar6 = 7;
      }
      else if (param_1 == 0x20002) {
        uVar6 = 0;
      }
      else if (param_1 == 0x20003) {
        uVar6 = 1;
      }
      else if (param_1 == 0x20004) {
        uVar6 = 2;
      }
      else if (param_1 == 0x20005) {
        uVar6 = 3;
      }
      else if (param_1 != 0x20006) {
        if (param_1 == 0x20007) {
          uVar6 = 5;
        }
        else {
          if (param_1 != 0x20008) goto LAB_14000b1a6;
          uVar6 = 6;
        }
      }
    }
    else if (param_1 == 0x2000a) {
      uVar6 = 8;
    }
    else if (param_1 == 0x2000b) {
      uVar6 = 9;
    }
    else if (param_1 == 0x2000c) {
      uVar6 = 10;
    }
    else if (param_1 == 0x2000d) {
      uVar6 = 0xb;
    }
    else if (param_1 == 0x2000e) {
      uVar6 = 0xc;
    }
    else {
      if (param_1 != 0x2000f) goto LAB_14000b1a6;
      uVar6 = 0xd;
    }
  }
  else if (param_1 < 0x2001d) {
    if (param_1 == 0x2001c) {
      uVar6 = 0x15;
    }
    else if (param_1 == 0x20011) {
      uVar6 = 0xf;
    }
    else if (param_1 == 0x20015) {
      uVar6 = 0x10;
    }
    else if (param_1 == 0x20016) {
      uVar6 = 0x11;
    }
    else if (param_1 == 0x20019) {
      uVar6 = 0x12;
    }
    else if (param_1 == 0x2001a) {
      uVar6 = 0x13;
    }
    else {
      if (param_1 != 0x2001b) goto LAB_14000b1a6;
      uVar6 = 0x14;
    }
  }
  else if (param_1 == 0x2001e) {
    uVar6 = 0x16;
  }
  else if (param_1 == 0x2001f) {
    uVar6 = 0x17;
  }
  else if (param_1 == 0x20022) {
    uVar6 = 0x18;
  }
  else if (param_1 == 0x20023) {
    uVar6 = 0x19;
  }
  else if (param_1 == 0x20024) {
    uVar6 = 0x1a;
  }
  else {
    if (param_1 != 0x20025) {
LAB_14000b1a6:
      if (param_1 == 0x81001) {
        iVar4 = 0;
      }
      else if (param_1 == 0x81002) {
        iVar4 = 1;
      }
      else if (param_1 == 0x81003) {
        iVar4 = 2;
      }
      else if (param_1 == 0x81004) {
        iVar4 = 3;
      }
      else if (param_1 != 0x81005) {
        if (param_1 != 0x81006) {
          if (0x71007 < param_1) goto LAB_14000b414;
          if (param_1 == 0x71007) {
            uVar6 = 0x49;
          }
          else if (param_1 == 0x71001) {
            uVar6 = 0x44;
          }
          else if (param_1 == 0x71003) {
            uVar6 = 0x45;
          }
          else if (param_1 == 0x71004) {
            uVar6 = 0x46;
          }
          else if (param_1 == 0x71005) {
            uVar6 = 0x47;
          }
          else {
            if (param_1 != 0x71006) goto LAB_14000b431;
            uVar6 = 0x48;
          }
          goto LAB_14000b4e6;
        }
        iVar4 = 5;
      }
      goto LAB_14000b4c7;
    }
    uVar6 = 0x1b;
  }
LAB_14000b4e6:
  if (uVar6 < 0x1a) {
    if (uVar6 != 0x19) {
      if (uVar6 < 0xd) {
        if (uVar6 != 0xc) {
          if (6 < uVar6) {
            iVar4 = uVar6 - 7;
            bVar9 = iVar4 == 0;
            goto LAB_14000b506;
          }
          uVar3 = uVar6;
          if (uVar6 != 6) goto LAB_14000b501;
        }
      }
      else if (uVar6 < 0x14) {
        if (uVar6 != 0x13) {
          uVar3 = uVar6 - 0xd;
LAB_14000b501:
          if (uVar3 != 0) {
            iVar4 = uVar3 - 1;
            bVar9 = iVar4 == 0;
            goto LAB_14000b506;
          }
        }
      }
      else {
        iVar4 = uVar6 - 0x14;
        bVar9 = iVar4 == 0;
LAB_14000b506:
        if ((((!bVar9) && (iVar4 != 1)) && (iVar4 != 2)) && (iVar4 = iVar4 + -3, iVar4 != 0)) {
LAB_14000b51a:
          if (iVar4 != 1) goto LAB_14000b434;
        }
      }
    }
LAB_14000b520:
    iVar5 = 0;
  }
  else {
    if (uVar6 < 0x27) {
      if (uVar6 != 0x26) {
        if (uVar6 < 0x21) {
          if (((uVar6 == 0x20) || (uVar6 == 0x1a)) || (uVar6 == 0x1b)) goto LAB_14000b520;
          if (((uVar6 != 0x1c) && (uVar6 != 0x1d)) && (iVar4 = uVar6 - 0x1e, iVar4 != 0))
          goto LAB_14000b51a;
        }
        else {
          if (((uVar6 != 0x21) && (uVar6 != 0x22)) && (iVar5 = uVar6 - 0x23, iVar5 != 0))
          goto LAB_14000b583;
LAB_14000b5fd:
          iVar5 = 7;
        }
        goto LAB_14000b593;
      }
    }
    else if (uVar6 < 0x2e) {
      if (uVar6 == 0x2d) {
        iVar5 = 6;
        goto LAB_14000b593;
      }
      if (((uVar6 != 0x27) && (uVar6 != 0x28)) && (uVar6 != 0x29)) {
        if (((uVar6 == 0x2a) || (uVar6 == 0x2b)) || (uVar6 == 0x2c)) goto LAB_14000b5fd;
        goto LAB_14000b434;
      }
    }
    else if (((uVar6 != 0x2e) && (uVar6 != 0x2f)) && (iVar5 = uVar6 - 0x30, iVar5 != 0)) {
LAB_14000b583:
      if ((iVar5 != 1) && (iVar5 != 2)) {
LAB_14000b434:
        if ((int)(uVar6 - 0x33) < 9) {
          if (uVar6 - 0x33 == 8) {
LAB_14000b627:
            iVar7 = 9;
          }
          else if ((uVar6 != 0x33) && (uVar6 != 0x34)) {
            if (uVar6 == 0x35) goto LAB_14000b627;
            if (uVar6 != 0x36) {
              if (uVar6 == 0x37) goto LAB_14000b627;
              if (((uVar6 != 0x38) && (uVar6 != 0x39)) && (uVar6 != 0x3a)) goto LAB_14000b668;
            }
          }
        }
        else if (((uVar6 != 0x3c) && (uVar6 != 0x3d)) && (uVar6 != 0x3e)) {
          if (((uVar6 != 0x3f) && (uVar6 != 0x40)) &&
             ((uVar6 != 0x41 && ((uVar6 != 0x42 && (uVar6 != 0x43)))))) {
LAB_14000b668:
            if ((int)(uVar6 - 0x44) < 6) {
              if (((uVar6 - 0x44 != 5) && (uVar6 != 0x44)) && (uVar6 != 0x45)) {
                if (((uVar6 != 0x46) && (uVar6 != 0x47)) && (uVar6 != 0x48)) {
                  return 0;
                }
                goto LAB_14000b596;
              }
            }
            else if (((uVar6 != 0x4a) && (uVar6 != 0x4b)) && (uVar6 != 0x4c)) {
              if (uVar6 != 0x4d) {
                return 0;
              }
              iVar8 = 0xe;
              goto LAB_14000b596;
            }
            iVar8 = 0xc;
            goto LAB_14000b596;
          }
          iVar7 = 0xb;
        }
        iVar8 = iVar7;
        goto LAB_14000b596;
      }
    }
    iVar5 = 8;
  }
LAB_14000b593:
  iVar8 = iVar5;
LAB_14000b596:
  if (iVar8 == 2) {
    puVar1 = &DAT_140059730;
  }
  else if (iVar8 == 5) {
    puVar1 = &DAT_1400598d0;
  }
  else if (iVar8 == 8) {
    puVar1 = &DAT_140059a70;
  }
  else if (iVar8 == 0xb) {
    puVar1 = &DAT_140059c10;
  }
  else {
    if (iVar8 != 0xe) {
      return 0;
    }
    puVar1 = &DAT_140059db0;
  }
  if ((code *)*puVar1 == (code *)0x0) {
    return 0;
  }
  uVar2 = (*(code *)*puVar1)(param_1);
  return uVar2;
}



===== XdvGetRuleTimedUnit @ 14000b71c =====

undefined4 XdvGetRuleTimedUnit(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar6 = 0;
  iVar8 = 0xd;
  uVar3 = 4;
  iVar7 = 10;
  if (0x40003 < param_1) {
    if (param_1 < 0x92012) {
      if (param_1 == 0x92011) {
        uVar3 = 0x28;
      }
      else if (param_1 < 0x91003) {
        if (param_1 == 0x91002) {
          uVar3 = 0x22;
        }
        else if (param_1 == 0x40007) {
          uVar3 = 0x1d;
        }
        else if (param_1 == 0x4000a) {
          uVar3 = 0x1e;
        }
        else if (param_1 == 0x4100b) {
          uVar3 = 0x1f;
        }
        else if (param_1 == 0x43006) {
          uVar3 = 0x20;
        }
        else {
          if (param_1 != 0x91001) {
            if (param_1 < 0x82002) {
              if (param_1 == 0x82001) {
                uVar3 = 0xc;
              }
              else if (param_1 < 0x81008) {
                if (param_1 != 0x81007) goto LAB_14000b9db;
                uVar3 = 6;
              }
              else if (param_1 == 0x81008) {
                uVar3 = 7;
              }
              else if (param_1 == 0x81009) {
                uVar3 = 8;
              }
              else if (param_1 == 0x8100a) {
                uVar3 = 9;
              }
              else if (param_1 == 0x8100b) {
                uVar3 = 10;
              }
              else {
                if (param_1 != 0x8100c) goto LAB_14000bc4a;
                uVar3 = 0xb;
              }
              goto LAB_14000bcf7;
            }
            goto LAB_14000bc24;
          }
          uVar3 = 0x21;
        }
      }
      else if (param_1 == 0x9100e) {
        uVar3 = 0x23;
      }
      else if (param_1 == 0x92003) {
        uVar3 = 0x24;
      }
      else if (param_1 == 0x9200d) {
        uVar3 = 0x25;
      }
      else if (param_1 == 0x9200f) {
        uVar3 = 0x26;
      }
      else {
        if (param_1 != 0x92010) goto LAB_14000bc24;
        uVar3 = 0x27;
      }
      goto LAB_14000bd16;
    }
    if (param_1 < 0x94008) {
      if (param_1 == 0x94007) {
        uVar3 = 0x2e;
      }
      else if (param_1 == 0x92012) {
        uVar3 = 0x29;
      }
      else if (param_1 == 0x93004) {
        uVar3 = 0x2a;
      }
      else if (param_1 == 0x93005) {
        uVar3 = 0x2b;
      }
      else if (param_1 == 0x93006) {
        uVar3 = 0x2c;
      }
      else {
        if (param_1 != 0x93101) goto LAB_14000bc24;
        uVar3 = 0x2d;
      }
      goto LAB_14000bd16;
    }
    if (param_1 == 0x94008) {
      uVar3 = 0x2f;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x94009) {
      uVar3 = 0x30;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x9400b) {
      uVar3 = 0x31;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x9400c) {
      uVar3 = 0x32;
      goto LAB_14000bd16;
    }
LAB_14000bc24:
    if (param_1 == 0x82002) {
      uVar3 = 0xd;
LAB_14000bcf7:
      uVar3 = uVar3 + 0x33;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x82003) {
      uVar3 = 0xe;
      goto LAB_14000bcf7;
    }
    if (param_1 == 0x82004) {
      uVar3 = 0xf;
      goto LAB_14000bcf7;
    }
    if (param_1 == 0x82005) {
      uVar3 = 0x10;
      goto LAB_14000bcf7;
    }
LAB_14000bc4a:
    if (param_1 == 0x71008) {
      uVar3 = 0x4a;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x71009) {
      uVar3 = 0x4b;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x7100a) {
      uVar3 = 0x4c;
      goto LAB_14000bd16;
    }
    if (param_1 == 0x72001) {
      uVar3 = 0x4d;
      goto LAB_14000bd16;
    }
LAB_14000bc64:
    uVar3 = 0xffffffff;
    goto LAB_14000bc67;
  }
  if (param_1 == 0x40003) {
    uVar3 = 0x1c;
  }
  else if (param_1 < 0x20011) {
    if (param_1 == 0x20010) {
      uVar3 = 0xe;
    }
    else if (param_1 < 0x2000a) {
      if (param_1 == 0x20009) {
        uVar3 = 7;
      }
      else if (param_1 == 0x20002) {
        uVar3 = 0;
      }
      else if (param_1 == 0x20003) {
        uVar3 = 1;
      }
      else if (param_1 == 0x20004) {
        uVar3 = 2;
      }
      else if (param_1 == 0x20005) {
        uVar3 = 3;
      }
      else if (param_1 != 0x20006) {
        if (param_1 == 0x20007) {
          uVar3 = 5;
        }
        else {
          if (param_1 != 0x20008) goto LAB_14000b9db;
          uVar3 = 6;
        }
      }
    }
    else if (param_1 == 0x2000a) {
      uVar3 = 8;
    }
    else if (param_1 == 0x2000b) {
      uVar3 = 9;
    }
    else if (param_1 == 0x2000c) {
      uVar3 = 10;
    }
    else if (param_1 == 0x2000d) {
      uVar3 = 0xb;
    }
    else if (param_1 == 0x2000e) {
      uVar3 = 0xc;
    }
    else {
      if (param_1 != 0x2000f) goto LAB_14000b9db;
      uVar3 = 0xd;
    }
  }
  else if (param_1 < 0x2001d) {
    if (param_1 == 0x2001c) {
      uVar3 = 0x15;
    }
    else if (param_1 == 0x20011) {
      uVar3 = 0xf;
    }
    else if (param_1 == 0x20015) {
      uVar3 = 0x10;
    }
    else if (param_1 == 0x20016) {
      uVar3 = 0x11;
    }
    else if (param_1 == 0x20019) {
      uVar3 = 0x12;
    }
    else if (param_1 == 0x2001a) {
      uVar3 = 0x13;
    }
    else {
      if (param_1 != 0x2001b) goto LAB_14000b9db;
      uVar3 = 0x14;
    }
  }
  else if (param_1 == 0x2001e) {
    uVar3 = 0x16;
  }
  else if (param_1 == 0x2001f) {
    uVar3 = 0x17;
  }
  else if (param_1 == 0x20022) {
    uVar3 = 0x18;
  }
  else if (param_1 == 0x20023) {
    uVar3 = 0x19;
  }
  else if (param_1 == 0x20024) {
    uVar3 = 0x1a;
  }
  else {
    if (param_1 != 0x20025) {
LAB_14000b9db:
      if (param_1 == 0x81001) {
        uVar3 = 0;
      }
      else if (param_1 == 0x81002) {
        uVar3 = 1;
      }
      else if (param_1 == 0x81003) {
        uVar3 = 2;
      }
      else if (param_1 == 0x81004) {
        uVar3 = 3;
      }
      else if (param_1 != 0x81005) {
        if (param_1 != 0x81006) {
          if (0x71007 < param_1) goto LAB_14000bc4a;
          if (param_1 == 0x71007) {
            uVar3 = 0x49;
          }
          else if (param_1 == 0x71001) {
            uVar3 = 0x44;
          }
          else if (param_1 == 0x71003) {
            uVar3 = 0x45;
          }
          else if (param_1 == 0x71004) {
            uVar3 = 0x46;
          }
          else if (param_1 == 0x71005) {
            uVar3 = 0x47;
          }
          else {
            if (param_1 != 0x71006) goto LAB_14000bc64;
            uVar3 = 0x48;
          }
          goto LAB_14000bd16;
        }
        uVar3 = 5;
      }
      goto LAB_14000bcf7;
    }
    uVar3 = 0x1b;
  }
LAB_14000bd16:
  if (uVar3 < 0x1a) {
    if (uVar3 != 0x19) {
      if (uVar3 < 0xd) {
        if (uVar3 != 0xc) {
          if (6 < uVar3) {
            iVar4 = uVar3 - 7;
            bVar9 = iVar4 == 0;
            goto LAB_14000bd47;
          }
          if (uVar3 != 6) {
            uVar5 = uVar3;
            goto LAB_14000bd3e;
          }
        }
      }
      else if (uVar3 < 0x14) {
        if (uVar3 != 0x13) {
          uVar5 = uVar3 - 0xd;
LAB_14000bd3e:
          if (uVar5 != 0) {
            iVar4 = uVar5 - 1;
            bVar9 = iVar4 == 0;
            goto LAB_14000bd47;
          }
        }
      }
      else {
        iVar4 = uVar3 - 0x14;
        bVar9 = iVar4 == 0;
LAB_14000bd47:
        if ((((!bVar9) && (iVar4 != 1)) && (iVar4 != 2)) && (iVar4 = iVar4 + -3, iVar4 != 0)) {
LAB_14000bd68:
          if (iVar4 != 1) goto LAB_14000bc67;
        }
      }
    }
LAB_14000bdea:
    iVar8 = iVar6;
LAB_14000bded:
    if (iVar8 == 2) {
      puVar2 = &DAT_1400595a8;
    }
    else if (iVar8 == 5) {
      puVar2 = &DAT_140059748;
    }
    else if (iVar8 == 8) {
      puVar2 = &DAT_1400598e8;
    }
    else if (iVar8 == 0xb) {
      puVar2 = &DAT_140059a88;
    }
    else {
      if (iVar8 != 0xe) goto LAB_14000bed8;
      puVar2 = &DAT_140059c28;
    }
    uVar1 = *puVar2;
  }
  else {
    if (uVar3 < 0x27) {
      if (uVar3 == 0x26) goto LAB_14000bde7;
      if (uVar3 < 0x21) {
        if (((uVar3 != 0x20) && (uVar3 != 0x1a)) && (uVar3 != 0x1b)) {
          if (((uVar3 != 0x1c) && (uVar3 != 0x1d)) && (iVar4 = uVar3 - 0x1e, iVar4 != 0))
          goto LAB_14000bd68;
          iVar6 = 1;
        }
      }
      else {
        if (((uVar3 != 0x21) && (uVar3 != 0x22)) && (iVar6 = uVar3 - 0x23, iVar6 != 0))
        goto LAB_14000bdd9;
LAB_14000be56:
        iVar6 = 7;
      }
      goto LAB_14000bdea;
    }
    if (uVar3 < 0x2e) {
      if (uVar3 == 0x2d) {
        iVar6 = 6;
        goto LAB_14000bdea;
      }
      if (((uVar3 != 0x27) && (uVar3 != 0x28)) && (uVar3 != 0x29)) {
        if (((uVar3 == 0x2a) || (uVar3 == 0x2b)) || (uVar3 == 0x2c)) goto LAB_14000be56;
        goto LAB_14000bc67;
      }
LAB_14000bde7:
      iVar6 = 8;
      goto LAB_14000bdea;
    }
    if (((uVar3 == 0x2e) || (uVar3 == 0x2f)) || (iVar6 = uVar3 - 0x30, iVar6 == 0))
    goto LAB_14000bde7;
LAB_14000bdd9:
    if ((iVar6 == 1) || (iVar6 == 2)) goto LAB_14000bde7;
LAB_14000bc67:
    if ((int)(uVar3 - 0x33) < 9) {
      if (uVar3 - 0x33 == 8) {
LAB_14000be85:
        iVar7 = 9;
      }
      else if ((uVar3 != 0x33) && (uVar3 != 0x34)) {
        if (uVar3 == 0x35) goto LAB_14000be85;
        if (uVar3 != 0x36) {
          if (uVar3 == 0x37) goto LAB_14000be85;
          if (((uVar3 != 0x38) && (uVar3 != 0x39)) && (uVar3 != 0x3a)) goto LAB_14000bead;
        }
      }
LAB_14000bf03:
      iVar8 = iVar7;
      goto LAB_14000bded;
    }
    if (((uVar3 == 0x3c) || (uVar3 == 0x3d)) || (uVar3 == 0x3e)) goto LAB_14000bf03;
    if (((uVar3 == 0x3f) || (uVar3 == 0x40)) ||
       ((uVar3 == 0x41 || ((uVar3 == 0x42 || (uVar3 == 0x43)))))) {
      iVar7 = 0xb;
      goto LAB_14000bf03;
    }
LAB_14000bead:
    if (5 < (int)(uVar3 - 0x44)) {
      if (((uVar3 == 0x4a) || (uVar3 == 0x4b)) || (uVar3 == 0x4c)) {
LAB_14000bef8:
        iVar8 = 0xc;
      }
      else {
        if (uVar3 != 0x4d) goto LAB_14000bed8;
        iVar8 = 0xe;
      }
      goto LAB_14000bded;
    }
    if (((uVar3 - 0x44 == 5) || (uVar3 == 0x44)) || (uVar3 == 0x45)) goto LAB_14000bef8;
    if (((uVar3 == 0x46) || (uVar3 == 0x47)) || (uVar3 == 0x48)) goto LAB_14000bded;
LAB_14000bed8:
    uVar1 = 0;
  }
  return uVar1;
}



===== XdvIsTimedExtensionStarted @ 14000bf50 =====

undefined1 XdvIsTimedExtensionStarted(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = (longlong)param_1 * 0x1a0;
  uVar2 = ExAcquireSpinLockShared(&DAT_1400595c4 + lVar3);
  uVar1 = (&DAT_1400595a4)[lVar3];
  ExReleaseSpinLockShared(&DAT_1400595c4 + lVar3,uVar2);
  return uVar1;
}



===== XdvMultiplyTimedFactor @ 14000bfb4 =====

void XdvMultiplyTimedFactor(void)

{
  ulonglong uVar1;
  uint uVar2;
  
  if (XdvTimedFactor != 0) {
    if (DAT_140032a48 == 0) {
      if (0xffff < XdvTimedFactor) {
        XdvTimedFactor = 0xffff;
      }
      XDV_NDISOIDCOMPLETE_TIMELIMIT = (int)(XDV_NDISOIDCOMPLETE_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_NDISDATASEND_TIMELIMIT = (int)(XDV_NDISDATASEND_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_NDISDATAHANG_TIMELIMIT = (int)(XDV_NDISDATAHANG_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_NDISFILTERPAUSECOMPLETE_TIMELIMIT =
           (int)(XDV_NDISFILTERPAUSECOMPLETE_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_NDISFILTERDATASEND_TIMELIMIT =
           (int)(XDV_NDISFILTERDATASEND_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_NDISFILTERDATARECEIVE_TIMELIMIT =
           (int)(XDV_NDISFILTERDATARECEIVE_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_WLAN_ASSOCIATION_TIMELIMIT = (int)(XDV_WLAN_ASSOCIATION_TIMELIMIT * XdvTimedFactor) / 1000
      ;
      XDV_WLAN_CONNECTION_ROAMING_TIMELIMIT =
           (int)(XDV_WLAN_CONNECTION_ROAMING_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_WLAN_CONNECT_TIMELIMIT = (int)(XDV_WLAN_CONNECT_TIMELIMIT * XdvTimedFactor) / 1000;
      XDV_WLAN_LINKQUALITY_TIMELIMIT = (int)(XDV_WLAN_LINKQUALITY_TIMELIMIT * XdvTimedFactor) / 1000
      ;
      XDV_WLANSCAN_TIMELIMIT = (int)(XDV_WLANSCAN_TIMELIMIT * XdvTimedFactor) / 1000;
    }
    else {
      uVar2 = XdvTimedFactor;
      if (0x7fffffff < XdvTimedFactor) {
        uVar2 = 0;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x92003);
      if ((char)uVar1 != '\0') {
        XDV_NDISOIDCOMPLETE_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x9200d);
      if ((char)uVar1 != '\0') {
        XDV_NDISDATASEND_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x9200f);
      if ((char)uVar1 != '\0') {
        XDV_NDISDATAHANG_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x92010);
      if ((char)uVar1 != '\0') {
        XDV_NDISFILTERPAUSECOMPLETE_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x92011);
      if ((char)uVar1 != '\0') {
        XDV_NDISFILTERDATASEND_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x92012);
      if ((char)uVar1 != '\0') {
        XDV_NDISFILTERDATARECEIVE_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x94007);
      if ((char)uVar1 != '\0') {
        XDV_WLAN_ASSOCIATION_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x94008);
      if ((char)uVar1 != '\0') {
        XDV_WLAN_CONNECTION_ROAMING_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x94009);
      if ((char)uVar1 != '\0') {
        XDV_WLAN_CONNECT_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x9400b);
      if ((char)uVar1 != '\0') {
        XDV_WLAN_LINKQUALITY_TIMELIMIT = uVar2;
      }
      uVar1 = XdvIsRuleIdInXdvDebugRules(0x9400c);
      if ((char)uVar1 != '\0') {
        XDV_WLANSCAN_TIMELIMIT = uVar2;
      }
    }
  }
  return;
}



===== XdvNdisTimedCallback @ 14000c250 =====

void XdvNdisTimedCallback(void)

{
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    Ndis_OnTimerExpire();
    if (((XdvVerifierOptions & 0x10000) != 0) && ((DAT_140032a4c & 0x10) == 0)) {
      if (NdisPerformanceControlCounter < 2) {
        NdisPerformanceControlCounter = 1;
        NdisPerformanceControl_OnTimer();
      }
      else {
        NdisPerformanceControlCounter = NdisPerformanceControlCounter - 1;
      }
    }
  }
  return;
}



===== XdvPassiveTimerRoutine @ 14000c2b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 XdvPassiveTimerRoutine(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  
  LOCK();
  *(longlong *)(param_2 + 0x10) = *(longlong *)(param_2 + 0x10) + 1;
  UNLOCK();
  (**(code **)(param_2 + 0x188))(param_2 + 0x28,param_2 + 0x24,*(undefined4 *)(param_2 + 8));
  LOCK();
  uVar1 = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_2 + 0x20) = 0;
  UNLOCK();
  return uVar1;
}



===== XdvPerformanceControlForNdisRules @ 14000c2e8 =====

void XdvPerformanceControlForNdisRules(longlong param_1,longlong param_2)

{
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 1;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 2;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 4;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 8;
  FreeWatchedList((longlong *)(param_1 + 0x160));
  *(longlong *)(param_1 + 0x160) = 0;
  XdvNdisDataClean((longlong *)(param_1 + 0x68));
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  XdvNdisDataClean((longlong *)(param_1 + 0x90));
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x40;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  XdvNdisDataClean((longlong *)(param_1 + 0x100));
  XdvNdisDataClean((longlong *)(param_1 + 0x108));
  *(longlong *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x110) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  *(undefined8 *)(param_1 + 0x128) = 0;
  XdvNdisDataClean((longlong *)(param_1 + 0x130));
  XdvNdisDataClean((longlong *)(param_1 + 0x138));
  *(longlong *)(param_1 + 0x130) = 0;
  *(undefined8 *)(param_1 + 0x138) = 0;
  *(undefined8 *)(param_1 + 0x140) = 0;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x200;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x400;
  FreeWatchedList((longlong *)(param_1 + 0x168));
  *(longlong *)(param_1 + 0x168) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x800;
  *(undefined8 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x2000;
  FreeWatchedList((longlong *)(param_1 + 0x170));
  *(longlong *)(param_1 + 0x170) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x4000;
  FreeWatchedList((longlong *)(param_1 + 0x178));
  *(longlong *)(param_1 + 0x178) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x8000;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x10000;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(ulonglong *)(param_2 + 0x50) = *(ulonglong *)(param_2 + 0x50) | 0x20000;
  FreeWatchedList((longlong *)(param_1 + 0x180));
  *(longlong *)(param_1 + 0x180) = 0;
  return;
}



===== XdvRuleId2TimedLimit @ 14000c4a0 =====

undefined4 * XdvRuleId2TimedLimit(uint param_1)

{
  if (param_1 < 0x92013) {
    if (param_1 == 0x92012) {
      return &XDV_NDISFILTERDATARECEIVE_TIMELIMIT;
    }
    if (param_1 == 0x92003) {
      return &XDV_NDISOIDCOMPLETE_TIMELIMIT;
    }
    if (param_1 == 0x9200d) {
      return &XDV_NDISDATASEND_TIMELIMIT;
    }
    if (param_1 == 0x9200f) {
      return &XDV_NDISDATAHANG_TIMELIMIT;
    }
    if (param_1 == 0x92010) {
      return &XDV_NDISFILTERPAUSECOMPLETE_TIMELIMIT;
    }
    if (param_1 == 0x92011) {
      return &XDV_NDISFILTERDATASEND_TIMELIMIT;
    }
  }
  else {
    if (param_1 == 0x94007) {
      return &XDV_WLAN_ASSOCIATION_TIMELIMIT;
    }
    if (param_1 == 0x94008) {
      return &XDV_WLAN_CONNECTION_ROAMING_TIMELIMIT;
    }
    if (param_1 == 0x94009) {
      return &XDV_WLAN_CONNECT_TIMELIMIT;
    }
    if (param_1 == 0x9400b) {
      return &XDV_WLAN_LINKQUALITY_TIMELIMIT;
    }
    if (param_1 == 0x9400c) {
      return &XDV_WLANSCAN_TIMELIMIT;
    }
  }
  return (undefined4 *)0x0;
}



===== XdvTimedGetCurrentTimeTick @ 14000c550 =====

longlong XdvTimedGetCurrentTimeTick(uint param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if (4 < param_1) {
    return 0;
  }
  lVar2 = 0;
  LOCK();
  lVar1 = *(longlong *)(&DAT_1400595b0 + (longlong)(int)param_1 * 0x1a0);
  if (lVar1 == 0) {
    *(longlong *)(&DAT_1400595b0 + (longlong)(int)param_1 * 0x1a0) = 0;
  }
  else {
    lVar2 = lVar1;
  }
  UNLOCK();
  return lVar2;
}



===== XdvTimedRegisterContext @ 14000c580 =====

undefined1 XdvTimedRegisterContext(int param_1,undefined8 *param_2)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  cVar2 = XdvIsTimedExtensionStarted(param_1);
  if (((cVar2 == '\0') || (param_2 == (undefined8 *)0x0)) || (*(int *)(param_2 + 2) != param_1)) {
    uVar3 = 0;
  }
  else {
    lVar6 = (longlong)param_1 * 0x1a0;
    uVar3 = ExAcquireSpinLockExclusive(&DAT_1400595c4 + lVar6);
    puVar7 = auStack_28;
    puVar4 = &DAT_1400595c8 + lVar6;
    puVar5 = *(undefined8 **)(&DAT_1400595d0 + lVar6);
    if ((undefined *)*puVar5 != puVar4) {
      puVar4 = (undefined *)0x3;
      pcVar1 = (code *)swi(0x29);
      uVar3 = (*pcVar1)();
      puVar7 = auStack_20;
    }
    *param_2 = puVar4;
    param_2[1] = puVar5;
    *puVar5 = param_2;
    *(undefined8 **)(puVar4 + 8) = param_2;
    param_2[4] = &XdvTimedExtensions;
    *(undefined8 *)(puVar7 + -8) = 0x14000c607;
    ExReleaseSpinLockExclusive(&DAT_1400595c4 + lVar6,uVar3);
    uVar3 = 1;
  }
  return uVar3;
}



===== XdvTimedRemoveContext @ 14000c630 =====

ulonglong XdvTimedRemoveContext(int param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  ulonglong in_RAX;
  undefined8 uVar5;
  
  if ((param_2 != (longlong *)0x0) && ((int)param_2[2] == param_1)) {
    uVar4 = ExAcquireSpinLockExclusive(&DAT_1400595c4 + (longlong)param_1 * 0x1a0);
    lVar1 = *param_2;
    if ((*(longlong **)(lVar1 + 8) == param_2) &&
       (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      uVar5 = ExReleaseSpinLockExclusive
                        (&DAT_1400595c4 + (longlong)param_1 * 0x1a0,
                         CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4));
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
    pcVar3 = (code *)swi(0x29);
    in_RAX = (*pcVar3)(3);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== XdvTimedStartExtension @ 14000c6c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
XdvTimedStartExtension
          (uint param_1,int param_2,longlong param_3,undefined8 param_4,undefined1 param_5)

{
  undefined *puVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  lVar7 = (longlong)(int)param_1;
  if ((((XdvDeviceObject == 0) || (4 < param_1)) || (param_2 < 1)) || (param_3 == 0)) {
    uVar5 = 0;
  }
  else {
    lVar8 = lVar7 * 0x1a0;
    uVar3 = ExAcquireSpinLockExclusive(&DAT_1400595c4 + lVar8);
    uVar5 = 1;
    if ((&DAT_1400595a4)[lVar8] != '\x01') {
      puVar1 = &DAT_1400595c8 + lVar8;
      (&DAT_1400595a5)[lVar8] = param_5;
      *(uint *)(&XdvTimedExtensions + lVar8) = param_1;
      (&DAT_1400595a4)[lVar8] = 1;
      *(longlong *)(&DAT_140059728 + lVar8) = param_3;
      (&DAT_140059730)[lVar7 * 0x34] = param_4;
      (&DAT_1400595a8)[lVar7 * 0x68] = param_2;
      LOCK();
      *(undefined8 *)(&DAT_1400595b0 + lVar8) = 1;
      UNLOCK();
      LOCK();
      *(undefined8 *)(&DAT_1400595b8 + lVar8) = 1;
      UNLOCK();
      *(undefined **)(&DAT_1400595d0 + lVar8) = puVar1;
      *(undefined **)puVar1 = puVar1;
      *(uint *)(&DAT_1400595d8 + lVar8) = param_1;
      uVar6 = ExAllocateTimer(XdvTimerCallback,&XdvTimedExtensions + lVar8,8);
      iVar2 = (&DAT_1400595a8)[lVar7 * 0x68];
      *(undefined8 *)(&DAT_140059738 + lVar8) = uVar6;
      local_48 = 0;
      uStack_40 = -(ulonglong)((XdvVerifierOptions & 0x10000) != 0) | 0x80000000;
      cVar4 = ExSetTimer(uVar6,0xfffffffffd050f80,(longlong)(iVar2 * 10000),&local_48);
      if (cVar4 != '\0') {
        uVar5 = 0;
      }
    }
    ExReleaseSpinLockExclusive(&DAT_1400595c4 + lVar8,uVar3);
  }
  return uVar5;
}



===== XdvTimedStopExtension @ 14000c850 =====

undefined1 XdvTimedStopExtension(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char cVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined8 local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res10 = 0;
  if (4 < param_1) {
    return 0;
  }
  uVar7 = 1;
  lVar6 = (longlong)(int)param_1 * 0x1a0;
  while( true ) {
    LOCK();
    iVar2 = *(int *)(&DAT_1400595c0 + lVar6);
    *(int *)(&DAT_1400595c0 + lVar6) = 1;
    UNLOCK();
    if (iVar2 == 0) break;
    local_res10 = 2000000;
    KeDelayExecutionThread(0,0,&local_res10);
  }
  puVar1 = &DAT_1400595c4 + lVar6;
  uVar4 = ExAcquireSpinLockExclusive(puVar1);
  uVar3 = 1;
  if ((&DAT_1400595a4)[lVar6] != '\0') {
    if (*(undefined8 **)(&DAT_1400595c8 + lVar6) == (undefined8 *)(&DAT_1400595c8 + lVar6)) {
      *(undefined4 *)(&XdvTimedExtensions + lVar6) = 0;
      *(undefined2 *)(&DAT_1400595a4 + lVar6) = 0;
      *(undefined8 *)(&DAT_140059728 + lVar6) = 0;
      (&DAT_1400595a8)[(longlong)(int)param_1 * 0x68] = 0;
      LOCK();
      *(undefined8 *)(&DAT_1400595b0 + lVar6) = 0;
      UNLOCK();
      LOCK();
      *(undefined8 *)(&DAT_1400595b8 + lVar6) = 0;
      UNLOCK();
      local_28 = 0;
      local_38 = 0;
      uStack_30 = 0;
      cVar5 = ExDeleteTimer(*(undefined8 *)(&DAT_140059738 + lVar6),1,0,&local_38);
      if (cVar5 == '\0') {
        ExReleaseSpinLockExclusive(puVar1,uVar4);
        return 0;
      }
      LOCK();
      *(undefined4 *)(&DAT_1400595c0 + lVar6) = 0;
      UNLOCK();
      goto LAB_14000c8e0;
    }
    uVar3 = 0;
  }
  uVar7 = uVar3;
LAB_14000c8e0:
  ExReleaseSpinLockExclusive(puVar1,uVar4);
  return uVar7;
}



===== XdvTimerCallback @ 14000c980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvTimerCallback(undefined8 param_1,int *param_2)

{
  int iVar1;
  undefined *puVar2;
  
  ExAcquireSpinLockSharedAtDpcLevel(&DAT_1400595c4 + (longlong)*param_2 * 0x1a0);
  if ((char)param_2[1] == '\0') {
    puVar2 = &DAT_1400595c4 + (longlong)*param_2 * 0x1a0;
  }
  else {
    LOCK();
    *(longlong *)(param_2 + 6) = *(longlong *)(param_2 + 6) + 1;
    UNLOCK();
    LOCK();
    iVar1 = param_2[8];
    param_2[8] = 1;
    UNLOCK();
    puVar2 = &DAT_1400595c4 + (longlong)*param_2 * 0x1a0;
    if (iVar1 == 0) {
      ExReleaseSpinLockSharedFromDpcLevel(puVar2);
      if ((*(byte *)((longlong)param_2 + 5) < 2) && (XdvTimerWorkItem != 0)) {
        IoQueueWorkItem(XdvTimerWorkItem,XdvPassiveTimerRoutine,4,param_2);
        return;
      }
      LOCK();
      *(longlong *)(param_2 + 4) = *(longlong *)(param_2 + 4) + 1;
      UNLOCK();
      (**(code **)(param_2 + 0x62))(param_2 + 10,param_2 + 9,param_2[2]);
      LOCK();
      param_2[8] = 0;
      UNLOCK();
      return;
    }
  }
  ExReleaseSpinLockSharedFromDpcLevel(puVar2);
  return;
}



===== CheckCancelLockRule_Exit @ 14000ca70 =====

void CheckCancelLockRule_Exit(longlong param_1)

{
  char cVar1;
  int iVar2;
  
  if (DAT_140032e94 < 5) {
    DifUtilDbgPrint("A registered driver cancel routine was called.\n");
    DAT_140032e94 = DAT_140032e94 + 1;
  }
  cVar1 = KeGetCurrentIrql();
  if (((cVar1 == '\x02') && (*(longlong *)(param_1 + 8) != 0)) &&
     (*(char *)(*(longlong *)(param_1 + 8) + 0x45) != '\x02')) {
    DifUtilDbgPrint("The driver should have released global cancellation lock!\n");
    iVar2 = CarReportDifPluginRuleViolation(0x25,1,0);
    if (iVar2 < 0) {
      DifUtilDbgPrint("Test: Oops! Something went wrong.\n");
    }
  }
  return;
}



===== DifTestPluginEntry @ 14000cb10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DifTestPluginEntry(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_288 [32];
  undefined4 local_268;
  undefined4 local_258;
  undefined8 local_254;
  undefined4 local_24c;
  code *local_248;
  undefined4 local_240;
  char *local_238;
  undefined4 local_230;
  code *local_228;
  code *local_220;
  char *local_218;
  undefined4 local_210;
  code *local_208;
  code *local_200;
  char *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1e8;
  code *local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  code *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  undefined8 local_1a0;
  char *local_198;
  undefined4 local_190;
  undefined8 local_188;
  code *local_180;
  char *local_178;
  undefined4 local_170;
  undefined8 local_168;
  code *local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  code *local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  code *local_120;
  char *local_118;
  undefined4 local_110;
  undefined8 local_108;
  code *local_100;
  char *local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  code *local_e0;
  char *local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  code *local_c0;
  char *local_b8;
  undefined4 local_b0;
  code *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  local_254 = 0;
  local_24c = 0;
  local_240 = 0;
  if (CarIsOnecheckEnabled != (code *)0x0) {
    (*CarIsOnecheckEnabled)();
  }
  if (param_1 != (undefined8 *)0x0) {
    _PluginTestConfigData = *param_1;
  }
  lVar2 = ExAllocatePool2(0x40,0x28,0x74537450);
  if (lVar2 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    local_230 = 0x7a;
    local_238 = "ZwCreateKey";
    local_228 = TestZwCreateKey_Entry;
    local_220 = TestZwCreateKey_Exit;
    local_218 = "MmMapIoSpace";
    local_208 = TestMmMapIoSpace_Entry;
    local_200 = TestMmMapIoSpace_Exit;
    local_1f8 = "KeSetEvent";
    local_1e0 = TestKeSetEvent_Exit;
    local_1d8 = "ExFreePoolWithTag";
    local_1c8 = TestExFreePoolWithTag_Entry;
    local_1b8 = "ExAcquireFastMutex";
    local_1a8 = TestExAcquireFastMutex_Entry;
    local_198 = "ExAllocatePoolWithTag";
    local_180 = TestExAllocatePoolWithTag_Exit;
    local_178 = "ExAllocatePool";
    local_160 = TestExAllocatePool_Exit;
    local_158 = "ExAllocatePool2";
    local_148 = TestExAllocatePool2_Entry;
    local_140 = TestExAllocatePool2_Exit;
    local_138 = "ExAllocatePool3";
    local_128 = TestExAllocatePool3_Entry;
    local_120 = TestExAllocatePool3_Exit;
    local_118 = "ExAllocatePoolWithQuota";
    local_100 = TestExAllocatePoolWithQuota_Exit;
    local_f8 = "ExAllocatePoolWithQuotaTag";
    local_e0 = TestExAllocatePoolWithQuotaTag_Exit;
    local_d8 = "DriverCancel";
    local_c0 = CheckCancelLockRule_Exit;
    local_b8 = "IRP_MJ_DEVICE_CONTROL";
    local_a8 = TestIrpMJDeviceControl_Entry;
    local_210 = 0xdd;
    local_1f0 = 0xf9;
    local_1e8 = 0;
    local_1d0 = 400;
    local_1c0 = 0;
    local_1b0 = 0x1a9;
    local_1a0 = 0;
    local_190 = 0x19e;
    local_188 = 0;
    local_170 = 0x19d;
    local_168 = 0;
    local_150 = 0x1a3;
    local_130 = 0x1a2;
    local_110 = 0x1a0;
    local_108 = 0;
    local_f0 = 0x1a1;
    local_e8 = 0;
    local_d0 = 0x10000020;
    local_c8 = 0;
    local_b0 = 0x1000000e;
    local_a0 = 0;
    local_98 = "DriverUnload";
    local_90 = 0x1000001f;
    local_88 = TestDriverUnload_Entry;
    local_80 = 0;
    local_78 = "DllInitialize";
    local_68 = TestDriverUnload_Entry;
    local_58 = "DllUnload";
    local_48 = TestDllUnload_Entry;
    local_38 = "ExAcquireFastResourceExclusive";
    local_28 = TestExAcquireFastResourceExclusive_Entry;
    local_70 = 0x80000000;
    local_60 = 0;
    local_50 = 0x80000001;
    local_40 = 0;
    local_30 = 0x1ba;
    local_20 = 0;
    *(code **)(lVar2 + 0x10) = TestPluginControl;
    *(code **)(lVar2 + 0x18) = TestPluginCleanup;
    *(undefined4 *)(lVar2 + 0x20) = 0x1004;
    XdvInsertPluginObject(0x25,lVar2);
    local_258 = 4;
    local_248 = TestObjTrkInitialize;
    iVar1 = DifRegisterPlugin(&local_238,0x11,0x25,&local_258);
    if ((-1 < iVar1) && (iVar1 = DifRegisterObjectTracking(0x25,0,_guard_check_icall), -1 < iVar1))
    {
      iVar1 = CarRegisterDefaultRuleClassConfiguration(0xc4,0x25);
      if (-1 < iVar1) {
        local_268 = 2;
        iVar1 = CarRegisterRuleOverride(0x25,2,1,2);
      }
      if (-1 < iVar1) {
        return iVar1;
      }
    }
    TestPluginCleanup();
  }
  return iVar1;
}



===== TestDriverUnload_Entry @ 14000cf40 =====

void TestDriverUnload_Entry(undefined8 *param_1)

{
  DifUtilDbgPrint("DriverUnload for 0x%llx\n",*param_1);
  return;
}



===== TestDllUnload_Entry @ 14000cf70 =====

void TestDllUnload_Entry(undefined8 *param_1)

{
  DifUtilDbgPrint("DllUnload for 0x%llx\n",*param_1);
  return;
}



===== TestExAcquireFastMutex_Entry @ 14000cfa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAcquireFastMutex_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e98 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e98 = DAT_140032e98 + 1;
  }
  return;
}



===== TestExAcquireFastResourceExclusive_Entry @ 14000d030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAcquireFastResourceExclusive_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e9c < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e9c = DAT_140032e9c + 1;
  }
  return;
}



===== TestExAllocatePool2_Entry @ 14000d0c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePool2_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e70 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e70 = DAT_140032e70 + 1;
  }
  return;
}



===== TestExAllocatePool2_Exit @ 14000d150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePool2_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e80 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e80 = DAT_140032e80 + 1;
  }
  return;
}



===== TestExAllocatePool3_Entry @ 14000d1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePool3_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e6c < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e6c = DAT_140032e6c + 1;
  }
  return;
}



===== TestExAllocatePool3_Exit @ 14000d270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePool3_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e8c < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e8c = DAT_140032e8c + 1;
  }
  return;
}



===== TestExAllocatePoolWithQuotaTag_Exit @ 14000d300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePoolWithQuotaTag_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032ea4 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032ea4 = DAT_140032ea4 + 1;
  }
  return;
}



===== TestExAllocatePoolWithQuota_Exit @ 14000d390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePoolWithQuota_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e68 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e68 = DAT_140032e68 + 1;
  }
  return;
}



===== TestExAllocatePoolWithTag_Exit @ 14000d420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePoolWithTag_Exit(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  int *piVar5;
  
  lVar4 = (*XdvGetDriverName)(*param_1);
  piVar5 = (int *)DifGetPluginPerDriverData(0x25,*param_1);
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  if ((lVar4 != 0) && (DAT_140032eac < 5)) {
    uVar1 = *param_1;
    uVar3 = (*XdvIsBootDriver)(uVar1);
    uVar2 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d, CallerAddress: 0x%llx\n",
                    lVar4,uVar2,uVar3,uVar1);
    DAT_140032eac = DAT_140032eac + 1;
  }
  return;
}



===== TestExAllocatePool_Exit @ 14000d4e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExAllocatePool_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e88 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e88 = DAT_140032e88 + 1;
  }
  return;
}



===== TestExFreePoolWithTag_Entry @ 14000d570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestExFreePoolWithTag_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032ea0 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032ea0 = DAT_140032ea0 + 1;
  }
  return;
}



===== TestIrpMJDeviceControl_Entry @ 14000d600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestIrpMJDeviceControl_Entry(longlong param_1)

{
  undefined8 uVar1;
  
  if (DAT_140032e74 < 5) {
    uVar1 = (*XdvGetDriverName)(*(undefined8 *)
                                 (*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x18));
    DifUtilDbgPrint("Driver %S registered for IRP_MJ_DEVICE_CONTROL IRP handling.\n",uVar1);
    DAT_140032e74 = DAT_140032e74 + 1;
  }
  return;
}



===== TestKeSetEvent_Exit @ 14000d650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestKeSetEvent_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e90 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e90 = DAT_140032e90 + 1;
  }
  return;
}



===== TestMmMapIoSpace_Entry @ 14000d6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestMmMapIoSpace_Entry(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032ea8 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032ea8 = DAT_140032ea8 + 1;
  }
  return;
}



===== TestMmMapIoSpace_Exit @ 14000d770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestMmMapIoSpace_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e7c < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e7c = DAT_140032e7c + 1;
  }
  return;
}



===== _guard_check_icall @ 14000d800 =====

void _guard_check_icall(void)

{
  return;
}



===== TestObjTrkDelete @ 14000d80c =====

void TestObjTrkDelete(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (param_1 != (longlong *)0x0) {
    lVar1 = 0;
    lVar2 = 100;
    do {
      uVar3 = *param_1 - lVar1;
      if (uVar3 == (uVar3 / 10) * 10) {
        DifObjTrkRemoveItem(0x25,uVar3);
      }
      lVar1 = lVar1 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  return;
}



===== TestObjTrkDeleteCallback @ 14000d890 =====

void TestObjTrkDeleteCallback(void)

{
  TestObjTrkDelete((longlong *)&DAT_140059340);
  TestObjTrkDelete((longlong *)&DAT_140059320);
  TestObjTrkDelete((longlong *)&DAT_140059358);
  return;
}



===== TestObjTrkInitialize @ 14000d8d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TestObjTrkInitialize(int *param_1)

{
  ulonglong uVar1;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 0;
  if (*param_1 == 0) {
    if (DAT_140059330 == 0) {
      uVar1 = ExAllocatePool2(0x40,0x10,0x6142704e);
      DAT_140059330 = uVar1 & 0xfffffff000000000;
      DifUtilDbgPrint("Nonpage base address: 0x%p\n",DAT_140059330);
      _DAT_140059340 = DAT_140059330;
      _DAT_140059338 = DAT_140059330;
    }
    if (DAT_140059328 == 0) {
      uVar1 = ExAllocatePool2(0x100,0x10,0x61427050);
      DAT_140059328 = uVar1 & 0xfffffff000000000;
      DifUtilDbgPrint("Page base address: 0x%p\n",DAT_140059328);
      _DAT_140059320 = DAT_140059328;
      _DAT_14003af18 = DAT_140059328;
    }
    if (DAT_140059348 == 0) {
      DAT_140059348 = (ulonglong)&local_68 & 0xfffffff000000000;
      DifUtilDbgPrint("Stack base address: 0x%p\n");
      _DAT_140059358 = DAT_140059348;
      _DAT_140059350 = DAT_140059348;
    }
    ObjTrkTestInsertTimer = ExAllocateTimer(TestObjTrkInsertCallback,0,8);
    if (((ObjTrkTestInsertTimer != 0) &&
        (ObjTrkTestDeleteTimer = ExAllocateTimer(TestObjTrkDeleteCallback,0,8),
        ObjTrkTestDeleteTimer != 0)) &&
       (ObjTrkTestRangeRemoveTimer = ExAllocateTimer(TestObjTrkRangeRemoveCallback,0,8),
       ObjTrkTestRangeRemoveTimer != 0)) {
      local_48 = 0;
      local_38 = 0;
      local_28 = 0;
      local_68 = 0xfffffffffd050f80;
      local_40 = 0x80000000;
      local_30 = 0x80000000;
      local_20 = 0x80000000;
      ExSetTimer(ObjTrkTestInsertTimer,0xfffffffffd050f80,10000000,&local_48);
      ExSetTimer(ObjTrkTestDeleteTimer,local_68,10000000,&local_38);
      ExSetTimer(ObjTrkTestRangeRemoveTimer,local_68,20000000,&local_28);
      return;
    }
    if (DAT_140059330 != 0) {
      ExFreePoolWithTag(DAT_140059330,0);
      DAT_140059330 = 0;
    }
    if (DAT_140059328 != 0) {
      ExFreePoolWithTag(DAT_140059328,0);
      DAT_140059328 = 0;
    }
    DAT_140059348 = 0;
    if (ObjTrkTestInsertTimer != 0) {
      local_50 = 0;
      local_60 = 0;
      uStack_58 = 0;
      ExDeleteTimer(ObjTrkTestInsertTimer,0,0,&local_60);
      ObjTrkTestInsertTimer = 0;
    }
    if (ObjTrkTestDeleteTimer != 0) {
      local_50 = 0;
      local_60 = 0;
      uStack_58 = 0;
      ExDeleteTimer(ObjTrkTestDeleteTimer,0,0,&local_60);
      ObjTrkTestDeleteTimer = 0;
    }
    if (ObjTrkTestRangeRemoveTimer != 0) {
      local_50 = 0;
      local_60 = 0;
      uStack_58 = 0;
      ExDeleteTimer(ObjTrkTestRangeRemoveTimer,0,0,&local_60);
      ObjTrkTestRangeRemoveTimer = 0;
    }
  }
  return;
}



===== TestObjTrkInsert @ 14000dc14 =====

void TestObjTrkInsert(longlong *param_1)

{
  longlong lVar1;
  
  if (param_1 != (longlong *)0x0) {
    lVar1 = 100;
    do {
      DifObjTrkInsertItem(0x25,*param_1);
      *param_1 = *param_1 + 1;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
  }
  return;
}



===== TestObjTrkInsertCallback @ 14000dc60 =====

void TestObjTrkInsertCallback(void)

{
  TestObjTrkInsert((longlong *)&DAT_140059340);
  TestObjTrkInsert((longlong *)&DAT_140059320);
  TestObjTrkInsert((longlong *)&DAT_140059358);
  return;
}



===== TestObjTrkRangeDeleteMax @ 14000dc94 =====

void TestObjTrkRangeDeleteMax(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    DifObjTrkQeuryInvokeDeleteRange(*param_1 + -1,2,0);
    DifObjTrkQeuryInvokeDeleteRange(*param_1 + -1,2,0);
  }
  return;
}



===== TestObjTrkRangeDeleteMiddle @ 14000dce8 =====

void TestObjTrkRangeDeleteMiddle(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    DifObjTrkQeuryInvokeDeleteRange(*param_1 + -0x3c,0x14,0);
    DifObjTrkQeuryInvokeDeleteRange(*param_1 + -0x3c,0x14,0);
  }
  return;
}



===== TestObjTrkRangeDeleteMin @ 14000dd3c =====

void TestObjTrkRangeDeleteMin(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    DifObjTrkQeuryInvokeDeleteRange(*param_1,2,0);
    DifObjTrkQeuryInvokeDeleteRange(*param_1,2,0);
    *param_1 = *param_1 + 2;
  }
  return;
}



===== TestObjTrkRangeRemoveCallback @ 14000dd90 =====

void TestObjTrkRangeRemoveCallback(void)

{
  TestObjTrkRangeDeleteMiddle((longlong *)&DAT_140059340);
  TestObjTrkRangeDeleteMiddle((longlong *)&DAT_140059320);
  TestObjTrkRangeDeleteMiddle((longlong *)&DAT_140059358);
  TestObjTrkRangeDeleteMax((longlong *)&DAT_140059340);
  TestObjTrkRangeDeleteMax((longlong *)&DAT_140059320);
  TestObjTrkRangeDeleteMax((longlong *)&DAT_140059358);
  TestObjTrkRangeDeleteMin((longlong *)&DAT_140059338);
  TestObjTrkRangeDeleteMin((longlong *)&DAT_14003af18);
  TestObjTrkRangeDeleteMin((longlong *)&DAT_140059350);
  return;
}



===== TestPluginCleanup @ 14000de10 =====

void TestPluginCleanup(void)

{
  longlong lVar1;
  
  lVar1 = XdvRemovePluginObject(0x25);
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== TestPluginControl @ 14000de40 =====

undefined4
TestPluginControl(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  uVar4 = 0xc00000bb;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x18);
  if (uVar1 == 0x10044000) {
    if (7 < *(uint *)(*(longlong *)(param_1 + 0xb8) + 8)) {
      uVar3 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = PluginTestConfigData;
        uVar3 = 8;
        *(undefined1 *)(puVar2 + 1) = DAT_140059584;
        uVar4 = 0;
      }
      goto LAB_14000deaf;
    }
    uVar4 = 0xc000009a;
  }
  else {
    XdvUtilDbgPrint("VerifierExt!%s: invalid IOCTL received: 0x%0x\n","TestPluginControl",
                    (ulonglong)uVar1,param_4);
  }
  uVar3 = 0;
LAB_14000deaf:
  *(undefined8 *)(param_1 + 0x38) = uVar3;
  *(undefined4 *)(param_1 + 0x30) = uVar4;
  IofCompleteRequest(param_1,0);
  return uVar4;
}



===== TestZwCreateKey_Entry @ 14000dee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestZwCreateKey_Entry(undefined8 *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (DAT_140032e84 < 5) {
    uVar3 = (*XdvGetDriverName)(*param_1);
    DifUtilDbgPrint("ZwCreateKey is called by %S\n",uVar3);
    DAT_140032e84 = DAT_140032e84 + 1;
  }
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    iVar2 = CarReportDifPluginRuleViolation(0x25,2,*param_1);
    if (iVar2 < 0) {
      DifUtilDbgPrint("Test: Oops! Something went wrong.\n");
    }
  }
  return;
}



===== TestZwCreateKey_Exit @ 14000df70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TestZwCreateKey_Exit(undefined8 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = (*XdvGetDriverName)(*param_1);
  if (DAT_140032e78 < 5) {
    uVar2 = (*XdvIsBootDriver)(*param_1);
    uVar1 = (*XdvGetDriverSigningLevel)(*param_1);
    DifUtilDbgPrint("DriverName: %S, SigningLevel: %d, IsBootDriver: %d\n",uVar3,uVar1,uVar2);
    DAT_140032e78 = DAT_140032e78 + 1;
  }
  return;
}



===== DifDrvIsoPluginEntry @ 14000e000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DifDrvIsoPluginEntry(uint *param_1)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  DrvIsoMode = 0;
  local_68 = 0;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  local_58 = 0xc4;
  local_54 = 0x20;
  local_50 = 5;
  local_4c = 3;
  local_38 = 0x300000005;
  uStack_30 = 0x200000000;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0x200000000;
  uStack_40 = 0x200000000;
  local_28 = 0x200000000;
  uStack_20 = 0x300000005;
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 3) < 3) {
      DrvIsoMode = *param_1 & 3;
    }
    else {
      DifUtilDbgPrint("DrvIso: Invalid mode %d specified in configuration data.\n");
    }
  }
  uVar1 = 0;
  if (CarIsOnecheckEnabled != (code *)0x0) {
    uVar1 = (*CarIsOnecheckEnabled)();
  }
  DrvIsoIsOnecheckEnabled = uVar1;
  lVar3 = ExAllocatePool2(0x40,0x28,0x73737664);
  if (lVar3 == 0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)(lVar3 + 0x20) = 0x1002;
    *(code **)(lVar3 + 0x10) = DrvIsoControl;
    *(code **)(lVar3 + 0x18) = DrvIsoCleanup;
    XdvInsertPluginObject(0x20,lVar3);
    iVar2 = ExInitializeResourceLite(&DrvIsoDriverDataInitLock);
    if ((-1 < iVar2) && (iVar2 = ExInitializeResourceLite(&DrvIsoControlSetInitLock), -1 < iVar2)) {
      uStack_70 = 0;
      local_78 = 0x80;
      local_68 = 0;
      uStack_60 = 0;
      iVar2 = DifRegisterPlugin(&PTR_s_IoOpenDriverRegistryKey_14001d000,0x21,0x20,&local_78);
      if ((-1 < iVar2) && (iVar2 = CarRegisterRuleClassConfiguration(&local_58), -1 < iVar2)) {
        return iVar2;
      }
    }
  }
  DrvIsoCleanup();
  return iVar2;
}



===== DrvIsoCleanup @ 14000e1c0 =====

void DrvIsoCleanup(void)

{
  longlong lVar1;
  
  lVar1 = XdvRemovePluginObject(0x20);
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== DrvIsoControl @ 14000e1f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 DrvIsoControl(longlong param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  uVar4 = 0xc0000002;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0xb8) + 0x18);
  if (iVar1 == 0x10024000) {
    if (CarDeletePluginRuleViolations != (code *)0x0) {
      (*CarDeletePluginRuleViolations)(0x20);
    }
    DifUtilDbgPrint("DrvIso: Reset violation tracking\n");
LAB_14000e2cb:
    uVar4 = 0;
  }
  else {
    if (iVar1 != 0x10024190) {
      DifUtilDbgPrint("DrvIso: invalid IOCTL received: 0x%x\n");
      goto LAB_14000e2cd;
    }
    if (*(uint **)(param_1 + 0x18) == (uint *)0x0) {
      pcVar3 = "DrvIso: Set mode - null input buffer\n";
    }
    else if (*(int *)(*(longlong *)(param_1 + 0xb8) + 0x10) == 4) {
      uVar2 = **(uint **)(param_1 + 0x18);
      if (uVar2 < 3) {
        DifUtilDbgPrint("DrvIso: Set mode - updating mode from %d to %d\n",DrvIsoMode,uVar2);
        DrvIsoMode = uVar2;
        goto LAB_14000e2cb;
      }
      pcVar3 = "DrvIso: Set mode - invalid mode specified\n";
    }
    else {
      pcVar3 = "DrvIso: Set mode - invalid input size\n";
    }
    DifUtilDbgPrint(pcVar3);
    uVar4 = 0xc000000d;
  }
LAB_14000e2cd:
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = uVar4;
  IofCompleteRequest(param_1,0);
  return uVar4;
}



===== DrvIso_CleanupPerDriverData @ 14000e2fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DrvIso_CleanupPerDriverData(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = DifGetPluginPerDriverData(0x20,param_1);
  if (lVar1 == 0) {
    uVar2 = (*XdvGetDriverName)(param_1);
    DifUtilDbgPrint("Failed to get driver isolation per driver data for %S\n",uVar2);
  }
  else {
    DrvIso_FreePerDriverData(lVar1);
  }
  return;
}



===== DrvIso_DllInitialize_Exit @ 14000e360 =====

void DrvIso_DllInitialize_Exit(longlong *param_1)

{
  if (((int)param_1[3] < 0) && (*param_1 != 0)) {
    DrvIso_CleanupPerDriverData(*param_1);
  }
  return;
}



===== DrvIso_DllUnload_Exit @ 14000e390 =====

void DrvIso_DllUnload_Exit(longlong *param_1)

{
  if (*param_1 != 0) {
    DrvIso_CleanupPerDriverData(*param_1);
  }
  return;
}



===== DrvIso_DriverEntry_Exit @ 14000e3b0 =====

void DrvIso_DriverEntry_Exit(longlong *param_1)

{
  longlong lVar1;
  
  if ((int)param_1[3] < 0) {
    lVar1 = *param_1;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(param_1[2] + 0x18);
    }
    DrvIso_CleanupPerDriverData(lVar1);
  }
  return;
}



===== DrvIso_DriverUnload_Exit @ 14000e3e0 =====

void DrvIso_DriverUnload_Exit(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1[1] + 0x18);
  }
  DrvIso_CleanupPerDriverData(lVar1);
  return;
}



===== DrvIso_FreePerDriverData @ 14000e408 =====

void DrvIso_FreePerDriverData(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DrvIsoDriverDataInitLock,1);
  puVar6 = auStack_28;
  if (*(char *)(param_1 + 0x68) != '\0') {
    plVar1 = (longlong *)(param_1 + 0x70);
    while (plVar2 = (longlong *)*plVar1, puVar6 = auStack_28, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_20;
        break;
      }
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      DrvIso_FreeUnicodeRegistryPath((undefined4 *)(plVar2 + 2));
      ExFreePoolWithTag(plVar2,0x73737664);
    }
    *(undefined8 *)(puVar6 + -8) = 0x14000e493;
    iVar5 = ExDeleteResourceLite(param_1);
    if (iVar5 < 0) {
      *(undefined8 *)(puVar6 + -8) = 0x14000e4aa;
      DifUtilDbgPrint("DrvIso: Failed to delete lock for per driver data.\n");
    }
    *(undefined1 *)(param_1 + 0x68) = 0;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000e4c1;
  ExReleaseResourceLite(&DrvIsoDriverDataInitLock);
  *(undefined8 *)(puVar6 + -8) = 0x14000e4cd;
  KeLeaveCriticalRegion();
  return;
}



===== DrvIso_FreeViolationAllocatedAnsiErrorString @ 14000e4ec =====

void DrvIso_FreeViolationAllocatedAnsiErrorString(longlong param_1)

{
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 8),0x73737664);
      *(undefined8 *)(param_1 + 8) = 0;
    }
    ExFreePoolWithTag(param_1,0x73737664);
  }
  return;
}



===== DrvIso_GenerateViolationAllocatedAnsiErrorString @ 14000e53c =====

int DrvIso_GenerateViolationAllocatedAnsiErrorString
              (ushort *param_1,ushort *param_2,longlong param_3,longlong param_4,undefined8 *param_5
              )

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  void *_Dst;
  undefined8 *puVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBX;
  ulonglong local_48;
  void *local_40;
  ulonglong local_38;
  void *local_30;
  
  local_48 = 0;
  local_38 = 0;
  _Dst = (void *)0x0;
  local_40 = (void *)0x0;
  local_30 = (void *)0x0;
  if (param_1 == (ushort *)0x0) {
    return unaff_EBX;
  }
  if (param_2 == (ushort *)0x0) {
    return unaff_EBX;
  }
  if (param_3 == 0) {
    return unaff_EBX;
  }
  if (param_5 == (undefined8 *)0x0) {
    return unaff_EBX;
  }
  *param_5 = 0;
  iVar3 = RtlUnicodeStringToAnsiString(&local_48,param_3,1);
  if (-1 < iVar3) {
    bVar2 = false;
    if (param_4 != 0) {
      iVar3 = RtlUnicodeStringToAnsiString(&local_38,param_4,1);
      bVar2 = false;
      if (-1 < iVar3) {
        bVar2 = true;
      }
    }
    uVar5 = *param_1 + 1 + (uint)(ushort)local_48 + (uint)*param_2;
    if (((*param_1 <= uVar5) && (*param_2 <= uVar5)) && ((ushort)local_48 <= uVar5)) {
      uVar6 = uVar5;
      if (bVar2) {
        uVar6 = uVar5 + (ushort)local_38 + 1;
        if (uVar6 < uVar5) goto LAB_14000e725;
      }
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar6,0x73737664);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,(ulonglong)uVar6);
        memcpy(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
        uVar1 = *param_1;
        memcpy((void *)((longlong)_Dst + (ulonglong)uVar1),*(void **)(param_2 + 4),
               (ulonglong)*param_2);
        uVar5 = (uint)*param_2 + (uint)uVar1;
        memcpy((void *)((ulonglong)uVar5 + (longlong)_Dst),local_40,local_48 & 0xffff);
        uVar5 = uVar5 + (ushort)local_48;
        if (bVar2) {
          *(undefined1 *)((ulonglong)uVar5 + (longlong)_Dst) = 0x5c;
          memcpy((void *)((ulonglong)(uVar5 + 1) + (longlong)_Dst),local_30,local_38 & 0xffff);
        }
        puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x73737664);
        if (puVar4 != (undefined8 *)0x0) {
          *puVar4 = 0;
          puVar4[1] = 0;
          RtlInitAnsiString(puVar4,_Dst);
          _Dst = (void *)0x0;
          *param_5 = puVar4;
        }
      }
    }
  }
LAB_14000e725:
  if (local_40 != (void *)0x0) {
    RtlFreeAnsiString(&local_48);
  }
  if (local_30 != (void *)0x0) {
    RtlFreeAnsiString(&local_38);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x73737664);
  }
  return unaff_EBX;
}



===== DrvIso_InitializePerDriverData @ 14000e79c =====

int DrvIso_InitializePerDriverData(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(char *)(param_1 + 0x68) == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DrvIsoDriverDataInitLock,1);
    if (*(char *)(param_1 + 0x68) == '\0') {
      iVar2 = ExInitializeResourceLite(param_1);
      if (-1 < iVar2) {
        lVar1 = param_1 + 0x70;
        *(undefined1 *)(param_1 + 0x68) = 1;
        *(longlong *)(param_1 + 0x78) = lVar1;
        *(longlong *)lVar1 = lVar1;
      }
    }
    ExReleaseResourceLite(&DrvIsoDriverDataInitLock);
    KeLeaveCriticalRegion();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== DrvIso_ReportViolation @ 14000e834 =====

undefined4 DrvIso_ReportViolation(undefined4 param_1,char *param_2,undefined8 param_3,char param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *local_78 [3];
  char *local_60;
  int local_30;
  uint local_2c;
  
  memset(local_78,0,0x58);
  uVar3 = 0;
  if ((param_4 == '\0') || (DrvIsoIsOnecheckEnabled == '\0')) {
    iVar4 = 0;
    cVar1 = *param_2;
    pcVar5 = param_2;
    while (cVar1 != '\0') {
      iVar2 = toupper((int)cVar1);
      iVar4 = iVar4 * 0x1003f + iVar2;
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar5;
    }
    CarInitializeRuleViolationDetails(local_78);
    local_2c = -(uint)(param_4 != '\0') & 1000000;
    local_78[0] = param_2;
    local_60 = param_2;
    local_30 = iVar4;
    uVar3 = CarReportDifPluginRuleViolation(0x20,param_1,param_3,local_78);
  }
  return uVar3;
}



===== DrvIso_AddParametersPath @ 14000e920 =====

int DrvIso_AddParametersPath(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  ulonglong uVar6;
  longlong *plVar7;
  char *pcVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  iVar5 = DrvIso_InitializePerDriverData(param_1);
  if (iVar5 < 0) {
    pcVar8 = "Failed to initialize per driver data. Status = 0x%08x\n";
  }
  else {
    uVar6 = DrvIso_GetUnicodeRegistryPathFromHandle(param_2,(longlong)&local_18);
    iVar5 = (int)uVar6;
    if (-1 < iVar5) {
      bVar3 = true;
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(param_1,1);
      puVar10 = auStack_38;
      puVar11 = auStack_38;
      puVar1 = (undefined8 *)(param_1 + 0x70);
      for (puVar9 = (undefined8 *)*puVar1; puVar9 != puVar1; puVar9 = (undefined8 *)*puVar9) {
        cVar4 = RtlEqualUnicodeString(puVar9 + 2,&local_18,1);
        if (cVar4 != '\0') goto LAB_14000ea26;
      }
      plVar7 = (longlong *)ExAllocatePool2(0x40,0x20,0x73737664);
      if (plVar7 == (longlong *)0x0) {
        iVar5 = -0x3fffffe9;
        puVar11 = auStack_38;
      }
      else {
        *(undefined4 *)(plVar7 + 2) = (undefined4)local_18;
        *(undefined4 *)((longlong)plVar7 + 0x14) = local_18._4_4_;
        *(undefined4 *)(plVar7 + 3) = (undefined4)uStack_10;
        *(undefined4 *)((longlong)plVar7 + 0x1c) = uStack_10._4_4_;
        puVar9 = *(undefined8 **)(param_1 + 0x78);
        if ((undefined8 *)*puVar9 != puVar1) {
          puVar9 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar2)();
          puVar10 = auStack_30;
        }
        *plVar7 = (longlong)puVar1;
        bVar3 = false;
        plVar7[1] = (longlong)puVar9;
        *puVar9 = plVar7;
        *(longlong **)(param_1 + 0x78) = plVar7;
        puVar11 = puVar10;
      }
LAB_14000ea26:
      *(undefined8 *)(puVar11 + -8) = 0x14000ea30;
      ExReleaseResourceLite(param_1);
      *(undefined8 *)(puVar11 + -8) = 0x14000ea3c;
      KeLeaveCriticalRegion();
      if (bVar3) {
        *(undefined8 *)(puVar11 + -8) = 0x14000ea50;
        DrvIso_FreeUnicodeRegistryPath((undefined4 *)(puVar11 + 0x20));
        return iVar5;
      }
      return iVar5;
    }
    pcVar8 = "Failed to get key path from handle. Status = 0x%08x\n";
  }
  DifUtilDbgPrint(pcVar8,iVar5);
  return iVar5;
}



===== DrvIso_EnforceMutableHandleTag @ 14000ea74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DrvIso_EnforceMutableHandleTag
                    (longlong *param_1,longlong param_2,undefined8 param_3,char param_4,
                    undefined8 param_5)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int extraout_EAX;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined2 *puVar8;
  wchar_t *pwVar9;
  ulonglong uVar10;
  char *pcVar11;
  ulonglong *puVar12;
  longlong lVar13;
  int local_res8 [2];
  longlong local_res10;
  uint local_78 [2];
  longlong local_70;
  ulonglong local_68;
  undefined2 *puStack_60;
  ulonglong local_58 [2];
  ushort local_48 [8];
  
  local_70 = 0;
  local_78[0] = 0;
  local_res8[0] = 0;
  lVar13 = 0;
  bVar1 = false;
  puVar8 = (undefined2 *)0x0;
  local_68 = 0;
  puStack_60 = (undefined2 *)0x0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_res10 = param_2;
  if ((param_1 == (longlong *)0x0) || (*param_1 == 0)) {
    uVar10 = 0xc000000d;
    goto LAB_14000ee25;
  }
  uVar3 = ZwQueryKey(*param_1,7,local_78,4,local_res8);
  if ((int)uVar3 < 0) {
    return (ulonglong)uVar3;
  }
  if (local_res8[0] != 4) {
    return 0xc0000001;
  }
  if ((local_78[0] & 0x1000) != 0) {
    return (ulonglong)uVar3;
  }
  uVar5 = DrvIso_GetUnicodeRegistryPathFromHandle(param_1,(longlong)local_58);
  uVar10 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    RtlInitUnicodeString(local_58,L"<unknown>");
LAB_14000ebad:
    lVar6 = local_res10;
    if (local_res10 == 0) goto LAB_14000ecce;
    puVar8 = (undefined2 *)ExAllocatePool2(0x40,0x400,0x73737664);
    if (puVar8 == (undefined2 *)0x0) {
      uVar10 = 0xc0000017;
    }
    else {
      *puVar8 = 0;
      local_68 = CONCAT44(local_68._4_4_,0x4000000);
      puStack_60 = puVar8;
      iVar4 = RtlAppendUnicodeStringToString(&local_68,local_58);
      if (((iVar4 < 0) || (iVar4 = RtlAppendUnicodeToString(&local_68,L"\\"), iVar4 < 0)) ||
         (iVar4 = RtlAppendUnicodeStringToString(&local_68,lVar6), iVar4 < 0)) {
        *puVar8 = 0;
        local_68 = local_68 & 0xffffffffffff0000;
LAB_14000ecce:
        if ((ushort)local_68 < 2) goto LAB_14000ec74;
        pwVar9 = (wchar_t *)(*XdvGetDriverName)(param_3);
        puVar12 = &local_68;
      }
      else {
        if (1 < (local_68 >> 0x10 & 0xffff) - (local_68 & 0xffff)) {
          puVar8[local_68 >> 1 & 0x7fff] = 0;
          goto LAB_14000ecce;
        }
        *puVar8 = 0;
        local_68 = local_68 & 0xffffffffffff0000;
LAB_14000ec74:
        pwVar9 = (wchar_t *)(*XdvGetDriverName)(param_3);
        puVar12 = local_58;
      }
      cVar2 = DrvIso_OnExceptionList(pwVar9,0,(ushort *)puVar12,param_4 == '\0');
      if (cVar2 == '\0') {
        if ((ushort)local_68 < 2) {
          pwVar9 = (wchar_t *)(*XdvGetDriverName)(param_3);
          puVar12 = local_58;
        }
        else {
          pwVar9 = (wchar_t *)(*XdvGetDriverName)(param_3);
          puVar12 = &local_68;
        }
        uVar10 = DrvIso_OnModeExceptionList(pwVar9,0,(ushort *)puVar12,param_4 == '\0');
        lVar13 = local_res10;
        pcVar11 = "DRIVER_ISOLATION_WARNING";
        if ((char)uVar10 == '\0') {
          pcVar11 = "DRIVER_ISOLATION_VIOLATION";
        }
        uVar7 = (*XdvGetDriverName)(param_3);
        if (lVar13 == 0) {
          DifUtilDbgPrint("%s: %S: %s%s\'%wZ\'\n",pcVar11,uVar7,
                          "Registry operations should only use key handles returned from WDF or WDM APIs."
                          ,param_5,local_58);
        }
        else {
          DifUtilDbgPrint("%s: %S: %s%s\'%wZ\\%wZ\'\n");
        }
        RtlInitAnsiString(local_48,param_5);
        DrvIso_GenerateViolationAllocatedAnsiErrorString
                  ((ushort *)&ERROR_STRING_REGISTRY_OP,local_48,(longlong)local_58,lVar13,&local_70)
        ;
        lVar13 = local_70;
        if (extraout_EAX < 0) {
          pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs."
          ;
        }
        else {
          pcVar11 = *(char **)(local_70 + 8);
        }
        DrvIso_ReportViolation(1,pcVar11,param_3,(char)uVar10);
      }
      uVar10 = 0;
      if (puVar8 != (undefined2 *)0x0) {
        ExFreePoolWithTag(puVar8,0x73737664);
      }
    }
    if (!bVar1) goto LAB_14000ee25;
  }
  else {
    bVar1 = true;
    if (param_4 == '\0') goto LAB_14000ebad;
    lVar6 = DifGetPluginPerDriverData(0x20,param_3);
    if (lVar6 == 0) {
      uVar7 = (*XdvGetDriverName)(param_3);
      DifUtilDbgPrint("Failed to get driver isolation per driver data for %S\n",uVar7);
      goto LAB_14000ebad;
    }
    cVar2 = DrvIso_IsValidParametersPath(lVar6,local_58);
    if (cVar2 == '\0') goto LAB_14000ebad;
  }
  DrvIso_FreeUnicodeRegistryPath((undefined4 *)local_58);
LAB_14000ee25:
  if (lVar13 != 0) {
    DrvIso_FreeViolationAllocatedAnsiErrorString(lVar13);
  }
  return uVar10;
}



===== DrvIso_FreeUnicodeRegistryPath @ 14000ee58 =====

void DrvIso_FreeUnicodeRegistryPath(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (*(longlong *)(param_1 + 2) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 2),0x73737664);
    *(undefined8 *)(param_1 + 2) = 0;
    *param_1 = 0;
  }
  return;
}



===== DrvIso_GetUnicodeRegistryPathFromHandle @ 14000eea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DrvIso_GetUnicodeRegistryPathFromHandle(longlong *param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint *_Dst;
  void *_Dst_00;
  undefined1 auStack_68 [32];
  uint *local_48;
  uint local_38 [2];
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_30 = 0;
  local_38[0] = 0;
  if ((((param_1 == (longlong *)0x0) || (*param_1 == 0)) || (param_2 == 0)) ||
     (*(longlong *)(param_2 + 8) != 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    local_48 = local_38;
    uVar2 = ZwQueryKey(*param_1,3,&local_30);
    if ((int)uVar2 < 0) {
      if ((int)uVar2 == -0x7ffffffb) {
        _Dst = (uint *)ExAllocatePool2(0x40,local_38[0],0x73737664);
        if (_Dst == (uint *)0x0) {
          uVar2 = 0xc0000017;
        }
        else {
          memset(_Dst,0,(ulonglong)local_38[0]);
          local_48 = local_38;
          uVar1 = ZwQueryKey(*param_1,3,_Dst,local_38[0]);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = *_Dst + 2;
            if (uVar1 < *_Dst) {
              uVar2 = 0x80000005;
            }
            else {
              _Dst_00 = (void *)ExAllocatePool2(0x40,uVar1,0x73737664);
              if (_Dst_00 == (void *)0x0) {
                uVar2 = 0xc0000017;
              }
              else {
                memset(_Dst_00,0,(ulonglong)uVar1);
                memcpy(_Dst_00,_Dst + 1,(ulonglong)*_Dst);
                RtlInitUnicodeString(param_2,_Dst_00);
                uVar2 = 0;
              }
            }
          }
          ExFreePoolWithTag(_Dst,0x73737664);
        }
      }
    }
    else {
      uVar2 = 0xc000090b;
    }
  }
  return uVar2;
}



===== DrvIso_IoOpenDriverRegistryKey_Exit @ 14000f050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DrvIso_IoOpenDriverRegistryKey_Exit(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (((-1 < *(int *)(param_1 + 5)) && (*(int *)(param_1 + 3) == 0)) && (param_1[1] != 0)) {
    lVar2 = DifGetPluginPerDriverData(0x20,*param_1);
    if (lVar2 == 0) {
      uVar3 = (*XdvGetDriverName)(*param_1);
      DifUtilDbgPrint("Failed to get driver isolation per driver data for %S\n",uVar3);
    }
    else {
      iVar1 = DrvIso_AddParametersPath(lVar2,(longlong *)param_1[1]);
      if (iVar1 < 0) {
        DifUtilDbgPrint("Failed to store parameters handle key path. Status = 0x%08x\n",iVar1);
      }
    }
  }
  return;
}



===== DrvIso_IsValidParametersPath @ 14000f0e0 =====

undefined1 DrvIso_IsValidParametersPath(longlong param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  iVar2 = DrvIso_InitializePerDriverData(param_1);
  if (-1 < iVar2) {
    KeEnterCriticalRegion();
    ExAcquireResourceSharedLite(param_1,1);
    for (puVar3 = *(undefined8 **)(param_1 + 0x70); puVar3 != (undefined8 *)(param_1 + 0x70);
        puVar3 = (undefined8 *)*puVar3) {
      cVar1 = RtlPrefixUnicodeString(puVar3 + 2,param_2,1);
      if (cVar1 != '\0') {
        uVar4 = 1;
        break;
      }
    }
    ExReleaseResourceLite(param_1);
    KeLeaveCriticalRegion();
  }
  return uVar4;
}



===== DrvIso_Key_Exit_Verification @ 14000f198 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DrvIso_Key_Exit_Verification
                    (longlong param_1,undefined8 param_2,char param_3,char *param_4)

{
  ushort *puVar1;
  longlong lVar2;
  char cVar3;
  int extraout_EAX;
  wchar_t *pwVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  ulonglong uVar8;
  char cVar9;
  undefined8 uVar10;
  char *pcVar11;
  longlong local_res8;
  ushort local_48 [8];
  
  uVar8 = 0;
  pcVar11 = "Registry operations should not use absolute paths.";
  local_res8 = 0;
  cVar9 = '\0';
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  if (param_1 == 0) {
    uVar8 = 0xc000000d;
  }
  else if (*(longlong *)(param_1 + 8) == 0) {
    puVar1 = *(ushort **)(param_1 + 0x10);
    if (puVar1 != (ushort *)0x0) {
      pwVar4 = (wchar_t *)(*XdvGetDriverName)(param_2);
      cVar3 = DrvIso_OnExceptionList(pwVar4,0,puVar1,param_3 == '\0');
      if (cVar3 != '\0') {
        return 0;
      }
    }
    puVar1 = *(ushort **)(param_1 + 0x10);
    uVar10 = 0;
    if (puVar1 != (ushort *)0x0) {
      pwVar4 = (wchar_t *)(*XdvGetDriverName)(param_2);
      uVar5 = DrvIso_OnModeExceptionList(pwVar4,0,puVar1,param_3 == '\0');
      uVar10 = *(undefined8 *)(param_1 + 0x10);
      cVar9 = (char)uVar5;
    }
    uVar6 = (*XdvGetDriverName)(param_2);
    pcVar7 = "DRIVER_ISOLATION_WARNING";
    if (cVar9 == '\0') {
      pcVar7 = "DRIVER_ISOLATION_VIOLATION";
    }
    DifUtilDbgPrint("%s: %S: %s%s\'%wZ\'\n",pcVar7,uVar6,
                    "Registry operations should not use absolute paths.",param_4,uVar10);
    if (param_4 == (char *)0x0) {
      param_4 = "";
    }
    RtlInitAnsiString(local_48,param_4);
    DrvIso_GenerateViolationAllocatedAnsiErrorString
              ((ushort *)&ERROR_STRING_ABSOLUTE_REG_PATH,local_48,*(longlong *)(param_1 + 0x10),0,
               &local_res8);
    lVar2 = local_res8;
    if (-1 < extraout_EAX) {
      pcVar11 = *(char **)(local_res8 + 8);
    }
    DrvIso_ReportViolation(1,pcVar11,param_2,cVar9);
    if (lVar2 != 0) {
      DrvIso_FreeViolationAllocatedAnsiErrorString(lVar2);
    }
  }
  else {
    local_res8 = *(longlong *)(param_1 + 8);
    uVar8 = DrvIso_EnforceMutableHandleTag
                      (&local_res8,*(longlong *)(param_1 + 0x10),param_2,param_3,param_4);
    uVar8 = uVar8 & 0xffffffff;
  }
  return uVar8;
}



===== DrvIso_RtlCheckRegistryKey_Exit @ 14000f370 =====

void DrvIso_RtlCheckRegistryKey_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_RtlRegistryApi_Access
              (*(uint *)(param_1 + 2),(wchar_t *)param_1[1],*param_1,'\x01',
               " Detected validation of unisolated registry key ");
  }
  return;
}



===== DrvIso_RtlCreateRegistryKey_Exit @ 14000f3b0 =====

void DrvIso_RtlCreateRegistryKey_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_RtlRegistryApi_Access
              (*(uint *)(param_1 + 2),(wchar_t *)param_1[1],*param_1,'\0',
               " Detected creation of unisolated registry key ");
  }
  return;
}



===== DrvIso_RtlDeleteRegistryValue_Exit @ 14000f3f0 =====

void DrvIso_RtlDeleteRegistryValue_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_RtlRegistryApi_Access
              (*(uint *)(param_1 + 3),(wchar_t *)param_1[2],*param_1,'\0',
               " Detected deletion of value under unisolated registry key ");
  }
  return;
}



===== DrvIso_RtlQueryRegistryValues_Exit @ 14000f430 =====

void DrvIso_RtlQueryRegistryValues_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_RtlRegistryApi_Access
              (*(uint *)(param_1 + 5),(wchar_t *)param_1[4],*param_1,'\x01',
               " Detected querying of value(s) under unisolated registry key ");
  }
  return;
}



===== DrvIso_RtlRegistryApi_Access @ 14000f464 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DrvIso_RtlRegistryApi_Access
                    (uint param_1,wchar_t *param_2,undefined8 param_3,char param_4,char *param_5)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int extraout_EAX;
  ulonglong uVar5;
  undefined2 *puVar6;
  wchar_t *pwVar7;
  undefined8 uVar8;
  char *pcVar9;
  ushort *puVar10;
  char *pcVar11;
  undefined1 auStackY_2f8 [32];
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  ulonglong local_2b8;
  undefined2 *puStack_2b0;
  wchar_t *local_2a8;
  undefined8 local_2a0;
  undefined1 *puStack_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined1 local_258 [512];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_2f8;
  local_2a8 = (wchar_t *)0x0;
  local_2b8 = 0;
  puStack_2b0 = (undefined2 *)0x0;
  local_2c8 = 0;
  uStack_2c0 = 0;
  local_280 = 0;
  uStack_278 = 0;
  local_2a0 = 0;
  puStack_298 = (undefined1 *)0x0;
  local_290 = 0;
  uStack_288 = 0;
  local_270 = 0;
  uStack_268 = 0;
  if ((param_1 >> 0x1e & 1) != 0) {
    local_2a8 = param_2;
    uVar5 = DrvIso_EnforceMutableHandleTag((longlong *)&local_2a8,0,param_3,param_4,param_5);
    return uVar5;
  }
  uVar1 = param_1 & 0x7fffffff;
  if (-1 < (int)param_1) {
    uVar1 = param_1;
  }
  if (5 < uVar1) {
    return 0xc000000d;
  }
  if (uVar1 == 0) {
    if (param_2 == (wchar_t *)0x0) {
      return 0xc000000d;
    }
    pcVar11 = "Registry operations should not use absolute paths.";
    puVar10 = (ushort *)&ERROR_STRING_ABSOLUTE_REG_PATH;
    RtlInitUnicodeString(&local_2c8);
    pcVar9 = "relative to RTL_REGISTRY_ABSOLUTE: ";
  }
  else if (uVar1 == 1) {
    pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs.";
    puVar10 = (ushort *)&ERROR_STRING_REGISTRY_OP;
    if (param_2 == (wchar_t *)0x0) {
      param_2 = L"";
    }
    RtlInitUnicodeString(&local_2c8,param_2);
    pcVar9 = "relative to RTL_REGISTRY_SERVICES: ";
  }
  else if (uVar1 == 2) {
    pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs.";
    puVar10 = (ushort *)&ERROR_STRING_REGISTRY_OP;
    if (param_2 == (wchar_t *)0x0) {
      param_2 = L"";
    }
    RtlInitUnicodeString(&local_2c8,param_2);
    pcVar9 = "relative to RTL_REGISTRY_CONTROL: ";
  }
  else if (uVar1 == 3) {
    pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs.";
    puVar10 = (ushort *)&ERROR_STRING_REGISTRY_OP;
    if (param_2 == (wchar_t *)0x0) {
      param_2 = L"";
    }
    RtlInitUnicodeString(&local_2c8,param_2);
    pcVar9 = "relative to RTL_REGISTRY_WINDOWS_NT: ";
  }
  else if (uVar1 == 4) {
    pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs.";
    puVar10 = (ushort *)&ERROR_STRING_REGISTRY_OP;
    if (param_2 == (wchar_t *)0x0) {
      param_2 = L"";
    }
    RtlInitUnicodeString(&local_2c8,param_2);
    pcVar9 = "relative to RTL_REGISTRY_DEVICEMAP: ";
  }
  else {
    if (uVar1 != 5) {
      return 0xc000000d;
    }
    pcVar11 = "Registry operations should only use key handles returned from WDF or WDM APIs.";
    puVar10 = (ushort *)&ERROR_STRING_REGISTRY_OP;
    if (param_2 == (wchar_t *)0x0) {
      param_2 = L"";
    }
    RtlInitUnicodeString(&local_2c8,param_2);
    pcVar9 = "relative to RTL_REGISTRY_USER: ";
  }
  RtlInitAnsiString(&local_290,pcVar9);
  local_2a0 = CONCAT44(local_2a0._4_4_,0x2000000);
  local_258[0] = 0;
  puStack_298 = local_258;
  if (param_5 == (char *)0x0) {
    param_5 = " Attempt to modify key ";
  }
  RtlInitAnsiString(&local_280,param_5);
  iVar4 = RtlAppendStringToString(&local_2a0,&local_280);
  if ((iVar4 < 0) || (iVar4 = RtlAppendStringToString(&local_2a0,&local_290), iVar4 < 0)) {
    RtlInitAnsiString(&local_2a0," Attempt to modify key ");
  }
  puVar6 = (undefined2 *)ExAllocatePool2(0x40,0x400,0x73737664);
  if (puVar6 == (undefined2 *)0x0) {
    return 0xc0000017;
  }
  *puVar6 = 0;
  local_2b8 = CONCAT44(local_2b8._4_4_,0x4000000);
  puStack_2b0 = puVar6;
  if ((&PTR_u__14001d4c8)[uVar1] != (undefined *)0x0) {
    RtlInitUnicodeString(&local_270);
    iVar4 = RtlAppendUnicodeStringToString(&local_2b8);
    if ((iVar4 < 0) || (iVar4 = RtlAppendUnicodeStringToString(&local_2b8), iVar4 < 0)) {
      *puVar6 = 0;
      uVar3 = 0;
      local_2b8 = local_2b8 & 0xffffffffffff0000;
    }
    else {
      if ((local_2b8 >> 0x10 & 0xffff) - (local_2b8 & 0xffff) < 2) {
        *puVar6 = 0;
        local_2b8 = local_2b8 & 0xffffffffffff0000;
        goto LAB_14000f811;
      }
      puVar6[(ushort)local_2b8 >> 1] = 0;
      uVar3 = (ushort)local_2b8;
    }
    if (uVar3 != 0) {
      pwVar7 = (wchar_t *)(*XdvGetDriverName)(param_3);
      cVar2 = DrvIso_OnExceptionList(pwVar7,0,(ushort *)&local_2b8,param_4 == '\0');
      if (cVar2 != '\0') goto LAB_14000f8da;
    }
  }
LAB_14000f811:
  pwVar7 = (wchar_t *)(*XdvGetDriverName)(param_3);
  uVar5 = DrvIso_OnModeExceptionList(pwVar7,0,(ushort *)&local_2b8,param_4 == '\0');
  uVar8 = (*XdvGetDriverName)(param_3);
  pcVar9 = "DRIVER_ISOLATION_WARNING";
  if ((char)uVar5 == '\0') {
    pcVar9 = "DRIVER_ISOLATION_VIOLATION";
  }
  DifUtilDbgPrint("%s: %S: %s%Z\'%wZ\'\n",pcVar9,uVar8);
  DrvIso_GenerateViolationAllocatedAnsiErrorString
            (puVar10,(ushort *)&local_2a0,(longlong)&local_2c8,0,&local_2a8);
  pwVar7 = local_2a8;
  if (-1 < extraout_EAX) {
    pcVar11 = *(char **)(local_2a8 + 4);
  }
  DrvIso_ReportViolation(1,pcVar11,param_3,(char)uVar5);
  if (pwVar7 != (wchar_t *)0x0) {
    DrvIso_FreeViolationAllocatedAnsiErrorString((longlong)pwVar7);
  }
LAB_14000f8da:
  ExFreePoolWithTag(puVar6,0x73737664);
  return 0;
}



===== DrvIso_RtlWriteRegistryValue_Exit @ 14000f920 =====

void DrvIso_RtlWriteRegistryValue_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_RtlRegistryApi_Access
              (*(uint *)(param_1 + 6),(wchar_t *)param_1[5],*param_1,'\0',
               " Detected setting of value under unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwCreateKeyTransacted_Exit @ 14000f960 =====

void DrvIso_ZwCreateKeyTransacted_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_Key_Exit_Verification
              (param_1[6],*param_1,'\0'," Detected creation of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwCreateKey_Exit @ 14000f990 =====

void DrvIso_ZwCreateKey_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_Key_Exit_Verification
              (param_1[5],*param_1,'\0'," Detected creation of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwDeleteKey_Entry @ 14000f9c0 =====

void DrvIso_ZwDeleteKey_Entry(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[1];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\0'," Detected deletion of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwDeleteValueKey_Exit @ 14000fa00 =====

void DrvIso_ZwDeleteValueKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[2];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\0',
               " Detected deletion of value under unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwOpenKeyTransacted_Exit @ 14000fa40 =====

void DrvIso_ZwOpenKeyTransacted_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_Key_Exit_Verification
              (param_1[2],*param_1,'\x01'," Detected opening of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwOpenKeyTransactedEx_Exit @ 14000fa70 =====

void DrvIso_ZwOpenKeyTransactedEx_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_Key_Exit_Verification
              (param_1[3],*param_1,'\x01'," Detected opening of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwOpenKey_Exit @ 14000faa0 =====

void DrvIso_ZwOpenKey_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_Key_Exit_Verification
              (param_1[1],*param_1,'\x01'," Detected opening of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwQueryKey_Exit @ 14000fad0 =====

void DrvIso_ZwQueryKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[5];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\x01'," Detected querying of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwQueryValueKey_Exit @ 14000fb10 =====

void DrvIso_ZwQueryValueKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[6];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\x01',
               " Detected querying of value under unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwRenameKey_Exit @ 14000fb50 =====

void DrvIso_ZwRenameKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[2];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\0'," Detected rename of unisolated registry key ");
  }
  return;
}



===== DrvIso_ZwSetInformationKey_Exit @ 14000fb90 =====

void DrvIso_ZwSetInformationKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if ((param_1 != (undefined8 *)0x0) && (*(int *)(param_1 + 3) != 5)) {
    local_res8[0] = param_1[4];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\0'," Detected information change of unisolated registry key "
              );
  }
  return;
}



===== DrvIso_ZwSetValueKey_Exit @ 14000fbe0 =====

void DrvIso_ZwSetValueKey_Exit(undefined8 *param_1)

{
  longlong local_res8 [4];
  
  if (param_1 != (undefined8 *)0x0) {
    local_res8[0] = param_1[5];
    DrvIso_EnforceMutableHandleTag
              (local_res8,0,*param_1,'\0',
               " Detected setting of value under unisolated registry key ");
  }
  return;
}



===== DrvIso_File_Exit_Verification @ 14000fc1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DrvIso_File_Exit_Verification
              (longlong param_1,undefined8 param_2,char param_3,longlong param_4,char *param_5)

{
  longlong lVar1;
  char cVar2;
  int extraout_EAX;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  longlong local_res8;
  longlong local_48;
  ushort local_40 [4];
  longlong lStack_38;
  ushort local_30 [12];
  
  local_48 = 0;
  local_res8 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  lStack_38 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  if (param_1 == 0) {
    iVar3 = -0x3ffffff3;
    goto LAB_14000fe7d;
  }
  if (*(longlong *)(param_1 + 8) != 0) goto LAB_14000fe65;
  if (*(ushort **)(param_1 + 0x10) == (ushort *)0x0) {
    iVar3 = 0;
    goto LAB_14000fe7d;
  }
  cVar2 = GetRelativePath(*(ushort **)(param_1 + 0x10),(ushort *)&DAT_14001d518,(short *)0x0);
  if (cVar2 == '\0') {
    cVar2 = GetRelativePath(*(ushort **)(param_1 + 0x10),(ushort *)&DAT_14001d528,(short *)0x0);
    if (cVar2 != '\0') {
      if (param_3 == '\0') {
        pcVar6 = "Files in the driver store should not be modified.";
        uVar5 = (*XdvGetDriverName)(param_2);
        DifUtilDbgPrint("%s: %S: %s%s\'%wZ\'\n","DRIVER_ISOLATION_VIOLATION",uVar5,
                        "Files in the driver store should not be modified.",param_5,
                        *(undefined8 *)(param_1 + 0x10));
        if (param_5 == (char *)0x0) {
          param_5 = "";
        }
        RtlInitAnsiString(local_30,param_5);
        DrvIso_GenerateViolationAllocatedAnsiErrorString
                  ((ushort *)&ERROR_STRING_DRIVERSTORE_PATH,local_30,*(longlong *)(param_1 + 0x10),0
                   ,&local_48);
        lVar1 = local_48;
        if (-1 < extraout_EAX) {
          pcVar6 = *(char **)(local_48 + 8);
        }
        DrvIso_ReportViolation(2,pcVar6,param_2,'\0');
        if (lVar1 != 0) {
          DrvIso_FreeViolationAllocatedAnsiErrorString(lVar1);
        }
      }
      goto LAB_14000fe65;
    }
    if (param_4 == 0) {
LAB_14000fe16:
      uVar5 = DrvIso_NormalizeFilePath(*(ushort **)(param_1 + 0x10),local_40);
      if (-1 < (int)uVar5) {
        uVar4 = DrvIso_ValidateFilePath
                          (local_40,*(ushort **)(param_1 + 0x10),param_2,param_3,param_5);
        if ((int)uVar4 < 0) {
          DifUtilDbgPrint("Failed to validate file path \'%wZ\'. Status = 0x%08x\n",
                          local_res8 + 0x58,uVar4 & 0xffffffff);
        }
      }
      goto LAB_14000fe65;
    }
    iVar3 = ObReferenceObjectByHandle
                      (param_4,0x120089,*(undefined8 *)IoFileObjectType_exref,0,&local_res8,0);
    if (iVar3 < 0) goto LAB_14000fe16;
    if ((*(longlong *)(local_res8 + 0x10) == 0) || (*(ushort *)(local_res8 + 0x58) == 0))
    goto LAB_14000fe65;
    uVar4 = DrvIso_ValidateFilePath
                      ((ushort *)(local_res8 + 0x58),*(ushort **)(param_1 + 0x10),param_2,param_3,
                       param_5);
    iVar3 = (int)uVar4;
    if (iVar3 < 0) {
      DifUtilDbgPrint("Failed to validate file path \'%wZ\'. Status = 0x%08x\n",local_res8 + 0x58,
                      uVar4 & 0xffffffff);
    }
  }
  else {
LAB_14000fe65:
    iVar3 = 0;
  }
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
LAB_14000fe7d:
  if (lStack_38 != 0) {
    ExFreePoolWithTag(lStack_38,0x73737664);
  }
  return iVar3;
}



===== DrvIso_IoCreateFileSpecifyDeviceObjectHint_Exit @ 14000fec0 =====

void DrvIso_IoCreateFileSpecifyDeviceObjectHint_Exit(undefined8 *param_1)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  
  lVar3 = 0;
  pcVar1 = " Detected opening of file ";
  cVar2 = '\x01';
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (-1 < *(int *)(param_1 + 0xd)) {
    lVar3 = *(longlong *)param_1[0xc];
  }
  if (*(int *)((longlong)param_1 + 0x34) == 1) {
    if ((*(uint *)(param_1 + 0xb) & 0x500d0156) == 0) goto LAB_14000ff08;
    pcVar1 = " Detected opening for write access of file ";
  }
  else {
    pcVar1 = " Detected creation of file ";
  }
  cVar2 = '\0';
LAB_14000ff08:
  DrvIso_File_Exit_Verification(param_1[10],*param_1,cVar2,lVar3,pcVar1);
  return;
}



===== DrvIso_IoCreateFile_Exit @ 14000ff30 =====

void DrvIso_IoCreateFile_Exit(undefined8 *param_1)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  
  lVar3 = 0;
  pcVar1 = " Detected opening of file ";
  cVar2 = '\x01';
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (-1 < *(int *)(param_1 + 0xc)) {
    lVar3 = *(longlong *)param_1[0xb];
  }
  if (*(int *)((longlong)param_1 + 0x2c) == 1) {
    if ((*(uint *)(param_1 + 10) & 0x500d0156) == 0) goto LAB_14000ff78;
    pcVar1 = " Detected opening for write access of file ";
  }
  else {
    pcVar1 = " Detected creation of file ";
  }
  cVar2 = '\0';
LAB_14000ff78:
  DrvIso_File_Exit_Verification(param_1[9],*param_1,cVar2,lVar3,pcVar1);
  return;
}



===== DrvIso_NormalizeFilePath @ 14000ff98 =====

undefined8 DrvIso_NormalizeFilePath(ushort *param_1,ushort *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined2 *puVar4;
  longlong lVar5;
  ushort *puVar6;
  ushort uVar7;
  ulonglong uVar8;
  ushort uVar9;
  ushort local_38;
  ushort local_36;
  undefined4 local_34;
  undefined2 *local_30;
  ushort local_28 [8];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_34 = 0;
  RtlInitUnicodeString(&DAT_140059360,L"\\Device\\BootDevice");
  RtlInitUnicodeString(&DAT_140059370,L"\\SystemRoot");
  cVar1 = RtlPrefixUnicodeString(&DAT_14001d548,param_1,1);
  if (cVar1 == '\0') {
    cVar1 = RtlPrefixUnicodeString(&DAT_14001d558,param_1,1);
    if (cVar1 == '\0') {
      cVar1 = GetRelativePath(param_1,(ushort *)&DAT_140059370,(short *)local_28);
      if (cVar1 != '\0') {
        uVar7 = local_28[0] + 0x12;
        puVar4 = (undefined2 *)ExAllocatePool2(0x40,uVar7,0x73737664);
        if (puVar4 == (undefined2 *)0x0) {
          return 0xc0000017;
        }
        local_38 = 0;
        local_36 = uVar7;
        local_30 = puVar4;
        iVar2 = RtlAppendUnicodeStringToString(&local_38,&DAT_14001d538);
        if ((iVar2 < 0) || (iVar2 = RtlAppendUnicodeStringToString(&local_38,local_28), iVar2 < 0))
        {
          *puVar4 = 0;
          local_38 = 0;
        }
        else {
          if ((ulonglong)local_36 - (ulonglong)local_38 < 2) {
            *puVar4 = 0;
            local_38 = 0;
            goto LAB_14001027b;
          }
          puVar4[local_38 >> 1] = 0;
        }
        if (local_38 != 0) {
          *(undefined2 **)(param_2 + 4) = local_30;
          param_2[1] = local_36;
          *param_2 = local_38;
          return 0;
        }
LAB_14001027b:
        ExFreePoolWithTag(puVar4,0x73737664);
        return 0xc0000257;
      }
      cVar1 = GetRelativePath(param_1,(ushort *)&DAT_140059360,(short *)local_28);
      if (cVar1 != '\0') {
        uVar7 = local_28[0] + 2;
        lVar3 = ExAllocatePool2(0x40,uVar7,0x73737664);
        if (lVar3 == 0) {
          return 0xc0000017;
        }
        *(longlong *)(param_2 + 4) = lVar3;
        puVar6 = local_28;
        *param_2 = 0;
        param_2[1] = uVar7;
        goto LAB_140010302;
      }
      cVar1 = RtlPrefixUnicodeString(&DAT_14001d508,param_1,1);
      if (cVar1 == '\0') {
        return 0xc0000257;
      }
      if (*param_1 < 0x1e) {
        return 0xc0000257;
      }
      iVar2 = iswalnum(*(wint_t *)(*(longlong *)(param_1 + 4) + 0x18));
      if (iVar2 == 0) {
        return 0xc0000257;
      }
      iVar2 = iswdigit(*(wint_t *)(*(longlong *)(param_1 + 4) + 0x18));
      if (iVar2 != 0) {
        return 0xc0000257;
      }
      if (*(short *)(*(longlong *)(param_1 + 4) + 0x1a) != 0x3a) {
        return 0xc0000257;
      }
      if (*(short *)(*(longlong *)(param_1 + 4) + 0x1c) != 0x5c) {
        return 0xc0000257;
      }
      uVar7 = *param_1 - 0x1a;
      lVar3 = ExAllocatePool2(0x40,uVar7,0x73737664);
      if (lVar3 == 0) {
        return 0xc0000017;
      }
      lVar5 = 0x1c;
      goto LAB_1400103b9;
    }
    if (*param_1 < 0x30) {
      return 0xc0000257;
    }
    uVar8 = 0x16;
    uVar7 = 0x16;
    if (0x2c < (*param_1 & 0xfffe)) {
      do {
        uVar7 = (ushort)uVar8;
        iVar2 = iswdigit(*(wint_t *)(*(longlong *)(param_1 + 4) + uVar8 * 2));
        if (iVar2 == 0) break;
        uVar7 = uVar7 + 1;
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < *param_1 >> 1);
    }
    if (*param_1 >> 1 <= uVar7) {
      return 0xc0000257;
    }
    if (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar7 * 2) != 0x5c) {
      return 0xc0000257;
    }
    uVar9 = *param_1 + uVar7 * -2 + 2;
    lVar3 = ExAllocatePool2(0x40,uVar9,0x73737664);
    if (lVar3 == 0) {
      return 0xc0000017;
    }
    *(longlong *)(param_2 + 4) = lVar3;
    *param_2 = 0;
    param_2[1] = uVar9;
    local_30 = (undefined2 *)(*(longlong *)(param_1 + 4) + (ulonglong)(uVar7 & 0x7fff) * 2);
    local_38 = *param_1 + uVar7 * -2;
    local_36 = param_1[1] + uVar7 * -2;
  }
  else {
    if (*param_1 < 0xe) {
      return 0xc0000257;
    }
    iVar2 = iswalnum(*(wint_t *)(*(longlong *)(param_1 + 4) + 8));
    if (iVar2 == 0) {
      return 0xc0000257;
    }
    iVar2 = iswdigit(*(wint_t *)(*(longlong *)(param_1 + 4) + 8));
    if (iVar2 != 0) {
      return 0xc0000257;
    }
    if (*(short *)(*(longlong *)(param_1 + 4) + 10) != 0x3a) {
      return 0xc0000257;
    }
    if (*(short *)(*(longlong *)(param_1 + 4) + 0xc) != 0x5c) {
      return 0xc0000257;
    }
    uVar7 = *param_1 - 10;
    lVar3 = ExAllocatePool2(0x40,uVar7,0x73737664);
    if (lVar3 == 0) {
      return 0xc0000017;
    }
    lVar5 = 0xc;
LAB_1400103b9:
    *(longlong *)(param_2 + 4) = lVar3;
    *param_2 = 0;
    param_2[1] = uVar7;
    local_30 = (undefined2 *)(*(longlong *)(param_1 + 4) + lVar5);
    local_38 = *param_1 - (short)lVar5;
    local_36 = param_1[1] - (short)lVar5;
  }
  puVar6 = &local_38;
LAB_140010302:
  RtlCopyUnicodeString(param_2,puVar6);
  return 0;
}



===== DrvIso_ZwCreateFile_Exit @ 140010420 =====

void DrvIso_ZwCreateFile_Exit(undefined8 *param_1)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  
  lVar3 = 0;
  pcVar1 = " Detected opening of file ";
  cVar2 = '\x01';
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (-1 < *(int *)(param_1 + 10)) {
    lVar3 = *(longlong *)param_1[9];
  }
  if (*(int *)((longlong)param_1 + 0x1c) == 1) {
    if ((*(uint *)(param_1 + 8) & 0x500d0156) == 0) goto LAB_140010468;
    pcVar1 = " Detected opening for write access of file ";
  }
  else {
    pcVar1 = " Detected creation of file ";
  }
  cVar2 = '\0';
LAB_140010468:
  DrvIso_File_Exit_Verification(param_1[7],*param_1,cVar2,lVar3,pcVar1);
  return;
}



===== DrvIso_NtDeleteFile_Exit @ 140010490 =====

void DrvIso_NtDeleteFile_Exit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    DrvIso_File_Exit_Verification(param_1[1],*param_1,'\0',0," Detected deletion of file ");
  }
  return;
}



===== DrvIso_ZwOpenFile_Exit @ 1400104d0 =====

void DrvIso_ZwOpenFile_Exit(undefined8 *param_1)

{
  char *pcVar1;
  longlong lVar2;
  bool bVar3;
  
  lVar2 = 0;
  if (param_1 != (undefined8 *)0x0) {
    if (-1 < *(int *)(param_1 + 6)) {
      lVar2 = *(longlong *)param_1[5];
    }
    bVar3 = (*(uint *)(param_1 + 4) & 0x500d0156) == 0;
    pcVar1 = " Detected opening for write access of file ";
    if (bVar3) {
      pcVar1 = " Detected opening of file ";
    }
    DrvIso_File_Exit_Verification(param_1[3],*param_1,bVar3,lVar2,pcVar1);
  }
  return;
}



===== DrvIso_ValidateFilePath @ 140010528 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
DrvIso_ValidateFilePath
          (ushort *param_1,ushort *param_2,undefined8 param_3,char param_4,char *param_5)

{
  char cVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  wchar_t *pwVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  ushort *puVar9;
  longlong local_38;
  ushort local_30 [12];
  
  local_38 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  pwVar2 = (wchar_t *)(*XdvGetDriverName)(param_3);
  cVar1 = DrvIso_OnExceptionList(pwVar2,1,param_1,param_4 == '\0');
  if (cVar1 == '\0') {
    puVar9 = param_1;
    if (param_2 != (ushort *)0x0) {
      puVar9 = param_2;
    }
    lVar3 = RtlFindUnicodeSubstring(param_1,&DAT_14001d4f8,1);
    if (lVar3 == 0) {
      pwVar2 = (wchar_t *)(*XdvGetDriverName)(param_3);
      uVar5 = DrvIso_OnModeExceptionList(pwVar2,1,param_1,param_4 == '\0');
      cVar1 = (char)uVar5;
      pcVar8 = "File operations should not use absolute paths.";
      uVar4 = (*XdvGetDriverName)(param_3);
      pcVar6 = "DRIVER_ISOLATION_WARNING";
      if (cVar1 == '\0') {
        pcVar6 = "DRIVER_ISOLATION_VIOLATION";
      }
      DifUtilDbgPrint("%s: %S: %s%s\'%wZ\'\n",pcVar6,uVar4,
                      "File operations should not use absolute paths.",param_5,puVar9);
      if (param_5 == (char *)0x0) {
        param_5 = "";
      }
      RtlInitAnsiString(local_30,param_5);
      iVar7 = DrvIso_GenerateViolationAllocatedAnsiErrorString
                        ((ushort *)&ERROR_STRING_ABSOLUTE_FILE_PATH,local_30,(longlong)puVar9,0,
                         &local_38);
      if (-1 < extraout_EAX_00) {
        pcVar8 = *(char **)(local_38 + 8);
      }
    }
    else {
      if (param_4 != '\0') {
        return 0;
      }
      pcVar8 = "Files in the driver store should not be modified.";
      uVar4 = (*XdvGetDriverName)(param_3);
      DifUtilDbgPrint("%s: %S: %s%s\'%wZ\'\n","DRIVER_ISOLATION_VIOLATION",uVar4,
                      "Files in the driver store should not be modified.",param_5,puVar9);
      if (param_5 == (char *)0x0) {
        param_5 = "";
      }
      RtlInitAnsiString(local_30,param_5);
      iVar7 = DrvIso_GenerateViolationAllocatedAnsiErrorString
                        ((ushort *)&ERROR_STRING_DRIVERSTORE_PATH,local_30,(longlong)puVar9,0,
                         &local_38);
      if (-1 < extraout_EAX) {
        pcVar8 = *(char **)(local_38 + 8);
      }
      cVar1 = '\0';
    }
    lVar3 = local_38;
    DrvIso_ReportViolation(2,pcVar8,CONCAT44((int)((ulonglong)param_3 >> 0x20),iVar7),cVar1);
    if (lVar3 != 0) {
      DrvIso_FreeViolationAllocatedAnsiErrorString(lVar3);
    }
  }
  return 0;
}



===== DrvIso_EnsureActiveControlSetPathInitialized @ 140010770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DrvIso_EnsureActiveControlSetPathInitialized(void)

{
  int iVar1;
  char cVar2;
  undefined1 auStack_b8 [32];
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  char local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_58 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_50 = uStack_50 & 0xffffffff00000000;
  local_68 = (undefined8 *)0x0;
  uStack_60 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_80 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (DrvIsoActiveControlSetPath == 0) {
    KeEnterCriticalRegion();
    cVar2 = '\x01';
    ExAcquireResourceExclusiveLite(&DrvIsoControlSetInitLock,1);
    if (DrvIsoActiveControlSetPath == 0) {
      RtlInitUnicodeString(&local_48,L"\\Registry\\Machine\\System\\Select");
      RtlInitUnicodeString(&local_38,L"Current");
      local_68 = &local_48;
      local_78 = CONCAT44(local_78._4_4_,0x30);
      uStack_70 = 0;
      uStack_60 = CONCAT44(uStack_60._4_4_,0x240);
      local_58 = 0;
      uStack_50 = 0;
      iVar1 = ZwOpenKey(&local_80,0xf003f,&local_78);
      if (-1 < iVar1) {
        iVar1 = ZwQueryValueKey(local_80,&local_38,2,local_28);
        if (((-1 < iVar1) && (local_24 == 4)) && (local_20 == 4)) {
          cVar2 = local_1c;
        }
      }
      _DrvIsoActiveControlSetPath = 0x4e0000;
      _DAT_140032ef8 = &DrvIsoActiveControlSetPathBuffer;
      RtlUnicodeStringPrintfEx
                ((ushort *)&DrvIsoActiveControlSetPath,(undefined2 *)0x0,0x800,
                 L"\\Registry\\Machine\\System\\ControlSet%03d",cVar2);
    }
    ExReleaseResourceLite(&DrvIsoControlSetInitLock);
    KeLeaveCriticalRegion();
    if (local_80 != 0) {
      ZwClose();
    }
  }
  return;
}



===== DrvIso_IsPathException @ 14001093c =====

undefined8
DrvIso_IsPathException(int param_1,ushort *param_2,undefined8 *param_3,uint param_4,char param_5)

{
  char cVar1;
  undefined7 extraout_var;
  undefined1 *puVar2;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined1 uVar3;
  uint uVar4;
  ushort local_48 [24];
  
  uVar3 = 0;
  uVar4 = 0;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
  local_48[0x10] = 0;
  local_48[0x11] = 0;
  local_48[0x12] = 0;
  local_48[0x13] = 0;
  local_48[0x14] = 0;
  local_48[0x15] = 0;
  local_48[0x16] = 0;
  local_48[0x17] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  puVar2 = (undefined1 *)register0x00000020;
  if (param_4 != 0) {
    do {
      if ((param_5 == '\0') || (*(char *)(param_3 + 1) != '\0')) {
        RtlInitUnicodeString(local_48,*param_3);
        cVar1 = GetRelativePath(param_2,local_48,(short *)0x0);
        puVar2 = (undefined1 *)CONCAT71(extraout_var,cVar1);
        if (cVar1 != '\0') {
LAB_140010a17:
          uVar3 = 1;
          break;
        }
        if (param_1 == 0) {
          cVar1 = GetRelativePath(local_48,(ushort *)&DAT_14001edf8,(short *)(local_48 + 8));
          puVar2 = (undefined1 *)CONCAT71(extraout_var_00,cVar1);
          if (cVar1 != '\0') {
            DrvIso_EnsureActiveControlSetPathInitialized();
            cVar1 = GetRelativePath(param_2,&DrvIsoActiveControlSetPath,(short *)(local_48 + 0x10));
            puVar2 = (undefined1 *)CONCAT71(extraout_var_01,cVar1);
            if (cVar1 != '\0') {
              cVar1 = GetRelativePath(local_48 + 0x10,local_48 + 8,(short *)0x0);
              puVar2 = (undefined1 *)CONCAT71(extraout_var_02,cVar1);
              if (cVar1 != '\0') goto LAB_140010a17;
            }
          }
        }
      }
      uVar4 = uVar4 + 1;
      param_3 = param_3 + 2;
    } while (uVar4 < param_4);
  }
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),uVar3);
}



===== DrvIso_OnExceptionList @ 140010a3c =====

char DrvIso_OnExceptionList(wchar_t *param_1,int param_2,ushort *param_3,char param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  uint uVar4;
  char cVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar6 = 0;
  cVar5 = '\0';
  if (param_1 != (wchar_t *)0x0) {
    if (param_2 == 0) {
      uVar7 = 0x6d;
      puVar3 = &DAT_14001ddd8;
    }
    else {
      if (param_2 != 1) {
        return '\0';
      }
      uVar7 = 0x15;
      puVar3 = (undefined8 *)&DAT_14001ebc8;
    }
    uVar4 = 0;
    do {
      if (((wchar_t *)puVar3[-1] == (wchar_t *)0x0) ||
         (iVar1 = _wcsicmp(param_1,(wchar_t *)puVar3[-1]), iVar1 == 0)) {
        if (*(uint *)(puVar3 + 1) == 0) {
          return '\x01';
        }
        uVar2 = DrvIso_IsPathException
                          (param_2,param_3,(undefined8 *)*puVar3,*(uint *)(puVar3 + 1),param_4);
        uVar6 = uVar2 & 0xff;
        if ((char)uVar2 != '\0') {
          return (char)uVar2;
        }
      }
      cVar5 = (char)uVar6;
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 3;
    } while (uVar4 < uVar7);
  }
  return cVar5;
}



===== DrvIso_OnModeExceptionList @ 140010b04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DrvIso_OnModeExceptionList(wchar_t *param_1,int param_2,ushort *param_3,char param_4)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined1 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined1 auStack_1a8 [32];
  undefined4 local_168;
  undefined1 local_164 [8];
  uint local_15c;
  ulonglong local_48;
  
  uVar3 = __security_cookie ^ (ulonglong)auStack_1a8;
  uVar5 = 0;
  puVar7 = (undefined8 *)0x0;
  uVar6 = 0;
  bVar1 = false;
  if ((DrvIsoMode < 3) && (param_1 != (wchar_t *)0x0)) {
    local_48 = uVar3;
    uVar3 = Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      if (param_2 == 0) {
        lVar4 = (longlong)(int)DrvIsoMode;
        uVar3 = lVar4 * 2;
        puVar7 = *(undefined8 **)(&DAT_14001dc70 + lVar4 * 0x10);
        uVar6 = *(uint *)(&DAT_14001dc78 + lVar4 * 0x10);
      }
      else {
        if (param_2 != 1) goto LAB_140010d91;
        lVar4 = (longlong)(int)DrvIsoMode;
        uVar3 = lVar4 * 2;
        puVar7 = *(undefined8 **)(&DAT_14001dbf0 + lVar4 * 0x10);
        uVar6 = *(uint *)(&DAT_14001dbf8 + lVar4 * 0x10);
      }
    }
    else {
      memset(local_164,0,0x110);
      local_168 = 0x114;
      uVar3 = RtlGetVersion(&local_168);
      uVar8 = 0;
      if (-1 < (int)uVar3) {
        uVar8 = local_15c;
      }
      if (param_2 == 0) {
        uVar3 = Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 != 0) && (0x6bcf < uVar8)) {
          bVar1 = true;
          puVar7 = *(undefined8 **)(&DAT_14001f920 + (longlong)(int)DrvIsoMode * 0x10);
          uVar6 = *(uint *)(&DAT_14001f928 + (longlong)(int)DrvIsoMode * 0x10);
        }
        uVar3 = Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 == 0) || (uVar8 < 0x6658)) {
          if (!bVar1) {
            lVar4 = (longlong)(int)DrvIsoMode;
            uVar3 = lVar4 * 2;
            puVar7 = *(undefined8 **)(&DAT_14001ea30 + lVar4 * 0x10);
            uVar6 = *(uint *)(&DAT_14001ea38 + lVar4 * 0x10);
          }
        }
        else if (!bVar1) {
          lVar4 = (longlong)(int)DrvIsoMode;
          uVar3 = lVar4 * 2;
          puVar7 = *(undefined8 **)(&DAT_14001e9d0 + lVar4 * 0x10);
          uVar6 = *(uint *)(&DAT_14001e9d8 + lVar4 * 0x10);
        }
      }
      else {
        if (param_2 != 1) goto LAB_140010d91;
        uVar3 = Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 != 0) && (0x6bcf < uVar8)) {
          bVar1 = true;
          puVar7 = *(undefined8 **)(&DAT_14001f380 + (longlong)(int)DrvIsoMode * 0x10);
          uVar6 = *(uint *)(&DAT_14001f388 + (longlong)(int)DrvIsoMode * 0x10);
        }
        uVar3 = Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 == 0) || (uVar8 < 0x6658)) {
          if (!bVar1) {
            lVar4 = (longlong)(int)DrvIsoMode;
            uVar3 = lVar4 * 2;
            puVar7 = *(undefined8 **)(&DAT_14001f630 + lVar4 * 0x10);
            uVar6 = *(uint *)(&DAT_14001f638 + lVar4 * 0x10);
          }
        }
        else if (!bVar1) {
          lVar4 = (longlong)(int)DrvIsoMode;
          uVar3 = lVar4 * 2;
          puVar7 = *(undefined8 **)(&DAT_14001f440 + lVar4 * 0x10);
          uVar6 = *(uint *)(&DAT_14001f448 + lVar4 * 0x10);
        }
      }
    }
    if ((puVar7 != (undefined8 *)0x0) && (uVar6 != 0)) {
      iVar2 = _wcsicmp(param_1,L"wdf01000.sys");
      uVar3 = CONCAT44(extraout_var,iVar2);
      if (iVar2 != 0) {
        iVar2 = _wcsicmp(param_1,L"wudfrd.sys");
        uVar3 = CONCAT44(extraout_var_00,iVar2);
        if (iVar2 != 0) {
          uVar3 = DrvIso_IsPathException(param_2,param_3,puVar7,uVar6,param_4);
          uVar5 = (undefined1)uVar3;
          goto LAB_140010d91;
        }
      }
      uVar5 = 1;
    }
  }
LAB_140010d91:
  return CONCAT71((int7)(uVar3 >> 8),uVar5);
}



===== Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledDeviceUsageNoInline @ 140010dc8 =====

ulonglong Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_DrvIso_WhcpEnforcement_25H2__private_featureState;
  if ((Feature_DrvIso_WhcpEnforcement_25H2__private_featureState & 0x10) == 0) {
    uVar1 = Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_DrvIso_WhcpEnforcement_25H2__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledFallback @ 140010e00 =====

void Feature_DrvIso_WhcpEnforcement_25H2__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_DrvIso_WhcpEnforcement_25H2__private_descriptor);
  return;
}



===== Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledDeviceUsageNoInline @ 140010e1c =====

ulonglong Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_featureState;
  if ((Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_featureState & 0x10) == 0) {
    uVar1 = Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledFallback @ 140010e54 =====

void Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_DrvIso_WhcpEnforcement_25H2_vNext__private_descriptor);
  return;
}



===== Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledDeviceUsageNoInline @ 140010e70 =====

ulonglong Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_featureState;
  if ((Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_featureState & 0x10) == 0) {
    uVar1 = Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledFallback(local_res8,3)
    ;
  }
  else {
    uVar1 = (ulonglong)(Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledFallback @ 140010ea8 =====

void Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_DrvIso_WhcpEnforcement_UpdatedStructure__private_descriptor);
  return;
}



===== GetRelativePath @ 140010ec4 =====

undefined1 GetRelativePath(ushort *param_1,ushort *param_2,short *param_3)

{
  short sVar1;
  char cVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  cVar2 = RtlPrefixUnicodeString(param_2,param_1,1);
  if (cVar2 != '\0') {
    uVar3 = *param_2 >> 1;
    if ((*param_2 == *param_1) ||
       ((uVar3 < *param_1 >> 1 &&
        ((sVar1 = *(short *)(*(longlong *)(param_1 + 4) + (ulonglong)uVar3 * 2), sVar1 == 0 ||
         (sVar1 == 0x5c)))))) {
      if (param_3 != (short *)0x0) {
        *(ulonglong *)(param_3 + 4) = *(longlong *)(param_1 + 4) + (ulonglong)uVar3 * 2;
        *param_3 = *param_1 - *param_2;
        param_3[1] = param_1[1] - *param_2;
      }
      uVar4 = 1;
    }
  }
  return uVar4;
}



===== RtlUnicodeStringPrintfEx @ 140010f7c =====

int RtlUnicodeStringPrintfEx
              (ushort *param_1,undefined2 *param_2,uint param_3,wchar_t *param_4,char param_5)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  wchar_t *local_68;
  ulonglong local_60;
  
  if ((param_1 == (ushort *)0x0) && ((param_3 >> 8 & 1) != 0)) {
LAB_140011013:
    local_60 = 0;
    local_68 = (wchar_t *)0x0;
  }
  else {
    uVar1 = *param_1;
    if ((((uVar1 & 1) != 0) ||
        (((uVar2 = param_1[1], (uVar2 & 1) != 0 || (uVar2 < uVar1)) || (uVar2 == 0xffff)))) ||
       ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
      return -0x3ffffff3;
    }
    if (param_1 == (ushort *)0x0) goto LAB_140011013;
    local_68 = *(wchar_t **)(param_1 + 4);
    local_60 = (ulonglong)(param_1[1] >> 1);
  }
  uVar5 = 0;
  if (((param_3 >> 8 & 1) != 0) && (param_4 == (wchar_t *)0x0)) {
    param_4 = L"";
  }
  iVar4 = 0;
  uVar8 = local_60;
  pwVar10 = local_68;
  if ((param_3 & 0xffffe000) == 0) {
    if (local_60 == 0) {
      if (*param_4 != L'\0') {
        if (local_68 == (wchar_t *)0x0) goto LAB_140011053;
        iVar4 = -0x7ffffffb;
      }
    }
    else {
      iVar3 = _vsnwprintf(local_68,local_60,param_4,&param_5);
      if ((iVar3 < 0) || (uVar5 = (longlong)iVar3, local_60 < (ulonglong)(longlong)iVar3)) {
        iVar4 = -0x7ffffffb;
        uVar5 = local_60;
      }
      uVar8 = local_60 - uVar5;
      pwVar10 = local_68 + uVar5;
      if (((-1 < iVar4) && ((param_3 >> 9 & 1) != 0)) && (uVar8 != 0)) {
        memset(pwVar10,param_3 & 0xff,uVar8 * 2);
        goto LAB_1400110ed;
      }
    }
    if (-1 < iVar4) goto LAB_1400110ed;
  }
  else {
LAB_140011053:
    iVar4 = -0x3ffffff3;
    uVar5 = 0;
  }
  if (((param_3 & 0x1c00) != 0) && (local_60 != 0)) {
    uVar6 = 0;
    uVar7 = local_60;
    pwVar9 = local_68;
    if ((param_3 & 0x1000) == 0) {
      uVar6 = uVar5;
      uVar7 = uVar8;
      pwVar9 = pwVar10;
    }
    if ((param_3 >> 10 & 1) != 0) {
      memset(local_68,param_3 & 0xff,local_60 * 2);
      uVar6 = 0;
      uVar7 = local_60;
      pwVar9 = local_68;
    }
    uVar5 = uVar6;
    uVar8 = uVar7;
    pwVar10 = pwVar9;
    if ((param_3 >> 0xb & 1) != 0) {
      uVar5 = 0;
      uVar8 = local_60;
      pwVar10 = local_68;
    }
  }
LAB_1400110ed:
  if (param_1 != (ushort *)0x0) {
    *param_1 = (short)uVar5 * 2;
  }
  if ((((iVar4 + 0x80000000U & 0x80000000) != 0) || (iVar4 == -0x7ffffffb)) &&
     (param_2 != (undefined2 *)0x0)) {
    *param_2 = 0;
    param_2[1] = (short)uVar8 * 2;
    *(wchar_t **)(param_2 + 4) = pwVar10;
  }
  return iVar4;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400111c0 =====

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
LAB_1400113c9:
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
LAB_14001129b:
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
      if (param_3 == 4) goto LAB_1400113c9;
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
        goto LAB_14001129b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400114b4 =====

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
      goto LAB_140011585;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140011585;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140011585;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140011585;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140011585;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140011585;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140011585;
    }
  }
  uVar3 = 0xff;
LAB_140011585:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400115dc =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400116cc =====

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
LAB_14001177f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400117ad;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14001177f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400117ad:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140011938 =====

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



===== wil_details_IsEnabledFallback @ 14001199c =====

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



===== AddDriver @ 140011a30 =====

uint * AddDriver(void *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  uint *puVar3;
  longlong lVar4;
  void *_Dst;
  uint *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = (uint *)ExAllocatePool2(0x40,0x30,0x64497644);
  if (puVar3 == (uint *)0x0) {
    DifUtilDbgPrint("AddDriver(): failed to allocate memory for driver entry!\n");
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3[0] = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    *(char *)(puVar3 + 4) = NextFillPattern;
    NextFillPattern = NextFillPattern + '\x01';
    if (param_1 != (void *)0x0) {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (*(short *)((longlong)param_1 + lVar4 * 2) != 0);
      *puVar3 = (uint)lVar4;
      if (0x100 < (uint)lVar4) {
        *puVar3 = 0x100;
        lVar4 = 0x100;
      }
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)((int)lVar4 + 1) * 2,0x64497644);
      *(void **)(puVar3 + 2) = _Dst;
      memset(_Dst,0,(ulonglong)(*puVar3 + 1) * 2);
      memcpy(*(void **)(puVar3 + 2),param_1,(ulonglong)*puVar3 * 2);
    }
    DifUtilDbgPrint("Tracking driver %S with fill pattern 0x%02x\n",param_1,(char)puVar3[4]);
    uVar2 = ExAcquireSpinLockExclusive(&IDEnabledDriverListLock);
    puVar6 = auStack_28;
    puVar7 = &DAT_140059400;
    puVar5 = puVar3 + 8;
    if (*(undefined8 **)DAT_140059408 != &DAT_140059400) {
      puVar5 = (uint *)0x3;
      pcVar1 = (code *)swi(0x29);
      uVar2 = (*pcVar1)();
      puVar6 = auStack_20;
    }
    *(uint **)(puVar5 + 2) = DAT_140059408;
    *(undefined8 **)puVar5 = puVar7;
    *(uint **)DAT_140059408 = puVar5;
    *(undefined8 *)(puVar6 + -8) = 0x140011b6e;
    DAT_140059408 = puVar5;
    ExReleaseSpinLockExclusive(&IDEnabledDriverListLock,uVar2);
  }
  return puVar3;
}



===== AddIrp @ 140011b88 =====

undefined8 * AddIrp(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x64497644);
  if (puVar3 == (undefined8 *)0x0) {
    DifUtilDbgPrint("AddIrp(): failed to allocate memory for irp entry!\n");
    puVar3 = (undefined8 *)0x0;
  }
  else {
    puVar3[2] = 0;
    puVar3[3] = 0;
    *puVar3 = param_1;
    *(undefined4 *)(puVar3 + 1) = param_2;
    *(undefined4 *)((longlong)puVar3 + 0xc) = param_3;
    uVar2 = ExAcquireSpinLockExclusive(&IrpListLock);
    puVar6 = auStack_28;
    puVar7 = &DAT_1400593d0;
    puVar4 = puVar3 + 2;
    puVar5 = DAT_1400593d8;
    if ((undefined8 *)*DAT_1400593d8 != &DAT_1400593d0) {
      puVar5 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar4 = (undefined8 *)(*pcVar1)(3,uVar2);
      puVar6 = auStack_20;
    }
    puVar4[1] = puVar5;
    *puVar4 = puVar7;
    *puVar5 = puVar4;
    *(undefined8 *)(puVar6 + -8) = 0x140011c45;
    DAT_1400593d8 = puVar4;
    ExReleaseSpinLockExclusive(&IrpListLock);
    TrackingIrpCount = TrackingIrpCount + 1;
    if ((((XdvVerifierOptions & 0x10000) == 0) && (TrackingIrpCount == (TrackingIrpCount / 10) * 10)
        ) && (TrackingIrpCountHighWaterMark < TrackingIrpCount)) {
      *(undefined8 *)(puVar6 + -8) = 0x140011c9f;
      TrackingIrpCountHighWaterMark = TrackingIrpCount;
      DifUtilDbgPrint("TrackingIrpCount: %d\n",TrackingIrpCount);
    }
  }
  return puVar3;
}



===== DeviceControlDispatchHook @ 140011cd0 =====

void DeviceControlDispatchHook(longlong param_1)

{
  char cVar1;
  void *pvVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  pvVar2 = SanitizeDeviceName((ushort *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x38));
  if (pvVar2 == (void *)0x0) {
    DifUtilDbgPrint("Failed to get device name from driver object!\n");
    return;
  }
  if (((*(char *)(*(longlong *)(param_1 + 8) + 0x43) == *(char *)(*(longlong *)(param_1 + 8) + 0x42)
       ) && (cVar1 = KeGetCurrentIrql(), cVar1 == '\0')) &&
     (*(char *)(*(longlong *)(param_1 + 8) + 0x40) != '\0')) {
    cVar1 = GetIntegrityLevel(local_res10,local_res8);
    if (cVar1 == '\0') {
      DifUtilDbgPrint("Failed to get caller token information!\n");
    }
    else {
      plVar3 = FindIrpByAddress(*(longlong *)(param_1 + 8));
      if (((plVar3 == (longlong *)0x0) &&
          (((XdvVerifierOptions & 0x10000) == 0 ||
           (cVar1 = DifPluginSimplePerfControl(TrackingIrpCount,100,1000), cVar1 != '\0')))) &&
         (puVar4 = AddIrp(*(undefined8 *)(param_1 + 8),local_res10[0],local_res8[0]),
         puVar4 == (undefined8 *)0x0)) {
        DifUtilDbgPrint("Failed to track irp for device %S!\n",pvVar2);
      }
    }
  }
  ExFreePoolWithTag(pvVar2,0x64497644);
  return;
}



===== DifInfoDisclosurePluginEntry @ 140011e00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DifInfoDisclosurePluginEntry(void)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_1a8 [32];
  undefined4 local_188 [4];
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  char *local_138;
  undefined4 local_130;
  undefined8 local_128;
  code *local_120;
  char *local_118;
  undefined4 local_110;
  undefined8 local_108;
  code *local_100;
  char *local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  code *local_e0;
  char *local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  code *local_c0;
  char *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  code *local_a0;
  char *local_98;
  undefined4 local_90;
  undefined8 local_88;
  code *local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1a8;
  _IDEnabledDriverList = 0;
  _DAT_1400593f8 = 0;
  DAT_140059408 = &DAT_140059400;
  DAT_140059400 = &DAT_140059400;
  DAT_1400593d8 = &DAT_1400593d0;
  DAT_1400593d0 = &DAT_1400593d0;
  local_188[0] = 0x4c45414b;
  _DAT_1400593e8 = 0;
  uRam00000001400593f0 = 0;
  bVar1 = RtlRandomEx(local_188);
  local_168 = 0x200000000;
  uStack_160 = 0x200000000;
  local_158 = 0x200000000;
  uStack_150 = 0x300000005;
  local_148 = 0x300000005;
  uStack_140 = 0x300000005;
  local_178 = 0xc4;
  local_174 = 0x26;
  local_170 = 5;
  local_16c = 3;
  StartingFillPattern = bVar1 % 0x30 + 0x40;
  NextFillPattern = StartingFillPattern;
  iVar2 = CarRegisterRuleClassConfiguration(&local_178);
  if (-1 < iVar2) {
    local_128 = 0;
    local_108 = 0;
    local_e8 = 0;
    local_c8 = 0;
    local_a8 = 0;
    local_88 = 0;
    local_60 = 0;
    local_40 = 0;
    local_20 = 0;
    local_138 = "ExAllocatePool";
    local_120 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_118 = "ExAllocatePoolWithTag";
    local_100 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_f8 = "ExAllocatePoolWithTagPriority";
    local_e0 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_d8 = "ExAllocatePoolWithQuota";
    local_c0 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_b8 = "ExAllocatePoolWithQuotaTag";
    local_a0 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_98 = "ExAllocatePool2";
    local_80 = ExAllocatePoolWithQuotaTag_ID_Exit;
    local_78 = "IoCreateDevice";
    local_68 = IoCreateDevice_ID_Enter;
    local_58 = "IofCompleteRequest";
    local_48 = IofCompleteRequest_ID_Enter;
    local_38 = "IRP_MJ_DEVICE_CONTROL";
    local_28 = DeviceControlDispatchHook;
    local_130 = 0x19d;
    local_110 = 0x19e;
    local_f0 = 0x19f;
    local_d0 = 0x1a0;
    local_b0 = 0x1a1;
    local_90 = 0x1a3;
    local_70 = 0x163;
    local_50 = 0x12d;
    local_30 = 0x1000000e;
    DifRegisterPlugin(&local_138,9,0x26);
  }
  return;
}



===== ExAllocatePoolWithQuotaTag_ID_Exit @ 140012080 =====

void ExAllocatePoolWithQuotaTag_ID_Exit(undefined8 *param_1)

{
  FillPoolAllocation(*param_1,(void *)param_1[8],param_1[5],*(uint *)(param_1 + 7));
  return;
}



===== FillPoolAllocation @ 1400120a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FillPoolAllocation(undefined8 param_1,void *param_2,size_t param_3,uint param_4)

{
  void *pvVar1;
  uint *puVar2;
  
  if (((((param_4 >> 10 & 1) == 0) && (param_2 != (void *)0x0)) && (-1 < (int)param_4)) &&
     ((pvVar1 = (void *)(*XdvGetDriverName)(), pvVar1 != (void *)0x0 &&
      ((puVar2 = FindDriverByName(pvVar1), puVar2 != (uint *)0x0 ||
       (puVar2 = AddDriver(pvVar1), puVar2 != (uint *)0x0)))))) {
    memset(param_2,(uint)(byte)puVar2[4],param_3);
  }
  return;
}



===== FindDriverByName @ 140012120 =====

uint * FindDriverByName(void *param_1)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)0x0;
  if (param_1 == (void *)0x0) {
    puVar4 = (uint *)0x0;
  }
  else {
    uVar2 = ExAcquireSpinLockShared(&IDEnabledDriverListLock);
    for (puVar1 = DAT_140059400; puVar5 = (uint *)(puVar1 + -4),
        puVar5 != (uint *)&IDEnabledDriverList; puVar1 = (undefined8 *)*puVar1) {
      if ((*puVar5 != 0) &&
         (iVar3 = memcmp(param_1,(void *)puVar1[-3],(ulonglong)*puVar5 * 2), iVar3 == 0)) {
        puVar4 = puVar5;
        break;
      }
    }
    ExReleaseSpinLockShared(&IDEnabledDriverListLock,uVar2);
  }
  return puVar4;
}



===== FindIrpByAddress @ 1400121dc =====

longlong * FindIrpByAddress(longlong param_1)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)0x0;
  uVar2 = ExAcquireSpinLockShared(&IrpListLock);
  puVar1 = DAT_1400593d0;
  do {
    plVar3 = puVar1 + -2;
    if (plVar3 == (longlong *)&IrpList) {
LAB_14001222b:
      ExReleaseSpinLockShared(&IrpListLock,uVar2);
      return plVar4;
    }
    if (*plVar3 == param_1) {
      plVar4 = plVar3;
      goto LAB_14001222b;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== GetIntegrityLevel @ 140012254 =====

undefined1 GetIntegrityLevel(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 *_Dst;
  undefined4 *puVar2;
  char *pcVar3;
  undefined1 uVar4;
  uint local_res18 [2];
  longlong local_res20;
  
  local_res20 = 0;
  local_res18[0] = 0;
  uVar4 = 0;
  iVar1 = ZwOpenProcessTokenEx(0xffffffffffffffff,0x80000000,0x200,&local_res20);
  if (iVar1 < 0) {
    pcVar3 = "Failed to get process token 0x%08x!\n";
  }
  else {
    ZwQueryInformationToken(local_res20,0x19,0,0,local_res18);
    if (local_res18[0] != 0) {
      _Dst = (undefined8 *)ExAllocatePool2(0x40,local_res18[0],0x64497644);
      if (_Dst == (undefined8 *)0x0) {
        DifUtilDbgPrint("Failed to allocate memory for token!\n");
        goto LAB_1400123f3;
      }
      memset(_Dst,0,(ulonglong)local_res18[0]);
      iVar1 = ZwQueryInformationToken(local_res20,0x19,_Dst,local_res18[0],local_res18);
      if (iVar1 < 0) {
        pcVar3 = "Failed to get the integrity level token 0x%08x!\n";
LAB_140012365:
        DifUtilDbgPrint(pcVar3,iVar1);
      }
      else {
        puVar2 = (undefined4 *)RtlSubAuthoritySid(*_Dst,0);
        if (puVar2 == (undefined4 *)0x0) {
          DifUtilDbgPrint("Failed to get integrity level from SID!\n");
        }
        else {
          *param_1 = *puVar2;
        }
        iVar1 = ZwQueryInformationToken(local_res20,0x1d,_Dst,4,local_res18);
        if (iVar1 < 0) {
          pcVar3 = "Failed to get app container status 0x%08x!\n";
          goto LAB_140012365;
        }
        uVar4 = 1;
        *param_2 = *(undefined4 *)_Dst;
      }
      ExFreePoolWithTag(_Dst,0x64497644);
      goto LAB_1400123f3;
    }
    pcVar3 = "Failed to get the size of the integrity token 0x%08x!\n";
  }
  DifUtilDbgPrint(pcVar3,iVar1);
LAB_1400123f3:
  if (local_res20 != 0) {
    ZwClose();
  }
  return uVar4;
}



===== IoCreateDevice_ID_Enter @ 140012430 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoCreateDevice_ID_Enter(undefined8 *param_1)

{
  void *pvVar1;
  uint *puVar2;
  
  pvVar1 = (void *)(*XdvGetDriverName)(*param_1);
  if (pvVar1 != (void *)0x0) {
    puVar2 = FindDriverByName(pvVar1);
    if (puVar2 == (uint *)0x0) {
      AddDriver(pvVar1);
    }
  }
  return;
}



===== IofCompleteRequest_ID_Enter @ 140012470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IofCompleteRequest_ID_Enter(undefined8 *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  char cVar6;
  byte bVar7;
  undefined1 uVar8;
  void *pvVar9;
  uint *puVar10;
  void *pvVar11;
  longlong *plVar12;
  undefined8 uVar13;
  ulonglong *puVar14;
  longlong lVar15;
  undefined8 *puVar16;
  uint uVar17;
  int local_res8;
  ulonglong *in_stack_ffffffffffffff88;
  ulonglong uVar18;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar19;
  
  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  lVar15 = 0;
  puVar14 = (ulonglong *)0x0;
  uVar17 = 0xffffffff;
  local_res8 = 0;
  lVar1 = param_1[2];
  if (*(char *)(lVar1 + 0x40) == '\0') {
    return;
  }
  if (**(char **)(lVar1 + 0xb8) != '\x0e') {
    return;
  }
  pvVar9 = (void *)(*XdvGetDriverName)(*param_1);
  if (pvVar9 == (void *)0x0) {
    return;
  }
  puVar10 = FindDriverByName(pvVar9);
  if (puVar10 == (uint *)0x0) {
    return;
  }
  pvVar11 = SanitizeDeviceName((ushort *)
                               (*(longlong *)(*(longlong *)(*(longlong *)(lVar1 + 0xb8) + 0x28) + 8)
                               + 0x38));
  if (pvVar11 == (void *)0x0) {
    DifUtilDbgPrint("Failed to sanitize device name for driver %S!\n",pvVar9);
  }
  plVar12 = FindIrpByAddress(param_1[2]);
  if (plVar12 != (longlong *)0x0) {
    uVar17 = *(uint *)(plVar12 + 1);
    local_res8 = *(int *)((longlong)plVar12 + 0xc);
  }
  if ((XdvVerifierOptions & 0x10000) == 0) {
    cVar6 = '\x01';
  }
  else {
    cVar6 = DifPluginSimplePerfControl(puVar10[5],100,1000);
  }
  if (cVar6 != '\0') {
    if ((*(uint *)(lVar1 + 0x10) & 0x10) == 0) {
      puVar16 = *(undefined8 **)(lVar1 + 8);
      if (puVar16 == (undefined8 *)0x0) {
        if (((*(ulonglong *)(lVar1 + 0x70) != 0) &&
            (*(ulonglong *)(lVar1 + 0x70) < *(ulonglong *)MmUserProbeAddress_exref)) &&
           ((uVar17 == 0xffffffff || ((uVar17 & 0xf000) < 0x2001)))) {
          bVar7 = KeGetCurrentIrql();
          if (bVar7 < 2) {
            uVar18 = 0;
            lVar15 = IoAllocateMdl(*(undefined8 *)(lVar1 + 0x70),*(undefined4 *)(lVar1 + 0x38),0,1,0
                                  );
            if (lVar15 == 0) {
              DifUtilDbgPrint("Failed to allocate MDL for user buffer!\n");
              goto LAB_1400128bf;
            }
            MmProbeAndLockPages(lVar15,1,0);
            if ((*(byte *)(lVar15 + 10) & 5) == 0) {
              puVar14 = (ulonglong *)
                        MmMapLockedPagesSpecifyCache
                                  (lVar15,0,1,0,uVar18 & 0xffffffff00000000,
                                   CONCAT44(uVar19,0x40000020));
            }
            else {
              puVar14 = *(ulonglong **)(lVar15 + 0x18);
            }
            if ((puVar14 != (ulonglong *)0x0) &&
               (uVar13 = ScanBufferForInfoDisclosure
                                   ((longlong)puVar10,puVar14,*(ulonglong *)(lVar1 + 0x38)),
               (char)uVar13 == '\x01')) {
              PrintBufferToKd((longlong)puVar10,lVar1,(ulonglong)uVar17,local_res8,puVar14,
                              *(ulonglong *)(lVar1 + 0x38));
            }
          }
          if (puVar14 != (ulonglong *)0x0) {
            MmUnlockPages(lVar15);
          }
          if (lVar15 != 0) {
            IoFreeMdl(lVar15);
          }
        }
      }
      else {
        for (; puVar16 != (undefined8 *)0x0; puVar16 = (undefined8 *)*puVar16) {
          if ((*(byte *)((longlong)puVar16 + 10) & 5) == 0) {
            in_stack_ffffffffffffff88 =
                 (ulonglong *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffff00000000);
            puVar14 = (ulonglong *)
                      MmMapLockedPagesSpecifyCache
                                (puVar16,0,1,0,in_stack_ffffffffffffff88,0x40000020);
          }
          else {
            puVar14 = (ulonglong *)puVar16[3];
          }
          if ((puVar14 != (ulonglong *)0x0) &&
             ((uVar17 == 0xffffffff || ((uVar17 & 0xf000) < 0x2001)))) {
            uVar13 = ScanBufferForInfoDisclosure
                               ((longlong)puVar10,puVar14,(ulonglong)*(uint *)(puVar16 + 5));
            if ((char)uVar13 == '\x01') {
              PrintBufferToKd((longlong)puVar10,lVar1,(ulonglong)uVar17,local_res8,puVar14,
                              (ulonglong)*(uint *)(puVar16 + 5));
              in_stack_ffffffffffffff88 = puVar14;
            }
          }
        }
      }
    }
    else if ((((((*(uint *)(lVar1 + 0x10) & 0x40) != 0) && (*(uint *)(lVar1 + 0x30) != 0x80000016))
              && ((*(uint *)(lVar1 + 0x30) & 0xc0000000) != 0xc0000000)) &&
             ((uVar17 == 0xffffffff || ((uVar17 & 0xf000) < 0x2001)))) &&
            (uVar13 = ScanBufferForInfoDisclosure
                                ((longlong)puVar10,*(ulonglong **)(lVar1 + 0x18),
                                 *(ulonglong *)(lVar1 + 0x38)), (char)uVar13 == '\x01')) {
      PrintBufferToKd((longlong)puVar10,lVar1,(ulonglong)uVar17,local_res8,
                      *(ulonglong **)(lVar1 + 0x18),*(ulonglong *)(lVar1 + 0x38));
    }
  }
LAB_1400128bf:
  if (plVar12 != (longlong *)0x0) {
    uVar8 = ExAcquireSpinLockExclusive(&IrpListLock);
    plVar2 = DAT_1400593d0;
    do {
      plVar5 = plVar2;
      if (plVar5 + -2 == (longlong *)&IrpList) goto LAB_140012903;
      plVar2 = (longlong *)*plVar5;
    } while (plVar5[-2] != lVar1);
    plVar3 = (longlong *)plVar5[1];
    if (((longlong *)plVar2[1] != plVar5) || ((longlong *)*plVar3 != plVar5)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = (longlong)plVar2;
    plVar2[1] = (longlong)plVar3;
    TrackingIrpCount = TrackingIrpCount + -1;
LAB_140012903:
    ExReleaseSpinLockExclusive(&IrpListLock,uVar8);
    ExFreePoolWithTag(plVar12,0x64497644);
  }
  if (pvVar11 != (void *)0x0) {
    ExFreePoolWithTag(pvVar11,0x64497644);
  }
  return;
}



===== PrintBufferToKd @ 140012984 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PrintBufferToKd(longlong param_1,longlong param_2,ulonglong param_3,int param_4,
                    ulonglong *param_5,ulonglong param_6)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  ulonglong uVar8;
  char *pcVar9;
  ulonglong uVar10;
  char *pcVar11;
  uint uVar12;
  ulonglong uVar13;
  size_t _Size;
  uint uVar14;
  ulonglong *puVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auStack_358 [32];
  ulonglong *local_338;
  char *local_330;
  uint local_328;
  byte local_318;
  uint local_314;
  uint local_310;
  uint local_30c;
  char *local_308;
  ulonglong local_300;
  char *local_2f8;
  ulonglong local_2f0;
  ulonglong *local_2e8;
  longlong local_2e0;
  ulonglong *local_2d8;
  longlong local_2d0;
  ulonglong local_2c8;
  ulonglong local_2c0;
  ulonglong local_2b8;
  char *local_2b0;
  undefined8 local_290;
  undefined1 local_268 [272];
  char local_158 [272];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_358;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar14 = 0;
  local_308 = (char *)0x0;
  uVar16 = 0;
  uVar12 = (uint)param_3;
  uVar10 = param_3 & 0xffffffff;
  local_2e8 = param_5;
  local_318 = 0;
  local_2d8 = param_5;
  local_30c = uVar12;
  local_2e0 = param_1;
  local_2d0 = lVar2;
  if ((XdvVerifierOptions & 0x10000) != 0) goto LAB_140012e32;
  DifUtilDbgPrint("\nInformation disclosure detected:\n");
  DifUtilDbgPrint("\tDriver Name: %S\n",*(undefined8 *)(param_1 + 8));
  DifUtilDbgPrint("\tIOCTL: 0x%08x\n\n",*(undefined4 *)(lVar2 + 0x18));
  uVar5 = KeGetCurrentIrql();
  DifUtilDbgPrint("\tIRQL: %d\n\n",uVar5);
  if (param_4 == 0) {
    if (0x5000 < (uVar12 & 0xf000)) {
      pcVar9 = "\tCaller Integrity Level: Unknown\n";
      goto LAB_140012ab1;
    }
    DifUtilDbgPrint("\tCaller Integrity Level: %s\n",
                    (&IntegrityLevelStrings)[(uint)((param_3 & 0xffffffff) >> 0xc) & 0xf]);
  }
  else {
    pcVar9 = "\tCaller Integrity Level: AppContainer\n";
LAB_140012ab1:
    DifUtilDbgPrint(pcVar9);
  }
  DifUtilDbgPrint("\n");
  uVar10 = 0x400;
  if (param_6 < 0x401) {
    uVar10 = param_6;
  }
  uVar12 = (uint)((uVar10 & 0xf) != 0) + (int)(uVar10 >> 4);
  uVar17 = uVar12 * 0x54;
  local_310 = uVar17 + 1;
  uVar13 = (ulonglong)local_310;
  local_314 = uVar12;
  local_300 = uVar10;
  local_2f8 = (char *)ExAllocatePool2(0x40,local_310,0x64497644);
  if (local_2f8 == (char *)0x0) {
    DifUtilDbgPrint("Failed to allocate buffer for output string!\n");
    return;
  }
  memset(local_2f8,0,uVar13);
  if (uVar12 != 0) {
    local_2f0 = (ulonglong)uVar12;
    pcVar9 = local_2f8;
    puVar15 = local_2d8;
    do {
      local_338 = puVar15;
      iVar7 = _snprintf_s(pcVar9,(ulonglong)uVar17,(ulonglong)uVar17,"%p: ");
      uVar17 = uVar17 - iVar7;
      pcVar9 = pcVar9 + iVar7;
      uVar13 = 0;
      while( true ) {
        uVar8 = 0x10;
        if (uVar10 < 0x10) {
          uVar8 = uVar10;
        }
        if (uVar8 <= uVar13) break;
        if ((uVar14 == 0) ||
           (uVar12 = (uint)*(byte *)(uVar13 + (longlong)puVar15),
           *(byte *)(uVar13 + (longlong)puVar15) != local_318)) {
          if (3 < uVar14) {
            *local_308 = '[';
            if (uVar13 == 0) {
              pcVar9[-0x14] = ']';
            }
            else {
              uVar16 = uVar16 + 1;
              if (uVar13 == 8) {
                pcVar9[-2] = ']';
              }
              else {
                pcVar9[-1] = ']';
              }
            }
          }
          local_308 = (char *)0x0;
          uVar14 = 0;
          bVar1 = *(byte *)(uVar13 + (longlong)puVar15);
          uVar12 = (uint)bVar1;
          if ((StartingFillPattern <= bVar1) && (bVar1 < NextFillPattern)) {
            uVar14 = 1;
            local_318 = bVar1;
            local_308 = pcVar9;
          }
        }
        else {
          uVar14 = uVar14 + 1;
        }
        local_338 = (ulonglong *)CONCAT44(local_338._4_4_,uVar12);
        iVar7 = _snprintf_s(pcVar9,(ulonglong)uVar17,(ulonglong)uVar17," %02X ");
        uVar17 = uVar17 - iVar7;
        pcVar9 = pcVar9 + iVar7;
        if (uVar13 == 7) {
          iVar7 = _snprintf_s(pcVar9,(ulonglong)uVar17,(ulonglong)uVar17," ");
          pcVar9 = pcVar9 + iVar7;
          uVar17 = uVar17 - iVar7;
        }
        uVar13 = uVar13 + 1;
      }
      iVar7 = _snprintf_s(pcVar9,(ulonglong)uVar17,(ulonglong)uVar17,"\n");
      uVar17 = uVar17 - iVar7;
      pcVar9 = pcVar9 + iVar7;
      if (uVar10 < 0x10) {
        puVar15 = (ulonglong *)((longlong)puVar15 + uVar10);
        uVar13 = uVar10;
      }
      else {
        puVar15 = puVar15 + 2;
        uVar13 = 0x10;
      }
      uVar10 = uVar10 - uVar13;
      local_2f0 = local_2f0 - 1;
    } while (local_2f0 != 0);
    uVar10 = (ulonglong)local_314;
    local_2f0 = 0;
    pcVar9 = local_2f8;
    param_1 = local_2e0;
    do {
      pcVar9 = pcVar9 + 0x12;
      uVar13 = 0x10;
      if (local_300 < 0x10) {
        uVar13 = local_300;
      }
      uVar14 = 0;
      uVar12 = (uint)(uVar13 >> 3) & 0x1fffffff;
      if ((uVar13 >> 3 & 0x1fffffff) != 0) {
        puVar15 = local_2e8;
        do {
          pcVar11 = pcVar9 + 1;
          if (uVar14 != uVar12 >> 1) {
            pcVar11 = pcVar9;
          }
          if (((*puVar15 & 0xffff000000000000) == 0xffff000000000000) &&
             (cVar6 = MmIsAddressValid(), cVar6 != '\0')) {
            *pcVar11 = '[';
            uVar16 = uVar16 + 1;
            pcVar11[0x1f] = ']';
          }
          puVar15 = puVar15 + 1;
          pcVar9 = pcVar11 + 0x20;
          uVar14 = uVar14 + 1;
        } while (uVar14 < uVar12);
        param_1 = local_2e0;
        local_2e8 = puVar15;
      }
      pcVar9 = pcVar9 + 1;
      uVar13 = 0x10;
      if (local_300 < 0x10) {
        uVar13 = local_300;
      }
      local_300 = local_300 - uVar13;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  pcVar9 = local_2f8;
  pcVar11 = local_2f8;
  uVar12 = local_310;
  do {
    _Size = (size_t)uVar12;
    if (0x100 < uVar12) {
      _Size = 0x100;
    }
    memcpy(local_268,pcVar11,_Size);
    if (0x103 < _Size) {
      __report_rangecheckfailure();
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_268[_Size] = 0;
    DifUtilDbgPrint(local_268);
    pcVar11 = pcVar11 + _Size;
    uVar12 = uVar12 - (int)_Size;
  } while (uVar12 != 0);
  ExFreePoolWithTag(pcVar9);
  if (0x400 < param_6) {
    DifUtilDbgPrint("-------------------- Truncated --------------------\n");
  }
  DifUtilDbgPrint("\n");
  uVar10 = (ulonglong)local_30c;
LAB_140012e32:
  uVar12 = *(uint *)(local_2d0 + 0x18);
  uVar3 = *(undefined8 *)(param_1 + 8);
  memset(&local_2c8,0,0x58);
  memset(local_158,0,0x104);
  pcVar9 = "Unknown";
  if (((uint)uVar10 & 0xf000) < 0x5001) {
    pcVar9 = (&IntegrityLevelStrings)[(uint)(uVar10 >> 0xc) & 0xf];
  }
  cVar6 = KeGetCurrentIrql();
  if (cVar6 == '\0') {
    local_338 = (ulonglong *)CONCAT44(local_338._4_4_,uVar16);
    local_330 = pcVar9;
    local_328 = uVar12;
    RtlStringCbPrintfA(local_158,0x104,
                       "DriverName=%S, NumberOfLeaks=%d, IntegrityLevel=%s, IoctlCode=0x%08x",uVar3)
    ;
  }
  CarInitializeRuleViolationDetails(&local_2c8);
  local_2c0 = (ulonglong)uVar16;
  local_2b0 = local_158;
  local_2c8 = (ulonglong)uVar12;
  local_2b8 = uVar10;
  local_290 = uVar3;
  iVar7 = CarReportDifPluginRuleViolation(0x26,1,0,&local_2c8);
  if (iVar7 < 0) {
    DifUtilDbgPrint("Failed to report rule violation: %x\n",iVar7);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  DifUtilDbgPrint("%S ViolationCount: %d\n",*(undefined8 *)(param_1 + 8),
                  *(undefined4 *)(param_1 + 0x18));
  return;
}



===== RtlStringCbPrintfA @ 140012f7c =====

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



===== SanitizeDeviceName @ 140012ff0 =====

void * SanitizeDeviceName(ushort *param_1)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 2,0x64497644);
  if (_Dst == (void *)0x0) {
    DifUtilDbgPrint("SanitizeDeviceName(): failed to allocate memory for driver name.");
    _Dst = (void *)0x0;
  }
  else {
    memcpy(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
    *(undefined2 *)((longlong)_Dst + (ulonglong)(*param_1 >> 1) * 2) = 0;
  }
  return _Dst;
}



===== ScanBufferForInfoDisclosure @ 140013078 =====

ulonglong ScanBufferForInfoDisclosure(longlong param_1,ulonglong *param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  
  uVar2 = 0;
  bVar6 = 0;
  if (param_1 != 0) {
    uVar5 = *(int *)(param_1 + 0x14) + 1;
    uVar1 = XdvVerifierOptions & 0x10000;
    *(uint *)(param_1 + 0x14) = uVar5;
    if ((uVar1 == 0) &&
       (register0x00000020 = (BADSPACEBASE *)((ulonglong)uVar5 * 0xcccccccd & 0xffffffff),
       uVar5 == (uVar5 / 10) * 10)) {
      register0x00000020 =
           (BADSPACEBASE *)DifUtilDbgPrint("%S ScanCount: %d\n",*(undefined8 *)(param_1 + 8));
    }
    uVar3 = 0;
    puVar4 = param_2;
    if (param_3 != 0) {
      do {
        bVar7 = (byte)*puVar4;
        register0x00000020 =
             (BADSPACEBASE *)CONCAT71((int7)((ulonglong)register0x00000020 >> 8),bVar7);
        if ((bVar7 < StartingFillPattern) || (NextFillPattern <= bVar7)) {
          uVar2 = 0;
        }
        else {
          if (bVar7 == bVar6) {
            uVar2 = uVar2 + 1;
            bVar7 = bVar6;
          }
          else {
            if (3 < uVar2) goto LAB_140013134;
            uVar2 = 1;
          }
          bVar6 = bVar7;
          if (3 < uVar2) goto LAB_140013134;
        }
        register0x00000020 = (BADSPACEBASE *)((longlong)param_2 + (param_3 - (longlong)puVar4));
        if (((((undefined1 *)0x7 < register0x00000020) && (((ulonglong)puVar4 & 7) == 0)) &&
            (register0x00000020 = (BADSPACEBASE *)(*puVar4 & 0xffff000000000000),
            (undefined1 *)register0x00000020 == (undefined1 *)0xffff000000000000)) &&
           (register0x00000020 = (BADSPACEBASE *)MmIsAddressValid(),
           (char)register0x00000020 != '\0')) {
LAB_140013134:
          return CONCAT71((int7)((ulonglong)register0x00000020 >> 8),1);
        }
        uVar3 = uVar3 + 1;
        puVar4 = (ulonglong *)((longlong)puVar4 + 1);
      } while (uVar3 < param_3);
    }
  }
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== DdiStdReportRuleViolation @ 1400131a0 =====

void DdiStdReportRuleViolation(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 local_68 [3];
  undefined8 local_50;
  
  memset(local_68,0,0x58);
  CarInitializeRuleViolationDetails(local_68);
  local_68[0] = param_1;
  local_50 = param_1;
  CarReportDifPluginRuleViolation(0x11,param_2,param_3,local_68);
  return;
}



===== DifDdiStdPluginEntry @ 140013220 =====

void DifDdiStdPluginEntry(void)

{
  int iVar1;
  
  iVar1 = CarRegisterDefaultRuleClassConfiguration(0xc4,0x11);
  if (-1 < iVar1) {
    DifRegisterPlugin(&DdiStdThunkTable,0x8f,0x11);
  }
  return;
}



===== SLIC_CmRegisterCallbackEx_entry_IrqlExApcLte2 @ 140013270 =====

void SLIC_CmRegisterCallbackEx_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CmRegisterCallbackEx should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_CmRegisterCallback_entry_IrqlExApcLte2 @ 1400132b0 =====

void SLIC_CmRegisterCallback_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CmRegisterCallback should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_CmUnRegisterCallback_entry_IrqlExApcLte2 @ 1400132f0 =====

void SLIC_CmUnRegisterCallback_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CmUnRegisterCallback should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ExAcquireFastMutex_entry_IrqlExApcLte1 @ 140013330 =====

void SLIC_ExAcquireFastMutex_entry_IrqlExApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExAcquireFastMutex should only be called at IRQL <= APC_LEVEL.",0x20005,*param_1);
  }
  return;
}



===== SLIC_ExAcquireResourceExclusiveLite_entry_IrqlExApcLte3 @ 140013370 =====

void SLIC_ExAcquireResourceExclusiveLite_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExAcquireResourceExclusiveLite should only be called at IRQL <= APC_LEVEL.",0x20007,
               *param_1);
  }
  return;
}



===== SLIC_ExAcquireResourceSharedLite_entry_IrqlExApcLte3 @ 1400133b0 =====

void SLIC_ExAcquireResourceSharedLite_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExAcquireResourceSharedLite should only be called at IRQL <= APC_LEVEL.",0x20007,
               *param_1);
  }
  return;
}



===== SLIC_ExAcquireSharedStarveExclusive_entry_IrqlExApcLte3 @ 1400133f0 =====

void SLIC_ExAcquireSharedStarveExclusive_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExAcquireSharedStarveExclusive should only be called at IRQL <= APC_LEVEL.",0x20007,
               *param_1);
  }
  return;
}



===== SLIC_ExAcquireSharedWaitForExclusive_entry_IrqlExApcLte3 @ 140013430 =====

void SLIC_ExAcquireSharedWaitForExclusive_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExAcquireSharedWaitForExclusive should only be called at IRQL <= APC_LEVEL.",0x20007
               ,*param_1);
  }
  return;
}



===== SLIC_ExAllocatePoolWithQuotaTag_internal_entry_IrqlExAllocatePool @ 140013470 =====

void SLIC_ExAllocatePoolWithQuotaTag_internal_entry_IrqlExAllocatePool(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    uVar3 = *(uint *)(param_1 + 7) & 7;
    if (uVar3 == 1) {
      pcVar4 = 
      "ExAllocatePoolWithQuotaTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPool."
      ;
    }
    else if (uVar3 == 3) {
      pcVar4 = 
      "ExAllocatePoolWithQuotaTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not DontUseThisType."
      ;
    }
    else if (uVar3 == 5) {
      pcVar4 = 
      "ExAllocatePoolWithQuotaTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPoolCacheAligned."
      ;
    }
    else {
      if (uVar3 != 7) {
        return;
      }
      pcVar4 = 
      "ExAllocatePoolWithQuotaTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not MaxPoolType."
      ;
    }
  }
  else {
    pcVar4 = "ExAllocatePoolWithQuotaTag should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  DdiStdReportRuleViolation(pcVar4,0x20004,*param_1);
  return;
}



===== SLIC_ExAllocatePoolWithQuota_internal_entry_IrqlExAllocatePool @ 140013500 =====

void SLIC_ExAllocatePoolWithQuota_internal_entry_IrqlExAllocatePool(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    uVar3 = *(uint *)(param_1 + 7) & 7;
    if (uVar3 == 1) {
      pcVar4 = 
      "ExAllocatePoolWithQuota can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPool."
      ;
    }
    else if (uVar3 == 3) {
      pcVar4 = 
      "ExAllocatePoolWithQuota can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not DontUseThisType."
      ;
    }
    else if (uVar3 == 5) {
      pcVar4 = 
      "ExAllocatePoolWithQuota can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPoolCacheAligned."
      ;
    }
    else {
      if (uVar3 != 7) {
        return;
      }
      pcVar4 = 
      "ExAllocatePoolWithQuota can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not MaxPoolType."
      ;
    }
  }
  else {
    pcVar4 = "ExAllocatePoolWithQuota should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  DdiStdReportRuleViolation(pcVar4,0x20004,*param_1);
  return;
}



===== SLIC_ExAllocatePoolWithTagPriority_internal_entry_IrqlExAllocatePool @ 140013590 =====

void SLIC_ExAllocatePoolWithTagPriority_internal_entry_IrqlExAllocatePool(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    uVar3 = *(uint *)(param_1 + 7) & 7;
    if (uVar3 == 1) {
      pcVar4 = 
      "ExAllocatePoolWithTagPriority can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPool."
      ;
    }
    else if (uVar3 == 3) {
      pcVar4 = 
      "ExAllocatePoolWithTagPriority can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not DontUseThisType."
      ;
    }
    else if (uVar3 == 5) {
      pcVar4 = 
      "ExAllocatePoolWithTagPriority can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPoolCacheAligned."
      ;
    }
    else {
      if (uVar3 != 7) {
        return;
      }
      pcVar4 = 
      "ExAllocatePoolWithTagPriority can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not MaxPoolType."
      ;
    }
  }
  else {
    pcVar4 = "ExAllocatePoolWithTagPriority should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  DdiStdReportRuleViolation(pcVar4,0x20004,*param_1);
  return;
}



===== SLIC_ExAllocatePoolWithTag_internal_entry_IrqlExAllocatePool @ 140013620 =====

void SLIC_ExAllocatePoolWithTag_internal_entry_IrqlExAllocatePool(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    uVar3 = *(uint *)(param_1 + 7) & 7;
    if (uVar3 == 1) {
      pcVar4 = 
      "ExAllocatePoolWithTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPool."
      ;
    }
    else if (uVar3 == 3) {
      pcVar4 = 
      "ExAllocatePoolWithTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not DontUseThisType."
      ;
    }
    else if (uVar3 == 5) {
      pcVar4 = 
      "ExAllocatePoolWithTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPoolCacheAligned."
      ;
    }
    else {
      if (uVar3 != 7) {
        return;
      }
      pcVar4 = 
      "ExAllocatePoolWithTag can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not MaxPoolType."
      ;
    }
  }
  else {
    pcVar4 = "ExAllocatePoolWithTag should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  DdiStdReportRuleViolation(pcVar4,0x20004,*param_1);
  return;
}



===== SLIC_ExAllocatePool_internal_entry_IrqlExAllocatePool @ 1400136b0 =====

void SLIC_ExAllocatePool_internal_entry_IrqlExAllocatePool(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 3) {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    uVar3 = *(uint *)(param_1 + 7) & 7;
    if (uVar3 == 1) {
      pcVar4 = 
      "ExAllocatePool can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPool."
      ;
    }
    else if (uVar3 == 3) {
      pcVar4 = 
      "ExAllocatePool can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not DontUseThisType."
      ;
    }
    else if (uVar3 == 5) {
      pcVar4 = 
      "ExAllocatePool can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not PagedPoolCacheAligned."
      ;
    }
    else {
      if (uVar3 != 7) {
        return;
      }
      pcVar4 = 
      "ExAllocatePool can be called at DISPATCH_LEVEL only if a NonPagedXXX is specified for PoolType, not MaxPoolType."
      ;
    }
  }
  else {
    pcVar4 = "ExAllocatePool should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  DdiStdReportRuleViolation(pcVar4,0x20004,*param_1);
  return;
}



===== SLIC_ExConvertExclusiveToSharedLite_entry_IrqlExApcLte3 @ 140013740 =====

void SLIC_ExConvertExclusiveToSharedLite_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExConvertExclusiveToSharedLite should only be called at IRQL <= APC_LEVEL.",0x20007,
               *param_1);
  }
  return;
}



===== SLIC_ExCreateCallback_entry_IrqlExApcLte2 @ 140013780 =====

void SLIC_ExCreateCallback_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExCreateCallback should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ExDeletePagedLookasideList_entry_IrqlExApcLte2 @ 1400137c0 =====

void SLIC_ExDeletePagedLookasideList_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExDeletePagedLookasideList should only be called at IRQL <= APC_LEVEL.",0x20006,
               *param_1);
  }
  return;
}



===== SLIC_ExDeleteResourceLite_entry_IrqlExApcLte3 @ 140013800 =====

void SLIC_ExDeleteResourceLite_entry_IrqlExApcLte3(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExDeleteResourceLite should only be called at IRQL <= APC_LEVEL.",0x20007,*param_1);
  }
  return;
}



===== SLIC_ExInitializePagedLookasideList_internal_entry_IrqlExApcLte2 @ 140013840 =====

void SLIC_ExInitializePagedLookasideList_internal_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExInitializePagedLookasideList should only be called at IRQL <= APC_LEVEL.",0x20006,
               *param_1);
  }
  return;
}



===== SLIC_ExIsProcessorFeaturePresent_entry_IrqlExPassive @ 140013880 =====

void SLIC_ExIsProcessorFeaturePresent_entry_IrqlExPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ExIsProcessorFeaturePresent should only be called at IRQL = PASSIVE_LEVEL.",0x20008,
               *param_1);
  }
  return;
}



===== SLIC_ExRaiseAccessViolation_entry_IrqlExPassive @ 1400138c0 =====

void SLIC_ExRaiseAccessViolation_entry_IrqlExPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ExRaiseAccessViolation should only be called at IRQL = PASSIVE_LEVEL.",0x20008,
               *param_1);
  }
  return;
}



===== SLIC_ExRaiseDatatypeMisalignment_entry_IrqlExPassive @ 140013900 =====

void SLIC_ExRaiseDatatypeMisalignment_entry_IrqlExPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ExRaiseDatatypeMisalignment should only be called at IRQL = PASSIVE_LEVEL.",0x20008,
               *param_1);
  }
  return;
}



===== SLIC_ExRaiseStatus_entry_IrqlExPassive @ 140013940 =====

void SLIC_ExRaiseStatus_entry_IrqlExPassive(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExRaiseStatus should only be called at IRQL <= APC_LEVEL.",0x20008,*param_1);
  }
  return;
}



===== SLIC_ExRegisterCallback_entry_IrqlExApcLte2 @ 140013980 =====

void SLIC_ExRegisterCallback_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExRegisterCallback should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ExSetTimerResolution_entry_IrqlExApcLte2 @ 1400139c0 =====

void SLIC_ExSetTimerResolution_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExSetTimerResolution should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ExTryToAcquireFastMutex_entry_IrqlExApcLte1 @ 140013a00 =====

void SLIC_ExTryToAcquireFastMutex_entry_IrqlExApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExTryToAcquireFastMutex should only be called at IRQL <= APC_LEVEL.",0x20005,
               *param_1);
  }
  return;
}



===== SLIC_ExUnregisterCallback_entry_IrqlExApcLte2 @ 140013a40 =====

void SLIC_ExUnregisterCallback_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ExUnregisterCallback should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ExUuidCreate_entry_IrqlExPassive @ 140013a80 =====

void SLIC_ExUuidCreate_entry_IrqlExPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ExUuidCreate should only be called at IRQL = PASSIVE_LEVEL.",0x20008,*param_1);
  }
  return;
}



===== SLIC_IoAllocateController_entry_IrqlDispatch @ 140013ac0 =====

void SLIC_IoAllocateController_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("IoAllocateController should only be called at IRQL == DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_IoAttachDevice_entry_IrqlIoPassive1 @ 140013b00 =====

void SLIC_IoAttachDevice_entry_IrqlIoPassive1(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoAttachDevice should only be called at IRQL = PASSIVE_LEVEL.",0x2000a,*param_1);
  }
  return;
}



===== SLIC_IoBuildDeviceIoControlRequest_internal_entry_IrqlIoPassive1 @ 140013b40 =====

void SLIC_IoBuildDeviceIoControlRequest_internal_entry_IrqlIoPassive1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoBuildDeviceIoControlRequest should only be called at IRQL <= APC_LEVEL.",0x2000a,
               *param_1);
  }
  return;
}



===== SLIC_IoCheckShareAccess_entry_IrqlIoPassive2 @ 140013b80 =====

void SLIC_IoCheckShareAccess_entry_IrqlIoPassive2(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCheckShareAccess should only be called at IRQL = PASSIVE_LEVEL.",0x2000b,*param_1)
    ;
  }
  return;
}



===== SLIC_IoConnectInterrupt_entry_IrqlIoPassive2 @ 140013bc0 =====

void SLIC_IoConnectInterrupt_entry_IrqlIoPassive2(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoConnectInterrupt should only be called at IRQL = PASSIVE_LEVEL.",0x2000b,*param_1)
    ;
  }
  return;
}



===== SLIC_IoCreateController_entry_IrqlIoPassive2 @ 140013c00 =====

void SLIC_IoCreateController_entry_IrqlIoPassive2(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateController should only be called at IRQL = PASSIVE_LEVEL.",0x2000b,*param_1)
    ;
  }
  return;
}



===== SLIC_IoCreateDevice_entry_IrqlIoPassive1 @ 140013c40 =====

void SLIC_IoCreateDevice_entry_IrqlIoPassive1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoCreateDevice should only be called at IRQL <= APC_LEVEL.",0x2000a,*param_1);
  }
  return;
}



===== SLIC_IoCreateFile_entry_IrqlIoPassive4 @ 140013c80 =====

void SLIC_IoCreateFile_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateFile should only be called at IRQL = PASSIVE_LEVEL.",0x2000d,*param_1);
  }
  return;
}



===== SLIC_IoCreateNotificationEvent_entry_IrqlIoPassive4 @ 140013cc0 =====

void SLIC_IoCreateNotificationEvent_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateNotificationEvent should only be called at IRQL = PASSIVE_LEVEL.",0x2000d,
               *param_1);
  }
  return;
}



===== SLIC_IoCreateSymbolicLink_entry_IrqlIoPassive3 @ 140013d00 =====

void SLIC_IoCreateSymbolicLink_entry_IrqlIoPassive3(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateSymbolicLink should only be called at IRQL = PASSIVE_LEVEL.",0x2000c,
               *param_1);
  }
  return;
}



===== SLIC_IoCreateSynchronizationEvent_entry_IrqlIoPassive4 @ 140013d40 =====

void SLIC_IoCreateSynchronizationEvent_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateSynchronizationEvent should only be called at IRQL = PASSIVE_LEVEL.",0x2000d
               ,*param_1);
  }
  return;
}



===== SLIC_IoCreateUnprotectedSymbolicLink_entry_IrqlIoPassive4 @ 140013d80 =====

void SLIC_IoCreateUnprotectedSymbolicLink_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateUnprotectedSymbolicLink should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000d,*param_1);
  }
  return;
}



===== SLIC_IoDeleteController_entry_IrqlIoPassive4 @ 140013dc0 =====

void SLIC_IoDeleteController_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoDeleteController should only be called at IRQL = PASSIVE_LEVEL.",0x2000d,*param_1)
    ;
  }
  return;
}



===== SLIC_IoDeleteDevice_entry_IrqlIoApcLte @ 140013e00 =====

void SLIC_IoDeleteDevice_entry_IrqlIoApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoDeleteDevice should only be called at IRQL <= APC_LEVEL.",0x20009,*param_1);
  }
  return;
}



===== SLIC_IoDeleteSymbolicLink_entry_IrqlIoPassive4 @ 140013e40 =====

void SLIC_IoDeleteSymbolicLink_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoDeleteSymbolicLink should only be called at IRQL = PASSIVE_LEVEL.",0x2000d,
               *param_1);
  }
  return;
}



===== SLIC_IoDetachDevice_entry_IrqlIoPassive3 @ 140013e80 =====

void SLIC_IoDetachDevice_entry_IrqlIoPassive3(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoDetachDevice should only be called at IRQL = PASSIVE_LEVEL.",0x2000c,*param_1);
  }
  return;
}



===== SLIC_IoDisconnectInterrupt_entry_IrqlIoPassive4 @ 140013ec0 =====

void SLIC_IoDisconnectInterrupt_entry_IrqlIoPassive4(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoDisconnectInterrupt should only be called at IRQL = PASSIVE_LEVEL.",0x2000d,
               *param_1);
  }
  return;
}



===== SLIC_IoFreeController_entry_IrqlDispatch @ 140013f00 =====

void SLIC_IoFreeController_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("IoFreeController should only be called at IRQL == DISPATCH_LEVEL.",0x20003,*param_1)
    ;
  }
  return;
}



===== SLIC_IoGetConfigurationInformation_entry_IrqlIoPassive5 @ 140013f40 =====

void SLIC_IoGetConfigurationInformation_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetConfigurationInformation should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoGetDeviceObjectPointer_entry_IrqlIoPassive5 @ 140013f80 =====

void SLIC_IoGetDeviceObjectPointer_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetDeviceObjectPointer should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoGetDeviceToVerify_entry_IrqlIoDispatch @ 140013fc0 =====

void SLIC_IoGetDeviceToVerify_entry_IrqlIoDispatch(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("IoGetDeviceToVerify should only be called at IRQL <= DISPATCH_LEVEL.",0x20022,
               *param_1);
  }
  return;
}



===== SLIC_IoGetDmaAdapter_entry_IrqlIoPassive5 @ 140014000 =====

void SLIC_IoGetDmaAdapter_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetDmaAdapter should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoGetFileObjectGenericMapping_entry_IrqlIoPassive5 @ 140014040 =====

void SLIC_IoGetFileObjectGenericMapping_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetFileObjectGenericMapping should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoGetInitialStack_entry_IrqlIoApcLte @ 140014080 =====

void SLIC_IoGetInitialStack_entry_IrqlIoApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoGetInitialStack should only be called at IRQL <= APC_LEVEL.",0x20009,*param_1);
  }
  return;
}



===== SLIC_IoInitializeTimer_entry_IrqlIoPassive5 @ 1400140c0 =====

void SLIC_IoInitializeTimer_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoInitializeTimer should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoIsWdmVersionAvailable_entry_IrqlIoPassive5 @ 140014100 =====

void SLIC_IoIsWdmVersionAvailable_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoIsWdmVersionAvailable should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoRaiseHardError_entry_IrqlIoApcLte @ 140014140 =====

void SLIC_IoRaiseHardError_entry_IrqlIoApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoRaiseHardError should only be called at IRQL <= APC_LEVEL.",0x20009,*param_1);
  }
  return;
}



===== SLIC_IoRaiseInformationalHardError_entry_IrqlIoApcLte @ 140014180 =====

void SLIC_IoRaiseInformationalHardError_entry_IrqlIoApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("IoRaiseInformationalHardError should only be called at IRQL <= APC_LEVEL.",0x20009,
               *param_1);
  }
  return;
}



===== SLIC_IoReadPartitionTable_entry_IrqlIoPassive5 @ 1400141c0 =====

void SLIC_IoReadPartitionTable_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoReadPartitionTable should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoRegisterDeviceInterface_entry_IrqlIoPassive3 @ 140014200 =====

void SLIC_IoRegisterDeviceInterface_entry_IrqlIoPassive3(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoRegisterDeviceInterface should only be called at IRQL = PASSIVE_LEVEL.",0x2000c,
               *param_1);
  }
  return;
}



===== SLIC_IoRegisterDriverReinitialization_entry_IrqlIoPassive5 @ 140014240 =====

void SLIC_IoRegisterDriverReinitialization_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoRegisterDriverReinitialization should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoRegisterShutdownNotification_entry_IrqlIoPassive5 @ 140014280 =====

void SLIC_IoRegisterShutdownNotification_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoRegisterShutdownNotification should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoRemoveShareAccess_entry_IrqlIoPassive5 @ 1400142c0 =====

void SLIC_IoRemoveShareAccess_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoRemoveShareAccess should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,*param_1
              );
  }
  return;
}



===== SLIC_IoSetDeviceInterfaceState_entry_IrqlIoPassive1 @ 140014300 =====

void SLIC_IoSetDeviceInterfaceState_entry_IrqlIoPassive1(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoSetDeviceInterfaceState should only be called at IRQL = PASSIVE_LEVEL.",0x2000a,
               *param_1);
  }
  return;
}



===== SLIC_IoSetDeviceToVerify_entry_IrqlIoDispatch @ 140014340 =====

void SLIC_IoSetDeviceToVerify_entry_IrqlIoDispatch(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("IoSetDeviceToVerify should only be called at IRQL <= DISPATCH_LEVEL.",0x20022,
               *param_1);
  }
  return;
}



===== SLIC_IoSetPartitionInformation_entry_IrqlIoPassive5 @ 140014380 =====

void SLIC_IoSetPartitionInformation_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoSetPartitionInformation should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoSetShareAccess_entry_IrqlIoPassive5 @ 1400143c0 =====

void SLIC_IoSetShareAccess_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoSetShareAccess should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoStartNextPacket_entry_IrqlDispatch @ 140014400 =====

void SLIC_IoStartNextPacket_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("IoStartNextPacket should only be called at IRQL == DISPATCH_LEVEL.",0x20003,*param_1
              );
  }
  return;
}



===== SLIC_IoUnregisterShutdownNotification_entry_IrqlIoPassive5 @ 140014440 =====

void SLIC_IoUnregisterShutdownNotification_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoUnregisterShutdownNotification should only be called at IRQL = PASSIVE_LEVEL.",
               0x2000e,*param_1);
  }
  return;
}



===== SLIC_IoUpdateShareAccess_entry_IrqlIoPassive5 @ 140014480 =====

void SLIC_IoUpdateShareAccess_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoUpdateShareAccess should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,*param_1
              );
  }
  return;
}



===== SLIC_IoWMIAllocateInstanceIds_entry_IrqlIoPassive5 @ 1400144c0 =====

void SLIC_IoWMIAllocateInstanceIds_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoWMIAllocateInstanceIds should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoWMIRegistrationControl_entry_IrqlIoPassive5 @ 140014500 =====

void SLIC_IoWMIRegistrationControl_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoWMIRegistrationControl should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IoWriteErrorLogEntry_entry_IrqlDispatch @ 140014540 =====

void SLIC_IoWriteErrorLogEntry_entry_IrqlDispatch(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("IoWriteErrorLogEntry should only be called at IRQL <= DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_IoWritePartitionTable_entry_IrqlIoPassive5 @ 140014580 =====

void SLIC_IoWritePartitionTable_entry_IrqlIoPassive5(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoWritePartitionTable should only be called at IRQL = PASSIVE_LEVEL.",0x2000e,
               *param_1);
  }
  return;
}



===== SLIC_IofCompleteRequest_entry_PnpRemove @ 1400145c0 =====

void SLIC_IofCompleteRequest_entry_PnpRemove(undefined8 *param_1)

{
  byte bVar1;
  longlong lVar2;
  
  lVar2 = param_1[2];
  if ((((*(int *)(lVar2 + 0x30) != 0) && (*(char *)(lVar2 + 0x43) <= *(char *)(lVar2 + 0x42))) &&
      (**(char **)(lVar2 + 0xb8) == '\x1b')) &&
     ((bVar1 = (*(char **)(lVar2 + 0xb8))[1], bVar1 < 0x18 &&
      ((0x80004cU >> (bVar1 & 0x1f) & 1) != 0)))) {
    DdiStdReportRuleViolation("The IRP can only be completed with STATUS_SUCCESS.",0x43006,*param_1)
    ;
  }
  return;
}



===== SLIC_KeAcquireGuardedMutexUnsafe_entry_IrqlKeApcLte1 @ 140014620 =====

void SLIC_KeAcquireGuardedMutexUnsafe_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeAcquireGuardedMutexUnsafe should only be called at IRQL <= APC_LEVEL.",0x2000f,
               *param_1);
  }
  return;
}



===== SLIC_KeAcquireGuardedMutex_entry_IrqlKeApcLte1 @ 140014660 =====

void SLIC_KeAcquireGuardedMutex_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeAcquireGuardedMutex should only be called at IRQL <= APC_LEVEL.",0x2000f,*param_1)
    ;
  }
  return;
}



===== SLIC_KeAcquireSpinLockAtDpcLevel_entry_IrqlKeAcquireReleaseSpinLock @ 1400146a0 =====

void SLIC_KeAcquireSpinLockAtDpcLevel_entry_IrqlKeAcquireReleaseSpinLock(undefined8 *param_1)

{
  byte bVar1;
  byte in_IF;
  
  bVar1 = KeGetCurrentIrql();
  if ((bVar1 < 2) && ((in_IF & 1) != 0)) {
    DdiStdReportRuleViolation
              ("KeAcquireSpinLockAtDpcLevel should only be called at IRQL >= DISPATCH_LEVEL.",
               0x20015,*param_1);
  }
  return;
}



===== SLIC_KeAcquireSpinLockRaiseToDpc_entry_IrqlKeAcquireReleaseSpinLock @ 1400146f0 =====

void SLIC_KeAcquireSpinLockRaiseToDpc_entry_IrqlKeAcquireReleaseSpinLock(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeAcquireSpinLockRaiseToDpc should only be called at IRQL <= DISPATCH_LEVEL.",
               0x20015,*param_1);
  }
  return;
}



===== SLIC_KeCancelTimer_entry_IrqlKeDispatchLte @ 140014730 =====

void SLIC_KeCancelTimer_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeCancelTimer should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeClearEvent_entry_IrqlKeDispatchLte @ 140014770 =====

void SLIC_KeClearEvent_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeClearEvent should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeDelayExecutionThread_entry_IrqlKeApcLte1 @ 1400147b0 =====

void SLIC_KeDelayExecutionThread_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeDelayExecutionThread should only be called at IRQL <= APC_LEVEL.",0x2000f,*param_1
              );
  }
  return;
}



===== SLIC_KeDeregisterNmiCallback_entry_IrqlKeApcLte2 @ 1400147f0 =====

void SLIC_KeDeregisterNmiCallback_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeDeregisterNmiCallback should only be called at IRQL <= APC_LEVEL.",0x20010,
               *param_1);
  }
  return;
}



===== SLIC_KeEnterCriticalRegion_entry_IrqlKeApcLte2 @ 140014830 =====

void SLIC_KeEnterCriticalRegion_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeEnterCriticalRegion should only be called at IRQL <= APC_LEVEL.",0x20010,*param_1)
    ;
  }
  return;
}



===== SLIC_KeEnterGuardedRegion_entry_IrqlKeApcLte2 @ 140014870 =====

void SLIC_KeEnterGuardedRegion_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeEnterGuardedRegion should only be called at IRQL <= APC_LEVEL.",0x20010,*param_1);
  }
  return;
}



===== SLIC_KeInitializeDeviceQueue_entry_IrqlKeDispatchLte @ 1400148b0 =====

void SLIC_KeInitializeDeviceQueue_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeInitializeDeviceQueue should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,
               *param_1);
  }
  return;
}



===== SLIC_KeInitializeSemaphore_entry_IrqlKeDispatchLte @ 1400148f0 =====

void SLIC_KeInitializeSemaphore_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeInitializeSemaphore should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,
               *param_1);
  }
  return;
}



===== SLIC_KeInitializeTimerEx_entry_IrqlKeDispatchLte @ 140014930 =====

void SLIC_KeInitializeTimerEx_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeInitializeTimerEx should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,
               *param_1);
  }
  return;
}



===== SLIC_KeInitializeTimer_entry_IrqlKeDispatchLte @ 140014970 =====

void SLIC_KeInitializeTimer_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeInitializeTimer should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1
              );
  }
  return;
}



===== SLIC_KeInsertByKeyDeviceQueue_entry_IrqlDispatch @ 1400149b0 =====

void SLIC_KeInsertByKeyDeviceQueue_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("KeInsertByKeyDeviceQueue should only be called at IRQL == DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_KeInsertDeviceQueue_entry_IrqlDispatch @ 1400149f0 =====

void SLIC_KeInsertDeviceQueue_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("KeInsertDeviceQueue should only be called at IRQL == DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_KeLeaveCriticalRegion_entry_IrqlKeApcLte2 @ 140014a30 =====

void SLIC_KeLeaveCriticalRegion_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeLeaveCriticalRegion should only be called at IRQL <= APC_LEVEL.",0x20010,*param_1)
    ;
  }
  return;
}



===== SLIC_KeLeaveGuardedRegion_entry_IrqlKeApcLte2 @ 140014a70 =====

void SLIC_KeLeaveGuardedRegion_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeLeaveGuardedRegion should only be called at IRQL <= APC_LEVEL.",0x20010,*param_1);
  }
  return;
}



===== SLIC_KePulseEvent_entry_IrqlKeDispatchLte @ 140014ab0 =====

void SLIC_KePulseEvent_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KePulseEvent should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeReadStateEvent_entry_IrqlKeDispatchLte @ 140014af0 =====

void SLIC_KeReadStateEvent_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeReadStateEvent should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1)
    ;
  }
  return;
}



===== SLIC_KeReadStateTimer_entry_IrqlKeDispatchLte @ 140014b30 =====

void SLIC_KeReadStateTimer_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeReadStateTimer should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1)
    ;
  }
  return;
}



===== SLIC_KeRegisterNmiCallback_entry_IrqlKeApcLte2 @ 140014b70 =====

void SLIC_KeRegisterNmiCallback_entry_IrqlKeApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeRegisterNmiCallback should only be called at IRQL <= APC_LEVEL.",0x20010,*param_1)
    ;
  }
  return;
}



===== SLIC_KeReleaseGuardedMutexUnsafe_entry_IrqlKeApcLte1 @ 140014bb0 =====

void SLIC_KeReleaseGuardedMutexUnsafe_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeReleaseGuardedMutexUnsafe should only be called at IRQL <= APC_LEVEL.",0x2000f,
               *param_1);
  }
  return;
}



===== SLIC_KeReleaseGuardedMutex_entry_IrqlKeApcLte1 @ 140014bf0 =====

void SLIC_KeReleaseGuardedMutex_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeReleaseGuardedMutex should only be called at IRQL <= APC_LEVEL.",0x2000f,*param_1)
    ;
  }
  return;
}



===== SLIC_KeReleaseMutex_entry_IrqlKeDispatchLte @ 140014c30 =====

void SLIC_KeReleaseMutex_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeReleaseMutex should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeReleaseSpinLockFromDpcLevel_entry_IrqlKeAcquireReleaseSpinLock @ 140014c70 =====

void SLIC_KeReleaseSpinLockFromDpcLevel_entry_IrqlKeAcquireReleaseSpinLock(undefined8 *param_1)

{
  byte bVar1;
  byte in_IF;
  
  bVar1 = KeGetCurrentIrql();
  if ((bVar1 < 2) && ((in_IF & 1) != 0)) {
    DdiStdReportRuleViolation
              ("KeReleaseSpinLockFromDpcLevel should only be called at IRQL >= DISPATCH_LEVEL.",
               0x20015,*param_1);
  }
  return;
}



===== SLIC_KeReleaseSpinLock_entry_IrqlKeAcquireReleaseSpinLock @ 140014cc0 =====

void SLIC_KeReleaseSpinLock_entry_IrqlKeAcquireReleaseSpinLock(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("KeReleaseSpinLock should only be called at IRQL = DISPATCH_LEVEL.",0x20015,*param_1)
    ;
  }
  return;
}



===== SLIC_KeRemoveByKeyDeviceQueue_entry_IrqlDispatch @ 140014d00 =====

void SLIC_KeRemoveByKeyDeviceQueue_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("KeRemoveByKeyDeviceQueue should only be called at IRQL == DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_KeRemoveDeviceQueue_entry_IrqlDispatch @ 140014d40 =====

void SLIC_KeRemoveDeviceQueue_entry_IrqlDispatch(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\x02') {
    DdiStdReportRuleViolation
              ("KeRemoveDeviceQueue should only be called at IRQL == DISPATCH_LEVEL.",0x20003,
               *param_1);
  }
  return;
}



===== SLIC_KeRemoveEntryDeviceQueue_entry_IrqlKeDispatchLte @ 140014d80 =====

void SLIC_KeRemoveEntryDeviceQueue_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeRemoveEntryDeviceQueue should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,
               *param_1);
  }
  return;
}



===== SLIC_KeResetEvent_entry_IrqlKeDispatchLte @ 140014dc0 =====

void SLIC_KeResetEvent_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeResetEvent should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeSetEvent_entry_IrqlKeSetEvent @ 140014e00 =====

void SLIC_KeSetEvent_entry_IrqlKeSetEvent(undefined8 *param_1)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
  if (*(char *)(param_1 + 1) == '\0') {
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 3) {
      return;
    }
    pcVar3 = "KeSetEvent should only be called at IRQL <= DISPATCH_LEVEL.";
  }
  else {
    cVar2 = KeGetCurrentIrql();
    if (cVar2 != '\x02') {
      return;
    }
    pcVar3 = "KeSetEvent should only be called at IRQL <= APC_LEVEL when Wait is set to TRUE.";
  }
  DdiStdReportRuleViolation(pcVar3,0x20016,*param_1);
  return;
}



===== SLIC_KeSetTimerEx_entry_IrqlKeDispatchLte @ 140014e60 =====

void SLIC_KeSetTimerEx_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeSetTimerEx should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeSetTimer_entry_IrqlKeDispatchLte @ 140014ea0 =====

void SLIC_KeSetTimer_entry_IrqlKeDispatchLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("KeSetTimer should only be called at IRQL <= DISPATCH_LEVEL.",0x20011,*param_1);
  }
  return;
}



===== SLIC_KeTryToAcquireGuardedMutex_entry_IrqlKeApcLte1 @ 140014ee0 =====

void SLIC_KeTryToAcquireGuardedMutex_entry_IrqlKeApcLte1(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("KeTryToAcquireGuardedMutex should only be called at IRQL <= APC_LEVEL.",0x2000f,
               *param_1);
  }
  return;
}



===== SLIC_MmAllocateNonCachedMemory_entry_IrqlMmApcLte @ 140014f20 =====

void SLIC_MmAllocateNonCachedMemory_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmAllocateNonCachedMemory should only be called at IRQL <= APC_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmAllocatePagesForMdlEx_entry_IrqlMmApcLte @ 140014f60 =====

void SLIC_MmAllocatePagesForMdlEx_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("MmAllocatePagesForMdlEx should only be called at IRQL <= DISPATCH_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmAllocatePagesForMdl_entry_IrqlMmApcLte @ 140014fa0 =====

void SLIC_MmAllocatePagesForMdl_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("MmAllocatePagesForMdl should only be called at IRQL <= DISPATCH_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmFreeContiguousMemory_entry_IrqlMmDispatch @ 140014fe0 =====

void SLIC_MmFreeContiguousMemory_entry_IrqlMmDispatch(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("MmFreeContiguousMemory should only be called at IRQL <= DISPATCH_LEVEL.",0x2001a,
               *param_1);
  }
  return;
}



===== SLIC_MmFreeNonCachedMemory_entry_IrqlMmApcLte @ 140015020 =====

void SLIC_MmFreeNonCachedMemory_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmFreeNonCachedMemory should only be called at IRQL <= APC_LEVEL.",0x20019,*param_1)
    ;
  }
  return;
}



===== SLIC_MmFreePagesFromMdl_entry_IrqlMmApcLte @ 140015060 =====

void SLIC_MmFreePagesFromMdl_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    DdiStdReportRuleViolation
              ("MmFreePagesFromMdl should only be called at IRQL <= DISPATCH_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmLockPagableDataSection_entry_IrqlMmApcLte @ 1400150a0 =====

void SLIC_MmLockPagableDataSection_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmLockPagableDataSection should only be called at IRQL <= APC_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmLockPagableSectionByHandle_entry_IrqlMmApcLte @ 1400150e0 =====

void SLIC_MmLockPagableSectionByHandle_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmLockPagableSectionByHandle should only be called at IRQL <= APC_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmPageEntireDriver_entry_IrqlMmApcLte @ 140015120 =====

void SLIC_MmPageEntireDriver_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmPageEntireDriver should only be called at IRQL <= APC_LEVEL.",0x20019,*param_1);
  }
  return;
}



===== SLIC_MmResetDriverPaging_entry_IrqlMmApcLte @ 140015160 =====

void SLIC_MmResetDriverPaging_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmResetDriverPaging should only be called at IRQL <= APC_LEVEL.",0x20019,*param_1);
  }
  return;
}



===== SLIC_MmSecureVirtualMemory_entry_IrqlMmApcLte @ 1400151a0 =====

void SLIC_MmSecureVirtualMemory_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmSecureVirtualMemory should only be called at IRQL <= APC_LEVEL.",0x20019,*param_1)
    ;
  }
  return;
}



===== SLIC_MmUnlockPagableImageSection_entry_IrqlMmApcLte @ 1400151e0 =====

void SLIC_MmUnlockPagableImageSection_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmUnlockPagableImageSection should only be called at IRQL <= APC_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_MmUnsecureVirtualMemory_entry_IrqlMmApcLte @ 140015220 =====

void SLIC_MmUnsecureVirtualMemory_entry_IrqlMmApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("MmUnsecureVirtualMemory should only be called at IRQL <= APC_LEVEL.",0x20019,
               *param_1);
  }
  return;
}



===== SLIC_ObGetObjectSecurity_entry_IrqlApcLte @ 140015260 =====

void SLIC_ObGetObjectSecurity_entry_IrqlApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ObGetObjectSecurity should only be called at IRQL <= APC_LEVEL.",0x20002,*param_1);
  }
  return;
}



===== SLIC_ObReferenceObjectByHandle_entry_IrqlObPassive @ 1400152a0 =====

void SLIC_ObReferenceObjectByHandle_entry_IrqlObPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ObReferenceObjectByHandle should only be called at IRQL = PASSIVE_LEVEL.",0x2001b,
               *param_1);
  }
  return;
}



===== SLIC_ObReleaseObjectSecurity_entry_IrqlApcLte @ 1400152e0 =====

void SLIC_ObReleaseObjectSecurity_entry_IrqlApcLte(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ObReleaseObjectSecurity should only be called at IRQL <= APC_LEVEL.",0x20002,
               *param_1);
  }
  return;
}



===== SLIC_PoRequestPowerIrp_entry_RequestedPowerIrp @ 140015320 =====

void SLIC_PoRequestPowerIrp_entry_RequestedPowerIrp(undefined8 *param_1)

{
  if ((*(char *)((longlong)param_1 + 0x24) != '\0') && (param_1[1] != 0)) {
    DdiStdReportRuleViolation
              ("The last parameter of PoRequestPowerIrp must be null.",0x4100b,*param_1);
  }
  return;
}



===== SLIC_ProbeForRead_entry_IrqlExApcLte2 @ 140015360 =====

void SLIC_ProbeForRead_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ProbeForRead should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_ProbeForWrite_entry_IrqlExApcLte2 @ 1400153a0 =====

void SLIC_ProbeForWrite_entry_IrqlExApcLte2(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("ProbeForWrite should only be called at IRQL <= APC_LEVEL.",0x20006,*param_1);
  }
  return;
}



===== SLIC_PsCreateSystemThread_entry_IrqlPsPassive @ 1400153e0 =====

void SLIC_PsCreateSystemThread_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsCreateSystemThread should only be called at IRQL = PASSIVE_LEVEL.",0x2001c,
               *param_1);
  }
  return;
}



===== SLIC_PsGetVersion_entry_IrqlPsPassive @ 140015420 =====

void SLIC_PsGetVersion_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsGetVersion should only be called at IRQL = PASSIVE_LEVEL.",0x2001c,*param_1);
  }
  return;
}



===== SLIC_PsSetCreateProcessNotifyRoutine_entry_IrqlPsPassive @ 140015460 =====

void SLIC_PsSetCreateProcessNotifyRoutine_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsSetCreateProcessNotifyRoutine should only be called at IRQL = PASSIVE_LEVEL.",
               0x2001c,*param_1);
  }
  return;
}



===== SLIC_PsSetCreateThreadNotifyRoutine_entry_IrqlPsPassive @ 1400154a0 =====

void SLIC_PsSetCreateThreadNotifyRoutine_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsSetCreateThreadNotifyRoutine should only be called at IRQL = PASSIVE_LEVEL.",
               0x2001c,*param_1);
  }
  return;
}



===== SLIC_PsSetLoadImageNotifyRoutine_entry_IrqlPsPassive @ 1400154e0 =====

void SLIC_PsSetLoadImageNotifyRoutine_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsSetLoadImageNotifyRoutine should only be called at IRQL = PASSIVE_LEVEL.",0x2001c,
               *param_1);
  }
  return;
}



===== SLIC_PsTerminateSystemThread_entry_IrqlPsPassive @ 140015520 =====

void SLIC_PsTerminateSystemThread_entry_IrqlPsPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("PsTerminateSystemThread should only be called at IRQL = PASSIVE_LEVEL.",0x2001c,
               *param_1);
  }
  return;
}



===== SLIC_RtlDeleteRegistryValue_entry_IrqlRtlPassive @ 140015560 =====

void SLIC_RtlDeleteRegistryValue_entry_IrqlRtlPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("RtlDeleteRegistryValue should only be called at IRQL = PASSIVE_LEVEL.",0x2001e,
               *param_1);
  }
  return;
}



===== SLIC_ZwClose_entry_IrqlZwPassive @ 1400155a0 =====

void SLIC_ZwClose_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwClose should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwCreateKey_entry_IrqlZwPassive @ 1400155e0 =====

void SLIC_ZwCreateKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwCreateKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwDeleteKey_entry_IrqlZwPassive @ 140015620 =====

void SLIC_ZwDeleteKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwDeleteKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwEnumerateKey_entry_IrqlZwPassive @ 140015660 =====

void SLIC_ZwEnumerateKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwEnumerateKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwEnumerateValueKey_entry_IrqlZwPassive @ 1400156a0 =====

void SLIC_ZwEnumerateValueKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwEnumerateValueKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1
              );
  }
  return;
}



===== SLIC_ZwFlushKey_entry_IrqlZwPassive @ 1400156e0 =====

void SLIC_ZwFlushKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwFlushKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwOpenKey_entry_IrqlZwPassive @ 140015720 =====

void SLIC_ZwOpenKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwOpenKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwQueryKey_entry_IrqlZwPassive @ 140015760 =====

void SLIC_ZwQueryKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwQueryKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwQueryValueKey_entry_IrqlZwPassive @ 1400157a0 =====

void SLIC_ZwQueryValueKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwQueryValueKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== SLIC_ZwSetValueKey_entry_IrqlZwPassive @ 1400157e0 =====

void SLIC_ZwSetValueKey_entry_IrqlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwSetValueKey should only be called at IRQL = PASSIVE_LEVEL.",0x2001f,*param_1);
  }
  return;
}



===== DifDdiStatefulPluginEntry @ 140015820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifDdiStatefulPluginEntry(void)

{
  undefined1 auStack_2d8 [32];
  char *local_2b8;
  undefined4 local_2b0;
  code *local_2a8;
  code *local_2a0;
  char *local_298;
  undefined4 local_290;
  code *local_288;
  code *local_280;
  char *local_278;
  undefined4 local_270;
  code *local_268;
  code *local_260;
  char *local_258;
  undefined4 local_250;
  undefined8 local_248;
  code *local_240;
  char *local_238;
  undefined4 local_230;
  undefined8 local_228;
  code *local_220;
  char *local_218;
  undefined4 local_210;
  undefined8 local_208;
  code *local_200;
  char *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1e8;
  code *local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  undefined8 local_1c8;
  code *local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  undefined8 local_1a0;
  char *local_198;
  undefined4 local_190;
  code *local_188;
  undefined8 local_180;
  char *local_178;
  undefined4 local_170;
  undefined8 local_168;
  code *local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  undefined8 local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  undefined8 local_120;
  char *local_118;
  undefined4 local_110;
  code *local_108;
  undefined8 local_100;
  char *local_f8;
  undefined4 local_f0;
  code *local_e8;
  undefined8 local_e0;
  char *local_d8;
  undefined4 local_d0;
  code *local_c8;
  undefined8 local_c0;
  char *local_b8;
  undefined4 local_b0;
  code *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_2d8;
  local_2b0 = 0x1000001e;
  local_290 = 0x1000000e;
  local_2b8 = "AddDevice";
  local_2a8 = Ds_AddDevice_Entry;
  local_2a0 = Ds_IRP_MJ_DEVICE_CONTROL_Exit;
  local_298 = "IRP_MJ_DEVICE_CONTROL";
  local_288 = Ds_IRP_MJ_DEVICE_CONTROL_Entry;
  local_280 = Ds_IRP_MJ_DEVICE_CONTROL_Exit;
  local_278 = "DriverEntry";
  local_268 = Ds_AddDevice_Entry;
  local_260 = Ds_IRP_MJ_DEVICE_CONTROL_Exit;
  local_258 = "KeAcquireSpinLockAtDpcLevel";
  local_240 = Ds_KeAcquireSpinLockAtDpcLevel_Exit;
  local_238 = "KeReleaseSpinLockFromDpcLevel";
  local_220 = Ds_KeReleaseSpinLockFromDpcLevel_Exit;
  local_218 = "KeAcquireSpinLockRaiseToDpc";
  local_200 = Ds_KeReleaseSpinLockFromDpcLevel_Exit;
  local_1f8 = "KeReleaseSpinLock";
  local_1e0 = Ds_KeReleaseSpinLockFromDpcLevel_Exit;
  local_1d8 = "KeTryToAcquireSpinLockAtDpcLevel";
  local_1c0 = Ds_KeTryToAcquireSpinLockAtDpcLevel_Exit;
  local_1b8 = "KeAcquireInStackQueuedSpinLockAtDpcLevel";
  local_1a8 = Ds_KeAcquireInStackQueuedSpinLock_Exit;
  local_198 = "KeReleaseInStackQueuedSpinLockFromDpcLevel";
  local_188 = Ds_KeReleaseInStackQueuedSpinLock_Entry;
  local_178 = "KeAcquireInStackQueuedSpinLock";
  local_160 = Ds_KeAcquireInStackQueuedSpinLock_Exit;
  local_158 = "KeReleaseInStackQueuedSpinLock";
  local_148 = Ds_KeReleaseInStackQueuedSpinLock_Entry;
  local_138 = "KeLeaveCriticalRegion";
  local_128 = Ds_ExReleaseResourceAndLeaveCriticalRegion_Entry;
  local_270 = 0x1000001c;
  local_250 = 0x124;
  local_248 = 0;
  local_230 = 0x101;
  local_228 = 0;
  local_210 = 0x123;
  local_208 = 0;
  local_1f0 = 0x102;
  local_1e8 = 0;
  local_1d0 = 0xf2;
  local_1c8 = 0;
  local_1b0 = 0x129;
  local_1a0 = 0;
  local_190 = 0x106;
  local_180 = 0;
  local_170 = 0x12a;
  local_168 = 0;
  local_150 = 0x108;
  local_140 = 0;
  local_130 = 0x112;
  local_120 = 0;
  local_118 = "KeEnterCriticalRegion";
  local_108 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_f8 = "ExEnterPriorityRegionAndAcquireResourceExclusive";
  local_e8 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_d8 = "ExEnterPriorityRegionAndAcquireResourceShared";
  local_c8 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_b8 = "ExEnterCriticalRegionAndAcquireResourceExclusive";
  local_a8 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_98 = "ExEnterCriticalRegionAndAcquireResourceShared";
  local_88 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_78 = "ExEnterCriticalRegionAndAcquireSharedWaitForExclusive";
  local_68 = Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry;
  local_58 = "ExReleaseResourceAndLeavePriorityRegion";
  local_48 = Ds_ExReleaseResourceAndLeaveCriticalRegion_Entry;
  local_38 = "ExReleaseResourceAndLeaveCriticalRegion";
  local_28 = Ds_ExReleaseResourceAndLeaveCriticalRegion_Entry;
  local_110 = 0x11e;
  local_100 = 0;
  local_f0 = 0x193;
  local_e0 = 0;
  local_d0 = 0x192;
  local_c0 = 0;
  local_b0 = 0x196;
  local_a0 = 0;
  local_90 = 0x195;
  local_80 = 0;
  local_70 = 0x194;
  local_60 = 0;
  local_50 = 0x183;
  local_40 = 0;
  local_30 = 0x184;
  local_20 = 0;
  DifRegisterPlugin(&local_2b8,0x15,0x13,0);
  return;
}



===== DsCheckOrDecrementTracker @ 140015bcc =====

void DsCheckOrDecrementTracker(int param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int *piVar2;
  undefined8 local_68 [3];
  undefined8 local_50;
  
  piVar2 = (int *)DifFindThreadContextData(0x13);
  if (piVar2 == (int *)0x0) {
    return;
  }
  if (param_1 == 0) {
    if (0 < *piVar2) {
      *piVar2 = *piVar2 + -1;
      return;
    }
  }
  else {
    if (param_1 != 1) {
      return;
    }
    if (0 < piVar2[1]) {
      piVar2[1] = piVar2[1] + -1;
      return;
    }
  }
  uVar1 = *(undefined8 *)(*(longlong *)(piVar2 + 4) + 0x18);
  memset(local_68,0,0x58);
  CarInitializeRuleViolationDetails(local_68);
  local_68[0] = param_3;
  local_50 = param_3;
  CarReportDifPluginRuleViolation(0x20,param_2,uVar1,local_68);
  return;
}



===== DsIncrementTracker @ 140015c94 =====

undefined8 DsIncrementTracker(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  piVar2 = (int *)DifFindThreadContextData(0x13);
  uVar3 = 0;
  if (piVar2 != (int *)0x0) {
    if (param_1 == 0) {
      *piVar2 = *piVar2 + 1;
    }
    else if (param_1 == 1) {
      iVar1 = piVar2[1];
      piVar2[1] = iVar1 + 1U;
      piVar2 = (int *)(ulonglong)(iVar1 + 1U);
    }
    else if (param_1 == 2) {
      iVar1 = piVar2[2];
      piVar2[2] = iVar1 + 1U;
      piVar2 = (int *)(ulonglong)(iVar1 + 1U);
    }
    uVar3 = CONCAT71((int7)((ulonglong)piVar2 >> 8),1);
  }
  return uVar3;
}



===== Ds_AddDevice_Entry @ 140015cf0 =====

void Ds_AddDevice_Entry(longlong param_1)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_18 = *(undefined8 *)(param_1 + 0x10);
  local_28 = 0;
  local_20 = 0;
  DifPushThreadContextData(0x13,&local_28);
  return;
}



===== Ds_IRP_MJ_DEVICE_CONTROL_Exit @ 140015d30 =====

void Ds_IRP_MJ_DEVICE_CONTROL_Exit(void)

{
  DifPopThreadContextData(0x13,0,0);
  return;
}



===== Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry @ 140015d60 =====

void Ds_ExEnterPriorityRegionAndAcquireResourceExclusive_Entry(void)

{
  DsIncrementTracker(0);
  return;
}



===== Ds_ExReleaseResourceAndLeaveCriticalRegion_Entry @ 140015d80 =====

void Ds_ExReleaseResourceAndLeaveCriticalRegion_Entry(void)

{
  DsCheckOrDecrementTracker
            (0,0x40003,
             "The driver is claiming to leave critical region from outside some critical region.");
  return;
}



===== Ds_IRP_MJ_DEVICE_CONTROL_Entry @ 140015db0 =====

void Ds_IRP_MJ_DEVICE_CONTROL_Entry(longlong param_1)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = 0;
  local_20 = 0;
  local_18 = *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 8);
  DifPushThreadContextData(0x13,&local_28);
  return;
}



===== Ds_KeAcquireInStackQueuedSpinLock_Exit @ 140015e00 =====

void Ds_KeAcquireInStackQueuedSpinLock_Exit(void)

{
  DsIncrementTracker(1);
  return;
}



===== Ds_KeAcquireSpinLockAtDpcLevel_Exit @ 140015e20 =====

void Ds_KeAcquireSpinLockAtDpcLevel_Exit(void)

{
  DsIncrementTracker(2);
  return;
}



===== Ds_KeReleaseSpinLockFromDpcLevel_Exit @ 140015e40 =====

void Ds_KeReleaseSpinLockFromDpcLevel_Exit(void)

{
  longlong lVar1;
  
  lVar1 = DifFindThreadContextData(0x13);
  if (lVar1 != 0) {
    *(int *)(lVar1 + 8) = *(int *)(lVar1 + 8) + -1;
  }
  return;
}



===== Ds_KeReleaseInStackQueuedSpinLock_Entry @ 140015e70 =====

void Ds_KeReleaseInStackQueuedSpinLock_Entry(void)

{
  DsCheckOrDecrementTracker
            (1,0x40007,"The driver is releasing a stack queued spin lock without acquiring first.");
  return;
}



===== Ds_KeTryToAcquireSpinLockAtDpcLevel_Exit @ 140015ea0 =====

void Ds_KeTryToAcquireSpinLockAtDpcLevel_Exit(longlong param_1)

{
  if (*(char *)(param_1 + 0x10) != '\0') {
    DsIncrementTracker(2);
  }
  return;
}



===== DifDdiMoreIrqlPluginEntry @ 140015ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifDdiMoreIrqlPluginEntry(void)

{
  int iVar1;
  undefined1 auStack_418 [32];
  char *local_3f8;
  undefined4 local_3f0;
  code *local_3e8;
  undefined8 local_3e0;
  char *local_3d8;
  undefined4 local_3d0;
  code *local_3c8;
  undefined8 local_3c0;
  char *local_3b8;
  undefined4 local_3b0;
  code *local_3a8;
  undefined8 local_3a0;
  char *local_398;
  undefined4 local_390;
  code *local_388;
  undefined8 local_380;
  char *local_378;
  undefined4 local_370;
  code *local_368;
  undefined8 local_360;
  char *local_358;
  undefined4 local_350;
  code *local_348;
  undefined8 local_340;
  char *local_338;
  undefined4 local_330;
  code *local_328;
  undefined8 local_320;
  char *local_318;
  undefined4 local_310;
  code *local_308;
  undefined8 local_300;
  char *local_2f8;
  undefined4 local_2f0;
  code *local_2e8;
  undefined8 local_2e0;
  char *local_2d8;
  undefined4 local_2d0;
  code *local_2c8;
  undefined8 local_2c0;
  char *local_2b8;
  undefined4 local_2b0;
  code *local_2a8;
  undefined8 local_2a0;
  char *local_298;
  undefined4 local_290;
  code *local_288;
  undefined8 local_280;
  char *local_278;
  undefined4 local_270;
  code *local_268;
  undefined8 local_260;
  char *local_258;
  undefined4 local_250;
  code *local_248;
  undefined8 local_240;
  char *local_238;
  undefined4 local_230;
  code *local_228;
  undefined8 local_220;
  char *local_218;
  undefined4 local_210;
  code *local_208;
  undefined8 local_200;
  char *local_1f8;
  undefined4 local_1f0;
  code *local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  code *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  undefined8 local_1a0;
  char *local_198;
  undefined4 local_190;
  code *local_188;
  undefined8 local_180;
  char *local_178;
  undefined4 local_170;
  code *local_168;
  undefined8 local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  undefined8 local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  undefined8 local_120;
  char *local_118;
  undefined4 local_110;
  code *local_108;
  undefined8 local_100;
  char *local_f8;
  undefined4 local_f0;
  code *local_e8;
  undefined8 local_e0;
  char *local_d8;
  undefined4 local_d0;
  code *local_c8;
  undefined8 local_c0;
  char *local_b8;
  undefined4 local_b0;
  code *local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined4 local_90;
  code *local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_418;
  local_3d0 = 0x10;
  local_3f0 = 0;
  local_3f8 = "ZwWriteFile";
  local_3e8 = SLIC_ZwWriteFile_entry_IrqlNtifsApcPassive;
  local_3d8 = "ZwSetInformationKey";
  local_3c8 = SLIC_ZwSetInformationKey_entry_IrqlIoRtlZwPassive;
  local_3b8 = "ZwSetInformationFile";
  local_3a8 = SLIC_ZwSetInformationFile_entry_IrqlIoRtlZwPassive;
  local_398 = "ZwSetEaFile";
  local_388 = SLIC_ZwSetEaFile_entry_IrqlIoRtlZwPassive;
  local_378 = "ZwRenameKey";
  local_368 = SLIC_ZwRenameKey_entry_IrqlIoRtlZwPassive;
  local_358 = "ZwOpenKeyTransactedEx";
  local_348 = SLIC_ZwOpenKeyTransactedEx_entry_IrqlIoRtlZwPassive;
  local_338 = "ZwOpenKeyTransacted";
  local_328 = SLIC_ZwOpenKeyTransacted_entry_IrqlIoRtlZwPassive;
  local_318 = "ZwOpenKeyEx";
  local_308 = SLIC_ZwOpenKeyEx_entry_IrqlIoRtlZwPassive;
  local_2f8 = "ZwFlushBuffersFileEx";
  local_2e8 = SLIC_ZwFlushBuffersFileEx_entry_IrqlIoRtlZwPassive;
  local_2d8 = "ZwFlushBuffersFile";
  local_2c8 = SLIC_ZwFlushBuffersFile_entry_IrqlIoRtlZwPassive;
  local_2b8 = "ZwDeleteValueKey";
  local_2a8 = SLIC_ZwDeleteValueKey_entry_IrqlIoRtlZwPassive;
  local_298 = "ZwDeleteFile";
  local_288 = SLIC_ZwDeleteFile_entry_IrqlIoRtlZwPassive;
  local_278 = "ZwCreateKeyTransacted";
  local_268 = SLIC_ZwCreateKeyTransacted_entry_IrqlIoRtlZwPassive;
  local_258 = "ZwCreateFile";
  local_3e0 = 0;
  local_3c0 = 0;
  local_3b0 = 0x12;
  local_3a0 = 0;
  local_390 = 0x15;
  local_380 = 0;
  local_370 = 0x1e;
  local_360 = 0;
  local_350 = 0x50;
  local_340 = 0;
  local_330 = 0x51;
  local_320 = 0;
  local_310 = 0x52;
  local_300 = 0;
  local_2f0 = 0x65;
  local_2e0 = 0;
  local_2d0 = 0x66;
  local_2c0 = 0;
  local_2b0 = 0x6f;
  local_2a0 = 0;
  local_290 = 0x71;
  local_280 = 0;
  local_270 = 0x79;
  local_260 = 0;
  local_250 = 0x7c;
  local_248 = SLIC_ZwCreateFile_entry_IrqlIoRtlZwPassive;
  local_238 = "ZwCreateDirectoryObject";
  local_228 = SLIC_ZwCreateDirectoryObject_entry_IrqlIoRtlZwPassive;
  local_218 = "RtlWriteRegistryValue";
  local_208 = SLIC_RtlWriteRegistryValue_entry_IrqlIoRtlZwPassive;
  local_1f8 = "RtlCreateSystemVolumeInformationFolder";
  local_1e8 = SLIC_RtlCreateSystemVolumeInformationFolder_entry_IrqlIoRtlZwPassive;
  local_1d8 = "RtlCreateRegistryKey";
  local_1c8 = SLIC_RtlCreateRegistryKey_entry_IrqlIoRtlZwPassive;
  local_1b8 = "NtWriteFile";
  local_1a8 = SLIC_NtWriteFile_entry_IrqlNtifsApcPassive;
  local_198 = "NtSetInformationFile";
  local_188 = SLIC_NtSetInformationFile_entry_IrqlNtifsApcPassive;
  local_178 = "NtCreateFile";
  local_168 = SLIC_NtCreateFile_entry_IrqlNtifsApcPassive;
  local_158 = "IoOpenDeviceRegistryKey";
  local_148 = SLIC_IoOpenDeviceRegistryKey_entry_IrqlIoRtlZwPassive;
  local_138 = "IoOpenDeviceInterfaceRegistryKey";
  local_128 = SLIC_IoOpenDeviceInterfaceRegistryKey_entry_IrqlIoRtlZwPassive;
  local_118 = "IoGetDriverDirectory";
  local_108 = SLIC_IoGetDriverDirectory_entry_IrqlIoRtlZwPassive;
  local_f8 = "IoGetDeviceDirectory";
  local_e8 = SLIC_IoGetDeviceDirectory_entry_IrqlIoRtlZwPassive;
  local_d8 = "IoCreateFileSpecifyDeviceObjectHint";
  local_c8 = SLIC_IoCreateFileSpecifyDeviceObjectHint_entry_IrqlIoRtlZwPassive;
  local_b8 = "IoCreateFileEx";
  local_a8 = SLIC_IoCreateFileEx_entry_IrqlIoRtlZwPassive;
  local_240 = 0;
  local_230 = 0x7f;
  local_220 = 0;
  local_210 = 0x95;
  local_200 = 0;
  local_1f0 = 0xa6;
  local_1e0 = 0;
  local_1d0 = 0xa7;
  local_1c0 = 0;
  local_1b0 = 0xcc;
  local_1a0 = 0;
  local_190 = 0xcd;
  local_180 = 0;
  local_170 = 0xd0;
  local_160 = 0;
  local_150 = 0x145;
  local_140 = 0;
  local_130 = 0x146;
  local_120 = 0;
  local_110 = 0x14d;
  local_100 = 0;
  local_f0 = 0x151;
  local_e0 = 0;
  local_d0 = 0x160;
  local_c0 = 0;
  local_b0 = 0x161;
  local_a0 = 0;
  local_98 = "CcFastCopyWrite";
  local_90 = 0x1af;
  local_88 = SLIC_CcFastCopyWrite_entry_IrqlNtifsApcPassive;
  local_80 = 0;
  local_78 = "CcDeferWrite";
  local_68 = SLIC_CcDeferWrite_entry_IrqlNtifsApcPassive;
  local_58 = "CcCopyWriteEx";
  local_48 = SLIC_CcCopyWriteEx_entry_IrqlNtifsApcPassive;
  local_38 = "CcCopyWrite";
  local_28 = SLIC_CcCopyWrite_entry_IrqlNtifsApcPassive;
  local_70 = 0x1b0;
  local_60 = 0;
  local_50 = 0x1b1;
  local_40 = 0;
  local_30 = 0x1b2;
  local_20 = 0;
  iVar1 = CarRegisterDefaultRuleClassConfiguration(0xc4,0x11);
  if (-1 < iVar1) {
    DifRegisterPlugin(&local_3f8,0x1f,0x22,0);
  }
  return;
}



===== SLIC_CcCopyWriteEx_entry_IrqlNtifsApcPassive @ 140016440 =====

void SLIC_CcCopyWriteEx_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CcCopyWriteEx should only be called at IRQL <= APC_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_CcCopyWrite_entry_IrqlNtifsApcPassive @ 140016480 =====

void SLIC_CcCopyWrite_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CcCopyWrite should only be called at IRQL <= APC_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_CcDeferWrite_entry_IrqlNtifsApcPassive @ 1400164c0 =====

void SLIC_CcDeferWrite_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CcDeferWrite should only be called at IRQL <= APC_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_CcFastCopyWrite_entry_IrqlNtifsApcPassive @ 140016500 =====

void SLIC_CcFastCopyWrite_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  if (1 < bVar1) {
    DdiStdReportRuleViolation
              ("CcFastCopyWrite should only be called at IRQL <= APC_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_IoCreateFileEx_entry_IrqlIoRtlZwPassive @ 140016540 =====

void SLIC_IoCreateFileEx_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateFileEx should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_IoCreateFileSpecifyDeviceObjectHint_entry_IrqlIoRtlZwPassive @ 140016580 =====

void SLIC_IoCreateFileSpecifyDeviceObjectHint_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoCreateFileSpecifyDeviceObjectHint should only be called at IRQL = PASSIVE_LEVEL.",
               0x20023,*param_1);
  }
  return;
}



===== SLIC_IoGetDeviceDirectory_entry_IrqlIoRtlZwPassive @ 1400165c0 =====

void SLIC_IoGetDeviceDirectory_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetDeviceDirectory should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_IoGetDriverDirectory_entry_IrqlIoRtlZwPassive @ 140016600 =====

void SLIC_IoGetDriverDirectory_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoGetDriverDirectory should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_IoOpenDeviceInterfaceRegistryKey_entry_IrqlIoRtlZwPassive @ 140016640 =====

void SLIC_IoOpenDeviceInterfaceRegistryKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoOpenDeviceInterfaceRegistryKey should only be called at IRQL = PASSIVE_LEVEL.",
               0x20023,*param_1);
  }
  return;
}



===== SLIC_IoOpenDeviceRegistryKey_entry_IrqlIoRtlZwPassive @ 140016680 =====

void SLIC_IoOpenDeviceRegistryKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("IoOpenDeviceRegistryKey should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_NtCreateFile_entry_IrqlNtifsApcPassive @ 1400166c0 =====

void SLIC_NtCreateFile_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("NtCreateFile should only be called at IRQL = PASSIVE_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_NtSetInformationFile_entry_IrqlNtifsApcPassive @ 140016700 =====

void SLIC_NtSetInformationFile_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("NtSetInformationFile should only be called at IRQL = PASSIVE_LEVEL.",0x20024,
               *param_1);
  }
  return;
}



===== SLIC_NtWriteFile_entry_IrqlNtifsApcPassive @ 140016740 =====

void SLIC_NtWriteFile_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("NtWriteFile should only be called at IRQL = PASSIVE_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== SLIC_RtlCreateRegistryKey_entry_IrqlIoRtlZwPassive @ 140016780 =====

void SLIC_RtlCreateRegistryKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("RtlCreateRegistryKey should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_RtlCreateSystemVolumeInformationFolder_entry_IrqlIoRtlZwPassive @ 1400167c0 =====

void SLIC_RtlCreateSystemVolumeInformationFolder_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("RtlCreateSystemVolumeInformationFolder should only be called at IRQL = PASSIVE_LEVEL."
               ,0x20023,*param_1);
  }
  return;
}



===== SLIC_RtlWriteRegistryValue_entry_IrqlIoRtlZwPassive @ 140016800 =====

void SLIC_RtlWriteRegistryValue_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("RtlWriteRegistryValue should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwCreateDirectoryObject_entry_IrqlIoRtlZwPassive @ 140016840 =====

void SLIC_ZwCreateDirectoryObject_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwCreateDirectoryObject should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwCreateFile_entry_IrqlIoRtlZwPassive @ 140016880 =====

void SLIC_ZwCreateFile_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwCreateFile should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwCreateKeyTransacted_entry_IrqlIoRtlZwPassive @ 1400168c0 =====

void SLIC_ZwCreateKeyTransacted_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwCreateKeyTransacted should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwDeleteFile_entry_IrqlIoRtlZwPassive @ 140016900 =====

void SLIC_ZwDeleteFile_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwDeleteFile should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwDeleteValueKey_entry_IrqlIoRtlZwPassive @ 140016940 =====

void SLIC_ZwDeleteValueKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwDeleteValueKey should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwFlushBuffersFileEx_entry_IrqlIoRtlZwPassive @ 140016980 =====

void SLIC_ZwFlushBuffersFileEx_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwFlushBuffersFileEx should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwFlushBuffersFile_entry_IrqlIoRtlZwPassive @ 1400169c0 =====

void SLIC_ZwFlushBuffersFile_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwFlushBuffersFile should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1)
    ;
  }
  return;
}



===== SLIC_ZwOpenKeyEx_entry_IrqlIoRtlZwPassive @ 140016a00 =====

void SLIC_ZwOpenKeyEx_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwOpenKeyEx should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwOpenKeyTransactedEx_entry_IrqlIoRtlZwPassive @ 140016a40 =====

void SLIC_ZwOpenKeyTransactedEx_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwOpenKeyTransactedEx should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwOpenKeyTransacted_entry_IrqlIoRtlZwPassive @ 140016a80 =====

void SLIC_ZwOpenKeyTransacted_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwOpenKeyTransacted should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1
              );
  }
  return;
}



===== SLIC_ZwRenameKey_entry_IrqlIoRtlZwPassive @ 140016ac0 =====

void SLIC_ZwRenameKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwRenameKey should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwSetEaFile_entry_IrqlIoRtlZwPassive @ 140016b00 =====

void SLIC_ZwSetEaFile_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwSetEaFile should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1);
  }
  return;
}



===== SLIC_ZwSetInformationFile_entry_IrqlIoRtlZwPassive @ 140016b40 =====

void SLIC_ZwSetInformationFile_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwSetInformationFile should only be called at IRQL = PASSIVE_LEVEL.",0x20023,
               *param_1);
  }
  return;
}



===== SLIC_ZwSetInformationKey_entry_IrqlIoRtlZwPassive @ 140016b80 =====

void SLIC_ZwSetInformationKey_entry_IrqlIoRtlZwPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwSetInformationKey should only be called at IRQL = PASSIVE_LEVEL.",0x20023,*param_1
              );
  }
  return;
}



===== SLIC_ZwWriteFile_entry_IrqlNtifsApcPassive @ 140016bc0 =====

void SLIC_ZwWriteFile_entry_IrqlNtifsApcPassive(undefined8 *param_1)

{
  char cVar1;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    DdiStdReportRuleViolation
              ("ZwWriteFile should only be called at IRQL = PASSIVE_LEVEL.",0x20024,*param_1);
  }
  return;
}



===== DifHvciPluginEntry @ 140016c00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DifHvciPluginEntry(void)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStack_398 [32];
  undefined8 local_378;
  code *pcStack_370;
  undefined8 local_368;
  undefined4 local_360;
  char *local_358;
  undefined4 local_350;
  code *local_348;
  undefined8 local_340;
  char *local_338;
  undefined4 local_330;
  code *local_328;
  undefined8 local_320;
  char *local_318;
  undefined4 local_310;
  code *local_308;
  undefined8 local_300;
  char *local_2f8;
  undefined4 local_2f0;
  code *local_2e8;
  undefined8 local_2e0;
  char *local_2d8;
  undefined4 local_2d0;
  code *local_2c8;
  undefined8 local_2c0;
  char *local_2b8;
  undefined4 local_2b0;
  code *local_2a8;
  undefined8 local_2a0;
  char *local_298;
  undefined4 local_290;
  code *local_288;
  undefined8 local_280;
  char *local_278;
  undefined4 local_270;
  code *local_268;
  undefined8 local_260;
  char *local_258;
  undefined4 local_250;
  code *local_248;
  undefined8 local_240;
  char *local_238;
  undefined4 local_230;
  code *local_228;
  undefined8 local_220;
  char *local_218;
  undefined4 local_210;
  code *local_208;
  undefined8 local_200;
  char *local_1f8;
  undefined4 local_1f0;
  code *local_1e8;
  undefined8 local_1e0;
  char *local_1d8;
  undefined4 local_1d0;
  code *local_1c8;
  undefined8 local_1c0;
  char *local_1b8;
  undefined4 local_1b0;
  code *local_1a8;
  undefined8 local_1a0;
  char *local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined8 local_180;
  char *local_178;
  undefined4 local_170;
  code *local_168;
  undefined8 local_160;
  char *local_158;
  undefined4 local_150;
  code *local_148;
  undefined8 local_140;
  char *local_138;
  undefined4 local_130;
  code *local_128;
  undefined8 local_120;
  char *local_118;
  undefined4 local_110;
  code *local_108;
  undefined8 local_100;
  char *local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  char *local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  char *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  char *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_398;
  local_368 = 0;
  local_378 = 0;
  pcStack_370 = (code *)0x0;
  local_360 = 0;
  lVar2 = ExAllocatePool2(0x40,0x28,0x6c706943);
  if (lVar2 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)(lVar2 + 0x20) = 0x1003;
    *(code **)(lVar2 + 0x10) = HvciHandleIo;
    *(code **)(lVar2 + 0x18) = HvciCleanup;
    XdvInsertPluginObject(0x19,lVar2);
    local_350 = 0x19d;
    local_358 = "ExAllocatePool";
    local_348 = Hvci_ExAllocatePool_Entry;
    local_338 = "ExAllocatePool2";
    local_328 = Hvci_ExAllocatePoolWithTag_Entry;
    local_318 = "ExAllocatePoolWithTag";
    local_308 = Hvci_ExAllocatePoolWithTag_Entry;
    local_2f8 = "ExAllocatePoolWithTagPriority";
    local_2e8 = Hvci_ExAllocatePoolWithTag_Entry;
    local_2d8 = "ExAllocatePoolWithQuota";
    local_2c8 = Hvci_ExAllocatePool_Entry;
    local_2b8 = "ExAllocatePoolWithQuotaTag";
    local_2a8 = Hvci_ExAllocatePoolWithTag_Entry;
    local_298 = "ExInitializeLookasideListEx";
    local_288 = Hvci_ExInitializeLookasideListEx_Entry;
    local_278 = "MmMapViewOfSection";
    local_268 = Hvci_MmMapIoSpaceEx_Entry;
    local_258 = "NtMapViewOfSection";
    local_248 = Hvci_MmMapIoSpaceEx_Entry;
    local_238 = "MmMapIoSpaceEx";
    local_228 = Hvci_MmMapIoSpaceEx_Entry;
    local_218 = "MmCreateSection";
    local_208 = Hvci_MmCreateSection_Entry;
    local_1f8 = "NtCreateSection";
    local_1e8 = Hvci_NtCreateSection_Entry;
    local_340 = 0;
    local_330 = 0x1a3;
    local_320 = 0;
    local_310 = 0x19e;
    local_300 = 0;
    local_2f0 = 0x19f;
    local_2e0 = 0;
    local_2d0 = 0x1a0;
    local_2c0 = 0;
    local_2b0 = 0x1a1;
    local_2a0 = 0;
    local_290 = 399;
    local_280 = 0;
    local_270 = 0x1b3;
    local_260 = 0;
    local_250 = 0x1b4;
    local_240 = 0;
    local_230 = 0x1b5;
    local_220 = 0;
    local_210 = 0x1b6;
    local_200 = 0;
    local_1f0 = 0x1b7;
    local_1e0 = 0;
    local_1d0 = 0x1b8;
    local_1d8 = "MmProtectMdlSystemAddress";
    local_1c8 = Hvci_MmMapIoSpaceEx_Entry;
    local_1b8 = "ExAllocateCacheAwareRundownProtection";
    local_1a8 = Hvci_ExAllocateCacheAwareRundownProtection_Entry;
    local_198 = "MmAllocateContiguousNodeMemory";
    local_178 = "ZwCreateSection";
    local_168 = Hvci_NtCreateSection_Entry;
    local_158 = "ZwMapViewOfSection";
    local_148 = Hvci_MmMapIoSpaceEx_Entry;
    local_138 = "ZwProtectVirtualMemory";
    local_128 = Hvci_ZwProtectVirtualMemory_Entry;
    local_118 = "MmMapLockedPagesSpecifyCache";
    local_108 = Hvci_MmMapLockedPagesSpecifyCache_Entry;
    local_f8 = "MmMapLockedPages";
    local_d8 = "MmMapIoSpace";
    local_b8 = "MmAllocateContiguousMemory";
    local_98 = "MmAllocateContiguousMemorySpecifyCache";
    local_78 = "MmAllocateContiguousMemorySpecifyCacheNode";
    local_58 = "DriverEntry";
    local_48 = Hvci_DriverEntry_Entry;
    local_38 = "DllInitialize";
    local_28 = Hvci_DllInitialize_Entry;
    pcStack_370 = HvciUnload;
    local_1c0 = 0;
    local_1b0 = 0x1b9;
    local_1a0 = 0;
    local_190 = 0xea;
    local_188 = 0;
    local_180 = 0;
    local_170 = 0x77;
    local_160 = 0;
    local_150 = 0x5c;
    local_140 = 0;
    local_130 = 0x3f;
    local_120 = 0;
    local_110 = 0xdb;
    local_100 = 0;
    local_f0 = 0xdc;
    local_e8 = 0;
    local_e0 = 0;
    local_d0 = 0xdd;
    local_c8 = 0;
    local_c0 = 0;
    local_b0 = 0xee;
    local_a8 = 0;
    local_a0 = 0;
    local_90 = 0xec;
    local_88 = 0;
    local_80 = 0;
    local_70 = 0xeb;
    local_68 = 0;
    local_60 = 0;
    local_50 = 0x1000001c;
    local_40 = 0;
    local_30 = 0x80000000;
    local_20 = 0;
    local_378 = CONCAT44(local_378._4_4_,0x18);
    iVar1 = DifRegisterPlugin(&local_358,0x1a,0x19,&local_378);
    if (-1 < iVar1) {
      if ((char)VfOptionFlags < '\0') {
        _HvciDefaultActions = 0x200000002;
        uRam0000000140032950 = 0x200000002;
        _DAT_140032958 = 0x200000002;
      }
      HvciPluginInitialized = 1;
      return iVar1;
    }
  }
  HvciCleanup();
  return iVar1;
}



===== HvciCheckImageCompliance @ 140017120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HvciCheckImageCompliance(undefined8 param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar9 = 0;
  lVar6 = 0;
  bVar2 = true;
  lVar4 = RtlImageNtHeader();
  if (lVar4 != 0) {
    puVar1 = (uint *)(lVar4 + 0xe8);
    puVar8 = (undefined8 *)((ulonglong)*(ushort *)(lVar4 + 0x14) + 0x18 + lVar4);
    if ((*puVar1 == 0) || (*(int *)(lVar4 + 0xec) == 0)) {
      bVar2 = false;
    }
    uVar5 = (*XdvGetDriverName)(param_1);
    if (*(short *)(lVar4 + 6) != 0) {
      do {
        if ((*(uint *)((longlong)puVar8 + 0x24) & 0xa0000000) == 0xa0000000) {
          local_48 = *puVar8;
          local_40 = 0;
          iVar3 = _stricmp((char *)&local_48,"INIT");
          if ((iVar3 != 0) || ((VfOptionFlags & 0x100) != 0)) {
            uVar7 = 0x40032964;
            HvciPreprocessOptions((uint *)&DAT_140032964,0x14002f250,0x2003,uVar5);
            HvciReportIssueWithOptions(uVar7,0x2003,uVar5,puVar8,&local_48,(uint *)&DAT_140032964);
            lVar6 = DifGetPluginPerDriverData(0x19,param_1);
            if (lVar6 != 0) {
              LOCK();
              *(int *)(lVar6 + 0xc) = *(int *)(lVar6 + 0xc) + 1;
              UNLOCK();
              LOCK();
              _ExecuteWriteSectionCount = _ExecuteWriteSectionCount + 1;
              UNLOCK();
            }
          }
        }
        if (bVar2) {
          if (((*(uint *)((longlong)puVar8 + 0xc) <= *puVar1) &&
              (*puVar1 < *(uint *)((longlong)puVar8 + 0xc) + *(int *)(puVar8 + 1))) &&
             ((*(uint *)((longlong)puVar8 + 0x24) & 0x20000000) != 0)) {
            local_48 = *puVar8;
            local_40 = 0;
            uVar7 = 0x40032940;
            HvciPreprocessOptions((uint *)&DAT_140032940,0x14002f2c0,0x2005,uVar5);
            HvciReportIssueWithOptions(uVar7,0x2005,uVar5,puVar1,&local_48,(uint *)&DAT_140032940);
            if (lVar6 != 0) {
              LOCK();
              *(int *)(lVar6 + 0x14) = *(int *)(lVar6 + 0x14) + 1;
              UNLOCK();
              LOCK();
              _IatInExecutableSectionCount = _IatInExecutableSectionCount + 1;
              UNLOCK();
            }
          }
        }
        if (((*(short *)(lVar4 + 0x18) == 0x10b) || (*(short *)(lVar4 + 0x18) == 0x20b)) &&
           ((*(uint *)(lVar4 + 0x38) == 0 || ((*(uint *)(lVar4 + 0x38) & 0xfff) != 0)))) {
          local_48 = *puVar8;
          local_40 = 0;
          uVar7 = 0x40032934;
          HvciPreprocessOptions((uint *)&DAT_140032934,0x14002f330,0x2004,uVar5);
          HvciReportIssueWithOptions(uVar7,0x2004,uVar5,puVar8,&local_48,(uint *)&DAT_140032934);
          if (lVar6 != 0) {
            LOCK();
            *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
            UNLOCK();
            LOCK();
            _SectionAlignmentFailureCount = _SectionAlignmentFailureCount + 1;
            UNLOCK();
          }
        }
        puVar8 = puVar8 + 5;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(lVar4 + 6));
    }
  }
  return;
}



===== HvciCheckPageProtection @ 1400173dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HvciCheckPageProtection(ulonglong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  if ((param_1 & 0xf0) != 0) {
    uVar2 = 0x4003293c;
    HvciPreprocessOptions((uint *)&DAT_14003293c,0x14002f1b8,0x2001,param_2);
    HvciReportIssueWithOptions(uVar2,0x2001,param_2,param_1 & 0xffffffff,0,(uint *)&DAT_14003293c);
    lVar1 = DifGetPluginPerDriverData(0x19,param_2);
    if (lVar1 != 0) {
      LOCK();
      *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
      UNLOCK();
      LOCK();
      _ExecutePageProtectionCount = _ExecutePageProtectionCount + 1;
      UNLOCK();
    }
  }
  return;
}



===== HvciCheckPoolType @ 140017470 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HvciCheckPoolType(uint param_1,undefined8 param_2,ulonglong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (((HvciPluginInitialized != '\0') && (((longlong)(int)param_1 & 1U) == 0)) &&
     ((param_1 >> 9 & 1) == 0)) {
    uVar2 = 0x40032938;
    HvciPreprocessOptions((uint *)&DAT_140032938,0x14002f160,0x2000,param_2);
    HvciReportIssueWithOptions
              (uVar2,0x2000,param_2,(longlong)(int)param_1,param_3 & 0xffffffff,
               (uint *)&DAT_140032938);
    piVar1 = (int *)DifGetPluginPerDriverData(0x19,param_2);
    if (piVar1 != (int *)0x0) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      LOCK();
      _ExecutePoolTypeCount = _ExecutePoolTypeCount + 1;
      UNLOCK();
    }
  }
  return;
}



===== HvciCleanup @ 140017520 =====

void HvciCleanup(void)

{
  longlong lVar1;
  
  lVar1 = XdvRemovePluginObject(0x19);
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== HvciHandleIo @ 140017550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 HvciHandleIo(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  uVar4 = 0;
  puVar2 = *(uint **)(param_1 + 0x18);
  uVar6 = 0;
  uVar5 = *(uint *)(lVar1 + 0x18);
  local_res8[0] = 0;
  if ((*(uint *)(lVar1 + 0x10) == 0) || (*(uint *)(lVar1 + 0x10) < *(uint *)(lVar1 + 8))) {
    uVar4 = 0xc000000d;
  }
  else if (uVar5 == 0x10034000) {
    if (DifGetVerifiedDriverCount == (code *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (*DifGetVerifiedDriverCount)();
    }
    *puVar2 = uVar5;
    uVar6 = 8;
  }
  else if (uVar5 == 0x10034004) {
    uVar5 = *puVar2;
    if (DifGetVerifiedDriverCount != (code *)0x0) {
      uVar3 = (*DifGetVerifiedDriverCount)();
      if (uVar5 < uVar3) {
        uVar4 = 0xc0000023;
        goto LAB_140017632;
      }
    }
    uVar4 = DifEnumeratePluginData(0x19,uVar5,HvciPerDriverCallback,puVar2,local_res8);
    uVar6 = local_res8[0] * 0x94;
  }
  else {
    XdvUtilDbgPrint("VerifierExt!%s: invalid IOCTL received: 0x%0x\n","HvciHandleIo",
                    (ulonglong)uVar5,param_4);
    uVar4 = 0xc0000002;
  }
LAB_140017632:
  *(ulonglong *)(param_1 + 0x38) = (ulonglong)uVar6;
  *(undefined4 *)(param_1 + 0x30) = uVar4;
  IofCompleteRequest(param_1,0);
  return uVar4;
}



===== HvciPerDriverCallback @ 140017670 =====

void HvciPerDriverCallback(int param_1,ushort *param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  uint uVar2;
  void *_Dst;
  
  uVar2 = (uint)*param_2;
  _Dst = (void *)((ulonglong)(uint)(param_1 * 0x94) + param_4);
  if (0x3c < *param_2) {
    uVar2 = 0x3c;
  }
  memcpy(_Dst,*(void **)(param_2 + 4),(ulonglong)uVar2);
  uVar1 = param_3[1];
  *(undefined8 *)((longlong)_Dst + 0x7c) = *param_3;
  *(undefined8 *)((longlong)_Dst + 0x84) = uVar1;
  *(undefined8 *)((longlong)_Dst + 0x8c) = param_3[2];
  return;
}



===== HvciPreprocessOptions @ 1400176c8 =====

void HvciPreprocessOptions(uint *param_1,longlong param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 == 0xffffffff) {
    if (5 < (ulonglong)(param_3 & 0xf)) {
      *param_1 = 4;
      goto LAB_140017709;
    }
    uVar1 = *(uint *)(&HvciDefaultActions + (ulonglong)(param_3 & 0xf) * 4);
    *param_1 = uVar1;
  }
  if (uVar1 == 0) {
    return;
  }
  if ((uVar1 & 0x10) != 0) {
    *param_1 = 0;
  }
LAB_140017709:
  DifUtilDbgPrint("*********** Verifier Detected a Code Integrity Issue ************\n");
  DifUtilDbgPrint("**\n");
  DifUtilDbgPrint("** ");
  if (param_2 != 0) {
    DbgPrintEx(0x65,0,param_2,param_4);
  }
  DifUtilDbgPrint("\n");
  DifUtilDbgPrint("**\n");
  DifUtilDbgPrint("*****************************************************************\n");
  return;
}



===== HvciReportIssueWithOptions @ 1400177b4 =====

void HvciReportIssueWithOptions
               (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,uint *param_6)

{
  uint uVar1;
  code *pcVar2;
  char cVar3;
  undefined4 local_res8 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_18;
  
  local_res8[0] = param_1;
  memset(&local_68,0,0x58);
  uVar1 = *param_6;
  if ((uVar1 != 0) && ((uVar1 & 2) == 0)) {
    if (((uVar1 & 8) == 0) && (KdDebuggerEnabled_exref != (code *)0x0)) {
      if ((uVar1 & 4) != 0) {
        do {
          DifUtilDbgPrint("\n*** Verifier assertion failed ***\n");
          DbgPrompt("(B)reak, (I)gnore, (W)arn only, (R)emove assert? ",local_res8,2);
          cVar3 = (char)local_res8[0];
          if (cVar3 == 'B') {
code_r0x00014001787b:
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          if (cVar3 == 'I') {
            return;
          }
          if (cVar3 == 'R') {
LAB_14001787e:
            *param_6 = 0;
            return;
          }
          if (cVar3 == 'W') break;
          if (cVar3 == 'b') goto code_r0x00014001787b;
          if (cVar3 == 'i') {
            return;
          }
          if (cVar3 == 'r') goto LAB_14001787e;
        } while (cVar3 != 'w');
        *param_6 = 2;
      }
    }
    else {
      CarInitializeRuleViolationDetails(&local_68);
      local_58 = param_5;
      local_18 = 0xc4;
      local_68 = param_3;
      local_60 = param_4;
      CarReportDifPluginRuleViolation(0x19,param_2,param_3,&local_68);
    }
  }
  return;
}



===== HvciUnload @ 1400178f0 =====

void HvciUnload(void)

{
  HvciPluginInitialized = 0;
  HvciCleanup();
  return;
}



===== Hvci_DllInitialize_Entry @ 140017910 =====

void Hvci_DllInitialize_Entry(longlong param_1)

{
  HvciCheckImageCompliance(*(undefined8 *)(param_1 + 0x10));
  return;
}



===== Hvci_DriverEntry_Entry @ 140017930 =====

void Hvci_DriverEntry_Entry(longlong param_1)

{
  HvciCheckImageCompliance(*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x18));
  return;
}



===== Hvci_ExAllocateCacheAwareRundownProtection_Entry @ 140017950 =====

void Hvci_ExAllocateCacheAwareRundownProtection_Entry(undefined8 *param_1)

{
  HvciCheckPageProtection((ulonglong)*(uint *)((longlong)param_1 + 0xc),*param_1);
  return;
}



===== Hvci_ExAllocatePoolWithTag_Entry @ 140017970 =====

void Hvci_ExAllocatePoolWithTag_Entry(undefined8 *param_1)

{
  HvciCheckPoolType(*(uint *)(param_1 + 7),*param_1,(ulonglong)*(uint *)((longlong)param_1 + 0x24));
  return;
}



===== Hvci_ExAllocatePool_Entry @ 140017990 =====

void Hvci_ExAllocatePool_Entry(undefined8 *param_1)

{
  HvciCheckPoolType(*(uint *)(param_1 + 7),*param_1,0);
  return;
}



===== Hvci_ExInitializeLookasideListEx_Entry @ 1400179b0 =====

void Hvci_ExInitializeLookasideListEx_Entry(undefined8 *param_1)

{
  HvciCheckPoolType(*(uint *)((longlong)param_1 + 0x24),*param_1,(ulonglong)*(uint *)(param_1 + 2));
  return;
}



===== Hvci_MmCreateSection_Entry @ 1400179d0 =====

void Hvci_MmCreateSection_Entry(undefined8 *param_1)

{
  HvciCheckPageProtection((ulonglong)*(uint *)((longlong)param_1 + 0x1c),*param_1);
  return;
}



===== Hvci_MmMapIoSpaceEx_Entry @ 1400179f0 =====

void Hvci_MmMapIoSpaceEx_Entry(undefined8 *param_1)

{
  HvciCheckPageProtection((ulonglong)*(uint *)(param_1 + 1),*param_1);
  return;
}



===== Hvci_MmMapLockedPagesSpecifyCache_Entry @ 140017a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Hvci_MmMapLockedPagesSpecifyCache_Entry(undefined8 *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(param_1 + 1);
  if ((uVar1 >> 0x1e & 1) == 0) {
    uVar2 = *param_1;
    uVar4 = 0x40032960;
    HvciPreprocessOptions((uint *)&DAT_140032960,0x14002f1f0,0x2002,uVar2);
    HvciReportIssueWithOptions(uVar4,0x2002,uVar2,(longlong)(int)uVar1,0,(uint *)&DAT_140032960);
    lVar3 = DifGetPluginPerDriverData(0x19,uVar2);
    if (lVar3 != 0) {
      LOCK();
      *(int *)(lVar3 + 8) = *(int *)(lVar3 + 8) + 1;
      UNLOCK();
      LOCK();
      _ExecutePageMappingCount = _ExecutePageMappingCount + 1;
      UNLOCK();
    }
  }
  return;
}



===== Hvci_NtCreateSection_Entry @ 140017ab0 =====

void Hvci_NtCreateSection_Entry(undefined8 *param_1)

{
  HvciCheckPageProtection((ulonglong)*(uint *)((longlong)param_1 + 0x14),*param_1);
  return;
}



===== Hvci_ZwProtectVirtualMemory_Entry @ 140017ad0 =====

void Hvci_ZwProtectVirtualMemory_Entry(undefined8 *param_1)

{
  HvciCheckPageProtection((ulonglong)*(uint *)(param_1 + 2),*param_1);
  return;
}



===== AvxDriverUnload_Exit @ 140017af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AvxDriverUnload_Exit(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  ulonglong *local_res8;
  
  local_res8 = (ulonglong *)0x0;
  lVar2 = (*XdvGetPristineDriverUnloadRoutine)(param_1[1]);
  if (lVar2 != 0) {
    puVar3 = (uint *)DifGetPluginPerDriverData(0x28,*param_1);
    if ((puVar3 != (uint *)0x0) && (*puVar3 != puVar3[1])) {
      iVar1 = CarCreateRuleViolationDetails(&local_res8);
      if (-1 < iVar1) {
        *local_res8 = (ulonglong)*puVar3;
        local_res8[1] = (ulonglong)puVar3[1];
        CarReportDifPluginRuleViolation(0x28,1,lVar2,local_res8);
        CarDeleteRuleViolationDetails(&local_res8);
      }
    }
  }
  return;
}



===== AvxKeRestoreExtendedProcessorState_Exit @ 140017bb0 =====

void AvxKeRestoreExtendedProcessorState_Exit(undefined8 *param_1)

{
  longlong lVar1;
  
  lVar1 = DifGetPluginPerDriverData(0x28,*param_1);
  if (lVar1 != 0) {
    *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
  }
  return;
}



===== AvxKeSaveExtendedProcessorState_Exit @ 140017be0 =====

void AvxKeSaveExtendedProcessorState_Exit(undefined8 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)DifGetPluginPerDriverData(0x28,*param_1);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  return;
}



===== DifAvxPluginEntry @ 140017c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifAvxPluginEntry(void)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined8 uStack_8c;
  undefined8 local_84;
  char *local_78;
  undefined4 local_70;
  undefined8 local_68;
  code *local_60;
  char *local_58;
  undefined4 local_50;
  undefined8 local_48;
  code *local_40;
  char *local_38;
  undefined4 local_30;
  undefined8 local_28;
  code *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_84 = 0;
  local_68 = 0;
  local_48 = 0;
  local_28 = 0;
  local_78 = "DriverUnload";
  local_98 = 8;
  local_60 = AvxDriverUnload_Exit;
  local_58 = "KeSaveExtendedProcessorState";
  local_70 = 0x1000001f;
  local_40 = AvxKeSaveExtendedProcessorState_Exit;
  local_38 = "KeRestoreExtendedProcessorState";
  local_20 = AvxKeRestoreExtendedProcessorState_Exit;
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_8c = 0;
  local_50 = 0xfa;
  local_30 = 0xfb;
  iVar1 = DifRegisterPlugin(&local_78,3,0x28,&local_98);
  if (-1 < iVar1) {
    CarRegisterDefaultRuleClassConfiguration(0xc4,0x28);
  }
  return;
}



===== AmmCheckInitiatorRule @ 140017cfc =====

void AmmCheckInitiatorRule(ulonglong param_1,uint param_2,longlong param_3,char param_4)

{
  if (((param_1 != 0) && ((*(uint *)(param_1 + 0x18) & 0x400) == 0)) &&
     (((param_2 >> 8 & 1) != 0 || (param_4 != '\0')))) {
    AmmReportInitiatorViolation((~param_2 & 1) + 1,param_1,(ulonglong)param_2,param_3);
  }
  return;
}



===== AmmReportInitiatorViolation @ 140017d44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AmmReportInitiatorViolation
               (undefined4 param_1,ulonglong param_2,ulonglong param_3,longlong param_4)

{
  ushort uVar1;
  int iVar2;
  wchar_t *_Str1;
  longlong lVar3;
  ushort uVar4;
  undefined1 auStack_88 [32];
  ulonglong *local_68;
  longlong local_60 [7];
  
  local_60[5] = __security_cookie ^ (ulonglong)auStack_88;
  lVar3 = 0;
  local_68 = (ulonglong *)0x0;
  if (param_4 != 0) {
    _Str1 = (wchar_t *)(*XdvGetDriverName)(param_4);
    if ((_Str1 == (wchar_t *)0x0) || (iVar2 = _wcsicmp(_Str1,L"FltMgr.sys"), iVar2 != 0)) {
      lVar3 = param_4;
    }
    else {
      local_60[4] = 0;
      uVar4 = 0;
      local_60[0] = 0;
      local_60[1] = 0;
      local_60[2] = 0;
      local_60[3] = 0;
      uVar1 = RtlCaptureStackBackTrace(4,5,local_60,0);
      if (0 < (int)(uVar1 - 2)) {
        do {
          if (param_4 == local_60[uVar4]) {
            lVar3 = local_60[(ulonglong)uVar4 + 2];
            break;
          }
          uVar4 = uVar4 + 1;
        } while ((int)(uint)uVar4 < (int)(uVar1 - 2));
      }
    }
  }
  CarCreateRuleViolationDetails(&local_68);
  *local_68 = param_3 & 0xffffffff;
  local_68[1] = param_2;
  CarReportDifPluginRuleViolation(0x29,param_1,lVar3,local_68);
  CarDeleteRuleViolationDetails(&local_68);
  return;
}



===== Amm_IoCreateFileEx_Entry @ 140017e90 =====

void Amm_IoCreateFileEx_Entry(longlong *param_1)

{
  AmmCheckInitiatorRule(param_1[10],*(uint *)(param_1 + 2),*param_1,'\x01');
  return;
}



===== Amm_IoCreateFileSpecifyDeviceObjectHint_Entry @ 140017ec0 =====

void Amm_IoCreateFileSpecifyDeviceObjectHint_Entry(longlong *param_1)

{
  AmmCheckInitiatorRule(param_1[10],*(uint *)(param_1 + 2),*param_1,'\0');
  return;
}



===== Amm_IoCreateFile_Entry @ 140017ef0 =====

void Amm_IoCreateFile_Entry(longlong *param_1)

{
  AmmCheckInitiatorRule(param_1[9],*(uint *)(param_1 + 1),*param_1,'\0');
  return;
}



===== DifAMMPluginEntry @ 140017f20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DifAMMPluginEntry(void)

{
  int iVar1;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  char *local_78;
  undefined4 local_70;
  code *local_68;
  undefined8 local_60;
  char *local_58;
  undefined4 local_50;
  code *local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_30;
  code *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_60 = 0;
  local_40 = 0;
  local_20 = 0;
  local_78 = "IoCreateFile";
  local_68 = Amm_IoCreateFile_Entry;
  local_58 = "IoCreateFileEx";
  local_48 = Amm_IoCreateFileEx_Entry;
  local_70 = 0x162;
  local_38 = "IoCreateFileSpecifyDeviceObjectHint";
  local_50 = 0x161;
  local_28 = Amm_IoCreateFileSpecifyDeviceObjectHint_Entry;
  local_30 = 0x160;
  iVar1 = DifRegisterPlugin(&local_78,3,0x29);
  if (-1 < iVar1) {
    iVar1 = CarRegisterDefaultRuleClassConfiguration(0xc4,0x29);
    if (-1 < iVar1) {
      local_88 = 2;
      iVar1 = CarRegisterRuleOverride(0x29,1,1,1);
      if (-1 < iVar1) {
        local_88 = 2;
        CarRegisterRuleOverride(0x29,2,1,1);
      }
    }
  }
  return;
}



===== CheckTimerRuleViolation @ 140018050 =====

void CheckTimerRuleViolation(void)

{
  short sVar1;
  undefined8 *puVar2;
  char *pcVar3;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x58,0x6f4d6544);
  if (puVar2 != (undefined8 *)0x0) {
    pcVar3 = (char *)ExAllocatePool2(0x40,0x41,0x6f4d6544);
    if (pcVar3 != (char *)0x0) {
      builtin_strncpy(pcVar3,"Driver freed a memory block containing an active periodic timer.",0x40
                     );
      *puVar2 = pcVar3;
      puVar2[3] = pcVar3;
    }
    sVar1 = RtlCaptureStackBackTrace(7,1,local_res18);
    if (sVar1 != 0) {
      puVar2[6] = local_res18[0];
    }
    CarReportDifPluginRuleViolation(0x2f,0x300001,puVar2[6],puVar2);
    if (pcVar3 != (char *)0x0) {
      ExFreePoolWithTag(pcVar3,0);
    }
    ExFreePoolWithTag(puVar2,0);
  }
  return;
}



===== DifObjTrkDemoPluginEntry @ 140018170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DifObjTrkDemoPluginEntry(undefined8 *param_1)

{
  int iVar1;
  char *local_48;
  undefined4 local_40;
  undefined8 local_38;
  code *local_30;
  char *local_28;
  undefined4 local_20;
  undefined8 local_18;
  code *local_10;
  
  if (param_1 != (undefined8 *)0x0) {
    _ObjTrkDemoConfigData = *param_1;
  }
  local_38 = 0;
  local_18 = 0;
  local_48 = "KeSetTimerEx";
  local_40 = 0xf7;
  local_30 = ObjTrkDemo_KeSetTimerEx_Exit;
  local_28 = "KeCancelTimer";
  local_10 = ObjTrkDemo_KeCancelTimer_Exit;
  local_20 = 0x122;
  iVar1 = DifRegisterPlugin(&local_48,2,0x2f);
  if (-1 < iVar1) {
    iVar1 = DifRegisterObjectTracking(0x2f,0,CheckTimerRuleViolation);
    if (-1 < iVar1) {
      CarRegisterDefaultRuleClassConfiguration(0xc4,0x2f);
    }
  }
  return;
}



===== ObjTrkDemo_KeCancelTimer_Exit @ 140018230 =====

void ObjTrkDemo_KeCancelTimer_Exit(longlong param_1)

{
  DifObjTrkRemoveItem(0x2f,*(undefined8 *)(param_1 + 8));
  DifObjTrkRemoveItem(0x2f,*(undefined8 *)(param_1 + 8));
  return;
}



===== ObjTrkDemo_KeSetTimerEx_Exit @ 140018280 =====

void ObjTrkDemo_KeSetTimerEx_Exit(longlong param_1)

{
  if (0 < *(int *)(param_1 + 0x10)) {
    DifObjTrkInsertItem(0x2f,*(undefined8 *)(param_1 + 0x20));
    if (*(longlong *)(param_1 + 8) != 0) {
      DifObjTrkInsertItem(0x2f,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x18));
    }
  }
  return;
}



===== XdvNdisAllocateVerifierContext_wrapper @ 1400182e0 =====

undefined8
XdvNdisAllocateVerifierContext_wrapper
          (short *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  undefined8 *_Dst;
  void *_Dst_00;
  short *psVar2;
  
  if ((param_4 == (longlong *)0x0) || (*param_4 != 0)) {
    return 0xc0000001;
  }
  uVar1 = (uint)XdvRuleClasses & 0x220000;
  *param_4 = 0;
  if (uVar1 == 0) {
    return 0;
  }
  _Dst = (undefined8 *)ExAllocatePool2(0x40,0x168,0x4e766458);
  if (_Dst == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  memset(_Dst,0,0x168);
  *(undefined4 *)(_Dst + 2) = 2;
  _Dst_00 = (void *)ExAllocatePool2(0x40,0x188,0x4e766458);
  _Dst[6] = _Dst_00;
  if (_Dst_00 == (void *)0x0) {
    if (XdvLookasideStore == 0) {
      return 0xc000009a;
    }
    ExFreePoolWithTag(_Dst,0x4d766458);
    return 0xc000009a;
  }
  if (param_1 == (short *)0x0) {
LAB_1400183d7:
    psVar2 = (short *)0x0;
  }
  else {
    if (*param_1 == 3) {
      psVar2 = *(short **)(param_1 + 4);
      goto LAB_1400183dd;
    }
    psVar2 = param_1;
    if (*param_1 != 4) goto LAB_1400183d7;
  }
  param_1 = (short *)0x0;
LAB_1400183dd:
  memset(_Dst_00,0,0x188);
  *(undefined4 *)(_Dst + 5) = 0x188;
  *(undefined4 *)_Dst[6] = 2;
  *(short **)(_Dst[6] + 0x18) = param_1;
  *(short **)(_Dst[6] + 0x20) = psVar2;
  *(undefined8 *)(_Dst[6] + 0x10) = param_2;
  *(undefined8 **)(_Dst[6] + 8) = _Dst;
  _Dst[0x2c] = param_3;
  XdvTimedRegisterContext(2,_Dst);
  *param_4 = (longlong)_Dst;
  return 0;
}



===== XdvNdisFIndicateReceiveNetBufferLists_wrapper @ 140018460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFIndicateReceiveNetBufferLists_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
               uint param_5,longlong param_6,undefined *param_7)

{
  longlong lVar1;
  longlong local_38 [2];
  
  local_38[0] = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_38[0] = 0;
    if (param_6 != 0) {
      local_38[0] = *(longlong *)(param_6 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_38,param_6,'\0');
  }
  lVar1 = local_38[0];
  if (((((uint)XdvRuleClasses & 0x200000) != 0) && (local_38[0] != 0)) && ((param_5 & 2) == 0)) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_38[0] + 0x130),(int)DAT_1400598f0,param_2,param_3);
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_6,'\0');
  }
  (*(code *)param_7)(param_1,param_2,param_3,param_4,param_5);
  return;
}



===== XdvNdisFPauseComplete_wrapper @ 140018570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFPauseComplete_wrapper(undefined8 param_1,longlong param_2,undefined *param_3)

{
  longlong *plVar1;
  int *piVar2;
  int *local_res18;
  
  piVar2 = (int *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_2 == 0) {
      local_res18 = (int *)0x0;
    }
    else {
      local_res18 = *(int **)(param_2 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)&local_res18,param_2,'\0');
    piVar2 = local_res18;
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (piVar2 != (int *)0x0)) {
    plVar1 = (longlong *)(piVar2 + 0x3f);
    if ((int)*plVar1 == 0) {
      SLIC_StatefulAbort("The filter driver calls NdisFPauseComplete without its FilterPause returning NDIS_STATUS_PENDING first."
                         ,0x92010,piVar2,plVar1,(longlong *)0x0,4);
    }
    else {
      *(undefined4 *)plVar1 = 0;
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar2,param_2,'\0');
  }
  (*(code *)param_3)(param_1);
  return;
}



===== XdvNdisFReturnNetBufferLists_wrapper @ 140018650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFReturnNetBufferLists_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,longlong param_4,
               undefined *param_5)

{
  longlong lVar1;
  longlong local_28 [2];
  
  lVar1 = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_4 == 0) {
      local_28[0] = 0;
    }
    else {
      local_28[0] = *(longlong *)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_4,'\0');
    lVar1 = local_28[0];
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (lVar1 != 0)) {
    XdvNdisDataComplete((longlong *)(lVar1 + 0x138),param_2);
    if (*(longlong *)(lVar1 + 0x138) == 0) {
      *(undefined4 *)(lVar1 + 0x15c) = 0;
      *(undefined8 *)(lVar1 + 0x148) = 0;
      *(undefined4 *)(lVar1 + 0x154) = 0;
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisFSendNetBufferListsComplete_wrapper @ 140018740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFSendNetBufferListsComplete_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,longlong param_4,
               undefined *param_5)

{
  longlong lVar1;
  longlong local_28 [2];
  
  lVar1 = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_4 == 0) {
      local_28[0] = 0;
    }
    else {
      local_28[0] = *(longlong *)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_4,'\0');
    lVar1 = local_28[0];
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (lVar1 != 0)) {
    XdvNdisDataComplete((longlong *)(lVar1 + 0x108),param_2);
    if (*(longlong *)(lVar1 + 0x108) == 0) {
      *(undefined4 *)(lVar1 + 300) = 0;
      *(undefined8 *)(lVar1 + 0x118) = 0;
      *(undefined4 *)(lVar1 + 0x124) = 0;
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisFSendNetBufferLists_wrapper @ 140018830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFSendNetBufferLists_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
               longlong param_5,undefined *param_6)

{
  longlong lVar1;
  longlong local_28 [2];
  
  local_28[0] = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_28[0] = 0;
    if (param_5 != 0) {
      local_28[0] = *(longlong *)(param_5 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_5,'\0');
  }
  lVar1 = local_28[0];
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (local_28[0] != 0)) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_28[0] + 0x100),(int)DAT_1400598f0,param_2,param_3);
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_5,'\0');
  }
  (*(code *)param_6)(param_1,param_2,param_3,param_4);
  return;
}



===== XdvNdisFilterPauseHandler_wrapper @ 140018930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XdvNdisFilterPauseHandler_wrapper
              (undefined8 param_1,undefined8 param_2,longlong param_3,undefined *param_4)

{
  int iVar1;
  int *piVar2;
  int *local_res20;
  
  local_res20 = (int *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_res20 = (int *)0x0;
    if (param_3 != 0) {
      local_res20 = *(int **)(param_3 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)&local_res20,param_3,'\0');
  }
  piVar2 = local_res20;
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (local_res20 != (int *)0x0)) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    local_res20[0x3f] = (int)DAT_1400598f0;
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)local_res20,param_3,'\0');
  }
  iVar1 = (*(code *)param_4)(param_1,param_2);
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    StartCriticalSectionNdisGroup((longlong *)&local_res20,param_3,'\0');
    piVar2 = local_res20;
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (piVar2 != (int *)0x0)) {
    if (iVar1 == 0) {
      piVar2[0x3f] = 0;
    }
    else if (iVar1 != 0x103) {
      SLIC_StatefulAbort("The filter driver can only return NDIS_STATUS_SUCCESS or NDIS_STATUS_PENDING from FilterPause."
                         ,0x92010,piVar2,(longlong *)(piVar2 + 0x3f),(longlong *)0x0,4);
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar2,param_3,'\0');
  }
  return iVar1;
}



===== XdvNdisFilterReceiveNetBufferListsHandler_wrapper @ 140018a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFilterReceiveNetBufferListsHandler_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
               uint param_5,longlong param_6,undefined *param_7)

{
  longlong lVar1;
  longlong local_38 [2];
  
  local_38[0] = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_38[0] = 0;
    if (param_6 != 0) {
      local_38[0] = *(longlong *)(param_6 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_38,param_6,'\0');
  }
  lVar1 = local_38[0];
  if (((((uint)XdvRuleClasses & 0x200000) != 0) && (local_38[0] != 0)) && ((param_5 & 2) == 0)) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_38[0] + 0x138),(int)DAT_1400598f0,param_2,param_3);
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_6,'\0');
  }
  (*(code *)param_7)(param_1,param_2,param_3,param_4,param_5);
  return;
}



===== XdvNdisFilterReturnNetBufferListsHandler_wrapper @ 140018ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFilterReturnNetBufferListsHandler_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,longlong param_4,
               undefined *param_5)

{
  longlong lVar1;
  longlong local_28 [2];
  
  lVar1 = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_4 == 0) {
      local_28[0] = 0;
    }
    else {
      local_28[0] = *(longlong *)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_4,'\0');
    lVar1 = local_28[0];
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (lVar1 != 0)) {
    XdvNdisDataComplete((longlong *)(lVar1 + 0x130),param_2);
    if (*(longlong *)(lVar1 + 0x130) == 0) {
      *(undefined4 *)(lVar1 + 0x158) = 0;
      *(undefined8 *)(lVar1 + 0x140) = 0;
      *(undefined4 *)(lVar1 + 0x150) = 0;
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisFilterSendNetBufferListsCompleteHandler_wrapper @ 140018c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFilterSendNetBufferListsCompleteHandler_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,longlong param_4,
               undefined *param_5)

{
  longlong lVar1;
  longlong local_28 [2];
  
  lVar1 = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_4 == 0) {
      local_28[0] = 0;
    }
    else {
      local_28[0] = *(longlong *)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_4,'\0');
    lVar1 = local_28[0];
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (lVar1 != 0)) {
    XdvNdisDataComplete((longlong *)(lVar1 + 0x100),param_2);
    if (*(longlong *)(lVar1 + 0x100) == 0) {
      *(undefined4 *)(lVar1 + 0x128) = 0;
      *(undefined8 *)(lVar1 + 0x110) = 0;
      *(undefined4 *)(lVar1 + 0x120) = 0;
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisFilterSendNetBufferListsHandler_wrapper @ 140018d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisFilterSendNetBufferListsHandler_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
               longlong param_5,undefined *param_6)

{
  longlong lVar1;
  longlong local_28 [2];
  
  local_28[0] = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_28[0] = 0;
    if (param_5 != 0) {
      local_28[0] = *(longlong *)(param_5 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_5,'\0');
  }
  lVar1 = local_28[0];
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (local_28[0] != 0)) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_28[0] + 0x108),(int)DAT_1400598f0,param_2,param_3);
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_5,'\0');
  }
  (*(code *)param_6)(param_1,param_2,param_3,param_4);
  return;
}



===== XdvNdisFreeVerifierContext_wrapper @ 140018e80 =====

void XdvNdisFreeVerifierContext_wrapper(longlong *param_1)

{
  longlong lVar1;
  
  if ((((uint)XdvRuleClasses & 0x220000) != 0) && (param_1 != (longlong *)0x0)) {
    XdvTimedRemoveContext(2,param_1);
    lVar1 = param_1[6];
    if (lVar1 != 0) {
      if (*(int *)(lVar1 + 0x28) != 0) {
        *(undefined4 *)(lVar1 + 0x28) = 3;
        return;
      }
      ExFreePoolWithTag(lVar1,0x4e766458);
      param_1[6] = 0;
    }
    ExFreePoolWithTag(param_1,0x4e766458);
  }
  return;
}



===== XdvNdisMIndicateStatusEx_wrapper @ 140018f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMIndicateStatusEx_wrapper
               (undefined8 param_1,longlong param_2,longlong param_3,undefined *param_4)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  longlong *local_res20;
  int *local_38 [2];
  
  local_38[0] = (int *)0x0;
  local_res20 = (longlong *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_38[0] = (int *)0x0;
    if (param_3 != 0) {
      local_38[0] = *(int **)(param_3 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)local_38,param_3,'\0');
  }
  piVar3 = local_38[0];
  if (((uint)XdvRuleClasses & 0x200000) == 0) goto LAB_14001954c;
  if (local_38[0] != (int *)0x0) {
    FindCreateWatchedState
              ((longlong *)(local_38[0] + 0x5e),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\0',
               (longlong *)&local_res20);
    FindCreateWatchedState
              ((longlong *)(piVar3 + 0x5c),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\0',
               (longlong *)&local_res20);
    FindCreateWatchedState
              ((longlong *)(piVar3 + 0x5a),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\0',
               (longlong *)&local_res20);
  }
  if ((((uint)XdvRuleClasses & 0x200000) == 0) || (piVar3 == (int *)0x0)) goto LAB_14001954c;
  FindWatchedState(*(longlong **)(piVar3 + 0x60),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\x01',
                   '\0',&local_res20);
  if ((local_res20 != (longlong *)0x0) && (*(int *)(param_2 + 0x14) == 0x40030000)) {
    FreeWatchedState((longlong *)&local_res20,0x78,(longlong *)(piVar3 + 0x60));
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    iVar1 = *(int *)(param_2 + 0x14);
    if ((iVar1 == 0x40030003) || (iVar1 == 0x4003002a)) {
      if (*(int *)(*(longlong *)(param_2 + 0x30) + 0xc) == 0) {
        LOCK();
        if (DAT_1400598f0 == 0) {
          DAT_1400598f0 = 0;
        }
        UNLOCK();
        local_38[0][0x3e] = (int)DAT_1400598f0;
        piVar3 = local_38[0];
      }
    }
    else if (((iVar1 + 0xbffcfffaU & 0xfffffff9) == 0) && (iVar1 != 0x4003000a)) {
      piVar3[0x3e] = 0;
    }
    if ((*(int *)(param_2 + 0x10) == 0) && (*(int *)(param_2 + 0x14) == 0x40030004)) {
      if (*(char *)((longlong)piVar3 + 0xef) == '\0') {
        if ((*(char *)((longlong)piVar3 + 0xed) == '\0') && ((char)piVar3[0x3b] == '\0')) {
          SLIC_StatefulAbort("NDIS_STATUS_DOT11_CONNECTION_START is inidcated without a prevoius OID_DOT11_CONNECT_REQUEST."
                             ,0x94009,piVar3,(longlong *)(piVar3 + 0x3a),(longlong *)0x0,8);
        }
      }
      else {
        if (*(char *)((longlong)piVar3 + 0xef) == '\x03') {
          *(undefined2 *)((longlong)piVar3 + 0xee) = 0;
        }
        else {
          *(undefined1 *)((longlong)piVar3 + 0xee) = 1;
        }
        piVar3[0x3a] = 0;
      }
    }
  }
  FindWatchedState(*(longlong **)(piVar3 + 0x5e),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\x01',
                   '\0',&local_res20);
  if (local_res20 != (longlong *)0x0) {
    if ((*(int *)(param_2 + 0x14) + 0xbffcfffcU & 0xfffffffd) == 0) {
      LOCK();
      if (DAT_1400598f0 == 0) {
        DAT_1400598f0 = 0;
      }
      UNLOCK();
      *(int *)(local_res20 + 0xe) = (int)DAT_1400598f0;
      piVar3 = local_38[0];
    }
    else if (((*(int *)(param_2 + 0x14) + 0xbffcfffbU & 0xfffffffd) == 0) ||
            ((int)local_res20[0xe] == 0)) {
      FreeWatchedState((longlong *)&local_res20,0x78,(longlong *)(piVar3 + 0x5e));
    }
  }
  FindWatchedState(*(longlong **)(piVar3 + 0x5c),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\x01',
                   '\0',&local_res20);
  if (local_res20 != (longlong *)0x0) {
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0x40030002) {
      LOCK();
      if (DAT_1400598f0 == 0) {
        DAT_1400598f0 = 0;
      }
      UNLOCK();
      *(int *)(local_res20 + 0xe) = (int)DAT_1400598f0;
      piVar3 = local_38[0];
    }
    else if (((iVar1 == 0x40030003) || (iVar1 == 0x4003002a)) || ((int)local_res20[0xe] == 0)) {
      FreeWatchedState((longlong *)&local_res20,0x78,(longlong *)(piVar3 + 0x5c));
    }
  }
  if ((*(int *)(param_2 + 0x10) == 0) && (*(char *)((longlong)piVar3 + 0xdd) != '\x01')) {
    iVar1 = *(int *)(param_2 + 0x14);
    if ((iVar1 == 0x40030003) || (iVar1 == 0x4003002a)) {
      if (*(int *)(*(longlong *)(param_2 + 0x30) + 0xc) == 0) {
        *(undefined1 *)(piVar3 + 0x39) = 1;
      }
    }
    else if (iVar1 == 0x40030008) {
      if ((char)piVar3[0x39] == '\x01') {
        *(undefined1 *)(piVar3 + 0x39) = 0;
      }
      else if ((char)*(longlong *)(piVar3 + 0x37) == '\0') {
        SLIC_StatefulAbort("NDIS_STATUS_DOT11_DISASSOCIATION without NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION first."
                           ,0x93006,piVar3,(longlong *)(piVar3 + 0x37),(longlong *)0x0,0xc);
      }
    }
  }
  FindWatchedState(*(longlong **)(piVar3 + 0x5a),0x78,(ulonglong)*(uint *)(param_2 + 0x10),'\x01',
                   '\0',&local_res20);
  if (local_res20 != (longlong *)0x0) {
    if (*(int *)(param_2 + 0x10) != 0) goto LAB_140019390;
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0x40030004) {
      if (*(char *)((longlong)local_res20 + 0x71) == '\x01') {
        pcVar2 = 
        "NDIS_STATUS_DOT11_CONNECTION_COMPLETION missing for the previous NDIS_STATUS_DOT11_CONNECTION_START."
        ;
      }
      else {
        if ((char)local_res20[0xe] != '\x01') {
          *(undefined1 *)((longlong)local_res20 + 0x71) = 1;
          goto LAB_14001939e;
        }
        pcVar2 = 
        "NDIS_STATUS_DOT11_CONNECTION_START indicated between NDIS_STATUS_DOT11_ROAMING_START and NDIS_STATUS_DOT11_ROAMING_COMPLETION."
        ;
      }
    }
    else {
      if (iVar1 != 0x40030006) {
        if (iVar1 == 0x40030005) {
          if (*(char *)((longlong)local_res20 + 0x71) != '\x01') {
            pcVar2 = 
            "NDIS_STATUS_DOT11_CONNECTION_COMPLETION without an NDIS_STATUS_DOT11_CONNECTION_START indicated first."
            ;
            goto LAB_1400193f6;
          }
          *(undefined1 *)((longlong)local_res20 + 0x71) = 0;
        }
        else if (iVar1 == 0x40030007) {
          if ((char)local_res20[0xe] != '\x01') {
            pcVar2 = 
            "NDIS_STATUS_DOT11_ROAMING_COMPLETION without an NDIS_STATUS_DOT11_ROAMING_START indicated first."
            ;
            goto LAB_1400193f6;
          }
          *(undefined1 *)(local_res20 + 0xe) = 0;
        }
        else if ((*(char *)((longlong)local_res20 + 0x71) == '\x01') ||
                ((char)local_res20[0xe] == '\x01')) goto LAB_14001939e;
LAB_140019390:
        FreeWatchedState((longlong *)&local_res20,0x78,(longlong *)(piVar3 + 0x5a));
        goto LAB_14001939e;
      }
      if (*(char *)((longlong)local_res20 + 0x71) == '\x01') {
        pcVar2 = 
        "NDIS_STATUS_DOT11_ROAMING_START indicated between NDIS_STATUS_DOT11_CONNECTION_START and NDIS_STATUS_DOT11_CONNECTION_COMPLETION."
        ;
      }
      else {
        if ((char)local_res20[0xe] != '\x01') {
          *(undefined1 *)(local_res20 + 0xe) = 1;
          goto LAB_14001939e;
        }
        pcVar2 = 
        "NDIS_STATUS_DOT11_ROAMING_COMPLETION missing for the previous NDIS_STATUS_DOT11_ROAMING_START."
        ;
      }
    }
LAB_1400193f6:
    SLIC_StatefulAbort(pcVar2,0x93005,piVar3,local_res20,(longlong *)(piVar3 + 0x5a),0x78);
  }
LAB_14001939e:
  if ((*(int *)(param_2 + 0x10) == 0) && ((char)piVar3[0x35] != '\x01')) {
    iVar1 = *(int *)(param_2 + 0x14);
    if (iVar1 == 0x40030004) {
      *(undefined1 *)((longlong)piVar3 + 0xd3) = 1;
    }
    else if (iVar1 == 0x40030006) {
      *(undefined1 *)((longlong)piVar3 + 0xd2) = 1;
    }
    else {
      if (iVar1 == 0x40030005) {
        if (*(char *)((longlong)piVar3 + 0xd1) != '\x01') {
          *(undefined1 *)((longlong)piVar3 + 0xd3) = 0;
          goto LAB_14001954c;
        }
        if ((char)piVar3[0x34] != '\0') goto LAB_14001954c;
        pcVar2 = 
        "NDIS_STATUS_DOT11_CONNECTION_COMPLETION indicated without an NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION for an NDIS_STATUS_DOT11_ASSOCIATION_START."
        ;
      }
      else if (iVar1 == 0x40030007) {
        if (*(char *)((longlong)piVar3 + 0xd1) != '\x01') {
          *(undefined1 *)((longlong)piVar3 + 0xd2) = 0;
          goto LAB_14001954c;
        }
        if ((char)piVar3[0x34] != '\0') goto LAB_14001954c;
        pcVar2 = 
        "NDIS_STATUS_DOT11_ROAMING_COMPLETION indicated without an NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION for an NDIS_STATUS_DOT11_ASSOCIATION_START."
        ;
      }
      else if (iVar1 == 0x40030002) {
        if ((*(char *)((longlong)piVar3 + 0xd2) == '\x01') ||
           (*(char *)((longlong)piVar3 + 0xd3) == '\x01')) {
          if (*(char *)((longlong)piVar3 + 0xd1) != '\x01') {
            *(undefined1 *)((longlong)piVar3 + 0xd1) = 1;
            goto LAB_14001954c;
          }
          if ((char)piVar3[0x34] != '\0') goto LAB_14001954c;
          pcVar2 = "Double association start.";
        }
        else {
          if ((char)piVar3[0x34] != '\0') goto LAB_14001954c;
          pcVar2 = 
          "NDIS_STATUS_DOT11_ASSOCIATION_START indicated outside the connection/roaming operations."
          ;
        }
      }
      else {
        if ((iVar1 != 0x40030003) && (iVar1 != 0x4003002a)) goto LAB_14001954c;
        if (*(char *)((longlong)piVar3 + 0xd1) == '\x01') {
          *(undefined1 *)((longlong)piVar3 + 0xd1) = 0;
          goto LAB_14001954c;
        }
        if ((char)piVar3[0x34] != '\0') goto LAB_14001954c;
        pcVar2 = 
        "NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION indicated without an NDIS_STATUS_DOT11_ASSOCIATION_START first."
        ;
      }
      SLIC_StatefulAbort(pcVar2,0x93004,piVar3,(longlong *)(piVar3 + 0x34),(longlong *)0x0,0xc);
    }
  }
LAB_14001954c:
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar3,param_3,'\0');
  }
  (*(code *)param_4)(param_1,param_2);
  return;
}



===== XdvNdisMOidRequestComplete_wrapper @ 1400195a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMOidRequestComplete_wrapper
               (undefined8 param_1,longlong param_2,int param_3,longlong param_4,undefined *param_5)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  longlong local_38;
  int *local_30;
  
  local_30 = (int *)0x0;
  local_38 = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_30 = (int *)0x0;
    if (param_4 != 0) {
      local_30 = *(int **)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)&local_30,param_4,'\0');
  }
  piVar5 = local_30;
  if (((((uint)XdvRuleClasses >> 0x15 & 1) != 0) || (((uint)XdvRuleClasses >> 0x11 & 1) != 0)) &&
     (local_30 != (int *)0x0)) {
    plVar1 = (longlong *)(local_30 + 0x2c);
    cVar2 = (char)*plVar1;
    if ((cVar2 == '\0') || (cVar2 == '\x03')) {
      pcVar4 = "Double OID completion detected at NdisMOidRequestComplete.";
LAB_14001966b:
      SLIC_StatefulAbort(pcVar4,0x91002,local_30,plVar1,(longlong *)0x0,0x10);
    }
    else {
      if (*(longlong *)(local_30 + 0x2e) != param_2) {
        pcVar4 = 
        "A different OID is being completed at NdisMOidRequestComplete rather than the one previously sent by MiniportOidRequest."
        ;
        goto LAB_14001966b;
      }
      if (cVar2 == '\x01') {
        *(undefined1 *)plVar1 = 3;
      }
      else if (cVar2 == '\x02') {
        *(undefined1 *)plVar1 = 0;
      }
    }
    if ((char)*(longlong *)(piVar5 + 0x12) == '\0') {
      if (param_3 == 0x103) {
        pcVar4 = 
        "NdisMOidRequestComplete should not be called with 3rd parameter (i.e., Status) as NDIS_STATUS_PENDING."
        ;
        goto LAB_14001980c;
      }
      if (param_2 != 0) {
        iVar3 = *(int *)(param_2 + 0x20);
        if (*(int *)(param_2 + 0x20) == -0x2fefeff) {
          if ((param_3 != 0x10003) && (param_3 != 0)) {
            pcVar4 = 
            "This OID should only be completed with NDIS_STATUS_NOT_ACCEPTED or NDIS_STATUS_SUCCESS."
            ;
LAB_14001980c:
            SLIC_StatefulAbort(pcVar4,0x91001,piVar5,(longlong *)(piVar5 + 0x12),(longlong *)0x0,
                               0x10);
          }
        }
        else if (((((iVar3 == 0x10228) || (iVar3 == -0x3fcfdfd)) ||
                  ((iVar3 == 0x10224 ||
                   ((((iVar3 == 0x10246 || (iVar3 == 0x10239)) || (iVar3 == 0x1010209)) ||
                    ((iVar3 == -0x2fefef5 || (iVar3 == -0x2fefef1)))))))) || (iVar3 == 0xf010107))
                && (((param_3 != 0x10003 && (param_3 != -0x3ffefff4)) && (param_3 != 0)))) {
          pcVar4 = 
          "This OID should only be completed with NDIS_STATUS_NOT_ACCEPTED, NDIS_STATUS_REQUEST_ABORTED, or NDIS_STATUS_SUCCESS."
          ;
          goto LAB_14001980c;
        }
      }
    }
  }
  if ((((uint)XdvRuleClasses & 0x200000) == 0) || (piVar5 == (int *)0x0)) goto LAB_140019a90;
  FindWatchedState(*(longlong **)(piVar5 + 0x60),0x78,(ulonglong)*(uint *)(param_2 + 8),'\x01','\0',
                   &local_38);
  if ((local_38 == 0) || (*(int *)(param_2 + 0x20) != 0xd01030b)) {
    if (param_3 == 0) goto LAB_1400198b7;
  }
  else if (param_3 == 0) {
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    *(int *)(local_38 + 0x70) = (int)DAT_1400598f0;
    *(undefined1 *)(local_38 + 0x74) = 3;
    piVar5 = local_30;
LAB_1400198b7:
    iVar3 = piVar5[0x3d];
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        if ((char)piVar5[0x3c] != '\0') {
          piVar5[0x3e] = 0;
        }
        *(undefined1 *)(piVar5 + 0x3c) = 0;
      }
      else if (iVar3 == 2) {
        *(undefined1 *)(piVar5 + 0x3c) = 1;
      }
      piVar5[0x3d] = 0;
    }
  }
  *(undefined1 *)(piVar5 + 0x3b) = 0;
  if ((*(int *)(param_2 + 8) == 0) && (*(int *)(param_2 + 0x20) == 0xe010181)) {
    if (param_3 == 0) {
      if (*(char *)((longlong)piVar5 + 0xee) == '\x01') {
        *(undefined2 *)((longlong)piVar5 + 0xee) = 0;
        piVar5[0x3a] = 0;
      }
LAB_140019999:
      iVar3 = piVar5[0x38];
      if (iVar3 != 0) {
        if (iVar3 == 1) {
          if (*(char *)((longlong)piVar5 + 0xdd) != '\0') {
            *(undefined1 *)(piVar5 + 0x39) = 0;
          }
          *(undefined1 *)((longlong)piVar5 + 0xdd) = 0;
        }
        else if (iVar3 == 2) {
          *(undefined1 *)((longlong)piVar5 + 0xdd) = 1;
        }
        piVar5[0x38] = 0;
      }
      iVar3 = piVar5[0x36];
      if (iVar3 != 0) {
        if (iVar3 == 1) {
          if ((char)piVar5[0x35] != '\0') {
            *(undefined2 *)((longlong)piVar5 + 0xd2) = 0;
            *(undefined1 *)((longlong)piVar5 + 0xd1) = 0;
          }
          *(undefined1 *)(piVar5 + 0x35) = 0;
        }
        else if (iVar3 == 2) {
          *(undefined1 *)(piVar5 + 0x35) = 1;
        }
        piVar5[0x36] = 0;
      }
    }
    else if (*(char *)((longlong)piVar5 + 0xee) == '\x01') {
      if (*(char *)((longlong)piVar5 + 0xed) == '\0') {
        SLIC_StatefulAbort("OID_DOT11_CONNECT_REQUEST is failed by NdisMOidRequestComplete after NDIS_STATUS_DOT11_CONNECTION_START is inidcated."
                           ,0x94009,piVar5,(longlong *)(piVar5 + 0x3a),(longlong *)0x0,8);
      }
    }
    else {
      *(undefined2 *)((longlong)piVar5 + 0xee) = 0;
      piVar5[0x3a] = 0;
    }
  }
  else if (param_3 == 0) goto LAB_140019999;
  FindWatchedState(*(longlong **)(piVar5 + 0x58),0x78,param_2,'\x01','\x01',&local_38);
  if (local_38 != 0) {
    FreeWatchedState(&local_38,0x78,(longlong *)(piVar5 + 0x58));
  }
  if (*(longlong *)(piVar5 + 0x32) == param_2) {
    *(undefined1 *)(piVar5 + 0x30) = 0;
  }
  else {
    SLIC_StatefulAbort("A different OID is being completed other than the pending OID.",0x9100e,
                       piVar5,(longlong *)(piVar5 + 0x30),(longlong *)0x0,0x10);
  }
LAB_140019a90:
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar5,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisMSendNetBufferListsComplete_wrapper @ 140019af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMSendNetBufferListsComplete_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,longlong param_4,
               undefined *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *local_28 [2];
  
  local_28[0] = (int *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_28[0] = (int *)0x0;
    if (param_4 != 0) {
      local_28[0] = *(int **)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)local_28,param_4,'\0');
  }
  piVar5 = local_28[0];
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (local_28[0] != (int *)0x0)) {
    if (((XdvVerifierOptions & 0x10000) != 0) &&
       (lVar2 = *(longlong *)(local_28[0] + 0x24), lVar2 != 0)) {
      local_28[0][0x2a] = *(int *)(lVar2 + 0x10);
      local_28[0][0x28] = *(int *)(lVar2 + 0x14);
      *(undefined8 *)(local_28[0] + 0x26) = *(undefined8 *)(lVar2 + 0x18);
      LOCK();
      if (DAT_1400598f0 == 0) {
        DAT_1400598f0 = 0;
      }
      UNLOCK();
      iVar4 = (int)DAT_1400598f0 - local_28[0][0x29];
      local_28[0][0x22] = iVar4;
      if (XDV_NDISDATAHANG_TIMELIMIT <= iVar4) {
        *(undefined8 *)(local_28[0] + 0xc) = *(undefined8 *)(local_28[0] + 0x26);
        local_28[0][0xf] = (int)*(longlong *)(local_28[0] + 0x20);
        local_28[0][0xe] = iVar4;
        *(undefined1 *)(local_28[0] + 0x10) = 0;
        SLIC_StatefulAbort("9: The miniport driver didn\'t process any NBL too long before this moment."
                           ,0x9200f,local_28[0],(longlong *)(local_28[0] + 0x20),(longlong *)0x0,
                           0x30);
      }
    }
    if (*(longlong *)(piVar5 + 0x24) != 0) {
      XdvNdisDataComplete((longlong *)(piVar5 + 0x24),param_2);
      if (piVar5[0x20] != 0) {
        piVar5[0x20] = piVar5[0x20] + -1;
      }
    }
    piVar3 = local_28[0];
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    local_28[0][0x29] = (int)DAT_1400598f0;
    if (((XdvVerifierOptions & 0x10000) == 0) && (*(longlong *)(local_28[0] + 0x1a) != 0)) {
      XdvNdisDataComplete((longlong *)(local_28[0] + 0x1a),param_2);
      if (piVar3[0x16] != 0) {
        piVar3[0x16] = piVar3[0x16] + -1;
      }
    }
    plVar1 = (longlong *)(piVar3 + 0x1a);
    lVar2 = *plVar1;
    piVar5 = piVar3;
    if (lVar2 != 0) {
      piVar3[0x1f] = *(int *)(lVar2 + 0x10);
      piVar3[0x1e] = *(int *)(lVar2 + 0x14);
      *(undefined8 *)(piVar3 + 0x1c) = *(undefined8 *)(lVar2 + 0x18);
      LOCK();
      if (DAT_1400598f0 == 0) {
        DAT_1400598f0 = 0;
      }
      UNLOCK();
      iVar4 = (int)DAT_1400598f0 - piVar3[0x1f];
      local_28[0][0x18] = iVar4;
      piVar5 = local_28[0];
      if (XDV_NDISDATASEND_TIMELIMIT <= iVar4) {
        *(undefined8 *)(local_28[0] + 0xc) = *(undefined8 *)(piVar3 + 0x1c);
        local_28[0][0xf] = (int)*(longlong *)(local_28[0] + 0x16);
        local_28[0][0xe] = iVar4;
        *(undefined1 *)(local_28[0] + 0x10) = 0;
        SLIC_StatefulAbort("9: Timeout on sending a NET_BUFFER_LIST by MiniportSendNetBufferLists.",
                           0x9200d,local_28[0],(longlong *)(local_28[0] + 0x16),(longlong *)0x0,0x28
                          );
      }
    }
    if (((XdvVerifierOptions & 0x10000) != 0) && (*plVar1 != 0)) {
      XdvNdisDataComplete(plVar1,param_2);
      if (piVar5[0x16] != 0) {
        piVar5[0x16] = piVar5[0x16] + -1;
      }
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar5,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2,param_3);
  return;
}



===== XdvNdisMiniportDevicePnPEventNotifyHandler_wrapper @ 140019d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMiniportDevicePnPEventNotifyHandler_wrapper
               (undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4,
               undefined *param_5)

{
  longlong local_18 [2];
  
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    if (param_4 == 0) {
      local_18[0] = 0;
    }
    else {
      local_18[0] = *(longlong *)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_18,param_4,'\0');
    if (((uint)XdvRuleClasses & 0x220000) != 0) {
      if ((local_18[0] != 0) && (*(int *)(param_2 + 8) == 2)) {
        *(undefined1 *)(local_18[0] + 0x48) = 1;
      }
      EndCriticalSectionNdisGroup(local_18[0],param_4,'\0');
    }
  }
  (*(code *)param_5)(param_1,param_2);
  return;
}



===== XdvNdisMiniportHaltExHandler_wrapper @ 140019e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMiniportHaltExHandler_wrapper
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,longlong param_4,
               undefined *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *local_28 [2];
  
  plVar4 = (longlong *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_28[0] = (longlong *)0x0;
    if (param_4 != 0) {
      local_28[0] = *(longlong **)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)local_28,param_4,'\0');
    plVar4 = local_28[0];
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (plVar4 != (longlong *)0x0)) {
    plVar1 = plVar4 + 0x30;
    plVar3 = (longlong *)*plVar1;
    while (plVar3 != (longlong *)0x0) {
      local_28[0] = plVar3;
      FreeWatchedState((longlong *)local_28,0x78,plVar1);
      plVar2 = (longlong *)*plVar1;
      if ((plVar2 == (longlong *)0x0) ||
         ((plVar3 = plVar2, local_28[0] != (longlong *)0x0 &&
          (plVar3 = (longlong *)*local_28[0], plVar3 == plVar2)))) break;
    }
    *(undefined8 *)((longlong)plVar4 + 0xf4) = 0;
    plVar1 = plVar4 + 0x2f;
    *(undefined4 *)((longlong)plVar4 + 0xed) = 1;
    *(undefined4 *)(plVar4 + 0x1d) = 0;
    plVar3 = (longlong *)*plVar1;
    while (plVar3 != (longlong *)0x0) {
      local_28[0] = plVar3;
      FreeWatchedState((longlong *)local_28,0x78,plVar1);
      plVar2 = (longlong *)*plVar1;
      if ((plVar2 == (longlong *)0x0) ||
         ((plVar3 = plVar2, local_28[0] != (longlong *)0x0 &&
          (plVar3 = (longlong *)*local_28[0], plVar3 == plVar2)))) break;
    }
    plVar1 = plVar4 + 0x2e;
    plVar3 = (longlong *)*plVar1;
    while (plVar3 != (longlong *)0x0) {
      local_28[0] = plVar3;
      FreeWatchedState((longlong *)local_28,0x78,plVar1);
      plVar2 = (longlong *)*plVar1;
      if ((plVar2 == (longlong *)0x0) ||
         ((plVar3 = plVar2, local_28[0] != (longlong *)0x0 &&
          (plVar3 = (longlong *)*local_28[0], plVar3 == plVar2)))) break;
    }
    *(undefined4 *)(plVar4 + 0x1c) = 0;
    plVar1 = plVar4 + 0x2d;
    *(undefined2 *)((longlong)plVar4 + 0xdc) = 1;
    *(undefined1 *)((longlong)plVar4 + 0xe4) = 0;
    plVar3 = (longlong *)*plVar1;
    while (local_28[0] = plVar3, plVar3 != (longlong *)0x0) {
      FreeWatchedState((longlong *)local_28,0x78,plVar1);
      plVar2 = (longlong *)*plVar1;
      if ((plVar2 == (longlong *)0x0) ||
         ((plVar3 = plVar2, local_28[0] != (longlong *)0x0 &&
          (plVar3 = (longlong *)*local_28[0], plVar3 == plVar2)))) break;
    }
    *(undefined4 *)(plVar4 + 0x1b) = 0;
    *(undefined4 *)((longlong)plVar4 + 0xd1) = 0;
    *(undefined1 *)(plVar4 + 0x1a) = 1;
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)plVar4,param_4,'\0');
  }
  (*(code *)param_5)(param_1,param_2);
  return;
}



===== XdvNdisMiniportOidRequestHandler_wrapper @ 14001a020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int XdvNdisMiniportOidRequestHandler_wrapper
              (undefined8 param_1,longlong param_2,undefined8 param_3,longlong param_4,
              undefined *param_5)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong *plVar5;
  char *pcVar6;
  longlong *plVar7;
  int *piVar8;
  int *piVar9;
  longlong *local_38;
  int *local_30;
  
  local_30 = (int *)0x0;
  local_38 = (longlong *)0x0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_30 = (int *)0x0;
    if (param_4 != 0) {
      local_30 = *(int **)(param_4 + 0x30);
    }
    StartCriticalSectionNdisGroup((longlong *)&local_30,param_4,'\0');
    if ((((uint)XdvRuleClasses & 0x220000) != 0) && (local_30 != (int *)0x0)) {
      *(longlong *)(local_30 + 0x2e) = param_2;
      *(undefined1 *)(local_30 + 0x2c) = 1;
      if (param_2 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_2 + 0x20);
      }
      local_30[0x13] = iVar3;
      *(longlong *)(local_30 + 0x14) = param_2;
    }
  }
  piVar8 = local_30;
  if (((uint)XdvRuleClasses & 0x200000) != 0) {
    if (local_30 != (int *)0x0) {
      FindCreateWatchedState
                ((longlong *)(local_30 + 0x60),0x78,(ulonglong)*(uint *)(param_2 + 8),'\0',
                 (longlong *)&local_38);
      CreateWatchedState((longlong *)(piVar8 + 0x58),0x78,param_2,'\x01',&local_38);
    }
    if ((((uint)XdvRuleClasses & 0x200000) != 0) && (piVar8 != (int *)0x0)) {
      plVar1 = (longlong *)(piVar8 + 0x60);
      FindWatchedState((longlong *)*plVar1,0x78,(ulonglong)*(uint *)(param_2 + 8),'\x01','\0',
                       &local_38);
      if (local_38 != (longlong *)0x0) {
        if (*(int *)(param_2 + 0x20) == -0x2fefeff) {
          FreeWatchedList(plVar1);
        }
        else if (*(char *)((longlong)local_38 + 0x74) == '\0') {
          if (*(int *)(param_2 + 0x20) == 0xd01030b) {
            *(undefined1 *)((longlong)local_38 + 0x74) = 1;
          }
          else {
            FreeWatchedState((longlong *)&local_38,0x78,plVar1);
          }
        }
      }
      piVar9 = (int *)(param_2 + 0x20);
      iVar3 = *(int *)(param_2 + 0x20);
      if (*(int *)(param_2 + 0x20) == -0x2fefeff) {
LAB_14001a22f:
        piVar8[0x3e] = 0;
      }
      else if (*(int *)(param_2 + 8) == 0) {
        if (iVar3 == 0xe01018e) goto LAB_14001a22f;
        if (iVar3 == 0xe01017f) {
          if (*(int *)(param_2 + 4) == 1) {
            if (*(uint *)(param_2 + 0x30) < 4) {
              iVar3 = 0;
            }
            else {
              iVar3 = **(int **)(param_2 + 0x28);
            }
            piVar8[0x3d] = iVar3;
          }
        }
        else if (iVar3 == 0xd010310) {
          piVar8[0x3d] = 1;
          piVar8[0x3e] = 0;
        }
      }
      iVar3 = *piVar9;
      if (*piVar9 == -0x2fefeff) {
LAB_14001a328:
        piVar8[0x3a] = 0;
      }
      else if (*(int *)(param_2 + 8) == 0) {
        if (iVar3 == 0xe010181) {
          *(undefined1 *)((longlong)piVar8 + 0xef) = 1;
          LOCK();
          if (DAT_1400598f0 == 0) {
            DAT_1400598f0 = 0;
          }
          UNLOCK();
          local_30[0x3a] = (int)DAT_1400598f0;
          piVar8 = local_30;
        }
        else if ((iVar3 == 0xe01018e) || (iVar3 == 0xd010310)) {
          *(undefined2 *)((longlong)piVar8 + 0xee) = 0;
          *(undefined1 *)(piVar8 + 0x3b) = 1;
          goto LAB_14001a328;
        }
      }
      plVar1 = (longlong *)(piVar8 + 0x5e);
      local_38 = (longlong *)*plVar1;
      do {
        while( true ) {
          if (local_38 == (longlong *)0x0) goto LAB_14001a390;
          if (*piVar9 == -0x2fefeff) {
            FreeWatchedState((longlong *)&local_38,0x78,plVar1);
          }
          plVar4 = (longlong *)*plVar1;
          if (plVar4 == (longlong *)0x0) goto LAB_14001a390;
          if (local_38 != (longlong *)0x0) break;
          local_38 = plVar4;
        }
        local_38 = (longlong *)*local_38;
      } while (local_38 != plVar4);
LAB_14001a390:
      plVar1 = (longlong *)(piVar8 + 0x5c);
      plVar4 = (longlong *)*plVar1;
      while (local_38 = plVar4, plVar4 != (longlong *)0x0) {
        plVar7 = plVar4;
        if (*piVar9 == -0x2fefeff) {
          FreeWatchedState((longlong *)&local_38,0x78,plVar1);
          plVar7 = local_38;
        }
        local_38 = (longlong *)0x0;
        plVar5 = (longlong *)*plVar1;
        if ((plVar5 == (longlong *)0x0) ||
           ((plVar4 = plVar5, plVar7 != (longlong *)0x0 &&
            (plVar4 = (longlong *)*plVar7, plVar4 == plVar5)))) break;
      }
      if (*(int *)(param_2 + 8) == 0) {
        if (*piVar9 == 0xe01017f) {
          if (*(int *)(param_2 + 4) == 1) {
            if (*(uint *)(param_2 + 0x30) < 4) {
              iVar3 = 0;
            }
            else {
              iVar3 = **(int **)(param_2 + 0x28);
            }
            piVar8[0x38] = iVar3;
          }
        }
        else if (*piVar9 == 0xd010310) {
          piVar8[0x38] = 1;
        }
        if (*(int *)(param_2 + 8) == 0) {
          if (*piVar9 == 0xe01017f) {
            if (*(int *)(param_2 + 4) == 1) {
              if (*(uint *)(param_2 + 0x30) < 4) {
                iVar3 = 0;
              }
              else {
                iVar3 = **(int **)(param_2 + 0x28);
              }
              piVar8[0x36] = iVar3;
            }
          }
          else if (*piVar9 == 0xd010310) {
            piVar8[0x36] = 1;
          }
        }
      }
      FindWatchedState(*(longlong **)(piVar8 + 0x58),0x78,param_2,'\x01','\x01',&local_38);
      if (local_38 != (longlong *)0x0) {
        LOCK();
        if (DAT_1400598f0 == 0) {
          DAT_1400598f0 = 0;
        }
        UNLOCK();
        *(int *)(local_38 + 0xe) = (int)DAT_1400598f0;
        piVar8 = local_30;
      }
      plVar1 = (longlong *)(piVar8 + 0x30);
      if ((char)*plVar1 == '\x01') {
        SLIC_StatefulAbort("Double OID request detected at MiniportOidRequest.",0x9100e,piVar8,
                           plVar1,(longlong *)0x0,0x10);
      }
      else {
        *(undefined1 *)plVar1 = 1;
        *(longlong *)(piVar8 + 0x32) = param_2;
      }
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar8,param_4,'\0');
  }
  iVar3 = (*(code *)param_5)(param_1,param_2);
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    StartCriticalSectionNdisGroup((longlong *)&local_30,param_4,'\0');
    piVar8 = local_30;
  }
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (piVar8 != (int *)0x0)) {
    plVar1 = (longlong *)(piVar8 + 0x60);
    local_38 = (longlong *)*plVar1;
    if (local_38 != (longlong *)0x0) {
      do {
        pcVar6 = (char *)((longlong)local_38 + 0x74);
        plVar4 = local_38;
        if (*pcVar6 == '\x01') {
          if (iVar3 == 0x103) {
            *pcVar6 = '\x02';
          }
          else if (iVar3 == 0) {
            LOCK();
            if (DAT_1400598f0 == 0) {
              DAT_1400598f0 = 0;
            }
            UNLOCK();
            *(int *)(local_38 + 0xe) = (int)DAT_1400598f0;
            *pcVar6 = '\x03';
          }
          else {
            FreeWatchedState((longlong *)&local_38,0x78,plVar1);
            plVar4 = local_38;
          }
        }
        local_38 = (longlong *)0x0;
        plVar7 = (longlong *)*plVar1;
        if (plVar7 == (longlong *)0x0) break;
        plVar5 = plVar7;
        if (plVar4 != (longlong *)0x0) {
          plVar5 = (longlong *)*plVar4;
          if (plVar5 == plVar7) break;
        }
        local_38 = plVar5;
      } while (plVar5 != (longlong *)0x0);
      piVar8 = local_30;
    }
    if (iVar3 == 0) {
      iVar2 = piVar8[0x3d];
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          if ((char)piVar8[0x3c] != '\0') {
            piVar8[0x3e] = 0;
          }
          *(undefined1 *)(piVar8 + 0x3c) = 0;
        }
        else if (iVar2 == 2) {
          *(undefined1 *)(piVar8 + 0x3c) = 1;
        }
        piVar8[0x3d] = 0;
      }
LAB_14001a66d:
      *(undefined1 *)(piVar8 + 0x3b) = 0;
    }
    else if (iVar3 != 0x103) goto LAB_14001a66d;
    if (*(char *)((longlong)piVar8 + 0xef) == '\x01') {
      if (iVar3 == 0) {
        if (*(char *)((longlong)piVar8 + 0xee) == '\0') {
          *(undefined1 *)((longlong)piVar8 + 0xef) = 3;
        }
        else {
          *(undefined2 *)((longlong)piVar8 + 0xee) = 0;
          piVar8[0x3a] = 0;
        }
        goto LAB_14001a714;
      }
      if (iVar3 == 0x103) {
        *(undefined1 *)((longlong)piVar8 + 0xef) = 2;
      }
      else if (*(char *)((longlong)piVar8 + 0xee) == '\x01') {
        if (*(char *)((longlong)piVar8 + 0xed) == '\0') {
          SLIC_StatefulAbort("OID_DOT11_CONNECT_REQUEST is failed by MiniportOidRequest after NDIS_STATUS_DOT11_CONNECTION_START is inidcated."
                             ,0x94009,piVar8,(longlong *)(piVar8 + 0x3a),(longlong *)0x0,8);
        }
      }
      else {
        *(undefined2 *)((longlong)piVar8 + 0xee) = 0;
        piVar8[0x3a] = 0;
      }
    }
    else if (iVar3 == 0) {
LAB_14001a714:
      iVar2 = piVar8[0x38];
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          if (*(char *)((longlong)piVar8 + 0xdd) != '\0') {
            *(undefined1 *)(piVar8 + 0x39) = 0;
          }
          *(undefined1 *)((longlong)piVar8 + 0xdd) = 0;
        }
        else if (iVar2 == 2) {
          *(undefined1 *)((longlong)piVar8 + 0xdd) = 1;
        }
        piVar8[0x38] = 0;
      }
      iVar2 = piVar8[0x36];
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          if ((char)piVar8[0x35] != '\0') {
            *(undefined2 *)((longlong)piVar8 + 0xd2) = 0;
            *(undefined1 *)((longlong)piVar8 + 0xd1) = 0;
          }
          *(undefined1 *)(piVar8 + 0x35) = 0;
        }
        else if (iVar2 == 2) {
          *(undefined1 *)(piVar8 + 0x35) = 1;
        }
        piVar8[0x36] = 0;
      }
    }
    FindWatchedState(*(longlong **)(piVar8 + 0x58),0x78,param_2,'\x01','\x01',&local_38);
    if (iVar3 != 0x103) {
      if (local_38 != (longlong *)0x0) {
        FreeWatchedState((longlong *)&local_38,0x78,(longlong *)(piVar8 + 0x58));
      }
      if (*(longlong *)(piVar8 + 0x32) == param_2) {
        *(undefined1 *)(piVar8 + 0x30) = 0;
      }
      else {
        SLIC_StatefulAbort("A different OID is being completed other than the pending OID.",0x9100e,
                           piVar8,(longlong *)(piVar8 + 0x30),(longlong *)0x0,0x10);
      }
    }
  }
  if (((uint)XdvRuleClasses & 0x220000) == 0) {
    return iVar3;
  }
  if (piVar8 != (int *)0x0) {
    if (iVar3 == 0x103) {
      *(byte *)(piVar8 + 0x2c) = -((char)piVar8[0x2c] != '\x03') & 2;
    }
    else {
      plVar1 = (longlong *)(piVar8 + 0x2c);
      if ((char)*plVar1 == '\x03') {
        SLIC_StatefulAbort("Double OID completion detected at MiniportOidRequest.",0x91002,piVar8,
                           plVar1,(longlong *)0x0,0x10);
      }
      else {
        *(undefined1 *)plVar1 = 0;
      }
    }
    if ((char)*(longlong *)(piVar8 + 0x12) == '\0') {
      iVar2 = piVar8[0x13];
      if (iVar2 == -0x2fefeff) {
        if (((iVar3 == 0x103) || (iVar3 == 0x10003)) || (iVar3 == 0)) goto LAB_14001a935;
        pcVar6 = 
        "This OID should only be completed with NDIS_STATUS_NOT_ACCEPTED, NDIS_STATUS_SUCCESS, or NDIS_STATUS_PENDING."
        ;
      }
      else {
        if (((((0x22 < iVar2 - 0x10224U) ||
              ((0x400200011U >> ((ulonglong)(iVar2 - 0x10224U) & 0x3f) & 1) == 0)) &&
             ((iVar2 != -0x3fcfdfd && ((iVar2 != 0x1010209 && (iVar2 != -0x2fefef5)))))) &&
            ((iVar2 != -0x2fefef1 && (iVar2 != 0xf010107)))) ||
           ((((iVar3 == 0x103 || (iVar3 == 0x10003)) || (iVar3 == -0x3ffefff4)) || (iVar3 == 0))))
        goto LAB_14001a935;
        pcVar6 = 
        "This OID should only be completed with NDIS_STATUS_NOT_ACCEPTED, NDIS_STATUS_REQUEST_ABORTED, NDIS_STATUS_SUCCESS, or NDIS_STATUS_PENDING."
        ;
      }
      SLIC_StatefulAbort(pcVar6,0x91001,piVar8,(longlong *)(piVar8 + 0x12),(longlong *)0x0,0x10);
    }
  }
LAB_14001a935:
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup((longlong)piVar8,param_4,'\0');
  }
  return iVar3;
}



===== XdvNdisMiniportSendNetBufferListsHandler_wrapper @ 14001a980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void XdvNdisMiniportSendNetBufferListsHandler_wrapper
               (undefined8 param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,longlong param_6,undefined *param_7)

{
  longlong lVar1;
  longlong local_28 [2];
  
  local_28[0] = 0;
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    local_28[0] = 0;
    if (param_6 != 0) {
      local_28[0] = *(longlong *)(param_6 + 0x30);
    }
    StartCriticalSectionNdisGroup(local_28,param_6,'\0');
  }
  lVar1 = local_28[0];
  if ((((uint)XdvRuleClasses & 0x200000) != 0) && (local_28[0] != 0)) {
    if (*(longlong *)(local_28[0] + 0x90) == 0) {
      LOCK();
      if (DAT_1400598f0 == 0) {
        DAT_1400598f0 = 0;
      }
      UNLOCK();
      *(int *)(local_28[0] + 0xa4) = (int)DAT_1400598f0;
    }
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_28[0] + 0x90),(int)DAT_1400598f0,param_2,param_3);
    lVar1 = local_28[0];
    *(int *)(local_28[0] + 0x80) = *(int *)(local_28[0] + 0x80) + 1;
    LOCK();
    if (DAT_1400598f0 == 0) {
      DAT_1400598f0 = 0;
    }
    UNLOCK();
    XdvNdisDataSendReceive((longlong *)(local_28[0] + 0x68),(int)DAT_1400598f0,param_2,param_3);
    *(int *)(lVar1 + 0x58) = *(int *)(lVar1 + 0x58) + 1;
  }
  if (((uint)XdvRuleClasses & 0x220000) != 0) {
    EndCriticalSectionNdisGroup(lVar1,param_6,'\0');
  }
  (*(code *)param_7)(param_1,param_2,param_3,param_4);
  return;
}



===== __GSHandlerCheck @ 14001aac8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001aaec =====

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



===== __cpu_features_init @ 14001ab60 =====

/* WARNING: Removing unreachable block (ram,0x00014001abca) */
/* WARNING: Removing unreachable block (ram,0x00014001ab79) */
/* WARNING: Removing unreachable block (ram,0x00014001ab6a) */

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



===== __security_check_cookie @ 14001ac30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14001ac70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14001aca0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001aca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14001acd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 14001ad20 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14001ad63;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14001add4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14001add0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001add4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001adcc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001add0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001adcc;
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
LAB_14001add4:
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
LAB_14001ad63:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 14001ae40 =====

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



===== memset @ 14001b140 =====

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



===== __memset_repmovs @ 14001b280 =====

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



===== __memset_query @ 14001b300 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14001b380 =====

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



===== __memset_spec_ermsb_repmovsb @ 14001b4c0 =====

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



===== __memset_spec_plain @ 14001b540 =====

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



===== XdvDriverUnload @ 140080010 =====

void XdvDriverUnload(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  if ((int)XdvRuleClasses != -1) {
    XdvCleanup(param_1,param_2,param_3,param_4);
  }
  if (XdvDeviceObject != 0) {
    IoDeleteSymbolicLink(&XdvSymbolicName);
    IoDeleteDevice(XdvDeviceObject);
    XdvDeviceObject = 0;
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
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1400800b0 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400800eb;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140080165:
  while( true ) {
    if (&UNK_1400312a7 < ppuVar3) {
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
      if (&UNK_1400312a7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400800eb:
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
      if (&UNK_1400312a7 < ppuVar2) goto LAB_140080165;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140080165;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400801a0 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140080238;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140080238;
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
LAB_140080238:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140080280 =====

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
              if (&UNK_1400312a7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140080300 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400803fd;
  }
LAB_140080406:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400803fd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140080406;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1400803ce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1400803ce;
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
    if (&UNK_1400312a7 < ppuVar3) goto LAB_140080406;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400803fd;
}



===== WdmlibIoCreateDeviceSecure @ 14008042c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1)

{
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
            (param_1,4,&XdvObjectName,0x1000,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,0,&XdvDeviceObject
            );
  return;
}



===== IoDevObjCreateDeviceSecure @ 140080520 =====

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
    if ((int)uVar5 < 0) goto LAB_140080680;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140080680;
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
LAB_140080680:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1400806b4 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 1400807a4 =====

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



===== SepSddlAddAceToAcl @ 140080884 =====

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



===== SepSddlDaclFromSDDLString @ 140080984 =====

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



===== SepSddlGetAclForString @ 140080a70 =====

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
LAB_140080e0b:
              iVar5 = -0x3ffffff3;
LAB_140080e0d:
              lVar7 = *param_2;
              goto LAB_140080df3;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_140080e0b;
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
                ppuVar17 = &PTR_u_RC_140032320;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_14003232c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_140032328)[uVar11 * 4];
                    goto LAB_140080cfd;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_140080e0b;
                uVar15 = (uint)local_res8;
LAB_140080cfd:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_140080e0d;
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
            if (iVar5 != 0) goto LAB_140080e0d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_140080d7b:
              iVar5 = -0x3fffff89;
              goto LAB_140080e0d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_140080d7b;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_140080e0d;
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
LAB_140080df3:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 140080e38 =====

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
  puVar5 = &DAT_1400324a4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14003249c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_140032498 + uVar7 * 0x18);
      uVar6 = (&DAT_1400324a4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_140080ecf;
      }
      else {
LAB_140080ecf:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_140032490 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_140080ee4;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_140080ee4:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 140080f0c =====

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
LAB_140080f8f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_140080f6d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_140080f8f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_140080f6d:
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



===== SepSddlSecurityDescriptorFromSDDLString @ 140081018 =====

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
        goto LAB_14008115d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14008115d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1400811bc =====

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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140020550,0x20019,&local_b0);
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



===== PiRegStateReadStackCreationSettingsFromKey @ 140081358 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1400204d0);
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
      if ((int)uVar3 < 0) goto LAB_1400814d7;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1400204e8,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1400814d7;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140020500,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1400814d7;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140020530,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1400814d7:
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



===== PpRegStateReadCreateClassCreationSettings @ 14008151c =====

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140020470,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x140020488);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x140020498,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1400204b8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 140081680 =====

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
                      (local_res20,0x140020470,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
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
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1400204d0);
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



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1400817e8 =====

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



===== CmRegUtilCreateWstrKey @ 1400818e4 =====

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



===== CmRegUtilOpenExistingWstrKey @ 1400819b4 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 140081a48 =====

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
    if (iVar1 < 0) goto LAB_140081b80;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_140081b80:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 140081bc4 =====

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



===== CmRegUtilWstrValueGetDword @ 140081d10 =====

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



===== CmRegUtilWstrValueSetWstrString @ 140081db4 =====

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



===== entry @ 140083010 =====

void entry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140083044 =====

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



===== DriverEntry @ 140083078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DriverEntry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  longlong *plVar6;
  longlong lVar7;
  bool bVar8;
  
  bVar1 = false;
  wil_InitializeFeatureStaging();
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(code **)(param_1 + 0xe0) = XdvControlPlugins;
  *(code **)(param_1 + 0x70) = XdvDispatchCreate;
  uVar3 = WdmlibIoCreateDeviceSecure(param_1);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  puVar5 = (undefined4 *)&XdvObjectName;
  uVar2 = IoCreateSymbolicLink(&XdvSymbolicName);
  uVar3 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
LAB_140083135:
    plVar6 = &DAT_1400320e0;
    lVar7 = 0xc;
    do {
      if (*plVar6 != 0) {
        (**(code **)(*plVar6 + 0x18))();
        *plVar6 = 0;
      }
      plVar6 = plVar6 + 5;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    if (bVar1) {
      IoDeleteSymbolicLink(&XdvSymbolicName);
    }
    if (XdvDeviceObject != 0) {
      IoDeleteDevice();
      XdvDeviceObject = 0;
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
  }
  else {
    bVar8 = (int)XdvRuleClasses != -1;
    bVar1 = true;
    puVar5 = *(undefined4 **)(XdvDeviceObject + 0x40);
    *puVar5 = 0x40002;
    if (bVar8) {
      uVar4 = XdvInitialize();
      uVar3 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_140083135;
      if ((DAT_140032a14 & 0x800) != 0) {
        *(code **)(param_1 + 0x68) = XdvDriverUnload;
      }
    }
    *(uint *)(XdvDeviceObject + 0x30) = *(uint *)(XdvDeviceObject + 0x30) & 0xffffff7f;
  }
  XdvUtilDbgPrint("Driver Verifier: DIF extension driver started.\n",puVar5,param_3,param_4);
  return uVar3;
}



===== wil_InitializeFeatureStaging @ 14008320c =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_140083293;
    }
LAB_1400832cd:
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
LAB_140083293:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400832cd;
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
    goto LAB_1400832cd;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400312a7 < ppuVar3) goto LAB_1400832cd;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140083293;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140083320 =====

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
            if (&UNK_1400312a7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14008340a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14008340a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14008340a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400312a7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


