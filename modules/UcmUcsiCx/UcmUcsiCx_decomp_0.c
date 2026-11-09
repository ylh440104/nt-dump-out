
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
  *param_6 = PTR_DAT_140021048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140021048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140021060,&local_18,0,0,param_5,param_6);
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



===== __C_specific_handler @ 1400010cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _PushBackOne2<UcmUcsiCx::UCMUCSI_OPM_COMMAND_const&___ptr64> @ 1400010e0 =====

/* private: bool __cdecl utl::vector<struct UcmUcsiCx::UCMUCSI_OPM_COMMAND,class
   utl::allocator<struct UcmUcsiCx::UCMUCSI_OPM_COMMAND> >::_PushBackOne2<struct
   UcmUcsiCx::UCMUCSI_OPM_COMMAND const & __ptr64>(struct UcmUcsiCx::UCMUCSI_OPM_COMMAND const &
   __ptr64) __ptr64 */

bool __thiscall
utl::vector<UcmUcsiCx::UCMUCSI_OPM_COMMAND,utl::allocator<UcmUcsiCx::UCMUCSI_OPM_COMMAND>_>::
_PushBackOne2<UcmUcsiCx::UCMUCSI_OPM_COMMAND_const&___ptr64>
          (vector<UcmUcsiCx::UCMUCSI_OPM_COMMAND,utl::allocator<UcmUcsiCx::UCMUCSI_OPM_COMMAND>_>
           *this,UCMUCSI_OPM_COMMAND *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  bool bVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  __uint64 _Var7;
  UCMUCSI_OPM_COMMAND *pUVar8;
  ulonglong uVar9;
  bool bVar10;
  
  if (*(longlong *)(this + 8) == *(longlong *)(this + 0x10)) {
    uVar9 = (longlong)param_1 - *(longlong *)this;
    uVar5 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 5) * -0xf0f0f0f0f0f0f0f;
    _Var7 = (uVar5 >> 2) * 7 + 8;
    if (0x3c3c3c3c3c3c3c < _Var7) {
      _Var7 = 0x3c3c3c3c3c3c3c;
    }
    bVar10 = false;
    if (uVar5 < _Var7) {
      bVar3 = _SetCapacity(this,_Var7);
      if (bVar3) {
        if (uVar9 < (ulonglong)((longlong)*(undefined8 **)(this + 8) - *(longlong *)this)) {
          param_1 = (UCMUCSI_OPM_COMMAND *)(*(longlong *)this + uVar9);
        }
        lVar4 = 4;
        puVar2 = *(undefined8 **)(this + 8);
        do {
          pUVar8 = param_1;
          puVar6 = puVar2;
          uVar1 = *(undefined8 *)&(pUVar8->DataBlock).field0_0x0.m_DataBlock.CCI.AsUInt32;
          *puVar6 = *(undefined8 *)pUVar8;
          puVar6[1] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 4);
          puVar6[2] = *(undefined8 *)
                       ((longlong)&(pUVar8->DataBlock).field0_0x0.m_DataBlock.Control.AsUInt64 + 4);
          puVar6[3] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x14);
          puVar6[4] = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0xc);
          puVar6[5] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x24);
          puVar6[6] = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x1c)
          ;
          puVar6[7] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x34);
          puVar6[8] = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x2c)
          ;
          puVar6[9] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x44);
          puVar6[10] = *(undefined8 *)
                        ((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x3c);
          puVar6[0xb] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x54);
          puVar6[0xc] = *(undefined8 *)
                         ((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x4c);
          puVar6[0xd] = uVar1;
          uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 100);
          param_1 = (UCMUCSI_OPM_COMMAND *)((longlong)&(pUVar8->DataBlock).field0_0x0 + 0x7c);
          puVar6[0xe] = *(undefined8 *)
                         ((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x5c);
          puVar6[0xf] = uVar1;
          lVar4 = lVar4 + -1;
          puVar2 = puVar6 + 0x10;
        } while (lVar4 != 0);
        uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x74);
        bVar10 = true;
        puVar6[0x10] = *(undefined8 *)param_1;
        puVar6[0x11] = uVar1;
        uVar1 = *(undefined8 *)((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x84);
        puVar6[0x12] = *(undefined8 *)
                        ((pUVar8->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x7c);
        puVar6[0x13] = uVar1;
        *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x220;
      }
    }
  }
  else {
    bVar10 = false;
  }
  return bVar10;
}



===== operator= @ 140001208 =====

/* public: class UcmUcsiCx::UcsiDataBlock & __ptr64 __cdecl
   UcmUcsiCx::UcsiDataBlock::operator=(class UcmUcsiCx::UcsiDataBlock const & __ptr64) __ptr64 */

UcsiDataBlock * __thiscall
UcmUcsiCx::UcsiDataBlock::operator=(UcsiDataBlock *this,UcsiDataBlock *param_1)

{
  ulong64 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  _UCSI_CCI _Var4;
  UcsiDataBlock *pUVar5;
  UcsiDataBlock *pUVar6;
  UcsiDataBlock *pUVar7;
  UcsiDataBlock *pUVar8;
  longlong lVar9;
  
  if (this != param_1) {
    lVar9 = 4;
    pUVar6 = this;
    pUVar8 = param_1;
    do {
      pUVar7 = pUVar8;
      pUVar5 = pUVar6;
      uVar3 = *(undefined2 *)&(pUVar7->field0_0x0).m_DataBlock.field_0x2;
      _Var4.AsUInt32 = (pUVar7->field0_0x0).m_DataBlock.CCI.AsUInt32;
      uVar1 = (pUVar7->field0_0x0).m_DataBlock.Control.AsUInt64;
      (pUVar5->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 =
           (pUVar7->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16;
      *(undefined2 *)&(pUVar5->field0_0x0).m_DataBlock.field_0x2 = uVar3;
      (pUVar5->field0_0x0).m_DataBlock.CCI.AsUInt32 = _Var4.AsUInt32;
      (pUVar5->field0_0x0).m_DataBlock.Control.AsUInt64 = uVar1;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 8);
      *(undefined8 *)(pUVar5->field0_0x0).m_DataBlockEx.MessageIn =
           *(undefined8 *)(pUVar7->field0_0x0).m_DataBlockEx.MessageIn;
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 8) = uVar2;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x18);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x10) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x10);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x18) = uVar2;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x28);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x20) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x20);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x28) = uVar2;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x38);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x30) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x30);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x38) = uVar2;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x48);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x40) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x40);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x48) = uVar2;
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x58);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x50) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x50);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x58) = uVar2;
      pUVar6 = (UcsiDataBlock *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x70);
      uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x68);
      pUVar8 = (UcsiDataBlock *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x70);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x60) =
           *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x60);
      *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x68) = uVar2;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar3 = *(undefined2 *)&(pUVar8->field0_0x0).m_DataBlock.field_0x2;
    _Var4.AsUInt32 = (pUVar8->field0_0x0).m_DataBlock.CCI.AsUInt32;
    uVar2 = *(undefined8 *)((pUVar7->field0_0x0).m_DataBlockEx.MessageIn + 0x78);
    (pUVar6->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 =
         (pUVar8->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16;
    *(undefined2 *)&(pUVar6->field0_0x0).m_DataBlock.field_0x2 = uVar3;
    (pUVar6->field0_0x0).m_DataBlock.CCI.AsUInt32 = _Var4.AsUInt32;
    *(undefined8 *)((pUVar5->field0_0x0).m_DataBlockEx.MessageIn + 0x78) = uVar2;
    this->m_UcsiDataBlockExEnabled = param_1->m_UcsiDataBlockExEnabled;
  }
  return this;
}



===== AddCommand @ 140001290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl UcmUcsiCx::CommandList::AddCommand(struct UcmUcsiCx::UCMUCSI_OPM_COMMAND *
   __ptr64) __ptr64 */

bool __thiscall UcmUcsiCx::CommandList::AddCommand(CommandList *this,UCMUCSI_OPM_COMMAND *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  bool bVar3;
  longlong lVar4;
  undefined8 *puVar5;
  UCMUCSI_OPM_COMMAND *pUVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xd,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  bVar3 = false;
  (**(code **)(WdfFunctions_01023 + 0x9e0))(WdfDriverGlobals,this->m_OpmCommandListLock);
  puVar1 = *(undefined8 **)&this->field_0x18;
  if ((longlong)puVar1 - *(longlong *)&this->m_OpmCommandList == 0x1540) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xe,
                         &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids,
                         (char)this->m_Ppm->_padding_,
                         (char)(param_1->DataBlock).field0_0x0.m_DataBlock.Control.AsUInt64);
    }
  }
  else if (puVar1 == *(undefined8 **)&this->field_0x20) {
    bVar3 = utl::
            vector<UcmUcsiCx::UCMUCSI_OPM_COMMAND,utl::allocator<UcmUcsiCx::UCMUCSI_OPM_COMMAND>_>::
            _PushBackOne2<UcmUcsiCx::UCMUCSI_OPM_COMMAND_const&___ptr64>
                      (&this->m_OpmCommandList,param_1);
  }
  else {
    lVar4 = 4;
    do {
      pUVar6 = param_1;
      puVar5 = puVar1;
      uVar2 = *(undefined8 *)&(pUVar6->DataBlock).field0_0x0.m_DataBlock.CCI.AsUInt32;
      *puVar5 = *(undefined8 *)pUVar6;
      puVar5[1] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 4);
      puVar5[2] = *(undefined8 *)
                   ((longlong)&(pUVar6->DataBlock).field0_0x0.m_DataBlock.Control.AsUInt64 + 4);
      puVar5[3] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x14);
      puVar5[4] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0xc);
      puVar5[5] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x24);
      puVar5[6] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x1c);
      puVar5[7] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x34);
      puVar5[8] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x2c);
      puVar5[9] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x44);
      puVar5[10] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x3c);
      puVar5[0xb] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x54);
      puVar5[0xc] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x4c);
      puVar5[0xd] = uVar2;
      uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 100);
      param_1 = (UCMUCSI_OPM_COMMAND *)((longlong)&(pUVar6->DataBlock).field0_0x0 + 0x7c);
      puVar5[0xe] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x5c);
      puVar5[0xf] = uVar2;
      lVar4 = lVar4 + -1;
      puVar1 = puVar5 + 0x10;
    } while (lVar4 != 0);
    uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x74);
    bVar3 = true;
    puVar5[0x10] = *(undefined8 *)param_1;
    puVar5[0x11] = uVar2;
    uVar2 = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x84);
    puVar5[0x12] = *(undefined8 *)((pUVar6->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x7c);
    puVar5[0x13] = uVar2;
    *(longlong *)&this->field_0x18 = *(longlong *)&this->field_0x18 + 0x220;
  }
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,this->m_OpmCommandListLock);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xf,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  return bVar3;
}



===== ClearList @ 140001460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::CommandList::ClearList(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandList::ClearList(CommandList *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x12,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x9e0))(WdfDriverGlobals,this->m_OpmCommandListLock);
  if (*(longlong *)&this->m_OpmCommandList != *(longlong *)&this->field_0x18) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,4,0x13,
                        &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids,
                        (char)this->m_Ppm->_padding_);
    }
    this->field_0x18 = this->m_OpmCommandList;
    *(undefined7 *)&this->field_0x19 = *(undefined7 *)&this->field_0x11;
  }
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,this->m_OpmCommandListLock);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x14,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  return;
}



===== Deinitialize @ 14000157c =====

/* public: void __cdecl UcmUcsiCx::CommandList::Deinitialize(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandList::Deinitialize(CommandList *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x10,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  ClearList(this);
  this->m_Ppm = (Ppm *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x11,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  return;
}



===== Initialize @ 14000162c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiCx::CommandList::Initialize(class UcmUcsiCx::Ppm * __ptr64) __ptr64
    */

long __thiscall UcmUcsiCx::CommandList::Initialize(CommandList *this,Ppm *param_1)

{
  int iVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,10,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  this->m_Ppm = param_1;
  local_18 = 0;
  local_38 = 0;
  uStack_40 = 0;
  uStack_30 = 0x100000001;
  uStack_20 = 0;
  local_48 = 0x38;
  local_28 = param_1->_padding_;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x9d8))
                    (WdfDriverGlobals,&local_48,&this->m_OpmCommandListLock);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xb,
                       &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0xc,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  return iVar1;
}



===== PopOldestCommand @ 140001780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl UcmUcsiCx::CommandList::PopOldestCommand(struct
   UcmUcsiCx::UCMUCSI_OPM_COMMAND * __ptr64) __ptr64 */

bool __thiscall
UcmUcsiCx::CommandList::PopOldestCommand(CommandList *this,UCMUCSI_OPM_COMMAND *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  UCMUCSI_OPM_COMMAND *pUVar5;
  bool bVar6;
  undefined4 *puVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x15,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  bVar6 = false;
  (**(code **)(WdfFunctions_01023 + 0x9e0))(WdfDriverGlobals,this->m_OpmCommandListLock);
  if (*(undefined8 **)&this->m_OpmCommandList != *(undefined8 **)&this->field_0x18) {
    lVar4 = 4;
    puVar2 = *(undefined8 **)&this->m_OpmCommandList;
    do {
      pUVar5 = param_1;
      puVar3 = puVar2;
      uVar1 = puVar3[1];
      *(undefined8 *)pUVar5 = *puVar3;
      *(undefined8 *)&(pUVar5->DataBlock).field0_0x0.m_DataBlock.CCI.AsUInt32 = uVar1;
      uVar1 = puVar3[3];
      *(undefined8 *)((longlong)&(pUVar5->DataBlock).field0_0x0.m_DataBlock.Control.AsUInt64 + 4) =
           puVar3[2];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 4) = uVar1;
      uVar1 = puVar3[5];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0xc) = puVar3[4];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x14) = uVar1;
      uVar1 = puVar3[7];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x1c) = puVar3[6];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x24) = uVar1;
      uVar1 = puVar3[9];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x2c) = puVar3[8];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x34) = uVar1;
      uVar1 = puVar3[0xb];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x3c) = puVar3[10];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x44) = uVar1;
      uVar1 = puVar3[0xd];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x4c) = puVar3[0xc];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x54) = uVar1;
      param_1 = (UCMUCSI_OPM_COMMAND *)((longlong)&(pUVar5->DataBlock).field0_0x0 + 0x7c);
      uVar1 = puVar3[0xf];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x5c) = puVar3[0xe];
      *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 100) = uVar1;
      lVar4 = lVar4 + -1;
      puVar2 = puVar3 + 0x10;
    } while (lVar4 != 0);
    uVar1 = puVar3[0x11];
    bVar6 = true;
    *(undefined8 *)param_1 = puVar3[0x10];
    *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x74) = uVar1;
    uVar1 = puVar3[0x13];
    *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x7c) = puVar3[0x12];
    *(undefined8 *)((pUVar5->DataBlock).field0_0x0.m_DataBlockEx.MessageIn + 0x84) = uVar1;
    lVar4 = ((*(longlong *)&this->field_0x18 - *(longlong *)&this->m_OpmCommandList) + -0x220) /
            0x220;
    if (lVar4 != 0) {
      puVar7 = (undefined4 *)(*(longlong *)&this->m_OpmCommandList + 0x438);
      do {
        puVar7[-0x10e] = puVar7[-0x86];
        UcsiDataBlock::operator=
                  ((UcsiDataBlock *)(puVar7 + -0x10d),(UcsiDataBlock *)(puVar7 + -0x85));
        puVar7[-0x88] = *puVar7;
        *(undefined1 *)(puVar7 + -0x87) = *(undefined1 *)(puVar7 + 1);
        puVar7 = puVar7 + 0x88;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    *(longlong *)&this->field_0x18 = *(longlong *)&this->field_0x18 + -0x220;
  }
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,this->m_OpmCommandListLock);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x16,
                     &WPP_85cb14f422cb39fc20fbd114dff9a7a5_Traceguids);
  }
  return bVar6;
}



===== _SetCapacity @ 140001968 =====

/* private: bool __cdecl utl::vector<struct UcmUcsiCx::UCMUCSI_OPM_COMMAND,class
   utl::allocator<struct UcmUcsiCx::UCMUCSI_OPM_COMMAND> >::_SetCapacity(unsigned __int64) __ptr64
    */

bool __thiscall
utl::vector<UcmUcsiCx::UCMUCSI_OPM_COMMAND,utl::allocator<UcmUcsiCx::UCMUCSI_OPM_COMMAND>_>::
_SetCapacity(vector<UcmUcsiCx::UCMUCSI_OPM_COMMAND,utl::allocator<UcmUcsiCx::UCMUCSI_OPM_COMMAND>_>
             *this,__uint64 param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  
  if (param_1 < 0x78787878787879) {
    puVar8 = (undefined8 *)ExAllocatePool2(0x40,param_1 * 0x220,0x69736355);
    if ((puVar8 != (undefined8 *)0x0) && (puVar8 != (undefined8 *)0xffffffffffffffff)) {
      lVar1 = *(longlong *)this;
      lVar9 = (*(longlong *)(this + 8) - lVar1 >> 5) * -0xf0f0f0f0f0f0f0f;
      if (lVar9 != 0) {
        puVar12 = puVar8;
        do {
          lVar13 = 4;
          puVar6 = puVar12;
          puVar7 = (undefined8 *)((lVar1 - (longlong)puVar8) + (longlong)puVar12);
          do {
            puVar11 = puVar7;
            puVar10 = puVar6;
            uVar5 = puVar11[1];
            *puVar10 = *puVar11;
            puVar10[1] = uVar5;
            uVar5 = puVar11[3];
            puVar10[2] = puVar11[2];
            puVar10[3] = uVar5;
            uVar5 = puVar11[5];
            puVar10[4] = puVar11[4];
            puVar10[5] = uVar5;
            uVar5 = puVar11[7];
            puVar10[6] = puVar11[6];
            puVar10[7] = uVar5;
            uVar5 = puVar11[9];
            puVar10[8] = puVar11[8];
            puVar10[9] = uVar5;
            uVar5 = puVar11[0xb];
            puVar10[10] = puVar11[10];
            puVar10[0xb] = uVar5;
            uVar5 = puVar11[0xd];
            puVar10[0xc] = puVar11[0xc];
            puVar10[0xd] = uVar5;
            uVar5 = puVar11[0xf];
            puVar10[0xe] = puVar11[0xe];
            puVar10[0xf] = uVar5;
            lVar13 = lVar13 + -1;
            puVar6 = puVar10 + 0x10;
            puVar7 = puVar11 + 0x10;
          } while (lVar13 != 0);
          uVar2 = *(undefined4 *)((longlong)puVar11 + 0x84);
          uVar3 = *(undefined4 *)(puVar11 + 0x11);
          uVar4 = *(undefined4 *)((longlong)puVar11 + 0x8c);
          puVar12 = puVar12 + 0x44;
          *(undefined4 *)(puVar10 + 0x10) = *(undefined4 *)(puVar11 + 0x10);
          *(undefined4 *)((longlong)puVar10 + 0x84) = uVar2;
          *(undefined4 *)(puVar10 + 0x11) = uVar3;
          *(undefined4 *)((longlong)puVar10 + 0x8c) = uVar4;
          uVar5 = puVar11[0x13];
          puVar10[0x12] = puVar11[0x12];
          puVar10[0x13] = uVar5;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
      }
      lVar1 = *(longlong *)this;
      lVar9 = *(longlong *)(this + 8);
      if (lVar1 != -1) {
        *(longlong *)(this + 8) = lVar1;
        ExFreePoolWithTag(lVar1,0x69736355);
      }
      *(undefined8 **)this = puVar8;
      *(undefined8 **)(this + 8) = puVar8 + (lVar9 - lVar1 >> 5) * 4;
      *(undefined8 **)(this + 0x10) = puVar8 + param_1 * 0x44;
      return true;
    }
  }
  return false;
}



===== WPP_RECORDER_SF_ @ 140001ae0 =====

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



===== WPP_RECORDER_SF_q @ 140001bb8 =====

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



===== WPP_RECORDER_SF_qd @ 140001cb4 =====

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



===== CancellingRequestDueToStopEntry @ 140001de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::CancellingRequestDueToStopEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
CancellingRequestDueToStopEntry(void *param_1)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2d,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x30,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  cVar1 = (**(code **)(WdfFunctions_01023 + 0x810))
                    (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x18));
  if (cVar1 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x31,
                      &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
                      (char)**(undefined8 **)((longlong)param_1 + 0x38));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x32,
                       &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2e,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
  }
  return 0;
}



===== CheckForCompletionEntry @ 140001f60 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::CheckForCompletionEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
CheckForCompletionEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = CommandHandler::IsCommandCompletionSetToTrue(param_1);
  return EVar1;
}



===== CheckForMoreCommandsEntry @ 140001f80 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::CheckForMoreCommandsEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
CheckForMoreCommandsEntry(void *param_1)

{
  int iVar1;
  bool bVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3d,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  *(undefined4 *)((longlong)param_1 + 0x510) = 0xc0000001;
  *(undefined4 *)((longlong)param_1 + 0x514) = 0;
  LOCK();
  iVar1 = *(int *)((longlong)param_1 + 0x4e4);
  *(int *)((longlong)param_1 + 0x4e4) = 0;
  UNLOCK();
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (iVar1 != 0)) {
    RtlAssert("oldValue == 0","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp",
              0x2a8,0);
  }
  bVar2 = CommandList::PopOldestCommand
                    ((CommandList *)((longlong)param_1 + 0x40),
                     (UCMUCSI_OPM_COMMAND *)((longlong)param_1 + 0x2c4));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3e,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return (-(ushort)bVar2 & 9) + 0xb;
}



===== CopyUcsiControlAndMessageOutFrom @ 140002090 =====

/* public: void __cdecl UcmUcsiCx::UcsiDataBlock::CopyUcsiControlAndMessageOutFrom(class
   UcmUcsiCx::UcsiDataBlock const & __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::UcsiDataBlock::CopyUcsiControlAndMessageOutFrom
          (UcsiDataBlock *this,UcsiDataBlock *param_1)

{
  byte bVar1;
  uchar *_Dst;
  _UCSI_MESSAGE_OUT *_Src;
  ulonglong _Size;
  
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
     (this->m_UcsiDataBlockExEnabled != param_1->m_UcsiDataBlockExEnabled)) {
    RtlAssert("m_UcsiDataBlockExEnabled == Other.m_UcsiDataBlockExEnabled",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\UcsiDataBlock.h",0x5e);
  }
  (this->field0_0x0).m_DataBlock.Control.AsUInt64 =
       (param_1->field0_0x0).m_DataBlock.Control.AsUInt64;
  if (this->m_UcsiDataBlockExEnabled == false) {
    _Dst = (uchar *)((longlong)&this->field0_0x0 + 0x20);
    _Dst[0] = '\0';
    _Dst[1] = '\0';
    _Dst[2] = '\0';
    _Dst[3] = '\0';
    _Dst[4] = '\0';
    _Dst[5] = '\0';
    _Dst[6] = '\0';
    _Dst[7] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x18] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x19] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1a] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1b] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1c] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1d] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1e] = '\0';
    (this->field0_0x0).m_DataBlockEx.MessageIn[0x1f] = '\0';
    bVar1 = (param_1->field0_0x0).m_DataBlock.Control._s_1.DataLength;
    if (bVar1 == 0) {
      return;
    }
    _Size = 0x10;
    if (bVar1 < 0x10) {
      _Size = (ulonglong)bVar1;
    }
    _Src = &(param_1->field0_0x0).m_DataBlock.MessageOut;
  }
  else {
    _Dst = (this->field0_0x0).m_DataBlockEx.MessageOut;
    _Size = 0xff;
    memset(_Dst,0,0xff);
    bVar1 = (param_1->field0_0x0).m_DataBlock.Control._s_1.DataLength;
    if (bVar1 == 0) {
      return;
    }
    if (bVar1 != 0xff) {
      _Size = (ulonglong)bVar1;
    }
    _Src = (_UCSI_MESSAGE_OUT *)(param_1->field0_0x0).m_DataBlockEx.MessageOut;
  }
  memmove(_Dst,_Src,_Size);
  return;
}



===== EnqueueAck @ 140002170 =====

/* public: void __cdecl UcmUcsiCx::CommandHandler::EnqueueAck(bool) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::EnqueueAck(CommandHandler *this,bool param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x27,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  this->m_ShouldAckConnectChange = param_1;
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,(ushort)!param_1 * 2 + 1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x28,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== EnqueueEvent @ 140002230 =====

/* public: void __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EnqueueEvent(enum UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::Event) __ptr64 */

void __thiscall
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
          (OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *this,Event param_1)

{
  SmFx::StateMachineEngine::EnqueueEvent(&this->m_engine,(ushort)param_1);
  return;
}



===== EvtCommandTimerFuncThunk @ 140002250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl UcmUcsiCx::CommandHandler::EvtCommandTimerFuncThunk(struct
   WDFTIMER__ * __ptr64) */

void __cdecl UcmUcsiCx::CommandHandler::EvtCommandTimerFuncThunk(WDFTIMER__ *param_1)

{
  UCMUCSIPPM__ *pUVar1;
  Ppm *pPVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2b,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  pUVar1 = (UCMUCSIPPM__ *)(**(code **)(WdfFunctions_01023 + 0xa08))(WdfDriverGlobals);
  pPVar2 = Ppm::GetContextFromObject(pUVar1);
  SetUnrecoverableFailureContext(&(pPVar2->m_Opm).m_CommandHandler,CommandTimeout,0x102);
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)&(pPVar2->m_Opm).m_CommandHandler,7);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2c,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== EvtLogEventEnqueue @ 140002330 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::EvtLogEventEnqueue(enum
   UcmUcsiCx::CommandHandlerStateMachine<class UcmUcsiCx::CommandHandler>::EventId) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::EvtLogEventEnqueue(CommandHandler *this,EventId param_1)

{
  EventId EVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined6 in_register_00000012;
  
  uVar3 = (undefined1)(param_1 >> 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    EVar1 = param_1;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      uVar2 = 5;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x51,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
      EVar1 = CONCAT11(uVar3,uVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                        CONCAT62(in_register_00000012,EVar1),3,0x52,
                        &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,(char)param_1);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x53,
                         &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
      }
    }
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 140002400 =====

/* private: static void __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EvtLogEventEnqueueThunk
          (void *param_1,ushort param_2)

{
  CommandHandler::EvtLogEventEnqueue(param_1,param_2);
  return;
}



===== EvtLogMachineException @ 140002418 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::EvtLogMachineException(enum
   SmFx::MachineException,enum UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EventId,enum UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::StateId) __ptr64 */

void __thiscall
UcmUcsiCx::CommandHandler::EvtLogMachineException
          (CommandHandler *this,MachineException param_1,EventId param_2,StateId param_3)

{
  undefined4 in_register_00000014;
  undefined8 uVar1;
  undefined6 in_register_00000082;
  undefined8 uVar2;
  char *pcVar3;
  
  uVar2 = CONCAT62(in_register_00000082,param_2);
  uVar1 = CONCAT44(in_register_00000014,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    this = (CommandHandler *)WPP_GLOBAL_Control;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      this = *(CommandHandler **)(WPP_GLOBAL_Control + 0x40);
      uVar1 = CONCAT71((int7)((ulonglong)uVar1 >> 8),5);
      uVar2 = 3;
      WPP_RECORDER_SF_(this,5,3,0x4e,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this = *(CommandHandler **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_LLL(this,uVar1,uVar2,0x4f,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                          (char)param_1,(char)param_2,(char)(param_3 & 0xffff));
    }
  }
  if (param_1 == UnhandledEvent) {
    pcVar3 = "[Command Handler] SmFx Unhandled Event exception";
  }
  else if (param_1 == EventQueueOverflow) {
    pcVar3 = "[Command Handler] SmFx Event Queue Overflow exception";
  }
  else if (param_1 == StackOverflow) {
    pcVar3 = "[Command Handler] SmFx Stack Overflow exception";
  }
  else {
    pcVar3 = "[Command Handler] SmFx Unknown exception";
  }
  MicrosoftTelemetryAssertTriggeredArgsMsgKM(this,(uint)param_2,param_3 & 0xffff,pcVar3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x50,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== EvtLogMachineExceptionThunk @ 140002540 =====

/* private: static void __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EvtLogMachineExceptionThunk(void * __ptr64,enum
   SmFx::MachineException,unsigned short,unsigned short) */

void __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  undefined2 in_register_0000008a;
  
  CommandHandler::EvtLogMachineException
            (param_1,param_2,param_3,CONCAT22(in_register_0000008a,param_4));
  return;
}



===== EvtLogTransition @ 140002558 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::EvtLogTransition(enum SmFx::TransitionType,enum
   UcmUcsiCx::CommandHandlerStateMachine<class UcmUcsiCx::CommandHandler>::StateId,enum
   UcmUcsiCx::CommandHandlerStateMachine<class UcmUcsiCx::CommandHandler>::EventId,enum
   UcmUcsiCx::CommandHandlerStateMachine<class UcmUcsiCx::CommandHandler>::StateId) __ptr64 */

void __thiscall
UcmUcsiCx::CommandHandler::EvtLogTransition
          (CommandHandler *this,TransitionType param_1,StateId param_2,EventId param_3,
          StateId param_4)

{
  TransitionType TVar1;
  undefined4 in_register_00000014;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    TVar1 = param_1;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      TVar1 = CONCAT31((int3)(param_1 >> 8),5);
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x54,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LLLL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,TVar1),3,
                 0x55,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids,(char)param_1,(char)param_2,
                 (char)param_3,(char)param_4);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x56,
                         &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
      }
    }
  }
  return;
}



===== EvtLogTransitionThunk @ 140002650 =====

/* private: static void __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EvtLogTransitionThunk(void * __ptr64,enum
   SmFx::TransitionType,unsigned short,unsigned short,unsigned short) */

void __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_0000008a;
  
  CommandHandler::EvtLogTransition
            (param_1,param_2,param_3,CONCAT22(in_register_0000008a,param_4),param_5);
  return;
}



===== EvtMachineDestroyed @ 140002670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::CommandHandler::EvtMachineDestroyed(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::EvtMachineDestroyed(CommandHandler *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x57,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x670))
            (WdfDriverGlobals,this->m_Ppm->_padding_,0,0x3ac,
             "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp");
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x58,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== EvtMachineDestroyedThunk @ 140002740 =====

/* private: static void __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EvtMachineDestroyedThunk
          (void *param_1)

{
  CommandHandler::EvtMachineDestroyed(param_1);
  return;
}



===== FailedEntry @ 140002760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::FailedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::FailedEntry
          (void *param_1)

{
  UnrecoverableFailureContext local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x4a,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x9e0))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x4f0));
  local_28.Type = *(LkdFailureType *)((longlong)param_1 + 0x4f8);
  local_28.SubType = *(LkdFailureSubType *)((longlong)param_1 + 0x4fc);
  local_28.UcsiCommandInOpm = *(_UCSI_COMMAND *)((longlong)param_1 + 0x500);
  local_28.UcsiCommandForPpm = *(_UCSI_COMMAND *)((longlong)param_1 + 0x504);
  local_28._16_8_ = *(undefined8 *)((longlong)param_1 + 0x508);
  (**(code **)(WdfFunctions_01023 + 0x9e8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x4f0));
  if ((((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (local_28.Type != HwRequestFailedByClient))
     && (local_28.Type != CommandTimeout)) {
    RtlAssert("failureContextCopy.Type == LkdFailureType::HwRequestFailedByClient || failureContextCopy.Type == LkdFailureType::CommandTimeout"
              ,"onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp",0x34d,0);
  }
  CxDevice::UnrecoverableFailureEncountered
            (*(CxDevice **)(*(longlong *)((longlong)param_1 + 0x10) + 0xd38),&local_28);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x4b,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return 0;
}



===== HardwareRequestCompleted @ 1400028c0 =====

/* public: static void __cdecl UcmUcsiCx::CommandHandler::HardwareRequestCompleted(class
   UcmUcsiCx::Ppm * __ptr64,long) */

void __cdecl UcmUcsiCx::CommandHandler::HardwareRequestCompleted(Ppm *param_1,long param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ushort uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x15,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (param_2 == 0) {
    uVar3 = 0xe;
  }
  else {
    if ((((param_1->m_Opm).m_CommandHandler.m_Ppm)->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue)
    {
      uVar1 = (uint)(((param_1->m_Opm).m_CommandHandler.m_InSendExParam)->DataBlockHeader).Control.
                    AsUInt64;
    }
    else {
      uVar1 = (uint)(param_1->m_Opm).m_CommandHandler.m_InBuffer.m_InSendParam.UcmUcsiDataBlock.
                    Control.AsUInt64;
    }
    uVar2 = (ulonglong)uVar1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar2 = *(ulonglong *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_qLL(uVar2,2,3,0x16,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                          (char)param_1->_padding_,(char)uVar1,(char)param_2);
    }
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (uVar2,uVar1 & 0xff,param_2,"Client driver failed hardware request");
    SetUnrecoverableFailureContext
              (&(param_1->m_Opm).m_CommandHandler,HwRequestFailedByClient,param_2);
    uVar3 = 0xd;
  }
  SmFx::StateMachineEngine::EnqueueEvent
            ((StateMachineEngine *)&(param_1->m_Opm).m_CommandHandler,uVar3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x17,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== Initialize @ 140002a10 =====

/* public: long __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::Initialize(struct UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::StateMachineEngineConfig const & __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::Initialize
          (CommandHandlerStateMachine<UcmUcsiCx::CommandHandler> *this,
          StateMachineEngineConfig *param_1)

{
  long lVar1;
  STATE_MACHINE_ENGINE_CONFIG local_58;
  
  local_58._28_4_ = 0;
  local_58._66_4_ = 0;
  local_58._70_2_ = 0;
  local_58.machineSpec = &c_specification;
  local_58.poolTag = *(uint *)(param_1 + 8);
  local_58.deviceObject = *(_DEVICE_OBJECT **)param_1;
  local_58.logExceptionCallback = EvtLogMachineExceptionThunk;
  local_58.logEventEnqueueCallback = EvtLogEventEnqueueThunk;
  local_58.logTransitionCallback = EvtLogTransitionThunk;
  local_58.machineDestroyedCallback = EvtMachineDestroyedThunk;
  local_58.isWorkerRequired = true;
  local_58.stackSize = '\x05';
  local_58.context = this;
  lVar1 = SmFx::StateMachineEngine::Initialize(&this->m_engine,&local_58);
  return lVar1;
}



===== IsAutoAckDisabledEntry @ 140002a90 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::IsAutoAckDisabledEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::IsAutoAckDisabledEntry
          (void *param_1)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x33,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  cVar1 = *(char *)((longlong)param_1 + 0x590);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x34,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return (-(ushort)(cVar1 != '\0') & 0xfff7) + 0x14;
}



===== IsCommandCompletionSetToTrue @ 140002b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum UcmUcsiCx::CommandHandlerStateMachine<class UcmUcsiCx::CommandHandler>::Event
   __cdecl UcmUcsiCx::CommandHandler::IsCommandCompletionSetToTrue(void) __ptr64 */

Event __thiscall UcmUcsiCx::CommandHandler::IsCommandCompletionSetToTrue(CommandHandler *this)

{
  UcsiDataBlock *this_00;
  byte bVar1;
  uint uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x35,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  bVar1 = 0;
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
     ((this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control._s_1.Command != 1)) {
    RtlAssert("m_CurrentOpmCommand.DataBlock.GetUcsiCommand() == UcsiCommandPpmReset",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp",0x234,0);
  }
  if ((this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
    uVar2 = (this->m_OutExParam->DataBlockHeader).CCI.AsUInt32;
  }
  else {
    uVar2 = (this->m_OutParam).UcmUcsiDataBlock.CCI.AsUInt32;
  }
  (**(code **)(WdfFunctions_01023 + 0x9e0))(WdfDriverGlobals,this->m_CachedCommandDataLock);
  this_00 = &this->m_CachedCommandCompletionData;
  (this->m_CachedCommandCompletionData).m_UcsiDataBlockExEnabled =
       (this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue;
  (this_00->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 = (this->m_Ppm->m_UcsiVersion).AsUInt16;
  UcsiDataBlock::CopyUcsiControlAndMessageOutFrom(this_00,&(this->m_CurrentOpmCommand).DataBlock);
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && ((uVar2 & 0xff00) != 0)) {
    RtlAssert("Other.DataLength == 0",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\UcsiDataBlock.h",0x70);
  }
  (this->m_CachedCommandCompletionData).field0_0x0.m_DataBlock.CCI.AsUInt32 = uVar2;
  UcsiDataBlock::PrettyPrintCci(this_00,(void *)this->m_Ppm->_padding_);
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,this->m_CachedCommandDataLock);
  if ((uVar2 >> 0x1b & 1) == 0) {
    this->m_SynchCommandRetrialCount = this->m_SynchCommandRetrialCount + 1;
  }
  else {
    bVar1 = 1;
    this->m_CommandStatus = 0;
    this->m_SynchCommandRetrialCount = 0;
    if (this->m_AutoAckEnableRequested == WdfFalse) {
      this->m_AutoAckEnabled = false;
      this->m_AutoAckEnableRequested = WdfUseDefault;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x36,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return (-(ushort)bVar1 & 9) + No;
}



===== IsInitialized @ 140002d54 =====

/* public: bool __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::IsInitialized(void) __ptr64 */

bool __thiscall
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::IsInitialized
          (CommandHandlerStateMachine<UcmUcsiCx::CommandHandler> *this)

{
  return (this->m_engine).m_impl != (StateMachineEngineImpl *)0x0;
}



===== MaxRetrialReachedEntry @ 140002d70 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::MaxRetrialReachedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::MaxRetrialReachedEntry
          (void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2f,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  uVar1 = 0x14;
  if (*(int *)((longlong)param_1 + 0x514) == 0x14) {
    CommandHandler::SetUnrecoverableFailureContext(param_1,CommandTimeout,0x102);
  }
  else {
    uVar1 = 0xb;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x30,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return uVar1;
}



===== PpmNotificationReceived @ 140002e3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::CommandHandler::PpmNotificationReceived(class
   UcmUcsiCx::UcsiDataBlock const & __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::CommandHandler::PpmNotificationReceived(CommandHandler *this,UcsiDataBlock *param_1)

{
  uchar *_Dst;
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  uint uVar5;
  ulonglong in_R8;
  bool bVar6;
  undefined *in_stack_ffffffffffffffb8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 3;
    in_stack_ffffffffffffffb8 = &WPP_be66407a1aed381749fba11a60c926d7_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1e,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  uVar5 = (param_1->field0_0x0).m_DataBlock.CCI.AsUInt32;
  if ((uVar5 >> 0x1c & 1) == 0) {
    if ((uVar5 >> 0x1d & 1) != 0) {
      LOCK();
      iVar1 = this->m_AckCommandPendingInPpm;
      this->m_AckCommandPendingInPpm = 0;
      UNLOCK();
      if (iVar1 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_R8 = 3;
          in_stack_ffffffffffffffb8 = &WPP_be66407a1aed381749fba11a60c926d7_Traceguids;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,3,0x21,
                            &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                            (char)this->m_Ppm->_padding_);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x20,
                              in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,
                              (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.
                                    Control.AsUInt64,(char)this->m_OpmCmdSeqNum);
        }
        if (this->m_AutoAckEnableRequested == WdfFalse) {
          this->m_AutoAckEnabled = false;
          this->m_AutoAckEnableRequested = WdfUseDefault;
        }
        SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,2);
      }
      ppuVar4 = &WPP_RECORDER_INITIALIZED;
      if (-1 < (int)(param_1->field0_0x0).m_DataBlock.CCI.AsUInt32) goto LAB_140002f06;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        ppuVar4 = *(undefined ***)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_qLD(ppuVar4,3,in_R8,0x22,in_stack_ffffffffffffffb8,
                            (char)this->m_Ppm->_padding_,
                            (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.
                                  Control.AsUInt64,(char)this->m_OpmCmdSeqNum);
      }
      uVar5 = (uint)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64 &
              0xff;
      in_R8 = (ulonglong)uVar5;
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (ppuVar4,(param_1->field0_0x0).m_DataBlock.CCI.AsUInt32,uVar5,
                 "[Command Handler] Both CommandCompleted and AckCompleted are indicated.");
    }
    if ((int)(param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 < 0) {
      (**(code **)(WdfFunctions_01023 + 0x9e0))(WdfDriverGlobals,this->m_CachedCommandDataLock);
      bVar6 = (this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue;
      (this->m_CachedCommandCompletionData).m_UcsiDataBlockExEnabled = bVar6;
      if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
         (bVar6 != param_1->m_UcsiDataBlockExEnabled)) {
        in_R8 = 0x78;
        RtlAssert("m_UcsiDataBlockExEnabled == Other.m_UcsiDataBlockExEnabled");
      }
      _Dst = (this->m_CachedCommandCompletionData).field0_0x0.m_DataBlockEx.MessageIn;
      (this->m_CachedCommandCompletionData).field0_0x0.m_DataBlock.UcsiVersion.AsUInt16 =
           (param_1->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16;
      (this->m_CachedCommandCompletionData).field0_0x0.m_DataBlock.CCI.AsUInt32 =
           (param_1->field0_0x0).m_DataBlock.CCI.AsUInt32;
      if (param_1->m_UcsiDataBlockExEnabled == false) {
        uVar3 = *(undefined8 *)((param_1->field0_0x0).m_DataBlockEx.MessageIn + 8);
        *(undefined8 *)_Dst = *(undefined8 *)(param_1->field0_0x0).m_DataBlockEx.MessageIn;
        *(undefined8 *)
         ((this->m_CachedCommandCompletionData).field0_0x0.m_DataBlockEx.MessageIn + 8) = uVar3;
      }
      else {
        in_R8 = 0xff;
        memset(_Dst,0,0xff);
        bVar2 = (this->m_CachedCommandCompletionData).field0_0x0.m_DataBlock.CCI._s_1.DataLength;
        if (bVar2 != 0) {
          in_R8 = (ulonglong)bVar2;
          memmove(_Dst,&(param_1->field0_0x0).m_DataBlock.MessageIn,in_R8);
        }
      }
      UcsiDataBlock::CopyUcsiControlAndMessageOutFrom
                (&this->m_CachedCommandCompletionData,&(this->m_CurrentOpmCommand).DataBlock);
      (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,this->m_CachedCommandDataLock);
      uVar5 = (param_1->field0_0x0).m_DataBlock.CCI.AsUInt32;
      if ((uVar5 >> 0x1e & 1) == 0) {
        if ((uVar5 >> 0x19 & 1) == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x25,
                                in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,
                                (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.
                                      Control.AsUInt64,(char)this->m_OpmCmdSeqNum);
          }
          this->m_CommandStatus = 0;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_R8,0x24,
                                in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,
                                (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.
                                      Control.AsUInt64,(char)this->m_OpmCmdSeqNum);
          }
          this->m_CommandStatus = -0x3fffff45;
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,this->m_Ppm,0x23,
                              in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,
                              (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.
                                    Control.AsUInt64,(char)this->m_OpmCmdSeqNum);
        }
        this->m_CommandStatus = -0x3fffffff;
      }
      SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,6);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x1f,
                          in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,
                          (char)(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control
                                .AsUInt64,(char)this->m_OpmCmdSeqNum);
    }
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,0xc);
  }
LAB_140002f06:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x26,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== PurgeUnservicedCommandsDueToStopEntry @ 1400032b0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::PurgeUnservicedCommandsDueToStopEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
PurgeUnservicedCommandsDueToStopEntry(void *param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x39,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  CommandList::ClearList((CommandList *)((longlong)param_1 + 0x40));
  lVar1 = *(longlong *)((longlong)param_1 + 0x10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x44,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)(lVar1 + 8),3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x45,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  *(undefined1 *)((longlong)param_1 + 8) = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3a,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return 9;
}



===== RetreiveCommandTypeEntry @ 1400033f0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::RetreiveCommandTypeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
RetreiveCommandTypeEntry(void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x31,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (*(int *)((longlong)param_1 + 0x2c4) == 0) {
    uVar1 = 4;
  }
  else if (*(int *)((longlong)param_1 + 0x2c4) == 1) {
    uVar1 = 0x12;
  }
  else {
    uVar1 = 0;
    if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
      RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp",0x20d,0);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x32,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return uVar1;
}



===== SendAckToPPMEntry @ 1400034f0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::SendAckToPPMEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::SendAckToPPMEntry
          (void *param_1)

{
  CommandHandler *this;
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3f,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  uVar1 = 0x20004;
  if (*(char *)((longlong)param_1 + 0x4e8) != '\0') {
    uVar1 = 0x30004;
    *(undefined1 *)((longlong)param_1 + 0x4e8) = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  this = (CommandHandler *)((longlong)param_1 + 0x18);
  LOCK();
  *(undefined4 *)((longlong)param_1 + 0x4e4) = 1;
  UNLOCK();
  if (*(int *)(*(longlong *)((longlong)param_1 + 0x10) + 0xd24) == 1) {
    *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x580) + 0x10) = uVar1;
    PpmInterface::SendUcsiDataEx
              ((PpmInterface *)this,
               *(_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_EX_IN_PARAMS **)((longlong)param_1 + 0x580));
  }
  else {
    *(undefined8 *)((longlong)param_1 + 0x528) = uVar1;
    PpmInterface::SendUcsiData
              ((PpmInterface *)this,
               (_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS *)((longlong)param_1 + 0x518));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (this = (CommandHandler *)WPP_GLOBAL_Control, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    this = *(CommandHandler **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_(this,5,3,0x41,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  CommandHandler::UpdateCurrentCommandStatus(this);
  return 0;
}



===== SendCommandCompleteToOpm @ 140003658 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::SendCommandCompleteToOpm(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::SendCommandCompleteToOpm(CommandHandler *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x42,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  Opm::EvtCommandCompletionReceived
            (&this->m_Ppm->m_Opm,&this->m_CachedCommandCompletionData,this->m_CommandStatus,
             this->m_OpmCmdSeqNum);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x43,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== SendCommandCompletedToOpmStateMachineEntry @ 140003710 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::SendCommandCompletedToOpmStateMachineEntry(void *
   __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
SendCommandCompletedToOpmStateMachineEntry(void *param_1)

{
  CommandHandler::SendCommandCompleteToOpm(param_1);
  return 9;
}



===== SendGETCommandToPPMEntry @ 140003730 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::SendGETCommandToPPMEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
SendGETCommandToPPMEntry(void *param_1)

{
  CommandHandler::RequestUCSIDataFromPpm(param_1);
  return 0;
}



===== SendNewCommandToPPMEntry @ 140003750 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::SendNewCommandToPPMEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
SendNewCommandToPPMEntry(void *param_1)

{
  CommandHandler::SendUCSICommandToPpm(param_1);
  CommandHandler::UpdateCurrentCommandStatus(param_1);
  return 0;
}



===== SendSENDCommandToPPMEntry @ 140003770 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::SendSENDCommandToPPMEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
SendSENDCommandToPPMEntry(void *param_1)

{
  CommandHandler::SendUCSICommandToPpm(param_1);
  return 0;
}



===== SendUCSICommandToPpm @ 140003788 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::SendUCSICommandToPpm(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::SendUCSICommandToPpm(CommandHandler *this)

{
  uchar *_Dst;
  undefined8 *_Dst_00;
  byte bVar1;
  uint uVar2;
  UCMUCSIPPM__ *pUVar3;
  uint uVar4;
  <unnamed_type_m_InBuffer> *p<Var5;
  char *in_R8;
  size_t _Size;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = (char *)0x3;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x44,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  UcsiDataBlock::PrettyPrintCommand
            (&(this->m_CurrentOpmCommand).DataBlock,(void *)this->m_Ppm->_padding_,in_R8,
             (this->m_CurrentOpmCommand).FromTestInterface,(this->m_CurrentOpmCommand).OpmCmdSeqNum)
  ;
  this->m_OpmCmdSeqNum = (this->m_CurrentOpmCommand).OpmCmdSeqNum;
  pUVar3 = (UCMUCSIPPM__ *)this->m_Ppm->_padding_;
  if ((this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
    this->m_InSendExParam->PpmObject = pUVar3;
    uVar2 = (this->m_Ppm->m_PpmConfig).UcsiMaxDataLength;
    _Dst = this->m_InSendExParam->MessageOutStart;
    (this->m_InSendExParam->DataBlockHeader).Control.AsUInt64 =
         (this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
    memset(_Dst,0,(ulonglong)uVar2);
    bVar1 = (this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control._s_1.DataLength;
    if (bVar1 != 0) {
      uVar4 = (uint)bVar1;
      if (uVar2 <= bVar1) {
        uVar4 = uVar2;
      }
      memmove(_Dst,(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlockEx.MessageOut,
              (ulonglong)uVar4);
    }
    PpmInterface::SendUcsiDataEx(&this->m_PpmInterface,this->m_InSendExParam);
  }
  else {
    (this->m_InBuffer).m_InSendParam.PpmObject = pUVar3;
    _Dst_00 = (undefined8 *)((longlong)&this->m_InBuffer + 0x28);
    (this->m_InBuffer).m_InSendParam.UcmUcsiDataBlock.Control.AsUInt64 =
         (this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
    *_Dst_00 = 0;
    p<Var5 = &this->m_InBuffer;
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[8] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[9] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[10] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[0xb] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[0xc] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[0xd] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[0xe] = '\0';
    (p<Var5->m_InSendParam).UcmUcsiDataBlock.MessageOut.AsBuffer[0xf] = '\0';
    bVar1 = (this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control._s_1.DataLength;
    if (bVar1 != 0) {
      _Size = 0x10;
      if (bVar1 < 0x10) {
        _Size = (size_t)bVar1;
      }
      memmove(_Dst_00,&(this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.MessageOut,_Size
             );
    }
    PpmInterface::SendUcsiData(&this->m_PpmInterface,&(this->m_InBuffer).m_InSendParam);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x45,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== SendUcsiCommand @ 140003934 =====

/* public: bool __cdecl UcmUcsiCx::CommandHandler::SendUcsiCommand(struct
   UcmUcsiCx::UCMUCSI_OPM_COMMAND * __ptr64) __ptr64 */

bool __thiscall
UcmUcsiCx::CommandHandler::SendUcsiCommand(CommandHandler *this,UCMUCSI_OPM_COMMAND *param_1)

{
  bool bVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x29,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  bVar1 = CommandList::AddCommand(&this->m_CommandList,param_1);
  if (bVar1) {
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,5);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2a,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return bVar1;
}



===== SetUnrecoverableFailureContext @ 1400039fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::CommandHandler::SetUnrecoverableFailureContext(enum
   UcmUcsiCx::LkdFailureType,long) __ptr64 */

void __thiscall
UcmUcsiCx::CommandHandler::SetUnrecoverableFailureContext
          (CommandHandler *this,LkdFailureType param_1,long param_2)

{
  Ppm *pPVar1;
  WDFSPINLOCK__ *pWVar2;
  ulong64 uVar3;
  _UCSI_COMMAND _Var4;
  
  (**(code **)(WdfFunctions_01023 + 0x9e0))
            (WdfDriverGlobals,this->m_UnrecoverableFailureContextLock);
  uVar3 = (this->m_CurrentOpmCommand).DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
  pPVar1 = this->m_Ppm;
  (this->m_UnrecoverableFailureContext).Type = param_1;
  (this->m_UnrecoverableFailureContext).Status = param_2;
  (this->m_UnrecoverableFailureContext).UcsiCommandInOpm = (_UCSI_COMMAND)uVar3 & 0xff;
  if ((pPVar1->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
    _Var4 = (_UCSI_COMMAND)(this->m_InSendExParam->DataBlockHeader).Control.AsUInt64;
  }
  else {
    _Var4 = (_UCSI_COMMAND)(this->m_InBuffer).m_InSendParam.UcmUcsiDataBlock.Control.AsUInt64;
  }
  (this->m_UnrecoverableFailureContext).SubType = Undefined;
  pWVar2 = this->m_UnrecoverableFailureContextLock;
  (this->m_UnrecoverableFailureContext).UcsiCommandForPpm = _Var4 & 0xff;
  (this->m_UnrecoverableFailureContext).ConnectorNumber = '\0';
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,pWVar2);
  return;
}



===== StartCommandTimer @ 140003ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::CommandHandler::StartCommandTimer(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::StartCommandTimer(CommandHandler *this)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x46,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  cVar1 = (**(code **)(WdfFunctions_01023 + 0x9f8))
                    (WdfDriverGlobals,this->m_CommandTimer,0xfffffffffa0a1f00);
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (cVar1 != '\0')) {
    RtlAssert("timerWasInQueue == 0",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp",0x317,0);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x47,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== StartedEntry @ 140003bc0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::StartedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::StartedEntry
          (void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x37,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  *(undefined1 *)((longlong)param_1 + 8) = 1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x38,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return 0;
}



===== StartingAckCompleteTimerEntry @ 140003c70 =====

/* public: static unsigned short __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::EntryFuncs::StartingAckCompleteTimerEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::EntryFuncs::
StartingAckCompleteTimerEntry(void *param_1)

{
  CommandHandler::StartCommandTimer(param_1);
  return 9;
}



===== Stop @ 140003c8c =====

/* public: void __cdecl UcmUcsiCx::CommandHandler::Stop(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::Stop(CommandHandler *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1b,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (this->m_IsStarted == false) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x1c,
                        &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                        (char)this->m_Ppm->_padding_);
    }
    Verify::Break();
  }
  else {
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,0x10);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1d,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== StopCommandTimer @ 140003d78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum SmFx::StopTimerResult __cdecl UcmUcsiCx::CommandHandler::StopCommandTimer(void)
   __ptr64 */

StopTimerResult __thiscall UcmUcsiCx::CommandHandler::StopCommandTimer(CommandHandler *this)

{
  char cVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x48,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  cVar1 = (**(code **)(WdfFunctions_01023 + 0xa00))(WdfDriverGlobals,this->m_CommandTimer,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x49,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return WaitForTimerFiredEventAndIgnoreIt - (cVar1 != '\0');
}



===== UpdateCurrentCommandStatus @ 140003e3c =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::UpdateCurrentCommandStatus(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::UpdateCurrentCommandStatus(CommandHandler *this)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x4c,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x4d,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
  }
  return;
}



===== WaitingForAckCompleteStopTimer @ 140003ed0 =====

/* public: static enum SmFx::StopTimerResult __cdecl UcmUcsiCx::CommandHandlerStateMachine<class
   UcmUcsiCx::CommandHandler>::StopTimerOnExitDetails::WaitingForAckCompleteStopTimer(void *
   __ptr64) */

StopTimerResult __cdecl
UcmUcsiCx::CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::StopTimerOnExitDetails::
WaitingForAckCompleteStopTimer(void *param_1)

{
  StopTimerResult SVar1;
  
  SVar1 = CommandHandler::StopCommandTimer(param_1);
  return SVar1;
}



===== WPP_RECORDER_SF_L @ 140003ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_LLL @ 140003fd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,3,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_LLLL @ 1400040c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_LLLL
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
               &param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qDd @ 140004224 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qLD @ 14000437c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,3,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140004480 =====

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



===== WPP_RECORDER_SF_qLddD @ 1400045d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,0x40,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_be66407a1aed381749fba11a60c926d7_Traceguids,0x40,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== CxDevice @ 140004708 =====

/* private: __cdecl UcmUcsiCx::CxDevice::CxDevice(struct WDFDEVICE__ * __ptr64) __ptr64 */

CxDevice * __thiscall UcmUcsiCx::CxDevice::CxDevice(CxDevice *this,WDFDEVICE__ *param_1)

{
  this->_padding_ = (longlong)param_1;
  this->m_PrivateGlobals = (_UCMUCSI_PRIVATE_DRIVER_GLOBALS *)0x0;
  this->m_SelfIoTargetQueue = (WDFQUEUE__ *)0x0;
  this->m_Ppm = (Ppm *)0x0;
  this->m_deviceInstanceId = (wchar_t *)0x0;
  this->m_deviceServiceName = (wchar_t *)0x0;
  (this->m_TestInterface).m_CxDevice = (CxDevice *)0x0;
  (this->m_TestInterface).m_Queue = (WDFQUEUE__ *)0x0;
  (this->m_TestInterface).m_ActiveRequest = (WDFREQUEST__ *)0x0;
  (this->m_TestInterface).m_ActiveRequestIoctl = 0;
  (this->m_TestInterface).m_OutputBufferLength = 0;
  (this->m_TestInterface).m_InputBufferLength = 0;
  this->m_SystemPowerOperation = (atomic<UcmUcsiCx::UcsiPowerOperation>)0x0;
  this->m_IsBugcheckOnCommandFailureEnabled = false;
  return this;
}



===== EvtCxDevicePostSelfManagedIoInit @ 140004750 =====

/* public: static long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePostSelfManagedIoInit(struct
   WDFDEVICE__ * __ptr64) */

long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePostSelfManagedIoInit(WDFDEVICE__ *param_1)

{
  CxDevice *this;
  UcsiPowerOperation UVar1;
  
  this = GetContextFromObject(param_1);
  UVar1 = *(UcsiPowerOperation *)(WdfDriverGlobals + 8);
  if (((UVar1 & 4) != PowerOperationNone) && (this == (CxDevice *)0x0)) {
    UVar1 = 0x40018d10;
    RtlAssert("cxDeviceObject","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x170,0)
    ;
  }
  UpdatePowerOperationUnconditionally(this,UVar1,PowerOperationNone);
  return 0;
}



===== EvtCxDevicePreSelfManagedIoRestart @ 1400047b0 =====

/* public: static long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePreSelfManagedIoRestart(struct
   WDFDEVICE__ * __ptr64) */

long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePreSelfManagedIoRestart(WDFDEVICE__ *param_1)

{
  bool bVar1;
  CxDevice *this;
  UcsiPowerOperation UVar2;
  
  this = GetContextFromObject(param_1);
  UVar2 = *(UcsiPowerOperation *)(WdfDriverGlobals + 8);
  if (((UVar2 & 4) != PowerOperationNone) && (this == (CxDevice *)0x0)) {
    UVar2 = 0x1a5;
    RtlAssert("cxDeviceObject","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x1a5,0)
    ;
  }
  bVar1 = UpdatePowerOperationConditionally(this,PowerOperationPowerUp,UVar2);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)param_1);
    }
    if (this->m_Ppm != (Ppm *)0x0) {
      Ppm::PowerOn(this->m_Ppm);
    }
  }
  return 0;
}



===== EvtCxDevicePreSelfManagedIoSuspend @ 140004870 =====

/* public: static long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePreSelfManagedIoSuspend(struct
   WDFDEVICE__ * __ptr64) */

long __cdecl UcmUcsiCx::CxDevice::EvtCxDevicePreSelfManagedIoSuspend(WDFDEVICE__ *param_1)

{
  bool bVar1;
  CxDevice *this;
  UcsiPowerOperation UVar2;
  
  this = GetContextFromObject(param_1);
  UVar2 = *(UcsiPowerOperation *)(WdfDriverGlobals + 8);
  if (((UVar2 & 4) != PowerOperationNone) && (this == (CxDevice *)0x0)) {
    UVar2 = 0x182;
    RtlAssert("cxDeviceObject","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x182,0)
    ;
  }
  bVar1 = UpdatePowerOperationConditionally(this,PowerOperationPowerDown,UVar2);
  if (bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1e,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)param_1);
    }
    if (this->m_Ppm != (Ppm *)0x0) {
      Ppm::PowerOff(this->m_Ppm);
    }
  }
  return 0;
}



===== EvtDeviceWdmPreprocessSetPowerIrp @ 140004930 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::CxDevice::EvtDeviceWdmPreprocessSetPowerIrp(struct
   WDFDEVICE__ * __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
UcmUcsiCx::CxDevice::EvtDeviceWdmPreprocessSetPowerIrp
          (WDFDEVICE__ *param_1,_IRP *param_2,void *param_3)

{
  void **ppvVar1;
  uint uVar2;
  void *pvVar3;
  long lVar4;
  CxDevice *this;
  UcsiPowerOperation UVar5;
  UcsiPowerOperation UVar6;
  undefined1 uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x23,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  this = GetContextFromObject(param_1);
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (this == (CxDevice *)0x0)) {
    RtlAssert("cxDeviceObject","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x1f9,0)
    ;
  }
  pvVar3 = (param_2->Tail).Apc.SystemArgument1;
  if (*(int *)((longlong)pvVar3 + 0x10) == 0) {
    uVar2 = *(uint *)((longlong)pvVar3 + 8);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    UVar5 = 0x4001d148;
    uVar7 = SUB81(param_1,0);
    if ((*(int *)((longlong)pvVar3 + 0x18) == 1) && ((uVar2 >> 0x10 & 0xf) == 1)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x25,
                          &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar7);
      }
    }
    else {
      if ((uVar2 >> 8 & 0xf) == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          UVar5 = 0x4001d104;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x27,
                            &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar7);
        }
        UVar6 = PowerOperationPowerUp;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          UVar5 = 0x4001d104;
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x26,
                            &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar7);
        }
        UVar6 = PowerOperationPowerDown;
      }
      UpdatePowerOperationUnconditionally(this,UVar5,UVar6);
    }
  }
  param_2->CurrentLocation = param_2->CurrentLocation + '\x01';
  ppvVar1 = &(param_2->Tail).Apc.SystemArgument1;
  *ppvVar1 = (void *)((longlong)*ppvVar1 + 0x48);
  lVar4 = (**(code **)(WdfFunctions_01023 + 0xc88))(WdfDriverGlobals,param_1,param_2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x28,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return lVar4;
}



===== EvtIoDefaultThunk @ 140004bc0 =====

/* private: static void __cdecl UcmUcsiCx::CxDevice::EvtIoDefaultThunk(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl UcmUcsiCx::CxDevice::EvtIoDefaultThunk(WDFQUEUE__ *param_1,WDFREQUEST__ *param_2)

{
  PpmInterface::DispatchHardwareRequest(param_2);
  return;
}



===== EvtObjectContextCleanupThunk @ 140004be0 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   UcmUcsiCx::CxDevice>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiCx::CxDevice>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  CxDevice *this;
  
  this = UcmUcsiCx::CxDevice::GetContextFromObject(param_1);
  UcmUcsiCx::CxDevice::EvtObjectContextCleanup(this);
  return;
}



===== EvtObjectContextDestroyThunk @ 140004c00 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct WDFDEVICE__ * __ptr64,class
   UcmUcsiCx::CxDevice>::EvtObjectContextDestroyThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiCx::CxDevice>::EvtObjectContextDestroyThunk
          (void *param_1)

{
  UcmUcsiCx::CxDevice::GetContextFromObject(param_1);
  return;
}



===== GetContextFromObject @ 140004c18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class UcmUcsiCx::CxDevice * __ptr64 __cdecl
   UcmUcsiCx::CxDevice::GetContextFromObject(struct WDFDEVICE__ * __ptr64) */

CxDevice * __cdecl UcmUcsiCx::CxDevice::GetContextFromObject(WDFDEVICE__ *param_1)

{
  CxDevice *pCVar1;
  
  pCVar1 = (CxDevice *)
           (**(code **)(WdfFunctions_01023 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CxDevice_TYPE_INFO_14001d0a0);
  return pCVar1;
}



===== RtlStringCbPrintfW @ 140004c4c =====

/* long __cdecl RtlStringCbPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCbPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  int iVar1;
  ulonglong uVar2;
  long lVar3;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    lVar3 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,uVar2,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      lVar3 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = 0;
  }
  else {
    lVar3 = -0x3ffffff3;
    if (uVar2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar3;
}



===== UpdatePowerOperationConditionally @ 140004cc8 =====

/* public: bool __cdecl UcmUcsiCx::CxDevice::UpdatePowerOperationConditionally(enum
   UcmUcsiCx::UcsiPowerOperation,enum UcmUcsiCx::UcsiPowerOperation) __ptr64 */

bool __thiscall
UcmUcsiCx::CxDevice::UpdatePowerOperationConditionally
          (CxDevice *this,UcsiPowerOperation param_1,UcsiPowerOperation param_2)

{
  atomic<UcmUcsiCx::UcsiPowerOperation> aVar1;
  bool bVar2;
  
  LOCK();
  aVar1 = this->m_SystemPowerOperation;
  bVar2 = (atomic<UcmUcsiCx::UcsiPowerOperation>)param_1 == aVar1;
  if (bVar2) {
    this->m_SystemPowerOperation = (atomic<UcmUcsiCx::UcsiPowerOperation>)0x0;
  }
  else {
    param_1 = (UcsiPowerOperation)aVar1;
  }
  UNLOCK();
  if (bVar2) {
    bVar2 = true;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1b,
                          &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_,
                          (char)param_1,0);
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



===== UpdatePowerOperationUnconditionally @ 140004d3c =====

/* public: void __cdecl UcmUcsiCx::CxDevice::UpdatePowerOperationUnconditionally(enum
   UcmUcsiCx::UcsiPowerOperation,enum UcmUcsiCx::UcsiPowerOperation) __ptr64 */

void __thiscall
UcmUcsiCx::CxDevice::UpdatePowerOperationUnconditionally
          (CxDevice *this,UcsiPowerOperation param_1,UcsiPowerOperation param_2)

{
  atomic<UcmUcsiCx::UcsiPowerOperation> aVar1;
  
  LOCK();
  aVar1 = this->m_SystemPowerOperation;
  this->m_SystemPowerOperation = (atomic<UcmUcsiCx::UcsiPowerOperation>)param_2;
  UNLOCK();
  if (aVar1 == (atomic<UcmUcsiCx::UcsiPowerOperation>)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
                          &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_,0,
                          (char)param_2);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this = *(CxDevice **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_qLLL(this);
    }
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (this,(int)aVar1 << 0x10,param_2,"Unexpected power operation update");
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004df8 =====

void McGenEventWrite_EtwWriteTransfer(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 *in_stack_00000028;
  
  puVar1 = DAT_14001d108;
  uVar2 = 0;
  if (DAT_14001d108 == (ushort *)0x0) {
    *in_stack_00000028 = 0;
    uVar3 = 0;
  }
  else {
    *in_stack_00000028 = DAT_14001d108;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(in_stack_00000028 + 1) = uVar3;
  *(undefined4 *)((longlong)in_stack_00000028 + 0xc) = uVar2;
  EtwWriteTransfer(MS_UCMUCSICX_ETW_PROVIDER_Context,&UCMUCSICX_FAILURE,0,0,8);
  return;
}



===== McTemplateK0zzqqqqq_EtwWriteTransfer @ 140004e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zzqqqqq_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *in_R9;
  wchar_t *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 auStack_c8 [32];
  undefined1 *local_a8;
  undefined1 local_98 [16];
  wchar_t *local_88;
  int local_80;
  undefined4 local_7c;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
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
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = -1;
  local_70 = 10;
  if (in_R9 == (wchar_t *)0x0) {
    local_80 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != L'\0');
    local_80 = (int)lVar2 * 2 + 2;
  }
  local_7c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  if (in_stack_00000028 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_70 = (int)lVar1 * 2 + 2;
  }
  local_68 = &uStack0000000000000030;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_58 = &uStack0000000000000038;
  local_48 = &uStack0000000000000040;
  local_38 = &uStack0000000000000048;
  local_28 = &uStack0000000000000050;
  local_a8 = local_98;
  local_6c = 0;
  local_60 = 4;
  local_50 = 4;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_88 = in_R9;
  local_78 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer();
  return;
}



===== WPP_RECORDER_SF_d @ 140004f68 =====

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



===== WPP_RECORDER_SF_qLLL @ 140005064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,0x1c,&uStack0000000000000030,8,
               &uStack0000000000000038,4,local_18,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,0x1c,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,local_18,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qLLLLL @ 140005184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLLLLL(undefined8 param_1)

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
               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,0x24,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,0x24,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== imp_UcmUcsiDeviceInitInitialize @ 1400052e0 =====

long imp_UcmUcsiDeviceInitInitialize(_UCMUCSI_DRIVER_GLOBALS *param_1,WDFDEVICE_INIT *param_2)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                     &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (-1 < lVar1) {
    lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"DeviceInit");
    if (-1 < lVar1) {
      lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0');
      if (-1 < lVar1) {
        lVar1 = UcmUcsiCx::CxDevice::DeviceInitInitialize(param_2);
        if (-1 < lVar1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xb,
                              &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids,(char)param_2);
          }
          lVar1 = 0;
        }
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xc,
                     &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids);
  }
  return lVar1;
}



===== imp_UcmUcsiDeviceInitialize @ 140005400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long imp_UcmUcsiDeviceInitialize
               (_UCMUCSI_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,
               _UCMUCSI_DEVICE_CONFIG *param_3)

{
  long lVar1;
  uint uVar2;
  _UCMUCSI_DEVICE_CONFIG *p_Var3;
  undefined1 uVar4;
  
  p_Var3 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    p_Var3 = (_UCMUCSI_DEVICE_CONFIG *)&DAT_00000002;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xd,
                     &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (-1 < lVar1) {
    lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0');
    if (-1 < lVar1) {
      lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"WdfDevice");
      if (-1 < lVar1) {
        lVar1 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"Config");
        if (-1 < lVar1) {
          uVar4 = SUB81(param_2,0);
          if (param_3->Size == 4) {
            uVar2 = (**(code **)(WdfFunctions_01023 + 0x158))(WdfDriverGlobals,param_2);
            if ((uVar2 & 0xffff7fff) == 0x105) {
              lVar1 = UcmUcsiCx::CxDevice::CreateAndInitialize(param_1,param_2,p_Var3);
              if (-1 < lVar1) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x10,
                                    &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids,uVar4);
                }
                lVar1 = 0;
              }
              goto LAB_1400055ad;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xf,
                                &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids,uVar4);
            }
            lVar1 = -0x3ffffe7c;
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xe,
                                  &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids,uVar4,4,
                                  (char)param_3->Size);
            }
            lVar1 = -0x3ffffffc;
          }
          UcmUcsiCx::Verify::Break();
        }
      }
    }
  }
LAB_1400055ad:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x11,
                     &WPP_6fb6d6128d86335652c2bdcf5800bf0e_Traceguids);
  }
  return lVar1;
}



===== GetPrivateGlobals @ 140005604 =====

/* public: static struct UcmUcsiCx::_UCMUCSI_PRIVATE_DRIVER_GLOBALS * __ptr64 __cdecl
   UcmUcsiCx::Driver::GetPrivateGlobals(struct _UCMUCSI_DRIVER_GLOBALS * __ptr64) */

_UCMUCSI_PRIVATE_DRIVER_GLOBALS * __cdecl
UcmUcsiCx::Driver::GetPrivateGlobals(_UCMUCSI_DRIVER_GLOBALS *param_1)

{
  return (_UCMUCSI_PRIVATE_DRIVER_GLOBALS *)(param_1 + -1);
}



===== RtlUnicodeStringPrintf @ 140005610 =====

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
  
  uVar1 = param_1->Length;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1->MaximumLength, (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((lVar5 = 0, param_1->Buffer != (wchar_t *)0x0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1->MaximumLength >> 1);
    local_res18 = in_R8;
    local_res20 = in_R9;
    iVar3 = _vsnwprintf(param_1->Buffer,_Count,(wchar_t *)param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      lVar5 = -0x7ffffffb;
      uVar4 = _Count;
    }
    param_1->Length = (short)uVar4 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== McGenControlCallbackV2 @ 1400056b0 =====

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



===== McGenEventRegister_EtwRegister @ 1400057c0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (MS_UCMUCSICX_ETW_PROVIDER_Context == 0) {
    EtwRegister(&MS_UCMUCSICX_ETW_PROVIDER,McGenControlCallbackV2,&MS_UCMUCSICX_ETW_PROVIDER_Context
                ,&MS_UCMUCSICX_ETW_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140005800 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (MS_UCMUCSICX_ETW_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    MS_UCMUCSICX_ETW_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== WPP_RECORDER_SF_qDDDD @ 140005834 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDD
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
               &param_6,8,&param_7,4,&param_8,4,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,&param_9,
                  4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_qSd @ 1400059dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qSd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x32,&uStack0000000000000030,8,
               L"AllowBinding1_1FromAnyClients",0x3c,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,3,5,&WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x32,
                  &uStack0000000000000030,8,L"AllowBinding1_1FromAnyClients",0x3c,
                  &uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qZ @ 140005ae0 =====

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
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
  goto LAB_140005ba8;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_140005b51:
    pwVar4 = L"NULL";
  }
  else {
    wVar1 = *in_stack_00000038;
    if (*in_stack_00000038 == L'\0') goto LAB_140005b51;
    pwVar4 = *(wchar_t **)(in_stack_00000038 + 4);
  }
  pwVar2 = in_stack_00000038;
  if (in_stack_00000038 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x25,&uStack0000000000000030,8,pwVar2,
             2,pwVar4,wVar1,0);
LAB_140005ba8:
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
  WppAutoLogTrace(param_1,4,5,&WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x25,
                  &uStack0000000000000030,8,in_stack_00000038,2,pwVar3,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_ql @ 140005c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0xc,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0xc,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qs @ 140005d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x1b,&uStack0000000000000030,8,
               pcVar3,lVar2,0);
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
  WppAutoLogTrace(param_1,4,1,&WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0x1b,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,0);
  return;
}



===== WppClassicProviderCallback @ 140005e60 =====

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



===== wil_details_RecordCachedUsage @ 140005ebc =====

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



===== wil_details_RecordFeatureUsageReporting @ 140006010 =====

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



===== Ppm @ 140006094 =====

/* private: __cdecl UcmUcsiCx::Ppm::Ppm(struct UCMUCSIPPM__ * __ptr64) __ptr64 */

Ppm * __thiscall UcmUcsiCx::Ppm::Ppm(Ppm *this,UCMUCSIPPM__ *param_1)

{
  Opm *pOVar1;
  CommandHandler *pCVar2;
  
  this->_padding_ = (longlong)param_1;
  *(undefined8 *)&(this->m_Opm).m_CommandHandler.m_CommandList.m_OpmCommandList = 0xffffffffffffffff
  ;
  *(undefined8 *)&(this->m_Opm).m_CommandHandler.m_CommandList.field_0x18 = 0xffffffffffffffff;
  *(undefined8 *)&(this->m_Opm).m_CommandHandler.m_CommandList.field_0x20 = 0xffffffffffffffff;
  *(undefined8 *)&this->m_Opm = 0;
  (this->m_Opm).m_CommandHandler._padding_ = 0;
  (this->m_Opm).m_CommandHandler.m_PpmInterface.m_HardwareRequest = (WDFREQUEST__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_PpmInterface.m_InputMemory = (WDFMEMORY__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_PpmInterface.m_OutputMemory = (WDFMEMORY__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_PpmInterface.m_HardwareRequestCompletionCallback =
       (_func___cdecl_void_Ppm_ptr_long *)0x0;
  (this->m_Opm).m_CommandHandler.m_PpmInterface.m_Ppm = (Ppm *)0x0;
  (this->m_Opm).m_CommandHandler.m_CommandList.m_Ppm = (Ppm *)0x0;
  (this->m_Opm).m_CommandHandler.m_CommandList.m_OpmCommandListLock = (WDFSPINLOCK__ *)0x0;
  (this->m_Opm).m_Ppm = (Ppm *)0x0;
  (this->m_Opm).m_CommandHandler.m_IsStarted = false;
  (this->m_Opm).m_CommandHandler.m_Ppm = (Ppm *)0x0;
  (this->m_Opm).m_CommandHandler.m_OpmCmdSeqNum = 0;
  (this->m_Opm).m_CommandHandler.m_CommandTimer = (WDFTIMER__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_CachedCommandDataLock = (WDFSPINLOCK__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_CachedCommandData.UcsiVersion.AsUInt16 = 0;
  *(undefined2 *)&(this->m_Opm).m_CommandHandler.m_CachedCommandData.field_0x2 = 0;
  (this->m_Opm).m_CommandHandler.m_CachedCommandData.CCI.AsUInt32 = 0;
  (this->m_Opm).m_CommandHandler.m_CachedCommandData.Control.AsUInt64 = 0;
  pOVar1 = &this->m_Opm;
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[0] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[1] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[2] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[3] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[4] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[5] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[6] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageIn.AsBuffer[7] = '\0';
  pCVar2 = &(this->m_Opm).m_CommandHandler;
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[8] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[9] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[10] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[0xb] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[0xc] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[0xd] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[0xe] = '\0';
  (pCVar2->m_CachedCommandData).MessageIn.AsBuffer[0xf] = '\0';
  pOVar1 = &this->m_Opm;
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[0] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[1] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[2] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[3] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[4] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[5] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[6] = '\0';
  (pOVar1->m_CommandHandler).m_CachedCommandData.MessageOut.AsBuffer[7] = '\0';
  pCVar2 = &(this->m_Opm).m_CommandHandler;
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[8] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[9] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[10] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[0xb] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[0xc] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[0xd] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[0xe] = '\0';
  (pCVar2->m_CachedCommandData).MessageOut.AsBuffer[0xf] = '\0';
  (this->m_Opm).m_CommandHandler.m_CachedCommandCompletionData.m_UcsiDataBlockExEnabled = false;
  (this->m_Opm).m_CommandHandler.m_CurrentOpmCommand.DataBlock.m_UcsiDataBlockExEnabled = false;
  (this->m_Opm).m_CommandHandler.m_ShouldAckConnectChange = false;
  (this->m_Opm).m_CommandHandler.m_UnrecoverableFailureContextLock = (WDFSPINLOCK__ *)0x0;
  (this->m_Opm).m_CommandHandler.m_UnrecoverableFailureContext.Type = Undefined;
  (this->m_Opm).m_CommandHandler.m_UnrecoverableFailureContext.SubType = Undefined;
  (this->m_Opm).m_CommandHandler.m_SynchCommandRetrialCount = 0;
  (this->m_Opm).m_CommandHandler.m_InSendExParam =
       (_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_EX_IN_PARAMS *)0x0;
  (this->m_Opm).m_CommandHandler.m_OutExParam =
       (_UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_EX_OUT_PARAMS *)0x0;
  (this->m_Opm).m_CommandHandler.m_AutoAckEnabled = true;
  (this->m_Opm).m_CommandHandler.m_AutoAckEnableRequested = WdfUseDefault;
  (this->m_Opm).m_CommandCompleteNotificationEnabled = '\0';
  (this->m_Opm).m_IsUsbDeviceControllerEnabled = false;
  (this->m_Opm).m_Connectors = (WDFCOLLECTION__ *)0x0;
  (this->m_Opm).m_LatestOpmCmdSeqNum = 0;
  (this->m_Opm).m_ActiveCommandCtx.OpmCommand.DataBlock.m_UcsiDataBlockExEnabled = false;
  (this->m_Opm).m_ActiveCommandCtx.CompletionData.m_UcsiDataBlockExEnabled = false;
  (this->m_Opm).m_ActiveTestCommand.m_UcsiDataBlockExEnabled = false;
  (this->m_Opm).m_ActiveTestInterfaceControlCommand.AsUInt64 = 0;
  (this->m_Opm).m_CurrentConnectorNumber = 1;
  (this->m_Opm).m_NumAltModesReturned = 0;
  (this->m_Opm).m_CciDataLength = 0;
  (this->m_Opm).m_BatteryNotChargingNotificationDisableOverride = '\0';
  (this->m_Opm).m_UcsiEnableOvercurrentErrorNotification = false;
  (this->m_Opm).m_UnrecoverableFailureContextLock = (WDFSPINLOCK__ *)0x0;
  (this->m_Opm).m_UnrecoverableFailureContext.Type = Undefined;
  (this->m_Opm).m_UnrecoverableFailureContext.SubType = Undefined;
  this->m_HardwareBringUpModeEnabled = false;
  (this->m_PpmConfig).Size = 0;
  (this->m_PpmConfig).UsbDeviceControllerEnabled = '\0';
  *(undefined3 *)&(this->m_PpmConfig).field_0x5 = 0;
  (this->m_PpmConfig).ConnectorCollectionHandle = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  (this->m_PpmConfig).UcsiVersion.AsUInt16 = 0;
  *(ushort *)&(this->m_PpmConfig).field_0x12 = 0;
  *(ushort *)&(this->m_PpmConfig).UcsiDataBlockExEnabled = 0;
  *(ushort *)((longlong)&(this->m_PpmConfig).UcsiDataBlockExEnabled + 2) = 0;
  *(undefined8 *)&(this->m_PpmConfig).UcsiMaxDataLength = 0;
  (this->m_UcsiVersion).AsUInt16 = 0;
  this->m_CxDevice = (CxDevice *)0x0;
  this->m_HardwareRequestQueue = (WDFQUEUE__ *)0x0;
  this->m_IsStarted = false;
  return this;
}



===== EvtObjectContextCleanupThunk @ 1400061e0 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct UCMUCSIPPM__ * __ptr64,class
   UcmUcsiCx::Ppm>::EvtObjectContextCleanupThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiCx::Ppm>::EvtObjectContextCleanupThunk
          (void *param_1)

{
  Ppm *this;
  
  this = UcmUcsiCx::Ppm::GetContextFromObject(param_1);
  UcmUcsiCx::Ppm::EvtObjectContextCleanup(this);
  return;
}



===== EvtObjectContextDestroyThunk @ 140006200 =====

/* private: static void __cdecl WdfCpp::ObjectContext<struct UCMUCSIPPM__ * __ptr64,class
   UcmUcsiCx::Ppm>::EvtObjectContextDestroyThunk(void * __ptr64) */

void __cdecl
WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiCx::Ppm>::EvtObjectContextDestroyThunk
          (void *param_1)

{
  longlong lVar1;
  Ppm *pPVar2;
  
  pPVar2 = UcmUcsiCx::Ppm::GetContextFromObject(param_1);
  if ((pPVar2 != (Ppm *)0x0) &&
     (lVar1 = *(longlong *)&(pPVar2->m_Opm).m_CommandHandler.m_CommandList.m_OpmCommandList,
     lVar1 != -1)) {
    *(longlong *)&(pPVar2->m_Opm).m_CommandHandler.m_CommandList.field_0x18 = lVar1;
    ExFreePoolWithTag(lVar1,0x69736355);
  }
  return;
}



===== EvtPowerOffComplete @ 14000623c =====

/* public: void __cdecl UcmUcsiCx::Ppm::EvtPowerOffComplete(void) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::EvtPowerOffComplete(Ppm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x42,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  KeSetEvent(&this->m_PowerOffEvent,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x43,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== EvtPowerOnComplete @ 1400062f0 =====

/* public: void __cdecl UcmUcsiCx::Ppm::EvtPowerOnComplete(void) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::EvtPowerOnComplete(Ppm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x44,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  KeSetEvent(&this->m_PowerOnEvent,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x45,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== GetContextFromObject @ 1400063a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class UcmUcsiCx::Ppm * __ptr64 __cdecl UcmUcsiCx::Ppm::GetContextFromObject(struct
   UCMUCSIPPM__ * __ptr64) */

Ppm * __cdecl UcmUcsiCx::Ppm::GetContextFromObject(UCMUCSIPPM__ *param_1)

{
  Ppm *pPVar1;
  
  pPVar1 = (Ppm *)(**(code **)(WdfFunctions_01023 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_Ppm_TYPE_INFO_14001d0c8);
  return pPVar1;
}



===== GetCxDevice @ 1400063d8 =====

/* public: class UcmUcsiCx::CxDevice * __ptr64 __cdecl UcmUcsiCx::Ppm::GetCxDevice(void) __ptr64 */

CxDevice * __thiscall UcmUcsiCx::Ppm::GetCxDevice(Ppm *this)

{
  return this->m_CxDevice;
}



===== GetOpm @ 1400063e8 =====

/* public: class UcmUcsiCx::Opm * __ptr64 __cdecl UcmUcsiCx::Ppm::GetOpm(void) __ptr64 */

Opm * __thiscall UcmUcsiCx::Ppm::GetOpm(Ppm *this)

{
  return &this->m_Opm;
}



===== PpmNotificationReceived @ 1400063f4 =====

/* public: void __cdecl UcmUcsiCx::Ppm::PpmNotificationReceived(struct _UCSI_DATA_BLOCK * __ptr64)
   __ptr64 */

void __thiscall UcmUcsiCx::Ppm::PpmNotificationReceived(Ppm *this,_UCSI_DATA_BLOCK *param_1)

{
  longlong lVar1;
  _UCSI_VERSION *p_Var2;
  undefined2 uVar3;
  _UCSI_VERSION local_228 [264];
  undefined1 local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x46,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  if (this->m_IsStarted == false) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x47;
LAB_140006487:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar3,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_);
    }
  }
  else {
    if ((this->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue) {
      p_Var2 = local_228;
      for (lVar1 = 0x30; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(char *)&p_Var2->AsUInt16 = (char)(param_1->UcsiVersion).AsUInt16;
        param_1 = (_UCSI_DATA_BLOCK *)&(param_1->UcsiVersion)._s_1.MajorVersion;
        p_Var2 = (_UCSI_VERSION *)((longlong)&p_Var2->AsUInt16 + 1);
      }
      local_18 = 0;
      ValidateAndCacheUcsiVersion(this,local_228);
      UcsiDataBlock::PrettyPrintCci((UcsiDataBlock *)&local_228[0]._s_1,(void *)this->_padding_);
      Opm::PpmNotificationReceived(&this->m_Opm,(UcsiDataBlock *)&local_228[0]._s_1);
      CommandHandler::PpmNotificationReceived
                (&(this->m_Opm).m_CommandHandler,(UcsiDataBlock *)&local_228[0]._s_1);
      goto LAB_1400064fe;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x48;
      goto LAB_140006487;
    }
  }
  Verify::Break();
LAB_1400064fe:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x49,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== PpmNotificationReceivedEx @ 140006554 =====

/* public: void __cdecl UcmUcsiCx::Ppm::PpmNotificationReceivedEx(struct _UCSI_DATA_BLOCK_HEADER *
   __ptr64,void * __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::Ppm::PpmNotificationReceivedEx(Ppm *this,_UCSI_DATA_BLOCK_HEADER *param_1,void *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  _UCSI_VERSION *p_Var3;
  undefined8 *puVar4;
  undefined2 uVar5;
  _UCSI_VERSION local_238 [2];
  byte local_233;
  undefined8 local_228 [64];
  undefined1 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4a,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  if (this->m_IsStarted == false) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x4b;
LAB_1400065e9:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar5,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_);
    }
  }
  else {
    if ((this->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
      p_Var3 = local_238;
      for (lVar1 = 2; lVar1 != 0; lVar1 = lVar1 + -1) {
        *(undefined8 *)&p_Var3->AsUInt16 = *(undefined8 *)param_1;
        param_1 = (_UCSI_DATA_BLOCK_HEADER *)&param_1->Control;
        p_Var3 = p_Var3 + 4;
      }
      if (local_233 != 0) {
        puVar4 = local_228;
        for (uVar2 = (ulonglong)local_233 + 7 >> 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = *(undefined8 *)param_2;
          param_2 = (undefined8 *)((longlong)param_2 + 8);
          puVar4 = puVar4 + 1;
        }
      }
      local_28 = 1;
      ValidateAndCacheUcsiVersion(this,local_238);
      UcsiDataBlock::PrettyPrintCci((UcsiDataBlock *)&local_238[0]._s_1,(void *)this->_padding_);
      Opm::PpmNotificationReceived(&this->m_Opm,(UcsiDataBlock *)&local_238[0]._s_1);
      CommandHandler::PpmNotificationReceived
                (&(this->m_Opm).m_CommandHandler,(UcsiDataBlock *)&local_238[0]._s_1);
      goto LAB_14000667e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x4c;
      goto LAB_1400065e9;
    }
  }
  Verify::Break();
LAB_14000667e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x4d,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== RtlStringCchPrintfExW @ 1400066d4 =====

/* long __cdecl RtlStringCchPrintfExW(unsigned short * __ptr64,unsigned __int64,unsigned short *
   __ptr64 * __ptr64,unsigned __int64 * __ptr64,unsigned long,unsigned short const * __ptr64,...) */

long __cdecl
RtlStringCchPrintfExW
          (ushort *param_1,__uint64 param_2,ushort **param_3,__uint64 *param_4,ulong param_5,
          ushort *param_6,...)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  long lVar4;
  __uint64 _Var5;
  ushort *puVar6;
  char cStack0000000000000038;
  
  iVar1 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar1 = 0;
    if (0x7ffffffe < param_2 - 1) {
      iVar1 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (ushort *)0x0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    iVar1 = -0x3ffffff3;
  }
  if (iVar1 < 0) {
    if (param_2 == 0) {
      return iVar1;
    }
    *param_1 = 0;
    return iVar1;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (ushort *)0x0)) {
    param_6 = (ushort *)L"";
  }
  lVar4 = 0;
  _Var5 = param_2;
  puVar6 = param_1;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == L'\0') goto LAB_1400067f6;
      lVar4 = (-(uint)(param_1 != (ushort *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      uVar3 = param_2 - 1;
      iVar1 = _vsnwprintf((wchar_t *)param_1,uVar3,(wchar_t *)param_6,&cStack0000000000000038);
      if (iVar1 < 0) {
LAB_14000686c:
        lVar4 = -0x7ffffffb;
LAB_140006871:
        param_1[uVar3] = 0;
      }
      else {
        uVar2 = (ulonglong)iVar1;
        if (uVar3 < uVar2) goto LAB_14000686c;
        if (uVar2 == uVar3) goto LAB_140006871;
        uVar3 = uVar2;
      }
      _Var5 = param_2 - uVar3;
      puVar6 = param_1 + uVar3;
      if (-1 < lVar4) {
        if ((((param_5 >> 9 & 1) != 0) && (1 < _Var5)) && (2 < _Var5 * 2)) {
          memset(puVar6 + 1,param_5 & 0xff,_Var5 * 2 - 2);
        }
        goto LAB_1400067f6;
      }
    }
  }
  else {
    lVar4 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    uVar3 = param_2 & 0x7fffffffffffffff;
    if ((uVar3 != 0) && ((param_5 >> 0xc & 1) != 0)) {
      *param_1 = 0;
      _Var5 = uVar3;
      puVar6 = param_1;
    }
    if ((param_5 >> 10 & 1) == 0) {
LAB_1400067c9:
      if (uVar3 == 0) goto LAB_1400067de;
    }
    else {
      memset(param_1,param_5 & 0xff,param_2 * 2);
      if ((char)param_5 == '\0') {
        _Var5 = uVar3;
        puVar6 = param_1;
        goto LAB_1400067c9;
      }
      if (uVar3 == 0) goto LAB_1400067de;
      _Var5 = 1;
      puVar6 = param_1 + (param_2 - 1);
      *puVar6 = 0;
    }
    if ((param_5 >> 0xb & 1) != 0) {
      *param_1 = 0;
      _Var5 = uVar3;
      puVar6 = param_1;
    }
  }
LAB_1400067de:
  if (((lVar4 + 0x80000000U & 0x80000000) == 0) && (lVar4 != -0x7ffffffb)) {
    return lVar4;
  }
LAB_1400067f6:
  if (param_3 != (ushort **)0x0) {
    *param_3 = puVar6;
  }
  if (param_4 != (__uint64 *)0x0) {
    *param_4 = _Var5;
  }
  return lVar4;
}



===== SendHardwareRequestToClientDriver @ 140006904 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::Ppm::SendHardwareRequestToClientDriver(struct WDFREQUEST__ *
   __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::SendHardwareRequestToClientDriver(Ppm *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x39,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x8c8))
                    (WdfDriverGlobals,param_1,this->m_HardwareRequestQueue);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x3a,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,
                         (char)iVar1);
    }
    (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3b,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== SetHardwareRequestQueue @ 140006a34 =====

/* public: void __cdecl UcmUcsiCx::Ppm::SetHardwareRequestQueue(struct WDFQUEUE__ * __ptr64) __ptr64
    */

void __thiscall UcmUcsiCx::Ppm::SetHardwareRequestQueue(Ppm *this,WDFQUEUE__ *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x36,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  if (this->m_HardwareRequestQueue == (WDFQUEUE__ *)0x0) {
    this->m_HardwareRequestQueue = param_1;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x37,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_);
    }
    Verify::Break();
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x38,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== ValidateAndCacheUcsiVersion @ 140006b2c =====

/* private: void __cdecl UcmUcsiCx::Ppm::ValidateAndCacheUcsiVersion(union _UCSI_VERSION const &
   __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::ValidateAndCacheUcsiVersion(Ppm *this,_UCSI_VERSION *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = param_1->AsUInt16;
  if (uVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,0x4e,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_);
    }
    if ((this->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue) {
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x4f,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_);
    }
  }
  else {
    uVar2 = (this->m_UcsiVersion).AsUInt16;
    if (uVar2 == uVar1) {
      return;
    }
    if (uVar2 == 0) {
      (this->m_UcsiVersion).AsUInt16 = uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x51,
                 &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,
                 (this->m_UcsiVersion)._s_1.MajorVersion,(byte)(uVar1 >> 4) & 0xf,(byte)uVar1 & 0xf)
      ;
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x50,
                 &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,
                 (this->m_UcsiVersion)._s_1.MajorVersion,(byte)(uVar2 >> 4) & 0xf,
                 (param_1->_s_1).MajorVersion,(byte)(uVar1 >> 4) & 0xf);
    }
    if (this->m_HardwareBringUpModeEnabled == false) {
      return;
    }
  }
  Verify::Break();
  return;
}



===== WriteDevPropWithUcsiVersion @ 140006ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiCx::Ppm::WriteDevPropWithUcsiVersion(union _UCSI_VERSION const &
   __ptr64) __ptr64 */

long __thiscall UcmUcsiCx::Ppm::WriteDevPropWithUcsiVersion(Ppm *this,_UCSI_VERSION *param_1)

{
  long lVar1;
  undefined2 uVar2;
  undefined1 auStackY_88 [32];
  ushort *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined8 local_30;
  ushort local_28 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = (ushort *)0x0;
  local_3c = 0;
  local_30 = 0;
  lVar1 = RtlStringCchPrintfExW(local_28,5,&local_48,(__uint64 *)0x0,0x200,(ushort *)L"%x.%x");
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar2 = 0x23;
  }
  else {
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
       (10 < (int)((longlong)local_48 - (longlong)local_28 >> 1) * 2 + 2U)) {
      RtlAssert("versionStringCbLength <= sizeof(versionString)",
                "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\ppm.cpp",0x1a5,0);
    }
    local_3c = 0;
    local_30 = 0;
    local_38 = &DEVPKEY_Device_FirmwareVersion;
    local_40 = 0x18;
    lVar1 = (**(code **)(WdfFunctions_01023 + 0xd98))
                      (WdfDriverGlobals,this->m_CxDevice->_padding_,&local_40,0x12);
    if (-1 < lVar1) {
      return lVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar2 = 0x24;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,uVar2,
                    &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)lVar1);
  return lVar1;
}



===== WPP_RECORDER_SF_qDDD @ 140006e94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDD
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
               &param_6,8,&param_7,4,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,&param_9,
                  4,0);
  return;
}



===== WPP_RECORDER_SF_qDDDLDD @ 140007008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDLDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,0x25,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,0x25,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_qSl @ 140007180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qSl(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,0x2c,&uStack0000000000000030,8,
               L"HardwareBringUpModeEnabled",0x36,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,0x2c,
                  &uStack0000000000000030,8,L"HardwareBringUpModeEnabled",0x36,
                  &uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qDq @ 140007284 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,0x25,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,0x25,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 140007378 =====

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



===== imp_UcmUcsiConnectorCollectionAddConnector @ 1400074b0 =====

long imp_UcmUcsiConnectorCollectionAddConnector
               (_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSI_CONNECTOR_COLLECTION__ *param_2,
               _UCMUCSI_CONNECTOR_INFO *param_3)

{
  long lVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0xf,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if ((((-1 < lVar1) &&
       (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"ConnectorCollectionObject"),
       -1 < lVar1)) &&
      (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"ConnectorInfo"), -1 < lVar1)) &&
     ((lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0'), -1 < lVar1 &&
      (lVar1 = UcmUcsiCx::Ppm::ConnectorCollectionAddConnector(param_2,param_3), lVar1 < 0)))) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x10,
                       &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,(char)param_2,(char)lVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x11,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return lVar1;
}



===== imp_UcmUcsiConnectorCollectionCreate @ 1400075f0 =====

long imp_UcmUcsiConnectorCollectionCreate
               (_UCMUCSI_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,
               _WDF_OBJECT_ATTRIBUTES *param_3,UCMUCSI_CONNECTOR_COLLECTION__ **param_4)

{
  long lVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,10,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if ((-1 < lVar1) &&
     (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"WdfDevice"), -1 < lVar1)) {
    uVar2 = SUB81(param_2,0);
    if ((param_3 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
       ((param_3->ParentObject == (WDFDEVICE__ *)0x0 || (param_3->ParentObject == param_2)))) {
      lVar1 = UcmUcsiCx::Verify::IsNotNull(param_4,(ushort *)L"ConnectorCollection");
      if ((-1 < lVar1) && (lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0'), -1 < lVar1)) {
        lVar1 = UcmUcsiCx::Ppm::CreateConnectorCollection(param_2,param_3,param_4);
        if (lVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return lVar1;
          }
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xc,
                             &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar2,(char)lVar1);
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return lVar1;
          }
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,8,0xd,
                             &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar2,(char)*param_4);
        }
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0xb,
                          &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar2);
      }
      lVar1 = -0x3ffffff0;
      UcmUcsiCx::Verify::Break();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0xe,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return lVar1;
}



===== imp_UcmUcsiPpmCreate @ 1400077e0 =====

long imp_UcmUcsiPpmCreate
               (_UCMUCSI_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_UCMUCSI_PPM_CONFIG *param_3,
               _WDF_OBJECT_ATTRIBUTES *param_4,longlong *param_5)

{
  ulong uVar1;
  longlong lVar2;
  long lVar3;
  CxDevice *pCVar4;
  wchar_t *pwVar5;
  undefined1 uVar6;
  Ppm *local_58;
  _UCMUCSI_PPM_CONFIG local_50;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x12,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  local_58 = (Ppm *)0x0;
  local_50.Size = 0;
  local_50.UsbDeviceControllerEnabled = '\0';
  local_50._5_3_ = 0;
  local_50.ConnectorCollectionHandle = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  local_50.UcsiVersion.AsUInt16 = 0;
  local_50._18_2_ = 0;
  local_50.UcsiDataBlockExEnabled = WdfFalse;
  local_50.UcsiMaxDataLength = 0;
  local_50._28_4_ = 0;
  lVar3 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if ((lVar3 < 0) ||
     (lVar3 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"WdfDevice"), lVar3 < 0))
  goto LAB_140007a7a;
  pCVar4 = UcmUcsiCx::CxDevice::GetContextFromObject(param_2);
  uVar6 = SUB81(param_2,0);
  if ((param_4 == (_WDF_OBJECT_ATTRIBUTES *)0x0) ||
     ((param_4->ParentObject == (WDFDEVICE__ *)0x0 || (param_4->ParentObject == param_2)))) {
    lVar3 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"Config");
    if (lVar3 < 0) goto LAB_140007a7a;
    pwVar5 = L"PPMObject";
    lVar3 = UcmUcsiCx::Verify::IsNotNull(param_5,(ushort *)L"PPMObject");
    if ((lVar3 < 0) || (lVar3 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0'), lVar3 < 0))
    goto LAB_140007a7a;
    uVar1 = param_3->Size;
    if (uVar1 != 0x20) {
      if (uVar1 != 0x10) {
        lVar3 = -0x3ffffffc;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar5,8,0x14,
                              &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar6,(char)uVar1,4);
        }
        goto LAB_1400078dd;
      }
      local_50.ConnectorCollectionHandle = param_3->ConnectorCollectionHandle;
      param_3 = &local_50;
      local_50.Size = 0x20;
      local_50.UsbDeviceControllerEnabled = '\0';
      local_50._5_3_ = 0;
      local_50.UcsiMaxDataLength = 0;
      local_50._28_4_ = 0;
      local_50.UcsiVersion.AsUInt16 = 0;
      local_50._18_2_ = 0;
      local_50.UcsiDataBlockExEnabled = WdfUseDefault;
    }
    lVar3 = UcmUcsiCx::Ppm::IsConfigValid(pCVar4,param_3);
    if (-1 < lVar3) {
      lVar3 = UcmUcsiCx::Ppm::CreateAndInitialize(pCVar4,param_3,param_4,&local_58);
      if (-1 < lVar3) {
        lVar3 = 0;
        lVar2 = local_58->_padding_;
        *param_5 = lVar2;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0;
        }
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_3,8,0x16,
                           &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar6,(char)lVar2);
      }
      goto LAB_140007a7a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x15,
                         &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar6,(char)lVar3);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x13,
                        &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,uVar6);
    }
    lVar3 = -0x3ffffff0;
  }
LAB_1400078dd:
  UcmUcsiCx::Verify::Break();
LAB_140007a7a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x17,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return lVar3;
}



===== imp_UcmUcsiPpmNotification @ 140007ae0 =====

void imp_UcmUcsiPpmNotification
               (_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSIPPM__ *param_2,_UCSI_DATA_BLOCK *param_3)

{
  long lVar1;
  Ppm *this;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x22,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (-1 < lVar1) {
    lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"PpmObject");
    if (-1 < lVar1) {
      lVar1 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"DataBlock");
      if (-1 < lVar1) {
        lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\x02');
        if (-1 < lVar1) {
          this = UcmUcsiCx::Ppm::GetContextFromObject(param_2);
          UcmUcsiCx::Ppm::PpmNotificationReceived(this,param_3);
        }
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x23,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return;
}



===== imp_UcmUcsiPpmNotificationEx @ 140007be0 =====

void imp_UcmUcsiPpmNotificationEx
               (_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSIPPM__ *param_2,
               _UCSI_DATA_BLOCK_HEADER *param_3,void *param_4)

{
  long lVar1;
  Ppm *this;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x24,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (-1 < lVar1) {
    lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"PpmObject");
    if (-1 < lVar1) {
      lVar1 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"DataBlockHeader");
      if (-1 < lVar1) {
        lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\x02');
        if (-1 < lVar1) {
          this = UcmUcsiCx::Ppm::GetContextFromObject(param_2);
          if (((param_3->CCI)._s_1.DataLength == 0) || (param_4 != (void *)0x0)) {
            UcmUcsiCx::Ppm::PpmNotificationReceivedEx(this,param_3,param_4);
          }
          else {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            UcmUcsiCx::Verify::Break();
          }
        }
      }
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x26,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return;
}



===== imp_UcmUcsiPpmSetUcsiCommandRequestQueue @ 140007d40 =====

void imp_UcmUcsiPpmSetUcsiCommandRequestQueue
               (_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSIPPM__ *param_2,WDFQUEUE__ *param_3)

{
  long lVar1;
  Ppm *this;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x18,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if ((((-1 < lVar1) &&
       (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"PpmObject"), -1 < lVar1)) &&
      (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_3,(ushort *)L"PpmRequestQueue"), -1 < lVar1)) &&
     (lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\x02'), -1 < lVar1)) {
    this = UcmUcsiCx::Ppm::GetContextFromObject(param_2);
    if (this->m_IsStarted == false) {
      UcmUcsiCx::Ppm::SetHardwareRequestQueue(this,param_3);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,8,0x1a,
                        &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,(char)param_2);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,8,0x19,
                          &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,(char)param_2);
      }
      UcmUcsiCx::Verify::Break();
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1b,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return;
}



===== imp_UcmUcsiPpmStart @ 140007ec0 =====

long imp_UcmUcsiPpmStart(_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSIPPM__ *param_2)

{
  long lVar1;
  Ppm *this;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1c,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (((-1 < lVar1) &&
      (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"PpmObject"), -1 < lVar1)) &&
     (lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0'), -1 < lVar1)) {
    this = UcmUcsiCx::Ppm::GetContextFromObject(param_2);
    lVar1 = UcmUcsiCx::Ppm::Start(this);
    if (-1 < lVar1) {
      lVar1 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,8,0x1d,
                        &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,(char)param_2);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1e,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return lVar1;
}



===== imp_UcmUcsiPpmStop @ 140007ff0 =====

void imp_UcmUcsiPpmStop(_UCMUCSI_DRIVER_GLOBALS *param_1,UCMUCSIPPM__ *param_2)

{
  long lVar1;
  Ppm *this;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x1f,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  lVar1 = UcmUcsiCx::Verify::IsDriverGlobalsValid(param_1);
  if (((-1 < lVar1) &&
      (lVar1 = UcmUcsiCx::Verify::IsNotNull(param_2,(ushort *)L"PpmObject"), -1 < lVar1)) &&
     (lVar1 = UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo('\0'), -1 < lVar1)) {
    this = UcmUcsiCx::Ppm::GetContextFromObject(param_2);
    UcmUcsiCx::Ppm::Stop(this);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,8,0x20,
                      &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids,(char)this);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,8,0x21,
                     &WPP_1ffb804d0459310ad997fc779ed8b0ed_Traceguids);
  }
  return;
}



===== AssignHardwareRequestBuffer @ 14000810c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiCx::PpmInterface::AssignHardwareRequestBuffer(unsigned long,void *
   __ptr64,unsigned __int64,struct WDFMEMORY__ * __ptr64 * __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::PpmInterface::AssignHardwareRequestBuffer
          (PpmInterface *this,ulong param_1,void *param_2,__uint64 param_3,WDFMEMORY__ **param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  WDFREQUEST__ *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x26,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  local_58 = 0;
  uStack_50 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = (WDFREQUEST__ *)0x0;
  uStack_30 = 0;
  if (*param_4 == (WDFMEMORY__ *)0x0) {
    local_58 = 0x38;
    uStack_40 = 0x100000001;
    local_38 = this->m_HardwareRequest;
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x608))
                      (WdfDriverGlobals,&local_58,param_2,param_3,param_4);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar2 = 0x27;
      uVar3 = (undefined1)this->m_Ppm->_padding_;
LAB_140008219:
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar2,
                          &WPP_e278b5df54c93308c1906314c6922925_Traceguids,uVar3,(char)param_1,
                          (char)iVar1);
      goto LAB_140008280;
    }
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x618))(WdfDriverGlobals,*param_4,param_2,param_3);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar2 = 0x28;
      uVar3 = (undefined1)this->m_Ppm->_padding_;
      goto LAB_140008219;
    }
  }
  iVar1 = 0;
LAB_140008280:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x29,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return iVar1;
}



===== DispatchHardwareRequest @ 1400082dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl UcmUcsiCx::PpmInterface::DispatchHardwareRequest(struct WDFREQUEST__
   * __ptr64) */

void __cdecl UcmUcsiCx::PpmInterface::DispatchHardwareRequest(WDFREQUEST__ *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  Ppm *this;
  undefined8 *local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xf,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  this = (Ppm *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x11,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  local_res8 = (undefined8 *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01023 + 0x8d0))(WdfDriverGlobals,param_1);
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x4e8))(WdfDriverGlobals,uVar3);
  iVar2 = (**(code **)(WdfFunctions_01023 + 0x868))(WdfDriverGlobals,param_1,8,&local_res8,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x12,
                         &WPP_e278b5df54c93308c1906314c6922925_Traceguids,uVar1,(char)iVar2);
    }
    if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
      RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\ppminterface.cpp",0x8d,0);
    }
  }
  else {
    this = Ppm::GetContextFromObject((UCMUCSIPPM__ *)*local_res8);
    iVar2 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x13,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  if (iVar2 < 0) {
    if (param_1 != (WDFREQUEST__ *)0x0) {
      (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_1,iVar2);
    }
  }
  else {
    Ppm::SendHardwareRequestToClientDriver(this,param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x10,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== GetUcsiData @ 14000851c =====

/* public: void __cdecl UcmUcsiCx::PpmInterface::GetUcsiData(struct
   _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS * __ptr64,struct
   _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_OUT_PARAMS * __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::PpmInterface::GetUcsiData
          (PpmInterface *this,_UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS *param_1,
          _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_OUT_PARAMS *param_2)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1c,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  SendRequestToSelfIoTarget(this,0x5d4004,param_1,8,param_2,0x30);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1d,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== GetUcsiDataEx @ 1400085f4 =====

/* public: void __cdecl UcmUcsiCx::PpmInterface::GetUcsiDataEx(struct
   _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS * __ptr64,struct
   _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_EX_OUT_PARAMS * __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::PpmInterface::GetUcsiDataEx
          (PpmInterface *this,_UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_IN_PARAMS *param_1,
          _UCMUCSI_PPM_GET_UCSI_DATA_BLOCK_EX_OUT_PARAMS *param_2)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1e,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  SendRequestToSelfIoTarget
            (this,0x5d400c,param_1,8,param_2,
             (ulonglong)((this->m_Ppm->m_PpmConfig).UcsiMaxDataLength + 0x10));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1f,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== HardwareRequestCompletionRoutine @ 1400086e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl UcmUcsiCx::PpmInterface::HardwareRequestCompletionRoutine(struct
   WDFREQUEST__ * __ptr64,struct WDFIOTARGET__ * __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS *
   __ptr64,void * __ptr64) */

void __cdecl
UcmUcsiCx::PpmInterface::HardwareRequestCompletionRoutine
          (WDFREQUEST__ *param_1,WDFIOTARGET__ *param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
          void *param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  undefined2 uVar5;
  ulong uVar6;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x2a,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  iVar4 = (param_3->IoStatus).field0_0x0.Status;
  uVar6 = (param_3->Parameters).Ioctl.IoControlCode;
  uVar1 = (param_3->Parameters).Ioctl.Output.Length;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,9,0x2b,
                          &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
                          (char)**(undefined8 **)((longlong)param_4 + 0x20),(char)uVar6,(char)iVar4)
      ;
    }
    goto LAB_14000891b;
  }
  if (uVar6 == 0x5d4004) {
    uVar3 = 0x30;
  }
  else if (uVar6 == 0x5d400c) {
    uVar3 = 0x18;
  }
  else {
    if (((uVar6 != 0x5d8000) && (uVar6 != 0x5d8008)) && ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0)
       ) {
      RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\ppminterface.cpp",0x1bf,0);
    }
    uVar3 = 0;
  }
  if (uVar1 == uVar3) goto LAB_14000891b;
  if (uVar6 == 0x5d400c) {
    if (uVar1 < 8) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x2d;
        uVar3 = 8;
        uVar6 = 0x5d400c;
        goto LAB_1400088c2;
      }
    }
    else {
      lVar2 = (**(code **)(WdfFunctions_01023 + 0x610))
                        (WdfDriverGlobals,(param_3->Parameters).Ioctl.Output.Buffer,0);
      if ((*(byte *)(lVar2 + 5) == 0) || (*(byte *)(lVar2 + 5) + 0x10 <= uVar1)) goto LAB_14000891b;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLDPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar5 = 0x2e;
LAB_1400088c2:
    WPP_RECORDER_SF_qLPP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar5,
               &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
               (char)**(undefined8 **)((longlong)param_4 + 0x20),(char)uVar6,(char)uVar3,(char)uVar1
              );
  }
  iVar4 = -0x3ffffdfa;
  Verify::Break();
LAB_14000891b:
  (**(code **)((longlong)param_4 + 0x18))(*(undefined8 *)((longlong)param_4 + 0x20),iVar4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x2f,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== SendRequestToSelfIoTarget @ 140008980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl UcmUcsiCx::PpmInterface::SendRequestToSelfIoTarget(unsigned long,void *
   __ptr64,unsigned __int64,void * __ptr64,unsigned __int64) __ptr64 */

void __thiscall
UcmUcsiCx::PpmInterface::SendRequestToSelfIoTarget
          (PpmInterface *this,ulong param_1,void *param_2,__uint64 param_3,void *param_4,
          __uint64 param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined1 auStackY_d8 [32];
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x20,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = (**(code **)(WdfFunctions_01023 + 0xdc0))
                    (WdfDriverGlobals,this->m_Ppm->m_CxDevice->_padding_);
  local_74 = 0;
  local_6c = 0;
  local_80 = 0x18;
  local_78 = 0;
  iVar2 = (**(code **)(WdfFunctions_01023 + 0x7c8))
                    (WdfDriverGlobals,this->m_HardwareRequest,&local_80);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x21,
                         &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)iVar2);
    }
  }
  else if (((param_2 == (void *)0x0) ||
           (iVar2 = AssignHardwareRequestBuffer(this,param_1,param_2,param_3,&this->m_InputMemory),
           -1 < iVar2)) &&
          ((param_4 == (void *)0x0 ||
           (iVar2 = AssignHardwareRequestBuffer(this,param_1,param_4,param_5,&this->m_OutputMemory),
           -1 < iVar2)))) {
    iVar2 = (**(code **)(WdfFunctions_01023 + 0x5d8))
                      (WdfDriverGlobals,uVar3,this->m_HardwareRequest,param_1);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar4 = 0x22;
LAB_140008b7e:
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,uVar4,
                           &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
                           (char)this->m_Ppm->_padding_,(char)iVar2);
      }
    }
    else {
      (**(code **)(WdfFunctions_01023 + 0x820))
                (WdfDriverGlobals,this->m_HardwareRequest,HardwareRequestCompletionRoutine,this);
      local_68 = 0x100000010;
      uStack_60 = 0xffffffffff676980;
      iVar2 = (**(code **)(WdfFunctions_01023 + 0x830))(WdfDriverGlobals,this->m_HardwareRequest);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0x23;
          goto LAB_140008b7e;
        }
      }
      else {
        cVar1 = (**(code **)(WdfFunctions_01023 + 0x7e8))
                          (WdfDriverGlobals,this->m_HardwareRequest,uVar3,&local_68);
        if (cVar1 != '\0') goto LAB_140008d0d;
        iVar2 = (**(code **)(WdfFunctions_01023 + 0x7f0))(WdfDriverGlobals,this->m_HardwareRequest);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0x24,
                              &WPP_e278b5df54c93308c1906314c6922925_Traceguids,
                              (char)this->m_Ppm->_padding_,(char)param_1,(char)iVar2);
        }
        if (-1 < iVar2) goto LAB_140008d0d;
      }
    }
  }
  (*this->m_HardwareRequestCompletionCallback)(this->m_Ppm,iVar2);
LAB_140008d0d:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x25,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== SendUcsiData @ 140008d68 =====

/* public: void __cdecl UcmUcsiCx::PpmInterface::SendUcsiData(struct
   _UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS * __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::PpmInterface::SendUcsiData
          (PpmInterface *this,_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_IN_PARAMS *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x18,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  SendRequestToSelfIoTarget(this,0x5d8000,param_1,0x38,(void *)0x0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x19,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== SendUcsiDataEx @ 140008e38 =====

/* public: void __cdecl UcmUcsiCx::PpmInterface::SendUcsiDataEx(struct
   _UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_EX_IN_PARAMS * __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::PpmInterface::SendUcsiDataEx
          (PpmInterface *this,_UCMUCSI_PPM_SEND_UCSI_DATA_BLOCK_EX_IN_PARAMS *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1a,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  SendRequestToSelfIoTarget
            (this,0x5d8008,param_1,
             (ulonglong)(param_1->DataBlockHeader).Control._s_1.DataLength + 0x18,(void *)0x0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0x1b,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return;
}



===== WPP_RECORDER_SF_qLDPP @ 140008f0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLDPP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e278b5df54c93308c1906314c6922925_Traceguids,0x2c,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,2,9,&WPP_e278b5df54c93308c1906314c6922925_Traceguids,0x2c,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_qLPP @ 14000904c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLPP
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
               &param_6,8,&param_7,4,&param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,8,&param_9,
                  8,0);
  return;
}



===== AckCommand @ 1400091c0 =====

/* private: void __cdecl UcmUcsiCx::Opm::AckCommand(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::AckCommand(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x46,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  CommandHandler::EnqueueAck(&this->m_CommandHandler,false);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x47,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== AckCommandAndConnectorChange @ 140009264 =====

/* private: void __cdecl UcmUcsiCx::Opm::AckCommandAndConnectorChange(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::AckCommandAndConnectorChange(Opm *this)

{
  _UCM_PD_POWER_DATA_OBJECT *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x48,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  CommandHandler::EnqueueAck(&this->m_CommandHandler,true);
  (this->m_ConnectorChangeCtx).InProgress = 0;
  (this->m_ConnectorChangeCtx).ChargingState = UcmChargingStateInvalid;
  (this->m_ConnectorChangeCtx).Rdo.Ul = 0;
  (this->m_ConnectorChangeCtx).Pdos[0].Ul = 0;
  p_Var1 = (this->m_ConnectorChangeCtx).Pdos + 1;
  (&p_Var1->Ul)[0] = 0;
  (&p_Var1->Ul)[1] = 0;
  p_Var1 = (this->m_ConnectorChangeCtx).Pdos + 3;
  (&p_Var1->Ul)[0] = 0;
  (&p_Var1->Ul)[1] = 0;
  p_Var1 = (this->m_ConnectorChangeCtx).Pdos + 5;
  (&p_Var1->Ul)[0] = 0;
  (&p_Var1->Ul)[1] = 0;
  *(undefined4 *)&(this->m_ConnectorChangeCtx).PdoCount = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x49,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendAckForLastCommandEntry @ 140009330 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendAckForLastCommandEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::SendAckForLastCommandEntry
          (void *param_1)

{
  Opm::AckCommand(param_1);
  return 6;
}



===== AddConnector @ 14000934c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: struct UcmUcsiCx::_PPM_CONNECTOR * __ptr64 __cdecl UcmUcsiCx::Opm::AddConnector(void)
   __ptr64 */

_PPM_CONNECTOR * __thiscall UcmUcsiCx::Opm::AddConnector(Opm *this)

{
  int iVar1;
  ulong uVar2;
  undefined2 uVar3;
  _PPM_CONNECTOR *local_res8;
  WDFMEMORY__ *local_res10;
  undefined8 local_58;
  code *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  WDFCOLLECTION__ *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x22,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res10 = (WDFMEMORY__ *)0x0;
  local_40 = 1;
  local_3c = 1;
  local_38 = this->m_Connectors;
  local_50 = EvtPpmConnectorContextCleanup;
  local_res8 = (_PPM_CONNECTOR *)0x0;
  local_58 = 0x38;
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x600))
                    (WdfDriverGlobals,&local_58,0x200,0,0x60,&local_res10,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x23;
LAB_140009472:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar3,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)iVar1);
    }
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x78))
                      (WdfDriverGlobals,this->m_Connectors,local_res10);
    if (-1 < iVar1) {
      memset(local_res8,0,0x60);
      local_res8->WdfObject = local_res10;
      local_res8->WdfDevice = (WDFDEVICE__ *)this->m_Ppm->m_CxDevice->_padding_;
      uVar2 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,this->m_Connectors);
      local_res8->Index = uVar2;
      local_res8->UcmConnector = (UCMCONNECTOR__ *)0x0;
      goto LAB_14000952a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 0x24;
      goto LAB_140009472;
    }
  }
  if (local_res8 != (_PPM_CONNECTOR *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals,local_res10);
    local_res8 = (_PPM_CONNECTOR *)0x0;
  }
LAB_14000952a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x25,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return local_res8;
}



===== AreAlternateModesPresent @ 140009580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::AreAlternateModesPresent(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::AreAlternateModesPresent(Opm *this)

{
  byte bVar1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  Event EVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_58 = 0;
  uStack_50 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  bVar1 = (this->m_PpmCapabilities).field2_0x5._s_3.bNumAltModes;
  if (((bVar1 != 0) && ((this->m_PpmCapabilities).field2_0x5.AlternateModeDetailsAvailable != 0)) &&
     ((char)(p_Var3->field10_0x29).Capabilities.OperationMode.AsUInt8 < '\0')) {
    local_58 = CONCAT44(local_58._4_4_,0x38);
    uStack_40 = 0x100000001;
    local_38 = this->m_Ppm->_padding_;
    iVar2 = (**(code **)(WdfFunctions_01023 + 0x600))
                      (WdfDriverGlobals,&local_58,0x200,0,(ulonglong)bVar1 << 3,
                       &p_Var3->AltModesMemory,&p_Var3->AltModes);
    if (-1 < iVar2) {
      EVar4 = Yes;
      goto LAB_1400096d7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qPDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  EVar4 = No;
LAB_1400096d7:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar4;
}



===== CacheGetConnectorStatusData @ 140009738 =====

/* private: void __cdecl UcmUcsiCx::Opm::CacheGetConnectorStatusData(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::CacheGetConnectorStatusData(Opm *this)

{
  undefined8 uVar1;
  bool bVar2;
  undefined8 uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x50,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  bVar2 = true;
  if (((this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue) ||
     ((this->m_Ppm->m_PpmConfig).UcsiVersion._s_1.MajorVersion < 2)) {
    bVar2 = false;
  }
  if (bVar2) {
    uVar1 = *(undefined8 *)
             (this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
    uVar3 = *(undefined8 *)
             ((this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn + 8);
    (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 = (short)uVar1;
    (this->field26_0xc58).m_ConnectorStatus.field1_0x2._s_0 =
         (_UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0)(short)((ulonglong)uVar1 >> 0x10);
    (this->field26_0xc58).m_ConnectorStatus.RequestDataObject = (int)((ulonglong)uVar1 >> 0x20);
    *(undefined8 *)&(this->field26_0xc58).m_ConnectorStatus.field3_0x8._s_0 = uVar3;
  }
  else {
    uVar1 = *(undefined8 *)
             (this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
    (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 = (short)uVar1;
    (this->field26_0xc58).m_ConnectorStatus.field1_0x2._s_0 =
         (_UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0)(short)((ulonglong)uVar1 >> 0x10);
    (this->field26_0xc58).m_ConnectorStatus.RequestDataObject = (int)((ulonglong)uVar1 >> 0x20);
    (this->field26_0xc58).m_ConnectorStatus.field3_0x8._s_0 =
         *(_UCSI_GET_CONNECTOR_STATUS_IN_u_8_s_0 *)
          ((this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn + 8);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x51,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== CacheGetConnectorStatusDataOnNotificationEntry @ 140009820 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CacheGetConnectorStatusDataOnNotificationEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CacheGetConnectorStatusDataOnNotificationEntry(void *param_1)

{
  Opm::CacheGetConnectorStatusData(param_1);
  return 6;
}



===== CheckBatteryStatusChangeEntry @ 140009840 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckBatteryStatusChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckBatteryStatusChangeEntry
          (void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,99,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,100,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((uVar1 & 0x200) != 0) & 0xb) + 9;
}



===== CheckConnectChangeEntry @ 140009900 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckConnectChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckConnectChangeEntry
          (void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x65,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x66,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((uVar1 & 0x4000) != 0) & 0xb) + 9;
}



===== CheckConnectStatusOnPowerUpEntry @ 1400099c0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckConnectStatusOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckConnectStatusOnPowerUpEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::IsStatusConnected(param_1);
  return EVar1;
}



===== CheckConnectorCapabilitiesEntry @ 1400099e0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckConnectorCapabilitiesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckConnectorCapabilitiesEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::CheckIfConnectorCapabilitiesIsValid(param_1);
  return EVar1;
}



===== CheckConnectorStatusDataValidityOnPowerUpEntry @ 140009a00 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckConnectorStatusDataValidityOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckConnectorStatusDataValidityOnPowerUpEntry(void *param_1)

{
  int iVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x69,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  iVar1 = *(int *)((longlong)param_1 + 0xc6c);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)(iVar1 != 0) & 0xb) + 9;
}



===== CheckDataDirectionChangeEntry @ 140009ab0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckDataDirectionChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckDataDirectionChangeEntry
          (void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x67,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x68,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((uVar1 & 0x800) != 0) & 0xb) + 9;
}



===== CheckErrorEntry @ 140009b70 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckErrorEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckErrorEntry(void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x74,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if ((Driver::m_TestSigning != false) && (*(short *)((longlong)param_1 + 0xc58) < 0)) {
    if (*(char *)((longlong)param_1 + 0xc99) != '\0') {
      uVar1 = 0x14;
      goto LAB_140009c2a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,10,0x75,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)**(undefined8 **)((longlong)param_1 + 8),
                         (char)*(undefined4 *)((longlong)param_1 + 0xc54));
    }
  }
  uVar1 = 9;
LAB_140009c2a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x76,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return uVar1;
}



===== CheckForPDInHandlePowerOperationModeEntry @ 140009c80 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckForPDInHandlePowerOperationModeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckForPDInHandlePowerOperationModeEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::IsPowerOperationModePD(param_1);
  return EVar1;
}



===== CheckIfAltModeNeedsToBeReportedEntry @ 140009ca0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfAltModeNeedsToBeReportedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckIfAltModeNeedsToBeReportedEntry(void *param_1)

{
  _PPM_CONNECTOR *p_Var1;
  ushort uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xfe,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = Opm::GetConnector(param_1,*(ulong *)((longlong)param_1 + 0xc54));
  if ((p_Var1->AltModesReported != '\0') ||
     (uVar2 = 0x14, (*(byte *)((longlong)param_1 + 0x5bd) & 4) == 0)) {
    uVar2 = 9;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xff,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return uVar2;
}



===== CheckIfConnectorCapabilitiesIsValid @ 140009d6c =====

/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::CheckIfConnectorCapabilitiesIsValid(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::CheckIfConnectorCapabilitiesIsValid(Opm *this)

{
  byte bVar1;
  _WDF_TRI_STATE _Var2;
  uint uVar3;
  bool bVar4;
  _PPM_CONNECTOR *p_Var5;
  Ppm *pPVar6;
  ushort uVar7;
  uint uVar8;
  undefined2 uVar9;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x54,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  pPVar6 = this->m_Ppm;
  bVar4 = true;
  _Var2 = (pPVar6->m_PpmConfig).UcsiDataBlockExEnabled;
  if ((_Var2 != WdfTrue) || (uVar8 = 4, (pPVar6->m_PpmConfig).UcsiVersion._s_1.MajorVersion < 2)) {
    uVar8 = 2;
  }
  uVar3 = this->m_CciDataLength;
  if (uVar3 != uVar8) {
    if (uVar8 < uVar3) {
      bVar1 = (pPVar6->m_PpmConfig).UcsiVersion._s_1.MajorVersion;
      if (_Var2 == WdfTrue) {
        if ((bVar1 < 3) &&
           ((bVar1 != 2 || (((pPVar6->m_PpmConfig).UcsiVersion.AsUInt16 & 0xf0) < 0x11)))) {
LAB_140009e33:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qLPP
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x57,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)this->m_CurrentConnectorNumber,(char)this->m_CciDataLength,(char)uVar8
                      );
          }
          SetUnrecoverableFailureContext(this,CommandExecutionFailed,InvalidCciDataLength,0);
          return No;
        }
      }
      else if (bVar1 < 2) goto LAB_140009e33;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140009eed;
      pPVar6 = this->m_Ppm;
      uVar9 = 0x55;
    }
    else {
      if (((((uVar8 <= uVar3) || ((pPVar6->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue)) ||
           ((pPVar6->m_PpmConfig).UcsiVersion._s_1.MajorVersion != 2)) ||
          ((uVar7 = (pPVar6->m_PpmConfig).UcsiVersion.AsUInt16 & 0xf0, uVar7 != 0 && (uVar7 != 0x10)
           ))) || ((uVar3 != 2 || (pPVar6->m_HardwareBringUpModeEnabled == false))))
      goto LAB_140009e33;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140009eed;
      uVar9 = 0x56;
    }
    WPP_RECORDER_SF_qLPP
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,10,uVar9,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)pPVar6->_padding_,
               (char)this->m_CurrentConnectorNumber,(char)uVar3,(char)uVar8);
  }
LAB_140009eed:
  p_Var5 = GetConnector(this,this->m_CurrentConnectorNumber);
  if (((this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue) ||
     ((this->m_Ppm->m_PpmConfig).UcsiVersion._s_1.MajorVersion < 2)) {
    bVar4 = false;
  }
  if (bVar4) {
    (p_Var5->field10_0x29).UcsiV2Capabilities.field0_0x0.AsUInt32 =
         *(uint *)(this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
  }
  else {
    (p_Var5->field10_0x29).Capabilities =
         *(_UCSI_GET_CONNECTOR_CAPABILITY_IN *)
          (this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x58,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return Yes;
}



===== CheckIfMoreAltModePresentEntry @ 14000a000 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfMoreAltModePresentEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckIfMoreAltModePresentEntry
          (void *param_1)

{
  int iVar1;
  char *in_RDX;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffd8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    in_RDX = (char *)CONCAT71((int7)((ulonglong)in_RDX >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf2,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (*(char *)((longlong)param_1 + 0x5dc) != '\f')
     ) {
    in_RDX = "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp";
    in_R8 = 0xab1;
    RtlAssert("lastUcsiCommand == UcsiCommandGetAlternateModes",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0xab1,0);
  }
  iVar1 = *(int *)((longlong)param_1 + 0xc6c);
  if (iVar1 != 0) {
    if (iVar1 == 6) {
      *(undefined4 *)((longlong)param_1 + 0xc68) = 1;
      goto LAB_14000a0f9;
    }
    if (iVar1 == 0xc) {
      *(undefined4 *)((longlong)param_1 + 0xc68) = 2;
      goto LAB_14000a0f9;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),in_RDX,in_R8,0xf3,
                         in_stack_ffffffffffffffd8,(char)**(undefined8 **)((longlong)param_1 + 8),
                         (char)iVar1);
    }
    Verify::Break();
  }
  *(undefined4 *)((longlong)param_1 + 0xc68) = 0;
LAB_14000a0f9:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf4,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 9;
}



===== CheckIfMoreAlternateModesAreSupportedEntry @ 14000a150 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfMoreAlternateModesAreSupportedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckIfMoreAlternateModesAreSupportedEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::ShouldCheckIfMoreAltModeArePresent(param_1);
  return EVar1;
}



===== CheckIfMoreConnectorsArePresentOnPowerUpEntry @ 14000a170 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfMoreConnectorsArePresentOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckIfMoreConnectorsArePresentOnPowerUpEntry(void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::HasMoreConnectors(param_1);
  return EVar1;
}



===== CheckIfMorePdosAvailableEntry @ 14000a190 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfMorePdosAvailableEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckIfMorePdosAvailableEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::ShouldCheckForMorePdos(param_1);
  return EVar1;
}



===== CheckIfPowerDirectionDifferentFromDefaultEntry @ 14000a1b0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfPowerDirectionDifferentFromDefaultEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckIfPowerDirectionDifferentFromDefaultEntry(void *param_1)

{
  ushort uVar1;
  _PPM_CONNECTOR *p_Var2;
  int iVar3;
  ushort uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6f,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar4 = *(ushort *)((longlong)param_1 + 0xc5a);
  uVar1 = uVar4 >> 0xd;
  if (uVar1 == 1) {
    iVar3 = 2;
  }
  else if (uVar1 == 2) {
    iVar3 = 1;
  }
  else if (uVar1 == 3) {
    iVar3 = 3;
  }
  else if (uVar1 == 4) {
    iVar3 = 4;
  }
  else if (uVar1 == 5) {
    iVar3 = 6;
  }
  else {
    if (uVar1 != 6) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x70,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)**(undefined8 **)((longlong)param_1 + 8),(byte)(uVar4 >> 0xd));
      }
      uVar4 = 9;
      goto LAB_14000a2e9;
    }
    iVar3 = 5;
  }
  if (iVar3 == 2) {
    if ((uVar4 & 0x10) == 0) goto LAB_14000a2ac;
LAB_14000a2de:
    uVar4 = 0x14;
  }
  else {
    if ((iVar3 == 1) && ((uVar4 & 0x10) == 0)) goto LAB_14000a2de;
LAB_14000a2ac:
    uVar4 = 9;
  }
  p_Var2 = Opm::GetConnector(param_1,*(ulong *)((longlong)param_1 + 0xc54));
  if ((*(char *)((longlong)param_1 + 0x5a9) == '\0') && (iVar3 == 2)) {
    p_Var2->PerformRoleCorrectionOnNextPdContract = '\x01';
  }
  else {
    p_Var2->PerformRoleCorrectionOnNextPdContract = '\0';
  }
LAB_14000a2e9:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x71,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return uVar4;
}



===== CheckIfRoleCorrectionIsNeededEntry @ 14000a340 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckIfRoleCorrectionIsNeededEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
CheckIfRoleCorrectionIsNeededEntry(void *param_1)

{
  _PPM_CONNECTOR *p_Var1;
  ushort uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x80,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = Opm::GetConnector(param_1,*(ulong *)((longlong)param_1 + 0xc54));
  if (p_Var1->PerformRoleCorrectionOnNextPdContract == '\0') {
    uVar2 = 9;
  }
  else {
    p_Var1->PerformRoleCorrectionOnNextPdContract = '\0';
    uVar2 = 0x14;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x81,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return uVar2;
}



===== CheckOperationModeEntry @ 14000a410 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckOperationModeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckOperationModeEntry
          (void *param_1)

{
  byte bVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x72,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  bVar1 = *(byte *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x73,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((bVar1 & 4) != 0) & 0xb) + 9;
}



===== CheckOvercurrentEntry @ 14000a4d0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckOvercurrentEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckOvercurrentEntry
          (void *param_1)

{
  byte bVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x77,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  bVar1 = *(byte *)((longlong)param_1 + 0x808);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x78,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((bVar1 & 0x80) != 0) & 0xb) + 9;
}



===== CheckPowerDirectionChangeEntry @ 14000a590 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckPowerDirectionChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckPowerDirectionChangeEntry
          (void *param_1)

{
  ushort uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = *(ushort *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6e,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((uVar1 & 0x1000) != 0) & 0xb) + 9;
}



===== CheckPowerLevelChangeEntry @ 14000a650 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckPowerLevelChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckPowerLevelChangeEntry
          (void *param_1)

{
  byte bVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  bVar1 = *(byte *)((longlong)param_1 + 0xc58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x6c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((bVar1 & 0x40) != 0) & 0xb) + 9;
}



===== CheckPpmCapabilitiesEntry @ 14000a710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::CheckPpmCapabilitiesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::CheckPpmCapabilitiesEntry
          (void *param_1)

{
  Event EVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x59,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x70))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x5b0));
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  EVar1 = Opm::IsPpmCapabilityValid(param_1);
  return EVar1;
}



===== DisableCommandHandlerAutoAck @ 14000a7d0 =====

/* private: void __cdecl UcmUcsiCx::Opm::DisableCommandHandlerAutoAck(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::DisableCommandHandlerAutoAck(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (this->m_CommandHandler).m_AutoAckEnableRequested = WdfFalse;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== DisableCommandHandlerAutoAckEntry @ 14000a880 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::DisableCommandHandlerAutoAckEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
DisableCommandHandlerAutoAckEntry(void *param_1)

{
  Opm::DisableCommandHandlerAutoAck(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xca,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  *(undefined4 *)((longlong)param_1 + 0xc54) = 1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xcb,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 6;
}



===== EnableAllNotifications @ 14000a934 =====

/* private: void __cdecl UcmUcsiCx::Opm::EnableAllNotifications(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::EnableAllNotifications(Opm *this)

{
  _UCSI_GET_CAPABILITY_IN_u_5 *p_Var1;
  ushort uVar2;
  ushort uVar3;
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar3 = 0xda05;
  local_res8.AsUInt64 = 0xda050005;
  if (p_Var1->ExternalSupplyNotificationSupported != 0) {
    uVar3 = 0xda07;
    local_res8.AsUInt64 = 0xda070005;
  }
  uVar2 = uVar3;
  if (p_Var1->PdoDetailsAvailable != 0) {
    uVar2 = uVar3 | 0x60;
    local_res8.AsUInt64 = (ulonglong)CONCAT22(uVar3,local_res8.AsUInt64._0_2_) | 0x600000;
  }
  uVar3 = uVar2;
  if (p_Var1->PdResetNotificationSupported != 0) {
    uVar3 = uVar2 | 0x80;
    local_res8.AsUInt64 = (ulonglong)CONCAT22(uVar2,local_res8.AsUInt64._0_2_) | 0x800000;
  }
  if (p_Var1->AlternateModeDetailsAvailable != 0) {
    local_res8.AsUInt64 = (ulonglong)CONCAT22(uVar3,local_res8.AsUInt64._0_2_) | 0x1000000;
  }
  LOCK();
  this->m_ConnectorChangeNotificationsEnabled = 1;
  UNLOCK();
  EnqueueCommandInCommandHandler(this,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5e,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EnableAllNotificationsEntry @ 14000aa40 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::EnableAllNotificationsEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::EnableAllNotificationsEntry
          (void *param_1)

{
  Opm::EnableAllNotifications(param_1);
  return 0;
}



===== EnablePpmNotificationForCommandCompletionEntry @ 14000aa60 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::EnablePpmNotificationForCommandCompletionEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
EnablePpmNotificationForCommandCompletionEntry(void *param_1)

{
  Opm::SendEnableCommandCompletionNotification(param_1);
  return 0;
}



===== EnableCommandHandlerAutoAck @ 14000aa78 =====

/* private: void __cdecl UcmUcsiCx::Opm::EnableCommandHandlerAutoAck(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::EnableCommandHandlerAutoAck(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x5f,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (this->m_CommandHandler).m_AutoAckEnableRequested = WdfTrue;
  (this->m_CommandHandler).m_AutoAckEnabled = true;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x60,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EnableCommandHandlerAutoAckEntry @ 14000ab30 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::EnableCommandHandlerAutoAckEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::EnableCommandHandlerAutoAckEntry
          (void *param_1)

{
  Opm::EnableCommandHandlerAutoAck(param_1);
  return 6;
}



===== EnqueueCommandInCommandHandler @ 14000ab4c =====

/* public: void __cdecl UcmUcsiCx::Opm::EnqueueCommandInCommandHandler(union _UCSI_CONTROL const &
   __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::Opm::EnqueueCommandInCommandHandler(Opm *this,_UCSI_CONTROL *param_1)

{
  long *plVar1;
  UCMUCSI_OPM_COMMAND *pUVar2;
  int iVar3;
  byte bVar4;
  Ppm *pPVar5;
  bool bVar6;
  
  pPVar5 = this->m_Ppm;
  (this->m_ActiveCommandCtx).OpmCommand.DataBlock.m_UcsiDataBlockExEnabled =
       (pPVar5->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue;
  (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.UcsiVersion.AsUInt16 =
       (pPVar5->m_UcsiVersion).AsUInt16;
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && ((param_1->_s_1).DataLength != 0)) {
    RtlAssert("UcsiControl.DataLength == 0",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\UcsiDataBlock.h",0x53);
  }
  (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64 =
       param_1->AsUInt64;
  memset((this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlockEx.MessageOut,0,0xff)
  ;
  LOCK();
  plVar1 = &this->m_LatestOpmCmdSeqNum;
  iVar3 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  (this->m_ActiveCommandCtx).OpmCommand.FromTestInterface = false;
  pUVar2 = &(this->m_ActiveCommandCtx).OpmCommand;
  bVar4 = (param_1->_s_1).Command;
  (this->m_ActiveCommandCtx).OpmCommand.OpmCmdSeqNum = iVar3 + 1;
  pUVar2->ExecType = (uint)(bVar4 == 1);
  bVar6 = CommandHandler::SendUcsiCommand(&this->m_CommandHandler,pUVar2);
  if (!bVar6) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xcc,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)param_1->AsUInt64);
    }
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,8);
  }
  return;
}



===== EvtCommandCompletionReceived @ 14000ac80 =====

/* public: void __cdecl UcmUcsiCx::Opm::EvtCommandCompletionReceived(class UcmUcsiCx::UcsiDataBlock
   const & __ptr64,long,long) __ptr64 */

void __thiscall
UcmUcsiCx::Opm::EvtCommandCompletionReceived
          (Opm *this,UcsiDataBlock *param_1,long param_2,long param_3)

{
  UcsiDataBlock *this_00;
  int iVar1;
  ulong64 uVar2;
  ulong64 uVar3;
  longlong lVar4;
  Opm *pOVar5;
  ushort uVar6;
  undefined4 in_register_00000084;
  undefined8 uVar7;
  undefined *in_stack_ffffffffffffffb8;
  
  uVar7 = CONCAT44(in_register_00000084,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar7 = 10;
    in_stack_ffffffffffffffb8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x1d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_2 != 0)) && (param_2 != -0x3fffffff))
     && (param_2 != -0x3fffff45)) {
    uVar7 = 0x158;
    RtlAssert("CommandStatus == ((NTSTATUS)0x00000000L) || CommandStatus == ((NTSTATUS)0xC0000001L) || CommandStatus == ((NTSTATUS)0xC00000BBL)"
              ,"onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp");
  }
  this_00 = &(this->m_ActiveCommandCtx).CompletionData;
  (this->m_ActiveCommandCtx).Status = param_2;
  UcsiDataBlock::operator=(this_00,param_1);
  iVar1 = (this->m_ActiveCommandCtx).OpmCommand.OpmCmdSeqNum;
  uVar6 = 2;
  if (param_3 != iVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x1e,
                          in_stack_ffffffffffffffb8,(char)this->m_Ppm->_padding_,(char)param_3,
                          (char)iVar1);
    }
    lVar4 = (ulonglong)(byte)(param_1->field0_0x0).m_DataBlock.Control.AsUInt64 << 0x10;
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (lVar4,(this->m_ActiveCommandCtx).OpmCommand.OpmCmdSeqNum,
               (uint)(ushort)((short)(this->m_ActiveCommandCtx).OpmCommand.OpmCmdSeqNum -
                             (short)param_3) | (uint)lVar4,
               "OPM command completion with an unexpected OpmCmdSeqNum");
  }
  if (param_2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x1f,
                          &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                          (char)this->m_Ppm->_padding_,
                          (char)(param_1->field0_0x0).m_DataBlock.Control.AsUInt64,(char)param_2);
    }
    SetUnrecoverableFailureContext
              (this,CommandExecutionFailed,
               (param_2 != -0x3fffffff) + CommandCompletedWithErrorIndicator,param_2);
  }
  else {
    uVar2 = (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
    uVar3 = (param_1->field0_0x0).m_DataBlock.Control.AsUInt64;
    if (((uint)uVar3 & 0xff) == ((uint)uVar2 & 0xff)) {
      if ((param_1->field0_0x0).m_DataBlock.CCI._s_1.DataLength != 0) {
        UcsiDataBlock::PrettyPrintMessageIn
                  (this_00,(void *)this->m_Ppm->_padding_,(this->m_ActiveCommandCtx).Status);
      }
      this->m_CciDataLength = (uint)(param_1->field0_0x0).m_DataBlock.CCI._s_1.DataLength;
      uVar6 = 1;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x20,
                            &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                            (char)this->m_Ppm->_padding_,(char)uVar3,(char)uVar2);
      }
      if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
        RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0x198);
      }
      pOVar5 = this;
      SetUnrecoverableFailureContext(this,CommandExecutionFailed,CommandCompletedOutOfSync,0);
      MicrosoftTelemetryAssertTriggeredArgsMsgKM
                (pOVar5,(uint)(param_1->field0_0x0).m_DataBlock.Control.AsUInt64 & 0xff,
                 (uint)(this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.
                       Control.AsUInt64 & 0xff,"[OPM] Command completion out of sync");
    }
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,uVar6);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x21,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EvtLogEventEnqueue @ 14000af88 =====

/* private: void __cdecl UcmUcsiCx::Opm::EvtLogEventEnqueue(enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::EventId) __ptr64 */

void __thiscall UcmUcsiCx::Opm::EvtLogEventEnqueue(Opm *this,EventId param_1)

{
  EventId EVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined6 in_register_00000012;
  
  uVar3 = (undefined1)(param_1 >> 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    EVar1 = param_1;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      uVar2 = 5;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x10e,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
      EVar1 = CONCAT11(uVar3,uVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                        CONCAT62(in_register_00000012,EVar1),10,0x10f,
                        &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)param_1);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x110,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
      }
    }
  }
  return;
}



===== EvtLogEventEnqueueThunk @ 14000b060 =====

/* private: static void __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EvtLogEventEnqueueThunk(void * __ptr64,unsigned short) */

void __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EvtLogEventEnqueueThunk
          (void *param_1,ushort param_2)

{
  Opm::EvtLogEventEnqueue(param_1,param_2);
  return;
}



===== EvtLogMachineException @ 14000b078 =====

/* private: void __cdecl UcmUcsiCx::Opm::EvtLogMachineException(enum SmFx::MachineException,enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::EventId,enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::StateId) __ptr64 */

void __thiscall
UcmUcsiCx::Opm::EvtLogMachineException
          (Opm *this,MachineException param_1,EventId param_2,StateId param_3)

{
  undefined4 in_register_00000014;
  undefined8 uVar1;
  undefined6 in_register_00000082;
  undefined8 uVar2;
  char *pcVar3;
  
  uVar2 = CONCAT62(in_register_00000082,param_2);
  uVar1 = CONCAT44(in_register_00000014,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    this = (Opm *)WPP_GLOBAL_Control;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      this = *(Opm **)(WPP_GLOBAL_Control + 0x40);
      uVar2 = 10;
      uVar1 = CONCAT71((int7)((ulonglong)uVar1 >> 8),5);
      WPP_RECORDER_SF_(this,5,10,0x10b,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this = *(Opm **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_LLL(this,uVar1,uVar2,0x10c,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                          (char)param_1,(char)param_2,(char)(param_3 & 0xffff));
    }
  }
  if (param_1 == UnhandledEvent) {
    pcVar3 = "[OPM] SmFx Unhandled Event exception";
  }
  else if (param_1 == EventQueueOverflow) {
    pcVar3 = "[OPM] SmFx Event Queue Overflow exception";
  }
  else if (param_1 == StackOverflow) {
    pcVar3 = "[OPM] SmFx Stack Overflow exception";
  }
  else {
    pcVar3 = "[OPM] SmFx Unknown exception";
  }
  MicrosoftTelemetryAssertTriggeredArgsMsgKM(this,(uint)param_2,param_3 & 0xffff,pcVar3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x10d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EvtLogMachineExceptionThunk @ 14000b1a0 =====

/* private: static void __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EvtLogMachineExceptionThunk(void * __ptr64,enum SmFx::MachineException,unsigned
   short,unsigned short) */

void __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EvtLogMachineExceptionThunk
          (void *param_1,MachineException param_2,ushort param_3,ushort param_4)

{
  undefined2 in_register_0000008a;
  
  Opm::EvtLogMachineException(param_1,param_2,param_3,CONCAT22(in_register_0000008a,param_4));
  return;
}



===== EvtLogTransition @ 14000b1b8 =====

/* private: void __cdecl UcmUcsiCx::Opm::EvtLogTransition(enum SmFx::TransitionType,enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::StateId,enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::EventId,enum
   UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::StateId) __ptr64 */

void __thiscall
UcmUcsiCx::Opm::EvtLogTransition
          (Opm *this,TransitionType param_1,StateId param_2,EventId param_3,StateId param_4)

{
  TransitionType TVar1;
  undefined4 in_register_00000014;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    TVar1 = param_1;
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      TVar1 = CONCAT31((int3)(param_1 >> 8),5);
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x111,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_LLLL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,TVar1),10,
                 0x112,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)param_1,(char)param_2,
                 (char)param_3,(char)param_4);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x113,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
      }
    }
  }
  return;
}



===== EvtLogTransitionThunk @ 14000b2c0 =====

/* private: static void __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EvtLogTransitionThunk(void * __ptr64,enum SmFx::TransitionType,unsigned
   short,unsigned short,unsigned short) */

void __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EvtLogTransitionThunk
          (void *param_1,TransitionType param_2,ushort param_3,ushort param_4,ushort param_5)

{
  undefined2 in_register_0000008a;
  
  Opm::EvtLogTransition(param_1,param_2,param_3,CONCAT22(in_register_0000008a,param_4),param_5);
  return;
}



===== EvtMachineDestroyed @ 14000b2e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::EvtMachineDestroyed(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::EvtMachineDestroyed(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x114,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x670))
            (WdfDriverGlobals,this->m_Ppm->_padding_,0,0xc1f,
             "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp");
  this->m_Ppm = (Ppm *)0x0;
  KeSetEvent(&this->m_OpmStateMachineDestroyedEvent,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x115,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EvtMachineDestroyedThunk @ 14000b3e0 =====

/* private: static void __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EvtMachineDestroyedThunk(void * __ptr64) */

void __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EvtMachineDestroyedThunk(void *param_1)

{
  Opm::EvtMachineDestroyed(param_1);
  return;
}



===== EvtPpmConnectorContextCleanup @ 14000b400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl UcmUcsiCx::Opm::EvtPpmConnectorContextCleanup(void * __ptr64) */

void __cdecl UcmUcsiCx::Opm::EvtPpmConnectorContextCleanup(void *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x28,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,param_1,0);
  if (*(longlong *)(lVar1 + 0x20) != 0) {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01023 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(lVar1 + 0x20),
                        PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0);
    *puVar2 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x29,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ExecuteTestUcsiCommandEntry @ 14000b4f0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ExecuteTestUcsiCommandEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ExecuteTestUcsiCommandEntry
          (void *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  Opm::EnableCommandHandlerAutoAck(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf0,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  *(bool *)((longlong)param_1 + 0x7e4) = *(int *)(*(longlong *)((longlong)param_1 + 8) + 0xd24) == 1
  ;
  (((UcsiDataBlock *)((longlong)param_1 + 0x5d4))->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 =
       *(ushort *)(*(longlong *)((longlong)param_1 + 8) + 0xd30);
  UcsiDataBlock::CopyUcsiControlAndMessageOutFrom
            ((UcsiDataBlock *)((longlong)param_1 + 0x5d4),
             (UcsiDataBlock *)((longlong)param_1 + 0xa0c));
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x5c8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined1 *)((longlong)param_1 + 0x7ec) = 1;
  *(int *)((longlong)param_1 + 0x7e8) = iVar2 + 1;
  ((UCMUCSI_OPM_COMMAND *)((longlong)param_1 + 0x5d0))->ExecType =
       (uint)(*(char *)((longlong)param_1 + 0xa14) == '\x01');
  bVar3 = CommandHandler::SendUcsiCommand
                    ((CommandHandler *)((longlong)param_1 + 0x10),
                     (UCMUCSI_OPM_COMMAND *)((longlong)param_1 + 0x5d0));
  if (!bVar3) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xcd,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)**(undefined8 **)((longlong)param_1 + 8),
                         (char)*(undefined4 *)((longlong)param_1 + 0xa14));
    }
    SmFx::StateMachineEngine::EnqueueEvent(param_1,8);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf1,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== FailedEntry @ 14000b670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::FailedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::FailedEntry(void *param_1)

{
  UnrecoverableFailureContext local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x106,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (**(code **)(WdfFunctions_01023 + 0x9e0))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0xce0));
  local_28.Type = *(LkdFailureType *)((longlong)param_1 + 0xce8);
  local_28.SubType = *(LkdFailureSubType *)((longlong)param_1 + 0xcec);
  local_28.UcsiCommandInOpm = *(_UCSI_COMMAND *)((longlong)param_1 + 0xcf0);
  local_28.UcsiCommandForPpm = *(_UCSI_COMMAND *)((longlong)param_1 + 0xcf4);
  local_28._16_8_ = *(undefined8 *)((longlong)param_1 + 0xcf8);
  (**(code **)(WdfFunctions_01023 + 0x9e8))
            (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0xce0));
  if ((((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (local_28.Type != TestSimulatedFailure)) &&
     (1 < local_28.Type - CommandExecutionFailed)) {
    RtlAssert("failureContextCopy.Type == LkdFailureType::TestSimulatedFailure || failureContextCopy.Type == LkdFailureType::IncorrectConnectorNumber || failureContextCopy.Type == LkdFailureType::CommandExecutionFailed"
              ,"onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0xbb2,0);
  }
  CxDevice::UnrecoverableFailureEncountered
            (*(CxDevice **)(*(longlong *)((longlong)param_1 + 8) + 0xd38),&local_28);
  SmFx::StateMachineEngine::EnqueueEvent(param_1,0x11);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x107,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetAlternateModesEntry @ 14000b7e0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetAlternateModesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetAlternateModesEntry
          (void *param_1)

{
  _PPM_CONNECTOR *p_Var1;
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd2,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = Opm::GetConnector(param_1,*(ulong *)((longlong)param_1 + 0xc54));
  local_res8.AsUInt64 =
       ((ulonglong)(p_Var1->NumAltModes & 0xff) << 8 | (ulonglong)(p_Var1->Index & 0x7f)) << 0x18 |
       0x1000000000c;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd3,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetConnector @ 14000b8d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: struct UcmUcsiCx::_PPM_CONNECTOR * __ptr64 __cdecl UcmUcsiCx::Opm::GetConnector(unsigned
   long) __ptr64 */

_PPM_CONNECTOR * __thiscall UcmUcsiCx::Opm::GetConnector(Opm *this,ulong param_1)

{
  longlong lVar1;
  _PPM_CONNECTOR *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x26,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  lVar1 = (**(code **)(WdfFunctions_01023 + 0x90))(WdfDriverGlobals,this->m_Connectors,param_1 - 1);
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (lVar1 == 0)) {
    RtlAssert("connectorMem != nullptr","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",
              0x206,0);
  }
  p_Var2 = (_PPM_CONNECTOR *)(**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,lVar1,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x27,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return p_Var2;
}



===== GetConnectorCapabilitiesEntry @ 14000ba10 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetConnectorCapabilitiesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetConnectorCapabilitiesEntry
          (void *param_1)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd6,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 = (ulonglong)(*(uint *)((longlong)param_1 + 0xc54) & 0x7f) << 0x10 | 7;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd7,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetConnectorStatusOnPowerUpEntry @ 14000bae0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetConnectorStatusOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetConnectorStatusOnPowerUpEntry
          (void *param_1)

{
  Opm::SendGetConnectorStatusCommand(param_1);
  return 0;
}



===== GetErrorStatusEntry @ 14000bb00 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetErrorStatusEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetErrorStatusEntry
          (void *param_1)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xde,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 = 0x13;
  if ((*(int *)(*(longlong *)((longlong)param_1 + 8) + 0xd24) == 1) &&
     (1 < *(byte *)(*(longlong *)((longlong)param_1 + 8) + 0xd21))) {
    local_res8.AsUInt64 = (ulonglong)(*(uint *)((longlong)param_1 + 0xc54) & 0x7f) << 0x10 | 0x13;
  }
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xdf,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetPartnerAlternateModesEntry @ 14000bbf0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetPartnerAlternateModesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetPartnerAlternateModesEntry
          (void *param_1)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd4,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 =
       (ulonglong)(*(uint *)((longlong)param_1 + 0xc54) & 0x7f) << 0x18 | 0x1000001000c;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd5,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetPpmCapabilityEntry @ 14000bcd0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetPpmCapabilityEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetPpmCapabilityEntry
          (void *param_1)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xdc,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 = 6;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xdd,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== GetSourcePDOsEntry @ 14000bd90 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::GetSourcePDOsEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::GetSourcePDOsEntry
          (void *param_1)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x52,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  *(undefined4 *)((longlong)param_1 + 0xc30) = *(undefined4 *)((longlong)param_1 + 0xc5c);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x53,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4d,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
  }
  iVar2 = 3;
  bVar3 = *(byte *)((longlong)param_1 + 0xc60) & 3;
  if ((*(byte *)((longlong)param_1 + 0xc60) & 3) == 0) {
    iVar2 = 1;
LAB_14000bec6:
    *(int *)((longlong)param_1 + 0xc2c) = iVar2;
    if (iVar2 == 1) {
      bVar1 = Opm::ShouldIgnoreBatteryNotChargingStatus(param_1);
      if ((bVar1) || ((*(ushort *)((longlong)param_1 + 0xc58) & 0x200) == 0)) {
        *(undefined4 *)((longlong)param_1 + 0xc2c) = 0;
      }
    }
  }
  else {
    if (bVar3 == 1) {
      iVar2 = 2;
      goto LAB_14000bec6;
    }
    if (bVar3 == 2) goto LAB_14000bec6;
    if (bVar3 == 3) {
      iVar2 = 4;
      goto LAB_14000bec6;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000bf4f;
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x4e,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                       (char)**(undefined8 **)((longlong)param_1 + 8),bVar3);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x4f,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xda,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
  }
LAB_14000bf4f:
  local_res8.AsUInt64 =
       (((ulonglong)((ushort)~*(ushort *)((longlong)param_1 + 0xc5a) & 0x10) |
        (ulonglong)*(byte *)((longlong)param_1 + 0xc50) << 5) << 3 |
       (ulonglong)(*(uint *)((longlong)param_1 + 0xc54) & 0x7f)) << 0x10 | 0x700000010;
  *(ushort *)((longlong)param_1 + 0xc58) = *(ushort *)((longlong)param_1 + 0xc58) & 0xfdbf;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xdb,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== HandleNotificationEntry @ 14000c000 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::HandleNotificationEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::HandleNotificationEntry
          (void *param_1)

{
  Opm::DisableCommandHandlerAutoAck(param_1);
  return 0;
}



===== NotifyPowerDownCompleteEntry @ 14000c020 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::NotifyPowerDownCompleteEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::NotifyPowerDownCompleteEntry
          (void *param_1)

{
  Opm::NotifyPowerDownComplete(param_1);
  return 6;
}



===== NotifyPowerUpCompleteOnFailureEntry @ 14000c040 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::NotifyPowerUpCompleteOnFailureEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
NotifyPowerUpCompleteOnFailureEntry(void *param_1)

{
  Opm::NotifyPowerUpComplete(param_1);
  return 6;
}



===== HasMoreConnectors @ 14000c05c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::HasMoreConnectors(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::HasMoreConnectors(Opm *this)

{
  uint uVar1;
  uint uVar2;
  Event EVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x61,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,this->m_Connectors);
  EVar3 = Yes;
  uVar2 = this->m_CurrentConnectorNumber + 1;
  if (uVar1 <= this->m_CurrentConnectorNumber) {
    EVar3 = No;
    uVar2 = 1;
  }
  this->m_CurrentConnectorNumber = uVar2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x62,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar3;
}



===== Initialize @ 14000c148 =====

/* public: long __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::Initialize(struct UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::StateMachineEngineConfig const & __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::Initialize
          (OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *this,StateMachineEngineConfig *param_1)

{
  long lVar1;
  STATE_MACHINE_ENGINE_CONFIG local_58;
  
  local_58._28_4_ = 0;
  local_58._66_4_ = 0;
  local_58._70_2_ = 0;
  local_58.machineSpec = &c_specification;
  local_58.poolTag = *(uint *)(param_1 + 8);
  local_58.deviceObject = *(_DEVICE_OBJECT **)param_1;
  local_58.logExceptionCallback = EvtLogMachineExceptionThunk;
  local_58.logEventEnqueueCallback = EvtLogEventEnqueueThunk;
  local_58.logTransitionCallback = EvtLogTransitionThunk;
  local_58.machineDestroyedCallback = EvtMachineDestroyedThunk;
  local_58.isWorkerRequired = true;
  local_58.stackSize = '\t';
  local_58.context = this;
  lVar1 = SmFx::StateMachineEngine::Initialize(&this->m_engine,&local_58);
  return lVar1;
}



===== IsPowerOperationModePD @ 14000c1c4 =====

/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::IsPowerOperationModePD(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::IsPowerOperationModePD(Opm *this)

{
  Event EVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x79,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  EVar1 = Yes;
  if ((this->field26_0xc58).field1_0x2.PowerOperationMode != 3) {
    EVar1 = No;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x7a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar1;
}



===== IsPpmCapabilityValid @ 14000c278 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::IsPpmCapabilityValid(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::IsPpmCapabilityValid(Opm *this)

{
  ushort uVar1;
  WDFCOLLECTION__ *pWVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  ushort uVar8;
  ulonglong uVar9;
  Event EVar10;
  undefined8 in_R8;
  bool bVar11;
  bool bVar12;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    in_R8 = 10;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x7b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if ((*(uint *)(WdfDriverGlobals + 8) & 4) == 0) {
LAB_14000c312:
    if (this->m_CciDataLength != 0x10) {
      EVar10 = No;
      goto LAB_14000c4a4;
    }
  }
  else if (this->m_CciDataLength != 0x10) {
    in_R8 = 0x5d3;
    RtlAssert("m_CciDataLength == sizeof(UCSI_GET_CAPABILITY_IN)",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0x5d3,0);
    goto LAB_14000c312;
  }
  uVar3 = *(undefined4 *)
           ((this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn + 4);
  uVar4 = *(undefined4 *)
           ((this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn + 8);
  uVar5 = *(undefined4 *)
           ((this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn + 0xc);
  pWVar2 = this->m_Connectors;
  (this->m_PpmCapabilities).bmAttributes.AsUInt32 =
       *(uint *)(this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
  *(undefined4 *)&(this->m_PpmCapabilities).field_0x4 = uVar3;
  *(undefined4 *)&(this->m_PpmCapabilities).field2_0x5._s_3.bNumAltModes = uVar4;
  (this->m_PpmCapabilities).bcdPdVersion = (short)uVar5;
  (this->m_PpmCapabilities).bcdUsbTypeCVersion = (short)((uint)uVar5 >> 0x10);
  uVar7 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,pWVar2);
  if (((this->m_PpmCapabilities).bNumConnectors != uVar7) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar6 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,this->m_Connectors);
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_R8,0x7c,
                        in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,
                        (this->m_PpmCapabilities).bNumConnectors,uVar6);
  }
  EVar10 = Yes;
  uVar1 = (this->m_Ppm->m_UcsiVersion).AsUInt16;
  uVar6 = (undefined1)(uVar1 >> 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x7d,
                        in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,uVar6,
                        (byte)(uVar1 >> 4) & 0xf);
  }
  uVar8 = uVar1 >> 8;
  uVar9 = (ulonglong)uVar8;
  if (uVar8 != 0) {
    if (uVar8 == 1) {
      if ((uVar1 & 0xf0) < 0x21) goto LAB_14000c4a4;
    }
    else {
      bVar11 = uVar8 < 2;
      bVar12 = false;
      if (uVar8 == 2) {
        if (0x10 < (uVar1 & 0xf0)) goto LAB_14000c44e;
        bVar11 = false;
        bVar12 = true;
      }
      if (bVar11 || bVar12) goto LAB_14000c4a4;
    }
  }
LAB_14000c44e:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = *(ulonglong *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_qDD(uVar9,3,in_R8,0x7e,in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,
                        uVar6,(byte)(uVar1 >> 4) & 0xf);
  }
  MicrosoftTelemetryAssertTriggeredArgsMsgKM(uVar9,(uint)uVar1,0x210,"Unexpected UCSI PPM version");
LAB_14000c4a4:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x7f,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar10;
}



===== IsStatusConnected @ 14000c4f8 =====

/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::IsStatusConnected(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::IsStatusConnected(Opm *this)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x82,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x83,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return (-(ushort)((this->field26_0xc58).field1_0x2.ConnectStatus != 0) & 0xb) + No;
}



===== NotifyPowerDownComplete @ 14000c5ac =====

/* private: void __cdecl UcmUcsiCx::Opm::NotifyPowerDownComplete(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::NotifyPowerDownComplete(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x84,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  Ppm::EvtPowerOffComplete(this->m_Ppm);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x85,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== NotifyPowerUpComplete @ 14000c650 =====

/* private: void __cdecl UcmUcsiCx::Opm::NotifyPowerUpComplete(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::NotifyPowerUpComplete(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x86,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  Ppm::EvtPowerOnComplete(this->m_Ppm);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x87,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== NotifyTestUcsiCommandCompleteEntry @ 14000c700 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::NotifyTestUcsiCommandCompleteEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
NotifyTestUcsiCommandCompleteEntry(void *param_1)

{
  Opm::NotifyTestUcsiCommandComplete(param_1);
  return 6;
}



===== PerformRoleCorrectionEntry @ 14000c720 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::PerformRoleCorrectionEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::PerformRoleCorrectionEntry
          (void *param_1)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xce,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 = (ulonglong)(*(uint *)((longlong)param_1 + 0xc54) & 0x7f) << 0x10 | 0x800009;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xcf,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== PowerDownAndWaitForPowerUpEntry @ 14000c7f0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::PowerDownAndWaitForPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::PowerDownAndWaitForPowerUpEntry
          (void *param_1)

{
  Opm::EnableCommandHandlerAutoAck(param_1);
  return 0;
}



===== PpmNotificationReceived @ 14000c808 =====

/* public: void __cdecl UcmUcsiCx::Opm::PpmNotificationReceived(class UcmUcsiCx::UcsiDataBlock &
   __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::Opm::PpmNotificationReceived(Opm *this,UcsiDataBlock *param_1)

{
  int iVar1;
  undefined8 in_R8;
  bool bVar2;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffd8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x18,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 & 0xfe) != 0) {
    LOCK();
    iVar1 = (this->m_ConnectorChangeCtx).InProgress;
    (this->m_ConnectorChangeCtx).InProgress = 1;
    UNLOCK();
    if (iVar1 == 0) {
      LOCK();
      bVar2 = this->m_ConnectorChangeNotificationsEnabled == 0;
      if (bVar2) {
        this->m_ConnectorChangeNotificationsEnabled = 0;
      }
      UNLOCK();
      if (bVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x1a,
                             &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                             (char)this->m_Ppm->_padding_,
                             (byte)((param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 >> 1) & 0x7f);
        }
        LOCK();
        (this->m_ConnectorChangeCtx).InProgress = 0;
        UNLOCK();
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x1b,
                             &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                             (char)this->m_Ppm->_padding_,
                             (byte)((param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 >> 1) & 0x7f);
        }
        this->m_CurrentConnectorNumber = (param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 >> 1 & 0x7f;
        SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,4);
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,in_R8,0x19,
                          in_stack_ffffffffffffffd8,(char)this->m_Ppm->_padding_,
                          (byte)((param_1->field0_0x0).m_DataBlock.CCI.AsUInt32 >> 1) & 0x7f,
                          (char)this->m_CurrentConnectorNumber);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x1c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== PrepareAlternateModeMemoryEntry @ 14000c9d0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::PrepareAlternateModeMemoryEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::PrepareAlternateModeMemoryEntry
          (void *param_1)

{
  Event EVar1;
  
  EVar1 = Opm::AreAlternateModesPresent(param_1);
  return EVar1;
}



===== ReportAltModesEntry @ 14000c9f0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportAltModesEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportAltModesEntry
          (void *param_1)

{
  Opm::ReportAltModesToUCM(param_1);
  return 6;
}



===== ReportBatteryStatusChangeEntry @ 14000ca10 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportBatteryStatusChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportBatteryStatusChangeEntry
          (void *param_1)

{
  Opm::ReportBatteryStatusChangeToUCM(param_1);
  return 6;
}



===== ReportConnectorToUcmEntry @ 14000ca30 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportConnectorToUcmEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportConnectorToUcmEntry
          (void *param_1)

{
  Opm::ReportConnectorToUCM(param_1);
  return 6;
}



===== ReportDataDirectionOnPowerUpEntry @ 14000ca50 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportDataDirectionOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ReportDataDirectionOnPowerUpEntry(void *param_1)

{
  Opm::ReportDataDirectionChangeToUCMOnConnectorChange(param_1);
  return 6;
}



===== ReportDataRoleChangeAfterPowerLevelChangeEntry @ 14000ca70 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportDataRoleChangeAfterPowerLevelChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ReportDataRoleChangeAfterPowerLevelChangeEntry(void *param_1)

{
  Opm::ReportDataDirectionChangeToUCM(param_1);
  return 6;
}



===== ReportEndOfConnectorCreationEntry @ 14000ca90 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportEndOfConnectorCreationEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ReportEndOfConnectorCreationEntry(void *param_1)

{
  Opm::ReportEndOfConnectorCreations(param_1);
  return 6;
}



===== ReportOvercurrentEntry @ 14000cab0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportOvercurrentEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportOvercurrentEntry
          (void *param_1)

{
  Opm::ReportOvercurrentToUCM(param_1);
  return 6;
}



===== ReportPDSourceCapsEntry @ 14000cad0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportPDSourceCapsEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportPDSourceCapsEntry
          (void *param_1)

{
  Opm::ReportPDSourceCapsToUCM(param_1);
  return 6;
}



===== ReportPowerDirectionChangeEntry @ 14000caf0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportPowerDirectionChangeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportPowerDirectionChangeEntry
          (void *param_1)

{
  Opm::ReportPowerDirectionChangeToUCMOnConnectorChange(param_1);
  return 6;
}



===== ReportPowerDirectionChangedEntry @ 14000cb10 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportPowerDirectionChangedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportPowerDirectionChangedEntry
          (void *param_1)

{
  Opm::ReportPowerDirectionChangeToUCM(param_1);
  return 6;
}



===== ReportPowerDirectionChangedOnAttachEntry @ 14000cb30 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportPowerDirectionChangedOnAttachEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ReportPowerDirectionChangedOnAttachEntry(void *param_1)

{
  Opm::ReportPowerDirectionChangeToUCMOnAttach(param_1);
  return 6;
}



===== ReportRDOEntry @ 14000cb50 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportRDOEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportRDOEntry(void *param_1)

{
  Opm::ReportRDOToUCM(param_1);
  return 6;
}



===== ReportSetPowerLevelCompletionEntry @ 14000cb70 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportSetPowerLevelCompletionEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ReportSetPowerLevelCompletionEntry(void *param_1)

{
  Opm::ReportSetPowerLevelCompletionToUCM(param_1);
  return 6;
}



===== ReportTypeCAttachEntry @ 14000cb90 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCAttachEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCAttachEntry
          (void *param_1)

{
  Opm::ReportTypeCAttachToUCM(param_1);
  return 6;
}



===== ReportTypeCCurrentAdChangedEntry @ 14000cbb0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCCurrentAdChangedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCCurrentAdChangedEntry
          (void *param_1)

{
  Opm::ReportTypeCCurrentAdChangedToUCM(param_1);
  return 6;
}



===== ReportTypeCDetachEntry @ 14000cbd0 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCDetachEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCDetachEntry
          (void *param_1)

{
  Opm::ReportTypeCDetachToUCM(param_1);
  Opm::AckCommandAndConnectorChange(param_1);
  return 6;
}



===== ReportTypeCDetachOnPowerUpEntry @ 14000cc00 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCDetachOnPowerUpEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::ReportTypeCDetachOnPowerUpEntry
          (void *param_1)

{
  Opm::ReportTypeCDetachToUCM(param_1);
  return 6;
}



===== SendCommandAndConnectorChangeAckEntry @ 14000cc20 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendCommandAndConnectorChangeAckEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
SendCommandAndConnectorChangeAckEntry(void *param_1)

{
  Opm::AckCommandAndConnectorChange(param_1);
  return 6;
}



===== SendDRSwapEntry @ 14000cc40 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendDRSwapEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::SendDRSwapEntry(void *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  _UCSI_CONTROL local_res8;
  
  Opm::EnableCommandHandlerAutoAck(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe6,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  lVar2 = *(longlong *)((longlong)param_1 + 0xc70);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0xe7,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                       (char)**(undefined8 **)((longlong)param_1 + 8),
                       (char)*(undefined4 *)((longlong)param_1 + 0xc78));
  }
  iVar1 = *(int *)((longlong)param_1 + 0xc78);
  if (iVar1 == 1) {
    uVar3 = 0x80;
  }
  else {
    if (iVar1 != 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xe8,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)**(undefined8 **)((longlong)param_1 + 8),(char)iVar1);
      }
      SmFx::StateMachineEngine::EnqueueEvent(param_1,8);
      goto LAB_14000cd6f;
    }
    uVar3 = 0x100;
  }
  local_res8.AsUInt64 = (*(uint *)(lVar2 + 0x18) & 0x7f | uVar3) << 0x10 | 9;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
LAB_14000cd6f:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe9,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== SendEnableCommandCompletionNotification @ 14000cdc0 =====

/* private: void __cdecl UcmUcsiCx::Opm::SendEnableCommandCompletionNotification(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::SendEnableCommandCompletionNotification(Opm *this)

{
  _UCSI_CONTROL local_res10;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd0,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res10.AsUInt64 = 0x10005;
  EnqueueCommandInCommandHandler(this,&local_res10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd1,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendGetConnectorStatusCommand @ 14000ce80 =====

/* private: void __cdecl UcmUcsiCx::Opm::SendGetConnectorStatusCommand(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::SendGetConnectorStatusCommand(Opm *this)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd8,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 = 0;
  (this->field26_0xc58).m_ConnectorStatus.field1_0x2._s_0 =
       (_UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0)0x0;
  (this->field26_0xc58).m_ConnectorStatus.RequestDataObject = 0;
  (this->field26_0xc58).m_ConnectorStatus.field3_0x8._s_0 =
       (_UCSI_GET_CONNECTOR_STATUS_IN_u_8_s_0)0x0;
  local_res8.AsUInt64 = (ulonglong)(this->m_CurrentConnectorNumber & 0x7f) << 0x10 | 0x12;
  EnqueueCommandInCommandHandler(this,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xd9,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendPpmResetWhilePowerResumeEntry @ 14000cf50 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendPpmResetWhilePowerResumeEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
SendPpmResetWhilePowerResumeEntry(void *param_1)

{
  Opm::SendResetCommandAndGetResponse(param_1);
  return 0;
}



===== SendResetCommandAndGetResponse @ 14000cf68 =====

/* private: void __cdecl UcmUcsiCx::Opm::SendResetCommandAndGetResponse(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::SendResetCommandAndGetResponse(Opm *this)

{
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe0,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res8.AsUInt64 = 1;
  LOCK();
  this->m_ConnectorChangeNotificationsEnabled = 0;
  UNLOCK();
  EnqueueCommandInCommandHandler(this,&local_res8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe1,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendSetPowerLevelCommand @ 14000d02c =====

/* private: void __cdecl UcmUcsiCx::Opm::SendSetPowerLevelCommand(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::SendSetPowerLevelCommand(Opm *this)

{
  uchar uVar1;
  _UCM_POWER_ROLE _Var2;
  _UCM_SET_POWER_LEVEL_PARAMS_FORMAT _Var3;
  _UCM_UCSI_SET_POWER_LEVEL_C_CURRENT _Var4;
  uint uVar5;
  _PPM_CONNECTOR *p_Var6;
  ulonglong uVar7;
  _UCSI_CONTROL local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xea,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var6 = (this->m_UcmConnectorCallbackInfo).PpmConnector;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0xeb,
                      &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_)
    ;
  }
  _Var2 = (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.PowerRole;
  if (_Var2 == UcmPowerRoleSink) {
    uVar7 = 0;
  }
  else {
    if (_Var2 != UcmPowerRoleSource) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xec,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)this->m_Ppm->_padding_,(char)_Var2);
      }
      SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,8);
      goto LAB_14000d210;
    }
    uVar7 = 0x80;
  }
  _Var3 = (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Format;
  if (_Var3 == UcmSetPowerLevelParamsFormatUcsi) {
    _Var4 = (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.field3_0xc.Ucsi.
            MaximumTypeCCurrent;
    if ((int)_Var4 < 4) {
      uVar1 = (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.field3_0xc.Ucsi.
              MaximumPdPowerIn500mW;
      uVar5 = p_Var6->Index;
      (this->m_ActiveCommandCtx).Status = -0x3ffffee0;
      local_res8.AsUInt64 =
           ((ulonglong)(CONCAT41(_Var4,uVar1) & 0x3ff) << 8 | (ulonglong)(uVar5 & 0x7f) | uVar7) <<
           0x10 | 0x14;
      EnqueueCommandInCommandHandler(this,&local_res8);
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,10,0xee,
                          &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                          (char)this->m_Ppm->_padding_,(char)_Var4,0xd);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xed,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)_Var3);
  }
LAB_14000d210:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xef,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendSetPowerLevelEntry @ 14000d260 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendSetPowerLevelEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::SendSetPowerLevelEntry
          (void *param_1)

{
  Opm::EnableCommandHandlerAutoAck(param_1);
  Opm::SendSetPowerLevelCommand(param_1);
  return 0;
}



===== SendSetPowerRoleEntry @ 14000d290 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::SendSetPowerRoleEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::SendSetPowerRoleEntry
          (void *param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  _UCSI_CONTROL local_res8;
  
  Opm::EnableCommandHandlerAutoAck(param_1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe2,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  lVar2 = *(longlong *)((longlong)param_1 + 0xc70);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0xe3,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                       (char)**(undefined8 **)((longlong)param_1 + 8),
                       (char)*(undefined4 *)((longlong)param_1 + 0xc7c));
  }
  iVar1 = *(int *)((longlong)param_1 + 0xc7c);
  if (iVar1 == 1) {
    uVar3 = 0x100;
  }
  else {
    if (iVar1 != 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xe4,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)**(undefined8 **)((longlong)param_1 + 8),(char)iVar1);
      }
      SmFx::StateMachineEngine::EnqueueEvent(param_1,8);
      goto LAB_14000d3bf;
    }
    uVar3 = 0x80;
  }
  local_res8.AsUInt64 = (*(uint *)(lVar2 + 0x18) & 0x7f | uVar3) << 0x10 | 0xb;
  Opm::EnqueueCommandInCommandHandler(param_1,&local_res8);
LAB_14000d3bf:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xe5,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== SetUnrecoverableFailureContext @ 14000d410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::Opm::SetUnrecoverableFailureContext(enum
   UcmUcsiCx::LkdFailureType,enum UcmUcsiCx::LkdFailureSubType,long) __ptr64 */

void __thiscall
UcmUcsiCx::Opm::SetUnrecoverableFailureContext
          (Opm *this,LkdFailureType param_1,LkdFailureSubType param_2,long param_3)

{
  WDFSPINLOCK__ *pWVar1;
  _UCSI_COMMAND _Var2;
  
  if ((((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_1 != TestSimulatedFailure)) &&
     (1 < param_1 - CommandExecutionFailed)) {
    RtlAssert("Type == LkdFailureType::TestSimulatedFailure || Type == LkdFailureType::IncorrectConnectorNumber || Type == LkdFailureType::CommandExecutionFailed"
              ,"onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",300,0);
  }
  (**(code **)(WdfFunctions_01023 + 0x9e0))
            (WdfDriverGlobals,this->m_UnrecoverableFailureContextLock);
  (this->m_UnrecoverableFailureContext).Type = param_1;
  (this->m_UnrecoverableFailureContext).SubType = param_2;
  (this->m_UnrecoverableFailureContext).Status = param_3;
  if (param_1 == CommandExecutionFailed) {
    (this->m_UnrecoverableFailureContext).UcsiCommandInOpm =
         (_UCSI_COMMAND)
         (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64 &
         0xff;
    if ((((this->m_CommandHandler).m_Ppm)->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
      _Var2 = (_UCSI_COMMAND)
              (((this->m_CommandHandler).m_InSendExParam)->DataBlockHeader).Control.AsUInt64;
    }
    else {
      _Var2 = (_UCSI_COMMAND)
              (this->m_CommandHandler).m_InBuffer.m_InSendParam.UcmUcsiDataBlock.Control.AsUInt64;
    }
    _Var2 = _Var2 & 0xff;
  }
  else {
    _Var2 = 0;
    (this->m_UnrecoverableFailureContext).UcsiCommandInOpm = 0;
  }
  (this->m_UnrecoverableFailureContext).UcsiCommandForPpm = _Var2;
  pWVar1 = this->m_UnrecoverableFailureContextLock;
  (this->m_UnrecoverableFailureContext).ConnectorNumber = (uchar)this->m_CurrentConnectorNumber;
  (**(code **)(WdfFunctions_01023 + 0x9e8))(WdfDriverGlobals,pWVar1);
  return;
}



===== ShouldCheckForMorePdos @ 14000d534 =====

/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::ShouldCheckForMorePdos(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::ShouldCheckForMorePdos(Opm *this)

{
  ulonglong uVar1;
  _PPM_CONNECTOR *p_Var2;
  ulonglong uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined8 in_R8;
  ulonglong uVar7;
  undefined2 uVar8;
  Event EVar9;
  undefined *in_stack_ffffffffffffffa8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffa8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf5,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  EVar9 = No;
  uVar1 = *(ulonglong *)((longlong)&(this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0 + 8);
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && ((char)uVar1 != '\x10')) {
    in_R8 = 0xae4;
    RtlAssert("lastUcsiControl.Command == UcsiCommandGetPdos",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0xae4,0);
  }
  uVar6 = this->m_CciDataLength >> 2;
  p_Var2 = GetConnector(this,this->m_CurrentConnectorNumber);
  bVar5 = (byte)uVar6;
  if (bVar5 == 0) {
    if ((uVar1 >> 0x17 & 1) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return No;
      }
      uVar8 = 0xf7;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return No;
      }
      uVar8 = 0xf6;
    }
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_R8,uVar8,
                       in_stack_ffffffffffffffa8,(char)this->m_Ppm->_padding_,(char)p_Var2->Id);
    goto LAB_14000d6de;
  }
  if ((*(uint *)(WdfDriverGlobals + 8) & 4) == 0) {
    if (bVar5 < 5) goto LAB_14000d744;
  }
  else if (bVar5 < 5) {
LAB_14000d744:
    uVar3 = uVar1 >> 0x18 & 0xff;
    uVar7 = (ulonglong)(uVar6 & 0xff);
    if (uVar3 + uVar7 < 7) {
      memmove((this->m_ConnectorChangeCtx).Pdos + uVar3,
              &(this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlock.MessageIn,uVar7 << 2
             );
      bVar4 = (char)(uVar1 >> 0x18) + bVar5;
      (this->m_ConnectorChangeCtx).PdoCount = bVar4;
      if ((bVar5 == 4) && (bVar4 < 7)) {
        EVar9 = Yes;
      }
      goto LAB_14000d6de;
    }
  }
  else {
    RtlAssert("pdoCount <= 4","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0xafc,0);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return No;
  }
  WPP_RECORDER_SF_qDDLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
LAB_14000d6de:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xf9,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar9;
}



===== ShouldCheckIfMoreAltModeArePresent @ 14000d7a4 =====

/* private: enum UcmUcsiCx::OsPolicyManagerStateMachine<class UcmUcsiCx::Opm>::Event __cdecl
   UcmUcsiCx::Opm::ShouldCheckIfMoreAltModeArePresent(void) __ptr64 */

Event __thiscall UcmUcsiCx::Opm::ShouldCheckIfMoreAltModeArePresent(Opm *this)

{
  byte bVar1;
  uint uVar2;
  _PPM_CONNECTOR *p_Var3;
  uint uVar4;
  Event EVar5;
  undefined8 in_R8;
  uchar *puVar6;
  ulonglong uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xfa,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar7 = (ulonglong)this->m_CurrentConnectorNumber;
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar2 = this->m_CciDataLength;
  if (uVar2 != 0) {
    if (uVar2 == 6) {
      uVar2 = 1;
    }
    else {
      if (uVar2 != 0xc) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,in_R8,0xfb,
                             in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)uVar2);
        }
        Verify::Break();
        goto LAB_14000d927;
      }
      uVar2 = 2;
    }
    uVar4 = p_Var3->NumAltModes;
    bVar1 = (this->m_PpmCapabilities).field2_0x5._s_3.bNumAltModes;
    if ((uint)bVar1 < uVar4 + uVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,10,0xfc,
                   &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_,
                   (char)p_Var3->Index,(char)(uVar4 + uVar2),bVar1);
      }
      Verify::Break();
      uVar4 = p_Var3->NumAltModes;
      uVar2 = (this->m_PpmCapabilities).field2_0x5._s_3.bNumAltModes - uVar4;
    }
    if (uVar2 != 0) {
      uVar7 = (ulonglong)uVar2;
      puVar6 = (this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlockEx.MessageIn;
      do {
        p_Var3->AltModes[uVar4].SVID = *(ushort *)puVar6;
        p_Var3->AltModes[p_Var3->NumAltModes].Mode = *(uint *)(puVar6 + 2);
        uVar4 = p_Var3->NumAltModes + 1;
        p_Var3->NumAltModes = uVar4;
        uVar7 = uVar7 - 1;
        puVar6 = puVar6 + 6;
      } while (uVar7 != 0);
    }
    if (uVar4 != (this->m_PpmCapabilities).field2_0x5._s_3.bNumAltModes) {
      EVar5 = Yes;
      goto LAB_14000d92c;
    }
  }
LAB_14000d927:
  EVar5 = No;
LAB_14000d92c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xfd,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return EVar5;
}



===== StartCommandHandlerMachineEntry @ 14000d990 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::StartCommandHandlerMachineEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::StartCommandHandlerMachineEntry
          (void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x102,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x18,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x18) == '\0') {
    SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)((longlong)param_1 + 0x10),0xf);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x19,
                        &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                        (char)**(undefined8 **)((longlong)param_1 + 0x20));
    }
    Verify::Break();
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1a,
                       &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x103,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
  }
  return 6;
}



===== StartPowerDown @ 14000daf8 =====

/* public: void __cdecl UcmUcsiCx::Opm::StartPowerDown(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::StartPowerDown(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x40,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x41,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== StartPowerUp @ 14000dba0 =====

/* public: void __cdecl UcmUcsiCx::Opm::StartPowerUp(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::StartPowerUp(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x42,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  SmFx::StateMachineEngine::EnqueueEvent((StateMachineEngine *)this,0xb);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x43,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== StopCommandHandlerMachineEntry @ 14000dc50 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::StopCommandHandlerMachineEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::StopCommandHandlerMachineEntry
          (void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x104,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (*(char *)((longlong)param_1 + 0x18) != '\0') {
    CommandHandler::Stop((CommandHandler *)((longlong)param_1 + 0x10));
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x105,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== StoppedEntry @ 14000dd10 =====

/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::StoppedEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::StoppedEntry(void *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x100,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  KeSetEvent((longlong)param_1 + 0xcb0,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x101,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return 0;
}



===== ValidatingConnectorChangeNotificationEntry @ 14000dde0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static unsigned short __cdecl UcmUcsiCx::OsPolicyManagerStateMachine<class
   UcmUcsiCx::Opm>::EntryFuncs::ValidatingConnectorChangeNotificationEntry(void * __ptr64) */

ushort __cdecl
UcmUcsiCx::OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EntryFuncs::
ValidatingConnectorChangeNotificationEntry(void *param_1)

{
  uint uVar1;
  _PPM_CONNECTOR *p_Var2;
  ushort uVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x108,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar3 = 0x12;
  if (*(int *)((longlong)param_1 + 0xc54) != 0) {
    uVar1 = (**(code **)(WdfFunctions_01023 + 0x70))
                      (WdfDriverGlobals,*(undefined8 *)((longlong)param_1 + 0x5b0));
    if (*(uint *)((longlong)param_1 + 0xc54) <= uVar1) {
      p_Var2 = Opm::GetConnector(param_1,*(uint *)((longlong)param_1 + 0xc54));
      if (p_Var2 != (_PPM_CONNECTOR *)0x0) goto LAB_14000ded6;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x109,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                       (char)**(undefined8 **)((longlong)param_1 + 8),
                       (char)*(undefined4 *)((longlong)param_1 + 0xc54));
  }
  Opm::SetUnrecoverableFailureContext(param_1,IncorrectConnectorNumber,Undefined,0);
  uVar3 = 8;
LAB_14000ded6:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x10a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return uVar3;
}



===== WPP_RECORDER_SF_qDD @ 14000df30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDLi @ 14000e034 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDLi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,0xf8,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,0xf8,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_qDi @ 14000e174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDi(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,199,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,199,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qLi @ 14000e26c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,4,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qP @ 14000e364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,3,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qPDd @ 14000e438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,0x4b,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,0x4b,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qi @ 14000e554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qi(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,
                  &param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qid @ 14000e630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qid(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,10,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== CompleteExistingCommand @ 14000e728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::CompleteExistingCommand(long) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::CompleteExistingCommand(TestInterface *this,long param_1)

{
  WDFREQUEST__ *pWVar1;
  long lVar2;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffb8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 0xb;
    in_stack_ffffffffffffffb8 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x2e,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  if (this->m_ActiveRequest != (WDFREQUEST__ *)0x0) {
    lVar2 = -0x3fffff4b;
    if (param_1 != 0x102) {
      lVar2 = param_1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x2f,in_stack_ffffffffffffffb8,
                 (char)this->m_CxDevice->_padding_,(char)this->m_ActiveRequestIoctl,
                 (char)this->m_ActiveRequest,(char)lVar2);
    }
    pWVar1 = this->m_ActiveRequest;
    this->m_ActiveRequest = (WDFREQUEST__ *)0x0;
    (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar1,lVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x30,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== EvtIoDeviceControl @ 14000e850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl UcmUcsiCx::TestInterface::EvtIoDeviceControl(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
UcmUcsiCx::TestInterface::EvtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  TestInterface *this;
  WDFDEVICE__ *pWVar1;
  CxDevice *pCVar2;
  __uint64 _Var3;
  undefined *in_stack_ffffffffffffffa8;
  
  _Var3 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Var3 = 0xb;
    in_stack_ffffffffffffffa8 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x13,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  pWVar1 = (WDFDEVICE__ *)(**(code **)(WdfFunctions_01023 + 0x4e8))(WdfDriverGlobals,param_1);
  pCVar2 = CxDevice::GetContextFromObject(pWVar1);
  this = &pCVar2->m_TestInterface;
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
     ((pCVar2->m_TestInterface).m_ActiveRequest != (WDFREQUEST__ *)0x0)) {
    _Var3 = 0x4b;
    RtlAssert("m_ActiveRequest == (0)",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\TestInterface.h");
  }
  (pCVar2->m_TestInterface).m_ActiveRequestIoctl = param_5;
  (pCVar2->m_TestInterface).m_ActiveRequest = param_2;
  (pCVar2->m_TestInterface).m_OutputBufferLength = param_3;
  (pCVar2->m_TestInterface).m_InputBufferLength = param_4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (param_5 == 0x12131010) {
    IoctlSimulateFailure(this);
  }
  else if (param_5 == 0x12131014) {
    IoctlGetDeviceInfo(this);
  }
  else if (param_5 == 0x12131018) {
    IoctlSendCommand(this);
  }
  else if (param_5 == 0x1213101c) {
    IoctlSendCommandEx(this);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,_Var3,0x15,in_stack_ffffffffffffffa8,
                 (char)pWVar1,(char)param_5,(char)param_2,0xbb);
    }
    (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x16,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== EvtUcsiCommandCompleted @ 14000ea50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::EvtUcsiCommandCompleted(long,class
   UcmUcsiCx::UcsiDataBlock const & __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::TestInterface::EvtUcsiCommandCompleted
          (TestInterface *this,long param_1,UcsiDataBlock *param_2)

{
  WDFREQUEST__ **ppWVar1;
  WDFREQUEST__ *pWVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulong64 uVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  UcsiDataBlock *pUVar11;
  undefined8 uVar12;
  undefined8 *local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x2a,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  local_res8 = (undefined8 *)0x0;
  ppWVar1 = &this->m_ActiveRequest;
  if (param_1 == 0x102) {
    iVar8 = -0x3fffff4b;
  }
  else {
    iVar8 = (**(code **)(WdfFunctions_01023 + 0x870))(WdfDriverGlobals,*ppWVar1,0,&local_res8,0);
    if (iVar8 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000eca1;
      WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xb,0x2b,
                          &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                          (char)this->m_CxDevice->_padding_,(char)this->m_ActiveRequestIoctl,
                          (char)iVar8);
    }
    else {
      if (this->m_ActiveRequestIoctl == 0x12131018) {
        uVar6 = (param_2->field0_0x0).m_DataBlock.Control.AsUInt64;
        uVar12 = 0x30;
        *local_res8 = *(undefined8 *)&(param_2->field0_0x0).m_DataBlock;
        local_res8[1] = uVar6;
        uVar3 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 4);
        uVar4 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 8);
        uVar5 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 0xc);
        *(undefined4 *)(local_res8 + 2) =
             *(undefined4 *)(param_2->field0_0x0).m_DataBlockEx.MessageIn;
        *(undefined4 *)((longlong)local_res8 + 0x14) = uVar3;
        *(undefined4 *)(local_res8 + 3) = uVar4;
        *(undefined4 *)((longlong)local_res8 + 0x1c) = uVar5;
        uVar3 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 0x14);
        uVar4 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 0x18);
        uVar5 = *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 0x1c);
        *(undefined4 *)(local_res8 + 4) =
             *(undefined4 *)((param_2->field0_0x0).m_DataBlockEx.MessageIn + 0x10);
        *(undefined4 *)((longlong)local_res8 + 0x24) = uVar3;
        *(undefined4 *)(local_res8 + 5) = uVar4;
        *(undefined4 *)((longlong)local_res8 + 0x2c) = uVar5;
      }
      else {
        lVar10 = 4;
        if (this->m_ActiveRequestIoctl != 0x1213101c) {
          if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
            RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\testinterface.cpp",
                      0x1e1,0);
          }
          iVar8 = -0x3fffffff;
          goto LAB_14000ec5f;
        }
        puVar7 = local_res8;
        do {
          pUVar11 = param_2;
          puVar9 = puVar7;
          uVar6 = (pUVar11->field0_0x0).m_DataBlock.Control.AsUInt64;
          *puVar9 = *(undefined8 *)&(pUVar11->field0_0x0).m_DataBlock;
          puVar9[1] = uVar6;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 8);
          puVar9[2] = *(undefined8 *)(pUVar11->field0_0x0).m_DataBlockEx.MessageIn;
          puVar9[3] = uVar12;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x18);
          puVar9[4] = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x10);
          puVar9[5] = uVar12;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x28);
          puVar9[6] = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x20);
          puVar9[7] = uVar12;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x38);
          puVar9[8] = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x30);
          puVar9[9] = uVar12;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x48);
          puVar9[10] = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x40);
          puVar9[0xb] = uVar12;
          uVar12 = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x58);
          puVar9[0xc] = *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x50);
          puVar9[0xd] = uVar12;
          uVar3 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 100);
          uVar4 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x68);
          uVar5 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x6c);
          param_2 = (UcsiDataBlock *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x70);
          *(undefined4 *)(puVar9 + 0xe) =
               *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x60);
          *(undefined4 *)((longlong)puVar9 + 0x74) = uVar3;
          *(undefined4 *)(puVar9 + 0xf) = uVar4;
          *(undefined4 *)((longlong)puVar9 + 0x7c) = uVar5;
          lVar10 = lVar10 + -1;
          puVar7 = puVar9 + 0x10;
        } while (lVar10 != 0);
        uVar3 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x74);
        uVar4 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x78);
        uVar5 = *(undefined4 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x7c);
        uVar12 = 0x210;
        *(undefined4 *)(puVar9 + 0x10) = *(undefined4 *)&(param_2->field0_0x0).m_DataBlock;
        *(undefined4 *)((longlong)puVar9 + 0x84) = uVar3;
        *(undefined4 *)(puVar9 + 0x11) = uVar4;
        *(undefined4 *)((longlong)puVar9 + 0x8c) = uVar5;
      }
      (**(code **)(WdfFunctions_01023 + 0x898))(WdfDriverGlobals,*ppWVar1,uVar12);
    }
  }
LAB_14000ec5f:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLqPd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
LAB_14000eca1:
  pWVar2 = *ppWVar1;
  *ppWVar1 = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar2,iVar8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x2d,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== PurgeQueue @ 14000ed1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::PurgeQueue(void) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::PurgeQueue(TestInterface *this)

{
  if (this->m_Queue != (WDFQUEUE__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x528))(WdfDriverGlobals,this->m_Queue,0,0);
  }
  return;
}



===== WPP_RECORDER_SF_qDDDDDDLDDDDs @ 14000ed58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDDDDLDDDDs(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
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
  undefined1 uStack0000000000000088;
  char *in_stack_00000090;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000090 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000090[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000090;
    if (in_stack_00000090 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x1a,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000090 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000090[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000090 == (char *)0x0) {
    in_stack_00000090 = "NULL";
  }
  WppAutoLogTrace(param_1,4,7,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x1a,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  in_stack_00000090,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_qLq @ 14000f05c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x14,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x14,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qLqPd @ 14000f154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqPd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x2c,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x2c,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qLqd @ 14000f290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qPP @ 14000f3b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000040;
  undefined8 local_18 [2];
  
  local_18[0] = 0x38;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x18,&uStack0000000000000030,8,
               local_18,8,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,2,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x18,
                  &uStack0000000000000030,8,local_18,8,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qPPP @ 14000f4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qPPP
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,2,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 14000f5c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x400) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x1b,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,0xb,&WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,0x1b,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== PrettyPrintCci @ 14000f6b8 =====

/* public: void __cdecl UcmUcsiCx::UcsiDataBlock::PrettyPrintCci(void * __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::UcsiDataBlock::PrettyPrintCci(UcsiDataBlock *this,void *param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDddDddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((this->m_UcsiDataBlockExEnabled != false) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return;
}



===== PrettyPrintCommand @ 14000f7e4 =====

/* public: void __cdecl UcmUcsiCx::UcsiDataBlock::PrettyPrintCommand(void * __ptr64,char const *
   __ptr64,bool,long) __ptr64 */

void __thiscall
UcmUcsiCx::UcsiDataBlock::PrettyPrintCommand
          (UcsiDataBlock *this,void *param_1,char *param_2,bool param_3,long param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  char *pcVar3;
  uint uVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar8;
  
  pcVar3 = " (Test) ";
  uVar1 = *(ulonglong *)((longlong)&this->field0_0x0 + 8);
  bVar7 = 0;
  uVar4 = (uint)(this->field0_0x0).m_DataBlock.Control.AsUInt64 & 0xff;
  if (!param_3) {
    pcVar3 = " ";
  }
  uVar2 = uVar1 & 0xff;
  if (uVar2 < 0xe) {
    if (((uVar2 == 0xd) || (uVar2 == 3)) ||
       (((uVar2 == 7 || (((uVar2 == 8 || (uVar2 == 9)) || (uVar2 == 10)))) || (uVar2 == 0xb))))
    goto LAB_14000f87a;
    if (uVar2 != 0xc) goto LAB_14000f885;
    bVar7 = (byte)(uVar1 >> 0x18);
  }
  else {
    if ((((uVar2 != 0xe) && (uVar2 != 0xf)) && (uVar2 != 0x10)) &&
       (((uVar2 != 0x11 && (uVar2 != 0x12)) && (uVar2 != 0x14)))) goto LAB_14000f885;
LAB_14000f87a:
    bVar7 = (byte)(uVar1 >> 0x10);
  }
  bVar7 = bVar7 & 0x7f;
LAB_14000f885:
  if (uVar4 == 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qssLddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if (uVar4 == 5) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qssLDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if (uVar4 == 9) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar5 = 0xc;
      bVar6 = (byte)(uVar1 >> 0x17);
      uVar8 = 9;
    }
    else {
      if (uVar4 != 0xb) {
        if (uVar4 == 0x14) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_qssLDLDLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return;
        }
        if (bVar7 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          WPP_RECORDER_SF_qssLDiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_qssLDDiD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar5 = 0xd;
      bVar6 = (byte)(uVar1 >> 0x17);
      uVar8 = 0xb;
    }
    WPP_RECORDER_SF_qssLDLD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),this,(ulonglong)uVar4,uVar5,
               in_stack_ffffffffffffffa8,(char)param_1,pcVar3,in_stack_ffffffffffffffc0,uVar8,bVar7,
               bVar6 & 7,(char)param_4);
  }
  return;
}



===== PrettyPrintMessageIn @ 14000fb34 =====

/* public: void __cdecl UcmUcsiCx::UcsiDataBlock::PrettyPrintMessageIn(void * __ptr64,long) __ptr64
    */

void __thiscall
UcmUcsiCx::UcsiDataBlock::PrettyPrintMessageIn(UcsiDataBlock *this,void *param_1,long param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x13,
                     &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids);
  }
  uVar1 = (this->field0_0x0).m_DataBlock.Control.AsUInt64;
  uVar2 = uVar1 & 0xff;
  if (uVar2 == 0x12) {
    if (param_2 == 0) {
      if (((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x14,
                               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,(char)param_1,
                               (byte)(uVar1 >> 0x10) & 0x7f),
           (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
          (WPP_RECORDER_SF_qsssssssssssss(*(undefined8 *)(WPP_GLOBAL_Control + 0x40)),
          (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
         (WPP_RECORDER_SF_qdLLLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40)),
         (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qLDsss(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if (this->m_UcsiDataBlockExEnabled == false) {
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      return;
    }
  }
  else if ((uVar2 == 0x13) && (param_2 == 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qDDDDDDDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    return;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xd,0x1a,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,(char)param_1,
               (char)*(undefined4 *)(this->field0_0x0).m_DataBlockEx.MessageIn,
               (char)*(undefined4 *)((this->field0_0x0).m_DataBlockEx.MessageIn + 4),
               (char)*(undefined4 *)((this->field0_0x0).m_DataBlockEx.MessageIn + 8),
               (char)*(undefined4 *)((this->field0_0x0).m_DataBlockEx.MessageIn + 0xc));
  }
  return;
}



===== WPP_RECORDER_SF_qDDDDDDDDDDDDDDDD @ 140010074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDDDDDDDDDDDDDDD(undefined8 param_1)

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
  undefined1 uStack0000000000000088;
  undefined1 uStack0000000000000090;
  undefined1 uStack0000000000000098;
  undefined1 uStack00000000000000a0;
  undefined1 uStack00000000000000a8;
  undefined1 uStack00000000000000b0;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x19,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,
               &uStack0000000000000080,4,&uStack0000000000000088,4,&uStack0000000000000090,4,
               &uStack0000000000000098,4,&uStack00000000000000a0,4,&uStack00000000000000a8,4,
               &uStack00000000000000b0,4,0);
  }
  WppAutoLogTrace(param_1,3,10,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x19,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,&uStack0000000000000080,4,&uStack0000000000000088,4,
                  &uStack0000000000000090,4,&uStack0000000000000098,4,&uStack00000000000000a0,4,
                  &uStack00000000000000a8,4,&uStack00000000000000b0,4,0);
  return;
}



===== WPP_RECORDER_SF_qDddDddddd @ 140010358 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDddDddddd(undefined8 param_1)

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
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,&uStack0000000000000078,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,
                  &uStack0000000000000078,4,0);
  return;
}



===== WPP_RECORDER_SF_qLDsss @ 140010540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLDsss(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  char *in_stack_00000048;
  char *in_stack_00000050;
  char *in_stack_00000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    if (in_stack_00000058 == (char *)0x0) {
      lVar5 = 5;
    }
    else {
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (in_stack_00000058[lVar4] != '\0');
      lVar5 = lVar5 + 2;
    }
    pcVar7 = in_stack_00000058;
    if (in_stack_00000058 == (char *)0x0) {
      pcVar7 = "NULL";
    }
    if (in_stack_00000050 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000050[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar6 = in_stack_00000050;
    if (in_stack_00000050 == (char *)0x0) {
      pcVar6 = "NULL";
    }
    if (in_stack_00000048 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000048[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x17,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,pcVar1,lVar3,pcVar6,lVar4,pcVar7,
               lVar5,0);
  }
  if (in_stack_00000058 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    lVar4 = -1;
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (in_stack_00000058[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  if (in_stack_00000058 == (char *)0x0) {
    in_stack_00000058 = "NULL";
  }
  if (in_stack_00000050 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000050[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000050 == (char *)0x0) {
    in_stack_00000050 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000048 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000048[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = "NULL";
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x17,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  in_stack_00000048,lVar2,in_stack_00000050,lVar4,in_stack_00000058,lVar5,0);
  return;
}



===== WPP_RECORDER_SF_qdLLLD @ 1400107c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdLLLD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 140010918 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qddd @ 140010a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x12,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x12,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLDD @ 140010b28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLDD(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,10,&uStack0000000000000030,8,pcVar3,
               lVar2,"Sending",8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,0);
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
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,10,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,"Sending",8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLDDiD @ 140010d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLDDiD(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xf,&uStack0000000000000030,8,pcVar3
               ,lVar2,"Sending",8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,8,&uStack0000000000000068,4,0);
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
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xf,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,"Sending",8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,8,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLDLD @ 140010f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLDLD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,char *param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = param_7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,param_4,&param_6,8,pcVar3,lVar2,
               "Sending",8,&param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
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
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,param_4,&param_6,8,
                  pcVar4,lVar1,"Sending",8,&param_9,4,&param_10,4,&param_11,4,&param_12,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLDLDLD @ 140011174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLDLDLD(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xe,&uStack0000000000000030,8,pcVar3
               ,lVar2,"Sending",8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,
               &uStack0000000000000070,4,0);
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
  WppAutoLogTrace(param_1,4,10,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xe,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,"Sending",8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLDiD @ 1400113d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLDiD(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x10,&uStack0000000000000030,8,
               pcVar3,lVar2,"Sending",8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,8,&uStack0000000000000060,4,0);
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
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x10,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,"Sending",8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,8,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_qssLddD @ 1400115f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qssLddD(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
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
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xb,&uStack0000000000000030,8,pcVar3
               ,lVar2,"Sending",8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,0);
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
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0xb,
                  &uStack0000000000000030,8,in_stack_00000038,lVar1,"Sending",8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_qsssssssssssss @ 140011820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsssssssssssss(undefined8 param_1)

{
  longlong lVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  longlong lVar9;
  longlong lVar10;
  char *pcVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  char *pcVar17;
  longlong lVar18;
  char *pcVar19;
  longlong lVar20;
  longlong lVar21;
  char *pcVar22;
  longlong lVar23;
  char *pcVar24;
  longlong lVar25;
  char *pcVar26;
  longlong lVar27;
  char *pcStack0000000000000028;
  undefined1 uStack0000000000000030;
  char *in_stack_00000038;
  char *in_stack_00000040;
  char *in_stack_00000048;
  char *in_stack_00000050;
  char *in_stack_00000058;
  char *in_stack_00000060;
  char *in_stack_00000068;
  char *in_stack_00000070;
  char *in_stack_00000078;
  char *in_stack_00000080;
  char *in_stack_00000088;
  char *in_stack_00000090;
  char *in_stack_00000098;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  
  pcStack0000000000000028 = "NULL";
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    if (in_stack_00000098 == (char *)0x0) {
      local_98 = 5;
    }
    else {
      lVar1 = -1;
      do {
        local_98 = lVar1;
        lVar1 = local_98 + 1;
      } while (in_stack_00000098[lVar1] != '\0');
      local_98 = local_98 + 2;
    }
    pcVar2 = in_stack_00000098;
    if (in_stack_00000098 == (char *)0x0) {
      pcVar2 = "NULL";
    }
    if (in_stack_00000090 == (char *)0x0) {
      local_90 = 5;
    }
    else {
      lVar1 = -1;
      do {
        local_90 = lVar1;
        lVar1 = local_90 + 1;
      } while (in_stack_00000090[lVar1] != '\0');
      local_90 = local_90 + 2;
    }
    pcVar3 = in_stack_00000090;
    if (in_stack_00000090 == (char *)0x0) {
      pcVar3 = "NULL";
    }
    if (in_stack_00000088 == (char *)0x0) {
      local_88 = 5;
    }
    else {
      lVar1 = -1;
      do {
        local_88 = lVar1;
        lVar1 = local_88 + 1;
      } while (in_stack_00000088[lVar1] != '\0');
      local_88 = local_88 + 2;
    }
    pcVar4 = in_stack_00000088;
    if (in_stack_00000088 == (char *)0x0) {
      pcVar4 = "NULL";
    }
    if (in_stack_00000080 == (char *)0x0) {
      local_80 = 5;
    }
    else {
      lVar1 = -1;
      do {
        local_80 = lVar1;
        lVar1 = local_80 + 1;
      } while (in_stack_00000080[lVar1] != '\0');
      local_80 = local_80 + 2;
    }
    pcVar5 = in_stack_00000080;
    if (in_stack_00000080 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000078 == (char *)0x0) {
      local_78 = 5;
    }
    else {
      lVar1 = -1;
      do {
        local_78 = lVar1;
        lVar1 = local_78 + 1;
      } while (in_stack_00000078[lVar1] != '\0');
      local_78 = local_78 + 2;
    }
    pcVar6 = in_stack_00000078;
    if (in_stack_00000078 == (char *)0x0) {
      pcVar6 = "NULL";
    }
    if (in_stack_00000070 == (char *)0x0) {
      lVar1 = 5;
    }
    else {
      lVar25 = -1;
      do {
        lVar1 = lVar25;
        lVar25 = lVar1 + 1;
      } while (in_stack_00000070[lVar25] != '\0');
      lVar1 = lVar1 + 2;
    }
    pcVar7 = in_stack_00000070;
    if (in_stack_00000070 == (char *)0x0) {
      pcVar7 = "NULL";
    }
    if (in_stack_00000068 == (char *)0x0) {
      lVar25 = 5;
    }
    else {
      lVar27 = -1;
      do {
        lVar25 = lVar27;
        lVar27 = lVar25 + 1;
      } while (in_stack_00000068[lVar27] != '\0');
      lVar25 = lVar25 + 2;
    }
    pcVar8 = in_stack_00000068;
    if (in_stack_00000068 == (char *)0x0) {
      pcVar8 = "NULL";
    }
    if (in_stack_00000060 == (char *)0x0) {
      lVar27 = 5;
    }
    else {
      lVar16 = -1;
      do {
        lVar27 = lVar16;
        lVar16 = lVar27 + 1;
      } while (in_stack_00000060[lVar16] != '\0');
      lVar27 = lVar27 + 2;
    }
    pcVar24 = in_stack_00000060;
    if (in_stack_00000060 == (char *)0x0) {
      pcVar24 = "NULL";
    }
    if (in_stack_00000058 == (char *)0x0) {
      lVar16 = 5;
    }
    else {
      lVar18 = -1;
      do {
        lVar16 = lVar18;
        lVar18 = lVar16 + 1;
      } while (in_stack_00000058[lVar18] != '\0');
      lVar16 = lVar16 + 2;
    }
    pcVar26 = in_stack_00000058;
    if (in_stack_00000058 == (char *)0x0) {
      pcVar26 = "NULL";
    }
    if (in_stack_00000050 == (char *)0x0) {
      lVar18 = 5;
    }
    else {
      lVar23 = -1;
      do {
        lVar18 = lVar23;
        lVar23 = lVar18 + 1;
      } while (in_stack_00000050[lVar23] != '\0');
      lVar18 = lVar18 + 2;
    }
    pcVar17 = in_stack_00000050;
    if (in_stack_00000050 == (char *)0x0) {
      pcVar17 = "NULL";
    }
    if (in_stack_00000048 == (char *)0x0) {
      lVar23 = 5;
    }
    else {
      lVar20 = -1;
      do {
        lVar23 = lVar20;
        lVar20 = lVar23 + 1;
      } while (in_stack_00000048[lVar20] != '\0');
      lVar23 = lVar23 + 2;
    }
    pcVar22 = in_stack_00000048;
    if (in_stack_00000048 == (char *)0x0) {
      pcVar22 = "NULL";
    }
    if (in_stack_00000040 == (char *)0x0) {
      lVar20 = 5;
    }
    else {
      lVar13 = -1;
      do {
        lVar20 = lVar13;
        lVar13 = lVar20 + 1;
      } while (in_stack_00000040[lVar13] != '\0');
      lVar20 = lVar20 + 2;
    }
    pcVar19 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar19 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar13 = 5;
    }
    else {
      lVar9 = -1;
      do {
        lVar13 = lVar9;
        lVar9 = lVar13 + 1;
      } while (in_stack_00000038[lVar9] != '\0');
      lVar13 = lVar13 + 2;
    }
    pcVar11 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar11 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x15,&uStack0000000000000030,8,
               pcVar11,lVar13,pcVar19,lVar20,pcVar22,lVar23,pcVar17,lVar18,pcVar26,lVar16,pcVar24,
               lVar27,pcVar8,lVar25,pcVar7,lVar1,pcVar6,local_78,pcVar5,local_80,pcVar4,local_88,
               pcVar3,local_90,pcVar2,local_98,0);
  }
  lVar1 = 5;
  if (in_stack_00000098 == (char *)0x0) {
    lVar25 = 5;
  }
  else {
    lVar27 = -1;
    do {
      lVar25 = lVar27;
      lVar27 = lVar25 + 1;
    } while (in_stack_00000098[lVar27] != '\0');
    lVar25 = lVar25 + 2;
  }
  if (in_stack_00000098 == (char *)0x0) {
    in_stack_00000098 = "NULL";
  }
  if (in_stack_00000090 == (char *)0x0) {
    lVar27 = 5;
  }
  else {
    lVar16 = -1;
    do {
      lVar27 = lVar16;
      lVar16 = lVar27 + 1;
    } while (in_stack_00000090[lVar16] != '\0');
    lVar27 = lVar27 + 2;
  }
  if (in_stack_00000090 == (char *)0x0) {
    in_stack_00000090 = "NULL";
  }
  if (in_stack_00000088 == (char *)0x0) {
    lVar16 = 5;
  }
  else {
    lVar18 = -1;
    do {
      lVar16 = lVar18;
      lVar18 = lVar16 + 1;
    } while (in_stack_00000088[lVar18] != '\0');
    lVar16 = lVar16 + 2;
  }
  if (in_stack_00000088 == (char *)0x0) {
    in_stack_00000088 = "NULL";
  }
  if (in_stack_00000080 == (char *)0x0) {
    lVar18 = 5;
  }
  else {
    lVar23 = -1;
    do {
      lVar18 = lVar23;
      lVar23 = lVar18 + 1;
    } while (in_stack_00000080[lVar23] != '\0');
    lVar18 = lVar18 + 2;
  }
  if (in_stack_00000080 == (char *)0x0) {
    in_stack_00000080 = "NULL";
  }
  if (in_stack_00000078 == (char *)0x0) {
    lVar23 = 5;
  }
  else {
    lVar20 = -1;
    do {
      lVar23 = lVar20;
      lVar20 = lVar23 + 1;
    } while (in_stack_00000078[lVar20] != '\0');
    lVar23 = lVar23 + 2;
  }
  if (in_stack_00000078 == (char *)0x0) {
    in_stack_00000078 = "NULL";
  }
  if (in_stack_00000070 == (char *)0x0) {
    lVar20 = 5;
  }
  else {
    lVar13 = -1;
    do {
      lVar20 = lVar13;
      lVar13 = lVar20 + 1;
    } while (in_stack_00000070[lVar13] != '\0');
    lVar20 = lVar20 + 2;
  }
  if (in_stack_00000070 == (char *)0x0) {
    in_stack_00000070 = "NULL";
  }
  if (in_stack_00000068 == (char *)0x0) {
    lVar13 = 5;
  }
  else {
    lVar9 = -1;
    do {
      lVar13 = lVar9;
      lVar9 = lVar13 + 1;
    } while (in_stack_00000068[lVar9] != '\0');
    lVar13 = lVar13 + 2;
  }
  if (in_stack_00000068 == (char *)0x0) {
    in_stack_00000068 = "NULL";
  }
  if (in_stack_00000060 == (char *)0x0) {
    lVar9 = 5;
  }
  else {
    lVar21 = -1;
    do {
      lVar9 = lVar21;
      lVar21 = lVar9 + 1;
    } while (in_stack_00000060[lVar21] != '\0');
    lVar9 = lVar9 + 2;
  }
  if (in_stack_00000060 == (char *)0x0) {
    in_stack_00000060 = "NULL";
  }
  if (in_stack_00000058 != (char *)0x0) {
    lVar21 = -1;
    do {
      lVar1 = lVar21;
      lVar21 = lVar1 + 1;
    } while (in_stack_00000058[lVar21] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (in_stack_00000058 == (char *)0x0) {
    in_stack_00000058 = "NULL";
  }
  if (in_stack_00000050 == (char *)0x0) {
    lVar21 = 5;
  }
  else {
    lVar14 = -1;
    do {
      lVar21 = lVar14;
      lVar14 = lVar21 + 1;
    } while (in_stack_00000050[lVar14] != '\0');
    lVar21 = lVar21 + 2;
  }
  if (in_stack_00000050 == (char *)0x0) {
    in_stack_00000050 = "NULL";
  }
  if (in_stack_00000048 == (char *)0x0) {
    lVar14 = 5;
  }
  else {
    lVar12 = -1;
    do {
      lVar14 = lVar12;
      lVar12 = lVar14 + 1;
    } while (in_stack_00000048[lVar12] != '\0');
    lVar14 = lVar14 + 2;
  }
  if (in_stack_00000048 == (char *)0x0) {
    in_stack_00000048 = pcStack0000000000000028;
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar12 = 5;
  }
  else {
    lVar10 = -1;
    do {
      lVar12 = lVar10;
      lVar10 = lVar12 + 1;
    } while (in_stack_00000040[lVar10] != '\0');
    lVar12 = lVar12 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = pcStack0000000000000028;
  }
  lVar10 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar15 = 5;
  }
  else {
    do {
      lVar15 = lVar10;
      lVar10 = lVar15 + 1;
    } while (in_stack_00000038[lVar10] != '\0');
    lVar15 = lVar15 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = pcStack0000000000000028;
  }
  WppAutoLogTrace(param_1,4,0xd,&WPP_ec9fd6d8e8f836f6053e524848699f34_Traceguids,0x15,
                  &uStack0000000000000030,8,in_stack_00000038,lVar15,in_stack_00000040,lVar12,
                  in_stack_00000048,lVar14,in_stack_00000050,lVar21,in_stack_00000058,lVar1,
                  in_stack_00000060,lVar9,in_stack_00000068,lVar13,in_stack_00000070,lVar20,
                  in_stack_00000078,lVar23,in_stack_00000080,lVar18,in_stack_00000088,lVar16,
                  in_stack_00000090,lVar27,in_stack_00000098,lVar25,0);
  return;
}



===== Break @ 1400120dc =====

/* void __cdecl UcmUcsiCx::Verify::Break(void) */

void __cdecl UcmUcsiCx::Verify::Break(void)

{
  if ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) {
    RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\verify.cpp",0xd8,0);
  }
  return;
}



===== IsDriverGlobalsValid @ 140012120 =====

/* long __cdecl UcmUcsiCx::Verify::IsDriverGlobalsValid(struct _UCMUCSI_DRIVER_GLOBALS * __ptr64) */

long __cdecl UcmUcsiCx::Verify::IsDriverGlobalsValid(_UCMUCSI_DRIVER_GLOBALS *param_1)

{
  undefined2 uVar1;
  
  if (param_1 == (_UCMUCSI_DRIVER_GLOBALS *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140012186;
    uVar1 = 10;
  }
  else {
    if (param_1[-1].Reserved == 0x78435555) {
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140012186;
    uVar1 = 0xb;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xc,uVar1,
                   &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids);
LAB_140012186:
  Break();
  return -0x3ffffff3;
}



===== IsIrqlLessThanOrEqualTo @ 1400121a0 =====

/* long __cdecl UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo(unsigned char) */

long __cdecl UcmUcsiCx::Verify::IsIrqlLessThanOrEqualTo(uchar param_1)

{
  byte bVar1;
  long lVar2;
  
  bVar1 = KeGetCurrentIrql();
  if (param_1 < bVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    lVar2 = -0x3ffffeb8;
    Break();
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}



===== IsNotNull @ 140012204 =====

/* long __cdecl UcmUcsiCx::Verify::IsNotNull(void * __ptr64,unsigned short const * __ptr64) */

long __cdecl UcmUcsiCx::Verify::IsNotNull(void *param_1,ushort *param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 == (void *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    lVar1 = -0x3ffffff3;
    Break();
  }
  return lVar1;
}



===== WPP_RECORDER_SF_DD @ 140012250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,0xc,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,0xc,&WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,0xc,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 140012320 =====

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
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
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
               &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,0xd,pwVar2,lVar1,0);
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
  WppAutoLogTrace(param_1,2,0xc,&WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,0xd,
                  in_stack_00000030,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_qqs @ 14001244c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqs(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,param_4,&param_6,8,&param_7,8,
               "Waiting for Opm machine to stop",0x20,0);
  }
  WppAutoLogTrace(param_1,param_2,0xc,&WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,param_4,
                  &param_6,8,&param_7,8,"Waiting for Opm machine to stop",0x20,0);
  return;
}



===== operator_new[] @ 140012554 =====

/* void * __ptr64 __cdecl operator new[](unsigned __int64) */

void * __cdecl operator_new__(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,param_1,0x69736355);
  return pvVar1;
}



===== operator_delete[] @ 140012580 =====

/* void __cdecl operator delete[](void * __ptr64) */

void __cdecl operator_delete__(void *param_1)

{
  ExFreePoolWithTag(param_1,0x69736355);
  return;
}



===== FxStubDriverUnloadCommon @ 1400125a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar1 = &_UcmCx_BIND_INFO;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d2a8 != &__KMDF_CLASS_BIND_START) {
    puVar2 = (uint *)(PTR___KMDF_CLASS_BIND_START_14001d2a8 + 0x50);
    while( true ) {
      for (; (puVar1 + 2 <= puVar2 && (*(longlong *)puVar1 == 0)); puVar1 = puVar1 + 2) {
      }
      if (puVar1 < puVar2) break;
      puVar1 = puVar2;
LAB_1400125fd:
      if (puVar1 == (uint *)0x0) goto LAB_140012653;
      if (puVar2 <= puVar1) goto LAB_14001266b;
      if (*(code **)(puVar1 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      else {
        (**(code **)(puVar1 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar1);
      }
      puVar1 = (uint *)((longlong)puVar1 + (ulonglong)*puVar1);
    }
    if ((puVar1 + 0x14 <= puVar2) && (*puVar1 == 0x50)) goto LAB_1400125fd;
LAB_140012653:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14001266b:
  WdfVersionUnbind(&DAT_14001d4c0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1400126a0 =====

void entry(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1400126d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FxDriverEntryWorker(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  int iVar2;
  _DRIVER_OBJECT *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_DRIVER_OBJECT *)0x0) {
    lVar1 = UcmUcsiCx::Driver::CreateAndInit((_DRIVER_OBJECT *)0x0,param_2);
  }
  else {
    _DAT_14001d4c0 = 0x2080000;
    _DAT_14001d4c8 = &DAT_14001d4f0;
    RtlCopyUnicodeString(&DAT_14001d4c0);
    p_Var3 = param_1;
    lVar1 = WdfVersionBind(param_1,&DAT_14001d4c0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < lVar1) {
      lVar1 = FxStubBindClasses((_WDF_BIND_INFO *)p_Var3);
      if ((-1 < lVar1) && (lVar1 = FxStubInitTypes(), -1 < lVar1)) {
        lVar1 = UcmUcsiCx::Driver::CreateAndInit(param_1,param_2);
        if (-1 < lVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (param_1->DriverUnload != (_func___cdecl_void__DRIVER_OBJECT_ptr *)0x0) {
              DAT_14001d6f8 = param_1->DriverUnload;
            }
            param_1->DriverUnload = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",lVar1,&DAT_14001d4c0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d2a8 != &__KMDF_CLASS_BIND_START) {
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
  return lVar1;
}



===== FxStubDriverUnload @ 140012860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14001d6f8 != (code *)0x0) && (DAT_14001d6f8 != FxStubDriverUnload)) {
    (*DAT_14001d6f8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140012894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400128b9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &_UcmCx_BIND_INFO;
  while( true ) {
    for (; (puVar2 + 2 < (uint *)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*(longlong *)puVar2 == 0)); puVar2 = puVar2 + 2) {
    }
    if ((uint *)0x14001d29f < puVar2) break;
    if (((&__KMDF_CLASS_BIND_END < puVar2 + 0x14) || (*puVar2 != 0x50)) || (puVar2 == (uint *)0x0))
    {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14001d2a8 = (undefined *)puVar2;
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



===== FxStubInitTypes @ 140012a1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140012a39) */
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
    if ((void **)0x14001d2bf < ppvVar2) break;
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



===== EnqueueEvent @ 140012ae4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl SmFx::StateMachineEngine::EnqueueEvent(unsigned short) __ptr64 */

void __thiscall SmFx::StateMachineEngine::EnqueueEvent(StateMachineEngine *this,ushort param_1)

{
  StateMachineEngineImpl *this_00;
  StateMachineEngineImpl SVar1;
  bool bVar2;
  undefined2 uVar3;
  bool bVar4;
  
  this_00 = this->m_impl;
  SVar1 = (StateMachineEngineImpl)KeAcquireSpinLockRaiseToDpc(this_00 + 1000);
  this_00[0x3f1] = SVar1;
  if (*(int *)(this_00 + 0x3e0) == 5) {
    if (param_1 == *(ushort *)(this_00 + 0x370)) {
      if (*(code **)(this_00 + 0x3a0) != (code *)0x0) {
        if (param_1 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined2 *)
                   (*(longlong *)(*(longlong *)(this_00 + 0x378) + 0x10) + (ulonglong)param_1 * 4);
        }
        (**(code **)(this_00 + 0x3a0))(*(undefined8 *)(this_00 + 0x380),uVar3);
      }
      *(undefined2 *)(this_00 + 0x370) = 0;
      goto LAB_140012b72;
    }
    bVar4 = false;
  }
  else {
    bVar4 = *(int *)(this_00 + 0x3e0) == 1;
  }
  bVar2 = StateMachineEngineImpl::EnqueueEventWithDisposition(this_00,param_1);
  if (!bVar2) {
    return;
  }
  if (!bVar4) {
    KeReleaseSpinLock(this_00 + 1000,this_00[0x3f1]);
    return;
  }
LAB_140012b72:
  this_00[0x3d7] = SVar1;
  this_00[0x3d6] = (StateMachineEngineImpl)0x0;
  if ((byte)SVar1 < 2) {
    *(void **)(this_00 + 0x3d8) = SystemReserved1[0xf];
  }
  else {
    *(undefined4 *)(this_00 + 0x3d8) = SystemReserved1[0x12]._4_4_;
  }
  StateMachineEngineImpl::ProcessEventQueue(this_00);
  return;
}



===== Initialize @ 140012c00 =====

/* public: long __cdecl SmFx::StateMachineEngine::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::Initialize(StateMachineEngine *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  long lVar1;
  StateMachineEngineImpl *this_00;
  uint uVar2;
  
  uVar2 = 0x78466d53;
  if (param_1->poolTag != 0) {
    uVar2 = param_1->poolTag;
  }
  this_00 = (StateMachineEngineImpl *)ExAllocatePool2(0x40,0x420,uVar2);
  if (this_00 == (StateMachineEngineImpl *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    memset(this_00,0,0x420);
    *(undefined2 *)(this_00 + 0x3d5) = 0x101;
    this_00[0x3d7] = (StateMachineEngineImpl)0x2;
    *(undefined8 *)(this_00 + 0x408) = 0;
    *(undefined8 *)(this_00 + 0x410) = 0;
    *(StateMachineEngine **)(this_00 + 0x418) = this;
    this->m_impl = this_00;
    lVar1 = StateMachineEngineImpl::Initialize(this_00,param_1);
    if (lVar1 < 0) {
      StateMachineEngineImpl::Destroy(this_00);
      this->m_impl = (StateMachineEngineImpl *)0x0;
    }
    else {
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== <lambda_invoker_cdecl> @ 140012cc0 =====

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
      goto LAB_140012db8;
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
LAB_140012db8:
  SmFx::StateMachineEngine::StateMachineEngineImpl::ProcessEventQueue(param_1);
  return;
}



===== ~StateMachineEngineImpl @ 140012dd4 =====

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



===== AddEventToEventQueue @ 140012e94 =====

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
    ReportExceptionWithLockHeld(this,EventQueueOverflow,param_1,0);
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



===== Destroy @ 140012f20 =====

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



===== EnqueueEventWithDisposition @ 140012f7c =====

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
          goto LAB_140013042;
        }
      }
    }
    else {
      if (cVar1 != '\x03') {
LAB_140013042:
        KeReleaseSpinLock(this + 1000,CONCAT71((int7)(uVar4 >> 8),this[0x3f1]));
        return false;
      }
      for (uVar4 = CONCAT71(uVar5,this[0x3d2]); SUB81(uVar4,0) != this[0x3d3];
          uVar4 = CONCAT71((int7)(uVar4 >> 8),(char)SUB81(uVar4,0) + '\x01') & 0xffffffffffffff0f) {
        if (*(ushort *)(this + (uVar4 & 0xff) * 2 + 0x340) == param_1) goto LAB_140013042;
      }
    }
  }
  bVar2 = AddEventToEventQueue(this,param_1);
  return bVar2;
}



===== ExecuteCurrentState @ 140013068 =====

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
                LogTransition(this,Purge,(ushort)uVar13,uVar3,0,(char)this[0x3d4] + 0xff);
                goto LAB_1400131cb;
              }
              lVar6 = lVar6 + 1;
              uVar4 = puVar1[lVar6];
            }
            uVar8 = (ulonglong)(byte)SVar2;
            SVar2 = (StateMachineEngineImpl)((char)SVar2 + 1U & 0xf);
            *(ushort *)(this + uVar8 * 2 + 0x340) = uVar3;
LAB_1400131cb:
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



===== ExecuteEventAction @ 1400132b8 =====

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
    MVar5 = UnhandledEvent;
LAB_1400136a9:
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
      LogTransition(this,External,uVar6,*(ushort *)(param_1 + 4),uVar8,(uchar)param_1[6]);
      *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = uVar8;
LAB_140013670:
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
            if (SVar1 != (StateMachineEngineImpl)0x0) goto LAB_14001342c;
          }
          else {
            uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -4 + (ulonglong)(byte)SVar1 * 2);
LAB_14001342c:
            uVar6 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2);
          }
          LogTransition(this,ExplicitPop,uVar6,local_28._4_2_,uVar8,local_28._6_1_);
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
        LogTransition(this,Call,uVar8,0,uVar6,(uchar)SVar1);
        *(ushort *)(*(longlong *)(this + 0x368) + (ulonglong)(byte)this[0x3d4] * 2) = uVar6;
        this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + '\x01');
        goto LAB_140013670;
      }
      uVar6 = 0;
      MVar5 = StackOverflow;
      goto LAB_1400136a9;
    }
    uVar8 = 0;
    if (*(longlong *)(*(longlong *)(param_1 + 8) + 8) == 0) {
      if (this[0x3d4] != (StateMachineEngineImpl)0x0) {
        uVar8 = *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2);
      }
      LogTransition(this,Ignore,uVar8,*(ushort *)(param_1 + 4),
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
      LogTransition(this,Internal,uVar8,*(ushort *)(param_1 + 4),
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



===== ExitCurrentState @ 1400136d4 =====

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



===== FindActionForEvent @ 1400137d4 =====

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
              goto LAB_14001395a;
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
              goto LAB_14001395a;
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
            goto LAB_14001395e;
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
LAB_14001395a:
              *(ushort **)(param_2 + 8) = puVar2;
LAB_14001395e:
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



===== Initialize @ 140013984 =====

/* private: long __cdecl SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize(struct
   SmFx::STATE_MACHINE_ENGINE_CONFIG const & __ptr64) __ptr64 */

long __thiscall
SmFx::StateMachineEngine::StateMachineEngineImpl::Initialize
          (StateMachineEngineImpl *this,STATE_MACHINE_ENGINE_CONFIG *param_1)

{
  _DEVICE_OBJECT *p_Var1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined8 uVar6;
  _func___cdecl_void_void_ptr_ushort *p_Var7;
  long lVar8;
  longlong lVar9;
  StateMachineEngineImpl SVar10;
  int iVar11;
  
  pvVar5 = param_1->context;
  *(STATE_MACHINE_SPECIFICATION **)(this + 0x378) = param_1->machineSpec;
  *(void **)(this + 0x380) = pvVar5;
  uVar6 = *(undefined8 *)&param_1->poolTag;
  *(_DEVICE_OBJECT **)(this + 0x388) = param_1->deviceObject;
  *(undefined8 *)(this + 0x390) = uVar6;
  p_Var7 = param_1->logEventEnqueueCallback;
  *(_func___cdecl_void_void_ptr_MachineException_ushort_ushort **)(this + 0x398) =
       param_1->logExceptionCallback;
  *(_func___cdecl_void_void_ptr_ushort **)(this + 0x3a0) = p_Var7;
  uVar2 = *(undefined4 *)((longlong)&param_1->logTransitionCallback + 4);
  uVar3 = *(undefined4 *)&param_1->machineDestroyedCallback;
  uVar4 = *(undefined4 *)((longlong)&param_1->machineDestroyedCallback + 4);
  *(undefined4 *)(this + 0x3a8) = *(undefined4 *)&param_1->logTransitionCallback;
  *(undefined4 *)(this + 0x3ac) = uVar2;
  *(undefined4 *)(this + 0x3b0) = uVar3;
  *(undefined4 *)(this + 0x3b4) = uVar4;
  *(undefined8 *)(this + 0x3b8) = *(undefined8 *)&param_1->isWorkerRequired;
  if (this[0x3f0] == (StateMachineEngineImpl)0x0) {
    KeInitializeSpinLock(this + 1000);
    this[0x3f0] = (StateMachineEngineImpl)0x1;
  }
  SVar10 = (StateMachineEngineImpl)0x10;
  if (this[0x3b9] != (StateMachineEngineImpl)0x0) {
    SVar10 = this[0x3b9];
  }
  this[0x360] = SVar10;
  iVar11 = 0x78466d53;
  if (*(int *)(this + 0x390) != 0) {
    iVar11 = *(int *)(this + 0x390);
  }
  lVar9 = ExAllocatePool2(0x40,(ulonglong)(byte)SVar10 * 2,iVar11);
  *(longlong *)(this + 0x368) = lVar9;
  if (lVar9 == 0) {
LAB_140013a3d:
    lVar8 = -0x3fffff66;
  }
  else {
    if (this[0x3b8] != (StateMachineEngineImpl)0x0) {
      p_Var1 = param_1->deviceObject;
      if (*(longlong *)(this + 0x3f8) != 0) {
        return -0x3ffffe7c;
      }
      lVar9 = IoAllocateWorkItem(p_Var1);
      *(longlong *)(this + 0x3f8) = lVar9;
      if (lVar9 == 0) goto LAB_140013a3d;
      *(_DEVICE_OBJECT **)(this + 0x400) = p_Var1;
      *(code **)(this + 0x408) = <lambda_c276094d149607b901f7fae525da7e78>::<lambda_invoker_cdecl>;
      *(StateMachineEngineImpl **)(this + 0x410) = this;
    }
    InitiateFirstRun(this);
    lVar8 = 0;
  }
  return lVar8;
}



===== InitiateFirstRun @ 140013abc =====

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



===== LogTransition @ 140013bb8 =====

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
  if ((param_1 - Internal & 0xfffffffb) == 0) {
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



===== PopToStackDepth @ 140013ce4 =====

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
      LogTransition(this,ImplicitPop,
                    *(ushort *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)SVar1 * 2),
                    *(ushort *)(param_1 + 4),uVar3,(char)SVar1 - 1);
      *(undefined2 *)(*(longlong *)(this + 0x368) + -2 + (ulonglong)(byte)this[0x3d4] * 2) = 0;
      this[0x3d4] = (StateMachineEngineImpl)((char)this[0x3d4] + -1);
      this[0x3d5] = (StateMachineEngineImpl)0x0;
    } while ((byte)param_1[6] + 1 < (uint)(byte)this[0x3d4]);
  }
  return 1;
}



===== ProcessEventQueue @ 140013dc4 =====

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
LAB_140013e01:
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
          if (SUB81(uVar7,0) == SVar5) goto LAB_140013e6a;
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
        if (uVar1 != 0) goto LAB_140013eef;
      }
LAB_140013e6a:
      EVar4 = 1;
      goto LAB_140013e6f;
    }
    local_28 = *(undefined8 *)(this + 0x3c0);
    uStack_20 = *(undefined8 *)(this + 0x3c8);
    bVar8 = false;
LAB_140013eef:
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
      if (!bVar8) goto LAB_140013e6f;
      *(undefined2 *)(this + 0x370) = 0;
      bVar8 = true;
      goto LAB_140013e01;
    }
    if (EVar4 != 2) {
LAB_140013e6f:
      UpdateEngineState(this,EVar4);
      return;
    }
  } while( true );
}



===== ReportException @ 140013fd8 =====

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



===== ReportExceptionWithLockHeld @ 14001404c =====

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



===== UpdateEngineState @ 140014134 =====

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



===== Feature_SMST__private_IsEnabledDeviceUsageNoInline @ 14001421c =====

ulonglong Feature_SMST__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_SMST__private_featureState;
  if ((Feature_SMST__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SMST__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SMST__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SMST__private_IsEnabledFallback @ 140014254 =====

void Feature_SMST__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14001426c =====

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
LAB_14001446f:
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
LAB_140014347:
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
      if (param_3 == 4) goto LAB_14001446f;
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
        goto LAB_140014347;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140014558 =====

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
      goto LAB_14001461b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14001461b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14001461b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14001461b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14001461b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14001461b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14001461b;
    }
  }
  uVar2 = 0xff;
LAB_14001461b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3803791,&Feature_Standalone_Future_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140014674 =====

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
                     (local_50,&Feature_SMST__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3803791,param_3,1,&Feature_SMST__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3803791);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140014760 =====

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
LAB_140014813:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140014841;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140014813;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140014841:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400149cc =====

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
  if ((Feature_SMST__private_featureState & 2) != 0) {
    uVar1 = Feature_SMST__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_SMST__private_featureState;
      if (bVar3) {
        Feature_SMST__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_SMST__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140014a20 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_SMST__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_SMST__private_featureState,(ulonglong)param_1,0x14001c160);
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



===== <lambda_invoker_cdecl> @ 140014ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_9395206af589ac42132775cb7e45a067>::<lambda_invoker_cdecl>
               (undefined8 param_1,longlong param_2)

{
  (**(code **)(param_2 + 0x10))(*(undefined8 *)(param_2 + 0x18));
  return;
}



===== ~Worker @ 140014ad0 =====

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



===== InitializeTelemetryAssertsKMWorkerInternal @ 140014b10 =====

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
    _DAT_14001d718 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140021040);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140021008);
    TraceLoggingRegister_EtwRegister_EtwSetInformation(0x140021078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 140014bc4 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,0,param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140014bf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140014dbd) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
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
  longlong *plVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined1 *puVar14;
  char *pcVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  char *pcVar18;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [116];
  undefined4 local_12c;
  undefined4 local_128 [2];
  IMAGE_DOS_HEADER *local_120;
  undefined1 local_118 [32];
  undefined4 *local_f8;
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
  
  puVar14 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_14001524a;
  local_12c = param_4;
  local_120 = param_1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar14 = auStack_1a8;
  for (plVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar9 != &g_MicrosoftTelemetryAssertsTriggeredList; plVar9 = (longlong *)*plVar9
      ) {
    plVar8 = plVar9 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar8 == param_1) goto LAB_140014d44;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar13 = _DAT_fffff78000000320;
  puVar14 = auStack_1a8;
  if (plVar8 != (longlong *)0x0) {
    *plVar8 = (longlong)param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar14 = auStack_1a8;
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
      puVar14 = auStack_1a0;
    }
    *plVar9 = (longlong)plVar11;
    plVar9[1] = (longlong)puVar12;
    plVar11[1] = (longlong)plVar9;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar9;
LAB_140014d44:
    *(int *)(plVar8 + 2) = (int)plVar8[2] + 1;
    *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
    lVar13 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar14 + -8) = 0x140014d54;
    uVar6 = KeQueryTimeIncrement();
    lVar13 = (longlong)((ulonglong)uVar6 * lVar13) / 10000;
    if (60000 < (ulonglong)(lVar13 - plVar8[1])) {
      if ((param_1 < &IMAGE_DOS_HEADER_140000000) || ((IMAGE_DOS_HEADER *)0x140030000 < param_1)) {
        uVar6 = 0;
      }
      else {
        uVar6 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar14 + 0x74) = (int)plVar8[2];
      *(undefined4 *)(puVar14 + 0x78) = *(undefined4 *)((longlong)plVar8 + 0x14);
      plVar8[1] = lVar13;
      *(int *)(puVar14 + 0x70) = (int)plVar8[3];
      *(undefined8 *)(puVar14 + -8) = 0x140014e07;
      KeReleaseSpinLock(&g_AssertSpinLock,CONCAT71((int7)((ulonglong)lVar13 >> 8),uVar3));
      pcVar15 = g_ModuleName;
      pcVar18 = "<unknown>";
      lVar13 = -1;
      uVar16 = 0x400000000000;
      if (5 < DAT_140021040) {
        if (((_DAT_140021050 & 0x400000000000) == 0) ||
           ((DAT_140021058 & 0x400000000000) != DAT_140021058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_f8 = local_128;
          local_128[0] = 10;
          local_e8 = puVar14 + 0x50;
          local_f0 = 4;
          local_d8 = puVar14 + 0x54;
          *(uint *)(puVar14 + 0x50) = uVar6;
          local_b8 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            local_b8 = g_ModuleName;
          }
          local_c8 = puVar14 + 0x58;
          local_e0 = 4;
          lVar10 = -1;
          *(dword *)(puVar14 + 0x54) = 0xedc368b1;
          local_d0 = 4;
          *(dword *)(puVar14 + 0x58) = 0x30000;
          local_c0 = 4;
          do {
            lVar10 = lVar10 + 1;
          } while (local_b8[lVar10] != '\0');
          local_b0 = (int)lVar10 + 1;
          *(undefined4 *)(puVar14 + 0x5c) = *(undefined4 *)(puVar14 + 0x74);
          local_a8 = puVar14 + 0x5c;
          *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x78);
          local_98 = puVar14 + 0x60;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar14 + -8) = 0x140014f18;
          bVar4 = KeGetCurrentIrql();
          local_80 = 4;
          *(uint *)(puVar14 + 100) = (uint)bVar4;
          local_88 = puVar14 + 100;
          if (pcVar15 == (char *)0x0) {
            local_78 = "";
            local_70 = 1;
          }
          else {
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (pcVar15[lVar10] != '\0');
            local_70 = (int)lVar10 + 1;
            local_78 = pcVar15;
          }
          *(undefined4 *)(puVar14 + 0x68) = *(undefined4 *)(puVar14 + 0x7c);
          local_68 = puVar14 + 0x68;
          *(undefined4 *)(puVar14 + 0x6c) = param_5;
          local_58 = puVar14 + 0x6c;
          if (param_6 == (char *)0x0) {
            param_6 = "<unknown>";
          }
          local_6c = 0;
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
          *(undefined1 **)(puVar14 + 0x28) = local_118;
          *(undefined4 *)(puVar14 + 0x20) = 0xe;
          local_3c = 0;
          *(undefined8 *)(puVar14 + -8) = 0x140014fed;
          local_48 = param_6;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_78,&DAT_14001a911,uVar16,pcVar18,*(undefined4 *)(puVar14 + 0x20),
                     *(undefined8 **)(puVar14 + 0x28));
        }
      }
      if ((DAT_140021078 == 0) || (*(int *)(puVar14 + 0x70) != 0)) goto LAB_14001524a;
      *(undefined8 *)(puVar14 + -8) = 0x14001500e;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_14001524a;
      *(undefined4 *)(puVar14 + 0x40) = 0;
      *(undefined8 *)(puVar14 + 0x38) = 0;
      *(undefined8 *)(puVar14 + 0x30) = 0;
      *(undefined8 *)(puVar14 + 0x28) = 0x30000;
      *(undefined8 *)(puVar14 + 0x20) = 0xedc368b1;
      uVar17 = (ulonglong)uVar6;
      *(undefined8 *)(puVar14 + -8) = 0x140015056;
      pcVar18 = g_ModuleName;
      iVar7 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_140021040) {
        if (((_DAT_140021050 & 0x400000000000) == 0) ||
           ((DAT_140021058 & 0x400000000000) != DAT_140021058)) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        if (bVar2) {
          local_f8 = (undefined4 *)(puVar14 + 0x70);
          local_e8 = puVar14 + 0x6c;
          local_d8 = puVar14 + 0x68;
          local_c8 = puVar14 + 100;
          *(undefined4 *)(puVar14 + 0x70) = 10;
          local_f0 = 4;
          *(uint *)(puVar14 + 0x6c) = uVar6;
          local_e0 = 4;
          *(dword *)(puVar14 + 0x68) = 0xedc368b1;
          local_d0 = 4;
          *(dword *)(puVar14 + 100) = 0x30000;
          local_c0 = 4;
          local_b8 = g_ModuleName;
          if (g_ModuleName == (char *)0x0) {
            local_b8 = "<unknown>";
          }
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (local_b8[lVar10] != '\0');
          local_b0 = (int)lVar10 + 1;
          *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x74);
          local_a8 = puVar14 + 0x60;
          *(undefined4 *)(puVar14 + 0x5c) = *(undefined4 *)(puVar14 + 0x78);
          local_98 = puVar14 + 0x5c;
          local_88 = puVar14 + 0x58;
          local_ac = 0;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar14 + 0x58) = iVar7;
          local_80 = 4;
          if (pcVar15 == (char *)0x0) {
            pcVar15 = "";
            local_70 = 1;
          }
          else {
            do {
              lVar13 = lVar13 + 1;
            } while (pcVar15[lVar13] != '\0');
            local_70 = (int)lVar13 + 1;
          }
          *(undefined4 *)(puVar14 + 0x54) = *(undefined4 *)(puVar14 + 0x7c);
          local_68 = puVar14 + 0x54;
          *(undefined4 *)(puVar14 + 0x50) = param_5;
          local_58 = puVar14 + 0x50;
          *(undefined1 **)(puVar14 + 0x28) = local_118;
          *(undefined4 *)(puVar14 + 0x20) = 0xd;
          local_6c = 0;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar14 + -8) = 0x1400151ed;
          local_78 = pcVar15;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_b8,&DAT_14001a9bb,uVar17,pcVar18,*(undefined4 *)(puVar14 + 0x20),
                     *(undefined8 **)(puVar14 + 0x28));
        }
      }
      if (iVar7 != 0) goto LAB_14001524a;
      *(undefined8 *)(puVar14 + -8) = 0x1400151ff;
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
  *(undefined8 *)(puVar14 + -8) = 0x140015245;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_14001524a:
  *(undefined8 *)(puVar14 + -8) = 0x140015256;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140015280 =====

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
    *(undefined8 *)(puVar6 + -8) = 0x140015313;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140015330;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_140021098;
    DAT_140021098 = 0;
    DAT_140021078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001535a;
    EtwUnregister(uVar3);
    uVar3 = DAT_140021028;
    DAT_140021028 = 0;
    _DAT_140021008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001537c;
    EtwUnregister(uVar3);
    uVar3 = DAT_140021060;
    DAT_140021060 = 0;
    DAT_140021040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x14001539e;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 1400153b8 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== _guard_check_icall @ 1400153d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400153e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001540c =====

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



===== __GSHandlerCheck_SEH @ 140015474 =====

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



===== __cpu_features_init @ 140015510 =====

/* WARNING: Removing unreachable block (ram,0x00014001557a) */
/* WARNING: Removing unreachable block (ram,0x000140015529) */
/* WARNING: Removing unreachable block (ram,0x00014001551a) */

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



===== __security_check_cookie @ 1400155e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140015620 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140015650 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140015650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140015680 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140015700 =====

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



===== memset @ 140015a00 =====

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



===== __memset_repmovs @ 140015b40 =====

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



===== __memset_query @ 140015bc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140015c40 =====

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
        if (param_3 != &DAT_00000001) {
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



===== __memset_spec_ermsb_repmovsb @ 140015d80 =====

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



===== __memset_spec_plain @ 140015e00 =====

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
        if (param_3 != &DAT_00000001) {
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



===== Initialize @ 140022008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiCx::CommandHandler::Initialize(struct _UCMUCSI_PPM_CONFIG *
   __ptr64,class UcmUcsiCx::Ppm * __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::CommandHandler::Initialize
          (CommandHandler *this,_UCMUCSI_PPM_CONFIG *param_1,Ppm *param_2)

{
  long lVar1;
  CxDevice *pCVar2;
  _UCMUCSI_PPM_CONFIG *p_Var3;
  undefined8 *puVar4;
  undefined2 uVar5;
  _func_void_Ppm_ptr_long *in_R9;
  int iVar6;
  undefined8 local_res8;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_88;
  code *pcStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  longlong local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  p_Var3 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R9 = (_func_void_Ppm_ptr_long *)0xa;
    p_Var3 = (_UCMUCSI_PPM_CONFIG *)CONCAT71((int7)((ulonglong)param_1 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,10,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  local_res8 = 0;
  this->m_Ppm = param_2;
  local_30 = 0;
  local_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_88 = 0;
  pcStack_80 = (code *)0x0;
  local_78 = 0;
  uStack_70 = 0;
  lVar1 = PpmInterface::Initialize(&this->m_PpmInterface,p_Var3,param_2,in_R9);
  if (lVar1 < 0) goto LAB_140022443;
  local_60 = CONCAT44(local_60._4_4_,0x38);
  uStack_48 = 0x100000001;
  local_40 = this->m_Ppm->_padding_;
  pcStack_80 = EvtCommandTimerFuncThunk;
  local_78 = CONCAT35(local_78._5_3_,0x100000000);
  local_88 = CONCAT44(local_88._4_4_,0x28);
  uStack_70 = uStack_70 & 0xffffffff00000000;
  lVar1 = (**(code **)(WdfFunctions_01023 + 0x9f0))
                    (WdfDriverGlobals,&local_88,&local_60,&this->m_CommandTimer);
  if (lVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar5 = 0xb;
  }
  else {
    local_30 = 0;
    local_50 = 0;
    uStack_48 = 0x100000001;
    uStack_58 = 0;
    local_60 = 0x38;
    uStack_38 = 0;
    local_40 = this->m_Ppm->_padding_;
    lVar1 = (**(code **)(WdfFunctions_01023 + 0x9d8))
                      (WdfDriverGlobals,&local_60,&this->m_CachedCommandDataLock);
    if (lVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar1;
      }
      uVar5 = 0xc;
    }
    else {
      lVar1 = (**(code **)(WdfFunctions_01023 + 0x9d8))
                        (WdfDriverGlobals,&local_60,&this->m_UnrecoverableFailureContextLock);
      if (-1 < lVar1) {
        iVar6 = param_1->UcsiMaxDataLength + 0x18;
        local_40 = this->m_Ppm->_padding_;
        puVar4 = &local_60;
        lVar1 = (**(code **)(WdfFunctions_01023 + 0x600))
                          (WdfDriverGlobals,puVar4,0x200,0,iVar6,&local_res8,&this->m_InSendExParam)
        ;
        if (lVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140022443;
          uVar5 = 0xe;
        }
        else {
          iVar6 = param_1->UcsiMaxDataLength + 0x10;
          puVar4 = &local_60;
          lVar1 = (**(code **)(WdfFunctions_01023 + 0x600))
                            (WdfDriverGlobals,puVar4,0x200,0,iVar6,&local_res8,&this->m_OutExParam);
          if (-1 < lVar1) {
            (**(code **)(WdfFunctions_01023 + 0x668))
                      (WdfDriverGlobals,param_2->_padding_,0,0x72,
                       "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp");
            pCVar2 = Ppm::GetCxDevice(this->m_Ppm);
            local_98 = (**(code **)(WdfFunctions_01023 + 0xf8))(WdfDriverGlobals,pCVar2->_padding_);
            local_90 = 0x78435555;
            lVar1 = CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::Initialize
                              ((CommandHandlerStateMachine<UcmUcsiCx::CommandHandler> *)this,
                               (StateMachineEngineConfig *)&local_98);
            if (lVar1 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar5 = 0x10;
LAB_1400223de:
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar5,
                                   &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                                   (char)this->m_Ppm->_padding_,(char)lVar1);
              }
            }
            else {
              lVar1 = CommandList::Initialize(&this->m_CommandList,param_2);
              if (-1 < lVar1) goto LAB_140022443;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar5 = 0x11;
                goto LAB_1400223de;
              }
            }
            (**(code **)(WdfFunctions_01023 + 0x670))
                      (WdfDriverGlobals,this->m_Ppm->_padding_,0,0x89,
                       "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\commandhandler.cpp");
            goto LAB_140022443;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140022443;
          uVar5 = 0xf;
        }
        WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,3,uVar5,
                            &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,
                            (char)this->m_Ppm->_padding_,(char)iVar6,(char)lVar1);
        goto LAB_140022443;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar1;
      }
      uVar5 = 0xd;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar5,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids,(char)this->m_Ppm->_padding_,
                     (char)lVar1);
LAB_140022443:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x12,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return lVar1;
}



===== RequestUCSIDataFromPpm @ 1400224a0 =====

/* private: void __cdecl UcmUcsiCx::CommandHandler::RequestUCSIDataFromPpm(void) __ptr64 */

void __thiscall UcmUcsiCx::CommandHandler::RequestUCSIDataFromPpm(CommandHandler *this)

{
  <unnamed_type_m_InBuffer> *p<Var1;
  _WDF_TRI_STATE _Var2;
  undefined8 local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3b,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  local_res8 = 0xfffffffffffcf2c0;
  KeDelayExecutionThread(0,0,&local_res8);
  p<Var1 = &this->m_InBuffer;
  _Var2 = (this->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled;
  (p<Var1->m_InSendParam).PpmObject = (UCMUCSIPPM__ *)this->m_Ppm->_padding_;
  if (_Var2 == WdfTrue) {
    PpmInterface::GetUcsiDataEx(&this->m_PpmInterface,&p<Var1->m_InGetParam,this->m_OutExParam);
  }
  else {
    PpmInterface::GetUcsiData(&this->m_PpmInterface,&p<Var1->m_InGetParam,&this->m_OutParam);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x3c,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  return;
}



===== CreateAndInitialize @ 140022594 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::CxDevice::CreateAndInitialize(struct
   _UCMUCSI_DRIVER_GLOBALS * __ptr64,struct WDFDEVICE__ * __ptr64,struct _UCMUCSI_DEVICE_CONFIG *
   __ptr64) */

long __cdecl
UcmUcsiCx::CxDevice::CreateAndInitialize
          (_UCMUCSI_DRIVER_GLOBALS *param_1,WDFDEVICE__ *param_2,_UCMUCSI_DEVICE_CONFIG *param_3)

{
  int iVar1;
  CxDevice *this;
  _UCMUCSI_DEVICE_CONFIG *p_Var2;
  CxDevice *local_res18;
  undefined8 local_68;
  code *local_60;
  code *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined *local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    local_res18 = (CxDevice *)param_3;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  p_Var2 = (_UCMUCSI_DEVICE_CONFIG *)&local_68;
  local_38 = PTR__WDF_CxDevice_TYPE_INFO_14001d0a0;
  local_res18 = (CxDevice *)0x0;
  local_60 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiCx::CxDevice>::
             EvtObjectContextCleanupThunk;
  local_68 = 0x38;
  local_58 = WdfCpp::ObjectContext<WDFDEVICE__*___ptr64,UcmUcsiCx::CxDevice>::
             EvtObjectContextDestroyThunk;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 1;
  local_4c = 1;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x658))(WdfDriverGlobals,param_2,p_Var2,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                       &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)param_2,(char)iVar1);
  }
  else {
    if (local_res18 == (CxDevice *)0x0) {
      this = (CxDevice *)0x0;
    }
    else {
      this = (CxDevice *)CxDevice(local_res18,param_2);
    }
    iVar1 = Initialize(this,param_1,p_Var2);
    if (iVar1 < 0) {
      if (this != (CxDevice *)0x0) {
        Deinitialize(this);
      }
    }
    else {
      iVar1 = 0;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xc,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return iVar1;
}



===== Deinitialize @ 14002273c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::CxDevice::Deinitialize(void) __ptr64 */

void __thiscall UcmUcsiCx::CxDevice::Deinitialize(CxDevice *this)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  uVar1 = (**(code **)(WdfFunctions_01023 + 0xdc0))(WdfDriverGlobals,this->_padding_);
  (**(code **)(WdfFunctions_01023 + 0xd20))(WdfDriverGlobals,uVar1,1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x1a,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return;
}



===== DeleteDeviceProblemDescProperty @ 140022818 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::CxDevice::DeleteDeviceProblemDescProperty(void) __ptr64 */

void __thiscall UcmUcsiCx::CxDevice::DeleteDeviceProblemDescProperty(CxDevice *this)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar3;
  undefined8 in_stack_ffffffffffffffe0;
  uint uVar4;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  uVar4 = (uint)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x36,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01023 + 0x108))(WdfDriverGlobals,this->_padding_);
  iVar1 = IoSetDevicePropertyData
                    (uVar2,&DEVPKEY_Device_DriverProblemDesc,0,0,CONCAT44(uVar3,0x19),
                     (ulonglong)uVar4 << 0x20,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x37,
                       &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_,
                       (char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x38,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return;
}



===== DeviceInitInitialize @ 140022940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::CxDevice::DeviceInitInitialize(struct WDFDEVICE_INIT *
   __ptr64) */

long __cdecl UcmUcsiCx::CxDevice::DeviceInitInitialize(WDFDEVICE_INIT *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 local_res10 [8];
  undefined4 local_e8 [30];
  code *local_70;
  code *local_68;
  code *local_50;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xd,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  memset(local_e8,0,200);
  (**(code **)(WdfFunctions_01023 + 0xdc8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01023 + 0xc60))(WdfDriverGlobals,param_1);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xe,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,0x9a);
    }
    Verify::Break();
  }
  else {
    local_70 = EvtCxDevicePostSelfManagedIoInit;
    local_e8[0] = 200;
    local_50 = EvtCxDevicePreSelfManagedIoSuspend;
    local_68 = EvtCxDevicePreSelfManagedIoRestart;
    (**(code **)(WdfFunctions_01023 + 0xde8))(WdfDriverGlobals,lVar2,local_e8);
    local_res10[0] = 2;
    iVar1 = (**(code **)(WdfFunctions_01023 + 0xc68))
                      (WdfDriverGlobals,lVar2,EvtDeviceWdmPreprocessSetPowerIrp,0x16,local_res10,1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xf,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x10,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return iVar1;
}



===== EvtObjectContextCleanup @ 140022b44 =====

/* private: void __cdecl UcmUcsiCx::CxDevice::EvtObjectContextCleanup(void) __ptr64 */

void __thiscall UcmUcsiCx::CxDevice::EvtObjectContextCleanup(CxDevice *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x20,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  Deinitialize(this);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x21,
                      &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x22,
                       &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
    }
  }
  return;
}



===== Initialize @ 140022c18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl UcmUcsiCx::CxDevice::Initialize(struct _UCMUCSI_DRIVER_GLOBALS *
   __ptr64,struct _UCMUCSI_DEVICE_CONFIG * __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::CxDevice::Initialize
          (CxDevice *this,_UCMUCSI_DRIVER_GLOBALS *param_1,_UCMUCSI_DEVICE_CONFIG *param_2)

{
  longlong lVar1;
  WDFQUEUE__ *pWVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  _UCMUCSI_PRIVATE_DRIVER_GLOBALS *p_Var7;
  undefined8 uVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  undefined2 uVar11;
  undefined4 extraout_XMM0_Da;
  undefined4 extraout_XMM0_Db;
  undefined4 extraout_XMM0_Dc;
  undefined4 extraout_XMM0_Dd;
  undefined1 auStackY_388 [32];
  undefined1 uVar12;
  undefined8 local_340;
  undefined *puStack_338;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  longlong local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  wchar_t *local_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined4 local_2a8;
  undefined8 local_2a4;
  code *local_298;
  undefined4 local_258;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_388;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x11,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  lVar1 = this->_padding_;
  local_330 = 0;
  local_318 = 0;
  local_2c8 = L"ACPI";
  local_340 = 0;
  puStack_338 = (undefined *)0x0;
  local_320 = 0;
  local_2d0 = 0xa0008;
  local_2c0 = 0;
  uStack_2b8 = 0;
  p_Var7 = Driver::GetPrivateGlobals(param_1);
  local_2f8 = CONCAT44(extraout_XMM0_Db,extraout_XMM0_Da);
  this->m_PrivateGlobals = p_Var7;
  uStack_300 = CONCAT44(extraout_XMM0_Dd,extraout_XMM0_Dc);
  local_2d8 = 0;
  uStack_2e0 = CONCAT44(extraout_XMM0_Dd,extraout_XMM0_Dc);
  local_308 = CONCAT44(extraout_XMM0_Db,0x38);
  uStack_2f0 = 0x100000001;
  local_2e8 = lVar1;
  memset(&local_2a8,0,0x60);
  local_258 = 0xffffffff;
  local_298 = EvtIoDefaultThunk;
  local_2a8 = 0x60;
  local_2a4 = 2;
  iVar6 = (**(code **)(WdfFunctions_01023 + 0x4c0))(WdfDriverGlobals,lVar1,&local_2a8,&local_308);
  uVar12 = (undefined1)lVar1;
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    uVar11 = 0x12;
  }
  else {
    pWVar2 = this->m_SelfIoTargetQueue;
    uVar8 = (**(code **)(WdfFunctions_01023 + 0xdc0))(WdfDriverGlobals,lVar1);
    iVar6 = (**(code **)(WdfFunctions_01023 + 0xdd0))(WdfDriverGlobals,uVar8,pWVar2);
    if (iVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar6;
      }
      uVar11 = 0x13;
    }
    else {
      local_318 = 0x200000008;
      iVar6 = (*UcmFunctions)(UcmDriverGlobals,lVar1,&local_318);
      if (-1 < iVar6) {
        TestInterface::Initialize(&this->m_TestInterface,this);
        local_340 = 0x18;
        puStack_338 = &DEVPKEY_Device_EnumeratorName;
        local_330 = 0;
        iVar6 = (**(code **)(WdfFunctions_01023 + 0xd88))(WdfDriverGlobals,lVar1,&local_340,0x200);
        if (iVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x15,
                               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar12,(char)iVar6);
          }
LAB_140022f27:
          bVar4 = Verify::IsForceCrashOnCommandFailureEnabled((WDFDEVICE__ *)this->_padding_);
        }
        else {
          RtlInitUnicodeString(&local_2c0,local_248);
          cVar3 = RtlEqualUnicodeString(&local_2c0,&local_2d0,1);
          if (cVar3 != '\0') goto LAB_140022f27;
          lVar9 = (**(code **)(WdfFunctions_01023 + 0xf8))(WdfDriverGlobals,lVar1);
          iVar6 = MmIsDriverVerifying(*(undefined8 *)(lVar9 + 8));
          if (iVar6 == 0) {
            bVar5 = Verify::IsForceCrashOnCommandFailureEnabled((WDFDEVICE__ *)this->_padding_);
            bVar4 = false;
            if (bVar5) goto LAB_140022f71;
          }
          else {
LAB_140022f71:
            bVar4 = true;
          }
        }
        this->m_IsBugcheckOnCommandFailureEnabled = bVar4;
        puStack_338 = &DEVPKEY_Device_InstanceId;
        local_2d8 = 0;
        local_2f8 = 0;
        local_328 = 0;
        uStack_300 = 0;
        local_340 = 0x18;
        uStack_2e0 = 0;
        local_330 = 0;
        local_308 = 0x38;
        uStack_2f0 = 0x100000001;
        local_2e8 = lVar1;
        iVar6 = (**(code **)(WdfFunctions_01023 + 0xd90))(WdfDriverGlobals,lVar1,&local_340,0x200);
        if (iVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x16,
                               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar12,(char)iVar6);
          }
        }
        else {
          local_310 = 0;
          pwVar10 = (wchar_t *)
                    (**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,local_328,&local_310)
          ;
          this->m_deviceInstanceId = pwVar10;
        }
        local_340 = 0x18;
        local_2f8 = 0;
        local_330 = 0;
        puStack_338 = &DEVPKEY_Device_Service;
        local_2d8 = 0;
        uStack_300 = 0;
        local_308 = 0x38;
        uStack_2e0 = 0;
        uStack_2f0 = 0x100000001;
        local_2e8 = lVar1;
        iVar6 = (**(code **)(WdfFunctions_01023 + 0xd90))(WdfDriverGlobals,lVar1,&local_340,0x200);
        if (iVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x17,
                               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar12,(char)iVar6);
          }
        }
        else {
          local_310 = 0;
          pwVar10 = (wchar_t *)
                    (**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,local_328,&local_310)
          ;
          this->m_deviceServiceName = pwVar10;
        }
        iVar6 = 0;
        goto LAB_140023158;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar6;
      }
      uVar11 = 0x14;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,uVar12,(char)iVar6);
LAB_140023158:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x18,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return iVar6;
}



===== SetDeviceProblemDescProperty @ 1400231bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl UcmUcsiCx::CxDevice::SetDeviceProblemDescProperty(unsigned long,enum
   _UCSI_COMMAND,long,unsigned char) __ptr64 */

void __thiscall
UcmUcsiCx::CxDevice::SetDeviceProblemDescProperty
          (CxDevice *this,ulong param_1,_UCSI_COMMAND param_2,long param_3,uchar param_4)

{
  undefined1 auVar1 [16];
  ushort *puVar2;
  undefined1 uVar3;
  int iVar4;
  long lVar5;
  longlong lVar6;
  short *psVar7;
  __uint64 _Var8;
  ushort *puVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  undefined1 auStackY_f8 [32];
  wchar_t local_98 [32];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_f8;
  builtin_wcsncpy(local_98,L"@System32\\drivers\\UcmUcsiCx.sys",0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2c,
                       &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2d,
                         &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_,
                         (char)param_1);
    }
  }
  lVar6 = (**(code **)(WdfFunctions_01023 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  iVar4 = RtlFindMessage(*(undefined8 *)(lVar6 + 0x18),0xb,0,param_1);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar13 = 0x2e;
  }
  else {
    if (0xfffffffe < (ulonglong)uRam0000000000000000 - 4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar13 = 0x2f;
LAB_140023326:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_);
      goto LAB_1400235da;
    }
    psVar7 = (short *)0x4;
    uVar11 = (ulonglong)uRam0000000000000000 - 4 >> 1;
    uVar12 = uVar11;
    if (uVar11 < 0x80000000) {
      for (; (uVar12 != 0 && (*psVar7 != 0)); psVar7 = psVar7 + 1) {
        uVar12 = uVar12 - 1;
      }
      if (uVar12 != 0) {
        uVar12 = (uVar11 - uVar12) * 2 + 0xb2;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = uVar12;
        _Var8 = SUB168(ZEXT816(2) * auVar1,0);
        if (SUB168(ZEXT816(2) * auVar1,8) != 0) {
          _Var8 = 0xffffffffffffffff;
        }
        puVar9 = operator_new__(_Var8);
        if (puVar9 == (ushort *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return;
          }
          uVar13 = 0x31;
          goto LAB_140023326;
        }
        UcsiCommandToString(param_2);
        lVar5 = RtlStringCbPrintfW(puVar9,uVar12,(ushort *)L"%s,#%d;%s;(%s,0x%08x,%u)",local_98);
        if (lVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x32;
LAB_140023468:
            uVar3 = (undefined1)lVar5;
LAB_14002346c:
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                               &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,
                               (char)this->_padding_,uVar3);
          }
        }
        else {
          uVar12 = uVar12 >> 1;
          puVar2 = puVar9;
          if (uVar12 < 0x80000000) {
            for (; (uVar12 != 0 && (*puVar2 != 0)); puVar2 = puVar2 + 1) {
              uVar12 = uVar12 - 1;
            }
            if (uVar12 != 0) {
              uVar10 = (**(code **)(WdfFunctions_01023 + 0x108))(WdfDriverGlobals,this->_padding_);
              lVar5 = IoSetDevicePropertyData(uVar10,&DEVPKEY_Device_DriverProblemDesc,0,0);
              if ((lVar5 < 0) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                uVar13 = 0x34;
                goto LAB_140023468;
              }
              goto LAB_140023585;
            }
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x33;
            uVar3 = 0xd;
            goto LAB_14002346c;
          }
        }
LAB_140023585:
        operator_delete__(puVar9);
        goto LAB_1400235da;
      }
    }
    iVar4 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar13 = 0x30;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_,
                     (char)iVar4);
LAB_1400235da:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x35,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return;
}



===== UcsiCommandToString @ 140023638 =====

/* private: static unsigned short const * __ptr64 __cdecl
   UcmUcsiCx::CxDevice::UcsiCommandToString(enum _UCSI_COMMAND) */

ushort * __cdecl UcmUcsiCx::CxDevice::UcsiCommandToString(_UCSI_COMMAND param_1)

{
  if ((int)param_1 < 0xc) {
    if (param_1 == UcsiCommandSetPdr) {
      return (ushort *)L"SetPdr";
    }
    if ((int)param_1 < 7) {
      if (param_1 == UcsiCommandGetCapability) {
        return (ushort *)L"GetCapability";
      }
      if (param_1 == UcsiCommandPpmReset) {
        return (ushort *)L"PpmReset";
      }
      if (param_1 == UcsiCommandCancel) {
        return (ushort *)L"Cancel";
      }
      if (param_1 == UcsiCommandConnectorReset) {
        return (ushort *)L"ConnectorReset";
      }
      if (param_1 == UcsiCommandAckCcCi) {
        return (ushort *)L"AckCcCi";
      }
      if (param_1 == UcsiCommandSetNotificationEnable) {
        return (ushort *)L"SetNotificationEnable";
      }
    }
    else {
      if (param_1 == UcsiCommandGetConnectorCapability) {
        return (ushort *)L"GetConnectorCapability";
      }
      if (param_1 == UcsiCommandSetUom) {
        return (ushort *)L"SetUom";
      }
      if (param_1 == UcsiCommandSetUor) {
        return (ushort *)L"SetUor";
      }
      if (param_1 == UcsiCommandSetPdm) {
        return (ushort *)L"SetPdm";
      }
    }
  }
  else {
    if (param_1 == UcsiCommandGetAlternateModes) {
      return (ushort *)L"GetAlternateModes";
    }
    if (param_1 == UcsiCommandGetCamSupported) {
      return (ushort *)L"GetCamSupported";
    }
    if (param_1 == UcsiCommandGetCurrentCam) {
      return (ushort *)L"GetCurrentCam";
    }
    if (param_1 == UcsiCommandSetNewCam) {
      return (ushort *)L"SetNewCam";
    }
    if (param_1 == UcsiCommandGetPdos) {
      return (ushort *)L"GetPdos";
    }
    if (param_1 == UcsiCommandGetCableProperty) {
      return (ushort *)L"GetCableProperty";
    }
    if (param_1 == UcsiCommandGetConnectorStatus) {
      return (ushort *)L"GetConnectorStatus";
    }
    if (param_1 == UcsiCommandGetErrorStatus) {
      return (ushort *)L"GetErrorStatus";
    }
    if (param_1 == UcsiCommandSetPowerLevel) {
      return (ushort *)L"SetPowerLevel";
    }
  }
  return (ushort *)L"UnrecognizedCommand";
}



===== UnrecoverableFailureEncountered @ 140023770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::CxDevice::UnrecoverableFailureEncountered(struct
   UcmUcsiCx::UnrecoverableFailureContext const & __ptr64) __ptr64 */

void __thiscall
UcmUcsiCx::CxDevice::UnrecoverableFailureEncountered
          (CxDevice *this,UnrecoverableFailureContext *param_1)

{
  LkdFailureType LVar1;
  LkdFailureSubType LVar2;
  bool bVar3;
  bool bVar4;
  Opm *this_00;
  _UCSI_COMMAND _Var5;
  ulong uVar6;
  Event EVar7;
  long lVar8;
  int iVar9;
  uchar uVar10;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x29,
                       &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2a,
                        &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids,(char)this->_padding_);
    }
  }
  Verify::Break();
  LVar1 = param_1->Type;
  if (LVar1 == CommandTimeout) {
    bVar4 = true;
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_1->Status != 0x102)) {
      RtlAssert("FailureContext.Status == ((NTSTATUS)0x00000102L)",
                "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x24b,0);
    }
    uVar6 = 0xc0010000;
LAB_14002392f:
    bVar3 = true;
    iVar9 = param_1->Status;
LAB_140023933:
    _Var5 = param_1->UcsiCommandForPpm;
    uVar10 = '\0';
  }
  else {
    if (LVar1 == CommandExecutionFailed) {
      LVar2 = param_1->SubType;
      bVar4 = false;
      bVar3 = true;
      if (LVar2 != InvalidCciDataLength) {
        if ((LVar2 != CommandCompletedWithErrorIndicator) &&
           (LVar2 != CommandCompletedWithNotSupportedIndicator)) {
          if (LVar2 == CommandCompletedOutOfSync) {
            DeleteDeviceProblemDescProperty(this);
          }
          goto LAB_140023944;
        }
        uVar6 = 0xc0010004;
        goto LAB_14002392f;
      }
      iVar9 = 0;
      uVar6 = 0xc0010003;
      goto LAB_140023933;
    }
    if (LVar1 != IncorrectConnectorNumber) {
      if (LVar1 != HwRequestFailedByClient) {
        if ((LVar1 != TestSimulatedFailure) && ((*(uint *)(WdfDriverGlobals + 8) & 4) != 0)) {
          RtlAssert("false","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\cxdevice.cpp",0x2aa,0);
        }
        bVar4 = false;
        bVar3 = false;
        goto LAB_140023944;
      }
      iVar9 = param_1->Status;
      bVar4 = true;
      if ((iVar9 == -0x3fffff63) || (bVar3 = true, iVar9 == -0x3ffffff2)) {
        bVar3 = false;
      }
      uVar6 = 0xc0010001;
      goto LAB_140023933;
    }
    uVar10 = param_1->ConnectorNumber;
    iVar9 = 0;
    _Var5 = 0;
    bVar4 = false;
    bVar3 = true;
    uVar6 = 0xc0010002;
  }
  SetDeviceProblemDescProperty(this,uVar6,_Var5,iVar9,uVar10);
LAB_140023944:
  if ((Microsoft_Windows_USB_UCMUCSICXEnableBits & 1) != 0) {
    McTemplateK0zzqqqqq_EtwWriteTransfer();
  }
  if (bVar3) {
    GenerateUcsiFailureDump
              ((WDFDEVICE__ *)this->_padding_,param_1->UcsiCommandForPpm,param_1->Type,
               param_1->Status,this->m_IsBugcheckOnCommandFailureEnabled);
  }
  _Var5 = param_1->UcsiCommandForPpm & 0xff;
  MicrosoftTelemetryAssertTriggeredArgsMsgKM
            ((ulonglong)_Var5,
             ((param_1->SubType & 0xff | param_1->Type << 8) << 8 | param_1->UcsiCommandInOpm & 0xff
             ) << 8 | _Var5,param_1->Status,"UnrecoverableFailure2");
  TestInterface::PurgeQueue(&this->m_TestInterface);
  if (bVar4) {
    EVar7 = 0x11;
    this_00 = Ppm::GetOpm(this->m_Ppm);
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this_00,EVar7);
    lVar8 = param_1->Status;
  }
  else {
    lVar8 = -0x3ffffe7c;
  }
  TestInterface::CompleteExistingCommand(&this->m_TestInterface,lVar8);
  Ppm::EvtPowerOnComplete(this->m_Ppm);
  Ppm::EvtPowerOffComplete(this->m_Ppm);
  (**(code **)(WdfFunctions_01023 + 0x2b8))(WdfDriverGlobals,this->_padding_,1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x2b,
                     &WPP_eda9072c037939d992e9c19cdadfb869_Traceguids);
  }
  return;
}



===== BindClassExtensionClient @ 140023aa0 =====

/* private: static long __cdecl UcmUcsiCx::Driver::BindClassExtensionClient(struct
   _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 * __ptr64) */

long __cdecl
UcmUcsiCx::Driver::BindClassExtensionClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  ulong uVar1;
  ulong uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  long lVar6;
  ulong uVar7;
  __uint64 _Var8;
  undefined1 uVar9;
  
  uVar9 = SUB81(param_1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x17,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qDDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x18,
                 &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,uVar9,(char)DAT_14001d034,
                 (char)param_1->FunctionTableCount,(char)(param_1->Version).Major,
                 (char)(param_1->Version).Minor);
    }
  }
  uVar1 = (param_1->Version).Major;
  if (uVar1 == s_WdfClassLibraryInfo.Version.Major) {
    uVar2 = (param_1->Version).Minor;
    if (uVar2 == s_WdfClassLibraryInfo.Version.Minor) {
      if (param_1->FunctionTableCount == DAT_14001d034) {
        if (uVar2 == 0) goto LAB_140023b9d;
LAB_140023baf:
        memmove(param_1->FunctionTable,&PTR_imp_UcmUcsiDeviceInitInitialize_14001d038,
                (ulonglong)param_1->FunctionTableCount << 3);
        _Var8 = 0x78435555;
        puVar5 = (undefined4 *)ExAllocatePool2(0x40);
        if (puVar5 == (undefined4 *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x1a,
                              &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,uVar9);
          }
          lVar6 = -0x3fffff66;
        }
        else {
          pvVar3 = param_1->ClassBindInfo;
          *(undefined8 *)(puVar5 + 2) = *(undefined8 *)&param_1->Version;
          *puVar5 = 0x78435555;
          puVar5[4] = (param_1->Version).Build;
          GetImageName(pvVar3,(uchar *)(puVar5 + 5),_Var8);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          if ((((m_AllowBinding1_1FromAnyClients == false) && ((param_1->Version).Major == 1)) &&
              ((param_1->Version).Minor == 1)) &&
             (iVar4 = _stricmp((char *)(puVar5 + 5),"UcmUcsiAcpiClient.sys"), iVar4 != 0)) {
            lVar6 = -0x3fffff45;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1c,
                                 &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,uVar9,0xbb);
            }
            ExFreePoolWithTag(puVar5,0x78435555);
            *(undefined8 *)param_1->ClassBindInfo = 0;
          }
          else {
            lVar6 = 0;
            *(undefined4 **)param_1->ClassBindInfo = puVar5 + 1;
          }
        }
        goto LAB_140023d58;
      }
    }
    else if (uVar2 == 0) {
LAB_140023b9d:
      if (param_1->FunctionTableCount == 9) goto LAB_140023baf;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar2 = (param_1->Version).Minor;
    uVar7 = 9;
    if (uVar2 == s_WdfClassLibraryInfo.Version.Minor) {
      uVar7 = DAT_14001d034;
    }
    WPP_RECORDER_SF_qDDDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x19,
               &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,uVar9,(char)uVar1,(char)uVar2,
               (char)uVar7,(char)param_1->FunctionTableCount);
  }
  lVar6 = -0x3ffffff3;
  Verify::Break();
LAB_140023d58:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1d,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return lVar6;
}



===== CheckTestSigning @ 140023db0 =====

/* private: static bool __cdecl UcmUcsiCx::Driver::CheckTestSigning(void) */

bool __cdecl UcmUcsiCx::Driver::CheckTestSigning(void)

{
  int iVar1;
  bool bVar2;
  undefined8 local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2a,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  local_res8 = 8;
  iVar1 = ZwQuerySystemInformation(0x67,&local_res8,8,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2b,
                        &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,(char)iVar1);
    }
    bVar2 = false;
  }
  else {
    bVar2 = (bool)(local_res8._4_1_ >> 1 & 1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x2c,
                      &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,bVar2);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2d,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
  }
  return bVar2;
}



===== DeinitializeClassExtension @ 140023ef0 =====

/* private: static void __cdecl UcmUcsiCx::Driver::DeinitializeClassExtension(void) */

void __cdecl UcmUcsiCx::Driver::DeinitializeClassExtension(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x15,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x16,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
  }
  return;
}



===== EvtDriverUnload @ 140023f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl UcmUcsiCx::Driver::EvtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl UcmUcsiCx::Driver::EvtDriverUnload(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x10,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  UnregisterClassExtension();
  McGenEventUnregister_EtwUnregister();
  UninitializeTelemetryAssertsKM();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x11,
                      &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,(char)param_1);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x12,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
  }
  WppCleanupKm(uVar1);
  return;
}



===== GetImageName @ 1400240d8 =====

/* private: static long __cdecl UcmUcsiCx::Driver::GetImageName(void * __ptr64,unsigned char *
   __ptr64,unsigned __int64) */

long __cdecl UcmUcsiCx::Driver::GetImageName(void *param_1,uchar *param_2,__uint64 param_3)

{
  undefined1 auVar1 [16];
  int iVar2;
  ulonglong uVar3;
  __uint64 _Var4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  uint uVar7;
  longlong lVar8;
  uchar *puVar9;
  uint uVar10;
  __uint64 local_res18;
  uint local_res20 [2];
  
  puVar9 = param_2;
  local_res18 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    puVar9 = (uchar *)CONCAT71((int7)((ulonglong)param_2 >> 8),5);
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2e,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  local_res18 = local_res18 & 0xffffffff00000000;
  local_res20[0] = 0;
  if (DAT_14001d4d8 == 0) {
    puVar9 = (uchar *)0x0;
    PsGetVersion(local_res20,0,0,0);
    if (local_res20[0] < 5) {
      iVar2 = -0x3fffff45;
      goto LAB_14002425a;
    }
    DAT_14001d4d0 = MmGetSystemRoutineAddress(&DAT_140018350);
    LOCK();
    DAT_14001d4d8 = 1;
    UNLOCK();
  }
  uVar3 = AuxKlibQueryModuleInformation((uint *)&local_res18,puVar9,0);
  iVar2 = (int)uVar3;
  if ((iVar2 < 0) || ((int)local_res18 == 0)) goto LAB_14002425a;
  uVar3 = (local_res18 & 0xffffffff) / 0x110;
  uVar10 = (uint)uVar3;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar3;
  lVar8 = SUB168(ZEXT816(0x110) * auVar1,8);
  _Var4 = SUB168(ZEXT816(0x110) * auVar1,0);
  if (lVar8 != 0) {
    _Var4 = 0xffffffffffffffff;
  }
  puVar5 = operator_new__(_Var4);
  if (puVar5 == (ulonglong *)0x0) {
    iVar2 = -0x3fffff66;
    goto LAB_14002425a;
  }
  uVar3 = AuxKlibQueryModuleInformation((uint *)&local_res18,lVar8,(ulonglong)puVar5);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    uVar7 = 0;
    puVar6 = puVar5;
    if (uVar10 != 0) {
      do {
        if (((void *)*puVar6 <= param_1) &&
           (param_1 < (void *)((ulonglong)(uint)puVar6[1] + (longlong)*puVar6))) {
          puVar9 = (uchar *)((longlong)puVar6 + (ulonglong)*(ushort *)((longlong)puVar6 + 0xc) + 0xe
                            );
          lVar8 = 0x20;
          goto LAB_1400242b6;
        }
        puVar6 = puVar6 + 0x22;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar10);
    }
    iVar2 = -0x3ffffddb;
  }
  goto LAB_140024242;
  while( true ) {
    *param_2 = *puVar9;
    puVar9 = puVar9 + 1;
    param_2 = param_2 + 1;
    lVar8 = lVar8 + -1;
    if (lVar8 == 0) break;
LAB_1400242b6:
    if ((lVar8 == -0x7fffffde) || (*puVar9 == '\0')) break;
  }
  iVar2 = 0;
  puVar9 = param_2 + -1;
  if (lVar8 != 0) {
    puVar9 = param_2;
  }
  *puVar9 = '\0';
LAB_140024242:
  ExFreePoolWithTag(puVar5,0);
LAB_14002425a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x2f,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return iVar2;
}



===== InitializeClassExtension @ 140024300 =====

/* private: static long __cdecl UcmUcsiCx::Driver::InitializeClassExtension(void) */

long __cdecl UcmUcsiCx::Driver::InitializeClassExtension(void)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x13,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x14,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
    }
  }
  return 0;
}



===== IsAllowBinding1_1FromAnyClientsEnabled @ 140024390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static bool __cdecl UcmUcsiCx::Driver::IsAllowBinding1_1FromAnyClientsEnabled(struct
   WDFDRIVER__ * __ptr64) */

bool __cdecl UcmUcsiCx::Driver::IsAllowBinding1_1FromAnyClientsEnabled(WDFDRIVER__ *param_1)

{
  int iVar1;
  bool bVar2;
  int local_res10 [2];
  longlong local_res18;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x30,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  local_res18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res10[0] = 0;
  bVar2 = false;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x3b8))(WdfDriverGlobals,param_1,0x20019,0,&local_res18)
  ;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0x31,
                         &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,(char)param_1,(char)iVar1)
      ;
    }
  }
  else {
    RtlInitUnicodeString(&local_28,L"AllowBinding1_1FromAnyClients");
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res18,&local_28,local_res10);
    if (iVar1 < 0) {
      if ((iVar1 != -0x3fffffcc) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qSd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
    else {
      bVar2 = local_res10[0] != 0;
    }
  }
  if (local_res18 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x33,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return bVar2;
}



===== UnbindClassExtensionClient @ 140024560 =====

/* private: static void __cdecl UcmUcsiCx::Driver::UnbindClassExtensionClient(struct
   _WDF_CLASS_BIND_INFO * __ptr64,void * __ptr64 * __ptr64) */

void __cdecl
UcmUcsiCx::Driver::UnbindClassExtensionClient(_WDF_CLASS_BIND_INFO *param_1,void **param_2)

{
  _UCMUCSI_PRIVATE_DRIVER_GLOBALS *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1e,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  if (*(_UCMUCSI_DRIVER_GLOBALS **)param_1->ClassBindInfo != (_UCMUCSI_DRIVER_GLOBALS *)0x0) {
    p_Var1 = GetPrivateGlobals(*(_UCMUCSI_DRIVER_GLOBALS **)param_1->ClassBindInfo);
    ExFreePoolWithTag(p_Var1,0x78435555);
    *(undefined8 *)param_1->ClassBindInfo = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x1f,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return;
}



===== UnregisterClassExtension @ 140024630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl UcmUcsiCx::Driver::UnregisterClassExtension(void) */

void __cdecl UcmUcsiCx::Driver::UnregisterClassExtension(void)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x28,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  if (s_ClassLibraryDevice != (WDFDEVICE__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    s_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x29,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return;
}



===== WppCleanupKm @ 1400246f4 =====

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



===== WppInitKm @ 1400247a4 =====

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



===== WppLoadTracingSupport @ 140024880 =====

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



===== WppTraceCallback @ 1400249d0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140024c58 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140024c93;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140024d0d:
  while( true ) {
    if (&UNK_14001c207 < ppuVar3) {
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
      if (&UNK_14001c207 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140024c93:
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
      if (&UNK_14001c207 < ppuVar2) goto LAB_140024d0d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140024d0d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140024d48 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140024de4;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140024de4;
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
LAB_140024de4:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140024e50 =====

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
              if (&UNK_14001c207 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 140024ed0 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140024ef0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140024fed;
  }
LAB_140024ff6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140024fed:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140024ff6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140024fbe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140024fbe;
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
    if (&UNK_14001c207 < ppuVar3) goto LAB_140024ff6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140024fed;
}



===== GenerateUcsiFailureDump @ 14002501c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UcmUcsiCx::GenerateUcsiFailureDump(struct WDFDEVICE__ * __ptr64,enum
   _UCSI_COMMAND,enum UcmUcsiCx::LkdFailureType,long,bool) */

void __cdecl
UcmUcsiCx::GenerateUcsiFailureDump
          (WDFDEVICE__ *param_1,_UCSI_COMMAND param_2,LkdFailureType param_3,long param_4,
          bool param_5)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_28 [2];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,10,
                     &WPP_3a4725f2856f3d2d85d8f9bb9355213a_Traceguids);
  }
  lVar2 = (**(code **)(WdfFunctions_01023 + 0xf8))(WdfDriverGlobals,param_1);
  local_28[0] = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x58);
  if (param_5) {
    DbgPrintEx(0x65,0,
               "\n\n************************* \n* A UCSI command or notification has failed. This typically happens when UCSI\n* firmware is not responsive for a UCSI command or when the firmware provides* illegal connector notification.\n* Run \"!rcdrkd.rcdrlogdump UcmUcsiCx\" for more information. ****\n\n"
              );
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x1d8,(longlong)(int)param_3,(longlong)(int)param_2,local_28,(longlong)param_4);
  }
  iVar1 = DbgkWerCaptureLiveKernelDump
                    (L"UcmUcsiCx.sys",0x1d4,(longlong)(int)param_3,(longlong)(int)param_2,local_28,
                     (longlong)param_4,0,0,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0xb,
                       &WPP_3a4725f2856f3d2d85d8f9bb9355213a_Traceguids,(char)param_1,(char)iVar1);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0xc,
                      &WPP_3a4725f2856f3d2d85d8f9bb9355213a_Traceguids,(char)param_1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0xd,
                     &WPP_3a4725f2856f3d2d85d8f9bb9355213a_Traceguids);
  }
  return;
}



===== ConnectorCollectionAddConnector @ 1400251f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Ppm::ConnectorCollectionAddConnector(struct
   UCMUCSI_CONNECTOR_COLLECTION__ * __ptr64,struct _UCMUCSI_CONNECTOR_INFO * __ptr64) */

long __cdecl
UcmUcsiCx::Ppm::ConnectorCollectionAddConnector
          (UCMUCSI_CONNECTOR_COLLECTION__ *param_1,_UCMUCSI_CONNECTOR_INFO *param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong64 uVar3;
  int iVar4;
  undefined2 uVar5;
  ulong *local_res8;
  undefined8 local_res18;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  UCMUCSI_CONNECTOR_COLLECTION__ *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0xd,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  local_res18 = 0;
  local_38 = 0;
  local_res8 = (ulong *)0x0;
  local_58 = 0;
  uStack_50 = 0x100000001;
  uStack_60 = 0;
  uStack_40 = 0;
  local_68 = 0x38;
  local_48 = param_1;
  iVar4 = (**(code **)(WdfFunctions_01023 + 0x600))
                    (WdfDriverGlobals,&local_68,0x200,0,0x10,&local_res18,&local_res8);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0xe;
LAB_140025320:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar5,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)param_1,(char)iVar4)
      ;
    }
  }
  else {
    uVar1 = *(ulong *)&param_2->field_0x4;
    uVar3 = param_2->ConnectorId;
    uVar2 = *(ulong *)((longlong)&param_2->ConnectorId + 4);
    *local_res8 = param_2->Size;
    local_res8[1] = uVar1;
    local_res8[2] = (ulong)uVar3;
    local_res8[3] = uVar2;
    iVar4 = (**(code **)(WdfFunctions_01023 + 0x78))(WdfDriverGlobals,param_1,local_res18);
    if (-1 < iVar4) goto LAB_14002536a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0xf;
      goto LAB_140025320;
    }
  }
  if (local_res8 != (ulong *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals,local_res18);
  }
LAB_14002536a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x10,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar4;
}



===== CreateAndInitialize @ 1400253c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Ppm::CreateAndInitialize(class UcmUcsiCx::CxDevice *
   __ptr64,struct _UCMUCSI_PPM_CONFIG * __ptr64,struct _WDF_OBJECT_ATTRIBUTES * __ptr64,class
   UcmUcsiCx::Ppm * __ptr64 * __ptr64) */

long __cdecl
UcmUcsiCx::Ppm::CreateAndInitialize
          (CxDevice *param_1,_UCMUCSI_PPM_CONFIG *param_2,_WDF_OBJECT_ATTRIBUTES *param_3,
          Ppm **param_4)

{
  int iVar1;
  Ppm *pPVar2;
  _WDF_OBJECT_ATTRIBUTES *p_Var3;
  ulonglong uVar4;
  undefined2 uVar5;
  UCMUCSIPPM__ *local_res8;
  UCMUCSIPPM__ *pUVar6;
  _WDF_OBJECT_ATTRIBUTES local_68;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x11,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  pUVar6 = (UCMUCSIPPM__ *)param_1->_padding_;
  local_68.Size = 0x38;
  local_68._4_4_ = 0;
  local_68.ExecutionLevel = WdfExecutionLevelInheritFromParent;
  local_68.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
  local_68.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)PTR__WDF_Ppm_TYPE_INFO_14001d0c8;
  local_68.EvtCleanupCallback =
       WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiCx::Ppm>::EvtObjectContextCleanupThunk;
  local_68.EvtDestroyCallback =
       WdfCpp::ObjectContext<UCMUCSIPPM__*___ptr64,UcmUcsiCx::Ppm>::EvtObjectContextDestroyThunk;
  local_res8 = (UCMUCSIPPM__ *)0x0;
  local_68.ParentObject = (void *)0x0;
  local_68.ContextSizeOverride = 0;
  uVar4 = -(ulonglong)(param_3 != (_WDF_OBJECT_ATTRIBUTES *)0x0) & (ulonglong)&local_68;
  p_Var3 = &local_68;
  if (param_3 != (_WDF_OBJECT_ATTRIBUTES *)0x0) {
    p_Var3 = param_3;
  }
  p_Var3->ParentObject = pUVar6;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x678))(WdfDriverGlobals,p_Var3,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x12;
LAB_1400254de:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar5,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)pUVar6,(char)iVar1);
    }
  }
  else if ((uVar4 == 0) ||
          (iVar1 = (**(code **)(WdfFunctions_01023 + 0x658))(WdfDriverGlobals,local_res8,uVar4,0),
          -1 < iVar1)) {
    pPVar2 = (Ppm *)(**(code **)(WdfFunctions_01023 + 0x650))
                              (WdfDriverGlobals,local_res8,PTR__WDF_Ppm_TYPE_INFO_14001d0c8);
    if (pPVar2 == (Ppm *)0x0) {
      pPVar2 = (Ppm *)0x0;
    }
    else {
      pPVar2 = (Ppm *)Ppm(pPVar2,local_res8);
    }
    iVar1 = Initialize(pPVar2,param_1,param_2);
    if (-1 < iVar1) {
      param_1->m_Ppm = pPVar2;
      iVar1 = 0;
      *param_4 = pPVar2;
      goto LAB_140025603;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar5 = 0x13;
    pUVar6 = local_res8;
    goto LAB_1400254de;
  }
  if (local_res8 != (UCMUCSIPPM__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    local_res8 = (UCMUCSIPPM__ *)0x0;
  }
LAB_140025603:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x14,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar1;
}



===== CreateConnectorCollection @ 140025660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Ppm::CreateConnectorCollection(struct WDFDEVICE__ *
   __ptr64,struct _WDF_OBJECT_ATTRIBUTES * __ptr64,struct UCMUCSI_CONNECTOR_COLLECTION__ * __ptr64 *
   __ptr64) */

long __cdecl
UcmUcsiCx::Ppm::CreateConnectorCollection
          (WDFDEVICE__ *param_1,_WDF_OBJECT_ATTRIBUTES *param_2,
          UCMUCSI_CONNECTOR_COLLECTION__ **param_3)

{
  int iVar1;
  UCMUCSI_CONNECTOR_COLLECTION__ *local_res10;
  _WDF_OBJECT_ATTRIBUTES local_68;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,10,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  local_res10 = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  local_68.ContextTypeInfo = (_WDF_OBJECT_CONTEXT_TYPE_INFO *)0x0;
  local_68.Size = 0;
  local_68._4_4_ = 0;
  local_68.EvtCleanupCallback = (_func___cdecl_void_void_ptr *)0x0;
  local_68.EvtDestroyCallback = (_func___cdecl_void_void_ptr *)0x0;
  local_68.ExecutionLevel = WdfExecutionLevelInvalid;
  local_68.SynchronizationScope = WdfSynchronizationScopeInvalid;
  local_68.ParentObject = (WDFDEVICE__ *)0x0;
  local_68.ContextSizeOverride = 0;
  if (param_2 == (_WDF_OBJECT_ATTRIBUTES *)0x0) {
    local_68.Size = 0x38;
    local_68._4_4_ = 0;
    param_2 = &local_68;
    local_68.ExecutionLevel = WdfExecutionLevelInheritFromParent;
    local_68.SynchronizationScope = WdfSynchronizationScopeInheritFromParent;
    local_68.ParentObject = param_1;
  }
  else if (param_2->ParentObject == (void *)0x0) {
    param_2->ParentObject = param_1;
  }
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x68))(WdfDriverGlobals,param_2,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0xb,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)param_1,(char)iVar1)
      ;
    }
    *param_3 = (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0;
  }
  else {
    *param_3 = local_res10;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0xc,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar1;
}



===== EvtObjectContextCleanup @ 1400257c4 =====

/* private: void __cdecl UcmUcsiCx::Ppm::EvtObjectContextCleanup(void) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::EvtObjectContextCleanup(Ppm *this)

{
  longlong lVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x21,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1e,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
    }
  }
  lVar1 = this->_padding_;
  Opm::Deinitialize(&this->m_Opm);
  this->m_CxDevice = (CxDevice *)0x0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x1f,
                      &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)lVar1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x20,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x22,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
      }
    }
  }
  return;
}



===== Initialize @ 140025914 =====

/* private: long __cdecl UcmUcsiCx::Ppm::Initialize(class UcmUcsiCx::CxDevice * __ptr64,struct
   _UCMUCSI_PPM_CONFIG * __ptr64) __ptr64 */

long __thiscall UcmUcsiCx::Ppm::Initialize(Ppm *this,CxDevice *param_1,_UCMUCSI_PPM_CONFIG *param_2)

{
  _UCMUCSI_PPM_CONFIG *p_Var1;
  longlong lVar2;
  UCMUCSI_CONNECTOR_COLLECTION__ *pUVar3;
  uchar uVar4;
  undefined3 uVar5;
  undefined4 uVar6;
  long lVar7;
  uint uVar8;
  _UCMUCSI_PPM_CONFIG *p_Var9;
  undefined2 uVar10;
  undefined1 uVar11;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x19,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  lVar2 = this->_padding_;
  this->m_CxDevice = param_1;
  p_Var9 = param_2;
  lVar7 = ValidatePpmConfig(this,param_2);
  uVar11 = (undefined1)lVar2;
  if (lVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar7;
    }
    uVar10 = 0x1a;
  }
  else {
    uVar4 = param_2->UsbDeviceControllerEnabled;
    uVar5 = *(undefined3 *)&param_2->field_0x5;
    pUVar3 = param_2->ConnectorCollectionHandle;
    p_Var1 = &this->m_PpmConfig;
    p_Var1->Size = param_2->Size;
    p_Var1->UsbDeviceControllerEnabled = uVar4;
    *(undefined3 *)&p_Var1->field_0x5 = uVar5;
    (this->m_PpmConfig).ConnectorCollectionHandle = pUVar3;
    uVar8 = param_2->UcsiMaxDataLength;
    uVar6 = *(undefined4 *)&param_2->field_0x1c;
    *(undefined8 *)&(this->m_PpmConfig).UcsiVersion.AsUInt16 =
         *(undefined8 *)&(param_2->UcsiVersion).AsUInt16;
    (this->m_PpmConfig).UcsiMaxDataLength = uVar8;
    *(undefined4 *)&(this->m_PpmConfig).field_0x1c = uVar6;
    if ((this->m_PpmConfig).UcsiMaxDataLength == 0) {
      uVar8 = 0xff;
      if ((this->m_PpmConfig).UcsiDataBlockExEnabled != WdfTrue) {
        uVar8 = 0x10;
      }
      (this->m_PpmConfig).UcsiMaxDataLength = uVar8;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        p_Var9 = (_UCMUCSI_PPM_CONFIG *)CONCAT71((int7)((ulonglong)p_Var9 >> 8),4);
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x1b,
                           &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,uVar11,(char)uVar8);
      }
    }
    if (Driver::m_TestSigning != false) {
      QueryRegistryDeviceHardwareKey(this,(ushort *)p_Var9,&this->m_HardwareBringUpModeEnabled);
    }
    lVar7 = Opm::Initialize(&this->m_Opm,p_Var1,this);
    if (-1 < lVar7) {
      KeInitializeEvent(&this->m_PowerOnEvent,0,0);
      KeInitializeEvent(&this->m_PowerOffEvent,0,0);
      lVar7 = 0;
      goto LAB_140025aad;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar7;
    }
    uVar10 = 0x1c;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,uVar10,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,uVar11,(char)lVar7);
LAB_140025aad:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x1d,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return lVar7;
}



===== IsConfigValid @ 140025b04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Ppm::IsConfigValid(class UcmUcsiCx::CxDevice *
   __ptr64,struct _UCMUCSI_PPM_CONFIG * __ptr64) */

long __cdecl UcmUcsiCx::Ppm::IsConfigValid(CxDevice *param_1,_UCMUCSI_PPM_CONFIG *param_2)

{
  int iVar1;
  long lVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x15,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x70))
                    (WdfDriverGlobals,param_2->ConnectorCollectionHandle);
  if (iVar1 == 0) {
    lVar2 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x16,
                      &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)param_1->_padding_);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,7,0x17,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)param_1->_padding_);
    }
    lVar2 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x18,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return lVar2;
}



===== PowerOff @ 140025c44 =====

/* public: long __cdecl UcmUcsiCx::Ppm::PowerOff(void) __ptr64 */

long __thiscall UcmUcsiCx::Ppm::PowerOff(Ppm *this)

{
  int iVar1;
  undefined8 local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3c,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  KeClearEvent(&this->m_PowerOffEvent);
  Opm::StartPowerDown(&this->m_Opm);
  local_res8 = 0xffffffffdc3cba00;
  iVar1 = KeWaitForSingleObject(&this->m_PowerOffEvent,0,0,0,&local_res8);
  if (iVar1 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x3d,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,
                       (char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3e,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar1;
}



===== PowerOn @ 140025d68 =====

/* public: long __cdecl UcmUcsiCx::Ppm::PowerOn(void) __ptr64 */

long __thiscall UcmUcsiCx::Ppm::PowerOn(Ppm *this)

{
  int iVar1;
  undefined8 local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x3f,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  KeClearEvent(&this->m_PowerOnEvent);
  Opm::StartPowerUp(&this->m_Opm);
  local_res8 = 0xffffffffdc3cba00;
  iVar1 = KeWaitForSingleObject(&this->m_PowerOnEvent,0,0,0,&local_res8);
  if (iVar1 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x40,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,
                       (char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x41,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar1;
}



===== QueryRegistryDeviceHardwareKey @ 140025e8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl UcmUcsiCx::Ppm::QueryRegistryDeviceHardwareKey(unsigned short const *
   __ptr64,bool * __ptr64) __ptr64 */

long __thiscall
UcmUcsiCx::Ppm::QueryRegistryDeviceHardwareKey(Ppm *this,ushort *param_1,bool *param_2)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8;
  ushort *local_res10;
  undefined1 uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res10 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x29,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  local_res8 = 0;
  local_res10 = (ushort *)((ulonglong)local_res10 & 0xffffffff00000000);
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_38,L"HardwareBringUpModeEnabled");
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x180))
                    (WdfDriverGlobals,this->m_CxDevice->_padding_,1,0x20019,0,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002602c;
    uVar3 = (undefined1)this->_padding_;
    uVar2 = 0x2a;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res8,&local_38,&local_res10);
    if (-1 < iVar1) {
      iVar1 = 0;
      *param_2 = (int)local_res10 != 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qSl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_14002602c;
    }
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_14002602c;
    uVar2 = 0x2b;
    uVar3 = (undefined1)this->_padding_;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,7,uVar2,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,uVar3,(char)iVar1);
LAB_14002602c:
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2d,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return iVar1;
}



===== Start @ 1400260a0 =====

/* public: long __cdecl UcmUcsiCx::Ppm::Start(void) __ptr64 */

long __thiscall UcmUcsiCx::Ppm::Start(Ppm *this)

{
  long lVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x2e,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  uVar2 = (undefined1)this->_padding_;
  if (this->m_IsStarted == false) {
    if (this->m_HardwareRequestQueue != (WDFQUEUE__ *)0x0) {
      this->m_IsStarted = true;
      Opm::Start(&this->m_Opm);
      lVar1 = 0;
      goto LAB_140026191;
    }
    lVar1 = -0x3ffffff8;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x30,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,uVar2);
    }
  }
  else {
    lVar1 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x2f,
                         &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,uVar2,0x10);
    }
  }
  Verify::Break();
LAB_140026191:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x31,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return lVar1;
}



===== Stop @ 1400261e0 =====

/* public: void __cdecl UcmUcsiCx::Ppm::Stop(void) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::Stop(Ppm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x32,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  if ((*(uint *)(WdfDriverGlobals + 8) & 4) == 0) {
LAB_14002626d:
    if (this->m_IsStarted == false) goto LAB_140026285;
  }
  else if (this->m_IsStarted == false) {
    RtlAssert("m_IsStarted","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\ppm.cpp",0x298,0);
    goto LAB_14002626d;
  }
  StopInternal(this);
  this->m_IsStarted = false;
LAB_140026285:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x33,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  return;
}



===== StopInternal @ 1400262d0 =====

/* private: void __cdecl UcmUcsiCx::Ppm::StopInternal(void) __ptr64 */

void __thiscall UcmUcsiCx::Ppm::StopInternal(Ppm *this)

{
  _KEVENT *p_Var1;
  int iVar2;
  char *pcVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x34,
                     &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x16,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = &(this->m_Opm).m_StoppedNotificationEvent;
  iVar2 = KeReadStateEvent(p_Var1);
  if (iVar2 == 0) {
    pcVar3 = (char *)0x11;
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)&this->m_Opm,0x11);
    Verify::WaitForSingleObject(p_Var1,pcVar3,(void *)((this->m_Opm).m_Ppm)->_padding_);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x17,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,7,0x35,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids);
    }
  }
  return;
}



===== ValidatePpmConfig @ 140026414 =====

/* private: long __cdecl UcmUcsiCx::Ppm::ValidatePpmConfig(struct _UCMUCSI_PPM_CONFIG * __ptr64)
   __ptr64 */

long __thiscall UcmUcsiCx::Ppm::ValidatePpmConfig(Ppm *this,_UCMUCSI_PPM_CONFIG *param_1)

{
  uint uVar1;
  _UCMUCSI_PRIVATE_DRIVER_GLOBALS *p_Var2;
  CxDevice *pCVar3;
  char *pcVar4;
  _UCMUCSI_PPM_CONFIG *p_Var5;
  long lVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  
  p_Var5 = param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    p_Var5 = (_UCMUCSI_PPM_CONFIG *)(ulonglong)((param_1->UcsiVersion).AsUInt16 & 0xf);
    WPP_RECORDER_SF_qDDDLDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  p_Var2 = this->m_CxDevice->m_PrivateGlobals;
  uVar1 = (p_Var2->ClientClassVersion).Major;
  if ((1 < uVar1) || ((uVar1 == 1 && ((p_Var2->ClientClassVersion).Minor != 0)))) {
    p_Var5 = (_UCMUCSI_PPM_CONFIG *)&param_1->UcsiVersion;
    WriteDevPropWithUcsiVersion(this,(_UCSI_VERSION *)p_Var5);
  }
  if ((param_1->UcsiDataBlockExEnabled == WdfTrue) &&
     ((param_1->UcsiVersion)._s_1.MajorVersion == 1)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffe7e;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,7,0x26,
                       &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,0x82);
    return -0x3ffffe7e;
  }
  lVar6 = 0;
  if ((1 < (param_1->UcsiVersion)._s_1.MajorVersion) && (param_1->UcsiDataBlockExEnabled != WdfTrue)
     ) {
    pCVar3 = this->m_CxDevice;
    pcVar4 = (char *)(ulonglong)*(uint *)(WdfDriverGlobals + 8);
    if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
       (pCVar3->m_PrivateGlobals == (_UCMUCSI_PRIVATE_DRIVER_GLOBALS *)0x0)) {
      pcVar4 = "m_PrivateGlobals != nullptr";
      RtlAssert("m_PrivateGlobals != nullptr",
                "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\CxDevice.h",0x92,0);
    }
    p_Var2 = pCVar3->m_PrivateGlobals;
    p_Var5 = (_UCMUCSI_PPM_CONFIG *)(ulonglong)(param_1->UcsiVersion).AsUInt16;
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              (pcVar4,(uint)(param_1->UcsiVersion).AsUInt16,
               CONCAT22((short)(p_Var2->ClientClassVersion).Major,
                        (short)(p_Var2->ClientClassVersion).Minor),
               "UCSI 2+ PPM is not opted in for UcsiDataBlockExEnabled");
  }
  uVar1 = param_1->UcsiMaxDataLength;
  if (uVar1 == 0) {
LAB_140026610:
    ValidateAndCacheUcsiVersion(this,&param_1->UcsiVersion);
  }
  else {
    if (param_1->UcsiDataBlockExEnabled == WdfTrue) {
      if (uVar1 == 0xff) goto LAB_140026610;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffe7e;
      }
      uVar7 = 0x27;
      uVar8 = 0xff;
    }
    else {
      if (uVar1 == 0x10) goto LAB_140026610;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffe7e;
      }
      uVar7 = 0x28;
      uVar8 = 0x10;
    }
    lVar6 = -0x3ffffe7e;
    WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var5,7,uVar7,
                        &WPP_810444b6362f3a69ee1d3be24b04334f_Traceguids,(char)this->_padding_,uVar8
                        ,0x82);
  }
  return lVar6;
}



===== Initialize @ 140026640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiCx::PpmInterface::Initialize(struct _UCMUCSI_PPM_CONFIG *
   __ptr64,class UcmUcsiCx::Ppm * __ptr64,void (__cdecl*)(class UcmUcsiCx::Ppm * __ptr64,long))
   __ptr64 */

long __thiscall
UcmUcsiCx::PpmInterface::Initialize
          (PpmInterface *this,_UCMUCSI_PPM_CONFIG *param_1,Ppm *param_2,
          _func_void_Ppm_ptr_long *param_3)

{
  int iVar1;
  CxDevice *pCVar2;
  undefined8 uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,10,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (param_2 == (Ppm *)0x0)) {
    RtlAssert("PpmObject != nullptr",
              "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\ppminterface.cpp",0x2b,0);
  }
  this->m_Ppm = param_2;
  this->m_HardwareRequestCompletionCallback = CommandHandler::HardwareRequestCompleted;
  pCVar2 = Ppm::GetCxDevice(param_2);
  uVar3 = (**(code **)(WdfFunctions_01023 + 0xdc0))(WdfDriverGlobals,pCVar2->_padding_);
  local_38 = 0;
  local_18 = 0;
  uStack_40 = 0;
  local_48 = 0x38;
  uStack_20 = 0;
  uStack_30 = 0x100000001;
  local_28 = this->m_Ppm->_padding_;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x7b8))(WdfDriverGlobals,&local_48,uVar3,this);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,9,0xb,
                       &WPP_e278b5df54c93308c1906314c6922925_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar1);
  }
  else {
    iVar1 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xc,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  return iVar1;
}



===== Deinitialize @ 140026804 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::Opm::Deinitialize(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::Deinitialize(Opm *this)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  Opm *this_00;
  _KEVENT *p_Var4;
  undefined8 local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x11,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x13,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  bVar2 = CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::IsInitialized
                    ((CommandHandlerStateMachine<UcmUcsiCx::CommandHandler> *)
                     &this->m_CommandHandler);
  if (bVar2) {
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)&this->m_CommandHandler,8);
  }
  CommandList::Deinitialize(&(this->m_CommandHandler).m_CommandList);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xd,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  if ((this->m_CommandHandler).m_PpmInterface.m_Ppm != (Ppm *)0x0) {
    (this->m_CommandHandler).m_PpmInterface.m_Ppm = (Ppm *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,9,0xe,
                     &WPP_e278b5df54c93308c1906314c6922925_Traceguids);
  }
  (this->m_CommandHandler).m_Ppm = (Ppm *)0x0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x14,
                     &WPP_be66407a1aed381749fba11a60c926d7_Traceguids);
  }
  if (this->m_Connectors != (WDFCOLLECTION__ *)0x0) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    this->m_Connectors = (WDFCOLLECTION__ *)0x0;
  }
  this_00 = this;
  bVar2 = CommandHandlerStateMachine<UcmUcsiCx::CommandHandler>::IsInitialized
                    ((CommandHandlerStateMachine<UcmUcsiCx::CommandHandler> *)this);
  if (bVar2) {
    lVar1 = this->m_Ppm->_padding_;
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this_00,5);
    local_res8 = 0xfffffffffa0a1f00;
    p_Var4 = &this->m_OpmStateMachineDestroyedEvent;
    iVar3 = KeWaitForSingleObject(p_Var4,0,0,0,&local_res8);
    if (iVar3 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        p_Var4 = *(_KEVENT **)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_qd(p_Var4,2,7,0x12,&WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)lVar1,(char)iVar3);
      }
      MicrosoftTelemetryAssertTriggeredArgsMsgKM(p_Var4,0,iVar3,"[OPM] Deinitialize wait failed");
    }
  }
  else {
    this->m_Ppm = (Ppm *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x13,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== EvtUcmConnectorSetDataRole @ 140026a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Opm::EvtUcmConnectorSetDataRole(struct UCMCONNECTOR__ *
   __ptr64,enum _UCM_DATA_ROLE) */

long __cdecl
UcmUcsiCx::Opm::EvtUcmConnectorSetDataRole(UCMCONNECTOR__ *param_1,_UCM_DATA_ROLE param_2)

{
  _PPM_CONNECTOR *p_Var1;
  longlong *plVar2;
  CxDevice *pCVar3;
  Opm *this;
  long lVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01023 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0);
  p_Var1 = (_PPM_CONNECTOR *)*plVar2;
  if (p_Var1 == (_PPM_CONNECTOR *)0x0) {
    lVar4 = -0x3ffffe7c;
  }
  else {
    pCVar3 = CxDevice::GetContextFromObject(p_Var1->WdfDevice);
    this = Ppm::GetOpm(pCVar3->m_Ppm);
    (this->m_UcmConnectorCallbackInfo).PpmConnector = p_Var1;
    (this->m_UcmConnectorCallbackInfo).DataRole = param_2;
    (this->m_UcmConnectorCallbackInfo).PowerRole = UcmPowerRoleInvalid;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Size = 0;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.PowerRole = UcmPowerRoleInvalid;
    *(undefined8 *)&(this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Format = 0;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.field3_0xc.Ucsi.MaximumTypeCCurrent =
         UcmUcsiSetPowerLevelCCurrentPpmDefault;
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,0xf);
    lVar4 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return lVar4;
}



===== EvtUcmConnectorSetPowerLevel @ 140026bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Opm::EvtUcmConnectorSetPowerLevel(struct UCMCONNECTOR__ *
   __ptr64,struct _UCM_SET_POWER_LEVEL_PARAMS * __ptr64) */

long __cdecl
UcmUcsiCx::Opm::EvtUcmConnectorSetPowerLevel
          (UCMCONNECTOR__ *param_1,_UCM_SET_POWER_LEVEL_PARAMS *param_2)

{
  _PPM_CONNECTOR *p_Var1;
  undefined8 uVar2;
  _UCM_POWER_ROLE _Var3;
  longlong *plVar4;
  CxDevice *pCVar5;
  Opm *this;
  _UCM_UCSI_SET_POWER_LEVEL_C_CURRENT _Var6;
  long lVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3e,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01023 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0);
  p_Var1 = (_PPM_CONNECTOR *)*plVar4;
  if (p_Var1 == (_PPM_CONNECTOR *)0x0) {
    lVar7 = -0x3ffffe7c;
  }
  else {
    pCVar5 = CxDevice::GetContextFromObject(p_Var1->WdfDevice);
    this = Ppm::GetOpm(pCVar5->m_Ppm);
    (this->m_UcmConnectorCallbackInfo).PpmConnector = p_Var1;
    (this->m_UcmConnectorCallbackInfo).DataRole = UcmDataRoleInvalid;
    (this->m_UcmConnectorCallbackInfo).PowerRole = UcmPowerRoleInvalid;
    if (param_2 == (_UCM_SET_POWER_LEVEL_PARAMS *)0x0) {
      _Var6 = UcmUcsiSetPowerLevelCCurrentPpmDefault;
      (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Size = 0;
      (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.PowerRole = UcmPowerRoleInvalid;
      *(undefined8 *)&(this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Format = 0;
    }
    else {
      _Var3 = param_2->PowerRole;
      uVar2 = *(undefined8 *)&param_2->Format;
      (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Size = param_2->Size;
      (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.PowerRole = _Var3;
      *(undefined8 *)&(this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Format = uVar2;
      _Var6 = (param_2->field3_0xc).Ucsi.MaximumTypeCCurrent;
    }
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.field3_0xc.Ucsi.MaximumTypeCCurrent =
         _Var6;
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,0xe);
    lVar7 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3f,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return lVar7;
}



===== EvtUcmConnectorSetPowerRole @ 140026cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl UcmUcsiCx::Opm::EvtUcmConnectorSetPowerRole(struct UCMCONNECTOR__ *
   __ptr64,enum _UCM_POWER_ROLE) */

long __cdecl
UcmUcsiCx::Opm::EvtUcmConnectorSetPowerRole(UCMCONNECTOR__ *param_1,_UCM_POWER_ROLE param_2)

{
  _PPM_CONNECTOR *p_Var1;
  longlong *plVar2;
  CxDevice *pCVar3;
  Opm *this;
  long lVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01023 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0);
  p_Var1 = (_PPM_CONNECTOR *)*plVar2;
  if (p_Var1 == (_PPM_CONNECTOR *)0x0) {
    lVar4 = -0x3ffffe7c;
  }
  else {
    pCVar3 = CxDevice::GetContextFromObject(p_Var1->WdfDevice);
    this = Ppm::GetOpm(pCVar3->m_Ppm);
    (this->m_UcmConnectorCallbackInfo).PpmConnector = p_Var1;
    (this->m_UcmConnectorCallbackInfo).DataRole = UcmDataRoleInvalid;
    (this->m_UcmConnectorCallbackInfo).PowerRole = param_2;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Size = 0;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.PowerRole = UcmPowerRoleInvalid;
    *(undefined8 *)&(this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.Format = 0;
    (this->m_UcmConnectorCallbackInfo).SetPowerLevelParams.field3_0xc.Ucsi.MaximumTypeCCurrent =
         UcmUcsiSetPowerLevelCCurrentPpmDefault;
    OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
              ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,0xd);
    lVar4 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x3d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return lVar4;
}



===== GetEnableNotChargingErrorNotificationOverride @ 140026e18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::GetEnableNotChargingErrorNotificationOverride(void) __ptr64
    */

void __thiscall UcmUcsiCx::Opm::GetEnableNotChargingErrorNotificationOverride(Opm *this)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x2e,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res10 = 0;
  local_res8[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_48,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\USB");
  RtlInitUnicodeString(&local_38,L"UcsiEnableNotChargingErrorNotification");
  iVar2 = (**(code **)(WdfFunctions_01023 + 0x728))
                    (WdfDriverGlobals,0,&local_48,0x20019,0,&local_res10);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026f85;
    uVar3 = 0x2f;
LAB_140026eff:
    uVar1 = (undefined1)this->m_Ppm->_padding_;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_38,local_res8);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026f85;
      uVar3 = 0x30;
      goto LAB_140026eff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026f85;
    uVar3 = 0x31;
    uVar1 = (undefined1)this->m_Ppm->_padding_;
    iVar2 = local_res8[0];
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,uVar3,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,uVar1,(char)iVar2);
LAB_140026f85:
  this->m_BatteryNotChargingNotificationDisableOverride = local_res8[0] != 0;
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x32,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== GetRegValueUcsiEnableOvercurrentErrorNotification @ 140027000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::GetRegValueUcsiEnableOvercurrentErrorNotification(void)
   __ptr64 */

void __thiscall UcmUcsiCx::Opm::GetRegValueUcsiEnableOvercurrentErrorNotification(Opm *this)

{
  int iVar1;
  undefined2 uVar2;
  int local_res8 [2];
  longlong local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x35,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_res10 = 0;
  local_res8[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  RtlInitUnicodeString(&local_48,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\USB");
  RtlInitUnicodeString(&local_38,L"UcsiEnableOvercurrentErrorNotification");
  this->m_UcsiEnableOvercurrentErrorNotification = false;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x728))
                    (WdfDriverGlobals,0,&local_48,0x20019,0,&local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400271a3;
    uVar2 = 0x36;
LAB_1400270ee:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,uVar2,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar1);
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_38,local_res8);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400271a3;
      uVar2 = 0x37;
      goto LAB_1400270ee;
    }
    this->m_UcsiEnableOvercurrentErrorNotification = local_res8[0] != 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0x38,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,this->m_UcsiEnableOvercurrentErrorNotification);
  }
LAB_1400271a3:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x738))(WdfDriverGlobals);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x39,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== Initialize @ 140027210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiCx::Opm::Initialize(struct _UCMUCSI_PPM_CONFIG * __ptr64,class
   UcmUcsiCx::Ppm * __ptr64) __ptr64 */

long __thiscall UcmUcsiCx::Opm::Initialize(Opm *this,_UCMUCSI_PPM_CONFIG *param_1,Ppm *param_2)

{
  UCMUCSI_CONNECTOR_COLLECTION__ *pUVar1;
  ulong64 uVar2;
  undefined1 uVar3;
  uint uVar4;
  long lVar5;
  CxDevice *pCVar6;
  _PPM_CONNECTOR *p_Var7;
  longlong lVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  char *pcVar12;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,10,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  this->m_Ppm = param_2;
  pUVar1 = param_1->ConnectorCollectionHandle;
  local_38 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
     (pUVar1 == (UCMUCSI_CONNECTOR_COLLECTION__ *)0x0)) {
    RtlAssert("connectorInfoCollection","onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0x36
              ,0);
  }
  uVar4 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,pUVar1);
  lVar5 = CommandHandler::Initialize(&this->m_CommandHandler,param_1,this->m_Ppm);
  if (lVar5 < 0) goto LAB_14002769a;
  KeInitializeEvent(&this->m_StoppedNotificationEvent,0,1);
  KeInitializeEvent(&this->m_OpmStateMachineDestroyedEvent,0,0);
  pcVar12 = "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp";
  (**(code **)(WdfFunctions_01023 + 0x668))(WdfDriverGlobals,param_2->_padding_,0,0x49);
  pCVar6 = Ppm::GetCxDevice(this->m_Ppm);
  local_78 = (**(code **)(WdfFunctions_01023 + 0xf8))(WdfDriverGlobals,pCVar6->_padding_);
  local_70 = 0x78435555;
  lVar5 = OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::Initialize
                    ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,
                     (StateMachineEngineConfig *)&local_78);
  if (lVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0xb;
LAB_1400273d5:
      uVar4 = 10;
LAB_1400273db:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar11,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)lVar5);
    }
  }
  else {
    uStack_50 = 0x100000001;
    this->m_IsUsbDeviceControllerEnabled = param_1->UsbDeviceControllerEnabled != '\0';
    local_68 = CONCAT44(local_68._4_4_,0x38);
    local_48 = this->m_Ppm->_padding_;
    lVar5 = (**(code **)(WdfFunctions_01023 + 0x68))(WdfDriverGlobals,&local_68,&this->m_Connectors)
    ;
    if (-1 < lVar5) {
      lVar5 = (**(code **)(WdfFunctions_01023 + 0x9d8))
                        (WdfDriverGlobals,&local_68,&this->m_UnrecoverableFailureContextLock);
      if (-1 < lVar5) {
        uVar9 = 0;
        if (uVar4 != 0) {
          do {
            p_Var7 = AddConnector(this);
            if (p_Var7 == (_PPM_CONNECTOR *)0x0) {
              lVar5 = -0x3fffff66;
              goto LAB_140027633;
            }
            lVar8 = (**(code **)(WdfFunctions_01023 + 0x90))(WdfDriverGlobals,pUVar1);
            if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) && (lVar8 == 0)) {
              RtlAssert("connectorInfoMem != nullptr",
                        "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp",0x75,0);
            }
            uVar10 = 0;
            lVar8 = (**(code **)(WdfFunctions_01023 + 0x610))(WdfDriverGlobals,lVar8);
            uVar2 = *(ulong64 *)(lVar8 + 8);
            p_Var7->Id = uVar2;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar10,0xe,pcVar12,
                                 (char)this->m_Ppm->_padding_,(char)uVar2);
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar4);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar3 = (**(code **)(WdfFunctions_01023 + 0x70))(WdfDriverGlobals,this->m_Connectors);
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,10,0xf,
                             &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                             (char)this->m_Ppm->_padding_,uVar3);
        }
        GetEnableNotChargingErrorNotificationOverride(this);
        if (Driver::m_TestSigning != false) {
          GetRegValueUcsiEnableOvercurrentErrorNotification(this);
        }
        lVar5 = 0;
        goto LAB_14002769a;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140027633;
      uVar11 = 0xd;
      uVar4 = 3;
      goto LAB_1400273db;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0xc;
      goto LAB_1400273d5;
    }
  }
LAB_140027633:
  (**(code **)(WdfFunctions_01023 + 0x670))
            (WdfDriverGlobals,this->m_Ppm->_padding_,0,0x8d,
             "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\opm.cpp");
LAB_14002769a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x10,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return lVar5;
}



===== NotifyTestUcsiCommandComplete @ 1400276fc =====

/* private: void __cdecl UcmUcsiCx::Opm::NotifyTestUcsiCommandComplete(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::NotifyTestUcsiCommandComplete(Opm *this)

{
  uint uVar1;
  CxDevice *pCVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x88,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  pCVar2 = Ppm::GetCxDevice(this->m_Ppm);
  TestInterface::EvtUcsiCommandCompleted
            (&pCVar2->m_TestInterface,(this->m_ActiveCommandCtx).Status,
             &(this->m_ActiveCommandCtx).CompletionData);
  uVar1 = (uint)(this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.
                AsUInt64 & 0xff;
  if (uVar1 == 9) {
    ReportDataDirectionChangeToUCM(this);
  }
  else if (uVar1 == 0xb) {
    ReportPowerDirectionChangeToUCM(this);
  }
  (this->m_ActiveCommandCtx).OpmCommand.FromTestInterface = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x89,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportAltModesToUCM @ 1400277e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportAltModesToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportAltModesToUCM(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0 _Var1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0 *p_Var4;
  undefined4 *puVar5;
  ulonglong uVar6;
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0 local_18 [2];
  undefined4 local_14 [3];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x8a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  if (this->m_NumAltModesReturned != 0) {
    puVar5 = local_14;
    uVar6 = (ulonglong)this->m_NumAltModesReturned;
    p_Var4 = &(this->m_ActiveCommandCtx).CompletionData.field0_0x0.m_DataBlock.MessageIn.
              ConnectorStatus.field1_0x2;
    do {
      _Var1 = *p_Var4;
      *(_UCSI_GET_CONNECTOR_STATUS_IN_u_2_s_0 *)(puVar5 + -1) = p_Var4[-1];
      *puVar5 = CONCAT22(p_Var4[1],_Var1);
      puVar5 = puVar5 + 2;
      uVar6 = uVar6 - 1;
      p_Var4 = p_Var4 + 3;
    } while (uVar6 != 0);
    iVar2 = (*DAT_14001d368)(UcmDriverGlobals,p_Var3->UcmConnector,local_18);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x8b,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)iVar2);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x8c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportBatteryStatusChangeToUCM @ 140027940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportBatteryStatusChangeToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportBatteryStatusChangeToUCM(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_8 *p_Var1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x8d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar6 = 3;
  uVar7 = p_Var1->BatteryChargingStatus;
  uVar5 = (ulonglong)uVar7;
  if (p_Var1->BatteryChargingStatus == 0) {
    uVar6 = 1;
  }
  else if (uVar7 == 1) {
    uVar6 = 2;
    uVar5 = 0;
  }
  else {
    uVar4 = uVar7 - 2;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 != 0) {
      if (uVar4 != 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x8e,
                             &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                             (char)this->m_Ppm->_padding_,(char)uVar7);
        }
        goto LAB_140027abc;
      }
      uVar6 = 4;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,(ulonglong)uVar7,0x8f,
                        in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,uVar6,
                        (char)p_Var3->Id);
  }
  iVar2 = (*DAT_14001d340)(UcmDriverGlobals,p_Var3->UcmConnector,uVar6);
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x90,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar2);
  }
LAB_140027abc:
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 =
       (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 & 0xfdff;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x91,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportConnectorToUCM @ 140027b1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportConnectorToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportConnectorToUCM(Opm *this)

{
  undefined1 *puVar1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  CxDevice *pCVar4;
  undefined8 *puVar5;
  undefined8 local_c8;
  ulonglong uStack_c0;
  ulonglong local_b8;
  code *pcStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  code *local_90;
  code *pcStack_88;
  _UCM_PD_ALTERNATE_MODE *local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  ulong64 local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x92,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  local_68 = p_Var3->Id;
  local_a8 = 0;
  local_70 = 0x20;
  local_c8 = 0x100000028;
  uStack_c0 = CONCAT44(-(uint)((p_Var3->field10_0x29).Provider != 0),
                       (uint)(p_Var3->field10_0x29).Capabilities.OperationMode.AsUInt8) &
              0x700000007;
  pcStack_b0 = EvtUcmConnectorSetDataRole;
  local_b8 = (ulonglong)((p_Var3->field10_0x29).Capabilities.OperationMode.AsUInt8 >> 3 & 1);
  local_a0 = 0x100000030;
  uStack_98 = (ulonglong)((p_Var3->field10_0x29).Consumer | (p_Var3->field10_0x29).Provider * 2);
  local_90 = EvtUcmConnectorSetPowerRole;
  pcStack_88 = EvtUcmConnectorSetPowerLevel;
  local_80 = (_UCM_PD_ALTERNATE_MODE *)0x0;
  uStack_78 = 0;
  if (p_Var3->NumAltModes != 0) {
    local_80 = p_Var3->AltModes;
    uStack_78 = (ulonglong)p_Var3->NumAltModes;
  }
  local_60 = &local_c8;
  local_58 = &local_a0;
  local_40 = 0;
  uStack_48 = 0;
  local_20 = PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0;
  local_30 = 0;
  uStack_28 = 0;
  local_50 = 0x38;
  uStack_38 = 0x100000001;
  pCVar4 = Ppm::GetCxDevice(this->m_Ppm);
  iVar2 = (*DAT_14001d308)(UcmDriverGlobals,pCVar4->_padding_,&local_70,&local_50,
                           &p_Var3->UcmConnector);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x93,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar2);
  }
  else {
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01023 + 0x650))
                       (WdfDriverGlobals,p_Var3->UcmConnector,
                        PTR__WDF_PPM_UCM_CONNECTOR_CONTEXT_TYPE_INFO_14001d0f0);
    *puVar5 = p_Var3;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x94,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportDataDirectionChangeToUCM @ 140027d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportDataDirectionChangeToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportDataDirectionChangeToUCM(Opm *this)

{
  ulonglong uVar1;
  _PPM_CONNECTOR *p_Var2;
  undefined4 uVar3;
  uint uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x95,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
  p_Var2 = GetConnector(this,(uint)(uVar1 >> 0x10) & 0x7f);
  uVar4 = (uint)(uVar1 >> 0x17) & 7;
  if (uVar4 == 1) {
LAB_140027e5b:
    uVar3 = 1;
  }
  else {
    if (uVar4 != 2) {
      if (uVar4 == 5) goto LAB_140027e5b;
      if (uVar4 != 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x96,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)this->m_Ppm->_padding_,(char)uVar4);
        goto LAB_140027e89;
      }
    }
    uVar3 = 2;
  }
  (*DAT_14001d348)(UcmDriverGlobals,p_Var2->UcmConnector,
                   (byte)((uint)(this->m_ActiveCommandCtx).Status >> 0x1f) ^ 1,uVar3);
LAB_140027e89:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x97,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportDataDirectionChangeToUCMOnConnectorChange @ 140027edc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportDataDirectionChangeToUCMOnConnectorChange(void)
   __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportDataDirectionChangeToUCMOnConnectorChange(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2 *p_Var1;
  _PPM_CONNECTOR *p_Var2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  char cVar6;
  uint uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x98,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var2 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar7 = p_Var1.ConnectorPartnerType;
  if (uVar7 == 1) {
    iVar3 = 2;
    uVar5 = 0;
  }
  else if (uVar7 == 2) {
    iVar3 = 1;
    uVar5 = 0;
  }
  else if (uVar7 == 3) {
    iVar3 = 3;
    uVar5 = 0;
  }
  else if (uVar7 == 4) {
    iVar3 = 4;
    uVar5 = 0;
  }
  else {
    uVar4 = uVar7 - 5;
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      iVar3 = 6;
    }
    else {
      if (uVar4 != 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0x99,
                             &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                             (char)this->m_Ppm->_padding_,p_Var1.ConnectorPartnerType);
        }
        goto LAB_140028057;
      }
      iVar3 = 5;
    }
  }
  if (((iVar3 - 1U & 0xfffffffc) == 0) && (iVar3 != 3)) {
    cVar6 = (iVar3 == 2) + '\x01';
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,(ulonglong)uVar7,0x9a,
                          in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,cVar6,
                          (char)p_Var2->Id);
    }
    (*DAT_14001d348)(UcmDriverGlobals,p_Var2->UcmConnector,1,cVar6);
  }
LAB_140028057:
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 =
       (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 & 0xf7ff;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x9b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportEndOfConnectorCreations @ 1400280b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportEndOfConnectorCreations(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportEndOfConnectorCreations(Opm *this)

{
  CxDevice *pCVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x9c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  pCVar1 = Ppm::GetCxDevice(this->m_Ppm);
  (*DAT_14001d308)(UcmDriverGlobals,pCVar1->_padding_,0,0,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x9d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportOvercurrentToUCM @ 140028188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportOvercurrentToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportOvercurrentToUCM(Opm *this)

{
  int iVar1;
  _PPM_CONNECTOR *p_Var2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xc6,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var2 = GetConnector(this,this->m_CurrentConnectorNumber);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  iVar1 = (*DAT_14001d3a8)(UcmDriverGlobals,p_Var2->UcmConnector);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,200,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xc9,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportPDSourceCapsToUCM @ 1400282dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportPDSourceCapsToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportPDSourceCapsToUCM(Opm *this)

{
  ulong64 *puVar1;
  ulonglong uVar2;
  int iVar3;
  _PPM_CONNECTOR *p_Var4;
  UCMCONNECTOR__ *pUVar5;
  undefined8 in_R8;
  _UCM_PD_POWER_DATA_OBJECT *p_Var6;
  undefined2 uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x9e,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar2 = (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
  p_Var4 = GetConnector(this,this->m_CurrentConnectorNumber);
  puVar1 = &p_Var4->Id;
  if ((uVar2 >> 0x17 & 1) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0xa1,
                         in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)*puVar1);
    }
    p_Var6 = (this->m_ConnectorChangeCtx).Pdos;
    pUVar5 = p_Var4->UcmConnector;
    iVar3 = (*DAT_14001d328)(UcmDriverGlobals,pUVar5,p_Var6,(this->m_ConnectorChangeCtx).PdoCount);
    if (-1 < iVar3) goto LAB_14002846c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar7 = 0xa2;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x9f,
                         in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)*puVar1);
    }
    p_Var6 = (this->m_ConnectorChangeCtx).Pdos;
    pUVar5 = p_Var4->UcmConnector;
    iVar3 = (*DAT_14001d330)(UcmDriverGlobals,pUVar5,p_Var6,(this->m_ConnectorChangeCtx).PdoCount);
    if (-1 < iVar3) goto LAB_14002846c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar7 = 0xa0;
  }
  WPP_RECORDER_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar5,p_Var6,uVar7,
                      in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)*puVar1,
                      (char)iVar3);
LAB_14002846c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xa3,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportPowerDirectionChangeToUCM @ 1400284c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCM(Opm *this)

{
  ulonglong uVar1;
  _PPM_CONNECTOR *p_Var2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xa4,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
  p_Var2 = GetConnector(this,(uint)(uVar1 >> 0x10) & 0x7f);
  uVar6 = 1;
  uVar5 = (uint)(uVar1 >> 0x17) & 7;
  if (uVar5 == 1) {
LAB_1400285a9:
    uVar4 = 2;
  }
  else {
    if (uVar5 != 2) {
      if (uVar5 == 5) goto LAB_1400285a9;
      if (uVar5 != 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xa5,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)this->m_Ppm->_padding_,(char)uVar5);
        goto LAB_140028623;
      }
    }
    uVar4 = 1;
  }
  if ((this->m_ActiveCommandCtx).Status < 0) {
    uVar6 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0xa7;
      bVar3 = 2;
      uVar6 = 0;
      goto LAB_1400285de;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar7 = 0xa6;
    bVar3 = 4;
    uVar6 = 1;
LAB_1400285de:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,10,uVar7,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,uVar4);
  }
  (*DAT_14001d350)(UcmDriverGlobals,p_Var2->UcmConnector,uVar6,uVar4);
LAB_140028623:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xa8,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportPowerDirectionChangeToUCMInternal @ 140028678 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMInternal(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMInternal(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2 *p_Var1;
  _PPM_CONNECTOR *p_Var2;
  undefined4 uVar3;
  ushort uVar4;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xa9,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var2 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar4 = p_Var1->PowerDirection;
  if (p_Var1->PowerDirection == 0) {
    uVar3 = 1;
  }
  else {
    if (uVar4 != 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xaa,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)uVar4);
      goto LAB_14002876c;
    }
    uVar3 = 2;
  }
  (*DAT_14001d350)(UcmDriverGlobals,p_Var2->UcmConnector,1,uVar3);
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 =
       (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 & 0xefff;
LAB_14002876c:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xab,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportPowerDirectionChangeToUCMOnAttach @ 1400287bc =====

/* private: void __cdecl UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMOnAttach(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMOnAttach(Opm *this)

{
  _PPM_CONNECTOR *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xae,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = GetConnector(this,this->m_CurrentConnectorNumber);
  ReportPowerDirectionChangeToUCMInternal(this);
  p_Var1->AltModesReported = '\0';
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xaf,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportPowerDirectionChangeToUCMOnConnectorChange @ 140028884 =====

/* private: void __cdecl UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMOnConnectorChange(void)
   __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportPowerDirectionChangeToUCMOnConnectorChange(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xac,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  ReportPowerDirectionChangeToUCMInternal(this);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xad,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportRDOToUCM @ 14002892c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl UcmUcsiCx::Opm::ReportRDOToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportRDOToUCM(Opm *this)

{
  ulonglong uVar1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  UCMCONNECTOR__ *pUVar4;
  undefined8 in_R8;
  undefined4 *puVar5;
  undefined1 auStackY_78 [32];
  undefined *in_stack_ffffffffffffffa8;
  undefined4 local_38;
  undefined4 local_34;
  ulong local_30;
  _UCM_CHARGING_STATE local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffa8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xb2,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = (this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.m_DataBlock.Control.AsUInt64;
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  local_2c = UcmChargingStateInvalid;
  local_38 = 0x10;
  local_34 = 3;
  if ((uVar1 >> 0x17 & 1) != 0) {
    local_2c = (this->m_ConnectorChangeCtx).ChargingState;
  }
  local_30 = (this->m_ConnectorChangeCtx).Rdo.Ul;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0xb3,
                       in_stack_ffffffffffffffa8,(char)this->m_Ppm->_padding_,(char)p_Var3->Id);
  }
  pUVar4 = p_Var3->UcmConnector;
  puVar5 = &local_38;
  iVar2 = (*DAT_14001d338)(UcmDriverGlobals);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar4,puVar5,0xb4,
                        in_stack_ffffffffffffffa8,(char)this->m_Ppm->_padding_,(char)p_Var3->Id,
                        (char)iVar2);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xb5,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportSetPowerLevelCompletionToUCM @ 140028ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportSetPowerLevelCompletionToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportSetPowerLevelCompletionToUCM(Opm *this)

{
  _PPM_CONNECTOR *p_Var1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xb0,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var1 = GetConnector(this,(uint)((this->m_ActiveCommandCtx).OpmCommand.DataBlock.field0_0x0.
                                    m_DataBlock.Control.AsUInt64 >> 0x10) & 0x7f);
  (*DAT_14001d3a0)(UcmDriverGlobals,p_Var1->UcmConnector,
                   &(this->m_UcmConnectorCallbackInfo).SetPowerLevelParams,
                   (this->m_ActiveCommandCtx).Status);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xb1,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportTypeCAttachToUCM @ 140028ba8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportTypeCAttachToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportTypeCAttachToUCM(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_8 *p_Var1;
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2 *p_Var2;
  ushort uVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  _PPM_CONNECTOR *p_Var7;
  ushort uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 in_R8;
  undefined2 uVar11;
  undefined1 auStackY_88 [32];
  undefined *in_stack_ffffffffffffff98;
  byte bVar12;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffff98 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xb6,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  local_48 = 0;
  uStack_40 = 0;
  p_Var7 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar10 = 4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0xb7,
                       in_stack_ffffffffffffff98,(char)this->m_Ppm->_padding_,(char)p_Var7->Id);
  }
  uVar8 = *(ushort *)((longlong)&this->field26_0xc58 + 2);
  uVar9 = 3;
  uVar3 = uVar8 >> 0xd;
  bVar12 = (byte)(uVar8 >> 0xd);
  if (uVar3 == 1) {
    uVar5 = 2;
LAB_140028d04:
    uStack_40 = 0;
    local_48 = CONCAT44(uVar5,0x10);
    if ((uVar8 & 0x10) == 0) {
      bVar12 = p_Var1->BatteryChargingStatus;
      if (p_Var1->BatteryChargingStatus == 0) {
        uVar9 = 1;
      }
      else if (bVar12 == 1) {
        uVar9 = 2;
      }
      else if (bVar12 != 2) {
        if (bVar12 != 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140028e2f;
          uVar11 = 0xb9;
          goto LAB_140028cb7;
        }
        uVar9 = 4;
      }
      uStack_40 = (ulonglong)uVar9 << 0x20;
      if ((uVar9 == 1) &&
         ((bVar4 = ShouldIgnoreBatteryNotChargingStatus(this), bVar4 ||
          (((this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 >> 9 & 1) == 0)))
         ) {
        uStack_40 = uStack_40 & 0xffffffff;
      }
    }
    uVar8 = p_Var2->PowerOperationMode;
    if (((uVar8 == 1) || (uVar8 == 2)) || (uVar8 == 3)) {
      uVar10 = 1;
    }
    else if (uVar8 == 4) {
      uVar10 = 2;
    }
    else if (uVar8 != 5) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140028e2f;
      uVar11 = 0xba;
      bVar12 = p_Var2->PowerOperationMode;
      goto LAB_140028cb7;
    }
    uStack_40 = CONCAT44(uStack_40._4_4_,uVar10);
    iVar6 = (*DAT_14001d310)(UcmDriverGlobals,p_Var7->UcmConnector,&local_48);
    if ((iVar6 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xbb,
                         &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                         (char)this->m_Ppm->_padding_,(char)iVar6);
    }
  }
  else {
    if (uVar3 == 2) {
      uVar5 = 1;
      goto LAB_140028d04;
    }
    if (uVar3 == 3) {
      uVar5 = 3;
      goto LAB_140028d04;
    }
    if (uVar3 == 4) {
      uVar5 = 4;
      goto LAB_140028d04;
    }
    if (uVar3 == 5) {
      uVar5 = 6;
      goto LAB_140028d04;
    }
    if (uVar3 == 6) {
      uVar5 = 5;
      goto LAB_140028d04;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140028e2f;
    uVar11 = 0xb8;
LAB_140028cb7:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,uVar11,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,bVar12);
  }
LAB_140028e2f:
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 =
       (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 & 0xb5fb;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xbc,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportTypeCCurrentAdChangedToUCM @ 140028e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportTypeCCurrentAdChangedToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportTypeCCurrentAdChangedToUCM(Opm *this)

{
  _UCSI_GET_CONNECTOR_STATUS_IN_u_2 *p_Var1;
  int iVar2;
  _PPM_CONNECTOR *p_Var3;
  UCMCONNECTOR__ *pUVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xbd,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var3 = GetConnector(this,this->m_CurrentConnectorNumber);
  uVar6 = p_Var1->PowerOperationMode;
  if (((uVar6 == 1) || (uVar6 == 2)) || (uVar6 == 3)) {
    uVar5 = 1;
  }
  else if (uVar6 == 4) {
    uVar5 = 2;
  }
  else {
    if (uVar6 != 5) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xbe,
                           &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,
                           (char)this->m_Ppm->_padding_,p_Var1->PowerOperationMode);
      }
      goto LAB_140029013;
    }
    uVar5 = 4;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,(ulonglong)uVar6,0xbf,
                       in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)p_Var3->Id);
  }
  pUVar4 = p_Var3->UcmConnector;
  uVar7 = (ulonglong)uVar5;
  iVar2 = (*DAT_14001d320)(UcmDriverGlobals);
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pUVar4,uVar7,0xc0,
                        in_stack_ffffffffffffffc8,(char)this->m_Ppm->_padding_,(char)p_Var3->Id,
                        (char)iVar2);
  }
LAB_140029013:
  (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 =
       (this->field26_0xc58).m_ConnectorStatus.ConnectorStatusChange.AsUInt16 & 0xfffb;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xc1,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ReportTypeCDetachToUCM @ 140029074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl UcmUcsiCx::Opm::ReportTypeCDetachToUCM(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::ReportTypeCDetachToUCM(Opm *this)

{
  int iVar1;
  _PPM_CONNECTOR *p_Var2;
  undefined8 in_R8;
  undefined *in_stack_ffffffffffffffd8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_R8 = 10;
    in_stack_ffffffffffffffd8 = &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xc2,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  p_Var2 = GetConnector(this,this->m_CurrentConnectorNumber);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0xc3,
                       in_stack_ffffffffffffffd8,(char)this->m_Ppm->_padding_,(char)p_Var2->Id);
  }
  iVar1 = (*DAT_14001d318)(UcmDriverGlobals,p_Var2->UcmConnector);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,10,0xc4,
                       &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids,(char)this->m_Ppm->_padding_
                       ,(char)iVar1);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0xc5,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== SendTestUcsiCommand @ 1400291c4 =====

/* public: void __cdecl UcmUcsiCx::Opm::SendTestUcsiCommand(class UcmUcsiCx::UcsiDataBlock const &
   __ptr64) __ptr64 */

void __thiscall UcmUcsiCx::Opm::SendTestUcsiCommand(Opm *this,UcsiDataBlock *param_1)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x2a,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  UcsiDataBlock::operator=(&this->m_ActiveTestCommand,param_1);
  OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
            ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,7);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x2b,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== ShouldIgnoreBatteryNotChargingStatus @ 140029288 =====

/* private: bool __cdecl UcmUcsiCx::Opm::ShouldIgnoreBatteryNotChargingStatus(void) __ptr64 */

bool __thiscall UcmUcsiCx::Opm::ShouldIgnoreBatteryNotChargingStatus(Opm *this)

{
  ushort uVar1;
  bool bVar2;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x33,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  uVar1 = (this->m_Ppm->m_UcsiVersion).AsUInt16;
  bVar2 = false;
  if (((uVar1 & 0xff00) < 0x101) && ((uVar1 & 0xf0) < 0x10)) {
    bVar2 = false;
    if (this->m_BatteryNotChargingNotificationDisableOverride == '\0') {
      bVar2 = true;
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x34,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return bVar2;
}



===== Start @ 140029370 =====

/* public: void __cdecl UcmUcsiCx::Opm::Start(void) __ptr64 */

void __thiscall UcmUcsiCx::Opm::Start(Opm *this)

{
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x14,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  KeResetEvent(&this->m_StoppedNotificationEvent);
  OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
            ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this,0x10);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x15,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== Initialize @ 14002942c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl UcmUcsiCx::TestInterface::Initialize(class UcmUcsiCx::CxDevice * __ptr64)
   __ptr64 */

long __thiscall UcmUcsiCx::TestInterface::Initialize(TestInterface *this,CxDevice *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7b;
  code *local_60;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,10,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  memset(&local_88,0,0x60);
  this->m_CxDevice = param_1;
  local_c8 = 0;
  uStack_c0 = 0;
  local_98 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  bVar1 = IsEnabled(this);
  if (bVar1) {
    local_88 = 0x60;
    local_7b = 1;
    local_60 = EvtIoDeviceControl;
    local_84 = 1;
    local_80 = 1;
    local_c8 = CONCAT44(local_c8._4_4_,0x38);
    uStack_b0 = 0x100000002;
    iVar2 = (**(code **)(WdfFunctions_01023 + 0x4c0))
                      (WdfDriverGlobals,this->m_CxDevice->_padding_,&local_88,&local_c8,
                       &this->m_Queue);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0xb,
                           &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                           (char)this->m_CxDevice->_padding_,(char)iVar2);
      }
      this->m_Queue = (WDFQUEUE__ *)0x0;
    }
    else {
      iVar2 = (**(code **)(WdfFunctions_01023 + 0x268))
                        (WdfDriverGlobals,this->m_CxDevice->_padding_,
                         &GUID_DEVINTERFACE_UCMUCSICX_TEST,0);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0xc,
                           &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                           (char)this->m_CxDevice->_padding_,(char)iVar2);
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,0xb,0xd,
                          &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                          (char)this->m_CxDevice->_padding_);
      }
    }
  }
  else {
    iVar2 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0xe,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return iVar2;
}



===== IoctlGetDeviceInfo @ 140029674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::IoctlGetDeviceInfo(void) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::IoctlGetDeviceInfo(TestInterface *this)

{
  CxDevice *pCVar1;
  _UCMUCSI_PRIVATE_DRIVER_GLOBALS *p_Var2;
  WDFREQUEST__ *pWVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  uchar *puVar7;
  longlong lVar8;
  ushort *local_res8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x17,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  local_res8 = (ushort *)0x0;
  if (this->m_OutputBufferLength < 0x38) {
    iVar4 = -0x3fffffdd;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400299f0;
    WPP_RECORDER_SF_qPP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    iVar4 = -0x3fffffdd;
  }
  else {
    iVar4 = (**(code **)(WdfFunctions_01023 + 0x870))
                      (WdfDriverGlobals,this->m_ActiveRequest,0x38,&local_res8,0);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400299f0;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x19,
                         &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                         (char)this->m_CxDevice->_padding_,(char)iVar4);
    }
    else {
      *local_res8 = (this->m_CxDevice->m_Ppm->m_UcsiVersion).AsUInt16;
      local_res8[1] = (this->m_CxDevice->m_Ppm->m_PpmConfig).UcsiVersion.AsUInt16;
      *(_WDF_TRI_STATE *)(local_res8 + 2) =
           (this->m_CxDevice->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled;
      *(bool *)(local_res8 + 4) =
           (this->m_CxDevice->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue;
      pCVar1 = this->m_CxDevice;
      if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
         (pCVar1->m_PrivateGlobals == (_UCMUCSI_PRIVATE_DRIVER_GLOBALS *)0x0)) {
        RtlAssert("m_PrivateGlobals != nullptr",
                  "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\CxDevice.h",0x92,0);
      }
      p_Var2 = pCVar1->m_PrivateGlobals;
      *(ulong *)(local_res8 + 6) = (p_Var2->ClientClassVersion).Major;
      *(ulong *)(local_res8 + 8) = (p_Var2->ClientClassVersion).Minor;
      *(ulong *)(local_res8 + 10) = (p_Var2->ClientClassVersion).Build;
      pCVar1 = this->m_CxDevice;
      if (((*(uint *)(WdfDriverGlobals + 8) & 4) != 0) &&
         (pCVar1->m_PrivateGlobals == (_UCMUCSI_PRIVATE_DRIVER_GLOBALS *)0x0)) {
        RtlAssert("m_PrivateGlobals != nullptr",
                  "onecore\\drivers\\wdm\\usb\\ucmucsi\\cx\\src\\CxDevice.h",0x8b,0);
      }
      lVar8 = 0x20;
      puVar6 = local_res8 + 0xc;
      puVar7 = pCVar1->m_PrivateGlobals->ClientImageName;
      do {
        if ((lVar8 == -0x7fffffde) || (*puVar7 == '\0')) break;
        *(uchar *)puVar6 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar6 = (ushort *)((longlong)puVar6 + 1);
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      puVar5 = (ushort *)((longlong)puVar6 + -1);
      if (lVar8 != 0) {
        puVar5 = puVar6;
      }
      *(char *)puVar5 = '\0';
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDDDDDDLDDDDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      (**(code **)(WdfFunctions_01023 + 0x898))(WdfDriverGlobals,this->m_ActiveRequest,0x38);
      iVar4 = 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
LAB_1400299f0:
  pWVar3 = this->m_ActiveRequest;
  this->m_ActiveRequest = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar3,iVar4);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x1c,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== IoctlSendCommand @ 140029a68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::IoctlSendCommand(void) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::IoctlSendCommand(TestInterface *this)

{
  CxDevice *pCVar1;
  ulonglong uVar2;
  WDFREQUEST__ *pWVar3;
  int iVar4;
  Opm *this_00;
  undefined8 uVar5;
  undefined8 *local_res8;
  undefined *in_stack_fffffffffffffd98;
  UcsiDataBlock_u_0 local_238;
  undefined1 local_28;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x1d,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  pCVar1 = this->m_CxDevice;
  local_res8 = (undefined8 *)0x0;
  if ((pCVar1->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
    iVar4 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0xb;
      in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x1e,
                         &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,(char)pCVar1->_padding_,
                         0x18);
      iVar4 = -0x3fffff45;
LAB_140029c35:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar5,0x21,in_stack_fffffffffffffd98
                   ,(char)this->m_CxDevice->_padding_,(char)this->m_ActiveRequestIoctl,
                   (char)this->m_ActiveRequest,(char)iVar4);
      }
    }
  }
  else {
    uVar2 = this->m_InputBufferLength;
    uVar5 = 0x30;
    if ((uVar2 < 0x30) || (this->m_OutputBufferLength < 0x30)) {
      iVar4 = -0x3fffffdd;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qPPP
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0x30,0x1f,
                   in_stack_fffffffffffffd98,(char)pCVar1->_padding_,0x30,(char)uVar2,
                   (char)this->m_OutputBufferLength);
        iVar4 = -0x3fffffdd;
        goto LAB_140029c35;
      }
    }
    else {
      iVar4 = (**(code **)(WdfFunctions_01023 + 0x868))
                        (WdfDriverGlobals,this->m_ActiveRequest,0x30,&local_res8,0);
      if (-1 < iVar4) {
        local_28 = 0;
        local_238._0_8_ = *local_res8;
        local_238.m_DataBlock.Control = (_UCSI_CONTROL)((_UCSI_CONTROL *)(local_res8 + 1))->AsUInt64
        ;
        local_238.m_DataBlockShared.MessageInStart = *(uchar (*) [8])(local_res8 + 2);
        local_238.m_DataBlockEx.MessageIn._8_8_ = local_res8[3];
        local_238.m_DataBlockEx.MessageIn._16_8_ = local_res8[4];
        local_238.m_DataBlockEx.MessageIn._24_8_ = local_res8[5];
        this_00 = Ppm::GetOpm(this->m_CxDevice->m_Ppm);
        Opm::SendTestUcsiCommand(this_00,(UcsiDataBlock *)&local_238.m_DataBlock);
        goto LAB_140029c9a;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0xb;
        in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x20,
                           &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                           (char)this->m_CxDevice->_padding_,(char)iVar4);
        goto LAB_140029c35;
      }
    }
  }
  pWVar3 = this->m_ActiveRequest;
  this->m_ActiveRequest = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar3,iVar4);
LAB_140029c9a:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x22,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== IoctlSendCommandEx @ 140029cec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::IoctlSendCommandEx(void) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::IoctlSendCommandEx(TestInterface *this)

{
  CxDevice *pCVar1;
  ulonglong uVar2;
  WDFREQUEST__ *pWVar3;
  ulong64 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  Opm *this_00;
  UcsiDataBlock *pUVar11;
  UcsiDataBlock *pUVar12;
  longlong lVar13;
  undefined8 uVar14;
  undefined8 *local_res8;
  undefined *in_stack_fffffffffffffd98;
  UcsiDataBlock local_238;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x23,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  pCVar1 = this->m_CxDevice;
  local_res8 = (undefined8 *)0x0;
  if ((pCVar1->m_Ppm->m_PpmConfig).UcsiDataBlockExEnabled == WdfTrue) {
    uVar2 = this->m_InputBufferLength;
    uVar14 = 0x210;
    if ((uVar2 < 0x210) || (this->m_OutputBufferLength < 0x210)) {
      iVar9 = -0x3fffffdd;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qPPP
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,0x210,0x25,
                   in_stack_fffffffffffffd98,(char)pCVar1->_padding_,0x10,(char)uVar2,
                   (char)this->m_OutputBufferLength);
        iVar9 = -0x3fffffdd;
        goto LAB_140029efd;
      }
    }
    else {
      iVar9 = (**(code **)(WdfFunctions_01023 + 0x868))
                        (WdfDriverGlobals,this->m_ActiveRequest,0x210,&local_res8,0);
      if (-1 < iVar9) {
        lVar13 = 4;
        local_238.m_UcsiDataBlockExEnabled = true;
        puVar8 = local_res8;
        pUVar12 = &local_238;
        do {
          pUVar11 = pUVar12;
          puVar10 = puVar8;
          uVar14 = *puVar10;
          uVar4 = puVar10[1];
          uVar5 = puVar10[2];
          uVar6 = puVar10[3];
          (pUVar11->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 = (short)uVar14;
          *(short *)&(pUVar11->field0_0x0).m_DataBlock.field_0x2 =
               (short)((ulonglong)uVar14 >> 0x10);
          (pUVar11->field0_0x0).m_DataBlock.CCI.AsUInt32 = (int)((ulonglong)uVar14 >> 0x20);
          (pUVar11->field0_0x0).m_DataBlock.Control.AsUInt64 = uVar4;
          uVar14 = puVar10[4];
          uVar7 = puVar10[5];
          *(undefined8 *)(pUVar11->field0_0x0).m_DataBlockEx.MessageIn = uVar5;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 8) = uVar6;
          uVar5 = puVar10[6];
          uVar6 = puVar10[7];
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x10) = uVar14;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x18) = uVar7;
          uVar14 = puVar10[8];
          uVar7 = puVar10[9];
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x20) = uVar5;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x28) = uVar6;
          uVar5 = puVar10[10];
          uVar6 = puVar10[0xb];
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x30) = uVar14;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x38) = uVar7;
          uVar14 = puVar10[0xc];
          uVar7 = puVar10[0xd];
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x40) = uVar5;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x48) = uVar6;
          uVar5 = puVar10[0xe];
          uVar6 = puVar10[0xf];
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x50) = uVar14;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x58) = uVar7;
          pUVar12 = (UcsiDataBlock *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x70);
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x60) = uVar5;
          *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x68) = uVar6;
          lVar13 = lVar13 + -1;
          puVar8 = puVar10 + 0x10;
        } while (lVar13 != 0);
        uVar14 = puVar10[0x10];
        uVar5 = puVar10[0x11];
        (pUVar12->field0_0x0).m_DataBlock.UcsiVersion.AsUInt16 = (short)uVar14;
        *(short *)&(pUVar12->field0_0x0).m_DataBlock.field_0x2 = (short)((ulonglong)uVar14 >> 0x10);
        (pUVar12->field0_0x0).m_DataBlock.CCI.AsUInt32 = (int)((ulonglong)uVar14 >> 0x20);
        *(undefined8 *)((pUVar11->field0_0x0).m_DataBlockEx.MessageIn + 0x78) = uVar5;
        this_00 = Ppm::GetOpm(this->m_CxDevice->m_Ppm);
        Opm::SendTestUcsiCommand(this_00,&local_238);
        goto LAB_140029f64;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar14 = 0xb;
        in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x26,
                           &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                           (char)this->m_CxDevice->_padding_,(char)iVar9);
        goto LAB_140029efd;
      }
    }
  }
  else {
    iVar9 = -0x3fffff45;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar14 = 0xb;
      in_stack_fffffffffffffd98 = &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids;
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xb,0x24,
                         &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,(char)pCVar1->_padding_,
                         0x1c);
      iVar9 = -0x3fffff45;
LAB_140029efd:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar14,0x27,
                   in_stack_fffffffffffffd98,(char)this->m_CxDevice->_padding_,
                   (char)this->m_ActiveRequestIoctl,(char)this->m_ActiveRequest,(char)iVar9);
      }
    }
  }
  pWVar3 = this->m_ActiveRequest;
  this->m_ActiveRequest = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar3,iVar9);
LAB_140029f64:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x28,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return;
}



===== IoctlSimulateFailure @ 140029fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl UcmUcsiCx::TestInterface::IoctlSimulateFailure(void) __ptr64 */

void __thiscall UcmUcsiCx::TestInterface::IoctlSimulateFailure(TestInterface *this)

{
  WDFREQUEST__ **ppWVar1;
  WDFREQUEST__ *pWVar2;
  Opm *this_00;
  
  ppWVar1 = &this->m_ActiveRequest;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),this->m_CxDevice,0xb,0x29,
                       &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                       (char)this->m_CxDevice->_padding_,(char)*ppWVar1);
  }
  pWVar2 = *ppWVar1;
  *ppWVar1 = (WDFREQUEST__ *)0x0;
  (**(code **)(WdfFunctions_01023 + 0x838))(WdfDriverGlobals,pWVar2);
  this_00 = Ppm::GetOpm(this->m_CxDevice->m_Ppm);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x2c,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  Opm::SetUnrecoverableFailureContext(this_00,TestSimulatedFailure,Undefined,0);
  OsPolicyManagerStateMachine<UcmUcsiCx::Opm>::EnqueueEvent
            ((OsPolicyManagerStateMachine<UcmUcsiCx::Opm> *)this_00,0x13);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,10,0x2d,
                     &WPP_87e79890d12033c0f94f8f0722aba0fa_Traceguids);
  }
  return;
}



===== IsEnabled @ 14002a0f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: bool __cdecl UcmUcsiCx::TestInterface::IsEnabled(void) __ptr64 */

bool __thiscall UcmUcsiCx::TestInterface::IsEnabled(TestInterface *this)

{
  int iVar1;
  bool bVar2;
  undefined2 uVar3;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0xf,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  local_res10 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_res8[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x180))
                    (WdfDriverGlobals,this->m_CxDevice->_padding_,1,0x20019,0,&local_res10);
  bVar2 = false;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar3 = 0x10;
  }
  else {
    RtlInitUnicodeString(&local_38,L"TestInterfaceEnabled");
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res10,&local_38,local_res8);
    if (-1 < iVar1) {
      bVar2 = false;
      if (local_res8[0] != 0) {
        bVar2 = true;
      }
      goto LAB_14002a25e;
    }
    if (iVar1 == -0x3fffffcc) goto LAB_14002a25e;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar3 = 0x11;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xb,uVar3,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids,
                     (char)this->m_CxDevice->_padding_,(char)iVar1);
LAB_14002a25e:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xb,0x12,
                     &WPP_dd4cc20ef9363f276059349b48a807d6_Traceguids);
  }
  return bVar2;
}



===== IsForceCrashOnCommandFailureEnabled @ 14002a2ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* bool __cdecl UcmUcsiCx::Verify::IsForceCrashOnCommandFailureEnabled(struct WDFDEVICE__ * __ptr64)
    */

bool __cdecl UcmUcsiCx::Verify::IsForceCrashOnCommandFailureEnabled(WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined2 uVar4;
  int local_res10 [2];
  undefined8 local_res18;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xc,0x10,
                     &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids);
  }
  local_28 = 0;
  uStack_20 = 0;
  local_res18 = 0;
  local_res10[0] = 0;
  uVar2 = (**(code **)(WdfFunctions_01023 + 0x138))(WdfDriverGlobals,param_1);
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x3b8))(WdfDriverGlobals,uVar2,0x20019,0,&local_res18);
  bVar3 = false;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar4 = 0x11;
  }
  else {
    RtlInitUnicodeString(&local_28,L"ForceCommandFailureCrash");
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x780))
                      (WdfDriverGlobals,local_res18,&local_28,local_res10);
    if (-1 < iVar1) {
      bVar3 = false;
      if (local_res10[0] != 0) {
        bVar3 = true;
      }
      goto LAB_14002a418;
    }
    if (iVar1 == -0x3fffffcc) goto LAB_14002a418;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar4 = 0x12;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,0xc,uVar4,
                     &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids,(char)param_1,(char)iVar1);
LAB_14002a418:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xc,0x13,
                     &WPP_06b0a02e56f33a37991e8012de016a69_Traceguids);
  }
  return bVar3;
}



===== WaitForSingleObject @ 14002a468 =====

/* long __cdecl UcmUcsiCx::Verify::WaitForSingleObject(struct _KEVENT * __ptr64,char const *
   __ptr64,void * __ptr64) */

long __cdecl UcmUcsiCx::Verify::WaitForSingleObject(_KEVENT *param_1,char *param_2,void *param_3)

{
  int iVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined8 local_res10 [3];
  undefined8 *puVar5;
  
  local_res10[0] = 0xffffffffee1e5d00;
  puVar5 = local_res10;
  uVar3 = 0;
  iVar1 = KeWaitForSingleObject(param_1,0,0,0);
  if (iVar1 == 0x102) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0x102;
    }
    uVar4 = 0xe;
    bVar2 = 3;
  }
  else {
    if (-1 < iVar1) {
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xf;
    bVar2 = 2;
  }
  WPP_RECORDER_SF_qqs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar2,uVar3,uVar4,puVar5,
                      (char)param_3,(char)SystemReserved1[0xf]);
  return iVar1;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 14002a524 =====

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
  *(undefined8 *)(puVar7 + -8) = 0x14002a587;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14002a5a7;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14002a5bb;
  return iVar6;
}



===== _tlgEnableCallback @ 14002a5e0 =====

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



===== AuxKlibQueryModuleInformation @ 14002a65c =====

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
  if (DAT_14001d4d8 == 1) {
    if (DAT_14001d4d0 == (code *)0x0) {
      uVar5 = (ulonglong)(-(uint)((param_3 & 7) != 0) & 0xc00000f1);
      if ((param_3 & 7) == 0) {
        puVar7 = local_158;
        uVar12 = 0x130;
        while( true ) {
          uVar4 = ZwQuerySystemInformation(0xb,puVar7,uVar12,local_168);
          uVar5 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) break;
          if (uVar4 != 0xc0000004) goto LAB_14002a80a;
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
LAB_14002a80a:
        if (puVar7 != local_158) {
          ExFreePoolWithTag(puVar7,0);
        }
      }
    }
    else {
      uVar5 = (*DAT_14001d4d0)(param_1,0x110,param_3);
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  return uVar5;
}



===== AuxKlibQueryModuleInformation$filt$0 @ 14002a8ae =====

bool AuxKlibQueryModuleInformation_filt_0(undefined8 *param_1)

{
  return *(int *)*param_1 == -0x3fffff66;
}



===== __security_init_cookie @ 14002b008 =====

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



===== CreateAndInit @ 14002b03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: static long __cdecl UcmUcsiCx::Driver::CreateAndInit(struct _DRIVER_OBJECT *
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl UcmUcsiCx::Driver::CreateAndInit(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStackY_108 [32];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  longlong lStack_a8;
  ulonglong local_a0;
  undefined8 local_98;
  code *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  _DAT_14001d498 = 1;
  local_a0 = (ulonglong)(uint)local_a0;
  local_58 = 0;
  uStack_50 = 0;
  _WPP_MAIN_CB = 0;
  DAT_14001d478 = &WPP_ThisDir_CTLGUID_UcmUcsiCx;
  DAT_14001d480 = 0;
  _DAT_14001d490 = 0;
  _DAT_14001d4b0 = 0;
  _DAT_14001d4b8 = 0;
  WppLoadTracingSupport();
  _DAT_14001d490 = 0;
  WppInitKm(param_1,param_2);
  local_58 = CONCAT35(local_58._5_3_,0x100000010);
  uStack_50 = 0x200000001;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_58);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  wil_InitializeFeatureStaging();
  local_b0 = 0;
  lStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitUnicodeString(&local_c0,0);
    iVar3 = IoQueryFullDriverPath(param_1,&local_c0);
    if (-1 < iVar3) {
      iVar3 = RtlUnicodeStringToAnsiString(&local_b0,&local_c0,1);
      ExFreePoolWithTag(uStack_b8,0);
      if (-1 < iVar3) {
        uVar1 = (uint)(ushort)local_b0;
        do {
          uVar2 = uVar1;
          uVar1 = uVar2 - 1;
          if (uVar1 == 0) goto LAB_14002b214;
        } while (*(char *)((ulonglong)uVar1 + lStack_a8) != '\\');
        if (uVar1 != (ushort)local_b0) {
          local_78 = 0;
          uStack_70 = 0;
          RtlInitAnsiString(&local_78,(ulonglong)uVar2 + lStack_a8);
          local_68 = local_78;
          uStack_60 = uStack_70;
          InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_68);
        }
LAB_14002b214:
        RtlFreeAnsiString(&local_b0);
      }
    }
  }
  McGenEventRegister_EtwRegister();
  m_TestSigning = CheckTestSigning();
  local_90 = EvtDriverUnload;
  local_a0 = 0x20;
  local_98 = 0;
  local_88 = 1;
  local_84 = 0x78435555;
  iVar3 = (**(code **)(WdfFunctions_01023 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b3d6;
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xb,
                       &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,(char)param_1,(char)iVar3);
  }
  else {
    iVar3 = RegisterClassExtension(param_1,param_2);
    if (-1 < iVar3) {
      m_AllowBinding1_1FromAnyClients = IsAllowBinding1_1FromAnyClientsEnabled((WDFDRIVER__ *)0x0);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if ((m_AllowBinding1_1FromAnyClients != false) && (m_TestSigning == false)) {
        m_AllowBinding1_1FromAnyClients = false;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          m_AllowBinding1_1FromAnyClients = false;
          return iVar3;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,5,0xd,
                          &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar3;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0xe,
                        &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,0);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xf,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  if (-1 < iVar3) {
    return iVar3;
  }
LAB_14002b3d6:
  UnregisterClassExtension();
  McGenEventUnregister_EtwUnregister();
  UninitializeTelemetryAssertsKM();
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
  return iVar3;
}



===== RegisterClassExtension @ 14002b464 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static long __cdecl UcmUcsiCx::Driver::RegisterClassExtension(struct _DRIVER_OBJECT *
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
UcmUcsiCx::Driver::RegisterClassExtension(_DRIVER_OBJECT *param_1,_UNICODE_STRING *param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined1 auStackY_178 [32];
  longlong local_138;
  _UNICODE_STRING local_130;
  wchar_t local_118 [104];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_130.Buffer = local_118;
  local_130.Length = 0;
  local_130.MaximumLength = 200;
  local_130._4_4_ = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x20,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  local_138 = (**(code **)(WdfFunctions_01023 + 200))
                        (WdfDriverGlobals,*WdfDriverGlobals,&SDDL_DEVOBJ_KERNEL_ONLY);
  if (local_138 == 0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b6d3;
    uVar3 = 0x21;
  }
  else {
    uVar2 = 0;
    iVar1 = -0x3fffffcb;
    do {
      if (iVar1 != -0x3fffffcb) break;
      iVar1 = RtlUnicodeStringPrintf(&local_130,(ushort *)L"\\Device\\UcmUcsiCx%u",(ulonglong)uVar2)
      ;
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b6d3;
        uVar3 = 0x22;
        goto LAB_14002b533;
      }
      iVar1 = (**(code **)(WdfFunctions_01023 + 0x218))(WdfDriverGlobals,local_138,&local_130);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b6d3;
        uVar3 = 0x23;
        goto LAB_14002b533;
      }
      iVar1 = (**(code **)(WdfFunctions_01023 + 600))
                        (WdfDriverGlobals,&local_138,0,&s_ClassLibraryDevice);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 100);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002b6d3;
      uVar3 = 0x24;
    }
    else {
      (**(code **)(WdfFunctions_01023 + 0xd8))(WdfDriverGlobals,s_ClassLibraryDevice);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      iVar1 = WdfRegisterClassLibrary(&s_WdfClassLibraryInfo,param_2,&local_130);
      if ((-1 < iVar1) || ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
      goto LAB_14002b6d3;
      uVar3 = 0x26;
    }
  }
LAB_14002b533:
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar3,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids,(char)param_1,(char)iVar1);
LAB_14002b6d3:
  if (local_138 != 0) {
    (**(code **)(WdfFunctions_01023 + 0x1b0))(WdfDriverGlobals);
    local_138 = 0;
  }
  if ((iVar1 < 0) && (s_ClassLibraryDevice != (WDFDEVICE__ *)0x0)) {
    (**(code **)(WdfFunctions_01023 + 0x680))(WdfDriverGlobals);
    s_ClassLibraryDevice = (WDFDEVICE__ *)0x0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x27,
                     &WPP_d36d40f2067b38fda705840b8c56fc7e_Traceguids);
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14002b790 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14002b817;
    }
LAB_14002b851:
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
LAB_14002b817:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14002b851;
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
    goto LAB_14002b851;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14001c207 < ppuVar3) goto LAB_14002b851;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14002b817;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002b8a4 =====

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
            if (&UNK_14001c207 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14002b98e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14002b98e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14002b98e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14001c207 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


