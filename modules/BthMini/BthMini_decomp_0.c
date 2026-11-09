
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
  *param_6 = PTR_DAT_14000c048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000c048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000c060,&local_18,0,0,param_5,param_6);
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



===== BthMini_ScoAddChannel @ 1400010d0 =====

/* long __cdecl BthMini_ScoAddChannel(struct _BTDEVICE * __ptr64,struct _BTH_SCO_ADD_CHANNEL_ARG *
   __ptr64) */

long __cdecl BthMini_ScoAddChannel(_BTDEVICE *param_1,_BTH_SCO_ADD_CHANNEL_ARG *param_2)

{
  char cVar1;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1e,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0xd);
  return -0x3ffffff3;
}



===== BthMini_ScoControlChannel @ 140001140 =====

/* long __cdecl BthMini_ScoControlChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_CONTROL_CHANNEL_ARG * __ptr64) */

long __cdecl BthMini_ScoControlChannel(_BTDEVICE *param_1,_BTH_SCO_CONTROL_CHANNEL_ARG *param_2)

{
  char cVar1;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x20,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0xd);
  return -0x3ffffff3;
}



===== BthMini_ScoRemoveChannel @ 1400011b0 =====

/* long __cdecl BthMini_ScoRemoveChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_REMOVE_CHANNEL_ARG * __ptr64) */

long __cdecl BthMini_ScoRemoveChannel(_BTDEVICE *param_1,_BTH_SCO_REMOVE_CHANNEL_ARG *param_2)

{
  char cVar1;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0xd);
  return -0x3ffffff3;
}



===== BthMini_ScoValidateChannel @ 140001220 =====

/* long __cdecl BthMini_ScoValidateChannel(struct _BTDEVICE * __ptr64,struct
   _BTH_SCO_VALIDATE_CHANNEL_ARG * __ptr64) */

long __cdecl BthMini_ScoValidateChannel(_BTDEVICE *param_1,_BTH_SCO_VALIDATE_CHANNEL_ARG *param_2)

{
  char cVar1;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0xd);
  return -0x3ffffff3;
}



===== McGenControlCallbackV2 @ 140001290 =====

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



===== McGenEventRegister_EtwRegister @ 1400013a0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (BTHMINI_EVENT_PROVIDER_Context == 0) {
    EtwRegister(&BTHMINI_EVENT_PROVIDER,McGenControlCallbackV2,&BTHMINI_EVENT_PROVIDER_Context,
                &BTHMINI_EVENT_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1400013e0 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (BTHMINI_EVENT_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    BTHMINI_EVENT_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140001414 =====

void McGenEventWrite_EtwWriteTransfer(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *in_stack_00000028;
  
  puVar1 = DAT_140009008;
  uVar2 = 0;
  if (DAT_140009008 == (ushort *)0x0) {
    *in_stack_00000028 = 0;
    uVar3 = 0;
  }
  else {
    *in_stack_00000028 = DAT_140009008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(in_stack_00000028 + 1) = uVar3;
  *(undefined4 *)((longlong)in_stack_00000028 + 0xc) = uVar2;
  EtwWriteTransfer(BTHMINI_EVENT_PROVIDER_Context,&_E_LFDVersionNotSupported,0,0,4);
  return;
}



===== McTemplateK0qqq_EtwWriteTransfer @ 14000147c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 auStack_98 [32];
  undefined1 *local_78;
  undefined4 local_68 [2];
  undefined4 local_60 [2];
  undefined1 local_58 [16];
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  local_40 = 4;
  local_48 = local_res20;
  local_60[0] = 0;
  local_38 = local_68;
  local_28 = local_60;
  local_78 = local_58;
  local_68[0] = 0;
  local_30 = 4;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer();
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_ @ 140001500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6,undefined2 param_7)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,param_7,0);
  }
  WppAutoLogTrace(param_4,4,param_6,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,param_7,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_DD @ 140001574 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_DD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0x18,
               &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,4,2,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0x18,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_Dd @ 140001630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_Dd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000424;
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0x17,
               &uStack0000000000000048,4,local_18,4,0);
  }
  WppAutoLogTrace(param_4,2,2,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0x17,
                  &uStack0000000000000048,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_d @ 1400016f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_d
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,4,0);
  }
  WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qd @ 140001790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,0);
  }
  WppAutoLogTrace(param_4,param_5,param_6,param_8,param_7,&param_9,8,&param_10,4,0);
  return;
}



===== WppClassicProviderCallback @ 140001860 =====

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



===== EvtObjectContextCleanupThunk @ 1400018c0 =====

/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   Fdo,1>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,Fdo,1>::EvtObjectContextCleanupThunk(void *param_1)

{
  Fdo *this;
  
  this = Fdo::FromWdfDevice(param_1);
  if (this != (Fdo *)0x0) {
    Fdo::~Fdo(this);
  }
  return;
}



===== FromWdfDevice @ 1400018e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class Fdo & __ptr64 __cdecl Fdo::FromWdfDevice(struct WDFDEVICE__ * __ptr64) */

Fdo * __cdecl Fdo::FromWdfDevice(WDFDEVICE__ *param_1)

{
  Fdo *pFVar1;
  
  pFVar1 = (Fdo *)(**(code **)(WdfFunctions_01031 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_Fdo_TYPE_INFO_140009098);
  return pFVar1;
}



===== GetRecorderLog @ 140001918 =====

/* public: struct RECORDER_LOG__ * __ptr64 __cdecl Fdo::GetRecorderLog(void)const __ptr64 */

RECORDER_LOG__ * __thiscall Fdo::GetRecorderLog(Fdo *this)

{
  return (RECORDER_LOG__ *)this->m_recorder;
}



===== WPP_RECORDER_AND_TRACE_SF_q @ 140001924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_q
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,0);
  }
  WppAutoLogTrace(param_4,param_5,1,param_8,param_7,&param_9,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDDD @ 1400019c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDDD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,0x13,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,0x13,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLL @ 140001ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,param_7,&param_9,8,
               &param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_4,4,1,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,param_7,&param_9,8,
                  &param_10,4,&param_11,4,0);
  return;
}



===== DecrementPendingEventPacketCount @ 140001bac =====

/* private: void __cdecl ReceiveQueue::DecrementPendingEventPacketCount(void) __ptr64 */

void __thiscall ReceiveQueue::DecrementPendingEventPacketCount(ReceiveQueue *this)

{
  kernel_spin_lock *pkVar1;
  undefined8 uVar2;
  uchar uVar3;
  kspin_lock_saved_irql local_18;
  
  pkVar1 = &this->m_pendingEventPacketCounterLock;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pkVar1);
  uVar2 = local_18._8_8_;
  local_18.savedIrql = uVar3;
  local_18._13_2_ = SUB82(uVar2,5);
  local_18._15_1_ = SUB81(uVar2,7);
  local_18.spinLock = &pkVar1->m_kSpinLock;
  if (this->m_pendingEventPacketCounter == 0) {
    MicrosoftTelemetryAssertTriggeredMsgKM("Underrun of pending event packet count.");
  }
  else {
    this->m_pendingEventPacketCounter = this->m_pendingEventPacketCounter - 1;
  }
  if (pkVar1 != (kernel_spin_lock *)0x0) {
    wil::details::kspin_lock_saved_irql::Release(&local_18);
  }
  return;
}



===== EvtIoQueueIoDefault @ 140001c38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl ReceiveQueue::EvtIoQueueIoDefault(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall ReceiveQueue::EvtIoQueueIoDefault(ReceiveQueue *this,WDFREQUEST__ *param_1)

{
  kernel_spin_lock *pkVar1;
  int *piVar2;
  int *piVar3;
  uchar uVar4;
  char cVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  code *pcVar9;
  uint uVar10;
  byte bVar11;
  undefined1 auStackY_128 [32];
  undefined1 in_stack_fffffffffffffef8;
  undefined7 in_stack_fffffffffffffef9;
  undefined4 in_stack_ffffffffffffff00;
  undefined4 in_stack_ffffffffffffff04;
  kspin_lock_saved_irql local_c8;
  ulonglong local_b8;
  int *local_b0 [3];
  kspin_lock_saved_irql local_98;
  undefined1 local_88 [8];
  int local_80;
  undefined4 local_78;
  undefined4 local_70;
  int *local_68;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0[0] = (int *)0x0;
  local_b8 = 0;
  (*DAT_140009308)(BthDriverGlobals,param_1,local_b0,&local_b8);
  pkVar1 = &this->m_pendingEventPacketCounterLock;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pkVar1);
  uVar8 = local_c8._8_8_;
  cVar5 = '\x01';
  local_c8.savedIrql = uVar4;
  local_c8._13_2_ = SUB82(uVar8,5);
  local_c8._15_1_ = SUB81(uVar8,7);
  local_c8.spinLock = &pkVar1->m_kSpinLock;
  if (this->m_pendingEventPacketCounter == 0) {
    this->m_pendingEventPacketCounter = 1;
    if (pkVar1 != (kernel_spin_lock *)0x0) {
      local_98.savedIrql = uVar4;
      local_98._9_7_ = local_c8._9_7_;
      local_98.spinLock = &pkVar1->m_kSpinLock;
      wil::details::kspin_lock_saved_irql::Release(&local_98);
    }
    bVar11 = 1;
    uVar10 = 0x101;
  }
  else {
    if (this->m_pendingEventPacketCounter != 1) {
      MicrosoftTelemetryAssertTriggeredMsgKM("Overrun of pending event packet count.");
    }
    if (pkVar1 != (kernel_spin_lock *)0x0) {
      wil::details::kspin_lock_saved_irql::Release(&local_c8);
    }
    uVar10 = this->m_maxAclTransferLength;
    bVar11 = 0;
  }
  piVar3 = local_b0[0];
  if (local_b8 < uVar10 + 9) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qDP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,local_b8,this->m_fdo->m_recorder);
    MicrosoftTelemetryAssertTriggeredMsgKM("Receive packet buffer smaller than expected.");
    if (bVar11 != 0) {
      DecrementPendingEventPacketCount(this);
    }
    uVar6 = 0xc0000206;
  }
  else {
    piVar2 = local_b0[0] + 1;
    *local_b0[0] = (uint)bVar11 * 2 + 2;
    lVar7 = (**(code **)(WdfFunctions_01031 + 0x8e8))(WdfDriverGlobals);
    *(int **)(lVar7 + 0x70) = piVar2;
    memset(local_88,0,0x48);
    local_80 = uVar10 + 5;
    local_68 = piVar3;
    local_78 = 4;
    local_70 = 0x410413;
    local_88[0] = 0xe;
    (**(code **)(WdfFunctions_01031 + 0x7e0))(WdfDriverGlobals,param_1,local_88);
    pcVar9 = EvtRequestCompletionRoutineThunk;
    (**(code **)(WdfFunctions_01031 + 0x820))
              (WdfDriverGlobals,param_1,EvtRequestCompletionRoutineThunk,this);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_qLq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,pcVar9,this->m_fdo->m_recorder,
               CONCAT71(in_stack_fffffffffffffef9,in_stack_fffffffffffffef8),
               CONCAT44(in_stack_ffffffffffffff04,in_stack_ffffffffffffff00),0xc,
               &WPP_2ff610a6053a331857203d83879ac13c_Traceguids,(char)*(undefined8 *)this->m_fdo,
               (char)*piVar3,(char)param_1);
    uVar8 = (**(code **)(WdfFunctions_01031 + 0x150))(WdfDriverGlobals,*(undefined8 *)this->m_fdo);
    cVar5 = (**(code **)(WdfFunctions_01031 + 0x7e8))(WdfDriverGlobals,param_1,uVar8,0);
    if (cVar5 != '\0') {
      return;
    }
    uVar6 = (**(code **)(WdfFunctions_01031 + 0x7f0))(WdfDriverGlobals);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
               this->m_fdo->m_recorder,2,1,0xd,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,
               (char)*(undefined8 *)this->m_fdo,(char)uVar6);
    if (bVar11 != 0) {
      DecrementPendingEventPacketCount(this);
    }
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,uVar6);
  return;
}



===== EvtIoQueueIoDefaultThunk @ 140001fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl ReceiveQueue::EvtIoQueueIoDefaultThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl ReceiveQueue::EvtIoQueueIoDefaultThunk(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  ReceiveQueue *this;
  
  this = (ReceiveQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_ReceiveQueue_TYPE_INFO_1400090c0);
  EvtIoQueueIoDefault(this,param_2);
  return;
}



===== GetContextFromObject @ 140002000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static class ReceiveQueue * __ptr64 __cdecl ReceiveQueue::GetContextFromObject(struct
   WDFQUEUE__ * __ptr64) */

ReceiveQueue * __cdecl ReceiveQueue::GetContextFromObject(WDFQUEUE__ *param_1)

{
  ReceiveQueue *pRVar1;
  
  pRVar1 = (ReceiveQueue *)
           (**(code **)(WdfFunctions_01031 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_ReceiveQueue_TYPE_INFO_1400090c0);
  return pRVar1;
}



===== EvtRequestCompletionRoutine @ 140002034 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl ReceiveQueue::EvtRequestCompletionRoutine(struct WDFREQUEST__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64) __ptr64 */

void __thiscall
ReceiveQueue::EvtRequestCompletionRoutine
          (ReceiveQueue *this,WDFREQUEST__ *param_1,_WDF_REQUEST_COMPLETION_PARAMS *param_2)

{
  int iVar1;
  _BTHX_HCI_PACKET_TYPE _Var2;
  ReceivePacketBuffer *pRVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  ReceivePacketBuffer **ppRVar7;
  __uint64 _Var8;
  undefined8 uVar9;
  ReceivePacketBuffer *local_res18;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffffa0;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar10;
  
  local_res18 = (ReceivePacketBuffer *)0x0;
  local_res20 = 0;
  ppRVar7 = &local_res18;
  (*DAT_140009308)(BthDriverGlobals,param_1,ppRVar7,&local_res20);
  pRVar3 = local_res18;
  iVar1 = (param_2->IoStatus).field0_0x0.Status;
  _Var2 = (local_res18->inputData).packetType;
  if (_Var2 == HciPacketEvent) {
    DecrementPendingEventPacketCount(this);
  }
  uVar10 = SUB81(param_1,0);
  if (iVar1 < 0) {
    cVar4 = (**(code **)(WdfFunctions_01031 + 0x808))(WdfDriverGlobals);
    if ((cVar4 == '\0') || (iVar1 != -0x3ffffee0)) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      WPP_RECORDER_AND_TRACE_SF_qqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,ppRVar7,this->m_fdo->m_recorder);
      if ((g_bthVerifierOn & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0xbff,2,(longlong)iVar1,0,0);
      }
      LOCK();
      this->m_consecutiveIOFailures = (atomic<unsigned_int>)((int)this->m_consecutiveIOFailures + 1)
      ;
      UNLOCK();
    }
    else {
      cVar4 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar4 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,ppRVar7,this->m_fdo->m_recorder,4,
                 in_stack_ffffffffffffffa0,0xf,in_stack_ffffffffffffffb0,
                 (char)*(undefined8 *)this->m_fdo,uVar10);
    }
    lVar6 = (param_2->IoStatus).field0_0x0.Status;
  }
  else {
    _Var8 = (param_2->IoStatus).Information;
    bVar5 = IsPacketValid(this,pRVar3,_Var8);
    if (bVar5) {
      this->m_consecutiveIOFailures = (atomic<unsigned_int>)0x0;
      (*DAT_1400092f8)(BthDriverGlobals,param_1,_Var2 != HciPacketEvent);
      uVar9 = 9;
      (*DAT_140009300)(BthDriverGlobals,param_1,9,(pRVar3->outputData).readWriteContext.DataLen);
      cVar4 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
      {
        cVar4 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,uVar9,this->m_fdo->m_recorder,4,
                 in_stack_ffffffffffffffa0,0x11,in_stack_ffffffffffffffb0,
                 (char)*(undefined8 *)this->m_fdo,uVar10);
      lVar6 = 0;
    }
    else {
      cVar4 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar4 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,_Var8,this->m_fdo->m_recorder,2,
                 in_stack_ffffffffffffffa0,0x10,in_stack_ffffffffffffffb0,
                 (char)*(undefined8 *)this->m_fdo,uVar10);
      (*DAT_140009310)(BthDriverGlobals,param_1);
      lVar6 = -0x3fffffc2;
    }
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,lVar6);
  return;
}



===== EvtRequestCompletionRoutineThunk @ 1400022d0 =====

/* private: static void __cdecl ReceiveQueue::EvtRequestCompletionRoutineThunk(struct WDFREQUEST__ *
   __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void *
   __ptr64) */

void __cdecl
ReceiveQueue::EvtRequestCompletionRoutineThunk
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  EvtRequestCompletionRoutine(param_4,param_1,param_3);
  return;
}



===== GetDesiredBufferLength @ 1400022ec =====

/* public: unsigned __int64 __cdecl ReceiveQueue::GetDesiredBufferLength(void)const __ptr64 */

__uint64 __thiscall ReceiveQueue::GetDesiredBufferLength(ReceiveQueue *this)

{
  uint uVar1;
  
  uVar1 = 0x101;
  if (0x101 < this->m_maxAclTransferLength) {
    uVar1 = this->m_maxAclTransferLength;
  }
  return (ulonglong)(uVar1 + 9);
}



===== GetDesiredNumberOfPendingPackets @ 140002304 =====

/* public: unsigned int __cdecl ReceiveQueue::GetDesiredNumberOfPendingPackets(void)const __ptr64 */

uint __thiscall ReceiveQueue::GetDesiredNumberOfPendingPackets(ReceiveQueue *this)

{
  return 3;
}



===== GetNumberOfConsecutiveIOFailures @ 140002314 =====

/* public: unsigned int __cdecl ReceiveQueue::GetNumberOfConsecutiveIOFailures(void)const __ptr64 */

uint __thiscall ReceiveQueue::GetNumberOfConsecutiveIOFailures(ReceiveQueue *this)

{
  return (uint)this->m_consecutiveIOFailures;
}



===== IsPacketValid @ 140002320 =====

/* private: bool __cdecl ReceiveQueue::IsPacketValid(struct ReceiveQueue::ReceivePacketBuffer &
   __ptr64,unsigned __int64) __ptr64 */

bool __thiscall
ReceiveQueue::IsPacketValid(ReceiveQueue *this,ReceivePacketBuffer *param_1,__uint64 param_2)

{
  byte bVar1;
  _BTHX_HCI_PACKET_TYPE _Var2;
  uint uVar3;
  char cVar4;
  Fdo *pFVar5;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined2 uVar6;
  undefined8 in_stack_ffffffffffffffd0;
  undefined1 uVar7;
  
  _Var2 = (param_1->inputData).packetType;
  bVar1 = (param_1->outputData).readWriteContext.Type;
  if (_Var2 == bVar1) {
    if (param_2 < 5) {
      cVar4 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar4 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,param_2,this->m_fdo->m_recorder,
                 in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x13,
                 &WPP_2ff610a6053a331857203d83879ac13c_Traceguids,(char)*(undefined8 *)this->m_fdo,
                 (char)param_2);
    }
    else {
      uVar3 = (param_1->outputData).readWriteContext.DataLen;
      if (param_2 - 5 == (ulonglong)uVar3) {
        if (bVar1 == 4) {
          if (uVar3 - 2 < 0x100) {
            return true;
          }
          cVar4 = '\x01';
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          pFVar5 = this->m_fdo;
          uVar7 = (undefined1)*(undefined8 *)pFVar5;
          uVar6 = 0x15;
        }
        else {
          if ((3 < uVar3) && (uVar3 <= this->m_maxAclTransferLength)) {
            return true;
          }
          cVar4 = '\x01';
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar4 = '\0';
          }
          pFVar5 = this->m_fdo;
          uVar7 = (undefined1)*(undefined8 *)pFVar5;
          uVar6 = 0x16;
        }
        WPP_RECORDER_AND_TRACE_SF_qD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,WPP_GLOBAL_Control,
                   pFVar5->m_recorder,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,uVar6,
                   in_stack_ffffffffffffffd0,uVar7,(char)uVar3);
      }
      else {
        cVar4 = '\x01';
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar4 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_qPD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,WPP_GLOBAL_Control,
                   this->m_fdo->m_recorder);
      }
    }
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_qDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar4,param_2,this->m_fdo->m_recorder);
    if ((g_bthVerifierOn & 1) != 0) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xbff,1,(longlong)(int)_Var2,bVar1,0);
    }
  }
  return false;
}



===== Release @ 14000250c =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(param_1->spinLock,param_1->savedIrql);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qD @ 140002530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,param_7,&param_9,8,
               &param_10,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,param_7,&param_9,8,
                  &param_10,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDD @ 1400025f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0x12,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0x12,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qDP @ 1400026d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qDP
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0xb,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qLq @ 1400027b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qLq
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,4,&param_11,8,0);
  }
  WppAutoLogTrace(param_4,4,1,param_8,param_7,&param_9,8,&param_10,4,&param_11,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qP @ 14000289c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qP
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)(param_1,0x2b,param_8,param_7,&param_9,8,&param_10,8,0);
  }
  WppAutoLogTrace(param_4,2,1,param_8,param_7,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qPD @ 140002960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qPD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0x14,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0x14,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qq @ 140002a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qq
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined2 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,param_7,&param_9,8,
               &param_10,8,0);
  }
  WppAutoLogTrace(param_4,param_5,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,param_7,
                  &param_9,8,&param_10,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqd @ 140002b04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0xe,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_2ff610a6053a331857203d83879ac13c_Traceguids,0xe,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  return;
}



===== EvtIoQueueIoDefault @ 140002be4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl TransmitQueue::EvtIoQueueIoDefault(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall TransmitQueue::EvtIoQueueIoDefault(TransmitQueue *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  _BTHX_HCI_READ_WRITE_CONTEXT *p_Var5;
  undefined4 *puVar6;
  longlong lVar7;
  void **ppvVar8;
  undefined8 uVar9;
  code *pcVar10;
  char cVar11;
  undefined1 auStackY_108 [32];
  undefined1 in_stack_ffffffffffffff18;
  undefined7 in_stack_ffffffffffffff19;
  undefined4 in_stack_ffffffffffffff20;
  undefined4 in_stack_ffffffffffffff24;
  ulong local_a8 [2];
  size_t local_a0;
  void *local_98 [2];
  undefined1 local_88 [8];
  undefined4 local_80;
  ulong local_78;
  undefined4 local_70;
  _BTHX_HCI_READ_WRITE_CONTEXT *local_68;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar2 = (*DAT_140009318)(BthDriverGlobals);
  ppvVar8 = local_98;
  cVar11 = '\0';
  local_98[0] = (void *)0x0;
  local_a0 = 0;
  (*DAT_140009320)(BthDriverGlobals,param_1,ppvVar8,&local_a0);
  cVar1 = '\x01';
  if (uVar2 < 2) {
    local_a8[0] = 0;
    lVar3 = ULongLongToULong(local_a0 + 5,local_a8);
    if (lVar3 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar1 = '\0';
      }
      WPP_RECORDER_AND_TRACE_SF_qP
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,ppvVar8,
                 (*(undefined8 **)(this + 8))[1],
                 CONCAT71(in_stack_ffffffffffffff19,in_stack_ffffffffffffff18),
                 CONCAT44(in_stack_ffffffffffffff24,in_stack_ffffffffffffff20),0xc,
                 &WPP_91be94ee4ad8322db47672e026161e26_Traceguids,(char)**(undefined8 **)(this + 8),
                 (char)local_a0);
      uVar4 = 0xc0000206;
    }
    else {
      uVar9 = 0x4e494d42;
      p_Var5 = (_BTHX_HCI_READ_WRITE_CONTEXT *)ExAllocatePool2(0x40,local_a8[0]);
      if (p_Var5 == (_BTHX_HCI_READ_WRITE_CONTEXT *)0x0) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar1 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_q
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,uVar9,
                   (*(undefined8 **)(this + 8))[1],2,
                   CONCAT44(in_stack_ffffffffffffff24,in_stack_ffffffffffffff20),0xd,
                   &WPP_91be94ee4ad8322db47672e026161e26_Traceguids,
                   (char)**(undefined8 **)(this + 8));
        uVar4 = 0xc000009a;
      }
      else {
        p_Var5->Type = (uVar2 != 0) + '\x01';
        p_Var5->DataLen = (ulong)local_a0;
        memmove(p_Var5->Data,local_98[0],local_a0);
        puVar6 = (undefined4 *)
                 (**(code **)(WdfFunctions_01031 + 0x650))
                           (WdfDriverGlobals,param_1,PTR__WDF_RequestContext_TYPE_INFO_140009060);
        *puVar6 = 0;
        lVar7 = (**(code **)(WdfFunctions_01031 + 0x8e8))(WdfDriverGlobals);
        *(undefined4 **)(lVar7 + 0x70) = puVar6;
        memset(local_88,0,0x48);
        local_78 = local_a8[0];
        local_88[0] = 0xe;
        local_70 = 0x41040f;
        local_80 = 4;
        local_68 = p_Var5;
        (**(code **)(WdfFunctions_01031 + 0x7e0))(WdfDriverGlobals,param_1,local_88);
        pcVar10 = EvtRequestCompletionRoutineThunk;
        (**(code **)(WdfFunctions_01031 + 0x820))
                  (WdfDriverGlobals,param_1,EvtRequestCompletionRoutineThunk,p_Var5);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           (cVar1 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar1 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_qLq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,pcVar10,
                   (*(undefined8 **)(this + 8))[1],
                   CONCAT71(in_stack_ffffffffffffff19,in_stack_ffffffffffffff18),
                   CONCAT44(in_stack_ffffffffffffff24,in_stack_ffffffffffffff20),0xe,
                   &WPP_91be94ee4ad8322db47672e026161e26_Traceguids,
                   (char)**(undefined8 **)(this + 8),(char)uVar2,(char)param_1);
        uVar9 = (**(code **)(WdfFunctions_01031 + 0x150))
                          (WdfDriverGlobals,**(undefined8 **)(this + 8));
        cVar1 = (**(code **)(WdfFunctions_01031 + 0x7e8))(WdfDriverGlobals,param_1,uVar9,0);
        if (cVar1 != '\0') {
          return;
        }
        uVar4 = (**(code **)(WdfFunctions_01031 + 0x7f0))(WdfDriverGlobals,param_1);
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          cVar11 = '\x01';
        }
        WPP_RECORDER_AND_TRACE_SF_qd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar11,WPP_GLOBAL_Control,
                   (*(undefined8 **)(this + 8))[1],2,1,0xf,
                   &WPP_91be94ee4ad8322db47672e026161e26_Traceguids,
                   (char)**(undefined8 **)(this + 8),(char)uVar4);
        wil::details::pool_helpers<_BTHX_HCI_READ_WRITE_CONTEXT*___ptr64,0>::FreePoolWithTag(p_Var5)
        ;
      }
    }
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar1 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,ppvVar8,
               *(undefined8 *)(*(longlong *)(this + 8) + 8));
    MicrosoftTelemetryAssertTriggeredMsgKM("Unknown packet type.");
    uVar4 = 0xc00000bb;
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,uVar4);
  return;
}



===== EvtIoQueueIoDefaultThunk @ 140002ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl TransmitQueue::EvtIoQueueIoDefaultThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl TransmitQueue::EvtIoQueueIoDefaultThunk(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  TransmitQueue *this;
  
  this = (TransmitQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_TransmitQueue_TYPE_INFO_1400090e8);
  EvtIoQueueIoDefault(this,param_2);
  return;
}



===== EvtObjectContextCleanupThunk @ 140003040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static void __cdecl WdfCpp::ObjectContext<struct WDFQUEUE__ * __ptr64,class
   TransmitQueue,1>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,TransmitQueue,1>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  (**(code **)(WdfFunctions_01031 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_TransmitQueue_TYPE_INFO_1400090e8);
  return;
}



===== EvtRequestCompletionRoutine @ 140003074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl TransmitQueue::EvtRequestCompletionRoutine(struct WDFREQUEST__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS const & __ptr64,void * __ptr64) __ptr64 */

void __thiscall
TransmitQueue::EvtRequestCompletionRoutine
          (TransmitQueue *this,WDFREQUEST__ *param_1,_WDF_REQUEST_COMPLETION_PARAMS *param_2,
          void *param_3)

{
  int iVar1;
  uint uVar2;
  ulong64 uVar3;
  uint *puVar4;
  undefined8 uVar5;
  char cVar6;
  ulonglong local_res18 [2];
  
  iVar1 = (param_2->IoStatus).field0_0x0.Status;
  (*DAT_140009318)(BthDriverGlobals);
  if (iVar1 < 0) {
    cVar6 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar6 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_qqLd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,WPP_GLOBAL_Control,
               *(undefined8 *)(*(longlong *)(this + 8) + 8));
  }
  else {
    uVar3 = (param_2->IoStatus).Information;
    if (uVar3 == 4) {
      puVar4 = (uint *)(**(code **)(WdfFunctions_01031 + 0x650))
                                 (WdfDriverGlobals,param_1,
                                  PTR__WDF_RequestContext_TYPE_INFO_140009060);
      uVar2 = *puVar4;
      local_res18[1] = 0;
      local_res18[0] = 0;
      (*DAT_140009320)(BthDriverGlobals,param_1,local_res18 + 1,local_res18);
      if (uVar2 == local_res18[0]) {
        cVar6 = '\x01';
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
          cVar6 = '\0';
        }
        WPP_RECORDER_AND_TRACE_SF_qqL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,local_res18[0],
                   *(undefined8 *)(*(longlong *)(this + 8) + 8));
      }
      else {
        cVar6 = '\x01';
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
          cVar6 = '\0';
        }
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        WPP_RECORDER_AND_TRACE_SF_qqLPD
                  (uVar5,cVar6,local_res18[0],*(undefined8 *)(*(longlong *)(this + 8) + 8));
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  (uVar5,(undefined4)local_res18[0],uVar2,
                   "Transmit packet request completed with fewer bytes.");
      }
    }
    else {
      cVar6 = '\x01';
      if ((g_bthVerifierOn & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0xbff,3,uVar3,4,0);
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar6 = '\0';
      }
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      WPP_RECORDER_AND_TRACE_SF_qqLP(uVar5,cVar6,uVar3,*(undefined8 *)(*(longlong *)(this + 8) + 8))
      ;
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (uVar5,(int)(param_2->IoStatus).Information,0,
                 "Transport driver returned incorrect number of bytes.");
    }
  }
  (**(code **)(WdfFunctions_01031 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  if (param_3 != (void *)0x0) {
    wil::details::pool_helpers<_BTHX_HCI_READ_WRITE_CONTEXT*___ptr64,0>::FreePoolWithTag(param_3);
  }
  return;
}



===== EvtRequestCompletionRoutineThunk @ 1400032d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl TransmitQueue::EvtRequestCompletionRoutineThunk(struct WDFREQUEST__
   * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64,void *
   __ptr64) */

void __cdecl
TransmitQueue::EvtRequestCompletionRoutineThunk
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  undefined8 uVar1;
  TransmitQueue *this;
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x8d0))(WdfDriverGlobals,param_1);
  this = (TransmitQueue *)
         (**(code **)(WdfFunctions_01031 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_TransmitQueue_TYPE_INFO_1400090e8);
  EvtRequestCompletionRoutine(this,param_1,param_3,param_4);
  return;
}



===== FreePoolWithTag @ 140003354 =====

/* public: static void __cdecl wil::details::pool_helpers<struct _BTHX_HCI_READ_WRITE_CONTEXT *
   __ptr64,0>::FreePoolWithTag(struct _BTHX_HCI_READ_WRITE_CONTEXT * __ptr64) */

void __cdecl
wil::details::pool_helpers<_BTHX_HCI_READ_WRITE_CONTEXT*___ptr64,0>::FreePoolWithTag
          (_BTHX_HCI_READ_WRITE_CONTEXT *param_1)

{
  if (param_1 != (_BTHX_HCI_READ_WRITE_CONTEXT *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== ULongLongToULong @ 140003378 =====

/* long __cdecl ULongLongToULong(unsigned __int64,unsigned long * __ptr64) */

long __cdecl ULongLongToULong(__uint64 param_1,ulong *param_2)

{
  ulong uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0x100000000) {
    uVar1 = (ulong)param_1;
  }
  *param_2 = uVar1;
  return -(uint)(0xffffffff < param_1) & 0x80070216;
}



===== WPP_RECORDER_AND_TRACE_SF_qL @ 14000339c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0xb,
               &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0xb,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqL @ 14000345c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqL
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x13,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_4,4,1,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x13,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLP @ 14000353c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLP
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x11,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,8,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x11,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLPD @ 14000363c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLPD
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x12,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,8,&uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x12,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_AND_TRACE_SF_qqLd @ 140003764 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_AND_TRACE_SF_qqLd
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (param_2 != '\0') {
    (*pfnWppTraceMessage)
              (param_1,0x2b,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x10,
               &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
               &uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_4,2,1,&WPP_91be94ee4ad8322db47672e026161e26_Traceguids,0x10,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WppRecorderLogCloseFunction @ 140003868 =====

/* void __cdecl WppRecorderLogCloseFunction(struct RECORDER_LOG__ * __ptr64) */

void __cdecl WppRecorderLogCloseFunction(RECORDER_LOG__ *param_1)

{
  RECORDER_LOG__ *pRVar1;
  
  pRVar1 = (RECORDER_LOG__ *)imp_WppRecorderLogGetDefault(WPP_GLOBAL_Control);
  if (param_1 != pRVar1) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control,param_1);
  }
  return;
}



===== FxStubDriverUnloadCommon @ 1400038ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_BthCoreCx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140009268 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_140009268 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_140009268 == 0x78) {
      puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_140009268 + 0x78);
    }
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_14000391c:
      if (puVar1 == (uint *)0x0) goto LAB_140003975;
      if (puVar2 <= puVar1) goto LAB_14000398d;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_140009100,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&DAT_140009100,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if (((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) ||
       ((puVar1 + 0x1e <= puVar2 && (*puVar1 == 0x78)))) goto LAB_14000391c;
LAB_140003975:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000398d:
  WdfVersionUnbind(&DAT_1400093a0,&DAT_140009100,WdfDriverGlobals);
  return;
}



===== entry @ 1400039c0 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined *param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 1400039f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined *puVar4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    iVar1 = DriverEntry((_DRIVER_OBJECT *)0x0,param_2,param_3);
  }
  else {
    _DAT_1400093a0 = 0x2080000;
    _DAT_1400093a8 = &DAT_140009400;
    RtlCopyUnicodeString(&DAT_1400093a0);
    puVar4 = &DAT_140009100;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1400093a0,&DAT_140009100,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (param_1->DriverUnload != (_func___cdecl_void__DRIVER_OBJECT_ptr *)0x0) {
              DAT_140009608 = param_1->DriverUnload;
            }
            param_1->DriverUnload = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1400093a0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140009268 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_140009100,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 140003b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140009608 != (code *)0x0) && (DAT_140009608 != FxStubDriverUnload)) {
    (*DAT_140009608)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140003bb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140003bd9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_BthCoreCx_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x14000925f < puVar2) break;
    if ((((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) &&
        ((&__KMDF_CLASS_BIND_END < puVar2 + 0x1e || (*puVar2 != 0x78)))) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140009268 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_140009100,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&DAT_140009100,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    puVar2 = (uint *)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 140003d48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140003d65) */
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
    if ((void **)0x14000927f < ppvVar2) break;
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



===== InitializeTelemetryAssertsKMWorkerInternal @ 140003e10 =====

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
    _DAT_140009648 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14000c040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14000c008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x14000c078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140003ec4 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,"bthmini.sys",param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredMsgKM @ 140003ef8 =====

void MicrosoftTelemetryAssertTriggeredMsgKM(char *param_1)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,0,(char *)0x0,0xffffffff,0xffffffff,param_1)
  ;
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140003f28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400040fd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,int param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  longlong *plVar12;
  wchar_t *pwVar13;
  char *pcVar14;
  undefined8 *puVar15;
  byte *pbVar16;
  longlong lVar17;
  undefined1 *puVar18;
  undefined8 uVar19;
  IMAGE_DOS_HEADER *pIVar20;
  int iVar21;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [120];
  int local_128;
  undefined4 local_124;
  IMAGE_DOS_HEADER *local_120;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  char *local_48;
  int local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  puVar18 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_140004820;
  local_128 = param_2;
  local_124 = param_4;
  local_120 = param_1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar18 = auStack_1a8;
  for (plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList; plVar9 = (longlong *)*plVar9
      ) {
    plVar8 = plVar9 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar8 == param_1) goto LAB_14000407a;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar17 = _DAT_fffff78000000320;
  puVar18 = auStack_1a8;
  if (plVar8 != (longlong *)0x0) {
    *plVar8 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar18 = auStack_1a8;
    plVar8[2] = 0;
    *(undefined4 *)(plVar8 + 3) = 0;
    puVar15 = &g_MicrosoftTelemetryAssertsTriggeredList;
    plVar8[1] = (longlong)((ulonglong)uVar6 * lVar17) / 10000 + -0xea61;
    plVar9 = plVar8 + 4;
    plVar12 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar12 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar9 = (longlong *)(*pcVar1)();
      puVar18 = auStack_1a0;
    }
    *plVar9 = (longlong)plVar12;
    plVar9[1] = (longlong)puVar15;
    plVar12[1] = (longlong)plVar9;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar9;
LAB_14000407a:
    *(int *)(plVar8 + 2) = (int)plVar8[2] + 1;
    *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
    lVar17 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar18 + -8) = 0x14000408a;
    uVar6 = KeQueryTimeIncrement();
    lVar17 = (longlong)((ulonglong)uVar6 * lVar17) / 10000;
    if (60000 < (ulonglong)(lVar17 - plVar8[1])) {
      pIVar20 = &IMAGE_DOS_HEADER_140000000;
      *(dword *)(puVar18 + 0x6c) = 0x7a22425a;
      if ((param_1 < &IMAGE_DOS_HEADER_140000000) || ((IMAGE_DOS_HEADER *)0x140015000 < param_1)) {
        iVar21 = 0;
      }
      else {
        iVar21 = (int)param_1 + -0x40000000;
      }
      plVar8[1] = lVar17;
      *(int *)(puVar18 + 0x70) = (int)plVar8[2];
      lVar11 = plVar8[3];
      *(undefined4 *)(puVar18 + 0x74) = *(undefined4 *)((longlong)plVar8 + 0x14);
      *(undefined8 *)(puVar18 + -8) = 0x140004145;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar17 >> 8),uVar3));
      uVar19 = 0;
      if (param_3 == (char *)0x0) {
        param_3 = (char *)g_ModuleName;
      }
      lVar17 = -1;
      if (local_128 == 0) {
        if (5 < DAT_14000c040) {
          if (((_DAT_14000c050 & 0x400000000000) == 0) ||
             (bVar2 = true, (DAT_14000c058 & 0x400000000000) != DAT_14000c058)) {
            bVar2 = false;
          }
          if (bVar2) {
            *(undefined4 *)(puVar18 + 0x68) = 10;
            local_f8 = puVar18 + 0x68;
            local_e8 = puVar18 + 100;
            *(undefined4 *)(puVar18 + 0x60) = *(undefined4 *)(puVar18 + 0x6c);
            local_d8 = puVar18 + 0x60;
            local_c8 = puVar18 + 0x5c;
            local_f0 = 4;
            *(int *)(puVar18 + 100) = iVar21;
            local_e0 = 4;
            local_d0 = 4;
            *(dword *)(puVar18 + 0x5c) = 0x15000;
            local_c0 = 4;
            local_b8 = g_ModuleName;
            if (g_ModuleName == (wchar_t *)0x0) {
              local_b8 = L"<unknown>";
            }
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (*(char *)((longlong)local_b8 + lVar10) != '\0');
            local_b0 = (int)lVar10 + 1;
            *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x70);
            local_a8 = puVar18 + 0x58;
            *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x74);
            local_98 = puVar18 + 0x54;
            local_ac = 0;
            local_a0 = 4;
            local_90 = 4;
            *(undefined8 *)(puVar18 + -8) = 0x14000442b;
            bVar4 = KeGetCurrentIrql();
            pcVar14 = (char *)0x0;
            *(uint *)(puVar18 + 0x50) = (uint)bVar4;
            local_88 = puVar18 + 0x50;
            if (param_6 == (char *)0x0) {
              param_6 = "<unknown>";
            }
            if ((wchar_t *)param_6 == (wchar_t *)0x0) {
              param_6 = "";
              local_70 = 1;
            }
            else {
              lVar10 = -1;
              do {
                lVar10 = lVar10 + 1;
              } while (*(char *)((longlong)param_6 + lVar10) != '\0');
              local_70 = (int)lVar10 + 1;
            }
            pbVar16 = &DAT_1400079e1;
            *(undefined1 **)(puVar18 + 0x28) = local_118;
            *(undefined4 *)(puVar18 + 0x20) = 0xb;
            local_78 = (wchar_t *)param_6;
            goto LAB_140004497;
          }
        }
      }
      else if (5 < DAT_14000c040) {
        if (((_DAT_14000c050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_14000c058 & 0x400000000000) != DAT_14000c058)) {
          bVar2 = false;
        }
        if (bVar2) {
          *(undefined4 *)(puVar18 + 0x78) = 10;
          local_f8 = puVar18 + 0x78;
          local_e8 = puVar18 + 0x7c;
          *(undefined4 *)(puVar18 + 0x50) = *(undefined4 *)(puVar18 + 0x6c);
          local_d8 = puVar18 + 0x50;
          local_c8 = puVar18 + 0x54;
          local_f0 = 4;
          *(int *)(puVar18 + 0x7c) = iVar21;
          local_e0 = 4;
          local_d0 = 4;
          *(dword *)(puVar18 + 0x54) = 0x15000;
          local_c0 = 4;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (wchar_t *)0x0) {
            local_b8 = L"<unknown>";
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (*(char *)((longlong)local_b8 + lVar10) != '\0');
          local_b0 = (int)lVar10 + 1;
          *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x70);
          local_a8 = puVar18 + 0x58;
          *(undefined4 *)(puVar18 + 0x5c) = *(undefined4 *)(puVar18 + 0x74);
          local_98 = puVar18 + 0x5c;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14000426f;
          bVar4 = KeGetCurrentIrql();
          *(uint *)(puVar18 + 0x60) = (uint)bVar4;
          local_88 = puVar18 + 0x60;
          if ((wchar_t *)param_3 == (wchar_t *)0x0) {
            pcVar14 = "";
            local_70 = 1;
          }
          else {
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (*(char *)((longlong)param_3 + lVar10) != '\0');
            local_70 = (int)lVar10 + 1;
            pcVar14 = param_3;
          }
          *(undefined4 *)(puVar18 + 100) = local_124;
          local_68 = puVar18 + 100;
          *(undefined4 *)(puVar18 + 0x68) = param_5;
          local_58 = puVar18 + 0x68;
          if (param_6 == (char *)0x0) {
            param_6 = "<unknown>";
          }
          local_60 = 4;
          local_50 = 4;
          if (param_6 == (char *)0x0) {
            param_6 = "";
            local_40 = 1;
          }
          else {
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (param_6[lVar10] != '\0');
            local_40 = (int)lVar10 + 1;
          }
          *(undefined1 **)(puVar18 + 0x28) = local_118;
          local_3c = 0;
          pbVar16 = &DAT_140007891;
          *(undefined4 *)(puVar18 + 0x20) = 0xe;
          local_78 = (wchar_t *)pcVar14;
          local_48 = param_6;
LAB_140004497:
          local_6c = 0;
          local_80 = 4;
          *(undefined8 *)(puVar18 + -8) = 0x14000449c;
          _tlgWriteTransfer_EtwWriteTransfer
                    (pcVar14,pbVar16,uVar19,pIVar20,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if ((DAT_14000c078 == 0) || ((int)lVar11 != 0)) goto LAB_140004820;
      *(undefined8 *)(puVar18 + -8) = 0x1400044b8;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_140004820;
      uVar6 = *(uint *)(puVar18 + 0x6c);
      pwVar13 = L"TELASSERT";
      *(undefined4 *)(puVar18 + 0x40) = 0;
      *(undefined8 *)(puVar18 + 0x38) = 0;
      *(undefined8 *)(puVar18 + 0x30) = 0;
      *(undefined8 *)(puVar18 + 0x28) = 0x15000;
      *(ulonglong *)(puVar18 + 0x20) = (ulonglong)uVar6;
      *(undefined8 *)(puVar18 + -8) = 0x140004504;
      iVar7 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1,iVar21,g_ModuleName);
      if (local_128 == 0) {
        if (5 < DAT_14000c040) {
          if (((_DAT_14000c050 & 0x400000000000) == 0) ||
             (bVar2 = true, (DAT_14000c058 & 0x400000000000) != DAT_14000c058)) {
            bVar2 = false;
          }
          if (bVar2) {
            *(undefined4 *)(puVar18 + 0x68) = 10;
            *(int *)(puVar18 + 100) = iVar21;
            *(uint *)(puVar18 + 0x60) = uVar6;
            *(dword *)(puVar18 + 0x5c) = 0x15000;
            local_b8 = g_ModuleName;
            if (g_ModuleName == (wchar_t *)0x0) {
              local_b8 = L"<unknown>";
            }
            do {
              lVar17 = lVar17 + 1;
            } while (*(char *)((longlong)local_b8 + lVar17) != '\0');
            local_b0 = (int)lVar17;
            *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x70);
            *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x74);
            *(undefined1 **)(puVar18 + 0x28) = local_118;
            *(undefined4 *)(puVar18 + 0x20) = 10;
            pbVar16 = &DAT_140007a4e;
            *(int *)(puVar18 + 0x50) = iVar7;
            pcVar14 = (char *)pwVar13;
            goto LAB_1400047be;
          }
        }
      }
      else if (5 < DAT_14000c040) {
        if (((_DAT_14000c050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_14000c058 & 0x400000000000) != DAT_14000c058)) {
          bVar2 = false;
        }
        if (bVar2) {
          *(undefined4 *)(puVar18 + 0x68) = 10;
          *(int *)(puVar18 + 100) = iVar21;
          *(uint *)(puVar18 + 0x60) = uVar6;
          *(dword *)(puVar18 + 0x5c) = 0x15000;
          pcVar14 = (char *)g_ModuleName;
          if (g_ModuleName == (wchar_t *)0x0) {
            pcVar14 = "<unknown>";
          }
          lVar11 = -1;
          do {
            lVar11 = lVar11 + 1;
          } while (*(char *)((longlong)pcVar14 + lVar11) != '\0');
          local_b0 = (int)lVar11;
          *(undefined4 *)(puVar18 + 0x58) = *(undefined4 *)(puVar18 + 0x70);
          *(undefined4 *)(puVar18 + 0x54) = *(undefined4 *)(puVar18 + 0x74);
          *(int *)(puVar18 + 0x50) = iVar7;
          if ((wchar_t *)param_3 == (wchar_t *)0x0) {
            param_3 = "";
            local_70 = 1;
          }
          else {
            do {
              lVar17 = lVar17 + 1;
            } while (*(char *)((longlong)param_3 + lVar17) != '\0');
            local_70 = (int)lVar17 + 1;
          }
          pbVar16 = &DAT_14000793b;
          *(undefined4 *)(puVar18 + 0x7c) = local_124;
          local_68 = puVar18 + 0x7c;
          *(undefined4 *)(puVar18 + 0x78) = param_5;
          local_58 = puVar18 + 0x78;
          *(undefined1 **)(puVar18 + 0x28) = local_118;
          *(undefined4 *)(puVar18 + 0x20) = 0xd;
          local_6c = 0;
          local_60 = 4;
          local_50 = 4;
          local_b8 = (wchar_t *)pcVar14;
          local_78 = (wchar_t *)param_3;
LAB_1400047be:
          local_b0 = local_b0 + 1;
          local_80 = 4;
          local_88 = puVar18 + 0x50;
          local_90 = 4;
          local_98 = puVar18 + 0x54;
          local_a0 = 4;
          local_a8 = puVar18 + 0x58;
          local_ac = 0;
          local_c0 = 4;
          local_c8 = puVar18 + 0x5c;
          local_d0 = 4;
          local_d8 = puVar18 + 0x60;
          local_e0 = 4;
          local_e8 = puVar18 + 100;
          local_f0 = 4;
          local_f8 = puVar18 + 0x68;
          *(undefined8 *)(puVar18 + -8) = 0x1400047c3;
          _tlgWriteTransfer_EtwWriteTransfer
                    (pcVar14,pbVar16,0,0x400000000000,*(undefined4 *)(puVar18 + 0x20),
                     *(undefined8 **)(puVar18 + 0x28));
        }
      }
      if (iVar7 != 0) goto LAB_140004820;
      *(undefined8 *)(puVar18 + -8) = 0x1400047d5;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar9[-4] == local_120) {
            *(int *)(plVar9 + -1) = (int)plVar9[-1] + 1;
            break;
          }
          plVar9 = (longlong *)*plVar9;
        } while ((longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar18 + -8) = 0x14000481b;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_140004820:
  *(undefined8 *)(puVar18 + -8) = 0x14000482c;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140004854 =====

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
    *(undefined8 *)(puVar6 + -8) = 0x1400048e7;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140004904;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_14000c098;
    DAT_14000c098 = 0;
    DAT_14000c078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14000492e;
    EtwUnregister(uVar3);
    uVar3 = DAT_14000c028;
    DAT_14000c028 = 0;
    _DAT_14000c008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140004950;
    EtwUnregister(uVar3);
    uVar3 = DAT_14000c060;
    DAT_14000c060 = 0;
    DAT_14000c040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140004972;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 14000498c =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== BthLib_Unload @ 140004998 =====

void BthLib_Unload(void)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  undefined1 uVar4;
  bool bVar5;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&BthLib_RefObjGlobals);
  while (pppplVar2 = DAT_140009628, (longlong *****)DAT_140009628 != &DAT_140009628) {
    if ((((longlong *****)DAT_140009628[1] != &DAT_140009628) ||
        (pppplVar1 = (longlong ****)*DAT_140009628, (longlong ****)pppplVar1[1] != DAT_140009628))
       || (DAT_140009628 = pppplVar1, pppplVar1[1] = (longlong ***)&DAT_140009628,
          (longlong *****)*local_10 != &local_18)) goto LAB_140004a75;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  KeReleaseSpinLock(&BthLib_RefObjGlobals,uVar4);
  while( true ) {
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar2 = (longlong ****)*local_18, (longlong ****)pppplVar2[1] != local_18)) break;
    pppplVar2[1] = (longlong ***)&local_18;
    bVar5 = local_18 != (longlong ****)0x408;
    local_18 = pppplVar2;
    if (bVar5) {
      ExFreePool();
    }
  }
LAB_140004a75:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== RefObj_GlobalsInit @ 140004a90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RefObj_GlobalsInit(void)

{
  _DAT_140009630 = &DAT_140009628;
  DAT_140009628 = &DAT_140009628;
  KeInitializeSpinLock(&BthLib_RefObjGlobals);
  MmIsDriverVerifyingByAddress(RefObj_GlobalsInit);
  return;
}



===== _guard_check_icall @ 140004af0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140004b08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140004b2c =====

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



===== __cpu_features_init @ 140004ba0 =====

/* WARNING: Removing unreachable block (ram,0x000140004c0a) */
/* WARNING: Removing unreachable block (ram,0x000140004bb9) */
/* WARNING: Removing unreachable block (ram,0x000140004baa) */

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



===== __security_check_cookie @ 140004c70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140004cb0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140004ce0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140004ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004d10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140004d80 =====

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



===== memset @ 140005080 =====

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



===== __memset_repmovs @ 1400051c0 =====

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



===== __memset_query @ 140005240 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400052c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140005400 =====

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



===== __memset_spec_plain @ 140005480 =====

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



===== BthMini_CreateDeviceExtension @ 14000d008 =====

/* struct _DEVICE_EXTENSION * __ptr64 __cdecl BthMini_CreateDeviceExtension(void) */

_DEVICE_EXTENSION * __cdecl BthMini_CreateDeviceExtension(void)

{
  _DEVICE_EXTENSION *p_Var1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  undefined8 in_R8;
  undefined8 uVar5;
  undefined1 in_stack_ffffffffffffffc8;
  undefined7 in_stack_ffffffffffffffc9;
  
  uVar4 = 0;
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffc9,in_stack_ffffffffffffffc8),2,0xf);
  uVar5 = 0x4e494d42;
  p_Var1 = (_DEVICE_EXTENSION *)ExAllocatePool2(0x40);
  if (p_Var1 == (_DEVICE_EXTENSION *)0x0) {
    uVar4 = 0x9a;
  }
  else {
    p_Var1->pBtDevice = (_BTDEVICE *)0x0;
    (p_Var1->Capabilities).MaxAclTransferInSize = 0;
    (p_Var1->Capabilities).ScoSupport = ScoSupportNone;
    (p_Var1->Capabilities).MaxScoChannels = 0;
    (p_Var1->Capabilities).IsDeviceIdleCapable = '\0';
    (p_Var1->Capabilities).IsDeviceWakeCapable = '\0';
    *(undefined2 *)&(p_Var1->Capabilities).field_0xe = 0;
    *(undefined8 *)&p_Var1->LTDBthXDDIVersion = 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar3,uVar5,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x10,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,uVar4);
  return p_Var1;
}



===== BthMini_DriverUnload @ 14000d0e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthMini_DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl BthMini_DriverUnload(_DRIVER_OBJECT *param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined8 in_R8;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffd8,2,0xe);
  UninitializeTelemetryAssertsKM();
  McGenEventUnregister_EtwUnregister();
  BthLib_Unload();
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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== BthMini_GetCapabilities @ 14000d1e0 =====

/* long __cdecl BthMini_GetCapabilities(struct _BTDEVICE * __ptr64,struct _BTH_GET_CAPABILITIES_ARG
   * __ptr64) */

long __cdecl BthMini_GetCapabilities(_BTDEVICE *param_1,_BTH_GET_CAPABILITIES_ARG *param_2)

{
  void *pvVar1;
  char cVar2;
  undefined8 in_R8;
  undefined1 in_stack_ffffffffffffffc8;
  undefined7 in_stack_ffffffffffffffc9;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffc9,in_stack_ffffffffffffffc8),1,0x1b);
  pvVar1 = param_1->MiniportContext;
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)((longlong)pvVar1 + 8);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)((longlong)pvVar1 + 0xc);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)((longlong)pvVar1 + 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0);
  return 0;
}



===== BthMini_InitDeviceExtension @ 14000d29c =====

/* long __cdecl BthMini_InitDeviceExtension(struct _DEVICE_EXTENSION * __ptr64) */

long __cdecl BthMini_InitDeviceExtension(_DEVICE_EXTENSION *param_1)

{
  char cVar1;
  char cVar2;
  undefined8 in_R8;
  undefined1 in_stack_ffffffffffffffc8;
  undefined7 in_stack_ffffffffffffffc9;
  
  cVar2 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar1,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),
             CONCAT71(in_stack_ffffffffffffffc9,in_stack_ffffffffffffffc8),2,0x11);
  if (0x1000 < (param_1->Capabilities).MaxAclTransferInSize) {
    (param_1->Capabilities).MaxAclTransferInSize = 0x1000;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar2 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar2,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x12,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,0);
  return 0;
}



===== BthMini_PnpAddDevice @ 14000d34c =====

/* long __cdecl BthMini_PnpAddDevice(struct _BTDEVICE * __ptr64) */

long __cdecl BthMini_PnpAddDevice(_BTDEVICE *param_1)

{
  long lVar1;
  _DEVICE_EXTENSION *p_Var2;
  _BTHX_VERSION _Var3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  _BTHX_VERSION _Var7;
  undefined8 in_R8;
  _BTHX_VERSION *p_Var8;
  undefined8 uVar9;
  _BTHX_VERSION local_res10 [2];
  undefined8 in_stack_ffffffffffffffb8;
  undefined2 uVar10;
  
  local_res10[0].Version = 0;
  cVar6 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,in_R8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffffb8,2,0x15);
  p_Var8 = (_BTHX_VERSION *)0x0;
  lVar1 = BthMini_SubmitIrpSync(param_1,0,(void *)0x0,4,local_res10,0x410403);
  if (lVar1 == 0) {
    _Var7.Version = local_res10[0].Version & 1;
    if (_Var7.Version == 0) {
LAB_14000d4fb:
      lVar1 = -0x3ffffbdc;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      p_Var8 = (_BTHX_VERSION *)WPP_GLOBAL_Control;
      WPP_RECORDER_AND_TRACE_SF_Dd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
                 *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      if ((Microsoft_Windows_Bluetooth_BthminiEnableBits & 1) != 0) {
        McTemplateK0qqq_EtwWriteTransfer();
      }
      goto LAB_14000d53f;
    }
    _Var3.Version = 0x80000000;
    do {
      if ((_Var7.Version & _Var3.Version) != 0) {
        _Var7.Version = _Var3.Version;
        if (_Var3.Version == 0) goto LAB_14000d4fb;
        break;
      }
      _Var3.Version = _Var3.Version >> 1;
    } while (_Var3.Version != 0);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_DD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    p_Var8 = local_res10;
    local_res10[0].Version = _Var7.Version;
    lVar1 = BthMini_SubmitIrpSync(param_1,4,p_Var8,0,(void *)0x0,0x410407);
    if (lVar1 == 0) {
      p_Var2 = BthMini_CreateDeviceExtension();
      if (p_Var2 == (_DEVICE_EXTENSION *)0x0) {
        lVar1 = -0x3fffff66;
      }
      else {
        p_Var2->pBtDevice = param_1;
        lVar1 = 0;
        (p_Var2->LTDBthXDDIVersion).Version = local_res10[0].Version;
        param_1->MiniportContext = p_Var2;
      }
      goto LAB_14000d53f;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar10 = 0x19;
  }
  else {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar10 = 0x16;
  }
  WPP_RECORDER_AND_TRACE_SF_d
            (uVar4,cVar5,p_Var8,uVar9,2,2,uVar10,&WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
             (char)lVar1);
LAB_14000d53f:
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_qd
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,p_Var8,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x1a,
             &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,(char)param_1,(char)lVar1);
  return lVar1;
}



===== BthMini_SubmitIrpSync @ 14000d5a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl BthMini_SubmitIrpSync(struct _BTDEVICE * __ptr64,unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long) */

long __cdecl
BthMini_SubmitIrpSync
          (_BTDEVICE *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,ulong param_6)

{
  long lVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  ulonglong local_38;
  void *pvStack_30;
  ulonglong local_28;
  ulonglong local_20;
  void *pvStack_18;
  ulonglong local_10;
  
  local_28 = 0;
  pvStack_30 = (void *)0x0;
  if (param_2 == 0) {
    puVar4 = (ulonglong *)0x0;
  }
  else {
    puVar4 = &local_38;
    local_28 = (ulonglong)param_2;
    pvStack_30 = param_3;
  }
  local_38 = (ulonglong)(param_2 != 0);
  local_10 = 0;
  pvStack_18 = (void *)0x0;
  if (param_4 == 0) {
    puVar3 = (ulonglong *)0x0;
  }
  else {
    puVar3 = &local_20;
    pvStack_18 = param_5;
    local_10 = (ulonglong)param_4;
  }
  local_20 = (ulonglong)(param_4 != 0);
  uVar2 = (**(code **)(WdfFunctions_01031 + 0xf0))(WdfDriverGlobals,param_1->FunctionalDeviceObject)
  ;
  uVar2 = (**(code **)(WdfFunctions_01031 + 0x150))(WdfDriverGlobals,uVar2);
  lVar1 = (**(code **)(WdfFunctions_01031 + 0x5d0))
                    (WdfDriverGlobals,uVar2,0,param_6,puVar4,puVar3,0,0);
  return lVar1;
}



===== BthMini_WdfDeviceAdd @ 14000d6b0 =====

/* long __cdecl BthMini_WdfDeviceAdd(struct WDFDRIVER__ * __ptr64,struct WDFDEVICE_INIT * __ptr64)
    */

long __cdecl BthMini_WdfDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  
  lVar1 = Fdo::Make(param_2);
  return lVar1;
}



===== BthMini_WdfDriverUnload @ 14000d6d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl BthMini_WdfDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl BthMini_WdfDriverUnload(WDFDRIVER__ *param_1)

{
  _DRIVER_OBJECT *p_Var1;
  
  p_Var1 = (_DRIVER_OBJECT *)(**(code **)(WdfFunctions_01031 + 0x3b0))(WdfDriverGlobals,param_1);
  BthMini_DriverUnload(p_Var1);
  return;
}



===== BthVerif_IsBthVerifDisabled @ 14000d708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl BthVerif_IsBthVerifDisabled(void) */

uchar __cdecl BthVerif_IsBthVerifDisabled(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_RCX;
  undefined8 in_RDX;
  uchar uVar3;
  undefined1 auStack_58 [32];
  int local_38 [2];
  longlong local_30;
  undefined1 local_28 [8];
  undefined4 local_20;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = 0;
  local_38[0] = 0;
  uVar3 = '\0';
  local_20 = 4;
  iVar1 = BthOpenKey(in_RCX,in_RDX,&local_30);
  if (-1 < iVar1) {
    uVar2 = BthQueryKeyValueUlong(local_30,in_RDX,(longlong)local_28,local_38);
    if (-1 < (int)uVar2) {
      uVar3 = '\0';
      if (local_38[0] != 0) {
        uVar3 = '\x01';
      }
    }
    if (local_30 != 0) {
      ZwClose();
    }
  }
  return uVar3;
}



===== WppInitKm @ 14000d79c =====

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



===== WppLoadTracingSupport @ 14000d878 =====

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



===== WppTraceCallback @ 14000d9c0 =====

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



===== Fdo @ 14000dc48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl Fdo::Fdo(class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct RECORDER_LOG__ * __ptr64,void (__cdecl*)(struct
   RECORDER_LOG__ * __ptr64),&void __cdecl WppRecorderLogCloseFunction(struct RECORDER_LOG__ *
   __ptr64),struct wistd::integral_constant<unsigned __int64,0>,struct RECORDER_LOG__ *
   __ptr64,struct RECORDER_LOG__ * __ptr64,0,std::nullptr_t> > >) __ptr64 */

Fdo * __thiscall
Fdo::Fdo(Fdo *this,
        unique_any_t<wil::details::unique_storage<wil::details::resource_policy<RECORDER_LOG___*,void_(__cdecl*)(RECORDER_LOG___*),&void___cdecl_WppRecorderLogCloseFunction(RECORDER_LOG___*),wistd::integral_constant<unsigned___int64,0>,RECORDER_LOG___*,RECORDER_LOG___*,0,std::nullptr_t>_>_>
        *param_2)

{
  undefined8 uVar1;
  RECORDER_LOG__ *pRVar2;
  char cVar3;
  undefined *puVar4;
  undefined8 in_stack_ffffffffffffffd0;
  
  uVar1 = (**(code **)(WdfFunctions_01031 + 0x660))(WdfDriverGlobals,this);
  *(undefined8 *)this = uVar1;
  this->m_recorder = *param_2;
  *param_2 = (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<RECORDER_LOG___*,void_(__cdecl*)(RECORDER_LOG___*),&void___cdecl_WppRecorderLogCloseFunction(RECORDER_LOG___*),wistd::integral_constant<unsigned___int64,0>,RECORDER_LOG___*,RECORDER_LOG___*,0,std::nullptr_t>_>_>
              )0x0;
  this->m_btDevice = (_BTDEVICE *)0x0;
  this->m_devExt = (_DEVICE_EXTENSION *)0x0;
  (this->m_receiveQueue)._MyDat._MyRealVal = (ReceiveQueue *)0x0;
  *(undefined8 *)&this->m_transmitQueue = 0;
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  puVar4 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar4 + 0x18),cVar3,*(undefined8 *)this,pRVar2,4,
             in_stack_ffffffffffffffd0,10,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,
             (char)*(undefined8 *)this);
  if (*param_2 !=
      (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<RECORDER_LOG___*,void_(__cdecl*)(RECORDER_LOG___*),&void___cdecl_WppRecorderLogCloseFunction(RECORDER_LOG___*),wistd::integral_constant<unsigned___int64,0>,RECORDER_LOG___*,RECORDER_LOG___*,0,std::nullptr_t>_>_>
       )0x0) {
    WppRecorderLogCloseFunction((RECORDER_LOG__ *)*param_2);
  }
  return this;
}



===== ~Fdo @ 14000dd08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl Fdo::~Fdo(void) __ptr64 */

void __thiscall Fdo::~Fdo(Fdo *this)

{
  _DEVICE_EXTENSION *p_Var1;
  ReceiveQueue *pRVar2;
  RECORDER_LOG__ *pRVar3;
  Fdo *pFVar4;
  char cVar5;
  char cVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined1 uVar9;
  undefined7 in_stack_ffffffffffffffc9;
  undefined4 in_stack_ffffffffffffffd0;
  undefined4 in_stack_ffffffffffffffd4;
  
  cVar6 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
  }
  pFVar4 = this;
  puVar8 = WPP_GLOBAL_Control;
  pRVar3 = GetRecorderLog(this);
  uVar7 = *(undefined8 *)pFVar4;
  uVar9 = 4;
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar8 + 0x18),cVar5,uVar7,pRVar3,4,
             CONCAT44(in_stack_ffffffffffffffd4,in_stack_ffffffffffffffd0),0xb,
             &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)uVar7);
  p_Var1 = this->m_devExt;
  if (p_Var1 != (_DEVICE_EXTENSION *)0x0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar5,uVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(in_stack_ffffffffffffffc9,uVar9),
               2,0x13);
    ExFreePoolWithTag(p_Var1,0);
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar6 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,uVar7,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT71(in_stack_ffffffffffffffc9,uVar9),
               2,0x14);
    this->m_devExt = (_DEVICE_EXTENSION *)0x0;
    this->m_btDevice->MiniportContext = (void *)0x0;
  }
  if (*(undefined8 **)&this->m_transmitQueue != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))
              (WdfDriverGlobals,**(undefined8 **)&this->m_transmitQueue);
  }
  pRVar2 = (this->m_receiveQueue)._MyDat._MyRealVal;
  if (pRVar2 != (ReceiveQueue *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,pRVar2->_padding_);
  }
  if (this->m_recorder !=
      (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<RECORDER_LOG___*,void_(__cdecl*)(RECORDER_LOG___*),&void___cdecl_WppRecorderLogCloseFunction(RECORDER_LOG___*),wistd::integral_constant<unsigned___int64,0>,RECORDER_LOG___*,RECORDER_LOG___*,0,std::nullptr_t>_>_>
       )0x0) {
    WppRecorderLogCloseFunction((RECORDER_LOG__ *)this->m_recorder);
  }
  return;
}



===== EvtControllerTransportResetThunk @ 14000de80 =====

/* private: static long __cdecl Fdo::EvtControllerTransportResetThunk(struct WDFDEVICE__ * __ptr64)
    */

long __cdecl Fdo::EvtControllerTransportResetThunk(WDFDEVICE__ *param_1)

{
  uint uVar1;
  Fdo *this;
  RECORDER_LOG__ *pRVar2;
  char *pcVar3;
  long lVar4;
  undefined *puVar5;
  char cVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  this = FromWdfDevice(param_1);
  uVar1 = ReceiveQueue::GetNumberOfConsecutiveIOFailures((this->m_receiveQueue)._MyDat._MyRealVal);
  if (uVar1 < 4) {
    lVar4 = 0;
    cVar6 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    puVar5 = WPP_GLOBAL_Control;
    pRVar2 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(puVar5 + 0x18),cVar6,puVar5,pRVar2,3,in_stack_ffffffffffffffd0,0x18,
               &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)*(undefined8 *)this);
    pcVar3 = "Ignoring sporadic transport failure.";
  }
  else {
    cVar6 = '\x01';
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    puVar5 = WPP_GLOBAL_Control;
    pRVar2 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_q
              (*(undefined8 *)(puVar5 + 0x18),cVar6,*(undefined8 *)this,pRVar2,3,
               in_stack_ffffffffffffffd0,0x19,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,
               (char)*(undefined8 *)this);
    lVar4 = -0x3ffffb7d;
    pcVar3 = "Unrecoverable transport failure.";
  }
  MicrosoftTelemetryAssertTriggeredMsgKM(pcVar3);
  return lVar4;
}



===== EvtDeviceD0EntryThunk @ 14000df80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl Fdo::EvtDeviceD0EntryThunk(struct WDFDEVICE__ * __ptr64,enum
   _WDF_POWER_DEVICE_STATE) */

long __cdecl Fdo::EvtDeviceD0EntryThunk(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  undefined1 uVar1;
  Fdo *this;
  RECORDER_LOG__ *pRVar2;
  char cVar3;
  undefined *puVar4;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  this = FromWdfDevice(param_1);
  uVar1 = (**(code **)(WdfFunctions_01031 + 0xc20))(WdfDriverGlobals,*(undefined8 *)this);
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  puVar4 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_qLL
            (*(undefined8 *)(puVar4 + 0x18),cVar3,*(undefined8 *)this,pRVar2,
             in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x16,in_stack_ffffffffffffffd0,
             (char)*(undefined8 *)this,(char)param_2,uVar1);
  return 0;
}



===== EvtDeviceD0ExitThunk @ 14000e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl Fdo::EvtDeviceD0ExitThunk(struct WDFDEVICE__ * __ptr64,enum
   _WDF_POWER_DEVICE_STATE) */

long __cdecl Fdo::EvtDeviceD0ExitThunk(WDFDEVICE__ *param_1,_WDF_POWER_DEVICE_STATE param_2)

{
  undefined1 uVar1;
  Fdo *this;
  RECORDER_LOG__ *pRVar2;
  char cVar3;
  undefined *puVar4;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 in_stack_ffffffffffffffd0;
  
  this = FromWdfDevice(param_1);
  uVar1 = (**(code **)(WdfFunctions_01031 + 0xc20))(WdfDriverGlobals,*(undefined8 *)this);
  cVar3 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar3 = '\0';
  }
  puVar4 = WPP_GLOBAL_Control;
  pRVar2 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_qLL
            (*(undefined8 *)(puVar4 + 0x18),cVar3,*(undefined8 *)this,pRVar2,
             in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x17,in_stack_ffffffffffffffd0,
             (char)*(undefined8 *)this,(char)param_2,uVar1);
  return 0;
}



===== EvtDevicePrepareHardware @ 14000e0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl Fdo::EvtDevicePrepareHardware(void) __ptr64 */

long __thiscall Fdo::EvtDevicePrepareHardware(Fdo *this)

{
  _DEVICE_EXTENSION *p_Var1;
  int iVar2;
  long lVar3;
  RECORDER_LOG__ *pRVar4;
  undefined8 uVar5;
  Fdo *pFVar6;
  ReceiveQueue *this_00;
  char cVar7;
  undefined *puVar8;
  char cVar9;
  char cVar10;
  undefined *puVar11;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffff70;
  undefined2 uVar12;
  undefined8 local_58;
  ReceiveQueue *local_50;
  __uint64 local_48;
  uint local_40;
  undefined4 local_3c;
  undefined8 local_38;
  code *local_30;
  
  cVar10 = '\0';
  cVar7 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
     (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar9 = '\0';
  }
  pFVar6 = this;
  puVar8 = WPP_GLOBAL_Control;
  pRVar4 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar8 + 0x18),cVar9,puVar8,pRVar4,4,in_stack_ffffffffffffff70,0x11,
             &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)*(undefined8 *)pFVar6);
  p_Var1 = this->m_devExt;
  (p_Var1->Capabilities).MaxAclTransferInSize = 0;
  (p_Var1->Capabilities).ScoSupport = ScoSupportNone;
  (p_Var1->Capabilities).MaxScoChannels = 0;
  (p_Var1->Capabilities).IsDeviceIdleCapable = '\0';
  (p_Var1->Capabilities).IsDeviceWakeCapable = '\0';
  *(undefined2 *)&(p_Var1->Capabilities).field_0xe = 0;
  local_50 = (ReceiveQueue *)&this->m_devExt->Capabilities;
  local_58 = 1;
  local_48 = 0x10;
  uVar5 = (**(code **)(WdfFunctions_01031 + 0x150))(WdfDriverGlobals,*(undefined8 *)this);
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x5d0))
                    (WdfDriverGlobals,uVar5,0,0x41040b,0,&local_58,0,0);
  if (iVar2 != 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
       (cVar10 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar10 = '\0';
    }
    puVar8 = WPP_GLOBAL_Control;
    pRVar4 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(puVar8 + 0x18),cVar10,puVar8,pRVar4,2,1,0x10,
               &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)*(undefined8 *)this,
               (char)iVar2);
    if (iVar2 < 0) {
      return iVar2;
    }
    return -0x3fffffff;
  }
  if ((this->m_devExt->Capabilities).IsDeviceIdleCapable == '\0') {
    local_res8 = 8;
    iVar2 = (*DAT_1400092d8)(BthDriverGlobals,*(undefined8 *)this,&local_res8);
    if (iVar2 < 0) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        cVar10 = '\x01';
      }
      puVar11 = WPP_GLOBAL_Control;
      pRVar4 = GetRecorderLog(this);
      puVar8 = *(undefined **)this;
      uVar5 = *(undefined8 *)(puVar11 + 0x18);
      uVar12 = 0x12;
      puVar11 = puVar8;
      goto LAB_14000e280;
    }
  }
  p_Var1 = this->m_devExt;
  if ((((p_Var1->Capabilities).MaxAclTransferInSize < 0x103) ||
      ((p_Var1->Capabilities).ScoSupport != ScoSupportHCIBypass)) ||
     ((p_Var1->Capabilities).MaxScoChannels != 1)) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    puVar8 = WPP_GLOBAL_Control;
    pRVar4 = GetRecorderLog(this);
    WPP_RECORDER_AND_TRACE_SF_qDDD(*(undefined8 *)(puVar8 + 0x18),cVar7,*(undefined8 *)this,pRVar4);
    return -0x3ffffe7e;
  }
  lVar3 = BthMini_InitDeviceExtension(p_Var1);
  if (lVar3 < 0) {
    return lVar3;
  }
  lVar3 = ReceiveQueue::Make(this,(this->m_devExt->Capabilities).MaxAclTransferInSize,
                             &this->m_receiveQueue);
  if (lVar3 < 0) {
    return lVar3;
  }
  lVar3 = TransmitQueue::Make(this,&this->m_transmitQueue);
  if (lVar3 < 0) {
    return lVar3;
  }
  this_00 = (this->m_receiveQueue)._MyDat._MyRealVal;
  uVar5 = **(undefined8 **)&this->m_transmitQueue;
  local_48 = ReceiveQueue::GetDesiredBufferLength(this_00);
  local_50 = (ReceiveQueue *)this_00->_padding_;
  local_58 = 0x30;
  local_3c = 0;
  local_38 = uVar5;
  local_40 = ReceiveQueue::GetDesiredNumberOfPendingPackets(local_50);
  local_30 = EvtControllerTransportResetThunk;
  iVar2 = (*DAT_1400092c8)(BthDriverGlobals,*(undefined8 *)this,&local_58);
  if (-1 < iVar2) {
    return 0;
  }
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    cVar10 = '\x01';
  }
  puVar8 = WPP_GLOBAL_Control;
  pRVar4 = GetRecorderLog(this);
  puVar11 = *(undefined **)this;
  uVar5 = *(undefined8 *)(puVar8 + 0x18);
  uVar12 = 0x14;
LAB_14000e280:
  WPP_RECORDER_AND_TRACE_SF_qd
            (uVar5,cVar10,puVar8,pRVar4,2,1,uVar12,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,
             (char)puVar11,(char)iVar2);
  return iVar2;
}



===== EvtDevicePrepareHardwareThunk @ 14000e430 =====

/* private: static long __cdecl Fdo::EvtDevicePrepareHardwareThunk(struct WDFDEVICE__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
Fdo::EvtDevicePrepareHardwareThunk
          (WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  long lVar1;
  Fdo *this;
  
  this = FromWdfDevice(param_1);
  lVar1 = EvtDevicePrepareHardware(this);
  return lVar1;
}



===== EvtDeviceReleaseHardwareThunk @ 14000e450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl Fdo::EvtDeviceReleaseHardwareThunk(struct WDFDEVICE__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl Fdo::EvtDeviceReleaseHardwareThunk(WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  ReceiveQueue *pRVar1;
  undefined8 *puVar2;
  Fdo *this;
  RECORDER_LOG__ *pRVar3;
  char cVar4;
  undefined *puVar5;
  undefined8 in_stack_ffffffffffffffd0;
  
  this = FromWdfDevice(param_1);
  cVar4 = '\x01';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar4 = '\0';
  }
  puVar5 = WPP_GLOBAL_Control;
  pRVar3 = GetRecorderLog(this);
  WPP_RECORDER_AND_TRACE_SF_q
            (*(undefined8 *)(puVar5 + 0x18),cVar4,*(undefined8 *)this,pRVar3,4,
             in_stack_ffffffffffffffd0,0x15,&WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,
             (char)*(undefined8 *)this);
  pRVar1 = (this->m_receiveQueue)._MyDat._MyRealVal;
  (this->m_receiveQueue)._MyDat._MyRealVal = (ReceiveQueue *)0x0;
  if (pRVar1 != (ReceiveQueue *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,pRVar1->_padding_);
  }
  puVar2 = *(undefined8 **)&this->m_transmitQueue;
  *(undefined8 *)&this->m_transmitQueue = 0;
  if (puVar2 != (undefined8 *)0x0) {
    (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar2);
  }
  return 0;
}



===== Make @ 14000e514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl Fdo::Make(struct WDFDEVICE_INIT * __ptr64) */

long __cdecl Fdo::Make(WDFDEVICE_INIT *param_1)

{
  _BTDEVICE **pp_Var1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  Fdo *pFVar5;
  RECORDER_LOG__ *pRVar6;
  char *pcVar7;
  longlong lVar8;
  char cVar9;
  undefined *puVar10;
  undefined1 auStackY_158 [32];
  undefined2 uVar11;
  RECORDER_LOG__ *local_108;
  RECORDER_LOG__ *local_100;
  WDFDEVICE_INIT *local_f8;
  WDFDEVICE__ *local_f0;
  undefined4 local_e8 [2];
  code *local_e0;
  code *local_d0;
  code *local_c0;
  code *local_b8;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  char local_38 [16];
  undefined *local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_158;
  local_f8 = param_1;
  iVar2 = (*DAT_1400092d0)(BthDriverGlobals,param_1);
  cVar9 = '\0';
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar9 = '\x01';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
               &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)iVar2);
  }
  else {
    local_28 = (undefined *)0x0;
    local_48 = 0;
    pcVar7 = local_38;
    lVar8 = 0x10;
    uStack_40 = 0x1000000000;
    local_38[8] = '\0';
    local_38[9] = '\0';
    local_38[10] = '\0';
    local_38[0xb] = '\0';
    local_38[0xc] = '\0';
    local_38[0xd] = '\0';
    local_38[0xe] = '\0';
    local_38[0xf] = '\0';
    local_38[0] = '\0';
    local_38[1] = '\0';
    local_38[2] = '\0';
    local_38[3] = '\0';
    local_38[4] = '\0';
    local_38[5] = '\0';
    local_38[6] = '\0';
    local_38[7] = '\0';
    do {
      if ((lVar8 == -0x7fffffee) || (pcVar7[(longlong)"Fdo" - (longlong)local_38] == '\0')) break;
      *pcVar7 = pcVar7[(longlong)"Fdo" - (longlong)local_38];
      pcVar7 = pcVar7 + 1;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    local_108 = (RECORDER_LOG__ *)0x0;
    pcVar4 = pcVar7 + -1;
    if (lVar8 != 0) {
      pcVar4 = pcVar7;
    }
    *pcVar4 = '\0';
    local_28 = (undefined *)0x200000002;
    local_58 = 0x4e494d4200000038;
    pcStack_50 = (code *)0x10000002000;
    iVar2 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_58,&local_108);
    if (iVar2 < 0) {
      cVar9 = '\x01';
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar9 = '\0';
      }
      uVar11 = 0xd;
    }
    else {
      pcStack_50 = (code *)0x0;
      local_48 = 0;
      local_38[0] = '\0';
      local_38[1] = '\0';
      local_38[2] = '\0';
      local_38[3] = '\0';
      local_38[4] = '\0';
      local_38[5] = '\0';
      local_38[6] = '\0';
      local_38[7] = '\0';
      local_38[8] = '\0';
      local_38[9] = '\0';
      local_38[10] = '\0';
      local_38[0xb] = '\0';
      local_38[0xc] = '\0';
      local_38[0xd] = '\0';
      local_38[0xe] = '\0';
      local_38[0xf] = '\0';
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_58 = 0x38;
      }
      else if (WdfStructureCount < 0x27) {
        local_58 = 0xffffffff;
      }
      else {
        local_58 = (ulonglong)*(uint *)(WdfStructures + 0x130);
      }
      local_28 = PTR__WDF_RequestContext_TYPE_INFO_140009060;
      uStack_40 = 0x100000001;
      (**(code **)(WdfFunctions_01031 + 0x240))(WdfDriverGlobals,local_f8,&local_58);
      memset(local_e8,0,0x90);
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_e8[0] = 0x90;
      }
      else if (WdfStructureCount < 0x2a) {
        local_e8[0] = 0xffffffff;
      }
      else {
        local_e8[0] = *(undefined4 *)(WdfStructures + 0x148);
      }
      local_c0 = EvtDevicePrepareHardwareThunk;
      local_b8 = EvtDeviceReleaseHardwareThunk;
      local_e0 = EvtDeviceD0EntryThunk;
      local_d0 = EvtDeviceD0ExitThunk;
      (**(code **)(WdfFunctions_01031 + 0x1b8))(WdfDriverGlobals,local_f8,local_e8);
      local_38[0] = '\0';
      local_38[1] = '\0';
      local_38[2] = '\0';
      local_38[3] = '\0';
      local_38[4] = '\0';
      local_38[5] = '\0';
      local_38[6] = '\0';
      local_38[7] = '\0';
      local_38[8] = '\0';
      local_38[9] = '\0';
      local_38[10] = '\0';
      local_38[0xb] = '\0';
      local_38[0xc] = '\0';
      local_38[0xd] = '\0';
      local_38[0xe] = '\0';
      local_38[0xf] = '\0';
      local_f0 = (WDFDEVICE__ *)0x0;
      local_48 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_58 = 0x38;
      }
      else if (WdfStructureCount < 0x27) {
        local_58 = 0xffffffff;
      }
      else {
        local_58 = (ulonglong)*(uint *)(WdfStructures + 0x130);
      }
      local_28 = PTR__WDF_Fdo_TYPE_INFO_140009098;
      pcStack_50 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,Fdo,1>::EvtObjectContextCleanupThunk;
      uStack_40 = 0x100000001;
      iVar2 = (**(code **)(WdfFunctions_01031 + 600))
                        (WdfDriverGlobals,&local_f8,&local_58,&local_f0);
      cVar9 = '\x01';
      if (-1 < iVar2) {
        pFVar5 = FromWdfDevice(local_f0);
        if (pFVar5 == (Fdo *)0x0) {
          pFVar5 = (Fdo *)0x0;
        }
        else {
          local_100 = local_108;
          local_108 = (RECORDER_LOG__ *)0x0;
          pFVar5 = (Fdo *)Fdo(pFVar5,&local_100);
        }
        pp_Var1 = &pFVar5->m_btDevice;
        local_100 = (RECORDER_LOG__ *)CONCAT44(local_100._4_4_,4);
        iVar2 = (*BthFunctions)(BthDriverGlobals,local_f0,&local_100,pp_Var1);
        if (iVar2 < 0) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) ||
             (cVar9 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 2)) {
            cVar9 = '\0';
          }
          puVar10 = WPP_GLOBAL_Control;
          pRVar6 = GetRecorderLog(pFVar5);
          WPP_RECORDER_AND_TRACE_SF_qd
                    (*(undefined8 *)(puVar10 + 0x18),cVar9,*(undefined8 *)pFVar5,pRVar6,2,1,0xf,
                     &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)*(undefined8 *)pFVar5,
                     (char)iVar2);
          if (local_108 != (RECORDER_LOG__ *)0x0) {
            WppRecorderLogCloseFunction(local_108);
          }
          return iVar2;
        }
        lVar3 = BthMini_PnpAddDevice(*pp_Var1);
        if (lVar3 < 0) {
          if (local_108 != (RECORDER_LOG__ *)0x0) {
            WppRecorderLogCloseFunction(local_108);
          }
          return lVar3;
        }
        pFVar5->m_devExt = (*pp_Var1)->MiniportContext;
        if (local_108 != (RECORDER_LOG__ *)0x0) {
          WppRecorderLogCloseFunction(local_108);
        }
        return 0;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      {
        cVar9 = '\0';
      }
      uVar11 = 0xe;
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar9,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,
               &WPP_fdedab720d313a349c8da8dee5df1c00_Traceguids,(char)iVar2);
    if (local_108 != (RECORDER_LOG__ *)0x0) {
      WppRecorderLogCloseFunction(local_108);
    }
  }
  return iVar2;
}



===== Make @ 14000e9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl ReceiveQueue::Make(class Fdo & __ptr64,unsigned int,class
   utl::unique_ptr<class ReceiveQueue,struct WdfCpp::Details::ObjectContextDeleter<class
   ReceiveQueue> > & __ptr64) */

long __cdecl
ReceiveQueue::Make(Fdo *param_1,uint param_2,
                  unique_ptr<ReceiveQueue,WdfCpp::Details::ObjectContextDeleter<ReceiveQueue>_>
                  *param_3)

{
  ReceiveQueue *pRVar1;
  int iVar2;
  RECORDER_LOG__ *pRVar3;
  ReceiveQueue *pRVar4;
  longlong lVar5;
  char cVar6;
  undefined *puVar7;
  WDFQUEUE__ *local_res8;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined *local_88;
  undefined4 local_78;
  undefined8 local_74;
  code *local_68;
  undefined4 local_28;
  
  memset(&local_78,0,0x60);
  cVar6 = '\0';
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_78 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_78 = 0xffffffff;
  }
  else {
    local_78 = *(undefined4 *)(WdfStructures + 0x108);
  }
  local_74 = 2;
  local_68 = EvtIoQueueIoDefaultThunk;
  local_28 = 0xffffffff;
  local_b4 = 0;
  local_a8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_b8 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_b8 = 0xffffffff;
  }
  else {
    local_b8 = *(undefined4 *)(WdfStructures + 0x130);
  }
  local_88 = PTR__WDF_ReceiveQueue_TYPE_INFO_1400090c0;
  local_a0 = 1;
  local_b0 = GetContextFromObject;
  local_9c = 1;
  local_res8 = (WDFQUEUE__ *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)param_1,&local_78,&local_b8,&local_res8);
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar6 = '\x01';
    }
    puVar7 = WPP_GLOBAL_Control;
    pRVar3 = Fdo::GetRecorderLog(param_1);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(puVar7 + 0x18),cVar6,*(undefined8 *)param_1,pRVar3,2,1,10,
               &WPP_2ff610a6053a331857203d83879ac13c_Traceguids,(char)*(undefined8 *)param_1,
               (char)iVar2);
  }
  else {
    pRVar4 = GetContextFromObject(local_res8);
    if (pRVar4 != (ReceiveQueue *)0x0) {
      lVar5 = (**(code **)(WdfFunctions_01031 + 0x660))(WdfDriverGlobals,pRVar4);
      pRVar4->_padding_ = lVar5;
      pRVar4->m_fdo = param_1;
      pRVar4->m_maxAclTransferLength = param_2;
      KeInitializeSpinLock(&pRVar4->m_pendingEventPacketCounterLock);
      pRVar4->m_pendingEventPacketCounter = 0;
      pRVar4->m_consecutiveIOFailures = (atomic<unsigned_int>)0x0;
    }
    pRVar1 = (param_3->_MyDat)._MyRealVal;
    (param_3->_MyDat)._MyRealVal = pRVar4;
    if (pRVar1 != (ReceiveQueue *)0x0) {
      (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,pRVar1->_padding_);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== Make @ 14000ebf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl TransmitQueue::Make(class Fdo & __ptr64,class utl::unique_ptr<class
   TransmitQueue,struct WdfCpp::Details::ObjectContextDeleter<class TransmitQueue> > & __ptr64) */

long __cdecl
TransmitQueue::Make(Fdo *param_1,
                   unique_ptr<TransmitQueue,WdfCpp::Details::ObjectContextDeleter<TransmitQueue>_>
                   *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  RECORDER_LOG__ *pRVar3;
  undefined8 *extraout_RAX;
  undefined8 uVar4;
  char cVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  void *local_res8;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined *local_88;
  undefined4 local_78;
  undefined8 local_74;
  code *local_68;
  undefined4 local_28;
  
  memset(&local_78,0,0x60);
  cVar5 = '\0';
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_78 = 0x60;
  }
  else if (WdfStructureCount < 0x22) {
    local_78 = 0xffffffff;
  }
  else {
    local_78 = *(undefined4 *)(WdfStructures + 0x108);
  }
  local_74 = 2;
  local_68 = EvtIoQueueIoDefaultThunk;
  local_28 = 0xffffffff;
  local_b4 = 0;
  local_a8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_b8 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_b8 = 0xffffffff;
  }
  else {
    local_b8 = *(undefined4 *)(WdfStructures + 0x130);
  }
  local_88 = PTR__WDF_TransmitQueue_TYPE_INFO_1400090e8;
  local_a0 = 1;
  local_b0 = WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,TransmitQueue,1>::
             EvtObjectContextCleanupThunk;
  local_9c = 1;
  local_res8 = (void *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01031 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)param_1,&local_78,&local_b8,&local_res8);
  if (iVar2 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar5 = '\x01';
    }
    puVar7 = WPP_GLOBAL_Control;
    pRVar3 = Fdo::GetRecorderLog(param_1);
    WPP_RECORDER_AND_TRACE_SF_qd
              (*(undefined8 *)(puVar7 + 0x18),cVar5,*(undefined8 *)param_1,pRVar3,2,1,10,
               &WPP_91be94ee4ad8322db47672e026161e26_Traceguids,(char)*(undefined8 *)param_1,
               (char)iVar2);
  }
  else {
    WdfCpp::ObjectContext<WDFQUEUE__*___ptr64,TransmitQueue,1>::EvtObjectContextCleanupThunk
              (local_res8);
    if (extraout_RAX == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)0x0;
    }
    else {
      uVar4 = (**(code **)(WdfFunctions_01031 + 0x660))(WdfDriverGlobals,extraout_RAX);
      *extraout_RAX = uVar4;
      extraout_RAX[1] = param_1;
      puVar6 = extraout_RAX;
    }
    puVar1 = *(undefined8 **)param_2;
    *(undefined8 **)param_2 = puVar6;
    if (puVar1 != (undefined8 *)0x0) {
      (**(code **)(WdfFunctions_01031 + 0x680))(WdfDriverGlobals,*puVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 14000edf0 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x14000ee53;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14000ee73;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14000ee87;
  return iVar6;
}



===== _tlgEnableCallback @ 14000eea0 =====

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



===== BthOpenKey @ 14000ef1c =====

void BthOpenKey(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\BthMini\\Parameters");
  local_38 = 0x30;
  local_30 = 0;
  local_28 = &local_48;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  ZwOpenKey(param_3,0xf003f,&local_38);
  return;
}



===== BthQueryKeyValueUlong @ 14000ef9c =====

undefined8
BthQueryKeyValueUlong(undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined8 local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res10 = param_2;
  RtlInitUnicodeString(&local_18,L"BthMiniVerifierDisable");
  local_res10 = CONCAT44(local_res10._4_4_,0x13);
  uVar1 = ZwQueryValueKey(param_1,&local_18,2,param_3,0x13,&local_res10);
  if (-1 < (int)uVar1) {
    if (*(int *)(param_3 + 4) == 4) {
      *param_4 = *(undefined4 *)(param_3 + 0xc);
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  return uVar1;
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

int DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2,undefined *param_3)

{
  uint uVar1;
  uint uVar2;
  uchar uVar3;
  int iVar4;
  undefined8 uVar5;
  char cVar6;
  char cVar7;
  undefined8 in_stack_ffffffffffffff28;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined *puStack_90;
  undefined4 local_88;
  undefined4 local_84;
  code *local_80;
  code *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined8 local_28;
  undefined8 uStack_20;
  
  _DAT_140009378 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140009358 = &WPP_ThisDir_CTLGUID_bthmini;
  DAT_140009360 = 0;
  _DAT_140009370 = 0;
  cVar7 = '\x01';
  _DAT_140009390 = 0;
  _DAT_140009398 = 0;
  WppLoadTracingSupport();
  _DAT_140009370 = 0;
  WppInitKm(param_1,param_2);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
     (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
    cVar6 = '\0';
  }
  WPP_RECORDER_AND_TRACE_SF_
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,param_3,
             *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,2,10);
  RefObj_GlobalsInit();
  McGenEventRegister_EtwRegister();
  local_98 = 0;
  puStack_90 = (undefined *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_a8,0);
    iVar4 = IoQueryFullDriverPath(param_1,&local_a8);
    if (-1 < iVar4) {
      param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      iVar4 = RtlUnicodeStringToAnsiString(&local_98,&local_a8);
      ExFreePoolWithTag(uStack_a0,0);
      if (-1 < iVar4) {
        uVar1 = (uint)(ushort)local_98;
        do {
          uVar2 = uVar1;
          uVar1 = uVar2 - 1;
          if (uVar1 == 0) goto LAB_1400101d1;
          param_3 = puStack_90;
        } while (puStack_90[uVar1] != '\\');
        if (uVar1 != (ushort)local_98) {
          local_68 = 0;
          uStack_60 = 0;
          RtlInitAnsiString(&local_68,puStack_90 + uVar2);
          local_28 = local_68;
          uStack_20 = uStack_60;
          uVar5 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_28);
          iVar4 = (int)uVar5;
        }
LAB_1400101d1:
        RtlFreeAnsiString(&local_98);
        if (-1 < iVar4) goto LAB_14001022e;
      }
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 3)) {
      cVar6 = '\0';
    }
    param_3 = &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids;
    in_stack_ffffffffffffff28 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff28 >> 8),3);
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,
               &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xb,
               &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,(char)iVar4);
  }
LAB_14001022e:
  iVar4 = MmIsDriverVerifying(param_1);
  if ((iVar4 != 0) && (uVar3 = BthVerif_IsBthVerifDisabled(), uVar3 == '\0')) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) ||
       (cVar6 = '\x01', (byte)WPP_GLOBAL_Control[0x29] < 4)) {
      cVar6 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar6,param_3,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_stack_ffffffffffffff28,2,0xc);
    g_bthVerifierOn = 0xffffff;
  }
  local_84 = 0;
  local_70 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_88 = 0x20;
  }
  else if (WdfStructureCount < 0x19) {
    local_88 = 0xffffffff;
  }
  else {
    local_88 = *(undefined4 *)(WdfStructures + 0xc0);
  }
  local_6c = 0x4e494d42;
  local_80 = BthMini_WdfDeviceAdd;
  local_78 = BthMini_WdfDriverUnload;
  iVar4 = (**(code **)(WdfFunctions_01031 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0,&local_88,0);
  if (iVar4 < 0) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2)) {
      cVar7 = '\0';
    }
    WPP_RECORDER_AND_TRACE_SF_d
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),cVar7,WPP_GLOBAL_Control,
               *(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd,
               &WPP_834d457208c931bce4a8b3974b76bf2d_Traceguids,(char)iVar4);
  }
  else {
    local_58 = BthMini_GetCapabilities;
    local_50 = BthMini_ScoValidateChannel;
    local_48 = BthMini_ScoAddChannel;
    local_40 = BthMini_ScoRemoveChannel;
    local_38 = BthMini_ScoControlChannel;
    iVar4 = (*DAT_1400092e0)(BthDriverGlobals,param_1,param_2,&local_58,0x28);
    if (-1 < iVar4) {
      return iVar4;
    }
  }
  BthMini_DriverUnload(param_1);
  return iVar4;
}


