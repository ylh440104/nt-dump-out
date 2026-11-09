
===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByVal<8>
   const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64,struct _tlgWrapperByVal<8> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<8> *param_7,
          _tlgWrapperByVal<4> *param_8)

{
  long lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [4];
  _tlgWrapperByVal<8> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<8> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_28 = param_8;
  local_38 = param_7;
  local_48 = param_6;
  local_58 = param_5;
  local_20 = 4;
  local_30 = 8;
  local_40 = 4;
  local_50 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,param_2,0,0,6,local_78);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010a4 =====

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
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary> @ 140001148 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct _tlgWrapperBinary>(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperBinary const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<8> *param_7,
          _tlgWrapperByVal<4> *param_8,_tlgWrapperBinary *param_9)

{
  long lVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  _tlgWrapperByVal<8> *local_78;
  undefined8 local_70;
  _tlgWrapperByVal<4> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<8> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  uint *local_38;
  undefined8 local_30;
  void *local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_38 = local_20;
  local_30 = 2;
  local_20[1] = 0;
  local_28 = param_9->Ptr;
  local_20[0] = (uint)param_9->Size;
  local_48 = param_8;
  local_58 = param_7;
  local_68 = param_6;
  local_78 = param_5;
  local_50 = 8;
  local_70 = 8;
  local_40 = 4;
  local_60 = 4;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,param_2,0,0,8,local_98);
  return lVar1;
}



===== Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_> @ 140001204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByVal<8>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<8>,struct _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<8> const & __ptr64,struct _tlgWrapperByVal<2> const &
   __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByVal<8> *param_5,_tlgWrapperByVal<4> *param_6,_tlgWrapperByVal<8> *param_7,
          _tlgWrapperByVal<2> *param_8,_tlgWrapperByVal<4> *param_9)

{
  long lVar1;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  _tlgWrapperByVal<8> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<4> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<8> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<2> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_28 = param_9;
  local_38 = param_8;
  local_48 = param_7;
  local_58 = param_6;
  local_68 = param_5;
  local_20 = 4;
  local_30 = 2;
  local_40 = 8;
  local_50 = 4;
  local_60 = 8;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,param_2,0,0,7,local_88);
  return lVar1;
}



===== __report_gsfailure @ 1400012c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400012cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400012cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== EvtCadRequestCompletion @ 1400012e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtCadRequestCompletion(struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) */

void __cdecl
EvtCadRequestCompletion
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  long lVar1;
  
  lVar1 = (param_3->IoStatus).field0_0x0.Status;
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x34,
                         &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)param_1,(char)lVar1)
      ;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x35,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)param_1);
  }
  TraceLoggingCadUpdate
            (lVar1,*(ulong *)param_4,*(__uint64 *)((longlong)param_4 + 0x18),
             *(ulong *)((longlong)param_4 + 0x14),*(ulong *)((longlong)param_4 + 8),
             *(ulong *)((longlong)param_4 + 0xc),*(ulong *)((longlong)param_4 + 0x10));
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== EvtDriverUnload @ 1400013e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl EvtDriverUnload(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xf,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x10,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)param_1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                       &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,g_ClassLibraryDevice);
  g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
  }
  TraceLoggingDriverUnload();
  PolicyManagerTraceLoggingUnregister();
  uVar1 = DAT_14002a180;
  DAT_14002a180 = 0;
  DAT_14002a160 = 0;
  EtwUnregister(uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
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
  WppCleanupKm(uVar2);
  return;
}



===== EvtIoTargetQueryRemove @ 1400015f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtIoTargetQueryRemove(struct WDFIOTARGET__ * __ptr64) */

long __cdecl EvtIoTargetQueryRemove(WDFIOTARGET__ *param_1)

{
  longlong *plVar1;
  undefined *puVar2;
  undefined *in_stack_ffffffffffffffe8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffe8 = &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x20,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  puVar2 = PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100;
  plVar1 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x21,
                      in_stack_ffffffffffffffe8,*(char **)(*plVar1 + 8));
  }
  (**(code **)(WdfFunctions_01015 + 0x548))(WdfDriverGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x22,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return 0;
}



===== EvtPdConnStateTimerFunc @ 140001700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtPdConnStateTimerFunc(struct WDFTIMER__ * __ptr64) */

void __cdecl EvtPdConnStateTimerFunc(WDFTIMER__ *param_1)

{
  undefined8 uVar1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  uchar local_res10 [8];
  _UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4a,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
  local_res10[0] = '\x01';
  if (p_Var2->PortPartnerAttached != '\0') {
    if ((p_Var2->DeferUrsStateUpdate != '\0') && (p_Var2->UrsStateUpdatedForAttach == '\0')) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x4b,
                           &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                           (char)p_Var2->UcmCxCtx->DeviceSelf,(char)(p_Var2->Config).ConnectorId);
      }
      UpdateUrsState(p_Var2);
      p_Var2->UrsStateUpdatedForAttach = '\x01';
    }
    local_18.ChargingState = (p_Var2->AttachParams).ChargingState;
    local_18.PdConnState = UcmPdConnStateNotSupported;
    local_18.Rdo.Ul = 0;
    local_18.Size = 0x10;
    UcmConnectorPdConnectionStateChangedInternal(p_Var2,&local_18,local_res10);
    if (local_res10[0] == '\0') goto LAB_14000187c;
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var2->Lock);
LAB_14000187c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4c,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return;
}



===== EvtPolicyManagerProtectBrownout @ 1400018d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtPolicyManagerProtectBrownout(void * __ptr64,unsigned __int64,unsigned char) */

long __cdecl EvtPolicyManagerProtectBrownout(void *param_1,__uint64 param_2,uchar param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x51,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,puVar2[0x12],0);
  uVar5 = 0;
  do {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,puVar2[0x13]);
    if (uVar1 <= uVar5) {
LAB_140001ab5:
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar2[0x12]);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x53,
                         &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
      }
      return 0;
    }
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,puVar2[0x13],uVar5);
    puVar4 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,uVar3,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
    if (puVar4[4] == param_2) {
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*puVar4,0);
      if (*(longlong *)(puVar4[5] + 0x20) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x52,
                              &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)*puVar2,
                              (char)puVar4[4],param_3);
        }
        (**(code **)(puVar4[5] + 0x20))(uVar3,param_3);
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar4);
      goto LAB_140001ab5;
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



===== EvtPolicyManagerSetDataRole @ 140001b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtPolicyManagerSetDataRole(void * __ptr64,unsigned __int64,enum _UCM_DATA_ROLE) */

long __cdecl EvtPolicyManagerSetDataRole(void *param_1,__uint64 param_2,_UCM_DATA_ROLE param_3)

{
  long lVar1;
  _UCMCX_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x44,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  p_Var2 = (_UCMCX_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  lVar1 = SetConnectorDataRoleInternal(p_Var2,param_2,param_3);
  TraceLoggingEvtPolicyManagerSetDataRole(lVar1,param_2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x45,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return lVar1;
}



===== EvtPolicyManagerSetPowerLevel @ 140001c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtPolicyManagerSetPowerLevel(void * __ptr64,unsigned __int64,struct
   _UCM_SET_POWER_LEVEL_PARAMS * __ptr64) */

long __cdecl
EvtPolicyManagerSetPowerLevel(void *param_1,__uint64 param_2,_UCM_SET_POWER_LEVEL_PARAMS *param_3)

{
  long lVar1;
  _UCMCX_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4f,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  p_Var2 = (_UCMCX_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  lVar1 = SetConnectorPowerLevelInternal(p_Var2,param_2,param_3);
  TraceLoggingEvtPolicyManagerSetPowerLevel(lVar1,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x50,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return lVar1;
}



===== EvtPolicyManagerSetPowerRole @ 140001d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl EvtPolicyManagerSetPowerRole(void * __ptr64,unsigned __int64,enum _UCM_POWER_ROLE)
    */

long __cdecl EvtPolicyManagerSetPowerRole(void *param_1,__uint64 param_2,_UCM_POWER_ROLE param_3)

{
  long lVar1;
  _UCMCX_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4d,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  p_Var2 = (_UCMCX_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  lVar1 = SetConnectorPowerRoleInternal(p_Var2,param_2,param_3);
  TraceLoggingEvtPolicyManagerSetPowerRole(lVar1,param_2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4e,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return lVar1;
}



===== EvtUrsRequestCompletion @ 140001e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl EvtUrsRequestCompletion(struct WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void * __ptr64) */

void __cdecl
EvtUrsRequestCompletion
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  long lVar1;
  ulonglong uVar2;
  
  lVar1 = (param_3->IoStatus).field0_0x0.Status;
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x23,
                        &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)lVar1);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x24,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  uVar2 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    TraceLoggingUrsUpdateOld(lVar1,*(ulong *)param_4);
  }
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== GetConnectorById @ 140001f0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct UCMCONNECTOR__ * __ptr64 __cdecl GetConnectorById(struct _UCMCX_CONTEXT * __ptr64,unsigned
   __int64) */

UCMCONNECTOR__ * __cdecl GetConnectorById(_UCMCX_CONTEXT *param_1,__uint64 param_2)

{
  uint uVar1;
  UCMCONNECTOR__ *pUVar2;
  longlong lVar3;
  uint uVar4;
  UCMCONNECTOR__ *pUVar5;
  
  pUVar5 = (UCMCONNECTOR__ *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->ConnectorsLock,0);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,param_1->Connectors);
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      pUVar2 = (UCMCONNECTOR__ *)
               (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1->Connectors,uVar4);
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,pUVar2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
      if (*(__uint64 *)(lVar3 + 0x20) == param_2) {
        pUVar5 = pUVar2;
        break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->ConnectorsLock);
  return pUVar5;
}



===== GetIoTargetByName @ 140002018 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct WDFIOTARGET__ * __ptr64 __cdecl GetIoTargetByName(struct WDFCOLLECTION__ * __ptr64,struct
   _UNICODE_STRING const * __ptr64) */

WDFIOTARGET__ * __cdecl GetIoTargetByName(WDFCOLLECTION__ *param_1,_UNICODE_STRING *param_2)

{
  char cVar1;
  uint uVar2;
  WDFIOTARGET__ *pWVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,param_1);
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      pWVar3 = (WDFIOTARGET__ *)
               (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1,uVar5);
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,pWVar3,PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100);
      (**(code **)(WdfFunctions_01015 + 0x9a8))
                (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),&local_18);
      cVar1 = RtlEqualUnicodeString(param_2,&local_18,1);
      if (cVar1 != '\0') {
        return pWVar3;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  return (WDFIOTARGET__ *)0x0;
}



===== GetIoTargetForConnectorId @ 140002120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct WDFIOTARGET__ * __ptr64 __cdecl GetIoTargetForConnectorId(struct WDFCOLLECTION__ *
   __ptr64,unsigned __int64) */

WDFIOTARGET__ * __cdecl GetIoTargetForConnectorId(WDFCOLLECTION__ *param_1,__uint64 param_2)

{
  uint *puVar1;
  uint uVar2;
  WDFIOTARGET__ *pWVar3;
  longlong lVar4;
  __uint64 *p_Var5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,param_1);
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      pWVar3 = (WDFIOTARGET__ *)
               (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1,uVar7);
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,pWVar3,PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100);
      if (*(longlong *)(lVar4 + 0x10) != 0) {
        p_Var5 = (__uint64 *)
                 (**(code **)(WdfFunctions_01015 + 0x610))
                           (WdfDriverGlobals,*(longlong *)(lVar4 + 0x10),0);
        uVar6 = 0;
        puVar1 = (uint *)((longlong)p_Var5 + 4);
        if (*puVar1 != 0) {
          do {
            p_Var5 = p_Var5 + 1;
            if (*p_Var5 == param_2) {
              return pWVar3;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < *puVar1);
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar2);
  }
  if (uVar2 == 1) {
    pWVar3 = (WDFIOTARGET__ *)(**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1,0);
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,pWVar3,PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100);
    if (*(longlong *)(lVar4 + 0x10) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400022d9;
      uVar8 = 0x26;
    }
    else {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x610))
                        (WdfDriverGlobals,*(longlong *)(lVar4 + 0x10),0);
      if (*(int *)(lVar4 + 4) != 0) goto LAB_1400022d7;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400022d9;
      uVar8 = 0x25;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,uVar8,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)pWVar3);
  }
  else {
LAB_1400022d7:
    pWVar3 = (WDFIOTARGET__ *)0x0;
  }
LAB_1400022d9:
  return pWVar3;
}



===== GetUrsConnectorIds @ 140002300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl GetUrsConnectorIds(struct WDFIOTARGET__ * __ptr64) */

void __cdecl GetUrsConnectorIds(WDFIOTARGET__ *param_1)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined8 local_res8;
  undefined4 *local_res10;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  WDFIOTARGET__ *local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_40 = 0;
  local_20 = 0;
  uStack_28 = 0;
  uStack_48 = 0;
  local_res10 = (undefined4 *)0x0;
  local_res8 = 0;
  local_68 = (ulonglong)(uint)local_68;
  local_50 = 0x38;
  uStack_38 = 0x100000001;
  local_30 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_50,0x200,0,0x10,&local_res8,&local_res10);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar4 = 0x14;
  }
  else {
    local_60 = local_res8;
    local_68 = 3;
    local_58 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,param_1,0,0x2a001c,0,&local_68,0,0);
    if (iVar2 == -0x3fffffdd) {
      uVar1 = *local_res10;
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res8);
      local_20 = 0;
      local_40 = 0;
      uStack_48 = 0;
      local_50 = 0x38;
      uStack_28 = 0;
      uStack_38 = 0x100000001;
      local_30 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,&local_50,0x200,0,uVar1,&local_res8,&local_res10);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x15;
        goto LAB_1400023b0;
      }
      local_60 = local_res8;
      local_68 = 3;
      local_58 = 0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                        (WdfDriverGlobals,param_1,0,0x2a001c,0,&local_68,0,0);
    }
    if (-1 < iVar2) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100);
      *(undefined8 *)(lVar3 + 0x10) = local_res8;
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar4 = 0x16;
  }
LAB_1400023b0:
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar4,
                    &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)iVar2);
  return;
}



===== PnPEventHandler @ 1400025a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PnPEventHandler(struct _UNICODE_STRING const * __ptr64,unsigned char,struct
   _PNP_CALLBACK_CONFIG * __ptr64) */

long __cdecl PnPEventHandler(_UNICODE_STRING *param_1,uchar param_2,_PNP_CALLBACK_CONFIG *param_3)

{
  WDFCOLLECTION__ **ppWVar1;
  WDFCOLLECTION__ *pWVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  WDFIOTARGET__ *pWVar6;
  undefined8 *puVar7;
  _UCMCONNECTOR_CONTEXT *p_Var8;
  _UNICODE_STRING *p_Var9;
  WDFWAITLOCK__ *pWVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  WDFIOTARGET__ *pWVar13;
  undefined2 uVar14;
  uint uVar15;
  _UNICODE_STRING *local_res18;
  undefined *in_stack_fffffffffffffee8;
  char *pcVar16;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  _UNICODE_STRING *local_d8;
  undefined8 uStack_d0;
  undefined *local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_6c;
  undefined4 local_68;
  
  uVar15 = 0;
  local_res18 = (_UNICODE_STRING *)0x0;
  local_c8 = (undefined *)0x0;
  uVar11 = 0x88;
  iVar4 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = (_UNICODE_STRING *)0x0;
  uStack_d0 = 0;
  memset(&local_b8,0,0x88);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffee8 = &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids;
    uVar11 = 2;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x17,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  if ((param_3->IoTargetHandlePointer != (WDFIOTARGET__ **)0x0) &&
     (param_3->IoTargetCollection != (WDFCOLLECTION__ **)0x0)) {
    iVar4 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,0x18,
                        in_stack_fffffffffffffee8,param_3->InterfaceName);
    }
    goto LAB_140002696;
  }
  ppWVar1 = param_3->IoTargetCollection;
  if (ppWVar1 == (WDFCOLLECTION__ **)0x0) {
    pWVar6 = *param_3->IoTargetHandlePointer;
  }
  else {
    pWVar6 = GetIoTargetByName(*ppWVar1,param_1);
  }
  bVar3 = ppWVar1 != (WDFCOLLECTION__ **)0x0;
  if (param_2 == '\0') {
    if (pWVar6 != (WDFIOTARGET__ *)0x0) {
      pWVar13 = (WDFIOTARGET__ *)0x0;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_3->IoTargetLock);
      if (bVar3) {
        pWVar13 = pWVar6;
        (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*param_3->IoTargetCollection);
      }
      else {
        *param_3->IoTargetHandlePointer = (WDFIOTARGET__ *)0x0;
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_3->IoTargetLock);
      (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals,pWVar6);
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar6);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pWVar13,0x1e,
                          in_stack_fffffffffffffee8,param_3->InterfaceName);
      }
      goto LAB_140002bf5;
    }
LAB_140002ada:
    iVar4 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar11,0x19,
                        in_stack_fffffffffffffee8,param_3->InterfaceName);
    }
  }
  else {
    if (pWVar6 != (WDFIOTARGET__ *)0x0) goto LAB_140002ada;
    puVar12 = &local_f8;
    local_c8 = PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100;
    local_e8 = 0;
    uStack_f0 = 0;
    local_f8 = 0x38;
    local_d8 = (_UNICODE_STRING *)0x0;
    uStack_d0 = 0;
    uStack_e0 = 0x100000001;
    p_Var9 = (_UNICODE_STRING *)param_3->UcmCxCtx->DeviceSelf;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,p_Var9,puVar12,&local_res18);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar16 = param_3->InterfaceName;
        uVar14 = 0x1a;
LAB_140002782:
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var9,puVar12,uVar14,
                           &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,pcVar16,(char)iVar4);
      }
    }
    else {
      puVar7 = (undefined8 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res18,
                          PTR__WDF_UCMIOTARGET_CONTEXT_TYPE_INFO_14002a100);
      puVar12 = &local_f8;
      *puVar7 = param_3;
      local_e8 = 0;
      local_c8 = (undefined *)0x0;
      uStack_d0 = 0;
      local_d8 = local_res18;
      uStack_f0 = 0;
      local_f8 = 0x38;
      uStack_e0 = 0x100000001;
      p_Var9 = param_1;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,param_1,puVar12,puVar7 + 1)
      ;
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x1b;
LAB_140002843:
          pcVar16 = param_3->InterfaceName;
          goto LAB_140002782;
        }
      }
      else {
        memset(&local_b8,0,0x88);
        local_88._0_2_ = param_1->Length;
        local_88._2_2_ = param_1->MaximumLength;
        uStack_84 = *(undefined4 *)&param_1->field_0x4;
        uStack_80 = *(undefined4 *)&param_1->Buffer;
        uStack_7c = *(undefined4 *)((longlong)&param_1->Buffer + 4);
        puVar12 = (undefined8 *)&local_b8;
        local_b0 = EvtIoTargetQueryRemove;
        local_b8 = 0x88;
        local_b4 = 2;
        local_78 = 0xc0000000;
        local_68 = 0x40;
        local_6c = 1;
        p_Var9 = local_res18;
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals);
        if (-1 < iVar4) {
          (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_3->IoTargetLock,0);
          if (bVar3) {
            (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*param_3->IoTargetCollection,local_res18);
          }
          else {
            *param_3->IoTargetHandlePointer = (WDFIOTARGET__ *)local_res18;
          }
          pWVar10 = param_3->IoTargetLock;
          (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar10,2,0x1d,
                               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                               (char)param_3->UcmCxCtx->DeviceSelf,param_3->InterfaceName);
          }
          iVar4 = 0;
          if (param_3->InterfacePostOpenCallback != (_func___cdecl_void_WDFIOTARGET___ptr *)0x0) {
            (*param_3->InterfacePostOpenCallback)((WDFIOTARGET__ *)local_res18);
          }
          (**(code **)(WdfFunctions_01015 + 0x9c8))
                    (WdfDriverGlobals,param_3->UcmCxCtx->ConnectorsLock,0);
          pWVar2 = param_3->UcmCxCtx->Connectors;
          uVar5 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,pWVar2);
          if (uVar5 != 0) {
            do {
              uVar11 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,pWVar2,uVar15);
              p_Var8 = (_UCMCONNECTOR_CONTEXT *)
                       (**(code **)(WdfFunctions_01015 + 0x650))
                                 (WdfDriverGlobals,uVar11,
                                  PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
              (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var8->Lock,0);
              (*param_3->InterfaceOnlineCallback)(p_Var8);
              (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var8->Lock);
              uVar15 = uVar15 + 1;
            } while (uVar15 < uVar5);
          }
          (**(code **)(WdfFunctions_01015 + 0x9d0))
                    (WdfDriverGlobals,param_3->UcmCxCtx->ConnectorsLock);
          goto LAB_140002bf5;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar14 = 0x1c;
          goto LAB_140002843;
        }
      }
    }
  }
LAB_140002696:
  if (local_res18 != (_UNICODE_STRING *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_res18 = (_UNICODE_STRING *)0x0;
  }
LAB_140002bf5:
  TraceLoggingPnPEvent(iVar4,param_3->InterfaceName,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1f,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return iVar4;
}



===== SetConnectorDataRoleInternal @ 140002c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SetConnectorDataRoleInternal(struct _UCMCX_CONTEXT * __ptr64,unsigned __int64,enum
   _UCM_DATA_ROLE) */

long __cdecl
SetConnectorDataRoleInternal(_UCMCX_CONTEXT *param_1,__uint64 param_2,_UCM_DATA_ROLE param_3)

{
  int iVar1;
  int iVar2;
  UCMCONNECTOR__ *pUVar3;
  longlong lVar4;
  __uint64 _Var5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  undefined8 local_res20;
  undefined8 *puVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  
  _Var5 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Var5 = CONCAT71((int7)(param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x54,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  if (param_3 == UcmDataRoleInvalid) {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    WPP_RECORDER_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Var5,2,0x55,
                       &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0,0xd);
  }
  else {
    pUVar3 = GetConnectorById(param_1,param_2);
    uVar11 = (undefined1)param_2;
    if (pUVar3 == (UCMCONNECTOR__ *)0x0) {
      iVar1 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar9 = 0x56;
      uVar12 = 0xd;
    }
    else {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pUVar3);
      if (*(longlong *)(lVar4 + 0x50) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x58,
                             &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,(char)param_3);
        }
        uVar6 = 0;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->RoleSwapLock);
        KeResetEvent(lVar4 + 0x98);
        iVar1 = (**(code **)(lVar4 + 0x50))(pUVar3);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_iLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x59,
                                &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,
                                (char)param_3,(char)iVar1);
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x5a,
                              &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11);
          }
          uVar7 = 0;
          do {
            puVar10 = &local_res20;
            local_res20 = 0xffffffffff676980;
            uVar8 = 0;
            uVar6 = 0;
            iVar2 = KeWaitForSingleObject(lVar4 + 0x98,0,0,0);
            if (iVar2 == 0) {
              if (*(_UCM_DATA_ROLE *)(lVar4 + 0x100) == param_3) {
                iVar1 = 0;
                goto LAB_140002f6a;
              }
              if (*(_UCM_DATA_ROLE *)(lVar4 + 0x100) == UcmDataRoleInvalid) {
                iVar1 = -0x3ffffe7c;
                iVar2 = -0x3ffffe7c;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x5b,
                                    &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11);
                  goto LAB_140002f6a;
                }
                break;
              }
              iVar1 = -0x3fffffff;
            }
            else if (iVar2 == 0x102) {
              iVar1 = -0x3fffff4b;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_did(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,uVar8,0x5c,
                                  puVar10,(char)uVar7,uVar11,(char)iVar1);
            }
            uVar7 = uVar7 + 1;
            iVar2 = iVar1;
          } while (uVar7 < 2);
          iVar1 = iVar2;
        }
LAB_140002f6a:
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->RoleSwapLock);
        goto LAB_140002f8b;
      }
      iVar1 = -0x3fffff45;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff45;
      }
      uVar9 = 0x57;
      uVar12 = 0xbb;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar9,
                       &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,uVar12);
  }
LAB_140002f8b:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x5d,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return iVar1;
}



===== SetConnectorPowerLevelInternal @ 140003048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SetConnectorPowerLevelInternal(struct _UCMCX_CONTEXT * __ptr64,unsigned
   __int64,struct _UCM_SET_POWER_LEVEL_PARAMS * __ptr64) */

long __cdecl
SetConnectorPowerLevelInternal
          (_UCMCX_CONTEXT *param_1,__uint64 param_2,_UCM_SET_POWER_LEVEL_PARAMS *param_3)

{
  UCMCONNECTOR__ *pUVar1;
  longlong lVar2;
  undefined2 uVar3;
  int iVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x67,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  pUVar1 = GetConnectorById(param_1,param_2);
  if (pUVar1 == (UCMCONNECTOR__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    iVar4 = -0x3ffffff3;
    uVar3 = 0x68;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,pUVar1,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
    if ((*(char *)(lVar2 + 100) == '\0') || (*(longlong *)(lVar2 + 0x78) == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff45;
      }
      uVar3 = 0x69;
      iVar4 = -0x3fffff45;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x6a,
                          &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)param_2);
      }
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->PowerLevelChangeLock,0);
      if (param_3->PowerRole == UcmPowerRoleSink) {
        if (param_3->Format == UcmSetPowerLevelParamsFormatRdo) {
          *(ulong *)(lVar2 + 0x178) = (param_3->field3_0xc).Rdo.Rdo.Ul;
        }
      }
      else if ((param_3->PowerRole == UcmPowerRoleSource) &&
              (param_3->Format == UcmSetPowerLevelParamsFormatCCurrent)) {
        *(ulong *)(lVar2 + 0x17c) = (param_3->field3_0xc).Rdo.Rdo.Ul;
      }
      iVar4 = (**(code **)(lVar2 + 0x78))(pUVar1,param_3);
      if (-1 < iVar4) {
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->PowerLevelChangeLock);
        return iVar4;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar4;
      }
      uVar3 = 0x6b;
    }
  }
  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar3,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)param_2,(char)iVar4);
  return iVar4;
}



===== SetConnectorPowerRoleInternal @ 140003260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SetConnectorPowerRoleInternal(struct _UCMCX_CONTEXT * __ptr64,unsigned __int64,enum
   _UCM_POWER_ROLE) */

long __cdecl
SetConnectorPowerRoleInternal(_UCMCX_CONTEXT *param_1,__uint64 param_2,_UCM_POWER_ROLE param_3)

{
  int iVar1;
  int iVar2;
  UCMCONNECTOR__ *pUVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined8 local_res20;
  undefined8 *puVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  
  uVar10 = (undefined1)param_3;
  if (param_3 - UcmPowerRoleSink < 2) {
    pUVar3 = GetConnectorById(param_1,param_2);
    uVar11 = (undefined1)param_2;
    if (pUVar3 == (UCMCONNECTOR__ *)0x0) {
      iVar1 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar7 = 0x5f;
      uVar10 = 0xd;
    }
    else {
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pUVar3);
      if ((*(char *)(lVar4 + 100) != '\0') && (*(longlong *)(lVar4 + 0x70) != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x61,
                             &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,uVar10);
        }
        uVar5 = 0;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->RoleSwapLock);
        KeResetEvent(lVar4 + 0xb0);
        iVar1 = (**(code **)(lVar4 + 0x70))(pUVar3);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_iLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x62,
                                &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,uVar10,
                                (char)iVar1);
          }
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,99,
                              &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11);
          }
          uVar8 = 1;
          do {
            puVar9 = &local_res20;
            local_res20 = 0xffffffffff676980;
            uVar6 = 0;
            uVar5 = 0;
            iVar2 = KeWaitForSingleObject(lVar4 + 0xb0,0,0,0);
            if (iVar2 == 0) {
              if (*(_UCM_POWER_ROLE *)(lVar4 + 0x104) == param_3) {
                iVar1 = 0;
                break;
              }
              if (*(_UCM_POWER_ROLE *)(lVar4 + 0x104) == UcmPowerRoleInvalid) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,100,
                                    &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11);
                }
                iVar1 = -0x3ffffe7c;
                break;
              }
              iVar1 = -0x3fffffff;
            }
            else if (iVar2 == 0x102) {
              iVar1 = -0x3fffff4b;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_did(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x65,puVar9
                                  ,(char)uVar8,uVar11,(char)iVar1);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < 3);
        }
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->RoleSwapLock);
        goto LAB_140003599;
      }
      iVar1 = -0x3fffff45;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff45;
      }
      uVar7 = 0x60;
      uVar10 = 0xbb;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar7,
                       &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar11,uVar10);
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    WPP_RECORDER_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x5e,
                       &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar10,0xd);
  }
LAB_140003599:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x66,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return iVar1;
}



===== TraceLoggingCadUpdate @ 1400035f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingCadUpdate(long,unsigned long,unsigned __int64,unsigned long,unsigned
   long,unsigned long,unsigned long) */

void __cdecl
TraceLoggingCadUpdate
          (long param_1,ulong param_2,__uint64 param_3,ulong param_4,ulong param_5,ulong param_6,
          ulong param_7)

{
  undefined1 auStackY_118 [32];
  ulong local_e8;
  ulong local_e4;
  ulong local_e0;
  ulong local_dc;
  ulong local_d8;
  long local_d4;
  __uint64 local_d0 [3];
  undefined8 local_b8 [4];
  __uint64 *local_98;
  undefined8 local_90;
  long *local_88;
  undefined8 local_80;
  ulong *local_78;
  undefined8 local_70;
  __uint64 *local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  ulong *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_e8 = param_7;
    local_e4 = param_6;
    local_e0 = param_5;
    local_28 = &local_e8;
    local_38 = &local_e4;
    local_48 = &local_e0;
    local_58 = &local_dc;
    local_68 = local_d0;
    local_78 = &local_d8;
    local_88 = &local_d4;
    local_98 = local_d0 + 1;
    local_d0[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    local_60 = 8;
    local_70 = 4;
    local_80 = 4;
    local_90 = 8;
    local_dc = param_4;
    local_d8 = param_2;
    local_d4 = param_1;
    local_d0[0] = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002702b,0,0,10,local_b8);
  }
  return;
}



===== TraceLoggingDriverLoad @ 140003748 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingDriverLoad(long) */

void __cdecl TraceLoggingDriverLoad(long param_1)

{
  undefined1 auStackY_98 [32];
  long local_68 [2];
  undefined8 local_60;
  undefined8 local_58 [4];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  long *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x200000000000) != 0)) &&
     ((DAT_14002a178 & 0x200000000000) == DAT_14002a178)) {
    local_28 = local_68;
    local_1c = 0;
    local_38 = &local_60;
    local_60 = 0x3000800;
    local_20 = 4;
    local_2c = 0;
    local_30 = 8;
    local_68[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002724a,0,0,4,local_58);
  }
  return;
}



===== TraceLoggingDriverUnload @ 140003814 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingDriverUnload(void) */

void __cdecl TraceLoggingDriverUnload(void)

{
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 local_40 [4];
  undefined8 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x200000000000) != 0)) &&
     ((DAT_14002a178 & 0x200000000000) == DAT_14002a178)) {
    local_20 = &local_48;
    local_48 = 0x3000800;
    local_14 = 0;
    local_18 = 8;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002721e,0,0,3,local_40);
  }
  return;
}



===== TraceLoggingEvtPolicyManagerSetDataRole @ 1400038b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingEvtPolicyManagerSetDataRole(long,unsigned __int64,unsigned long) */

void __cdecl TraceLoggingEvtPolicyManagerSetDataRole(long param_1,__uint64 param_2,ulong param_3)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _GUID *in_R9;
  _tlgWrapperByVal<4> local_res20 [2];
  _tlgWrapperByVal<4> local_28 [2];
  _tlgWrapperByVal<8> local_20;
  _tlgWrapperByVal<8> local_18 [3];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_18[0].Value = 0x3000800;
    local_res20[0].Value = param_3;
    local_28[0].Value = param_1;
    local_20.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_140026fd0,
               (_GUID *)CONCAT44(in_register_00000084,param_3),in_R9,local_18,local_28,&local_20,
               local_res20);
  }
  return;
}



===== TraceLoggingEvtPolicyManagerSetPowerLevel @ 14000393c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingEvtPolicyManagerSetPowerLevel(long,unsigned __int64) */

void __cdecl TraceLoggingEvtPolicyManagerSetPowerLevel(long param_1,__uint64 param_2)

{
  undefined1 auStackY_b8 [32];
  long local_88 [2];
  __uint64 local_80 [3];
  undefined8 local_68 [4];
  __uint64 *local_48;
  undefined8 local_40;
  long *local_38;
  undefined8 local_30;
  __uint64 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = local_80;
    local_38 = local_88;
    local_48 = local_80 + 1;
    local_80[1] = 0x3000800;
    local_20 = 8;
    local_30 = 4;
    local_40 = 8;
    local_88[0] = param_1;
    local_80[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140026e91,0,0,5,local_68);
  }
  return;
}



===== TraceLoggingEvtPolicyManagerSetPowerRole @ 140003a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingEvtPolicyManagerSetPowerRole(long,unsigned __int64,unsigned long) */

void __cdecl TraceLoggingEvtPolicyManagerSetPowerRole(long param_1,__uint64 param_2,ulong param_3)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _GUID *in_R9;
  _tlgWrapperByVal<4> local_res20 [2];
  _tlgWrapperByVal<4> local_28 [2];
  _tlgWrapperByVal<8> local_20;
  _tlgWrapperByVal<8> local_18 [3];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_18[0].Value = 0x3000800;
    local_res20[0].Value = param_3;
    local_28[0].Value = param_1;
    local_20.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_140026ee4,
               (_GUID *)CONCAT44(in_register_00000084,param_3),in_R9,local_18,local_28,&local_20,
               local_res20);
  }
  return;
}



===== TraceLoggingPnPEvent @ 140003a94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingPnPEvent(long,char const * __ptr64,unsigned char) */

void __cdecl TraceLoggingPnPEvent(long param_1,char *param_2,uchar param_3)

{
  longlong lVar1;
  undefined1 auStackY_b8 [32];
  uchar local_88 [4];
  long local_84;
  undefined8 local_80;
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  char *local_38;
  int local_30;
  undefined4 local_2c;
  uchar *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = local_88;
    local_80 = 0x3000800;
    local_20 = 1;
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_30 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_2[lVar1] != '\0');
      local_30 = (int)lVar1 + 1;
    }
    local_48 = &local_84;
    local_58 = &local_80;
    local_2c = 0;
    local_40 = 4;
    local_50 = 8;
    local_88[0] = param_3;
    local_84 = param_1;
    local_38 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_1400271d8,0,0,6,local_78);
  }
  return;
}



===== TraceLoggingUcmConnectorPdConnectionStateChangedInternal @ 140003ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorPdConnectionStateChangedInternal(long,unsigned
   __int64,unsigned long,unsigned long,unsigned long,unsigned long) */

void __cdecl
TraceLoggingUcmConnectorPdConnectionStateChangedInternal
          (long param_1,__uint64 param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6)

{
  undefined1 auStackY_108 [32];
  ulong local_d8;
  ulong local_d4;
  ulong local_d0;
  ulong local_cc;
  long local_c8 [2];
  __uint64 local_c0 [3];
  undefined8 local_a8 [4];
  __uint64 *local_88;
  undefined8 local_80;
  long *local_78;
  undefined8 local_70;
  __uint64 *local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  ulong *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_d8 = param_6;
    local_d4 = param_5;
    local_28 = &local_d8;
    local_38 = &local_d4;
    local_48 = &local_d0;
    local_58 = &local_cc;
    local_68 = local_c0;
    local_78 = local_c8;
    local_88 = local_c0 + 1;
    local_c0[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    local_60 = 8;
    local_70 = 4;
    local_80 = 8;
    local_d0 = param_4;
    local_cc = param_3;
    local_c8[0] = param_1;
    local_c0[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140026f41,0,0,9,local_a8);
  }
  return;
}



===== TraceLoggingUrsUpdate @ 140003cd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUrsUpdate(unsigned __int64,unsigned long) */

void __cdecl TraceLoggingUrsUpdate(__uint64 param_1,ulong param_2)

{
  undefined1 auStackY_b8 [32];
  ulong local_88 [2];
  __uint64 local_80 [3];
  undefined8 local_68 [4];
  __uint64 *local_48;
  undefined8 local_40;
  __uint64 *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = local_88;
    local_38 = local_80;
    local_48 = local_80 + 1;
    local_80[1] = 0x3000800;
    local_20 = 4;
    local_30 = 8;
    local_40 = 8;
    local_88[0] = param_2;
    local_80[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140027095,0,0,5,local_68);
  }
  return;
}



===== TraceLoggingUrsUpdateDecisionForPortPartnerUfpWithNoUsbData @ 140003dac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUrsUpdateDecisionForPortPartnerUfpWithNoUsbData(unsigned char,unsigned
   char,unsigned __int64,enum _URS_HARDWARE_EVENT,enum _URS_HARDWARE_EVENT) */

void __cdecl
TraceLoggingUrsUpdateDecisionForPortPartnerUfpWithNoUsbData
          (uchar param_1,uchar param_2,__uint64 param_3,_URS_HARDWARE_EVENT param_4,
          _URS_HARDWARE_EVENT param_5)

{
  undefined1 auStackY_e8 [32];
  uchar local_b8;
  uchar local_b7 [3];
  _URS_HARDWARE_EVENT local_b4;
  _URS_HARDWARE_EVENT local_b0 [2];
  __uint64 local_a8 [6];
  __uint64 *local_78;
  undefined8 local_70;
  uchar *local_68;
  undefined8 local_60;
  uchar *local_58;
  undefined8 local_50;
  __uint64 *local_48;
  undefined8 local_40;
  _URS_HARDWARE_EVENT *local_38;
  undefined8 local_30;
  _URS_HARDWARE_EVENT *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_b4 = param_5;
    local_28 = &local_b4;
    local_38 = local_b0;
    local_48 = local_a8;
    local_58 = &local_b8;
    local_68 = local_b7;
    local_78 = local_a8 + 1;
    local_40 = 8;
    local_70 = 8;
    local_a8[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_50 = 1;
    local_60 = 1;
    local_b8 = param_2;
    local_b7[0] = param_1;
    local_b0[0] = param_4;
    local_a8[0] = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_1400270dd,0,0,8,local_a8 + 2);
  }
  return;
}



===== TraceLoggingUrsUpdateOld @ 140003ec0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUrsUpdateOld(long,unsigned long) */

void __cdecl TraceLoggingUrsUpdateOld(long param_1,ulong param_2)

{
  undefined1 auStackY_a8 [32];
  ulong local_78;
  long local_74;
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined8 local_40;
  long *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = &local_78;
    local_38 = &local_74;
    local_48 = &local_70;
    local_70 = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 8;
    local_78 = param_2;
    local_74 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140027194,0,0,5,local_68);
  }
  return;
}



===== UcmConnectorPdConnectionStateChangedInternal @ 140003f94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UcmConnectorPdConnectionStateChangedInternal(struct _UCMCONNECTOR_CONTEXT *
   __ptr64,struct _UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS * __ptr64,unsigned char * __ptr64) */

long __cdecl
UcmConnectorPdConnectionStateChangedInternal
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS *param_2,
          uchar *param_3)

{
  uint uVar1;
  __uint64 _Var2;
  byte bVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  WDFMEMORY__ *pWVar7;
  _UCM_PD_CONN_STATE _Var8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  undefined8 in_stack_ffffffffffffffb8;
  undefined1 uVar12;
  
  lVar9 = 0;
  if (*param_3 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->Lock,0);
    *param_3 = '\x01';
  }
  _Var8 = param_2->PdConnState;
  _Var2 = (param_1->Config).ConnectorId;
  if (_Var8 == UcmPdConnStateNegotiationSucceeded) {
    param_1->PdConnState = UcmPdConnStateNegotiationFailed;
    if (param_1->LocalPortPowerRole == UcmPowerRoleSink) {
      pWVar7 = param_1->PartnerSourcePdos;
      bVar3 = param_1->PartnerSourcePdosCount;
    }
    else {
      pWVar7 = param_1->SourcePdos;
      bVar3 = param_1->SourcePdosCount;
    }
    uVar12 = (undefined1)_Var2;
    if (pWVar7 == (WDFMEMORY__ *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x46,
                           &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                           (char)param_1->UcmCxCtx->DeviceSelf,uVar12);
      }
    }
    else {
      uVar5 = (param_2->Rdo).Ul >> 0x1c & 7;
      if ((uVar5 != 0) && (uVar5 <= bVar3)) {
        lVar4 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,pWVar7,0);
        if (lVar4 == 0) {
          lVar9 = -0x3fffffff;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x48,
                                &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                (char)param_1->UcmCxCtx->DeviceSelf,
                                (char)(param_1->Config).ConnectorId,1);
          }
          goto LAB_140004267;
        }
        uVar5 = (param_2->Rdo).Ul;
        uVar11 = (uVar5 >> 0x1c & 7) - 1;
        uVar1 = *(uint *)(lVar4 + (ulonglong)uVar11 * 4);
        uVar10 = uVar1 >> 0x1e;
        if (uVar10 == 0) {
LAB_1400041c5:
          param_1->PdOperatingCurrent = (uVar5 >> 10 & 0x3ff) * 10;
        }
        else {
          uVar6 = uVar10 - 1;
          if (uVar6 != 0) {
            if (uVar6 != 1) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qidd
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar6,
                           (ulonglong)uVar10,0x49,in_stack_ffffffffffffffb8,
                           (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                           (char)uVar11,(byte)(uVar1 >> 0x1e));
              }
              goto LAB_140004267;
            }
            goto LAB_1400041c5;
          }
          param_1->PdOperatingCurrent = ((uVar5 >> 10 & 0x3ff) / (uVar1 >> 0x14 & 0x3ff)) * 5;
        }
        param_1->PdVoltage = (*(uint *)(lVar4 + (ulonglong)uVar11 * 4) >> 10 & 0x3ff) * 0x32;
        (param_1->PdRequestDataObject).Ul = (param_2->Rdo).Ul;
        _Var8 = UcmPdConnStateNegotiationSucceeded;
        goto LAB_140004245;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qidd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar7,(ulonglong)bVar3,0x47,
                   in_stack_ffffffffffffffb8,(char)param_1->UcmCxCtx->DeviceSelf,uVar12,(char)uVar5,
                   bVar3);
      }
    }
    lVar9 = -0x3ffffddb;
  }
  else {
LAB_140004245:
    param_1->PdConnState = _Var8;
    (param_1->AttachParams).ChargingState = param_2->ChargingState;
    UpdateCadState(param_1);
    ConnectorIndicateStateChangeAndReleaseLock(param_1);
    *param_3 = '\0';
  }
LAB_140004267:
  TraceLoggingUcmConnectorPdConnectionStateChangedInternal
            (lVar9,_Var2,param_2->Size,param_2->PdConnState,(param_2->Rdo).Ul,param_2->ChargingState
            );
  return lVar9;
}



===== UcmCxContextCleanup @ 1400042b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UcmCxContextCleanup(void * __ptr64) */

void __cdecl UcmCxContextCleanup(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x12,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  UcmDeregisterForPnPEvents(*(void **)(lVar1 + 0x60));
  *(undefined8 *)(lVar1 + 0x60) = 0;
  UcmDeregisterForPnPEvents(*(void **)(lVar1 + 0x80));
  *(undefined8 *)(lVar1 + 0x80) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x13,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return;
}



===== UcmDumpPdo @ 14000439c =====

/* void __cdecl UcmDumpPdo(union _UCM_PD_POWER_DATA_OBJECT * __ptr64,unsigned __int64,unsigned
   char,unsigned char) */

void __cdecl
UcmDumpPdo(_UCM_PD_POWER_DATA_OBJECT *param_1,__uint64 param_2,uchar param_3,uchar param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  undefined7 in_register_00000081;
  undefined2 uVar4;
  char *pcVar5;
  undefined8 in_stack_ffffffffffffff78;
  
  uVar1 = param_1->Ul;
  pcVar3 = "partner";
  pcVar5 = "source";
  if (param_4 == '\0') {
    pcVar3 = "local";
  }
  if (param_3 == '\0') {
    pcVar5 = "sink";
  }
  uVar2 = uVar1 >> 0x1e;
  if (uVar2 == 0) {
    if (param_3 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_issdddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_issddddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if (uVar2 == 1) {
      if (param_3 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x6f;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x6e;
      }
    }
    else {
      if (uVar2 != 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_issdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return;
      }
      if (param_3 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x71;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x70;
      }
    }
    uVar2 = uVar1 >> 0x14 & 0x3ff;
    WPP_RECORDER_SF_issdddD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar2,
               CONCAT71(in_register_00000081,param_3),uVar4,in_stack_ffffffffffffff78,(char)param_2,
               pcVar3,pcVar5,(char)uVar1,(char)(uVar1 >> 10),(char)uVar2,(char)uVar1);
  }
  return;
}



===== UcmDumpPdos @ 140004678 =====

/* void __cdecl UcmDumpPdos(union _UCM_PD_POWER_DATA_OBJECT * __ptr64,unsigned long,unsigned
   __int64,unsigned char,unsigned char) */

void __cdecl
UcmDumpPdos(_UCM_PD_POWER_DATA_OBJECT *param_1,ulong param_2,__uint64 param_3,uchar param_4,
           uchar param_5)

{
  ulonglong uVar1;
  
  if (param_2 != 0) {
    uVar1 = (ulonglong)param_2;
    do {
      UcmDumpPdo(param_1,param_3,param_4,param_5);
      param_1 = param_1 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



===== UcmDumpRdo @ 1400046d4 =====

/* void __cdecl UcmDumpRdo(union _UCM_PD_REQUEST_DATA_OBJECT * __ptr64,unsigned __int64) */

void __cdecl UcmDumpRdo(_UCM_PD_REQUEST_DATA_OBJECT *param_1,__uint64 param_2)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_idddddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== UpdateCadState @ 1400047a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpdateCadState(struct _UCMCONNECTOR_CONTEXT * __ptr64) */

long __cdecl UpdateCadState(_UCMCONNECTOR_CONTEXT *param_1)

{
  _UCM_POWER_ROLE _Var1;
  uint uVar2;
  _UCM_PD_CONN_STATE _Var3;
  _UCM_TYPEC_CURRENT _Var4;
  _UCMCX_CONTEXT *p_Var5;
  char cVar6;
  int iVar7;
  ulong uVar8;
  uchar uVar9;
  __uint64 _Var10;
  undefined2 uVar11;
  ulong uVar12;
  ulong *local_res8;
  WDFIOTARGET__ *local_res10;
  undefined8 local_res18;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  WDFIOTARGET__ *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res8 = (ulong *)0x0;
  local_48 = 0;
  local_res10 = (WDFIOTARGET__ *)0x0;
  cVar6 = '\0';
  local_res18 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (WDFIOTARGET__ *)0x0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x36,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->UcmCxCtx->CadLock,0);
  p_Var5 = param_1->UcmCxCtx;
  if (p_Var5->CadIoTarget == (WDFIOTARGET__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x37,
                        &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)p_Var5->DeviceSelf);
    }
    iVar7 = -0x3fffffcc;
    goto LAB_140004e82;
  }
  local_78 = CONCAT44(local_78._4_4_,0x38);
  uVar9 = '\x01';
  uStack_60 = 0x100000001;
  local_58 = p_Var5->CadIoTarget;
  iVar7 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_78);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004e82;
    uVar11 = 0x38;
  }
  else {
    local_48 = 0;
    local_68 = 0;
    uStack_50 = 0;
    local_58 = local_res10;
    uStack_70 = 0;
    local_78 = 0x38;
    uStack_60 = 0x100000001;
    iVar7 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_78,0x200,0,0x38,&local_res18,&local_res8);
    if (-1 < iVar7) {
      local_res8[0] = 0;
      local_res8[1] = 0;
      local_res8[2] = 0;
      local_res8[3] = 0;
      local_res8[4] = 0;
      local_res8[5] = 0;
      local_res8[6] = 0;
      local_res8[7] = 0;
      local_res8[8] = 0;
      local_res8[9] = 0;
      local_res8[10] = 0;
      local_res8[0xb] = 0;
      local_res8[0xc] = 0;
      local_res8[0xd] = 0;
      *(ulong64 *)(local_res8 + 6) = (param_1->Config).ConnectorId;
      if (param_1->PortPartnerAttached == '\0') {
LAB_140004aba:
        if (param_1->IsLastCadIoctlCharging != '\0') goto LAB_140004be2;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3f,
                             &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                             (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId
                            );
        }
LAB_140004e7f:
        iVar7 = 0;
      }
      else {
        _Var1 = param_1->LocalPortPowerRole;
        if (_Var1 != UcmPowerRoleSink) {
          if (_Var1 != UcmPowerRoleSource) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3e,
                                  &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                  (char)param_1->UcmCxCtx->DeviceSelf,
                                  (char)(param_1->Config).ConnectorId,(char)_Var1);
            }
            uVar2 = *(uint *)(WdfDriverGlobals + 8);
joined_r0x000140004a64:
            iVar7 = -0x3ffffe7c;
            if ((uVar2 & 4) != 0) {
              iVar7 = -0x3ffffe7c;
              RtlAssert("FALSE","onecore\\drivers\\wdm\\usb\\ucm\\cx\\driver\\driver.cpp");
            }
            goto LAB_140004e82;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0x3a;
LAB_140004a84:
            WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,uVar11,
                               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                               (char)param_1->UcmCxCtx->DeviceSelf,
                               (char)(param_1->Config).ConnectorId);
          }
          goto LAB_140004aba;
        }
        _Var3 = param_1->PdConnState;
        if (_Var3 == UcmPdConnStateNotSupported) {
          _Var4 = (param_1->AttachParams).CurrentAdvertisement;
          if (_Var4 == UcmTypeCCurrentDefaultUsb) {
            local_res8[2] = 1;
          }
          else {
            if (_Var4 == UcmTypeCCurrent1500mA) {
              local_res8[3] = 0x5dc;
            }
            else {
              if (_Var4 != UcmTypeCCurrent3000mA) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3b,
                                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                      (char)param_1->UcmCxCtx->DeviceSelf,
                                      (char)(param_1->Config).ConnectorId,(char)_Var4);
                }
                iVar7 = -0x3ffffff3;
                goto LAB_140004e82;
              }
              local_res8[3] = 3000;
            }
            local_res8[4] = 5000;
          }
        }
        else {
          if (_Var3 == UcmPdConnStateNegotiationFailed) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0x3c;
              goto LAB_140004a84;
            }
            goto LAB_140004aba;
          }
          if (_Var3 != UcmPdConnStateNegotiationSucceeded) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3d,
                                  &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                  (char)param_1->UcmCxCtx->DeviceSelf,
                                  (char)(param_1->Config).ConnectorId,(char)_Var3);
            }
            uVar2 = *(uint *)(WdfDriverGlobals + 8);
            goto joined_r0x000140004a64;
          }
          local_res8[2] = 2;
          local_res8[3] = param_1->PdOperatingCurrent;
          local_res8[4] = param_1->PdVoltage;
        }
LAB_140004be2:
        *local_res8 = 5;
        local_res8[5] = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiqddDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        if (((local_res8[3] == 0) && (local_res8[4] == 0)) && (local_res8[2] == 0)) {
          uVar9 = '\0';
        }
        param_1->IsLastCadIoctlCharging = uVar9;
        iVar7 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                          (WdfDriverGlobals,param_1->UcmCxCtx->CadIoTarget,local_res10,0x29c4c8,
                           local_res18,0,0,0);
        if (iVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140004e82;
          uVar11 = 0x41;
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0x820))
                    (WdfDriverGlobals,local_res10,EvtCadRequestCompletion);
          cVar6 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_res10);
          if (cVar6 != '\0') goto LAB_140004e7f;
          iVar7 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_res10);
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140004e82;
          uVar11 = 0x42;
        }
        WPP_RECORDER_SF_qiqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar11,
                   &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                   (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                   (char)local_res10,(char)iVar7);
      }
      goto LAB_140004e82;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004e82;
    uVar11 = 0x39;
  }
  WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar11,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                      (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                      (char)iVar7);
LAB_140004e82:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->UcmCxCtx->CadLock);
  if (iVar7 < 0) {
    if (local_res8 == (ulong *)0x0) {
      uVar15 = 0;
      uVar12 = 0;
      _Var10 = 0;
      uVar14 = 0;
      uVar13 = 0;
      uVar8 = 0;
    }
    else {
      uVar15 = local_res8[4];
      uVar12 = local_res8[5];
      _Var10 = *(__uint64 *)(local_res8 + 6);
      uVar14 = local_res8[3];
      uVar13 = local_res8[2];
      uVar8 = *local_res8;
    }
    TraceLoggingCadUpdate(iVar7,uVar8,_Var10,uVar12,uVar13,uVar14,uVar15);
  }
  if ((local_res10 != (WDFIOTARGET__ *)0x0) && (cVar6 == '\0')) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x43,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return iVar7;
}



===== UpdateUrsState @ 140004f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpdateUrsState(struct _UCMCONNECTOR_CONTEXT * __ptr64) */

long __cdecl UpdateUrsState(_UCMCONNECTOR_CONTEXT *param_1)

{
  _UCM_TYPEC_PARTNER _Var1;
  _UCMCX_CONTEXT *p_Var2;
  _UCM_PRIVATE_DRIVER_GLOBALS *p_Var3;
  __uint64 _Var4;
  char cVar5;
  int iVar6;
  WDFIOTARGET__ *pWVar7;
  ulonglong uVar8;
  _URS_HARDWARE_EVENT _Var9;
  uchar uVar10;
  undefined2 uVar11;
  char cVar12;
  _URS_HARDWARE_EVENT *local_res8;
  WDFIOTARGET__ *local_res10;
  undefined8 local_res18;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  WDFIOTARGET__ *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res8 = (_URS_HARDWARE_EVENT *)0x0;
  local_48 = 0;
  local_res10 = (WDFIOTARGET__ *)0x0;
  cVar12 = '\0';
  cVar5 = '\0';
  local_res18 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (WDFIOTARGET__ *)0x0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x27,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->UcmCxCtx->UrsLock,0);
  pWVar7 = GetIoTargetForConnectorId(param_1->UcmCxCtx->UrsIoTargets,(param_1->Config).ConnectorId);
  if (pWVar7 == (WDFIOTARGET__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x28,
                         &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                         (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId);
    }
    iVar6 = -0x3fffffcc;
    goto LAB_14000554f;
  }
  uVar10 = '\x01';
  local_78 = CONCAT44(local_78._4_4_,0x38);
  uStack_60 = 0x100000001;
  local_58 = pWVar7;
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_78,pWVar7,&local_res10);
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000554f;
    uVar11 = 0x29;
  }
  else {
    local_48 = 0;
    local_68 = 0;
    uStack_50 = 0;
    local_58 = local_res10;
    uStack_70 = 0;
    local_78 = 0x38;
    uStack_60 = 0x100000001;
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_78,0x200,0,4,&local_res18,&local_res8);
    if (-1 < iVar6) {
      if (param_1->PortPartnerAttached == '\0') {
        *local_res8 = UrsHardwareEventDetach;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
LAB_1400053ef:
        uVar8 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar8 != 0) {
          _Var4 = (param_1->Config).ConnectorId;
          param_1->PreviousUrsHardwareEvent = *local_res8;
          TraceLoggingUrsUpdate(_Var4,*local_res8);
        }
        iVar6 = (**(code **)(WdfFunctions_01015 + 0x5d8))
                          (WdfDriverGlobals,pWVar7,local_res10,0x2a0014,local_res18,0,0,0);
        if (iVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000554f;
          uVar11 = 0x31;
          cVar5 = cVar12;
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0x820))
                    (WdfDriverGlobals,local_res10,EvtUrsRequestCompletion,local_res8);
          cVar5 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,local_res10,pWVar7,0);
          if (cVar5 != '\0') goto LAB_14000554c;
          iVar6 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,local_res10);
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000554f;
          uVar11 = 0x32;
        }
        WPP_RECORDER_SF_qiqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar11,
                   &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                   (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                   (char)local_res10,(char)iVar6);
      }
      else {
        _Var1 = (param_1->AttachParams).Partner;
        if (_Var1 == UcmTypeCPartnerUfp) {
          *local_res8 = UrsHardwareEventPortTypeDfp;
          uVar8 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
          if ((((int)uVar8 != 0) && (param_1->PartnerSourcePdosCount != '\0')) &&
             (param_1->PartnerUsbCommunicationCapable == '\0')) {
            p_Var2 = param_1->UcmCxCtx;
            p_Var3 = p_Var2->PrivateGlobals;
            if (p_Var3->IsClientUcmUcsiCx == '\0') {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x2d;
LAB_1400052f1:
                WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,uVar11,
                                   &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                   (char)p_Var2->DeviceSelf,(char)(param_1->Config).ConnectorId);
              }
            }
            else if ((p_Var3->IsTestSigningOn == '\0') ||
                    (p_Var3->TestOverrideLoadUsbHostForPartnerUfpNoUsbData == '\0')) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2c,
                                   &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                                   (char)p_Var2->DeviceSelf,(char)(param_1->Config).ConnectorId);
              }
              *local_res8 = UrsHardwareEventDetach;
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0x2b;
              goto LAB_1400052f1;
            }
            p_Var3 = param_1->UcmCxCtx->PrivateGlobals;
            if ((p_Var3->IsTestSigningOn == '\0') ||
               (p_Var3->TestOverrideLoadUsbHostForPartnerUfpNoUsbData == '\0')) {
              uVar10 = '\0';
            }
            TraceLoggingUrsUpdateDecisionForPortPartnerUfpWithNoUsbData
                      (p_Var3->IsClientUcmUcsiCx,uVar10,(param_1->Config).ConnectorId,*local_res8,
                       param_1->PreviousUrsHardwareEvent);
          }
LAB_14000535d:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qiqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          goto LAB_1400053ef;
        }
        if (_Var1 == UcmTypeCPartnerDfp) {
          *local_res8 = UrsHardwareEventPortTypeUfp;
          goto LAB_14000535d;
        }
        if (_Var1 == UcmTypeCPartnerPoweredCableWithUfp) {
          *local_res8 = UrsHardwareEventPortTypeDfp;
          goto LAB_14000535d;
        }
        cVar5 = cVar12;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2e,
                              &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                              (char)param_1->UcmCxCtx->DeviceSelf,
                              (char)(param_1->Config).ConnectorId,(char)_Var1);
        }
LAB_14000554c:
        iVar6 = 0;
      }
      goto LAB_14000554f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000554f;
    uVar11 = 0x2a;
  }
  WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar11,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,
                      (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                      (char)iVar6);
LAB_14000554f:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->UcmCxCtx->UrsLock);
  uVar8 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar8 == 0) && (iVar6 < 0)) {
    if (local_res8 == (_URS_HARDWARE_EVENT *)0x0) {
      _Var9 = UrsHardwareEventNone;
    }
    else {
      _Var9 = *local_res8;
    }
    TraceLoggingUrsUpdateOld(iVar6,_Var9);
  }
  if ((local_res10 != (WDFIOTARGET__ *)0x0) && (cVar5 == '\0')) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x33,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  return iVar6;
}



===== DriverEntry @ 140005614 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStackY_128 [32];
  undefined1 uVar3;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  DAT_14002a3d8 = &WPP_ThisDir_CTLGUID_UCMCX;
  DAT_14002a3e0 = &DAT_14002a420;
  _DAT_14002a428 = &WPP_ThisDir_CTLGUID_POLICY_MANAGER;
  WPP_MAIN_CB = 0;
  _DAT_14002a3f0 = 0;
  _DAT_14002a3f8 = 1;
  _DAT_14002a410 = 0;
  _DAT_14002a418 = 0;
  _DAT_14002a420 = 0;
  _DAT_14002a430 = 0;
  _DAT_14002a440 = 0;
  _DAT_14002a448 = 1;
  _DAT_14002a460 = 0;
  _DAT_14002a468 = 0;
  WppLoadTracingSupport();
  _DAT_14002a3f0 = 0;
  WppInitKm(param_1,param_2);
  wil_InitializeFeatureStaging();
  local_58 = 0x100000010;
  uStack_50 = 0x200000001;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_58);
  uVar3 = SUB81(param_1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                       &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                        &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar3);
    }
  }
  TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14002a160);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14002a278);
  local_b8 = 0;
  uStack_b0 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitAnsiString(&local_b8,"PolicyManagerKm");
    local_68 = local_b8;
    uStack_60 = uStack_b0;
    InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_68);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xb,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  local_78 = 0;
  local_98 = 0;
  uStack_a0 = 0;
  local_a8 = 0x38;
  local_88 = 0;
  uStack_80 = 0;
  uStack_90 = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_a8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                         &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar3,(char)iVar2);
    }
  }
  else {
    iVar2 = CxRegister(param_1,param_2);
    if (-1 < iVar2) {
      iVar2 = UsbDualRoleFeaturesMarkUcmPresence();
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0xd,
                             &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,uVar3,(char)iVar2);
        }
        iVar2 = 0;
      }
    }
  }
  TraceLoggingDriverLoad(iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
  }
  if (iVar2 < 0) {
    TraceLoggingDriverUnload();
    PolicyManagerTraceLoggingUnregister();
    uVar1 = DAT_14002a180;
    DAT_14002a180 = 0;
    DAT_14002a160 = 0;
    EtwUnregister(uVar1);
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    WppCleanupKm(param_1);
  }
  return iVar2;
}



===== Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline @ 140005a30 =====

ulonglong Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_UFFPPUWOUD__private_featureState;
  if ((Feature_UFFPPUWOUD__private_featureState & 0x10) == 0) {
    uVar1 = Feature_UFFPPUWOUD__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_UFFPPUWOUD__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_UFFPPUWOUD__private_IsEnabledFallback @ 140005a68 =====

void Feature_UFFPPUWOUD__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== WPP_RECORDER_SF_ @ 140005a80 =====

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



===== WPP_RECORDER_SF_L @ 140005b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== WPP_RECORDER_SF_Ld @ 140005c54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ld(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_did @ 140005d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_did(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,3,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,4,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140005e78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140005f74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_id @ 1400060c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_id(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_iLd @ 1400061f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iLd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,2,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_idddddddddD @ 1400062f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_idddddddddD(undefined8 param_1)

{
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
  undefined1 uStack0000000000000080;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x73,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x73,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  return;
}



===== WPP_RECORDER_SF_issdD @ 140006504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_issdD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x72,&uStack0000000000000030,8,
               pcVar2,lVar3,pcVar5,lVar4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,3,1,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x72,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,in_stack_00000040,lVar4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_issdddD @ 140006714 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_issdddD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,char *param_7,char *param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar6 = param_8;
  pcVar5 = param_7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_8 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (param_8[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar7 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar7 = "NULL";
    }
    if (param_7 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (param_7[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,8,pcVar2,lVar3,
               pcVar7,lVar4,&param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
  }
  if (pcVar6 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (pcVar6[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (pcVar6 == (char *)0x0) {
    pcVar6 = "NULL";
  }
  lVar3 = -1;
  if (pcVar5 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (pcVar5[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,8,
                  pcVar5,lVar1,pcVar6,lVar4,&param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_RECORDER_SF_issdddddddD @ 140006984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_issdddddddD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x6d,&uStack0000000000000030,8,
               pcVar2,lVar3,pcVar5,lVar4,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,
               &uStack0000000000000070,4,&uStack0000000000000078,4,&uStack0000000000000080,4,0);
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x6d,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,in_stack_00000040,lVar4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  return;
}



===== WPP_RECORDER_SF_issddddddddD @ 140006c84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_issddddddddD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  char *in_stack_00000040;
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
    if (in_stack_00000040 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x6c,&uStack0000000000000030,8,
               pcVar2,lVar3,pcVar5,lVar4,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,
               &uStack0000000000000070,4,&uStack0000000000000078,4,&uStack0000000000000080,4,
               &uStack0000000000000088,4,0);
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x6c,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,in_stack_00000040,lVar4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,0);
  return;
}



===== WPP_RECORDER_SF_qi @ 140006fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qi(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qiL @ 1400070dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qidd @ 14000722c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qidd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qiqL @ 140007348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x30,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x30,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qiqLL @ 14000745c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x2f,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x2f,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qiqd @ 140007598 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,&param_9,
                  4,0);
  return;
}



===== WPP_RECORDER_SF_qiqddDdd @ 14000770c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqddDdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x40,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,0x40,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_qs @ 1400078ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,char *param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  pcVar4 = param_7;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (pcVar4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,pcVar4,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_s @ 140007a2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,pcVar3,lVar2,0);
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
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,2,&WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,param_4,param_6
                  ,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 140007b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_6[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,pcVar3,lVar2,&param_7
               ,4,0);
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
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,2,2,param_5,param_4,param_6,lVar1,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 140007c90 =====

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



===== _tlgDefineProvider_annotation__Tlgg_UpmTraceLoggingProviderProv @ 140007cec =====

void _tlgDefineProvider_annotation__Tlgg_UpmTraceLoggingProviderProv(void)

{
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140007cf8 =====

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
LAB_140007efb:
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
LAB_140007dd3:
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
      if (param_3 == 4) goto LAB_140007efb;
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
        goto LAB_140007dd3;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140007fe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_1400080a7;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_1400080a7;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_1400080a7;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_1400080a7;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_1400080a7;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_1400080a7;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_1400080a7;
    }
  }
  uVar2 = 0xff;
LAB_1400080a7:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x36e0f65,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,&Feature_UFFPPUWOUD__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x36e0f65,param_3,1,&Feature_UFFPPUWOUD__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x36e0f65);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400081ec =====

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
LAB_14000829f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400082cd;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000829f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400082cd:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140008458 =====

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
  if ((Feature_UFFPPUWOUD__private_featureState & 2) != 0) {
    uVar1 = Feature_UFFPPUWOUD__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_UFFPPUWOUD__private_featureState;
      if (bVar3) {
        Feature_UFFPPUWOUD__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_UFFPPUWOUD__private_featureState;
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



===== wil_details_IsEnabledFallback @ 1400084ac =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_UFFPPUWOUD__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_UFFPPUWOUD__private_featureState,(ulonglong)param_1,
                             0x140029a58);
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



===== wil_details_RecordCachedUsage @ 14000853c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140008690 =====

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



===== CxBindClient @ 140008720 =====

/* long __cdecl CxBindClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 * __ptr64) */

long __cdecl CxBindClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  void *pvVar5;
  uchar uVar6;
  int iVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  long lVar10;
  __uint64 _Var11;
  
  puVar8 = (undefined4 *)0x0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                       &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  uVar2 = (param_1->Version).Minor;
  puVar1 = &param_1->FunctionTableCount;
  if (((uVar2 == DAT_14002a008) && (*puVar1 != DAT_14002a034)) || ((uVar2 == 0 && (*puVar1 != 0xb)))
     ) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    lVar10 = -0x3ffffff3;
  }
  else {
    memmove(param_1->FunctionTable,&PTR_imp_UcmInitializeDevice_14002a038,(ulonglong)*puVar1 << 3);
    _Var11 = 0x586d6355;
    puVar8 = (undefined4 *)ExAllocatePool2();
    if (puVar8 == (undefined4 *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                         &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
      }
      lVar10 = -0x3fffff66;
    }
    else {
      *puVar8 = 0x47445055;
      puVar4 = param_1->ClassBindInfo;
      *(undefined8 *)(puVar8 + 2) = *WdfDriverGlobals;
      *(_WDF_CLASS_BIND_INFO **)(puVar8 + 4) = param_1;
      *puVar4 = puVar8 + 1;
      uVar9 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 != 0) {
        uVar6 = CheckTestSigning();
        *(uchar *)(puVar8 + 6) = uVar6;
        uVar6 = CheckTestOverrideLoadUsbHostForPartnerUfpNoUsbData();
        pvVar5 = param_1->ClassBindInfo;
        *(uchar *)((longlong)puVar8 + 0x19) = uVar6;
        GetImageName(pvVar5,(char *)((longlong)puVar8 + 0x1b),_Var11);
        iVar7 = _stricmp((char *)((longlong)puVar8 + 0x1b),"UcmUcsiCx.sys");
        *(bool *)((longlong)puVar8 + 0x1a) = iVar7 == 0;
      }
      lVar10 = 0;
    }
  }
  uVar9 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
  uVar2 = (param_1->Version).Minor;
  uVar3 = (param_1->Version).Major;
  if ((int)uVar9 == 0) {
    TraceLoggingClientBind
              (lVar10,DAT_14002a034,param_1->FunctionTableCount,DAT_14002a004,DAT_14002a008,uVar3,
               uVar2);
  }
  else {
    TraceLoggingClientBind2
              (lVar10,(char *)(-(ulonglong)(puVar8 != (undefined4 *)0x0) & (longlong)puVar8 + 0x1bU)
               ,DAT_14002a034,param_1->FunctionTableCount,DAT_14002a004,DAT_14002a008,uVar3,uVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
  }
  return lVar10;
}



===== CxDeinitialize @ 1400089d0 =====

/* void __cdecl CxDeinitialize(void) */

void __cdecl CxDeinitialize(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                       &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xd,
                       &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
    }
  }
  return;
}



===== CxInitialize @ 140008a60 =====

/* long __cdecl CxInitialize(void) */

long __cdecl CxInitialize(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                       &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xb,
                       &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
    }
  }
  return 0;
}



===== CxUnbindClient @ 140008af0 =====

/* void __cdecl CxUnbindClient(struct _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 * __ptr64) */

void __cdecl CxUnbindClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x13,
                     &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
  }
  if (*(longlong *)param_1->ClassBindInfo != 0) {
    ExFreePoolWithTag(*(longlong *)param_1->ClassBindInfo + -4,0x586d6355);
    *(undefined8 *)param_1->ClassBindInfo = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids);
  }
  return;
}



===== TraceLoggingClientBind2 @ 140008bbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingClientBind2(long,char const * __ptr64,unsigned long,unsigned
   long,unsigned long,unsigned long,unsigned long,unsigned long) */

void __cdecl
TraceLoggingClientBind2
          (long param_1,char *param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6,
          ulong param_7,ulong param_8)

{
  longlong lVar1;
  undefined1 auStackY_138 [32];
  undefined1 local_108 [4];
  ulong local_104;
  ulong local_100;
  ulong local_fc;
  ulong local_f8;
  ulong local_f4;
  ulong local_f0;
  long local_ec;
  undefined8 local_e8 [2];
  undefined8 local_d8 [4];
  undefined8 *local_b8;
  undefined8 local_b0;
  long *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  char *local_88;
  int local_80;
  undefined4 local_7c;
  ulong *local_78;
  undefined8 local_70;
  ulong *local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  ulong *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_138;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_104 = param_8;
    local_100 = param_7;
    local_fc = param_6;
    local_f8 = param_5;
    local_28 = &local_104;
    local_38 = &local_100;
    local_48 = &local_fc;
    local_58 = &local_f8;
    local_68 = &local_f4;
    local_78 = &local_f0;
    local_108[0] = 1;
    local_e8[0] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    local_60 = 4;
    local_70 = 4;
    if (param_2 == (char *)0x0) {
      param_2 = "";
      local_80 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_2[lVar1] != '\0');
      local_80 = (int)lVar1 + 1;
    }
    local_98 = local_108;
    local_a8 = &local_ec;
    local_7c = 0;
    local_b8 = local_e8;
    local_90 = 1;
    local_a0 = 4;
    local_b0 = 8;
    local_f4 = param_4;
    local_f0 = param_3;
    local_ec = param_1;
    local_88 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140027328,0,0,0xc,local_d8);
  }
  return;
}



===== TraceLoggingClientBind @ 140008d5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingClientBind(long,unsigned long,unsigned long,unsigned long,unsigned
   long,unsigned long,unsigned long) */

void __cdecl
TraceLoggingClientBind
          (long param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6,
          ulong param_7)

{
  undefined1 auStackY_118 [32];
  ulong local_e8;
  ulong local_e4;
  ulong local_e0;
  ulong local_dc;
  ulong local_d8;
  ulong local_d4;
  long local_d0 [2];
  undefined8 local_c8 [2];
  undefined8 local_b8 [4];
  undefined8 *local_98;
  undefined8 local_90;
  long *local_88;
  undefined8 local_80;
  ulong *local_78;
  undefined8 local_70;
  ulong *local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  ulong *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_e8 = param_7;
    local_e4 = param_6;
    local_e0 = param_5;
    local_28 = &local_e8;
    local_38 = &local_e4;
    local_48 = &local_e0;
    local_58 = &local_dc;
    local_68 = &local_d8;
    local_78 = &local_d4;
    local_88 = local_d0;
    local_98 = local_c8;
    local_c8[0] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    local_60 = 4;
    local_70 = 4;
    local_80 = 4;
    local_90 = 8;
    local_dc = param_4;
    local_d8 = param_3;
    local_d4 = param_2;
    local_d0[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002727d,0,0,10,local_b8);
  }
  return;
}



===== WPP_RECORDER_SF_DD @ 140008eb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids,0xf,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids,0xf,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_LLLLL @ 140008f84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLLLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids,0x10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_a8752676166c3e46a24a81a23ac558b0_Traceguids,0x10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== TraceLoggingDetectedPortPartnerDrdWithNoUsbData @ 1400090b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingDetectedPortPartnerDrdWithNoUsbData(unsigned char,unsigned __int64,enum
   _URS_HARDWARE_EVENT,unsigned char,unsigned int,enum _UCM_POWER_ROLE,enum _UCM_DATA_ROLE,enum
   _UCM_TYPEC_PARTNER) */

void __cdecl
TraceLoggingDetectedPortPartnerDrdWithNoUsbData
          (uchar param_1,__uint64 param_2,_URS_HARDWARE_EVENT param_3,uchar param_4,uint param_5,
          _UCM_POWER_ROLE param_6,_UCM_DATA_ROLE param_7,_UCM_TYPEC_PARTNER param_8)

{
  undefined1 auStackY_128 [32];
  uchar local_f8;
  uchar local_f7 [3];
  _UCM_TYPEC_PARTNER local_f4;
  _UCM_DATA_ROLE local_f0;
  _UCM_POWER_ROLE local_ec;
  uint local_e8;
  _URS_HARDWARE_EVENT local_e4;
  __uint64 local_e0 [3];
  undefined8 local_c8 [4];
  __uint64 *local_a8;
  undefined8 local_a0;
  uchar *local_98;
  undefined8 local_90;
  __uint64 *local_88;
  undefined8 local_80;
  _URS_HARDWARE_EVENT *local_78;
  undefined8 local_70;
  uchar *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  _UCM_POWER_ROLE *local_48;
  undefined8 local_40;
  _UCM_DATA_ROLE *local_38;
  undefined8 local_30;
  _UCM_TYPEC_PARTNER *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_f4 = param_8;
    local_f0 = param_7;
    local_ec = param_6;
    local_e8 = param_5;
    local_28 = &local_f4;
    local_38 = &local_f0;
    local_48 = &local_ec;
    local_58 = &local_e8;
    local_68 = &local_f8;
    local_78 = &local_e4;
    local_88 = local_e0;
    local_98 = local_f7;
    local_a8 = local_e0 + 1;
    local_e0[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 4;
    local_60 = 1;
    local_70 = 4;
    local_80 = 8;
    local_90 = 1;
    local_a0 = 8;
    local_f8 = param_4;
    local_f7[0] = param_1;
    local_e4 = param_3;
    local_e0[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_1400277dc,0,0,0xb,local_c8);
  }
  return;
}



===== TraceLoggingUcmConnectorAlternateModeEntered @ 140009224 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorAlternateModeEntered(long,unsigned __int64,unsigned
   short,unsigned int) */

void __cdecl
TraceLoggingUcmConnectorAlternateModeEntered
          (long param_1,__uint64 param_2,ushort param_3,uint param_4)

{
  undefined4 in_register_0000000c;
  undefined6 in_register_00000082;
  undefined4 in_register_0000008c;
  _tlgWrapperByVal<2> local_28 [2];
  _tlgWrapperByVal<4> local_24;
  _tlgWrapperByVal<4> local_20 [2];
  _tlgWrapperByVal<8> local_18;
  _tlgWrapperByVal<8> local_10 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_10[0].Value = 0x3000800;
    local_28[0].Value = param_3;
    local_24.Value = param_4;
    local_20[0].Value = param_1;
    local_18.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_1400274c0,
               (_GUID *)CONCAT62(in_register_00000082,param_3),
               (_GUID *)CONCAT44(in_register_0000008c,param_4),local_10,local_20,&local_18,local_28,
               &local_24);
  }
  return;
}



===== TraceLoggingUcmConnectorAlternateModeExited @ 1400092c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorAlternateModeExited(long,unsigned __int64,unsigned
   short,unsigned int) */

void __cdecl
TraceLoggingUcmConnectorAlternateModeExited
          (long param_1,__uint64 param_2,ushort param_3,uint param_4)

{
  undefined4 in_register_0000000c;
  undefined6 in_register_00000082;
  undefined4 in_register_0000008c;
  _tlgWrapperByVal<2> local_28 [2];
  _tlgWrapperByVal<4> local_24;
  _tlgWrapperByVal<4> local_20 [2];
  _tlgWrapperByVal<8> local_18;
  _tlgWrapperByVal<8> local_10 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_10[0].Value = 0x3000800;
    local_28[0].Value = param_3;
    local_24.Value = param_4;
    local_20[0].Value = param_1;
    local_18.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_14002745f,
               (_GUID *)CONCAT62(in_register_00000082,param_3),
               (_GUID *)CONCAT44(in_register_0000008c,param_4),local_10,local_20,&local_18,local_28,
               &local_24);
  }
  return;
}



===== TraceLoggingUcmConnectorAlternateModeHardwareConfigured @ 140009364 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorAlternateModeHardwareConfigured(long,unsigned
   __int64,unsigned short,unsigned int) */

void __cdecl
TraceLoggingUcmConnectorAlternateModeHardwareConfigured
          (long param_1,__uint64 param_2,ushort param_3,uint param_4)

{
  undefined4 in_register_0000000c;
  undefined6 in_register_00000082;
  undefined4 in_register_0000008c;
  _tlgWrapperByVal<2> local_28 [2];
  _tlgWrapperByVal<4> local_24;
  _tlgWrapperByVal<4> local_20 [2];
  _tlgWrapperByVal<8> local_18;
  _tlgWrapperByVal<8> local_10 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_10[0].Value = 0x3000800;
    local_28[0].Value = param_3;
    local_24.Value = param_4;
    local_20[0].Value = param_1;
    local_18.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_1400273f2,
               (_GUID *)CONCAT62(in_register_00000082,param_3),
               (_GUID *)CONCAT44(in_register_0000008c,param_4),local_10,local_20,&local_18,local_28,
               &local_24);
  }
  return;
}



===== TraceLoggingUcmConnectorChargingStateChanged @ 140009404 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorChargingStateChanged(long,unsigned __int64,unsigned long) */

void __cdecl
TraceLoggingUcmConnectorChargingStateChanged(long param_1,__uint64 param_2,ulong param_3)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _GUID *in_R9;
  _tlgWrapperByVal<4> local_res20 [2];
  _tlgWrapperByVal<4> local_28 [2];
  _tlgWrapperByVal<8> local_20;
  _tlgWrapperByVal<8> local_18 [3];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_18[0].Value = 0x3000800;
    local_res20[0].Value = param_3;
    local_28[0].Value = param_1;
    local_20.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_1400275ca,
               (_GUID *)CONCAT44(in_register_00000084,param_3),in_R9,local_18,local_28,&local_20,
               local_res20);
  }
  return;
}



===== TraceLoggingUcmConnectorCreate @ 140009488 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorCreate(long,unsigned long,unsigned long,unsigned
   __int64,unsigned char,unsigned long,unsigned long,unsigned char,unsigned char,unsigned
   char,unsigned char) */

void __cdecl
TraceLoggingUcmConnectorCreate
          (long param_1,ulong param_2,ulong param_3,__uint64 param_4,uchar param_5,ulong param_6,
          ulong param_7,uchar param_8,uchar param_9,uchar param_10,uchar param_11)

{
  undefined1 auStackY_158 [32];
  uchar local_128;
  uchar local_127;
  uchar local_126;
  uchar local_125;
  uchar local_124 [4];
  ulong local_120;
  ulong local_11c;
  ulong local_118;
  ulong local_114;
  long local_110 [2];
  __uint64 local_108 [6];
  __uint64 *local_d8;
  undefined8 local_d0;
  long *local_c8;
  undefined8 local_c0;
  ulong *local_b8;
  undefined8 local_b0;
  ulong *local_a8;
  undefined8 local_a0;
  __uint64 *local_98;
  undefined8 local_90;
  uchar *local_88;
  undefined8 local_80;
  ulong *local_78;
  undefined8 local_70;
  ulong *local_68;
  undefined8 local_60;
  uchar *local_58;
  undefined8 local_50;
  uchar *local_48;
  undefined8 local_40;
  uchar *local_38;
  undefined8 local_30;
  uchar *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_158;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_128 = param_11;
    local_127 = param_10;
    local_126 = param_9;
    local_125 = param_8;
    local_120 = param_7;
    local_11c = param_6;
    local_124[0] = param_5;
    local_28 = &local_128;
    local_38 = &local_127;
    local_48 = &local_126;
    local_58 = &local_125;
    local_68 = &local_120;
    local_78 = &local_11c;
    local_88 = local_124;
    local_98 = local_108;
    local_a8 = &local_118;
    local_b8 = &local_114;
    local_c8 = local_110;
    local_d8 = local_108 + 1;
    local_108[1] = 0x3000800;
    local_20 = 1;
    local_30 = 1;
    local_40 = 1;
    local_50 = 1;
    local_60 = 4;
    local_70 = 4;
    local_80 = 1;
    local_90 = 8;
    local_a0 = 4;
    local_b0 = 4;
    local_c0 = 4;
    local_d0 = 8;
    local_118 = param_3;
    local_114 = param_2;
    local_110[0] = param_1;
    local_108[0] = param_4;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_1400279f4,0,0,0xe,local_108 + 2);
  }
  return;
}



===== TraceLoggingUcmConnectorDataDirectionChanged @ 140009654 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorDataDirectionChanged(unsigned __int64,unsigned char,unsigned
   long) */

void __cdecl
TraceLoggingUcmConnectorDataDirectionChanged(__uint64 param_1,uchar param_2,ulong param_3)

{
  undefined1 auStackY_c8 [32];
  uchar local_98 [4];
  ulong local_94;
  __uint64 local_90 [3];
  undefined8 local_78 [4];
  __uint64 *local_58;
  undefined8 local_50;
  __uint64 *local_48;
  undefined8 local_40;
  uchar *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = &local_94;
    local_38 = local_98;
    local_48 = local_90;
    local_58 = local_90 + 1;
    local_90[1] = 0x3000800;
    local_20 = 4;
    local_30 = 1;
    local_40 = 8;
    local_50 = 8;
    local_98[0] = param_2;
    local_94 = param_3;
    local_90[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_1400276b1,0,0,6,local_78);
  }
  return;
}



===== TraceLoggingUcmConnectorGetPolicy @ 140009740 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorGetPolicy(long,unsigned __int64,enum
   _UCM_CONNECTOR_POLICY_TYPE) */

void __cdecl
TraceLoggingUcmConnectorGetPolicy(long param_1,__uint64 param_2,_UCM_CONNECTOR_POLICY_TYPE param_3)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _GUID *in_R9;
  _tlgWrapperByVal<4> local_res20 [2];
  _tlgWrapperByVal<4> local_28 [2];
  _tlgWrapperByVal<8> local_20;
  _tlgWrapperByVal<8> local_18 [3];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_18[0].Value = 0x3000800;
    local_res20[0].Value = param_3;
    local_28[0].Value = param_1;
    local_20.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_140027522,
               (_GUID *)CONCAT44(in_register_00000084,param_3),in_R9,local_18,local_28,&local_20,
               local_res20);
  }
  return;
}



===== TraceLoggingUcmConnectorPdPartnerSourceCaps @ 1400097c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorPdPartnerSourceCaps(long,unsigned __int64,unsigned long,void
   * __ptr64,unsigned short) */

void __cdecl
TraceLoggingUcmConnectorPdPartnerSourceCaps
          (long param_1,__uint64 param_2,ulong param_3,void *param_4,ushort param_5)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _tlgWrapperByVal<4> local_38;
  _tlgWrapperByVal<4> local_34;
  _tlgWrapperByVal<8> local_30;
  _tlgWrapperByVal<8> local_28;
  _tlgWrapperBinary local_20 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_20[0].Size = param_5;
    local_28.Value = 0x3000800;
    local_38.Value = param_3;
    local_34.Value = param_1;
    local_30.Value = param_2;
    local_20[0].Ptr = param_4;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_140027777,
               (_GUID *)CONCAT44(in_register_00000084,param_3),param_4,&local_28,&local_34,&local_30
               ,&local_38,local_20);
  }
  return;
}



===== TraceLoggingUcmConnectorPdSourceCaps @ 140009874 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorPdSourceCaps(long,unsigned __int64,unsigned long,void *
   __ptr64,unsigned short) */

void __cdecl
TraceLoggingUcmConnectorPdSourceCaps
          (long param_1,__uint64 param_2,ulong param_3,void *param_4,ushort param_5)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _tlgWrapperByVal<4> local_38;
  _tlgWrapperByVal<4> local_34;
  _tlgWrapperByVal<8> local_30;
  _tlgWrapperByVal<8> local_28;
  _tlgWrapperBinary local_20 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_20[0].Size = param_5;
    local_28.Value = 0x3000800;
    local_38.Value = param_3;
    local_34.Value = param_1;
    local_30.Value = param_2;
    local_20[0].Ptr = param_4;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::
    Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperBinary>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_140027719,
               (_GUID *)CONCAT44(in_register_00000084,param_3),param_4,&local_28,&local_34,&local_30
               ,&local_38,local_20);
  }
  return;
}



===== TraceLoggingUcmConnectorPowerDirectionChanged @ 140009924 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorPowerDirectionChanged(unsigned __int64,unsigned
   char,unsigned long,unsigned long) */

void __cdecl
TraceLoggingUcmConnectorPowerDirectionChanged
          (__uint64 param_1,uchar param_2,ulong param_3,ulong param_4)

{
  undefined1 auStackY_d8 [32];
  uchar local_a8 [4];
  ulong local_a4;
  ulong local_a0 [2];
  __uint64 local_98 [6];
  __uint64 *local_68;
  undefined8 local_60;
  __uint64 *local_58;
  undefined8 local_50;
  uchar *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = &local_a4;
    local_38 = local_a0;
    local_48 = local_a8;
    local_58 = local_98;
    local_68 = local_98 + 1;
    local_98[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 1;
    local_50 = 8;
    local_60 = 8;
    local_a8[0] = param_2;
    local_a4 = param_4;
    local_a0[0] = param_3;
    local_98[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002762f,0,0,7,local_98 + 2);
  }
  return;
}



===== TraceLoggingUcmConnectorTypeCAttach @ 140009a28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorTypeCAttach(long,unsigned long,unsigned __int64,unsigned
   long,unsigned long,unsigned long) */

void __cdecl
TraceLoggingUcmConnectorTypeCAttach
          (long param_1,ulong param_2,__uint64 param_3,ulong param_4,ulong param_5,ulong param_6)

{
  undefined1 auStackY_108 [32];
  ulong local_d8;
  ulong local_d4;
  ulong local_d0;
  ulong local_cc [3];
  __uint64 local_c0 [3];
  undefined8 local_a8 [4];
  __uint64 *local_88;
  undefined8 local_80;
  ulong *local_78;
  undefined8 local_70;
  ulong *local_68;
  undefined8 local_60;
  __uint64 *local_58;
  undefined8 local_50;
  ulong *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_d8 = param_6;
    local_d4 = param_5;
    local_28 = &local_d8;
    local_38 = &local_d4;
    local_48 = &local_d0;
    local_58 = local_c0;
    local_68 = local_cc;
    local_78 = local_cc + 1;
    local_88 = local_c0 + 1;
    local_cc[1] = 0;
    local_c0[1] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 8;
    local_60 = 4;
    local_70 = 4;
    local_80 = 8;
    local_d0 = param_4;
    local_cc[0] = param_2;
    local_c0[0] = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002796b,0,0,9,local_a8);
  }
  return;
}



===== TraceLoggingUcmConnectorTypeCCurrentAdChanged @ 140009b60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorTypeCCurrentAdChanged(long,unsigned __int64,unsigned long)
    */

void __cdecl
TraceLoggingUcmConnectorTypeCCurrentAdChanged(long param_1,__uint64 param_2,ulong param_3)

{
  undefined4 in_register_0000000c;
  undefined4 in_register_00000084;
  _tlgWrapperByVal<4> local_res8 [6];
  _tlgWrapperByVal<4> local_res20 [2];
  _tlgWrapperByVal<8> local_18;
  _tlgWrapperByVal<8> local_10 [2];
  
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_res20[0].Value = 0;
    local_10[0].Value = 0x3000800;
    local_res8[0].Value = param_3;
    local_18.Value = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>,_tlgWrapperByVal<4>_>
              ((_tlgProvider_t *)CONCAT44(in_register_0000000c,param_1),&DAT_1400278b1,
               (_GUID *)CONCAT44(in_register_00000084,param_3),(_GUID *)0x400000000000,local_10,
               local_res20,&local_18,local_res8);
  }
  return;
}



===== TraceLoggingUcmConnectorTypeCDetach @ 140009be8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmConnectorTypeCDetach(long,unsigned __int64) */

void __cdecl TraceLoggingUcmConnectorTypeCDetach(long param_1,__uint64 param_2)

{
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  __uint64 local_80 [3];
  undefined8 local_68 [4];
  __uint64 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  __uint64 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = local_80;
    local_80[1] = 0x3000800;
    local_38 = local_88;
    local_88[0] = 0;
    local_48 = local_80 + 1;
    local_20 = 8;
    local_30 = 4;
    local_40 = 8;
    local_80[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_14002791e,0,0,5,local_68);
  }
  return;
}



===== TraceLoggingUcmDeviceGetConnectorIds @ 140009cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmDeviceGetConnectorIds(long,unsigned long) */

void __cdecl TraceLoggingUcmDeviceGetConnectorIds(long param_1,ulong param_2)

{
  undefined1 auStackY_a8 [32];
  ulong local_78;
  long local_74;
  undefined8 local_70;
  undefined8 local_68 [4];
  undefined8 *local_48;
  undefined8 local_40;
  long *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = &local_78;
    local_38 = &local_74;
    local_48 = &local_70;
    local_70 = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 8;
    local_78 = param_2;
    local_74 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140027579,0,0,5,local_68);
  }
  return;
}



===== TraceLoggingUcmInitializeDevice @ 140009d94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUcmInitializeDevice(long,unsigned long,enum _WDF_TRI_STATE) */

void __cdecl TraceLoggingUcmInitializeDevice(long param_1,ulong param_2,_WDF_TRI_STATE param_3)

{
  undefined1 auStackY_c8 [32];
  _WDF_TRI_STATE local_98;
  ulong local_94;
  long local_90 [2];
  undefined8 local_88 [2];
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  _WDF_TRI_STATE *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (((5 < DAT_14002a160) && ((_DAT_14002a170 & 0x400000000000) != 0)) &&
     ((DAT_14002a178 & 0x400000000000) == DAT_14002a178)) {
    local_28 = &local_98;
    local_38 = &local_94;
    local_48 = local_90;
    local_58 = local_88;
    local_88[0] = 0x3000800;
    local_20 = 4;
    local_30 = 4;
    local_40 = 4;
    local_50 = 8;
    local_98 = param_3;
    local_94 = param_2;
    local_90[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a160,&DAT_140027ae4,0,0,6,local_78);
  }
  return;
}



===== WPP_RECORDER_SF_Li @ 140009e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Li(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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
               &param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_dPd @ 140009fac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dPd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,4,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 14000a0a0 =====

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



===== WPP_RECORDER_SF_qLiqq @ 14000a1c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLiqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x1e,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x1e,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_qiD @ 14000a300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qiDD @ 14000a458 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qiDLL @ 14000a570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiDLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x3b,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x3b,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qiLL @ 14000a6ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLL
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qiLLL @ 14000a7d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLLL
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,&param_9,
                  4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_qiLLLD @ 14000a978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLLLD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x44,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x44,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qiLD @ 14000aacc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLD
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,&param_9,
                  4,0);
  return;
}



===== WPP_RECORDER_SF_qiLdDDdqq @ 14000ac48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLdDDdqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x1f,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,8,&uStack0000000000000070,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x1f,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,8,&uStack0000000000000070,8,0);
  return;
}



===== WPP_RECORDER_SF_qiLdDLqq @ 14000ae0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLdDLqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x21,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,8,
               &uStack0000000000000068,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x21,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,&uStack0000000000000068,8,0);
  return;
}



===== WPP_RECORDER_SF_qiLdL @ 14000afac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLdL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_qiLdd @ 14000b0e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiLdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x92,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x92,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qicL @ 14000b224 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qicL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,1,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,1,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qidLLLDLLL @ 14000b344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qidLLLDLLL(undefined8 param_1)

{
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
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x96,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x96,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,0);
  return;
}



===== imp_UcmConnectorCableProperties @ 14000b530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
imp_UcmConnectorCableProperties(undefined8 param_1,undefined8 param_2,_UCM_CABLE_PROPERTIES param_3)

{
  _UCMCONNECTOR_CONTEXT *p_Var1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x91,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var1 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiLdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var1->Lock,0);
  if (p_Var1->PortPartnerAttached == '\0') {
    uVar2 = 0xc0000184;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x93,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                          (char)p_Var1->UcmCxCtx->DeviceSelf,(char)(p_Var1->Config).ConnectorId,0x84
                         );
    }
  }
  else {
    p_Var1->CableProperties = param_3;
  }
  ConnectorIndicateStateChangeAndReleaseLock(p_Var1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x94,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return uVar2;
}



===== imp_UcmConnectorChargingStateChanged @ 14000b6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorChargingStateChanged
               (undefined8 param_1,undefined8 param_2,_UCM_CHARGING_STATE param_3)

{
  _UCMCX_CONTEXT **pp_Var1;
  __uint64 _Var2;
  _UCMCONNECTOR_CONTEXT *p_Var3;
  long lVar4;
  undefined1 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x65,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var3 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  pp_Var1 = &p_Var3->UcmCxCtx;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x66,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)(*pp_Var1)->DeviceSelf,(char)(p_Var3->Config).ConnectorId,
                        (char)param_3);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var3->Lock,0);
  _Var2 = (p_Var3->Config).ConnectorId;
  uVar5 = (undefined1)_Var2;
  if (p_Var3->LocalPortPowerRole == UcmPowerRoleSink) {
    if (param_3 == UcmChargingStateInvalid) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x68,
                           &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                           (char)(*pp_Var1)->DeviceSelf,uVar5);
      }
      lVar4 = -0x3ffffff3;
    }
    else {
      (p_Var3->AttachParams).ChargingState = param_3;
      lVar4 = 0;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x67,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                          (char)(*pp_Var1)->DeviceSelf,uVar5,(char)p_Var3->LocalPortPowerRole);
    }
    lVar4 = -0x3ffffe7c;
  }
  ConnectorIndicateStateChangeAndReleaseLock(p_Var3);
  TraceLoggingUcmConnectorChargingStateChanged(lVar4,_Var2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x69,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return lVar4;
}



===== imp_UcmConnectorCreate @ 14000b8f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorCreate
               (undefined8 param_1,WDFDEVICE__ *param_2,ulong *param_3,undefined8 *param_4,
               undefined8 *param_5)

{
  _CAPSTORE_CONNECTOR **pp_Var1;
  _LIST_ENTRY *p_Var2;
  uint *_Src;
  _UCM_CONNECTOR_TYPEC_CONFIG *p_Var3;
  _UCM_CONNECTOR_PD_CONFIG *p_Var4;
  ulong64 uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  int iVar8;
  long lVar9;
  _UCMCX_CONTEXT *p_Var10;
  _UCMCONNECTOR_CONTEXT *p_Var11;
  ulonglong uVar12;
  undefined8 uVar13;
  byte bVar14;
  _CAPSTORE_CONNECTOR *p_Var15;
  undefined8 *puVar16;
  uchar uVar17;
  undefined8 uVar18;
  undefined2 uVar19;
  __uint64 *p_Var20;
  ulong uVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  ulong uVar25;
  ulong uVar26;
  uint uVar27;
  uint uVar28;
  ulong uVar29;
  undefined4 uVar30;
  uint uVar31;
  undefined4 uVar32;
  ulong uVar33;
  ulong uVar34;
  ulong uVar35;
  ulong uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  ulong uVar43;
  undefined4 uVar44;
  ulong local_res18 [2];
  undefined *in_stack_fffffffffffffdb8;
  ulong *puVar45;
  undefined1 uVar46;
  ulong local_1f8;
  uchar local_1f4;
  UCMCONNECTOR__ *local_1f0;
  uint local_1e8;
  uint local_1e4;
  uint local_1e0;
  longlong local_1d8;
  undefined8 local_1d0;
  code *pcStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  UCMCONNECTOR__ *local_1b0;
  undefined8 uStack_1a8;
  undefined *local_1a0;
  ulong local_198;
  ulong local_194;
  WDFMEMORY__ *local_190;
  longlong local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  __uint64 *local_f8;
  WDFMEMORY__ *local_f0;
  undefined8 local_e8;
  code *pcStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  ulong64 uStack_b8;
  longlong local_b0;
  ulong uStack_a8;
  ulong uStack_a4;
  uchar local_a0;
  uchar uStack_9f;
  undefined2 uStack_9e;
  ulong uStack_9c;
  _UCM_PD_ALTERNATE_MODE *p_Stack_98;
  ulong local_90;
  undefined4 uStack_8c;
  
  local_1f0 = (UCMCONNECTOR__ *)0x0;
  local_1a0 = (undefined *)0x0;
  local_c8 = 0;
  local_1d0 = 0;
  pcStack_1c8 = (code *)0x0;
  local_c0 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  uStack_9e = 0;
  local_1b0 = (UCMCONNECTOR__ *)0x0;
  uStack_1a8 = 0;
  uStack_8c = 0;
  local_e8 = 0;
  pcStack_e0 = (code *)0x0;
  local_1f8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_res18[0] = 0;
  local_190 = (WDFMEMORY__ *)0x0;
  local_f0 = (WDFMEMORY__ *)0x0;
  local_198 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffdb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1c,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var10 = (_UCMCX_CONTEXT *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  uVar46 = SUB81(param_2,0);
  if (((param_3 == (ulong *)0x0) && (param_4 == (undefined8 *)0x0)) &&
     (param_5 == (undefined8 *)0x0)) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var10->ConnectorsLock,0);
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,p_Var10->Connectors);
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var10->ConnectorsLock);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1d,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,uVar7);
    }
    PolicyManagerUcmInterfaceReady(param_2);
    iVar8 = 0;
    goto LAB_14000cc39;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLiqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  puVar45 = *(ulong **)(param_3 + 4);
  if (puVar45 == (ulong *)0x0) {
    uVar33 = 0;
    uVar34 = 0;
    uVar35 = 0;
    uVar36 = 0;
    local_188 = 0;
    uVar25 = 0;
    uVar26 = 0;
    uVar27 = 0;
    uVar28 = 0;
    local_160 = 0;
    uVar23 = 0;
    uVar24 = 0;
    local_1e4 = 0;
    local_180 = 0;
    uStack_178 = 0;
    local_1e0 = local_1e0 & 0xffffff00;
    local_170 = 0;
    uStack_168 = 0;
  }
  else {
    local_160 = *(undefined8 *)(puVar45 + 8);
    uVar25 = *puVar45;
    uVar26 = puVar45[1];
    local_180 = *(undefined8 *)puVar45;
    uVar27 = puVar45[2];
    uVar28 = puVar45[3];
    uStack_178 = *(undefined8 *)(puVar45 + 2);
    uVar33 = puVar45[4];
    uVar34 = puVar45[5];
    local_170 = *(undefined8 *)(puVar45 + 4);
    uVar35 = puVar45[6];
    uVar36 = puVar45[7];
    uStack_168 = *(undefined8 *)(puVar45 + 6);
    uVar23 = (undefined4)local_160;
    uVar24 = (undefined4)((ulonglong)local_160 >> 0x20);
    local_188 = *(longlong *)(puVar45 + 6);
    local_1e4 = uVar27;
    local_1e0 = uVar33;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiLdDDdqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  p_Var20 = (__uint64 *)(param_3 + 2);
  _Src = *(uint **)(param_3 + 6);
  uVar29 = 0;
  uVar30 = 0;
  uVar31 = 0;
  uVar32 = 0;
  uVar37 = 0;
  uVar38 = 0;
  uVar39 = 0;
  uVar40 = 0;
  uVar41 = 0;
  uVar42 = 0;
  uVar43 = 0;
  uVar44 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = (_UCM_PD_ALTERNATE_MODE *)0x0;
  local_194 = uVar26;
  if (_Src == (uint *)0x0) {
    local_1d8 = 0;
    uVar21 = 0;
    local_1e8 = 0;
    local_1f4 = '\0';
LAB_14000bdd7:
    if ((char)local_194 == '\0') {
      iVar8 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar19 = 0x22;
LAB_14000bdf3:
        uVar46 = (undefined1)*p_Var20;
LAB_14000bdfb:
        iVar8 = -0x3ffffff3;
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar19,
                           &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,0xd);
      }
      goto LAB_14000cb3b;
    }
    local_1f0 = GetConnectorById(p_Var10,*p_Var20);
    if (local_1f0 == (UCMCONNECTOR__ *)0x0) {
      if (((local_1e4 & 4) != 0) && (local_188 == 0)) {
        iVar8 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x24;
          goto LAB_14000bdf3;
        }
        goto LAB_14000cb3b;
      }
      if (param_4 == (undefined8 *)0x0) {
        param_4 = &local_1d0;
        puVar16 = (undefined8 *)0x0;
        local_1b0 = (UCMCONNECTOR__ *)param_2;
      }
      else {
        if (((WDFDEVICE__ *)param_4[4] != (WDFDEVICE__ *)0x0) &&
           ((WDFDEVICE__ *)param_4[4] != param_2)) {
          iVar8 = -0x3ffffff3;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000cb3b;
          uVar19 = 0x25;
          uVar46 = (undefined1)*(undefined8 *)(param_3 + 2);
          goto LAB_14000bdfb;
        }
        param_4[4] = param_2;
        local_1b0 = (UCMCONNECTOR__ *)0x0;
        puVar16 = &local_1d0;
      }
      uStack_1a8 = 0;
      local_1c0 = 0;
      uStack_1b8 = 0x100000001;
      local_1a0 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
      pcStack_1c8 = ConnectorCleanup;
      local_1d0 = 0x38;
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,param_4,&local_1f0);
      if (iVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x26;
LAB_14000bfaf:
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar19,
                            &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)iVar8);
        }
        goto LAB_14000cb3b;
      }
      if ((puVar16 != (undefined8 *)0x0) &&
         (iVar8 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_1f0,puVar16,0),
         iVar8 < 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x27;
          goto LAB_14000bfaf;
        }
        goto LAB_14000cb3b;
      }
      p_Var11 = (_UCMCONNECTOR_CONTEXT *)
                (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,local_1f0,
                           PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
      p_Var11->AttachCount = 0;
      p_Var11->ChangeCount = 0;
      p_Var11->DisplayPortEntered = '\0';
      p_Var11->ThunderboltEntered = '\0';
      p_Var11->UcmCxCtx = p_Var10;
      p_Var11->PortPartnerAttached = '\0';
      p_Var11->UrsStateUpdatedForAttach = '\0';
      p_Var11->PartnerPdAlternateModes = (WDFMEMORY__ *)0x0;
      p_Var11->PartnerPdAlternateModeCount = 0;
      p_Var11->PdAlternateModesSupported = (WDFMEMORY__ *)0x0;
      p_Var11->PdAlternateModesEnteredCount = 0;
      p_Var11->PdAlternateModesSupportedCount = 0;
      p_Var11->CurrentPdAlternateModesSupportedChangedCount = 0;
      uVar12 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar12 != 0) {
        p_Var11->PartnerSourcePdosCount = '\0';
        p_Var11->PartnerUsbCommunicationCapable = '\0';
        p_Var11->PartnerSourcePdos = (WDFMEMORY__ *)0x0;
        p_Var11->PreviousUrsHardwareEvent = UrsHardwareEventNone;
      }
      p_Var11->DeferUrsStateUpdate = '\0';
      p_Var2 = &p_Var11->PdAlternateModeListHead;
      (p_Var11->PdAlternateModeListHead).Blink = p_Var2;
      p_Var2->Flink = p_Var2;
      local_c8 = 0;
      pcStack_e0 = EvtPdConnStateTimerFunc;
      local_1a0 = (undefined *)0x0;
      local_1c0 = 0;
      local_e8 = 0x28;
      uStack_1a8 = 0;
      local_1b0 = local_1f0;
      pcStack_1c8 = (code *)0x0;
      local_d8 = 0x100000000;
      uStack_d0 = 0;
      local_1d0 = 0x38;
      uStack_1b8 = 0x100000002;
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                        (WdfDriverGlobals,&local_e8,&local_1d0,&p_Var11->TimerForPdConnState);
      if (iVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x28;
          goto LAB_14000bfaf;
        }
        goto LAB_14000cb3b;
      }
      local_1a0 = (undefined *)0x0;
      local_1c0 = 0;
      uStack_1b8 = 0x100000001;
      uStack_1a8 = 0;
      local_1b0 = local_1f0;
      pcStack_1c8 = (code *)0x0;
      local_1d0 = 0x38;
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,0);
      if (iVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x29;
          goto LAB_14000bfaf;
        }
        goto LAB_14000cb3b;
      }
      KeInitializeEvent(&p_Var11->EventDataDirectionChanged,1);
      KeInitializeEvent(&p_Var11->EventPowerDirectionChanged,1,0);
      if (p_Var10->EnablePolicyManagement == '\0') {
        if (uVar21 == 0) {
LAB_14000c3ee:
          if (p_Var10->EnablePolicyManagement != '\0') goto LAB_14000c3f9;
          uStack_178 = CONCAT44(uVar28,(uint)uStack_178);
          goto LAB_14000c8d1;
        }
        local_1a0 = (undefined *)0x0;
        local_1c0 = 0;
        uStack_1a8 = 0;
        local_1b0 = local_1f0;
        pcStack_1c8 = (code *)0x0;
        local_1d0 = 0x38;
        uStack_1b8 = 0x100000001;
        in_stack_fffffffffffffdb8 = (undefined *)((ulonglong)uVar21 << 3);
        iVar8 = (**(code **)(WdfFunctions_01015 + 0x600))
                          (WdfDriverGlobals,&local_1d0,0x200,0,in_stack_fffffffffffffdb8,&local_190,
                           0);
        if (iVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar19 = 0x2c;
            uVar27 = 2;
            bVar14 = 2;
LAB_14000c2de:
            WPP_RECORDER_SF_qiLD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar14,uVar27,uVar19,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                       (char)p_Var11->UcmCxCtx->DeviceSelf,(char)(p_Var11->Config).ConnectorId,
                       (char)uVar21,(char)iVar8);
          }
        }
        else {
          iVar8 = (**(code **)(WdfFunctions_01015 + 0x628))
                            (WdfDriverGlobals,local_190,0,CONCAT44(uVar42,uVar41));
          if (-1 < iVar8) {
            (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var11->Lock,0);
            if (p_Var11->PdAlternateModesSupported != (WDFMEMORY__ *)0x0) {
              (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
            }
            p_Var11->PdAlternateModesSupported = local_190;
            p_Var11->PdAlternateModesSupportedCount = uVar21;
            (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var11->Lock);
            goto LAB_14000c3ee;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar19 = 0x2d;
            bVar14 = 4;
            uVar27 = 7;
            goto LAB_14000c2de;
          }
        }
        goto LAB_14000cb3b;
      }
LAB_14000c3f9:
      pp_Var1 = &p_Var11->CapStoreConn;
      iVar8 = CapStoreFindConnectorById(param_2,*(__uint64 *)(param_3 + 2),pp_Var1);
      if (iVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2e,
                              &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,
                              (char)*(undefined8 *)(param_3 + 2),(char)iVar8);
        }
        goto LAB_14000cb3b;
      }
      lVar9 = CapStoreGetCapabilityUlong(param_2,*pp_Var1,1,local_res18);
      uVar21 = local_res18[0];
      if (-1 < lVar9) {
        if (local_1e4 != local_res18[0]) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_fffffffffffffdb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
            WPP_RECORDER_SF_qiLLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x2f,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,
                       (char)*(undefined8 *)(param_3 + 2),1,(char)local_1e4,(char)local_res18[0]);
          }
          uStack_178 = CONCAT44(uStack_178._4_4_,uVar21);
          local_1e4 = uVar21;
          uVar25 = (ulong)local_180;
          uVar26 = local_180._4_4_;
          uVar27 = uVar21;
          uVar28 = uStack_178._4_4_;
        }
      }
      lVar9 = CapStoreGetCapabilityUlong(param_2,*pp_Var1,2,local_res18);
      uVar21 = local_res18[0];
      if ((lVar9 < 0) || (uStack_178 = CONCAT44(uVar28,(uint)uStack_178), uVar28 == local_res18[0]))
      {
        uStack_178 = CONCAT44(uVar28,(uint)uStack_178);
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_fffffffffffffdb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
          WPP_RECORDER_SF_qiLLL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x30,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,
                     (char)*(undefined8 *)(param_3 + 2),2,(char)uVar28,(char)local_res18[0]);
        }
        uStack_178 = CONCAT44(uVar21,(uint)uStack_178);
        uVar25 = (ulong)local_180;
        uVar26 = local_180._4_4_;
        uVar27 = (uint)uStack_178;
        uVar28 = uVar21;
      }
      p_Var15 = p_Var11->CapStoreConn;
      uVar18 = 3;
      lVar9 = CapStoreGetCapabilityUlong(param_2,p_Var15,3,local_res18);
      uVar21 = local_res18[0];
      if (-1 < lVar9) {
        uVar13 = 0;
        if ((local_1e0 & 0xff) != local_res18[0]) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = WPP_RECORDER_SF_qiLdL
                               (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var15,uVar18,0x31,
                                in_stack_fffffffffffffdb8,uVar46,(char)*(undefined8 *)(param_3 + 2),
                                3,(char)local_1e0,(char)local_res18[0]);
          }
          uVar18 = local_170;
          local_170 = CONCAT71(local_170._1_7_,uVar21 != 0);
          uVar6 = local_170;
          local_170._4_4_ = SUB84(uVar18,4);
          local_1e0 = (uint)CONCAT71((int7)((ulonglong)uVar13 >> 8),uVar21 != 0);
          uVar33 = (ulong)local_170;
          uVar34 = local_170._4_4_;
          uVar35 = (ulong)uStack_168;
          uVar36 = uStack_168._4_4_;
          local_170 = uVar6;
        }
      }
      p_Var15 = p_Var11->CapStoreConn;
      uVar18 = 4;
      lVar9 = CapStoreGetCapabilityUlong(param_2,p_Var15,4,local_res18);
      if (((lVar9 < 0) || (local_1f4 == '\0')) || (local_res18[0] != 0)) {
        uVar22 = local_1e8;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiLdL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var15,uVar18,0x32,
                     in_stack_fffffffffffffdb8,uVar46,(char)*(undefined8 *)(param_3 + 2),4,local_1f4
                     ,0);
        }
        uVar29 = 0;
        uVar30 = 0;
        uVar31 = 0;
        uVar32 = 0;
        uVar37 = 0;
        uVar38 = 0;
        uVar39 = 0;
        uVar40 = 0;
        uVar41 = 0;
        uVar42 = 0;
        uVar43 = 0;
        uVar44 = 0;
        local_158 = 0;
        uStack_150 = 0;
        local_1f4 = '\0';
        local_1d8 = 0;
        uVar22 = 0;
      }
      lVar9 = CapStoreGetCapabilityUlong(param_2,p_Var11->CapStoreConn,5,local_res18);
      uVar21 = local_res18[0];
      if (-1 < lVar9) {
        if (local_1f4 != '\0') {
          if (uVar22 != local_res18[0]) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              in_stack_fffffffffffffdb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
              WPP_RECORDER_SF_qiLLL
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x33,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,
                         (char)*(undefined8 *)(param_3 + 2),5,(char)uVar22,(char)local_res18[0]);
            }
            uStack_150 = CONCAT44(uStack_150._4_4_,uVar21);
            uVar29 = (ulong)local_158;
            uVar30 = local_158._4_4_;
            uVar31 = uVar21;
            uVar32 = uStack_150._4_4_;
          }
        }
      }
      uVar18 = 9;
      lVar9 = CapStoreGetCapabilityUlong(param_2,p_Var11->CapStoreConn,9,local_res18);
      if (-1 < lVar9) {
        uVar17 = (uchar)local_res18[0];
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiLL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar18,0x34,
                     in_stack_fffffffffffffdb8,uVar46,(char)*(undefined8 *)(param_3 + 2),9,uVar17);
        }
        p_Var11->DeferUrsStateUpdate = uVar17;
      }
      uVar18 = 10;
      lVar9 = CapStoreGetCapabilityUlong(param_2,p_Var11->CapStoreConn,10,local_res18);
      if (-1 < lVar9) {
        uVar17 = (uchar)local_res18[0];
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiLL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar18,0x35,
                     in_stack_fffffffffffffdb8,uVar46,(char)*(undefined8 *)(param_3 + 2),10,uVar17);
        }
        p_Var11->HardwareCCDebounce = uVar17;
      }
      puVar45 = &local_198;
      uVar18 = 8;
      lVar9 = CapStoreGetCapabilityMemory(param_2,p_Var11->CapStoreConn,8,&local_f0,puVar45);
      if (-1 < lVar9) {
        if (local_190 != (WDFMEMORY__ *)0x0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        }
        uVar21 = local_198;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiLL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar18,0x36,puVar45,uVar46,
                     (char)*(undefined8 *)(param_3 + 2),8,(char)local_198);
        }
        p_Var11->PdAlternateModesSupported = local_f0;
        p_Var11->CurrentPdAlternateModesSupported = local_f0;
        p_Var11->PdAlternateModesSupportedCount = uVar21;
        p_Var11->CurrentPdAlternateModesSupportedCount = uVar21;
      }
LAB_14000c8d1:
      uVar21 = param_3[1];
      uVar5 = *(ulong64 *)(param_3 + 2);
      (p_Var11->Config).Size = param_3[0];
      *(ulong *)&(p_Var11->Config).field_0x4 = uVar21;
      (p_Var11->Config).ConnectorId = uVar5;
      p_Var3 = *(_UCM_CONNECTOR_TYPEC_CONFIG **)(param_3 + 4);
      p_Var4 = *(_UCM_CONNECTOR_PD_CONFIG **)(param_3 + 6);
      (p_Var11->TypeCConfig).Size = uVar25;
      *(ulong *)&(p_Var11->TypeCConfig).IsSupported = uVar26;
      (p_Var11->TypeCConfig).SupportedOperatingModes = uVar27;
      (p_Var11->TypeCConfig).SupportedPowerSourcingCapabilities = uVar28;
      (p_Var11->PdConfig).Size = uVar29;
      *(undefined4 *)&(p_Var11->PdConfig).IsSupported = uVar30;
      (p_Var11->PdConfig).SupportedPowerRoles = uVar31;
      *(undefined4 *)&(p_Var11->PdConfig).field_0xc = uVar32;
      (p_Var11->Config).TypeCConfig = p_Var3;
      (p_Var11->Config).PdConfig = p_Var4;
      (p_Var11->Config).TypeCConfig = &p_Var11->TypeCConfig;
      *(ulong *)&(p_Var11->TypeCConfig).AudioAccessoryCapable = uVar33;
      *(ulong *)&(p_Var11->TypeCConfig).field_0x14 = uVar34;
      *(ulong *)&(p_Var11->TypeCConfig).EvtSetDataRole = uVar35;
      *(ulong *)((longlong)&(p_Var11->TypeCConfig).EvtSetDataRole + 4) = uVar36;
      (p_Var11->Config).PdConfig = &p_Var11->PdConfig;
      *(undefined4 *)&(p_Var11->PdConfig).EvtSetPowerRole = uVar37;
      *(undefined4 *)((longlong)&(p_Var11->PdConfig).EvtSetPowerRole + 4) = uVar38;
      *(undefined4 *)&(p_Var11->PdConfig).EvtSetPowerLevel = uVar39;
      *(undefined4 *)((longlong)&(p_Var11->PdConfig).EvtSetPowerLevel + 4) = uVar40;
      (p_Var11->TypeCConfig).EvtProtectBrownout =
           (_func___cdecl_long_UCMCONNECTOR___ptr_uchar *)CONCAT44(uVar24,uVar23);
      *(undefined4 *)&(p_Var11->PdConfig).SupportedPdAlternateModes = uVar41;
      *(undefined4 *)((longlong)&(p_Var11->PdConfig).SupportedPdAlternateModes + 4) = uVar42;
      (p_Var11->PdConfig).SupportedPdAlternateModeCount = uVar43;
      *(undefined4 *)&(p_Var11->PdConfig).field_0x2c = uVar44;
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var10->ConnectorsLock,0);
      iVar8 = (**(code **)(WdfFunctions_01015 + 0x78))
                        (WdfDriverGlobals,p_Var10->Connectors,local_1f0);
      local_1f8 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,p_Var10->Connectors);
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var10->ConnectorsLock);
      if (iVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x37;
LAB_14000cb12:
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar19,
                            &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)iVar8);
        }
        goto LAB_14000cb3b;
      }
      p_Var3 = (p_Var11->Config).TypeCConfig;
      uStack_150 = (p_Var11->Config).ConnectorId;
      local_148 = *(longlong *)(p_Var11->WnfState).Data;
      uStack_a8 = p_Var3->SupportedOperatingModes;
      uStack_a4 = p_Var3->SupportedPowerSourcingCapabilities;
      uStack_140._0_4_ = p_Var3->SupportedOperatingModes;
      uStack_140._4_4_ = p_Var3->SupportedPowerSourcingCapabilities;
      local_a0 = p_Var3->AudioAccessoryCapable;
      p_Var4 = (p_Var11->Config).PdConfig;
      local_158 = local_c0;
      uStack_9f = p_Var4->IsSupported;
      uStack_9c = p_Var4->SupportedPowerRoles;
      uStack_130 = p_Var4->SupportedPdAlternateModes;
      local_90 = p_Var4->SupportedPdAlternateModeCount;
      local_138 = CONCAT44(uStack_9c,CONCAT22(uStack_9e,CONCAT11(uStack_9f,local_a0)));
      local_120 = EvtPolicyManagerSetDataRole;
      local_118 = EvtPolicyManagerSetPowerRole;
      local_110 = EvtPolicyManagerSetPowerLevel;
      local_128 = CONCAT44(uStack_8c,local_90);
      local_108 = EvtPolicyManagerProtectBrownout;
      uStack_b8 = uStack_150;
      local_b0 = local_148;
      p_Stack_98 = uStack_130;
      iVar8 = PolicyManagerConnectorCreate
                        (param_2,&local_158,(longlong *)&p_Var11->PolicyManagerConn);
      if (iVar8 < 0) {
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var10->ConnectorsLock,0);
        (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,p_Var10->Connectors,local_1f0);
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var10->ConnectorsLock);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar19 = 0x38;
          goto LAB_14000cb12;
        }
        goto LAB_14000cb3b;
      }
      ConnectorInitializeNotifications(p_Var11);
      *param_5 = local_1f0;
      goto LAB_14000cb83;
    }
    iVar8 = 0x40000000;
    *param_5 = local_1f0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x23,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)*p_Var20,0);
    }
LAB_14000cb88:
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var10->ConnectorsLock,0);
    local_1f8 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,p_Var10->Connectors);
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var10->ConnectorsLock);
  }
  else {
    uVar31 = *_Src;
    if ((uVar31 == 0x30) || (uVar31 == 0x18)) {
      local_f8 = (__uint64 *)(param_3 + 2);
      local_158 = 0x100000030;
      uStack_150 = (ulong64)_Src[2];
      memmove(&local_158,_Src,(ulonglong)uVar31);
      uVar21 = (ulong)uStack_130;
      local_1f4 = local_158._4_1_;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        local_1e8 = (uint)uStack_150;
        local_1d8 = local_148;
        uVar29 = (ulong)local_158;
        uVar30 = local_158._4_4_;
        uVar31 = (uint)uStack_150;
        uVar32 = uStack_150._4_4_;
        uVar37 = (undefined4)local_148;
        uVar38 = local_148._4_4_;
        uVar39 = (undefined4)uStack_140;
        uVar40 = uStack_140._4_4_;
        uVar41 = (undefined4)local_138;
        uVar42 = local_138._4_4_;
        uVar43 = (ulong)uStack_130;
        uVar44 = uStack_130._4_4_;
      }
      else {
        local_1d8 = local_148;
        local_1e8 = (uint)uStack_150;
        WPP_RECORDER_SF_qiLdDLqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        p_Var20 = local_f8;
        uVar29 = (ulong)local_158;
        uVar30 = local_158._4_4_;
        uVar31 = (uint)uStack_150;
        uVar32 = uStack_150._4_4_;
        uVar37 = (undefined4)local_148;
        uVar38 = local_148._4_4_;
        uVar39 = (undefined4)uStack_140;
        uVar40 = uStack_140._4_4_;
        uVar41 = (undefined4)local_138;
        uVar42 = local_138._4_4_;
        uVar43 = (ulong)uStack_130;
        uVar44 = uStack_130._4_4_;
      }
      goto LAB_14000bdd7;
    }
    iVar8 = -0x3ffffffc;
    local_f8 = p_Var20;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiLD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x20,
                 &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar46,(char)*p_Var20,(char)uVar31
                 ,4);
    }
    local_1f4 = (uchar)((ulonglong)local_158 >> 0x20);
    local_1d8 = local_148;
    local_1f8 = 0;
LAB_14000cb3b:
    if (local_1f0 != (UCMCONNECTOR__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      local_1f0 = (UCMCONNECTOR__ *)0x0;
    }
LAB_14000cb83:
    if (local_1f8 == 0) goto LAB_14000cb88;
  }
  TraceLoggingUcmConnectorCreate
            (iVar8,local_1f8,*param_3,*(__uint64 *)(param_3 + 2),(uchar)local_194,local_1e4,
             uStack_178._4_4_,(uchar)local_1e0,local_1f4,local_188 != 0,local_1d8 != 0);
LAB_14000cc39:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x39,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar8;
}



===== imp_UcmConnectorDataDirectionChanged @ 14000ccc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void imp_UcmConnectorDataDirectionChanged
               (undefined8 param_1,undefined8 param_2,uchar param_3,_UCM_DATA_ROLE param_4)

{
  __uint64 _Var1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  WDFWAITLOCK__ *pWVar3;
  undefined8 uVar4;
  undefined *in_stack_ffffffffffffffb8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x5a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  uVar4 = 0;
  pWVar3 = p_Var2->Lock;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals);
  _Var1 = (p_Var2->Config).ConnectorId;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qicL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,uVar4,0x5b,
               in_stack_ffffffffffffffb8,(char)p_Var2->UcmCxCtx->DeviceSelf,(char)_Var1,param_3,
               (char)param_4);
  }
  if (p_Var2->PortPartnerAttached == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x5d,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var2->UcmCxCtx->DeviceSelf,(char)(p_Var2->Config).ConnectorId);
    }
  }
  else if (param_3 != '\0') {
    p_Var2->LocalPortDataRole = param_4;
    if (param_4 == UcmDataRoleDfp) {
      (p_Var2->AttachParams).Partner = UcmTypeCPartnerUfp;
    }
    else if (param_4 == UcmDataRoleUfp) {
      (p_Var2->AttachParams).Partner = UcmTypeCPartnerDfp;
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x5c,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)param_4,
                         (char)(p_Var2->Config).ConnectorId);
    }
    UpdateUrsState(p_Var2);
  }
  KeSetEvent(&p_Var2->EventDataDirectionChanged,0,0);
  ConnectorIndicateStateChangeAndReleaseLock(p_Var2);
  TraceLoggingUcmConnectorDataDirectionChanged(_Var1,param_3,param_4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x5e,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return;
}



===== imp_UcmConnectorGetPolicy @ 14000cf10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorGetPolicy(undefined8 param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  undefined1 uVar2;
  long lVar3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  _UCM_CONNECTOR_POLICY_TYPE _Var5;
  undefined *puVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6c,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  puVar6 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  if ((param_3 != (int *)0x0) && (*param_3 == 0x10)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar6 = (undefined *)0x2;
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x6d,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                          (char)p_Var4->UcmCxCtx->DeviceSelf,(char)(p_Var4->Config).ConnectorId,
                          (char)param_3[1]);
    }
    iVar1 = param_3[1];
    if (iVar1 < 7) {
      if (iVar1 == 6) {
        lVar3 = PolicyGetPdAlternateModes
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODES **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 1) {
        lVar3 = PolicyGetTypeCOperatingMode
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_TYPEC_OPERATING_MODE **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 2) {
        lVar3 = PolicyGetTypeCSourceCurrentLevel
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_TYPEC_SOURCE_CURRENT_LEVEL **)
                                   (param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 3) {
        lVar3 = PolicyGetPdSourceCapabilities
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_PD_SOURCE_CAPABILITIES **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 4) {
        lVar3 = PolicyGetPdSinkCapabilities
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_PD_SINK_CAPABILITIES **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 5) {
        lVar3 = PolicyGetPdRequestDataObject
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_PD_REQUEST_DATA_OBJECT **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
    }
    else {
      if (iVar1 == 7) {
        lVar3 = PolicyGetPdAlternateModeToNegotiate
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODE_TO_NEGOTIATE **)
                                   (param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 8) {
        lVar3 = PolicyGetSupportedPowerRoles
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_SUPPORTED_POWER_ROLES **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 9) {
        lVar3 = PolicyGetPdEnabled(p_Var4,*(_UCM_CONNECTOR_POLICY_PD_ENABLED **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 10) {
        lVar3 = PolicyGetDeferUrsStateUpdate
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_DEFER_URS_STATE_UPDATE **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
      if (iVar1 == 0xb) {
        lVar3 = PolicyGetHardwareCCDebounce
                          (p_Var4,*(_UCM_CONNECTOR_POLICY_HARDWARE_CC_DEBOUNCE **)(param_3 + 2));
        goto LAB_14000d0d4;
      }
    }
  }
  lVar3 = -0x3ffffff3;
LAB_14000d0d4:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (param_3 == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (undefined1)param_3[1];
    }
    WPP_RECORDER_SF_iLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar6,0x6e,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)(p_Var4->Config).ConnectorId,uVar2,(char)lVar3);
  }
  if (param_3 == (int *)0x0) {
    _Var5 = UcmConnectorPolicyUndefined;
  }
  else {
    _Var5 = param_3[1];
  }
  TraceLoggingUcmConnectorGetPolicy(lVar3,(p_Var4->Config).ConnectorId,_Var5);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6f,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return lVar3;
}



===== imp_UcmConnectorOvercurrent @ 14000d190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 imp_UcmConnectorOvercurrent(undefined8 param_1,undefined8 param_2)

{
  _UCMCX_CONTEXT **pp_Var1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  undefined4 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x98,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  pp_Var1 = &p_Var2->UcmCxCtx;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x99,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)(*pp_Var1)->DeviceSelf
                       ,(char)(p_Var2->Config).ConnectorId);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
  if (p_Var2->PortPartnerAttached == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x9a,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)(*pp_Var1)->DeviceSelf,0x84);
    }
  }
  else {
    if (p_Var2->LocalPortPowerRole == UcmPowerRoleSource) {
      p_Var2->Overcurrent = '\x01';
      ConnectorIndicateStateChangeAndReleaseLock(p_Var2);
      uVar3 = 0;
      goto LAB_14000d346;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x9b,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                          (char)(*pp_Var1)->DeviceSelf,(char)p_Var2->LocalPortPowerRole,0x84);
    }
  }
  uVar3 = 0xc0000184;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var2->Lock);
LAB_14000d346:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x9c,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return uVar3;
}



===== imp_UcmConnectorPartnerPdAlternateModes @ 14000d3a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int imp_UcmConnectorPartnerPdAlternateModes
              (undefined8 param_1,undefined8 param_2,_UCM_PD_ALTERNATE_MODE *param_3,uint param_4)

{
  _UCMCX_CONTEXT **pp_Var1;
  undefined1 uVar2;
  int iVar3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  byte bVar5;
  _UCM_PD_ALTERNATE_MODE _Var6;
  uint uVar7;
  undefined2 uVar8;
  WDFMEMORY__ *local_res18;
  undefined1 uVar9;
  _UCM_PD_ALTERNATE_MODE local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  _Var6.SVID = 0;
  _Var6._2_2_ = 0;
  _Var6.Mode = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x70,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  local_res18 = (WDFMEMORY__ *)0x0;
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  pp_Var1 = &p_Var4->UcmCxCtx;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x71,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)(*pp_Var1)->DeviceSelf,(char)(p_Var4->Config).ConnectorId,
                        (char)param_4);
  }
  local_68.SVID = 0;
  local_68._2_2_ = 0;
  local_68.Mode = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock,0);
  if ((param_3 == (_UCM_PD_ALTERNATE_MODE *)0x0) || (param_4 == 0)) {
    iVar3 = -0x3ffffff3;
  }
  else if (p_Var4->PortPartnerAttached == '\0') {
    iVar3 = -0x3ffffe7c;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x72,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                          (char)(*pp_Var1)->DeviceSelf,(char)(p_Var4->Config).ConnectorId,0x84);
    }
  }
  else {
    if ((*pp_Var1)->EnablePolicyManagement != '\0') {
      PolicyPreparePdAlternateModeToNegotiate(p_Var4,param_3,param_4,&local_68);
      _Var6 = local_68;
    }
    uStack_48 = 0x100000001;
    local_60 = CONCAT44(local_60._4_4_,0x38);
    local_40 = param_2;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_60,0x200,0,(ulonglong)param_4 << 3,&local_res18,0);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x73;
        uVar9 = (undefined1)(p_Var4->Config).ConnectorId;
        uVar2 = SUB81(p_Var4->UcmCxCtx->DeviceSelf,0);
        uVar7 = 2;
        bVar5 = 2;
LAB_14000d5f5:
        WPP_RECORDER_SF_qiLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,uVar7,uVar8,
                   &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar2,uVar9,(char)param_4,
                   (char)iVar3);
      }
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x628))
                        (WdfDriverGlobals,local_res18,0,param_3,(ulonglong)param_4 << 3);
      if (-1 < iVar3) {
        if (p_Var4->PartnerPdAlternateModes != (WDFMEMORY__ *)0x0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        }
        p_Var4->PartnerPdAlternateModes = local_res18;
        p_Var4->PartnerPdAlternateModeCount = param_4;
        if (p_Var4->UcmCxCtx->EnablePolicyManagement != '\0') {
          p_Var4->PolicyPreparedPdAlternateModeToNegotiate = _Var6;
        }
        goto LAB_14000d6fe;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = (undefined1)(p_Var4->Config).ConnectorId;
        uVar8 = 0x74;
        bVar5 = 4;
        uVar7 = 7;
        uVar2 = SUB81(p_Var4->UcmCxCtx->DeviceSelf,0);
        goto LAB_14000d5f5;
      }
    }
  }
  if (local_res18 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_res18 = (WDFMEMORY__ *)0x0;
  }
LAB_14000d6fe:
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x75,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar3;
}



===== imp_UcmConnectorPdAlternateModeDiscoveryDone @ 14000d770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 imp_UcmConnectorPdAlternateModeDiscoveryDone(undefined8 param_1,undefined8 param_2)

{
  _UCMCONNECTOR_CONTEXT *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x7b,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var1 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x7c,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                       (char)p_Var1->UcmCxCtx->DeviceSelf,(char)(p_Var1->Config).ConnectorId);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var1->Lock,0);
  if ((p_Var1->DeferUrsStateUpdate != '\0') && (p_Var1->UrsStateUpdatedForAttach == '\0')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x7d,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var1->UcmCxCtx->DeviceSelf,(char)(p_Var1->Config).ConnectorId);
    }
    UpdateUrsState(p_Var1);
    p_Var1->UrsStateUpdatedForAttach = '\x01';
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var1->Lock);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x7e,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return 0;
}



===== imp_UcmConnectorPdAlternateModeEntered @ 14000d930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000dc1f) */

int imp_UcmConnectorPdAlternateModeEntered(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong64 *puVar1;
  __uint64 _Var2;
  code *pcVar3;
  int iVar4;
  _UCMCONNECTOR_CONTEXT *p_Var5;
  _LIST_ENTRY *p_Var6;
  undefined8 uVar7;
  _LIST_ENTRY *p_Var8;
  ushort uVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  uint uStackX_1c;
  _LIST_ENTRY *local_res20;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  undefined *in_stack_ffffffffffffff38;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res20 = (_LIST_ENTRY *)0x0;
  local_48 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff38 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x7f,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  uVar7 = param_2;
  puVar11 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
  p_Var5 = (_UCMCONNECTOR_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  puVar1 = &(p_Var5->Config).ConnectorId;
  uStackX_1c = (uint)((ulonglong)param_3 >> 0x20);
  uVar9 = (ushort)param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar11,0x80,
               in_stack_ffffffffffffff38,(char)p_Var5->UcmCxCtx->DeviceSelf,(char)*puVar1,
               (char)param_3,(char)((ulonglong)param_3 >> 0x20));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var5->Lock,0);
  _Var2 = *puVar1;
  if (p_Var5->PortPartnerAttached == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x81,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
    }
  }
  else {
    if (p_Var5->PdAlternateModesEnteredCount <= p_Var5->PartnerPdAlternateModeCount) {
      local_78 = CONCAT44(local_78._4_4_,0x38);
      uStack_60 = 0x100000001;
      local_58 = param_2;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,&local_78,0x200,0);
      puVar10 = auStackY_e8;
      if (iVar4 < 0) {
        puVar10 = auStackY_e8;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x83,
                             &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)*puVar1,
                             (char)iVar4);
          puVar10 = auStackY_e8;
        }
      }
      else {
        p_Var6 = &p_Var5->PdAlternateModeListHead;
        uRam0000000000000000 = 0;
        uRam0000000000000004 = 0;
        uRam0000000000000008 = 0;
        uRam000000000000000c = 0;
        p_Var8 = (p_Var5->PdAlternateModeListHead).Blink;
        uRam0000000000000010 = param_3;
        if (p_Var8->Flink != p_Var6) {
          p_Var6 = (_LIST_ENTRY *)0x3;
          pcVar3 = (code *)swi(0x29);
          local_res20 = (_LIST_ENTRY *)(*pcVar3)();
          puVar10 = auStackY_e0;
        }
        local_res20->Flink = p_Var6;
        local_res20->Blink = p_Var8;
        p_Var8->Flink = local_res20;
        p_Var6->Blink = local_res20;
        if (uVar9 == 0xff01) {
          p_Var5->DisplayPortEntered = '\x01';
        }
        if (uVar9 == 0x8087) {
          p_Var5->ThunderboltEntered = '\x01';
        }
        p_Var5->PdAlternateModesEnteredCount = p_Var5->PdAlternateModesEnteredCount + 1;
      }
      goto LAB_14000dc0a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x82,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)_Var2,
                          (char)p_Var5->PdAlternateModesEnteredCount,
                          (char)p_Var5->PartnerPdAlternateModeCount);
    }
  }
  iVar4 = -0x3ffffff3;
  puVar10 = auStackY_e8;
LAB_14000dc0a:
  *(undefined8 *)(puVar10 + -8) = 0x14000dc12;
  ConnectorIndicateStateChangeAndReleaseLock(p_Var5);
  *(undefined8 *)(puVar10 + -8) = 0x14000dc4e;
  TraceLoggingUcmConnectorAlternateModeEntered(iVar4,_Var2,uVar9,uStackX_1c);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar10 + 0x20) = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    *(undefined8 *)(puVar10 + -8) = 0x14000dc88;
    WPP_RECORDER_SF_(uVar7,5,2,0x84,*(undefined8 *)(puVar10 + 0x20));
  }
  return iVar4;
}



===== imp_UcmConnectorPdAlternateModeExited @ 14000dcb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorPdAlternateModeExited(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _LIST_ENTRY *p_Var1;
  __uint64 _Var2;
  _LIST_ENTRY *p_Var3;
  _LIST_ENTRY *p_Var4;
  _UCMCX_CONTEXT *p_Var5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  _UCMCONNECTOR_CONTEXT *p_Var9;
  _LIST_ENTRY *p_Var10;
  ushort uVar11;
  undefined1 *puVar12;
  long lVar13;
  undefined *puVar14;
  _LIST_ENTRY *p_Var15;
  bool bVar16;
  uint uStackX_1c;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined *in_stack_ffffffffffffffa8;
  
  lVar13 = 0;
  bVar8 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x85,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  puVar14 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
  p_Var9 = (_UCMCONNECTOR_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uStackX_1c = (uint)((ulonglong)param_3 >> 0x20);
  uVar11 = (ushort)param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,puVar14,0x86,
               in_stack_ffffffffffffffa8,(char)p_Var9->UcmCxCtx->DeviceSelf,
               (char)(p_Var9->Config).ConnectorId,(char)param_3,(char)((ulonglong)param_3 >> 0x20));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var9->Lock,0);
  _Var2 = (p_Var9->Config).ConnectorId;
  if (p_Var9->PdAlternateModesEnteredCount == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x87,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var9->UcmCxCtx->DeviceSelf,(char)_Var2);
    }
    lVar13 = -0x3ffffff3;
    puVar12 = auStackY_78;
  }
  else {
    p_Var1 = &p_Var9->PdAlternateModeListHead;
    p_Var10 = p_Var1->Flink;
    puVar12 = auStackY_78;
    p_Var15 = p_Var10->Flink;
    if (p_Var1 != p_Var10) {
      do {
        if ((*(ushort *)&p_Var10[1].Flink == uVar11) &&
           (*(uint *)((longlong)&p_Var10[1].Flink + 4) == uStackX_1c)) {
          p_Var3 = p_Var10->Flink;
          if ((p_Var3->Blink != p_Var10) || (p_Var4 = p_Var10->Blink, p_Var4->Flink != p_Var10)) {
            pcVar7 = (code *)swi(0x29);
            (*pcVar7)(3);
            puVar12 = auStackY_70;
            goto LAB_14000de98;
          }
          p_Var4->Flink = p_Var3;
          bVar8 = true;
          p_Var3->Blink = p_Var4;
        }
        bVar16 = p_Var1 != p_Var15;
        p_Var10 = p_Var15;
        p_Var15 = p_Var15->Flink;
      } while (bVar16);
      puVar12 = auStackY_78;
      if (bVar8) {
        p_Var9->PdAlternateModesEnteredCount = p_Var9->PdAlternateModesEnteredCount - 1;
        if (uVar11 == 0xff01) {
          p_Var9->DisplayPortEntered = '\0';
        }
        puVar12 = auStackY_78;
        if (uVar11 == 0x8087) {
          p_Var9->ThunderboltEntered = '\0';
          puVar12 = auStackY_78;
        }
        goto LAB_14000deed;
      }
    }
LAB_14000de98:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      p_Var5 = p_Var9->UcmCxCtx;
      *(ulong64 *)(puVar12 + 0x30) = (p_Var9->Config).ConnectorId;
      *(WDFDEVICE__ **)(puVar12 + 0x28) = p_Var5->DeviceSelf;
      *(undefined **)(puVar12 + 0x20) = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined8 *)(puVar12 + -8) = 0x14000dee8;
      WPP_RECORDER_SF_qi(uVar6,2,2,0x88,*(undefined8 *)(puVar12 + 0x20),puVar12[0x28],puVar12[0x30])
      ;
    }
    lVar13 = -0x3ffffddb;
  }
LAB_14000deed:
  *(undefined8 *)(puVar12 + -8) = 0x14000def5;
  ConnectorIndicateStateChangeAndReleaseLock(p_Var9);
  *(undefined8 *)(puVar12 + -8) = 0x14000df06;
  TraceLoggingUcmConnectorAlternateModeExited(lVar13,_Var2,uVar11,uStackX_1c);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar12 + 0x20) = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    *(undefined8 *)(puVar12 + -8) = 0x14000df40;
    WPP_RECORDER_SF_(uVar6,5,2,0x89,*(undefined8 *)(puVar12 + 0x20));
  }
  return lVar13;
}



===== imp_UcmConnectorPdAlternateModeHardwareConfigured @ 14000df70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorPdAlternateModeHardwareConfigured
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _LIST_ENTRY *p_Var1;
  __uint64 _Var2;
  bool bVar3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  _LIST_ENTRY *p_Var5;
  _LIST_ENTRY *p_Var6;
  long lVar7;
  undefined *puVar8;
  undefined2 uVar9;
  bool bVar10;
  uint uStackX_1c;
  undefined *in_stack_ffffffffffffffa8;
  undefined1 uVar11;
  
  lVar7 = 0;
  bVar3 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x8a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  puVar8 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uStackX_1c = (uint)((ulonglong)param_3 >> 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,puVar8,0x8b,
               in_stack_ffffffffffffffa8,(char)p_Var4->UcmCxCtx->DeviceSelf,
               (char)(p_Var4->Config).ConnectorId,(char)param_3,(char)((ulonglong)param_3 >> 0x20));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock,0);
  _Var2 = (p_Var4->Config).ConnectorId;
  uVar11 = (undefined1)_Var2;
  if (p_Var4->PortPartnerAttached == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x8c;
LAB_14000e09f:
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar9,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var4->UcmCxCtx->DeviceSelf,uVar11);
    }
  }
  else {
    if (p_Var4->PdAlternateModesEnteredCount != 0) {
      p_Var1 = &p_Var4->PdAlternateModeListHead;
      p_Var5 = p_Var1->Flink;
      p_Var6 = p_Var5->Flink;
      if (p_Var1 != p_Var5) {
        do {
          if ((*(ushort *)&p_Var5[1].Flink == (ushort)param_3) &&
             (*(uint *)((longlong)&p_Var5[1].Flink + 4) == uStackX_1c)) {
            bVar3 = true;
          }
          bVar10 = p_Var1 != p_Var6;
          p_Var5 = p_Var6;
          p_Var6 = p_Var6->Flink;
        } while (bVar10);
        if (bVar3) goto LAB_14000e19d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x8e,
                           &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                           (char)p_Var4->UcmCxCtx->DeviceSelf,uVar11);
      }
      lVar7 = -0x3ffffddb;
      goto LAB_14000e19d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x8d;
      goto LAB_14000e09f;
    }
  }
  lVar7 = -0x3ffffff3;
LAB_14000e19d:
  if ((p_Var4->DeferUrsStateUpdate != '\0') && (p_Var4->UrsStateUpdatedForAttach == '\0')) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x8f,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var4->UcmCxCtx->DeviceSelf,(char)(p_Var4->Config).ConnectorId);
    }
    UpdateUrsState(p_Var4);
    p_Var4->UrsStateUpdatedForAttach = '\x01';
  }
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  TraceLoggingUcmConnectorAlternateModeHardwareConfigured(lVar7,_Var2,(ushort)param_3,uStackX_1c);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x90,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return lVar7;
}



===== imp_UcmConnectorPdAlternateModesSupportedChanged @ 14000e280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int imp_UcmConnectorPdAlternateModesSupportedChanged
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  ulong64 *puVar1;
  _UCMCX_CONTEXT **pp_Var2;
  int iVar3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  undefined1 uVar5;
  WDFMEMORY__ *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x76,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  local_68 = (WDFMEMORY__ *)0x0;
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  puVar1 = &(p_Var4->Config).ConnectorId;
  pp_Var2 = &p_Var4->UcmCxCtx;
  uVar5 = (undefined1)param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x77,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)(*pp_Var2)->DeviceSelf,(char)*puVar1,uVar5);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock,0);
  if (param_4 == 0) {
    if (p_Var4->CurrentPdAlternateModesSupported != (WDFMEMORY__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      p_Var4->CurrentPdAlternateModesSupported = (WDFMEMORY__ *)0x0;
    }
    p_Var4->CurrentPdAlternateModesSupportedCount = 0;
    iVar3 = 0;
LAB_14000e592:
    p_Var4->CurrentPdAlternateModesSupportedChangedCount =
         p_Var4->CurrentPdAlternateModesSupportedChangedCount + 1;
  }
  else {
    local_60 = CONCAT44(local_60._4_4_,0x38);
    uStack_48 = 0x100000001;
    local_40 = param_2;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_60,0x200,0,(ulonglong)param_4 << 3,&local_68,0);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qiLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x78,
                   &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)(*pp_Var2)->DeviceSelf,
                   (char)*puVar1,uVar5,(char)iVar3);
      }
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x628))
                        (WdfDriverGlobals,local_68,0,param_3,(ulonglong)param_4 << 3);
      if (-1 < iVar3) {
        if (p_Var4->CurrentPdAlternateModesSupported != (WDFMEMORY__ *)0x0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        }
        p_Var4->CurrentPdAlternateModesSupported = local_68;
        p_Var4->CurrentPdAlternateModesSupportedCount = param_4;
        goto LAB_14000e592;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qiLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x79,
                   &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)(*pp_Var2)->DeviceSelf,
                   (char)*puVar1,uVar5,(char)iVar3);
      }
    }
    if (local_68 != (WDFMEMORY__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      local_68 = (WDFMEMORY__ *)0x0;
    }
  }
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x7a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar3;
}



===== imp_UcmConnectorPdConnectionStateChanged @ 14000e610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorPdConnectionStateChanged
               (undefined8 param_1,undefined8 param_2,
               _UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS *param_3)

{
  long lVar1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  uchar local_res20 [8];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x43,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiLLLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,p_Var2->TimerForPdConnState,1);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
  local_res20[0] = '\x01';
  lVar1 = UcmConnectorPdConnectionStateChangedInternal(p_Var2,param_3,local_res20);
  if (local_res20[0] != '\0') {
    ConnectorIndicateStateChangeAndReleaseLock(p_Var2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x45,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return lVar1;
}



===== imp_UcmConnectorPdPartnerSourceCaps @ 14000e7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorPdPartnerSourceCaps
               (undefined8 param_1,undefined8 param_2,_UCM_PD_POWER_DATA_OBJECT *param_3,
               byte param_4)

{
  ulong64 *puVar1;
  uint uVar2;
  int iVar3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  ulonglong uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  _UCM_PD_POWER_DATA_OBJECT *p_Var9;
  undefined2 uVar10;
  longlong lVar11;
  uint uVar12;
  longlong lVar13;
  undefined1 uVar14;
  WDFMEMORY__ *local_78;
  undefined8 local_70;
  ulong64 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_30 = 0;
  local_78 = (WDFMEMORY__ *)0x0;
  local_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4b,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  puVar1 = &(p_Var4->Config).ConnectorId;
  uVar12 = (uint)param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var4->UcmCxCtx,2,0x4c,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)p_Var4->UcmCxCtx->DeviceSelf,(char)*puVar1,param_4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock,0);
  local_68 = *puVar1;
  if (param_4 == 0) {
    iVar3 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0x4d;
LAB_14000e8f3:
      iVar3 = -0x3ffffff3;
      uVar14 = 0xd;
LAB_14000e8f7:
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar10,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar14);
    }
  }
  else if (param_3->Ul < 0x40000000) {
    local_60 = CONCAT44(local_60._4_4_,0x38);
    puVar7 = &local_60;
    uStack_48 = 0x100000001;
    uVar8 = 0x200;
    lVar11 = (ulonglong)param_4 << 2;
    lVar13 = lVar11;
    local_40 = param_2;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,puVar7,0x200,0,lVar11,&local_78,&local_70);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,uVar8,0x4f,lVar13,
                            param_4,(char)lVar11,(char)iVar3);
      }
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,local_78,0,param_3,lVar11);
      if (-1 < iVar3) {
        if (p_Var4->PartnerSourcePdos != (WDFMEMORY__ *)0x0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        }
        p_Var4->PartnerSourcePdos = local_78;
        p_Var4->PartnerSourcePdosCount = param_4;
        uVar5 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 != 0) {
          p_Var4->PartnerUsbCommunicationCapable = '\x01';
          uVar6 = 0;
          if (param_4 != 0) {
            p_Var9 = (_UCM_PD_POWER_DATA_OBJECT *)&param_3->Ul;
            do {
              uVar2 = p_Var9->Ul;
              if ((uVar2 < 0x40000000) && ((uVar2 & 0xffc00) == 0x19000)) {
                if ((uVar2 >> 0x1a & 1) == 0) {
                  p_Var4->PartnerUsbCommunicationCapable = '\0';
                  uVar6 = param_3[uVar6].Ul;
                  if ((uVar6 >> 0x19 & 1) != 0) {
                    TraceLoggingDetectedPortPartnerDrdWithNoUsbData
                              (p_Var4->UcmCxCtx->PrivateGlobals->IsClientUcmUcsiCx,*puVar1,
                               p_Var4->PreviousUrsHardwareEvent,(byte)(uVar6 >> 0x1d) & 1,uVar6,
                               p_Var4->LocalPortPowerRole,p_Var4->LocalPortDataRole,
                               (p_Var4->AttachParams).Partner);
                  }
                }
                break;
              }
              uVar6 = uVar6 + 1;
              p_Var9 = p_Var9 + 1;
            } while (uVar6 < uVar12);
          }
        }
        UcmDumpPdos(param_3,uVar12,*puVar1,'\x01','\x01');
        if (p_Var4->UcmCxCtx->EnablePolicyManagement != '\0') {
          PolicyPrepareRdo(p_Var4,param_3,uVar12,&p_Var4->PolicyPreparedPdRequestDataObject);
        }
        uVar5 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
        if (((((int)uVar5 != 0) && (p_Var4->UcmCxCtx->PrivateGlobals->IsClientUcmUcsiCx != '\0')) &&
            (p_Var4->PreviousUrsHardwareEvent == UrsHardwareEventPortTypeDfp)) &&
           (p_Var4->PartnerUsbCommunicationCapable == '\0')) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x51,
                               &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                               (char)p_Var4->UcmCxCtx->DeviceSelf,(char)*puVar1);
          }
          UpdateUrsState(p_Var4);
        }
        goto LAB_14000ebf4;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0x50;
        uVar14 = (undefined1)iVar3;
        goto LAB_14000e8f7;
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0x4e;
      goto LAB_14000e8f3;
    }
  }
  if (local_78 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_78 = (WDFMEMORY__ *)0x0;
  }
LAB_14000ebf4:
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  TraceLoggingUcmConnectorPdPartnerSourceCaps(iVar3,local_68,uVar12,param_3,(ushort)param_4 << 2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x52,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar3;
}



===== imp_UcmConnectorPdSourceCaps @ 14000ec90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmConnectorPdSourceCaps(undefined8 param_1,undefined8 param_2,uint *param_3,byte param_4)

{
  int iVar1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  longlong lVar7;
  undefined1 uVar8;
  WDFMEMORY__ *local_78;
  undefined8 local_70;
  ulong64 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_30 = 0;
  local_78 = (WDFMEMORY__ *)0x0;
  local_70 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x53,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var2->UcmCxCtx,2,0x54,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)p_Var2->UcmCxCtx->DeviceSelf,(char)(p_Var2->Config).ConnectorId,
                        param_4);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
  local_68 = (p_Var2->Config).ConnectorId;
  if (param_4 == 0) {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x55;
LAB_14000eddd:
      iVar1 = -0x3ffffff3;
      uVar8 = 0xd;
LAB_14000ede1:
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar6,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,uVar8);
    }
  }
  else if (*param_3 < 0x40000000) {
    local_60 = CONCAT44(local_60._4_4_,0x38);
    puVar3 = &local_60;
    uStack_48 = 0x100000001;
    uVar5 = 0x200;
    lVar4 = (ulonglong)param_4 << 2;
    lVar7 = lVar4;
    local_40 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,puVar3,0x200,0,lVar4,&local_78,&local_70);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar3,uVar5,0x57,lVar7,
                            param_4,(char)lVar4,(char)iVar1);
      }
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,local_78,0,param_3,lVar4);
      if (-1 < iVar1) {
        if (p_Var2->SourcePdos != (WDFMEMORY__ *)0x0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        }
        p_Var2->SourcePdos = local_78;
        p_Var2->SourcePdosCount = param_4;
        goto LAB_14000ef84;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x58;
        uVar8 = (undefined1)iVar1;
        goto LAB_14000ede1;
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x56;
      goto LAB_14000eddd;
    }
  }
  if (local_78 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_78 = (WDFMEMORY__ *)0x0;
  }
LAB_14000ef84:
  ConnectorIndicateStateChangeAndReleaseLock(p_Var2);
  TraceLoggingUcmConnectorPdSourceCaps(iVar1,local_68,(uint)param_4,param_3,(ushort)param_4 << 2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x59,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar1;
}



===== imp_UcmConnectorPowerDirectionChanged @ 14000f020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void imp_UcmConnectorPowerDirectionChanged
               (undefined8 param_1,undefined8 param_2,uchar param_3,_UCM_POWER_ROLE param_4)

{
  _UCMCX_CONTEXT **pp_Var1;
  _UCM_POWER_ROLE _Var2;
  __uint64 _Var3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined *in_stack_ffffffffffffffa8;
  undefined1 uVar7;
  undefined1 uVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x5f,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  puVar5 = PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150;
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  pp_Var1 = &p_Var4->UcmCxCtx;
  uVar8 = (undefined1)param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qicL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,puVar5,0x60,
               in_stack_ffffffffffffffa8,(char)(*pp_Var1)->DeviceSelf,
               (char)(p_Var4->Config).ConnectorId,param_3,uVar8);
  }
  uVar6 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock);
  _Var3 = (p_Var4->Config).ConnectorId;
  _Var2 = p_Var4->LocalPortPowerRole;
  uVar7 = (undefined1)_Var3;
  if (p_Var4->PortPartnerAttached == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,99,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)(*pp_Var1)->DeviceSelf,uVar7);
    }
  }
  else if (param_3 != '\0') {
    if (_Var2 == param_4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x62,
                            &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                            (char)(*pp_Var1)->DeviceSelf,uVar7,uVar8);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qiLL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar6,0x61,in_stack_ffffffffffffffa8
                   ,(char)(*pp_Var1)->DeviceSelf,uVar7,(char)_Var2,uVar8);
      }
      p_Var4->LocalPortPowerRole = param_4;
      p_Var4->PdConnState = UcmPdConnStateNegotiationFailed;
      UpdateCadState(p_Var4);
    }
  }
  KeSetEvent(&p_Var4->EventPowerDirectionChanged,0,0);
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  TraceLoggingUcmConnectorPowerDirectionChanged(_Var3,param_3,_Var2,param_4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,100,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return;
}



===== imp_UcmConnectorSetPowerLevelCompleted @ 14000f2b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
imp_UcmConnectorSetPowerLevelCompleted
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x95,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qidLLLDLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  PolicyManagerUcmConnectorSetPowerLevelCompleted(*(undefined8 *)(lVar1 + 0x188),param_4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x97,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return 0;
}



===== imp_UcmConnectorTypeCAttach @ 14000f410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 imp_UcmConnectorTypeCAttach(undefined8 param_1,undefined8 param_2,ulong *param_3)

{
  _UCM_TYPEC_PARTNER _Var1;
  __uint64 _Var2;
  ulong uVar3;
  _UCM_TYPEC_CURRENT _Var4;
  _UCM_CHARGING_STATE _Var5;
  _UCMCONNECTOR_CONTEXT *p_Var6;
  ulonglong uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x3a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var6 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiDLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var6->Lock,0);
  _Var2 = (p_Var6->Config).ConnectorId;
  if ((p_Var6->PortPartnerAttached != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x3c,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                       (char)p_Var6->UcmCxCtx->DeviceSelf,(char)_Var2);
  }
  p_Var6->AttachCount = (2 - (uint)(p_Var6->AttachCount != 0xffffffff)) + p_Var6->AttachCount;
  uVar3 = *param_3;
  _Var1 = param_3[1];
  _Var4 = param_3[2];
  _Var5 = param_3[3];
  p_Var6->PortPartnerAttached = '\x01';
  p_Var6->Overcurrent = '\0';
  (p_Var6->AttachParams).Size = uVar3;
  (p_Var6->AttachParams).Partner = _Var1;
  (p_Var6->AttachParams).CurrentAdvertisement = _Var4;
  (p_Var6->AttachParams).ChargingState = _Var5;
  _Var1 = (p_Var6->AttachParams).Partner;
  p_Var6->PartnerAtAttach = _Var1;
  if (_Var1 == UcmTypeCPartnerInvalid) {
LAB_14000f5b4:
    p_Var6->LocalPortDataRole = UcmDataRoleInvalid;
  }
  else {
    if (_Var1 != UcmTypeCPartnerUfp) {
      if (_Var1 == UcmTypeCPartnerDfp) {
        p_Var6->LocalPortDataRole = UcmDataRoleUfp;
        goto LAB_14000f5ba;
      }
      if (((_Var1 != UcmTypeCPartnerPoweredCableNoUfp) &&
          (_Var1 != UcmTypeCPartnerPoweredCableWithUfp)) && (_Var1 != UcmTypeCPartnerAudioAccessory)
         ) goto LAB_14000f5b4;
    }
    p_Var6->LocalPortDataRole = UcmDataRoleDfp;
  }
LAB_14000f5ba:
  p_Var6->LocalPortPowerRole = (_Var1 != UcmTypeCPartnerDfp) + UcmPowerRoleSink;
  KeResetEvent(&p_Var6->EventDataDirectionChanged);
  KeResetEvent(&p_Var6->EventPowerDirectionChanged);
  p_Var6->PdConnState = UcmPdConnStateNotSupported;
  (p_Var6->PdRequestDataObject).Ul = 0;
  uVar7 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    if (p_Var6->PartnerSourcePdos != (WDFMEMORY__ *)0x0) {
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      p_Var6->PartnerSourcePdos = (WDFMEMORY__ *)0x0;
    }
    p_Var6->PartnerSourcePdosCount = '\0';
    p_Var6->PartnerUsbCommunicationCapable = '\0';
  }
  (p_Var6->CableProperties).ActiveCable = '\0';
  (p_Var6->CableProperties).ModeSupport = '\0';
  UpdateCadState(p_Var6);
  if (((p_Var6->DeferUrsStateUpdate == '\0') || (p_Var6->LocalPortDataRole != UcmDataRoleDfp)) ||
     (p_Var6->PdAlternateModesSupportedCount == 0)) {
    UpdateUrsState(p_Var6);
    p_Var6->UrsStateUpdatedForAttach = '\x01';
  }
  else {
    p_Var6->UrsStateUpdatedForAttach = '\0';
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3d,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                         (char)p_Var6->UcmCxCtx->DeviceSelf,(char)(p_Var6->Config).ConnectorId);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9f8))
            (WdfDriverGlobals,p_Var6->TimerForPdConnState,0xffffffffff676980);
  ConnectorIndicateStateChangeAndReleaseLock(p_Var6);
  TraceLoggingUcmConnectorTypeCAttach((long)p_Var6,*param_3,_Var2,param_3[1],param_3[2],param_3[3]);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x3e,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return 0;
}



===== imp_UcmConnectorTypeCCurrentAdChanged @ 14000f770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
imp_UcmConnectorTypeCCurrentAdChanged
          (undefined8 param_1,undefined8 param_2,_UCM_TYPEC_CURRENT param_3)

{
  _UCMCX_CONTEXT **pp_Var1;
  _UCM_PD_CONN_STATE _Var2;
  __uint64 _Var3;
  _UCMCONNECTOR_CONTEXT *p_Var4;
  undefined8 uVar5;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar6;
  undefined1 uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x46,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var4 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_2);
  pp_Var1 = &p_Var4->UcmCxCtx;
  uVar7 = (undefined1)param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids;
    WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x47,
                        &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                        (char)(*pp_Var1)->DeviceSelf,(char)(p_Var4->Config).ConnectorId,uVar7);
  }
  uVar5 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var4->Lock);
  _Var3 = (p_Var4->Config).ConnectorId;
  uVar6 = (undefined1)_Var3;
  if (p_Var4->LocalPortPowerRole == UcmPowerRoleSink) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiLL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar5,0x48,in_stack_ffffffffffffffb8,
                 (char)(*pp_Var1)->DeviceSelf,uVar6,
                 (char)(p_Var4->AttachParams).CurrentAdvertisement,uVar7);
    }
    _Var2 = p_Var4->PdConnState;
    (p_Var4->AttachParams).CurrentAdvertisement = param_3;
    if (_Var2 != UcmPdConnStateNegotiationSucceeded) {
      UpdateCadState(p_Var4);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiLL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar5,0x49,in_stack_ffffffffffffffb8,
               (char)(*pp_Var1)->DeviceSelf,uVar6,uVar7,(char)p_Var4->LocalPortPowerRole);
  }
  ConnectorIndicateStateChangeAndReleaseLock(p_Var4);
  TraceLoggingUcmConnectorTypeCCurrentAdChanged((long)p_Var4,_Var3,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return 0;
}



===== imp_UcmConnectorTypeCDetach @ 14000f970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 imp_UcmConnectorTypeCDetach(undefined8 param_1,undefined8 param_2)

{
  __uint64 _Var1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x3f,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  p_Var2 = (_UCMCONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x40,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                       (char)p_Var2->UcmCxCtx->DeviceSelf,(char)(p_Var2->Config).ConnectorId);
  }
  (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,p_Var2->TimerForPdConnState,1);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
  _Var1 = (p_Var2->Config).ConnectorId;
  p_Var2->PortPartnerAttached = '\0';
  p_Var2->Overcurrent = '\0';
  p_Var2->UrsStateUpdatedForAttach = '\0';
  p_Var2->PartnerAtAttach = UcmTypeCPartnerInvalid;
  p_Var2->LocalPortDataRole = UcmDataRoleInvalid;
  p_Var2->LocalPortPowerRole = UcmPowerRoleInvalid;
  p_Var2->PdConnState = UcmPdConnStateInvalid;
  (p_Var2->PdRequestDataObject).Ul = 0;
  (p_Var2->PolicyPreparedPdRequestDataObject).Ul = 0;
  p_Var2->PolicyPreparedTypeCCurrentAdvertisement = 0;
  (p_Var2->AttachParams).Size = 0;
  (p_Var2->AttachParams).Partner = UcmTypeCPartnerInvalid;
  (p_Var2->AttachParams).CurrentAdvertisement = UcmTypeCCurrentInvalid;
  (p_Var2->AttachParams).ChargingState = UcmChargingStateInvalid;
  (p_Var2->CableProperties).Size = 0;
  (p_Var2->CableProperties).ActiveCable = '\0';
  (p_Var2->CableProperties).ModeSupport = '\0';
  *(undefined2 *)&(p_Var2->CableProperties).field_0x6 = 0;
  (p_Var2->CableProperties).Size = 8;
  if ((p_Var2->PdAlternateModesEnteredCount != 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x41,
                      &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,
                      (char)p_Var2->PdAlternateModesEnteredCount);
  }
  if (p_Var2->SourcePdos != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    p_Var2->SourcePdos = (WDFMEMORY__ *)0x0;
    p_Var2->SourcePdosCount = '\0';
  }
  if (p_Var2->PartnerSourcePdos != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    p_Var2->PartnerSourcePdos = (WDFMEMORY__ *)0x0;
    p_Var2->PartnerSourcePdosCount = '\0';
  }
  if (p_Var2->PartnerPdAlternateModes != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    p_Var2->PartnerPdAlternateModes = (WDFMEMORY__ *)0x0;
    p_Var2->PartnerPdAlternateModeCount = 0;
  }
  (p_Var2->PolicyPreparedPdAlternateModeToNegotiate).SVID = 0;
  *(undefined2 *)&(p_Var2->PolicyPreparedPdAlternateModeToNegotiate).field_0x2 = 0;
  (p_Var2->PolicyPreparedPdAlternateModeToNegotiate).Mode = 0;
  (p_Var2->PolicyPreparedPdRequestDataObject).Ul = 0;
  KeSetEvent(&p_Var2->EventDataDirectionChanged,0,0);
  KeSetEvent(&p_Var2->EventPowerDirectionChanged,0,0);
  UpdateUrsState(p_Var2);
  p_Var2->UrsStateUpdatedForAttach = '\0';
  UpdateCadState(p_Var2);
  ConnectorIndicateStateChangeAndReleaseLock(p_Var2);
  TraceLoggingUcmConnectorTypeCDetach((long)p_Var2,_Var1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x42,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return 0;
}



===== imp_UcmDeviceGetConnectorIds @ 14000fc60 =====

long imp_UcmDeviceGetConnectorIds
               (undefined8 param_1,WDFDEVICE__ *param_2,ulong *param_3,__uint64 **param_4)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6a,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  if ((param_3 == (ulong *)0x0) || (param_4 == (__uint64 **)0x0)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = CapStoreGetConnectorIds(param_2,param_3,param_4);
    TraceLoggingUcmDeviceGetConnectorIds(lVar1,*param_3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x6b,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return lVar1;
}



===== imp_UcmInitializeDevice @ 14000fd40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmInitializeDevice(longlong param_1,WDFDEVICE__ *param_2,ulong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  ulong uVar3;
  _WDF_TRI_STATE _Var4;
  undefined2 uVar5;
  int local_res18 [2];
  _PNP_CALLBACK_CONFIG *local_res20;
  _UCMCX_CONTEXT *local_88;
  ulong local_80 [2];
  undefined8 local_78;
  code *pcStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  WDFDEVICE__ *local_58;
  undefined8 uStack_50;
  undefined *local_48;
  
  local_48 = (undefined *)0x0;
  local_88 = (_UCMCX_CONTEXT *)0x0;
  local_res20 = (_PNP_CALLBACK_CONFIG *)0x0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_78 = 0;
  pcStack_70 = (code *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = (WDFDEVICE__ *)0x0;
  uStack_50 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                       &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xb,
                         &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)param_2,
                         (char)*param_3);
    }
  }
  uVar3 = *param_3;
  if (uVar3 != 8) {
    if (uVar3 != 4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xc,
                          &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)uVar3);
      }
      iVar1 = -0x3ffffffc;
      goto LAB_14000fe43;
    }
    param_3 = local_80;
    local_80[0] = 8;
    local_80[1] = 2;
  }
  local_78 = 0x38;
  uStack_60 = 0x100000001;
  local_48 = PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128;
  pcStack_70 = UcmCxContextCleanup;
  local_68 = 0;
  local_58 = (WDFDEVICE__ *)0x0;
  uStack_50 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,&local_78,&local_88);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000fe43;
    uVar5 = 0xd;
  }
  else {
    local_88->DeviceSelf = param_2;
    uVar2 = Feature_UFFPPUWOUD__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 != 0) {
      local_88->PrivateGlobals = (_UCM_PRIVATE_DRIVER_GLOBALS *)(param_1 + -4);
    }
    local_48 = (undefined *)0x0;
    local_68 = 0;
    pcStack_70 = (code *)0x0;
    local_78 = 0x38;
    uStack_50 = 0;
    uStack_60 = 0x100000001;
    local_58 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_78,&local_88->UrsLock)
    ;
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000fe43;
      uVar5 = 0xe;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                        (WdfDriverGlobals,&local_78,&local_88->CadLock);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000fe43;
        uVar5 = 0xf;
      }
      else {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                          (WdfDriverGlobals,&local_78,&local_88->ConnectorsLock);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000fe43;
          uVar5 = 0x10;
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                            (WdfDriverGlobals,&local_78,&local_88->RoleSwapLock);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000fe43;
            uVar5 = 0x11;
          }
          else {
            iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))
                              (WdfDriverGlobals,&local_78,&local_88->PowerLevelChangeLock);
            if (iVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_14000fe43;
              uVar5 = 0x12;
            }
            else {
              local_48 = (undefined *)0x0;
              local_68 = 0;
              pcStack_70 = (code *)0x0;
              local_78 = 0x38;
              uStack_50 = 0;
              uStack_60 = 0x100000001;
              local_58 = param_2;
              iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))
                                (WdfDriverGlobals,&local_78,&local_88->Connectors);
              if (iVar1 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_14000fe43;
                uVar5 = 0x13;
              }
              else {
                local_48 = (undefined *)0x0;
                local_68 = 0;
                pcStack_70 = (code *)0x0;
                uStack_50 = 0;
                local_78 = 0x38;
                uStack_60 = 0x100000001;
                local_58 = param_2;
                iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                                  (WdfDriverGlobals,&local_78,0x200,0,0x50,
                                   &local_88->CadPnpCallbackConfig,&local_res20);
                if (iVar1 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14000fe43;
                  uVar5 = 0x14;
LAB_1400101cb:
                  WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar5,
                                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,0x50,
                                     (char)iVar1);
                  goto LAB_14000fe43;
                }
                local_res20->UcmCxCtx = local_88;
                local_res20->InterfaceName = "CAD";
                (local_res20->InterfaceGuid).Data1 = 0xec0a1cc9;
                (local_res20->InterfaceGuid).Data2 = 0x4294;
                (local_res20->InterfaceGuid).Data3 = 0x43fb;
                (local_res20->InterfaceGuid).Data4[0] = 0xbf;
                (local_res20->InterfaceGuid).Data4[1] = '7';
                (local_res20->InterfaceGuid).Data4[2] = 0xb8;
                (local_res20->InterfaceGuid).Data4[3] = 'P';
                (local_res20->InterfaceGuid).Data4[4] = 0xce;
                (local_res20->InterfaceGuid).Data4[5] = 0x95;
                (local_res20->InterfaceGuid).Data4[6] = 0xf3;
                (local_res20->InterfaceGuid).Data4[7] = '7';
                local_res20->Handle = &local_88->CadPnPEventHandle;
                local_res20->IoTargetLock = local_88->CadLock;
                local_res20->IoTargetHandlePointer = &local_88->CadIoTarget;
                local_res20->IoTargetCollection = (WDFCOLLECTION__ **)0x0;
                local_res20->InterfaceOnlineCallback = UpdateCadState;
                local_res20->InterfacePostOpenCallback = (_func___cdecl_void_WDFIOTARGET___ptr *)0x0
                ;
                iVar1 = UcmRegisterForPnPEvents(local_res20);
                if (iVar1 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_14000fe43;
                  uVar5 = 0x15;
                }
                else {
                  iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                                    (WdfDriverGlobals,&local_78,0x200,0,0x50,
                                     &local_88->UrsPnpCallbackConfig,&local_res20);
                  if (iVar1 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14000fe43;
                    uVar5 = 0x16;
                    goto LAB_1400101cb;
                  }
                  local_res20->UcmCxCtx = local_88;
                  local_res20->InterfaceName = "URS";
                  (local_res20->InterfaceGuid).Data1 = 0x5e837b9c;
                  (local_res20->InterfaceGuid).Data2 = 0x19ba;
                  (local_res20->InterfaceGuid).Data3 = 0x43fc;
                  (local_res20->InterfaceGuid).Data4[0] = 0xb8;
                  (local_res20->InterfaceGuid).Data4[1] = 0xdd;
                  (local_res20->InterfaceGuid).Data4[2] = 0x84;
                  (local_res20->InterfaceGuid).Data4[3] = 0x9e;
                  (local_res20->InterfaceGuid).Data4[4] = 'b';
                  (local_res20->InterfaceGuid).Data4[5] = 0x93;
                  (local_res20->InterfaceGuid).Data4[6] = 0xe5;
                  (local_res20->InterfaceGuid).Data4[7] = 'C';
                  local_res20->Handle = &local_88->UrsPnPEventHandle;
                  local_res20->IoTargetLock = local_88->UrsLock;
                  local_res20->IoTargetHandlePointer = (WDFIOTARGET__ **)0x0;
                  local_res20->IoTargetCollection = &local_88->UrsIoTargets;
                  local_res20->InterfaceOnlineCallback = UpdateUrsState;
                  local_res20->InterfacePostOpenCallback = GetUrsConnectorIds;
                  local_48 = (undefined *)0x0;
                  local_68 = 0;
                  pcStack_70 = (code *)0x0;
                  local_78 = 0x38;
                  uStack_50 = 0;
                  uStack_60 = 0x100000001;
                  local_58 = param_2;
                  iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))
                                    (WdfDriverGlobals,&local_78,local_res20->IoTargetCollection);
                  if (iVar1 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_14000fe43;
                    uVar5 = 0x17;
                  }
                  else {
                    iVar1 = UcmRegisterForPnPEvents(local_res20);
                    if (iVar1 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                      goto LAB_14000fe43;
                      uVar5 = 0x18;
                    }
                    else {
                      uVar3 = param_3[1];
                      local_88->EnablePolicyManagement = uVar3 == 1;
                      if ((uVar3 != 1) ||
                         (iVar1 = CapStoreInitialize(local_88->DeviceSelf), -1 < iVar1)) {
                        iVar1 = InterfaceCreate(local_88);
                        if (iVar1 < 0) goto LAB_14000fe43;
                        local_res18[0] = 0;
                        if (local_88->EnablePolicyManagement != '\0') {
                          local_res18[0] =
                               (uint)(uint3)(local_88->CapStore).BrownoutProtectionConfig << 8;
                        }
                        iVar1 = PolicyManagerInitialize(param_2,local_res18);
                        if ((-1 < iVar1) ||
                           ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
                        goto LAB_14000fe43;
                        uVar5 = 0x1a;
                      }
                      else {
                        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                        goto LAB_14000fe43;
                        uVar5 = 0x19;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar5,
                    &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids,(char)iVar1);
LAB_14000fe43:
  if (param_3 == (ulong *)0x0) {
    _Var4 = WdfUseDefault;
    uVar3 = 0;
  }
  else {
    _Var4 = param_3[1];
    uVar3 = *param_3;
  }
  TraceLoggingUcmInitializeDevice(iVar1,uVar3,_Var4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1b,
                     &WPP_2a098b208772356ce4eb499ce9650b01_Traceguids);
  }
  return iVar1;
}



===== InterfaceCreate @ 140010534 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl InterfaceCreate(struct _UCMCX_CONTEXT * __ptr64) */

long __cdecl InterfaceCreate(_UCMCX_CONTEXT *param_1)

{
  WDFDEVICE__ *pWVar1;
  int iVar2;
  WDFQUEUE__ **ppWVar3;
  undefined2 uVar4;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined8 local_84;
  code *local_60;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  pWVar1 = param_1->DeviceSelf;
  memset(&local_88,0,0x60);
  local_88 = 0x60;
  local_b8 = 0;
  uStack_c0 = 0;
  local_84 = 1;
  local_60 = InterfaceEvtIoDeviceControl;
  uStack_b0 = 0x100000002;
  local_98 = 0;
  ppWVar3 = &param_1->InterfaceQueue;
  local_a8 = 0;
  uStack_a0 = 0;
  local_c8 = 0x38;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,pWVar1,&local_88,&local_c8,ppWVar3);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0xb;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xca0))
                      (WdfDriverGlobals,pWVar1,*WdfDriverGlobals,0xe,
                       InterfaceEvtDeviceWdmIrpDispatch,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0xc,
                          &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*ppWVar3);
      *ppWVar3 = (WDFQUEUE__ *)0x0;
      iVar2 = 0;
      goto LAB_14001073c;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,pWVar1,&GUID_DEVINTERFACE_USB_CONNECTOR_MGR,0);
    if (-1 < iVar2) goto LAB_14001073c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0xd;
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar4,
                    &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar2);
LAB_14001073c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xe,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return iVar2;
}



===== InterfaceEvtDeviceWdmIrpDispatch @ 1400107a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl InterfaceEvtDeviceWdmIrpDispatch(struct WDFDEVICE__ * __ptr64,unsigned char,unsigned
   char,unsigned long,void * __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
InterfaceEvtDeviceWdmIrpDispatch
          (WDFDEVICE__ *param_1,uchar param_2,uchar param_3,ulong param_4,void *param_5,
          _IRP *param_6,void *param_7)

{
  bool bVar1;
  long lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffd8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x13,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  if ((((param_4 == 0x574004) || (param_4 == 0x574008)) || (param_4 == 0x57400c)) ||
     ((param_4 == 0x578010 || (bVar1 = false, param_4 == 0x578014)))) {
    bVar1 = true;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffd8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x14,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (bVar1) {
    lVar4 = *(longlong *)(lVar4 + 0xb0);
    pcVar3 = *(code **)(WdfFunctions_01015 + 0xc90);
  }
  else {
    lVar4 = PolicyManagerInspectIoCtlForInterception(param_1,param_4);
    if (lVar4 == 0) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0xc88))(WdfDriverGlobals,param_1,param_6,param_7);
      return lVar2;
    }
    pcVar3 = *(code **)(WdfFunctions_01015 + 0xc90);
  }
  lVar2 = (*pcVar3)(WdfDriverGlobals,param_1,param_6,lVar4,
                    (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffff00000000);
  return lVar2;
}



===== InterfaceEvtIoDeviceControl @ 140010930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceEvtIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
InterfaceEvtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  undefined8 uVar1;
  _UCMCX_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xf,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  p_Var2 = (_UCMCX_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x10,
                       &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)param_2,(char)param_5)
    ;
  }
  if (param_5 == 0x574004) {
    InterfaceUcmGetInformation(p_Var2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x574008) {
    InterfaceUcmGetConnectorProperties(p_Var2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x57400c) {
    InterfaceUcmGetConnectorState(p_Var2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x578010) {
    InterfaceUcmSetConnectorDataRole(p_Var2,param_2,param_3,param_4);
  }
  else if (param_5 == 0x578014) {
    InterfaceUcmSetConnectorPowerRole(p_Var2,param_2,param_3,param_4);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x11,
                        &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x12,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== InterfaceUcmGetConnectorProperties @ 140010b4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceUcmGetConnectorProperties(struct _UCMCX_CONTEXT * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
InterfaceUcmGetConnectorProperties
          (_UCMCX_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  ulong uVar1;
  int iVar2;
  WDFREQUEST__ *pWVar3;
  undefined2 uVar4;
  _UCM_CONNECTOR_PROPERTIES *local_res20;
  undefined *in_stack_ffffffffffffffa8;
  ulong *local_38 [2];
  
  local_38[0] = (ulong *)0x0;
  local_res20 = (_UCM_CONNECTOR_PROPERTIES *)0x0;
  pWVar3 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    pWVar3 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1a,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (param_4 == 4) {
    if (param_3 == 0x38) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_38,0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010d5c;
        uVar4 = 0x1d;
      }
      else {
        uVar1 = *local_38[0];
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,0x38,&local_res20,0);
        if (-1 < iVar2) {
          *(undefined8 *)local_res20 = 0;
          *(undefined8 *)(local_res20 + 8) = 0;
          *(undefined8 *)(local_res20 + 0x10) = 0;
          *(undefined8 *)(local_res20 + 0x18) = 0;
          *(undefined8 *)(local_res20 + 0x20) = 0;
          *(undefined8 *)(local_res20 + 0x28) = 0;
          *(undefined8 *)(local_res20 + 0x30) = 0;
          iVar2 = ConnectorGetProperties(param_1,uVar1,local_res20);
          if (-1 < iVar2) {
            (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x38);
            iVar2 = 0;
          }
          goto LAB_140010d5c;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010d5c;
        uVar4 = 0x1e;
      }
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar4,
                        &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar2);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,4,0x1c,
                            in_stack_ffffffffffffffa8,8,0x38,(char)param_3);
      }
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,4,0x1b,
                          in_stack_ffffffffffffffa8,8,4,(char)param_4);
    }
    iVar2 = -0x3ffffdfa;
  }
LAB_140010d5c:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1f,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== InterfaceUcmGetConnectorState @ 140010dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceUcmGetConnectorState(struct _UCMCX_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
InterfaceUcmGetConnectorState
          (_UCMCX_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  ulong uVar1;
  int iVar2;
  WDFREQUEST__ *pWVar3;
  undefined2 uVar4;
  _UCM_CONNECTOR_STATE *local_res20;
  undefined *in_stack_ffffffffffffffa8;
  ulong *local_38 [2];
  
  local_38[0] = (ulong *)0x0;
  local_res20 = (_UCM_CONNECTOR_STATE *)0x0;
  pWVar3 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffa8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    pWVar3 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x20,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (param_4 == 4) {
    if (param_3 == 0xcb0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_38,0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010fd7;
        uVar4 = 0x23;
      }
      else {
        uVar1 = *local_38[0];
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,0xcb0,&local_res20,0);
        if (-1 < iVar2) {
          memset(local_res20,0,0xcb0);
          iVar2 = ConnectorGetState(param_1,uVar1,local_res20);
          if (-1 < iVar2) {
            (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0xcb0);
            iVar2 = 0;
          }
          goto LAB_140010fd7;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010fd7;
        uVar4 = 0x24;
      }
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar4,
                        &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar2);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,4,0x22,
                            in_stack_ffffffffffffffa8,0xc,0xb0,(char)param_3);
      }
      iVar2 = -0x3ffffdfa;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,4,0x21,
                          in_stack_ffffffffffffffa8,0xc,4,(char)param_4);
    }
    iVar2 = -0x3ffffdfa;
  }
LAB_140010fd7:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x25,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== InterfaceUcmGetInformation @ 140011048 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceUcmGetInformation(struct _UCMCX_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
InterfaceUcmGetInformation
          (_UCMCX_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  undefined4 uVar2;
  WDFREQUEST__ *pWVar3;
  __uint64 _Var4;
  undefined4 *local_res20;
  undefined *in_stack_ffffffffffffffb8;
  
  local_res20 = (undefined4 *)0x0;
  pWVar3 = param_2;
  _Var4 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Var4 = 3;
    in_stack_ffffffffffffffb8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    pWVar3 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x15,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (param_4 == 0) {
    if (param_3 == 4) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,&local_res20,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x18,
                            &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar1);
        }
      }
      else {
        *local_res20 = 0;
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,param_1->Connectors);
        *local_res20 = uVar2;
        (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,4);
        iVar1 = 0;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,_Var4,0x17,
                            in_stack_ffffffffffffffb8,4,4,(char)param_3);
      }
      iVar1 = -0x3ffffdfa;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,_Var4,0x16,
                          in_stack_ffffffffffffffb8,4,0,(char)param_4);
    }
    iVar1 = -0x3ffffdfa;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x19,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== InterfaceUcmSetConnectorDataRole @ 140011270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceUcmSetConnectorDataRole(struct _UCMCX_CONTEXT * __ptr64,struct WDFREQUEST__
   * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
InterfaceUcmSetConnectorDataRole
          (_UCMCX_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  WDFREQUEST__ *pWVar2;
  undefined2 uVar3;
  __uint64 *local_res20;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar4;
  
  local_res20 = (__uint64 *)0x0;
  pWVar2 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    pWVar2 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x26,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (param_4 == 0x10) {
    if (param_3 == 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                        (WdfDriverGlobals,param_2,0x10,&local_res20,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x29,
                            &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar1);
        }
      }
      else {
        iVar1 = SetConnectorDataRoleInternal
                          (param_1,*local_res20,*(_UCM_DATA_ROLE *)(local_res20 + 1));
      }
      goto LAB_1400113b3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x28;
      uVar4 = 0;
      param_4 = param_3;
      goto LAB_1400112f8;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar3 = 0x27;
    uVar4 = 0x10;
LAB_1400112f8:
    WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,0x10,uVar3,
                        in_stack_ffffffffffffffb8,0x10,uVar4,(char)param_4);
  }
  iVar1 = -0x3ffffdfa;
LAB_1400113b3:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2a,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== InterfaceUcmSetConnectorPowerRole @ 140011424 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl InterfaceUcmSetConnectorPowerRole(struct _UCMCX_CONTEXT * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
InterfaceUcmSetConnectorPowerRole
          (_UCMCX_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  WDFREQUEST__ *pWVar2;
  undefined2 uVar3;
  __uint64 *local_res20;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar4;
  
  local_res20 = (__uint64 *)0x0;
  pWVar2 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids;
    pWVar2 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2b,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  if (param_4 == 0x10) {
    if (param_3 == 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                        (WdfDriverGlobals,param_2,0x10,&local_res20,0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x2e,
                            &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,(char)iVar1);
        }
      }
      else {
        iVar1 = SetConnectorPowerRoleInternal
                          (param_1,*local_res20,*(_UCM_POWER_ROLE *)(local_res20 + 1));
      }
      goto LAB_140011567;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x2d;
      uVar4 = 0;
      param_4 = param_3;
      goto LAB_1400114ac;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar3 = 0x2c;
    uVar4 = 0x10;
LAB_1400114ac:
    WPP_RECORDER_SF_LPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,0x10,uVar3,
                        in_stack_ffffffffffffffb8,0x14,uVar4,(char)param_4);
  }
  iVar1 = -0x3ffffdfa;
LAB_140011567:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2f,
                     &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_LPP @ 1400115d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LPP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_a4727a13ee49310d74dbc8dd361644c7_Traceguids,param_4,&param_6,4,
                  &param_7,8,&param_8,8,0);
  return;
}



===== ConnectorCleanup @ 1400116d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ConnectorCleanup(void * __ptr64) */

void __cdecl ConnectorCleanup(void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x18,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x19,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  return;
}



===== ConnectorCopyAlternateModes @ 140011790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ConnectorCopyAlternateModes(struct WDFMEMORY__ * __ptr64,struct
   _UCM_PD_ALTERNATE_MODE (& __ptr64)[128]) */

void __cdecl ConnectorCopyAlternateModes(WDFMEMORY__ *param_1,_UCM_PD_ALTERNATE_MODE *param_2)

{
  void *_Src;
  ulonglong local_res8 [4];
  
  if (param_1 != (WDFMEMORY__ *)0x0) {
    local_res8[0] = 0;
    _Src = (void *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_1,local_res8);
    if (0x400 < local_res8[0]) {
      local_res8[0] = 0x400;
    }
    memmove(param_2,_Src,local_res8[0]);
  }
  return;
}



===== ConnectorCopyPdos @ 1400117f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ConnectorCopyPdos(struct WDFMEMORY__ * __ptr64,union _UCM_PD_POWER_DATA_OBJECT (&
   __ptr64)[7]) */

void __cdecl ConnectorCopyPdos(WDFMEMORY__ *param_1,_UCM_PD_POWER_DATA_OBJECT *param_2)

{
  void *_Src;
  ulonglong local_res8 [4];
  
  if (param_1 != (WDFMEMORY__ *)0x0) {
    local_res8[0] = 0;
    _Src = (void *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_1,local_res8);
    if (0x1c < local_res8[0]) {
      local_res8[0] = 0x1c;
    }
    memmove(param_2,_Src,local_res8[0]);
  }
  return;
}



===== ConnectorFillState @ 140011858 =====

/* void __cdecl ConnectorFillState(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_STATE * __ptr64) */

void __cdecl ConnectorFillState(_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_STATE *param_2)

{
  long lVar1;
  ulong local_res8 [2];
  ulong local_res10 [2];
  WDFMEMORY__ *local_res18;
  WDFMEMORY__ *local_res20;
  
  local_res18 = (WDFMEMORY__ *)0x0;
  local_res8[0] = 0;
  local_res20 = (WDFMEMORY__ *)0x0;
  local_res10[0] = 0;
  memset(param_2,0,0xcb0);
  *(ulong *)(param_2 + 4) = param_1->ChangeCount;
  param_2[8] = (_UCM_CONNECTOR_STATE)param_1->PortPartnerAttached;
  *(ulong *)(param_2 + 0xc) = param_1->AttachCount;
  *(_UCM_TYPEC_PARTNER *)(param_2 + 0x10) = param_1->PartnerAtAttach;
  *(_UCM_TYPEC_CURRENT *)(param_2 + 0x18) = (param_1->AttachParams).CurrentAdvertisement;
  *(_UCM_PD_CONN_STATE *)(param_2 + 0x1c) = param_1->PdConnState;
  *(ulong *)(param_2 + 0x20) = (param_1->PdRequestDataObject).Ul;
  *(_UCM_DATA_ROLE *)(param_2 + 0x24) = param_1->LocalPortDataRole;
  *(_UCM_POWER_ROLE *)(param_2 + 0x28) = param_1->LocalPortPowerRole;
  *(_UCM_CHARGING_STATE *)(param_2 + 0x2c) = (param_1->AttachParams).ChargingState;
  param_2[0x70] = (_UCM_CONNECTOR_STATE)param_1->PartnerSourcePdosCount;
  *(ulong *)(param_2 + 0x90) = param_1->PdAlternateModesEnteredCount;
  ConnectorCopyPdos(param_1->PartnerSourcePdos,(_UCM_PD_POWER_DATA_OBJECT *)(param_2 + 0x74));
  *(ulong *)(param_2 + 0x898) = param_1->PartnerPdAlternateModeCount;
  ConnectorCopyAlternateModes
            (param_1->PartnerPdAlternateModes,(_UCM_PD_ALTERNATE_MODE *)(param_2 + 0x498));
  *(ulong *)(param_2 + 0xc9c) = param_1->CurrentPdAlternateModesSupportedCount;
  ConnectorCopyAlternateModes
            (param_1->CurrentPdAlternateModesSupported,(_UCM_PD_ALTERNATE_MODE *)(param_2 + 0x89c));
  *(ulong *)(param_2 + 0xca0) = param_1->CurrentPdAlternateModesSupportedChangedCount;
  param_2[0xcac] = (_UCM_CONNECTOR_STATE)param_1->Overcurrent;
  if (param_1->UcmCxCtx->EnablePolicyManagement == '\0') {
    param_2[0x30] = (_UCM_CONNECTOR_STATE)param_1->SourcePdosCount;
    ConnectorCopyPdos(param_1->SourcePdos,(_UCM_PD_POWER_DATA_OBJECT *)(param_2 + 0x34));
    *(ulong *)(param_2 + 0x494) = param_1->PdAlternateModesSupportedCount;
    ConnectorCopyAlternateModes
              (param_1->PdAlternateModesSupported,(_UCM_PD_ALTERNATE_MODE *)(param_2 + 0x94));
  }
  else {
    lVar1 = CapStoreGetCapabilityMemory
                      (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,6,&local_res18,local_res8
                      );
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xd,
                           &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,
                           (char)(param_1->Config).ConnectorId,(char)lVar1);
      }
    }
    else {
      param_2[0x30] = local_res8[0]._0_1_;
      ConnectorCopyPdos(local_res18,(_UCM_PD_POWER_DATA_OBJECT *)(param_2 + 0x34));
    }
    lVar1 = CapStoreGetCapabilityMemory
                      (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,8,&local_res20,
                       local_res10);
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xe,
                           &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,
                           (char)(param_1->Config).ConnectorId,(char)lVar1);
      }
    }
    else {
      param_2[0x30] = local_res10[0]._0_1_;
      ConnectorCopyAlternateModes(local_res20,(_UCM_PD_ALTERNATE_MODE *)(param_2 + 0x94));
    }
    *(_UCM_CABLE_PROPERTIES *)(param_2 + 0xca4) = param_1->CableProperties;
  }
  return;
}



===== ConnectorGetProperties @ 140011ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ConnectorGetProperties(struct _UCMCX_CONTEXT * __ptr64,unsigned long,struct
   _UCM_CONNECTOR_PROPERTIES * __ptr64) */

long __cdecl
ConnectorGetProperties(_UCMCX_CONTEXT *param_1,ulong param_2,_UCM_CONNECTOR_PROPERTIES *param_3)

{
  UCMCONNECTOR__ *pUVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,10,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  pUVar1 = UcmGetConnectorByIndex(param_1,param_2);
  if (pUVar1 == (UCMCONNECTOR__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xb,
                        &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,(char)param_2);
    }
    lVar3 = -0x3ffffddb;
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,pUVar1,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*puVar2,0);
    *(undefined8 *)(param_3 + 8) = puVar2[4];
    *(undefined8 *)(param_3 + 0x10) = *(undefined8 *)((longlong)puVar2 + 0xcc);
    *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(puVar2[5] + 8);
    *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(puVar2[5] + 0xc);
    param_3[0x20] = *(_UCM_CONNECTOR_PROPERTIES *)(puVar2[5] + 0x10);
    param_3[0x21] = *(_UCM_CONNECTOR_PROPERTIES *)(puVar2[6] + 4);
    *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(puVar2[6] + 8);
    *(undefined8 *)(param_3 + 0x28) = *(undefined8 *)(puVar2[6] + 0x20);
    *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(puVar2[6] + 0x28);
    *(ulong *)param_3 = param_2;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*puVar2);
    lVar3 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  return lVar3;
}



===== ConnectorGetState @ 140011c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl ConnectorGetState(struct _UCMCX_CONTEXT * __ptr64,unsigned long,struct
   _UCM_CONNECTOR_STATE * __ptr64) */

long __cdecl ConnectorGetState(_UCMCX_CONTEXT *param_1,ulong param_2,_UCM_CONNECTOR_STATE *param_3)

{
  UCMCONNECTOR__ *pUVar1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  long lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xf,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  pUVar1 = UcmGetConnectorByIndex(param_1,param_2);
  if (pUVar1 == (UCMCONNECTOR__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x10,
                        &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,(char)param_2);
    }
    lVar3 = -0x3ffffddb;
  }
  else {
    p_Var2 = (_UCMCONNECTOR_CONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,pUVar1,PTR__WDF_UCMCONNECTOR_CONTEXT_TYPE_INFO_14002a150);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,p_Var2->Lock,0);
    ConnectorFillState(p_Var2,param_3);
    *(ulong *)param_3 = param_2;
    lVar3 = 0;
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,p_Var2->Lock);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x11,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  return lVar3;
}



===== ConnectorIndicateStateChangeAndReleaseLock @ 140011ddc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl ConnectorIndicateStateChangeAndReleaseLock(struct _UCMCONNECTOR_CONTEXT * __ptr64)
    */

void __cdecl ConnectorIndicateStateChangeAndReleaseLock(_UCMCONNECTOR_CONTEXT *param_1)

{
  UPMCONNECTOR__ *pUVar1;
  int iVar2;
  _UPM_CONNECTOR_CONTEXT *p_Var3;
  undefined1 auStackY_d18 [32];
  _UCM_CONNECTOR_STATE local_cd8 [3248];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d18;
  memset(local_cd8,0,0xcb0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x15,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  param_1->ChangeCount = (param_1->ChangeCount + 2) - (uint)(param_1->ChangeCount != 0xffffffff);
  ConnectorFillState(param_1,local_cd8);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->Lock);
  pUVar1 = param_1->PolicyManagerConn;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2c,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  p_Var3 = (_UPM_CONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,pUVar1,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
  UpmConnectorUcmStateChanged(p_Var3,local_cd8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2d,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  if ((param_1->NotificationsInitialized != '\0') &&
     (iVar2 = ZwUpdateWnfStateData(&param_1->WnfState,0,0,0), iVar2 < 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x16,
                      &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,(char)iVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x17,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  return;
}



===== ConnectorInitializeNotifications @ 140012004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ConnectorInitializeNotifications(struct _UCMCONNECTOR_CONTEXT * __ptr64) */

void __cdecl ConnectorInitializeNotifications(_UCMCONNECTOR_CONTEXT *param_1)

{
  void *pvVar1;
  long lVar2;
  void *local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x12,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  if (param_1->UcmCxCtx->InterfaceQueue != (WDFQUEUE__ *)0x0) {
    local_res8 = (void *)0x0;
    lVar2 = WnfCreateSecurityDescriptor(&local_res8);
    pvVar1 = local_res8;
    if (-1 < lVar2) {
      lVar2 = ZwCreateWnfStateName(&param_1->WnfState,3,0,0,0,0,local_res8);
    }
    if (pvVar1 != (void *)0x0) {
      ExFreePoolWithTag(pvVar1,0x586d6355);
    }
    if (lVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x13,
                        &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids,(char)lVar2);
    }
    else {
      param_1->NotificationsInitialized = '\x01';
      (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->Lock,0);
      ConnectorIndicateStateChangeAndReleaseLock(param_1);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x14,
                     &WPP_8db01fe4f5db3047565c23e4590513cc_Traceguids);
  }
  return;
}



===== UcmGetConnectorByIndex @ 140012184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct UCMCONNECTOR__ * __ptr64 __cdecl UcmGetConnectorByIndex(struct _UCMCX_CONTEXT *
   __ptr64,unsigned long) */

UCMCONNECTOR__ * __cdecl UcmGetConnectorByIndex(_UCMCX_CONTEXT *param_1,ulong param_2)

{
  UCMCONNECTOR__ *pUVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,param_1->ConnectorsLock,0);
  pUVar1 = (UCMCONNECTOR__ *)
           (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,param_1->Connectors,param_2);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,param_1->ConnectorsLock);
  return pUVar1;
}



===== RtlStringCchPrintfA @ 140012214 =====

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



===== WPP_RECORDER_SF_qLDd @ 140012288 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0140008;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x36,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x36,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qP @ 1400123a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qPd @ 140012478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x14,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x14,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qdD @ 14001256c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qsHd @ 140012660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsHd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 local_18 [4];
  
  pcVar4 = param_7;
  local_18[0] = 0xc014000f;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,param_4,&param_6,8,pcVar3,lVar2,
               &param_8,2,local_18,4,0);
  }
  lVar2 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (pcVar4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,param_4,&param_6,8,
                  pcVar4,lVar1,&param_8,2,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qsPPd @ 14001280c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsPPd(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [2];
  undefined8 local_10;
  
  local_18[0] = 0xc014000f;
  local_10 = 0x10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x26,&uStack0000000000000030,8,
               pcVar3,lVar2,&local_10,8,&uStack0000000000000048,8,local_18,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,5,&WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x26,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,&local_10,8,
                  &uStack0000000000000048,8,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qsd @ 1400129e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  char *pcVar5;
  
  pcVar5 = param_7;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (param_7[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,pcVar3,lVar2,&param_8,4,0);
  }
  lVar2 = -1;
  if (pcVar5 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (pcVar5[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,pcVar5,lVar1,&param_8,4,0);
  return;
}



===== CapStoreFindConnectorById @ 140012ba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CapStoreFindConnectorById(struct WDFDEVICE__ * __ptr64,unsigned __int64,struct
   _CAPSTORE_CONNECTOR * __ptr64 * __ptr64) */

long __cdecl
CapStoreFindConnectorById(WDFDEVICE__ *param_1,__uint64 param_2,_CAPSTORE_CONNECTOR **param_3)

{
  longlong lVar1;
  _CAPSTORE_CONNECTOR *p_Var2;
  long lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2d,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  lVar3 = -0x3ffffff3;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  p_Var2 = (_CAPSTORE_CONNECTOR *)(((_CAPSTORE_CONNECTOR *)(lVar1 + 0x20))->ConnectorList).Flink;
  do {
    if (p_Var2 == (_CAPSTORE_CONNECTOR *)(lVar1 + 0x20)) {
LAB_140012c51:
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2e,
                         &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
      }
      return lVar3;
    }
    if (p_Var2->ConnectorId == param_2) {
      *param_3 = p_Var2;
      lVar3 = 0;
      goto LAB_140012c51;
    }
    p_Var2 = (_CAPSTORE_CONNECTOR *)(p_Var2->ConnectorList).Flink;
  } while( true );
}



===== CapStoreGetCapabilityMemory @ 140012cac =====

/* long __cdecl CapStoreGetCapabilityMemory(struct WDFDEVICE__ * __ptr64,struct _CAPSTORE_CONNECTOR
   * __ptr64,enum CapabilityId,struct WDFMEMORY__ * __ptr64 * __ptr64,unsigned long * __ptr64) */

long __cdecl
CapStoreGetCapabilityMemory
          (WDFDEVICE__ *param_1,_CAPSTORE_CONNECTOR *param_2,CapabilityId param_3,
          WDFMEMORY__ **param_4,ulong *param_5)

{
  WDFMEMORY__ *pWVar1;
  ulong uVar2;
  long lVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x33,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  if (((param_2 == (_CAPSTORE_CONNECTOR *)0x0) || (param_4 == (WDFMEMORY__ **)0x0)) ||
     (param_5 == (ulong *)0x0)) {
    lVar3 = -0x3ffffff3;
    goto LAB_140012e67;
  }
  if (param_3 == 6) {
    pWVar1 = param_2->PdSourcePdos;
    if (pWVar1 != (WDFMEMORY__ *)0x0) {
      uVar2 = param_2->PdSourcePdosCount;
LAB_140012e58:
      *param_5 = uVar2;
      *param_4 = pWVar1;
      lVar3 = 0;
      goto LAB_140012e67;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffcc;
    }
    uVar4 = 0x35;
    uVar5 = 6;
  }
  else if (param_3 == 7) {
    pWVar1 = param_2->PdSinkPdos;
    if (pWVar1 != (WDFMEMORY__ *)0x0) {
      uVar2 = param_2->PdSinkPdosCount;
      goto LAB_140012e58;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffcc;
    }
    uVar4 = 0x36;
    uVar5 = 7;
  }
  else {
    if (param_3 != 8) {
      lVar3 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x34,
                          &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,(char)param_1,
                          (char)param_3,0xd);
      goto LAB_140012e67;
    }
    pWVar1 = param_2->SupportedPdAlternateModes;
    if (pWVar1 != (WDFMEMORY__ *)0x0) {
      uVar2 = param_2->SupportedPdAlternateModesCount;
      goto LAB_140012e58;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffcc;
    }
    uVar4 = 0x37;
    uVar5 = 8;
  }
  lVar3 = -0x3fffffcc;
  WPP_RECORDER_SF_qiLD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar4,
             &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,(char)param_1,
             (char)param_2->ConnectorId,uVar5,0x34);
LAB_140012e67:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x38,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  return lVar3;
}



===== CapStoreGetCapabilityUlong @ 140012ec0 =====

/* long __cdecl CapStoreGetCapabilityUlong(struct WDFDEVICE__ * __ptr64,struct _CAPSTORE_CONNECTOR *
   __ptr64,enum CapabilityId,unsigned long * __ptr64) */

long __cdecl
CapStoreGetCapabilityUlong
          (WDFDEVICE__ *param_1,_CAPSTORE_CONNECTOR *param_2,CapabilityId param_3,ulong *param_4)

{
  _WDF_TRI_STATE _Var1;
  long lVar2;
  bool bVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2f,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  if (param_2 == (_CAPSTORE_CONNECTOR *)0x0) {
    lVar2 = -0x3ffffff3;
LAB_140013078:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    WPP_RECORDER_SF_qiLD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x30,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,(char)param_1,
               (char)param_2->ConnectorId,(char)param_3,(char)lVar2);
  }
  else {
    lVar2 = 0;
    if (param_3 == 1) {
      _Var1 = param_2->SupportedOperatingModes;
      bVar3 = _Var1 == WdfFalse;
LAB_14001306d:
      if (bVar3) {
LAB_140013073:
        lVar2 = -0x3fffffcc;
        goto LAB_140013078;
      }
    }
    else {
      if (param_3 == 2) {
        _Var1 = param_2->SupportedTypeCPowerSourcingCapabilities;
LAB_14001304c:
        bVar3 = _Var1 == WdfFalse;
      }
      else {
        if (param_3 == 3) {
          _Var1 = param_2->AudioAccessoryCapable;
        }
        else if (param_3 == 4) {
          _Var1 = param_2->IsPdSupported;
        }
        else {
          if (param_3 == 5) {
            _Var1 = param_2->SupportedPowerRoles;
            goto LAB_14001304c;
          }
          if (param_3 != 9) {
            if (param_3 != 10) {
              if (param_3 == 0xb) {
                lVar2 = -0x3fffff45;
              }
              else {
                lVar2 = -0x3febfff1;
              }
              goto LAB_140013078;
            }
            _Var1 = param_2->HardwareCCDebounce;
            bVar3 = _Var1 == WdfUseDefault;
            goto LAB_14001306d;
          }
          _Var1 = param_2->DeferUrsStateUpdate;
        }
        bVar3 = _Var1 == WdfUseDefault;
      }
      if (bVar3) goto LAB_140013073;
    }
    *param_4 = _Var1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_qiLD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x31,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,(char)param_1,
               (char)param_2->ConnectorId,(char)param_3,(char)_Var1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x32,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  return lVar2;
}



===== CapStoreGetConnectorIds @ 1400130c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CapStoreGetConnectorIds(struct WDFDEVICE__ * __ptr64,unsigned long *
   __ptr64,unsigned __int64 * __ptr64 * __ptr64) */

long __cdecl CapStoreGetConnectorIds(WDFDEVICE__ *param_1,ulong *param_2,__uint64 **param_3)

{
  longlong lVar1;
  __uint64 *p_Var2;
  long lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x12,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  if ((param_2 == (ulong *)0x0) || (param_3 == (__uint64 **)0x0)) {
    lVar3 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    WPP_RECORDER_SF_qqqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  else if (*(char *)(lVar1 + 0x18) == '\0') {
    lVar3 = -0x3ffffe7c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffe7c;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x14,
                       &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,(char)param_1,0x84);
  }
  else {
    p_Var2 = (__uint64 *)
             (**(code **)(WdfFunctions_01015 + 0x610))
                       (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x38),0);
    *param_3 = p_Var2;
    lVar3 = 0;
    *param_2 = *(ulong *)(lVar1 + 0x30);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x15,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  return lVar3;
}



===== CapStoreInitialize @ 140013250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CapStoreInitialize(struct WDFDEVICE__ * __ptr64) */

long __cdecl CapStoreInitialize(WDFDEVICE__ *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  uint uVar8;
  longlong local_res10;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  local_res10 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (WDFDEVICE__ *)0x0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,10,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  uVar9 = SUB81(param_1,0);
  if (*(char *)(lVar3 + 0x18) == '\0') {
    puVar1 = (undefined8 *)(lVar3 + 0x20);
    *(undefined8 **)(lVar3 + 0x28) = puVar1;
    *puVar1 = puVar1;
    *(undefined4 *)(lVar3 + 0x30) = 0;
    *(undefined8 *)(lVar3 + 0x38) = 0;
    lVar2 = CapStoreInitializeUsingAcpi(param_1);
    if (-1 < lVar2) {
      local_68 = CONCAT44(local_68._4_4_,0x38);
      uStack_50 = 0x100000001;
      local_48 = param_1;
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                        (WdfDriverGlobals,&local_68,0x200,0,(ulonglong)*(uint *)(lVar3 + 0x30) << 3,
                         (undefined8 *)(lVar3 + 0x38),&local_res10);
      if (lVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar2;
        }
        WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xd,
                            &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar9,
                            (char)*(undefined4 *)(lVar3 + 0x30),(char)lVar2);
      }
      else {
        uVar8 = 0;
        puVar6 = (undefined8 *)*puVar1;
        if (*(int *)(lVar3 + 0x30) != 0) {
          do {
            if (puVar6 == puVar1) break;
            uVar5 = (ulonglong)uVar8;
            uVar8 = uVar8 + 1;
            *(undefined8 *)(local_res10 + uVar5 * 8) = puVar6[3];
            puVar6 = (undefined8 *)*puVar6;
          } while (uVar8 < *(uint *)(lVar3 + 0x30));
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xe,
                            &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar9);
        }
        *(undefined1 *)(lVar3 + 0x18) = 1;
      }
      goto LAB_14001348d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar7 = 0xc;
    uVar10 = (undefined1)lVar2;
    bVar4 = 2;
  }
  else {
    lVar2 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar7 = 0xb;
    uVar10 = 0;
    bVar4 = 3;
  }
  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar4,6,uVar7,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar9,uVar10);
LAB_14001348d:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xf,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  return lVar2;
}



===== CapStoreInitializeUsingAcpi @ 1400134e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CapStoreInitializeUsingAcpi(struct WDFDEVICE__ * __ptr64) */

long __cdecl CapStoreInitializeUsingAcpi(WDFDEVICE__ *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 uVar3;
  bool bVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  longlong lVar8;
  WDFMEMORY__ *pWVar9;
  byte *pbVar10;
  byte *pbVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var18;
  undefined2 uVar19;
  uint uVar20;
  bool bVar21;
  WDFMEMORY__ *pWVar22;
  undefined1 auStackY_198 [8];
  undefined1 auStackY_190 [24];
  undefined1 uVar23;
  WDFMEMORY__ *local_148;
  ulong local_140 [2];
  WDFMEMORY__ *local_138;
  longlong *local_130;
  byte *local_128;
  undefined8 local_120;
  longlong local_118;
  longlong local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  WDFDEVICE__ *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  _ACPI_PLD_BUFFER local_d0;
  _CAPSTORE_CONNECTOR local_b8;
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_198;
  local_138 = (WDFMEMORY__ *)0x0;
  local_140[0] = 0;
  local_d0._0_1_ = 0;
  local_d0.Color = 0;
  local_d0.Width = 0;
  local_d0.Height = 0;
  local_d0.Reserved = 0;
  local_d0.CardCageNumber = 0;
  local_d0.CabinetNumber = 0;
  local_d0.EjectionRequired = 0;
  local_d0.Ejectable = 0;
  local_d0.Bay = 0;
  local_d0.GroupPosition = 0;
  local_d0.GroupToken = 0;
  local_d0.GroupOrientation = 0;
  local_d0.Shape = 0;
  local_d0.HorizontalPosition = 0;
  local_d0.VerticalPosition = 0;
  local_d0.Panel = 0;
  local_d0.Lid = 0;
  local_d0.Dock = 0;
  local_d0.UserVisible = 0;
  local_48 = 0;
  lStack_40 = 0;
  memset(&local_b8,0,0x70);
  local_120 = 0;
  local_130 = (longlong *)0x0;
  local_108 = 0;
  uStack_100 = 0;
  local_d8 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = (WDFDEVICE__ *)0x0;
  uStack_e0 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x16,
                     &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids);
  }
  local_148 = (WDFMEMORY__ *)0x0;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  local_118 = lVar8;
  lVar6 = AcpiGetIoTarget(param_1,(WDFIOTARGET__ **)(lVar8 + 0x40));
  if (lVar6 < 0) {
LAB_140013631:
    puVar16 = auStackY_198;
  }
  else {
    lVar6 = AcpiEnumChildren(param_1,&local_138);
    uVar23 = SUB81(param_1,0);
    if (lVar6 < 0) {
      puVar17 = auStackY_198;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013c2f;
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x17,
                         &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23,(char)lVar6);
      goto LAB_140013631;
    }
    local_110 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_138,0);
    puVar16 = auStackY_198;
    puVar17 = auStackY_198;
    puVar13 = auStackY_198;
    puVar15 = auStackY_198;
    puVar14 = auStackY_198;
    uVar20 = 1;
    local_138 = (WDFMEMORY__ *)CONCAT44(local_138._4_4_,1);
    pbVar10 = (byte *)(local_110 + 8);
    if (1 < *(uint *)(local_110 + 4)) {
LAB_140013681:
      local_128 = pbVar10 + (ulonglong)*(uint *)(pbVar10 + 4) + 8;
      if ((*local_128 & 1) != 0) {
        pbVar10 = local_128 + 8;
        lVar6 = AcpiEvaluateAdr(param_1,(char *)pbVar10,local_140);
        uVar5 = local_140[0];
        if (lVar6 < 0) goto LAB_1400139b8;
        if ((*(ulong *)(lVar8 + 0x30) != local_140[0]) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qLs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        memset(&local_b8,0,0x70);
        local_b8.Index = uVar5;
        lVar6 = AcpiEvaluatePld(param_1,(char *)pbVar10,&local_d0);
        if (-1 < lVar6) {
          local_b8.ConnectorId =
               (ulong64)(((uint)local_d0._8_4_ >> 0x10 & 0x7f80 | local_d0._8_4_ & 0x7f8000) >> 7);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qsLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          pbVar11 = pbVar10;
          lVar6 = AcpiEvaluateDsd(param_1,(char *)pbVar10,&local_148);
          if (-1 < lVar6) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pbVar11,6,0x1c,
                                 &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23,
                                 (char *)pbVar10);
            }
            pWVar22 = local_148;
            pWVar9 = (WDFMEMORY__ *)
                     (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_148,0);
            bVar21 = false;
            bVar4 = false;
            p_Var18 = (_ACPI_METHOD_ARGUMENT_V1 *)(pWVar9 + 3);
            local_148 = pWVar9;
            do {
              uVar12 = 4;
              if (3 < *(ushort *)(p_Var18 + 2)) {
                uVar12 = (ulonglong)*(ushort *)(p_Var18 + 2);
              }
              if ((_ACPI_METHOD_ARGUMENT_V1 *)
                  ((longlong)&pWVar9[3].unused + (ulonglong)(uint)pWVar9[1].unused) <=
                  p_Var18 + uVar12 + 4) {
                lVar7 = -0x3febfff1;
                lVar6 = -0x3febfff1;
                if (bVar4) {
                  puVar13 = auStackY_198;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140013a2c;
                  uVar19 = 0x20;
                  puVar15 = auStackY_198;
                }
                else {
                  puVar13 = auStackY_198;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140013a2c;
                  uVar19 = 0x1f;
                }
                goto LAB_140013ae1;
              }
              if (bVar21) {
                if (bVar4) goto LAB_14001388c;
              }
              else {
                lVar6 = AcpiParseGuid(p_Var18,&local_48,(ulong)pWVar9);
                if (lVar6 < 0) {
                  puVar13 = auStackY_198;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x1d,
                                      &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23);
                    puVar13 = auStackY_198;
                  }
                  goto LAB_140013a2c;
                }
                pWVar9 = local_148;
                if ((local_48 == 0x468840f46b856e62) && (lStack_40 == -0x219fdd7577a1b943)) {
                  bVar4 = true;
                }
              }
              uVar12 = (ulonglong)*(ushort *)(p_Var18 + 2);
              bVar21 = (bool)(bVar21 ^ 1);
              if (*(ushort *)(p_Var18 + 2) < 4) {
                uVar12 = 4;
              }
              p_Var18 = p_Var18 + uVar12 + 4;
            } while( true );
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x1b,
                                &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23,
                                (char *)pbVar10,(char)lVar6);
          }
          pWVar22 = local_148;
          goto LAB_140013a2c;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013c2f;
        WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x19,
                            &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23,(char *)pbVar10,
                            (char)lVar6);
        goto LAB_140013631;
      }
      goto LAB_1400139b8;
    }
LAB_1400139d5:
    if (*(int *)(lVar8 + 0x30) == 0) {
      lVar6 = -0x3febfff1;
      puVar17 = auStackY_198;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013c2f;
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x22,
                         &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar23,0xf);
      puVar13 = auStackY_198;
      pWVar22 = (WDFMEMORY__ *)0x0;
LAB_140013a2c:
      puVar16 = puVar13;
      if (pWVar22 != (WDFMEMORY__ *)0x0) {
        pcVar2 = *(code **)(WdfFunctions_01015 + 0x680);
        *(undefined8 *)(puVar13 + -8) = 0x140013a52;
        (*pcVar2)(WdfDriverGlobals,pWVar22);
      }
    }
  }
  puVar17 = puVar16;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar16 + 0x20) = &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids;
    *(undefined8 *)(puVar16 + -8) = 0x140013c2f;
    WPP_RECORDER_SF_(uVar3,5,6,0x23,*(undefined8 *)(puVar16 + 0x20));
  }
LAB_140013c2f:
  *(undefined8 *)(puVar17 + -8) = 0x140013c3d;
  return lVar6;
LAB_14001388c:
  lVar6 = CapStoreParseAcpiDsdData(param_1,&local_b8,p_Var18);
  if (lVar6 < 0) {
    puVar13 = auStackY_198;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013a2c;
    uVar19 = 0x1e;
    puVar15 = auStackY_198;
    lVar7 = lVar6;
  }
  else {
    local_d8 = 0;
    local_f8 = 0;
    uStack_100 = 0;
    local_108 = 0x38;
    uStack_e0 = 0;
    uStack_f0 = 0x100000001;
    local_e8 = param_1;
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,&local_108,0x200,0);
    lVar8 = local_118;
    lVar7 = lVar6;
    if (-1 < lVar6) {
      *local_130 = (longlong)local_b8.ConnectorList.Flink;
      local_130[1] = (longlong)local_b8.ConnectorList.Blink;
      local_130[2] = CONCAT44(local_b8._20_4_,local_b8.Index);
      local_130[3] = local_b8.ConnectorId;
      local_130[4] = local_b8._32_8_;
      local_130[5] = local_b8._40_8_;
      local_130[6] = local_b8._48_8_;
      local_130[7] = (longlong)local_b8.PdSourcePdos;
      local_130[8] = local_b8._64_8_;
      local_130[9] = (longlong)local_b8.PdSinkPdos;
      *(ulong *)(local_130 + 10) = local_b8.PdSinkPdosCount;
      *(undefined4 *)((longlong)local_130 + 0x54) = local_b8._84_4_;
      *(undefined4 *)(local_130 + 0xb) = local_b8.SupportedPdAlternateModes._0_4_;
      *(undefined4 *)((longlong)local_130 + 0x5c) = local_b8.SupportedPdAlternateModes._4_4_;
      *(ulong *)(local_130 + 0xc) = local_b8.SupportedPdAlternateModesCount;
      *(_WDF_TRI_STATE *)((longlong)local_130 + 100) = local_b8.DeferUrsStateUpdate;
      *(_WDF_TRI_STATE *)(local_130 + 0xd) = local_b8.HardwareCCDebounce;
      *(undefined4 *)((longlong)local_130 + 0x6c) = local_b8._108_4_;
      plVar1 = *(longlong **)(local_118 + 0x28);
      if (*plVar1 == local_118 + 0x20) {
        local_130[1] = (longlong)plVar1;
        *local_130 = local_118 + 0x20;
        *plVar1 = (longlong)local_130;
        *(longlong **)(local_118 + 0x28) = local_130;
        *(int *)(local_118 + 0x30) = *(int *)(local_118 + 0x30) + 1;
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,pWVar22);
        local_148 = (WDFMEMORY__ *)0x0;
        uVar20 = (uint)local_138;
LAB_1400139b8:
        uVar20 = uVar20 + 1;
        local_138 = (WDFMEMORY__ *)CONCAT44(local_138._4_4_,uVar20);
        pbVar10 = local_128;
        if (*(uint *)(local_110 + 4) <= uVar20) goto LAB_1400139d5;
        goto LAB_140013681;
      }
      pcVar2 = (code *)swi(0x29);
      lVar7 = (*pcVar2)(3);
      puVar14 = auStackY_190;
    }
    puVar13 = puVar14;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140013a2c;
    uVar19 = 0x21;
    puVar15 = puVar14;
  }
LAB_140013ae1:
  *(long *)(puVar15 + 0x30) = lVar7;
  *(WDFDEVICE__ **)(puVar15 + 0x28) = param_1;
  *(undefined **)(puVar15 + 0x20) = &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids;
  uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(undefined8 *)(puVar15 + -8) = 0x140013b07;
  WPP_RECORDER_SF_id(uVar3,2,6,uVar19,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28],puVar15[0x30]);
  puVar13 = puVar15;
  goto LAB_140013a2c;
}



===== CapStoreParseAcpiDsdData @ 140013c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CapStoreParseAcpiDsdData(struct WDFDEVICE__ * __ptr64,struct _CAPSTORE_CONNECTOR *
   __ptr64,struct _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64) */

long __cdecl
CapStoreParseAcpiDsdData
          (WDFDEVICE__ *param_1,_CAPSTORE_CONNECTOR *param_2,_ACPI_METHOD_ARGUMENT_V1 *param_3)

{
  ulong uVar1;
  uint uVar2;
  __uint64 _Var3;
  ulong64 uVar4;
  long lVar5;
  int iVar6;
  _UCM_PD_POWER_DATA_OBJECT *p_Var7;
  uint *puVar8;
  undefined2 *puVar9;
  ulonglong uVar10;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var11;
  int iVar12;
  undefined *puVar13;
  undefined2 uVar14;
  longlong lVar15;
  int iVar16;
  ulonglong uVar17;
  uint uVar18;
  int local_res20;
  undefined1 uVar19;
  undefined1 uVar20;
  _WDF_TRI_STATE local_58;
  ulong local_54;
  _ACPI_METHOD_ARGUMENT_V1 *local_50;
  ulong64 local_48;
  longlong local_40;
  
  local_54 = 0;
  local_58 = WdfFalse;
  lVar5 = 0;
  local_40 = (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  uVar19 = SUB81(param_1,0);
  if (*(short *)param_3 != 3) {
    lVar5 = -0x3febfff8;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3febfff8;
    }
    uVar14 = 0x24;
    uVar20 = 8;
    uVar18 = 6;
LAB_140013cef:
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar18,uVar14,
                       &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar19,uVar20);
    return lVar5;
  }
  local_50 = param_3 + 4;
  local_res20 = 0;
  uVar18 = 6;
  uVar17 = 4;
LAB_140013d31:
  puVar13 = &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids;
  uVar10 = (ulonglong)*(ushort *)(param_3 + 2);
  if (*(ushort *)(param_3 + 2) < (ushort)uVar17) {
    uVar10 = uVar17;
  }
  if (param_3 + uVar10 + 4 <= local_50) {
    return lVar5;
  }
  if (*(short *)local_50 != 3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar18,0x25,
                         &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,uVar19,(char)local_res20);
    }
    return -0x3febfff8;
  }
  p_Var11 = local_50 + 4;
  lVar15 = local_40;
  iVar16 = local_res20;
  lVar5 = AcpiParseULong(p_Var11,&local_54);
  uVar1 = local_54;
  if (lVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar18,0x26,puVar13,uVar19,
                          (char)iVar16,(char)lVar5);
      uVar17 = 4;
      iVar16 = local_res20;
    }
    goto LAB_14001420e;
  }
  uVar10 = (ulonglong)*(ushort *)(p_Var11 + 2);
  if (*(ushort *)(p_Var11 + 2) < (ushort)uVar17) {
    uVar10 = uVar17;
  }
  p_Var11 = p_Var11 + uVar10 + 4;
  if (uVar18 < local_54) {
    if (local_54 == 7) {
      lVar5 = AcpiParsePdPdos(param_1,p_Var11,&param_2->PdSinkPdos,&param_2->PdSinkPdosCount);
      if (lVar5 < 0) {
LAB_1400141c6:
        uVar17 = 4;
        iVar16 = local_res20;
        goto LAB_1400141d0;
      }
      _Var3 = param_2->ConnectorId;
      uVar1 = param_2->PdSinkPdosCount;
      p_Var7 = (_UCM_PD_POWER_DATA_OBJECT *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2->PdSinkPdos,0);
      UcmDumpPdos(p_Var7,uVar1,_Var3,'\0','\0');
      puVar8 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))
                                 (WdfDriverGlobals,param_2->PdSinkPdos,0);
      if (((puVar8 == (uint *)0x0) || (0x3fffffff < *puVar8)) || ((*puVar8 & 0xffc00) != 0x19000)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3febfff1;
        }
        uVar14 = 0x2a;
        goto LAB_140013f48;
      }
    }
    else {
      iVar6 = local_54 - 8;
      if (iVar6 != 0) goto LAB_140013f68;
      lVar5 = AcpiParsePdAlternateModes
                        (param_1,p_Var11,&param_2->SupportedPdAlternateModes,
                         &param_2->SupportedPdAlternateModesCount);
      if (lVar5 < 0) goto LAB_1400141c6;
      local_48 = param_2->ConnectorId;
      uVar2 = param_2->SupportedPdAlternateModesCount;
      puVar9 = (undefined2 *)
               (**(code **)(WdfFunctions_01015 + 0x610))
                         (WdfDriverGlobals,param_2->SupportedPdAlternateModes,0);
      uVar4 = local_48;
      uVar17 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        do {
          uVar10 = uVar17;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x74,
                                &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)uVar4,
                                (char)*puVar9,(char)*(undefined4 *)(puVar9 + 2));
          }
          puVar9 = puVar9 + 4;
          uVar17 = uVar10 - 1;
        } while (uVar17 != 0);
        uVar18 = (int)uVar10 + 5;
      }
    }
LAB_140014200:
    uVar17 = 4;
    iVar16 = local_res20;
  }
  else {
    if (local_54 == uVar18) {
      lVar5 = AcpiParsePdPdos(param_1,p_Var11,&param_2->PdSourcePdos,&param_2->PdSourcePdosCount);
      if (lVar5 < 0) goto LAB_1400141c6;
      _Var3 = param_2->ConnectorId;
      uVar1 = param_2->PdSourcePdosCount;
      p_Var7 = (_UCM_PD_POWER_DATA_OBJECT *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,param_2->PdSourcePdos,0);
      UcmDumpPdos(p_Var7,uVar1,_Var3,'\x01','\0');
      puVar8 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))
                                 (WdfDriverGlobals,param_2->PdSourcePdos,0);
      if (((puVar8 != (uint *)0x0) && (*puVar8 < 0x40000000)) && ((*puVar8 & 0xffc00) == 0x19000))
      goto LAB_140014200;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3febfff1;
      }
      uVar14 = 0x29;
LAB_140013f48:
      lVar5 = -0x3febfff1;
      uVar20 = 0xf;
      goto LAB_140013cef;
    }
    if ((local_54 != 1) && (iVar6 = local_54 - 2, iVar6 != 0)) {
LAB_140013f68:
      if ((iVar6 != 1) && ((iVar6 != 2 && (iVar6 != 3)))) {
        lVar5 = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001420e;
        WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar18,0x2b,puVar13,uVar19,
                            (char)local_54,(char)iVar16);
        goto LAB_140014200;
      }
    }
    lVar5 = AcpiParseULong(p_Var11,&local_58);
    if (lVar5 < 0) {
LAB_1400141d0:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        goto LAB_140014200;
      }
    }
    else if (uVar1 == 1) {
      param_2->SupportedOperatingModes = local_58;
    }
    else if (uVar1 == 2) {
      param_2->SupportedTypeCPowerSourcingCapabilities = local_58;
    }
    else if (uVar1 == 3) {
      param_2->AudioAccessoryCapable = local_58;
    }
    else if (uVar1 == 4) {
      param_2->IsPdSupported = local_58;
    }
    else {
      iVar6 = uVar1 - 5;
      if (iVar6 == 0) {
        param_2->SupportedPowerRoles = local_58;
      }
      else {
        iVar12 = iVar6 - (int)uVar17;
        if (iVar6 == (int)uVar17) {
          param_2->DeferUrsStateUpdate = local_58;
        }
        else if (iVar12 == 1) {
          param_2->HardwareCCDebounce = local_58;
        }
        else if (iVar12 == 2) {
          if (*(char *)(lVar15 + 0x48) == '\0') {
            *(char *)(lVar15 + 0x49) = (char)(local_58 >> 8);
            *(undefined1 *)(lVar15 + 0x48) = 1;
            *(char *)(lVar15 + 0x4a) = (char)local_58;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
              goto LAB_140014200;
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            goto LAB_140014200;
          }
        }
      }
    }
  }
LAB_14001420e:
  local_res20 = iVar16 + 1;
  uVar10 = (ulonglong)*(ushort *)(local_50 + 2);
  if (*(ushort *)(local_50 + 2) < (ushort)uVar17) {
    uVar10 = uVar17;
  }
  local_50 = local_50 + uVar10 + 4;
  goto LAB_140013d31;
}



===== WPP_RECORDER_SF_qDD @ 140014290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x28,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x28,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qLLi @ 140014384 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLLi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x2c,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,3,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x2c,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_qLi @ 14001449c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x27,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,3,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x27,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qLs @ 140014590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLs(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000040[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,4,pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000040[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(param_1,3,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,in_stack_00000040,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_qqqd @ 14001470c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc000000d;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x13,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x13,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qsLi @ 14001482c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsLi(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000038 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000038[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x1a,&uStack0000000000000030,8,
               pcVar3,lVar2,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  lVar2 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000038[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,4,6,&WPP_2ef6ecab836f302bb4782560ea144323_Traceguids,0x1a,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== PolicyGetDeferUrsStateUpdate @ 1400149d0 =====

/* long __cdecl PolicyGetDeferUrsStateUpdate(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_DEFER_URS_STATE_UPDATE * __ptr64) */

long __cdecl
PolicyGetDeferUrsStateUpdate
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_DEFER_URS_STATE_UPDATE *param_2)

{
  uchar uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  long lVar4;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffd8;
  
  uVar2 = SUB81(param_2,0);
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 7;
    in_stack_ffffffffffffffd8 = &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids;
    uVar2 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x35,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_DEFER_URS_STATE_UPDATE *)0x0) || (param_2->Size != 8)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    uVar1 = param_1->DeferUrsStateUpdate;
    param_2->IsEnabled = uVar1;
    lVar4 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_ic(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar3,uVar2),in_R8,0x36,
                       in_stack_ffffffffffffffd8,(char)(param_1->Config).ConnectorId,uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x37,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar4;
}



===== PolicyGetHardwareCCDebounce @ 140014ac8 =====

/* long __cdecl PolicyGetHardwareCCDebounce(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_HARDWARE_CC_DEBOUNCE * __ptr64) */

long __cdecl
PolicyGetHardwareCCDebounce
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_HARDWARE_CC_DEBOUNCE *param_2)

{
  uchar uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  long lVar4;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffd8;
  
  uVar2 = SUB81(param_2,0);
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 7;
    in_stack_ffffffffffffffd8 = &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids;
    uVar2 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x38,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_HARDWARE_CC_DEBOUNCE *)0x0) || (param_2->Size != 8)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    uVar1 = param_1->HardwareCCDebounce;
    param_2->IsEnabled = uVar1;
    lVar4 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_ic(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar3,uVar2),in_R8,0x39,
                       in_stack_ffffffffffffffd8,(char)(param_1->Config).ConnectorId,uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3a,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar4;
}



===== PolicyGetPdAlternateModeToNegotiate @ 140014bc0 =====

/* long __cdecl PolicyGetPdAlternateModeToNegotiate(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODE_TO_NEGOTIATE * __ptr64) */

long __cdecl
PolicyGetPdAlternateModeToNegotiate
          (_UCMCONNECTOR_CONTEXT *param_1,
          _UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODE_TO_NEGOTIATE *param_2)

{
  _UCM_PD_ALTERNATE_MODE _Var1;
  long lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1f,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODE_TO_NEGOTIATE *)0x0) ||
     (param_2->Size != 0xc)) {
    lVar2 = -0x3ffffff3;
  }
  else if ((param_1->PolicyPreparedPdAlternateModeToNegotiate).SVID == 0) {
    lVar2 = -0x3ffffe7c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffe7c;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x20,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,0x84);
  }
  else {
    _Var1 = param_1->PolicyPreparedPdAlternateModeToNegotiate;
    lVar2 = 0;
    param_2->PdAlternateMode = _Var1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x21,
                        &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                        (char)(param_1->Config).ConnectorId,(char)_Var1.SVID,
                        (char)(param_2->PdAlternateMode).Mode);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x22,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar2;
}



===== PolicyGetPdAlternateModes @ 140014d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PolicyGetPdAlternateModes(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODES * __ptr64) */

long __cdecl
PolicyGetPdAlternateModes
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODES *param_2)

{
  long lVar1;
  _UCM_PD_ALTERNATE_MODE *p_Var2;
  ulong local_res10 [2];
  WDFMEMORY__ *local_res18;
  
  local_res10[0] = 0;
  local_res18 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1d,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if (((param_2 == (_UCM_CONNECTOR_POLICY_PD_ALTERNATE_MODES *)0x0) || (param_2->Size != 0x10)) ||
     (param_2->PdAlternateModes != (_UCM_PD_ALTERNATE_MODE *)0x0)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = CapStoreGetCapabilityMemory
                      (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,8,&local_res18,
                       local_res10);
    if (-1 < lVar1) {
      param_2->PdAlternateModeCount = local_res10[0];
      p_Var2 = (_UCM_PD_ALTERNATE_MODE *)
               (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_res18,0);
      param_2->PdAlternateModes = p_Var2;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1e,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar1;
}



===== PolicyGetPdEnabled @ 140014e38 =====

/* long __cdecl PolicyGetPdEnabled(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_ENABLED * __ptr64) */

long __cdecl
PolicyGetPdEnabled(_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_PD_ENABLED *param_2)

{
  uchar uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  long lVar4;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffd8;
  
  uVar2 = SUB81(param_2,0);
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 7;
    in_stack_ffffffffffffffd8 = &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids;
    uVar2 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x32,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_PD_ENABLED *)0x0) || (param_2->Size != 8)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    uVar1 = (param_1->PdConfig).IsSupported;
    param_2->IsEnabled = uVar1;
    lVar4 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_ic(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar3,uVar2),in_R8,0x33,
                       in_stack_ffffffffffffffd8,(char)(param_1->Config).ConnectorId,uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x34,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar4;
}



===== PolicyGetPdRequestDataObject @ 140014f30 =====

/* long __cdecl PolicyGetPdRequestDataObject(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_REQUEST_DATA_OBJECT * __ptr64) */

long __cdecl
PolicyGetPdRequestDataObject
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_PD_REQUEST_DATA_OBJECT *param_2)

{
  ulong uVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  long lVar4;
  
  uVar2 = SUB81(param_2,0);
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = 5;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x19,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_PD_REQUEST_DATA_OBJECT *)0x0) || (param_2->Size != 8)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    uVar1 = (param_1->PolicyPreparedPdRequestDataObject).Ul;
    if (uVar1 == 0) {
      lVar4 = -0x3ffffe7c;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffe7c;
      }
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x1a,
                         &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                         (char)(param_1->Config).ConnectorId,0x84);
    }
    else {
      (param_2->PdRequestDataObject).Ul = uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_iD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar3,uVar2),7,0x1b,
                           &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                           (char)(param_1->Config).ConnectorId,(char)uVar1);
      }
      lVar4 = 0;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1c,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar4;
}



===== PolicyGetPdSinkCapabilities @ 140015080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PolicyGetPdSinkCapabilities(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_SINK_CAPABILITIES * __ptr64) */

long __cdecl
PolicyGetPdSinkCapabilities
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_PD_SINK_CAPABILITIES *param_2)

{
  _UCM_PD_POWER_DATA_OBJECT *p_Var1;
  ulong uVar2;
  long lVar3;
  ulong local_res10 [2];
  WDFMEMORY__ *local_res18;
  
  local_res10[0] = 0;
  local_res18 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x16,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_PD_SINK_CAPABILITIES *)0x0) || (param_2->Size != 0x24)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    lVar3 = CapStoreGetCapabilityMemory
                      (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,7,&local_res18,
                       local_res10);
    uVar2 = local_res10[0];
    if (-1 < lVar3) {
      p_Var1 = param_2->PowerDataObjects;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x620))
                        (WdfDriverGlobals,local_res18,0,p_Var1,(ulonglong)local_res10[0] << 2);
      if (lVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar3;
        }
        WPP_RECORDER_SF_qiLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x17,
                   &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                   (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                   (uchar)uVar2,(char)lVar3);
      }
      else {
        param_2->PowerDataObjectCount = (uchar)uVar2;
        p_Var1->Ul = p_Var1->Ul & 0xf7ffffff | 0x26000000;
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x18,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar3;
}



===== PolicyGetPdSourceCapabilities @ 140015238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PolicyGetPdSourceCapabilities(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_PD_SOURCE_CAPABILITIES * __ptr64) */

long __cdecl
PolicyGetPdSourceCapabilities
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_PD_SOURCE_CAPABILITIES *param_2)

{
  _UCM_PD_POWER_DATA_OBJECT *p_Var1;
  ulong uVar2;
  long lVar3;
  ulong local_res10 [2];
  WDFMEMORY__ *local_res18;
  
  local_res10[0] = 0;
  local_res18 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x13,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_PD_SOURCE_CAPABILITIES *)0x0) || (param_2->Size != 0x24)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    lVar3 = CapStoreGetCapabilityMemory
                      (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,6,&local_res18,
                       local_res10);
    uVar2 = local_res10[0];
    if (-1 < lVar3) {
      p_Var1 = param_2->PowerDataObjects;
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x620))
                        (WdfDriverGlobals,local_res18,0,p_Var1,(ulonglong)local_res10[0] << 2);
      if (lVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar3;
        }
        WPP_RECORDER_SF_qiLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x14,
                   &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                   (char)param_1->UcmCxCtx->DeviceSelf,(char)(param_1->Config).ConnectorId,
                   (uchar)uVar2,(char)lVar3);
      }
      else {
        param_2->PowerDataObjectCount = (uchar)uVar2;
        p_Var1->Ul = p_Var1->Ul & 0xe7ffffff | 0x26000000;
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x15,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar3;
}



===== PolicyGetSupportedPowerRoles @ 1400153f0 =====

/* long __cdecl PolicyGetSupportedPowerRoles(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_SUPPORTED_POWER_ROLES * __ptr64) */

long __cdecl
PolicyGetSupportedPowerRoles
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_SUPPORTED_POWER_ROLES *param_2)

{
  ulong uVar1;
  long lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2e,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_SUPPORTED_POWER_ROLES *)0x0) || (param_2->Size != 8)) {
    lVar2 = -0x3ffffff3;
  }
  else if ((param_1->PdConfig).IsSupported == '\0') {
    lVar2 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x2f,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,0xbb);
  }
  else {
    uVar1 = (param_1->PdConfig).SupportedPowerRoles;
    param_2->PowerRoles = uVar1;
    lVar2 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x30,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,(char)uVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x31,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar2;
}



===== PolicyGetTypeCOperatingMode @ 140015540 =====

/* long __cdecl PolicyGetTypeCOperatingMode(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_TYPEC_OPERATING_MODE * __ptr64) */

long __cdecl
PolicyGetTypeCOperatingMode
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_TYPEC_OPERATING_MODE *param_2)

{
  long lVar1;
  _CAPSTORE_CONNECTOR *p_Var2;
  ulong uVar3;
  undefined8 uVar4;
  ulong local_res10 [2];
  undefined *in_stack_ffffffffffffffc8;
  
  local_res10[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,10,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_TYPEC_OPERATING_MODE *)0x0) || (param_2->Size != 8)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    p_Var2 = param_1->CapStoreConn;
    uVar4 = 1;
    lVar1 = CapStoreGetCapabilityUlong(param_1->UcmCxCtx->DeviceSelf,p_Var2,1,local_res10);
    if (lVar1 < 0) {
      uVar3 = (param_1->TypeCConfig).SupportedOperatingModes;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_idL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var2,uVar4,0xb,
                            in_stack_ffffffffffffffc8,(char)(param_1->Config).ConnectorId,
                            (char)lVar1,(char)uVar3);
      }
      lVar1 = 0;
    }
    else {
      uVar3 = local_res10[0];
    }
    if ((uVar3 & 4) == 0) {
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 2) == 0) {
          lVar1 = -0x3fffffcc;
          goto LAB_140015697;
        }
        param_2->TypeCOperatingMode = UcmTypeCOperatingModeUfp;
      }
      else {
        param_2->TypeCOperatingMode = UcmTypeCOperatingModeDfp;
      }
    }
    else {
      param_2->TypeCOperatingMode = UcmTypeCOperatingModeDrp;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0xc,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,(char)param_2->TypeCOperatingMode);
  }
LAB_140015697:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0xd,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar1;
}



===== PolicyGetTypeCSourceCurrentLevel @ 1400156ec =====

/* long __cdecl PolicyGetTypeCSourceCurrentLevel(struct _UCMCONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_POLICY_TYPEC_SOURCE_CURRENT_LEVEL * __ptr64) */

long __cdecl
PolicyGetTypeCSourceCurrentLevel
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_POLICY_TYPEC_SOURCE_CURRENT_LEVEL *param_2)

{
  _UCM_TYPEC_CURRENT _Var1;
  long lVar2;
  _UCM_TYPEC_CURRENT _Var3;
  _CAPSTORE_CONNECTOR *p_Var4;
  ulong uVar5;
  undefined8 uVar6;
  ulong local_res10 [2];
  undefined *in_stack_ffffffffffffffc8;
  
  local_res10[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0xe,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  if ((param_2 == (_UCM_CONNECTOR_POLICY_TYPEC_SOURCE_CURRENT_LEVEL *)0x0) || (param_2->Size != 8))
  {
    lVar2 = -0x3ffffff3;
  }
  else {
    p_Var4 = param_1->CapStoreConn;
    uVar6 = 2;
    lVar2 = CapStoreGetCapabilityUlong(param_1->UcmCxCtx->DeviceSelf,p_Var4,2,local_res10);
    if (lVar2 < 0) {
      uVar5 = (param_1->TypeCConfig).SupportedPowerSourcingCapabilities;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_idL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var4,uVar6,0xf,
                            in_stack_ffffffffffffffc8,(char)(param_1->Config).ConnectorId,
                            (char)lVar2,(char)uVar5);
      }
      lVar2 = 0;
    }
    else {
      uVar5 = local_res10[0];
    }
    if ((uVar5 & 4) == 0) {
      if ((uVar5 & 2) == 0) {
        if ((uVar5 & 1) == 0) {
          lVar2 = -0x3fffffcc;
        }
        else {
          param_2->TypeCSourceCurrentLevel = UcmTypeCCurrentDefaultUsb;
        }
      }
      else {
        param_2->TypeCSourceCurrentLevel = UcmTypeCCurrent1500mA;
      }
    }
    else {
      param_2->TypeCSourceCurrentLevel = UcmTypeCCurrent3000mA;
    }
    if (param_1->PolicyPreparedTypeCCurrentAdvertisement == UcmTypeCCurrentInvalid) {
      if (lVar2 < 0) goto LAB_14001589b;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_iLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      _Var1 = param_1->PolicyPreparedTypeCCurrentAdvertisement;
      if (lVar2 < 0) {
        param_2->TypeCSourceCurrentLevel = _Var1;
        lVar2 = 0;
      }
      else {
        _Var3 = param_2->TypeCSourceCurrentLevel;
        if ((int)_Var1 <= (int)param_2->TypeCSourceCurrentLevel) {
          _Var3 = _Var1;
        }
        param_2->TypeCSourceCurrentLevel = _Var3;
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x11,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,(char)param_2->TypeCSourceCurrentLevel);
  }
LAB_14001589b:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x12,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar2;
}



===== PolicyPreparePdAlternateModeToNegotiate @ 1400158f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PolicyPreparePdAlternateModeToNegotiate(struct _UCMCONNECTOR_CONTEXT *
   __ptr64,struct _UCM_PD_ALTERNATE_MODE * __ptr64,unsigned long,struct _UCM_PD_ALTERNATE_MODE *
   __ptr64) */

long __cdecl
PolicyPreparePdAlternateModeToNegotiate
          (_UCMCONNECTOR_CONTEXT *param_1,_UCM_PD_ALTERNATE_MODE *param_2,ulong param_3,
          _UCM_PD_ALTERNATE_MODE *param_4)

{
  _UCM_PD_ALTERNATE_MODE _Var1;
  long lVar2;
  _UCM_PD_ALTERNATE_MODE *p_Var3;
  _UCM_PD_ALTERNATE_MODE *p_Var4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  ulong local_res8 [2];
  undefined1 uVar9;
  WDFMEMORY__ *local_38 [2];
  
  local_38[0] = (WDFMEMORY__ *)0x0;
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x29,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  lVar2 = CapStoreGetCapabilityMemory
                    (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,8,local_38,local_res8);
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar9 = (undefined1)(param_1->Config).ConnectorId;
    uVar8 = 0x2a;
    bVar5 = 2;
  }
  else {
    uVar7 = 0;
    p_Var3 = (_UCM_PD_ALTERNATE_MODE *)
             (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_38[0],0);
    if (local_res8[0] != 0) {
      do {
        uVar6 = 0;
        if (param_3 != 0) {
          p_Var4 = param_2;
          do {
            if (p_Var3->SVID == p_Var4->SVID) {
              _Var1 = *p_Var3;
              *param_4 = _Var1;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x2b,
                                    &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                                    (char)(param_1->Config).ConnectorId,(char)_Var1.SVID,
                                    (char)param_4->Mode);
              }
              lVar2 = 0;
              goto LAB_140015a58;
            }
            uVar6 = uVar6 + 1;
            p_Var4 = p_Var4 + 1;
          } while (uVar6 < param_3);
        }
        uVar7 = uVar7 + 1;
        p_Var3 = p_Var3 + 1;
      } while (uVar7 < local_res8[0]);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffcc;
    }
    uVar9 = (undefined1)(param_1->Config).ConnectorId;
    uVar8 = 0x2c;
    lVar2 = -0x3fffffcc;
    bVar5 = 4;
  }
  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,7,uVar8,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,uVar9,(char)lVar2);
LAB_140015a58:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2d,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar2;
}



===== PolicyPrepareRdo @ 140015b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PolicyPrepareRdo(struct _UCMCONNECTOR_CONTEXT * __ptr64,union
   _UCM_PD_POWER_DATA_OBJECT * __ptr64,unsigned long,union _UCM_PD_REQUEST_DATA_OBJECT * __ptr64) */

long __cdecl
PolicyPrepareRdo(_UCMCONNECTOR_CONTEXT *param_1,_UCM_PD_POWER_DATA_OBJECT *param_2,ulong param_3,
                _UCM_PD_REQUEST_DATA_OBJECT *param_4)

{
  uint uVar1;
  _UCMCONNECTOR_CONTEXT *p_Var2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  ulong uVar8;
  _UCM_PD_POWER_DATA_OBJECT *p_Var9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  _UCMCONNECTOR_CONTEXT *local_res8;
  _UCM_PD_POWER_DATA_OBJECT *local_res10;
  uint local_58;
  ulong local_54;
  WDFMEMORY__ *local_50;
  long local_48;
  uint *local_40;
  
  local_50 = (WDFMEMORY__ *)0x0;
  local_54 = 0;
  local_res8 = param_1;
  local_res10 = (_UCM_PD_POWER_DATA_OBJECT *)&param_2->Ul;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x23,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  lVar3 = CapStoreGetCapabilityMemory
                    (param_1->UcmCxCtx->DeviceSelf,param_1->CapStoreConn,7,&local_50,&local_54);
  uVar8 = local_54;
  local_48 = lVar3;
  if (lVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar3;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x24,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,(char)lVar3);
    goto LAB_140015fba;
  }
  if ((local_54 == 0) || (param_3 == 0)) {
    lVar3 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    WPP_RECORDER_SF_iLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    goto LAB_140015fba;
  }
  local_40 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_50,0);
  p_Var2 = local_res8;
  uVar5 = 0xffffffff;
  local_50 = (WDFMEMORY__ *)((ulonglong)local_50 & 0xffffffff00000000);
  local_58 = 0;
  uVar6 = 0;
  uVar15 = 0;
  if (uVar8 == 0) {
LAB_140015f0a:
    uVar6 = *local_40 & 0x3ff;
    puVar7 = (uint *)(ulonglong)uVar6;
    uVar5 = local_res10->Ul;
    if (uVar6 <= (local_res10->Ul & 0x3ff)) {
      uVar5 = *local_40;
    }
    uVar5 = (uVar5 & 0x3ff | 0x5c000) << 10 | uVar6;
    local_res8 = (_UCMCONNECTOR_CONTEXT *)CONCAT44(local_res8._4_4_,uVar5);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar7 = (uint *)CONCAT71((uint7)(uint3)(uVar6 >> 8),3);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x26,
                        &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                        (char)(param_1->Config).ConnectorId);
    }
  }
  else {
    uVar11 = 0;
    do {
      uVar14 = 0;
      if (param_3 != 0) {
        uVar1 = local_40[uVar15];
        p_Var9 = local_res10;
        uVar10 = (uint)local_50;
        do {
          uVar13 = p_Var9->Ul;
          uVar4 = uVar13 >> 0x1e;
          if (uVar4 == uVar1 >> 0x1e) {
            uVar12 = uVar1;
            if (uVar4 == 0) {
              uVar4 = uVar13 >> 10 & 0x3ff;
              if ((uVar1 >> 10 & 0x3ff) == uVar4) {
                if ((uVar13 & 0x3ff) <= (uVar1 & 0x3ff)) {
                  uVar12 = uVar13;
                }
LAB_140015d96:
                uVar12 = uVar12 & 0x3ff;
                uVar13 = uVar12 * uVar4 * 500;
LAB_140015da7:
                if ((uVar11 < uVar13) || ((uVar13 == uVar11 && (uVar10 < uVar4)))) {
                  uVar11 = uVar13;
                  uVar10 = uVar4;
                  uVar5 = uVar14;
                  uVar6 = uVar12;
                }
              }
            }
            else if (uVar4 == 1) {
              if ((((uVar1 & 0x3ff00000) <= (uVar13 & 0x3ff00000)) &&
                  ((uVar13 & 0xffc00) <= (uVar1 & 0xffc00))) &&
                 ((uVar1 & 0x3ff) <= (uVar13 & 0x3ff))) {
                uVar13 = (uVar1 & 0x3ff) * 250000;
                uVar4 = uVar1 >> 0x14 & 0x3ff;
                uVar12 = uVar13 / (uVar4 * 500);
                goto LAB_140015da7;
              }
            }
            else if (((uVar4 == 2) && ((uVar1 & 0x3ff00000) <= (uVar13 & 0x3ff00000))) &&
                    (((uVar13 & 0xffc00) <= (uVar1 & 0xffc00) &&
                     ((uVar1 & 0x3ff) <= (uVar13 & 0x3ff))))) {
              uVar4 = uVar1 >> 0x14 & 0x3ff;
              goto LAB_140015d96;
            }
          }
          uVar14 = uVar14 + 1;
          p_Var9 = p_Var9 + 1;
        } while (uVar14 < param_3);
        local_50 = (WDFMEMORY__ *)CONCAT44(local_50._4_4_,uVar10);
        uVar8 = local_54;
        local_58 = uVar11;
      }
      uVar14 = (int)uVar15 + 1;
      uVar15 = (ulonglong)uVar14;
    } while (uVar14 < uVar8);
    param_1 = local_res8;
    lVar3 = local_48;
    if (uVar5 == 0xffffffff) goto LAB_140015f0a;
    uVar11 = (uVar5 + 1) * 0x10000000;
    uVar5 = local_res10[uVar5].Ul >> 0x1e;
    param_1 = p_Var2;
    if ((uVar5 == 0) || (uVar5 == 1)) {
      uVar5 = (uVar6 & 0x3ff | 0xc000) << 10 | uVar11 & 0x70000000 | uVar6 & 0x3ff;
      local_res8 = (_UCMCONNECTOR_CONTEXT *)CONCAT44(local_res8._4_4_,uVar5);
      puVar7 = local_40;
    }
    else {
      if (uVar5 != 2) {
        lVar3 = -0x3fffffff;
        goto LAB_140015fba;
      }
      uVar6 = local_58 / 250000 & 0x3ff;
      uVar5 = uVar6 << 10 | uVar11 & 0x70000000 | uVar6;
      local_res8 = (_UCMCONNECTOR_CONTEXT *)CONCAT44(local_res8._4_4_,uVar5);
      puVar7 = (uint *)(ulonglong)uVar6;
    }
  }
  param_4->Ul = uVar5;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_iD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,7,0x27,
                       &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,
                       (char)(param_1->Config).ConnectorId,(char)uVar5);
  }
  UcmDumpRdo((_UCM_PD_REQUEST_DATA_OBJECT *)&local_res8,(param_1->Config).ConnectorId);
LAB_140015fba:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x28,
                     &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids);
  }
  return lVar3;
}



===== WPP_RECORDER_SF_iD @ 14001600c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iD(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_iLL @ 140016138 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,0x10,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,0x10,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_iLLd @ 14001622c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_iLLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000001;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,0x25,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,7,&WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,0x25,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_ic @ 14001634c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ic(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,param_4,&param_6,8,&param_7,1,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,param_4,&param_6,8,
                  &param_7,1,0);
  return;
}



===== WPP_RECORDER_SF_idL @ 140016420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_idL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_783032c988a13c00a6d46d390c026ac4_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== CxRegister @ 140016514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CxRegister(struct _DRIVER_OBJECT * __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl CxRegister(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined2 uVar4;
  WDFDEVICE__ **in_R9;
  undefined1 auStackY_178 [32];
  undefined1 uVar5;
  longlong local_138;
  ushort local_130 [4];
  undefined1 *local_128;
  undefined1 local_118 [208];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_128 = local_118;
  local_130[0] = 0;
  local_130[1] = 200;
  local_130[2] = 0;
  local_130[3] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R9 = (WDFDEVICE__ **)0xa;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
  }
  local_138 = (**(code **)(WdfFunctions_01015 + 200))
                        (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
  if (local_138 == 0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016771;
    uVar4 = 0xb;
    uVar5 = 0x9a;
    iVar1 = -0x3fffff66;
  }
  else {
    uVar3 = 0;
    do {
      uVar2 = RtlUnicodeStringPrintf(local_130,L"\\Device\\UcmCx%u",(ulonglong)uVar3,in_R9);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016771;
        uVar4 = 0xc;
        goto LAB_140016749;
      }
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_138,local_130);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016771;
        uVar4 = 0xd;
        goto LAB_140016749;
      }
      in_R9 = &g_ClassLibraryDevice;
      iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_138,0);
      uVar3 = uVar3 + 1;
    } while (iVar1 == -0x3fffffcb);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140016771;
      uVar4 = 0xe;
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,g_ClassLibraryDevice);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      iVar1 = WdfRegisterClassLibrary(&g_WdfClassLibraryInfo,param_2,local_130);
      if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      goto LAB_140016771;
      uVar4 = 0x10;
    }
LAB_140016749:
    uVar5 = (undefined1)iVar1;
  }
  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,(char)param_1,uVar5);
LAB_140016771:
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
    local_138 = 0;
  }
  if ((iVar1 < 0) && (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0)) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
  }
  return iVar1;
}



===== RtlUnicodeStringPrintf @ 14001682c =====

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



===== WPP_RECORDER_SF_qZ @ 1400168cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qZ(undefined8 param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  pwVar3 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_140016994;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_14001693d:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_14001693d;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,0xf,&uStack0000000000000030,8,pwVar2,2
             ,pwVar4,wVar1,0);
LAB_140016994:
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 != L'\0') {
      pwVar3 = *(wchar_t **)(in_stack_00000038 + 4);
    }
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"\b";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,0xf,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== PnpEventHandlerKm @ 140016a30 =====

/* long __cdecl PnpEventHandlerKm(void * __ptr64,void * __ptr64) */

long __cdecl PnpEventHandlerKm(void *param_1,void *param_2)

{
  long lVar1;
  uchar uVar2;
  undefined7 uVar3;
  void *pvVar4;
  
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
  lVar1 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x10,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  if ((*(longlong *)((longlong)param_1 + 4) == 0x11d046f0cb3a4004) &&
     (*(longlong *)((longlong)param_1 + 0xc) == 0x3f05139760008fb0)) {
    uVar2 = '\x01';
  }
  else {
    if ((*(longlong *)((longlong)param_1 + 4) != 0x11d046f0cb3a4005) ||
       (*(longlong *)((longlong)param_1 + 0xc) != 0x3f05139760008fb0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF__guid_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      goto LAB_140016b3a;
    }
    uVar2 = '\0';
  }
  pvVar4 = param_2;
  lVar1 = PnPEventHandler(*(_UNICODE_STRING **)((longlong)param_1 + 0x28),uVar2,param_2);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(uVar3,uVar2),pvVar4,0x12,
                       &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids,
                       *(char **)((longlong)param_2 + 8),(char)lVar1);
  }
LAB_140016b3a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x13,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  return lVar1;
}



===== UcmDeregisterForPnPEvents @ 140016b8c =====

/* long __cdecl UcmDeregisterForPnPEvents(void * __ptr64) */

long __cdecl UcmDeregisterForPnPEvents(void *param_1)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xd,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  if (param_1 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = IoUnregisterPlugPlayNotification(param_1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xe,
                        &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids,(char)iVar1);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xf,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  return iVar1;
}



===== UcmRegisterForPnPEvents @ 140016c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UcmRegisterForPnPEvents(struct _PNP_CALLBACK_CONFIG * __ptr64) */

long __cdecl UcmRegisterForPnPEvents(_PNP_CALLBACK_CONFIG *param_1)

{
  void **ppvVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  _GUID *p_Var5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  ppvVar1 = param_1->Handle;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  uVar4 = 1;
  p_Var5 = &param_1->InterfaceGuid;
  iVar2 = IoRegisterPlugPlayNotification(2,1,p_Var5,uVar3,PnpEventHandlerKm,param_1,ppvVar1);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,p_Var5,0xb,
                       &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids,param_1->InterfaceName,
                       (char)iVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xc,
                     &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids);
  }
  return iVar2;
}



===== WPP_RECORDER_SF__guid_s @ 140016dbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid_s(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong in_stack_00000038;
  
  lVar2 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 != 0) {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (*(char *)(in_stack_00000038 + lVar1) != '\0');
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids,0x11);
  }
  if (in_stack_00000038 != 0) {
    do {
      lVar2 = lVar2 + 1;
    } while (*(char *)(in_stack_00000038 + lVar2) != '\0');
  }
  WppAutoLogTrace(param_1,3,2,&WPP_1d63a5c03c573741c5eb4ab50f5dc3bd_Traceguids,0x11);
  return;
}



===== FxStubDriverUnloadCommon @ 140016f04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14002a358 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14002a358 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_140016f5d:
      if (ppvVar1 == (void **)0x0) goto LAB_140016fb3;
      if (ppvVar2 <= ppvVar1) goto LAB_140016fcb;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_140016f5d;
LAB_140016fb3:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_140016fcb:
  WdfVersionUnbind(&DAT_14002a470,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140017000 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140017034 =====

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
    _DAT_14002a470 = 0x2080000;
    _DAT_14002a478 = &DAT_14002a4d0;
    RtlCopyUnicodeString(&DAT_14002a470);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14002a470,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (param_1->DriverUnload != (_func___cdecl_void__DRIVER_OBJECT_ptr *)0x0) {
              DAT_14002a6d8 = param_1->DriverUnload;
            }
            param_1->DriverUnload = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14002a470);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14002a358 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1400171c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14002a6d8 != (code *)0x0) && (DAT_14002a6d8 != FxStubDriverUnload)) {
    (*DAT_14002a6d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1400171f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140017219) */
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
    if ((void **)0x14002a34f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14002a358 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 14001737c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140017399) */
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
    if ((void **)0x14002a36f < ppvVar2) break;
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



===== TraceLoggingPolicyManagerInitialize @ 140017444 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingPolicyManagerInitialize(long,unsigned long) */

void __cdecl TraceLoggingPolicyManagerInitialize(long param_1,ulong param_2)

{
  undefined1 auStackY_98 [32];
  ulong local_68;
  long local_64 [3];
  undefined8 local_58 [4];
  long *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((5 < DAT_14002a278) && ((_DAT_14002a288 & 0x400000000000) != 0)) &&
     ((DAT_14002a290 & 0x400000000000) == DAT_14002a290)) {
    local_28 = &local_68;
    local_1c = 0;
    local_38 = local_64;
    local_20 = 4;
    local_2c = 0;
    local_30 = 4;
    local_68 = param_2;
    local_64[0] = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a278,&DAT_140027b3e,0,0,4,local_58);
  }
  return;
}



===== PolicyManagerConnectorCreate @ 140017504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PolicyManagerConnectorCreate(undefined8 param_1,undefined8 *param_2,longlong *param_3)

{
  _UPM_CONNECTOR_CONTEXT *p_Var1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  int iVar9;
  longlong *plVar10;
  _UPM_CONNECTOR_CONTEXT *p_Var11;
  longlong *plVar12;
  short *psVar13;
  ulonglong uVar14;
  undefined2 uVar15;
  longlong local_res20;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  longlong local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  longlong local_b0;
  undefined8 local_a8;
  code *pcStack_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined8 local_84;
  code *local_60;
  
  local_res20 = 0;
  local_98 = 0;
  local_a8 = 0;
  pcStack_a0 = (code *)0x0;
  memset(&local_88,0,0x60);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1c,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  plVar10 = (longlong *)
            (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268);
  local_b8 = PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240;
  local_e8 = 0x38;
  uStack_e4 = 0;
  local_d8 = 0;
  uStack_d4 = 0;
  uStack_c0 = 0;
  uStack_d0 = 0x100000001;
  local_c8 = *plVar10;
  uStack_e0 = 0x40018e30;
  uStack_dc = 1;
  iVar9 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_e8,&local_res20);
  if (iVar9 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                        &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)iVar9);
    }
  }
  else {
    p_Var11 = (_UPM_CONNECTOR_CONTEXT *)
              (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res20,
                         PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
    uVar2 = param_2[1];
    uVar4 = param_2[2];
    uVar5 = param_2[3];
    *(undefined8 *)(p_Var11 + 8) = *param_2;
    *(undefined8 *)(p_Var11 + 0x10) = uVar2;
    *(longlong **)p_Var11 = plVar10;
    uVar2 = param_2[4];
    uVar6 = param_2[5];
    *(undefined8 *)(p_Var11 + 0x18) = uVar4;
    *(undefined8 *)(p_Var11 + 0x20) = uVar5;
    *(undefined4 *)(p_Var11 + 0x19d8) = 0;
    uVar4 = param_2[6];
    uVar5 = param_2[7];
    *(undefined8 *)(p_Var11 + 0x28) = uVar2;
    *(undefined8 *)(p_Var11 + 0x30) = uVar6;
    uVar6 = param_2[8];
    uVar7 = param_2[9];
    *(undefined8 *)(p_Var11 + 0x38) = uVar4;
    *(undefined8 *)(p_Var11 + 0x40) = uVar5;
    uVar2 = param_2[10];
    *(undefined8 *)(p_Var11 + 0x48) = uVar6;
    *(undefined8 *)(p_Var11 + 0x50) = uVar7;
    *(undefined8 *)(p_Var11 + 0x58) = uVar2;
    uVar3 = *(uint *)(p_Var11 + 0x24);
    if ((uVar3 & 4) == 0) {
      if ((uVar3 & 2) == 0) {
        *(uint *)(p_Var11 + 0x19c8) = uVar3 & 1;
      }
      else {
        *(undefined4 *)(p_Var11 + 0x19c8) = 2;
      }
    }
    else {
      *(undefined4 *)(p_Var11 + 0x19c8) = 4;
    }
    local_d8 = 0;
    uStack_d4 = 0;
    uStack_e4 = 0;
    uStack_e0 = 0;
    uStack_dc = 0;
    uStack_d0 = 0x100000001;
    p_Var1 = p_Var11 + 0x19e0;
    uStack_c0 = 0;
    local_b8 = (undefined *)0x0;
    local_e8 = 0x38;
    local_c8 = *plVar10;
    iVar9 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_e8,p_Var1);
    if (iVar9 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar15 = 0x1e;
        goto LAB_140017795;
      }
    }
    else {
      pcStack_a0 = UpmConnectorWorkItemCallback;
      local_b8 = PTR__WDF_UPMCONNECTOR_WORKITEM_CONTEXT_TYPE_INFO_14002a218;
      local_a8 = CONCAT44(local_a8._4_4_,0x18);
      local_98 = CONCAT71(local_98._1_7_,1);
      iVar9 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                        (WdfDriverGlobals,&local_a8,&local_e8,p_Var11 + 0x1a18);
      lVar8 = local_res20;
      if (iVar9 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                            &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)iVar9);
        }
      }
      else {
        plVar12 = (longlong *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,*(undefined8 *)(p_Var11 + 0x1a18),
                             PTR__WDF_UPMCONNECTOR_WORKITEM_CONTEXT_TYPE_INFO_14002a218);
        *plVar12 = lVar8;
        KeInitializeEvent(p_Var11 + 0x1a00,0,0);
        KeSetEvent(p_Var11 + 0x1a00,0,0);
        uVar3 = *(uint *)(param_2 + 6);
        uVar14 = (ulonglong)uVar3;
        *(undefined4 *)(p_Var11 + 0x19f0) = 0;
        *(undefined8 *)(p_Var11 + 0x1a28) = 0;
        *(undefined2 *)(p_Var11 + 0x1a30) = 0;
        if (uVar3 != 0) {
          psVar13 = (short *)param_2[5];
          do {
            if (*psVar13 == -0x7f79) {
              p_Var11[0x1a2d] = (_UPM_CONNECTOR_CONTEXT)0x1;
            }
            if (*psVar13 == -0xff) {
              p_Var11[0x1a2c] = (_UPM_CONNECTOR_CONTEXT)0x1;
            }
            psVar13 = psVar13 + 4;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
        local_b0 = 0;
        iVar9 = PmWnfCreateSecurityDescriptor(&local_b0);
        lVar8 = local_b0;
        if (-1 < iVar9) {
          iVar9 = ZwCreateWnfStateName(p_Var11 + 0x19cc,3,0,0,0,0,local_b0);
        }
        if (lVar8 != 0) {
          ExFreePoolWithTag(lVar8,0x53574d50);
        }
        if (iVar9 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x21;
LAB_140017795:
            WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar15,
                              &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)iVar9);
          }
        }
        else {
          local_60 = UpmConnectorAssignPowerLevelEvtIoDeviceControl;
          local_b8 = PTR__WDF_UPMCONNECTOR_ACPLQUEUE_CONTEXT_TYPE_INFO_14002a1f0;
          local_c8 = local_res20;
          local_88 = 0x60;
          local_84 = 1;
          uStack_e4 = 0;
          uStack_e0 = 0;
          uStack_dc = 0;
          local_d8 = 0;
          uStack_d4 = 0;
          uStack_c0 = 0;
          local_e8 = 0x38;
          uStack_d0 = 0x100000002;
          iVar9 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                            (WdfDriverGlobals,*plVar10,&local_88,&local_e8,p_Var11 + 0x1a38);
          if (iVar9 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = 0x22;
              goto LAB_140017795;
            }
          }
          else {
            plVar12 = (longlong *)
                      (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,*(undefined8 *)(p_Var11 + 0x1a38),
                                 PTR__WDF_UPMCONNECTOR_ACPLQUEUE_CONTEXT_TYPE_INFO_14002a1f0);
            *plVar12 = local_res20;
            iVar9 = (**(code **)(WdfFunctions_01015 + 0x78))
                              (WdfDriverGlobals,plVar10[4],local_res20);
            if (-1 < iVar9) {
              *param_3 = local_res20;
              (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)p_Var1,0);
              UpmConnectorIndicateStateChange(p_Var11);
              (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)p_Var1);
              goto LAB_140017b0a;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar15 = 0x23;
              goto LAB_140017795;
            }
          }
        }
      }
    }
  }
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_140017b0a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x24,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  return iVar9;
}



===== PolicyManagerInitialize @ 140017b68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PolicyManagerInitialize(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  _UPM_DEVICE_CONTEXT *p_Var5;
  undefined2 uVar6;
  undefined1 auStackY_178 [32];
  _UPM_DEVICE_CONTEXT *local_138;
  int local_130 [2];
  undefined8 local_128;
  undefined8 local_120;
  code *pcStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined *local_f0;
  undefined8 local_e8;
  undefined8 *local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  code *local_b0;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  memset(&local_d8,0,0x60);
  local_40 = 0x65;
  local_78 = 0x61007300690044;
  uStack_70 = 0x500065006c0062;
  local_138 = (_UPM_DEVICE_CONTEXT *)0x0;
  local_128 = 0;
  local_68 = 0x630069006c006f;
  uStack_60 = 0x6e0061004d0079;
  local_e8 = 0x3c003a;
  local_58 = 0x72006500670061;
  uStack_50 = 0x650074006e0049;
  local_48 = 0x63006100660072;
  local_130[0] = 0;
  local_e0 = &local_78;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  local_f0 = PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268;
  local_120 = 0x38;
  pcStack_118 = UpmDeviceContextCleanup;
  local_110 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  uStack_108 = 0x100000001;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_1,&local_120,&local_138);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017fc8;
    uVar6 = 0xf;
  }
  else {
    uVar1 = *param_2;
    *(undefined8 *)local_138 = param_1;
    *(undefined4 *)(local_138 + 8) = uVar1;
    local_f0 = (undefined *)0x0;
    local_110 = 0;
    pcStack_118 = (code *)0x0;
    local_120 = 0x38;
    uStack_f8 = 0;
    uStack_108 = 0x100000001;
    *(undefined8 *)(local_138 + 0x40) = 0;
    *(undefined8 *)(local_138 + 0x48) = 0;
    local_100 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_120,local_138 + 0x18);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017fc8;
      uVar6 = 0x10;
    }
    else {
      p_Var5 = local_138 + 0x20;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_120);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140017fc8;
        uVar6 = 0x11;
      }
      else {
        UsbDualRoleFeaturesQueryLocalMachine((uint *)(local_138 + 0x2c));
        iVar2 = PmWnfSubscribeChangeNotification
                          ((undefined8 *)&WNF_USB_TYPE_C_PARTNER_STATE,0xd,p_Var5,0x14001b9b0,
                           local_138,(undefined8 *)(local_138 + 0x10));
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140017fc8;
          uVar6 = 0x12;
        }
        else {
          local_b0 = UpmClientEvtIoDeviceControl;
          local_d8 = 0x60;
          local_d4 = 1;
          uStack_108 = CONCAT44(uStack_108._4_4_,2);
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                            (WdfDriverGlobals,param_1,&local_d8,&local_120);
          if (-1 < iVar2) {
            if (*(char *)((longlong)param_2 + 1) != '\0') {
              iVar2 = UpmBpInitialize(local_138);
              if (iVar2 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_140017fc8;
                uVar6 = 0x14;
                goto LAB_140017cbf;
              }
            }
            local_138[0xc] = (_UPM_DEVICE_CONTEXT)0x0;
            uVar3 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,param_1,1,0x20019);
            if ((int)uVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar6 = 0x16;
                bVar4 = 3;
LAB_140017fa8:
                WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar4,1,uVar6,
                                   &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)param_1,
                                   (char)uVar3);
              }
            }
            else {
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))
                                (WdfDriverGlobals,local_128,&local_e8,local_130);
              if (iVar2 < 0) {
                if (iVar2 != -0x3fffffcc) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140017fc5;
                  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x17,
                                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)param_1,
                                     (char)iVar2);
                }
              }
              else {
                local_138[0xc] = (_UPM_DEVICE_CONTEXT)(local_130[0] != 0);
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar6 = 0x18;
                bVar4 = 4;
                uVar3 = (uint)(byte)local_138[0xc];
                goto LAB_140017fa8;
              }
            }
LAB_140017fc5:
            iVar2 = 0;
            goto LAB_140017fc8;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140017fc8;
          uVar6 = 0x13;
        }
      }
    }
  }
LAB_140017cbf:
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                    &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)iVar2);
LAB_140017fc8:
  TraceLoggingPolicyManagerInitialize(iVar2,*(ulong *)(local_138 + 0x2c));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  return iVar2;
}



===== PolicyManagerInspectIoCtlForInterception @ 140018040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PolicyManagerInspectIoCtlForInterception(undefined8 param_1,int param_2)

{
  bool bVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2a,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268);
  if (((((param_2 == 0x574200) || (param_2 == 0x574204)) || (param_2 == 0x574208)) ||
      ((param_2 == 0x57420c || (param_2 == 0x574210)))) || (bVar1 = false, param_2 == 0x578214)) {
    bVar1 = true;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2b,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  if (bVar1) {
    uVar3 = *(undefined8 *)(lVar2 + 0x30);
  }
  return uVar3;
}



===== PolicyManagerTraceLoggingUnregister @ 140018148 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PolicyManagerTraceLoggingUnregister(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  puVar6 = auStackY_38;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStackY_38;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar6 = auStackY_30;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140018227;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140018244;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar2 = DAT_14002e098;
    DAT_14002e098 = 0;
    DAT_14002e078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001826b;
    EtwUnregister(uVar2);
    uVar2 = DAT_14002e028;
    DAT_14002e028 = 0;
    _DAT_14002e008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001828b;
    EtwUnregister(uVar2);
    uVar2 = DAT_14002e060;
    DAT_14002e060 = 0;
    DAT_14002e040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x1400182ab;
    EtwUnregister(uVar2);
  }
  uVar2 = DAT_14002a298;
  DAT_14002a298 = 0;
  DAT_14002a278 = 0;
  *(undefined8 *)(puVar6 + -8) = 0x1400182cb;
  EtwUnregister(uVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar6 + 0x20) = &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids;
    *(undefined8 *)(puVar6 + -8) = 0x140018300;
    WPP_RECORDER_SF_(uVar2,5,1,0xd,*(undefined8 *)(puVar6 + 0x20));
  }
  return;
}



===== PolicyManagerUcmConnectorSetPowerLevelCompleted @ 140018324 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PolicyManagerUcmConnectorSetPowerLevelCompleted(undefined8 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2e,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  puVar1 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar4 = 0;
  uVar2 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9c8))();
  lVar3 = puVar1[0x348];
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 1;
      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_qi(uVar2,2,1,0x2f,&WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,
                         (char)*(undefined8 *)*puVar1,(char)puVar1[2]);
    }
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (uVar2,0,uVar4,"UCM reports unexpected SetPowerLevel completion.");
    lVar3 = 0;
  }
  else {
    puVar1[0x348] = 0;
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,puVar1[0x33c]);
  if (lVar3 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                 &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,(char)*(undefined8 *)*puVar1,
                 (char)puVar1[2],(char)lVar3,(char)param_2);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar3,param_2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x31,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  return;
}



===== PolicyManagerUcmInterfaceReady @ 14001850c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PolicyManagerUcmInterfaceReady(undefined8 param_1)

{
  int iVar1;
  _UPM_DEVICE_CONTEXT *p_Var2;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x25,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  p_Var2 = (_UPM_DEVICE_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268);
  uVar3 = (undefined1)param_1;
  if (p_Var2[0xc] == (_UPM_DEVICE_CONTEXT)0x0) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_USB_POLICY_MANAGER,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x27,
                         &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,uVar3,(char)iVar1);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x270))
                (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_USB_POLICY_MANAGER,0,1);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x28,
                          &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,uVar3);
      }
      UpmDevicePublishWnfStateForHubCollectionChange(p_Var2);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x26,
                      &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids,uVar3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x29,
                     &WPP_427d7ae842d9310bd9b6a1c01d2165ac_Traceguids);
  }
  return;
}



===== TraceLoggingUpmConnectorPublishWnfUsbErrorNotification @ 1400186e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUpmConnectorPublishWnfUsbErrorNotification(long,unsigned __int64,enum
   _USB_ERROR_NOTIFICATION) */

void __cdecl
TraceLoggingUpmConnectorPublishWnfUsbErrorNotification
          (long param_1,__uint64 param_2,_USB_ERROR_NOTIFICATION param_3)

{
  undefined1 auStackY_a8 [32];
  _USB_ERROR_NOTIFICATION local_78;
  long local_74;
  __uint64 local_70;
  undefined8 local_68 [4];
  long *local_48;
  undefined8 local_40;
  __uint64 *local_38;
  undefined8 local_30;
  _USB_ERROR_NOTIFICATION *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((5 < DAT_14002a278) && ((_DAT_14002a288 & 0x400000000000) != 0)) &&
     ((DAT_14002a290 & 0x400000000000) == DAT_14002a290)) {
    local_28 = &local_78;
    local_38 = &local_70;
    local_48 = &local_74;
    local_20 = 4;
    local_30 = 8;
    local_40 = 4;
    local_78 = param_3;
    local_74 = param_1;
    local_70 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a278,&DAT_140027c48,0,0,5,local_68);
  }
  return;
}



===== TraceLoggingUpmConnectorPublishWnfUsbPeerDeviceState @ 1400187b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUpmConnectorPublishWnfUsbPeerDeviceState(long,unsigned __int64,unsigned
   char,unsigned long) */

void __cdecl
TraceLoggingUpmConnectorPublishWnfUsbPeerDeviceState
          (long param_1,__uint64 param_2,uchar param_3,ulong param_4)

{
  undefined1 auStackY_c8 [32];
  uchar local_98 [4];
  ulong local_94;
  long local_90 [2];
  __uint64 local_88 [2];
  undefined8 local_78 [4];
  long *local_58;
  undefined8 local_50;
  __uint64 *local_48;
  undefined8 local_40;
  uchar *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if (((5 < DAT_14002a278) && ((_DAT_14002a288 & 0x400000000000) != 0)) &&
     ((DAT_14002a290 & 0x400000000000) == DAT_14002a290)) {
    local_28 = &local_94;
    local_38 = local_98;
    local_48 = local_88;
    local_58 = local_90;
    local_20 = 4;
    local_30 = 1;
    local_40 = 8;
    local_50 = 4;
    local_98[0] = param_3;
    local_94 = param_4;
    local_90[0] = param_1;
    local_88[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a278,&DAT_140027cae,0,0,6,local_78);
  }
  return;
}



===== TraceLoggingUpmConnectorRunPolicy @ 14001889c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUpmConnectorRunPolicy(long,unsigned __int64,unsigned long,unsigned
   long,unsigned long,unsigned char,unsigned long,unsigned long) */

void __cdecl
TraceLoggingUpmConnectorRunPolicy
          (long param_1,__uint64 param_2,ulong param_3,ulong param_4,ulong param_5,uchar param_6,
          ulong param_7,ulong param_8)

{
  undefined1 auStackY_118 [32];
  uchar local_e8 [4];
  ulong local_e4;
  ulong local_e0;
  ulong local_dc;
  ulong local_d8;
  ulong local_d4 [3];
  __uint64 local_c8 [2];
  undefined8 local_b8 [4];
  ulong *local_98;
  undefined8 local_90;
  __uint64 *local_88;
  undefined8 local_80;
  ulong *local_78;
  undefined8 local_70;
  ulong *local_68;
  undefined8 local_60;
  ulong *local_58;
  undefined8 local_50;
  uchar *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  ulong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  if (((5 < DAT_14002a278) && ((_DAT_14002a288 & 0x400000000000) != 0)) &&
     ((DAT_14002a290 & 0x400000000000) == DAT_14002a290)) {
    local_e4 = param_8;
    local_e0 = param_7;
    local_e8[0] = param_6;
    local_dc = param_5;
    local_28 = &local_e4;
    local_38 = &local_e0;
    local_48 = local_e8;
    local_58 = &local_dc;
    local_68 = &local_d8;
    local_78 = local_d4;
    local_88 = local_c8;
    local_98 = local_d4 + 1;
    local_d4[1] = 0;
    local_20 = 4;
    local_30 = 4;
    local_40 = 1;
    local_50 = 4;
    local_60 = 4;
    local_70 = 4;
    local_80 = 8;
    local_90 = 4;
    local_d8 = param_4;
    local_d4[0] = param_3;
    local_c8[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a278,&DAT_140027b85,0,0,10,local_b8);
  }
  return;
}



===== TraceLoggingUpmConnectorWnfUsbTypeCPartnerState @ 1400189f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl TraceLoggingUpmConnectorWnfUsbTypeCPartnerState(long,unsigned __int64,unsigned
   char,unsigned long,unsigned char) */

void __cdecl
TraceLoggingUpmConnectorWnfUsbTypeCPartnerState
          (long param_1,__uint64 param_2,uchar param_3,ulong param_4,uchar param_5)

{
  undefined1 auStackY_d8 [32];
  uchar local_a8;
  uchar local_a7 [3];
  ulong local_a4 [3];
  __uint64 local_98 [2];
  undefined8 local_88 [4];
  ulong *local_68;
  undefined8 local_60;
  __uint64 *local_58;
  undefined8 local_50;
  uchar *local_48;
  undefined8 local_40;
  ulong *local_38;
  undefined8 local_30;
  uchar *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (((5 < DAT_14002a278) && ((_DAT_14002a288 & 0x400000000000) != 0)) &&
     ((DAT_14002a290 & 0x400000000000) == DAT_14002a290)) {
    local_a8 = param_5;
    local_28 = &local_a8;
    local_38 = local_a4;
    local_48 = local_a7;
    local_58 = local_98;
    local_68 = local_a4 + 1;
    local_a4[1] = 0;
    local_20 = 1;
    local_30 = 4;
    local_40 = 1;
    local_50 = 8;
    local_60 = 4;
    local_a7[0] = param_3;
    local_a4[0] = param_4;
    local_98[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x14002a278,&DAT_140027d1b,0,0,7,local_88);
  }
  return;
}



===== UcmConnectorRunPolicy @ 140018af8 =====

/* unsigned char __cdecl UcmConnectorRunPolicy(struct _UPM_CONNECTOR_CONTEXT * __ptr64,enum
   _UCM_DATA_ROLE * __ptr64,enum _UCM_POWER_ROLE * __ptr64,enum _USB_PEER_DEVICE_CONNECTION_STATE *
   __ptr64) */

uchar __cdecl
UcmConnectorRunPolicy
          (_UPM_CONNECTOR_CONTEXT *param_1,_UCM_DATA_ROLE *param_2,_UCM_POWER_ROLE *param_3,
          _USB_PEER_DEVICE_CONNECTION_STATE *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  _UPM_CONNECTOR_CONTEXT *p_Var5;
  undefined8 uVar6;
  undefined8 uVar7;
  _USB_PEER_DEVICE_CONNECTION_STATE _Var8;
  uchar uVar9;
  _UCM_DATA_ROLE _Var10;
  _UCM_POWER_ROLE _Var11;
  bool bVar12;
  
  _Var10 = UcmDataRoleInvalid;
  uVar9 = '\0';
  p_Var5 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var5 = (_UPM_CONNECTOR_CONTEXT *)WPP_GLOBAL_Control,
     *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    p_Var5 = *(_UPM_CONNECTOR_CONTEXT **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var5,5,1,0x22,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  lVar3 = *(longlong *)param_1;
  uVar7 = *(undefined8 *)(param_1 + 0x10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    p_Var5 = *(_UPM_CONNECTOR_CONTEXT **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_DisDL(p_Var5);
  }
  uVar4 = (uint)p_Var5;
  uVar1 = *(uint *)(lVar3 + 0x2c);
  _Var11 = UcmPowerRoleSource;
  uVar2 = *(uint *)(param_1 + 0x19e9);
  if (((uVar1 & 1) == 0) || ((uVar2 & 2) == 0)) {
    bVar12 = (uVar1 & 2) != 0;
    uVar4 = (uint)CONCAT71((int7)((ulonglong)p_Var5 >> 8),bVar12);
    if (!((uVar2 & 1) != 0 && bVar12)) {
      uVar4 = uVar2 >> 1;
      if (((uVar1 & uVar2 & 1) == 0) || ((uVar4 & 1) != 0)) {
        if ((((uVar1 & 2) == 0) || ((uVar4 & 1) == 0)) || ((uVar2 & 1) != 0)) {
          if (((uVar1 & 1) == 0) || (uVar2 != 0)) {
            if ((((uVar1 & 2) != 0) && (uVar2 == 0)) &&
               ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
              uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
              WPP_RECORDER_SF_(uVar7,4,1,0x26,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
              uVar4 = (uint)uVar7;
            }
            goto LAB_140018cc8;
          }
          _Var8 = 4;
          goto LAB_140018d80;
        }
        _Var8 = 2;
      }
      else {
        _Var8 = 1;
      }
      p_Var5 = param_1;
      UpmConnectorPublishWnfEventForAttach(param_1,_Var8);
      uVar4 = (uint)p_Var5;
      goto LAB_140018cc8;
    }
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_(uVar7,4,1,0x25,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
        uVar4 = (uint)uVar7;
      }
      goto LAB_140018cc8;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_(uVar6,4,1,0x24,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
      uVar4 = (uint)uVar6;
    }
    _Var10 = UcmDataRoleUfp;
    _Var8 = 3;
    _Var11 = UcmPowerRoleSink;
  }
  else {
    _Var8 = 3;
LAB_140018d80:
    _Var10 = UcmDataRoleDfp;
  }
  if (*(_UCM_DATA_ROLE *)(param_1 + 0xd34) == _Var10) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_Li(uVar6,3,1,0x27,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                         (char)_Var10,(char)uVar7);
      uVar4 = (uint)uVar6;
    }
  }
  else {
    uVar9 = '\x01';
    *param_2 = _Var10;
    *param_3 = _Var11;
    *param_4 = _Var8;
  }
LAB_140018cc8:
  TraceLoggingUpmConnectorRunPolicy
            (uVar4,*(__uint64 *)(param_1 + 0x10),*(ulong *)(lVar3 + 0x2c),
             *(ulong *)(param_1 + 0xd34),_Var10,uVar9,*(ulong *)(param_1 + 0x19e9),
             *(ulong *)(param_1 + 0xd20));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x28,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return uVar9;
}



===== UpmConnectorContextCleanup @ 140018e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorContextCleanup(void * __ptr64) */

void __cdecl UpmConnectorContextCleanup(void *param_1)

{
  _UPM_CONNECTOR_CONTEXT *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xf,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  p_Var1 = (_UPM_CONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
  if (*(longlong *)(p_Var1 + 0x19e0) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(longlong *)(p_Var1 + 0x19e0),0);
    p_Var1[0x19d4] = (_UPM_CONNECTOR_CONTEXT)0x1;
    UpmConnectorIndicateStateChange(p_Var1);
    KeWaitForSingleObject(p_Var1 + 0x1a00,0,0,0,0);
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var1 + 0x19e0));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x10,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmConnectorGetProperties @ 140018f74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorGetProperties(struct _UPM_CONNECTOR_CONTEXT * __ptr64,struct
   _UPM_CONNECTOR_PROPERTIES * __ptr64) */

void __cdecl
UpmConnectorGetProperties(_UPM_CONNECTOR_CONTEXT *param_1,_UPM_CONNECTOR_PROPERTIES *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x59,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  memset(param_2,0,0x332);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0),0);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x660))(WdfDriverGlobals,param_1);
  *(undefined8 *)(param_2 + 8) = uVar1;
  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 0x19cc);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0x28) = param_1[0x28];
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0x29) = param_1[0x29];
  *(undefined4 *)(param_2 + 0x2a) = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = 0x80;
  if (*(uint *)(param_1 + 0x38) < 0x80) {
    uVar2 = (ulonglong)*(uint *)(param_1 + 0x38);
  }
  *(int *)(param_2 + 0x2e) = (int)uVar2;
  memmove(param_2 + 0x32,*(void **)(param_1 + 0x30),uVar2 * 6);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x5a,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmConnectorGetState @ 1400190e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorGetState(struct _UPM_CONNECTOR_CONTEXT * __ptr64,struct
   _UPM_CONNECTOR_STATE * __ptr64) */

void __cdecl UpmConnectorGetState(_UPM_CONNECTOR_CONTEXT *param_1,_UPM_CONNECTOR_STATE *param_2)

{
  _UPM_CONNECTOR_CONTEXT *p_Var1;
  undefined8 uVar2;
  _UPM_CONNECTOR_STATE *p_Var3;
  _UPM_CONNECTOR_CONTEXT *p_Var4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x5b,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  memset(param_2,0,0x690);
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0),0);
  p_Var4 = param_1 + 0xda4;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xd14);
  lVar7 = 6;
  lVar5 = 6;
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0xc) = param_1[0xd18];
  *(undefined4 *)(param_2 + 0xd) = *(undefined4 *)(param_1 + 0xd1c);
  *(undefined4 *)(param_2 + 0x11) = *(undefined4 *)(param_1 + 0xd20);
  *(undefined4 *)(param_2 + 0x15) = *(undefined4 *)(param_1 + 0xd28);
  *(undefined4 *)(param_2 + 0x19) = *(undefined4 *)(param_1 + 0xd2c);
  *(undefined4 *)(param_2 + 0x1d) = *(undefined4 *)(param_1 + 0xd3c);
  *(undefined4 *)(param_2 + 0x21) = *(undefined4 *)(param_1 + 0xd30);
  *(undefined4 *)(param_2 + 0x25) = *(undefined4 *)(param_1 + 0xd34);
  *(undefined4 *)(param_2 + 0x29) = *(undefined4 *)(param_1 + 0xd38);
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0x67) = param_1[0xd80];
  *(undefined4 *)(param_2 + 0x84) = *(undefined4 *)(param_1 + 0xda0);
  uVar2 = *(undefined8 *)(param_1 + 0xd8c);
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_1 + 0xd84);
  *(undefined8 *)(param_2 + 0x70) = uVar2;
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_1 + 0xd94);
  *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0xd9c);
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0x2d) = param_1[0xd40];
  uVar2 = *(undefined8 *)(param_1 + 0xd4c);
  *(undefined8 *)(param_2 + 0x2e) = *(undefined8 *)(param_1 + 0xd44);
  *(undefined8 *)(param_2 + 0x36) = uVar2;
  *(undefined8 *)(param_2 + 0x3e) = *(undefined8 *)(param_1 + 0xd54);
  *(undefined4 *)(param_2 + 0x46) = *(undefined4 *)(param_1 + 0xd5c);
  *(_UPM_CONNECTOR_CONTEXT *)(param_2 + 0x4a) = param_1[0xd60];
  uVar2 = *(undefined8 *)(param_1 + 0xd6c);
  *(undefined8 *)(param_2 + 0x4b) = *(undefined8 *)(param_1 + 0xd64);
  *(undefined8 *)(param_2 + 0x53) = uVar2;
  *(undefined8 *)(param_2 + 0x5b) = *(undefined8 *)(param_1 + 0xd74);
  *(undefined4 *)(param_2 + 99) = *(undefined4 *)(param_1 + 0xd7c);
  *(undefined4 *)(param_2 + 0x388) = *(undefined4 *)(param_1 + 0x11a4);
  p_Var3 = param_2 + 0x88;
  do {
    uVar2 = *(undefined8 *)(p_Var4 + 8);
    *(undefined8 *)p_Var3 = *(undefined8 *)p_Var4;
    *(undefined8 *)(p_Var3 + 8) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x18);
    *(undefined8 *)(p_Var3 + 0x10) = *(undefined8 *)(p_Var4 + 0x10);
    *(undefined8 *)(p_Var3 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x28);
    *(undefined8 *)(p_Var3 + 0x20) = *(undefined8 *)(p_Var4 + 0x20);
    *(undefined8 *)(p_Var3 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x38);
    *(undefined8 *)(p_Var3 + 0x30) = *(undefined8 *)(p_Var4 + 0x30);
    *(undefined8 *)(p_Var3 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x48);
    *(undefined8 *)(p_Var3 + 0x40) = *(undefined8 *)(p_Var4 + 0x40);
    *(undefined8 *)(p_Var3 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x58);
    *(undefined8 *)(p_Var3 + 0x50) = *(undefined8 *)(p_Var4 + 0x50);
    *(undefined8 *)(p_Var3 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x68);
    *(undefined8 *)(p_Var3 + 0x60) = *(undefined8 *)(p_Var4 + 0x60);
    *(undefined8 *)(p_Var3 + 0x68) = uVar2;
    p_Var1 = p_Var4 + 0x70;
    uVar2 = *(undefined8 *)(p_Var4 + 0x78);
    p_Var4 = p_Var4 + 0x80;
    *(undefined8 *)(p_Var3 + 0x70) = *(undefined8 *)p_Var1;
    *(undefined8 *)(p_Var3 + 0x78) = uVar2;
    lVar5 = lVar5 + -1;
    p_Var3 = p_Var3 + 0x80;
  } while (lVar5 != 0);
  p_Var4 = param_1 + 0x11a8;
  *(undefined4 *)(param_2 + 0x68c) = *(undefined4 *)(param_1 + 0x15a8);
  p_Var3 = param_2 + 0x38c;
  do {
    uVar2 = *(undefined8 *)(p_Var4 + 8);
    *(undefined8 *)p_Var3 = *(undefined8 *)p_Var4;
    *(undefined8 *)(p_Var3 + 8) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x18);
    *(undefined8 *)(p_Var3 + 0x10) = *(undefined8 *)(p_Var4 + 0x10);
    *(undefined8 *)(p_Var3 + 0x18) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x28);
    *(undefined8 *)(p_Var3 + 0x20) = *(undefined8 *)(p_Var4 + 0x20);
    *(undefined8 *)(p_Var3 + 0x28) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x38);
    *(undefined8 *)(p_Var3 + 0x30) = *(undefined8 *)(p_Var4 + 0x30);
    *(undefined8 *)(p_Var3 + 0x38) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x48);
    *(undefined8 *)(p_Var3 + 0x40) = *(undefined8 *)(p_Var4 + 0x40);
    *(undefined8 *)(p_Var3 + 0x48) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x58);
    *(undefined8 *)(p_Var3 + 0x50) = *(undefined8 *)(p_Var4 + 0x50);
    *(undefined8 *)(p_Var3 + 0x58) = uVar2;
    uVar2 = *(undefined8 *)(p_Var4 + 0x68);
    *(undefined8 *)(p_Var3 + 0x60) = *(undefined8 *)(p_Var4 + 0x60);
    *(undefined8 *)(p_Var3 + 0x68) = uVar2;
    p_Var1 = p_Var4 + 0x70;
    uVar2 = *(undefined8 *)(p_Var4 + 0x78);
    p_Var4 = p_Var4 + 0x80;
    *(undefined8 *)(p_Var3 + 0x70) = *(undefined8 *)p_Var1;
    *(undefined8 *)(p_Var3 + 0x78) = uVar2;
    lVar7 = lVar7 + -1;
    p_Var3 = p_Var3 + 0x80;
  } while (lVar7 != 0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dDL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5e,
                           &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                           (char)*(undefined4 *)(param_2 + 0x29),
                           (char)*(undefined4 *)(param_2 + 0x25));
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x5f,
                             &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                             (char)*(undefined4 *)(param_2 + 0x15),
                             (char)*(undefined4 *)(param_2 + 0x19));
        }
      }
    }
  }
  uVar6 = 0;
  if (param_2[0x2d] != (_UPM_CONNECTOR_STATE)0x0) {
    do {
      UpmDumpPdo((_USBC_PD_POWER_DATA_OBJECT *)(param_2 + (ulonglong)uVar6 * 4 + 0x2e),false,true);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (byte)param_2[0x2d]);
  }
  uVar6 = 0;
  if (param_2[0x4a] != (_UPM_CONNECTOR_STATE)0x0) {
    do {
      UpmDumpPdo((_USBC_PD_POWER_DATA_OBJECT *)(param_2 + (ulonglong)uVar6 * 4 + 0x4b),false,false);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (byte)param_2[0x4a]);
  }
  uVar6 = 0;
  if (param_2[0x67] != (_UPM_CONNECTOR_STATE)0x0) {
    do {
      UpmDumpPdo((_USBC_PD_POWER_DATA_OBJECT *)(param_2 + ((ulonglong)uVar6 + 0x1a) * 4),true,true);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (byte)param_2[0x67]);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x61,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmConnectorIndicateStateChange @ 14001957c =====

/* void __cdecl UpmConnectorIndicateStateChange(struct _UPM_CONNECTOR_CONTEXT * __ptr64) */

void __cdecl UpmConnectorIndicateStateChange(_UPM_CONNECTOR_CONTEXT *param_1)

{
  undefined1 uVar1;
  undefined8 in_stack_ffffffffffffffe0;
  uint uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  uint uVar3;
  
  uVar2 = (uint)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  uVar3 = (uint)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x56,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  *(uint *)(param_1 + 0x19d8) =
       (*(int *)(param_1 + 0x19d8) + 2) - (uint)(*(int *)(param_1 + 0x19d8) != -1);
  uVar1 = ZwUpdateWnfStateData
                    (param_1 + 0x19cc,0,0,0,0,(ulonglong)uVar2 << 0x20,(ulonglong)uVar3 << 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x57,
                        &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                        (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10),uVar1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x58,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
    }
  }
  return;
}



===== UpmConnectorInvokeSetDataRole @ 1400196a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmConnectorInvokeSetDataRole(struct _UPM_CONNECTOR_CONTEXT * __ptr64,enum
   _UCM_DATA_ROLE) */

long __cdecl UpmConnectorInvokeSetDataRole(_UPM_CONNECTOR_CONTEXT *param_1,_UCM_DATA_ROLE param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x3c,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  uVar3 = (undefined1)param_2;
  if (*(code **)(param_1 + 0x40) == (code *)0x0) {
    iVar1 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x3d,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x10),uVar3);
  }
  else if (*(char *)(*(undefined8 **)param_1 + 1) == '\0') {
    uVar2 = (ulonglong)param_2;
    iVar1 = (**(code **)(param_1 + 0x40))(**(undefined8 **)param_1,*(undefined8 *)(param_1 + 0x10));
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_Lid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar2,0x3f,
                          &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,uVar3,
                          (char)*(undefined8 *)(param_1 + 0x10),(char)iVar1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x40,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,uVar3,
                         (char)*(undefined8 *)(param_1 + 0x10));
    }
  }
  else {
    iVar1 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3e,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x41,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return iVar1;
}



===== UpmConnectorInvokeSetPowerLevel @ 140019870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmConnectorInvokeSetPowerLevel(struct _UPM_CONNECTOR_CONTEXT * __ptr64,struct
   _UPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS * __ptr64) */

long __cdecl
UpmConnectorInvokeSetPowerLevel
          (_UPM_CONNECTOR_CONTEXT *param_1,_UPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *param_2)

{
  _UPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS _Var1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined1 auStackY_a8 [32];
  undefined1 uVar10;
  undefined1 uVar11;
  int iVar12;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x62,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  puVar2 = *(undefined8 **)param_1;
  if (*(longlong *)(param_1 + 0x50) == 0) {
    iVar3 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    uVar9 = 99;
    bVar5 = 3;
LAB_14001990c:
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,1,uVar9,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,
                       (char)*(undefined8 *)(param_1 + 0x10));
    goto LAB_140019c56;
  }
  if (*(int *)(param_2 + 0xc) == 1) {
    iVar12 = *(int *)(param_1 + 0x19c0);
    if (iVar12 != 0) {
      _Var1 = param_2[0x10];
      uVar6 = (uint)(byte)_Var1;
      if ((0xfd < (byte)((char)_Var1 - 1U)) || ((uint)(byte)_Var1 <= (uint)(iVar12 * 500)))
      goto LAB_1400199bd;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar9 = 100;
LAB_140019982:
      iVar3 = -0x3ffffff3;
      WPP_RECORDER_SF_qiLLL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar9,
                 &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,
                 (char)*(undefined8 *)(param_1 + 0x10),(char)uVar6,
                 (char)*(undefined4 *)(param_2 + 8),(char)iVar12);
      goto LAB_140019c56;
    }
LAB_1400199bd:
    uVar6 = *(uint *)(param_2 + 0x11);
    if ((uVar6 != 0) && (iVar12 = *(int *)(param_1 + 0x19c8), iVar12 != 0)) {
      if (uVar6 == 1) {
        iVar3 = 4;
      }
      else if (uVar6 == 2) {
        iVar3 = 2;
      }
      else {
        if (uVar6 != 3) {
          iVar3 = -0x3ffffff3;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3ffffff3;
          }
          WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x65,
                              &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,
                              (char)*(undefined8 *)(param_1 + 0x10),(char)uVar6);
          goto LAB_140019c56;
        }
        iVar3 = 1;
      }
      if (iVar12 < iVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar9 = 0x66;
        goto LAB_140019982;
      }
    }
  }
  else if ((*(int *)(param_2 + 0xc) == 2) && (param_1[0xd60] != (_UPM_CONNECTOR_CONTEXT)0x0)) {
    uVar6 = *(uint *)(param_2 + 0x10);
    uVar4 = uVar6 >> 0x1c & 7;
    if ((byte)param_1[0xd80] < uVar4) {
      iVar3 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      WPP_RECORDER_SF_qiLD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x67,
                 &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,
                 (char)*(undefined8 *)(param_1 + 0x10),(char)uVar4,param_1[0xd60]);
      goto LAB_140019c56;
    }
    uVar7 = 0;
    uVar4 = *(uint *)(param_1 + (ulonglong)(uVar4 - 1) * 4 + 0xd84);
    uVar8 = uVar4 >> 0x1e;
    if (uVar8 == 0) {
      uVar4 = uVar4 >> 10;
LAB_140019b6a:
      uVar7 = (uVar4 & 0x3ff) * (uVar6 & 0x3ff) * 500;
    }
    else if (uVar8 == 1) {
      uVar7 = (uVar6 & 0x3ff) * 0xfa;
    }
    else {
      if (uVar8 == 2) {
        uVar4 = uVar4 >> 0x14;
        goto LAB_140019b6a;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x68,
                            &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,
                            (char)*(undefined8 *)(param_1 + 0x10),(byte)(uVar4 >> 0x1e));
      }
    }
    if (*(uint *)(param_1 + 0x19c4) < uVar7) {
      iVar3 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar9 = 0x69;
      bVar5 = 2;
      goto LAB_14001990c;
    }
  }
  uStack_50._5_3_ = (undefined3)((ulonglong)*(undefined8 *)(param_2 + 0xc) >> 0x28);
  uStack_50._0_5_ =
       CONCAT14((char)*(undefined4 *)(param_2 + 0x10),(int)*(undefined8 *)(param_2 + 0xc));
  local_48 = *(undefined4 *)(param_2 + 0x11);
  local_58 = CONCAT44(*(undefined4 *)(param_2 + 8),0x14);
  iVar3 = (**(code **)(param_1 + 0x50))(*puVar2,*(undefined8 *)(param_1 + 0x10),&local_58);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    uVar11 = (undefined1)*(undefined4 *)(param_2 + 8);
    uVar9 = 0x6a;
    bVar5 = 2;
    uVar10 = (undefined1)*(undefined8 *)(param_1 + 0x10);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    uVar9 = 0x6b;
    uVar11 = (undefined1)*(undefined4 *)(param_2 + 8);
    bVar5 = 4;
    uVar10 = (undefined1)*(undefined8 *)(param_1 + 0x10);
  }
  WPP_RECORDER_SF_qiLD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,1,uVar9,
             &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*puVar2,uVar10,uVar11,
             (char)iVar3);
LAB_140019c56:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x6c,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return iVar3;
}



===== UpmConnectorInvokeSetPowerRole @ 140019cb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmConnectorInvokeSetPowerRole(struct _UPM_CONNECTOR_CONTEXT * __ptr64,enum
   _UCM_POWER_ROLE) */

long __cdecl UpmConnectorInvokeSetPowerRole(_UPM_CONNECTOR_CONTEXT *param_1,_UCM_POWER_ROLE param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x42,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  uVar3 = (undefined1)param_2;
  if (*(code **)(param_1 + 0x48) == (code *)0x0) {
    iVar1 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x43,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x10),uVar3);
  }
  else if (*(char *)(*(undefined8 **)param_1 + 1) == '\0') {
    uVar2 = (ulonglong)param_2;
    iVar1 = (**(code **)(param_1 + 0x48))(**(undefined8 **)param_1,*(undefined8 *)(param_1 + 0x10));
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_Lid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar2,0x45,
                          &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,uVar3,
                          (char)*(undefined8 *)(param_1 + 0x10),(char)iVar1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x46,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,uVar3,
                         (char)*(undefined8 *)(param_1 + 0x10));
    }
  }
  else {
    iVar1 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x44,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x47,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return iVar1;
}



===== UpmConnectorPartnerPdAlternateModesChangedInternal @ 140019e84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmConnectorPartnerPdAlternateModesChangedInternal(struct _UPM_CONNECTOR_CONTEXT *
   __ptr64,struct _UCM_PD_ALTERNATE_MODE * __ptr64,unsigned long) */

long __cdecl
UpmConnectorPartnerPdAlternateModesChangedInternal
          (_UPM_CONNECTOR_CONTEXT *param_1,_UCM_PD_ALTERNATE_MODE *param_2,ulong param_3)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  _USB_ERROR_NOTIFICATION _Var6;
  uint uVar7;
  undefined *puVar8;
  undefined2 uVar9;
  undefined *in_stack_ffffffffffffffc8;
  
  uVar3 = (ulonglong)param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x32,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  lVar1 = *(longlong *)param_1;
  *(undefined2 *)(param_1 + 0x1a2e) = 0;
  if (param_3 != 0) {
    do {
      if (param_2->SVID == 0xff01) {
        param_1[0x1a2e] = (_UPM_CONNECTOR_CONTEXT)0x1;
      }
      if (param_2->SVID == 0x8087) {
        param_1[0x1a2f] = (_UPM_CONNECTOR_CONTEXT)0x1;
      }
      param_2 = param_2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (*(int *)(param_1 + 0x1a28) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x33,
                      &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x10));
    goto LAB_14001a15b;
  }
  if (param_1[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) goto LAB_14001a15b;
  if ((param_1[0x1a2e] == (_UPM_CONNECTOR_CONTEXT)0x0) ||
     (param_1[0x1a30] == (_UPM_CONNECTOR_CONTEXT)0x0)) {
    if (((byte)param_1[0x1a2f] & (byte)param_1[0x1a31]) == 0) {
      if ((param_1[0x1a2e] != (_UPM_CONNECTOR_CONTEXT)0x0) &&
         (param_1[0x1a2c] == (_UPM_CONNECTOR_CONTEXT)0x0)) {
        for (uVar7 = 0;
            uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                              (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20)), uVar7 < uVar2;
            uVar7 = uVar7 + 1) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x90))
                            (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20),uVar7);
          puVar8 = PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
          if (*(char *)(lVar5 + 0x1a2c) != '\0') {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14001a14e;
            uVar9 = 0x36;
            goto LAB_14001a12c;
          }
        }
      }
      if ((param_1[0x1a2f] != (_UPM_CONNECTOR_CONTEXT)0x0) &&
         (param_1[0x1a2d] == (_UPM_CONNECTOR_CONTEXT)0x0)) {
        uVar7 = 0;
LAB_14001a0a8:
        uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                          (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
        if (uVar7 < uVar2) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x90))
                            (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20),uVar7);
          puVar8 = PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240;
          lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
          if (*(char *)(lVar5 + 0x1a2d) == '\0') goto code_r0x00014001a119;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x37;
LAB_14001a12c:
            WPP_RECORDER_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar8,uVar9,
                               in_stack_ffffffffffffffc8,(char)*(undefined8 *)(param_1 + 0x10),
                               (char)*(undefined8 *)(lVar5 + 0x10));
          }
LAB_14001a14e:
          _Var6 = 3;
          goto LAB_14001a153;
        }
      }
      goto LAB_14001a15b;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x35;
      goto LAB_140019fba;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = 0x34;
LAB_140019fba:
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar9,
                      &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x10));
  }
  _Var6 = 4;
LAB_14001a153:
  UpmConnectorPublishWnfUsbErrorNotification(param_1,_Var6);
LAB_14001a15b:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x38,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return 0;
code_r0x00014001a119:
  uVar7 = uVar7 + 1;
  goto LAB_14001a0a8;
}



===== UpmConnectorPdConnStateChangedInternal @ 14001a1b4 =====

/* long __cdecl UpmConnectorPdConnStateChangedInternal(struct _UPM_CONNECTOR_CONTEXT * __ptr64,enum
   _UCM_PD_CONN_STATE) */

long __cdecl
UpmConnectorPdConnStateChangedInternal(_UPM_CONNECTOR_CONTEXT *param_1,_UCM_PD_CONN_STATE param_2)

{
  uint uVar1;
  int iVar2;
  _USB_ERROR_NOTIFICATION _Var3;
  
  uVar1 = *(uint *)(param_1 + 0xd30);
  iVar2 = *(int *)(param_1 + 0xd38);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2c,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2d,
                          &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                          (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10),
                          (char)param_2);
    }
  }
  if (*(int *)(param_1 + 0x1a28) == 6) {
    if ((uVar1 >> 0x1a & 1) != 0) goto LAB_14001a355;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2e,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                         (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10));
    }
    _Var3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1a28) != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2f,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                         (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10));
      goto LAB_14001a355;
    }
    if ((iVar2 != 2) || ((uVar1 >> 0x1a & 1) == 0)) goto LAB_14001a355;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                         (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10));
    }
    _Var3 = 6;
  }
  UpmConnectorPublishWnfUsbErrorNotification(param_1,_Var3);
LAB_14001a355:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x31,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return 0;
}



===== UpmConnectorPublishWnfEventForAttach @ 14001a3ac =====

/* long __cdecl UpmConnectorPublishWnfEventForAttach(struct _UPM_CONNECTOR_CONTEXT * __ptr64,enum
   _USB_PEER_DEVICE_CONNECTION_STATE) */

long __cdecl
UpmConnectorPublishWnfEventForAttach
          (_UPM_CONNECTOR_CONTEXT *param_1,_USB_PEER_DEVICE_CONNECTION_STATE param_2)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1e,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  *(_USB_PEER_DEVICE_CONNECTION_STATE *)(param_1 + 0x19f0) = param_2;
  lVar1 = UpmConnectorPublishWnfUsbPeerDeviceState(param_1,'\x01',param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1f,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return lVar1;
}



===== UpmConnectorPublishWnfUsbErrorNotification @ 14001a46c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl UpmConnectorPublishWnfUsbErrorNotification(struct _UPM_CONNECTOR_CONTEXT *
   __ptr64,enum _USB_ERROR_NOTIFICATION) */

long __cdecl
UpmConnectorPublishWnfUsbErrorNotification
          (_UPM_CONNECTOR_CONTEXT *param_1,_USB_ERROR_NOTIFICATION param_2)

{
  long lVar1;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  _USB_ERROR_NOTIFICATION local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  local_48 = *(undefined8 *)(param_1 + 0x10);
  *(_USB_ERROR_NOTIFICATION *)(param_1 + 0x1a28) = param_2;
  local_40 = param_2;
  lVar1 = ZwUpdateWnfStateData(&WNF_USB_ERROR_NOTIFICATION,&local_48,0xc);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qiLD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)**(undefined8 **)param_1,
               (char)*(undefined8 *)(param_1 + 0x10),(char)param_2,(char)lVar1);
  }
  TraceLoggingUpmConnectorPublishWnfUsbErrorNotification
            (lVar1,*(__uint64 *)(param_1 + 0x10),param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1d,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return lVar1;
}



===== UpmConnectorPublishWnfUsbPeerDeviceState @ 14001a5c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl UpmConnectorPublishWnfUsbPeerDeviceState(struct _UPM_CONNECTOR_CONTEXT *
   __ptr64,unsigned char,enum _USB_PEER_DEVICE_CONNECTION_STATE) */

long __cdecl
UpmConnectorPublishWnfUsbPeerDeviceState
          (_UPM_CONNECTOR_CONTEXT *param_1,uchar param_2,_USB_PEER_DEVICE_CONNECTION_STATE param_3)

{
  long lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  uchar local_50;
  _USB_PEER_DEVICE_CONNECTION_STATE local_4f;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  local_58 = *(undefined8 *)(param_1 + 0x10);
  local_50 = param_2;
  local_4f = param_3;
  lVar1 = ZwUpdateWnfStateData(&WNF_USB_PEER_DEVICE_STATE,&local_58,0xd);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_icdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  TraceLoggingUpmConnectorPublishWnfUsbPeerDeviceState
            (lVar1,*(__uint64 *)(param_1 + 0x10),param_2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x17,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return lVar1;
}



===== UpmConnectorSchedulePolicyWorkItem @ 14001a708 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorSchedulePolicyWorkItem(struct _UPM_CONNECTOR_CONTEXT * __ptr64) */

void __cdecl UpmConnectorSchedulePolicyWorkItem(_UPM_CONNECTOR_CONTEXT *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 in_RDX;
  undefined2 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_RDX = CONCAT71((int7)((ulonglong)in_RDX >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x4d,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  iVar2 = *(int *)(param_1 + 0x19f4) + 1;
  *(int *)(param_1 + 0x19f4) = iVar2;
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x19f4) = 1;
    iVar2 = 1;
  }
  uVar1 = (undefined1)iVar2;
  if (param_1[0x19f8] == (_UPM_CONNECTOR_CONTEXT)0x0) {
    KeWaitForSingleObject(param_1 + 0x1a00,0,0,0,0);
    KeResetEvent(param_1 + 0x1a00);
    in_RDX = *(undefined8 *)(param_1 + 0x1a18);
    param_1[0x19f8] = (_UPM_CONNECTOR_CONTEXT)0x1;
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar1 = (undefined1)*(undefined4 *)(param_1 + 0x19f4);
    uVar3 = 0x4f;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0x4e;
  }
  WPP_RECORDER_SF_iD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,1,uVar3,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                     (char)*(undefined8 *)(param_1 + 0x10),uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x50,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmConnectorSupportedAlternateModesChangedInternal @ 14001a87c =====

/* long __cdecl UpmConnectorSupportedAlternateModesChangedInternal(struct _UPM_CONNECTOR_CONTEXT *
   __ptr64,struct _UCM_PD_ALTERNATE_MODE * __ptr64,unsigned long) */

long __cdecl
UpmConnectorSupportedAlternateModesChangedInternal
          (_UPM_CONNECTOR_CONTEXT *param_1,_UCM_PD_ALTERNATE_MODE *param_2,ulong param_3)

{
  bool bVar1;
  bool bVar2;
  _UPM_CONNECTOR_CONTEXT _Var3;
  ulonglong uVar4;
  _UPM_CONNECTOR_CONTEXT _Var5;
  _USB_ERROR_NOTIFICATION _Var6;
  
  uVar4 = (ulonglong)param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x39,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  bVar1 = false;
  bVar2 = false;
  if ((param_1[0x1a2c] == (_UPM_CONNECTOR_CONTEXT)0x0) ||
     (param_1[0x1a2d] == (_UPM_CONNECTOR_CONTEXT)0x0)) goto LAB_14001aa02;
  if (param_3 != 0) {
    bVar1 = false;
    bVar2 = false;
    do {
      if (param_2->SVID == 0xff01) {
        bVar1 = true;
      }
      else if (param_2->SVID == 0x8087) {
        bVar2 = true;
      }
      param_2 = param_2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  _Var3 = param_1[0x1a30];
  if ((_Var3 != (_UPM_CONNECTOR_CONTEXT)0x0) && (bVar1)) {
    param_1[0x1a30] = (_UPM_CONNECTOR_CONTEXT)0x0;
    _Var3 = (_UPM_CONNECTOR_CONTEXT)0x0;
  }
  _Var5 = param_1[0x1a31];
  if ((_Var5 != (_UPM_CONNECTOR_CONTEXT)0x0) && (bVar2)) {
    param_1[0x1a31] = (_UPM_CONNECTOR_CONTEXT)0x0;
    _Var5 = (_UPM_CONNECTOR_CONTEXT)0x0;
  }
  if (((_Var3 == (_UPM_CONNECTOR_CONTEXT)0x0) && (_Var5 == (_UPM_CONNECTOR_CONTEXT)0x0)) &&
     (*(int *)(param_1 + 0x1a28) == 4)) {
    _Var6 = 0;
  }
  else {
    if (!bVar2) {
      param_1[0x1a31] = (_UPM_CONNECTOR_CONTEXT)0x1;
      _Var5 = (_UPM_CONNECTOR_CONTEXT)0x1;
    }
    if (!bVar1) {
      param_1[0x1a30] = (_UPM_CONNECTOR_CONTEXT)0x1;
      _Var3 = (_UPM_CONNECTOR_CONTEXT)0x1;
    }
    if (*(int *)(param_1 + 0x1a28) != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3a,
                        &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x10));
      goto LAB_14001aa02;
    }
    if ((param_1[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) ||
       (((param_1[0x1a2f] == (_UPM_CONNECTOR_CONTEXT)0x0 || (_Var5 == (_UPM_CONNECTOR_CONTEXT)0x0))
        && ((param_1[0x1a2e] == (_UPM_CONNECTOR_CONTEXT)0x0 ||
            (_Var3 == (_UPM_CONNECTOR_CONTEXT)0x0)))))) goto LAB_14001aa02;
    _Var6 = 4;
  }
  UpmConnectorPublishWnfUsbErrorNotification(param_1,_Var6);
LAB_14001aa02:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x3b,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return 0;
}



===== UpmConnectorUcmStateChanged @ 14001aa54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorUcmStateChanged(struct _UPM_CONNECTOR_CONTEXT * __ptr64,struct
   _UCM_CONNECTOR_STATE * __ptr64) */

void __cdecl
UpmConnectorUcmStateChanged(_UPM_CONNECTOR_CONTEXT *param_1,_UCM_CONNECTOR_STATE *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  _UPM_CONNECTOR_CONTEXT *p_Var5;
  ulonglong uVar6;
  bool bVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x6d,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0),0);
  memmove(param_1 + 0x60,param_1 + 0xd10,0xcb0);
  memmove(param_1 + 0xd10,param_2,0xcb0);
  bVar7 = false;
  *(undefined4 *)(param_1 + 0x19c0) = 0;
  if (param_1[0xd40] != (_UPM_CONNECTOR_CONTEXT)0x0) {
    uVar4 = 0;
    p_Var5 = param_1 + 0xd44;
    uVar6 = (ulonglong)(byte)param_1[0xd40];
    do {
      uVar1 = *(uint *)p_Var5;
      uVar3 = 0;
      uVar2 = uVar1 >> 0x1e;
      if (uVar2 == 0) {
        uVar2 = uVar1 >> 10;
LAB_14001ab5f:
        uVar3 = (uVar2 & 0x3ff) * (uVar1 & 0x3ff) * 500;
      }
      else if (uVar2 == 1) {
        uVar3 = (uVar1 & 0x3ff) * 0xfa;
      }
      else if (uVar2 == 2) {
        uVar2 = uVar1 >> 0x14;
        goto LAB_14001ab5f;
      }
      if (uVar4 < uVar3) {
        *(uint *)(param_1 + 0x19c0) = uVar3;
        uVar4 = uVar3;
      }
      p_Var5 = p_Var5 + 4;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(undefined4 *)(param_1 + 0x19c4) = 0;
  if (param_1[0xd60] != (_UPM_CONNECTOR_CONTEXT)0x0) {
    uVar4 = 0;
    p_Var5 = param_1 + 0xd64;
    uVar6 = (ulonglong)(byte)param_1[0xd60];
    do {
      uVar1 = *(uint *)p_Var5;
      uVar3 = 0;
      uVar2 = uVar1 >> 0x1e;
      if (uVar2 == 0) {
        uVar2 = uVar1 >> 10;
LAB_14001abd4:
        uVar3 = (uVar2 & 0x3ff) * (uVar1 & 0x3ff) * 500;
      }
      else if (uVar2 == 1) {
        uVar3 = (uVar1 >> 0x14 & 0x3ff) * 0x32;
      }
      else if (uVar2 == 2) {
        uVar2 = uVar1 >> 0x14;
        goto LAB_14001abd4;
      }
      if (uVar4 < uVar3) {
        *(uint *)(param_1 + 0x19c4) = uVar3;
        uVar4 = uVar3;
      }
      p_Var5 = p_Var5 + 4;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (param_1[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) {
LAB_14001ad7d:
    if ((*(int *)(param_1 + 0xd3c) != 1) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qiL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x6e,
                          &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                          (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10),
                          (char)*(int *)(param_1 + 0xd3c));
    }
    if (*(int *)(param_1 + 0x19f0) != 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x20,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
      }
      UpmConnectorPublishWnfUsbPeerDeviceState
                (param_1,'\0',*(_USB_PEER_DEVICE_CONNECTION_STATE *)(param_1 + 0x19f0));
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x21,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
      }
      *(undefined4 *)(param_1 + 0x19f0) = 0;
    }
    if (*(int *)(param_1 + 0x1a28) != 0) {
      *(undefined4 *)(param_1 + 0x1a28) = 0;
      UpmConnectorPublishWnfUsbErrorNotification(param_1,0);
    }
    bVar7 = *(int *)(param_1 + 0x88) == 1;
  }
  else {
    if ((*(int *)(param_1 + 0xd38) == 2) && (param_1[0x19bc] != (_UPM_CONNECTOR_CONTEXT)0x0)) {
      if (*(int *)(param_1 + 0x1a28) != 0xc) {
        UpmConnectorPublishWnfUsbErrorNotification(param_1,0xc);
      }
      goto LAB_14001aee0;
    }
    if (((param_1[0x68] == (_UPM_CONNECTOR_CONTEXT)0x0) ||
        ((*(int *)(param_1 + 0xd1c) != *(int *)(param_1 + 0x6c) ||
         (*(int *)(param_1 + 0xd2c) != *(int *)(param_1 + 0x7c))))) &&
       (param_1[0x1a20] = (_UPM_CONNECTOR_CONTEXT)0x0,
       param_1[0x19e8] != (_UPM_CONNECTOR_CONTEXT)0x0)) {
      UpmConnectorSchedulePolicyWorkItem(param_1);
    }
    if (param_1[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) goto LAB_14001ad7d;
    if ((((param_1[0x68] == (_UPM_CONNECTOR_CONTEXT)0x0) ||
         (*(int *)(param_1 + 0xd1c) != *(int *)(param_1 + 0x6c))) &&
        (*(int *)(param_1 + 0xd20) == 5)) && (param_1[0x28] == (_UPM_CONNECTOR_CONTEXT)0x0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x29,
                           &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2a,
                             &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                             (char)**(undefined8 **)param_1,(char)*(undefined8 *)(param_1 + 0x10));
        }
      }
      UpmConnectorPublishWnfUsbErrorNotification(param_1,9);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2b,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
      }
      goto LAB_14001aee0;
    }
    if ((*(int *)(param_1 + 0xd38) == 1) && (*(int *)(param_1 + 0x88) != 1)) {
      bVar7 = true;
    }
  }
  if ((*(int *)(param_1 + 0xd3c) != *(int *)(param_1 + 0x8c)) &&
     (param_1[0xd18] != (_UPM_CONNECTOR_CONTEXT)0x0)) {
    bVar7 = true;
  }
  if (*(_UCM_PD_CONN_STATE *)(param_1 + 0xd2c) != *(_UCM_PD_CONN_STATE *)(param_1 + 0x7c)) {
    UpmConnectorPdConnStateChangedInternal(param_1,*(_UCM_PD_CONN_STATE *)(param_1 + 0xd2c));
  }
  if (*(ulong *)(param_1 + 0x15a8) != *(ulong *)(param_1 + 0x8f8)) {
    UpmConnectorPartnerPdAlternateModesChangedInternal
              (param_1,(_UCM_PD_ALTERNATE_MODE *)(param_1 + 0x11a8),*(ulong *)(param_1 + 0x15a8));
  }
  if (*(int *)(param_1 + 0x19b0) != *(int *)(param_1 + 0xd00)) {
    UpmConnectorSupportedAlternateModesChangedInternal
              (param_1,(_UCM_PD_ALTERNATE_MODE *)(param_1 + 0x15ac),*(ulong *)(param_1 + 0x19ac));
  }
LAB_14001aee0:
  if (*(char *)(*(longlong *)param_1 + 9) != '\0') {
    UpmBpEvtConnectorStateChanged(param_1);
  }
  UpmConnectorIndicateStateChange(param_1);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0));
  if (bVar7) {
    UpmExecuteGlobalPolicies(*(_UPM_DEVICE_CONTEXT **)param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x6f,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmConnectorUnpublishWnfUsbErrorNotificationForBrownoutProtection @ 14001af7c =====

/* long __cdecl UpmConnectorUnpublishWnfUsbErrorNotificationForBrownoutProtection(struct
   _UPM_CONNECTOR_CONTEXT * __ptr64) */

long __cdecl
UpmConnectorUnpublishWnfUsbErrorNotificationForBrownoutProtection(_UPM_CONNECTOR_CONTEXT *param_1)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x18,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  if (*(int *)(param_1 + 0x1a28) - 10U < 2) {
    lVar1 = UpmConnectorPublishWnfUsbErrorNotification(param_1,0);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                         (char)*(int *)(param_1 + 0x1a28),(char)*(undefined8 *)(param_1 + 0x10));
    }
    lVar1 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return lVar1;
}



===== UpmConnectorWnfHandler @ 14001b078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmConnectorWnfHandler(struct _UPM_CONNECTOR_CONTEXT * __ptr64,struct
   _WNF_USB_TYPE_C_PARTNER_STATE_DATA * __ptr64,unsigned long) */

long __cdecl
UpmConnectorWnfHandler
          (_UPM_CONNECTOR_CONTEXT *param_1,_WNF_USB_TYPE_C_PARTNER_STATE_DATA *param_2,ulong param_3
          )

{
  _UPM_CONNECTOR_CONTEXT *p_Var1;
  _UPM_CONNECTOR_CONTEXT *p_Var2;
  _UPM_CONNECTOR_CONTEXT _Var3;
  undefined8 uVar4;
  uchar uVar5;
  
  uVar5 = '\0';
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0),0);
  p_Var2 = param_1 + 0x19e8;
  p_Var1 = (_UPM_CONNECTOR_CONTEXT *)(param_2 + 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_idDLdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  _Var3 = *p_Var1;
  if (_Var3 == (_UPM_CONNECTOR_CONTEXT)0x0) {
    if (*p_Var2 != (_UPM_CONNECTOR_CONTEXT)0x0) goto LAB_14001b1a1;
  }
  else if (*p_Var2 == (_UPM_CONNECTOR_CONTEXT)0x0) goto LAB_14001b1a1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_di(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    _Var3 = *p_Var1;
  }
  uVar5 = '\x01';
LAB_14001b1a1:
  *p_Var2 = _Var3;
  *(undefined4 *)(param_1 + 0x19e9) = *(undefined4 *)(param_2 + 9);
  if ((*p_Var1 != (_UPM_CONNECTOR_CONTEXT)0x0) && (param_1[0xd18] != (_UPM_CONNECTOR_CONTEXT)0x0)) {
    UpmConnectorSchedulePolicyWorkItem(param_1);
  }
  uVar4 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x19e0));
  TraceLoggingUpmConnectorWnfUsbTypeCPartnerState
            ((long)uVar4,*(__uint64 *)param_2,(uchar)*p_Var1,*(ulong *)(param_2 + 9),uVar5);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return 0;
}



===== UpmConnectorWorkItemCallback @ 14001b260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorWorkItemCallback(struct WDFWORKITEM__ * __ptr64) */

void __cdecl UpmConnectorWorkItemCallback(WDFWORKITEM__ *param_1)

{
  int iVar1;
  uchar uVar2;
  long lVar3;
  undefined8 *puVar4;
  _UPM_CONNECTOR_CONTEXT *p_Var5;
  _UCM_POWER_ROLE _Var6;
  _UCM_DATA_ROLE _Var7;
  _USB_PEER_DEVICE_CONNECTION_STATE _Var8;
  int iVar9;
  _UCM_DATA_ROLE local_res10 [2];
  _UCM_POWER_ROLE local_res18 [2];
  _USB_PEER_DEVICE_CONNECTION_STATE local_res20 [2];
  
  local_res10[0] = UcmDataRoleInvalid;
  _Var7 = UcmDataRoleInvalid;
  local_res18[0] = UcmPowerRoleInvalid;
  _Var6 = UcmPowerRoleInvalid;
  local_res20[0] = 0;
  _Var8 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x48,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_UPMCONNECTOR_WORKITEM_CONTEXT_TYPE_INFO_14002a218);
  p_Var5 = (_UPM_CONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,*puVar4,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
  iVar9 = 0;
LAB_14001b31d:
  do {
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0),0);
    iVar1 = *(int *)(p_Var5 + 0x19f4);
    if (iVar1 == iVar9) {
      p_Var5[0x19f8] = (_UPM_CONNECTOR_CONTEXT)0x0;
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0));
      KeSetEvent(p_Var5 + 0x1a00,0,0);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x4c,
                         &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
      }
      return;
    }
    if (p_Var5[0x1a20] == (_UPM_CONNECTOR_CONTEXT)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x49,
                            &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                            (char)*(undefined8 *)(p_Var5 + 0x10),(char)iVar1,
                            (char)*(undefined4 *)(p_Var5 + 0x19e9));
      }
      p_Var5[0x1a20] = (_UPM_CONNECTOR_CONTEXT)0x1;
LAB_14001b3e7:
      *(undefined4 *)(p_Var5 + 0x1a21) = *(undefined4 *)(p_Var5 + 0x19e9);
      uVar2 = UcmConnectorRunPolicy(p_Var5,local_res10,local_res18,local_res20);
      _Var7 = local_res10[0];
      _Var6 = local_res18[0];
      _Var8 = local_res20[0];
    }
    else {
      if (*(int *)(p_Var5 + 0x1a21) != *(int *)(p_Var5 + 0x19e9)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_14001b3e7;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      uVar2 = '\0';
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0));
    iVar9 = iVar1;
  } while (uVar2 == '\0');
  lVar3 = UpmConnectorInvokeSetDataRole(p_Var5,_Var7);
  if (-1 < lVar3) {
    lVar3 = UpmConnectorInvokeSetPowerRole(p_Var5,_Var6);
    if (-1 < lVar3) goto LAB_14001b31d;
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0));
  UpmConnectorPublishWnfEventForAttach(p_Var5,_Var8);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0));
  goto LAB_14001b31d;
}



===== UpmDeviceContextCleanup @ 14001b5a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmDeviceContextCleanup(void * __ptr64) */

void __cdecl UpmDeviceContextCleanup(void *param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined *in_stack_ffffffffffffffe8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffe8 = &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268);
  (**(code **)(WdfFunctions_01015 + 0x270))
            (WdfDriverGlobals,*puVar2,&GUID_DEVINTERFACE_THERMAL_COOLING,0,
             (ulonglong)in_stack_ffffffffffffffe8 & 0xffffffffffffff00);
  plVar1 = puVar2 + 10;
  if (*plVar1 != 0) {
    PmWnfUnsubscribeChangeNotification(plVar1);
    *plVar1 = 0;
  }
  if (puVar2[0x10] != 0) {
    (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,puVar2[0x10],1);
  }
  if (puVar2[9] != 0) {
    ExFreePoolWithTag(puVar2[9],0);
    puVar2[9] = 0;
  }
  if (puVar2[8] != 0) {
    ExFreePoolWithTag(puVar2[8],0);
    puVar2[8] = 0;
  }
  if (puVar2[2] != 0) {
    PmWnfUnsubscribeChangeNotification(puVar2 + 2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xb,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return;
}



===== UpmDeviceFindConnectorByHandle @ 14001b720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct UPMCONNECTOR__ * __ptr64 __cdecl UpmDeviceFindConnectorByHandle(struct _UPM_DEVICE_CONTEXT
   * __ptr64,unsigned __int64) */

UPMCONNECTOR__ * __cdecl
UpmDeviceFindConnectorByHandle(_UPM_DEVICE_CONTEXT *param_1,__uint64 param_2)

{
  uint uVar1;
  __uint64 _Var2;
  longlong lVar3;
  uint uVar4;
  
  _Var2 = 0;
  lVar3 = 0;
  uVar4 = 0;
  do {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    if (uVar1 <= uVar4) {
LAB_14001b7b8:
      return (UPMCONNECTOR__ *)(-(ulonglong)(lVar3 != 0) & _Var2);
    }
    _Var2 = (**(code **)(WdfFunctions_01015 + 0x90))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),uVar4);
    if (_Var2 == param_2) {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,_Var2,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
      goto LAB_14001b7b8;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



===== UpmDeviceFindConnectorById @ 14001b7e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct UPMCONNECTOR__ * __ptr64 __cdecl UpmDeviceFindConnectorById(struct _UPM_DEVICE_CONTEXT *
   __ptr64,unsigned __int64) */

UPMCONNECTOR__ * __cdecl UpmDeviceFindConnectorById(_UPM_DEVICE_CONTEXT *param_1,__uint64 param_2)

{
  uint uVar1;
  UPMCONNECTOR__ *pUVar2;
  longlong lVar3;
  uint uVar4;
  
  uVar4 = 0;
  while( true ) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    if (uVar1 <= uVar4) {
      return (UPMCONNECTOR__ *)0x0;
    }
    pUVar2 = (UPMCONNECTOR__ *)
             (**(code **)(WdfFunctions_01015 + 0x90))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),uVar4);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,pUVar2,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
    if (*(__uint64 *)(lVar3 + 0x10) == param_2) break;
    uVar4 = uVar4 + 1;
  }
  return pUVar2;
}



===== UpmDevicePublishWnfStateForHubCollectionChange @ 14001b8a0 =====

/* long __cdecl UpmDevicePublishWnfStateForHubCollectionChange(struct _UPM_DEVICE_CONTEXT * __ptr64)
    */

long __cdecl UpmDevicePublishWnfStateForHubCollectionChange(_UPM_DEVICE_CONTEXT *param_1)

{
  long lVar1;
  undefined8 in_stack_ffffffffffffffe0;
  uint uVar2;
  
  uVar2 = (uint)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  lVar1 = ZwUpdateWnfStateData
                    (&WNF_USB_POLICY_MANAGER_HUB_COLLECTION_STATE,0,0,0,0,(ulonglong)uVar2 << 0x20,0
                    );
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)*(undefined8 *)param_1
                       ,(char)lVar1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
    }
  }
  return lVar1;
}



===== UpmDeviceWnfCallback @ 14001b9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmDeviceWnfCallback(struct _WNF_STATE_NAME const * __ptr64,unsigned long,void *
   __ptr64,void const * __ptr64,unsigned long) */

long __cdecl
UpmDeviceWnfCallback
          (_WNF_STATE_NAME *param_1,ulong param_2,void *param_3,void *param_4,ulong param_5)

{
  UPMCONNECTOR__ *pUVar1;
  _UPM_CONNECTOR_CONTEXT *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x51,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  if (param_5 == 0xd) {
    if (param_4 == (void *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x53,
                       &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
    }
    else {
      pUVar1 = UpmDeviceFindConnectorById(param_3,*(__uint64 *)param_4);
      if (pUVar1 == (UPMCONNECTOR__ *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x54,
                          &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,
                          (char)*(undefined8 *)param_4);
      }
      else {
        p_Var2 = (_UPM_CONNECTOR_CONTEXT *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,pUVar1,
                            PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
        UpmConnectorWnfHandler(p_Var2,param_4,param_2);
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x52,
                      &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)param_5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x55,
                     &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids);
  }
  return 0;
}



===== UpmDumpPdo @ 14001bb5c =====

/* void __cdecl UpmDumpPdo(union _USBC_PD_POWER_DATA_OBJECT * __ptr64,bool,bool) */

void __cdecl UpmDumpPdo(_USBC_PD_POWER_DATA_OBJECT *param_1,bool param_2,bool param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  undefined7 in_register_00000081;
  undefined2 uVar4;
  char *pcVar5;
  undefined8 in_stack_ffffffffffffff98;
  
  uVar1 = *(uint *)param_1;
  pcVar3 = "Partner";
  pcVar5 = "Source";
  if (!param_2) {
    pcVar3 = "Local";
  }
  if (!param_3) {
    pcVar5 = "Sink";
  }
  uVar2 = uVar1 >> 0x1e;
  if (uVar2 == 0) {
    if (param_3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ssddddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_ssdddddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if (uVar2 == 1) {
      if (param_3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x72;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x73;
      }
    }
    else {
      if (uVar2 != 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_ssdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return;
      }
      if (param_3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x74;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar4 = 0x75;
      }
    }
    uVar2 = uVar1 >> 0x14 & 0x3ff;
    WPP_RECORDER_SF_ssdddD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar2,
               CONCAT71(in_register_00000081,param_3),uVar4,in_stack_ffffffffffffff98,pcVar3,pcVar5,
               (char)uVar1,(char)(uVar1 >> 10),(char)uVar2,(char)uVar1);
  }
  return;
}



===== WPP_RECORDER_SF_DDiD @ 14001be20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDiD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x4a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x4a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_DiD @ 14001bf34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DiD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x4b,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x4b,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DisDL @ 14001c028 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DisDL(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000040[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x23,&uStack0000000000000030,4,
               &uStack0000000000000038,8,pcVar3,lVar2,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000040[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x23,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,in_stack_00000040,lVar1,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_Lid @ 14001c1f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lid(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,8
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_dDL @ 14001c2fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x5d,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x5d,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_dddddddD @ 14001c3e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dddddddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x60,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x60,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_di @ 14001c57c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_di(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x13,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x13,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_icdd @ 14001c650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_icdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,1,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,1,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_idDLdd @ 14001c770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_idDLdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x12,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x12,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_ii @ 14001c8c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qiiD @ 14001c994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiiD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x5c,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x5c,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_ssdD @ 14001caa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssdD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *in_stack_00000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000038[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x76,pcVar2,lVar3,pcVar5,lVar4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  if (in_stack_00000038 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,3,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x76,
                  in_stack_00000030,lVar1,in_stack_00000038,lVar4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_ssdddD @ 14001cc84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssdddD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,char *param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10,undefined1 param_11)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (param_7[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (param_6 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (param_6[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,param_4,pcVar2,lVar3,pcVar5,lVar4,
               &param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  }
  if (param_7 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_7[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  lVar3 = -1;
  if (param_6 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (param_6[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,param_4,param_6,lVar1
                  ,param_7,lVar4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_SF_ssdddddddD @ 14001cebc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssdddddddD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *in_stack_00000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000038[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x71,pcVar2,lVar3,pcVar5,lVar4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,
               &uStack0000000000000070,4,&uStack0000000000000078,4,0);
  }
  if (in_stack_00000038 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x71,
                  in_stack_00000030,lVar1,in_stack_00000038,lVar4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,0);
  return;
}



===== WPP_RECORDER_SF_ssddddddddD @ 14001d188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ssddddddddD(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *in_stack_00000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  undefined1 uStack0000000000000078;
  undefined1 uStack0000000000000080;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000038[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar3 = lVar1;
        lVar1 = lVar3 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar2 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x70,pcVar2,lVar3,pcVar5,lVar4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,
               &uStack0000000000000070,4,&uStack0000000000000078,4,&uStack0000000000000080,4,0);
  }
  if (in_stack_00000038 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = lVar1 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,0x70,
                  in_stack_00000030,lVar1,in_stack_00000038,lVar4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,0);
  return;
}



===== UpmClientAssignConnectorPowerLevel @ 14001d480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientAssignConnectorPowerLevel(struct _UPM_DEVICE_CONTEXT * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientAssignConnectorPowerLevel
          (_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  UPMCONNECTOR__ *pUVar2;
  longlong lVar3;
  WDFREQUEST__ *pWVar4;
  undefined8 uVar5;
  __uint64 *local_res18;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 uVar6;
  undefined1 uVar7;
  
  local_res18 = (__uint64 *)0x0;
  pWVar4 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    pWVar4 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x39,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar5 = 0x15;
  uVar7 = SUB81(param_2,0);
  if (param_4 == 0x15) {
    uVar6 = 0;
    pWVar4 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x15,&local_res18);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar5,0x3b,uVar6,
                            (char)*(undefined8 *)param_1,uVar7,(char)iVar1);
      }
    }
    else {
      pUVar2 = UpmDeviceFindConnectorByHandle(param_1,*local_res18);
      if (pUVar2 == (UPMCONNECTOR__ *)0x0) {
        iVar1 = -0x3ffffddb;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,uVar5,0x3c,uVar6,
                              (char)*(undefined8 *)param_1,uVar7,(char)*local_res18);
        }
      }
      else {
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,pUVar2,
                           PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
        uVar5 = *(undefined8 *)(lVar3 + 0x1a38);
        pWVar4 = param_2;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals);
        if (-1 < iVar1) goto LAB_14001d6b0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqid
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar5,0x3d,uVar6,
                     (char)*(undefined8 *)param_1,uVar7,(char)*local_res18,(char)iVar1);
        }
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,0x15,0x3a,
                 in_stack_ffffffffffffffb8,(char)*(undefined8 *)param_1,uVar7,0x14,0x15,
                 (char)param_4);
    }
    iVar1 = -0x3ffffdfa;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
LAB_14001d6b0:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x3e,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientEvtIoDeviceControl @ 14001d710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientEvtIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
UpmClientEvtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  uchar uVar1;
  _UPM_DEVICE_CONTEXT *p_Var2;
  longlong lVar3;
  WDFREQUEST__ *pWVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined *in_stack_ffffffffffffffc8;
  undefined1 uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar5 = PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268;
  p_Var2 = (_UPM_DEVICE_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar6);
  uVar7 = SUB81(param_2,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar5,0x13,
                        in_stack_ffffffffffffffc8,(char)*(undefined8 *)p_Var2,uVar7,(char)param_5);
  }
  pWVar4 = param_2;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  if (*(char *)(lVar3 + 0x40) == '\x01') {
    uVar1 = UpmInternalIsFromPrivilegedUserOrGroup(p_Var2);
    if (uVar1 != '\0') goto LAB_14001d8bb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,puVar5,0x10,
                          in_stack_ffffffffffffffc8,(char)*(undefined8 *)p_Var2,uVar7,0);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,puVar5,0x14,
                          in_stack_ffffffffffffffc8,(char)*(undefined8 *)p_Var2,uVar7,0x22);
    }
    uVar6 = 0xc0000022;
  }
  else {
LAB_14001d8bb:
    if (param_5 == 0x574200) {
      UpmClientRegister(p_Var2,param_2,param_3,param_4);
      goto LAB_14001d997;
    }
    if (param_5 == 0x574204) {
      UpmClientGetHubCollectionDelta(p_Var2,param_2,param_3,param_4);
      goto LAB_14001d997;
    }
    if (param_5 == 0x574208) {
      UpmClientGetHubProperties(p_Var2,param_2,param_3,param_4);
      goto LAB_14001d997;
    }
    if (param_5 == 0x57420c) {
      UpmClientGetConnectorSnapshot(p_Var2,param_2,param_3,param_4);
      goto LAB_14001d997;
    }
    if (param_5 == 0x574210) {
      UpmClientGetConnectorState(p_Var2,param_2,param_3,param_4);
      goto LAB_14001d997;
    }
    if (param_5 == 0x578214) {
      UpmClientAssignConnectorPowerLevel(p_Var2,param_2,(__uint64)puVar5,param_4);
      goto LAB_14001d997;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar5,0x15,
                          in_stack_ffffffffffffffc8,(char)*(undefined8 *)p_Var2,uVar7,(char)param_5)
      ;
    }
    uVar6 = 0xc00000bb;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
LAB_14001d997:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x16,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientGetConnectorSnapshot @ 14001d9f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientGetConnectorSnapshot(struct _UPM_DEVICE_CONTEXT * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientGetConnectorSnapshot
          (_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  UPMCONNECTOR__ *pUVar2;
  _UPM_CONNECTOR_CONTEXT *p_Var3;
  WDFREQUEST__ *pWVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  _UPM_CONNECTOR_PROPERTIES *local_res20;
  undefined *in_stack_ffffffffffffff98;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  __uint64 *local_38 [2];
  
  local_38[0] = (__uint64 *)0x0;
  local_res20 = (_UPM_CONNECTOR_PROPERTIES *)0x0;
  pWVar4 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff98 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    pWVar4 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2b,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar5 = 8;
  uVar9 = SUB81(param_2,0);
  if (param_4 == 8) {
    if (param_3 == 0x9c2) {
      uVar7 = 0;
      pWVar4 = param_2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,local_38);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dc96;
        uVar8 = (undefined1)*(undefined8 *)param_1;
        uVar6 = 0x2e;
      }
      else {
        uVar5 = 0x9c2;
        uVar7 = 0;
        pWVar4 = param_2;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,0x9c2,&local_res20);
        if (-1 < iVar1) {
          pUVar2 = UpmDeviceFindConnectorByHandle(param_1,*local_38[0]);
          if (pUVar2 == (UPMCONNECTOR__ *)0x0) {
            iVar1 = -0x3ffffff3;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqid
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,uVar5,0x30,uVar7,
                         (char)*(undefined8 *)param_1,uVar9,(char)*local_38[0],0xd);
            }
          }
          else {
            p_Var3 = (_UPM_CONNECTOR_CONTEXT *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,pUVar2,
                                PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
            UpmConnectorGetProperties(p_Var3,local_res20);
            UpmConnectorGetState(p_Var3,(_UPM_CONNECTOR_STATE *)(local_res20 + 0x332));
            (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x9c2);
            iVar1 = 0;
          }
          goto LAB_14001dc96;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001dc96;
        uVar6 = 0x2f;
        uVar8 = (undefined1)*(undefined8 *)param_1;
      }
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar5,uVar6,uVar7,uVar8,
                          uVar9,(char)iVar1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqLPP
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,8,0x2d,
                   in_stack_ffffffffffffff98,(char)*(undefined8 *)param_1,uVar9,0xc,0xc2,
                   (char)param_3);
      }
      iVar1 = -0x3ffffdfa;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,8,0x2c,in_stack_ffffffffffffff98,
                 (char)*(undefined8 *)param_1,uVar9,0xc,8,(char)param_4);
    }
    iVar1 = -0x3ffffdfa;
  }
LAB_14001dc96:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x31,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientGetConnectorState @ 14001dd08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientGetConnectorState(struct _UPM_DEVICE_CONTEXT * __ptr64,struct WDFREQUEST__
   * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientGetConnectorState
          (_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  UPMCONNECTOR__ *pUVar2;
  _UPM_CONNECTOR_CONTEXT *p_Var3;
  WDFREQUEST__ *pWVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  __uint64 *local_res20;
  undefined *in_stack_ffffffffffffff98;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  _UPM_CONNECTOR_STATE *local_38 [2];
  
  local_res20 = (__uint64 *)0x0;
  local_38[0] = (_UPM_CONNECTOR_STATE *)0x0;
  pWVar4 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff98 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    pWVar4 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x32,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar5 = 8;
  uVar9 = SUB81(param_2,0);
  if (param_4 == 8) {
    if (param_3 == 0x690) {
      uVar7 = 0;
      pWVar4 = param_2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res20);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001df91;
        uVar8 = (undefined1)*(undefined8 *)param_1;
        uVar6 = 0x35;
      }
      else {
        uVar5 = 0x690;
        uVar7 = 0;
        pWVar4 = param_2;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x690,local_38);
        if (-1 < iVar1) {
          pUVar2 = UpmDeviceFindConnectorByHandle(param_1,*local_res20);
          if (pUVar2 == (UPMCONNECTOR__ *)0x0) {
            iVar1 = -0x3ffffddb;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqid
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,uVar5,0x37,uVar7,
                         (char)*(undefined8 *)param_1,uVar9,(char)*local_res20,0x25);
            }
          }
          else {
            p_Var3 = (_UPM_CONNECTOR_CONTEXT *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,pUVar2,
                                PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
            UpmConnectorGetState(p_Var3,local_38[0]);
            (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x690);
            iVar1 = 0;
          }
          goto LAB_14001df91;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001df91;
        uVar6 = 0x36;
        uVar8 = (undefined1)*(undefined8 *)param_1;
      }
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar5,uVar6,uVar7,uVar8,
                          uVar9,(char)iVar1);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqLPP
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,8,0x34,
                   in_stack_ffffffffffffff98,(char)*(undefined8 *)param_1,uVar9,0x10,0x90,
                   (char)param_3);
      }
      iVar1 = -0x3ffffdfa;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,8,0x33,in_stack_ffffffffffffff98,
                 (char)*(undefined8 *)param_1,uVar9,0x10,8,(char)param_4);
    }
    iVar1 = -0x3ffffdfa;
  }
LAB_14001df91:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x38,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientGetHubCollectionDelta @ 14001e004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientGetHubCollectionDelta(struct _UPM_DEVICE_CONTEXT * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientGetHubCollectionDelta
          (_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  WDFREQUEST__ *pWVar4;
  __uint64 _Var5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined4 *local_res20;
  ulonglong *in_stack_ffffffffffffff88;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint *local_38;
  ulonglong local_30;
  
  local_38 = (uint *)0x0;
  local_res20 = (undefined4 *)0x0;
  local_30 = 0;
  _Var5 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Var5 = 1;
    in_stack_ffffffffffffff88 = (ulonglong *)&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1d,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar3 = 0x14;
  uVar9 = SUB81(param_2,0);
  if (param_4 < 0x14) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0x1e;
      uVar10 = 0x14;
LAB_14001e09d:
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,_Var5,uVar7,
                 in_stack_ffffffffffffff88,(char)*(undefined8 *)param_1,uVar9,4,uVar10,(char)param_4
                );
    }
  }
  else {
    in_stack_ffffffffffffff88 = &local_30;
    _Var5 = 0x14;
    pWVar4 = param_2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x14,&local_38);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqLd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,_Var5,0x1f,
                   in_stack_ffffffffffffff88,(char)*(undefined8 *)param_1,uVar9,4,(char)iVar2);
      }
      goto LAB_14001e27d;
    }
    uVar1 = *local_38;
    uVar3 = (ulonglong)uVar1;
    if ((uVar1 < 2) || ((ulonglong)(uVar1 - 1) * 0x10 + 0x14 <= local_30)) {
      if (param_3 == 0x208) {
        uVar6 = 0x208;
        uVar8 = 0;
        pWVar4 = param_2;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                          (WdfDriverGlobals,param_2,0x208,&local_res20);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar6,0x22,uVar8,
                                (char)*(undefined8 *)param_1,uVar9,(char)iVar2);
          }
        }
        else {
          if (*local_38 == 0) {
            *local_res20 = 1;
            local_res20[1] = 0;
            *(undefined8 *)(local_res20 + 2) = *(undefined8 *)param_1;
          }
          else {
            *local_res20 = 0;
            local_res20[1] = 0;
          }
          (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x208);
          iVar2 = 0;
        }
        goto LAB_14001e27d;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x21;
        uVar10 = 8;
        param_4 = param_3;
        goto LAB_14001e09d;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqDLPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  iVar2 = -0x3ffffdfa;
LAB_14001e27d:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x23,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientGetHubProperties @ 14001e2fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientGetHubProperties(struct _UPM_DEVICE_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientGetHubProperties
          (_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 uVar3;
  longlong lVar4;
  WDFREQUEST__ *pWVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  undefined8 *local_res20;
  undefined *in_stack_ffffffffffffff98;
  undefined8 uVar10;
  undefined1 uVar11;
  int iVar12;
  longlong *local_38 [2];
  
  local_38[0] = (longlong *)0x0;
  local_res20 = (undefined8 *)0x0;
  pWVar5 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff98 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    pWVar5 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x24,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar8 = 8;
  uVar11 = SUB81(param_2,0);
  if (param_4 != 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar5,8,0x25,in_stack_ffffffffffffff98,
                 (char)*(undefined8 *)param_1,uVar11,8,8,(char)param_4);
    }
    iVar12 = -0x3ffffdfa;
    goto LAB_14001e5b5;
  }
  if (param_3 != 0x21c) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar5,8,0x26,in_stack_ffffffffffffff98,
                 (char)*(undefined8 *)param_1,uVar11,8,0x1c,(char)param_3);
    }
    iVar12 = -0x3ffffdfa;
    goto LAB_14001e5b5;
  }
  uVar10 = 0;
  pWVar5 = param_2;
  iVar12 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,local_38);
  if (iVar12 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e5b5;
    lVar4 = *(longlong *)param_1;
    uVar9 = 0x27;
LAB_14001e451:
    uVar3 = (undefined1)lVar4;
  }
  else {
    lVar4 = *(longlong *)param_1;
    if (*local_38[0] != lVar4) {
      iVar12 = -0x3ffffff8;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e5b5;
      uVar9 = 0x28;
      iVar12 = -0x3ffffff8;
      goto LAB_14001e451;
    }
    uVar8 = 0x21c;
    uVar10 = 0;
    pWVar5 = param_2;
    iVar12 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x21c,&local_res20);
    if (-1 < iVar12) {
      *local_res20 = *(undefined8 *)param_1;
      local_res20[1] = 0;
      local_res20[2] = 0;
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      uVar7 = 0;
      *(undefined4 *)(local_res20 + 3) = uVar1;
      while (uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                               (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20)), uVar7 < uVar2) {
        uVar8 = (**(code **)(WdfFunctions_01015 + 0x90))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),uVar7);
        uVar6 = (ulonglong)uVar7;
        uVar7 = uVar7 + 1;
        *(undefined8 *)((longlong)local_res20 + uVar6 * 8 + 0x1c) = uVar8;
      }
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x21c);
      iVar12 = 0;
      goto LAB_14001e5b5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001e5b5;
    uVar9 = 0x29;
    uVar3 = (undefined1)*(undefined8 *)param_1;
  }
  WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar5,uVar8,uVar9,uVar10,uVar3,
                      uVar11,(char)iVar12);
LAB_14001e5b5:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar12);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2a,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmClientRegister @ 14001e628 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmClientRegister(struct _UPM_DEVICE_CONTEXT * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
UpmClientRegister(_UPM_DEVICE_CONTEXT *param_1,WDFREQUEST__ *param_2,__uint64 param_3,
                 __uint64 param_4)

{
  int iVar1;
  WDFREQUEST__ *pWVar2;
  __uint64 _Var3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined4 *local_res20;
  undefined *in_stack_ffffffffffffff98;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined4 *local_38 [2];
  
  local_res20 = (undefined4 *)0x0;
  local_38[0] = (undefined4 *)0x0;
  pWVar2 = param_2;
  _Var3 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Var3 = 1;
    in_stack_ffffffffffffff98 = &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids;
    pWVar2 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x17,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  uVar7 = SUB81(param_2,0);
  if (param_4 < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x18;
LAB_14001e6af:
      WPP_RECORDER_SF_qqLPP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,_Var3,uVar5,
                 in_stack_ffffffffffffff98,(char)*(undefined8 *)param_1,uVar7,0,4,(char)param_4);
    }
  }
  else {
    if (param_3 == 4) {
      uVar4 = 4;
      uVar6 = 0;
      pWVar2 = param_2;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_res20);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqLd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,uVar4,0x1a,uVar6,
                     (char)*(undefined8 *)param_1,uVar7,0,(char)iVar1);
        }
      }
      else {
        uVar4 = 4;
        uVar6 = 0;
        pWVar2 = param_2;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,local_38);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar2,uVar4,0x1b,uVar6,
                                (char)*(undefined8 *)param_1,uVar7,(char)iVar1);
          }
        }
        else {
          *local_38[0] = *local_res20;
          (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,4);
          iVar1 = 0;
        }
      }
      goto LAB_14001e808;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x19;
      param_4 = param_3;
      goto LAB_14001e6af;
    }
  }
  iVar1 = -0x3ffffdfa;
LAB_14001e808:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1c,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmConnectorAssignPowerLevelEvtIoDeviceControl @ 14001e880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmConnectorAssignPowerLevelEvtIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
UpmConnectorAssignPowerLevelEvtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  _UPM_DEVICE_CONTEXT *p_Var3;
  UPMCONNECTOR__ *pUVar4;
  _UPM_CONNECTOR_CONTEXT *p_Var5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  _UPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *local_28;
  undefined8 local_20;
  
  local_28 = (_UPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS *)0x0;
  local_20 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x3f,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x15,&local_28,0);
  uVar7 = 0;
  (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x690,&local_20);
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar6 = PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268;
  p_Var3 = (_UPM_DEVICE_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  pUVar4 = UpmDeviceFindConnectorByHandle(p_Var3,*(__uint64 *)local_28);
  uVar8 = SUB81(param_2,0);
  if (pUVar4 == (UPMCONNECTOR__ *)0x0) {
    lVar1 = -0x3ffffddb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0,puVar6,0x40,uVar7,
                          (char)*(undefined8 *)p_Var3,uVar8,(char)*(__uint64 *)local_28);
    }
  }
  else {
    puVar6 = PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240;
    p_Var5 = (_UPM_CONNECTOR_CONTEXT *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    if (p_Var5[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) {
      lVar1 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pUVar4 = (UPMCONNECTOR__ *)CONCAT71((int7)(*(__uint64 *)local_28 >> 8),2);
        WPP_RECORDER_SF_qiqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x41,uVar7,
                   (char)*(undefined8 *)p_Var3,(char)*(undefined8 *)(p_Var5 + 0x10),uVar8,
                   (char)*(__uint64 *)local_28,0xd);
      }
    }
    else {
      puVar6 = (undefined *)0x0;
      uVar2 = WdfDriverGlobals;
      (**(code **)(WdfFunctions_01015 + 0x9c8))();
      if (*(longlong *)(p_Var5 + 0x1a40) == 0) {
        *(WDFREQUEST__ **)(p_Var5 + 0x1a40) = param_2;
        lVar1 = 0;
      }
      else {
        lVar1 = -0x7fffffef;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          WPP_RECORDER_SF_qiqqd(uVar2);
        }
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  (uVar2,0,puVar6,"Parallel AssignConnectorPowerLevel requests");
      }
      pUVar4 = *(UPMCONNECTOR__ **)(p_Var5 + 0x19e0);
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
      if (-1 < lVar1) {
        lVar1 = UpmConnectorInvokeSetPowerLevel(p_Var5,local_28);
        if (-1 < lVar1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_qiqid
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar6,0x45,uVar7,
                     (char)*(undefined8 *)p_Var3,(char)*(undefined8 *)(p_Var5 + 0x10),uVar8,
                     (char)*(__uint64 *)local_28,(char)lVar1);
          goto LAB_14001ea40;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qiqid
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0x43,uVar7,
                     (char)*(undefined8 *)p_Var3,(char)*(undefined8 *)(p_Var5 + 0x10),uVar8,
                     (char)*(__uint64 *)local_28,(char)lVar1);
        }
        puVar6 = (undefined *)0x0;
        uVar2 = WdfDriverGlobals;
        (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0))
        ;
        if (*(WDFREQUEST__ **)(p_Var5 + 0x1a40) == param_2) {
          *(undefined8 *)(p_Var5 + 0x1a40) = 0;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            WPP_RECORDER_SF_qiqq(uVar2);
          }
          MicrosoftTelemetryAssertTriggeredArgsMsgKM
                    (uVar2,(uint)(*(longlong *)(p_Var5 + 0x1a40) != 0),puVar6,
                     "UCM reports unexpected SetPowerLevel completion.");
          param_2 = (WDFREQUEST__ *)0x0;
        }
        pUVar4 = *(UPMCONNECTOR__ **)(p_Var5 + 0x19e0);
        (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals);
      }
    }
  }
  if (param_2 != (WDFREQUEST__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqid
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar4,puVar6,0x46,uVar7,
                 (char)*(undefined8 *)p_Var3,(char)param_2,(char)*(__uint64 *)local_28,(char)lVar1);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  }
LAB_14001ea40:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x47,
                     &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids);
  }
  return;
}



===== UpmInternalIsFromPrivilegedUserOrGroup @ 14001ed24 =====

/* unsigned char __cdecl UpmInternalIsFromPrivilegedUserOrGroup(struct _UPM_DEVICE_CONTEXT *
   __ptr64) */

uchar __cdecl UpmInternalIsFromPrivilegedUserOrGroup(_UPM_DEVICE_CONTEXT *param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uchar uVar6;
  undefined2 uVar7;
  bool bVar8;
  uint *local_res8;
  undefined8 *local_res10;
  longlong local_38 [4];
  
  local_res8 = (uint *)0x0;
  local_res10 = (undefined8 *)0x0;
  uVar6 = '\0';
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if (*(longlong *)(param_1 + 0x40) == 0) {
    lVar3 = ExAllocatePool2(0x40,0x44,0x536d7055);
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return '\0';
      }
      uVar7 = 10;
      goto LAB_14001ed9f;
    }
    iVar2 = SecLookupWellKnownSid(0x16,lVar3,0x44);
    if (-1 < iVar2) {
      LOCK();
      bVar8 = *(longlong *)(param_1 + 0x40) == 0;
      if (bVar8) {
        *(longlong *)(param_1 + 0x40) = lVar3;
      }
      UNLOCK();
      if (!bVar8) {
        ExFreePoolWithTag(lVar3,0);
      }
      goto LAB_14001ee5e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee2d;
    uVar7 = 0xb;
LAB_14001ee05:
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                      &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,(char)iVar2);
LAB_14001ee2d:
    ExFreePoolWithTag(lVar3,0);
    return '\0';
  }
LAB_14001ee5e:
  if (*(longlong *)(param_1 + 0x48) == 0) {
    lVar3 = ExAllocatePool2(0x40,0x44,0x536d7055);
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return '\0';
      }
      uVar7 = 0xc;
LAB_14001ed9f:
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                        &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x9a);
      return '\0';
    }
    iVar2 = SecLookupWellKnownSid(0x62,lVar3,0x44);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ee2d;
      uVar7 = 0xd;
      goto LAB_14001ee05;
    }
    LOCK();
    bVar8 = *(longlong *)(param_1 + 0x48) == 0;
    if (bVar8) {
      *(longlong *)(param_1 + 0x48) = lVar3;
    }
    UNLOCK();
    if (!bVar8) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  SeCaptureSubjectContext(local_38);
  SeLockSubjectContext(local_38);
  lVar3 = local_38[2];
  if (local_38[0] != 0) {
    lVar3 = local_38[0];
  }
  cVar1 = SeTokenIsAdmin(lVar3);
  if (cVar1 == '\0') {
    iVar2 = SeQueryInformationToken(lVar3,1,&local_res10);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001f038;
      uVar7 = 0xe;
    }
    else {
      cVar1 = RtlEqualSid(*(undefined8 *)(param_1 + 0x40),*local_res10);
      if (cVar1 != '\0') goto LAB_14001f035;
      iVar2 = SeQueryInformationToken(lVar3,2,&local_res8);
      if (-1 < iVar2) {
        uVar5 = 0;
        if (*local_res8 != 0) {
          do {
            cVar1 = RtlEqualSid(*(undefined8 *)(param_1 + 0x48),
                                *(undefined8 *)(local_res8 + uVar5 * 4 + 2));
            if (cVar1 != '\0') goto LAB_14001f035;
            uVar4 = (int)uVar5 + 1;
            uVar5 = (ulonglong)uVar4;
          } while (uVar4 < *local_res8);
        }
        goto LAB_14001f038;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001f038;
      uVar7 = 0xf;
    }
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                      &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,(char)iVar2);
  }
  else {
LAB_14001f035:
    uVar6 = '\x01';
  }
LAB_14001f038:
  if (local_res8 != (uint *)0x0) {
    ExFreePoolWithTag(local_res8,0);
    local_res8 = (uint *)0x0;
  }
  if (local_res10 != (undefined8 *)0x0) {
    ExFreePoolWithTag(local_res10,0);
    local_res10 = (undefined8 *)0x0;
  }
  SeUnlockSubjectContext(local_38);
  SeReleaseSubjectContext(local_38);
  return uVar6;
}



===== WPP_RECORDER_SF_qiqid @ 14001f0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqid
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,8,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,8,&param_9,8,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_qiqq @ 14001f1f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x44,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x44,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_qiqqd @ 14001f300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qiqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0x80000011;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x42,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,
               local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x42,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qqDLPP @ 14001f440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDLPP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0x574204;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x20,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,local_18,4,
               &uStack0000000000000050,8,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,0x20,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  local_18,4,&uStack0000000000000050,8,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_qqL @ 14001f5a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLPP @ 14001f6a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLPP
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,8,&param_10,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_qqLd @ 14001f7dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 14001f8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqi @ 14001f9ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qqid @ 14001fadc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqid
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_b9f499c8723733e9fb08e8268f35f89d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== UpmBpEvtConnectorStateChanged @ 14001fbf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmBpEvtConnectorStateChanged(struct _UPM_CONNECTOR_CONTEXT * __ptr64) */

void __cdecl UpmBpEvtConnectorStateChanged(_UPM_CONNECTOR_CONTEXT *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1e,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  lVar2 = *(longlong *)param_1;
  iVar1 = *(int *)(param_1 + 0xd38);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x58),0);
  if (*(char *)(lVar2 + 0x79) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x22;
LAB_14001fcff:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar3,
                       &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
    }
  }
  else {
    if (iVar1 == *(int *)(lVar2 + 0x74)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x20,
                         &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
      }
      goto LAB_14001fd45;
    }
    *(int *)(lVar2 + 0x74) = iVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x21;
      goto LAB_14001fcff;
    }
  }
  *(undefined1 *)(lVar2 + 0x79) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9f8))
            (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x80),0xfffffffffe363c80);
LAB_14001fd45:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x58));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x26,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  return;
}



===== UpmBpEvtDebounceTimerFunc @ 14001fdc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmBpEvtDebounceTimerFunc(struct WDFTIMER__ * __ptr64) */

void __cdecl UpmBpEvtDebounceTimerFunc(WDFTIMER__ *param_1)

{
  undefined8 uVar1;
  _UPM_DEVICE_CONTEXT *p_Var2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  p_Var2 = (_UPM_DEVICE_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar1,PTR__WDF_UPM_DEVICE_CONTEXT_TYPE_INFO_14002a268);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x58),0);
  if (p_Var2[0x78] != (_UPM_DEVICE_CONTEXT)0x0) {
    *(undefined4 *)(p_Var2 + 0x60) = *(undefined4 *)(p_Var2 + 0x70);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
                        &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                        (char)*(undefined4 *)(p_Var2 + 0x70));
    }
  }
  *(undefined2 *)(p_Var2 + 0x78) = 0;
  UpmBpRunPolicyWithLock(p_Var2);
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var2 + 0x58));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1d,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  return;
}



===== UpmBpInitialize @ 14001ff24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmBpInitialize(struct _UPM_DEVICE_CONTEXT * __ptr64) */

long __cdecl UpmBpInitialize(_UPM_DEVICE_CONTEXT *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  code *pcStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  _UPM_DEVICE_CONTEXT *local_50;
  code *local_48;
  code *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  code *local_28;
  
  local_54 = 0;
  local_ac = 0;
  local_98 = 0;
  local_88 = 0;
  local_b8 = 0;
  local_d8 = 0;
  local_c8 = *(undefined8 *)param_1;
  uStack_c0 = 0;
  uStack_e0 = 0;
  local_e8 = 0x38;
  local_38 = 0;
  uStack_30 = 0;
  uStack_d0 = 0x100000001;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_e8,param_1 + 0x58);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 10;
  }
  else {
    local_b8 = 0;
    local_c8 = *(undefined8 *)param_1;
    uStack_68 = 0;
    local_80 = 0x28;
    local_d8 = 0;
    uStack_c0 = 0;
    local_60 = 0;
    pcStack_78 = UpmBpEvtDebounceTimerFunc;
    uStack_e0 = 0;
    local_e8 = 0x38;
    uStack_d0 = 0x100000002;
    local_70 = 0x100000000;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                      (WdfDriverGlobals,&local_80,&local_e8,param_1 + 0x80);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0xb;
    }
    else {
      local_54 = 0;
      local_ac = 0;
      local_98 = 0;
      local_88 = 0;
      local_90 = 0;
      local_48 = _guard_check_icall;
      local_40 = _guard_check_icall;
      local_28 = UpmBpPassiveCoolingNotification;
      local_a8 = &local_58;
      local_a0 = &GUID_THERMAL_COOLING_INTERFACE;
      local_38 = 0;
      uStack_30 = 0;
      local_58 = 0x10038;
      local_b0 = 0x30;
      local_50 = param_1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x720))
                        (WdfDriverGlobals,*(undefined8 *)param_1,&local_b0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0xd;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe,
                           &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
        }
        puVar2 = &GUID_DEVINTERFACE_THERMAL_COOLING;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                          (WdfDriverGlobals,*(undefined8 *)param_1,
                           &GUID_DEVINTERFACE_THERMAL_COOLING,0);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar3 = 0xf;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar2 = (undefined *)0x1;
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x10,
                             &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
          }
          iVar1 = PmWnfSubscribeChangeNotification
                            ((undefined8 *)&WNF_USB_XHCI_AUDIO_OFFLOAD_STATE,1,puVar2,0x140020a00,
                             param_1,(undefined8 *)(param_1 + 0x50));
          if (-1 < iVar1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar1;
            }
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x12,
                             &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
            return iVar1;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar3 = 0x11;
        }
      }
    }
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                    &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,(char)iVar1);
  return iVar1;
}



===== UpmBpPassiveCoolingNotification @ 140020280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmBpPassiveCoolingNotification(void * __ptr64,unsigned long) */

void __cdecl UpmBpPassiveCoolingNotification(void *param_1,ulong param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  if (*(byte *)((longlong)param_1 + 10) < param_2) {
    iVar1 = 0;
  }
  else {
    iVar1 = 2 - (uint)(*(byte *)((longlong)param_1 + 0xb) < param_2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x16,
                       &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,(char)param_2,(char)iVar1);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x58),0);
  if (*(char *)((longlong)param_1 + 0x78) == '\0') {
    *(int *)((longlong)param_1 + 0x70) = iVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = 0x19;
LAB_1400203b0:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar2,
                       &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
    }
  }
  else {
    if (iVar1 == *(int *)((longlong)param_1 + 0x70)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x17,
                         &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
      }
      goto LAB_1400203f6;
    }
    *(int *)((longlong)param_1 + 0x70) = iVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = 0x18;
      goto LAB_1400203b0;
    }
  }
  *(undefined1 *)((longlong)param_1 + 0x78) = 1;
  (**(code **)(WdfFunctions_01015 + 0x9f8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x80),0xfffffffffe363c80);
LAB_1400203f6:
  (**(code **)(WdfFunctions_01015 + 0x9d0))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x58));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids);
  }
  return;
}



===== UpmBpRunPolicyWithLock @ 14002046c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl UpmBpRunPolicyWithLock(struct _UPM_DEVICE_CONTEXT * __ptr64) */

void __cdecl UpmBpRunPolicyWithLock(_UPM_DEVICE_CONTEXT *param_1)

{
  _UPM_CONNECTOR_CONTEXT _Var1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  _UPM_CONNECTOR_CONTEXT *p_Var8;
  _USB_ERROR_NOTIFICATION _Var9;
  undefined4 *puVar10;
  undefined2 uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStackY_a8 [32];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  ulonglong local_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  bVar3 = false;
  bVar12 = false;
  bVar4 = false;
  bVar13 = false;
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x90))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),0);
  p_Var8 = (_UPM_CONNECTOR_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar7,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
  uVar7 = 0;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var8 + 0x19e0),0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_LddL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  _Var1 = p_Var8[0xd18];
  bVar5 = true;
  if ((_Var1 == (_UPM_CONNECTOR_CONTEXT)0x0) || (*(int *)(p_Var8 + 0xd38) != 1)) {
    if ((*(int *)(param_1 + 0x68) == 0) &&
       (((*(int *)(param_1 + 0x60) == 1 && (_Var1 != (_UPM_CONNECTOR_CONTEXT)0x0)) &&
        (*(int *)(p_Var8 + 0xd38) == 2)))) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x28;
LAB_1400205e1:
        uVar7 = 0;
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar11,
                          &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                          (char)*(undefined8 *)(p_Var8 + 0x10));
      }
LAB_140020612:
      bVar3 = true;
    }
    else if ((((p_Var8[0x68] == (_UPM_CONNECTOR_CONTEXT)0x0) &&
              (_Var1 != (_UPM_CONNECTOR_CONTEXT)0x0)) && (*(int *)(p_Var8 + 0xd38) == 2)) &&
            (*(int *)(param_1 + 0x60) == 1)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x29;
        goto LAB_1400205e1;
      }
      goto LAB_140020612;
    }
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (((p_Var8[0x68] == (_UPM_CONNECTOR_CONTEXT)0x0) &&
      (p_Var8[0xd18] != (_UPM_CONNECTOR_CONTEXT)0x0)) &&
     ((*(int *)(p_Var8 + 0xd38) == 2 && (*(int *)(param_1 + 0x60) == 2)))) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0;
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2a,
                        &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                        (char)*(undefined8 *)(p_Var8 + 0x10));
    }
    bVar4 = true;
  }
  if (bVar2) {
    UpmConnectorUnpublishWnfUsbErrorNotificationForBrownoutProtection(p_Var8);
  }
  else {
    if (bVar3) {
      _Var9 = 10;
    }
    else {
      if (!bVar4) goto LAB_140020698;
      _Var9 = 0xb;
    }
    UpmConnectorPublishWnfUsbErrorNotification(p_Var8,_Var9);
  }
LAB_140020698:
  if (*(uint *)(param_1 + 0x68) == 2) {
    if (((1 < *(uint *)(param_1 + 0x60)) || (p_Var8[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0)) ||
       (*(int *)(p_Var8 + 0xd38) != 2)) goto LAB_14002075e;
    bVar12 = param_1[100] != (_UPM_DEVICE_CONTEXT)0x0;
    bVar13 = param_1[100] == (_UPM_DEVICE_CONTEXT)0x0;
  }
  else {
    if (*(uint *)(param_1 + 0x68) < 2) {
      if (*(int *)(param_1 + 0x60) != 2) goto LAB_1400207d0;
      if ((((p_Var8[0xd18] != (_UPM_CONNECTOR_CONTEXT)0x0) && (*(int *)(p_Var8 + 0xd38) == 2)) &&
          (param_1[100] != (_UPM_DEVICE_CONTEXT)0x0)) && (*(int *)(p_Var8 + 0xd2c) == 1)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2b,
                            &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                            (char)*(undefined8 *)(p_Var8 + 0x10));
        }
        bVar3 = false;
        goto LAB_1400207d7;
      }
    }
LAB_14002075e:
    if (*(int *)(param_1 + 0x60) == 2) {
      if (p_Var8[0xd18] == (_UPM_CONNECTOR_CONTEXT)0x0) {
        bVar3 = false;
      }
      else {
        if (*(int *)(p_Var8 + 0xd38) != 2) goto LAB_1400207d0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2c,
                            &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                            (char)*(undefined8 *)(p_Var8 + 0x10));
        }
        bVar3 = true;
      }
      bVar5 = false;
      goto LAB_1400207d7;
    }
  }
LAB_1400207d0:
  bVar5 = false;
  bVar3 = false;
LAB_1400207d7:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var8 + 0x19e0));
  if ((bVar12) || (bVar5)) {
    bVar12 = !bVar12;
    local_50 = 0x14;
    local_4c = 2;
    local_44 = (ulonglong)bVar12;
    local_48 = 3;
    if (*(longlong *)(p_Var8 + 0x50) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x2f,
                           &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,bVar12,
                           (char)*(undefined8 *)(p_Var8 + 0x10));
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Li(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2d,
                           &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,bVar12,
                           (char)*(undefined8 *)(p_Var8 + 0x10));
      }
      puVar10 = &local_50;
      uVar6 = (**(code **)(p_Var8 + 0x50))(*(undefined8 *)param_1,*(undefined8 *)(p_Var8 + 0x10));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Lid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar10,0x2e,
                            &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,(char)local_44,
                            (char)*(undefined8 *)(p_Var8 + 0x10),uVar6);
      }
    }
  }
  else if ((bVar13 != false) || (bVar3)) {
    if (*(longlong *)(p_Var8 + 0x58) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x31,
                          &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                          (char)*(undefined8 *)(p_Var8 + 0x10));
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0;
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x30,
                           &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,
                           (char)*(undefined8 *)(p_Var8 + 0x10),bVar13 ^ 1);
      }
      (**(code **)(p_Var8 + 0x58))
                (*(undefined8 *)param_1,*(undefined8 *)(p_Var8 + 0x10),
                 CONCAT71((int7)((ulonglong)uVar7 >> 8),bVar13) ^ 1);
    }
  }
  return;
}



===== UpmBpWnfCallback @ 140020a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl UpmBpWnfCallback(struct _WNF_STATE_NAME const * __ptr64,unsigned long,void *
   __ptr64,void const * __ptr64,unsigned long) */

long __cdecl
UpmBpWnfCallback(_WNF_STATE_NAME *param_1,ulong param_2,void *param_3,void *param_4,ulong param_5)

{
  if ((param_4 == (void *)0x0) || (param_5 != 1)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                          &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,(char)param_4,
                          (char)param_5,1);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9c8))
              (WdfDriverGlobals,*(undefined8 *)((longlong)param_3 + 0x58),0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x14,
                         &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,*(undefined1 *)param_4,
                         *(undefined1 *)((longlong)param_3 + 100));
    }
    *(undefined1 *)((longlong)param_3 + 100) = *(undefined1 *)param_4;
    UpmBpRunPolicyWithLock(param_3);
    (**(code **)(WdfFunctions_01015 + 0x9d0))
              (WdfDriverGlobals,*(undefined8 *)((longlong)param_3 + 0x58));
  }
  return 0;
}



===== WPP_RECORDER_SF_LddL @ 140020b18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LddL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,0x27,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,0x27,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_dL @ 140020c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,0x1f,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_37d7de29a25c3bfc7e3b45617b16ec8e_Traceguids,0x1f,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== _guard_check_icall @ 140020d00 =====

void _guard_check_icall(void)

{
  return;
}



===== UpmExecuteGlobalPolicies @ 140020d0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UpmExecuteGlobalPolicies(struct _UPM_DEVICE_CONTEXT * __ptr64) */

void __cdecl UpmExecuteGlobalPolicies(_UPM_DEVICE_CONTEXT *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  _UPM_CONNECTOR_CONTEXT *p_Var5;
  _USB_ERROR_NOTIFICATION _Var6;
  uint uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18),0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                      &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids,(char)*(undefined8 *)param_1)
    ;
  }
  bVar1 = false;
  uVar7 = 0;
  while ((uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                            (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20)), uVar7 < uVar2 &&
         (!bVar1))) {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),uVar7);
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar3,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
    uVar3 = *(undefined8 *)(lVar4 + 0x19e0);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,uVar3,0);
    if (((*(char *)(lVar4 + 0xd18) != '\0') && (*(int *)(lVar4 + 0xd38) == 1)) &&
       ((*(int *)(lVar4 + 0xd3c) == 2 &&
        (bVar1 = true, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)))) {
      WPP_RECORDER_SF_qiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,1,0xc,
                          &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids,
                          (char)*(undefined8 *)param_1,(char)*(undefined8 *)(lVar4 + 0x10),
                          (char)uVar7);
    }
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 0x19e0));
    uVar7 = uVar7 + 1;
  }
  uVar7 = 0;
  do {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    if (uVar2 <= uVar7) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe,
                          &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids,
                          (char)*(undefined8 *)param_1);
      }
      (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x18));
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xf,
                         &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids);
      }
      return;
    }
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),uVar7);
    p_Var5 = (_UPM_CONNECTOR_CONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,uVar3,PTR__WDF_UPM_CONNECTOR_CONTEXT_TYPE_INFO_14002a240);
    (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0),0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDidLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (p_Var5[0xd18] != (_UPM_CONNECTOR_CONTEXT)0x0) {
      if (((bVar1) || (*(int *)(p_Var5 + 0xd38) != 1)) ||
         (uVar2 = *(uint *)(p_Var5 + 0xd3c), (uVar2 & 0xfffffffd) == 0)) {
        if (*(int *)(p_Var5 + 0x1a28) != 0) goto LAB_14002106e;
      }
      else {
        if (*(int *)(p_Var5 + 0x1a28) == 0) {
          if (uVar2 == 1) {
            _Var6 = 2;
          }
          else if (uVar2 == 2) {
            _Var6 = 0;
          }
          else {
            if ((uVar2 != 3) && (uVar2 != 4)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x77,
                                  &WPP_5165d293585431d3f8f85bac8c597c7a_Traceguids,(char)uVar2);
              }
              goto LAB_140021084;
            }
            _Var6 = 1;
          }
        }
        else {
LAB_14002106e:
          if (!bVar1) goto LAB_140021084;
          _Var6 = 0;
        }
        UpmConnectorPublishWnfUsbErrorNotification(p_Var5,_Var6);
      }
    }
LAB_140021084:
    (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(p_Var5 + 0x19e0));
    uVar7 = uVar7 + 1;
  } while( true );
}



===== WPP_RECORDER_SF_qDidLLL @ 14002115c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDidLLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids,0xd,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c79f43fa98103274a472d0fe71f7ade0_Traceguids,0xd,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== CheckUSBFnConfiguration @ 1400212d4 =====

int CheckUSBFnConfiguration(uint *param_1,wchar_t *param_2)

{
  rsize_t _SizeInWords;
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  wchar_t *_Dst;
  wchar_t *pwVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong local_res18;
  short *local_res20;
  undefined8 in_stack_ffffffffffffffb8;
  
  local_res18 = 0;
  local_res20 = (short *)0x0;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (param_2[lVar5] != L'\0');
  _SizeInWords = lVar5 * 2 + 0x92;
  _Dst = (wchar_t *)ExAllocatePool2(0x40,_SizeInWords,0x55445246);
  if (_Dst == (wchar_t *)0x0) {
    iVar3 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x1a,
                        &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,0x9a);
    }
  }
  else {
    wcscpy_s(_Dst,_SizeInWords,
             L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Configurations\\");
    pwVar6 = _Dst;
    wcscat_s(_Dst,_SizeInWords,param_2);
    plVar8 = &local_res18;
    iVar3 = MyRegOpenKeyForRead(pwVar6,_Dst,plVar8);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,plVar8,0x1b,
                           in_stack_ffffffffffffffb8,_Dst,(char)iVar3);
      }
    }
    else {
      iVar3 = MyRegQueryString(local_res18,L"InterfaceList",(longlong *)&local_res20);
      psVar2 = local_res20;
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x1c,
                            &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar3);
        }
      }
      else {
        uVar7 = 0;
        sVar1 = *local_res20;
        while ((sVar1 != 0 && (*param_1 != 0xe))) {
          pwVar6 = psVar2 + uVar7;
          if (((*param_1 & 2) == 0) && (iVar4 = _wcsicmp(pwVar6,L"MTP"), iVar4 == 0)) {
            *param_1 = *param_1 | 2;
          }
          else if (((*param_1 & 4) == 0) && (iVar4 = _wcsicmp(pwVar6,L"IpOverUsb"), iVar4 == 0)) {
            *param_1 = *param_1 | 4;
          }
          else if (((*param_1 & 8) == 0) && (iVar4 = _wcsicmp(pwVar6,L"VidStream"), iVar4 == 0)) {
            *param_1 = *param_1 | 8;
          }
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (psVar2[uVar7 + lVar5] != 0);
          uVar7 = (ulonglong)(uint)((int)uVar7 + 1 + (int)lVar5);
          sVar1 = psVar2[uVar7];
        }
      }
      if (psVar2 != (short *)0x0) {
        ExFreePoolWithTag(psVar2,0);
      }
    }
    ExFreePoolWithTag(_Dst,0);
  }
  if (local_res18 != 0) {
    ZwClose();
  }
  return iVar3;
}



===== CheckUSBFnIncludeDefaultCfg @ 140021574 =====

bool CheckUSBFnIncludeDefaultCfg(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  int local_res8 [2];
  longlong local_res10;
  
  local_res10 = 0;
  local_res8[0] = 0;
  iVar1 = MyRegOpenKeyForRead(param_1,
                              L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Default"
                              ,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021712;
    uVar3 = 0x14;
  }
  else {
    iVar1 = MyRegQueryUlong(local_res10,L"IncludeDefaultCfg",local_res8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x15,
                          &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar1);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x16,
                        &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)local_res8[0]);
    }
    lVar2 = local_res10;
    ZwClose();
    local_res10 = 0;
    iVar1 = MyRegOpenKeyForRead(lVar2,
                                L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN",
                                &local_res10);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021712;
      uVar3 = 0x17;
    }
    else {
      iVar1 = MyRegQueryUlong(local_res10,L"IncludeDefaultCfg",local_res8);
      if (-1 < iVar1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                            &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)local_res8[0]);
        }
        goto LAB_140021712;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021712;
      uVar3 = 0x18;
    }
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar3,
                    &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar1);
LAB_140021712:
  if (local_res10 != 0) {
    ZwClose();
  }
  return local_res8[0] != 0;
}



===== GetPersistedKeyPath @ 140021748 =====

int GetPersistedKeyPath(longlong *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  iVar1 = RtlGetPersistedStateLocation
                    (L"USB",0,L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USB",0,0,0,
                     local_res10);
  if (iVar1 == -0x7ffffffb) {
    uVar3 = (ulonglong)local_res10[0];
    lVar2 = ExAllocatePool2(0x40,uVar3,0x55445246);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar3,1,0xb,
                           &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)local_res10[0],
                           0x9a);
      }
    }
    else {
      iVar1 = RtlGetPersistedStateLocation
                        (L"USB",0,L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USB",0,
                         lVar2,local_res10[0],0);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                            &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar1);
        }
        ExFreePoolWithTag(lVar2,0);
      }
      else {
        *param_1 = lVar2;
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                      &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== ReadManifestAssignedValue @ 1400218f4 =====

void ReadManifestAssignedValue(undefined4 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  *param_1 = 0;
  iVar1 = MyRegOpenKeyForRead(param_1,
                              L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USB",
                              local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400219cd;
    uVar2 = 0x11;
  }
  else {
    iVar1 = MyRegQueryUlong(local_res8[0],L"DualRoleFeatures",param_1);
    if (-1 < iVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x13,
                          &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)*param_1);
      }
      goto LAB_1400219cd;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400219cd;
    uVar2 = 0x12;
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                    &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar1);
LAB_1400219cd:
  if (local_res8[0] != 0) {
    ZwClose();
  }
  return;
}



===== ReadUSBFnFeaturesFromCurrentConfiguration @ 1400219f0 =====

int ReadUSBFnFeaturesFromCurrentConfiguration(uint *param_1,char param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t **ppwVar4;
  undefined2 uVar5;
  longlong local_res18;
  wchar_t *local_res20;
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res18 = 0;
  local_res20 = (wchar_t *)0x0;
  pwVar3 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Default";
  if (param_2 == '\0') {
    pwVar3 = L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN";
  }
  iVar2 = MyRegOpenKeyForRead(param_1,pwVar3,&local_res18);
  if (iVar2 < 0) {
    if (param_2 == '\x01') {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021b52;
      uVar5 = 0x1d;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021b52;
      uVar5 = 0x1e;
    }
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar5,
                      &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar2);
  }
  else {
    ppwVar4 = &local_res20;
    iVar2 = MyRegQueryString(local_res18,L"CurrentConfiguration",(longlong *)ppwVar4);
    pwVar1 = local_res20;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,ppwVar4,0x1f,
                           in_stack_ffffffffffffffc8,pwVar3,(char)iVar2);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      ZwClose(local_res18);
      local_res18 = 0;
      iVar2 = CheckUSBFnConfiguration(param_1,pwVar1);
    }
    if (pwVar1 != (wchar_t *)0x0) {
      ExFreePoolWithTag(pwVar1,0);
    }
  }
LAB_140021b52:
  if (local_res18 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== UsbDualRoleFeaturesMarkUcmPresence @ 140021b80 =====

int UsbDualRoleFeaturesMarkUcmPresence(void)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined2 uVar4;
  longlong local_res8;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar5;
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
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  local_res10 = 0;
  local_res8 = 0;
  iVar3 = GetPersistedKeyPath(&local_res8);
  lVar1 = local_res8;
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021d15;
    uVar4 = 0x2a;
  }
  else {
    local_1c = 0;
    local_34 = 0;
    local_48 = 0;
    uStack_40 = 0;
    RtlInitUnicodeString(&local_48,local_res8);
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar3 = ZwOpenKey(&local_res10,0x2001f,&local_38);
    lVar2 = local_res10;
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021d15;
      uVar4 = 0x2b;
    }
    else {
      local_res8 = CONCAT44(local_res8._4_4_,1);
      local_48 = 0;
      uStack_40 = 0;
      RtlInitUnicodeString(&local_48,L"UcmIsPresent");
      iVar3 = ZwSetValueKey(lVar2,&local_48,0,4,&local_res8,CONCAT44(uVar5,4));
      if (-1 < iVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_140021d15;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021d15;
      uVar4 = 0x2c;
    }
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                    &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar3);
LAB_140021d15:
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  return iVar3;
}



===== UsbDualRoleFeaturesQueryLocalMachine @ 140021d5c =====

void UsbDualRoleFeaturesQueryLocalMachine(uint *param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  bool bVar3;
  int iVar4;
  longlong *plVar5;
  uint *puVar6;
  wchar_t **ppwVar7;
  byte bVar8;
  ulonglong *puVar9;
  undefined2 uVar10;
  ulonglong local_res8;
  longlong local_res10;
  wchar_t *local_res18 [2];
  undefined *in_stack_ffffffffffffffa8;
  
  local_res8 = 0;
  local_res10 = 0;
  plVar5 = &local_res10;
  iVar4 = GetPersistedKeyPath(plVar5);
  lVar1 = local_res10;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0xd;
LAB_140021db4:
      bVar8 = 2;
LAB_140021db6:
      in_stack_ffffffffffffffa8 = &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids;
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar8,1,uVar10,
                        &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar4);
    }
  }
  else {
    iVar4 = MyRegOpenKeyForRead(plVar5,local_res10,&local_res8);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar10 = 0xe;
        goto LAB_140021db4;
      }
    }
    else {
      iVar4 = MyRegQueryUlong(local_res8,L"DualRoleFeaturesTestOverride",param_1);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0xf;
          bVar8 = 4;
          goto LAB_140021db6;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffffa8 = &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids;
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x10,
                          &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)*param_1);
      }
    }
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1);
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  if (iVar4 < 0) {
    puVar6 = param_1;
    ReadManifestAssignedValue(param_1);
    *param_1 = *param_1 & 0xfffffff1;
    bVar3 = CheckUSBFnIncludeDefaultCfg(puVar6);
    if (bVar3) {
      CheckUSBFnConfiguration(param_1,L"Default");
    }
    iVar4 = ReadUSBFnFeaturesFromCurrentConfiguration(param_1,'\0');
    if (iVar4 < 0) {
      ReadUSBFnFeaturesFromCurrentConfiguration(param_1,'\x01');
    }
  }
  local_res10 = 0;
  ppwVar7 = local_res18;
  local_res18[0] = (wchar_t *)0x0;
  local_res8 = local_res8 & 0xffffffff00000000;
  iVar4 = GetPersistedKeyPath((longlong *)ppwVar7);
  pwVar2 = local_res18[0];
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 0x21;
      bVar8 = 2;
LAB_140021f09:
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar8,1,uVar10,
                        &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)iVar4);
    }
  }
  else {
    plVar5 = &local_res10;
    iVar4 = MyRegOpenKeyForRead(ppwVar7,local_res18[0],plVar5);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,plVar5,0x22,
                           in_stack_ffffffffffffffa8,pwVar2,(char)iVar4);
      }
    }
    else {
      puVar9 = &local_res8;
      iVar4 = MyRegQueryUlong(local_res10,L"UcmIsPresent",(undefined4 *)puVar9);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x23;
          bVar8 = 3;
          goto LAB_140021f09;
        }
      }
      else {
        iVar4 = (int)local_res8;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x24,
                             in_stack_ffffffffffffffa8,pwVar2,(char)local_res8);
        }
        *param_1 = *param_1 & 0x7fffffff | -(uint)(iVar4 != 0) & 0x80000000;
      }
    }
  }
  if (pwVar2 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar2,0);
  }
  if (local_res10 != 0) {
    ZwClose();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x25,
                      &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,(char)*param_1);
  }
  if ((*param_1 & 1) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022075;
    uVar10 = 0x27;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140022075;
    uVar10 = 0x26;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar10,
                   &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids);
LAB_140022075:
  if ((*param_1 & 2) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar10 = 0x29;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar10 = 0x28;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar10,
                   &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids);
  return;
}



===== WPP_RECORDER_SF_S @ 1400220cc =====

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
               &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,0x2d,pwVar2,lVar1,0);
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
  WppAutoLogTrace(param_1,4,1,&WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,0x2d,
                  in_stack_00000030,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_SS @ 1400221f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SS(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  wchar_t *in_stack_00000030;
  wchar_t *in_stack_00000038;
  
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar6 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar6 = L"NULL";
    }
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000030[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,0x20,pwVar3,lVar2,pwVar6,lVar1,0);
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (in_stack_00000030[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,0x20,
                  in_stack_00000030,lVar4,in_stack_00000038,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 14002238c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,param_4,pwVar2,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_5169c4c8089132207a438b4341aed5b6_Traceguids,param_4,param_6
                  ,lVar3,&param_7,4,0);
  return;
}



===== MyRegOpenKeyForRead @ 1400224f0 =====

void MyRegOpenKeyForRead(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
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
  
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48);
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  ZwOpenKey(param_3,0x20019,&local_38);
  return;
}



===== MyRegQueryString @ 140022570 =====

int MyRegQueryString(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res18[0] = 0;
  *param_3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  lVar3 = ExAllocatePool2(0x40,0x10,0x55445246);
  if (lVar3 == 0) {
LAB_1400225d5:
    iVar2 = -0x3fffff66;
  }
  else {
    iVar2 = ZwQueryValueKey(param_1,&local_28,2,lVar3,0x10,local_res18);
    if ((iVar2 == -0x7ffffffb) || (iVar2 == -0x3fffffdd)) {
      while( true ) {
        uVar1 = *(uint *)(lVar3 + 8);
        lVar4 = ExAllocatePool2(0x40,uVar1,0x55445246);
        *param_3 = lVar4;
        if (lVar4 == 0) break;
        ExFreePoolWithTag(lVar3,0);
        lVar3 = ExAllocatePool2(0x40,local_res18[0],0x55445246);
        if (lVar3 == 0) goto LAB_1400225d5;
        iVar2 = ZwQueryValueKey(param_1,&local_28,2,lVar3,local_res18[0],local_res18);
        if (iVar2 < 0) goto LAB_1400226db;
        if (uVar1 == *(uint *)(lVar3 + 8)) {
          memmove((void *)*param_3,(void *)(lVar3 + 0xc),(ulonglong)uVar1);
          goto LAB_1400226db;
        }
        ExFreePoolWithTag((void *)*param_3,0);
        *param_3 = 0;
      }
      iVar2 = -0x3fffff66;
    }
LAB_1400226db:
    ExFreePoolWithTag(lVar3,0);
    if (-1 < iVar2) {
      return iVar2;
    }
  }
  if (*param_3 != 0) {
    ExFreePoolWithTag(*param_3,0);
    *param_3 = 0;
  }
  return iVar2;
}



===== MyRegQueryUlong @ 14002273c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MyRegQueryUlong(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  RtlInitUnicodeString(&local_40);
  local_50 = local_48;
  local_58 = 0x14;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  if (-1 < iVar1) {
    if ((int)uStack_28 == 4) {
      *param_3 = uStack_28._4_4_;
    }
    else {
      iVar1 = -0x3fffffff;
    }
  }
  return iVar1;
}



===== WnfCreateSecurityDescriptor @ 1400227f4 =====

/* long __cdecl WnfCreateSecurityDescriptor(void * __ptr64 * __ptr64) */

long __cdecl WnfCreateSecurityDescriptor(void **param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  void *pvVar4;
  undefined4 local_res10 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res10[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  pvVar4 = (void *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x150));
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar1 = iVar1 + iVar2 + 0x18;
  lVar3 = ExAllocatePool2(0x100,iVar1,0x586d6355);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = RtlCreateAcl(lVar3,iVar1,2);
    if (-1 < iVar1) {
      iVar1 = RtlAddAccessAllowedAce
                        (lVar3,2,1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x150));
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar3,2,3,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
        if (-1 < iVar1) {
          iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
          if (-1 < iVar1) {
            iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar3,0);
            if (-1 < iVar1) {
              local_res10[0] = RtlLengthSecurityDescriptor(&local_38);
              pvVar4 = (void *)ExAllocatePool2(0x100,local_res10[0],0x586d6355);
              if (pvVar4 == (void *)0x0) {
                iVar1 = -0x3fffff66;
              }
              else {
                iVar1 = RtlAbsoluteToSelfRelativeSD(&local_38,pvVar4,local_res10);
                if (-1 < iVar1) {
                  *param_1 = pvVar4;
                }
              }
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar3,0x586d6355);
    if ((iVar1 < 0) && (pvVar4 != (void *)0x0)) {
      ExFreePoolWithTag(pvVar4,0x586d6355);
    }
  }
  return iVar1;
}



===== PmWnfCallbackInternal @ 140022a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl PmWnfCallbackInternal(struct _EX_WNF_SUBSCRIPTION * __ptr64,struct _WNF_STATE_NAME
   const * __ptr64,unsigned long,unsigned long,struct _WNF_TYPE_ID const * __ptr64,void * __ptr64)
    */

long __cdecl
PmWnfCallbackInternal
          (_EX_WNF_SUBSCRIPTION *param_1,_WNF_STATE_NAME *param_2,ulong param_3,ulong param_4,
          _WNF_TYPE_ID *param_5,void *param_6)

{
  longlong *plVar1;
  void *pvVar2;
  int iVar3;
  undefined4 local_18 [4];
  
  pvVar2 = param_6;
  local_18[0] = 0;
  if (((param_6 != (void *)0x0) && (*(int *)param_6 == 0x53574d50)) &&
     (plVar1 = (longlong *)((longlong)param_6 + 0x18), *plVar1 != 0)) {
    param_6._0_4_ = *(undefined4 *)((longlong)param_6 + 0x20);
    iVar3 = ExQueryWnfStateData(param_1,local_18,*plVar1,&param_6);
    if (-1 < iVar3) {
      (**(code **)((longlong)pvVar2 + 0x28))
                (param_2,local_18[0],*(undefined8 *)((longlong)pvVar2 + 0x30),
                 *(undefined8 *)((longlong)pvVar2 + 0x18),param_6._0_4_);
    }
  }
  return 0;
}



===== PmWnfCreateSecurityDescriptor @ 140022a94 =====

int PmWnfCreateSecurityDescriptor(longlong *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 local_res10 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res10[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar4 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x150));
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar1 = iVar1 + iVar2 + 0x18;
  lVar3 = ExAllocatePool2(0x40,iVar1,0x53574d50);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = RtlCreateAcl(lVar3,iVar1,2);
    if (-1 < iVar1) {
      iVar1 = RtlAddAccessAllowedAce
                        (lVar3,2,1,*(undefined8 *)(*(longlong *)SeExports_exref + 0x150));
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar3,2,3,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
        if (-1 < iVar1) {
          iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
          if (-1 < iVar1) {
            iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar3,0);
            if (-1 < iVar1) {
              local_res10[0] = RtlLengthSecurityDescriptor(&local_38);
              lVar4 = ExAllocatePool2(0x40,local_res10[0],0x53574d50);
              if (lVar4 == 0) {
                iVar1 = -0x3fffff66;
              }
              else {
                iVar1 = RtlAbsoluteToSelfRelativeSD(&local_38,lVar4,local_res10);
                if (-1 < iVar1) {
                  *param_1 = lVar4;
                }
              }
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar3,0x53574d50);
    if ((iVar1 < 0) && (lVar4 != 0)) {
      ExFreePoolWithTag(lVar4,0x53574d50);
    }
  }
  return iVar1;
}



===== PmWnfSubscribeChangeNotification @ 140022ca0 =====

int PmWnfSubscribeChangeNotification
              (undefined8 *param_1,undefined4 param_2,undefined8 param_3,longlong param_4,
              undefined8 param_5,undefined8 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
  if ((param_6 == (undefined8 *)0x0) || (param_4 == 0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x38,0x53574d50);
    if (puVar2 == (undefined4 *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *puVar2 = 0x53574d50;
      *(undefined8 *)(puVar2 + 4) = *param_1;
      *(undefined8 *)(puVar2 + 0xc) = param_5;
      *(longlong *)(puVar2 + 10) = param_4;
      puVar2[8] = param_2;
      lVar3 = ExAllocatePool2(0x40,param_2,0x53574d50);
      *(longlong *)(puVar2 + 6) = lVar3;
      if (lVar3 == 0) {
        iVar1 = -0x3fffff66;
      }
      else {
        iVar1 = ExSubscribeWnfStateChange(puVar2 + 2,param_1,1,0,PmWnfCallbackInternal,puVar2);
        if (-1 < iVar1) {
          *param_6 = puVar2;
          return iVar1;
        }
      }
      if (*(longlong *)(puVar2 + 6) != 0) {
        ExFreePoolWithTag(*(longlong *)(puVar2 + 6),0x53574d50);
        *(undefined8 *)(puVar2 + 6) = 0;
      }
      ExFreePoolWithTag(puVar2,0x53574d50);
    }
  }
  return iVar1;
}



===== PmWnfUnsubscribeChangeNotification @ 140022dd4 =====

undefined8 PmWnfUnsubscribeChangeNotification(undefined8 *param_1)

{
  int *piVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if ((param_1 == (undefined8 *)0x0) || (piVar1 = (int *)*param_1, piVar1 == (int *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else if (*piVar1 == 0x53574d50) {
    ExUnsubscribeWnfStateChange(*(undefined8 *)(piVar1 + 2));
    if (*(longlong *)(piVar1 + 6) != 0) {
      ExFreePoolWithTag(*(longlong *)(piVar1 + 6),0x53574d50);
      piVar1[6] = 0;
      piVar1[7] = 0;
    }
    ExFreePoolWithTag(piVar1,0x53574d50);
    *param_1 = 0;
  }
  else {
    uVar2 = 0xc0000008;
  }
  return uVar2;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140022e6c =====

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
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_14002a708 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14002e040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14002e008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14002e078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140022f20 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  uint in_stack_ffffffffffffffec;
  
  MicrosoftTelemetryAssertTriggeredWorker
            (unaff_retaddr,1,"PolicyManagerKm",param_2,(ulonglong)in_stack_ffffffffffffffec << 0x20,
             param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140022f54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014002310f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5,char *param_6)

{
  code *pcVar1;
  longlong lVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined1 *puVar14;
  int iVar15;
  undefined1 auStack_268 [8];
  undefined1 auStack_260 [116];
  undefined4 local_1ec;
  undefined1 local_1e8 [32];
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 *local_1b8;
  undefined8 local_1b0;
  undefined1 *local_1a8;
  undefined8 local_1a0;
  undefined1 *local_198;
  undefined8 local_190;
  char *local_188;
  int local_180;
  undefined4 local_17c;
  undefined1 *local_178;
  undefined8 local_170;
  undefined1 *local_168;
  undefined8 local_160;
  undefined1 *local_158;
  undefined8 local_150;
  char *local_148;
  undefined8 local_140;
  undefined1 *local_138;
  undefined8 local_130;
  undefined1 *local_128;
  undefined8 local_120;
  char *local_118;
  int local_110;
  undefined4 local_10c;
  undefined1 local_108 [32];
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  undefined1 *local_b8;
  undefined8 local_b0;
  char *local_a8;
  int local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  puVar14 = auStack_268;
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  iVar15 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1400235a8;
  local_1ec = param_4;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar14 = auStack_268;
  for (plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList; plVar9 = (longlong *)*plVar9
      ) {
    plVar8 = plVar9 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar8 == param_1) goto LAB_140023095;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar13 = _DAT_fffff78000000320;
  puVar14 = auStack_268;
  if (plVar8 != (longlong *)0x0) {
    *plVar8 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar14 = auStack_268;
    plVar8[2] = 0;
    *(undefined4 *)(plVar8 + 3) = 0;
    puVar12 = &g_MicrosoftTelemetryAssertsTriggeredList;
    plVar8[1] = (longlong)((ulonglong)uVar6 * lVar13) / 10000 + -0xea61;
    plVar9 = plVar8 + 4;
    plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar11 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar9 = (longlong *)(*pcVar1)();
      puVar14 = auStack_260;
    }
    *plVar9 = (longlong)plVar11;
    plVar9[1] = (longlong)puVar12;
    plVar11[1] = (longlong)plVar9;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar9;
LAB_140023095:
    *(int *)(plVar8 + 2) = (int)plVar8[2] + 1;
    *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
    lVar13 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar14 + -8) = 0x1400230a6;
    uVar6 = KeQueryTimeIncrement();
    lVar13 = (longlong)((ulonglong)uVar6 * lVar13) / 10000;
    if (60000 < (ulonglong)(lVar13 - plVar8[1])) {
      if (((IMAGE_DOS_HEADER *)0x13fffffff < param_1) && (param_1 < (IMAGE_DOS_HEADER *)0x140036001)
         ) {
        iVar15 = (int)param_1 + -0x40000000;
      }
      plVar8[1] = lVar13;
      *(int *)(puVar14 + 0x74) = (int)plVar8[2];
      lVar2 = plVar8[3];
      *(undefined4 *)(puVar14 + 0x78) = *(undefined4 *)((longlong)plVar8 + 0x14);
      *(undefined8 *)(puVar14 + -8) = 0x140023156;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar13 >> 8),uVar3));
      lVar13 = -1;
      if (((5 < DAT_14002e040) && ((_DAT_14002e050 & 0x400000000000) != 0)) &&
         ((DAT_14002e058 & 0x400000000000) == DAT_14002e058)) {
        local_1c8 = puVar14 + 0x50;
        *(undefined4 *)(puVar14 + 0x50) = 10;
        local_1b8 = puVar14 + 0x54;
        local_1a8 = puVar14 + 0x58;
        local_198 = puVar14 + 0x5c;
        local_1c0 = 4;
        *(int *)(puVar14 + 0x54) = iVar15;
        local_1b0 = 4;
        *(dword *)(puVar14 + 0x58) = 0xdef844f9;
        local_1a0 = 4;
        *(dword *)(puVar14 + 0x5c) = 0x36000;
        local_190 = 4;
        local_188 = g_ModuleName;
        if (g_ModuleName == (char *)0x0) {
          local_188 = "<unknown>";
        }
        lVar10 = -1;
        do {
          lVar10 = lVar10 + 1;
        } while (local_188[lVar10] != '\0');
        local_180 = (int)lVar10 + 1;
        *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x74);
        local_178 = puVar14 + 0x60;
        *(undefined4 *)(puVar14 + 100) = *(undefined4 *)(puVar14 + 0x78);
        local_168 = puVar14 + 100;
        local_17c = 0;
        local_170 = 4;
        local_160 = 4;
        *(undefined8 *)(puVar14 + -8) = 0x140023264;
        bVar4 = KeGetCurrentIrql();
        *(uint *)(puVar14 + 0x68) = (uint)bVar4;
        local_158 = puVar14 + 0x68;
        local_148 = "PolicyManagerKm";
        *(undefined4 *)(puVar14 + 0x6c) = *(undefined4 *)(puVar14 + 0x7c);
        local_138 = puVar14 + 0x6c;
        local_128 = puVar14 + 0x70;
        if (param_6 == (char *)0x0) {
          param_6 = "<unknown>";
        }
        local_150 = 4;
        local_140 = 0x10;
        local_130 = 4;
        *(undefined4 *)(puVar14 + 0x70) = 0;
        local_120 = 4;
        if (param_6 == (char *)0x0) {
          param_6 = "";
          local_110 = 1;
        }
        else {
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (param_6[lVar10] != '\0');
          local_110 = (int)lVar10 + 1;
        }
        local_10c = 0;
        *(undefined1 **)(puVar14 + 0x28) = local_1e8;
        *(undefined4 *)(puVar14 + 0x20) = 0xe;
        *(undefined8 *)(puVar14 + -8) = 0x140023329;
        local_118 = param_6;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x14002e040,&DAT_140027d95,0,0,*(undefined4 *)(puVar14 + 0x20),
                   *(undefined8 **)(puVar14 + 0x28));
      }
      if ((DAT_14002e078 == 0) || ((int)lVar2 != 0)) goto LAB_1400235a8;
      *(undefined8 *)(puVar14 + -8) = 0x140023345;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_1400235a8;
      *(undefined4 *)(puVar14 + 0x40) = 0;
      *(undefined8 *)(puVar14 + 0x38) = 0;
      *(undefined8 *)(puVar14 + 0x30) = 0;
      *(undefined8 *)(puVar14 + 0x28) = 0x36000;
      *(undefined8 *)(puVar14 + 0x20) = 0xdef844f9;
      *(undefined8 *)(puVar14 + -8) = 0x14002338f;
      iVar7 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (((5 < DAT_14002e040) && ((_DAT_14002e050 & 0x400000000000) != 0)) &&
         ((DAT_14002e058 & 0x400000000000) == DAT_14002e058)) {
        local_e8 = puVar14 + 0x70;
        *(undefined4 *)(puVar14 + 0x70) = 10;
        local_d8 = puVar14 + 0x6c;
        local_e0 = 4;
        local_c8 = puVar14 + 0x68;
        local_b8 = puVar14 + 100;
        *(int *)(puVar14 + 0x6c) = iVar15;
        local_d0 = 4;
        *(dword *)(puVar14 + 0x68) = 0xdef844f9;
        local_c0 = 4;
        *(dword *)(puVar14 + 100) = 0x36000;
        local_b0 = 4;
        local_a8 = g_ModuleName;
        if (g_ModuleName == (char *)0x0) {
          local_a8 = "<unknown>";
        }
        do {
          lVar13 = lVar13 + 1;
        } while (local_a8[lVar13] != '\0');
        *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x74);
        local_a0 = (int)lVar13 + 1;
        local_98 = puVar14 + 0x60;
        local_9c = 0;
        *(undefined4 *)(puVar14 + 0x5c) = *(undefined4 *)(puVar14 + 0x78);
        local_88 = puVar14 + 0x5c;
        local_78 = puVar14 + 0x58;
        local_68 = "PolicyManagerKm";
        *(undefined4 *)(puVar14 + 0x54) = *(undefined4 *)(puVar14 + 0x7c);
        local_58 = puVar14 + 0x54;
        local_48 = puVar14 + 0x50;
        *(undefined4 *)(puVar14 + 0x50) = 0;
        *(undefined1 **)(puVar14 + 0x28) = local_108;
        *(undefined4 *)(puVar14 + 0x20) = 0xd;
        local_90 = 4;
        local_80 = 4;
        *(int *)(puVar14 + 0x58) = iVar7;
        local_70 = 4;
        local_60 = 0x10;
        local_50 = 4;
        local_40 = 4;
        *(undefined8 *)(puVar14 + -8) = 0x14002354f;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x14002e040,&DAT_140027e3f,0,0,*(undefined4 *)(puVar14 + 0x20),
                   *(undefined8 **)(puVar14 + 0x28));
      }
      if (iVar7 != 0) goto LAB_1400235a8;
      *(undefined8 *)(puVar14 + -8) = 0x140023561;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar9[-4] == param_1) {
            *(int *)(plVar9 + -1) = (int)plVar9[-1] + 1;
            break;
          }
          plVar9 = (longlong *)*plVar9;
        } while ((longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar14 + -8) = 0x1400235a3;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_1400235a8:
  *(undefined8 *)(puVar14 + -8) = 0x1400235b7;
  return;
}



===== __GSHandlerCheck @ 1400235e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14002360c =====

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



===== __GSHandlerCheck_SEH @ 140023674 =====

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



===== __cpu_features_init @ 140023710 =====

/* WARNING: Removing unreachable block (ram,0x00014002377a) */
/* WARNING: Removing unreachable block (ram,0x000140023729) */
/* WARNING: Removing unreachable block (ram,0x00014002371a) */

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



===== __security_check_cookie @ 1400237e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140023820 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140023850 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140023850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140023880 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140023900 =====

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



===== memset @ 140023c00 =====

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



===== __memset_repmovs @ 140023d40 =====

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



===== __memset_query @ 140023dc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140023e40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140023f80 =====

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



===== __memset_spec_plain @ 140024000 =====

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



===== CheckTestOverrideLoadUsbHostForPartnerUfpNoUsbData @ 14002f008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl CheckTestOverrideLoadUsbHostForPartnerUfpNoUsbData(void) */

uchar __cdecl CheckTestOverrideLoadUsbHostForPartnerUfpNoUsbData(void)

{
  int iVar1;
  undefined2 uVar2;
  bool bVar3;
  int local_res8 [2];
  longlong local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  bVar3 = false;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"TestOverrideLoadUsbHostForPartnerUfpNoUsbData");
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f189;
    uVar2 = 0x77;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10[0],&local_18,local_res8);
    if (-1 < iVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x7a,
                          &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)local_res8[0]);
      }
      bVar3 = local_res8[0] != 0;
      goto LAB_14002f189;
    }
    if (iVar1 == -0x3fffffcc) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x78,
                         &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids);
      }
      goto LAB_14002f189;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002f189;
    uVar2 = 0x79;
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                    &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)iVar1);
LAB_14002f189:
  if (local_res10[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return bVar3;
}



===== CheckTestSigning @ 14002f1bc =====

/* unsigned char __cdecl CheckTestSigning(void) */

uchar __cdecl CheckTestSigning(void)

{
  int iVar1;
  byte bVar2;
  undefined8 local_res8;
  
  bVar2 = 0;
  local_res8 = 8;
  iVar1 = ZwQuerySystemInformation(0x67,&local_res8,8,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return '\0';
    }
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x75,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,(char)iVar1);
  }
  else {
    bVar2 = local_res8._4_1_ >> 1 & 1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x76,
                      &WPP_025dd88da4b83a120e9ac9305b3f20a7_Traceguids,bVar2);
  }
  return bVar2;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 14002f284 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x14002f2e7;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14002f307;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14002f31b;
  return iVar6;
}



===== WppCleanupKm @ 14002f334 =====

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



===== WppInitKm @ 14002f3e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  
  if ((code **)WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = (undefined *)&WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        puVar2[7] = 0;
        (*pcVar1)(puVar2[1],0,WppClassicProviderCallback,puVar2,puVar2 + 7);
        puVar2 = (undefined8 *)puVar2[2];
      } while (puVar2 != (undefined8 *)0x0);
    }
    else if (WPPTraceSuite == 2) {
      WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 14002f4c0 =====

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



===== WppTraceCallback @ 14002f610 =====

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



===== _tlgEnableCallback @ 14002f8a0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14002f91c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_UFFPPUWOUD__private_descriptor;
  ppuVar2 = &Feature_UFFPPUWOUD__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014002f957;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14002f9d1:
  while( true ) {
    if (&UNK_140029aff < ppuVar3) {
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
      if (&UNK_140029aff < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014002f957:
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
      if (&UNK_140029aff < ppuVar2) goto LAB_14002f9d1;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14002f9d1;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14002fa0c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14002faa8;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14002faa8;
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
LAB_14002faa8:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14002fb10 =====

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
      for (ppuVar2 = &Feature_UFFPPUWOUD__private_descriptor;
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
              if (&UNK_140029aff < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14002fb90 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14002fbb0 =====

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
  for (ppuVar3 = &Feature_UFFPPUWOUD__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14002fcad;
  }
LAB_14002fcb6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14002fcad:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14002fcb6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14002fc7e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14002fc7e;
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
    if (&UNK_140029aff < ppuVar3) goto LAB_14002fcb6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14002fcad;
}



===== AcpiEnumChildren @ 14002fcdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEnumChildren(struct WDFDEVICE__ * __ptr64,struct WDFMEMORY__ * __ptr64 *
   __ptr64) */

long __cdecl AcpiEnumChildren(WDFDEVICE__ *param_1,WDFMEMORY__ **param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  WDFMEMORY__ *local_res8;
  undefined8 *local_res18;
  longlong local_res20;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  int *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  WDFDEVICE__ *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  WDFMEMORY__ *pWStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong lStack_48;
  undefined8 local_40;
  
  local_res18 = (undefined8 *)0x0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lStack_48 = 0;
  local_a8 = (int *)0x0;
  local_68 = 0;
  pWStack_60 = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  local_res20 = 0;
  local_res8 = (WDFMEMORY__ *)0x0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  puVar4 = &local_a0;
  uVar1 = *(undefined8 *)(lVar3 + 0x40);
  uVar6 = 0x200;
  local_70 = 0;
  local_90 = 0;
  uStack_88 = 0x100000001;
  uStack_98 = 0;
  local_a0 = 0x38;
  uStack_78 = 0;
  uVar9 = 0x10;
  local_80 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,puVar4,0x200,0,0x10,&local_res20,&local_res18);
  uVar11 = SUB81(param_1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,uVar6,0xb,uVar9,uVar11,
                         0x10);
    }
    goto LAB_1400300cd;
  }
  uVar5 = 0x14;
  uVar8 = 0;
  *local_res18 = 0;
  local_res18[1] = 0;
  *(undefined4 *)local_res18 = 0x48696541;
  *(undefined4 *)((longlong)local_res18 + 4) = 1;
  lStack_48 = local_res20;
  local_50 = 3;
  local_40 = 0;
  while( true ) {
    puVar4 = &local_a0;
    local_70 = 0;
    local_90 = 0;
    uVar6 = 0x200;
    uStack_98 = 0;
    local_a0 = 0x38;
    uStack_78 = 0;
    uStack_88 = 0x100000001;
    uVar10 = uVar5;
    local_80 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,puVar4,0x200,0,uVar5,&local_res8,&local_a8);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,uVar6,0xc,uVar10,uVar11
                           ,(char)uVar5);
      }
      goto LAB_1400300cd;
    }
    pWStack_60 = local_res8;
    local_68 = 3;
    local_58 = 0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar1,0,0x32c020,&local_50,&local_68,0,0);
    if (-1 < iVar2) break;
    if (iVar2 != -0x7ffffffb) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xf,
                           &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar11,(char)iVar2);
      }
      goto LAB_1400300cd;
    }
    if (*local_a8 != 0x47696541) {
      iVar2 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x10;
        goto LAB_140030034;
      }
      goto LAB_1400300cd;
    }
    uVar5 = (ulonglong)(uint)local_a8[1];
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res8);
    uVar8 = uVar8 + 1;
    local_res8 = (WDFMEMORY__ *)0x0;
    if (1 < uVar8) goto LAB_1400300cd;
  }
  if (*local_a8 == 0x47696541) {
    if (local_a8[1] != 0) {
      *param_2 = local_res8;
      local_res8 = (WDFMEMORY__ *)0x0;
      goto LAB_1400300cd;
    }
    iVar2 = -0x3febfff1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400300cd;
    uVar7 = 0xe;
  }
  else {
    iVar2 = -0x3febfff1;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400300cd;
    uVar7 = 0xd;
  }
LAB_140030034:
  iVar2 = -0x3febfff1;
  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar7,
                    &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar11);
LAB_1400300cd:
  if (local_res20 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_res20 = 0;
  }
  if (local_res8 != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    local_res8 = (WDFMEMORY__ *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x11,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar2;
}



===== AcpiEvaluateAdr @ 140030174 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEvaluateAdr(struct WDFDEVICE__ * __ptr64,char const * __ptr64,unsigned long *
   __ptr64) */

long __cdecl AcpiEvaluateAdr(WDFDEVICE__ *param_1,char *param_2,ulong *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  WDFMEMORY__ *pWVar4;
  undefined2 uVar5;
  undefined1 auStackY_1a8 [32];
  undefined *in_stack_fffffffffffffe78;
  undefined1 uVar6;
  WDFMEMORY__ *local_158 [2];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_158[0] = (WDFMEMORY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffe78 = &WPP_c6a2c65348053a21207e265485f83edf_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1a,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  if (param_3 == (ulong *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    uVar2 = RtlStringCchPrintfA(local_148,0x100,"%s._ADR",param_2);
    iVar1 = (int)uVar2;
    uVar6 = SUB81(param_1,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1b,
                         &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar6,(char)uVar2);
    }
    else {
      iVar1 = AcpiEvaluateMethod(param_1,local_148,local_158);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar5 = 0x1c;
      }
      else {
        uVar2 = 0;
        pWVar4 = local_158[0];
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals);
        if (*(int *)(lVar3 + 8) == 0) {
          iVar1 = -0x3febfff1;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3febfff1;
          }
          uVar5 = 0x1d;
        }
        else {
          if (*(short *)(lVar3 + 0xc) != 0) {
            iVar1 = -0x3febfff1;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return -0x3febfff1;
            }
            WPP_RECORDER_SF_qsHd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar2,0x1e,
                       in_stack_fffffffffffffe78,uVar6,local_148,(char)*(short *)(lVar3 + 0xc));
            goto LAB_14003035f;
          }
          if (3 < *(ushort *)(lVar3 + 0xe)) {
            iVar1 = 0;
            *param_3 = *(ulong *)(lVar3 + 0x10);
            goto LAB_14003035f;
          }
          iVar1 = -0x3ffffff3;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3ffffff3;
          }
          uVar5 = 0x1f;
        }
      }
      WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar5,
                          &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar6,local_148,
                          (char)iVar1);
    }
  }
LAB_14003035f:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x20,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar1;
}



===== AcpiEvaluateDsd @ 1400303bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl AcpiEvaluateDsd(struct WDFDEVICE__ * __ptr64,char const * __ptr64,struct WDFMEMORY__
   * __ptr64 * __ptr64) */

long __cdecl AcpiEvaluateDsd(WDFDEVICE__ *param_1,char *param_2,WDFMEMORY__ **param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_178 [32];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  uVar2 = RtlStringCchPrintfA(local_138,0x100,"%s._DSD",param_2);
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x29,
                       &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,(char)param_1,(char)uVar2);
  }
  else {
    iVar1 = AcpiEvaluateMethod(param_1,local_138,param_3);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2a,
                          &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,(char)param_1,local_138,
                          (char)iVar1);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2b,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar1;
}



===== AcpiEvaluateMethod @ 14003053c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400308dc) */
/* WARNING: Removing unreachable block (ram,0x000140030937) */
/* WARNING: Removing unreachable block (ram,0x0001400308eb) */
/* WARNING: Removing unreachable block (ram,0x000140030904) */
/* WARNING: Removing unreachable block (ram,0x00014003099b) */
/* long __cdecl AcpiEvaluateMethod(struct WDFDEVICE__ * __ptr64,char const * __ptr64,struct
   WDFMEMORY__ * __ptr64 * __ptr64) */

long __cdecl AcpiEvaluateMethod(WDFDEVICE__ *param_1,char *param_2,WDFMEMORY__ **param_3)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  longlong lVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 auStackY_228 [32];
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  WDFDEVICE__ *local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined4 local_158;
  char local_154 [268];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_228;
  lVar7 = 0x100;
  memset(local_154,0,0x100);
  local_190 = 0;
  uStack_188 = 0;
  local_160 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = (WDFDEVICE__ *)0x0;
  uStack_168 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x12,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_UCMCX_CONTEXT_TYPE_INFO_14002a128);
  pcVar5 = local_154;
  uVar1 = *(undefined8 *)(lVar3 + 0x40);
  local_158 = 0x41696541;
  do {
    if ((lVar7 == -0x7ffffefe) || (pcVar5[(longlong)param_2 - (longlong)local_154] == '\0')) break;
    *pcVar5 = pcVar5[(longlong)param_2 - (longlong)local_154];
    pcVar5 = pcVar5 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  pcVar4 = pcVar5 + -1;
  if (lVar7 != 0) {
    pcVar4 = pcVar5;
  }
  *pcVar4 = '\0';
  if (lVar7 == 0) {
    iVar2 = -0x7ffffffb;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x13,
                         &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,(char)param_1,5);
    }
  }
  else {
    cVar6 = '\x01';
    uVar9 = 0x200;
    while( true ) {
      local_160 = 0;
      local_180 = 0;
      uStack_188 = 0;
      uStack_168 = 0;
      local_190 = 0x38;
      uStack_178 = 0x100000001;
      local_170 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))(WdfDriverGlobals,&local_190,0x200,0);
      if (iVar2 < 0) break;
      memset((void *)0x0,0,(ulonglong)uVar9);
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))(WdfDriverGlobals,uVar1,0);
      if (-1 < iVar2) {
        iVar2 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x17;
          iVar2 = -0x3fffffff;
LAB_1400308ae:
          WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar8,
                             &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,(char)param_1,
                             (char)iVar2);
        }
        goto LAB_140030991;
      }
      if (iVar2 != -0x7ffffffb) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x16;
          goto LAB_1400308ae;
        }
        goto LAB_140030991;
      }
      (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,0);
      if (cVar6 == '\x02') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x7ffffffb;
        }
        WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        goto LAB_140030991;
      }
      cVar6 = cVar6 + '\x01';
      uVar9 = uRam0000000000000004;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
LAB_140030991:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x19,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar2;
}



===== AcpiEvaluatePld @ 140030a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiEvaluatePld(struct WDFDEVICE__ * __ptr64,char const * __ptr64,struct
   _ACPI_PLD_BUFFER * __ptr64) */

long __cdecl AcpiEvaluatePld(WDFDEVICE__ *param_1,char *param_2,_ACPI_PLD_BUFFER *param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  WDFMEMORY__ *pWVar4;
  undefined2 uVar5;
  undefined1 auStackY_1a8 [32];
  undefined *in_stack_fffffffffffffe78;
  undefined1 uVar6;
  WDFMEMORY__ *local_158 [2];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffe78 = &WPP_c6a2c65348053a21207e265485f83edf_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x21,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  local_158[0] = (WDFMEMORY__ *)0x0;
  uVar2 = RtlStringCchPrintfA(local_148,0x100,"%s._PLD",param_2);
  iVar1 = (int)uVar2;
  uVar6 = SUB81(param_1,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x22,
                       &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar6,(char)uVar2);
    goto LAB_140030c44;
  }
  iVar1 = AcpiEvaluateMethod(param_1,local_148,local_158);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x23;
LAB_140030b20:
      WPP_RECORDER_SF_qsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar5,
                          &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar6,local_148,
                          (char)iVar1);
    }
  }
  else {
    uVar2 = 0;
    pWVar4 = local_158[0];
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals);
    if (*(int *)(lVar3 + 8) == 0) {
      iVar1 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x24;
        iVar1 = -0x3febfff1;
        goto LAB_140030b20;
      }
    }
    else if (*(short *)(lVar3 + 0xc) == 2) {
      if (*(ushort *)(lVar3 + 0xe) < 0x10) {
        iVar1 = -0x3febfff1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qsPPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        uVar2 = *(undefined8 *)(lVar3 + 0x18);
        *(undefined8 *)param_3 = *(undefined8 *)(lVar3 + 0x10);
        *(undefined8 *)&param_3->field_0x8 = uVar2;
      }
    }
    else {
      iVar1 = -0x3febfff1;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qsHd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,uVar2,0x25,
                   in_stack_fffffffffffffe78,uVar6,local_148,(char)*(short *)(lVar3 + 0xc));
      }
    }
  }
  if (local_158[0] != (WDFMEMORY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_158[0]);
  }
LAB_140030c44:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x27,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar1;
}



===== AcpiParseGuid @ 140030ca4 =====

/* long __cdecl AcpiParseGuid(struct _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64,void *
   __ptr64,unsigned long) */

long __cdecl AcpiParseGuid(_ACPI_METHOD_ARGUMENT_V1 *param_1,void *param_2,ulong param_3)

{
  long lVar1;
  
  if (*(short *)(param_1 + 2) == 0x10) {
    memmove(param_2,param_1 + 4,0x10);
    lVar1 = 0;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2c,
                         &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,0x10,
                         (char)*(short *)(param_1 + 2));
    }
    lVar1 = -0x3febfff8;
  }
  return lVar1;
}



===== AcpiParsePdAlternateModes @ 140030d1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiParsePdAlternateModes(struct WDFDEVICE__ * __ptr64,struct
   _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64,struct WDFMEMORY__ * __ptr64 * __ptr64,unsigned
   long * __ptr64) */

long __cdecl
AcpiParsePdAlternateModes
          (WDFDEVICE__ *param_1,_ACPI_METHOD_ARGUMENT_V1 *param_2,WDFMEMORY__ **param_3,
          ulong *param_4)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var5;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var6;
  undefined2 uVar7;
  longlong local_res10;
  undefined1 uVar8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  local_res10 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (WDFDEVICE__ *)0x0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x33,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  uVar8 = SUB81(param_1,0);
  if (*(short *)param_2 == 3) {
    p_Var6 = param_2 + 4;
    uVar4 = 0;
    p_Var5 = p_Var6;
    do {
      uVar3 = 4;
      if (3 < *(ushort *)(param_2 + 2)) {
        uVar3 = (ulonglong)*(ushort *)(param_2 + 2);
      }
      if (param_2 + uVar3 + 4 <= p_Var5) {
        if ((uVar4 == 0) || ((uVar4 & 1) != 0)) {
          iVar2 = -0x3febfff1;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3febfff1;
          }
          uVar7 = 0x37;
LAB_140030fe1:
          WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar7,
                              &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar8,(char)uVar4,
                              (char)iVar2);
        }
        else {
          *param_4 = uVar4 >> 1;
          local_68 = CONCAT44(local_68._4_4_,0x38);
          uStack_50 = 0x100000001;
          local_48 = param_1;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x600))
                            (WdfDriverGlobals,&local_68,0x200,0,(ulonglong)(uVar4 >> 1) << 3,param_3
                             ,&local_res10);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar2;
            }
            WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x38,
                                &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar8,
                                (char)*param_4,(char)iVar2);
          }
          else {
            uVar4 = 0;
            bVar1 = false;
            while( true ) {
              uVar3 = (ulonglong)*(ushort *)(param_2 + 2);
              if (*(ushort *)(param_2 + 2) < 4) {
                uVar3 = 4;
              }
              if (param_2 + uVar3 + 4 <= p_Var6) break;
              if (bVar1) {
                *(undefined4 *)(local_res10 + 4 + (ulonglong)(uVar4 >> 1) * 8) =
                     *(undefined4 *)(p_Var6 + 4);
              }
              else {
                *(short *)(local_res10 + (ulonglong)(uVar4 >> 1) * 8) = *(short *)(p_Var6 + 4);
              }
              uVar3 = (ulonglong)*(ushort *)(p_Var6 + 2);
              if (*(ushort *)(p_Var6 + 2) < 4) {
                uVar3 = 4;
              }
              p_Var6 = p_Var6 + uVar3 + 4;
              uVar4 = uVar4 + 1;
              bVar1 = (bool)(bVar1 ^ 1);
            }
            iVar2 = 0;
          }
        }
        goto LAB_140031016;
      }
      if (*(short *)p_Var5 != 0) {
        iVar2 = -0x3febfff8;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3febfff8;
        }
        uVar7 = 0x35;
        goto LAB_140030fe1;
      }
      if (((uVar4 & 1) == 0) && (0xffff < *(uint *)(p_Var5 + 4))) goto LAB_140030e5b;
      uVar3 = (ulonglong)*(ushort *)(p_Var5 + 2);
      if (*(ushort *)(p_Var5 + 2) < 4) {
        uVar3 = 4;
      }
      p_Var5 = p_Var5 + uVar3 + 4;
      uVar4 = uVar4 + 1;
    } while( true );
  }
  iVar2 = -0x3febfff8;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return -0x3febfff8;
  }
  WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x34,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar8,8);
LAB_140031016:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x39,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar2;
LAB_140030e5b:
  iVar2 = -0x3febfff8;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return -0x3febfff8;
  }
  WPP_RECORDER_SF_qLDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  goto LAB_140031016;
}



===== AcpiParsePdPdos @ 140031074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiParsePdPdos(struct WDFDEVICE__ * __ptr64,struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,struct WDFMEMORY__ * __ptr64 * __ptr64,unsigned long * __ptr64) */

long __cdecl
AcpiParsePdPdos(WDFDEVICE__ *param_1,_ACPI_METHOD_ARGUMENT_V1 *param_2,WDFMEMORY__ **param_3,
               ulong *param_4)

{
  int iVar1;
  ulonglong uVar2;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var3;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var4;
  uint uVar5;
  undefined2 uVar6;
  longlong local_res10;
  undefined1 uVar7;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  WDFDEVICE__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_38 = 0;
  local_res10 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (WDFDEVICE__ *)0x0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2d,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  uVar7 = SUB81(param_1,0);
  if (*(short *)param_2 == 3) {
    p_Var4 = param_2 + 4;
    uVar5 = 0;
    p_Var3 = p_Var4;
    while( true ) {
      uVar2 = 4;
      if (3 < *(ushort *)(param_2 + 2)) {
        uVar2 = (ulonglong)*(ushort *)(param_2 + 2);
      }
      if (param_2 + uVar2 + 4 <= p_Var3) {
        if (uVar5 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return -0x3febfff8;
          }
          uVar6 = 0x30;
          goto LAB_140031132;
        }
        local_68 = CONCAT44(local_68._4_4_,0x38);
        uStack_50 = 0x100000001;
        local_48 = param_1;
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                          (WdfDriverGlobals,&local_68,0x200,0,(ulonglong)uVar5 << 2,param_3,
                           &local_res10);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x31,
                              &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar7,(char)uVar5,
                              (char)iVar1);
        }
        else {
          *param_4 = uVar5;
          uVar5 = 0;
          while( true ) {
            uVar2 = (ulonglong)*(ushort *)(param_2 + 2);
            if (*(ushort *)(param_2 + 2) < 4) {
              uVar2 = 4;
            }
            if (param_2 + uVar2 + 4 <= p_Var4) break;
            *(undefined4 *)(local_res10 + (ulonglong)uVar5 * 4) = *(undefined4 *)(p_Var4 + 4);
            uVar2 = (ulonglong)*(ushort *)(p_Var4 + 2);
            if (*(ushort *)(p_Var4 + 2) < 4) {
              uVar2 = 4;
            }
            p_Var4 = p_Var4 + uVar2 + 4;
            uVar5 = uVar5 + 1;
          }
          iVar1 = 0;
        }
        goto LAB_140031310;
      }
      if (*(short *)p_Var3 != 0) break;
      uVar2 = (ulonglong)*(ushort *)(p_Var3 + 2);
      if (*(ushort *)(p_Var3 + 2) < 4) {
        uVar2 = 4;
      }
      p_Var3 = p_Var3 + uVar2 + 4;
      uVar5 = uVar5 + 1;
    }
    iVar1 = -0x3febfff8;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3febfff8;
    }
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x2f,
                        &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar7,(char)uVar5,8);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3febfff8;
    }
    uVar6 = 0x2e;
LAB_140031132:
    iVar1 = -0x3febfff8;
    WPP_RECORDER_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar6,
                       &WPP_c6a2c65348053a21207e265485f83edf_Traceguids,uVar7,8);
  }
LAB_140031310:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x32,
                     &WPP_c6a2c65348053a21207e265485f83edf_Traceguids);
  }
  return iVar1;
}



===== AcpiParseULong @ 14003136c =====

/* long __cdecl AcpiParseULong(struct _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64,unsigned long *
   __ptr64) */

long __cdecl AcpiParseULong(_ACPI_METHOD_ARGUMENT_V1 *param_1,ulong *param_2)

{
  if (*(ushort *)(param_1 + 2) < 4) {
    return -0x3ffffff3;
  }
  *param_2 = *(ulong *)(param_1 + 4);
  return 0;
}



===== GetImageName @ 14003138c =====

/* long __cdecl GetImageName(void * __ptr64,char * __ptr64,unsigned __int64) */

long __cdecl GetImageName(void *param_1,char *param_2,__uint64 param_3)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  char *pcVar4;
  ulonglong *puVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  undefined2 uVar10;
  __uint64 local_res18;
  uint local_res20 [2];
  undefined1 uVar11;
  
  pcVar4 = param_2;
  local_res18 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    pcVar4 = (char *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x14,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
  }
  local_res18 = local_res18 & 0xffffffff00000000;
  local_res20[0] = 0;
  if (DAT_14002a488 == 0) {
    pcVar4 = (char *)0x0;
    PsGetVersion(local_res20,0,0,0);
    if (4 < local_res20[0]) {
      DAT_14002a480 = MmGetSystemRoutineAddress(&DAT_140026030);
      LOCK();
      DAT_14002a488 = 1;
      UNLOCK();
      goto LAB_14003148f;
    }
    iVar1 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff45;
    }
    uVar10 = 0x15;
    uVar11 = 0xbb;
  }
  else {
LAB_14003148f:
    uVar2 = AuxKlibQueryModuleInformation((uint *)&local_res18,pcVar4,0);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      if ((int)local_res18 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x17,
                           &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
        }
        iVar1 = -0x3fffffff;
        goto LAB_140031646;
      }
      uVar2 = (local_res18 & 0xffffffff) / 0x110;
      uVar8 = (uint)uVar2;
      lVar7 = uVar2 * 0x110;
      puVar3 = (ulonglong *)ExAllocatePool2(0x100,lVar7,0x586d6355);
      if (puVar3 == (ulonglong *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x18,
                            &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,(char)local_res18);
        }
        iVar1 = -0x3fffff66;
        goto LAB_140031646;
      }
      uVar2 = AuxKlibQueryModuleInformation((uint *)&local_res18,lVar7,(ulonglong)puVar3);
      iVar1 = (int)uVar2;
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x19,
                            &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,(char)uVar2);
        }
      }
      else {
        uVar6 = 0;
        puVar5 = puVar3;
        if (uVar8 != 0) {
          do {
            if (((void *)*puVar5 <= param_1) &&
               (param_1 < (void *)((ulonglong)(uint)puVar5[1] + (longlong)*puVar5))) {
              lVar7 = 0x20;
              lVar9 = (ulonglong)*(ushort *)((longlong)puVar5 + 0xc) - (longlong)param_2;
              goto LAB_14003169e;
            }
            puVar5 = puVar5 + 0x22;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar8);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x1a,
                            &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,(char)param_1);
        }
        iVar1 = -0x3ffffddb;
      }
      goto LAB_140031635;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar10 = 0x16;
    uVar11 = (undefined1)uVar2;
  }
  WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,uVar10,
                    &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids,uVar11);
  goto LAB_140031646;
  while( true ) {
    *param_2 = param_2[(longlong)puVar5 + lVar9 + 0xe];
    param_2 = param_2 + 1;
    lVar7 = lVar7 + -1;
    if (lVar7 == 0) break;
LAB_14003169e:
    if ((lVar7 == -0x7fffffde) || (param_2[(longlong)puVar5 + lVar9 + 0xe] == '\0')) break;
  }
  iVar1 = 0;
  pcVar4 = param_2 + -1;
  if (lVar7 != 0) {
    pcVar4 = param_2;
  }
  *pcVar4 = '\0';
LAB_140031635:
  ExFreePoolWithTag(puVar3,0);
LAB_140031646:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_e12d73b73fcc3e377d0d86f5e6af1ac4_Traceguids);
  }
  return iVar1;
}



===== AcpiGetIoTarget @ 1400316e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl AcpiGetIoTarget(struct WDFDEVICE__ * __ptr64,struct WDFIOTARGET__ * __ptr64 *
   __ptr64) */

long __cdecl AcpiGetIoTarget(WDFDEVICE__ *param_1,WDFIOTARGET__ **param_2)

{
  WDFIOTARGET__ *pWVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_b50151b40c85334701ccf5fe94c069be_Traceguids);
  }
  pWVar1 = (WDFIOTARGET__ *)(**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  *param_2 = pWVar1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xb,
                     &WPP_b50151b40c85334701ccf5fe94c069be_Traceguids);
  }
  return 0;
}



===== AuxKlibQueryModuleInformation @ 1400317ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AuxKlibQueryModuleInformation(uint *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined1 auStack_188 [32];
  undefined4 local_168 [2];
  uint *local_160;
  uint local_158 [76];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  uVar11 = 0;
  local_168[0] = 0;
  local_158[1] = 0;
  memset(local_158,0,300);
  if (DAT_14002a488 == 1) {
    if (DAT_14002a480 == (code *)0x0) {
      uVar5 = (ulonglong)(-(uint)((param_3 & 7) != 0) & 0xc00000f1);
      if ((param_3 & 7) == 0) {
        puVar7 = local_158;
        uVar12 = 0x130;
        while( true ) {
          uVar4 = ZwQuerySystemInformation(0xb,puVar7,uVar12,local_168);
          uVar5 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) break;
          if (uVar4 != 0xc0000004) goto LAB_14003195a;
          if (puVar7 != local_158) {
            ExFreePoolWithTag(puVar7,0);
          }
          puVar7 = (uint *)ExAllocatePoolWithQuotaTag(0x409,local_168[0],0x4b787541);
          if (puVar7 == (uint *)0x0) {
            return 0xc000009a;
          }
          local_160 = puVar7;
          uVar12 = local_168[0];
        }
        uVar4 = *puVar7;
        if ((ulonglong)uVar4 * 0x110 < 0x100000000) {
          if (param_3 != 0) {
            if (*param_1 < uVar4 * 0x110) {
              uVar5 = 0xc0000023;
            }
            else if (uVar4 != 0) {
              do {
                puVar9 = (undefined8 *)(uVar11 * 0x110 + param_3);
                *puVar9 = *(undefined8 *)(puVar7 + uVar11 * 0x4a + 6);
                *(uint *)(puVar9 + 1) = puVar7[uVar11 * 0x4a + 8];
                *(undefined2 *)((longlong)puVar9 + 0xc) =
                     *(undefined2 *)(uVar11 * 0x128 + 0x2e + (longlong)puVar7);
                puVar6 = puVar7 + uVar11 * 0x4a + 0xc;
                lVar8 = 2;
                puVar9 = (undefined8 *)((longlong)puVar9 + 0xe);
                do {
                  uVar3 = *(undefined8 *)(puVar6 + 2);
                  *puVar9 = *(undefined8 *)puVar6;
                  puVar9[1] = uVar3;
                  uVar3 = *(undefined8 *)(puVar6 + 6);
                  puVar9[2] = *(undefined8 *)(puVar6 + 4);
                  puVar9[3] = uVar3;
                  uVar3 = *(undefined8 *)(puVar6 + 10);
                  puVar9[4] = *(undefined8 *)(puVar6 + 8);
                  puVar9[5] = uVar3;
                  uVar3 = *(undefined8 *)(puVar6 + 0xe);
                  puVar9[6] = *(undefined8 *)(puVar6 + 0xc);
                  puVar9[7] = uVar3;
                  uVar3 = *(undefined8 *)(puVar6 + 0x12);
                  puVar9[8] = *(undefined8 *)(puVar6 + 0x10);
                  puVar9[9] = uVar3;
                  uVar3 = *(undefined8 *)(puVar6 + 0x16);
                  puVar9[10] = *(undefined8 *)(puVar6 + 0x14);
                  puVar9[0xb] = uVar3;
                  uVar10 = puVar6[0x19];
                  uVar1 = puVar6[0x1a];
                  uVar2 = puVar6[0x1b];
                  *(uint *)(puVar9 + 0xc) = puVar6[0x18];
                  *(uint *)((longlong)puVar9 + 100) = uVar10;
                  *(uint *)(puVar9 + 0xd) = uVar1;
                  *(uint *)((longlong)puVar9 + 0x6c) = uVar2;
                  uVar3 = *(undefined8 *)(puVar6 + 0x1e);
                  puVar9[0xe] = *(undefined8 *)(puVar6 + 0x1c);
                  puVar9[0xf] = uVar3;
                  puVar6 = puVar6 + 0x20;
                  lVar8 = lVar8 + -1;
                  puVar9 = puVar9 + 0x10;
                } while (lVar8 != 0);
                uVar10 = (int)uVar11 + 1;
                uVar11 = (ulonglong)uVar10;
              } while (uVar10 < *puVar7);
            }
          }
          *param_1 = uVar4 * 0x110;
        }
        else {
          uVar5 = 0xc0000095;
        }
LAB_14003195a:
        if (puVar7 != local_158) {
          ExFreePoolWithTag(puVar7,0);
        }
      }
    }
    else {
      uVar5 = (*DAT_14002a480)(param_1,0x110,param_3);
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  return uVar5;
}



===== AuxKlibQueryModuleInformation$filt$0 @ 1400319fe =====

bool AuxKlibQueryModuleInformation_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff66;
}



===== __security_init_cookie @ 140032008 =====

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



===== wil_InitializeFeatureStaging @ 14003203c =====

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
    for (ppuVar3 = &Feature_UFFPPUWOUD__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400320c3;
    }
LAB_1400320fd:
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
LAB_1400320c3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400320fd;
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
    goto LAB_1400320fd;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140029aff < ppuVar3) goto LAB_1400320fd;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400320c3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140032150 =====

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
  ppuVar4 = &Feature_UFFPPUWOUD__private_descriptor;
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
            if (&UNK_140029aff < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14003223a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14003223a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14003223a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140029aff < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


