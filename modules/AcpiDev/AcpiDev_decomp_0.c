
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



===== AcpiDevicePreprocessPowerIrp @ 140001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AcpiDevicePreprocessPowerIrp(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  uVar1 = AcpiGedDevicePreprocessPowerIrp(param_1,param_2);
  if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,3,0xf,
                      &WPP_1ccacece04d73147648def3cff7a3fc0_Traceguids,(char)uVar1);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_ @ 1400010b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 140001168 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 140001250 =====

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



===== wil_details_RecordCachedUsage @ 1400012ac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001400 =====

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



===== WPP_RECORDER_SF_DDD @ 140001484 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc014000f;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_354a49f1b8303beee23fe4cdef06f2fe_Traceguids,0xb,&uStack0000000000000030,4,
               &uStack0000000000000038,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,0,7,&WPP_354a49f1b8303beee23fe4cdef06f2fe_Traceguids,0xb,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_DDDD @ 140001570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_354a49f1b8303beee23fe4cdef06f2fe_Traceguids,0xe,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,0,7,&WPP_354a49f1b8303beee23fe4cdef06f2fe_Traceguids,0xe,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== FxStubDriverUnloadCommon @ 140001674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140005158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140005158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1400016cd:
      if (ppvVar1 == (void **)0x0) goto LAB_140001723;
      if (ppvVar2 <= ppvVar1) goto LAB_14000173b;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1400016cd;
LAB_140001723:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000173b:
  WdfVersionUnbind(&DAT_1400053e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140001770 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400017a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

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
    _DAT_1400053e0 = 0x2080000;
    _DAT_1400053e8 = &DAT_1400051d0;
    RtlCopyUnicodeString(&DAT_1400053e0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1400053e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1400053d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1400053e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140005158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 140001930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1400053d8 != (code *)0x0) && (DAT_1400053d8 != FxStubDriverUnload)) {
    (*DAT_1400053d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140001964 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140001989) */
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
    if ((void **)0x14000514f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140005158 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 140001aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140001b09) */
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
    if ((void **)0x14000516f < ppvVar2) break;
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



===== AcpiGedSetWakeInterruptStatus @ 140001bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AcpiGedSetWakeInterruptStatus(undefined8 param_1,int *param_2)

{
  longlong lVar1;
  uint7 extraout_var;
  uint7 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined8 in_stack_ffffffffffffffe8;
  
  uVar5 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018);
  uVar4 = 0;
  if (*(uint *)(lVar1 + 8) != 0) {
    do {
      if (*(int *)(uVar4 * 0x20 + 0x1c + *(longlong *)(lVar1 + 0x10)) == *param_2) {
        uVar2 = (uint7)(uint3)((uint)*param_2 >> 8);
        uVar5 = 1;
        *(char *)(uVar4 * 0x20 + 0x18 + *(longlong *)(lVar1 + 0x10)) = (char)param_2[1];
        goto LAB_140001c48;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar1 + 8));
  }
  uVar2 = 0x1400050;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,7,0x12,
                      in_stack_ffffffffffffffe8,(char)*param_2);
    uVar2 = extraout_var;
  }
LAB_140001c48:
  return CONCAT71(uVar2,uVar5);
}



===== RtlStringCbPrintfA @ 140001c6c =====

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



===== WPP_RECORDER_SF_d @ 140001ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control +
                ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + (ulonglong)(param_3 >> 0x10) * 0x14) * 4 +
                0x2c) >> (param_3 - 1 & 0x1f) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + (ulonglong)(param_3 >> 0x10) * 0x50 + 0x18),0x2b
               ,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,0,param_3,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140001dc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,0,7,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qD @ 140001e68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,7,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_s @ 140001f34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,0x22,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,0x22,
                  in_stack_00000030,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sD @ 140002040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
    if (param_6 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_6[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,pcVar1,lVar3,&param_7,4,0);
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (param_6[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,0,8,&WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,param_4,param_6,lVar2
                  ,&param_7,4,0);
  return;
}



===== _guard_check_icall @ 140002180 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002198 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400021bc =====

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



===== __cpu_features_init @ 140002230 =====

/* WARNING: Removing unreachable block (ram,0x00014000229a) */
/* WARNING: Removing unreachable block (ram,0x000140002249) */
/* WARNING: Removing unreachable block (ram,0x00014000223a) */

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



===== __security_check_cookie @ 140002300 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140002340 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002370 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400023a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140002400 =====

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



===== memset @ 140002700 =====

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



===== __memset_repmovs @ 140002840 =====

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



===== __memset_query @ 1400028c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002940 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002a80 =====

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



===== __memset_spec_plain @ 140002b00 =====

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



===== AcpiDeviceDriverUnload @ 140008010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AcpiDeviceDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,1,0x11,
                     &WPP_1ccacece04d73147648def3cff7a3fc0_Traceguids);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar2 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,uVar1);
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
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



===== AcpiDeviceEvtDeviceAdd @ 140008170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AcpiDeviceEvtDeviceAdd(undefined8 param_1,undefined8 ****param_2)

{
  int iVar1;
  longlong *plVar2;
  undefined8 *******pppppppuVar3;
  undefined2 uVar4;
  undefined8 *******local_res10;
  undefined8 *******local_res18 [2];
  ulonglong local_d8 [6];
  undefined *local_a8;
  undefined4 local_98 [10];
  code *local_70;
  code *local_68;
  
  local_res18[0] = (undefined8 *******)0x0;
  local_d8[0] = (ulonglong)(uint)local_d8[0];
  local_res10 = (undefined8 *******)param_2;
  memset(local_98,0,0x90);
  local_70 = AcpiDevicePrepareHardware;
  local_98[0] = 0x90;
  local_68 = AcpiDeviceReleaseHardware;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,local_98);
  pppppppuVar3 = local_res10;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,AcpiDevicePreprocessPowerIrp,0x16,0,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xb;
  }
  else {
    local_a8 = PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018;
    pppppppuVar3 = &local_res10;
    local_d8[2] = 0;
    local_d8[1] = 0;
    local_d8[0] = 0x38;
    local_d8[4] = 0;
    local_d8[5] = 0;
    local_d8[3] = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,pppppppuVar3,local_d8,local_res18);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar4 = 0xc;
    }
    else {
      pppppppuVar3 = local_res18[0];
      plVar2 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res18[0],
                          PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018);
      *plVar2 = (longlong)local_res18[0];
      iVar1 = AcpiGedDevicePrepareQueryInterface(local_res18[0]);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,local_res18[0],0);
        return iVar1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar4 = 0xd;
    }
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pppppppuVar3,1,uVar4,
                    &WPP_1ccacece04d73147648def3cff7a3fc0_Traceguids,(char)iVar1);
  return iVar1;
}



===== AcpiDevicePrepareHardware @ 140008380 =====

ulonglong AcpiDevicePrepareHardware(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  ulonglong uVar1;
  
  uVar1 = AcpiGedDevicePrepareHardware(param_1,param_2,param_3);
  if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0xe,
                      &WPP_1ccacece04d73147648def3cff7a3fc0_Traceguids,(char)uVar1);
  }
  return uVar1 & 0xffffffff;
}



===== AcpiDeviceReleaseHardware @ 1400083e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AcpiDeviceReleaseHardware(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018);
  if (*(longlong *)(lVar1 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x10),0x78444547);
  }
  if (*(longlong *)(lVar1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x20),0x78444547);
  }
  return 0;
}



===== WppInitKm @ 140008450 =====

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



===== WppLoadTracingSupport @ 14000852c =====

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



===== WppTraceCallback @ 140008670 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_details_EvaluateFeatureDependencies @ 1400088f8 =====

/* WARNING: Removing unreachable block (ram,0x000140008920) */
/* WARNING: Removing unreachable block (ram,0x000140008930) */
/* WARNING: Removing unreachable block (ram,0x000140008935) */
/* WARNING: Removing unreachable block (ram,0x00014000893a) */
/* WARNING: Removing unreachable block (ram,0x000140008945) */
/* WARNING: Removing unreachable block (ram,0x00014000895a) */
/* WARNING: Removing unreachable block (ram,0x000140008950) */
/* WARNING: Removing unreachable block (ram,0x00014000896a) */
/* WARNING: Removing unreachable block (ram,0x000140008987) */
/* WARNING: Removing unreachable block (ram,0x000140008996) */
/* WARNING: Removing unreachable block (ram,0x00014000899b) */
/* WARNING: Removing unreachable block (ram,0x00014000898d) */
/* WARNING: Removing unreachable block (ram,0x00014000899d) */
/* WARNING: Removing unreachable block (ram,0x0001400089a2) */
/* WARNING: Removing unreachable block (ram,0x000140008992) */
/* WARNING: Removing unreachable block (ram,0x000140008925) */
/* WARNING: Removing unreachable block (ram,0x00014000892e) */
/* WARNING: Removing unreachable block (ram,0x0001400089ad) */
/* WARNING: Removing unreachable block (ram,0x0001400089b2) */
/* WARNING: Removing unreachable block (ram,0x0001400089a4) */
/* WARNING: Removing unreachable block (ram,0x0001400089d5) */
/* WARNING: Removing unreachable block (ram,0x0001400089b4) */
/* WARNING: Removing unreachable block (ram,0x0001400089ce) */
/* WARNING: Removing unreachable block (ram,0x0001400089d3) */
/* WARNING: Removing unreachable block (ram,0x0001400089c5) */
/* WARNING: Removing unreachable block (ram,0x0001400089ca) */
/* WARNING: Removing unreachable block (ram,0x0001400089a9) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400089e8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140008a80;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140008a80;
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
LAB_140008a80:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140008ad0 =====

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
      for (plVar2 = &wil_details_featureDescriptors_a; plVar2 < &wil_details_featureDescriptors_a;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_140004caf < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140008b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_140008c4d;
  }
LAB_140008c56:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140008c4d:
  if (plVar3 == (longlong *)0x0) goto LAB_140008c56;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140008c1e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140008c1e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_140004caf < plVar3) goto LAB_140008c56;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_140008c4d;
}



===== AcpiDeviceUtilEnumerateNamespaceChildren @ 140008c7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140008dc8) */
/* WARNING: Removing unreachable block (ram,0x000140008dd1) */
/* WARNING: Removing unreachable block (ram,0x000140008df2) */
/* WARNING: Removing unreachable block (ram,0x000140008e0b) */
/* WARNING: Removing unreachable block (ram,0x000140008e3c) */
/* WARNING: Removing unreachable block (ram,0x000140008e9f) */
/* WARNING: Removing unreachable block (ram,0x000140008eaf) */
/* WARNING: Removing unreachable block (ram,0x000140008ed9) */
/* WARNING: Removing unreachable block (ram,0x000140008ef2) */
/* WARNING: Removing unreachable block (ram,0x000140008f00) */
/* WARNING: Removing unreachable block (ram,0x000140008f06) */
/* WARNING: Removing unreachable block (ram,0x000140008f0b) */
/* WARNING: Removing unreachable block (ram,0x000140008f14) */
/* WARNING: Removing unreachable block (ram,0x000140008f19) */
/* WARNING: Removing unreachable block (ram,0x000140008f29) */
/* WARNING: Removing unreachable block (ram,0x000140008f4c) */

int AcpiDeviceUtilEnumerateNamespaceChildren
              (undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*param_1);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c020);
  if (iVar1 == -0x7ffffffb) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,7,10,
                      &WPP_354a49f1b8303beee23fe4cdef06f2fe_Traceguids,(char)iVar1);
  }
  return -0x3febfff1;
}



===== AcpiDeviceUtilParseNamespaceEventPins @ 140008fbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
AcpiDeviceUtilParseNamespaceEventPins
          (longlong param_1,int param_2,longlong param_3,uint param_4,uint *param_5,longlong param_6
          ,uint param_7,uint *param_8)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined1 local_48 [2];
  char acStack_46 [6];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_48;
  uVar10 = 0;
  *param_5 = 0;
  *param_8 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar10 = 0xc0140008;
  }
  else {
    uVar6 = 1;
    pbVar8 = (byte *)(param_1 + 8);
    if (1 < *(uint *)(param_1 + 4)) {
      do {
        pbVar8 = pbVar8 + (ulonglong)*(uint *)(pbVar8 + 4) + 8;
        if (((*pbVar8 & 1) == 0) && (4 < *(uint *)(pbVar8 + 4))) {
          acStack_46[2] = 0;
          if (((char)*(undefined4 *)(pbVar8 + (ulonglong)(*(uint *)(pbVar8 + 4) - 5) + 8) == '_') &&
             ((cVar2 = (char)((uint)*(undefined4 *)
                                     (pbVar8 + (ulonglong)(*(uint *)(pbVar8 + 4) - 5) + 8) >> 8),
              cVar2 == 'E' || (cVar2 == 'L')))) {
            uVar5 = 0;
            pcVar9 = acStack_46;
            uVar7 = 0;
            do {
              cVar1 = *pcVar9;
              iVar4 = (int)cVar1;
              if ((byte)(cVar1 - 0x30U) < 10) {
                uVar3 = iVar4 - 0x30;
              }
              else if ((byte)(cVar1 + 0xbfU) < 6) {
                uVar3 = iVar4 - 0x37;
              }
              else {
                if (5 < (byte)(cVar1 + 0x9fU)) goto LAB_1400090ec;
                uVar3 = iVar4 - 0x57;
              }
              if (0xf < uVar3) goto LAB_1400090ec;
              uVar7 = uVar7 + 1;
              uVar5 = uVar5 << 4 | uVar3;
              pcVar9 = pcVar9 + 1;
            } while (uVar7 < 2);
            if (cVar2 == 'E') {
              if ((param_3 != 0) && (*param_5 < param_4)) {
                *(uint *)(param_3 + (ulonglong)*param_5 * 4) = uVar5;
              }
              *param_5 = *param_5 + 1;
            }
            else if (cVar2 == 'L') {
              if ((param_6 != 0) && (*param_8 < param_7)) {
                *(uint *)(param_6 + (ulonglong)*param_8 * 4) = uVar5;
              }
              *param_8 = *param_8 + 1;
            }
          }
        }
LAB_1400090ec:
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(param_1 + 4));
    }
    if ((param_4 < *param_5) || (param_7 < *param_8)) {
      uVar10 = 0xc0000023;
    }
  }
  return uVar10;
}



===== AcpiGedDeviceBuildEdgeLevelPinList @ 14000913c =====

int AcpiGedDeviceBuildEdgeLevelPinList
              (undefined8 *param_1,longlong *param_2,uint *param_3,uint *param_4)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  byte *pbVar5;
  longlong *plVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint *puVar11;
  undefined2 uVar12;
  uint uVar13;
  uint uVar14;
  uint local_res8 [2];
  longlong *local_res10;
  uint *local_res18;
  uint *local_res20;
  uint *in_stack_ffffffffffffff88;
  undefined1 uVar15;
  uint local_58;
  uint local_54;
  longlong local_50 [2];
  
  local_res8[0] = 0;
  puVar11 = &local_54;
  local_58 = 0;
  plVar6 = local_50;
  lVar4 = 0;
  local_50[0] = 0;
  local_54 = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar2 = AcpiDeviceUtilEnumerateNamespaceChildren(param_1,plVar6,puVar11);
  lVar1 = local_50[0];
  uVar13 = local_54;
  uVar15 = SUB81(param_1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140009408;
    uVar12 = 0x18;
  }
  else {
    if (local_50[0] == 0) goto LAB_140009244;
    if (local_54 == 0) {
      iVar2 = -0x3febfff8;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140009408;
      uVar12 = 0x1b;
    }
    else {
      uVar14 = *(uint *)(local_50[0] + 4);
      pbVar5 = (byte *)(local_50[0] + 8);
      uVar10 = 1;
      if (1 < uVar14) {
        do {
          pbVar5 = pbVar5 + (ulonglong)*(uint *)(pbVar5 + 4) + 8;
          if ((((*pbVar5 & 1) == 0) && (4 < *(uint *)(pbVar5 + 4))) &&
             (*(int *)(pbVar5 + (ulonglong)(*(uint *)(pbVar5 + 4) - 5) + 8) == 0x5456455f)) break;
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
        } while (uVar9 < uVar14);
      }
      if ((uint)uVar10 == uVar14) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar12 = 0x1a;
          goto LAB_14000922f;
        }
      }
      else {
        *(undefined1 *)(param_1 + 3) = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar12 = 0x19;
LAB_14000922f:
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar5,uVar10,uVar12,
                            in_stack_ffffffffffffff88,uVar15);
        }
      }
LAB_140009244:
      puVar11 = (uint *)0x0;
      in_stack_ffffffffffffff88 = local_res8;
      plVar6 = (longlong *)(ulonglong)uVar13;
      uVar3 = AcpiDeviceUtilParseNamespaceEventPins
                        (lVar1,uVar13,0,0,in_stack_ffffffffffffff88,0,0,&local_58);
      uVar14 = local_58;
      uVar13 = local_res8[0];
      iVar2 = (int)uVar3;
      if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffffdd)) {
        uVar10 = (ulonglong)local_res8[0];
        if (local_58 + local_res8[0] == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar6,7,0x1d,
                             &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids);
          }
          iVar2 = 0;
        }
        else {
          lVar7 = (ulonglong)(local_58 + local_res8[0]) << 2;
          uVar3 = 0x78444547;
          lVar4 = ExAllocatePool2(0x100);
          if (lVar4 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar3,0x1e,
                                in_stack_ffffffffffffff88,uVar15);
            }
            iVar2 = -0x3fffff66;
            goto LAB_140009408;
          }
          if (uVar13 == 0) {
            if (uVar14 == 0) goto LAB_1400093f3;
          }
          uVar8 = (ulonglong)local_54;
          puVar11 = local_res8;
          lVar7 = lVar4;
          uVar3 = AcpiDeviceUtilParseNamespaceEventPins
                            (lVar1,local_54,lVar4,uVar13,puVar11,lVar4 + uVar10 * 4,uVar14,&local_58
                            );
          iVar2 = (int)uVar3;
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,lVar7,0x1f,puVar11
                                 ,uVar15,(char)uVar3);
            }
            ExFreePoolWithTag(lVar4,0x78444547);
            goto LAB_140009408;
          }
          uVar14 = local_58;
          uVar13 = local_res8[0];
        }
LAB_1400093f3:
        *local_res10 = lVar4;
        *local_res18 = uVar13;
        *local_res20 = uVar14;
        goto LAB_140009408;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140009408;
      uVar12 = 0x1c;
    }
  }
  WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar6,puVar11,uVar12,
                     in_stack_ffffffffffffff88,uVar15,(char)iVar2);
LAB_140009408:
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x78444547);
  }
  return iVar2;
}



===== AcpiGedDeviceConnectInterrupts @ 14000943c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AcpiGedDeviceConnectInterrupts(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  int *piVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined *local_a8;
  undefined4 local_98 [4];
  undefined4 local_88;
  code *local_80;
  undefined8 local_78;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_40;
  undefined4 local_3c;
  
  local_c8 = 0;
  local_a8 = PTR__WDF_ACPI_GED_INTERRUPT_CONTEXT_TYPE_INFO_140005080;
  uStack_d0 = 0;
  iVar2 = 0;
  local_d8 = 0x38;
  local_b8 = 0;
  uStack_b0 = 0;
  uStack_c0 = 0x100000001;
  memset(local_98,0,0x68);
  local_78 = 0;
  local_40 = 1;
  uVar7 = 0;
  local_98[0] = 0x68;
  local_88 = 2;
  local_80 = AcpiGedDeviceInterruptPassiveIsr;
  local_3c = 2;
  iVar1 = 0;
  if (*(int *)(param_1 + 1) != 0) {
    do {
      iVar2 = iVar1;
      piVar5 = (int *)(uVar7 * 0x20 + param_1[2]);
      if (*piVar5 != -1) {
        local_50 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,uVar7);
        local_58 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar7);
        uVar4 = *param_1;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x468))
                          (WdfDriverGlobals,uVar4,local_98,&local_d8,piVar5 + 2);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar2;
          }
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,7,0x14,
                            &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,(char)iVar2);
          return iVar2;
        }
        puVar3 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,*(undefined8 *)(piVar5 + 2),
                            PTR__WDF_ACPI_GED_INTERRUPT_CONTEXT_TYPE_INFO_140005080);
        puVar3[1] = piVar5;
        *puVar3 = param_1;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      iVar1 = iVar2;
    } while (uVar6 < *(uint *)(param_1 + 1));
  }
  return iVar2;
}



===== AcpiGedDeviceEnableDisableAcpiEvents @ 140009600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AcpiGedDeviceEnableDisableAcpiEvents(uint *param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffe8;
  
  uVar4 = 0;
  cVar1 = (char)param_2;
  if (*param_1 != 0) {
    do {
      puVar2 = (undefined4 *)(uVar4 * 0x20 + *(longlong *)(param_1 + 2));
      if (*(char *)(puVar2 + 6) == '\0') {
        param_2 = *(undefined8 *)(puVar2 + 2);
        bVar5 = cVar1 == '\0';
        if (bVar5) {
          (**(code **)(WdfFunctions_01015 + 0x498))(WdfDriverGlobals);
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0x490))();
        }
        LOCK();
        puVar2[5] = (uint)!bVar5;
        UNLOCK();
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,8,0x23,
                          in_stack_ffffffffffffffe8,(char)*puVar2);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *param_1);
  }
  return 0;
}



===== AcpiGedDeviceInterruptPassiveIsr @ 1400096d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool AcpiGedDeviceInterruptPassiveIsr(undefined8 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ushort uVar6;
  undefined8 uVar7;
  undefined1 auStackY_c8 [32];
  ulonglong *puVar8;
  char local_78 [8];
  ulonglong local_70;
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_40 = 0;
  local_70 = (ulonglong)(uint)local_70;
  local_58 = 0;
  local_78[0] = 'L';
  local_78[1] = 'E';
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  puVar1 = (undefined4 *)puVar3[1];
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,*(undefined8 *)*puVar3);
  local_50 = 0;
  if (*(char *)(puVar1 + 4) == '\0') {
    RtlStringCbPrintfA((char *)&local_50,5,"_%c%02X",(ulonglong)(uint)(int)local_78[(int)puVar1[1]])
    ;
    local_60 = 8;
    local_48 = 0x42696541;
  }
  else {
    local_50._0_4_ = 0x5456455f;
    local_50 = 0x5456455f;
    local_48 = 0x49696541;
    local_40 = *puVar1;
    local_60 = 0xc;
  }
  local_68 = &local_48;
  local_70 = 1;
  local_5c = 0;
  uVar6 = 0;
  local_44 = (undefined4)local_50;
  do {
    puVar8 = &local_70;
    uVar7 = 0;
    uVar5 = uVar4;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar4,0,0x32c004);
    if ((iVar2 == -0x3fffffcc) || (iVar2 == -0x3ffffff2)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar7,0x20,puVar8,
                           (char *)&local_50,(char)iVar2);
      }
      break;
    }
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      break;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar7,0x21,puVar8,
                         (char *)&local_50,(char)iVar2);
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  return iVar2 == 0;
}



===== AcpiGedDevicePrepareAcpiEventing @ 1400098fc =====

int AcpiGedDevicePrepareAcpiEventing(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  int *piVar11;
  int *piVar12;
  undefined *in_stack_ffffffffffffffd8;
  
  plVar5 = param_1 + 4;
  iVar1 = AcpiGedDeviceBuildEdgeLevelPinList
                    (param_1,plVar5,(uint *)(param_1 + 5),(uint *)((longlong)param_1 + 0x2c));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar5,7,0x10,
                        &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,(char)iVar1);
    }
  }
  else {
    uVar8 = 0;
    if (*(int *)(param_1 + 1) != 0) {
      do {
        uVar7 = *(uint *)(param_1 + 5);
        piVar12 = (int *)(uVar8 * 0x20 + param_1[2]);
        iVar1 = piVar12[1];
        if (iVar1 == 1) {
          uVar6 = 0;
        }
        else {
          uVar6 = (ulonglong)uVar7;
          uVar7 = *(int *)((longlong)param_1 + 0x2c) + uVar7;
        }
        uVar4 = (uint)uVar6;
        if (uVar4 < uVar7) {
          piVar11 = (int *)(param_1[4] + uVar6 * 4);
          uVar3 = uVar6;
          do {
            iVar2 = (int)uVar3;
            if (*piVar12 == *piVar11) {
              uVar9 = 0;
              if (iVar1 == 1) {
                if (iVar2 - uVar4 < *(uint *)(param_1 + 5)) goto LAB_1400099da;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140009a55;
                uVar10 = 0x16;
              }
              else {
                if ((iVar1 != 0) || (iVar2 - uVar4 < *(uint *)((longlong)param_1 + 0x2c)))
                goto LAB_1400099da;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140009a55;
                uVar10 = 0x17;
              }
              uVar8 = 7;
              in_stack_ffffffffffffffd8 = &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids;
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,7,uVar10,
                                &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,
                                (char)*(undefined4 *)(param_1[4] + uVar3 * 4));
              goto LAB_140009a55;
            }
            uVar3 = (ulonglong)(iVar2 + 1U);
            piVar11 = piVar11 + 1;
          } while (iVar2 + 1U < uVar7);
        }
        if (*(char *)(param_1 + 3) == '\0') {
LAB_140009a55:
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3fffffff;
          }
          WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,uVar8,0x11,
                             in_stack_ffffffffffffffd8,(char)param_1,(char)*piVar12);
          return -0x3fffffff;
        }
        uVar9 = 1;
LAB_1400099da:
        iVar1 = 0;
        *(undefined1 *)(piVar12 + 4) = uVar9;
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < *(uint *)(param_1 + 1));
    }
  }
  return iVar1;
}



===== AcpiGedDevicePrepareHardware @ 140009aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AcpiGedDevicePrepareHardware(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  char *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined2 uVar10;
  int iVar11;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018);
  iVar11 = 0;
  uVar5 = param_3;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals);
  uVar9 = 0;
  if (uVar2 != 0) {
    do {
      uVar5 = param_3;
      pcVar4 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar9);
      iVar1 = iVar11 + 1;
      if (*pcVar4 != '\x02') {
        iVar1 = iVar11;
      }
      iVar11 = iVar1;
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
  *(int *)(puVar3 + 1) = iVar11;
  if (iVar11 == 0) {
    iVar11 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,7,0xd,
                        &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,1);
    }
    uVar6 = 0xc0000001;
  }
  else {
    uVar7 = (ulonglong)(uint)(iVar11 << 5);
    uVar5 = ExAllocatePool2(0x100,uVar7,0x78444547);
    puVar3[2] = uVar5;
    if (uVar5 != 0) {
      uVar6 = AcpiGedDeviceSetInterruptInformationFromResources
                        (*(uint *)(puVar3 + 1),uVar5,param_3,param_2);
      iVar11 = (int)uVar6;
      uVar6 = uVar6 & 0xffffffff;
      if (iVar11 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0xf;
          goto LAB_140009c16;
        }
        if (iVar11 < 0) goto LAB_140009c6d;
      }
      uVar2 = AcpiGedDevicePrepareAcpiEventing(puVar3);
      uVar6 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar6;
        }
        uVar10 = 0xb;
        param_3 = uVar5;
      }
      else {
        uVar2 = AcpiGedDeviceConnectInterrupts(puVar3,param_3,param_2);
        uVar6 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          return uVar6;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar6;
        }
        uVar10 = 0xc;
      }
      uVar8 = (undefined1)uVar2;
      goto LAB_140009ccf;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,7,0x15,
                        &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,0);
    }
    uVar6 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000009a;
    }
    uVar10 = 0xe;
    iVar11 = -0x3fffff66;
    uVar5 = uVar7;
LAB_140009c16:
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,7,uVar10,
                      &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,(char)iVar11);
  }
LAB_140009c6d:
  param_3 = uVar5;
  uVar8 = (undefined1)iVar11;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return uVar6;
  }
  uVar10 = 10;
LAB_140009ccf:
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,2,uVar10,
                    &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,uVar8);
  return uVar6;
}



===== AcpiGedDevicePrepareQueryInterface @ 140009d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AcpiGedDevicePrepareQueryInterface(undefined8 param_1)

{
  int iVar1;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_64 = 0;
  local_3c = 0;
  local_28 = 0;
  local_18 = 0;
  local_20 = 0;
  local_58 = _guard_check_icall;
  local_50 = _guard_check_icall;
  local_48 = AcpiGedSetWakeInterruptStatus;
  local_38 = &local_68;
  local_30 = &GUID_GED_INTERFACE_STANDARD;
  local_68 = 0x10028;
  local_40 = 0x30;
  local_60 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))(WdfDriverGlobals,param_1,&local_40);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,1,0x13,
                      &WPP_6ad9da3e848632d5b79c01478dc1856d_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== AcpiGedDevicePreprocessPowerIrp @ 140009e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AcpiGedDevicePreprocessPowerIrp(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  uVar3 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_ACPI_DEVICE_EXTENSION_TYPE_INFO_140005018);
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x10) == 0) {
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (iVar1 == 1) {
      *(undefined1 *)(lVar2 + 0x88) = 1;
      uVar4 = 1;
    }
    else {
      if ((((iVar1 != 2) && (iVar1 != 3)) && (iVar1 != 4)) && ((iVar1 != 5 && (iVar1 != 6)))) {
        return 0;
      }
      *(undefined1 *)(lVar2 + 0x88) = 0;
      uVar4 = 0;
    }
    uVar3 = AcpiGedDeviceEnableDisableAcpiEvents((uint *)(lVar2 + 8),uVar4);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}



===== AcpiGedDeviceSetInterruptInformationFromResources @ 140009ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AcpiGedDeviceSetInterruptInformationFromResources
          (uint param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    uVar4 = 0;
    puVar3 = (uint *)(param_2 + 4);
    do {
      pcVar1 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,uVar4);
      if (*pcVar1 == '\x02') {
        lVar2 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_4,uVar4);
        if (lVar2 == 0) {
          puVar3[-1] = 0xffffffff;
          *puVar3 = 0;
          puVar3[4] = 0;
        }
        else {
          puVar3[-1] = *(uint *)(lVar2 + 8);
          puVar3[6] = uVar4;
          if ((pcVar1[2] & 0x20U) != 0) {
            *(undefined1 *)((longlong)puVar3 + 0xd) = 1;
          }
          *puVar3 = *(ushort *)(pcVar1 + 2) & 1;
          puVar3[4] = 1;
        }
      }
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 8;
    } while (uVar4 < param_1);
  }
  return 0;
}



===== __security_init_cookie @ 14000a008 =====

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



===== DriverEntry @ 14000a03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  ulonglong local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  local_28 = (ulonglong)(uint)local_28;
  local_res18[0] = 0;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_140005408 = &WPP_ThisDir_CTLGUID_AcpiDevicesTraceGuid;
  DAT_140005410 = 0;
  _DAT_140005420 = 0;
  _DAT_140005428 = 1;
  _DAT_140005440 = 0;
  _DAT_140005448 = 0;
  WppLoadTracingSupport();
  _DAT_140005420 = 0;
  WppInitKm(param_1,param_2);
  local_28 = 0x20;
  local_20 = AcpiDeviceEvtDeviceAdd;
  local_18 = AcpiDeviceDriverUnload;
  local_10 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,1,10,
                        &WPP_1ccacece04d73147648def3cff7a3fc0_Traceguids,(char)iVar1);
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
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14000a1b0 =====

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
    for (plVar3 = &wil_details_featureDescriptors_a; plVar3 < &wil_details_featureDescriptors_a;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_14000a237;
    }
LAB_14000a271:
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
LAB_14000a237:
  if (plVar3 == (longlong *)0x0) goto LAB_14000a271;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_14000a271;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_140004caf < plVar3) goto LAB_14000a271;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_14000a237;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000a2c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_a;
  while( true ) {
    if (&wil_details_featureDescriptors_a <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_140004caf < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000a3ae;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000a3ae;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000a3ae:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140004caf < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


