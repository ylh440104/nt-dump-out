
===== _SerCx2SystemDmaReceiveCleanupTransactionComplete @ 1c0001010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaReceiveCleanupTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMARECEIVE__ * __ptr64) */

void __cdecl
_SerCx2SystemDmaReceiveCleanupTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMARECEIVE__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x65,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b08);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78071)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x66,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== StateMachineEngine_EvtOnPassive @ 1c00010e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl StateMachineEngine_EvtOnPassive(struct WDFWORKITEM__ * __ptr64) */

void __cdecl StateMachineEngine_EvtOnPassive(WDFWORKITEM__ *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_SM_ENGINE_WORKITEM_CONTEXT_TYPE_INFO_1c0023b30);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)*puVar1,0xebe0000f);
  return;
}



===== _SerCx2PioTransmitPurgeFifoComplete @ 1c0001130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioTransmitPurgeFifoComplete(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2PIOTRANSMIT__ * __ptr64,unsigned long) */

void __cdecl
_SerCx2PioTransmitPurgeFifoComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIOTRANSMIT__ *param_2,ulong param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffd8 = &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x18,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  puVar6 = PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x68);
  uVar2 = *(uint *)(lVar1 + 0x20);
  if (uVar2 < param_3) {
    uVar5 = 0;
    Verifier_DbgBreak("Invalid number of bytes purged",0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(*(longlong *)(lVar3 + 0x10) + 0x410),uVar5,puVar6,0x19,
                         in_stack_ffffffffffffffd8,(char)param_3,(char)*(undefined4 *)(lVar1 + 0x20)
                        );
    }
    uVar2 = *(uint *)(lVar1 + 0x20);
    param_3 = uVar2;
  }
  uVar4 = *(int *)(lVar1 + 0x18) - param_3;
  *(uint *)(lVar1 + 0x18) = uVar4;
  *(uint *)(lVar1 + 0x20) = uVar2 - param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(*(longlong *)(lVar3 + 0x10) + 0x410),(ulonglong)uVar4,puVar6
                        ,0x1a,in_stack_ffffffffffffffd8,(char)lVar3,(char)param_3,(char)uVar4);
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar3 + 0x10) + 0x78),0xebe78201)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Receive_EvtDmaCompletion @ 1c00012b0 =====

/* void __cdecl Receive_EvtDmaCompletion(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
Receive_EvtDmaCompletion
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3c,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  *(DMA_COMPLETION_STATUS *)(*(longlong *)((longlong)param_3 + 0x20) + 0x94) = param_5;
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)((longlong)param_3 + 0x78),0xebe78180);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3d,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2PioTransmitReady @ 1c0001370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioTransmitReady(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2PIOTRANSMIT__ * __ptr64) */

void __cdecl _SerCx2PioTransmitReady(_WDF_DRIVER_GLOBALS *param_1,SERCX2PIOTRANSMIT__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x10,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78041)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x11,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2SystemDmaReceiveInitializeTransactionComplete @ 1c0001450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaReceiveInitializeTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMARECEIVE__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2SystemDmaReceiveInitializeTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMARECEIVE__ *param_2,uchar param_3)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,99,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b08);
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),
             (-(uint)(param_3 != '\0') & 0x50) + 0xebe78021);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,100,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2CustomTransmitTransactionCleanupComplete @ 1c0001540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomTransmitTransactionCleanupComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMTRANSMITTRANSACTION__ * __ptr64) */

void __cdecl
_SerCx2CustomTransmitTransactionCleanupComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMTRANSMITTRANSACTION__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7f,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_TRANSMIT_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023ce0);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),0xebe78071)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x80,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2CustomReceiveTransactionCleanupComplete @ 1c0001620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomReceiveTransactionCleanupComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMRECEIVETRANSACTION__ * __ptr64) */

void __cdecl
_SerCx2CustomReceiveTransactionCleanupComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMRECEIVETRANSACTION__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x7e,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),0xebe78071)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x7f,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Transfer_EvtRequestCancel @ 1c0001700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transfer_EvtRequestCancel(struct WDFREQUEST__ * __ptr64) */

void __cdecl Transfer_EvtRequestCancel(WDFREQUEST__ *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x26,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023d08);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qcq(*(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x3d8));
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x40),0xebe78210)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x28,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_CustomTransactionComplete @ 1c0001830 =====

/* long __cdecl Receive_CustomTransactionComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl Receive_CustomTransactionComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  _SM_ENGINE_EVENT _Var4;
  
  lVar3 = *(longlong *)(*(longlong *)((longlong)param_3 + 0x30) + 0x68);
  if ((ulonglong)*(uint *)(lVar3 + 0x24) < *(ulonglong *)(param_2 + 0x38)) {
    Verifier_DbgBreak("Memory Corruption: Transferred More bytes that requested",3);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar3 + 0x24);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  iVar2 = *(int *)(param_2 + 0x38);
  *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + iVar2;
  *(int *)(lVar3 + 0x20) = iVar2;
  if (iVar1 < 0) {
    if (iVar1 == -0x3ffffee0) {
      _Var4 = 0xebe78240;
    }
    else {
      *(int *)(lVar3 + 4) = iVar1;
      _Var4 = 0xebe78250;
    }
  }
  else {
    _Var4 = 0xebe78260;
  }
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)((longlong)param_3 + 0x30) + 0x78),_Var4);
  return -0x3fffffea;
}



===== Transmit_CustomTransactionComplete @ 1c00018d0 =====

/* long __cdecl Transmit_CustomTransactionComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl Transmit_CustomTransactionComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  _SM_ENGINE_EVENT _Var5;
  
  uVar4 = *(ulonglong *)(param_2 + 0x38);
  lVar3 = *(longlong *)(*(longlong *)((longlong)param_3 + 0x30) + 0x68);
  if (*(uint *)(lVar3 + 0x24) < uVar4) {
    Verifier_DbgBreak("Transferred More bytes that requested",2);
    uVar2 = *(uint *)(lVar3 + 0x24);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
    uVar4 = (ulonglong)uVar2;
  }
  iVar1 = *(int *)(param_2 + 0x30);
  *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + (int)uVar4;
  *(int *)(lVar3 + 0x20) = (int)uVar4;
  if (iVar1 < 0) {
    if (iVar1 == -0x3ffffee0) {
      _Var5 = 0xebe78240;
    }
    else {
      *(int *)(lVar3 + 4) = iVar1;
      _Var5 = 0xebe78250;
    }
  }
  else {
    _Var5 = 0xebe78260;
  }
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)((longlong)param_3 + 0x30) + 0x78),_Var5);
  return -0x3fffffea;
}



===== Transmit_EvtIoWrite @ 1c0001970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_EvtIoWrite(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64) */

void __cdecl Transmit_EvtIoWrite(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  _IRP *p_Var4;
  undefined8 uVar5;
  undefined8 uVar6;
  WDFREQUEST__ *pWVar7;
  undefined2 uVar8;
  undefined8 local_res20;
  
  local_res20 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x25,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSMIT_CONTEXT_TYPE_INFO_1c0023d80);
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023d08);
  if (g_SerCx2DriverContext[0x28] != (_SERCX_DRIVER_CONTEXT)0x0) {
    p_Var4 = (_IRP *)(**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    Etw_GetActivityId(p_Var4,'\x01',(_GUID *)(lVar2 + 0x58));
    if ((DAT_1c0025a81 & 1) != 0) {
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_2);
      uVar6 = WdfDriverGlobals;
      uVar5 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar5);
      McTemplateK0px_EtwWriteTransfer
                (uVar6,&SerCx2EtwEventTransmitIoStart,lVar2 + 0x58,uVar5,(char)param_3);
    }
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,1,&local_res20,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x26;
LAB_1c0001c85:
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x410),2,5,uVar8,
                        &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)iVar1);
    }
  }
  else {
    pWVar7 = param_2;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x878))(WdfDriverGlobals);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x27;
        goto LAB_1c0001c85;
      }
    }
    else {
      if (param_3 < 0x3b9aca01) {
        *puVar3 = 0x6e617254;
        puVar3[1] = local_res20;
        puVar3[2] = 0;
        puVar3[6] = lVar2 + 0x38;
        *(int *)((longlong)puVar3 + 0x1c) = (int)param_3;
        *(undefined4 *)(puVar3 + 3) = 0;
        *(undefined4 *)(puVar3 + 4) = 0;
        *(WDFREQUEST__ **)(lVar2 + 0x50) = param_2;
        *(undefined8 **)(lVar2 + 0x68) = puVar3;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqqd
                    (*(undefined8 *)(lVar2 + 0x410),pWVar7,5,0x29,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)param_2,0,
                     (char)local_res20,(char)param_3);
        }
        StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(lVar2 + 0x78),0xebe780a0);
        goto LAB_1c0001aed;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x410),2,5,0x28,
                          &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,0);
      }
      iVar1 = -0x3ffffff3;
    }
  }
  Etw_TransmitIoStop(param_2,iVar1,0);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
LAB_1c0001aed:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2a,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2PioTransmitCleanupTransactionComplete @ 1c0001d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioTransmitCleanupTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2PIOTRANSMIT__ * __ptr64) */

void __cdecl
_SerCx2PioTransmitCleanupTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIOTRANSMIT__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x14,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78071)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x15,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Receive_EvtIoRead @ 1c0001de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_EvtIoRead(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned
   __int64) */

void __cdecl Receive_EvtIoRead(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  _IRP *p_Var5;
  undefined8 uVar6;
  undefined8 uVar7;
  WDFREQUEST__ *pWVar8;
  undefined8 local_res20;
  
  local_res20 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x52,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RECEIVE_CONTEXT_TYPE_INFO_1c0023a68);
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023d08);
  uVar1 = *(undefined8 *)(lVar3 + 0x410);
  if (g_SerCx2DriverContext[0x28] != (_SERCX_DRIVER_CONTEXT)0x0) {
    p_Var5 = (_IRP *)(**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    Etw_GetActivityId(p_Var5,'\x01',(_GUID *)(lVar3 + 0x58));
    if ((DAT_1c0025a81 & 4) != 0) {
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_2);
      uVar7 = WdfDriverGlobals;
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar6);
      McTemplateK0px_EtwWriteTransfer
                (uVar7,&SerCx2EtwEventReceiveIoStart,lVar3 + 0x58,uVar6,(char)param_3);
    }
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,1,&local_res20,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(uVar1,2,7,0x53,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)iVar2)
      ;
    }
  }
  else {
    pWVar8 = param_2;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x880))(WdfDriverGlobals);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(uVar1,2,7,0x54,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                          (char)iVar2);
      }
    }
    else {
      if (param_3 < 0x3b9aca01) {
        *puVar4 = 0x6e617254;
        puVar4[1] = local_res20;
        puVar4[2] = 0;
        puVar4[6] = lVar3 + 0x38;
        *(int *)((longlong)puVar4 + 0x1c) = (int)param_3;
        *(undefined4 *)(puVar4 + 3) = 0;
        *(undefined4 *)(puVar4 + 4) = 0;
        *(WDFREQUEST__ **)(lVar3 + 0x50) = param_2;
        *(undefined8 **)(lVar3 + 0x68) = puVar4;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqqd
                    (uVar1,pWVar8,7,0x56,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                     (char)param_2,0,(char)local_res20,(char)param_3);
        }
        StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(lVar3 + 0x78),0xebe780a0);
        goto LAB_1c0001f16;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(uVar1,2,7,0x55,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,0);
      }
      iVar2 = -0x3ffffff3;
    }
  }
  Etw_ReceiveIoStop(param_2,iVar2,0);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
LAB_1c0001f16:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x57,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Etw_ReceiveIoStop @ 1c0002190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Etw_ReceiveIoStop(struct WDFREQUEST__ * __ptr64,long,unsigned __int64) */

void __cdecl Etw_ReceiveIoStop(WDFREQUEST__ *param_1,long param_2,__uint64 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
  iVar1 = IoGetActivityIdIrp(uVar2,&local_28);
  if ((DAT_1c0025a81 & 4) != 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_1);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar2);
    puVar3 = &local_28;
    if (iVar1 < 0) {
      puVar3 = (undefined8 *)0x0;
    }
    McTemplateK0pdx_EtwWriteTransfer
              (0,&SerCx2EtwEventReceiveIoStop,puVar3,uVar2,(char)param_2,(char)param_3);
  }
  return;
}



===== _SerCx2PioTransmitInitializeTransactionComplete @ 1c00022a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioTransmitInitializeTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2PIOTRANSMIT__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2PioTransmitInitializeTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIOTRANSMIT__ *param_2,uchar param_3)

{
  longlong lVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x12,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58);
  _Var2 = 0xebe78071;
  if (param_3 == '\0') {
    _Var2 = 0xebe78021;
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),_Var2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x13,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2PioTransmitDrainFifoComplete @ 1c00023a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioTransmitDrainFifoComplete(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2PIOTRANSMIT__ * __ptr64) */

void __cdecl
_SerCx2PioTransmitDrainFifoComplete(_WDF_DRIVER_GLOBALS *param_1,SERCX2PIOTRANSMIT__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x16,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe781f1)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x17,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2PioReceiveInitializeTransactionComplete @ 1c0002480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioReceiveInitializeTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2PIORECEIVE__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2PioReceiveInitializeTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIORECEIVE__ *param_2,uchar param_3)

{
  longlong lVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x12,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68);
  if (*(char *)(lVar1 + 0x50) == '\0') {
    if (param_3 == '\0') {
      _Var2 = 0xebe78021;
    }
    else {
      _Var2 = 0xebe78071;
    }
    StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),_Var2);
  }
  else {
    *(uchar *)(lVar1 + 0x51) = param_3;
    KeSetEvent(lVar1 + 0x58,0,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x13,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2PioReceiveCleanupTransactionComplete @ 1c00025a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioReceiveCleanupTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2PIORECEIVE__ * __ptr64) */

void __cdecl
_SerCx2PioReceiveCleanupTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIORECEIVE__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x14,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68);
  if (*(char *)(lVar1 + 0x50) == '\0') {
    StateMachineEngine_EventAdd
              ((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78071);
  }
  else {
    KeSetEvent(lVar1 + 0x58,0,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x15,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2CustomReceiveTransactionReportProgress @ 1c00026a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomReceiveTransactionReportProgress(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMRECEIVETRANSACTION__ * __ptr64,enum
   _SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS) */

void __cdecl
_SerCx2CustomReceiveTransactionReportProgress
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMRECEIVETRANSACTION__ *param_2,
          _SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS param_3)

{
  longlong lVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x82,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
  if (param_3 == 0) {
    _Var2 = 0xebe782b1;
  }
  else {
    if (param_3 != 1) {
      Verifier_DbgBreak("Assert Failed: Progress == SerCx2CustomReceiveTransactionBytesTransferred",
                        0);
    }
    *(undefined1 *)(lVar1 + 0x68) = 1;
    _Var2 = 0xebe782a1;
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),_Var2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x83,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2PioReceiveReady @ 1c00027c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2PioReceiveReady(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2PIORECEIVE__ * __ptr64) */

void __cdecl _SerCx2PioReceiveReady(_WDF_DRIVER_GLOBALS *param_1,SERCX2PIORECEIVE__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x10,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78041)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x11,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Transfer_TimerFired @ 1c00028a0 =====

/* void __cdecl Transfer_TimerFired(void * __ptr64,struct _SERCX_TIMER_PRIVCONTEXT * __ptr64,enum
   _TIMEOUT_TYPE) */

void __cdecl
Transfer_TimerFired(void *param_1,_SERCX_TIMER_PRIVCONTEXT *param_2,_TIMEOUT_TYPE param_3)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x32,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe780b0;
  if (param_3 != 0) {
    _Var1 = 0xebe780c0;
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)((longlong)param_1 + 0x40),_Var1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x33,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== StateMachineEngine_EventAdd @ 1c0002970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl StateMachineEngine_EventAdd(struct _SM_ENGINE_CONTEXT * __ptr64,enum
   _SM_ENGINE_EVENT) */

void __cdecl StateMachineEngine_EventAdd(_SM_ENGINE_CONTEXT *param_1,_SM_ENGINE_EVENT param_2)

{
  _SM_ENGINE_CONTEXT *p_Var1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  char cVar9;
  _SM_ENGINE_CONTEXT _Var10;
  uint uVar11;
  int iVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  code *pcVar15;
  _SM_ENGINE_CONTEXT _Var16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int local_res8;
  char local_res10;
  code *local_res18;
  
  local_res18 = (code *)0x0;
  puVar17 = (undefined4 *)0x0;
  cVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(_SM_ENGINE_EVENT *)(param_1 + (ulonglong)(byte)param_1[0x379] * 4 + 0x278) = param_2;
  param_1[0x379] = (_SM_ENGINE_CONTEXT)((char)param_1[0x379] + 1U & 0x3f);
  if (*(code **)(param_1 + 0x380) != (code *)0x0) {
    (**(code **)(param_1 + 0x380))(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),param_2);
  }
  puVar19 = *(undefined4 **)(param_1 + 0x20);
  if (param_2 == 0xebe0000f) {
    if ((param_1[0x37b] == (_SM_ENGINE_CONTEXT)0x0) || (param_1[0x37a] == (_SM_ENGINE_CONTEXT)0x0))
    {
      *(int *)(param_1 + 0x37c) = *(int *)(param_1 + 0x37c) + 1;
      goto LAB_1c0003044;
    }
  }
  else {
    *(_SM_ENGINE_EVENT *)(param_1 + (ulonglong)(byte)param_1[0x6d] * 4 + 0x2c) = param_2;
    param_1[0x6d] = (_SM_ENGINE_CONTEXT)((char)param_1[0x6d] + 1U & 0xf);
    if (param_1[0x37a] == (_SM_ENGINE_CONTEXT)0x1) {
LAB_1c0003044:
      KeReleaseSpinLock(param_1 + 0x18,cVar9);
      return;
    }
    param_1[0x37a] = (_SM_ENGINE_CONTEXT)0x1;
  }
  KeReleaseSpinLock(param_1 + 0x18,cVar9);
  (**(code **)(WdfFunctions_01015 + 0x668))
            (WdfDriverGlobals,*(undefined8 *)param_1,StateMachineEngine_EventAdd,0x1fb,
             "onecore\\drivers\\serial\\sercx2\\statemachineengine\\statemachineengine.cpp");
  local_res10 = cVar9;
  if (param_2 == 0xebe0000f) {
    uVar3 = *puVar19;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = uVar3;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = 0xebe0000f;
    param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
    if (*(code **)(param_1 + 0x388) != (code *)0x0) {
      (**(code **)(param_1 + 0x388))
                (*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),0x57a70000,0xebe0000f,uVar3);
    }
    param_1[0x37b] = (_SM_ENGINE_CONTEXT)0x0;
    iVar12 = (**(code **)(puVar19 + 2))(*(undefined8 *)(param_1 + 8));
  }
  else {
    iVar12 = 0;
  }
  do {
    puVar18 = puVar17;
LAB_1c0002a8a:
    if (iVar12 == 0) {
      cVar9 = KeAcquireSpinLockRaiseToDpc();
      uVar13 = (ulonglong)(byte)param_1[0x6c];
      local_res8 = 0;
      while( true ) {
        _Var16 = SUB81(uVar13,0);
        if (_Var16 == param_1[0x6d]) break;
        uVar5 = puVar19[4];
        uVar6 = *(uint *)(param_1 + uVar13 * 4 + 0x2c);
        uVar11 = uVar6 & 0xf;
        if ((uVar5 & 8) == 0) {
          if (uVar11 == 3) {
LAB_1c0002bfb:
            puVar18 = (undefined4 *)0x0;
            local_res18 = (code *)0x0;
            uVar14 = 0;
            goto LAB_1c0002c0f;
          }
          if (uVar11 == 1) {
            if ((uVar5 & 0x10) == 0) goto LAB_1c0002bfb;
          }
          else if ((uVar11 == 0) && ((uVar5 & 1) != 0)) goto LAB_1c0002bfb;
LAB_1c0002e1a:
          uVar13 = (ulonglong)(byte)((char)_Var16 + 1) & 0xffffffffffffff0f;
        }
        else {
          puVar18 = (undefined4 *)0x0;
          local_res18 = (code *)0x0;
          uVar14 = 0;
          while( true ) {
            uVar5 = *(uint *)(*(longlong *)(puVar19 + 6) + uVar14 * 0x10);
            if (uVar5 == 0) break;
            if (uVar5 == uVar6) {
              pcVar15 = *(code **)(*(longlong *)(puVar19 + 6) + 8 + uVar14 * 0x10);
              uVar3 = *puVar19;
              *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = uVar3;
              *(uint *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = uVar6;
              param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
              if (*(code **)(param_1 + 0x388) != (code *)0x0) {
                (**(code **)(param_1 + 0x388))
                          (*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,uVar3);
              }
              if (pcVar15 != (code *)0x0) goto LAB_1c0003111;
              break;
            }
            uVar14 = (ulonglong)((int)uVar14 + 1);
          }
          puVar8 = *(uint **)(puVar19 + 8);
          uVar14 = 0;
          uVar5 = *puVar8;
          while ((uVar5 != 0 && (uVar5 != uVar6))) {
            uVar14 = (ulonglong)((int)uVar14 + 1);
            uVar5 = puVar8[uVar14 * 2];
          }
          p_Var1 = param_1 + 0x378;
          if (puVar8[uVar14 * 2] != 0) {
            uVar3 = *puVar19;
            puVar17 = *(undefined4 **)
                       (*(longlong *)(param_1 + 0x10) + (ulonglong)puVar8[uVar14 * 2 + 1] * 8);
            uVar4 = *puVar17;
            *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = uVar4;
            *(uint *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = uVar6;
            *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
            pcVar15 = *(code **)(param_1 + 0x388);
            if (pcVar15 != (code *)0x0) {
              (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,uVar4);
            }
            if (puVar17 != (undefined4 *)0x0) goto LAB_1c0003121;
          }
          uVar3 = *puVar19;
          *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = 0x57a70def;
          *(uint *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = uVar6;
          *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
          pcVar15 = *(code **)(param_1 + 0x388);
          if (pcVar15 == (code *)0x0) goto LAB_1c0002e1a;
          (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,0x57a70def);
          uVar13 = (ulonglong)(byte)((char)_Var16 + 1) & 0xffffffffffffff0f;
        }
      }
      goto LAB_1c0002cf4;
    }
    puVar18 = (undefined4 *)0x0;
    local_res18 = (code *)0x0;
    uVar13 = 0;
    while( true ) {
      iVar2 = *(int *)(*(longlong *)(puVar19 + 6) + uVar13 * 0x10);
      if (iVar2 == 0) break;
      if (iVar2 == iVar12) {
        pcVar15 = *(code **)(*(longlong *)(puVar19 + 6) + 8 + uVar13 * 0x10);
        *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = *puVar19;
        *(int *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = iVar12;
        param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
        if (*(code **)(param_1 + 0x388) != (code *)0x0) {
          (**(code **)(param_1 + 0x388))();
        }
        if (pcVar15 != (code *)0x0) {
          local_res18 = pcVar15;
          goto LAB_1c00031bd;
        }
        break;
      }
      uVar13 = (ulonglong)((int)uVar13 + 1);
    }
    piVar7 = *(int **)(puVar19 + 8);
    uVar13 = 0;
    iVar2 = *piVar7;
    while ((iVar2 != 0 && (iVar2 != iVar12))) {
      uVar13 = (ulonglong)((int)uVar13 + 1);
      iVar2 = piVar7[uVar13 * 2];
    }
    p_Var1 = param_1 + 0x378;
    if (piVar7[uVar13 * 2] != 0) {
      uVar3 = *puVar19;
      puVar17 = *(undefined4 **)
                 (*(longlong *)(param_1 + 0x10) + (ulonglong)(uint)piVar7[uVar13 * 2 + 1] * 8);
      uVar4 = *puVar17;
      *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = uVar4;
      *(int *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = iVar12;
      *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
      pcVar15 = *(code **)(param_1 + 0x388);
      if (pcVar15 != (code *)0x0) {
        (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,iVar12,uVar4);
      }
      cVar9 = local_res10;
      if (puVar17 == (undefined4 *)0x0) goto LAB_1c0002b4a;
      goto LAB_1c0002dd7;
    }
LAB_1c0002b4a:
    uVar3 = *puVar19;
    *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = 0x57a70bad;
    *(int *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = iVar12;
    *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
    pcVar15 = *(code **)(param_1 + 0x388);
    puVar17 = puVar18;
    if (pcVar15 == (code *)0x0) {
      goto LAB_1c0002dcc;
    }
    (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,iVar12,0x57a70bad);
LAB_1c0002b8e:
    iVar12 = 0;
    *(int *)(param_1 + 0x37c) = *(int *)(param_1 + 0x37c) + 1;
  } while( true );
LAB_1c0002c0f:
  uVar5 = *(uint *)(*(longlong *)(puVar19 + 6) + uVar14 * 0x10);
  if (uVar5 == 0) goto LAB_1c0002c32;
  if (uVar5 == uVar6) {
    pcVar15 = *(code **)(*(longlong *)(puVar19 + 6) + 8 + uVar14 * 0x10);
    uVar3 = *puVar19;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = uVar3;
    *(uint *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = uVar6;
    param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
    if (*(code **)(param_1 + 0x388) != (code *)0x0) {
      (**(code **)(param_1 + 0x388))
                (*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,uVar3);
    }
    if (pcVar15 != (code *)0x0) goto LAB_1c0003111;
    goto LAB_1c0002c32;
  }
  uVar14 = (ulonglong)((int)uVar14 + 1);
  goto LAB_1c0002c0f;
LAB_1c0003111:
  puVar18 = (undefined4 *)0x0;
  local_res18 = pcVar15;
  goto LAB_1c0002cfc;
LAB_1c0002c32:
  puVar8 = *(uint **)(puVar19 + 8);
  uVar14 = 0;
  uVar5 = *puVar8;
  while ((uVar5 != 0 && (uVar5 != uVar6))) {
    uVar14 = (ulonglong)((int)uVar14 + 1);
    uVar5 = puVar8[uVar14 * 2];
  }
  p_Var1 = param_1 + 0x378;
  if (puVar8[uVar14 * 2] != 0) {
    uVar3 = *puVar19;
    puVar17 = *(undefined4 **)
               (*(longlong *)(param_1 + 0x10) + (ulonglong)puVar8[uVar14 * 2 + 1] * 8);
    uVar4 = *puVar17;
    *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = uVar4;
    *(uint *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = uVar6;
    *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
    pcVar15 = *(code **)(param_1 + 0x388);
    if (pcVar15 != (code *)0x0) {
      (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,uVar4);
    }
    if (puVar17 != (undefined4 *)0x0) {
LAB_1c0003121:
      local_res18 = (code *)0x0;
      puVar18 = puVar17;
LAB_1c0002cf4:
      goto LAB_1c0002cfc;
    }
  }
  uVar3 = *puVar19;
  *(undefined4 *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x7c) = 0x57a70bad;
  *(uint *)(param_1 + (ulonglong)(byte)*p_Var1 * 8 + 0x78) = uVar6;
  *p_Var1 = (_SM_ENGINE_CONTEXT)((char)*p_Var1 + 1U & 0x3f);
  pcVar15 = *(code **)(param_1 + 0x388);
  if (pcVar15 != (code *)0x0) {
    (*pcVar15)(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,uVar6,0x57a70bad);
  }
LAB_1c0002cfc:
  if (_Var16 != param_1[0x6d]) {
    local_res8 = *(int *)(param_1 + uVar13 * 4 + 0x2c);
    _Var10 = param_1[0x6c];
    if (_Var16 != _Var10) {
      do {
        uVar14 = (ulonglong)(byte)((char)uVar13 - 1) & 0xffffffffffffff0f;
        *(undefined4 *)(param_1 + uVar13 * 4 + 0x2c) =
             *(undefined4 *)(param_1 + (ulonglong)((int)uVar13 - 1U & 0xf) * 4 + 0x2c);
        _Var10 = param_1[0x6c];
        uVar13 = uVar14;
      } while (SUB81(uVar14,0) != _Var10);
    }
    *(undefined4 *)(param_1 + (ulonglong)(byte)_Var10 * 4 + 0x2c) = 0;
    param_1[0x6c] = (_SM_ENGINE_CONTEXT)((char)param_1[0x6c] + 1U & 0xf);
  }
  if (local_res8 == 0) {
    param_1[0x37a] = (_SM_ENGINE_CONTEXT)0x0;
    KeReleaseSpinLock(param_1 + 0x18,cVar9);
  }
  else {
    KeReleaseSpinLock(param_1 + 0x18);
    puVar17 = puVar18;
    local_res10 = cVar9;
    if (local_res18 != (code *)0x0) {
LAB_1c00031bd:
      (*local_res18)(*(undefined8 *)(param_1 + 8));
      iVar12 = 0;
      goto LAB_1c0002a8a;
    }
LAB_1c0002dcc:
    if (puVar17 == (undefined4 *)0x0) goto LAB_1c0002b8e;
LAB_1c0002dd7:
    iVar12 = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar17;
    puVar18 = puVar17;
    puVar19 = puVar17;
    if (*(code **)(puVar17 + 2) == (code *)0x0) goto LAB_1c0002a8a;
    if (((puVar17[4] & 2) == 0) || (cVar9 == '\0')) {
      iVar12 = (**(code **)(puVar17 + 2))(*(undefined8 *)(param_1 + 8));
      goto LAB_1c0002a8a;
    }
    param_1[0x37b] = (_SM_ENGINE_CONTEXT)0x1;
    uVar3 = *puVar17;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = 0x57a70000;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = 0xebe00010;
    param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
    if (*(code **)(param_1 + 0x388) != (code *)0x0) {
      (**(code **)(param_1 + 0x388))
                (*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),uVar3,0xebe00010,0x57a70000);
    }
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x70));
  }
  (**(code **)(WdfFunctions_01015 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)param_1,StateMachineEngine_EventAdd,0x276,
             "onecore\\drivers\\serial\\sercx2\\statemachineengine\\statemachineengine.cpp");
  return;
}



===== Etw_TransmitIoStop @ 1c00031f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Etw_TransmitIoStop(struct WDFREQUEST__ * __ptr64,long,unsigned __int64) */

void __cdecl Etw_TransmitIoStop(WDFREQUEST__ *param_1,long param_2,__uint64 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
  iVar1 = IoGetActivityIdIrp(uVar2,&local_28);
  if ((DAT_1c0025a81 & 1) != 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_1);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar2);
    puVar3 = &local_28;
    if (iVar1 < 0) {
      puVar3 = (undefined8 *)0x0;
    }
    McTemplateK0pdx_EtwWriteTransfer
              (0,&SerCx2EtwEventTransmitIoStop,puVar3,uVar2,(char)param_2,(char)param_3);
  }
  return;
}



===== WPP_RECORDER_SF_qqqd @ 1c0003300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== Transfer_EtwWriteStateMachineTransition @ 1c0003490 =====

/* void __cdecl Transfer_EtwWriteStateMachineTransition(void * __ptr64,void * __ptr64,enum
   _SM_ENGINE_STATE,enum _SM_ENGINE_EVENT,enum _SM_ENGINE_STATE) */

void __cdecl
Transfer_EtwWriteStateMachineTransition
          (void *param_1,void *param_2,_SM_ENGINE_STATE param_3,_SM_ENGINE_EVENT param_4,
          _SM_ENGINE_STATE param_5)

{
  undefined *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar2 = (undefined1)param_3;
  uVar3 = (undefined1)param_4;
  if (*(char *)((longlong)param_2 + 0x10) == 'r') {
    if ((param_5 == 0x57a70bad) &&
       ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 0x40) != 0)) {
      McTemplateK0pddd_EtwWriteTransfer
                (param_1,&SerCx2EtwEventReceiveTransferStateMachineInvalidTransition,
                 (longlong)param_2 + 0x20,param_2,uVar2,uVar3,0xad);
    }
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 0x20) == 0) {
      return;
    }
    puVar1 = &SerCx2EtwEventReceiveTransferStateMachineTransition;
  }
  else {
    if ((param_5 == 0x57a70bad) &&
       ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 0x10) != 0)) {
      McTemplateK0pddd_EtwWriteTransfer
                (param_1,&SerCx2EtwEventTransmitTransferStateMachineInvalidTransition,
                 (longlong)param_2 + 0x20,param_2,uVar2,uVar3,0xad);
    }
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 8) == 0) {
      return;
    }
    puVar1 = &SerCx2EtwEventTransmitTransferStateMachineTransition;
  }
  McTemplateK0pddd_EtwWriteTransfer
            (param_1,puVar1,(longlong)param_2 + 0x20,param_2,uVar2,uVar3,(char)param_5);
  return;
}



===== TransferStateEntryFunc_StartPioTransaction @ 1c0003580 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartPioTransaction(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartPioTransaction(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (*(char *)((longlong)param_1 + 0x10) == 't') {
    _Var1 = Transmit_PioTransaction((_TRANSMIT_CONTEXT *)((longlong)param_1 + -0x38));
  }
  else {
    _Var1 = Receive_PioTransaction((_RECEIVE_CONTEXT *)((longlong)param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Receive_PioTransaction @ 1c0003600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Receive_PioTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Receive_PioTransaction(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  _SM_ENGINE_EVENT _Var4;
  uint uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar5 = *(int *)(lVar2 + 0x24) - *(int *)(lVar2 + 0x20);
  uVar3 = (**(code **)(lVar1 + 0x30))
                    (*(undefined8 *)(lVar1 + 8),
                     (ulonglong)*(uint *)(lVar2 + 0x18) + *(longlong *)(lVar2 + 8),uVar5);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qdd(*(undefined8 *)(*(longlong *)(lVar1 + 0x10) + 0x410),5,7,0x1c,
                        &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar1,(char)uVar5,
                        (char)uVar3);
  }
  if (uVar5 < uVar3) {
    Verifier_DbgBreak("Possible Memory corruption, Buffer Overflow",3);
    uVar3 = uVar5;
  }
  *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + uVar3;
  *(int *)(lVar2 + 0x20) = *(int *)(lVar2 + 0x20) + uVar3;
  if (uVar3 == 0) {
    _Var4 = 0xebe78302;
  }
  else {
    _Var4 = 0xebe782f2;
    if (uVar3 < uVar5) {
      _Var4 = 0xebe78312;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1d,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return _Var4;
}



===== Transmit_PioTransaction @ 1c0003780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_PioTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transmit_PioTransaction(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  _SM_ENGINE_EVENT _Var6;
  ulonglong uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x22,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar5 = *(int *)(lVar2 + 0x24) - *(int *)(lVar2 + 0x20);
  uVar7 = (ulonglong)uVar5;
  lVar4 = (ulonglong)*(uint *)(lVar2 + 0x18) + *(longlong *)(lVar2 + 8);
  uVar3 = (**(code **)(lVar1 + 0x30))(*(undefined8 *)(lVar1 + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(*(longlong *)(lVar1 + 0x10) + 0x410),lVar4,uVar7,0x23,
                        in_stack_ffffffffffffffc8,(char)lVar1,(char)uVar5,(char)uVar3);
  }
  if (uVar5 < uVar3) {
    Verifier_DbgBreak("Sent more than expected",2);
    uVar3 = uVar5;
  }
  *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + uVar3;
  *(int *)(lVar2 + 0x20) = *(int *)(lVar2 + 0x20) + uVar3;
  if (uVar3 == 0) {
    _Var6 = 0xebe78302;
  }
  else {
    _Var6 = 0xebe782f2;
    if (uVar3 < uVar5) {
      _Var6 = 0xebe78312;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x24,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return _Var6;
}



===== TransferStateEntryFunc_AcquirePowerReferenceAsync @ 1c0003900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_AcquirePowerReferenceAsync(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_AcquirePowerReferenceAsync(void *param_1)

{
  longlong lVar1;
  int iVar2;
  _SM_ENGINE_EVENT _Var3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x13,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)((longlong)param_1 + 0x30);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 0x10),0
                     ,0,0x11b,"onecore\\drivers\\serial\\sercx2\\sercx2\\sys\\transfer.cpp");
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)((longlong)param_1 + 0x3d8),2,6,0x14,
                        &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,(char)iVar2);
    }
    Verifier_DbgBreak("The client may have sent an IO in an invalid state",0);
    *(int *)(lVar1 + 4) = iVar2;
    _Var3 = 0xebe78082;
  }
  else if (iVar2 == 0x103) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)((longlong)param_1 + 0x3d8),4,6,0x15,
                       &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
    }
    _Var3 = 0xebe781d2;
  }
  else {
    _Var3 = 0xebe781e2;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x16,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var3;
}



===== TransferStateEntryFunc_InitTimer @ 1c0003a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitTimer(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitTimer(void *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  lVar3 = *(longlong *)((longlong)param_1 + 0x38);
  uVar1 = *(uint *)(*(longlong *)((longlong)param_1 + 0x30) + 0x1c);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x1d,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  uVar4 = (ulonglong)*(uint *)(lVar3 + 0x2c);
  uVar2 = *(uint *)(lVar3 + 0x30);
  uVar5 = (ulonglong)*(uint *)(lVar3 + 0x28);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  if ((((uVar5 == 0) || (*(int *)(lVar3 + 0x4c) != -0x14187c8e)) &&
      (uVar5 = 0x2de41353000, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
     && (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x60),5,0xd,0x1e,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  *(ulonglong *)(lVar3 + 0x38) = uVar5 * 10000;
  if (*(int *)(lVar3 + 0x4c) == -0x14187c8e) {
    uVar4 = (ulonglong)uVar2 * (ulonglong)uVar1 + uVar4;
LAB_1c0003b69:
    if (uVar4 != 0) goto LAB_1c0003b7e;
  }
  else if (*(int *)(lVar3 + 0x4c) == -0x14187c9e) goto LAB_1c0003b69;
  uVar4 = 0x2de41353000;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x60),4,0xd,0x1f,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
LAB_1c0003b7e:
  *(ulonglong *)(lVar3 + 0x40) = uVar4 * 10000 + _DAT_fffff78000000008;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x20,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return 0xebe78092;
}



===== WPP_RECORDER_SF_ @ 1c0003c90 =====

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



===== TransferStateEntryFunc_CustomReceiveTransactionQueryProgress2 @ 1c0003d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CustomReceiveTransactionQueryProgress2(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_CustomReceiveTransactionQueryProgress2(void *param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x82,
                       &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8b,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  (**(code **)(*(longlong *)((longlong)param_1 + -8) + 0x60))
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + -8) + 8));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8c,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x83,
                       &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
    }
  }
  return 0;
}



===== Timer_EvtHighResTimerFired @ 1c0003eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Timer_EvtHighResTimerFired(struct WDFTIMER__ * __ptr64) */

void __cdecl Timer_EvtHighResTimerFired(WDFTIMER__ *param_1)

{
  WDFTIMER__ *pWVar1;
  
  pWVar1 = (WDFTIMER__ *)(**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  Timer_EvtTimerFired(pWVar1);
  return;
}



===== Timer_EvtTimerFired @ 1c0003ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Timer_EvtTimerFired(struct WDFTIMER__ * __ptr64) */

void __cdecl Timer_EvtTimerFired(WDFTIMER__ *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x26,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_TIMER_PRIVCONTEXT_TYPE_INFO_1c0023d30);
  (**(code **)(lVar1 + 0x50))(*(undefined8 *)(lVar1 + 0x58),lVar1,*(undefined4 *)(lVar1 + 0x48));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x27,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_ChooseNextTransactionMode @ 1c0003fd0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ChooseNextTransactionMode(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ChooseNextTransactionMode(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x54,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x10) == 't') {
    _Var1 = Transmit_ChooseNextTransactionMode((_TRANSMIT_CONTEXT *)((longlong)param_1 + -0x38));
  }
  else {
    _Var1 = Receive_ChooseNextTransactionMode((_RECEIVE_CONTEXT *)((longlong)param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x55,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Receive_ChooseNextTransactionMode @ 1c0004090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Receive_ChooseNextTransactionMode(struct _RECEIVE_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Receive_ChooseNextTransactionMode(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  ulonglong uVar8;
  uint uVar9;
  _SM_ENGINE_EVENT _Var10;
  uint local_res8 [2];
  longlong local_res10;
  
  local_res8[0] = 0;
  local_res10 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x48,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar5 = *(uint *)(lVar1 + 0x20);
  if ((uVar5 != 0) && ((DAT_1c0025a81 & 8) != 0)) {
    uVar9 = *(uint *)(lVar1 + 0x18) - uVar5;
    McTemplateK0pxqdbr2_EtwWriteTransfer
              ((ulonglong)uVar9,&SerCx2EtwEventReceiveIoPayload,*(longlong *)(lVar1 + 0x30) + 0x20,
               *(undefined8 *)(lVar2 + 0x10),(char)uVar9,uVar5,(char)*(undefined4 *)(lVar1 + 0x28),
               (*(longlong *)(lVar1 + 8) - (ulonglong)uVar5) + (ulonglong)*(uint *)(lVar1 + 0x18));
  }
  iVar6 = *(int *)(lVar1 + 0x28);
  uVar5 = *(uint *)(lVar1 + 0x18);
  *(undefined4 *)(lVar1 + 0x28) = 0;
  *(undefined8 *)(lVar1 + 0x20) = 0;
  if (*(uint *)(lVar1 + 0x1c) <= uVar5) {
    _Var10 = 0xebe78322;
    goto LAB_1c0004171;
  }
  uVar9 = *(uint *)(lVar1 + 0x1c) - uVar5;
  lVar3 = *(longlong *)(param_1 + 0x28);
  lVar4 = *(longlong *)(param_1 + 0x20);
  if (g_ForcePioReceive != '\0') goto LAB_1c000415b;
  if (iVar6 != -0x14187c7e) {
    if (*(int *)(lVar1 + 4) != 0x102) {
LAB_1c0004138:
      if (*(code **)(lVar2 + 0x60) == (code *)0x0) {
LAB_1c0004145:
        if (lVar3 == 0) {
          if ((lVar4 == 0) || ((ulonglong)uVar9 < *(ulonglong *)(lVar4 + 0x30))) goto LAB_1c000415b;
          uVar8 = ((ulonglong)*(uint *)(lVar1 + 0x18) + *(longlong *)(lVar1 + 8)) %
                  (ulonglong)*(uint *)(lVar4 + 0x38);
          if (uVar8 == 0) {
            local_res8[0] = uVar9 - uVar9 % *(uint *)(lVar4 + 0x90);
            goto LAB_1c00043ec;
          }
          local_res8[0] = *(uint *)(lVar4 + 0x38) - (int)uVar8;
          if (uVar9 <= local_res8[0]) {
            local_res8[0] = uVar9;
          }
        }
        else if (uVar9 < *(uint *)(lVar3 + 0x28)) {
LAB_1c000415b:
          local_res8[0] = uVar9;
        }
        else {
          uVar8 = ((ulonglong)*(uint *)(lVar1 + 0x18) + *(longlong *)(lVar1 + 8)) %
                  (ulonglong)*(uint *)(lVar3 + 0x24);
          if (uVar8 == 0) {
            _Var10 = 0xebe78222;
            local_res8[0] = uVar9 - uVar9 % *(uint *)(lVar3 + 0x30);
            if (*(uint *)(lVar3 + 0x2c) <= local_res8[0]) {
              local_res8[0] = *(uint *)(lVar3 + 0x2c);
            }
            goto LAB_1c0004171;
          }
          local_res8[0] = *(uint *)(lVar3 + 0x24) - (int)uVar8;
          if (uVar9 <= local_res8[0]) {
            local_res8[0] = uVar9;
          }
        }
      }
      else {
        iVar6 = (**(code **)(lVar2 + 0x60))
                          (*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar1 + 0x10),uVar5,uVar9,
                           &local_res10,local_res8);
        if (iVar6 != 0) {
          if ((uVar9 < local_res8[0]) || (local_res8[0] == 0)) {
            pcVar7 = "EvtSerCx2SelectNextReceiveTransactionType returned invalid number of bytes";
          }
          else {
            if ((iVar6 != 3) || (local_res10 == *(longlong *)(lVar3 + 8))) goto LAB_1c00043a6;
            pcVar7 = 
            "EvtSerCx2SelectNextReceiveTransactionType returned SerCx2TransactionTypeCustom, but an invalid CustomReceive Object"
            ;
          }
          Verifier_DbgBreak(pcVar7,1);
          goto LAB_1c0004145;
        }
LAB_1c00043a6:
        if (iVar6 != 1) {
          if (iVar6 != 2) {
            if (iVar6 == 3) {
              _Var10 = 0xebe78222;
              goto LAB_1c0004171;
            }
            goto LAB_1c0004145;
          }
LAB_1c00043ec:
          _Var10 = 0xebe78152;
          goto LAB_1c0004171;
        }
      }
      _Var10 = 0xebe78142;
      goto LAB_1c0004171;
    }
    if (iVar6 == -0x14187dde) {
      uVar5 = *(uint *)(lVar3 + 0x30);
    }
    else {
      if (iVar6 != -0x14187eae) goto LAB_1c0004138;
      uVar5 = *(uint *)(lVar4 + 0x90);
    }
    if (1 < uVar5) {
      _Var10 = 0xebe78382;
      local_res8[0] = uVar9;
      if ((*(uint *)(lVar2 + 0x13c) & 1) == 0) {
        _Var10 = 0xebe78292;
      }
      goto LAB_1c0004171;
    }
  }
  _Var10 = 0xebe78322;
LAB_1c0004171:
  *(_SM_ENGINE_EVENT *)(lVar1 + 0x28) = _Var10;
  *(uint *)(lVar1 + 0x24) = local_res8[0];
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x49,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return _Var10;
}



===== Transmit_ChooseNextTransactionMode @ 1c0004400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_ChooseNextTransactionMode(struct _TRANSMIT_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transmit_ChooseNextTransactionMode(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  char *pcVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  _SM_ENGINE_EVENT _Var9;
  uint uVar10;
  uint local_res8 [2];
  longlong local_res10;
  
  local_res8[0] = 0;
  local_res10 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4e,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar2 = *(longlong *)(param_1 + 0x10);
  uVar10 = *(uint *)(lVar1 + 0x18);
  *(undefined8 *)(lVar1 + 0x20) = 0;
  *(undefined4 *)(lVar1 + 0x28) = 0;
  if (*(uint *)(lVar1 + 0x1c) <= uVar10) {
    _Var9 = 0xebe78322;
    *(undefined4 *)(lVar1 + 0x28) = 0xebe78322;
    *(uint *)(lVar1 + 0x24) = local_res8[0];
    goto LAB_1c00044c7;
  }
  uVar8 = *(uint *)(lVar1 + 0x1c) - uVar10;
  lVar6 = *(longlong *)(param_1 + 0x20);
  lVar3 = *(longlong *)(param_1 + 0x28);
  if (g_ForcePioTransmit != '\0') goto LAB_1c000449f;
  if (*(code **)(lVar2 + 0x68) == (code *)0x0) {
LAB_1c000448d:
    if (lVar3 == 0) {
      if ((lVar6 == 0) || ((ulonglong)uVar8 < *(ulonglong *)(lVar6 + 0x30))) goto LAB_1c000449f;
      uVar10 = *(uint *)(lVar6 + 0x38);
      uVar7 = ((ulonglong)*(uint *)(lVar1 + 0x18) + *(longlong *)(lVar1 + 8)) % (ulonglong)uVar10;
      iVar4 = (int)uVar7;
      if (uVar7 != 0) goto LAB_1c00045b4;
      local_res8[0] = uVar8 - uVar8 % *(uint *)(lVar6 + 0x98);
LAB_1c0004694:
      _Var9 = 0xebe78152;
    }
    else {
      if (uVar8 < *(uint *)(lVar3 + 0x28)) {
LAB_1c000449f:
        local_res8[0] = uVar8;
        goto LAB_1c00044a2;
      }
      uVar10 = *(uint *)(lVar3 + 0x24);
      uVar7 = ((ulonglong)*(uint *)(lVar1 + 0x18) + *(longlong *)(lVar1 + 8)) % (ulonglong)uVar10;
      iVar4 = (int)uVar7;
      if (uVar7 != 0) {
LAB_1c00045b4:
        local_res8[0] = uVar10 - iVar4;
        if (uVar8 <= uVar10 - iVar4) {
          local_res8[0] = uVar8;
        }
        goto LAB_1c00044a2;
      }
      _Var9 = 0xebe78222;
      local_res8[0] = uVar8 - uVar8 % *(uint *)(lVar3 + 0x30);
      if (*(uint *)(lVar3 + 0x2c) <= local_res8[0]) {
        local_res8[0] = *(uint *)(lVar3 + 0x2c);
      }
    }
  }
  else {
    iVar4 = (**(code **)(lVar2 + 0x68))
                      (*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar1 + 0x10),uVar10,uVar8,
                       &local_res10,local_res8);
    if (iVar4 != 0) {
      if ((uVar8 < local_res8[0]) || (local_res8[0] == 0)) {
        pcVar5 = "EvtSerCx2SelectNextTransmitTransactionType returned invalid number of bytes";
      }
      else {
        if ((iVar4 != 3) || (local_res10 == *(longlong *)(lVar3 + 8))) goto LAB_1c0004639;
        pcVar5 = 
        "EvtSerCx2SelectNextTransmitTransactionType returned SerCx2TransactionTypeCustom, but an invalid CustomTransmit Object"
        ;
      }
      Verifier_DbgBreak(pcVar5,1);
      goto LAB_1c000448d;
    }
LAB_1c0004639:
    if (iVar4 != 1) {
      if (iVar4 == 2) goto LAB_1c0004694;
      if (iVar4 != 3) goto LAB_1c000448d;
      _Var9 = 0xebe78222;
      goto LAB_1c00044a7;
    }
LAB_1c00044a2:
    _Var9 = 0xebe78142;
  }
LAB_1c00044a7:
  *(_SM_ENGINE_EVENT *)(lVar1 + 0x28) = _Var9;
  *(uint *)(lVar1 + 0x24) = local_res8[0];
  if ((DAT_1c0025a81 & 2) != 0) {
    lVar6 = *(longlong *)(lVar1 + 8) + (ulonglong)*(uint *)(lVar1 + 0x18);
    McTemplateK0pxqdbr2_EtwWriteTransfer
              (lVar6,&SerCx2EtwEventTransmitIoPayload,*(longlong *)(lVar1 + 0x30) + 0x20,
               *(undefined8 *)(lVar2 + 0x10),(char)*(uint *)(lVar1 + 0x18),local_res8[0],(char)_Var9
               ,lVar6);
  }
LAB_1c00044c7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4f,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return _Var9;
}



===== File_EvtDeviceFileCreate @ 1c00046f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl File_EvtDeviceFileCreate(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,struct WDFFILEOBJECT__ * __ptr64) */

uchar __cdecl
File_EvtDeviceFileCreate(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,WDFFILEOBJECT__ *param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  _UNICODE_STRING *p_Var8;
  short sVar9;
  WDFFILEOBJECT__ *pWVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined *puVar13;
  _UNICODE_STRING *p_Var14;
  undefined2 uVar15;
  undefined1 auStackY_b8 [32];
  undefined *in_stack_ffffffffffffff68;
  undefined8 local_78;
  short *psStack_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_48 = 0x58;
  local_60 = &local_50;
  local_50 = 0x43005200450053;
  local_68 = 0xc000a;
  bVar2 = false;
  bVar1 = false;
  local_78 = 0;
  psStack_70 = (short *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff68 = &WPP_2f0c136022e93545036f062fa9631a83_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,10,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  puVar13 = PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar7 == 0) {
    iVar5 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(0,2,9,0xb,&WPP_2f0c136022e93545036f062fa9631a83_Traceguids,0x9a);
    }
    goto LAB_1c0004914;
  }
  p_Var8 = (_UNICODE_STRING *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_3);
  if ((p_Var8 == (_UNICODE_STRING *)0x0) || (*(short *)p_Var8 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar7 + 0x130),4,9,0xc,
                       &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
    }
    iVar5 = 0;
    goto LAB_1c0004914;
  }
  uVar6 = *(uint *)p_Var8;
  psStack_70 = *(short **)(p_Var8 + 8);
  local_78 = *(undefined8 *)p_Var8;
  if ((short)uVar6 != 0) {
    puVar13 = (undefined *)0xfffe;
    local_78._2_2_ = (short)(uVar6 >> 0x10);
    sVar9 = local_78._2_2_;
    do {
      if (*psStack_70 != 0x5c) break;
      psStack_70 = psStack_70 + 1;
      uVar4 = (short)uVar6 - 2;
      uVar6 = (uint)uVar4;
      sVar9 = sVar9 + -2;
      local_78._0_4_ = CONCAT22(sVar9,uVar4);
    } while (uVar4 != 0);
  }
  if (*(short *)(lVar7 + 0x1a8) == 0) {
LAB_1c0004816:
    pWVar10 = param_3;
    p_Var14 = p_Var8;
    iVar5 = File_QueryConnectionProperties(param_1,param_3,p_Var8);
    if (-1 < iVar5) goto LAB_1c000482e;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar15 = 0xe;
LAB_1c0004b1f:
      WPP_RECORDER_SF_qZd(*(undefined8 *)(lVar7 + 0x130),pWVar10,p_Var14,uVar15,
                          in_stack_ffffffffffffff68,(char)param_1,(wchar_t *)p_Var8,(char)iVar5);
    }
  }
  else {
    p_Var14 = (_UNICODE_STRING *)CONCAT71((int7)((ulonglong)puVar13 >> 8),1);
    puVar12 = &local_78;
    cVar3 = RtlEqualUnicodeString(&local_68,puVar12,p_Var14);
    if (cVar3 == '\0') goto LAB_1c0004816;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      in_stack_ffffffffffffff68 = &WPP_2f0c136022e93545036f062fa9631a83_Traceguids;
      p_Var14 = (_UNICODE_STRING *)0x0;
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar7 + 0x130),puVar12,9,0xd,
                        &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)param_1);
    }
LAB_1c000482e:
    p_Var14 = (_UNICODE_STRING *)CONCAT71((int7)((ulonglong)p_Var14 >> 8),1);
    in_stack_ffffffffffffff68 =
         (undefined *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff68 >> 0x20),0x79);
    pWVar10 = (WDFFILEOBJECT__ *)param_1;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0xdb0))(WdfDriverGlobals,param_1,p_Var14,0);
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar15 = 0xf;
        goto LAB_1c0004b1f;
      }
    }
    else {
      bVar1 = bVar2;
      if (*(int *)(lVar7 + 0x1a0) == 0) {
LAB_1c000487c:
        Receive_ResetRingBuffer(*(_RECEIVE_CONTEXT **)(lVar7 + 0xd0));
        if ((*(code **)(lVar7 + 0x30) == (code *)0x0) ||
           (iVar5 = (**(code **)(lVar7 + 0x30))(param_1), -1 < iVar5)) {
          lVar11 = 1;
          (**(code **)(lVar7 + 0x48))(param_1);
          if ((*(char *)(lVar7 + 4) == '\0') && (lVar11 = *(longlong *)(lVar7 + 0xb8), lVar11 != 0))
          {
            iVar5 = (**(code **)(lVar7 + 0x58))(param_1);
            if (iVar5 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = 0x12;
                bVar2 = bVar1;
                goto LAB_1c0004b71;
              }
              goto LAB_1c00048e1;
            }
            *(undefined1 *)(lVar7 + 4) = 1;
          }
          *(WDFFILEOBJECT__ **)(lVar7 + 8) = param_3;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(lVar7 + 0x130),lVar11,9,0x13,
                              &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)param_3);
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar7 + 0x130),2,9,0x11,
                            &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)iVar5);
        }
      }
      else {
        iVar5 = SerCx_OpenFunctionConfigConnections(param_1);
        if (-1 < iVar5) {
          bVar1 = true;
          goto LAB_1c000487c;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar15 = 0x10;
LAB_1c0004b71:
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar7 + 0x130),2,9,uVar15,
                            &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)iVar5);
          bVar1 = bVar2;
        }
      }
LAB_1c00048e1:
      (**(code **)(WdfFunctions_01015 + 0xdb8))(WdfDriverGlobals,param_1,0,0xb9);
      if (-1 < iVar5) goto LAB_1c0004914;
    }
  }
  if (*(longlong *)(lVar7 + 0xb8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar7 + 0xb8),0x32584353);
    *(undefined8 *)(lVar7 + 0xb8) = 0;
  }
  if (bVar1) {
    SerCx_CloseFunctionConfigConnections(param_1);
  }
LAB_1c0004914:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar5);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x14,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return '\x01';
}



===== File_QueryConnectionProperties @ 1c0004c74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl File_QueryConnectionProperties(struct WDFDEVICE__ * __ptr64,struct WDFFILEOBJECT__ *
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
File_QueryConnectionProperties
          (WDFDEVICE__ *param_1,WDFFILEOBJECT__ *param_2,_UNICODE_STRING *param_3)

{
  undefined8 uVar1;
  long lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStackY_e8 [32];
  undefined8 local_98;
  undefined8 local_90;
  longlong lStack_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 *puStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = 0;
  local_68 = 0;
  local_80 = 0;
  local_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  puStack_70 = (undefined8 *)0x0;
  local_90 = 0;
  lStack_88 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1e,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  lVar2 = File_ParseFileObjectName(param_3,(_LARGE_INTEGER *)&local_98);
  uVar1 = local_98;
  if (lVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(lVar3 + 0x130),2,9,0x1f,
                      &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)lVar2);
  }
  else {
    puStack_70 = &local_58;
    uStack_50 = local_98;
    uVar6 = 0x54;
    local_58 = 1;
    local_78 = 1;
    local_68 = 0x10;
    uVar5 = 0;
    do {
      lVar4 = ExAllocatePool2(0x40,uVar6);
      if (lVar4 == 0) {
        lVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffff66;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x130),2,9,0x20,
                           &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)param_2,0x9a);
        goto LAB_1c0004e38;
      }
      local_90 = 1;
      local_80 = (ulonglong)uVar6;
      lStack_88 = lVar4;
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                        (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0xb0),0,0x2ac000);
      if (lVar2 == -0x3fffffdd) {
        uVar6 = *(int *)(lVar4 + 4) + 8;
        ExFreePoolWithTag(lVar4,0x32584353);
      }
      if (100 < uVar5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x130),2,9,0x21,
                           &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
        }
        goto LAB_1c0004e2d;
      }
      uVar5 = uVar5 + 1;
    } while (lVar2 == -0x3fffffdd);
    *(undefined8 *)(lVar3 + 0xc0) = uVar1;
    *(longlong *)(lVar3 + 0xb8) = lVar4;
LAB_1c0004e2d:
    if (lVar2 < 0) {
      ExFreePoolWithTag(lVar4,0x32584353);
    }
  }
LAB_1c0004e38:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x22,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return lVar2;
}



===== Receive_ResetRingBuffer @ 1c0004fb4 =====

/* void __cdecl Receive_ResetRingBuffer(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_ResetRingBuffer(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x27,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  RingBuffer_Reset(*(_SERCX_RING_BUFFER_PRIVCONTEXT **)(*(longlong *)(param_1 + 0x18) + 0x48));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x28,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== RingBuffer_Reset @ 1c0005060 =====

/* void __cdecl RingBuffer_Reset(struct _SERCX_RING_BUFFER_PRIVCONTEXT * __ptr64) */

void __cdecl RingBuffer_Reset(_SERCX_RING_BUFFER_PRIVCONTEXT *param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0x12,
                       &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x28),4,0xe,0x13,
                         &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids,(char)param_1,
                         (char)*(undefined4 *)(param_1 + 0x1c));
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0x14,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  return;
}



===== File_ParseFileObjectName @ 1c0005140 =====

/* long __cdecl File_ParseFileObjectName(struct _UNICODE_STRING * __ptr64,union _LARGE_INTEGER *
   __ptr64) */

long __cdecl File_ParseFileObjectName(_UNICODE_STRING *param_1,_LARGE_INTEGER *param_2)

{
  longlong lVar1;
  short sVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  ushort uVar6;
  longlong lVar7;
  undefined8 local_res8;
  undefined8 local_48;
  short *psStack_40;
  undefined8 local_38;
  short *psStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x23,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  sVar2 = *(short *)param_1;
  for (psVar4 = *(short **)(param_1 + 8); (sVar2 != 0 && (*psVar4 == 0x5c)); psVar4 = psVar4 + 1) {
    sVar2 = sVar2 + -2;
  }
  local_res8 = 0;
  local_38 = 0;
  psStack_30 = (short *)0x0;
  local_48 = 0;
  psStack_40 = (short *)0x0;
  if (psVar4 == (short *)0x0) {
    local_48._0_2_ = 0;
    uVar6 = (ushort)local_48;
  }
  else {
    lVar7 = 0x7fff;
    psVar3 = psVar4;
    do {
      if (*psVar3 == 0) break;
      psVar3 = psVar3 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    uVar5 = ~-(uint)(lVar7 != 0) & 0xc000000d;
    if (lVar7 == 0) {
      local_48._0_2_ = 0;
      uVar6 = (ushort)local_48;
    }
    else {
      uVar6 = (0x7fff - (short)lVar7) * 2;
      local_48 = (ulonglong)(ushort)(uVar6 + 2) << 0x10;
      psStack_40 = psVar4;
    }
    if ((int)uVar5 < 0) goto LAB_1c0005261;
  }
  lVar7 = local_48;
  if (0x1f < uVar6) {
    local_48 = CONCAT62(local_48._2_6_,0x20);
    for (uVar6 = 0; sVar2 = psStack_40[uVar6], uVar6 < 0x10; uVar6 = uVar6 + 1) {
      if (((9 < (ushort)(sVar2 - 0x30U)) && (5 < (ushort)(sVar2 - 0x61U))) &&
         (5 < (ushort)(sVar2 - 0x41U))) goto LAB_1c000525e;
    }
    if ((sVar2 == 0x5c) || (sVar2 == 0)) {
      psStack_30 = psStack_40 + 8;
      local_48 = CONCAT62(local_48._2_6_,0x10);
      lVar1 = local_48;
      local_48._2_2_ = SUB82(lVar7,2);
      local_38 = (ulonglong)CONCAT22(local_48._2_2_ + -0x10,0x10);
      local_48 = lVar1;
      uVar5 = RtlUnicodeStringToInteger(&local_48,0x10,(longlong)&local_res8 + 4);
      if ((-1 < (int)uVar5) &&
         (uVar5 = RtlUnicodeStringToInteger(&local_38,0x10,&local_res8), -1 < (int)uVar5)) {
        *(undefined8 *)param_2 = local_res8;
      }
      goto LAB_1c0005261;
    }
  }
LAB_1c000525e:
  uVar5 = 0xc000000d;
LAB_1c0005261:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x24,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return uVar5;
}



===== TransferStateEntryFunc_CopyBytesFromRingBuffer @ 1c00053a0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CopyBytesFromRingBuffer(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CopyBytesFromRingBuffer(void *param_1)

{
  ulong uVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x62,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  uVar1 = Receive_CopyBytesFromRingBuffer((_RECEIVE_CONTEXT *)((longlong)param_1 + -0x38));
  _Var2 = 0xebe78332;
  if (uVar1 == 0) {
    _Var2 = 0xebe78342;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,99,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var2;
}



===== Receive_CopyBytesFromRingBuffer @ 1c0005460 =====

/* unsigned long __cdecl Receive_CopyBytesFromRingBuffer(struct _RECEIVE_CONTEXT * __ptr64) */

ulong __cdecl Receive_CopyBytesFromRingBuffer(_RECEIVE_CONTEXT *param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  _RECEIVE_CONTEXT *_Dst;
  _RECEIVE_CONTEXT *_Dst_00;
  
  _Dst = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (_Dst = (_RECEIVE_CONTEXT *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Dst = *(_RECEIVE_CONTEXT **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(_Dst,5,7,0x24,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x68);
  lVar3 = *(longlong *)(param_1 + 0x18);
  uVar5 = *(uint *)(lVar2 + 0x1c);
  _Dst_00 = *(_RECEIVE_CONTEXT **)(lVar2 + 8);
  lVar4 = *(longlong *)(lVar3 + 0x48);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (_Dst = (_RECEIVE_CONTEXT *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Dst = *(_RECEIVE_CONTEXT **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(_Dst,5,0xe,0x15,&WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  uVar1 = *(uint *)(lVar4 + 0x1c);
  if (uVar5 <= *(uint *)(lVar4 + 0x1c)) {
    uVar1 = uVar5;
  }
  if (uVar1 != 0) {
    memcpy(_Dst_00,*(void **)(lVar4 + 0x10),(ulonglong)uVar1);
    uVar5 = *(int *)(lVar4 + 0x1c) - uVar1;
    *(uint *)(lVar4 + 0x1c) = uVar5;
    _Dst = _Dst_00;
    if (uVar5 != 0) {
      _Dst = *(_RECEIVE_CONTEXT **)(lVar4 + 0x10);
      memcpy(_Dst,_Dst + uVar1,(ulonglong)uVar5);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    _Dst = *(_RECEIVE_CONTEXT **)(lVar4 + 0x28);
    WPP_RECORDER_SF_qdd(_Dst,4,0xe,0x16,&WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids,(char)lVar4
                        ,(char)uVar1,(char)*(undefined4 *)(lVar4 + 0x1c));
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (_Dst = (_RECEIVE_CONTEXT *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0))
    {
      _Dst = *(_RECEIVE_CONTEXT **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_(_Dst,5,0xe,0x17,&WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
    }
  }
  if ((uVar1 != 0) && ((DAT_1c0025a81 & 8) != 0)) {
    McTemplateK0pxqdbr2_EtwWriteTransfer
              (_Dst,&SerCx2EtwEventReceiveIoPayload,*(longlong *)(lVar2 + 0x30) + 0x20,
               *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x10),0,uVar1,0,
               *(undefined8 *)(lVar2 + 8));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x410),4,7,0x25,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar3,(char)uVar1);
  }
  *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + uVar1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x26,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return uVar1;
}



===== WPP_RECORDER_SF_qdd @ 1c00056f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== WPP_RECORDER_SF_qd @ 1c0005870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== TransferStateEntryFunc_CompleteRequest @ 1c00059c0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CompleteRequest(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CompleteRequest(void *param_1)

{
  Transfer_CompleteRequest(param_1);
  return 0xebe78092;
}



===== Transfer_CompleteRequest @ 1c00059e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl Transfer_CompleteRequest(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CompleteRequest(_TRANSFER_SM_CONTEXT *param_1)

{
  int *piVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  char extraout_var;
  char extraout_var_00;
  undefined8 uVar8;
  uint uVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  undefined1 uVar12;
  undefined1 auStackY_a8 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x10,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  lVar5 = *(longlong *)(param_1 + 0x30);
  lVar6 = *(longlong *)(param_1 + 8);
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qcqddd(*(undefined8 *)(param_1 + 0x3d8));
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x72) {
    uVar3 = *(uint *)(lVar5 + 0x20);
    if ((uVar3 != 0) && ((DAT_1c0025a81 & 8) != 0)) {
      uVar9 = *(uint *)(lVar5 + 0x18) - uVar3;
      McTemplateK0pxqdbr2_EtwWriteTransfer
                ((ulonglong)uVar9,&SerCx2EtwEventReceiveIoPayload,*(longlong *)(lVar5 + 0x30) + 0x20
                 ,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x10),(char)uVar9,uVar3,
                 (char)*(undefined4 *)(lVar5 + 0x28),
                 (*(longlong *)(lVar5 + 8) - (ulonglong)uVar3) + (ulonglong)*(uint *)(lVar5 + 0x18))
      ;
    }
    uVar2 = (undefined1)*(undefined4 *)(lVar5 + 0x18);
    local_48 = 0;
    uStack_40 = 0;
    uVar12 = (undefined1)*(undefined4 *)(lVar5 + 4);
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar4);
    IoGetActivityIdIrp(uVar8,&local_48);
    if ((DAT_1c0025a81 & 4) == 0) goto LAB_1c0005ad0;
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,uVar4);
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar8);
    puVar10 = &SerCx2EtwEventReceiveIoStop;
    cVar7 = extraout_var_00;
  }
  else {
    uVar2 = (undefined1)*(undefined4 *)(lVar5 + 0x18);
    local_48 = 0;
    uStack_40 = 0;
    uVar12 = (undefined1)*(undefined4 *)(lVar5 + 4);
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,uVar4);
    IoGetActivityIdIrp(uVar8,&local_48);
    if ((DAT_1c0025a81 & 1) == 0) goto LAB_1c0005ad0;
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,uVar4);
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar8);
    puVar10 = &SerCx2EtwEventTransmitIoStop;
    cVar7 = extraout_var;
  }
  puVar11 = &local_48;
  if (cVar7 < '\0') {
    puVar11 = (undefined8 *)0x0;
  }
  McTemplateK0pdx_EtwWriteTransfer(0,puVar10,puVar11,uVar8,uVar12,uVar2);
LAB_1c0005ad0:
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x170));
  piVar1 = (int *)(lVar6 + 0x17c);
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (*(char *)(lVar6 + 0x178) != '\0')) {
    *(longlong *)(lVar6 + 0x188) =
         *(longlong *)(lVar6 + 0x188) + (_DAT_fffff78000000008 - *(longlong *)(lVar6 + 0x180));
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x170));
  (**(code **)(WdfFunctions_01015 + 0x848))
            (WdfDriverGlobals,uVar4,*(undefined4 *)(lVar5 + 4),*(undefined4 *)(lVar5 + 0x18));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x12,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_EtwWriteStateMachineEvent @ 1c0005e10 =====

/* void __cdecl Transfer_EtwWriteStateMachineEvent(void * __ptr64,void * __ptr64,enum
   _SM_ENGINE_EVENT) */

void __cdecl
Transfer_EtwWriteStateMachineEvent(void *param_1,void *param_2,_SM_ENGINE_EVENT param_3)

{
  undefined *puVar1;
  
  if (*(char *)((longlong)param_2 + 0x10) == 'r') {
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 0x20) == 0) {
      return;
    }
    puVar1 = &SerCx2EtwEventReceiveTransferStateMachineEvent;
  }
  else {
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 8) == 0) {
      return;
    }
    puVar1 = &SerCx2EtwEventTransmitTransferStateMachineEvent;
  }
  McTemplateK0pd_EtwWriteTransfer(param_1,puVar1,(longlong)param_2 + 0x20,param_2,(char)param_3);
  return;
}



===== TransferStateEntryFunc_IsDpcWatchDogExpiringSoon @ 1c0005e70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsDpcWatchDogExpiringSoon(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsDpcWatchDogExpiringSoon(void *param_1)

{
  int iVar1;
  _SM_ENGINE_EVENT _Var2;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x8c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  iVar1 = KeQueryDpcWatchdogInformation(&local_28);
  if (-1 < iVar1) {
    if (((int)local_28 != 0) && (local_28._4_4_ < (uint)((int)local_28 * 0x50) / 100)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)((longlong)param_1 + 0x3d8),4,6,0x8d,
                         &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
      }
      LOCK();
      *(int *)((longlong)param_1 + 0x3d0) = *(int *)((longlong)param_1 + 0x3d0) + 1;
      UNLOCK();
      _Var2 = 0xebe78172;
      goto LAB_1c0005ed0;
    }
    if (((int)uStack_20 != 0) && (uStack_20._4_4_ < (uint)((int)uStack_20 * 0x32) / 100)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)((longlong)param_1 + 0x3d8),4,6,0x8e,
                         &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
      }
      LOCK();
      *(int *)((longlong)param_1 + 0x3d4) = *(int *)((longlong)param_1 + 0x3d4) + 1;
      UNLOCK();
      _Var2 = 0xebe78172;
      goto LAB_1c0005ed0;
    }
  }
  _Var2 = 0xebe78122;
LAB_1c0005ed0:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x8f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var2;
}



===== TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrInCurrentCustomTransaction @ 1c0006020 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrInCurrentCustomTransaction(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrInCurrentCustomTransaction(void *param_1)

{
  char cVar1;
  int iVar2;
  _SM_ENGINE_EVENT _Var3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x86,
                       &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x91,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  cVar1 = *(char *)(*(longlong *)((longlong)param_1 + -8) + 0x68);
  iVar2 = *(int *)(*(longlong *)((longlong)param_1 + 0x30) + 0x18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x92,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  _Var3 = 0xebe78172;
  if (iVar2 == 0 && cVar1 == '\0') {
    _Var3 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x87,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var3;
}



===== TransferStateEntryFunc_StartTimerForIntervalTimeout @ 1c00061a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartTimerForIntervalTimeout(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartTimerForIntervalTimeout(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x38);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x21,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  if (_DAT_fffff78000000008 < *(longlong *)(lVar1 + 0x40)) {
    lVar2 = *(longlong *)(lVar1 + 0x38);
    lVar4 = *(longlong *)(lVar1 + 0x40) - _DAT_fffff78000000008;
    uVar3 = *(undefined8 *)(lVar1 + 8);
    *(undefined4 *)(lVar1 + 0x48) = 0;
    *(undefined8 *)(lVar1 + 0x18) = uVar3;
    if (lVar2 < lVar4) {
      if (*(char *)(lVar1 + 0x34) != '\0') {
        uVar3 = *(undefined8 *)(lVar1 + 0x10);
        *(undefined8 *)(lVar1 + 0x18) = uVar3;
      }
    }
    else {
      *(undefined4 *)(lVar1 + 0x48) = 1;
      lVar2 = lVar4;
    }
    (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,uVar3,-lVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar1 + 0x60),4,0xd,0x22,
                       &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
    }
    (**(code **)(lVar1 + 0x50))(*(undefined8 *)(lVar1 + 0x58),lVar1,1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x23,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return 0xebe78092;
}



===== TransferStateEntryFunc_CleanupPioTransaction2 @ 1c0006310 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupPioTransaction2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupPioTransaction2(void *param_1)

{
  Transfer_CleanupPioTransaction(param_1);
  return 0;
}



===== Transfer_CleanupPioTransaction @ 1c0006330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transfer_CleanupPioTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CleanupPioTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_CleanupPioTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x20,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
    (**(code **)(*(longlong *)(param_1 + -0x20) + 0x28))
              (*(undefined8 *)(*(longlong *)(param_1 + -0x20) + 8));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x21,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transmit_CleanupPioTransaction @ 1c0006470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_CleanupPioTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_CleanupPioTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2d,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x28))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2e,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_ReleasePowerReference2 @ 1c0006530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ReleasePowerReference2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ReleasePowerReference2(void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0xdb8))
            (WdfDriverGlobals,*(undefined8 *)(*(longlong *)((longlong)param_1 + 8) + 0x10),0,0x17d,
             "onecore\\drivers\\serial\\sercx2\\sercx2\\sys\\transfer.cpp");
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return 0xebe78092;
}



===== TransferStateEntryFunc_InitializePioTransaction2 @ 1c0006610 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializePioTransaction2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializePioTransaction2(void *param_1)

{
  Transfer_InitializePioTransaction(param_1);
  return 0;
}



===== Transfer_InitializePioTransaction @ 1c0006630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transfer_InitializePioTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_InitializePioTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_InitializePioTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1e,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
    (**(code **)(*(longlong *)(param_1 + -0x20) + 0x20))
              (*(undefined8 *)(*(longlong *)(param_1 + -0x20) + 8),
               *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x24));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1f,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transmit_InitializePioTransaction @ 1c0006780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_InitializePioTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_InitializePioTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x20))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8),
             *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x24));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Etw_GetActivityId @ 1c0006840 =====

/* unsigned char __cdecl Etw_GetActivityId(struct _IRP * __ptr64,unsigned char,struct _GUID *
   __ptr64) */

uchar __cdecl Etw_GetActivityId(_IRP *param_1,uchar param_2,_GUID *param_3)

{
  int iVar1;
  
  iVar1 = IoGetActivityIdIrp(param_1,param_3);
  if (iVar1 < 0) {
    if (param_2 == '\0') {
      return '\0';
    }
    iVar1 = EtwActivityIdControl(3,param_3);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(0,3,0xf,0x12,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar1);
    }
    iVar1 = IoSetActivityIdIrp(param_1,param_3);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(0,3,0xf,0x13,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar1);
    }
  }
  return '\x01';
}



===== TransferStateEntryFunc_StopTimer2 @ 1c0006940 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StopTimer2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StopTimer2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_StopTimer(param_1);
  return _Var1;
}



===== Transfer_StopTimer @ 1c0006960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transfer_StopTimer(struct _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_StopTimer(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  char cVar2;
  _SM_ENGINE_EVENT _Var3;
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x24,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  cVar2 = (**(code **)(WdfFunctions_01015 + 0xa00))
                    (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x18),0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x25,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  _Var3 = 0xebe78092;
  if (cVar2 == '\0') {
    _Var3 = 0xebe78082;
  }
  return _Var3;
}



===== TransferStateEntryFunc_MarkRequestCancellable @ 1c0006a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_MarkRequestCancellable(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_MarkRequestCancellable(void *param_1)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x29,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))
                    (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x18),
                     Transfer_EvtRequestCancel);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x2a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (iVar1 >> 0x1f & 0xfffffff0U) + 0xebe78092;
}



===== TransferStateEntryFunc_IsCleanupPioTransactionNeeded5 @ 1c0006b20 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupPioTransactionNeeded5(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupPioTransactionNeeded5(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xc,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x10) == 't') {
    _Var1 = 0xebe78172;
    if (*(longlong *)(*(longlong *)((longlong)param_1 + -0x20) + 0x28) == 0) {
      _Var1 = 0xebe78122;
    }
  }
  else {
    _Var1 = 0xebe78122;
    if (*(longlong *)(*(longlong *)((longlong)param_1 + -0x20) + 0x28) != 0) {
      _Var1 = 0xebe78172;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xd,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_IsTransmitTransactionAndPioFifoDrainOrPurgeNeeded2 @ 1c0006bf0 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_IsTransmitTransactionAndPioFifoDrainOrPurgeNeeded2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsTransmitTransactionAndPioFifoDrainOrPurgeNeeded2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,100,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x10) == 't') {
    _Var1 = 0xebe78122;
    if (*(longlong *)(*(longlong *)((longlong)param_1 + -0x20) + 0x48) != 0) {
      _Var1 = 0xebe78172;
    }
  }
  else {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x65,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_EnableAndWaitForPioReadyNotification @ 1c0006cc0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_EnableAndWaitForPioReadyNotification(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_EnableAndWaitForPioReadyNotification(void *param_1)

{
  Transfer_EnablePioReadyNotification(param_1);
  return 0;
}



===== Transfer_EnablePioReadyNotification @ 1c0006ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transfer_EnablePioReadyNotification(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_EnablePioReadyNotification(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_EnablePioReadyNotification((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x22,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
    (**(code **)(*(longlong *)(param_1 + -0x20) + 0x38))
              (*(undefined8 *)(*(longlong *)(param_1 + -0x20) + 8));
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x23,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_IsReceiveTransaction10 @ 1c0006e30 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsReceiveTransaction10(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsReceiveTransaction10(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x38,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe78172;
  if (*(char *)((longlong)param_1 + 0x10) != 'r') {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x39,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_CancelPioReadyNotificaiton2 @ 1c0006ef0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelPioReadyNotificaiton2(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelPioReadyNotificaiton2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_CancelPioReadyNotification(param_1);
  return _Var1;
}



===== Transfer_CancelPioReadyNotification @ 1c0006f10 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_CancelPioReadyNotification(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_CancelPioReadyNotification(_TRANSFER_SM_CONTEXT *param_1)

{
  uchar uVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xe,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    uVar1 = Transmit_CancelPioReadyNotification((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    uVar1 = Receive_CancelPioReadyNotification((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  _Var2 = 0xebe78092;
  if (uVar1 == '\0') {
    _Var2 = 0xebe78082;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xf,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var2;
}



===== Receive_CancelPioReadyNotification @ 1c0006fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_CancelPioReadyNotification(struct _RECEIVE_CONTEXT * __ptr64) */

uchar __cdecl Receive_CancelPioReadyNotification(_RECEIVE_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x29,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x40))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return uVar1;
}



===== TransferStateEntryFunc_UnmarkRequestCancellable @ 1c00070a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_UnmarkRequestCancellable(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_UnmarkRequestCancellable(void *param_1)

{
  int iVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x30,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))
                    (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x18));
  _Var2 = 0xebe78092;
  if (iVar1 == -0x3ffffee0) {
    _Var2 = 0xebe78082;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x31,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var2;
}



===== TransferStateEntryFunc_IsInitializePioTransactionNeeded @ 1c0007170 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsInitializePioTransactionNeeded(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsInitializePioTransactionNeeded(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsInitializePioTransactionNeeded(param_1);
  return _Var1;
}



===== Transfer_IsInitializePioTransactionNeeded @ 1c0007190 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsInitializePioTransactionNeeded(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_IsInitializePioTransactionNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,10,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = 0xebe78172;
    if (*(longlong *)(*(longlong *)(param_1 + -0x20) + 0x20) == 0) {
      _Var1 = 0xebe78122;
    }
  }
  else {
    _Var1 = 0xebe78122;
    if (*(longlong *)(*(longlong *)(param_1 + -0x20) + 0x20) != 0) {
      _Var1 = 0xebe78172;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xb,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_StartTimerForTotalTimeout10 @ 1c0007260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartTimerForTotalTimeout10(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartTimerForTotalTimeout10(void *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x38);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x21,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  if (_DAT_fffff78000000008 < *(longlong *)(lVar1 + 0x40)) {
    lVar2 = *(longlong *)(lVar1 + 0x40) - _DAT_fffff78000000008;
    *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar1 + 8);
    *(undefined4 *)(lVar1 + 0x48) = 1;
    (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),-lVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar1 + 0x60),4,0xd,0x22,
                       &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
    }
    (**(code **)(lVar1 + 0x50))(*(undefined8 *)(lVar1 + 0x58),lVar1,1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x23,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return 0xebe78092;
}



===== TransferStateEntryFunc_InitRequest @ 1c0007390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitRequest(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitRequest(void *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)((longlong)param_1 + 8);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x170));
  *(int *)(lVar1 + 0x17c) = *(int *)(lVar1 + 0x17c) + 1;
  if ((*(int *)(lVar1 + 0x17c) == 1) && (*(char *)(lVar1 + 0x178) != '\0')) {
    *(undefined8 *)(lVar1 + 0x180) = _DAT_fffff78000000008;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x170));
  return 0xebe78092;
}



===== TransferStateEntryFunc_StartCustomTransaction @ 1c0007420 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartCustomTransaction(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_StartCustomTransaction(void *param_1)

{
  Transfer_StartCustomTransaction(param_1);
  return 0xebe78092;
}



===== Transfer_StartCustomTransaction @ 1c0007440 =====

/* void __cdecl Transfer_StartCustomTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_StartCustomTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_StartCustomTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_StartCustomTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transmit_StartCustomTransaction @ 1c0007500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_StartCustomTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_StartCustomTransaction(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x83,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x30);
  lVar2 = *(longlong *)(param_1 + 0x28);
  uVar3 = *(undefined8 *)(param_1 + 0x410);
  lVar4 = *(longlong *)(lVar1 + 0x28);
  IoReuseIrp(lVar4,0);
  iVar7 = IoSetCompletionRoutineEx
                    (*(undefined8 *)(lVar1 + 0x18),lVar4,Transmit_CustomTransactionComplete,lVar1,1,
                     1,1);
  if (iVar7 < 0) {
    lVar6 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar6 + -0x10) = Transmit_CustomTransactionComplete;
    *(longlong *)(lVar6 + -8) = lVar1;
    *(undefined1 *)(lVar6 + -0x45) = 0xe0;
  }
  *(char *)(lVar4 + 0x43) = *(char *)(lVar4 + 0x43) + -1;
  *(longlong *)(lVar4 + 0xb8) = *(longlong *)(lVar4 + 0xb8) + -0x48;
  uVar5 = *(undefined8 *)(lVar1 + 0x20);
  local_40 = 0;
  local_48 = 0x18;
  local_44 = 3;
  local_38 = *(undefined8 *)(lVar1 + 0x28);
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,uVar5,&local_48);
  iVar7 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,uVar5,*(undefined8 *)(lVar2 + 0x10));
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(uVar3,2,5,0x84,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)iVar7)
      ;
    }
    Verifier_DbgBreak("WdfRequestForwardToIoQueue was not expected to fail",2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x85,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Receive_StartCustomTransaction @ 1c00076f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_StartCustomTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_StartCustomTransaction(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x86,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x30);
  lVar2 = *(longlong *)(lVar1 + 0x28);
  *(undefined1 *)(lVar1 + 0x68) = 0;
  lVar3 = *(longlong *)(param_1 + 0x28);
  uVar4 = *(undefined8 *)(param_1 + 0x410);
  IoReuseIrp(lVar2,0);
  iVar7 = IoSetCompletionRoutineEx
                    (*(undefined8 *)(lVar1 + 0x18),lVar2,Receive_CustomTransactionComplete,lVar1,1,1
                     ,1);
  if (iVar7 < 0) {
    lVar6 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar6 + -0x10) = Receive_CustomTransactionComplete;
    *(longlong *)(lVar6 + -8) = lVar1;
    *(undefined1 *)(lVar6 + -0x45) = 0xe0;
  }
  *(char *)(lVar2 + 0x43) = *(char *)(lVar2 + 0x43) + -1;
  *(longlong *)(lVar2 + 0xb8) = *(longlong *)(lVar2 + 0xb8) + -0x48;
  uVar5 = *(undefined8 *)(lVar1 + 0x20);
  local_40 = 0;
  local_48 = 0x18;
  local_44 = 3;
  local_38 = *(undefined8 *)(lVar1 + 0x28);
  (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,uVar5,&local_48);
  iVar7 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                    (WdfDriverGlobals,uVar5,*(undefined8 *)(lVar3 + 0x10));
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(uVar4,2,7,0x87,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)iVar7)
      ;
    }
    Verifier_DbgBreak("WdfRequestForwardToIoQueue was not expected to fail",2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x88,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Ioctl_EvtIoControl @ 1c00078e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_EvtIoControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Ioctl_EvtIoControl(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,
                  ulong param_5)

{
  WDFDEVICE__ *pWVar1;
  longlong lVar2;
  undefined8 uVar3;
  __uint64 _Var4;
  __uint64 _Var5;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar6;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4f,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  pWVar1 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,pWVar1);
  _Var5 = 0;
  _Var4 = 0;
  (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  *(undefined8 *)(lVar2 + 0x120) = uVar3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(lVar2 + 0x130));
  }
  if (param_5 == 0x1b001c) {
    Ioctl_SetTimeouts(pWVar1,param_2,_Var4,param_4);
    goto LAB_1c0007a19;
  }
  if (param_5 == 0x1b00a0) {
    (**(code **)(WdfFunctions_01015 + 0x8c8))
              (WdfDriverGlobals,param_2,*(undefined8 *)(lVar2 + 0x118));
    goto LAB_1c0007a19;
  }
  if (param_5 == 0x1b0008) {
switchD_1c0007b50_caseD_1b005c:
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0);
  }
  else {
    if (param_5 == 0x1b0058) {
      Ioctl_GetChars(pWVar1,param_2,param_3);
      goto LAB_1c0007a19;
    }
    switch(param_5) {
    case 0x1b0010:
      Ioctl_SetBreakOn(pWVar1,param_2);
      break;
    default:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 1;
        WPP_RECORDER_SF_L(*(undefined8 *)(lVar2 + 0x130),4,8,0x52,
                          &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_5);
      }
      (**(code **)(lVar2 + 0x50))(pWVar1,param_2,param_3,param_4,CONCAT44(uVar6,param_5));
      break;
    case 0x1b0014:
      Ioctl_SetBreakOff(pWVar1,param_2,param_3,param_4);
      break;
    case 0x1b0018:
    case 0x1b002c:
    case 0x1b0038:
    case 0x1b003c:
    case 0x1b0070:
    case 0x1b007c:
    case 0x1b0080:
    case 0x1b008c:
    case 0x1b0090:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(lVar2 + 0x130),3,8,0x51,
                          &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_5);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
      break;
    case 0x1b0020:
      Ioctl_GetTimeouts(pWVar1,param_2,param_3,_Var5);
      break;
    case 0x1b0040:
      Ioctl_GetWaitMask(pWVar1,param_2,param_3);
      break;
    case 0x1b0044:
      Ioctl_SetWaitMask(pWVar1,param_2,param_4);
      break;
    case 0x1b0048:
      Ioctl_WaitOnMask(pWVar1,param_2,param_3);
      break;
    case 0x1b004c:
      Ioctl_Purge(pWVar1,param_2,param_4);
      break;
    case 0x1b005c:
      goto switchD_1c0007b50_caseD_1b005c;
    case 0x1b00a4:
      Ioctl_SetIntervalTimerResolution(pWVar1,param_2,_Var4,param_4);
    }
  }
LAB_1c0007a19:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x53,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetTimeouts @ 1c0007c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetTimeouts(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Ioctl_SetTimeouts(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  ulong uVar1;
  ulong uVar2;
  _SERCX_TIMER_PRIVCONTEXT *p_Var3;
  _SERCX_TIMER_PRIVCONTEXT *p_Var4;
  int iVar5;
  longlong lVar6;
  ulong *local_res18;
  
  local_res18 = (ulong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x13,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_4 == 0x14) {
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x14,&local_res18,0);
    if (iVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar6 + 0x130),2,8,0x15,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar5);
      }
    }
    else {
      p_Var3 = *(_SERCX_TIMER_PRIVCONTEXT **)(*(longlong *)(lVar6 + 200) + 0x70);
      p_Var4 = *(_SERCX_TIMER_PRIVCONTEXT **)(*(longlong *)(lVar6 + 0xd0) + 0x70);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x17,
                         &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
      }
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(p_Var3 + 0x20));
      uVar1 = *(ulong *)(p_Var3 + 0x2c);
      uVar2 = *(ulong *)(p_Var3 + 0x30);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x18,
                         &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
      }
      iVar5 = Timer_SetTimeouts(p_Var3,0,local_res18[4],local_res18[3]);
      if (iVar5 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar6 + 0x130),2,8,0x16,
                            &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)iVar5);
        }
      }
      else {
        iVar5 = Timer_SetTimeouts(p_Var4,*local_res18,local_res18[2],local_res18[1]);
        if (iVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(lVar6 + 0x130),2,8,0x17,
                              &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)iVar5);
          }
          Timer_SetTimeouts(p_Var3,0,uVar1,uVar2);
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ddddd(*(undefined8 *)(lVar6 + 0x130));
        }
      }
    }
  }
  else {
    iVar5 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar6 + 0x130),2,8,0x14,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar5);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x19,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Timer_SetTimeouts @ 1c0008028 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Timer_SetTimeouts(struct _SERCX_TIMER_PRIVCONTEXT * __ptr64,unsigned long,unsigned
   long,unsigned long) */

long __cdecl
Timer_SetTimeouts(_SERCX_TIMER_PRIVCONTEXT *param_1,ulong param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0xf,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  uVar2 = 0xebe78372;
  if (param_2 == 0xffffffff) {
    if (param_4 == 0) {
      if (param_3 != 0) {
LAB_1c00081f6:
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar3 = 0x10;
        goto LAB_1c0008216;
      }
      uVar2 = 0xebe78352;
    }
    else {
      if ((param_4 != 0xffffffff) || (0xfffffffd < param_3 - 1)) goto LAB_1c00081f6;
      uVar2 = 0xebe78362;
LAB_1c00080a8:
      if (86400000 < param_3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar3 = 0x15;
        goto LAB_1c00081b4;
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    *(ulong *)(param_1 + 0x2c) = param_3;
    *(ulong *)(param_1 + 0x30) = param_4;
    *(ulong *)(param_1 + 0x28) = param_2;
    *(undefined4 *)(param_1 + 0x4c) = uVar2;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    lVar1 = 0;
    goto LAB_1c00080fd;
  }
  if (param_4 == 0xffffffff) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar3 = 0x11;
LAB_1c0008216:
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x60),2,0xd,uVar3,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  else {
    if (param_3 == 0xffffffff) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar3 = 0x12;
      goto LAB_1c0008216;
    }
    if (param_2 < 0x5265c01) {
      if (param_4 < 0x5265c01) goto LAB_1c00080a8;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar3 = 0x14;
      param_3 = param_4;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar3 = 0x13;
      param_3 = param_2;
    }
LAB_1c00081b4:
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x60),2,0xd,uVar3,
                      &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids,(char)param_3);
  }
  lVar1 = -0x3ffffff3;
LAB_1c00080fd:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x16,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return lVar1;
}



===== Ioctl_GetChars @ 1c0008288 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_GetChars(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned
   __int64) */

void __cdecl Ioctl_GetChars(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 *local_res18 [2];
  
  local_res18[0] = (undefined4 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x2e,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_3 == 6) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,6,local_res18,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar2 + 0x130),2,8,0x30,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar1);
      }
      goto LAB_1c0008383;
    }
    *local_res18[0] = 0;
    *(undefined2 *)(local_res18[0] + 1) = 0;
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,6);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0008383;
    uVar3 = *(undefined8 *)(lVar2 + 0x130);
    uVar5 = 0x31;
    bVar4 = 4;
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0008383;
    uVar3 = *(undefined8 *)(lVar2 + 0x130);
    uVar5 = 0x2f;
    bVar4 = 2;
    iVar1 = -0x3ffffff3;
  }
  WPP_RECORDER_SF_(uVar3,bVar4,8,uVar5,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
LAB_1c0008383:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x32,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_L @ 1c000848c =====

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



===== WPP_RECORDER_SF_qqL @ 1c000858c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x50,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x50,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_ddddd @ 1c0008698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x18,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x18,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== TransferStateEntryFunc_PioDrainFifo @ 1c0008800 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_PioDrainFifo(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_PioDrainFifo(void *param_1)

{
  Transfer_PioDrainFifo(param_1);
  return 0;
}



===== Transfer_PioDrainFifo @ 1c0008820 =====

/* void __cdecl Transfer_PioDrainFifo(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_PioDrainFifo(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x66,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Transmit_PioDrainFifo((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x67,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transmit_PioDrainFifo @ 1c00088d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_PioDrainFifo(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_PioDrainFifo(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x50,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x48))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x51,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Ioctl_EvtIrpPreprocess @ 1c0008990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Ioctl_EvtIrpPreprocess(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl Ioctl_EvtIrpPreprocess(WDFDEVICE__ *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x58,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  puVar4 = &local_48;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = IoGetActivityIdIrp(param_2);
  if (iVar2 < 0) {
    iVar2 = EtwActivityIdControl(3,&local_48);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(0,3,0xf,0x12,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar2);
    }
    puVar4 = &local_48;
    iVar2 = IoSetActivityIdIrp();
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      puVar4 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar4 >> 8),3);
      WPP_RECORDER_SF_d(0,3,0xf,0x13,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar2);
    }
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (Microsoft_Windows_Serial_ClassExtension_V2EnableBits < '\0') {
    McTemplateK0pddbr2_EtwWriteTransfer
              (lVar1,puVar4,&local_48,param_1,(char)*(undefined4 *)(lVar1 + 0x18),
               *(undefined4 *)(lVar1 + 0x10),*(undefined8 *)(param_2 + 0x18));
  }
  puVar4 = *(undefined8 **)(param_2 + 0xb8);
  puVar4[-9] = *puVar4;
  puVar4[-8] = puVar4[1];
  puVar4[-7] = puVar4[2];
  puVar4[-6] = puVar4[3];
  *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
  *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
  *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
  *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
  puVar4[-3] = puVar4[6];
  *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar2 = IoSetCompletionRoutineEx(uVar3,param_2,Ioctl_EvtIrpPostProcess,0);
  if (iVar2 < 0) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar1 + -0x10) = Ioctl_EvtIrpPostProcess;
    *(undefined8 *)(lVar1 + -8) = 0;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xc88))(WdfDriverGlobals,param_1,param_2,param_3);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    WPP_RECORDER_SF_d(0,2,8,0x59,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)iVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x5a,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return iVar2;
}



===== TransferStateEntryFunc_SetRequestStatusOnTimeout10 @ 1c0008c60 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SetRequestStatusOnTimeout10(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SetRequestStatusOnTimeout10(void *param_1)

{
  Transfer_SetRequestStatusOnTimeout(param_1);
  return 0xebe78092;
}



===== Transfer_SetRequestStatusOnTimeout @ 1c0008c80 =====

/* void __cdecl Transfer_SetRequestStatusOnTimeout(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_SetRequestStatusOnTimeout(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x22,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 4) = 0x102;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x23,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_GetTimeoutMode2 @ 1c0008d30 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_GetTimeoutMode2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_GetTimeoutMode2(void *param_1)

{
  return *(_SM_ENGINE_EVENT *)(*(longlong *)((longlong)param_1 + 0x38) + 0x4c);
}



===== TransferStateEntryFunc_HaveAnyBytesAlreadyBeenReceived1 @ 1c0008d50 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_HaveAnyBytesAlreadyBeenReceived1(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_HaveAnyBytesAlreadyBeenReceived1(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_HaveAnyBytesAlreadyBeenReceived(param_1);
  return _Var1;
}



===== Transfer_HaveAnyBytesAlreadyBeenReceived @ 1c0008d70 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_HaveAnyBytesAlreadyBeenReceived(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_HaveAnyBytesAlreadyBeenReceived(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe78172;
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x18) == 0) {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Ioctl_EvtIrpPostProcess @ 1c0008e30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Ioctl_EvtIrpPostProcess(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl Ioctl_EvtIrpPostProcess(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  WDFDEVICE__ *pWVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x5b,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  pWVar2 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,param_1);
  if (pWVar2 == (WDFDEVICE__ *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_(0,2,8,0x5c,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,pWVar2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (iVar1 == 0x1b0010) {
      Ioctl_SetBreakOnComplete(pWVar2,param_2);
    }
    else if (iVar1 == 0x1b0014) {
      Ioctl_SetBreakOffComplete(pWVar2,param_2);
    }
    else if (iVar1 == 0x1b0044) {
      Ioctl_SetWaitMaskComplete(pWVar2,param_2);
    }
    else if (iVar1 == 0x1b006c) {
      Ioctl_GetCommStatusComplete(pWVar2,param_2);
    }
    if (*(_IRP **)(lVar3 + 0x120) == param_2) {
      *(undefined8 *)(lVar3 + 0x120) = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLd(*(undefined8 *)(lVar3 + 0x130));
      }
      (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x110));
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqLd(*(undefined8 *)(lVar3 + 0x130));
    }
    local_48 = 0;
    uStack_40 = 0;
    iVar1 = IoGetActivityIdIrp(param_2,&local_48);
    lVar3 = *(longlong *)(param_2 + 0xb8);
    if ((char)Microsoft_Windows_Serial_ClassExtension_V2EnableBits < '\0') {
      puVar4 = &local_48;
      if (iVar1 < 0) {
        puVar4 = (undefined8 *)0x0;
      }
      McTemplateK0pdddbr3_EtwWriteTransfer
                ((ulonglong)Microsoft_Windows_Serial_ClassExtension_V2EnableBits,lVar3,puVar4,pWVar2
                 ,(char)*(undefined4 *)(lVar3 + 0x18),(char)*(undefined4 *)(param_2 + 0x30),
                 *(undefined4 *)(lVar3 + 8),*(undefined8 *)(param_2 + 0x18));
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x5f,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return 0;
}



===== WPP_RECORDER_SF_qLd @ 1c0009124 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x5d,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x5d,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== SerCx_PowerIrpPreprocess @ 1c0009230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SerCx_PowerIrpPreprocess(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl SerCx_PowerIrpPreprocess(WDFDEVICE__ *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  _IRP *p_Var6;
  undefined1 auStackY_98 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_58 = 0;
  uStack_50 = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  p_Var6 = param_2;
  iVar3 = IoGetActivityIdIrp(param_2,&local_58);
  if (iVar3 < 0) {
    iVar3 = EtwActivityIdControl(3,&local_58);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(0,3,0xf,0x12,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar3);
    }
    p_Var6 = param_2;
    iVar3 = IoSetActivityIdIrp(param_2,&local_58);
    if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      p_Var6 = (_IRP *)0x0;
      WPP_RECORDER_SF_d(0,3,0xf,0x13,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar3);
    }
  }
  if (*(char *)(lVar1 + 1) == '\x02') {
    if (*(int *)(lVar1 + 0x10) == 0) {
      if ((DAT_1c0025a81 & 0x10) != 0) {
        McTemplateK0pd_EtwWriteTransfer
                  (p_Var6,&SerCx2EtwEventSystemPowerStateTransitionStart,&local_58,param_1,
                   (char)*(undefined4 *)(lVar1 + 0x18));
      }
      if (*(int *)(lVar1 + 0x18) != 1) {
        SerCx_TryToPurgeIoOnSx(param_1);
      }
    }
    else if ((*(int *)(lVar1 + 0x10) == 1) && ((DAT_1c0025a81 & 0x10) != 0)) {
      McTemplateK0pd_EtwWriteTransfer
                (p_Var6,&SerCx2EtwEventDevicePowerStateTransitionStart,&local_58,param_1,
                 (char)*(undefined4 *)(lVar1 + 0x18));
    }
  }
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
  *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
  *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
  *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  iVar3 = IoSetCompletionRoutineEx(uVar5,param_2,SerCx_PowerIrpPostprocess,0);
  if (iVar3 < 0) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar1 + -8) = 0;
    *(code **)(lVar1 + -0x10) = SerCx_PowerIrpPostprocess;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0xc88))(WdfDriverGlobals,param_1,param_2,param_3);
  return lVar4;
}



===== TransferStateEntryFunc_IsInitializeCustomTransactionNeeded @ 1c0009480 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsInitializeCustomTransactionNeeded(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsInitializeCustomTransactionNeeded(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsInitializeCustomTransactionNeeded(param_1);
  return _Var1;
}



===== Transfer_IsInitializeCustomTransactionNeeded @ 1c00094a0 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsInitializeCustomTransactionNeeded(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_IsInitializeCustomTransactionNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x76,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = 0xebe78172;
    if (*(longlong *)(*(longlong *)(param_1 + -8) + 0x40) == 0) {
      _Var1 = 0xebe78122;
    }
  }
  else {
    _Var1 = 0xebe78122;
    if (*(longlong *)(*(longlong *)(param_1 + -8) + 0x40) != 0) {
      _Var1 = 0xebe78172;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x77,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Receive_EvtCustomIoDefault @ 1c0009570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_EvtCustomIoDefault(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl Receive_EvtCustomIoDefault(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x69,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_RECEIVE_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023c40);
  lVar2 = *(longlong *)(lVar2 + 8);
  lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x68);
  (**(code **)(lVar2 + 0x48))
            (*(undefined8 *)(lVar2 + 8),param_2,*(undefined8 *)(lVar1 + 0x10),
             *(undefined4 *)(lVar1 + 0x18),CONCAT44(uVar3,*(undefined4 *)(lVar1 + 0x24)));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x6a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Transmit_EvtCustomIoDefault @ 1c0009660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_EvtCustomIoDefault(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64) */

void __cdecl Transmit_EvtCustomIoDefault(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6a,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_TRANSMIT_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023bf0);
  lVar2 = *(longlong *)(lVar2 + 8);
  lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x68);
  (**(code **)(lVar2 + 0x48))
            (*(undefined8 *)(lVar2 + 8),param_2,*(undefined8 *)(lVar1 + 0x10),
             *(undefined4 *)(lVar1 + 0x18),CONCAT44(uVar3,*(undefined4 *)(lVar1 + 0x24)));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_CleanupCustomTransaction2 @ 1c0009760 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupCustomTransaction2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupCustomTransaction2(void *param_1)

{
  Transfer_CleanupCustomTransaction(param_1);
  return 0;
}



===== Transfer_CleanupCustomTransaction @ 1c0009778 =====

/* void __cdecl Transfer_CleanupCustomTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CleanupCustomTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_CleanupCustomTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_CleanupCustomTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_CleanupCustomTransaction @ 1c000982c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_CleanupCustomTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_CleanupCustomTransaction(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x89,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x30) + 0x50))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Transmit_CleanupCustomTransaction @ 1c00098e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_CleanupCustomTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_CleanupCustomTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x86,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x30) + 0x50))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x87,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_IsCleanupCustomTransactionNeeded @ 1c00099a0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupCustomTransactionNeeded(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupCustomTransactionNeeded(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsCleanupCustomTransactionNeeded(param_1);
  return _Var1;
}



===== Transfer_IsCleanupCustomTransactionNeeded @ 1c00099c0 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsCleanupCustomTransactionNeeded(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_IsCleanupCustomTransactionNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x78,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = 0xebe78172;
    if (*(longlong *)(*(longlong *)(param_1 + -8) + 0x50) == 0) {
      _Var1 = 0xebe78122;
    }
  }
  else {
    _Var1 = 0xebe78122;
    if (*(longlong *)(*(longlong *)(param_1 + -8) + 0x50) != 0) {
      _Var1 = 0xebe78172;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x79,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== SerCx_PowerIrpPostprocess @ 1c0009a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SerCx_PowerIrpPostprocess(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void
   * __ptr64) */

long __cdecl SerCx_PowerIrpPostprocess(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  _IRP *p_Var5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x43,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,param_1);
  if (lVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_(0,2,8,0x44,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  else {
    lVar2 = *(longlong *)(param_2 + 0xb8);
    p_Var5 = param_2;
    iVar3 = IoGetActivityIdIrp(param_2,&local_38);
    iVar1 = *(int *)(lVar2 + 0x10);
    if (iVar1 == 0) {
      if ((DAT_1c0025a81 & 0x10) == 0) goto LAB_1c0009b47;
      puVar6 = &SerCx2EtwEventSystemPowerStateTransitionStop;
    }
    else {
      if ((iVar1 != 1) || ((DAT_1c0025a81 & 0x10) == 0)) goto LAB_1c0009b47;
      puVar6 = &SerCx2EtwEventDevicePowerStateTransitionStop;
    }
    puVar7 = &local_38;
    if (iVar3 < 0) {
      puVar7 = (undefined8 *)0x0;
    }
    McTemplateK0pdd_EtwWriteTransfer
              (p_Var5,puVar6,puVar7,lVar4,(char)*(undefined4 *)(lVar2 + 0x18),
               (char)*(undefined4 *)(param_2 + 0x30));
  }
LAB_1c0009b47:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x45,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return 0;
}



===== TransferStateEntryFunc_IsPioOnTimeoutUsingRegularPioMode @ 1c0009c60 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsPioOnTimeoutUsingRegularPioMode(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsPioOnTimeoutUsingRegularPioMode(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsPioOnTimeoutUsingRegularPioMode(param_1);
  return _Var1;
}



===== Transfer_IsPioOnTimeoutUsingRegularPioMode @ 1c0009c80 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsPioOnTimeoutUsingRegularPioMode(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_IsPioOnTimeoutUsingRegularPioMode(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x88,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe78172;
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x28) != -0x14187c7e) {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x89,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_IsSingleByteRequest @ 1c0009d40 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsSingleByteRequest(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsSingleByteRequest(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsSingleByteRequest(param_1);
  return _Var1;
}



===== Transfer_IsSingleByteRequest @ 1c0009d58 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsSingleByteRequest(struct _TRANSFER_SM_CONTEXT * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl Transfer_IsSingleByteRequest(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe78172;
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x1c) != 1) {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== TransferStateEntryFunc_CancelCustomTransaction1 @ 1c0009e10 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelCustomTransaction1(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelCustomTransaction1(void *param_1)

{
  Transfer_CancelCustomTransaction(param_1);
  return 0xebe78092;
}



===== Transfer_CancelCustomTransaction @ 1c0009e2c =====

/* void __cdecl Transfer_CancelCustomTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CancelCustomTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x80,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_CancelCustomTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_CancelCustomTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x81,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_CancelCustomTransaction @ 1c0009ee0 =====

/* void __cdecl Receive_CancelCustomTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_CancelCustomTransaction(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8f,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  IoCancelIrp(*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x28));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x90,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_IsCustomReceiveTransactionNewDataNotificationSupported @ 1c0009fa0 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_IsCustomReceiveTransactionNewDataNotificationSupported(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsCustomReceiveTransactionNewDataNotificationSupported(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsCustomReceiveTransactionNewDataNotificationSupported(param_1);
  return _Var1;
}



===== Transfer_IsCustomReceiveTransactionNewDataNotificationSupported @ 1c0009fb8 =====

/* enum _SM_ENGINE_EVENT __cdecl
   Transfer_IsCustomReceiveTransactionNewDataNotificationSupported(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_IsCustomReceiveTransactionNewDataNotificationSupported(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + -8) + 0x58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x7b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(lVar1 != 0) & 0x50) + 0xebe78122;
}



===== Timer_GetTimeouts @ 1c000a06c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Timer_GetTimeouts(struct _SERCX_TIMER_PRIVCONTEXT * __ptr64,unsigned long *
   __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) */

void __cdecl
Timer_GetTimeouts(_SERCX_TIMER_PRIVCONTEXT *param_1,ulong *param_2,ulong *param_3,ulong *param_4)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x17,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  if (param_3 != (ulong *)0x0) {
    *param_3 = *(ulong *)(param_1 + 0x2c);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = *(ulong *)(param_1 + 0x30);
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = *(ulong *)(param_1 + 0x28);
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x18,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_AcquirePowerReferenceSync @ 1c000a1a0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_AcquirePowerReferenceSync(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_AcquirePowerReferenceSync(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_AcquirePowerReferenceSync(param_1);
  return _Var1;
}



===== Transfer_AcquirePowerReferenceSync @ 1c000a1b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transfer_AcquirePowerReferenceSync(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_AcquirePowerReferenceSync(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  int iVar2;
  _SM_ENGINE_EVENT _Var3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x17,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x30);
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xdb0))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x10),1,0,0x156,
                     "onecore\\drivers\\serial\\sercx2\\sercx2\\sys\\transfer.cpp");
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x3d8),2,6,0x18,
                        &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,(char)iVar2);
    }
    Verifier_DbgBreak("The client may have sent an IO in an invalid state",0);
    *(int *)(lVar1 + 4) = iVar2;
    _Var3 = 0xebe78082;
  }
  else {
    _Var3 = 0xebe781e2;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x19,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var3;
}



===== File_EvtFileClose @ 1c000a310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl File_EvtFileClose(struct WDFFILEOBJECT__ * __ptr64) */

void __cdecl File_EvtFileClose(WDFFILEOBJECT__ *param_1)

{
  WDFDEVICE__ *pWVar1;
  longlong lVar2;
  WDFDEVICE__ *pWVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x15,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  pWVar1 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  pWVar3 = pWVar1;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,pWVar1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(longlong *)(lVar2 + 8) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),4,9,0x16,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  else {
    if (*(code **)(lVar2 + 0x38) != (code *)0x0) {
      (**(code **)(lVar2 + 0x38))(pWVar1);
    }
    if (*(longlong *)(lVar2 + 0xb8) != 0) {
      pWVar3 = (WDFDEVICE__ *)0x32584353;
      ExFreePoolWithTag();
      *(undefined8 *)(lVar2 + 0xb8) = 0;
    }
    if (*(int *)(lVar2 + 0x1a0) != 0) {
      SerCx_CloseFunctionConfigConnections(pWVar1);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(lVar2 + 0x130),pWVar3,9,0x17,
                      &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,(char)param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x18,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return;
}



===== Ioctl_EvtPassiveIoControl @ 1c000a4d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_EvtPassiveIoControl(struct WDFQUEUE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
Ioctl_EvtPassiveIoControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  char *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x54,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar5 = uVar3;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar3,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_5 == 0x1b004c) {
    uVar5 = CONCAT71((int7)((ulonglong)uVar5 >> 8),*(char *)(lVar4 + 0xe8));
    pcVar1 = (char *)(lVar4 + 0xe9);
    if ((*(char *)(lVar4 + 0xe8) != '\0') || (*pcVar1 != '\0')) {
      (**(code **)(lVar4 + 0x48))
                (*(undefined8 *)(lVar4 + 0x10),uVar5,
                 CONCAT71((int7)((ulonglong)pcVar1 >> 8),*pcVar1));
    }
    if (*(char *)(lVar4 + 0xe8) != '\0') {
      Receive_ResetRingBuffer(*(_RECEIVE_CONTEXT **)(lVar4 + 0xd0));
    }
    if ((*(char *)(lVar4 + 0xea) != '\0') || (*(char *)(lVar4 + 0xe8) != '\0')) {
      uVar5 = *(undefined8 *)(*(longlong *)(lVar4 + 0xd0) + 8);
      (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals);
    }
    if ((*(char *)(lVar4 + 0xeb) != '\0') || (*(char *)(lVar4 + 0xe9) != '\0')) {
      uVar5 = *(undefined8 *)(*(longlong *)(lVar4 + 200) + 8);
      (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals);
    }
    *(undefined8 *)(lVar4 + 0xe0) = 0;
    *(undefined4 *)(lVar4 + 0xe8) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar4 + 0x130),uVar5,8,0x55,
                        &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2);
    }
    uVar2 = 0;
  }
  else {
    if (param_5 != 0x1b00a0) goto LAB_1c000a5b2;
    if (*(longlong *)(lVar4 + 0xb8) == 0) {
      uVar2 = 0xc0000010;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x130),2,8,0x56,
                         &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
      }
    }
    else {
      uVar2 = (**(code **)(lVar4 + 0x58))(uVar3);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar2);
LAB_1c000a5b2:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x57,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== File_EvtFileCleanup @ 1c000a750 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl File_EvtFileCleanup(struct WDFFILEOBJECT__ * __ptr64) */

void __cdecl File_EvtFileCleanup(WDFFILEOBJECT__ *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x19,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  if (*(longlong *)(lVar2 + 8) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),4,9,0x1a,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1b,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_SetStatusForCancelledRequestIfNoBytesTransferred12 @ 1c000a870 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_SetStatusForCancelledRequestIfNoBytesTransferred12(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_SetStatusForCancelledRequestIfNoBytesTransferred12(void *param_1)

{
  Transfer_SetStatusForCancelledRequestIfNoBytesTransferred(param_1);
  return 0xebe78092;
}



===== Transfer_SetStatusForCancelledRequestIfNoBytesTransferred @ 1c000a88c =====

/* void __cdecl Transfer_SetStatusForCancelledRequestIfNoBytesTransferred(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl
Transfer_SetStatusForCancelledRequestIfNoBytesTransferred(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x18) == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 4) = 0xc0000120;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_q @ 1c000a948 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== Transfer_ProcessSystemDmaCompletion @ 1c000aa40 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_ProcessSystemDmaCompletion(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_ProcessSystemDmaCompletion(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = Transmit_ProcessSystemDmaCompletion((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    _Var1 = Receive_ProcessSystemDmaCompletion((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Transmit_ProcessSystemDmaCompletion @ 1c000aaf4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_ProcessSystemDmaCompletion(struct _TRANSMIT_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transmit_ProcessSystemDmaCompletion(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  ulong uVar5;
  int iVar6;
  undefined8 uVar7;
  _SM_ENGINE_EVENT _Var8;
  int iVar9;
  int local_res8 [2];
  undefined1 uVar10;
  
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar3 = *(undefined8 *)(lVar1 + 0x18);
  uVar5 = Transmit_DmaCounter(param_1);
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x368))(WdfDriverGlobals,uVar3);
  iVar9 = *(int *)(lVar1 + 0x9c);
  if ((iVar9 == 0) && (*(char *)(lVar2 + 0x38) != '\0')) {
    iVar9 = 3;
  }
  *(undefined1 *)(lVar2 + 0x38) = 0;
  if (iVar9 == 0) {
    cVar4 = (**(code **)(WdfFunctions_01015 + 0x338))(WdfDriverGlobals,uVar3,local_res8);
    if (cVar4 == '\0') {
      _Var8 = 0xebe78192;
      goto LAB_1c000ad3c;
    }
    _Var8 = 0xebe78102;
    if (local_res8[0] < 0) {
      _Var8 = 0xebe78112;
    }
  }
  else if (iVar9 == 3) {
    (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar3,iVar6 - uVar5,local_res8);
    _Var8 = 0xebe780f2;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar3,iVar6 - uVar5,local_res8);
    _Var8 = 0xebe78112;
  }
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x350))(WdfDriverGlobals,uVar3);
  *(int *)(lVar2 + 0x20) = *(int *)(lVar2 + 0x20) + (int)uVar7;
  iVar9 = *(int *)(lVar2 + 0x18) + (int)uVar7;
  *(int *)(lVar2 + 0x18) = iVar9;
  if (_Var8 == 0xebe78112) {
    *(int *)(lVar2 + 4) = local_res8[0];
  }
  uVar10 = (undefined1)iVar9;
  if (local_res8[0] < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqddd
                (*(undefined8 *)(param_1 + 0x410),uVar7,5,0x3e,
                 &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)lVar1,(char)lVar2,
                 (char)uVar7,uVar10,(char)local_res8[0]);
    }
  }
  else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
          (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqdd
              (*(undefined8 *)(param_1 + 0x410),5,5,0x3d,
               &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)lVar1,(char)lVar2,(char)uVar7,
               uVar10);
  }
  (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,uVar3);
LAB_1c000ad3c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3f,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return _Var8;
}



===== Receive_ProcessSystemDmaCompletion @ 1c000ad90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Receive_ProcessSystemDmaCompletion(struct _RECEIVE_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Receive_ProcessSystemDmaCompletion(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  char cVar4;
  ulong uVar5;
  int iVar6;
  undefined8 uVar7;
  _SM_ENGINE_EVENT _Var8;
  int iVar9;
  int local_res8 [2];
  undefined1 uVar10;
  
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x36,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar3 = *(undefined8 *)(lVar1 + 0x18);
  uVar5 = Receive_DmaCounter(param_1);
  iVar6 = (**(code **)(WdfFunctions_01015 + 0x368))(WdfDriverGlobals,uVar3);
  iVar9 = *(int *)(lVar1 + 0x94);
  if ((iVar9 == 0) && (*(char *)(lVar2 + 0x38) != '\0')) {
    iVar9 = 3;
  }
  *(undefined1 *)(lVar2 + 0x38) = 0;
  if (iVar9 == 0) {
    *(undefined1 *)(lVar1 + 0x9a) = 1;
    cVar4 = (**(code **)(WdfFunctions_01015 + 0x338))(WdfDriverGlobals,uVar3,local_res8);
    if (cVar4 == '\0') {
      *(undefined4 *)(lVar1 + 0x9c) = 0;
      _Var8 = 0xebe78192;
      goto LAB_1c000b031;
    }
    _Var8 = 0xebe78102;
    if (local_res8[0] < 0) {
      _Var8 = 0xebe78112;
    }
  }
  else if (iVar9 == 3) {
    if (uVar5 != *(ulong *)(lVar1 + 0x9c)) {
      *(undefined1 *)(lVar1 + 0x9a) = 1;
    }
    (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar3,iVar6 - uVar5,local_res8);
    _Var8 = 0xebe780f2;
  }
  else {
    if (uVar5 != *(ulong *)(lVar1 + 0x9c)) {
      *(undefined1 *)(lVar1 + 0x9a) = 1;
    }
    (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar3,iVar6 - uVar5,local_res8);
    _Var8 = 0xebe78112;
  }
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x350))(WdfDriverGlobals,uVar3);
  *(int *)(lVar2 + 0x20) = *(int *)(lVar2 + 0x20) + (int)uVar7;
  iVar9 = *(int *)(lVar2 + 0x18) + (int)uVar7;
  *(int *)(lVar2 + 0x18) = iVar9;
  if (_Var8 == 0xebe78112) {
    *(int *)(lVar2 + 4) = local_res8[0];
  }
  uVar10 = (undefined1)iVar9;
  if (local_res8[0] < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqddd
                (*(undefined8 *)(param_1 + 0x410),uVar7,7,0x38,
                 &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar1,(char)lVar2,
                 (char)uVar7,uVar10,(char)local_res8[0]);
    }
  }
  else if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
          (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqdd
              (*(undefined8 *)(param_1 + 0x410),5,7,0x37,
               &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar1,(char)lVar2,(char)uVar7,
               uVar10);
  }
  (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,uVar3);
LAB_1c000b031:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x39,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return _Var8;
}



===== Receive_DmaCounter @ 1c000b084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned long __cdecl Receive_DmaCounter(struct _RECEIVE_CONTEXT * __ptr64) */

ulong __cdecl Receive_DmaCounter(_RECEIVE_CONTEXT *param_1)

{
  ulong uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0x88) + 8) + 0x50
                      ))();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),5,7,0x2c,
                        &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)uVar1);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2d,
                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
    }
  }
  return uVar1;
}



===== WPP_RECORDER_SF_d @ 1c000b17c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== TransferStateEntryFunc_CancelPioFifoDrain @ 1c000b280 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelPioFifoDrain(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelPioFifoDrain(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_CancelPioFifoDrain(param_1);
  return _Var1;
}



===== Transfer_CancelPioFifoDrain @ 1c000b298 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_CancelPioFifoDrain(struct _TRANSFER_SM_CONTEXT * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl Transfer_CancelPioFifoDrain(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x68,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = Transmit_CancelPioFifoDrain((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x69,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Transmit_CancelPioFifoDrain @ 1c000b344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_CancelPioFifoDrain(struct _TRANSMIT_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transmit_CancelPioFifoDrain(_TRANSMIT_CONTEXT *param_1)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x52,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  cVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x50))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x53,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return (-(uint)(cVar1 != '\0') & 0x10) + 0xebe78082;
}



===== TransferStateEntryFunc_ProgramSystemDmaTransaction @ 1c000b400 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ProgramSystemDmaTransaction(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ProgramSystemDmaTransaction(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_ProgramSystemDmaTransaction(param_1);
  return _Var1;
}



===== Transfer_ProgramSystemDmaTransaction @ 1c000b418 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_ProgramSystemDmaTransaction(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_ProgramSystemDmaTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  int iVar1;
  _SM_ENGINE_EVENT _Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    iVar1 = Transmit_ProgramSystemDmaTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    iVar1 = Receive_ProgramSystemDmaTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (iVar1 < 0) {
    _Var2 = 0xebe78082;
    *(int *)(*(longlong *)(param_1 + 0x30) + 4) = iVar1;
  }
  else {
    _Var2 = 0xebe78092;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var2;
}



===== Receive_ProgramSystemDmaTransaction @ 1c000b4ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Receive_ProgramSystemDmaTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

long __cdecl Receive_ProgramSystemDmaTransaction(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x40,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar2 = *(longlong *)(param_1 + 0x20);
  iVar3 = (**(code **)(WdfFunctions_01015 + 0xcb0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Receive_EvtProgramDma,0,
                     *(undefined8 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x18),
                     *(int *)(lVar1 + 0x24) - *(int *)(lVar1 + 0x20));
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),2,7,0x41,
                      &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)iVar3);
  }
  else {
    if (*(longlong *)(lVar2 + 0x70) != 0) {
      (**(code **)(WdfFunctions_01015 + 0xcc0))
                (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Receive_EvtConfigureDmaChannel,
                 param_1);
    }
    (**(code **)(WdfFunctions_01015 + 0xcc8))
              (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Receive_EvtDmaCompletion,param_1);
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x328))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),lVar1);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),2,7,0x42,
                          &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)iVar3);
      }
      (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18));
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x43,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return iVar3;
}



===== Transmit_ProgramSystemDmaTransaction @ 1c000b6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Transmit_ProgramSystemDmaTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

long __cdecl Transmit_ProgramSystemDmaTransaction(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x46,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  lVar2 = *(longlong *)(param_1 + 0x20);
  iVar3 = (**(code **)(WdfFunctions_01015 + 0xcb0))
                    (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Transmit_EvtProgramDma,1,
                     *(undefined8 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x18),
                     *(int *)(lVar1 + 0x24) - *(int *)(lVar1 + 0x20));
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),2,5,0x47,
                      &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)iVar3);
  }
  else {
    if (*(longlong *)(lVar2 + 0x70) != 0) {
      (**(code **)(WdfFunctions_01015 + 0xcc0))
                (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Transmit_EvtConfigureDmaChannel,
                 param_1);
    }
    (**(code **)(WdfFunctions_01015 + 0xcc8))
              (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),Transmit_EvtDmaCompletion,param_1);
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x328))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18),lVar1);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),2,5,0x48,
                          &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)iVar3);
      }
      (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x18));
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x49,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return iVar3;
}



===== TransferStateEntryFunc_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded4 @ 1c000b900 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded4(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded4(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded(param_1);
  return _Var1;
}



===== Transfer_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded @ 1c000b918 =====

/* enum _SM_ENGINE_EVENT __cdecl
   Transfer_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_IsTransmitTransactionAndSystemDmaFifoDrainOrPurgeNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = (-(uint)(*(longlong *)(*(longlong *)(param_1 + -0x18) + 0x78) != 0) & 0x50) + 0xebe78122
    ;
  }
  else {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== _SerCx2SaveReceiveFifoOnD0Exit @ 1c000b9e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SaveReceiveFifoOnD0Exit(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2PIORECEIVE__ * __ptr64,unsigned long) */

void __cdecl
_SerCx2SaveReceiveFifoOnD0Exit
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2PIORECEIVE__ *param_2,ulong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulong local_res18 [2];
  uchar *local_res20;
  
  uVar6 = (ulonglong)param_3;
  local_res18[0] = 0;
  local_res20 = (uchar *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x16,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  uVar4 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68);
  lVar1 = *(longlong *)(lVar5 + 0x10);
  uVar2 = *(undefined8 *)(lVar1 + 0x410);
  RingBuffer_GetBuffer
            (*(_SERCX_RING_BUFFER_PRIVCONTEXT **)(lVar5 + 0x48),param_3,&local_res20,local_res18);
  uVar3 = local_res18[0];
  if ((local_res18[0] != param_3) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_dd(uVar2,uVar6,7,0x17,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                       (char)param_3,(char)local_res18[0]);
  }
  if (uVar3 != 0) {
    *(undefined1 *)(lVar5 + 0x50) = 1;
    if (*(longlong *)(lVar5 + 0x20) != 0) {
      KeResetEvent(lVar5 + 0x58);
      (**(code **)(lVar5 + 0x20))(*(undefined8 *)(lVar5 + 8),uVar3);
      KeWaitForSingleObject(lVar5 + 0x58,0,0,0,0);
      if (*(char *)(lVar5 + 0x51) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(lVar1 + 0x410),2,7,0x18,
                           &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
        }
        *(undefined1 *)(lVar5 + 0x50) = 0;
        goto LAB_1c000bc26;
      }
    }
    uVar4 = (**(code **)(lVar5 + 0x30))(param_2,local_res20,uVar3);
    if (*(longlong *)(lVar5 + 0x28) != 0) {
      KeResetEvent(lVar5 + 0x58);
      (**(code **)(lVar5 + 0x28))(*(undefined8 *)(lVar5 + 8));
      KeWaitForSingleObject(lVar5 + 0x58,0,0,0,0);
    }
    *(undefined1 *)(lVar5 + 0x50) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(uVar2,4,7,0x19,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar5
                         ,(char)uVar4);
    }
    if ((DAT_1c0025a81 & 4) != 0) {
      McTemplateK0pqq_EtwWriteTransfer();
    }
  }
LAB_1c000bc26:
  RingBuffer_PutBuffer(*(_SERCX_RING_BUFFER_PRIVCONTEXT **)(lVar5 + 0x48),uVar4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== RingBuffer_GetBuffer @ 1c000bc90 =====

/* void __cdecl RingBuffer_GetBuffer(struct _SERCX_RING_BUFFER_PRIVCONTEXT * __ptr64,unsigned
   long,unsigned char * __ptr64 * __ptr64,unsigned long * __ptr64) */

void __cdecl
RingBuffer_GetBuffer
          (_SERCX_RING_BUFFER_PRIVCONTEXT *param_1,ulong param_2,uchar **param_3,ulong *param_4)

{
  uint uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xd,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  uVar1 = *(int *)(param_1 + 0x18) - *(uint *)(param_1 + 0x1c);
  param_1[0x20] = (_SERCX_RING_BUFFER_PRIVCONTEXT)0x1;
  if (param_2 < uVar1) {
    uVar1 = param_2;
  }
  *param_3 = (uchar *)((ulonglong)*(uint *)(param_1 + 0x1c) + *(longlong *)(param_1 + 0x10));
  *param_4 = uVar1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xe,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  return;
}



===== TransferStateEntryFunc_IsCleanupSystemDmaTransactionNeeded2 @ 1c000bd60 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupSystemDmaTransactionNeeded2(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsCleanupSystemDmaTransactionNeeded2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsCleanupSystemDmaTransactionNeeded(param_1);
  return _Var1;
}



===== Transfer_IsCleanupSystemDmaTransactionNeeded @ 1c000bd78 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsCleanupSystemDmaTransactionNeeded(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_IsCleanupSystemDmaTransactionNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + -0x18) + 0x68);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(lVar1 != 0) & 0x50) + 0xebe78122;
}



===== SerCx_PowerSettingCallback @ 1c000be30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl SerCx_PowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned
   long,void * __ptr64) */

long __cdecl SerCx_PowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  char cVar1;
  longlong lVar2;
  
  cVar1 = *(char *)param_2;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_4,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x170));
  if ((cVar1 != *(char *)(lVar2 + 0x178)) &&
     (*(char *)(lVar2 + 0x178) = cVar1, *(int *)(lVar2 + 0x17c) != 0)) {
    if (cVar1 == '\0') {
      *(longlong *)(lVar2 + 0x188) =
           *(longlong *)(lVar2 + 0x188) + (_DAT_fffff78000000008 - *(longlong *)(lVar2 + 0x180));
    }
    else {
      *(longlong *)(lVar2 + 0x180) = _DAT_fffff78000000008;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x170));
  return 0;
}



===== TransferStateEntryFunc_CancelSystemDmaTransfer @ 1c000bf10 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaTransfer(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaTransfer(void *param_1)

{
  Transfer_CancelSystemDmaTransfer(param_1);
  return 0xebe78092;
}



===== Transfer_CancelSystemDmaTransfer @ 1c000bf2c =====

/* void __cdecl Transfer_CancelSystemDmaTransfer(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CancelSystemDmaTransfer(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x52,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_CancelSystemDmaTransfer((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_CancelSystemDmaTransfer((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x53,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_CancelSystemDmaTransfer @ 1c000bfdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_CancelSystemDmaTransfer(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_CancelSystemDmaTransfer(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x46,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x38) = 1;
  (**(code **)(WdfFunctions_01015 + 0xd50))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x18));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x47,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== McGenControlCallbackV2 @ 1c000c0a0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== Transfer_InitializeSystemDmaTransaction @ 1c000c1b0 =====

/* void __cdecl Transfer_InitializeSystemDmaTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_InitializeSystemDmaTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_InitializeSystemDmaTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_InitializeSystemDmaTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x4b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_InitializeSystemDmaTransaction @ 1c000c260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_InitializeSystemDmaTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_InitializeSystemDmaTransaction(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x34,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x60))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8),
             *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x24));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x35,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== SerCx_WnfPdcCallback @ 1c000c320 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl SerCx_WnfPdcCallback(struct _EX_WNF_SUBSCRIPTION * __ptr64,struct _WNF_STATE_NAME
   const * __ptr64,unsigned long,unsigned long,struct _WNF_TYPE_ID const * __ptr64,void * __ptr64)
    */

long __cdecl
SerCx_WnfPdcCallback
          (_EX_WNF_SUBSCRIPTION *param_1,_WNF_STATE_NAME *param_2,ulong param_3,ulong param_4,
          _WNF_TYPE_ID *param_5,void *param_6)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 auStackY_b8 [32];
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_40 = 0;
  local_58 = 0x18;
  local_54 = 0;
  local_20 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  iVar1 = ExQueryWnfStateData(*(undefined8 *)((longlong)param_6 + 0x150),&local_54,&local_40,
                              &local_58);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)((longlong)param_6 + 0x130),2,0x10,0x46,
                        &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar1);
    }
  }
  else {
    lVar2 = CONCAT44(uStack_3c,local_40) + -0x44fd8b8ecc99192b;
    if (lVar2 == 0) {
      lVar2 = CONCAT44(uStack_34,uStack_38) + -0x294d1b1462efa9b0;
    }
    bVar3 = lVar2 == 0;
    if ((bool)*(char *)((longlong)param_6 + 0x168) != bVar3) {
      *(bool *)((longlong)param_6 + 0x168) = bVar3;
      if (bVar3) {
        *(ulonglong *)((longlong)param_6 + 0x160) = CONCAT44(uStack_2c,uStack_30);
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
        *(undefined8 *)((longlong)param_6 + 0x188) = 0;
        (**(code **)(WdfFunctions_01015 + 0x9e8))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_6 + 0x170));
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x9e0))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_6 + 0x170));
        if ((*(int *)((longlong)param_6 + 0x17c) != 0) &&
           (*(char *)((longlong)param_6 + 0x178) != '\0')) {
          *(longlong *)((longlong)param_6 + 0x188) =
               *(longlong *)((longlong)param_6 + 0x188) +
               (_DAT_fffff78000000008 - *(longlong *)((longlong)param_6 + 0x180));
        }
        lVar2 = *(longlong *)((longlong)param_6 + 0x188);
        (**(code **)(WdfFunctions_01015 + 0x9e8))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)param_6 + 0x170));
        if (lVar2 != 0) {
          local_20 = 0;
          local_50 = 0;
          local_28 = (**(code **)(WdfFunctions_01015 + 0x108))
                               (WdfDriverGlobals,*(undefined8 *)((longlong)param_6 + 0x10));
          local_48 = *(undefined8 *)((longlong)param_6 + 0xc0);
          local_50 = local_50 & 0xfdffffffffffffff | 0x100000000000000;
          if ((Microsoft_Windows_SleepStudyEnableBits & 1) != 0) {
            McTemplateK0ujqzr2jxxx_EtwWriteTransfer();
          }
        }
      }
    }
  }
  return 0;
}



===== Receive_EvtProgramDma @ 1c000c570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_EvtProgramDma(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST *
   __ptr64) */

uchar __cdecl
Receive_EvtProgramDma
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 in_register_0000008c;
  
  uVar2 = WdfDriverGlobals;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0,
                     CONCAT44(in_register_0000008c,param_4));
  if ((DAT_1c0025a81 & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (uVar2,&SerCx2EtwEventSystemDmaEvent,*(longlong *)(lVar1 + 0xd0) + 0x58,param_2,2);
  }
  return '\x01';
}



===== SerCx_TryToPurgeIoOnSx @ 1c000c5d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl SerCx_TryToPurgeIoOnSx(struct WDFDEVICE__ * __ptr64) */

void __cdecl SerCx_TryToPurgeIoOnSx(WDFDEVICE__ *param_1)

{
  byte bVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x41,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar2 != 0) {
    bVar1 = (**(code **)(WdfFunctions_01015 + 0x4c8))
                      (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x118),0,0);
    if ((bVar1 & 0xc) == 0xc) {
      bVar1 = (**(code **)(WdfFunctions_01015 + 0x4c8))
                        (WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x110),0,0);
      if ((bVar1 & 0xc) == 0xc) {
        bVar1 = (**(code **)(WdfFunctions_01015 + 0x4c8))
                          (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 0xd0) + 8),0,0);
        if ((bVar1 & 0xc) != 0xc) {
          Verifier_DbgBreak("Client driver has pending Reads while going in Sx",1);
          if ((bVar1 & 0x13) == 3) {
            (**(code **)(WdfFunctions_01015 + 0x520))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 0xd0) + 8));
            (**(code **)(WdfFunctions_01015 + 0x4d0))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 0xd0) + 8));
          }
        }
        bVar1 = (**(code **)(WdfFunctions_01015 + 0x4c8))
                          (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 200) + 8),0,0);
        if ((bVar1 & 0xc) != 0xc) {
          Verifier_DbgBreak("Client driver has pending Writes while going in Sx",1);
          if ((bVar1 & 0x13) == 3) {
            (**(code **)(WdfFunctions_01015 + 0x520))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 200) + 8));
            (**(code **)(WdfFunctions_01015 + 0x4d0))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar2 + 200) + 8));
          }
        }
        goto LAB_1c000c80e;
      }
      pcVar3 = "Client driver has pending IOCTL while going in Sx";
    }
    else {
      pcVar3 = "Client driver has pending Ioctls while going in Sx";
    }
    Verifier_DbgBreak(pcVar3,1);
  }
LAB_1c000c80e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x42,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return;
}



===== Receive_CleanupSystemDmaTransaction @ 1c000c860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_CleanupSystemDmaTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_CleanupSystemDmaTransaction(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x44,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x68))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x45,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Transmit_EnablePioReadyNotification @ 1c000c90c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_EnablePioReadyNotification(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_EnablePioReadyNotification(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2f,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x38))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x30,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transfer_PioPurgeFifo @ 1c000c9b8 =====

/* void __cdecl Transfer_PioPurgeFifo(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_PioPurgeFifo(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Transmit_PioPurgeFifo((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Receive_EvtConfigureDmaChannel @ 1c000ca60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_EvtConfigureDmaChannel(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,struct _MDL * __ptr64,unsigned __int64,unsigned __int64) */

uchar __cdecl
Receive_EvtConfigureDmaChannel
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,_MDL *param_4,
          __uint64 param_5,__uint64 param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  _SM_ENGINE_CONTEXT *p_Var4;
  uchar uVar5;
  
  lVar1 = *(longlong *)((longlong)param_3 + 0x20);
  uVar5 = '\0';
  lVar2 = *(longlong *)((longlong)param_3 + 0x68);
  p_Var4 = *(_SM_ENGINE_CONTEXT **)(lVar1 + 8);
  if (param_4 == (_MDL *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      p_Var4 = *(_SM_ENGINE_CONTEXT **)((longlong)param_3 + 0x410);
      WPP_RECORDER_SF_qq(p_Var4,param_2,7,0x3e,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                         (char)lVar1,(char)lVar2);
    }
  }
  else {
    iVar3 = (**(code **)(lVar1 + 0x70))(p_Var4,param_4,param_5 & 0xffffffff,param_6 & 0xffffffff);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqdd
                  (*(undefined8 *)((longlong)param_3 + 0x410),2,7,0x3f,
                   &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)lVar1,(char)lVar2,
                   (char)*(undefined4 *)(lVar2 + 0x18),(char)iVar3);
      }
      p_Var4 = (_SM_ENGINE_CONTEXT *)((longlong)param_3 + 0x78);
      *(int *)(lVar2 + 4) = iVar3;
      StateMachineEngine_EventAdd(p_Var4,0xebe781a0);
      goto LAB_1c000cacd;
    }
  }
  uVar5 = '\x01';
LAB_1c000cacd:
  if ((DAT_1c0025a81 & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (p_Var4,&SerCx2EtwEventSystemDmaEvent,(longlong)param_3 + 0x58,param_2,4);
  }
  return uVar5;
}



===== TransferStateEntryFunc_IsInitializeSystemDmaTransactionNeeded @ 1c000cba0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsInitializeSystemDmaTransactionNeeded(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsInitializeSystemDmaTransactionNeeded(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsInitializeSystemDmaTransactionNeeded(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_IsSystemDmaNewDataNotificationEnabled4 @ 1c000cbc0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsSystemDmaNewDataNotificationEnabled4(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsSystemDmaNewDataNotificationEnabled4(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsSystemDmaNewDataNotificationEnabled(param_1);
  return _Var1;
}



===== Transfer_IsSystemDmaNewDataNotificationEnabled @ 1c000cbd8 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsSystemDmaNewDataNotificationEnabled(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_IsSystemDmaNewDataNotificationEnabled(_TRANSFER_SM_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x58,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    uVar1 = '\0';
  }
  else {
    uVar1 = Receive_IsSystemDmaNewDataNotificationEnabled((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x59,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(uVar1 != '\0') & 0x50) + 0xebe78122;
}



===== Receive_IsSystemDmaNewDataNotificationEnabled @ 1c000cc94 =====

/* unsigned char __cdecl Receive_IsSystemDmaNewDataNotificationEnabled(struct _RECEIVE_CONTEXT *
   __ptr64) */

uchar __cdecl Receive_IsSystemDmaNewDataNotificationEnabled(_RECEIVE_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4c,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  uVar1 = *(uchar *)(*(longlong *)(param_1 + 0x20) + 0x98);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4d,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return uVar1;
}



===== SerCx_QueryFriendlyName @ 1c000cd3c =====

/* long __cdecl SerCx_QueryFriendlyName(struct WDFDEVICE__ * __ptr64,struct _SERCX_CONTEXT *
   __ptr64) */

long __cdecl SerCx_QueryFriendlyName(WDFDEVICE__ *param_1,_SERCX_CONTEXT *param_2)

{
  long lVar1;
  
  lVar1 = SerCx_QueryFriendlyNameFromRegistry(param_1,param_2);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(0,3,10,0x52,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)lVar1);
    }
    lVar1 = SerCx_QueryFriendlyNameFromAcpi(param_1,param_2);
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(0,3,10,0x54,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)lVar1);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(0,4,10,0x53,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
    }
    lVar1 = 0;
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(0,4,10,0x51,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar1;
}



===== SerCx_QueryFriendlyNameFromRegistry @ 1c000ce4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_QueryFriendlyNameFromRegistry(struct WDFDEVICE__ * __ptr64,struct
   _SERCX_CONTEXT * __ptr64) */

long __cdecl SerCx_QueryFriendlyNameFromRegistry(WDFDEVICE__ *param_1,_SERCX_CONTEXT *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  int local_res20 [2];
  longlong local_38 [4];
  
  local_38[0] = 0;
  local_res18[0] = 0;
  lVar2 = 0;
  local_res20[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))(WdfDriverGlobals,param_1,1,0x20019,0,local_38);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_38 + 1,L"SerCxFriendlyName");
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))
                      (WdfDriverGlobals,local_38[0],local_38 + 1,0,0,local_res18,local_res20);
    if (iVar1 == -0x7ffffffb) {
      if (local_res20[0] == 1) {
        lVar2 = ExAllocatePool2(0x40,local_res18[0],0x32584353);
        if (lVar2 == 0) {
          iVar1 = -0x3fffff66;
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x758))
                            (WdfDriverGlobals,local_38[0],local_38 + 1,local_res18[0],lVar2,0,0);
          if (-1 < iVar1) {
            RtlInitUnicodeString(param_2 + 0x1a8,lVar2);
          }
        }
      }
      else {
        iVar1 = -0x3ffffff3;
      }
    }
  }
  if (local_38[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if ((iVar1 < 0) && (lVar2 != 0)) {
    ExFreePoolWithTag(lVar2,0x32584353);
  }
  return iVar1;
}



===== Transmit_DmaCounter @ 1c000cff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned long __cdecl Transmit_DmaCounter(struct _TRANSMIT_CONTEXT * __ptr64) */

ulong __cdecl Transmit_DmaCounter(_TRANSMIT_CONTEXT *param_1)

{
  ulong uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x35,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0x90) + 8) + 0x50
                      ))();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x410),5,5,0x36,
                        &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)uVar1);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x37,
                       &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
    }
  }
  return uVar1;
}



===== RingBuffer_PutBuffer @ 1c000d0f4 =====

/* void __cdecl RingBuffer_PutBuffer(struct _SERCX_RING_BUFFER_PRIVCONTEXT * __ptr64,unsigned long)
    */

void __cdecl RingBuffer_PutBuffer(_SERCX_RING_BUFFER_PRIVCONTEXT *param_1,ulong param_2)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xf,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  param_1[0x20] = (_SERCX_RING_BUFFER_PRIVCONTEXT)0x0;
  *(ulong *)(param_1 + 0x1c) = iVar1 + param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qdd(*(undefined8 *)(param_1 + 0x28),4,0xe,0x10,
                        &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids,(char)param_1,(char)param_2
                        ,(char)(iVar1 + param_2));
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0x11,
                       &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
    }
  }
  return;
}



===== Transmit_CancelSystemDmaTransfer @ 1c000d1d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_CancelSystemDmaTransfer(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_CancelSystemDmaTransfer(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x38) = 1;
  (**(code **)(WdfFunctions_01015 + 0xd50))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x18));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4d,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transfer_IsInitializeSystemDmaTransactionNeeded @ 1c000d2a0 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsInitializeSystemDmaTransactionNeeded(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_IsInitializeSystemDmaTransactionNeeded(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x48,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + -0x18) + 0x60);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x49,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(lVar1 != 0) & 0x50) + 0xebe78122;
}



===== Transmit_PioPurgeFifo @ 1c000d354 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_PioPurgeFifo(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_PioPurgeFifo(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x54,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x58))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8),
             *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x20));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x55,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_InitializeSystemDmaTransaction @ 1c000d408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_InitializeSystemDmaTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_InitializeSystemDmaTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3a,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x60))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8),
             *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x24));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x3b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_CancelPioReadyNotification @ 1c000d4bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Transmit_CancelPioReadyNotification(struct _TRANSMIT_CONTEXT * __ptr64) */

uchar __cdecl Transmit_CancelPioReadyNotification(_TRANSMIT_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x31,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x18) + 0x40))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x32,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return uVar1;
}



===== TransferStateEntryFunc_ProcessSystemDmaCompletion @ 1c000d570 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ProcessSystemDmaCompletion(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ProcessSystemDmaCompletion(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_ProcessSystemDmaCompletion(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_InitializeSystemDmaTransaction @ 1c000d590 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializeSystemDmaTransaction(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializeSystemDmaTransaction(void *param_1)

{
  Transfer_InitializeSystemDmaTransaction(param_1);
  return 0;
}



===== __report_gsfailure @ 1c000d5c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlUnicodeStringPrintf @ 1c000d5d0 =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  ulonglong _Count;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *(ushort *)param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 2), (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((lVar5 = 0, *(longlong *)(param_1 + 8) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(*(ushort *)(param_1 + 2) >> 1);
    local_res18 = in_R8;
    local_res20 = in_R9;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 8),_Count,(wchar_t *)param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      lVar5 = -0x7ffffffb;
      uVar4 = _Count;
    }
    *(short *)param_1 = (short)uVar4 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== CxBindClient @ 1c000d670 =====

undefined4 CxBindClient(longlong param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined8 *puVar5;
  undefined **ppuVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  longlong lVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1b,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  iVar8 = *(int *)(param_1 + 0x10);
  if (iVar8 == 2) {
    iVar8 = *(int *)(param_1 + 0x14);
    if (iVar8 == 0) {
      if (*(int *)(param_1 + 0x28) == 0x23) {
        ppuVar4 = &PTR__SerCx2InitializeDeviceInit_1c0022038;
        puVar5 = *(undefined8 **)(param_1 + 0x20);
        lVar11 = 2;
        do {
          lVar10 = lVar11;
          puVar9 = puVar5;
          ppuVar6 = ppuVar4;
          puVar3 = ppuVar6[1];
          *puVar9 = *ppuVar6;
          puVar9[1] = puVar3;
          puVar3 = ppuVar6[3];
          puVar9[2] = ppuVar6[2];
          puVar9[3] = puVar3;
          puVar3 = ppuVar6[5];
          puVar9[4] = ppuVar6[4];
          puVar9[5] = puVar3;
          puVar3 = ppuVar6[7];
          puVar9[6] = ppuVar6[6];
          puVar9[7] = puVar3;
          puVar3 = ppuVar6[9];
          puVar9[8] = ppuVar6[8];
          puVar9[9] = puVar3;
          puVar3 = ppuVar6[0xb];
          puVar9[10] = ppuVar6[10];
          puVar9[0xb] = puVar3;
          puVar3 = ppuVar6[0xd];
          puVar9[0xc] = ppuVar6[0xc];
          puVar9[0xd] = puVar3;
          uVar12 = *(undefined4 *)((longlong)ppuVar6 + 0x74);
          uVar1 = *(undefined4 *)(ppuVar6 + 0xf);
          uVar2 = *(undefined4 *)((longlong)ppuVar6 + 0x7c);
          *(undefined4 *)(puVar9 + 0xe) = *(undefined4 *)(ppuVar6 + 0xe);
          *(undefined4 *)((longlong)puVar9 + 0x74) = uVar12;
          *(undefined4 *)(puVar9 + 0xf) = uVar1;
          *(undefined4 *)((longlong)puVar9 + 0x7c) = uVar2;
          lVar11 = lVar10 + -1;
          ppuVar4 = ppuVar6 + 0x10;
          puVar5 = puVar9 + 0x10;
        } while (lVar11 != 0);
        uVar12 = *(undefined4 *)((longlong)ppuVar6 + 0x84);
        uVar1 = *(undefined4 *)(ppuVar6 + 0x11);
        uVar2 = *(undefined4 *)((longlong)ppuVar6 + 0x8c);
        *(undefined4 *)(puVar9 + 0x10) = *(undefined4 *)(ppuVar6 + 0x10);
        *(undefined4 *)((longlong)puVar9 + 0x84) = uVar12;
        *(undefined4 *)(puVar9 + 0x11) = uVar1;
        *(undefined4 *)((longlong)puVar9 + 0x8c) = uVar2;
        puVar9[0x12] = ppuVar6[0x12];
        iVar8 = (int)lVar10 + 0x3f;
        puVar7 = (undefined4 *)ExAllocatePool2(iVar8,iVar8,0x32786353);
        if (puVar7 == (undefined4 *)0x0) {
          uVar12 = 0xc000009a;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000009a;
          }
          WPP_RECORDER_SF_d(0,2,1,0x1f,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,0x9a);
        }
        else {
          *puVar7 = 0x32786353;
          uVar12 = 0;
          **(undefined8 **)(param_1 + 0x30) = puVar7 + 2;
        }
      }
      else {
        uVar12 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000000d;
        }
        WPP_RECORDER_SF_LLd();
      }
      goto LAB_1c000d811;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar13 = 0x1d;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar13 = 0x1c;
  }
  uVar12 = 0xc000000d;
  WPP_RECORDER_SF_L(0,2,1,uVar13,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,(char)iVar8);
LAB_1c000d811:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x20,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  return uVar12;
}



===== CxDeinitialize @ 1c000d870 =====

void CxDeinitialize(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
  }
  return;
}



===== CxInitialize @ 1c000d900 =====

undefined8 CxInitialize(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x17,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x18,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
  }
  return 0;
}



===== CxUnbindClient @ 1c000d990 =====

void CxUnbindClient(longlong param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x21,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  lVar1 = **(longlong **)(param_1 + 0x30);
  if (lVar1 != 0) {
    Verfier_VerifyPrivateGlobals((_SERCX_CLIENT_GLOBALS *)(lVar1 + -8));
    ExFreePoolWithTag(lVar1 + -8,0);
    **(undefined8 **)(param_1 + 0x30) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x22,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  return;
}



===== DriverEntry @ 1c000da6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  _SERCX_DRIVER_CONTEXT *p_Var1;
  bool bVar2;
  int iVar3;
  _SERCX_DRIVER_CONTEXT *p_Var4;
  undefined8 *puVar5;
  uint uVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_1d8 [32];
  longlong local_198;
  undefined8 local_190;
  undefined1 *local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined *local_148;
  undefined8 local_140;
  undefined8 local_138;
  code *local_130;
  undefined8 local_128;
  undefined1 local_118 [208];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_190 = 0xc80000;
  local_188 = local_118;
  local_180 = 0;
  local_198 = 0;
  _WPP_MAIN_CB = 0;
  _DAT_1c0025b08 = 1;
  bVar2 = false;
  DAT_1c0025ae8 = &WPP_ThisDir_CTLGUID_SerCx2TraceGuid;
  DAT_1c0025af0 = 0;
  _DAT_1c0025b00 = 0;
  _DAT_1c0025b20 = 0;
  _DAT_1c0025b28 = 0;
  WppLoadTracingSupport();
  _DAT_1c0025b00 = 0;
  WppInitKm(param_1,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  local_148 = PTR__WDF_SERCX_DRIVER_CONTEXT_TYPE_INFO_1c0023cb8;
  local_168 = 0;
  local_130 = SerCx_EvtDriverUnload;
  uStack_170 = 0;
  local_178 = 0x38;
  local_158 = 0;
  uStack_150 = 0;
  uStack_160 = 0x100000001;
  local_140 = 0x20;
  local_128 = 1;
  local_138 = 0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_178);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000dee5;
    uVar7 = 0xb;
LAB_1c000dbf9:
    bVar2 = false;
  }
  else {
    p_Var4 = (_SERCX_DRIVER_CONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_180,PTR__WDF_SERCX_DRIVER_CONTEXT_TYPE_INFO_1c0023cb8
                       );
    puVar5 = &local_178;
    g_SerCx2DriverContext = p_Var4;
    *(undefined4 *)p_Var4 = 0x72446353;
    p_Var1 = p_Var4 + 0x10;
    *(_SERCX_DRIVER_CONTEXT **)(p_Var4 + 0x18) = p_Var1;
    *(_SERCX_DRIVER_CONTEXT **)p_Var1 = p_Var1;
    local_148 = (undefined *)0x0;
    local_168 = 0;
    uStack_160 = 0x100000001;
    uStack_170 = 0;
    local_178 = 0x38;
    local_158 = 0;
    uStack_150 = 0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,puVar5,p_Var4 + 8);
    p_Var1 = g_SerCx2DriverContext;
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000dee5;
      uVar7 = 0xc;
      goto LAB_1c000dbf9;
    }
    *(undefined4 *)(g_SerCx2DriverContext + 0x20) = 0;
    p_Var1[0x28] = (_SERCX_DRIVER_CONTEXT)0x0;
    McGenEventRegister_EtwRegister
              (&SerCx2EtwProvider,puVar5,&SerCx2EtwProvider_Context,
               (longlong *)&SerCx2EtwProvider_Context);
    McGenEventRegister_EtwRegister
              (&SLEEPSTUDY_ETW_PROVIDER,puVar5,&SLEEPSTUDY_ETW_PROVIDER_Context,
               (longlong *)&SLEEPSTUDY_ETW_PROVIDER_Context);
    bVar2 = true;
    local_198 = (**(code **)(WdfFunctions_01015 + 200))
                          (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
    if (local_198 != 0) {
      uVar6 = 0;
      do {
        uVar8 = (ulonglong)uVar6;
        uVar6 = uVar6 + 1;
        iVar3 = RtlUnicodeStringPrintf
                          ((_UNICODE_STRING *)&local_190,(ushort *)L"%s%d",L"\\Device\\SerCx2Dev",
                           uVar8);
        if ((iVar3 < 0) ||
           (iVar3 = (**(code **)(WdfFunctions_01015 + 0x218))(WdfDriverGlobals,local_198,&local_190)
           , iVar3 < 0)) goto LAB_1c000deb3;
        iVar3 = (**(code **)(WdfFunctions_01015 + 600))
                          (WdfDriverGlobals,&local_198,0,&g_ClassLibraryDevice);
      } while (iVar3 == -0x3fffffcb);
      if (iVar3 < 0) {
LAB_1c000deb3:
        (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals,local_198);
        local_198 = 0;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(0,4,2,0xe,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
        }
        (**(code **)(WdfFunctions_01015 + 0xd8))(WdfDriverGlobals,g_ClassLibraryDevice);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(0,4,2,0xf,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
        }
        iVar3 = WdfRegisterClassLibrary(&g_WdfClassLibraryInfo,param_2,&local_190);
        if (iVar3 < 0) {
          (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,g_ClassLibraryDevice);
          g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
        }
      }
      goto LAB_1c000dee5;
    }
    iVar3 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000dee5;
    uVar7 = 0xd;
    iVar3 = -0x3fffff66;
  }
  WPP_RECORDER_SF_d(0,2,2,uVar7,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,(char)iVar3);
LAB_1c000dee5:
  *(undefined2 *)(local_188 + 0xc6) = 0;
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(0,2,2,0x10,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,(char)iVar3);
    }
    if (bVar2) {
      if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 2) != 0) {
        McTemplateK0zd_EtwWriteTransfer();
      }
      McGenEventUnregister_EtwUnregister((longlong *)&SLEEPSTUDY_ETW_PROVIDER_Context);
      McGenEventUnregister_EtwUnregister((longlong *)&SerCx2EtwProvider_Context);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x11,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
    WppCleanupKm(param_1);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Z();
    }
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 1) != 0) {
      McTemplateK0z_EtwWriteTransfer();
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x13,
                       &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
    }
  }
  return iVar3;
}



===== McGenEventRegister_EtwRegister @ 1c000e01c =====

void McGenEventRegister_EtwRegister
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  if (*param_4 == 0) {
    EtwRegister(param_1,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c000e048 =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c000e07c =====

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



===== McTemplateK0_EtwWriteTransfer @ 1c000e0dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(void)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventDriverUnload,0,1,local_28);
  return;
}



===== McTemplateK0z_EtwWriteTransfer @ 1c000e130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0z_EtwWriteTransfer(void)

{
  longlong lVar1;
  wchar_t *in_R9;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (in_R9 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  local_28 = in_R9;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventDriverLoad,0,2,local_38);
  return;
}



===== McTemplateK0zd_EtwWriteTransfer @ 1c000e1c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zd_EtwWriteTransfer(void)

{
  longlong lVar1;
  wchar_t *in_R9;
  undefined1 uStack0000000000000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (in_R9 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_R9[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  local_20 = 4;
  local_28 = &uStack0000000000000028;
  local_38 = in_R9;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventDriverLoadError,0,3,local_48);
  return;
}



===== SerCx_EvtDriverUnload @ 1c000e270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SerCx_EvtDriverUnload(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x14,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  if (g_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))();
    g_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(0,4,2,0x15,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 1) != 0) {
    McTemplateK0_EtwWriteTransfer();
  }
  McGenEventUnregister_EtwUnregister((longlong *)&SLEEPSTUDY_ETW_PROVIDER_Context);
  McGenEventUnregister_EtwUnregister((longlong *)&SerCx2EtwProvider_Context);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x16,
                     &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar1);
  return;
}



===== WPP_RECORDER_SF_LLd @ 1c000e3ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLd(void)

{
  undefined1 uStack0000000000000038;
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 0xc000000d;
  local_10[0] = 0x23;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,0x1e,local_10,4,
               &uStack0000000000000038,4,local_18,4,0);
  }
  WppAutoLogTrace(0,2,1,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,0x1e,local_10,4,
                  &uStack0000000000000038,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_Z @ 1c000e498 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Z(void)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  wchar_t *in_stack_00000030;
  
  pwVar3 = L"NULL";
  wVar4 = L'\b';
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_1c000e545;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c000e500:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000030;
    if (*in_stack_00000030 == L'\0') goto LAB_1c000e500;
    pwVar5 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  pwVar2 = in_stack_00000030;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,0x12,pwVar2,2,pwVar5,wVar1,0);
LAB_1c000e545:
  if ((in_stack_00000030 != (wchar_t *)0x0) &&
     (wVar4 = *in_stack_00000030, *in_stack_00000030 != L'\0')) {
    pwVar3 = *(wchar_t **)(in_stack_00000030 + 4);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"\b";
  }
  WppAutoLogTrace(0,4,2,&WPP_2335db47bf2439c92089c1e2bb8fbb5c_Traceguids,0x12,in_stack_00000030,2,
                  pwVar3,wVar4,0);
  return;
}



===== WppClassicProviderCallback @ 1c000e5c0 =====

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



===== TransferStateEntryFunc_CancelSystemDmaFifoDrain2 @ 1c000e620 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaFifoDrain2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaFifoDrain2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_CancelSystemDmaFifoDrain(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_CancelSystemDmaNewDataNotification2 @ 1c000e640 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaNewDataNotification2(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CancelSystemDmaNewDataNotification2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_CancelSystemDmaNewDataNotification(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_CleanupSystemDmaTransaction4 @ 1c000e660 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupSystemDmaTransaction4(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_CleanupSystemDmaTransaction4(void *param_1)

{
  Transfer_CleanupSystemDmaTransaction(param_1);
  return 0;
}



===== TransferStateEntryFunc_DidNewBytesArriveDuringSystemDma2 @ 1c000e680 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_DidNewBytesArriveDuringSystemDma2(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_DidNewBytesArriveDuringSystemDma2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_DidNewBytesArriveDuringSystemDma(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_EnableCustomReceiveTransactionNewDataNotification @ 1c000e6a0 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_EnableCustomReceiveTransactionNewDataNotification(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_EnableCustomReceiveTransactionNewDataNotification(void *param_1)

{
  Transfer_EnableCustomReceiveTransactionNewDataNotification(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_EnableSystemDmaNewDataNotification @ 1c000e6c0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_EnableSystemDmaNewDataNotification(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_EnableSystemDmaNewDataNotification(void *param_1)

{
  Transfer_EnableSystemDmaNewDataNotification(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_ErrorState @ 1c000e6e0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ErrorState(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ErrorState(void *param_1)

{
  Transfer_ErrorState(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_HaveAllBytesForCurrentTransactionTransferred @ 1c000e700 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_HaveAllBytesForCurrentTransactionTransferred(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_HaveAllBytesForCurrentTransactionTransferred(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_HaveAllBytesForCurrentTransactionTransferred(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma @ 1c000e720 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_InitializeCustomTransaction @ 1c000e740 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializeCustomTransaction(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InitializeCustomTransaction(void *param_1)

{
  Transfer_InitializeCustomTransaction(param_1);
  return 0;
}



===== TransferStateEntryFunc_InternalInitializeSystemDmaTransaction @ 1c000e760 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_InternalInitializeSystemDmaTransaction(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_InternalInitializeSystemDmaTransaction(void *param_1)

{
  Transfer_InternalInitializeSystemDmaTransaction(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_IsSystemDmaNewDataNotificationSupported @ 1c000e780 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_IsSystemDmaNewDataNotificationSupported(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_IsSystemDmaNewDataNotificationSupported(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_IsSystemDmaNewDataNotificationSupported(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_PioPurgeFifo @ 1c000e7a0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_PioPurgeFifo(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_PioPurgeFifo(void *param_1)

{
  Transfer_PioPurgeFifo(param_1);
  return 0;
}



===== TransferStateEntryFunc_ProcessSystemDmaConfigureChannelFailure2 @ 1c000e7c0 =====

/* enum _SM_ENGINE_EVENT __cdecl
   TransferStateEntryFunc_ProcessSystemDmaConfigureChannelFailure2(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_ProcessSystemDmaConfigureChannelFailure2(void *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  _Var1 = Transfer_ProcessSystemDmaConfigureChannelFailure(param_1);
  return _Var1;
}



===== TransferStateEntryFunc_RecordSystemDmaNewDataNotificationFired @ 1c000e7e0 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_RecordSystemDmaNewDataNotificationFired(void
   * __ptr64) */

_SM_ENGINE_EVENT __cdecl
TransferStateEntryFunc_RecordSystemDmaNewDataNotificationFired(void *param_1)

{
  Transfer_RecordSystemDmaNewDataNotificationFired(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_ReduceRequestLengthTo1Byte @ 1c000e800 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ReduceRequestLengthTo1Byte(void * __ptr64)
    */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_ReduceRequestLengthTo1Byte(void *param_1)

{
  *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x30) + 0x1c) = 1;
  return 0xebe78092;
}



===== TransferStateEntryFunc_SetStatusForUnsupportedRequest @ 1c000e820 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SetStatusForUnsupportedRequest(void *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SetStatusForUnsupportedRequest(void *param_1)

{
  Transfer_SetStatusForUnsupportedRequest(param_1);
  return 0xebe78092;
}



===== TransferStateEntryFunc_SwitchToPassive @ 1c000e840 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SwitchToPassive(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SwitchToPassive(void *param_1)

{
  return 0xebe78092;
}



===== TransferStateEntryFunc_SystemDmaDrainFifo @ 1c000e850 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SystemDmaDrainFifo(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SystemDmaDrainFifo(void *param_1)

{
  Transfer_SystemDmaDrainFifo(param_1);
  return 0;
}



===== TransferStateEntryFunc_SystemDmaPurgeFifo4 @ 1c000e870 =====

/* enum _SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SystemDmaPurgeFifo4(void * __ptr64) */

_SM_ENGINE_EVENT __cdecl TransferStateEntryFunc_SystemDmaPurgeFifo4(void *param_1)

{
  Transfer_SystemDmaPurgeFifo(param_1);
  return 0;
}



===== Transfer_CancelSystemDmaFifoDrain @ 1c000e888 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_CancelSystemDmaFifoDrain(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_CancelSystemDmaFifoDrain(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x70,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = Transmit_CancelSystemDmaFifoDrain((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x71,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Transfer_CancelSystemDmaNewDataNotification @ 1c000e930 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_CancelSystemDmaNewDataNotification(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_CancelSystemDmaNewDataNotification(_TRANSFER_SM_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  uVar1 = Receive_CancelSystemDmaNewDataNotification((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(uVar1 != '\0') & 0x10) + 0xebe78082;
}



===== Transfer_CleanupSystemDmaTransaction @ 1c000e9e0 =====

/* void __cdecl Transfer_CleanupSystemDmaTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_CleanupSystemDmaTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x50,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_CleanupSystemDmaTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_CleanupSystemDmaTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x51,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_DidNewBytesArriveDuringSystemDma @ 1c000ea90 =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_DidNewBytesArriveDuringSystemDma(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Transfer_DidNewBytesArriveDuringSystemDma(_TRANSFER_SM_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x40,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  uVar1 = Receive_DidNewBytesArriveDuringSystemDma((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x41,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(uVar1 != '\0') & 0x50) + 0xebe78122;
}



===== Transfer_EnableCustomReceiveTransactionNewDataNotification @ 1c000eb40 =====

/* void __cdecl Transfer_EnableCustomReceiveTransactionNewDataNotification(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl
Transfer_EnableCustomReceiveTransactionNewDataNotification(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x84,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Receive_CustomTransactionEnableNewDataNotification((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x85,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_EnableSystemDmaNewDataNotification @ 1c000ebe4 =====

/* void __cdecl Transfer_EnableSystemDmaNewDataNotification(struct _TRANSFER_SM_CONTEXT * __ptr64)
    */

void __cdecl Transfer_EnableSystemDmaNewDataNotification(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x56,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Receive_EnableSystemDmaNewDataNotification((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x57,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_ErrorState @ 1c000ec88 =====

/* void __cdecl Transfer_ErrorState(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_ErrorState(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x8a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Verifier_DbgBreak("Unexpected State Reached",2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x8b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_HaveAllBytesForCurrentTransactionTransferred @ 1c000ed2c =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_HaveAllBytesForCurrentTransactionTransferred(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_HaveAllBytesForCurrentTransactionTransferred(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x44,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  _Var1 = 0xebe78172;
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x20) !=
      *(int *)(*(longlong *)(param_1 + 0x30) + 0x24)) {
    _Var1 = 0xebe78122;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x45,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Transfer_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma @ 1c000eddc =====

/* enum _SM_ENGINE_EVENT __cdecl
   Transfer_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(_TRANSFER_SM_CONTEXT *param_1)

{
  uchar uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x42,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  uVar1 = Receive_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma
                    ((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x43,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(uVar1 != '\0') & 0x50) + 0xebe78122;
}



===== Transfer_InitializeCustomTransaction @ 1c000ee8c =====

/* void __cdecl Transfer_InitializeCustomTransaction(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_InitializeCustomTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x74,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_InitializeCustomTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_InitializeCustomTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x75,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_InternalInitializeSystemDmaTransaction @ 1c000ef3c =====

/* void __cdecl Transfer_InternalInitializeSystemDmaTransaction(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

void __cdecl Transfer_InternalInitializeSystemDmaTransaction(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x46,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    Transmit_InternalInitializeSystemDmaTransaction((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  }
  else {
    Receive_InternalInitializeSystemDmaTransaction((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x47,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_IsSystemDmaNewDataNotificationSupported @ 1c000efec =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_IsSystemDmaNewDataNotificationSupported(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_IsSystemDmaNewDataNotificationSupported(_TRANSFER_SM_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3c,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + -0x18) + 0x78);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x3d,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return (-(uint)(lVar1 != 0) & 0x50) + 0xebe78122;
}



===== Transfer_ProcessSystemDmaConfigureChannelFailure @ 1c000f09c =====

/* enum _SM_ENGINE_EVENT __cdecl Transfer_ProcessSystemDmaConfigureChannelFailure(struct
   _TRANSFER_SM_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transfer_ProcessSystemDmaConfigureChannelFailure(_TRANSFER_SM_CONTEXT *param_1)

{
  _SM_ENGINE_EVENT _Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x60,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  if (param_1[0x10] == (_TRANSFER_SM_CONTEXT)0x74) {
    _Var1 = Transmit_ProcessSystemDmaConfigureChannelFailure((_TRANSMIT_CONTEXT *)(param_1 + -0x38))
    ;
  }
  else {
    _Var1 = Receive_ProcessSystemDmaConfigureChannelFailure((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x61,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return _Var1;
}



===== Transfer_RecordSystemDmaNewDataNotificationFired @ 1c000f150 =====

/* void __cdecl Transfer_RecordSystemDmaNewDataNotificationFired(struct _TRANSFER_SM_CONTEXT *
   __ptr64) */

void __cdecl Transfer_RecordSystemDmaNewDataNotificationFired(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5a,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Receive_RecordSystemDmaNewDataNotificationFired((_RECEIVE_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x5b,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_SMContextInit @ 1c000f1f4 =====

/* long __cdecl Transfer_SMContextInit(struct _TRANSFER_SM_CONTEXT * __ptr64,enum _REQUEST_TYPE,void
   * __ptr64,struct RECORDER_LOG__ * __ptr64) */

long __cdecl
Transfer_SMContextInit
          (_TRANSFER_SM_CONTEXT *param_1,_REQUEST_TYPE param_2,void *param_3,RECORDER_LOG__ *param_4
          )

{
  long lVar1;
  _TRANSFER_SM_CONTEXT _Var2;
  undefined4 in_register_00000014;
  _func_void_void_ptr__SERCX_TIMER_PRIVCONTEXT_ptr__TIMEOUT_TYPE *p_Var3;
  _SERCX_TIMER_PRIVCONTEXT *local_res8;
  undefined *in_stack_ffffffffffffffb8;
  _SM_ENGINE_STATE_TABLE_ENTRY **pp_Var4;
  _SERCX_TIMER_PRIVCONTEXT **pp_Var5;
  _func_void_void_ptr_void_ptr__SM_ENGINE_STATE__SM_ENGINE_EVENT__SM_ENGINE_STATE
  *in_stack_ffffffffffffffc8;
  
  p_Var3 = (_func_void_void_ptr__SERCX_TIMER_PRIVCONTEXT_ptr__TIMEOUT_TYPE *)
           CONCAT44(in_register_00000014,param_2);
  local_res8 = (_SERCX_TIMER_PRIVCONTEXT *)0x0;
  _Var2 = SUB41(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids;
    p_Var3 = (_func_void_void_ptr__SERCX_TIMER_PRIVCONTEXT_ptr__TIMEOUT_TYPE *)
             CONCAT71((int7)((ulonglong)p_Var3 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x34,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  *(undefined4 *)param_1 = 0x78546d53;
  pp_Var5 = &local_res8;
  param_1[0x10] = _Var2;
  *(RECORDER_LOG__ **)(param_1 + 0x3d8) = param_4;
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + -0x28);
  pp_Var4 = (_SM_ENGINE_STATE_TABLE_ENTRY **)
            CONCAT71((int7)((ulonglong)in_stack_ffffffffffffffb8 >> 8),
                     _Var2 == (_TRANSFER_SM_CONTEXT)0x72);
  lVar1 = Timer_Create(param_3,p_Var3,param_1,param_4,_Var2 == (_TRANSFER_SM_CONTEXT)0x72,pp_Var5);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x3d8),2,6,0x35,
                      &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,(char)lVar1);
  }
  else {
    *(_SERCX_TIMER_PRIVCONTEXT **)(param_1 + 0x38) = local_res8;
    lVar1 = StateMachineEngine_Init
                      ((_SM_ENGINE_CONTEXT *)(param_1 + 0x40),param_3,param_1,(ulong)param_4,pp_Var4
                       ,(_func_void_void_ptr_void_ptr__SM_ENGINE_EVENT *)pp_Var5,
                       in_stack_ffffffffffffffc8);
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar1;
      }
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x3d8),2,6,0x36,
                       &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x37,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return lVar1;
}



===== Transfer_SetStatusForUnsupportedRequest @ 1c000f364 =====

/* void __cdecl Transfer_SetStatusForUnsupportedRequest(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_SetStatusForUnsupportedRequest(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x20,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 4) = 0xc00000bb;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x21,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_SystemDmaDrainFifo @ 1c000f408 =====

/* void __cdecl Transfer_SystemDmaDrainFifo(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_SystemDmaDrainFifo(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6e,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Transmit_SystemDmaDrainFifo((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x6f,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== Transfer_SystemDmaPurgeFifo @ 1c000f4ac =====

/* void __cdecl Transfer_SystemDmaPurgeFifo(struct _TRANSFER_SM_CONTEXT * __ptr64) */

void __cdecl Transfer_SystemDmaPurgeFifo(_TRANSFER_SM_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x72,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  Transmit_SystemDmaPurgeFifo((_TRANSMIT_CONTEXT *)(param_1 + -0x38));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x73,
                     &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids);
  }
  return;
}



===== McTemplateK0pd_EtwWriteTransfer @ 1c000f550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0pddd_EtwWriteTransfer @ 1c000f5c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pddd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = &local_res20;
  local_50 = 8;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = &param_7;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0pxqdbr2_EtwWriteTransfer @ 1c000f660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pxqdbr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined1 param_7,undefined8 param_8)

{
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 8;
  local_68 = &local_res20;
  local_1c = 0;
  local_58 = &param_5;
  local_50 = 8;
  local_48 = &param_6;
  local_40 = 4;
  local_38 = &param_7;
  local_28 = param_8;
  local_20 = param_6;
  local_30 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,6,local_78);
  return;
}



===== WPP_RECORDER_SF_qcq @ 1c000f70c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qcq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,0x27,&uStack0000000000000030,8,
               &uStack0000000000000038,1,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,5,6,&WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,0x27,
                  &uStack0000000000000030,8,&uStack0000000000000038,1,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qcqddd @ 1c000f800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qcqddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,1,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,5,6,&WPP_8b0ca2a383a43c8326b027fa7f2ea4d3_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,1,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== RtlStringCbVPrintfExW @ 1c000f960 =====

/* long __cdecl RtlStringCbVPrintfExW(unsigned short * __ptr64,unsigned __int64,unsigned short *
   __ptr64 * __ptr64,unsigned __int64 * __ptr64,unsigned long,unsigned short const * __ptr64,char *
   __ptr64) */

long __cdecl
RtlStringCbVPrintfExW
          (ushort *param_1,__uint64 param_2,ushort **param_3,__uint64 *param_4,ulong param_5,
          ushort *param_6,char *param_7)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _Count;
  int iVar3;
  
  if (0x7ffffffe < (param_2 >> 1) - 1) {
    return -0x3ffffff3;
  }
  _Count = (param_2 >> 1) - 1;
  iVar3 = 0;
  iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_6,param_7);
  if (iVar1 < 0) {
LAB_1c000f9ce:
    iVar3 = -0x7ffffffb;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_Count < uVar2) goto LAB_1c000f9ce;
    if (uVar2 != _Count) {
      _Count = uVar2;
      goto LAB_1c000f9d5;
    }
  }
  param_1[_Count] = 0;
LAB_1c000f9d5:
  if (((-1 < iVar3) || (iVar3 == -0x7ffffffb)) && (param_3 != (ushort **)0x0)) {
    *param_3 = param_1 + _Count;
  }
  return iVar3;
}



===== RtlStringCchPrintfA @ 1c000fa10 =====

/* long __cdecl RtlStringCchPrintfA(char * __ptr64,unsigned __int64,char const * __ptr64,...) */

long __cdecl RtlStringCchPrintfA(char *param_1,__uint64 param_2,char *param_3,...)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return lVar2;
}



===== SerCx_ApplySecurityDescriptor @ 1c000fa84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_ApplySecurityDescriptor(struct WDFDEVICE__ * __ptr64) */

long __cdecl SerCx_ApplySecurityDescriptor(WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_res10 [8];
  longlong local_res18;
  
  local_res18 = 0;
  local_res10[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x22,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,param_1);
  iVar1 = ObGetObjectSecurity(uVar2,&local_res18,local_res10);
  if (-1 < iVar1) {
    if (local_res18 != 0) {
      iVar1 = ObSetSecurityObjectByPointer(uVar2,0x1f,local_res18);
    }
    ObReleaseObjectSecurity(local_res18,local_res10[0]);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x23,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return iVar1;
}



===== SerCx_CloseFunctionConfigConnections @ 1c000fba4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl SerCx_CloseFunctionConfigConnections(struct WDFDEVICE__ * __ptr64) */

void __cdecl SerCx_CloseFunctionConfigConnections(WDFDEVICE__ *param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  uVar3 = 0;
  if (*(int *)(lVar1 + 0x1a0) != 0) {
    do {
      if (*(longlong *)(*(longlong *)(lVar1 + 0x198) + uVar3 * 8) != 0) {
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
        *(undefined8 *)(*(longlong *)(lVar1 + 0x198) + uVar3 * 8) = 0;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(lVar1 + 0x1a0));
  }
  return;
}



===== SerCx_CreateDeviceInterface @ 1c000fc3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_CreateDeviceInterface(struct WDFDEVICE__ * __ptr64,struct _SERCX_CONTEXT *
   __ptr64) */

long __cdecl SerCx_CreateDeviceInterface(WDFDEVICE__ *param_1,_SERCX_CONTEXT *param_2)

{
  int iVar1;
  undefined1 local_res8 [8];
  longlong local_res18 [2];
  undefined4 uVar3;
  longlong lVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  WDFDEVICE__ *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res18[0] = 0;
  local_res8[0] = 0;
  local_48 = 0;
  local_28 = 0;
  uStack_50 = 0;
  local_58 = 0x38;
  uStack_30 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uStack_40 = 0x100000001;
  local_38 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,&local_58,local_res18);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_78,&u_SERCX);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_COMPORT,&local_78);
    if (-1 < iVar1) {
      lVar2 = local_res18[0];
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                        (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_COMPORT,&local_78,
                         local_res18[0]);
      uVar3 = (undefined4)((ulonglong)lVar2 >> 0x20);
      if (-1 < iVar1) {
        (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res18[0],&local_68);
        iVar1 = IoSetDeviceInterfacePropertyData
                          (&local_68,&DEVPKEY_DeviceInterface_Serial_PortName,0,0,
                           CONCAT44(uVar3,0x12),*(ushort *)(param_2 + 0x1a8) + 2,
                           *(undefined8 *)(param_2 + 0x1b0));
        if (-1 < iVar1) {
          iVar1 = IoSetDeviceInterfacePropertyData
                            (&local_68,&DEVPKEY_DeviceInterface_Restricted,0,0,0x11,1,local_res8);
        }
      }
    }
  }
  if (local_res18[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== SerCx_CreateRecorderLog @ 1c000fe28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SerCx_CreateRecorderLog(unsigned long,unsigned long,unsigned long,char *
   __ptr64,struct RECORDER_LOG__ * __ptr64 * __ptr64) */

long __cdecl
SerCx_CreateRecorderLog
          (ulong param_1,ulong param_2,ulong param_3,char *param_4,RECORDER_LOG__ **param_5)

{
  long lVar1;
  undefined1 auStack_78 [32];
  char *local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  char local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_48 = 0x38;
  local_28[0x10] = '\x02';
  local_28[0x11] = '\0';
  local_28[0x12] = '\0';
  local_28[0x13] = '\0';
  local_28[0x14] = '\x02';
  local_28[0x15] = '\0';
  local_28[0x16] = '\0';
  local_28[0x17] = '\0';
  uStack_30 = 0x1000000000;
  uStack_40 = 0x19000001000;
  local_58 = param_4;
  RtlStringCchPrintfA(local_28,0x10,"%02d %s",(ulonglong)param_1);
  lVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_48,param_5);
  return lVar1;
}



===== SerCx_CreateResourceHubTarget @ 1c000fee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_CreateResourceHubTarget(struct WDFDEVICE__ * __ptr64,struct _SERCX_CONTEXT *
   __ptr64) */

long __cdecl SerCx_CreateResourceHubTarget(WDFDEVICE__ *param_1,_SERCX_CONTEXT *param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_90;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 local_5c;
  undefined4 local_58;
  
  memset(&local_a8,0,0x88);
  local_f8 = 0;
  uStack_f0 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x24,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  local_b8 = 0;
  local_d8 = 0;
  uStack_d0 = 0x100000001;
  uStack_e0 = 0;
  local_e8 = 0x38;
  local_c8 = 0;
  uStack_c0 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))
                    (WdfDriverGlobals,param_1,&local_e8,param_2 + 0xb0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x25;
  }
  else {
    RtlInitUnicodeString(&local_f8,L"\\Device\\RESOURCE_HUB");
    local_90 = SerCx_EvtSerCxIoTargetRemoveComplete;
    local_a8 = 0x88;
    local_a4 = 2;
    local_78 = (undefined4)local_f8;
    uStack_74 = local_f8._4_4_;
    uStack_70 = (undefined4)uStack_f0;
    uStack_6c = uStack_f0._4_4_;
    local_68 = 0x1f0000;
    local_58 = 0x40;
    local_5c = 1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0xb0),&local_a8);
    if (-1 < iVar1) goto LAB_1c0010085;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar2 = 0x26;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(param_2 + 0x130),2,10,uVar2,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)param_1,(char)iVar1);
LAB_1c0010085:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x27,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return iVar1;
}



===== SerCx_EvtDestroy @ 1c00100e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl SerCx_EvtDestroy(void * __ptr64) */

void __cdecl SerCx_EvtDestroy(void *param_1)

{
  longlong *plVar1;
  _SERCX_DRIVER_CONTEXT *p_Var2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  _SERCX_DRIVER_CONTEXT *p_Var6;
  int iVar7;
  longlong lVar8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xf,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(longlong *)(lVar8 + 0x158) != 0) {
    iVar7 = PoUnregisterPowerSettingCallback();
    if ((iVar7 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar8 + 0x130),2,3,0x10,
                        &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar7);
    }
    *(undefined8 *)(lVar8 + 0x158) = 0;
  }
  if (*(longlong *)(lVar8 + 0x150) != 0) {
    ExUnsubscribeWnfStateChange();
    *(undefined8 *)(lVar8 + 0x150) = 0;
  }
  if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 1) != 0) {
    McTemplateK0p_EtwWriteTransfer();
  }
  plVar1 = (longlong *)(lVar8 + 0x18);
  if ((*plVar1 != 0) || (*(longlong *)(lVar8 + 0x20) != 0)) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))
              (WdfDriverGlobals,*(undefined8 *)(g_SerCx2DriverContext + 8));
    p_Var6 = g_SerCx2DriverContext;
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(lVar8 + 0x20), (longlong *)*plVar4 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    *(undefined8 *)(lVar8 + 0x20) = 0;
    *plVar1 = 0;
    p_Var2 = p_Var6 + 0x20;
    *(int *)p_Var2 = *(int *)p_Var2 + -1;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(p_Var6 + 8));
  }
  if (*(longlong *)(lVar8 + 0x1b0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar8 + 0x1b0),0x32584353);
    *(undefined8 *)(lVar8 + 0x1a8) = 0;
    *(undefined8 *)(lVar8 + 0x1b0) = 0;
  }
  if (*(longlong *)(lVar8 + 0x130) != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    *(undefined8 *)(lVar8 + 0x130) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x11,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return;
}



===== SerCx_EvtSerCxIoTargetRemoveComplete @ 1c0010310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl SerCx_EvtSerCxIoTargetRemoveComplete(struct WDFIOTARGET__ * __ptr64) */

void __cdecl SerCx_EvtSerCxIoTargetRemoveComplete(WDFIOTARGET__ *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x35,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x550))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x36,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return;
}



===== SerCx_OpenFunctionConfigConnections @ 1c00103e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SerCx_OpenFunctionConfigConnections(struct WDFDEVICE__ * __ptr64) */

long __cdecl SerCx_OpenFunctionConfigConnections(WDFDEVICE__ *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined1 auStackY_208 [32];
  undefined8 local_1b8;
  undefined4 local_1b0;
  undefined4 uStack_1ac;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 local_14c;
  undefined4 local_148;
  __uint64 local_108 [6];
  undefined1 local_d8 [160];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_208;
  local_1b8 = 0;
  iVar1 = 0;
  memset(&local_198,0,0x88);
  uStack_1a0 = local_d8;
  local_1a8 = 0x980000;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4b,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  for (uVar7 = 0; uVar4 = 0, uVar7 < *(uint *)(lVar2 + 0x1a0); uVar7 = uVar7 + 1) {
    uVar5 = (ulonglong)uVar7;
    local_1b0 = *(undefined4 *)(*(longlong *)(lVar2 + 400) + uVar5 * 8);
    uStack_1ac = *(undefined4 *)(*(longlong *)(lVar2 + 400) + 4 + uVar5 * 8);
    iVar1 = RESOURCE_HUB_STRING_PRINTF
                      ((ushort *)local_108,0x22,(ushort *)L"%0*I64x",(__uint64 *)0x10);
    if (-1 < iVar1) {
      iVar1 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                        ((short *)&local_1a8,(ushort *)L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_108
                        );
    }
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0010741;
      uVar6 = 0x4c;
      goto LAB_1c001069a;
    }
    local_1b8 = 0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,param_1,0,&local_1b8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0010741;
      uVar6 = 0x4d;
      goto LAB_1c001069a;
    }
    *(undefined8 *)(*(longlong *)(lVar2 + 0x198) + uVar5 * 8) = local_1b8;
    memset(&local_198,0,0x88);
    local_198 = 0x88;
    local_194 = 2;
    local_168 = (undefined4)local_1a8;
    uStack_164 = local_1a8._4_4_;
    uStack_160 = (undefined4)uStack_1a0;
    uStack_15c = uStack_1a0._4_4_;
    local_158 = 0x12019f;
    local_148 = 0x40;
    local_14c = 1;
    uVar3 = PsGetHostSilo();
    uVar3 = PsAttachSiloToCurrentThread(uVar3);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,local_1b8);
    PsDetachSiloFromCurrentThread(uVar3);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x130),2,10,0x4e,
                          &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar1);
      }
      goto LAB_1c0010741;
    }
  }
  do {
    if (*(uint *)(lVar2 + 0x1a0) <= uVar4) {
      if (iVar1 < 0) {
LAB_1c0010741:
        uVar5 = 0;
        if (*(int *)(lVar2 + 0x1a0) != 0) {
          do {
            if (*(longlong *)(*(longlong *)(lVar2 + 0x198) + uVar5 * 8) != 0) {
              (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
              *(undefined8 *)(*(longlong *)(lVar2 + 0x198) + uVar5 * 8) = 0;
            }
            uVar7 = (int)uVar5 + 1;
            uVar5 = (ulonglong)uVar7;
          } while (uVar7 < *(uint *)(lVar2 + 0x1a0));
        }
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x50,
                         &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
      }
      return iVar1;
    }
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,
                       *(undefined8 *)(*(longlong *)(lVar2 + 0x198) + (ulonglong)uVar4 * 8),0,
                       0x480010);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x4f;
LAB_1c001069a:
        WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x130),2,10,uVar6,
                          &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar1);
      }
      goto LAB_1c0010741;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}



===== SerCx_ParseFunctionConfigResources @ 1c00107f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_ParseFunctionConfigResources(struct WDFDEVICE__ * __ptr64,struct
   _CM_RESOURCE_LIST * __ptr64) */

long __cdecl SerCx_ParseFunctionConfigResources(WDFDEVICE__ *param_1,_CM_RESOURCE_LIST *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  long lVar5;
  ushort uVar6;
  _CM_RESOURCE_LIST *p_Var7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  lVar5 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x47,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_2 != (_CM_RESOURCE_LIST *)0x0) {
    *(undefined4 *)(lVar2 + 0x1a0) = 0;
    if (*(longlong *)(lVar2 + 400) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar2 + 400),0x32786353);
      *(undefined8 *)(lVar2 + 400) = 0;
    }
    if (*(longlong *)(lVar2 + 0x198) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar2 + 0x198),0x32786353);
      *(undefined8 *)(lVar2 + 0x198) = 0;
    }
    for (uVar6 = 0; uVar6 < 2; uVar6 = uVar6 + 1) {
      p_Var7 = param_2 + 4;
      if (uVar6 == 1) {
        lVar3 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(lVar2 + 0x1a0) << 3,0x32786353);
        *(longlong *)(lVar2 + 400) = lVar3;
        if (lVar3 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar8 = 0x48;
LAB_1c0010a40:
            WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x130),2,10,uVar8,
                              &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,0x9a);
          }
        }
        else {
          lVar3 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(lVar2 + 0x1a0) << 3,0x32786353);
          *(longlong *)(lVar2 + 0x198) = lVar3;
          if (lVar3 != 0) goto LAB_1c0010957;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar8 = 0x49;
            goto LAB_1c0010a40;
          }
        }
        lVar5 = -0x3fffff66;
        if (*(longlong *)(lVar2 + 400) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 400),0x32786353);
          *(undefined8 *)(lVar2 + 400) = 0;
        }
        if (*(longlong *)(lVar2 + 0x198) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar2 + 0x198),0x32786353);
          *(undefined8 *)(lVar2 + 0x198) = 0;
        }
        break;
      }
LAB_1c0010957:
      uVar9 = 0;
      uVar11 = 0;
      if (*(int *)param_2 == 0) break;
      do {
        uVar10 = 0;
        uVar1 = 0;
        if (*(int *)(p_Var7 + 0xc) != 0) {
          do {
            uVar4 = (ulonglong)uVar10;
            if (((p_Var7[uVar4 * 0x14 + 0x10] == (_CM_RESOURCE_LIST)0x84) &&
                (p_Var7[uVar4 * 0x14 + 0x14] == (_CM_RESOURCE_LIST)0x3)) &&
               (p_Var7[uVar4 * 0x14 + 0x15] == (_CM_RESOURCE_LIST)0x1)) {
              if (uVar6 == 1) {
                *(undefined4 *)(*(longlong *)(lVar2 + 400) + (ulonglong)uVar9 * 8) =
                     *(undefined4 *)(p_Var7 + uVar4 * 0x14 + 0x18);
                *(undefined4 *)(*(longlong *)(lVar2 + 400) + 4 + (ulonglong)uVar9 * 8) =
                     *(undefined4 *)(p_Var7 + uVar4 * 0x14 + 0x1c);
              }
              uVar9 = uVar9 + 1;
            }
            uVar1 = *(uint *)(p_Var7 + 0xc);
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar1);
        }
        uVar11 = uVar11 + 1;
        p_Var7 = p_Var7 + (ulonglong)uVar1 * 0x14 + 0x10;
      } while (uVar11 < *(uint *)param_2);
      if (uVar9 == 0) break;
      if (uVar6 == 0) {
        *(uint *)(lVar2 + 0x1a0) = uVar9;
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4a,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar5;
}



===== SerCx_PnpIrpPreprocess @ 1c0010b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_PnpIrpPreprocess(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl SerCx_PnpIrpPreprocess(WDFDEVICE__ *param_1,_IRP *param_2,void *param_3)

{
  long lVar1;
  
  if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\0') {
    lVar1 = SerCx_ParseFunctionConfigResources
                      (param_1,*(_CM_RESOURCE_LIST **)(*(longlong *)(param_2 + 0xb8) + 0x10));
    if (lVar1 < 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(long *)(param_2 + 0x30) = lVar1;
      IofCompleteRequest(param_2,0);
      return lVar1;
    }
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0xc88))(WdfDriverGlobals,param_1,param_2,param_3);
  return lVar1;
}



===== SerCx_QueryFriendlyNameFromAcpi @ 1c0010bb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_QueryFriendlyNameFromAcpi(struct WDFDEVICE__ * __ptr64,struct _SERCX_CONTEXT *
   __ptr64) */

long __cdecl SerCx_QueryFriendlyNameFromAcpi(WDFDEVICE__ *param_1,_SERCX_CONTEXT *param_2)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  int *piVar9;
  longlong lVar10;
  ulonglong uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  undefined4 local_res18 [2];
  undefined4 local_res20;
  undefined4 local_res24;
  undefined8 *puVar15;
  undefined4 uVar16;
  undefined8 local_68;
  int *piStack_60;
  ulonglong local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  
  piVar9 = (int *)0x0;
  uVar5 = 0x80;
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  local_50 = 1;
  local_40 = 8;
  local_58 = 0;
  local_48 = &local_res20;
  local_res20 = 0x42696541;
  local_68 = 0;
  piStack_60 = (int *)0x0;
  local_res24 = 0x4453445f;
  while( true ) {
    if (piVar9 != (int *)0x0) {
      ExFreePoolWithTag(piVar9,0x32584353);
    }
    piVar9 = (int *)ExAllocatePool2(0x40,uVar5,0x32584353);
    if (piVar9 == (int *)0x0) {
      iVar7 = -0x3fffff66;
      goto LAB_1c0010ee6;
    }
    puVar15 = &local_50;
    local_68 = 1;
    local_58 = (ulonglong)uVar5;
    piStack_60 = piVar9;
    iVar7 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar8,0,0x32c004,puVar15,&local_68,0,0);
    if (iVar7 != -0x7ffffffb) break;
    uVar5 = piVar9[1];
  }
  if (-1 < iVar7) {
    if (*piVar9 == 0x426f6541) {
      uVar5 = piVar9[2];
      if (uVar5 != 0) {
        piVar12 = piVar9 + 3;
        bVar4 = false;
        uVar14 = 0;
        do {
          if (bVar4) goto LAB_1c0010d7b;
          if ((((uVar14 & 1) == 0) && ((short)*piVar12 == 2)) &&
             (*(short *)((longlong)piVar12 + 2) == 0x10)) {
            lVar10 = RtlCompareMemory(piVar12 + 1,&ACPI_DEVICE_PROPERTIES_DSD_GUID);
            if (lVar10 == 0x10) {
              bVar4 = true;
            }
          }
          uVar11 = (ulonglong)*(ushort *)((longlong)piVar12 + 2);
          if (*(ushort *)((longlong)piVar12 + 2) < 4) {
            uVar11 = 4;
          }
          uVar14 = uVar14 + 1;
          piVar12 = (int *)((longlong)piVar12 + uVar11 + 4);
          uVar5 = piVar9[2];
        } while (uVar14 < uVar5);
        if (bVar4) {
LAB_1c0010d7b:
          if ((uVar14 < uVar5) && ((short)*piVar12 == 3)) {
            piVar13 = piVar12 + 1;
            piVar12 = (int *)((ulonglong)*(ushort *)((longlong)piVar12 + 2) + (longlong)piVar13);
            for (; piVar13 + 2 <= piVar12; piVar13 = (int *)((longlong)piVar13 + uVar11 + 4)) {
              if (((short)*piVar13 == 3) &&
                 (uVar2 = *(ushort *)((longlong)piVar13 + 2), 0xf < uVar2)) {
                piVar1 = piVar13 + 1;
                if (((short)*piVar1 == 1) && (*(short *)((longlong)piVar13 + 6) == 0x13)) {
                  iVar6 = strncmp((char *)(piVar13 + 2),"SerCx-FriendlyName",0x13);
                  uVar16 = (undefined4)((ulonglong)puVar15 >> 0x20);
                  if (iVar6 == 0) {
                    uVar11 = 4;
                    if (3 < *(ushort *)((longlong)piVar13 + 6)) {
                      uVar11 = (ulonglong)*(ushort *)((longlong)piVar13 + 6);
                    }
                    if (uVar11 + 0xc + (longlong)piVar1 <= (longlong)piVar1 + (ulonglong)uVar2) {
                      lVar10 = ExAllocatePool2(0x40,(ulonglong)
                                                    *(ushort *)(uVar11 + 6 + (longlong)piVar1) * 2,
                                               0x32584353);
                      *(longlong *)(param_2 + 0x1b0) = lVar10;
                      if (lVar10 == 0) {
                        iVar7 = -0x3fffff66;
                      }
                      else {
                        sVar3 = *(short *)(uVar11 + 6 + (longlong)piVar1) * 2;
                        local_res18[0] = 0;
                        *(short *)(param_2 + 0x1aa) = sVar3;
                        iVar7 = RtlMultiByteToUnicodeN
                                          (lVar10,sVar3,local_res18,(longlong)piVar13 + uVar11 + 0xc
                                           ,CONCAT44(uVar16,(uint)*(ushort *)
                                                                   (uVar11 + 6 + (longlong)piVar1)))
                        ;
                        if (-1 < iVar7) {
                          *(short *)(param_2 + 0x1a8) = (short)local_res18[0] + -2;
                        }
                      }
                      break;
                    }
                  }
                }
              }
              uVar11 = (ulonglong)*(ushort *)((longlong)piVar13 + 2);
              if (*(ushort *)((longlong)piVar13 + 2) < 4) {
                uVar11 = 4;
              }
            }
          }
        }
      }
    }
    else {
      iVar7 = -0x3ffffff3;
    }
  }
  ExFreePoolWithTag(piVar9,0x32584353);
  if (iVar7 < 0) {
LAB_1c0010ee6:
    if (*(longlong *)(param_2 + 0x1b0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x1b0),0x32584353);
      *(undefined8 *)(param_2 + 0x1a8) = 0;
      *(undefined8 *)(param_2 + 0x1b0) = 0;
    }
  }
  return iVar7;
}



===== SerCx_ReadRegistryValues @ 1c0010f34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_ReadRegistryValues(struct _SERCX_CONTEXT * __ptr64) */

long __cdecl SerCx_ReadRegistryValues(_SERCX_CONTEXT *param_1)

{
  int iVar1;
  long lVar2;
  undefined2 uVar3;
  WDFKEY__ *local_res10;
  
  local_res10 = (WDFKEY__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x37,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3b8))
                    (WdfDriverGlobals,*WdfDriverGlobals,0x20019,0,&local_res10);
  if (iVar1 < 0) {
    local_res10 = (WDFKEY__ *)0x0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00110e7;
    uVar3 = 0x38;
  }
  else {
    iVar1 = SerCx_ReadULongFromParametersRegistryValue
                      (param_1,local_res10,(ushort *)L"RxPioThreshold",(ulong *)(param_1 + 0x140),
                       (uchar *)(param_1 + 0x148));
    if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fffffcc)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00110e7;
      uVar3 = 0x39;
    }
    else {
      iVar1 = SerCx_ReadULongFromParametersRegistryValue
                        (param_1,local_res10,(ushort *)L"TxPioThreshold",(ulong *)(param_1 + 0x144),
                         (uchar *)(param_1 + 0x149));
      if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3fffffcc)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00110e7;
        uVar3 = 0x3a;
      }
      else {
        iVar1 = SerCx_ReadULongFromParametersRegistryValue
                          (param_1,local_res10,(ushort *)L"Flags",(ulong *)(param_1 + 0x13c),
                           (uchar *)0x0);
        if ((((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar1 == -0x3fffffcc)) ||
           ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
        goto LAB_1c00110e7;
        uVar3 = 0x3b;
      }
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x130),2,10,uVar3,
                    &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar1);
LAB_1c00110e7:
  if (local_res10 != (WDFKEY__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  lVar2 = 0;
  if (iVar1 != -0x3fffffcc) {
    lVar2 = iVar1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3c,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar2;
}



===== SerCx_ReadULongFromParametersRegistryValue @ 1c0011168 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_ReadULongFromParametersRegistryValue(struct _SERCX_CONTEXT * __ptr64,struct
   WDFKEY__ * __ptr64,unsigned short const * __ptr64,unsigned long * __ptr64,unsigned char *
   __ptr64) */

long __cdecl
SerCx_ReadULongFromParametersRegistryValue
          (_SERCX_CONTEXT *param_1,WDFKEY__ *param_2,ushort *param_3,ulong *param_4,uchar *param_5)

{
  int iVar1;
  ulong local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_30 = 0;
  uStack_28 = 0;
  local_38[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3d,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  RtlInitUnicodeString(&local_30,param_3);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,param_2,&local_30,local_38);
  if (iVar1 < 0) {
    if ((iVar1 != -0x3fffffcc) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_Sd(*(undefined8 *)(param_1 + 0x130));
    }
  }
  else {
    *param_4 = local_38[0];
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DS(*(undefined8 *)(param_1 + 0x130));
    }
  }
  if (param_5 != (uchar *)0x0) {
    *param_5 = (byte)((uint)iVar1 >> 0x1f) ^ 1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x40,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return iVar1;
}



===== SerCx_SetDefaultSecurityDescriptor @ 1c00112d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_SetDefaultSecurityDescriptor(struct WDFDEVICE_INIT * __ptr64) */

long __cdecl SerCx_SetDefaultSecurityDescriptor(WDFDEVICE_INIT *param_1)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x20,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x230))(WdfDriverGlobals,param_1,0x80,1);
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x220))(WdfDriverGlobals,param_1,&DAT_1c001e000);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x21,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar1;
}



===== SerCx_SetupQueues @ 1c00113bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_SetupQueues(struct WDFDEVICE__ * __ptr64) */

long __cdecl SerCx_SetupQueues(WDFDEVICE__ *param_1)

{
  long lVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *pvVar6;
  ulong uVar7;
  undefined2 uVar8;
  void *local_res10;
  void *local_res18;
  RECORDER_LOG__ *local_res20;
  undefined8 local_e8;
  code *pcStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  undefined4 local_98;
  undefined8 local_94;
  undefined1 local_8c [12];
  code *local_80;
  code *local_78;
  code *local_70;
  undefined4 local_48;
  undefined8 local_40;
  
  local_b0 = 0;
  puVar4 = (undefined4 *)0x0;
  local_a0 = 0;
  puVar5 = (undefined4 *)0x0;
  local_res10 = (void *)0x0;
  local_res18 = (void *)0x0;
  local_a8 = 0;
  local_res20 = (RECORDER_LOG__ *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x28,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  local_e8 = 0x38;
  local_b8 = PTR__WDF_RECEIVE_CONTEXT_TYPE_INFO_1c0023a68;
  local_d8 = 0;
  pcStack_e0 = Receive_EvtQueueCleanup;
  uStack_d0 = 0x100000001;
  local_c8 = 0;
  uStack_c0 = 0;
  memset(&local_98,0,0x60);
  local_80 = Receive_EvtIoRead;
  local_98 = 0x60;
  local_40 = *WdfDriverGlobals;
  local_94 = 1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,param_1,&local_98,&local_e8,&local_res10);
  if (iVar2 < 0) {
    local_res10 = (void *)0x0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x29;
LAB_1c0011514:
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar3 + 0x130),2,10,uVar8,
                        &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)iVar2);
    }
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_res10);
    uVar7 = 0;
    *puVar4 = 0x65766352;
    *(longlong *)(puVar4 + 4) = lVar3;
    *(void **)(puVar4 + 2) = local_res10;
    pvVar6 = local_res10;
    (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,local_res10,0,0);
    lVar1 = SerCx_CreateRecorderLog(*(ulong *)(lVar3 + 0x138),(ulong)pvVar6,uVar7,"RX",&local_res20)
    ;
    if ((lVar1 < 0) &&
       (local_res20 = *(RECORDER_LOG__ **)(lVar3 + 0x130),
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      pvVar6 = (void *)CONCAT71((int7)((ulonglong)pvVar6 >> 8),2);
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar3 + 0x130),2,10,0x2a,
                        &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)lVar1);
    }
    *(undefined4 **)(lVar3 + 0xd0) = puVar4;
    iVar2 = Transfer_SMContextInit
                      ((_TRANSFER_SM_CONTEXT *)(puVar4 + 0xe),
                       (_REQUEST_TYPE)CONCAT71((int7)((ulonglong)pvVar6 >> 8),0x72),local_res10,
                       local_res20);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x2b;
        goto LAB_1c0011514;
      }
    }
    else {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x2e8))(WdfDriverGlobals,param_1,local_res10,3);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x2c;
          goto LAB_1c0011514;
        }
      }
      else {
        local_b8 = PTR__WDF_TRANSMIT_CONTEXT_TYPE_INFO_1c0023d80;
        local_e8 = 0x38;
        local_d8 = 0;
        uStack_d0 = 0x100000001;
        local_c8 = 0;
        uStack_c0 = 0;
        pcStack_e0 = Transmit_EvtQueueCleanup;
        memset(&local_98,0,0x60);
        local_78 = Transmit_EvtIoWrite;
        local_98 = 0x60;
        local_94 = 1;
        local_40 = *WdfDriverGlobals;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,param_1,&local_98,&local_e8,&local_res18);
        if (iVar2 < 0) {
          local_res18 = (void *)0x0;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar8 = 0x2d;
            goto LAB_1c0011514;
          }
        }
        else {
          puVar5 = (undefined4 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_res18);
          uVar7 = 0;
          *puVar5 = 0x746d7854;
          *(longlong *)(puVar5 + 4) = lVar3;
          *(void **)(puVar5 + 2) = local_res18;
          pvVar6 = local_res18;
          (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,local_res18,0,0);
          lVar1 = SerCx_CreateRecorderLog
                            (*(ulong *)(lVar3 + 0x138),(ulong)pvVar6,uVar7,"TX",&local_res20);
          if ((lVar1 < 0) &&
             (local_res20 = *(RECORDER_LOG__ **)(lVar3 + 0x130),
             (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            pvVar6 = (void *)CONCAT71((int7)((ulonglong)pvVar6 >> 8),2);
            WPP_RECORDER_SF_d(*(undefined8 *)(lVar3 + 0x130),2,10,0x2e,
                              &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)lVar1);
          }
          *(undefined4 **)(lVar3 + 200) = puVar5;
          iVar2 = Transfer_SMContextInit
                            ((_TRANSFER_SM_CONTEXT *)(puVar5 + 0xe),
                             (_REQUEST_TYPE)CONCAT71((int7)((ulonglong)pvVar6 >> 8),0x74),
                             local_res18,local_res20);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar8 = 0x2f;
              goto LAB_1c0011514;
            }
          }
          else {
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x2e8))
                              (WdfDriverGlobals,param_1,local_res18,4);
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = 0x30;
                goto LAB_1c0011514;
              }
            }
            else {
              local_b8 = (undefined *)0x0;
              local_d8 = 0;
              pcStack_e0 = (code *)0x0;
              uStack_d0 = 0x400000001;
              local_c8 = 0;
              uStack_c0 = 0;
              local_e8 = 0x38;
              memset(local_8c,0,0x54);
              local_98 = 0x60;
              local_94 = 0x100000003;
              local_40 = *WdfDriverGlobals;
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                (WdfDriverGlobals,param_1,&local_98,&local_e8,&local_a8);
              if (-1 < iVar2) {
                *(longlong *)(lVar3 + 0x100) = local_a8;
                memset(&local_98,0,0x60);
                local_70 = Ioctl_EvtIoControl;
                local_94 = 0x100000001;
                local_98 = 0x60;
                local_40 = *WdfDriverGlobals;
                local_d8 = 0;
                uStack_d0 = 0x100000001;
                local_b8 = (undefined *)0x0;
                pcStack_e0 = (code *)0x0;
                local_e8 = 0x38;
                local_c8 = 0;
                uStack_c0 = 0;
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,param_1,&local_98,&local_e8,&local_b0);
                if (iVar2 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar8 = 0x31;
                    goto LAB_1c0011514;
                  }
                }
                else {
                  iVar2 = (**(code **)(WdfFunctions_01015 + 0x2e8))
                                    (WdfDriverGlobals,param_1,local_b0,0xe);
                  if (iVar2 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar8 = 0x32;
                      goto LAB_1c0011514;
                    }
                  }
                  else {
                    *(longlong *)(lVar3 + 0x110) = local_b0;
                    memset(&local_98,0,0x60);
                    local_48 = 0xffffffff;
                    local_70 = Ioctl_EvtPassiveIoControl;
                    local_98 = 0x60;
                    local_94 = 0x100000002;
                    local_40 = *WdfDriverGlobals;
                    local_d8 = 0;
                    local_b8 = (undefined *)0x0;
                    pcStack_e0 = (code *)0x0;
                    local_e8 = 0x38;
                    local_c8 = 0;
                    uStack_c0 = 0;
                    uStack_d0 = 0x100000002;
                    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                      (WdfDriverGlobals,param_1,&local_98,&local_e8,&local_a0);
                    if (-1 < iVar2) {
                      *(longlong *)(lVar3 + 0x118) = local_a0;
                      goto LAB_1c0011604;
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar8 = 0x33;
                      goto LAB_1c0011514;
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
  if (local_res10 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(puVar4 + 2) = 0;
  }
  if (local_res18 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(puVar5 + 2) = 0;
  }
  if (local_a8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar3 + 0x100) = 0;
  }
  if (local_b0 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar3 + 0x110) = 0;
  }
  if (local_a0 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
    *(undefined8 *)(lVar3 + 0x118) = 0;
  }
LAB_1c0011604:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x34,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return iVar2;
}



===== SerCx_ValidateConfig @ 1c0011bc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl SerCx_ValidateConfig(struct _SERCX2_CONFIG * __ptr64) */

long __cdecl SerCx_ValidateConfig(_SERCX2_CONFIG *param_1)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x1e,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar1 = Verifier_VerifyNotNull(param_1);
  if (-1 < lVar1) {
    if (*(int *)param_1 == 0x50) {
      if (((*(longlong *)(param_1 + 0x30) == 0) || (*(longlong *)(param_1 + 0x28) == 0)) ||
         (*(longlong *)(param_1 + 0x20) == 0)) {
        lVar1 = -0x3ffffff3;
      }
      if ((*(longlong *)(param_1 + 0x48) != 0) &&
         (*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x20) != 0)) {
        Verifier_DbgBreak("Assert Failed: Config->RequestAttributes->ParentObject == 0",1);
        lVar1 = -0x3ffffff3;
      }
    }
    else {
      lVar1 = -0x3ffffffc;
      (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x1f,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar1;
}



===== _SerCx2InitializeDevice @ 1c0011cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl _SerCx2InitializeDevice(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct _SERCX2_CONFIG * __ptr64) */

long __cdecl
_SerCx2InitializeDevice(_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_SERCX2_CONFIG *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  _SERCX_CONTEXT *p_Var4;
  _WDF_DRIVER_GLOBALS *p_Var5;
  undefined8 uVar6;
  WDFDEVICE__ *pWVar7;
  _SERCX_DRIVER_CONTEXT *p_Var8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  _SERCX_DRIVER_CONTEXT *p_Var12;
  undefined2 uVar13;
  longlong *plVar14;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  _SERCX_CONTEXT *local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  code *local_70;
  undefined8 uStack_68;
  WDFDEVICE__ *local_60;
  undefined8 uStack_58;
  undefined *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_50 = (undefined *)0x0;
  local_48 = 0x41c6013da3bc0875;
  local_88 = (_SERCX_CONTEXT *)0x0;
  local_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  local_70 = (code *)0x0;
  uStack_68 = 0;
  local_60 = (WDFDEVICE__ *)0x0;
  uStack_58 = 0;
  p_Var5 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var5 = (_WDF_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var5 = *(_WDF_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var5,5,3,0x12,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  puVar10 = auStackY_b8;
  iVar3 = Verifier_VerifyIrqlEquals((uchar)p_Var5);
  puVar9 = auStackY_b8;
  if ((((-1 < iVar3) &&
       (iVar3 = Verfier_VerifyPrivateGlobals((_SERCX_CLIENT_GLOBALS *)(param_1 + -8)),
       puVar9 = auStackY_b8, -1 < iVar3)) &&
      (iVar3 = Verifier_VerifyNotNull(param_2), puVar9 = auStackY_b8, -1 < iVar3)) &&
     (iVar3 = SerCx_ValidateConfig(param_3), puVar9 = auStackY_b8, -1 < iVar3)) {
    puVar11 = &local_80;
    local_50 = PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0;
    uStack_7c = 0;
    uStack_78 = 0;
    local_70 = SerCx_EvtDestroy;
    uStack_74 = 0;
    local_60 = (WDFDEVICE__ *)0x0;
    uStack_58 = 0;
    local_80 = 0x38;
    uStack_68 = 0x100000001;
    pWVar7 = param_2;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_2,puVar11,&local_88);
    puVar9 = auStackY_b8;
    if (-1 < iVar3) {
      *(undefined8 *)(local_88 + 0x20) = 0;
      *(undefined8 *)(local_88 + 0x18) = 0;
      LOCK();
      p_Var12 = g_SerCx2DriverContext + 0x24;
      iVar3 = *(int *)p_Var12;
      *(int *)p_Var12 = *(int *)p_Var12 + 1;
      UNLOCK();
      *(int *)(local_88 + 0x138) = iVar3 + 1;
      iVar3 = SerCx_CreateRecorderLog
                        (*(ulong *)(local_88 + 0x138),(ulong)pWVar7,(ulong)puVar11,"DEV",
                         (RECORDER_LOG__ **)(local_88 + 0x130));
      puVar9 = auStackY_b8;
      if (-1 < iVar3) {
        local_50 = (undefined *)0x0;
        local_70 = (code *)0x0;
        uStack_7c = 0;
        uStack_78 = 0;
        uStack_74 = 0;
        local_80 = 0x38;
        uStack_58 = 0;
        uStack_68 = 0x100000001;
        local_60 = param_2;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                          (WdfDriverGlobals,&local_80,local_88 + 0x170);
        if (iVar3 < 0) {
          puVar10 = auStackY_b8;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c001226d;
          uVar13 = 0x13;
LAB_1c0011ef4:
          uVar6 = *(undefined8 *)(local_88 + 0x130);
        }
        else {
          iVar3 = ExSubscribeWnfStateChange(local_88 + 0x150,&local_48,1,0);
          if (iVar3 < 0) {
            puVar10 = auStackY_b8;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c001226d;
            uVar13 = 0x14;
          }
          else {
            iVar3 = PoRegisterPowerSettingCallback
                              (0,&GUID_LOW_POWER_EPOCH,SerCx_PowerSettingCallback,param_2);
            if (-1 < iVar3) {
              iVar3 = SerCx_ReadRegistryValues(local_88);
              if (iVar3 < 0) {
                puVar10 = auStackY_b8;
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1c001226d;
                uVar13 = 0x16;
              }
              else {
                local_50 = (undefined *)0x0;
                local_70 = (code *)0x0;
                uStack_7c = 0;
                uStack_78 = 0;
                uStack_74 = 0;
                local_80 = 0x38;
                uStack_58 = 0;
                uStack_68 = 0x100000001;
                local_60 = param_2;
                iVar3 = (**(code **)(WdfFunctions_01015 + 0x9d8))
                                  (WdfDriverGlobals,&local_80,local_88 + 0x108);
                if (iVar3 < 0) {
                  puVar10 = auStackY_b8;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_1c001226d;
                  uVar13 = 0x17;
                }
                else {
                  *(WDFDEVICE__ **)(local_88 + 0x10) = param_2;
                  uVar6 = *(undefined8 *)(param_3 + 8);
                  *(undefined8 *)(local_88 + 0x28) = *(undefined8 *)param_3;
                  *(undefined8 *)(local_88 + 0x30) = uVar6;
                  uVar6 = *(undefined8 *)(param_3 + 0x18);
                  *(undefined8 *)(local_88 + 0x38) = *(undefined8 *)(param_3 + 0x10);
                  *(undefined8 *)(local_88 + 0x40) = uVar6;
                  uVar6 = *(undefined8 *)(param_3 + 0x28);
                  *(undefined8 *)(local_88 + 0x48) = *(undefined8 *)(param_3 + 0x20);
                  *(undefined8 *)(local_88 + 0x50) = uVar6;
                  uVar6 = *(undefined8 *)(param_3 + 0x38);
                  *(undefined8 *)(local_88 + 0x58) = *(undefined8 *)(param_3 + 0x30);
                  *(undefined8 *)(local_88 + 0x60) = uVar6;
                  uVar6 = *(undefined8 *)(param_3 + 0x48);
                  *(undefined8 *)(local_88 + 0x68) = *(undefined8 *)(param_3 + 0x40);
                  *(undefined8 *)(local_88 + 0x70) = uVar6;
                  if (*(longlong *)(local_88 + 0x70) != 0) {
                    puVar1 = *(undefined8 **)(param_3 + 0x48);
                    uVar6 = puVar1[1];
                    *(undefined8 *)(local_88 + 0x78) = *puVar1;
                    *(undefined8 *)(local_88 + 0x80) = uVar6;
                    uVar6 = puVar1[3];
                    *(undefined8 *)(local_88 + 0x88) = puVar1[2];
                    *(undefined8 *)(local_88 + 0x90) = uVar6;
                    uVar6 = puVar1[5];
                    *(undefined8 *)(local_88 + 0x98) = puVar1[4];
                    *(undefined8 *)(local_88 + 0xa0) = uVar6;
                    *(undefined8 *)(local_88 + 0xa8) = puVar1[6];
                    *(_SERCX_CONTEXT **)(local_88 + 0x70) = local_88 + 0x78;
                  }
                  iVar3 = SerCx_QueryFriendlyName(param_2,local_88);
                  if (iVar3 < 0) {
                    puVar10 = auStackY_b8;
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                    goto LAB_1c001226d;
                    uVar13 = 0x18;
                  }
                  else {
                    iVar3 = SerCx_CreateResourceHubTarget(param_2,local_88);
                    if (iVar3 < 0) {
                      puVar10 = auStackY_b8;
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                      goto LAB_1c001226d;
                      uVar13 = 0x19;
                    }
                    else {
                      iVar3 = SerCx_SetupQueues(param_2);
                      if (iVar3 < 0) {
                        puVar10 = auStackY_b8;
                        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                        goto LAB_1c001226d;
                        uVar13 = 0x1a;
                      }
                      else {
                        iVar3 = SerCx_ApplySecurityDescriptor(param_2);
                        if (iVar3 < 0) {
                          puVar10 = auStackY_b8;
                          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                          goto LAB_1c001226d;
                          uVar13 = 0x1b;
                        }
                        else {
                          *(undefined8 *)(local_88 + 400) = 0;
                          *(undefined8 *)(local_88 + 0x198) = 0;
                          *(undefined4 *)(local_88 + 0x1a0) = 0;
                          if ((*(short *)(local_88 + 0x1a8) == 0) ||
                             (iVar3 = SerCx_CreateDeviceInterface(param_2,local_88), -1 < iVar3)) {
                            Etw_DeviceCreate(param_2);
                            (**(code **)(WdfFunctions_01015 + 0x9e0))
                                      (WdfDriverGlobals,*(undefined8 *)(g_SerCx2DriverContext + 8));
                            puVar9 = auStackY_b8;
                            p_Var4 = local_88 + 0x18;
                            p_Var12 = g_SerCx2DriverContext + 0x10;
                            plVar14 = *(longlong **)(g_SerCx2DriverContext + 0x18);
                            p_Var8 = g_SerCx2DriverContext;
                            if ((_SERCX_DRIVER_CONTEXT *)*plVar14 != p_Var12) {
                              pcVar2 = (code *)swi(0x29);
                              p_Var4 = (_SERCX_CONTEXT *)(*pcVar2)(3);
                              puVar9 = auStackY_b0;
                            }
                            *(_SERCX_DRIVER_CONTEXT **)p_Var4 = p_Var12;
                            *(longlong **)(p_Var4 + 8) = plVar14;
                            *plVar14 = (longlong)p_Var4;
                            *(_SERCX_CONTEXT **)(p_Var12 + 8) = p_Var4;
                            *(int *)(p_Var8 + 0x20) = *(int *)(p_Var8 + 0x20) + 1;
                            uVar6 = *(undefined8 *)(p_Var8 + 8);
                            pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
                            *(undefined8 *)(puVar9 + -8) = 0x1c0012236;
                            (*pcVar2)(WdfDriverGlobals,uVar6);
                            goto LAB_1c001223d;
                          }
                          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                          goto LAB_1c001226d;
                          uVar13 = 0x1c;
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_1c0011ef4;
            }
            puVar10 = auStackY_b8;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c001226d;
            uVar13 = 0x15;
          }
          uVar6 = 0;
        }
        WPP_RECORDER_SF_d(uVar6,2,3,uVar13,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,
                          (char)iVar3);
        puVar9 = auStackY_b8;
      }
    }
  }
LAB_1c001223d:
  puVar10 = puVar9;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined **)(puVar9 + 0x20) = &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids;
    *(undefined8 *)(puVar9 + -8) = 0x1c001226d;
    WPP_RECORDER_SF_(uVar6,5,3,0x1d,*(undefined8 *)(puVar9 + 0x20));
  }
LAB_1c001226d:
  *(undefined8 *)(puVar10 + -8) = 0x1c001227b;
  return iVar3;
}



===== _SerCx2InitializeDeviceInit @ 1c00122a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2InitializeDeviceInit(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   WDFDEVICE_INIT * __ptr64) */

long __cdecl _SerCx2InitializeDeviceInit(_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  WDFCXDEVICE_INIT *pWVar2;
  _WDF_DRIVER_GLOBALS *p_Var3;
  undefined2 uVar4;
  undefined1 local_res18 [8];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_68 = 0;
  uStack_60 = 0;
  local_38 = (undefined *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  p_Var3 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (p_Var3 = (_WDF_DRIVER_GLOBALS *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) {
    p_Var3 = *(_WDF_DRIVER_GLOBALS **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(p_Var3,5,3,10,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  lVar1 = Verifier_VerifyIrqlEquals((uchar)p_Var3);
  if (((-1 < lVar1) &&
      (lVar1 = Verfier_VerifyPrivateGlobals((_SERCX_CLIENT_GLOBALS *)(param_1 + -8)), -1 < lVar1))
     && (lVar1 = Verifier_VerifyNotNull(param_2), -1 < lVar1)) {
    pWVar2 = (WDFCXDEVICE_INIT *)(**(code **)(WdfFunctions_01015 + 0xc60))(WdfDriverGlobals,param_2)
    ;
    lVar1 = Verifier_VerifyNotNull(pWVar2);
    if (((-1 < lVar1) && (lVar1 = File_InitFileObject(param_2,pWVar2), -1 < lVar1)) &&
       (lVar1 = SerCx_SetDefaultSecurityDescriptor(param_2), -1 < lVar1)) {
      local_38 = PTR__WDF_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023d08;
      local_68 = CONCAT44(local_68._4_4_,0x38);
      uStack_50 = 0x100000001;
      (**(code **)(WdfFunctions_01015 + 0xc78))(WdfDriverGlobals,pWVar2,&local_68);
      lVar1 = (**(code **)(WdfFunctions_01015 + 0xc68))
                        (WdfDriverGlobals,pWVar2,Ioctl_EvtIrpPreprocess,0xe,0,0);
      if (lVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar1;
        }
        uVar4 = 0xb;
      }
      else {
        local_res18[0] = 2;
        lVar1 = (**(code **)(WdfFunctions_01015 + 0xc68))
                          (WdfDriverGlobals,pWVar2,SerCx_PowerIrpPreprocess,0x16,local_res18,1);
        if (lVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return lVar1;
          }
          uVar4 = 0xc;
        }
        else {
          local_res18[0] = 0;
          lVar1 = (**(code **)(WdfFunctions_01015 + 0xc68))
                            (WdfDriverGlobals,pWVar2,SerCx_PnpIrpPreprocess,0x1b,local_res18,1);
          if (-1 < lVar1) goto LAB_1c00124ed;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return lVar1;
          }
          uVar4 = 0xd;
        }
      }
      WPP_RECORDER_SF_d(0,2,3,uVar4,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,(char)lVar1);
    }
  }
LAB_1c00124ed:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xe,
                     &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids);
  }
  return lVar1;
}



===== McTemplateK0p_EtwWriteTransfer @ 1c0012548 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0p_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 8;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventDeviceDestroy,0,2,local_38);
  return;
}



===== McTemplateK0pdd_EtwWriteTransfer @ 1c00125b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pdd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = &local_res20;
  local_30 = 4;
  local_38 = &param_5;
  local_20 = 4;
  local_28 = &param_6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0ujqzr2jxxx_EtwWriteTransfer @ 1c0012634 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0ujqzr2jxxx_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 auStackY_e8 [32];
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8 [2];
  undefined1 *local_98;
  undefined8 local_90;
  undefined8 local_80;
  undefined4 *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_b8[0] = 6;
  local_98 = local_res20;
  local_b0 = 0;
  local_78 = local_b8;
  local_90 = 1;
  local_80 = 0x10;
  local_68 = L"CLIENT";
  local_48 = &uStack0000000000000048;
  local_38 = &uStack0000000000000050;
  local_28 = &local_b0;
  local_70 = 4;
  local_60 = 0xc;
  local_50 = 0x10;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SLEEPSTUDY_ETW_PROVIDER_Context,&SLEEPSTUDY_EVT_SCENARIO_BLOCKER,0,9,
             local_a8);
  return;
}



===== RESOURCE_HUB_STRING_PRINTF @ 1c0012728 =====

void RESOURCE_HUB_STRING_PRINTF(ushort *param_1,__uint64 param_2,ushort *param_3,__uint64 *param_4)

{
  __uint64 *local_res20;
  ulong in_stack_ffffffffffffffc8;
  
  local_res20 = param_4;
  RtlStringCbVPrintfExW
            (param_1,param_2,(ushort **)0x0,param_4,in_stack_ffffffffffffffc8,param_3,
             (char *)&local_res20);
  return;
}



===== RESOURCE_HUB_UNICODE_STRING_PRINTF @ 1c0012758 =====

void RESOURCE_HUB_UNICODE_STRING_PRINTF
               (short *param_1,ushort *param_2,undefined8 param_3,__uint64 *param_4)

{
  long lVar1;
  undefined8 local_res18;
  __uint64 *local_res20;
  ulong in_stack_ffffffffffffffc8;
  ushort *local_18 [2];
  
  local_18[0] = (ushort *)0x0;
  local_res18 = param_3;
  local_res20 = param_4;
  lVar1 = RtlStringCbVPrintfExW
                    (*(ushort **)(param_1 + 4),(ulonglong)(ushort)param_1[1],local_18,param_4,
                     in_stack_ffffffffffffffc8,param_2,(char *)&local_res18);
  if (-1 < lVar1) {
    *param_1 = (short)((longlong)(ulonglong)(uint)((int)local_18[0] - *(int *)(param_1 + 4)) >> 1) *
               2;
  }
  return;
}



===== WPP_RECORDER_SF_DS @ 1c00127bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
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
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,0x3f,&uStack0000000000000030,4,
               pwVar2,lVar1,0);
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000038[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,10,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,0x3f,
                  &uStack0000000000000030,4,in_stack_00000038,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c0012910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  lVar3 = -1;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
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
               &WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,0x3e,pwVar2,lVar1,
               &uStack0000000000000038,4,0);
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (in_stack_00000030[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,10,&WPP_afdde2fa70bc39562b3e5990ddb83a3d_Traceguids,0x3e,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,0);
  return;
}



===== Transmit_CancelCustomTransaction @ 1c0012a64 =====

/* void __cdecl Transmit_CancelCustomTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_CancelCustomTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x88,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  IoCancelIrp(*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x28));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x89,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_CancelSystemDmaFifoDrain @ 1c0012b18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_CancelSystemDmaFifoDrain(struct _TRANSMIT_CONTEXT *
   __ptr64) */

_SM_ENGINE_EVENT __cdecl Transmit_CancelSystemDmaFifoDrain(_TRANSMIT_CONTEXT *param_1)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x58,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  cVar1 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0x80))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x59,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return (-(uint)(cVar1 != '\0') & 0x10) + 0xebe78082;
}



===== Transmit_CleanupSystemDmaTransaction @ 1c0012bd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_CleanupSystemDmaTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_CleanupSystemDmaTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4a,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x68))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x4b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_EvtConfigureDmaChannel @ 1c0012c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Transmit_EvtConfigureDmaChannel(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,struct _MDL * __ptr64,unsigned __int64,unsigned __int64) */

uchar __cdecl
Transmit_EvtConfigureDmaChannel
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,_MDL *param_4,
          __uint64 param_5,__uint64 param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  _SM_ENGINE_CONTEXT *p_Var4;
  uchar uVar5;
  
  lVar1 = *(longlong *)((longlong)param_3 + 0x20);
  uVar5 = '\0';
  lVar2 = *(longlong *)((longlong)param_3 + 0x68);
  p_Var4 = *(_SM_ENGINE_CONTEXT **)(lVar1 + 8);
  if (param_4 == (_MDL *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      p_Var4 = *(_SM_ENGINE_CONTEXT **)((longlong)param_3 + 0x410);
      WPP_RECORDER_SF_qq(p_Var4,param_2,5,0x44,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                         (char)lVar1,(char)lVar2);
    }
  }
  else {
    iVar3 = (**(code **)(lVar1 + 0x70))(p_Var4,param_4,param_5 & 0xffffffff,param_6 & 0xffffffff);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqdd
                  (*(undefined8 *)((longlong)param_3 + 0x410),2,5,0x45,
                   &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)lVar1,(char)lVar2,
                   (char)*(undefined4 *)(lVar2 + 0x18),(char)iVar3);
      }
      p_Var4 = (_SM_ENGINE_CONTEXT *)((longlong)param_3 + 0x78);
      *(int *)(lVar2 + 4) = iVar3;
      StateMachineEngine_EventAdd(p_Var4,0xebe781a0);
      goto LAB_1c0012ced;
    }
  }
  uVar5 = '\x01';
LAB_1c0012ced:
  if ((DAT_1c0025a81 & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (p_Var4,&SerCx2EtwEventSystemDmaEvent,(longlong)param_3 + 0x58,param_2,3);
  }
  return uVar5;
}



===== Transmit_EvtCustomTransactionDestroy @ 1c0012dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_EvtCustomTransactionDestroy(void * __ptr64) */

void __cdecl Transmit_EvtCustomTransactionDestroy(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x73,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_CUSTOM_TRANSMIT_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023ce0);
  if (*(longlong *)(lVar1 + 0x28) != 0) {
    IoFreeIrp();
    *(undefined8 *)(lVar1 + 0x28) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x74,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_EvtDmaCompletion @ 1c0012eb0 =====

/* void __cdecl Transmit_EvtDmaCompletion(struct WDFDMATRANSACTION__ * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,enum DMA_COMPLETION_STATUS) */

void __cdecl
Transmit_EvtDmaCompletion
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,DMA_COMPLETION_STATUS param_5)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x42,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  *(DMA_COMPLETION_STATUS *)(*(longlong *)((longlong)param_3 + 0x20) + 0x9c) = param_5;
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)((longlong)param_3 + 0x78),0xebe78180);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x43,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_EvtProgramDma @ 1c0012f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Transmit_EvtProgramDma(struct WDFDMATRANSACTION__ * __ptr64,struct
   WDFDEVICE__ * __ptr64,void * __ptr64,enum _WDF_DMA_DIRECTION,struct _SCATTER_GATHER_LIST *
   __ptr64) */

uchar __cdecl
Transmit_EvtProgramDma
          (WDFDMATRANSACTION__ *param_1,WDFDEVICE__ *param_2,void *param_3,
          _WDF_DMA_DIRECTION param_4,_SCATTER_GATHER_LIST *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 in_register_0000008c;
  
  uVar2 = WdfDriverGlobals;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0,
                     CONCAT44(in_register_0000008c,param_4));
  if ((DAT_1c0025a81 & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (uVar2,&SerCx2EtwEventSystemDmaEvent,*(longlong *)(lVar1 + 200) + 0x58,param_2,1);
  }
  return '\x01';
}



===== Transmit_EvtQueueCleanup @ 1c0012fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_EvtQueueCleanup(void * __ptr64) */

void __cdecl Transmit_EvtQueueCleanup(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x33,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_TRANSMIT_CONTEXT_TYPE_INFO_1c0023d80);
  if ((*(longlong *)(lVar1 + 0x410) != 0) &&
     (*(longlong *)(lVar1 + 0x410) != *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x130))) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
  }
  *(undefined8 *)(*(longlong *)(lVar1 + 0x10) + 200) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x34,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_InitializeCustomTransaction @ 1c00130e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_InitializeCustomTransaction(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_InitializeCustomTransaction(_TRANSMIT_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x81,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  (**(code **)(*(longlong *)(param_1 + 0x30) + 0x40))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8),*(undefined8 *)(lVar1 + 0x10),
             *(undefined4 *)(lVar1 + 0x18),*(undefined4 *)(lVar1 + 0x24));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x82,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_InternalInitializeSystemDmaTransaction @ 1c00131a0 =====

/* void __cdecl Transmit_InternalInitializeSystemDmaTransaction(struct _TRANSMIT_CONTEXT * __ptr64)
    */

void __cdecl Transmit_InternalInitializeSystemDmaTransaction(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x38,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x38) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x39,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_ProcessSystemDmaConfigureChannelFailure @ 1c0013248 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Transmit_ProcessSystemDmaConfigureChannelFailure(struct
   _TRANSMIT_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl
Transmit_ProcessSystemDmaConfigureChannelFailure(_TRANSMIT_CONTEXT *param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x40,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18);
  (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar1,0,local_res8);
  (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x41,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return 0xebe78112;
}



===== Transmit_SystemDmaDrainFifo @ 1c0013340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_SystemDmaDrainFifo(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_SystemDmaDrainFifo(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x56,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x78))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x57,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== Transmit_SystemDmaPurgeFifo @ 1c00133ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Transmit_SystemDmaPurgeFifo(struct _TRANSMIT_CONTEXT * __ptr64) */

void __cdecl Transmit_SystemDmaPurgeFifo(_TRANSMIT_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5a,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x88))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x20) + 8),
             *(undefined4 *)(*(longlong *)(param_1 + 0x68) + 0x20));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5b,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2CustomTransmitCreate @ 1c00134b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2CustomTransmitCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__
   * __ptr64,struct _SERCX2_CUSTOM_TRANSMIT_CONFIG * __ptr64,struct _WDF_OBJECT_ATTRIBUTES *
   __ptr64,struct SERCX2CUSTOMTRANSMIT__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2CustomTransmitCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_SERCX2_CUSTOM_TRANSMIT_CONFIG *param_3
          ,_WDF_OBJECT_ATTRIBUTES *param_4,SERCX2CUSTOMTRANSMIT__ **param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  undefined2 uVar10;
  WDFDEVICE__ *local_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined8 uStack_b8;
  WDFDEVICE__ *local_b0;
  undefined8 uStack_a8;
  undefined *local_a0;
  undefined8 local_98 [2];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  code *local_78;
  undefined4 local_38;
  
  local_a0 = (undefined *)0x0;
  local_d8 = (WDFDEVICE__ *)0x0;
  local_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  uStack_c4 = 0;
  local_c0 = 0;
  uStack_bc = 0;
  uStack_b8 = 0;
  local_b0 = (WDFDEVICE__ *)0x0;
  uStack_a8 = 0;
  memset(&local_88,0,0x60);
  local_98[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x6c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar5 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    iVar4 = -0x3ffffe7c;
    goto LAB_1c0013893;
  }
  lVar1 = *(longlong *)(lVar5 + 200);
  uVar2 = *(undefined8 *)(lVar1 + 0x410);
  if (*(longlong *)(lVar1 + 0x18) == 0) {
    pcVar8 = "SerCx2CustomTransmitCreate cannot be called unless Pio Transmit has been created";
LAB_1c00135b5:
    Verifier_DbgBreak(pcVar8,1);
    iVar4 = -0x3ffffff0;
  }
  else {
    if ((*(longlong *)(lVar1 + 0x20) != 0) ||
       (*(longlong *)(*(longlong *)(lVar5 + 0xd0) + 0x20) != 0)) {
      pcVar8 = "SystemDma / Custom are exclusive modes, cannot create both";
      goto LAB_1c00135b5;
    }
    if (*(longlong *)(lVar1 + 0x28) != 0) {
      pcVar8 = "SerCx2CustomTransmitCreate called more than once";
      goto LAB_1c00135b5;
    }
    if (param_3[0x14] != (_SERCX2_CUSTOM_TRANSMIT_CONFIG)0x0) {
      if (((*(int *)(param_3 + 0x10) == 0) && (*(int *)(param_3 + 4) == 0)) &&
         (*(int *)(param_3 + 8) == 0)) {
        *(undefined4 *)(param_3 + 4) = 1;
        uVar9 = 1;
        *(undefined4 *)(param_3 + 0x10) = 1;
        goto LAB_1c0013632;
      }
      pcVar8 = 
      "If Exclusive Flag is set, MinimumTransferUnit, MinimumTransactionLength, Alignment must not be specified"
      ;
      goto LAB_1c001361e;
    }
    uVar9 = *(uint *)(param_3 + 4);
LAB_1c0013632:
    if (*(int *)(param_3 + 0xc) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0xffffffff;
    }
    if (*(int *)(param_3 + 8) == 0) {
      *(undefined4 *)(param_3 + 8) = 1;
    }
    uVar7 = *(uint *)(param_3 + 0x10);
    if (uVar7 == 0) {
      *(undefined4 *)(param_3 + 0x10) = 1;
      uVar7 = 1;
    }
    if (uVar9 == 0) {
      *(uint *)(param_3 + 4) = uVar7;
      uVar9 = uVar7;
      if (uVar7 != 0) goto LAB_1c001365e;
LAB_1c0013665:
      pcVar8 = "MinimumTransferUnit must be a power of 2";
LAB_1c001361e:
      Verifier_DbgBreak(pcVar8,1);
      iVar4 = -0x3ffffff3;
    }
    else {
LAB_1c001365e:
      if ((uVar7 & uVar7 - 1) != 0) goto LAB_1c0013665;
      if ((uVar9 == 0) || ((uVar9 & uVar9 - 1) != 0)) {
        pcVar8 = "Alignment must be a power of 2";
        goto LAB_1c001361e;
      }
      if (uVar9 < uVar7) {
        pcVar8 = "Alignment (if specified) must be >= MinimumTransferUnit";
        goto LAB_1c001361e;
      }
      local_a0 = PTR__WDF_CUSTOM_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023da8;
      uStack_bc = 0;
      uStack_cc = 0;
      uStack_c8 = 0;
      uStack_c4 = 0;
      local_c0 = 0;
      uStack_a8 = 0;
      local_d0 = 0x38;
      uStack_b8 = 0x100000001;
      local_b0 = *(WDFDEVICE__ **)(*(longlong *)(lVar5 + 200) + 8);
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_d0,&local_d8);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(uVar2,2,5,0x6d,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                            (char)iVar4);
        }
      }
      else {
        puVar6 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_d8,
                            PTR__WDF_CUSTOM_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023da8);
        *puVar6 = 0x54737543;
        *(WDFDEVICE__ **)(puVar6 + 2) = local_d8;
        *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(lVar5 + 200);
        uVar3 = *(undefined8 *)(param_3 + 8);
        *(undefined8 *)(puVar6 + 8) = *(undefined8 *)param_3;
        *(undefined8 *)(puVar6 + 10) = uVar3;
        *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(param_3 + 0x10);
        if ((*(char *)(lVar5 + 0x149) != '\0') &&
           (puVar6[10] = *(undefined4 *)(lVar5 + 0x144),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 0x130),4,5,0x6e,
                            &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                            (char)*(undefined4 *)(lVar5 + 0x144));
        }
        local_38 = 0xffffffff;
        local_80 = 0;
        local_88 = 0x60;
        local_a0 = (undefined *)0x0;
        local_c0 = 0;
        uStack_bc = 0;
        uStack_a8 = 0;
        local_b0 = local_d8;
        local_78 = Transmit_EvtCustomIoDefault;
        uStack_cc = 0;
        uStack_c8 = 0;
        uStack_c4 = 0;
        local_d0 = 0x38;
        uStack_b8 = 0x100000001;
        local_84 = 2;
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,param_2,&local_88,&local_d0,local_98);
        if (-1 < iVar4) {
          *(undefined8 *)(puVar6 + 4) = local_98[0];
          if (param_4 != (_WDF_OBJECT_ATTRIBUTES *)0x0) {
            param_2 = local_d8;
            iVar4 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_d8,param_4,0);
            if (iVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x70;
                goto LAB_1c0013870;
              }
              goto LAB_1c0013893;
            }
          }
          *(undefined4 **)(*(longlong *)(lVar5 + 200) + 0x28) = puVar6;
          *param_5 = (SERCX2CUSTOMTRANSMIT__ *)local_d8;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qq(uVar2,param_2,5,0x71,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids
                               ,(char)local_d8,(char)puVar6);
          }
          goto LAB_1c00138b7;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x6f;
LAB_1c0013870:
          WPP_RECORDER_SF_d(uVar2,2,5,uVar10,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                            (char)iVar4);
        }
      }
    }
  }
LAB_1c0013893:
  if (local_d8 != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c00138b7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x72,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return iVar4;
}



===== _SerCx2CustomTransmitTransactionCreate @ 1c00139e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2CustomTransmitTransactionCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2CUSTOMTRANSMIT__ * __ptr64,struct _SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG *
   __ptr64,struct _WDF_OBJECT_ATTRIBUTES * __ptr64,struct SERCX2CUSTOMTRANSMITTRANSACTION__ *
   __ptr64 * __ptr64) */

long __cdecl
_SerCx2CustomTransmitTransactionCreate
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMTRANSMIT__ *param_2,
          _SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG *param_3,_WDF_OBJECT_ATTRIBUTES *param_4,
          SERCX2CUSTOMTRANSMITTRANSACTION__ **param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined4 *puVar9;
  SERCX2CUSTOMTRANSMIT__ *pSVar10;
  undefined2 uVar11;
  SERCX2CUSTOMTRANSMIT__ *local_88;
  SERCX2CUSTOMTRANSMIT__ *local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  SERCX2CUSTOMTRANSMIT__ *local_58;
  undefined8 uStack_50;
  undefined *local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  local_48 = (undefined *)0x0;
  local_88 = (SERCX2CUSTOMTRANSMIT__ *)0x0;
  local_80 = (SERCX2CUSTOMTRANSMIT__ *)0x0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_58 = (SERCX2CUSTOMTRANSMIT__ *)0x0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x75,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  local_38 = (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,
                        PTR__WDF_CUSTOM_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023da8);
  lVar1 = *(longlong *)(local_38 + 0x18);
  local_30 = *(longlong *)(lVar1 + 0x10);
  uVar2 = *(undefined8 *)(lVar1 + 0x410);
  local_40 = (**(code **)(WdfFunctions_01015 + 0xf8))
                       (WdfDriverGlobals,*(undefined8 *)(local_30 + 0x10));
  if (*(longlong *)(lVar1 + 0x30) == 0) {
    iVar6 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x10));
    if (-1 < iVar6) {
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_50 = 0;
      local_48 = PTR__WDF_CUSTOM_TRANSMIT_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023ce0;
      local_68 = 0xc0012dc0;
      uStack_64 = 1;
      local_78 = 0x38;
      uStack_60 = 0x100000001;
      local_58 = param_2;
      iVar6 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_78,&local_88);
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(uVar2,2,5,0x76,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                            (char)iVar6);
        }
      }
      else {
        puVar7 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_88,
                            PTR__WDF_CUSTOM_TRANSMIT_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023ce0);
        *puVar7 = 0x78547543;
        *(SERCX2CUSTOMTRANSMIT__ **)(puVar7 + 2) = local_88;
        *(longlong *)(puVar7 + 6) = local_40;
        *(longlong *)(puVar7 + 0xc) = lVar1;
        *(longlong *)(puVar7 + 4) = local_38;
        uVar3 = *(undefined4 *)(param_3 + 4);
        uVar4 = *(undefined4 *)(param_3 + 8);
        uVar5 = *(undefined4 *)(param_3 + 0xc);
        puVar7[0xe] = *(undefined4 *)param_3;
        puVar7[0xf] = uVar3;
        puVar7[0x10] = uVar4;
        puVar7[0x11] = uVar5;
        uVar3 = *(undefined4 *)(param_3 + 0x14);
        uVar4 = *(undefined4 *)(param_3 + 0x18);
        uVar5 = *(undefined4 *)(param_3 + 0x1c);
        puVar7[0x12] = *(undefined4 *)(param_3 + 0x10);
        puVar7[0x13] = uVar3;
        puVar7[0x14] = uVar4;
        puVar7[0x15] = uVar5;
        lVar8 = IoAllocateIrp(*(char *)(local_40 + 0x4c) + '\x01',0);
        if (lVar8 == 0) {
          iVar6 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(uVar2,2,5,0x77,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
          }
        }
        else {
          *(longlong *)(puVar7 + 10) = lVar8;
          local_48 = PTR__WDF_CUSTOM_TRANSMIT_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023bf0;
          local_58 = local_88;
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 0;
          local_68 = 0;
          uStack_64 = 0;
          uStack_50 = 0;
          local_78 = 0x38;
          uStack_60 = 0x100000001;
          iVar6 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_78,0,&local_80);
          if (iVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0x78;
LAB_1c0013d04:
              WPP_RECORDER_SF_d(uVar2,2,5,uVar11,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                                (char)iVar6);
            }
          }
          else {
            pSVar10 = local_80;
            puVar9 = (undefined4 *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_80,
                                PTR__WDF_CUSTOM_TRANSMIT_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023bf0);
            *puVar9 = 0x63747543;
            *(undefined4 **)(puVar9 + 2) = puVar7;
            if ((*(longlong *)(local_30 + 0x70) == 0) ||
               (pSVar10 = local_80,
               iVar6 = (**(code **)(WdfFunctions_01015 + 0x658))
                                 (WdfDriverGlobals,local_80,*(longlong *)(local_30 + 0x70),0),
               -1 < iVar6)) {
              *(SERCX2CUSTOMTRANSMIT__ **)(puVar7 + 8) = local_80;
              if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
                 (pSVar10 = local_88,
                 iVar6 = (**(code **)(WdfFunctions_01015 + 0x658))
                                   (WdfDriverGlobals,local_88,param_4,0), -1 < iVar6)) {
                *(undefined4 **)(lVar1 + 0x30) = puVar7;
                *param_5 = (SERCX2CUSTOMTRANSMITTRANSACTION__ *)local_88;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qq(uVar2,pSVar10,5,0x7b,
                                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,(char)local_88
                                     ,(char)puVar7);
                }
                goto LAB_1c0013e59;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar11 = 0x7a;
                goto LAB_1c0013d04;
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar11 = 0x79;
              goto LAB_1c0013d04;
            }
          }
        }
      }
    }
  }
  else {
    Verifier_DbgBreak("SerCx2CustomTransmitTransactionCreate called more than once",1);
    iVar6 = -0x3ffffff0;
  }
  if (local_88 != (SERCX2CUSTOMTRANSMIT__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c0013e59:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return iVar6;
}



===== _SerCx2CustomTransmitTransactionInitializeComplete @ 1c0013ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomTransmitTransactionInitializeComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMTRANSMITTRANSACTION__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2CustomTransmitTransactionInitializeComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMTRANSMITTRANSACTION__ *param_2,uchar param_3)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7d,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_TRANSMIT_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023ce0);
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),
             (-(uint)(param_3 != '\0') & 0x50) + 0xebe78021);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x7e,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2PioTransmitCreate @ 1c0013fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2PioTransmitCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct _SERCX2_PIO_TRANSMIT_CONFIG * __ptr64,struct _WDF_OBJECT_ATTRIBUTES *
   __ptr64,struct SERCX2PIOTRANSMIT__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2PioTransmitCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_SERCX2_PIO_TRANSMIT_CONFIG *param_3,
          _WDF_OBJECT_ATTRIBUTES *param_4,SERCX2PIOTRANSMIT__ **param_5)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  SERCX2PIOTRANSMIT__ *local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  local_30 = (undefined *)0x0;
  local_68 = (SERCX2PIOTRANSMIT__ *)0x0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  local_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar6 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    lVar5 = -0x3ffffe7c;
  }
  else {
    uVar1 = *(undefined8 *)(*(longlong *)(lVar6 + 200) + 0x410);
    if (*(longlong *)(*(longlong *)(lVar6 + 200) + 0x18) == 0) {
      lVar5 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x18));
      if (((-1 < lVar5) && (lVar5 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x20)), -1 < lVar5))
         && (lVar5 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x28)), -1 < lVar5)) {
        if (*(longlong *)(param_3 + 0x30) == 0) {
          if ((*(longlong *)(param_3 + 0x38) != 0) || (*(longlong *)(param_3 + 0x40) != 0)) {
LAB_1c0014180:
            lVar5 = -0x3ffffff3;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(uVar1,2,5,0xb,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
            }
            Verifier_DbgBreak("Missing data purge/drain callback",0);
            goto LAB_1c001408a;
          }
        }
        else if ((*(longlong *)(param_3 + 0x38) == 0) || (*(longlong *)(param_3 + 0x40) == 0))
        goto LAB_1c0014180;
        local_30 = PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58;
        uStack_4c = 0;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_54 = 0;
        local_50 = 0;
        uStack_38 = 0;
        local_60 = 0x38;
        uStack_48 = 0x100000001;
        local_40 = *(undefined8 *)(*(longlong *)(lVar6 + 200) + 8);
        lVar5 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_60,&local_68);
        if (lVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0xc;
LAB_1c001425d:
            WPP_RECORDER_SF_d(uVar1,2,5,uVar9,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                              (char)lVar5);
          }
        }
        else {
          puVar7 = (undefined4 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_68,
                              PTR__WDF_PIOTRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023b58);
          *puVar7 = 0x546f6950;
          *(SERCX2PIOTRANSMIT__ **)(puVar7 + 2) = local_68;
          *(undefined8 *)(puVar7 + 4) = *(undefined8 *)(lVar6 + 200);
          uVar8 = *(undefined8 *)(param_3 + 8);
          *(undefined8 *)(puVar7 + 6) = *(undefined8 *)param_3;
          *(undefined8 *)(puVar7 + 8) = uVar8;
          uVar8 = *(undefined8 *)(param_3 + 0x18);
          *(undefined8 *)(puVar7 + 10) = *(undefined8 *)(param_3 + 0x10);
          *(undefined8 *)(puVar7 + 0xc) = uVar8;
          uVar8 = *(undefined8 *)(param_3 + 0x28);
          *(undefined8 *)(puVar7 + 0xe) = *(undefined8 *)(param_3 + 0x20);
          *(undefined8 *)(puVar7 + 0x10) = uVar8;
          uVar2 = *(undefined4 *)(param_3 + 0x34);
          uVar3 = *(undefined4 *)(param_3 + 0x38);
          uVar4 = *(undefined4 *)(param_3 + 0x3c);
          puVar7[0x12] = *(undefined4 *)(param_3 + 0x30);
          puVar7[0x13] = uVar2;
          puVar7[0x14] = uVar3;
          puVar7[0x15] = uVar4;
          *(undefined8 *)(puVar7 + 0x16) = *(undefined8 *)(param_3 + 0x40);
          if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
             (lVar5 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_68,param_4,0)
             , -1 < lVar5)) {
            *(undefined4 **)(*(longlong *)(lVar6 + 200) + 0x18) = puVar7;
            *param_5 = local_68;
            uVar8 = *(undefined8 *)(*(longlong *)(lVar6 + 200) + 8);
            (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals);
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return lVar5;
            }
            WPP_RECORDER_SF_qq(uVar1,uVar8,5,0xe,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                               (char)local_68,(char)puVar7);
            goto LAB_1c00140ad;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0xd;
            goto LAB_1c001425d;
          }
        }
      }
    }
    else {
      Verifier_DbgBreak("SerCx2PioTransmitCreate called more than once",1);
      lVar5 = -0x3ffffff0;
    }
  }
LAB_1c001408a:
  if (local_68 != (SERCX2PIOTRANSMIT__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c00140ad:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xf,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return lVar5;
}



===== _SerCx2SystemDmaTransmitCleanupTransactionComplete @ 1c00143c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaTransmitCleanupTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMATRANSMIT__ * __ptr64) */

void __cdecl
_SerCx2SystemDmaTransmitCleanupTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMATRANSMIT__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x68,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe78071)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x69,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2SystemDmaTransmitCreate @ 1c00144a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2SystemDmaTransmitCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   WDFDEVICE__ * __ptr64,struct _SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG * __ptr64,struct
   _WDF_OBJECT_ATTRIBUTES * __ptr64,struct SERCX2SYSTEMDMATRANSMIT__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2SystemDmaTransmitCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,
          _SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG *param_3,_WDF_OBJECT_ATTRIBUTES *param_4,
          SERCX2SYSTEMDMATRANSMIT__ **param_5)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong lVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  char *pcVar11;
  SERCX2SYSTEMDMATRANSMIT__ *_Dst;
  undefined2 uVar12;
  SERCX2SYSTEMDMATRANSMIT__ *local_148;
  undefined8 local_140;
  undefined8 local_138;
  ulonglong uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined *local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_88 [5];
  int local_74;
  
  _Dst = (SERCX2SYSTEMDMATRANSMIT__ *)local_88;
  local_e8 = (undefined *)0x0;
  local_148 = (SERCX2SYSTEMDMATRANSMIT__ *)0x0;
  local_118 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  memset(&local_d8,0,0x50);
  local_140 = 0;
  memset(_Dst,0,0x58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x5c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar8 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    iVar7 = -0x3ffffe7c;
    goto LAB_1c00145a8;
  }
  lVar2 = *(longlong *)(lVar8 + 200);
  uVar3 = *(undefined8 *)(lVar2 + 0x410);
  if (*(longlong *)(lVar2 + 0x18) == 0) {
    pcVar11 = "SerCx2SystemDmaTransmitCreate cannot be called unless Pio Transmit has been created";
LAB_1c001463d:
    Verifier_DbgBreak(pcVar11,1);
    iVar7 = -0x3ffffff0;
  }
  else {
    if ((*(longlong *)(lVar2 + 0x28) != 0) ||
       (*(longlong *)(*(longlong *)(lVar8 + 0xd0) + 0x28) != 0)) {
      pcVar11 = "SystemDma / Custom are exclusive modes, cannot create both";
      goto LAB_1c001463d;
    }
    if (*(longlong *)(lVar2 + 0x20) != 0) {
      pcVar11 = "SerCx2SystemDmaTransmitCreate called more than once";
      goto LAB_1c001463d;
    }
    if (param_3[0x3c] == (_SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG)0x0) {
LAB_1c001469e:
      uVar1 = *(uint *)(param_3 + 0x38);
      if ((uVar1 != 0) && ((uVar1 & uVar1 - 1) != 0)) {
        pcVar11 = "MinimumTransferUnitOverride must be a power of 2";
        goto LAB_1c00146bc;
      }
      if (*(longlong *)(param_3 + 0x58) == 0) {
        if ((*(longlong *)(param_3 + 0x60) == 0) && (*(longlong *)(param_3 + 0x68) == 0))
        goto LAB_1c0014735;
LAB_1c00146e2:
        iVar7 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(uVar3,2,5,0x5d,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
        }
        Verifier_DbgBreak("Missing data purge/drain callback",0);
      }
      else {
        if ((*(longlong *)(param_3 + 0x60) == 0) || (*(longlong *)(param_3 + 0x68) == 0))
        goto LAB_1c00146e2;
LAB_1c0014735:
        local_e8 = PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90;
        uStack_104 = 0;
        uStack_114 = 0;
        uStack_110 = 0;
        uStack_10c = 0;
        local_108 = 0;
        uStack_f0 = 0;
        local_118 = 0x38;
        uStack_100 = 0x100000001;
        local_f8 = *(undefined8 *)(*(longlong *)(lVar8 + 200) + 8);
        local_d0 = *(undefined8 *)(param_3 + 8);
        local_d8 = 0x50;
        local_d4 = 7;
        iVar7 = (**(code **)(WdfFunctions_01015 + 0x2f0))
                          (WdfDriverGlobals,param_2,&local_d8,&local_118,&local_148);
        if (iVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x5e;
LAB_1c00147db:
            WPP_RECORDER_SF_d(uVar3,2,5,uVar12,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                              (char)iVar7);
          }
        }
        else {
          if (*(int *)(param_3 + 0x1c) != 0) {
            (**(code **)(WdfFunctions_01015 + 0x308))
                      (WdfDriverGlobals,local_148,*(int *)(param_3 + 0x1c));
          }
          local_128 = *(undefined8 *)(param_3 + 0x28);
          uStack_120 = *(undefined8 *)(param_3 + 0x30);
          local_138 = 0x20;
          uStack_130 = (ulonglong)*(uint *)(param_3 + 0x20);
          iVar7 = (**(code **)(WdfFunctions_01015 + 0xca8))(WdfDriverGlobals,local_148,&local_138,1)
          ;
          if (iVar7 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x5f;
              goto LAB_1c00147db;
            }
          }
          else {
            iVar7 = (**(code **)(WdfFunctions_01015 + 0x310))
                              (WdfDriverGlobals,local_148,0,&local_140);
            if (iVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar12 = 0x60;
                goto LAB_1c00147db;
              }
            }
            else {
              puVar9 = (undefined4 *)
                       (**(code **)(WdfFunctions_01015 + 0x650))
                                 (WdfDriverGlobals,local_148,
                                  PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90);
              *puVar9 = 0x54414d44;
              *(SERCX2SYSTEMDMATRANSMIT__ **)(puVar9 + 2) = local_148;
              *(undefined8 *)(puVar9 + 4) = *(undefined8 *)(lVar8 + 200);
              *(undefined8 *)(puVar9 + 6) = local_140;
              uVar10 = (**(code **)(WdfFunctions_01015 + 0xc08))(WdfDriverGlobals,local_148,1);
              *(undefined8 *)(puVar9 + 0x24) = uVar10;
              local_88[0] = 1;
              iVar7 = (**(code **)(*(longlong *)(*(longlong *)(puVar9 + 0x24) + 8) + 0x80))();
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                goto LAB_1c00145a8;
                uVar12 = 0x61;
LAB_1c00149a5:
                WPP_RECORDER_SF_d(uVar3,2,5,uVar12,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                                  (char)iVar7);
              }
              else {
                if (*(int *)(param_3 + 0x38) == 0) {
                  puVar9[0x26] = local_74;
                  if (local_74 == 0) {
                    puVar9[0x26] = 1;
                  }
                }
                else {
                  puVar9[0x26] = *(int *)(param_3 + 0x38);
                  if ((param_3[0x3c] != (_SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG)0x0) && (local_74 != 1))
                  {
                    _Dst = (SERCX2SYSTEMDMATRANSMIT__ *)0x1;
                    Verifier_DbgBreak("Exclusive mode specified, but Dma Adapter does not support MTU value of 1"
                                      ,1);
                  }
                }
                uVar10 = *(undefined8 *)(param_3 + 8);
                *(undefined8 *)(puVar9 + 8) = *(undefined8 *)param_3;
                *(undefined8 *)(puVar9 + 10) = uVar10;
                uVar10 = *(undefined8 *)(param_3 + 0x18);
                *(undefined8 *)(puVar9 + 0xc) = *(undefined8 *)(param_3 + 0x10);
                *(undefined8 *)(puVar9 + 0xe) = uVar10;
                uVar10 = *(undefined8 *)(param_3 + 0x28);
                *(undefined8 *)(puVar9 + 0x10) = *(undefined8 *)(param_3 + 0x20);
                *(undefined8 *)(puVar9 + 0x12) = uVar10;
                uVar10 = *(undefined8 *)(param_3 + 0x38);
                *(undefined8 *)(puVar9 + 0x14) = *(undefined8 *)(param_3 + 0x30);
                *(undefined8 *)(puVar9 + 0x16) = uVar10;
                uVar10 = *(undefined8 *)(param_3 + 0x48);
                *(undefined8 *)(puVar9 + 0x18) = *(undefined8 *)(param_3 + 0x40);
                *(undefined8 *)(puVar9 + 0x1a) = uVar10;
                uVar10 = *(undefined8 *)(param_3 + 0x58);
                *(undefined8 *)(puVar9 + 0x1c) = *(undefined8 *)(param_3 + 0x50);
                *(undefined8 *)(puVar9 + 0x1e) = uVar10;
                uVar4 = *(undefined4 *)(param_3 + 100);
                uVar5 = *(undefined4 *)(param_3 + 0x68);
                uVar6 = *(undefined4 *)(param_3 + 0x6c);
                puVar9[0x20] = *(undefined4 *)(param_3 + 0x60);
                puVar9[0x21] = uVar4;
                puVar9[0x22] = uVar5;
                puVar9[0x23] = uVar6;
                uVar1 = puVar9[0xe];
                if (uVar1 == 0) {
                  puVar9[0xe] = puVar9[0x26];
LAB_1c0014a58:
                  if ((*(char *)(lVar8 + 0x149) != '\0') &&
                     (*(ulonglong *)(puVar9 + 0xc) = (ulonglong)*(uint *)(lVar8 + 0x144),
                     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    _Dst = (SERCX2SYSTEMDMATRANSMIT__ *)CONCAT71((int7)((ulonglong)_Dst >> 8),4);
                    WPP_RECORDER_SF_d(*(undefined8 *)(lVar8 + 0x130),4,5,0x62,
                                      &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                                      (char)*(undefined4 *)(lVar8 + 0x144));
                  }
                  if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
                     (_Dst = local_148,
                     iVar7 = (**(code **)(WdfFunctions_01015 + 0x658))
                                       (WdfDriverGlobals,local_148,param_4,0), -1 < iVar7)) {
                    *(undefined4 **)(*(longlong *)(lVar8 + 200) + 0x20) = puVar9;
                    *param_5 = local_148;
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qq(uVar3,_Dst,5,100,
                                         &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,
                                         (char)local_148,(char)puVar9);
                    }
                    goto LAB_1c00145cc;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 99;
                    goto LAB_1c00149a5;
                  }
                }
                else {
                  if ((uVar1 & uVar1 - 1) == 0) {
                    if ((uint)puVar9[0x26] <= uVar1) goto LAB_1c0014a58;
                    pcVar11 = "Alignment (if specified) must be >= MinimumTransferUnit";
                  }
                  else {
                    pcVar11 = "Alignment must be a power of 2";
                  }
                  Verifier_DbgBreak(pcVar11,1);
                  iVar7 = -0x3ffffff3;
                }
              }
            }
          }
        }
      }
    }
    else {
      if (((*(int *)(param_3 + 0x38) == 0) && (*(int *)(param_3 + 0x18) == 0)) &&
         (*(longlong *)(param_3 + 0x10) == 0)) {
        *(undefined4 *)(param_3 + 0x18) = 1;
        *(undefined4 *)(param_3 + 0x38) = 1;
        goto LAB_1c001469e;
      }
      pcVar11 = 
      "If Exclusive Flag is set, MinimumTransferUnitOverride, DmaAlignment, MinimumTransactionLength must not be specified"
      ;
LAB_1c00146bc:
      Verifier_DbgBreak(pcVar11,1);
      iVar7 = -0x3ffffff3;
    }
  }
LAB_1c00145a8:
  if (local_148 != (SERCX2SYSTEMDMATRANSMIT__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c00145cc:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x65,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return iVar7;
}



===== _SerCx2SystemDmaTransmitDrainFifoComplete @ 1c0014ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaTransmitDrainFifoComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMATRANSMIT__ * __ptr64) */

void __cdecl
_SerCx2SystemDmaTransmitDrainFifoComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMATRANSMIT__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1c,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe781f1)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1d,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2SystemDmaReceiveGetDmaEnabler @ 1c0014c80 =====

/* struct WDFDMAENABLER__ * __ptr64 __cdecl _SerCx2SystemDmaReceiveGetDmaEnabler(struct
   _WDF_DRIVER_GLOBALS * __ptr64,struct SERCX2SYSTEMDMARECEIVE__ * __ptr64) */

WDFDMAENABLER__ * __cdecl
_SerCx2SystemDmaReceiveGetDmaEnabler(_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMARECEIVE__ *param_2)

{
  return (WDFDMAENABLER__ *)param_2;
}



===== _SerCx2SystemDmaTransmitInitializeTransactionComplete @ 1c0014c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaTransmitInitializeTransactionComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMATRANSMIT__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2SystemDmaTransmitInitializeTransactionComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMATRANSMIT__ *param_2,uchar param_3)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x66,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90);
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),
             (-(uint)(param_3 != '\0') & 0x50) + 0xebe78021);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x67,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== _SerCx2SystemDmaTransmitPurgeFifoComplete @ 1c0014d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaTransmitPurgeFifoComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMATRANSMIT__ * __ptr64,unsigned long) */

void __cdecl
_SerCx2SystemDmaTransmitPurgeFifoComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMATRANSMIT__ *param_2,ulong param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffd8 = &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1e,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  puVar6 = PTR__WDF_SYSTEM_DMA_TRANSMIT_PRIVCONTEXT_TYPE_INFO_1c0023c90;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x68);
  uVar2 = *(uint *)(lVar1 + 0x20);
  if (uVar2 < param_3) {
    uVar5 = 0;
    Verifier_DbgBreak("Invalid number of bytes purged",0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(*(longlong *)(lVar3 + 0x10) + 0x410),uVar5,puVar6,0x1f,
                         in_stack_ffffffffffffffd8,(char)param_3,(char)*(undefined4 *)(lVar1 + 0x20)
                        );
    }
    uVar2 = *(uint *)(lVar1 + 0x20);
    param_3 = uVar2;
  }
  uVar4 = *(int *)(lVar1 + 0x18) - param_3;
  *(uint *)(lVar1 + 0x18) = uVar4;
  *(uint *)(lVar1 + 0x20) = uVar2 - param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(*(longlong *)(lVar3 + 0x10) + 0x410),(ulonglong)uVar4,puVar6
                        ,0x20,in_stack_ffffffffffffffd8,(char)lVar3,(char)param_3,(char)uVar4);
  }
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar3 + 0x10) + 0x78),0xebe78201)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x21,
                     &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_DD @ 1c0014f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 1c0014fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,5,5,&WPP_ec48bba28a323977bea4b7acdc3c1657_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c00150c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqdd @ 1c00151f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdd
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



===== WPP_RECORDER_SF_qqddd @ 1c001536c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqddd
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,&param_9,4,
                  &param_10,4,0);
  return;
}



===== Receive_CancelSystemDmaNewDataNotification @ 1c0015514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_CancelSystemDmaNewDataNotification(struct _RECEIVE_CONTEXT *
   __ptr64) */

uchar __cdecl Receive_CancelSystemDmaNewDataNotification(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  uchar uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x50,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined1 *)(lVar1 + 0x98) = 0;
  uVar2 = (**(code **)(lVar1 + 0x80))(*(undefined8 *)(lVar1 + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x51,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return uVar2;
}



===== Receive_CustomTransactionEnableNewDataNotification @ 1c00155d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_CustomTransactionEnableNewDataNotification(struct _RECEIVE_CONTEXT *
   __ptr64) */

void __cdecl Receive_CustomTransactionEnableNewDataNotification(_RECEIVE_CONTEXT *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8d,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  (**(code **)(*(longlong *)(param_1 + 0x30) + 0x58))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x8e,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_DidNewBytesArriveDuringSystemDma @ 1c0015680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_DidNewBytesArriveDuringSystemDma(struct _RECEIVE_CONTEXT * __ptr64)
    */

uchar __cdecl Receive_DidNewBytesArriveDuringSystemDma(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  ulong uVar3;
  uchar uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2e,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (*(int *)(lVar1 + 0x9c) == 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x368))
                      (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x18));
    *(undefined4 *)(lVar1 + 0x9c) = uVar2;
  }
  uVar3 = Receive_DmaCounter(param_1);
  if (*(char *)(lVar1 + 0x9a) == '\0') {
    if (uVar3 != 0) {
      if (*(ulong *)(lVar1 + 0x9c) == uVar3) {
        uVar4 = '\0';
        goto LAB_1c001573a;
      }
      goto LAB_1c0015721;
    }
  }
  else {
    *(undefined1 *)(lVar1 + 0x9a) = 0;
LAB_1c0015721:
    *(ulong *)(lVar1 + 0x9c) = uVar3;
  }
  uVar4 = '\x01';
LAB_1c001573a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2f,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return uVar4;
}



===== Receive_EnableSystemDmaNewDataNotification @ 1c0015790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_EnableSystemDmaNewDataNotification(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_EnableSystemDmaNewDataNotification(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined1 *)(lVar1 + 0x98) = 1;
  (**(code **)(lVar1 + 0x78))(*(undefined8 *)(lVar1 + 8));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_EvtCustomTransactionDestroy @ 1c0015850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_EvtCustomTransactionDestroy(void * __ptr64) */

void __cdecl Receive_EvtCustomTransactionDestroy(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x72,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
  if (*(longlong *)(lVar1 + 0x28) != 0) {
    IoFreeIrp();
    *(undefined8 *)(lVar1 + 0x28) = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x73,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_EvtQueueCleanup @ 1c0015940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_EvtQueueCleanup(void * __ptr64) */

void __cdecl Receive_EvtQueueCleanup(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x58,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_RECEIVE_CONTEXT_TYPE_INFO_1c0023a68);
  if ((*(longlong *)(lVar1 + 0x410) != 0) &&
     (*(longlong *)(lVar1 + 0x410) != *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x130))) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
  }
  *(undefined8 *)(*(longlong *)(lVar1 + 0x10) + 0xd0) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x59,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma @ 1c0015a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned char __cdecl Receive_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(struct
   _RECEIVE_CONTEXT * __ptr64) */

uchar __cdecl
Receive_HaveAnyBytesBeenReceivedEarlierOrDuringCurrentSystemDma(_RECEIVE_CONTEXT *param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x30,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  if ((*(int *)(*(longlong *)(param_1 + 0x68) + 0x18) == 0) &&
     (*(char *)(*(longlong *)(param_1 + 0x20) + 0x99) == '\0')) {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18);
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x350))(WdfDriverGlobals,uVar1);
    if (lVar3 == 0) {
      uVar4 = (**(code **)(WdfFunctions_01015 + 0x368))(WdfDriverGlobals,uVar1);
      uVar2 = Receive_DmaCounter(param_1);
      bVar5 = uVar4 != uVar2;
      goto LAB_1c0015b09;
    }
  }
  bVar5 = true;
LAB_1c0015b09:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x31,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return bVar5;
}



===== Receive_InitializeCustomTransaction @ 1c0015b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Receive_InitializeCustomTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_InitializeCustomTransaction(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x84,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x68);
  (**(code **)(*(longlong *)(param_1 + 0x30) + 0x40))
            (*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8),*(undefined8 *)(lVar1 + 0x10),
             *(undefined4 *)(lVar1 + 0x18),*(undefined4 *)(lVar1 + 0x24));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x85,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_InternalInitializeSystemDmaTransaction @ 1c0015c1c =====

/* void __cdecl Receive_InternalInitializeSystemDmaTransaction(struct _RECEIVE_CONTEXT * __ptr64) */

void __cdecl Receive_InternalInitializeSystemDmaTransaction(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x32,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x38) = 0;
  *(undefined2 *)(lVar1 + 0x99) = 0;
  *(undefined1 *)(lVar1 + 0x98) = 0;
  *(undefined4 *)(lVar1 + 0x9c) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x33,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== Receive_ProcessSystemDmaConfigureChannelFailure @ 1c0015ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* enum _SM_ENGINE_EVENT __cdecl Receive_ProcessSystemDmaConfigureChannelFailure(struct
   _RECEIVE_CONTEXT * __ptr64) */

_SM_ENGINE_EVENT __cdecl Receive_ProcessSystemDmaConfigureChannelFailure(_RECEIVE_CONTEXT *param_1)

{
  undefined8 uVar1;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x20) + 0x18);
  (**(code **)(WdfFunctions_01015 + 0x348))(WdfDriverGlobals,uVar1,0,local_res8);
  (**(code **)(WdfFunctions_01015 + 0x330))(WdfDriverGlobals,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return 0xebe78112;
}



===== Receive_RecordSystemDmaNewDataNotificationFired @ 1c0015dd4 =====

/* void __cdecl Receive_RecordSystemDmaNewDataNotificationFired(struct _RECEIVE_CONTEXT * __ptr64)
    */

void __cdecl Receive_RecordSystemDmaNewDataNotificationFired(_RECEIVE_CONTEXT *param_1)

{
  longlong lVar1;
  ulong uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4e,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined2 *)(lVar1 + 0x98) = 0x100;
  uVar2 = Receive_DmaCounter(param_1);
  *(ulong *)(lVar1 + 0x9c) = uVar2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4f,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2CustomReceiveCreate @ 1c0015ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2CustomReceiveCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct _SERCX2_CUSTOM_RECEIVE_CONFIG * __ptr64,struct _WDF_OBJECT_ATTRIBUTES *
   __ptr64,struct SERCX2CUSTOMRECEIVE__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2CustomReceiveCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_SERCX2_CUSTOM_RECEIVE_CONFIG *param_3,
          _WDF_OBJECT_ATTRIBUTES *param_4,SERCX2CUSTOMRECEIVE__ **param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  undefined2 uVar10;
  WDFDEVICE__ *local_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined8 uStack_b8;
  WDFDEVICE__ *local_b0;
  undefined8 uStack_a8;
  undefined *local_a0;
  undefined8 local_98 [2];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  code *local_78;
  undefined4 local_38;
  
  local_a0 = (undefined *)0x0;
  local_d8 = (WDFDEVICE__ *)0x0;
  local_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  uStack_c4 = 0;
  local_c0 = 0;
  uStack_bc = 0;
  uStack_b8 = 0;
  local_b0 = (WDFDEVICE__ *)0x0;
  uStack_a8 = 0;
  memset(&local_88,0,0x60);
  local_98[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x6b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar5 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    iVar4 = -0x3ffffe7c;
    goto LAB_1c0016282;
  }
  lVar1 = *(longlong *)(lVar5 + 0xd0);
  uVar2 = *(undefined8 *)(lVar1 + 0x410);
  if (*(longlong *)(lVar1 + 0x18) == 0) {
    pcVar8 = "SerCx2CustomReceiveCreate cannot be called unless Pio Receive has been created";
LAB_1c0015fa4:
    Verifier_DbgBreak(pcVar8,1);
    iVar4 = -0x3ffffff0;
  }
  else {
    if ((*(longlong *)(*(longlong *)(lVar5 + 200) + 0x20) != 0) ||
       (*(longlong *)(lVar1 + 0x20) != 0)) {
      pcVar8 = "SystemDma / Custom are exclusive modes, cannot create both";
      goto LAB_1c0015fa4;
    }
    if (*(longlong *)(lVar1 + 0x28) != 0) {
      pcVar8 = "SerCx2CustomReceiveCreate called more than once";
      goto LAB_1c0015fa4;
    }
    if (param_3[0x14] != (_SERCX2_CUSTOM_RECEIVE_CONFIG)0x0) {
      if (((*(int *)(param_3 + 0x10) == 0) && (*(int *)(param_3 + 4) == 0)) &&
         (*(int *)(param_3 + 8) == 0)) {
        *(undefined4 *)(param_3 + 4) = 1;
        uVar9 = 1;
        *(undefined4 *)(param_3 + 0x10) = 1;
        goto LAB_1c0016021;
      }
      pcVar8 = 
      "If Exclusive Flag is set, MinimumTransferUnit, MinimumTransactionLength, Alignment must not be specified"
      ;
      goto LAB_1c001600d;
    }
    uVar9 = *(uint *)(param_3 + 4);
LAB_1c0016021:
    if (*(int *)(param_3 + 0xc) == 0) {
      *(undefined4 *)(param_3 + 0xc) = 0xffffffff;
    }
    if (*(int *)(param_3 + 8) == 0) {
      *(undefined4 *)(param_3 + 8) = 1;
    }
    uVar7 = *(uint *)(param_3 + 0x10);
    if (uVar7 == 0) {
      *(undefined4 *)(param_3 + 0x10) = 1;
      uVar7 = 1;
    }
    if (uVar9 == 0) {
      *(uint *)(param_3 + 4) = uVar7;
      uVar9 = uVar7;
      if (uVar7 != 0) goto LAB_1c001604d;
LAB_1c0016054:
      pcVar8 = "MinimumTransferUnit must be a power of 2";
LAB_1c001600d:
      Verifier_DbgBreak(pcVar8,1);
      iVar4 = -0x3ffffff3;
    }
    else {
LAB_1c001604d:
      if ((uVar7 & uVar7 - 1) != 0) goto LAB_1c0016054;
      if ((uVar9 == 0) || ((uVar9 & uVar9 - 1) != 0)) {
        pcVar8 = "Alignment must be a power of 2";
        goto LAB_1c001600d;
      }
      if (uVar9 < uVar7) {
        pcVar8 = "Alignment (if specified) must be >= MinimumTransferUnit";
        goto LAB_1c001600d;
      }
      local_a0 = PTR__WDF_CUSTOM_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b80;
      uStack_bc = 0;
      uStack_cc = 0;
      uStack_c8 = 0;
      uStack_c4 = 0;
      local_c0 = 0;
      uStack_a8 = 0;
      local_d0 = 0x38;
      uStack_b8 = 0x100000001;
      local_b0 = *(WDFDEVICE__ **)(*(longlong *)(lVar5 + 0xd0) + 8);
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_d0,&local_d8);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(uVar2,2,7,0x6c,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                            (char)iVar4);
        }
      }
      else {
        puVar6 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_d8,
                            PTR__WDF_CUSTOM_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b80);
        *puVar6 = 0x52737543;
        *(WDFDEVICE__ **)(puVar6 + 2) = local_d8;
        *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(lVar5 + 0xd0);
        uVar3 = *(undefined8 *)(param_3 + 8);
        *(undefined8 *)(puVar6 + 8) = *(undefined8 *)param_3;
        *(undefined8 *)(puVar6 + 10) = uVar3;
        *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(param_3 + 0x10);
        if ((*(char *)(lVar5 + 0x148) != '\0') &&
           (puVar6[10] = *(undefined4 *)(lVar5 + 0x140),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 0x130),4,7,0x6d,
                            &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                            (char)*(undefined4 *)(lVar5 + 0x140));
        }
        local_38 = 0xffffffff;
        local_80 = 0;
        local_88 = 0x60;
        local_a0 = (undefined *)0x0;
        local_c0 = 0;
        uStack_bc = 0;
        uStack_a8 = 0;
        local_b0 = local_d8;
        local_78 = Receive_EvtCustomIoDefault;
        uStack_cc = 0;
        uStack_c8 = 0;
        uStack_c4 = 0;
        local_d0 = 0x38;
        uStack_b8 = 0x100000001;
        local_84 = 2;
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,param_2,&local_88,&local_d0,local_98);
        if (-1 < iVar4) {
          *(undefined8 *)(puVar6 + 4) = local_98[0];
          if (param_4 != (_WDF_OBJECT_ATTRIBUTES *)0x0) {
            param_2 = local_d8;
            iVar4 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,local_d8,param_4,0);
            if (iVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar10 = 0x6f;
                goto LAB_1c001625f;
              }
              goto LAB_1c0016282;
            }
          }
          *(undefined4 **)(*(longlong *)(lVar5 + 0xd0) + 0x28) = puVar6;
          *param_5 = (SERCX2CUSTOMRECEIVE__ *)local_d8;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qq(uVar2,param_2,7,0x70,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids
                               ,(char)local_d8,(char)puVar6);
          }
          goto LAB_1c00162a6;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x6e;
LAB_1c001625f:
          WPP_RECORDER_SF_d(uVar2,2,7,uVar10,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                            (char)iVar4);
        }
      }
    }
  }
LAB_1c0016282:
  if (local_d8 != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c00162a6:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x71,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return iVar4;
}



===== _SerCx2CustomReceiveTransactionCreate @ 1c00163c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2CustomReceiveTransactionCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   SERCX2CUSTOMRECEIVE__ * __ptr64,struct _SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG * __ptr64,struct
   _WDF_OBJECT_ATTRIBUTES * __ptr64,struct SERCX2CUSTOMRECEIVETRANSACTION__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2CustomReceiveTransactionCreate
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMRECEIVE__ *param_2,
          _SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG *param_3,_WDF_OBJECT_ATTRIBUTES *param_4,
          SERCX2CUSTOMRECEIVETRANSACTION__ **param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined4 *puVar10;
  SERCX2CUSTOMRECEIVE__ *pSVar11;
  undefined2 uVar12;
  SERCX2CUSTOMRECEIVE__ *local_88;
  SERCX2CUSTOMRECEIVE__ *local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 uStack_60;
  SERCX2CUSTOMRECEIVE__ *local_58;
  undefined8 uStack_50;
  undefined *local_48;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  
  local_48 = (undefined *)0x0;
  local_88 = (SERCX2CUSTOMRECEIVE__ *)0x0;
  local_80 = (SERCX2CUSTOMRECEIVE__ *)0x0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_58 = (SERCX2CUSTOMRECEIVE__ *)0x0;
  uStack_50 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x74,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  local_38 = (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,
                        PTR__WDF_CUSTOM_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b80);
  lVar1 = *(longlong *)(local_38 + 0x18);
  local_30 = *(longlong *)(lVar1 + 0x10);
  uVar2 = *(undefined8 *)(lVar1 + 0x410);
  local_40 = (**(code **)(WdfFunctions_01015 + 0xf8))
                       (WdfDriverGlobals,*(undefined8 *)(local_30 + 0x10));
  if (*(longlong *)(lVar1 + 0x30) == 0) {
    iVar7 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x10));
    if ((-1 < iVar7) && (iVar7 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x28)), -1 < iVar7)) {
      local_48 = PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18;
      local_68 = 0xc0015850;
      uStack_64 = 1;
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_50 = 0;
      local_78 = 0x38;
      uStack_60 = 0x100000001;
      local_58 = param_2;
      iVar7 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_78,&local_88);
      if (iVar7 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(uVar2,2,7,0x75,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                            (char)iVar7);
        }
      }
      else {
        puVar8 = (undefined4 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_88,
                            PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
        *puVar8 = 0x78527543;
        *(SERCX2CUSTOMRECEIVE__ **)(puVar8 + 2) = local_88;
        *(longlong *)(puVar8 + 6) = local_40;
        *(longlong *)(puVar8 + 0xc) = lVar1;
        *(longlong *)(puVar8 + 4) = local_38;
        uVar6 = *(undefined8 *)(param_3 + 8);
        *(undefined8 *)(puVar8 + 0xe) = *(undefined8 *)param_3;
        *(undefined8 *)(puVar8 + 0x10) = uVar6;
        uVar3 = *(undefined4 *)(param_3 + 0x14);
        uVar4 = *(undefined4 *)(param_3 + 0x18);
        uVar5 = *(undefined4 *)(param_3 + 0x1c);
        puVar8[0x12] = *(undefined4 *)(param_3 + 0x10);
        puVar8[0x13] = uVar3;
        puVar8[0x14] = uVar4;
        puVar8[0x15] = uVar5;
        uVar3 = *(undefined4 *)(param_3 + 0x24);
        uVar4 = *(undefined4 *)(param_3 + 0x28);
        uVar5 = *(undefined4 *)(param_3 + 0x2c);
        puVar8[0x16] = *(undefined4 *)(param_3 + 0x20);
        puVar8[0x17] = uVar3;
        puVar8[0x18] = uVar4;
        puVar8[0x19] = uVar5;
        lVar9 = IoAllocateIrp(*(char *)(local_40 + 0x4c) + '\x01',0);
        if (lVar9 == 0) {
          iVar7 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(uVar2,2,7,0x76,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
          }
        }
        else {
          *(longlong *)(puVar8 + 10) = lVar9;
          local_48 = PTR__WDF_CUSTOM_RECEIVE_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023c40;
          local_58 = local_88;
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 0;
          local_68 = 0;
          uStack_64 = 0;
          uStack_50 = 0;
          local_78 = 0x38;
          uStack_60 = 0x100000001;
          iVar7 = (**(code **)(WdfFunctions_01015 + 0x7b8))(WdfDriverGlobals,&local_78,0,&local_80);
          if (iVar7 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x77;
LAB_1c00166fb:
              WPP_RECORDER_SF_d(uVar2,2,7,uVar12,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                                (char)iVar7);
            }
          }
          else {
            pSVar11 = local_80;
            puVar10 = (undefined4 *)
                      (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,local_80,
                                 PTR__WDF_CUSTOM_RECEIVE_REQUEST_PRIVCONTEXT_TYPE_INFO_1c0023c40);
            *puVar10 = 0x63727543;
            *(undefined4 **)(puVar10 + 2) = puVar8;
            if ((*(longlong *)(local_30 + 0x70) == 0) ||
               (pSVar11 = local_80,
               iVar7 = (**(code **)(WdfFunctions_01015 + 0x658))
                                 (WdfDriverGlobals,local_80,*(longlong *)(local_30 + 0x70),0),
               -1 < iVar7)) {
              *(SERCX2CUSTOMRECEIVE__ **)(puVar8 + 8) = local_80;
              if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
                 (pSVar11 = local_88,
                 iVar7 = (**(code **)(WdfFunctions_01015 + 0x658))
                                   (WdfDriverGlobals,local_88,param_4,0), -1 < iVar7)) {
                *(undefined4 **)(lVar1 + 0x30) = puVar8;
                *param_5 = (SERCX2CUSTOMRECEIVETRANSACTION__ *)local_88;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qq(uVar2,pSVar11,7,0x7a,
                                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)local_88
                                     ,(char)puVar8);
                }
                goto LAB_1c001684f;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar12 = 0x79;
                goto LAB_1c00166fb;
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x78;
              goto LAB_1c00166fb;
            }
          }
        }
      }
    }
  }
  else {
    Verifier_DbgBreak("SerCx2CustomReceiveTransactionCreate called more than once",1);
    iVar7 = -0x3ffffff0;
  }
  if (local_88 != (SERCX2CUSTOMRECEIVE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c001684f:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x7b,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return iVar7;
}



===== _SerCx2CustomReceiveTransactionInitializeComplete @ 1c00168b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomReceiveTransactionInitializeComplete(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMRECEIVETRANSACTION__ * __ptr64,unsigned char) */

void __cdecl
_SerCx2CustomReceiveTransactionInitializeComplete
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMRECEIVETRANSACTION__ *param_2,uchar param_3)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x7c,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
  StateMachineEngine_EventAdd
            ((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),
             (-(uint)(param_3 != '\0') & 0x50) + 0xebe78021);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x7d,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2CustomReceiveTransactionNewDataNotification @ 1c00169a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CustomReceiveTransactionNewDataNotification(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2CUSTOMRECEIVETRANSACTION__ * __ptr64) */

void __cdecl
_SerCx2CustomReceiveTransactionNewDataNotification
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2CUSTOMRECEIVETRANSACTION__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x80,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_CUSTOM_RECEIVE_TRANSACTION_PRIVCONTEXT_TYPE_INFO_1c0023c18);
  *(undefined1 *)(lVar1 + 0x68) = 1;
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x30) + 0x78),0xebe782d0)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x81,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== _SerCx2PioReceiveCreate @ 1c0016a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2PioReceiveCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct _SERCX2_PIO_RECEIVE_CONFIG * __ptr64,struct _WDF_OBJECT_ATTRIBUTES *
   __ptr64,struct SERCX2PIORECEIVE__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2PioReceiveCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_SERCX2_PIO_RECEIVE_CONFIG *param_3,
          _WDF_OBJECT_ATTRIBUTES *param_4,SERCX2PIORECEIVE__ **param_5)

{
  RECORDER_LOG__ *pRVar1;
  long lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  SERCX2PIORECEIVE__ *pSVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  SERCX2PIORECEIVE__ *local_78;
  _SERCX_RING_BUFFER_PRIVCONTEXT *local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  local_38 = (undefined *)0x0;
  local_78 = (SERCX2PIORECEIVE__ *)0x0;
  local_70 = (_SERCX_RING_BUFFER_PRIVCONTEXT *)0x0;
  local_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  local_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,10,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar3 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    lVar2 = -0x3ffffe7c;
  }
  else {
    pRVar1 = *(RECORDER_LOG__ **)(*(longlong *)(lVar3 + 0xd0) + 0x410);
    if (*(longlong *)(*(longlong *)(lVar3 + 0xd0) + 0x18) == 0) {
      lVar2 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x18));
      if (((-1 < lVar2) && (lVar2 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x20)), -1 < lVar2))
         && (lVar2 = Verifier_VerifyNotNull(*(void **)(param_3 + 0x28)), -1 < lVar2)) {
        local_38 = PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68;
        uStack_54 = 0;
        uStack_64 = 0;
        uStack_60 = 0;
        uStack_5c = 0;
        local_58 = 0;
        uStack_40 = 0;
        local_68 = 0x38;
        uStack_50 = 0x100000001;
        local_48 = *(undefined8 *)(*(longlong *)(lVar3 + 0xd0) + 8);
        lVar2 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_68,&local_78);
        if (lVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(pRVar1,2,7,0xb,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                              (char)lVar2);
          }
        }
        else {
          pSVar5 = local_78;
          puVar4 = (undefined4 *)
                   (**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_78,
                              PTR__WDF_PIORECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023c68);
          *puVar4 = 0x526f6950;
          *(SERCX2PIORECEIVE__ **)(puVar4 + 2) = local_78;
          *(undefined8 *)(puVar4 + 4) = *(undefined8 *)(lVar3 + 0xd0);
          uVar6 = *(undefined8 *)(param_3 + 8);
          *(undefined8 *)(puVar4 + 6) = *(undefined8 *)param_3;
          *(undefined8 *)(puVar4 + 8) = uVar6;
          uVar6 = *(undefined8 *)(param_3 + 0x18);
          *(undefined8 *)(puVar4 + 10) = *(undefined8 *)(param_3 + 0x10);
          *(undefined8 *)(puVar4 + 0xc) = uVar6;
          uVar6 = *(undefined8 *)(param_3 + 0x28);
          *(undefined8 *)(puVar4 + 0xe) = *(undefined8 *)(param_3 + 0x20);
          *(undefined8 *)(puVar4 + 0x10) = uVar6;
          lVar2 = RingBuffer_Create(local_78,(ulong)pSVar5,pRVar1,&local_70);
          if (lVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0xc;
LAB_1c0016d16:
              WPP_RECORDER_SF_d(pRVar1,2,7,uVar7,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                                (char)lVar2);
            }
          }
          else {
            *(_SERCX_RING_BUFFER_PRIVCONTEXT **)(puVar4 + 0x12) = local_70;
            *(undefined1 *)(puVar4 + 0x14) = 0;
            KeInitializeEvent(puVar4 + 0x16,0,0);
            if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
               (lVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                                  (WdfDriverGlobals,local_78,param_4,0), -1 < lVar2)) {
              *(undefined4 **)(*(longlong *)(lVar3 + 0xd0) + 0x18) = puVar4;
              *param_5 = local_78;
              uVar6 = *(undefined8 *)(*(longlong *)(lVar3 + 0xd0) + 8);
              (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qq(pRVar1,uVar6,7,0xe,
                                   &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,(char)local_78,
                                   (char)puVar4);
              }
              goto LAB_1c0016e2a;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0xd;
              goto LAB_1c0016d16;
            }
          }
        }
      }
    }
    else {
      Verifier_DbgBreak("SerCx2PioReceiveCreate called more than once",1);
      lVar2 = -0x3ffffff0;
    }
  }
  if (local_78 != (SERCX2PIORECEIVE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c0016e2a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0xf,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return lVar2;
}



===== _SerCx2SystemDmaReceiveCreate @ 1c0016e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl _SerCx2SystemDmaReceiveCreate(struct _WDF_DRIVER_GLOBALS * __ptr64,struct
   WDFDEVICE__ * __ptr64,struct _SERCX2_SYSTEM_DMA_RECEIVE_CONFIG * __ptr64,struct
   _WDF_OBJECT_ATTRIBUTES * __ptr64,struct SERCX2SYSTEMDMARECEIVE__ * __ptr64 * __ptr64) */

long __cdecl
_SerCx2SystemDmaReceiveCreate
          (_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,
          _SERCX2_SYSTEM_DMA_RECEIVE_CONFIG *param_3,_WDF_OBJECT_ATTRIBUTES *param_4,
          SERCX2SYSTEMDMARECEIVE__ **param_5)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  char *pcVar8;
  SERCX2SYSTEMDMARECEIVE__ *_Dst;
  undefined2 uVar9;
  SERCX2SYSTEMDMARECEIVE__ *local_148;
  undefined8 local_140;
  undefined8 local_138;
  ulonglong uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined *local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_88 [5];
  int local_74;
  
  _Dst = (SERCX2SYSTEMDMARECEIVE__ *)local_88;
  local_e8 = (undefined *)0x0;
  local_148 = (SERCX2SYSTEMDMARECEIVE__ *)0x0;
  local_118 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  memset(&local_d8,0,0x50);
  local_140 = 0;
  memset(_Dst,0,0x58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x5a,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (lVar5 == 0) {
    Verifier_DbgBreak("The Controller driver either forgot to call SerCx2InitializeDevice, or forgot to check the return status of it"
                      ,1);
    iVar4 = -0x3ffffe7c;
    goto LAB_1c0016f97;
  }
  lVar2 = *(longlong *)(lVar5 + 0xd0);
  uVar3 = *(undefined8 *)(lVar2 + 0x410);
  if (*(longlong *)(lVar2 + 0x18) == 0) {
    pcVar8 = "SerCx2SystemDmaReceiveCreate cannot be called unless Pio Receive has been created";
LAB_1c001702b:
    Verifier_DbgBreak(pcVar8,1);
    iVar4 = -0x3ffffff0;
  }
  else {
    if ((*(longlong *)(*(longlong *)(lVar5 + 200) + 0x28) != 0) ||
       (*(longlong *)(lVar2 + 0x28) != 0)) {
      pcVar8 = "SystemDma / Custom are exclusive modes, cannot create both";
      goto LAB_1c001702b;
    }
    if (*(longlong *)(lVar2 + 0x20) != 0) {
      pcVar8 = "SerCx2SystemDmaReceiveCreate called more than once";
      goto LAB_1c001702b;
    }
    if (param_3[0x3c] == (_SERCX2_SYSTEM_DMA_RECEIVE_CONFIG)0x0) {
LAB_1c001708c:
      uVar1 = *(uint *)(param_3 + 0x38);
      if ((uVar1 != 0) && ((uVar1 & uVar1 - 1) != 0)) {
        pcVar8 = "MinimumTransferUnitOverride must be a power of 2";
        goto LAB_1c00170aa;
      }
      if (*(longlong *)(param_3 + 0x58) == 0) {
        if (*(longlong *)(param_3 + 0x60) != 0) {
LAB_1c00170d1:
          Verifier_DbgBreak("EvtSerCx2SystemDmaReceiveEnableNewDataNotification & EvtSerCx2SystemDmaReceiveCancelNewDataNotification both must be NULL or Non NULL"
                            ,1);
        }
      }
      else if (*(longlong *)(param_3 + 0x60) == 0) goto LAB_1c00170d1;
      local_e8 = PTR__WDF_SYSTEM_DMA_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b08;
      uStack_104 = 0;
      uStack_114 = 0;
      uStack_110 = 0;
      uStack_10c = 0;
      local_108 = 0;
      uStack_f0 = 0;
      local_118 = 0x38;
      uStack_100 = 0x100000001;
      local_f8 = *(undefined8 *)(*(longlong *)(lVar5 + 0xd0) + 8);
      local_d0 = *(undefined8 *)(param_3 + 8);
      local_d8 = 0x50;
      local_d4 = 7;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x2f0))
                        (WdfDriverGlobals,param_2,&local_d8,&local_118,&local_148);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x5b;
LAB_1c0017185:
          WPP_RECORDER_SF_d(uVar3,2,7,uVar9,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                            (char)iVar4);
        }
      }
      else {
        if (*(int *)(param_3 + 0x1c) != 0) {
          (**(code **)(WdfFunctions_01015 + 0x308))
                    (WdfDriverGlobals,local_148,*(int *)(param_3 + 0x1c));
        }
        local_128 = *(undefined8 *)(param_3 + 0x28);
        uStack_120 = *(undefined8 *)(param_3 + 0x30);
        local_138 = 0x20;
        uStack_130 = (ulonglong)*(uint *)(param_3 + 0x20);
        iVar4 = (**(code **)(WdfFunctions_01015 + 0xca8))(WdfDriverGlobals,local_148,&local_138,0);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x5c;
            goto LAB_1c0017185;
          }
        }
        else {
          iVar4 = (**(code **)(WdfFunctions_01015 + 0x310))(WdfDriverGlobals,local_148,0,&local_140)
          ;
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar9 = 0x5d;
              goto LAB_1c0017185;
            }
          }
          else {
            puVar6 = (undefined4 *)
                     (**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_148,
                                PTR__WDF_SYSTEM_DMA_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b08);
            *puVar6 = 0x52414d44;
            *(SERCX2SYSTEMDMARECEIVE__ **)(puVar6 + 2) = local_148;
            *(undefined8 *)(puVar6 + 4) = *(undefined8 *)(lVar5 + 0xd0);
            *(undefined8 *)(puVar6 + 6) = local_140;
            uVar7 = (**(code **)(WdfFunctions_01015 + 0xc08))(WdfDriverGlobals,local_148,0);
            *(undefined8 *)(puVar6 + 0x22) = uVar7;
            local_88[0] = 1;
            iVar4 = (**(code **)(*(longlong *)(*(longlong *)(puVar6 + 0x22) + 8) + 0x80))();
            if (iVar4 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0016f97;
              uVar9 = 0x5e;
LAB_1c001734f:
              WPP_RECORDER_SF_d(uVar3,2,7,uVar9,&WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                                (char)iVar4);
            }
            else {
              if (*(int *)(param_3 + 0x38) == 0) {
                puVar6[0x24] = local_74;
                if (local_74 == 0) {
                  puVar6[0x24] = 1;
                }
              }
              else {
                puVar6[0x24] = *(int *)(param_3 + 0x38);
                if ((param_3[0x3c] != (_SERCX2_SYSTEM_DMA_RECEIVE_CONFIG)0x0) && (local_74 != 1)) {
                  _Dst = (SERCX2SYSTEMDMARECEIVE__ *)0x1;
                  Verifier_DbgBreak("Exclusive mode specified, but Dma Adapter does not support MTU value of 1"
                                    ,1);
                }
              }
              uVar7 = *(undefined8 *)(param_3 + 8);
              *(undefined8 *)(puVar6 + 8) = *(undefined8 *)param_3;
              *(undefined8 *)(puVar6 + 10) = uVar7;
              uVar7 = *(undefined8 *)(param_3 + 0x18);
              *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(param_3 + 0x10);
              *(undefined8 *)(puVar6 + 0xe) = uVar7;
              uVar7 = *(undefined8 *)(param_3 + 0x28);
              *(undefined8 *)(puVar6 + 0x10) = *(undefined8 *)(param_3 + 0x20);
              *(undefined8 *)(puVar6 + 0x12) = uVar7;
              uVar7 = *(undefined8 *)(param_3 + 0x38);
              *(undefined8 *)(puVar6 + 0x14) = *(undefined8 *)(param_3 + 0x30);
              *(undefined8 *)(puVar6 + 0x16) = uVar7;
              uVar7 = *(undefined8 *)(param_3 + 0x48);
              *(undefined8 *)(puVar6 + 0x18) = *(undefined8 *)(param_3 + 0x40);
              *(undefined8 *)(puVar6 + 0x1a) = uVar7;
              uVar7 = *(undefined8 *)(param_3 + 0x58);
              *(undefined8 *)(puVar6 + 0x1c) = *(undefined8 *)(param_3 + 0x50);
              *(undefined8 *)(puVar6 + 0x1e) = uVar7;
              *(undefined8 *)(puVar6 + 0x20) = *(undefined8 *)(param_3 + 0x60);
              uVar1 = puVar6[0xe];
              if (uVar1 == 0) {
                puVar6[0xe] = puVar6[0x24];
LAB_1c0017404:
                if ((*(char *)(lVar5 + 0x148) != '\0') &&
                   (*(ulonglong *)(puVar6 + 0xc) = (ulonglong)*(uint *)(lVar5 + 0x140),
                   (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  _Dst = (SERCX2SYSTEMDMARECEIVE__ *)CONCAT71((int7)((ulonglong)_Dst >> 8),4);
                  WPP_RECORDER_SF_d(*(undefined8 *)(lVar5 + 0x130),4,7,0x5f,
                                    &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                                    (char)*(undefined4 *)(lVar5 + 0x140));
                }
                if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
                   (_Dst = local_148,
                   iVar4 = (**(code **)(WdfFunctions_01015 + 0x658))
                                     (WdfDriverGlobals,local_148,param_4,0), -1 < iVar4)) {
                  *(undefined4 **)(*(longlong *)(lVar5 + 0xd0) + 0x20) = puVar6;
                  *param_5 = local_148;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_qq(uVar3,_Dst,7,0x61,
                                       &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids,
                                       (char)local_148,(char)puVar6);
                  }
                  goto LAB_1c0016fbb;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar9 = 0x60;
                  goto LAB_1c001734f;
                }
              }
              else {
                if ((uVar1 & uVar1 - 1) == 0) {
                  if ((uint)puVar6[0x24] <= uVar1) goto LAB_1c0017404;
                  pcVar8 = "Alignment (if specified) must be >= MinimumTransferUnit";
                }
                else {
                  pcVar8 = "Alignment must be a power of 2";
                }
                Verifier_DbgBreak(pcVar8,1);
                iVar4 = -0x3ffffff3;
              }
            }
          }
        }
      }
    }
    else {
      if (((*(int *)(param_3 + 0x38) == 0) && (*(int *)(param_3 + 0x18) == 0)) &&
         (*(longlong *)(param_3 + 0x10) == 0)) {
        *(undefined4 *)(param_3 + 0x18) = 1;
        *(undefined4 *)(param_3 + 0x38) = 1;
        goto LAB_1c001708c;
      }
      pcVar8 = 
      "If Exclusive Flag is set, MinimumTransferUnitOverride, DmaAlignment, MinimumTransactionLength must not be specified"
      ;
LAB_1c00170aa:
      Verifier_DbgBreak(pcVar8,1);
      iVar4 = -0x3ffffff3;
    }
  }
LAB_1c0016f97:
  if (local_148 != (SERCX2SYSTEMDMARECEIVE__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
LAB_1c0016fbb:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x62,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return iVar4;
}



===== _SerCx2SystemDmaReceiveNewDataNotification @ 1c0017550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2SystemDmaReceiveNewDataNotification(struct _WDF_DRIVER_GLOBALS *
   __ptr64,struct SERCX2SYSTEMDMARECEIVE__ * __ptr64) */

void __cdecl
_SerCx2SystemDmaReceiveNewDataNotification
          (_WDF_DRIVER_GLOBALS *param_1,SERCX2SYSTEMDMARECEIVE__ *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x67,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF_SYSTEM_DMA_RECEIVE_PRIVCONTEXT_TYPE_INFO_1c0023b08);
  StateMachineEngine_EventAdd((_SM_ENGINE_CONTEXT *)(*(longlong *)(lVar1 + 0x10) + 0x78),0xebe782d0)
  ;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x68,
                     &WPP_5cf92927f3a6354ed4db5ead32b2b500_Traceguids);
  }
  return;
}



===== McTemplateK0pqq_EtwWriteTransfer @ 1c0017620 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pqq_EtwWriteTransfer(void)

{
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 8;
  local_48 = local_res20;
  local_30 = 4;
  local_38 = &uStack0000000000000028;
  local_20 = 4;
  local_28 = &uStack0000000000000030;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,
             &SerCx2EtwEventReceiveIOSaveReceiveFifoOnD0Exit,0,4,local_58);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c00176a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
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



===== Ioctl_EvtIoQueuePurgeComplete @ 1c00177e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_EvtIoQueuePurgeComplete(struct WDFQUEUE__ * __ptr64,void * __ptr64) */

void __cdecl Ioctl_EvtIoQueuePurgeComplete(WDFQUEUE__ *param_1,void *param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x2b,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar2 = *(longlong *)((longlong)param_2 + 8);
  LOCK();
  piVar1 = (int *)(lVar2 + 0xd8);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    uVar5 = *(undefined8 *)(lVar2 + 0x118);
    uVar4 = *(undefined8 *)(lVar2 + 0xe0);
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qqd(*(undefined8 *)((longlong)param_2 + 0x3d8),uVar4,uVar5,0x2c,
                          in_stack_ffffffffffffffc8,(char)*(undefined8 *)(lVar2 + 0xe0),
                          (char)*(undefined8 *)(lVar2 + 0x118),(char)iVar3);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x2d,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_EvtTransmitQueueStoppedForSetBreakOn @ 1c0017900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Ioctl_EvtTransmitQueueStoppedForSetBreakOn(struct WDFQUEUE__ * __ptr64,void *
   __ptr64) */

void __cdecl Ioctl_EvtTransmitQueueStoppedForSetBreakOn(WDFQUEUE__ *param_1,void *param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4d,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_48);
  (**(code **)(lVar2 + 0x50))(uVar1,param_2,uStack_40,local_38);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4e,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_GetCommStatusComplete @ 1c0017a6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_GetCommStatusComplete(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64) */

void __cdecl Ioctl_GetCommStatusComplete(WDFDEVICE__ *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x60,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
    if (*(int *)(lVar1 + 8) == 0x14) {
      *(int *)(*(longlong *)(param_2 + 0x18) + 8) =
           *(int *)(*(longlong *)(param_2 + 0x18) + 8) +
           *(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar2 + 0xd0) + 0x18) + 0x48) + 0x1c);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),2,8,0x61,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x62,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_GetTimeouts @ 1c0017b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_GetTimeouts(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Ioctl_GetTimeouts(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  _SERCX_TIMER_PRIVCONTEXT *p_Var1;
  int iVar2;
  longlong lVar3;
  ulong *local_res20;
  
  local_res20 = (ulong *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1a,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_3 == 0x14) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x14,&local_res20,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x130),2,8,0x1c,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar2);
      }
    }
    else {
      local_res20[0] = 0;
      local_res20[1] = 0;
      local_res20[2] = 0;
      local_res20[3] = 0;
      local_res20[4] = 0;
      p_Var1 = *(_SERCX_TIMER_PRIVCONTEXT **)(*(longlong *)(lVar3 + 0xd0) + 0x70);
      Timer_GetTimeouts(*(_SERCX_TIMER_PRIVCONTEXT **)(*(longlong *)(lVar3 + 200) + 0x70),
                        (ulong *)0x0,local_res20 + 4,local_res20 + 3);
      Timer_GetTimeouts(p_Var1,local_res20,local_res20 + 2,local_res20 + 1);
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x14);
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x130),2,8,0x1b,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1d,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_GetWaitMask @ 1c0017db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_GetWaitMask(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64) */

void __cdecl Ioctl_GetWaitMask(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined4 *local_res18;
  
  local_res18 = (undefined4 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x3d,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_3 == 4) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,&local_res18,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar2 + 0x130),2,8,0x3f,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar1);
      }
    }
    else {
      *local_res18 = 0;
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x108));
      *local_res18 = *(undefined4 *)(lVar2 + 0xf0);
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x108));
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,4);
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),2,8,0x3e,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x40,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_Purge @ 1c0017fc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_Purge(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned
   __int64) */

void __cdecl Ioctl_Purge(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int local_res18 [2];
  uint *local_res20;
  undefined *puVar8;
  
  local_res20 = (uint *)0x0;
  local_res18[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x22,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  uVar7 = *(undefined8 *)(*(longlong *)(lVar4 + 0xd0) + 8);
  uVar1 = *(undefined8 *)(*(longlong *)(lVar4 + 200) + 8);
  if (param_3 == 4) {
    puVar8 = (undefined *)0x0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_res20);
    if (-1 < iVar2) {
      uVar6 = *local_res20;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        puVar8 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar4 + 0x130),4,8,0x25,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (byte)uVar6);
      }
      if (((byte)uVar6 & 10) == 8) {
        (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,uVar7,0,0);
        (**(code **)(WdfFunctions_01015 + 0x4c8))(WdfDriverGlobals,uVar7,0,local_res18);
        if (local_res18[0] != 0) {
          Verifier_DbgBreak("Client Driver Issue: Cannot Purge Fifo with pending read reqeusts, unless SERIAL_PURGE_RXABORT flag is specified"
                            ,1);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar8 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
            WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x130),4,8,0x26,
                             &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
          }
          uVar6 = uVar6 & 0xfffffff7;
          (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar7);
        }
      }
      if (((byte)uVar6 & 5) == 4) {
        (**(code **)(WdfFunctions_01015 + 0x4d8))(WdfDriverGlobals,uVar1,0,0);
        (**(code **)(WdfFunctions_01015 + 0x4c8))(WdfDriverGlobals,uVar1,0,local_res18);
        if (local_res18[0] != 0) {
          Verifier_DbgBreak("Client Driver Issue: Cannot Purge Fifo with pending write reqeusts, unless SERIAL_PURGE_TXABORT flag is specified"
                            ,1);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar8 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
            WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x130),4,8,0x27,
                             &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
          }
          uVar6 = uVar6 & 0xfffffffb;
          (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,uVar1);
        }
      }
      *(undefined4 *)(lVar4 + 0xd8) = 0;
      *(byte *)(lVar4 + 0xe8) = (byte)(uVar6 >> 3) & 1;
      uVar5 = uVar6 & 2;
      *(byte *)(lVar4 + 0xe9) = (byte)(uVar6 >> 2) & 1;
      uVar6 = uVar6 & 1;
      *(bool *)(lVar4 + 0xea) = uVar5 != 0;
      *(char *)(lVar4 + 0xeb) = (char)uVar6;
      if (uVar5 != 0) {
        *(undefined4 *)(lVar4 + 0xd8) = 1;
      }
      uVar3 = (uint)(uVar5 != 0);
      if (uVar6 != 0) {
        uVar3 = uVar3 + 1;
        *(uint *)(lVar4 + 0xd8) = uVar3;
      }
      *(WDFREQUEST__ **)(lVar4 + 0xe0) = param_2;
      if (uVar3 == 0) {
        uVar7 = *(undefined8 *)(lVar4 + 0x118);
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar4 + 0x130),param_2,uVar7,0x28,puVar8,
                              (char)*(undefined8 *)(lVar4 + 0xe0),
                              (char)*(undefined8 *)(lVar4 + 0x118),(char)iVar2);
        }
      }
      else {
        if (uVar5 != 0) {
          (**(code **)(WdfFunctions_01015 + 0x528))
                    (WdfDriverGlobals,uVar7,Ioctl_EvtIoQueuePurgeComplete,
                     *(longlong *)(lVar4 + 0xd0) + 0x38);
        }
        if (uVar6 != 0) {
          (**(code **)(WdfFunctions_01015 + 0x528))
                    (WdfDriverGlobals,uVar1,Ioctl_EvtIoQueuePurgeComplete,
                     *(longlong *)(lVar4 + 200) + 0x38);
        }
      }
      goto LAB_1c0018456;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(lVar4 + 0x130),2,8,0x24,
                        &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)iVar2);
      goto LAB_1c0018115;
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x130),2,8,0x23,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
      iVar2 = -0x3ffffff3;
LAB_1c0018115:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar4 + 0x130),4,8,0x29,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar2);
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
LAB_1c0018456:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x2a,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetBreakOff @ 1c00184ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetBreakOff(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Ioctl_SetBreakOff(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  longlong lVar1;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar2;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4b,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(longlong *)(*(longlong *)(lVar1 + 200) + 0x18) == 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000184);
  }
  else {
    (**(code **)(lVar1 + 0x50))(param_1,param_2,param_3,param_4,CONCAT44(uVar2,0x1b0014));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4c,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetBreakOffComplete @ 1c00185dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetBreakOffComplete(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64) */

void __cdecl Ioctl_SetBreakOffComplete(WDFDEVICE__ *param_1,_IRP *param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,99,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
    if (*(char *)(lVar1 + 0x128) != '\0') {
      *(undefined1 *)(lVar1 + 0x128) = 0;
      (**(code **)(WdfFunctions_01015 + 0xdb8))
                (WdfDriverGlobals,param_1,0,0x68a,
                 "onecore\\drivers\\serial\\sercx2\\sercx2\\sys\\ioctl.cpp");
      (**(code **)(WdfFunctions_01015 + 0x4d0))
                (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 200) + 8));
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,100,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetBreakOn @ 1c0018724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetBreakOn(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl Ioctl_SetBreakOn(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x49,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(longlong *)(*(longlong *)(lVar1 + 200) + 0x18) != 0) {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x4c8))
                      (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 200) + 8),0,0);
    if ((uVar2 & 4) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x4d8))
                (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 200) + 8),
                 Ioctl_EvtTransmitQueueStoppedForSetBreakOn,param_2);
      goto LAB_1c0018843;
    }
    Verifier_DbgBreak("Cannot call Break On with Transmit I/O pending",1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000184);
LAB_1c0018843:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x4a,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetBreakOnComplete @ 1c0018898 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetBreakOnComplete(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64) */

void __cdecl Ioctl_SetBreakOnComplete(WDFDEVICE__ *param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar2;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar2 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x65,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(char *)(lVar1 + 0x128) == '\0') {
    if (*(int *)(param_2 + 0x30) < 0) {
      (**(code **)(WdfFunctions_01015 + 0x4d0))
                (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(lVar1 + 200) + 8));
    }
    else {
      *(undefined1 *)(lVar1 + 0x128) = 1;
      (**(code **)(WdfFunctions_01015 + 0xdb0))
                (WdfDriverGlobals,param_1,0,0,CONCAT44(uVar2,0x6be),
                 "onecore\\drivers\\serial\\sercx2\\sercx2\\sys\\ioctl.cpp");
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x66,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetIntervalTimerResolution @ 1c00189e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetIntervalTimerResolution(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64) */

void __cdecl
Ioctl_SetIntervalTimerResolution
          (WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4)

{
  int iVar1;
  longlong lVar2;
  char *local_res18;
  
  local_res18 = (char *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1e,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_4 == 1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,1,&local_res18,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar2 + 0x130),2,8,0x20,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)iVar1);
      }
    }
    else {
      iVar1 = Timer_SetIntervalTimerHighResolution
                        (*(_SERCX_TIMER_PRIVCONTEXT **)(*(longlong *)(lVar2 + 0xd0) + 0x70),
                         *local_res18 != '\0');
    }
  }
  else {
    iVar1 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),2,8,0x1f,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x21,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetWaitMask @ 1c0018b94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetWaitMask(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ *
   __ptr64,unsigned __int64) */

void __cdecl Ioctl_SetWaitMask(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  uint uVar1;
  longlong lVar2;
  code *pcVar3;
  WDFREQUEST__ *pWVar4;
  uint *local_res18;
  undefined8 uVar5;
  
  local_res18 = (uint *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x33,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_3 == 4) {
    uVar5 = 0;
    pWVar4 = param_2;
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,&local_res18);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar2 + 0x130),2,8,0x35,
                           &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)param_2,
                           (char)uVar1);
      }
    }
    else if ((*local_res18 & 0xffffe302) == 0) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x108));
      *(uint *)(lVar2 + 0xf4) = *local_res18;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x108));
      pcVar3 = *(code **)(lVar2 + 0x40);
      if (pcVar3 != (code *)0x0) {
        uVar1 = *local_res18;
        goto LAB_1c0018d90;
      }
      uVar1 = 0xc00000bb;
    }
    else {
      uVar1 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Ld(*(undefined8 *)(lVar2 + 0x130),pWVar4,8,0x36,uVar5,(char)*local_res18,0xd
                          );
      }
    }
  }
  else {
    uVar1 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x130),2,8,0x34,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
  }
  pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
  param_1 = WdfDriverGlobals;
LAB_1c0018d90:
  (*pcVar3)(param_1,param_2,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x37,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== Ioctl_SetWaitMaskComplete @ 1c0018df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_SetWaitMaskComplete(struct WDFDEVICE__ * __ptr64,struct _IRP * __ptr64) */

void __cdecl Ioctl_SetWaitMaskComplete(WDFDEVICE__ *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res10;
  undefined4 *local_res18 [2];
  
  local_res10 = 0;
  local_res18[0] = (undefined4 *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x38,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (*(int *)(param_2 + 0x30) < 0) {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x108));
    *(uint *)(lVar3 + 0xf8) = *(uint *)(lVar3 + 0xf8) & *(uint *)(lVar3 + 0xf0);
    *(undefined4 *)(lVar3 + 0xf4) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x108));
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x108));
    *(uint *)(lVar3 + 0xf8) = *(uint *)(lVar3 + 0xf8) & *(uint *)(lVar3 + 0xf4);
    *(uint *)(lVar3 + 0xf0) = *(uint *)(lVar3 + 0xf4);
    *(undefined4 *)(lVar3 + 0xf4) = 0;
    (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x108));
    puVar1 = (undefined8 *)(lVar3 + 0x130);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*puVar1,4,8,0x39,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                        (char)*(undefined4 *)(lVar3 + 0xf0));
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x100),&local_res10);
    if (iVar2 < 0) {
      if ((iVar2 != -0x7fffffe6) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qd(*puVar1,2,8,0x3a,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                           (char)*(undefined8 *)(lVar3 + 0x100),(char)iVar2);
      }
    }
    else {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,local_res10,4,local_res18,0);
      if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qd(*puVar1,2,8,0x3b,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                           (char)local_res10,(char)iVar2);
      }
      *local_res18[0] = 0;
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,local_res10,4);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*puVar1,4,8,0x3c,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                           (char)local_res10,(char)iVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res10,0);
    }
  }
  return;
}



===== Ioctl_WaitOnMask @ 1c00190b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Ioctl_WaitOnMask(struct WDFDEVICE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned
   __int64) */

void __cdecl Ioctl_WaitOnMask(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  WDFREQUEST__ *pWVar5;
  int local_res18 [2];
  int *local_res20;
  undefined *puVar6;
  undefined1 uVar7;
  
  local_res20 = (int *)0x0;
  bVar1 = false;
  local_res18[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x41,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  if (param_3 == 4) {
    (**(code **)(WdfFunctions_01015 + 0x4c8))
              (WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x100),local_res18,0);
    if (local_res18[0] == 0) {
      puVar6 = (undefined *)0x0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,4,&local_res20);
      uVar7 = SUB81(param_2,0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x130),2,8,0x44,
                             &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,uVar7,(char)iVar2);
        }
      }
      else {
        *local_res20 = 0;
        (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x108));
        if (*(int *)(lVar3 + 0xf8) != 0) {
          bVar1 = true;
          *local_res20 = *(int *)(lVar3 + 0xf8);
          *(undefined4 *)(lVar3 + 0xf8) = 0;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            puVar6 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
            WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x130),4,8,0x45,
                               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,uVar7,(char)iVar2);
          }
        }
        uVar4 = *(undefined8 *)(lVar3 + 0x108);
        (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
        if (bVar1) {
          (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,iVar2,4);
          goto LAB_1c00193ef;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          puVar6 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
          WPP_RECORDER_SF_q(*(undefined8 *)(lVar3 + 0x130),uVar4,8,0x46,
                            &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                            (char)*(undefined8 *)(lVar3 + 0x120));
        }
        *(undefined8 *)(lVar3 + 0x120) = 0;
        (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x110));
        uVar4 = *(undefined8 *)(lVar3 + 0x100);
        pWVar5 = param_2;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals);
        if (-1 < iVar2) goto LAB_1c00193ef;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar3 + 0x130),pWVar5,uVar4,0x47,puVar6,uVar7,
                              (char)*(undefined8 *)(lVar3 + 0x100),(char)iVar2);
        }
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x130),2,8,0x43,
                         &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
      }
      iVar2 = -0x3ffffe7c;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x130),2,8,0x42,
                       &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
    }
    iVar2 = -0x3ffffff3;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
LAB_1c00193ef:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x48,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== _SerCx2CompleteWait @ 1c0019440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl _SerCx2CompleteWait(struct _WDF_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ *
   __ptr64,unsigned long) */

void __cdecl _SerCx2CompleteWait(_WDF_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,ulong param_3)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  WDFDEVICE__ *pWVar7;
  undefined2 uVar8;
  undefined8 local_res20;
  undefined *in_stack_ffffffffffffff98;
  undefined4 *local_38;
  undefined8 local_30;
  
  local_38 = (undefined4 *)0x0;
  local_30 = 0;
  local_res20 = 0;
  pWVar7 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff98 = &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids;
    pWVar7 = (WDFDEVICE__ *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  bVar1 = KeGetCurrentIrql();
  if (2 < bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(0,pWVar7,4,0xc,&WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,2,0x10);
    }
    (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
    goto LAB_1c00197e5;
  }
  lVar2 = Verfier_VerifyPrivateGlobals((_SERCX_CLIENT_GLOBALS *)(param_1 + -8));
  if ((lVar2 < 0) || (lVar2 = Verifier_VerifyNotNull(param_2), lVar2 < 0)) goto LAB_1c00197e5;
  pvVar4 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_2,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
  lVar2 = Verifier_VerifyNotNull(pvVar4);
  if (lVar2 < 0) goto LAB_1c00197e5;
  if (param_3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_Ld(*(undefined8 *)((longlong)pvVar4 + 0x130),param_2,3,0xb,
                       in_stack_ffffffffffffff98,0,(char)lVar2);
    goto LAB_1c00197e5;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))
            (WdfDriverGlobals,*(undefined8 *)((longlong)pvVar4 + 0x108));
  if (((param_3 & ~*(uint *)((longlong)pvVar4 + 0xf0)) == 0) ||
     ((param_3 & ~*(uint *)((longlong)pvVar4 + 0xf4)) == 0)) {
    *(uint *)((longlong)pvVar4 + 0xf8) = *(uint *)((longlong)pvVar4 + 0xf8) | param_3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LL(*(undefined8 *)((longlong)pvVar4 + 0x130));
    }
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)((longlong)pvVar4 + 0x100),&local_res20);
    if (iVar3 == -0x7fffffe6) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)((longlong)pvVar4 + 0x130),4,3,0xe,
                          &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0);
      }
    }
    else if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = *(undefined8 *)((longlong)pvVar4 + 0x130);
        uVar8 = 0xf;
        uVar5 = *(undefined8 *)((longlong)pvVar4 + 0x100);
LAB_1c00196d2:
        WPP_RECORDER_SF_qd(uVar6,2,3,uVar8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,
                           (char)uVar5,(char)iVar3);
      }
    }
    else {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                        (WdfDriverGlobals,local_res20,4,&local_38,&local_30);
      if (-1 < iVar3) {
        *local_38 = *(undefined4 *)((longlong)pvVar4 + 0xf8);
        *(undefined4 *)((longlong)pvVar4 + 0xf8) = 0;
        (**(code **)(WdfFunctions_01015 + 0x9e8))
                  (WdfDriverGlobals,*(undefined8 *)((longlong)pvVar4 + 0x108));
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)((longlong)pvVar4 + 0x130),4,3,0x11,
                             &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,(char)local_res20,
                             (char)iVar3);
        }
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,local_res20,iVar3,4);
        goto LAB_1c00197e5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = *(undefined8 *)((longlong)pvVar4 + 0xd0);
        uVar8 = 0x10;
        uVar5 = local_res20;
        goto LAB_1c00196d2;
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_LLLd(*(undefined8 *)((longlong)pvVar4 + 0x130));
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)pvVar4 + 0x108));
LAB_1c00197e5:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x12,
                     &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_LL @ 1c0019834 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_LLLd @ 1c0019904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0xc,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0xc,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_Ld @ 1c0019a14 =====

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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,param_4,
                  &param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLd @ 1c0019b3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x5e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,0x5e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0019c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_338f66a9bb763ad85c87f9eb62eab7dd_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== File_InitFileObject @ 1c0019d44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl File_InitFileObject(struct WDFDEVICE_INIT * __ptr64,struct WDFCXDEVICE_INIT *
   __ptr64) */

long __cdecl File_InitFileObject(WDFDEVICE_INIT *param_1,WDFCXDEVICE_INIT *param_2)

{
  undefined4 local_78;
  undefined4 local_74;
  code *local_70;
  code *local_68;
  code *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_74 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1c,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,param_1,1);
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,param_1,0x1b);
  local_78 = 0x28;
  local_20 = 0;
  local_54 = 4;
  local_40 = 0;
  local_70 = File_EvtDeviceFileCreate;
  uStack_48 = 0;
  local_50 = 0x38;
  local_68 = File_EvtFileClose;
  local_60 = File_EvtFileCleanup;
  local_30 = 0;
  uStack_28 = 0;
  uStack_38 = 0x100000001;
  local_58 = 2;
  (**(code **)(WdfFunctions_01015 + 0xc80))(WdfDriverGlobals,param_2,&local_78,&local_50);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1d,
                     &WPP_2f0c136022e93545036f062fa9631a83_Traceguids);
  }
  return 0;
}



===== WPP_RECORDER_SF_qZd @ 1c0019ecc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qZd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,wchar_t *param_7,undefined1 param_8)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  
  pwVar3 = param_7;
  pwVar4 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
  goto LAB_1c0019fb8;
  if (param_7 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c0019f44:
    pwVar5 = L"NULL";
  }
  else {
    wVar1 = *param_7;
    if (*param_7 == L'\0') goto LAB_1c0019f44;
    pwVar5 = *(wchar_t **)(param_7 + 4);
  }
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_2f0c136022e93545036f062fa9631a83_Traceguids,param_4,&param_6,8,pwVar2,2,pwVar5,
             wVar1,&param_8,4,0);
LAB_1c0019fb8:
  if (pwVar3 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *pwVar3;
    if (*pwVar3 != L'\0') {
      pwVar4 = *(wchar_t **)(pwVar3 + 4);
    }
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"\b";
  }
  WppAutoLogTrace(param_1,2,9,&WPP_2f0c136022e93545036f062fa9631a83_Traceguids,param_4,&param_6,8,
                  pwVar3,2,pwVar4,wVar1,&param_8,4,0);
  return;
}



===== Timer_Create @ 1c001a060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Timer_Create(void * __ptr64,void (__cdecl*)(void * __ptr64,struct
   _SERCX_TIMER_PRIVCONTEXT * __ptr64,enum _TIMEOUT_TYPE),void * __ptr64,struct RECORDER_LOG__ *
   __ptr64,unsigned char,struct _SERCX_TIMER_PRIVCONTEXT * __ptr64 * __ptr64) */

long __cdecl
Timer_Create(void *param_1,_func_void_void_ptr__SERCX_TIMER_PRIVCONTEXT_ptr__TIMEOUT_TYPE *param_2,
            void *param_3,RECORDER_LOG__ *param_4,uchar param_5,_SERCX_TIMER_PRIVCONTEXT **param_6)

{
  int iVar1;
  _SERCX_TIMER_PRIVCONTEXT *p_Var2;
  undefined2 uVar3;
  undefined8 local_res8;
  void *local_res10;
  undefined8 local_98;
  code *pcStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  void *local_50;
  undefined8 uStack_48;
  undefined *local_40;
  
  local_res10 = (void *)0x0;
  local_res8 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,10,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  local_40 = PTR__WDF_SERCX_TIMER_PRIVCONTEXT_TYPE_INFO_1c0023d30;
  uStack_5c = 0;
  local_78 = 0;
  uStack_48 = 0;
  pcStack_90 = Timer_EvtTimerFired;
  uStack_58 = 0x100000001;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  local_70 = 0x38;
  local_98 = 0x28;
  local_88 = 0x100000000;
  uStack_80 = 0;
  local_50 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                    (WdfDriverGlobals,&local_98,&local_70,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0xb;
  }
  else {
    p_Var2 = (_SERCX_TIMER_PRIVCONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res10,
                        PTR__WDF_SERCX_TIMER_PRIVCONTEXT_TYPE_INFO_1c0023d30);
    *(undefined4 *)p_Var2 = 0x726d6954;
    *(code **)(p_Var2 + 0x50) = Transfer_TimerFired;
    *(void **)(p_Var2 + 0x58) = param_3;
    *(void **)(p_Var2 + 8) = local_res10;
    *(RECORDER_LOG__ **)(p_Var2 + 0x60) = param_4;
    if (param_5 != '\0') {
      local_40 = (undefined *)0x0;
      local_98 = 0x28;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_48 = 0;
      local_50 = local_res10;
      pcStack_90 = Timer_EvtHighResTimerFired;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      local_70 = 0x38;
      uStack_58 = 0x100000001;
      local_88 = 0x100000000;
      uStack_80 = 0;
      local_78 = 1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                        (WdfDriverGlobals,&local_98,&local_70,p_Var2 + 0x10);
      if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(param_4,2,0xd,0xc,&WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids,
                          (char)iVar1);
      }
    }
    *(undefined4 *)(p_Var2 + 0x4c) = 0xebe78372;
    local_40 = (undefined *)0x0;
    uStack_60 = 0;
    uStack_5c = 0;
    uStack_48 = 0;
    local_50 = local_res10;
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0;
    local_70 = 0x38;
    uStack_58 = 0x100000001;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_70,&local_res8);
    if (-1 < iVar1) {
      *(undefined8 *)(p_Var2 + 0x20) = local_res8;
      *param_6 = p_Var2;
      goto LAB_1c001a31a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0xd;
  }
  WPP_RECORDER_SF_d(param_4,2,0xd,uVar3,&WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids,(char)iVar1
                   );
LAB_1c001a31a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0xe,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return iVar1;
}



===== Timer_SetIntervalTimerHighResolution @ 1c001a370 =====

/* long __cdecl Timer_SetIntervalTimerHighResolution(struct _SERCX_TIMER_PRIVCONTEXT *
   __ptr64,unsigned char) */

long __cdecl Timer_SetIntervalTimerHighResolution(_SERCX_TIMER_PRIVCONTEXT *param_1,uchar param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x19,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x60),2,0xd,0x1a,
                       &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
    }
    lVar1 = -0x3fffff45;
  }
  else {
    param_1[0x34] = (_SERCX_TIMER_PRIVCONTEXT)param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_l(*(undefined8 *)(param_1 + 0x60));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xd,0x1c,
                     &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids);
  }
  return lVar1;
}



===== WPP_RECORDER_SF_l @ 1c001a470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_l(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids,0x1b,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_fc5ffe8243fc3baa6261c947d41bb26c_Traceguids,0x1b,
                  &uStack0000000000000030,4,0);
  return;
}



===== RingBuffer_Create @ 1c001a51c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RingBuffer_Create(void * __ptr64,unsigned long,struct RECORDER_LOG__ *
   __ptr64,struct _SERCX_RING_BUFFER_PRIVCONTEXT * __ptr64 * __ptr64) */

long __cdecl
RingBuffer_Create(void *param_1,ulong param_2,RECORDER_LOG__ *param_3,
                 _SERCX_RING_BUFFER_PRIVCONTEXT **param_4)

{
  int iVar1;
  _SERCX_RING_BUFFER_PRIVCONTEXT *p_Var2;
  undefined8 local_res8;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_5c;
  undefined8 uStack_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  void *local_40;
  undefined8 local_38;
  undefined *local_30;
  
  local_res8 = 0;
  local_68 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,10,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  local_4c = 0;
  local_48 = 1;
  local_44 = 1;
  local_30 = PTR__WDF_SERCX_RING_BUFFER_PRIVCONTEXT_TYPE_INFO_1c0023d58;
  local_5c = 0;
  uStack_54 = 0;
  local_38 = 0;
  local_60 = 0x38;
  local_40 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x600))
                    (WdfDriverGlobals,&local_60,0x200,0x32786353,0x400,&local_res8,&local_68);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_d(param_3,2,0xe,0xb,&WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids,(char)iVar1
                     );
  }
  else {
    p_Var2 = (_SERCX_RING_BUFFER_PRIVCONTEXT *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF_SERCX_RING_BUFFER_PRIVCONTEXT_TYPE_INFO_1c0023d58);
    *param_4 = p_Var2;
    *(undefined4 *)p_Var2 = 0x66756252;
    *(undefined8 *)(p_Var2 + 0x10) = local_68;
    *(undefined8 *)(p_Var2 + 0x18) = 0x400;
    p_Var2[0x20] = (_SERCX_RING_BUFFER_PRIVCONTEXT)0x0;
    *(undefined8 *)(p_Var2 + 8) = local_res8;
    *(RECORDER_LOG__ **)(p_Var2 + 0x28) = param_3;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xc,
                     &WPP_8b069348b17a3069fd179bd396f0cf7b_Traceguids);
  }
  return iVar1;
}



===== Verfier_VerifyPrivateGlobals @ 1c001a6d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Verfier_VerifyPrivateGlobals(struct _SERCX_CLIENT_GLOBALS * __ptr64) */

long __cdecl Verfier_VerifyPrivateGlobals(_SERCX_CLIENT_GLOBALS *param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if ((param_1 == (_SERCX_CLIENT_GLOBALS *)0x0) || (*(int *)param_1 != 0x32786353)) {
    lVar1 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(0,2,4,0xe,&WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,(char)param_1,
                         0x10);
    }
    (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
  }
  return lVar1;
}



===== Verifier_DbgBreak @ 1c001a758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Verifier_DbgBreak(char const * __ptr64,enum DBGBREAK_TYPE) */

void __cdecl Verifier_DbgBreak(char *param_1,DBGBREAK_TYPE param_2)

{
  code *pcVar1;
  char cVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s();
  }
  DbgPrint("SerCx Verifier Break: %s\n",param_1);
  if (param_2 != 0) {
    if (param_2 == 1) {
      (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
      return;
    }
    if (param_2 != 2) {
      if (param_2 != 3) {
        return;
      }
      goto LAB_1c001a7d8;
    }
  }
  cVar2 = KdRefreshDebuggerNotPresent();
  if (cVar2 != '\0') {
    return;
  }
LAB_1c001a7d8:
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== Verifier_VerifyIrqlEquals @ 1c001a7ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl Verifier_VerifyIrqlEquals(unsigned char) */

long __cdecl Verifier_VerifyIrqlEquals(uchar param_1)

{
  char cVar1;
  undefined8 in_RDX;
  long lVar2;
  
  lVar2 = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 != '\0') {
    lVar2 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_dd(0,in_RDX,4,0xd,&WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,0,0x10);
    }
    (**(code **)(WdfFunctions_01015 + 0xb78))(WdfDriverGlobals);
  }
  return lVar2;
}



===== Verifier_VerifyNotNull @ 1c001a868 =====

/* long __cdecl Verifier_VerifyNotNull(void * __ptr64) */

long __cdecl Verifier_VerifyNotNull(void *param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(0,2,4,0xb,&WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,0x10);
    }
    Verifier_DbgBreak("Null Parameter is not allowed",1);
  }
  return lVar1;
}



===== WPP_RECORDER_SF_s @ 1c001a8d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(void)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *in_stack_00000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar1 = -1;
      do {
        lVar2 = lVar1;
        lVar1 = lVar2 + 1;
      } while (in_stack_00000030[lVar1] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar3 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,10,pcVar3,lVar2,0);
  }
  lVar2 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (in_stack_00000030[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(0,2,4,&WPP_7627759baaa33404ee2b7d5a38983274_Traceguids,10,in_stack_00000030,lVar1,
                  0);
  return;
}



===== Etw_DeviceCreate @ 1c001a9dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Etw_DeviceCreate(struct WDFDEVICE__ * __ptr64) */

void __cdecl Etw_DeviceCreate(WDFDEVICE__ *param_1)

{
  ushort *puVar1;
  ushort *local_res10 [3];
  
  local_res10[0] = (ushort *)0x0;
  if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 1) != 0) {
    Etw_GetDeviceInstanceId(param_1,local_res10);
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,param_1,PTR__WDF_SERCX_CONTEXT_TYPE_INFO_1c0023ae0);
    puVar1 = local_res10[0];
    if ((Microsoft_Windows_Serial_ClassExtension_V2EnableBits & 1) != 0) {
      McTemplateK0pppz_EtwWriteTransfer();
    }
    if (puVar1 != (ushort *)0x0) {
      ExFreePoolWithTag(puVar1,0x32584353);
    }
  }
  return;
}



===== Etw_GetDeviceInstanceId @ 1c001aa90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Etw_GetDeviceInstanceId(struct WDFDEVICE__ * __ptr64,unsigned short * __ptr64 *
   __ptr64) */

void __cdecl Etw_GetDeviceInstanceId(WDFDEVICE__ *param_1,ushort **param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 in_stack_ffffffffffffffc8;
  uint uVar6;
  longlong lVar5;
  undefined4 uVar7;
  
  uVar6 = (uint)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  local_res18[0] = 0;
  local_res20[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x108))(WdfDriverGlobals,param_1);
  lVar5 = (ulonglong)uVar6 << 0x20;
  iVar1 = IoGetDevicePropertyData
                    (uVar3,&DEVPKEY_Device_InstanceId,0,0,lVar5,0,local_res18,local_res20);
  uVar7 = (undefined4)((ulonglong)lVar5 >> 0x20);
  iVar2 = 0;
  if (iVar1 != -0x3fffffdd) {
    iVar2 = iVar1;
  }
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(0,2,0xf,0xe,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar2);
    }
  }
  else if (local_res18[0] < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(0,2,0xf,0xf,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids);
    }
  }
  else {
    puVar4 = (ushort *)ExAllocatePool2(0x100,local_res18[0],0x32584353);
    if (puVar4 != (ushort *)0x0) {
      iVar2 = IoGetDevicePropertyData
                        (uVar3,&DEVPKEY_Device_InstanceId,0,0,CONCAT44(uVar7,local_res18[0]),puVar4,
                         local_res18,local_res20);
      if (-1 < iVar2) {
        *param_2 = puVar4;
        puVar4[(local_res18[0] >> 1) - 1] = 0;
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(0,2,0xf,0x11,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,(char)iVar2)
        ;
      }
      *param_2 = (ushort *)0x0;
      ExFreePoolWithTag(puVar4,0x32584353);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(0,2,0xf,0x10,&WPP_de3ad1f8ac2f365cb62c0e8efcd102da_Traceguids,
                        (char)local_res18[0]);
    }
  }
  *param_2 = (ushort *)0x0;
  return;
}



===== McTemplateK0pddbr2_EtwWriteTransfer @ 1c001ac8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pddbr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined4 param_6,undefined8 param_7)

{
  undefined8 local_res20;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined8 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 8;
  local_58 = &local_res20;
  local_1c = 0;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = param_7;
  local_20 = param_6;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventIoctlStart,param_3,5,local_68);
  return;
}



===== McTemplateK0pdddbr3_EtwWriteTransfer @ 1c001ad2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pdddbr3_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined4 param_7,undefined8 param_8)

{
  undefined8 local_res20;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 8;
  local_68 = &local_res20;
  local_1c = 0;
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_40 = 4;
  local_38 = &param_7;
  local_30 = 4;
  local_28 = param_8;
  local_20 = param_7;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventIoctlStop,param_3,6,local_78);
  return;
}



===== McTemplateK0pdx_EtwWriteTransfer @ 1c001addc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pdx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_20 = 8;
  local_28 = &param_6;
  local_30 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0pppz_EtwWriteTransfer @ 1c001ae60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pppz_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  undefined1 uStack0000000000000028;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 8;
  local_48 = &uStack0000000000000028;
  local_38 = &uStack0000000000000030;
  local_40 = 8;
  local_30 = 8;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000038[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  local_28 = in_stack_00000038;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,&SerCx2EtwEventDeviceCreate,0,5,local_68);
  return;
}



===== McTemplateK0px_EtwWriteTransfer @ 1c001af30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0px_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            ((undefined8 *)&SerCx2EtwProvider_Context,param_2,param_3,3,local_48);
  return;
}



===== FxStubDriverUnloadCommon @ 1c001afa4 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_1c0025b30,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c001afe0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c001b014 =====

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
    _DAT_1c0025b30 = 0x2080000;
    _DAT_1c0025b38 = &DAT_1c0026780;
    RtlCopyUnicodeString(&DAT_1c0025b30);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c0025b30,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0026988 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c0025b30);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0025a18 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c001b1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0026988 != (code *)0x0) && (DAT_1c0026988 != FxStubDriverUnload)) {
    (*DAT_1c0026988)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c001b1d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c001b1f9) */
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
    if ((uint *)0x1c0025a0f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_1c0025a18 = (undefined *)puVar2;
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



===== FxStubUnbindClasses @ 1c001b334 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0025a18 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_1c0025a18 + 0x50);
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



===== FxGetNextClassBindInfo @ 1c001b3f0 =====

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



===== FxStubInitTypes @ 1c001b438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c001b455) */
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
    if ((void **)0x1c0025a2f < ppvVar2) break;
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



===== StateMachineEngine_Init @ 1c001b500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl StateMachineEngine_Init(struct _SM_ENGINE_CONTEXT * __ptr64,void * __ptr64,void *
   __ptr64,unsigned long,struct _SM_ENGINE_STATE_TABLE_ENTRY * __ptr64 * __ptr64,void
   (__cdecl*)(void * __ptr64,void * __ptr64,enum _SM_ENGINE_EVENT),void (__cdecl*)(void *
   __ptr64,void * __ptr64,enum _SM_ENGINE_STATE,enum _SM_ENGINE_EVENT,enum _SM_ENGINE_STATE)) */

long __cdecl
StateMachineEngine_Init
          (_SM_ENGINE_CONTEXT *param_1,void *param_2,void *param_3,ulong param_4,
          _SM_ENGINE_STATE_TABLE_ENTRY **param_5,
          _func_void_void_ptr_void_ptr__SM_ENGINE_EVENT *param_6,
          _func_void_void_ptr_void_ptr__SM_ENGINE_STATE__SM_ENGINE_EVENT__SM_ENGINE_STATE *param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_res8;
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_res8 = 0;
  memset(param_1 + 0x10,0,0x380);
  *(void **)param_1 = param_2;
  *(void **)(param_1 + 8) = param_3;
  *(undefined **)(param_1 + 0x20) = PTR_TransferStateTableEntryWaitingForRequest_1c0024368;
  *(undefined ***)(param_1 + 0x10) = &TransferStateTable;
  KeInitializeSpinLock(param_1 + 0x18);
  local_2c = 0;
  local_18 = 0;
  local_10 = PTR__WDF_SM_ENGINE_WORKITEM_CONTEXT_TYPE_INFO_1c0023b30;
  pcStack_50 = StateMachineEngine_EvtOnPassive;
  local_3c = 0;
  uStack_34 = 0;
  local_40 = 0x38;
  local_28 = 1;
  local_24 = 1;
  local_58 = 0x18;
  local_48 = 1;
  local_20 = param_2;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                    (WdfDriverGlobals,&local_58,&local_40,&local_res8);
  if (-1 < iVar2) {
    puVar3 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF_SM_ENGINE_WORKITEM_CONTEXT_TYPE_INFO_1c0023b30);
    iVar2 = 0;
    *puVar3 = param_1;
    *(undefined8 *)(param_1 + 0x70) = local_res8;
    *(code **)(param_1 + 0x380) = Transfer_EtwWriteStateMachineEvent;
    *(code **)(param_1 + 0x388) = Transfer_EtwWriteStateMachineTransition;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x379] * 4 + 0x278) = 0xebe00030;
    param_1[0x379] = (_SM_ENGINE_CONTEXT)((char)param_1[0x379] + 1U & 0x3f);
    if (*(code **)(param_1 + 0x380) != (code *)0x0) {
      (**(code **)(param_1 + 0x380))(*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),0xebe00030)
      ;
    }
    uVar1 = **(undefined4 **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x7c) = uVar1;
    *(undefined4 *)(param_1 + (ulonglong)(byte)param_1[0x378] * 8 + 0x78) = 0xebe00030;
    param_1[0x378] = (_SM_ENGINE_CONTEXT)((char)param_1[0x378] + 1U & 0x3f);
    if (*(code **)(param_1 + 0x388) != (code *)0x0) {
      (**(code **)(param_1 + 0x388))
                (*(undefined8 *)param_1,*(undefined8 *)(param_1 + 8),0x57a70001,0xebe00030,uVar1);
    }
  }
  return iVar2;
}



===== _guard_check_icall @ 1c001b700 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c001b718 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c001b73c =====

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



===== __cpu_features_init @ 1c001b7b0 =====

/* WARNING: Removing unreachable block (ram,0x0001c001b81a) */
/* WARNING: Removing unreachable block (ram,0x0001c001b7c9) */
/* WARNING: Removing unreachable block (ram,0x0001c001b7ba) */

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



===== __security_check_cookie @ 1c001b880 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c001b8c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c001b8f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c001b8f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c001b920 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c001b980 =====

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



===== memset @ 1c001bc80 =====

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



===== __memset_repmovs @ 1c001bdc0 =====

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



===== __memset_query @ 1c001be40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c001bec0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c001c000 =====

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



===== __memset_spec_plain @ 1c001c080 =====

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



===== WppCleanupKm @ 1c002a008 =====

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



===== WppInitKm @ 1c002a0b8 =====

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



===== WppLoadTracingSupport @ 1c002a194 =====

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



===== WppTraceCallback @ 1c002a2e0 =====

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



===== __security_init_cookie @ 1c002b008 =====
/* FAILED */
