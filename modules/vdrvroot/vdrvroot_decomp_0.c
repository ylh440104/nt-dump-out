
===== McGenControlCallbackV2 @ 1c0001010 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar3 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar5 = 0;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar5 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar5 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 & ~(1 << ((byte)uVar5 & 0x1f));
          }
          else {
            puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar5 >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)uVar5 & 0x1f);
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== entry @ 1c0001130 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0001164 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  _WDF_BIND_INFO *p_Var3;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar2 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c00053e0 = 0x2080000;
    _DAT_1c00053e8 = &DAT_1c00051d0;
    RtlCopyUnicodeString(&DAT_1c00053e0);
    p_Var3 = param_1;
    uVar2 = WdfVersionBind(param_1,&DAT_1c00053e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar2) {
      uVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar2 = DriverEntry(param_1,param_2);
        uVar1 = (uint)uVar2;
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00053d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar2 & 0xffffffff,
                   &DAT_1c00053e0);
        FxStubDriverEntryFailure();
      }
      FxStubDriverUnloadCommon();
      uVar2 = (ulonglong)uVar1;
    }
  }
  return uVar2;
}



===== McGenEventRegister_EtwRegister @ 1c0001288 =====

void McGenEventRegister_EtwRegister(void)

{
  if (VDRVROOT_PROVIDER_ID_Context == 0) {
    EtwRegister(&VDRVROOT_PROVIDER_ID,McGenControlCallbackV2,&VDRVROOT_PROVIDER_ID_Context,
                &VDRVROOT_PROVIDER_ID_Context);
  }
  return;
}



===== __report_gsfailure @ 1c00012e0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c00012f0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (VDRVROOT_PROVIDER_ID_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    VDRVROOT_PROVIDER_ID_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0001324 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c0005018;
  uVar2 = 0;
  if (DAT_1c0005018 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c0005018;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(VDRVROOT_PROVIDER_ID_Context,param_2,0,0,1,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1c0001388 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,param_4,local_28);
  return;
}



===== WPP_SF_ @ 1c00013c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,param_2,0);
  return;
}



===== WPP_SF_D @ 1c00013f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DD @ 1c000143c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,0x22,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_q @ 1c0001494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WppClassicProviderCallback @ 1c00014e0 =====

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



===== RtlUnicodeStringPrintf @ 1c0001514 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== VdrvDeviceQueryStop @ 1c00015c0 =====

undefined8 VdrvDeviceQueryStop(void)

{
  return 0xc0000001;
}



===== WPP_SF_S @ 1c00015d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6c4249c3353f3ed7bdc2f07cc6a69920_Traceguids,0x12,param_4,lVar1,0);
  return;
}



===== _guard_check_icall @ 1c0001650 =====

void _guard_check_icall(void)

{
  return;
}



===== FxStubDriverEntryFailure @ 1c000165c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverEntryFailure(void) */

void __cdecl FxStubDriverEntryFailure(void)

{
  int iVar1;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005158 != &__KMDF_CLASS_BIND_START) {
    local_1c = 0;
    uStack_18 = 0;
    local_14 = 0;
    local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
    local_20 = 0x18;
    iVar1 = WdfLdrQueryInterface(&local_28);
    if (-1 < iVar1) {
      (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
    }
  }
  return;
}



===== FxStubDriverUnloadCommon @ 1c00016c8 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1c00053e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== FxStubDriverUnload @ 1c0001700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00053d8 != (code *)0x0) && (DAT_1c00053d8 != FxStubDriverUnload)) {
    (*DAT_1c00053d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0001734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0001759) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x1c000514f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1c0005158 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 1c0001894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0005158 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c0005158 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 1c0001950 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 1c0001998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00019b5) */
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
    if ((void **)0x1c000516f < ppvVar2) break;
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



===== __GSHandlerCheck @ 1c0001a68 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001a8c =====

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



===== __cpu_features_init @ 1c0001b00 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001b6a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001b19) */
/* WARNING: Removing unreachable block (ram,0x0001c0001b0a) */

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



===== __security_check_cookie @ 1c0001bd0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001c10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001c40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001c70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0001cc0 =====

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



===== memset @ 1c0001fc0 =====

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



===== __memset_repmovs @ 1c0002100 =====

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



===== __memset_query @ 1c0002180 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002200 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002340 =====

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



===== __memset_spec_plain @ 1c00023c0 =====

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



===== VdrvCheckPolicyValue @ 1c0008008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VdrvCheckPolicyValue(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_78 [32];
  longlong *local_58;
  int *local_50;
  int local_48 [2];
  longlong local_40 [3];
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  int local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_40[0] = 0;
  local_58 = local_40;
  local_48[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  iVar2 = 0;
  iVar1 = IoOpenDriverRegistryKey(0,0,0x20019,0);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_40 + 1,L"EnableVhdopDriver");
    local_50 = local_48;
    local_58 = (longlong *)CONCAT44(local_58._4_4_,0x10);
    iVar1 = ZwQueryValueKey(local_40[0],local_40 + 1,2,local_28);
    if (((-1 < iVar1) && (local_48[0] == 0x10)) && (local_24 == 4)) {
      iVar2 = 0;
      if (local_20 == 4) {
        iVar2 = local_1c;
      }
    }
  }
  if (local_40[0] != 0) {
    ZwClose();
  }
  EnableVhdopDriver = iVar2 != 0;
  return 0;
}



===== WppInitKm @ 1c0008100 =====

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



===== VdrvDriverCleanup @ 1c00081a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VdrvDriverCleanup(undefined8 param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd);
  }
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
  McGenEventUnregister_EtwUnregister();
  return;
}



===== VdrvpNotifyNetStopEvent @ 1c000820c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VdrvpNotifyNetStopEvent(undefined8 param_1,int *param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 uVar2;
  longlong lVar3;
  int iVar4;
  
  uVar2 = 0;
  iVar4 = 0;
  if (*param_2 == 1) {
    lVar3 = 0;
    do {
      if ((*(int *)((longlong)&DAT_1c0005488 + lVar3) == 3) &&
         (iVar1 = (**(code **)((longlong)&DAT_1c0005470 + lVar3))
                            (*(undefined8 *)((longlong)&DAT_1c0005448 + lVar3),param_2[1]),
         iVar1 < 0)) {
        iVar4 = iVar1;
      }
      lVar3 = lVar3 + 0x70;
    } while (lVar3 < 0xe0);
    if (-1 < iVar4) {
      return 0;
    }
  }
  else {
    uVar2 = 2;
    iVar4 = -0x3ffffff3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
              (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),param_3,iVar4,uVar2);
  }
  return iVar4;
}



===== VdrvpRegisterHbaDriver @ 1c00082e0 =====

undefined8
VdrvpRegisterHbaDriver(undefined8 param_1,undefined8 *param_2,uint param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  longlong lVar7;
  undefined *puVar8;
  
  uVar1 = (ulonglong)param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20);
  }
  if (param_3 < 2) {
    lVar7 = uVar1 * 0x70;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_1c0005478 + lVar7,0);
    if ((((&DAT_1c0005488)[uVar1 * 0x1c] - 1 & 0xfffffffc) == 0) &&
       ((&DAT_1c0005488)[uVar1 * 0x1c] != 3)) {
      (&DAT_1c0005488)[uVar1 * 0x1c] = 3;
      *(undefined8 *)(&DAT_1c0005480 + lVar7) = param_1;
      puVar8 = (undefined *)0x0;
      uVar5 = param_2[1];
      *(undefined8 *)(&VhdAdapterData + lVar7) = *param_2;
      (&DAT_1c0005448)[uVar1 * 0xe] = uVar5;
      uVar5 = param_2[3];
      *(undefined8 *)(&DAT_1c0005450 + lVar7) = param_2[2];
      *(undefined8 *)(lVar7 + 0x1c0005458) = uVar5;
      uVar2 = *(undefined4 *)((longlong)param_2 + 0x24);
      uVar3 = *(undefined4 *)(param_2 + 5);
      uVar4 = *(undefined4 *)((longlong)param_2 + 0x2c);
      *(undefined4 *)(&DAT_1c0005460 + lVar7) = *(undefined4 *)(param_2 + 4);
      *(undefined4 *)(lVar7 + 0x1c0005464) = uVar2;
      *(undefined4 *)(&DAT_1c0005468 + lVar7) = uVar3;
      *(undefined4 *)(lVar7 + 0x1c000546c) = uVar4;
      (&DAT_1c0005470)[uVar1 * 0xe] = param_2[6];
      KeSetEvent(&DAT_1c0005490 + lVar7,0);
      puVar6 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        puVar8 = &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids;
        param_4 = 0;
        WPP_SF_D(puVar6,0x21,&WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,0);
      }
      if ((Microsoft_Windows_VDRVROOTEnableBits & 1) != 0) {
        McTemplateK0_EtwWriteTransfer(puVar6,&DriverRegistration,puVar8,param_4);
      }
      uVar5 = 0;
    }
    else {
      uVar5 = 0xc0000001;
    }
    ExReleasePushLockExclusiveEx(&DAT_1c0005478 + lVar7,0);
    KeLeaveCriticalRegion();
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== VdrvpUnregisterHbaDriver @ 1c0008460 =====

void VdrvpUnregisterHbaDriver(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  byte bVar1;
  ulonglong uVar2;
  undefined *puVar3;
  longlong lVar4;
  
  if (param_2 < 2) {
    uVar2 = (ulonglong)param_2;
    lVar4 = uVar2 * 0x70;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_1c0005478 + lVar4,0);
    if ((*(longlong *)(&DAT_1c0005480 + lVar4) == param_1) && ((&DAT_1c0005488)[uVar2 * 0x1c] == 3))
    {
      puVar3 = &DAT_1c0005490 + lVar4;
      KeResetEvent();
      (&DAT_1c0005488)[uVar2 * 0x1c] = 4;
      *(undefined8 *)(&VhdAdapterData + lVar4) = 0;
      (&DAT_1c0005448)[uVar2 * 0xe] = 0;
      bVar1 = Microsoft_Windows_VDRVROOTEnableBits & 1;
      *(undefined8 *)(&DAT_1c0005450 + lVar4) = 0;
      *(undefined8 *)(lVar4 + 0x1c0005458) = 0;
      *(undefined8 *)(&DAT_1c0005460 + lVar4) = 0;
      *(undefined8 *)(&DAT_1c0005468 + lVar4) = 0;
      (&DAT_1c0005470)[uVar2 * 0xe] = 0;
      if (bVar1 != 0) {
        McTemplateK0_EtwWriteTransfer(puVar3,&DriverUnregistration,param_3,param_4);
      }
    }
    ExReleasePushLockExclusiveEx(&DAT_1c0005478 + lVar4,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== WppCleanupKm @ 1c000852c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppTraceCallback @ 1c00085b0 =====

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



===== VdrvDeviceListCreatePdo @ 1c0008840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VdrvDeviceListCreatePdo
                    (undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,param_1);
  uVar2 = VdrvpCreatePdo(uVar1,param_3,*(uint *)(param_2 + 4),param_4);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_6c4249c3353f3ed7bdc2f07cc6a69920_Traceguids,(int)uVar2);
  }
  return uVar2 & 0xffffffff;
}



===== VdrvpCreatePdo @ 1c00088d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VdrvpCreatePdo(undefined8 param_1,undefined8 param_2,uint param_3,ulonglong param_4)

{
  uint uVar1;
  undefined2 uVar2;
  wchar_t *pwVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 auStack_2e8 [32];
  undefined4 local_2c8;
  undefined8 local_2b8;
  undefined8 local_2b0;
  ushort local_2a8 [4];
  wchar_t *local_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 *puStack_280;
  undefined *local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  ulonglong local_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  code *local_228;
  code *pcStack_220;
  code *local_218;
  code *pcStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  code *local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  ulonglong uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  wchar_t local_d8 [80];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2e8;
  local_2a8[0] = 0;
  local_2a8[1] = 0xa0;
  local_2a8[2] = 0;
  local_2a8[3] = 0;
  local_2a0 = local_d8;
  uVar5 = (ulonglong)param_3;
  local_2b0 = 0;
  local_e8 = 0;
  uStack_e4 = 0;
  local_e0 = 0;
  local_188 = 0;
  uStack_180 = uStack_180 & 0xffffffff00000000;
  local_268 = 0;
  local_260 = local_260 & 0xffffffff00000000;
  local_258 = 0;
  uStack_250 = 0;
  local_298 = 0;
  uStack_290 = 0;
  local_248 = 0;
  uStack_240 = 0;
  local_f8 = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  local_208 = 0;
  uStack_200 = 0;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_1d8 = 0;
  uStack_1d0 = 0;
  local_1c8 = 0;
  uStack_1c0 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_198 = (code *)0x0;
  uStack_190 = 0;
  local_238 = 0;
  uStack_230 = 0;
  local_228 = (code *)0x0;
  pcStack_220 = (code *)0x0;
  local_218 = (code *)0x0;
  pcStack_210 = (code *)0x0;
  local_288 = 0;
  puStack_280 = (undefined8 *)0x0;
  local_278 = (undefined *)0x0;
  uStack_270 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_2b8 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_4 = (ulonglong)param_3;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_6c4249c3353f3ed7bdc2f07cc6a69920_Traceguids,param_3);
  }
  if (param_3 == 1) {
    RtlInitUnicodeString(&local_258,L"{8e7bd593-6e6c-4c52-86a6-77175494dd8e}\\MsCompatibleVhdHba");
    RtlInitUnicodeString(&local_298,L"{8e7bd593-6e6c-4c52-86a6-77175494dd8e}\\MsVhdHba");
    pwVar3 = L"VHD Bus 0";
  }
  else {
    if (param_3 != 2) {
      uVar4 = 0xc000000d;
      goto LAB_1c0009073;
    }
    RtlInitUnicodeString(&local_258,L"{8e7bd593-6e6c-4c52-86a6-77175494dd8e}\\MsCompatibleVhdHba2");
    RtlInitUnicodeString(&local_298,L"{8e7bd593-6e6c-4c52-86a6-77175494dd8e}\\MsVhdHba2");
    pwVar3 = L"VHD Bus 1";
  }
  RtlInitUnicodeString(&local_248,pwVar3);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_2b8,0x2a);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_2b8,&local_298);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0009073;
    uVar2 = 0xc;
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_2b8,&local_298);
    uVar4 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_1c0009073;
      uVar2 = 0xd;
    }
    else {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x6b8))(WdfDriverGlobals,local_2b8,&local_258);
      uVar4 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar4;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
        uVar2 = 0xe;
      }
      else {
        uVar4 = RtlUnicodeStringPrintf(local_2a8,L"%02d",uVar5,param_4);
        uVar1 = (uint)uVar4;
        uVar4 = uVar4 & 0xffffffff;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar4;
          }
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
          uVar2 = 0xf;
        }
        else {
          uVar1 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_2b8,local_2a8);
          uVar4 = (ulonglong)uVar1;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar4;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
            uVar2 = 0x10;
          }
          else {
            (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,local_2b8);
            uStack_190 = 0;
            local_198 = VdrvDeviceQueryStop;
            uStack_200 = 0;
            local_208 = 0x90;
            local_1f8 = 0;
            uStack_1f0 = 0;
            local_1e8 = 0;
            uStack_1e0 = 0;
            local_1d8 = 0;
            uStack_1d0 = 0;
            local_1c8 = 0;
            uStack_1c0 = 0;
            local_1b8 = 0;
            uStack_1b0 = 0;
            local_1a8 = 0;
            uStack_1a0 = 0;
            local_188 = 0;
            uStack_180 = 0;
            (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_2b8,&local_208);
            pwVar3 = L"Microsoft_VHD_ISO_VHBA_%02d";
            uVar4 = RtlUnicodeStringPrintf(local_2a8,L"Microsoft_VHD_ISO_VHBA_%02d",uVar5,param_4);
            uVar1 = (uint)uVar4;
            uVar4 = uVar4 & 0xffffffff;
            if ((int)uVar1 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return uVar4;
              }
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
              uVar2 = 0x11;
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar3,uVar5,local_2a0);
              }
              local_2c8 = 0x409;
              uVar1 = (**(code **)(WdfFunctions_01015 + 0x6c0))
                                (WdfDriverGlobals,local_2b8,local_2a8,&local_248);
              uVar4 = (ulonglong)uVar1;
              if ((int)uVar1 < 0) {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return uVar4;
                }
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
                uVar2 = 0x13;
              }
              else {
                (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_2b8,0x409);
                uVar1 = (**(code **)(WdfFunctions_01015 + 600))
                                  (WdfDriverGlobals,&local_2b8,0,&local_2b0);
                uVar4 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  uStack_170 = 2;
                  local_168 = 0x200000002;
                  uStack_160 = 2;
                  local_158 = 0x200000002;
                  uStack_150 = CONCAT44(param_3,param_3);
                  local_178 = 0x200000030;
                  (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_2b0,&local_178);
                  local_f8 = 0x1c;
                  uStack_f4 = 2;
                  uStack_f0 = 2;
                  uStack_ec = 2;
                  local_e8 = 2;
                  uStack_e4 = 2;
                  local_e0 = 2;
                  (**(code **)(WdfFunctions_01015 + 0xe8))(WdfDriverGlobals,local_2b0,&local_f8);
                  uStack_140 = 0x200000002;
                  uStack_130 = 0x500000002;
                  local_108 = 0xffffffffffffffff;
                  uStack_100 = 0x5ffffffff;
                  local_148 = 0x100000050;
                  local_138 = 0x200000001;
                  uStack_110 = 0x700000002;
                  local_128 = 0x200000002;
                  uStack_120 = 0x300000003;
                  local_118 = 0x400000004;
                  (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_2b0,&local_148);
                  (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_2b0,1,1);
                  local_228 = _guard_check_icall;
                  pcStack_220 = _guard_check_icall;
                  local_218 = VdrvpRegisterHbaDriver;
                  pcStack_210 = VdrvpUnregisterHbaDriver;
                  puStack_280 = &local_238;
                  local_278 = &GUID_VDRV_REGISTRATION_INTERFACE;
                  local_238 = CONCAT44(local_238._4_4_,0x20030);
                  uStack_230 = local_2b0;
                  local_288 = 0x30;
                  uStack_270 = 0;
                  local_260 = 0;
                  local_268 = 0;
                  uVar1 = (**(code **)(WdfFunctions_01015 + 0x720))
                                    (WdfDriverGlobals,local_2b0,&local_288);
                  uVar4 = (ulonglong)uVar1;
                  goto LAB_1c0009073;
                }
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return uVar4;
                }
                if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009073;
                uVar2 = 0x14;
              }
            }
          }
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_6c4249c3353f3ed7bdc2f07cc6a69920_Traceguids,uVar1);
LAB_1c0009073:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_6c4249c3353f3ed7bdc2f07cc6a69920_Traceguids,(int)uVar4);
  }
  return uVar4;
}



===== VdrvDeviceControl @ 1c00090d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VdrvDeviceControl(undefined8 param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4,
                      int param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint *puVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  ulonglong local_res18;
  ulonglong local_res20;
  undefined4 local_58 [2];
  int *local_50;
  undefined8 local_48;
  uint *local_40;
  
  local_40 = (uint *)0x0;
  local_48 = 0;
  local_50 = (int *)0x0;
  local_58[0] = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  KeEnterCriticalRegion();
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,uVar5);
  }
  if (param_5 == 0x2d592c) {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,0x20,&local_40,&local_res20);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c00094a0;
      uVar7 = 0x16;
    }
    else {
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,param_2,0,&local_48,&local_res18);
      puVar3 = local_40;
      uVar8 = local_48;
      uVar2 = local_res20;
      uVar1 = local_res18;
      if (-1 < iVar4) {
        uVar6 = 0;
        if (((EnableVhdopDriver == '\0') || (*local_40 < 2)) ||
           (uVar6 = (ulonglong)local_40[8], local_40[8] < 3)) {
          lVar9 = uVar6 * 0x70;
          ExAcquirePushLockSharedEx(&DAT_1c0005478 + lVar9,0);
          if ((uint)(&DAT_1c0005488)[uVar6 * 0x1c] < 2) {
            ExReleasePushLockSharedEx(&DAT_1c0005478 + lVar9,0);
            iVar4 = VdrvpDoStaticEnumeration(uVar5,(longlong)(&VhdAdapterData + lVar9));
            if (-1 < iVar4) {
              ExAcquirePushLockSharedEx(&DAT_1c0005478 + lVar9,0);
              goto LAB_1c00093d9;
            }
          }
          else {
LAB_1c00093d9:
            if ((&DAT_1c0005488)[uVar6 * 0x1c] == 3) {
              iVar4 = (**(code **)(&DAT_1c0005468 + lVar9))
                                ((&DAT_1c0005448)[uVar6 * 0xe],uVar2 & 0xffffffff,puVar3,
                                 uVar1 & 0xffffffff,uVar8,local_58);
            }
            else {
              iVar4 = -0x3fffff45;
            }
            ExReleasePushLockSharedEx(&DAT_1c0005478 + lVar9,0);
          }
          if (-1 < iVar4) {
            (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,local_58[0]);
            iVar4 = 0;
            goto LAB_1c00094a0;
          }
        }
        else {
          iVar4 = -0x3ffffff3;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,iVar4);
        }
        goto LAB_1c00094a0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c00094a0;
      uVar7 = 0x17;
    }
  }
  else {
    if (param_5 != 0x2d9938) {
      iVar4 = -0x3ffffff0;
      goto LAB_1c00094a0;
    }
    uVar8 = 8;
    uVar5 = WdfDriverGlobals;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_50,0);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,iVar4);
      }
      goto LAB_1c00094a0;
    }
    iVar4 = VdrvpNotifyNetStopEvent(uVar5,local_50,uVar8);
    if (-1 < iVar4) {
      iVar4 = 0;
      goto LAB_1c00094a0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c00094a0;
    uVar7 = 0x1a;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
           &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,iVar4);
LAB_1c00094a0:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar4);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b);
  }
  KeLeaveCriticalRegion();
  return;
}



===== VdrvAddDevice @ 1c0009530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong VdrvAddDevice(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  undefined1 auStack_158 [32];
  undefined8 *local_138;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  code *pcStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_158;
  local_28 = 0;
  local_128 = 0;
  local_118 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = (code *)0x0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  pcStack_d0 = (code *)0x0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,param_3,param_1);
  }
  if (VdrvDeviceCount != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf);
    }
    uVar6 = 0xc0000001;
    goto LAB_1c0009903;
  }
  VdrvDeviceCount = 1;
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_120,0x2a);
  local_88 = VdrvDeviceListCreatePdo;
  local_98 = 0x800000060;
  (**(code **)(WdfFunctions_01015 + 0x410))(WdfDriverGlobals,local_120,&local_98,0);
  uVar4 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_120,0,&local_128);
  uVar1 = uStack_f0;
  iVar3 = (int)uVar4;
  uVar6 = uVar4 & 0xffffffff;
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0009903;
    uVar5 = 0x10;
  }
  else {
    pcStack_d0 = VdrvDeviceControl;
    local_138 = &local_118;
    uStack_f0 = CONCAT44(uStack_f0._4_4_,2);
    uVar2 = uStack_f0;
    uStack_f0._6_2_ = SUB82(uVar1,6);
    uStack_f0._0_6_ = CONCAT15(1,(int5)uVar2);
    local_f8 = 0x200000060;
    local_a8 = CONCAT44(local_a8._4_4_,0xffffffff);
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_128,&local_f8,0);
    iVar3 = (int)uVar4;
    uVar6 = uVar4 & 0xffffffff;
    if (iVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_1c0009903;
      uVar5 = 0x11;
    }
    else {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x268))
                        (WdfDriverGlobals,local_128,&GUID_DEVINTERFACE_SURFACE_VIRTUAL_DRIVE,0);
      iVar3 = (int)uVar4;
      uVar6 = uVar4 & 0xffffffff;
      if (iVar3 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar4;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009903;
        uVar5 = 0x12;
      }
      else {
        RtlInitUnicodeString(&local_110,L"\\DosDevices\\GLOBAL\\VDRVROOT");
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x280))(WdfDriverGlobals,local_128,&local_110);
        iVar3 = (int)uVar4;
        uVar6 = uVar4 & 0xffffffff;
        if (-1 < iVar3) {
          (**(code **)(WdfFunctions_01015 + 0x188))(WdfDriverGlobals,local_128,1,1);
          local_38 = 0x247dd23ee2d9f781;
          uStack_30 = 0x198d65b043566d8d;
          local_28 = 0xf;
          (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,local_128,&local_38);
          KeInitializeEvent(&DAT_1c0005490,0,0);
          _DAT_1c00054a8 = 1;
          KeInitializeEvent(&DAT_1c0005500,0,0);
          _DAT_1c0005518 = 2;
          goto LAB_1c0009903;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar4;
        }
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0009903;
        uVar5 = 0x13;
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,iVar3);
LAB_1c0009903:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,(int)uVar6);
  }
  return uVar6;
}



===== VdrvpDoStaticEnumeration @ 1c0009960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VdrvpDoStaticEnumeration(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_res10;
  undefined4 local_res14;
  undefined8 local_res18;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  ExAcquirePushLockExclusiveEx(param_2 + 0x38,0);
  if (*(int *)(param_2 + 0x48) == 0) {
    RtlInitUnicodeString
              (&local_28,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FsDepends");
    iVar2 = ZwLoadDriver(&local_28);
    if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x3ffffef2)) goto LAB_1c0009b18;
    uVar1 = *(undefined4 *)(param_2 + 0x68);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,uVar1);
    }
    local_res10 = 8;
    local_res14 = uVar1;
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x420))(WdfDriverGlobals,param_1);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x48))(WdfDriverGlobals,uVar3,&local_res10,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,iVar2);
    }
    if (iVar2 < 0) goto LAB_1c0009b18;
    *(undefined4 *)(param_2 + 0x48) = 1;
LAB_1c0009aba:
    ExReleasePushLockExclusiveEx(param_2 + 0x38,0);
    local_res18 = 0xffffffffe52d8b80;
    KeWaitForSingleObject(param_2 + 0x50,0,0,1,&local_res18);
    ExAcquirePushLockExclusiveEx(param_2 + 0x38,0);
    if (*(int *)(param_2 + 0x48) == 1) {
      *(undefined4 *)(param_2 + 0x48) = 2;
    }
  }
  else if (*(int *)(param_2 + 0x48) == 1) goto LAB_1c0009aba;
  iVar2 = 0;
LAB_1c0009b18:
  ExReleasePushLockExclusiveEx(param_2 + 0x38,0);
  return iVar2;
}



===== WppLoadTracingSupport @ 1c0009b40 =====

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



===== __security_init_cookie @ 1c000a008 =====

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



===== DriverEntry @ 1c000a040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res18;
  ulonglong local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  code *local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_68 = (ulonglong)(uint)local_68;
  local_res18 = 0;
  local_48 = (ulonglong)(uint)local_48;
  McGenEventRegister_EtwRegister();
  _WPP_MAIN_CB = 0;
  DAT_1c0005408 = &WPP_ThisDir_CTLGUID_VdrvRootTraceGuid;
  DAT_1c0005410 = 0;
  _DAT_1c0005420 = 0;
  _DAT_1c0005428 = 1;
  WppLoadTracingSupport();
  _DAT_1c0005420 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10);
  }
  VdrvCheckPolicyValue();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_173a767f697c32c0a426cb4ba1809f53_Traceguids,(uint)EnableVhdopDriver);
  }
  local_48 = 0x38;
  local_38 = 0;
  local_40 = VdrvDriverCleanup;
  local_60 = VdrvAddDevice;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_30 = 1;
  local_2c = 1;
  local_68 = 0x20;
  local_58 = 0;
  uStack_50 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_48,&local_68,&local_res18);
  uVar2 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_2,local_res18);
    }
    WppCleanupKm();
    McGenEventUnregister_EtwUnregister();
  }
  else {
    uVar2 = IoReportRootDevice(param_1);
  }
  return uVar2;
}


