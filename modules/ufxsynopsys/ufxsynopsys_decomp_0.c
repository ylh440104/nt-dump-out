
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



===== memcpy_s @ 1c0001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memmove(_Dst,_Src,_MaxCount);
        goto LAB_1c000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _invalid_parameter();
  }
  return eVar1;
}



===== _invalid_parameter @ 1c00010b4 =====

void _invalid_parameter(void)

{
  return;
}



===== __cpu_features_init @ 1c00010d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000113a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010da) */

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



===== DefaultQueue_EvtIoDeviceControl @ 1c00011a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueue_EvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  char cVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar5;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xd,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqddd
              (puVar2[0x4b],uVar4,puVar3,0xe,in_stack_ffffffffffffffb8,(char)param_1,(char)param_2,
               (char)param_3,(char)param_4,(char)param_5);
    uVar5 = (undefined4)((ulonglong)param_1 >> 0x20);
  }
  uVar4 = param_2;
  cVar1 = (*DAT_1c001dec0)(UfxGlobals,*puVar2,param_2,param_3,param_4,CONCAT44(uVar5,param_5));
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar2[0x4b],2,uVar4,0xf,&WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
    }
    uVar4 = 0xc0000010;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x10,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  return;
}



===== DefaultQueue_EvtIoInternalDeviceControl @ 1c0001370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueue_EvtIoInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5)

{
  char cVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar5;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x11,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqddd
              (puVar2[0x4b],uVar4,puVar3,0x12,in_stack_ffffffffffffffb8,(char)param_1,(char)param_2,
               (char)param_3,(char)param_4,(char)param_5);
    uVar5 = (undefined4)((ulonglong)param_1 >> 0x20);
  }
  uVar4 = param_2;
  cVar1 = (*DAT_1c001dec8)(UfxGlobals,*puVar2,param_2,param_3,param_4,CONCAT44(uVar5,param_5));
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar2[0x4b],2,uVar4,0x13,&WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
    }
    uVar4 = 0xc0000010;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x14,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0001534 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0sqq_EtwWriteTransfer @ 1c0001594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sqq_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_R9;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (in_R9 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != '\0');
    local_40 = (int)lVar1 + 1;
  }
  local_3c = 0;
  local_38 = &uStack0000000000000028;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_28 = &uStack0000000000000030;
  local_30 = 4;
  local_20 = 4;
  local_48 = in_R9;
  McGenEventWrite_EtwWriteTransfer
            (&UfxSynopsysGuid_Context,&FailedNtStatus,&UfxSynopsysGuid,4,local_58);
  return;
}



===== WPP_RECORDER_SF_ @ 1c0001640 =====

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



===== WPP_RECORDER_SF_d @ 1c00016d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_qqddd @ 1c0001780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqddd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,5,1,&WPP_462c4d276e5135751c4e692fb8db711a_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 1c00018bc =====

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
  McGenEventWrite_EtwWriteTransfer(&UfxSynopsysGuid_Context,param_2,&UfxSynopsysGuid,3,local_48);
  return;
}



===== RtlStringCchPrintfA @ 1c0001938 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

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



===== RtlStringCchPrintfW @ 1c00019ac =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== SynopsysCsNotifyCallback @ 1c0001a30 =====

void SynopsysCsNotifyCallback(undefined1 param_1,undefined1 param_2)

{
  gIsInConnectedStandby = param_1;
  gIsIdleResiliencyEngaged = param_2;
  SynopsysEtwLogConnectedStandbyInfo();
  return;
}



===== SynopsysDeviceEnterHibernation @ 1c0001a54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDeviceEnterHibernation(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint *puVar11;
  undefined *puVar12;
  undefined8 uVar13;
  undefined8 local_res10;
  undefined1 uVar14;
  byte bVar15;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x30,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar12 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 600),4,puVar12,0x31,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),
                      PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8);
  uVar8 = WdfDriverGlobals;
  uVar13 = DAT_1c001d600;
  plVar7 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar6);
  puVar10 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
  uVar1 = *puVar10;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar8,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,(char)uVar1);
  }
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 600),4,uVar13,0x32,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    *(undefined1 *)(lVar4 + 0x22e) = 1;
  }
  else {
    puVar10 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (uVar8,&RegisterWrite,uVar13,(uint)puVar10 & 0xffff,(char)uVar1);
    }
    *puVar10 = uVar1 | 0x80000000;
    LOCK();
    UNLOCK();
  }
  puVar10 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x10);
  uVar1 = *puVar10;
  bVar15 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,bVar15);
  }
  puVar11 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x10);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterWrite,uVar13,(uint)puVar11 & 0xffff,bVar15 | 2)
    ;
  }
  *puVar11 = uVar1 | 2;
  LOCK();
  UNLOCK();
  puVar10 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
  uVar1 = *puVar10;
  bVar15 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,bVar15);
  }
  puVar11 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar10,&RegisterWrite,uVar13,(uint)puVar11 & 0xffff,bVar15 | 0x40);
  }
  *puVar11 = uVar1 | 0x40;
  LOCK();
  UNLOCK();
  if ((*(char *)(lVar4 + 0x23d) == '\x01') && ((*(uint *)(lVar4 + 0x1d8) >> 9 & 1) == 0)) {
    puVar10 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x1c0);
    uVar1 = *puVar10;
    uVar14 = (undefined1)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,uVar14);
    }
    puVar11 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterWrite,uVar13,(uint)puVar11 & 0xffff,uVar14);
    }
    *puVar11 = uVar1 | 0x20000;
    LOCK();
    UNLOCK();
  }
  puVar10 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
  uVar1 = *puVar10;
  bVar15 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,bVar15);
  }
  puVar11 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterWrite,uVar13,(uint)puVar11 & 0xffff,bVar15);
  }
  *puVar11 = uVar1 & 0x7fffffff;
  do {
    LOCK();
    UNLOCK();
    do {
      puVar10 = (uint *)(*(longlong *)(lVar4 + 0x48) + 0xc);
      uVar3 = *puVar10;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar10,&RegisterRead,uVar13,(uint)puVar10 & 0xffff,(char)uVar3);
      }
      if ((uVar3 >> 0x16 & 1) != 0) {
        puVar11 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar10,&RegisterWrite,uVar13,(uint)puVar11 & 0xffff,bVar15 & 0xbf | 0xa0);
        }
        *puVar11 = uVar1 & 0x7ffffebf | 0xa0;
        LOCK();
        UNLOCK();
        puVar6 = &local_res10;
        local_res10 = 0xfffffffffff0bdc0;
        KeDelayExecutionThread(0);
        SynopsysAcpiSetPmuState(param_1,'\0',puVar6);
        *(undefined1 *)(lVar4 + 0x22d) = 1;
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x33,
                           &WPP_591a655566d938762c68c3daf5528955_Traceguids);
        }
        return;
      }
      puVar9 = (undefined4 *)(*plVar7 + 0xc);
      uVar2 = *puVar9;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar9,&RegisterRead,uVar13,(uint)puVar9 & 0xffff,(char)uVar2);
      }
    } while ((short)uVar2 == 0);
    lVar5 = *plVar7;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar9,&RegisterWrite,uVar13,(uint)(undefined4 *)(lVar5 + 0xc) & 0xffff,(char)uVar2
                );
    }
    *(undefined4 *)(lVar5 + 0xc) = uVar2;
  } while( true );
}



===== SynopsysDeviceExitHibernation @ 1c0001ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDeviceExitHibernation(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  undefined8 local_res10;
  byte bVar9;
  undefined1 uVar10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x34,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),4,puVar7,0x35,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  puVar8 = &local_res10;
  local_res10 = 0xfffffffffffe7960;
  KeDelayExecutionThread(0,0);
  SynopsysAcpiSetPmuState(param_1,'\x01',puVar8);
  puVar4 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x100);
  uVar1 = *puVar4;
  bVar9 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar8,(uint)puVar4 & 0xffff,bVar9);
  }
  puVar5 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x100);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar8,(uint)puVar5 & 0xffff,bVar9 & 0xbf)
    ;
  }
  *puVar5 = uVar1 & 0xffffffbf;
  LOCK();
  UNLOCK();
  if ((*(char *)(lVar2 + 0x23d) == '\x01') && ((*(uint *)(lVar2 + 0x1d8) >> 9 & 1) == 0)) {
    puVar4 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x1c0);
    uVar1 = *puVar4;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar8,(uint)puVar4 & 0xffff,(char)uVar1)
      ;
    }
    uVar6 = uVar1 | 0x20000;
    if ((*(byte *)(lVar2 + 0x1d8) & 0x20) == 0) {
      uVar6 = uVar1 & 0xfffdffff;
    }
    puVar5 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar4,&RegisterWrite,puVar8,(uint)puVar5 & 0xffff,(char)uVar6);
    }
    *puVar5 = uVar6;
    LOCK();
    UNLOCK();
  }
  puVar4 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x10);
  uVar1 = *puVar4;
  bVar9 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar8,(uint)puVar4 & 0xffff,bVar9);
  }
  puVar5 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x10);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar8,(uint)puVar5 & 0xffff,bVar9 & 0xfd)
    ;
  }
  *puVar5 = uVar1 & 0xfffffffd;
  LOCK();
  UNLOCK();
  if (*(char *)(lVar2 + 0x22e) != '\0') {
    *(undefined1 *)(lVar2 + 0x22e) = 0;
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x48) + 4);
    uVar1 = *puVar4;
    uVar10 = (undefined1)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar8,(uint)puVar4 & 0xffff,uVar10);
    }
    puVar5 = (uint *)(*(longlong *)(lVar2 + 0x48) + 4);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar8,(uint)puVar5 & 0xffff,uVar10);
    }
    *puVar5 = uVar1 | 0x80000000;
    LOCK();
    UNLOCK();
  }
  *(undefined1 *)(lVar2 + 0x22d) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,0x36,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return;
}



===== SynopsysDeviceInitializeDefaultEndpoint @ 1c00021ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDeviceInitializeDefaultEndpoint
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  uint *puVar11;
  undefined *puVar12;
  byte bVar13;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3f,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar12 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar4 = *(longlong *)(lVar4 + 0x18);
  if (lVar4 != 0) {
    lVar9 = lVar4;
    puVar12 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    SynopsysTransferDestroy(lVar4,lVar9,puVar12);
    iVar2 = SynopsysTransferInitialize(lVar4,lVar9,puVar12);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0x40,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar2);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
    else {
      UfxDevice_StartConfiguration(*puVar3,'\x01',puVar12);
      uVar8 = 0;
      UfxEndpointConfigureHardware(lVar4,'\0',puVar12);
      puVar12 = (undefined *)0x0;
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      UfxDeviceSetRunStop(*puVar3,'\x01',0);
      SynopsysTransferStart(lVar4,uVar8,puVar12);
      do {
        puVar7 = (uint *)(*(longlong *)(lVar6 + 0x18) + 0xc);
        uVar1 = *puVar7;
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterRead,puVar12,(uint)puVar7 & 0xffff,(char)uVar1);
        }
      } while ((uVar1 >> 10 & 1) != 0);
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar3[0x46]);
      if ((*(char *)((longlong)puVar3 + 0x23c) == '\x01') && (*(int *)(puVar3 + 0x47) == 0)) {
        puVar7 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
        uVar1 = *puVar7;
        bVar13 = (byte)uVar1;
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer(puVar7,&RegisterRead,puVar12,(uint)puVar7 & 0xffff,bVar13)
          ;
        }
        puVar11 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterWrite,puVar12,(uint)puVar11 & 0xffff,bVar13 | 0x40);
        }
        *puVar11 = uVar1 | 0x40;
        LOCK();
        UNLOCK();
      }
      uVar8 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar3[0x46]);
      puVar10 = (undefined4 *)(*(longlong *)(lVar5 + 0x18) + 0x620);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer(uVar8,&RegisterWrite,puVar12,(uint)puVar10 & 0xffff,3);
      }
      *puVar10 = 3;
      LOCK();
      UNLOCK();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar12,0x41,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return;
}



===== SynopsysDevicePerformSoftReset @ 1c00024a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDevicePerformSoftReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  uint *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  uint uVar9;
  undefined *puVar10;
  uint uVar11;
  uint *puVar12;
  undefined1 uVar13;
  byte bVar14;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3a,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  uVar7 = *puVar3;
  puVar10 = PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628;
  (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (*(char *)((longlong)puVar3 + 0x22c) == '\x01') {
    SynopsysAcpiSoftCoreReset(param_1,uVar7,puVar10);
  }
  else {
    puVar6 = (uint *)(puVar3[9] + 4);
    uVar11 = *puVar6;
    uVar13 = (undefined1)uVar11;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,uVar13);
    }
    lVar5 = puVar3[9];
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar6,&RegisterWrite,puVar10,(uint)(uint *)(lVar5 + 4) & 0xffff,uVar13);
    }
    *(uint *)(lVar5 + 4) = uVar11 | 0x40000000;
    LOCK();
    UNLOCK();
    do {
      puVar6 = (uint *)(puVar3[9] + 4);
      uVar11 = *puVar6;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar11);
      }
    } while ((uVar11 & 0x40000000) != 0);
  }
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x10);
  uVar11 = *puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar11)
    ;
  }
  iVar1 = *(int *)(puVar3 + 0x4d);
  uVar11 = uVar11 & 0x6cfff;
  puVar12 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x10);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar6,&RegisterWrite,puVar10,(uint)puVar12 & 0xffff,(char)uVar11);
  }
  *puVar12 = iVar1 << 0x13 | uVar11 | 0x12000;
  LOCK();
  UNLOCK();
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x10);
  puVar8 = (undefined *)(ulonglong)*puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer
              (puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)*puVar6);
  }
  *(undefined1 *)((longlong)puVar3 + 0x23c) = 0;
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x100);
  uVar11 = *puVar6;
  bVar14 = (byte)uVar11;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,bVar14);
  }
  puVar12 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x100);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterWrite;
    McTemplateK0qq_EtwWriteTransfer
              (puVar6,&RegisterWrite,puVar10,(uint)puVar12 & 0xffff,bVar14 & 0xbf);
  }
  *puVar12 = uVar11 & 0xffffffbf;
  LOCK();
  UNLOCK();
  puVar6 = (uint *)puVar3[9];
  uVar11 = *puVar6;
  bVar14 = (byte)uVar11;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,bVar14);
  }
  if (((uVar11 & 7) - 4 < 2) && (*(undefined1 *)((longlong)puVar3 + 0x23d) = 1, (uVar11 & 7) == 5))
  {
    puVar6 = (uint *)puVar3[9];
    uVar11 = uVar11 & 0xfffffffc | 4;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      puVar8 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                (5,&RegisterWrite,puVar10,(uint)puVar6 & 0xffff,bVar14 & 0xfc | 4);
    }
    *puVar6 = uVar11;
    LOCK();
    UNLOCK();
  }
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x40);
  uVar9 = *puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar9);
  }
  *(uint *)(puVar3 + 0x4e) = uVar9 >> 0xb & 0x1f;
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0xc);
  uVar9 = *puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar9);
  }
  if ((uVar9 >> 0x1d & 1) == 0) {
    puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x280);
    uVar9 = *puVar6;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      puVar8 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer
                (puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar9);
    }
    uVar2 = (uVar9 & 0xffff) * *(int *)(puVar3 + 0x4e) >> 10;
    uVar9 = 0x10;
    if (uVar2 < 0x10) {
      uVar9 = uVar2;
    }
    *(uint *)((longlong)puVar3 + 0x26c) = uVar9;
    uVar11 = uVar11 ^ (uVar9 << 0x11 ^ uVar11) & 0x3e0000;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = param_1;
      puVar10 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      puVar8 = (undefined *)CONCAT71((int7)((ulonglong)uVar7 >> 8),4);
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 600),4,puVar10,0x3b,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,
                        (byte)(uVar11 >> 0x11) & 0x1f);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = param_1;
      puVar10 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      puVar8 = (undefined *)CONCAT71((int7)((ulonglong)uVar7 >> 8),4);
      WPP_RECORDER_SF_(*(undefined8 *)(lVar5 + 600),4,puVar10,0x3c,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    *(undefined1 *)((longlong)puVar3 + 0x274) = 1;
  }
  puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 8);
  uVar9 = *puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar9);
  }
  if ((uVar9 >> 0x1d & 1) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar10 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      puVar8 = (undefined *)CONCAT71((int7)((ulonglong)param_1 >> 8),4);
      puVar6 = *(uint **)(lVar5 + 600);
      WPP_RECORDER_SF_(puVar6,4,puVar10,0x3d,&WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    *(undefined1 *)((longlong)puVar3 + 0x275) = 1;
  }
  puVar12 = (uint *)puVar3[9];
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar8 = &RegisterWrite;
    McTemplateK0qq_EtwWriteTransfer
              (puVar6,&RegisterWrite,puVar10,(uint)puVar12 & 0xffff,(char)uVar11);
  }
  *puVar12 = uVar11 & 0xffbfffff;
  LOCK();
  UNLOCK();
  if (*(char *)((longlong)puVar3 + 0x23d) == '\x01') {
    puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x1c0);
    uVar11 = *puVar6;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      puVar8 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer
                (puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar11);
    }
    uVar9 = uVar11 & 0xfffdffff;
    if ((ulonglong)(*(uint *)(puVar3 + 0x3b) & 0x220) != 0) {
      uVar9 = uVar11 | 0x20000;
    }
    puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      puVar8 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                ((ulonglong)(*(uint *)(puVar3 + 0x3b) & 0x220),&RegisterWrite,puVar10,
                 (uint)puVar6 & 0xffff,(char)uVar9);
    }
    *puVar6 = uVar9;
    LOCK();
    UNLOCK();
  }
  SynopsysInterruptProgramEventBuffers(puVar3[1],puVar8,puVar10);
  if (*(char *)(puVar3 + 0x3b) < '\0') {
    puVar6 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x900);
    uVar11 = *puVar6;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,(char)uVar11);
    }
    puVar12 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x900);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterWrite,puVar10,(uint)puVar12 & 0xffff,1);
    }
    *puVar12 = uVar11 & 0xffff0001 | 1;
    LOCK();
    UNLOCK();
  }
  puVar6 = (uint *)(puVar3[9] + 8);
  uVar11 = *puVar6;
  bVar14 = (byte)uVar11;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,puVar10,(uint)puVar6 & 0xffff,bVar14);
  }
  lVar4 = puVar3[9];
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar6,&RegisterWrite,puVar10,(uint)(uint *)(lVar4 + 8) & 0xffff,bVar14 | 0x5f);
  }
  *(uint *)(lVar4 + 8) = uVar11 | 0x25f;
  LOCK();
  UNLOCK();
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar10,0x3e,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return;
}



===== SynopsysDeviceVendorReset @ 1c0002b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDeviceVendorReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  undefined8 uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  undefined4 local_res10 [2];
  undefined1 uVar8;
  undefined *in_stack_ffffffffffffff98;
  undefined4 uVar9;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff98 = &WPP_591a655566d938762c68c3daf5528955_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2e,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar7 = (undefined4 *)&USBFN_FILTER_INTERFACE_CONTROLLER_RESET;
  uVar5 = CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff98 >> 0x10),0x20);
  (**(code **)(WdfFunctions_01015 + 0x418))
            (WdfDriverGlobals,param_1,&USBFN_FILTER_INTERFACE_CONTROLLER_RESET,&local_48,uVar5,0,0);
  uVar9 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if ((*(byte *)(lVar3 + 0x1d8) & 4) != 0) {
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
    uVar1 = *puVar4;
    uVar8 = (undefined1)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar7,(uint)puVar4 & 0xffff,uVar8);
    }
    puVar6 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar7,(uint)puVar6 & 0xffff,uVar8);
    }
    *puVar6 = uVar1 | 0x80000000;
    LOCK();
    UNLOCK();
    puVar7 = local_res10;
    uVar5 = *(undefined8 *)(lVar3 + 0x218);
    local_res10[0] = 0;
    local_res10[0] = (**(code **)(lVar3 + 0x220))(uVar5,0,puVar7,0xa0,CONCAT44(uVar9,4));
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(uVar5,&RegisterWrite,puVar7,(uint)puVar4 & 0xffff,uVar8);
    }
    *puVar4 = uVar1 & 0x7fffffff;
    LOCK();
    UNLOCK();
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x2f,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return;
}



===== SynopsysDevice_EvtDeviceCleanup @ 1c0002d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDevice_EvtDeviceCleanup(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar1 = *(longlong *)(lVar1 + 600);
  lVar2 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  if (lVar1 != lVar2) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control,lVar1);
  }
  return;
}



===== SynopsysDevice_EvtDeviceD0Entry @ 1c0002de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SynopsysDevice_EvtDeviceD0Entry(undefined8 param_1,int param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x23,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  uVar4 = param_1;
  puVar5 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(puVar3[0x4b],uVar4,puVar5,0x24,
                      &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)param_2);
  }
  if (*(char *)((longlong)puVar3 + 0x22d) != '\0') {
    SynopsysDeviceExitHibernation(param_1,uVar4,puVar5);
  }
  uVar6 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar3[0x3a]);
  uVar4 = puVar3[0x3a];
  *(undefined4 *)(puVar3 + 0x48) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  SynopsysEtwLogConnectedStandbyInfo();
  if (2 < param_2) {
    if ((*(byte *)(puVar3 + 0x3b) & 0x40) == 0) {
      SynopsysDeviceVendorReset(param_1,uVar4,uVar6);
      SynopsysDevicePerformSoftReset(param_1,uVar4,uVar6);
      uVar6 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar3[0x3a]);
      *(undefined1 *)((longlong)puVar3 + 0x1cc) = 1;
    }
    else {
      uVar6 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar3[0x3a]);
      *(undefined1 *)((longlong)puVar3 + 0x23e) = 1;
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar3[0x3a]);
  }
  if (param_2 == 5) {
    uVar4 = *puVar3;
    (*DAT_1c001de78)(UfxGlobals);
    SynopsysAcpiNotificationEnabled(param_1,uVar4,uVar6);
    pcVar1 = DAT_1c001de80;
    uVar4 = UfxGlobals;
    if ((puVar3[3] == 0) && (*(char *)((longlong)puVar3 + 0x1ca) == '\0')) {
      *(undefined1 *)((longlong)puVar3 + 0x59) = 1;
      *(undefined1 *)(puVar3 + 0xb) = 1;
      (*pcVar1)(uVar4,*puVar3);
    }
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1);
    if (iVar2 != 3) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1);
      if (iVar2 != 2) goto LAB_1c000306d;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar3[0xc]);
    uVar4 = puVar3[0xc];
    *(undefined1 *)(puVar3 + 0x45) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
    SynopsysAcpiNotificationEnabled(param_1,uVar4,uVar6);
  }
LAB_1c000306d:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x25,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return 0;
}



===== SynopsysDevice_EvtDeviceD0Exit @ 1c00030c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SynopsysDevice_EvtDeviceD0Exit(undefined8 param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x26,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  uVar2 = param_1;
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(lVar1 + 600),uVar2,puVar3,0x27,
                      &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)param_2);
  }
  if ((param_2 - 4U < 2) && (*(char *)(lVar1 + 0x229) == '\x01')) {
    SynopsysDeviceEnterHibernation(param_1,uVar2,puVar3);
  }
  uVar2 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x1d0));
  *(int *)(lVar1 + 0x240) = param_2;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x1d0));
  SynopsysEtwLogConnectedStandbyInfo();
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar2,0x28,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return 0;
}



===== SynopsysDevice_EvtDeviceD0ExitPreInterruptsDisabled @ 1c0003220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SynopsysDevice_EvtDeviceD0ExitPreInterruptsDisabled
          (undefined8 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x29,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar3 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar2[0x3a]);
  *(undefined1 *)((longlong)puVar2 + 0x1cc) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar2[0x3a]);
  if (((param_2 == 5) ||
      (iVar1 = (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1), iVar1 == 3)) ||
     (iVar1 = (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1), iVar1 == 2)) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar2[0xc]);
    *(undefined1 *)(puVar2 + 0x45) = 1;
    if ((*(char *)(puVar2 + 0xb) == '\0') && (*(char *)(puVar2 + 0x4c) == '\0')) {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar2[0xc]);
    }
    else {
      KeClearEvent(puVar2 + 5);
      if (param_2 == 5) {
        (*DAT_1c001df00)(UfxGlobals,*puVar2);
      }
      (*DAT_1c001de88)(UfxGlobals,*puVar2);
      *(undefined1 *)(puVar2 + 0xb) = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar2[0xc]);
      uVar3 = 0;
      KeWaitForSingleObject(puVar2 + 5,0,0,0,0);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_(puVar2[0x4b],4,uVar3,0x2a,&WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar3,0x2b,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return 0;
}



===== WPP_RECORDER_SF_D @ 1c0003480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_DDD @ 1c0003530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_L @ 1c0003620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 1c00036c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x5a,pwVar2,lVar1,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_591a655566d938762c68c3daf5528955_Traceguids,0x5a,
                  in_stack_00000030,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_ddd @ 1c00037f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x45,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_591a655566d938762c68c3daf5528955_Traceguids,0x45,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_i @ 1c00038dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_i(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x5b,&uStack0000000000000030,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_591a655566d938762c68c3daf5528955_Traceguids,0x5b,
                  &uStack0000000000000030,8,0);
  return;
}



===== WPP_RECORDER_SF_iS @ 1c0003988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,wchar_t *param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  pwVar3 = param_7;
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_7[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_591a655566d938762c68c3daf5528955_Traceguids,param_4,&param_6,8,pwVar2,lVar1,0);
  }
  if (pwVar3 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (pwVar3[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_591a655566d938762c68c3daf5528955_Traceguids,param_4,&param_6,8,
                  pwVar3,lVar4,0);
  return;
}



===== McGenControlCallbackV2 @ 1c0003ae0 =====

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
  
  if (param_7 == 0) {
    return;
  }
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
LAB_1c0003bf8:
    gEtwContext = 0;
  }
  else {
    if (param_2 == 1) {
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
    else if (param_2 == 0) goto LAB_1c0003bf8;
    gEtwContext = 1;
    SynopsysEtwRundown();
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c0003c0c =====

void McGenEventRegister_EtwRegister(void)

{
  if (UfxSynopsysGuid_Context == 0) {
    EtwRegister(&UfxSynopsysGuid,McGenControlCallbackV2,&UfxSynopsysGuid_Context,
                &UfxSynopsysGuid_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c0003c4c =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (UfxSynopsysGuid_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    UfxSynopsysGuid_Context = 0;
  }
  return uVar1;
}



===== WppClassicProviderCallback @ 1c0003c80 =====

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



===== EtwUpdateDeviceHandle @ 1c0003cdc =====

void EtwUpdateDeviceHandle(undefined8 param_1)

{
  DAT_1c001df18 = param_1;
  return;
}



===== McTemplateK0n_EtwWriteTransfer @ 1c0003cec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0n_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5)

{
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = param_5;
  local_1c = 0;
  local_20 = param_4;
  McGenEventWrite_EtwWriteTransfer(&UfxSynopsysGuid_Context,param_2,&UfxSynopsysGuid,2,local_38);
  return;
}



===== McTemplateK0nn_EtwWriteTransfer @ 1c0003d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0nn_EtwWriteTransfer(void)

{
  undefined1 auStackY_78 [32];
  undefined8 local_48 [3];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_2c = 0;
  local_30 = 0x10;
  local_1c = 0;
  local_20 = 7;
  McGenEventWrite_EtwWriteTransfer
            (&UfxSynopsysGuid_Context,&EndpointInformation,&UfxSynopsysGuid,3,local_48);
  return;
}



===== McTemplateK0qqqq_EtwWriteTransfer @ 1c0003de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &uStack0000000000000028;
  local_40 = 4;
  local_38 = &uStack0000000000000030;
  local_30 = 4;
  local_28 = &uStack0000000000000038;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer
            (&UfxSynopsysGuid_Context,&RegisterInformation,&UfxSynopsysGuid,5,local_68);
  return;
}



===== McTemplateK0ttqtqq_EtwWriteTransfer @ 1c0003e88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ttqtqq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = local_res20;
  local_70 = 4;
  local_68 = &uStack0000000000000028;
  local_60 = 4;
  local_58 = &uStack0000000000000030;
  local_50 = 4;
  local_48 = &uStack0000000000000038;
  local_40 = 4;
  local_38 = &uStack0000000000000040;
  local_30 = 4;
  local_28 = &uStack0000000000000048;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer
            (&UfxSynopsysGuid_Context,&ConnectedStandbyInformation,&UfxSynopsysGuid,7,local_88);
  return;
}



===== SynopsysEtwLogConnectedStandbyInfo @ 1c0003f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysEtwLogConnectedStandbyInfo(void)

{
  longlong *plVar1;
  
  if (DAT_1c001df18 != 0) {
    plVar1 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,DAT_1c001df18,
                        PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    if (*plVar1 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,*plVar1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x10) != 0) {
        McTemplateK0ttqtqq_EtwWriteTransfer();
      }
    }
  }
  return;
}



===== SynopsysEtwRundown @ 1c000400c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysEtwRundown(void)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  
  if (DAT_1c001df18 != 0) {
    SynopsysEtwLogConnectedStandbyInfo();
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,DAT_1c001df18,
                        PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*puVar2,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
    uVar9 = 0;
    while( true ) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 8));
      if (uVar1 <= uVar9) break;
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 8),uVar9);
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,uVar4,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x10) != 0) {
        McTemplateK0nn_EtwWriteTransfer();
      }
      uVar9 = uVar9 + 1;
    }
    uVar9 = 0;
    while( true ) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10));
      if (uVar1 <= uVar9) break;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x10),uVar9);
      uVar4 = WdfDriverGlobals;
      puVar10 = PTR__WDF_ETW_ERROR_RECORD_CONTEXT_TYPE_INFO_1c001d680;
      piVar6 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar5);
      if (*piVar6 == 0) {
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x20) != 0) {
          uVar11 = 0x18;
          puVar8 = &ChargerDetectionError;
          goto LAB_1c00041ce;
        }
      }
      else if ((*piVar6 == 1) && ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x20) != 0)) {
        uVar11 = 0x10;
        puVar8 = &DeterminePortTypeFailed;
LAB_1c00041ce:
        McTemplateK0n_EtwWriteTransfer(uVar4,puVar8,puVar10,uVar11,piVar6 + 2);
      }
      uVar9 = uVar9 + 1;
    }
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,DAT_1c001df18);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x10) != 0) {
      uVar4 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x1d0));
      if (*(int *)(lVar3 + 0x240) == 1) {
        puVar7 = *(undefined4 **)(lVar3 + 0x48);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterRead,uVar4,(uint)puVar7 & 0xffff,(char)*puVar7);
        }
        puVar7 = (undefined4 *)(*(longlong *)(lVar3 + 0x48) + 4);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterRead,uVar4,(uint)puVar7 & 0xffff,(char)*puVar7);
        }
        puVar7 = (undefined4 *)(*(longlong *)(lVar3 + 0x48) + 8);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterRead,uVar4,(uint)puVar7 & 0xffff,(char)*puVar7);
        }
        puVar7 = (undefined4 *)(*(longlong *)(lVar3 + 0x48) + 0xc);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterRead,uVar4,(uint)puVar7 & 0xffff,(char)*puVar7);
        }
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 0x10) != 0) {
          McTemplateK0qqqq_EtwWriteTransfer();
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x1d0));
    }
  }
  return;
}



===== EventBufferHandleEvent @ 1c000433c =====

undefined4 EventBufferHandleEvent(undefined *param_1,uint *param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2d,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  uVar1 = *param_2;
  if ((uVar1 & 1) == 0) {
    uVar3 = HandleEndpointEvent((ulonglong)param_1,uVar1,param_3);
    uVar2 = (undefined4)uVar3;
  }
  else {
    uVar3 = HandleDeviceEvent(param_1,uVar1,param_3);
    uVar2 = (undefined4)uVar3;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2e,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return uVar2;
}



===== HandleDeviceEvent @ 1c00043f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HandleDeviceEvent(undefined *param_1,uint param_2,undefined8 param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  undefined7 uVar6;
  undefined *puVar5;
  undefined *puVar7;
  undefined2 uVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x15,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  puVar5 = param_1;
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar4 = param_2 >> 8 & 0xf;
  uVar6 = (undefined7)((ulonglong)puVar5 >> 8);
  if (uVar4 == 0) {
    *(undefined1 *)((longlong)puVar2 + 0x6b) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar5 = (undefined *)CONCAT71(uVar6,4);
      WPP_RECORDER_SF_(puVar2[0x4b],4,puVar7,0x16,&WPP_6870c699ef883de553917296c0bc562c_Traceguids);
    }
    HandleUsbDisconnect(param_1,puVar5,puVar7);
  }
  else if (uVar4 == 1) {
    *(undefined1 *)((longlong)puVar2 + 0x6b) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar5 = (undefined *)CONCAT71(uVar6,4);
      WPP_RECORDER_SF_(puVar2[0x4b],4,puVar7,0x17,&WPP_6870c699ef883de553917296c0bc562c_Traceguids);
    }
    HandleUsbReset(param_1,puVar5,puVar7);
  }
  else if (uVar4 == 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar5 = (undefined *)CONCAT71(uVar6,4);
      WPP_RECORDER_SF_(puVar2[0x4b],4,puVar7,0x18,&WPP_6870c699ef883de553917296c0bc562c_Traceguids);
    }
    HandleUsbConnectionDone(param_1,puVar5,puVar7);
  }
  else {
    bVar1 = (byte)(param_2 >> 0x10);
    if (uVar4 == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(puVar2[0x4b],4,puVar7,0x19,
                          &WPP_6870c699ef883de553917296c0bc562c_Traceguids,bVar1 & 0xf);
      }
      HandleUSBLinkStateChange(param_1,param_2,puVar7);
    }
    else {
      if (uVar4 == 4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(puVar2[0x4b],4,puVar7,0x1a,
                           &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
        }
        pcVar3 = DAT_1c001de98;
        if (*(char *)((longlong)puVar2 + 0x6b) == '\0') goto LAB_1c0004684;
        *(undefined1 *)((longlong)puVar2 + 0x6b) = 0;
      }
      else {
        if (uVar4 != 6) {
          if (uVar4 == 10) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 1;
            }
            uVar8 = 0x1c;
          }
          else {
            if (uVar4 != 0xb) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return 1;
              }
              WPP_RECORDER_SF_D(puVar2[0x4b],2,puVar7,0x1e,
                                &WPP_6870c699ef883de553917296c0bc562c_Traceguids,(char)param_2);
              goto LAB_1c0004684;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 1;
            }
            uVar8 = 0x1d;
          }
          WPP_RECORDER_SF_(puVar2[0x4b],2,puVar7,uVar8,
                           &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
          goto LAB_1c0004684;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(puVar2[0x4b],4,puVar7,0x1b,
                             &WPP_6870c699ef883de553917296c0bc562c_Traceguids,bVar1 & 0xf,
                             (byte)(param_2 >> 0x14) & 1);
        }
        pcVar3 = DAT_1c001de90;
        if (*(char *)((longlong)puVar2 + 0x6b) != '\0') goto LAB_1c0004684;
        *(undefined1 *)((longlong)puVar2 + 0x6b) = 1;
      }
      (*pcVar3)(UfxGlobals,*puVar2);
    }
  }
LAB_1c0004684:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x1f,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return 1;
}



===== HandleEndpointEvent @ 1c00046d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HandleEndpointEvent(ulonglong param_1,uint param_2,undefined8 param_3)

{
  int *piVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined *puVar11;
  undefined2 uVar12;
  byte bVar13;
  undefined *in_stack_ffffffffffffffa8;
  undefined1 uVar14;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_6870c699ef883de553917296c0bc562c_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x20,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar11 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar4 = *(longlong *)(lVar4 + 0x18 + (ulonglong)(param_2 >> 1 & 0x1f) * 8);
  if (lVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 1;
    }
    uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_SF_D(uVar6,3,puVar11,0x21,&WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                      (byte)(param_2 >> 1) & 0x1f);
    goto LAB_1c0004d32;
  }
  uVar2 = param_2 >> 6 & 0xf;
  uVar14 = (undefined1)param_2;
  if (uVar2 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
      uVar12 = 0x22;
LAB_1c0004cfc:
      uVar2 = param_2 >> 0xc & 0xf;
      WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar5 + 0x40),(ulonglong)uVar2,puVar11,uVar12,
                          &WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                          (byte)(param_2 >> 1) & 0x1f,(char)uVar2,uVar14);
    }
  }
  else {
    if (uVar2 != 2) {
      if (uVar2 == 3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,lVar4,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8
                            );
          puVar11 = (undefined *)(ulonglong)(param_2 >> 0xf & 1);
          WPP_RECORDER_SF_DDdD(*(undefined8 *)(lVar5 + 0x40));
        }
        SynopsysTransferNotReady(lVar4,param_2,puVar11);
        goto LAB_1c0004d32;
      }
      if (uVar2 != 7) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 1;
        }
        puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
        WPP_RECORDER_SF_D(*(undefined8 *)(lVar4 + 0x40),2,puVar11,0x2b,
                          &WPP_6870c699ef883de553917296c0bc562c_Traceguids,uVar14);
        goto LAB_1c0004d32;
      }
      uVar2 = param_2 >> 0x18 & 0xf;
      if (uVar2 == 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,lVar4,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8
                            );
          uVar10 = param_2 >> 0x10 & 0x7f;
          puVar11 = (undefined *)(ulonglong)uVar10;
          uVar2 = param_2 >> 0xc & 0xf;
          WPP_RECORDER_SF_DDDD
                    (*(undefined8 *)(lVar7 + 0x40),(ulonglong)uVar2,puVar11,0x25,
                     in_stack_ffffffffffffffa8,(byte)(param_2 >> 1) & 0x1f,(char)uVar2,(char)uVar10,
                     uVar14);
        }
LAB_1c0004956:
        SynopsysTransferCommandStartComplete(lVar4,param_2,puVar11);
      }
      else {
        if (uVar2 == 7) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
            uVar2 = param_2 >> 0xc & 0xf;
            WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar7 + 0x40),(ulonglong)uVar2,puVar11,0x26,
                                &WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                                (byte)(param_2 >> 1) & 0x1f,(char)uVar2,uVar14);
          }
          goto LAB_1c0004956;
        }
        if (uVar2 == 8) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,lVar4,
                               PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
            uVar10 = param_2 >> 0x10 & 0x7f;
            puVar11 = (undefined *)(ulonglong)uVar10;
            uVar2 = param_2 >> 0xc & 0xf;
            WPP_RECORDER_SF_DDDD
                      (*(undefined8 *)(lVar7 + 0x40),(ulonglong)uVar2,puVar11,0x27,
                       in_stack_ffffffffffffffa8,(byte)(param_2 >> 1) & 0x1f,(char)uVar2,
                       (char)uVar10,uVar14);
          }
          SynopsysTransferCommandEndComplete(lVar4,param_2,puVar11);
        }
        else if (uVar2 == 4) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
            uVar2 = param_2 >> 0xc & 0xf;
            param_1 = (ulonglong)uVar2;
            WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar7 + 0x40),param_1,puVar11,0x28,
                                &WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                                (byte)(param_2 >> 1) & 0x1f,(char)uVar2,uVar14);
          }
          SynopsysTransferStallSetComplete(lVar4,param_1,puVar11);
        }
        else if (uVar2 == 5) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
            lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
            uVar2 = param_2 >> 0xc & 0xf;
            param_1 = (ulonglong)uVar2;
            WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar7 + 0x40),param_1,puVar11,0x29,
                                &WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                                (byte)(param_2 >> 1) & 0x1f,(char)uVar2,uVar14);
          }
          SynopsysTransferStallClearComplete(lVar4,param_1,puVar11);
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
          WPP_RECORDER_SF_dDDD(*(undefined8 *)(lVar4 + 0x40));
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar3[0x46]);
      piVar1 = (int *)(puVar3 + 0x47);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        if (*(char *)((longlong)puVar3 + 0x23c) == '\x01') {
          puVar8 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
          uVar2 = *puVar8;
          bVar13 = (byte)uVar2;
          if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
            McTemplateK0qq_EtwWriteTransfer
                      (puVar8,&RegisterRead,puVar11,(uint)puVar8 & 0xffff,bVar13);
          }
          puVar9 = (uint *)(*(longlong *)(lVar5 + 0x18) + 0x100);
          if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
            McTemplateK0qq_EtwWriteTransfer
                      (puVar8,&RegisterWrite,puVar11,(uint)puVar9 & 0xffff,bVar13 | 0x40);
          }
          *puVar9 = uVar2 | 0x40;
          LOCK();
          UNLOCK();
        }
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar3[0x46]);
        if (*(char *)((longlong)puVar3 + 0x251) == '\0') {
          puVar11 = (undefined *)0x0;
          (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,puVar3[0x49]);
        }
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar3[0x46]);
      }
      goto LAB_1c0004d32;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar4);
      uVar12 = 0x23;
      goto LAB_1c0004cfc;
    }
  }
  SynopsysTransferComplete(lVar4,param_2,puVar11);
LAB_1c0004d32:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar11,0x2c,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return 1;
}



===== HandleUSBLinkStateChange @ 1c0004d8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleUSBLinkStateChange(undefined8 param_1,uint param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x12,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar1 = UfxGlobals;
  uVar3 = param_2 >> 0x10 & 0xf;
  if (uVar3 == 0) {
    if (*(char *)((longlong)puVar2 + 0x6b) != '\0') {
      *(undefined1 *)((longlong)puVar2 + 0x6b) = 0;
      (*DAT_1c001de98)(uVar1,*puVar2);
    }
    *(undefined1 *)(puVar2 + 0xd) = 0;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_D(puVar2[0x4b],5,puVar4,0x13,&WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                        (char)uVar3);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x14,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return;
}



===== HandleUsbConnectionDone @ 1c0004eb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleUsbConnectionDone(undefined *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined *puVar6;
  ulonglong uVar7;
  uint *puVar8;
  byte bVar9;
  undefined1 uVar10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xc,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar3 = WdfDriverGlobals;
  puVar6 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))();
  uVar5 = *(uint *)(puVar1[9] + 0xc);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_1 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer
              (uVar3,&RegisterRead,puVar6,(uint)(uint *)(puVar1[9] + 0xc) & 0xffff,(char)uVar5);
  }
  uVar5 = uVar5 & 7;
  if (uVar5 == 4) {
    *(undefined4 *)((longlong)puVar1 + 0x6c) = 3;
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x10);
    uVar5 = *puVar4;
    bVar9 = (byte)uVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,bVar9);
    }
    puVar8 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x10);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                (puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,bVar9 & 0x7f | 0x40);
    }
    *puVar8 = uVar5 & 0xffffff7f | 0x40;
    LOCK();
    UNLOCK();
    *(undefined1 *)((longlong)puVar1 + 0x23c) = 1;
    if ((*(char *)((longlong)puVar1 + 0x23d) != '\x01') ||
       ((*(uint *)(puVar1 + 0x3b) >> 9 & 1) != 0)) goto LAB_1c00051cb;
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
    uVar5 = *puVar4;
    uVar10 = (undefined1)uVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,uVar10);
    }
    puVar8 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,uVar10);
    }
    *puVar8 = uVar5 & 0xfffdffff;
  }
  else {
    if ((uVar5 - 1 & 0xfffffffd) == 0) {
      *(undefined4 *)((longlong)puVar1 + 0x6c) = 1;
    }
    else {
      *(uint *)((longlong)puVar1 + 0x6c) = ~-(uint)(uVar5 != 0) & 2;
    }
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x10);
    uVar5 = *puVar4;
    bVar9 = (byte)uVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,bVar9);
    }
    puVar8 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x10);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                (puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,bVar9 & 0x3f);
    }
    *puVar8 = uVar5 & 0xffffff3f;
    LOCK();
    UNLOCK();
    if ((*(char *)((longlong)puVar1 + 0x23d) == '\x01') &&
       ((*(uint *)(puVar1 + 0x3b) >> 9 & 1) == 0)) {
      puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
      uVar5 = *puVar4;
      uVar10 = (undefined1)uVar5;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        param_1 = &RegisterRead;
        McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,uVar10);
      }
      puVar8 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x1c0);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        param_1 = &RegisterWrite;
        McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,uVar10);
      }
      *puVar8 = uVar5 | 0x20000;
      LOCK();
      UNLOCK();
    }
    *(undefined1 *)((longlong)puVar1 + 0x23c) = 0;
    puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x100);
    uVar5 = *puVar4;
    bVar9 = (byte)uVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,bVar9);
    }
    puVar8 = (uint *)(*(longlong *)(lVar2 + 0x18) + 0x100);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_1 = &RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                (puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,bVar9 & 0xbf);
    }
    *puVar8 = uVar5 & 0xffffffbf;
  }
  LOCK();
  UNLOCK();
LAB_1c00051cb:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(puVar1[0x4b],param_1,puVar6,0xd,
                      &WPP_6870c699ef883de553917296c0bc562c_Traceguids,
                      (char)*(undefined4 *)((longlong)puVar1 + 0x6c));
  }
  if ((*(byte *)(puVar1 + 0x3b) & 2) != 0) {
    puVar4 = (uint *)(*(longlong *)(lVar2 + 8) + 0xf8830);
    uVar5 = *puVar4;
    uVar10 = (undefined1)uVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,puVar6,(uint)puVar4 & 0xffff,uVar10);
    }
    puVar8 = (uint *)(*(longlong *)(lVar2 + 8) + 0xf8830);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterWrite,puVar6,(uint)puVar8 & 0xffff,uVar10);
    }
    *puVar8 = uVar5 & 0xfeffffff;
    LOCK();
    UNLOCK();
  }
  uVar7 = (ulonglong)*(uint *)((longlong)puVar1 + 0x6c);
  (*DAT_1c001dea0)(UfxGlobals,*puVar1);
  *(undefined1 *)((longlong)puVar1 + 0x6a) = 1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0xe,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return;
}



===== HandleUsbDisconnect @ 1c00052e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleUsbDisconnect(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  byte bVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xf,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  uVar5 = WdfDriverGlobals;
  puVar6 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar1 = *(uint *)(puVar4[9] + 4);
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (uVar5,&RegisterRead,puVar6,(uint)(uint *)(puVar4[9] + 4) & 0xffff,bVar7);
  }
  lVar2 = puVar4[9];
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (uVar5,&RegisterWrite,puVar6,(uint)(uint *)(lVar2 + 4) & 0xffff,bVar7 & 0xbf | 0xa0);
  }
  *(uint *)(lVar2 + 4) = uVar1 & 0xfffffebf | 0xa0;
  LOCK();
  UNLOCK();
  if (*(char *)(puVar4 + 0x4c) == '\x01') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar4[0x4b],4,puVar6,0x10,&WPP_6870c699ef883de553917296c0bc562c_Traceguids);
    }
    pcVar3 = DAT_1c001de88;
    uVar5 = UfxGlobals;
    *(undefined1 *)(puVar4 + 0xd) = 0;
    *(undefined1 *)((longlong)puVar4 + 0x6b) = 0;
    (*pcVar3)(uVar5,*puVar4);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x11,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return;
}



===== HandleUsbReset @ 1c0005450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HandleUsbReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  byte bVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  puVar5 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar4 = *puVar3;
  UfxDevice_Reset(uVar4,param_1,puVar5);
  *(undefined1 *)(puVar3 + 0xd) = 0;
  uVar1 = *(uint *)puVar3[9];
  bVar6 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (uVar4,&RegisterRead,puVar5,(uint)(uint *)puVar3[9] & 0xffff,bVar6);
  }
  puVar2 = (uint *)puVar3[9];
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar4,&RegisterWrite,puVar5,(uint)puVar2 & 0xffff,bVar6 & 7);
  }
  *puVar2 = uVar1 & 0xfffffc07;
  LOCK();
  UNLOCK();
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0xb,
                     &WPP_6870c699ef883de553917296c0bc562c_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_DDDD @ 1c0005578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6870c699ef883de553917296c0bc562c_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_6870c699ef883de553917296c0bc562c_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_DDdD @ 1c0005684 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6870c699ef883de553917296c0bc562c_Traceguids,0x24,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_6870c699ef883de553917296c0bc562c_Traceguids,0x24,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_dDDD @ 1c0005790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6870c699ef883de553917296c0bc562c_Traceguids,0x2a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_6870c699ef883de553917296c0bc562c_Traceguids,0x2a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c000589c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== DeviceInterrupt_EvtAttachInterruptIsr @ 1c0005980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
DeviceInterrupt_EvtAttachInterruptIsr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x16,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 8));
  if (*(char *)(lVar1 + 0x59) == '\0') {
    *(undefined1 *)(lVar1 + 0x59) = 1;
  }
  else {
    if (*(longlong *)(lVar1 + 0x20) != 0) goto LAB_1c0005a6f;
    *(undefined1 *)(lVar1 + 0x59) = 0;
  }
  *(undefined1 *)(lVar1 + 0x5a) = 1;
  (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
LAB_1c0005a6f:
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x17,
                             &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== DeviceInterrupt_EvtDetachInterruptIsr @ 1c0005ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
DeviceInterrupt_EvtDetachInterruptIsr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x18,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 8));
  if (*(char *)(lVar1 + 0x59) != '\0') {
    *(undefined1 *)(lVar1 + 0x59) = 0;
    *(undefined1 *)(lVar1 + 0x5a) = 1;
    (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x19,
                             &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== DeviceInterrupt_EvtInterruptDpc @ 1c0005c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceInterrupt_EvtInterruptDpc
               (undefined8 param_1,undefined *param_2,undefined8 param_3,undefined *param_4)

{
  char cVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  char *pcVar12;
  uint uVar13;
  undefined1 uVar14;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = (code *)0x13;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar5[0xc]);
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,puVar5[1]);
  cVar1 = *(char *)((longlong)puVar5 + 0x59);
  cVar2 = *(char *)((longlong)puVar5 + 0x5a);
  *(undefined1 *)((longlong)puVar5 + 0x5a) = 0;
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,puVar5[1]);
  pcVar3 = DAT_1c001de88;
  puVar11 = UfxGlobals;
  if ((cVar2 != '\0') && (cVar1 != '\0')) {
    if (*(char *)(puVar5 + 0xb) != '\0') {
      *(undefined1 *)(puVar5 + 0xd) = 0;
      *(undefined1 *)((longlong)puVar5 + 0x6b) = 0;
      (*pcVar3)(puVar11,*puVar5);
    }
    *(undefined1 *)(puVar5 + 0xd) = 0;
    *(undefined1 *)((longlong)puVar5 + 0x6b) = 0;
    if (*(char *)(puVar5 + 0x45) == '\0') {
      (*DAT_1c001de80)(UfxGlobals,*puVar5);
      *(undefined1 *)(puVar5 + 0xb) = 1;
    }
  }
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,puVar5[1],
                      PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8);
  puVar11 = (uint *)*puVar6;
  pcVar12 = DAT_1c001d600;
  plVar7 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar13 = 0;
  if ((*(char *)(puVar5 + 0x3b) < '\0') && ((char)plVar7[4] == '\x01')) {
    puVar11 = (uint *)((longlong)plVar7 + 0x1c);
    EventBufferHandleEvent(param_2,puVar11,pcVar12);
    *(undefined1 *)(plVar7 + 4) = 0;
  }
  puVar10 = (uint *)(*plVar7 + 0xc);
  uVar9 = *puVar10;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (undefined *)((ulonglong)puVar10 & 0xffff);
    puVar11 = (uint *)&RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,pcVar12,(int)param_4,(char)uVar9);
  }
  do {
    if ((short)uVar9 == 0) break;
    puVar11 = (uint *)(plVar7[2] + (ulonglong)*(uint *)(plVar7 + 3) * 4);
    iVar4 = EventBufferHandleEvent(param_2,puVar11,pcVar12);
    uVar13 = uVar13 + 1;
    lVar8 = *plVar7;
    uVar9 = (int)plVar7[3] + iVar4 & 0x3ff;
    *(uint *)(plVar7 + 3) = uVar9;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_4 = (undefined *)((ulonglong)(lVar8 + 0xc) & 0xffff);
      puVar11 = (uint *)&RegisterWrite;
      McTemplateK0qq_EtwWriteTransfer
                ((ulonglong)uVar9,&RegisterWrite,pcVar12,(int)param_4,(char)(iVar4 * 4));
    }
    *(int *)(lVar8 + 0xc) = iVar4 * 4;
    LOCK();
    UNLOCK();
    puVar10 = (uint *)(*plVar7 + 0xc);
    uVar9 = *puVar10;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_4 = (undefined *)((ulonglong)puVar10 & 0xffff);
      puVar11 = (uint *)&RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,pcVar12,(int)param_4,(char)uVar9);
    }
  } while (uVar13 < 0x10);
  if (*(char *)((longlong)puVar5 + 0x69) != '\0') {
    puVar10 = (uint *)(puVar5[9] + 0xc);
    uVar13 = *puVar10;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      param_4 = (undefined *)((ulonglong)puVar10 & 0xffff);
      puVar11 = (uint *)&RegisterRead;
      McTemplateK0qq_EtwWriteTransfer(puVar10,&RegisterRead,pcVar12,(int)param_4,(char)uVar13);
    }
    if ((uVar13 >> 0x16 & 1) != 0) {
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar5);
      param_4 = *(undefined **)(WdfFunctions_01015 + 0xa00);
      (*(code *)param_4)(WdfDriverGlobals,*(undefined8 *)(lVar8 + 0x128));
      pcVar12 = (char *)0x0;
      puVar11 = (uint *)*puVar5;
      puVar10 = UfxGlobals;
      (*DAT_1c001de70)();
      *(undefined1 *)((longlong)puVar5 + 0x69) = 0;
    }
  }
  if ((cVar1 == '\0') && (*(char *)(puVar5 + 0xb) != '\0')) {
    if ((*(char *)(puVar5 + 0x39) == '\0') && ((*(byte *)(puVar5 + 0x3b) & 1) != 0)) {
      puVar11 = (uint *)0x0;
      SmfEnqueueEventCommon(puVar5[10],0,pcVar12,param_4);
    }
    *(undefined1 *)(puVar5 + 0xd) = 0;
    *(undefined1 *)((longlong)puVar5 + 0x6b) = 0;
    if (0 < *(int *)(puVar5 + 0x2d)) {
      SynopsysAttachAbortOperation(param_2,puVar11,pcVar12);
    }
    ProprietaryChargerEnqueueAbortOperation(*puVar5,puVar11,pcVar12);
    puVar10 = UfxGlobals;
    (*DAT_1c001de88)(UfxGlobals,*puVar5);
    *(undefined1 *)(puVar5 + 0xb) = 0;
  }
  if (*(char *)(puVar5 + 0x3b) < '\0') {
    lVar8 = *plVar7;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar10,&RegisterWrite,pcVar12,(uint)(undefined4 *)(lVar8 + 0xc) & 0xffff,0);
    }
    *(undefined4 *)(lVar8 + 0xc) = 0x80000000;
    LOCK();
    UNLOCK();
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(puVar5[0x4b],5,pcVar12,0x14,&WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  puVar11 = (uint *)(*plVar7 + 8);
  uVar13 = *puVar11;
  uVar14 = (undefined1)uVar13;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar11,&RegisterRead,pcVar12,(uint)puVar11 & 0xffff,uVar14);
  }
  lVar8 = *plVar7;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar11,&RegisterWrite,pcVar12,(uint)(uint *)(lVar8 + 8) & 0xffff,uVar14);
  }
  *(uint *)(lVar8 + 8) = uVar13 & 0x7fffffff;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar5[0xc]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar12,0x15,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return;
}



===== DeviceInterrupt_EvtInterruptIsr @ 1c00060e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 DeviceInterrupt_EvtInterruptIsr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined1 uVar10;
  undefined *puVar11;
  undefined1 uVar12;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xe,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  uVar10 = 0;
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8
                     );
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar4,DAT_1c001d600);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x4b8))(WdfDriverGlobals,param_1);
  puVar11 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar6);
  puVar8 = (undefined4 *)(*plVar5 + 0xc);
  uVar1 = *puVar8;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar8,&RegisterRead,puVar11,(uint)puVar8 & 0xffff,(char)uVar1);
  }
  if ((short)uVar1 != 0) {
    uVar10 = 1;
    *(undefined1 *)(puVar4 + 1) = 1;
    puVar9 = (uint *)(*plVar5 + 8);
    uVar2 = *puVar9;
    uVar12 = (undefined1)uVar2;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar9,&RegisterRead,puVar11,(uint)puVar9 & 0xffff,uVar12);
    }
    lVar3 = *plVar5;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar9,&RegisterWrite,puVar11,(uint)(uint *)(lVar3 + 8) & 0xffff,uVar12);
    }
    *(uint *)(lVar3 + 8) = uVar2 | 0x80000000;
    LOCK();
    UNLOCK();
    if (*(char *)(lVar7 + 0x1d8) < '\0') {
      if ((char)plVar5[4] == '\x01') goto LAB_1c00062db;
      puVar11 = (undefined *)(ulonglong)*(uint *)(plVar5 + 3);
      uVar2 = *(uint *)(plVar5[2] + (longlong)puVar11 * 4);
      *(uint *)((longlong)plVar5 + 0x1c) = uVar2;
      *(uint *)(plVar5 + 3) = *(uint *)(plVar5 + 3) + 1 & 0x3ff;
      *(undefined1 *)(plVar5 + 4) = 1;
      lVar7 = *plVar5;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  ((ulonglong)uVar2,&RegisterWrite,puVar11,
                   (uint)(undefined4 *)(lVar7 + 0xc) & 0xffff,4);
      }
      *(undefined4 *)(lVar7 + 0xc) = 4;
      LOCK();
      UNLOCK();
    }
    (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
  }
LAB_1c00062db:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar11,0xf,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return uVar10;
}



===== SynopsysInterruptProgramEventBuffers @ 1c0006338 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysInterruptProgramEventBuffers(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint *puVar9;
  undefined8 uVar10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8
                     );
  uVar10 = DAT_1c001d600;
  plVar5 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar4);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals,*puVar4);
  plVar5[1] = lVar6;
  uVar8 = WdfDriverGlobals;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0xb0))(WdfDriverGlobals,*puVar4);
  lVar6 = *plVar5;
  uVar1 = *(undefined4 *)((longlong)plVar5 + 0xc);
  plVar5[2] = lVar7;
  *(undefined4 *)(plVar5 + 3) = 0;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (uVar8,&RegisterWrite,uVar10,(uint)(undefined4 *)(lVar6 + 4) & 0xffff,(char)uVar1);
  }
  *(undefined4 *)(lVar6 + 4) = uVar1;
  LOCK();
  UNLOCK();
  lVar6 = plVar5[1];
  puVar3 = (undefined4 *)*plVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar8,&RegisterWrite,uVar10,(uint)puVar3 & 0xffff,(char)lVar6);
  }
  *puVar3 = (int)lVar6;
  LOCK();
  UNLOCK();
  puVar9 = (uint *)(*plVar5 + 8);
  uVar2 = *puVar9;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar9,&RegisterRead,uVar10,(uint)puVar9 & 0xffff,(char)uVar2);
  }
  lVar6 = *plVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar9,&RegisterWrite,uVar10,(uint)(uint *)(lVar6 + 8) & 0xffff,0);
  }
  *(uint *)(lVar6 + 8) = uVar2 & 0x7fff0000 | 0x1000;
  LOCK();
  UNLOCK();
  puVar9 = (uint *)(*plVar5 + 0xc);
  uVar2 = *puVar9;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar9,&RegisterRead,uVar10,(uint)puVar9 & 0xffff,(char)uVar2);
  }
  lVar6 = *plVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar9,&RegisterWrite,uVar10,(uint)(uint *)(lVar6 + 0xc) & 0xffff,0);
  }
  *(uint *)(lVar6 + 0xc) = uVar2 & 0xffff0000;
  LOCK();
  UNLOCK();
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar10,0x1b,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return;
}



===== SynopsysInterruptWatchdogTimer @ 1c0006580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysInterruptWatchdogTimer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x10,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar4 = PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 8));
  if (*(int *)(lVar2 + 0x238) != 0) {
    if (*(char *)(lVar3 + 8) == '\x01') {
      *(undefined1 *)(lVar3 + 8) = 0;
      puVar4 = (undefined *)0xffffffffff676980;
      (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x248));
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),4,puVar4,0x11,
                         &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
      }
      puVar4 = (undefined *)0x2;
      DbgkWerCaptureLiveKernelDump(L"UFXSYNOPSYS",0x198,2,0,0,0,0,LiveDumpSecondaryCallback,1);
      *(undefined1 *)(lVar2 + 0x251) = 1;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x12,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return;
}



===== SynopsysAttachAbortOperation @ 1c000672c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAttachAbortOperation(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  code *pcVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  pcVar2 = *(code **)(WdfFunctions_01015 + 0xbe0);
  (*pcVar2)(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x160));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar2,0x22,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return;
}



===== SynopsysAttachInterfaceSetDeviceState @ 1c0006808 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAttachInterfaceSetDeviceState(undefined8 param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1f,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  puVar2 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(code **)(lVar1 + 0x150) != (code *)0x0) &&
     ((((param_2 == 2 || (param_2 == 4)) || (param_2 == 5)) || (param_2 == 6)))) {
    puVar2 = (undefined *)(ulonglong)*(uint *)(lVar1 + 0x6c);
    (**(code **)(lVar1 + 0x150))(*(undefined8 *)(lVar1 + 0x128),param_2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x20,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return;
}



===== SynopsysAcpiNotificationEnabled @ 1c0006908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiNotificationEnabled(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3b,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar2 + 0x22b) != '\0') {
    puVar3 = (undefined *)0x1;
    iVar1 = SynopsysAcpiEvaluateDsmMethod
                      (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,5,(undefined4 *)0x0,0,
                       &local_28);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,0x3c,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x3d,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiNotifyCallback @ 1c0006a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAcpiNotifyCallback(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x25,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (param_2 == 0x80) {
    *(undefined1 *)(puVar3 + 0xd) = 0;
    *(undefined1 *)((longlong)puVar3 + 0x6b) = 0;
    if (*(char *)(puVar3 + 0x4c) == '\0') {
      if (*(char *)(puVar3 + 0xb) != '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(puVar3[0x4b],4,puVar4,0x26,
                           &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
        }
        (*DAT_1c001de88)(UfxGlobals,*puVar3);
      }
      *(undefined1 *)((longlong)puVar3 + 0x59) = 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar3[0x4b],4,puVar4,0x27,&WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar3[0xc]);
    if ((*(char *)(puVar3 + 0x45) == '\0') &&
       ((*DAT_1c001de80)(UfxGlobals,*puVar3), *(char *)(puVar3 + 0x4c) == '\0')) {
      *(undefined1 *)(puVar3 + 0xb) = 1;
    }
  }
  else {
    if (param_2 != 0x81) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_(puVar3[0x4b],2,puVar4,0x29,&WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
      goto LAB_1c0006c99;
    }
    if (*(char *)(puVar3 + 0x4c) == '\x01') goto LAB_1c0006c99;
    *(undefined1 *)((longlong)puVar3 + 0x59) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar3[0xc]);
    if (*(char *)(puVar3 + 0xb) != '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(puVar3[0x4b],4,puVar4,0x28,&WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids
                        );
      }
      pcVar2 = DAT_1c001de88;
      uVar1 = UfxGlobals;
      *(undefined1 *)(puVar3 + 0xd) = 0;
      *(undefined1 *)((longlong)puVar3 + 0x6b) = 0;
      (*pcVar2)(uVar1,*puVar3);
      *(undefined1 *)(puVar3 + 0xb) = 0;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar3[0xc]);
LAB_1c0006c99:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x2a,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiSetPmuState @ 1c0006ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiSetPmuState(undefined8 param_1,char param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_88 [32];
  uint local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x38,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  uVar2 = 1;
  local_48[0] = ~-(uint)(param_2 != '\0') & 3;
  iVar1 = SynopsysAcpiEvaluateDsmMethod
                    (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,4,local_48,1,&local_40);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0x39,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar2,0x3a,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiSoftCoreReset @ 1c0006e48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiSoftCoreReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3e,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  uVar2 = 1;
  iVar1 = SynopsysAcpiEvaluateDsmMethod
                    (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,6,(undefined4 *)0x0,0,
                     &local_28);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0x3f,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar2,0x40,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiUnregisterForNotification @ 1c0006f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAcpiUnregisterForNotification(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2e,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  puVar2 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar1 + 0x1ca) == '\x01') {
    (**(code **)(lVar1 + 0x1c0))(*(undefined8 *)(lVar1 + 0x178));
    (**(code **)(lVar1 + 0x188))(*(undefined8 *)(lVar1 + 0x178));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x2f,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== ProprietaryChargerCreateWorkItem @ 1c0007074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ProprietaryChargerCreateWorkItem
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 local_res10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined *local_30;
  
  local_30 = PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0;
  local_res10 = 0;
  puVar4 = &local_60;
  local_78 = 0x18;
  local_68 = 1;
  local_5c = 0;
  uStack_54 = 0;
  local_4c = 0;
  local_38 = 0;
  local_60 = 0x38;
  local_48 = 1;
  local_44 = 1;
  uStack_70 = param_3;
  local_40 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_78,puVar4,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x1e,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
    uVar3 = 0;
  }
  else {
    puVar4 = (undefined4 *)PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0;
    puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_res10);
    *puVar2 = param_1;
    uVar3 = local_res10;
  }
  *param_4 = uVar3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x1f,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return iVar1;
}



===== ProprietaryChargerEnqueueAbortOperation @ 1c00071f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerEnqueueAbortOperation
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar1);
  if (0 < *(int *)(lVar2 + 0x11c)) {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0xf8));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x1b,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerReleaseInterface @ 1c0007304 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerReleaseInterface(void *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  if (*(code **)((longlong)param_1 + 0x18) != (code *)0x0) {
    (**(code **)((longlong)param_1 + 0x18))(*(undefined8 *)((longlong)param_1 + 8));
  }
  uVar1 = 0x40;
  memset(param_1,0,0x40);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar1,0xb,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerResetOperationWorkItem @ 1c00073c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerResetOperationWorkItem
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined *puVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x30,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar2,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar6 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar3);
  uVar1 = (**(code **)(lVar4 + 0xe0))(*(undefined8 *)(lVar4 + 0xb0));
  uVar5 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x31,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)uVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  (*DAT_1c001de70)(UfxGlobals,*puVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar5,0x32,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerTryBeginOperation @ 1c0007554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ProprietaryChargerTryBeginOperation(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x20,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
  LOCK();
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  cVar1 = *(char *)(param_1 + 0x59);
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  if (cVar1 == '\0') {
    LOCK();
    *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
    UNLOCK();
    uVar2 = 0xc000009d;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x60));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return uVar2;
}



===== EvtDisconnectTimer @ 1c0007690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtDisconnectTimer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined *puVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x16,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,puVar4[0xc]);
  puVar5 = (uint *)(puVar4[9] + 0xc);
  uVar6 = *puVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,puVar7,(uint)puVar5 & 0xffff,(char)uVar6);
  }
  cVar1 = *(char *)((longlong)puVar4 + 0x69);
  cVar2 = *(char *)((longlong)puVar4 + 0x6a);
  *(undefined1 *)((longlong)puVar4 + 0x69) = 0;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,puVar4[0xc]);
  if (cVar1 != '\0') {
    uVar6 = uVar6 >> 0x16 & 1;
    if ((cVar2 == '\0') || (uVar6 != 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(puVar4[0x4b],4,puVar7,0x17,
                          &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)uVar6);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar4[0x4b],2,puVar7,0x18,&WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
    puVar7 = (undefined *)0x0;
    (*DAT_1c001de70)(UfxGlobals,*puVar4);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x19,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDeviceSetRunStop @ 1c0007868 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDeviceSetRunStop(undefined8 param_1,char param_2,undefined8 param_3)

{
  uint uVar1;
  bool bVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint *puVar5;
  uint uVar6;
  undefined *puVar7;
  bool bVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar3);
  bVar2 = true;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x60));
  puVar5 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
  uVar1 = *puVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,puVar7,(uint)puVar5 & 0xffff,(char)uVar1);
  }
  bVar8 = param_2 != '\0';
  if (bVar8) {
    *(undefined2 *)(lVar4 + 0x6a) = 0;
  }
  *(bool *)(lVar4 + 0x250) = bVar8;
  if ((uint)bVar8 != -((int)uVar1 >> 0x1f)) {
    uVar6 = (uint)CONCAT11(bVar8,bVar8) << 0x17 | uVar1 & 0x7f7fffff;
    puVar5 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                ((ulonglong)bVar8,&RegisterWrite,puVar7,(uint)puVar5 & 0xffff,
                 (char)(uVar1 & 0x7f7fffff));
    }
    *puVar5 = uVar6;
    LOCK();
    UNLOCK();
    if (-1 < (int)uVar6) {
      puVar5 = (uint *)(*(longlong *)(lVar4 + 0x48) + 0xc);
      uVar1 = *puVar5;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar5,&RegisterRead,puVar7,(uint)puVar5 & 0xffff,(char)uVar1);
      }
      if ((uVar1 >> 0x16 & 1) == 0) {
        bVar2 = false;
        *(undefined1 *)(lVar4 + 0x69) = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 600),4,puVar7,0x1b,
                           &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
        }
        puVar7 = (undefined *)0xfffffffffeced300;
        (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,puVar3[0x25]);
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x60));
  if ((bVar2) && ((char)param_3 != '\0')) {
    puVar7 = (undefined *)0x0;
    (*DAT_1c001de70)(UfxGlobals,param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x1c,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtCleanupCallback @ 1c0007b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtCleanupCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x14,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar4 = PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628;
  puVar1 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(puVar1 + 0x26) != '\0') {
    uVar3 = *puVar1;
    puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (*(longlong *)(lVar2 + 200) != 0) {
      ProprietaryChargerReleaseInterface((void *)(lVar2 + 0xa8),uVar3,puVar4);
    }
  }
  DAT_1c001df18 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x15,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceAddressed @ 1c0007c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceAddressed(undefined8 param_1,ushort param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined *puVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  uVar4 = WdfDriverGlobals;
  puVar6 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  uVar5 = **(uint **)(lVar3 + 0x48);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (uVar4,&RegisterRead,puVar6,(uint)*(uint **)(lVar3 + 0x48) & 0xffff,(char)uVar5);
  }
  uVar5 = ((uint)param_2 << 3 ^ uVar5) & 0x3f8 ^ uVar5;
  puVar1 = *(uint **)(lVar3 + 0x48);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar4,&RegisterWrite,puVar6,(uint)puVar1 & 0xffff,(char)uVar5);
  }
  *puVar1 = uVar5;
  LOCK();
  UNLOCK();
  uVar4 = 0;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x22,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceEndpointAdd @ 1c0007d80 =====

int UfxDevice_EvtDeviceEndpointAdd(undefined8 param_1,undefined4 *param_2,undefined *param_3)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x23,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  iVar1 = UfxEndpointAdd(param_1,param_2,param_3);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x24,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x25,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return iVar1;
}



===== UfxDevice_EvtDeviceHostConnect @ 1c0007e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceHostConnect(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1d,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar3);
  uVar8 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x1d0));
  pcVar1 = (char *)(lVar4 + 0x1cc);
  uVar5 = *(undefined8 *)(lVar4 + 0x1d0);
  if (*(char *)(lVar4 + 0x23e) == '\x01') {
    *(undefined1 *)(lVar4 + 0x23e) = 0;
    *pcVar1 = '\x01';
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    SynopsysDeviceVendorReset(*puVar3,uVar5,uVar8);
    SynopsysDevicePerformSoftReset(*puVar3,uVar5,uVar8);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
  }
  puVar9 = (undefined *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x1d0));
  if (*pcVar1 == '\x01') {
    uVar7 = 0;
    while( true ) {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,puVar3[1]);
      if (uVar2 <= uVar7) break;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,puVar3[1],uVar7);
      puVar9 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar5);
      uVar7 = uVar7 + 1;
      *(undefined2 *)(lVar6 + 0x38) = 0;
    }
    uVar5 = *(undefined8 *)(lVar4 + 0x1d0);
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
    SynopsysDeviceInitializeDefaultEndpoint(*puVar3,uVar5,puVar9);
    *pcVar1 = '\0';
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x1d0));
    UfxDeviceSetRunStop(param_1,'\x01',0);
  }
  uVar5 = 0;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar5,0x1e,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceHostDisconnect @ 1c0008120 =====

void UfxDevice_EvtDeviceHostDisconnect(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar1 = (undefined1)param_3;
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1f,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  UfxDevice_Reset(param_1,param_2,CONCAT71(uVar2,uVar1));
  uVar1 = 1;
  UfxDeviceSetRunStop(param_1,'\0',CONCAT71(uVar2,1));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,CONCAT71(uVar2,uVar1),0x20,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDevicePortDetect @ 1c00081d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDevicePortDetect(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  uVar3 = *puVar1;
  pcVar5 = WdfFunctions_01015;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar3,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar4 = 1;
  if (*(char *)(puVar2 + 0x39) == '\x01') {
    SynopsysAcpiGetPortType(*puVar1,uVar3,1);
  }
  else if (puVar2[0x28] == 0) {
    if ((*(byte *)(puVar2 + 0x3b) & 1) == 0) {
      if ((puVar2[3] != 0) || (*(char *)((longlong)puVar2 + 0x1ca) != '\0')) {
        uVar4 = 0;
      }
      (*DAT_1c001dea8)(UfxGlobals,*puVar2,uVar4);
    }
    else {
      SmfEnqueueEventCommon(puVar2[10],1,(char *)0x1,pcVar5);
    }
  }
  else {
    SynopsysAttachInterfaceEnqueueGetAttachAction(param_1,0,1);
  }
  return;
}



===== UfxDevice_EvtDeviceProprietaryChargerReset @ 1c00082b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceProprietaryChargerReset
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined *puVar3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x49,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1c,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar1);
  if (*(longlong *)(lVar2 + 0xe0) == 0) {
    puVar3 = (undefined *)0x0;
    (*DAT_1c001de70)(UfxGlobals,param_1);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x100));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x1d,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x4a,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
  }
  return;
}



===== UfxDevice_EvtDeviceSuperSpeedPowerFeature @ 1c0008450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceSuperSpeedPowerFeature(undefined8 param_1,short param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x43,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  uVar5 = WdfDriverGlobals;
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  if ((*(byte *)(lVar3 + 0x1d8) & 0x10) != 0) goto LAB_1c0008590;
  puVar6 = (uint *)(*(longlong *)(lVar3 + 0x48) + 4);
  uVar1 = *puVar6;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar5,&RegisterRead,puVar7,(uint)puVar6 & 0xffff,(char)uVar1);
  }
  if (param_2 == 0x30) {
    uVar4 = -(uint)((char)param_3 != '\0') & 0x400;
    uVar1 = uVar1 & 0xfffffbff;
LAB_1c0008560:
    uVar5 = (ulonglong)uVar4;
    uVar1 = uVar4 | uVar1;
  }
  else if (param_2 == 0x31) {
    uVar4 = -(uint)((char)param_3 != '\0') & 0x1000;
    uVar1 = uVar1 & 0xffffefff;
    goto LAB_1c0008560;
  }
  puVar6 = (uint *)(*(longlong *)(lVar3 + 0x48) + 4);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar5,&RegisterWrite,puVar7,(uint)puVar6 & 0xffff,(char)uVar1);
  }
  *puVar6 = uVar1;
  LOCK();
  UNLOCK();
LAB_1c0008590:
  uVar8 = 0;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar8,0x44,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceTestModeSet @ 1c0008600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceTestModeSet(undefined8 param_1,uint param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined *puVar6;
  ulonglong uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3f,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar6 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar1);
  uVar4 = 0xc0000001;
  if (param_2 < 6) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 600),4,puVar6,0x41,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)param_2);
    }
    puVar3 = (uint *)(*(longlong *)(lVar2 + 0x48) + 4);
    uVar4 = *puVar3;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar3,&RegisterRead,puVar6,(uint)puVar3 & 0xffff,(char)uVar4)
      ;
    }
    puVar5 = (uint *)(*(longlong *)(lVar2 + 0x48) + 4);
    uVar4 = (param_2 * 2 ^ uVar4) & 0x1e ^ uVar4;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar3,&RegisterWrite,puVar6,(uint)puVar5 & 0xffff,(char)uVar4);
    }
    *puVar5 = uVar4;
    LOCK();
    UNLOCK();
    uVar4 = 0;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 600),2,puVar6,0x40,
                      &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)param_2);
  }
  uVar7 = (ulonglong)uVar4;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0x42,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_Reset @ 1c00087d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_Reset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x31,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar8 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  uVar5 = puVar2[1];
  puVar7 = (undefined4 *)(*(longlong *)(lVar3 + 0x18) + 0x620);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals);
  SynopsysTransferReset(uVar4,uVar5,puVar8);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(uVar4,&RegisterWrite,puVar8,(uint)puVar7 & 0xffff,3);
  }
  *puVar7 = 3;
  LOCK();
  UNLOCK();
  uVar6 = 1;
  while( true ) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,puVar2[1]);
    if (uVar1 <= uVar6) break;
    puVar8 = (undefined *)(ulonglong)uVar6;
    uVar5 = puVar2[1];
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals);
    SynopsysTransferReset(uVar4,uVar5,puVar8);
    uVar6 = uVar6 + 1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,0x32,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_StartConfiguration @ 1c0008970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_StartConfiguration(undefined8 param_1,char param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x33,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  lVar2 = *(longlong *)(lVar2 + 0x18);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,puVar1[1]);
  uVar4 = (ulonglong)((-(uint)(param_2 != '\0') & 0xfffe0000) + 0x20009);
  UfxEndpointCommand(uVar3,(undefined4 *)(lVar2 + 0x700),uVar4,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x34,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_dL @ 1c0008aa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== EndpointQueue_EvtIoStop @ 1c0008b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EndpointQueue_EvtIoStop(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined *puVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1d,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728);
  uVar1 = *puVar3;
  puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
  uVar6 = param_2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dqDqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
      uVar6 = (ulonglong)*(uint *)(lVar4 + 0x20);
      WPP_RECORDER_SF_qDqD(*(undefined8 *)(lVar5 + 0x40));
    }
    TransferLock(uVar1);
    SynopsysTransferRequestCancel(param_2,uVar6,puVar7);
    TransferUnlock(uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x20,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== EvtEndpointCommandQueue @ 1c0008d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtEndpointCommandQueue
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  char *local_28 [2];
  
  local_28[0] = (char *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  uVar5 = 0;
  uVar4 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0,local_28,0);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x22,
                        &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)uVar1);
    }
joined_r0x0001c0008ef2:
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
LAB_1c0008f0c:
    uVar5 = (ulonglong)uVar1;
  }
  else {
    if (param_5 == 0x2ac026) {
      SynopsysTransferGetStall(*puVar2,local_28[0],uVar5);
    }
    else {
      if (param_5 == 0x2ac029) {
        if (*local_28[0] == '\0') {
          *(undefined8 *)(lVar3 + 0x30) = param_2;
          SynopsysTransferCommandStallClear(*puVar2,uVar4,uVar5);
        }
        else {
          *(undefined8 *)(lVar3 + 0x28) = param_2;
          SynopsysTransferCommandStallSet(*puVar2,uVar4,uVar5);
        }
        goto LAB_1c0008f64;
      }
      if (param_5 != 0x2ac401) {
        uVar1 = 0xc0000010;
        goto LAB_1c0008f0c;
      }
      uVar4 = UfxEndpointDescriptorUpdate(*puVar2,(undefined4 *)local_28[0],uVar5);
      uVar1 = (uint)uVar4;
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x23,
                            &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)uVar4);
        }
        goto joined_r0x0001c0008ef2;
      }
    }
    uVar5 = 0;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2);
LAB_1c0008f64:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar5,0x24,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== McTemplateK0spqqqqq_EtwWriteTransfer @ 1c0008fb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0spqqqqq_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_R9;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [4];
  undefined8 local_98 [2];
  char *local_88;
  int local_80;
  undefined4 local_7c;
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
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a8[0] = 0;
  if (in_R9 == (char *)0x0) {
    local_80 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != '\0');
    local_80 = (int)lVar1 + 1;
  }
  local_7c = 0;
  local_78 = &uStack0000000000000028;
  local_60 = 4;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_50 = 4;
  local_68 = &uStack0000000000000030;
  local_58 = &uStack0000000000000038;
  local_40 = 4;
  local_48 = &uStack0000000000000040;
  local_30 = 4;
  local_38 = &uStack0000000000000048;
  local_70 = 8;
  local_28 = local_a8;
  local_20 = 4;
  local_88 = in_R9;
  McGenEventWrite_EtwWriteTransfer
            (&UfxSynopsysGuid_Context,&EndpointCommand,&UfxSynopsysGuid,8,local_98);
  return;
}



===== UfxEndpointAdd @ 1c00090b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int UfxEndpointAdd(undefined8 param_1,undefined4 *param_2,undefined *param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 auStackY_248 [32];
  undefined4 local_1f0 [2];
  undefined8 local_1e8;
  ulonglong local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined *local_1b0;
  ulonglong local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined *local_178;
  ulonglong local_170;
  code *local_168;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined *local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_12c;
  code *local_100;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  code *local_a8;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_248;
  local_170 = (ulonglong)(uint)local_170;
  local_1e8 = 0;
  local_1a8 = (ulonglong)(uint)local_1a8;
  local_1e0 = (ulonglong)(uint)local_1e0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,*puVar4,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  puVar1 = PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728;
  local_198 = 0;
  local_140 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  local_154 = 1;
  local_158 = 2;
  uStack_1a0 = 0;
  local_1a8 = 0x38;
  uStack_190 = 0x100000002;
  local_170 = 0x38;
  local_160 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_168 = UfxEndpoint_Cleanup;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728;
  memset(&local_138,0,0x60);
  local_138 = 0x60;
  local_134 = 3;
  local_1d0 = 0;
  local_130 = 2;
  uStack_1d8 = 0;
  local_12c = 1;
  local_100 = EndpointQueue_EvtIoStop;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_1e0 = 0x38;
  uStack_1c8 = 0x100000002;
  local_1b0 = puVar1;
  memset(&local_d8,0,0x60);
  local_d8 = 0x60;
  local_a8 = EvtEndpointCommandQueue;
  local_d0 = 2;
  local_d4 = 1;
  local_1f0[0] = 4;
  (*DAT_1c001ded8)(UfxGlobals,param_3,local_1f0);
  iVar3 = (*DAT_1c001ded0)(UfxGlobals,param_1,param_3,&local_170);
  if (iVar3 < 0) {
    pcVar7 = (code *)param_3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0xb,
                        &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)iVar3);
      pcVar7 = (code *)param_3;
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals,puVar4[1],0);
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,0,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    puVar5[1] = param_1;
    *puVar5 = *puVar4;
    *(undefined2 *)(puVar5 + 7) = 0;
    *(undefined4 *)(puVar5 + 2) = *param_2;
    *(undefined2 *)((longlong)puVar5 + 0x14) = *(undefined2 *)(param_2 + 1);
    *(undefined1 *)((longlong)puVar5 + 0x16) = *(undefined1 *)((longlong)param_2 + 6);
    local_78 = 0x38;
    local_58 = local_58 & 0xffffffffffffff00;
    uStack_60 = CONCAT44(0x10,(undefined4)uStack_60);
    local_68 = 0;
    uStack_60 = uStack_60 & 0xffffffffffffff00;
    uStack_70 = 0x40000002000;
    local_48 = 0x200000001;
    RtlStringCchPrintfA((char *)&local_58,0x10,"EP %.2X",(ulonglong)*(byte *)((longlong)param_2 + 2)
                       );
    iVar3 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_78,&local_1e8);
    if (iVar3 < 0) {
      uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    }
    else {
      uVar6 = local_1e8;
    }
    uVar2 = UfxGlobals;
    puVar5[8] = uVar6;
    uVar6 = (*DAT_1c001dee8)(uVar2,0);
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,uVar6,PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728);
    *puVar5 = 0;
    uVar6 = (*DAT_1c001def0)(UfxGlobals,0);
    pcVar7 = (code *)PTR__WDF_ENDPOINT_QUEUE_CONTEXT_TYPE_INFO_1c001d728;
    puVar5 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    *puVar5 = 0;
    iVar3 = SynopsysTransferInitialize(0,uVar6,pcVar7);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar7,0xc,
                          &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)iVar3);
      }
    }
    else {
      if (*(int *)(puVar4 + 0x23) == 5) {
        UfxEndpointConfigure(0,uVar6,pcVar7);
      }
      uVar6 = (*DAT_1c001dee8)(UfxGlobals,0);
      pcVar7 = SynopsysTransferReadyNotify;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x530))
                        (WdfDriverGlobals,uVar6,SynopsysTransferReadyNotify,0);
      if (-1 < iVar3) goto LAB_1c0009623;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar7,0xd,
                          &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)iVar3);
      }
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0009623:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar7,0xe,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return iVar3;
}



===== UfxEndpointCommand @ 1c0009684 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxEndpointCommand(undefined8 param_1,undefined4 *param_2,undefined8 param_3,undefined4 param_4
                       ,undefined4 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined **ppuVar8;
  uint uVar9;
  undefined *puVar10;
  uint *puVar11;
  byte bVar12;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xf,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  uVar6 = WdfDriverGlobals;
  puVar10 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (((*(byte *)(lVar5 + 0x13) & 3) == 0) && (param_2 == (undefined4 *)(puVar2[3] + 0x10))) {
    if (*(char *)((longlong)puVar2 + 0x39) != '\0') {
      do {
        uVar9 = param_2[3];
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (uVar6,&RegisterRead,puVar10,(uint)(param_2 + 3) & 0xffff,(char)uVar9);
        }
      } while ((uVar9 & 0x400) != 0);
    }
    *(undefined1 *)((longlong)puVar2 + 0x39) = 1;
  }
  else {
    if (*(char *)(puVar2 + 7) != '\0') {
      do {
        uVar9 = param_2[3];
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (uVar6,&RegisterRead,puVar10,(uint)(param_2 + 3) & 0xffff,(char)uVar9);
        }
      } while ((uVar9 & 0x400) != 0);
    }
    *(undefined1 *)(puVar2 + 7) = 1;
  }
  uVar9 = (uint)param_3 | 0x400;
  if (*(char *)(lVar3 + 0x250) == '\x01') {
    uVar9 = (uint)param_3 | 0x500;
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x230));
    *(int *)(lVar3 + 0x238) = *(int *)(lVar3 + 0x238) + 1;
    if (*(int *)(lVar3 + 0x238) == 1) {
      if (*(char *)(lVar3 + 0x23c) == '\x01') {
        puVar7 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x100);
        uVar1 = *puVar7;
        bVar12 = (byte)uVar1;
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer(puVar7,&RegisterRead,puVar10,(uint)puVar7 & 0xffff,bVar12)
          ;
        }
        puVar11 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x100);
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (puVar7,&RegisterWrite,puVar10,(uint)puVar11 & 0xffff,bVar12 & 0xbf);
        }
        *puVar11 = uVar1 & 0xffffffbf;
        LOCK();
        UNLOCK();
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x230));
      puVar10 = PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 8))
      ;
      *(undefined1 *)(lVar4 + 8) = 0;
      if (*(char *)(lVar3 + 0x251) == '\0') {
        puVar10 = (undefined *)0xffffffffff676980;
        (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x248));
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x230));
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqDDDD(puVar2[8]);
  }
  ppuVar8 = &PTR_s_Reserved_1c0019000;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
    McTemplateK0spqqqqq_EtwWriteTransfer();
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (ppuVar8,&RegisterWrite,puVar10,(uint)(param_2 + 2) & 0xffff,(char)param_4);
  }
  param_2[2] = param_4;
  LOCK();
  UNLOCK();
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (ppuVar8,&RegisterWrite,puVar10,(uint)(param_2 + 1) & 0xffff,(char)param_5);
  }
  param_2[1] = param_5;
  LOCK();
  UNLOCK();
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(ppuVar8,&RegisterWrite,puVar10,(uint)param_2 & 0xffff,0);
  }
  *param_2 = 0;
  LOCK();
  UNLOCK();
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (ppuVar8,&RegisterWrite,puVar10,(uint)(param_2 + 3) & 0xffff,(char)uVar9);
  }
  param_2[3] = uVar9;
  LOCK();
  UNLOCK();
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar10,0x11,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== UfxEndpointConfigure @ 1c0009b20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxEndpointConfigure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined *puVar7;
  uint uVar8;
  uint *puVar9;
  undefined *puVar10;
  uint uVar11;
  bool bVar12;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x16,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  uVar11 = 1 << ((byte)*(undefined4 *)(puVar2 + 4) & 0x1f);
  uVar6 = param_1;
  puVar10 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(byte *)(lVar4 + 0x13) & 3) == 0) {
    uVar11 = uVar11 | 1 << ((char)*(undefined4 *)(puVar2 + 4) + 1U & 0x1f);
  }
  bVar1 = *(byte *)((longlong)puVar2 + 0x12);
  bVar12 = (bVar1 & 0xf) == 0;
  puVar7 = (undefined *)CONCAT71((int7)((ulonglong)uVar6 >> 8),bVar12);
  UfxEndpointConfigureHardware(param_1,bVar12,puVar10);
  if ((bVar1 & 0xf) == 0) {
    puVar7 = (undefined *)0x0;
    UfxDevice_StartConfiguration(puVar2[1],'\0',puVar10);
  }
  puVar5 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x620);
  uVar8 = *puVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar7 = &RegisterRead;
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,puVar10,(uint)puVar5 & 0xffff,(char)uVar8);
  }
  uVar8 = uVar8 | uVar11;
  puVar9 = (uint *)(*(longlong *)(lVar3 + 0x18) + 0x620);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    puVar7 = &RegisterWrite;
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterWrite,puVar10,(uint)puVar9 & 0xffff,(char)uVar8)
    ;
  }
  *puVar9 = uVar8;
  LOCK();
  UNLOCK();
  if ((bVar1 & 0xf) != 0) {
    SynopsysTransferStart(param_1,puVar7,puVar10);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar10,0x17,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== UfxEndpointConfigureHardware @ 1c0009cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxEndpointConfigureHardware(undefined8 param_1,char param_2,undefined8 param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined *puVar11;
  uint uVar12;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x12,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar11 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dq(puVar4[8],4,puVar11,0x13,&WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,
                       (char)*(undefined4 *)(puVar4 + 4),(char)param_1);
  }
  puVar2 = (undefined4 *)puVar4[3];
  uVar12 = *(byte *)((longlong)puVar4 + 0x12) & 0xf;
  if (((*(byte *)((longlong)puVar4 + 0x12) & 0xf) != 0) || (uVar10 = 0x200, param_2 != '\0')) {
    uVar10 = (uint)*(ushort *)((longlong)puVar4 + 0x14);
  }
  uVar10 = (uVar10 & 0x7ff) << 3 | (uint)*(byte *)((longlong)puVar4 + 0x13) * 2 & 0xffc1c007;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((*(byte *)(lVar7 + 0x13) & 3) == 0) {
LAB_1c0009e74:
    uVar10 = uVar10 | uVar12 << 0x11;
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if (*(char *)(lVar7 + 0x12) < '\0') goto LAB_1c0009e74;
  }
  if (*(int *)(lVar5 + 0x6c) == 3) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((*(byte *)(lVar7 + 0x13) & 3) == 2) {
      uVar9 = WdfDriverGlobals;
      puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      if ((*(byte *)(lVar7 + 0x13) & 3) == 0) {
LAB_1c0009f13:
        if (*(char *)(lVar5 + 0x275) != '\0') goto LAB_1c0009f91;
        puVar1 = (uint *)(*(longlong *)(lVar6 + 0x18) + 0x200 + (ulonglong)uVar12 * 4);
        uVar3 = *puVar1;
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          McTemplateK0qq_EtwWriteTransfer
                    (uVar9,&RegisterRead,puVar11,(uint)puVar1 & 0xffff,(char)uVar3);
        }
        uVar3 = ((uVar3 & 0xffff) * *(int *)(lVar5 + 0x270)) / (uVar10 >> 3 & 0x7ff);
        if (0xf < uVar3) {
          uVar3 = 0x10;
        }
        uVar8 = uVar3 - 1;
        if (uVar3 == 0) {
          uVar8 = 0;
        }
        uVar10 = uVar10 | (uVar8 & 0xf) << 0x16;
      }
      else {
        uVar9 = WdfDriverGlobals;
        puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
        lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
        if (*(char *)(lVar7 + 0x12) < '\0') goto LAB_1c0009f13;
LAB_1c0009f91:
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8
                          );
        if ((*(byte *)(lVar6 + 0x13) & 3) != 0) {
          lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
          if (((-1 < *(char *)(lVar6 + 0x12)) && (*(char *)(lVar5 + 0x274) == '\0')) &&
             (*(int *)(lVar5 + 0x26c) != 0)) {
            uVar10 = uVar10 | (*(int *)(lVar5 + 0x26c) - 1U & 0xf) << 0x16;
          }
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dDq(puVar4[8]);
      }
    }
  }
  uVar10 = uVar10 | -(uint)(param_2 != '\0') & 0x80000000;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((*(byte *)((longlong)puVar4 + 0x16) == 0) || (*(int *)(lVar5 + 0x6c) == 1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(byte *)((longlong)puVar4 + 0x16) - 1;
  }
  uVar12 = (uVar3 & 0xff | uVar12 << 10) << 0x10 |
           (-(uint)((*(byte *)(lVar6 + 0x13) & 3) != 0) & 0xfffffc00) + 0x700;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((*(byte *)(lVar5 + 0x13) & 3) == 0) {
    UfxEndpointCommand(param_1,puVar2,1,uVar10,uVar12);
    puVar11 = (undefined *)0x1;
    UfxEndpointCommand(param_1,puVar2 + 4,1,uVar10,uVar12 | 0x2000000);
    goto LAB_1c000a184;
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((*(byte *)(lVar5 + 0x13) & 3) == 0) {
LAB_1c000a165:
    uVar3 = 0;
  }
  else {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    uVar3 = 0x2000000;
    if (-1 < *(char *)(lVar5 + 0x12)) goto LAB_1c000a165;
  }
  puVar11 = (undefined *)0x1;
  UfxEndpointCommand(param_1,puVar2,1,uVar10,uVar12 | uVar3);
LAB_1c000a184:
  if (param_2 == '\0') {
    UfxEndpointCommand(param_1,puVar2,2,1,0);
    puVar11 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    if ((*(byte *)(lVar5 + 0x13) & 3) == 0) {
      puVar11 = (undefined *)0x2;
      UfxEndpointCommand(param_1,puVar2 + 4,2,1,0);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar11,0x15,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== UfxEndpointDescriptorUpdate @ 1c000a240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 UfxEndpointDescriptorUpdate(undefined8 param_1,undefined4 *param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x18,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  uVar2 = param_1;
  puVar3 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  *(undefined4 *)(lVar1 + 0x10) = *param_2;
  *(undefined2 *)(lVar1 + 0x14) = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)(lVar1 + 0x16) = *(undefined1 *)((longlong)param_2 + 6);
  if ((*(byte *)((longlong)param_2 + 2) & 0xf) == 0) {
    UfxEndpointConfigure(param_1,uVar2,puVar3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x19,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return 0;
}



===== UfxEndpoint_Cleanup @ 1c000a330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxEndpoint_Cleanup(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint *puVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 uVar12;
  undefined *puVar13;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar14;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar14 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,puVar2[1],PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar2,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar12 = param_1;
  (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,puVar3[1],param_1);
  uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),1);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                    (WdfDriverGlobals,*puVar3,uVar12,0,CONCAT44(uVar14,0x25d),
                     "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxendpoint.c");
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar12,0x1b,
                        &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x1d0));
    if (*(char *)(lVar6 + 0x23e) == '\0') {
      uVar9 = 1 << ((byte)*(undefined4 *)(puVar2 + 4) & 0x1f);
      puVar13 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      if ((*(byte *)(lVar5 + 0x13) & 3) == 0) {
        uVar9 = uVar9 | 1 << ((char)*(undefined4 *)(puVar2 + 4) + 1U & 0x1f);
      }
      puVar7 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x620);
      uVar10 = *puVar7;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar7,&RegisterRead,puVar13,(uint)puVar7 & 0xffff,(char)uVar10);
      }
      uVar10 = ~uVar9 & uVar10;
      puVar11 = (uint *)(*(longlong *)(lVar4 + 0x18) + 0x620);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer
                  (puVar7,&RegisterWrite,puVar13,(uint)puVar11 & 0xffff,(char)uVar10);
      }
      *puVar11 = uVar10;
      LOCK();
      UNLOCK();
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x1d0));
    uVar8 = *puVar3;
    uVar12 = 0;
    (**(code **)(WdfFunctions_01015 + 0xdb8))
              (WdfDriverGlobals,uVar8,0,0x270,
               "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxendpoint.c");
    SynopsysTransferDestroy(param_1,uVar8,uVar12);
    lVar4 = puVar2[8];
    lVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    if (lVar4 != lVar6) {
      imp_WppRecorderLogDelete(WPP_GLOBAL_Control,lVar4);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar12,0x1c,
                     &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_Dq @ 1c000a6a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,8
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_dDq @ 1c000a784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x14,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x14,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_dqDqd @ 1c000a878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dqDqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x1e,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x1e,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qDqD @ 1c000a9b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDqD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x1f,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x1f,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_sqDDDD @ 1c000aacc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqDDDD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x10,pcVar1,lVar3,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               local_18,4,&uStack0000000000000058,4,0);
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
  WppAutoLogTrace(param_1,4,1,&WPP_a128aa9db2233ec7c0f25bd437ba8b59_Traceguids,0x10,
                  in_stack_00000030,lVar2,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,local_18,4,&uStack0000000000000058,4,0);
  return;
}



===== McTemplateK0pqqqqqq_EtwWriteTransfer @ 1c000acc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pqqqqqq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88 = local_res20;
  local_70 = 4;
  local_78 = &uStack0000000000000028;
  local_60 = 4;
  local_68 = &uStack0000000000000030;
  local_50 = 4;
  local_58 = &uStack0000000000000038;
  local_40 = 4;
  local_48 = &uStack0000000000000040;
  local_80 = 8;
  local_38 = &uStack0000000000000048;
  local_28 = &uStack0000000000000050;
  local_30 = 4;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(&UfxSynopsysGuid_Context,&TrbLog,&UfxSynopsysGuid,8,local_98);
  return;
}



===== McTemplateK0spqppqqqqqqq_EtwWriteTransfer @ 1c000ad98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0spqppqqqqqqq_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_R9;
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 auStackY_118 [32];
  undefined8 local_e8 [2];
  char *local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (in_R9 == (char *)0x0) {
    local_d0 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != '\0');
    local_d0 = (int)lVar1 + 1;
  }
  local_cc = 0;
  local_c8 = &uStack0000000000000028;
  local_c0 = 8;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_b0 = 4;
  local_b8 = &uStack0000000000000030;
  local_a8 = &uStack0000000000000038;
  local_a0 = 8;
  local_98 = &uStack0000000000000040;
  local_90 = 8;
  local_88 = &uStack0000000000000048;
  local_80 = 4;
  local_78 = &uStack0000000000000050;
  local_68 = &uStack0000000000000058;
  local_58 = &uStack0000000000000060;
  local_48 = &uStack0000000000000068;
  local_38 = &uStack0000000000000070;
  local_28 = &uStack0000000000000078;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_d8 = in_R9;
  McGenEventWrite_EtwWriteTransfer(&UfxSynopsysGuid_Context,&Transfer,&UfxSynopsysGuid,0xd,local_e8)
  ;
  return;
}



===== SynopsysAddRequestToList @ 1c000aef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysAddRequestToList(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong *puVar8;
  undefined8 *local_res18 [2];
  ulonglong local_58 [6];
  undefined *local_28;
  
  local_res18[0] = (undefined8 *)0x0;
  local_58[0] = (ulonglong)(uint)local_58[0];
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  local_28 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
  puVar8 = local_58;
  local_58[2] = 0;
  local_58[1] = 0;
  local_58[0] = 0x38;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[3] = 0x100000001;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,puVar8,local_res18);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0x79,
                        &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar3);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    memset(local_res18[0],0,0x60);
    puVar2 = local_res18[0];
    local_res18[0][1] = param_2;
    *local_res18[0] = param_1;
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
    *(undefined4 *)(puVar2 + 6) = 0;
    lVar6 = lVar4 + 0x40;
    plVar7 = *(longlong **)(lVar4 + 0x48);
    plVar5 = local_res18[0] + 4;
    if (*plVar7 != lVar6) {
      lVar6 = 3;
      pcVar1 = (code *)swi(0x29);
      plVar5 = (longlong *)(*pcVar1)();
    }
    *plVar5 = lVar6;
    plVar5[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(lVar6 + 8) = plVar5;
    LOCK();
    *(int *)(lVar4 + 0x50) = *(int *)(lVar4 + 0x50) + 1;
    UNLOCK();
  }
  return iVar3;
}



===== SynopsysCancelAllRequestsForEndpoint @ 1c000b0b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysCancelAllRequestsForEndpoint(undefined8 param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  puVar6 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  puVar4 = *(undefined8 **)(lVar3 + 0x40);
  while (puVar1 = (undefined8 *)*puVar4, (undefined8 *)(lVar3 + 0x40) != puVar4) {
    iVar2 = *(int *)(puVar4 + 2);
    if (iVar2 == 0) {
      puVar6 = (undefined *)0xc0000120;
      SynopsysQueueRequestForCompletion(param_1,puVar4[-3],0xc0000120,0);
    }
    else if ((((iVar2 != 6) && (iVar2 != 7)) && (iVar2 != 8)) &&
            (((iVar2 != 9 && (iVar2 != 10)) && (iVar2 != 0xb)))) {
      uVar5 = puVar4[-3];
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x80,
                             &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2,
                             (char)iVar2);
        }
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
          McTemplateK0sqq_EtwWriteTransfer();
        }
      }
      else {
        SynopsysTransferRequestCancel(puVar4[-3],uVar5,puVar6);
      }
    }
    puVar4 = puVar1;
  }
  return;
}



===== SynopsysCompletionWorkItem @ 1c000b250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysCompletionWorkItem(undefined8 param_1)

{
  longlong ****pppplVar1;
  char cVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  longlong ****pppplVar5;
  code *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong ****pppplVar10;
  longlong lVar11;
  undefined1 *puVar12;
  longlong ****pppplVar13;
  undefined *puVar14;
  bool bVar15;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  char *in_stack_ffffffffffffff98;
  longlong ****local_48;
  longlong ****local_40;
  
  uVar7 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  local_res18 = uVar7;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar7,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar7,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  local_40 = (longlong ****)&local_48;
  local_48 = (longlong ****)&local_48;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x68));
  puVar12 = auStackY_88;
  pppplVar1 = (longlong ****)(lVar9 + 0x58);
  while (pppplVar13 = (longlong ****)*pppplVar1, pppplVar13 != pppplVar1) {
    pppplVar5 = (longlong ****)*pppplVar13;
    do {
      pppplVar10 = pppplVar13;
      ppplVar3 = *pppplVar10;
      if (((longlong ****)ppplVar3[1] != pppplVar10) ||
         (ppplVar4 = pppplVar10[1], (longlong ****)*ppplVar4 != pppplVar10)) goto LAB_1c000b574;
      *ppplVar4 = (longlong **)ppplVar3;
      ppplVar3[1] = (longlong **)ppplVar4;
      if ((longlong *****)*local_40 != &local_48) goto LAB_1c000b574;
      pppplVar10[1] = (longlong ***)local_40;
      *pppplVar10 = (longlong ***)&local_48;
      *local_40 = (longlong ***)pppplVar10;
      bVar15 = pppplVar1 != pppplVar5;
      pppplVar13 = pppplVar5;
      pppplVar5 = (longlong ****)*pppplVar5;
      local_40 = pppplVar10;
    } while (bVar15);
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x68));
    pppplVar13 = local_48;
    while (pppplVar5 = (longlong ****)*pppplVar13, &local_48 != (longlong *****)pppplVar13) {
      TRACE_TRANSFER("COMPLETE",uVar7,(longlong)pppplVar13[-3]);
      ppplVar3 = *pppplVar13;
      if (((longlong ****)ppplVar3[1] != pppplVar13) ||
         (ppplVar4 = pppplVar13[1], (longlong ****)*ppplVar4 != pppplVar13)) goto LAB_1c000b574;
      *ppplVar4 = (longlong **)ppplVar3;
      ppplVar3[1] = (longlong **)ppplVar4;
      cVar2 = *(char *)(pppplVar13 + -1);
      if (pppplVar13[-2] != (longlong ***)0x0) {
        puVar14 = PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588;
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
        if (*(uint *)(lVar11 + 0x10) < (uint)(*(int *)(lVar11 + 0x14) - *(int *)(lVar11 + 0x44))) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_LL(*(undefined8 *)(lVar8 + 0x40));
          }
          pppplVar13[4] = (longlong ***)(ulonglong)*(uint *)(lVar11 + 0x10);
        }
        if (*(longlong *)(lVar11 + 0x28) != 0) {
          local_res10[0] = 0;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(lVar8 + 0x40),4,puVar14,0x82,in_stack_ffffffffffffff98
                              ,(char)pppplVar13[-2]);
          }
          *(undefined8 *)(lVar11 + 0x28) = 0;
          (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,pppplVar13[-2],0,local_res10);
        }
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pppplVar13[-2]);
        pppplVar13[-2] = (longlong ***)0x0;
      }
      if (*(int *)((longlong)pppplVar13 + 0x1c) < 0) {
        (**(code **)(WdfFunctions_01015 + 0x838))();
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x848))
                  (WdfDriverGlobals,pppplVar13[-3],*(int *)((longlong)pppplVar13 + 0x1c),
                   pppplVar13[4]);
      }
      if (cVar2 != '\0') {
        in_stack_ffffffffffffff98 =
             "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\transfer.c";
        (**(code **)(WdfFunctions_01015 + 0x670))(WdfDriverGlobals,pppplVar13[-3],0,0xf03);
      }
      pppplVar13 = pppplVar5;
      uVar7 = local_res18;
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar9 + 0x68));
  }
LAB_1c000b57b:
  uVar7 = *(undefined8 *)(lVar9 + 0x68);
  *(undefined1 *)(lVar9 + 0x84) = 0;
  pcVar6 = *(code **)(WdfFunctions_01015 + 0x9e8);
  *(undefined8 *)(puVar12 + -8) = 0x1c000b5a1;
  (*pcVar6)(WdfDriverGlobals,uVar7);
  return;
LAB_1c000b574:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar12 = auStackY_80;
  goto LAB_1c000b57b;
}



===== SynopsysEvtProgramDma @ 1c000b5c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SynopsysEvtProgramDma
          (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
          undefined8 param_5)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x31,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
  TransferLock(param_3);
  pcVar7 = (code *)PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38))
  ;
  *(undefined4 *)(lVar2 + 0x18) = 0;
  *(undefined4 *)(lVar2 + 0x44) = 0;
  *(undefined4 *)(lVar2 + 0x4c) = 0;
  if (*(int *)(puVar3 + 6) == 8) {
    uVar6 = *puVar3;
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
LAB_1c000b698:
    pcVar7 = (code *)PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
    lVar5 = (*pcVar4)(WdfDriverGlobals,uVar6);
    if ((*(longlong *)(lVar5 + 0x88) != 0) && (*(longlong *)(lVar5 + 0x88) == puVar3[1])) {
      *(undefined8 *)(lVar5 + 0x88) = 0;
    }
    *(undefined4 *)(puVar3 + 6) = 9;
    TransferCancelCleanup(param_3,*(longlong *)(lVar2 + 0x38),pcVar7);
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar7,0x32,
                          &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar1);
      }
    }
    else {
      pcVar7 = SynopsysEvtRequestCancel;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))
                        (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x38));
      if (iVar1 == -0x3ffffee0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar7,0x33,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x20);
        }
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
          McTemplateK0sqq_EtwWriteTransfer();
        }
        uVar6 = *puVar3;
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x650);
        goto LAB_1c000b698;
      }
      if (-1 < iVar1) {
        TRACE_TRANSFER("SG LIST ALLOCATED",param_3,*(longlong *)(lVar2 + 0x38));
        pcVar7 = (code *)PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
        (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar3);
        *(undefined4 *)(puVar3 + 6) = 2;
        *(undefined8 *)(lVar2 + 0x28) = param_5;
        *(undefined8 *)(lVar2 + 0x30) = 0;
        SynopsysProgramTransfers(param_3);
        goto LAB_1c000b884;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar7,0x34,
                          &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar1);
      }
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
LAB_1c000b884:
  uVar6 = TransferUnlock(param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar7,0x35,
                             &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
}



===== SynopsysEvtRequestCancel @ 1c000b8f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysEvtRequestCancel(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1c,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  TransferLock(*puVar1);
  uVar2 = *puVar1;
  lVar3 = param_1;
  TRACE_TRANSFER("CANCEL",uVar2,param_1);
  SynopsysTransferRequestCancel(param_1,uVar2,lVar3);
  TransferUnlock(*puVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,lVar3,0x1d,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysProgramTransfers @ 1c000b9dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysProgramTransfers(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  bool bVar3;
  char cVar4;
  longlong lVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined *puVar9;
  bool bVar10;
  
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  puVar9 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  bVar3 = false;
  puVar2 = *(undefined8 **)(lVar5 + 0x40);
  do {
    if ((((undefined8 *)(lVar5 + 0x40) == puVar2) || (*(char *)(lVar5 + 0x3a) == '\x01')) ||
       (iVar1 = *(int *)(puVar2 + 2), iVar1 == 1)) {
      return;
    }
    if (iVar1 == 2) {
      cVar4 = TransferProgram(param_1,puVar2[-3],puVar9);
      if (cVar4 != '\0') {
        uVar8 = puVar2[-4];
        pcVar6 = *(code **)(WdfFunctions_01015 + 0x650);
        if (!bVar3) goto LAB_1c000bb05;
        puVar9 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
        (*pcVar6)(WdfDriverGlobals,uVar8);
        *(undefined4 *)(puVar2 + 2) = 3;
      }
LAB_1c000bb3d:
      bVar10 = *(char *)((longlong)puVar2 + 0x31) == '\0';
LAB_1c000bb41:
      if (bVar10) {
        return;
      }
    }
    else {
      if (iVar1 == 3) {
        if (!bVar3) {
          uVar8 = puVar2[-4];
          pcVar6 = *(code **)(WdfFunctions_01015 + 0x650);
LAB_1c000bb05:
          bVar3 = true;
          lVar7 = (*pcVar6)(WdfDriverGlobals,uVar8,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
          *(undefined8 *)(lVar7 + 0x88) = puVar2[-3];
          puVar9 = (undefined *)puVar2[7];
          *(undefined4 *)(puVar2 + 2) = 4;
          TransferCommandStartOrUpdate(param_1,puVar2[-3],puVar9);
        }
        goto LAB_1c000bb3d;
      }
      if ((iVar1 != 4) && (iVar1 != 5)) {
        if (iVar1 == 6) {
          return;
        }
        bVar10 = iVar1 == 7;
        goto LAB_1c000bb41;
      }
      if (*(char *)((longlong)puVar2 + 0x31) == '\0') {
        return;
      }
      bVar3 = true;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== SynopsysQueueRequestForCompletion @ 1c000bb78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysQueueRequestForCompletion
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined *puVar8;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  puVar8 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (puVar6 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar5 + 0x40),3,puVar8,0x83,in_stack_ffffffffffffffd8,
                        (char)param_2);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,param_3,param_4);
    return;
  }
  if ((*(int *)(puVar6 + 6) == 10) &&
     (iVar4 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,puVar6[1]), iVar4 < 0)) {
    if (iVar4 != -0x3ffffee0) {
      return;
    }
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*puVar6,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
    if ((*(longlong *)(lVar5 + 0x88) != 0) && (*(longlong *)(lVar5 + 0x88) == puVar6[1])) {
      *(undefined8 *)(lVar5 + 0x88) = 0;
    }
    *(undefined4 *)(puVar6 + 6) = 0xb;
    return;
  }
  plVar1 = puVar6 + 4;
  *(undefined4 *)((longlong)puVar6 + 0x3c) = param_3;
  puVar6[8] = param_4;
  lVar5 = *plVar1;
  if ((*(longlong **)(lVar5 + 8) == plVar1) &&
     (plVar2 = (longlong *)puVar6[5], (longlong *)*plVar2 == plVar1)) {
    *plVar2 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar2;
    LOCK();
    *(int *)(lVar7 + 0x50) = *(int *)(lVar7 + 0x50) + -1;
    UNLOCK();
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x68));
    plVar2 = *(longlong **)(lVar7 + 0x60);
    if (*plVar2 == lVar7 + 0x58) {
      *plVar1 = lVar7 + 0x58;
      puVar6[5] = plVar2;
      *plVar2 = (longlong)plVar1;
      *(longlong **)(lVar7 + 0x60) = plVar1;
      if (*(char *)(lVar7 + 0x84) == '\0') {
        *(undefined1 *)(lVar7 + 0x84) = 1;
        (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x78));
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x68));
      return;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== SynopsysRequestDispatch @ 1c000bdc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysRequestDispatch(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  undefined2 uVar10;
  undefined *local_res10;
  undefined *in_stack_ffffffffffffffd8;
  
  local_res10 = (undefined *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffd8 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x7a,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  ppuVar9 = (undefined **)PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar3 + 0x70) == '\0') {
    *(undefined1 *)(lVar3 + 0x70) = 1;
    while (*(char *)(lVar3 + 0x39) != '\0') {
      if (*(int *)(lVar3 + 0x54) <= *(int *)(lVar3 + 0x50)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          ppuVar9 = (undefined **)PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          iVar1 = *(int *)(lVar3 + 0x54);
          uVar10 = 0x7b;
          bVar7 = 4;
LAB_1c000c0ef:
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 0x40),bVar7,ppuVar9,uVar10,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar1);
        }
        break;
      }
      uVar4 = (*DAT_1c001dee8)(UfxGlobals,param_1);
      ppuVar9 = &local_res10;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,uVar4);
      if (iVar1 < 0) {
        if ((iVar1 != -0x7fffffe6) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          ppuVar9 = (undefined **)PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          uVar10 = 0x7c;
          bVar7 = 2;
          goto LAB_1c000c0ef;
        }
        break;
      }
      uVar2 = SynopsysAddRequestToList(param_1,local_res10);
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar8 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 0x40),2,puVar8,0x7d,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)uVar2);
        }
        ppuVar9 = (undefined **)(ulonglong)uVar2;
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res10);
        break;
      }
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res10,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
      ppuVar9 = (undefined **)PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      if ((*(byte *)(lVar6 + 0x13) & 3) == 0) {
        ppuVar9 = (undefined **)PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
        if (*(char *)(lVar6 + 8) != '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar8 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
            lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
            WPP_RECORDER_SF_q(*(undefined8 *)(lVar5 + 0x40),2,puVar8,0x7e,in_stack_ffffffffffffffd8,
                              (char)param_1);
          }
          ppuVar9 = (undefined **)0xc0000010;
          SynopsysQueueRequestForCompletion(param_1,local_res10,0xc0000010,0);
          break;
        }
      }
      puVar8 = local_res10;
      lVar6 = TransferRequest(param_1,local_res10,ppuVar9);
      *(longlong *)(lVar5 + 0x10) = lVar6;
      if (lVar6 != 0) {
        TransferUnlock(param_1);
        TransferDmaExecute(*(undefined8 *)(lVar5 + 0x10),puVar8,ppuVar9);
        TransferLock(param_1);
      }
    }
    *(undefined1 *)(lVar3 + 0x70) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,ppuVar9,0x7f,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferCommandEndComplete @ 1c000c150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferCommandEndComplete(longlong param_1,uint param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined *puVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x36,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar5 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  plVar1 = (longlong *)(lVar3 + 0x40);
  plVar2 = (longlong *)*plVar1;
  if (plVar1 != plVar2) {
    do {
      if (*(uint *)(plVar2 + 3) == (param_2 >> 0x10 & 0x7f)) {
        lVar5 = plVar2[-3];
        if (lVar5 != 0) {
          puVar6 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
          puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar5);
          goto LAB_1c000c27b;
        }
        break;
      }
      plVar2 = (longlong *)*plVar2;
    } while (plVar1 != plVar2);
  }
  puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
    puVar6 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    puVar4 = (undefined8 *)(lVar3 + 0x20);
LAB_1c000c27b:
    if (puVar4 != (undefined8 *)0x0) {
      *(undefined1 *)((longlong)puVar4 + 0x34) = 0;
      if (*(int *)(puVar4 + 6) == 7) {
        puVar6 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar4);
        if ((*(longlong *)(lVar3 + 0x88) != 0) && (*(longlong *)(lVar3 + 0x88) == puVar4[1])) {
          *(undefined8 *)(lVar3 + 0x88) = 0;
        }
        *(undefined4 *)(puVar4 + 6) = 9;
        TransferCancelCleanup(param_1,lVar5,puVar6);
      }
      else {
        TransferRequestTryUnmarkCancelableAndCleanup(param_1,lVar5,puVar6);
      }
    }
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x37,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferCommandStallClear @ 1c000c37c =====

void SynopsysTransferCommandStallClear(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar1 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x75,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  TransferCommandStallClear(param_1,CONCAT71(uVar2,uVar1),param_3);
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x76,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferCommandStallSet @ 1c000c428 =====

void SynopsysTransferCommandStallSet(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar1 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x73,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  TransferCommandStallSet(param_1,CONCAT71(uVar2,uVar1),param_3);
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x74,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferCommandStartComplete @ 1c000c4d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferCommandStartComplete(longlong param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x38,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar3 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  puVar2 = *(undefined8 **)(lVar1 + 0x40);
  do {
    if ((undefined8 *)(lVar1 + 0x40) == puVar2) {
LAB_1c000c5ab:
      puVar4 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      if ((*(byte *)(lVar1 + 0x13) & 3) == 0) {
        puVar4 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
        lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
        puVar2 = (undefined8 *)(lVar1 + 0x20);
LAB_1c000c601:
        if (puVar2 != (undefined8 *)0x0) {
          if ((param_2 & 0xf000) == 0) {
            *(undefined1 *)((longlong)puVar2 + 0x35) = 1;
            *(uint *)(puVar2 + 7) = param_2 >> 0x10 & 0x7f;
            if ((lVar3 != 0) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              puVar4 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
              lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
              WPP_RECORDER_SF_Dq(*(undefined8 *)(lVar1 + 0x40),4,puVar4,0x3a,
                                 &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,
                                 (char)*(undefined4 *)(puVar2 + 7),(char)lVar3);
            }
            puVar4 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
            if (*(int *)(puVar2 + 6) == 6) {
              lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
              if ((*(longlong *)(lVar1 + 0x88) != 0) && (*(longlong *)(lVar1 + 0x88) == puVar2[1]))
              {
                *(undefined8 *)(lVar1 + 0x88) = 0;
              }
              *(undefined4 *)(puVar2 + 6) = 7;
              TransferCommandEnd(param_1,lVar3,puVar4);
            }
            else {
              lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
              *(undefined8 *)(lVar3 + 0x88) = puVar2[1];
              *(undefined4 *)(puVar2 + 6) = 5;
            }
          }
          else {
            TRACE_TRANSFER("START FAIL",param_1,0);
            lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_1,
                               PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
            if ((*(byte *)(lVar1 + 0x13) & 3) == 0) {
              lVar3 = param_1;
              puVar4 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
              lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
              if (*(char *)(lVar1 + 8) == '\0') {
                TransferCommandStallSet(param_1,lVar3,puVar4);
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                puVar4 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
                lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
                WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x40),2,puVar4,0x39,
                                 &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
              }
            }
            else {
              puVar4 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
              lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
              if ((*(longlong *)(lVar1 + 0x88) != 0) && (*(longlong *)(lVar1 + 0x88) == puVar2[1]))
              {
                *(undefined8 *)(lVar1 + 0x88) = 0;
              }
              *(undefined4 *)(puVar2 + 6) = 9;
              TransferRequestTryUnmarkCancelableAndCleanup(param_1,lVar3,puVar4);
            }
          }
        }
      }
      TransferUnlock(param_1);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x3b,
                         &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
      }
      return;
    }
    if ((*(int *)(puVar2 + 2) - 4U & 0xfffffffd) == 0) {
      lVar3 = puVar2[-3];
      if (lVar3 != 0) {
        puVar4 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
        puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar3);
        goto LAB_1c000c601;
      }
      goto LAB_1c000c5ab;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== SynopsysTransferComplete @ 1c000c880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferComplete(longlong param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x47,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar2 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(byte *)(lVar1 + 0x13) & 3) == 0) {
    TransferCompleteControl(param_1,param_2,puVar2);
  }
  else {
    TransferCompleteData(param_1,param_2,puVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x48,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferDestroy @ 1c000c958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferDestroy(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined *puVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x49,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),
                     PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  *(undefined8 *)(lVar2 + 0x18 + (ulonglong)*(uint *)(lVar1 + 0x20) * 8) = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
    *(undefined8 *)(lVar2 + 0x18 + (ulonglong)(*(int *)(lVar1 + 0x20) + 1) * 8) = 0;
  }
  *(undefined1 *)(lVar5 + 0x39) = 0;
  SynopsysCancelAllRequestsForEndpoint(param_1);
  lVar1 = *(longlong *)(lVar5 + 8);
  lVar2 = *(longlong *)(lVar5 + 0x10);
  *(undefined8 *)(lVar5 + 8) = 0;
  *(undefined8 *)(lVar5 + 0x10) = 0;
  lVar5 = 0;
  puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
    puVar6 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
    plVar4 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    lVar5 = *plVar4;
    *plVar4 = 0;
  }
  TransferUnlock(param_1);
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar1);
  }
  if (lVar2 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar2);
  }
  if (lVar5 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x4a,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferGetStall @ 1c000cba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferGetStall(undefined8 param_1,undefined1 *param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x77,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar2 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  TransferLock(param_1);
  *param_2 = *(undefined1 *)(lVar1 + 0x38);
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x78,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferInitialize @ 1c000cc88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysTransferInitialize(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  void *_Dst;
  undefined8 uVar10;
  ulonglong uVar11;
  byte bVar12;
  undefined4 uVar13;
  uint uVar14;
  ulonglong *puVar15;
  undefined8 *local_res10;
  undefined8 local_res18;
  longlong *local_res20;
  undefined8 local_88;
  code *pcStack_80;
  ulonglong local_78;
  ulonglong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  longlong local_50;
  undefined8 uStack_48;
  undefined *local_40;
  
  local_res10 = (undefined8 *)0x0;
  local_70 = (ulonglong)(uint)local_70;
  local_78 = local_78 & 0xffffffff00000000;
  local_res18 = 0;
  local_88 = 0;
  pcStack_80 = (code *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x4b,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,puVar4[1],PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  local_40 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  puVar15 = &local_70;
  local_60 = 0;
  uStack_68 = 0;
  local_70 = 0x38;
  local_50 = 0;
  uStack_48 = 0;
  uStack_58 = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,puVar15,&local_res10);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x4c,
                        &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
    }
  }
  else {
    *local_res10 = *puVar4;
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    uVar13 = 1;
    if ((*(byte *)(lVar8 + 0x13) & 3) == 2) {
      uVar13 = 0x10;
    }
    *(undefined4 *)((longlong)local_res10 + 0x54) = uVar13;
    puVar15 = local_res10 + 4;
    if (*puVar15 == 0) {
      local_60 = 0;
      local_40 = (undefined *)0x0;
      uStack_68 = 0;
      local_70 = 0x38;
      uStack_48 = 0;
      uStack_58 = 0x100000001;
      local_50 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_70);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x4d,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
        }
        goto joined_r0x0001c000cf38;
      }
    }
    puVar15 = local_res10 + 0xd;
    if (*puVar15 == 0) {
      local_60 = 0;
      local_40 = (undefined *)0x0;
      uStack_68 = 0;
      local_70 = 0x38;
      uStack_48 = 0;
      uStack_58 = 0x100000001;
      local_50 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_70);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x4e,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
        }
        goto joined_r0x0001c000cf38;
      }
      puVar9 = local_res10 + 0xb;
      local_res10[0xc] = puVar9;
      *puVar9 = puVar9;
      puVar9 = local_res10 + 8;
      local_res10[9] = puVar9;
      *puVar9 = puVar9;
      *(undefined4 *)(local_res10 + 10) = 0;
    }
    if (local_res10[0xf] == 0) {
      puVar15 = &local_70;
      pcStack_80 = SynopsysCompletionWorkItem;
      local_78 = 1;
      local_60 = 0;
      local_40 = (undefined *)0x0;
      uStack_68 = 0;
      uStack_48 = 0;
      uStack_58 = 0x100000001;
      local_88 = 0x18;
      local_70 = 0x38;
      local_50 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_88);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x4f,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
        }
        goto joined_r0x0001c000cf38;
      }
    }
    if (local_res10[1] == 0) {
      puVar15 = (ulonglong *)0x200;
      local_res18 = 0xf00000008;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xbf8))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40),0x200,&local_res18,0,
                         local_res10 + 1);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x50,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
        }
        goto joined_r0x0001c000cf38;
      }
    }
    _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0xb0))(WdfDriverGlobals,local_res10[1]);
    uVar10 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals);
    local_res10[5] = uVar10;
    local_res10[3] = _Dst;
    memset(_Dst,0,0x200);
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    bVar12 = *(byte *)(lVar8 + 0x13) & 3;
    lVar8 = local_res10[3];
    uVar13 = *(undefined4 *)((longlong)local_res10 + 0x2c);
    puVar1 = (undefined4 *)((ulonglong)(-(uint)(bVar12 != 0) & 0x20) + 0x1d0 + lVar8);
    *puVar1 = *(undefined4 *)(local_res10 + 5);
    puVar1[1] = uVar13;
    puVar1[2] = 0;
    puVar1[3] = 0x80;
    uVar11 = (ulonglong)(-(uint)(bVar12 != 0) & 0x20);
    *(uint *)(uVar11 + 0x1dc + lVar8) = *(uint *)(uVar11 + 0x1dc + lVar8) | 1;
    LOCK();
    UNLOCK();
    uVar14 = (*(byte *)((longlong)puVar4 + 0x12) & 0xf) * 2;
    uVar11 = (ulonglong)uVar14;
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((((*(byte *)(lVar8 + 0x13) & 3) == 0) ||
        (lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,param_1,
                            PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8),
        *(char *)(lVar8 + 0x12) < '\0')) &&
       (lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8
                          ), (*(byte *)(lVar8 + 0x13) & 3) != 0)) {
      uVar11 = (ulonglong)(uVar14 + 1);
    }
    *(longlong *)(lVar7 + 0x18 + uVar11 * 8) = param_1;
    puVar4[3] = (uVar11 + 0x70) * 0x10 + *(longlong *)(lVar6 + 0x18);
    *(int *)(puVar4 + 4) = (int)uVar11;
    puVar15 = (ulonglong *)PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    if ((*(byte *)(lVar6 + 0x13) & 3) == 0) {
      local_res20 = (longlong *)0x0;
      puVar15 = &local_70;
      local_60 = 0;
      local_40 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
      uStack_68 = 0;
      local_70 = 0x38;
      local_50 = 0;
      uStack_48 = 0;
      uStack_58 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_1,puVar15,&local_res20);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x52,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
        }
      }
      else {
        uVar14 = (int)uVar11 + 1;
        local_res20[4] = param_1;
        if (uVar14 < 0x20) {
          *(longlong *)(lVar7 + 0x18 + (ulonglong)uVar14 * 8) = param_1;
          if (*local_res20 == 0) {
            puVar15 = (ulonglong *)0x8;
            local_res18 = 0x3f00000008;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0xbf8))
                              (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40),8,&local_res18,0,
                               local_res20);
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x54,
                                  &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar2);
              }
              goto joined_r0x0001c000cf38;
            }
          }
          lVar6 = (**(code **)(WdfFunctions_01015 + 0xb0))(WdfDriverGlobals,*local_res20);
          local_res20[2] = lVar6;
          goto LAB_1c000d5b8;
        }
        iVar2 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x53,
                            &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,1);
        }
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      goto LAB_1c000d426;
    }
LAB_1c000d5b8:
    iVar2 = 0;
    if (local_res10[2] != 0) goto LAB_1c000d426;
    local_res18 = 0x3f00000008;
    puVar15 = (ulonglong *)
              (longlong)
              (int)((uint)*(ushort *)((longlong)puVar4 + 0x14) *
                   *(int *)((longlong)local_res10 + 0x54));
    iVar3 = (**(code **)(WdfFunctions_01015 + 0xbf8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40),puVar15,&local_res18,0,
                       local_res10 + 2);
    if (-1 < iVar3) goto LAB_1c000d426;
    iVar2 = iVar3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x55,
                        &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar3);
    }
  }
joined_r0x0001c000cf38:
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c000d426:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar15,0x56,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return iVar2;
}



===== SynopsysTransferNotReady @ 1c000d688 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferNotReady(undefined8 param_1,uint param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x62,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  uVar2 = param_1;
  puVar3 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (*(char *)(lVar1 + 8) == '\0') {
    if (((param_2 & 0x3000) == 0x2000) &&
       (*(undefined1 *)(lVar1 + 9) = 1, *(char *)(lVar1 + 0x54) == '\0')) {
      if (*(longlong *)(lVar1 + 0x18) == 0) {
        SynopsysRequestDispatch(param_1,0,puVar3);
      }
      else {
        puVar3 = (undefined *)
                 (CONCAT71((int7)((ulonglong)puVar3 >> 8),(char)(param_2 >> 1)) & 0xffffffffffffff01
                 );
        TransferHandshake(param_1,*(longlong *)(lVar1 + 0x18),puVar3);
      }
    }
  }
  else if (*(char *)(lVar1 + 0x55) != '\0') {
    TransferCommandStallSet(param_1,uVar2,puVar3);
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,99,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferReadyNotify @ 1c000d7c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferReadyNotify(undefined1 param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *in_stack_ffffffffffffffe8;
  
  uVar2 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      uVar2 = CONCAT71((int7)((ulonglong)param_2 >> 8),5);
      in_stack_ffffffffffffffe8 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x6c,
                       &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = param_2;
      param_3 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
      uVar2 = CONCAT71((int7)((ulonglong)uVar2 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar1 + 0x40),4,param_3,0x6d,in_stack_ffffffffffffffe8,
                        param_1);
    }
  }
  TransferLock(param_2);
  SynopsysRequestDispatch(param_2,uVar2,param_3);
  TransferUnlock(param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x6e,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferRequestCancel @ 1c000d8b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferRequestCancel(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char cVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined *puVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1e,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  plVar3 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  puVar5 = (undefined *)0x0;
  *(undefined1 *)(plVar3 + 3) = 1;
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,param_1,0,0x370,
             "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\transfer.c");
  iVar1 = (int)plVar3[6];
  if (iVar1 == 1) {
    cVar2 = (**(code **)(WdfFunctions_01015 + 0xcf0))(WdfDriverGlobals,plVar3[2]);
    if (cVar2 == '\0') {
      puVar5 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar3);
      if ((*(longlong *)(lVar4 + 0x88) != 0) && (*(longlong *)(lVar4 + 0x88) == plVar3[1])) {
        *(undefined8 *)(lVar4 + 0x88) = 0;
      }
      *(undefined4 *)(plVar3 + 6) = 8;
      goto LAB_1c000db4f;
    }
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*plVar3,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqDq(*(undefined8 *)(lVar4 + 0x40));
    }
  }
  else if ((iVar1 != 2) && (iVar1 != 3)) {
    if (iVar1 == 4) {
      puVar5 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar3);
      if ((*(longlong *)(lVar4 + 0x88) != 0) && (*(longlong *)(lVar4 + 0x88) == plVar3[1])) {
        *(undefined8 *)(lVar4 + 0x88) = 0;
      }
      *(undefined4 *)(plVar3 + 6) = 6;
    }
    else if (iVar1 == 5) {
      puVar5 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar3);
      if ((*(longlong *)(lVar4 + 0x88) != 0) && (*(longlong *)(lVar4 + 0x88) == plVar3[1])) {
        *(undefined8 *)(lVar4 + 0x88) = 0;
      }
      *(undefined4 *)(plVar3 + 6) = 7;
      TransferCommandEnd(*plVar3,param_1,puVar5);
    }
    else if (iVar1 == 0xb) {
      puVar5 = (undefined *)0xc0000120;
      SynopsysQueueRequestForCompletion(*plVar3,param_1,0xc0000120,0);
    }
    goto LAB_1c000db4f;
  }
  puVar5 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar3);
  if ((*(longlong *)(lVar4 + 0x88) != 0) && (*(longlong *)(lVar4 + 0x88) == plVar3[1])) {
    *(undefined8 *)(lVar4 + 0x88) = 0;
  }
  *(undefined4 *)(plVar3 + 6) = 9;
  TransferCancelCleanup(*plVar3,param_1,puVar5);
LAB_1c000db4f:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0x20,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferReset @ 1c000dba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferReset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x67,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  TransferLock(param_1);
  puVar4 = (undefined *)0x0;
  TRACE_TRANSFER("RESET",param_1,0);
  if (*(uint *)(lVar1 + 0x20) < 2) {
    uVar3 = param_1;
    puVar4 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (*(char *)(lVar1 + 8) != '\0') goto LAB_1c000dca7;
    if (*(int *)(lVar2 + 0x50) == 0) {
      TransferCommandStallSet(param_1,uVar3,puVar4);
      goto LAB_1c000dca7;
    }
  }
  else {
    *(undefined1 *)(lVar2 + 0x39) = 0;
  }
  SynopsysCancelAllRequestsForEndpoint(param_1);
LAB_1c000dca7:
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x68,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferStallClearComplete @ 1c000dcfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferStallClearComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x71,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar2 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  TransferLock(param_1);
  if (*(longlong *)(lVar1 + 0x30) != 0) {
    *(undefined8 *)(lVar1 + 0x30) = 0;
    puVar2 = (undefined *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals);
    SynopsysProgramTransfers(param_1);
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x72,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferStallSetComplete @ 1c000de08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferStallSetComplete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined *puVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x6f,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  TransferLock(param_1);
  puVar5 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
    puVar5 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    *(undefined1 *)(lVar1 + 0x38) = 0;
    if (*(longlong *)(lVar3 + 0x18) != 0) {
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*(longlong *)(lVar3 + 0x18),
                         PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
      puVar5 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      if ((*(longlong *)(lVar4 + 0x88) != 0) &&
         (*(longlong *)(lVar4 + 0x88) == *(longlong *)(lVar1 + 8))) {
        *(undefined8 *)(lVar4 + 0x88) = 0;
      }
      *(undefined4 *)(lVar1 + 0x30) = 10;
    }
    if (*(char *)(lVar3 + 0x54) == '\0') {
      TransferRequestTryUnmarkCancelableAndCleanup(param_1,0,puVar5);
    }
  }
  if (*(longlong *)(lVar2 + 0x28) != 0) {
    *(undefined8 *)(lVar2 + 0x28) = 0;
    puVar5 = (undefined *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals);
    SynopsysProgramTransfers(param_1);
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0x70,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== SynopsysTransferStart @ 1c000e020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysTransferStart(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x69,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  TransferLock(param_1);
  TRACE_TRANSFER("START",param_1,0);
  *(undefined1 *)(lVar2 + 0x39) = 1;
  uVar3 = param_1;
  puVar4 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((*(byte *)(lVar2 + 0x13) & 3) == 0) {
    TransferSetupPacket(param_1,uVar3,puVar4);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = param_1;
      puVar4 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),4);
      WPP_RECORDER_SF_Dq(*(undefined8 *)(lVar2 + 0x40),4,puVar4,0x6a,
                         &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,
                         (char)*(undefined4 *)(lVar1 + 0x20),(char)param_1);
    }
    SynopsysRequestDispatch(param_1,uVar3,puVar4);
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x6b,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TRACE_TRANSFER @ 1c000e1c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TRACE_TRANSFER(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = 0;
  lVar1 = 0;
  if (param_3 == 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((*(byte *)(lVar2 + 0x13) & 3) == 0) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_2,PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0);
      lVar1 = lVar3 + 0x20;
      lVar3 = *(longlong *)(lVar3 + 0x30);
    }
  }
  else {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_3,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
    lVar3 = *(longlong *)(lVar1 + 0x10);
  }
  if (lVar1 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  }
  if (lVar3 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,lVar3,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 4) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,param_2,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    McTemplateK0spqppqqqqqqq_EtwWriteTransfer();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,param_2,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    WPP_RECORDER_SF_sDqqqDDDdddd(*(undefined8 *)(lVar1 + 0x40));
  }
  return;
}



===== TransferAppendExtraTrb @ 1c000e4a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TransferAppendExtraTrb(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined4 uStack_48;
  uint uStack_44;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x10));
  uVar2 = *(ushort *)(lVar7 + 0x14);
  iVar3 = *(int *)(lVar5 + 0x80);
  iVar1 = iVar3 + 1;
  *(int *)(lVar5 + 0x80) = iVar1;
  if (iVar1 == *(int *)(lVar5 + 0x54)) {
    *(undefined4 *)(lVar5 + 0x80) = 0;
  }
  plVar9 = (longlong *)((ulonglong)param_2 * 0x10 + *(longlong *)(lVar5 + 0x18));
  uVar4 = CONCAT44((*(uint *)(lVar6 + 8) & 0x3f) << 4,*(undefined4 *)(lVar6 + 0x1c)) &
          0xffffffff00ffffff;
  uStack_44 = (uint)(uVar4 >> 0x20) | 2;
  uStack_48 = (undefined4)uVar4;
  *plVar9 = (int)((uint)uVar2 * iVar3) + lVar8;
  *(undefined4 *)(plVar9 + 1) = uStack_48;
  *(uint *)((longlong)plVar9 + 0xc) = uStack_44;
  *(uint *)((longlong)plVar9 + 0xc) = *(uint *)((longlong)plVar9 + 0xc) | 1;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
    McTemplateK0pqqqqqq_EtwWriteTransfer();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar5 + 0x40));
  }
  *(int *)(lVar6 + 0x14) = *(int *)(lVar6 + 0x14) + *(int *)(lVar6 + 0x1c);
  *(int *)(lVar6 + 0x18) = *(int *)(lVar6 + 0x18) + *(int *)(lVar6 + 0x1c);
  *(undefined1 *)(lVar6 + 0xc) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0,0x22,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferBegin @ 1c000e7ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000ed3a) */

undefined8
TransferBegin(undefined8 param_1,undefined *param_2,undefined8 param_3,undefined1 param_4)

{
  byte bVar1;
  ushort uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined *puVar9;
  char cVar10;
  ulonglong *puVar11;
  code *pcVar12;
  undefined *puVar13;
  undefined1 auStackY_f8 [32];
  ulonglong local_a0 [6];
  undefined *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_a0[0] = (ulonglong)(uint)local_a0[0];
  local_68 = 0;
  uStack_60 = 0;
  local_48 = 0;
  cVar10 = (char)param_3;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x57,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar6 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  local_70 = PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588;
  puVar11 = local_a0;
  local_a0[2] = 0;
  local_a0[3] = 0x100000001;
  local_a0[1] = 0;
  local_a0[0] = 0x38;
  local_a0[4] = 0;
  local_a0[5] = 0;
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x310))(WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x40));
  puVar9 = (undefined *)(ulonglong)uVar8;
  if ((int)uVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x58,
                        &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)uVar8);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
LAB_1c000ecbe:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdq(puVar3[8]);
    }
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,*puVar6,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
    if ((*(longlong *)(lVar4 + 0x88) != 0) && (*(longlong *)(lVar4 + 0x88) == puVar6[1])) {
      *(undefined8 *)(lVar4 + 0x88) = 0;
    }
    *(undefined4 *)(puVar6 + 6) = 10;
    SynopsysQueueRequestForCompletion(param_1,param_2,(int)puVar9,0);
    puVar13 = puVar9;
  }
  else {
    local_48 = 0;
    uStack_60 = 0;
    local_68 = 0x28;
    local_58 = 0;
    uStack_50 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,0,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    bVar1 = *(byte *)(lVar5 + 0x13);
    *(char *)(puVar7 + 4) = cVar10;
    *puVar7 = param_1;
    puVar7[7] = param_2;
    *(uint *)(puVar7 + 1) = (-(uint)((bVar1 & 3) != 0) & 0xfffffffc) + 5;
    *(undefined1 *)((longlong)puVar7 + 0xc) = param_4;
    *(undefined8 *)(lVar4 + 0x30) = puVar3[3];
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if (((*(byte *)(lVar5 + 0x13) & 3) == 0) && (cVar10 != '\0')) {
      *(longlong *)(lVar4 + 0x30) = *(longlong *)(lVar4 + 0x30) + 0x10;
    }
    *(uint *)(puVar7 + 2) = (uint)uStack_60;
    if (cVar10 == '\0') {
      uVar2 = *(ushort *)((longlong)puVar3 + 0x14);
      uVar8 = (uint)uStack_60 % (uint)uVar2;
      if (uVar8 != 0) {
        *(undefined1 *)((longlong)puVar7 + 0xc) = 1;
        *(uint *)((longlong)puVar7 + 0x1c) = uVar2 - uVar8;
      }
    }
    *puVar6 = param_1;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((*(byte *)(lVar4 + 0x13) & 3) == 0) {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0);
      *(undefined1 *)(lVar4 + 0xb) = 1;
    }
    puVar6[2] = 0;
    pcVar12 = SynopsysEvtRequestCancel;
    uVar8 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2);
    puVar9 = (undefined *)(ulonglong)uVar8;
    if ((int)uVar8 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar12,0x59,
                          &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)uVar8);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      goto LAB_1c000ecbe;
    }
    TRACE_TRANSFER("BEGIN",param_1,(longlong)param_2);
    if (*(int *)(puVar7 + 2) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,*puVar6,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
      *(undefined4 *)(puVar6 + 6) = 1;
      puVar13 = param_2;
      uVar8 = (**(code **)(WdfFunctions_01015 + 800))(WdfDriverGlobals,0);
      puVar9 = (undefined *)(ulonglong)uVar8;
      if (-1 < (int)uVar8) goto LAB_1c000ed74;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar13,0x5a,
                          &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)uVar8);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      goto LAB_1c000ecbe;
    }
    *(undefined1 *)(puVar7 + 8) = 1;
    TRACE_TRANSFER("ZERO LENGTH",param_1,puVar7[7]);
    *(undefined1 *)((longlong)puVar7 + 0xc) = 1;
    *(undefined4 *)((longlong)puVar7 + 0x1c) = 0;
    puVar13 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
    (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar6);
    *(undefined4 *)(puVar6 + 6) = 2;
  }
  SynopsysProgramTransfers(param_1);
LAB_1c000ed74:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar13,0x5c,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return 0;
}



===== TransferCancelCleanup @ 1c000ede4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCancelCleanup(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined *puVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x29,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar7 = 0;
  if (param_2 == 0) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0);
      lVar7 = lVar7 + 0x20;
    }
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  }
  uVar5 = *(uint *)(lVar7 + 0x48);
  while ((uVar5 != *(uint *)(lVar7 + 0x4c) || (*(char *)(lVar2 + 0x3a) == '\x01'))) {
    *(undefined1 *)(lVar2 + 0x3a) = 0;
    puVar6 = (undefined8 *)((ulonglong)uVar5 * 0x10 + *(longlong *)(lVar2 + 0x18));
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
      McTemplateK0pqqqqqq_EtwWriteTransfer();
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar3 + 0x40));
    }
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    bVar1 = *(byte *)(lVar3 + 0x13);
    *puVar6 = 0;
    puVar6[1] = 0;
    uVar5 = (uVar5 + 1) % ((-(uint)((bVar1 & 3) != 0) & 2) + 0x1d);
  }
  lVar3 = *(longlong *)(lVar7 + 0x10);
  *(undefined1 *)(lVar7 + 0x50) = 0;
  if (lVar3 != 0) {
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar3,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
    if (*(longlong *)(lVar4 + 0x28) != 0) {
      TRACE_TRANSFER("CLEANUP (Data)",param_1,param_2);
      (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,lVar3,0);
      *(undefined8 *)(lVar4 + 0x28) = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,lVar3);
    *(undefined8 *)(lVar7 + 0x10) = 0;
  }
  lVar7 = param_1;
  puVar8 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((*(byte *)(lVar3 + 0x13) & 3) == 0) {
    lVar7 = param_1;
    puVar8 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    *(undefined4 *)(lVar4 + 8) = 0;
    lVar3 = *(longlong *)(lVar4 + 0x18);
    if (lVar3 == 0) goto LAB_1c000f166;
    TRACE_TRANSFER("CLEANUP (Handshake)",param_1,lVar3);
    *(undefined8 *)(lVar4 + 0x18) = 0;
    lVar7 = *(longlong *)(lVar2 + 0x18);
    *(undefined8 *)(lVar7 + 0x1f0) = 0;
    *(undefined8 *)(lVar7 + 0x1f8) = 0;
    param_2 = lVar3;
  }
  else {
LAB_1c000f166:
    if (param_2 == 0) goto LAB_1c000f202;
  }
  lVar7 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,lVar7,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    WPP_RECORDER_SF_qq(*(undefined8 *)(lVar3 + 0x40));
  }
  puVar8 = (undefined *)0xc0000120;
  SynopsysQueueRequestForCompletion(param_1,lVar7,0xc0000120,0);
  SynopsysRequestDispatch(param_1,lVar7,puVar8);
LAB_1c000f202:
  if (*(char *)(lVar2 + 0x39) == '\0') {
    if (*(char *)(lVar2 + 0x38) != '\0') {
      TransferCommandStallClear(param_1,lVar7,puVar8);
    }
  }
  else {
    lVar7 = param_1;
    puVar8 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if ((*(byte *)(lVar2 + 0x13) & 3) == 0) {
      TransferSetupPacket(param_1,lVar7,puVar8);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,0x2b,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandEnd @ 1c000f2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandEnd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x10,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  uVar3 = (ulonglong)(*(int *)(lVar2 + 0x38) << 0x10 | 0x808);
  UfxEndpointCommand(param_1,*(undefined4 **)(lVar1 + 0x30),uVar3,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar3,0x11,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandStallClear @ 1c000f3b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandStallClear(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xe,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  puVar1 = *(undefined4 **)(lVar2 + 0x18);
  *(undefined1 *)(lVar3 + 0x38) = 0;
  uVar4 = 5;
  UfxEndpointCommand(param_1,puVar1,5,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0xf,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandStallSet @ 1c000f4bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandStallSet(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xc,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  puVar1 = *(undefined4 **)(lVar2 + 0x18);
  *(undefined1 *)(lVar3 + 0x38) = 1;
  uVar4 = 4;
  UfxEndpointCommand(param_1,puVar1,4,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0xd,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandStart @ 1c000f5c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandStart(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uStackX_1c;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x12,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar3 = 0;
  if (param_2 == 0) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    if ((*(byte *)(lVar2 + 0x13) & 3) == 0) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0);
      lVar3 = lVar3 + 0x20;
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  uStackX_1c = (undefined4)((ulonglong)param_3 >> 0x20);
  uVar4 = 6;
  puVar1 = *(undefined4 **)(lVar2 + 0x30);
  *(undefined2 *)(lVar3 + 0x34) = 1;
  UfxEndpointCommand(param_1,puVar1,6,uStackX_1c,(int)param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x13,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandStartOrUpdate @ 1c000f728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandStartOrUpdate(undefined8 param_1,longlong param_2,undefined *param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x16,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar2 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  if (*(char *)(lVar1 + 0x34) == '\0') {
    TransferCommandStart(param_1,param_2,param_3);
  }
  else {
    TransferCommandUpdate(param_1,param_2,puVar2);
    param_3 = puVar2;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x17,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCommandUpdate @ 1c000f814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCommandUpdate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x14,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  uVar3 = (ulonglong)(*(int *)(lVar2 + 0x38) << 0x10 | 7);
  UfxEndpointCommand(param_1,*(undefined4 **)(lVar1 + 0x30),uVar3,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar3,0x15,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCompleteControl @ 1c000f924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCompleteControl(longlong param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined *in_stack_ffffffffffffff88;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff88 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x40,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  TransferLock(param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  puVar7 = PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(char *)(lVar4 + 8) == '\0') {
    if (*(char *)(lVar4 + 10) == '\0') {
      if (*(char *)(lVar4 + 0xb) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x40),3,puVar7,0x45,
                           &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
        }
      }
      else {
        TransferUnlock(param_1);
        TransferCompleteData(param_1,param_2,puVar7);
        TransferLock(param_1);
      }
    }
    else {
      lVar3 = *(longlong *)(lVar3 + 0x18);
      TRACE_TRANSFER("COMPLETE (Handshake)",param_1,*(longlong *)(lVar4 + 0x18));
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
      puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
        in_stack_ffffffffffffff88 =
             (undefined *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                      *(undefined4 *)(lVar5 + 0x20));
        McTemplateK0pqqqqqq_EtwWriteTransfer();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar5 + 0x40));
      }
      if ((*(uint *)(lVar3 + 0x1fc) & 1) == 0) {
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x800))
                          (WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x18));
        if (uVar2 == 0xc0000120) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar7,0x44,
                              &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x20);
          }
          if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
            McTemplateK0sqq_EtwWriteTransfer();
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
            lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
            WPP_RECORDER_SF_qd(*(undefined8 *)(lVar5 + 0x40),4,puVar7,0x43,in_stack_ffffffffffffff88
                               ,(char)*(undefined8 *)(lVar4 + 0x18),(char)uVar2);
          }
          uVar6 = *(undefined8 *)(lVar4 + 0x18);
          puVar7 = (undefined *)(ulonglong)uVar2;
          SynopsysQueueRequestForCompletion(param_1,uVar6,uVar2,0);
          SynopsysProgramTransfers(param_1);
          *(undefined1 *)(lVar4 + 10) = 0;
          *(undefined8 *)(lVar4 + 0x18) = 0;
          *(undefined1 *)(lVar4 + 0x54) = 0;
          *(undefined8 *)(lVar3 + 0x1f0) = 0;
          *(undefined8 *)(lVar3 + 0x1f8) = 0;
          TransferSetupPacket(param_1,uVar6,puVar7);
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
        WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x40),2,puVar7,0x42,
                         &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
      }
    }
  }
  else {
    lVar3 = *(longlong *)(lVar3 + 0x18);
    TRACE_TRANSFER("COMPLETE (Setup)",param_1,0);
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
    puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
      McTemplateK0pqqqqqq_EtwWriteTransfer();
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar5 + 0x40));
    }
    pcVar1 = DAT_1c001dee0;
    uVar6 = UfxGlobals;
    if ((*(uint *)(lVar3 + 0x1ec) & 1) == 0) {
      *(undefined1 *)(lVar4 + 8) = 0;
      *(undefined1 *)(lVar4 + 0x54) = 0;
      *(undefined8 *)(lVar3 + 0x1e0) = 0;
      *(undefined8 *)(lVar3 + 0x1e8) = 0;
      puVar7 = *(undefined **)(lVar4 + 0x10);
      (*pcVar1)(uVar6,param_1);
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar7 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x40),2,puVar7,0x41,
                       &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
    }
  }
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0x46,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferCompleteData @ 1c000ff10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferCompleteData(longlong param_1,uint param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  undefined *puVar13;
  undefined8 *puVar14;
  uint unaff_R13D;
  uint uVar15;
  char cVar16;
  uint local_res18 [2];
  uint local_res20;
  undefined *in_stack_ffffffffffffff38;
  int local_78;
  
  bVar5 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff38 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3c,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  TransferLock(param_1);
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  local_78 = 0;
  lVar12 = param_1;
  if (*(longlong *)(lVar7 + 0x88) == 0) {
    puVar13 = (undefined *)0x0;
    TRACE_TRANSFER("COMPLETION SKIPPED - Cancelled",param_1,0);
  }
  else {
    plVar8 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar7 + 0x88),
                        PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
    lVar3 = plVar8[2];
    lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    uVar15 = unaff_R13D & 0xffffff00;
    local_res20 = uVar15;
    if (((param_2 & 0x3c0) == 0x80) && ((param_2 >> 0xd & 1) != 0)) {
      TRACE_TRANSFER("XferInProgress event with IsShortPacket set",param_1,0);
      local_res18[0] = local_res18[0] & 0xffffff00;
      cVar16 = false;
    }
    else {
      uVar11 = local_res18[0] >> 8;
      local_res18[0] = local_res18[0] & 0xffffff00;
      cVar16 = false;
      if ((param_2 & 0x3c0) == 0x40) {
        cVar16 = (param_2 >> 0xd & 1) != 0;
        if ((bool)cVar16) {
          local_res18[0] = CONCAT31((int3)uVar11,1);
        }
        bVar5 = false;
        if ((param_2 >> 0xf & 1) != 0) {
          bVar5 = true;
        }
      }
    }
    uVar11 = *(uint *)(plVar8 + 9);
    bVar4 = false;
    while (((uVar11 != *(uint *)((longlong)plVar8 + 0x4c) || (*(char *)(lVar7 + 0x3a) == '\x01')) &&
           ((char)uVar15 == '\0'))) {
      puVar14 = (undefined8 *)((ulonglong)uVar11 * 0x10 + *(longlong *)(lVar7 + 0x18));
      lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8)
      ;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
        in_stack_ffffffffffffff38 =
             (undefined *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff38 >> 0x20),
                      *(undefined4 *)(lVar10 + 0x20));
        McTemplateK0pqqqqqq_EtwWriteTransfer();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar10 + 0x40));
      }
      *(undefined1 *)(lVar7 + 0x3a) = 0;
      cVar16 = (char)local_res18[0];
      if ((((*(uint *)((longlong)puVar14 + 0xc) & 0x800) != 0) && (!bVar5)) &&
         (local_res20 = local_res20 & 0xff, (char)local_res18[0] == '\0')) {
        local_res20 = 1;
      }
      uVar15 = local_res20;
      if ((*(uint *)(lVar9 + 0x50) == uVar11) && (*(int *)(lVar9 + 0x4c) != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar13 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
          lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          in_stack_ffffffffffffff38 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
          WPP_RECORDER_SF_(*(undefined8 *)(lVar10 + 0x40),4,puVar13,0x3d,
                           &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
        }
      }
      else {
        *(int *)(lVar9 + 0x34) = *(int *)(lVar9 + 0x34) + 1;
      }
      uVar1 = *(uint *)(puVar14 + 1);
      *puVar14 = 0;
      puVar14[1] = 0;
      local_78 = local_78 + (uVar1 & 0xffffff);
      lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      uVar11 = (uVar11 + 1) % ((-(uint)((*(byte *)(lVar10 + 0x13) & 3) != 0) & 2) + 0x1d);
      bVar4 = true;
    }
    *(uint *)(plVar8 + 9) = uVar11;
    if ((!bVar4) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      puVar13 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar10 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      WPP_RECORDER_SF_Dqddd
                (*(undefined8 *)(lVar10 + 0x40),3,puVar13,0x3e,in_stack_ffffffffffffff38,
                 (char)*(undefined4 *)(lVar6 + 0x20),(char)param_1,(char)plVar8[9],
                 (char)*(undefined4 *)((longlong)plVar8 + 0x4c),*(undefined1 *)(lVar7 + 0x3a));
    }
    if ((bVar5) || (cVar16 != '\0')) {
      *(int *)(lVar9 + 0x44) = local_78;
      TRACE_TRANSFER("COMPLETE (LST or ISP)",param_1,*(longlong *)(lVar9 + 0x38));
      *(undefined1 *)(plVar8 + 10) = 0;
      lVar12 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*plVar8);
      if ((*(longlong *)(lVar12 + 0x88) != 0) && (*(longlong *)(lVar12 + 0x88) == plVar8[1])) {
        *(undefined8 *)(lVar12 + 0x88) = 0;
      }
      *(undefined4 *)(plVar8 + 6) = 10;
      SynopsysProgramTransfers(param_1);
      puVar13 = (undefined *)0x0;
      lVar12 = *(longlong *)(lVar9 + 0x38);
      SynopsysQueueRequestForCompletion
                (param_1,lVar12,0,(ulonglong)(uint)(*(int *)(lVar9 + 0x14) - *(int *)(lVar9 + 0x44))
                );
    }
    else {
      puVar13 = (undefined *)0x0;
      local_res18[0] = 0;
      TRACE_TRANSFER("COMPLETE (IOC)",param_1,0);
      iVar2 = *(int *)(lVar9 + 0x18);
      if (*(int *)(lVar9 + 0x34) == **(int **)(lVar9 + 0x28)) {
        (**(code **)(WdfFunctions_01015 + 0x650))
                  (WdfDriverGlobals,*plVar8,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
        *(undefined4 *)(plVar8 + 6) = 1;
        TRACE_TRANSFER("COMPLETE DMA (IOC)",param_1,*(longlong *)(lVar9 + 0x38));
        *(undefined8 *)(lVar9 + 0x28) = 0;
        TransferUnlock(param_1);
        puVar13 = (undefined *)(ulonglong)(uint)(iVar2 - local_78);
        (**(code **)(WdfFunctions_01015 + 0x340))(WdfDriverGlobals,lVar3,puVar13,local_res18);
        TransferLock(param_1);
        lVar12 = 0x80000000;
        if (((local_res18[0] + 0x80000000 & 0x80000000) == 0) && (local_res18[0] != 0xc0000016)) {
          lVar12 = *(longlong *)(lVar9 + 0x38);
          TransferRequestTryUnmarkCancelableAndCleanup(param_1,lVar12,puVar13);
        }
      }
      else if (*(char *)((longlong)plVar8 + 0x51) == '\0') {
        TRACE_TRANSFER("MAP TRBs (IOC)",param_1,*(longlong *)(lVar9 + 0x38));
        lVar12 = *plVar8;
        puVar13 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
        (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
        *(undefined4 *)(plVar8 + 6) = 2;
      }
      SynopsysProgramTransfers(param_1);
    }
  }
  SynopsysRequestDispatch(param_1,lVar12,puVar13);
  TransferUnlock(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar13,0x3f,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferDmaExecute @ 1c0010598 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferDmaExecute(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *in_stack_ffffffffffffffb8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x18,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
  uVar1 = *puVar3;
  puVar8 = PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
  puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,puVar3[7]);
  if (*(char *)(puVar3 + 8) == '\0') {
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
    puVar8 = PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560;
    (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar4);
    *(undefined4 *)(puVar4 + 6) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar5 + 0x40),4,puVar8,0x19,in_stack_ffffffffffffffb8,
                        (char)param_1);
    }
    puVar8 = (undefined *)*puVar3;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x328))(WdfDriverGlobals,param_1);
    puVar7 = (undefined *)(ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0x1a,
                           in_stack_ffffffffffffffb8,(char)param_1,(char)uVar2);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      TransferLock(uVar1);
      uVar6 = puVar3[7];
      SynopsysQueueRequestForCompletion(uVar1,uVar6,uVar2,0);
      SynopsysRequestDispatch(uVar1,uVar6,puVar7);
      TransferUnlock(uVar1);
      puVar8 = puVar7;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,0x1b,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferHandshake @ 1c00107b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TransferHandshake(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  code *pcVar8;
  code *pcVar9;
  undefined *in_stack_ffffffffffffff48;
  
  pcVar8 = (code *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff48 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x5d,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROL_CONTEXT_TYPE_INFO_1c001d6d0);
  pcVar9 = (code *)PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8;
  puVar6 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (*(longlong *)(lVar5 + 0x18) == param_2) {
LAB_1c0010955:
    *(longlong *)(lVar5 + 0x18) = param_2;
    if (*(char *)(lVar5 + 9) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar9 = (code *)PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
        in_stack_ffffffffffffff48 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
        WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x40),4,pcVar9,0x5f,
                         &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
      }
    }
    else {
      lVar7 = *(longlong *)(lVar3 + 0x18);
      *(longlong *)(lVar4 + 0x30) = lVar7;
      if ((char)param_3 != '\0') {
        *(longlong *)(lVar4 + 0x30) = lVar7 + 0x10;
      }
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,*puVar6,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
      *(undefined8 *)(lVar7 + 0x88) = puVar6[1];
      *(undefined4 *)(puVar6 + 6) = 5;
      cVar1 = *(char *)(lVar5 + 0xb);
      lVar7 = *(longlong *)(lVar4 + 0x18);
      *(undefined4 *)(lVar7 + 0x1f0) = 0;
      *(undefined4 *)(lVar7 + 500) = 0;
      *(undefined4 *)(lVar7 + 0x1f8) = 0;
      *(uint *)(lVar7 + 0x1fc) = (-(uint)(cVar1 != '\0') & 0xfffffff0) + 0x42;
      *(uint *)(lVar7 + 0x1fc) = *(uint *)(lVar7 + 0x1fc) | 1;
      LOCK();
      UNLOCK();
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
      lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
        in_stack_ffffffffffffff48 =
             (undefined *)
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff48 >> 0x20),
                      *(undefined4 *)(lVar7 + 0x20));
        McTemplateK0pqqqqqq_EtwWriteTransfer();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar7 + 0x40));
      }
      TRACE_TRANSFER("HANDSHAKE",param_1,param_2);
      pcVar9 = (code *)(*(longlong *)(lVar4 + 0x28) + 0x1f0);
      TransferCommandStart(param_1,param_2,pcVar9);
      *(undefined1 *)(lVar5 + 10) = 1;
    }
    if (-1 < (int)pcVar8) goto LAB_1c0010be8;
  }
  else {
    pcVar9 = SynopsysEvtRequestCancel;
    uVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals);
    pcVar8 = (code *)(ulonglong)uVar2;
    if (-1 < (int)uVar2) goto LAB_1c0010955;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff48 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar9,0x5e,
                        &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)uVar2);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      in_stack_ffffffffffffff48 =
           (undefined *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff48 >> 0x20),0xa4a);
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x40),4,pcVar9,0x60,in_stack_ffffffffffffff48,
                       (char)*(undefined8 *)(lVar5 + 0x18),(char)pcVar8);
  }
  SynopsysQueueRequestForCompletion(param_1,param_2,(int)pcVar8,0);
  SynopsysProgramTransfers(param_1);
  pcVar9 = pcVar8;
LAB_1c0010be8:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar9,0x61,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferLock @ 1c0010c48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferLock(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
  return;
}



===== TransferProgram @ 1c0010ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 TransferProgram(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  longlong lVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined *puVar23;
  undefined4 *puVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  bool bVar28;
  undefined *in_stack_fffffffffffffef8;
  undefined1 uVar29;
  undefined1 local_b8;
  uint local_b4;
  uint local_b0;
  undefined8 uStack_48;
  
  uVar17 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffef8 = &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2c,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  local_b8 = 0;
  uVar19 = (-(uint)((*(byte *)(lVar9 + 0x13) & 3) != 0) & 2) + 0x1d;
  puVar10 = (undefined8 *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_CONTEXT_TYPE_INFO_1c001d6a8);
  uVar1 = puVar10[2];
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_DMA_CONTEXT_TYPE_INFO_1c001d588);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  local_b0 = 0;
  lVar18 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  for (puVar11 = *(undefined8 **)(lVar18 + 0x40); (undefined8 *)(lVar18 + 0x40) != puVar11;
      puVar11 = (undefined8 *)*puVar11) {
    if (*(char *)(puVar11 + 6) != '\0') {
      local_b0 = *(uint *)(puVar11 + 5);
      break;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar12 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  for (lVar18 = *(longlong *)(lVar12 + 0x48); lVar12 + 0x40 != lVar18;
      lVar18 = *(longlong *)(lVar18 + 8)) {
    if (*(char *)(lVar18 + 0x30) != '\0') {
      uVar17 = *(uint *)(lVar18 + 0x2c);
      break;
    }
  }
  lVar18 = *(longlong *)(lVar7 + 0x28);
  puVar13 = (undefined4 *)(*(longlong *)(lVar7 + 0x18) + (ulonglong)uVar17 * 0x10);
  TRACE_TRANSFER("PROGRAMMING++",param_1,*(longlong *)(lVar9 + 0x38));
  uVar29 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar23 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar12 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_Dqddd
              (*(undefined8 *)(lVar12 + 0x40),4,puVar23,0x2d,in_stack_fffffffffffffef8,
               (char)*(undefined4 *)(lVar8 + 0x20),uVar29,(char)local_b0,(char)uVar17,
               *(undefined1 *)(lVar7 + 0x3a));
  }
  if (*(char *)(lVar9 + 0x40) == '\x01') {
    puVar23 = (undefined *)0x0;
  }
  else {
    puVar23 = (undefined *)(ulonglong)(uint)(**(int **)(lVar9 + 0x28) - *(int *)(lVar9 + 0x30));
  }
  uVar20 = uVar19;
  if (uVar17 != local_b0) {
    if (local_b0 < uVar17) {
      uVar20 = (uVar19 - uVar17) + local_b0;
    }
    else {
      uVar20 = local_b0 - uVar17;
    }
  }
  uVar21 = (uint)puVar23;
  if ((uVar21 == 1) && (uVar20 == 1)) {
    if (*(char *)(lVar9 + 0xc) != '\0') goto LAB_1c0010fc3;
  }
  else if ((uVar20 < 4) && (uVar20 < uVar21)) {
LAB_1c0010fc3:
    *(undefined1 *)(lVar7 + 0x3a) = 1;
    goto LAB_1c0010fd0;
  }
  bVar28 = false;
  local_b4 = 0;
  puVar10[0xb] = lVar18 + (ulonglong)uVar17 * 0x10;
  if (*(char *)((longlong)puVar10 + 0x34) == '\0') {
    *(uint *)(puVar10 + 9) = uVar17;
  }
  bVar3 = false;
  if (uVar21 != 0) {
    do {
      bVar3 = true;
      if (bVar28) break;
      uVar21 = *(uint *)(lVar9 + 0x30);
      piVar2 = *(int **)(lVar9 + 0x28);
      puVar24 = (undefined4 *)((ulonglong)uVar17 * 0x10 + *(longlong *)(lVar7 + 0x18));
      uVar25 = piVar2[(ulonglong)uVar21 * 6 + 6] - *(uint *)(lVar9 + 0x4c);
      lVar18 = (ulonglong)*(uint *)(lVar9 + 0x4c) +
               *(longlong *)(piVar2 + (ulonglong)uVar21 * 6 + 4);
      uVar22 = (int)puVar23 - 1;
      uVar20 = uVar20 - 1;
      *(undefined4 *)(lVar9 + 0x4c) = 0;
      if (((uVar22 == 1) && (uVar20 == 1)) && (*(char *)(lVar9 + 0xc) != '\0')) {
        bVar28 = true;
      }
      else {
        bVar28 = (uVar17 + 1) % uVar19 == local_b0;
        if ((uVar20 < 4) && (uVar20 < uVar22)) {
          bVar28 = true;
        }
      }
      uVar27 = *piVar2 - 1;
      iVar14 = *(int *)(lVar9 + 0x10);
      iVar16 = *(int *)(lVar9 + 0x14) + uVar25;
      *(bool *)((longlong)puVar10 + 0x51) = iVar16 == iVar14;
      uStack_48._0_4_ = uVar25 & 0xffffff;
      if (((bVar28) || (uVar21 == uVar27)) &&
         ((iVar16 != iVar14 &&
          ((uStack_48._0_4_ =
                 ((uint)uStack_48 -
                  ((uint)uStack_48 + *(int *)(lVar9 + 0x18)) % (uint)*(ushort *)(lVar8 + 0x14) ^
                 (uint)uStack_48) & 0xffffff ^ (uint)uStack_48, bVar28 &&
           ((uint)uStack_48 != uVar25)))))) {
        *(uint *)(lVar9 + 0x50) = uVar17;
        *(uint *)(lVar9 + 0x4c) = (uint)uStack_48;
      }
      uVar5 = (uint)uStack_48;
      uVar25 = *(uint *)(lVar9 + 8);
      if (uVar25 == 5) {
        *(undefined4 *)(lVar9 + 8) = 1;
      }
      uVar26 = 0;
      *(int *)(lVar9 + 0x18) = *(int *)(lVar9 + 0x18) + (uint)uStack_48;
      iVar14 = *(int *)(lVar9 + 0x14) + (uint)uStack_48;
      *(int *)(lVar9 + 0x14) = iVar14;
      if (iVar14 == *(int *)(lVar9 + 0x10)) {
        bVar4 = true;
        bVar3 = true;
        if (*(char *)(lVar9 + 0xc) != '\0') goto LAB_1c0011211;
        uVar6 = 2;
        uVar15 = uVar26;
      }
      else {
        bVar3 = false;
LAB_1c0011211:
        bVar4 = bVar3;
        uVar6 = 0;
        uVar15 = 4;
      }
      if ((uVar6 == 0) && ((bVar28 || ((uVar21 == uVar27 && (!bVar4)))))) {
        uVar26 = 0x800;
      }
      uVar26 = (uVar25 & 0x3f) << 4 | uVar6 | uVar15 | uVar26;
      local_b4 = local_b4 + 1;
      if ((local_b4 & 3) == 0) {
        uVar25 = uVar20;
        if (uVar22 < uVar20) {
          uVar25 = uVar22;
        }
        if (3 < uVar25) {
          uVar26 = uVar26 | 0x800;
        }
      }
      uStack_48 = CONCAT44(uVar26,(uint)uStack_48) | 0x40000000000;
      if (puVar24 != puVar13) {
        uStack_48 = CONCAT44(uVar26,uVar5) | 0x40100000000;
      }
      *puVar24 = (int)lVar18;
      puVar24[1] = (int)((ulonglong)lVar18 >> 0x20);
      puVar24[2] = (uint)uStack_48;
      puVar24[3] = uStack_48._4_4_;
      (**(code **)(WdfFunctions_01015 + 0x650))
                (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
      lVar18 = (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8)
      ;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
        in_stack_fffffffffffffef8 =
             (undefined *)
             CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),
                      *(undefined4 *)(lVar18 + 0x20));
        McTemplateK0pqqqqqq_EtwWriteTransfer();
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar18 + 0x40));
      }
      local_b8 = 1;
      if (*(int *)(lVar9 + 0x4c) == 0) {
        *(int *)(lVar9 + 0x30) = *(int *)(lVar9 + 0x30) + 1;
      }
      lVar18 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      uVar17 = (uVar17 + 1) % ((-(uint)((*(byte *)(lVar18 + 0x13) & 3) != 0) & 2) + 0x1d);
      puVar23 = (undefined *)(ulonglong)uVar22;
      bVar3 = bVar28;
    } while (uVar21 != uVar27);
  }
  if ((*(int *)(lVar9 + 0x14) == *(int *)(lVar9 + 0x10)) && (*(char *)(lVar9 + 0xc) != '\0')) {
    if (bVar3) goto LAB_1c001156d;
    TRACE_TRANSFER("EXTRA",param_1,*(longlong *)(lVar9 + 0x38));
    TransferAppendExtraTrb(param_1,uVar17,uVar1);
    *(undefined1 *)(lVar9 + 0xc) = 0;
    uVar17 = (uVar17 + 1) % uVar19;
    if (uVar17 == local_b0) {
      *(undefined1 *)(lVar7 + 0x3a) = 1;
    }
  }
  else if (bVar3) {
LAB_1c001156d:
    *(undefined1 *)(lVar7 + 0x3a) = 1;
  }
  *(undefined4 *)(lVar9 + 0x44) = *(undefined4 *)(lVar9 + 0x18);
  puVar13[3] = puVar13[3] | 1;
  LOCK();
  UNLOCK();
  *(uint *)((longlong)puVar10 + 0x4c) = uVar17;
  *(undefined1 *)(puVar10 + 10) = 1;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,*puVar10,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  *(undefined4 *)(puVar10 + 6) = 3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar23 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar18 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_Dqddd
              (*(undefined8 *)(lVar18 + 0x40),4,puVar23,0x2e,in_stack_fffffffffffffef8,
               (char)*(undefined4 *)(lVar8 + 0x20),uVar29,(char)local_b0,
               (char)*(undefined4 *)((longlong)puVar10 + 0x4c),*(undefined1 *)(lVar7 + 0x3a));
  }
  puVar23 = *(undefined **)(lVar9 + 0x38);
  TRACE_TRANSFER("PROGRAMMING--",param_1,(longlong)puVar23);
  if ((*(uint *)((longlong)puVar10 + 0x4c) == local_b0) && (*(char *)(lVar7 + 0x3a) == '\0')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return local_b8;
    }
    puVar23 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_Dq(*(undefined8 *)(lVar7 + 0x40),2,puVar23,0x2f,
                       &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,
                       (char)*(undefined4 *)(lVar8 + 0x20),uVar29);
  }
LAB_1c0010fd0:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar23,0x30,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return local_b8;
}



===== TransferRequest @ 1c0011614 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 TransferRequest(undefined8 param_1,undefined *param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 auStackY_a8 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,100,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  puVar5 = &local_68;
  local_48 = 0;
  uVar4 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  iVar1 = (int)uStack_50;
  if ((int)uStack_50 == 0x2ac018) {
    uVar7 = CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
  }
  else {
    if ((int)uStack_50 != 0x2ac01c) {
      puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
      if ((((*(byte *)(lVar3 + 0x13) & 3) == 0) ||
          (puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8,
          lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,
                             PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8),
          *(char *)(lVar3 + 0x12) < '\0')) && (iVar1 == 0x2ac00d)) {
        uVar8 = 0;
        uVar7 = CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
      }
      else {
        puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8
                          );
        if ((((*(byte *)(lVar3 + 0x13) & 3) == 0) ||
            (puVar6 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8,
            lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_1,
                               PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8),
            *(char *)(lVar3 + 0x12) < '\0')) && (iVar1 == 0x2ac011)) {
          uVar8 = 1;
          uVar7 = CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
        }
        else {
          lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
          if ((((*(byte *)(lVar3 + 0x13) & 3) != 0) &&
              (lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1),
              *(char *)(lVar3 + 0x12) < '\0')) || (iVar1 != 0x2ac016)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_DDq(*(undefined8 *)(lVar2 + 0x40));
            }
            uVar7 = 0xc0000010;
            SynopsysQueueRequestForCompletion(param_1,param_2,0xc0000010,0);
            SynopsysProgramTransfers(param_1);
            goto LAB_1c0011898;
          }
          uVar8 = 0;
          uVar7 = 0;
        }
      }
      uVar4 = TransferBegin(param_1,param_2,uVar7,uVar8);
      goto LAB_1c0011898;
    }
    uVar7 = 0;
  }
  TransferHandshake(param_1,(longlong)param_2,uVar7);
LAB_1c0011898:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0x66,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return uVar4;
}



===== TransferRequestTryUnmarkCancelableAndCleanup @ 1c00118f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferRequestTryUnmarkCancelableAndCleanup
               (longlong param_1,longlong param_2,undefined *param_3)

{
  int iVar1;
  longlong lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x25,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  if (param_2 != 0) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8;
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
      WPP_RECORDER_SF_dq(*(undefined8 *)(lVar2 + 0x40));
    }
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x27,
                          &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      goto LAB_1c0011a0e;
    }
  }
  TransferCancelCleanup(param_1,param_2,param_3);
LAB_1c0011a0e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x28,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferSetupPacket @ 1c0011a5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TransferSetupPacket(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x23,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  puVar3 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  TRACE_TRANSFER("SETUP",param_1,0);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  memset(*(void **)(lVar2 + 0x18),0,
         (ulonglong)(-(uint)((*(byte *)(lVar5 + 0x13) & 3) != 0) & 0x20) + 0x1d0);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0xb8))(WdfDriverGlobals,*puVar3);
  lVar5 = *(longlong *)(lVar2 + 0x18);
  *(int *)(lVar5 + 0x1e0) = (int)uVar4;
  *(int *)(lVar5 + 0x1e4) = (int)((ulonglong)uVar4 >> 0x20);
  *(undefined4 *)(lVar5 + 0x1e8) = 8;
  *(undefined4 *)(lVar5 + 0x1ec) = 0x22;
  *(uint *)(lVar5 + 0x1ec) = *(uint *)(lVar5 + 0x1ec) | 1;
  LOCK();
  UNLOCK();
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UFXENDPOINT_CONTEXT_TYPE_INFO_1c001d6f8);
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 8) != 0) {
    McTemplateK0pqqqqqq_EtwWriteTransfer();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqdDDDD(*(undefined8 *)(lVar5 + 0x40));
  }
  lVar5 = *(longlong *)(lVar2 + 0x28) + 0x1e0;
  *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(lVar1 + 0x18);
  TransferCommandStart(param_1,0,lVar5);
  *(undefined4 *)(puVar3 + 1) = 1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,lVar5,0x24,
                     &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids);
  }
  return;
}



===== TransferUnlock @ 1c0011dbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TransferUnlock(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSFER_CONTEXT_TYPE_INFO_1c001d560);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
  return;
}



===== WPP_RECORDER_SF_DDq @ 1c0011e14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x65,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x65,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_Dqddd @ 1c0011f08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dqddd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,
                  &param_6,4,&param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_LL @ 1c001204c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x81,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x81,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_dq @ 1c001211c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x26,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x26,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c00121f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,
                  &param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c00122a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,param_4,
                  &param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qdq @ 1c0012384 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x5b,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x5b,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0012478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x2a,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x2a,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqDq @ 1c0012548 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x1f,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0x1f,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqdDDDD @ 1c001265c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqdDDDD(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0xb,pcVar1,lVar3,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,0);
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
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,0xb,in_stack_00000030
                  ,lVar2,&uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048
                  ,4,&uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
                  &uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqqqDDDdddd @ 1c0012880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqqDDDdddd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,10,pcVar1,lVar3,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,8,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,0);
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
  WppAutoLogTrace(param_1,4,1,&WPP_148ea38ade7e33154bda8224d716e6c9_Traceguids,10,in_stack_00000030,
                  lVar2,&uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,
                  8,&uStack0000000000000050,8,&uStack0000000000000058,4,&uStack0000000000000060,4,
                  &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
                  &uStack0000000000000080,4,&uStack0000000000000088,4,0);
  return;
}



===== ActionFun_Detector_A_Cleanup @ 1c0012b60 =====

void ActionFun_Detector_A_Cleanup(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  
  uVar3 = (undefined1)param_2;
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  lVar1 = *(longlong *)(param_1 + 0xf98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1f,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar2 = *(undefined8 **)(lVar1 + 8);
  if (*(char *)(puVar2 + 8) != '\0') {
    DetectorCleanup(puVar2,CONCAT71(uVar4,uVar3),param_3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x20,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== ActionFun_Detector_A_Ignore @ 1c0012c10 =====

void ActionFun_Detector_A_Ignore(void)

{
  return;
}



===== EntryFun_Detector_Aca_Detecting_Detector @ 1c0012c20 =====

void EntryFun_Detector_Aca_Detecting_Detector(void)

{
  return;
}



===== EntryFun_Detector_CheckCharging_Detecting_Detector @ 1c0012c30 =====

void EntryFun_Detector_CheckCharging_Detecting_Detector
               (longlong param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  byte bVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  
  bVar1 = FF_DetectorCheckChgDet(*(longlong *)(param_1 + 0xf98),param_2,param_3);
  *(ulonglong *)(*(longlong *)(param_1 + 0xc18) + 0x10) = (ulonglong)bVar1;
  if (*(longlong *)(*(longlong *)(param_1 + 0xc18) + 0x10) != 0) {
    uVar2 = FF_DetectorCheckRida(*(longlong *)(param_1 + 0xf98),(ulonglong)bVar1,param_3);
    *(ulonglong *)(*(longlong *)(param_1 + 0xc18) + 0x10) = uVar2 & 0xff;
    if (*(longlong *)(*(longlong *)(param_1 + 0xc18) + 0x10) == 0) {
      uVar3 = 3;
      goto LAB_1c0012c92;
    }
  }
  uVar3 = 0;
LAB_1c0012c92:
  SmfRaise(param_1,uVar3,param_3,param_4);
  return;
}



===== EntryFun_Detector_CheckDcd_Detecting_Detector @ 1c0012cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EntryFun_Detector_CheckDcd_Detecting_Detector
               (longlong param_1,undefined8 param_2,char *param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  longlong *plVar4;
  undefined4 uVar5;
  bool bVar6;
  
  lVar2 = *(longlong *)(param_1 + 0xf98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1b;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1b,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar3 = *(uint **)(*(longlong *)(lVar2 + 8) + 8);
  uVar1 = *puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar3 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar3,&RegisterRead,param_3,(int)param_4,(char)uVar1);
  }
  bVar6 = (uVar1 & 2) == 0;
  if (bVar6) {
    param_3 = (char *)0xfffffffffff85ee0;
    (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1c;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1c,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  *(ulonglong *)(*(longlong *)(param_1 + 0xc18) + 0x10) = (ulonglong)!bVar6;
  plVar4 = *(longlong **)(param_1 + 0xc18);
  if (plVar4[2] == 0) {
    *plVar4 = *plVar4 + -1;
    if (**(longlong **)(param_1 + 0xc18) != 0) {
      return;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 3;
  }
  SmfRaise(param_1,uVar5,param_3,param_4);
  return;
}



===== EntryFun_Detector_DcpOrCdp2_Detecting_Detector @ 1c0012df0 =====

void EntryFun_Detector_DcpOrCdp2_Detecting_Detector
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  byte bVar2;
  
  bVar2 = FF_DetectorCheckChgDet(*(longlong *)(param_1 + 0xf98),param_2,param_3);
  *(ulonglong *)(*(longlong *)(param_1 + 0xc18) + 0x10) = (ulonglong)bVar2;
  pcVar1 = *(char **)(param_1 + 0xc18);
  *(ulonglong *)(pcVar1 + 8) = (ulonglong)(*(longlong *)(pcVar1 + 0x10) != 0) + 2;
  SmfRaise(param_1,0,pcVar1,param_4);
  return;
}



===== EntryFun_Detector_DcpOrCdp_Detecting_Detector @ 1c0012e50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EntryFun_Detector_DcpOrCdp_Detecting_Detector
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  byte bVar7;
  
  lVar2 = *(longlong *)(param_1 + 0xf98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x15,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar3 = *(undefined8 **)(lVar2 + 8);
  puVar5 = (uint *)*puVar3;
  uVar1 = *puVar5;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(uint)puVar5 & 0xffff,bVar7);
  }
  puVar4 = (uint *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar5,&RegisterWrite,param_3,(uint)puVar4 & 0xffff,bVar7 | 0x34);
  }
  *puVar4 = uVar1 | 0x34;
  LOCK();
  UNLOCK();
  puVar5 = (uint *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar5,&RegisterRead,(ulonglong)*puVar5,(uint)puVar5 & 0xffff,(char)*puVar5);
  }
  uVar6 = 0xfffffffffff9e580;
  (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,puVar3[6]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x16,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== EntryFun_Detector_Detecting_Detecting_Detector @ 1c0012f90 =====

void EntryFun_Detector_Detecting_Detecting_Detector
               (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  FF_DetectorPrimaryDetection(*(longlong *)(param_1 + 0xf98),param_2,param_3);
  return;
}



===== EntryFun_Detector_Detecting_Stopped_Detector @ 1c0012fb0 =====

void EntryFun_Detector_Detecting_Stopped_Detector
               (longlong param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  *(undefined8 *)(*(longlong *)(param_1 + 0xc18) + 8) = 0;
  SmfRaise(param_1,3,param_3,param_4);
  return;
}



===== EntryFun_Detector_DisablingDcd_Detecting_Detector @ 1c0012fe0 =====

void EntryFun_Detector_DisablingDcd_Detecting_Detector
               (longlong param_1,undefined8 param_2,char *param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  byte bVar7;
  
  lVar2 = *(longlong *)(param_1 + 0xf98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x19;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x19,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar3 = *(ulonglong **)(lVar2 + 8);
  puVar6 = (uint *)*puVar3;
  uVar1 = *puVar6;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar6 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,param_3,(int)param_4,bVar7);
  }
  puVar4 = (uint *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar4 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterWrite,param_3,(int)param_4,bVar7 & 0xfc);
  }
  *puVar4 = uVar1 & 0xfffffffc;
  LOCK();
  UNLOCK();
  puVar5 = (undefined4 *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar5 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(int)param_4,(char)*puVar5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1a;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  SmfRaise(param_1,3,param_3,param_4);
  return;
}



===== EntryFun_Detector_EnablingDcd_Detecting_Detector @ 1c0013120 =====

void EntryFun_Detector_EnablingDcd_Detecting_Detector
               (longlong param_1,undefined8 param_2,char *param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  byte bVar7;
  
  lVar2 = *(longlong *)(param_1 + 0xf98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1d;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1d,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar3 = *(ulonglong **)(lVar2 + 8);
  puVar6 = (uint *)*puVar3;
  uVar1 = *puVar6;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar6 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,param_3,(int)param_4,bVar7);
  }
  puVar4 = (uint *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar4 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterWrite,param_3,(int)param_4,bVar7 & 0xfd);
  }
  *puVar4 = uVar1 & 0xfffffffd;
  LOCK();
  UNLOCK();
  puVar5 = (undefined4 *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar5 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(int)param_4,(char)*puVar5);
  }
  puVar6 = (uint *)*puVar3;
  uVar1 = *puVar6;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar6 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterRead,param_3,(int)param_4,bVar7);
  }
  puVar4 = (uint *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar4 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar6,&RegisterWrite,param_3,(int)param_4,bVar7 | 3);
  }
  *puVar4 = uVar1 | 3;
  LOCK();
  UNLOCK();
  puVar5 = (undefined4 *)*puVar3;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    param_4 = (ulonglong)puVar5 & 0xffff;
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(int)param_4,(char)*puVar5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1e;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1e,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  **(undefined8 **)(param_1 + 0xc18) = 10;
  SmfRaise(param_1,3,param_3,param_4);
  return;
}



===== EntryFun_Detector_Stopped_Stopped_Detector @ 1c00132e0 =====

void EntryFun_Detector_Stopped_Stopped_Detector(void)

{
  return;
}



===== EntryFun_Detector_Stopping_Stopped_Detector @ 1c00132f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EntryFun_Detector_Stopping_Stopped_Detector
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char *pcVar4;
  
  lVar2 = *(longlong *)(param_1 + 0xf98);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xc18) + 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0xf;
    param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xf,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar3 = *(undefined8 **)(lVar2 + 8);
  if (uVar1 == 3) {
    *(undefined1 *)(puVar3 + 8) = 1;
  }
  else {
    DetectorCleanup(puVar3,param_2,param_3);
  }
  pcVar4 = (char *)(ulonglong)uVar1;
  (*DAT_1c001dea8)(UfxGlobals,puVar3[4]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x10;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar4,0x10,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  SmfRaise(param_1,3,pcVar4,param_4);
  return;
}



===== Constructor_Detector @ 1c00133f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Constructor_Detector(longlong param_1,undefined1 *param_2,undefined8 param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  longlong local_40;
  undefined8 local_38;
  undefined *local_30;
  
  local_88 = (ulonglong)(uint)local_88;
  local_5c = local_5c & 0xffffffff00000000;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xc,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  plVar2 = (longlong *)ExAllocatePool2(0x40,0x48,0x666e7953);
  *param_2 = 1;
  *(longlong **)(param_2 + 8) = plVar2;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658);
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  lVar8 = 0;
  lVar9 = 4;
  plVar5 = plVar2;
  do {
    lVar6 = *(longlong *)(lVar3 + 8) + 0xf8818 + lVar8;
    lVar8 = lVar8 + 4;
    *plVar5 = lVar6;
    plVar5 = plVar5 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  puVar7 = &local_60;
  plVar2[7] = *(longlong *)(lVar3 + 0x18) + 0xb08;
  plVar2[4] = *plVar4;
  plVar2[5] = param_1;
  local_30 = PTR__WDF_DETECTOR_TIMER_CONTEXT_TYPE_INFO_1c001d8a0;
  local_68 = 0;
  pcStack_80 = DetectorTimer;
  local_5c = 0;
  uStack_54 = 0;
  local_4c = 0;
  local_38 = 0;
  local_60 = 0x38;
  local_48 = 1;
  local_44 = 1;
  local_88 = 0x28;
  local_78 = 0x100000000;
  uStack_70 = 0;
  local_40 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))(WdfDriverGlobals,&local_88,puVar7,plVar2 + 6);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar7,0xd,
                        &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    puVar7 = (undefined4 *)PTR__WDF_DETECTOR_TIMER_CONTEXT_TYPE_INFO_1c001d8a0;
    plVar5 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,plVar2[6]);
    *plVar5 = plVar4[10];
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar7,0xe,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== DetectorCleanup @ 1c0013670 =====

void DetectorCleanup(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  byte bVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar4 = (uint *)*param_1;
  uVar1 = *puVar4;
  bVar5 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar4,&RegisterRead,param_3,(uint)puVar4 & 0xffff,bVar5);
  }
  puVar2 = (uint *)*param_1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar4,&RegisterWrite,param_3,(uint)puVar2 & 0xffff,bVar5 & 0xcf);
  }
  *puVar2 = uVar1 & 0xffffffcf;
  LOCK();
  UNLOCK();
  puVar3 = (undefined4 *)*param_1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar3,&RegisterRead,param_3,(uint)puVar3 & 0xffff,(char)*puVar3);
  }
  *(undefined1 *)(param_1 + 8) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x22,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== DetectorTimer @ 1c0013790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DetectorTimer(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  ulonglong *puVar1;
  char *pcVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = (char *)0xa;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  pcVar2 = PTR__WDF_DETECTOR_TIMER_CONTEXT_TYPE_INFO_1c001d8a0;
  puVar1 = (ulonglong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  SmfEnqueueEventCommon(*puVar1,2,pcVar2,param_4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar2,0xb,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== FF_DetectorCheckChgDet @ 1c0013854 =====

undefined1 FF_DetectorCheckChgDet(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined1 uVar6;
  byte bVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar2 = *(undefined8 **)(param_1 + 8);
  puVar5 = (uint *)puVar2[1];
  uVar1 = *puVar5;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(uint)puVar5 & 0xffff,(char)uVar1);
  }
  uVar6 = 1;
  if ((uVar1 & 1) == 0) {
    uVar6 = 0;
  }
  else {
    puVar5 = (uint *)*puVar2;
    uVar1 = *puVar5;
    bVar7 = (byte)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(uint)puVar5 & 0xffff,bVar7);
    }
    puVar3 = (uint *)*puVar2;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar5,&RegisterWrite,param_3,(uint)puVar3 & 0xffff,bVar7 & 0xdb | 0x10);
    }
    *puVar3 = uVar1 & 0xffffffdb | 0x10;
    LOCK();
    UNLOCK();
    puVar4 = (undefined4 *)*puVar2;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar4,&RegisterRead,param_3,(uint)puVar4 & 0xffff,(char)*puVar4);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x14,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return uVar6;
}



===== FF_DetectorCheckRida @ 1c00139ac =====

ulonglong FF_DetectorCheckRida(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x11,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 8);
  puVar2 = *(uint **)(lVar3 + 8);
  uVar1 = *puVar2;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    lVar3 = McTemplateK0qq_EtwWriteTransfer
                      (puVar2,&RegisterRead,param_3,(uint)puVar2 & 0xffff,(char)uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    lVar3 = WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x12,
                             &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return CONCAT71((int7)((ulonglong)lVar3 >> 8),(char)(uVar1 >> 2)) & 0xffffffffffffff01;
}



===== FF_DetectorPrimaryDetection @ 1c0013a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FF_DetectorPrimaryDetection(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  byte bVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x17,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  puVar2 = *(undefined8 **)(param_1 + 8);
  puVar5 = (uint *)*puVar2;
  uVar1 = *puVar5;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(uint)puVar5 & 0xffff,bVar7);
  }
  puVar3 = (uint *)*puVar2;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar5,&RegisterWrite,param_3,(uint)puVar3 & 0xffff,bVar7 & 0xf3);
  }
  *puVar3 = uVar1 & 0xfffffff3;
  LOCK();
  UNLOCK();
  puVar4 = (undefined4 *)*puVar2;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar4,&RegisterRead,param_3,(uint)puVar4 & 0xffff,(char)*puVar4);
  }
  puVar5 = (uint *)*puVar2;
  uVar1 = *puVar5;
  bVar7 = (byte)uVar1;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,param_3,(uint)puVar5 & 0xffff,bVar7);
  }
  puVar3 = (uint *)*puVar2;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar5,&RegisterWrite,param_3,(uint)puVar3 & 0xffff,bVar7 | 0x30);
  }
  *puVar3 = uVar1 | 0x30;
  LOCK();
  UNLOCK();
  puVar5 = (uint *)*puVar2;
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
    McTemplateK0qq_EtwWriteTransfer
              (puVar5,&RegisterRead,(ulonglong)*puVar5,(uint)puVar5 & 0xffff,(char)*puVar5);
  }
  uVar6 = 0xfffffffffff9e580;
  (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,puVar2[6]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar6,0x18,
                     &WPP_b849710d7a37319130f2356a0d2ac266_Traceguids);
  }
  return;
}



===== LiveDumpSecondaryCallback @ 1c0013c20 =====

undefined8 LiveDumpSecondaryCallback(void)

{
  return 0;
}



===== FxStubDriverUnloadCommon @ 1c0013c2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_UFX_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c001db78 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c001db78 + 0x50);
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_1c0013c85:
      if (puVar1 == (uint *)0x0) goto LAB_1c0013cdb;
      if (puVar2 <= puVar1) goto LAB_1c0013cf3;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if ((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) goto LAB_1c0013c85;
LAB_1c0013cdb:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0013cf3:
  WdfVersionUnbind(&DAT_1c001de48,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0013d30 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 1c0013d64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *puVar4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2,param_3);
  }
  else {
    _DAT_1c001de48 = 0x2080000;
    _DAT_1c001de50 = &DAT_1c001dc20;
    RtlCopyUnicodeString(&DAT_1c001de48);
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c001de48,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c001de28 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c001de48);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c001db78 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0013ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c001de28 != (code *)0x0) && (DAT_1c001de28 != FxStubDriverUnload)) {
    (*DAT_1c001de28)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0013f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0013f49) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_UFX_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x1c001db6f < puVar2) break;
    if (((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c001db78 = (undefined *)puVar2;
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
    puVar2 = (uint *)((ulonglong)*puVar2 + (longlong)puVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c00140ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00140c9) */
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
    if ((void **)0x1c001db8f < ppvVar2) break;
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



===== McTemplateK0ss_EtwWriteTransfer @ 1c0014174 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ss_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,char *param_5
               )

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != '\0');
    local_30 = (int)lVar2 + 1;
  }
  local_2c = 0;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  if (param_5 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_38 = param_4;
  local_28 = param_5;
  McGenEventWrite_EtwWriteTransfer((undefined8 *)&UfxGuid_Context,param_2,&UfxGuid,3,local_48);
  return;
}



===== McTemplateK0ssq_EtwWriteTransfer @ 1c0014240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ssq_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  char *in_R9;
  char *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  if (in_R9 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  if (in_stack_00000028 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_28 = &uStack0000000000000030;
  local_2c = 0;
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  local_20 = 4;
  local_48 = in_R9;
  local_38 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&UfxGuid_Context,&DebugMessageInt,&UfxGuid,4,local_58);
  return;
}



===== SmfClonePackedSet @ 1c0014324 =====

void SmfClonePackedSet(longlong param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,param_2 * 4,0x31676154);
  if (param_2 != 0) {
    lVar3 = param_1 - (longlong)puVar1;
    uVar2 = (ulonglong)param_2;
    do {
      *puVar1 = *(undefined4 *)(lVar3 + (longlong)puVar1);
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== SmfCreate @ 1c0014380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SmfCreate(ulonglong *param_1,ulonglong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  void *_Dst;
  longlong lVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  char *pcVar10;
  char *pcVar11;
  
  KeGetCurrentIrql();
  pcVar11 = (char *)((ulonglong)(uint)param_1[1] * 10);
  uVar1 = *(uint *)(*(longlong *)(*param_1 + 0x18) + 0x10 + (ulonglong)(uint)param_1[1] * 0x50);
  pcVar10 = (char *)0x31676154;
  uVar5 = ExAllocatePool2(0x40,0xfd8);
  if (uVar5 == 0) {
    return -0x3fffffe9;
  }
  *(undefined4 *)(uVar5 + 0xc04) = 0x7dc;
  *(undefined1 *)(uVar5 + 0xc00) = 0;
  uVar9 = *param_1;
  *(ulonglong *)(uVar5 + 0xc08) = uVar9;
  uVar2 = param_1[1];
  *(uint *)(uVar5 + 0xc10) = (uint)uVar2;
  *(undefined4 *)(uVar5 + 0xc20) =
       *(undefined4 *)(*(longlong *)(uVar9 + 0x18) + 0x40 + (ulonglong)(uint)uVar2 * 0x50);
  *(ulonglong *)(uVar5 + 0xc28) = uVar5 ^ 0x11;
  *param_2 = uVar5 ^ 0x11;
  *(undefined4 *)(uVar5 + 0xf90) = 3;
  *(undefined1 *)(uVar5 + 0xc48) = 0;
  *(undefined2 *)(uVar5 + 0xc40) = 0;
  *(undefined4 *)(uVar5 + 0xc44) = 0;
  *(undefined4 *)(uVar5 + 0xc30) = 0x7fffffff;
  *(undefined4 *)(uVar5 + 0xc34) = 0;
  *(undefined4 *)(uVar5 + 0xc38) = 0;
  *(undefined4 *)(uVar5 + 0xc3c) = 0;
  if (uVar1 == 0) {
    _Dst = (void *)0x0;
  }
  else {
    uVar9 = (ulonglong)(uVar1 * 8);
    pcVar10 = (char *)0x31676154;
    _Dst = (void *)ExAllocatePool2(0x40);
  }
  *(void **)(uVar5 + 0xc18) = _Dst;
  if (uVar1 != 0) {
    if (_Dst == (void *)0x0) goto LAB_1c00144ad;
    memmove(_Dst,(void *)param_1[2],(ulonglong)uVar1 << 3);
  }
  pcVar10 = (char *)0x31676154;
  *(undefined2 *)(uVar5 + 0xf50) = 0;
  uVar9 = 0x100;
  *(undefined1 *)(uVar5 + 0xf68) = 0x10;
  lVar6 = ExAllocatePool2(0x40);
  *(longlong *)(uVar5 + 0xf58) = lVar6;
  if (lVar6 != 0) {
    *(undefined4 *)(uVar5 + 0xf60) = 0;
    *(undefined2 *)(uVar5 + 0xf64) = 0;
    *(undefined1 *)(uVar5 + 0xf66) = 0;
    uVar1 = **(uint **)(uVar5 + 0xc08);
    if ((uVar1 == 0) || ((uVar1 & 0x1f) != 0)) {
      uVar3 = (short)(uVar1 >> 5) + 1;
    }
    else {
      uVar3 = (ushort)(uVar1 >> 5);
    }
    pcVar10 = (char *)0x31676154;
    uVar9 = (ulonglong)((uint)uVar3 * 4);
    lVar6 = ExAllocatePool2(0x40);
    *(longlong *)(uVar5 + 0xf70) = lVar6;
    if (lVar6 != 0) {
      pcVar10 = (char *)0x31676154;
      uVar9 = (ulonglong)((uint)uVar3 * 4);
      lVar6 = ExAllocatePool2(0x40);
      *(longlong *)(uVar5 + 0xf78) = lVar6;
      if (lVar6 != 0) {
        pcVar10 = (char *)0x31676154;
        uVar9 = (ulonglong)((uint)uVar3 * 8);
        lVar6 = ExAllocatePool2(0x40);
        *(longlong *)(uVar5 + 0xf80) = lVar6;
        if (lVar6 != 0) {
          pcVar10 = (char *)0x31676154;
          uVar9 = (ulonglong)((uint)uVar3 * 8);
          lVar6 = ExAllocatePool2(0x40);
          *(longlong *)(uVar5 + 0xf88) = lVar6;
          if (lVar6 != 0) {
            pcVar10 = (char *)0x31676154;
            uVar9 = 0x18;
            puVar7 = (undefined1 *)ExAllocatePool2(0x40);
            *(undefined1 **)(uVar5 + 0xf98) = puVar7;
            if (puVar7 != (undefined1 *)0x0) {
              *puVar7 = 0;
              *(ulonglong *)(*(longlong *)(uVar5 + 0xf98) + 0x10) = param_1[3];
              (**(code **)(*(longlong *)(*(longlong *)(uVar5 + 0xc08) + 0x18) + 0x48 +
                          (ulonglong)*(uint *)(uVar5 + 0xc10) * 0x50))
                        (param_1[3],*(undefined8 *)(uVar5 + 0xf98));
              *(undefined4 *)(uVar5 + 4000) = 1;
              KeInitializeSpinLock(uVar5 + 0xfa8);
              uVar9 = param_1[4];
              *(ulonglong *)(uVar5 + 0xfb8) = uVar9;
              uVar8 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals);
              lVar6 = IoAllocateWorkItem(uVar8);
              *(longlong *)(uVar5 + 0xfc0) = lVar6;
              if (lVar6 != 0) {
                iVar4 = SmfReadRegistry(uVar5);
                if (iVar4 < 0) {
                  return iVar4;
                }
                SmfTraceStep(uVar5,3,pcVar10,pcVar11);
                *(undefined1 *)(uVar5 + 0xc48) = 1;
                SmfRunStateMachine(uVar5,'\x01',pcVar10,pcVar11);
                return iVar4;
              }
            }
          }
        }
      }
    }
  }
LAB_1c00144ad:
  SmfFreeSMContext(uVar5,uVar9,pcVar10,(longlong)pcVar11);
  return -0x3fffffe9;
}



===== SmfCreateAttributes @ 1c00146f4 =====

longlong SmfCreateAttributes(void)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(PTR_MachineTable_1c001d7a0 + 0x10);
  lVar2 = ExAllocatePool2(0x40,0x28,0x31676154);
  if (lVar2 != 0) {
    if (iVar1 == 0) {
      lVar3 = 0;
    }
    else {
      lVar3 = ExAllocatePool2(0x40,iVar1 * 8,0x31676154);
    }
    *(longlong *)(lVar2 + 0x10) = lVar3;
    if (iVar1 == 0) {
      return lVar2;
    }
    if (lVar3 != 0) {
      return lVar2;
    }
    ExFreePool(lVar2);
  }
  SmfReportException(4,0);
  return lVar2;
}



===== SmfDelete @ 1c001478c =====

void SmfDelete(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  longlong lVar4;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xfa8);
  iVar2 = *(int *)(param_1 + 4000);
  cVar1 = *(char *)(param_1 + 0xc48);
  lVar4 = CONCAT71((int7)((ulonglong)param_2 >> 8),uVar3);
  *(undefined1 *)(param_1 + 0xfb0) = uVar3;
  KeReleaseSpinLock(param_1 + 0xfa8);
  if (iVar2 < 0) {
    SmfReportException(2,param_1);
  }
  else if ((cVar1 == '\0') && (iVar2 == 0)) {
    if ((*(char *)(param_1 + 0xf66) != '\0') ||
       (*(short *)(param_1 + 0xf60) != *(short *)(param_1 + 0xf62))) {
      lVar4 = param_1;
      SmfReportException(1,param_1);
    }
    *(undefined4 *)(param_1 + 0xc04) = 0xfffff823;
    SmfRemoveMachine(param_1,lVar4,param_3,param_4);
  }
  return;
}



===== SmfDequeueEvent @ 1c0014850 =====

uint * SmfDequeueEvent(uint *param_1,longlong param_2,char *param_3,longlong param_4)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined1 uVar11;
  int iVar12;
  longlong lVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  bVar10 = false;
  lVar13 = param_2;
  uVar11 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xfa8);
  bVar4 = *(byte *)(param_2 + 0xf68);
  *(undefined1 *)(param_2 + 0xfb0) = uVar11;
  uVar6 = *(ushort *)(param_2 + 0xf60);
  param_1[0] = 0x7fffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((*(char *)(param_2 + 0xf66) != '\0') ||
     (*(short *)(param_2 + 0xf60) != *(short *)(param_2 + 0xf62))) {
    uVar15 = 0;
    uVar16 = (uint)bVar4;
    if (*(short *)(param_2 + 0xf64) != 0) {
      do {
        puVar1 = (uint *)(*(longlong *)(param_2 + 0xf58) +
                         (longlong)((int)(uVar6 + uVar15) % (int)uVar16) * 0x10);
        uVar7 = puVar1[1];
        uVar8 = puVar1[2];
        uVar9 = puVar1[3];
        *param_1 = *puVar1;
        param_1[1] = uVar7;
        param_1[2] = uVar8;
        param_1[3] = uVar9;
        lVar13 = 0;
        if ((*(uint *)(*(longlong *)(param_2 + 0xf78) + (ulonglong)(*param_1 >> 5) * 4) >>
             ((byte)*param_1 & 0x1f) & 1) == 0) break;
        uVar15 = uVar15 + 1;
      } while ((int)uVar15 < (int)(uint)*(ushort *)(param_2 + 0xf64));
    }
    if (uVar15 == *(ushort *)(param_2 + 0xf64)) {
      param_1[0] = 0x7fffffff;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    else {
      for (; 0 < (int)uVar15; uVar15 = uVar15 - 1) {
        param_4 = *(longlong *)(param_2 + 0xf58);
        iVar12 = (int)(uVar6 + uVar15) % (int)uVar16;
        param_3 = (char *)(longlong)iVar12;
        puVar2 = (undefined8 *)
                 (param_4 + (longlong)((int)((bVar4 - 1) + iVar12) % (int)uVar16) * 0x10);
        uVar14 = puVar2[1];
        puVar3 = (undefined8 *)(param_4 + (longlong)param_3 * 0x10);
        *puVar3 = *puVar2;
        puVar3[1] = uVar14;
      }
      *(short *)(param_2 + 0xf64) = *(short *)(param_2 + 0xf64) + -1;
      *(undefined1 *)(param_2 + 0xf66) = 0;
      *(short *)(param_2 + 0xf60) = (short)((*(ushort *)(param_2 + 0xf60) + 1) % (uint)bVar4);
      lVar13 = 0;
      *(uint *)(param_2 + 0xc30) = *param_1;
      *(undefined8 *)(param_2 + 0xc38) = *(undefined8 *)(param_1 + 2);
      SmfTraceStep(param_2,1,param_3,param_4);
    }
  }
  if (*param_1 == 0x7fffffff) {
    param_3 = (char *)((ulonglong)*(uint *)(param_2 + 0xc10) * 10);
    lVar13 = *(longlong *)(*(longlong *)(param_2 + 0xc08) + 0x18);
    cVar5 = *(char *)(*(longlong *)(lVar13 + 0x28 + (ulonglong)*(uint *)(param_2 + 0xc10) * 0x50) +
                      0x58 + (ulonglong)*(uint *)(param_2 + 0xc20) * 0x60);
    *(char *)(param_2 + 0xc48) = cVar5;
    if ((cVar5 == '\0') && (*(int *)(param_2 + 4000) == 0)) {
      bVar10 = true;
    }
  }
  uVar14 = CONCAT71((int7)((ulonglong)lVar13 >> 8),*(undefined1 *)(param_2 + 0xfb0));
  KeReleaseSpinLock(param_2 + 0xfa8);
  if (bVar10) {
    SmfDelete(param_2,uVar14,param_3,param_4);
  }
  return param_1;
}



===== SmfDereference @ 1c0014a4c =====

void SmfDereference(ulonglong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar4 = param_1 ^ 0x11;
  if (*(int *)(uVar4 + 0xc04) != 0x7dc) {
    param_2 = 0;
    SmfReportException(2,0);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(uVar4 + 0xfa8);
  *(int *)(uVar4 + 4000) = *(int *)(uVar4 + 4000) + -1;
  iVar1 = *(int *)(uVar4 + 4000);
  uVar3 = CONCAT71((int7)((ulonglong)param_2 >> 8),uVar2);
  *(undefined1 *)(uVar4 + 0xfb0) = uVar2;
  KeReleaseSpinLock(uVar4 + 0xfa8);
  if (iVar1 < 0) {
    SmfReportException(2,uVar4);
  }
  else if (iVar1 == 0) {
    SmfDelete(uVar4,uVar3,param_3,param_4);
  }
  return;
}



===== SmfEnqueueEvent @ 1c0014ae8 =====

void SmfEnqueueEvent(ulonglong param_1,uint param_2,char *param_3,char *param_4)

{
  SmfEnqueueEventCommon(param_1,param_2,param_3,param_4);
  return;
}



===== SmfEnqueueEventCommon @ 1c0014b00 =====

void SmfEnqueueEventCommon(ulonglong param_1,uint param_2,char *param_3,char *param_4)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 uVar4;
  byte bVar5;
  ushort uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  short sVar9;
  uint uVar10;
  ulonglong uVar11;
  
  uVar11 = param_1 ^ 0x11;
  if (*(int *)(uVar11 + 0xc04) != 0x7dc) {
    SmfReportException(2,0);
  }
  uVar2 = *(ushort *)
           (*(longlong *)(*(longlong *)(uVar11 + 0xc08) + 8) + 0x10 + (ulonglong)param_2 * 0x18);
  uVar4 = KeAcquireSpinLockRaiseToDpc(uVar11 + 0xfa8);
  *(undefined1 *)(uVar11 + 0xfb0) = uVar4;
  if (*(int *)(uVar11 + 0xfcc) == 0) {
LAB_1c0014bc0:
    if (*(char *)(uVar11 + 0xf66) != '\0') {
      bVar5 = SmfResizeEventQueue(uVar11);
      SmfTraceStep(uVar11,10,param_3,param_4);
      if (bVar5 == 0) {
        uVar4 = *(undefined1 *)(uVar11 + 0xfb0);
        goto LAB_1c0014b9f;
      }
    }
    if ((*(int *)(uVar11 + 0xfd0) != 0) && (uVar2 != 0xffff)) {
      uVar6 = *(ushort *)(uVar11 + 0xf60);
      uVar7 = (ulonglong)uVar6;
      param_3 = (char *)0x0;
      uVar3 = *(ushort *)(uVar11 + 0xf62);
      param_4 = (char *)(ulonglong)uVar3;
      if (uVar3 < uVar6) {
        if ((uint)uVar6 < (uint)*(byte *)(uVar11 + 0xf68)) {
          do {
            uVar10 = (int)uVar7 + 1;
            uVar6 = (ushort)param_3 + 1;
            if (*(uint *)(*(longlong *)(uVar11 + 0xf58) + uVar7 * 0x10) != param_2) {
              uVar6 = (ushort)param_3;
            }
            param_3 = (char *)(ulonglong)uVar6;
            uVar7 = (ulonglong)uVar10;
          } while (uVar10 < *(byte *)(uVar11 + 0xf68));
        }
        uVar7 = 0;
        uVar6 = 0;
      }
      if (uVar6 < uVar3) {
        do {
          uVar10 = (int)uVar7 + 1;
          uVar6 = (ushort)param_3 + 1;
          if (*(uint *)(*(longlong *)(uVar11 + 0xf58) + uVar7 * 0x10) != param_2) {
            uVar6 = (ushort)param_3;
          }
          param_3 = (char *)(ulonglong)uVar6;
          uVar7 = (ulonglong)uVar10;
        } while (uVar10 < uVar3);
      }
      if (uVar2 <= (ushort)param_3) {
        KeReleaseSpinLock(uVar11 + 0xfa8,*(undefined1 *)(uVar11 + 0xfb0));
        uVar8 = 3;
        goto LAB_1c0014bb3;
      }
    }
    uVar2 = *(ushort *)(uVar11 + 0xf62);
    *(uint *)(*(longlong *)(uVar11 + 0xf58) + (ulonglong)uVar2 * 0x10) = param_2;
    *(undefined8 *)(*(longlong *)(uVar11 + 0xf58) + 8 + (ulonglong)uVar2 * 0x10) = 0;
    *(short *)(uVar11 + 0xf64) = *(short *)(uVar11 + 0xf64) + 1;
    sVar9 = (short)((uVar2 + 1) % (uint)*(byte *)(uVar11 + 0xf68));
    *(short *)(uVar11 + 0xf62) = sVar9;
    *(bool *)(uVar11 + 0xf66) = sVar9 == *(short *)(uVar11 + 0xf60);
    SmfTraceStep(uVar11,0,param_3,param_4);
    cVar1 = *(char *)(uVar11 + 0xc48);
    *(undefined1 *)(uVar11 + 0xc48) = 1;
    KeReleaseSpinLock(uVar11 + 0xfa8);
    if (cVar1 == '\0') {
      SmfRunStateMachine(uVar11,'\0',param_3,param_4);
    }
  }
  else {
    param_4 = *(char **)(*(longlong *)(uVar11 + 0xc08) + 0x18);
    param_3 = (char *)(ulonglong)(byte)param_4[(ulonglong)*(uint *)(uVar11 + 0xc10) * 0x50 + 0x30];
    if (*(ushort *)(uVar11 + 0xf64) !=
        (ushort)(byte)param_4[(ulonglong)*(uint *)(uVar11 + 0xc10) * 0x50 + 0x30])
    goto LAB_1c0014bc0;
LAB_1c0014b9f:
    KeReleaseSpinLock(uVar11 + 0xfa8,uVar4);
    uVar8 = 6;
LAB_1c0014bb3:
    SmfReportException(uVar8,uVar11);
  }
  return;
}



===== SmfFreeAttributes @ 1c0014d5c =====

void SmfFreeAttributes(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    ExFreePool();
  }
  ExFreePool(param_1);
  return;
}



===== SmfFreeSMContext @ 1c0014d98 =====

void SmfFreeSMContext(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  short sVar1;
  
  for (sVar1 = *(short *)(param_1 + 0xf50); sVar1 != 0; sVar1 = sVar1 + -1) {
    SmfPopState(param_1,'\x01',param_3,param_4);
  }
  if (*(longlong *)(param_1 + 0xf88) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xf78) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xf58) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xf98) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xf80) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xf70) != 0) {
    ExFreePool();
  }
  if (*(longlong *)(param_1 + 0xc18) != 0) {
    ExFreePool();
  }
  ExFreePool(param_1);
  return;
}



===== SmfInitAttributes @ 1c0014e98 =====

void SmfInitAttributes(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  uVar1 = *(uint *)(PTR_MachineTable_1c001d7a0 + 0x10);
  *param_1 = &DriverDecl_PortDetector;
  param_1[3] = param_5;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[4] = param_2;
  if (uVar1 != 0) {
    lVar3 = 0;
    lVar4 = 0;
    uVar5 = (ulonglong)uVar1;
    do {
      iVar2 = *(int *)(*(longlong *)(PTR_MachineTable_1c001d7a0 + 0x18) + 0x10 + lVar4);
      if (iVar2 == -4) {
LAB_1c0014ef4:
        *(undefined8 *)(lVar3 + param_1[2]) = 0;
      }
      else if (iVar2 == -3) {
        *(undefined8 *)(lVar3 + param_1[2]) = 0x7fffffff;
      }
      else if ((iVar2 == -2) || (iVar2 == -1)) goto LAB_1c0014ef4;
      lVar4 = lVar4 + 0x18;
      lVar3 = lVar3 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}



===== SmfIsCallTransition @ 1c0014f20 =====

undefined8 SmfIsCallTransition(longlong param_1,int param_2)

{
  ushort *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 uVar4;
  
  piVar2 = *(int **)(*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                    (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
  uVar4 = 0;
  uVar3 = 0;
  puVar1 = (ushort *)(piVar2 + (ulonglong)*(uint *)(param_1 + 0xc20) * 0x18 + 0xb);
  if (*puVar1 != 0) {
    piVar2 = (int *)(*(longlong *)(piVar2 + (ulonglong)*(uint *)(param_1 + 0xc20) * 0x18 + 0xc) +
                    0xc);
    do {
      if (((char)piVar2[2] != '\0') && (*piVar2 == param_2)) {
        uVar4 = 1;
        break;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 6;
    } while (uVar3 < *puVar1);
  }
  return CONCAT71((int7)((ulonglong)piVar2 >> 8),uVar4);
}



===== SmfPopState @ 1c0014f90 =====

void SmfPopState(longlong param_1,char param_2,undefined8 param_3,longlong param_4)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  short sStack_20;
  undefined4 uStack_1c;
  
  uVar10 = **(uint **)(param_1 + 0xc08);
  if ((uVar10 == 0) || ((uVar10 & 0x1f) != 0)) {
    uVar10 = (uint)(ushort)((short)(uVar10 >> 5) + 1);
  }
  else {
    uVar10 = uVar10 >> 5;
  }
  uVar11 = (ulonglong)*(ushort *)(param_1 + 0xf50);
  *(ushort *)(param_1 + 0xf50) = *(ushort *)(param_1 + 0xf50) - 1;
  puVar1 = (undefined8 *)(param_1 + 0xc30 + uVar11 * 0x30);
  uVar8 = *puVar1;
  uVar9 = puVar1[1];
  plVar2 = (longlong *)(param_1 + 0xc40 + uVar11 * 0x30);
  lVar6 = *plVar2;
  lVar7 = plVar2[1];
  puVar3 = (undefined4 *)(param_1 + 0xc20 + uVar11 * 0x30);
  uVar4 = *puVar3;
  uVar5 = puVar3[2];
  *(undefined4 *)(param_1 + 0xc20) = uVar4;
  if ((short)uVar10 != 0) {
    uVar11 = (ulonglong)uVar10 & 0xffff;
    param_4 = 0;
    do {
      *(undefined4 *)(param_4 + *(longlong *)(param_1 + 0xf70)) =
           *(undefined4 *)((lVar6 - lVar7) + param_4 + lVar7);
      *(undefined4 *)(param_4 + *(longlong *)(param_1 + 0xf80)) = *(undefined4 *)(param_4 + lVar7);
      param_4 = param_4 + 4;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  ExFreePool(lVar6,uVar4,(int)lVar6,param_4,uVar4);
  ExFreePool(lVar7);
  sStack_20 = (short)uVar9;
  if (param_2 == '\0') {
    if (sStack_20 != -1) {
      SmfReportException(5,param_1);
    }
    *(undefined4 *)(param_1 + 0xc44) = 1;
    *(undefined2 *)(param_1 + 0xc40) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xc30) = uVar5;
    *(undefined8 *)(param_1 + 0xc38) = uVar8;
    *(short *)(param_1 + 0xc40) = sStack_20;
    uStack_1c = (undefined4)((ulonglong)uVar9 >> 0x20);
    *(undefined4 *)(param_1 + 0xc44) = uStack_1c;
  }
  return;
}



===== SmfPushState @ 1c0015108 =====

void SmfPushState(longlong param_1)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  
  lVar11 = 0;
  uVar6 = **(uint **)(param_1 + 0xc08);
  if ((uVar6 == 0) || ((uVar6 & 0x1f) != 0)) {
    uVar6 = (uint)(ushort)((short)(uVar6 >> 5) + 1);
  }
  else {
    uVar6 = uVar6 >> 5;
  }
  uVar3 = *(ushort *)(param_1 + 0xf50);
  uVar8 = (ulonglong)uVar3;
  lVar9 = *(longlong *)(*(uint **)(param_1 + 0xc08) + 6);
  lVar7 = (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60;
  lVar4 = *(longlong *)(lVar9 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
  lVar10 = *(longlong *)(lVar7 + 0x38 + lVar4);
  lVar9 = *(longlong *)
           (*(longlong *)(lVar9 + 0x38 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x10 +
           (ulonglong)*(uint *)(lVar7 + 0x28 + lVar4) * 0x18);
  lVar4 = *(longlong *)(lVar7 + 0x50 + lVar4);
  *(uint *)(param_1 + 0xc50 + uVar8 * 0x30) = *(uint *)(param_1 + 0xc20);
  *(undefined4 *)(param_1 + 0xc58 + uVar8 * 0x30) = *(undefined4 *)(param_1 + 0xc30);
  *(undefined8 *)(param_1 + (uVar8 + 0x42) * 0x30) = *(undefined8 *)(param_1 + 0xc38);
  *(undefined2 *)(param_1 + 0xc68 + uVar8 * 0x30) = *(undefined2 *)(param_1 + 0xc40);
  *(undefined4 *)(param_1 + 0xc6c + uVar8 * 0x30) = *(undefined4 *)(param_1 + 0xc44);
  uVar5 = SmfClonePackedSet(*(longlong *)(param_1 + 0xf70),uVar6 & 0xffff);
  *(undefined8 *)(param_1 + 0xc70 + uVar8 * 0x30) = uVar5;
  uVar5 = SmfClonePackedSet(*(longlong *)(param_1 + 0xf80),uVar6 & 0xffff);
  *(undefined8 *)(param_1 + 0xc78 + uVar8 * 0x30) = uVar5;
  *(ushort *)(param_1 + 0xf50) = uVar3 + 1;
  if ((short)uVar6 != 0) {
    lVar9 = lVar9 - lVar4;
    uVar8 = (ulonglong)(uVar6 & 0xffff);
    lVar10 = lVar10 - lVar4;
    do {
      puVar1 = (uint *)(lVar11 + lVar4);
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf80));
      *puVar2 = *puVar2 & ~*(uint *)((longlong)puVar1 + lVar9);
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf80));
      *puVar2 = *puVar2 | *puVar1;
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf80));
      *puVar2 = *puVar2 & ~*(uint *)((longlong)puVar1 + lVar10);
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf70));
      *puVar2 = *puVar2 | *(uint *)((longlong)puVar1 + lVar9);
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf70));
      *puVar2 = *puVar2 & ~*puVar1;
      puVar2 = (uint *)(lVar11 + *(longlong *)(param_1 + 0xf70));
      *puVar2 = *puVar2 & ~*(uint *)((longlong)puVar1 + lVar10);
      lVar11 = lVar11 + 4;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  return;
}



===== SmfRaise @ 1c00152dc =====

void SmfRaise(longlong param_1,undefined4 param_2,char *param_3,undefined8 param_4)

{
  *(undefined8 *)(param_1 + 0xc38) = 0;
  *(undefined4 *)(param_1 + 0xc30) = param_2;
  *(undefined4 *)(param_1 + 0xf90) = 1;
  SmfTraceStep(param_1,4,param_3,param_4);
  return;
}



===== SmfReadRegistry @ 1c0015310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SmfReadRegistry(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined **ppuVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  longlong lVar9;
  longlong lVar10;
  longlong local_res8;
  longlong local_res10;
  
  local_res8 = 0;
  puVar4 = (undefined8 *)(param_1 + 0xfc8);
  local_res10 = 0;
  *puVar4 = 0;
  *(undefined4 *)(param_1 + 0xfd0) = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x138))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0xfb8));
  uVar7 = 0x20019;
  uVar3 = WdfDriverGlobals;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))(WdfDriverGlobals,uVar2,0x20019,0,&local_res8);
  lVar10 = 3;
  if (iVar1 < 0) {
    if ((Microsoft_WindowsPhone_UfxEnableBits & 0x10) != 0) {
      McTemplateK0ss_EtwWriteTransfer
                (uVar3,&DebugMessage,uVar7,"SmfReadRegistry","Failed to open driver registry key!");
    }
  }
  else {
    puVar8 = &StrSmf;
    uVar3 = WdfDriverGlobals;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                      (WdfDriverGlobals,local_res8,&StrSmf,0x20019,0,&local_res10);
    if (iVar1 < 0) {
      if ((Microsoft_WindowsPhone_UfxEnableBits & 0x10) != 0) {
        McTemplateK0ss_EtwWriteTransfer
                  (uVar3,&DebugMessage,puVar8,"SmfReadRegistry","Failed to open smf registry key!");
      }
    }
    else {
      ppuVar5 = &PTR_StrVerifyEventHandlers_1c00190c8;
      lVar9 = 3;
      puVar6 = puVar4;
      do {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                          (WdfDriverGlobals,local_res10,*ppuVar5,puVar4);
        if (iVar1 < 0) {
          *(undefined4 *)puVar6 = 0;
        }
        puVar4 = (undefined8 *)((longlong)puVar4 + 4);
        puVar6 = (undefined8 *)((longlong)puVar6 + 4);
        ppuVar5 = ppuVar5 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    iVar1 = 0;
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  do {
    if ((Microsoft_WindowsPhone_UfxEnableBits & 0x10) != 0) {
      McTemplateK0ssq_EtwWriteTransfer();
    }
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  return iVar1;
}



===== SmfRemoveMachine @ 1c0015524 =====

void SmfRemoveMachine(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  IoFreeWorkItem(*(undefined8 *)(param_1 + 0xfc0));
  if (**(char **)(param_1 + 0xf98) != '\0') {
    ExFreePool(*(undefined8 *)(*(char **)(param_1 + 0xf98) + 8));
  }
  SmfFreeSMContext(param_1,param_2,param_3,param_4);
  return;
}



===== SmfResizeEventQueue @ 1c0015574 =====

byte SmfResizeEventQueue(longlong param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  byte bVar14;
  ushort uVar15;
  ulonglong uVar16;
  
  bVar2 = *(byte *)(param_1 + 0xf68);
  puVar5 = *(undefined4 **)(param_1 + 0xf58);
  uVar3 = *(ushort *)(param_1 + 0xf60);
  bVar14 = 0;
  uVar4 = *(ushort *)(param_1 + 0xf62);
  uVar16 = (ulonglong)uVar4;
  uVar15 = 0;
  if (bVar2 != 0xff) {
    if (bVar2 < 0x80) {
      bVar14 = bVar2 * '\x02';
    }
    else {
      bVar14 = 0xff;
    }
    lVar10 = ExAllocatePool2(0x40,(ulonglong)bVar14 << 4,0x31676154);
    if (lVar10 == 0) {
      bVar14 = 0;
    }
    else {
      if (uVar3 < bVar2) {
        puVar12 = puVar5 + (ulonglong)uVar3 * 4;
        uVar13 = (ulonglong)(ushort)(bVar2 - uVar3);
        do {
          uVar6 = *puVar12;
          uVar7 = puVar12[1];
          uVar8 = puVar12[2];
          uVar9 = puVar12[3];
          uVar11 = (ulonglong)uVar15;
          puVar12 = puVar12 + 4;
          uVar15 = uVar15 + 1;
          puVar1 = (undefined4 *)(lVar10 + uVar11 * 0x10);
          *puVar1 = uVar6;
          puVar1[1] = uVar7;
          puVar1[2] = uVar8;
          puVar1[3] = uVar9;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      if (uVar4 != 0) {
        puVar12 = puVar5;
        do {
          uVar6 = *puVar12;
          uVar7 = puVar12[1];
          uVar8 = puVar12[2];
          uVar9 = puVar12[3];
          uVar13 = (ulonglong)uVar15;
          puVar12 = puVar12 + 4;
          uVar15 = uVar15 + 1;
          puVar1 = (undefined4 *)(lVar10 + uVar13 * 0x10);
          *puVar1 = uVar6;
          puVar1[1] = uVar7;
          puVar1[2] = uVar8;
          puVar1[3] = uVar9;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
      }
      *(longlong *)(param_1 + 0xf58) = lVar10;
      *(undefined2 *)(param_1 + 0xf60) = 0;
      *(ushort *)(param_1 + 0xf62) = uVar15;
      *(undefined1 *)(param_1 + 0xf66) = 0;
      *(byte *)(param_1 + 0xf68) = bVar14;
      ExFreePool(puVar5);
    }
  }
  return bVar14;
}



===== SmfRunStateMachine @ 1c00156c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmfRunStateMachine(longlong param_1,char param_2,char *param_3,char *param_4)

{
  uint *puVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  undefined4 uVar6;
  uint *puVar7;
  undefined8 uVar8;
  int *piVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  longlong lVar13;
  uint uVar14;
  longlong lVar15;
  char *pcVar16;
  uint uVar17;
  ulonglong uVar18;
  bool bVar19;
  uint local_88 [28];
  
  bVar19 = param_2 == '\0';
LAB_1c00156f4:
  if (!bVar19) goto LAB_1c0015890;
LAB_1c00156fa:
  puVar7 = SmfDequeueEvent(local_88,param_1,param_3,(longlong)param_4);
  uVar17 = *puVar7;
  if (uVar17 == 0x7fffffff) {
    if (*(char *)(*(longlong *)
                   (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                   (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x58 +
                 (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) == '\0') {
      return;
    }
    *(undefined4 *)(param_1 + 0xc30) = 0x7ffffffe;
    *(undefined8 *)(param_1 + 0xc38) = 0;
  }
  else {
    uVar8 = SmfIsCallTransition(param_1,uVar17);
    if ((char)uVar8 != '\0') goto LAB_1c0015e9c;
    lVar13 = *(longlong *)
              (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
              (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
    uVar12 = (ulonglong)(*(uint *)(param_1 + 0xc30) >> 5);
    uVar14 = 1 << ((byte)*(uint *)(param_1 + 0xc30) & 0x1f);
    param_3 = (char *)(ulonglong)uVar14;
    if ((*(uint *)(*(longlong *)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 0x38 + lVar13) +
                  uVar12 * 4) & uVar14) == 0) {
      if ((*(uint *)(*(longlong *)(param_1 + 0xf88) + uVar12 * 4) & uVar14) != 0) {
        *(undefined4 *)(param_1 + 0xc44) = 2;
        goto LAB_1c0015888;
      }
      if (*(ushort *)(param_1 + 0xf50) != 0) {
        param_4 = (char *)((ulonglong)(uint)*(ushort *)(param_1 + 0xf50) - 1);
        puVar7 = (uint *)((longlong)param_4 * 0x30 + 0xc50 + param_1);
        do {
          if ((short)puVar7[6] != -1) break;
          param_3 = (char *)(ulonglong)(uVar17 >> 5);
          if ((*(uint *)(*(longlong *)((ulonglong)*puVar7 * 0x60 + 0x38 + lVar13) +
                        (longlong)param_3 * 4) & 1 << ((byte)uVar17 & 0x1f)) != 0)
          goto LAB_1c0015881;
          puVar7 = puVar7 + -0xc;
          param_4 = param_4 + -1;
        } while (-1 < (longlong)param_4);
      }
      if (*(int *)(param_1 + 0xfc8) == 0) {
        if ((Microsoft_WindowsPhone_UfxEnableBits & 0x10) != 0) {
          param_4 = "SmfRunStateMachine";
          McTemplateK0ssq_EtwWriteTransfer();
        }
        goto LAB_1c00156fa;
      }
      SmfReportException(0,param_1);
    }
  }
LAB_1c0015881:
  *(undefined4 *)(param_1 + 0xc44) = 1;
LAB_1c0015888:
  do {
    *(undefined2 *)(param_1 + 0xc40) = 0;
LAB_1c0015890:
    uVar17 = **(uint **)(param_1 + 0xc08);
    if ((uVar17 == 0) || ((uVar17 & 0x1f) != 0)) {
      uVar17 = (uVar17 >> 5) + 1;
    }
    else {
      uVar17 = uVar17 >> 5;
    }
    lVar13 = *(longlong *)(*(uint **)(param_1 + 0xc08) + 6);
    uVar12 = (ulonglong)*(uint *)(param_1 + 0xc10);
    uVar18 = (ulonglong)*(uint *)(param_1 + 0xc20);
    lVar11 = uVar18 * 0x60;
    lVar15 = *(longlong *)(lVar13 + 0x28 + uVar12 * 0x50);
    lVar3 = *(longlong *)(lVar11 + 0x50 + lVar15);
    lVar4 = *(longlong *)(lVar11 + 0x38 + lVar15);
    lVar13 = *(longlong *)
              (*(longlong *)(lVar13 + 0x38 + uVar12 * 0x50) + 0x10 +
              (ulonglong)*(uint *)(lVar11 + 0x28 + lVar15) * 0x18);
    if ((uVar17 & 0xffff) != 0) {
      lVar15 = 0;
      uVar12 = (ulonglong)(uVar17 & 0xffff);
      do {
        puVar7 = (uint *)(lVar15 + lVar3);
        *(uint *)(lVar15 + *(longlong *)(param_1 + 0xf88)) =
             ~*(uint *)((lVar13 - lVar3) + (longlong)puVar7) &
             *(uint *)(lVar15 + *(longlong *)(param_1 + 0xf80));
        puVar1 = (uint *)(lVar15 + *(longlong *)(param_1 + 0xf88));
        *puVar1 = *puVar1 | *puVar7;
        puVar1 = (uint *)(lVar15 + *(longlong *)(param_1 + 0xf88));
        *puVar1 = *puVar1 & ~*(uint *)((lVar4 - lVar3) + (longlong)puVar7);
        lVar15 = lVar15 + 4;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
      uVar12 = (ulonglong)*(uint *)(param_1 + 0xc10);
      uVar18 = (ulonglong)*(uint *)(param_1 + 0xc20);
    }
    uVar17 = **(uint **)(param_1 + 0xc08);
    if ((uVar17 == 0) || ((uVar17 & 0x1f) != 0)) {
      uVar17 = (uVar17 >> 5) + 1;
    }
    else {
      uVar17 = uVar17 >> 5;
    }
    param_4 = (char *)(ulonglong)uVar17;
    lVar13 = *(longlong *)(*(uint **)(param_1 + 0xc08) + 6);
    puVar7 = (uint *)(uVar12 * 10);
    lVar15 = *(longlong *)(lVar13 + 0x28 + uVar12 * 0x50);
    lVar11 = uVar18 * 0x60;
    lVar3 = *(longlong *)(lVar11 + 0x50 + lVar15);
    lVar4 = *(longlong *)(lVar11 + 0x38 + lVar15);
    lVar13 = *(longlong *)
              (*(longlong *)(lVar13 + 0x38 + uVar12 * 0x50) + 0x10 +
              (ulonglong)*(uint *)(lVar11 + 0x28 + lVar15) * 0x18);
    uVar12 = (ulonglong)param_4 & 0xffff;
    if ((int)uVar12 != 0) {
      param_4 = (char *)0x0;
      do {
        puVar7 = (uint *)(param_4 + lVar3);
        *(uint *)(param_4 + *(longlong *)(param_1 + 0xf78)) =
             *(uint *)(param_4 + *(longlong *)(param_1 + 0xf70)) |
             *(uint *)((lVar13 - lVar3) + (longlong)puVar7);
        *(uint *)(param_4 + *(longlong *)(param_1 + 0xf78)) =
             *(uint *)(param_4 + *(longlong *)(param_1 + 0xf78)) & ~*puVar7;
        *(uint *)(param_4 + *(longlong *)(param_1 + 0xf78)) =
             *(uint *)(param_4 + *(longlong *)(param_1 + 0xf78)) &
             ~*(uint *)((lVar4 - lVar3) + (longlong)puVar7);
        param_4 = param_4 + 4;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    if (*(int *)(param_1 + 0xc44) == 0) {
      if (*(short *)(param_1 + 0xc40) == 0) {
        SmfTraceStep(param_1,2,(char *)puVar7,param_4);
      }
      if (((*(uint *)(*(longlong *)
                       (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                       (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x10 +
                     (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) & 1) != 0) &&
         (cVar5 = KeGetCurrentIrql(), cVar5 != '\0')) goto LAB_1c0016127;
      *(undefined4 *)(param_1 + 0xf90) = 3;
      param_3 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
      (**(code **)(*(longlong *)
                    (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                    (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x18 +
                  (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60))(param_1);
      iVar10 = *(int *)(param_1 + 0xf90);
      if (iVar10 != 0) {
        if (iVar10 != 1) {
          if (iVar10 != 2) goto LAB_1c00156fa;
          *(undefined4 *)(param_1 + 0xc44) = 0;
          goto LAB_1c0015888;
        }
        uVar17 = *(uint *)(param_1 + 0xc30);
        uVar14 = 1 << ((byte)uVar17 & 0x1f);
        param_4 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
        param_3 = *(char **)(*(longlong *)(param_1 + 0xc08) + 0x18);
        if ((*(uint *)(*(longlong *)
                        (*(longlong *)
                          (param_3 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50 + 0x28) + 0x38 +
                        (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) + (ulonglong)(uVar17 >> 5) * 4
                      ) & uVar14) == 0) {
          uVar17 = *(uint *)(*(longlong *)(param_1 + 0xf88) + (ulonglong)(uVar17 >> 5) * 4);
          *(undefined2 *)(param_1 + 0xc40) = 0;
          *(uint *)(param_1 + 0xc44) = ((uVar14 & uVar17) != 0) + 1;
          goto LAB_1c0015890;
        }
        uVar8 = SmfIsCallTransition(param_1,uVar17);
        if ((char)uVar8 != '\0') goto LAB_1c0015e9c;
      }
      *(undefined4 *)(param_1 + 0xc44) = 1;
      goto LAB_1c0015888;
    }
    lVar13 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
    if (*(int *)(param_1 + 0xc44) == 1) {
      if (((*(uint *)(*(longlong *)(lVar13 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) +
                      0x10 + (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) & 2) != 0) &&
         (cVar5 = KeGetCurrentIrql(), cVar5 != '\0')) goto LAB_1c0016127;
      *(undefined4 *)(param_1 + 0xf90) = 3;
      param_3 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
      if (*(longlong *)
           (*(longlong *)
             (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
             (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x20 +
           (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) != 0) {
        if (*(short *)(param_1 + 0xc40) == 0) {
          SmfTraceStep(param_1,0xb,param_3,param_4);
        }
        param_3 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
        (**(code **)(*(longlong *)
                      (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                      (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50) + 0x20 +
                    (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60))(param_1);
      }
      if (*(int *)(param_1 + 0xf90) == 2) {
        *(undefined4 *)(param_1 + 0xc44) = 0;
        goto LAB_1c0015888;
      }
      if (*(int *)(param_1 + 0xf90) != 3) goto LAB_1c00156fa;
LAB_1c0015e9c:
      iVar10 = *(int *)(param_1 + 0xc30);
      if (iVar10 == 0x7fffffff) {
        SmfPopState(param_1,'\x01',param_3,(longlong)param_4);
        uVar6 = *(undefined4 *)(param_1 + 0xc20);
        *(undefined4 *)(param_1 + 8 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 0x7fffffff;
        *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = uVar6;
        *(undefined4 *)(param_1 + 4 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 2;
        *(char *)(param_1 + 0xc00) = *(char *)(param_1 + 0xc00) + '\x01';
        SmfTraceStep(param_1,5,param_3,param_4);
        bVar19 = *(short *)(param_1 + 0xc40) == -1;
        goto LAB_1c00156f4;
      }
      lVar13 = *(longlong *)
                (*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
      lVar15 = (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60;
      uVar17 = 0;
      uVar2 = *(ushort *)(lVar13 + 0x2c + lVar15);
      pcVar16 = (char *)(ulonglong)uVar2;
      uVar14 = (uint)uVar2;
      if (iVar10 == 0x7ffffffe) {
        lVar13 = *(longlong *)(lVar13 + 0x30 + lVar15);
        if (uVar14 != 0) {
          piVar9 = (int *)(lVar13 + 0xc);
          do {
            if (*piVar9 == 0x7ffffffe) {
              uVar12 = (ulonglong)uVar17;
              uVar6 = *(undefined4 *)(lVar13 + 0x10 + uVar12 * 0x18);
              *(undefined4 *)(param_1 + 8 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) =
                   0x7ffffffe;
              *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = uVar6;
              *(undefined4 *)(param_1 + 4 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 0;
              *(char *)(param_1 + 0xc00) = *(char *)(param_1 + 0xc00) + '\x01';
              if (*(char *)(lVar13 + 0x14 + uVar12 * 0x18) != '\0') {
                *(undefined2 *)(param_1 + 0xc40) = 0xffff;
                SmfPushState(param_1);
              }
              uVar6 = *(undefined4 *)(lVar13 + 0x10 + uVar12 * 0x18);
LAB_1c0015fd4:
              *(undefined4 *)(param_1 + 0xc20) = uVar6;
              goto LAB_1c0015e28;
            }
            uVar17 = uVar17 + 1;
            piVar9 = piVar9 + 6;
          } while (uVar17 < uVar14);
        }
      }
      else {
        lVar13 = *(longlong *)(lVar13 + 0x30 + lVar15);
        if (uVar14 != 0) {
          piVar9 = (int *)(lVar13 + 0xc);
          do {
            if (*piVar9 == iVar10) {
              uVar12 = (ulonglong)uVar17;
              uVar6 = *(undefined4 *)(lVar13 + 0x10 + uVar12 * 0x18);
              cVar5 = *(char *)(lVar13 + 0x14 + uVar12 * 0x18);
              *(int *)(param_1 + 8 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = iVar10;
              *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = uVar6;
              if (cVar5 == '\0') {
                *(undefined4 *)(param_1 + 4 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 0;
                *(char *)(param_1 + 0xc00) = *(char *)(param_1 + 0xc00) + '\x01';
              }
              else {
                *(undefined4 *)(param_1 + 4 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 3;
                *(char *)(param_1 + 0xc00) = *(char *)(param_1 + 0xc00) + '\x01';
                SmfTraceStep(param_1,7,pcVar16,param_4);
                *(undefined2 *)(param_1 + 0xc40) = 0xffff;
                SmfPushState(param_1);
              }
              uVar6 = *(undefined4 *)(lVar13 + 0x10 + uVar12 * 0x18);
              goto LAB_1c0015fd4;
            }
            uVar17 = uVar17 + 1;
            piVar9 = piVar9 + 6;
          } while (uVar17 < uVar14);
        }
        if (*(short *)(param_1 + 0xf50) == 0) {
          SmfReportException(0,param_1);
        }
        else {
          SmfPopState(param_1,'\0',pcVar16,(longlong)param_4);
          uVar6 = *(undefined4 *)(param_1 + 0xc20);
          *(int *)(param_1 + 8 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = iVar10;
          *(undefined4 *)(param_1 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = uVar6;
          *(undefined4 *)(param_1 + 4 + (ulonglong)*(byte *)(param_1 + 0xc00) * 0xc) = 4;
          *(char *)(param_1 + 0xc00) = *(char *)(param_1 + 0xc00) + '\x01';
          SmfTraceStep(param_1,8,pcVar16,param_4);
        }
      }
      goto LAB_1c0015890;
    }
    uVar17 = *(uint *)(param_1 + 0xc30);
    param_4 = (char *)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 +
                      *(longlong *)(lVar13 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50));
    param_3 = (char *)(ulonglong)(uVar17 >> 5);
    lVar13 = 0;
    if ((*(uint *)(*(longlong *)(param_4 + 0x50) + (longlong)param_3 * 4) >> ((byte)uVar17 & 0x1f) &
        1) != 0) {
      iVar10 = 0;
      if (*(ushort *)(param_4 + 0x40) != 0) {
        param_3 = (char *)(ulonglong)*(ushort *)(param_4 + 0x40);
        lVar15 = 0;
        puVar7 = (uint *)(*(longlong *)(param_4 + 0x48) + 0x18);
        do {
          if (*puVar7 == uVar17) {
            lVar13 = (longlong)iVar10 * 0x30 + *(longlong *)(param_4 + 0x48);
            goto LAB_1c0015dc1;
          }
          iVar10 = iVar10 + 1;
          lVar15 = lVar15 + 1;
          puVar7 = puVar7 + 0xc;
        } while (lVar15 < (longlong)param_3);
      }
    }
    param_4 = *(char **)(*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 0x28 +
                        (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
    if (-1 < (int)(*(ushort *)(param_1 + 0xf50) - 1)) {
      lVar15 = (ulonglong)*(ushort *)(param_1 + 0xf50) - 1;
      do {
        uVar12 = (ulonglong)*(uint *)(param_1 + 0xc50 + lVar15 * 0x30);
        param_3 = (char *)(uVar12 * 0x60);
        if ((*(uint *)(*(longlong *)(param_3 + 0x50 + (longlong)param_4) +
                      (ulonglong)(uVar17 >> 5) * 4) >> ((byte)uVar17 & 0x1f) & 1) != 0) {
          iVar10 = 0;
          lVar15 = 0;
          if (*(ushort *)(param_3 + 0x40 + (longlong)param_4) != 0) {
            puVar7 = (uint *)(*(longlong *)(param_3 + 0x48 + (longlong)param_4) + 0x18);
            do {
              if (*puVar7 == uVar17) {
                lVar13 = (longlong)iVar10 * 0x30 + *(longlong *)(param_4 + uVar12 * 0x60 + 0x48);
                goto LAB_1c0015dc1;
              }
              iVar10 = iVar10 + 1;
              lVar15 = lVar15 + 1;
              puVar7 = puVar7 + 0xc;
            } while (lVar15 < (longlong)(ulonglong)*(ushort *)(param_3 + 0x40 + (longlong)param_4));
          }
        }
        lVar15 = lVar15 + -1;
      } while (-1 < lVar15);
    }
LAB_1c0015dc1:
    if ((*(char *)(lVar13 + 0x28) != '\0') && (cVar5 = KeGetCurrentIrql(), cVar5 != '\0')) {
LAB_1c0016127:
      IoQueueWorkItemEx(*(undefined8 *)(param_1 + 0xfc0),SmfRunStateMachineWorkItemPassiveFlag,1,
                        param_1);
      return;
    }
    if (*(short *)(param_1 + 0xc40) == 0) {
      param_3 = *(char **)(lVar13 + 0x10);
      SmfTraceStep(param_1,9,param_3,param_4);
    }
    *(undefined4 *)(param_1 + 0xf90) = 3;
    (**(code **)(lVar13 + 0x20))(param_1);
    iVar10 = *(int *)(param_1 + 0xf90);
    if (iVar10 == 0) goto LAB_1c0015881;
    if (iVar10 == 1) {
      uVar17 = *(uint *)(param_1 + 0xc30);
      uVar14 = 1 << ((byte)uVar17 & 0x1f);
      param_4 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
      param_3 = *(char **)(*(longlong *)(param_1 + 0xc08) + 0x18);
      if ((*(uint *)(*(longlong *)
                      (*(longlong *)(param_3 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50 + 0x28)
                       + 0x38 + (ulonglong)*(uint *)(param_1 + 0xc20) * 0x60) +
                    (ulonglong)(uVar17 >> 5) * 4) & uVar14) != 0) {
        uVar8 = SmfIsCallTransition(param_1,uVar17);
        if ((char)uVar8 != '\0') goto LAB_1c0015e9c;
        goto LAB_1c0015881;
      }
      uVar17 = *(uint *)(*(longlong *)(param_1 + 0xf88) + (ulonglong)(uVar17 >> 5) * 4);
      *(undefined2 *)(param_1 + 0xc40) = 0;
      *(uint *)(param_1 + 0xc44) = ((uVar17 & uVar14) != 0) + 1;
      goto LAB_1c0015890;
    }
    if (iVar10 != 2) goto LAB_1c00156fa;
LAB_1c0015e28:
    *(undefined4 *)(param_1 + 0xc44) = 0;
  } while( true );
}



===== SmfRunStateMachineWorkItemPassiveFlag @ 1c0016170 =====

void SmfRunStateMachineWorkItemPassiveFlag
               (undefined8 param_1,longlong param_2,char *param_3,char *param_4)

{
  SmfRunStateMachine(param_2,'\x01',param_3,param_4);
  return;
}



===== McTemplateK0s_EtwWriteTransfer @ 1c001618c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0s_EtwWriteTransfer(void)

{
  longlong lVar1;
  char *in_R9;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (in_R9 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  local_1c = 0;
  local_28 = in_R9;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&UfxGuid_Context,&CreateMachine,&UfxGuid,2,local_38);
  return;
}



===== McTemplateK0sq_EtwWriteTransfer @ 1c001621c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_2c = 0;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_20 = 4;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer((undefined8 *)&UfxGuid_Context,param_2,&UfxGuid,3,local_48);
  return;
}



===== McTemplateK0ssp_EtwWriteTransfer @ 1c00162bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ssp_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  char *in_R9;
  char *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  if (in_R9 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  if (in_stack_00000028 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_28 = &uStack0000000000000030;
  local_2c = 0;
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  local_20 = 8;
  local_48 = in_R9;
  local_38 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer((undefined8 *)&UfxGuid_Context,&Dequeue,&UfxGuid,4,local_58);
  return;
}



===== McTemplateK0sss_EtwWriteTransfer @ 1c00163a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sss_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,char *param_5
               ,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  if (param_5 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_5[lVar2] != '\0');
    local_30 = (int)lVar2 + 1;
  }
  local_2c = 0;
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  if (param_6 == (char *)0x0) {
    local_20 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != '\0');
    local_20 = (int)lVar1 + 1;
  }
  local_1c = 0;
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  local_48 = param_4;
  local_38 = param_5;
  local_28 = param_6;
  McGenEventWrite_EtwWriteTransfer((undefined8 *)&UfxGuid_Context,param_2,&UfxGuid,4,local_58);
  return;
}



===== McTemplateK0sssp_EtwWriteTransfer @ 1c00164ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sssp_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  char *in_R9;
  char *in_stack_00000028;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  char *local_58;
  int local_50;
  undefined4 local_4c;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = -1;
  if (in_R9 == (char *)0x0) {
    local_50 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != '\0');
    local_50 = (int)lVar2 + 1;
  }
  local_4c = 0;
  if (in_R9 == (char *)0x0) {
    in_R9 = "NULL";
  }
  if (in_stack_00000028 == (char *)0x0) {
    local_40 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000028[lVar2] != '\0');
    local_40 = (int)lVar2 + 1;
  }
  local_3c = 0;
  if (in_stack_00000028 == (char *)0x0) {
    in_stack_00000028 = "NULL";
  }
  if (in_stack_00000030 == (char *)0x0) {
    local_30 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000030[lVar1] != '\0');
    local_30 = (int)lVar1 + 1;
  }
  local_28 = &uStack0000000000000038;
  local_2c = 0;
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  local_20 = 8;
  local_58 = in_R9;
  local_48 = in_stack_00000028;
  local_38 = in_stack_00000030;
  McGenEventWrite_EtwWriteTransfer((undefined8 *)&UfxGuid_Context,&Enqueue,&UfxGuid,5,local_68);
  return;
}



===== SmfReportException @ 1c00165c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SmfReportException(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (Microsoft_WindowsPhone_UfxEnableBits < '\0') {
    uVar1 = (ulonglong)*(uint *)(param_2 + 0xc10);
    McTemplateK0sq_EtwWriteTransfer
              (param_1,&MachineException,uVar1 * 10,
               *(char **)(*(longlong *)(*(longlong *)(param_2 + 0xc08) + 0x18) + 8 + uVar1 * 0x50),
               (char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0xb80))
            (WdfDriverGlobals,0x1000008e,
             *(undefined8 *)
              (*(longlong *)(*(longlong *)(param_2 + 0xc08) + 0x18) + 8 +
              (ulonglong)*(uint *)(param_2 + 0xc10) * 0x50),*(undefined8 *)(param_2 + 0xc28),
             (longlong)(int)param_1,0);
  return;
}



===== SmfTraceStep @ 1c001667c =====

void SmfTraceStep(longlong param_1,int param_2,char *param_3,undefined8 param_4)

{
  char *pcVar1;
  char *pcVar2;
  longlong lVar3;
  undefined *puVar4;
  char **ppcVar5;
  longlong lVar6;
  char *pcVar7;
  char *local_res18;
  undefined8 local_res20;
  char *pcVar8;
  
  ppcVar5 = &local_res18;
  local_res18 = param_3;
  local_res20 = param_4;
  if (param_2 < 7) {
    if (param_2 == 6) {
      if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
        return;
      }
      lVar3 = (ulonglong)*(uint *)(param_1 + 0xc10) * 10;
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
      pcVar2 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                         *(longlong *)(lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50))
      ;
      pcVar1 = "CallStatement";
    }
    else {
      if (param_2 == 0) {
joined_r0x0001c0016855:
        if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
          return;
        }
        McTemplateK0sssp_EtwWriteTransfer();
        return;
      }
      if (param_2 == 1) {
        if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
          return;
        }
        McTemplateK0ssp_EtwWriteTransfer();
        return;
      }
      if (param_2 == 2) {
        if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
          return;
        }
        lVar3 = (ulonglong)*(uint *)(param_1 + 0xc10) * 10;
        lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
        pcVar2 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                           *(longlong *)
                            (lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50));
        pcVar1 = "Transition";
      }
      else {
        if (param_2 == 3) {
          if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
            return;
          }
          McTemplateK0s_EtwWriteTransfer();
          return;
        }
        if (param_2 == 4) goto joined_r0x0001c0016855;
        if (param_2 != 5) {
          return;
        }
        if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
          return;
        }
        lVar3 = (ulonglong)*(uint *)(param_1 + 0xc10) * 10;
        lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
        pcVar2 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                           *(longlong *)
                            (lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50));
        pcVar1 = "Pop";
      }
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (param_2 == 9) {
          if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
            return;
          }
          puVar4 = &Action;
          pcVar1 = (char *)((ulonglong)*(uint *)(param_1 + 0xc10) * 10);
          pcVar2 = *(char **)(*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 8 +
                             (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
          pcVar8 = param_3;
        }
        else {
          if (param_2 == 10) {
            if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
              return;
            }
            McTemplateK0sq_EtwWriteTransfer
                      ((ulonglong)*(uint *)(param_1 + 0xc10) * 10,&QueueResize,ppcVar5,
                       *(char **)(*(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18) + 8 +
                                 (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50),
                       *(undefined1 *)(param_1 + 0xf68));
            return;
          }
          if (param_2 != 0xb) {
            return;
          }
          if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
            return;
          }
          lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
          pcVar2 = *(char **)(lVar6 + 8 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
          puVar4 = &Exit;
          pcVar1 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                             *(longlong *)
                              (lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50));
          pcVar8 = pcVar1;
        }
        McTemplateK0ss_EtwWriteTransfer(pcVar1,puVar4,ppcVar5,pcVar2,pcVar8);
        return;
      }
      if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
        return;
      }
      lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
      pcVar2 = *(char **)(*(longlong *)(param_1 + 0xc08) + 8);
      ppcVar5 = (char **)((ulonglong)*(uint *)(param_1 + 0xc30) * 3);
      pcVar8 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                         *(longlong *)(lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50))
      ;
      puVar4 = &Unhandled;
      pcVar7 = *(char **)(lVar6 + 8 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50);
      pcVar1 = *(char **)(pcVar2 + (ulonglong)*(uint *)(param_1 + 0xc30) * 0x18 + 8);
      goto LAB_1c0016ae4;
    }
    if ((Microsoft_WindowsPhone_UfxEnableBits & 0x40) == 0) {
      return;
    }
    lVar3 = (ulonglong)*(uint *)(param_1 + 0xc10) * 10;
    lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xc08) + 0x18);
    pcVar2 = *(char **)((ulonglong)*(uint *)(param_1 + 0xc20) * 0x60 + 8 +
                       *(longlong *)(lVar6 + 0x28 + (ulonglong)*(uint *)(param_1 + 0xc10) * 0x50));
    pcVar1 = "CallTransition";
  }
  pcVar7 = *(char **)(lVar6 + 8 + lVar3 * 8);
  puVar4 = &Transition;
  pcVar8 = pcVar2;
LAB_1c0016ae4:
  McTemplateK0sss_EtwWriteTransfer(pcVar2,puVar4,ppcVar5,pcVar7,pcVar1,pcVar8);
  return;
}



===== CsNotifyWnfCallback @ 1c0016b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CsNotifyWnfCallback(void)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  longlong local_30;
  longlong lStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_34 = 0;
  local_38 = 0x18;
  local_30 = 0;
  lStack_28 = 0;
  local_20 = 0;
  iVar1 = ExQueryWnfStateData(0,&local_34,&local_30,&local_38);
  if (-1 < iVar1) {
    if ((local_30 == 0x44fd8b8ecc99192b) && (lStack_28 == 0x294d1b1462efa9b0)) {
      if ((gIsInConnectedStandby == '\0') && (gCsNotifyCallback != (code *)0x0)) {
        (*gCsNotifyCallback)(0x294d1b1462efa901,gIsIdleResiliencyEngaged);
      }
      gIsInConnectedStandby = '\x01';
    }
    else {
      if ((gIsInConnectedStandby == '\x01') && (gCsNotifyCallback != (code *)0x0)) {
        (*gCsNotifyCallback)(0,gIsIdleResiliencyEngaged);
      }
      gIsInConnectedStandby = '\0';
    }
  }
  return iVar1;
}



===== IdleResiliencySettingCallback @ 1c0016be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IdleResiliencySettingCallback(undefined8 param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  if (cVar1 != gIsIdleResiliencyEngaged) {
    gIsIdleResiliencyEngaged = cVar1;
    if (gCsNotifyCallback != (code *)0x0) {
      (*gCsNotifyCallback)(gIsInConnectedStandby);
    }
  }
  return 0;
}



===== _guard_check_icall @ 1c0016c30 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0016c48 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0016c6c =====

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



===== __security_check_cookie @ 1c0016ce0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0016d20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0016d50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0016d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0016d80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1c0016e00 =====

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



===== memset @ 1c0017100 =====

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



===== __memset_repmovs @ 1c0017240 =====

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



===== __memset_query @ 1c00172c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0017340 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0017480 =====

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



===== __memset_spec_plain @ 1c0017500 =====

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



===== DefaultQueueCreate @ 1c0020008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int DefaultQueueCreate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5b;
  code *local_40;
  code *local_38;
  undefined4 local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  memset(&local_68,0,0x60);
  local_18 = 0xffffffff;
  puVar2 = &local_68;
  local_40 = DefaultQueue_EvtIoDeviceControl;
  local_68 = 0x60;
  local_38 = DefaultQueue_EvtIoInternalDeviceControl;
  local_5b = 1;
  local_64 = 2;
  local_60 = 1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,puVar2,0,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar2,0xb,
                        &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0xc,
                     &WPP_462c4d276e5135751c4e692fb8db711a_Traceguids);
  }
  return iVar1;
}



===== SynopsysDeviceCreate @ 1c0020174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int SynopsysDeviceCreate(undefined8 param_1,ulonglong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 auStackY_1d8 [32];
  undefined8 local_1a8;
  ulonglong *local_1a0;
  undefined8 local_198;
  ulonglong local_190;
  code *local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined *local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined4 local_114;
  undefined4 local_108;
  undefined4 local_104;
  code *local_100;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_a8;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_190 = (ulonglong)(uint)local_190;
  local_104 = 0;
  local_1a8 = 0;
  local_1a0 = param_2;
  memset(&local_108,0,0x8c);
  uVar3 = 0x50;
  memset(&local_158,0,0x50);
  local_198 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar3,10,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    param_2 = local_1a0;
  }
  local_160 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  local_190 = 0x38;
  local_188 = SynopsysDevice_EvtDeviceCleanup;
  local_180 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_178 = 1;
  local_174 = 1;
  iVar1 = (*UfxClassFunctions)(UfxGlobals,param_1,param_2,&local_190);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xb,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
    }
joined_r0x0001c00203d4:
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) == 0) goto LAB_1c00208b7;
  }
  else {
    memset(&local_108,0,0x90);
    local_e0 = SynopsysDevice_EvtDevicePrepareHardware;
    local_d8 = SynopsysDevice_EvtDeviceReleaseHardware;
    local_100 = SynopsysDevice_EvtDeviceD0Entry;
    local_f0 = SynopsysDevice_EvtDeviceD0Exit;
    local_e8 = SynopsysDevice_EvtDeviceD0ExitPreInterruptsDisabled;
    local_a8 = SynopsysDevice_EvtDeviceSurpriseRemoval;
    local_108 = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_1a0,&local_108);
    puVar4 = &local_1a8;
    param_2 = &local_190;
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_1a0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xc,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
      }
      goto joined_r0x0001c00203d4;
    }
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_1a8,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    local_78 = 0x38;
    local_58 = local_58 & 0xffffffffffffff00;
    uStack_60 = CONCAT44(0x10,(undefined4)uStack_60);
    local_68 = 0;
    uStack_60 = uStack_60 & 0xffffffffffffff00;
    uStack_70 = 0x20000001000;
    local_48 = 0x200000001;
    RtlStringCchPrintfA((char *)&local_58,0x10,"CONTROLLER",puVar4);
    iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_78,&local_198);
    if (iVar1 < 0) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    }
    else {
      uVar3 = local_198;
    }
    *(undefined8 *)(lVar2 + 600) = uVar3;
    *(undefined4 *)(lVar2 + 0x268) = 2;
    KeInitializeEvent(lVar2 + 0x28,0,0);
    *(undefined4 *)(lVar2 + 0x84) = 0;
    param_2 = (ulonglong *)(lVar2 + 0x80);
    *(undefined8 *)(lVar2 + 0x90) = 0;
    *(undefined4 *)(lVar2 + 0x98) = 0;
    *(undefined4 *)(lVar2 + 0xa0) = 0;
    *(undefined4 *)param_2 = 0x24;
    *(undefined4 *)(lVar2 + 0x8c) = 0;
    *(undefined4 *)(lVar2 + 0x90) = 2;
    *(undefined4 *)(lVar2 + 0x94) = 2;
    *(undefined8 *)(lVar2 + 0x98) = 2;
    *(undefined4 *)(lVar2 + 0xa0) = 2;
    *(undefined4 *)(lVar2 + 0x84) = 2;
    *(undefined4 *)(lVar2 + 0x88) = 5;
    *(undefined4 *)(lVar2 + 0x9c) = 2;
    *(undefined4 *)(lVar2 + 0x8c) = 100;
    *(undefined4 *)(lVar2 + 0x88) = 4;
    uVar3 = local_1a8;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = CONCAT71((int7)((ulonglong)uVar3 >> 8),2);
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xd,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
    iVar1 = DefaultQueueCreate(local_1a8,uVar3,param_2);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xe,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) == 0) goto LAB_1c00208b7;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x1a8))(WdfDriverGlobals,local_1a8,0x80);
      memset(&local_158,0,0x50);
      param_2 = &local_158;
      local_158._0_4_ = 0x50;
      local_158._4_4_ = 6;
      local_150 = 0x1cffffe3;
      local_114 = 3;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x2f0))(WdfDriverGlobals,local_1a8,param_2,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xf,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
        }
      }
      else {
        iVar1 = SynopsysUfxDeviceCreate(local_1a8);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0x10,
                              &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
          }
        }
        else {
          param_2 = (ulonglong *)(lVar2 + 0x60);
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,0);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0x11,
                                &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
            }
          }
          else {
            param_2 = (ulonglong *)(lVar2 + 0x1d0);
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0);
            if (iVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0x12,
                                  &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
              }
            }
            else {
              param_2 = (ulonglong *)(lVar2 + 0x230);
              iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,0);
              if (-1 < iVar1) {
                *(undefined1 *)(lVar2 + 0x23c) = 0;
                *(undefined4 *)(lVar2 + 0x238) = 0;
                goto LAB_1c00208b7;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0x13,
                                  &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
              }
            }
          }
        }
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) == 0) goto LAB_1c00208b7;
    }
  }
  McTemplateK0sqq_EtwWriteTransfer();
LAB_1c00208b7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_2,0x14,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return iVar1;
}



===== SynopsysDevice_EvtDevicePrepareHardware @ 1c0020920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysDevice_EvtDevicePrepareHardware
              (undefined *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  char *pcVar6;
  undefined8 *puVar7;
  longlong lVar8;
  longlong lVar9;
  longlong *plVar10;
  ulonglong *puVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  uint *puVar14;
  undefined4 *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined8 *puVar18;
  uint uVar19;
  undefined8 local_res20;
  undefined1 uVar20;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_res20 = 0;
  local_48 = local_48 & 0xffffffff00000000;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x17,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar17 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar5 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  bVar2 = false;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_2);
  SynopsysDevice_PopulateEnumeratorInfo(param_1);
  puVar16 = (undefined *)0x0;
  if (uVar3 != 0) {
    do {
      puVar17 = puVar16;
      pcVar6 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2);
      if (*pcVar6 == '\x02') {
        puVar17 = (undefined *)
                  (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,puVar16);
        iVar4 = SynopsysInterruptCreate(param_1,(longlong)pcVar6,puVar17);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x19,
                              &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar4);
          }
joined_r0x0001c0020bf9:
          if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
            McTemplateK0sqq_EtwWriteTransfer();
          }
          goto LAB_1c0020aaa;
        }
      }
      else if ((*pcVar6 == '\x03') && (!bVar2)) {
        bVar2 = true;
        iVar4 = SynopsysRegistersCreate(param_1,(longlong)pcVar6,puVar17);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x18,
                              &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar4);
          }
          goto joined_r0x0001c0020bf9;
        }
      }
      uVar19 = (int)puVar16 + 1;
      puVar16 = (undefined *)(ulonglong)uVar19;
    } while (uVar19 < uVar3);
  }
  if (puVar5[1] == 0) {
    iVar4 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x1a,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x9a);
    }
  }
  else {
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,puVar5[1],
                        PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8);
    uVar12 = WdfDriverGlobals;
    puVar17 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
    lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    puVar15 = (undefined4 *)(*(longlong *)(lVar8 + 0x18) + 0x20);
    uVar1 = *puVar15;
    uVar20 = (undefined1)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(uVar12,&RegisterRead,puVar17,(uint)puVar15 & 0xffff,uVar20);
    }
    *(undefined4 *)((longlong)puVar5 + 0x254) = uVar1;
    if ((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
        (WPP_RECORDER_SF_D(puVar5[0x4b],4,puVar17,0x1b,
                           &WPP_591a655566d938762c68c3daf5528955_Traceguids,uVar20),
        (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar17,0x15,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    puVar17 = param_1;
    puVar16 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
    lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    SynopsysDevice_PopulateDeviceFlagsFromKse(lVar9);
    SynopsysAcpiGetVendorDeviceFlags(param_1,puVar17,puVar16);
    uVar13 = *(ulonglong *)(lVar9 + 0x1d8) | 0x10;
    if (*(short *)(lVar9 + 0x254) == 0x300a) {
      uVar13 = *(ulonglong *)(lVar9 + 0x1d8) | 0x90;
    }
    *(ulonglong *)(lVar9 + 0x1d8) = uVar13 | 0x40;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar16,0x16,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    local_48 = DAT_1c001d600;
    puVar18 = &local_res20;
    local_68 = 0;
    puVar17 = (undefined *)0x1000;
    uStack_70 = 0;
    local_res20 = 0x100000000008;
    local_58 = 0;
    uStack_50 = 0;
    local_78 = 0x38;
    uStack_60 = 0x100000001;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0xbf8))
                      (WdfDriverGlobals,puVar5[8],0x1000,puVar18,&local_78,puVar7);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x1c,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar4);
      }
    }
    else {
      uVar13 = DAT_1c001d600;
      plVar10 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar7);
      *plVar10 = *(longlong *)(lVar8 + 0x18) + 0x300;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        puVar18 = (undefined8 *)0x37;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar13,0x37,
                         &WPP_591a655566d938762c68c3daf5528955_Traceguids);
      }
      lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
      puVar16 = param_1;
      puVar17 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
      lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      if (*(char *)(lVar8 + 0x22a) != '\0') {
        puVar16 = (undefined *)CONCAT71((int7)((ulonglong)puVar16 >> 8),1);
        SynopsysAcpiSetPmuState(param_1,'\x01',puVar17);
        puVar14 = (uint *)(*(longlong *)(lVar9 + 0x18) + 0x44);
        uVar3 = *puVar14;
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
          puVar18 = (undefined8 *)((ulonglong)puVar14 & 0xffff);
          puVar16 = &RegisterRead;
          McTemplateK0qq_EtwWriteTransfer(puVar14,&RegisterRead,puVar17,(int)puVar18,(char)uVar3);
        }
        if ((uVar3 & 0x3000000) == 0x2000000) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar18 = (undefined8 *)0x38;
            puVar16 = (undefined *)CONCAT71((int7)((ulonglong)puVar16 >> 8),4);
            WPP_RECORDER_SF_(*(undefined8 *)(lVar8 + 600),4,puVar17,0x38,
                             &WPP_591a655566d938762c68c3daf5528955_Traceguids);
          }
          *(undefined1 *)(lVar8 + 0x229) = 1;
        }
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        puVar18 = (undefined8 *)0x39;
        puVar16 = (undefined *)CONCAT71((int7)((ulonglong)puVar16 >> 8),5);
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar17,0x39,
                         &WPP_591a655566d938762c68c3daf5528955_Traceguids);
      }
      iVar4 = 0;
      *(undefined4 *)(puVar5 + 0x48) = 1;
      if ((*(char *)((longlong)puVar5 + 0x1ca) != '\x01') ||
         (iVar4 = SynopsysAcpiRegisterForNotification(param_1,puVar16,puVar17), -1 < iVar4)) {
        if ((*(char *)(puVar5 + 0x39) == '\0') && ((*(byte *)(puVar5 + 0x3b) & 1) != 0)) {
          puVar11 = (ulonglong *)SmfCreateAttributes();
          if (puVar11 == (ulonglong *)0x0) {
            iVar4 = -0x3fffff66;
            goto LAB_1c0020aaa;
          }
          SmfInitAttributes(puVar11,param_1,puVar17,puVar18,param_1);
          iVar4 = SmfCreate(puVar11,puVar5 + 10);
          SmfFreeAttributes((longlong)puVar11);
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x1f,
                                &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar4);
            }
            goto joined_r0x0001c002105b;
          }
        }
        puVar17 = (undefined *)0x0;
        UfxDeviceSetRunStop(*puVar5,'\0',0);
        goto LAB_1c0020aaa;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x1e,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar4);
      }
    }
  }
joined_r0x0001c002105b:
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0020aaa:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar17,0x20,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return iVar4;
}



===== SynopsysDevice_EvtDeviceReleaseHardware @ 1c00210e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SynopsysDevice_EvtDeviceReleaseHardware
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x21;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x21,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar3 = *(longlong *)(lVar1 + 0x248);
  if (lVar3 != 0) {
    puVar4 = (undefined *)CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
    (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals);
  }
  *(undefined8 *)(lVar1 + 8) = 0;
  *(undefined8 *)(lVar1 + 0x10) = 0;
  *(undefined8 *)(lVar1 + 0x18) = 0;
  *(undefined8 *)(lVar1 + 0x20) = 0;
  if (*(ulonglong *)(lVar1 + 0x50) != 0) {
    SmfDereference(*(ulonglong *)(lVar1 + 0x50),lVar3,puVar4,param_4);
  }
  SynopsysAcpiUnregisterForNotification(param_1,lVar3,puVar4);
  puVar4 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((puVar2 != (undefined8 *)0x0) && (puVar2[1] != 0)) {
    MmUnmapIoSpace(puVar2[1],puVar2[2]);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x22,
                     &WPP_591a655566d938762c68c3daf5528955_Traceguids);
  }
  return 0;
}



===== SynopsysDevice_EvtDeviceSurpriseRemoval @ 1c0021250 =====

void SynopsysDevice_EvtDeviceSurpriseRemoval
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2c,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2d,
                       &WPP_591a655566d938762c68c3daf5528955_Traceguids);
    }
  }
  return;
}



===== SynopsysDevice_PopulateAcpiDeviceInformation @ 1c00212d4 =====

void SynopsysDevice_PopulateAcpiDeviceInformation(longlong param_1,char *param_2)

{
  ushort uVar1;
  uint uVar2;
  
  RtlStringCchPrintfA(param_2 + 10,5,"%04X",(ulonglong)*(ushort *)(param_1 + 0x1a));
  uVar1 = *(ushort *)(param_1 + 8);
  if (uVar1 == 0) {
    RtlStringCchPrintfA(param_2,5,"%s","UKWN");
  }
  else {
    if (*(ushort *)(param_1 + 0xc) == 0) {
      uVar2 = (uint)*(ushort *)(param_1 + 10);
    }
    else {
      uVar2 = (uint)*(ushort *)(param_1 + 0xc) - (uint)uVar1;
    }
    memmove(param_2,(void *)(param_1 + (ulonglong)uVar1),(ulonglong)uVar2);
    if (*(ushort *)(param_1 + 0xc) != 0) {
      memmove(param_2 + 5,(void *)((ulonglong)*(ushort *)(param_1 + 0xc) + param_1),
              (ulonglong)(*(ushort *)(param_1 + 10) - uVar2));
      return;
    }
  }
  RtlStringCchPrintfA(param_2 + 5,5,"%s","FFFF");
  return;
}



===== SynopsysDevice_PopulateDeviceFlagsFromKse @ 1c00213b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysDevice_PopulateDeviceFlagsFromKse(longlong param_1)

{
  bool bVar1;
  int iVar2;
  wchar_t *pwVar3;
  ulonglong *puVar4;
  undefined1 auStackY_128 [32];
  undefined8 in_stack_fffffffffffffef8;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong local_e8;
  ulonglong local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  ulonglong local_c8 [2];
  wchar_t local_b8 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  bVar1 = false;
  local_d0 = 0;
  local_c8[0] = 0;
  if (*(int *)(param_1 + 0x1e0) == 1) {
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:PCI\\VEN_%04X",
                        (ulonglong)*(uint *)(param_1 + 0x1f8));
  }
  else {
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:ACPI\\VEN_%S",param_1 + 0x1e4);
  }
  puVar4 = &local_e8;
  pwVar3 = L"UFXSYNOPSYS";
  iVar2 = KseQueryDeviceFlags(local_b8);
  if (-1 < iVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_iS(*(undefined8 *)(param_1 + 600),pwVar3,puVar4,0x55,in_stack_fffffffffffffef8
                         ,(char)local_e8,local_b8);
    }
    bVar1 = true;
    *(ulonglong *)(param_1 + 0x1d8) = *(ulonglong *)(param_1 + 0x1d8) | local_e8;
  }
  if (*(int *)(param_1 + 0x1e0) == 1) {
    lVar5 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffef8 >> 0x20),
                     *(undefined4 *)(param_1 + 0x1fc));
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:PCI\\VEN_%04X&DEV_%04X",
                        (ulonglong)*(uint *)(param_1 + 0x1f8));
  }
  else {
    lVar5 = param_1 + 0x1e9;
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:ACPI\\VEN_%S&DEV_%S",param_1 + 0x1e4);
  }
  pwVar3 = L"UFXSYNOPSYS";
  puVar4 = &local_e0;
  iVar2 = KseQueryDeviceFlags(local_b8);
  if (-1 < iVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_iS(*(undefined8 *)(param_1 + 600),pwVar3,puVar4,0x56,lVar5,(char)local_e0,
                         local_b8);
    }
    bVar1 = true;
    *(ulonglong *)(param_1 + 0x1d8) = *(ulonglong *)(param_1 + 0x1d8) | local_e0;
  }
  if (*(int *)(param_1 + 0x1e0) == 1) {
    lVar5 = CONCAT44((int)((ulonglong)lVar5 >> 0x20),*(undefined4 *)(param_1 + 0x1fc));
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:PCI\\VEN_%04X&DEV_%04X&REV_%02X",
                        (ulonglong)*(uint *)(param_1 + 0x1f8));
  }
  else {
    lVar5 = param_1 + 0x1e9;
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:ACPI\\VEN_%S&DEV_%S&REV_%S",param_1 + 0x1e4);
  }
  puVar4 = &local_d8;
  pwVar3 = L"UFXSYNOPSYS";
  iVar2 = KseQueryDeviceFlags(local_b8);
  if (-1 < iVar2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_iS(*(undefined8 *)(param_1 + 600),pwVar3,puVar4,0x57,lVar5,(char)local_d8,
                         local_b8);
    }
    bVar1 = true;
    *(ulonglong *)(param_1 + 0x1d8) = *(ulonglong *)(param_1 + 0x1d8) | local_d8;
  }
  if (*(int *)(param_1 + 0x1e0) == 1) {
    uVar6 = CONCAT44((int)((ulonglong)lVar5 >> 0x20),*(undefined4 *)(param_1 + 0x1fc));
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:PCI\\VEN_%04X&DEV_%04X&SUBSYS_%04X%04X",
                        (ulonglong)*(uint *)(param_1 + 0x1f8));
    puVar4 = &local_d0;
    pwVar3 = L"UFXSYNOPSYS";
    iVar2 = KseQueryDeviceFlags(local_b8);
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_iS(*(undefined8 *)(param_1 + 600),pwVar3,puVar4,0x58,uVar6,(char)local_d0,
                           local_b8);
      }
      bVar1 = true;
      *(ulonglong *)(param_1 + 0x1d8) = *(ulonglong *)(param_1 + 0x1d8) | local_d0;
    }
    uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),*(undefined4 *)(param_1 + 0x1fc));
    RtlStringCchPrintfW(local_b8,0x3c,L"UFXSYNOPSYS:PCI\\VEN_%04X&DEV_%04X&SUBSYS_%04X%04X&REV_%02X"
                        ,(ulonglong)*(uint *)(param_1 + 0x1f8));
    puVar4 = local_c8;
    pwVar3 = L"UFXSYNOPSYS";
    iVar2 = KseQueryDeviceFlags(local_b8);
    if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_iS(*(undefined8 *)(param_1 + 600),pwVar3,puVar4,0x59,uVar6,(char)local_c8[0]
                           ,local_b8);
      }
      *(ulonglong *)(param_1 + 0x1d8) = *(ulonglong *)(param_1 + 0x1d8) | local_c8[0];
      goto LAB_1c0021764;
    }
  }
  if (!bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_S(*(undefined8 *)(param_1 + 600));
  }
LAB_1c0021764:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_i(*(undefined8 *)(param_1 + 600));
  }
  return;
}



===== SynopsysDevice_PopulateEnumeratorInfo @ 1c00217b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysDevice_PopulateEnumeratorInfo(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 auStackY_58 [32];
  wchar_t local_20 [8];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  uVar4 = 0x10;
  iVar1 = IoGetDeviceProperty(uVar3,0xf,0x10,local_20);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x51,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
    }
  }
  else {
    iVar1 = _wcsicmp(local_20,L"ACPI");
    if (iVar1 == 0) {
      *(undefined4 *)(lVar2 + 0x1e0) = 2;
      iVar1 = SynopsysDevice_RetrieveAcpiData(param_1,(char *)(lVar2 + 0x1e4));
      if (-1 < iVar1) {
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x53,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
      }
    }
    else {
      iVar1 = _wcsicmp(local_20,L"URS");
      if (iVar1 == 0) {
        pcVar5 = (char *)(lVar2 + 0x1e4);
        iVar1 = SynopsysDevice_RetrieveUrsData
                          (param_1,(undefined4 *)(lVar2 + 0x1e0),pcVar5,(uint *)(lVar2 + 0x1f8));
        if (-1 < iVar1) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar5,0x54,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
        }
      }
      else {
        iVar1 = _wcsicmp(local_20,L"PCI");
        if (iVar1 != 0) {
          *(undefined4 *)(lVar2 + 0x1e0) = 0;
          return;
        }
        *(undefined4 *)(lVar2 + 0x1e0) = 1;
        iVar1 = SynopsysDevice_RetrievePciData(param_1,(uint *)(lVar2 + 0x1f8));
        if (-1 < iVar1) {
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x52,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
        }
      }
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
  return;
}



===== SynopsysDevice_PopulatePciDeviceInformation @ 1c0021a94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysDevice_PopulatePciDeviceInformation
               (undefined8 param_1,uint param_2,ushort param_3,uint param_4,longlong param_5,
               ushort *param_6,uint *param_7)

{
  longlong lVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    WPP_RECORDER_SF_ddd(*(undefined8 *)(lVar1 + 600));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
      WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar1 + 600),(ulonglong)param_6[1],(ulonglong)*param_6,
                          0x46,&WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)*param_6,
                          (char)param_6[1],(char)param_6[4]);
    }
  }
  param_7[4] = (uint)param_3;
  param_7[5] = param_4 & 0xffff;
  param_7[3] = param_2;
  *param_7 = (uint)*param_6;
  param_7[1] = (uint)param_6[1];
  *(ushort *)(param_7 + 2) = (ushort)(byte)param_6[4];
  *(ushort *)(param_7 + 6) = param_6[0x16];
  *(ushort *)((longlong)param_7 + 0x1a) = param_6[0x17];
  *(undefined8 *)(param_7 + 8) = *(undefined8 *)(param_5 + 8);
  *(undefined8 *)(param_7 + 10) = *(undefined8 *)(param_5 + 0x30);
  return;
}



===== SynopsysDevice_RetrieveAcpiData @ 1c0021be4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SynopsysDevice_RetrieveAcpiData(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 auStackY_a8 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  uVar4 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c028);
  if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x7ffffffb)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x4e,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
    }
  }
  else {
    uVar4 = 0x534e5953;
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,local_40._4_2_);
    if (puVar3 != (undefined8 *)0x0) {
      uVar4 = 0;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x32c028);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x50,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
        }
        if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
          McTemplateK0sqq_EtwWriteTransfer();
        }
      }
      else {
        SynopsysDevice_PopulateAcpiDeviceInformation((longlong)puVar3,param_2);
      }
      if (puVar3 == &local_40) {
        return iVar1;
      }
      ExFreePoolWithTag(puVar3,0x534e5953);
      return iVar1;
    }
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x4f,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x9a);
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
  return iVar1;
}



===== SynopsysDevice_RetrievePciData @ 1c0021ea8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SynopsysDevice_RetrievePciData(undefined8 param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  ushort *puVar5;
  undefined1 auStackY_1c8 [32];
  undefined1 local_178 [8];
  undefined8 local_170;
  code *local_140;
  ushort local_138 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1c8;
  memset(local_178,0,0x40);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar3 = 0xe;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x288))(WdfDriverGlobals,param_1,0xe,4);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,0x47,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
    }
  }
  else {
    uVar3 = 0x10;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x288))(WdfDriverGlobals,param_1,0x10,4);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,0x48,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
      }
    }
    else {
      puVar4 = &GUID_BUS_INTERFACE_STANDARD;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                        (WdfDriverGlobals,param_1,&GUID_BUS_INTERFACE_STANDARD,local_178);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x49,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar1);
        }
      }
      else {
        memset(local_138,0,0x100);
        puVar5 = local_138;
        iVar2 = (*local_140)(local_170,0,puVar5,0);
        if (iVar2 == 0x100) {
          SynopsysDevice_PopulatePciDeviceInformation
                    (param_1,0,0,0,(longlong)local_178,local_138,param_2);
          return iVar1;
        }
        iVar1 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x4a,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,1);
        }
      }
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
  return iVar1;
}



===== SynopsysDevice_RetrieveUrsData @ 1c0022200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysDevice_RetrieveUrsData
              (undefined8 param_1,undefined4 *param_2,char *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong local_30;
  uint *local_28;
  ulonglong local_20;
  
  local_30 = (ulonglong)(uint)local_30;
  uVar4 = 0x534e5953;
  puVar3 = (uint *)ExAllocatePool2(0x40,0x150);
  if (puVar3 == (uint *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x4b,
                        &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x9a);
    }
joined_r0x0001c00223bc:
    iVar2 = -0x3fffff66;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      iVar2 = -0x3fffff66;
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    uVar5 = 0;
    local_30 = 1;
    local_20 = 0x150;
    local_28 = puVar3;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                      (WdfDriverGlobals,uVar4,0,0x2a0004,0,&local_30,0,0);
    if (iVar2 == -0x7ffffffb) {
      uVar1 = *puVar3;
      ExFreePoolWithTag(puVar3,0x534e5953);
      uVar5 = 0x534e5953;
      puVar3 = (uint *)ExAllocatePool2(0x40);
      if (puVar3 == (uint *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x4c,
                            &WPP_591a655566d938762c68c3daf5528955_Traceguids,0x9a);
        }
        goto joined_r0x0001c00223bc;
      }
      uVar5 = 0;
      local_30 = 1;
      local_20 = (ulonglong)uVar1;
      local_28 = puVar3;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                        (WdfDriverGlobals,uVar4,0,0x2a0004,0,&local_30,0,0);
    }
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x4d,
                          &WPP_591a655566d938762c68c3daf5528955_Traceguids,(char)iVar2);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
    else if (puVar3[1] == 1) {
      *param_2 = 2;
      SynopsysDevice_PopulateAcpiDeviceInformation((longlong)(puVar3 + 2),param_3);
      param_4[0] = 0;
      param_4[1] = 0;
      param_4[2] = 0;
      param_4[3] = 0;
      param_4[4] = 0;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[7] = 0;
      param_4[8] = 0;
      param_4[9] = 0;
      param_4[10] = 0;
      param_4[0xb] = 0;
    }
    else {
      *param_2 = 1;
      SynopsysDevice_PopulatePciDeviceInformation
                (param_1,puVar3[2],(ushort)puVar3[3],(uint)*(ushort *)((longlong)puVar3 + 0xe),
                 (longlong)(puVar3 + 4),(ushort *)(puVar3 + 0x14),param_4);
      param_3[0] = '\0';
      param_3[1] = '\0';
      param_3[2] = '\0';
      param_3[3] = '\0';
      param_3[4] = '\0';
      param_3[5] = '\0';
      param_3[6] = '\0';
      param_3[7] = '\0';
      param_3[8] = '\0';
      param_3[9] = '\0';
      param_3[10] = '\0';
      param_3[0xb] = '\0';
      param_3[0xc] = '\0';
      param_3[0xd] = '\0';
      param_3[0xe] = '\0';
    }
    if (puVar3 != (uint *)0x0) {
      ExFreePoolWithTag(puVar3,0x534e5953);
    }
  }
  return iVar2;
}



===== Synopsys_EvtDriverDeviceAdd @ 1c0022540 =====

int Synopsys_EvtDriverDeviceAdd(undefined8 param_1,ulonglong *param_2,undefined8 param_3)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xd,
                     &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids);
  }
  iVar1 = SynopsysDeviceCreate(param_1,param_2);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0xe,
                        &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xf,
                     &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids);
  }
  return iVar1;
}



===== Synopsys_EvtDriverUnload @ 1c0022650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Synopsys_EvtDriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x10,
                     &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids);
  }
  gCsNotifyCallback = 0;
  if (gPowerSettingCallbackHandle != 0) {
    PoUnregisterPowerSettingCallback();
  }
  if (gWnfSubscriptionHandle != 0) {
    ExUnsubscribeWnfStateChange();
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  McGenEventUnregister_EtwUnregister();
  return;
}



===== WppCleanupKm @ 1c002270c =====

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



===== WppInitKm @ 1c00227bc =====

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



===== WppLoadTracingSupport @ 1c0022898 =====

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



===== WppTraceCallback @ 1c00229e0 =====

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



===== SynopsysInterruptCreate @ 1c0022c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysInterruptCreate(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_c8;
  code *local_c0;
  code *local_b8;
  longlong local_98;
  undefined8 local_90;
  undefined1 local_80;
  undefined4 local_7c;
  undefined1 local_78;
  ulonglong local_68 [6];
  undefined *local_38;
  
  local_d4 = 0;
  uVar4 = 100;
  memset(&local_d8,0,100);
  local_68[0] = (ulonglong)(uint)local_68[0];
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,10,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  puVar5 = (undefined4 *)PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  local_68[2] = 0;
  local_38 = (undefined *)0x0;
  local_68[1] = 0;
  plVar3 = (longlong *)(lVar2 + 8);
  local_68[3] = 0x100000001;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[0] = 0x38;
  if (*plVar3 == 0) {
    memset(&local_d8,0,0x68);
    local_c0 = DeviceInterrupt_EvtInterruptIsr;
    local_38 = PTR__WDF_DEVICE_INTERRUPT_CONTEXT_TYPE_INFO_1c001d5d8;
  }
  else {
    if (*(longlong *)(lVar2 + 0x10) == 0) {
      *(undefined8 *)(lVar2 + 0x10) = 1;
LAB_1c0022d7e:
      iVar1 = 0;
      goto LAB_1c0022ed5;
    }
    plVar3 = (longlong *)(lVar2 + 0x18);
    if (*plVar3 == 0) {
      memset(&local_d8,0,0x68);
      local_c0 = DeviceInterrupt_EvtAttachInterruptIsr;
    }
    else {
      plVar3 = (longlong *)(lVar2 + 0x20);
      if (*plVar3 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(lVar2 + 600),3,puVar5,0xb,
                            &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids,
                            (char)*(undefined4 *)(param_2 + 8));
        }
        goto LAB_1c0022d7e;
      }
      memset(&local_d8,0,0x68);
      local_c0 = DeviceInterrupt_EvtDetachInterruptIsr;
    }
    local_80 = 1;
    local_78 = 1;
  }
  local_b8 = DeviceInterrupt_EvtInterruptDpc;
  puVar5 = &local_d8;
  local_d8 = 0x68;
  local_c8 = 2;
  local_7c = 2;
  local_98 = param_2;
  local_90 = param_3;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x468))(WdfDriverGlobals,param_1,puVar5,local_68,plVar3)
  ;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0xc,
                        &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
LAB_1c0022ed5:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0xd,
                     &WPP_295876aa620d33436e9ae61ec399b5b5_Traceguids);
  }
  return iVar1;
}



===== SynopsysAbortGetAttachActionWorker @ 1c0022f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAbortGetAttachActionWorker(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1c,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750
                     );
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  if ((0 < *(int *)(lVar3 + 0x168)) &&
     (iVar1 = (**(code **)(lVar3 + 0x148))(*(undefined8 *)(lVar3 + 0x128)), iVar1 < 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 600),2,puVar4,0x1d,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x1e,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return;
}



===== SynopsysAttachInterfaceEnqueueGetAttachAction @ 1c0023058 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysAttachInterfaceEnqueueGetAttachAction
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  code *pcVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x11,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  pcVar3 = *(code **)(WdfFunctions_01015 + 0xbe0);
  (*pcVar3)(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x158));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar3,0x12,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return;
}



===== SynopsysAttachInterfaceInitialize @ 1c0023158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysAttachInterfaceInitialize(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  ulonglong local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined *local_30;
  
  local_78 = (ulonglong)(uint)local_78;
  local_5c = local_5c & 0xffffffff00000000;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xd,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar4 = &local_60;
  local_4c = 0;
  local_38 = 0;
  local_60 = 0x38;
  local_78 = 0x18;
  pcStack_70 = SynopsysGetAttachActionWorker;
  local_68 = 1;
  local_48 = 1;
  local_44 = 1;
  local_30 = PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750;
  local_5c = 0;
  uStack_54 = 0;
  local_40 = *puVar2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_78,puVar4,puVar2 + 0x2b)
  ;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xe,
                        &WPP_330c10c327d7324e3487526feb162862_Traceguids,(char)iVar1);
    }
  }
  else {
    puVar3 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,puVar2[0x2b],
                        PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750);
    puVar4 = &local_60;
    *puVar3 = param_1;
    pcStack_70 = SynopsysAbortGetAttachActionWorker;
    local_30 = PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750;
    local_78 = 0x18;
    local_68 = 1;
    local_5c = 0;
    uStack_54 = 0;
    local_4c = 0;
    local_38 = 0;
    local_60 = 0x38;
    local_48 = 1;
    local_44 = 1;
    local_40 = *puVar2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_78,puVar4,puVar2 + 0x2c);
    if (-1 < iVar1) {
      puVar4 = (undefined4 *)PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750;
      puVar2 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,puVar2[0x2c]);
      *puVar2 = param_1;
      goto LAB_1c00233dd;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xf,
                        &WPP_330c10c327d7324e3487526feb162862_Traceguids,(char)iVar1);
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c00233dd:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x10,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return iVar1;
}



===== SynopsysAttachInterfaceQuery @ 1c0023434 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysAttachInterfaceQuery(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 in_stack_ffffffffffffffe0;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffffffffffe0 >> 0x10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar3 = &GUID_USBFN_INTERFACE_ATTACH;
  *(undefined8 *)(lVar2 + 0x120) = 0;
  *(undefined8 *)(lVar2 + 0x128) = 0;
  *(undefined8 *)(lVar2 + 0x130) = 0;
  *(undefined8 *)(lVar2 + 0x138) = 0;
  *(undefined8 *)(lVar2 + 0x140) = 0;
  *(undefined8 *)(lVar2 + 0x148) = 0;
  *(undefined8 *)(lVar2 + 0x150) = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_USBFN_INTERFACE_ATTACH,
                     (undefined8 *)(lVar2 + 0x120),0x38,CONCAT22(uVar4,1),0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,0xb,
                        &WPP_330c10c327d7324e3487526feb162862_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0xc,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return iVar1;
}



===== SynopsysGetAttachActionWorker @ 1c00235b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SynopsysGetAttachActionWorker
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_res10;
  
  local_res10 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = (char *)0x13;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x13,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ATTACH_INTERFACE_CONTEXT_TYPE_INFO_1c001d750
                     );
  pcVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  puVar2 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  if (*(char *)((longlong)puVar2 + 0x59) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(puVar2[0x4b],4,pcVar4,0x14,&WPP_330c10c327d7324e3487526feb162862_Traceguids);
    }
    pcVar4 = (char *)0x0;
LAB_1c002367c:
    (*DAT_1c001dea8)(UfxGlobals,*puVar2);
  }
  else {
    LOCK();
    *(int *)(puVar2 + 0x2d) = *(int *)(puVar2 + 0x2d) + 1;
    UNLOCK();
    puVar3 = &local_res10;
    iVar1 = (*(code *)puVar2[0x28])(puVar2[0x25]);
    LOCK();
    *(int *)(puVar2 + 0x2d) = *(int *)(puVar2 + 0x2d) + -1;
    UNLOCK();
    if (iVar1 < 0) {
      pcVar4 = (char *)0x0;
      (*DAT_1c001dea8)(UfxGlobals,*puVar2);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar4,0x15,
                          &WPP_330c10c327d7324e3487526feb162862_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
      goto LAB_1c0023692;
    }
    if (local_res10._4_4_ == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(puVar2[0x4b],puVar3,pcVar4,0x16,
                          &WPP_330c10c327d7324e3487526feb162862_Traceguids,(char)local_res10);
      }
      pcVar4 = (char *)(local_res10 & 0xffffffff);
      if ((*(uint *)(puVar2 + 0x3b) >> 8 & 1) == 0) goto LAB_1c002367c;
      uVar5 = 5;
    }
    else {
      if (local_res10._4_4_ == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(puVar2[0x4b],4,pcVar4,0x17,
                           &WPP_330c10c327d7324e3487526feb162862_Traceguids);
        }
        uVar5 = 1;
      }
      else {
        if (local_res10._4_4_ == 2) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_4 = (char *)0x18;
            WPP_RECORDER_SF_(puVar2[0x4b],4,pcVar4,0x18,
                             &WPP_330c10c327d7324e3487526feb162862_Traceguids);
          }
          SmfEnqueueEvent(puVar2[10],1,pcVar4,param_4);
          goto LAB_1c0023692;
        }
        if (local_res10._4_4_ == 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(puVar2[0x4b],4,pcVar4,0x19,
                             &WPP_330c10c327d7324e3487526feb162862_Traceguids);
          }
          uVar5 = 1;
          pcVar4 = (char *)0x4;
          goto LAB_1c002384f;
        }
        if (local_res10._4_4_ != 4) goto LAB_1c0023692;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(puVar2[0x4b],4,pcVar4,0x1a,
                           &WPP_330c10c327d7324e3487526feb162862_Traceguids);
        }
        uVar5 = 2;
      }
      pcVar4 = (char *)(local_res10 & 0xffffffff);
    }
LAB_1c002384f:
    (*DAT_1c001def8)(UfxGlobals,*puVar2,pcVar4,uVar5);
  }
LAB_1c0023692:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar4,0x1b,
                     &WPP_330c10c327d7324e3487526feb162862_Traceguids);
  }
  return;
}



===== SynopsysAcpiEvaluateDsmMethod @ 1c00238b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysAcpiEvaluateDsmMethod
              (undefined8 param_1,void *param_2,undefined8 param_3,undefined4 param_4,
              undefined4 *param_5,ushort param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined4 *local_res8;
  longlong local_78;
  undefined8 *local_70;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar7 = (ulonglong)param_6;
  local_res8 = (undefined4 *)0x0;
  local_68 = (ulonglong)(uint)local_68;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x15,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  local_78 = 0;
  local_38 = 0;
  local_70 = (undefined8 *)0x0;
  local_58 = 0;
  uStack_60 = 0;
  local_68 = 0x38;
  uVar3 = uVar7 << 3;
  uStack_50 = 0x100000001;
  uStack_40 = 0;
  if (uVar3 < 4) {
    uVar3 = 4;
  }
  puVar6 = (undefined8 *)0x200;
  local_48 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_68,0x200,0x534e5953,uVar3 + 0x38,&local_78,&local_res8)
  ;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x16,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar2);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    memset(local_res8,0,uVar3 + 0x38);
    puVar5 = local_res8;
    *local_res8 = 0x43696541;
    local_res8[2] = 0x18;
    local_res8[3] = 4;
    local_res8[1] = 0x4d53445f;
    local_res8[4] = 0x100002;
    memcpy_s(local_res8 + 5,0x10,param_2,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)puVar5 + 0x12);
    if (*(ushort *)((longlong)puVar5 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined4 *)((longlong)puVar5 + uVar3 + 0x14) = 0x40000;
    *(int *)((longlong)puVar5 + uVar3 + 0x18) = (int)param_3;
    puVar4 = (undefined2 *)((longlong)puVar5 + uVar3 + 0x24);
    *(undefined4 *)((longlong)puVar5 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)puVar5 + uVar3 + 0x20) = param_4;
    *puVar4 = 4;
    puVar4[1] = param_6 << 3;
    if (param_6 != 0) {
      puVar5 = (undefined4 *)(puVar4 + 2);
      do {
        *puVar5 = 0x40000;
        uVar1 = *param_5;
        param_5 = param_5 + 1;
        puVar5[1] = uVar1;
        uVar7 = uVar7 - 1;
        puVar5 = puVar5 + 2;
      } while (uVar7 != 0);
    }
    local_38 = 0;
    local_58 = 0;
    uStack_60 = 0;
    local_68 = 0x38;
    uStack_40 = 0;
    uStack_50 = 0x100000001;
    *param_7 = 0;
    param_7[1] = 0;
    *(undefined4 *)(param_7 + 2) = 0;
    puVar6 = param_7;
    local_48 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x608))
                      (WdfDriverGlobals,&local_68,param_7,0x14,&local_70);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x17,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar2);
      }
    }
    else {
      *param_7 = 0;
      param_7[1] = 0;
      *(undefined4 *)(param_7 + 2) = 0;
      puVar6 = local_70;
      iVar2 = SynopsysAcpiEvaluateMethod(param_1,local_78,local_70);
      if (-1 < iVar2) goto LAB_1c0023c3c;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x18,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar2);
      }
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
LAB_1c0023c3c:
  if (local_78 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (local_70 != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x19,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return iVar2;
}



===== SynopsysAcpiEvaluateMethod @ 1c0023cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SynopsysAcpiEvaluateMethod(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1a,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  uVar4 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,uVar2,0,0x32c004);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x1b,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
    }
  }
  else {
    uVar4 = 0;
    piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_3);
    if ((*piVar3 == 0x426f6541) && (piVar3[2] != 0)) goto LAB_1c0023eb7;
    iVar1 = -0x3febfff1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x1c,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,0xf);
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0023eb7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x1d,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return iVar1;
}



===== SynopsysAcpiGetPortType @ 1c0023f18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiGetPortType(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 ******ppppppuVar7;
  uint uVar8;
  undefined8 ******ppppppuVar9;
  undefined8 uVar10;
  bool bVar11;
  undefined1 auStackY_118 [32];
  undefined4 *local_d8;
  undefined8 ******local_d0;
  undefined4 *local_c8;
  undefined8 ******local_c0;
  undefined8 *****local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined *local_88;
  undefined8 *****local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  ppppppuVar7 = (undefined8 ******)&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID;
  ppppppuVar9 = (undefined8 ******)0x1;
  iVar2 = SynopsysAcpiEvaluateDsmMethod
                    (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,2,(undefined4 *)0x0,0,
                     &local_48);
  if (iVar2 < 0) {
    (*DAT_1c001dea8)(UfxGlobals,*puVar4,0);
    local_b8 = (undefined8 *****)((ulonglong)local_b8 & 0xffffffff);
    local_d0 = (undefined8 ******)0x0;
    local_d8 = (undefined4 *)0x0;
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    ppppppuVar9 = &local_d0;
    ppppppuVar7 = &local_b8;
    local_88 = (undefined *)0x0;
    local_a8 = 0;
    uStack_b0 = 0;
    uStack_90 = 0;
    uStack_a0 = 0x100000001;
    local_b8 = (undefined8 *****)0x38;
    local_98 = *puVar5;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals);
    if (-1 < iVar3) {
      ppppppuVar9 = &local_b8;
      local_a8 = 0;
      uStack_a0 = 0x100000001;
      local_88 = PTR__WDF_ETW_ERROR_RECORD_CONTEXT_TYPE_INFO_1c001d680;
      uStack_b0 = 0;
      local_b8 = (undefined8 *****)0x38;
      local_98 = 0;
      uStack_90 = 0;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,local_d0,ppppppuVar9,&local_d8);
      if (iVar3 < 0) {
        ppppppuVar7 = local_d0;
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      }
      else {
        *local_d8 = 1;
        *(undefined8 *)(local_d8 + 2) = param_1;
        local_d8[4] = iVar2;
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*puVar5,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
        ppppppuVar7 = *(undefined8 *******)(lVar6 + 0x10);
        ppppppuVar9 = local_d0;
        (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppppppuVar7 = (undefined8 ******)CONCAT71((int7)((ulonglong)ppppppuVar7 >> 8),2);
      WPP_RECORDER_SF_(puVar4[0x4b],2,ppppppuVar9,0xb,
                       &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
    }
  }
  if ((uStack_40._4_2_ != 0) && (uStack_40._6_2_ == 0)) {
    (*DAT_1c001dea8)(UfxGlobals,*puVar4,0);
    local_80 = (undefined8 *****)((ulonglong)local_80 & 0xffffffff);
    local_c0 = (undefined8 ******)0x0;
    local_c8 = (undefined4 *)0x0;
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
    ppppppuVar9 = &local_c0;
    ppppppuVar7 = &local_80;
    local_50 = (undefined *)0x0;
    local_70 = 0;
    uStack_78 = 0;
    uStack_58 = 0;
    uStack_68 = 0x100000001;
    local_80 = (undefined8 *****)0x38;
    local_60 = *puVar5;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals);
    if (-1 < iVar3) {
      ppppppuVar9 = &local_80;
      local_70 = 0;
      uStack_68 = 0x100000001;
      local_50 = PTR__WDF_ETW_ERROR_RECORD_CONTEXT_TYPE_INFO_1c001d680;
      uStack_78 = 0;
      local_80 = (undefined8 *****)0x38;
      local_60 = 0;
      uStack_58 = 0;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,local_c0,ppppppuVar9,&local_c8);
      if (iVar3 < 0) {
        ppppppuVar7 = local_c0;
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      }
      else {
        *local_c8 = 1;
        *(undefined8 *)(local_c8 + 2) = param_1;
        local_c8[4] = iVar2;
        lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,*puVar5,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
        ppppppuVar7 = *(undefined8 *******)(lVar6 + 0x10);
        ppppppuVar9 = local_c0;
        (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals);
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppppppuVar7 = (undefined8 ******)CONCAT71((int7)((ulonglong)ppppppuVar7 >> 8),2);
      WPP_RECORDER_SF_(puVar4[0x4b],2,ppppppuVar9,0xc,
                       &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
    }
  }
  cVar1 = (char)local_38;
  bVar11 = *(char *)((longlong)puVar4 + 0x1cb) == '\0';
  uVar8 = local_38 & 0xff;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(puVar4[0x4b],ppppppuVar7,ppppppuVar9,0xd,
                      &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)local_38);
  }
  if (cVar1 == '\0') {
    uVar10 = 0;
  }
  else if (uVar8 == 1) {
    uVar10 = 1;
  }
  else if (uVar8 == 2) {
    uVar10 = 2;
  }
  else {
    if (uVar8 != 3) {
      uVar10 = 0;
      (*DAT_1c001def8)(UfxGlobals,*puVar4,0,bVar11);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_(puVar4[0x4b],2,uVar10,0xe,&WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
      goto LAB_1c00243f2;
    }
    uVar10 = 3;
  }
  (*DAT_1c001def8)(UfxGlobals,*puVar4,uVar10,bVar11);
LAB_1c00243f2:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar10,0xf,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiGetVendorDeviceFlags @ 1c0024454 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiGetVendorDeviceFlags(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x30,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar5 = 0;
  iVar2 = SynopsysAcpiEvaluateDsmMethod
                    (param_1,&USBFN_DSM_VENDOR_PROPERTIES_GUID,0,0,(undefined4 *)0x0,0,&local_48);
  uVar1 = local_38;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x31,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar2);
    }
  }
  else if ((uStack_40._4_2_ == 2) && (uStack_40._6_2_ != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(lVar3 + 600),4,uVar5,0x33,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(undefined1)local_38);
    }
    if ((uVar1 & 2) == 0) goto LAB_1c0024757;
    uVar5 = 0;
    iVar2 = SynopsysAcpiEvaluateDsmMethod
                      (param_1,&USBFN_DSM_VENDOR_PROPERTIES_GUID,0,1,(undefined4 *)0x0,0,&local_48);
    uVar1 = local_38;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x34,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar2);
      }
    }
    else {
      if ((((int)uStack_40 != 0) && (0x13 < local_48._4_4_)) && (uStack_40._4_2_ == 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(lVar3 + 600),4,uVar5,0x36,
                            &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(undefined1)local_38);
        }
        uVar4 = *(ulonglong *)(lVar3 + 0x1d8) | 1;
        if ((uVar1 & 1) == 0) {
          uVar4 = *(ulonglong *)(lVar3 + 0x1d8) & 0xfffffffffffffffe;
        }
        if ((uVar1 & 2) == 0) {
          uVar4 = uVar4 & 0xfffffffffffffffd;
        }
        else {
          uVar4 = uVar4 | 2;
        }
        if ((uVar1 & 0x20) == 0) {
          uVar4 = uVar4 & 0xfffffffffffffeff;
        }
        else {
          uVar4 = uVar4 | 0x100;
        }
        *(ulonglong *)(lVar3 + 0x1d8) = uVar4;
        goto LAB_1c0024757;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x35,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,0xd);
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x32,
                      &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,0xd);
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0024757:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar5,0x37,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiInitializeAttachAndPortDetect @ 1c00247b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiInitializeAttachAndPortDetect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  undefined8 uVar4;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  uint local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x1e,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar4 = 1;
  iVar1 = SynopsysAcpiEvaluateDsmMethod
                    (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,0,(undefined4 *)0x0,0,
                     &local_48);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x1f,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
    }
  }
  else {
    if ((uStack_40._4_2_ == 2) && (uStack_40._6_2_ != 0)) {
      uVar3 = (ushort)(byte)local_38;
      if (1 < uStack_40._6_2_) {
        uVar3 = (ushort)local_38;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(lVar2 + 600),4,uVar4,0x21,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)uVar3);
      }
      if ((uVar3 & 4) != 0) {
        *(undefined1 *)(lVar2 + 0x1c8) = 1;
      }
      if ((uVar3 & 8) != 0) {
        *(undefined1 *)(lVar2 + 0x1c9) = 1;
      }
      if ((uVar3 & 2) != 0) {
        uVar4 = 1;
        iVar1 = SynopsysAcpiEvaluateDsmMethod
                          (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,1,(undefined4 *)0x0,0
                           ,&local_48);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x22,
                              &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
          }
          if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
            McTemplateK0sqq_EtwWriteTransfer();
          }
          goto LAB_1c0024b78;
        }
        if ((((int)uStack_40 == 0) || (local_48._4_4_ < 0x14)) || (uStack_40._4_2_ != 0)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),2,uVar4,0x23,
                           &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
          goto LAB_1c0024b78;
        }
        if ((local_38 & 1) != 0) {
          *(undefined1 *)(lVar2 + 0x1ca) = 1;
        }
        if ((local_38 & 2) != 0) {
          *(undefined1 *)(lVar2 + 0x1cb) = 1;
        }
      }
      if ((uVar3 & 0x10) != 0) {
        *(undefined1 *)(lVar2 + 0x22a) = 1;
      }
      if ((uVar3 & 0x20) != 0) {
        *(undefined1 *)(lVar2 + 0x22b) = 1;
      }
      if ((uVar3 & 0x40) != 0) {
        *(undefined1 *)(lVar2 + 0x22c) = 1;
      }
      if ((uVar3 >> 8 & 1) != 0) {
        uVar4 = 1;
        iVar1 = SynopsysAcpiEvaluateDsmMethod
                          (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,8,(undefined4 *)0x0,0
                           ,&local_48);
        if (((-1 < iVar1) && (uStack_40._4_2_ == 0)) && (uStack_40._6_2_ != 0)) {
          *(undefined1 *)(lVar2 + 0x260) = 1;
          *(uint *)(lVar2 + 0x264) = local_38;
        }
      }
      if ((uVar3 >> 9 & 1) != 0) {
        uVar4 = 1;
        iVar1 = SynopsysAcpiEvaluateDsmMethod
                          (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,9,(undefined4 *)0x0,0
                           ,&local_48);
        if (((-1 < iVar1) && (uStack_40._4_2_ == 0)) && (uStack_40._6_2_ != 0)) {
          *(uint *)(lVar2 + 0x268) = local_38;
        }
      }
      goto LAB_1c0024b78;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x20,
                        &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,0xd);
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0024b78:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x24,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== SynopsysAcpiRegisterForNotification @ 1c0024bd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysAcpiRegisterForNotification(undefined *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined4 in_stack_ffffffffffffffd0;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffffffffffd0 >> 0x10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2b,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar3 = &GUID_ACPI_INTERFACE_STANDARD2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,param_1,&GUID_ACPI_INTERFACE_STANDARD2,lVar2 + 0x170,0x58,
                     CONCAT22(uVar4,1),0);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(lVar2 + 0x1b8))(*(undefined8 *)(lVar2 + 0x178),SynopsysAcpiNotifyCallback);
    puVar3 = param_1;
    if (iVar1 < 0) {
      if (*(code **)(lVar2 + 0x188) != (code *)0x0) {
        (**(code **)(lVar2 + 0x188))(*(undefined8 *)(lVar2 + 0x178));
        puVar3 = param_1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,0x2c,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x2d,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return iVar1;
}



===== SynopsysAcpiSetDeviceState @ 1c0024d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SynopsysAcpiSetDeviceState(undefined8 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined2 uVar5;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x10,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  iVar1 = *(int *)(lVar2 + 0x6c);
  if (iVar1 == 0) {
    uVar3 = 0;
LAB_1c0024e74:
    if (param_2 == 1) goto LAB_1c0024f4f;
    if (param_2 == 2) {
      local_48 = 1;
    }
    else {
      if (param_2 == 3) goto LAB_1c0024f4f;
      if (param_2 == 4) {
        local_48 = 2;
      }
      else if (param_2 == 5) {
        local_48 = 3;
      }
      else {
        if (param_2 != 6) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          uVar5 = 0x12;
          goto LAB_1c0024e4b;
        }
        local_48 = 4;
      }
    }
    puVar4 = (undefined *)0x1;
    local_44 = uVar3;
    iVar1 = SynopsysAcpiEvaluateDsmMethod
                      (param_1,&USBFN_DSM_ATTACH_AND_PORT_DETECTION_GUID,1,3,&local_48,2,&local_40);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x13,
                          &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids,(char)iVar1);
      }
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
        McTemplateK0sqq_EtwWriteTransfer();
      }
    }
  }
  else {
    if (iVar1 == 1) {
      uVar3 = 1;
      goto LAB_1c0024e74;
    }
    if (iVar1 == 2) {
      uVar3 = 2;
      goto LAB_1c0024e74;
    }
    if (iVar1 == 3) {
      uVar3 = 3;
      goto LAB_1c0024e74;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar5 = 0x11;
LAB_1c0024e4b:
    WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),2,puVar4,uVar5,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
LAB_1c0024f4f:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x14,
                     &WPP_944e3b7dd22b392e00095b14308d0ff3_Traceguids);
  }
  return;
}



===== ProprietaryChargerAbortOperationWorkItem @ 1c0024fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerAbortOperationWorkItem
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2d,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0);
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar2,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar4 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar2);
  iVar1 = (**(code **)(lVar3 + 0xd8))(*(undefined8 *)(lVar3 + 0xb0));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x2e,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x2f,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerDetectWorkItem @ 1c0025120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerDetectWorkItem(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x25,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar2,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  uVar5 = *puVar3;
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar5 = ProprietaryChargerTryBeginOperation(lVar4,uVar5,puVar7);
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar7,0x26,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)uVar5);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  else {
    puVar3 = (undefined8 *)(lVar4 + 0x108);
    *puVar3 = 0;
    *(undefined8 *)(lVar4 + 0x110) = 0;
    *(undefined4 *)(lVar4 + 0x118) = 0;
    puVar6 = puVar3;
    iVar1 = (**(code **)(lVar4 + 200))(*(undefined8 *)(lVar4 + 0xb0));
    ProprietaryChargerEndOperation(lVar4,puVar6,puVar7);
    if (iVar1 < 0) {
      *puVar3 = 0;
      *(undefined8 *)(lVar4 + 0x110) = 0;
      *(undefined4 *)(lVar4 + 0x118) = 0;
    }
  }
  lVar4 = lVar4 + 0x108;
  (*DAT_1c001deb0)(UfxGlobals,*puVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,lVar4,0x27,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerEndOperation @ 1c00252fc =====

void ProprietaryChargerEndOperation(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x22,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  if (*(int *)(param_1 + 0x11c) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 600),2,param_3,0x23,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  else {
    LOCK();
    *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + -1;
    UNLOCK();
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x24,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== ProprietaryChargerInitialize @ 1c00253c8 =====

int ProprietaryChargerInitialize(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  code *pcVar2;
  undefined2 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x10,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  pcVar2 = ProprietaryChargerDetectWorkItem;
  iVar1 = ProprietaryChargerCreateWorkItem
                    (*param_1,param_2,ProprietaryChargerDetectWorkItem,param_1 + 0x1d);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x11;
  }
  else {
    pcVar2 = ProprietaryChargerSetPropertyWorkItem;
    iVar1 = ProprietaryChargerCreateWorkItem
                      (*param_1,param_2,ProprietaryChargerSetPropertyWorkItem,param_1 + 0x1e);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x12;
    }
    else {
      pcVar2 = ProprietaryChargerAbortOperationWorkItem;
      iVar1 = ProprietaryChargerCreateWorkItem
                        (*param_1,param_2,ProprietaryChargerAbortOperationWorkItem,param_1 + 0x1f);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x13;
      }
      else {
        pcVar2 = ProprietaryChargerResetOperationWorkItem;
        iVar1 = ProprietaryChargerCreateWorkItem
                          (*param_1,param_2,ProprietaryChargerResetOperationWorkItem,param_1 + 0x20)
        ;
        if (-1 < iVar1) goto LAB_1c00254fd;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x14;
      }
    }
  }
  WPP_RECORDER_SF_(param_1[0x4b],2,pcVar2,uVar3,&WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
LAB_1c00254fd:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,pcVar2,0x15,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return iVar1;
}



===== ProprietaryChargerQuerySupport @ 1c002554c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 ProprietaryChargerQuerySupport(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  void *_Dst;
  int iVar1;
  undefined1 uVar2;
  undefined *puVar3;
  undefined4 in_stack_ffffffffffffffc0;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffffffffffc0 >> 0x10);
  uVar2 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0xc,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  _Dst = (void *)(param_1 + 0xa8);
  memset(_Dst,0,0x40);
  puVar3 = &GUID_UFX_INTERFACE_PROPRIETARY_CHARGER;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,param_2,&GUID_UFX_INTERFACE_PROPRIETARY_CHARGER,_Dst,0x40,
                     CONCAT22(uVar4,1),0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(param_1 + 600),3,puVar3,0xe,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)iVar1);
    }
    puVar3 = (undefined *)0x40;
    memset(_Dst,0,0x40);
  }
  else if (((*(longlong *)(param_1 + 200) == 0) || (*(longlong *)(param_1 + 0xd0) == 0)) ||
          (*(longlong *)(param_1 + 0xd8) == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_2 = CONCAT71((int7)((ulonglong)param_2 >> 8),2);
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 600),2,puVar3,0xd,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
    ProprietaryChargerReleaseInterface(_Dst,param_2,puVar3);
  }
  else {
    uVar2 = 1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0xf,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return uVar2;
}



===== ProprietaryChargerSetPropertyWorkItem @ 1c00256e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProprietaryChargerSetPropertyWorkItem(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 local_res10;
  
  local_res10 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x28,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar3,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar4,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar6 = puVar3[1];
  uVar7 = 0x18;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,uVar6,0x18,&local_res10,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x29,
                        &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)iVar2);
    }
  }
  else {
    uVar6 = ProprietaryChargerTryBeginOperation(lVar5,uVar6,uVar7);
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x2a,
                          &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)uVar6);
      }
    }
    else {
      uVar6 = local_res10;
      iVar2 = (**(code **)(lVar5 + 0xd0))(*(undefined8 *)(lVar5 + 0xb0));
      ProprietaryChargerEndOperation(lVar5,uVar6,uVar7);
      if (-1 < iVar2) goto LAB_1c00258e6;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x2b,
                          &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids,(char)iVar2);
      }
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c00258e6:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,puVar3[1]);
  pcVar1 = DAT_1c001de70;
  uVar6 = UfxGlobals;
  uVar7 = 0;
  puVar3[1] = 0;
  (*pcVar1)(uVar6,*puVar3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0x2c,
                     &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
  }
  return;
}



===== SynopsysRegistersCreate @ 1c0025970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SynopsysRegistersCreate(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *local_res10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_res10 = (undefined8 *)0x0;
  local_38 = (undefined *)((ulonglong)local_38 & 0xffffffff00000000);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_b21ada4d398a308dcc05aba8672ccdfc_Traceguids);
  }
  puVar4 = (undefined8 *)PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(uint *)(param_2 + 0xc) < 0xcc20) {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xb,
                        &WPP_b21ada4d398a308dcc05aba8672ccdfc_Traceguids,0xd);
    }
  }
  else {
    puVar4 = &local_68;
    local_38 = PTR__WDF_REGISTERS_CONTEXT_TYPE_INFO_1c001d658;
    local_58 = 0;
    uStack_60 = 0;
    local_68 = 0x38;
    local_48 = 0;
    uStack_40 = 0;
    uStack_50 = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,puVar4,&local_res10);
    if (iVar1 == 0x40000000) {
      iVar1 = 0;
      *local_res10 = 0;
      local_res10[1] = 0;
      local_res10[2] = 0;
      local_res10[3] = 0;
    }
    else if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xc,
                          &WPP_b21ada4d398a308dcc05aba8672ccdfc_Traceguids,(char)iVar1);
      }
      goto joined_r0x0001c0025bb7;
    }
    puVar4 = (undefined8 *)0x204;
    *local_res10 = "2.03a";
    lVar3 = MmMapIoSpaceEx(*(undefined8 *)(param_2 + 4),*(undefined4 *)(param_2 + 0xc));
    if (lVar3 != 0) {
      local_res10[1] = lVar3;
      local_res10[2] = (ulonglong)*(uint *)(param_2 + 0xc);
      local_res10[3] = lVar3 + 0xc100;
      *(longlong *)(lVar2 + 0x48) = lVar3 + 0xc700;
      goto LAB_1c0025bd1;
    }
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0xd,
                        &WPP_b21ada4d398a308dcc05aba8672ccdfc_Traceguids,0x9a);
    }
  }
joined_r0x0001c0025bb7:
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0025bd1:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0xe,
                     &WPP_b21ada4d398a308dcc05aba8672ccdfc_Traceguids);
  }
  return iVar1;
}



===== SynopsysUfxDeviceCreate @ 1c0025c20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

int SynopsysUfxDeviceCreate(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulonglong *puVar6;
  undefined8 uVar7;
  undefined1 auStackY_1b8 [32];
  ulonglong local_168;
  code *pcStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined *local_138;
  undefined8 local_130;
  undefined8 local_128;
  code *pcStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 *puStack_e8;
  undefined8 local_e0;
  ulonglong local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  undefined8 local_88;
  code *local_80;
  undefined8 local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  undefined8 local_48;
  undefined4 uStack_40;
  char cStack_3c;
  undefined1 uStack_3b;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined4 uStack_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_d8 = (ulonglong)(uint)local_d8;
  uVar5 = 0x84;
  memset(&local_d8,0,0x84);
  uStack_38 = 0;
  uStack_36 = 0;
  uStack_35 = 0;
  uStack_34 = 0;
  local_130 = 0;
  local_f8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  cStack_3c = '\0';
  uStack_3b = 0;
  uStack_3a = 0;
  local_108 = (ulonglong)local_108._4_4_ << 0x20;
  local_128 = 0;
  pcStack_120 = (code *)0x0;
  local_e0 = (ulonglong)local_e0._4_4_ << 0x20;
  local_118 = 0;
  uStack_110 = 0;
  local_168 = (ulonglong)(uint)local_168;
  local_f0 = 0;
  puStack_e8 = (undefined4 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar5,10,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar6 = &local_100;
  local_100._4_4_ = 0x5053485f;
  local_158 = 0;
  local_100._0_4_ = 0x42696541;
  pcStack_160 = (code *)0x0;
  local_138 = (undefined *)0x0;
  local_148 = 0;
  uStack_140 = 0;
  local_168 = 0x38;
  uStack_150 = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x608))(WdfDriverGlobals,&local_168,puVar6,8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0xb,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
    }
  }
  else {
    puStack_e8 = (undefined4 *)&local_100;
    local_f0 = 1;
    local_e0 = 8;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    uVar7 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))(WdfDriverGlobals,uVar5,0,0x32c004);
    cStack_3c = 0;
    uStack_3b = 0;
    uStack_36 = 0;
    uStack_35 = 0;
    uStack_34 = 0;
    uStack_3a = 0xffff;
    uStack_38 = 0xffff;
    uStack_40 = 1;
    local_48 = CONCAT44((iVar2 < 0) + 2,0x18);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(puVar3[0x4b],4,uVar7,0xc,&WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,
                        (char)iVar2);
    }
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_f8);
    uVar5 = param_1;
    cStack_3c = ProprietaryChargerQuerySupport((longlong)puVar3,param_1,uVar7);
    iVar1 = SynopsysAttachInterfaceQuery(param_1,uVar5,uVar7);
    if ((iVar1 < 0) &&
       (SynopsysAcpiInitializeAttachAndPortDetect(param_1,uVar5,uVar7),
       *(char *)(puVar3 + 0x4c) == '\x01')) {
      uStack_36 = 1;
      uStack_34 = *(undefined4 *)((longlong)puVar3 + 0x264);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dL(puVar3[0x4b]);
    }
    local_d8 = 0x88;
    local_88 = 0;
    local_78 = 0;
    local_d0 = UfxDevice_EvtDeviceHostConnect;
    puVar6 = &local_d8;
    local_c8 = UfxDevice_EvtDeviceHostDisconnect;
    local_168 = 0x38;
    local_c0 = UfxDevice_EvtDeviceAddressed;
    local_158 = 0;
    local_b8 = UfxDevice_EvtDeviceEndpointAdd;
    local_b0 = UfxDevice_EvtDeviceDefaultEndpointAdd;
    local_a8 = UfxDevice_EvtDeviceUsbStateChange;
    local_a0 = UfxDevice_EvtDevicePortChange;
    local_98 = UfxDevice_EvtDevicePortDetect;
    local_90 = UfxDevice_EvtDeviceRemoteWakeupSignal;
    local_80 = UfxDevice_EvtDeviceTestModeSet;
    local_70 = UfxDevice_EvtDeviceSuperSpeedPowerFeature;
    local_68 = UfxDevice_EvtDeviceProprietaryChargerDetect;
    local_60 = UfxDevice_EvtDeviceProprietaryChargerSetProperty;
    local_58 = UfxDevice_EvtDeviceProprietaryChargerReset;
    local_138 = PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628;
    pcStack_160 = UfxDevice_EvtCleanupCallback;
    local_148 = 0;
    uStack_140 = 0;
    uStack_150 = 0x100000001;
    iVar2 = (*DAT_1c001de68)(UfxGlobals,param_1,puVar6,&local_48);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0xe,
                          &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
      }
    }
    else {
      uVar5 = local_130;
      puVar6 = (ulonglong *)PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628;
      puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
      *puVar4 = param_1;
      puVar4[0x23] = 3;
      *(undefined1 *)(puVar4 + 0x24) = 1;
      *(char *)((longlong)puVar4 + 0x121) = cStack_3c;
      *(undefined1 *)(puVar4 + 0x26) = 1;
      *puVar3 = local_130;
      if ((iVar1 < 0) ||
         (iVar2 = SynopsysAttachInterfaceInitialize(param_1,uVar5,puVar6), -1 < iVar2)) {
        if ((cStack_3c == '\0') ||
           (iVar2 = ProprietaryChargerInitialize(puVar3,param_1,puVar6), -1 < iVar2)) {
          puVar6 = &local_168;
          local_138 = (undefined *)0x0;
          local_108 = 0;
          local_128 = 0x28;
          local_158 = 0;
          pcStack_120 = EvtDisconnectTimer;
          pcStack_160 = (code *)0x0;
          local_168 = 0x38;
          uStack_140 = 0;
          uStack_150 = 0x100000001;
          local_118 = 0x100000000;
          uStack_110 = 0;
          local_148 = param_1;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                            (WdfDriverGlobals,&local_128,puVar6,puVar4 + 0x25);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x11,
                                &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
            }
          }
          else {
            local_138 = (undefined *)0x0;
            local_158 = 0;
            uStack_140 = 0;
            local_148 = local_130;
            pcStack_160 = (code *)0x0;
            local_168 = 0x38;
            uStack_150 = 0x100000001;
            (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_168,puVar4 + 1);
            local_138 = (undefined *)0x0;
            local_158 = 0;
            uStack_140 = 0;
            local_148 = local_130;
            pcStack_160 = (code *)0x0;
            local_168 = 0x38;
            uStack_150 = 0x100000001;
            (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_168,puVar4 + 2);
            puVar6 = &local_168;
            local_138 = (undefined *)0x0;
            local_108 = 0;
            local_128 = 0x28;
            local_158 = 0;
            pcStack_120 = SynopsysInterruptWatchdogTimer;
            pcStack_160 = (code *)0x0;
            local_168 = 0x38;
            uStack_140 = 0;
            uStack_150 = 0x100000002;
            local_118 = 0x100000000;
            uStack_110 = 0;
            local_148 = param_1;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                              (WdfDriverGlobals,&local_128,puVar6,puVar3 + 0x49);
            if (-1 < iVar2) {
              EtwUpdateDeviceHandle(param_1);
              goto LAB_1c0026428;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x12,
                                &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
            }
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x10,
                            &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0xf,
                          &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
      }
    }
  }
  if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
    McTemplateK0sqq_EtwWriteTransfer();
  }
LAB_1c0026428:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar6,0x13,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return iVar2;
}



===== UfxDeviceStopOrResumeIdle @ 1c0026490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UfxDeviceStopOrResumeIdle(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar7;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  iVar4 = 4;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar7 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x35,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar5 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar1);
  iVar6 = (int)param_3;
  if ((param_2 == 1) || (param_2 == 2)) {
    if ((iVar6 == 0) || ((iVar6 == 1 || (iVar6 == 2)))) goto LAB_1c002656b;
    if (iVar6 == 3) {
      cVar3 = *(char *)((longlong)puVar1 + 0x121);
    }
    else {
      if (iVar6 != 4) {
        if (iVar6 == 5) {
          iVar4 = *(int *)(lVar2 + 0x118);
        }
        goto LAB_1c002663c;
      }
      cVar3 = '\0';
    }
    iVar4 = 4 - (uint)((*(byte *)(lVar2 + 0x1d8) & 8) != 0);
  }
  else if (((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) {
LAB_1c002656b:
    cVar3 = '\x01';
  }
  else {
LAB_1c002663c:
    cVar3 = '\0';
  }
  if (iVar4 != *(int *)(lVar2 + 0x88)) {
    *(int *)(lVar2 + 0x88) = iVar4;
    puVar5 = (undefined *)(lVar2 + 0x80);
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x170))(WdfDriverGlobals,*puVar1);
    if (-1 < iVar4) goto LAB_1c0026664;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x36,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar4);
    }
joined_r0x0001c00265e6:
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
    goto LAB_1c00267ef;
  }
LAB_1c0026664:
  if (cVar3 == '\0') {
    if (*(char *)(puVar1 + 0x24) != '\0') goto LAB_1c00267b5;
    *(int *)(puVar1 + 0x23) = param_2;
    *(int *)((longlong)puVar1 + 0x11c) = iVar6;
    *(undefined1 *)(puVar1 + 0x24) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),4,puVar5,0x39,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
    puVar5 = (undefined *)0x0;
    (**(code **)(WdfFunctions_01015 + 0xdb8))
              (WdfDriverGlobals,*puVar1,0,0x431,
               "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxdevice.c");
  }
  else {
    if (*(char *)(puVar1 + 0x24) == '\0') {
LAB_1c00267b5:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),4,puVar5,0x3a,
                         &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 1;
        WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 600),4,puVar5,0x37,
                         &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
      }
      puVar5 = (undefined *)CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
      iVar4 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                        (WdfDriverGlobals,*puVar1,puVar5,0,CONCAT44(uVar7,0x422),
                         "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxdevice.c")
      ;
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x38,
                            &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar4);
        }
        goto joined_r0x0001c00265e6;
      }
      *(undefined1 *)(puVar1 + 0x24) = 0;
    }
    *(int *)((longlong)puVar1 + 0x11c) = iVar6;
    *(int *)(puVar1 + 0x23) = param_2;
  }
  iVar4 = 0;
LAB_1c00267ef:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar5,0x3b,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return iVar4;
}



===== UfxDevice_EvtDeviceDefaultEndpointAdd @ 1c0026850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceDefaultEndpointAdd(undefined8 param_1,undefined2 param_2,undefined *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_res20;
  undefined2 local_res21;
  undefined1 local_res23;
  undefined2 local_res24;
  undefined1 local_res26;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x26,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  local_res21 = 5;
  local_res26 = 0;
  local_res20 = 7;
  local_res23 = 0;
  local_res24 = param_2;
  uVar1 = UfxEndpointAdd(param_1,(undefined4 *)&local_res20,param_3);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x27,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)uVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  uVar2 = (ulonglong)uVar1;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar2,0x28,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDevicePortChange @ 1c0026990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDevicePortChange(undefined8 param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  ulonglong uVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x2d,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar4 = *puVar2;
    puVar5 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    WPP_RECORDER_SF_L(*(undefined8 *)(lVar3 + 600),uVar4,puVar5,0x2e,
                      &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)param_2);
  }
  uVar6 = (ulonglong)param_2;
  iVar1 = UfxDeviceStopOrResumeIdle(param_1,*(int *)(puVar2 + 0x23),uVar6);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x2f,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  SynopsysEtwLogConnectedStandbyInfo();
  uVar4 = 0;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0x30,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceProprietaryChargerDetect @ 1c0026b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceProprietaryChargerDetect
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined *puVar3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x45,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x16,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar3 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*puVar1);
  *(undefined1 *)((longlong)puVar1 + 0x121) = 0;
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0xe8));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x17,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar3,0x46,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
  }
  return;
}



===== UfxDevice_EvtDeviceProprietaryChargerSetProperty @ 1c0026cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceProprietaryChargerSetProperty
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x47,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x18,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
  }
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  puVar4 = PTR__WDF_PROPRIETARY_CHARGER_CONTEXT_TYPE_INFO_1c001d5b0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0xf0));
  *(undefined8 *)(lVar3 + 8) = param_2;
  (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0xf0));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x19,
                       &WPP_5e10b54914fd3cc709f21bcabebf43cb_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar4,0x48,
                       &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
    }
  }
  return;
}



===== UfxDevice_EvtDeviceRemoteWakeupSignal @ 1c0026e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceRemoteWakeupSignal(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint *puVar5;
  uint *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  byte bVar10;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar11;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar11 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3c,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  puVar7 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar3,PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778);
  uVar8 = CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                    (WdfDriverGlobals,*puVar3,uVar8,0,CONCAT44(uVar11,0x496),
                     "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxdevice.c");
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar4 + 600),2,uVar8,0x3d,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)uVar2);
    }
  }
  else {
    *(undefined1 *)(lVar4 + 0x68) = 1;
    puVar5 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
    uVar1 = *puVar5;
    bVar10 = (byte)uVar1;
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer(puVar5,&RegisterRead,uVar8,(uint)puVar5 & 0xffff,bVar10);
    }
    puVar6 = (uint *)(*(longlong *)(lVar4 + 0x48) + 4);
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
      McTemplateK0qq_EtwWriteTransfer
                (puVar5,&RegisterWrite,uVar8,(uint)puVar6 & 0xffff,bVar10 & 0x1f);
    }
    *puVar6 = uVar1 & 0xffffff1f | 0x100;
    LOCK();
    UNLOCK();
    (**(code **)(WdfFunctions_01015 + 0xdb8))
              (WdfDriverGlobals,*puVar3,0,0x4a7,
               "onecore\\drivers\\wdm\\usb\\usbfn\\client\\ufxsynopsys\\src\\ufxdevice.c");
  }
  uVar9 = (ulonglong)uVar2;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar9,0x3e,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UfxDevice_EvtDeviceUsbStateChange @ 1c0027080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UfxDevice_EvtDeviceUsbStateChange(undefined8 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined *puVar11;
  ulonglong uVar12;
  uint *puVar13;
  undefined1 uVar14;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x29,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UFXDEVICE_CONTEXT_TYPE_INFO_1c001d628);
  uVar8 = *puVar4;
  puVar11 = PTR__WDF_CONTROLLER_CONTEXT_TYPE_INFO_1c001d778;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  iVar1 = *(int *)(puVar4 + 0x23);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(lVar5 + 600),uVar8,puVar11,0x2a,
                      &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)param_2);
  }
  uVar12 = (ulonglong)*(uint *)((longlong)puVar4 + 0x11c);
  iVar2 = UfxDeviceStopOrResumeIdle(param_1,param_2,uVar12);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar12,0x2b,
                        &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids,(char)iVar2);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
  }
  SynopsysEtwLogConnectedStandbyInfo();
  if (param_2 == 1) {
    if (iVar1 == 3) {
      *(bool *)((longlong)puVar4 + 0x121) = *(longlong *)(lVar5 + 200) != 0;
    }
  }
  else if ((param_2 == 5) && (iVar1 != 6)) {
    uVar9 = 1;
    while( true ) {
      uVar10 = (ulonglong)uVar9;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,puVar4[1]);
      if (uVar3 <= uVar9) break;
      uVar8 = puVar4[1];
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals);
      UfxEndpointConfigure(uVar6,uVar8,uVar10);
      uVar9 = uVar9 + 1;
      uVar12 = uVar10;
    }
    if ((*(uint *)(lVar5 + 0x1d8) >> 10 & 1) == 0) {
      puVar7 = (uint *)(*(longlong *)(lVar5 + 0x48) + 4);
      uVar9 = *puVar7;
      uVar14 = (undefined1)uVar9;
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer(puVar7,&RegisterRead,uVar12,(uint)puVar7 & 0xffff,uVar14);
      }
      puVar13 = (uint *)(*(longlong *)(lVar5 + 0x48) + 4);
      if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 2) != 0) {
        McTemplateK0qq_EtwWriteTransfer(puVar7,&RegisterWrite,uVar12,(uint)puVar13 & 0xffff,uVar14);
      }
      *puVar13 = uVar9 | 0xa00;
      LOCK();
      UNLOCK();
    }
  }
  if (*(char *)(lVar5 + 0x1c9) == '\x01') {
    SynopsysAcpiSetDeviceState(*puVar4,param_2,uVar12);
  }
  else if (*(longlong *)(lVar5 + 0x150) != 0) {
    SynopsysAttachInterfaceSetDeviceState(*puVar4,param_2,uVar12);
  }
  if (param_2 == 3) {
    KeSetEvent(lVar5 + 0x28,0);
  }
  uVar8 = 0;
  (*DAT_1c001de70)(UfxGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar8,0x2c,
                     &WPP_c853a9dc1f80304598261d9e62a9d011_Traceguids);
  }
  return;
}



===== UnregisterForCsNotifications @ 1c002736c =====

void UnregisterForCsNotifications(void)

{
  gCsNotifyCallback = 0;
  if (gPowerSettingCallbackHandle != 0) {
    PoUnregisterPowerSettingCallback();
  }
  if (gWnfSubscriptionHandle != 0) {
    ExUnsubscribeWnfStateChange();
  }
  return;
}



===== __security_init_cookie @ 1c0028008 =====

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



===== DriverEntry @ 1c002803c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStackY_d8 [32];
  ulonglong local_78 [10];
  
  local_78[9] = __security_cookie ^ (ulonglong)auStackY_d8;
  local_78[0] = (ulonglong)(uint)local_78[0];
  local_78[7] = 0;
  local_78[8] = 0;
  McGenEventRegister_EtwRegister();
  _WPP_MAIN_CB = 0;
  DAT_1c001df28 = &WPP_ThisDir_CTLGUID_SynopsysWPPGuid;
  DAT_1c001df30 = 0;
  _DAT_1c001df40 = 0;
  _DAT_1c001df48 = 1;
  _DAT_1c001df60 = 0;
  _DAT_1c001df68 = 0;
  WppLoadTracingSupport();
  _DAT_1c001df40 = 0;
  WppInitKm(param_1,param_2);
  local_78[7] = CONCAT35(local_78[7]._5_3_,0x100000010);
  local_78[8] = 0x200000001;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,local_78 + 7);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,10,
                     &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids);
  }
  local_78[6] = 0;
  local_78[2] = 0;
  local_78[1] = 0;
  local_78[0] = 0x38;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[3] = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,local_78);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xb,
                        &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids,(char)iVar1);
    }
    if ((Microsoft_WindowsPhone_UfxSynopsysEnableBits & 1) != 0) {
      McTemplateK0sqq_EtwWriteTransfer();
    }
    WppCleanupKm(param_1);
    McGenEventUnregister_EtwUnregister();
  }
  else {
    RegisterForCsNotifications();
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_2,0xc,
                       &WPP_8422343cfe873a1380c66251f0221fbf_Traceguids);
    }
  }
  return iVar1;
}



===== RegisterForCsNotifications @ 1c002827c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RegisterForCsNotifications(void)

{
  int iVar1;
  undefined1 auStack_48 [32];
  code *local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_20 = 0;
  local_18 = 0x41c6013da3bc0875;
  local_28 = CsNotifyWnfCallback;
  iVar1 = ExSubscribeWnfStateChange(&gWnfSubscriptionHandle,&local_18,1);
  if (iVar1 < 0) {
    gWnfSubscriptionHandle = 0;
  }
  else {
    local_28 = (code *)&gPowerSettingCallbackHandle;
    iVar1 = PoRegisterPowerSettingCallback
                      (0,&GUID_PDC_IDLE_RESILIENCY_ENGAGED,IdleResiliencySettingCallback,0);
    if (-1 < iVar1) {
      gCsNotifyCallback = SynopsysCsNotifyCallback;
      return;
    }
    gPowerSettingCallbackHandle = 0;
  }
  UnregisterForCsNotifications();
  return;
}


