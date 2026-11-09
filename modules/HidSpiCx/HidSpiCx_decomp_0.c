
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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
  *param_6 = PTR_DAT_14001a048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14001a048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14001a060,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== <lambda_invoker_cdecl> @ 1400010d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_0eb4ccaa4a77b54fe32dd9f977a723f3>::<lambda_invoker_cdecl>(undefined8 param_1)

{
  CxDevice *this;
  
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtPostPrepareHardware(this);
  return;
}



===== <lambda_invoker_cdecl> @ 140001110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_3a04e05a417483df07b23118ebb1e804>::<lambda_invoker_cdecl>
               (undefined8 param_1,_IRP *param_2,void *param_3)

{
  CxDevice *this;
  
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtWdmIrpPreprocess(this,param_2,param_3);
  return;
}



===== <lambda_invoker_cdecl> @ 140001170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_8cdcb6676c41e398f8d01040a1be6dce>::<lambda_invoker_cdecl>(undefined8 param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)(WdfFunctions_01031 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 == '\0')) {
    (**(code **)(WdfFunctions_01031 + 0x520))(WdfDriverGlobals,*(undefined8 *)(pcVar1 + 0x40));
  }
  return;
}



===== <lambda_invoker_cdecl> @ 1400011d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int <lambda_b17cc146140b155744e9db98374e935b>::<lambda_invoker_cdecl>
              (undefined8 param_1,char param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffb0;
  
  pcVar3 = (char *)(**(code **)(WdfFunctions_01031 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  if ((pcVar3 == (char *)0x0) || (*pcVar3 != '\0')) {
    iVar2 = 0;
  }
  else {
    bVar1 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar4 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,4,
                 in_stack_ffffffffffffffb0,0x21,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                 (char)pcVar3,param_2 + -1);
    }
    HidSpiDevice::SetPowerOn(*(HidSpiDevice **)(pcVar3 + 0xb8));
    iVar2 = KeWaitForSingleObject(pcVar3 + 0xf0,0,0,0,0);
    if (iVar2 == 0) {
      iVar2 = *(int *)(pcVar3 + 0xe8);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar1) || (bVar6)) {
        uVar4 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,uVar4,2,
                   in_stack_ffffffffffffffb0,0x22,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                   (char)pcVar3,(char)iVar2);
      }
    }
  }
  return iVar2;
}



===== <lambda_invoker_cdecl> @ 140001390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_bfd87e50b7a722585d0162d63baacbeb>::<lambda_invoker_cdecl>
               (undefined8 param_1,_IRP *param_2,void *param_3)

{
  CxDevice *this;
  
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtPnpStopIrpPreprocess(this,param_2,param_3);
  return;
}



===== <lambda_invoker_cdecl> @ 1400013f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_c55067a657b9e79bb2dab387c21bb61a>::<lambda_invoker_cdecl>
               (undefined8 param_1,WDFREQUEST__ *param_2)

{
  undefined8 uVar1;
  CxDevice *this;
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x4e8))(WdfDriverGlobals,param_1);
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtSelfIo(this,param_2);
  return;
}



===== <lambda_invoker_cdecl> @ 140001460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_d8acab477fcb6eda44b4297b0fa58d14>::<lambda_invoker_cdecl>
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,__uint64 param_4,
               ulong param_5)

{
  long lVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  undefined *puVar5;
  bool bVar6;
  
  uVar3 = (**(code **)(WdfFunctions_01031 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar5 = PTR__WDF_CxDevice_TYPE_INFO_140017090;
  lVar2 = (**(code **)(WdfFunctions_01031 + 0x650))(WdfDriverGlobals,uVar3);
  lVar1 = HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::EvtDeviceIoControl
                    (*(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)(lVar2 + 0xa8),
                     param_2,(__uint64)puVar5,param_4,param_5);
  if (lVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar4 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar6)) {
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,uVar3);
    }
    (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  }
  return;
}



===== <lambda_invoker_cdecl> @ 1400015a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_d9ea304143e555c250204b0ba65fd2d9>::<lambda_invoker_cdecl>(undefined8 param_1)

{
  CxDevice *this;
  
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtPreReleaseHardware(this);
  return;
}



===== <lambda_invoker_cdecl> @ 1400015e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_dfd60797b33275f96c55844c9e52654e>::<lambda_invoker_cdecl>
               (undefined8 param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  CxDevice *this;
  
  this = (CxDevice *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_140017090);
  CxDevice::EvtD0ExitPreHardwareDisabled(this,param_2);
  return;
}



===== <lambda_invoker_cdecl> @ 140001630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static __cdecl <lambda_e02dfa3165444d199da10aaadebb0ca3>::<lambda_invoker_cdecl>(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl
<lambda_e02dfa3165444d199da10aaadebb0ca3>::<lambda_invoker_cdecl>(WDFWORKITEM__ *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01031 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_HidClassMinidriverWorkItemContext_TYPE_INFO_1400170b8);
  lVar4 = (**(code **)(WdfFunctions_01031 + 0x8e8))(WdfDriverGlobals,*puVar3);
  puVar1 = *(undefined8 **)(*(longlong *)(lVar4 + 0xb8) + 0x20);
  if (puVar1 == (undefined8 *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    (*(code *)*puVar1)(puVar1[1]);
    iVar2 = (**(code **)(WdfFunctions_01031 + 0x8c8))(WdfDriverGlobals,*puVar3,puVar3[1]);
    if (-1 < iVar2) {
      return;
    }
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,*puVar3,iVar2);
  return;
}



===== ~HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> @ 1400016f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl HidClassMinidriver<class HidSpiRequestManager,class
   HidSpiRequest>::~HidClassMinidriver<class HidSpiRequestManager,class HidSpiRequest>(void) __ptr64
    */

void __thiscall
HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::
~HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>
          (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this)

{
  if (*(longlong *)(this + 0x28) != 0) {
    (**(code **)(WdfFunctions_01031 + 0xbf0))(WdfDriverGlobals);
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0x28));
    *(undefined8 *)(this + 0x28) = 0;
  }
  if (*(longlong *)(this + 0x10) != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(this + 0x10) = 0;
  }
  if (*(longlong *)(this + 0x18) != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(this + 0x18) = 0;
  }
  if (*(longlong *)(this + 0x20) != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(this + 0x20) = 0;
  }
  if (*(_RefCountBase **)(this + 8) != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(*(_RefCountBase **)(this + 8));
  }
  return;
}



===== ~lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_> @ 1400017d4 =====

void wil::details::lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>::
     ~lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>(longlong *param_1)

{
  longlong lVar1;
  _RefCountBase *p_Var2;
  
  if ((char)param_1[1] != '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    lVar1 = *param_1;
    p_Var2 = *(_RefCountBase **)(lVar1 + 0xc0);
    *(undefined8 *)(lVar1 + 0xc0) = 0;
    *(undefined8 *)(lVar1 + 0xb8) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
    lVar1 = *param_1;
    p_Var2 = *(_RefCountBase **)(lVar1 + 0xd0);
    *(undefined8 *)(lVar1 + 0xd0) = 0;
    *(undefined8 *)(lVar1 + 200) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
    lVar1 = *param_1;
    p_Var2 = *(_RefCountBase **)(lVar1 + 0xb0);
    *(undefined8 *)(lVar1 + 0xb0) = 0;
    *(undefined8 *)(lVar1 + 0xa8) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
    lVar1 = *param_1;
    p_Var2 = *(_RefCountBase **)(lVar1 + 0xe0);
    *(undefined8 *)(lVar1 + 0xe0) = 0;
    *(undefined8 *)(lVar1 + 0xd8) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
  }
  return;
}



===== CheckIfDeviceNeedsResetOnPowerOn @ 140001888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl CxDevice::CheckIfDeviceNeedsResetOnPowerOn(void) __ptr64 */

bool __thiscall CxDevice::CheckIfDeviceNeedsResetOnPowerOn(CxDevice *this)

{
  undefined8 uVar1;
  char cVar2;
  bool bVar3;
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffffd0;
  
  local_res8[0] = 0;
  (**(code **)(this + 0x98))(*(undefined8 *)(this + 0x60),local_res8);
  if (local_res8[0] == 2) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
    bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar2 != '\0') || (bVar3)) {
      uVar1 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,uVar1,4,
                 in_stack_ffffffffffffffd0,0x2d,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                 (char)this);
    }
    bVar3 = true;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar2 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar2 = '\0';
    }
    bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar2 != '\0') || (bVar3)) {
      uVar1 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,uVar1,4,
                 in_stack_ffffffffffffffd0,0x2e,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                 (char)this);
    }
    bVar3 = false;
  }
  return bVar3;
}



===== CreateAndInitialize @ 1400019f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CxDevice::CreateAndInitialize(struct WDFDEVICE__ * __ptr64,struct
   _HIDSPICX_DEVICE_CONFIG * __ptr64) */

long __cdecl CxDevice::CreateAndInitialize(WDFDEVICE__ *param_1,_HIDSPICX_DEVICE_CONFIG *param_2)

{
  CxDevice *pCVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  CxDevice *local_res18 [2];
  undefined8 in_stack_ffffffffffffff70;
  ulonglong local_68 [6];
  undefined *local_38;
  
  local_res18[0] = (CxDevice *)0x0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_68[0] = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_68[0] = 0xffffffff;
  }
  else {
    local_68[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  local_38 = PTR__WDF_CxDevice_TYPE_INFO_140017090;
  cVar4 = '\x01';
  local_68[3] = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x658))(WdfDriverGlobals,param_1,local_68,local_res18);
  pCVar1 = local_res18[0];
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffff70,0xb,
                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,(char)param_1,(char)iVar2);
    }
  }
  else {
    *local_res18[0] = (CxDevice)0x0;
    local_res18[0][0xa0] = (CxDevice)0x0;
    *(undefined8 *)(local_res18[0] + 0xa8) = 0;
    *(undefined8 *)(local_res18[0] + 0xb0) = 0;
    *(undefined8 *)(local_res18[0] + 0xb8) = 0;
    *(undefined8 *)(local_res18[0] + 0xc0) = 0;
    *(undefined8 *)(local_res18[0] + 200) = 0;
    *(undefined8 *)(local_res18[0] + 0xd0) = 0;
    *(undefined8 *)(local_res18[0] + 0xd8) = 0;
    *(undefined8 *)(local_res18[0] + 0xe0) = 0;
    *(undefined2 *)(local_res18[0] + 0x120) = 0;
    *(undefined4 *)(local_res18[0] + 0x124) = 0;
    *(WDFDEVICE__ **)(local_res18[0] + 0x38) = param_1;
    iVar2 = Initialize(local_res18[0],param_2);
    if (-1 < iVar2) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar4 = '\0';
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar4 != '\0') || (bVar5)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,uVar3,4,
                   in_stack_ffffffffffffff70,0xc,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                   (char)pCVar1,(char)param_1);
      }
    }
  }
  return iVar2;
}



===== EvtD0ExitPreHardwareDisabled @ 140001c3c =====

/* private: long __cdecl CxDevice::EvtD0ExitPreHardwareDisabled(enum _WDF_POWER_DEVICE_STATE)
   __ptr64 */

long __thiscall
CxDevice::EvtD0ExitPreHardwareDisabled(CxDevice *this,_WDF_POWER_DEVICE_STATE param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  HidSpiDeviceNeedsResetOnPowerOn HVar5;
  bool bVar6;
  HidSpiDevicePowerState local_res18;
  undefined8 in_stack_ffffffffffffff80;
  
  if ((this == (CxDevice *)0x0) || (*this != (CxDevice)0x0)) {
    iVar2 = 0;
  }
  else {
    bVar1 = true;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar6)) {
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,uVar3,4,
                 in_stack_ffffffffffffff80,0x23,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                 (char)this,(char)param_1 + -1);
    }
    if ((this[0x120] == (CxDevice)0x0) || (local_res18 = 2, 4 < (int)param_1)) {
      local_res18 = 3;
    }
    if (this[0x121] == (CxDevice)0x0) {
      HVar5 = (HidSpiDeviceNeedsResetOnPowerOn)(3 < (int)param_1);
    }
    else if (this[0x120] == (CxDevice)0x0) {
      HVar5 = 1;
    }
    else if (((int)param_1 < 4) || (this[0xa0] == (CxDevice)0x0)) {
      HVar5 = 0;
    }
    else {
      HVar5 = 2;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar6)) {
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qLlll(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,uVar3);
    }
    HidSpiDevice::SetPowerDown(*(HidSpiDevice **)(this + 0xb8),local_res18,HVar5);
    this[0x120] = (CxDevice)0x0;
    iVar2 = KeWaitForSingleObject(this + 0xf0,0,0,0,0);
    if (iVar2 == 0) {
      iVar2 = *(int *)(this + 0xe8);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar1) || (bVar6)) {
        uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,uVar3,2,
                   in_stack_ffffffffffffff80,0x25,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                   (char)this,(char)iVar2);
      }
    }
  }
  return iVar2;
}



===== EvtDeviceIoControl @ 140001ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidClassMinidriver<class HidSpiRequestManager,class
   HidSpiRequest>::EvtDeviceIoControl(struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned
   __int64,unsigned long) __ptr64 */

long __thiscall
HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::EvtDeviceIoControl
          (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this,WDFREQUEST__ *param_1,
          __uint64 param_2,__uint64 param_3,ulong param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  longlong lVar3;
  HidSpiRequest *pHVar4;
  long lVar5;
  int iVar6;
  undefined8 *puVar7;
  ulong uVar8;
  HidSpiRequest *local_res18;
  undefined8 local_res20;
  undefined8 local_68;
  ulonglong local_60 [2];
  longlong *local_50;
  ulong *local_48;
  HidSpiRequest **local_40;
  undefined1 local_38;
  
  uVar8 = param_4;
  local_res18 = (HidSpiRequest *)param_2;
  local_res20 = param_3;
  if (param_4 == 0xb000b) {
    lVar5 = (**(code **)(WdfFunctions_01031 + 0x8c8))
                      (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x10));
    return lVar5;
  }
  if (param_4 == 0xb0233) {
    lVar5 = (**(code **)(WdfFunctions_01031 + 0x8c8))
                      (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x18));
    return lVar5;
  }
  if (param_4 == 0xb002b) {
    puVar7 = (undefined8 *)
             (**(code **)(WdfFunctions_01031 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(this + 0x28),
                        PTR__WDF_HidClassMinidriverWorkItemContext_TYPE_INFO_1400170b8);
    *puVar7 = param_1;
    puVar7[1] = *(undefined8 *)(this + 0x20);
    (**(code **)(WdfFunctions_01031 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(this + 0x28));
    return 0;
  }
  local_res18 = (HidSpiRequest *)0x0;
  lVar5 = HidSpiRequest::CreateRequestFromWdfRequest(param_1,&local_res18);
  if (lVar5 < 0) {
    return lVar5;
  }
  if (uVar8 < 0xb0028) {
    if (uVar8 == 0xb0027) {
      local_res20 = 0;
      local_60[0] = 0;
      iVar6 = (**(code **)(WdfFunctions_01031 + 0x870))
                        (WdfDriverGlobals,param_1,0,&local_res20,local_60);
      if (iVar6 < 0) {
        return iVar6;
      }
      *(__uint64 *)(local_res18 + 0x18) = local_res20;
      *(ulonglong *)(local_res18 + 0x20) = local_60[0];
      *(__uint64 *)(local_res18 + 0x38) = local_res20;
      *(ulonglong *)(local_res18 + 0x40) = local_60[0];
      local_48 = &param_4;
      local_50 = *(longlong **)this;
      local_40 = &local_res18;
      param_4 = 0;
      local_38 = 1;
      if (local_60[0] < 0x20) {
        param_4 = 0xc0000206;
      }
      else {
        lVar3 = *local_50;
        if (*(char *)(lVar3 + 0x60) == '\0') {
          param_4 = 0xc00000a3;
        }
        else {
          uVar1 = *(undefined2 *)(lVar3 + 0x54);
          uVar2 = *(undefined2 *)(lVar3 + 0x56);
          *(undefined2 *)(local_res20 + 8) = *(undefined2 *)(lVar3 + 0x58);
          *(undefined2 *)(local_res20 + 4) = uVar1;
          *(undefined2 *)(local_res20 + 6) = uVar2;
          (**(code **)(WdfFunctions_01031 + 0x898))
                    (WdfDriverGlobals,*(undefined8 *)local_res18,0x20);
        }
      }
      wil::details::lambda_call<<lambda_161f2748ff1ff1f71933cab8c395b34a>_>::
      ~lambda_call<<lambda_161f2748ff1ff1f71933cab8c395b34a>_>((longlong *)&local_50);
      return iVar6;
    }
    if (uVar8 == 0xb0003) {
      local_60[0] = 0;
      local_res20 = 0;
      iVar6 = (**(code **)(WdfFunctions_01031 + 0x870))
                        (WdfDriverGlobals,param_1,0,local_60,&local_res20);
      if (iVar6 < 0) {
        return iVar6;
      }
      *(ulonglong *)(local_res18 + 0x18) = local_60[0];
      *(__uint64 *)(local_res18 + 0x20) = local_res20;
      *(ulonglong *)(local_res18 + 0x38) = local_60[0];
      *(__uint64 *)(local_res18 + 0x40) = local_res20;
      HidSpiRequestManager::HidGetDeviceDescriptor(*(HidSpiRequestManager **)this,local_res18);
      return iVar6;
    }
    if (uVar8 == 0xb0007) {
      local_60[0] = 0;
      local_res20 = 0;
      iVar6 = (**(code **)(WdfFunctions_01031 + 0x870))
                        (WdfDriverGlobals,param_1,0,local_60,&local_res20);
      if (iVar6 < 0) {
        return iVar6;
      }
      *(ulonglong *)(local_res18 + 0x18) = local_60[0];
      *(__uint64 *)(local_res18 + 0x20) = local_res20;
      *(ulonglong *)(local_res18 + 0x38) = local_60[0];
      *(__uint64 *)(local_res18 + 0x40) = local_res20;
      HidSpiRequestManager::HidGetReportDescriptor(*(HidSpiRequestManager **)this,local_res18);
      return iVar6;
    }
    if (uVar8 != 0xb000f) {
      if (uVar8 == 0xb0013) {
        local_res20 = (ulonglong)local_res20._4_4_ << 0x20;
        param_4 = 0;
        local_60[0] = 0;
        local_68 = 0;
        lVar5 = HidClassMinidriverHelpers::GetStringId(param_1,&param_4,(ulong *)&local_res20);
        if (lVar5 < 0) {
          return lVar5;
        }
        iVar6 = (**(code **)(WdfFunctions_01031 + 0x870))
                          (WdfDriverGlobals,param_1,0,local_60,&local_68);
        if (iVar6 < 0) {
          return iVar6;
        }
        *(ulonglong *)(local_res18 + 0x18) = local_60[0];
        *(undefined8 *)(local_res18 + 0x20) = local_68;
        *(ulonglong *)(local_res18 + 0x38) = local_60[0];
        *(undefined8 *)(local_res18 + 0x40) = local_68;
        HidSpiRequestManager::HidGetString
                  (*(HidSpiRequestManager **)this,local_res18,(ulong)local_res20,param_4);
        return iVar6;
      }
      if (uVar8 == 0xb001f) {
        local_60[0] = 0;
        local_res20 = 0;
        iVar6 = (**(code **)(WdfFunctions_01031 + 0x868))
                          (WdfDriverGlobals,param_1,0,local_60,&local_res20);
        pHVar4 = local_res18;
        if (iVar6 < 0) {
          return iVar6;
        }
        if (local_res20 == 4) {
          uVar8 = 0;
          (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,*(undefined8 *)local_res18);
          HidSpiRequestManager::HidActivateDevice(*(HidSpiRequestManager **)this,pHVar4,uVar8);
          return iVar6;
        }
      }
      else {
        if (uVar8 != 0xb0023) {
          return -0x3fffff45;
        }
        local_60[0] = 0;
        local_res20 = 0;
        iVar6 = (**(code **)(WdfFunctions_01031 + 0x868))
                          (WdfDriverGlobals,param_1,0,local_60,&local_res20);
        pHVar4 = local_res18;
        if (iVar6 < 0) {
          return iVar6;
        }
        if (local_res20 == 4) {
          uVar8 = 0;
          (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,*(undefined8 *)local_res18);
          HidSpiRequestManager::HidDeactivateDevice(*(HidSpiRequestManager **)this,pHVar4,uVar8);
          return iVar6;
        }
      }
      return -0x3ffffff3;
    }
  }
  else {
    if (uVar8 == 0xb0191) {
      local_60[0] = 0;
      local_60[1] = 0;
      lVar5 = HidClassMinidriverHelpers::RequestGetHidXferPacket_ToWriteToDevice
                        (param_1,(_HID_XFER_PACKET *)local_60);
      if (lVar5 < 0) {
        return lVar5;
      }
      HidSpiRequestManager::HidSetFeature
                (*(HidSpiRequestManager **)this,local_res18,(_HID_XFER_PACKET *)local_60);
      return lVar5;
    }
    if (uVar8 == 0xb0192) {
      local_60[0] = 0;
      local_60[1] = 0;
      lVar5 = HidClassMinidriverHelpers::RequestGetHidXferPacket_ToReadFromDevice
                        (param_1,(_HID_XFER_PACKET *)local_60);
      if (lVar5 < 0) {
        return lVar5;
      }
      HidSpiRequestManager::HidGetFeature
                (*(HidSpiRequestManager **)this,local_res18,(_HID_XFER_PACKET *)local_60);
      return lVar5;
    }
    if (uVar8 != 0xb0195) {
      if (uVar8 == 0xb01a2) {
        local_60[0] = 0;
        local_60[1] = 0;
        lVar5 = HidClassMinidriverHelpers::RequestGetHidXferPacket_ToReadFromDevice
                          (param_1,(_HID_XFER_PACKET *)local_60);
        if (lVar5 < 0) {
          return lVar5;
        }
        HidSpiRequestManager::HidGetInputReport
                  (*(HidSpiRequestManager **)this,local_res18,(_HID_XFER_PACKET *)local_60);
        return lVar5;
      }
      if (uVar8 != 0xb01e2) {
        return -0x3fffff45;
      }
      param_4 = 0;
      local_res20 = (ulonglong)local_res20._4_4_ << 0x20;
      local_68 = 0;
      local_60[0] = 0;
      lVar5 = HidClassMinidriverHelpers::GetStringId(param_1,(ulong *)&local_res20,&param_4);
      if (lVar5 < 0) {
        return lVar5;
      }
      puVar7 = &local_68;
      uVar8 = 0;
      iVar6 = (**(code **)(WdfFunctions_01031 + 0x870))(WdfDriverGlobals,param_1,0,puVar7,local_60);
      if (iVar6 < 0) {
        return iVar6;
      }
      *(undefined8 *)(local_res18 + 0x18) = local_68;
      *(ulonglong *)(local_res18 + 0x20) = local_60[0];
      *(undefined8 *)(local_res18 + 0x38) = local_68;
      *(ulonglong *)(local_res18 + 0x40) = local_60[0];
      HidSpiRequestManager::HidGetIndexedString
                (*(HidSpiRequestManager **)this,local_res18,uVar8,(ulong)puVar7);
      return iVar6;
    }
  }
  local_60[0] = 0;
  local_60[1] = 0;
  lVar5 = HidClassMinidriverHelpers::RequestGetHidXferPacket_ToWriteToDevice
                    (param_1,(_HID_XFER_PACKET *)local_60);
  if (-1 < lVar5) {
    HidSpiRequestManager::HidWriteReport
              (*(HidSpiRequestManager **)this,local_res18,(_HID_XFER_PACKET *)local_60);
  }
  return lVar5;
}



===== EvtPnpStopIrpPreprocess @ 140002514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CxDevice::EvtPnpStopIrpPreprocess(struct _IRP * __ptr64,void * __ptr64)
   __ptr64 */

long __thiscall CxDevice::EvtPnpStopIrpPreprocess(CxDevice *this,_IRP *param_1,void *param_2)

{
  longlong lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffb0;
  
  if (((this == (CxDevice *)0x0) || (*this != (CxDevice)0x0)) || (*(longlong *)(this + 0xa8) == 0))
  {
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
    uVar4 = *(undefined8 *)(this + 0x38);
  }
  else {
    local_res8 = 0;
    (**(code **)(WdfFunctions_01031 + 0x4f0))
              (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 0xa8) + 0x18),&local_res8);
    lVar1 = local_res8;
    if (local_res8 != 0) {
      iVar2 = (**(code **)(WdfFunctions_01031 + 0x8c8))
                        (WdfDriverGlobals,local_res8,*(undefined8 *)(this + 0x50));
      if (iVar2 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar5 != '\0') || (bVar6)) {
          uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,
                     in_stack_ffffffffffffffb0,0x28,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids
                     ,(char)this,(char)iVar2);
        }
        (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,lVar1,0xc00000e5);
      }
    }
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
    uVar4 = *(undefined8 *)(this + 0x38);
  }
  lVar3 = (**(code **)(WdfFunctions_01031 + 0xc88))(WdfDriverGlobals,uVar4,param_1,param_2);
  return lVar3;
}



===== EvtPostPrepareHardware @ 1400026cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CxDevice::EvtPostPrepareHardware(void) __ptr64 */

long __thiscall CxDevice::EvtPostPrepareHardware(CxDevice *this)

{
  CxDevice *_Dst;
  HidSpiCxReportInterface *pHVar1;
  CxDevice *pCVar2;
  shared_ptr<HidSpiRequestManager> *psVar3;
  undefined4 uVar4;
  _RefCountBase *p_Var5;
  longlong lVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this_00;
  undefined8 *puVar10;
  undefined8 *puVar11;
  HidSpiCxReportInterface *pHVar12;
  HidSpiDevice *pHVar13;
  nothrow_t *pnVar14;
  bool bVar15;
  char cVar16;
  bool bVar17;
  undefined8 local_res8 [4];
  undefined2 in_stack_ffffffffffffff50;
  undefined6 in_stack_ffffffffffffff52;
  undefined2 uVar18;
  undefined1 uVar19;
  CxDevice *local_80;
  undefined1 local_78;
  undefined8 local_70;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  
  if ((this == (CxDevice *)0x0) || (*this != (CxDevice)0x0)) {
    return 0;
  }
  bVar15 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar16 = '\0';
  }
  bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  uVar19 = SUB81(this,0);
  if ((cVar16 != '\0') || (bVar17)) {
    uVar9 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,bVar17,uVar9,4,
               CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x11,
               &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19);
  }
  _Dst = this + 0x58;
  local_78 = 1;
  pnVar14 = (nothrow_t *)0x0;
  local_80 = this;
  memset(_Dst,0,0x48);
  this[0xa0] = (CxDevice)0x0;
  if (this[0x121] != (CxDevice)0x0) {
    pnVar14 = *(nothrow_t **)(this + 0x38);
    in_stack_ffffffffffffff50 = 1;
    iVar7 = (**(code **)(WdfFunctions_01031 + 0x418))
                      (WdfDriverGlobals,pnVar14,&GUID_D3COLD_SUPPORT_INTERFACE,_Dst,0x48,1,0);
    if (iVar7 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar16 = '\0';
      }
      bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar16 != '\0') || (pnVar14 = (nothrow_t *)WPP_GLOBAL_Control, bVar17)) {
        uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        pnVar14 = (nothrow_t *)CONCAT71(0x140014b,cVar16);
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,bVar17,uVar9,3,
                   CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x12,
                   &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19,(char)iVar7);
      }
    }
    else {
      this[0xa0] = (CxDevice)0x1;
    }
  }
  pCVar2 = this + 0xa8;
  this_00 = operator_new(0x30,pnVar14);
  if (this_00 == (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *)0x0) {
    this_00 = (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *)0x0;
  }
  else {
    *(undefined8 *)this_00 = 0;
    *(undefined8 *)(this_00 + 8) = 0;
    *(undefined8 *)(this_00 + 0x10) = 0;
    *(undefined8 *)(this_00 + 0x18) = 0;
    *(undefined8 *)(this_00 + 0x20) = 0;
    *(undefined8 *)(this_00 + 0x28) = 0;
  }
  puVar10 = operator_new(0x18,pnVar14);
  if (puVar10 == (undefined8 *)0x0) {
    if (this_00 != (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *)0x0) {
      HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::
      ~HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>(this_00);
      pnVar14 = (nothrow_t *)0x58435348;
      ExFreePoolWithTag(this_00);
    }
  }
  else {
    *(undefined4 *)(puVar10 + 1) = 1;
    *(undefined4 *)((longlong)puVar10 + 0xc) = 1;
    *puVar10 = &utl::
                _RefCountVtable<utl::_RefCountNormal<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>*___ptr64,utl::default_delete<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>_>,utl::allocator<int>_>,0>
                ::_vftable_;
    puVar10[2] = this_00;
    p_Var5 = *(_RefCountBase **)(this + 0xb0);
    *(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)pCVar2 = this_00;
    *(undefined8 **)(this + 0xb0) = puVar10;
    if (p_Var5 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var5);
    }
  }
  if (*(longlong *)pCVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar15 = false;
    }
    bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar15 != false) || (bVar17)) {
      uVar9 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,2,
                 CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x13,
                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19);
    }
    if (*(code **)(this + 0x70) != (code *)0x0) {
      (**(code **)(this + 0x70))(*(undefined8 *)(this + 0x60));
LAB_140002dc3:
      memset(_Dst,0,0x48);
    }
  }
  else {
    psVar3 = (shared_ptr<HidSpiRequestManager> *)(this + 200);
    puVar10 = operator_new(0x18,pnVar14);
    if (puVar10 == (undefined8 *)0x0) {
      puVar10 = (undefined8 *)0x0;
    }
    else {
      puVar10[2] = 0;
      *puVar10 = 0;
      puVar10[1] = 0;
    }
    puVar11 = operator_new(0x18,pnVar14);
    if (puVar11 == (undefined8 *)0x0) {
      if (puVar10 != (undefined8 *)0x0) {
        if ((_RefCountBase *)puVar10[1] != (_RefCountBase *)0x0) {
          utl::_RefCountBase::_DecStrong((_RefCountBase *)puVar10[1]);
        }
        pnVar14 = (nothrow_t *)0x58435348;
        ExFreePoolWithTag(puVar10);
      }
    }
    else {
      *(undefined4 *)(puVar11 + 1) = 1;
      *(undefined4 *)((longlong)puVar11 + 0xc) = 1;
      *puVar11 = &utl::
                  _RefCountVtable<utl::_RefCountNormal<HidSpiRequestManager*___ptr64,utl::default_delete<HidSpiRequestManager>,utl::allocator<int>_>,0>
                  ::_vftable_;
      puVar11[2] = puVar10;
      p_Var5 = *(_RefCountBase **)(this + 0xd0);
      *(undefined8 **)psVar3 = puVar10;
      *(undefined8 **)(this + 0xd0) = puVar11;
      if (p_Var5 != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong(p_Var5);
      }
    }
    if (*(longlong *)psVar3 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar15 = false;
      }
      bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar15 != false) || (bVar17)) {
        uVar9 = imp_WppRecorderLogGetDefault();
        uVar18 = 0x14;
LAB_140002d8e:
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,2,
                   CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),uVar18,
                   &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19);
      }
    }
    else {
      pHVar12 = operator_new(0x88,pnVar14);
      if (pHVar12 == (HidSpiCxReportInterface *)0x0) {
        pHVar12 = (HidSpiCxReportInterface *)0x0;
      }
      else {
        pnVar14 = (nothrow_t *)0x0;
        memset(pHVar12,0,0x88);
        pHVar1 = pHVar12 + 0x38;
        *(undefined8 *)(pHVar12 + 0x10) = 0;
        *(HidSpiCxReportInterface **)pHVar1 = pHVar1;
        *(HidSpiCxReportInterface **)(pHVar12 + 0x40) = pHVar1;
        *(undefined8 *)(pHVar12 + 0x48) = 0;
        pHVar1 = pHVar12 + 0x50;
        *(HidSpiCxReportInterface **)pHVar1 = pHVar1;
        *(HidSpiCxReportInterface **)(pHVar12 + 0x58) = pHVar1;
        *(undefined8 *)(pHVar12 + 0x60) = 0;
        *(undefined8 *)(pHVar12 + 0x28) = 0;
        pHVar12[0x30] = (HidSpiCxReportInterface)0x1;
        *(undefined8 *)(pHVar12 + 0x68) = 0;
        *(undefined8 *)(pHVar12 + 0x70) = 0;
        *(undefined8 *)(pHVar12 + 0x78) = 0;
        *(undefined8 *)(pHVar12 + 0x80) = 0;
      }
      puVar10 = operator_new(0x18,pnVar14);
      if (puVar10 == (undefined8 *)0x0) {
        if (pHVar12 != (HidSpiCxReportInterface *)0x0) {
          HidSpiCxReportInterface::~HidSpiCxReportInterface(pHVar12);
          pnVar14 = (nothrow_t *)0x58435348;
          ExFreePoolWithTag(pHVar12);
        }
      }
      else {
        *(undefined4 *)(puVar10 + 1) = 1;
        *(undefined4 *)((longlong)puVar10 + 0xc) = 1;
        *puVar10 = &utl::
                    _RefCountVtable<utl::_RefCountNormal<HidSpiCxReportInterface*___ptr64,utl::default_delete<HidSpiCxReportInterface>,utl::allocator<int>_>,0>
                    ::_vftable_;
        puVar10[2] = pHVar12;
        p_Var5 = *(_RefCountBase **)(this + 0xe0);
        *(HidSpiCxReportInterface **)(this + 0xd8) = pHVar12;
        *(undefined8 **)(this + 0xe0) = puVar10;
        if (p_Var5 != (_RefCountBase *)0x0) {
          utl::_RefCountBase::_DecStrong(p_Var5);
        }
      }
      if (*(longlong *)(this + 0xd8) == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar15 = false;
        }
        bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar15 != false) || (bVar17)) {
          uVar9 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x15;
          goto LAB_140002d8e;
        }
      }
      else {
        pHVar13 = operator_new(0xe8,pnVar14);
        if (pHVar13 == (HidSpiDevice *)0x0) {
          pHVar13 = (HidSpiDevice *)0x0;
        }
        else {
          pnVar14 = (nothrow_t *)0x0;
          memset(pHVar13,0,0xe8);
          *(undefined8 *)(pHVar13 + 0x30) = 0;
          *(undefined8 *)(pHVar13 + 0x38) = 0;
          *(undefined8 *)(pHVar13 + 0x40) = 0;
          *(undefined8 *)(pHVar13 + 0x48) = 0;
          *(undefined8 *)(pHVar13 + 0x50) = 0;
          *(undefined8 *)(pHVar13 + 0x58) = 0;
          pHVar13[0x60] = (HidSpiDevice)0x0;
          *(undefined8 *)(pHVar13 + 0x68) = 0;
          *(undefined8 *)(pHVar13 + 0x70) = 0;
          *(undefined8 *)(pHVar13 + 0x78) = 0;
          *(undefined8 *)(pHVar13 + 0x80) = 0;
          *(undefined8 *)(pHVar13 + 0x88) = 0;
          *(undefined8 *)(pHVar13 + 0x90) = 0;
          *(undefined4 *)(pHVar13 + 0x98) = 0;
          *(undefined2 *)(pHVar13 + 0x9c) = 0;
          *(undefined8 *)(pHVar13 + 0xa0) = 0;
          *(undefined4 *)(pHVar13 + 0xa8) = 0xc00000e5;
          *(undefined8 *)(pHVar13 + 0xb0) = 0;
          *(undefined8 *)(pHVar13 + 0xb8) = 0;
          *(undefined8 *)(pHVar13 + 0xc0) = 0;
          *(undefined8 *)(pHVar13 + 200) = 0;
          *(undefined8 *)(pHVar13 + 0xd0) = 0;
          *(undefined8 *)(pHVar13 + 0xd8) = 0;
          *(undefined4 *)(pHVar13 + 0xe0) = 0;
        }
        puVar10 = operator_new(0x18,pnVar14);
        if (puVar10 == (undefined8 *)0x0) {
          if (pHVar13 != (HidSpiDevice *)0x0) {
            HidSpiDevice::~HidSpiDevice(pHVar13);
            ExFreePoolWithTag(pHVar13);
          }
        }
        else {
          *(undefined4 *)(puVar10 + 1) = 1;
          *(undefined4 *)((longlong)puVar10 + 0xc) = 1;
          *puVar10 = &utl::
                      _RefCountVtable<utl::_RefCountNormal<HidSpiDevice*___ptr64,utl::default_delete<HidSpiDevice>,utl::allocator<int>_>,0>
                      ::_vftable_;
          puVar10[2] = pHVar13;
          p_Var5 = *(_RefCountBase **)(this + 0xc0);
          *(HidSpiDevice **)(this + 0xb8) = pHVar13;
          *(undefined8 **)(this + 0xc0) = puVar10;
          if (p_Var5 != (_RefCountBase *)0x0) {
            utl::_RefCountBase::_DecStrong(p_Var5);
          }
        }
        if (*(longlong *)(this + 0xb8) != 0) {
          puVar10 = *(undefined8 **)psVar3;
          puVar10[2] = this;
          lVar6 = *(longlong *)(this + 0xc0);
          uVar9 = *(undefined8 *)(this + 0xb8);
          if (lVar6 != 0) {
            LOCK();
            *(int *)(lVar6 + 8) = *(int *)(lVar6 + 8) + 1;
            UNLOCK();
          }
          *puVar10 = uVar9;
          p_Var5 = (_RefCountBase *)puVar10[1];
          puVar10[1] = lVar6;
          if (p_Var5 != (_RefCountBase *)0x0) {
            utl::_RefCountBase::_DecStrong(p_Var5);
          }
          lVar8 = HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::Initialize
                            (*(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)pCVar2,
                             psVar3,*(WDFDEVICE__ **)(this + 0x38));
          if (lVar8 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar15 = false;
            }
            bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((bVar15 != false) || (bVar17)) {
              uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
              WPP_RECORDER_AND_TRACE_SF_qd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,2,
                         CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x18,
                         &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19,(char)lVar8);
            }
          }
          else {
            local_70 = *(undefined8 *)(this + 0xb8);
            pHVar12 = *(HidSpiCxReportInterface **)(this + 0xd8);
            uVar4 = *(undefined4 *)(this + 0x30);
            uVar9 = *(undefined8 *)(this + 0x38);
            local_68 = *(longlong *)(this + 0xc0);
            if (local_68 != 0) {
              LOCK();
              *(int *)(local_68 + 8) = *(int *)(local_68 + 8) + 1;
              UNLOCK();
            }
            lVar8 = HidSpiCxReportInterface::Initialize(pHVar12,this,&local_70,uVar9,uVar4);
            if (lVar8 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar15 = false;
              }
              bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((bVar15 != false) || (bVar17)) {
                uVar9 = imp_WppRecorderLogGetDefault();
                uVar18 = 0x19;
LAB_140003013:
                WPP_RECORDER_AND_TRACE_SF_qd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,2,
                           CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),uVar18,
                           &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19,(char)lVar8);
              }
            }
            else {
              local_60 = *(undefined8 *)(this + 0xd8);
              pHVar13 = *(HidSpiDevice **)(this + 0xb8);
              uVar9 = *(undefined8 *)(this + 0x38);
              local_58 = *(longlong *)(this + 0xe0);
              if (local_58 != 0) {
                LOCK();
                *(int *)(local_58 + 8) = *(int *)(local_58 + 8) + 1;
                UNLOCK();
              }
              lVar8 = HidSpiDevice::Initialize(pHVar13,pCVar2,&local_60,this,uVar9);
              if (-1 < lVar8) {
                local_res8[0] = 0;
                local_78 = 0;
                iVar7 = (**(code **)(WdfFunctions_01031 + 0x4f0))
                                  (WdfDriverGlobals,*(undefined8 *)(this + 0x50),local_res8);
                if (iVar7 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    bVar15 = false;
                  }
                  bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                  if ((bVar15 != false) || (bVar17)) {
                    uVar9 = imp_WppRecorderLogGetDefault();
                    WPP_RECORDER_AND_TRACE_SF_qd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,4,
                               CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x1d,
                               &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19,(char)iVar7);
                  }
                }
                else {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                    cVar16 = '\0';
                  }
                  bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                  if ((cVar16 != '\0') || (bVar17)) {
                    uVar9 = imp_WppRecorderLogGetDefault();
                    WPP_RECORDER_AND_TRACE_SF_q
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,bVar17,uVar9,4,
                               CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x1b,
                               &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19);
                  }
                  iVar7 = (**(code **)(WdfFunctions_01031 + 0x8c8))
                                    (WdfDriverGlobals,local_res8[0],
                                     *(undefined8 *)(*(longlong *)pCVar2 + 0x18));
                  if (iVar7 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                      bVar15 = false;
                    }
                    bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                    if ((bVar15) || (bVar17)) {
                      uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
                      WPP_RECORDER_AND_TRACE_SF_qd
                                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar15,bVar17,uVar9,2,
                                 CONCAT62(in_stack_ffffffffffffff52,in_stack_ffffffffffffff50),0x1c,
                                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar19,(char)iVar7
                                );
                    }
                    (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,local_res8[0],iVar7);
                  }
                }
                wil::details::lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>::
                ~lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>((longlong *)&local_80);
                return 0;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar15 = false;
              }
              bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((bVar15 != false) || (bVar17)) {
                uVar9 = imp_WppRecorderLogGetDefault();
                uVar18 = 0x1a;
                goto LAB_140003013;
              }
            }
            puVar10 = *(undefined8 **)pCVar2;
            p_Var5 = (_RefCountBase *)puVar10[1];
            puVar10[1] = 0;
            *puVar10 = 0;
            if (p_Var5 != (_RefCountBase *)0x0) {
              utl::_RefCountBase::_DecStrong(p_Var5);
            }
          }
          if (*(code **)(this + 0x70) != (code *)0x0) {
            (**(code **)(this + 0x70))(*(undefined8 *)(this + 0x60));
            memset(_Dst,0,0x48);
          }
          goto LAB_14000306a;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar15 = false;
        }
        bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar15 != false) || (bVar17)) {
          uVar9 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x16;
          goto LAB_140002d8e;
        }
      }
    }
    if (*(code **)(this + 0x70) != (code *)0x0) {
      (**(code **)(this + 0x70))(*(undefined8 *)(this + 0x60));
      goto LAB_140002dc3;
    }
  }
  lVar8 = -0x3fffff66;
LAB_14000306a:
  wil::details::lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>::
  ~lambda_call<<lambda_87fe8716ac3d5d24638cfe7dfb41127b>_>((longlong *)&local_80);
  return lVar8;
}



===== EvtPreReleaseHardware @ 1400032b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CxDevice::EvtPreReleaseHardware(void) __ptr64 */

long __thiscall CxDevice::EvtPreReleaseHardware(CxDevice *this)

{
  undefined8 *puVar1;
  _RefCountBase *p_Var2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  char cVar6;
  char cVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar9;
  
  if ((this != (CxDevice *)0x0) && (*this == (CxDevice)0x0)) {
    cVar7 = '\x01';
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)))) {
      cVar6 = '\0';
    }
    bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    uVar9 = SUB81(this,0);
    if ((cVar6 != '\0') || (bVar8)) {
      uVar5 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar8,uVar5,4,
                 in_stack_ffffffffffffffb0,0x1e,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                 uVar9);
    }
    puVar1 = *(undefined8 **)(this + 0xa8);
    if (puVar1 != (undefined8 *)0x0) {
      p_Var2 = (_RefCountBase *)puVar1[1];
      *puVar1 = 0;
      puVar1[1] = 0;
      if (p_Var2 != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong(p_Var2);
      }
    }
    p_Var2 = *(_RefCountBase **)(this + 0xd0);
    *(undefined8 *)(this + 200) = 0;
    *(undefined8 *)(this + 0xd0) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
    p_Var2 = *(_RefCountBase **)(this + 0xb0);
    *(undefined8 *)(this + 0xa8) = 0;
    *(undefined8 *)(this + 0xb0) = 0;
    if (p_Var2 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(p_Var2);
    }
    if (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 0xb8) !=
        (HidSpiDeviceStateMachine<HidSpiDevice> *)0x0) {
      HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 0xb8),2);
      iVar4 = KeWaitForSingleObject(this + 0x108,0,0,0,0);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar7 = '\0';
        }
        bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar7 != '\0') || (bVar8)) {
          uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar8,uVar5,2,
                     in_stack_ffffffffffffffb0,0x1f,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids
                     ,uVar9,(char)iVar4);
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar7 = '\0';
        }
        bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar7 != '\0') || (bVar8)) {
          uVar5 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_q
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar8,uVar5,4,
                     in_stack_ffffffffffffffb0,0x20,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids
                     ,uVar9);
        }
      }
      lVar3 = *(longlong *)(this + 0xd8);
      p_Var2 = *(_RefCountBase **)(lVar3 + 0x10);
      *(undefined8 *)(lVar3 + 8) = 0;
      *(undefined8 *)(lVar3 + 0x10) = 0;
      if (p_Var2 != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong(p_Var2);
      }
      p_Var2 = *(_RefCountBase **)(this + 0xc0);
      *(undefined8 *)(this + 0xb8) = 0;
      *(undefined8 *)(this + 0xc0) = 0;
      if (p_Var2 != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong(p_Var2);
      }
      p_Var2 = *(_RefCountBase **)(this + 0xe0);
      *(undefined8 *)(this + 0xd8) = 0;
      *(undefined8 *)(this + 0xe0) = 0;
      if (p_Var2 != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong(p_Var2);
      }
    }
    if (*(code **)(this + 0x70) != (code *)0x0) {
      (**(code **)(this + 0x70))(*(undefined8 *)(this + 0x60));
      memset(this + 0x58,0,0x48);
    }
  }
  return 0;
}



===== EvtSelfIo @ 14000359c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CxDevice::EvtSelfIo(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall CxDevice::EvtSelfIo(CxDevice *this,WDFREQUEST__ *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  bool bVar7;
  undefined1 auStackY_c8 [32];
  undefined1 in_stack_ffffffffffffff58;
  undefined7 in_stack_ffffffffffffff59;
  undefined8 in_stack_ffffffffffffff60;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    uVar1 = 0x28;
  }
  else if (WdfStructureCount < 0x34) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = *(ushort *)(WdfStructures + 0x198);
  }
  local_68 = (ulonglong)uVar1;
  cVar4 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar5 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
    cVar5 = '\0';
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
     (cVar6 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
    cVar6 = '\0';
  }
  if ((cVar5 != '\0') || (cVar6 != '\0')) {
    uVar3 = imp_WppRecorderLogGetDefault();
    in_stack_ffffffffffffff58 = 5;
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,cVar6,uVar3,5,
               in_stack_ffffffffffffff60,0x2a,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
               (char)this,(char)param_1);
  }
  (**(code **)(WdfFunctions_01031 + 0x850))(WdfDriverGlobals,param_1,&local_68);
  if (local_68._4_4_ == 3) {
    uVar3 = *(undefined8 *)(this + 0x20);
  }
  else {
    if (local_68._4_4_ != 4) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar4 = '\0';
      }
      bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar4 != '\0') || (bVar7)) {
        uVar3 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar7,uVar3);
      }
      iVar2 = -0x3ffffff3;
      goto LAB_1400037fb;
    }
    uVar3 = *(undefined8 *)(this + 0x28);
  }
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x8c8))(WdfDriverGlobals,param_1,uVar3);
  if (-1 < iVar2) {
    return;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar4 = '\0';
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar4 != '\0') || (bVar7)) {
    uVar3 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qqd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar7,uVar3,
               CONCAT71(in_stack_ffffffffffffff59,in_stack_ffffffffffffff58),
               in_stack_ffffffffffffff60,0x2c,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
               (char)this,(char)param_1,(char)iVar2);
  }
LAB_1400037fb:
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== EvtWdmIrpPreprocess @ 14000384c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CxDevice::EvtWdmIrpPreprocess(struct _IRP * __ptr64,void * __ptr64) __ptr64
    */

long __thiscall CxDevice::EvtWdmIrpPreprocess(CxDevice *this,_IRP *param_1,void *param_2)

{
  uint uVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  char cVar6;
  bool bVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((this == (CxDevice *)0x0) || (*this != (CxDevice)0x0)) {
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
    uVar5 = *(undefined8 *)(this + 0x38);
LAB_140003a8b:
    iVar4 = (**(code **)(WdfFunctions_01031 + 0xc88))(WdfDriverGlobals,uVar5,param_1,param_2);
  }
  else {
    pcVar2 = *(char **)(param_1 + 0xb8);
    if (*pcVar2 == '\x16') {
      bVar8 = true;
      this[0x120] = (CxDevice)0x1;
      param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
      *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
      lVar3 = (**(code **)(WdfFunctions_01031 + 0xc88))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x38));
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        bVar8 = false;
      }
      bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar8) || (bVar7)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar8,bVar7,uVar5,4,
                   in_stack_ffffffffffffffd0,0x26,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                   (char)this,(char)lVar3);
      }
      return lVar3;
    }
    uVar1 = *(uint *)(pcVar2 + 0x18);
    if (uVar1 < 0xb0028) {
      if (((uVar1 != 0xb0027) && (uVar1 != 0xb0003)) &&
         ((uVar1 != 0xb0007 &&
          ((((uVar1 != 0xb000b && (uVar1 != 0xb000f)) && (uVar1 != 0xb0013)) && (uVar1 != 0xb001f)))
          ))) {
        bVar8 = uVar1 == 0xb0023;
        goto LAB_1400039a2;
      }
    }
    else if (((uVar1 != 0xb002b) && (uVar1 != 0xb0191)) &&
            (((uVar1 != 0xb0192 && ((uVar1 != 0xb0195 && (uVar1 != 0xb01a2)))) && (uVar1 != 0xb01e2)
             ))) {
      bVar8 = uVar1 == 0xb0233;
LAB_1400039a2:
      if (!bVar8) {
        param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
        *(char **)(param_1 + 0xb8) = pcVar2 + 0x48;
        uVar5 = *(undefined8 *)(this + 0x38);
        goto LAB_140003a8b;
      }
    }
    iVar4 = (**(code **)(WdfFunctions_01031 + 0xc90))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x38),param_1,
                       *(undefined8 *)(this + 0x40),0);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar6 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar6 != '\0') || (bVar8)) {
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar8,uVar5,2,
                   in_stack_ffffffffffffffd0,0x27,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
                   (char)this,(char)iVar4);
      }
    }
  }
  return iVar4;
}



===== Initialize @ 140003ac4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidClassMinidriver<class HidSpiRequestManager,class
   HidSpiRequest>::Initialize(class utl::shared_ptr<class HidSpiRequestManager> & __ptr64,struct
   WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall
HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::Initialize
          (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this,
          shared_ptr<HidSpiRequestManager> *param_1,WDFDEVICE__ *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  _RefCountBase *this_00;
  int iVar3;
  ulonglong local_88;
  code *pcStack_80;
  undefined8 local_78;
  undefined4 local_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  WDFDEVICE__ *local_48;
  undefined8 local_40;
  undefined *local_38;
  
  lVar1 = *(longlong *)(param_1 + 8);
  uVar2 = *(undefined8 *)param_1;
  if (lVar1 != 0) {
    LOCK();
    *(int *)(lVar1 + 8) = *(int *)(lVar1 + 8) + 1;
    UNLOCK();
  }
  *(undefined8 *)this = uVar2;
  this_00 = *(_RefCountBase **)(this + 8);
  *(longlong *)(this + 8) = lVar1;
  if (this_00 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(this_00);
  }
  memset(&uStack_5c,0,0x54);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_68 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_68 = 0xffffffff;
  }
  else {
    local_68 = *(undefined4 *)(WdfStructures + 0x108);
  }
  local_64 = 3;
  iVar3 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                    (WdfDriverGlobals,param_2,&local_68,0,this + 0x10);
  if (-1 < iVar3) {
    memset(&uStack_5c,0,0x54);
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_68 = 0x60;
    }
    else if (WdfStructureCount < 0x22) {
      local_68 = 0xffffffff;
    }
    else {
      local_68 = *(undefined4 *)(WdfStructures + 0x108);
    }
    local_64 = 3;
    iVar3 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                      (WdfDriverGlobals,param_2,&local_68,0,this + 0x18);
    if (-1 < iVar3) {
      memset(&uStack_5c,0,0x54);
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_68 = 0x60;
      }
      else if (WdfStructureCount < 0x22) {
        local_68 = 0xffffffff;
      }
      else {
        local_68 = *(undefined4 *)(WdfStructures + 0x108);
      }
      local_64 = 3;
      iVar3 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                        (WdfDriverGlobals,param_2,&local_68,0,this + 0x20);
      if (-1 < iVar3) {
        local_54 = 0;
        local_40 = 0;
        local_64 = 0;
        uStack_5c = 0;
        if (WdfClientVersionHigherThanFramework == '\0') {
          local_68 = 0x38;
        }
        else if (WdfStructureCount < 0x27) {
          local_68 = 0xffffffff;
        }
        else {
          local_68 = *(undefined4 *)(WdfStructures + 0x130);
        }
        local_38 = PTR__WDF_HidClassMinidriverWorkItemContext_TYPE_INFO_1400170b8;
        local_50 = 1;
        local_4c = 1;
        if (WdfClientVersionHigherThanFramework == '\0') {
          local_88 = 0x18;
        }
        else if (WdfStructureCount < 0x44) {
          local_88 = 0xffffffff;
        }
        else {
          local_88 = (ulonglong)*(uint *)(WdfStructures + 0x218);
        }
        pcStack_80 = <lambda_e02dfa3165444d199da10aaadebb0ca3>::<lambda_invoker_cdecl>;
        local_78 = 1;
        local_48 = param_2;
        iVar3 = (**(code **)(WdfFunctions_01031 + 0xbd8))
                          (WdfDriverGlobals,&local_88,&local_68,this + 0x28);
      }
    }
  }
  return iVar3;
}



===== Initialize @ 140003d84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CxDevice::Initialize(struct _HIDSPICX_DEVICE_CONFIG * __ptr64) __ptr64 */

long __thiscall CxDevice::Initialize(CxDevice *this,_HIDSPICX_DEVICE_CONFIG *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffff20;
  undefined2 uVar6;
  ulonglong local_b8 [8];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c [4];
  code *local_68;
  code *local_48;
  undefined4 local_28;
  
  uVar3 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 8) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x10) = uVar3;
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x20) = uVar3;
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x30) = uVar3;
  memset(&local_78,0,0x60);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_78 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_78 = 0xffffffff;
  }
  else {
    local_78 = *(undefined4 *)(WdfStructures + 0x108);
  }
  local_70 = 0;
  local_48 = <lambda_d8acab477fcb6eda44b4297b0fa58d14>::<lambda_invoker_cdecl>;
  local_74 = 2;
  local_28 = 0xffffffff;
  local_b8[6] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_b8[0] = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_b8[0] = 0xffffffff;
  }
  else {
    local_b8[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  bVar1 = true;
  local_b8[3] = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x38),&local_78,local_b8,this + 0x40);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((!bVar1) && (!bVar5)) {
      return iVar2;
    }
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    uVar6 = 0xd;
  }
  else {
    memset(&local_78,0,0x60);
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_78 = 0x60;
    }
    else if (WdfStructureCount < 0x22) {
      local_78 = 0xffffffff;
    }
    else {
      local_78 = *(undefined4 *)(WdfStructures + 0x108);
    }
    local_70 = 0;
    local_68 = <lambda_c55067a657b9e79bb2dab387c21bb61a>::<lambda_invoker_cdecl>;
    local_74 = 2;
    local_28 = 0xffffffff;
    local_b8[6] = 0;
    local_b8[1] = 0;
    local_b8[2] = 0;
    local_b8[4] = 0;
    local_b8[5] = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_b8[0] = 0x38;
    }
    else if (WdfStructureCount < 0x27) {
      local_b8[0] = 0xffffffff;
    }
    else {
      local_b8[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
    }
    local_b8[3] = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x38),&local_78,local_b8,this + 0x48)
    ;
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar1 == false) && (!bVar5)) {
        return iVar2;
      }
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      uVar6 = 0xe;
    }
    else {
      uVar3 = *(undefined8 *)(this + 0x48);
      uVar4 = (**(code **)(WdfFunctions_01031 + 0xdc0))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x38));
      iVar2 = (**(code **)(WdfFunctions_01031 + 0xdd0))(WdfDriverGlobals,uVar4,uVar3);
      if (-1 < iVar2) {
        memset(local_6c,0,0x54);
        if (WdfClientVersionHigherThanFramework == '\0') {
          local_78 = 0x60;
        }
        else if (WdfStructureCount < 0x22) {
          local_78 = 0xffffffff;
        }
        else {
          local_78 = *(undefined4 *)(WdfStructures + 0x108);
        }
        local_70 = 0;
        local_74 = 3;
        iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                          (WdfDriverGlobals,*(undefined8 *)(this + 0x38),&local_78,0,this + 0x50);
        if (-1 < iVar2) {
          LoadConfiguration(this);
          KeInitializeEvent(this + 0xf0,1,0);
          KeInitializeEvent(this + 0x108,1,0);
          return 0;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar1 != false) || (bVar5)) {
          uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar5,uVar3,2,
                     in_stack_ffffffffffffff20,0x10,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids
                     ,(char)this,(char)iVar2);
        }
        return iVar2;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar1 == false) && (!bVar5)) {
        return iVar2;
      }
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      uVar6 = 0xf;
    }
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar5,uVar3,2,
             in_stack_ffffffffffffff20,uVar6,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
             (char)this,(char)iVar2);
  return iVar2;
}



===== InitializeDeviceInit @ 1400042a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CxDevice::InitializeDeviceInit(struct WDFDEVICE_INIT * __ptr64) */

long __cdecl CxDevice::InitializeDeviceInit(WDFDEVICE_INIT *param_1)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  undefined1 local_res10 [8];
  undefined1 local_res18 [16];
  undefined4 in_stack_fffffffffffffea0;
  undefined4 in_stack_fffffffffffffea4;
  undefined4 local_138 [6];
  code *local_120;
  code *local_118;
  code *local_90;
  code *local_40;
  code *local_30;
  
  (**(code **)(WdfFunctions_01031 + 0xdc8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01031 + 0x1c8))(WdfDriverGlobals,param_1,0);
  lVar2 = (**(code **)(WdfFunctions_01031 + 0xc60))(WdfDriverGlobals);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,
                 CONCAT44(in_stack_fffffffffffffea4,in_stack_fffffffffffffea0),10,
                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,(char)param_1);
    }
    iVar1 = -0x3fffff66;
  }
  else {
    memset(local_138,0,0x118);
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_138[0] = 0x118;
    }
    else if (WdfStructureCount < 0x48) {
      local_138[0] = 0xffffffff;
    }
    else {
      local_138[0] = *(undefined4 *)(WdfStructures + 0x238);
    }
    local_120 = <lambda_0eb4ccaa4a77b54fe32dd9f977a723f3>::<lambda_invoker_cdecl>;
    local_118 = <lambda_d9ea304143e555c250204b0ba65fd2d9>::<lambda_invoker_cdecl>;
    local_40 = <lambda_b17cc146140b155744e9db98374e935b>::<lambda_invoker_cdecl>;
    local_30 = <lambda_dfd60797b33275f96c55844c9e52654e>::<lambda_invoker_cdecl>;
    local_90 = <lambda_8cdcb6676c41e398f8d01040a1be6dce>::<lambda_invoker_cdecl>;
    (**(code **)(WdfFunctions_01031 + 0xde8))(WdfDriverGlobals,lVar2,local_138);
    iVar1 = (**(code **)(WdfFunctions_01031 + 0xc68))
                      (WdfDriverGlobals,lVar2,
                       <lambda_3a04e05a417483df07b23118ebb1e804>::<lambda_invoker_cdecl>,0xf,0,0);
    if (-1 < iVar1) {
      local_res10[0] = 4;
      iVar1 = (**(code **)(WdfFunctions_01031 + 0xc68))
                        (WdfDriverGlobals,lVar2,
                         <lambda_bfd87e50b7a722585d0162d63baacbeb>::<lambda_invoker_cdecl>,0x1b,
                         local_res10,1);
      if (-1 < iVar1) {
        local_res18[0] = 0;
        iVar1 = (**(code **)(WdfFunctions_01031 + 0xc68))
                          (WdfDriverGlobals,lVar2,
                           <lambda_3a04e05a417483df07b23118ebb1e804>::<lambda_invoker_cdecl>,0x16,
                           local_res18,1);
      }
    }
  }
  return iVar1;
}



===== LoadConfiguration @ 14000450c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CxDevice::LoadConfiguration(void) __ptr64 */

void __thiscall CxDevice::LoadConfiguration(CxDevice *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined1 auStackY_f8 [32];
  undefined8 *puVar7;
  undefined1 uVar8;
  int local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  wchar_t *local_80;
  wchar_t local_78 [16];
  wchar_t local_58 [20];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_90 = local_58;
  builtin_wcsncpy(local_58,L"UseD3HotPowerPol",0x10);
  puVar7 = &local_a0;
  builtin_wcsncpy(local_78,L"MaxPowerOnTime",0xf);
  bVar1 = true;
  builtin_wcsncpy(local_58 + 0x10,L"icy",4);
  local_80 = local_78;
  local_98 = 0x280026;
  local_88 = 0x1e001c;
  local_a0 = 0;
  local_a4 = 0;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x180))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x38),1,0x20019);
  uVar8 = SUB81(this,0);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar1) || (bVar6)) {
      uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,uVar4,2,puVar7,0x36,
                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar8,(char)iVar2);
    }
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01031 + 0x780))(WdfDriverGlobals,local_a0,&local_98,&local_a4)
    ;
    if (iVar2 < 0) {
      if (iVar2 != -0x3fffffcc) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar5 != '\0') || (bVar6)) {
          uVar4 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,puVar7,0x38,
                     &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar8,(char)iVar2);
        }
      }
    }
    else {
      this[0x121] = (CxDevice)(local_a4 != 0);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar5 != '\0') || (bVar6)) {
        uVar4 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4);
      }
    }
    iVar3 = (**(code **)(WdfFunctions_01031 + 0x780))(WdfDriverGlobals,local_a0,&local_88,&local_a4)
    ;
    iVar2 = local_a4;
    if (iVar3 < 0) {
      if (iVar3 != -0x3fffffcc) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar1 = false;
        }
        bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar1 != false) || (bVar6)) {
          uVar4 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,uVar4,2,puVar7,0x3a,
                     &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar8,(char)iVar3);
        }
      }
    }
    else {
      *(int *)(this + 0x124) = local_a4;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        bVar1 = false;
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar1 != false) || (bVar6)) {
        uVar4 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,bVar6,uVar4,4,puVar7,0x39,
                   &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar8,(char)iVar2);
      }
    }
    (**(code **)(WdfFunctions_01031 + 0x738))(WdfDriverGlobals,local_a0);
  }
  return;
}



===== SetDeviceFailed @ 140004950 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CxDevice::SetDeviceFailed(enum CxDevicePnpProblem,bool) __ptr64 */

void __thiscall CxDevice::SetDeviceFailed(CxDevice *this,CxDevicePnpProblem param_1,bool param_2)

{
  (**(code **)(WdfFunctions_01031 + 0x528))(WdfDriverGlobals,*(undefined8 *)(this + 0x40),0,0);
  SetPnpProblemMessage(this,param_1);
  (**(code **)(WdfFunctions_01031 + 0x2b8))
            (WdfDriverGlobals,*(undefined8 *)(this + 0x38),!param_2 + '\x01');
  return;
}



===== SetPnpProblemMessage @ 1400049d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CxDevice::SetPnpProblemMessage(enum CxDevicePnpProblem) __ptr64 */

void __thiscall CxDevice::SetPnpProblemMessage(CxDevice *this,CxDevicePnpProblem param_1)

{
  wchar_t *pwVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  short *psVar7;
  wchar_t *pwVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 auStackY_c8 [32];
  undefined8 in_stack_ffffffffffffff60;
  undefined2 uVar14;
  undefined1 uVar15;
  wchar_t local_70 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  builtin_wcsncpy(local_70,L"@System32\\drivers\\hidspicx.sys",0x1f);
  cVar3 = KeGetCurrentIrql();
  if (cVar3 != '\0') {
    return;
  }
  if (param_1 == 2) {
    uVar11 = 0xc0010001;
  }
  else if (param_1 == 3) {
    uVar11 = 0xc0010002;
  }
  else if (param_1 == 4) {
    uVar11 = 0xc0010003;
  }
  else if (param_1 == 5) {
    uVar11 = 0xc0010004;
  }
  else if (param_1 == 6) {
    uVar11 = 0xc0010005;
  }
  else {
    uVar11 = 0xc0010000;
  }
  lVar5 = (**(code **)(WdfFunctions_01031 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  iVar4 = RtlFindMessage(*(undefined8 *)(lVar5 + 0x18),0xb,0,uVar11);
  puVar2 = WPP_RECORDER_INITIALIZED;
  uVar15 = SUB81(this,0);
  if (iVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    if ((cVar3 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) {
      return;
    }
    uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    uVar14 = 0x2f;
    goto LAB_140004fda;
  }
  if (0xfffffffe < (ulonglong)uRam0000000000000000 - 4) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar13)) {
      return;
    }
    uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    uVar14 = 0x30;
LAB_140004bf6:
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar13,uVar6,2,
               in_stack_ffffffffffffff60,uVar14,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,
               uVar15);
    return;
  }
  psVar7 = (short *)&DAT_00000004;
  uVar10 = (ulonglong)uRam0000000000000000 - 4 >> 1;
  cVar3 = '\x01';
  uVar12 = uVar10;
  if (uVar10 < 0x80000000) {
    for (; (uVar12 != 0 && (*psVar7 != 0)); psVar7 = psVar7 + 1) {
      uVar12 = uVar12 - 1;
    }
    if (uVar12 != 0) {
      uVar12 = (uVar10 - uVar12) * 2 + 0x5a;
      pwVar8 = (wchar_t *)ExAllocatePool2(0x40,uVar12,0x58435348);
      if (pwVar8 == (wchar_t *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar3 == '\0') && (!bVar13)) {
          return;
        }
        uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        uVar14 = 0x32;
        goto LAB_140004bf6;
      }
      uVar6 = 4;
      uVar9 = RtlStringCbPrintfW(pwVar8,uVar12,L"%s,#%d;%s",local_70);
      iVar4 = (int)uVar9;
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar3 == '\0') && (!bVar13)) goto LAB_140004f50;
        uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        uVar14 = 0x33;
      }
      else {
        uVar12 = uVar12 >> 1;
        uVar10 = uVar12;
        pwVar1 = pwVar8;
        if (uVar12 < 0x80000000) {
          for (; (uVar10 != 0 && (*pwVar1 != L'\0')); pwVar1 = pwVar1 + 1) {
            uVar10 = uVar10 - 1;
          }
          if (uVar10 != 0) {
            uVar9 = (**(code **)(WdfFunctions_01031 + 0x108))
                              (WdfDriverGlobals,*(undefined8 *)(this + 0x38));
            uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),((int)uVar12 - (int)uVar10) * 2 + 2);
            iVar4 = IoSetDevicePropertyData(uVar9,&DEVPKEY_Device_DriverProblemDesc,0,0);
            if (-1 < iVar4) goto LAB_140004f50;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar3 = '\0';
            }
            bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar3 == '\0') && (!bVar13)) goto LAB_140004f50;
            uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            uVar14 = 0x35;
            goto LAB_140004f33;
          }
        }
        iVar4 = -0x3ffffff3;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        bVar13 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar3 == '\0') && (!bVar13)) goto LAB_140004f50;
        uVar9 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        uVar14 = 0x34;
      }
LAB_140004f33:
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar13,uVar9,2,uVar6,uVar14,
                 &WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar15,(char)iVar4);
LAB_140004f50:
      ExFreePoolWithTag(pwVar8,0x58435348);
      return;
    }
  }
  iVar4 = -0x3ffffff3;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  if ((cVar3 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) {
    return;
  }
  uVar6 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  uVar14 = 0x31;
LAB_140004fda:
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
             (undefined **)puVar2 != &WPP_RECORDER_INITIALIZED,uVar6,2,in_stack_ffffffffffffff60,
             uVar14,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,uVar15,(char)iVar4);
  return;
}



===== _CallDeleter @ 140005030 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountNormal<class
   HidClassMinidriver<class HidSpiRequestManager,class HidSpiRequest> * __ptr64,struct
   utl::default_delete<class HidClassMinidriver<class HidSpiRequestManager,class HidSpiRequest>
   >,class utl::allocator<int> >,0>::_CallDeleter(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountNormal<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>*___ptr64,utl::default_delete<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>_>,utl::allocator<int>_>,0>
::_CallDeleter(_RefCountVtable<utl::_RefCountNormal<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>*___ptr64,utl::default_delete<HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>_>,utl::allocator<int>_>,0>
               *this)

{
  HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this_00;
  
  this_00 = *(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)(this + 0x10);
  if (this_00 != (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *)0x0) {
    HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::
    ~HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>(this_00);
    ExFreePoolWithTag(this_00,0x58435348);
  }
  return;
}



===== _CallDeleter @ 140005070 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountNormal<class
   HidSpiCxReportInterface * __ptr64,struct utl::default_delete<class HidSpiCxReportInterface>,class
   utl::allocator<int> >,0>::_CallDeleter(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountNormal<HidSpiCxReportInterface*___ptr64,utl::default_delete<HidSpiCxReportInterface>,utl::allocator<int>_>,0>
::_CallDeleter(_RefCountVtable<utl::_RefCountNormal<HidSpiCxReportInterface*___ptr64,utl::default_delete<HidSpiCxReportInterface>,utl::allocator<int>_>,0>
               *this)

{
  HidSpiCxReportInterface *this_00;
  
  this_00 = *(HidSpiCxReportInterface **)(this + 0x10);
  if (this_00 != (HidSpiCxReportInterface *)0x0) {
    HidSpiCxReportInterface::~HidSpiCxReportInterface(this_00);
    ExFreePoolWithTag(this_00,0x58435348);
  }
  return;
}



===== _CallDeleter @ 1400050b0 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountNormal<class HidSpiDevice *
   __ptr64,struct utl::default_delete<class HidSpiDevice>,class utl::allocator<int>
   >,0>::_CallDeleter(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountNormal<HidSpiDevice*___ptr64,utl::default_delete<HidSpiDevice>,utl::allocator<int>_>,0>
::_CallDeleter(_RefCountVtable<utl::_RefCountNormal<HidSpiDevice*___ptr64,utl::default_delete<HidSpiDevice>,utl::allocator<int>_>,0>
               *this)

{
  HidSpiDevice *this_00;
  
  this_00 = *(HidSpiDevice **)(this + 0x10);
  if (this_00 != (HidSpiDevice *)0x0) {
    HidSpiDevice::~HidSpiDevice(this_00);
    ExFreePoolWithTag(this_00,0x58435348);
  }
  return;
}



===== _CallDeleter @ 1400050f0 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountNormal<class
   HidSpiRequestManager * __ptr64,struct utl::default_delete<class HidSpiRequestManager>,class
   utl::allocator<int> >,0>::_CallDeleter(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountNormal<HidSpiRequestManager*___ptr64,utl::default_delete<HidSpiRequestManager>,utl::allocator<int>_>,0>
::_CallDeleter(_RefCountVtable<utl::_RefCountNormal<HidSpiRequestManager*___ptr64,utl::default_delete<HidSpiRequestManager>,utl::allocator<int>_>,0>
               *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0x10);
  if (lVar1 != 0) {
    if (*(_RefCountBase **)(lVar1 + 8) != (_RefCountBase *)0x0) {
      _RefCountBase::_DecStrong(*(_RefCountBase **)(lVar1 + 8));
    }
    ExFreePoolWithTag(lVar1,0x58435348);
  }
  return;
}



===== _DecStrong @ 140005130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl utl::_RefCountBase::_DecStrong(void) __ptr64 */

void __thiscall utl::_RefCountBase::_DecStrong(_RefCountBase *this)

{
  _RefCountBase *p_Var1;
  int iVar2;
  
  if (*(longlong *)(this + 8) == 0x100000001) {
    (*(code *)**(undefined8 **)this)(this);
  }
  else {
    LOCK();
    p_Var1 = this + 8;
    iVar2 = *(int *)p_Var1;
    *(int *)p_Var1 = *(int *)p_Var1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      return;
    }
    (*(code *)**(undefined8 **)this)(this);
    if (*(int *)(this + 0xc) != 1) {
      LOCK();
      p_Var1 = this + 0xc;
      iVar2 = *(int *)p_Var1;
      *(int *)p_Var1 = *(int *)p_Var1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        return;
      }
    }
  }
  (**(code **)(*(longlong *)this + 8))(this);
  return;
}



===== _FreeRefCount @ 1400051c0 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountNormal<class
   HidSpiCxReportInterface * __ptr64,struct utl::default_delete<class HidSpiCxReportInterface>,class
   utl::allocator<int> >,0>::_FreeRefCount(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountNormal<HidSpiCxReportInterface*___ptr64,utl::default_delete<HidSpiCxReportInterface>,utl::allocator<int>_>,0>
::_FreeRefCount(_RefCountVtable<utl::_RefCountNormal<HidSpiCxReportInterface*___ptr64,utl::default_delete<HidSpiCxReportInterface>,utl::allocator<int>_>,0>
                *this)

{
  ExFreePoolWithTag(this,0x58435348);
  return;
}



===== RtlStringCbPrintfW @ 1400051e4 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 140005260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,1,param_8,param_7,&param_9,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDd @ 140005314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x29,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x29,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 14000540c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,1,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLlll @ 1400054e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLlll
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x24,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x24,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ql @ 140005624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_ql(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x37,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x37,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 1400056f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,1,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqD @ 1400057d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqD(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x2b,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_533f9d85120f331666b8abf11cf63f3b_Traceguids,0x2b,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqd @ 1400058c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqd
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,param_8,param_7,&param_9,8,&param_10,8,&param_11,4,0);
  }
  return;
}



===== operator_new @ 1400059b8 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,struct std::nothrow_t const & __ptr64) */

void * __cdecl operator_new(__uint64 param_1,nothrow_t *param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,param_1,0x58435348);
  return pvVar1;
}



===== DriverRegisterClassExtension @ 1400059e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl DriverRegisterClassExtension(struct _DRIVER_OBJECT * __ptr64,struct _UNICODE_STRING
   * __ptr64) */

long __cdecl DriverRegisterClassExtension(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  WDFDEVICE__ **in_R9;
  ulonglong uVar5;
  bool bVar6;
  undefined1 auStackY_188 [32];
  undefined8 in_stack_fffffffffffffea0;
  undefined2 uVar7;
  undefined1 uVar8;
  longlong local_138;
  ushort local_130 [4];
  undefined1 *local_128;
  _UNICODE_STRING *local_120;
  undefined1 local_118 [208];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  local_130[0] = 0;
  local_130[1] = 200;
  local_130[2] = 0;
  local_130[3] = 0;
  local_128 = local_118;
  local_120 = param_2;
  local_138 = (**(code **)(WdfFunctions_01031 + 200))
                        (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
  uVar8 = SUB81(param_1,0);
  if (local_138 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar4 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_fffffffffffffea0,0xb,
                 &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar8);
    }
    return -0x3fffff66;
  }
  cVar4 = '\x01';
  uVar5 = 0;
  do {
    uVar2 = RtlUnicodeStringPrintf(local_130,L"\\Device\\HidSpiCx%u",uVar5,in_R9);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar3 != '\0') || (bVar6)) {
        uVar7 = 0xc;
LAB_140005d16:
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar6,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_fffffffffffffea0,uVar7,
                   &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar8,(char)iVar1);
      }
      goto LAB_140005d28;
    }
    iVar1 = (**(code **)(WdfFunctions_01031 + 0x218))(WdfDriverGlobals,local_138,local_130);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar3 = '\0';
      }
      else {
        cVar3 = '\x01';
      }
      bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar3 != '\0') || (bVar6)) {
        uVar7 = 0xd;
        goto LAB_140005d16;
      }
      goto LAB_140005d28;
    }
    in_R9 = &g_ClassLibraryDevice;
    iVar1 = (**(code **)(WdfFunctions_01031 + 600))(WdfDriverGlobals,&local_138,0);
    uVar5 = (ulonglong)((int)uVar5 + 1);
  } while (iVar1 == -0x3fffffcb);
  if (iVar1 < 0) {
LAB_140005d28:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 == '\0') && (!bVar6)) goto LAB_140005d81;
    uVar7 = 0xe;
  }
  else {
    (**(code **)(WdfFunctions_01031 + 0xd8))(WdfDriverGlobals,g_ClassLibraryDevice);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    if ((cVar3 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qZ
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    iVar1 = WdfRegisterClassLibrary(&g_WdfClassLibraryInfo,local_120,local_130);
    if (-1 < iVar1) goto LAB_140005d81;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 == '\0') && (!bVar6)) goto LAB_140005d81;
    uVar7 = 0x10;
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_fffffffffffffea0,uVar7,
             &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar8,(char)iVar1);
LAB_140005d81:
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01031 + 0x1b0))(WdfDriverGlobals);
  }
  return iVar1;
}



===== Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline @ 140005dd8 =====

ulonglong Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_featureState;
  if ((Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_featureState & 0x10) == 0) {
    uVar1 = Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledFallback @ 140005e10 =====

void Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor);
  return;
}



===== RtlUnicodeStringPrintf @ 140005e2c =====

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



===== WPP_RECORDER_AND_TRACE_SF_ @ 140005ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,param_7,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,param_7,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDDDD @ 140005f54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDDDD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11,undefined1 param_12,undefined1 param_13)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,&param_11,4,&param_12,4,&param_13
               ,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,param_8,param_7,&param_9,8,&param_10,4,&param_11,4,&param_12,4,
                    &param_13,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qZ @ 140006094 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qZ(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  
  pwVar4 = L"NULL";
  if (param_2 == '\0') goto LAB_14000615b;
  if (in_stack_00000050 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1400060ff:
    pwVar3 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000050;
    if (*in_stack_00000050 == L'\0') goto LAB_1400060ff;
    pwVar3 = *(wchar_t **)(in_stack_00000050 + 4);
  }
  pwVar2 = in_stack_00000050;
  if (in_stack_00000050 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,0xf,
             &uStack0000000000000048,8,pwVar2,2,pwVar3,wVar1,0);
LAB_14000615b:
  if (param_3 != '\0') {
    if (in_stack_00000050 == (wchar_t *)0x0) {
      wVar1 = L'\b';
    }
    else {
      wVar1 = *in_stack_00000050;
      if (*in_stack_00000050 != L'\0') {
        pwVar4 = *(wchar_t **)(in_stack_00000050 + 4);
      }
    }
    if (in_stack_00000050 == (wchar_t *)0x0) {
      in_stack_00000050 = L"\b";
    }
    WppAutoLogTrace(param_4,4,1,&WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,0xf,
                    &uStack0000000000000048,8,in_stack_00000050,2,pwVar4,wVar1,0);
  }
  return;
}



===== WppClassicProviderCallback @ 140006200 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000625c =====

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
LAB_14000645f:
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar5 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar5 = uVar3 | uVar5 & 0xffffbfff;
      }
      uVar6 = uVar5 >> 5 & 0x1ff;
      uVar3 = uVar6 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 5 ^ uVar5) & 0x3fe0;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140006337:
        uVar5 = 0;
        if (param_3 == 2) {
          uVar5 = 2;
        }
        else if (param_3 == 3) {
          uVar5 = 8;
        }
        else if (param_3 == 6) {
          uVar5 = 4;
        }
        else if (param_3 == 7) {
          uVar5 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar5 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar6 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar6 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar6;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_14000645f;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar5 = param_3 - 0x140;
          if ((int)uVar5 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
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
                param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_140006337;
      }
    }
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar5 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar5 = uVar3 | uVar5 & 0xffbfffff;
      }
      uVar6 = uVar5 >> 0xf & 0x7f;
      uVar3 = uVar6 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 0xf ^ uVar5) & 0x3f8000;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140006548 =====

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
      goto LAB_140006619;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140006619;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140006619;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140006619;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140006619;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140006619;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140006619;
    }
  }
  uVar3 = 0xff;
LAB_140006619:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006670 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006760 =====

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
LAB_140006813:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140006841;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140006813;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140006841:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400069cc =====

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



===== wil_details_IsEnabledFallback @ 140006a30 =====

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



===== wil_details_RecordCachedUsage @ 140006ac4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 140006c10 =====

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



===== GetStringId @ 140006c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl HidClassMinidriverHelpers::GetStringId(struct WDFREQUEST__ *
   __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) */

long __cdecl
HidClassMinidriverHelpers::GetStringId(WDFREQUEST__ *param_1,ulong *param_2,ulong *param_3)

{
  ushort uVar1;
  undefined1 auStack_58 [32];
  ulonglong local_38 [4];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    uVar1 = 0x28;
  }
  else if (WdfStructureCount < 0x34) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = *(ushort *)(WdfStructures + 0x198);
  }
  local_38[0] = (ulonglong)uVar1;
  (**(code **)(WdfFunctions_01031 + 0x850))(WdfDriverGlobals,param_1,local_38);
  *param_2 = (uint)local_18 & 0xffff;
  *param_3 = (uint)local_18 >> 0x10;
  return 0;
}



===== RequestGetHidXferPacket_ToReadFromDevice @ 140006d50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl
   HidClassMinidriverHelpers::RequestGetHidXferPacket_ToReadFromDevice(struct WDFREQUEST__ *
   __ptr64,struct _HID_XFER_PACKET * __ptr64) */

long __cdecl
HidClassMinidriverHelpers::RequestGetHidXferPacket_ToReadFromDevice
          (WDFREQUEST__ *param_1,_HID_XFER_PACKET *param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  long lVar3;
  longlong lVar4;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    uVar2 = 0x28;
  }
  else if (WdfStructureCount < 0x34) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = *(ushort *)(WdfStructures + 0x198);
  }
  local_38 = (ulonglong)uVar2;
  (**(code **)(WdfFunctions_01031 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (uStack_30 < 0x10) {
    lVar3 = -0x3fffffdd;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01031 + 0x8e8))(WdfDriverGlobals,param_1);
    lVar3 = 0;
    uVar1 = (*(undefined8 **)(lVar4 + 0x70))[1];
    *(undefined8 *)param_2 = **(undefined8 **)(lVar4 + 0x70);
    *(undefined8 *)(param_2 + 8) = uVar1;
  }
  return lVar3;
}



===== RequestGetHidXferPacket_ToWriteToDevice @ 140006e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl
   HidClassMinidriverHelpers::RequestGetHidXferPacket_ToWriteToDevice(struct WDFREQUEST__ *
   __ptr64,struct _HID_XFER_PACKET * __ptr64) */

long __cdecl
HidClassMinidriverHelpers::RequestGetHidXferPacket_ToWriteToDevice
          (WDFREQUEST__ *param_1,_HID_XFER_PACKET *param_2)

{
  undefined8 uVar1;
  ushort uVar2;
  long lVar3;
  longlong lVar4;
  undefined1 auStack_58 [32];
  ulonglong local_38 [6];
  
  local_38[5] = __security_cookie ^ (ulonglong)auStack_58;
  local_38[4] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    uVar2 = 0x28;
  }
  else if (WdfStructureCount < 0x34) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = *(ushort *)(WdfStructures + 0x198);
  }
  local_38[0] = (ulonglong)uVar2;
  (**(code **)(WdfFunctions_01031 + 0x850))(WdfDriverGlobals,param_1,local_38);
  if (local_38[2] < 0x10) {
    lVar3 = -0x3fffffdd;
  }
  else {
    lVar4 = (**(code **)(WdfFunctions_01031 + 0x8e8))(WdfDriverGlobals,param_1);
    lVar3 = 0;
    uVar1 = (*(undefined8 **)(lVar4 + 0x70))[1];
    *(undefined8 *)param_2 = **(undefined8 **)(lVar4 + 0x70);
    *(undefined8 *)(param_2 + 8) = uVar1;
  }
  return lVar3;
}



===== imp_HidSpiCxDeviceConfigure @ 140006f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_HidSpiCxDeviceConfigure
               (longlong param_1,WDFDEVICE__ *param_2,_HIDSPICX_DEVICE_CONFIG *param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined1 *puVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffd0;
  undefined2 uVar6;
  undefined1 uVar7;
  
  uVar7 = SUB81(param_2,0);
  if (((int *)(param_1 + -4) == (int *)0x0) || (*(int *)(param_1 + -4) != 0x78635348)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar1 = '\0';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar1 == '\0') && (!bVar5)) {
      return -0x3ffffff3;
    }
    uVar6 = 0xc;
  }
  else {
    cVar1 = KeGetCurrentIrql();
    if (cVar1 != '\0') {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,0xd,
                   &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,uVar7);
      }
      return -0x3ffffeb8;
    }
    if (param_3 == (_HIDSPICX_DEVICE_CONFIG *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar1 == '\0') && (!bVar5)) {
        return -0x3ffffff3;
      }
      uVar6 = 0xe;
    }
    else if (*(int *)param_3 == 0x30) {
      cVar1 = '\x01';
      if ((*(uint *)(param_3 + 0x2c) & 1) == 0) {
        if (*(longlong *)(param_3 + 8) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar1 = '\0';
          }
          bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar1 == '\0') && (!bVar5)) {
            return -0x3ffffff3;
          }
          uVar6 = 0x12;
        }
        else if (*(longlong *)(param_3 + 0x10) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar1 = '\0';
          }
          bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar1 == '\0') && (!bVar5)) {
            return -0x3ffffff3;
          }
          uVar6 = 0x13;
        }
        else if (*(uint *)(param_3 + 0x2c) == 0) {
          if ((*(longlong *)(param_3 + 0x18) != 0) && (*(longlong *)(param_3 + 0x20) != 0)) {
            uVar2 = (**(code **)(WdfFunctions_01031 + 0x158))(WdfDriverGlobals,param_2);
            if ((uVar2 & 0xffff7fff) == 0x105) {
              lVar3 = CxDevice::CreateAndInitialize(param_2,param_3);
              return lVar3;
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar1 = '\0';
            }
            if ((cVar1 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              WPP_RECORDER_AND_TRACE_SF_q
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                         *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,0x16
                         ,&WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,uVar7);
            }
            return -0x3ffffe7c;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar1 = '\0';
          }
          bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar1 == '\0') && (!bVar5)) {
            return -0x3ffffff3;
          }
          uVar6 = 0x15;
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar1 = '\0';
          }
          bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar1 == '\0') && (!bVar5)) {
            return -0x3ffffff3;
          }
          uVar6 = 0x14;
        }
      }
      else {
        puVar4 = (undefined1 *)
                 (**(code **)(WdfFunctions_01031 + 0x650))
                           (WdfDriverGlobals,param_2,PTR__WDF_CxDevice_TYPE_INFO_140017090);
        if (puVar4 != (undefined1 *)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar1 = '\0';
          }
          else {
            cVar1 = '\x01';
          }
          if ((cVar1 != '\0') ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_AND_TRACE_SF_q
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                       *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_stack_ffffffffffffffd0,0x10,
                       &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,uVar7);
          }
          *puVar4 = 1;
          return 0;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar1 = '\0';
        }
        bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar1 == '\0') && (!bVar5)) {
          return -0x3ffffff3;
        }
        uVar6 = 0x11;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar1 == '\0') && (!bVar5)) {
        return -0x3ffffff3;
      }
      uVar6 = 0xf;
    }
  }
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,bVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,uVar6,
             &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,uVar7);
  return -0x3ffffff3;
}



===== imp_HidSpiCxDeviceInitConfig @ 140007480 =====

long imp_HidSpiCxDeviceInitConfig(longlong param_1,WDFDEVICE_INIT *param_2)

{
  char cVar1;
  long lVar2;
  undefined8 in_stack_ffffffffffffffd0;
  
  if (((int *)(param_1 + -4) == (int *)0x0) || (*(int *)(param_1 + -4) != 0x78635348)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar1 = '\0';
    }
    if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,10,
                 &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,(char)param_2);
    }
    lVar2 = -0x3ffffff3;
  }
  else {
    cVar1 = KeGetCurrentIrql();
    if (cVar1 == '\0') {
      lVar2 = CxDevice::InitializeDeviceInit(param_2);
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar1 = '\0';
      }
      if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,0xb,
                   &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,(char)param_2);
      }
      lVar2 = -0x3ffffeb8;
    }
  }
  return lVar2;
}



===== imp_HidSpiCxNotifyDeviceReset @ 1400075b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void imp_HidSpiCxNotifyDeviceReset(longlong param_1,undefined8 param_2)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  undefined2 uVar5;
  
  if (((int *)(param_1 + -4) == (int *)0x0) || (*(int *)(param_1 + -4) != 0x78635348)) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        ((byte)WPP_GLOBAL_Control[0x29] < 2)))) {
      cVar3 = '\0';
    }
    bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar4)) {
      return;
    }
    uVar5 = 0x17;
  }
  else {
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 3) {
      lVar2 = (**(code **)(WdfFunctions_01031 + 0x650))
                        (WdfDriverGlobals,param_2,PTR__WDF_CxDevice_TYPE_INFO_140017090);
      if (*(HidSpiDevice **)(lVar2 + 0xb8) == (HidSpiDevice *)0x0) {
        return;
      }
      HidSpiDevice::EvtDeviceNeedsReset(*(HidSpiDevice **)(lVar2 + 0xb8));
      return;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar3 = '\0';
    }
    bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 == '\0') && (!bVar4)) {
      return;
    }
    uVar5 = 0x18;
  }
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffd0,uVar5,
             &WPP_4bbc87cbdd01386a14ab78d36433a214_Traceguids,(char)param_2);
  return;
}



===== <lambda_invoker_cdecl> @ 1400076f0 =====

void <lambda_2dd2bf9e81c39ecfd03f589d79607541>::<lambda_invoker_cdecl>
               (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  HidSpiDeviceStateMachine<HidSpiDevice> *this;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffd0;
  
  iVar1 = *(int *)(param_3 + 8);
  this = *(HidSpiDeviceStateMachine<HidSpiDevice> **)(param_4 + 8);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar5)) {
      uVar2 = *(undefined8 *)(this + 0x68);
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,uVar3,2,
                 in_stack_ffffffffffffffd0,0x4e,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar2,(char)iVar1);
    }
    *(undefined4 *)(this + 0x20) = 1;
  }
  *(int *)(this + 0xa8) = iVar1;
  HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent(this,0xc);
  return;
}



===== ~HidSpiCxReportInterface @ 1400077e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl HidSpiCxReportInterface::~HidSpiCxReportInterface(void) __ptr64 */

void __thiscall HidSpiCxReportInterface::~HidSpiCxReportInterface(HidSpiCxReportInterface *this)

{
  HidSpiCxReportInterface *pHVar1;
  longlong *plVar2;
  longlong lVar3;
  HidSpiCxReportInterface *pHVar4;
  HidSpiCxReportInterface *pHVar5;
  
  pHVar1 = this + 0x38;
  for (pHVar4 = *(HidSpiCxReportInterface **)pHVar1; pHVar4 != pHVar1;
      pHVar4 = *(HidSpiCxReportInterface **)pHVar4) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*(longlong *)(pHVar4 + 0x10));
  }
  pHVar4 = this + 0x50;
  for (pHVar5 = *(HidSpiCxReportInterface **)pHVar4; pHVar5 != pHVar4;
      pHVar5 = *(HidSpiCxReportInterface **)pHVar5) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*(longlong *)(pHVar5 + 0x10));
  }
  if (*(longlong *)(this + 0x78) != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
  }
  if (*(longlong *)(this + 0x80) != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
  }
  Lock::~Lock((Lock *)(this + 0x68));
  while (pHVar5 = *(HidSpiCxReportInterface **)pHVar4, pHVar5 != pHVar4) {
    plVar2 = *(longlong **)(pHVar5 + 8);
    lVar3 = *(longlong *)pHVar5;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    ExFreePoolWithTag(pHVar5,0x58435348);
  }
  *(undefined8 *)(this + 0x60) = 0;
  while (pHVar4 = *(HidSpiCxReportInterface **)pHVar1, pHVar4 != pHVar1) {
    plVar2 = *(longlong **)(pHVar4 + 8);
    lVar3 = *(longlong *)pHVar4;
    *plVar2 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar2;
    ExFreePoolWithTag(pHVar4,0x58435348);
  }
  *(undefined8 *)(this + 0x48) = 0;
  if (*(_RefCountBase **)(this + 0x10) != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(*(_RefCountBase **)(this + 0x10));
  }
  return;
}



===== EvtReadCompleted @ 140007934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiCxReportInterface::EvtReadCompleted(struct WDFREQUEST__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64) __ptr64 */

void __thiscall
HidSpiCxReportInterface::EvtReadCompleted
          (HidSpiCxReportInterface *this,WDFREQUEST__ *param_1,
          _WDF_REQUEST_COMPLETION_PARAMS *param_2)

{
  HidSpiCxReportInterface *pHVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  bool bVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  _HIDSPICX_REPORT *p_Var9;
  undefined8 uVar10;
  undefined8 uVar11;
  nothrow_t *pnVar12;
  char cVar13;
  char cVar14;
  bool bVar15;
  bool bVar16;
  undefined1 in_stack_ffffffffffffff78;
  undefined7 in_stack_ffffffffffffff79;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 in_stack_ffffffffffffff90;
  undefined1 uVar17;
  undefined8 local_40;
  
  lVar6 = (**(code **)(WdfFunctions_01031 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
  pnVar12 = (nothrow_t *)0x2;
  bVar5 = true;
  LOCK();
  bVar15 = *(int *)(lVar6 + 8) == 1;
  if (bVar15) {
    *(int *)(lVar6 + 8) = 2;
  }
  UNLOCK();
  bVar15 = !bVar15;
  LOCK();
  if (*(int *)(lVar6 + 8) == 3) {
    *(int *)(lVar6 + 8) = 4;
  }
  UNLOCK();
  uVar17 = SUB81(param_1,0);
  if ((this[0x30] == (HidSpiCxReportInterface)0x0) || (!bVar15)) {
    iVar2 = *(int *)(param_2 + 8);
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar5 = false;
      }
      bVar16 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((bVar5) || (bVar16)) {
        uVar10 = *(undefined8 *)this;
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,bVar16,uVar7,
                   CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                   in_stack_ffffffffffffff80,0x20,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                   (char)uVar10,uVar17,(char)iVar2);
      }
      HidSpiDevice::EvtDeviceNeedsReset(*(HidSpiDevice **)(this + 8));
    }
    else {
      local_40 = 0;
      p_Var9 = (_HIDSPICX_REPORT *)
               (**(code **)(WdfFunctions_01031 + 0x610))
                         (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x10),&local_40);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar13 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 5)) {
        cVar13 = '\0';
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (cVar14 = '\x01', *(short *)(WPP_GLOBAL_Control + 0x48) == 0)) {
        cVar14 = '\0';
      }
      if ((cVar13 != '\0') || (cVar14 != '\0')) {
        uVar10 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qqqq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,cVar14,uVar10);
      }
      bVar16 = HidSpiDevice::EvtInputReportReceived
                         (*(HidSpiDevice **)(this + 8),p_Var9,*(void **)(lVar6 + 0x10));
      if (!bVar16) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          bVar5 = false;
        }
        bVar16 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar5 != false) || (bVar16)) {
          uVar10 = *(undefined8 *)(lVar6 + 0x10);
          uVar7 = *(undefined8 *)this;
          uVar11 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qqq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,bVar16,uVar11,
                     CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                     in_stack_ffffffffffffff80,0x22,in_stack_ffffffffffffff90,(char)uVar7,
                     (char)uVar10,uVar17);
        }
        Lock::lock((Lock *)(this + 0x68));
        *(undefined8 *)(lVar6 + 0x10) = *(undefined8 *)(*(longlong *)(this + 0x50) + 0x10);
        plVar8 = *(longlong **)(this + 0x50);
        plVar4 = (longlong *)plVar8[1];
        lVar6 = *plVar8;
        *plVar4 = lVar6;
        *(longlong **)(lVar6 + 8) = plVar4;
        ExFreePoolWithTag(plVar8,0x58435348);
        *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + -1;
        Lock::unlock((Lock *)(this + 0x68));
      }
    }
    if (bVar15) {
      SendPingPongRead(this,param_1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar13 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar13 = '\0';
    }
    bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar13 != '\0') || (bVar15)) {
      uVar10 = *(undefined8 *)this;
      uVar7 = imp_WppRecorderLogGetDefault();
      pnVar12 = (nothrow_t *)CONCAT71((int7)((ulonglong)param_1 >> 8),cVar13);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar15,uVar7,4,
                 in_stack_ffffffffffffff80,0x1e,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                 (char)uVar10,uVar17);
    }
    Lock::lock((Lock *)(this + 0x68));
    plVar8 = operator_new(0x18,pnVar12);
    if (plVar8 != (longlong *)0x0) {
      plVar8[2] = *(longlong *)(lVar6 + 0x10);
      puVar3 = *(undefined8 **)(this + 0x58);
      plVar8[1] = (longlong)puVar3;
      *plVar8 = (longlong)(this + 0x50);
      *puVar3 = plVar8;
      *(longlong **)(this + 0x58) = plVar8;
      *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + 1;
    }
    *(undefined8 *)(lVar6 + 0x10) = 0;
    Lock::unlock((Lock *)(this + 0x68));
    *(undefined4 *)(lVar6 + 8) = 0;
    LOCK();
    pHVar1 = this + 0x28;
    lVar6 = *(longlong *)pHVar1;
    *(longlong *)pHVar1 = *(longlong *)pHVar1 + -1;
    UNLOCK();
    if (lVar6 == 1) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar13 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar13 = '\0';
      }
      bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar13 != '\0') || (bVar15)) {
        uVar10 = *(undefined8 *)this;
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar15,uVar7,4,
                   in_stack_ffffffffffffff80,0x1f,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                   (char)uVar10,uVar17);
      }
      HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 8),1);
    }
  }
  return;
}



===== EvtReadCompletion @ 140007df0 =====

/* public: static void __cdecl HidSpiCxReportInterface::EvtReadCompletion(struct WDFREQUEST__ *
   __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void *
   __ptr64) */

void __cdecl
HidSpiCxReportInterface::EvtReadCompletion
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  EvtReadCompleted(param_4,param_1,param_3);
  return;
}



===== Initialize @ 140007e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidSpiCxReportInterface::Initialize(class CxDevice * __ptr64,class
   utl::shared_ptr<class HidSpiDevice>,struct WDFDEVICE__ * __ptr64,unsigned __int64) __ptr64 */

long __thiscall
HidSpiCxReportInterface::Initialize
          (HidSpiCxReportInterface *this,undefined8 param_1,undefined8 *param_3,WDFDEVICE__ *param_4
          ,nothrow_t *param_5)

{
  longlong lVar1;
  _RefCountBase *this_00;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 uVar8;
  nothrow_t *pnVar9;
  ulonglong uVar10;
  bool bVar11;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 local_58;
  undefined8 local_54;
  undefined8 uStack_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  WDFDEVICE__ *local_38;
  undefined8 local_30;
  undefined *local_28;
  
  *(undefined8 *)this = param_1;
  lVar1 = param_3[1];
  uVar8 = *param_3;
  if (lVar1 != 0) {
    LOCK();
    *(int *)(lVar1 + 8) = *(int *)(lVar1 + 8) + 1;
    UNLOCK();
  }
  *(undefined8 *)(this + 8) = uVar8;
  this_00 = *(_RefCountBase **)(this + 0x10);
  *(longlong *)(this + 0x10) = lVar1;
  if (this_00 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(this_00);
  }
  *(WDFDEVICE__ **)(this + 0x18) = param_4;
  Lock::Initialize((Lock *)(this + 0x68),param_4);
  uVar3 = KeQueryActiveProcessorCount(0);
  *(nothrow_t **)(this + 0x20) = (nothrow_t *)(ulonglong)uVar3;
  if ((param_5 != (nothrow_t *)0x0) && (param_5 < (nothrow_t *)(ulonglong)uVar3)) {
    *(nothrow_t **)(this + 0x20) = param_5;
  }
  local_44 = 0;
  local_30 = 0;
  local_54 = 0;
  uStack_4c = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_58 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_58 = 0xffffffff;
  }
  else {
    local_58 = *(undefined4 *)(WdfStructures + 0x130);
  }
  bVar2 = true;
  local_28 = PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0;
  local_40 = 1;
  local_3c = 1;
  local_38 = param_4;
  uVar8 = (**(code **)(WdfFunctions_01031 + 0xdc0))(WdfDriverGlobals,*(undefined8 *)(this + 0x18));
  iVar4 = (**(code **)(WdfFunctions_01031 + 0x7b8))(WdfDriverGlobals,&local_58,uVar8,this + 0x78);
  if (iVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar2 = false;
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar2) || (bVar11)) {
      uVar8 = *(undefined8 *)this;
      uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar11,uVar5,2,
                 in_stack_ffffffffffffff70,10,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                 (char)uVar8,(char)iVar4);
    }
    if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
    }
  }
  else {
    puVar6 = (undefined8 *)
             (**(code **)(WdfFunctions_01031 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(this + 0x78),
                        PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
    uVar10 = 0;
    *puVar6 = this;
    if (*(longlong *)(this + 0x20) != 0) {
      do {
        param_5 = (nothrow_t *)0x0;
        uVar8 = (**(code **)(WdfFunctions_01031 + 0xdc0))
                          (WdfDriverGlobals,*(undefined8 *)(this + 0x18));
        iVar4 = (**(code **)(WdfFunctions_01031 + 0x7b8))(WdfDriverGlobals,&local_58,uVar8,&param_5)
        ;
        if (iVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar2 = false;
          }
          bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((bVar2 != false) || (bVar11)) {
            uVar8 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            WPP_RECORDER_AND_TRACE_SF_qPd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar11,uVar8);
          }
          if ((_RefCountBase *)param_3[1] == (_RefCountBase *)0x0) {
            return iVar4;
          }
          utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
          return iVar4;
        }
        pnVar9 = param_5;
        puVar6 = (undefined8 *)
                 (**(code **)(WdfFunctions_01031 + 0x650))
                           (WdfDriverGlobals,param_5,
                            PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
        *puVar6 = this;
        *(undefined4 *)(puVar6 + 1) = 0;
        plVar7 = operator_new(0x18,pnVar9);
        if (plVar7 == (longlong *)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar2 = false;
          }
          bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((bVar2 != false) || (bVar11)) {
            uVar8 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
            WPP_RECORDER_AND_TRACE_SF_qP
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar11,uVar8);
          }
          if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
            utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
          }
          return -0x3fffff66;
        }
        uVar10 = uVar10 + 1;
        plVar7[2] = (longlong)param_5;
        puVar6 = *(undefined8 **)(this + 0x40);
        plVar7[1] = (longlong)puVar6;
        *plVar7 = (longlong)(this + 0x38);
        *puVar6 = plVar7;
        *(longlong **)(this + 0x40) = plVar7;
        *(longlong *)(this + 0x48) = *(longlong *)(this + 0x48) + 1;
      } while (uVar10 < *(ulonglong *)(this + 0x20));
    }
    if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
    }
    iVar4 = 0;
  }
  return iVar4;
}



===== ReleaseReportBuffer @ 140008238 =====

/* public: void __cdecl HidSpiCxReportInterface::ReleaseReportBuffer(void * __ptr64) __ptr64 */

void __thiscall
HidSpiCxReportInterface::ReleaseReportBuffer(HidSpiCxReportInterface *this,void *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong *plVar5;
  nothrow_t *pnVar6;
  char cVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar7 != '\0') || (pnVar6 = param_1, bVar8)) {
    uVar1 = *(undefined8 *)this;
    uVar4 = imp_WppRecorderLogGetDefault();
    pnVar6 = (nothrow_t *)CONCAT71(0x140014d,cVar7);
    WPP_RECORDER_AND_TRACE_SF_qq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar8,uVar4,4,
               in_stack_ffffffffffffffd0,0x1d,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
               (char)uVar1,(char)param_1);
  }
  Lock::lock((Lock *)(this + 0x68));
  lVar2 = *(longlong *)(this + 0x50);
  plVar5 = operator_new(0x18,pnVar6);
  if (plVar5 != (longlong *)0x0) {
    plVar5[2] = (longlong)param_1;
    puVar3 = *(undefined8 **)(lVar2 + 8);
    plVar5[1] = (longlong)puVar3;
    *plVar5 = lVar2;
    *puVar3 = plVar5;
    *(longlong **)(lVar2 + 8) = plVar5;
    *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + 1;
  }
  Lock::unlock((Lock *)(this + 0x68));
  return;
}



===== SendPingPongRead @ 140008348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl HidSpiCxReportInterface::SendPingPongRead(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

long __thiscall
HidSpiCxReportInterface::SendPingPongRead(HidSpiCxReportInterface *this,WDFREQUEST__ *param_1)

{
  HidSpiCxReportInterface *pHVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  undefined **ppuVar10;
  undefined *puVar11;
  nothrow_t *pnVar12;
  char cVar13;
  bool bVar14;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 in_stack_ffffffffffffff80;
  undefined2 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  lVar6 = (**(code **)(WdfFunctions_01031 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
  cVar13 = '\x01';
  while( true ) {
    ppuVar10 = &WPP_RECORDER_INITIALIZED;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    uVar17 = SUB81(param_1,0);
    if ((cVar3 != '\0') || (bVar14)) {
      uVar9 = *(undefined8 *)this;
      uVar7 = imp_WppRecorderLogGetDefault();
      ppuVar10 = (undefined **)CONCAT71((int7)((ulonglong)ppuVar10 >> 8),cVar3);
      in_stack_ffffffffffffff78 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff78 >> 8),4);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar14,uVar7,4,
                 in_stack_ffffffffffffff80,0xf,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                 (char)uVar9,uVar17);
    }
    if (this[0x30] != (HidSpiCxReportInterface)0x0) {
      Lock::lock((Lock *)(this + 0x68));
      plVar8 = operator_new(0x18,(nothrow_t *)ppuVar10);
      if (plVar8 != (longlong *)0x0) {
        plVar8[2] = *(longlong *)(lVar6 + 0x10);
        puVar2 = *(undefined8 **)(this + 0x58);
        plVar8[1] = (longlong)puVar2;
        *plVar8 = (longlong)(this + 0x50);
        *puVar2 = plVar8;
        *(longlong **)(this + 0x58) = plVar8;
        *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + 1;
      }
      *(undefined8 *)(lVar6 + 0x10) = 0;
      *(undefined4 *)(lVar6 + 8) = 0;
      Lock::unlock((Lock *)(this + 0x68));
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar13 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar13 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar13 != '\0') || (bVar14)) {
        uVar9 = *(undefined8 *)this;
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar7,4,
                   in_stack_ffffffffffffff80,0x10,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                   (char)uVar9,uVar17);
      }
      LOCK();
      pHVar1 = this + 0x28;
      lVar6 = *(longlong *)pHVar1;
      *(longlong *)pHVar1 = *(longlong *)pHVar1 + -1;
      UNLOCK();
      if (lVar6 != 1) {
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar13 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar13 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar13 != '\0') || (bVar14)) {
        uVar9 = *(undefined8 *)this;
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar7,4,
                   in_stack_ffffffffffffff80,0x11,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                   (char)uVar9,uVar17);
      }
      HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 8),1);
      return 0;
    }
    uStack_3c = 0;
    local_38 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_48 = 0x18;
    }
    else if (WdfStructureCount < 0x35) {
      local_48 = 0xffffffff;
    }
    else {
      local_48 = *(undefined4 *)(WdfStructures + 0x1a0);
    }
    uStack_44 = 0;
    uStack_40 = 0;
    iVar4 = (**(code **)(WdfFunctions_01031 + 0x7c8))(WdfDriverGlobals,param_1,&local_48);
    if (iVar4 < 0) break;
    uVar9 = *(undefined8 *)(lVar6 + 0x10);
    uVar7 = (**(code **)(WdfFunctions_01031 + 0xdc0))(WdfDriverGlobals,*(undefined8 *)(this + 0x18))
    ;
    in_stack_ffffffffffffff80 = 0;
    in_stack_ffffffffffffff78 = 0;
    iVar4 = (**(code **)(WdfFunctions_01031 + 0x5b8))(WdfDriverGlobals,uVar7,param_1,uVar9);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar13 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar13 == '\0') && (!bVar14)) {
        return iVar4;
      }
      uVar16 = (undefined1)*(undefined8 *)this;
      uVar9 = imp_WppRecorderLogGetDefault();
      uVar15 = 0x13;
      goto LAB_140008a4c;
    }
    (**(code **)(WdfFunctions_01031 + 0x820))(WdfDriverGlobals,param_1,EvtReadCompletion,this);
    *(undefined4 *)(lVar6 + 8) = 1;
    uVar9 = (**(code **)(WdfFunctions_01031 + 0xdc0))(WdfDriverGlobals,*(undefined8 *)(this + 0x18))
    ;
    cVar3 = (**(code **)(WdfFunctions_01031 + 0x7e8))(WdfDriverGlobals,param_1,uVar9,0);
    if (cVar3 == '\0') {
      lVar5 = (**(code **)(WdfFunctions_01031 + 0x7f0))(WdfDriverGlobals,param_1);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar13 = '\0';
      }
      else {
        cVar13 = '\x01';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar13 != '\0') || (pnVar12 = (nothrow_t *)WPP_GLOBAL_Control, bVar14)) {
        uVar9 = *(undefined8 *)this;
        puVar11 = WPP_GLOBAL_Control;
        uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        pnVar12 = (nothrow_t *)CONCAT71((int7)((ulonglong)puVar11 >> 8),cVar13);
        WPP_RECORDER_AND_TRACE_SF_qqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar7,
                   in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,0x14,
                   &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,(char)uVar9,uVar17,(char)lVar5);
      }
      Lock::lock((Lock *)(this + 0x68));
      plVar8 = operator_new(0x18,pnVar12);
      if (plVar8 != (longlong *)0x0) {
        plVar8[2] = *(longlong *)(lVar6 + 0x10);
        puVar2 = *(undefined8 **)(this + 0x58);
        plVar8[1] = (longlong)puVar2;
        *plVar8 = (longlong)(this + 0x50);
        *puVar2 = plVar8;
        *(longlong **)(this + 0x58) = plVar8;
        *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + 1;
      }
      *(undefined8 *)(lVar6 + 0x10) = 0;
      *(undefined4 *)(lVar6 + 8) = 0;
      Lock::unlock((Lock *)(this + 0x68));
      LOCK();
      pHVar1 = this + 0x28;
      lVar6 = *(longlong *)pHVar1;
      *(longlong *)pHVar1 = *(longlong *)pHVar1 + -1;
      UNLOCK();
      if ((lVar6 == 1) && (this[0x30] != (HidSpiCxReportInterface)0x0)) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 4)
            ))) {
          cVar13 = '\0';
        }
        else {
          cVar13 = '\x01';
        }
        bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar13 != '\0') || (bVar14)) {
          uVar9 = *(undefined8 *)this;
          uVar7 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar7,4,
                     in_stack_ffffffffffffff80,0x15,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids
                     ,(char)uVar9,uVar17);
        }
        HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                  (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 8),1);
      }
      return lVar5;
    }
    LOCK();
    bVar14 = *(int *)(lVar6 + 8) == 1;
    if (bVar14) {
      *(int *)(lVar6 + 8) = 3;
    }
    UNLOCK();
    if (bVar14) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar3 = '\0';
      }
      bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar3 != '\0') || (bVar14)) {
        uVar9 = *(undefined8 *)this;
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar14,uVar7,4,
                   in_stack_ffffffffffffff80,0x16,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                   (char)uVar9,uVar17);
      }
      if (this[0x30] != (HidSpiCxReportInterface)0x0) {
        LOCK();
        bVar14 = *(int *)(lVar6 + 8) == 3;
        if (bVar14) {
          *(int *)(lVar6 + 8) = 5;
        }
        UNLOCK();
        if (bVar14) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
            cVar13 = '\0';
          }
          bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar13 != '\0') || (bVar14)) {
            uVar9 = *(undefined8 *)this;
            uVar7 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar7,4,
                       in_stack_ffffffffffffff80,0x17,
                       &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,(char)uVar9,uVar17);
          }
          (**(code **)(WdfFunctions_01031 + 0x810))(WdfDriverGlobals,param_1);
        }
      }
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (cVar3 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 != '\0') || (bVar14)) {
      uVar9 = *(undefined8 *)this;
      uVar7 = imp_WppRecorderLogGetDefault();
      in_stack_ffffffffffffff78 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff78 >> 8),4);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar14,uVar7,4,
                 in_stack_ffffffffffffff80,0x18,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                 (char)uVar9,uVar17);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar13 = '\0';
  }
  bVar14 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar13 == '\0') && (!bVar14)) {
    return iVar4;
  }
  uVar16 = (undefined1)*(undefined8 *)this;
  uVar9 = imp_WppRecorderLogGetDefault();
  uVar15 = 0x12;
LAB_140008a4c:
  WPP_RECORDER_AND_TRACE_SF_qqd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar14,uVar9,
             in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,uVar15,
             &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,uVar16,uVar17,(char)iVar4);
  return iVar4;
}



===== StartReadPump @ 140008c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidSpiCxReportInterface::StartReadPump(unsigned __int64) __ptr64 */

long __thiscall
HidSpiCxReportInterface::StartReadPump(HidSpiCxReportInterface *this,__uint64 param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong lVar10;
  nothrow_t *pnVar11;
  HidSpiCxReportInterface *pHVar12;
  char cVar13;
  ulonglong uVar14;
  bool bVar15;
  longlong local_res10 [2];
  __uint64 _Var16;
  undefined8 in_stack_ffffffffffffff50;
  undefined *in_stack_ffffffffffffff60;
  ulonglong local_78 [5];
  undefined8 uStack_50;
  undefined8 local_48;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar13 = '\0';
  }
  else {
    cVar13 = '\x01';
  }
  bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar13 != '\0') || (bVar15)) {
    uVar1 = *(undefined8 *)(this + 0x20);
    uVar8 = *(undefined8 *)this;
    uVar7 = imp_WppRecorderLogGetDefault();
    in_stack_ffffffffffffff60 = &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids;
    WPP_RECORDER_AND_TRACE_SF_qPP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar15,uVar7,4,
               in_stack_ffffffffffffff50,0xd,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
               (char)uVar8,(char)uVar1,(char)param_1);
  }
  uVar14 = *(ulonglong *)(this + 0x70);
  if (uVar14 < param_1) {
    while (*(longlong *)(*(longlong *)(this + 0x50) + 0x10) != 0) {
      (**(code **)(WdfFunctions_01031 + 0x680))
                (WdfDriverGlobals,*(longlong *)(*(longlong *)(this + 0x50) + 0x10));
      plVar9 = (longlong *)(*(longlong **)(this + 0x50))[1];
      lVar10 = **(longlong **)(this + 0x50);
      *plVar9 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar9;
      ExFreePoolWithTag();
      *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + -1;
    }
    *(undefined8 *)(this + 0x70) = 0;
    uVar14 = 0;
  }
  local_78[1] = 0;
  local_48 = 0;
  local_78[2] = 0;
  uStack_50 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_78[0] = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_78[0] = 0xffffffff;
  }
  else {
    local_78[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  local_78[4] = *(ulonglong *)(this + 0x18);
  local_78[3] = 0x100000001;
  if (uVar14 < param_1) {
    uVar14 = 0;
    if (*(longlong *)(this + 0x20) != -1) {
      do {
        local_res10[0] = 0;
        pnVar11 = (nothrow_t *)local_78;
        local_res10[1] = 0;
        plVar9 = local_res10;
        _Var16 = param_1;
        iVar5 = (**(code **)(WdfFunctions_01031 + 0x600))
                          (WdfDriverGlobals,pnVar11,0x200,0x58435348,param_1,plVar9,local_res10 + 1)
        ;
        lVar4 = local_res10[1];
        lVar10 = local_res10[0];
        if (iVar5 < 0) {
          return iVar5;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar13 = '\0';
        }
        else {
          cVar13 = '\x01';
        }
        bVar15 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar13 != '\0') || (bVar15)) {
          uVar1 = *(undefined8 *)this;
          uVar8 = imp_WppRecorderLogGetDefault();
          pnVar11 = (nothrow_t *)CONCAT71((int7)((ulonglong)pnVar11 >> 8),cVar13);
          WPP_RECORDER_AND_TRACE_SF_qqq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar13,bVar15,uVar8,_Var16,plVar9,
                     0xe,in_stack_ffffffffffffff60,(char)uVar1,(char)lVar10,(char)lVar4);
        }
        lVar10 = *(longlong *)(this + 0x50);
        plVar9 = operator_new(0x18,pnVar11);
        if (plVar9 == (longlong *)0x0) {
          (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,local_res10[0]);
          return -0x3fffff66;
        }
        uVar14 = uVar14 + 1;
        plVar9[2] = local_res10[0];
        puVar2 = *(undefined8 **)(lVar10 + 8);
        *plVar9 = lVar10;
        plVar9[1] = (longlong)puVar2;
        *puVar2 = plVar9;
        *(longlong **)(lVar10 + 8) = plVar9;
        *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + 1;
      } while (uVar14 < *(longlong *)(this + 0x20) + 1U);
    }
    *(__uint64 *)(this + 0x70) = param_1;
  }
  this[0x30] = (HidSpiCxReportInterface)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  pHVar12 = *(HidSpiCxReportInterface **)(this + 0x38);
  while( true ) {
    if (pHVar12 == this + 0x38) {
      return 0;
    }
    lVar10 = (**(code **)(WdfFunctions_01031 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(pHVar12 + 0x10),
                        PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
    Lock::lock((Lock *)(this + 0x68));
    *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(*(longlong *)(this + 0x50) + 0x10);
    plVar9 = *(longlong **)(this + 0x50);
    plVar3 = (longlong *)plVar9[1];
    lVar10 = *plVar9;
    *plVar3 = lVar10;
    *(longlong **)(lVar10 + 8) = plVar3;
    ExFreePoolWithTag(plVar9,0x58435348);
    *(longlong *)(this + 0x60) = *(longlong *)(this + 0x60) + -1;
    Lock::unlock((Lock *)(this + 0x68));
    lVar6 = SendPingPongRead(this,*(WDFREQUEST__ **)(pHVar12 + 0x10));
    LOCK();
    *(longlong *)(this + 0x28) = *(longlong *)(this + 0x28) + 1;
    UNLOCK();
    if (lVar6 < 0) break;
    pHVar12 = *(HidSpiCxReportInterface **)pHVar12;
  }
  return lVar6;
}



===== StopAndFlushReadPump @ 140008fe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiCxReportInterface::StopAndFlushReadPump(void) __ptr64 */

void __thiscall HidSpiCxReportInterface::StopAndFlushReadPump(HidSpiCxReportInterface *this)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  HidSpiCxReportInterface *pHVar5;
  char cVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffb0;
  
  LOCK();
  *(longlong *)(this + 0x28) = *(longlong *)(this + 0x28) + 1;
  UNLOCK();
  if ((this[0x30] == (HidSpiCxReportInterface)0x0) && (1 < *(ulonglong *)(this + 0x28))) {
    this[0x30] = (HidSpiCxReportInterface)0x1;
    for (pHVar5 = *(HidSpiCxReportInterface **)(this + 0x38); pHVar5 != this + 0x38;
        pHVar5 = *(HidSpiCxReportInterface **)pHVar5) {
      lVar2 = (**(code **)(WdfFunctions_01031 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(pHVar5 + 0x10),
                         PTR__WDF_HidSpiCxReportInterfaceRequestContext_TYPE_INFO_1400170e0);
      LOCK();
      bVar7 = *(int *)(lVar2 + 8) == 3;
      if (bVar7) {
        *(int *)(lVar2 + 8) = 5;
      }
      UNLOCK();
      if (bVar7) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar6 = '\0';
        }
        else {
          cVar6 = '\x01';
        }
        bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar6 != '\0') || (bVar7)) {
          uVar1 = *(undefined8 *)(pHVar5 + 0x10);
          uVar4 = *(undefined8 *)this;
          uVar3 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar3,4,
                     in_stack_ffffffffffffffb0,0x19,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids
                     ,(char)uVar4,(char)uVar1);
        }
        (**(code **)(WdfFunctions_01031 + 0x810))(WdfDriverGlobals,*(undefined8 *)(pHVar5 + 0x10));
      }
    }
  }
  LOCK();
  pHVar5 = this + 0x28;
  lVar2 = *(longlong *)pHVar5;
  *(longlong *)pHVar5 = *(longlong *)pHVar5 + -1;
  UNLOCK();
  if (lVar2 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar6 != '\0') || (bVar7)) {
      uVar1 = *(undefined8 *)this;
      uVar4 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar4,4,
                 in_stack_ffffffffffffffb0,0x1a,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,
                 (char)uVar1);
    }
    HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
              (*(HidSpiDeviceStateMachine<HidSpiDevice> **)(this + 8),1);
  }
  return;
}



===== WriteOutputReport @ 140009208 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidSpiCxReportInterface::WriteOutputReport(struct _HIDSPICX_REPORT *
   __ptr64) __ptr64 */

long __thiscall
HidSpiCxReportInterface::WriteOutputReport(HidSpiCxReportInterface *this,_HIDSPICX_REPORT *param_1)

{
  HidSpiCxReportInterface *pHVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  bool bVar9;
  HidSpiCxReportInterface *in_stack_ffffffffffffff88;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 uVar10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_2c;
  undefined4 local_24;
  
  pHVar1 = this + 0x80;
  if (*(longlong *)pHVar1 == 0) {
    in_stack_ffffffffffffff88 = pHVar1;
    iVar4 = (**(code **)(WdfFunctions_01031 + 0x608))(WdfDriverGlobals,0);
  }
  else {
    iVar4 = (**(code **)(WdfFunctions_01031 + 0x618))
                      (WdfDriverGlobals,*(longlong *)pHVar1,param_1,
                       (ulonglong)*(ushort *)(param_1 + 1) + 4);
  }
  if (-1 < iVar4) {
    local_2c = 0;
    local_24 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_38 = 0x18;
    }
    else if (WdfStructureCount < 0x35) {
      local_38 = 0xffffffff;
    }
    else {
      local_38 = *(undefined4 *)(WdfStructures + 0x1a0);
    }
    local_34 = 0;
    local_30 = 0;
    iVar4 = (**(code **)(WdfFunctions_01031 + 0x7c8))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x78),&local_38);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar3 = '\0';
      }
      bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar3 != '\0') || (bVar9)) {
        uVar8 = *(undefined8 *)(this + 0x78);
        uVar6 = *(undefined8 *)this;
        uVar5 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
        WPP_RECORDER_AND_TRACE_SF_qqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar9,uVar5,
                   in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,0x1b,
                   &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,(char)uVar6,(char)uVar8,
                   (char)iVar4);
      }
    }
    else {
      lVar2 = *(longlong *)pHVar1;
      uVar8 = *(undefined8 *)(this + 0x78);
      uVar6 = (**(code **)(WdfFunctions_01031 + 0xdc0))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x18));
      uVar10 = 0;
      uVar5 = 0;
      iVar4 = (**(code **)(WdfFunctions_01031 + 0x5c8))(WdfDriverGlobals,uVar6,uVar8,lVar2);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar3 = '\0';
        }
        bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar3 != '\0') || (bVar9)) {
          uVar8 = *(undefined8 *)(this + 0x78);
          uVar6 = *(undefined8 *)this;
          uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
          WPP_RECORDER_AND_TRACE_SF_qqd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar9,uVar7,uVar5,uVar10,0x1c,
                     &WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,(char)uVar6,(char)uVar8,
                     (char)iVar4);
        }
      }
      else {
        (**(code **)(WdfFunctions_01031 + 0x820))
                  (WdfDriverGlobals,*(undefined8 *)(this + 0x78),
                   <lambda_2dd2bf9e81c39ecfd03f589d79607541>::<lambda_invoker_cdecl>,this);
        uVar8 = (**(code **)(WdfFunctions_01031 + 0xdc0))
                          (WdfDriverGlobals,*(undefined8 *)(this + 0x18));
        cVar3 = (**(code **)(WdfFunctions_01031 + 0x7e8))
                          (WdfDriverGlobals,*(undefined8 *)(this + 0x78),uVar8,0);
        if (cVar3 == '\0') {
          iVar4 = (**(code **)(WdfFunctions_01031 + 0x7f0))
                            (WdfDriverGlobals,*(undefined8 *)(this + 0x78));
        }
        else {
          iVar4 = 0;
        }
      }
    }
  }
  return iVar4;
}



===== WPP_RECORDER_AND_TRACE_SF_qP @ 140009548 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qP(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0xc,
               &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0xc,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPP @ 140009614 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPP
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,&param_11,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,1,param_8,param_7,&param_9,8,&param_10,8,&param_11,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPd @ 14000970c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0xb,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqq @ 140009804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqq
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,param_7,&param_9,8,
               &param_10,8,&param_11,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,param_7,&param_9,8,
                    &param_10,8,&param_11,8,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqqq @ 1400098f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqqq(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0x21,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,
               &uStack0000000000000060,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,5,1,&WPP_2282335edb2433c1db0c07ac37f2ed4a_Traceguids,0x21,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,
                    &uStack0000000000000060,8,0);
  }
  return;
}



===== ~HidSpiDevice @ 1400099fc =====

/* public: __cdecl HidSpiDevice::~HidSpiDevice(void) __ptr64 */

void __thiscall HidSpiDevice::~HidSpiDevice(HidSpiDevice *this)

{
  Lock *this_00;
  
  if (*(longlong *)(this + 0xb8) != 0) {
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
    *(undefined8 *)(this + 0xb8) = 0;
    *(undefined8 *)(this + 0xc0) = 0;
  }
  if (*(longlong *)(this + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 200),0x58435348);
    *(undefined8 *)(this + 200) = 0;
  }
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  if (*(_RefCountBase **)(this + 0x40) != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(*(_RefCountBase **)(this + 0x40));
  }
  if (*(_RefCountBase **)(this + 0x30) != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(*(_RefCountBase **)(this + 0x30));
  }
  Timer::~Timer((Timer *)(this + 0x18));
  Lock::~Lock((Lock *)(this + 0x10));
  this_00 = *(Lock **)(this + 8);
  if (this_00 != (Lock *)0x0) {
    Lock::~Lock(this_00);
    ExFreePoolWithTag(this_00,0x58435348);
  }
  return;
}



===== CancellingPingPongReadsEntry @ 140009ad0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CancellingPingPongReadsEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CancellingPingPongReadsEntry(void *param_1)

{
  Timer::Start((Timer *)((longlong)param_1 + 0x18),10000);
  HidSpiCxReportInterface::StopAndFlushReadPump
            (*(HidSpiCxReportInterface **)((longlong)param_1 + 0x28));
  return 8;
}



===== CheckingIfDeviceNeedsResetEntry @ 140009b10 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CheckingIfDeviceNeedsResetEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CheckingIfDeviceNeedsResetEntry(void *param_1)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  
  iVar1 = *(int *)((longlong)param_1 + 0xe4);
  if (iVar1 == 0) {
    uVar3 = 6;
  }
  else if ((iVar1 == 1) || (iVar1 != 2)) {
    uVar3 = 0xf;
  }
  else {
    bVar2 = CxDevice::CheckIfDeviceNeedsResetOnPowerOn(*(CxDevice **)((longlong)param_1 + 0x68));
    uVar3 = (-(ushort)bVar2 & 9) + 6;
  }
  return uVar3;
}



===== CheckingIfShouldResetOnPowerUpTimeoutEntry @ 140009b60 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CheckingIfShouldResetOnPowerUpTimeoutEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CheckingIfShouldResetOnPowerUpTimeoutEntry
          (void *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  
  uVar2 = Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    uVar1 = 6;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x9c) = 1;
    uVar1 = 0xf;
  }
  return uVar1;
}



===== CheckingResetRetryCountEntry @ 140009ba0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CheckingResetRetryCountEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CheckingResetRetryCountEntry(void *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)((longlong)param_1 + 0x70);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    *(undefined4 *)((longlong)param_1 + 0x20) = 0xc;
    return 7;
  }
  return 8;
}



===== CheckingWriteCompletionStatusEntry @ 140009bd0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CheckingWriteCompletionStatusEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CheckingWriteCompletionStatusEntry
          (void *param_1)

{
  return (-1 < *(int *)((longlong)param_1 + 0xa8)) + 7;
}



===== ClearDeviceState @ 140009be8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::ClearDeviceState(void) __ptr64 */

Event __thiscall HidSpiDevice::ClearDeviceState(HidSpiDevice *this)

{
  undefined4 uVar1;
  Event EVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  char cVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffff40;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar6 != '\0') || (bVar7)) {
    uVar1 = *(undefined4 *)(this + 0x20);
    uVar4 = *(undefined8 *)(this + 0x68);
    uVar3 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar3,4,
               in_stack_ffffffffffffff40,0x14,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar4,(char)uVar1);
  }
  (**(code **)(WdfFunctions_01031 + 0x4d8))
            (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 0x68) + 0x40),0,0);
  Timer::Stop((Timer *)(this + 0x18));
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  CompletePendingTransferAndSetNotReady(this);
  *(undefined4 *)(this + 0xa8) = 0xc00000e5;
  if (*(longlong *)(this + 200) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 200),0x58435348);
    *(undefined8 *)(this + 200) = 0;
  }
  if (*(longlong *)(this + 0xb8) != 0) {
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
    *(undefined8 *)(this + 0xb8) = 0;
    *(undefined8 *)(this + 0xc0) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar6 != '\0') || (bVar7)) {
    uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_AND_TRACE_SF_qLLLLLLLLL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar4);
  }
  cVar6 = '\x01';
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined8 *)(this + 0xd0) = 4;
  *(undefined8 *)(this + 0xd8) = 0x20;
  lVar5 = ExAllocatePool2(0x40,4,0x58435348);
  *(longlong *)(this + 200) = lVar5;
  if (lVar5 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar6 = '\0';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar6 != '\0') || (bVar7)) {
      uVar4 = *(undefined8 *)(this + 0x68);
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar3,2,
                 in_stack_ffffffffffffff40,0x16,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar4);
    }
    *(undefined4 *)(this + 0x20) = 4;
    EVar2 = 7;
  }
  else {
    *(undefined4 *)(this + 0x70) = 3;
    EVar2 = 8;
  }
  return EVar2;
}



===== ClearingDeviceStateEntry @ 140009f80 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ClearingDeviceStateEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ClearingDeviceStateEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::ClearDeviceState(param_1);
  return (ushort)EVar1;
}



===== CompletePendingTransferAndSetNotReady @ 140009f98 =====

/* private: void __cdecl HidSpiDevice::CompletePendingTransferAndSetNotReady(void) __ptr64 */

void __thiscall HidSpiDevice::CompletePendingTransferAndSetNotReady(HidSpiDevice *this)

{
  HidSpiRequest *this_00;
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  Lock::lock((Lock *)(this + 0x10));
  this_00 = *(HidSpiRequest **)(this + 0xb0);
  *(undefined8 *)(this + 0xb0) = 0;
  this[0x9d] = (HidSpiDevice)0x0;
  Lock::unlock((Lock *)(this + 0x10));
  if (this_00 != (HidSpiRequest *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar3 = '\0';
    }
    bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar3 != '\0') || (bVar4)) {
      uVar1 = *(undefined8 *)(this + 0x68);
      uVar2 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
                 in_stack_ffffffffffffffd0,0x40,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)this_00);
    }
    HidSpiRequest::Complete(this_00,-0x3fffff1b);
  }
  return;
}



===== CompletePowerFailure @ 14000a0a4 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::CompletePowerFailure(void) __ptr64 */

Event __thiscall HidSpiDevice::CompletePowerFailure(HidSpiDevice *this)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar5 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar5 = '\0';
  }
  bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar5 != '\0') || (bVar6)) {
    uVar1 = *(undefined4 *)(this + 0xe0);
    uVar2 = *(undefined8 *)(this + 0x68);
    uVar4 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,
               in_stack_ffffffffffffffd0,0x3d,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar2,(char)uVar1);
  }
  lVar3 = *(longlong *)(this + 0x68);
  *(undefined4 *)(this + 0x20) = 6;
  *(undefined4 *)(lVar3 + 0xe8) = 0xc0000001;
  KeSetEvent(lVar3 + 0xf0,0,0);
  *(undefined4 *)(this + 0xe0) = 0;
  return 8;
}



===== CompletePowerSuccess @ 14000a1b0 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::CompletePowerSuccess(void) __ptr64 */

Event __thiscall HidSpiDevice::CompletePowerSuccess(HidSpiDevice *this)

{
  undefined8 uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  char cVar7;
  bool bVar8;
  undefined8 in_stack_ffffffffffffffb0;
  
  bVar2 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar7 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar7 = '\0';
  }
  bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar7 != '\0') || (bVar8)) {
    uVar3 = *(undefined4 *)(this + 0xe0);
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar4 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar8,uVar4,4,
               in_stack_ffffffffffffffb0,0x3e,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1,(char)uVar3);
  }
  uVar3 = 7;
  if (*(int *)(this + 0xe0) != 1) {
    uVar3 = 0;
  }
  *(undefined4 *)(this + 0x20) = uVar3;
  lVar6 = *(longlong *)(this + 0x68);
  *(undefined4 *)(lVar6 + 0xe8) = 0;
  lVar6 = lVar6 + 0xf0;
  KeSetEvent(lVar6,0);
  *(undefined4 *)(this + 0xe0) = 0;
  uVar5 = Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar5 != 0) && (this[0x9c] != (HidSpiDevice)0x0)) {
    this[0x9c] = (HidSpiDevice)0x0;
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (lVar6,CONCAT22(*(undefined2 *)(this + 0x54),*(undefined2 *)(this + 0x56)),0,
               "Recovered after power-on timeout");
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 3))))
    {
      bVar2 = false;
    }
    bVar8 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar2) || (bVar8)) {
      uVar1 = *(undefined8 *)(this + 0x68);
      uVar4 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar8,uVar4,3,
                 in_stack_ffffffffffffffb0,0x3f,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1);
    }
  }
  return 8;
}



===== CompleteTransferIfDoneOrStartResponseTimer @ 14000a38c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::CompleteTransferIfDoneOrStartResponseTimer(void) __ptr64 */

Event __thiscall HidSpiDevice::CompleteTransferIfDoneOrStartResponseTimer(HidSpiDevice *this)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar2 = *(longlong *)(this + 0xb0);
  bVar4 = true;
  iVar1 = *(int *)(lVar2 + 0x48);
  if ((iVar1 - 1U < 3) || (((iVar1 == 4 && (((byte)this[0x5a] & 1) == 0)) || (iVar1 == 5)))) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar4 = false;
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar4 != false) || (bVar7)) {
      uVar3 = *(undefined8 *)(this + 0x68);
      uVar6 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,bVar7,uVar6,4,
                 in_stack_ffffffffffffffd0,0x17,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar3,(char)lVar2);
    }
    Timer::Start((Timer *)(this + 0x18),2000);
  }
  else {
    LOCK();
    *(int *)(this + 0x94) = *(int *)(this + 0x94) + 1;
    UNLOCK();
    LOCK();
    *(int *)(this + 0x88) = *(int *)(this + 0x88) + 1;
    UNLOCK();
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      bVar4 = false;
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar4) || (bVar7)) {
      uVar3 = *(undefined8 *)(this + 0xb0);
      uVar6 = *(undefined8 *)(this + 0x68);
      uVar5 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,bVar7,uVar5,4,
                 in_stack_ffffffffffffffd0,0x18,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar6,(char)uVar3);
    }
    (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,**(undefined8 **)(this + 0xb0),0);
    HidSpiRequest::Complete(*(HidSpiRequest **)(this + 0xb0),0);
    *(undefined8 *)(this + 0xb0) = 0;
  }
  return 8;
}



===== CompletingPowerFailureEntry @ 14000a580 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CompletingPowerFailureEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CompletingPowerFailureEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::CompletePowerFailure(param_1);
  return (ushort)EVar1;
}



===== CompletingPowerSuccessOnPowerDownEntry @ 14000a5a0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CompletingPowerSuccessOnPowerDownEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CompletingPowerSuccessOnPowerDownEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::CompletePowerSuccess(param_1);
  return (ushort)EVar1;
}



===== CompletingTransferIfDoneEntry @ 14000a5c0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::CompletingTransferIfDoneEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::CompletingTransferIfDoneEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::CompleteTransferIfDoneOrStartResponseTimer(param_1);
  return (ushort)EVar1;
}



===== ConfigurePowerTransfer @ 14000a5d8 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::ConfigurePowerTransfer(void) __ptr64 */

Event __thiscall HidSpiDevice::ConfigurePowerTransfer(HidSpiDevice *this)

{
  int iVar1;
  
  memset(*(void **)(this + 200),0,*(size_t *)(this + 0xd0));
  **(undefined1 **)(this + 200) = 7;
  *(undefined2 *)(*(longlong *)(this + 200) + 1) = 1;
  *(undefined1 *)(*(longlong *)(this + 200) + 3) = 1;
  iVar1 = *(int *)(this + 0xe0);
  if (iVar1 == 1) {
    *(undefined1 *)(*(longlong *)(this + 200) + 4) = 1;
  }
  else if (iVar1 == 2) {
    *(undefined1 *)(*(longlong *)(this + 200) + 4) = 2;
  }
  else if (iVar1 == 3) {
    *(undefined1 *)(*(longlong *)(this + 200) + 4) = 3;
  }
  return 8;
}



===== ConfigureTransfer @ 14000a664 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::ConfigureTransfer(void) __ptr64 */

Event __thiscall HidSpiDevice::ConfigureTransfer(HidSpiDevice *this)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong _Size;
  void *_Src;
  Event EVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  long lVar8;
  char cVar9;
  bool bVar10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  
  lVar3 = *(longlong *)(this + 0xb0);
  if (lVar3 == 0) {
LAB_14000a690:
    EVar4 = 7;
  }
  else {
    iVar2 = *(int *)(lVar3 + 0x48);
    uVar1 = *(undefined1 *)(lVar3 + 0x4c);
    if (iVar2 == 1) {
      memset(*(void **)(this + 200),0,*(size_t *)(this + 0xd0));
      **(undefined1 **)(this + 200) = 2;
    }
    else {
      if (iVar2 != 2) {
        if ((iVar2 == 3) || (iVar2 == 4)) {
          _Size = *(ulonglong *)(lVar3 + 0x30);
          _Src = *(void **)(lVar3 + 0x28);
          if (_Size <= *(ushort *)(this + 0x50)) {
            memset(*(void **)(this + 200),0,*(size_t *)(this + 0xd0));
            memcpy((void *)(*(longlong *)(this + 200) + 4),_Src,_Size);
            uVar7 = 3;
            if (iVar2 != 3) {
              uVar7 = 5;
            }
            **(undefined1 **)(this + 200) = uVar7;
            *(short *)(*(longlong *)(this + 200) + 1) = (short)_Size;
            goto LAB_14000a89e;
          }
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar9 != '\0') || (bVar10)) {
            uVar6 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qqPD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar10,uVar6);
          }
          lVar8 = -0x3fffffdd;
        }
        else {
          if (iVar2 == 5) goto LAB_14000a86f;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar9 != '\0') || (bVar10)) {
            uVar6 = *(undefined8 *)(this + 0x68);
            uVar5 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qqd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar10,uVar5,
                       in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0x24,
                       &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar6,(char)lVar3,0xd)
            ;
          }
          lVar8 = -0x3ffffff3;
        }
        HidSpiRequest::Complete(*(HidSpiRequest **)(this + 0xb0),lVar8);
        *(undefined8 *)(this + 0xb0) = 0;
        goto LAB_14000a690;
      }
LAB_14000a86f:
      memset(*(void **)(this + 200),0,*(size_t *)(this + 0xd0));
      uVar7 = 4;
      if (iVar2 != 2) {
        uVar7 = 6;
      }
      **(undefined1 **)(this + 200) = uVar7;
LAB_14000a89e:
      *(undefined1 *)(*(longlong *)(this + 200) + 3) = uVar1;
    }
    EVar4 = 8;
  }
  return EVar4;
}



===== ConfiguringDescriptorTransferEntry @ 14000a900 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ConfiguringDescriptorTransferEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ConfiguringDescriptorTransferEntry
          (void *param_1)

{
  memset(*(void **)((longlong)param_1 + 200),0,*(size_t *)((longlong)param_1 + 0xd0));
  **(undefined1 **)((longlong)param_1 + 200) = 1;
  return 8;
}



===== ConfiguringPowerOnTransferEntry @ 14000a940 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ConfiguringPowerOnTransferEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ConfiguringPowerOnTransferEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::ConfigurePowerTransfer(param_1);
  return (ushort)EVar1;
}



===== ConfiguringTransferEntry @ 14000a960 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ConfiguringTransferEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ConfiguringTransferEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::ConfigureTransfer(param_1);
  return (ushort)EVar1;
}



===== DebouncingResetOnPowerUpEntry @ 14000a980 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::DebouncingResetOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::DebouncingResetOnPowerUpEntry(void *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffc0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar4 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar4 != '\0') || (bVar5)) {
    uVar1 = *(undefined4 *)((longlong)param_1 + 0x74);
    uVar2 = *(undefined8 *)((longlong)param_1 + 0x68);
    uVar3 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,uVar3,4,
               in_stack_ffffffffffffffc0,0x51,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar2,(char)uVar1);
  }
  Timer::Start((Timer *)((longlong)param_1 + 0x18),*(ulong *)((longlong)param_1 + 0x74));
  return 0;
}



===== Dispatch @ 14000aa60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiDevice::Dispatch(class HidSpiRequest * __ptr64) __ptr64 */

void __thiscall HidSpiDevice::Dispatch(HidSpiDevice *this,HidSpiRequest *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  HidSpiRequest *pHVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  undefined8 in_stack_ffffffffffffffb0;
  
  bVar6 = false;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x8c8))
                    (WdfDriverGlobals,*(undefined8 *)param_1,**(undefined8 **)(this + 8));
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar5 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar1 = *(undefined8 *)(this + 0x68);
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar3,
                 CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
                 in_stack_ffffffffffffffb0,0x10,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)param_1,(char)iVar2);
    }
    HidSpiRequest::Complete(param_1,-0x3fffff1b);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar7)) {
      uVar1 = *(undefined8 *)(this + 0x68);
      uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar7,uVar3,4,
                 in_stack_ffffffffffffffb0,0x11,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)param_1);
    }
    Lock::lock((Lock *)(this + 0x10));
    if (this[0x9d] != (HidSpiDevice)0x0) {
      pHVar4 = HidSpiRequestQueue::Dequeue(*(HidSpiRequestQueue **)(this + 8));
      *(HidSpiRequest **)(this + 0xb0) = pHVar4;
      if (pHVar4 != (HidSpiRequest *)0x0) {
        bVar6 = true;
        this[0x9d] = (HidSpiDevice)0x0;
      }
    }
    Lock::unlock((Lock *)(this + 0x10));
    if (bVar6) {
      HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,0xe);
    }
  }
  return;
}



===== EnqueueEvent @ 14000ac60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiDeviceStateMachine<class HidSpiDevice>::EnqueueEvent(enum
   HidSpiDeviceStateMachine<class HidSpiDevice>::Event) __ptr64 */

void __thiscall
HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
          (HidSpiDeviceStateMachine<HidSpiDevice> *this,Event param_1)

{
  StateMachineEngineImpl *this_00;
  StateMachineEngineImpl SVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 uVar4;
  bool bVar5;
  
  this_00 = *(StateMachineEngineImpl **)this;
  uVar3 = (ushort)param_1;
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this_00 + 1000);
  this_00[0x3f1] = SVar1;
  if (*(int *)(this_00 + 0x3e0) == 5) {
    if (uVar3 == *(ushort *)(this_00 + 0x370)) {
      if (*(code **)(this_00 + 0x3a0) != (code *)0x0) {
        if (uVar3 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined2 *)
                   (*(longlong *)(*(longlong *)(this_00 + 0x378) + 0x10) + (ulonglong)uVar3 * 4);
        }
        (**(code **)(this_00 + 0x3a0))(*(undefined8 *)(this_00 + 0x380),uVar4);
      }
      *(undefined2 *)(this_00 + 0x370) = 0;
      goto LAB_14000acee;
    }
    bVar5 = false;
  }
  else {
    bVar5 = *(int *)(this_00 + 0x3e0) == 1;
  }
  bVar2 = SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition
                    (this_00,uVar3);
  if (!bVar2) {
    return;
  }
  if (!bVar5) {
    KeReleaseSpinLock(this_00 + 1000,this_00[0x3f1]);
    return;
  }
LAB_14000acee:
  this_00[0x3d7] = SVar1;
  this_00[0x3d6] = (StateMachineEngineImpl)0x0;
  if ((byte)SVar1 < 2) {
    *(void **)(this_00 + 0x3d8) = SystemReserved1[0xf];
  }
  else {
    *(undefined4 *)(this_00 + 0x3d8) = SystemReserved1[0x12]._4_4_;
  }
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(this_00);
  return;
}



===== EvtDeviceNeedsReset @ 14000ad7c =====

/* public: void __cdecl HidSpiDevice::EvtDeviceNeedsReset(void) __ptr64 */

void __thiscall HidSpiDevice::EvtDeviceNeedsReset(HidSpiDevice *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,2,
               in_stack_ffffffffffffffd0,0x4f,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1);
  }
  HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
            ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,4);
  return;
}



===== EvtDeviceReset @ 14000ae48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidClassMinidriver<class HidSpiRequestManager,class
   HidSpiRequest>::EvtDeviceReset(long) __ptr64 */

void __thiscall
HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::EvtDeviceReset
          (HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> *this,long param_1)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01031 + 0x4f0))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x18),local_res8);
  if (-1 < iVar1) {
    (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,local_res8[0],0);
  }
  return;
}



===== EvtInputReportReceived @ 14000aea8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl HidSpiDevice::EvtInputReportReceived(struct _HIDSPICX_REPORT * __ptr64,void
   * __ptr64) __ptr64 */

bool __thiscall
HidSpiDevice::EvtInputReportReceived(HidSpiDevice *this,_HIDSPICX_REPORT *param_1,void *param_2)

{
  _HIDSPICX_REPORT _Var1;
  ushort uVar2;
  ushort uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong _Size;
  undefined8 uVar7;
  _HIDSPICX_REPORT *_Dst;
  char cVar8;
  ulonglong uVar9;
  bool bVar10;
  bool bVar11;
  _HIDSPICX_REPORT *local_res8;
  ulonglong local_res10;
  ulonglong local_res20;
  undefined8 in_stack_ffffffffffffff88;
  undefined8 in_stack_ffffffffffffff90;
  undefined8 in_stack_ffffffffffffffa0;
  
  LOCK();
  *(int *)(this + 0x80) = *(int *)(this + 0x80) + 1;
  UNLOCK();
  LOCK();
  *(int *)(this + 0x84) = *(int *)(this + 0x84) + 1;
  UNLOCK();
  bVar11 = false;
  cVar8 = '\x01';
  local_res8 = (_HIDSPICX_REPORT *)0x0;
  local_res20 = 0;
  if (*param_1 == (_HIDSPICX_REPORT)0x1) {
    uVar2 = *(ushort *)(param_1 + 1);
    uVar3 = *(ushort *)(this + 0x4e);
    if (uVar2 <= uVar3) {
      local_res10 = 0;
      iVar5 = (**(code **)(WdfFunctions_01031 + 0x4f0))
                        (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 0x38) + 0x10),
                         &local_res10);
      if ((iVar5 < 0) ||
         (iVar5 = (**(code **)(WdfFunctions_01031 + 0x870))
                            (WdfDriverGlobals,local_res10,0,&local_res8,&local_res20),
         uVar4 = local_res10, iVar5 < 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          bVar11 = true;
        }
        bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar11 == false) && (!bVar10)) {
          return true;
        }
        uVar7 = *(undefined8 *)(this + 0x68);
        uVar6 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar11,bVar10,uVar6,2,
                   in_stack_ffffffffffffff90,0x49,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                   (char)uVar7);
        return true;
      }
      _Var1 = param_1[3];
      _Size = (ulonglong)*(ushort *)(param_1 + 1);
      local_res10 = local_res20;
      uVar9 = (_Var1 != (_HIDSPICX_REPORT)0x0) + _Size;
      if (local_res20 < uVar9) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          bVar11 = true;
        }
        bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar11 != false) || (bVar10)) {
          uVar7 = *(undefined8 *)(this + 0x68);
          uVar6 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qPP
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar11,bVar10,uVar6,2,
                     in_stack_ffffffffffffff90,0x4a,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids
                     ,(char)uVar7,(char)local_res10,(char)uVar9);
        }
        (**(code **)(WdfFunctions_01031 + 0x8d8))(WdfDriverGlobals,uVar4);
        return true;
      }
      if (_Var1 == (_HIDSPICX_REPORT)0x0) {
        _Dst = local_res8;
      }
      else {
        *local_res8 = _Var1;
        _Size = (ulonglong)*(ushort *)(param_1 + 1);
        _Dst = local_res8 + 1;
      }
      memcpy(_Dst,param_1 + 4,_Size);
      (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,uVar4,uVar9);
      (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,uVar4,0);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
        cVar8 = '\0';
      }
      bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar8 == '\0') && (!bVar11)) {
        return true;
      }
      uVar7 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qdP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,bVar11,uVar7);
      return true;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      bVar11 = true;
    }
    bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar11) || (bVar10)) {
      uVar7 = *(undefined8 *)(this + 0x68);
      uVar6 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qPD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar11,bVar10,uVar6,
                 in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,0x48,in_stack_ffffffffffffffa0,
                 (char)uVar7,(char)uVar2,(char)uVar3);
    }
    *(undefined4 *)(this + 0x20) = 5;
  }
  else {
    LOCK();
    bVar10 = *(longlong *)(this + 0xb8) == 0;
    if (bVar10) {
      *(_HIDSPICX_REPORT **)(this + 0xb8) = param_1;
    }
    UNLOCK();
    if (bVar10) {
      *(void **)(this + 0xc0) = param_2;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)
         ) {
        cVar8 = '\0';
      }
      bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar8 != '\0') || (bVar11)) {
        uVar7 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qDDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,bVar11,uVar7);
      }
      HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
                ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,0xb);
      return false;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      bVar11 = true;
    }
    bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((bVar11 != false) || (bVar10)) {
      uVar7 = *(undefined8 *)(this + 0x68);
      uVar6 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar11,bVar10,uVar6,2,
                 in_stack_ffffffffffffff90,0x4c,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar7);
    }
  }
  EvtDeviceNeedsReset(this);
  return true;
}



===== EvtLogEventEnqueue @ 14000b3c0 =====

/* private: void __cdecl HidSpiDevice::EvtLogEventEnqueue(enum HidSpiDeviceStateMachine<class
   HidSpiDevice>::EventId) __ptr64 */

void __thiscall HidSpiDevice::EvtLogEventEnqueue(HidSpiDevice *this,EventId param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x39,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1,(char)param_1);
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 14000b490 =====

/* private: static void __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EvtLogEventEnqueueThunk(void *param_1,ushort param_2)

{
  undefined2 in_register_00000012;
  
  HidSpiDevice::EvtLogEventEnqueue(param_1,CONCAT22(in_register_00000012,param_2));
  return;
}



===== EvtLogMachineException @ 14000b4a8 =====

/* private: void __cdecl HidSpiDevice::EvtLogMachineException(enum SmFx::MachineException,enum
   HidSpiDeviceStateMachine<class HidSpiDevice>::EventId,enum HidSpiDeviceStateMachine<class
   HidSpiDevice>::StateId) __ptr64 */

void __thiscall
HidSpiDevice::EvtLogMachineException
          (HidSpiDevice *this,MachineException param_1,EventId param_2,StateId param_3)

{
  undefined *puVar1;
  char cVar2;
  char *pcVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') ||
     (puVar1 = WPP_GLOBAL_Control,
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    puVar1 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_RECORDER_AND_TRACE_SF_qqLLL
              (puVar1,cVar2,(undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (param_1 == 1) {
    pcVar3 = "SM Unhandled Event";
  }
  else if (param_1 == 2) {
    pcVar3 = "SM Event Queue Overflow";
  }
  else {
    if (param_1 != 3) {
      return;
    }
    pcVar3 = "SM Stack Overflow";
  }
  MicrosoftTelemetryAssertTriggeredArgsMsgKM(puVar1,param_2 & 0xffff,param_3 & 0xffff,pcVar3);
  return;
}



===== EvtLogMachineExceptionThunk @ 14000b590 =====

/* private: static void __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EvtLogMachineExceptionThunk(void * __ptr64,enum SmFx::MachineException,unsigned
   short,unsigned short) */

void __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  
  HidSpiDevice::EvtLogMachineException
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4));
  return;
}



===== EvtLogTransition @ 14000b5a8 =====

/* private: void __cdecl HidSpiDevice::EvtLogTransition(enum SmFx::TransitionType,enum
   HidSpiDeviceStateMachine<class HidSpiDevice>::StateId,enum HidSpiDeviceStateMachine<class
   HidSpiDevice>::EventId,enum HidSpiDeviceStateMachine<class HidSpiDevice>::StateId) __ptr64 */

void __thiscall
HidSpiDevice::EvtLogTransition
          (HidSpiDevice *this,TransitionType param_1,StateId param_2,EventId param_3,StateId param_4
          )

{
  undefined8 uVar1;
  char cVar2;
  bool bVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar2 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar2 != '\0') || (bVar3)) {
    uVar1 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,uVar1);
  }
  return;
}



===== EvtLogTransitionThunk @ 14000b680 =====

/* private: static void __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_00000082;
  undefined2 in_register_0000008a;
  undefined4 in_stack_ffffffffffffffe8;
  
  HidSpiDevice::EvtLogTransition
            (param_1,param_2,CONCAT22(in_register_00000082,param_3),
             CONCAT22(in_register_0000008a,param_4),
             CONCAT22((short)((uint)in_stack_ffffffffffffffe8 >> 0x10),param_5));
  return;
}



===== EvtMachineDestroyed @ 14000b6a0 =====

/* private: void __cdecl HidSpiDevice::EvtMachineDestroyed(void) __ptr64 */

void __thiscall HidSpiDevice::EvtMachineDestroyed(HidSpiDevice *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x3b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1);
  }
  Timer::Stop((Timer *)(this + 0x18));
  CompletePendingTransferAndSetNotReady(this);
  KeSetEvent(*(longlong *)(this + 0x68) + 0x108,0,0);
  return;
}



===== EvtMachineDestroyedThunk @ 14000b790 =====

/* private: static void __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl HidSpiDeviceStateMachine<HidSpiDevice>::EvtMachineDestroyedThunk(void *param_1)

{
  HidSpiDevice::EvtMachineDestroyed(param_1);
  return;
}



===== EvtTimerFired @ 14000b7b0 =====

/* private: static void __cdecl HidSpiDevice::EvtTimerFired(void * __ptr64) */

void __cdecl HidSpiDevice::EvtTimerFired(void *param_1)

{
  LOCK();
  *(int *)((longlong)param_1 + 0x98) = *(int *)((longlong)param_1 + 0x98) + 1;
  UNLOCK();
  *(undefined4 *)((longlong)param_1 + 0x20) = 2;
  HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent(param_1,0xd);
  return;
}



===== Initialize @ 14000b7dc =====

/* public: long __cdecl HidSpiDeviceStateMachine<class HidSpiDevice>::Initialize(struct
   HidSpiDeviceStateMachine<class HidSpiDevice>::StateMachineEngineConfig const & __ptr64) __ptr64
    */

long __thiscall
HidSpiDeviceStateMachine<HidSpiDevice>::Initialize
          (HidSpiDeviceStateMachine<HidSpiDevice> *this,StateMachineEngineConfig *param_1)

{
  long lVar1;
  StateMachineEngineImpl *this_00;
  int iVar2;
  STATE_MACHINE_SPECIFICATION *local_58;
  HidSpiDeviceStateMachine<HidSpiDevice> *local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  code *local_38;
  code *local_30;
  code *local_28;
  code *local_20;
  undefined2 local_18;
  undefined4 local_16;
  undefined2 local_12;
  
  local_40 = *(int *)(param_1 + 8);
  local_58 = &c_specification;
  local_48 = *(undefined8 *)param_1;
  local_38 = EvtLogMachineExceptionThunk;
  local_3c = 0;
  local_30 = EvtLogEventEnqueueThunk;
  local_16 = 0;
  local_28 = EvtLogTransitionThunk;
  local_12 = 0;
  iVar2 = 0x78466d53;
  if (local_40 != 0) {
    iVar2 = local_40;
  }
  local_20 = EvtMachineDestroyedThunk;
  local_18 = 0x401;
  local_50 = this;
  this_00 = (StateMachineEngineImpl *)ExAllocatePool2(0x40,0x420,iVar2);
  if (this_00 == (StateMachineEngineImpl *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memset(this_00,0,0x420);
    *(undefined2 *)(this_00 + 0x3d5) = 0x101;
    this_00[0x3d7] = (StateMachineEngineImpl)0x2;
    *(undefined8 *)(this_00 + 0x408) = 0;
    *(undefined8 *)(this_00 + 0x410) = 0;
    *(HidSpiDeviceStateMachine<HidSpiDevice> **)(this_00 + 0x418) = this;
    *(StateMachineEngineImpl **)this = this_00;
    lVar1 = SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize
                      (this_00,(STATE_MACHINE_ENGINE_CONFIG *)&local_58);
    if (lVar1 < 0) {
      SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(this_00);
      *(undefined8 *)this = 0;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== Initialize @ 14000b908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl HidSpiDevice::Initialize(class utl::shared_ptr<class
   HidClassMinidriver<class HidSpiRequestManager,class HidSpiRequest> > & __ptr64,class
   utl::shared_ptr<class HidSpiCxReportInterface>,class CxDevice * __ptr64,struct WDFDEVICE__ *
   __ptr64) __ptr64 */

long __thiscall
HidSpiDevice::Initialize
          (HidSpiDevice *this,nothrow_t *param_1,undefined8 *param_3,undefined8 param_4,
          WDFDEVICE__ *param_5)

{
  uint uVar1;
  longlong lVar2;
  _RefCountBase *p_Var3;
  Lock *this_00;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char cVar9;
  _func_void_void_ptr *p_Var10;
  bool bVar11;
  undefined8 in_stack_ffffffffffffff40;
  undefined2 uVar12;
  undefined8 in_stack_ffffffffffffff50;
  undefined1 uVar13;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c [84];
  
  lVar2 = *(longlong *)(param_1 + 8);
  uVar8 = *(undefined8 *)param_1;
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 8) = *(int *)(lVar2 + 8) + 1;
    UNLOCK();
  }
  *(undefined8 *)(this + 0x38) = uVar8;
  p_Var3 = *(_RefCountBase **)(this + 0x40);
  *(longlong *)(this + 0x40) = lVar2;
  if (p_Var3 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(p_Var3);
  }
  *(undefined8 *)(this + 0x68) = param_4;
  lVar2 = param_3[1];
  uVar8 = *param_3;
  if (lVar2 != 0) {
    LOCK();
    *(int *)(lVar2 + 8) = *(int *)(lVar2 + 8) + 1;
    UNLOCK();
  }
  *(undefined8 *)(this + 0x28) = uVar8;
  p_Var3 = *(_RefCountBase **)(this + 0x30);
  *(longlong *)(this + 0x30) = lVar2;
  if (p_Var3 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(p_Var3);
  }
  puVar6 = operator_new(8,param_1);
  if (puVar6 != (undefined8 *)0x0) {
    *puVar6 = 0;
  }
  this_00 = *(Lock **)(this + 8);
  *(undefined8 **)(this + 8) = puVar6;
  if (this_00 != (Lock *)0x0) {
    Lock::~Lock(this_00);
    ExFreePoolWithTag(this_00);
  }
  lVar2 = *(longlong *)(this + 8);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 != '\0') || (bVar11)) {
      uVar8 = *(undefined8 *)(this + 0x68);
      uVar7 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,uVar7,2,
                 in_stack_ffffffffffffff40,10,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar8);
    }
    if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
    }
    return -0x3fffff66;
  }
  memset(local_6c,0,0x54);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_78 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_78 = 0xffffffff;
  }
  else {
    local_78 = *(undefined4 *)(WdfStructures + 0x108);
  }
  p_Var10 = (_func_void_void_ptr *)&local_78;
  local_70 = 0;
  local_74 = 3;
  iVar4 = (**(code **)(WdfFunctions_01031 + 0x4c0))(WdfDriverGlobals,param_5,p_Var10,0,lVar2);
  if (iVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 != '\0') || (bVar11)) {
      uVar8 = *(undefined8 *)(this + 0x68);
      uVar7 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,uVar7,2,
                 in_stack_ffffffffffffff40,0xb,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar8,(char)iVar4);
    }
    if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
    }
    return iVar4;
  }
  lVar5 = Timer::Initialize((Timer *)(this + 0x18),param_5,p_Var10,this);
  if (lVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 == '\0') && (!bVar11)) goto LAB_14000bc49;
    uVar13 = (undefined1)*(undefined8 *)(this + 0x68);
    uVar8 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    uVar12 = 0xc;
  }
  else {
    lVar5 = Lock::Initialize((Lock *)(this + 0x10),param_5);
    if (-1 < lVar5) {
      uVar1 = *(uint *)(*(longlong *)(this + 0x68) + 0x124);
      *(uint *)(this + 0x74) = uVar1;
      if (uVar1 == 0) {
        *(undefined4 *)(this + 0x74) = 1000;
      }
      else {
        uVar13 = (undefined1)*(longlong *)(this + 0x68);
        if (uVar1 < 100) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar9 = '\0';
          }
          bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar9 != '\0') || (bVar11)) {
            uVar8 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,uVar8,3,
                       in_stack_ffffffffffffff40,0xe,in_stack_ffffffffffffff50,uVar13,(char)uVar1,
                       100);
          }
          *(undefined4 *)(this + 0x74) = 100;
        }
        else if (1000 < uVar1) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
            cVar9 = '\0';
          }
          bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar9 != '\0') || (bVar11)) {
            uVar8 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,uVar8,3,
                       in_stack_ffffffffffffff40,0xf,in_stack_ffffffffffffff50,uVar13,(char)uVar1,
                       0xe8);
          }
          *(undefined4 *)(this + 0x74) = 1000;
        }
      }
      local_88 = (**(code **)(WdfFunctions_01031 + 0xf8))(WdfDriverGlobals,param_5);
      local_80 = 0x58435348;
      lVar5 = HidSpiDeviceStateMachine<HidSpiDevice>::Initialize
                        ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,
                         (StateMachineEngineConfig *)&local_88);
      if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
        utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
      }
      return lVar5;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar9 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar9 = '\0';
    }
    bVar11 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar9 == '\0') && (!bVar11)) goto LAB_14000bc49;
    uVar13 = (undefined1)*(undefined8 *)(this + 0x68);
    uVar8 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    uVar12 = 0xd;
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,bVar11,uVar8,2,
             in_stack_ffffffffffffff40,uVar12,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
             uVar13,(char)lVar5);
LAB_14000bc49:
  if ((_RefCountBase *)param_3[1] != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong((_RefCountBase *)param_3[1]);
  }
  return lVar5;
}



===== NotifyingClientOfPowerDownEntry @ 14000beb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::NotifyingClientOfPowerDownEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::NotifyingClientOfPowerDownEntry(void *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffb0;
  
  Timer::Stop((Timer *)((longlong)param_1 + 0x18));
  cVar5 = '\x01';
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar4 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar4 != '\0') || (bVar6)) {
    uVar1 = *(undefined8 *)((longlong)param_1 + 0x68);
    uVar3 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar6,uVar3,4,
               in_stack_ffffffffffffffb0,0x25,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1);
  }
  iVar2 = (**(code **)(*(longlong *)((longlong)param_1 + 0x68) + 0x18))
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x68) + 0x38),
                     *(int *)((longlong)param_1 + 0xe0) == 2);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar5 != '\0') || (bVar6)) {
    uVar1 = *(undefined8 *)((longlong)param_1 + 0x68);
    uVar3 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar3,4,
               in_stack_ffffffffffffffb0,0x26,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1,(char)iVar2);
  }
  return (-1 < iVar2) + 7;
}



===== ReadyEntry @ 14000c040 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ReadyEntry(void * __ptr64) */

ushort __cdecl HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ReadyEntry(void *param_1)

{
  bool bVar1;
  HidSpiRequest *pHVar2;
  
  bVar1 = false;
  if (*(int *)((longlong)param_1 + 0x20) != 7) {
    *(undefined4 *)((longlong)param_1 + 0x20) = 0;
  }
  Lock::lock((Lock *)((longlong)param_1 + 0x10));
  if (*(longlong *)((longlong)param_1 + 0xb0) == 0) {
    pHVar2 = HidSpiRequestQueue::Dequeue(*(HidSpiRequestQueue **)((longlong)param_1 + 8));
    *(HidSpiRequest **)((longlong)param_1 + 0xb0) = pHVar2;
    if (pHVar2 == (HidSpiRequest *)0x0) {
      *(undefined1 *)((longlong)param_1 + 0x9d) = 1;
    }
    else {
      *(undefined1 *)((longlong)param_1 + 0x9d) = 0;
      bVar1 = true;
    }
  }
  Lock::unlock((Lock *)((longlong)param_1 + 0x10));
  if (bVar1) {
    EnqueueEvent(param_1,0xe);
  }
  return 0;
}



===== ReleasingBufferOnCancelPingPongsEntry @ 14000c0e0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ReleasingBufferOnCancelPingPongsEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ReleasingBufferOnCancelPingPongsEntry
          (void *param_1)

{
  if (*(longlong *)((longlong)param_1 + 0xb8) != 0) {
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)((longlong)param_1 + 0x28),
               *(void **)((longlong)param_1 + 0xc0));
    *(undefined8 *)((longlong)param_1 + 0xb8) = 0;
    *(undefined8 *)((longlong)param_1 + 0xc0) = 0;
  }
  return 8;
}



===== ResettingSyncEntry @ 14000c130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ResettingSyncEntry(void * __ptr64) */

ushort __cdecl HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ResettingSyncEntry(void *param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  int iVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  LOCK();
  *(int *)((longlong)param_1 + 0x78) = *(int *)((longlong)param_1 + 0x78) + 1;
  UNLOCK();
  iVar3 = (**(code **)(*(longlong *)((longlong)param_1 + 0x68) + 0x10))
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x68) + 0x38));
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar5 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x68);
      uVar4 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,
                 in_stack_ffffffffffffffd0,0x3c,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)iVar3);
    }
    *(undefined4 *)((longlong)param_1 + 0x20) = 0xe;
    uVar2 = 7;
  }
  else {
    Timer::Start((Timer *)((longlong)param_1 + 0x18),2000);
    uVar2 = 8;
  }
  return uVar2;
}



===== ReturningFailureOnPingPongTimeoutEntry @ 14000c240 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::ReturningFailureOnPingPongTimeoutEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::ReturningFailureOnPingPongTimeoutEntry
          (void *param_1)

{
  return 7;
}



===== StoppingResetTimerOnFailureEntry @ 14000c250 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::StoppingResetTimerOnFailureEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::StoppingResetTimerOnFailureEntry(void *param_1)

{
  return 8;
}



===== ReturningSuccessOnResetStopTimer @ 14000c260 =====

/* public: static enum SmFx::StopTimerResult __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::StopTimerOnExitDetails::ReturningSuccessOnResetStopTimer(void * __ptr64) */

StopTimerResult __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::StopTimerOnExitDetails::ReturningSuccessOnResetStopTimer
          (void *param_1)

{
  bool bVar1;
  
  bVar1 = Timer::Stop((Timer *)((longlong)param_1 + 0x18));
  return (bVar1 ^ 1) + 1;
}



===== SendingWriteToBusEntry @ 14000c290 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::SendingWriteToBusEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::SendingWriteToBusEntry(void *param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar3 = HidSpiCxReportInterface::WriteOutputReport
                    (*(HidSpiCxReportInterface **)((longlong)param_1 + 0x28),
                     *(_HIDSPICX_REPORT **)((longlong)param_1 + 200));
  if (lVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar1 = *(undefined8 *)((longlong)param_1 + 0x68);
      uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,
                 in_stack_ffffffffffffffd0,0x27,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)lVar3);
    }
    *(undefined4 *)((longlong)param_1 + 0x20) = 1;
    uVar2 = 7;
  }
  else {
    uVar2 = 8;
  }
  return uVar2;
}



===== SetDeviceFailed @ 14000c390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::SetDeviceFailed(void) __ptr64 */

Event __thiscall HidSpiDevice::SetDeviceFailed(HidSpiDevice *this)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  CxDevicePnpProblem CVar7;
  char cVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffb0;
  
  CVar7 = 1;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     (cVar8 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
    cVar8 = '\0';
  }
  bVar9 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar8 != '\0') || (puVar6 = WPP_GLOBAL_Control, bVar9)) {
    uVar1 = *(undefined4 *)(this + 0x20);
    uVar3 = *(undefined8 *)(this + 0x68);
    uVar4 = imp_WppRecorderLogGetDefault();
    puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_RECORDER_AND_TRACE_SF_qd
              (puVar6,cVar8,bVar9,uVar4,2,in_stack_ffffffffffffffb0,0x28,
               &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar3,(char)uVar1);
  }
  MicrosoftTelemetryAssertTriggeredArgsMsgKM
            (puVar6,CONCAT22(*(undefined2 *)(this + 0x54),*(undefined2 *)(this + 0x56)),
             *(undefined4 *)(this + 0x20),"Setting Device Failed");
  DbgPrintEx(0x65,0,"\nHIDSPICX Device being set as failed\n");
  (**(code **)(WdfFunctions_01031 + 0xb78))(WdfDriverGlobals);
  (**(code **)(WdfFunctions_01031 + 0x4d8))
            (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 0x68) + 0x40),0,0);
  CompletePendingTransferAndSetNotReady(this);
  (**(code **)(WdfFunctions_01031 + 0x528))(WdfDriverGlobals,**(undefined8 **)(this + 8),0,0);
  iVar2 = *(int *)(this + 0x20);
  if (iVar2 != 1) {
    if (iVar2 == 4) {
      CVar7 = 6;
      goto LAB_14000c51b;
    }
    if (iVar2 == 6) {
      CVar7 = 5;
      goto LAB_14000c51b;
    }
    if (iVar2 == 8) {
      CVar7 = 4;
      goto LAB_14000c51b;
    }
    if (iVar2 == 0xc) {
      CVar7 = 3;
      goto LAB_14000c51b;
    }
    if (iVar2 != 0xe) goto LAB_14000c51b;
  }
  CVar7 = 2;
LAB_14000c51b:
  uVar5 = Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline();
  CxDevice::SetDeviceFailed
            (*(CxDevice **)(this + 0x68),CVar7,
             (int)uVar5 != 0 && g_HidSpiCxDriverVerifierEnabled == false);
  return 8;
}



===== SetPowerDown @ 14000c584 =====

/* public: void __cdecl HidSpiDevice::SetPowerDown(enum HidSpiDevicePowerState,enum
   HidSpiDeviceNeedsResetOnPowerOn) __ptr64 */

void __thiscall
HidSpiDevice::SetPowerDown
          (HidSpiDevice *this,HidSpiDevicePowerState param_1,HidSpiDeviceNeedsResetOnPowerOn param_2
          )

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 in_stack_ffffffffffffffc0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qLL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffb0,0x13,in_stack_ffffffffffffffc0,(char)uVar1,(char)param_1,
               (char)param_2);
  }
  *(HidSpiDevicePowerState *)(this + 0xe0) = param_1;
  *(HidSpiDeviceNeedsResetOnPowerOn *)(this + 0xe4) = param_2;
  HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
            ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,9);
  return;
}



===== SetPowerOn @ 14000c668 =====

/* public: void __cdecl HidSpiDevice::SetPowerOn(void) __ptr64 */

void __thiscall HidSpiDevice::SetPowerOn(HidSpiDevice *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x68);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x12,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
               (char)uVar1);
  }
  *(undefined4 *)(this + 0xe0) = 1;
  HidSpiDeviceStateMachine<HidSpiDevice>::EnqueueEvent
            ((HidSpiDeviceStateMachine<HidSpiDevice> *)this,10);
  return;
}



===== SettingDeviceFailedEntry @ 14000c740 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::SettingDeviceFailedEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::SettingDeviceFailedEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::SetDeviceFailed(param_1);
  return (ushort)EVar1;
}



===== StartPingPongReads @ 14000c758 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::StartPingPongReads(void) __ptr64 */

Event __thiscall HidSpiDevice::StartPingPongReads(HidSpiDevice *this)

{
  undefined8 uVar1;
  long lVar2;
  Event EVar3;
  undefined8 uVar4;
  char cVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar2 = HidSpiCxReportInterface::StartReadPump
                    (*(HidSpiCxReportInterface **)(this + 0x28),*(__uint64 *)(this + 0xd8));
  if (lVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar5 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar5 != '\0') || (bVar6)) {
      uVar1 = *(undefined8 *)(this + 0x68);
      uVar4 = imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,bVar6,uVar4,2,
                 in_stack_ffffffffffffffd0,0x50,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar1,(char)lVar2);
    }
    EVar3 = 7;
  }
  else {
    EVar3 = 8;
  }
  return EVar3;
}



===== StartingDescriptorResponseTimerEntry @ 14000c850 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::StartingDescriptorResponseTimerEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::StartingDescriptorResponseTimerEntry
          (void *param_1)

{
  Timer::Start((Timer *)((longlong)param_1 + 0x18),2000);
  return 8;
}



===== StartingPingPongsAfterDescriptorEntry @ 14000c880 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::StartingPingPongsAfterDescriptorEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::StartingPingPongsAfterDescriptorEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::StartPingPongReads(param_1);
  return (ushort)EVar1;
}



===== VerifyAndCompleteTransfer @ 14000c898 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::VerifyAndCompleteTransfer(void) __ptr64 */

Event __thiscall HidSpiDevice::VerifyAndCompleteTransfer(HidSpiDevice *this)

{
  char cVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  longlong lVar7;
  ulonglong uVar8;
  void *_Dst;
  HidSpiRequest *this_00;
  undefined *puVar9;
  Event EVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  long lVar14;
  undefined8 in_RDX;
  char cVar15;
  bool bVar16;
  bool bVar17;
  undefined1 in_stack_ffffffffffffff88;
  undefined7 in_stack_ffffffffffffff89;
  undefined8 in_stack_ffffffffffffff90;
  undefined2 uVar18;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar19;
  
  puVar9 = WPP_RECORDER_INITIALIZED;
  lVar14 = (long)in_RDX;
  pcVar6 = *(char **)(this + 0xb8);
  cVar15 = *pcVar6;
  if (cVar15 == '\x03') {
    sVar3 = *(short *)(pcVar6 + 1);
    if (sVar3 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar15 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar15 = '\0';
      }
      bVar16 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar15 != '\0') || (bVar16)) {
        uVar12 = *(undefined8 *)(this + 0x68);
        uVar11 = imp_WppRecorderLogGetDefault();
        lVar14 = (long)CONCAT71((int7)((ulonglong)in_RDX >> 8),cVar15);
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar15,bVar16,uVar11,3,
                   in_stack_ffffffffffffff90,0x2a,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                   (char)uVar12);
      }
      LOCK();
      *(int *)(this + 0x7c) = *(int *)(this + 0x7c) + 1;
      UNLOCK();
      HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::EvtDeviceReset
                (*(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)(this + 0x38),lVar14);
      HidSpiCxReportInterface::ReleaseReportBuffer
                (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
      EVar10 = 3;
      goto LAB_14000d289;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar15 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar15 = '\0';
    }
    bVar16 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar15 != '\0') || (bVar16)) {
      uVar12 = *(undefined8 *)(this + 0x68);
      uVar11 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar15,bVar16,uVar11,
                 CONCAT71(in_stack_ffffffffffffff89,in_stack_ffffffffffffff88),
                 in_stack_ffffffffffffff90,0x29,in_stack_ffffffffffffffa0,(char)uVar12,(char)sVar3);
    }
    *(undefined4 *)(this + 0x20) = 5;
  }
  else {
    lVar7 = *(longlong *)(this + 0xb0);
    if (lVar7 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (bVar16 = true, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        bVar16 = false;
      }
      if ((bVar16 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
         ) {
        uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
        uVar12 = imp_WppRecorderLogGetDefault();
        uVar18 = 0x2b;
LAB_14000ca8f:
        WPP_RECORDER_AND_TRACE_SF_qD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,
                   (undefined **)puVar9 != &WPP_RECORDER_INITIALIZED,uVar12,
                   CONCAT71(in_stack_ffffffffffffff89,in_stack_ffffffffffffff88),
                   in_stack_ffffffffffffff90,uVar18,in_stack_ffffffffffffffa0,uVar19,cVar15);
      }
    }
    else {
      iVar5 = *(int *)(lVar7 + 0x48);
      cVar1 = *(char *)(lVar7 + 0x4c);
      uVar4 = 0;
      bVar16 = true;
      if (iVar5 == 2) {
        if (cVar15 == '\x05') {
          cVar2 = pcVar6[3];
          if (cVar2 == cVar1) goto LAB_14000cdc6;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar16 = false;
          }
          bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((bVar16) || (bVar17)) {
            uVar12 = *(undefined8 *)(this + 0x68);
            uVar11 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qDD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar11,
                       CONCAT71(in_stack_ffffffffffffff89,in_stack_ffffffffffffff88),
                       in_stack_ffffffffffffff90,0x2d,in_stack_ffffffffffffffa0,(char)uVar12,cVar2,
                       cVar1);
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            bVar16 = false;
          }
          if ((bVar16 != false) ||
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
            uVar12 = imp_WppRecorderLogGetDefault();
            uVar18 = 0x2c;
            goto LAB_14000ca8f;
          }
        }
      }
      else if (iVar5 == 1) {
        if (cVar15 == '\b') {
LAB_14000cdc6:
          if (pcVar6[3] == cVar1) {
            if ((byte)(cVar15 - 9U) < 2) {
              if (*(short *)(pcVar6 + 1) == 0) {
LAB_14000d053:
                HidSpiCxReportInterface::ReleaseReportBuffer
                          (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
                *(undefined8 *)(this + 0xb8) = 0;
                *(undefined8 *)(this + 0xc0) = 0;
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
                  bVar16 = false;
                }
                bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((bVar16 != false) || (bVar17)) {
                  uVar12 = *(undefined8 *)(this + 0xb0);
                  uVar11 = *(undefined8 *)(this + 0x68);
                  uVar13 = imp_WppRecorderLogGetDefault();
                  WPP_RECORDER_AND_TRACE_SF_qq
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar13,4,
                             in_stack_ffffffffffffff90,0x37,
                             &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar11,
                             (char)uVar12);
                }
                (**(code **)(WdfFunctions_01031 + 0x898))
                          (WdfDriverGlobals,**(undefined8 **)(this + 0xb0),uVar4);
                this_00 = *(HidSpiRequest **)(this + 0xb0);
                *(undefined8 *)(this + 0xb0) = 0;
                HidSpiRequest::Complete(this_00,0);
                return 8;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar16 = false;
              }
              bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((bVar16 != false) || (bVar17)) {
                uVar12 = *(undefined8 *)(this + 0x68);
                uVar11 = imp_WppRecorderLogGetDefault();
                WPP_RECORDER_AND_TRACE_SF_qd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar11,2,
                           in_stack_ffffffffffffff90,0x34,
                           &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar12,(char)iVar5
                          );
              }
            }
            else {
              if (((cVar15 != '\x05') && (cVar15 != '\v')) ||
                 (*(ushort *)(pcVar6 + 1) <= *(ushort *)(this + 0x4e))) {
                uVar8 = *(ulonglong *)(lVar7 + 0x40);
                uVar4 = *(ushort *)(pcVar6 + 1);
                _Dst = *(void **)(lVar7 + 0x38);
                if (uVar4 <= uVar8) {
                  LOCK();
                  *(int *)(this + 0x8c) = *(int *)(this + 0x8c) + 1;
                  UNLOCK();
                  LOCK();
                  *(int *)(this + 0x90) = *(int *)(this + 0x90) + 1;
                  UNLOCK();
                  uVar4 = *(ushort *)(*(longlong *)(this + 0xb8) + 1);
                  memcpy(_Dst,(void *)(*(longlong *)(this + 0xb8) + 4),(ulonglong)uVar4);
                  goto LAB_14000d053;
                }
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                  bVar16 = false;
                }
                bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
                if ((bVar16 != false) || (bVar17)) {
                  uVar12 = *(undefined8 *)(this + 0x68);
                  uVar11 = imp_WppRecorderLogGetDefault();
                  WPP_RECORDER_AND_TRACE_SF_qPP
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar11,2,
                             in_stack_ffffffffffffff90,0x36,
                             &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar12,
                             (char)uVar8,(char)uVar4);
                }
                (**(code **)(WdfFunctions_01031 + 0x898))
                          (WdfDriverGlobals,**(undefined8 **)(this + 0xb0),0);
                HidSpiRequest::Complete(*(HidSpiRequest **)(this + 0xb0),-0x3fffffdd);
                *(undefined8 *)(this + 0xb0) = 0;
                HidSpiCxReportInterface::ReleaseReportBuffer
                          (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
                EVar10 = 8;
                goto LAB_14000d289;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                bVar16 = false;
              }
              bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((bVar16 != false) || (bVar17)) {
                uVar12 = imp_WppRecorderLogGetDefault();
                WPP_RECORDER_AND_TRACE_SF_qPDL
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar12);
              }
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              bVar16 = false;
            }
            bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((bVar16 != false) || (bVar17)) {
              uVar12 = imp_WppRecorderLogGetDefault();
              WPP_RECORDER_AND_TRACE_SF_qddL
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar12);
            }
          }
          *(undefined4 *)(this + 0x20) = 5;
          goto LAB_14000d274;
        }
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar16 = false;
        }
        if ((bVar16 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
          uVar12 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x2e;
          goto LAB_14000ca8f;
        }
      }
      else if (iVar5 == 3) {
        if (cVar15 == '\t') goto LAB_14000cdc6;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar16 = false;
        }
        if ((bVar16 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
          uVar12 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x2f;
          goto LAB_14000ca8f;
        }
      }
      else if (iVar5 == 4) {
        if (cVar15 == '\n') goto LAB_14000cdc6;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar16 = false;
        }
        if ((bVar16 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
          uVar12 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x30;
          goto LAB_14000ca8f;
        }
      }
      else if (iVar5 == 5) {
        if (cVar15 == '\v') goto LAB_14000cdc6;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar16 = false;
        }
        if ((bVar16 != false) ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar19 = (undefined1)*(undefined8 *)(this + 0x68);
          uVar12 = imp_WppRecorderLogGetDefault();
          uVar18 = 0x31;
          goto LAB_14000ca8f;
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          bVar16 = false;
        }
        bVar17 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((bVar16 != false) || (bVar17)) {
          uVar12 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qDL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar16,bVar17,uVar12);
        }
      }
    }
    *(undefined4 *)(this + 0x20) = 0xd;
  }
LAB_14000d274:
  HidSpiCxReportInterface::ReleaseReportBuffer
            (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
  EVar10 = 7;
LAB_14000d289:
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  return EVar10;
}



===== VerifyDescriptorCompletion @ 14000d2b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::VerifyDescriptorCompletion(void) __ptr64 */

Event __thiscall HidSpiDevice::VerifyDescriptorCompletion(HidSpiDevice *this)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined *puVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  longlong lVar15;
  char cVar16;
  char cVar17;
  bool bVar18;
  undefined1 in_stack_ffffffffffffff78;
  undefined7 in_stack_ffffffffffffff79;
  undefined8 in_stack_ffffffffffffff80;
  undefined2 uVar19;
  undefined8 in_stack_ffffffffffffff90;
  undefined1 uVar20;
  
  puVar11 = WPP_RECORDER_INITIALIZED;
  pcVar7 = *(char **)(this + 0xb8);
  cVar17 = *pcVar7;
  if (cVar17 != '\a') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar16 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar16 = '\0';
    }
    bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar16 != '\0') || (bVar18)) {
      uVar14 = *(undefined8 *)(this + 0x68);
      uVar13 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,bVar18,uVar13,
                 CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                 in_stack_ffffffffffffff80,0x19,in_stack_ffffffffffffff90,(char)uVar14,cVar17);
    }
    *(undefined4 *)(this + 0x20) = 8;
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
    *(undefined8 *)(this + 0xb8) = 0;
    *(undefined8 *)(this + 0xc0) = 0;
    return 5;
  }
  sVar1 = *(short *)(pcVar7 + 1);
  if (sVar1 == 0x18) {
    sVar1 = *(short *)(pcVar7 + 4);
    if (sVar1 == 0x18) {
      sVar1 = *(short *)(pcVar7 + 6);
      if (sVar1 != 0x300) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar17 = '\0';
        }
        bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
        if ((cVar17 != '\0') || (bVar18)) {
          uVar14 = *(undefined8 *)(this + 0x68);
          uVar13 = imp_WppRecorderLogGetDefault();
          WPP_RECORDER_AND_TRACE_SF_qDD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,
                     CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                     in_stack_ffffffffffffff80,0x1c,in_stack_ffffffffffffff90,(char)uVar14,0,
                     (char)sVar1);
        }
        *(undefined4 *)(this + 0x20) = 9;
        goto LAB_14000d447;
      }
      if (*(short *)(pcVar7 + 8) == 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar17 = '\0';
        }
        if ((cVar17 != '\0') ||
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar20 = (undefined1)*(undefined8 *)(this + 0x68);
          uVar14 = imp_WppRecorderLogGetDefault();
          uVar19 = 0x1d;
LAB_14000d623:
          WPP_RECORDER_AND_TRACE_SF_q
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,
                     (undefined **)puVar11 != &WPP_RECORDER_INITIALIZED,uVar14,2,
                     in_stack_ffffffffffffff80,uVar19,
                     &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,uVar20);
        }
      }
      else {
        uVar2 = *(ushort *)(pcVar7 + 0xe);
        if ((uVar2 & 3) == 0) {
          uVar3 = *(ushort *)(pcVar7 + 10);
          if ((ulonglong)uVar3 + 4 < (ulonglong)uVar2) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar17 = '\0';
            }
            bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
            if ((cVar17 != '\0') || (bVar18)) {
              uVar14 = *(undefined8 *)(this + 0x68);
              uVar13 = imp_WppRecorderLogGetDefault();
              WPP_RECORDER_AND_TRACE_SF_qDD
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,
                         CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                         in_stack_ffffffffffffff80,0x1f,in_stack_ffffffffffffff90,(char)uVar14,
                         (char)uVar2,(char)uVar3);
            }
          }
          else {
            if (((uVar2 != 0) && (uVar3 != 0)) || (uVar2 == uVar3)) {
              uVar8 = *(undefined4 *)(pcVar7 + 8);
              uVar9 = *(undefined4 *)(pcVar7 + 0xc);
              uVar10 = *(undefined4 *)(pcVar7 + 0x10);
              cVar17 = '\x01';
              *(undefined4 *)(this + 0x48) = *(undefined4 *)(pcVar7 + 4);
              *(undefined4 *)(this + 0x4c) = uVar8;
              *(undefined4 *)(this + 0x50) = uVar9;
              *(undefined4 *)(this + 0x54) = uVar10;
              *(undefined8 *)(this + 0x58) = *(undefined8 *)(pcVar7 + 0x14);
              this[0x60] = (HidSpiDevice)0x1;
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 (cVar16 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
                cVar16 = '\0';
              }
              bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((cVar16 != '\0') || (bVar18)) {
                uVar19 = *(undefined2 *)(this + 0x58);
                uVar4 = *(undefined2 *)(this + 0x56);
                uVar5 = *(undefined2 *)(this + 0x54);
                uVar6 = *(undefined2 *)(this + 0x4a);
                uVar14 = *(undefined8 *)(this + 0x68);
                uVar13 = imp_WppRecorderLogGetDefault();
                WPP_RECORDER_AND_TRACE_SF_qDDDD
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar16,bVar18,uVar13,
                           CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                           in_stack_ffffffffffffff80,0x21,
                           &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar14,(char)uVar6
                           ,(char)uVar5,(char)uVar4,(char)uVar19);
              }
              HidSpiCxReportInterface::ReleaseReportBuffer
                        (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
              *(undefined8 *)(this + 0xb8) = 0;
              *(undefined8 *)(this + 0xc0) = 0;
              ExFreePoolWithTag(*(undefined8 *)(this + 200),0x58435348);
              uVar2 = *(ushort *)(this + 0x4e);
              *(undefined8 *)(this + 200) = 0;
              if (uVar2 < *(ushort *)(this + 0x4c)) {
                uVar2 = *(ushort *)(this + 0x4c);
              }
              uVar12 = (uint)uVar2;
              if ((uVar2 & 3) != 0) {
                uVar12 = (uVar12 - (uVar12 & 3)) + 4;
              }
              *(longlong *)(this + 0xd8) = (longlong)(int)uVar12 + 4;
              lVar15 = (ulonglong)*(ushort *)(this + 0x50) + 4;
              if (*(ushort *)(this + 0x50) == 0) {
                lVar15 = 5;
              }
              *(longlong *)(this + 0xd0) = lVar15;
              lVar15 = ExAllocatePool2(0x40,lVar15,0x58435348);
              *(longlong *)(this + 200) = lVar15;
              if (lVar15 != 0) {
                (**(code **)(WdfFunctions_01031 + 0x4d0))
                          (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 0x68) + 0x40));
                return 8;
              }
              if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
                cVar17 = '\0';
              }
              bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
              if ((cVar17 != '\0') || (bVar18)) {
                uVar14 = *(undefined8 *)(this + 0x68);
                uVar13 = imp_WppRecorderLogGetDefault();
                WPP_RECORDER_AND_TRACE_SF_q
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,2,
                           in_stack_ffffffffffffff80,0x22,
                           &WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,(char)uVar14);
              }
              *(undefined4 *)(this + 0x20) = 4;
              return 7;
            }
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
              cVar17 = '\0';
            }
            if ((cVar17 != '\0') ||
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar20 = (undefined1)*(undefined8 *)(this + 0x68);
              uVar14 = imp_WppRecorderLogGetDefault();
              uVar19 = 0x20;
              goto LAB_14000d623;
            }
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar17 = '\0';
          }
          bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
          if ((cVar17 != '\0') || (bVar18)) {
            uVar14 = *(undefined8 *)(this + 0x68);
            uVar13 = imp_WppRecorderLogGetDefault();
            WPP_RECORDER_AND_TRACE_SF_qD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,
                       CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                       in_stack_ffffffffffffff80,0x1e,in_stack_ffffffffffffff90,(char)uVar14,
                       (char)uVar2);
          }
        }
      }
      *(undefined4 *)(this + 0x20) = 10;
      goto LAB_14000d447;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar17 = '\0';
    }
    bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar17 != '\0') || (bVar18)) {
      uVar14 = *(undefined8 *)(this + 0x68);
      uVar13 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qPD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,
                 CONCAT71(in_stack_ffffffffffffff79,in_stack_ffffffffffffff78),
                 in_stack_ffffffffffffff80,0x1b,in_stack_ffffffffffffff90,(char)uVar14,0x18,
                 (char)sVar1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar17 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar17 = '\0';
    }
    bVar18 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar17 != '\0') || (bVar18)) {
      uVar14 = *(undefined8 *)(this + 0x68);
      uVar13 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar17,bVar18,uVar13,2,
                 in_stack_ffffffffffffff80,0x1a,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar14,0x18,(char)sVar1);
    }
  }
  *(undefined4 *)(this + 0x20) = 3;
LAB_14000d447:
  HidSpiCxReportInterface::ReleaseReportBuffer
            (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  return 7;
}



===== VerifyPowerCompletion @ 14000da5c =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::VerifyPowerCompletion(void) __ptr64 */

Event __thiscall HidSpiDevice::VerifyPowerCompletion(HidSpiDevice *this)

{
  byte bVar1;
  char *pcVar2;
  undefined *puVar3;
  Event EVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  char cVar8;
  ushort uVar9;
  bool bVar10;
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  undefined8 in_stack_ffffffffffffffb0;
  undefined2 uVar11;
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar12;
  
  puVar3 = WPP_RECORDER_INITIALIZED;
  pcVar2 = *(char **)(this + 0xb8);
  if (*pcVar2 != '\x04') {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar8 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar8 = '\0';
    }
    bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar8 != '\0') || (bVar10)) {
      uVar6 = *(undefined8 *)(this + 0x68);
      uVar5 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar8,bVar10,uVar5,2,
                 in_stack_ffffffffffffffb0,0x41,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar6);
    }
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
    EVar4 = 5;
    goto LAB_14000dcf3;
  }
  uVar9 = *(ushort *)(pcVar2 + 1);
  bVar10 = true;
  if (uVar9 == 1) {
    cVar8 = pcVar2[3];
    if (cVar8 == '\x01') {
      bVar1 = pcVar2[4];
      if (bVar1 == 1) {
        HidSpiCxReportInterface::ReleaseReportBuffer
                  (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
        EVar4 = 8;
        goto LAB_14000dcf3;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar10 = false;
      }
      if ((bVar10 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
         ) {
        uVar12 = (undefined1)*(undefined8 *)(this + 0x68);
        uVar6 = imp_WppRecorderLogGetDefault();
        uVar9 = (ushort)bVar1;
        uVar11 = 0x44;
        goto LAB_14000dba1;
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
      }
      bVar10 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar7 != '\0') || (bVar10)) {
        uVar6 = *(undefined8 *)(this + 0x68);
        uVar5 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,bVar10,uVar5,
                   CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
                   in_stack_ffffffffffffffb0,0x43,in_stack_ffffffffffffffc0,(char)uVar6,cVar8,1);
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar10 = false;
    }
    if ((bVar10) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar12 = (undefined1)*(undefined8 *)(this + 0x68);
      uVar6 = imp_WppRecorderLogGetDefault();
      uVar11 = 0x42;
LAB_14000dba1:
      WPP_RECORDER_AND_TRACE_SF_qD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar10,
                 (undefined **)puVar3 != &WPP_RECORDER_INITIALIZED,uVar6,
                 CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
                 in_stack_ffffffffffffffb0,uVar11,in_stack_ffffffffffffffc0,uVar12,(char)uVar9);
    }
  }
  HidSpiCxReportInterface::ReleaseReportBuffer
            (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
  EVar4 = 7;
LAB_14000dcf3:
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  return EVar4;
}



===== VerifyResetResponse @ 14000dd24 =====

/* private: enum HidSpiDeviceStateMachine<class HidSpiDevice>::Event __cdecl
   HidSpiDevice::VerifyResetResponse(void) __ptr64 */

Event __thiscall HidSpiDevice::VerifyResetResponse(HidSpiDevice *this)

{
  short sVar1;
  undefined8 uVar2;
  Event EVar3;
  undefined8 uVar4;
  void *pvVar5;
  char cVar6;
  bool bVar7;
  undefined1 in_stack_ffffffffffffffb8;
  undefined7 in_stack_ffffffffffffffb9;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  if (**(char **)(this + 0xb8) == '\x03') {
    sVar1 = *(short *)(*(char **)(this + 0xb8) + 1);
    if (sVar1 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar6 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
        cVar6 = '\0';
      }
      bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar6 != '\0') || (bVar7)) {
        uVar2 = *(undefined8 *)(this + 0x68);
        uVar4 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar4,3,
                   in_stack_ffffffffffffffc0,0x47,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                   (char)uVar2);
      }
      LOCK();
      *(int *)(this + 0x7c) = *(int *)(this + 0x7c) + 1;
      UNLOCK();
      pvVar5 = *(void **)(this + 0xc0);
      HidSpiCxReportInterface::ReleaseReportBuffer
                (*(HidSpiCxReportInterface **)(this + 0x28),pvVar5);
      *(undefined8 *)(this + 0xb8) = 0;
      *(undefined8 *)(this + 0xc0) = 0;
      HidClassMinidriver<HidSpiRequestManager,HidSpiRequest>::EvtDeviceReset
                (*(HidClassMinidriver<HidSpiRequestManager,HidSpiRequest> **)(this + 0x38),
                 (long)pvVar5);
      EVar3 = 8;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (cVar6 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
        cVar6 = '\0';
      }
      bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
      if ((cVar6 != '\0') || (bVar7)) {
        uVar2 = *(undefined8 *)(this + 0x68);
        uVar4 = imp_WppRecorderLogGetDefault();
        WPP_RECORDER_AND_TRACE_SF_qD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar4,
                   CONCAT71(in_stack_ffffffffffffffb9,in_stack_ffffffffffffffb8),
                   in_stack_ffffffffffffffc0,0x46,in_stack_ffffffffffffffd0,(char)uVar2,(char)sVar1)
        ;
      }
      *(undefined4 *)(this + 0x20) = 5;
      HidSpiCxReportInterface::ReleaseReportBuffer
                (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
      *(undefined8 *)(this + 0xb8) = 0;
      EVar3 = 7;
      *(undefined8 *)(this + 0xc0) = 0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar6 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar6 != '\0') || (bVar7)) {
      uVar2 = *(undefined8 *)(this + 0x68);
      uVar4 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,bVar7,uVar4,2,
                 in_stack_ffffffffffffffc0,0x45,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,
                 (char)uVar2);
    }
    HidSpiCxReportInterface::ReleaseReportBuffer
              (*(HidSpiCxReportInterface **)(this + 0x28),*(void **)(this + 0xc0));
    *(undefined8 *)(this + 0xb8) = 0;
    EVar3 = 5;
    *(undefined8 *)(this + 0xc0) = 0;
  }
  return EVar3;
}



===== VerifyingAndCompletingTransferEntry @ 14000dfa0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::VerifyingAndCompletingTransferEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::VerifyingAndCompletingTransferEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::VerifyAndCompleteTransfer(param_1);
  return (ushort)EVar1;
}



===== VerifyingDescriptorCompletionEntry @ 14000dfc0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::VerifyingDescriptorCompletionEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::VerifyingDescriptorCompletionEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::VerifyDescriptorCompletion(param_1);
  return (ushort)EVar1;
}



===== VerifyingPowerOnResponseEntry @ 14000dfe0 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::VerifyingPowerOnResponseEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::VerifyingPowerOnResponseEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::VerifyPowerCompletion(param_1);
  return (ushort)EVar1;
}



===== VerifyingResetResponseEntry @ 14000e000 =====

/* public: static unsigned short __cdecl HidSpiDeviceStateMachine<class
   HidSpiDevice>::EntryFuncs::VerifyingResetResponseEntry(void * __ptr64) */

ushort __cdecl
HidSpiDeviceStateMachine<HidSpiDevice>::EntryFuncs::VerifyingResetResponseEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = HidSpiDevice::VerifyResetResponse(param_1);
  return (ushort)EVar1;
}



===== WPP_RECORDER_AND_TRACE_SF_qD @ 14000e018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
               &param_10,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
                    &param_10,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDD @ 14000e0ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
                    &param_10,4,&param_11,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDDd @ 14000e1e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDDd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x4d,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x4d,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDL @ 14000e2f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDL(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x32,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x32,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLL @ 14000e3f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLL
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined1 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,param_5,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,
                    &param_9,8,&param_10,4,&param_11,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLLLL @ 14000e4ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLLLL
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x3a,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x3a,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLLLLLLLLL @ 14000e628 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLLLLLLLLL
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x15,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
               &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
               &uStack0000000000000090,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x15,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                    &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                    &uStack0000000000000090,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPD @ 14000e81c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPD
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined2 param_7,undefined8 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
               &param_10,8,&param_11,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,param_7,&param_9,8,
                    &param_10,8,&param_11,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPDL @ 14000e914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPDL(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x35,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x35,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qdP @ 14000ea2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qdP(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x4b,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x4b,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0)
    ;
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qddL @ 14000eb24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qddL(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x33,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x33,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLLL @ 14000ec38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLLL
               (undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x38,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x38,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqPD @ 14000ed78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqPD(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x23,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,2,1,&WPP_ff32bd6c7fb53d0c17d2de63259091d6_Traceguids,0x23,
                    &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,8,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== Complete @ 14000ee8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiRequest::Complete(long) __ptr64 */

void __thiscall HidSpiRequest::Complete(HidSpiRequest *this,long param_1)

{
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,*(undefined8 *)this,param_1);
  return;
}



===== CreateRequestFromWdfRequest @ 14000eebc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl HidSpiRequest::CreateRequestFromWdfRequest(struct WDFREQUEST__ *
   __ptr64,class HidSpiRequest * __ptr64 * __ptr64) */

long __cdecl
HidSpiRequest::CreateRequestFromWdfRequest(WDFREQUEST__ *param_1,HidSpiRequest **param_2)

{
  int iVar1;
  HidSpiRequest *local_res18 [2];
  ulonglong local_48 [6];
  undefined *local_18;
  
  local_res18[0] = (HidSpiRequest *)0x0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_48[0] = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_48[0] = 0xffffffff;
  }
  else {
    local_48[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  local_48[3] = 0x100000001;
  local_18 = PTR__WDF_HidSpiRequest_TYPE_INFO_140017068;
  iVar1 = (**(code **)(WdfFunctions_01031 + 0x658))(WdfDriverGlobals,param_1,local_48,local_res18);
  if (-1 < iVar1) {
    *param_2 = local_res18[0];
    *(undefined8 *)(local_res18[0] + 8) = 0;
    *(undefined8 *)(local_res18[0] + 0x10) = 0;
    *(undefined8 *)(local_res18[0] + 0x18) = 0;
    *(undefined8 *)(local_res18[0] + 0x20) = 0;
    *(undefined8 *)(local_res18[0] + 0x28) = 0;
    *(undefined8 *)(local_res18[0] + 0x30) = 0;
    *(undefined8 *)(local_res18[0] + 0x38) = 0;
    *(undefined8 *)(local_res18[0] + 0x40) = 0;
    *(WDFREQUEST__ **)local_res18[0] = param_1;
    iVar1 = 0;
  }
  return iVar1;
}



===== ~lambda_call<<lambda_161f2748ff1ff1f71933cab8c395b34a>_> @ 14000efac =====

void wil::details::lambda_call<<lambda_161f2748ff1ff1f71933cab8c395b34a>_>::
     ~lambda_call<<lambda_161f2748ff1ff1f71933cab8c395b34a>_>(longlong *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((char)param_1[3] != '\0') {
    *(undefined1 *)(param_1 + 3) = 0;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar4 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar4 = '\0';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar5)) {
      uVar1 = *(undefined4 *)param_1[1];
      uVar2 = *(undefined8 *)(*param_1 + 0x10);
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,uVar3,4,
                 in_stack_ffffffffffffffd0,0xe,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
                 (char)uVar2,(char)uVar1);
    }
    HidSpiRequest::Complete(*(HidSpiRequest **)param_1[2],*(long *)param_1[1]);
  }
  return;
}



===== ~lambda_call<<lambda_bbd3c177d81c83c7cff6bed423221029>_> @ 14000f0a0 =====

void wil::details::lambda_call<<lambda_bbd3c177d81c83c7cff6bed423221029>_>::
     ~lambda_call<<lambda_bbd3c177d81c83c7cff6bed423221029>_>(longlong *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  bool bVar5;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((char)param_1[3] != '\0') {
    *(undefined1 *)(param_1 + 3) = 0;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        (cVar4 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar4 = '\0';
    }
    bVar5 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
    if ((cVar4 != '\0') || (bVar5)) {
      uVar1 = *(undefined4 *)param_1[1];
      uVar2 = *(undefined8 *)(*param_1 + 0x10);
      uVar3 = imp_WppRecorderLogGetDefault();
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,bVar5,uVar3,4,
                 in_stack_ffffffffffffffd0,10,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
                 (char)uVar2,(char)uVar1);
    }
    HidSpiRequest::Complete(*(HidSpiRequest **)param_1[2],*(long *)param_1[1]);
  }
  return;
}



===== operator() @ 14000f194 =====

void <lambda_43ac193a86c380d7f6c16c98a638408c>::operator()(longlong param_1)

{
  undefined8 uVar1;
  char cVar2;
  bool bVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar2 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  bVar3 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar2 != '\0') || (bVar3)) {
    uVar1 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,bVar3,uVar1);
  }
  HidSpiRequest::Complete
            ((HidSpiRequest *)**(undefined8 **)(param_1 + 0x20),**(long **)(param_1 + 0x18));
  return;
}



===== HidActivateDevice @ 14000f280 =====

/* public: void __cdecl HidSpiRequestManager::HidActivateDevice(class HidSpiRequest *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
HidSpiRequestManager::HidActivateDevice
          (HidSpiRequestManager *this,HidSpiRequest *param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x10);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x12,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar1);
  }
  HidSpiRequest::Complete(param_1,-0x3fffff45);
  return;
}



===== HidDeactivateDevice @ 14000f34c =====

/* public: void __cdecl HidSpiRequestManager::HidDeactivateDevice(class HidSpiRequest *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
HidSpiRequestManager::HidDeactivateDevice
          (HidSpiRequestManager *this,HidSpiRequest *param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x10);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x13,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar1);
  }
  HidSpiRequest::Complete(param_1,-0x3fffff45);
  return;
}



===== HidGetDeviceDescriptor @ 14000f418 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiRequestManager::HidGetDeviceDescriptor(class HidSpiRequest * __ptr64)
   __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetDeviceDescriptor(HidSpiRequestManager *this,HidSpiRequest *param_1)

{
  undefined4 *puVar1;
  undefined4 local_res8 [2];
  HidSpiRequest *local_res10 [3];
  HidSpiRequestManager *local_28;
  undefined4 *local_20;
  HidSpiRequest **local_18;
  undefined1 local_10;
  
  local_20 = local_res8;
  local_res8[0] = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  local_18 = local_res10;
  local_10 = 1;
  local_res10[0] = param_1;
  local_28 = this;
  if (*(ulonglong *)(param_1 + 0x20) < 9) {
    local_res8[0] = 0xc0000206;
  }
  else if (*(char *)(*(longlong *)this + 0x60) == '\0') {
    local_res8[0] = 0xc00000a3;
  }
  else {
    *(undefined2 *)((longlong)puVar1 + 7) = *(undefined2 *)(*(longlong *)this + 0x4c);
    *puVar1 = 0x12109;
    *(undefined2 *)(puVar1 + 1) = 0x100;
    *(undefined1 *)((longlong)puVar1 + 6) = 0x22;
    (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,*(undefined8 *)param_1,9);
  }
  wil::details::lambda_call<<lambda_bbd3c177d81c83c7cff6bed423221029>_>::
  ~lambda_call<<lambda_bbd3c177d81c83c7cff6bed423221029>_>((longlong *)&local_28);
  return;
}



===== HidGetFeature @ 14000f4c8 =====

/* public: void __cdecl HidSpiRequestManager::HidGetFeature(class HidSpiRequest * __ptr64,struct
   _HID_XFER_PACKET * __ptr64) __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetFeature
          (HidSpiRequestManager *this,HidSpiRequest *param_1,_HID_XFER_PACKET *param_2)

{
  HidSpiRequest HVar1;
  _HID_XFER_PACKET _Var2;
  HidSpiRequest *pHVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffc0;
  
  *(undefined4 *)(param_1 + 0x48) = 2;
  HVar1 = *(HidSpiRequest *)(param_2 + 0xc);
  bVar5 = true;
  param_1[0x4c] = HVar1;
  if (HVar1 != (HidSpiRequest)0x0) {
    pHVar3 = *(HidSpiRequest **)param_2;
    *pHVar3 = HVar1;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
    *(HidSpiRequest **)param_2 = pHVar3 + 1;
  }
  *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)param_2;
  *(ulonglong *)(param_1 + 0x40) = (ulonglong)*(uint *)(param_2 + 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar5 = false;
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((bVar5) || (bVar7)) {
    _Var2 = param_2[0xc];
    uVar4 = *(undefined8 *)(this + 0x10);
    uVar6 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,bVar7,uVar6,4,
               in_stack_ffffffffffffffc0,0x10,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar4,_Var2);
  }
  HidSpiDevice::Dispatch(*(HidSpiDevice **)this,param_1);
  return;
}



===== HidGetIndexedString @ 14000f5d8 =====

/* public: void __cdecl HidSpiRequestManager::HidGetIndexedString(class HidSpiRequest *
   __ptr64,unsigned long,unsigned long) __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetIndexedString
          (HidSpiRequestManager *this,HidSpiRequest *param_1,ulong param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar3 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((cVar3 != '\0') || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x10);
    uVar2 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,bVar4,uVar2,4,
               in_stack_ffffffffffffffd0,0x14,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar1);
  }
  HidSpiRequest::Complete(param_1,-0x3fffff45);
  return;
}



===== HidGetInputReport @ 14000f6a4 =====

/* public: void __cdecl HidSpiRequestManager::HidGetInputReport(class HidSpiRequest * __ptr64,struct
   _HID_XFER_PACKET * __ptr64) __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetInputReport
          (HidSpiRequestManager *this,HidSpiRequest *param_1,_HID_XFER_PACKET *param_2)

{
  HidSpiRequest HVar1;
  _HID_XFER_PACKET _Var2;
  HidSpiRequest *pHVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffc0;
  
  *(undefined4 *)(param_1 + 0x48) = 5;
  HVar1 = *(HidSpiRequest *)(param_2 + 0xc);
  bVar5 = true;
  param_1[0x4c] = HVar1;
  if (HVar1 != (HidSpiRequest)0x0) {
    pHVar3 = *(HidSpiRequest **)param_2;
    *pHVar3 = HVar1;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
    *(HidSpiRequest **)param_2 = pHVar3 + 1;
  }
  *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)param_2;
  *(ulonglong *)(param_1 + 0x40) = (ulonglong)*(uint *)(param_2 + 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar5 = false;
  }
  bVar7 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((bVar5) || (bVar7)) {
    _Var2 = param_2[0xc];
    uVar4 = *(undefined8 *)(this + 0x10);
    uVar6 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar5,bVar7,uVar6,4,
               in_stack_ffffffffffffffc0,0x11,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar4,_Var2);
  }
  HidSpiDevice::Dispatch(*(HidSpiDevice **)this,param_1);
  return;
}



===== HidGetReportDescriptor @ 14000f7b4 =====

/* public: void __cdecl HidSpiRequestManager::HidGetReportDescriptor(class HidSpiRequest * __ptr64)
   __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetReportDescriptor(HidSpiRequestManager *this,HidSpiRequest *param_1)

{
  undefined8 uVar1;
  bool bVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  bVar2 = true;
  param_1[0x4c] = (HidSpiRequest)0x0;
  *(undefined4 *)(param_1 + 0x48) = 1;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar2 = false;
  }
  bVar4 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((bVar2) || (bVar4)) {
    uVar1 = *(undefined8 *)(this + 0x10);
    uVar3 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar2,bVar4,uVar3,4,
               in_stack_ffffffffffffffd0,0xb,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar1);
  }
  HidSpiDevice::Dispatch(*(HidSpiDevice **)this,param_1);
  return;
}



===== HidGetString @ 14000f894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl HidSpiRequestManager::HidGetString(class HidSpiRequest * __ptr64,unsigned
   long,unsigned long) __ptr64 */

void __thiscall
HidSpiRequestManager::HidGetString
          (HidSpiRequestManager *this,HidSpiRequest *param_1,ulong param_2,ulong param_3)

{
  wchar_t *_Src;
  ulonglong _Size;
  undefined4 local_res8 [2];
  HidSpiRequest *local_res10;
  ulong local_res18 [2];
  ulong local_res20 [2];
  HidSpiRequestManager *local_48;
  ulong *local_40;
  ulong *local_38;
  undefined4 *local_30;
  HidSpiRequest **local_28;
  undefined1 local_20;
  
  local_res8[0] = 0;
  local_40 = local_res18;
  local_38 = local_res20;
  local_30 = local_res8;
  local_28 = &local_res10;
  local_res10 = param_1;
  local_res18[0] = param_2;
  local_res20[0] = param_3;
  local_48 = this;
  if (param_3 == 0xe) {
    _Src = L"Microsoft";
    _Size = 0x14;
  }
  else if (param_3 == 0xf) {
    _Src = L"HIDSPI Device";
    _Size = 0x1c;
  }
  else {
    if (param_3 != 0x10) {
      local_res8[0] = 0xc000000d;
      goto LAB_14000f959;
    }
    _Src = L"9999";
    _Size = 10;
  }
  if (*(ulonglong *)(param_1 + 0x20) < _Size) {
    local_res8[0] = 0xc0000206;
  }
  else {
    memcpy(*(void **)(param_1 + 0x18),_Src,_Size);
    (**(code **)(WdfFunctions_01031 + 0x898))(WdfDriverGlobals,*(undefined8 *)local_res10,_Size);
  }
LAB_14000f959:
  local_20 = 0;
  <lambda_43ac193a86c380d7f6c16c98a638408c>::operator()((longlong)&local_48);
  return;
}



===== HidSetFeature @ 14000f974 =====

/* public: void __cdecl HidSpiRequestManager::HidSetFeature(class HidSpiRequest * __ptr64,struct
   _HID_XFER_PACKET * __ptr64) __ptr64 */

void __thiscall
HidSpiRequestManager::HidSetFeature
          (HidSpiRequestManager *this,HidSpiRequest *param_1,_HID_XFER_PACKET *param_2)

{
  HidSpiRequest HVar1;
  _HID_XFER_PACKET _Var2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffc0;
  
  HVar1 = *(HidSpiRequest *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x48) = 3;
  param_1[0x4c] = HVar1;
  bVar4 = true;
  if (HVar1 != (HidSpiRequest)0x0) {
    *(longlong *)param_2 = *(longlong *)param_2 + 1;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
  }
  *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)param_2;
  *(ulonglong *)(param_1 + 0x30) = (ulonglong)*(uint *)(param_2 + 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar4 = false;
  }
  bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((bVar4) || (bVar6)) {
    _Var2 = param_2[0xc];
    uVar3 = *(undefined8 *)(this + 0x10);
    uVar5 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,bVar6,uVar5,4,
               in_stack_ffffffffffffffc0,0xf,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar3,_Var2);
  }
  HidSpiDevice::Dispatch(*(HidSpiDevice **)this,param_1);
  return;
}



===== HidWriteReport @ 14000fa7c =====

/* public: void __cdecl HidSpiRequestManager::HidWriteReport(class HidSpiRequest * __ptr64,struct
   _HID_XFER_PACKET * __ptr64) __ptr64 */

void __thiscall
HidSpiRequestManager::HidWriteReport
          (HidSpiRequestManager *this,HidSpiRequest *param_1,_HID_XFER_PACKET *param_2)

{
  HidSpiRequest HVar1;
  _HID_XFER_PACKET _Var2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined8 in_stack_ffffffffffffffc0;
  
  HVar1 = *(HidSpiRequest *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x48) = 4;
  param_1[0x4c] = HVar1;
  bVar4 = true;
  if (HVar1 != (HidSpiRequest)0x0) {
    *(longlong *)param_2 = *(longlong *)param_2 + 1;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;
  }
  *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)param_2;
  *(ulonglong *)(param_1 + 0x30) = (ulonglong)*(uint *)(param_2 + 8);
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    bVar4 = false;
  }
  bVar6 = (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED;
  if ((bVar4) || (bVar6)) {
    _Var2 = param_2[0xc];
    uVar3 = *(undefined8 *)(this + 0x10);
    uVar5 = imp_WppRecorderLogGetDefault();
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar4,bVar6,uVar5,4,
               in_stack_ffffffffffffffc0,0xc,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,
               (char)uVar3,_Var2);
  }
  HidSpiDevice::Dispatch(*(HidSpiDevice **)this,param_1);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLLd @ 14000fb84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLLd(undefined8 param_1,char param_2,char param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,0xd,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  if (param_3 != '\0') {
    WppAutoLogTrace(param_4,4,1,&WPP_d5f0c7ab87213ed013f4c7d603a1e7b4_Traceguids,0xd,
                    &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                    &uStack0000000000000060,4,0);
  }
  return;
}



===== ~Lock @ 14000fc98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl Lock::~Lock(void) __ptr64 */

void __thiscall Lock::~Lock(Lock *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)this = 0;
  }
  return;
}



===== Dequeue @ 14000fcd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class HidSpiRequest * __ptr64 __cdecl HidSpiRequestQueue::Dequeue(void) __ptr64 */

HidSpiRequest * __thiscall HidSpiRequestQueue::Dequeue(HidSpiRequestQueue *this)

{
  int iVar1;
  HidSpiRequest *pHVar2;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01031 + 0x4f0))(WdfDriverGlobals,*(undefined8 *)this,local_res8)
  ;
  if (iVar1 < 0) {
    pHVar2 = (HidSpiRequest *)0x0;
  }
  else {
    pHVar2 = (HidSpiRequest *)
             (**(code **)(WdfFunctions_01031 + 0x650))
                       (WdfDriverGlobals,local_res8[0],PTR__WDF_HidSpiRequest_TYPE_INFO_140017068);
  }
  return pHVar2;
}



===== Initialize @ 14000fd3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl Lock::Initialize(struct WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall Lock::Initialize(Lock *this,WDFDEVICE__ *param_1)

{
  long lVar1;
  ulonglong local_48 [4];
  WDFDEVICE__ *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_48[1] = 0;
  local_18 = 0;
  local_48[2] = 0;
  uStack_20 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_48[0] = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_48[0] = 0xffffffff;
  }
  else {
    local_48[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  local_48[3] = 0x100000001;
  local_28 = param_1;
  lVar1 = (**(code **)(WdfFunctions_01031 + 0x9d8))(WdfDriverGlobals,local_48,this);
  return lVar1;
}



===== lock @ 14000fdcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl Lock::lock(void) __ptr64 */

void __thiscall Lock::lock(Lock *this)

{
  (**(code **)(WdfFunctions_01031 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)this);
  return;
}



===== unlock @ 14000fdfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl Lock::unlock(void) __ptr64 */

void __thiscall Lock::unlock(Lock *this)

{
  (**(code **)(WdfFunctions_01031 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)this);
  return;
}



===== ~Timer @ 14000fe2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl Timer::~Timer(void) __ptr64 */

void __thiscall Timer::~Timer(Timer *this)

{
  if (*(longlong *)this != 0) {
    Stop(this);
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*(undefined8 *)this);
    *(undefined8 *)this = 0;
  }
  return;
}



===== EvtTimerFired @ 14000fe70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl Timer::EvtTimerFired(struct WDFTIMER__ * __ptr64) */

void __cdecl Timer::EvtTimerFired(WDFTIMER__ *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01031 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_TimerContext_TYPE_INFO_140017108);
  (*(code *)puVar1[1])(*puVar1);
  return;
}



===== Initialize @ 14000feb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl Timer::Initialize(struct WDFDEVICE__ * __ptr64,void (__cdecl*)(void *
   __ptr64),void * __ptr64) __ptr64 */

long __thiscall
Timer::Initialize(Timer *this,WDFDEVICE__ *param_1,_func_void_void_ptr *param_2,void *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  ulonglong local_68;
  code *pcStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  WDFDEVICE__ *local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_48 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_68 = 0x28;
  }
  else if (WdfStructureCount < 0x38) {
    local_68 = 0xffffffff;
  }
  else {
    local_68 = (ulonglong)*(uint *)(WdfStructures + 0x1b8);
  }
  uStack_50 = 0;
  local_2c = 0;
  local_18 = 0;
  pcStack_60 = EvtTimerFired;
  local_58 = 0;
  local_3c = 0;
  uStack_34 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_40 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_40 = 0xffffffff;
  }
  else {
    local_40 = *(undefined4 *)(WdfStructures + 0x130);
  }
  local_28 = 1;
  local_24 = 1;
  local_10 = PTR__WDF_TimerContext_TYPE_INFO_140017108;
  local_20 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01031 + 0x9f0))(WdfDriverGlobals,&local_68,&local_40,this);
  if (iVar1 < 0) {
    *(undefined8 *)this = 0;
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01031 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)this,
                        PTR__WDF_TimerContext_TYPE_INFO_140017108);
    *puVar2 = param_3;
    puVar2[1] = HidSpiDevice::EvtTimerFired;
    iVar1 = 0;
  }
  return iVar1;
}



===== Start @ 140010004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl Timer::Start(unsigned long) __ptr64 */

void __thiscall Timer::Start(Timer *this,ulong param_1)

{
  (**(code **)(WdfFunctions_01031 + 0x9f8))
            (WdfDriverGlobals,*(undefined8 *)this,(ulonglong)param_1 * -10000);
  return;
}



===== Stop @ 14001003c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl Timer::Stop(void) __ptr64 */

bool __thiscall Timer::Stop(Timer *this)

{
  char cVar1;
  
  cVar1 = (**(code **)(WdfFunctions_01031 + 0xa00))(WdfDriverGlobals,*(undefined8 *)this,0);
  return cVar1 != '\0';
}



===== FxStubDriverUnloadCommon @ 140010074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140017258 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140017258 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_140017258 == 0x78) {
      ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140017258 + 0x78);
    }
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1400100e4:
      if (ppvVar1 == (void **)0x0) goto LAB_14001013d;
      if (ppvVar2 <= ppvVar1) goto LAB_140010155;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_140017130,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&DAT_140017130,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if (((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) ||
       ((ppvVar1 + 0xf <= ppvVar2 && (*(uint *)ppvVar1 == 0x78)))) goto LAB_1400100e4;
LAB_14001013d:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_140010155:
  WdfVersionUnbind(&DAT_1400173b0,&DAT_140017130,WdfDriverGlobals);
  return;
}



===== entry @ 140010190 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400101c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  int iVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    iVar1 = DriverEntry((_DRIVER_OBJECT *)0x0,param_2);
  }
  else {
    _DAT_1400173b0 = 0x2080000;
    _DAT_1400173b8 = &DAT_1400173e0;
    RtlCopyUnicodeString(&DAT_1400173b0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1400173b0,&DAT_140017130,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1400175e8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1400173b0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140017258 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_140017130,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 140010350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1400175e8 != (code *)0x0) && (DAT_1400175e8 != FxStubDriverUnload)) {
    (*DAT_1400175e8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140010384 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400103a9) */
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
    if ((void **)0x14001724f < ppvVar2) break;
    if ((((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) &&
        ((&__KMDF_CLASS_BIND_END < ppvVar2 + 0xf || (*(uint *)ppvVar2 != 0x78)))) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140017258 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_140017130,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&DAT_140017130,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((longlong)ppvVar2 + (ulonglong)*(uint *)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 140010518 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140010535) */
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
    if ((void **)0x14001726f < ppvVar2) break;
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



===== <lambda_invoker_cdecl> @ 1400105e0 =====

void <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>
               (StateMachineEngineImpl *param_1)

{
  StateMachineEngineImpl *pSVar1;
  int iVar2;
  StateMachineEngineImpl SVar3;
  EngineState EVar4;
  ulonglong uVar5;
  
  pSVar1 = param_1 + 1000;
  SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  param_1[0x3f1] = SVar3;
  iVar2 = *(int *)(param_1 + 0x3e0);
  *(undefined4 *)(param_1 + 0x3e0) = 2;
  KeReleaseSpinLock(pSVar1,param_1[0x3f1]);
  *(undefined2 *)(param_1 + 0x3d6) = 1;
  *(void **)(param_1 + 0x3d8) = SystemReserved1[0xf];
  if (iVar2 == 3) {
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3c0));
    uVar5 = Feature_SMST__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      *(undefined8 *)(param_1 + 0x3c0) = 0;
      *(undefined8 *)(param_1 + 0x3c8) = 0;
      EVar4 = SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
      SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
      param_1[0x3f1] = SVar3;
      if (EVar4 != 1) {
        SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(param_1,EVar4);
        return;
      }
      goto LAB_1400106d8;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(param_1);
  }
  else {
    if (iVar2 != 4) {
      return;
    }
    SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
              (param_1,(EVENT_ACTION *)(param_1 + 0x3c0));
    *(undefined8 *)(param_1 + 0x3c0) = 0;
    *(undefined8 *)(param_1 + 0x3c8) = 0;
  }
  SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  param_1[0x3f1] = SVar3;
LAB_1400106d8:
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(param_1);
  return;
}



===== ~StateMachineEngineImpl @ 1400106f4 =====

/* private: __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::~StateMachineEngineImpl
          (StateMachineEngineImpl *this)

{
  Worker *this_00;
  StateMachineEngineImpl SVar1;
  
  **(undefined8 **)(this + 0x418) = 0;
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
  this[0x3f1] = SVar1;
  *(undefined4 *)(this + 0x3e0) = 0;
  KeReleaseSpinLock(this + 1000,this[0x3f1]);
  this_00 = (Worker *)(this + 0x3f8);
  if (*(longlong *)this_00 != 0) {
    IoFreeWorkItem();
    *(undefined8 *)this_00 = 0;
    *(undefined8 *)(this + 0x400) = 0;
    *(undefined8 *)(this + 0x408) = 0;
    *(undefined8 *)(this + 0x410) = 0;
  }
  if (*(longlong *)(this + 0x368) != 0) {
    ExFreePool();
    *(undefined8 *)(this + 0x368) = 0;
  }
  this[0x3f0] = (StateMachineEngineImpl)0x0;
  Worker::~Worker(this_00);
  this[0x3f0] = (StateMachineEngineImpl)0x0;
  return;
}



===== AddEventToEventQueue @ 1400107b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue(unsigned short) __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::AddEventToEventQueue
          (StateMachineEngineImpl *this,ushort param_1)

{
  bool bVar1;
  undefined2 uVar2;
  StateMachineEngineImpl SVar3;
  
  SVar3 = (StateMachineEngineImpl)((char)this[0x3d3] + 1U & 0xf);
  if (SVar3 == this[0x3d2]) {
    ReportExceptionWithLockHeld(this,2,param_1,0);
    bVar1 = false;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d3] * 2 + 0x340) = param_1;
    uVar2 = 0;
    this[0x3d3] = SVar3;
    if (*(code **)(this + 0x3a0) != (code *)0x0) {
      if (param_1 != 0) {
        uVar2 = *(undefined2 *)
                 (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_1 * 4);
      }
      (**(code **)(this + 0x3a0))(*(undefined8 *)(this + 0x380),uVar2);
    }
    bVar1 = true;
  }
  return bVar1;
}



===== Destroy @ 140010840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(void) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Destroy(StateMachineEngineImpl *this)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(code **)(this + 0x3b0);
  uVar2 = *(undefined8 *)(this + 0x380);
  ~StateMachineEngineImpl(this);
  ExFreePool(this);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(uVar2);
  }
  return;
}



===== EnqueueEventWithDisposition @ 14001089c =====

/* private: bool __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition(unsigned short)
   __ptr64 */

bool __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::EnqueueEventWithDisposition
          (StateMachineEngineImpl *this,ushort param_1)

{
  char cVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined6 in_register_00000012;
  ulonglong uVar4;
  undefined7 uVar5;
  StateMachineEngineImpl SVar6;
  
  uVar4 = CONCAT62(in_register_00000012,param_1);
  cVar1 = *(char *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + 2 + (ulonglong)param_1 * 4);
  if (cVar1 != '\x01') {
    uVar5 = (undefined7)(uVar4 >> 8);
    if (cVar1 == '\x02') {
      SVar6 = this[0x3d2];
      uVar4 = CONCAT71(uVar5,SVar6);
      bVar2 = false;
      if (SVar6 != this[0x3d3]) {
        do {
          if (*(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340) == param_1) {
            bVar2 = true;
          }
          else {
            uVar3 = (ulonglong)(byte)SVar6;
            SVar6 = (StateMachineEngineImpl)((char)SVar6 + 1U & 0xf);
            *(ushort *)(this + uVar3 * 2 + 0x340) = *(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340);
          }
          uVar4 = CONCAT71((int7)(uVar4 >> 8),(char)uVar4 + '\x01') & 0xffffffffffffff0f;
        } while (SUB81(uVar4,0) != this[0x3d3]);
        if (bVar2) {
          *(ushort *)(this + (ulonglong)((byte)((char)this[0x3d3] - 1) & 0xf) * 2 + 0x340) = param_1
          ;
          goto LAB_140010962;
        }
      }
    }
    else {
      if (cVar1 != '\x03') {
LAB_140010962:
        KeReleaseSpinLock(this + 1000,CONCAT71((int7)(uVar4 >> 8),this[0x3f1]));
        return false;
      }
      for (uVar4 = CONCAT71(uVar5,this[0x3d2]); SUB81(uVar4,0) != this[0x3d3];
          uVar4 = CONCAT71((int7)(uVar4 >> 8),(char)SUB81(uVar4,0) + '\x01') & 0xffffffffffffff0f) {
        if (*(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340) == param_1) goto LAB_140010962;
      }
    }
  }
  bVar2 = AddEventToEventQueue(this,param_1);
  return bVar2;
}



===== ExecuteCurrentState @ 140010988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(void) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteCurrentState(StateMachineEngineImpl *this)

{
  ushort *puVar1;
  StateMachineEngineImpl SVar2;
  ushort uVar3;
  ushort uVar4;
  EngineState EVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  EVENT_ACTION *pEVar9;
  StateMachineEngineImpl SVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  do {
    uVar3 = 0;
    if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
      uVar3 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = *(longlong *)(this + 0x378);
    lVar11 = (ulonglong)uVar3 * 0x10 + *(longlong *)(lVar6 + 0x18);
    if ((*(byte *)(lVar11 + 4) & 1) == 0) {
      if (*(char *)(lVar11 + 3) == '\x01') {
        uVar12 = (ulonglong)*(ushort *)(lVar6 + 2);
      }
      else {
        uVar12 = 0;
      }
    }
    else {
      uVar3 = (*(code *)**(undefined8 **)(lVar11 + 8))(*(undefined8 *)(this + 0x380));
      lVar6 = *(longlong *)(this + 0x378);
      uVar12 = (ulonglong)uVar3;
    }
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (ulonglong)
               *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = uVar13 * 0x10 + *(longlong *)(lVar6 + 0x18);
    uVar3 = *(ushort *)(lVar6 + 4);
    if ((uVar3 & 0x20) != 0) {
      uVar4 = 1;
      uVar8 = 0;
      do {
        uVar7 = (ulonglong)((int)uVar8 + 1);
        if ((uVar3 & uVar4) != uVar4) {
          uVar7 = uVar8;
        }
        uVar4 = uVar4 * 2;
        uVar8 = uVar7;
      } while (uVar4 != 0x20);
      puVar1 = *(ushort **)(*(longlong *)(lVar6 + 8) + uVar7 * 8);
      if (puVar1 != (ushort *)0x0) {
        SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
        this[0x3f1] = SVar2;
        SVar2 = this[0x3d2];
        SVar10 = SVar2;
        if (SVar2 != this[0x3d3]) {
          do {
            lVar6 = 0;
            uVar3 = *(ushort *)(this + (ulonglong)(byte)SVar10 * 2 + 0x340);
            uVar4 = *puVar1;
            while (uVar4 != 0) {
              if (uVar4 == uVar3) {
                LogTransition(this,7,(ushort)uVar13,uVar3,0,(char)this[0x3d4] + 0xff);
                goto LAB_140010aeb;
              }
              lVar6 = lVar6 + 1;
              uVar4 = puVar1[lVar6];
            }
            uVar8 = (ulonglong)(byte)SVar2;
            SVar2 = (StateMachineEngineImpl)((char)SVar2 + 1U & 0xf);
            *(ushort *)(this + uVar8 * 2 + 0x340) = uVar3;
LAB_140010aeb:
            SVar10 = (StateMachineEngineImpl)((char)SVar10 + 1U & 0xf);
          } while (SVar10 != this[0x3d3]);
        }
        this[0x3d3] = SVar2;
        KeReleaseSpinLock(this + 1000,this[0x3f1]);
      }
    }
    if (*(char *)(lVar11 + 3) == '\x01') {
      local_38 = 0;
      uStack_30 = 0;
      FindActionForEvent(this,(ushort)uVar12,(EVENT_ACTION *)&local_38);
      pEVar9 = (EVENT_ACTION *)&local_38;
    }
    else {
      if (*(char *)(lVar11 + 3) != '\x03') {
        return 1;
      }
      local_48 = 6;
      local_40 = *(longlong *)(*(longlong *)(this + 0x378) + 8) +
                 (ulonglong)*(byte *)(lVar11 + 6) * 2;
      pEVar9 = (EVENT_ACTION *)&local_48;
    }
    EVar5 = ExecuteEventAction(this,pEVar9);
    if (EVar5 != 2) {
      return EVar5;
    }
  } while( true );
}



===== ExecuteEventAction @ 140010bd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExecuteEventAction
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  byte bVar2;
  undefined8 uVar3;
  EngineState EVar4;
  MachineException MVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  undefined8 local_28;
  longlong lStack_20;
  
  iVar7 = *(int *)param_1;
  if (iVar7 == 1) {
    uVar8 = 0;
    if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
      uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    uVar6 = *(ushort *)(param_1 + 4);
    MVar5 = 1;
LAB_140010fc9:
    ReportException(this,MVar5,uVar6,uVar8);
    return 1;
  }
  if (iVar7 == 2) {
    EVar4 = PopToStackDepth(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    EVar4 = ExitCurrentState(this,param_1);
    if (EVar4 != 1) {
      return EVar4;
    }
    uVar8 = *(ushort *)(*(longlong *)(param_1 + 8) + 2);
    bVar2 = *(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 +
                     (ulonglong)uVar8 * 0x10);
    if ((((bVar2 & 2) == 0) || (this[0x3d6] != (StateMachineEngineImpl)0x0)) &&
       (((bVar2 & 1) == 0 || (this[0x3d7] == (StateMachineEngineImpl)0x0)))) {
      if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,1,uVar6,*(ushort *)(param_1 + 4),uVar8,(uchar)param_1[6]);
      *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = uVar8;
LAB_140010f90:
      this[0x3d5] = (StateMachineEngineImpl)0x0;
      return 2;
    }
    EVar4 = 3;
  }
  else {
    if (iVar7 != 3) {
      if (iVar7 == 4) {
        local_28 = *(undefined8 *)param_1;
        lStack_20 = *(longlong *)(param_1 + 8);
        do {
          EVar4 = PopToStackDepth(this,(EVENT_ACTION *)&local_28);
          if (EVar4 != 1) {
            return EVar4;
          }
          EVar4 = ExitCurrentState(this,(EVENT_ACTION *)&local_28);
          if (EVar4 != 1) {
            return EVar4;
          }
          SVar1 = this[0x3d4];
          if ((byte)SVar1 < 2) {
            uVar8 = 0;
            uVar6 = 0;
            if (SVar1 != (StateMachineEngineImpl)0x0) goto LAB_140010d4c;
          }
          else {
            uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
LAB_140010d4c:
            uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
          }
          LogTransition(this,3,uVar6,local_28._4_2_,uVar8,local_28._6_1_);
          *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = 0;
          SVar1 = this[0x3d4];
          this[0x3d4] = (StateMachineEngineImpl)((char)SVar1 + -1);
          this[0x3d5] = (StateMachineEngineImpl)0x0;
          FindActionForEvent(this,*(ushort *)(lStack_20 + 2),(EVENT_ACTION *)&local_28);
          if ((int)local_28 != 4) {
            if ((StateMachineEngineImpl)((char)SVar1 + -1) == (StateMachineEngineImpl)0x0) {
              return 1;
            }
            iVar7 = (int)local_28;
            if ((int)local_28 == 5) {
              iVar7 = 1;
            }
            local_28 = CONCAT44(local_28._4_4_,iVar7);
            EVar4 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
            return EVar4;
          }
        } while( true );
      }
      if (iVar7 == 5) {
        return 1;
      }
      if (iVar7 != 6) {
        return 1;
      }
      SVar1 = this[0x3d4];
      if (SVar1 == (StateMachineEngineImpl)0x0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
      }
      if (SVar1 != this[0x360]) {
        uVar6 = **(ushort **)(param_1 + 8);
        bVar2 = *(byte *)(*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + 2 +
                         (ulonglong)uVar6 * 0x10);
        if ((((bVar2 & 2) != 0) && (this[0x3d6] == (StateMachineEngineImpl)0x0)) ||
           (((bVar2 & 1) != 0 && (this[0x3d7] != (StateMachineEngineImpl)0x0)))) {
          uVar3 = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
          *(undefined8 *)(this + 0x3c8) = uVar3;
          return 3;
        }
        LogTransition(this,5,uVar8,0,uVar6,(uchar)SVar1);
        *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)this[0x3d4] * 2) = uVar6;
        this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + '\x01');
        goto LAB_140010f90;
      }
      uVar6 = 0;
      MVar5 = 3;
      goto LAB_140010fc9;
    }
    uVar8 = 0;
    if (*(longlong *)(*(longlong *)(param_1 + 8) + 8) == 0) {
      if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,6,uVar8,*(ushort *)(param_1 + 4),
                    *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                    (uchar)param_1[6]);
      return 1;
    }
    bVar2 = *(byte *)(*(longlong *)(param_1 + 8) + 2);
    if ((((bVar2 & 2) == 0) || (this[0x3d6] != (StateMachineEngineImpl)0x0)) &&
       (((bVar2 & 1) == 0 || (this[0x3d7] == (StateMachineEngineImpl)0x0)))) {
      if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,2,uVar8,*(ushort *)(param_1 + 4),
                    *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)param_1[6] * 2),
                    (uchar)param_1[6]);
      (**(code **)(*(longlong *)(param_1 + 8) + 8))(*(undefined8 *)(this + 0x380));
      return 1;
    }
    EVar4 = 4;
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x3c8) = uVar3;
  return EVar4;
}



===== ExitCurrentState @ 140010ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ExitCurrentState
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  short *psVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  ushort uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ushort uVar8;
  
  if (this[0x3d5] == (StateMachineEngineImpl)0x0) {
    this[0x3d5] = (StateMachineEngineImpl)0x1;
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    lVar6 = (ulonglong)uVar5 * 0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
    uVar5 = *(ushort *)(lVar6 + 4);
    if ((uVar5 & 0x40) != 0) {
      uVar8 = 1;
      uVar7 = 0;
      do {
        uVar4 = (ulonglong)((int)uVar7 + 1);
        if ((uVar5 & uVar8) != uVar8) {
          uVar4 = uVar7;
        }
        uVar8 = uVar8 * 2;
        uVar7 = uVar4;
      } while (uVar8 != 0x40);
      psVar1 = *(short **)(*(longlong *)(lVar6 + 8) + uVar4 * 8);
      if (((psVar1 != (short *)0x0) && (*(short *)(param_1 + 4) != *psVar1)) &&
         (iVar3 = (**(code **)(psVar1 + 4))(*(undefined8 *)(this + 0x380)), iVar3 != 1)) {
        uVar2 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(this + 0x3c0) = *(undefined8 *)param_1;
        *(undefined8 *)(this + 0x3c8) = uVar2;
        *(short *)(this + 0x370) = *psVar1;
        return 5;
      }
    }
  }
  return 1;
}



===== FindActionForEvent @ 1400110f4 =====

/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent(unsigned short,struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION * __ptr64) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::FindActionForEvent
          (StateMachineEngineImpl *this,ushort param_1,EVENT_ACTION *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  StateMachineEngineImpl SVar7;
  uint uVar8;
  longlong lVar9;
  
  SVar7 = this[0x3d4];
  *(ushort *)(param_2 + 4) = param_1;
  if (SVar7 == (StateMachineEngineImpl)0x0) {
    *(undefined4 *)param_2 = 1;
    param_2[6] = (EVENT_ACTION)0xff;
  }
  else {
    do {
      SVar7 = (StateMachineEngineImpl)((char)SVar7 + -1);
      lVar9 = (ulonglong)*(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)SVar7 * 2) *
              0x10 + *(longlong *)(*(longlong *)(this + 0x378) + 0x18);
      param_2[6] = (EVENT_ACTION)0xff;
      uVar4 = *(ushort *)(lVar9 + 4);
      uVar6 = (ulonglong)(uVar4 & 1);
      if ((uVar4 & 2) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 2;
              goto LAB_14001127a;
            }
            uVar5 = (ulonglong)((int)uVar5 + 1);
            puVar2 = puVar1 + uVar5 * 2;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((uVar4 & 1) + 1);
      }
      if ((uVar4 & 4) != 0) {
        uVar8 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        if (uVar3 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar3 == param_1) {
              *(undefined4 *)param_2 = 3;
              goto LAB_14001127a;
            }
            uVar8 = uVar8 + 1;
            puVar2 = puVar1 + (ulonglong)uVar8 * 8;
            uVar3 = *puVar2;
          } while (uVar3 != 0);
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 8) != 0) {
        uVar5 = 0;
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar3 = *puVar1;
        while (uVar3 != 0) {
          if (uVar3 == param_1) {
            *(undefined4 *)param_2 = 5;
            goto LAB_14001127e;
          }
          uVar5 = (ulonglong)((int)uVar5 + 1);
          uVar3 = puVar1[uVar5];
        }
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
      if ((uVar4 & 0x10) != 0) {
        puVar1 = *(ushort **)(*(longlong *)(lVar9 + 8) + uVar6 * 8);
        uVar6 = 0;
        uVar4 = *puVar1;
        if (uVar4 != 0) {
          puVar2 = puVar1;
          do {
            if (uVar4 == param_1) {
              *(undefined4 *)param_2 = 4;
LAB_14001127a:
              *(ushort **)(param_2 + 8) = puVar2;
LAB_14001127e:
              *(StateMachineEngineImpl *)(param_2 + 6) = SVar7;
              return;
            }
            uVar6 = (ulonglong)((int)uVar6 + 1);
            puVar2 = puVar1 + uVar6 * 2;
            uVar4 = *puVar2;
          } while (uVar4 != 0);
        }
      }
      *(undefined4 *)param_2 = 1;
    } while ((*(char *)(lVar9 + 3) != '\x01') && (SVar7 != (StateMachineEngineImpl)0x0));
  }
  return;
}



===== Initialize @ 1400112a4 =====

/* private: long __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize
          (StateMachineEngineImpl *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  longlong lVar6;
  StateMachineEngineImpl SVar7;
  int iVar8;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x378) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x380) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x388) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 0x390) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(this + 0x398) = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x3a0) = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  uVar3 = *(undefined4 *)(param_1 + 0x38);
  uVar4 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x3ac) = uVar2;
  *(undefined4 *)(this + 0x3b0) = uVar3;
  *(undefined4 *)(this + 0x3b4) = uVar4;
  *(undefined8 *)(this + 0x3b8) = *(undefined8 *)(param_1 + 0x40);
  if (this[0x3f0] == (StateMachineEngineImpl)0x0) {
    KeInitializeSpinLock(this + 1000);
    this[0x3f0] = (StateMachineEngineImpl)0x1;
  }
  SVar7 = (StateMachineEngineImpl)0x10;
  if (this[0x3b9] != (StateMachineEngineImpl)0x0) {
    SVar7 = this[0x3b9];
  }
  this[0x360] = SVar7;
  iVar8 = 0x78466d53;
  if (*(int *)(this + 0x390) != 0) {
    iVar8 = *(int *)(this + 0x390);
  }
  lVar6 = ExAllocatePool2(0x40,(ulonglong)(byte)SVar7 * 2,iVar8);
  *(longlong *)(this + 0x368) = lVar6;
  if (lVar6 == 0) {
LAB_14001135d:
    lVar5 = -0x3fffff66;
  }
  else {
    if (this[0x3b8] != (StateMachineEngineImpl)0x0) {
      uVar1 = *(undefined8 *)(param_1 + 0x10);
      if (*(longlong *)(this + 0x3f8) != 0) {
        return -0x3ffffe7c;
      }
      lVar6 = IoAllocateWorkItem(uVar1);
      *(longlong *)(this + 0x3f8) = lVar6;
      if (lVar6 == 0) goto LAB_14001135d;
      *(undefined8 *)(this + 0x400) = uVar1;
      *(code **)(this + 0x408) = <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>;
      *(StateMachineEngineImpl **)(this + 0x410) = this;
    }
    InitiateFirstRun(this);
    lVar5 = 0;
  }
  return lVar5;
}



===== InitiateFirstRun @ 1400113dc =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::InitiateFirstRun(StateMachineEngineImpl *this)

{
  StateMachineEngineImpl *pSVar1;
  StateMachineEngineImpl SVar2;
  EngineState EVar3;
  undefined4 local_18;
  undefined4 local_14;
  longlong local_10;
  
  pSVar1 = this + 1000;
  SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  this[0x3f1] = SVar2;
  *(undefined4 *)(this + 0x3e0) = 2;
  KeReleaseSpinLock(pSVar1,this[0x3f1]);
  this[0x3d7] = SVar2;
  this[0x3d6] = (StateMachineEngineImpl)0x0;
  if ((byte)SVar2 < 2) {
    *(void **)(this + 0x3d8) = SystemReserved1[0xf];
  }
  else {
    *(undefined4 *)(this + 0x3d8) = SystemReserved1[0x12]._4_4_;
  }
  local_14 = 0;
  local_18 = 6;
  local_10 = *(longlong *)(*(byte **)(this + 0x378) + 8) + (ulonglong)**(byte **)(this + 0x378) * 2;
  EVar3 = ExecuteEventAction(this,(EVENT_ACTION *)&local_18);
  if (EVar3 == 2) {
    EVar3 = ExecuteCurrentState(this);
  }
  SVar2 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(pSVar1);
  this[0x3f1] = SVar2;
  if (EVar3 == 1) {
    ProcessEventQueue(this);
  }
  else {
    UpdateEngineState(this,EVar3);
  }
  return;
}



===== LogTransition @ 1400114d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition(enum
   SmFx::TransitionType,unsigned short,unsigned short,unsigned short,unsigned char) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::LogTransition
          (StateMachineEngineImpl *this,TransitionType param_1,ushort param_2,ushort param_3,
          ushort param_4,uchar param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  *(TransitionType *)(this + (ulonglong)(byte)this[0x3d0] * 0xc) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 4) = param_3;
  if ((param_1 - 2 & 0xfffffffb) == 0) {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 6) = param_4;
  }
  else {
    *(ushort *)(this + (ulonglong)(byte)this[0x3d0] * 0xc + 6) = param_2;
  }
  uVar1 = 0;
  this[(ulonglong)(byte)this[0x3d0] * 0xc + 8] = (StateMachineEngineImpl)param_5;
  this[0x3d0] = (StateMachineEngineImpl)((char)this[0x3d0] + 1U & 0x3f);
  if (*(code **)(this + 0x3a8) != (code *)0x0) {
    if (param_4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_4 * 0x10);
    }
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_3 * 4);
    }
    if (param_2 != 0) {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_2 * 0x10);
    }
    (**(code **)(this + 0x3a8))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2,uVar3);
  }
  return;
}



===== PopToStackDepth @ 140011604 =====

/* private: enum SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth(struct
   SmFx::StateMachineEngine::StateMachineEngineImpl::EVENT_ACTION const & __ptr64) __ptr64 */

EngineState __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::PopToStackDepth
          (StateMachineEngineImpl *this,EVENT_ACTION *param_1)

{
  StateMachineEngineImpl SVar1;
  EngineState EVar2;
  ushort uVar3;
  
  if ((byte)param_1[6] + 1 < (uint)(byte)this[0x3d4]) {
    do {
      EVar2 = ExitCurrentState(this,param_1);
      if (EVar2 != 1) {
        return EVar2;
      }
      SVar1 = this[0x3d4];
      if ((byte)SVar1 < 2) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
      }
      LogTransition(this,4,*(ushort *)
                            (*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2),
                    *(ushort *)(param_1 + 4),uVar3,(char)SVar1 - 1);
      *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = 0;
      this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + -1);
      this[0x3d5] = (StateMachineEngineImpl)0x0;
    } while ((byte)param_1[6] + 1 < (uint)(byte)this[0x3d4]);
  }
  return 1;
}



===== ProcessEventQueue @ 1400116e4 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(void)
   __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(StateMachineEngineImpl *this)

{
  ushort uVar1;
  short sVar2;
  StateMachineEngineImpl SVar3;
  EngineState EVar4;
  StateMachineEngineImpl SVar5;
  uint uVar6;
  ulonglong uVar7;
  bool bVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  bVar8 = *(int *)(this + 0x3e0) == 5;
  *(undefined4 *)(this + 0x3e0) = 2;
LAB_140011721:
  do {
    if (!bVar8) {
      SVar3 = this[0x3d2];
      SVar5 = this[0x3d3];
      uVar7 = (ulonglong)(byte)SVar3;
      if (SVar3 != SVar5) {
        while( true ) {
          local_28 = 0;
          uStack_20 = 0;
          uVar1 = *(ushort *)(this + uVar7 * 2 + 0x340);
          FindActionForEvent(this,uVar1,(EVENT_ACTION *)&local_28);
          if ((int)local_28 != 5) break;
          uVar7 = (ulonglong)(byte)((char)SUB81(uVar7,0) + 1) & 0xffffffffffffff0f;
          if (SUB81(uVar7,0) == SVar5) goto LAB_14001178a;
        }
        if (SUB81(uVar7,0) != SVar3) {
          do {
            uVar6 = (int)uVar7 - 1;
            SVar5 = (StateMachineEngineImpl)((byte)uVar6 & 0xf);
            *(undefined2 *)(this + uVar7 * 2 + 0x340) =
                 *(undefined2 *)(this + ((ulonglong)uVar6 & 0xf) * 2 + 0x340);
            SVar3 = this[0x3d2];
            uVar7 = (ulonglong)(byte)SVar5;
          } while (SVar5 != SVar3);
        }
        this[0x3d2] = (StateMachineEngineImpl)((char)SVar3 + 1U & 0xf);
        if (uVar1 != 0) goto LAB_14001180f;
      }
LAB_14001178a:
      EVar4 = 1;
      goto LAB_14001178f;
    }
    local_28 = *(undefined8 *)(this + 0x3c0);
    uStack_20 = *(undefined8 *)(this + 0x3c8);
    bVar8 = false;
LAB_14001180f:
    KeReleaseSpinLock(this + 1000,this[0x3f1]);
    EVar4 = ExecuteEventAction(this,(EVENT_ACTION *)&local_28);
    if (EVar4 == 2) {
      EVar4 = ExecuteCurrentState(this);
    }
    if (EVar4 == 1) {
      EVar4 = 2;
    }
    SVar3 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
    this[0x3f1] = SVar3;
    if (EVar4 == 5) {
      SVar3 = this[0x3d2];
      bVar8 = false;
      sVar2 = *(short *)(this + 0x370);
      SVar5 = SVar3;
      if (SVar3 != this[0x3d3]) {
        do {
          *(undefined2 *)(this + (ulonglong)(byte)SVar5 * 2 + 0x340) =
               *(undefined2 *)(this + (ulonglong)(byte)SVar3 * 2 + 0x340);
          if ((bVar8) || (*(short *)(this + (ulonglong)(byte)SVar3 * 2 + 0x340) != sVar2)) {
            SVar5 = (StateMachineEngineImpl)((char)SVar5 + 1U & 0xf);
          }
          else {
            bVar8 = true;
          }
          SVar3 = (StateMachineEngineImpl)((char)SVar3 + 1U & 0xf);
        } while (SVar3 != this[0x3d3]);
      }
      this[0x3d3] = SVar5;
      if (!bVar8) goto LAB_14001178f;
      *(undefined2 *)(this + 0x370) = 0;
      bVar8 = true;
      goto LAB_140011721;
    }
    if (EVar4 != 2) {
LAB_14001178f:
      UpdateEngineState(this,EVar4);
      return;
    }
  } while( true );
}



===== ReportException @ 1400118f8 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportException
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  StateMachineEngineImpl SVar1;
  
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this + 1000);
  this[0x3f1] = SVar1;
  ReportExceptionWithLockHeld(this,param_1,param_2,param_3);
  return;
}



===== ReportExceptionWithLockHeld @ 14001196c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld(enum
   SmFx::MachineException,unsigned short,unsigned short) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::ReportExceptionWithLockHeld
          (StateMachineEngineImpl *this,MachineException param_1,ushort param_2,ushort param_3)

{
  undefined4 in_register_00000014;
  undefined2 uVar1;
  undefined2 uVar2;
  
  *(MachineException *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x300) = param_1;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x304) = param_2;
  *(ushort *)(this + (ulonglong)(byte)this[0x3d1] * 8 + 0x306) = param_3;
  this[0x3d1] = (StateMachineEngineImpl)((char)this[0x3d1] + 1U & 7);
  KeReleaseSpinLock(this + 1000,
                    CONCAT71((int7)(CONCAT44(in_register_00000014,param_1) >> 8),this[0x3f1]));
  uVar2 = 0;
  if (*(code **)(this + 0x398) != (code *)0x0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x10) + (ulonglong)param_2 * 4);
    }
    if (param_3 != 0) {
      uVar2 = *(undefined2 *)
               (*(longlong *)(*(longlong *)(this + 0x378) + 0x18) + (ulonglong)param_3 * 0x10);
    }
    (**(code **)(this + 0x398))(*(undefined8 *)(this + 0x380),param_1,uVar1,uVar2);
  }
  return;
}



===== UpdateEngineState @ 140011a54 =====

/* private: void __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState(enum
   SmFx::StateMachineEngine::StateMachineEngineImpl::EngineState) __ptr64 */

void __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::UpdateEngineState
          (StateMachineEngineImpl *this,EngineState param_1)

{
  undefined4 in_register_00000014;
  undefined7 uVar1;
  short sVar2;
  
  uVar1 = (undefined7)(CONCAT44(in_register_00000014,param_1) >> 8);
  if (param_1 - 3 < 2) {
    *(EngineState *)(this + 0x3e0) = param_1;
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
    IoQueueWorkItem(*(undefined8 *)(this + 0x3f8),
                    <lambda_9395206af589ac42132775cb7e45a067>::<lambda_invoker_cdecl>,1,this + 0x3f8
                   );
  }
  else if (param_1 == 5) {
    *(undefined4 *)(this + 0x3e0) = 5;
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
  }
  else {
    *(EngineState *)(this + 0x3e0) = param_1;
    if (this[0x3d4] == (StateMachineEngineImpl)0x0) {
      sVar2 = 0;
    }
    else {
      sVar2 = *(short *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
    }
    KeReleaseSpinLock(this + 1000,CONCAT71(uVar1,this[0x3f1]));
    if (sVar2 == 0) {
      Destroy(this);
    }
  }
  return;
}



===== Feature_SMST__private_IsEnabledDeviceUsageNoInline @ 140011b3c =====

ulonglong Feature_SMST__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SMST__private_featureState;
  if ((Feature_SMST__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SMST__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SMST__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SMST__private_IsEnabledFallback @ 140011b74 =====

void Feature_SMST__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SMST__private_descriptor);
  return;
}



===== <lambda_invoker_cdecl> @ 140011b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_9395206af589ac42132775cb7e45a067>::<lambda_invoker_cdecl>
               (undefined8 param_1,longlong param_2)

{
  (**(code **)(param_2 + 0x10))(*(undefined8 *)(param_2 + 0x18));
  return;
}



===== ~Worker @ 140011bb0 =====

/* public: __cdecl SmFx::Worker::~Worker(void) __ptr64 */

void __thiscall SmFx::Worker::~Worker(Worker *this)

{
  if (*(longlong *)this != 0) {
    IoFreeWorkItem();
    *(undefined8 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
  }
  return;
}



===== InitializeTelemetryAssertsKMByDriverObject @ 140011bf0 =====

ulonglong InitializeTelemetryAssertsKMByDriverObject(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_48,0);
    uVar3 = IoQueryFullDriverPath(param_1,&local_48);
    if (-1 < (int)uVar3) {
      uVar2 = RtlUnicodeStringToAnsiString(&local_38,&local_48,1);
      uVar3 = (ulonglong)uVar2;
      ExFreePoolWithTag(uStack_40,0);
      if (-1 < (int)uVar2) {
        uVar2 = (uint)(ushort)local_38;
        do {
          uVar1 = uVar2;
          uVar2 = uVar1 - 1;
          if (uVar2 == 0) goto LAB_140011cd1;
        } while (*(char *)((ulonglong)uVar2 + lStack_30) != '\\');
        if (uVar2 != (ushort)local_38) {
          local_28 = 0;
          uStack_20 = 0;
          RtlInitAnsiString(&local_28,(ulonglong)uVar1 + lStack_30);
          local_18 = local_28;
          uStack_10 = uStack_20;
          uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_18);
          uVar3 = uVar3 & 0xffffffff;
        }
LAB_140011cd1:
        RtlFreeAnsiString(&local_38);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140011cf8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memcpy(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_140017618 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14001a078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140011dac =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,"hidspicx.sys",param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140011de0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140011f96) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  code *pcVar1;
  bool bVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined8 uVar16;
  char *pcVar17;
  int iVar18;
  undefined1 auStack_198 [8];
  undefined1 auStack_190 [116];
  undefined4 local_11c;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  char *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  char *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  puVar15 = auStack_198;
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  iVar18 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400123ec;
  local_11c = param_4;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar15 = auStack_198;
  for (plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar10 = (longlong *)*plVar10) {
    plVar9 = plVar10 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar9 == param_1) goto LAB_140011f1c;
  }
  plVar9 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar14 = _DAT_fffff78000000320;
  puVar15 = auStack_198;
  if (plVar9 != (longlong *)0x0) {
    *plVar9 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar15 = auStack_198;
    plVar9[2] = 0;
    *(undefined4 *)(plVar9 + 3) = 0;
    puVar13 = &g_MicrosoftTelemetryAssertsTriggeredList;
    plVar9[1] = (longlong)((ulonglong)uVar7 * lVar14) / 10000 + -0xea61;
    plVar10 = plVar9 + 4;
    plVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar12 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar10 = (longlong *)(*pcVar1)();
      puVar15 = auStack_190;
    }
    *plVar10 = (longlong)plVar12;
    plVar10[1] = (longlong)puVar13;
    plVar12[1] = (longlong)plVar10;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar10;
LAB_140011f1c:
    *(int *)(plVar9 + 2) = (int)plVar9[2] + 1;
    *(int *)((longlong)plVar9 + 0x14) = *(int *)((longlong)plVar9 + 0x14) + 1;
    lVar14 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar15 + -8) = 0x140011f2d;
    uVar7 = KeQueryTimeIncrement();
    lVar14 = (longlong)((ulonglong)uVar7 * lVar14) / 10000;
    if (60000 < (ulonglong)(lVar14 - plVar9[1])) {
      uVar16 = 0x20b;
      if (((IMAGE_DOS_HEADER *)0x13fffffff < param_1) && (param_1 < (IMAGE_DOS_HEADER *)0x140020001)
         ) {
        iVar18 = (int)param_1 + -0x40000000;
      }
      plVar9[1] = lVar14;
      *(int *)(puVar15 + 0x74) = (int)plVar9[2];
      lVar3 = plVar9[3];
      *(undefined4 *)(puVar15 + 0x78) = *(undefined4 *)((longlong)plVar9 + 0x14);
      *(undefined8 *)(puVar15 + -8) = 0x140011fdd;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar14 >> 8),uVar4));
      lVar14 = -1;
      pcVar17 = "<unknown>";
      if (5 < DAT_14001a040) {
        if (((_DAT_14001a050 & 0x400000000000) == 0) ||
           ((DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_f8 = puVar15 + 0x50;
          local_e8 = puVar15 + 0x54;
          local_d8 = puVar15 + 0x58;
          local_c8 = puVar15 + 0x5c;
          *(undefined4 *)(puVar15 + 0x50) = 10;
          local_f0 = 4;
          *(int *)(puVar15 + 0x54) = iVar18;
          local_e0 = 4;
          *(dword *)(puVar15 + 0x58) = 0x64052d6a;
          local_d0 = 4;
          *(dword *)(puVar15 + 0x5c) = 0x20000;
          local_c0 = 4;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_b8 = "<unknown>";
          }
          lVar11 = -1;
          do {
            lVar11 = lVar11 + 1;
          } while (local_b8[lVar11] != '\0');
          local_b0 = (int)lVar11 + 1;
          *(undefined4 *)(puVar15 + 0x60) = *(undefined4 *)(puVar15 + 0x74);
          local_a8 = puVar15 + 0x60;
          *(undefined4 *)(puVar15 + 100) = *(undefined4 *)(puVar15 + 0x78);
          local_98 = puVar15 + 100;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x1400120f3;
          bVar5 = KeGetCurrentIrql();
          *(uint *)(puVar15 + 0x68) = (uint)bVar5;
          local_88 = puVar15 + 0x68;
          local_78 = "hidspicx.sys";
          *(undefined4 *)(puVar15 + 0x6c) = *(undefined4 *)(puVar15 + 0x7c);
          local_68 = puVar15 + 0x6c;
          *(undefined4 *)(puVar15 + 0x70) = param_5;
          local_58 = puVar15 + 0x70;
          if (param_6 == (char *)0x0) {
            param_6 = "<unknown>";
          }
          local_80 = 4;
          local_70 = 0xd;
          local_60 = 4;
          local_50 = 4;
          if (param_6 == (char *)0x0) {
            param_6 = "";
            local_40 = 1;
          }
          else {
            lVar11 = -1;
            do {
              lVar11 = lVar11 + 1;
            } while (param_6[lVar11] != '\0');
            local_40 = (int)lVar11 + 1;
          }
          local_3c = 0;
          *(undefined1 **)(puVar15 + 0x28) = local_118;
          *(undefined4 *)(puVar15 + 0x20) = 0xe;
          *(undefined8 *)(puVar15 + -8) = 0x1400121b1;
          local_48 = param_6;
          _tlgWriteTransfer_EtwWriteTransfer
                    (param_6,&DAT_140015591,uVar16,pcVar17,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if ((DAT_14001a078 == 0) || ((int)lVar3 != 0)) goto LAB_1400123ec;
      *(undefined8 *)(puVar15 + -8) = 0x1400121ce;
      cVar6 = KeGetCurrentIrql();
      if (cVar6 != '\0') goto LAB_1400123ec;
      *(undefined4 *)(puVar15 + 0x40) = 0;
      *(undefined8 *)(puVar15 + 0x38) = 0;
      *(undefined8 *)(puVar15 + 0x30) = 0;
      *(undefined8 *)(puVar15 + 0x28) = 0x20000;
      *(undefined8 *)(puVar15 + 0x20) = 0x64052d6a;
      *(undefined8 *)(puVar15 + -8) = 0x140012218;
      pcVar17 = g_ModuleName;
      iVar8 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1,iVar18);
      if (5 < DAT_14001a040) {
        if (((_DAT_14001a050 & 0x400000000000) == 0) ||
           ((DAT_14001a058 & 0x400000000000) != DAT_14001a058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_f8 = puVar15 + 0x70;
          *(undefined4 *)(puVar15 + 0x70) = 10;
          local_e8 = puVar15 + 0x6c;
          local_d8 = puVar15 + 0x68;
          local_c8 = puVar15 + 100;
          local_f0 = 4;
          *(int *)(puVar15 + 0x6c) = iVar18;
          local_e0 = 4;
          *(dword *)(puVar15 + 0x68) = 0x64052d6a;
          local_d0 = 4;
          *(dword *)(puVar15 + 100) = 0x20000;
          local_c0 = 4;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_b8 = "<unknown>";
          }
          do {
            lVar14 = lVar14 + 1;
          } while (local_b8[lVar14] != '\0');
          *(undefined4 *)(puVar15 + 0x60) = *(undefined4 *)(puVar15 + 0x74);
          local_a8 = puVar15 + 0x60;
          local_b0 = (int)lVar14 + 1;
          *(undefined4 *)(puVar15 + 0x5c) = *(undefined4 *)(puVar15 + 0x78);
          local_98 = puVar15 + 0x5c;
          local_88 = puVar15 + 0x58;
          local_78 = "hidspicx.sys";
          *(undefined4 *)(puVar15 + 0x54) = *(undefined4 *)(puVar15 + 0x7c);
          local_68 = puVar15 + 0x54;
          *(undefined4 *)(puVar15 + 0x50) = param_5;
          local_58 = puVar15 + 0x50;
          *(undefined1 **)(puVar15 + 0x28) = local_118;
          *(undefined4 *)(puVar15 + 0x20) = 0xd;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar15 + 0x58) = iVar8;
          local_80 = 4;
          local_70 = 0xd;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar15 + -8) = 0x140012393;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0,&DAT_14001563b,0xd,pcVar17,*(undefined4 *)(puVar15 + 0x20),
                     *(undefined8 **)(puVar15 + 0x28));
        }
      }
      if (iVar8 != 0) goto LAB_1400123ec;
      *(undefined8 *)(puVar15 + -8) = 0x1400123a5;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar10 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar10[-4] == param_1) {
            *(int *)(plVar10 + -1) = (int)plVar10[-1] + 1;
            break;
          }
          plVar10 = (longlong *)*plVar10;
        } while ((longlong **)plVar10 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x1400123e7;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_1400123ec:
  *(undefined8 *)(puVar15 + -8) = 0x1400123f8;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140012420 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x1400124b3;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1400124d0;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_14001a098;
    DAT_14001a098 = 0;
    DAT_14001a078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x1400124fa;
    EtwUnregister(uVar3);
    uVar3 = DAT_14001a028;
    DAT_14001a028 = 0;
    _DAT_14001a008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001251c;
    EtwUnregister(uVar3);
    uVar3 = DAT_14001a060;
    DAT_14001a060 = 0;
    DAT_14001a040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001253e;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertDiagTrackProv @ 140012558 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertDiagTrackProv(void)

{
  return;
}



===== _guard_check_icall @ 140012570 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140012588 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400125ac =====

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



===== __cpu_features_init @ 140012620 =====

/* WARNING: Removing unreachable block (ram,0x00014001268a) */
/* WARNING: Removing unreachable block (ram,0x000140012639) */
/* WARNING: Removing unreachable block (ram,0x00014001262a) */

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



===== __security_check_cookie @ 1400126f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140012730 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140012760 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140012760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140012790 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140012800 =====

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



===== memset @ 140012b00 =====

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



===== __memset_repmovs @ 140012c40 =====

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



===== __memset_query @ 140012cc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140012d40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140012e80 =====

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



===== __memset_spec_plain @ 140012f00 =====

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



===== BindClassExtensionClient @ 14001b010 =====

/* long __cdecl __based(PAGE) BindClassExtensionClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void *
   __ptr64 * __ptr64) */

long __cdecl BindClassExtensionClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  bool bVar1;
  long lVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined1 in_stack_ffffffffffffffa8;
  undefined7 in_stack_ffffffffffffffa9;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar5;
  
  bVar1 = true;
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  uVar5 = SUB81(param_1,0);
  if ((cVar4 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_qDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
               CONCAT71(in_stack_ffffffffffffffa9,in_stack_ffffffffffffffa8),
               in_stack_ffffffffffffffb0,0x13,&WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar5
               ,(char)DAT_140017034,(char)*(undefined4 *)(param_1 + 0x28),
               (char)*(undefined4 *)(param_1 + 0x10),(char)*(undefined4 *)(param_1 + 0x14));
  }
  if (*(uint *)(param_1 + 0x28) == DAT_140017034) {
    memcpy(*(void **)(param_1 + 0x20),&PTR_imp_HidSpiCxDeviceInitConfig_140017038,
           (ulonglong)*(uint *)(param_1 + 0x28) << 3);
    puVar3 = (undefined4 *)ExAllocatePool2(0x40,8,0x58435348);
    if (puVar3 == (undefined4 *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) {
        bVar1 = false;
      }
      if ((bVar1 != false) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                   *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffb0,0x15,
                   &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar5);
      }
      lVar2 = -0x3fffff66;
    }
    else {
      *puVar3 = 0x78635348;
      **(undefined8 **)(param_1 + 0x30) = puVar3 + 1;
      lVar2 = 0;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_q
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_stack_ffffffffffffffb0,0x14,
                 &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,uVar5);
    }
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== DeinitializeClassExtension @ 14001b1f0 =====

/* void __cdecl __based(PAGE) DeinitializeClassExtension(void) */

void __cdecl DeinitializeClassExtension(void)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,
               in_stack_ffffffffffffffe0,0x12);
  }
  return;
}



===== EvtDriverUnload @ 14001b260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl __based(PAGE) EvtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl EvtDriverUnload(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  
  if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
    g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  UninitializeTelemetryAssertsKM();
  return;
}



===== InitializeClassExtension @ 14001b320 =====

/* long __cdecl __based(PAGE) InitializeClassExtension(void) */

long __cdecl InitializeClassExtension(void)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
      (cVar1 = '\x01', (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
     ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  if ((cVar1 != '\0') || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
               (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,
               in_stack_ffffffffffffffe0,0x11);
  }
  return 0;
}



===== UnbindClassExtensionClient @ 14001b390 =====

/* void __cdecl __based(PAGE) UnbindClassExtensionClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void
   * __ptr64 * __ptr64) */

void __cdecl UnbindClassExtensionClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  if (**(longlong **)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(**(longlong **)(param_1 + 0x30) + -4,0x58435348);
    **(undefined8 **)(param_1 + 0x30) = 0;
  }
  return;
}



===== WppCleanupKm @ 14001b3d0 =====

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



===== WppInitKm @ 14001b480 =====

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



===== WppLoadTracingSupport @ 14001b55c =====

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



===== WppTraceCallback @ 14001b6a0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001b928 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
  ppuVar2 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001b963;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001b9dd:
  while( true ) {
    if (&UNK_14001692f < ppuVar3) {
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
      if (&UNK_14001692f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001b963:
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
      if (&UNK_14001692f < ppuVar2) goto LAB_14001b9dd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001b9dd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001ba18 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001bab4;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001bab4;
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
LAB_14001bab4:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001bb20 =====

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
      for (ppuVar2 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_14001692f < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14001bba0 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001bbc0 =====

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
  for (ppuVar3 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001bcbd;
  }
LAB_14001bcc6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001bcbd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001bcc6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001bc8e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001bc8e;
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
    if (&UNK_14001692f < ppuVar3) goto LAB_14001bcc6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001bcbd;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 14001bcec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegister_EtwRegister_EtwSetInformation(longlong param_1)

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
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001bd4f;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14001bd6f;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14001bd83;
  return iVar6;
}



===== _tlgEnableCallback @ 14001bda0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== __security_init_cookie @ 14001c008 =====

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



===== DriverEntry @ 14001c03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 local_res18 [2];
  undefined8 *puVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  code *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_res18[0] = 0;
  _WPP_MAIN_CB = 0;
  DAT_140017368 = &WPP_ThisDir_CTLGUID_HidSpiCx;
  bVar1 = true;
  DAT_140017370 = 0;
  _DAT_140017388 = 1;
  _DAT_140017380 = 0;
  _DAT_1400173a0 = 0;
  _DAT_1400173a8 = 0;
  WppLoadTracingSupport();
  _DAT_140017380 = 0;
  WppInitKm(param_1,param_2);
  local_34 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_38 = 0x20;
  }
  else if (WdfStructureCount < 0x19) {
    local_38 = 0xffffffff;
  }
  else {
    local_38 = *(undefined4 *)(WdfStructures + 0xc0);
  }
  local_30 = 0;
  local_28 = EvtDriverUnload;
  puVar4 = local_res18;
  local_20 = 1;
  local_1c = 0x58435348;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_38);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    {
      bVar1 = false;
    }
    if ((bVar1) || ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_AND_TRACE_SF_qd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),bVar1,
                 (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,10,
                 &WPP_6fd11aab44413a3814857b8aa68f378b_Traceguids,(char)param_1,(char)iVar2);
    }
    WppCleanupKm(param_1);
  }
  else {
    iVar2 = DriverRegisterClassExtension(param_1,param_2);
    if (iVar2 < 0) {
      if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
        (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals);
        g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
      }
      WppCleanupKm(param_1);
    }
    else {
      wil_InitializeFeatureStaging();
      InitializeTelemetryAssertsKMByDriverObject(param_1);
      uVar3 = Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_IsEnabledDeviceUsageNoInline()
      ;
      if (((int)uVar3 != 0) && ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0)) {
        g_HidSpiCxDriverVerifierEnabled = true;
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 14001c254 =====

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
    for (ppuVar3 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001c2db;
    }
LAB_14001c315:
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
LAB_14001c2db:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001c315;
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
    goto LAB_14001c315;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14001692f < ppuVar3) goto LAB_14001c315;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001c2db;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001c368 =====

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
  ppuVar4 = &Feature_ResetHidSpiCxDeviceAfterPowerUpTimeout__private_descriptor;
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
            if (&UNK_14001692f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001c452;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001c452;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001c452:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14001692f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


