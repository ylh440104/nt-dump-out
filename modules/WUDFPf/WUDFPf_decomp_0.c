
===== SendTaskMessageSynchronously @ 140001010 =====

long __thiscall
RdDeviceCompanion::SendTaskMessageSynchronously
          (RdDeviceCompanion *this,ushort param_1,ulong param_2,void *param_3,ulong param_4,
          void *param_5,ulong param_6,long64 *param_7,ulong64 *param_8)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionSynchronousTaskMessageToCompanionHost
                    (this->m_RdFdo,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return lVar1;
}



===== RdSendCompanionSynchronousTaskMessageToCompanionHost @ 140001070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

long __thiscall
RdFdoDevice::RdSendCompanionSynchronousTaskMessageToCompanionHost
          (RdFdoDevice *this,ushort param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6,long64 *param_7,ulong64 *param_8)

{
  longlong *plVar1;
  bool bVar2;
  WudfProblem WVar3;
  ulong uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  ulong *puVar7;
  undefined7 extraout_var;
  ushort uVar8;
  longlong lVar9;
  _GUID *p_Var10;
  ulong uVar11;
  RdFdoDevice *pRVar12;
  undefined1 auStackY_d8 [32];
  int in_stack_ffffffffffffff50;
  IUMDFLPCMessage *local_80;
  _GUID local_78;
  ulonglong local_68;
  WUDF_PROBLEM local_60;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  bVar2 = false;
  local_78.Data1 = 0;
  local_80 = (IUMDFLPCMessage *)0x0;
  if ((this->m_RdProcess->m_DebugModeCounter).DisableTimeouts == 0) {
    lVar5 = (this->m_RdProcess->m_HostProcessTimeoutInTimerUnits).QuadPart;
  }
  else {
    lVar5 = -0x98967fff676980;
  }
  local_78._4_4_ = param_2;
  local_78.Data4 = (uchar  [8])param_3;
  if (param_7 == (long64 *)0x0) {
LAB_140001110:
    lVar9 = lVar5;
LAB_140001113:
    uVar8 = (ushort)lVar9;
    if ((param_4 < 0xf000) && (param_6 < 0xf000)) {
      local_68 = (ulonglong)(param_4 + 0x20);
      LOCK();
      local_80 = this->m_PreAllocatedSynchronousTaskMsg;
      this->m_PreAllocatedSynchronousTaskMsg = (IUMDFLPCMessage *)0x0;
      UNLOCK();
      uVar11 = param_6 + 0x10;
      if (local_80 == (IUMDFLPCMessage *)0x0) {
        plVar1 = *(longlong **)(this->_padding_ + 0x70);
        uVar4 = (**(code **)(*plVar1 + 0x48))(plVar1,&local_80);
        if ((int)uVar4 < 0) goto LAB_14000131d;
        param_3 = (void *)local_78.Data4;
      }
      else {
        bVar2 = true;
        (**(code **)((longlong)*local_80 + 0x60))(local_80,local_68,uVar11);
      }
      puVar6 = (undefined1 *)(**(code **)((longlong)*local_80 + 0x18))(local_80,local_68);
      *puVar6 = 0x18;
      *(WUDF_COMPANION_CONTEXT__ **)(puVar6 + 8) = this->m_CompanionContext;
      *(undefined4 *)(puVar6 + 0x10) = local_78._4_4_;
      *(ushort *)(puVar6 + 0x1c) = param_1;
      *(ulong *)(puVar6 + 0x14) = param_4;
      *(ulong *)(puVar6 + 0x18) = param_6;
      if ((uchar  [8])param_3 != (uchar  [8])0x0) {
        memcpy();
      }
      p_Var10 = &local_78;
      puVar7 = (ulong *)(**(code **)((longlong)*local_80 + 0x28))();
      uVar4 = local_78.Data1;
      if (puVar7 == (ulong *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          p_Var10 = WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids;
          pRVar12 = this;
          WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x26,
                    WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,this,local_78.Data1);
          uVar11 = (ulong)pRVar12;
        }
        local_60.Message = WudfMsg_COMPANION_SYNCHRONOUS_TASK;
        local_60._17_1_ = 0;
        local_60.IrpInfo = 0;
        WVar3 = MapToSendProblem(uVar4);
        local_60._0_4_ = SUB84(CONCAT71(extraout_var,WVar3),0);
        local_60.Detector = WdfComponentReflector;
        local_60._5_1_ = 0;
        local_60._padding_ = 0;
        local_60.DeviceStarted = WudfDeviceStartState_Unknown;
        local_60._25_3_ = 0;
        local_60.ExitCode = WdfHostExit_CodeUnknown;
        local_60._9_1_ = 0;
        local_60._padding_ = 0x7000;
        local_60.Operation = WudfOperation_Pnp;
        local_60._13_1_ = 0;
        local_60._padding_ = 0;
        local_60.Status = uVar4;
        DisableDevice(this,&local_60,(wchar_t *)p_Var10,uVar11);
        if (-1 < (int)uVar4) goto LAB_140001281;
      }
      else {
        uVar4 = *puVar7;
        if (-1 < (int)uVar4) {
          p_Var10 = *(_GUID **)(puVar7 + 2);
          if (p_Var10 <= (_GUID *)(ulonglong)param_6) {
            if ((param_5 != (void *)0x0) && (p_Var10 != (_GUID *)0x0)) {
              memcpy();
            }
            if (param_8 != (ulong64 *)0x0) {
              *param_8 = *(ulong64 *)(puVar7 + 2);
            }
            goto LAB_140001281;
          }
          uVar4 = 0xc000000d;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            WPP_SF_qPP((WPP_GLOBAL_Control->Control).Logger,uVar8,p_Var10,this,(ulong64)p_Var10,
                       (ulong64)(ulonglong)param_6);
          }
        }
      }
    }
    else {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x25,
                  WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,this,0xefff);
      }
      uVar4 = 0xc000000d;
    }
  }
  else {
    lVar9 = *param_7;
    if (lVar9 < 0) {
      if (lVar9 < lVar5) goto LAB_140001110;
      goto LAB_140001113;
    }
    if (lVar9 < 1) goto LAB_140001113;
    uVar4 = 0xc000000d;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_qid((WPP_GLOBAL_Control->Control).Logger,param_1,(_GUID *)0x0,this,lVar9,
                 in_stack_ffffffffffffff50);
    }
  }
LAB_14000131d:
  if (param_8 != (ulong64 *)0x0) {
    *param_8 = 0;
  }
LAB_140001281:
  if (bVar2) {
    LOCK();
    this->m_PreAllocatedSynchronousTaskMsg = local_80;
    UNLOCK();
  }
  else if (local_80 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*local_80 + 8))();
  }
  return uVar4;
}



===== SendWait @ 1400014f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

_WUDFMESSAGE_REPLY_HEADER * __thiscall
WudfLpcMessage::SendWait(WudfLpcMessage *this,_LARGE_INTEGER param_1,long *param_2)

{
  uint uVar1;
  WdfComponentType WVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var4;
  ulonglong uVar5;
  _WUDFMESSAGE_REPLY_HEADER *p_Var6;
  ulong in_R9D;
  ulong uVar7;
  ulonglong local_res8;
  _LARGE_INTEGER local_res10;
  char *in_stack_ffffffffffffffa8;
  char *pcVar8;
  WdfDriverStopType in_stack_ffffffffffffffb0;
  WdfDriverStopType WVar9;
  longlong lVar10;
  WdfErrorClass in_stack_ffffffffffffffb8;
  WdfErrorClass WVar11;
  ulong in_stack_ffffffffffffffc0;
  ulong uVar12;
  
  p_Var6 = (_WUDFMESSAGE_REPLY_HEADER *)0x0;
  local_res8 = 0;
  pWVar3 = WPP_GLOBAL_Control;
  local_res10.QuadPart = param_1.QuadPart;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    WPP_SF_i((ulong64)pWVar3,(ushort)param_1._s_0.LowPart,(_GUID *)param_2,param_1.QuadPart);
    in_R9D = param_1._s_0.LowPart;
  }
  WVar2 = (WdfComponentType)pWVar3;
  if (this->_padding_ == 0) {
    in_R9D = 0x40018c30;
    WVar2 = WdfComponentInvalid;
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
               "TODO: Write something interesting here");
  }
  if (local_res10.QuadPart == 0) {
    WudfVerifyStatic(WVar2,(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x0,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",in_R9D,
                     in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,"TODO: Write something interesting here",false);
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x40,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,&this[-1].m_ReplyMessageExtendTimeout
              );
    }
    uVar1 = 0xc000000d;
  }
  else {
    *(undefined1 *)&this->_padding_ = 0;
    *(undefined2 *)(this->_padding_ + 4) = 1;
    lVar10 = this->_padding_;
    *(undefined4 *)(lVar10 + 0x18) = *(undefined4 *)&this->m_ReplyReceived;
    uVar5 = this->_padding_ + 0x28;
    local_res8 = uVar5;
    if (this->field_0x7c != '\0') {
      WudfVerifyStatic((WdfComponentType)lVar10,
                       (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                       local_res10._s_0,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
                       in_R9D,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,
                       in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                       "TODO: Write something interesting here",
                       *(int *)(this->_padding_ + 0x18) != 0);
    }
    pcVar8 = (this->m_ReplyCallbackLock).Value;
    lVar10 = this->_padding_;
    uVar7 = (ulong)lVar10;
    p_Var4 = *(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr **)
              (this->_padding_ + 0x80);
    WVar11 = (WdfErrorClass)&local_res8;
    uVar12 = 0;
    uVar1 = (**(code **)(*(longlong *)this->m_ReplyMessageCall + 0x98))
                      (this->m_ReplyMessageCall,p_Var4,0x20000);
    WVar9 = (WdfDriverStopType)lVar10;
    if ((int)uVar1 < 0) {
      pWVar3 = WPP_GLOBAL_Control;
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
        p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x41;
        uVar7 = uVar1;
        WPP_SF_D((ulong64)pWVar3,0x41,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar1);
      }
      if (this->field_0x7c != '\0') {
        WudfVerifyStatic((WdfComponentType)pWVar3,p_Var4,
                         L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar7,pcVar8,
                         WVar9,WVar11,uVar12,"ALPC should never fail here",uVar1 != 0xc000009a);
      }
    }
    else if (local_res8 < uVar5) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x42,
                WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
      }
      uVar1 = 0xc0000023;
    }
    else {
      p_Var6 = (_WUDFMESSAGE_REPLY_HEADER *)(this->_padding_ + 0x28);
    }
  }
  if (param_2 != (long *)0x0) {
    *param_2 = uVar1;
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x43,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,p_Var6);
  }
  return p_Var6;
}



===== SendWaitReceivePort @ 140001800 =====

long __thiscall
WdfLpcCorePortInterface::SendWaitReceivePort
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,_PORT_MESSAGE *param_3,
          _ALPC_MESSAGE_ATTRIBUTES *param_4,_PORT_MESSAGE *param_5,ulong64 *param_6,
          _ALPC_MESSAGE_ATTRIBUTES *param_7,_LARGE_INTEGER *param_8)

{
  int iVar1;
  
  (param_3->u2).s2.Type = (param_3->u2).s2.Type | 0x8000;
  iVar1 = ZwAlpcSendWaitReceivePort(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8)
  ;
  if (iVar1 == 0x102) {
    iVar1 = -0x3fffff4b;
  }
  return iVar1;
}



===== HostProcessTimeoutInTimerUnit @ 140001880 =====

_LARGE_INTEGER __thiscall RdProcess::HostProcessTimeoutInTimerUnit(RdProcess *this)

{
  _LARGE_INTEGER_s_0 _Var1;
  _LARGE_INTEGER_s_0 in_RDX;
  
  if ((this->m_DebugModeCounter).DisableTimeouts == 0) {
    _Var1 = (this->m_HostProcessTimeoutInTimerUnits)._s_0;
  }
  else {
    _Var1.LowPart = 10000000;
    _Var1.HighPart = -10000000;
  }
  *(_LARGE_INTEGER_s_0 *)in_RDX = _Var1;
  return (_LARGE_INTEGER)in_RDX;
}



===== ResetMessageBody @ 1400018b0 =====

void __thiscall
WudfLpcMessage::ResetMessageBody(WudfLpcMessage *this,ulong64 param_1,ulong64 param_2)

{
  undefined8 *puVar1;
  
  this->_padding_ = param_1;
  this->_padding_ = param_2;
  puVar1 = (undefined8 *)this->_padding_;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(short *)this->_padding_ = (short)this->_padding_;
  *(short *)(this->_padding_ + 2) = (short)this->_padding_ + 0x28;
  return;
}



===== `scalar_deleting_destructor' @ 140001900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void * __thiscall WudfLpcMessage::_scalar_deleting_destructor_(WudfLpcMessage *this,uint param_1)

{
  void *pvVar1;
  long lVar2;
  int iVar3;
  
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCMessage__;
  lVar2 = ResetDataBuffer((WudfLpcMessage *)&this->_padding_,0,0);
  if (lVar2 < 0) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
               "TODO: Write something interesting here");
  }
  if ((this->m_ReservedWithAlpc != '\0') && (this->m_MessageId != 0)) {
    iVar3 = (**(code **)((longlong)*this->m_LpcCorePortInterface + 0x58))
                      (this->m_LpcCorePortInterface,this->m_LpcCommPort->_padding_,0);
    if (iVar3 < 0) {
      WdfPlatform::UmdfDriverStop
                (WdfInternalError,0x100000000000000,
                 L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
                 "m_LpcCorePortInterface->DeleteResourceReserve failed");
    }
  }
  pvVar1 = (this->m_ReplyCallbackLock).Value;
  if (pvVar1 != (void *)0x0) {
    ExFreePoolWithTag(pvVar1,0);
  }
  WdfObject::~WdfObject((WdfObject *)this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== ~WdfObject @ 140001a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfObject::~WdfObject(WdfObject *this)

{
  void *pvVar1;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  this->_padding_ = (longlong)&___7WdfObject__6B_;
  if (this->m_Name != (wchar_t *)0x0) {
    ExFreePoolWithTag();
  }
  if (this->m_Parent != (WdfObject *)0x0) {
    (**(code **)(this->m_Parent->_padding_ + 8))();
  }
  pvVar1 = (this->m_Event).Value;
  if ((int)this->_padding_ < 0) {
    if ((pvVar1 != (void *)0x0) && (this->m_DeleteWaitInAction == '\0')) {
      ExFreePoolWithTag();
      (this->m_Event).Value = (void *)0x0;
    }
  }
  else {
    WudfVerifyStatic((WdfComponentType)pvVar1,
                     (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                     (ulonglong)(pvVar1 != (void *)0x0),
                     L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                     in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                     in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                     "release wait must have a event",
                     (pvVar1 != (void *)0x0) == (bool)this->m_DeleteWaitInAction);
  }
  pvVar1 = (this->m_Event).Value;
  if (pvVar1 != (void *)0x0) {
    KeSetEvent(pvVar1,0,0);
  }
  CUMDFUnknown::~CUMDFUnknown((CUMDFUnknown *)this);
  WdfObjectLock::~WdfObjectLock((WdfObjectLock *)&this->_padding_);
  return;
}



===== ResetDataBuffer @ 140001ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

long __thiscall
WudfLpcMessage::ResetDataBuffer(WudfLpcMessage *this,ulong64 param_1,ulong64 param_2)

{
  void *pvVar1;
  bool bVar2;
  uint uVar3;
  byte extraout_var_01;
  uint *puVar4;
  byte extraout_var;
  byte extraout_var_00;
  uint *puVar5;
  WdfComponentType WVar6;
  WPP_PROJECT_CONTROL_BLOCK *pWVar7;
  _func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
  *p_Var8;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var9;
  ulong in_R9D;
  ulong uVar10;
  uint uVar11;
  ulong64 uVar12;
  longlong lVar13;
  undefined8 local_res8;
  char *in_stack_ffffffffffffffa8;
  char *pcVar14;
  WdfDriverStopType in_stack_ffffffffffffffb0;
  WdfDriverStopType WVar15;
  WdfErrorClass in_stack_ffffffffffffffb8;
  WdfErrorClass WVar16;
  ulong in_stack_ffffffffffffffc0;
  
  pWVar7 = WPP_GLOBAL_Control;
  p_Var9 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)param_1;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar7 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    uVar12 = param_1;
    in_stack_ffffffffffffffa8 = (char *)param_2;
    WPP_SF_PP((ulong64)pWVar7,(ushort)param_1,(_GUID *)param_2,param_1,param_2);
    in_R9D = (ulong)uVar12;
  }
  pvVar1 = (this->m_ReplyCallbackLock).Value;
  *(undefined1 *)&this->_padding_ = 0;
  if ((pvVar1 != (void *)0x0) && ((*(uint *)((longlong)pvVar1 + 4) & 0x40000000) != 0)) {
    if ((this->_padding_ == 0) && (this->_padding_ == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    WudfVerifyStatic((WdfComponentType)pWVar7,p_Var9,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",in_R9D,
                     in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0,"TODO: Write something interesting here",bVar2);
    WVar6 = (WdfComponentType)(this->m_ReplyCallbackLock).Value;
    p_Var9 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x40000000;
    puVar4 = (uint *)AlpcGetMessageAttribute();
    if ((*puVar4 >> 0x11 & 1) != 0) {
      puVar4[4] = 0;
      puVar4[5] = 0;
      *puVar4 = *puVar4 & 0xfffdffff;
    }
    if (*(longlong *)(puVar4 + 4) != 0) {
      WudfVerifyStatic(WVar6,p_Var9,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
                       in_R9D,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,
                       in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                       "TODO: Write something interesting here",*(longlong *)(puVar4 + 6) != 0);
      p_Var8 = this->m_ReplyMessageCall;
      uVar10 = (ulong)*(undefined8 *)(puVar4 + 4);
      p_Var9 = *(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr **)
                (this->_padding_ + 0x80);
      (**(code **)(*(longlong *)p_Var8 + 0x78))(p_Var8,p_Var9,0);
      WudfVerifyStatic((WdfComponentType)p_Var8,p_Var9,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar10,
                       in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8
                       ,in_stack_ffffffffffffffc0,"TODO: Write something interesting here",
                       (bool)(extraout_var >> 7 ^ 1));
    }
    lVar13 = *(longlong *)(puVar4 + 2);
    if (lVar13 != 0) {
      p_Var8 = this->m_ReplyMessageCall;
      p_Var9 = *(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr **)
                (this->_padding_ + 0x80);
      (**(code **)(*(longlong *)p_Var8 + 0x68))(p_Var8,p_Var9,0);
      puVar4[2] = 0;
      puVar4[3] = 0;
      WudfVerifyStatic((WdfComponentType)p_Var8,p_Var9,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",(ulong)lVar13,
                       in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8
                       ,in_stack_ffffffffffffffc0,"TODO: Write something interesting here",
                       (bool)(extraout_var_00 >> 7 ^ 1));
    }
    puVar4 = (uint *)((longlong)(this->m_ReplyCallbackLock).Value + 4);
    *puVar4 = *puVar4 & 0xbfffffff;
  }
  this->_padding_ = param_1;
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  this->_padding_ = param_2;
  if ((char *)param_1 == (char *)0x0) {
LAB_140001e57:
    uVar3 = 0;
  }
  else {
    local_res8 = 0;
    puVar5 = (uint *)AlpcGetMessageAttribute((this->m_ReplyCallbackLock).Value,0x40000000);
    p_Var8 = this->m_ReplyMessageCall;
    uVar11 = 0;
    p_Var9 = *(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr **)
              (this->_padding_ + 0x80);
    WVar16 = (WdfErrorClass)&local_res8;
    pcVar14 = (char *)param_1;
    puVar4 = puVar5 + 2;
    uVar3 = (**(code **)(*(longlong *)p_Var8 + 0x60))(p_Var8,p_Var9,0);
    WVar15 = (WdfDriverStopType)puVar4;
    if ((int)uVar3 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        pcVar14 = (char *)CONCAT44((int)((ulonglong)pcVar14 >> 0x20),uVar3);
        uVar11 = (uint)param_1;
        WPP_SF_dd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x36,
                  WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar11,uVar3);
      }
    }
    else {
      WudfVerifyStatic((WdfComponentType)p_Var8,p_Var9,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar11,pcVar14,
                       WVar15,WVar16,in_stack_ffffffffffffffc0,
                       "TODO: Write something interesting here",*(longlong *)(puVar5 + 2) != 0);
      puVar4 = (uint *)((longlong)(this->m_ReplyCallbackLock).Value + 4);
      *puVar4 = *puVar4 | 0x40000000;
      *puVar5 = 0;
      *(ulong64 *)(puVar5 + 6) = param_1;
      puVar5[4] = 0;
      puVar5[5] = 0;
      p_Var8 = this->m_ReplyMessageCall;
      p_Var9 = *(_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr **)
                (this->_padding_ + 0x80);
      puVar4 = puVar5;
      uVar3 = (**(code **)(*(longlong *)p_Var8 + 0x70))(p_Var8,p_Var9,0);
      uVar11 = (uint)puVar4;
      if (-1 < (int)uVar3) {
        WudfVerifyStatic((WdfComponentType)p_Var8,p_Var9,
                         L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar11,pcVar14,
                         WVar15,WVar16,in_stack_ffffffffffffffc0,
                         "TODO: Write something interesting here",*(longlong *)(puVar5 + 4) != 0);
        if (this->_padding_ == 0) {
          *puVar5 = *puVar5 | 0x20000;
        }
        goto LAB_140001e57;
      }
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        uVar11 = uVar3;
        WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x37,
                 WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar3);
      }
    }
    p_Var9 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x0;
    (**(code **)(this->_padding_ + 0x38))(this,0,0);
    WudfVerifyStatic((WdfComponentType)this,p_Var9,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar11,pcVar14,
                     WVar15,WVar16,in_stack_ffffffffffffffc0,
                     "TODO: Write something interesting here",(bool)(extraout_var_01 >> 7 ^ 1));
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x38,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar3);
  }
  return uVar3;
}



===== WudfVerifyStatic @ 140001ed0 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __cdecl
WudfVerifyStatic(WdfComponentType param_1,
                _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *param_2,
                wchar_t *param_3,ulong param_4,char *param_5,WdfDriverStopType param_6,
                WdfErrorClass param_7,ulong param_8,char *param_9,bool param_10)

{
  if (!param_10) {
    WdfPlatform::UmdfDriverStop(WdfInternalError,0x100000000000000,param_3,param_9);
  }
  return;
}



===== MessageBody @ 140001f00 =====

void * __thiscall WudfLpcMessage::MessageBody(WudfLpcMessage *this,ulong64 param_1)

{
  *(short *)this->_padding_ = (short)param_1;
  *(short *)(this->_padding_ + 2) = (short)param_1 + 0x28;
  return (void *)(this->_padding_ + 0x28);
}



===== RdSendCompanionEventMessageToCompanionHost @ 140001f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

long __thiscall
RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
          (RdFdoDevice *this,WUDF_COMPANION_EVENT_TYPE param_1,_CM_RESOURCE_LIST *param_2,
          _CM_RESOURCE_LIST *param_3,ulong param_4)

{
  longlong *plVar1;
  _CM_RESOURCE_LIST *p_Var2;
  WudfProblem WVar3;
  ulong uVar4;
  undefined1 *puVar5;
  longlong lVar6;
  _LARGE_INTEGER _Var7;
  ulong *puVar8;
  undefined7 extraout_var;
  uchar auVar9 [8];
  ulonglong uVar10;
  _GUID *p_Var11;
  WUDF_COMPANION_EVENT_TYPE WVar12;
  code *pcVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStackY_e8 [32];
  _GUID local_98;
  _CM_RESOURCE_LIST *local_88;
  _CM_RESOURCE_LIST *local_80;
  WUDF_PROBLEM local_78;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_e8;
  auVar9[0] = '\0';
  auVar9[1] = '\0';
  auVar9[2] = '\0';
  auVar9[3] = '\0';
  auVar9[4] = '\0';
  auVar9[5] = '\0';
  auVar9[6] = '\0';
  auVar9[7] = '\0';
  lVar14 = 0;
  lVar15 = 0;
  local_98.Data1 = 0;
  local_88 = param_2;
  local_80 = param_3;
  if (param_1 == CompanionEvent_PrepareHardware) {
    if (param_2 != (_CM_RESOURCE_LIST *)0x0) {
      lVar14 = ((ulonglong)(param_2->List[0].PartialResourceList.Count - 1) + 2) * 0x14;
    }
    if (param_3 != (_CM_RESOURCE_LIST *)0x0) {
      lVar15 = ((ulonglong)(param_3->List[0].PartialResourceList.Count - 1) + 2) * 0x14;
    }
    uVar10 = lVar15 + 0x28 + lVar14;
    if (uVar10 < 0xffd8) goto LAB_14000201a;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x20,
                WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,this,0xffd7);
    }
    uVar4 = 0xc000042b;
  }
  else {
    uVar10 = 0x28;
LAB_14000201a:
    local_98.Data4[0] = '\0';
    local_98.Data4[1] = '\0';
    local_98.Data4[2] = '\0';
    local_98.Data4[3] = '\0';
    local_98.Data4[4] = '\0';
    local_98.Data4[5] = '\0';
    local_98.Data4[6] = '\0';
    local_98.Data4[7] = '\0';
    plVar1 = *(longlong **)(this->_padding_ + 0x70);
    uVar4 = (**(code **)(*plVar1 + 0x48))(plVar1,local_98.Data4,uVar10,4);
    if ((int)uVar4 < 0) {
      if (local_98.Data4 != (uchar  [8])0x0) {
        (**(code **)(*(longlong *)local_98.Data4 + 8))();
        local_98.Data4[0] = '\0';
        local_98.Data4[1] = '\0';
        local_98.Data4[2] = '\0';
        local_98.Data4[3] = '\0';
        local_98.Data4[4] = '\0';
        local_98.Data4[5] = '\0';
        local_98.Data4[6] = '\0';
        local_98.Data4[7] = '\0';
      }
    }
    else {
      puVar5 = (undefined1 *)
               (**(code **)(*(longlong *)local_98.Data4 + 0x18))(local_98.Data4,uVar10);
      auVar9 = local_98.Data4;
      *puVar5 = 0x19;
      lVar6 = (**(code **)(*(longlong *)local_98.Data4 + 0x18))(local_98.Data4,uVar10);
      p_Var2 = local_80;
      *(WUDF_COMPANION_CONTEXT__ **)(lVar6 + 8) = this->m_CompanionContext;
      *(WUDF_COMPANION_EVENT_TYPE *)(lVar6 + 0x10) = param_1;
      if (param_1 == CompanionEvent_PrepareHardware) {
        *(longlong *)(lVar6 + 0x18) = lVar14;
        *(longlong *)(lVar6 + 0x20) = lVar15;
        if (local_88 != (_CM_RESOURCE_LIST *)0x0) {
          memcpy();
        }
        if (p_Var2 != (_CM_RESOURCE_LIST *)0x0) {
          memcpy();
        }
      }
      else if (param_1 != CompanionEvent_ReleaseHardware) {
        if ((param_1 == CompanionEvent_D0Entry) || (param_1 == CompanionEvent_D0Exit)) {
          *(ulong *)(lVar6 + 0x18) = param_4;
        }
        else if (param_1 != CompanionEvent_SurpriseRemove) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x21,
                     WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,param_1);
          }
          uVar4 = 0xc00000bb;
          goto LAB_14000224d;
        }
      }
      pcVar13 = *(code **)(*(longlong *)auVar9 + 0x28);
      _Var7 = RdProcess::HostProcessTimeoutInTimerUnit(this->m_RdProcess);
      p_Var11 = &local_98;
      puVar8 = (ulong *)(*pcVar13)(auVar9,*(undefined8 *)_Var7._s_0);
      uVar4 = local_98.Data1;
      WVar12 = (WUDF_COMPANION_EVENT_TYPE)pcVar13;
      if (puVar8 == (ulong *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          p_Var11 = WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids;
          WVar12 = param_1;
          WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x22,
                    WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,param_1,local_98.Data1);
        }
        local_78.Message = WudfMsg_COMPANION_EVENT;
        local_78._17_1_ = 0;
        local_78.IrpInfo = 0;
        WVar3 = MapToSendProblem(uVar4);
        local_78._0_4_ = SUB84(CONCAT71(extraout_var,WVar3),0);
        local_78.Detector = WdfComponentReflector;
        local_78._5_1_ = 0;
        local_78._padding_ = 0;
        local_78.ExitCode = WdfHostExit_CodeUnknown;
        local_78._9_1_ = 0;
        local_78._padding_ = 0x7000;
        local_78.DeviceStarted = WudfDeviceStartState_Unknown;
        local_78._25_3_ = 0;
        local_78.Operation = WudfOperation_Pnp;
        local_78._13_1_ = 0;
        local_78._padding_ = 0;
        local_78.Status = uVar4;
        DisableDevice(this,&local_78,(wchar_t *)p_Var11,WVar12);
      }
      else {
        uVar4 = *puVar8;
      }
      if (-1 < (int)uVar4) goto LAB_140002282;
    }
  }
LAB_14000224d:
  if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
      (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
     (1 < (WPP_GLOBAL_Control->Control).Level)) {
    WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x23,
              WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,param_1,uVar4);
  }
LAB_140002282:
  if (auVar9 != (uchar  [8])0x0) {
    (**(code **)(*(longlong *)auVar9 + 8))(auVar9);
  }
  return uVar4;
}



===== WdfObject @ 1400022f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfObject * __thiscall
WdfObject::WdfObject
          (WdfObject *this,wchar_t *param_1,WdfObject *param_2,uchar param_3,RdType param_4)

{
  wchar_t wVar1;
  int iVar2;
  undefined1 auVar3 [16];
  ulong64 uVar4;
  long lVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  WUDF_EVENT WVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  longlong lVar12;
  int iVar13;
  ulong64 local_res8;
  
  WdfObjectLock::WdfObjectLock((WdfObjectLock *)&this->_padding_);
  iVar13 = (int)this->_padding_;
  this->_padding_ = (longlong)&___7WdfObject__6B_;
  this->m_ObjectType = param_4;
  *(undefined4 *)&this->_padding_ = 1;
  local_res8 = 0;
  this->m_Next = (WdfObject *)0x0;
  this->m_Name = (wchar_t *)0x0;
  this->m_MarkedForDelete = '\0';
  (this->m_Event).Value = (void *)0x0;
  this->m_Parent = (WdfObject *)0x0;
  this->m_DeleteWaitInAction = '\0';
  this->m_UniqueObjectId = 0xffffffff;
  if (-1 < iVar13) {
    if (param_1 == (wchar_t *)0x0) {
      iVar13 = -0x3ffffff3;
    }
    else {
      lVar5 = RtlStringLengthWorkerW(param_1,0x7fffffff,&local_res8);
      uVar4 = local_res8;
      if (lVar5 < 0) {
        iVar13 = -0x3ffffff3;
      }
      else {
        uVar11 = local_res8 + 1;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar11;
        uVar6 = SUB168(ZEXT816(2) * auVar3,0);
        if (SUB168(ZEXT816(2) * auVar3,8) != 0) {
          uVar6 = 0xffffffffffffffff;
        }
        pwVar7 = (wchar_t *)ExAllocatePool2(0x40,uVar6,0x64444d55);
        this->m_Name = pwVar7;
        if (pwVar7 == (wchar_t *)0x0) {
          iVar13 = -0x3fffffe9;
        }
        else {
          if ((param_2 == (WdfObject *)0x0) || (param_3 != '\0')) {
            WVar8 = WdfPlatformEvent::WudfAllocateEvent(NotificationEvent,(ulong)uVar6);
            (this->m_Event).Value = WVar8.Value;
            if (WVar8.Value == (void *)0x0) {
              iVar13 = -0x3fffffe9;
              goto LAB_140002437;
            }
          }
          pwVar7 = this->m_Name;
          if (uVar11 != 0) {
            if (uVar11 < 0x80000000) {
              lVar9 = (uVar11 - uVar4) + 0x7ffffffd;
              lVar12 = (longlong)param_1 - (longlong)pwVar7;
              do {
                if ((lVar9 == 0) ||
                   (wVar1 = *(wchar_t *)(lVar12 + (longlong)pwVar7), wVar1 == L'\0')) break;
                *pwVar7 = wVar1;
                lVar9 = lVar9 + -1;
                pwVar7 = pwVar7 + 1;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
              pwVar10 = pwVar7 + -1;
              if (uVar11 != 0) {
                pwVar10 = pwVar7;
              }
              *pwVar10 = L'\0';
              if (uVar11 != 0) {
                this->m_Parent = param_2;
                if (param_2 != (WdfObject *)0x0) {
                  (**(code **)param_2->_padding_)();
                }
                goto LAB_140002437;
              }
            }
            else {
              *pwVar7 = L'\0';
            }
          }
          iVar13 = -0x3fffff1b;
        }
      }
    }
  }
LAB_140002437:
  iVar2 = (int)this->_padding_;
  if ((iVar2 < 0) && (iVar2 != iVar13)) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "constructor already failed\n");
  }
  *(int *)&this->_padding_ = iVar13;
  return this;
}



===== Release @ 140002500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulong __thiscall WudfLpcMessage::Release(WudfLpcMessage *this)

{
  longlong *plVar1;
  longlong lVar2;
  ulong uVar3;
  
  LOCK();
  plVar1 = &this->_padding_;
  lVar2 = *plVar1;
  *(int *)plVar1 = (int)*plVar1 + -1;
  UNLOCK();
  uVar3 = (int)lVar2 - 1;
  if (uVar3 == 0xffffffff) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "double release object");
  }
  else if ((uVar3 == 0) && (this != (WudfLpcMessage *)0x0)) {
    (**(code **)(this->_padding_ + 0x18))(this,(int)lVar2);
  }
  return uVar3;
}



===== Release @ 140002560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulong __thiscall CUMDFUnknown::Release(CUMDFUnknown *this)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  
  LOCK();
  puVar1 = &this->m_RefCount;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  uVar3 = uVar2 - 1;
  if (uVar3 == 0xffffffff) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "double release object");
    return 0xffffffff;
  }
  if ((uVar3 == 0) && (this != (CUMDFUnknown *)0x0)) {
    (**(code **)(this->_padding_ + 0x18))(this,uVar2);
  }
  return uVar3;
}



===== SetCtorStatus @ 1400025d0 =====

void __thiscall WdfCtorStatus::SetCtorStatus(WdfCtorStatus *this,long param_1)

{
  if ((this->m_ConstructorStatus < 0) && (this->m_ConstructorStatus != param_1)) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "constructor already failed\n");
    this->m_ConstructorStatus = param_1;
  }
  else {
    this->m_ConstructorStatus = param_1;
  }
  return;
}



===== WudfLpcMessage @ 140002620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WudfLpcMessage * __thiscall
WudfLpcMessage::WudfLpcMessage
          (WudfLpcMessage *this,WdfLpcCommPort *param_1,uchar param_2,ulong64 param_3,
          ulong64 param_4,ulong64 param_5,ulong64 param_6,_ALPC_SECURITY_ATTR *param_7)

{
  int iVar1;
  undefined1 auVar2 [16];
  long lVar3;
  longlong lVar4;
  WUDF_EVENT WVar5;
  ulong uVar6;
  ulonglong uVar7;
  int iVar8;
  ulong64 local_res8;
  
  WdfObjectLock::WdfObjectLock((WdfObjectLock *)&this->_padding_);
  iVar8 = (int)this->_padding_;
  this->_padding_ = (longlong)&___7WdfObject__6B_;
  *(undefined4 *)&this->_padding_ = 1;
  local_res8 = 0;
  this->_padding_ = 0;
  this->_padding_ = 0;
  *(undefined2 *)&this->_padding_ = 0x1000;
  this->_padding_ = 0;
  this->_padding_ = 0;
  *(undefined1 *)((longlong)&this->_padding_ + 4) = 0;
  *(undefined4 *)&this->_padding_ = 0xffffffff;
  if (-1 < iVar8) {
    lVar3 = RtlStringLengthWorkerW(L"LpcMessage",0x7fffffff,&local_res8);
    if (lVar3 < 0) {
      iVar8 = -0x3ffffff3;
    }
    else {
      uVar7 = local_res8 + 1;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar7;
      uVar6 = SUB164(ZEXT816(2) * auVar2,0);
      if (SUB168(ZEXT816(2) * auVar2,8) != 0) {
        uVar6 = 0xffffffff;
      }
      lVar4 = ExAllocatePool2();
      this->_padding_ = lVar4;
      if (lVar4 == 0) {
        iVar8 = -0x3fffffe9;
      }
      else {
        if (param_1 == (WdfLpcCommPort *)0x0) {
          WVar5 = WdfPlatformEvent::WudfAllocateEvent(NotificationEvent,uVar6);
          this->_padding_ = (longlong)WVar5.Value;
          if (WVar5.Value == (void *)0x0) {
            iVar8 = -0x3fffffe9;
            goto LAB_140002769;
          }
        }
        lVar3 = RtlStringCchCopyW((wchar_t *)this->_padding_,uVar7,L"LpcMessage");
        if (lVar3 < 0) {
          iVar8 = -0x3fffff1b;
        }
        else {
          this->_padding_ = (longlong)param_1;
          if (param_1 != (WdfLpcCommPort *)0x0) {
            (**(code **)param_1->_padding_)();
          }
        }
      }
    }
  }
LAB_140002769:
  iVar1 = (int)this->_padding_;
  if ((iVar1 < 0) && (iVar1 != iVar8)) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "constructor already failed\n");
  }
  *(int *)&this->_padding_ = iVar8;
  *(undefined2 *)((longlong)&this->_padding_ + 4) = 0;
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCMessage__;
  WudfLpcpMessage(this,param_1,(_ALPC_DATA_VIEW_ATTR *)0x0,param_7,param_3,param_4,param_5,param_6,
                  param_2);
  return this;
}



===== WudfLpcpMessage @ 140002820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall
WudfLpcMessage::WudfLpcpMessage
          (WudfLpcMessage *this,WdfLpcCommPort *param_1,_ALPC_DATA_VIEW_ATTR *param_2,
          _ALPC_SECURITY_ATTR *param_3,ulong64 param_4,ulong64 param_5,ulong64 param_6,
          ulong64 param_7,uchar param_8)

{
  ulong *puVar1;
  IUMDFLPCCorePortInterface *pIVar2;
  _PORT_MESSAGE *p_Var3;
  ulong64 uVar4;
  void *pvVar5;
  _SECURITY_QUALITY_OF_SERVICE *p_Var6;
  ulong64 uVar7;
  ulong64 uVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  WUDF_EVENT WVar12;
  WPP_PROJECT_CONTROL_BLOCK *pWVar13;
  ushort uVar14;
  uint uVar15;
  ulong uVar16;
  _ALPC_MESSAGE_ATTRIBUTES *p_Var17;
  ulong64 uVar18;
  wchar_t *pwVar19;
  ulong64 local_res8;
  ulonglong local_res18 [2];
  void *in_stack_ffffffffffffffa8;
  
  uVar8 = param_7;
  uVar7 = param_6;
  param_6 = 0;
  local_res18[0] = (ulonglong)param_2 & 0xffffffff00000000;
  local_res8 = 0;
  param_7 = 0;
  pWVar13 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar13 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    WPP_SF_qqqPP((ulong64)pWVar13,(ushort)param_1,(_GUID *)param_2,param_1,in_stack_ffffffffffffffa8
                 ,param_3,uVar7,uVar8);
  }
  this->m_LpcCommPort = param_1;
  this->m_ReservedWithAlpc = param_8;
  uVar18 = uVar7;
  if (uVar7 <= uVar8) {
    uVar18 = uVar8;
  }
  this->m_MessageId = 0;
  pIVar2 = (IUMDFLPCCorePortInterface *)param_1->_padding_;
  uVar9 = (uint)this->_padding_;
  this->m_LpcCorePortInterface = pIVar2;
  if ((int)uVar9 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      uVar14 = 0x26;
LAB_140002d46:
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar14,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar9);
    }
  }
  else {
    uVar9 = CalculateMsgSize((ulong64)pWVar13,param_4,param_5,pIVar2,&param_7,&param_6,&local_res8,
                             (ulong *)local_res18);
    if ((int)uVar9 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        uVar14 = 0x27;
        goto LAB_140002d46;
      }
    }
    else {
      p_Var17 = (_ALPC_MESSAGE_ATTRIBUTES *)((longlong)&this->_padding_ + param_7);
      this->m_MessageAttrib = p_Var17;
      this->m_MessageAttribSize = param_6;
      this->m_SendMessageBodyLength = param_4;
      this->m_AlpcMessageHeader =
           (_PORT_MESSAGE *)((longlong)&p_Var17->AllocatedAttributes + param_6);
      this->m_ReplyMessageBodyLength = param_5;
      this->m_ReplyReceived = false;
      param_7 = 0;
      uVar9 = (**(code **)((longlong)*this->m_LpcCorePortInterface + 0x30))
                        (this->m_LpcCorePortInterface,local_res18[0] & 0xffffffff,p_Var17,param_6,
                         &param_7);
      if ((((int)uVar9 < 0) &&
          (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
         (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0' &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
        WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x34,
                 WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar9);
      }
      else if (-1 < (int)uVar9) {
        uVar16 = 0x20000000;
        uVar15 = 0x20000000;
        uVar9 = 0x20000000;
        if (param_3 != (_ALPC_SECURITY_ATTR *)0x0) {
          uVar16 = 0xa0000000;
          uVar15 = 0xa0000000;
          uVar9 = 0xa0000000;
        }
        if (uVar18 != 0) {
          uVar15 = uVar9 | 0x40000000;
          uVar16 = uVar15;
        }
        if ((uVar15 & this->m_MessageAttrib->AllocatedAttributes) == uVar15) {
          puVar1 = &this->m_MessageAttrib->ValidAttributes;
          *puVar1 = *puVar1 | 0x20000000;
          lVar10 = AlpcGetMessageAttribute(this->m_MessageAttrib,0x20000000);
          *(WudfLpcMessage **)(lVar10 + 8) = this;
          if (param_3 != (_ALPC_SECURITY_ATTR *)0x0) {
            puVar11 = (undefined8 *)AlpcGetMessageAttribute(this->m_MessageAttrib,0x80000000);
            p_Var6 = param_3->QoS;
            *puVar11 = *(undefined8 *)param_3;
            puVar11[1] = p_Var6;
            puVar11[2] = param_3->ContextHandle;
            if (puVar11[2] == 0) {
              WdfPlatform::UmdfDriverStop
                        (WdfInternalError,0x100000000000000,
                         L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
                         "TODO: Write something interesting here");
            }
            puVar1 = &this->m_MessageAttrib->ValidAttributes;
            *puVar1 = *puVar1 | 0x80000000;
          }
          p_Var3 = this->m_AlpcMessageHeader;
          uVar18 = this->m_SendMessageBodyLength;
          uVar4 = this->m_ReplyMessageBodyLength;
          (p_Var3->u1).Length = 0;
          (p_Var3->u2).ZeroInit = 0;
          (p_Var3->field2_0x8).ClientId.UniqueProcess = (void *)0x0;
          (p_Var3->field2_0x8).ClientId.UniqueThread = (void *)0x0;
          *(undefined8 *)&p_Var3->MessageId = 0;
          (p_Var3->field4_0x20).ClientViewSize = 0;
          (this->m_AlpcMessageHeader->u1).s1.DataLength = (short)this->m_SendMessageBodyLength;
          (this->m_AlpcMessageHeader->u1).s1.TotalLength =
               (short)this->m_SendMessageBodyLength + 0x28;
          if (param_8 == '\0') {
            (this->m_ReplyCallbackLock).Value = (void *)0x0;
LAB_140002d02:
            uVar9 = (**(code **)(this->_padding_ + 0x38))(&this->_padding_,uVar7,uVar8);
            if (-1 < (int)uVar9) {
              if (this->m_MessageAttrib->ValidAttributes != uVar16) {
                WdfPlatform::UmdfDriverStop
                          (WdfInternalError,0x100000000000000,
                           L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
                           "TODO: Write something interesting here");
              }
              goto LAB_140002da5;
            }
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
              uVar14 = 0x2c;
              goto LAB_140002d46;
            }
          }
          else {
            if (uVar18 + 0x28 <= uVar4 + 0x28) {
              uVar18 = uVar4;
            }
            lVar10 = this->m_LpcCommPort->_padding_;
            uVar9 = (**(code **)((longlong)*this->m_LpcCorePortInterface + 0x50))
                              (this->m_LpcCorePortInterface,lVar10,0,uVar18 + 0x28,
                               &this->m_MessageId);
            if ((int)uVar9 < 0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
                 (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                uVar14 = 0x2a;
                goto LAB_140002d46;
              }
            }
            else {
              WVar12 = WdfPlatformEvent::WudfAllocateEvent(SynchronizationEvent,(ulong)lVar10);
              (this->m_ReplyCallbackLock).Value = WVar12.Value;
              if (WVar12.Value != (void *)0x0) {
                KeSetEvent(WVar12.Value,0,0);
                goto LAB_140002d02;
              }
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2b,
                        WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
              }
              uVar9 = 0xc000009a;
            }
          }
        }
        else {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x29,
                    WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
          }
          uVar9 = 0xc000000d;
        }
        goto LAB_140002d59;
      }
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        uVar14 = 0x28;
        goto LAB_140002d46;
      }
    }
  }
LAB_140002d59:
  pvVar5 = (this->m_ReplyCallbackLock).Value;
  if (pvVar5 != (void *)0x0) {
    ExFreePoolWithTag(pvVar5,0);
    (this->m_ReplyCallbackLock).Value = (void *)0x0;
  }
LAB_140002da5:
  uVar15 = (uint)this->_padding_;
  if (((int)uVar15 < 0) && (uVar15 != uVar9)) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "constructor already failed\n");
  }
  *(uint *)&this->_padding_ = uVar9;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pwVar19 = L"succeeded";
    if ((int)uVar9 < 0) {
      pwVar19 = L"failed";
    }
    WPP_SF_S(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2d,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,pwVar19);
  }
  return;
}



===== AllocateLock @ 140002e50 =====

WUDF_LOCK __cdecl WdfPlatformLock::AllocateLock(void)

{
  int iVar1;
  WUDF_LOCK WVar2;
  
  WVar2.Value = (void *)ExAllocatePool2(0x40,0x68,0x7a444d55);
  if ((WVar2.Value != (void *)0x0) && (iVar1 = ExInitializeResourceLite(WVar2.Value), iVar1 < 0)) {
    ExFreePoolWithTag(WVar2.Value,0);
    WVar2.Value = (void *)0x0;
  }
  return (WUDF_LOCK)WVar2.Value;
}



===== InitializeMessageAttribute @ 140002eb0 =====

long __thiscall
WdfLpcCorePortInterface::InitializeMessageAttribute
          (WdfLpcCorePortInterface *this,ulong param_1,_ALPC_MESSAGE_ATTRIBUTES *param_2,
          ulong64 param_3,ulong64 *param_4)

{
  long lVar1;
  
  lVar1 = AlpcInitializeMessageAttribute(param_1,param_2,param_3,param_4);
  return lVar1;
}



===== CreateUmdfLpcMessage @ 140002ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
RdFdoDevice::CreateUmdfLpcMessage
          (RdFdoDevice *this,ulong64 param_1,ulong64 param_2,ulong64 param_3,_WUDFMESSAGE param_4,
          IUMDFLPCCommPortInterface *param_5,IUMDFLPCMessage **param_6)

{
  longlong *plVar1;
  int iVar2;
  _WUDFMESSAGE *p_Var3;
  IUMDFLPCMessage *local_res20;
  
  local_res20 = (IUMDFLPCMessage *)0x0;
  plVar1 = *(longlong **)(this->_padding_ + 0x70);
  iVar2 = (**(code **)(*plVar1 + 0x48))(plVar1,&local_res20,param_1,param_2,param_5,0,0,0,1);
  if (iVar2 < 0) {
    if (local_res20 != (IUMDFLPCMessage *)0x0) {
      (**(code **)((longlong)*local_res20 + 8))();
    }
  }
  else {
    p_Var3 = (_WUDFMESSAGE *)(**(code **)((longlong)*local_res20 + 0x18))(local_res20,param_1);
    *p_Var3 = param_4;
    *param_6 = local_res20;
  }
  return iVar2;
}



===== WdfGetLpcMessage @ 140002f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcInterface::WdfGetLpcMessage
          (WdfLpcInterface *this,IUMDFLPCMessage **param_1,ulong64 param_2,ulong64 param_3,
          IUMDFLPCCommPortInterface *param_4,ulong64 param_5,ulong64 param_6,
          _ALPC_SECURITY_ATTR *param_7,uchar param_8)

{
  WudfLpcMessage *pWVar1;
  uint uVar2;
  WdfLpcCommPort *pWVar3;
  
  pWVar3 = (WdfLpcCommPort *)(param_4 + -0x15);
  if (param_4 == (IUMDFLPCCommPortInterface *)0x0) {
    pWVar3 = (WdfLpcCommPort *)0x0;
  }
  pWVar1 = WudfLpcMessage::operator_new
                     ((ulong64)this,param_2,param_3,(IUMDFLPCCorePortInterface *)pWVar3->_padding_);
  if ((pWVar1 == (WudfLpcMessage *)0x0) ||
     (pWVar1 = WudfLpcMessage::WudfLpcMessage
                         (pWVar1,pWVar3,param_8,param_2,param_3,param_5,param_6,param_7),
     pWVar1 == (WudfLpcMessage *)0x0)) {
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0 &&
        (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xd,
              WPP_02695a365c923798242d82f859d29eea_Traceguids);
    }
    uVar2 = 0xc0000017;
  }
  else {
    uVar2 = (uint)pWVar1->_padding_;
    if (-1 < (int)uVar2) {
      *param_1 = (IUMDFLPCMessage *)&pWVar1->_padding_;
      return uVar2;
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xe,
               WPP_02695a365c923798242d82f859d29eea_Traceguids,uVar2);
    }
    (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
  }
  *param_1 = (IUMDFLPCMessage *)0x0;
  return uVar2;
}



===== operator_new @ 140003100 =====

void * __cdecl
WudfLpcMessage::operator_new
          (ulong64 param_1,ulong64 param_2,ulong64 param_3,IUMDFLPCCorePortInterface *param_4)

{
  uchar *puVar1;
  uchar *puVar2;
  uint uVar3;
  void *pvVar4;
  WPP_PROJECT_CONTROL_BLOCK *pWVar5;
  ushort uVar6;
  _GUID *p_Var7;
  undefined1 *puVar8;
  ulonglong local_res8;
  undefined1 *local_res10;
  _GUID *local_28;
  _GUID *local_20;
  
  pvVar4 = (void *)0x0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_28 = (_GUID *)0x0;
  local_20 = (_GUID *)0x0;
  local_res10 = (undefined1 *)0x0;
  pWVar5 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar5 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    WPP_SF_PPP((ulong64)pWVar5,(ushort)param_2,(_GUID *)param_3,(ulong64)param_4,param_2,param_3);
  }
  if (param_2 == 0) {
    pWVar5 = (WPP_PROJECT_CONTROL_BLOCK *)0x0;
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",
               "TODO: Write something interesting here");
  }
  uVar3 = CalculateMsgSize((ulong64)pWVar5,param_2,param_3,param_4,(ulong64 *)&local_res10,
                           (ulong64 *)&local_28,(ulong64 *)&local_20,(ulong *)&local_res8);
  if ((int)uVar3 < 0) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return (void *)0x0;
    }
    if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2f,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar3);
    }
    goto LAB_14000331e;
  }
  puVar1 = local_28->Data4 + (longlong)(local_res10 + -8);
  if (puVar1 < local_res10) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return (void *)0x0;
    }
    if ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14000331e;
    uVar6 = 0x30;
    p_Var7 = local_28;
    puVar8 = local_res10;
  }
  else {
    puVar2 = local_20->Data4 + (longlong)(puVar1 + -8);
    if (puVar1 <= puVar2) {
      pvVar4 = (void *)ExAllocatePool2(0x40,puVar2,0x69444d55);
      if (pvVar4 == (void *)0x0) {
        if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
          return (void *)0x0;
        }
        if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x32,
                   WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,(uint)puVar2);
        }
      }
      else {
        memset();
      }
      goto LAB_14000331e;
    }
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return (void *)0x0;
    }
    if ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14000331e;
    uVar6 = 0x31;
    p_Var7 = local_20;
    puVar8 = (undefined1 *)0xffffffffffffffff;
  }
  WPP_SF_IId(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar6,p_Var7,(ulong64)puVar8,
             (ulong64)p_Var7,-0x3fffff6b);
LAB_14000331e:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x33,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,pvVar4);
  }
  return pvVar4;
}



===== RtlStringCchCopyW @ 140003380 =====

long __cdecl RtlStringCchCopyW(wchar_t *param_1,ulong64 param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  long lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (0x7ffffffe < param_2 - 1) {
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
    return -0x3ffffff3;
  }
  lVar5 = 0x7ffffffe - param_2;
  lVar4 = (longlong)param_3 - (longlong)param_1;
  do {
    if ((lVar5 + param_2 == 0) || (wVar1 = *(wchar_t *)(lVar4 + (longlong)param_1), wVar1 == L'\0'))
    break;
    *param_1 = wVar1;
    param_1 = param_1 + 1;
    param_2 = param_2 - 1;
  } while (param_2 != 0);
  pwVar3 = param_1 + -1;
  if (param_2 != 0) {
    pwVar3 = param_1;
  }
  *pwVar3 = L'\0';
  lVar2 = -0x7ffffffb;
  if (param_2 != 0) {
    lVar2 = 0;
  }
  return lVar2;
}



===== WdfObjectLock @ 1400033f0 =====

WdfObjectLock * __thiscall WdfObjectLock::WdfObjectLock(WdfObjectLock *this)

{
  int iVar1;
  WUDF_LOCK WVar2;
  int iVar3;
  
  *(undefined4 *)&this->_padding_ = 0;
  (this->m_Lock).Value = (void *)0x0;
  WVar2 = WdfPlatformLock::AllocateLock();
  (this->m_Lock).Value = WVar2.Value;
  iVar1 = (int)this->_padding_;
  iVar3 = -0x3fffff66;
  if (WVar2.Value != (void *)0x0) {
    iVar3 = 0;
  }
  if ((iVar1 < 0) && (iVar1 != iVar3)) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "constructor already failed\n");
  }
  *(int *)&this->_padding_ = iVar3;
  return this;
}



===== ~CUMDFUnknown @ 140003470 =====

void __thiscall CUMDFUnknown::~CUMDFUnknown(CUMDFUnknown *this)

{
  this->_padding_ = (longlong)&___7CUMDFUnknown__6B_;
  if (this->m_RefCount != 0) {
    WdfPlatform::UmdfDriverStop
              (WdfInternalError,0x100000000000000,
               L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
               "deleting object with non-zero refCount");
  }
  return;
}



===== UmdfDriverStop @ 1400034b0 =====

void __cdecl
WdfPlatform::UmdfDriverStop
          (WdfDriverStopType param_1,ulong64 param_2,wchar_t *param_3,char *param_4)

{
  RtlAssert("Failed test","Unknown",0);
  return;
}



===== RtlStringCchLengthW @ 1400034e0 =====

long __cdecl RtlStringCchLengthW(wchar_t *param_1,ulong64 param_2,ulong64 *param_3)

{
  long lVar1;
  
  if ((param_1 == (wchar_t *)0x0) || (0x7fffffff < param_2)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = RtlStringLengthWorkerW(param_1,param_2,param_3);
    if (-1 < lVar1) {
      return lVar1;
    }
  }
  if (param_3 != (ulong64 *)0x0) {
    *param_3 = 0;
  }
  return lVar1;
}



===== RtlStringLengthWorkerW @ 140003520 =====

long __cdecl RtlStringLengthWorkerW(wchar_t *param_1,ulong64 param_2,ulong64 *param_3)

{
  uint uVar1;
  ulong64 uVar2;
  
  uVar2 = param_2;
  for (; (uVar2 != 0 && (*param_1 != L'\0')); param_1 = param_1 + 1) {
    uVar2 = uVar2 - 1;
  }
  uVar1 = ~-(uint)(uVar2 != 0) & 0xc000000d;
  if (param_3 != (ulong64 *)0x0) {
    if (uVar2 != 0) {
      *param_3 = param_2 - uVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== CalculateMsgSize @ 140003570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

long __cdecl
WudfLpcMessage::CalculateMsgSize
          (ulong64 param_1,ulong64 param_2,ulong64 param_3,IUMDFLPCCorePortInterface *param_4,
          ulong64 *param_5,ulong64 *param_6,ulong64 *param_7,ulong *param_8)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  _GUID *p_Var4;
  uint uVar5;
  WPP_PROJECT_CONTROL_BLOCK *pWVar6;
  ushort uVar7;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var8;
  long lVar9;
  _GUID *p_Var10;
  _GUID *local_res8;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  uVar1 = param_2 + 0x28;
  bVar3 = false;
  local_res8 = (_GUID *)0x0;
  if ((uVar1 < 0x28) || (uVar1 < param_2)) {
    if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
       ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) ||
        (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)))) goto LAB_14000383b;
    uVar7 = 0x1d;
  }
  else {
    pWVar6 = WPP_GLOBAL_Control;
    if (0xffff < uVar1) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        p_Var8 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1e;
LAB_1400035df:
        param_4 = (IUMDFLPCCorePortInterface *)(param_2 & 0xffffffff);
        pWVar6 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
        WPP_SF_D((ulong64)pWVar6,(ushort)p_Var8,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,
                 (uint)param_2);
        param_2 = (ulong64)p_Var8;
      }
LAB_1400035f2:
      WudfVerifyStatic((WdfComponentType)pWVar6,
                       (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)param_2,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",(ulong)param_4,
                       in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8
                       ,in_stack_ffffffffffffffe0,"TODO: Write something interesting here",false);
      goto LAB_14000383b;
    }
    uVar2 = param_3 + 0x28;
    if ((uVar2 < 0x28) || (uVar2 < param_3)) {
      if ((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
         ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) ||
          (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)))) goto LAB_14000383b;
      uVar7 = 0x1f;
    }
    else {
      if (0xffff < uVar2) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          p_Var8 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x20;
          param_2 = param_3;
          goto LAB_1400035df;
        }
        goto LAB_1400035f2;
      }
      if (uVar1 <= uVar2) {
        param_2 = param_3;
      }
      uVar5 = (**(code **)((longlong)*param_4 + 0x30))(param_4,0xe0000000,0,0,&local_res8);
      p_Var4 = local_res8;
      if (uVar5 != 0xc0000023) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x21,
                   WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar5);
        }
        goto LAB_14000383b;
      }
      if ((_GUID *)0x7 < local_res8) {
        p_Var10 = (_GUID *)((ulonglong)((longlong)&local_res8->Data3 + 1U) & 0xfffffffffffffff8);
        if (p_Var10 < local_res8) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            local_res8 = p_Var10;
            WPP_SF_ii(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x24,p_Var10,(long64)p_Var4
                      ,(long64)p_Var10);
          }
        }
        else {
          bVar3 = true;
          *param_5 = 0xe0;
          *param_6 = (ulong64)p_Var10;
          *param_7 = param_2 + 0x2f & 0xfffffffffffffff8;
          *param_8 = 0xe0000000;
        }
        goto LAB_14000383b;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14000383b;
      uVar7 = 0x22;
    }
  }
  WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar7,
          WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
LAB_14000383b:
  lVar9 = 0;
  if (!bVar3) {
    lVar9 = -0x3fffffff;
  }
  return lVar9;
}



===== ~WdfObjectLock @ 140003860 =====

void __thiscall WdfObjectLock::~WdfObjectLock(WdfObjectLock *this)

{
  void *pvVar1;
  
  pvVar1 = (this->m_Lock).Value;
  if (pvVar1 != (void *)0x0) {
    ExDeleteResourceLite(pvVar1);
    ExFreePoolWithTag(pvVar1,0);
  }
  return;
}



===== __report_gsfailure @ 1400038b0 =====

void __cdecl __report_gsfailure(ulong64 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,param_1,__security_cookie,__security_cookie_complement,0);
}



===== _wcsnicmp @ 1400038e3 =====

int __cdecl _wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400038e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _wcsnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== _purecall @ 140003900 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140003900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== RdDrvMgrCtrlDevice @ 140003914 =====

RdDrvMgrCtrlDevice * __thiscall
RdDrvMgrCtrlDevice::RdDrvMgrCtrlDevice
          (RdDrvMgrCtrlDevice *this,RdDriver *param_1,wchar_t *param_2,void *param_3)

{
  uint *puVar1;
  uint uVar2;
  void *pvVar3;
  ushort uVar4;
  RdDriver *pRVar5;
  _GUID *p_Var6;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffb0;
  void *pvVar7;
  
  pvVar7 = (void *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20),0x22);
  pRVar5 = param_1;
  p_Var6 = (_GUID *)param_2;
  RdDevice::RdDevice((RdDevice *)this,param_1,param_2,param_2,&SDDL_DEVOBJ_KERNEL_ONLY,0x22,
                     (WdfObject *)param_1,RdTypeContolDriverManager,'\0');
  this->_padding_ = (longlong)&___7RdDrvMgrCtrlDevice__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    pvVar7 = param_3;
    WPP_SF_qSq((WPP_GLOBAL_Control->Control).Logger,(ushort)pRVar5,p_Var6,param_1,param_2,param_3);
  }
  local_res8 = 0;
  this->m_ServiceProcessId = param_3;
  uVar2 = (uint)this->_padding_;
  if ((int)uVar2 < 0) goto LAB_140003b41;
  pvVar3 = WdfPlatformSecurity::WudfAllocateSecurityDescriptor
                     ((void **)(*(longlong *)SeExports_exref + 0x108),1);
  if (pvVar3 == (void *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,
              WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = ObOpenObjectByPointer
                      (this->_padding_,0x200,0,0x40000,0,(ulonglong)pvVar7 & 0xffffffffffffff00,
                       &local_res8);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 8) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        uVar4 = 0xc;
LAB_140003a83:
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar4,
                 WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,uVar2);
      }
    }
    else {
      uVar2 = ZwSetSecurityObject(local_res8,4,pvVar3);
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar4 = 0xd;
          goto LAB_140003a83;
        }
      }
      else {
        *(undefined1 *)(this->_padding_ + 0x4c) = 1;
        puVar1 = (uint *)(this->_padding_ + 0x30);
        *puVar1 = *puVar1 | 4;
        puVar1 = (uint *)(this->_padding_ + 0x30);
        *puVar1 = *puVar1 & 0xffffff7f;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
           (3 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0xe,
                   WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,(wchar_t *)this->_padding_);
        }
      }
    }
    operator_delete(pvVar3);
  }
  if (local_res8 != 0) {
    ZwClose();
  }
LAB_140003b41:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar2);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xf,WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids
           );
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140003ba0 =====

void * __thiscall
RdDrvMgrCtrlDevice::_scalar_deleting_destructor_(RdDrvMgrCtrlDevice *this,uint param_1)

{
  this->_padding_ = (longlong)&___7RdDrvMgrCtrlDevice__6B_;
  RdDevice::~RdDevice((RdDevice *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AddRef @ 140003be0 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

ulong __thiscall CUMDFUnknown::AddRef(CUMDFUnknown *this)

{
  ulong *puVar1;
  ulong uVar2;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *in_RDX;
  uint uVar3;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  LOCK();
  puVar1 = &this->m_RefCount;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  UNLOCK();
  uVar3 = uVar2 + 1;
  WudfVerifyStatic(1 < uVar3,in_RDX,
                   L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"referencing deleted object",1 < uVar3);
  return uVar3;
}



===== AreYouThis @ 140003c30 =====

uchar __thiscall WdfObject::AreYouThis(WdfObject *this,wchar_t *param_1)

{
  wchar_t wVar1;
  wchar_t wVar2;
  longlong lVar3;
  
  lVar3 = (longlong)this->m_Name - (longlong)param_1;
  do {
    wVar1 = *param_1;
    wVar2 = *(wchar_t *)((longlong)param_1 + lVar3);
    if (wVar1 != wVar2) break;
    param_1 = param_1 + 1;
  } while (wVar2 != L'\0');
  return wVar1 == wVar2;
}



===== Find @ 140003c58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

RdFdoDevice * __thiscall
WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>::Find
          (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *this,RdFdoDeviceParameters *param_1,
          uchar param_2,uchar param_3,uchar *param_4,long *param_5)

{
  wchar_t wVar1;
  wchar_t wVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  RdFdoDevice *pRVar5;
  code *pcVar6;
  RdFdoDevice *pRVar7;
  uchar uVar8;
  
  lVar3 = this->_padding_;
  uVar8 = '\0';
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar3,1);
  pRVar5 = (RdFdoDevice *)this->m_List;
  pRVar7 = pRVar5;
  if (pRVar5 == (RdFdoDevice *)0x0) {
LAB_140003cee:
    if (param_2 == '\0') goto LAB_140003d56;
    pRVar5 = (RdFdoDevice *)ExAllocatePool2(this->m_PoolFlags,0x198,this->m_Tag);
    if (pRVar5 == (RdFdoDevice *)0x0) goto LAB_140003d56;
    pRVar5 = RdFdoDevice::RdFdoDevice(pRVar5,param_1,this,(WdfObject *)this);
    if (pRVar5 == (RdFdoDevice *)0x0) goto LAB_140003d56;
    if (-1 < (int)pRVar5->_padding_) {
      uVar8 = '\x01';
      pRVar7 = pRVar5;
      goto LAB_140003d56;
    }
    (**(code **)(pRVar5->_padding_ + 0x28))(pRVar5);
    pcVar6 = *(code **)(pRVar5->_padding_ + 8);
  }
  else {
    do {
      pwVar4 = param_1->RdDeviceName;
      do {
        wVar1 = *pwVar4;
        wVar2 = *(wchar_t *)
                 ((longlong)pwVar4 + (pRVar5->_padding_ - (longlong)param_1->RdDeviceName));
        if (wVar1 != wVar2) break;
        pwVar4 = pwVar4 + 1;
      } while (wVar2 != L'\0');
    } while (((wVar1 != wVar2) || ((char)pRVar5->_padding_ != '\0')) &&
            (pRVar5 = (RdFdoDevice *)pRVar5->_padding_, pRVar5 != (RdFdoDevice *)0x0));
    pRVar7 = pRVar5;
    if (pRVar5 == (RdFdoDevice *)0x0) goto LAB_140003cee;
    pcVar6 = *(code **)pRVar5->_padding_;
  }
  (*pcVar6)(pRVar5);
LAB_140003d56:
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if (param_4 != (uchar *)0x0) {
    *param_4 = uVar8;
  }
  return pRVar7;
}



===== QueryInterface @ 140003db0 =====

long __thiscall CUMDFUnknown::QueryInterface(CUMDFUnknown *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)param_1 + -0x445062f89e156ea5;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x23a7a3508bc713b0;
  }
  *param_2 = (void *)(-(ulonglong)(lVar1 == 0) & (ulonglong)this);
  return ~-(uint)(lVar1 == 0) & 0xc00002b9;
}



===== RdCleanup @ 140003e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDevice::RdCleanup(RdDevice *this,_IRP *param_1)

{
  long lVar1;
  
  lVar1 = (**(code **)(this->_padding_ + 0x48))();
  return lVar1;
}



===== RdClose @ 140003e20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDrvMgrCtrlDevice::RdClose(RdDrvMgrCtrlDevice *this,_IRP *param_1)

{
  (param_1->IoStatus).field0_0x0.Status = 0;
  IofCompleteRequest(param_1,0);
  (**(code **)(this->_padding_ + 0xa8))(this,param_1,2);
  return 0;
}



===== RdCreate @ 140003e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDrvMgrCtrlDevice::RdCreate(RdDrvMgrCtrlDevice *this,_IRP *param_1)

{
  uint uVar1;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x10,
             WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,param_1);
  }
  uVar1 = (**(code **)(this->_padding_ + 0xb0))(this,this);
  (param_1->IoStatus).field0_0x0.Status = uVar1;
  IofCompleteRequest(param_1,0);
  (**(code **)(this->_padding_ + 0xa8))(this,param_1,0);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x12,
             WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,uVar1);
  }
  return uVar1;
}



===== RdDeviceIoControl @ 140003f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __thiscall RdDrvMgrCtrlDevice::RdDeviceIoControl(RdDrvMgrCtrlDevice *this,_IRP *param_1)

{
  ulong *puVar1;
  int iVar2;
  _IRP *p_Var3;
  _EPROCESS *p_Var4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  RdFdoDevice *this_00;
  RdProcess *pRVar8;
  void *pvVar9;
  ulong64 uVar10;
  byte bVar11;
  ushort uVar12;
  uchar uVar13;
  uchar uVar14;
  wchar_t *pwVar15;
  ulonglong uVar16;
  uint uVar17;
  undefined1 auStackY_1b8 [32];
  long *plVar18;
  byte local_188;
  uchar local_187;
  RdDrvMgrCtrlDevice *local_180;
  ulong64 *local_178;
  ulong64 local_170;
  _EPROCESS *local_168;
  longlong local_160;
  RdProcessParameters local_158;
  RdFdoDeviceParameters local_120;
  wchar_t *local_e8;
  ulong64 local_e0 [2];
  char local_d0 [8];
  wchar_t *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined1 local_b0;
  wchar_t *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined1 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  undefined8 local_78;
  bool local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_178 = (ulong64 *)0x0;
  local_120.RdDriver = (RdDriver *)0x0;
  local_120.RdDeviceName = (wchar_t *)0x0;
  local_120.PhysicalDeviceObject = (_DEVICE_OBJECT *)0x0;
  local_120.ProcessTimeout = 0;
  local_120.IsCompanionMode = '\0';
  local_120._29_3_ = 0;
  local_120.KernelServiceName = (wchar_t *)0x0;
  local_120.CompanionCallback = (IDeviceCompanionCallbacks *)0x0;
  local_188 = 0;
  local_180 = this;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x13,
             WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,param_1);
  }
  pvVar9 = (param_1->Tail).Apc.SystemArgument1;
  if (*(int *)((longlong)pvVar9 + 0x18) != -0x7ffe7c00) {
    uVar5 = 0xc0000002;
    goto LAB_140004779;
  }
  lVar7 = this->_padding_;
  if (*(longlong *)(lVar7 + 0x1c8) == 0) {
    uVar6 = PsGetCurrentProcess();
    *(undefined8 *)(lVar7 + 0x1c8) = uVar6;
  }
  uVar5 = *(uint *)((longlong)pvVar9 + 0x10);
  p_Var3 = (param_1->AssociatedIrp).MasterIrp;
  if (uVar5 == 0) {
    uVar5 = 0xc0000023;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140004779;
    uVar12 = 0x14;
  }
  else {
    if (0x46c < (ulonglong)uVar5) {
      uVar16 = (ulonglong)uVar5 - 0x46c;
      if ((uVar16 & 1) == 0) {
        if (uVar16 < 0x10000) {
          uVar16 = uVar16 >> 1;
          pwVar15 = (wchar_t *)
                    ((longlong)&p_Var3[5].Overlay.AsynchronousParameters.field0_0x0.UserApcRoutine +
                    4);
          uVar5 = RtlStringCchLengthW(pwVar15,uVar16,(ulong64 *)&local_178);
          if ((int)uVar5 < 0) {
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
               (1 < (WPP_GLOBAL_Control->Control).Level)) {
              uVar10 = (WPP_GLOBAL_Control->Control).Logger;
              uVar12 = 0x18;
LAB_1400041b3:
              WPP_SF_Sd(uVar10,uVar12,WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,pwVar15,uVar5)
              ;
            }
            goto LAB_140004779;
          }
          if (uVar16 == (longlong)local_178 + 1U) {
            iVar2 = *(int *)&p_Var3[5].Overlay.AsynchronousParameters.field0_0x0.UserApcRoutine;
            local_e8 = L"IoEventPortName";
            local_187 = iVar2 != 0;
            local_e0[0] = 0x18;
            local_e0[1] = 0x100;
            local_c8 = L"IoCancelPortName";
            local_d0[0] = '\x01';
            local_a8 = L"SystemEventPortName";
            local_c0 = 0x118;
            local_88 = L"NonStateChangingEventPortName";
            local_b8 = 0x100;
            local_70 = iVar2 == 0;
            local_b0 = 1;
            local_a0 = 0x218;
            local_98 = 0x100;
            local_90 = 1;
            local_80 = 0x318;
            local_78 = 0x100;
            local_68 = L"LifetimeId";
            local_60 = 0x418;
            local_58 = 0x4e;
            local_50 = 1;
            for (uVar17 = 0; uVar17 < 5; uVar17 = uVar17 + 1) {
              uVar16 = (ulonglong)uVar17;
              if (local_d0[uVar16 * 0x20] != '\0') {
                local_170 = 0;
                uVar5 = RtlStringCbLengthW((wchar_t *)
                                           ((longlong)(p_Var3->Tail).Apc.Reserved +
                                           (local_e0[uVar16 * 4] - 0x98)),local_e0[uVar16 * 4 + 1],
                                           &local_170);
                if ((int)uVar5 < 0) {
                  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                      (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
                     ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140004779;
                  uVar12 = 0x1a;
                }
                else {
                  if (local_170 != 0) goto LAB_140004309;
                  uVar5 = 0xc000000d;
                  if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                      (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
                     ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140004779;
                  uVar12 = 0x1b;
                }
                pwVar15 = (&local_e8)[uVar16 * 4];
                uVar10 = (WPP_GLOBAL_Control->Control).Logger;
                goto LAB_1400041b3;
              }
LAB_140004309:
            }
            uVar14 = '\x01';
            plVar18 = (long *)0x0;
            local_168 = (_EPROCESS *)0x0;
            uVar5 = ObReferenceObjectByHandle(p_Var3->MdlAddress,0x1fffff);
            p_Var4 = local_168;
            if ((int)uVar5 < 0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                 (1 < (WPP_GLOBAL_Control->Control).Level)) {
                uVar12 = 0x1c;
LAB_1400043f7:
                WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar12,
                         WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,uVar5);
              }
            }
            else {
              lVar7 = IoAllocateWorkItem(*(undefined8 *)(this->_padding_ + 0x58));
              local_160 = lVar7;
              if (lVar7 == 0) {
                uVar5 = 0xc000009a;
                if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                   (1 < (WPP_GLOBAL_Control->Control).Level)) {
                  uVar12 = 0x1d;
                  goto LAB_1400043f7;
                }
              }
              else {
                local_120.RdDriver = (RdDriver *)this->_padding_;
                local_120.PhysicalDeviceObject = (_DEVICE_OBJECT *)0x0;
                uVar13 = '\0';
                local_120.RdDeviceName = pwVar15;
                this_00 = WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>::Find
                                    ((local_120.RdDriver)->m_RdFdoDeviceList,&local_120,'\0',uVar14,
                                     (uchar *)0x0,plVar18);
                if (this_00 == (RdFdoDevice *)0x0) {
                  if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                      (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                     (1 < (WPP_GLOBAL_Control->Control).Level)) {
                    WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,0x1e,
                              WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,pwVar15,uVar5);
                  }
                  uVar5 = 0xc0000225;
                  IoFreeWorkItem(lVar7);
                }
                else {
                  this_00->m_CompanionType =
                       *(_WUDF_SERVICE_TYPE *)
                        &p_Var3[5].Overlay.AsynchronousParameters.field0_0x0.UserApcRoutine;
                  local_158.m_EProcess = p_Var4;
                  bVar11 = (byte)*(undefined4 *)&p_Var3->field_0x14;
                  this_00->m_DebugModeFlags =
                       (DEBUG_MODE_FLAGS)
                       (((bVar11 & 5) != 5) - 1U & 4 |
                       ((bVar11 & 3) != 3) - 1U & 2 | (local_188 ^ (local_188 ^ bVar11) & 1) & 0xf9)
                  ;
                  local_158.m_LifetimeId = (wchar_t *)&p_Var3[5].MdlAddress;
                  local_158.m_IoEventPortName = (wchar_t *)&p_Var3->AssociatedIrp;
                  local_158.m_IoCancelEventPortName = (wchar_t *)&p_Var3[1].field15_0x48;
                  local_158.m_SystemEventPortName = (wchar_t *)&p_Var3[2].Tail;
                  local_158.m_NonStateChangingEventPortName =
                       (wchar_t *)&p_Var3[3].Tail.Overlay.ListEntry;
                  local_158.m_HostConnectTimeoutSeconds = p_Var3->Flags;
                  local_158.m_ProcessIsCompanion = local_187;
                  pRVar8 = WdfObjectList<RdProcess,RdProcessParameters>::Find
                                     (*(WdfObjectList<RdProcess,RdProcessParameters> **)
                                       (local_180->_padding_ + 0xb8),&local_158,uVar13,uVar14,
                                      &local_188,plVar18);
                  if (pRVar8 == (RdProcess *)0x0) {
                    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                        (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                       (1 < (WPP_GLOBAL_Control->Control).Level)) {
                      WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,0x1f,
                                WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,pwVar15,uVar5);
                    }
                    uVar5 = 0xc0000225;
                  }
                  else {
                    uVar5 = RdFdoDevice::RdSetHostProcess(this_00,pRVar8);
                    if ((int)uVar5 < 0) {
                      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
                          && (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                         (1 < (WPP_GLOBAL_Control->Control).Level)) {
                        WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,0x20,
                                  WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,pwVar15,uVar5);
                      }
                    }
                    else {
                      uVar17 = p_Var3->Flags;
                      if (pRVar8->m_HostProcessTimeoutSeconds < uVar17) {
                        pRVar8->m_HostProcessTimeoutSeconds = uVar17;
                        (pRVar8->m_HostProcessTimeoutInTimerUnits).QuadPart =
                             (ulonglong)uVar17 * -10000000;
                        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control
                             ) && (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
                           (3 < (WPP_GLOBAL_Control->Control).Level)) {
                          pvVar9 = (void *)PsGetProcessId(pRVar8->m_EProcess);
                          WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x19,
                                    WPP_95aa3d4914343f637323421378a17a4a_Traceguids,pvVar9,uVar17);
                        }
                      }
                      bVar11 = (byte)*(uint *)&p_Var3->field_0x14;
                      if ((*(uint *)&p_Var3->field_0x14 & 1) != 0) {
                        LOCK();
                        (pRVar8->m_DebugModeCounter).Enabled =
                             (pRVar8->m_DebugModeCounter).Enabled + 1;
                        UNLOCK();
                        if ((((bVar11 & 3) != 3) - 1U & 2) != 0) {
                          LOCK();
                          puVar1 = &(pRVar8->m_DebugModeCounter).DisablePooling;
                          *puVar1 = *puVar1 + 1;
                          UNLOCK();
                        }
                        if ((((bVar11 & 5) != 5) - 1U & 4) != 0) {
                          LOCK();
                          puVar1 = &(pRVar8->m_DebugModeCounter).DisableTimeouts;
                          *puVar1 = *puVar1 + 1;
                          UNLOCK();
                        }
                      }
                    }
                  }
                  IoQueueWorkItemEx(local_160,RdFdoReleaseWorker,1,this_00);
                  if (pRVar8 != (RdProcess *)0x0) {
                    (**(code **)(pRVar8->_padding_ + 8))(pRVar8);
                  }
                }
                this = local_180;
              }
            }
            if (p_Var4 != (_EPROCESS *)0x0) {
              ObfDereferenceObject(p_Var4);
            }
            goto LAB_140004779;
          }
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x19,
                      WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,(int)uVar16,(int)local_178);
          }
        }
        else if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                 (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x17,
                   WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,(uint)uVar16);
        }
      }
      else if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
               (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
              (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x16,
                WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids);
      }
      uVar5 = 0xc000000d;
      goto LAB_140004779;
    }
    uVar5 = 0xc000000d;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140004779;
    uVar12 = 0x15;
  }
  WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar12,
          WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids);
LAB_140004779:
  (param_1->IoStatus).field0_0x0.Status = uVar5;
  IofCompleteRequest(param_1,0);
  (**(code **)(this->_padding_ + 0xa8))(this,param_1,0xe);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x21,
             WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,uVar5);
  }
  return uVar5;
}



===== RdFastIoDeviceIoControl @ 140004820 =====

uchar __thiscall
RdDevice::RdFastIoDeviceIoControl
          (RdDevice *this,_FILE_OBJECT *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5,ulong param_6,_IO_STATUS_BLOCK *param_7)

{
  return '\0';
}



===== RdFdoReleaseWorker @ 140004830 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
RdDrvMgrCtrlDevice::RdFdoReleaseWorker(void *param_1,void *param_2,_IO_WORKITEM *param_3)

{
  (**(code **)(*(longlong *)param_2 + 8))(param_2);
  IoFreeWorkItem(param_3);
  return;
}



===== RdQuerySetInformation @ 140004870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDrvMgrCtrlDevice::RdQuerySetInformation(RdDrvMgrCtrlDevice *this,_IRP *param_1)

{
  long lVar1;
  
  if (*(char *)(param_1->Tail).Apc.SystemArgument1 == '\x05') {
    lVar1 = -0x3fffff45;
    (param_1->IoStatus).field0_0x0.Status = -0x3fffff45;
    IofCompleteRequest(param_1,0);
    (**(code **)(this->_padding_ + 0xa8))(this,param_1,5);
  }
  else {
    lVar1 = (**(code **)(this->_padding_ + 0x48))();
  }
  return lVar1;
}



===== ReleaseRemoveLock @ 1400048f0 =====

void __thiscall
RdDrvMgrCtrlDevice::ReleaseRemoveLock(RdDrvMgrCtrlDevice *this,void *param_1,uchar param_2)

{
  if (param_2 == '\x02') {
    IoReleaseRemoveLockEx(this->_padding_,this,0x20);
  }
  else {
    RdDevice::ReleaseRemoveLock((RdDevice *)this,param_1,param_2);
  }
  return;
}



===== RtlStringCbLengthW @ 14000492c =====

long __cdecl RtlStringCbLengthW(wchar_t *param_1,ulong64 param_2,ulong64 *param_3)

{
  long lVar1;
  ulong64 uVar2;
  ulong64 local_res8 [4];
  
  uVar2 = 0;
  local_res8[0] = 0;
  if ((param_1 == (wchar_t *)0x0) || (0x7fffffff < param_2 >> 1)) {
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar1 = RtlStringLengthWorkerW(param_1,param_2 >> 1,local_res8);
    uVar2 = local_res8[0];
  }
  if (param_3 != (ulong64 *)0x0) {
    if (lVar1 < 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = uVar2 * 2;
    }
  }
  return lVar1;
}



===== WPP_SF_ @ 14000498c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_(ulong64 param_1,ushort param_2,_GUID *param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_D @ 1400049b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_D(ulong64 param_1,ushort param_2,_GUID *param_3,uint param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_S @ 1400049fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_S(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_Sd @ 140004a68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_Sd(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4,int param_5)

{
  longlong lVar1;
  
  if (param_4 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_dd @ 140004aec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_dd(ulong64 param_1,ushort param_2,_GUID *param_3,int param_4,int param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_q @ 140004b3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_q(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== WPP_SF_qSq @ 140004b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qSq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,wchar_t *param_5,
          void *param_6)

{
  longlong lVar1;
  
  if (param_5 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_90fbf584eb72335d9909000a3c9b9a1e_Traceguids,10);
  return;
}



===== WPP_SF_qq @ 140004c2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_qq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== PortIsClosed @ 140004c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

void __thiscall
RdLpcNotification::PortIsClosed(RdLpcNotification *this,IUMDFLPCCommPortInterface *param_1)

{
  WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *pWVar1;
  longlong lVar2;
  IUMDFLPCCommPortInterface *pIVar3;
  RdProcess *pRVar4;
  RdDriver *pRVar5;
  RdFdoDevice *this_00;
  _GUID *in_R8;
  IUMDFLPCCommPortInterface *in_R9;
  undefined1 auStack_88 [32];
  WUDF_PROBLEM local_68;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  local_68._17_1_ = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000020) == 0x80000020)) {
    in_R8 = WPP_63ac3b9ccd4d353876dd10835564cf47_Traceguids;
    in_R9 = param_1;
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,10,WPP_63ac3b9ccd4d353876dd10835564cf47_Traceguids
             ,param_1);
  }
  local_68.Status = -1;
  local_68.ProblemCode = WudfProblem_Disconnect;
  local_68._1_1_ = 0;
  local_68._padding_ = 0;
  local_68.Detector = WdfComponentReflector;
  local_68._5_1_ = 0;
  local_68._padding_ = 0;
  local_68.ExitCode = WdfHostExit_CodeUnknown;
  local_68._9_1_ = 0;
  local_68._padding_ = 0x7000;
  local_68.Operation = WudfOperation_Invalid;
  local_68._13_1_ = 0;
  local_68._padding_ = 0;
  local_68.Message = WudfMsg_Reserved;
  local_68.IrpInfo = 0;
  local_68.DeviceStarted = WudfDeviceStartState_Unknown;
  local_68._25_3_ = 0;
  pRVar5 = RdDriver::RdGetDriver();
  pWVar1 = pRVar5->m_RdFdoDeviceList;
  lVar2 = pWVar1->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar2,1);
  this_00 = (RdFdoDevice *)0x0;
  do {
    if (this_00 == (RdFdoDevice *)0x0) {
      this_00 = (RdFdoDevice *)pWVar1->m_List;
    }
    else {
      this_00 = (RdFdoDevice *)this_00->_padding_;
    }
  } while ((this_00 != (RdFdoDevice *)0x0) && ((uchar)this_00->_padding_ != '\0'));
  pIVar3 = pRVar5->m_DriverManagerLpcComm;
  while (this_00 != (RdFdoDevice *)0x0) {
    if ((param_1 == pIVar3) ||
       (((pRVar4 = this_00->m_RdProcess, pRVar4 != (RdProcess *)0x0 &&
         (((param_1 == pRVar4->m_IoEventLpcComm || (param_1 == pRVar4->m_IoCancelEventLpcComm)) ||
          (param_1 == pRVar4->m_SystemEventLpcComm)))) &&
        (this_00->m_CloseProcessMsg != (IUMDFLPCMessage *)0x0)))) {
      RdFdoDevice::DisableDevice(this_00,&local_68,(wchar_t *)in_R8,(ulong)in_R9);
    }
    do {
      this_00 = (RdFdoDevice *)this_00->_padding_;
      if (this_00 == (RdFdoDevice *)0x0) goto LAB_140004db2;
    } while ((char)this_00->_padding_ != '\0');
  }
LAB_140004db2:
  ExReleaseResourceLite(this->m_RdDriver->m_RdFdoDeviceList->_padding_);
  KeLeaveCriticalRegion();
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000020) == 0x80000020)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,WPP_63ac3b9ccd4d353876dd10835564cf47_Traceguids
           );
  }
  return;
}



===== PortIsConnected @ 140004e40 =====

long __thiscall
RdLpcNotification::PortIsConnected
          (RdLpcNotification *this,IUMDFLPCConnPortInterface *param_1,
          IUMDFLPCCommPortInterface *param_2,void *param_3,_MODE param_4)

{
  if (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000020) == 0x80000020) {
      WPP_SF_qqq((WPP_GLOBAL_Control->Control).Logger,0xc,
                 WPP_63ac3b9ccd4d353876dd10835564cf47_Traceguids,param_1,param_2,param_3);
    }
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000020) == 0x80000020)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xd,
               WPP_63ac3b9ccd4d353876dd10835564cf47_Traceguids,0);
    }
  }
  return 0;
}



===== WPP_SF_qqq @ 140004ed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,void *param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== RdProcess @ 140004f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

RdProcess * __thiscall
RdProcess::RdProcess
          (RdProcess *this,RdProcessParameters *param_1,
          WdfObjectList<RdProcess,RdProcessParameters> *param_2,WdfObject *param_3)

{
  ulong uVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  wchar_t *pwVar8;
  ushort uVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 auStackY_118 [32];
  ulong64 local_e8 [2];
  wchar_t *local_d8;
  wchar_t **local_d0;
  char local_c8 [8];
  wchar_t *local_c0;
  wchar_t **local_b8;
  undefined1 local_b0;
  wchar_t *local_a8;
  wchar_t **local_a0;
  undefined1 local_98;
  wchar_t *local_90;
  wchar_t **local_88;
  bool local_80;
  wchar_t *local_78;
  wchar_t **local_70;
  undefined1 local_68;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_118;
  WdfObject::WdfObject((WdfObject *)this,param_1->m_IoEventPortName,param_3,'\0',RdTypeObject);
  this->_padding_ = (longlong)&___7RdProcess__6B_;
  (this->m_DebugModeCounter).Enabled = 0;
  (this->m_DebugModeCounter).DisablePooling = 0;
  (this->m_DebugModeCounter).DisableTimeouts = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000100) == 0x80000100)) {
    WPP_SF_qqq((WPP_GLOBAL_Control->Control).Logger,10,
               WPP_95aa3d4914343f637323421378a17a4a_Traceguids,param_1,param_2,param_3);
  }
  uVar5 = (uint)this->_padding_;
  this->m_ObjectList = (WdfObjectList<RdProcess,RdProcessParameters> *)0x0;
  this->m_EProcess = (_EPROCESS *)0x0;
  this->m_IoEventLpcComm = (IUMDFLPCCommPortInterface *)0x0;
  this->m_IoCancelEventLpcComm = (IUMDFLPCCommPortInterface *)0x0;
  this->m_SystemEventLpcComm = (IUMDFLPCCommPortInterface *)0x0;
  this->m_NonStateChangingEventLpcComm = (IUMDFLPCCommPortInterface *)0x0;
  uVar11 = param_1->m_HostConnectTimeoutSeconds;
  this->m_HostProcessTimeoutSeconds = uVar11;
  (this->m_HostProcessTimeoutInTimerUnits).QuadPart = (ulonglong)uVar11 * -10000000;
  this->m_LifetimeId = (wchar_t *)0x0;
  this->m_IoEventPortName = (wchar_t *)0x0;
  this->m_IoCancelEventPortName = (wchar_t *)0x0;
  this->m_SystemEventPortName = (wchar_t *)0x0;
  this->m_NonStateChangingEventPortName = (wchar_t *)0x0;
  this->m_BreakOnDisable = 0;
  this->m_IsCompanion = param_1->m_ProcessIsCompanion;
  if (-1 < (int)uVar5) {
    if (param_1->m_EProcess == (_EPROCESS *)0x0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,
                WPP_95aa3d4914343f637323421378a17a4a_Traceguids);
      }
      uVar5 = 0xc000000d;
    }
    else {
      this->m_EProcess = param_1->m_EProcess;
      ObfReferenceObject();
      local_d8 = param_1->m_IoEventPortName;
      local_c0 = param_1->m_IoCancelEventPortName;
      local_a8 = param_1->m_SystemEventPortName;
      local_a0 = &this->m_SystemEventPortName;
      local_90 = param_1->m_NonStateChangingEventPortName;
      local_b8 = &this->m_IoCancelEventPortName;
      local_88 = &this->m_NonStateChangingEventPortName;
      local_80 = this->m_IsCompanion == '\0';
      local_70 = &this->m_LifetimeId;
      local_78 = param_1->m_LifetimeId;
      local_d0 = &this->m_IoEventPortName;
      local_c8[0] = '\x01';
      local_b0 = 1;
      local_98 = 1;
      local_68 = 1;
      for (uVar11 = 0; uVar11 < 5; uVar11 = uVar11 + 1) {
        uVar6 = (ulonglong)uVar11;
        local_e8[0] = 0;
        if (local_c8[uVar6 * 0x18] != '\0') {
          pwVar2 = (wchar_t *)local_e8[uVar6 * 3 + 2];
          uVar5 = RtlStringCchLengthW(pwVar2,0xfffe,local_e8);
          if ((int)uVar5 < 0) {
            if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) == 0)) ||
               ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_1400052e8;
            uVar9 = 0xc;
          }
          else {
            uVar10 = local_e8[0] + 1;
            auVar4._8_8_ = 0;
            auVar4._0_8_ = uVar10;
            uVar7 = SUB168(ZEXT816(2) * auVar4,0);
            if (SUB168(ZEXT816(2) * auVar4,8) != 0) {
              uVar7 = 0xffffffffffffffff;
            }
            pwVar8 = (wchar_t *)ExAllocatePool2(0x40,uVar7,0x51444d55);
            **(undefined8 **)(local_c8 + uVar6 * 0x18 + -8) = pwVar8;
            if (pwVar8 == (wchar_t *)0x0) {
              uVar5 = 0xc0000017;
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
                 (1 < (WPP_GLOBAL_Control->Control).Level)) {
                WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0xd,
                         WPP_95aa3d4914343f637323421378a17a4a_Traceguids,pwVar2);
              }
              goto LAB_1400052e8;
            }
            uVar5 = RtlStringCchCopyW(pwVar8,uVar10,pwVar2);
            if (-1 < (int)uVar5) goto LAB_1400051aa;
            if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) == 0)) ||
               ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_1400052e8;
            uVar9 = 0xe;
          }
          WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,uVar9,
                    WPP_95aa3d4914343f637323421378a17a4a_Traceguids,pwVar2,uVar5);
          goto LAB_1400052e8;
        }
LAB_1400051aa:
      }
      this->m_ObjectList = param_2;
      lVar3 = param_2->_padding_;
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(lVar3,1);
      this->_padding_ = (longlong)param_2->m_List;
      uVar1 = param_2->m_NextUniqueObjectId;
      param_2->m_NextUniqueObjectId = uVar1 + 1;
      *(ulong *)&this->_padding_ = uVar1;
      param_2->m_List = (WdfObject *)this;
      ExReleaseResourceLite(param_2->_padding_);
      KeLeaveCriticalRegion();
    }
  }
LAB_1400052e8:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar5);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000100) == 0x80000100)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xf,
             WPP_95aa3d4914343f637323421378a17a4a_Traceguids,uVar5);
  }
  return this;
}



===== ~RdProcess @ 140005350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdProcess::~RdProcess(RdProcess *this)

{
  this->_padding_ = (longlong)&___7RdProcess__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000100) == 0x80000100)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x10,
            WPP_95aa3d4914343f637323421378a17a4a_Traceguids);
  }
  MarkForDelete(this);
  if (this->m_IoEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_IoEventLpcComm + 0x18))();
    (**(code **)((longlong)*this->m_IoEventLpcComm + 8))();
  }
  if (this->m_IoCancelEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_IoCancelEventLpcComm + 0x18))();
    (**(code **)((longlong)*this->m_IoCancelEventLpcComm + 8))();
  }
  if (this->m_SystemEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_SystemEventLpcComm + 0x18))();
    (**(code **)((longlong)*this->m_SystemEventLpcComm + 8))();
  }
  if (this->m_NonStateChangingEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_NonStateChangingEventLpcComm + 0x18))();
    (**(code **)((longlong)*this->m_NonStateChangingEventLpcComm + 8))();
  }
  operator_delete(this->m_IoEventPortName);
  operator_delete(this->m_IoCancelEventPortName);
  operator_delete(this->m_SystemEventPortName);
  operator_delete(this->m_NonStateChangingEventPortName);
  operator_delete(this->m_LifetimeId);
  if (this->m_EProcess != (_EPROCESS *)0x0) {
    ObfDereferenceObject();
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000100) == 0x80000100)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x11,
            WPP_95aa3d4914343f637323421378a17a4a_Traceguids);
  }
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `scalar_deleting_destructor' @ 1400054e0 =====

void * __thiscall CUMDFUnknown::_scalar_deleting_destructor_(CUMDFUnknown *this,uint param_1)

{
  ~CUMDFUnknown(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140005520 =====

void * __thiscall RdProcess::_scalar_deleting_destructor_(RdProcess *this,uint param_1)

{
  ~RdProcess(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140005560 =====

void * __thiscall WdfObject::_scalar_deleting_destructor_(WdfObject *this,uint param_1)

{
  ~WdfObject(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ConnectToProcess @ 140005598 =====

long __thiscall RdProcess::ConnectToProcess(RdProcess *this)

{
  IUMDFLPCCommPortInterface *pIVar1;
  uint uVar2;
  RdDriver *this_00;
  void *pvVar3;
  void *pvVar4;
  ushort uVar5;
  WPP_PROJECT_CONTROL_BLOCK **ppWVar6;
  _IO_OBJECT local_res8;
  
  this_00 = RdDriver::RdGetDriver();
  pIVar1 = this->m_IoCancelEventLpcComm;
  ppWVar6 = &WPP_GLOBAL_Control;
  local_res8.DriverObject = this_00->m_DriverObject;
  if (this->m_IoEventLpcComm == (IUMDFLPCCommPortInterface *)0x0) {
    if (((pIVar1 == (IUMDFLPCCommPortInterface *)0x0) &&
        (this->m_SystemEventLpcComm == (IUMDFLPCCommPortInterface *)0x0)) &&
       (this->m_NonStateChangingEventLpcComm == (IUMDFLPCCommPortInterface *)0x0)) {
      pvVar3 = WdfPlatformSecurity::WudfAllocateWellKnownSid(WinLocalServiceSid);
      if (pvVar3 == (void *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)ppWVar6) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x13,
                  WPP_95aa3d4914343f637323421378a17a4a_Traceguids);
        }
        uVar2 = 0xc000009a;
        goto LAB_140005849;
      }
      pvVar4 = (void *)PsGetProcessId(this->m_EProcess);
      uVar2 = RdDriver::LpcConnect
                        (this_00,this->m_IoEventPortName,pvVar4,pvVar3,&local_res8,
                         &this->m_IoEventLpcComm);
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar5 = 0x14;
LAB_1400056c4:
          WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar5,
                   WPP_95aa3d4914343f637323421378a17a4a_Traceguids,uVar2);
        }
      }
      else if ((this->m_IsCompanion == '\0') &&
              (uVar2 = RdDriver::LpcConnect
                                 (this_00,this->m_IoCancelEventPortName,pvVar4,pvVar3,&local_res8,
                                  &this->m_IoCancelEventLpcComm), (int)uVar2 < 0)) {
        if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
           ((((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0 &&
            (1 < (WPP_GLOBAL_Control->Control).Level)))) {
          uVar5 = 0x15;
          goto LAB_1400056c4;
        }
      }
      else {
        uVar2 = RdDriver::LpcConnect
                          (this_00,this->m_SystemEventPortName,pvVar4,pvVar3,&local_res8,
                           &this->m_SystemEventLpcComm);
        if ((int)uVar2 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar5 = 0x16;
            goto LAB_1400056c4;
          }
        }
        else if ((this->m_IsCompanion == '\0') &&
                (uVar2 = RdDriver::LpcConnect
                                   (this_00,this->m_NonStateChangingEventPortName,pvVar4,pvVar3,
                                    &local_res8,&this->m_NonStateChangingEventLpcComm),
                (int)uVar2 < 0)) {
          if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
             ((((WPP_GLOBAL_Control->Control).Flags[0] & 0x100) != 0 &&
              (1 < (WPP_GLOBAL_Control->Control).Level)))) {
            uVar5 = 0x17;
            goto LAB_1400056c4;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      WdfPlatformSecurity::WudfFreeSid(pvVar3);
      goto LAB_140005849;
    }
  }
  else if (((pIVar1 != (IUMDFLPCCommPortInterface *)0x0) &&
           (this->m_SystemEventLpcComm != (IUMDFLPCCommPortInterface *)0x0)) &&
          (this->m_NonStateChangingEventLpcComm != (IUMDFLPCCommPortInterface *)0x0)) {
    uVar2 = -(uint)(this->m_IsCompanion != '\0') & 0xc0000184;
    goto LAB_140005849;
  }
  uVar2 = 0xc0000001;
LAB_140005849:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000100) == 0x80000100)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x18,
             WPP_95aa3d4914343f637323421378a17a4a_Traceguids,uVar2);
  }
  return uVar2;
}



===== DisableProcess @ 1400058a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdProcess::DisableProcess(RdProcess *this)

{
  if (this->m_IoEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_IoEventLpcComm + 0x48))();
  }
  if (this->m_IoCancelEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_IoCancelEventLpcComm + 0x48))();
  }
  if (this->m_SystemEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_SystemEventLpcComm + 0x48))();
  }
  if (this->m_NonStateChangingEventLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_NonStateChangingEventLpcComm + 0x48))();
  }
  return;
}



===== MarkForDelete @ 140005920 =====

void __thiscall RdProcess::MarkForDelete(RdProcess *this)

{
  uchar *in_R8;
  
  if (this->m_ObjectList != (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
    WdfObjectList<RdProcess,RdProcessParameters>::Remove(this->m_ObjectList,this,in_R8);
  }
  *(undefined1 *)&this->_padding_ = 1;
  return;
}



===== MarkForDelete @ 140005950 =====

void __thiscall WdfObject::MarkForDelete(WdfObject *this)

{
  this->m_MarkedForDelete = '\x01';
  return;
}



===== Remove @ 14000595c =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

uchar __thiscall
WdfObjectList<RdProcess,RdProcessParameters>::Remove
          (WdfObjectList<RdProcess,RdProcessParameters> *this,RdProcess *param_1,uchar *param_2)

{
  RdProcess *pRVar1;
  WdfObject *pWVar2;
  longlong lVar3;
  WdfObject **ppWVar4;
  bool bVar5;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  lVar3 = this->_padding_;
  bVar5 = false;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar3,1);
  ppWVar4 = &this->m_List;
  do {
    pRVar1 = (RdProcess *)*ppWVar4;
    if (pRVar1 == (RdProcess *)0x0) {
LAB_1400059bb:
      WudfVerifyStatic((WdfComponentType)lVar3,
                       (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)ppWVar4,
                       L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                       in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                       in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                       "expected object not found in list",bVar5);
      pWVar2 = this->m_List;
      ExReleaseResourceLite(this->_padding_);
      KeLeaveCriticalRegion();
      return pWVar2 == (WdfObject *)0x0;
    }
    if (pRVar1 == param_1) {
      bVar5 = true;
      *ppWVar4 = (WdfObject *)pRVar1->_padding_;
      goto LAB_1400059bb;
    }
    ppWVar4 = (WdfObject **)&pRVar1->_padding_;
  } while( true );
}



===== WPP_SF_qd @ 140005a1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_qd(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,int param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== ~RdDriver @ 140005a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdDriver::~RdDriver(RdDriver *this)

{
  wchar_t *pwVar1;
  
  this->_padding_ = (longlong)&___7RdDriver__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xc,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids
           );
  }
  pwVar1 = (this->m_RegistryPath).Buffer;
  if (pwVar1 != (wchar_t *)0x0) {
    operator_delete(pwVar1);
    (this->m_RegistryPath).Buffer = (wchar_t *)0x0;
  }
  if (this->m_Timer != (IUMDFPeriodicTimer *)0x0) {
    (**(code **)((longlong)*this->m_Timer + 0x18))();
    (**(code **)((longlong)*this->m_Timer + 8))();
    this->m_Timer = (IUMDFPeriodicTimer *)0x0;
  }
  if (this->m_WdfLpcInterface != (IUMDFLPCInterface *)0x0) {
    (**(code **)((longlong)*this->m_WdfLpcInterface + 8))();
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xd,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids
           );
  }
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140005b70 =====

void * __thiscall RdDriver::_scalar_deleting_destructor_(RdDriver *this,uint param_1)

{
  ~RdDriver(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== CloseProcessMessage @ 140005ba8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

IUMDFLPCMessage * __thiscall RdDriver::CloseProcessMessage(RdDriver *this)

{
  uint uVar1;
  undefined2 *puVar2;
  IUMDFLPCMessage *local_res8;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x26,
            WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  local_res8 = (IUMDFLPCMessage *)0x0;
  uVar1 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x48))
                    (this->m_WdfLpcInterface,&local_res8,0x28,4,this->m_DriverManagerLpcComm,0,0,0,1
                    );
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x27,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
    }
    if (local_res8 != (IUMDFLPCMessage *)0x0) {
      (**(code **)((longlong)*local_res8 + 8))();
      local_res8 = (IUMDFLPCMessage *)0x0;
    }
  }
  else {
    puVar2 = (undefined2 *)(**(code **)((longlong)*local_res8 + 0x18))(local_res8,0x28);
    *puVar2 = 0x20;
    *(undefined8 *)(puVar2 + 2) = 0;
    *(undefined8 *)(puVar2 + 6) = 0;
    *(undefined8 *)(puVar2 + 10) = 0;
    *(undefined4 *)(puVar2 + 0xe) = 0;
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x28,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,local_res8);
  }
  return local_res8;
}



===== ControlObjectMessage @ 140005d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

IUMDFLPCMessage * __thiscall RdDriver::ControlObjectMessage(RdDriver *this,wchar_t *param_1)

{
  uchar uVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  IUMDFLPCMessage *pIVar5;
  IUMDFLPCMessage *pIVar6;
  longlong lVar7;
  IUMDFLPCMessage *local_res18;
  ulong64 local_res20;
  
  local_res20 = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x19,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,param_1);
  }
  pIVar5 = (IUMDFLPCMessage *)0x0;
  local_res18 = (IUMDFLPCMessage *)0x0;
  lVar2 = RtlStringCbLengthW(param_1,0xffff,&local_res20);
  if (lVar2 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,0x1a,
                WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,param_1,lVar2);
      goto LAB_140005db5;
    }
  }
  else {
    lVar7 = local_res20 + 2;
    iVar3 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x48))
                      (this->m_WdfLpcInterface,&local_res18,0xc,4,this->m_DriverManagerLpcComm,lVar7
                       ,0,0,1);
    if (-1 < iVar3) {
      puVar4 = (undefined1 *)(**(code **)((longlong)*local_res18 + 0x18))(local_res18,0xc);
      *puVar4 = 0x1d;
      uVar1 = this->m_IsCompanion;
      *(undefined4 *)(puVar4 + 8) = 0;
      *(uint *)(puVar4 + 4) = (uint)(uVar1 != '\0');
      (**(code **)((longlong)*local_res18 + 0x30))(local_res18,param_1,lVar7,0,1);
      pIVar6 = local_res18;
      goto LAB_140005dd3;
    }
LAB_140005db5:
    pIVar5 = local_res18;
  }
  pIVar6 = (IUMDFLPCMessage *)0x0;
  if (pIVar5 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*pIVar5 + 8))(pIVar5);
    local_res18 = (IUMDFLPCMessage *)0x0;
    pIVar6 = (IUMDFLPCMessage *)0x0;
  }
LAB_140005dd3:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x1b,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,pIVar6);
    pIVar6 = local_res18;
  }
  return pIVar6;
}



===== DeleteDrvMgrCtrlDevice @ 140005ec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdDriver::DeleteDrvMgrCtrlDevice(RdDriver *this)

{
  _DEVICE_OBJECT *p_Var1;
  
  p_Var1 = (_DEVICE_OBJECT *)this->m_RdDrvMgrCtrl->_padding_;
  (**(code **)(this->m_RdDrvMgrCtrl->_padding_ + 0x28))();
  (**(code **)(this->m_RdDrvMgrCtrl->_padding_ + 8))();
  this->m_RdDrvMgrCtrl = (RdDrvMgrCtrlDevice *)0x0;
  if (p_Var1 != (_DEVICE_OBJECT *)0x0) {
    WaitForDrvMgrCtrlDeviceDeletion(this,p_Var1);
  }
  return;
}



===== Find @ 140005f2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

RdProcess * __thiscall
WdfObjectList<RdProcess,RdProcessParameters>::Find
          (WdfObjectList<RdProcess,RdProcessParameters> *this,RdProcessParameters *param_1,
          uchar param_2,uchar param_3,uchar *param_4,long *param_5)

{
  longlong lVar1;
  RdProcess *pRVar2;
  code *pcVar3;
  RdProcess *pRVar4;
  uchar uVar5;
  undefined7 in_register_00000081;
  undefined7 in_register_00000089;
  
  lVar1 = this->_padding_;
  uVar5 = '\0';
  KeEnterCriticalRegion
            (this,param_1,CONCAT71(in_register_00000081,param_2),
             CONCAT71(in_register_00000089,param_3));
  ExAcquireResourceExclusiveLite(lVar1,1);
  pRVar2 = (RdProcess *)this->m_List;
  pRVar4 = pRVar2;
  if (pRVar2 == (RdProcess *)0x0) {
LAB_140005f9b:
    pRVar2 = (RdProcess *)ExAllocatePool2(this->m_PoolFlags,0xd8,this->m_Tag);
    if (pRVar2 == (RdProcess *)0x0) goto LAB_140005ffe;
    pRVar2 = RdProcess::RdProcess(pRVar2,param_1,this,(WdfObject *)this);
    if (pRVar2 == (RdProcess *)0x0) goto LAB_140005ffe;
    if (-1 < (int)pRVar2->_padding_) {
      uVar5 = '\x01';
      pRVar4 = pRVar2;
      goto LAB_140005ffe;
    }
    (**(code **)(pRVar2->_padding_ + 0x28))(pRVar2);
    pcVar3 = *(code **)(pRVar2->_padding_ + 8);
  }
  else {
    do {
      if ((param_1->m_EProcess == pRVar2->m_EProcess) && ((char)pRVar2->_padding_ == '\0')) break;
      pRVar2 = (RdProcess *)pRVar2->_padding_;
    } while (pRVar2 != (RdProcess *)0x0);
    pRVar4 = pRVar2;
    if (pRVar2 == (RdProcess *)0x0) goto LAB_140005f9b;
    pcVar3 = *(code **)pRVar2->_padding_;
  }
  (*pcVar3)(pRVar2);
LAB_140005ffe:
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if (param_4 != (uchar *)0x0) {
    *param_4 = uVar5;
  }
  return pRVar4;
}



===== HintDrvMgrCtrlDeviceInRdDeviceList @ 140006048 =====

uchar __thiscall
RdDriver::HintDrvMgrCtrlDeviceInRdDeviceList(RdDriver *this,_DEVICE_OBJECT *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uchar uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  uint local_res8 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8[0] = 0;
  puVar4 = (undefined8 *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  uVar5 = '\x01';
  iVar2 = IoEnumerateDeviceObjectList(this->m_DriverObject,&local_28,0x10,local_res8);
  uVar6 = local_res8[0];
  if (iVar2 < 0) {
    if (0x1fffffff < local_res8[0]) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return '\x01';
      }
      if (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0) {
        return '\x01';
      }
      if ((WPP_GLOBAL_Control->Control).Level < 3) {
        return '\x01';
      }
      WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x3b,
                WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,0x1fffffff,local_res8[0]);
      return '\x01';
    }
    iVar2 = local_res8[0] * 8;
    uVar3 = SUB168(ZEXT816(8) * ZEXT416(local_res8[0]),0);
    if (SUB168(ZEXT816(8) * ZEXT416(local_res8[0]),8) != 0) {
      uVar3 = 0xffffffffffffffff;
    }
    puVar4 = (undefined8 *)ExAllocatePool2(0x40,uVar3,0x30444d55);
    if (puVar4 == (undefined8 *)0x0) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return '\x01';
      }
      if (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0) {
        return '\x01';
      }
      if ((WPP_GLOBAL_Control->Control).Level < 3) {
        return '\x01';
      }
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x3c,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
      return '\x01';
    }
    iVar2 = IoEnumerateDeviceObjectList(this->m_DriverObject,puVar4,iVar2,local_res8);
    if (iVar2 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
         (2 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x3d,
                  WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar6 & 0x1fffffff,local_res8[0]);
      }
      goto LAB_14000621e;
    }
    puVar8 = puVar4;
  }
  else {
    puVar8 = &local_28;
  }
  bVar1 = false;
  uVar7 = 0;
  if (local_res8[0] == 0) {
LAB_1400061d0:
    uVar5 = '\0';
  }
  else {
    do {
      if ((_DEVICE_OBJECT *)puVar8[uVar7] == param_1) {
        bVar1 = true;
      }
      ObfDereferenceObject();
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < local_res8[0]);
    if (!bVar1) goto LAB_1400061d0;
  }
  if (puVar4 == (undefined8 *)0x0) {
    return uVar5;
  }
LAB_14000621e:
  operator_delete(puVar4);
  return uVar5;
}



===== InitializeLpcAndConnect @ 140006248 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDriver::InitializeLpcAndConnect(RdDriver *this)

{
  uchar uVar1;
  IUMDFLPC *pIVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  RdLpcNotification *pRVar6;
  void *pvVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  wchar_t *pwVar10;
  WdfLpcInterface *pWVar11;
  WPP_PROJECT_CONTROL_BLOCK *pWVar12;
  ushort uVar13;
  WPP_PROJECT_CONTROL_BLOCK **ppWVar14;
  _GUID *p_Var15;
  WdfLpcInterface *local_res8;
  _DRIVER_OBJECT *local_res10;
  
  local_res10 = this->m_DriverObject;
  local_res8 = (WdfLpcInterface *)0x0;
  uVar4 = WdfLpcInterface::WdfLpcInterfaceCreateInstance(&local_res8);
  if ((int)uVar4 < 0) {
    this->m_WdfLpcInterface = (IUMDFLPCInterface *)0x0;
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return uVar4;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0) {
      return uVar4;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return uVar4;
    }
    uVar13 = 0x34;
  }
  else {
    pWVar11 = local_res8;
    if (local_res8 != (WdfLpcInterface *)0x0) {
      pWVar11 = (WdfLpcInterface *)&local_res8->field_0x10;
    }
    this->m_WdfLpcInterface = (IUMDFLPCInterface *)pWVar11;
    iVar5 = (**(code **)((longlong)*(IUMDFLPCInterface *)pWVar11 + 0x30))
                      (pWVar11,&this->m_Timer,1,&local_res10);
    if (iVar5 < 0) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return iVar5;
      }
      if (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0) {
        return iVar5;
      }
      if ((WPP_GLOBAL_Control->Control).Level < 2) {
        return iVar5;
      }
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x35,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
      return iVar5;
    }
    uVar4 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x40))
                      (this->m_WdfLpcInterface,&this->m_Lpc,2);
    if (-1 < (int)uVar4) {
      pRVar6 = (RdLpcNotification *)ExAllocatePool2(0x40,0x10,0x75444d55);
      if (pRVar6 != (RdLpcNotification *)0x0) {
        pRVar6->m_RdDriver = this;
        pRVar6->_padding_ = (longlong)&___7RdLpcNotification__6B_;
      }
      this->m_LpcNotification = pRVar6;
      if (pRVar6 == (RdLpcNotification *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x37,
                  WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
        }
        return -0x3fffffe9;
      }
      pvVar7 = WdfPlatformSecurity::WudfAllocateWellKnownSid(WinLocalSystemSid);
      if (pvVar7 == (void *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x38,
                  WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
        }
        return -0x3fffff66;
      }
      pIVar2 = this->m_Lpc;
      uVar1 = this->m_IsCompanion;
      pcVar3 = *(code **)((longlong)*pIVar2 + 0x28);
      uVar8 = PsGetCurrentProcessId();
      p_Var15 = (_GUID *)this->m_LpcNotification;
      uVar9 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x28))();
      iVar5 = (*pcVar3)(pIVar2,uVar9,p_Var15,uVar8,pvVar7,&local_res10,uVar1 != '\0',
                        (-(uint)(uVar1 != '\0') & 0xfbff) + 0x400,&this->m_DriverManagerLpcComm);
      if (iVar5 == -0x3fffffcc) {
        ppWVar14 = &WPP_GLOBAL_Control;
        pWVar12 = WPP_GLOBAL_Control;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
           (3 < (WPP_GLOBAL_Control->Control).Level)) {
          pWVar12 = (WPP_PROJECT_CONTROL_BLOCK *)(WPP_GLOBAL_Control->Control).Logger;
          p_Var15 = WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids;
          ppWVar14 = (WPP_PROJECT_CONTROL_BLOCK **)0x39;
          WPP_SF_((ulong64)pWVar12,0x39,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
        }
        if (((byte)Microsoft_Windows_DriverFrameworks_UserModeEnableBits[0] & 0x10) != 0) {
          McTemplateK0_EtwWriteTransfer
                    ((_MCGEN_TRACE_CONTEXT *)&pWVar12->Control,(_EVENT_DESCRIPTOR *)ppWVar14,p_Var15
                    );
        }
      }
      else if ((((iVar5 < 0) &&
                (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
               (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
              (1 < (WPP_GLOBAL_Control->Control).Level)) {
        pwVar10 = (wchar_t *)(**(code **)((longlong)*this->m_WdfLpcInterface + 0x28))();
        WPP_SF_Sd((WPP_GLOBAL_Control->Control).Logger,0x3a,
                  WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,pwVar10,iVar5);
      }
      WdfPlatformSecurity::WudfFreeSid(pvVar7);
      return iVar5;
    }
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return uVar4;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0) {
      return uVar4;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return uVar4;
    }
    uVar13 = 0x36;
  }
  WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar13,
           WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar4);
  return uVar4;
}



===== LpcConnect @ 1400065cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
RdDriver::LpcConnect
          (RdDriver *this,wchar_t *param_1,void *param_2,void *param_3,_IO_OBJECT *param_4,
          IUMDFLPCCommPortInterface **param_5)

{
  long lVar1;
  
  lVar1 = (**(code **)((longlong)*this->m_Lpc + 0x28))
                    (this->m_Lpc,param_1,this->m_LpcNotification,param_2,param_3,param_4,
                     this->m_IsCompanion != '\0',
                     (-(uint)(this->m_IsCompanion != '\0') & 0xfbff) + 0x400,param_5);
  return lVar1;
}



===== MarkForDelete @ 140006680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdDriver::MarkForDelete(RdDriver *this)

{
  *(undefined1 *)&this->_padding_ = 1;
  if (this->m_DriverManagerLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    (**(code **)((longlong)*this->m_DriverManagerLpcComm + 0x18))();
    (**(code **)((longlong)*this->m_DriverManagerLpcComm + 8))();
  }
  if (this->m_Lpc != (IUMDFLPC *)0x0) {
    (**(code **)((longlong)*this->m_Lpc + 8))();
  }
  operator_delete(this->m_LpcNotification);
  if (this->m_RdFdoDeviceList != (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0) {
    (**(code **)(this->m_RdFdoDeviceList->_padding_ + 0x28))();
    (**(code **)(this->m_RdFdoDeviceList->_padding_ + 8))();
  }
  if (this->m_RdProcessList != (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
    (**(code **)(this->m_RdProcessList->_padding_ + 0x28))();
    (**(code **)(this->m_RdProcessList->_padding_ + 8))();
  }
  if (this->m_RdNonPnPLibCtrl != (RdFxLibCtrlDevice *)0x0) {
    (**(code **)(*(longlong *)this->m_RdNonPnPLibCtrl + 0x28))();
    (**(code **)(*(longlong *)this->m_RdNonPnPLibCtrl + 8))();
    this->m_RdNonPnPLibCtrl = (RdFxLibCtrlDevice *)0x0;
  }
  if (this->m_RdCompanionLibrary != (RdCompanionLibrary *)0x0) {
    (**(code **)(this->m_RdCompanionLibrary->_padding_ + 0x28))();
    WdfObject::ReleaseWait((WdfObject *)&this->m_RdCompanionLibrary->_padding_,10000);
    this->m_RdCompanionLibrary = (RdCompanionLibrary *)0x0;
  }
  return;
}



===== Message @ 1400067b0 =====

void __thiscall
RdLpcNotification::Message
          (RdLpcNotification *this,IUMDFLPCPortInterface *param_1,_PORT_MESSAGE *param_2,
          _MODE param_3,ulong param_4,void *param_5,ushort param_6,void *param_7,ulong64 param_8)

{
  return;
}



===== OpenProcessMessage @ 1400067bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

IUMDFLPCMessage * __thiscall
RdDriver::OpenProcessMessage(RdDriver *this,wchar_t *param_1,uchar param_2,wchar_t *param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  ushort uVar3;
  ulonglong uVar4;
  longlong lVar5;
  IUMDFLPCMessage *local_48;
  ulong64 local_40;
  ulong64 local_38 [2];
  
  local_40 = 0;
  local_38[0] = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x21,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,param_1);
  }
  local_48 = (IUMDFLPCMessage *)0x0;
  uVar1 = RtlStringCbLengthW(param_1,0xffff,&local_40);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x22,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
    }
  }
  else {
    lVar5 = 0;
    uVar4 = local_40 + 2;
    if (param_2 == '\0') {
LAB_140006910:
      uVar1 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x48))
                        (this->m_WdfLpcInterface,&local_48,0x10,0x10,this->m_DriverManagerLpcComm,
                         lVar5 + uVar4,0,0,1);
      if (-1 < (int)uVar1) {
        puVar2 = (undefined1 *)(**(code **)((longlong)*local_48 + 0x18))(local_48,0x10);
        *puVar2 = 0x1f;
        *(undefined4 *)(puVar2 + 0xc) = 0;
        *(undefined4 *)(puVar2 + 4) = 0;
        *(uint *)(puVar2 + 8) = (uint)(param_2 != '\0');
        (**(code **)((longlong)*local_48 + 0x30))(local_48,param_1,uVar4,0,1);
        if (param_2 != '\0') {
          *(int *)(puVar2 + 0xc) = (int)uVar4;
          (**(code **)((longlong)*local_48 + 0x30))(local_48,param_3,lVar5,uVar4 & 0xffffffff,1);
        }
        goto LAB_140006a07;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006880;
      uVar3 = 0x24;
    }
    else {
      uVar1 = RtlStringCbLengthW(param_3,0xffff,local_38);
      if (-1 < (int)uVar1) {
        lVar5 = local_38[0] + 2;
        goto LAB_140006910;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006880;
      uVar3 = 0x23;
    }
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar3,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
  }
LAB_140006880:
  if (local_48 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*local_48 + 8))();
    local_48 = (IUMDFLPCMessage *)0x0;
  }
LAB_140006a07:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x25,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,local_48);
  }
  return local_48;
}



===== PrepareSharedResources @ 140006a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDriver::PrepareSharedResources(RdDriver *this)

{
  ulong *this_00;
  longlong lVar1;
  wchar_t *pwVar2;
  RdDrvMgrCtrlDevice *this_01;
  void *pvVar3;
  RdDrvMgrCtrlDevice *pRVar4;
  IUMDFLPCMessage *pIVar5;
  uint *puVar6;
  ushort uVar7;
  undefined8 uVar8;
  wchar_t *pwVar9;
  uint uVar10;
  
  uVar8 = 0x80000001;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    uVar8 = 0;
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x29,
            WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  lVar1 = this->_padding_;
  pwVar2 = (wchar_t *)0x0;
  pIVar5 = (IUMDFLPCMessage *)0x0;
  KeEnterCriticalRegion();
  pwVar9 = (wchar_t *)CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  ExAcquireResourceExclusiveLite(lVar1);
  if (this->m_DriverManagerLpcComm != (IUMDFLPCCommPortInterface *)0x0) {
    this_00 = &this->m_NumRedirectorInstances;
    if (*this_00 == 0) {
      uVar10 = 0xc000009a;
      pwVar2 = RdCreateUniqueName((RdDriver *)this_00,pwVar9);
      if (pwVar2 == (wchar_t *)0x0) goto LAB_140006cc9;
      this_01 = (RdDrvMgrCtrlDevice *)ExAllocatePool2(0x40,0x90,0x77444d55);
      pRVar4 = (RdDrvMgrCtrlDevice *)0x0;
      if (this_01 != (RdDrvMgrCtrlDevice *)0x0) {
        pvVar3 = (void *)(**(code **)((longlong)*this->m_DriverManagerLpcComm + 0x40))();
        pRVar4 = RdDrvMgrCtrlDevice::RdDrvMgrCtrlDevice(this_01,this,pwVar2,pvVar3);
      }
      this->m_RdDrvMgrCtrl = pRVar4;
      if (pRVar4 == (RdDrvMgrCtrlDevice *)0x0) {
        uVar10 = 0xc0000017;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006cc9;
        uVar7 = 0x2a;
      }
      else {
        uVar10 = (uint)pRVar4->_padding_;
        if ((int)uVar10 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x2b,
                     WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar10);
          }
          goto LAB_140006cc9;
        }
        pIVar5 = ControlObjectMessage(this,(wchar_t *)pRVar4->_padding_);
        if (pIVar5 == (IUMDFLPCMessage *)0x0) {
          uVar10 = 0xc0000017;
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006cc9;
          uVar7 = 0x2c;
        }
        else {
          puVar6 = (uint *)(**(code **)((longlong)*pIVar5 + 0x28))(pIVar5,0xfffffffffa0a1f00,0);
          if (puVar6 != (uint *)0x0) {
            if ((int)*puVar6 < 0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
                 (1 < (WPP_GLOBAL_Control->Control).Level)) {
                WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x2e,
                         WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,*puVar6);
              }
              uVar10 = *puVar6;
              goto LAB_140006cc9;
            }
            goto LAB_140006cc0;
          }
          uVar10 = 0xc000009a;
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006cc9;
          uVar7 = 0x2d;
        }
      }
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar7,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
      goto LAB_140006cc9;
    }
LAB_140006cc0:
    this->m_NumRedirectorInstances = *this_00 + 1;
  }
  uVar10 = 0;
LAB_140006cc9:
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if (((int)uVar10 < 0) && (this->m_RdDrvMgrCtrl != (RdDrvMgrCtrlDevice *)0x0)) {
    DeleteDrvMgrCtrlDevice(this);
  }
  if (pwVar2 != (wchar_t *)0x0) {
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
      WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x18,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,pwVar2);
    }
    operator_delete(pwVar2);
  }
  if (pIVar5 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*pIVar5 + 8))(pIVar5);
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x31,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar10);
  }
  return uVar10;
}



===== QueryGlobalRegistrySettings @ 140006da4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall RdDriver::QueryGlobalRegistrySettings(RdDriver *this)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  int *local_80;
  int local_78 [2];
  longlong local_70 [3];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70[0] = 0;
  local_54 = 0;
  local_3c = 0;
  local_78[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(local_70 + 1,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Wdf")
  ;
  local_50 = 0;
  local_48 = local_70 + 1;
  local_58 = 0x30;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  uVar1 = ZwOpenKey(local_70,0x80000000,&local_58);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x40,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
    }
  }
  else {
    RtlInitUnicodeString(local_70 + 1,L"WdfGlobalLogsDisabled");
    local_80 = local_78;
    local_88 = 0x10;
    iVar2 = ZwQueryValueKey(local_70[0],local_70 + 1,2,&local_28);
    if ((((-1 < iVar2) && (local_78[0] == 0x10)) && (local_28._4_4_ == 4)) && (uStack_20._4_4_ == 1)
       ) {
      this->m_IfrDisabled = '\x01';
    }
  }
  if (local_70[0] != 0) {
    ZwClose();
  }
  return;
}



===== QueryProcessMessage @ 140006f1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

IUMDFLPCMessage * __thiscall
RdDriver::QueryProcessMessage(RdDriver *this,wchar_t *param_1,uchar param_2,wchar_t *param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  ushort uVar3;
  ulonglong uVar4;
  longlong lVar5;
  IUMDFLPCMessage *local_48;
  ulong64 local_40;
  ulong64 local_38 [2];
  
  local_40 = 0;
  local_38[0] = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x1c,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,param_1);
  }
  local_48 = (IUMDFLPCMessage *)0x0;
  uVar1 = RtlStringCbLengthW(param_1,0xffff,&local_40);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x1d,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
    }
  }
  else {
    lVar5 = 0;
    uVar4 = local_40 + 2;
    if (param_2 == '\0') {
LAB_140007070:
      uVar1 = (**(code **)((longlong)*this->m_WdfLpcInterface + 0x48))
                        (this->m_WdfLpcInterface,&local_48,0x10,0xc,this->m_DriverManagerLpcComm,
                         lVar5 + uVar4,0,0,1);
      if (-1 < (int)uVar1) {
        puVar2 = (undefined1 *)(**(code **)((longlong)*local_48 + 0x18))(local_48,0x10);
        *(undefined4 *)(puVar2 + 0xc) = 0;
        *puVar2 = 0x1e;
        *(undefined4 *)(puVar2 + 4) = 0;
        *(uint *)(puVar2 + 8) = (uint)(param_2 != '\0');
        (**(code **)((longlong)*local_48 + 0x30))(local_48,param_1,uVar4,0,1);
        if (param_2 != '\0') {
          *(int *)(puVar2 + 0xc) = (int)uVar4;
          (**(code **)((longlong)*local_48 + 0x30))(local_48,param_3,lVar5,uVar4 & 0xffffffff,1);
        }
        goto LAB_140007168;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006fe0;
      uVar3 = 0x1f;
    }
    else {
      uVar1 = RtlStringCbLengthW(param_3,0xffff,local_38);
      if (-1 < (int)uVar1) {
        lVar5 = local_38[0] + 2;
        goto LAB_140007070;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140006fe0;
      uVar3 = 0x1e;
    }
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar3,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
  }
LAB_140006fe0:
  if (local_48 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*local_48 + 8))();
    local_48 = (IUMDFLPCMessage *)0x0;
  }
LAB_140007168:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x20,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,local_48);
  }
  return local_48;
}



===== RdCreateUniqueName @ 1400071c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

wchar_t * __thiscall RdDriver::RdCreateUniqueName(RdDriver *this,wchar_t *param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  ushort uVar3;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  uint local_a0;
  uint local_98;
  uint local_90;
  uint local_88;
  uint local_80;
  uint local_78;
  uint local_70;
  uint local_68;
  uint local_60;
  uint local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_48 = 0;
  uStack_40 = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x13,
            WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  pwVar2 = (wchar_t *)0x0;
  uVar1 = ExUuidCreate(&local_48);
  if ((int)uVar1 < 0) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) goto LAB_1400073b7;
    if ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x14,
               WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar1);
    }
  }
  else {
    pwVar2 = (wchar_t *)ExAllocatePool2(0x40,0x62,0x76444d55);
    if (pwVar2 == (wchar_t *)0x0) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return (wchar_t *)0x0;
      }
      if ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        uVar3 = 0x15;
LAB_14000737c:
        WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar3,
                WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
      }
    }
    else {
      local_58 = (uint)uStack_40._7_1_;
      local_60 = (uint)uStack_40._6_1_;
      local_68 = (uint)uStack_40._5_1_;
      local_70 = (uint)uStack_40._4_1_;
      local_78 = (uint)uStack_40._3_1_;
      local_80 = (uint)uStack_40._2_1_;
      local_88 = (uint)uStack_40._1_1_;
      local_90 = (uint)(byte)uStack_40;
      local_98 = (uint)local_48._6_2_;
      local_a0 = (uint)local_48._4_2_;
      local_a8 = (undefined4)local_48;
      uVar1 = RtlStringCchPrintfW(pwVar2,0x31,L"%s%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x"
                                 );
      if ((int)uVar1 < 0) {
        if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
        goto LAB_1400073b7;
        if ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar3 = 0x16;
          goto LAB_14000737c;
        }
      }
    }
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x17,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,pwVar2);
  }
  if (-1 < (int)uVar1) {
    return pwVar2;
  }
LAB_1400073b7:
  operator_delete(pwVar2);
  return (wchar_t *)0x0;
}



===== RdDispatch @ 140007400 =====

long __cdecl RdDriver::RdDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  char cVar1;
  uint uVar2;
  RdDevice *this;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_qq((WPP_GLOBAL_Control->Control).Logger,0x11,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,param_1,param_2);
  }
  this = RdDevice::RdWdmDeviceObject2RdDevice(param_1);
  cVar1 = *(char *)(param_2->Tail).Apc.SystemArgument1;
  if ((cVar1 - 2U & 0xef) != 0) {
    uVar2 = IoAcquireRemoveLockEx((longlong)param_1->DeviceExtension + 8,param_2,"",1,0x20);
    if ((int)uVar2 < 0) {
      if (cVar1 == '\x16') {
        PoStartNextPowerIrp(param_2);
      }
      (param_2->IoStatus).field0_0x0.Status = uVar2;
      IofCompleteRequest(param_2,0);
      goto LAB_1400074e5;
    }
  }
  uVar2 = RdDevice::ProcessIrp(this,param_2);
LAB_1400074e5:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x12,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,uVar2);
  }
  return uVar2;
}



===== RdGetDriver @ 140007538 =====

RdDriver * __cdecl RdDriver::RdGetDriver(void)

{
  undefined8 *puVar1;
  RdDriver *pRVar2;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xe,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids
           );
  }
  pRVar2 = (RdDriver *)0x0;
  puVar1 = (undefined8 *)IoGetDriverObjectExtension(RdDriverObject,DriverEntry);
  if (puVar1 == (undefined8 *)0x0) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return (RdDriver *)0x0;
    }
    if ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xf,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
    }
  }
  else {
    pRVar2 = (RdDriver *)*puVar1;
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x10,
             WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids,pRVar2);
  }
  return pRVar2;
}



===== RdUnload @ 140007620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl RdDriver::RdUnload(_DRIVER_OBJECT *param_1)

{
  longlong *plVar1;
  WPP_PROJECT_CONTROL_BLOCK *pWVar2;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,10,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids
             ,param_1);
  }
  if (g_wil_details_featureChangeNotification != (void *)0x0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = (void *)0x0;
  }
  if (g_wil_details_featureUsageProvider != (void *)0x0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = (void *)0x0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  plVar1 = (longlong *)IoGetDriverObjectExtension(param_1,DriverEntry);
  if ((plVar1 != (longlong *)0x0) && ((longlong *)*plVar1 != (longlong *)0x0)) {
    (**(code **)(*(longlong *)*plVar1 + 0x28))();
    WdfObject::ReleaseWait((WdfObject *)*plVar1,10000);
  }
  pWVar2 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    pWVar2 = (WPP_PROJECT_CONTROL_BLOCK *)(WPP_GLOBAL_Control->Control).Logger;
    WPP_SF_((ulong64)pWVar2,0xb,WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  McGenEventUnregister_EtwUnregister((ulong64 *)pWVar2->ReserveSpace);
  WppCleanupKm((_DRIVER_OBJECT *)&pWVar2->Control);
  return;
}



===== ReleaseWait @ 14000773c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfObject::ReleaseWait(WdfObject *this,ulong param_1)

{
  int iVar1;
  WUDF_EVENT WVar2;
  uchar uVar3;
  WdfObject *pWVar4;
  WUDF_EVENT WVar5;
  undefined4 in_register_00000014;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var6;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  p_Var6 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
           CONCAT44(in_register_00000014,param_1);
  iVar1 = (int)this->_padding_;
  pWVar4 = this;
  if ((iVar1 != -0x3fffffe9) && (iVar1 != -0x3fffff66)) {
    WudfVerifyStatic((WdfComponentType)this,p_Var6,
                     L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                     in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                     in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                     "ReleaseWait() must have a event",(this->m_Event).Value != (void *)0x0);
  }
  WudfVerifyStatic((WdfComponentType)pWVar4,p_Var6,
                   L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"already in release wait",
                   this->m_DeleteWaitInAction == '\0');
  WVar2.Value = (this->m_Event).Value;
  this->m_DeleteWaitInAction = '\x01';
  (**(code **)(this->_padding_ + 8))(this);
  if (WVar2.Value != (void *)0x0) {
    if (param_1 == 0xffffffff) {
      while( true ) {
        p_Var6 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x2710;
        WVar5.Value = WVar2.Value;
        uVar3 = WdfPlatformWait::WaitEvent(WVar2,10000);
        if (uVar3 != '\0') break;
        WudfVerifyStatic((WdfComponentType)WVar5.Value,p_Var6,
                         L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                         in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                         in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                         "Object destruction is taking a long time",false);
      }
    }
    else {
      p_Var6 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
               (ulonglong)param_1;
      WVar5.Value = WVar2.Value;
      uVar3 = WdfPlatformWait::WaitEvent(WVar2,param_1);
      if (uVar3 == '\0') {
        WudfVerifyStatic((WdfComponentType)WVar5.Value,p_Var6,
                         L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                         in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                         in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                         "object release wait failed",false);
      }
    }
    operator_delete(WVar2.Value);
  }
  return;
}



===== UnprepareSharedResources @ 140007844 =====

void __thiscall RdDriver::UnprepareSharedResources(RdDriver *this)

{
  ulong *puVar1;
  longlong lVar2;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x32,
            WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  lVar2 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar2,1);
  puVar1 = &this->m_NumRedirectorInstances;
  *puVar1 = *puVar1 - 1;
  if (*puVar1 == 0) {
    DeleteDrvMgrCtrlDevice(this);
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x33,
            WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
  }
  return;
}



===== WaitForDrvMgrCtrlDeviceDeletion @ 140007928 =====

void __thiscall RdDriver::WaitForDrvMgrCtrlDeviceDeletion(RdDriver *this,_DEVICE_OBJECT *param_1)

{
  uchar uVar1;
  uint uVar2;
  longlong local_res18;
  
  local_res18 = 0;
  uVar1 = HintDrvMgrCtrlDeviceInRdDeviceList(this,param_1);
  if (uVar1 != '\0') {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (2 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x3e,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
    }
    for (uVar2 = 0x7d; uVar2 < 0x1f41; uVar2 = uVar2 * 2) {
      local_res18 = (ulonglong)uVar2 * -10000;
      KeDelayExecutionThread(0,0,&local_res18);
      uVar1 = HintDrvMgrCtrlDeviceInRdDeviceList(this,param_1);
      if (uVar1 == '\0') {
        return;
      }
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (2 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x3f,
              WPP_7a773ebca44a3cdb0d6418677af51362_Traceguids);
    }
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140007a18 =====

ulong __cdecl McGenEventUnregister_EtwUnregister(ulong64 *param_1)

{
  ulong uVar1;
  
  if (UMDF_PROVIDER_Context.RegistrationHandle == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    UMDF_PROVIDER_Context.RegistrationHandle = 0;
  }
  return uVar1;
}



===== McGenEventWrite_EtwWriteTransfer @ 140007a4c =====

ulong __cdecl
McGenEventWrite_EtwWriteTransfer
          (_MCGEN_TRACE_CONTEXT *param_1,_EVENT_DESCRIPTOR *param_2,_GUID *param_3,ulong param_4,
          _EVENT_DATA_DESCRIPTOR *param_5)

{
  ulong64 uVar1;
  ulong uVar2;
  uint uVar3;
  
  uVar1 = UMDF_PROVIDER_Context.Logger;
  uVar2 = 0;
  if (UMDF_PROVIDER_Context.Logger == 0) {
    param_5->Ptr = 0;
    uVar3 = 0;
  }
  else {
    param_5->Ptr = UMDF_PROVIDER_Context.Logger;
    uVar2 = 2;
    uVar3 = (uint)*(ushort *)uVar1;
  }
  param_5->Size = uVar3;
  (param_5->field2_0xc).Reserved = uVar2;
  uVar2 = EtwWriteTransfer(UMDF_PROVIDER_Context.RegistrationHandle,
                           &EVENT_UMDF_REFLECTOR_DRVMGR_LPC_PORT_MISSING,0,0,1,param_5);
  return uVar2;
}



===== McTemplateK0_EtwWriteTransfer @ 140007ab4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulong __cdecl
McTemplateK0_EtwWriteTransfer
          (_MCGEN_TRACE_CONTEXT *param_1,_EVENT_DESCRIPTOR *param_2,_GUID *param_3)

{
  ulong uVar1;
  ulong in_R9D;
  undefined1 auStackY_58 [32];
  _EVENT_DATA_DESCRIPTOR local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  uVar1 = McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,in_R9D,&local_28);
  return uVar1;
}



===== RtlStringCchPrintfW @ 140007af0 =====

long __cdecl RtlStringCchPrintfW(wchar_t *param_1,ulong64 param_2,wchar_t *param_3)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  char local_res20 [8];
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return lVar2;
}



===== RdDevice @ 140007b6c =====

RdDevice * __thiscall
RdDevice::RdDevice(RdDevice *this,RdDriver *param_1,wchar_t *param_2,wchar_t *param_3,
                  _UNICODE_STRING *param_4,ulong param_5,WdfObject *param_6,RdType param_7,
                  uchar param_8)

{
  _DEVICE_OBJECT **pp_Var1;
  ulonglong uVar2;
  _IO_REMOVE_LOCK *p_Var3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  uint uVar8;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ushort uVar11;
  WdfObject *pWVar12;
  wchar_t *pwVar13;
  ulonglong uVar14;
  longlong lVar15;
  bool bVar16;
  wchar_t *local_res8;
  ulong64 local_res10;
  ulong uVar17;
  undefined8 in_stack_ffffffffffffff88;
  wchar_t *in_stack_ffffffffffffff90;
  WdfObject *in_stack_ffffffffffffffa0;
  undefined8 local_48;
  wchar_t *pwStack_40;
  
  uVar17 = (ulong)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff88 >> 8),param_7);
  pWVar12 = param_6;
  WdfObject::WdfObject((WdfObject *)this,param_2,param_6,param_8,param_7);
  this->_padding_ = (longlong)&___7RdDevice__6B_;
  local_48 = 0;
  pwStack_40 = (wchar_t *)0x0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    in_stack_ffffffffffffff90 = param_3;
    WPP_SF_qSSdq((WPP_GLOBAL_Control->Control).Logger,4,(_GUID *)pWVar12,param_1,param_2,param_3,
                 param_5,param_6);
    uVar17 = (ulong)param_2;
    in_stack_ffffffffffffffa0 = param_6;
  }
  this->m_RdDriver = param_1;
  pp_Var1 = &this->m_DeviceObject;
  local_res8 = (wchar_t *)0x0;
  local_res10 = 0;
  *pp_Var1 = (_DEVICE_OBJECT *)0x0;
  pwVar10 = (wchar_t *)0x0;
  this->m_NextLowerDeviceObject = (_DEVICE_OBJECT *)0x0;
  lVar15 = 0;
  this->m_RemoveLock = (_IO_REMOVE_LOCK *)0x0;
  RtlInitUnicodeString(&this->m_DosDeviceName,0);
  uVar8 = (uint)this->_padding_;
  if ((int)uVar8 < 0) goto LAB_140008109;
  uVar14 = 2;
  if (param_5 < 0x15) {
    if (((param_5 == 0x14) || (param_5 == 2)) ||
       ((param_5 == 3 || ((param_5 == 7 || (param_5 == 8)))))) goto LAB_1400080b9;
    bVar16 = param_5 == 9;
LAB_140007cb1:
    if (bVar16) goto LAB_1400080b9;
    if (param_3 != (wchar_t *)0x0) {
      uVar8 = RtlStringCchLengthW(param_3,0xfff6,&local_res10);
      if ((int)uVar8 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < (byte)uVar14)) goto LAB_140008109;
        uVar11 = 0xe;
      }
      else {
        lVar15 = local_res10 + 1;
        uVar2 = local_res10 + 9;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar14;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = uVar2;
        uVar9 = SUB168(auVar5 * auVar6,0);
        if (SUB168(auVar5 * auVar6,8) != 0) {
          uVar9 = 0xffffffffffffffff;
        }
        local_res8 = (wchar_t *)ExAllocatePool2(0x40,uVar9,0x36444d55);
        if (local_res8 == (wchar_t *)0x0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar11 = 0xf;
LAB_140007d90:
            WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar11,
                    WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
          }
LAB_140007da0:
          uVar8 = 0xc0000017;
          goto LAB_140008109;
        }
        uVar8 = RtlStringCchPrintfW(local_res8,uVar2,L"\\Device\\%s");
        if (-1 < (int)uVar8) {
          RtlInitUnicodeString(&local_48,local_res8);
          goto LAB_140007e14;
        }
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140008109;
        uVar11 = 0x10;
      }
LAB_140007d0c:
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar11,
               WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,uVar8);
      goto LAB_140008109;
    }
LAB_140007e14:
    if (param_4 == (_UNICODE_STRING *)0x0) {
      uVar8 = IoCreateDevice(param_1->m_DriverObject,0x28,
                             -(ulonglong)(param_3 != (wchar_t *)0x0) & (ulonglong)&local_48,param_5,
                             0x100,(ulonglong)in_stack_ffffffffffffff90 & 0xffffffffffffff00,pp_Var1
                            );
    }
    else {
      uVar8 = WdmlibIoCreateDeviceSecure
                        (param_1->m_DriverObject,(ulong)param_4,
                         (_UNICODE_STRING *)
                         (-(ulonglong)(param_3 != (wchar_t *)0x0) & (ulonglong)&local_48),param_5,
                         uVar17,(uchar)in_stack_ffffffffffffff90,param_4,
                         (_GUID *)in_stack_ffffffffffffffa0,pp_Var1);
    }
    if ((int)uVar8 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 4) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140008109;
      uVar11 = 0x11;
      goto LAB_140007d0c;
    }
    puVar4 = (*pp_Var1)->DeviceExtension;
    *puVar4 = this;
    if (param_3 == (wchar_t *)0x0) {
LAB_14000804f:
      p_Var3 = (_IO_REMOVE_LOCK *)(puVar4 + 1);
      this->m_RemoveLock = p_Var3;
      IoInitializeRemoveLockEx(p_Var3,0x58464457,1,0,0x20);
      uVar8 = IoAcquireRemoveLockEx(this->m_RemoveLock,this,"",1,0x20);
      pwVar10 = (wchar_t *)0x0;
      if ((int)uVar8 < 0) {
        this->m_RemoveLock = (_IO_REMOVE_LOCK *)0x0;
      }
      goto LAB_140008109;
    }
    uVar14 = lVar15 + 0xd;
    if (uVar14 < 0xffff) {
      auVar7._8_8_ = 0;
      auVar7._0_8_ = uVar14;
      uVar9 = SUB168(ZEXT816(2) * auVar7,0);
      if (SUB168(ZEXT816(2) * auVar7,8) != 0) {
        uVar9 = 0xffffffffffffffff;
      }
      pwVar10 = (wchar_t *)ExAllocatePool2(0x40,uVar9,0x37444d55);
      if (pwVar10 == (wchar_t *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar11 = 0x13;
          goto LAB_140007d90;
        }
        goto LAB_140007da0;
      }
      pwVar13 = L"\\DosDevices\\%s";
      uVar8 = RtlStringCchPrintfW(pwVar10,uVar14,L"\\DosDevices\\%s");
      if ((int)uVar8 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140008109;
        uVar11 = 0x14;
        goto LAB_140007d0c;
      }
      RtlInitUnicodeString(&this->m_DosDeviceName,pwVar10);
      uVar11 = (ushort)&local_48;
      pwVar10 = (wchar_t *)0x0;
      uVar8 = IoCreateSymbolicLink(&this->m_DosDeviceName);
      if ((int)uVar8 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_SSd((WPP_GLOBAL_Control->Control).Logger,uVar11,(_GUID *)pwVar13,
                     (this->m_DosDeviceName).Buffer,pwStack_40,uVar8);
        }
        goto LAB_140008109;
      }
      goto LAB_14000804f;
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x12,
              WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
    }
  }
  else {
    if (((param_5 != 0x1f) && (param_5 != 0x20)) && (param_5 != 0x24)) {
      bVar16 = param_5 == 0x35;
      goto LAB_140007cb1;
    }
LAB_1400080b9:
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xd,
               WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,param_5);
    }
  }
  uVar8 = 0xc000000d;
LAB_140008109:
  operator_delete(pwVar10);
  operator_delete(local_res8);
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar8);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x16,
            WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
  }
  return this;
}



===== ~RdDevice @ 14000817c =====

void __thiscall RdDevice::~RdDevice(RdDevice *this)

{
  this->_padding_ = (longlong)&___7RdDevice__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x17,
            WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
  }
  if (this->m_DeviceObject != (_DEVICE_OBJECT *)0x0) {
    IoDeleteDevice();
  }
  if ((this->m_DosDeviceName).Buffer != (wchar_t *)0x0) {
    IoDeleteSymbolicLink(&this->m_DosDeviceName);
    operator_delete((this->m_DosDeviceName).Buffer);
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x18,
            WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
  }
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140008250 =====

void * __thiscall RdDevice::_scalar_deleting_destructor_(RdDevice *this,uint param_1)

{
  ~RdDevice(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AcquireRemoveLockAlways @ 140008290 =====

long __thiscall RdDevice::AcquireRemoveLockAlways(RdDevice *this,void *param_1)

{
  long lVar1;
  
  lVar1 = IoAcquireRemoveLockEx(this->m_RemoveLock,param_1,"",1,0x20);
  return lVar1;
}



===== MarkForDelete @ 1400082d0 =====

void __thiscall RdDevice::MarkForDelete(RdDevice *this)

{
  *(undefined1 *)&this->_padding_ = 1;
  if (this->m_RemoveLock != (_IO_REMOVE_LOCK *)0x0) {
    IoReleaseRemoveLockAndWaitEx(this->m_RemoveLock,this,0x20);
  }
  return;
}



===== ProcessIrp @ 140008308 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDevice::ProcessIrp(RdDevice *this,_IRP *param_1)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  
  bVar1 = *(byte *)(param_1->Tail).Apc.SystemArgument1;
  uVar2 = (uint)bVar1;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x26,
              WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,param_1,uVar2);
  }
  if (uVar2 == 0) {
    pcVar3 = *(code **)(this->_padding_ + 0x50);
  }
  else if (bVar1 == 2) {
    pcVar3 = *(code **)(this->_padding_ + 0x98);
  }
  else if (bVar1 == 3) {
    pcVar3 = *(code **)(this->_padding_ + 0x58);
  }
  else if (bVar1 == 4) {
    pcVar3 = *(code **)(this->_padding_ + 0x60);
  }
  else if (bVar1 == 0xe) {
    pcVar3 = *(code **)(this->_padding_ + 0x68);
  }
  else if (bVar1 == 0xf) {
    pcVar3 = *(code **)(this->_padding_ + 0x70);
  }
  else if (bVar1 == 9) {
    pcVar3 = *(code **)(this->_padding_ + 0x78);
  }
  else if (bVar1 - 5 < 2) {
    pcVar3 = *(code **)(this->_padding_ + 0x80);
  }
  else if (bVar1 == 0x12) {
    pcVar3 = *(code **)(this->_padding_ + 0xa0);
  }
  else if (bVar1 == 0x1b) {
    pcVar3 = *(code **)(this->_padding_ + 0x30);
  }
  else if (bVar1 == 0x16) {
    pcVar3 = *(code **)(this->_padding_ + 0x38);
  }
  else if (bVar1 == 0x17) {
    pcVar3 = *(code **)(this->_padding_ + 0x40);
  }
  else if ((bVar1 == 1) || (uVar2 == 0x13)) {
    pcVar3 = *(code **)(this->_padding_ + 0x88);
  }
  else {
    pcVar3 = *(code **)(this->_padding_ + 0x48);
  }
  uVar2 = (*pcVar3)(this,param_1);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x27,
             WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,uVar2);
  }
  return uVar2;
}



===== RdCreateNamedPipeMailslot @ 1400084b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDevice::RdCreateNamedPipeMailslot(RdDevice *this,_IRP *param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(param_1->Tail).Apc.SystemArgument1;
  (param_1->IoStatus).field0_0x0.Status = -0x3fffff45;
  IofCompleteRequest(param_1,0);
  (**(code **)(this->_padding_ + 0xa8))(this,param_1,uVar1);
  return -0x3fffff45;
}



===== RdCreatePnpRegKey @ 14000851c =====

long __thiscall
RdDevice::RdCreatePnpRegKey
          (RdDevice *this,_DEVICE_OBJECT *param_1,ulong param_2,_UNICODE_STRING *param_3,
          _UNICODE_STRING *param_4,uchar param_5,uchar param_6,uchar param_7,ulong param_8,
          void **param_9,ulong *param_10)

{
  int iVar1;
  uchar uVar2;
  void *local_res8;
  void *local_res20;
  ulong *in_stack_ffffffffffffffe8;
  
  local_res8 = (void *)0x0;
  local_res20 = (void *)0x0;
  if (param_3 == (_UNICODE_STRING *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x1d,
              WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
    }
    iVar1 = -0x3ffffff3;
  }
  else {
    uVar2 = (uchar)&local_res8;
    iVar1 = IoOpenDeviceRegistryKey(param_1,1,3);
    if (iVar1 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x20,
                WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
      }
    }
    else {
      iVar1 = RdCreateRegistryKey((RdDevice *)param_1,local_res8,param_3,uVar2,param_6,param_7,3,
                                  &local_res20,in_stack_ffffffffffffffe8);
      if (iVar1 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x22,
                  WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids);
        }
      }
      else {
        *param_9 = local_res20;
      }
      if (local_res8 != (void *)0x0) {
        ZwClose();
      }
    }
  }
  return iVar1;
}



===== RdCreateRegistryKey @ 140008698 =====

long __thiscall
RdDevice::RdCreateRegistryKey
          (RdDevice *this,void *param_1,_UNICODE_STRING *param_2,uchar param_3,uchar param_4,
          uchar param_5,ulong param_6,void **param_7,ulong *param_8)

{
  long lVar1;
  undefined8 local_38;
  void *local_30;
  _UNICODE_STRING *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_20 = 0x280;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  if (param_4 == '\x01') {
    lVar1 = ZwCreateKey(param_7);
  }
  else {
    lVar1 = ZwOpenKey(param_7,param_6,&local_38);
  }
  return lVar1;
}



===== RdProcessIrpDefault @ 140008720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDevice::RdProcessIrpDefault(RdDevice *this,_IRP *param_1)

{
  undefined1 uVar1;
  long lVar2;
  
  lVar2 = (param_1->IoStatus).field0_0x0.Status;
  uVar1 = *(undefined1 *)(param_1->Tail).Apc.SystemArgument1;
  IofCompleteRequest(param_1,0);
  (**(code **)(this->_padding_ + 0xa8))(this,param_1,uVar1);
  return lVar2;
}



===== RdWdmDeviceObject2RdDevice @ 140008790 =====

RdDevice * __cdecl RdDevice::RdWdmDeviceObject2RdDevice(_DEVICE_OBJECT *param_1)

{
  undefined8 *puVar1;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x1b,
             WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,param_1);
  }
  puVar1 = param_1->DeviceExtension;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000004) == 0x80000004)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x1c,
             WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,(void *)*puVar1);
  }
  return (RdDevice *)*puVar1;
}



===== ReleaseRemoveLock @ 140008830 =====

void __thiscall RdDevice::ReleaseRemoveLock(RdDevice *this,void *param_1,uchar param_2)

{
  if ((param_2 - 2 & 0xef) != 0) {
    IoReleaseRemoveLockEx(this->m_RemoveLock,param_1,0x20);
  }
  return;
}



===== ReleaseRemoveLockAlways @ 140008870 =====

void __thiscall RdDevice::ReleaseRemoveLockAlways(RdDevice *this,void *param_1)

{
  IoReleaseRemoveLockEx(this->m_RemoveLock,param_1,0x20);
  return;
}



===== WPP_SF_SSd @ 14000889c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_SSd(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4,wchar_t *param_5,
          int param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  if (param_5 != (wchar_t *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_5[lVar2] != L'\0');
  }
  if (param_4 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,0x15);
  return;
}



===== WPP_SF_qSSdq @ 140008968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qSSdq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,wchar_t *param_5,
            wchar_t *param_6,int param_7,void *param_8)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  if (param_6 != (wchar_t *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_6[lVar2] != L'\0');
  }
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_c77fc780edcf302de3508ca2750d7a8c_Traceguids,0xc);
  return;
}



===== ~RdFdoDevice @ 140008a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdFdoDevice::~RdFdoDevice(RdFdoDevice *this)

{
  ulong *puVar1;
  RdProcess *pRVar2;
  DEBUG_MODE_FLAGS DVar3;
  uint in_EDX;
  
  this->_padding_ = (longlong)&___7RdFdoDevice__6B_;
  if (this->m_DriverInfo != (_DRIVER_SERVICE_INFO *)0x0) {
    _DRIVER_SERVICE_INFO::_scalar_deleting_destructor_(this->m_DriverInfo,in_EDX);
    this->m_DriverInfo = (_DRIVER_SERVICE_INFO *)0x0;
  }
  if (this->m_DirectlyTerminatedHostProcess != false) {
    WaitForHostProcessExit(this);
  }
  pRVar2 = this->m_RdProcess;
  if (pRVar2 != (RdProcess *)0x0) {
    if ((this->m_DebugModeFlags).Enabled != 0) {
      LOCK();
      (pRVar2->m_DebugModeCounter).Enabled = (pRVar2->m_DebugModeCounter).Enabled - 1;
      UNLOCK();
      if ((this->m_DebugModeFlags).DisablePooling != '\0') {
        LOCK();
        puVar1 = &(pRVar2->m_DebugModeCounter).DisablePooling;
        *puVar1 = *puVar1 - 1;
        UNLOCK();
      }
    }
    (**(code **)(this->m_RdProcess->_padding_ + 8))();
  }
  if (this->m_CloseProcessMsg != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*this->m_CloseProcessMsg + 8))();
  }
  if (-1 < this->m_PrepareSharedResourcesStatus) {
    RdDriver::UnprepareSharedResources((RdDriver *)this->_padding_);
  }
  if (this->m_RundownIoWorkItem != (_IO_WORKITEM *)0x0) {
    IoFreeWorkItem();
    this->m_RundownIoWorkItem = (_IO_WORKITEM *)0x0;
  }
  CloseDiagnosticsKey(this);
  if (this->m_KernelServiceName != (wchar_t *)0x0) {
    operator_delete(this->m_KernelServiceName);
  }
  RdDevice::~RdDevice((RdDevice *)this);
  return;
}



===== ~_DRIVER_SERVICE_INFO @ 140008b6c =====

void __thiscall _DRIVER_SERVICE_INFO::~_DRIVER_SERVICE_INFO(_DRIVER_SERVICE_INFO *this)

{
  _LIST_ENTRY *p_Var1;
  _MODULE_INFO *this_00;
  _LIST_ENTRY *p_Var2;
  _WUDF_MODULE_PDB_INFO *p_Var3;
  code *pcVar4;
  uint in_EDX;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  RdCRLock::Acquire(&this->DriverListLock);
  puVar5 = auStack_28;
  p_Var1 = &this->Head;
  do {
    this_00 = (_MODULE_INFO *)p_Var1->Flink;
    if (this_00 == (_MODULE_INFO *)p_Var1) {
LAB_140008bb7:
      (this->Head).Blink = p_Var1;
      p_Var1->Flink = p_Var1;
      *(undefined8 *)(puVar5 + -8) = 0x140008bc7;
      RdCRLock::Release(&this->DriverListLock);
      p_Var3 = this->WudfxPdbInfo;
      if (p_Var3 != (_WUDF_MODULE_PDB_INFO *)0x0) {
        *(undefined8 *)(puVar5 + -8) = 0x140008bd5;
        operator_delete(p_Var3);
        this->WudfxPdbInfo = (_WUDF_MODULE_PDB_INFO *)0x0;
      }
      p_Var3 = this->WppPdbInfo;
      if (p_Var3 != (_WUDF_MODULE_PDB_INFO *)0x0) {
        *(undefined8 *)(puVar5 + -8) = 0x140008be8;
        operator_delete(p_Var3);
        this->WppPdbInfo = (_WUDF_MODULE_PDB_INFO *)0x0;
      }
      return;
    }
    if (((this_00->NextEntry).Blink != p_Var1) ||
       (p_Var2 = (this_00->NextEntry).Flink, (_MODULE_INFO *)p_Var2->Blink != this_00)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_20;
      goto LAB_140008bb7;
    }
    p_Var1->Flink = p_Var2;
    p_Var2->Blink = p_Var1;
    _MODULE_INFO::_scalar_deleting_destructor_(this_00,in_EDX);
  } while( true );
}



===== ~_MODULE_INFO @ 140008c04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall _MODULE_INFO::~_MODULE_INFO(_MODULE_INFO *this)

{
  _LIST_ENTRY *p_Var1;
  _CX_INFO *this_00;
  _LIST_ENTRY *p_Var2;
  code *pcVar3;
  uint in_EDX;
  
  if (this->Image != (wchar_t *)0x0) {
    operator_delete(this->Image);
  }
  if (this->ServiceName != (wchar_t *)0x0) {
    operator_delete(this->ServiceName);
  }
  if (this->Ifr != (RdIfr *)0x0) {
    (**(code **)(this->Ifr->_padding_ + 8))();
  }
  if (this->PdbInfo != (_WUDF_MODULE_PDB_INFO *)0x0) {
    operator_delete(this->PdbInfo);
  }
  p_Var1 = &this->CxListHead;
  do {
    this_00 = (_CX_INFO *)p_Var1->Flink;
    if (this_00 == (_CX_INFO *)p_Var1) {
LAB_140008c80:
      (this->NextEntry).Blink = &this->NextEntry;
      (this->NextEntry).Flink = &this->NextEntry;
      (this->CxListHead).Blink = p_Var1;
      p_Var1->Flink = p_Var1;
      return;
    }
    if (((this_00->NextEntry).Blink != p_Var1) ||
       (p_Var2 = (this_00->NextEntry).Flink, (_CX_INFO *)p_Var2->Blink != this_00)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      goto LAB_140008c80;
    }
    p_Var1->Flink = p_Var2;
    p_Var2->Blink = p_Var1;
    _CX_INFO::_scalar_deleting_destructor_(this_00,in_EDX);
  } while( true );
}



===== `scalar_deleting_destructor' @ 140008ca0 =====

void * __thiscall RdFdoDevice::_scalar_deleting_destructor_(RdFdoDevice *this,uint param_1)

{
  ~RdFdoDevice(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140008cd8 =====

void * __thiscall _CX_INFO::_scalar_deleting_destructor_(_CX_INFO *this,uint param_1)

{
  this->ModuleInfo = (void *)0x0;
  (this->NextEntry).Blink = &this->NextEntry;
  (this->NextEntry).Flink = &this->NextEntry;
  operator_delete(this);
  return this;
}



===== `scalar_deleting_destructor' @ 140008d04 =====

void * __thiscall
_DRIVER_SERVICE_INFO::_scalar_deleting_destructor_(_DRIVER_SERVICE_INFO *this,uint param_1)

{
  ~_DRIVER_SERVICE_INFO(this);
  operator_delete(this);
  return this;
}



===== `scalar_deleting_destructor' @ 140008d2c =====

void * __thiscall _MODULE_INFO::_scalar_deleting_destructor_(_MODULE_INFO *this,uint param_1)

{
  ~_MODULE_INFO(this);
  operator_delete(this);
  return this;
}



===== CloseDiagnosticsKey @ 140008d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall RdFdoDevice::CloseDiagnosticsKey(RdFdoDevice *this)

{
  longlong lVar1;
  wchar_t **ppwVar2;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  wchar_t *local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  uStack_40 = 0;
  if (this->m_DiagnosticsSubKey != (void *)0x0) {
    lVar1 = 4;
    local_38[0] = L"HostPid";
    ppwVar2 = local_38;
    local_38[1] = L"RwTransferMode";
    local_38[2] = L"IoctlTransferMode";
    local_38[3] = L"RetrievalMode";
    do {
      RtlInitUnicodeString(&local_48,*ppwVar2);
      ZwDeleteValueKey(this->m_DiagnosticsSubKey,&local_48);
      ppwVar2 = ppwVar2 + 1;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    ZwClose(this->m_DiagnosticsSubKey);
    this->m_DiagnosticsSubKey = (void *)0x0;
  }
  return;
}



===== DisableDevice @ 140008e38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

void __thiscall
RdFdoDevice::DisableDevice(RdFdoDevice *this,WUDF_PROBLEM *param_1,wchar_t *param_2,ulong param_3)

{
  _WUDFMESSAGE _Var1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  code *pcVar6;
  undefined1 uVar7;
  short sVar8;
  WdfComponentType WVar9;
  undefined1 uVar10;
  short sVar11;
  _WDF_HOST_EXIT_CODE _Var12;
  undefined1 uVar13;
  short sVar14;
  WudfOperationType WVar15;
  undefined1 uVar16;
  short sVar17;
  ushort uVar18;
  undefined3 uVar19;
  byte bVar20;
  uint uVar21;
  long lVar22;
  void *pvVar23;
  _RD_DEBUG_TRIAGE_BLOCK *p_Var24;
  _EPROCESS *p_Var25;
  _EPROCESS *p_Var26;
  int iVar27;
  WPP_PROJECT_CONTROL_BLOCK *pWVar28;
  _RD_DEBUG_TRIAGE_BLOCK *p_Var29;
  _GUID *p_Var30;
  wchar_t *pwVar31;
  bool bVar32;
  undefined1 auStackY_178 [32];
  _KEY_VALUE_PARTIAL_INFORMATION *local_100;
  longlong local_f8;
  longlong local_f0;
  _RD_DEBUG_TRIAGE_BLOCK local_e8;
  undefined4 local_98;
  _GUID local_94;
  undefined4 local_84;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_178;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    uVar2._0_1_ = param_1->ProblemCode;
    uVar2._1_1_ = param_1->field_0x1;
    uVar2._2_2_ = param_1->_padding_;
    uVar3._0_1_ = param_1->Operation;
    uVar3._1_1_ = param_1->field_0xd;
    uVar3._2_2_ = param_1->_padding_;
    WPP_SF_LLLDd((WPP_GLOBAL_Control->Control).Logger,(ushort)param_1->Message,
                 (_GUID *)&WPP_GLOBAL_Control->Control,uVar2,uVar3,(uint)param_1->Message,
                 (uint)param_1->IrpInfo,param_1->Status);
  }
  LOCK();
  bVar32 = this->m_DeviceDisabled == 0;
  if (bVar32) {
    this->m_DeviceDisabled = 1;
  }
  UNLOCK();
  if (bVar32) {
    this->m_HasProblem = true;
    uVar7 = param_1->field_0x1;
    sVar8 = param_1->_padding_;
    WVar9 = param_1->Detector;
    uVar10 = param_1->field_0x5;
    sVar11 = param_1->_padding_;
    _Var12 = param_1->ExitCode;
    uVar13 = param_1->field_0x9;
    sVar14 = param_1->_padding_;
    WVar15 = param_1->Operation;
    uVar16 = param_1->field_0xd;
    sVar17 = param_1->_padding_;
    (this->m_HostProblem).ProblemCode = param_1->ProblemCode;
    (this->m_HostProblem).field_0x1 = uVar7;
    (this->m_HostProblem)._padding_ = sVar8;
    (this->m_HostProblem).Detector = WVar9;
    (this->m_HostProblem).field_0x5 = uVar10;
    (this->m_HostProblem)._padding_ = sVar11;
    (this->m_HostProblem).ExitCode = _Var12;
    (this->m_HostProblem).field_0x9 = uVar13;
    (this->m_HostProblem)._padding_ = sVar14;
    (this->m_HostProblem).Operation = WVar15;
    (this->m_HostProblem).field_0xd = uVar16;
    (this->m_HostProblem)._padding_ = sVar17;
    uVar7 = param_1->field_0x11;
    uVar18 = param_1->IrpInfo;
    lVar22 = param_1->Status;
    (this->m_HostProblem).Message = param_1->Message;
    (this->m_HostProblem).field_0x11 = uVar7;
    (this->m_HostProblem).IrpInfo = uVar18;
    (this->m_HostProblem).Status = lVar22;
    uVar19 = *(undefined3 *)&param_1->field_0x19;
    (this->m_HostProblem).DeviceStarted = param_1->DeviceStarted;
    *(undefined3 *)&(this->m_HostProblem).field_0x19 = uVar19;
    if (this->m_StartDeviceNtStatus < 0) {
      iVar27 = 1;
    }
    else {
      iVar27 = ((char)this->_padding_ != '\0') + 2;
    }
    *(int *)&(this->m_HostProblem).DeviceStarted = iVar27;
    local_78 = 0xffffffff;
    local_94 = GUID_WUDF_DEVICE_HOST_PROBLEM;
    local_84 = 0;
    local_74 = 0;
    local_98 = 0x240001;
    local_80 = 0;
    uVar21 = IoReportTargetDeviceChangeAsynchronous(this->m_Pdo,&local_98,0,0);
    if ((int)uVar21 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xc,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar21);
      }
    }
    else if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
             (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
            (3 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,
              WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
    }
    bVar20 = ShouldBreakIntoKdOnHostFailure(this,param_1);
    pWVar28 = WPP_GLOBAL_Control;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      pvVar23 = (void *)PsGetCurrentProcess();
      if (this->m_RdProcess == (RdProcess *)0x0) {
        p_Var30 = (_GUID *)0x0;
      }
      else {
        p_Var30 = (_GUID *)this->m_RdProcess->m_EProcess;
      }
      _Var1 = param_1->Message;
      pWVar28 = (WPP_PROJECT_CONTROL_BLOCK *)(ulonglong)_Var1;
      uVar4._0_1_ = param_1->Operation;
      uVar4._1_1_ = param_1->field_0xd;
      uVar4._2_2_ = param_1->_padding_;
      uVar5._0_1_ = param_1->ProblemCode;
      uVar5._1_1_ = param_1->field_0x1;
      uVar5._2_2_ = param_1->_padding_;
      WPP_SF_qqLLLDLdqql((WPP_GLOBAL_Control->Control).Logger,(ushort)_Var1,p_Var30,this,
                         (void *)this->_padding_,uVar5,uVar4,(uint)_Var1,(uint)param_1->IrpInfo,
                         *(ulong *)&param_1->DeviceStarted,param_1->Status,p_Var30,pvVar23,
                         (uint)bVar20);
    }
    if (bVar20 != 0) {
      memset();
      local_100 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
      local_70 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      bVar20 = KeGetCurrentIrql();
      pwVar31 = L"!wudfext.";
      if (this->m_IsLegacyStack == false) {
        pwVar31 = L"!wdfkd.wdf";
      }
      local_f0 = PsGetCurrentProcess();
      local_f8 = *(longlong *)(this->_padding_ + 0x1c8);
      bVar32 = local_f8 == local_f0;
      p_Var24 = (_RD_DEBUG_TRIAGE_BLOCK *)ExAllocatePool2(0x40,0x50,0x30444d55);
      p_Var29 = &local_e8;
      if (p_Var24 != (_RD_DEBUG_TRIAGE_BLOCK *)0x0) {
        p_Var29 = p_Var24;
      }
      memset();
      p_Var29->Problem = param_1;
      p_Var29->DeviceObject = (_DEVICE_OBJECT *)this->_padding_;
      p_Var29->DevnodeContext = this->m_DevnodeContext;
      p_Var25 = (_EPROCESS *)0x0;
      if (this->m_RdProcess != (RdProcess *)0x0) {
        p_Var25 = this->m_RdProcess->m_EProcess;
      }
      p_Var29->HostProcess = p_Var25;
      p_Var29->CurrentReflectorThread = SystemReserved1[0xf];
      p_Var29->DriverManagerProcess = *(_EPROCESS **)(this->_padding_ + 0x1c8);
      p_Var29->PdoName = (wchar_t *)this->_padding_;
      p_Var29->DriverManagerBreak = bVar32;
      p_Var29->IsLegacyStack = this->m_IsLegacyStack;
      if ((bVar20 == 0) && (lVar22 = GetDriverListFromRegistry(this,&local_100), -1 < lVar22)) {
        uVar18 = (ushort)local_100->DataLength;
        (p_Var29->DriverList).MaximumLength = uVar18;
        (p_Var29->DriverList).Length = uVar18 - 2;
        (p_Var29->DriverList).Buffer = (wchar_t *)local_100->Data;
      }
      if (local_f8 == local_f0) {
        DbgPrintEx(0x65,0,
                   "\n**** Problem detected in Driver Manager Service. !process 0x%p 0x1f Problem code %d ****\n"
                   ,p_Var29->DriverManagerProcess);
        DbgPrintEx(0x65,0,"**** Dump the driver manager information: !wudfext.drvmgr\n");
      }
      else {
        if ((p_Var29->DriverList).Buffer == (wchar_t *)0x0) {
          DbgPrintEx(0x65,0,
                     "\n**** Problem detected in UMDF driver. !process 0x%p 0x1f, !devstack 0x%p, Problem code %d ****\n"
                     ,p_Var29->HostProcess);
        }
        else {
          DbgPrintEx(0x65,0,
                     "\n**** Problem detected in UMDF driver \"%S\". !process 0x%p 0x1f, !devstack 0x%p, Problem code %d ****\n"
                    );
        }
        DbgPrintEx(0x65,0,"**** Dump UMDF driver image name and stack: %Sumdevstack 0x%p\n",pwVar31)
        ;
        DbgPrintEx(0x65,0,"**** Dump UM Irps for this stack: %Sumirps 0x%p\n",pwVar31);
        DbgPrintEx(0x65,0,"**** Dump UMDF trace log: !wmitrace.logdump WUDFTrace\n");
        DbgPrintEx(0x65,0,"**** Helpful UMDF debugger extension commands: %Shelp\n",pwVar31);
        DbgPrintEx(0x65,0,
                   "**** Note that driver host process may get terminated if you go past this break, making it difficult to debug the problem!\n\n"
                  );
        if ((((bVar20 < 2) && (this->m_RdProcess != (RdProcess *)0x0)) &&
            (p_Var25 = this->m_RdProcess->m_EProcess, p_Var25 != (_EPROCESS *)0x0)) &&
           (p_Var26 = (_EPROCESS *)PsGetCurrentProcess(), p_Var26 != p_Var25)) {
          KeStackAttachProcess(this->m_RdProcess->m_EProcess,&local_70);
        }
      }
      KeAcquireSpinLockRaiseToDpc(this->_padding_ + 0x1d0);
      pcVar6 = (code *)swi(3);
      RdDebugTriage = p_Var29;
      (*pcVar6)();
      return;
    }
    if (this->m_IsCompanion == '\0') {
      IoInvalidateDeviceState(this->m_Pdo);
    }
    else {
      (**(code **)*this->m_CompanionCallback)();
    }
    if (-1 < this->m_OpenProcessNtStatus) {
      SendCloseProcessMessage(this,(_IRP *)&pWVar28->Control);
    }
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xe,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids
           );
  }
  return;
}



===== GetDriverImageNameFromRegistry @ 140009484 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
RdFdoDevice::GetDriverImageNameFromRegistry
          (RdFdoDevice *this,void *param_1,wchar_t **param_2,ulong *param_3)

{
  short sVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  undefined8 uVar7;
  wchar_t *pwVar8;
  uint uVar9;
  short *psVar10;
  undefined1 auStack_a8 [32];
  int local_88;
  int *local_80;
  int local_78 [2];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 local_60 [32];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  uStack_68 = 0;
  local_78[0] = 0;
  RtlInitUnicodeString(&local_70,L"ImagePath");
  local_80 = local_78;
  local_88 = 0;
  iVar4 = ZwQueryValueKey(param_1,&local_70,1,local_60);
  iVar3 = local_78[0];
  if ((iVar4 == -0x3fffffdd) || (iVar4 == -0x7ffffffb)) {
    pvVar6 = (void *)ExAllocatePool2(0x40,local_78[0],0x30444d55);
    if (pvVar6 == (void *)0x0) {
      iVar4 = -0x3fffff66;
    }
    else {
      memset();
      local_80 = local_78;
      local_88 = iVar3;
      iVar4 = ZwQueryValueKey(param_1,&local_70,1,pvVar6);
      if (((iVar4 == 0) && (local_78[0] == iVar3)) && (*param_2 == (wchar_t *)0x0)) {
        psVar10 = (short *)((ulonglong)*(uint *)((longlong)pvVar6 + 8) + (longlong)pvVar6);
        auVar2 = ZEXT816(2) * ZEXT416(*(uint *)((longlong)pvVar6 + 0xc));
        uVar7 = auVar2._0_8_;
        if (auVar2._8_8_ != 0) {
          uVar7 = 0xffffffffffffffff;
        }
        pwVar8 = (wchar_t *)ExAllocatePool2(0x40,uVar7,0x30444d55);
        *param_2 = pwVar8;
        if (pwVar8 == (wchar_t *)0x0) {
          iVar4 = -0x3fffff66;
        }
        else {
          uVar9 = 0;
          if (*psVar10 != 0) {
            do {
              if (*(uint *)((longlong)pvVar6 + 0xc) <= (uVar9 & 0xffff)) break;
              sVar1 = *psVar10;
              psVar10 = psVar10 + 1;
              uVar5 = 0;
              if (sVar1 != 0x5c) {
                uVar5 = uVar9 & 0xffff;
              }
              uVar9 = uVar5 + 2;
            } while (*psVar10 != 0);
          }
          memcpy();
          *param_3 = uVar9 & 0xffff;
        }
      }
      operator_delete(pvVar6);
    }
  }
  return iVar4;
}



===== GetDriverListFromRegistry @ 140009658 =====

long __thiscall
RdFdoDevice::GetDriverListFromRegistry(RdFdoDevice *this,_KEY_VALUE_PARTIAL_INFORMATION **param_1)

{
  uint uVar1;
  RdDevice *this_00;
  RdFdoDevice *this_01;
  ushort uVar2;
  void *pvVar3;
  ulong in_R8D;
  void *local_res8;
  void *local_res10;
  _UNICODE_STRING *in_stack_ffffffffffffff88;
  uchar in_stack_ffffffffffffff90;
  ulong in_stack_ffffffffffffffa8;
  ulong *in_stack_ffffffffffffffb8;
  _UNICODE_STRING local_38;
  _UNICODE_STRING local_28;
  
  *param_1 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
  local_res8 = (void *)0x0;
  this_00 = (RdDevice *)&local_38;
  local_38.Length = 0;
  local_38.MaximumLength = 0;
  local_38._4_4_ = 0;
  local_38.Buffer = (wchar_t *)0x0;
  RtlInitUnicodeString(this_00,&u_WUDF);
  uVar1 = RdDevice::RdCreatePnpRegKey
                    (this_00,this->m_Pdo,in_R8D,&local_38,in_stack_ffffffffffffff88,
                     in_stack_ffffffffffffff90,'\0','\0',in_stack_ffffffffffffffa8,&local_res8,
                     in_stack_ffffffffffffffb8);
  pvVar3 = local_res8;
  if ((int)uVar1 < 0) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return uVar1;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0) {
      return uVar1;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return uVar1;
    }
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x40,
             WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar1);
    return uVar1;
  }
  local_res10 = (void *)0x0;
  uVar1 = OpenCompanionConfigRegKey(this,local_res8,&local_res10);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_1400097eb;
    uVar2 = 0x41;
  }
  else {
    ZwClose(pvVar3);
    pvVar3 = local_res10;
    this_01 = (RdFdoDevice *)&local_38;
    RtlInitUnicodeString(this_01,L"CompanionServiceList");
    local_28.Length = local_38.Length;
    local_28.MaximumLength = local_38.MaximumLength;
    local_28._4_4_ = local_38._4_4_;
    local_28.Buffer = local_38.Buffer;
    uVar1 = ReadMultiStringFromRegistry(this_01,pvVar3,&local_28,param_1);
    if ((((-1 < (int)uVar1) ||
         (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_1400097eb;
    uVar2 = 0x42;
  }
  WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar2,
           WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar1);
LAB_1400097eb:
  ZwClose(pvVar3);
  return uVar1;
}



===== GetDwordInfoFromRegistry @ 14000981c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
RdFdoDevice::GetDwordInfoFromRegistry
          (RdFdoDevice *this,void *param_1,wchar_t *param_2,ulong *param_3)

{
  int iVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  int *local_40;
  int local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_38[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_30,param_2);
  local_40 = local_38;
  local_48 = 0x10;
  iVar1 = ZwQueryValueKey(param_1,&local_30,2,&local_20);
  if ((iVar1 == 0) && (local_38[0] == 0x10)) {
    *param_3 = uStack_18._4_4_;
  }
  return iVar1;
}



===== MapToSendProblem @ 1400098c4 =====

WudfProblem __cdecl RdFdoDevice::MapToSendProblem(long param_1)

{
  if (param_1 == -0x3ffffbb0) {
    return WudfProblem_Disconnect;
  }
  return WudfProblem_Timeout - (param_1 != -0x3fffff4b);
}



===== MarkForDelete @ 1400098f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall RdFdoDevice::MarkForDelete(RdFdoDevice *this)

{
  uchar *in_R8;
  
  if ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList !=
      (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
    WdfObjectList<RdProcess,RdProcessParameters>::Remove
              ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList,(RdProcess *)this,
               in_R8);
  }
  RdDevice::MarkForDelete((RdDevice *)this);
  if (this->m_PreAllocatedSynchronousTaskMsg != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*this->m_PreAllocatedSynchronousTaskMsg + 8))();
    this->m_PreAllocatedSynchronousTaskMsg = (IUMDFLPCMessage *)0x0;
  }
  return;
}



===== PopulateDriverInfo @ 140009944 =====

long __thiscall RdFdoDevice::PopulateDriverInfo(RdFdoDevice *this)

{
  _LIST_ENTRY *p_Var1;
  short sVar2;
  _KEY_VALUE_PARTIAL_INFORMATION *p_Var3;
  ushort uVar4;
  long lVar5;
  _DRIVER_SERVICE_INFO *p_Var6;
  ushort uVar7;
  uint uVar8;
  _KEY_VALUE_PARTIAL_INFORMATION **pp_Var9;
  ushort uVar10;
  uchar *puVar11;
  uchar *puVar12;
  _KEY_VALUE_PARTIAL_INFORMATION *local_res8;
  _LIST_ENTRY *in_stack_ffffffffffffffc8;
  
  local_res8 = (_KEY_VALUE_PARTIAL_INFORMATION *)0x0;
  uVar8 = 0x48;
  p_Var6 = (_DRIVER_SERVICE_INFO *)ExAllocatePool2(0x40,0x48,0x30444d55);
  if (p_Var6 == (_DRIVER_SERVICE_INFO *)0x0) {
    p_Var6 = (_DRIVER_SERVICE_INFO *)0x0;
  }
  else {
    uVar8 = 1;
    (p_Var6->DriverListLock).m_OwningThread = (_KTHREAD *)0x0;
    KeInitializeEvent(&p_Var6->DriverListLock,1,1);
    p_Var1 = &p_Var6->Head;
    p_Var6->Count = 0;
    (p_Var6->Head).Blink = p_Var1;
    p_Var1->Flink = p_Var1;
    p_Var6->WudfxPdbInfo = (_WUDF_MODULE_PDB_INFO *)0x0;
    p_Var6->WppPdbInfo = (_WUDF_MODULE_PDB_INFO *)0x0;
  }
  this->m_DriverInfo = p_Var6;
  if (p_Var6 == (_DRIVER_SERVICE_INFO *)0x0) {
    lVar5 = -0x3fffff66;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      uVar8 = 0x3b;
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x3b,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,0xc000009a);
    }
    goto LAB_140009c5f;
  }
  pp_Var9 = &local_res8;
  lVar5 = GetDriverListFromRegistry(this,pp_Var9);
  p_Var3 = local_res8;
  uVar8 = (uint)pp_Var9;
  if (-1 < lVar5) {
    uVar10 = (ushort)local_res8->DataLength;
    puVar11 = local_res8->Data;
    uVar7 = uVar10 - 2;
    uVar8 = (uint)uVar7;
    if ((((((uVar7 | uVar10) & 1) == 0) && (uVar10 != 0)) && (uVar7 != 0)) &&
       ((((ulonglong)uVar7 + 2 <= (ulonglong)uVar10 &&
         (*(short *)(puVar11 + (ulonglong)(uint)(uVar7 >> 1) * 2) == 0)) &&
        (*(short *)(puVar11 + (ulonglong)((uVar7 >> 1) - 1) * 2) == 0)))) {
      lVar5 = 0;
      uVar7 = 0;
      uVar10 = 0;
      uVar8 = 0;
      if (*(short *)puVar11 == 0) {
LAB_140009bda:
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140009c4e;
        uVar8 = 0x3d;
      }
      else {
        puVar12 = puVar11;
        do {
          if (local_res8->DataLength <= (uint)uVar10) break;
          sVar2 = *(short *)(puVar12 + 2);
          if (sVar2 == 0) {
            puVar12 = puVar12 + 2;
          }
          puVar12 = puVar12 + 2;
          uVar4 = uVar10 + 2;
          if (sVar2 != 0) {
            uVar4 = uVar10;
          }
          uVar10 = uVar4 + 2;
          uVar4 = uVar7 + 1;
          if (sVar2 != 0) {
            uVar4 = uVar7;
          }
          uVar7 = uVar4;
        } while (*(short *)puVar12 != 0);
        if (uVar7 == 0) goto LAB_140009bda;
        if (uVar7 < 2) {
          uVar10 = 0;
          puVar12 = puVar11;
          uVar8 = 0;
          do {
            if ((*(wchar_t *)puVar12 == L'\0') || (p_Var3->DataLength <= (uint)uVar10))
            goto LAB_140009c4e;
            uVar7 = (short)uVar8 + 1;
            uVar8 = (uint)uVar7;
            if (*(wchar_t *)(puVar12 + 2) == L'\0') {
              lVar5 = PopulateDriverInfoWorker
                                (this,(wchar_t *)puVar11,uVar7,&this->m_DriverInfo->Count,
                                 in_stack_ffffffffffffffc8);
              uVar8 = (uint)puVar11;
              if (lVar5 < 0) {
                if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
                   (1 < (WPP_GLOBAL_Control->Control).Level)) {
                  uVar8 = 0x3f;
                  goto LAB_140009bff;
                }
                goto LAB_140009c4e;
              }
              uVar10 = uVar10 + 2;
              uVar8 = 0;
              puVar11 = puVar12 + 4;
              puVar12 = puVar11;
            }
            else {
              puVar12 = puVar12 + 2;
            }
            uVar10 = uVar10 + 2;
          } while( true );
        }
        lVar5 = -0x3ffffe7e;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140009c4e;
        uVar8 = 0x3e;
      }
LAB_140009bff:
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,(ushort)uVar8,
              WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
    }
    else {
      lVar5 = -0x3ffffff3;
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        uVar8 = 0x3c;
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x3c,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,0xc000000d);
      }
    }
  }
LAB_140009c4e:
  if (p_Var3 != (_KEY_VALUE_PARTIAL_INFORMATION *)0x0) {
    operator_delete(p_Var3);
  }
  if (-1 < lVar5) {
    return lVar5;
  }
LAB_140009c5f:
  if (this->m_DriverInfo != (_DRIVER_SERVICE_INFO *)0x0) {
    _DRIVER_SERVICE_INFO::_scalar_deleting_destructor_(this->m_DriverInfo,uVar8);
    this->m_DriverInfo = (_DRIVER_SERVICE_INFO *)0x0;
  }
  return lVar5;
}



===== PopulateDriverInfoWorker @ 140009ca0 =====

long __thiscall
RdFdoDevice::PopulateDriverInfoWorker
          (RdFdoDevice *this,wchar_t *param_1,ushort param_2,ushort *param_3,_LIST_ENTRY *param_4)

{
  _DRIVER_SERVICE_INFO *p_Var1;
  code *pcVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  _MODULE_INFO *this_00;
  undefined8 uVar5;
  wchar_t *pwVar6;
  _LIST_ENTRY *p_Var7;
  RdFdoDevice *this_01;
  ulong64 uVar8;
  _LIST_ENTRY *p_Var9;
  ushort uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined6 in_register_00000082;
  bool bVar14;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  CUmdfSvcConfig local_38;
  
  local_38.m_AutoClose = '\x01';
  param_4 = (_LIST_ENTRY *)0x0;
  local_38.m_Key = (void *)0x0;
  uVar4 = CUmdfSvcConfig::OpenServiceKey
                    (&local_38,param_1,(ulong)CONCAT62(in_register_00000082,param_2),&param_4);
  if ((int)uVar4 < 0) {
    puVar13 = auStackY_68;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (puVar13 = auStackY_68, ((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
       (puVar13 = auStackY_68, (WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000a029;
    uVar10 = 0x32;
  }
  else {
    this_01 = (RdFdoDevice *)0x40;
    this_00 = (_MODULE_INFO *)ExAllocatePool2(0x40,0x58,0x30444d55);
    p_Var9 = param_4;
    if (this_00 != (_MODULE_INFO *)0x0) {
      this_00->Image = (wchar_t *)0x0;
      this_00->MajorVersionNumber = 0;
      this_00->MinorVersionNumber = 0;
      this_00->ImageNameLengthCb = 0;
      this_00->ServiceName = (wchar_t *)0x0;
      this_00->ServiceNameLengthCb = 0;
      this_00->Ifr = (RdIfr *)0x0;
      this_00->PdbInfo = (_WUDF_MODULE_PDB_INFO *)0x0;
      (this_00->NextEntry).Blink = (_LIST_ENTRY *)this_00;
      (this_00->NextEntry).Flink = (_LIST_ENTRY *)this_00;
      p_Var7 = &this_00->CxListHead;
      (this_00->CxListHead).Blink = p_Var7;
      p_Var7->Flink = p_Var7;
      p_Var7 = param_4;
      uVar4 = GetDriverImageNameFromRegistry
                        (this_01,param_4,&this_00->Image,&this_00->ImageNameLengthCb);
      uVar11 = (uint)p_Var7;
      if ((int)uVar4 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (uVar11 = (WPP_GLOBAL_Control->Control).Flags[0], (uVar11 & 0x10) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar11 = 0x35;
LAB_140009dc7:
          uVar8 = (WPP_GLOBAL_Control->Control).Logger;
LAB_140009f67:
          WPP_SF_D(uVar8,(ushort)uVar11,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar4);
        }
      }
      else {
        p_Var7 = p_Var9;
        uVar4 = GetDwordInfoFromRegistry
                          (this_01,p_Var9,L"WdfMajorVersion",&this_00->MajorVersionNumber);
        uVar11 = (uint)p_Var7;
        if ((int)uVar4 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar11 = 0x36;
            goto LAB_140009dc7;
          }
        }
        else {
          bVar14 = this_00->MajorVersionNumber < 2;
          if (*param_3 == 0) {
            this->m_IsLegacyStack = bVar14;
          }
          else if (this->m_IsLegacyStack != bVar14) {
            uVar4 = 0xc000000d;
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
               (1 < (WPP_GLOBAL_Control->Control).Level)) {
              uVar11 = 0x37;
              WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x37,
                        WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this,-0x3ffffff3);
            }
            goto LAB_140009f76;
          }
          uVar4 = GetDwordInfoFromRegistry
                            (this_01,p_Var9,L"WdfMinorVersion",&this_00->MinorVersionNumber);
          uVar11 = (uint)p_Var9;
          if (-1 < (int)uVar4) {
            this_00->Ifr = (RdIfr *)0x0;
            this_00->ServiceNameLengthCb = (uint)param_2 * 2 + 2;
            auVar3 = ZEXT816(2) * ZEXT416(param_2 + 1);
            uVar5 = auVar3._0_8_;
            if (auVar3._8_8_ != 0) {
              uVar5 = 0xffffffffffffffff;
            }
            pwVar6 = (wchar_t *)ExAllocatePool2(0x40,uVar5,0x30444d55);
            uVar11 = (uint)uVar5;
            this_00->ServiceName = pwVar6;
            if (pwVar6 != (wchar_t *)0x0) {
              memcpy();
              this_00->ServiceName[param_2] = L'\0';
              RdCRLock::Acquire(&this->m_DriverInfo->DriverListLock);
              puVar12 = auStackY_68;
              p_Var7 = &this->m_DriverInfo->Head;
              p_Var9 = (this->m_DriverInfo->Head).Blink;
              if (p_Var9->Flink != p_Var7) {
                p_Var9 = (_LIST_ENTRY *)0x3;
                pcVar2 = (code *)swi(0x29);
                p_Var7 = (_LIST_ENTRY *)(*pcVar2)();
                puVar12 = auStackY_60;
              }
              (this_00->NextEntry).Blink = p_Var9;
              (this_00->NextEntry).Flink = p_Var7;
              p_Var9->Flink = (_LIST_ENTRY *)this_00;
              p_Var7->Blink = (_LIST_ENTRY *)this_00;
              *param_3 = *param_3 + 1;
              p_Var1 = this->m_DriverInfo;
              *(undefined8 *)(puVar12 + -8) = 0x140009fe9;
              RdCRLock::Release(&p_Var1->DriverListLock);
              puVar13 = puVar12;
              goto LAB_14000a029;
            }
            uVar4 = 0xc000009a;
            if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
               ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_140009f76;
            uVar8 = (WPP_GLOBAL_Control->Control).Logger;
            uVar11 = 0x3a;
            uVar4 = 0xc000009a;
            goto LAB_140009f67;
          }
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar11 = 0x38;
            goto LAB_140009dc7;
          }
        }
      }
LAB_140009f76:
      _MODULE_INFO::_scalar_deleting_destructor_(this_00,uVar11);
      puVar13 = auStackY_68;
      goto LAB_14000a029;
    }
    uVar4 = 0xc000009a;
    puVar13 = auStackY_68;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (puVar13 = auStackY_68, ((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
       (puVar13 = auStackY_68, (WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000a029;
    uVar10 = 0x33;
    uVar4 = 0xc000009a;
  }
  WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar10,
           WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar4);
  puVar13 = auStackY_68;
LAB_14000a029:
  *(undefined8 *)(puVar13 + -8) = 0x14000a033;
  CUmdfSvcConfig::~CUmdfSvcConfig((CUmdfSvcConfig *)(puVar13 + 0x30));
  return uVar4;
}



===== RdCloseProcessReply @ 14000a05c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall
RdFdoDevice::RdCloseProcessReply
          (RdFdoDevice *this,IUMDFLPCMessage *param_1,_WUDFMESSAGE_REPLY_HEADER *param_2,
          ulong64 param_3,WUDF_PROBLEM *param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 local_res20;
  undefined8 in_stack_ffffffffffffff88;
  uint uVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar3 = (uint)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_res20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (param_2->NtStatus < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x2b,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,param_2->NtStatus);
    }
    uStack_40 = 0;
    local_38 = 0;
    local_48 = CONCAT44(local_48._4_4_,0x30);
    uStack_30 = CONCAT44(uStack_30._4_4_,0x200);
    local_28 = 0;
    uStack_20 = 0;
    local_58 = PsGetProcessId(this->m_RdProcess->m_EProcess);
    uStack_50 = 0;
    uVar1 = ZwOpenProcess(&local_res20,0x1fffff,&local_48,&local_58);
    if ((int)uVar1 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x2c,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar1);
      }
    }
    else {
      uVar1 = ZwTerminateProcess(local_res20,param_2->NtStatus);
      if ((((int)uVar1 < 0) &&
          (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
         ((((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0 &&
          (1 < (WPP_GLOBAL_Control->Control).Level)))) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x2d,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar1);
      }
      this->m_DirectlyTerminatedHostProcess = true;
      ZwClose(local_res20);
    }
    if (this->m_RdProcess != (RdProcess *)0x0) {
      RdProcess::DisableProcess(this->m_RdProcess);
    }
  }
  iVar2 = IoSetDevicePropertyData
                    (this->m_Pdo,&DEVPKEY_Device_WudfHostProcessId,0,0,(ulonglong)uVar3 << 0x20,0,0)
  ;
  if ((((iVar2 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
      (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
     (4 < (WPP_GLOBAL_Control->Control).Level)) {
    WPP_SF_qqd((WPP_GLOBAL_Control->Control).Logger,0x2e,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this,(void *)this->_padding_,iVar2);
  }
  KeSetEvent(&this->m_HostProcessCloseDone,0,0);
  (**(code **)((longlong)*param_1 + 8))(param_1);
  return;
}



===== RdCloseProcessReply @ 14000a2a0 =====

void __cdecl
RdFdoDevice::RdCloseProcessReply
          (IUMDFLPCMessage *param_1,void *param_2,_WUDFMESSAGE_REPLY_HEADER *param_3,ulong64 param_4
          ,WUDF_PROBLEM *param_5)

{
  WUDF_PROBLEM *in_stack_ffffffffffffffe8;
  
  RdCloseProcessReply(param_2,param_1,param_3,param_4,in_stack_ffffffffffffffe8);
  return;
}



===== RdSendOpenProcessMessageToDrvMgr @ 14000a2c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdFdoDevice::RdSendOpenProcessMessageToDrvMgr(RdFdoDevice *this)

{
  IUMDFLPCMessage *pIVar1;
  IUMDFLPCMessage *pIVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ushort uVar6;
  uint uVar7;
  _GUID *p_Var8;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x15,
            WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
  }
  if (((RdDriver *)this->_padding_)->m_DriverManagerLpcComm == (IUMDFLPCCommPortInterface *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (2 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x1c,
              WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
    }
    uVar7 = 0xc0000034;
    goto LAB_14000a5a0;
  }
  pIVar1 = RdDriver::CloseProcessMessage((RdDriver *)this->_padding_);
  this->m_CloseProcessMsg = pIVar1;
  if (pIVar1 != (IUMDFLPCMessage *)0x0) {
    pIVar1 = RdDriver::QueryProcessMessage
                       ((RdDriver *)this->_padding_,(wchar_t *)this->_padding_,this->m_IsCompanion,
                        this->m_KernelServiceName);
    if (pIVar1 != (IUMDFLPCMessage *)0x0) {
      pIVar2 = RdDriver::OpenProcessMessage
                         ((RdDriver *)this->_padding_,(wchar_t *)this->_padding_,this->m_IsCompanion
                          ,this->m_KernelServiceName);
      if (pIVar2 == (IUMDFLPCMessage *)0x0) {
        uVar7 = 0xc000009a;
      }
      else {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (3 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0x16,
                   WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,(wchar_t *)this->_padding_);
        }
        p_Var8 = (_GUID *)0x0;
        uVar6 = 0x2e80;
        puVar3 = (uint *)(**(code **)((longlong)*pIVar1 + 0x28))(pIVar1);
        if (puVar3 == (uint *)0x0) {
          uVar7 = 0xc000009a;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar6 = 0x17;
LAB_14000a415:
            uVar7 = 0xc000009a;
            WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar6,
                    WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
          }
        }
        else {
          uVar7 = *puVar3;
          if ((int)uVar7 < 0) {
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
               (1 < (WPP_GLOBAL_Control->Control).Level)) {
              uVar6 = 0x18;
LAB_14000a456:
              WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar6,
                       WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar7);
            }
          }
          else {
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
               (3 < (WPP_GLOBAL_Control->Control).Level)) {
              WPP_SF_SDD((WPP_GLOBAL_Control->Control).Logger,uVar6,p_Var8,
                         (wchar_t *)this->_padding_,puVar3[1],puVar3[2]);
            }
            uVar5 = 0xffffffff;
            if (((byte)puVar3[2] & 5) != 5) {
              uVar5 = (ulonglong)puVar3[1];
            }
            puVar3 = (uint *)(**(code **)((longlong)*pIVar2 + 0x28))(pIVar2,uVar5 * -10000000,0);
            if (puVar3 == (uint *)0x0) {
              uVar7 = 0xc000009a;
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
                 (1 < (WPP_GLOBAL_Control->Control).Level)) {
                uVar6 = 0x1a;
                goto LAB_14000a415;
              }
            }
            else {
              uVar7 = *puVar3;
              this->m_OpenProcessNtStatus = uVar7;
              if ((int)uVar7 < 0) {
                if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
                   (1 < (WPP_GLOBAL_Control->Control).Level)) {
                  uVar6 = 0x1b;
                  goto LAB_14000a456;
                }
              }
              else {
                uVar7 = 0;
                lVar4 = (**(code **)((longlong)*this->m_CloseProcessMsg + 0x18))
                                  (this->m_CloseProcessMsg,0x28);
                *(undefined8 *)(lVar4 + 0x20) = *(undefined8 *)(puVar3 + 2);
              }
            }
          }
        }
      }
      (**(code **)((longlong)*pIVar1 + 8))(pIVar1);
      if (pIVar2 != (IUMDFLPCMessage *)0x0) {
        (**(code **)((longlong)*pIVar2 + 8))(pIVar2);
      }
      goto LAB_14000a5a0;
    }
  }
  uVar7 = 0xc000009a;
LAB_14000a5a0:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x1d,
             WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar7);
  }
  return uVar7;
}



===== RdSetHostProcess @ 14000a5fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdFdoDevice::RdSetHostProcess(RdFdoDevice *this,RdProcess *param_1)

{
  int iVar1;
  RdProcess *pRVar2;
  uint uVar3;
  uint local_res8 [2];
  ulonglong local_res18;
  longlong local_28 [2];
  
  pRVar2 = param_1;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    pRVar2 = (RdProcess *)0x20;
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x20,
             WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,param_1);
  }
  uVar3 = 0;
  if (this->m_RdProcess == (RdProcess *)0x0) {
    local_res8[0] = PsGetProcessId(param_1->m_EProcess);
    local_res18 = (ulonglong)local_res8[0];
    local_28[0] = 0;
    local_28[1] = 0;
    if (this->m_DiagnosticsSubKey != (void *)0x0) {
      RtlInitUnicodeString(local_28,L"HostPid");
      pRVar2 = (RdProcess *)local_28;
      ZwSetValueKey(this->m_DiagnosticsSubKey,pRVar2,0,0xb,&local_res18,8);
    }
    WriteDiagnosticsKeyValueString(this,(wchar_t *)pRVar2,param_1->m_LifetimeId);
    iVar1 = IoSetDevicePropertyData
                      (this->m_Pdo,&DEVPKEY_Device_WudfHostProcessId,0,0,7,4,local_res8);
    if ((((iVar1 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control))
        && (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (4 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_qqd((WPP_GLOBAL_Control->Control).Logger,0x22,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this,(void *)this->_padding_,iVar1)
      ;
    }
    this->m_RdProcess = param_1;
    (**(code **)param_1->_padding_)(param_1);
  }
  else {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x21,
              WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
    }
    uVar3 = 0xc0000001;
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x23,
             WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar3);
  }
  return uVar3;
}



===== ReadMultiStringFromRegistry @ 14000a7f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
RdFdoDevice::ReadMultiStringFromRegistry
          (RdFdoDevice *this,void *param_1,_UNICODE_STRING *param_2,
          _KEY_VALUE_PARTIAL_INFORMATION **param_3)

{
  ulong uVar1;
  uint uVar2;
  _KEY_VALUE_PARTIAL_INFORMATION *p_Var3;
  ulong64 uVar4;
  ushort uVar5;
  uint uVar6;
  undefined1 auStack_88 [32];
  int local_68;
  int *local_60;
  int local_58 [2];
  _KEY_VALUE_PARTIAL_INFORMATION local_50;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  p_Var3 = &local_50;
  local_50.DataLength = 0;
  local_50.Data[0] = '\0';
  local_50._13_3_ = 0;
  local_50.TitleIndex = 0;
  local_50.Type = 0;
  local_60 = local_58;
  local_58[0] = 0xc;
  local_68 = 0xc;
  uVar2 = ZwQueryValueKey(param_1,param_2,2,&local_50);
  if ((uVar2 != 0x80000005) && (uVar2 != 0xc0000023)) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (4 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x43,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar2);
    }
    if (-1 < (int)uVar2) {
      return uVar2;
    }
    goto LAB_14000aa89;
  }
  if (local_50.Type != 7) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0) {
      return -0x3ffffff3;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x44,
             WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,0xc000000d);
    return -0x3ffffff3;
  }
  uVar1 = local_50.DataLength;
  local_58[0] = local_50.DataLength + 0xc;
  p_Var3 = (_KEY_VALUE_PARTIAL_INFORMATION *)ExAllocatePool2(0x40,local_58[0],0x62444d55);
  if (p_Var3 == (_KEY_VALUE_PARTIAL_INFORMATION *)0x0) {
    uVar6 = 0xc000009a;
    uVar2 = 0xc000009a;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000aa89;
    uVar4 = (WPP_GLOBAL_Control->Control).Logger;
    uVar5 = 0x45;
LAB_14000aa7a:
    uVar2 = uVar6;
  }
  else {
    memset();
    local_60 = local_58;
    local_68 = local_58[0];
    uVar2 = ZwQueryValueKey(param_1,param_2,2,p_Var3);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000aa89;
      uVar5 = 0x46;
      uVar6 = uVar2;
LAB_14000aa76:
      uVar4 = (WPP_GLOBAL_Control->Control).Logger;
      goto LAB_14000aa7a;
    }
    uVar6 = p_Var3->DataLength;
    if (((uVar6 == 0) || (uVar1 < uVar6)) || (p_Var3->Type != 7)) {
      uVar6 = 0xc0000004;
      uVar2 = 0xc0000004;
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000aa89;
      uVar5 = 0x47;
      goto LAB_14000aa76;
    }
    if ((1 < uVar6) && (*(short *)(p_Var3->Data + (ulonglong)(uVar6 >> 1) * 2 + -2) == 0)) {
      *param_3 = p_Var3;
      return uVar2;
    }
    uVar2 = 0xc000000d;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000aa89;
    uVar4 = (WPP_GLOBAL_Control->Control).Logger;
    uVar5 = 0x48;
    uVar2 = 0xc000000d;
  }
  WPP_SF_D(uVar4,uVar5,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar2);
LAB_14000aa89:
  if (p_Var3 != &local_50) {
    operator_delete(p_Var3);
  }
  return uVar2;
}



===== SendCloseProcessMessage @ 14000aac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

long __thiscall RdFdoDevice::SendCloseProcessMessage(RdFdoDevice *this,_IRP *param_1)

{
  IUMDFLPCMessage *pIVar1;
  RdProcess *pRVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  ulong uVar7;
  ulong64 uVar8;
  ulong64 local_res10;
  WUDF_PROBLEM *pWVar9;
  
  local_res10 = 0;
  LOCK();
  pIVar1 = this->m_CloseProcessMsg;
  this->m_CloseProcessMsg = (IUMDFLPCMessage *)0x0;
  UNLOCK();
  if (pIVar1 == (IUMDFLPCMessage *)0x0) {
    iVar5 = -0x3fffffff;
  }
  else {
    pRVar2 = this->m_RdProcess;
    if (pRVar2 == (RdProcess *)0x0) {
      uVar7 = 0x3c;
    }
    else if ((pRVar2->m_DebugModeCounter).DisableTimeouts == 0) {
      uVar7 = pRVar2->m_HostProcessTimeoutSeconds;
    }
    else {
      uVar7 = 0xffffffff;
    }
    if (this->m_DeviceDisabled != 0) {
      uVar4 = RtlStringCchLengthW((wchar_t *)this->_padding_,0xffff,&local_res10);
      if (((((int)uVar4 < 0) &&
           (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (2 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x28,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar4);
      }
      lVar6 = (**(code **)((longlong)*pIVar1 + 0x18))(pIVar1,0x28);
      *(bool *)(lVar6 + 1) = this->m_HasProblem;
      if (this->m_HasProblem == false) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (2 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x2a,
                   WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this);
        }
      }
      else {
        uVar3 = *(undefined8 *)&(this->m_HostProblem).ExitCode;
        *(undefined8 *)(lVar6 + 4) = *(undefined8 *)&this->m_HostProblem;
        *(undefined8 *)(lVar6 + 0xc) = uVar3;
        *(undefined8 *)(lVar6 + 0x14) = *(undefined8 *)&(this->m_HostProblem).Message;
        *(undefined4 *)(lVar6 + 0x1c) = *(undefined4 *)&(this->m_HostProblem).DeviceStarted;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          iVar5._0_1_ = (this->m_HostProblem).ProblemCode;
          iVar5._1_1_ = (this->m_HostProblem).field_0x1;
          iVar5._2_2_ = (this->m_HostProblem)._padding_;
          WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x29,
                    WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this,iVar5);
        }
      }
    }
    pWVar9 = (WUDF_PROBLEM *)0x0;
    uVar8 = (ulong64)uVar7;
    iVar5 = (**(code **)((longlong)*pIVar1 + 0x20))(pIVar1,RdCloseProcessReply,this);
    if (iVar5 < 0) {
      local_res10 = CONCAT44(local_res10._4_4_,iVar5);
      RdCloseProcessReply(this,pIVar1,(_WUDFMESSAGE_REPLY_HEADER *)&local_res10,uVar8,pWVar9);
      iVar5 = 0;
    }
  }
  return iVar5;
}



===== SendTeardownMessagesOnAddDeviceFailure @ 14000ac98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall
RdFdoDevice::SendTeardownMessagesOnAddDeviceFailure(RdFdoDevice *this,uchar param_1,uchar param_2)

{
  IUMDFLPCMessage *pIVar1;
  uint uVar2;
  _LARGE_INTEGER _Var3;
  uint *puVar4;
  code *pcVar5;
  undefined8 local_res20;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_res20 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xf,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids
           );
  }
  if (param_2 == '\0') goto LAB_14000af01;
  LOCK();
  pIVar1 = this->m_CloseProcessMsg;
  this->m_CloseProcessMsg = (IUMDFLPCMessage *)0x0;
  UNLOCK();
  if (pIVar1 == (IUMDFLPCMessage *)0x0) {
    KeWaitForSingleObject(&this->m_HostProcessCloseDone,0,0,0,0);
    goto LAB_14000af01;
  }
  pcVar5 = *(code **)((longlong)*pIVar1 + 0x28);
  _Var3 = RdProcess::HostProcessTimeoutInTimerUnit(this->m_RdProcess);
  puVar4 = (uint *)(*pcVar5)(pIVar1,*(undefined8 *)_Var3._s_0,0);
  if (puVar4 == (uint *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x10,
              WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
    }
LAB_14000adb9:
    uStack_48 = 0;
    local_40 = 0;
    local_50 = CONCAT44(local_50._4_4_,0x30);
    uStack_38 = CONCAT44(uStack_38._4_4_,0x200);
    local_30 = 0;
    uStack_28 = 0;
    local_60 = PsGetProcessId(this->m_RdProcess->m_EProcess);
    uStack_58 = 0;
    uVar2 = ZwOpenProcess(&local_res20,0x1fffff,&local_50,&local_60);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x12,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar2);
      }
    }
    else {
      if (puVar4 == (uint *)0x0) {
        uVar2 = 0xc000009a;
      }
      else {
        uVar2 = *puVar4;
      }
      uVar2 = ZwTerminateProcess(local_res20,uVar2);
      if ((((int)uVar2 < 0) &&
          (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
         ((((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0 &&
          (1 < (WPP_GLOBAL_Control->Control).Level)))) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x13,
                 WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,uVar2);
      }
      this->m_DirectlyTerminatedHostProcess = true;
      ZwClose(local_res20);
    }
    if (this->m_RdProcess != (RdProcess *)0x0) {
      RdProcess::DisableProcess(this->m_RdProcess);
    }
  }
  else if ((int)*puVar4 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x11,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,*puVar4);
    }
    goto LAB_14000adb9;
  }
  (**(code **)((longlong)*pIVar1 + 8))(pIVar1);
LAB_14000af01:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x14,
            WPP_361e773ccae936d88ddb0c43383770cb_Traceguids);
  }
  return;
}



===== ShouldBreakIntoKdOnHostFailure @ 14000af4c =====

uchar __thiscall
RdFdoDevice::ShouldBreakIntoKdOnHostFailure(RdFdoDevice *this,WUDF_PROBLEM *param_1)

{
  long *plVar1;
  int iVar2;
  _EPROCESS *p_Var3;
  _EPROCESS *p_Var4;
  
  p_Var4 = (_EPROCESS *)0x0;
  if (((DAT_0001fd7a != '\0') && (DAT_0001fdca == '\0')) &&
     (iVar2 = *(int *)(this->_padding_ + 0xe0), iVar2 != 0)) {
    if (iVar2 == 2) {
      return '\x01';
    }
    if (iVar2 == 1) {
      if (this->m_RdProcess != (RdProcess *)0x0) {
        LOCK();
        plVar1 = &this->m_RdProcess->m_BreakOnDisable;
        iVar2 = *plVar1;
        *plVar1 = 1;
        UNLOCK();
        if (iVar2 != 0) {
          return '\0';
        }
      }
      p_Var3 = (_EPROCESS *)PsGetCurrentProcess();
      if (this->m_RdProcess != (RdProcess *)0x0) {
        p_Var4 = this->m_RdProcess->m_EProcess;
      }
      iVar2._0_1_ = param_1->ProblemCode;
      iVar2._1_1_ = param_1->field_0x1;
      iVar2._2_2_ = param_1->_padding_;
      if ((((iVar2 != 8) || (p_Var3 != p_Var4)) ||
          (iVar2 = PsGetProcessExitStatus(p_Var3), iVar2 != 0x70000001)) &&
         (*(_EPROCESS **)(this->_padding_ + 0x1c8) != p_Var3)) {
        return '\x01';
      }
    }
  }
  return '\0';
}



===== WaitForHostProcessExit @ 14000b028 =====

void __thiscall RdFdoDevice::WaitForHostProcessExit(RdFdoDevice *this)

{
  _EPROCESS *p_Var1;
  int iVar2;
  _LARGE_INTEGER _Var3;
  undefined8 local_res8 [2];
  
  p_Var1 = this->m_RdProcess->m_EProcess;
  _Var3 = RdProcess::HostProcessTimeoutInTimerUnit(this->m_RdProcess);
  local_res8[0] = *(undefined8 *)_Var3._s_0;
  iVar2 = KeWaitForSingleObject(p_Var1,0,0,0,local_res8);
  if ((((iVar2 == 0x102) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
       ) && (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
     (1 < (WPP_GLOBAL_Control->Control).Level)) {
    WPP_SF_qqq((WPP_GLOBAL_Control->Control).Logger,0x31,
               WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,this,(void *)this->_padding_,p_Var1);
  }
  return;
}



===== WriteDiagnosticsKeyValueString @ 14000b0d4 =====

long __thiscall
RdFdoDevice::WriteDiagnosticsKeyValueString(RdFdoDevice *this,wchar_t *param_1,wchar_t *param_2)

{
  long lVar1;
  ulong64 local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (this->m_DiagnosticsSubKey == (void *)0x0) {
    lVar1 = -0x3ffffff8;
  }
  else {
    RtlInitUnicodeString(&local_18,L"LifetimeID");
    lVar1 = RtlStringCchLengthW(param_2,0x7fffffff,local_res10);
    if (-1 < lVar1) {
      lVar1 = ZwSetValueKey(this->m_DiagnosticsSubKey,&local_18,0,1,param_2,
                            (int)local_res10[0] * 2 + 2);
    }
  }
  return lVar1;
}



===== WPP_SF_LLLDd @ 14000b17c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_LLLDd(ulong64 param_1,ushort param_2,_GUID *param_3,ulong param_4,ulong param_5,ulong param_6
            ,uint param_7,int param_8)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,10);
  return;
}



===== WPP_SF_SDD @ 14000b1fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_SDD(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4,uint param_5,uint param_6)

{
  longlong lVar1;
  
  if (param_4 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,0x19);
  return;
}



===== WPP_SF_qqLLLDLdqql @ 14000b29c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqLLLDLdqql(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,
                  ulong param_6,ulong param_7,ulong param_8,uint param_9,ulong param_10,int param_11
                  ,void *param_12,void *param_13,long param_14)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_361e773ccae936d88ddb0c43383770cb_Traceguids,0xd);
  return;
}



===== WPP_SF_qqd @ 14000b37c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqd(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,int param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2);
  return;
}



===== Acquire @ 14000b3dc =====

void __thiscall RdCRLock::Acquire(RdCRLock *this)

{
  KeEnterCriticalRegion();
  KeWaitForSingleObject(this,0,0,0,0);
  this->m_OwningThread = SystemReserved1[0xf];
  return;
}



===== Release @ 14000b428 =====

void __thiscall RdCRLock::Release(RdCRLock *this)

{
  this->m_OwningThread = (_KTHREAD *)0x0;
  KeSetEvent(this,0,0);
  KeLeaveCriticalRegion();
  return;
}



===== LoadCompanion @ 14000b460 =====

long __thiscall
RdCompanionLibrary::LoadCompanion
          (RdCompanionLibrary *this,_DEVICE_OBJECT *param_1,wchar_t *param_2,
          IDeviceCompanionCallbacks *param_3,IDeviceCompanion **param_4)

{
  long lVar1;
  
  lVar1 = RdDeviceCompanion::_LoadCompanion(param_1,param_2,this->m_RdDriver,param_3,param_4);
  return lVar1;
}



===== UnloadCompanion @ 14000b490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
RdCompanionLibrary::UnloadCompanion(RdCompanionLibrary *this,IDeviceCompanion *param_1)

{
  _IRP *p_Var1;
  
  p_Var1 = (_IRP *)param_1;
  (**(code **)(*(longlong *)param_1[1] + 0x28))();
  RdFdoDevice::RdSendCompanionRemoveMessageToCompanionHost((RdFdoDevice *)param_1[1]);
  RdFdoDevice::SendCloseProcessMessage((RdFdoDevice *)param_1[1],p_Var1);
  KeWaitForSingleObject((longlong)param_1[1] + 0xa8,0,0,0,0);
  WdfObject::ReleaseWait((WdfObject *)param_1[1],0xffffffff);
  (**(code **)((longlong)*param_1 + 0x40))(param_1,1);
  return 0;
}



===== `scalar_deleting_destructor' @ 14000b510 =====

void * __thiscall
RdDeviceCompanion::_scalar_deleting_destructor_(RdDeviceCompanion *this,uint param_1)

{
  this->_padding_ = (longlong)&___7RdDeviceCompanion__6B_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== GetCompanionProcess @ 14000b540 =====

_EPROCESS * __thiscall RdDeviceCompanion::GetCompanionProcess(RdDeviceCompanion *this)

{
  RdProcess *pRVar1;
  
  if ((this->m_RdFdo->m_DeviceDisabled == 0) &&
     (pRVar1 = this->m_RdFdo->m_RdProcess, pRVar1 != (RdProcess *)0x0)) {
    return pRVar1->m_EProcess;
  }
  return (_EPROCESS *)0x0;
}



===== Initialize @ 14000b56c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdDeviceCompanion::Initialize(RdDeviceCompanion *this)

{
  IDeviceCompanionCallbacks *pIVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((this->m_RdFdo->m_CompanionType == WudfServiceTypeCompanionSecure) &&
     (pIVar1 = this->m_RdFdo->m_CompanionCallback,
     iVar2 = (**(code **)((longlong)*pIVar1 + 8))(pIVar1,&this->m_SecureDeviceToken), iVar3 = iVar2,
     iVar2 < 0)) {
    iVar3 = QuerySoftwareSecureDeviceToken(this,&this->m_SecureDeviceToken);
    if (iVar3 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_dd((WPP_GLOBAL_Control->Control).Logger,0x12,
                  WPP_845e6abb383c38a359df284c952034f6_Traceguids,iVar2,iVar3);
      }
      return iVar2;
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (3 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x13,
              WPP_845e6abb383c38a359df284c952034f6_Traceguids);
    }
  }
  return iVar3;
}



===== QueryPnPDeviceStateNotification @ 14000b660 =====

void __thiscall RdDeviceCompanion::QueryPnPDeviceStateNotification(RdDeviceCompanion *this)

{
  RdProcess *this_00;
  
  if ((this->m_RdFdo->m_DeviceDisabled != 0) &&
     (this_00 = this->m_RdFdo->m_RdProcess, this_00 != (RdProcess *)0x0)) {
    RdProcess::DisableProcess(this_00);
  }
  return;
}



===== QuerySoftwareDeviceTag @ 14000b690 =====

long __thiscall RdDeviceCompanion::QuerySoftwareDeviceTag(RdDeviceCompanion *this,ulong *param_1)

{
  int iVar1;
  void *local_res8;
  CUmdfSvcConfig local_18;
  
  local_res8 = (void *)0xffffffffffffffff;
  local_18.m_Key = (void *)0x0;
  local_18.m_AutoClose = '\x01';
  iVar1 = IoOpenDeviceRegistryKey(this->m_RdFdo->m_Pdo,1,0x20019,&local_res8);
  if (-1 < iVar1) {
    iVar1 = CUmdfSvcConfig::GetSecureSoftwareDeviceTag(&local_18,local_res8,param_1);
  }
  if (local_res8 != (void *)0xffffffffffffffff) {
    ZwClose();
  }
  CUmdfSvcConfig::~CUmdfSvcConfig(&local_18);
  return iVar1;
}



===== QuerySoftwareSecureDeviceToken @ 14000b724 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
RdDeviceCompanion::QuerySoftwareSecureDeviceToken(RdDeviceCompanion *this,ulong64 *param_1)

{
  long lVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  ulong64 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  *param_1 = 0xffffffffffffffff;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar1 = QuerySoftwareDeviceTag(this,(ulong *)((longlong)&local_38 + 4));
  if (-1 < lVar1) {
    local_38 = CONCAT44(local_38._4_4_,1);
    lVar1 = VslQuerySecureDevice(&local_38,&local_28);
    if (-1 < lVar1) {
      if ((char)local_28 == '\0') {
        lVar1 = -0x3ffffff2;
      }
      else {
        *param_1 = uStack_20;
      }
    }
  }
  return lVar1;
}



===== SendD0Entry @ 14000b7c0 =====

long __thiscall RdDeviceCompanion::SendD0Entry(RdDeviceCompanion *this,ulong param_1)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
                    (this->m_RdFdo,CompanionEvent_D0Entry,(_CM_RESOURCE_LIST *)0x0,
                     (_CM_RESOURCE_LIST *)0x0,param_1);
  return lVar1;
}



===== SendD0Exit @ 14000b7f0 =====

long __thiscall RdDeviceCompanion::SendD0Exit(RdDeviceCompanion *this,ulong param_1)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
                    (this->m_RdFdo,CompanionEvent_D0Exit,(_CM_RESOURCE_LIST *)0x0,
                     (_CM_RESOURCE_LIST *)0x0,param_1);
  return lVar1;
}



===== SendPrepareHardware @ 14000b820 =====

long __thiscall
RdDeviceCompanion::SendPrepareHardware
          (RdDeviceCompanion *this,_CM_RESOURCE_LIST *param_1,_CM_RESOURCE_LIST *param_2)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
                    (this->m_RdFdo,CompanionEvent_PrepareHardware,param_1,param_2,0);
  return lVar1;
}



===== SendReleaseHardware @ 14000b850 =====

long __thiscall RdDeviceCompanion::SendReleaseHardware(RdDeviceCompanion *this)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
                    (this->m_RdFdo,CompanionEvent_ReleaseHardware,(_CM_RESOURCE_LIST *)0x0,
                     (_CM_RESOURCE_LIST *)0x0,0);
  return lVar1;
}



===== SendSurpriseRemove @ 14000b880 =====

long __thiscall RdDeviceCompanion::SendSurpriseRemove(RdDeviceCompanion *this)

{
  long lVar1;
  
  lVar1 = RdFdoDevice::RdSendCompanionEventMessageToCompanionHost
                    (this->m_RdFdo,CompanionEvent_SurpriseRemove,(_CM_RESOURCE_LIST *)0x0,
                     (_CM_RESOURCE_LIST *)0x0,0);
  return lVar1;
}



===== _LoadCompanion @ 14000b8a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
RdDeviceCompanion::_LoadCompanion
          (_DEVICE_OBJECT *param_1,wchar_t *param_2,RdDriver *param_3,
          IDeviceCompanionCallbacks *param_4,IDeviceCompanion **param_5)

{
  undefined1 auVar1 [16];
  uint uVar2;
  undefined8 uVar3;
  wchar_t *pwVar4;
  RdFdoDevice *this;
  RdDeviceCompanion *this_00;
  uchar uVar5;
  RdFdoDeviceParameters *pRVar6;
  ulong64 uVar7;
  wchar_t *pwVar8;
  RdDeviceCompanion *pRVar9;
  long *in_stack_ffffffffffffff90;
  uchar local_68;
  uchar local_67;
  uint local_64;
  RdFdoDeviceParameters local_60;
  
  local_64 = 0;
  pRVar9 = (RdDeviceCompanion *)0x0;
  local_68 = '\0';
  local_67 = '\0';
  *param_5 = (IDeviceCompanion *)0x0;
  local_60.RdDriver = (RdDriver *)0x0;
  local_60.RdDeviceName = (wchar_t *)0x0;
  local_60.PhysicalDeviceObject = (_DEVICE_OBJECT *)0x0;
  local_60.ProcessTimeout = 0;
  local_60.IsCompanionMode = '\0';
  local_60._29_3_ = 0;
  local_60.KernelServiceName = (wchar_t *)0x0;
  local_60.CompanionCallback = (IDeviceCompanionCallbacks *)0x0;
  uVar2 = IoGetDeviceProperty(0,0xb,0,0,&local_64);
  if (uVar2 != 0xc0000023) {
    if (-1 < (int)uVar2) {
      uVar2 = 0xc00000e5;
    }
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return uVar2;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0) {
      return uVar2;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return uVar2;
    }
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,10,WPP_845e6abb383c38a359df284c952034f6_Traceguids
             ,uVar2);
    return uVar2;
  }
  auVar1 = ZEXT816(2) * ZEXT416(local_64 >> 1);
  uVar3 = auVar1._0_8_;
  if (auVar1._8_8_ != 0) {
    uVar3 = 0xffffffffffffffff;
  }
  pwVar4 = (wchar_t *)ExAllocatePool2(0x40,uVar3,0x39444d55);
  if (pwVar4 == (wchar_t *)0x0) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return -0x3fffffe9;
    }
    if (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0) {
      return -0x3fffffe9;
    }
    if ((WPP_GLOBAL_Control->Control).Level < 2) {
      return -0x3fffffe9;
    }
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,WPP_845e6abb383c38a359df284c952034f6_Traceguids
           );
    return -0x3fffffe9;
  }
  pwVar8 = pwVar4;
  uVar2 = IoGetDeviceProperty(param_1,0xb,local_64,pwVar4,&local_64);
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xc,
               WPP_845e6abb383c38a359df284c952034f6_Traceguids,uVar2);
    }
    goto LAB_14000bcb9;
  }
  pRVar6 = &local_60;
  local_60.IsCompanionMode = '\x01';
  local_60.RdDriver = param_3;
  local_60.RdDeviceName = pwVar4;
  local_60.PhysicalDeviceObject = param_1;
  local_60.KernelServiceName = param_2;
  local_60.CompanionCallback = param_4;
  this = WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>::Find
                   (param_3->m_RdFdoDeviceList,pRVar6,'\x01',(uchar)pwVar8,&local_68,
                    in_stack_ffffffffffffff90);
  uVar5 = (uchar)pRVar6;
  if (this == (RdFdoDevice *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xd,
              WPP_845e6abb383c38a359df284c952034f6_Traceguids);
    }
    uVar2 = 0xc0000017;
    goto LAB_14000bcb9;
  }
  if (local_68 == '\0') {
    (**(code **)(this->_padding_ + 8))();
    uVar2 = 0xc0000182;
    goto LAB_14000bcb9;
  }
  uVar2 = RdFdoDevice::RdSendOpenProcessMessageToDrvMgr(this);
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      uVar3 = 0xe;
LAB_14000bc67:
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,(ushort)uVar3,
               WPP_845e6abb383c38a359df284c952034f6_Traceguids,uVar2);
      uVar5 = (uchar)uVar3;
    }
  }
  else {
    local_67 = '\x01';
    uVar2 = RdFdoDevice::PopulateDriverInfo(this);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        uVar3 = 0xf;
        goto LAB_14000bc67;
      }
    }
    else {
      uVar2 = RdFdoDevice::RdPrepareToCommunicateWithCompanionHost(this);
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar3 = 0x10;
          goto LAB_14000bc67;
        }
      }
      else {
        uVar5 = '\x18';
        this_00 = (RdDeviceCompanion *)ExAllocatePool2(0x40,0x18,0x30444d75);
        if (this_00 == (RdDeviceCompanion *)0x0) {
          uVar2 = 0xc0000017;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            uVar3 = 0x11;
            goto LAB_14000bc67;
          }
        }
        else {
          this_00->m_SecureDeviceToken = 0xffffffffffffffff;
          this_00->_padding_ = (longlong)&___7RdDeviceCompanion__6B_;
          this_00->m_RdFdo = this;
          this->m_StartDeviceNtStatus = 0;
          uVar2 = Initialize(this_00);
          pRVar9 = this_00;
          if (-1 < (int)uVar2) {
            uVar7 = this_00->m_SecureDeviceToken;
            uVar2 = RdFdoDevice::RdSendCompanionAddMessageToCompanionHost(this_00->m_RdFdo,uVar7);
            uVar5 = (uchar)uVar7;
            if (-1 < (int)uVar2) {
              *param_5 = (IDeviceCompanion *)this_00;
              goto LAB_14000bcb9;
            }
          }
        }
      }
    }
  }
  (**(code **)(this->_padding_ + 0x28))(this);
  RdFdoDevice::SendTeardownMessagesOnAddDeviceFailure(this,uVar5,local_67);
  WdfObject::ReleaseWait((WdfObject *)this,0xffffffff);
  if (pRVar9 != (RdDeviceCompanion *)0x0) {
    (**(code **)(pRVar9->_padding_ + 0x40))(pRVar9,1);
  }
LAB_14000bcb9:
  operator_delete(pwVar4);
  return uVar2;
}



===== RdDriver @ 14000bce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000c193) */
/* WARNING: Removing unreachable block (ram,0x00014000c199) */
/* WARNING: Removing unreachable block (ram,0x00014000c1b3) */
/* WARNING: Removing unreachable block (ram,0x00014000c1bf) */
/* WARNING: Removing unreachable block (ram,0x00014000c1c6) */
/* WARNING: Removing unreachable block (ram,0x00014000c1cc) */
/* WARNING: Removing unreachable block (ram,0x00014000c1aa) */

RdDriver * __thiscall
RdDriver::RdDriver(RdDriver *this,_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2,uchar param_3)

{
  uint uVar1;
  _EPROCESS *p_Var2;
  WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *this_00;
  WdfObjectList<RdProcess,RdProcessParameters> *this_01;
  RdCompanionLibrary *pRVar3;
  RdFxLibCtrlDevice *pRVar4;
  ushort uVar5;
  RdDriver *pRVar6;
  wchar_t *pwVar7;
  undefined1 auStack_a8 [32];
  void *local_70;
  CUmdfSvcConfig local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  WdfObject::WdfObject((WdfObject *)this,L"RdDriver",(WdfObject *)0x0,'\0',RdTypeObject);
  local_68.m_AutoClose = '\x01';
  local_68.m_Key = (void *)0x0;
  this->_padding_ = (longlong)&___7RdDriver__6B_;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0xd,
             WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids,param_1);
  }
  local_70 = (void *)0x0;
  this->m_DriverObject = param_1;
  this->m_NumRedirectorInstances = 0;
  this->m_RdDrvMgrCtrl = (RdDrvMgrCtrlDevice *)0x0;
  this->m_RdNonPnPLibCtrl = (RdFxLibCtrlDevice *)0x0;
  this->m_RdFdoDeviceList = (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0;
  this->m_RdCtrlDeviceList = (WdfObjectList<RdCtrlDevice,RdCtrlDeviceParameters> *)0x0;
  this->m_RdProcessList = (WdfObjectList<RdProcess,RdProcessParameters> *)0x0;
  p_Var2 = (_EPROCESS *)PsGetCurrentProcess();
  *(undefined4 *)&this->m_HostFailKdDebugBreak = 1;
  this->m_SystemProcess = p_Var2;
  this->m_NextRequestId = 0;
  m_DriverProcessTerminatedStatus = -0x3ffffbb0;
  this->m_Timer = (IUMDFPeriodicTimer *)0x0;
  this->m_WdfLpcInterface = (IUMDFLPCInterface *)0x0;
  this->m_Lpc = (IUMDFLPC *)0x0;
  this->m_LpcNotification = (RdLpcNotification *)0x0;
  this->m_DriverManagerLpcComm = (IUMDFLPCCommPortInterface *)0x0;
  this->m_DriverManagerProcess = (_EPROCESS *)0x0;
  this->m_IfrDisabled = '\0';
  this->m_IsIfrFromPagedPool = '\0';
  this->m_IsCompanion = '\x01';
  this->m_RdCompanionLibrary = (RdCompanionLibrary *)0x0;
  this->m_TriageLock = 0;
  RtlInitUnicodeString(&this->m_RegistryPath,0);
  uVar1 = (uint)this->_padding_;
  if ((int)uVar1 < 0) goto LAB_14000c253;
  param_1->MajorFunction[0] = RdDispatch;
  param_1->MajorFunction[0x12] = RdDispatch;
  param_1->MajorFunction[2] = RdDispatch;
  param_1->MajorFunction[0xf] = RdDispatch;
  param_1->MajorFunction[0xe] = RdDispatch;
  param_1->DriverUnload = RdUnload;
  this_00 = (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)
            ExAllocatePool2(0x40,0x78,0x71444d55);
  if (this_00 == (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    WdfObject::WdfObject
              ((WdfObject *)this_00,L"ListObjectNoName",(WdfObject *)this,'\0',RdTypeObject);
    this_00->m_List = (WdfObject *)0x0;
    this_00->_padding_ = (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
    this_00->m_NextUniqueObjectId = 1;
    this_00->m_Tag = 0x65444d55;
    this_00->m_PoolFlags = 0x40;
    this->m_RdFdoDeviceList = this_00;
    uVar1 = (uint)this_00->_padding_;
    if (-1 < (int)uVar1) {
      this_01 = (WdfObjectList<RdProcess,RdProcessParameters> *)
                ExAllocatePool2(0x40,0x78,0x73444d55);
      if (this_01 == (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
        this->m_RdProcessList = (WdfObjectList<RdProcess,RdProcessParameters> *)0x0;
LAB_14000c230:
        uVar1 = 0xc0000017;
      }
      else {
        WdfObject::WdfObject
                  ((WdfObject *)this_01,L"ListObjectNoName",(WdfObject *)this,'\0',RdTypeObject);
        this_01->m_List = (WdfObject *)0x0;
        this_01->_padding_ = (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
        this_01->m_NextUniqueObjectId = 1;
        this_01->m_Tag = 0x65444d55;
        this_01->m_PoolFlags = 0x40;
        this->m_RdProcessList = this_01;
        uVar1 = (uint)this_01->_padding_;
        if ((int)uVar1 < 0) {
          (**(code **)(this_01->_padding_ + 0x28))(this_01);
          (**(code **)(this->m_RdProcessList->_padding_ + 8))();
          this->m_RdProcessList = (WdfObjectList<RdProcess,RdProcessParameters> *)0x0;
          goto LAB_14000c253;
        }
        uVar1 = InitializeLpcAndConnect(this);
        if (uVar1 == 0xc0000034) goto LAB_14000c253;
        if ((int)uVar1 < 0) {
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000c253;
          uVar5 = 0xe;
        }
        else {
          pRVar3 = (RdCompanionLibrary *)ExAllocatePool2(0x40);
          if (pRVar3 == (RdCompanionLibrary *)0x0) {
            this->m_RdCompanionLibrary = (RdCompanionLibrary *)0x0;
            goto LAB_14000c230;
          }
          WdfObject::WdfObject
                    ((WdfObject *)&pRVar3->_padding_,L"RdCompanionLibrary",(WdfObject *)0x0,'\0',
                     RdTypeObject);
          pRVar3->m_RdDriver = this;
          pRVar3->_padding_ = (longlong)&RdCompanionLibrary::_vftable__for__ICompanionLibrary__;
          pwVar7 = (wchar_t *)0x77444d55;
          pRVar3->_padding_ = (longlong)&RdCompanionLibrary::_vftable__for__WdfObject__;
          this->m_RdCompanionLibrary = pRVar3;
          pRVar4 = (RdFxLibCtrlDevice *)ExAllocatePool2(0x40);
          if (pRVar4 == (RdFxLibCtrlDevice *)0x0) {
            this->m_RdNonPnPLibCtrl = (RdFxLibCtrlDevice *)0x0;
          }
          else {
            pRVar6 = this;
            pRVar4 = RdFxLibCtrlDevice::RdFxLibCtrlDevice(pRVar4,this,pwVar7);
            this->m_RdNonPnPLibCtrl = pRVar4;
            if (pRVar4 != (RdFxLibCtrlDevice *)0x0) {
              uVar1 = *(uint *)&pRVar4->field_0x10;
              if ((int)uVar1 < 0) {
                if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
                   ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000c253;
                uVar5 = 0x10;
              }
              else {
                uVar1 = CUmdfSvcConfig::OpenRootKey(&local_68,(ulong)pRVar6,&local_70);
                if (-1 < (int)uVar1) {
                  RtlInitUnicodeString(&local_58,L"HostFailKdDebugBreak");
                  ZwQueryValueKey(local_70,&local_58,2,&local_48);
                  QueryGlobalRegistrySettings(this);
                  uVar1 = 0;
                  goto LAB_14000c253;
                }
                if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
                   ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000c253;
                uVar5 = 0x11;
              }
              WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar5,
                       WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids,uVar1);
              goto LAB_14000c253;
            }
          }
          uVar1 = 0xc0000017;
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 1) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000c253;
          uVar5 = 0xf;
        }
        WPP_SF_((WPP_GLOBAL_Control->Control).Logger,uVar5,
                WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids);
      }
      goto LAB_14000c253;
    }
    (**(code **)(this_00->_padding_ + 0x28))(this_00);
    (**(code **)(this->m_RdFdoDeviceList->_padding_ + 8))();
  }
  this->m_RdFdoDeviceList = (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0;
LAB_14000c253:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar1);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000001) == 0x80000001)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x13,
             WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids,~uVar1 >> 0x1f);
  }
  CUmdfSvcConfig::~CUmdfSvcConfig(&local_68);
  return this;
}



===== ~WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> @ 14000c2cc =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall
WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>::~WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>
          (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *this)

{
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *in_RDX;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  this->_padding_ = (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
  WudfVerifyStatic((WdfComponentType)this,in_RDX,
                   L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"m_List is not NULL",this->m_List == (WdfObject *)0x0);
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `vector_deleting_destructor'`adjustor{8}' @ 14000c320 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl RdCompanionLibrary::`vector deleting
   destructor'`adjustor{8}' (unsigned int) __ptr64 */

void * __thiscall
RdCompanionLibrary::_vector_deleting_destructor__adjustor_8__(RdCompanionLibrary *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _scalar_deleting_destructor_((RdCompanionLibrary *)&this[-1].m_RdDriver,param_1);
  return pvVar1;
}



===== `scalar_deleting_destructor' @ 14000c330 =====

void * __thiscall
WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>::_scalar_deleting_destructor_
          (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *this,uint param_1)

{
  ~WdfObjectList<RdFdoDevice,RdFdoDeviceParameters>(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c368 =====

void * __thiscall
RdCompanionLibrary::_scalar_deleting_destructor_(RdCompanionLibrary *this,uint param_1)

{
  WdfObject::~WdfObject((WdfObject *)&this->_padding_);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledDeviceUsageNoInline @ 14000c3a4 =====

int __cdecl Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledDeviceUsageNoInline(void)

{
  uint uVar1;
  wil_details_FeatureStateCache local_res8;
  
  local_res8._s_2.payloadId = 0;
  local_res8.exchange = Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange;
  if ((Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange & 0x10) == 0) {
    uVar1 = Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledFallback
                      (local_res8,wil_ReportingKind_DeviceUsage);
  }
  else {
    uVar1 = Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange & 1;
  }
  return uVar1;
}



===== Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledFallback @ 14000c3dc =====

int __cdecl
Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledFallback
          (wil_details_FeatureStateCache param_1,wil_ReportingKind param_2)

{
  int iVar1;
  wil_details_FeatureDescriptor *in_R8;
  wil_UsageReportingMode in_R9D;
  
  iVar1 = wil_details_IsEnabledFallback(param_1,param_2,in_R8,in_R9D);
  return iVar1;
}



===== WPP_INIT_CONTROL_ARRAY @ 14000c3f4 =====

void __cdecl WPP_INIT_CONTROL_ARRAY(WPP_PROJECT_CONTROL_BLOCK *param_1)

{
  WPP_MAIN_CB[0].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[0].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[0].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[0].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[0].Control.ControlGuid = &WPP_ThisDir_CTLGUID_ReflectorTraceGuid;
  WPP_MAIN_CB[0].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 1);
  WPP_MAIN_CB[1].Control.ControlGuid = &WPP_ThisDir_CTLGUID_DriverManagerTraceGuid;
  WPP_MAIN_CB[1].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 2);
  WPP_MAIN_CB[2].Control.ControlGuid = &WPP_ThisDir_CTLGUID_TestTraceGuid;
  WPP_MAIN_CB[2].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 3);
  WPP_MAIN_CB[3].Control.ControlGuid = &WPP_ThisDir_CTLGUID_LpcDriverTraceGuid;
  WPP_MAIN_CB[3].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 4);
  WPP_MAIN_CB[4].Control.ControlGuid = &WPP_ThisDir_CTLGUID_HostProcessTraceGuid;
  WPP_MAIN_CB[4].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 5);
  WPP_MAIN_CB[5].Control.ControlGuid = &WPP_ThisDir_CTLGUID_FrameworkTraceGuid;
  WPP_MAIN_CB[5].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 6);
  WPP_MAIN_CB[6].Control.ControlGuid = &WPP_ThisDir_CTLGUID_PlatformLibraryTraceGuid;
  WPP_MAIN_CB[6].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)(WPP_MAIN_CB + 7);
  WPP_MAIN_CB[7].Control.ControlGuid = &WPP_ThisDir_CTLGUID_LpcTraceGuid;
  WPP_MAIN_CB[0].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[1].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[1].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[1].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[1].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[1].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[2].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[2].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[2].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[2].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[2].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[3].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[3].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[3].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[3].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[3].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[4].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[4].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[4].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[4].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[4].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[5].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[5].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[5].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[5].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[5].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[6].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[6].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[6].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[6].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[6].ReserveSpace[0x2f] = '\0';
  WPP_MAIN_CB[7].Control.Callback =
       (_func___cdecl_long_uchar_void_ptr_ulong_void_ptr_void_ptr_ulong_ptr *)0x0;
  WPP_MAIN_CB[7].Control.Next = (_WPP_TRACE_CONTROL_BLOCK *)0x0;
  WPP_MAIN_CB[7].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WPP_MAIN_CB[7].ReserveSpace[0x28] = '\x01';
  WPP_MAIN_CB[7].ReserveSpace[0x29] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2a] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2b] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2c] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2d] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2e] = '\0';
  WPP_MAIN_CB[7].ReserveSpace[0x2f] = '\0';
  return;
}



===== WppClassicProviderCallback @ 14000c5a0 =====

void __cdecl WppClassicProviderCallback(_GUID *param_1,uchar param_2,void *param_3,void *param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0;
    if (param_2 == '\0') {
      *(undefined1 *)((longlong)param_4 + 0x29) = 0;
      *(undefined4 *)((longlong)param_4 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)((longlong)param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)((longlong)param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *(undefined8 *)param_3;
    }
    *(undefined8 *)((longlong)param_4 + 0x18) = uVar1;
  }
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000c5d4 =====

wil_details_FeatureDescriptor * __cdecl wil_details_FeatureDescriptors_SkipPadding(ulong64 param_1)

{
  while( true ) {
    if (&Feature_ImplVal__private_descriptor.field_0x37 < param_1) {
      return (wil_details_FeatureDescriptor *)0x0;
    }
    if (((wil_details_FeatureDescriptor *)param_1)->featureStateCache !=
        (wil_details_FeatureStateCache *)0x0) break;
    param_1 = (ulong64)&((wil_details_FeatureDescriptor *)param_1)->featureReportingCache;
  }
  return (wil_details_FeatureDescriptor *)param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14000c5fc =====

void __cdecl
wil_details_FeatureReporting_IncrementOpportunityInCache
          (wil_details_FeatureReportingCache *param_1,wil_details_ServiceReportingKind param_2,
          uint param_3,wil_details_RecordUsageResult *param_4)

{
  uint uVar1;
  uint uVar2;
  wil_details_ServiceReportingKind wVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (param_1->reported).exchange;
  do {
    uVar1 = uVar2;
    param_4->countImmediate = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0x16 & 1) !=
        (uint)(param_2 == wil_details_ServiceReportingKind_PotentialUniqueOpportunity)) {
      uVar5 = uVar1 >> 0xf & 0x7f;
      if (uVar5 != 0) {
        param_4->countImmediate = uVar5;
        wVar3 = wil_details_ServiceReportingKind_PotentialUniqueOpportunity;
        if (param_2 != wil_details_ServiceReportingKind_UniqueOpportunity) {
          wVar3 = wil_details_ServiceReportingKind_UniqueOpportunity;
        }
        uVar2 = uVar1 & 0xffc07fff | 1;
        param_4->kindImmediate = wVar3;
      }
      uVar5 = 0;
      if (param_2 == wil_details_ServiceReportingKind_PotentialUniqueOpportunity) {
        uVar5 = 0x400000;
      }
      uVar2 = uVar5 | uVar2 & 0xffbfffff;
    }
    uVar4 = uVar2 >> 0xf & 0x7f;
    uVar5 = uVar4 + 1;
    if ((0x7f < uVar5) || (uVar5 < uVar4)) {
      uVar5 = 1;
      param_4->kindImmediate = param_2;
      param_4->countImmediate = uVar4;
    }
    LOCK();
    uVar4 = (param_1->reported).exchange;
    if (uVar1 == uVar4) {
      (param_1->reported).exchange = uVar2 ^ (uVar5 << 0xf ^ uVar2) & 0x3f8000;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (uVar1 != uVar4);
  param_4->ignoredUse = 0;
  param_4->queueBackground = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000c6e0 =====

void __cdecl
wil_details_FeatureReporting_IncrementUsageInCache
          (wil_details_FeatureReportingCache *param_1,wil_details_ServiceReportingKind param_2,
          uint param_3,wil_details_RecordUsageResult *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_1->reported).exchange;
  do {
    uVar1 = uVar2;
    param_4->countImmediate = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0xe & 1) !=
        (uint)(param_2 == wil_details_ServiceReportingKind_PotentialUniqueUsage)) {
      uVar4 = uVar1 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4->countImmediate = uVar4;
        param_4->kindImmediate =
             ~-(uint)(param_2 != wil_details_ServiceReportingKind_UniqueUsage) &
             wil_details_ServiceReportingKind_PotentialUniqueUsage;
        uVar2 = uVar1 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == wil_details_ServiceReportingKind_PotentialUniqueUsage) {
        uVar4 = 0x4000;
      }
      uVar2 = uVar4 | uVar2 & 0xffffbfff;
    }
    uVar3 = uVar2 >> 5 & 0x1ff;
    uVar4 = uVar3 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4->kindImmediate = param_2;
      param_4->countImmediate = uVar3;
    }
    LOCK();
    uVar3 = (param_1->reported).exchange;
    if (uVar1 == uVar3) {
      (param_1->reported).exchange = uVar2 ^ (uVar4 << 5 ^ uVar2) & 0x3fe0;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4->ignoredUse = 0;
  param_4->queueBackground = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000c7d0 =====

wil_details_RecordUsageResult * __cdecl
wil_details_FeatureReporting_RecordUsageInCache
          (wil_details_RecordUsageResult *__return_storage_ptr__,
          wil_details_FeatureReportingCache *param_1,wil_details_ServiceReportingKind param_2,
          uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  __return_storage_ptr__->queueBackground = 0;
  __return_storage_ptr__->countImmediate = 0;
  __return_storage_ptr__->kindImmediate = wil_details_ServiceReportingKind_UniqueUsage;
  __return_storage_ptr__->payloadId = 0;
  __return_storage_ptr__->ignoredUse = 0;
  __return_storage_ptr__->isWexpConfiguration = 0;
  if (param_2 == wil_details_ServiceReportingKind_UniqueUsage) {
LAB_14000c92c:
    wil_details_FeatureReporting_IncrementUsageInCache
              (param_1,param_2,param_2,__return_storage_ptr__);
  }
  else {
    if (param_2 == wil_details_ServiceReportingKind_UniqueOpportunity) {
LAB_14000c91c:
      wil_details_FeatureReporting_IncrementOpportunityInCache
                (param_1,param_2,param_2,__return_storage_ptr__);
      return __return_storage_ptr__;
    }
    if ((param_2 != wil_details_ServiceReportingKind_DeviceUsage) &&
       (param_2 != wil_details_ServiceReportingKind_DeviceOpportunity)) {
      if (param_2 == wil_details_ServiceReportingKind_PotentialUniqueUsage) goto LAB_14000c92c;
      if (param_2 == wil_details_ServiceReportingKind_PotentialUniqueOpportunity)
      goto LAB_14000c91c;
      if ((param_2 != wil_details_ServiceReportingKind_PotentialDeviceUsage) &&
         (param_2 != wil_details_ServiceReportingKind_PotentialDeviceOpportunity)) {
        uVar6 = param_2 - wil_details_ServiceReportingKind_VariantDeviceUsageBase;
        if ((int)uVar6 < 0x40) {
          uVar4 = (param_1->recorded).exchange;
          do {
            if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
              iVar3 = 0;
            }
            else {
              iVar3 = 1;
            }
            __return_storage_ptr__->ignoredUse = iVar3;
            LOCK();
            uVar5 = (param_1->recorded).exchange;
            bVar7 = uVar4 == uVar5;
            if (bVar7) {
              (param_1->recorded).exchange = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
            }
            else {
              uVar4 = uVar5;
            }
            UNLOCK();
          } while (!bVar7);
          if (__return_storage_ptr__->ignoredUse != 0) {
            return __return_storage_ptr__;
          }
        }
        __return_storage_ptr__->kindImmediate = param_2;
        __return_storage_ptr__->countImmediate = 1;
        __return_storage_ptr__->payloadId = param_3;
        return __return_storage_ptr__;
      }
    }
    uVar6 = 0;
    if (param_2 == wil_details_ServiceReportingKind_DeviceUsage) {
      uVar6 = 2;
    }
    else if (param_2 == wil_details_ServiceReportingKind_DeviceOpportunity) {
      uVar6 = 8;
    }
    else if (param_2 == wil_details_ServiceReportingKind_PotentialDeviceUsage) {
      uVar6 = 4;
    }
    else if (param_2 == wil_details_ServiceReportingKind_PotentialDeviceOpportunity) {
      uVar6 = 0x10;
    }
    iVar3 = 1;
    uVar4 = (param_1->reported).exchange;
    do {
      uVar2 = uVar4;
      uVar4 = uVar6 | uVar2;
      __return_storage_ptr__->ignoredUse = (uint)(uVar4 == uVar2);
      uVar5 = uVar4 | 1;
      if (uVar4 == uVar2) {
        uVar5 = uVar4;
      }
      LOCK();
      uVar1 = (param_1->reported).exchange;
      if (uVar2 == uVar1) {
        (param_1->reported).exchange = uVar5;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (uVar2 != uVar1);
    if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
      iVar3 = 0;
    }
    __return_storage_ptr__->queueBackground = iVar3;
  }
  return __return_storage_ptr__;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000c954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
wil_details_FeatureReporting_ReportUsageToService
          (wil_details_FeatureDescriptor *param_1,wil_details_FeatureStateCache param_2,
          wil_ReportingKind param_3,ulong64 param_4)

{
  wil_details_ServiceReportingKind wVar1;
  int iVar2;
  wil_details_FeatureDescriptor *pwVar3;
  uint uVar4;
  wil_ReportingKind local_res18 [4];
  
  uVar4 = param_2.exchange & 1;
  pwVar3 = (wil_details_FeatureDescriptor *)(ulonglong)param_3;
  local_res18[0] = param_3;
  wVar1 = wil_details_MapReportingKind(param_3,uVar4);
  iVar2 = wil_details_FeatureReporting_ReportUsageToServiceDirect(pwVar3,param_2,wVar1,param_2);
  if ((iVar2 != 0) &&
     (g_wil_details_pfnFeatureLoggingHook !=
      (_func___cdecl_void_uint_FEATURE_LOGGED_TRAITS_ptr_FEATURE_ERROR_ptr_int_wil_ReportingKind_ptr_wil_VariantReportingKind_ptr_uchar_ulong64
       *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x35cd1ae,&Feature_ValLabTest_logged_traits,(FEATURE_ERROR *)0x0,uVar4,local_res18,
               (wil_VariantReportingKind *)0x0,'\0',1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000c9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
wil_details_FeatureReporting_ReportUsageToServiceDirect
          (wil_details_FeatureDescriptor *param_1,wil_details_FeatureStateCache param_2,
          wil_details_ServiceReportingKind param_3,ulong64 param_4)

{
  uint6 uVar1;
  wil_details_RecordUsageResult *pwVar2;
  undefined1 auStackY_88 [32];
  uint in_stack_ffffffffffffff98;
  undefined8 local_58;
  wil_details_RecordUsageResult local_50;
  wil_details_RecordUsageResult local_38;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  pwVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (&local_50,&Feature_WdfUmdfRedirectorUmaSecurity01__private_reporting,param_3,
                      param_2._s_2.payloadId,in_stack_ffffffffffffff98);
  local_38.queueBackground = pwVar2->queueBackground;
  local_38.countImmediate = pwVar2->countImmediate;
  local_38.kindImmediate = pwVar2->kindImmediate;
  local_38.payloadId = pwVar2->payloadId;
  local_38.ignoredUse = pwVar2->ignoredUse;
  local_38.isWexpConfiguration = pwVar2->isWexpConfiguration;
  if (g_wil_details_recordFeatureUsage !=
      (_func___cdecl_void_uint_wil_details_ServiceReportingKind_uint_wil_details_FeatureReportingCache_ptr_wil_details_RecordUsageResult_ptr
       *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (0x35cd1ae,param_3,1,&Feature_WdfUmdfRedirectorUmaSecurity01__private_reporting,
               &local_38);
  }
  if ((ZPULL(param_2.exchange64,10,1) != 0) && (param_3 != wil_details_ServiceReportingKind_Store))
  {
    local_58._0_6_ = CONCAT24((short)param_3,0x35cd1ae);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (ZPULL(param_2.exchange64,0xb,1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (uint)(local_38.ignoredUse == 0);
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000cabc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

wil_details_FeatureStateCache __cdecl
wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
          (wil_details_FeatureStateCache *param_1,wil_details_FeatureStateCache param_2,
          wil_details_FeatureDescriptor *param_3)

{
  uint uVar1;
  wil_details_FeatureStateCache wVar2;
  wil_details_FeatureStateCache wVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_res8 [2];
  wil_details_FeatureStateCache local_res10;
  
  uVar1 = 0;
  local_res8[0] = 0;
  local_res10._s_2 = param_2._s_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (_func___cdecl_uint *)0x0) {
    uVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  wVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,(int *)local_res8);
  if (param_3->changeTime == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(uVar1 != 0);
  }
  wVar3.exchange64 = param_2.exchange64 & 0xffffffff;
  while( true ) {
    uVar6 = (uint)wVar3.exchange64;
    local_res10.exchange = uVar6;
    uVar4 = wVar2.exchange;
    if ((local_res8[0] != 0) && ((wVar3.exchange64 & 2) == 0)) {
      uVar5 = uVar6 & 0xfffff63e | uVar4 & 0x9c1;
      uVar6 = uVar5 | 2;
      local_res10.exchange64 = CONCAT44(local_res10._s_2.payloadId,uVar5) | 2;
    }
    if ((param_2.exchange64 & 4) == 0) {
      uVar5 = uVar4 & 0x400 | uVar6 & 0xfffffbff;
      uVar6 = uVar5 | 4;
      local_res10.exchange64 = CONCAT44(local_res10._s_2.payloadId,uVar5) | 4;
    }
    wVar3.exchange64 = param_2.exchange64 & 0xffffffff;
    LOCK();
    uVar5 = param_1->exchange;
    bVar7 = param_2.exchange == uVar5;
    if (bVar7) {
      param_1->exchange = uVar6;
    }
    else {
      wVar3._s_2.payloadId = 0;
      wVar3.exchange = uVar5;
    }
    UNLOCK();
    if (bVar7) break;
    param_2.exchange64 = wVar3.exchange64;
  }
  if (((param_2.exchange64 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges !=
      (_func___cdecl_void_wil_details_FeatureStateCache_ptr_wil_FeatureChangeTime_uint *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,(uint)param_3->changeTime,uVar1);
  }
  if (local_res8[0] == 0) {
    local_res10.exchange = uVar4 & 0x9c1 | uVar6 & 0xfffff63e;
  }
  return (wil_details_FeatureStateCache)local_res10.exchange64;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000cbcc =====

void __cdecl
wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
          (wil_details_FeatureStateCache param_1,wil_ReportingKind param_2,
          wil_details_FeatureDescriptor *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == wil_ReportingKind_DeviceUsage) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != wil_ReportingKind_DeviceOpportunity) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange & 2) != 0) {
    uVar1 = Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange;
    while ((uVar1 & 1) == (param_1.exchange & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange;
      if (bVar3) {
        Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState.exchange = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState._0_4_;
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



===== wil_details_GetCurrentFeatureEnabledState @ 14000cc20 =====

wil_details_FeatureStateCache __cdecl
wil_details_GetCurrentFeatureEnabledState(wil_details_FeatureDescriptor *param_1,int *param_2)

{
  uchar uVar1;
  wil_details_FeatureDescriptor *pwVar2;
  int iVar3;
  wil_FeatureEnabledState wVar4;
  wil_details_FeatureStateCache wVar5;
  uint uVar6;
  uint uVar7;
  wil_details_FeatureDescriptor **ppwVar8;
  ulonglong local_res8;
  wil_details_FeatureStateCache local_res10;
  wil_FeatureState local_28;
  
  uVar1 = param_1->changeTime;
  uVar6 = param_1->featureId;
  *param_2 = 1;
  local_28.hasNotification = 0;
  local_28.isWexpConfiguration = 0;
  local_28.enabledState = wil_FeatureEnabledState_Default;
  local_28.variant = '\0';
  local_28._5_3_ = 0;
  local_28.payloadKind = wil_FeatureVariantPayloadKind_None;
  local_28.payload = 0;
  iVar3 = wil_RtlStagingConfig_QueryFeatureState
                    (&local_28,uVar6,(uint)((byte)(uVar1 - 2) < 2),param_2);
  wVar4 = -(uint)(iVar3 != 0) & local_28.enabledState &
          (wil_FeatureEnabledState_Enabled|wil_FeatureEnabledState_Disabled);
  if (wVar4 == wil_FeatureEnabledState_Default) {
    uVar6 = -(uint)(param_1->isEnabledByDefault != '\0') & 0x40;
  }
  else {
    uVar6 = 0;
    if (local_28.enabledState == wil_FeatureEnabledState_Enabled) {
      uVar6 = 0x40;
    }
  }
  uVar7 = uVar6 >> 6 ^
          (wVar4 << 7 |
           -(uint)(local_28.isWexpConfiguration != 0) & 0x800 |
           -(uint)(local_28.hasNotification != 0) & 0x400 | uVar6);
  local_res8 = (ulonglong)uVar7;
  if ((uVar6 != 0) &&
     (ppwVar8 = param_1->requiresFeatures, ppwVar8 != (wil_details_FeatureDescriptor **)0x0)) {
    local_res8 = (ulonglong)uVar7;
    do {
      pwVar2 = *ppwVar8;
      if (pwVar2 == (wil_details_FeatureDescriptor *)0x0) {
        return (wil_details_FeatureStateCache)local_res8;
      }
      if ((pwVar2->isAlwaysEnabled == '\0') && (pwVar2->isAlwaysDisabled == '\0')) {
        local_res10.exchange = pwVar2->featureStateCache->exchange;
        local_res10._s_2.payloadId = 0;
        if ((local_res10.exchange & 2) == 0) {
          wVar5 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (pwVar2->featureStateCache,local_res10,pwVar2);
          local_res10.exchange = wVar5.exchange;
        }
        uVar6 = uVar7 & 0xfffffffe;
        uVar7 = (uint)((local_res10.exchange & uVar7 & 1) != 0);
      }
      else {
        if (((uVar7 & 1) == 0) || (pwVar2->isEnabledByDefault == '\0')) {
          uVar6 = 0;
        }
        else {
          uVar6 = 1;
        }
        uVar7 = uVar7 & 0xfffffffe;
      }
      uVar7 = uVar7 | uVar6;
      ppwVar8 = ppwVar8 + 1;
      local_res8 = (ulonglong)uVar7;
    } while ((uVar7 & 1) != 0);
  }
  return (wil_details_FeatureStateCache)local_res8;
}



===== wil_details_IsEnabledFallback @ 14000cd80 =====

int __cdecl
wil_details_IsEnabledFallback
          (wil_details_FeatureStateCache param_1,wil_ReportingKind param_2,
          wil_details_FeatureDescriptor *param_3,wil_UsageReportingMode param_4)

{
  wil_details_FeatureStateCache *pwVar1;
  wil_details_FeatureDescriptor *pwVar2;
  undefined4 in_register_0000008c;
  wil_details_FeatureStateCache local_res18;
  
  local_res18.exchange64 = param_1.exchange64 & 0xffffffff;
  if ((param_1.exchange64 & 2) == 0) {
    pwVar1 = &Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_WdfUmdfRedirectorUmaSecurity01__private_featureState,param_1,
                             &Feature_WdfUmdfRedirectorUmaSecurity01__private_descriptor);
    param_1.exchange64 = local_res18.exchange64 & 0xffffffff;
  }
  else {
    pwVar1 = (wil_details_FeatureStateCache *)param_1.exchange64;
  }
  if (param_2 != wil_ReportingKind_None) {
    pwVar2 = (wil_details_FeatureDescriptor *)(ulonglong)param_2;
    wil_details_FeatureReporting_ReportUsageToService
              ((wil_details_FeatureDescriptor *)pwVar1,local_res18,param_2,
               CONCAT44(in_register_0000008c,param_4));
    if (param_2 - wil_ReportingKind_DeviceUsage < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(local_res18,param_2,pwVar2);
    }
  }
  return param_1.exchange & 1;
}



===== wil_details_MapReportingKind @ 14000ce10 =====

wil_details_ServiceReportingKind __cdecl
wil_details_MapReportingKind(wil_ReportingKind param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != wil_ReportingKind_None) {
    if (param_1 == wil_ReportingKind_UniqueUsage) {
      return ~-(uint)(param_2 != 0) & wil_details_ServiceReportingKind_PotentialUniqueUsage;
    }
    if (param_1 == wil_ReportingKind_UniqueOpportunity) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) +
             wil_details_ServiceReportingKind_PotentialUniqueOpportunity;
    }
    if (param_1 == wil_ReportingKind_DeviceUsage) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) +
             wil_details_ServiceReportingKind_PotentialDeviceUsage;
    }
    if (param_1 == wil_ReportingKind_DeviceOpportunity) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) +
             wil_details_ServiceReportingKind_PotentialDeviceOpportunity;
    }
    if (param_1 == wil_ReportingKind_TotalDuration) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) +
             wil_details_ServiceReportingKind_DisabledTotalDuration;
    }
    if (param_1 == wil_ReportingKind_PausedDuration) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) +
             wil_details_ServiceReportingKind_DisabledPausedDuration;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return wil_details_ServiceReportingKind_None;
}



===== wil_details_RecordCachedUsage @ 14000ceb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl
wil_details_RecordCachedUsage
          (uint param_1,wil_details_FeatureReportingCache *param_2,
          _func___cdecl_void___WIL_RTL_FEATURE_USAGE_DATA_ptr_ulong64 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  __WIL_RTL_FEATURE_USAGE_DATA *p_Var5;
  ulong64 uVar6;
  bool bVar7;
  undefined1 auStack_68 [32];
  __WIL_RTL_FEATURE_USAGE_DATA local_48;
  __WIL_RTL_FEATURE_USAGE_DATA local_40 [5];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = (param_2->reported).exchange;
  do {
    LOCK();
    uVar4 = (param_2->reported).exchange;
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      (param_2->reported).exchange = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = (param_2->recorded).exchange;
    do {
      LOCK();
      uVar1 = (param_2->recorded).exchange;
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        (param_2->recorded).exchange = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
    uVar4 = uVar3 & ~uVar4;
  }
  p_Var5 = &local_48;
  if ((uVar4 & 1) != 0) {
    p_Var5 = local_40;
    local_48.ReportingKind = 2;
    local_48.UsageCount = 1;
    local_48.FeatureId = param_1;
  }
  if ((uVar4 & 2) != 0) {
    p_Var5->FeatureId = param_1;
    p_Var5->ReportingKind = 6;
    p_Var5->UsageCount = 1;
    p_Var5 = p_Var5 + 1;
  }
  if ((uVar4 & 4) != 0) {
    p_Var5->FeatureId = param_1;
    p_Var5->ReportingKind = 3;
    p_Var5->UsageCount = 1;
    p_Var5 = p_Var5 + 1;
  }
  if (7 < uVar4) {
    p_Var5->FeatureId = param_1;
    p_Var5->ReportingKind = 7;
    p_Var5->UsageCount = 1;
    p_Var5 = p_Var5 + 1;
  }
  if ((uVar2 >> 5 & 0x1ff) != 0) {
    p_Var5->FeatureId = param_1;
    p_Var5->UsageCount = (ushort)(uVar2 >> 5) & 0x1ff;
    p_Var5->ReportingKind = ((ushort)(uVar2 >> 0xe) & 1) << 2;
    p_Var5 = p_Var5 + 1;
  }
  if ((uVar2 >> 0xf & 0x7f) != 0) {
    p_Var5->FeatureId = param_1;
    p_Var5->UsageCount = (ushort)(uVar2 >> 0xf) & 0x7f;
    p_Var5->ReportingKind = ((ushort)(uVar2 >> 0x16) & 1) * 4 + 1;
    p_Var5 = p_Var5 + 1;
  }
  uVar6 = (longlong)p_Var5 - (longlong)&local_48 >> 3;
  if (0 < (longlong)uVar6) {
    wil_details_RecordFeatureUsageCallback(&local_48,uVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 14000d000 =====

void __cdecl
wil_details_RecordFeatureUsageReporting
          (uint param_1,wil_details_ServiceReportingKind param_2,uint param_3,
          wil_details_FeatureReportingCache *param_4,wil_details_RecordUsageResult *param_5)

{
  int iVar1;
  wil_details_RecordUsageResult *pwVar2;
  
  pwVar2 = param_5;
  iVar1 = g_wil_details_featureUsageCached;
  if (param_5->queueBackground != 0) {
    LOCK();
    g_wil_details_featureUsageCached = 1;
    UNLOCK();
    if ((iVar1 == 0) && (g_wil_details_featureUsageProvider != (void *)0x0)) {
      RtlArmFeatureUsageProviderFlushNotification(g_wil_details_featureUsageProvider,1);
    }
  }
  if (pwVar2->countImmediate != 0) {
    param_5._4_2_ = (undefined2)pwVar2->kindImmediate;
    param_5._6_2_ = (undefined2)pwVar2->countImmediate;
    param_5._0_4_ = param_1;
    RtlRecordFeatureUsage(&param_5,1);
  }
  return;
}



===== RdFdoDevice @ 14000d084 =====

/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

RdFdoDevice * __thiscall
RdFdoDevice::RdFdoDevice
          (RdFdoDevice *this,RdFdoDeviceParameters *param_1,
          WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *param_2,WdfObject *param_3)

{
  DEBUG_MODE_FLAGS *pDVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  _IO_WORKITEM *p_Var7;
  RdDevice *this_00;
  ushort uVar8;
  ulonglong uVar9;
  ulong uVar10;
  wchar_t *pwVar11;
  void *local_res8;
  WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *pWVar12;
  uchar uVar13;
  undefined4 in_stack_ffffffffffffffa8;
  ulong uVar14;
  ulong *in_stack_ffffffffffffffb8;
  _UNICODE_STRING local_38;
  
  uVar14 = CONCAT31((int3)((uint)in_stack_ffffffffffffffa8 >> 8),1);
  uVar10 = param_1->PhysicalDeviceObject->DeviceType;
  uVar13 = (uchar)uVar10;
  pWVar12 = (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0;
  RdDevice::RdDevice((RdDevice *)this,param_1->RdDriver,param_1->RdDeviceName,(wchar_t *)0x0,
                     (_UNICODE_STRING *)0x0,uVar10,param_3,RdTypeFdo,'\x01');
  this->_padding_ = (longlong)&___7RdFdoDevice__6B_;
  pDVar1->Enabled = '\0';
  pDVar1->DisableTimeouts = '\0';
  pDVar1->DisablePooling = '\0';
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    pWVar12 = param_2;
    WPP_SF_qqq((WPP_GLOBAL_Control->Control).Logger,0xc,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,param_1,param_2,param_3);
    uVar13 = (uchar)param_3;
  }
  this->m_Pdo = param_1->PhysicalDeviceObject;
  this->m_IsCompanion = param_1->IsCompanionMode;
  this->m_KernelServiceName = (wchar_t *)0x0;
  this->m_CompanionCallback = param_1->CompanionCallback;
  this->m_OpenProcessNtStatus = -0x3fffffff;
  this->m_ObjectList = (WdfObjectList<RdFdoDevice,RdFdoDeviceParameters> *)0x0;
  this->m_RdProcess = (RdProcess *)0x0;
  this->m_DevnodeContext = (WUDF_DEVNODE_CONTEXT__ *)0x0;
  this->m_CloseProcessMsg = (IUMDFLPCMessage *)0x0;
  this->m_DeviceDisabled = 0;
  this->m_DirectlyTerminatedHostProcess = false;
  this->m_HasProblem = false;
  this->m_RundownIoWorkItem = (_IO_WORKITEM *)0x0;
  this->m_RundownIoWorkItemActive = false;
  this->m_RdCmResources = (RdCmResources *)0x0;
  this->m_DriverInfo = (_DRIVER_SERVICE_INFO *)0x0;
  this->m_NumIOsCompleted = 0;
  this->m_PreAllocatedSynchronousTaskMsg = (IUMDFLPCMessage *)0x0;
  this->m_DiagnosticsSubKey = (void *)0x0;
  (this->m_HostProblem).ProblemCode = WudfProblem_None;
  (this->m_HostProblem).field_0x1 = 0;
  (this->m_HostProblem)._padding_ = 0;
  (this->m_HostProblem).Detector = WdfComponentInvalid;
  (this->m_HostProblem).field_0x5 = 0;
  (this->m_HostProblem)._padding_ = 0;
  (this->m_HostProblem).ExitCode = WdfHostExit_CodeUnknown;
  (this->m_HostProblem).field_0x9 = 0;
  (this->m_HostProblem)._padding_ = 0;
  (this->m_HostProblem).Operation = WudfOperation_Invalid;
  (this->m_HostProblem).field_0xd = 0;
  (this->m_HostProblem)._padding_ = 0;
  (this->m_HostProblem).Message = WudfMsg_Reserved;
  (this->m_HostProblem).field_0x11 = 0;
  (this->m_HostProblem).IrpInfo = 0;
  (this->m_HostProblem).Status = 0;
  *(undefined4 *)&(this->m_HostProblem).DeviceStarted = 0;
  this->m_PrepareSharedResourcesStatus = -0x3fffffff;
  this->m_IsLegacyStack = false;
  KeInitializeEvent(&this->m_HostProcessReady,0,0);
  KeInitializeEvent(&this->m_HostProcessCloseDone,0,0);
  uVar4 = (uint)this->_padding_;
  if ((int)uVar4 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d581;
    uVar8 = 0xd;
    goto LAB_14000d572;
  }
  if (this->m_IsCompanion == '\0') {
    uVar4 = 0xc000000d;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xe,
              WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids);
    }
    goto LAB_14000d581;
  }
  local_res8 = (void *)0x0;
  if (param_1->KernelServiceName == (wchar_t *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (2 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xf,
              WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids);
    }
  }
  else {
    uVar4 = RtlStringCchLengthW(param_1->KernelServiceName,0x101,(ulong64 *)&local_res8);
    if (-1 < (int)uVar4) {
      uVar9 = (longlong)local_res8 + 1;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar9;
      uVar5 = SUB168(ZEXT816(2) * auVar3,0);
      if (SUB168(ZEXT816(2) * auVar3,8) != 0) {
        uVar5 = 0xffffffffffffffff;
      }
      pwVar6 = (wchar_t *)ExAllocatePool2(0x40,uVar5,0x30444d75);
      this->m_KernelServiceName = pwVar6;
      if (pwVar6 == (wchar_t *)0x0) {
        uVar4 = 0xc0000017;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d581;
        uVar8 = 0x11;
      }
      else {
        pwVar11 = param_1->KernelServiceName;
        uVar4 = RtlStringCchCopyW(pwVar6,uVar9,pwVar11);
        uVar10 = (ulong)pwVar11;
        if ((int)uVar4 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
             (1 < (WPP_GLOBAL_Control->Control).Level)) {
            WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x12,
                     WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar4);
          }
          uVar4 = 0xc00000e5;
          goto LAB_14000d581;
        }
        local_res8 = (void *)0x0;
        this_00 = (RdDevice *)&local_38;
        local_38.Length = 0;
        local_38.MaximumLength = 0;
        local_38._4_4_ = 0;
        local_38.Buffer = (wchar_t *)0x0;
        RtlInitUnicodeString(this_00,L"WUDFDiagnosticInfo");
        uVar4 = RdDevice::RdCreatePnpRegKey
                          (this_00,this->m_Pdo,uVar10,&local_38,(_UNICODE_STRING *)pWVar12,uVar13,
                           '\x01','\x01',uVar14,&local_res8,in_stack_ffffffffffffffb8);
        if ((int)uVar4 < 0) {
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level == '\0')) goto LAB_14000d581;
          uVar8 = 0x13;
        }
        else {
          this->m_DiagnosticsSubKey = local_res8;
          this->m_RundownIoLock = 0;
          p_Var7 = (_IO_WORKITEM *)IoAllocateWorkItem(this->_padding_);
          this->m_RundownIoWorkItem = p_Var7;
          if (p_Var7 != (_IO_WORKITEM *)0x0) {
            if (((RdDriver *)this->_padding_)->m_DriverManagerLpcComm ==
                (IUMDFLPCCommPortInterface *)0x0) {
              this->m_PrepareSharedResourcesStatus = -0x3fffffcc;
            }
            else {
              uVar4 = RdDriver::PrepareSharedResources((RdDriver *)this->_padding_);
              this->m_PrepareSharedResourcesStatus = uVar4;
              if ((int)uVar4 < 0) {
                if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                    (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
                   ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d581;
                uVar8 = 0x15;
                goto LAB_14000d572;
              }
            }
            this->m_ObjectList = param_2;
            lVar2 = param_2->_padding_;
            KeEnterCriticalRegion();
            ExAcquireResourceExclusiveLite(lVar2,1);
            this->_padding_ = (longlong)param_2->m_List;
            uVar10 = param_2->m_NextUniqueObjectId;
            param_2->m_NextUniqueObjectId = uVar10 + 1;
            *(ulong *)&this->_padding_ = uVar10;
            param_2->m_List = (WdfObject *)this;
            ExReleaseResourceLite(param_2->_padding_);
            KeLeaveCriticalRegion();
            uVar4 = 0;
            goto LAB_14000d581;
          }
          uVar4 = 0xc000009a;
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 2) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level == '\0')) goto LAB_14000d581;
          uVar8 = 0x14;
        }
      }
LAB_14000d572:
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar8,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar4);
      goto LAB_14000d581;
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x10,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar4);
    }
  }
  uVar4 = 0xc000000d;
LAB_14000d581:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar4);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000002) == 0x80000002)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0x16,
            WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids);
  }
  return this;
}



===== OpenCompanionConfigRegKey @ 14000d5e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
RdFdoDevice::OpenCompanionConfigRegKey(RdFdoDevice *this,void *param_1,void **param_2)

{
  undefined1 auVar1 [16];
  short sVar2;
  uint uVar3;
  undefined8 uVar4;
  ushort uVar5;
  wchar_t *pwVar6;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  void *pvStack_e0;
  ulong64 local_d8 [2];
  wchar_t *local_c8;
  undefined8 local_c0;
  wchar_t *pwStack_b8;
  undefined8 local_b0;
  void *pvStack_a8;
  undefined8 *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  wchar_t local_80 [28];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  local_d8[0] = 0;
  local_b0 = 0;
  pvStack_a8 = (void *)0x0;
  local_80[0x18] = 0;
  local_c8 = local_80;
  local_a0 = (undefined8 *)0x0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_c0 = 0;
  pwStack_b8 = (wchar_t *)0x0;
  local_d8[1] = 0x320030;
  builtin_wcsncpy(local_80,L"CompanionConfigu",0x10);
  *param_2 = (void *)0xffffffffffffffff;
  pwVar6 = this->m_KernelServiceName;
  builtin_wcsncpy(local_80 + 0x10,L"rations\\",8);
  local_e8 = 0;
  pvStack_e0 = (void *)0x0;
  uVar3 = RtlStringCchLengthW(pwVar6,0x7fffffff,local_d8);
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
       ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d86d;
    uVar5 = 0x17;
  }
  else {
    sVar2 = (short)local_d8[0] * 2;
    local_c0._0_4_ = CONCAT22(sVar2 + 2,sVar2);
    local_e8._0_4_ = CONCAT22(sVar2 + 0x32U,(undefined2)local_e8);
    auVar1 = ZEXT816(2) * ZEXT216((ushort)(sVar2 + 0x32U) >> 1);
    uVar4 = auVar1._0_8_;
    if (auVar1._8_8_ != 0) {
      uVar4 = 0xffffffffffffffff;
    }
    pwStack_b8 = pwVar6;
    pvStack_e0 = (void *)ExAllocatePool2(0x40,uVar4,0x30444d55);
    if (pvStack_e0 == (void *)0x0) {
      uVar3 = 0xc000009a;
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
         ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d86d;
      uVar5 = 0x18;
    }
    else {
      uVar3 = RtlAppendUnicodeStringToString(&local_e8,local_d8 + 1);
      if ((int)uVar3 < 0) {
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
           ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d86d;
        uVar5 = 0x19;
      }
      else {
        uVar3 = RtlAppendUnicodeStringToString(&local_e8,&local_c0);
        if ((int)uVar3 < 0) {
          if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d86d;
          uVar5 = 0x1a;
        }
        else {
          local_a0 = &local_e8;
          local_b0 = CONCAT44(local_b0._4_4_,0x30);
          uStack_98 = CONCAT44(uStack_98._4_4_,0x240);
          local_90 = 0;
          uStack_88 = 0;
          pvStack_a8 = param_1;
          uVar3 = ZwOpenKey(param_2,0x20019,&local_b0);
          if ((((-1 < (int)uVar3) ||
               (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) ||
              (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) == 0)) ||
             ((WPP_GLOBAL_Control->Control).Level < 2)) goto LAB_14000d86d;
          uVar5 = 0x1b;
        }
      }
    }
  }
  WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar5,
           WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar3);
LAB_14000d86d:
  if (pvStack_e0 != (void *)0x0) {
    operator_delete(pvStack_e0);
  }
  return uVar3;
}



===== RdPrepareToCommunicateWithCompanionHost @ 14000d8a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdFdoDevice::RdPrepareToCommunicateWithCompanionHost(RdFdoDevice *this)

{
  longlong *plVar1;
  uint uVar2;
  
  if (this->m_RdProcess == (RdProcess *)0x0) {
    uVar2 = 0xc0000001;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,10,
              WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids);
    }
  }
  else {
    uVar2 = RdProcess::ConnectToProcess(this->m_RdProcess);
    if (-1 < (int)uVar2) {
      plVar1 = *(longlong **)(this->_padding_ + 0x70);
      uVar2 = (**(code **)(*plVar1 + 0x48))
                        (plVar1,&this->m_PreAllocatedSynchronousTaskMsg,0xffd7,0xffd7,
                         this->m_RdProcess->m_IoEventLpcComm,0,0,0,0);
      if (((((int)uVar2 < 0) &&
           (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xb,
                 WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar2);
      }
    }
  }
  return uVar2;
}



===== RdSendCompanionAddMessageToCompanionHost @ 14000d9b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

long __thiscall
RdFdoDevice::RdSendCompanionAddMessageToCompanionHost(RdFdoDevice *this,ulong64 param_1)

{
  _LIST_ENTRY *p_Var1;
  WudfProblem WVar2;
  uint uVar3;
  longlong lVar4;
  _LARGE_INTEGER _Var5;
  uint *puVar6;
  undefined7 extraout_var;
  uchar auVar7 [8];
  _GUID *p_Var8;
  ulong uVar9;
  ulong64 in_R9;
  code *pcVar10;
  ulonglong uVar11;
  undefined1 auStackY_a8 [32];
  _GUID local_68;
  IUMDFLPCMessage *local_58;
  WUDF_PROBLEM local_50;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68.Data1 = 0;
  local_68.Data4[0] = '\0';
  local_68.Data4[1] = '\0';
  local_68.Data4[2] = '\0';
  local_68.Data4[3] = '\0';
  local_68.Data4[4] = '\0';
  local_68.Data4[5] = '\0';
  local_68.Data4[6] = '\0';
  local_68.Data4[7] = '\0';
  local_58 = (IUMDFLPCMessage *)0x0;
  p_Var1 = (this->m_DriverInfo->Head).Flink;
  auVar7[0] = '\0';
  auVar7[1] = '\0';
  auVar7[2] = '\0';
  auVar7[3] = '\0';
  auVar7[4] = '\0';
  auVar7[5] = '\0';
  auVar7[6] = '\0';
  auVar7[7] = '\0';
  uVar11 = (ulonglong)*(uint *)&p_Var1[2].Blink + 0x18;
  if (0x21a < uVar11) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_qd((WPP_GLOBAL_Control->Control).Logger,0x1c,
                WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,this,0x21a);
    }
    return -0x3ffffbd5;
  }
  uVar3 = CreateUmdfLpcMessage
                    (this,0x10,4,in_R9,WudfMsg_COMPANION_REMOVE,
                     this->m_RdProcess->m_SystemEventLpcComm,&local_58);
  if ((-1 < (int)uVar3) &&
     (uVar3 = CreateUmdfLpcMessage
                        (this,uVar11,0x10,in_R9,WudfMsg_COMPANION_ADD,
                         this->m_RdProcess->m_SystemEventLpcComm,(IUMDFLPCMessage **)local_68.Data4)
     , auVar7 = local_68.Data4, -1 < (int)uVar3)) {
    lVar4 = (**(code **)(*(longlong *)local_68.Data4 + 0x18))(local_68.Data4,uVar11);
    *(ulong64 *)(lVar4 + 8) = param_1;
    *(uint *)(lVar4 + 0x10) = *(uint *)&p_Var1[2].Blink >> 1;
    memcpy();
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       ((((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0 &&
        (3 < (WPP_GLOBAL_Control->Control).Level)))) {
      WPP_SF_q((WPP_GLOBAL_Control->Control).Logger,0x1d,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,(void *)auVar7);
    }
    pcVar10 = *(code **)(*(longlong *)auVar7 + 0x28);
    _Var5 = RdProcess::HostProcessTimeoutInTimerUnit(this->m_RdProcess);
    p_Var8 = &local_68;
    puVar6 = (uint *)(*pcVar10)(auVar7,*(undefined8 *)_Var5._s_0);
    uVar3 = local_68.Data1;
    uVar9 = (ulong)pcVar10;
    if (puVar6 == (uint *)0x0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        p_Var8 = WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids;
        uVar9 = local_68.Data1;
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x1e,
                 WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,local_68.Data1);
      }
      local_50.Message = WudfMsg_COMPANION_ADD;
      local_50._17_1_ = 0;
      local_50.IrpInfo = 0;
      WVar2 = MapToSendProblem(uVar3);
      local_50._0_4_ = SUB84(CONCAT71(extraout_var,WVar2),0);
      local_50.Detector = WdfComponentReflector;
      local_50._5_1_ = 0;
      local_50._padding_ = 0;
      local_50.ExitCode = WdfHostExit_CodeUnknown;
      local_50._9_1_ = 0;
      local_50._padding_ = 0x7000;
      local_50.DeviceStarted = WudfDeviceStartState_Unknown;
      local_50._25_3_ = 0;
      local_50.Operation = WudfOperation_Pnp;
      local_50._13_1_ = 0;
      local_50._padding_ = 0;
      local_50.Status = uVar3;
      DisableDevice(this,&local_50,(wchar_t *)p_Var8,uVar9);
      if (-1 < (int)uVar3) goto LAB_14000dbf6;
    }
    else {
      uVar3 = *puVar6;
      this->m_CreateDeviceStackNtStatus = uVar3;
      if (-1 < (int)uVar3) {
        this->m_CompanionContext = *(WUDF_COMPANION_CONTEXT__ **)(puVar6 + 2);
        this->m_CompanionRemoveMsg = local_58;
        goto LAB_14000dbf6;
      }
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x1f,
                 WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar3);
      }
    }
  }
  if (local_58 != (IUMDFLPCMessage *)0x0) {
    (**(code **)((longlong)*local_58 + 8))();
  }
LAB_14000dbf6:
  if (auVar7 != (uchar  [8])0x0) {
    (**(code **)(*(longlong *)auVar7 + 8))(auVar7);
  }
  return uVar3;
}



===== RdSendCompanionRemoveMessageToCompanionHost @ 14000dca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "_WDF_HOST_EXIT_CODE": Some values do not have unique names */

long __thiscall RdFdoDevice::RdSendCompanionRemoveMessageToCompanionHost(RdFdoDevice *this)

{
  uint uVar1;
  undefined1 *puVar2;
  _LARGE_INTEGER _Var3;
  uint *puVar4;
  undefined7 extraout_var;
  ulong uVar5;
  _GUID *p_Var6;
  ulong uVar7;
  code *pcVar8;
  IUMDFLPCMessage *pIVar9;
  undefined1 auStack_68 [32];
  _GUID local_48;
  WUDF_PROBLEM local_38;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_38.Message = WudfMsg_Reserved;
  local_38._17_1_ = 0;
  local_38.IrpInfo = 0;
  local_38.Status = 0;
  local_38.DeviceStarted = WudfDeviceStartState_Unknown;
  local_38._25_3_ = 0;
  local_48.Data1 = 0;
  local_38.ProblemCode = WudfProblem_None;
  local_38._1_1_ = 0;
  local_38._padding_ = 0;
  local_38.Detector = WdfComponentInvalid;
  local_38._5_1_ = 0;
  local_38._padding_ = 0;
  local_38.ExitCode = WdfHostExit_CodeUnknown;
  local_38._9_1_ = 0;
  local_38._padding_ = 0;
  local_38.Operation = WudfOperation_Invalid;
  local_38._13_1_ = 0;
  local_38._padding_ = 0;
  puVar2 = (undefined1 *)
           (**(code **)((longlong)*this->m_CompanionRemoveMsg + 0x18))
                     (this->m_CompanionRemoveMsg,0x10);
  *puVar2 = 0x17;
  *(WUDF_COMPANION_CONTEXT__ **)(puVar2 + 8) = this->m_CompanionContext;
  pIVar9 = this->m_CompanionRemoveMsg;
  pcVar8 = *(code **)((longlong)*pIVar9 + 0x28);
  _Var3 = RdProcess::HostProcessTimeoutInTimerUnit(this->m_RdProcess);
  p_Var6 = &local_48;
  puVar4 = (uint *)(*pcVar8)(pIVar9,*(undefined8 *)_Var3._s_0);
  uVar5 = local_48.Data1;
  uVar7 = (ulong)pcVar8;
  if (puVar4 == (uint *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      p_Var6 = WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids;
      uVar7 = local_48.Data1;
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x28,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,local_48.Data1);
    }
    local_38.ProblemCode = MapToSendProblem(uVar5);
    local_38.Detector = WdfComponentReflector;
    local_38._5_1_ = 0;
    local_38._padding_ = 0;
    local_38._1_1_ = (char)(CONCAT71(extraout_var,local_38.ProblemCode) >> 8);
    local_38._padding_ = (short)(CONCAT71(extraout_var,local_38.ProblemCode) >> 0x10);
    local_38.DeviceStarted = WudfDeviceStartState_Unknown;
    local_38._25_3_ = 0;
    local_38.ExitCode = WdfHostExit_CodeUnknown;
    local_38._9_1_ = 0;
    local_38._padding_ = 0x7000;
    local_38.Operation = WudfOperation_Pnp;
    local_38._13_1_ = 0;
    local_38._padding_ = 0;
    local_38.Message = WudfMsg_COMPANION_REMOVE;
    local_38._16_8_ = CONCAT44(uVar5,local_38._16_4_) & 0xffffffff0000ffff;
    DisableDevice(this,&local_38,(wchar_t *)p_Var6,uVar7);
  }
  else {
    uVar1 = *puVar4;
    uVar5 = 0;
    if (((((int)uVar1 < 0) &&
         (uVar5 = uVar1, WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 2) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x29,
               WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,uVar1);
    }
  }
  (**(code **)((longlong)*this->m_CompanionRemoveMsg + 8))();
  this->m_CompanionRemoveMsg = (IUMDFLPCMessage *)0x0;
  return uVar5;
}



===== WPP_SF_qPP @ 14000de34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qPP(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,ulong64 param_5,
          ulong64 param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,0x27);
  return;
}



===== WPP_SF_qid @ 14000de98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qid(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,long64 param_5,int param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_296f7ca57bb735dfb98cd7e2d511be15_Traceguids,0x24);
  return;
}



===== RdFxLibCtrlDevice @ 14000df08 =====

RdFxLibCtrlDevice * __thiscall
RdFxLibCtrlDevice::RdFxLibCtrlDevice(RdFxLibCtrlDevice *this,RdDriver *param_1,wchar_t *param_2)

{
  uint *puVar1;
  uint uVar2;
  void *pvVar3;
  ushort uVar4;
  RdDriver *pRVar5;
  wchar_t *pwVar6;
  wchar_t *local_res18 [2];
  _UNICODE_STRING *p_Var7;
  uint uVar8;
  
  pwVar6 = L"WUDFRdNonPnP-01ef3135-0713-470c-95dc-5d1b184938c4";
  uVar8 = 0;
  p_Var7 = &SDDL_DEVOBJ_KERNEL_ONLY;
  pRVar5 = param_1;
  local_res18[0] = param_2;
  RdDevice::RdDevice((RdDevice *)this,param_1,L"WUDFRdNonPnP-01ef3135-0713-470c-95dc-5d1b184938c4",
                     L"WUDFRdNonPnP-01ef3135-0713-470c-95dc-5d1b184938c4",&SDDL_DEVOBJ_KERNEL_ONLY,
                     0x22,(WdfObject *)param_1,RdTypeContolDriverManager,'\0');
  *(undefined ***)this = &___7RdFxLibCtrlDevice__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_qS((WPP_GLOBAL_Control->Control).Logger,(ushort)pRVar5,(_GUID *)pwVar6,param_1,
              (wchar_t *)p_Var7);
  }
  local_res18[0] = (wchar_t *)0x0;
  uVar2 = *(uint *)&this->field_0x10;
  if ((int)uVar2 < 0) goto LAB_14000e12a;
  pvVar3 = WdfPlatformSecurity::WudfAllocateSecurityDescriptor
                     ((void **)(*(longlong *)SeExports_exref + 0x108),1);
  if (pvVar3 == (void *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,
              WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = ObOpenObjectByPointer
                      (*(undefined8 *)&this->field_0x68,0x200,0,0x40000,0,uVar8 & 0xffffff00,
                       local_res18);
    if ((int)uVar2 < 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          (((WPP_GLOBAL_Control->Control).Flags[0] & 8) != 0)) &&
         (1 < (WPP_GLOBAL_Control->Control).Level)) {
        uVar4 = 0xc;
LAB_14000e06c:
        WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,uVar4,
                 WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids,uVar2);
      }
    }
    else {
      uVar2 = ZwSetSecurityObject(local_res18[0],4,pvVar3);
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 4) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          uVar4 = 0xd;
          goto LAB_14000e06c;
        }
      }
      else {
        *(undefined1 *)(*(longlong *)&this->field_0x68 + 0x4c) = 1;
        puVar1 = (uint *)(*(longlong *)&this->field_0x68 + 0x30);
        *puVar1 = *puVar1 | 4;
        puVar1 = (uint *)(*(longlong *)&this->field_0x68 + 0x30);
        *puVar1 = *puVar1 & 0xffffff7f;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 0x10) != 0)) &&
           (3 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_S((WPP_GLOBAL_Control->Control).Logger,0xe,
                   WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids,*(wchar_t **)&this->field_0x48);
        }
      }
    }
    operator_delete(pvVar3);
  }
  if (local_res18[0] != (wchar_t *)0x0) {
    ZwClose();
  }
LAB_14000e12a:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->field_0x10,uVar2);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xf,WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids
           );
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000e190 =====

void * __thiscall
RdFxLibCtrlDevice::_scalar_deleting_destructor_(RdFxLibCtrlDevice *this,uint param_1)

{
  *(undefined ***)this = &___7RdFxLibCtrlDevice__6B_;
  RdDevice::~RdDevice((RdDevice *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== RdCreate @ 14000e1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdFxLibCtrlDevice::RdCreate(RdFxLibCtrlDevice *this,_IRP *param_1)

{
  long lVar1;
  void *pvVar2;
  
  if (param_1->RequestorMode == '\0') {
    lVar1 = (**(code **)(*(longlong *)this + 0xb0))(this,this);
  }
  else {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 8) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      pvVar2 = (void *)PsGetCurrentProcessId();
      WPP_SF_qq((WPP_GLOBAL_Control->Control).Logger,0x10,
                WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids,pvVar2,this);
    }
    lVar1 = -0x3fffffde;
  }
  (param_1->IoStatus).field0_0x0.Status = lVar1;
  IofCompleteRequest(param_1,0);
  (**(code **)(*(longlong *)this + 0xa8))(this,param_1,0);
  return lVar1;
}



===== RdInternalDeviceIoControl @ 14000e2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall RdFxLibCtrlDevice::RdInternalDeviceIoControl(RdFxLibCtrlDevice *this,_IRP *param_1)

{
  void *pvVar1;
  _IRP *p_Var2;
  undefined8 uVar3;
  uint uVar4;
  
  pvVar1 = (param_1->Tail).Apc.SystemArgument1;
  uVar4 = 0xc0000010;
  if (*(int *)((longlong)pvVar1 + 0x18) == -0x7ffd7c00) {
    if (*(uint *)((longlong)pvVar1 + 8) < 8) {
      uVar4 = 0xc0000023;
    }
    else {
      uVar4 = 0;
      p_Var2 = (param_1->AssociatedIrp).MasterIrp;
      uVar3 = *(undefined8 *)(*(longlong *)&this->field_0x78 + 0xd0);
      p_Var2->Type = (short)uVar3;
      p_Var2->Size = (short)((ulonglong)uVar3 >> 0x10);
      *(int *)&p_Var2->field_0x4 = (int)((ulonglong)uVar3 >> 0x20);
      (param_1->IoStatus).Information = 8;
    }
  }
  (param_1->IoStatus).field0_0x0.Status = uVar4;
  IofCompleteRequest(param_1,0);
  (**(code **)(*(longlong *)this + 0xa8))(this,param_1,0xe);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     (((WPP_GLOBAL_Control->Control).Flags[0] & 0x80000010) == 0x80000010)) {
    WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0x11,
             WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids,uVar4);
  }
  return uVar4;
}



===== WPP_SF_qS @ 14000e374 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_qS(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,wchar_t *param_5)

{
  longlong lVar1;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (L"WUDFRdNonPnP-01ef3135-0713-470c-95dc-5d1b184938c4"[lVar1] != L'\0');
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_78dce3c532ca3bb067cb22d291025ebd_Traceguids,10);
  return;
}



===== ~CUmdfSvcConfig @ 14000e3f0 =====

void __thiscall CUmdfSvcConfig::~CUmdfSvcConfig(CUmdfSvcConfig *this)

{
  if ((this->m_AutoClose != '\0') && (this->m_Key != (void *)0x0)) {
    ZwClose();
  }
  return;
}



===== GetSecureSoftwareDeviceTag @ 14000e41c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
CUmdfSvcConfig::GetSecureSoftwareDeviceTag(CUmdfSvcConfig *this,void *param_1,ulong *param_2)

{
  long lVar1;
  ulong in_R9D;
  undefined1 auStackY_b8 [32];
  ulong local_88 [2];
  void *local_80;
  _UNICODE_STRING local_78;
  _UNICODE_STRING local_68;
  wchar_t local_58 [8];
  wchar_t local_48 [20];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88[0] = 0;
  local_80 = (void *)0x0;
  builtin_wcsncpy(local_58,L"WUDF",5);
  local_78.Buffer = local_58;
  builtin_wcsncpy(local_48,L"SoftwareDeviceTag",0x12);
  local_68.Buffer = local_48;
  local_78.Length = 8;
  local_78.MaximumLength = 10;
  local_78._4_4_ = 0;
  local_68.Length = 0x22;
  local_68.MaximumLength = 0x24;
  local_68._4_4_ = 0;
  lVar1 = OpenKeyHelper(this,param_1,&local_78,in_R9D,'\0',&local_80);
  if (-1 < lVar1) {
    lVar1 = _QueryULong(local_80,&local_68,local_88);
    if (-1 < lVar1) {
      *param_2 = local_88[0];
    }
  }
  if (local_80 != (void *)0x0) {
    ZwClose();
  }
  return lVar1;
}



===== OpenKeyHelper @ 14000e50c =====

long __thiscall
CUmdfSvcConfig::OpenKeyHelper
          (CUmdfSvcConfig *this,void *param_1,_UNICODE_STRING *param_2,ulong param_3,uchar param_4,
          void **param_5)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  _UNICODE_STRING *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  *param_5 = (void *)0x0;
  if ((param_4 == '\0') || (this->m_Key == (void *)0x0)) {
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    local_30 = param_1;
    local_28 = param_2;
    iVar1 = ZwOpenKey(param_5,0x20019,&local_38);
    if ((-1 < iVar1) && (param_4 != '\0')) {
      this->m_Key = *param_5;
    }
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== OpenRootKey @ 14000e5a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall CUmdfSvcConfig::OpenRootKey(CUmdfSvcConfig *this,ulong param_1,void **param_2)

{
  long lVar1;
  undefined1 auStackY_e8 [32];
  _UNICODE_STRING local_b8;
  wchar_t local_a8 [72];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_b8.Length = 0x86;
  local_b8.MaximumLength = 0x88;
  local_b8._4_4_ = 0;
  builtin_wcsncpy(local_a8,
                  L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\WUDF",0x44
                 );
  local_b8.Buffer = local_a8;
  lVar1 = OpenKeyHelper(this,(void *)0x0,&local_b8,0x80,this->m_AutoClose,param_2);
  return lVar1;
}



===== OpenServiceKey @ 14000e668 =====

long __thiscall
CUmdfSvcConfig::OpenServiceKey(CUmdfSvcConfig *this,wchar_t *param_1,ulong param_2,void **param_3)

{
  ushort uVar1;
  long lVar2;
  longlong lVar3;
  ulong uVar4;
  ulong64 local_res20;
  void *local_38;
  _UNICODE_STRING local_30;
  
  uVar4 = (ulong)param_3;
  local_res20 = 0;
  local_38 = (void *)0x0;
  *param_3 = (void *)0x0;
  local_30.Length = 0;
  local_30.MaximumLength = 0;
  local_30._4_4_ = 0;
  local_30.Buffer = (wchar_t *)0x0;
  lVar2 = RtlStringCchLengthW(param_1,0x101,&local_res20);
  if (-1 < lVar2) {
    uVar1 = ((short)local_res20 + 0x4e) * 2;
    if (uVar1 < 0x9c) {
      lVar2 = -0x3fffff6b;
    }
    else {
      lVar3 = ExAllocatePool2(0x40,(ulonglong)uVar1 * 2,0x43534d55);
      if (lVar3 == 0) {
        lVar2 = -0x3fffff66;
      }
      else {
        RtlInitUnicodeString(&local_30,lVar3);
        local_30.MaximumLength = uVar1;
        lVar2 = RtlAppendUnicodeToString
                          (&local_30,
                           L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\WUDF\\Services\\"
                          );
        if (-1 < lVar2) {
          lVar2 = RtlAppendUnicodeToString(&local_30);
          if (-1 < lVar2) {
            lVar2 = OpenKeyHelper(this,(void *)0x0,&local_30,uVar4,this->m_AutoClose,&local_38);
            if (-1 < lVar2) {
              *param_3 = local_38;
            }
          }
        }
        ExFreePoolWithTag(lVar3,0);
      }
    }
  }
  return lVar2;
}



===== _QueryULong @ 14000e7bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl CUmdfSvcConfig::_QueryULong(void *param_1,_UNICODE_STRING *param_2,ulong *param_3)

{
  int iVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 *local_30;
  undefined4 local_28 [2];
  undefined1 local_20 [4];
  int local_1c;
  ulong local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = local_28;
  local_28[0] = 0x10;
  local_38 = 0x10;
  iVar1 = ZwQueryValueKey(param_1,param_2,2,local_20);
  if (((iVar1 + 0x80000000U & 0x80000000) != 0) || (iVar1 == -0x7ffffffb)) {
    if (local_1c == 4) {
      if (-1 < iVar1) {
        *param_3 = local_14;
      }
    }
    else {
      iVar1 = -0x3fffffdc;
    }
  }
  return iVar1;
}



===== TimerDPC @ 14000e850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl TimerDPC(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  (**(code **)((longlong)param_2 + 0x80))(*(undefined8 *)((longlong)param_2 + 0x88));
  return;
}



===== WaitEvent @ 14000e874 =====

uchar __cdecl WdfPlatformWait::WaitEvent(WUDF_EVENT param_1,ulong param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (param_2 == 0xffffffff) {
    plVar2 = (longlong *)0x0;
  }
  else {
    plVar2 = local_res18;
    local_res18[0] = -(ulonglong)(param_2 * 10000);
  }
  iVar1 = KeWaitForSingleObject(param_1.Value,0,0,0,plVar2);
  return iVar1 == 0;
}



===== WudfAllocateEvent @ 14000e8c4 =====

WUDF_EVENT __cdecl WdfPlatformEvent::WudfAllocateEvent(_EVENT_TYPE param_1,ulong param_2)

{
  void *pvVar1;
  undefined7 in_register_00000009;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,0x18,0x7e444d55);
  if (pvVar1 != (void *)0x0) {
    KeInitializeEvent(pvVar1,CONCAT71(in_register_00000009,param_1) & 0xffffffff,0);
  }
  return (WUDF_EVENT)pvVar1;
}



===== WudfSetEvent @ 14000e91c =====

void __cdecl WdfPlatformEvent::WudfSetEvent(WUDF_EVENT param_1)

{
  KeSetEvent(param_1.Value,0,0);
  return;
}



===== operator_delete @ 14000e940 =====

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== WudfAllocateSecurityDescriptor @ 14000e964 =====

void * __cdecl WdfPlatformSecurity::WudfAllocateSecurityDescriptor(void **param_1,ulong param_2)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar5 = 0x10;
  for (uVar6 = 0; (uint)uVar6 < param_2; uVar6 = (ulonglong)((uint)uVar6 + 1)) {
    iVar2 = RtlLengthSid(param_1[uVar6]);
    uVar4 = iVar2 + 0xc + uVar5;
    if (uVar4 < uVar5) {
      return (void *)0x0;
    }
    uVar5 = uVar4;
  }
  pvVar3 = (void *)ExAllocatePool2(0x40,(ulonglong)uVar5 + 0x28,0x32444d55);
  if (pvVar3 != (void *)0x0) {
    lVar1 = (longlong)pvVar3 + 0x28;
    iVar2 = RtlCreateAcl(lVar1,uVar5,2);
    if (-1 < iVar2) {
      for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1) {
        iVar2 = RtlAddAccessAllowedAce(lVar1,2,0x10000000);
        if (iVar2 < 0) goto LAB_14000ea56;
      }
      iVar2 = RtlCreateSecurityDescriptor(pvVar3,1);
      if ((-1 < iVar2) && (iVar2 = RtlSetDaclSecurityDescriptor(pvVar3,1,lVar1,0), -1 < iVar2)) {
        return pvVar3;
      }
    }
LAB_14000ea56:
    operator_delete(pvVar3);
  }
  return (void *)0x0;
}



===== WudfAllocateWellKnownSid @ 14000ea84 =====

void * __cdecl WdfPlatformSecurity::WudfAllocateWellKnownSid(WELL_KNOWN_SID_TYPE param_1)

{
  int iVar1;
  undefined7 in_register_00000009;
  
  iVar1 = (int)CONCAT71(in_register_00000009,param_1);
  if (iVar1 == 0x16) {
    return *(void **)(*(longlong *)SeExports_exref + 0x108);
  }
  if (iVar1 == 0x17) {
    return *(void **)(*(longlong *)SeExports_exref + 0x180);
  }
  return (void *)0x0;
}



===== WudfFreeSid @ 14000eac0 =====

void __cdecl WdfPlatformSecurity::WudfFreeSid(void *param_1)

{
  if ((param_1 != *(void **)(*(longlong *)SeExports_exref + 0x180)) &&
     (param_1 != *(void **)(*(longlong *)SeExports_exref + 0x108))) {
    operator_delete(param_1);
  }
  return;
}



===== AddRef @ 14000eb00 =====

ulong __thiscall WdfLpcInterface::AddRef(WdfLpcInterface *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::AddRef((CUMDFUnknown *)this);
  return uVar1;
}



===== AddRef`adjustor{16}' @ 14000eb20 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCorePortInterface::AddRef`adjustor{16}'
   (void) __ptr64 */

ulong __thiscall WdfLpcCorePortInterface::AddRef_adjustor_16__(WdfLpcCorePortInterface *this)

{
  ulong uVar1;
  
  uVar1 = WdfLpcInterface::AddRef((WdfLpcInterface *)&this[-1].field_0x20);
  return uVar1;
}



===== GetPeriodicTimer @ 14000eb30 =====

long __thiscall
WdfLpcInterface::GetPeriodicTimer
          (WdfLpcInterface *this,IUMDFPeriodicTimer **param_1,ulong param_2,_IO_OBJECT *param_3)

{
  WudfPeriodicTimer *pWVar1;
  long lVar2;
  
  lVar2 = 0;
  *param_1 = (IUMDFPeriodicTimer *)0x0;
  pWVar1 = WudfPeriodicTimer::WudfCreatePeriodicTimer(param_2,param_3);
  if (pWVar1 == (WudfPeriodicTimer *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x12,
              WPP_02695a365c923798242d82f859d29eea_Traceguids);
    }
    lVar2 = -0x3fffffff;
  }
  else {
    *param_1 = (IUMDFPeriodicTimer *)&pWVar1->_padding_;
  }
  return lVar2;
}



===== GetPeriodicTimerCallbackPacket @ 14000ebb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcInterface::GetPeriodicTimerCallbackPacket
          (WdfLpcInterface *this,IUMDFPeriodicTimerCallbackPacket **param_1,
          _func___cdecl_void_void_ptr *param_2,void *param_3)

{
  long lVar1;
  IUMDFPeriodicTimerCallbackPacket *pIVar2;
  WudfPeriodicTimerCallbackPacket *local_res10;
  
  pIVar2 = (IUMDFPeriodicTimerCallbackPacket *)0x0;
  *param_1 = (IUMDFPeriodicTimerCallbackPacket *)0x0;
  local_res10 = (WudfPeriodicTimerCallbackPacket *)0x0;
  lVar1 = WudfPeriodicTimerCallbackPacket::s_CreateInstance(&local_res10,param_2,param_3);
  if (lVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
              WPP_02695a365c923798242d82f859d29eea_Traceguids);
    }
    if (local_res10 != (WudfPeriodicTimerCallbackPacket *)0x0) {
      (**(code **)(local_res10->_padding_ + 8))();
    }
  }
  else {
    if (local_res10 != (WudfPeriodicTimerCallbackPacket *)0x0) {
      pIVar2 = (IUMDFPeriodicTimerCallbackPacket *)&local_res10->_padding_;
    }
    *param_1 = pIVar2;
  }
  return lVar1;
}



===== QueryInterface`adjustor{16}' @ 14000ec70 =====

/* [thunk]:public: virtual long __cdecl WdfLpc::QueryInterface`adjustor{16}' (struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall WdfLpc::QueryInterface_adjustor_16__(WdfLpc *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = CUMDFUnknown::QueryInterface((CUMDFUnknown *)&this[-1].m_Owner,param_1,param_2);
  return lVar1;
}



===== Release`adjustor{16}' @ 14000ec80 =====

/* [thunk]:public: virtual unsigned long __cdecl
   WudfPeriodicTimerCallbackPacket::Release`adjustor{16}' (void) __ptr64 */

ulong __thiscall
WudfPeriodicTimerCallbackPacket::Release_adjustor_16__(WudfPeriodicTimerCallbackPacket *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::Release((CUMDFUnknown *)&this[-1].m_Callback);
  return uVar1;
}



===== WdfCreateHostProcessLpcObjectDirectory @ 14000ec90 =====

long __thiscall
WdfLpcInterface::WdfCreateHostProcessLpcObjectDirectory
          (WdfLpcInterface *this,wchar_t *param_1,void **param_2)

{
  return 0;
}



===== WdfGetLpc @ 14000eca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcInterface::WdfGetLpc
          (WdfLpcInterface *this,IUMDFLPC **param_1,WdfComponentType param_2,
          IUMDFPeriodicTimer *param_3)

{
  WdfLpc *pWVar1;
  uint uVar2;
  IUMDFLPC *pIVar3;
  
  pWVar1 = (WdfLpc *)ExAllocatePool2(0x40);
  pIVar3 = (IUMDFLPC *)0x0;
  if (pWVar1 != (WdfLpc *)0x0) {
    pWVar1 = WdfLpc::WdfLpc(pWVar1,param_2,
                            (WudfPeriodicTimer *)
                            (-(ulonglong)(param_3 != (IUMDFPeriodicTimer *)0x0) &
                            (ulonglong)(param_3 + -6)));
    if (pWVar1 != (WdfLpc *)0x0) {
      uVar2 = (uint)pWVar1->_padding_;
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xc,
                   WPP_02695a365c923798242d82f859d29eea_Traceguids,uVar2);
        }
        (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
      }
      else {
        pIVar3 = (IUMDFLPC *)&pWVar1->_padding_;
      }
      goto LAB_14000ed9e;
    }
  }
  if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xb,
            WPP_02695a365c923798242d82f859d29eea_Traceguids);
  }
  uVar2 = 0xc0000017;
LAB_14000ed9e:
  *param_1 = pIVar3;
  return uVar2;
}



===== WdfGetLpcPortBaseName @ 14000edc0 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

wchar_t * __thiscall
WdfLpcInterface::WdfGetLpcPortBaseName(WdfLpcInterface *this,WdfComponentType param_1)

{
  int iVar1;
  uint uVar2;
  undefined7 in_register_00000011;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  iVar1 = (int)CONCAT71(in_register_00000011,param_1);
  if (iVar1 != 2) {
    uVar2 = iVar1 - 3;
    if (uVar2 != 0) {
      if (uVar2 == 1) {
        return L"\\UMDFCommunicationPorts\\WUDF";
      }
      WudfVerifyStatic((WdfComponentType)this,
                       (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                       (ulonglong)uVar2,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcinterface.cpp",in_R9D,
                       in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8
                       ,in_stack_ffffffffffffffe0,"unexpected UMDF component",false);
      return (wchar_t *)0x0;
    }
  }
  return L"\\UMDFCommunicationPorts";
}



===== WdfGetLpcReply @ 14000ee20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcInterface::WdfGetLpcReply
          (WdfLpcInterface *this,IUMDFLPCReply **param_1,IUMDFLPCPortInterface *param_2,
          ulong64 param_3,ulong param_4,uchar param_5)

{
  uint uVar1;
  WudfLpcReplyMessage *pWVar2;
  IUMDFLPCReply *pIVar3;
  WdfLpcPort *local_res18 [2];
  
  pIVar3 = (IUMDFLPCReply *)0x0;
  local_res18[0] = (WdfLpcPort *)0x0;
  uVar1 = (**(code **)((longlong)*param_2 + 0x10))(param_2,&IID_WdfLpcPort,local_res18);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xf,
               WPP_02695a365c923798242d82f859d29eea_Traceguids,param_2);
    }
  }
  else {
    pWVar2 = (WudfLpcReplyMessage *)ExAllocatePool2(0x40,0x88,0x43444d55);
    if (pWVar2 != (WudfLpcReplyMessage *)0x0) {
      pWVar2 = WudfLpcReplyMessage::WudfLpcReplyMessage
                         (pWVar2,local_res18[0],param_3,param_4,param_5);
      if (pWVar2 != (WudfLpcReplyMessage *)0x0) {
        uVar1 = (uint)pWVar2->_padding_;
        if ((int)uVar1 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x11,
                     WPP_02695a365c923798242d82f859d29eea_Traceguids,uVar1);
          }
          (**(code **)(pWVar2->_padding_ + 8))(pWVar2);
        }
        else {
          pIVar3 = (IUMDFLPCReply *)&pWVar2->_padding_;
        }
        goto LAB_14000ef9d;
      }
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x10,
              WPP_02695a365c923798242d82f859d29eea_Traceguids);
    }
    uVar1 = 0xc0000017;
  }
LAB_14000ef9d:
  *param_1 = pIVar3;
  return uVar1;
}



===== WdfGetProcessManagementName @ 14000efc0 =====

wchar_t * __thiscall WdfLpcInterface::WdfGetProcessManagementName(WdfLpcInterface *this)

{
  return L"\\UMDFCommunicationPorts\\ProcessManagement";
}



===== WdfLpcInterfaceCreateInstance @ 14000efd0 =====

long __cdecl WdfLpcInterface::WdfLpcInterfaceCreateInstance(WdfLpcInterface **param_1)

{
  long lVar1;
  WdfLpcInterface *pWVar2;
  
  pWVar2 = (WdfLpcInterface *)ExAllocatePool2(0x40,0x18,0x45444d55);
  lVar1 = 0;
  if (pWVar2 == (WdfLpcInterface *)0x0) {
    pWVar2 = (WdfLpcInterface *)0x0;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),10,
              WPP_02695a365c923798242d82f859d29eea_Traceguids);
    }
    lVar1 = -0x3fffffff;
  }
  else {
    *(undefined8 *)&pWVar2->field_0x8 = 1;
    *(undefined ***)pWVar2 = &WudfPeriodicTimerCallbackPacket::_vftable__for__CUMDFUnknown__;
    *(undefined ***)&pWVar2->field_0x10 = &_vftable__for__IUMDFLPCInterface__;
  }
  *param_1 = pWVar2;
  return lVar1;
}



===== WudfPeriodicTimer @ 14000f07c =====

WudfPeriodicTimer * __thiscall
WudfPeriodicTimer::WudfPeriodicTimer(WudfPeriodicTimer *this,ulong param_1,_IO_OBJECT *param_2)

{
  void *pvVar1;
  WUDF_EVENT WVar2;
  ulong uVar3;
  int iVar4;
  
  WudfPlatformTimer::WudfPlatformTimer((WudfPlatformTimer *)this,param_2);
  this->m_Generation = 0;
  this->m_Head = (WudfPeriodicTimerCallbackPacket *)0x0;
  (this->m_Timer).Value = (void *)0x0;
  (this->m_WorkItemEvent).Value = (void *)0x0;
  iVar4 = (int)this->_padding_;
  this->_padding_ = (longlong)&_vftable__for__WudfPlatformTimer__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFPeriodicTimer__;
  if (-1 < iVar4) {
    pvVar1 = (void *)ExAllocatePool2(0x40,0x90,0x33444d55);
    if (pvVar1 == (void *)0x0) {
      (this->m_Timer).Value = (void *)0x0;
      iVar4 = -0x3fffffff;
    }
    else {
      memset();
      KeInitializeTimerEx(pvVar1,0);
      uVar3 = 0x4000e850;
      KeInitializeDpc((longlong)pvVar1 + 0x40,TimerDPC,pvVar1);
      (this->m_Timer).Value = pvVar1;
      WVar2 = WdfPlatformEvent::WudfAllocateEvent(NotificationEvent,uVar3);
      (this->m_WorkItemEvent).Value = WVar2.Value;
      if (WVar2.Value != (void *)0x0) {
        WdfPlatformEvent::WudfSetEvent(WVar2);
        this->m_TimerPeriod = 1000;
        (this->m_TimerFirstPeriod).QuadPart = (ulonglong)param_1 * -10000000;
        return this;
      }
      iVar4 = -0x3fffffe9;
    }
  }
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,iVar4);
  return this;
}



===== ~WudfPeriodicTimer @ 14000f198 =====

void __thiscall WudfPeriodicTimer::~WudfPeriodicTimer(WudfPeriodicTimer *this)

{
  void *pvVar1;
  
  this->_padding_ = (longlong)&_vftable__for__WudfPlatformTimer__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFPeriodicTimer__;
  pvVar1 = (this->m_WorkItemEvent).Value;
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  pvVar1 = (this->m_Timer).Value;
  if (pvVar1 != (void *)0x0) {
    operator_delete(pvVar1);
  }
  WudfPlatformTimer::~WudfPlatformTimer((WudfPlatformTimer *)this);
  return;
}



===== `scalar_deleting_destructor' @ 14000f1f0 =====

void * __thiscall
WudfPeriodicTimer::_scalar_deleting_destructor_(WudfPeriodicTimer *this,uint param_1)

{
  ~WudfPeriodicTimer(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AddRef`adjustor{48}' @ 14000f230 =====

/* [thunk]:public: virtual unsigned long __cdecl WudfPeriodicTimer::AddRef`adjustor{48}' (void)
   __ptr64 */

ulong __thiscall WudfPeriodicTimer::AddRef_adjustor_48__(WudfPeriodicTimer *this)

{
  ulong uVar1;
  
  uVar1 = WdfLpcInterface::AddRef((WdfLpcInterface *)&this[-1].m_Generation);
  return uVar1;
}



===== FlushQueuedCallbackPacket @ 14000f240 =====

void __thiscall WudfPeriodicTimer::FlushQueuedCallbackPacket(WudfPeriodicTimer *this)

{
  KeFlushQueuedDpcs();
  WdfPlatformWait::WaitEvent((void *)this->_padding_,0xffffffff);
  return;
}



===== InstallCallbackPacket @ 14000f270 =====

void __thiscall
WudfPeriodicTimer::InstallCallbackPacket
          (WudfPeriodicTimer *this,IUMDFPeriodicTimerCallbackPacket *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  uVar1 = *(undefined8 *)&this[-1].m_TimerPeriod;
  uVar5 = -(ulonglong)(param_1 != (IUMDFPeriodicTimerCallbackPacket *)0x0) &
          (ulonglong)(param_1 + -2);
  KeEnterCriticalRegion(this,-(longlong)param_1);
  ExAcquireResourceExclusiveLite(uVar1,1);
  if (this->_padding_ == 0) {
    lVar2 = this->_padding_;
    lVar4 = this->_padding_;
    lVar3 = this->_padding_;
    *(code **)(lVar2 + 0x80) = PlatformTimerDpc;
    *(ulong **)(lVar2 + 0x88) = &this[-1].m_Generation;
    KeSetTimerEx(lVar2,lVar3,(int)lVar4,lVar2 + 0x40);
  }
  *(int *)(uVar5 + 0x1c) = (int)this->_padding_;
  *(longlong *)(uVar5 + 0x20) = this->_padding_;
  uVar1 = *(undefined8 *)&this[-1].m_TimerPeriod;
  this->_padding_ = uVar5;
  ExReleaseResourceLite(uVar1);
  KeLeaveCriticalRegion();
  return;
}



===== PlatformTimerDpc @ 14000f340 =====

void __cdecl WudfPeriodicTimer::PlatformTimerDpc(void *param_1)

{
  uchar uVar1;
  
  uVar1 = WdfPlatformWait::WaitEvent((WUDF_EVENT)*(void **)((longlong)param_1 + 0x48),0);
  if (uVar1 == '\x01') {
    KeClearEvent(*(undefined8 *)((longlong)param_1 + 0x48));
    IoQueueWorkItem(*(undefined8 *)((longlong)param_1 + 0x28),_WorkItemRoutine,1,param_1);
  }
  return;
}



===== QueryInterface`adjustor{48}' @ 14000f3a0 =====

/* [thunk]:public: virtual long __cdecl WudfPeriodicTimer::QueryInterface`adjustor{48}' (struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WudfPeriodicTimer::QueryInterface_adjustor_48__
          (WudfPeriodicTimer *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = CUMDFUnknown::QueryInterface((CUMDFUnknown *)&this[-1].m_Generation,param_1,param_2);
  return lVar1;
}



===== Release`adjustor{48}' @ 14000f3b0 =====

/* [thunk]:public: virtual unsigned long __cdecl WudfPeriodicTimer::Release`adjustor{48}' (void)
   __ptr64 */

ulong __thiscall WudfPeriodicTimer::Release_adjustor_48__(WudfPeriodicTimer *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::Release((CUMDFUnknown *)&this[-1].m_Generation);
  return uVar1;
}



===== UninstallCallbackPacket @ 14000f3c0 =====

void __thiscall
WudfPeriodicTimer::UninstallCallbackPacket
          (WudfPeriodicTimer *this,IUMDFPeriodicTimerCallbackPacket *param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar1 = *(undefined8 *)&this[-1].m_TimerPeriod;
  uVar5 = -(ulonglong)(param_1 != (IUMDFPeriodicTimerCallbackPacket *)0x0) &
          (ulonglong)(param_1 + -2);
  KeEnterCriticalRegion(this,-(longlong)param_1);
  ExAcquireResourceExclusiveLite(uVar1,1);
  uVar4 = this->_padding_;
  if (uVar4 == uVar5) {
    this->_padding_ = *(longlong *)(uVar5 + 0x20);
  }
  else {
    uVar2 = *(ulonglong *)(uVar4 + 0x20);
    while (uVar3 = uVar2, uVar3 != uVar5) {
      uVar4 = uVar3;
      uVar2 = *(ulonglong *)(uVar3 + 0x20);
    }
    *(undefined8 *)(uVar4 + 0x20) = *(undefined8 *)(uVar5 + 0x20);
  }
  *(undefined8 *)(uVar5 + 0x20) = 0;
  if (this->_padding_ == 0) {
    KeCancelTimer(this->_padding_);
  }
  ExReleaseResourceLite(*(undefined8 *)&this[-1].m_TimerPeriod);
  KeLeaveCriticalRegion();
  return;
}



===== WorkItemRoutine @ 14000f47c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall WudfPeriodicTimer::WorkItemRoutine(WudfPeriodicTimer *this)

{
  longlong lVar1;
  WudfPeriodicTimerCallbackPacket *pWVar2;
  void *pvVar3;
  _func___cdecl_void_void_ptr *p_Var4;
  
  this->m_Generation = this->m_Generation + 1;
  do {
    lVar1 = this->_padding_;
    p_Var4 = (_func___cdecl_void_void_ptr *)0x0;
    pvVar3 = (void *)0x0;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1,1);
    for (pWVar2 = this->m_Head; pWVar2 != (WudfPeriodicTimerCallbackPacket *)0x0;
        pWVar2 = pWVar2->m_Next) {
      if (pWVar2->m_Generation < this->m_Generation) {
        p_Var4 = pWVar2->m_Callback;
        pvVar3 = pWVar2->m_Context;
        pWVar2->m_Generation = this->m_Generation;
        break;
      }
    }
    ExReleaseResourceLite(this->_padding_);
    KeLeaveCriticalRegion();
    if (p_Var4 == (_func___cdecl_void_void_ptr *)0x0) {
      WdfPlatformEvent::WudfSetEvent((WUDF_EVENT)(this->m_WorkItemEvent).Value);
      return;
    }
    (*p_Var4)(pvVar3);
  } while( true );
}



===== WudfCreatePeriodicTimer @ 14000f530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WudfPeriodicTimer * __cdecl
WudfPeriodicTimer::WudfCreatePeriodicTimer(ulong param_1,_IO_OBJECT *param_2)

{
  WudfPeriodicTimer *pWVar1;
  
  pWVar1 = (WudfPeriodicTimer *)ExAllocatePool2(0x40,0x68,0x23444d55);
  if ((pWVar1 != (WudfPeriodicTimer *)0x0) &&
     (pWVar1 = WudfPeriodicTimer(pWVar1,param_1,param_2), pWVar1 != (WudfPeriodicTimer *)0x0)) {
    if (-1 < (int)pWVar1->_padding_) {
      return pWVar1;
    }
    (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
  }
  return (WudfPeriodicTimer *)0x0;
}



===== _WorkItemRoutine @ 14000f5a0 =====

void __cdecl WudfPeriodicTimer::_WorkItemRoutine(_DEVICE_OBJECT *param_1,void *param_2)

{
  WorkItemRoutine(param_2);
  return;
}



===== s_CreateInstance @ 14000f5b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WudfPeriodicTimerCallbackPacket::s_CreateInstance
          (WudfPeriodicTimerCallbackPacket **param_1,_func___cdecl_void_void_ptr *param_2,
          void *param_3)

{
  WudfPeriodicTimerCallbackPacket *pWVar1;
  int iVar2;
  
  *param_1 = (WudfPeriodicTimerCallbackPacket *)0x0;
  pWVar1 = (WudfPeriodicTimerCallbackPacket *)ExAllocatePool2(0x40,0x38,0x24444d55);
  if (pWVar1 == (WudfPeriodicTimerCallbackPacket *)0x0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    pWVar1->_padding_ = 0;
    pWVar1->m_Generation = 0;
    pWVar1->m_Next = (WudfPeriodicTimerCallbackPacket *)0x0;
    *(undefined4 *)&pWVar1->_padding_ = 1;
    pWVar1->_padding_ = (longlong)&_vftable__for__CUMDFUnknown__;
    pWVar1->_padding_ = (longlong)&_vftable__for__IUMDFPeriodicTimerCallbackPacket__;
    pWVar1->m_Callback = param_2;
    pWVar1->m_Context = param_3;
    iVar2 = pWVar1->_padding_;
    if (iVar2 < 0) {
      (**(code **)(pWVar1->_padding_ + 8))();
    }
    else {
      *param_1 = pWVar1;
    }
  }
  return iVar2;
}



===== WdfLpc @ 14000f660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpc * __thiscall WdfLpc::WdfLpc(WdfLpc *this,WdfComponentType param_1,WudfPeriodicTimer *param_2)

{
  longlong *this_00;
  WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *this_01;
  WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this_02;
  WudfPeriodicTimer *pWVar1;
  ushort uVar2;
  undefined7 in_register_00000011;
  uint uVar3;
  WdfLpcCorePortInterface *local_res8;
  
  *(undefined4 *)&this->_padding_ = 1;
  this_00 = &this->_padding_;
  this->_padding_ = (longlong)&___7CUMDFUnknown__6B_;
  WdfObjectLock::WdfObjectLock((WdfObjectLock *)this_00);
  this->_padding_ = (longlong)&_vftable__for__CUMDFUnknown__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPC__;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),10,
             WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_2);
  }
  *(int *)&this->m_Owner = (int)CONCAT71(in_register_00000011,param_1);
  uVar3 = (uint)*this_00;
  this->m_ConnPortList = (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0;
  this->m_CommPortList = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0;
  this->m_LpcNotification = (LpcNotification *)0x0;
  this->m_PeriodicTimer = (WudfPeriodicTimer *)0x0;
  this->m_LpcCorePortInterface = (IUMDFLPCCorePortInterface *)0x0;
  if ((int)uVar3 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14000fa05;
    uVar2 = 0xb;
  }
  else {
    local_res8 = (WdfLpcCorePortInterface *)0x0;
    WdfLpcCorePortInterface::s_CreateInstance(&local_res8);
    if (local_res8 == (WdfLpcCorePortInterface *)0x0) {
      this->m_LpcCorePortInterface = (IUMDFLPCCorePortInterface *)0x0;
    }
    else {
      this->m_LpcCorePortInterface = (IUMDFLPCCorePortInterface *)&local_res8->field_0x10;
      if (&local_res8->field_0x10 != (undefined1 *)0x0) {
        this_01 = (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)ExAllocatePool2(0x40);
        if (this_01 == (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0) {
          this->m_ConnPortList = (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            uVar2 = 0xe;
LAB_14000f9b0:
            WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar2,
                    WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
          }
        }
        else {
          WdfObject::WdfObject
                    ((WdfObject *)this_01,L"ListObjectNoName",(WdfObject *)0x0,'\0',RdTypeObject);
          this_01->m_List = (WdfObject *)0x0;
          this_01->_padding_ =
               (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
          this_01->m_NextUniqueObjectId = 1;
          this_01->m_Tag = 0x65444d55;
          this_01->m_PoolFlags = 0x40;
          this->m_ConnPortList = this_01;
          uVar3 = (uint)this_01->_padding_;
          if ((int)uVar3 < 0) {
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
              WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xf,
                      WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
            }
            WdfObject::ReleaseWait((WdfObject *)this->m_ConnPortList,10000);
            this->m_ConnPortList = (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0;
            goto LAB_14000fa05;
          }
          this_02 = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)
                    ExAllocatePool2(0x40,0x78);
          if (this_02 != (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
            WdfObject::WdfObject
                      ((WdfObject *)this_02,L"ListObjectNoName",(WdfObject *)0x0,'\0',RdTypeObject);
            this_02->m_List = (WdfObject *)0x0;
            this_02->_padding_ =
                 (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
            this_02->m_NextUniqueObjectId = 1;
            this_02->m_Tag = 0x65444d55;
            this_02->m_PoolFlags = 0x40;
            this->m_CommPortList = this_02;
            uVar3 = (uint)this_02->_padding_;
            if ((int)uVar3 < 0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x11,
                        WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
              }
              WdfObject::ReleaseWait((WdfObject *)this->m_CommPortList,10000);
              this->m_CommPortList = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0;
            }
            else if (param_2 == (WudfPeriodicTimer *)0x0) {
              pWVar1 = WudfPeriodicTimer::WudfCreatePeriodicTimer(1,(_IO_OBJECT *)0x0);
              this->m_PeriodicTimer = pWVar1;
              if (pWVar1 == (WudfPeriodicTimer *)0x0) {
                uVar3 = 0xc0000017;
                if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
                   (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                  WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x12,
                          WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
                }
              }
            }
            else {
              this->m_PeriodicTimer = param_2;
              (**(code **)param_2->_padding_)(param_2);
            }
            goto LAB_14000fa05;
          }
          this->m_CommPortList = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            uVar2 = 0x10;
            goto LAB_14000f9b0;
          }
        }
        uVar3 = 0xc0000017;
        goto LAB_14000fa05;
      }
    }
    uVar3 = 0xc0000017;
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14000fa05;
    uVar2 = 0xc;
  }
  WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar2,
           WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,uVar3);
LAB_14000fa05:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)this_00,uVar3);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
            WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
  }
  return this;
}



===== ~WdfLpc @ 14000fa68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall WdfLpc::~WdfLpc(WdfLpc *this)

{
  WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *pWVar1;
  longlong lVar2;
  WdfLpcCommPort *pWVar3;
  WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this_00;
  WdfObject *in_RDX;
  WdfObject *pWVar4;
  
  this->_padding_ = (longlong)&_vftable__for__CUMDFUnknown__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPC__;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    in_RDX = (WdfObject *)0x14;
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x14,
            WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
  }
  this_00 = this->m_CommPortList;
  if (this_00 != (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
    while( true ) {
      pWVar3 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::EnumFirst(this_00,in_RDX);
      if (pWVar3 == (WdfLpcCommPort *)0x0) break;
      ExReleaseResourceLite(this->m_CommPortList->_padding_);
      KeLeaveCriticalRegion();
      (**(code **)(pWVar3->_padding_ + 0x28))(pWVar3);
      (**(code **)(pWVar3->_padding_ + 8))(pWVar3);
      this_00 = this->m_CommPortList;
    }
    ExReleaseResourceLite();
    KeLeaveCriticalRegion();
  }
  if (this->m_ConnPortList == (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0) {
LAB_14000fbf6:
    if (this->m_CommPortList != (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
      WdfObject::ReleaseWait((WdfObject *)this->m_CommPortList,10000);
    }
    if (this->m_ConnPortList != (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0) {
      WdfObject::ReleaseWait((WdfObject *)this->m_ConnPortList,10000);
    }
    if (this->m_PeriodicTimer != (WudfPeriodicTimer *)0x0) {
      (**(code **)(this->m_PeriodicTimer->_padding_ + 8))();
    }
    operator_delete(this->m_LpcNotification);
    if (this->m_LpcCorePortInterface != (IUMDFLPCCorePortInterface *)0x0) {
      (**(code **)((longlong)*this->m_LpcCorePortInterface + 8))();
    }
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x15,
              WPP_3490e8082f90373e38fddadd87fb393b_Traceguids);
    }
    WdfObjectLock::~WdfObjectLock((WdfObjectLock *)&this->_padding_);
    CUMDFUnknown::~CUMDFUnknown((CUMDFUnknown *)this);
    return;
  }
  do {
    pWVar1 = this->m_ConnPortList;
    lVar2 = pWVar1->_padding_;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar2,1);
    pWVar4 = (WdfObject *)0x0;
    do {
      if (pWVar4 == (WdfObject *)0x0) {
        pWVar4 = pWVar1->m_List;
      }
      else {
        pWVar4 = pWVar4->m_Next;
      }
      if (pWVar4 == (WdfObject *)0x0) {
        ExReleaseResourceLite(this->m_ConnPortList->_padding_);
        KeLeaveCriticalRegion();
        goto LAB_14000fbf6;
      }
    } while (pWVar4->m_MarkedForDelete != '\0');
    ExReleaseResourceLite(this->m_ConnPortList->_padding_);
    KeLeaveCriticalRegion();
    (**(code **)(pWVar4->_padding_ + 0x28))(pWVar4);
    (**(code **)(pWVar4->_padding_ + 8))(pWVar4);
  } while( true );
}



===== `scalar_deleting_destructor' @ 14000fcc0 =====

void * __thiscall WdfLpc::_scalar_deleting_destructor_(WdfLpc *this,uint param_1)

{
  ~WdfLpc(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== Connect @ 14000fcf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpc::Connect(WdfLpc *this,WdfLpcCommPortParameters *param_1,WdfLpcCommPort **param_2)

{
  WdfLpcCommPort *pWVar1;
  uint uVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  pWVar1 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::CreateNew
                     (this->m_CommPortList,param_1,(long *)local_res8);
  uVar2 = local_res8[0];
  if ((int)local_res8[0] < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1a,
               WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,local_res8[0]);
    }
    if (pWVar1 != (WdfLpcCommPort *)0x0) {
      (**(code **)(pWVar1->_padding_ + 0x28))(pWVar1);
      (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
      pWVar1 = (WdfLpcCommPort *)0x0;
    }
  }
  else {
    uVar2 = 0;
  }
  *param_2 = pWVar1;
  return uVar2;
}



===== Connect @ 14000fdb0 =====

long __thiscall
WdfLpc::Connect(WdfLpc *this,wchar_t *param_1,IUMDFLPCNotification *param_2,void *param_3,
               void *param_4,_IO_OBJECT *param_5,WUDF_LPC_CLIENT_IDENTIFIER param_6,ulong64 param_7,
               IUMDFLPCCommPortInterface **param_8)

{
  long lVar1;
  IUMDFLPCCommPortInterface *pIVar2;
  WdfLpcCommPort *local_res8;
  undefined3 in_stack_00000039;
  WdfLpcCommPortParameters local_68;
  
  local_68._padding_._0_4_ = *(undefined4 *)&this->m_PeriodicTimer;
  local_68._padding_ = (longlong)&this[-1].m_Owner;
  pIVar2 = (IUMDFLPCCommPortInterface *)0x0;
  local_68._padding_ = param_7;
  local_68.m_ServerSid = param_4;
  local_68.m_IoObject = param_5;
  local_68.m_ClientIdentifier = param_6;
  local_68._81_3_ = in_stack_00000039;
  local_res8 = (WdfLpcCommPort *)0x0;
  local_68._padding_ = 0;
  local_68.m_AsyncConnect = '\0';
  local_68.m_ServerSideCommPort = '\0';
  local_68._padding_ = (longlong)param_1;
  local_68._padding_ = (longlong)param_2;
  local_68.m_PeerProcessId = param_3;
  lVar1 = Connect((WdfLpc *)local_68._padding_,&local_68,&local_res8);
  if (lVar1 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_Sd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x19,
                WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_1,lVar1);
    }
  }
  else {
    if (local_res8 != (WdfLpcCommPort *)0x0) {
      pIVar2 = (IUMDFLPCCommPortInterface *)&local_res8->_padding_;
    }
    *param_8 = pIVar2;
  }
  return lVar1;
}



===== CreateNew @ 14000feac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcCommPort * __thiscall
WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::CreateNew
          (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this,
          WdfLpcCommPortParameters *param_1,long *param_2)

{
  WdfLpcCommPort *pWVar1;
  int iVar2;
  
  iVar2 = -0x3fffff66;
  pWVar1 = (WdfLpcCommPort *)ExAllocatePool2(0x40,0x110,0x65444d55);
  if (pWVar1 != (WdfLpcCommPort *)0x0) {
    pWVar1 = WdfLpcCommPort::WdfLpcCommPort(pWVar1,param_1,this,(WdfObject *)this);
    if ((pWVar1 == (WdfLpcCommPort *)0x0) || (iVar2 = (int)pWVar1->_padding_, -1 < iVar2))
    goto LAB_14000ff2f;
    (**(code **)(pWVar1->_padding_ + 0x28))(pWVar1);
    (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
  }
  pWVar1 = (WdfLpcCommPort *)0x0;
LAB_14000ff2f:
  if (param_2 != (long *)0x0) {
    *param_2 = iVar2;
  }
  return pWVar1;
}



===== EnumFirst @ 14000ff54 =====

WdfLpcCommPort * __thiscall
WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::EnumFirst
          (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this,WdfObject *param_1)

{
  longlong lVar1;
  WdfLpcCommPort *pWVar2;
  
  lVar1 = this->_padding_;
  KeEnterCriticalRegion(this,(char)param_1);
  ExAcquireResourceExclusiveLite(lVar1,1);
  pWVar2 = (WdfLpcCommPort *)0x0;
  do {
    if (pWVar2 == (WdfLpcCommPort *)0x0) {
      pWVar2 = (WdfLpcCommPort *)this->m_List;
    }
    else {
      pWVar2 = (WdfLpcCommPort *)pWVar2->_padding_;
    }
  } while ((pWVar2 != (WdfLpcCommPort *)0x0) && ((char)pWVar2->_padding_ != '\0'));
  return pWVar2;
}



===== Find @ 14000ffb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcConnPort * __thiscall
WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters>::Find
          (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *this,
          WdfLpcConnPortParameters *param_1,uchar param_2,uchar param_3,uchar *param_4,long *param_5
          )

{
  longlong lVar1;
  WdfLpcConnPort *pWVar2;
  code *pcVar3;
  WdfLpcConnPort *pWVar4;
  uchar uVar5;
  undefined7 in_register_00000081;
  undefined7 in_register_00000089;
  
  lVar1 = this->_padding_;
  uVar5 = '\0';
  KeEnterCriticalRegion
            (this,param_1,CONCAT71(in_register_00000081,param_2),
             CONCAT71(in_register_00000089,param_3));
  ExAcquireResourceExclusiveLite(lVar1,1);
  pWVar2 = (WdfLpcConnPort *)this->m_List;
  pWVar4 = pWVar2;
  if (pWVar2 == (WdfLpcConnPort *)0x0) {
LAB_140010028:
    pWVar2 = (WdfLpcConnPort *)ExAllocatePool2(this->m_PoolFlags,200,this->m_Tag);
    if (pWVar2 == (WdfLpcConnPort *)0x0) goto LAB_14001008b;
    pWVar2 = WdfLpcConnPort::WdfLpcConnPort(pWVar2,param_1,this,(WdfObject *)this);
    if (pWVar2 == (WdfLpcConnPort *)0x0) goto LAB_14001008b;
    if (-1 < (int)pWVar2->_padding_) {
      uVar5 = '\x01';
      pWVar4 = pWVar2;
      goto LAB_14001008b;
    }
    (**(code **)(pWVar2->_padding_ + 0x28))(pWVar2);
    pcVar3 = *(code **)(pWVar2->_padding_ + 8);
  }
  else {
    do {
      if (((pWVar2->_padding_ != 0) && (param_1->_padding_ == pWVar2->_padding_)) &&
         ((char)pWVar2->_padding_ == '\0')) break;
      pWVar2 = (WdfLpcConnPort *)pWVar2->_padding_;
    } while (pWVar2 != (WdfLpcConnPort *)0x0);
    pWVar4 = pWVar2;
    if (pWVar2 == (WdfLpcConnPort *)0x0) goto LAB_140010028;
    pcVar3 = *(code **)pWVar2->_padding_;
  }
  (*pcVar3)(pWVar2);
LAB_14001008b:
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if (param_4 != (uchar *)0x0) {
    *param_4 = uVar5;
  }
  return pWVar4;
}



===== Listen @ 1400100e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

IUMDFLPCConnPortInterface * __thiscall
WdfLpc::Listen(WdfLpc *this,wchar_t *param_1,IUMDFLPCNotification *param_2,void **param_3,
              ulong param_4,uchar param_5,ulong64 param_6)

{
  WdfLpcConnPort *pWVar1;
  uchar local_res8 [8];
  long *in_stack_ffffffffffffffa0;
  WdfLpcConnPortParameters local_58;
  
  local_58._padding_ = 0;
  local_58._padding_ = (longlong)&this[-1].m_Owner;
  local_58._padding_._0_4_ = *(undefined4 *)&this->m_PeriodicTimer;
  local_58._padding_ = param_6;
  local_58.m_CommPortList =
       (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)this->_padding_;
  local_58.m_NumServerSIDs = param_4;
  local_58.m_ByPassProcessIdCheck = param_5;
  local_res8[0] = '\0';
  local_58._padding_ = (longlong)param_1;
  local_58._padding_ = (longlong)param_2;
  local_58.m_ServerSIDTable = param_3;
  pWVar1 = WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters>::Find
                     ((WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)this->_padding_,
                      &local_58,(uchar)param_2,(uchar)param_3,local_res8,in_stack_ffffffffffffffa0);
  if (pWVar1 == (WdfLpcConnPort *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_S(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x16,
               WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_1);
    }
  }
  else if (local_res8[0] == '\0') {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_S(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x17,
               WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,(wchar_t *)pWVar1->_padding_);
    }
    (**(code **)(pWVar1->_padding_ + 8))(pWVar1);
    pWVar1 = (WdfLpcConnPort *)0x0;
  }
  return (IUMDFLPCConnPortInterface *)
         (-(ulonglong)(pWVar1 != (WdfLpcConnPort *)0x0) & (ulonglong)&pWVar1->_padding_);
}



===== ValidateMessage @ 140010220 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

uchar __cdecl WdfLpc::ValidateMessage(_WUDFMESSAGE_HEADER *param_1,ulong64 param_2)

{
  _WUDFMESSAGE _Var1;
  WPP_PROJECT_CONTROL_BLOCK *pWVar2;
  uint uVar3;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var4;
  uint uVar5;
  bool bVar6;
  _WUDFMESSAGE_HEADER *in_R9;
  char *in_stack_ffffffffffffffc8;
  uint uVar7;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  pWVar2 = WPP_GLOBAL_Control;
  p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)param_2;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    pWVar2 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1c;
    in_R9 = param_1;
    in_stack_ffffffffffffffc8 = (char *)param_2;
    WPP_SF_qq((ulong64)pWVar2,0x1c,WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_1,
              (void *)param_2);
  }
  bVar6 = false;
  uVar5 = (uint)param_2;
  uVar7 = (uint)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  if (param_2 == 0) {
    pWVar2 = WPP_GLOBAL_Control;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      pWVar2 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
      p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1d;
      in_stack_ffffffffffffffc8 = (char *)((ulonglong)uVar7 << 0x20);
      WPP_SF_qd((ulong64)pWVar2,0x1d,WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_1,0);
      in_R9 = param_1;
    }
  }
  else {
    _Var1 = param_1->Message;
    p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)(ulonglong)_Var1;
    uVar3 = (uint)_Var1;
    if (_Var1 < WudfMsg_Max) {
      in_R9 = (_WUDFMESSAGE_HEADER *)((ulonglong)uVar3 * 0x20);
      if (param_2 < *(ulonglong *)(in_R9 + 0x14001c120)) {
        pWVar2 = WPP_GLOBAL_Control;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0)) ||
           (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 3)) goto LAB_1400103c6;
        in_stack_ffffffffffffffd8 = *(WdfErrorClass *)(in_R9 + 0x14001c120);
        p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1f;
      }
      else {
        if (param_2 <= *(ulonglong *)(in_R9 + 0x14001c128)) {
          bVar6 = true;
          goto LAB_1400103c6;
        }
        pWVar2 = WPP_GLOBAL_Control;
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0)) ||
           (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 3)) goto LAB_1400103c6;
        in_stack_ffffffffffffffd8 = *(WdfErrorClass *)(in_R9 + 0x14001c128);
        p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x20;
      }
      pWVar2 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
      in_stack_ffffffffffffffc8 = (char *)CONCAT44(uVar7,uVar3);
      WPP_SF_qDDD((ulong64)pWVar2,(ushort)p_Var4,(_GUID *)(ulonglong)uVar3,param_1,uVar3,uVar5,
                  in_stack_ffffffffffffffd8);
      in_stack_ffffffffffffffd0 = (WdfDriverStopType)uVar5;
      in_R9 = param_1;
    }
    else {
      pWVar2 = WPP_GLOBAL_Control;
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        pWVar2 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
        in_R9 = (_WUDFMESSAGE_HEADER *)(ulonglong)uVar3;
        p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1e;
        WPP_SF_D((ulong64)pWVar2,0x1e,WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,uVar3);
      }
    }
  }
LAB_1400103c6:
  WudfVerifyStatic((WdfComponentType)pWVar2,p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpc.cpp",(ulong)in_R9,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"TODO: Write something interesting here",bVar6);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x21,
             WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,(uint)bVar6);
  }
  return bVar6;
}



===== ValidateReplyMessage @ 140010440 =====

uchar __thiscall
WdfLpc::ValidateReplyMessage
          (WdfLpc *this,_WUDFMESSAGE_REPLY_HEADER *param_1,_WUDFMESSAGE param_2,ulong64 param_3)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  undefined7 in_register_00000081;
  _GUID *p_Var4;
  uint uVar5;
  
  p_Var4 = (_GUID *)CONCAT71(in_register_00000081,param_2);
  uVar3 = (uint)param_2;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    WPP_SF_qLq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),(ushort)param_1,p_Var4,param_1,
               uVar3,(void *)param_3);
  }
  bVar2 = 0;
  if (WudfMsg_Custom_Event < param_2) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return '\0';
    }
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x23,
               WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,uVar3);
    }
    goto LAB_140010621;
  }
  if (param_3 < 4) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return '\0';
    }
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 3)) goto LAB_140010621;
    uVar1 = 0x24;
    uVar5 = 4;
  }
  else {
    if (param_1->NtStatus == 0x103) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return '\0';
      }
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x25,
                 WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,0x103);
      }
      goto LAB_140010621;
    }
    if (param_3 < WudfMessageSizeTable[param_2].MinOutputMessageSize) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return '\0';
      }
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 3)) goto LAB_140010621;
      uVar5 = (uint)WudfMessageSizeTable[param_2].MinOutputMessageSize;
      uVar1 = 0x26;
    }
    else {
      if (param_3 <= WudfMessageSizeTable[param_2].MaxOutputMessageSize) {
        bVar2 = 1;
        goto LAB_140010621;
      }
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return '\0';
      }
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) == 0) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 3)) goto LAB_140010621;
      uVar5 = (uint)WudfMessageSizeTable[param_2].MaxOutputMessageSize;
      uVar1 = 0x27;
    }
  }
  WPP_SF_qDDD(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar1,p_Var4,param_1,uVar3,
              (uint)param_3,uVar5);
LAB_140010621:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000008) == 0x80000008)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x28,
             WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,(uint)bVar2);
  }
  return bVar2;
}



===== WPP_SF_qDDD @ 14001067c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qDDD(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,uint param_5,uint param_6,
           uint param_7)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,param_2);
  return;
}



===== WPP_SF_qLq @ 1400106f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qLq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,ulong param_5,void *param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_3490e8082f90373e38fddadd87fb393b_Traceguids,0x22);
  return;
}



===== WudfLpcReplyMessage @ 140010758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

WudfLpcReplyMessage * __thiscall
WudfLpcReplyMessage::WudfLpcReplyMessage
          (WudfLpcReplyMessage *this,WdfLpcPort *param_1,ulong64 param_2,ulong param_3,uchar param_4
          )

{
  ulonglong uVar1;
  ulong *puVar2;
  IUMDFLPCCorePortInterface *pIVar3;
  uint uVar4;
  _ALPC_MESSAGE_ATTRIBUTES *p_Var5;
  undefined4 *puVar6;
  _PORT_MESSAGE *p_Var7;
  WPP_PROJECT_CONTROL_BLOCK *pWVar8;
  ushort uVar9;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var10;
  WdfLpcPort *pWVar11;
  ulong uVar12;
  WdfLpcPort *pWVar13;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffffa8;
  char *pcVar14;
  WdfDriverStopType in_stack_ffffffffffffffb0;
  WdfErrorClass in_stack_ffffffffffffffb8;
  ulong in_stack_ffffffffffffffc0;
  
  pcVar14 = (char *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffffa8 >> 8),0x10);
  uVar12 = 0;
  pWVar11 = param_1;
  WdfObject::WdfObject((WdfObject *)this,L"ReplyMessage",(WdfObject *)param_1,'\0',RdTypeObject);
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCReply__;
  local_res8 = 0;
  p_Var10 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x80000080;
  pWVar8 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar8 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    in_stack_ffffffffffffffb8 = (WdfErrorClass)param_4;
    pWVar13 = param_1;
    pcVar14 = (char *)param_2;
    uVar12 = param_3;
    WPP_SF_qPdl((ulong64)pWVar8,0x80,(_GUID *)pWVar11,param_1,param_2,param_3,
                in_stack_ffffffffffffffb8);
    in_stack_ffffffffffffffb0 = (WdfDriverStopType)uVar12;
    uVar12 = (ulong)pWVar13;
  }
  WudfVerifyStatic((WdfComponentType)pWVar8,p_Var10,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar12,pcVar14,
                   in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                   "TODO: Write something interesting here",param_2 != 0);
  this->m_LpcPort = param_1;
  this->m_MessageAttrib = (_ALPC_MESSAGE_ATTRIBUTES *)0x0;
  this->m_AlpcMessageHeader = (_PORT_MESSAGE *)0x0;
  this->m_Context = (void *)0x0;
  this->m_MaxMessageBodyLength = param_2;
  pIVar3 = param_1->m_LpcCorePortInterface;
  uVar4 = (uint)this->_padding_;
  if ((int)uVar4 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140010ba7;
    uVar9 = 0xb;
LAB_140010882:
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar9,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar4);
    goto LAB_140010ba7;
  }
  uVar1 = param_2 + 0x28;
  if ((uVar1 < 0x28) || (uVar1 < param_2)) {
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0' &&
        (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xc,
              WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
    }
  }
  else {
    if (uVar1 < 0x10000) {
      if (param_4 == '\0') {
LAB_140010ab6:
        p_Var7 = (_PORT_MESSAGE *)ExAllocatePool2(0x40,uVar1,0x68444d55);
        this->m_AlpcMessageHeader = p_Var7;
        if (p_Var7 != (_PORT_MESSAGE *)0x0) {
          (p_Var7->u1).Length = 0;
          (p_Var7->u2).ZeroInit = 0;
          (p_Var7->field2_0x8).ClientId.UniqueProcess = (void *)0x0;
          (p_Var7->field2_0x8).ClientId.UniqueThread = (void *)0x0;
          *(undefined8 *)&p_Var7->MessageId = 0;
          (p_Var7->field4_0x20).ClientViewSize = 0;
          (this->m_AlpcMessageHeader->u1).s1.DataLength = (short)this->m_MaxMessageBodyLength;
          (this->m_AlpcMessageHeader->u1).s1.TotalLength = (short)uVar1;
          this->m_AlpcMessageHeader->MessageId = param_3;
          goto LAB_140010ba7;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x11,
                   WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,(uint)uVar1);
        }
      }
      else {
        uVar4 = (**(code **)((longlong)*pIVar3 + 0x30))(pIVar3,0x40000000,0,0,&local_res8);
        if (uVar4 != 0xc0000023) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xe,
                     WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar4);
          }
          if (-1 < (int)uVar4) {
            uVar4 = 0xc00000e5;
          }
          goto LAB_140010ba7;
        }
        p_Var5 = (_ALPC_MESSAGE_ATTRIBUTES *)ExAllocatePool2(0x40,local_res8,0x67444d55);
        this->m_MessageAttrib = p_Var5;
        if (p_Var5 != (_ALPC_MESSAGE_ATTRIBUTES *)0x0) {
          memset();
          uVar4 = (**(code **)((longlong)*pIVar3 + 0x30))
                            (pIVar3,0x40000000,this->m_MessageAttrib,local_res8,&local_res8);
          if ((int)uVar4 < 0) {
            if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
               (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140010ba7;
            uVar9 = 0x10;
            goto LAB_140010882;
          }
          puVar2 = &this->m_MessageAttrib->ValidAttributes;
          *puVar2 = *puVar2 | 0x40000000;
          puVar6 = (undefined4 *)AlpcGetMessageAttribute(this->m_MessageAttrib,0x40000000);
          *puVar6 = 0x10000;
          goto LAB_140010ab6;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xf,
                  WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
        }
      }
      uVar4 = 0xc0000017;
      goto LAB_140010ba7;
    }
    pWVar8 = WPP_GLOBAL_Control;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      pWVar8 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
      p_Var10 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0xd;
      uVar12 = (ulong)param_2;
      WPP_SF_D((ulong64)pWVar8,0xd,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar12);
    }
    WudfVerifyStatic((WdfComponentType)pWVar8,p_Var10,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar12,pcVar14,
                     in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                     "TODO: Write something interesting here",false);
  }
  uVar4 = 0xc000000d;
LAB_140010ba7:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar4);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x12,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  return this;
}



===== ~WudfLpcReplyMessage @ 140010c10 =====

void __thiscall WudfLpcReplyMessage::~WudfLpcReplyMessage(WudfLpcReplyMessage *this)

{
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCReply__;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  operator_delete(this->m_AlpcMessageHeader);
  operator_delete(this->m_MessageAttrib);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x14,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140010ce0 =====

void * __thiscall
WudfLpcReplyMessage::_scalar_deleting_destructor_(WudfLpcReplyMessage *this,uint param_1)

{
  ~WudfLpcReplyMessage(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AddRef`adjustor{88}' @ 140010d20 =====

/* [thunk]:public: virtual unsigned long __cdecl WudfLpcMessage::AddRef`adjustor{88}' (void) __ptr64
    */

ulong __thiscall WudfLpcMessage::AddRef_adjustor_88__(WudfLpcMessage *this)

{
  ulong uVar1;
  
  uVar1 = WdfLpcInterface::AddRef((WdfLpcInterface *)&this[-1].m_ReplyMessageExtendTimeout);
  return uVar1;
}



===== CopyMessageData @ 140010d30 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall
WudfLpcMessage::CopyMessageData
          (WudfLpcMessage *this,void *param_1,ulong64 param_2,ulong64 param_3,uchar param_4)

{
  uint uVar1;
  longlong lVar2;
  WdfComponentType WVar3;
  WPP_PROJECT_CONTROL_BLOCK *pWVar4;
  ulong uVar5;
  void *pvVar6;
  char *in_stack_ffffffffffffffb8;
  WdfDriverStopType in_stack_ffffffffffffffc0;
  WdfErrorClass in_stack_ffffffffffffffc8;
  ulong in_stack_ffffffffffffffd0;
  
  pWVar4 = WPP_GLOBAL_Control;
  pvVar6 = (void *)param_3;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar4 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    uVar1 = (uint)param_4;
    pvVar6 = param_1;
    in_stack_ffffffffffffffb8 = (char *)param_2;
    WPP_SF_qPl((ulong64)pWVar4,(ushort)param_1,(_GUID *)param_2,param_1,param_2,uVar1);
    in_stack_ffffffffffffffc0 = (WdfDriverStopType)uVar1;
  }
  WVar3 = (WdfComponentType)pWVar4;
  uVar5 = (ulong)pvVar6;
  if (param_4 == '\0') {
    WudfVerifyStatic(WVar3,param_1,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar5
                     ,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                     in_stack_ffffffffffffffd0,"TODO: Write something interesting here",
                     param_3 < (ulonglong)this->_padding_);
    lVar2 = this->_padding_;
  }
  else {
    WudfVerifyStatic(WVar3,param_1,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar5
                     ,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                     in_stack_ffffffffffffffd0,"TODO: Write something interesting here",
                     param_3 < (ulonglong)this->_padding_);
    lVar2 = this->_padding_;
  }
  WudfVerifyStatic(WVar3,param_1,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar5,
                   in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                   in_stack_ffffffffffffffd0,"TODO: Write something interesting here",
                   param_2 <= lVar2 - param_3);
  AlpcGetMessageAttribute((this->m_ReplyCallbackLock).Value,0x40000000);
  memcpy();
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x4a,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  return;
}



===== ExtendTimeout @ 140010ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall WudfLpcMessage::ExtendTimeout(WudfLpcMessage *this,ulong *param_1)

{
  uint uVar1;
  
  if (this->m_ReplyMessageExtendTimeout ==
      (_func___cdecl_long_IUMDFLPCMessage_ptr_void_ptr_ulong_ptr *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x4c,
              WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
    }
    uVar1 = 0xc0000001;
  }
  else {
    uVar1 = (*this->m_ReplyMessageExtendTimeout)
                      ((IUMDFLPCMessage *)
                       (-(ulonglong)(this != (WudfLpcMessage *)0x0) & (ulonglong)&this->_padding_),
                       this->m_ReplyContext,param_1);
    if ((((int)uVar1 < 0) &&
        (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
       (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0' &&
        (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x4b,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar1);
    }
  }
  return uVar1;
}



===== GetContext @ 140010f70 =====

void * __thiscall WudfLpcReplyMessage::GetContext(WudfLpcReplyMessage *this)

{
  return (void *)this->_padding_;
}



===== GetMessageDataLength @ 140010f80 =====

ulong64 __thiscall WudfLpcMessage::GetMessageDataLength(WudfLpcMessage *this)

{
  return this->_padding_;
}



===== GetMessageReplyDataLength @ 140010f90 =====

ulong64 __thiscall WudfLpcMessage::GetMessageReplyDataLength(WudfLpcMessage *this)

{
  return this->_padding_;
}



===== GetReplyContextLocked @ 140010fa0 =====

void * __thiscall WudfLpcMessage::GetReplyContextLocked(WudfLpcMessage *this,void *param_1)

{
  ValidateLockTicket((WudfLpcMessage *)&this[-1].m_ReplyMessageExtendTimeout,param_1);
  return (void *)this->_padding_;
}



===== LockPendingMessage @ 140010fc4 =====

void * __thiscall WudfLpcMessage::LockPendingMessage(WudfLpcMessage *this)

{
  bool *pbVar1;
  
  pbVar1 = &this->m_ReplyReceived;
  if (*pbVar1 == false) {
    WdfPlatformWait::WaitEvent((WUDF_EVENT)(this->m_ReplyCallbackLock).Value,0xffffffff);
    if (*pbVar1 == false) {
      return pbVar1;
    }
    WdfPlatformEvent::WudfSetEvent((WUDF_EVENT)(this->m_ReplyCallbackLock).Value);
  }
  return (void *)0x0;
}



===== MessageBody @ 140011010 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void * __thiscall WudfLpcReplyMessage::MessageBody(WudfLpcReplyMessage *this,ulong64 param_1)

{
  WPP_PROJECT_CONTROL_BLOCK *pWVar1;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var2;
  void *pvVar3;
  _GUID *in_R8;
  ulong in_R9D;
  ulong64 uVar4;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  pWVar1 = WPP_GLOBAL_Control;
  p_Var2 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)param_1;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar1 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    p_Var2 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1a;
    uVar4 = param_1;
    WPP_SF_P((ulong64)pWVar1,0x1a,in_R8,param_1);
    in_R9D = (ulong)uVar4;
  }
  WudfVerifyStatic((WdfComponentType)pWVar1,p_Var2,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"TODO: Write something interesting here",
                   param_1 <= (ulonglong)this->_padding_);
  if ((ulonglong)this->_padding_ < param_1) {
    pvVar3 = (void *)0x0;
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return (void *)0x0;
    }
    if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1b,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,&this[-1]._padding_);
    }
  }
  else {
    *(short *)this->_padding_ = (short)param_1;
    *(short *)(this->_padding_ + 2) = (short)param_1 + 0x28;
    pvVar3 = (void *)(this->_padding_ + 0x28);
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1c,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,pvVar3);
  }
  return pvVar3;
}



===== QueryInterface`adjustor{88}' @ 140011140 =====

/* [thunk]:public: virtual long __cdecl WudfLpcMessage::QueryInterface`adjustor{88}' (struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WudfLpcMessage::QueryInterface_adjustor_88__(WudfLpcMessage *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = CUMDFUnknown::QueryInterface
                    ((CUMDFUnknown *)&this[-1].m_ReplyMessageExtendTimeout,param_1,param_2);
  return lVar1;
}



===== Release`adjustor{88}' @ 140011150 =====

/* [thunk]:public: virtual unsigned long __cdecl WudfLpcReplyMessage::Release`adjustor{88}' (void)
   __ptr64 */

ulong __thiscall WudfLpcReplyMessage::Release_adjustor_88__(WudfLpcReplyMessage *this)

{
  ulong uVar1;
  
  uVar1 = WudfLpcMessage::Release((WudfLpcMessage *)&this[-1]._padding_);
  return uVar1;
}



===== Reply @ 140011160 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

long __thiscall
WudfLpcReplyMessage::Reply(WudfLpcReplyMessage *this,ulong param_1,IUMDFLPCPortInterface *param_2)

{
  bool bVar1;
  uint uVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  undefined4 in_register_00000014;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var4;
  ulong in_R9D;
  longlong *local_res8;
  undefined4 in_stack_ffffffffffffffa8;
  undefined4 in_stack_ffffffffffffffac;
  WdfDriverStopType in_stack_ffffffffffffffb0;
  WdfErrorClass in_stack_ffffffffffffffb8;
  ulong in_stack_ffffffffffffffc0;
  
  p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
           CONCAT44(in_register_00000014,param_1);
  local_res8 = (longlong *)0x0;
  pWVar3 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x15;
    in_R9D = param_1;
    WPP_SF_D((ulong64)pWVar3,0x15,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_1);
  }
  if ((*(int *)(this->_padding_ + 0x18) == 0) && (param_1 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  WudfVerifyStatic((WdfComponentType)pWVar3,p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",in_R9D,
                   (char *)CONCAT44(in_stack_ffffffffffffffac,in_stack_ffffffffffffffa8),
                   in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                   "TODO: Write something interesting here",bVar1);
  *(undefined2 *)(this->_padding_ + 4) = 2;
  if (param_1 != 0) {
    *(ulong *)(this->_padding_ + 0x18) = param_1;
  }
  if (*(int *)(this->_padding_ + 0x18) == 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x16,
              WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
    }
    uVar2 = 0xc000000d;
  }
  else {
    if (param_2 == (IUMDFLPCPortInterface *)0x0) {
      local_res8 = (longlong *)this->_padding_;
    }
    else {
      uVar2 = (**(code **)((longlong)*param_2 + 0x10))(param_2,&IID_WdfLpcPort,&local_res8);
      if ((int)uVar2 < 0) {
        if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
          return uVar2;
        }
        if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x17,
                   WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_2);
        }
        goto LAB_14001133d;
      }
    }
    uVar2 = (**(code **)(*local_res8 + 0x38))
                      (local_res8,0x10000,this->_padding_,this->_padding_,0,0);
    if ((int)uVar2 < 0) {
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return uVar2;
      }
      if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x18,
                 WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar2);
      }
    }
  }
LAB_14001133d:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x19,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  return uVar2;
}



===== ReplyMessage @ 140011390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall
WudfLpcMessage::ReplyMessage
          (WudfLpcMessage *this,_WUDFMESSAGE_REPLY_HEADER *param_1,ulong64 param_2,
          WUDF_PROBLEM *param_3)

{
  longlong *plVar1;
  void *pvVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  _WUDFMESSAGE_REPLY_HEADER *p_Var4;
  wchar_t *pwVar5;
  ulong uVar6;
  WUDF_PROBLEM *pWVar7;
  char *in_stack_ffffffffffffffa8;
  WdfDriverStopType in_stack_ffffffffffffffb0;
  WdfErrorClass in_stack_ffffffffffffffb8;
  ulong in_stack_ffffffffffffffc0;
  
  pWVar3 = WPP_GLOBAL_Control;
  p_Var4 = param_1;
  pWVar7 = param_3;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    pWVar7 = (WUDF_PROBLEM *)param_1;
    in_stack_ffffffffffffffa8 = (char *)param_2;
    WPP_SF_qP((ulong64)pWVar3,(ushort)param_1,(_GUID *)param_2,param_1,param_2);
  }
  uVar6 = (ulong)pWVar7;
  WudfVerifyStatic((WdfComponentType)pWVar3,
                   (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                   in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,
                   in_stack_ffffffffffffffc0,"reply message too small",3 < param_2);
  pvVar2 = LockPendingMessage(this);
  pwVar5 = L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp";
  WudfVerifyStatic(pvVar2 != (void *)0x0,
                   (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                   in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,in_stack_ffffffffffffffb8,
                   in_stack_ffffffffffffffc0,
                   "Message has not been replied to yet (or it wouldn\'t still exist) and so the lock operation should not fail"
                   ,pvVar2 != (void *)0x0);
  plVar1 = &this->_padding_;
  this->m_ReplyReceived = true;
  (**(code **)(*plVar1 + 0x40))(plVar1,pvVar2);
  if (param_2 < 4) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return;
    }
    if (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0') &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_P(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x47,(_GUID *)pwVar5,param_2);
    }
  }
  else if (this->m_ReplyMessageCall !=
           (_func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
            *)0x0) {
    (*this->m_ReplyMessageCall)
              ((IUMDFLPCMessage *)(-(ulonglong)(this != (WudfLpcMessage *)0x0) & (ulonglong)plVar1),
               this->m_ReplyContext,param_1,param_2,param_3);
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x48,
            WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids);
  }
  return;
}



===== Send @ 140011520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

long __thiscall
WudfLpcMessage::Send
          (WudfLpcMessage *this,
          _func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
          *param_1,void *param_2,ulong param_3,
          _func___cdecl_long_IUMDFLPCMessage_ptr_void_ptr_ulong_ptr *param_4)

{
  longlong lVar1;
  uint uVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  ushort uVar4;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var5;
  ulong uVar6;
  _func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
  *p_Var7;
  WdfDriverStopType WVar8;
  char *in_stack_ffffffffffffffb8;
  char *pcVar9;
  WdfDriverStopType in_stack_ffffffffffffffc0;
  WdfDriverStopType WVar10;
  WdfErrorClass in_stack_ffffffffffffffc8;
  ulong in_stack_ffffffffffffffd0;
  
  p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x80000080;
  uVar6 = param_3;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x39;
    p_Var7 = param_1;
    in_stack_ffffffffffffffb8 = param_2;
    WPP_SF_qqd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x39,
               WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_1,param_2,param_3);
    in_stack_ffffffffffffffc0 = (WdfDriverStopType)uVar6;
    uVar6 = (ulong)p_Var7;
  }
  if (param_3 == 0) {
    WudfVerifyStatic(WdfComponentPlatform,p_Var5,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                     in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                     in_stack_ffffffffffffffd0,
                     "ExtendTimeout callback not allowed when no timeout is specified",
                     param_4 == (_func___cdecl_long_IUMDFLPCMessage_ptr_void_ptr_ulong_ptr *)0x0);
  }
  *(bool *)((longlong)&this->_padding_ + 5) = param_3 != 0;
  this->_padding_ = (longlong)param_4;
  this->_padding_ = (longlong)param_1;
  this->_padding_ = (longlong)param_2;
  if (this->_padding_ == 0) {
    WVar8 = WdfInternalError;
    if (param_1 ==
        (_func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
         *)0x0) {
      if ((param_3 == 0) &&
         (param_4 == (_func___cdecl_long_IUMDFLPCMessage_ptr_void_ptr_ulong_ptr *)0x0))
      goto LAB_1400116d4;
      uVar2 = 0xc000000d;
      WudfVerifyStatic(WdfComponentPlatform,p_Var5,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                       in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8
                       ,in_stack_ffffffffffffffd0,"TODO: Write something interesting here",false);
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_1400117be;
      uVar4 = 0x3c;
    }
    else {
      uVar2 = 0xc000000d;
      WudfVerifyStatic(WdfComponentPlatform,p_Var5,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                       in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8
                       ,in_stack_ffffffffffffffd0,"TODO: Write something interesting here",false);
      if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        return -0x3ffffff3;
      }
      if ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_1400117be;
      uVar4 = 0x3b;
    }
  }
  else {
    WVar8 = WdfDriverError;
    if (param_1 !=
        (_func___cdecl_void_IUMDFLPCMessage_ptr_void_ptr__WUDFMESSAGE_REPLY_HEADER_ptr_ulong64_WUDF_PROBLEM_ptr
         *)0x0) {
LAB_1400116d4:
      *(undefined1 *)&this->_padding_ = 0;
      *(undefined2 *)(this->_padding_ + 4) = 1;
      lVar1 = this->_padding_;
      *(undefined4 *)(lVar1 + 0x18) = *(undefined4 *)&this->m_ReplyReceived;
      WudfVerifyStatic((WdfComponentType)lVar1,p_Var5,
                       L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                       in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8
                       ,in_stack_ffffffffffffffd0,"TODO: Write something interesting here",
                       *(int *)(this->_padding_ + 0x18) != 0);
      if (this->_padding_ == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (ulong)(this->m_ReplyCallbackLock).Value;
      }
      p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x0;
      pcVar9 = (char *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),param_3);
      WVar10 = WVar8;
      uVar2 = (**(code **)(*(longlong *)this->_padding_ + 0x38))
                        ((longlong *)this->_padding_,0,this->_padding_);
      if ((int)uVar2 < 0) {
        pWVar3 = WPP_GLOBAL_Control;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                      (ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec),
            (char)*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
          p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x3d;
          uVar6 = uVar2;
          WPP_SF_D((ulong64)pWVar3,0x3d,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar2);
        }
        WudfVerifyStatic((WdfComponentType)pWVar3,p_Var5,
                         L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,pcVar9,
                         WVar10,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                         "ALPC should never fail here",uVar2 != 0xc000009a);
      }
      else if (WVar8 == WdfInternalError) {
        (**(code **)(this[-1].m_ReplyMessageExtendTimeout + 8))();
      }
      goto LAB_1400117be;
    }
    uVar2 = 0xc000000d;
    WudfVerifyStatic(WdfComponentPlatform,p_Var5,
                     L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcmsg.cpp",uVar6,
                     in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,
                     in_stack_ffffffffffffffd0,"TODO: Write something interesting here",false);
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_1400117be;
    uVar4 = 0x3a;
  }
  uVar2 = 0xc000000d;
  WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar4,
           WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,&this[-1].m_ReplyMessageExtendTimeout);
LAB_1400117be:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000080) == 0x80000080)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x3e,
             WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,uVar2);
  }
  return uVar2;
}



===== SetContext @ 140011870 =====

void __thiscall WudfLpcReplyMessage::SetContext(WudfLpcReplyMessage *this,void *param_1)

{
  this->_padding_ = (longlong)param_1;
  return;
}



===== SetMessageID @ 140011880 =====

void __thiscall WudfLpcReplyMessage::SetMessageID(WudfLpcReplyMessage *this,ulong param_1)

{
  *(ulong *)(this->_padding_ + 0x18) = param_1;
  return;
}



===== UnlockPendingMessage @ 140011890 =====

void __thiscall WudfLpcMessage::UnlockPendingMessage(WudfLpcMessage *this,void *param_1)

{
  ValidateLockTicket((WudfLpcMessage *)&this[-1].m_ReplyMessageExtendTimeout,param_1);
  WdfPlatformEvent::WudfSetEvent((void *)this->_padding_);
  return;
}



===== ValidateLockTicket @ 1400118b8 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WudfLpcMessage::ValidateLockTicket(WudfLpcMessage *this,void *param_1)

{
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  WudfVerifyStatic((WdfComponentType)this,param_1,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\wdflpc.hpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,
                   "LockTicket is NULL or does not match expected value for this message",
                   param_1 == &this->m_ReplyReceived);
  return;
}



===== WPP_SF_IId @ 1400118f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_IId(ulong64 param_1,ushort param_2,_GUID *param_3,ulong64 param_4,ulong64 param_5,int param_6
          )

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_2);
  return;
}



===== WPP_SF_P @ 140011958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_P(ulong64 param_1,ushort param_2,_GUID *param_3,ulong64 param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_2);
  return;
}



===== WPP_SF_PP @ 1400119a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_PP(ulong64 param_1,ushort param_2,_GUID *param_3,ulong64 param_4,ulong64 param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x35);
  return;
}



===== WPP_SF_PPP @ 1400119f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_PPP(ulong64 param_1,ushort param_2,_GUID *param_3,ulong64 param_4,ulong64 param_5,
          ulong64 param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x2e);
  return;
}



===== WPP_SF_i @ 140011a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_i(ulong64 param_1,ushort param_2,_GUID *param_3,long64 param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x3f);
  return;
}



===== WPP_SF_ii @ 140011aac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_ii(ulong64 param_1,ushort param_2,_GUID *param_3,long64 param_4,long64 param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,param_2);
  return;
}



===== WPP_SF_qP @ 140011b04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_qP(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,ulong64 param_5)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x46);
  return;
}



===== WPP_SF_qPdl @ 140011b5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qPdl(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,ulong64 param_5,int param_6,
           long param_7)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,10);
  return;
}



===== WPP_SF_qPl @ 140011bd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qPl(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,ulong64 param_5,long param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x49);
  return;
}



===== WPP_SF_qqqPP @ 140011c38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqqPP(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,void *param_6
            ,ulong64 param_7,ulong64 param_8)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_b077cd04021d3bd0469f0776139c14ca_Traceguids,0x25);
  return;
}



===== WudfPlatformTimer @ 140011cbc =====

WudfPlatformTimer * __thiscall
WudfPlatformTimer::WudfPlatformTimer(WudfPlatformTimer *this,_IO_OBJECT *param_1)

{
  longlong *this_00;
  _IO_WORKITEM *p_Var1;
  int iVar2;
  
  this_00 = &this->_padding_;
  WdfObjectLock::WdfObjectLock((WdfObjectLock *)this_00);
  this->m_WorkItem = (_IO_WORKITEM *)0x0;
  iVar2 = (int)*this_00;
  this->_padding_ = (longlong)&___7WudfPlatformTimer__6B_;
  *(undefined4 *)&this->_padding_ = 1;
  if (-1 < iVar2) {
    if (param_1 == (_IO_OBJECT *)0x0) {
      iVar2 = -0x3ffffff3;
    }
    else {
      p_Var1 = (_IO_WORKITEM *)IoAllocateWorkItem(param_1->DeviceObject);
      this->m_WorkItem = p_Var1;
      if (p_Var1 == (_IO_WORKITEM *)0x0) {
        iVar2 = -0x3fffffe9;
      }
    }
  }
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)this_00,iVar2);
  return this;
}



===== ~WudfPlatformTimer @ 140011d54 =====

void __thiscall WudfPlatformTimer::~WudfPlatformTimer(WudfPlatformTimer *this)

{
  this->_padding_ = (longlong)&___7WudfPlatformTimer__6B_;
  if (this->m_WorkItem != (_IO_WORKITEM *)0x0) {
    IoFreeWorkItem();
  }
  CUMDFUnknown::~CUMDFUnknown((CUMDFUnknown *)this);
  WdfObjectLock::~WdfObjectLock((WdfObjectLock *)&this->_padding_);
  return;
}



===== `scalar_deleting_destructor' @ 140011da0 =====

void * __thiscall
WudfPlatformTimer::_scalar_deleting_destructor_(WudfPlatformTimer *this,uint param_1)

{
  ~WudfPlatformTimer(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ReferenceNext @ 140011dd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcConnPort * __thiscall
WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters>::ReferenceNext
          (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *this,ulong *param_1)

{
  ulong uVar1;
  uint uVar2;
  longlong lVar3;
  WdfLpcConnPort *pWVar4;
  WdfLpcConnPort *pWVar5;
  
  uVar1 = *param_1;
  lVar3 = this->_padding_;
  pWVar5 = (WdfLpcConnPort *)0x0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar3,1);
  for (pWVar4 = (WdfLpcConnPort *)this->m_List; pWVar4 != (WdfLpcConnPort *)0x0;
      pWVar4 = (WdfLpcConnPort *)pWVar4->_padding_) {
    if ((char)pWVar4->_padding_ == '\0') {
      uVar2 = (uint)pWVar4->_padding_;
      if (uVar1 + 1 <= uVar2) {
        if (uVar2 == uVar1 + 1) goto LAB_140011e4e;
        if (pWVar5 == (WdfLpcConnPort *)0x0) {
          pWVar5 = pWVar4;
        }
        else if (uVar2 < (uint)pWVar5->_padding_) {
          pWVar5 = pWVar4;
        }
      }
    }
  }
  pWVar4 = pWVar5;
  if (pWVar5 != (WdfLpcConnPort *)0x0) {
LAB_140011e4e:
    (**(code **)pWVar4->_padding_)(pWVar4);
    *param_1 = (ulong)pWVar4->_padding_;
    pWVar5 = pWVar4;
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  return pWVar5;
}



===== RetrieveMessage @ 140011ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfLpc::RetrieveMessage(WdfLpc *this)

{
  int iVar1;
  WdfLpcConnPort *pWVar2;
  WdfComponentType WVar3;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var4;
  WdfLpcConnPort *in_R9;
  undefined1 auStackY_178 [32];
  void **in_stack_fffffffffffffea8;
  undefined4 uVar5;
  WdfDriverStopType in_stack_fffffffffffffeb0;
  WdfErrorClass in_stack_fffffffffffffeb8;
  ulong in_stack_fffffffffffffec0;
  ulong local_128 [2];
  WdfLpcConnPort local_120;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_178;
  local_128[0] = 0;
  pWVar2 = WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters>::ReferenceNext
                     ((WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)this->_padding_,
                      local_128);
  while (pWVar2 != (WdfLpcConnPort *)0x0) {
    p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x0;
    WVar3 = (char)&local_120 + 8;
    memset();
    local_120._padding_ = 0;
    WudfVerifyStatic(WVar3,p_Var4,L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpc_xp.cpp",
                     (ulong)in_R9,(char *)in_stack_fffffffffffffea8,in_stack_fffffffffffffeb0,
                     in_stack_fffffffffffffeb8,in_stack_fffffffffffffec0,
                     "Kernel-mode implementation of UMDF IPC should not allocate IPC message on stack."
                     ,false);
    if (pWVar2->_padding_ == 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        in_R9 = pWVar2;
        WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xc,
                 WPP_05ad225c8b3436afbba871c0ee702dc8_Traceguids,pWVar2);
      }
    }
    else {
      local_120.ClientProcessList._4_4_ = 0;
      in_R9 = &local_120;
      local_120.ClientProcessList._0_4_ = 0xe0000000;
      local_120._padding_ = 0x98;
      in_stack_fffffffffffffea8 = &local_120.ClientProcessList;
      iVar1 = (**(code **)((longlong)*this->m_LpcNotification + 0x40))
                        (this->m_LpcNotification,pWVar2->_padding_,&local_120._padding_);
      uVar5 = (undefined4)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
      if (iVar1 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          in_R9 = (WdfLpcConnPort *)pWVar2->_padding_;
          in_stack_fffffffffffffea8 = (void **)CONCAT44(uVar5,iVar1);
          WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xb,
                    WPP_05ad225c8b3436afbba871c0ee702dc8_Traceguids,in_R9,iVar1);
        }
      }
      else {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 8) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          in_R9 = (WdfLpcConnPort *)pWVar2->_padding_;
          in_stack_fffffffffffffea8 =
               (void **)(CONCAT44(uVar5,(uint)local_120._padding_._4_2_) & 0xffffffffffff00ff);
          WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),10,
                    WPP_05ad225c8b3436afbba871c0ee702dc8_Traceguids,in_R9,
                    (int)in_stack_fffffffffffffea8);
        }
        (**(code **)(pWVar2->_padding_ + 0x30))
                  (pWVar2,&local_120._padding_,&local_120.ClientProcessList);
      }
    }
    (**(code **)(pWVar2->_padding_ + 8))(pWVar2);
    pWVar2 = WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters>::ReferenceNext
                       ((WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)this->_padding_,
                        local_128);
  }
  return;
}



===== WdfLpcCommPort @ 1400120b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcCommPort * __thiscall
WdfLpcCommPort::WdfLpcCommPort
          (WdfLpcCommPort *this,WdfLpcCommPortParameters *param_1,
          WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *param_2,WdfObject *param_3)

{
  ulong *puVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  _PORT_MESSAGE *p_Var5;
  _ALPC_MESSAGE_ATTRIBUTES *p_Var6;
  undefined4 *puVar7;
  WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *this_00;
  _IO_WORKITEM *p_Var8;
  ushort uVar9;
  _GUID *p_Var10;
  wchar_t *pwVar11;
  undefined8 local_res8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  
  WdfLpcPort::WdfLpcPort((WdfLpcPort *)this,(WdfLpcPortParameters *)param_1,param_3);
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  local_res8 = 0;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCCoreCallback__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCCommPortInterface__;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_qqq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),10,
               WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,param_1,param_2,param_3);
  }
  uVar4 = (uint)this->_padding_;
  this->m_ObjectList = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0;
  this->m_PeerProcessId = param_1->m_PeerProcessId;
  local_38 = 0;
  this->m_PendingMessages = (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)0x0;
  this->m_TimerPacket = (WudfPeriodicTimerCallbackPacket *)0x0;
  this->m_FastReplyPortMessage = (_PORT_MESSAGE *)0x0;
  this->m_FastReplyPortMessageData = (_WUDFMESSAGE_REPLY_ALL *)0x0;
  this->m_FastReplyAttributes = (_ALPC_MESSAGE_ATTRIBUTES *)0x0;
  this->m_LpcPortCloseNotificationRecieved = '\0';
  uVar3 = *(uint *)&param_1->m_ClientIdentifier;
  *(uint *)&this->m_ClientIdentifier = uVar3;
  this->m_PendingMessagesWithTimeout = 0;
  this->m_TimerPacketInstalled = '\0';
  this->m_AlpcRequestCallback = (void *)0x0;
  this->m_DrainMessageWorkItem = (_IO_WORKITEM *)0x0;
  this->m_DrainMessageWorkItemInUse = '\0';
  local_48 = 0;
  lStack_40 = (ulonglong)uVar3 << 0x20;
  lStack_40 = CONCAT71(lStack_40._1_7_,0x21);
  uStack_60 = 0;
  local_68 = 0x380010;
  local_58 = 0;
  uStack_50 = 0;
  if ((int)uVar4 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xb,
               WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar4);
    }
    goto LAB_140012251;
  }
  p_Var5 = (_PORT_MESSAGE *)ExAllocatePool2(0x40,0x88,0x68444d55);
  this->m_FastReplyPortMessage = p_Var5;
  if (p_Var5 == (_PORT_MESSAGE *)0x0) {
    uVar4 = 0xc0000017;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xc,
              WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
    }
    goto LAB_140012251;
  }
  memset();
  (this->m_FastReplyPortMessage->u2).s2.Type = 2;
  this->m_FastReplyPortMessageData = (_WUDFMESSAGE_REPLY_ALL *)(this->m_FastReplyPortMessage + 1);
  uVar4 = (**(code **)(*(longlong *)this->_padding_ + 0x30))
                    ((longlong *)this->_padding_,0x40000000,0,0,&local_res8);
  if (uVar4 != 0xc0000023) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xd,
               WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar4);
    }
    if (-1 < (int)uVar4) {
      uVar4 = 0xc00000e5;
    }
    goto LAB_140012251;
  }
  p_Var6 = (_ALPC_MESSAGE_ATTRIBUTES *)ExAllocatePool2(0x40,local_res8,0x67444d55);
  this->m_FastReplyAttributes = p_Var6;
  if (p_Var6 == (_ALPC_MESSAGE_ATTRIBUTES *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      uVar9 = 0xe;
LAB_140012435:
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar9,
              WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
    }
LAB_140012448:
    uVar4 = 0xc0000017;
  }
  else {
    memset();
    uVar4 = (**(code **)(*(longlong *)this->_padding_ + 0x30))
                      ((longlong *)this->_padding_,0x40000000,this->m_FastReplyAttributes,local_res8
                       ,&local_res8);
    if ((int)uVar4 < 0) {
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140012251;
      uVar9 = 0xf;
    }
    else {
      puVar1 = &this->m_FastReplyAttributes->ValidAttributes;
      *puVar1 = *puVar1 | 0x40000000;
      puVar7 = (undefined4 *)AlpcGetMessageAttribute(this->m_FastReplyAttributes,0x40000000);
      *puVar7 = 0x10000;
      uVar4 = WudfPeriodicTimerCallbackPacket::s_CreateInstance
                        (&this->m_TimerPacket,WudfPeriodicTimerCallback,this);
      if (-1 < (int)uVar4) {
        this_00 = (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)ExAllocatePool2(0x40);
        if (this_00 != (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)0x0) {
          p_Var10 = (_GUID *)0x0;
          WdfObject::WdfObject
                    ((WdfObject *)this_00,L"ListObjectNoName",(WdfObject *)0x0,'\0',RdTypeObject);
          this_00->m_List = (WdfObject *)0x0;
          this_00->_padding_ =
               (longlong)&___7__WdfObjectList_VRdProcess__VRdProcessParameters____6B_;
          this_00->m_NextUniqueObjectId = 1;
          this_00->m_Tag = 0x65444d55;
          this_00->m_PoolFlags = 0x40;
          this->m_PendingMessages = this_00;
          uVar4 = (uint)this_00->_padding_;
          if ((int)uVar4 < 0) {
            if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
              WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x12,
                       WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar4);
            }
            (**(code **)(this->m_PendingMessages->_padding_ + 0x28))();
            WdfObject::ReleaseWait((WdfObject *)this->m_PendingMessages,10000);
            this->m_PendingMessages = (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)0x0;
            goto LAB_140012251;
          }
          plVar2 = &this->_padding_;
          if (param_1->m_ServerSideCommPort == '\0') {
            p_Var10 = (_GUID *)this->_padding_;
            uVar4 = (**(code **)(*(longlong *)this->_padding_ + 0x20))
                              ((longlong *)this->_padding_,plVar2,p_Var10,param_1->m_ServerSid,
                               &local_68,param_1->m_AsyncConnect,this->_padding_,
                               -(ulonglong)(this != (WdfLpcCommPort *)0x0) &
                               (ulonglong)&this->_padding_);
            if ((int)uVar4 < 0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                WPP_SF_Sd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
                          WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,(wchar_t *)this->_padding_
                          ,uVar4);
              }
              goto LAB_140012251;
            }
            uVar4 = RegisterReplyCallback(this);
            if ((int)uVar4 < 0) {
              if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) == 0)) ||
                 (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140012251;
              uVar9 = 0x14;
              goto LAB_1400124c6;
            }
            p_Var8 = (_IO_WORKITEM *)IoAllocateWorkItem(param_1->m_IoObject->DeviceObject);
            this->m_DrainMessageWorkItem = p_Var8;
            if (p_Var8 == (_IO_WORKITEM *)0x0) {
              if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
                WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x15,
                        WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
              }
              uVar4 = 0xc000009a;
              goto LAB_140012251;
            }
          }
          else {
            *plVar2 = param_1->_padding_;
          }
          this->m_ObjectList = param_2;
          if (param_2 != (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
            WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Insert(param_2,this);
          }
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            pwVar11 = L"server";
            if (param_1->m_ServerSideCommPort == '\0') {
              pwVar11 = L"client";
            }
            WPP_SF_SqqS(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x9fe8,p_Var10,pwVar11,
                        this,(void *)*plVar2,(wchar_t *)this->_padding_);
          }
          goto LAB_140012251;
        }
        this->m_PendingMessages = (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)0x0;
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          uVar9 = 0x11;
          goto LAB_140012435;
        }
        goto LAB_140012448;
      }
      if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140012251;
      uVar9 = 0x10;
    }
LAB_1400124c6:
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar9,
             WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar4);
  }
LAB_140012251:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar4);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x17,
            WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
  }
  return this;
}



===== ~WdfLpcCommPort @ 14001288c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfLpcCommPort::~WdfLpcCommPort(WdfLpcCommPort *this)

{
  WPP_PROJECT_CONTROL_BLOCK *pWVar1;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *in_RDX;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCCoreCallback__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCCommPortInterface__;
  pWVar1 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    pWVar1 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    in_RDX = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1d;
    WPP_SF_((ulong64)pWVar1,0x1d,WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
  }
  WudfVerifyStatic((WdfComponentType)pWVar1,in_RDX,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpccomm.cpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"TODO: Write something interesting here",
                   (char)this->_padding_ != '\0');
  if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1e,
              WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,this,(void *)this->_padding_);
  }
  operator_delete(this->m_FastReplyPortMessage);
  operator_delete(this->m_FastReplyAttributes);
  if (this->m_PendingMessages != (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)0x0) {
    (**(code **)(this->m_PendingMessages->_padding_ + 0x28))();
    WdfObject::ReleaseWait((WdfObject *)this->m_PendingMessages,10000);
  }
  if (this->m_TimerPacket != (WudfPeriodicTimerCallbackPacket *)0x0) {
    (**(code **)(this->m_TimerPacket->_padding_ + 8))();
  }
  if (this->m_DrainMessageWorkItem != (_IO_WORKITEM *)0x0) {
    IoFreeWorkItem();
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1f,
            WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
  }
  WdfLpcPort::~WdfLpcPort((WdfLpcPort *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140012a40 =====

void * __thiscall WdfLpcCommPort::_scalar_deleting_destructor_(WdfLpcCommPort *this,uint param_1)

{
  ~WdfLpcCommPort(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AddRef`adjustor{160}' @ 140012a80 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCommPort::AddRef`adjustor{160}' (void)
   __ptr64 */

ulong __thiscall WdfLpcCommPort::AddRef_adjustor_160__(WdfLpcCommPort *this)

{
  ulong uVar1;
  
  uVar1 = WdfLpcInterface::AddRef((WdfLpcInterface *)&this[-1]._padding_);
  return uVar1;
}



===== AddRef`adjustor{168}' @ 140012aa0 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCommPort::AddRef`adjustor{168}' (void)
   __ptr64 */

ulong __thiscall WdfLpcCommPort::AddRef_adjustor_168__(WdfLpcCommPort *this)

{
  ulong uVar1;
  
  uVar1 = WdfLpcInterface::AddRef((WdfLpcInterface *)&this[-1]._padding_);
  return uVar1;
}



===== CreateSecurityContext @ 140012ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcCommPort::CreateSecurityContext
          (WdfLpcCommPort *this,_SECURITY_QUALITY_OF_SERVICE *param_1,void *param_2,void **param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1._0_4_ = this[-1].m_PendingMessagesWithTimeout;
  uVar1._4_1_ = this[-1].m_TimerPacketInstalled;
  uVar1._5_3_ = *(undefined3 *)&this[-1].field_0xed;
  lVar2 = (**(code **)((longlong)
                       ((this[-1].m_FastReplyPortMessageData)->field0_0x0).
                       WudfMsg_WMI_POWER_DATA_Reply + 0xa0))
                    (this[-1].m_FastReplyPortMessageData,uVar1,param_1,param_2,param_3);
  return lVar2;
}



===== DeleteSecurityContext @ 140012b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall WdfLpcCommPort::DeleteSecurityContext(WdfLpcCommPort *this,void *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1._0_4_ = this[-1].m_PendingMessagesWithTimeout;
  uVar1._4_1_ = this[-1].m_TimerPacketInstalled;
  uVar1._5_3_ = *(undefined3 *)&this[-1].field_0xed;
  lVar2 = (**(code **)((longlong)
                       ((this[-1].m_FastReplyPortMessageData)->field0_0x0).
                       WudfMsg_WMI_POWER_DATA_Reply + 0xa8))
                    (this[-1].m_FastReplyPortMessageData,uVar1,param_1);
  return lVar2;
}



===== Disconnect @ 140012b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall WdfLpcCommPort::Disconnect(WdfLpcCommPort *this)

{
  longlong lVar1;
  ulong uVar2;
  bool bVar3;
  
  lVar1._0_4_ = this[-1].m_PendingMessagesWithTimeout;
  lVar1._4_1_ = this[-1].m_TimerPacketInstalled;
  lVar1._5_3_ = *(undefined3 *)&this[-1].field_0xed;
  if (lVar1 != 0) {
    (**(code **)((longlong)
                 ((this[-1].m_FastReplyPortMessageData)->field0_0x0).WudfMsg_WMI_POWER_DATA_Reply +
                0xb0))();
    do {
      uVar2 = _AlpcRequestCallback(&this[-1]._padding_,(void *)0x0,(void *)0x0);
    } while (uVar2 != 0);
    lVar1 = this[-1]._padding_;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(lVar1,1);
    bVar3 = (char)this->_padding_ == '\0';
    if (bVar3) {
      *(undefined1 *)&this->_padding_ = 1;
    }
    ExReleaseResourceLite(this[-1]._padding_);
    KeLeaveCriticalRegion();
    if (bVar3) {
      (*(code *)**(undefined8 **)this[-1].m_FastReplyPortMessage)
                (this[-1].m_FastReplyPortMessage,
                 -(ulonglong)(&this[-1]._padding_ != (longlong *)0x0) & (ulonglong)this);
    }
  }
  lVar1 = this[-1]._padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar1,1);
  WudfSearchTimeoutMessagesWithLockHeld((WdfLpcCommPort *)&this[-1]._padding_,'\x01');
  ExReleaseResourceLite(this[-1]._padding_);
  KeLeaveCriticalRegion();
  return;
}



===== FastReply @ 140012c60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall
WdfLpcCommPort::FastReply(WdfLpcCommPort *this,ulong param_1,void *param_2,ulong param_3)

{
  _ALPC_MESSAGE_ATTRIBUTES *p_Var1;
  int iVar2;
  WdfLpcCommPort *pWVar3;
  undefined4 in_register_00000014;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var4;
  ulong uVar5;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  WdfDriverStopType in_stack_ffffffffffffffc0;
  WdfErrorClass in_stack_ffffffffffffffc8;
  ulong in_stack_ffffffffffffffd0;
  
  p_Var4 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
           CONCAT44(in_register_00000014,param_1);
  pWVar3 = this;
  uVar5 = param_3;
  WudfVerifyStatic((WdfComponentType)this,p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpccomm.cpp",param_3,
                   (char *)CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                   in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                   "reply buffer too large",param_3 < 0x61);
  WudfVerifyStatic((WdfComponentType)pWVar3,p_Var4,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpccomm.cpp",uVar5,
                   (char *)CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                   in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                   "reply buffer too large",param_3 + 0x28 < 0x8000);
  p_Var1 = this[-1].m_FastReplyAttributes;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(p_Var1,1);
  *(short *)this->_padding_ = (short)param_3;
  *(short *)(this->_padding_ + 2) = (short)(param_3 + 0x28);
  *(ulong *)(this->_padding_ + 0x18) = param_1;
  memcpy();
  iVar2 = (*(code *)(this[-1].m_PendingMessages)->_padding_)
                    (&this[-1].m_PendingMessages,0x10000,this->_padding_,this->_padding_,0,0);
  ExReleaseResourceLite(this[-1].m_FastReplyAttributes);
  KeLeaveCriticalRegion();
  if ((((iVar2 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
     (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_dd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2d,
              WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,param_1,iVar2);
  }
  return;
}



===== FastReply`adjustor{80}' @ 140012dd0 =====

/* [thunk]:public: virtual void __cdecl WdfLpcCommPort::FastReply`adjustor{80}' (unsigned long,void
   * __ptr64,unsigned long) __ptr64 */

void __thiscall
WdfLpcCommPort::FastReply_adjustor_80__
          (WdfLpcCommPort *this,ulong param_1,void *param_2,ulong param_3)

{
  FastReply((WdfLpcCommPort *)&this[-1].m_PeerProcessId,param_1,param_2,param_3);
  return;
}



===== FindExisting @ 140012de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WudfLpcMessage * __thiscall
WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters>::FindExisting
          (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *this,
          WudfLpcMessageParameters *param_1,bool param_2)

{
  ulong uVar1;
  longlong lVar2;
  WudfLpcMessage *pWVar3;
  bool bVar4;
  
  lVar2 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar2,1);
  pWVar3 = (WudfLpcMessage *)this->m_List;
  if (pWVar3 != (WudfLpcMessage *)0x0) {
    uVar1 = param_1->m_MessageId;
    do {
      if (uVar1 == 0) {
        bVar4 = param_1->m_LpcMessage == pWVar3;
      }
      else {
        lVar2 = AlpcGetMessageAttribute(pWVar3->m_MessageAttrib,0x20000000);
        uVar1 = param_1->m_MessageId;
        bVar4 = *(ulong *)(lVar2 + 0x14) == uVar1;
      }
    } while (((!bVar4) || ((char)pWVar3->_padding_ != '\0')) &&
            (pWVar3 = (WudfLpcMessage *)pWVar3->_padding_, pWVar3 != (WudfLpcMessage *)0x0));
    if (pWVar3 != (WudfLpcMessage *)0x0) {
      (**(code **)pWVar3->_padding_)(pWVar3);
    }
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  return pWVar3;
}



===== FindMessage @ 140012eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int __thiscall
WdfLpcCommPort::FindMessage
          (WdfLpcCommPort *this,ulong param_1,IUMDFLPCMessage **param_2,void **param_3)

{
  WudfLpcMessage *this_00;
  void *pvVar1;
  WudfLpcMessageParameters local_18;
  
  local_18.m_MessageId = param_1;
  this_00 = WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters>::FindExisting
                      ((WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *)this->_padding_,
                       &local_18,SUB81(param_2,0));
  if (param_3 != (void **)0x0) {
    if (this_00 == (WudfLpcMessage *)0x0) {
      *param_3 = (void *)0x0;
    }
    else {
      pvVar1 = WudfLpcMessage::LockPendingMessage(this_00);
      *param_3 = pvVar1;
      if (pvVar1 == (void *)0x0) {
        (**(code **)(this_00->_padding_ + 8))(this_00);
        this_00 = (WudfLpcMessage *)0x0;
      }
    }
  }
  *param_2 = (IUMDFLPCMessage *)
             (-(ulonglong)(this_00 != (WudfLpcMessage *)0x0) & (ulonglong)&this_00->_padding_);
  return (uint)(this_00 != (WudfLpcMessage *)0x0);
}



===== GetClientIdentifier @ 140012f50 =====

WUDF_LPC_CLIENT_IDENTIFIER __thiscall WdfLpcCommPort::GetClientIdentifier(WdfLpcCommPort *this)

{
  return (WUDF_LPC_CLIENT_IDENTIFIER)*(undefined4 *)((longlong)&this->_padding_ + 4);
}



===== GetContext @ 140012f60 =====

void * __thiscall WdfLpcCommPort::GetContext(WdfLpcCommPort *this)

{
  return (void *)this->_padding_;
}



===== GetContext`adjustor{80}' @ 140012f70 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl WdfLpcCommPort::GetContext`adjustor{80}' (void)
   __ptr64 */

void * __thiscall WdfLpcCommPort::GetContext_adjustor_80__(WdfLpcCommPort *this)

{
  void *pvVar1;
  
  pvVar1 = GetContext((WdfLpcCommPort *)&this[-1].m_PeerProcessId);
  return pvVar1;
}



===== ImpersonateClient @ 140012f80 =====

long __thiscall
WdfLpcCommPort::ImpersonateClient
          (WdfLpcCommPort *this,_SECURITY_IMPERSONATION_LEVEL param_1,_PORT_MESSAGE *param_2)

{
  return -0x3fffff45;
}



===== ImpersonateClient`adjustor{80}' @ 140012f90 =====

/* [thunk]:public: virtual long __cdecl WdfLpcCommPort::ImpersonateClient`adjustor{80}' (enum
   _SECURITY_IMPERSONATION_LEVEL,struct _PORT_MESSAGE * __ptr64) __ptr64 */

long __thiscall
WdfLpcCommPort::ImpersonateClient_adjustor_80__
          (WdfLpcCommPort *this,_SECURITY_IMPERSONATION_LEVEL param_1,_PORT_MESSAGE *param_2)

{
  long lVar1;
  
  lVar1 = ImpersonateClient((WdfLpcCommPort *)&this[-1].m_PeerProcessId,param_1,param_2);
  return lVar1;
}



===== Insert @ 140012fa0 =====

void __thiscall
WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Insert
          (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this,WdfLpcCommPort *param_1)

{
  ulong uVar1;
  longlong lVar2;
  
  lVar2 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar2,1);
  param_1->_padding_ = (longlong)this->m_List;
  uVar1 = this->m_NextUniqueObjectId;
  this->m_NextUniqueObjectId = uVar1 + 1;
  *(ulong *)&param_1->_padding_ = uVar1;
  this->m_List = (WdfObject *)param_1;
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  return;
}



===== MarkForDelete @ 140013030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall WdfLpcCommPort::MarkForDelete(WdfLpcCommPort *this)

{
  uchar *in_R8;
  
  if ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList !=
      (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
    WdfObjectList<RdProcess,RdProcessParameters>::Remove
              ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList,(RdProcess *)this,
               in_R8);
  }
  if (-1 < (int)this->_padding_) {
    (**(code **)(this->_padding_ + 0x48))();
  }
  if (this->m_AlpcRequestCallback != (void *)0x0) {
    ExUnregisterCallback();
    this->m_AlpcRequestCallback = (void *)0x0;
  }
  *(undefined1 *)&this->_padding_ = 1;
  return;
}



===== MarkForDelete`adjustor{88}' @ 1400130a0 =====

/* [thunk]:public: virtual void __cdecl WdfLpcCommPort::MarkForDelete`adjustor{88}' (void) __ptr64
    */

void __thiscall WdfLpcCommPort::MarkForDelete_adjustor_88__(WdfLpcCommPort *this)

{
  MarkForDelete((WdfLpcCommPort *)&this[-1].m_PendingMessages);
  return;
}



===== MarkForDelete`adjustor{168}' @ 1400130b0 =====

/* [thunk]:public: virtual void __cdecl WdfLpcCommPort::MarkForDelete`adjustor{168}' (void) __ptr64
    */

void __thiscall WdfLpcCommPort::MarkForDelete_adjustor_168__(WdfLpcCommPort *this)

{
  MarkForDelete((WdfLpcCommPort *)&this[-1]._padding_);
  return;
}



===== ProcessMessage @ 1400130d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uchar __thiscall
WdfLpcCommPort::ProcessMessage
          (WdfLpcCommPort *this,_PORT_MESSAGE *param_1,_ALPC_MESSAGE_ATTRIBUTES *param_2)

{
  ulong *puVar1;
  WudfLpcMessage *pWVar2;
  void *pvVar3;
  void *pvVar4;
  uchar uVar5;
  longlong lVar6;
  longlong *plVar7;
  ushort uVar8;
  uchar local_res10 [8];
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x22,
              WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,param_1,param_2);
  }
  lVar6 = AlpcGetMessageAttribute(param_2,0x20000000);
  uVar8 = (param_1->u2).s2.Type & 0xff;
  if (uVar8 == 1) {
LAB_140013330:
    pvVar3 = this->m_PeerProcessId;
    if ((pvVar3 != (void *)0x0) &&
       (pvVar4 = (param_1->field2_0x8).ClientId.UniqueProcess, pvVar4 != pvVar3)) {
      if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0 &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
        WPP_SF_qqq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x23,
                   WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,param_1,pvVar4,pvVar3);
      }
      return '\x01';
    }
  }
  else {
    if (uVar8 != 2) {
      if (uVar8 == 3) goto LAB_140013330;
      if (uVar8 == 5) {
        lVar6 = this->_padding_;
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(lVar6,1);
        this->m_LpcPortCloseNotificationRecieved = '\x01';
        ExReleaseResourceLite(this->_padding_);
        KeLeaveCriticalRegion();
        goto LAB_14001317c;
      }
      if (uVar8 != 0xc) goto LAB_14001317c;
    }
    pWVar2 = *(WudfLpcMessage **)(lVar6 + 8);
    if ((((uVar8 == 0xc) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
         ) && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x24,
                WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,param_1,pWVar2);
    }
    if (pWVar2 != (WudfLpcMessage *)0x0) {
      lVar6 = this->_padding_;
      local_res10[0] = '\0';
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(lVar6,1);
      WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters>::Remove
                (this->m_PendingMessages,pWVar2,local_res10);
      uVar5 = local_res10[0];
      if ((local_res10[0] != '\0') && (*(char *)((longlong)&pWVar2->_padding_ + 5) != '\0')) {
        puVar1 = &this->m_PendingMessagesWithTimeout;
        *puVar1 = *puVar1 - 1;
        if ((*puVar1 == 0) && (this->m_TimerPacketInstalled == '\x01')) {
          plVar7 = (longlong *)(*(longlong *)(this->_padding_ + 0x48) + 0x30);
          (**(code **)(*plVar7 + 0x28))
                    (plVar7,-(ulonglong)
                             (this->m_TimerPacket != (WudfPeriodicTimerCallbackPacket *)0x0) &
                            (ulonglong)&this->m_TimerPacket->_padding_);
          this->m_TimerPacketInstalled = '\0';
        }
      }
      ExReleaseResourceLite(this->_padding_);
      KeLeaveCriticalRegion();
      if (uVar5 == '\0') {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x25,
                   WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,pWVar2);
        }
        return '\0';
      }
    }
  }
LAB_14001317c:
  uVar5 = WdfLpcPort::ProcessMessage((WdfLpcPort *)this,param_1,param_2);
  return uVar5;
}



===== QueryInterface @ 1400133a0 =====

long __thiscall WdfLpcCommPort::QueryInterface(WdfLpcCommPort *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = WdfLpcPort::QueryInterface((WdfLpcPort *)this,param_1,param_2);
  return lVar1;
}



===== QueryInterface`adjustor{88}' @ 1400133c0 =====

/* [thunk]:public: virtual long __cdecl WdfLpcConnPort::QueryInterface`adjustor{88}' (struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WdfLpcConnPort::QueryInterface_adjustor_88__(WdfLpcConnPort *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = WdfLpcCommPort::QueryInterface((WdfLpcCommPort *)&this[-1]._padding_,param_1,param_2);
  return lVar1;
}



===== QueryInterface`adjustor{160}' @ 1400133d0 =====

/* [thunk]:public: virtual long __cdecl WdfLpcCommPort::QueryInterface`adjustor{160}' (struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WdfLpcCommPort::QueryInterface_adjustor_160__(WdfLpcCommPort *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface((WdfLpcCommPort *)&this[-1]._padding_,param_1,param_2);
  return lVar1;
}



===== QueryInterface`adjustor{168}' @ 1400133f0 =====

/* [thunk]:public: virtual long __cdecl WdfLpcCommPort::QueryInterface`adjustor{168}' (struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WdfLpcCommPort::QueryInterface_adjustor_168__(WdfLpcCommPort *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface((WdfLpcCommPort *)&this[-1]._padding_,param_1,param_2);
  return lVar1;
}



===== QueryInterface @ 140013410 =====

long __thiscall WdfLpcPort::QueryInterface(WdfLpcPort *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)param_1 + -0x4359e31d242e3def;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0xa48287f8ee61cb6;
  }
  if (lVar1 == 0) {
    *param_2 = this;
    return 0;
  }
  lVar1 = *(longlong *)param_1 + -0x445062f89e156ea5;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)param_1->Data4 + -0x23a7a3508bc713b0;
  }
  *param_2 = (void *)(-(ulonglong)(lVar1 == 0) & (ulonglong)this);
  return ~-(uint)(lVar1 == 0) & 0xc00002b9;
}



===== RegisterReplyCallback @ 140013474 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall WdfLpcCommPort::RegisterReplyCallback(WdfLpcCommPort *this)

{
  uint uVar1;
  void *pvVar2;
  ushort uVar3;
  longlong local_res10;
  longlong local_48 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_34 = 0;
  local_1c = 0;
  local_res10 = 0;
  local_38 = 0x30;
  pvVar2 = (void *)0x0;
  local_20 = 0x200;
  local_30 = 0;
  local_28 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar1 = ExCreateCallback(&local_res10,&local_38,1);
  if ((int)uVar1 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140013607;
    uVar3 = 0x1a;
  }
  else {
    pvVar2 = (void *)ExRegisterCallback(local_res10,_AlpcRequestCallback,this);
    if (pvVar2 == (void *)0x0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1b,
                WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
      }
      uVar1 = 0xc000009a;
      goto LAB_140013607;
    }
    local_48[1] = 0;
    local_48[0] = local_res10;
    uVar1 = (**(code **)(*(longlong *)this->_padding_ + 0x48))
                      ((longlong *)this->_padding_,this->_padding_,9,local_48,0x10);
    if (-1 < (int)uVar1) {
      this->m_AlpcRequestCallback = pvVar2;
      goto LAB_140013607;
    }
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        (-1 < (char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec))) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140013607;
    uVar3 = 0x1c;
  }
  WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar3,
           WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar1);
LAB_140013607:
  if (local_res10 != 0) {
    ObfDereferenceObject();
  }
  if ((int)uVar1 < 0) {
    ExUnregisterCallback(pvVar2);
  }
  return uVar1;
}



===== Release`adjustor{88}' @ 140013650 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCommPort::Release`adjustor{88}' (void)
   __ptr64 */

ulong __thiscall WdfLpcCommPort::Release_adjustor_88__(WdfLpcCommPort *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::Release((CUMDFUnknown *)&this[-1].m_PendingMessages);
  return uVar1;
}



===== Release`adjustor{160}' @ 140013660 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCommPort::Release`adjustor{160}' (void)
   __ptr64 */

ulong __thiscall WdfLpcCommPort::Release_adjustor_160__(WdfLpcCommPort *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::Release((CUMDFUnknown *)&this[-1]._padding_);
  return uVar1;
}



===== Release`adjustor{168}' @ 140013680 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcCommPort::Release`adjustor{168}' (void)
   __ptr64 */

ulong __thiscall WdfLpcCommPort::Release_adjustor_168__(WdfLpcCommPort *this)

{
  ulong uVar1;
  
  uVar1 = CUMDFUnknown::Release((CUMDFUnknown *)&this[-1]._padding_);
  return uVar1;
}



===== Remove @ 140013694 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

uchar __thiscall
WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters>::Remove
          (WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters> *this,WudfLpcMessage *param_1,
          uchar *param_2)

{
  WudfLpcMessage *pWVar1;
  WdfObject *pWVar2;
  longlong lVar3;
  WdfObject **ppWVar4;
  bool bVar5;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  lVar3 = this->_padding_;
  bVar5 = false;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar3,1);
  ppWVar4 = &this->m_List;
  do {
    pWVar1 = (WudfLpcMessage *)*ppWVar4;
    if (pWVar1 == (WudfLpcMessage *)0x0) {
LAB_1400136fb:
      if (param_2 == (uchar *)0x0) {
        WudfVerifyStatic((WdfComponentType)lVar3,
                         (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                         ppWVar4,
                         L"minkernel\\wdf\\framework\\umdf\\common\\inc\\clientserver\\object.hpp",
                         in_R9D,in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,
                         in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                         "expected object not found in list",bVar5);
      }
      else {
        *param_2 = bVar5;
      }
      pWVar2 = this->m_List;
      ExReleaseResourceLite(this->_padding_);
      KeLeaveCriticalRegion();
      return pWVar2 == (WdfObject *)0x0;
    }
    if (pWVar1 == param_1) {
      bVar5 = true;
      *ppWVar4 = (WdfObject *)pWVar1->_padding_;
      goto LAB_1400136fb;
    }
    ppWVar4 = (WdfObject **)&pWVar1->_padding_;
  } while( true );
}



===== Send @ 140013770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcCommPort::Send
          (WdfLpcCommPort *this,ulong param_1,_PORT_MESSAGE *param_2,
          _ALPC_MESSAGE_ATTRIBUTES *param_3,ulong param_4,uchar param_5)

{
  char *pcVar1;
  ulong *puVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  WdfLpcCommPort *pWVar6;
  
  pWVar6 = (WdfLpcCommPort *)0x0;
  if (param_5 != '\0') {
    lVar4 = AlpcGetMessageAttribute(param_3,0x20000000);
    pWVar6 = *(WdfLpcCommPort **)(lVar4 + 8);
    (**(code **)pWVar6->_padding_)(pWVar6);
  }
  lVar4 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar4,1);
  pcVar1 = (char *)((longlong)&pWVar6->_padding_ + 5);
  if (param_5 != '\0') {
    if (*pcVar1 != '\0') {
      if (this->m_PendingMessagesWithTimeout == 0xffffffff) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_dd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x20,
                    WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,-1,-0x3ffffbd5);
        }
        (**(code **)(pWVar6->_padding_ + 8))(pWVar6);
        ExReleaseResourceLite(this->_padding_);
        KeLeaveCriticalRegion();
        return -0x3ffffbd5;
      }
      this->m_PendingMessagesWithTimeout = this->m_PendingMessagesWithTimeout + 1;
      *(undefined4 *)&pWVar6->_padding_ = 0;
    }
    WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Insert
              ((WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)this->m_PendingMessages,
               pWVar6);
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  iVar3 = (**(code **)(*(longlong *)this->_padding_ + 0x38))
                    ((longlong *)this->_padding_,this->_padding_,param_1,param_2,param_3);
  lVar4 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar4,1);
  if (param_5 != '\0') {
    if (iVar3 < 0) {
      WdfObjectList<WudfLpcMessage,WudfLpcMessageParameters>::Remove
                (this->m_PendingMessages,(WudfLpcMessage *)pWVar6,(uchar *)0x0);
      if (*pcVar1 != '\0') {
        puVar2 = &this->m_PendingMessagesWithTimeout;
        *puVar2 = *puVar2 - 1;
        if ((*puVar2 == 0) && (this->m_TimerPacketInstalled == '\x01')) {
          plVar5 = (longlong *)(*(longlong *)(this->_padding_ + 0x48) + 0x30);
          (**(code **)(*plVar5 + 0x28))
                    (plVar5,-(ulonglong)
                             (this->m_TimerPacket != (WudfPeriodicTimerCallbackPacket *)0x0) &
                            (ulonglong)&this->m_TimerPacket->_padding_);
          this->m_TimerPacketInstalled = '\0';
        }
      }
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x21,
                  WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,(void *)this->_padding_,iVar3);
      }
    }
    else {
      *(ulong *)&pWVar6->_padding_ = param_4;
      if (((*pcVar1 != '\0') && (this->m_PendingMessagesWithTimeout != 0)) &&
         (this->m_TimerPacketInstalled == '\0')) {
        plVar5 = (longlong *)(*(longlong *)(this->_padding_ + 0x48) + 0x30);
        (**(code **)(*plVar5 + 0x20))
                  (plVar5,-(ulonglong)
                           (this->m_TimerPacket != (WudfPeriodicTimerCallbackPacket *)0x0) &
                          (ulonglong)&this->m_TimerPacket->_padding_);
        this->m_TimerPacketInstalled = '\x01';
      }
    }
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if (param_5 != '\0') {
    (**(code **)(pWVar6->_padding_ + 8))(pWVar6);
  }
  return iVar3;
}



===== SetContext @ 140013a80 =====

void __thiscall WdfLpcCommPort::SetContext(WdfLpcCommPort *this,void *param_1)

{
  this->_padding_ = (longlong)param_1;
  return;
}



===== SetContext`adjustor{80}' @ 140013a90 =====

/* [thunk]:public: virtual void __cdecl WdfLpcCommPort::SetContext`adjustor{80}' (void * __ptr64)
   __ptr64 */

void __thiscall WdfLpcCommPort::SetContext_adjustor_80__(WdfLpcCommPort *this,void *param_1)

{
  SetContext((WdfLpcCommPort *)&this[-1].m_PeerProcessId,param_1);
  return;
}



===== WudfPeriodicTimerCallback @ 140013aa0 =====

void __thiscall WdfLpcCommPort::WudfPeriodicTimerCallback(WdfLpcCommPort *this)

{
  longlong lVar1;
  
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x26,
             WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,this);
  }
  lVar1 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar1);
  WudfSearchTimeoutMessagesWithLockHeld(this,'\0');
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x27,
            WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids);
  }
  return;
}



===== WudfPeriodicTimerCallback @ 140013b90 =====

void __cdecl WdfLpcCommPort::WudfPeriodicTimerCallback(void *param_1)

{
  WudfPeriodicTimerCallback(param_1);
  return;
}



===== WudfSearchTimeoutMessagesWithLockHeld @ 140013ba8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __thiscall
WdfLpcCommPort::WudfSearchTimeoutMessagesWithLockHeld(WdfLpcCommPort *this,uchar param_1)

{
  int iVar1;
  long lVar2;
  WdfLpcCommPort *this_00;
  undefined8 uVar3;
  uint uVar4;
  undefined7 in_register_00000011;
  uint uVar5;
  char *pcVar6;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  if ((WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)this->m_PendingMessages !=
      (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
    uVar5 = 0;
    this_00 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::EnumFirst
                        ((WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)
                         this->m_PendingMessages,(WdfObject *)CONCAT71(in_register_00000011,param_1)
                        );
joined_r0x000140013be9:
    if (this_00 != (WdfLpcCommPort *)0x0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x10) != 0)) &&
         (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_q((ulong64)*(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8),0x28
                 ,WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,this_00);
      }
      if ((param_1 != '\0') ||
         (((iVar1 = (int)this_00->_padding_, iVar1 != 0 &&
           (iVar1 = iVar1 + -1, *(int *)&this_00->_padding_ = iVar1, iVar1 == 0)) &&
          ((lVar2 = WudfLpcMessage::ExtendTimeout((WudfLpcMessage *)this_00,local_res8), lVar2 < 0
           || (*(ulong *)&this_00->_padding_ = local_res8[0], local_res8[0] == 0)))))) {
        pcVar6 = "UMDF: IPC detected that the message to host timed out\n";
        DbgPrintEx(0x65);
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          uVar4 = (ushort)(((_PORT_MESSAGE *)this_00->_padding_)->u2).s2.Type & 0xffff00ff;
          WPP_SF_qqL(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),(ushort)uVar4,
                     (_GUID *)pcVar6,(void *)this->_padding_,this_00,uVar4);
        }
        uVar3 = AlpcGetMessageAttribute(this_00->m_TimerPacket,0x20000000);
        iVar1 = (**(code **)(*(longlong *)this->_padding_ + 0x88))
                          ((longlong *)this->_padding_,this->_padding_,2,uVar3);
        if (iVar1 < 0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0')) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2b,
                      WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,this,iVar1);
          }
        }
        else {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x10) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2a,
                     WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,this_00);
          }
          uVar5 = uVar5 + 1;
          *(undefined1 *)((longlong)&this_00->_padding_ + 4) = 1;
          if (this->m_DrainMessageWorkItemInUse == '\0') {
            this->m_DrainMessageWorkItemInUse = '\x01';
            (**(code **)this->_padding_)(this);
            IoQueueWorkItem(this->m_DrainMessageWorkItem,s_DrainCanceledMessageWorkItem,1,this);
          }
        }
      }
      do {
        this_00 = (WdfLpcCommPort *)this_00->_padding_;
        if (this_00 == (WdfLpcCommPort *)0x0) break;
      } while ((char)this_00->_padding_ != '\0');
      goto joined_r0x000140013be9;
    }
    ExReleaseResourceLite(this->m_PendingMessages->_padding_);
    KeLeaveCriticalRegion();
    if (((uVar5 != 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control))
       && (((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x1ec) < '\0' &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x2c,
               WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar5);
    }
  }
  return;
}



===== _AlpcRequestCallback @ 140013e70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulong __cdecl WdfLpcCommPort::_AlpcRequestCallback(void *param_1,void *param_2,void *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined1 auStack_158 [32];
  undefined4 *local_138;
  undefined8 local_128 [3];
  undefined1 local_110 [4];
  ushort local_10c;
  undefined4 local_78;
  undefined4 local_74;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  memset();
  bVar1 = false;
  (*(code *)**(undefined8 **)param_1)(param_1);
  do {
    local_138 = &local_78;
    local_78 = 0xe0000000;
    local_74 = 0;
    local_128[0] = 0x98;
    uVar2 = (**(code **)(**(longlong **)((longlong)param_1 + 0x78) + 0x40))
                      (*(longlong **)((longlong)param_1 + 0x78),
                       *(undefined8 *)((longlong)param_1 + 0x80),local_110,local_128);
    if (uVar2 == 0) {
      (**(code **)(*(longlong *)param_1 + 0x30))(param_1,local_110,&local_78);
      if ((local_10c & 0xff) == 5) {
        bVar1 = true;
      }
    }
    else if ((((uVar2 != 0x102) &&
              (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
             ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
            (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x19,
               WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,uVar2);
    }
  } while ((bVar1) && (uVar2 == 0));
  (**(code **)(*(longlong *)param_1 + 8))(param_1);
  return (uint)(uVar2 == 0);
}



===== s_DrainCanceledMessageWorkItem @ 140013fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WdfLpcCommPort::s_DrainCanceledMessageWorkItem(_DEVICE_OBJECT *param_1,void *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x20);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(uVar1);
  *(undefined1 *)((longlong)param_2 + 0x108) = 0;
  ExReleaseResourceLite(*(undefined8 *)((longlong)param_2 + 0x20));
  KeLeaveCriticalRegion();
  do {
    uVar2 = _AlpcRequestCallback(param_2,(void *)0x0,(void *)0x0);
  } while (uVar2 != 0);
  (**(code **)(*(longlong *)param_2 + 8))(param_2);
  return;
}



===== WPP_SF_SqqS @ 140014064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_SqqS(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4,void *param_5,
           void *param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = -1;
  if (param_7 != (wchar_t *)0x0) {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_7[lVar2] != L'\0');
  }
  if (param_4 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,0x16);
  return;
}



===== WPP_SF_qqL @ 140014144 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqL(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,ulong param_6)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_c2b78955d84d3452e3c647936d3ed929_Traceguids,0x29);
  return;
}



===== WdfLpcConnPort @ 1400141ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcConnPort * __thiscall
WdfLpcConnPort::WdfLpcConnPort
          (WdfLpcConnPort *this,WdfLpcConnPortParameters *param_1,
          WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *param_2,WdfObject *param_3)

{
  WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *pWVar1;
  uint uVar2;
  _GUID *p_Var3;
  ushort uVar4;
  WdfLpcConnPort *pWVar5;
  _GUID *p_Var6;
  
  WdfLpcPort::WdfLpcPort((WdfLpcPort *)this,(WdfLpcPortParameters *)param_1,param_3);
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  this->_padding_ = (longlong)&___7WdfLpcConnPort__6B_;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_qqq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),10,
               WPP_06915895859538f2af2b6374fb421630_Traceguids,param_1,param_2,param_3);
  }
  this->m_ObjectList = (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0;
  this->m_CommPortList = (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0;
  uVar2 = (uint)this->_padding_;
  this->m_ByPassProcessIdCheck = param_1->m_ByPassProcessIdCheck;
  if ((int)uVar2 < 0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xb,
               WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar2);
    }
    goto LAB_14001441b;
  }
  pWVar1 = param_1->m_CommPortList;
  if (pWVar1 == (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      uVar4 = 0xd;
LAB_1400142e2:
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar4,
              WPP_06915895859538f2af2b6374fb421630_Traceguids);
    }
  }
  else {
    this->m_CommPortList = pWVar1;
    (**(code **)pWVar1->_padding_)();
    p_Var3 = WdfPlatformSecurity::WudfAllocateSecurityDescriptor
                       (param_1->m_ServerSIDTable,param_1->m_NumServerSIDs);
    if (p_Var3 != (_GUID *)0x0) {
      uVar4 = (ushort)this->_padding_;
      p_Var6 = p_Var3;
      uVar2 = (**(code **)(*(longlong *)this->_padding_ + 0x18))();
      if ((int)uVar2 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_Sd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xf,
                    WPP_06915895859538f2af2b6374fb421630_Traceguids,(wchar_t *)this->_padding_,uVar2
                   );
        }
      }
      else {
        this->m_ObjectList = param_2;
        if (param_2 != (WdfObjectList<WdfLpcConnPort,WdfLpcConnPortParameters> *)0x0) {
          pWVar5 = this;
          WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Insert
                    ((WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)param_2,
                     (WdfLpcCommPort *)this);
          uVar4 = (ushort)pWVar5;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_qqS(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar4,p_Var6,this,
                     (void *)this->_padding_,(wchar_t *)this->_padding_);
        }
      }
      operator_delete(p_Var3);
      goto LAB_14001441b;
    }
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      uVar4 = 0xe;
      goto LAB_1400142e2;
    }
  }
  uVar2 = 0xc000000d;
LAB_14001441b:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar2);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x11,
            WPP_06915895859538f2af2b6374fb421630_Traceguids);
  }
  return this;
}



===== ~WdfLpcConnPort @ 14001447c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfLpcConnPort::~WdfLpcConnPort(WdfLpcConnPort *this)

{
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *in_RDX;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  this->_padding_ = (longlong)&___7WdfLpcConnPort__6B_;
  WudfVerifyStatic((WdfComponentType)this,in_RDX,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcconn.cpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"TODO: Write something interesting here",
                   (char)this->_padding_ != '\0');
  if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x12,
              WPP_06915895859538f2af2b6374fb421630_Traceguids,this,(void *)this->_padding_);
  }
  if (this->m_CommPortList != (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *)0x0) {
    (**(code **)(this->m_CommPortList->_padding_ + 8))();
  }
  WdfLpcPort::~WdfLpcPort((WdfLpcPort *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140014550 =====

void * __thiscall WdfLpcConnPort::_scalar_deleting_destructor_(WdfLpcConnPort *this,uint param_1)

{
  ~WdfLpcConnPort(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== ClearAccessControl @ 140014590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall WdfLpcConnPort::ClearAccessControl(WdfLpcConnPort *this,void *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(longlong *)this[-1]._padding_ + 0xc0))
                    ((longlong *)this[-1]._padding_,this[-1].ClientProcessList,param_1);
  if (((((int)uVar1 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
       ) && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x27,
             WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar1);
  }
  return uVar1;
}



===== FastReply @ 140014610 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall
WdfLpcConnPort::FastReply(WdfLpcConnPort *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined4 in_register_00000014;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  WudfVerifyStatic((WdfComponentType)this,
                   (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)
                   CONCAT44(in_register_00000014,param_1),
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\wdflpc.hpp",param_3,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"not supported",false);
  return;
}



===== FastReply`adjustor{72}' @ 140014640 =====

/* [thunk]:public: virtual void __cdecl WdfLpcConnPort::FastReply`adjustor{72}' (unsigned long,void
   * __ptr64,unsigned long) __ptr64 */

void __thiscall
WdfLpcConnPort::FastReply_adjustor_72__
          (WdfLpcConnPort *this,ulong param_1,void *param_2,ulong param_3)

{
  FastReply((WdfLpcConnPort *)&this[-1]._padding_,param_1,param_2,param_3);
  return;
}



===== Find @ 140014650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcCommPort * __thiscall
WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Find
          (WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters> *this,
          WdfLpcCommPortParameters *param_1,uchar param_2,uchar param_3,uchar *param_4,long *param_5
          )

{
  longlong lVar1;
  WdfLpcCommPort *pWVar2;
  
  lVar1 = this->_padding_;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(lVar1,1);
  pWVar2 = (WdfLpcCommPort *)this->m_List;
  if (pWVar2 != (WdfLpcCommPort *)0x0) {
    do {
      if (((pWVar2->_padding_ != 0) && (param_1->_padding_ == pWVar2->_padding_)) &&
         ((char)pWVar2->_padding_ == '\0')) break;
      pWVar2 = (WdfLpcCommPort *)pWVar2->_padding_;
    } while (pWVar2 != (WdfLpcCommPort *)0x0);
    if (pWVar2 != (WdfLpcCommPort *)0x0) {
      (**(code **)pWVar2->_padding_)(pWVar2);
    }
  }
  ExReleaseResourceLite(this->_padding_);
  KeLeaveCriticalRegion();
  return pWVar2;
}



===== GetContext`adjustor{72}' @ 140014700 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl WdfLpcConnPort::GetContext`adjustor{72}' (void)
   __ptr64 */

void * __thiscall WdfLpcConnPort::GetContext_adjustor_72__(WdfLpcConnPort *this)

{
  void *pvVar1;
  
  pvVar1 = WdfLpcCommPort::GetContext((WdfLpcCommPort *)&this[-1]._padding_);
  return pvVar1;
}



===== GetPortHandle @ 140014710 =====

void * __thiscall WdfLpcConnPort::GetPortHandle(WdfLpcConnPort *this)

{
  return this[-1].ClientProcessList;
}



===== ImpersonateClient`adjustor{72}' @ 140014720 =====

/* [thunk]:public: virtual long __cdecl WdfLpcConnPort::ImpersonateClient`adjustor{72}' (enum
   _SECURITY_IMPERSONATION_LEVEL,struct _PORT_MESSAGE * __ptr64) __ptr64 */

long __thiscall
WdfLpcConnPort::ImpersonateClient_adjustor_72__
          (WdfLpcConnPort *this,_SECURITY_IMPERSONATION_LEVEL param_1,_PORT_MESSAGE *param_2)

{
  long lVar1;
  
  lVar1 = WdfLpcCommPort::ImpersonateClient((WdfLpcCommPort *)&this[-1]._padding_,param_1,param_2);
  return lVar1;
}



===== MarkForDelete @ 140014730 =====

void __thiscall WdfLpcConnPort::MarkForDelete(WdfLpcConnPort *this)

{
  uchar *in_R8;
  
  if ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList !=
      (WdfObjectList<RdProcess,RdProcessParameters> *)0x0) {
    WdfObjectList<RdProcess,RdProcessParameters>::Remove
              ((WdfObjectList<RdProcess,RdProcessParameters> *)this->m_ObjectList,(RdProcess *)this,
               in_R8);
  }
  *(undefined1 *)&this->_padding_ = 1;
  return;
}



===== MarkForDelete`adjustor{88}' @ 140014760 =====

/* [thunk]:public: virtual void __cdecl WdfLpcConnPort::MarkForDelete`adjustor{88}' (void) __ptr64
    */

void __thiscall WdfLpcConnPort::MarkForDelete_adjustor_88__(WdfLpcConnPort *this)

{
  MarkForDelete((WdfLpcConnPort *)&this[-1]._padding_);
  return;
}



===== MarkForDelete`adjustor{160}' @ 140014770 =====

/* [thunk]:public: virtual void __cdecl WdfLpcConnPort::MarkForDelete`adjustor{160}' (void) __ptr64
    */

void __thiscall WdfLpcConnPort::MarkForDelete_adjustor_160__(WdfLpcConnPort *this)

{
  MarkForDelete((WdfLpcConnPort *)&this[-1]._padding_);
  return;
}



===== ProcessMessage @ 140014790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uchar __thiscall
WdfLpcConnPort::ProcessMessage
          (WdfLpcConnPort *this,_PORT_MESSAGE *param_1,_ALPC_MESSAGE_ATTRIBUTES *param_2)

{
  void *pvVar1;
  byte bVar2;
  undefined8 *puVar3;
  WdfLpcCommPort *pWVar4;
  WdfObject *pWVar5;
  int iVar6;
  _GUID *p_Var7;
  uchar in_R9B;
  _PORT_MESSAGE *p_Var8;
  _ALPC_MESSAGE_ATTRIBUTES *in_stack_ffffffffffffff58;
  long *in_stack_ffffffffffffff60;
  WdfObject local_88;
  
  p_Var7 = (_GUID *)param_2;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    p_Var7 = WPP_06915895859538f2af2b6374fb421630_Traceguids;
    p_Var8 = param_1;
    in_stack_ffffffffffffff58 = param_2;
    WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
              WPP_06915895859538f2af2b6374fb421630_Traceguids,param_1,param_2);
    in_R9B = (uchar)p_Var8;
  }
  bVar2 = 0;
  puVar3 = (undefined8 *)AlpcGetMessageAttribute(param_2,0x20000000);
  if (((param_1->u2).s2.Type & 0xffU) == 10) {
    bVar2 = ProcessMessage_Connect(this,param_1,param_2);
  }
  else {
    pvVar1 = (void *)*puVar3;
    pWVar5 = &local_88;
    local_88._padding_ = 0;
    local_88._padding_ = 0;
    local_88._padding_ = 0;
    local_88._padding_._0_4_ = 0;
    local_88.m_Parent = (WdfObject *)0x400;
    local_88.m_UniqueObjectId._0_2_ = 0;
    local_88.m_Next = (WdfObject *)0x0;
    local_88.m_Event.Value = (void *)0x0;
    local_88.m_MarkedForDelete = '\x02';
    local_88.m_ObjectType = 0;
    local_88._82_2_ = 0;
    local_88._padding_ = (longlong)pvVar1;
    pWVar4 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::Find
                       (this->m_CommPortList,(WdfLpcCommPortParameters *)pWVar5,(uchar)p_Var7,in_R9B
                        ,(uchar *)in_stack_ffffffffffffff58,in_stack_ffffffffffffff60);
    if (pWVar4 == (WdfLpcCommPort *)0x0) {
      if (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_qqqq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),(ushort)pWVar5,p_Var7,
                      pvVar1,this,(void *)this->_padding_,param_1);
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          pWVar5 = (WdfObject *)0x19;
          WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x19,
                  WPP_06915895859538f2af2b6374fb421630_Traceguids);
        }
      }
      pWVar4 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::EnumFirst
                         (this->m_CommPortList,pWVar5);
      for (iVar6 = 0; (pWVar4 != (WdfLpcCommPort *)0x0 && (iVar6 < 10)); iVar6 = iVar6 + 1) {
        if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0 &&
            (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))))) {
          WPP_SF_qq((ulong64)*(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8),
                    0x1a,WPP_06915895859538f2af2b6374fb421630_Traceguids,pWVar4,
                    (void *)pWVar4->_padding_);
        }
        do {
          pWVar4 = (WdfLpcCommPort *)pWVar4->_padding_;
          if (pWVar4 == (WdfLpcCommPort *)0x0) break;
        } while ((char)pWVar4->_padding_ != '\0');
      }
      ExReleaseResourceLite(this->m_CommPortList->_padding_);
      KeLeaveCriticalRegion();
    }
    else {
      bVar2 = (**(code **)(pWVar4->_padding_ + 0x30))(pWVar4,param_1,param_2);
      (**(code **)(pWVar4->_padding_ + 8))(pWVar4);
    }
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1b,
             WPP_06915895859538f2af2b6374fb421630_Traceguids,(uint)bVar2);
  }
  return bVar2;
}



===== ProcessMessage_Connect @ 140014a38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

uchar __thiscall
WdfLpcConnPort::ProcessMessage_Connect
          (WdfLpcConnPort *this,_PORT_MESSAGE *param_1,_ALPC_MESSAGE_ATTRIBUTES *param_2)

{
  uint uVar1;
  WdfLpcCommPort *pWVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  ushort uVar4;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var5;
  uint uVar6;
  ulong in_R9D;
  _PORT_MESSAGE *p_Var7;
  undefined1 auStackY_158 [32];
  _ALPC_MESSAGE_ATTRIBUTES *in_stack_fffffffffffffec8;
  WdfDriverStopType in_stack_fffffffffffffed0;
  WdfErrorClass in_stack_fffffffffffffed8;
  ulong in_stack_fffffffffffffee0;
  undefined1 local_f8 [96];
  undefined4 local_98;
  undefined8 local_94;
  undefined4 local_8c;
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x0;
  memset();
  pWVar3 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    pWVar3 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    p_Var5 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x1c;
    p_Var7 = param_1;
    WPP_SF_qq((ulong64)pWVar3,0x1c,WPP_06915895859538f2af2b6374fb421630_Traceguids,param_1,param_2);
    in_R9D = (ulong)p_Var7;
    in_stack_fffffffffffffec8 = param_2;
  }
  WudfVerifyStatic((WdfComponentType)pWVar3,p_Var5,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcconn.cpp",in_R9D,
                   (char *)in_stack_fffffffffffffec8,in_stack_fffffffffffffed0,
                   in_stack_fffffffffffffed8,in_stack_fffffffffffffee0,
                   "TODO: Write something interesting here",((param_1->u2).s2.Type & 0xffU) == 10);
  uVar6 = 0;
  if ((ushort)(param_1->u1).s1.DataLength < 8) {
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return '\0';
    }
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) == 0) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140014dd8;
    uVar4 = 0x1d;
  }
  else {
    local_f8._64_8_ = (void *)0x0;
    local_f8._80_4_ = param_1[1].u2.s2;
    local_f8._40_8_ = this->_padding_;
    if (this->m_ByPassProcessIdCheck == '\0') {
      local_f8._64_8_ = (param_1->field2_0x8).ClientId.UniqueProcess;
    }
    local_f8._0_8_ = this->_padding_;
    local_f8._8_8_ = this->_padding_;
    local_f8._16_8_ = this->_padding_;
    local_f8._32_4_ = SUB84(this->_padding_,0);
    local_f8._24_8_ = 0;
    local_f8[0x38] = '\0';
    local_f8[0x39] = '\x01';
    local_f8._48_8_ = (void *)0x0;
    pWVar2 = WdfObjectList<WdfLpcCommPort,WdfLpcCommPortParameters>::CreateNew
                       (this->m_CommPortList,(WdfLpcCommPortParameters *)local_f8,(long *)0x0);
    if (pWVar2 != (WdfLpcCommPort *)0x0) {
      (**(code **)pWVar2->_padding_)(pWVar2);
      uVar1 = (**(code **)(*(longlong *)this->_padding_ + 8))
                        ((longlong *)this->_padding_,&this->_padding_,&pWVar2->_padding_,
                         (param_1->field2_0x8).ClientId.UniqueProcess);
      if ((int)uVar1 < 0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1f,
                   WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar1);
        }
        (**(code **)(pWVar2->_padding_ + 8))(pWVar2);
      }
      else {
        local_78 = 0x400000;
        local_70 = 0x400000;
        local_68 = 0x400000;
        local_88 = this->_padding_;
        local_8c = 0x101;
        local_58 = 0;
        local_98 = 0x20000;
        local_60 = 0x2000000;
        local_80 = 0;
        local_94 = 0xc;
        uVar1 = (**(code **)(*(longlong *)this->_padding_ + 0x90))
                          ((longlong *)this->_padding_,&pWVar2->_padding_,this->_padding_,0);
        (**(code **)(pWVar2->_padding_ + 8))(pWVar2);
        if ((int)uVar1 < 0) {
          (*(code *)**(undefined8 **)this->_padding_)
                    ((undefined8 *)this->_padding_,&pWVar2->_padding_);
          if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
            return '\0';
          }
          if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) != 0) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x20,
                     WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar1);
          }
        }
        else {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x21,
                      WPP_06915895859538f2af2b6374fb421630_Traceguids,pWVar2,
                      (void *)pWVar2->_padding_);
          }
          uVar6 = 1;
        }
      }
      goto LAB_140014dd8;
    }
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
      return '\0';
    }
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 4) == 0) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_140014dd8;
    uVar4 = 0x1e;
  }
  WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar4,
          WPP_06915895859538f2af2b6374fb421630_Traceguids);
LAB_140014dd8:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x23,
             WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar6);
  }
  return (uchar)uVar6;
}



===== Release`adjustor{160}' @ 140014e50 =====

/* [thunk]:public: virtual unsigned long __cdecl WdfLpcConnPort::Release`adjustor{160}' (void)
   __ptr64 */

ulong __thiscall WdfLpcConnPort::Release_adjustor_160__(WdfLpcConnPort *this)

{
  ulong uVar1;
  
  uVar1 = WudfLpcMessage::Release((WudfLpcMessage *)&this[-1]._padding_);
  return uVar1;
}



===== Send @ 140014e70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcConnPort::Send
          (WdfLpcConnPort *this,ulong param_1,_PORT_MESSAGE *param_2,
          _ALPC_MESSAGE_ATTRIBUTES *param_3,ulong param_4,uchar param_5)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(longlong *)this->_padding_ + 0x38))
                    ((longlong *)this->_padding_,this->_padding_,param_1,param_2,param_3);
  if ((((iVar1 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x24,
              WPP_06915895859538f2af2b6374fb421630_Traceguids,param_2,iVar1);
  }
  return iVar1;
}



===== SetAccessControl @ 140014f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __thiscall
WdfLpcConnPort::SetAccessControl(WdfLpcConnPort *this,void *param_1,wchar_t *param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*(longlong *)this[-1]._padding_ + 0xb8))
                    ((longlong *)this[-1]._padding_,this[-1].ClientProcessList,param_1,param_2);
  if (((((int)uVar1 < 0) && (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control)
       ) && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 2) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x26,
             WPP_06915895859538f2af2b6374fb421630_Traceguids,uVar1);
  }
  return uVar1;
}



===== SetContext`adjustor{72}' @ 140014f90 =====

/* [thunk]:public: virtual void __cdecl WdfLpcConnPort::SetContext`adjustor{72}' (void * __ptr64)
   __ptr64 */

void __thiscall WdfLpcConnPort::SetContext_adjustor_72__(WdfLpcConnPort *this,void *param_1)

{
  WdfLpcCommPort::SetContext((WdfLpcCommPort *)&this[-1]._padding_,param_1);
  return;
}



===== WPP_SF_qqS @ 140014fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqS(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,
          wchar_t *param_6)

{
  longlong lVar1;
  
  if (param_6 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_06915895859538f2af2b6374fb421630_Traceguids,0x10);
  return;
}



===== WPP_SF_qqqq @ 14001504c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_qqqq(ulong64 param_1,ushort param_2,_GUID *param_3,void *param_4,void *param_5,void *param_6,
           void *param_7)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_06915895859538f2af2b6374fb421630_Traceguids,0x18);
  return;
}



===== WdfLpcPort @ 1400150bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

WdfLpcPort * __thiscall
WdfLpcPort::WdfLpcPort(WdfLpcPort *this,WdfLpcPortParameters *param_1,WdfObject *param_2)

{
  WdfLpc *pWVar1;
  IUMDFLPCCorePortInterface *pIVar2;
  undefined3 uVar3;
  uint uVar4;
  ulong64 uVar5;
  _ALPC_MESSAGE_ATTRIBUTES *p_Var6;
  ushort uVar7;
  WdfObject *pWVar8;
  wchar_t *pwVar9;
  undefined8 local_res8;
  
  pwVar9 = param_1->m_ServerPortName;
  pWVar8 = param_2;
  WdfObject::WdfObject((WdfObject *)this,pwVar9,param_2,'\0',RdTypeObject);
  local_res8 = 0;
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_Sqqq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),(ushort)pwVar9,(_GUID *)pWVar8,
                param_1->m_ServerPortName,param_1->m_Notification,param_1->m_PortHandle,param_2);
  }
  this->m_MsgAttribBuffer = (_ALPC_MESSAGE_ATTRIBUTES *)0x0;
  this->m_Notification = (IUMDFLPCNotification *)0x0;
  this->m_PortHandle = (void *)0x0;
  this->m_Context = (void *)0x0;
  pWVar1 = param_1->m_Lpc;
  uVar4 = (uint)this->_padding_;
  this->m_Lpc = pWVar1;
  pIVar2 = pWVar1->m_LpcCorePortInterface;
  this->m_LpcCorePortInterface = pIVar2;
  uVar3 = *(undefined3 *)&param_1->field_0x21;
  this->m_Owner = param_1->m_Owner;
  *(undefined3 *)&this->field_0x99 = uVar3;
  uVar5 = param_1->m_MaxMessageSize;
  if (uVar5 == 0) {
    uVar5 = 0x400;
  }
  this->m_MaxMessageSize = uVar5;
  if ((int)uVar4 < 0) {
    if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14001538e;
    uVar7 = 0xb;
LAB_140015372:
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar7,
             WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,uVar4);
  }
  else {
    if (param_1->m_ServerPortName == (wchar_t *)0x0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        uVar7 = 0xc;
LAB_14001520a:
        WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar7,
                WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
      }
    }
    else {
      if (param_1->m_Notification != (IUMDFLPCNotification *)0x0) {
        uVar4 = (**(code **)((longlong)*pIVar2 + 0x30))(pIVar2,0x60000000,0,0,&local_res8);
        if (uVar4 != 0xc0000023) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xe,
                     WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,uVar4);
          }
          if (-1 < (int)uVar4) {
            uVar4 = 0xc00000e5;
          }
          goto LAB_14001538e;
        }
        p_Var6 = (_ALPC_MESSAGE_ATTRIBUTES *)ExAllocatePool2(0x40,local_res8,0x31444d55);
        this->m_MsgAttribBuffer = p_Var6;
        if (p_Var6 == (_ALPC_MESSAGE_ATTRIBUTES *)0x0) {
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0xf,
                    WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
          }
          uVar4 = 0xc0000017;
          goto LAB_14001538e;
        }
        uVar4 = (**(code **)((longlong)*this->m_LpcCorePortInterface + 0x30))
                          (this->m_LpcCorePortInterface,0x60000000,p_Var6,local_res8,&local_res8);
        if (-1 < (int)uVar4) {
          this->m_Notification = param_1->m_Notification;
          goto LAB_14001538e;
        }
        if (((WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) ||
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) == 0)) ||
           (*(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9) < 2)) goto LAB_14001538e;
        uVar7 = 0x10;
        goto LAB_140015372;
      }
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        uVar7 = 0xd;
        goto LAB_14001520a;
      }
    }
    uVar4 = 0xc000000d;
  }
LAB_14001538e:
  WdfCtorStatus::SetCtorStatus((WdfCtorStatus *)&this->_padding_,uVar4);
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    pwVar9 = L"success";
    if ((int)uVar4 < 0) {
      pwVar9 = L"failure";
    }
    WPP_SF_S(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x11,
             WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,pwVar9);
  }
  return this;
}



===== ~WdfLpcPort @ 140015400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

void __thiscall WdfLpcPort::~WdfLpcPort(WdfLpcPort *this)

{
  WPP_PROJECT_CONTROL_BLOCK *pWVar1;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *in_RDX;
  ulong in_R9D;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  this->_padding_ = (longlong)&_vftable__for__WdfObject__;
  this->_padding_ = (longlong)&_vftable__for__IUMDFLPCPortInterface__;
  pWVar1 = WPP_GLOBAL_Control;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    pWVar1 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
    in_RDX = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x12;
    WPP_SF_((ulong64)pWVar1,0x12,WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
  }
  WudfVerifyStatic((WdfComponentType)pWVar1,in_RDX,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcport.cpp",in_R9D,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,
                   in_stack_ffffffffffffffe0,"TODO: Write something interesting here",
                   this->m_Context == (void *)0x0);
  if (this->m_PortHandle != (void *)0x0) {
    (**(code **)((longlong)*this->m_LpcCorePortInterface + 0x28))();
  }
  if (this->m_MsgAttribBuffer != (_ALPC_MESSAGE_ATTRIBUTES *)0x0) {
    operator_delete(this->m_MsgAttribBuffer);
  }
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x13,
            WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
  }
  WdfObject::~WdfObject((WdfObject *)this);
  return;
}



===== `scalar_deleting_destructor' @ 140015500 =====

void * __thiscall WdfLpcPort::_scalar_deleting_destructor_(WdfLpcPort *this,uint param_1)

{
  ~WdfLpcPort(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== MarkForDelete`adjustor{88}' @ 140015540 =====

/* [thunk]:public: virtual void __cdecl WdfLpcPort::MarkForDelete`adjustor{88}' (void) __ptr64 */

void __thiscall WdfLpcPort::MarkForDelete_adjustor_88__(WdfLpcPort *this)

{
  WdfObject::MarkForDelete((WdfObject *)&this[-1]._padding_);
  return;
}



===== ProcessMessage @ 140015550 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

uchar __thiscall
WdfLpcPort::ProcessMessage
          (WdfLpcPort *this,_PORT_MESSAGE *param_1,_ALPC_MESSAGE_ATTRIBUTES *param_2)

{
  uchar uVar1;
  undefined8 *puVar2;
  ushort uVar3;
  WPP_PROJECT_CONTROL_BLOCK *pWVar4;
  WudfLpcMessage *this_00;
  ushort uVar5;
  _func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *p_Var6;
  <unnamed_type_u1> *p<Var7;
  uint uVar8;
  _GUID *p_Var9;
  ulong64 uVar10;
  ulong uVar11;
  _PORT_MESSAGE_u_8 *p_Var12;
  undefined1 auStackY_b8 [32];
  _ALPC_MESSAGE_ATTRIBUTES *in_stack_ffffffffffffff68;
  WdfDriverStopType in_stack_ffffffffffffff70;
  WdfErrorClass in_stack_ffffffffffffff78;
  ulong in_stack_ffffffffffffff80;
  <unnamed_type_u1> local_68 [2];
  _PORT_MESSAGE_u_8 local_60;
  undefined1 local_50;
  undefined1 local_4f;
  undefined2 local_4e;
  undefined4 local_4c;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  p_Var9 = (_GUID *)param_2;
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    p_Var9 = WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids;
    in_stack_ffffffffffffff68 = param_2;
    WPP_SF_qq(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x14,
              WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,param_1,param_2);
  }
  uVar8 = 0;
  puVar2 = (undefined8 *)AlpcGetMessageAttribute(param_2,0x20000000);
  p_Var6 = (_func___cdecl_void_WdfDriverStopType_ulong64_wchar_t_ptr_char_ptr *)0x40000000;
  if ((param_2->ValidAttributes & 0x40000000) != 0) {
    AlpcGetMessageAttribute(param_2);
  }
  uVar5 = (param_1->u2).s2.Type;
  uVar11 = (ulong)uVar5;
  uVar3 = uVar5 & 0xff;
  if (uVar3 == 1) {
LAB_14001589f:
    uVar1 = WdfLpc::ValidateMessage
                      ((_WUDFMESSAGE_HEADER *)(param_1 + 1),
                       (ulonglong)(ushort)(param_1->u1).s1.DataLength);
    if (uVar1 != '\0') {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_qd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x16,
                  WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,this->m_PortHandle,
                  (uint)*(_WUDFMESSAGE *)&param_1[1].u1.s1.DataLength);
      }
      (**(code **)((longlong)*this->m_Notification + 0x10))
                (this->m_Notification,&this->_padding_,param_1,(ushort)~(param_1->u2).s2.Type >> 0xf
                );
      goto LAB_14001599e;
    }
    if (WPP_GLOBAL_Control == (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) goto LAB_1400159d5;
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
      WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x15,
              WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
    }
  }
  else {
    if (uVar3 == 2) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
        WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x17,
                 WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,this->m_PortHandle);
      }
      this_00 = (WudfLpcMessage *)puVar2[1];
      if (this_00 == (WudfLpcMessage *)0x0) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          uVar5 = 0x18;
LAB_140015762:
          WPP_SF_(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),uVar5,
                  WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids);
        }
      }
      else {
        uVar10 = (ulong64)(param_1->u1).s1.DataLength;
        p<Var7 = &param_1[1].u1;
        p_Var12 = (_PORT_MESSAGE_u_8 *)&((_PORT_MESSAGE_u_8 *)0x0)->ClientId;
LAB_140015728:
        WudfLpcMessage::ReplyMessage
                  (this_00,(_WUDFMESSAGE_REPLY_HEADER *)&p<Var7->s1,uVar10,
                   (WUDF_PROBLEM *)&p_Var12->ClientId);
      }
    }
    else {
      if (uVar3 == 3) goto LAB_14001589f;
      if (uVar3 == 5) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1b,
                   WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,(void *)*puVar2);
        }
        (**(code **)*this->m_Notification)
                  (this->m_Notification,
                   -(ulonglong)(this != (WdfLpcPort *)0x0) & (ulonglong)&this[1]._padding_);
      }
      else if (uVar3 == 0xb) {
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1c,
                   WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,(void *)*puVar2);
        }
      }
      else {
        if (uVar3 != 0xc) {
          pWVar4 = WPP_GLOBAL_Control;
          if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
            pWVar4 = *(WPP_PROJECT_CONTROL_BLOCK **)((longlong)WPP_GLOBAL_Control + 0x1d8);
            uVar11 = uVar5 & 0xffff00ff;
            WPP_SF_L((ulong64)pWVar4,(ushort)p_Var6,p_Var9,uVar11);
          }
          WudfVerifyStatic((WdfComponentType)pWVar4,p_Var6,
                           L"minkernel\\wdf\\framework\\umdf\\common\\lpc\\lpcport.cpp",uVar11,
                           (char *)in_stack_ffffffffffffff68,in_stack_ffffffffffffff70,
                           in_stack_ffffffffffffff78,in_stack_ffffffffffffff80,
                           "Unknown Message Type",false);
          goto LAB_1400159a0;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          WPP_SF_q(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x19,
                   WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,this->m_PortHandle);
        }
        this_00 = (WudfLpcMessage *)puVar2[1];
        if (this_00 != (WudfLpcMessage *)0x0) {
          local_4c = 0xffffffff;
          local_60._4_4_ = *(undefined4 *)&this->m_Owner;
          local_4f = 0;
          local_60.ClientId.UniqueThread = (void *)0x70000000;
          local_4e = 0;
          local_48 = 0;
          local_50 = 0;
          if (*(char *)((longlong)&this_00->_padding_ + 4) == '\0') {
            local_60._0_4_ = 8;
          }
          else {
            local_60._0_4_ = 3;
            *(undefined1 *)((longlong)&this_00->_padding_ + 4) = 0;
          }
          local_68[0].Length = 0xc0000450;
          p_Var12 = &local_60;
          uVar10 = 4;
          p<Var7 = local_68;
          goto LAB_140015728;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x1e9))) {
          uVar5 = 0x1a;
          goto LAB_140015762;
        }
      }
    }
LAB_14001599e:
    uVar8 = 1;
  }
LAB_1400159a0:
  if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x1ec) & 0x80000010) == 0x80000010)) {
    WPP_SF_D(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0x1d8),0x1e,
             WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,uVar8);
  }
LAB_1400159d5:
  return (uchar)uVar8;
}



===== QueryInterface`adjustor{88}' @ 140015a10 =====

/* [thunk]:public: virtual long __cdecl WdfLpcPort::QueryInterface`adjustor{88}' (struct _GUID const
   & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
WdfLpcPort::QueryInterface_adjustor_88__(WdfLpcPort *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface((WdfLpcPort *)&this[-1]._padding_,param_1,param_2);
  return lVar1;
}



===== WPP_SF_L @ 140015a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WPP_SF_L(ulong64 param_1,ushort param_2,_GUID *param_3,ulong param_4)

{
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,0x1d);
  return;
}



===== WPP_SF_Sqqq @ 140015a6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl
WPP_SF_Sqqq(ulong64 param_1,ushort param_2,_GUID *param_3,wchar_t *param_4,void *param_5,
           void *param_6,void *param_7)

{
  longlong lVar1;
  
  if (param_4 != (wchar_t *)0x0) {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
  }
  (*pfnWppTraceMessage)(param_1,0x2b,WPP_44268908b01933520f9ff4c2ad2ebd94_Traceguids,10);
  return;
}



===== ~WdfLpcCorePortInterface @ 140015b1c =====

void __thiscall WdfLpcCorePortInterface::~WdfLpcCorePortInterface(WdfLpcCorePortInterface *this)

{
  CUMDFUnknown::~CUMDFUnknown((CUMDFUnknown *)this);
  WdfObjectLock::~WdfObjectLock((WdfObjectLock *)&this->field_0x18);
  return;
}



===== `scalar_deleting_destructor' @ 140015b40 =====

void * __thiscall
WdfLpcCorePortInterface::_scalar_deleting_destructor_(WdfLpcCorePortInterface *this,uint param_1)

{
  ~WdfLpcCorePortInterface(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== AcceptConnectPort @ 140015b80 =====

long __thiscall
WdfLpcCorePortInterface::AcceptConnectPort
          (WdfLpcCorePortInterface *this,void **param_1,void *param_2,ulong param_3,
          _OBJECT_ATTRIBUTES *param_4,_ALPC_PORT_ATTRIBUTES *param_5,void *param_6,
          _PORT_MESSAGE *param_7,_ALPC_MESSAGE_ATTRIBUTES *param_8,uchar param_9)

{
  long lVar1;
  
  lVar1 = ZwAlpcAcceptConnectPort
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return lVar1;
}



===== CancelMessage @ 140015c00 =====

long __thiscall
WdfLpcCorePortInterface::CancelMessage
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,_ALPC_CONTEXT_ATTR *param_3)

{
  long lVar1;
  
  lVar1 = ZwAlpcCancelMessage(param_1,param_2,param_3);
  return lVar1;
}



===== Connect @ 140015c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
WdfLpcCorePortInterface::Connect
          (WdfLpcCorePortInterface *this,void **param_1,wchar_t *param_2,void *param_3,
          _PORT_MESSAGE *param_4,uchar param_5,ulong64 param_6,IUMDFLPCCoreCallback *param_7)

{
  int iVar1;
  undefined1 auStackY_138 [32];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined8 local_84;
  uint local_7c;
  ulong64 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_b4 = 0;
  local_9c = 0;
  local_7c = (uint)(ushort)local_7c;
  local_c8 = 0;
  uStack_c0 = 0;
  local_48 = 0;
  if ((ushort)(param_4->u1).s1.TotalLength < 0x28) {
    iVar1 = -0x3ffffdfa;
  }
  else {
    RtlInitUnicodeString(&local_c8,param_2);
    local_68 = 0x400000;
    local_60 = 0x400000;
    local_58 = 0x400000;
    local_b8 = 0x30;
    local_b0 = 0;
    local_78 = 0x400;
    if (param_6 != 0) {
      local_78 = param_6;
    }
    local_a0 = 0x200;
    (param_4->u2).s2.Type = (param_4->u2).s2.Type | 0x8000;
    local_a8 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_7c = 0x101;
    local_48 = 0;
    local_50 = 0x2000000;
    local_70 = 0;
    local_84 = 0xc;
    local_88 = 0x120000;
    *param_1 = (void *)0x0;
    iVar1 = ZwAlpcConnectPort(param_1,&local_c8,&local_b8,&local_88);
    if (iVar1 != 0) {
      if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0xec) & 2) != 0)) &&
         (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0xe9))) {
        WPP_SF_Sd(*(ulong64 *)((longlong)WPP_GLOBAL_Control + 0xd8),10,
                  WPP_101c75e918e53c4c810fcd7019ed6f54_Traceguids,param_2,iVar1);
      }
      if (iVar1 == 0x102) {
        iVar1 = -0x3fffff4b;
      }
      else if ((-1 < iVar1) && (*param_1 == (void *)0x0)) {
        iVar1 = -0x3fffffff;
      }
    }
  }
  return iVar1;
}



===== CreatePortSection @ 140015e20 =====

long __thiscall
WdfLpcCorePortInterface::CreatePortSection
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,void *param_3,ulong64 param_4,
          void **param_5,ulong64 *param_6)

{
  long lVar1;
  
  lVar1 = ZwAlpcCreatePortSection(param_1,param_2,param_3,param_4,param_5,param_6);
  return lVar1;
}



===== CreateResourceReserve @ 140015e70 =====

long __thiscall
WdfLpcCorePortInterface::CreateResourceReserve
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,ulong64 param_3,ulong *param_4)

{
  long lVar1;
  
  lVar1 = ZwAlpcCreateResourceReserve(param_1,param_2,param_3,param_4);
  return lVar1;
}



===== CreateSectionView @ 140015ea0 =====

long __thiscall
WdfLpcCorePortInterface::CreateSectionView
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,_ALPC_DATA_VIEW_ATTR *param_3)

{
  long lVar1;
  
  lVar1 = ZwAlpcCreateSectionView(param_1,param_2,param_3);
  return lVar1;
}



===== CreateSecurityContext @ 140015ed0 =====

long __thiscall
WdfLpcCorePortInterface::CreateSecurityContext
          (WdfLpcCorePortInterface *this,void *param_1,_SECURITY_QUALITY_OF_SERVICE *param_2,
          void *param_3,void **param_4)

{
  int iVar1;
  undefined8 local_28;
  _SECURITY_QUALITY_OF_SERVICE *local_20;
  void *local_18;
  
  local_28 = 0;
  local_18 = (void *)0x0;
  *param_4 = (void *)0x0;
  local_20 = param_2;
  iVar1 = AlpcCreateSecurityContext(param_1,param_3,0,&local_28);
  if (-1 < iVar1) {
    *param_4 = local_18;
  }
  return iVar1;
}



===== DeletePort @ 140015f30 =====

void __thiscall WdfLpcCorePortInterface::DeletePort(WdfLpcCorePortInterface *this,void *param_1)

{
  ZwClose(param_1);
  return;
}



===== DeletePortSection @ 140015f50 =====

long __thiscall
WdfLpcCorePortInterface::DeletePortSection
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = ZwAlpcDeletePortSection(param_1,param_2,param_3);
  return lVar1;
}



===== DeleteResourceReserve @ 140015f80 =====

long __thiscall
WdfLpcCorePortInterface::DeleteResourceReserve
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  
  lVar1 = ZwAlpcDeleteResourceReserve(param_1,param_2,param_3);
  return lVar1;
}



===== DeleteSectionView @ 140015fb0 =====

long __thiscall
WdfLpcCorePortInterface::DeleteSectionView
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = ZwAlpcDeleteSectionView(param_1,param_2,param_3);
  return lVar1;
}



===== DeleteSecurityContext @ 140015fe0 =====

long __thiscall
WdfLpcCorePortInterface::DeleteSecurityContext
          (WdfLpcCorePortInterface *this,void *param_1,void *param_2)

{
  long lVar1;
  
  lVar1 = ZwAlpcDeleteSecurityContext(param_1,0);
  return lVar1;
}



===== DisconnectPort @ 140016010 =====

void __thiscall
WdfLpcCorePortInterface::DisconnectPort(WdfLpcCorePortInterface *this,void *param_1,ulong param_2)

{
  ZwAlpcDisconnectPort(param_1,param_2);
  return;
}



===== GetMessage @ 140016040 =====

long __thiscall
WdfLpcCorePortInterface::GetMessage
          (WdfLpcCorePortInterface *this,void *param_1,_PORT_MESSAGE *param_2,ulong64 *param_3,
          _ALPC_MESSAGE_ATTRIBUTES *param_4)

{
  long lVar1;
  
  lVar1 = ZwAlpcSendWaitReceivePort(param_1,0,0,0,param_2,param_3,param_4,0);
  return lVar1;
}



===== ImpersonateClientOfPort @ 140016080 =====

/* WARNING: Enum "WdfErrorClass": Some values do not have unique names */

long __thiscall
WdfLpcCorePortInterface::ImpersonateClientOfPort
          (WdfLpcCorePortInterface *this,void *param_1,_PORT_MESSAGE *param_2,
          _SECURITY_IMPERSONATION_LEVEL param_3,void *param_4)

{
  undefined3 in_register_00000089;
  char *in_stack_ffffffffffffffc8;
  WdfDriverStopType in_stack_ffffffffffffffd0;
  WdfErrorClass in_stack_ffffffffffffffd8;
  ulong in_stack_ffffffffffffffe0;
  
  WudfVerifyStatic((WdfComponentType)this,param_1,
                   L"minkernel\\wdf\\framework\\umdf\\common\\lpccoreclient\\lpccore.cpp",
                   CONCAT31(in_register_00000089,param_3),in_stack_ffffffffffffffc8,
                   in_stack_ffffffffffffffd0,in_stack_ffffffffffffffd8,in_stack_ffffffffffffffe0,
                   "not implemented",false);
  return -0x3ffffffe;
}



===== Listen @ 1400160c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __thiscall
WdfLpcCorePortInterface::Listen
          (WdfLpcCorePortInterface *this,wchar_t *param_1,void *param_2,ulong64 param_3,
          void **param_4)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  void *local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  void *local_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined8 local_84;
  uint local_7c;
  ulong64 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d8 = (void *)0x0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_bc = 0;
  local_a4 = 0;
  local_7c = (uint)(ushort)local_7c;
  local_48 = 0;
  RtlInitUnicodeString(&local_d0);
  local_c0 = 0x30;
  local_b0 = &local_d0;
  local_68 = 0x400000;
  local_60 = 0x400000;
  local_58 = 0x400000;
  local_b8 = 0;
  local_78 = 0x400;
  if (param_3 != 0) {
    local_78 = param_3;
  }
  local_a8 = 0x200;
  local_98 = 0;
  local_7c = 0x101;
  local_48 = 0;
  local_50 = 0x2000000;
  local_70 = 0;
  local_84 = 0xc;
  local_88 = 0x60000;
  local_a0 = param_2;
  iVar1 = ZwAlpcCreatePort(&local_d8,&local_c0,&local_88);
  if (-1 < iVar1) {
    *param_4 = local_d8;
  }
  return iVar1;
}



===== SendMessage @ 1400161d0 =====

long __thiscall
WdfLpcCorePortInterface::SendMessage
          (WdfLpcCorePortInterface *this,void *param_1,ulong param_2,_PORT_MESSAGE *param_3,
          _ALPC_MESSAGE_ATTRIBUTES *param_4)

{
  long lVar1;
  
  (param_3->u2).s2.Type = (param_3->u2).s2.Type | 0x8000;
  lVar1 = ZwAlpcSendWaitReceivePort(param_1,param_2,param_3,param_4,0,0,0,0);
  return lVar1;
}



===== SetInformation @ 140016230 =====

long __thiscall
WdfLpcCorePortInterface::SetInformation
          (WdfLpcCorePortInterface *this,void *param_1,_ALPC_PORT_INFORMATION_CLASS param_2,
          void *param_3,ulong param_4)

{
  long lVar1;
  
  lVar1 = ZwAlpcSetInformation(param_1,param_2,param_3,param_4);
  return lVar1;
}



===== s_CreateInstance @ 140016260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl WdfLpcCorePortInterface::s_CreateInstance(WdfLpcCorePortInterface **param_1)

{
  WdfLpcCorePortInterface *pWVar1;
  int iVar2;
  
  pWVar1 = (WdfLpcCorePortInterface *)ExAllocatePool2(0x40,0x30,0x48444d55);
  if (pWVar1 == (WdfLpcCorePortInterface *)0x0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    WdfObjectLock::WdfObjectLock((WdfObjectLock *)&pWVar1->field_0x18);
    *(undefined4 *)&pWVar1->field_0x8 = 1;
    *(undefined ***)pWVar1 = &_vftable__for__CUMDFUnknown__;
    *(undefined ***)&pWVar1->field_0x10 = &_vftable__for__IUMDFLPCCorePortInterface__;
    iVar2 = *(int *)&pWVar1->field_0x18;
    if (iVar2 < 0) {
      (**(code **)(*(longlong *)pWVar1 + 8))(pWVar1);
    }
    else {
      iVar2 = 0;
      *param_1 = pWVar1;
    }
  }
  return iVar2;
}



===== WdmlibRtlInitUnicodeStringEx @ 1400162f8 =====

long __cdecl WdmlibRtlInitUnicodeStringEx(_UNICODE_STRING *param_1,wchar_t *param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ushort uVar3;
  
  uVar3 = 0;
  if (param_2 == (wchar_t *)0x0) {
    param_2 = (wchar_t *)0x0;
    uVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (param_2[uVar2] != L'\0');
    if (0x7ffe < uVar2) {
      return -0x3ffffefa;
    }
    uVar1 = (short)uVar2 * 2;
    uVar3 = uVar1 + 2;
  }
  param_1->Length = uVar1;
  param_1->MaximumLength = uVar3;
  param_1->Buffer = param_2;
  return 0;
}



===== __GSHandlerCheck @ 140016348 =====

_EXCEPTION_DISPOSITION __cdecl
__GSHandlerCheck(_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
                _DISPATCHER_CONTEXT *param_4)

{
  __GSHandlerCheckCommon(param_2,param_4,param_4->HandlerData);
  return ExceptionContinueSearch;
}



===== __GSHandlerCheckCommon @ 14001636c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl
__GSHandlerCheckCommon(void *param_1,_DISPATCHER_CONTEXT *param_2,_GS_HANDLER_DATA *param_3)

{
  return;
}



===== __cpu_features_init @ 1400163e0 =====

/* WARNING: Removing unreachable block (ram,0x00014001644a) */
/* WARNING: Removing unreachable block (ram,0x0001400163f9) */
/* WARNING: Removing unreachable block (ram,0x0001400163ea) */

int __cdecl __cpu_features_init(void)

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
  __isa_info.info = bVar7 | 1;
  return 0;
}



===== __security_check_cookie @ 1400164b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(void)

{
  ulong64 in_RCX;
  
  if ((in_RCX != __security_cookie) || ((short)(in_RCX >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(in_RCX);
  }
  return;
}



===== _guard_dispatch_icall @ 1400164f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall_nop replaced with injection: guard_dispatch_icall */

void __cdecl _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall_nop @ 140016520 =====

/* WARNING: This is an inlined function */

void __cdecl _guard_dispatch_icall_nop(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140016520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140016550 =====

/* WARNING: Function: _guard_dispatch_icall_nop replaced with injection: guard_dispatch_icall */

void __cdecl _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1400165c0 =====

void __cdecl memcpy(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *in_RCX;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined8 *in_RDX;
  longlong lVar14;
  ulonglong in_R8;
  undefined1 *puVar15;
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
  
  if (in_R8 < 8) {
    if (in_R8 != 0) {
      puVar9 = in_RCX;
      if (in_RDX < in_RCX) {
        puVar15 = (undefined1 *)((longlong)in_RCX + in_R8);
        do {
          puVar2 = puVar15 + ((longlong)in_RDX - (longlong)in_RCX) + -1;
          puVar15 = puVar15 + -1;
          in_R8 = in_R8 - 1;
          *puVar15 = *puVar2;
        } while (in_R8 != 0);
        return;
      }
      do {
        in_R8 = in_R8 - 1;
        *(undefined1 *)puVar9 =
             *(undefined1 *)((longlong)puVar9 + ((longlong)in_RDX - (longlong)in_RCX));
        puVar9 = (undefined8 *)((longlong)puVar9 + 1);
      } while (in_R8 != 0);
    }
    return;
  }
  if (in_R8 < 0x11) {
    uVar3 = *(undefined8 *)((longlong)in_RDX + (in_R8 - 8));
    *in_RCX = *in_RDX;
    *(undefined8 *)((longlong)in_RCX + (in_R8 - 8)) = uVar3;
    return;
  }
  if (in_R8 < 0x21) {
    uVar3 = in_RDX[1];
    puVar9 = (undefined8 *)((longlong)in_RDX + (in_R8 - 0x10));
    uVar4 = *puVar9;
    uVar5 = puVar9[1];
    *in_RCX = *in_RDX;
    in_RCX[1] = uVar3;
    puVar9 = (undefined8 *)((longlong)in_RCX + (in_R8 - 0x10));
    *puVar9 = uVar4;
    puVar9[1] = uVar5;
    return;
  }
  lVar14 = (longlong)in_RDX - (longlong)in_RCX;
  if ((in_RDX < in_RCX) && (in_RCX < (undefined8 *)((longlong)in_RDX + in_R8))) {
    puVar13 = (undefined4 *)((longlong)in_RCX + lVar14 + (in_R8 - 0x10));
    uVar18 = puVar13[1];
    uVar20 = puVar13[2];
    uVar22 = puVar13[3];
    puVar11 = (undefined4 *)((longlong)in_RCX + (in_R8 - 0x10));
    uVar16 = in_R8 - 0x10;
    puVar12 = puVar11;
    uVar19 = *puVar13;
    uVar21 = uVar18;
    uVar23 = uVar20;
    uVar25 = uVar22;
    if (((ulonglong)puVar11 & 0xf) != 0) {
      puVar12 = (undefined4 *)((ulonglong)puVar11 & 0xfffffffffffffff0);
      puVar1 = (undefined4 *)((longlong)puVar12 + lVar14);
      uVar19 = *puVar1;
      uVar21 = puVar1[1];
      uVar23 = puVar1[2];
      uVar25 = puVar1[3];
      *puVar11 = *puVar13;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 0xc)) = uVar18;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 8)) = uVar20;
      *(undefined4 *)((longlong)in_RCX + (in_R8 - 4)) = uVar22;
      uVar16 = (longlong)puVar12 - (longlong)in_RCX;
    }
    uVar17 = uVar16 >> 6;
    if (uVar17 != 0) {
      uVar16 = uVar16 & 0x3f;
      puVar13 = puVar12;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x10);
        uVar3 = *puVar9;
        uVar4 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x20);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar13 + lVar14 + -0x30);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar12 = (undefined4 *)((longlong)puVar13 + lVar14 + -0x40);
        uVar19 = *puVar12;
        uVar21 = puVar12[1];
        uVar23 = puVar12[2];
        uVar25 = puVar12[3];
        *puVar13 = uVar18;
        puVar13[1] = uVar20;
        puVar13[2] = uVar22;
        puVar13[3] = uVar24;
        puVar12 = puVar13 + -0x10;
        uVar17 = uVar17 - 1;
        *(undefined8 *)(puVar13 + -4) = uVar3;
        *(undefined8 *)(puVar13 + -2) = uVar4;
        *(undefined8 *)(puVar13 + -8) = uVar5;
        *(undefined8 *)(puVar13 + -6) = uVar6;
        *(undefined8 *)(puVar13 + -0xc) = uVar7;
        *(undefined8 *)(puVar13 + -10) = uVar8;
        puVar13 = puVar12;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar17 != 0);
    }
    for (uVar17 = uVar16 >> 4; uVar17 != 0; uVar17 = uVar17 - 1) {
      *puVar12 = uVar19;
      puVar12[1] = uVar21;
      puVar12[2] = uVar23;
      puVar12[3] = uVar25;
      puVar13 = (undefined4 *)((longlong)puVar12 + lVar14 + -0x10);
      uVar19 = *puVar13;
      uVar21 = puVar13[1];
      uVar23 = puVar13[2];
      uVar25 = puVar13[3];
      puVar12 = puVar12 + -4;
    }
    if ((uVar16 & 0xf) != 0) {
      puVar9 = (undefined8 *)((longlong)puVar12 - (uVar16 & 0xf));
      uVar3 = ((undefined8 *)((longlong)puVar9 + lVar14))[1];
      *puVar9 = *(undefined8 *)((longlong)puVar9 + lVar14);
      puVar9[1] = uVar3;
    }
    *puVar12 = uVar19;
    puVar12[1] = uVar21;
    puVar12[2] = uVar23;
    puVar12[3] = uVar25;
    return;
  }
  puVar13 = (undefined4 *)((longlong)in_RCX + lVar14);
  uVar18 = puVar13[1];
  uVar20 = puVar13[2];
  uVar22 = puVar13[3];
  puVar9 = in_RCX + 2;
  uVar19 = *puVar13;
  uVar21 = uVar18;
  uVar23 = uVar20;
  uVar25 = uVar22;
  if (((ulonglong)puVar9 & 0xf) != 0) {
    puVar12 = (undefined4 *)(((ulonglong)puVar9 & 0xfffffffffffffff0) + lVar14);
    uVar19 = *puVar12;
    uVar21 = puVar12[1];
    uVar23 = puVar12[2];
    uVar25 = puVar12[3];
    *(undefined4 *)in_RCX = *puVar13;
    *(undefined4 *)((longlong)in_RCX + 4) = uVar18;
    *(undefined4 *)(in_RCX + 1) = uVar20;
    *(undefined4 *)((longlong)in_RCX + 0xc) = uVar22;
    puVar9 = (undefined8 *)(((ulonglong)puVar9 & 0xfffffffffffffff0) + 0x10);
  }
  puVar15 = (undefined1 *)((longlong)in_RCX + (in_R8 - (longlong)puVar9));
  uVar16 = (ulonglong)puVar15 >> 6;
  if (uVar16 != 0) {
    if (uVar16 < 0x1001) {
      puVar15 = (undefined1 *)((ulonglong)puVar15 & 0x3f);
      puVar10 = puVar9;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar10 + lVar14);
        uVar4 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x20);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar13 = (undefined4 *)((longlong)puVar10 + lVar14 + 0x30);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *(undefined4 *)(puVar10 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar10 + -0xc) = uVar20;
        *(undefined4 *)(puVar10 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar10 + -4) = uVar24;
        puVar9 = puVar10 + 8;
        uVar16 = uVar16 - 1;
        *puVar10 = uVar3;
        puVar10[1] = uVar4;
        puVar10[2] = uVar5;
        puVar10[3] = uVar6;
        puVar10[4] = uVar7;
        puVar10[5] = uVar8;
        puVar10 = puVar9;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar16 != 0);
    }
    else {
      uVar16 = (ulonglong)puVar15 >> 6;
      puVar15 = (undefined1 *)((ulonglong)puVar15 & 0x3f);
      puVar10 = puVar9;
      uVar18 = uVar19;
      uVar20 = uVar21;
      uVar22 = uVar23;
      uVar24 = uVar25;
      do {
        uVar3 = *(undefined8 *)((longlong)puVar10 + lVar14);
        uVar4 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + lVar14 + 0x20);
        uVar7 = *puVar9;
        uVar8 = puVar9[1];
        puVar13 = (undefined4 *)((longlong)puVar10 + lVar14 + 0x30);
        uVar19 = *puVar13;
        uVar21 = puVar13[1];
        uVar23 = puVar13[2];
        uVar25 = puVar13[3];
        *(undefined4 *)(puVar10 + -2) = uVar18;
        *(undefined4 *)((longlong)puVar10 + -0xc) = uVar20;
        *(undefined4 *)(puVar10 + -1) = uVar22;
        *(undefined4 *)((longlong)puVar10 + -4) = uVar24;
        puVar9 = puVar10 + 8;
        uVar16 = uVar16 - 1;
        *puVar10 = uVar3;
        puVar10[1] = uVar4;
        puVar10[2] = uVar5;
        puVar10[3] = uVar6;
        puVar10[4] = uVar7;
        puVar10[5] = uVar8;
        puVar10 = puVar9;
        uVar18 = uVar19;
        uVar20 = uVar21;
        uVar22 = uVar23;
        uVar24 = uVar25;
      } while (uVar16 != 0);
    }
  }
  for (uVar16 = (ulonglong)puVar15 >> 4; uVar16 != 0; uVar16 = uVar16 - 1) {
    *(undefined4 *)(puVar9 + -2) = uVar19;
    *(undefined4 *)((longlong)puVar9 + -0xc) = uVar21;
    *(undefined4 *)(puVar9 + -1) = uVar23;
    *(undefined4 *)((longlong)puVar9 + -4) = uVar25;
    puVar13 = (undefined4 *)((longlong)puVar9 + lVar14);
    uVar19 = *puVar13;
    uVar21 = puVar13[1];
    uVar23 = puVar13[2];
    uVar25 = puVar13[3];
    puVar9 = puVar9 + 2;
  }
  if (((ulonglong)puVar15 & 0xf) != 0) {
    puVar10 = (undefined8 *)((longlong)puVar9 + (((ulonglong)puVar15 & 0xf) - 0x10));
    uVar3 = ((undefined8 *)((longlong)puVar10 + lVar14))[1];
    *puVar10 = *(undefined8 *)((longlong)puVar10 + lVar14);
    puVar10[1] = uVar3;
  }
  *(undefined4 *)(puVar9 + -2) = uVar19;
  *(undefined4 *)((longlong)puVar9 + -0xc) = uVar21;
  *(undefined4 *)(puVar9 + -1) = uVar23;
  *(undefined4 *)((longlong)puVar9 + -4) = uVar25;
  return;
}



===== memset @ 1400168c0 =====

void __cdecl memset(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 *in_R8;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  longlong extraout_XMM0_Qa;
  longlong lVar9;
  longlong extraout_XMM0_Qb;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar6 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar6) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar6) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    if (((__isa_info.info & 2) != 0) && ((undefined1 *)0x31f < in_R8)) {
      lVar9 = lVar4;
      if ((__isa_info.info & 1) == 0) {
        __memset_query();
        lVar4 = extraout_XMM0_Qa;
        lVar9 = extraout_XMM0_Qb;
      }
      *in_RCX = lVar4;
      in_RCX[1] = lVar9;
      in_RCX[2] = lVar4;
      in_RCX[3] = lVar9;
      in_RCX[4] = lVar4;
      in_RCX[5] = lVar9;
      in_RCX[6] = lVar4;
      in_RCX[7] = lVar9;
      puVar5 = (undefined1 *)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0);
      for (puVar7 = (undefined1 *)
                    ((longlong)in_RCX +
                    ((longlong)in_R8 - (longlong)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0)));
          puVar7 != (undefined1 *)0x0; puVar7 = puVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return;
    }
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
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
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar6 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar6);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== __memset_repmovs @ 140016a00 =====

void __cdecl __memset_repmovs(void)

{
  undefined1 *in_RCX;
  undefined1 *puVar1;
  longlong in_R8;
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
  
  if ((__isa_info.info & 1) == 0) {
    __memset_query();
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
  *in_RCX = in_XMM0_Ba;
  in_RCX[1] = in_XMM0_Bb;
  in_RCX[2] = in_XMM0_Bc;
  in_RCX[3] = in_XMM0_Bd;
  in_RCX[4] = in_XMM0_Be;
  in_RCX[5] = in_XMM0_Bf;
  in_RCX[6] = in_XMM0_Bg;
  in_RCX[7] = in_XMM0_Bh;
  in_RCX[8] = in_XMM0_Bi;
  in_RCX[9] = in_XMM0_Bj;
  in_RCX[10] = in_XMM0_Bk;
  in_RCX[0xb] = in_XMM0_Bl;
  in_RCX[0xc] = in_XMM0_Bm;
  in_RCX[0xd] = in_XMM0_Bn;
  in_RCX[0xe] = in_XMM0_Bo;
  in_RCX[0xf] = in_XMM0_Bp;
  in_RCX[0x10] = in_XMM0_Ba;
  in_RCX[0x11] = in_XMM0_Bb;
  in_RCX[0x12] = in_XMM0_Bc;
  in_RCX[0x13] = in_XMM0_Bd;
  in_RCX[0x14] = in_XMM0_Be;
  in_RCX[0x15] = in_XMM0_Bf;
  in_RCX[0x16] = in_XMM0_Bg;
  in_RCX[0x17] = in_XMM0_Bh;
  in_RCX[0x18] = in_XMM0_Bi;
  in_RCX[0x19] = in_XMM0_Bj;
  in_RCX[0x1a] = in_XMM0_Bk;
  in_RCX[0x1b] = in_XMM0_Bl;
  in_RCX[0x1c] = in_XMM0_Bm;
  in_RCX[0x1d] = in_XMM0_Bn;
  in_RCX[0x1e] = in_XMM0_Bo;
  in_RCX[0x1f] = in_XMM0_Bp;
  in_RCX[0x20] = in_XMM0_Ba;
  in_RCX[0x21] = in_XMM0_Bb;
  in_RCX[0x22] = in_XMM0_Bc;
  in_RCX[0x23] = in_XMM0_Bd;
  in_RCX[0x24] = in_XMM0_Be;
  in_RCX[0x25] = in_XMM0_Bf;
  in_RCX[0x26] = in_XMM0_Bg;
  in_RCX[0x27] = in_XMM0_Bh;
  in_RCX[0x28] = in_XMM0_Bi;
  in_RCX[0x29] = in_XMM0_Bj;
  in_RCX[0x2a] = in_XMM0_Bk;
  in_RCX[0x2b] = in_XMM0_Bl;
  in_RCX[0x2c] = in_XMM0_Bm;
  in_RCX[0x2d] = in_XMM0_Bn;
  in_RCX[0x2e] = in_XMM0_Bo;
  in_RCX[0x2f] = in_XMM0_Bp;
  in_RCX[0x30] = in_XMM0_Ba;
  in_RCX[0x31] = in_XMM0_Bb;
  in_RCX[0x32] = in_XMM0_Bc;
  in_RCX[0x33] = in_XMM0_Bd;
  in_RCX[0x34] = in_XMM0_Be;
  in_RCX[0x35] = in_XMM0_Bf;
  in_RCX[0x36] = in_XMM0_Bg;
  in_RCX[0x37] = in_XMM0_Bh;
  in_RCX[0x38] = in_XMM0_Bi;
  in_RCX[0x39] = in_XMM0_Bj;
  in_RCX[0x3a] = in_XMM0_Bk;
  in_RCX[0x3b] = in_XMM0_Bl;
  in_RCX[0x3c] = in_XMM0_Bm;
  in_RCX[0x3d] = in_XMM0_Bn;
  in_RCX[0x3e] = in_XMM0_Bo;
  in_RCX[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = in_RCX + (in_R8 - (longlong)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return;
}



===== __memset_query @ 140016a80 =====

void __cdecl __memset_query(void)

{
  __cpu_features_init();
  return;
}



===== __memset_spec_ermsb @ 140016b00 =====

void __cdecl __memset_spec_ermsb(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined1 *in_R8;
  ulonglong uVar6;
  undefined1 *puVar7;
  longlong *plVar8;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar6 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar6) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar6) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    if ((undefined1 *)0x31f < in_R8) {
      *in_RCX = lVar4;
      in_RCX[1] = lVar4;
      in_RCX[2] = lVar4;
      in_RCX[3] = lVar4;
      in_RCX[4] = lVar4;
      in_RCX[5] = lVar4;
      in_RCX[6] = lVar4;
      in_RCX[7] = lVar4;
      puVar5 = (undefined1 *)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0);
      for (puVar7 = (undefined1 *)
                    ((longlong)in_RCX +
                    ((longlong)in_R8 - (longlong)((ulonglong)(in_RCX + 8) & 0xffffffffffffffc0)));
          puVar7 != (undefined1 *)0x0; puVar7 = puVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return;
    }
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
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
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar6 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar6);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== __memset_spec_ermsb_repmovsb @ 140016c40 =====

void __cdecl __memset_spec_ermsb_repmovsb(void)

{
  undefined1 *in_RCX;
  undefined1 *puVar1;
  longlong in_R8;
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
  
  *in_RCX = in_XMM0_Ba;
  in_RCX[1] = in_XMM0_Bb;
  in_RCX[2] = in_XMM0_Bc;
  in_RCX[3] = in_XMM0_Bd;
  in_RCX[4] = in_XMM0_Be;
  in_RCX[5] = in_XMM0_Bf;
  in_RCX[6] = in_XMM0_Bg;
  in_RCX[7] = in_XMM0_Bh;
  in_RCX[8] = in_XMM0_Bi;
  in_RCX[9] = in_XMM0_Bj;
  in_RCX[10] = in_XMM0_Bk;
  in_RCX[0xb] = in_XMM0_Bl;
  in_RCX[0xc] = in_XMM0_Bm;
  in_RCX[0xd] = in_XMM0_Bn;
  in_RCX[0xe] = in_XMM0_Bo;
  in_RCX[0xf] = in_XMM0_Bp;
  in_RCX[0x10] = in_XMM0_Ba;
  in_RCX[0x11] = in_XMM0_Bb;
  in_RCX[0x12] = in_XMM0_Bc;
  in_RCX[0x13] = in_XMM0_Bd;
  in_RCX[0x14] = in_XMM0_Be;
  in_RCX[0x15] = in_XMM0_Bf;
  in_RCX[0x16] = in_XMM0_Bg;
  in_RCX[0x17] = in_XMM0_Bh;
  in_RCX[0x18] = in_XMM0_Bi;
  in_RCX[0x19] = in_XMM0_Bj;
  in_RCX[0x1a] = in_XMM0_Bk;
  in_RCX[0x1b] = in_XMM0_Bl;
  in_RCX[0x1c] = in_XMM0_Bm;
  in_RCX[0x1d] = in_XMM0_Bn;
  in_RCX[0x1e] = in_XMM0_Bo;
  in_RCX[0x1f] = in_XMM0_Bp;
  in_RCX[0x20] = in_XMM0_Ba;
  in_RCX[0x21] = in_XMM0_Bb;
  in_RCX[0x22] = in_XMM0_Bc;
  in_RCX[0x23] = in_XMM0_Bd;
  in_RCX[0x24] = in_XMM0_Be;
  in_RCX[0x25] = in_XMM0_Bf;
  in_RCX[0x26] = in_XMM0_Bg;
  in_RCX[0x27] = in_XMM0_Bh;
  in_RCX[0x28] = in_XMM0_Bi;
  in_RCX[0x29] = in_XMM0_Bj;
  in_RCX[0x2a] = in_XMM0_Bk;
  in_RCX[0x2b] = in_XMM0_Bl;
  in_RCX[0x2c] = in_XMM0_Bm;
  in_RCX[0x2d] = in_XMM0_Bn;
  in_RCX[0x2e] = in_XMM0_Bo;
  in_RCX[0x2f] = in_XMM0_Bp;
  in_RCX[0x30] = in_XMM0_Ba;
  in_RCX[0x31] = in_XMM0_Bb;
  in_RCX[0x32] = in_XMM0_Bc;
  in_RCX[0x33] = in_XMM0_Bd;
  in_RCX[0x34] = in_XMM0_Be;
  in_RCX[0x35] = in_XMM0_Bf;
  in_RCX[0x36] = in_XMM0_Bg;
  in_RCX[0x37] = in_XMM0_Bh;
  in_RCX[0x38] = in_XMM0_Bi;
  in_RCX[0x39] = in_XMM0_Bj;
  in_RCX[0x3a] = in_XMM0_Bk;
  in_RCX[0x3b] = in_XMM0_Bl;
  in_RCX[0x3c] = in_XMM0_Bm;
  in_RCX[0x3d] = in_XMM0_Bn;
  in_RCX[0x3e] = in_XMM0_Bo;
  in_RCX[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = in_RCX + (in_R8 - (longlong)((ulonglong)(in_RCX + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return;
}



===== __memset_spec_plain @ 140016cc0 =====

void __cdecl __memset_spec_plain(void)

{
  longlong *in_RCX;
  longlong *plVar1;
  longlong *plVar2;
  byte in_DL;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *in_R8;
  ulonglong uVar5;
  longlong *plVar6;
  
  lVar4 = (ulonglong)in_DL * 0x101010101010101;
  if (in_R8 < (undefined1 *)0x40) {
    if (in_R8 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < in_R8) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)in_RCX = uVar3;
        uVar5 = ((ulonglong)in_R8 & 8) >> 1;
        *(undefined4 *)(in_R8 + -4 + (longlong)in_RCX) = uVar3;
        *(undefined4 *)((longlong)in_RCX + uVar5) = uVar3;
        *(undefined4 *)((longlong)(in_R8 + -4 + (longlong)in_RCX) - uVar5) = uVar3;
        return;
      }
      if (in_R8 != (undefined1 *)0x0) {
        *(char *)in_RCX = (char)lVar4;
        if (in_R8 != (undefined1 *)0x1) {
          *(short *)((longlong)in_RCX + (longlong)(in_R8 + -2)) = (short)lVar4;
        }
      }
      return;
    }
  }
  else {
    *in_RCX = lVar4;
    in_RCX[1] = lVar4;
    plVar1 = (longlong *)((ulonglong)(in_RCX + 2) & 0xfffffffffffffff0);
    in_R8 = (undefined1 *)((longlong)in_RCX + ((longlong)in_R8 - (longlong)plVar1));
    in_RCX = plVar1;
    if ((undefined1 *)0x3f < in_R8) {
      plVar6 = (longlong *)
               ((ulonglong)((longlong)plVar1 + (longlong)(in_R8 + -0x30)) & 0xfffffffffffffff0);
      uVar5 = (ulonglong)in_R8 >> 6;
      plVar2 = plVar1;
      do {
        *plVar2 = lVar4;
        plVar2[1] = lVar4;
        plVar2[2] = lVar4;
        plVar2[3] = lVar4;
        uVar5 = uVar5 - 1;
        plVar2[4] = lVar4;
        plVar2[5] = lVar4;
        plVar2[6] = lVar4;
        plVar2[7] = lVar4;
        plVar2 = plVar2 + 8;
      } while (uVar5 != 0);
      *plVar6 = lVar4;
      plVar6[1] = lVar4;
      plVar6[2] = lVar4;
      plVar6[3] = lVar4;
      plVar6[4] = lVar4;
      plVar6[5] = lVar4;
      *(longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)) = lVar4;
      ((longlong *)((longlong)plVar1 + (longlong)(in_R8 + -0x10)))[1] = lVar4;
      return;
    }
  }
  plVar2 = (longlong *)(in_R8 + -0x10 + (longlong)in_RCX);
  *in_RCX = lVar4;
  in_RCX[1] = lVar4;
  uVar5 = ((ulonglong)in_R8 & 0x20) >> 1;
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar1 = (longlong *)((longlong)in_RCX + uVar5);
  *plVar1 = lVar4;
  plVar1[1] = lVar4;
  plVar2 = (longlong *)((longlong)plVar2 - uVar5);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  return;
}



===== WppCleanupKm @ 140021008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppCleanupKm(_DRIVER_OBJECT *param_1)

{
  WPP_PROJECT_CONTROL_BLOCK *pWVar1;
  
  if (WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) {
    pWVar1 = (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control->Control;
    if (WPPTraceSuite == WppTraceServer08) {
      for (; pWVar1 != (WPP_PROJECT_CONTROL_BLOCK *)0x0;
          pWVar1 = (WPP_PROJECT_CONTROL_BLOCK *)(pWVar1->Control).Next) {
        if ((pWVar1->Control).RegHandle != 0) {
          (*pfnEtwUnregister)((pWVar1->Control).RegHandle);
          (pWVar1->Control).RegHandle = 0;
        }
      }
    }
    else if (WPPTraceSuite == WppTraceWinXP) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 140021088 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppInitKm(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  _func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
  *p_Var1;
  WPP_PROJECT_CONTROL_BLOCK *pWVar2;
  
  pWVar2 = WPP_MAIN_CB;
  if (WPP_GLOBAL_Control != WPP_MAIN_CB) {
    WPP_GLOBAL_Control = WPP_MAIN_CB;
    if (WPPTraceSuite == WppTraceServer08) {
      do {
        p_Var1 = pfnEtwRegisterClassicProvider;
        (pWVar2->Control).RegHandle = 0;
        (*p_Var1)((pWVar2->Control).ControlGuid,0,WppClassicProviderCallback,pWVar2,
                  &(pWVar2->Control).RegHandle);
        pWVar2 = (WPP_PROJECT_CONTROL_BLOCK *)(pWVar2->Control).Next;
      } while (pWVar2 != (WPP_PROJECT_CONTROL_BLOCK *)0x0);
    }
    else if (WPPTraceSuite == WppTraceWinXP) {
      WPP_MAIN_CB[0].Control.Callback = WppTraceCallback;
      IoWMIRegistrationControl(WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== WppLoadTracingSupport @ 140021118 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void __cdecl WppLoadTracingSupport(void)

{
  ulong local_res8 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"PsGetVersion");
  pfnWppGetVersion =
       (_func___cdecl_uchar_ulong_ptr_ulong_ptr_ulong_ptr__UNICODE_STRING_ptr *)
       MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiTraceMessage");
  pfnWppTraceMessage =
       (_func___cdecl_long_ulong64_ulong__GUID_ptr_ushort *)MmGetSystemRoutineAddress(&local_18);
  RtlInitUnicodeString(&local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation =
       (_func___cdecl_long__TRACE_INFORMATION_CLASS_void_ptr_ulong_ulong_ptr_void_ptr *)
       MmGetSystemRoutineAddress(&local_18);
  WPPTraceSuite = WppTraceWinXP;
  if (pfnWppGetVersion !=
      (_func___cdecl_uchar_ulong_ptr_ulong_ptr_ulong_ptr__UNICODE_STRING_ptr *)0x0) {
    (*pfnWppGetVersion)(local_res8,(ulong *)0x0,(ulong *)0x0,(_UNICODE_STRING *)0x0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider =
         (_func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
          *)MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider !=
        (_func___cdecl_long__GUID_ptr_ulong__func___cdecl_void__GUID_ptr_uchar_void_ptr_void_ptr_ptr_void_ptr_ulong64_ptr
         *)0x0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = (_func___cdecl_long_ulong64 *)MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = WppTraceServer08;
    }
  }
  return;
}



===== WppTraceCallback @ 140021260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Enum "_TRACE_INFORMATION_CLASS": Some values do not have unique names */

long __cdecl
WppTraceCallback(uchar param_1,void *param_2,ulong param_3,void *param_4,void *param_5,
                ulong *param_6)

{
  int *piVar1;
  undefined8 uVar2;
  ushort *puVar3;
  undefined8 uVar4;
  ulong *puVar5;
  long lVar6;
  void *pvVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar5 = param_6;
  *param_6 = 0;
  if (param_1 < 6) {
    if ((param_1 == '\x05') ||
       ((((param_1 != '\0' && (param_1 != '\x01')) && (param_1 != '\x02')) &&
        ((param_1 != '\x03' && (param_1 == '\x04')))))) {
      local_res8[0] = 0;
      param_6._0_4_ = 0;
      if (param_5 != (void *)0x0) {
        if (param_3 < 0x30) {
          return -0x3ffffff3;
        }
        do {
          piVar1 = *(int **)((longlong)param_5 + 8);
          if (((*piVar1 == *(int *)((longlong)param_4 + 0x18)) &&
              (piVar1[1] == *(int *)((longlong)param_4 + 0x1c))) &&
             ((piVar1[2] == *(int *)((longlong)param_4 + 0x20) &&
              (piVar1[3] == *(int *)((longlong)param_4 + 0x24))))) break;
          param_5 = *(void **)((longlong)param_5 + 0x10);
        } while (param_5 != (void *)0x0);
        if (param_5 != (void *)0x0) {
          if (param_1 == '\x05') {
            *(undefined4 *)((longlong)param_5 + 0x2c) = 0;
            *(undefined8 *)((longlong)param_5 + 0x18) = 0;
            *(undefined1 *)((longlong)param_5 + 0x29) = 0;
            return 0;
          }
          bVar13 = WPPTraceSuite != WppTraceWinXP;
          uVar2 = *(undefined8 *)((longlong)param_4 + 8);
          *(undefined8 *)((longlong)param_5 + 0x18) = uVar2;
          if (bVar13) {
            uStack_34 = (undefined4)((ulonglong)uVar2 >> 0x20);
            *(undefined4 *)((longlong)param_5 + 0x2c) = uStack_34;
            uStack_36 = (undefined1)((ulonglong)uVar2 >> 0x10);
            *(undefined1 *)((longlong)param_5 + 0x29) = uStack_36;
            return 0;
          }
          lVar6 = (*pfnWppQueryTraceInformation)
                            (TraceEnableLevelClass,local_res8,4,(ulong *)&param_6,param_4);
          if (lVar6 == 0) {
            *(undefined1 *)((longlong)param_5 + 0x29) = (undefined1)local_res8[0];
          }
          lVar6 = (*pfnWppQueryTraceInformation)
                            (TraceEnableFlagsClass,(void *)((longlong)param_5 + 0x2c),4,
                             (ulong *)&param_6,param_4);
          return lVar6;
        }
      }
      return -0x3ffffd6b;
    }
  }
  else {
    if (param_1 == '\x06') {
      return 0;
    }
    if (param_1 == '\a') {
      return 0;
    }
    if (param_1 == '\b') {
      uVar10 = 0;
      puVar3 = *(ushort **)((longlong)param_5 + 0x20);
      pvVar7 = param_5;
      do {
        pvVar7 = *(void **)((longlong)pvVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (pvVar7 != (void *)0x0);
      if (0x3f < uVar10) {
        return -0x3ffffff3;
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
          return -0x3fffffdd;
        }
        *(uint *)param_4 = uVar12;
        *param_6 = 4;
        return -0x3fffffdd;
      }
      memset();
      *(uint *)param_4 = uVar12;
      *(uint *)((longlong)param_4 + 8) = uVar11;
      *(uint *)((longlong)param_4 + 0x10) = uVar10;
      if (puVar3 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar11 + (longlong)param_4) = *puVar3;
        memcpy();
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar9 = (undefined4 *)((longlong)param_4 + 0x28);
        do {
          uVar2 = **(undefined8 **)((longlong)param_5 + 8);
          uVar4 = (*(undefined8 **)((longlong)param_5 + 8))[1];
          *puVar9 = 0x81000;
          *(undefined8 *)(puVar9 + -4) = uVar2;
          *(undefined8 *)(puVar9 + -2) = uVar4;
          *(undefined1 *)((longlong)param_5 + 0x29) = 0;
          *(undefined4 *)((longlong)param_5 + 0x2c) = 0;
          param_5 = *(void **)((longlong)param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 8;
        } while (uVar8 != 0);
      }
      *puVar5 = uVar12;
      return 0;
    }
  }
  return -0x3ffffff0;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 1400214e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
wil_RtlStagingConfig_QueryFeatureState
          (wil_FeatureState *param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    param_1->enabledState =
         local_20._4_4_ >> 4 & (wil_FeatureEnabledState_Enabled|wil_FeatureEnabledState_Disabled);
    param_1->variant = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1->payload = local_18;
    param_1->payloadKind =
         local_20._4_4_ >> 0xe &
         (wil_FeatureVariantPayloadKind_External|wil_FeatureVariantPayloadKind_Resident);
    param_1->isWexpConfiguration = local_20._4_4_ >> 6 & 1;
    param_1->hasNotification = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1->hasNotification = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400215b4 =====

void __cdecl
wil_details_BuildFeatureStateCacheFromQueryResults
          (long param_1,_RTL_FEATURE_CONFIGURATION *param_2,wil_details_FeatureStateCache *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3->exchange64 = 0;
  }
  else {
    param_3->exchange64 = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)&param_2->field_0x4 & 0x40) << 2 | *(uint *)&param_2->field_0x4 & 0xb0) <<
              3 | 0x206;
      goto LAB_140021611;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)&param_2->field_0x4 & 0x80) << 3 | 0x206;
      goto LAB_140021611;
    }
  }
  uVar1 = 0x206;
LAB_140021611:
  param_3->exchange = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14002161c =====

void __cdecl wil_details_EvaluateFeatureDependencies(void)

{
  wil_details_FeatureDescriptor *pwVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  pwVar1 = wil_details_FeatureDescriptors_SkipPadding(0x14001bb90);
  if (pwVar1 != (wil_details_FeatureDescriptor *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = pwVar1->featureStateCache->exchange;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = pwVar1->isEnabledByDefault != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        pwVar1->featureStateCache->exchange = pwVar1->featureStateCache->exchange ^ uVar2;
        UNLOCK();
      }
      pwVar1 = wil_details_FeatureDescriptors_SkipPadding((ulong64)(pwVar1 + 1));
    } while (pwVar1 != (wil_details_FeatureDescriptor *)0x0);
  }
  pwVar1 = &Feature_GatePerf__private_descriptor;
  while( true ) {
    pwVar1 = wil_details_FeatureDescriptors_SkipPadding((ulong64)pwVar1);
    if (pwVar1 == (wil_details_FeatureDescriptor *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              (pwVar1->featureStateCache,pwVar1);
    pwVar1 = pwVar1 + 1;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400216d4 =====

wil_details_FeatureStateCache __cdecl
wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
          (wil_details_FeatureStateCache *param_1,wil_details_FeatureDescriptor *param_2)

{
  wil_details_FeatureStateCache local_res8;
  
  local_res8._s_2.payloadId = 0;
  local_res8.exchange = param_1->exchange;
  if ((param_1->exchange >> 9 & 1) != 0) {
    local_res8 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                           (param_1,local_res8,param_2);
  }
  return local_res8;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14002170c =====

wil_details_FeatureStateCache __cdecl
wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
          (wil_details_FeatureStateCache *param_1,wil_details_FeatureStateCache param_2,
          wil_details_FeatureDescriptor *param_3)

{
  uint uVar1;
  wil_details_FeatureDescriptor *pwVar2;
  uint uVar3;
  uint uVar4;
  wil_details_FeatureStateCache wVar5;
  wil_details_FeatureDescriptor **ppwVar6;
  uint uVar7;
  ulonglong local_res10;
  
  uVar7 = (uint)(param_2.exchange64 >> 6) & 1;
  if (((param_2.exchange64 >> 6 & 1) != 0) &&
     (ppwVar6 = param_3->requiresFeatures, ppwVar6 != (wil_details_FeatureDescriptor **)0x0)) {
    do {
      while( true ) {
        pwVar2 = *ppwVar6;
        if (pwVar2 == (wil_details_FeatureDescriptor *)0x0) goto LAB_140021788;
        if ((pwVar2->isAlwaysEnabled == '\0') && (pwVar2->isAlwaysDisabled == '\0')) break;
        if ((uVar7 == 0) || (pwVar2->isEnabledByDefault == '\0')) {
          uVar7 = 0;
          goto LAB_140021788;
        }
        uVar7 = 1;
        ppwVar6 = ppwVar6 + 1;
      }
      wVar5 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        (pwVar2->featureStateCache,pwVar2);
      if ((uVar7 == 0) || ((wVar5.exchange64 & 1) == 0)) {
        uVar7 = 0;
      }
      else {
        uVar7 = 1;
      }
      ppwVar6 = ppwVar6 + 1;
    } while (uVar7 != 0);
  }
LAB_140021788:
  wVar5.exchange64 = param_2.exchange64 & 0xffffffff;
  while( true ) {
    uVar4 = wVar5.exchange;
    uVar3 = param_2.exchange & 0xffffffce;
    if ((uVar4 & 1) == uVar7) {
      uVar3 = param_2.exchange & 0xfffffffe;
    }
    local_res10 = (ulonglong)(uVar3 | uVar7) & 0xfffffffffffffdff;
    LOCK();
    uVar1 = param_1->exchange;
    if (uVar4 == uVar1) {
      param_1->exchange = uVar3 & 0xfffffdff | uVar7;
    }
    else {
      wVar5._s_2.payloadId = 0;
      wVar5.exchange = uVar1;
    }
    UNLOCK();
    if (uVar4 == uVar1) break;
    param_2 = wVar5;
  }
  return (wil_details_FeatureStateCache)local_res10;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400217e0 =====

void __cdecl
wil_details_OnFeatureUsageProviderFlushNotification
          (_RTL_FEATURE_USAGE_PROVIDER_CALLBACK_TYPE param_1,void *param_2,void *param_3)

{
  int iVar1;
  wil_details_FeatureDescriptor *pwVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == FeatureUsageProviderCallBackUsageFlushNotification) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      pwVar2 = &Feature_GatePerf__private_descriptor;
      while (pwVar2 = wil_details_FeatureDescriptors_SkipPadding((ulong64)pwVar2),
            pwVar2 != (wil_details_FeatureDescriptor *)0x0) {
        if (((pwVar2->featureReportingCache->reported).exchange & 1) != 0) {
          wil_details_RecordCachedUsage(pwVar2->featureId,pwVar2->featureReportingCache,param_3);
        }
        pwVar2 = pwVar2 + 1;
      }
    }
  }
  return;
}



===== wil_details_RecordFeatureUsageCallback @ 140021834 =====

void __cdecl
wil_details_RecordFeatureUsageCallback(__WIL_RTL_FEATURE_USAGE_DATA *param_1,ulong64 param_2)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140021850 =====

void __cdecl wil_details_ReevaluateOnFeatureConfigurationChange(void *param_1)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002186c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl wil_details_UpdateFeatureConfiguredStates(void)

{
  long lVar1;
  wil_details_FeatureDescriptor *pwVar2;
  undefined1 auStack_58 [32];
  wil_details_FeatureStateCache local_38;
  undefined8 local_30;
  _RTL_FEATURE_CONFIGURATION local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pwVar2 = &Feature_GatePerf__private_descriptor;
  while( true ) {
    pwVar2 = wil_details_FeatureDescriptors_SkipPadding((ulong64)pwVar2);
    if (pwVar2 == (wil_details_FeatureDescriptor *)0x0) break;
    if (((pwVar2->isAlwaysDisabled == '\0') && (pwVar2->isAlwaysEnabled == '\0')) &&
       (pwVar2->changeTime == '\0')) {
      local_30 = 0;
      local_28.FeatureId = 0;
      local_28._4_4_ = 0;
      local_28.VariantPayload = 0;
      lVar1 = RtlQueryFeatureConfiguration(pwVar2->featureId,1,&local_30,&local_28);
      local_38.exchange64 = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(lVar1,&local_28,&local_38);
      LOCK();
      pwVar2->featureStateCache->exchange =
           pwVar2->featureStateCache->exchange ^
           (pwVar2->featureStateCache->exchange ^ local_38.exchange) & 0xf80;
      UNLOCK();
    }
    pwVar2 = pwVar2 + 1;
  }
  return;
}



===== WdmlibInit @ 140021920 =====

void __cdecl WdmlibInit(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
  PfnIoCreateDeviceSecure =
       (_func___cdecl_long__DRIVER_OBJECT_ptr_ulong__UNICODE_STRING_ptr_ulong_ulong_uchar__UNICODE_STRING_ptr__GUID_ptr__DEVICE_OBJECT_ptr_ptr
        *)MmGetSystemRoutineAddress(&local_18);
  if (PfnIoCreateDeviceSecure ==
      (_func___cdecl_long__DRIVER_OBJECT_ptr_ulong__UNICODE_STRING_ptr_ulong_ulong_uchar__UNICODE_STRING_ptr__GUID_ptr__DEVICE_OBJECT_ptr_ptr
       *)0x0) {
    PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
  }
  RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
  MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = '\x01';
  return;
}



===== WdmlibIoCreateDeviceSecure @ 1400219ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
WdmlibIoCreateDeviceSecure
          (_DRIVER_OBJECT *param_1,ulong param_2,_UNICODE_STRING *param_3,ulong param_4,
          ulong param_5,uchar param_6,_UNICODE_STRING *param_7,_GUID *param_8,
          _DEVICE_OBJECT **param_9)

{
  long lVar1;
  
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  lVar1 = (*PfnIoCreateDeviceSecure)
                    (param_1,0x28,param_3,param_4,0x100,'\0',param_7,(_GUID *)0x0,param_9);
  return lVar1;
}



===== IoDevObjCreateDeviceSecure @ 140021a30 =====

long __cdecl
IoDevObjCreateDeviceSecure
          (_DRIVER_OBJECT *param_1,ulong param_2,_UNICODE_STRING *param_3,ulong param_4,
          ulong param_5,uchar param_6,_UNICODE_STRING *param_7,_GUID *param_8,
          _DEVICE_OBJECT **param_9)

{
  _DEVICE_OBJECT **pp_Var1;
  long lVar2;
  ulong uVar3;
  _DRIVER_OBJECT *p_Var4;
  ulong uVar5;
  void *local_res18;
  ulong local_res20;
  STACK_CREATION_SETTINGS local_68;
  STACK_CREATION_SETTINGS local_50;
  
  pp_Var1 = param_9;
  local_res18 = (void *)0x0;
  local_68.Characteristics = 0;
  local_68.Exclusivity = 0;
  *param_9 = (_DEVICE_OBJECT *)0x0;
  param_9 = (_DEVICE_OBJECT **)0x0;
  local_68.Flags = 0;
  local_68.DeviceType = 0;
  local_68.SecurityDescriptor = (void *)0x0;
  if ((param_3 == (_UNICODE_STRING *)0x0) && (-1 < (char)param_5)) {
    return -0x3ffffff3;
  }
  uVar3 = param_2;
  local_res20 = param_4;
  if (param_8 != (_GUID *)0x0) {
    p_Var4 = param_1;
    lVar2 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,&local_68);
    uVar3 = (ulong)p_Var4;
    if (lVar2 < 0) {
      return lVar2;
    }
  }
  uVar5 = local_68.Flags;
  if (((ulonglong)local_68.Flags & 2) == 0) {
    lVar2 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar3,&local_res18);
    if (lVar2 < 0) goto LAB_140021b90;
    uVar5 = 2;
    local_68.Flags = 2;
    local_68.SecurityDescriptor = local_res18;
    if (param_8 != (_GUID *)0x0) {
      local_50.Flags = 2;
      local_50.DeviceType = 0;
      local_50.Characteristics = 0;
      local_50.Exclusivity = 0;
      local_50.SecurityDescriptor = local_res18;
      lVar2 = PpRegStateUpdateStackCreationSettings(param_8,&local_50);
      if (lVar2 < 0) goto LAB_140021b90;
    }
  }
  uVar3 = local_res20;
  if ((uVar5 & 1) != 0) {
    uVar3 = local_68.DeviceType;
  }
  if ((uVar5 & 4) != 0) {
    param_5 = local_68.Characteristics;
  }
  if ((uVar5 & 8) != 0) {
    param_6 = (uchar)local_68.Exclusivity;
  }
  lVar2 = IoCreateDevice(param_1,param_2,param_3,uVar3,param_5,param_6,&param_9);
  if (-1 < lVar2) {
    lVar2 = IopDevObjApplyPostCreationSettings((_DEVICE_OBJECT *)param_9,&local_68);
    if (lVar2 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *pp_Var1 = (_DEVICE_OBJECT *)param_9;
    }
  }
LAB_140021b90:
  if ((uVar5 & 2) != 0) {
    ExFreePoolWithTag(local_68.SecurityDescriptor,0);
  }
  return lVar2;
}



===== IopDevObjApplyPostCreationSettings @ 140021bc4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __cdecl
IopDevObjApplyPostCreationSettings(_DEVICE_OBJECT *param_1,STACK_CREATION_SETTINGS *param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uchar local_res10 [8];
  ulong local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = '\0';
  if ((param_2->Flags & 2) == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = SeUtilSecurityInfoFromSecurityDescriptor
                      (param_2->SecurityDescriptor,local_res10,local_res18);
    if (-1 < lVar1) {
      uVar2 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar3 = uVar2 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar3 = uVar2;
      }
      uVar2 = uVar3 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar2 = uVar3;
      }
      lVar1 = ObOpenObjectByPointer(param_1,0x200,0,uVar2,_DAT_00020484,0,&local_res20);
      if (-1 < lVar1) {
        lVar1 = ZwSetSecurityObject(local_res20,local_res18[0],param_2->SecurityDescriptor);
        ZwClose(local_res20);
      }
    }
  }
  return lVar1;
}



===== SeSddlSecurityDescriptorFromSDDL @ 140021cb4 =====

long __cdecl SeSddlSecurityDescriptorFromSDDL(_UNICODE_STRING *param_1,ulong param_2,void **param_3)

{
  ulonglong uVar1;
  ushort uVar2;
  long lVar3;
  wchar_t *pwVar4;
  ulong uVar5;
  
  uVar1 = (ulonglong)param_1->Length + 2;
  if (param_1->MaximumLength == uVar1) {
    uVar2 = param_1->Length >> 1;
    if (param_1->Buffer[uVar2] == L'\0') {
      lVar3 = SepSddlSecurityDescriptorFromSDDLString(param_1->Buffer,(uint)uVar2,param_3);
      return lVar3;
    }
  }
  pwVar4 = (wchar_t *)ExAllocatePoolWithTag(1,uVar1,0x73546553);
  if (pwVar4 == (wchar_t *)0x0) {
    *param_3 = (void *)0x0;
    lVar3 = -0x3fffff66;
  }
  else {
    memset();
    uVar5 = (ulong)param_1->Buffer;
    memcpy();
    pwVar4[param_1->Length >> 1] = L'\0';
    lVar3 = SepSddlSecurityDescriptorFromSDDLString(pwVar4,uVar5,param_3);
    ExFreePoolWithTag(pwVar4,0);
  }
  return lVar3;
}



===== SepSddlAddAceToAcl @ 140021d94 =====

long __cdecl
SepSddlAddAceToAcl(_ACL **param_1,ulong *param_2,ulong param_3,ulong param_4,ulong param_5,
                  ulong param_6,void *param_7)

{
  uint uVar1;
  ulong uVar2;
  _ACL *p_Var3;
  int iVar4;
  long lVar5;
  _ACL *p_Var6;
  undefined4 in_register_00000084;
  undefined4 in_register_0000008c;
  
  p_Var3 = *param_1;
  uVar2 = *param_2;
  iVar4 = RtlLengthSid(param_7,param_2,CONCAT44(in_register_00000084,param_3),
                       CONCAT44(in_register_0000008c,param_4));
  uVar1 = iVar4 + 8 + uVar2;
  p_Var6 = p_Var3;
  if (p_Var3->AclSize < uVar1) {
    iVar4 = (iVar4 + 8) * param_6 + uVar2;
    p_Var6 = (_ACL *)ExAllocatePoolWithTag(1,iVar4,0x6c416553);
    if (p_Var6 == (_ACL *)0x0) {
      return -0x3fffff66;
    }
    memset();
    memcpy();
    p_Var6->AclSize = (ushort)iVar4;
    ExFreePoolWithTag(p_Var3,0);
    *param_1 = p_Var6;
  }
  *param_2 = uVar1;
  lVar5 = RtlAddAccessAllowedAce(p_Var6,2,param_5,param_7);
  return lVar5;
}



===== SepSddlDaclFromSDDLString @ 140021e94 =====

long __cdecl SepSddlDaclFromSDDLString(wchar_t *param_1,ulong param_2,ulong *param_3,_ACL **param_4)

{
  long lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  ulong uVar4;
  _ACL *local_res8;
  wchar_t *local_res18 [2];
  
  local_res8 = (_ACL *)0x0;
  local_res18[0] = (wchar_t *)0x0;
  *param_4 = (_ACL *)0x0;
  *param_3 = 0;
  for (; *param_1 == L' '; param_1 = param_1 + 1) {
  }
  if ((*param_1 != L'D') || (param_1[1] != L':')) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != L'P') {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != L'P') {
    lVar2 = 2;
  }
  lVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (lVar1 == 0) {
    for (pwVar3 = local_res18[0]; *pwVar3 == L' '; pwVar3 = pwVar3 + 1) {
    }
    if (*pwVar3 == L'\0') {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    lVar1 = -0x3ffffff3;
  }
  if (local_res8 != (_ACL *)0x0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return lVar1;
}



===== SepSddlGetAclForString @ 140021f80 =====

long __cdecl SepSddlGetAclForString(wchar_t *param_1,_ACL **param_2,wchar_t **param_3)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  _ACL *p_Var9;
  wchar_t *pwVar10;
  uint uVar11;
  wchar_t **ppwVar12;
  undefined8 uVar13;
  uint uVar14;
  wchar_t *local_res8;
  uint local_res10;
  ulong local_res18 [2];
  ulong local_res20 [2];
  wchar_t *local_58;
  void *local_50 [2];
  
  *param_2 = (_ACL *)0x0;
  local_res18[0] = 0;
  lVar6 = 0;
  local_58 = (wchar_t *)0x0;
  local_50[0] = (void *)0x0;
  uVar14 = 0;
  pwVar7 = wcschr(param_1,L':');
  *param_3 = pwVar7;
  if (pwVar7 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (param_1[lVar8] != L'\0');
    pwVar7 = param_1 + lVar8;
  }
  else {
    pwVar7 = pwVar7 + -1;
  }
  *param_3 = pwVar7;
  bVar3 = false;
  bVar2 = false;
  uVar13 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar7; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar14 = uVar14 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar11 = uVar14 / 5;
  local_res8 = (wchar_t *)CONCAT44(local_res8._4_4_,uVar11);
  if ((uVar14 != uVar11 * 5) || ((uVar14 == 0 && (bVar2)))) {
    lVar6 = -0x3ffffff3;
  }
  else {
    if (uVar11 == 0) {
      p_Var9 = (_ACL *)ExAllocatePoolWithTag(1,8);
      *param_2 = p_Var9;
      if (p_Var9 != (_ACL *)0x0) {
        p_Var9->AclRevision = '\x02';
        p_Var9->Sbz1 = '\0';
        p_Var9->AclSize = 8;
        p_Var9->AceCount = 0;
        p_Var9->Sbz2 = 0;
        return 0;
      }
    }
    else {
      uVar14 = uVar11 * 0x30 + 8;
      if (0xffff < uVar14) {
        uVar14 = 0xffff;
      }
      p_Var9 = (_ACL *)ExAllocatePoolWithTag(1,uVar14,0x6c416553);
      *param_2 = p_Var9;
      if (p_Var9 != (_ACL *)0x0) {
        local_res20[0] = 8;
        memset();
        p_Var9->AclRevision = '\x02';
        p_Var9->Sbz1 = '\0';
        p_Var9->AclSize = (ushort)uVar14;
        p_Var9->AceCount = 0;
        p_Var9->Sbz2 = 0;
        uVar14 = (uint)local_res8;
        for (local_res10 = 0; uVar11 = 0, local_res10 < uVar14; local_res10 = local_res10 + 1) {
          local_res8 = (wchar_t *)((ulonglong)local_res8 & 0xffffffff00000000);
          for (; *param_1 == L' '; param_1 = param_1 + 1) {
          }
          if (*param_1 == L'(') {
            do {
              param_1 = param_1 + 1;
            } while (*param_1 == L' ');
          }
          iVar4 = _wcsnicmp(param_1,L"A",1);
          if (iVar4 != 0) {
LAB_14002229d:
            lVar6 = -0x3ffffff3;
LAB_14002229f:
            p_Var9 = *param_2;
            goto LAB_1400222ab;
          }
          for (pwVar7 = param_1 + 2; *pwVar7 == L' '; pwVar7 = pwVar7 + 1) {
          }
          if (*pwVar7 != L';') goto LAB_14002229d;
          do {
            pwVar7 = pwVar7 + 1;
          } while (*pwVar7 == L' ');
          while (wVar1 = *pwVar7, wVar1 != L';') {
            while (wVar1 == L' ') {
              pwVar7 = pwVar7 + 1;
              wVar1 = *pwVar7;
            }
            uVar5 = SepSddlLookupAccessMaskInTable(pwVar7,local_res18,&local_58);
            if (uVar5 == 0) {
              SepSddlParseWideStringUlong(pwVar7,&local_58,(ulong *)&local_res8);
              if (local_58 == pwVar7) goto LAB_14002229d;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (wchar_t *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar7 = local_58;
          }
          pwVar7 = pwVar7 + 1;
          if (lVar6 != 0) goto LAB_14002229f;
          lVar8 = 2;
          do {
            for (; *pwVar7 == L' '; pwVar7 = pwVar7 + 1) {
            }
            if (*pwVar7 != L';') {
              lVar6 = -0x3ffffff3;
            }
            pwVar7 = pwVar7 + 1;
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
          if (lVar6 != 0) goto LAB_14002229f;
          for (; *pwVar7 == L' '; pwVar7 = pwVar7 + 1) {
          }
          local_res8 = (wchar_t *)0x0;
          ppwVar12 = &local_res8;
          lVar6 = SepSddlGetSidForString(pwVar7,local_50,ppwVar12);
          if (lVar6 != 0) break;
          pwVar7 = local_res8;
          if (local_res8 == (wchar_t *)0x0) {
LAB_140022237:
            lVar6 = -0x3fffff89;
            goto LAB_14002229f;
          }
          for (; *pwVar7 == L' '; pwVar7 = pwVar7 + 1) {
          }
          if (*pwVar7 != L')') goto LAB_140022237;
          param_1 = pwVar7 + 1;
          if ((local_50[0] != (void *)0x0) &&
             (lVar6 = SepSddlAddAceToAcl(param_2,local_res20,(ulong)ppwVar12,(ulong)uVar13,uVar11,
                                         uVar14 - local_res10,local_50[0]), lVar6 != 0))
          goto LAB_14002229f;
          if (*param_1 == L'(') {
            param_1 = pwVar7 + 2;
          }
        }
        p_Var9 = *param_2;
        if (lVar6 == 0) {
          p_Var9->AclSize = (ushort)local_res20[0];
          return 0;
        }
LAB_1400222ab:
        ExFreePoolWithTag(p_Var9,0);
        *param_2 = (_ACL *)0x0;
        return lVar6;
      }
    }
    lVar6 = -0x3fffff66;
  }
  return lVar6;
}



===== SepSddlGetSidForString @ 1400222ec =====

long __cdecl SepSddlGetSidForString(wchar_t *param_1,void **param_2,wchar_t **param_3)

{
  OS_SID_VER OVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  void *pvVar6;
  uint uVar7;
  
  pvVar6 = (void *)0x0;
  uVar7 = 0;
  do {
    if (0xd < uVar7) {
      lVar5 = -0x3fffff8d;
LAB_14002238d:
      *param_2 = pvVar6;
      return lVar5;
    }
    iVar4 = _wcsnicmp(param_1,SidLookup[uVar7].Key,(ulonglong)SidLookup[uVar7].KeyLen);
    if (iVar4 == 0) {
      OVar1 = SidLookup[uVar7].OsVer;
      uVar2 = SidLookup[uVar7].KeyLen;
      *param_3 = param_1 + uVar2;
      if (OVar1 == WINXP_OR_LATER) {
        cVar3 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar2) >> 8),0x20));
        if (cVar3 != '\0') goto code_r0x000140022372;
      }
      else {
code_r0x000140022372:
        pvVar6 = *(void **)(SidLookup[uVar7].ExportSidFieldOffset + *(longlong *)SeExports_exref);
      }
      lVar5 = 0;
      goto LAB_14002238d;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 1400223b8 =====

ulong __cdecl SepSddlLookupAccessMaskInTable(wchar_t *param_1,ulong *param_2,wchar_t **param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (7 < uVar2) {
      *param_2 = 0;
      *param_3 = param_1;
      return 0;
    }
    iVar1 = _wcsnicmp(param_1,RightsLookup[uVar2].Key,(ulonglong)RightsLookup[uVar2].KeyLen);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = RightsLookup[uVar2].Value;
  *param_3 = param_1 + RightsLookup[uVar2].KeyLen;
  return 1;
}



===== SepSddlParseWideStringUlong @ 140022448 =====

ulong __cdecl SepSddlParseWideStringUlong(wchar_t *param_1,wchar_t **param_2,ulong *param_3)

{
  wchar_t wVar1;
  int iVar2;
  ulong uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  wVar1 = *param_1;
  *param_3 = 0;
  *param_2 = param_1;
  if (wVar1 == L'0') {
    if ((param_1[1] + L'ﾨ' & 0xffdfU) != 0) {
LAB_1400224b5:
      iVar6 = 10;
      goto LAB_14002248c;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(wVar1 + L'￐') < 10) goto LAB_1400224b5;
  iVar6 = 0x10;
LAB_14002248c:
  uVar7 = 0;
  for (pwVar4 = param_1; wVar1 = *pwVar4, wVar1 != L'\0'; pwVar4 = pwVar4 + 1) {
    if ((ushort)(wVar1 + L'￐') < 10) {
      iVar2 = (ushort)wVar1 - 0x30;
    }
    else {
      if (iVar6 != 0x10) break;
      if ((ushort)(wVar1 + L'﾿') < 6) {
        iVar2 = (ushort)wVar1 - 0x37;
      }
      else {
        if (5 < (ushort)(wVar1 + L'ﾟ')) break;
        iVar2 = (ushort)wVar1 - 0x57;
      }
    }
    uVar5 = iVar6 * uVar7 + iVar2;
    if (uVar5 < uVar7) goto LAB_1400224f9;
    uVar7 = uVar5;
  }
  if (pwVar4 == param_1) {
LAB_1400224f9:
    uVar3 = 0;
  }
  else {
    *param_2 = pwVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 140022520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long __cdecl
SepSddlSecurityDescriptorFromSDDLString
          (wchar_t *param_1,ulong param_2,_SECURITY_DESCRIPTOR **param_3)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  _SECURITY_DESCRIPTOR *p_Var5;
  ulong uVar6;
  ulong local_res10 [4];
  ulong local_res20 [2];
  _ACL *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  uVar6 = 0x4001a370;
  local_50 = 0;
  uStack_48 = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(&local_50);
  pcVar4 = (code *)MmGetSystemRoutineAddress(&local_50);
  if (pcVar4 != (code *)0x0) {
    iVar2 = (*pcVar4)(param_1,1,param_3);
    if (iVar2 < 0) {
      return iVar2;
    }
    (*param_3)->Control = (*param_3)->Control | 8;
    return iVar2;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58 = (_ACL *)0x0;
  p_Var5 = (_SECURITY_DESCRIPTOR *)0x0;
  *param_3 = (_SECURITY_DESCRIPTOR *)0x0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  lVar3 = SepSddlDaclFromSDDLString(param_1,uVar6,local_res20,&local_58);
  if (-1 < lVar3) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58,0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    p_Var5 = (_SECURITY_DESCRIPTOR *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (p_Var5 == (_SECURITY_DESCRIPTOR *)0x0) {
      lVar3 = -0x3fffff66;
    }
    else {
      memset();
      lVar3 = RtlAbsoluteToSelfRelativeSD(&local_40,p_Var5,local_res10);
      if (-1 < lVar3) {
        ExFreePoolWithTag(local_58,0);
        *param_3 = p_Var5;
        return lVar3;
      }
    }
  }
  if (local_58 != (_ACL *)0x0) {
    ExFreePoolWithTag(local_58,0);
  }
  if (p_Var5 != (_SECURITY_DESCRIPTOR *)0x0) {
    ExFreePoolWithTag(p_Var5,0);
  }
  return lVar3;
}



===== PiRegStateOpenClassKey @ 1400226c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl
PiRegStateOpenClassKey(_GUID *param_1,ulong param_2,ulong param_3,ulong *param_4,void **param_5)

{
  void *pvVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  undefined1 auStackY_128 [32];
  ulong local_b8;
  ulong local_b4;
  void *local_b0;
  void *local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = (void *)0x0;
  local_a8[0] = (void *)0x0;
  *param_5 = (void *)0x0;
  local_b8 = 0;
  if (param_4 != (ulong *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  lVar2 = CmRegUtilOpenExistingWstrKey
                    ((void *)0x0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class",
                     0x20019,&local_b0);
  if (-1 < lVar2) {
    uVar4 = param_1->Data1;
    uVar3 = 0x4001a4c0;
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    pvVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      lVar2 = CmRegUtilOpenExistingWstrKey(local_b0,local_98,0xf003f,local_a8);
      uVar4 = 2;
    }
    else {
      lVar2 = CmRegUtilCreateWstrKey(local_b0,local_98,uVar3,uVar4,(void *)0x0,&local_b8,local_a8);
      uVar4 = local_b8;
    }
    ZwClose(pvVar1);
    if ((-1 < lVar2) && (*param_5 = local_a8[0], param_4 != (ulong *)0x0)) {
      *param_4 = uVar4;
    }
  }
  return lVar2;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 140022860 =====

long __cdecl
PiRegStateReadStackCreationSettingsFromKey(void *param_1,STACK_CREATION_SETTINGS *param_2)

{
  long lVar1;
  _KEY_VALUE_FULL_INFORMATION *p_Var2;
  ulong in_R8D;
  ulong *puVar3;
  ulong in_R9D;
  uchar local_res10 [8];
  ulong local_res18 [2];
  void *local_res20;
  _KEY_VALUE_FULL_INFORMATION *local_58;
  _UNICODE_STRING local_50;
  
  param_2->Flags = 0;
  param_2->DeviceType = 0;
  param_2->SecurityDescriptor = (void *)0x0;
  param_2->Characteristics = 0;
  param_2->Exclusivity = 0;
  local_res20 = (void *)0x0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = (_KEY_VALUE_FULL_INFORMATION *)0x0;
  local_50.Length = 0;
  local_50.MaximumLength = 0;
  local_50._4_4_ = 0;
  local_50.Buffer = (wchar_t *)0x0;
  lVar1 = WdmlibRtlInitUnicodeStringEx(&local_50,L"Security");
  p_Var2 = (_KEY_VALUE_FULL_INFORMATION *)0x0;
  if ((lVar1 < 0) ||
     (lVar1 = CmRegUtilUcValueGetFullBuffer(param_1,&local_50,in_R8D,in_R9D,&local_58),
     p_Var2 = local_58, lVar1 < 0)) {
    if (lVar1 == -0x3fffffcc) {
      lVar1 = 0;
    }
  }
  else {
    in_R8D = 1;
    lVar1 = SeCaptureSecurityDescriptor
                      ((longlong)local_58->Name + ((ulonglong)local_58->DataOffset - 0x14),0,1,1,
                       &local_res20);
  }
  if (p_Var2 != (_KEY_VALUE_FULL_INFORMATION *)0x0) {
    ExFreePoolWithTag(p_Var2,0);
  }
  if (-1 < lVar1) {
    if (local_res20 != (void *)0x0) {
      puVar3 = local_res18;
      lVar1 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,puVar3);
      in_R8D = (ulong)puVar3;
      if (lVar1 < 0) goto LAB_1400229df;
      if (local_res10[0] == '\0') {
        param_2->Flags = param_2->Flags | 2;
        param_2->SecurityDescriptor = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    lVar1 = CmRegUtilWstrValueGetDword(param_1,L"DeviceType",in_R8D,&param_2->DeviceType);
    if (lVar1 < 0) {
      if (lVar1 != -0x3fffffcc) goto LAB_1400229df;
    }
    else {
      param_2->Flags = param_2->Flags | 1;
    }
    lVar1 = CmRegUtilWstrValueGetDword
                      (param_1,L"DeviceCharacteristics",in_R8D,&param_2->Characteristics);
    if (lVar1 < 0) {
      if (lVar1 != -0x3fffffcc) goto LAB_1400229df;
    }
    else {
      param_2->Flags = param_2->Flags | 4;
    }
    lVar1 = CmRegUtilWstrValueGetDword(param_1,L"Exclusive",in_R8D,&param_2->Exclusivity);
    if (-1 < lVar1) {
      param_2->Flags = param_2->Flags | 8;
      return lVar1;
    }
    if (lVar1 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1400229df:
  if (param_2->SecurityDescriptor != (void *)0x0) {
    ExFreePoolWithTag(param_2->SecurityDescriptor,0);
  }
  param_2->Flags = 0;
  param_2->DeviceType = 0;
  param_2->SecurityDescriptor = (void *)0x0;
  param_2->Characteristics = 0;
  param_2->Exclusivity = 0;
  return lVar1;
}



===== PpRegStateReadCreateClassCreationSettings @ 140022a24 =====

long __cdecl
PpRegStateReadCreateClassCreationSettings
          (_GUID *param_1,_DRIVER_OBJECT *param_2,STACK_CREATION_SETTINGS *param_3)

{
  long lVar1;
  void *pvVar2;
  _UNICODE_STRING *p_Var3;
  ulong local_res18 [2];
  void *local_res20;
  _UNICODE_STRING local_18;
  
  param_3->Flags = 0;
  param_3->SecurityDescriptor = (void *)0x0;
  param_3->DeviceType = 0;
  param_3->Characteristics = 0;
  param_3->Exclusivity = 0;
  local_res18[0] = 0;
  local_res20 = (void *)0x0;
  local_18._0_8_ = (void *)0x0;
  lVar1 = PiRegStateOpenClassKey(param_1,(ulong)param_2,1,local_res18,&local_res20);
  pvVar2 = local_res20;
  if (lVar1 < 0) {
    return lVar1;
  }
  if (local_res18[0] == 2) {
    lVar1 = CmRegUtilOpenExistingWstrKey(local_res20,L"Properties",0x20019,(void **)&local_18);
    ZwClose(local_res20);
    if (lVar1 < 0) {
      if (lVar1 == -0x3fffffcc) {
        return 0;
      }
      return lVar1;
    }
    lVar1 = PiRegStateReadStackCreationSettingsFromKey((void *)local_18._0_8_,param_3);
    pvVar2 = (void *)local_18._0_8_;
  }
  else {
    p_Var3 = &param_2->DriverExtension->ServiceKeyName;
    if (p_Var3 == (_UNICODE_STRING *)0x0) {
      lVar1 = -0x3fffff66;
    }
    else {
      local_18._0_8_ = (void *)0x0;
      local_18.Buffer = (wchar_t *)0x0;
      lVar1 = WdmlibRtlInitUnicodeStringEx(&local_18,L"Class");
      if ((-1 < lVar1) && (lVar1 = CmRegUtilUcValueSetUcString(pvVar2,&local_18,p_Var3), -1 < lVar1)
         ) {
        local_res18[0] = 0x31;
        lVar1 = CmRegUtilWstrValueSetWstrString(pvVar2,L"NoDisplayClass",(wchar_t *)local_res18);
        if (-1 < lVar1) {
          lVar1 = CmRegUtilWstrValueSetWstrString(pvVar2,L"NoUseClass",(wchar_t *)local_res18);
        }
      }
    }
  }
  ZwClose(pvVar2);
  return lVar1;
}



===== PpRegStateUpdateStackCreationSettings @ 140022b88 =====

long __cdecl PpRegStateUpdateStackCreationSettings(_GUID *param_1,STACK_CREATION_SETTINGS *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  void *pvVar8;
  ulong *local_res18;
  void *local_res20;
  void *local_38;
  _UNICODE_STRING local_30;
  
  uVar7 = 0;
  local_res18 = (ulong *)0x0;
  uVar5 = 0;
  local_38 = (void *)0x0;
  local_res20 = (void *)0x0;
  lVar1 = PiRegStateOpenClassKey(param_1,(ulong)param_2,0,(ulong *)0x0,&local_res20);
  uVar6 = (ulong)uVar7;
  if (-1 < lVar1) {
    puVar4 = PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == NOT_VALIDATED) {
      uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
      uVar6 = (ulong)uVar7;
      uVar5 = 1;
      iVar2 = SeCaptureSecurityDescriptor
                        (PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar7,&local_res18);
      if (iVar2 < 0) {
        PiRegStateDiscriptor = VALIDATED_UNSUCCESSFULLY;
      }
      else {
        PiRegStateDiscriptor = VALIDATED_SUCCESSFULLY;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != VALIDATED_SUCCESSFULLY) {
      puVar4 = (ulong *)0x0;
    }
    local_res18 = puVar4;
    lVar1 = CmRegUtilCreateWstrKey
                      (local_res20,L"Properties",uVar5,uVar6,puVar4,(ulong *)0x0,&local_38);
    ZwClose(local_res20);
    if (-1 < lVar1) {
      uVar3 = RtlLengthSecurityDescriptor(param_2->SecurityDescriptor);
      pvVar8 = param_2->SecurityDescriptor;
      local_30.Length = 0;
      local_30.MaximumLength = 0;
      local_30._4_4_ = 0;
      local_30.Buffer = (wchar_t *)0x0;
      lVar1 = WdmlibRtlInitUnicodeStringEx(&local_30,L"Security");
      if (-1 < lVar1) {
        lVar1 = ZwSetValueKey(local_38,&local_30,0,3,pvVar8,uVar3);
      }
      ZwClose(local_38);
    }
  }
  return lVar1;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 140022cf0 =====

long __cdecl SeUtilSecurityInfoFromSecurityDescriptor(void *param_1,uchar *param_2,ulong *param_3)

{
  int iVar1;
  uint uVar2;
  uchar local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = '\0';
  local_res10[0] = '\0';
  local_res20[0] = '\0';
  iVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < iVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    iVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < iVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      iVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < iVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        iVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < iVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          iVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return iVar1;
}



===== CmRegUtilCreateUcKey @ 140022dec =====

long __cdecl
CmRegUtilCreateUcKey
          (void *param_1,_UNICODE_STRING *param_2,ulong param_3,ulong param_4,void *param_5,
          ulong *param_6,void **param_7)

{
  int iVar1;
  void *local_res8 [3];
  ulong local_res20 [2];
  undefined8 local_38;
  void *local_30;
  _UNICODE_STRING *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res20[0] = 0;
  local_res8[0] = (void *)0x0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,0xf003f,&local_38,0,0,0,local_res20);
  if (iVar1 < 0) {
    local_res8[0] = (void *)0x0;
    local_res20[0] = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (ulong *)0x0) {
    *param_6 = local_res20[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 140022e94 =====

long __cdecl
CmRegUtilCreateWstrKey
          (void *param_1,wchar_t *param_2,ulong param_3,ulong param_4,void *param_5,ulong *param_6,
          void **param_7)

{
  long lVar1;
  _UNICODE_STRING local_18;
  
  local_18.Length = 0;
  local_18.MaximumLength = 0;
  local_18._4_4_ = 0;
  local_18.Buffer = (wchar_t *)0x0;
  lVar1 = WdmlibRtlInitUnicodeStringEx(&local_18,param_2);
  if (-1 < lVar1) {
    lVar1 = CmRegUtilCreateUcKey(param_1,&local_18,param_3,(ulong)param_1,param_5,param_6,param_7);
  }
  return lVar1;
}



===== CmRegUtilOpenExistingWstrKey @ 140022ef4 =====

long __cdecl
CmRegUtilOpenExistingWstrKey(void *param_1,wchar_t *param_2,ulong param_3,void **param_4)

{
  long lVar1;
  ulonglong uVar2;
  void *local_58;
  _UNICODE_STRING local_50;
  undefined8 local_40;
  void *local_38;
  _UNICODE_STRING *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50.Length = 0;
  local_50.MaximumLength = 0;
  local_50._4_4_ = 0;
  local_50.Buffer = (wchar_t *)0x0;
  uVar2 = (ulonglong)param_3;
  lVar1 = WdmlibRtlInitUnicodeStringEx(&local_50,param_2);
  if (-1 < lVar1) {
    local_24 = 0;
    local_30 = &local_50;
    local_58 = (void *)0x0;
    *param_4 = (void *)0x0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    lVar1 = ZwOpenKey(&local_58,uVar2 & 0xffffffff,&local_40);
    if (-1 < lVar1) {
      *param_4 = local_58;
    }
  }
  return lVar1;
}



===== CmRegUtilUcValueGetFullBuffer @ 140022f88 =====

long __cdecl
CmRegUtilUcValueGetFullBuffer
          (void *param_1,_UNICODE_STRING *param_2,ulong param_3,ulong param_4,
          _KEY_VALUE_FULL_INFORMATION **param_5)

{
  int iVar1;
  _KEY_VALUE_FULL_INFORMATION *p_Var2;
  uint uVar3;
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  uVar3 = param_2->Length + 0x1f & 0xfffffff8;
  *param_5 = (_KEY_VALUE_FULL_INFORMATION *)0x0;
  p_Var2 = (_KEY_VALUE_FULL_INFORMATION *)ExAllocatePoolWithTag(0x200,uVar3,0x62527050);
  if (p_Var2 == (_KEY_VALUE_FULL_INFORMATION *)0x0) {
    return -0x3fffff66;
  }
  memset();
  iVar1 = ZwQueryValueKey(param_1,param_2,1,p_Var2,uVar3,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(p_Var2,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    p_Var2 = (_KEY_VALUE_FULL_INFORMATION *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (p_Var2 == (_KEY_VALUE_FULL_INFORMATION *)0x0) {
      return -0x3fffff66;
    }
    memset();
    iVar1 = ZwQueryValueKey(param_1,param_2,1,p_Var2,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_1400230c0;
  }
  if (p_Var2->Type == 3) {
    *param_5 = p_Var2;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1400230c0:
  ExFreePoolWithTag(p_Var2,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 140023104 =====

long __cdecl
CmRegUtilUcValueSetUcString(void *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3)

{
  ushort uVar1;
  long lVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  longlong local_20;
  
  uVar1 = param_3->Length;
  local_24 = 0;
  if ((ulonglong)param_3->MaximumLength - (ulonglong)uVar1 < 2) {
    local_26 = uVar1 + 2;
    local_20 = ExAllocatePoolWithTag(1,(ulonglong)uVar1 + 2,0x63557050);
    if (local_20 == 0) {
      lVar2 = -0x3fffff66;
    }
    else {
      memset();
      local_28 = param_3->Length;
      memcpy();
      *(undefined2 *)(local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      lVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    param_3->Buffer[uVar1 >> 1] = L'\0';
    lVar2 = ZwSetValueKey(param_1,param_2,0,1,param_3->Buffer,param_3->Length + 2);
  }
  return lVar2;
}



===== CmRegUtilWstrValueGetDword @ 140023250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl CmRegUtilWstrValueGetDword(void *param_1,wchar_t *param_2,ulong param_3,ulong *param_4)

{
  long lVar1;
  ulong uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  _UNICODE_STRING local_30;
  undefined1 local_20 [4];
  int local_1c;
  ulong local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30.Length = 0;
  local_30.MaximumLength = 0;
  local_30._4_4_ = 0;
  local_30.Buffer = (wchar_t *)0x0;
  lVar1 = WdmlibRtlInitUnicodeStringEx(&local_30,param_2);
  uVar2 = 0;
  if (-1 < lVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    lVar1 = ZwQueryValueKey(param_1,&local_30,2,local_20);
    if (-1 < lVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        lVar1 = -0x3fffffdc;
      }
    }
    *param_4 = uVar2;
  }
  return lVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 1400232f4 =====

long __cdecl CmRegUtilWstrValueSetWstrString(void *param_1,wchar_t *param_2,wchar_t *param_3)

{
  long lVar1;
  _UNICODE_STRING local_28;
  _UNICODE_STRING local_18;
  
  local_18.Length = 0;
  local_18.MaximumLength = 0;
  local_18._4_4_ = 0;
  local_18.Buffer = (wchar_t *)0x0;
  local_28.Length = 0;
  local_28.MaximumLength = 0;
  local_28._4_4_ = 0;
  local_28.Buffer = (wchar_t *)0x0;
  lVar1 = WdmlibRtlInitUnicodeStringEx(&local_28,param_3);
  if (-1 < lVar1) {
    lVar1 = WdmlibRtlInitUnicodeStringEx(&local_18,param_2);
    if (-1 < lVar1) {
      lVar1 = CmRegUtilUcValueSetUcString(param_1,&local_18,&local_28);
    }
  }
  return lVar1;
}



===== GsDriverEntry @ 140024010 =====

long __cdecl GsDriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  
  __security_init_cookie();
  lVar1 = DriverEntry(param_1,param_2);
  return lVar1;
}



===== __security_init_cookie @ 140024044 =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x14001c100) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== DriverEntry @ 1400240b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl DriverEntry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  uint uVar1;
  RdDriver *pRVar2;
  WPP_PROJECT_CONTROL_BLOCK *pWVar3;
  _UNICODE_STRING *p_Var4;
  uchar uVar5;
  undefined1 auStack_168 [32];
  undefined8 *local_148 [2];
  WPP_PROJECT_CONTROL_BLOCK local_138 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  p_Var4 = (_UNICODE_STRING *)0x0;
  memset();
  pWVar3 = local_138;
  local_138[0].ReserveSpace[0] = '\x14';
  local_138[0].ReserveSpace[1] = '\x01';
  local_138[0].ReserveSpace[2] = '\0';
  local_138[0].ReserveSpace[3] = '\0';
  RtlGetVersion();
  wil_InitializeFeatureStaging();
  Feature_WdfUmdfRedirectorUmaSecurity01__private_IsEnabledDeviceUsageNoInline();
  WPP_INIT_CONTROL_ARRAY(pWVar3);
  WppLoadTracingSupport();
  WPP_MAIN_CB[0].Control.RegistryPath = (_UNICODE_STRING *)0x0;
  WppInitKm((_DRIVER_OBJECT *)&pWVar3->Control,p_Var4);
  local_148[0] = (undefined8 *)0x0;
  uVar5 = (uchar)local_148;
  RdDriverObject = param_1;
  uVar1 = IoAllocateDriverObjectExtension(param_1,DriverEntry,8);
  if (((int)uVar1 < 0) || (local_148[0] == (undefined8 *)0x0)) {
    if ((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
       ((((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0 &&
        (1 < (WPP_GLOBAL_Control->Control).Level)))) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,10,
              WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids);
    }
    if (-1 < (int)uVar1) {
      return uVar1;
    }
  }
  else {
    *local_148[0] = 0;
    p_Var4 = (_UNICODE_STRING *)0x38444d55;
    pRVar2 = (RdDriver *)ExAllocatePool2(0x40,0x1e0);
    if (pRVar2 == (RdDriver *)0x0) {
      *local_148[0] = 0;
    }
    else {
      pRVar2 = RdDriver::RdDriver(pRVar2,param_1,p_Var4,uVar5);
      *local_148[0] = pRVar2;
      if (pRVar2 != (RdDriver *)0x0) {
        uVar1 = (uint)pRVar2->_padding_;
        if (-1 < (int)uVar1) {
          return uVar1;
        }
        if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
            (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
           (1 < (WPP_GLOBAL_Control->Control).Level)) {
          WPP_SF_D((WPP_GLOBAL_Control->Control).Logger,0xc,
                   WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids,uVar1);
        }
        goto LAB_140024271;
      }
    }
    uVar1 = 0xc0000017;
    if (((WPP_GLOBAL_Control != (WPP_PROJECT_CONTROL_BLOCK *)&WPP_GLOBAL_Control) &&
        (((WPP_GLOBAL_Control->Control).Flags[0] & 1) != 0)) &&
       (1 < (WPP_GLOBAL_Control->Control).Level)) {
      WPP_SF_((WPP_GLOBAL_Control->Control).Logger,0xb,
              WPP_0fa67c068ee43f9736b7d395751c01ce_Traceguids);
    }
  }
LAB_140024271:
  RdDriver::RdUnload(param_1);
  return uVar1;
}



===== wil_InitializeFeatureStaging @ 1400242a4 =====

long __cdecl wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  wil_details_FeatureDescriptor *pwVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    pwVar3 = &Feature_GatePerf__private_descriptor;
    while (pwVar3 = wil_details_FeatureDescriptors_SkipPadding((ulong64)pwVar3),
          pwVar3 != (wil_details_FeatureDescriptor *)0x0) {
      if (((pwVar3->isAlwaysDisabled == '\0') && (pwVar3->isAlwaysEnabled == '\0')) &&
         (pwVar3->changeTime == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = (void *)0x0;
        }
        break;
      }
      pwVar3 = pwVar3 + 1;
    }
    g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
    iVar2 = RtlRegisterFeatureUsageProvider
                      (wil_details_OnFeatureUsageProviderFlushNotification,0,
                       &g_wil_details_featureUsageProvider);
    if (iVar2 != 0) {
      if (bVar1) {
        iVar2 = 0;
      }
      g_wil_details_featureUsageProvider = (void *)0x0;
      return iVar2;
    }
  }
  return 0;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140024394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  long lVar1;
  wil_details_FeatureDescriptor *pwVar2;
  wil_details_FeatureDescriptor *pwVar3;
  ulong64 uVar4;
  undefined1 auStack_58 [32];
  wil_details_FeatureStateCache local_38;
  undefined8 local_30;
  _RTL_FEATURE_CONFIGURATION local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  pwVar3 = &Feature_GatePerf__private_descriptor;
  do {
    pwVar2 = wil_details_FeatureDescriptors_SkipPadding((ulong64)pwVar3);
    if (pwVar2 == (wil_details_FeatureDescriptor *)0x0) {
      return;
    }
    local_30 = 0;
    local_38.exchange64 = 0;
    local_28.FeatureId = 0;
    local_28._4_4_ = 0;
    local_28.VariantPayload = 0;
    if ((pwVar2->isAlwaysDisabled == '\0') && (pwVar2->isAlwaysEnabled == '\0')) {
      lVar1 = RtlQueryFeatureConfiguration
                        (pwVar2->featureId,1 < (byte)(pwVar2->changeTime - 2),&local_30,&local_28);
      if (lVar1 == -0x7fffffde) {
        local_38.exchange64 = 0x206;
        uVar4 = 0x206;
        do {
          pwVar2->featureStateCache->exchange64 = uVar4;
          pwVar2 = wil_details_FeatureDescriptors_SkipPadding((ulong64)(pwVar2 + 1));
        } while (pwVar2 != (wil_details_FeatureDescriptor *)0x0);
        return;
      }
    }
    else {
      lVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(lVar1,&local_28,&local_38);
    pwVar3 = pwVar2 + 1;
    pwVar2->featureStateCache->exchange64 = local_38.exchange64;
  } while( true );
}


