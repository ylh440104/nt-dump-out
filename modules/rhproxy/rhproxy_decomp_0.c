
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



===== _RhpLogBugcheck @ 1c0001020 =====

void _RhpLogBugcheck(void)

{
  undefined8 unaff_retaddr;
  
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xd2,unaff_retaddr,1,0,0);
}



===== _RhpLogDebug @ 1c0001050 =====

undefined8 _RhpLogDebug(uint param_1)

{
  code *pcVar1;
  char cVar2;
  undefined8 uVar3;
  uint local_res8 [2];
  char *local_res10;
  
  local_res10 = "noncritical error";
  local_res8[0] = param_1;
  DbgPrintEx(0x65,0,"\n*** RHPROXY %s detected @%p.\n","noncritical error");
  if (DAT_1c0010284 == '\0') {
    KdRefreshDebuggerNotPresent();
    DAT_1c0010284 = '\x01';
  }
  if ((*KdDebuggerEnabled_exref != (code)0x0) && (*KdDebuggerNotPresent_exref == (code)0x0)) {
    do {
      local_res8[0] = local_res8[0] & 0xffff0000;
      DbgPrompt("Break to debug, Ignore, ignore All (bi)? ",local_res8,2);
      cVar2 = (char)local_res8[0];
      if ((cVar2 == 'B') || (cVar2 == 'b')) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
    } while ((cVar2 + 0xb7U & 0xdf) != 0);
  }
  return 1;
}



===== WPP_RECORDER_SF_sDs @ 1c000110c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDs(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,char *param_8)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  ulonglong uVar7;
  
  pcVar5 = param_8;
  uVar7 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar7 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar7 * 0x50 + 0x29])) {
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
    pcVar6 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar6 = "NULL";
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar7 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar2
               ,lVar3,&param_7,4,pcVar6,lVar4,0);
  }
  if (pcVar5 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (pcVar5[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = "NULL";
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,pcVar5,lVar4,0);
  return;
}



===== GetFromWdfObject @ 1c0001314 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class RHP_DRIVER * __ptr64 __cdecl RHP_DRIVER::GetFromWdfObject(void *
   __ptr64,bool) */

RHP_DRIVER * __cdecl RHP_DRIVER::GetFromWdfObject(void *param_1,bool param_2)

{
  int iVar1;
  RHP_DRIVER *pRVar2;
  
  pRVar2 = (RHP_DRIVER *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RHP_DRIVER_TYPE_INFO_1c0010028);
  if (param_2) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(int *)pRVar2 == 0x52504852) {
        return pRVar2;
      }
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,10,
                          &WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0x26,
                          "thisPtr->signature == _SIGNATURE::CONSTRUCTED");
    }
    if (*(int *)pRVar2 != 0x52504852) {
                    /* WARNING: Subroutine does not return */
      _RhpLogBugcheck();
    }
  }
  else {
    if (((((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (iVar1 = *(int *)pRVar2, iVar1 != 0x72706872)) && (iVar1 != 0x52504852)) && (iVar1 != 0)) {
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0xb,
                          &WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0x2c,
                          "(thisPtr->signature == _SIGNATURE::UNINITIALIZED) || (thisPtr->signature == _SIGNATURE::CONSTRUCTED) || (thisPtr->signature == _SIGNATURE::DESTRUCTED)"
                         );
    }
    iVar1 = *(int *)pRVar2;
    if (((iVar1 != 0x72706872) && (iVar1 != 0x52504852)) && (iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
      _RhpLogBugcheck();
    }
  }
  return pRVar2;
}



===== evtCleanupCallback @ 1c0001460 =====

/* private: static void __cdecl RHP_DRIVER::evtCleanupCallback(void * __ptr64) */

void __thiscall RHP_DRIVER::evtCleanupCallback(RHP_DRIVER *this)

{
  return;
}



===== evtDestroyCallback @ 1c0001470 =====

/* private: static void __cdecl RHP_DRIVER::evtDestroyCallback(void * __ptr64) */

void __cdecl RHP_DRIVER::evtDestroyCallback(void *param_1)

{
  RHP_DRIVER *this;
  
  this = GetFromWdfObject(param_1,false);
  ~RHP_DRIVER(this);
  return;
}



===== WPP_RECORDER_SF_sDqq @ 1c0001490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqq
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,8,&param_9,8,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,
                  &param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqqL @ 1c0001674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqL
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,8,&param_9,8,&param_10,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,
                  &param_9,8,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqqq @ 1c0001880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0xb3;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,0xe,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0x2f,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,0xe,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0x2f,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WppClassicProviderCallback @ 1c00019d0 =====

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



===== _CONTROLLER_REGISTRY @ 1c0001a2c =====

/* public: __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::_CONTROLLER_REGISTRY(void) __ptr64 */

_CONTROLLER_REGISTRY * __thiscall
RHP_DEVICE::_CONTROLLER_REGISTRY::_CONTROLLER_REGISTRY(_CONTROLLER_REGISTRY *this)

{
  RtlInitializeGenericTableAvl
            (this,rtlAvlCompareRoutine,RHP_SPI_CONTROLLER::rtlAvlResourceAllocateRoutine,
             RHP_SPI_CONTROLLER::rtlAvlResourceFreeRoutine,this);
  return this;
}



===== ~_CONTROLLER_REGISTRY @ 1c0001a6c =====

/* public: __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::~_CONTROLLER_REGISTRY(void) __ptr64 */

void __thiscall RHP_DEVICE::_CONTROLLER_REGISTRY::~_CONTROLLER_REGISTRY(_CONTROLLER_REGISTRY *this)

{
  int iVar1;
  
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    iVar1 = RtlNumberGenericTableElementsAvl();
    if (iVar1 != 0) {
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0xc,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x8e,
                          "!RtlNumberGenericTableElementsAvl(&this->rtlAvlTable)");
    }
  }
  iVar1 = RtlNumberGenericTableElementsAvl(this);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  return;
}



===== Add @ 1c0001b04 =====

/* public: long __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::Add(struct _UNICODE_STRING const &
   __ptr64,class RHP_CONTROLLER * __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::_CONTROLLER_REGISTRY::Add
          (_CONTROLLER_REGISTRY *this,_UNICODE_STRING *param_1,RHP_CONTROLLER *param_2,
          void **param_3)

{
  wchar_t *_Dst;
  longlong lVar1;
  void *pvVar2;
  uint uVar3;
  _CONTROLLER_REGISTRY *p_Var4;
  long lVar5;
  short sVar6;
  undefined8 uVar7;
  undefined *in_stack_ffffffffffffff88;
  char *in_stack_ffffffffffffff90;
  undefined8 local_48;
  wchar_t *pwStack_40;
  RHP_CONTROLLER *local_38;
  
  local_48 = 0;
  pwStack_40 = (wchar_t *)0x0;
  local_38 = (RHP_CONTROLLER *)0x0;
  uVar3 = 0xc000d678;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)param_1 != 0) goto LAB_1c0001ba3;
    in_stack_ffffffffffffff90 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp";
    in_stack_ffffffffffffff88 = &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids;
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDs(uVar7,2,3,0x12,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x4b,
                        "ReferenceString.Length");
    uVar3 = (uint)uVar7;
  }
  if (*(short *)param_1 == 0) {
    _RhpLogDebug(uVar3);
  }
LAB_1c0001ba3:
  sVar6 = *(short *)param_1 + 2;
  uVar7 = 0x32504852;
  _Dst = (wchar_t *)ExAllocatePoolWithTag(0x200,sVar6);
  if (_Dst == (wchar_t *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x13,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x56,(char)&local_48,
                 (char)sVar6);
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0xd,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xa0,(char)this,
                 (char)*(undefined2 *)param_1);
    }
    lVar5 = -0x3fffffff;
  }
  else {
    memcpy(_Dst,*(void **)(param_1 + 8),(ulonglong)*(ushort *)param_1);
    _Dst[*(ushort *)param_1 >> 1] = L'\0';
    local_48._0_4_ = CONCAT22(sVar6,*(undefined2 *)param_1);
    LOCK();
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    UNLOCK();
    p_Var4 = this;
    pwStack_40 = _Dst;
    local_38 = param_2;
    lVar1 = RtlLookupElementGenericTableAvl(this,&local_48);
    uVar3 = (uint)p_Var4;
    if (lVar1 == 0) {
      pvVar2 = (void *)RtlInsertElementGenericTableAvl(this,&local_48,0x18);
      if (pvVar2 != (void *)0x0) {
        *(undefined4 *)(this + 0x28) = 0;
        *(undefined8 *)(this + 0x20) = 0;
        if (param_3 != (void **)0x0) {
          *param_3 = pvVar2;
        }
        return 0;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xf,
                   &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xbf,(char)this,
                   (char)&local_48);
      }
      lVar5 = -0x3fffffe9;
    }
    else {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDqS
                  (uVar7,2,3,0xe,in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,0xb0,
                   (char)lVar1,pwStack_40);
        uVar3 = (uint)uVar7;
      }
      _RhpLogDebug(uVar3);
      lVar5 = -0x3ffffdd6;
    }
    _RECORD::cleanup((_RECORD *)&local_48);
  }
  return lVar5;
}



===== EnableControllerWdmIrpPreprocess @ 1c0001dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl RHP_DEVICE::EnableControllerWdmIrpPreprocess(struct WDFFILEOBJECT__ *
   __ptr64,void * __ptr64) */

void __cdecl RHP_DEVICE::EnableControllerWdmIrpPreprocess(WDFFILEOBJECT__ *param_1,void *param_2)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,param_1);
  *(void **)(*(longlong *)(lVar1 + 0x18) + 0x18) = param_2;
  return;
}



===== FindController @ 1c0001e10 =====

/* public: class RHP_CONTROLLER * __ptr64 __cdecl RHP_DEVICE::FindController(struct _UNICODE_STRING
   const & __ptr64,struct _UNICODE_STRING const * __ptr64 * __ptr64) __ptr64 */

RHP_CONTROLLER * __thiscall
RHP_DEVICE::FindController(RHP_DEVICE *this,_UNICODE_STRING *param_1,_UNICODE_STRING **param_2)

{
  undefined1 auVar1 [16];
  undefined2 uVar2;
  _UNICODE_STRING *p_Var3;
  uint uVar4;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  ushort local_48;
  undefined2 local_46;
  undefined4 local_44;
  short *local_40;
  undefined8 local_38;
  
  auVar1 = *(undefined1 (*) [16])param_1;
  local_58 = auVar1._0_4_;
  uStack_54 = auVar1._4_4_;
  local_48 = auVar1._0_2_;
  local_40 = auVar1._8_8_;
  if ((1 < local_48) && (*local_40 == 0x5c)) {
    local_48 = local_48 - 2;
    local_40 = local_40 + 1;
    local_58 = CONCAT22(local_48,local_48);
  }
  uStack_50._0_4_ = (int)local_40;
  uStack_50._4_4_ = (int)((ulonglong)local_40 >> 0x20);
  uVar2 = (undefined2)((uint)local_58 >> 0x10);
  local_38 = 0;
  local_46 = uVar2;
  local_44 = uStack_54;
  p_Var3 = (_UNICODE_STRING *)RtlLookupElementGenericTableAvl(this + 0x20,&local_48);
  if (p_Var3 != (_UNICODE_STRING *)0x0) {
    if (param_2 != (_UNICODE_STRING **)0x0) {
      *param_2 = p_Var3;
    }
    if (*(RHP_CONTROLLER **)(p_Var3 + 0x10) != (RHP_CONTROLLER *)0x0) {
      return *(RHP_CONTROLLER **)(p_Var3 + 0x10);
    }
  }
  do {
    if ((ushort)local_58 == 0) {
      return (RHP_CONTROLLER *)0x0;
    }
    uVar4 = (uint)((ushort)local_58 >> 1);
    do {
      uVar4 = uVar4 - 1;
      if ((int)uVar4 < 0) break;
    } while (*(short *)(uStack_50 + (longlong)(int)uVar4 * 2) != 0x5c);
    if ((int)uVar4 < 1) {
      local_58._0_2_ = 0;
    }
    else {
      local_58._0_2_ = (short)uVar4 * 2;
    }
    local_40 = (short *)uStack_50;
    local_38 = 0;
    local_48 = (ushort)local_58;
    local_46 = uVar2;
    local_44 = uStack_54;
    p_Var3 = (_UNICODE_STRING *)RtlLookupElementGenericTableAvl(this + 0x20,&local_48);
    if (p_Var3 != (_UNICODE_STRING *)0x0) {
      if (param_2 != (_UNICODE_STRING **)0x0) {
        *param_2 = p_Var3;
      }
      if (*(RHP_CONTROLLER **)(p_Var3 + 0x10) != (RHP_CONTROLLER *)0x0) {
        return *(RHP_CONTROLLER **)(p_Var3 + 0x10);
      }
    }
  } while( true );
}



===== GetAt @ 1c0001f78 =====

/* public: class RHP_CONTROLLER * __ptr64 __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::GetAt(unsigned
   long,struct _UNICODE_STRING const * __ptr64 * __ptr64) __ptr64 */

RHP_CONTROLLER * __thiscall
RHP_DEVICE::_CONTROLLER_REGISTRY::GetAt
          (_CONTROLLER_REGISTRY *this,ulong param_1,_UNICODE_STRING **param_2)

{
  longlong lVar1;
  RHP_CONTROLLER *pRVar2;
  
  lVar1 = RtlGetElementGenericTableAvl();
  pRVar2 = (RHP_CONTROLLER *)0x0;
  if (lVar1 != 0) {
    pRVar2 = *(RHP_CONTROLLER **)(lVar1 + 0x10);
  }
  return pRVar2;
}



===== GetFromWdfObject @ 1c0001fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static class RHP_DEVICE * __ptr64 __cdecl RHP_DEVICE::GetFromWdfObject(void *
   __ptr64,bool) */

RHP_DEVICE * __cdecl RHP_DEVICE::GetFromWdfObject(void *param_1,bool param_2)

{
  int iVar1;
  RHP_DEVICE *pRVar2;
  
  pRVar2 = (RHP_DEVICE *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_RHP_DEVICE_TYPE_INFO_1c0010078);
  if (param_2) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (*(int *)pRVar2 == 0x45504852) {
        return pRVar2;
      }
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,10,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2e,
                          "thisPtr->signature == _SIGNATURE::CONSTRUCTED");
    }
    if (*(int *)pRVar2 != 0x45504852) {
                    /* WARNING: Subroutine does not return */
      _RhpLogBugcheck();
    }
  }
  else {
    if (((((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (iVar1 = *(int *)pRVar2, iVar1 != 0x65706872)) && (iVar1 != 0x45504852)) && (iVar1 != 0)) {
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0xb,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x34,
                          "(thisPtr->signature == _SIGNATURE::UNINITIALIZED) || (thisPtr->signature == _SIGNATURE::CONSTRUCTED) || (thisPtr->signature == _SIGNATURE::DESTRUCTED)"
                         );
    }
    iVar1 = *(int *)pRVar2;
    if (((iVar1 != 0x65706872) && (iVar1 != 0x45504852)) && (iVar1 != 0)) {
                    /* WARNING: Subroutine does not return */
      _RhpLogBugcheck();
    }
  }
  return pRVar2;
}



===== GetReferenceStringFromWdfFileObject @ 1c00020e8 =====

/* public: struct _UNICODE_STRING const * __ptr64 __cdecl
   RHP_DEVICE::GetReferenceStringFromWdfFileObject(struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

_UNICODE_STRING * __thiscall
RHP_DEVICE::GetReferenceStringFromWdfFileObject(RHP_DEVICE *this,WDFFILEOBJECT__ *param_1)

{
  _FILE_OBJECT_CONTEXT *p_Var1;
  
  p_Var1 = getFileObjectContextFromWdfObject(this,param_1);
  return *(_UNICODE_STRING **)(p_Var1 + 0x10);
}



===== Remove @ 1c0002104 =====

/* public: void __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::Remove(struct _UNICODE_STRING const &
   __ptr64) __ptr64 */

void __thiscall
RHP_DEVICE::_CONTROLLER_REGISTRY::Remove(_CONTROLLER_REGISTRY *this,_UNICODE_STRING *param_1)

{
  void *pvVar1;
  uint uVar2;
  _CONTROLLER_REGISTRY *p_Var3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  
  local_28 = *(undefined4 *)param_1;
  uStack_24 = *(undefined4 *)(param_1 + 4);
  uStack_20 = *(undefined4 *)(param_1 + 8);
  uStack_1c = *(undefined4 *)(param_1 + 0xc);
  local_18 = 0;
  p_Var3 = this;
  pvVar1 = (void *)RtlLookupElementGenericTableAvl(local_28,&local_28);
  uVar2 = (uint)p_Var3;
  if (pvVar1 == (void *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqZ
                (uVar4,2,3,0x10,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0xdf,(char)this,
                 (wchar_t *)param_1);
      uVar2 = (uint)uVar4;
    }
    _RhpLogDebug(uVar2);
  }
  else {
    Remove(this,pvVar1);
  }
  return;
}



===== Remove @ 1c00021a0 =====

/* public: void __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::Remove(void * __ptr64) __ptr64 */

void __thiscall RHP_DEVICE::_CONTROLLER_REGISTRY::Remove(_CONTROLLER_REGISTRY *this,void *param_1)

{
  char cVar1;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  _RECORD::cleanup(param_1);
  cVar1 = RtlDeleteElementGenericTableAvl(this,param_1);
  if (cVar1 != '\0') {
    *(undefined4 *)(this + 0x28) = 0;
    *(undefined8 *)(this + 0x20) = 0;
    return;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqZ
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x11,in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0xfd,(char)this,param_1);
  }
                    /* WARNING: Subroutine does not return */
  _RhpLogBugcheck();
}



===== RtlUnicodeStringPrintf @ 1c0002230 =====

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



===== cleanup @ 1c00022d0 =====

/* public: void __cdecl RHP_DEVICE::_CONTROLLER_REGISTRY::_RECORD::cleanup(void) __ptr64 */

void __thiscall RHP_DEVICE::_CONTROLLER_REGISTRY::_RECORD::cleanup(_RECORD *this)

{
  *(undefined4 *)this = 0;
  ExFreePoolWithTag(*(undefined8 *)(this + 8),0x32504852);
  *(undefined8 *)(this + 8) = 0;
  RHP_CONTROLLER::ReleaseReference(*(RHP_CONTROLLER **)(this + 0x10));
  *(undefined8 *)(this + 0x10) = 0;
  return;
}



===== evtCleanupCallback @ 1c0002320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtCleanupCallback(void * __ptr64) */

void __cdecl RHP_DEVICE::evtCleanupCallback(void *param_1)

{
  RHP_DEVICE *pRVar1;
  _UNICODE_STRING *p_Var2;
  
  pRVar1 = GetFromWdfObject(param_1,false);
  while( true ) {
    p_Var2 = (_UNICODE_STRING *)
             RtlLookupElementGenericTableAvl((_CONTROLLER_REGISTRY *)(pRVar1 + 0x20),0);
    if (p_Var2 == (_UNICODE_STRING *)0x0) break;
    _CONTROLLER_REGISTRY::Remove((_CONTROLLER_REGISTRY *)(pRVar1 + 0x20),p_Var2);
  }
  if (*(longlong *)(pRVar1 + 0x18) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return;
}



===== evtDestroyCallback @ 1c0002390 =====

/* private: static void __cdecl RHP_DEVICE::evtDestroyCallback(void * __ptr64) */

void __cdecl RHP_DEVICE::evtDestroyCallback(void *param_1)

{
  RHP_DEVICE *this;
  
  this = GetFromWdfObject(param_1,false);
  ~RHP_DEVICE(this);
  return;
}



===== evtDeviceWdmIrpPreprocess @ 1c00023b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl RHP_DEVICE::evtDeviceWdmIrpPreprocess(struct WDFDEVICE__ *
   __ptr64,struct _IRP * __ptr64) */

long __cdecl RHP_DEVICE::evtDeviceWdmIrpPreprocess(WDFDEVICE__ *param_1,_IRP *param_2)

{
  longlong *plVar1;
  long lVar2;
  
  plVar1 = *(longlong **)
            (*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18) + 8);
  lVar2 = (**(code **)(*plVar1 + 0x28))(plVar1,param_1,param_2);
  return lVar2;
}



===== evtIoDeviceControl @ 1c00023f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtIoDeviceControl(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
RHP_DEVICE::evtIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  void *pvVar1;
  RHP_DEVICE *this;
  WDFFILEOBJECT__ *pWVar2;
  _FILE_OBJECT_CONTEXT *p_Var3;
  
  pvVar1 = (void *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = GetFromWdfObject(pvVar1,true);
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (pWVar2 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x16,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",6,(char)this,(char)param_2,
                 (char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000e5);
  }
  else {
    p_Var3 = getFileObjectContextFromWdfObject(this,pWVar2);
    (**(code **)(**(longlong **)(p_Var3 + 8) + 8))
              (*(longlong **)(p_Var3 + 8),param_1,param_2,param_3,param_4,param_5);
  }
  return;
}



===== evtIoInCallerContext @ 1c0002550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtIoInCallerContext(struct WDFDEVICE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64) */

void __cdecl RHP_DEVICE::evtIoInCallerContext(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  RHP_DEVICE *this;
  WDFFILEOBJECT__ *pWVar1;
  _FILE_OBJECT_CONTEXT *p_Var2;
  
  this = GetFromWdfObject(param_1,true);
  pWVar1 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (pWVar1 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xe2,(char)this,(char)param_2
                );
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000e5);
  }
  else {
    p_Var2 = getFileObjectContextFromWdfObject(this,pWVar1);
    (**(code **)**(undefined8 **)(p_Var2 + 8))(*(undefined8 **)(p_Var2 + 8),param_1,param_2);
  }
  return;
}



===== evtIoInternalDeviceControl @ 1c0002650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtIoInternalDeviceControl(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) */

void __cdecl
RHP_DEVICE::evtIoInternalDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  void *pvVar1;
  RHP_DEVICE *this;
  WDFFILEOBJECT__ *pWVar2;
  _FILE_OBJECT_CONTEXT *p_Var3;
  
  pvVar1 = (void *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = GetFromWdfObject(pvVar1,true);
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqqqLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (pWVar2 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x18,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x36,(char)this,(char)param_2
                 ,(char)param_5);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000e5);
  }
  else {
    p_Var3 = getFileObjectContextFromWdfObject(this,pWVar2);
    (**(code **)(**(longlong **)(p_Var3 + 8) + 0x10))
              (*(longlong **)(p_Var3 + 8),param_1,param_2,param_3,param_4,param_5);
  }
  return;
}



===== getFileObjectContextFromWdfObject @ 1c00027d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: class RHP_DEVICE::_FILE_OBJECT_CONTEXT * __ptr64 __cdecl
   RHP_DEVICE::getFileObjectContextFromWdfObject(struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

_FILE_OBJECT_CONTEXT * __thiscall
RHP_DEVICE::getFileObjectContextFromWdfObject(RHP_DEVICE *this,WDFFILEOBJECT__ *param_1)

{
  _FILE_OBJECT_CONTEXT *p_Var1;
  longlong lVar2;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,(char)param_1);
  p_Var1 = *(_FILE_OBJECT_CONTEXT **)(lVar2 + 0x18);
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(RHP_DEVICE **)p_Var1 == this) {
      return p_Var1;
    }
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x19,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x50,
                        "fileObjectContextPtr->devicePtr == this");
  }
  if (*(RHP_DEVICE **)p_Var1 != this) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  return p_Var1;
}



===== rtlAvlResourceAllocateRoutine @ 1c0002880 =====

/* private: static void * __ptr64 __cdecl RHP_SPI_CONTROLLER::rtlAvlResourceAllocateRoutine(struct
   _RTL_AVL_TABLE * __ptr64,unsigned long) */

void * __cdecl
RHP_SPI_CONTROLLER::rtlAvlResourceAllocateRoutine(_RTL_AVL_TABLE *param_1,ulong param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePoolWithTag(0x200,param_2,0x32504852);
  return pvVar1;
}



===== rtlAvlCompareRoutine @ 1c00028b0 =====

/* private: static enum _RTL_GENERIC_COMPARE_RESULTS __cdecl
   RHP_DEVICE::_CONTROLLER_REGISTRY::rtlAvlCompareRoutine(struct _RTL_AVL_TABLE * __ptr64,void *
   __ptr64,void * __ptr64) */

_RTL_GENERIC_COMPARE_RESULTS __cdecl
RHP_DEVICE::_CONTROLLER_REGISTRY::rtlAvlCompareRoutine
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  int iVar1;
  
  if ((param_2 != (void *)0x0) && (param_3 != (void *)0x0)) {
    iVar1 = (uint)(*(ushort *)param_2 >> 1) - (uint)(*(ushort *)param_3 >> 1);
    if (iVar1 == 0) {
      iVar1 = _wcsnicmp(*(wchar_t **)((longlong)param_2 + 8),*(wchar_t **)((longlong)param_3 + 8),
                        (ulonglong)(uint)(*(ushort *)param_3 >> 1));
    }
    if (iVar1 < 0) {
      return 0;
    }
    if (0 < iVar1) {
      return 1;
    }
  }
  return 2;
}



===== rtlAvlResourceFreeRoutine @ 1c0002910 =====

/* private: static void __cdecl RHP_SPI_CONTROLLER::rtlAvlResourceFreeRoutine(struct _RTL_AVL_TABLE
   * __ptr64,void * __ptr64) */

void __cdecl RHP_SPI_CONTROLLER::rtlAvlResourceFreeRoutine(_RTL_AVL_TABLE *param_1,void *param_2)

{
  ExFreePoolWithTag(param_2,0x32504852);
  return;
}



===== WPP_RECORDER_SF_sD @ 1c0002934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_sDd @ 1c0002ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sDLDD @ 1c0002c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,4,
               &param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,4,
                  &param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sDLL @ 1c0002db8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               ,4,&param_8,4,&param_9,4,0);
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
  WppAutoLogTrace(param_1,2,3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDPd @ 1c0002f4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDPd(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 0x10;
  local_10[0] = 0x4ac;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x2e,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_10,4,
               &uStack0000000000000040,8,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x2e,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_10,4,
                  &uStack0000000000000040,8,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_sDS @ 1c0003084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDS(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,wchar_t *param_8)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  ulonglong uVar8;
  
  pwVar7 = param_8;
  uVar8 = (ulonglong)(param_3 >> 0x10);
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar8 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar8 * 0x50 + 0x29])) {
    if (param_8 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_8[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar6 = param_8;
    if (param_8 == (wchar_t *)0x0) {
      pwVar6 = L"NULL";
    }
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
    pcVar5 = param_6;
    if (param_6 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar8 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar5
               ,lVar3,&param_7,4,pwVar6,lVar1,0);
  }
  if (pwVar7 != (wchar_t *)0x0) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (pwVar7[lVar4] != L'\0');
    lVar4 = lVar4 * 2 + 2;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    pwVar7 = L"NULL";
  }
  lVar1 = -1;
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_6[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,pwVar7,lVar4,0);
  return;
}



===== WPP_RECORDER_SF_sDdi @ 1c00032a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdi
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,4,&param_9,8,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,
                  &param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sDdq @ 1c0003488 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdq
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,4,&param_9,8,0);
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
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,&param_9,8,0
                 );
  return;
}



===== WPP_RECORDER_SF_sDi @ 1c0003660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDi(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,8,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_sDii @ 1c000381c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDii
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined8 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
               &param_9,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
                  &param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqD @ 1c0003998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqD
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,pcVar3,lVar2,&param_7
               ,4,&param_8,8,&param_9,4,0);
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
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,&param_9,4,0
                 );
  return;
}



===== WPP_RECORDER_SF_sDqLL @ 1c0003b34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLL
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               char *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9,
               undefined1 param_10)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,param_5,param_4,pcVar3
               ,lVar2,&param_7,4,&param_8,8,&param_9,4,&param_10,4,0);
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
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,
                  &param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqS @ 1c0003d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqS
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined8 param_6,undefined1 param_7,undefined1 param_8,wchar_t *param_9)

{
  longlong lVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  pwVar3 = param_9;
  lVar6 = -1;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_9 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_9[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_9;
    if (param_9 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
               pwVar2,lVar1,0);
  }
  if (pwVar3 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (pwVar3[lVar6] != L'\0');
    lVar4 = lVar6 * 2 + 2;
  }
  if (pwVar3 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
                  pwVar3,lVar4,0);
  return;
}



===== WPP_RECORDER_SF_sDqZ @ 1c0003f2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqZ
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined8 param_6,undefined1 param_7,undefined1 param_8,wchar_t *param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  
  pwVar4 = param_9;
  pwVar5 = L"NULL";
  uVar6 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar6 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) == 0) || ((byte)WPP_GLOBAL_Control[uVar6 * 0x50 + 0x29] < param_2)
     ) goto LAB_1c0004080;
  if (param_9 == (wchar_t *)0x0) {
    wVar1 = L'\b';
LAB_1c0003fe9:
    pwVar3 = L"NULL";
  }
  else {
    wVar1 = *param_9;
    if (*param_9 == L'\0') goto LAB_1c0003fe9;
    pwVar3 = *(wchar_t **)(param_9 + 4);
  }
  pwVar2 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + uVar6 * 0x50 + 0x18),0x2b,
             &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,pwVar2
             ,2,pwVar3,wVar1,0);
LAB_1c0004080:
  if (pwVar4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *pwVar4;
    if (*pwVar4 != L'\0') {
      pwVar5 = *(wchar_t **)(pwVar4 + 4);
    }
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
                  pwVar4,2,pwVar5,wVar1,0);
  return;
}



===== WPP_RECORDER_SF_sDqdLq @ 1c000413c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqdLq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
               &param_9,4,&param_10,4,&param_11,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
                  &param_9,4,&param_10,4,&param_11,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqdq @ 1c00042ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqdq
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
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
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,pcVar3,lVar2,&param_7
               ,4,&param_8,8,&param_9,4,&param_10,8,0);
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
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,8,&param_9,4,
                  &param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqdqZ @ 1c0004474 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqdqZ
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,wchar_t *param_11)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  
  pwVar4 = param_11;
  pwVar5 = L"NULL";
  uVar6 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar6 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) == 0) || ((byte)WPP_GLOBAL_Control[uVar6 * 0x50 + 0x29] < 2))
  goto LAB_1c00045f2;
  if (param_11 == (wchar_t *)0x0) {
    wVar2 = L'\b';
LAB_1c0004532:
    pwVar3 = L"NULL";
  }
  else {
    wVar2 = *param_11;
    if (*param_11 == L'\0') goto LAB_1c0004532;
    pwVar3 = *(wchar_t **)(param_11 + 4);
  }
  pwVar1 = param_11;
  if (param_11 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  (*pfnWppTraceMessage)
            (*(undefined8 *)(WPP_GLOBAL_Control + uVar6 * 0x50 + 0x18),0x2b,
             &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
             &param_9,4,&param_10,8,pwVar1,2,pwVar3,wVar2,0);
LAB_1c00045f2:
  if (pwVar4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *pwVar4;
    if (*pwVar4 != L'\0') {
      pwVar5 = *(wchar_t **)(pwVar4 + 4);
    }
  }
  if (pwVar4 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  WppAutoLogTrace(param_1,2,param_3,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,&param_7,4,&param_8,8,
                  &param_9,4,&param_10,8,pwVar4,2,pwVar5,wVar2,0);
  return;
}



===== WPP_RECORDER_SF_sDqqqLLL @ 1c00046dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqqLLL(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined4 local_28 [4];
  
  local_28[0] = 0x22c;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x17,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_28,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,
               &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x17,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_28,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,
                  &uStack0000000000000058,4,&uStack0000000000000060,4,&uStack0000000000000068,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqqqq @ 1c0004894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqqq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0x27c;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x1a,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,
               &uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,0x1a,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x2f,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,8,
                  &uStack0000000000000058,8,0);
  return;
}



===== `scalar_deleting_destructor' @ 1c0004a10 =====

/* protected: virtual void * __ptr64 __cdecl RHP_CONTROLLER::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall RHP_CONTROLLER::_scalar_deleting_destructor_(RHP_CONTROLLER *this,uint param_1)

{
  ~RHP_CONTROLLER(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x33504852);
  }
  return this;
}



===== EvtDeviceWdmIrpPreprocess @ 1c0004a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl RHP_CONTROLLER::EvtDeviceWdmIrpPreprocess(struct WDFDEVICE__ *
   __ptr64,struct _IRP * __ptr64) __ptr64 */

long __thiscall
RHP_CONTROLLER::EvtDeviceWdmIrpPreprocess(RHP_CONTROLLER *this,WDFDEVICE__ *param_1,_IRP *param_2)

{
  long lVar1;
  
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals);
  return lVar1;
}



===== EvtIoWrite @ 1c0004aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_CONTROLLER::EvtIoWrite(struct WDFQUEUE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,unsigned __int64) __ptr64 */

void __thiscall
RHP_CONTROLLER::EvtIoWrite
          (RHP_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3)

{
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000bb);
  return;
}



===== EvtIoInCallerContext @ 1c0004ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_CONTROLLER::EvtIoInCallerContext(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
RHP_CONTROLLER::EvtIoInCallerContext
          (RHP_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                          &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x55,(char)iVar1
                         );
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  return;
}



===== ReleaseReference @ 1c0004b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl RHP_CONTROLLER::ReleaseReference(void) __ptr64 */

void __thiscall RHP_CONTROLLER::ReleaseReference(RHP_CONTROLLER *this)

{
  RHP_CONTROLLER *pRVar1;
  int iVar2;
  
  LOCK();
  pRVar1 = this + 0x10;
  iVar2 = *(int *)pRVar1;
  *(int *)pRVar1 = *(int *)pRVar1 + -1;
  UNLOCK();
  if ((iVar2 == 1) && (this != (RHP_CONTROLLER *)0x0)) {
    (**(code **)(*(longlong *)this + 0x48))(this,1);
  }
  return;
}



===== VerifyFileCreateRequestParameters @ 1c0004bc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_CONTROLLER::VerifyFileCreateRequestParameters(struct WDFREQUEST__
   * __ptr64) */

long __cdecl RHP_CONTROLLER::VerifyFileCreateRequestParameters(WDFREQUEST__ *param_1)

{
  long lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (*(int *)(lStack_30 + 0x10) == 0x12019f) {
    if (uStack_20._2_2_ == 3) {
      lVar1 = 0;
    }
    else {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                            &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x35,
                            (char)((ulonglong)uStack_20 >> 0x10));
      }
      lVar1 = -0x3fffffbd;
    }
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
                          &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x2c,
                          (char)*(int *)(lStack_30 + 0x10));
    }
    lVar1 = -0x3fffffde;
  }
  return lVar1;
}



===== forwardIrpToRemoteTarget @ 1c0004d00 =====

/* protected: static long __cdecl RHP_CONTROLLER::forwardIrpToRemoteTarget(struct _IRP *
   __ptr64,struct _DEVICE_OBJECT * __ptr64,struct _FILE_OBJECT * __ptr64,bool) */

long __cdecl
RHP_CONTROLLER::forwardIrpToRemoteTarget
          (_IRP *param_1,_DEVICE_OBJECT *param_2,_FILE_OBJECT *param_3,bool param_4)

{
  longlong lVar1;
  long lVar2;
  int iVar3;
  _DEVICE_OBJECT *p_Var4;
  undefined8 uVar5;
  undefined7 in_register_00000089;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  if ((char)param_1[0x43] < (char)param_2[0x4c]) {
    uVar5 = 0;
    p_Var4 = param_2;
    iVar3 = IoAdjustStackSizeForRedirection
                      (*(undefined8 *)(lVar1 + 0x28),param_2,0,
                       CONCAT71(in_register_00000089,param_4));
    if (iVar3 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdqq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var4,uVar5,0xe,
                   &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",3,(char)iVar3,
                   (char)*(undefined8 *)(lVar1 + 0x28),(char)param_2);
      }
      lVar2 = -0x3fffffff;
    }
    else {
      lVar2 = -0x3ffffdd3;
    }
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(long *)(param_1 + 0x30) = lVar2;
    IofCompleteRequest(param_1,0);
  }
  else {
    *(_FILE_OBJECT **)(lVar1 + 0x30) = param_3;
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
    lVar2 = IofCallDriver(param_2,param_1);
  }
  return lVar2;
}



===== spbWdmIrpPreprocess @ 1c0004df8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static long __cdecl RHP_CONTROLLER::spbWdmIrpPreprocess(struct WDFDEVICE__ *
   __ptr64,struct _IRP * __ptr64) */

long __cdecl RHP_CONTROLLER::spbWdmIrpPreprocess(WDFDEVICE__ *param_1,_IRP *param_2)

{
  char cVar1;
  char *pcVar2;
  _FILE_OBJECT *p_Var3;
  long lVar4;
  _DEVICE_OBJECT *p_Var5;
  
  pcVar2 = *(char **)(param_2 + 0xb8);
  cVar1 = *pcVar2;
  if (((cVar1 != '\x03') && (cVar1 != '\x04')) &&
     ((cVar1 != '\x0e' ||
      ((*(int *)(pcVar2 + 0x18) != 0x41808 && (*(int *)(pcVar2 + 0x18) != 0x41814)))))) {
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(char **)(param_2 + 0xb8) = pcVar2 + 0x48;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
    return lVar4;
  }
  p_Var3 = *(_FILE_OBJECT **)(*(longlong *)(*(longlong *)(pcVar2 + 0x30) + 0x18) + 0x18);
  if (p_Var3 == (_FILE_OBJECT *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xd,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0xca);
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000184;
    IofCompleteRequest(param_2,0);
    lVar4 = -0x3ffffe7c;
  }
  else {
    p_Var5 = (_DEVICE_OBJECT *)IoGetRelatedDeviceObject(p_Var3);
    lVar4 = forwardIrpToRemoteTarget(param_2,p_Var5,p_Var3,SUB81(param_1,0));
  }
  return lVar4;
}



===== WPP_RECORDER_SF_sDDD @ 1c0004f14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               ,4,&param_8,4,&param_9,4,0);
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
  WppAutoLogTrace(param_1,2,1,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDdqq @ 1c00050a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdqq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
               ,4,&param_8,4,&param_9,8,&param_10,8,0);
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
  WppAutoLogTrace(param_1,2,1,param_5,param_4,param_6,lVar1,&param_7,4,&param_8,4,&param_9,8,
                  &param_10,8,0);
  return;
}



===== RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT> @ 1c0005270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpWdfRequestRetrieveInputBuffer<struct
   _RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT>(struct WDFREQUEST__ * __ptr64,struct
   _RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT * __ptr64 * __ptr64,unsigned __int64) */

long __cdecl
RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT>
          (WDFREQUEST__ *param_1,_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT **param_2,
          __uint64 param_3)

{
  uint uVar1;
  _RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_1,4,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    if ((((uVar1 != 0xc0000023) && (uVar1 != 0xc00000e5)) && (uVar1 != 0xc000009a)) &&
       (uVar1 != 0xc0000017)) {
      uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
    }
  }
  else {
    *param_2 = local_res18;
    uVar1 = 0;
  }
  return uVar1;
}



===== RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT> @ 1c00052fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpWdfRequestRetrieveInputBuffer<struct
   _RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT>(struct WDFREQUEST__ * __ptr64,struct
   _RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT * __ptr64 * __ptr64,unsigned __int64) */

long __cdecl
RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT>
          (WDFREQUEST__ *param_1,_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT **param_2,
          __uint64 param_3)

{
  uint uVar1;
  _RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_1,0x10,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    if ((((uVar1 != 0xc0000023) && (uVar1 != 0xc00000e5)) && (uVar1 != 0xc000009a)) &&
       (uVar1 != 0xc0000017)) {
      uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
    }
  }
  else {
    *param_2 = local_res18;
    uVar1 = 0;
  }
  return uVar1;
}



===== RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT> @ 1c0005388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpWdfRequestRetrieveOutputBuffer<struct
   _RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT>(struct WDFREQUEST__ * __ptr64,struct
   _RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT * __ptr64 * __ptr64,unsigned __int64) */

long __cdecl
RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT>
          (WDFREQUEST__ *param_1,_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT **param_2,__uint64 param_3
          )

{
  uint uVar1;
  _RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,0x10,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    if ((((uVar1 != 0xc0000023) && (uVar1 != 0xc00000e5)) && (uVar1 != 0xc000009a)) &&
       (uVar1 != 0xc0000017)) {
      uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
    }
  }
  else {
    *param_2 = local_res18;
    uVar1 = 0;
  }
  return uVar1;
}



===== RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT> @ 1c0005414 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpWdfRequestRetrieveOutputBuffer<struct
   _RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT>(struct WDFREQUEST__ * __ptr64,struct
   _RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT * __ptr64 * __ptr64,unsigned __int64) */

long __cdecl
RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT>
          (WDFREQUEST__ *param_1,_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT **param_2,__uint64 param_3)

{
  uint uVar1;
  _RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,4,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    if ((((uVar1 != 0xc0000023) && (uVar1 != 0xc00000e5)) && (uVar1 != 0xc000009a)) &&
       (uVar1 != 0xc0000017)) {
      uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
    }
  }
  else {
    *param_2 = local_res18;
    uVar1 = 0;
  }
  return uVar1;
}



===== RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER> @ 1c00054a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpWdfRequestRetrieveOutputBuffer<struct _RHPROXY_GPIO_PIN_INTERRUPT_BUFFER>(struct
   WDFREQUEST__ * __ptr64,struct _RHPROXY_GPIO_PIN_INTERRUPT_BUFFER * __ptr64 * __ptr64,unsigned
   __int64) */

long __cdecl
RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER>
          (WDFREQUEST__ *param_1,_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER **param_2,__uint64 param_3)

{
  uint uVar1;
  _RHPROXY_GPIO_PIN_INTERRUPT_BUFFER *local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = (_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,0x20,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    if ((((uVar1 != 0xc0000023) && (uVar1 != 0xc00000e5)) && (uVar1 != 0xc000009a)) &&
       (uVar1 != 0xc0000017)) {
      uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
    }
  }
  else {
    *param_2 = local_res18;
    uVar1 = 0;
  }
  return uVar1;
}



===== _NOTIFICATION @ 1c000552c =====

/* public: __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::_NOTIFICATION(void)
   __ptr64 */

_NOTIFICATION * __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::_NOTIFICATION(_NOTIFICATION *this)

{
  _NOTIFICATION *p_Var1;
  
  *(undefined4 *)this = 0;
  KeInitializeSpinLock(this + 8);
  p_Var1 = this + 0x10;
  *(_NOTIFICATION **)(this + 0x18) = p_Var1;
  *(_NOTIFICATION **)p_Var1 = p_Var1;
  return this;
}



===== ~_INTERRUPT_LOCK @ 1c0005564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK(void)
   __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK(_INTERRUPT_LOCK *this)

{
  if (*(longlong *)this != 0) {
    (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals);
    *(undefined8 *)this = 0;
  }
  return;
}



===== operator[] @ 1c00055a0 =====

/* public: struct RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR & __ptr64 __cdecl
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::operator[](unsigned short) __ptr64 */

_PIN_DESCRIPTOR * __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::operator[](_PIN_DESCRIPTOR_INDEX *this,ushort param_1)

{
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(ushort *)(this + 2) <= param_1)) {
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x1a,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x14,
                        "DescriptorId < this->count");
  }
  if (*(ushort *)(this + 2) <= param_1) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  return (_PIN_DESCRIPTOR *)((ulonglong)param_1 * 0x98 + *(longlong *)(this + 8));
}



===== `vector_deleting_destructor' @ 1c0005640 =====

/* private: virtual void * __ptr64 __cdecl RHP_GPIO_CONTROLLER::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
RHP_GPIO_CONTROLLER::_vector_deleting_destructor_(RHP_GPIO_CONTROLLER *this,uint param_1)

{
  ~RHP_GPIO_CONTROLLER(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x33504852);
  }
  return this;
}



===== AcquireInterruptLockIfEnabled @ 1c0005684 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_INTERRUPT_LOCK __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(void) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(_INTERRUPT_CONTEXT *this)

{
  undefined8 *in_RDX;
  
  if ((*(uint *)this & 3) == 0) {
    *in_RDX = 0;
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
    *in_RDX = *(undefined8 *)(this + 0x58);
  }
  return;
}



===== DisableNotificationSynchronized @ 1c00056dc =====

/* public: void __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::DisableNotificationSynchronized(void) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::DisableNotificationSynchronized(_INTERRUPT_CONTEXT *this)

{
  _INTERRUPT_LOCK local_res8 [32];
  
  AcquireInterruptLockIfEnabled(this);
  *(uint *)this = *(uint *)this & 0xffffffcf;
  _INTERRUPT_LOCK::~_INTERRUPT_LOCK(local_res8);
  return;
}



===== EnableNotificationSynchronized @ 1c000570c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::EnableNotificationSynchronized(void) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::EnableNotificationSynchronized(_INTERRUPT_CONTEXT *this)

{
  long lVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  *(uint *)this = *(uint *)this | 0x30;
  lVar1 = *(long *)(this + 4);
  *(long *)(this + 0x60) = lVar1;
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  return lVar1;
}



===== EvtCleanupCallback @ 1c0005780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl
   RHP_GPIO_CONTROLLER::_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT::EvtCleanupCallback(void *
   __ptr64) */

void __cdecl
RHP_GPIO_CONTROLLER::_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT::EvtCleanupCallback(void *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF__RHP_GPIO_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT_TYPE_INFO_1c00100a0
                     );
  ObfDereferenceObjectWithTag(*puVar1,0x34504852);
  *puVar1 = 0;
  return;
}



===== EvtIoDeviceControl @ 1c00057e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_GPIO_CONTROLLER::EvtIoDeviceControl(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::EvtIoDeviceControl
          (RHP_GPIO_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,
          __uint64 param_4,ulong param_5)

{
  WDFFILEOBJECT__ *pWVar1;
  _FILE_OBJECT_CONTEXT *p_Var2;
  uint uVar3;
  RHP_GPIO_CONTROLLER *pRVar4;
  undefined8 uVar5;
  
  pWVar1 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (pWVar1 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xf,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x4b,(char)this,(char)param_2,
                 (char)param_5);
    }
  }
  else {
    pRVar4 = this;
    p_Var2 = getFileObjectContextFromWdfObject(this,pWVar1);
    uVar3 = (uint)pRVar4;
    if (param_5 != 0x2241a0) {
      dispatchIoControl(this,param_5,p_Var2,param_2);
      return;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqq
                (uVar5,2,3,0x10,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x58,(char)p_Var2,(char)param_2
                );
      uVar3 = (uint)uVar5;
    }
    _RhpLogDebug(uVar3);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000e5);
  return;
}



===== EvtIoInCallerContext @ 1c0005940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual void __cdecl RHP_GPIO_CONTROLLER::EvtIoInCallerContext(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::EvtIoInCallerContext
          (RHP_GPIO_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  char cVar1;
  uint uVar2;
  WDFFILEOBJECT__ *pWVar3;
  _FILE_OBJECT_CONTEXT *p_Var4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_38 = 0;
  uStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  uVar6 = WdfDriverGlobals;
  pWVar3 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  uVar2 = (uint)uVar6;
  if (pWVar3 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqqL
                (uVar6,2,3,0xe,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc1,(char)this,(char)param_2,
                 (char)((ulonglong)local_58 >> 0x20));
      uVar2 = (uint)uVar6;
    }
    _RhpLogDebug(uVar2);
    uVar6 = 0xc00000e5;
    goto LAB_1c0005a35;
  }
  p_Var4 = getFileObjectContextFromWdfObject(this,pWVar3);
  if (local_58._4_4_ == 0xe) {
    if ((ulong)uStack_40 == 0x2241a0) {
      cVar1 = KeGetCurrentIrql();
      if (cVar1 == '\0') {
        ioctlRhproxyGpioPinValueRegisterNotification(this,p_Var4,param_2);
        return;
      }
    }
    else {
      if ((ulong)uStack_40 != 0x22c1c2) goto LAB_1c0005ad1;
      cVar1 = KeGetCurrentIrql();
      if (cVar1 == '\0') {
        ioctlRhproxyGpioPinRegisterInterruptBufferInCallerContext(this,param_1,param_2);
        return;
      }
    }
    uVar6 = 0xc0000719;
LAB_1c0005a35:
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar6);
    return;
  }
LAB_1c0005ad1:
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if ((local_58._4_4_ == 0xe) && ((ulong)uStack_40 != 0x22c1cc)) {
      dispatchIoControl(this,(ulong)uStack_40,p_Var4,param_2);
      return;
    }
  }
  else {
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x450))(WdfDriverGlobals,uVar6);
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    if (((cVar1 == '\x01') && ((uVar2 & 2) == 0)) && (*(longlong *)(lVar5 + 0x50) == 0)) {
      uVar6 = 0xc000022d;
      goto LAB_1c0005a35;
    }
  }
  RHP_CONTROLLER::EvtIoInCallerContext((RHP_CONTROLLER *)this,param_1,param_2);
  return;
}



===== FastIoDeviceControl @ 1c0005be0 =====

/* public: static unsigned char __cdecl RHP_GPIO_CONTROLLER::FastIoDeviceControl(struct _FILE_OBJECT
   * __ptr64,unsigned char,void * __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned
   long,struct _IO_STATUS_BLOCK * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

uchar __cdecl
RHP_GPIO_CONTROLLER::FastIoDeviceControl
          (_FILE_OBJECT *param_1,uchar param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6,ulong param_7,_IO_STATUS_BLOCK *param_8,_DEVICE_OBJECT *param_9)

{
  undefined8 *puVar1;
  _PIN_DESCRIPTOR *this;
  char cVar2;
  _PIN_DESCRIPTOR _Var3;
  long lVar4;
  int iVar5;
  undefined7 in_register_00000011;
  uint uVar6;
  uchar uVar7;
  undefined4 in_register_0000008c;
  long local_res8 [2];
  
  uVar7 = '\0';
  if (*(longlong *)(param_1 + 0x20) == 0) {
    return '\0';
  }
  if (param_7 == 0x2241af) {
    cVar2 = KeGetCurrentIrql(param_1,CONCAT71(in_register_00000011,param_2),param_3,
                             CONCAT44(in_register_0000008c,param_4));
    if (cVar2 != '\0') {
      return '\0';
    }
    local_res8[0] = 0;
    lVar4 = readPinValue(*(_FILE_OBJECT_CONTEXT **)(param_1 + 0x20),local_res8);
    *(long *)param_8 = lVar4;
    if (lVar4 < 0) {
      return '\x01';
    }
    *(longlong *)(param_8 + 8) = (longlong)local_res8[0];
    return '\x01';
  }
  if (param_7 != 0x22819b) {
    if (((param_7 == 0x2281a7) || (param_7 == 0x2281ab)) &&
       (cVar2 = KeGetCurrentIrql(), cVar2 == '\0')) {
      lVar4 = writePinValue(*(_FILE_OBJECT_CONTEXT **)(param_1 + 0x20),(uint)(param_7 == 0x2281a7));
      *(long *)param_8 = lVar4;
      return '\x01';
    }
    return '\0';
  }
  cVar2 = KeGetCurrentIrql();
  if (cVar2 != '\0') {
    return '\0';
  }
  puVar1 = *(undefined8 **)(param_1 + 0x20);
  this = (_PIN_DESCRIPTOR *)*puVar1;
  ExAcquirePushLockExclusiveEx(this,2);
  uVar6 = (uint)param_3;
  if (((((uVar6 != 1) && (uVar6 != 2)) && ((uVar6 != 4 && ((uVar6 != 8 && (uVar6 != 0x10)))))) &&
      (uVar6 != 0x20)) && ((uVar6 != 0x40 && (uVar6 != 0x80)))) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc6,(char)param_3);
    }
    *(undefined4 *)param_8 = 0xc000000d;
LAB_1c0005d3f:
    if (this != (_PIN_DESCRIPTOR *)0x0) {
      ExReleasePushLockExclusiveEx(this,2);
    }
    return '\x01';
  }
  if ((*(uint *)(puVar1[1] + 0x2c) & uVar6) == 0) {
    *(undefined4 *)param_8 = 0xc00000bb;
    goto LAB_1c0005d3f;
  }
  if ((*(int **)(this + 0x60) != (int *)0x0) && (**(int **)(this + 0x60) != 0)) goto LAB_1c0005dfc;
  if ((uVar6 == 1) || ((uVar6 == 2 || (uVar6 == 4)))) {
    if (uVar6 == 1) {
LAB_1c0005dcb:
      _Var3 = (_PIN_DESCRIPTOR)0x3;
    }
    else if (uVar6 == 2) {
LAB_1c0005dc7:
      _Var3 = (_PIN_DESCRIPTOR)0x1;
    }
    else {
      if (uVar6 != 4) {
        if ((uVar6 != 8) && (uVar6 != 0x10)) {
          if (uVar6 == 0x20) goto LAB_1c0005dc7;
          if ((uVar6 != 0x40) && (uVar6 == 0x80)) goto LAB_1c0005dc2;
        }
        goto LAB_1c0005dcb;
      }
LAB_1c0005dc2:
      _Var3 = (_PIN_DESCRIPTOR)0x2;
    }
    if (_Var3 != this[0x8b]) goto LAB_1c0005dfc;
    local_res8[0] = 0;
    iVar5 = _PIN_DESCRIPTOR::ReadPinValue(this,local_res8);
  }
  else {
    iVar5 = _PIN_DESCRIPTOR::WritePinValue(this,*(long *)(this + 0xc));
  }
  *(int *)param_8 = iVar5;
  if (-1 < iVar5) {
    *(uint *)(this + 8) = uVar6;
  }
  uVar7 = '\x01';
LAB_1c0005dfc:
  ExReleasePushLockExclusiveEx(this,2);
  return uVar7;
}



===== FilterEdge @ 1c0005e70 =====

bool `anonymous_namespace'::FilterEdge(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_1 == 1) {
      return param_2 == 0;
    }
    if (param_1 == 2) {
      return param_2 != 0;
    }
    if (param_1 == 3) {
      return true;
    }
  }
  return false;
}



===== Insert @ 1c0005ea0 =====

/* public: long __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Insert(struct
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT::_NOTIFICATION_ENTRY * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Insert
          (_NOTIFICATION *this,_NOTIFICATION_ENTRY *param_1)

{
  long lVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(this + 8,&local_28);
  puVar4 = auStack_48;
  lVar1 = *(long *)this;
  plVar3 = *(longlong **)(this + 0x18);
  if ((_NOTIFICATION *)*plVar3 != this + 0x10) {
    pcVar2 = (code *)swi(0x29);
    plVar3 = (longlong *)(*pcVar2)(3);
    puVar4 = auStack_40;
  }
  *(_NOTIFICATION **)param_1 = this + 0x10;
  *(longlong **)(param_1 + 8) = plVar3;
  *plVar3 = (longlong)param_1;
  *(_NOTIFICATION_ENTRY **)(this + 0x18) = param_1;
  *(undefined8 *)(puVar4 + -8) = 0x1c0005f08;
  KeReleaseInStackQueuedSpinLock(puVar4 + 0x20);
  return lVar1;
}



===== PushCurrentTimestamp @ 1c0005f28 =====

/* public: long __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::PushCurrentTimestamp(long,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::PushCurrentTimestamp
          (_INTERRUPT_BUFFER_CONTEXT *this,long param_1,ulong *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  
  uVar7 = KeQueryPerformanceCounter(0);
  lVar4 = *(longlong *)this;
  iVar1 = *(int *)(this + 8);
  uVar2 = *(uint *)(lVar4 + 0x14);
  uVar3 = *(uint *)(lVar4 + 0x10);
  uVar9 = (uVar3 + 1) % (iVar1 + 1U);
  if (uVar9 == uVar2) {
    lVar6 = -0x7ffffffb;
  }
  else {
    *(undefined8 *)(*(longlong *)this + 0x18 + (ulonglong)((iVar1 + 0x3fU >> 6) + uVar3) * 8) =
         uVar7;
    uVar8 = *(ulonglong *)(*(longlong *)this + 0x18 + (ulonglong)(uVar3 >> 6) * 8);
    if (param_1 == 0) {
      uVar8 = uVar8 & ~(1L << (uVar3 & 0x3f));
    }
    else {
      uVar8 = uVar8 | 1L << (uVar3 & 0x3f);
    }
    *(ulonglong *)(*(longlong *)this + 0x18 + (ulonglong)(uVar3 >> 6) * 8) = uVar8;
    uVar5 = uVar9 - uVar2;
    *(uint *)(lVar4 + 0x10) = uVar9;
    if (uVar9 < uVar2) {
      uVar5 = uVar5 + 1 + iVar1;
    }
    *param_2 = uVar5;
    lVar6 = 0;
  }
  return lVar6;
}



===== Remove @ 1c0005ff4 =====

/* public: void __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Remove(struct
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT::_NOTIFICATION_ENTRY * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Remove
          (_NOTIFICATION *this,_NOTIFICATION_ENTRY *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(this + 8,&local_28);
  lVar1 = *(longlong *)param_1;
  if ((*(_NOTIFICATION_ENTRY **)(lVar1 + 8) == param_1) &&
     (plVar2 = *(longlong **)(param_1 + 8), (_NOTIFICATION_ENTRY *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseInStackQueuedSpinLock(&local_28);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== RtlStringCbVPrintfExW @ 1c0006060 =====

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
LAB_1c00060ce:
    iVar3 = -0x7ffffffb;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_Count < uVar2) goto LAB_1c00060ce;
    if (uVar2 != _Count) {
      _Count = uVar2;
      goto LAB_1c00060d5;
    }
  }
  param_1[_Count] = 0;
LAB_1c00060d5:
  if (((-1 < iVar3) || (iVar3 == -0x7ffffffb)) && (param_3 != (ushort **)0x0)) {
    *param_3 = param_1 + _Count;
  }
  return iVar3;
}



===== SatisfyWaitFromDpc @ 1c0006110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::SatisfyWaitFromDpc(struct
   WDFINTERRUPT__ * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::SatisfyWaitFromDpc
          (_INTERRUPT_BUFFER_CONTEXT *this,WDFINTERRUPT__ *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 in_R8;
  undefined1 local_28 [32];
  
  KeAcquireInStackQueuedSpinLockAtDpcLevel(this + 0x20,local_28);
  lVar1 = *(longlong *)(this + 0x28);
  if (lVar1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
                         &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd2);
    }
    KeReleaseInStackQueuedSpinLockFromDpcLevel(local_28);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,param_1);
    *(undefined8 *)(this + 0x28) = 0;
    *(undefined4 *)(this + 0x30) = 0;
    this[0x34] = (_INTERRUPT_BUFFER_CONTEXT)0x0;
    (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,param_1);
    KeReleaseInStackQueuedSpinLockFromDpcLevel(local_28);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,lVar1);
    if (iVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_R8,0xb,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xe3,(char)lVar1,(char)iVar2)
        ;
      }
      if (iVar2 == -0x3ffffee0) {
        return;
      }
    }
    else {
      iVar2 = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar1,iVar2);
  }
  return;
}



===== SatisfyWaitInterruptsDisabled @ 1c00062b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::SatisfyWaitInterruptsDisabled(void) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_BUFFER_CONTEXT::SatisfyWaitInterruptsDisabled
          (_INTERRUPT_BUFFER_CONTEXT *this)

{
  longlong lVar1;
  int iVar2;
  undefined8 in_R8;
  undefined1 local_28 [32];
  
  KeAcquireInStackQueuedSpinLock(this + 0x20,local_28);
  lVar1 = *(longlong *)(this + 0x28);
  if (lVar1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
                         &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",4);
    }
    KeReleaseInStackQueuedSpinLock(local_28);
  }
  else {
    *(undefined8 *)(this + 0x28) = 0;
    *(undefined4 *)(this + 0x30) = 0;
    this[0x34] = (_INTERRUPT_BUFFER_CONTEXT)0x0;
    KeReleaseInStackQueuedSpinLock(local_28);
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,lVar1);
    if (iVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,in_R8,0xd,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x12,(char)lVar1,(char)iVar2)
        ;
      }
      if (iVar2 == -0x3ffffee0) {
        return;
      }
    }
    else {
      iVar2 = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar1,iVar2);
  }
  return;
}



===== SetInterruptCountModeSynchronized @ 1c0006418 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::SetInterruptCountModeSynchronized(enum
   _RHPROXY_GPIO_INTERRUPT_MODE) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::SetInterruptCountModeSynchronized
          (_INTERRUPT_CONTEXT *this,_RHPROXY_GPIO_INTERRUPT_MODE param_1)

{
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  *(_RHPROXY_GPIO_INTERRUPT_MODE *)this = (param_1 * 4 ^ *(uint *)this) & 0xc ^ *(uint *)this;
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  return;
}



===== Trigger @ 1c0006488 =====

/* public: void __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Trigger(long)
   __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_NOTIFICATION::Trigger(_NOTIFICATION *this,long param_1)

{
  _NOTIFICATION *p_Var1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(this + 8,&local_28);
  if (param_1 != *(int *)this) {
    *(long *)this = param_1;
    for (p_Var1 = *(_NOTIFICATION **)(this + 0x10); p_Var1 != this + 0x10;
        p_Var1 = *(_NOTIFICATION **)p_Var1) {
      KeReleaseSemaphore(*(undefined8 *)(p_Var1 + 0x10),0,1);
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== acpiPullConfigFromRhproxyDriveMode @ 1c0006510 =====

undefined1 `anonymous_namespace'::acpiPullConfigFromRhproxyDriveMode(int param_1)

{
  if (param_1 != 1) {
    if (param_1 == 2) {
      return 1;
    }
    if (param_1 == 4) {
      return 2;
    }
    if ((param_1 != 8) && (param_1 != 0x10)) {
      if (param_1 == 0x20) {
        return 1;
      }
      if ((param_1 != 0x40) && (param_1 == 0x80)) {
        return 2;
      }
    }
  }
  return 3;
}



===== cancelRegisterInterruptBufferPassiveWorker @ 1c000654c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   RHP_GPIO_CONTROLLER::cancelRegisterInterruptBufferPassiveWorker(struct WDFREQUEST__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::cancelRegisterInterruptBufferPassiveWorker(WDFREQUEST__ *param_1)

{
  longlong lVar1;
  _INTERRUPT_CONTEXT *this;
  undefined8 uVar2;
  longlong *plVar3;
  _INTERRUPT_LOCK local_res10 [8];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,
                      PTR__WDF__RHP_GPIO_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c00100f0);
  (**(code **)(WdfFunctions_01015 + 0x528))(WdfDriverGlobals,*(undefined8 *)(*plVar3 + 0x70),0,0);
  lVar1 = *plVar3;
  ExAcquirePushLockExclusiveEx(lVar1,2);
  this = *(_INTERRUPT_CONTEXT **)(lVar1 + 0x60);
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x14,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x12,
                        (char)*(undefined4 *)(lVar1 + 0x80));
  }
  _INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(this);
  *(uint *)this = *(uint *)this & 0xffffff3f;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  this[0x45] = (_INTERRUPT_CONTEXT)0x0;
  _INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK(local_res10);
  if (((*(uint *)this & 3) != 0) && ((*(uint *)this & 0xfffffffc) == 0)) {
    _INTERRUPT_CONTEXT::DisableWdfInterrupt(this);
  }
  ExReleasePushLockExclusiveEx(lVar1,2);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0);
  return;
}



===== cancelWaitInterruptBufferPassiveWorker @ 1c00066dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::cancelWaitInterruptBufferPassiveWorker(struct
   WDFREQUEST__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::cancelWaitInterruptBufferPassiveWorker(WDFREQUEST__ *param_1)

{
  longlong lVar1;
  _INTERRUPT_CONTEXT *this;
  undefined8 uVar2;
  longlong *plVar3;
  _INTERRUPT_LOCK local_res10 [8];
  undefined1 local_28 [32];
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,
                      PTR__WDF__RHP_GPIO_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c00100f0);
  lVar1 = *plVar3;
  ExAcquirePushLockExclusiveEx(lVar1,2);
  this = *(_INTERRUPT_CONTEXT **)(lVar1 + 0x60);
  KeAcquireInStackQueuedSpinLock(this + 0x30,local_28);
  if (*(longlong *)(this + 0x38) == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xfd,(char)param_1);
    }
    KeReleaseInStackQueuedSpinLock(local_28);
    ExReleasePushLockExclusiveEx(lVar1,2);
  }
  else {
    _INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(this);
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    this[0x44] = (_INTERRUPT_CONTEXT)0x0;
    _INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK(local_res10);
    KeReleaseInStackQueuedSpinLock(local_28);
    ExReleasePushLockExclusiveEx(lVar1,2);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  }
  return;
}



===== evtInterruptDpc @ 1c0006870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtInterruptDpc(struct WDFINTERRUPT__ *
   __ptr64,void * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::evtInterruptDpc(WDFINTERRUPT__ *param_1,void *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  bool bVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar2 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF__RHP_GPIO_CONTROLLER_INTERRUPT_CONTEXT_TYPE_INFO_1c00100c8);
  uVar1 = puVar2[1];
  uVar3 = *puVar2 >> 4 & 3;
  if (uVar3 == 0) goto LAB_1c0006950;
  if (uVar3 == 1) {
    bVar5 = uVar1 == 0;
LAB_1c00068e1:
    if (!bVar5) goto LAB_1c0006950;
  }
  else {
    if (uVar3 == 2) {
      bVar5 = uVar1 != 0;
      goto LAB_1c00068e1;
    }
    if (uVar3 != 3) goto LAB_1c0006950;
  }
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(puVar2 + 0x1a,&local_28);
  uVar3 = puVar2[0x18];
  puVar2[0x18] = uVar1;
  for (puVar4 = *(uint **)(puVar2 + 0x1c); puVar4 != puVar2 + 0x1c; puVar4 = *(uint **)puVar4) {
    KeReleaseSemaphore(*(undefined8 *)(puVar4 + 4),0,(uVar1 == uVar3) + '\x01',0);
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
LAB_1c0006950:
  if ((char)puVar2[0x11] != '\0') {
    _INTERRUPT_BUFFER_CONTEXT::SatisfyWaitFromDpc((_INTERRUPT_BUFFER_CONTEXT *)(puVar2 + 4),param_1)
    ;
  }
  if (*(char *)((longlong)puVar2 + 0x45) != '\0') {
    *(undefined1 *)((longlong)puVar2 + 0x45) = 0;
    KeSetEvent(*(undefined8 *)(puVar2 + 10),1);
  }
  return;
}



===== evtInterruptIsr @ 1c00069b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static unsigned char __cdecl RHP_GPIO_CONTROLLER::evtInterruptIsr(struct WDFINTERRUPT__
   * __ptr64,unsigned long) */

uchar __cdecl RHP_GPIO_CONTROLLER::evtInterruptIsr(WDFINTERRUPT__ *param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  ulong local_res18 [2];
  
  puVar3 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF__RHP_GPIO_CONTROLLER_INTERRUPT_CONTEXT_TYPE_INFO_1c00100c8);
  uVar5 = *puVar3;
  uVar4 = uVar5 & 3;
  if (uVar4 == 1) {
    uVar4 = 0;
  }
  else if (uVar4 == 2) {
    uVar4 = 1;
  }
  else {
    if (uVar4 != 3) {
      return '\0';
    }
    puVar3[1] = puVar3[1] ^ 1;
    uVar4 = puVar3[1];
  }
  uVar1 = uVar5 >> 2 & 3;
  if (uVar1 != 0) {
    if (uVar1 == 1) {
      bVar6 = uVar4 == 0;
LAB_1c0006a44:
      if (!bVar6) goto LAB_1c0006a4c;
    }
    else {
      if (uVar1 == 2) {
        bVar6 = uVar4 != 0;
        goto LAB_1c0006a44;
      }
      if (uVar1 != 3) goto LAB_1c0006a4c;
    }
    *(longlong *)(puVar3 + 2) = *(longlong *)(puVar3 + 2) + 1;
  }
LAB_1c0006a4c:
  uVar1 = uVar5 >> 6 & 3;
  if (uVar1 != 0) {
    if (uVar1 == 1) {
      bVar6 = uVar4 == 0;
LAB_1c0006a73:
      if (!bVar6) goto LAB_1c0006ad1;
    }
    else {
      if (uVar1 == 2) {
        bVar6 = uVar4 != 0;
        goto LAB_1c0006a73;
      }
      if (uVar1 != 3) goto LAB_1c0006ad1;
    }
    local_res18[0] = 0;
    lVar2 = _INTERRUPT_BUFFER_CONTEXT::PushCurrentTimestamp
                      ((_INTERRUPT_BUFFER_CONTEXT *)(puVar3 + 4),uVar4,local_res18);
    if (lVar2 == -0x7ffffffb) {
      *(undefined1 *)((longlong)puVar3 + 0x45) = 1;
    }
    else {
      if (((lVar2 != 0) || (*(longlong *)(puVar3 + 0xe) == 0)) || (local_res18[0] < puVar3[0x10]))
      goto LAB_1c0006ad1;
      *(undefined1 *)(puVar3 + 0x11) = 1;
    }
    (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
  }
LAB_1c0006ad1:
  uVar5 = uVar5 >> 4 & 3;
  if (uVar5 == 0) {
    return '\x01';
  }
  if (uVar5 == 1) {
    bVar6 = uVar4 == 0;
  }
  else {
    if (uVar5 != 2) {
      if (uVar5 != 3) {
        return '\x01';
      }
      goto LAB_1c0006afa;
    }
    bVar6 = uVar4 != 0;
  }
  if (!bVar6) {
    return '\x01';
  }
LAB_1c0006afa:
  (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
  return '\x01';
}



===== evtRegisterInterruptBufferRequestCancel @ 1c0006b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtRegisterInterruptBufferRequestCancel(struct
   WDFREQUEST__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::evtRegisterInterruptBufferRequestCancel(WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 local_res10 [3];
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  WDFREQUEST__ *local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    cancelRegisterInterruptBufferPassiveWorker(param_1);
  }
  else {
    local_48 = 0;
    local_58 = 0x18;
    pcStack_50 = evtCancelRegisterInterruptBufferWorkItem;
    local_res10[0] = 0;
    local_30 = 0;
    local_10 = 0;
    uStack_38 = 0;
    local_40 = 0x38;
    uStack_18 = 0;
    uStack_28 = 0x100000001;
    local_20 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_58,&local_40,local_res10);
    if (iVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd5,(char)iVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10[0]);
    }
  }
  return;
}



===== evtWaitInterruptBufferRequestCancel @ 1c0006ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtWaitInterruptBufferRequestCancel(struct
   WDFREQUEST__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::evtWaitInterruptBufferRequestCancel(WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  undefined8 local_res10 [3];
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  WDFREQUEST__ *local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    cancelWaitInterruptBufferPassiveWorker(param_1);
  }
  else {
    local_48 = 0;
    local_58 = 0x18;
    pcStack_50 = evtCancelWaitInterruptBufferWorkItem;
    local_res10[0] = 0;
    local_30 = 0;
    local_10 = 0;
    uStack_38 = 0;
    local_40 = 0x38;
    uStack_18 = 0;
    uStack_28 = 0x100000001;
    local_20 = param_1;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_58,&local_40,local_res10);
    if (iVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x18,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc3,(char)iVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10[0]);
    }
  }
  return;
}



===== getFileObjectContextFromWdfObject @ 1c0006dfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: class RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT * __ptr64 __cdecl
   RHP_GPIO_CONTROLLER::getFileObjectContextFromWdfObject(struct WDFFILEOBJECT__ * __ptr64) __ptr64
    */

_FILE_OBJECT_CONTEXT * __thiscall
RHP_GPIO_CONTROLLER::getFileObjectContextFromWdfObject
          (RHP_GPIO_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  _FILE_OBJECT_CONTEXT *p_Var1;
  
  p_Var1 = (_FILE_OBJECT_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,(char)param_1,
                      PTR__WDF__RHP_GPIO_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c00100f0);
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(RHP_GPIO_CONTROLLER **)(p_Var1 + 8) == this) {
      return p_Var1;
    }
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x1c,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x4c,
                        "fileObjectContextPtr->gpioControllerPtr == this");
  }
  if (*(RHP_GPIO_CONTROLLER **)(p_Var1 + 8) != this) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  return p_Var1;
}



===== ioctlRhproxyGpioPinQueryInterruptCount @ 1c0006eac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinQueryInterruptCount(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64,bool)
   __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinQueryInterruptCount
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2,
          bool param_3)

{
  longlong lVar1;
  _INTERRUPT_CONTEXT *this_00;
  undefined1 uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *local_res10;
  undefined8 local_28;
  _INTERRUPT_LOCK local_20 [8];
  
  if (*(longlong *)param_1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x12,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x84,(char)this,(char)param_1);
    }
  }
  else {
    puVar5 = (undefined8 *)0x0;
    local_28 = 0;
    local_res10 = (undefined8 *)0x0;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,0x10,&local_res10,&local_28);
    if ((int)uVar4 < 0) {
      if ((((uVar4 == 0xc0000023) || (uVar4 == 0xc00000e5)) || (uVar4 == 0xc000009a)) ||
         ((uVar4 == 0xc0000017 || (uVar4 = (int)uVar4 >> 0x1f & 0xc0000001, (int)uVar4 < 0))))
      goto LAB_1c0006f2a;
    }
    else {
      puVar5 = local_res10;
    }
    lVar1 = *(longlong *)param_1;
    this_00 = *(_INTERRUPT_CONTEXT **)(lVar1 + 0x60);
    if (this_00 != (_INTERRUPT_CONTEXT *)0x0) {
      if (param_3) {
        ExAcquirePushLockExclusiveEx(lVar1,2);
        _INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(this_00);
        *puVar5 = *(undefined8 *)(this_00 + 8);
        *(undefined8 *)(this_00 + 8) = 0;
        uVar3 = KeQueryPerformanceCounter(0);
        puVar5[1] = uVar3;
        _INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK(local_20);
        if (lVar1 != 0) {
          ExReleasePushLockExclusiveEx(lVar1,2);
        }
      }
      else {
        uVar2 = KfRaiseIrql(2);
        *puVar5 = *(undefined8 *)(this_00 + 8);
        uVar3 = KeQueryPerformanceCounter(0);
        puVar5[1] = uVar3;
        KeLowerIrql(uVar2);
      }
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,0x10);
      return;
    }
  }
  uVar4 = 0xc00000bb;
LAB_1c0006f2a:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar4);
  return;
}



===== ioctlRhproxyGpioPinWaitInterruptBuffer @ 1c00070d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinWaitInterruptBuffer(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) */

long __cdecl
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinWaitInterruptBuffer
          (_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  _INTERRUPT_CONTEXT *this;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  WDFREQUEST__ *pWVar6;
  undefined8 uVar7;
  code *pcVar8;
  uint *puVar9;
  uint *local_res8;
  undefined8 local_res18;
  undefined1 local_48 [32];
  
  lVar2 = *(longlong *)param_1;
  ExAcquirePushLockExclusiveEx(lVar2,2);
  this = *(_INTERRUPT_CONTEXT **)(lVar2 + 0x60);
  if (this == (_INTERRUPT_CONTEXT *)0x0) {
    uVar4 = 0xc00000bb;
  }
  else if (*(longlong *)(this + 0x20) == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                         &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x44);
    }
    uVar4 = 0xc0000184;
  }
  else {
    local_res18 = 0;
    local_res8 = (uint *)0x0;
    uVar7 = 4;
    puVar9 = (uint *)0x0;
    pWVar6 = param_2;
    uVar4 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_2,4,&local_res8,&local_res18);
    if ((int)uVar4 < 0) {
      if ((((uVar4 == 0xc0000023) || (uVar4 == 0xc00000e5)) || (uVar4 == 0xc000009a)) ||
         ((uVar4 == 0xc0000017 || (uVar4 = (int)uVar4 >> 0x1f & 0xc0000001, (int)uVar4 < 0))))
      goto LAB_1c0007384;
    }
    else {
      puVar9 = local_res8;
    }
    uVar4 = *puVar9;
    if (*(uint *)(this + 0x18) < uVar4) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar6,uVar7,0x16,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x59,(char)uVar4,
                   (char)*(uint *)(this + 0x18));
      }
      uVar4 = 0xc000000d;
    }
    else {
      KeAcquireInStackQueuedSpinLock(this + 0x30,local_48);
      lVar3 = *(longlong *)(this + 0x10);
      _INTERRUPT_CONTEXT::AcquireInterruptLockIfEnabled(this);
      uVar1 = *(uint *)(lVar3 + 0x14);
      uVar5 = *(uint *)(lVar3 + 0x10);
      if (uVar5 < uVar1) {
        uVar5 = uVar5 + 1 + (*(int *)(this + 0x18) - uVar1);
      }
      else {
        uVar5 = uVar5 - uVar1;
      }
      if (uVar5 < uVar4) {
        *(WDFREQUEST__ **)(this + 0x38) = param_2;
        *(uint *)(this + 0x40) = uVar4;
        this[0x44] = (_INTERRUPT_CONTEXT)0x0;
        _INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK((_INTERRUPT_LOCK *)&local_res8);
        pcVar8 = evtWaitInterruptBufferRequestCancel;
        uVar4 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2);
        if ((int)uVar4 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar8,0x17,
                       &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x97,(char)param_2,
                       (char)uVar4);
          }
          *(undefined8 *)(this + 0x38) = 0;
          *(undefined4 *)(this + 0x40) = 0;
          this[0x44] = (_INTERRUPT_CONTEXT)0x0;
          KeReleaseInStackQueuedSpinLock(local_48);
        }
        else {
          KeReleaseInStackQueuedSpinLock(local_48);
          uVar4 = 0x103;
        }
      }
      else {
        _INTERRUPT_CONTEXT::_INTERRUPT_LOCK::~_INTERRUPT_LOCK((_INTERRUPT_LOCK *)&local_res8);
        KeReleaseInStackQueuedSpinLock(local_48);
        uVar4 = 0;
      }
    }
  }
LAB_1c0007384:
  ExReleasePushLockExclusiveEx(lVar2,2);
  return uVar4;
}



===== pnpGpioIrqPolarityFromRhproxyInterruptMode @ 1c00073bc =====

undefined1 `anonymous_namespace'::pnpGpioIrqPolarityFromRhproxyInterruptMode(int param_1)

{
  if (param_1 == 1) {
    return 2;
  }
  if ((param_1 == 2) || (param_1 != 3)) {
    return 0;
  }
  return 4;
}



===== reserve @ 1c00073e0 =====

/* private: long __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::reserve(unsigned short) __ptr64
    */

long __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::reserve(_PIN_DESCRIPTOR_INDEX *this,ushort param_1)

{
  _PIN_DESCRIPTOR *p_Var1;
  _PIN_DESCRIPTOR_INDEX *p_Var2;
  longlong *plVar3;
  undefined1 auVar4 [16];
  long lVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong *puVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint uVar11;
  _PIN_DESCRIPTOR *p_Var12;
  longlong lVar13;
  RHP_DRIVER *this_00;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  
  if (*(ushort *)this < param_1) {
    if ((param_1 & 0x3f) != 0) {
      param_1 = (param_1 & 0xffc0) + 0x40;
    }
    uVar9 = CONCAT62(0,param_1);
    uVar10 = 0x34504852;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar9;
    uVar6 = SUB168(ZEXT816(0x98) * auVar4,0);
    if (SUB168(ZEXT816(0x98) * auVar4,8) != 0) {
      uVar6 = 0xffffffffffffffff;
    }
    lVar7 = uVar6 + 8;
    if (0xfffffffffffffff7 < uVar6) {
      lVar7 = -1;
    }
    if (lVar7 == 0) {
      lVar7 = 1;
    }
    puVar8 = (ulonglong *)ExAllocatePoolWithTag(0x200,lVar7);
    if (puVar8 != (ulonglong *)0x0) {
      *puVar8 = uVar9;
      p_Var1 = (_PIN_DESCRIPTOR *)(puVar8 + 1);
      p_Var12 = p_Var1;
      for (; uVar9 != 0; uVar9 = uVar9 - 1) {
        _PIN_DESCRIPTOR::_PIN_DESCRIPTOR(p_Var12);
        p_Var12 = p_Var12 + 0x98;
      }
      if (p_Var1 != (_PIN_DESCRIPTOR *)0x0) {
        p_Var2 = this + 8;
        uVar11 = 0;
        if (*(short *)this != 0) {
          do {
            uVar9 = (ulonglong)uVar11;
            uVar11 = uVar11 + 1;
            lVar7 = uVar9 * 0x98;
            p_Var12 = p_Var1 + lVar7;
            *(undefined8 *)(p_Var12 + 0x78) = *(undefined8 *)(*(longlong *)p_Var2 + 0x78 + lVar7);
            *(undefined4 *)(p_Var12 + 0x80) = *(undefined4 *)(*(longlong *)p_Var2 + 0x80 + lVar7);
            lVar7 = *(longlong *)(*(longlong *)p_Var2 + 0x60 + lVar7);
            *(longlong *)(p_Var12 + 0x60) = lVar7;
            *(_PIN_DESCRIPTOR **)(lVar7 + 0x48) = p_Var12;
          } while (uVar11 < *(ushort *)this);
        }
        lVar7 = *(longlong *)p_Var2;
        if (lVar7 != 0) {
          plVar3 = (longlong *)(lVar7 + -8);
          lVar13 = *plVar3;
          this_00 = (RHP_DRIVER *)(lVar13 * 0x98 + lVar7);
          for (; lVar13 != 0; lVar13 = lVar13 + -1) {
            this_00 = this_00 + -0x98;
            RHP_DRIVER::evtCleanupCallback(this_00);
          }
          if (plVar3 != (longlong *)0x0) {
            ExFreePoolWithTag(plVar3,0);
          }
        }
        *(ushort *)this = param_1;
        *(_PIN_DESCRIPTOR **)(this + 8) = p_Var1;
        goto LAB_1c0007407;
      }
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar10,0x1b,in_stack_ffffffffffffffa8,
                 in_stack_ffffffffffffffb0,0x2d,(char)this,(char)param_1);
    }
    lVar5 = -0x3fffffe9;
  }
  else {
LAB_1c0007407:
    lVar5 = 0;
  }
  return lVar5;
}



===== RESOURCE_HUB_STRING_PRINTF @ 1c00075ac =====

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



===== RESOURCE_HUB_UNICODE_STRING_PRINTF @ 1c00075dc =====

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



===== WPP_RECORDER_SF_sDDDD @ 1c0007640 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x8be;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x3a,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x3a,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDDDd @ 1c0007788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
               &param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
                  &param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF_sDLD @ 1c00078c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
               &param_9,4,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDLLd @ 1c00079e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLLd(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x8ff;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x3e,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x3e,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDLd @ 1c0007b2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
               &param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,4,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDPLLq @ 1c0007c48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDPLLq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0xb65;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x51,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,
               &uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x51,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,
                  &uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_sDSS @ 1c0007dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDSS
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined8 param_6,undefined1 param_7,wchar_t *param_8,wchar_t *param_9)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  pwVar5 = param_9;
  pwVar7 = param_8;
  lVar8 = -1;
  uVar9 = (ulonglong)(param_3 >> 0x10);
  lVar6 = 10;
  param_8 = L"NULL";
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar9 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar9 * 0x50 + 0x29])) {
    if (param_9 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_9[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar4 = param_9;
    if (param_9 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    if (pwVar7 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (pwVar7[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = pwVar7;
    if (pwVar7 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar9 * 0x50 + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,pwVar3,lVar2,
               pwVar4,lVar1,0);
  }
  if (pwVar5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (pwVar5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (pwVar5 == (wchar_t *)0x0) {
    pwVar5 = L"NULL";
  }
  if (pwVar7 != (wchar_t *)0x0) {
    do {
      lVar8 = lVar8 + 1;
    } while (pwVar7[lVar8] != L'\0');
    lVar6 = lVar8 * 2 + 2;
  }
  if (pwVar7 == (wchar_t *)0x0) {
    pwVar7 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,pwVar7,lVar6,
                  pwVar5,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_sDdqHLi @ 1c0008008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdqHLi(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined4 local_28 [4];
  
  local_28[0] = 0x63b;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x21,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_28,4,
               &uStack0000000000000040,4,&uStack0000000000000048,8,&uStack0000000000000050,2,
               &uStack0000000000000058,4,&uStack0000000000000060,8,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x21,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_28,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,&uStack0000000000000050,2,
                  &uStack0000000000000058,4,&uStack0000000000000060,8,0);
  return;
}



===== WPP_RECORDER_SF_sDiLd @ 1c000819c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDiLd(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x107e;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x8a,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x8a,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqL @ 1c00082f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqL
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
               &param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
                  &param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqLLL @ 1c000841c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLLL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
               &param_9,4,&param_10,4,&param_11,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
                  &param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqLi @ 1c0008588 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLi(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x124f;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x94,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x94,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqLq @ 1c00086e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqLq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x6ea;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x28,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,3,1,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x28,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqi @ 1c0008834 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqi
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined8 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
               &param_9,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,param_4,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,&param_7,4,&param_8,8,
                  &param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqll @ 1c00089b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqll(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x1232;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x93,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
               &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x93,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_sDqqS @ 1c0008b04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  undefined4 local_28 [4];
  
  local_28[0] = 0xdcd;
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000050 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000050[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000050;
    if (in_stack_00000050 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x6b,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_28,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,pwVar2,lVar1,0);
  }
  if (in_stack_00000050 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000050[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000050 == (wchar_t *)0x0) {
    in_stack_00000050 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,3,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,0x6b,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2d,local_28,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,in_stack_00000050,lVar3,0);
  return;
}



===== `vector_deleting_destructor' @ 1c0008cf0 =====

/* protected: virtual void * __ptr64 __cdecl RHP_SPI_CONTROLLER::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
RHP_SPI_CONTROLLER::_vector_deleting_destructor_(RHP_SPI_CONTROLLER *this,uint param_1)

{
  ~RHP_SPI_CONTROLLER(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x33504852);
  }
  return this;
}



===== EvtDeviceWdmIrpPreprocess @ 1c0008d40 =====

/* public: virtual long __cdecl RHP_I2C_CONTROLLER::EvtDeviceWdmIrpPreprocess(struct WDFDEVICE__ *
   __ptr64,struct _IRP * __ptr64) __ptr64 */

long __thiscall
RHP_I2C_CONTROLLER::EvtDeviceWdmIrpPreprocess
          (RHP_I2C_CONTROLLER *this,WDFDEVICE__ *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = RHP_CONTROLLER::spbWdmIrpPreprocess(param_1,param_2);
  return lVar1;
}



===== EvtIoDeviceControl @ 1c0008d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_SPI_CONTROLLER::EvtIoDeviceControl(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) __ptr64 */

void __thiscall
RHP_SPI_CONTROLLER::EvtIoDeviceControl
          (RHP_SPI_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,
          __uint64 param_4,ulong param_5)

{
  long lVar1;
  WDFFILEOBJECT__ *pWVar2;
  RHP_SPI_CONTROLLER *this_00;
  WDFREQUEST__ *pWVar3;
  
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqqDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  this_00 = WdfDriverGlobals;
  pWVar3 = param_2;
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))();
  if (pWVar2 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                 &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x4a,(char)this,(char)param_2);
    }
    lVar1 = -0x3fffff1b;
    goto LAB_1c0008f31;
  }
  if ((param_5 == 0x41808) || (param_5 == 0x41814)) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this_00 = *(RHP_SPI_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDs(this_00,2,3,0xc,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x61,
                          "!\"IOCTL_SPB_... should have been forwarded by WdmIrpPreprocess\"");
    }
    _RhpLogDebug((uint)this_00);
  }
  else {
    if (param_5 == 0x2244b0) {
      lVar1 = ioctlGetConnectionSetting(this_00,param_2,pWVar2);
      goto LAB_1c0008f31;
    }
    if (param_5 == 0x2244b8) {
      lVar1 = ioctlGetBusInfo(this,param_2);
      goto LAB_1c0008f31;
    }
    if (param_5 == 0x2284b4) {
      lVar1 = ioctlSetConnectionSetting(this,(WDFQUEUE__ *)pWVar3,param_2,pWVar2);
      goto LAB_1c0008f31;
    }
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqqL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
               &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x68,(char)this,(char)param_2,
               (char)param_5);
  }
  lVar1 = -0x3fffff45;
LAB_1c0008f31:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== ioctlGetBusInfo @ 1c0008f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_SPI_CONTROLLER::ioctlGetBusInfo(struct WDFREQUEST__ * __ptr64) __ptr64
    */

long __thiscall RHP_SPI_CONTROLLER::ioctlGetBusInfo(RHP_SPI_CONTROLLER *this,WDFREQUEST__ *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 *local_res18;
  undefined8 local_res20;
  
  puVar6 = (undefined8 *)0x0;
  local_res20 = 0;
  local_res18 = (undefined8 *)0x0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,0x2c,&local_res18,&local_res20);
  if ((int)uVar5 < 0) {
    if ((((uVar5 == 0xc0000023) || (uVar5 == 0xc00000e5)) || (uVar5 == 0xc000009a)) ||
       ((uVar5 == 0xc0000017 || (uVar5 = (int)uVar5 >> 0x1f & 0xc0000001, (int)uVar5 < 0)))) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar5;
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x6d,(char)uVar5);
      return uVar5;
    }
  }
  else {
    puVar6 = local_res18;
  }
  uVar4 = *(undefined8 *)(this + 0x88);
  *puVar6 = *(undefined8 *)(this + 0x80);
  puVar6[1] = uVar4;
  uVar1 = *(undefined4 *)(this + 0x94);
  uVar2 = *(undefined4 *)(this + 0x98);
  uVar3 = *(undefined4 *)(this + 0x9c);
  *(undefined4 *)(puVar6 + 2) = *(undefined4 *)(this + 0x90);
  *(undefined4 *)((longlong)puVar6 + 0x14) = uVar1;
  *(undefined4 *)(puVar6 + 3) = uVar2;
  *(undefined4 *)((longlong)puVar6 + 0x1c) = uVar3;
  puVar6[4] = *(undefined8 *)(this + 0xa0);
  *(undefined4 *)(puVar6 + 5) = *(undefined4 *)(this + 0xa8);
  (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_1,0x2c);
  return 0;
}



===== ioctlGetConnectionSetting @ 1c00090a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_SPI_CONTROLLER::ioctlGetConnectionSetting(struct WDFREQUEST__ *
   __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

long __thiscall
RHP_SPI_CONTROLLER::ioctlGetConnectionSetting
          (RHP_SPI_CONTROLLER *this,WDFREQUEST__ *param_1,WDFFILEOBJECT__ *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  RHP_SPI_CONTROLLER *pRVar5;
  uint uVar6;
  uint uVar7;
  RHP_SPI_CONTROLLER *local_res8;
  undefined8 local_res20;
  
  local_res8 = this;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF__RHP_SPI_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010118);
  ExAcquirePushLockSharedEx(lVar4,2);
  uVar6 = 0;
  if (*(longlong *)(lVar4 + 8) == 0) {
    uVar6 = 0xc0000184;
  }
  else {
    local_res20 = 0;
    local_res8 = (RHP_SPI_CONTROLLER *)0x0;
    pRVar5 = (RHP_SPI_CONTROLLER *)0x0;
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_1,0x10,&local_res8,&local_res20);
    if ((int)uVar7 < 0) {
      if ((((uVar7 == 0xc0000023) || (uVar7 == 0xc00000e5)) || (uVar7 == 0xc000009a)) ||
         ((uVar7 == 0xc0000017 || (uVar7 = (int)uVar7 >> 0x1f & 0xc0000001, (int)uVar7 < 0)))) {
        uVar6 = uVar7;
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xe,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x8f,(char)uVar6);
        }
        goto LAB_1c0009209;
      }
    }
    else {
      pRVar5 = local_res8;
    }
    uVar1 = *(undefined4 *)(lVar4 + 0x24);
    uVar2 = *(undefined4 *)(lVar4 + 0x28);
    uVar3 = *(undefined4 *)(lVar4 + 0x2c);
    *(undefined4 *)pRVar5 = *(undefined4 *)(lVar4 + 0x20);
    *(undefined4 *)(pRVar5 + 4) = uVar1;
    *(undefined4 *)(pRVar5 + 8) = uVar2;
    *(undefined4 *)(pRVar5 + 0xc) = uVar3;
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_1,0x10);
  }
LAB_1c0009209:
  ExReleasePushLockSharedEx(lVar4,2);
  return uVar6;
}



===== ioctlSetConnectionSetting @ 1c000923c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c00097c8) */
/* WARNING: Removing unreachable block (ram,0x0001c00098d9) */
/* WARNING: Removing unreachable block (ram,0x0001c00097ef) */
/* WARNING: Removing unreachable block (ram,0x0001c0009981) */
/* private: long __cdecl RHP_SPI_CONTROLLER::ioctlSetConnectionSetting(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

long __thiscall
RHP_SPI_CONTROLLER::ioctlSetConnectionSetting
          (RHP_SPI_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _SPI_RESOURCE *p_Var5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  byte *pbVar10;
  undefined1 auStackY_198 [32];
  longlong local_130;
  _SPI_RESOURCE *local_128;
  longlong local_120;
  byte *local_118;
  short local_110 [4];
  undefined1 *local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined2 local_d8;
  undefined2 local_d6;
  undefined4 local_d4;
  ulonglong local_d0;
  __uint64 local_c8 [2];
  short *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,
                     PTR__WDF__RHP_SPI_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010118);
  ExAcquirePushLockExclusiveEx(lVar7,2);
  if (*(longlong *)(lVar7 + 8) != 0) {
    uVar6 = 0xc0000184;
    goto LAB_1c00099e9;
  }
  local_100 = 0;
  local_118 = (byte *)0x0;
  pbVar10 = (byte *)0x0;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_118);
  if ((int)uVar6 < 0) {
    if ((((uVar6 == 0xc0000023) || (uVar6 == 0xc00000e5)) || (uVar6 == 0xc000009a)) ||
       ((uVar6 == 0xc0000017 || (uVar6 = (int)uVar6 >> 0x1f & 0xc0000001, (int)uVar6 < 0)))) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xf,
                            &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xb3,(char)uVar6);
      }
      goto LAB_1c00099e9;
    }
  }
  else {
    pbVar10 = local_118;
  }
  iVar1 = *(int *)(pbVar10 + 8);
  if ((((iVar1 == 0) || (iVar1 == 1)) || ((iVar1 == 2 || (iVar1 == 3)))) &&
     (((*(int *)(pbVar10 + 0xc) == 0 || (*(int *)(pbVar10 + 0xc) == 1)) && (*pbVar10 != 0)))) {
    if (((*(uint *)(this + 0x84) <= *(uint *)(pbVar10 + 4)) &&
        (*(uint *)(pbVar10 + 4) <= *(uint *)(this + 0x88))) &&
       (uVar9 = (ulonglong)(*pbVar10 - 1),
       (*(byte *)(*(longlong *)(this + 0xb8) + ((longlong)uVar9 >> 3)) >> (uVar9 & 7) & 1) != 0)) {
      local_128 = (_SPI_RESOURCE *)0x0;
      uVar6 = AcquireResource(this,*(ushort *)(pbVar10 + 2),
                              *(_RHPROXY_SPI_SHARING_MODE *)(pbVar10 + 0xc),&local_128);
      p_Var5 = local_128;
      if ((int)uVar6 < 0) goto LAB_1c00099e9;
      local_120 = 0;
      iVar1 = *(int *)(pbVar10 + 8);
      local_d0 = 0;
      local_e8 = 1;
      local_e4 = 2;
      local_e0 = *(undefined8 *)(local_128 + 0x10);
      local_d8 = 0xffff;
      local_d6 = *(undefined2 *)(local_128 + 10);
      local_d4 = *(undefined4 *)(pbVar10 + 4);
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          local_d0 = 0x100;
        }
        else {
          uVar6 = iVar1 - 2;
          if (uVar6 == 0) {
            local_d0 = 1;
          }
          else {
            if (uVar6 != 1) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
                WPP_RECORDER_SF_sDd(uVar8,2,3,0x10,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                                    "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xed,
                                    (char)iVar1);
                uVar6 = (uint)uVar8;
              }
              _RhpLogDebug(uVar6);
              ReleaseResource(this,*(ushort *)(local_128 + 8));
              goto LAB_1c00094a7;
            }
            local_d0 = 0x101;
          }
        }
      }
      local_d0 = (ulonglong)CONCAT13(*pbVar10,(undefined3)local_d0);
      ExAcquirePushLockExclusiveEx(local_128,2);
      uVar6 = RHP_DEVICE::InsertResourceHubRecord
                        (*(RHP_DEVICE **)(this + 8),
                         (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_e8,
                         (_LARGE_INTEGER *)&local_120);
      if ((int)uVar6 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xfc,(char)uVar6);
        }
        if ((uVar6 != 0xc000009a) && (uVar6 != 0xc0000017)) {
          uVar6 = (int)uVar6 >> 0x1f & 0xc0000001;
        }
        if (p_Var5 != (_SPI_RESOURCE *)0x0) {
          ExReleasePushLockExclusiveEx(p_Var5,2);
        }
      }
      else {
        if (p_Var5 != (_SPI_RESOURCE *)0x0) {
          ExReleasePushLockExclusiveEx(p_Var5,2);
        }
        local_110[0] = 0;
        local_110[1] = 0x4c;
        local_110[2] = 0;
        local_110[3] = 0;
        local_130 = local_120;
        local_108 = local_98;
        uVar6 = RESOURCE_HUB_STRING_PRINTF
                          ((ushort *)local_c8,0x22,(ushort *)L"%0*I64x",(__uint64 *)0x10);
        if (-1 < (int)uVar6) {
          uVar6 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                            (local_110,(ushort *)L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_c8);
        }
        if ((int)uVar6 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x12,
                                &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x12,(char)uVar6)
            ;
          }
          if ((uVar6 != 0xc000009a) && (uVar6 != 0xc0000017)) {
            uVar6 = (int)uVar6 >> 0x1f & 0xc0000001;
          }
        }
        else {
          local_c8[0] = 0x30;
          local_b8 = local_110;
          local_c8[1] = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_b0 = 0x200;
          uVar8 = PsGetHostSilo();
          uVar8 = PsAttachSiloToCurrentThread(uVar8);
          local_130 = 0;
          local_f8 = 0;
          uStack_f0 = 0;
          uVar6 = ZwCreateFile(&local_130,0xc0000000,local_c8,&local_f8);
          PsDetachSiloFromCurrentThread(uVar8);
          if ((int)uVar6 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDdi
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                         &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x39,(char)uVar6,
                         (char)local_120);
            }
            if (local_130 != 0) {
              ZwClose();
              local_130 = 0;
            }
          }
          else {
            uVar8 = 0xc0000000;
            uVar6 = ObReferenceObjectByHandleWithTag
                              (local_130,0xc0000000,*(undefined8 *)IoFileObjectType_exref,0);
            if ((int)uVar6 < 0) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDdq
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,1,0x14,
                           &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x49,(char)uVar6,
                           (char)local_130);
              }
              if ((uVar6 != 0xc000009a) && (uVar6 != 0xc0000017)) {
                uVar6 = (int)uVar6 >> 0x1f & 0xc0000001;
              }
              if (local_130 != 0) {
                ZwClose();
                local_130 = 0;
              }
            }
            else {
              if (local_130 != 0) {
                ZwClose();
              }
              uVar6 = RHP_CONTROLLER::spbInitializeFileObjectForForwarding
                                (param_3,(_FILE_OBJECT *)0x0);
              if (-1 < (int)uVar6) {
                if (*(longlong *)(lVar7 + 8) != 0) {
                  ObfDereferenceObjectWithTag(*(longlong *)(lVar7 + 8),0x36504852);
                }
                *(undefined8 *)(lVar7 + 8) = 0;
                *(_SPI_RESOURCE **)(lVar7 + 0x10) = local_128;
                *(longlong *)(lVar7 + 0x18) = local_120;
                uVar2 = *(undefined4 *)(pbVar10 + 4);
                uVar3 = *(undefined4 *)(pbVar10 + 8);
                uVar4 = *(undefined4 *)(pbVar10 + 0xc);
                *(undefined4 *)(lVar7 + 0x20) = *(undefined4 *)pbVar10;
                *(undefined4 *)(lVar7 + 0x24) = uVar2;
                *(undefined4 *)(lVar7 + 0x28) = uVar3;
                *(undefined4 *)(lVar7 + 0x2c) = uVar4;
                uVar6 = 0;
                goto LAB_1c00099e9;
              }
              if ((uVar6 != 0xc000009a) && (uVar6 != 0xc0000017)) {
                uVar6 = (int)uVar6 >> 0x1f & 0xc0000001;
              }
            }
          }
        }
        RHP_DEVICE::RemoveResourceHubRecord(*(RHP_DEVICE **)(this + 8),(_LARGE_INTEGER *)&local_120)
        ;
      }
      ReleaseResource(this,*(ushort *)(local_128 + 8));
      goto LAB_1c00099e9;
    }
  }
LAB_1c00094a7:
  uVar6 = 0xc000000d;
LAB_1c00099e9:
  ExReleasePushLockExclusiveEx(lVar7,2);
  return uVar6;
}



===== rtlAvlResourceCompareRoutine @ 1c0009a30 =====

/* private: static enum _RTL_GENERIC_COMPARE_RESULTS __cdecl
   RHP_SPI_CONTROLLER::rtlAvlResourceCompareRoutine(struct _RTL_AVL_TABLE * __ptr64,void *
   __ptr64,void * __ptr64) */

_RTL_GENERIC_COMPARE_RESULTS __cdecl
RHP_SPI_CONTROLLER::rtlAvlResourceCompareRoutine
          (_RTL_AVL_TABLE *param_1,void *param_2,void *param_3)

{
  if ((param_2 != (void *)0x0) && (param_3 != (void *)0x0)) {
    if (*(ushort *)((longlong)param_2 + 8) < *(ushort *)((longlong)param_3 + 8)) {
      return 0;
    }
    if (*(ushort *)((longlong)param_3 + 8) < *(ushort *)((longlong)param_2 + 8)) {
      return 1;
    }
  }
  return 2;
}



===== WPP_RECORDER_SF_sDDDq @ 1c0009a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDDq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x25d;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,0x22,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2c,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,0x22,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2c,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDqqDDD @ 1c0009bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDqqDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined4 local_28 [4];
  
  local_28[0] = 0x43;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,10,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2c,local_28,4,
               &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,4,
               &uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,10,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2c,local_28,4,
                  &uStack0000000000000040,8,&uStack0000000000000048,8,&uStack0000000000000050,4,
                  &uStack0000000000000058,4,&uStack0000000000000060,4,0);
  return;
}



===== EvtIoDeviceControl @ 1c0009d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_I2C_CONTROLLER::EvtIoDeviceControl(struct WDFQUEUE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned long) __ptr64 */

void __thiscall
RHP_I2C_CONTROLLER::EvtIoDeviceControl
          (RHP_I2C_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,
          __uint64 param_4,ulong param_5)

{
  long lVar1;
  WDFFILEOBJECT__ *pWVar2;
  RHP_I2C_CONTROLLER *this_00;
  
  this_00 = WdfDriverGlobals;
  pWVar2 = (WDFFILEOBJECT__ *)(**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
  if (pWVar2 == (WDFFILEOBJECT__ *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                 &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x3a,(char)this,(char)param_2);
    }
    lVar1 = -0x3fffff1b;
    goto LAB_1c0009e7b;
  }
  if (param_5 == 0x41808) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this_00 = *(RHP_I2C_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDs(this_00,2,3,0xb,&WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x50,
                          "!\"IOCTL_SPB_EXECUTE_SEQUENCE should have been forwarded by WdmIrpPreprocess\""
                         );
    }
    _RhpLogDebug((uint)this_00);
  }
  else {
    if (param_5 == 0x224320) {
      lVar1 = ioctlRhproxyI2CGetConnectionSettings(this_00,param_2,pWVar2);
      goto LAB_1c0009e7b;
    }
    if (param_5 == 0x228324) {
      lVar1 = ioctlRhproxyI2CSetConnectionSettings(this,param_1,param_2,pWVar2);
      goto LAB_1c0009e7b;
    }
  }
  lVar1 = -0x3fffff45;
LAB_1c0009e7b:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== ioctlRhproxyI2CGetConnectionSettings @ 1c0009eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_I2C_CONTROLLER::ioctlRhproxyI2CGetConnectionSettings(struct
   WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

long __thiscall
RHP_I2C_CONTROLLER::ioctlRhproxyI2CGetConnectionSettings
          (RHP_I2C_CONTROLLER *this,WDFREQUEST__ *param_1,WDFFILEOBJECT__ *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  RHP_I2C_CONTROLLER *pRVar5;
  uint uVar6;
  uint uVar7;
  RHP_I2C_CONTROLLER *local_res8;
  undefined8 local_res20;
  
  local_res8 = this;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,
                     PTR__WDF__RHP_I2C_CONTROLLER_I2C_RESOURCE_TYPE_INFO_1c0010140);
  ExAcquirePushLockSharedEx(lVar4,2);
  uVar6 = 0;
  if (*(longlong *)(lVar4 + 8) == 0) {
    uVar6 = 0xc0000184;
  }
  else {
    local_res20 = 0;
    local_res8 = (RHP_I2C_CONTROLLER *)0x0;
    pRVar5 = (RHP_I2C_CONTROLLER *)0x0;
    uVar7 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_1,0x10,&local_res8,&local_res20);
    if ((int)uVar7 < 0) {
      if ((((uVar7 == 0xc0000023) || (uVar7 == 0xc00000e5)) || (uVar7 == 0xc000009a)) ||
         ((uVar7 == 0xc0000017 || (uVar7 = (int)uVar7 >> 0x1f & 0xc0000001, (int)uVar7 < 0)))) {
        uVar6 = uVar7;
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x19,
                              &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x69,(char)uVar6);
        }
        goto LAB_1c000a011;
      }
    }
    else {
      pRVar5 = local_res8;
    }
    uVar1 = *(undefined4 *)(lVar4 + 0x14);
    uVar2 = *(undefined4 *)(lVar4 + 0x18);
    uVar3 = *(undefined4 *)(lVar4 + 0x1c);
    *(undefined4 *)pRVar5 = *(undefined4 *)(lVar4 + 0x10);
    *(undefined4 *)(pRVar5 + 4) = uVar1;
    *(undefined4 *)(pRVar5 + 8) = uVar2;
    *(undefined4 *)(pRVar5 + 0xc) = uVar3;
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_1,0x10);
  }
LAB_1c000a011:
  ExReleasePushLockSharedEx(lVar4,2);
  return uVar6;
}



===== ioctlRhproxyI2CSetConnectionSettings @ 1c000a044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c000a768) */
/* WARNING: Removing unreachable block (ram,0x0001c000a67f) */
/* WARNING: Removing unreachable block (ram,0x0001c000a7d2) */
/* WARNING: Removing unreachable block (ram,0x0001c000a65a) */
/* WARNING: Removing unreachable block (ram,0x0001c000a82c) */
/* private: long __cdecl RHP_I2C_CONTROLLER::ioctlRhproxyI2CSetConnectionSettings(struct WDFQUEUE__
   * __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

long __thiscall
RHP_I2C_CONTROLLER::ioctlRhproxyI2CSetConnectionSettings
          (RHP_I2C_CONTROLLER *this,WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  short sVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  ushort uVar11;
  RHP_I2C_CONTROLLER *pRVar12;
  ulonglong uVar13;
  _RHPROXY_I2C_CONNECTION_SETTINGS *p_Var14;
  undefined1 auStackY_1c8 [32];
  undefined8 local_160;
  longlong local_158;
  _RHPROXY_I2C_CONNECTION_SETTINGS *local_150;
  undefined4 local_148;
  undefined4 uStack_144;
  short local_140 [4];
  undefined1 *local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  short *local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined2 local_d0;
  undefined8 local_ce;
  undefined4 local_c6;
  undefined2 local_c2;
  __uint64 local_c0 [5];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_3,
                     PTR__WDF__RHP_I2C_CONTROLLER_I2C_RESOURCE_TYPE_INFO_1c0010140);
  ExAcquirePushLockExclusiveEx(lVar9,2);
  if (*(longlong *)(lVar9 + 8) != 0) {
    uVar8 = 0xc0000184;
    goto LAB_1c000a894;
  }
  p_Var14 = (_RHPROXY_I2C_CONNECTION_SETTINGS *)0x0;
  local_130 = 0;
  local_150 = (_RHPROXY_I2C_CONNECTION_SETTINGS *)0x0;
  pRVar12 = WdfDriverGlobals;
  uVar8 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_150);
  if ((int)uVar8 < 0) {
    if ((((uVar8 == 0xc0000023) || (uVar8 == 0xc00000e5)) || (uVar8 == 0xc000009a)) ||
       ((uVar8 == 0xc0000017 || (uVar8 = (int)uVar8 >> 0x1f & 0xc0000001, (int)uVar8 < 0)))) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                            &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xaa,(char)uVar8);
      }
      goto LAB_1c000a894;
    }
  }
  else {
    p_Var14 = local_150;
  }
  bVar6 = isConnectionSettingsValid(pRVar12,p_Var14);
  if (bVar6) {
    uVar11 = *(ushort *)p_Var14 + 0x80;
    if (*(int *)(p_Var14 + 4) != 1) {
      uVar11 = *(ushort *)p_Var14;
    }
    uVar13 = (ulonglong)uVar11;
    uVar8 = (uint)uVar11;
    if (*(int *)(p_Var14 + 0xc) == 1) {
      LOCK();
      pRVar12 = this + uVar13 * 2 + 0x30;
      sVar1 = *(short *)pRVar12;
      *(short *)pRVar12 = *(short *)pRVar12 + 1;
      UNLOCK();
      if ((ushort)(sVar1 + 1U) < 0x8001) goto LAB_1c000a266;
      LOCK();
      *(short *)(this + uVar13 * 2 + 0x30) = *(short *)(this + uVar13 * 2 + 0x30) + -1;
      UNLOCK();
    }
    else {
      sVar7 = 0;
      LOCK();
      sVar1 = *(short *)(this + uVar13 * 2 + 0x30);
      if (sVar1 == 0) {
        *(short *)(this + uVar13 * 2 + 0x30) = -0x8000;
      }
      else {
        sVar7 = sVar1;
      }
      UNLOCK();
      if (sVar7 == 0) {
LAB_1c000a266:
        local_d8 = *(undefined8 *)(this + 0x18);
        local_d0 = 0xffff;
        local_160 = 0;
        local_ce = 0;
        local_c6 = 0;
        local_c2 = 0;
        local_e0 = 1;
        local_dc = 3;
        iVar2 = *(int *)(p_Var14 + 8);
        if (iVar2 == 0) {
          local_ce = 0x186a00000;
        }
        else {
          if (iVar2 != 1) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
              WPP_RECORDER_SF_sDd(uVar10,2,3,0x14,&WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xe2,
                                  (char)iVar2);
              uVar8 = (uint)uVar10;
            }
            _RhpLogDebug(uVar8);
            uVar11 = *(ushort *)p_Var14 + 0x80;
            if (*(int *)(p_Var14 + 4) != 1) {
              uVar11 = *(ushort *)p_Var14;
            }
            if (*(int *)(p_Var14 + 0xc) == 1) {
              LOCK();
              *(short *)(this + (ulonglong)uVar11 * 2 + 0x30) =
                   *(short *)(this + (ulonglong)uVar11 * 2 + 0x30) + -1;
              UNLOCK();
            }
            else {
              LOCK();
              *(ushort *)(this + (ulonglong)uVar11 * 2 + 0x30) =
                   *(ushort *)(this + (ulonglong)uVar11 * 2 + 0x30) & 0x7fff;
              UNLOCK();
            }
            goto LAB_1c000a1ad;
          }
          local_ce = 0x61a800000;
        }
        local_ce = CONCAT26(*(undefined2 *)p_Var14,(undefined6)local_ce);
        if (*(int *)(p_Var14 + 4) != 0) {
          local_ce = CONCAT62((int6)((ulonglong)local_ce >> 0x10),1);
        }
        ExAcquirePushLockExclusiveEx(this + 0x20,0);
        uVar8 = RHP_DEVICE::InsertResourceHubRecord
                          (*(RHP_DEVICE **)(this + 8),
                           (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_e0,
                           (_LARGE_INTEGER *)&local_160);
        ExReleasePushLockExclusiveEx(this + 0x20,0);
        if ((int)uVar8 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                                &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xf3,(char)uVar8)
            ;
          }
          if ((uVar8 != 0xc000009a) && (uVar8 != 0xc0000017)) {
            uVar8 = (int)uVar8 >> 0x1f & 0xc0000001;
          }
        }
        else {
          local_138 = local_98;
          local_140[0] = 0;
          local_140[1] = 0x4c;
          local_140[2] = 0;
          local_140[3] = 0;
          local_148 = (undefined4)local_160;
          uStack_144 = local_160._4_4_;
          uVar8 = RESOURCE_HUB_STRING_PRINTF
                            ((ushort *)local_c0,0x22,(ushort *)L"%0*I64x",(__uint64 *)0x10);
          if (-1 < (int)uVar8) {
            uVar8 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                              (local_140,(ushort *)L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_c0);
          }
          if ((int)uVar8 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x16,
                                  &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",5,(char)uVar8);
            }
            if ((uVar8 != 0xc000009a) && (uVar8 != 0xc0000017)) {
              uVar8 = (int)uVar8 >> 0x1f & 0xc0000001;
            }
          }
          else {
            local_128 = 0x30;
            local_118 = local_140;
            local_120 = 0;
            local_108 = 0;
            uStack_100 = 0;
            local_110 = 0x200;
            uVar10 = PsGetHostSilo();
            uVar10 = PsAttachSiloToCurrentThread(uVar10);
            local_158 = 0;
            local_f0 = 0;
            uStack_e8 = 0;
            uVar8 = ZwCreateFile(&local_158,0xc0000000,&local_128,&local_f0);
            PsDetachSiloFromCurrentThread(uVar10);
            if ((int)uVar8 < 0) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDdi
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x17,
                           &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x2c,(char)uVar8,
                           (char)local_160);
              }
              if (local_158 != 0) {
                ZwClose();
                local_158 = 0;
              }
            }
            else {
              uVar10 = 0xc0000000;
              uVar8 = ObReferenceObjectByHandleWithTag
                                (local_158,0xc0000000,*(undefined8 *)IoFileObjectType_exref,0);
              if ((int)uVar8 < 0) {
                if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDdq
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,1,0x18,
                             &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x3c,(char)uVar8,
                             (char)local_158);
                }
                if ((uVar8 != 0xc000009a) && (uVar8 != 0xc0000017)) {
                  uVar8 = (int)uVar8 >> 0x1f & 0xc0000001;
                }
                if (local_158 != 0) {
                  ZwClose();
                  local_158 = 0;
                }
              }
              else {
                if (local_158 != 0) {
                  ZwClose();
                }
                uVar8 = RHP_CONTROLLER::spbInitializeFileObjectForForwarding
                                  (param_3,(_FILE_OBJECT *)0x0);
                if (-1 < (int)uVar8) {
                  if (*(longlong *)(lVar9 + 8) != 0) {
                    ObfDereferenceObjectWithTag(*(longlong *)(lVar9 + 8),0x35504852);
                  }
                  *(undefined8 *)(lVar9 + 8) = 0;
                  uVar3 = *(undefined4 *)(p_Var14 + 4);
                  uVar4 = *(undefined4 *)(p_Var14 + 8);
                  uVar5 = *(undefined4 *)(p_Var14 + 0xc);
                  *(undefined4 *)(lVar9 + 0x10) = *(undefined4 *)p_Var14;
                  *(undefined4 *)(lVar9 + 0x14) = uVar3;
                  *(undefined4 *)(lVar9 + 0x18) = uVar4;
                  *(undefined4 *)(lVar9 + 0x1c) = uVar5;
                  *(undefined8 *)(lVar9 + 0x20) = local_160;
                  uVar8 = 0;
                  goto LAB_1c000a894;
                }
                if ((uVar8 != 0xc000009a) && (uVar8 != 0xc0000017)) {
                  uVar8 = (int)uVar8 >> 0x1f & 0xc0000001;
                }
              }
            }
          }
          RHP_DEVICE::RemoveResourceHubRecord
                    (*(RHP_DEVICE **)(this + 8),(_LARGE_INTEGER *)&local_160);
        }
        uVar11 = *(ushort *)p_Var14 + 0x80;
        if (*(int *)(p_Var14 + 4) != 1) {
          uVar11 = *(ushort *)p_Var14;
        }
        if (*(int *)(p_Var14 + 0xc) == 1) {
          LOCK();
          *(short *)(this + (ulonglong)uVar11 * 2 + 0x30) =
               *(short *)(this + (ulonglong)uVar11 * 2 + 0x30) + -1;
          UNLOCK();
        }
        else {
          LOCK();
          *(ushort *)(this + (ulonglong)uVar11 * 2 + 0x30) =
               *(ushort *)(this + (ulonglong)uVar11 * 2 + 0x30) & 0x7fff;
          UNLOCK();
        }
        goto LAB_1c000a894;
      }
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x13,
                         &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xbf);
    }
    uVar8 = 0xc0000043;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x12,
                         &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xb2);
    }
LAB_1c000a1ad:
    uVar8 = 0xc000000d;
  }
LAB_1c000a894:
  ExReleasePushLockExclusiveEx(lVar9,2);
  return uVar8;
}



===== isConnectionSettingsValid @ 1c000a8dc =====

/* private: bool __cdecl RHP_I2C_CONTROLLER::isConnectionSettingsValid(struct
   _RHPROXY_I2C_CONNECTION_SETTINGS const * __ptr64) __ptr64 */

bool __thiscall
RHP_I2C_CONTROLLER::isConnectionSettingsValid
          (RHP_I2C_CONTROLLER *this,_RHPROXY_I2C_CONNECTION_SETTINGS *param_1)

{
  uint uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 == 0) {
    if (0x7f < *(ushort *)param_1) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return false;
      }
      uVar1 = (uint)*(ushort *)param_1;
      uVar2 = 0xc;
      uVar3 = 0x62;
      goto LAB_1c000a9ee;
    }
  }
  else {
    if (uVar1 != 1) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return false;
      }
      uVar2 = 0xe;
      uVar3 = 0x71;
      goto LAB_1c000a9ee;
    }
    if (0x3ff < *(ushort *)param_1) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return false;
      }
      uVar1 = (uint)*(ushort *)param_1;
      uVar2 = 0xd;
      uVar3 = 0x6a;
      goto LAB_1c000a9ee;
    }
  }
  uVar1 = *(uint *)(param_1 + 8);
  if ((uVar1 == 0) || (uVar1 == 1)) {
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 == 0) || (uVar1 == 1)) {
      return true;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar2 = 0x10;
    uVar3 = 0x87;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return false;
    }
    uVar2 = 0xf;
    uVar3 = 0x7c;
  }
LAB_1c000a9ee:
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,uVar2,
                      &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                      "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",uVar3,(char)uVar1);
  return false;
}



===== WPP_RECORDER_SF_sDLLq @ 1c000aa30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDLLq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x18c;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,0x1a,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x2c,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,0x1a,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x2c,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== EvtDeviceWdmIrpPreprocess @ 1c000ab80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl RHP_UART_CONTROLLER::EvtDeviceWdmIrpPreprocess(struct WDFDEVICE__ *
   __ptr64,struct _IRP * __ptr64) __ptr64 */

long __thiscall
RHP_UART_CONTROLLER::EvtDeviceWdmIrpPreprocess
          (RHP_UART_CONTROLLER *this,WDFDEVICE__ *param_1,_IRP *param_2)

{
  char cVar1;
  uint uVar2;
  _FILE_OBJECT *p_Var3;
  int iVar4;
  long lVar5;
  _DEVICE_OBJECT *p_Var6;
  char *pcVar7;
  bool bVar8;
  
  pcVar7 = *(char **)(param_2 + 0xb8);
  cVar1 = *pcVar7;
  if ((cVar1 == '\x03') || (cVar1 == '\x04')) goto LAB_1c000ac56;
  if (cVar1 == '\x0e') {
    uVar2 = *(uint *)(pcVar7 + 0x18);
    if (uVar2 < 0x1b0051) {
      if (uVar2 != 0x1b0050) {
        if (uVar2 < 0x1b0029) {
          if (uVar2 == 0x1b0028) goto LAB_1c000ac56;
          iVar4 = uVar2 - 0x1b0004;
          bVar8 = iVar4 == 0;
        }
        else {
          iVar4 = uVar2 - 0x1b002c;
          bVar8 = iVar4 == 0;
        }
LAB_1c000abd6:
        if (((!bVar8) && (iVar4 != 4)) && (iVar4 != 8)) {
          iVar4 = iVar4 + -0xc;
LAB_1c000ac15:
          if ((((iVar4 != 0) && (iVar4 != 4)) &&
              ((iVar4 != 8 && ((iVar4 != 0xc && (iVar4 != 0x10)))))) && (iVar4 != 0x14))
          goto LAB_1c000ac2b;
        }
      }
    }
    else if (uVar2 < 0x1b0079) {
      if (uVar2 != 0x1b0078) {
        iVar4 = uVar2 - 0x1b0054;
        bVar8 = iVar4 == 0;
        goto LAB_1c000abd6;
      }
    }
    else if ((uVar2 != 0x1b007c) && (uVar2 != 0x1b0080)) {
      iVar4 = uVar2 - 0x1b008c;
      goto LAB_1c000ac15;
    }
LAB_1c000ac56:
    p_Var3 = *(_FILE_OBJECT **)(*(longlong *)(*(longlong *)(pcVar7 + 0x30) + 0x18) + 0x18);
    p_Var6 = (_DEVICE_OBJECT *)IoGetRelatedDeviceObject(p_Var3);
    lVar5 = RHP_CONTROLLER::forwardIrpToRemoteTarget(param_2,p_Var6,p_Var3,SUB81(pcVar7,0));
  }
  else {
LAB_1c000ac2b:
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(char **)(param_2 + 0xb8) = pcVar7 + 0x48;
    lVar5 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals);
  }
  return lVar5;
}



===== WPP_RECORDER_SF_sDDLq @ 1c000ac94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDDLq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0x84;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3ff870efb3283585501589514d8bb436_Traceguids,10,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x2d,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_3ff870efb3283585501589514d8bb436_Traceguids,10,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,4,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_sDdqqq @ 1c000ade4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDdqqq(undefined8 param_1)

{
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0x193;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_3ff870efb3283585501589514d8bb436_Traceguids,0x16,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x2d,local_18,4,
               &uStack0000000000000040,4,&uStack0000000000000048,8,&uStack0000000000000050,8,
               &uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_3ff870efb3283585501589514d8bb436_Traceguids,0x16,
                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x2d,local_18,4,
                  &uStack0000000000000040,4,&uStack0000000000000048,8,&uStack0000000000000050,8,
                  &uStack0000000000000058,8,0);
  return;
}



===== FxStubDriverUnloadCommon @ 1c000af5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0010258 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0010258 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c000afb5:
      if (ppvVar1 == (void **)0x0) goto LAB_1c000b00b;
      if (ppvVar2 <= ppvVar1) goto LAB_1c000b023;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c000afb5;
LAB_1c000b00b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c000b023:
  WdfVersionUnbind(&DAT_1c00103f0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c000b060 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c000b094 =====

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
    _DAT_1c00103f0 = 0x2080000;
    _DAT_1c00103f8 = &DAT_1c0010420;
    RtlCopyUnicodeString(&DAT_1c00103f0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c00103f0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((longlong)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0010628 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c00103f0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0010258 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c000b220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0010628 != (code *)0x0) && (DAT_1c0010628 != FxStubDriverUnload)) {
    (*DAT_1c0010628)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c000b254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000b279) */
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
    if ((void **)0x1c001024f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0010258 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000b3dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000b3f9) */
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
    if ((void **)0x1c001026f < ppvVar2) break;
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



===== __GSHandlerCheck @ 1c000b4a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000b4cc =====

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



===== __cpu_features_init @ 1c000b540 =====

/* WARNING: Removing unreachable block (ram,0x0001c000b5aa) */
/* WARNING: Removing unreachable block (ram,0x0001c000b559) */
/* WARNING: Removing unreachable block (ram,0x0001c000b54a) */

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



===== __security_check_cookie @ 1c000b610 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c000b650 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000b680 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000b680. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000b6b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c000b700 =====

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



===== memset @ 1c000ba00 =====

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



===== __memset_repmovs @ 1c000bb40 =====

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



===== __memset_query @ 1c000bbc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000bc40 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c000bd80 =====

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



===== __memset_spec_plain @ 1c000be00 =====

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



===== RhpSendIoctlSynchronously @ 1c0013008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl RhpSendIoctlSynchronously(struct WDFIOTARGET__ * __ptr64,unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned __int64 * __ptr64) */

long __cdecl
RhpSendIoctlSynchronously
          (WDFIOTARGET__ *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,
          ulong param_6,__uint64 *param_7)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  ulonglong local_38;
  void *pvStack_30;
  ulonglong local_28;
  ulonglong local_20;
  void *pvStack_18;
  ulonglong local_10;
  
  pvVar1 = param_5;
  local_10 = 0;
  pvStack_18 = (void *)0x0;
  if (param_3 != (void *)0x0) {
    local_10 = (ulonglong)param_4;
    pvStack_18 = param_3;
  }
  local_20 = (ulonglong)(param_3 != (void *)0x0);
  pvVar3 = (void *)(ulonglong)param_6;
  local_28 = 0;
  pvStack_30 = (void *)0x0;
  if (param_5 != (void *)0x0) {
    pvStack_30 = param_5;
    local_28 = (ulonglong)param_6;
  }
  local_38 = (ulonglong)(param_5 != (void *)0x0);
  param_5 = (void *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                    (WdfDriverGlobals,param_1,0,param_2,
                     -(ulonglong)(param_3 != (void *)0x0) & (ulonglong)&local_20,
                     -(ulonglong)(pvVar1 != (void *)0x0) & (ulonglong)&local_38,0,&param_5);
  if ((-1 < iVar2) && (pvVar1 != (void *)0x0)) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      if (param_5 <= pvVar3) goto LAB_1c0013146;
      WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,10,
                          &WPP_9dcfb038d853353fc15f0d5242a06649_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcommon.cpp",0x3e,
                          "bytesReturned <= OutputBufferSize");
    }
    if (pvVar3 < param_5) {
                    /* WARNING: Subroutine does not return */
      _RhpLogBugcheck();
    }
  }
LAB_1c0013146:
  if (param_7 != (__uint64 *)0x0) {
    *param_7 = (__uint64)param_5;
  }
  return iVar2;
}



===== RHP_DRIVER @ 1c0013180 =====

/* private: __cdecl RHP_DRIVER::RHP_DRIVER(struct WDFDRIVER__ * __ptr64,struct _UNICODE_STRING const
   * __ptr64) __ptr64 */

RHP_DRIVER * __thiscall
RHP_DRIVER::RHP_DRIVER(RHP_DRIVER *this,WDFDRIVER__ *param_1,_UNICODE_STRING *param_2)

{
  *(WDFDRIVER__ **)(this + 8) = param_1;
  *(undefined4 *)this = 0x52504852;
  return this;
}



===== ~RHP_DRIVER @ 1c0013198 =====

/* private: __cdecl RHP_DRIVER::~RHP_DRIVER(void) __ptr64 */

void __thiscall RHP_DRIVER::~RHP_DRIVER(RHP_DRIVER *this)

{
  *(undefined4 *)this = 0;
  return;
}



===== evtDriverUnload @ 1c00131b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DRIVER::evtDriverUnload(struct WDFDRIVER__ * __ptr64) */

void __cdecl RHP_DRIVER::evtDriverUnload(WDFDRIVER__ *param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar2 = WPP_GLOBAL_Control;
    if ((int)WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
        }
      }
    }
    else if ((int)WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,uVar1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = &WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1c0013280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if ((int)WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if ((int)WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c001335c =====

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
  WPPTraceSuite._0_4_ = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite._0_4_ = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 1c00134a0 =====

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
          bVar13 = (int)WPPTraceSuite != 2;
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



===== RHP_DEVICE @ 1c0013728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: __cdecl RHP_DEVICE::RHP_DEVICE(struct WDFDEVICE__ * __ptr64) __ptr64 */

RHP_DEVICE * __thiscall RHP_DEVICE::RHP_DEVICE(RHP_DEVICE *this,WDFDEVICE__ *param_1)

{
  RHP_DEVICE *pRVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined2 uVar6;
  undefined1 auStackY_1a8 [32];
  undefined1 uVar7;
  undefined1 uVar8;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  code *pcStack_120;
  code *local_118;
  undefined4 local_f8;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_b8;
  undefined4 local_b4;
  wchar_t *local_b0;
  undefined4 local_a8;
  undefined4 local_9c;
  undefined4 local_98;
  wchar_t local_58 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  pRVar1 = this + 0x18;
  *(undefined4 *)this = 0x65706872;
  *(undefined8 *)pRVar1 = 0;
  *(WDFDEVICE__ **)(this + 8) = param_1;
  _CONTROLLER_REGISTRY::_CONTROLLER_REGISTRY((_CONTROLLER_REGISTRY *)(this + 0x20));
  memset(&local_148,0,0x60);
  local_f8 = 0xffffffff;
  pcStack_120 = evtIoDeviceControl;
  local_118 = evtIoInternalDeviceControl;
  uStack_140 = CONCAT44(uStack_140._4_4_,2);
  uVar2 = uStack_140;
  uStack_140._0_6_ = CONCAT15(1,(int5)uVar2);
  local_148 = 0x200000060;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                    (WdfDriverGlobals,*(undefined8 *)(this + 8),&local_148,0);
  puVar5 = (undefined *)(ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return this;
    }
    uVar8 = (undefined1)*(undefined8 *)(this + 8);
    uVar6 = 0x3d;
    uVar7 = 0x52;
LAB_1c0013832:
    WPP_RECORDER_SF_sDqdq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,uVar6,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar7,(char)this,(char)uVar3,
               uVar8);
  }
  else {
    local_128 = *(undefined8 *)(this + 8);
    builtin_wcsncpy(local_58 + 0x10,L"_HUB",5);
    builtin_wcsncpy(local_58,L"\\Device\\RESOURCE",0x10);
    local_118 = (code *)0x0;
    local_138 = 0;
    uStack_140 = 0;
    local_148 = 0x38;
    pcStack_120 = (code *)0x0;
    uStack_130 = 0x100000001;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,local_128,&local_148,pRVar1);
    if (iVar4 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return this;
      }
      uVar6 = 0x3e;
      uVar8 = (undefined1)*(undefined8 *)(this + 8);
      uVar7 = 0x6c;
    }
    else {
      memset(&local_e8,0,0x88);
      local_b4 = 0;
      local_b0 = local_58;
      local_e8 = 0x88;
      local_e4 = 2;
      local_b8 = 0x2a0028;
      local_a8 = 0x1f0000;
      local_98 = 0x40;
      local_9c = 1;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x540))
                        (WdfDriverGlobals,*(undefined8 *)pRVar1,&local_e8);
      if (-1 < iVar4) {
        puVar5 = &GUID_DEVINTERFACE_RHPROXY;
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x268))
                          (WdfDriverGlobals,*(undefined8 *)(this + 8),&GUID_DEVINTERFACE_RHPROXY,0);
        if (-1 < (int)uVar3) {
          *(undefined4 *)this = 0x45504852;
          return this;
        }
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return this;
        }
        uVar8 = (undefined1)*(undefined8 *)(this + 8);
        uVar6 = 0x40;
        uVar7 = 0x8c;
        goto LAB_1c0013832;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return this;
      }
      uVar6 = 0x3f;
      uVar8 = (undefined1)*(undefined8 *)(this + 8);
      uVar7 = 0x7e;
    }
    WPP_RECORDER_SF_sDqqL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
               &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar7,(char)this,uVar8,
               (char)iVar4);
  }
  return this;
}



===== ~RHP_DEVICE @ 1c0013a98 =====

/* private: __cdecl RHP_DEVICE::~RHP_DEVICE(void) __ptr64 */

void __thiscall RHP_DEVICE::~RHP_DEVICE(RHP_DEVICE *this)

{
  *(undefined4 *)this = 0;
  _CONTROLLER_REGISTRY::~_CONTROLLER_REGISTRY((_CONTROLLER_REGISTRY *)(this + 0x20));
  return;
}



===== CreateDeviceInterface @ 1c0013ab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl RHP_DEVICE::CreateDeviceInterface(void * __ptr64,struct _GUID const &
   __ptr64,unsigned long) __ptr64 */

long __thiscall
RHP_DEVICE::CreateDeviceInterface(RHP_DEVICE *this,void *param_1,_GUID *param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 local_res8 [8];
  longlong local_res10;
  undefined8 in_stack_ffffffffffffff78;
  longlong lVar7;
  undefined4 uVar8;
  undefined8 in_stack_ffffffffffffff80;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined8 local_48;
  wchar_t *pwStack_40;
  
  uVar4 = *(undefined8 *)(this + 8);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))(WdfDriverGlobals,uVar4,param_2,param_1);
  uVar12 = SUB81(this,0);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqdqZ
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0x24,in_stack_ffffffffffffff78,
                 in_stack_ffffffffffffff80,0xea,uVar12,(char)iVar1,(char)param_2,param_1);
    }
    if (iVar1 == -0x3fffff66) {
      return -0x3fffff66;
    }
    if (iVar1 == -0x3fffffe9) {
      return -0x3fffffe9;
    }
    return iVar1 >> 0x1f & 0xc0000001;
  }
  local_res10 = 0;
  uVar4 = 0;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_res10);
  if ((int)uVar5 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0013be6;
    uVar11 = 0xf7;
    uVar6 = 0x25;
  }
  else {
    uVar4 = *(undefined8 *)(this + 8);
    uVar3 = WdfDriverGlobals;
    lVar7 = local_res10;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x278))(WdfDriverGlobals,uVar4,param_2,param_1);
    uVar2 = (uint)uVar3;
    if ((int)uVar5 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDqdqZ
                  (uVar3,uVar4,3,0x26,lVar7,in_stack_ffffffffffffff80,6,uVar12,(char)uVar5,
                   (char)param_2,param_1);
        uVar2 = (uint)uVar3;
      }
      _RhpLogDebug(uVar2);
      goto LAB_1c0013be6;
    }
    local_48 = 0;
    pwStack_40 = (wchar_t *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x9a8))(WdfDriverGlobals,local_res10);
    uVar8 = (undefined4)((ulonglong)lVar7 >> 0x20);
    uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar10 = 1;
      uVar8 = 1;
      WPP_RECORDER_SF_sDS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x27,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xf,pwStack_40);
    }
    if ((param_3 & 1) != 0) {
      uVar9 = CONCAT44(uVar10,*(ushort *)param_1 + 2);
      uVar4 = 0;
      uVar3 = CONCAT44(uVar8,0x12);
      uVar5 = IoSetDeviceInterfacePropertyData
                        (&local_48,&DEVPKEY_DeviceInterface_Serial_PortName,0,0,uVar3,uVar9,
                         *(undefined8 *)((longlong)param_1 + 8));
      uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
      uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
      if ((int)uVar5 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
        goto LAB_1c0013be6;
        uVar6 = 0x28;
        uVar11 = 0x1e;
        goto LAB_1c0013bca;
      }
    }
    if ((param_3 & 2) != 0) {
      uVar9 = CONCAT44(uVar10,*(ushort *)param_1 + 2);
      uVar4 = 0;
      uVar3 = CONCAT44(uVar8,0x12);
      uVar5 = IoSetDeviceInterfacePropertyData
                        (&local_48,&DEVPKEY_DeviceInterface_Spb_FriendlyName,0,0,uVar3,uVar9,
                         *(undefined8 *)((longlong)param_1 + 8));
      uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
      uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
      if ((int)uVar5 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
        goto LAB_1c0013be6;
        uVar6 = 0x29;
        uVar11 = 0x30;
        goto LAB_1c0013bca;
      }
    }
    if ((param_3 & 4) == 0) {
LAB_1c0013e78:
      if (local_res10 != 0) {
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
      }
      return 0;
    }
    local_res8[0] = 0;
    uVar4 = 0;
    uVar5 = IoSetDeviceInterfacePropertyData
                      (&local_48,&DEVPKEY_DeviceInterface_Restricted,0,0,CONCAT44(uVar8,0x11),
                       CONCAT44(uVar10,1),local_res8);
    if (-1 < (int)uVar5) goto LAB_1c0013e78;
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0013be6;
    uVar6 = 0x2a;
    uVar11 = 0x49;
  }
LAB_1c0013bca:
  WPP_RECORDER_SF_sDqD
            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar6,
             &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar11,uVar12,(char)uVar5);
LAB_1c0013be6:
  if ((uVar5 != 0xc000009a) && (uVar5 != 0xc0000017)) {
    uVar5 = (int)uVar5 >> 0x1f & 0xc0000001;
  }
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return uVar5;
}



===== EvtDriverDeviceAdd @ 1c0013ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl RHP_DEVICE::EvtDriverDeviceAdd(struct WDFDRIVER__ * __ptr64,struct
   WDFDEVICE_INIT * __ptr64) */

long __cdecl RHP_DEVICE::EvtDriverDeviceAdd(WDFDRIVER__ *param_1,WDFDEVICE_INIT *param_2)

{
  int iVar1;
  RHP_DEVICE *this;
  int *piVar2;
  undefined2 uVar3;
  WDFDEVICE_INIT *local_res10;
  WDFDEVICE__ *local_res18;
  undefined8 in_stack_fffffffffffffee0;
  uint uVar5;
  ulonglong uVar4;
  undefined1 uVar6;
  undefined8 local_e8;
  code *local_e0;
  code *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined4 local_a8 [10];
  code *local_80;
  code *local_78;
  
  uVar5 = (uint)((ulonglong)in_stack_fffffffffffffee0 >> 0x20);
  local_res10 = param_2;
  RHP_DRIVER::GetFromWdfObject(param_1,true);
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals);
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  memset(local_a8,0,0x90);
  local_80 = evtDevicePrepareHardware;
  local_78 = evtDeviceReleaseHardware;
  local_a8[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,local_a8);
  (**(code **)(WdfFunctions_01015 + 0x250))(WdfDriverGlobals,local_res10,evtIoInCallerContext);
  uVar4 = (ulonglong)uVar5 << 0x20;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,evtDeviceWdmIrpPreprocess,4,0,uVar4);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0x1b;
    uVar6 = 0x9d;
  }
  else {
    uVar4 = uVar4 & 0xffffffff00000000;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_res10,evtDeviceWdmIrpPreprocess,3,0,uVar4);
    if (iVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x1c;
      uVar6 = 0xaa;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                        (WdfDriverGlobals,local_res10,evtDeviceWdmIrpPreprocess,0xe,0,
                         uVar4 & 0xffffffff00000000);
      if (-1 < iVar1) {
        local_e0 = evtDeviceFileCreate;
        local_e8 = 0x28;
        local_d8 = evtFileClose;
        local_d0 = 0;
        local_c8 = 0x400000002;
        (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_e8,0);
        local_b8 = PTR__WDF_RHP_DEVICE_TYPE_INFO_1c0010078;
        local_res18 = (WDFDEVICE__ *)0x0;
        local_e0 = evtCleanupCallback;
        local_e8 = 0x38;
        local_d8 = evtDestroyCallback;
        local_c8 = 0;
        uStack_c0 = 0;
        local_d0 = 0x100000002;
        iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                          (WdfDriverGlobals,&local_res10,&local_e8,&local_res18);
        if (iVar1 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1e,
                                &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xde,
                                (char)iVar1);
          }
        }
        else {
          this = (RHP_DEVICE *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,local_res18,PTR__WDF_RHP_DEVICE_TYPE_INFO_1c0010078);
          piVar2 = (int *)RHP_DEVICE(this,local_res18);
          if ((piVar2 != (int *)0x0) && (*piVar2 == 0x45504852)) {
            return 0;
          }
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                       &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xe9,(char)piVar2,
                       (char)local_res18);
          }
        }
        return -0x3fffffff;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x1d;
      uVar6 = 0xb7;
    }
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                      &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                      "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar6,(char)iVar1);
  return iVar1;
}



===== InitRhBufferForAllocation @ 1c00142c8 =====

/* public: static void __cdecl RHP_DEVICE::InitRhBufferForAllocation(union _LARGE_INTEGER const &
   __ptr64,enum _RH_CONNECTION_PROPERTIES_INPUT_TYPE,struct
   _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER * __ptr64) */

void __cdecl
RHP_DEVICE::InitRhBufferForAllocation
          (_LARGE_INTEGER *param_1,_RH_CONNECTION_PROPERTIES_INPUT_TYPE param_2,
          _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *param_3)

{
  int iVar1;
  undefined8 uVar2;
  _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *p_Var3;
  _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *p_Var4;
  
  uVar2 = *(undefined8 *)param_1;
  p_Var4 = (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)0x0;
  *(ulonglong *)param_3 = CONCAT44(param_2,1);
  *(undefined8 *)(param_3 + 8) = 0;
  *(undefined8 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 0x18) = 0;
  iVar1 = *(int *)(param_3 + 4);
  if ((iVar1 == 0) || ((iVar1 != 1 && (((iVar1 == 2 || (iVar1 == 3)) || (iVar1 == 4)))))) {
    p_Var3 = param_3 + 8;
  }
  else {
    p_Var3 = (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)0x0;
  }
  *(undefined8 *)p_Var3 = uVar2;
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      p_Var4 = param_3 + 0xc;
      goto LAB_1c001434d;
    }
    if (((iVar1 != 2) && (iVar1 != 3)) && (iVar1 != 4)) goto LAB_1c001434d;
  }
  p_Var4 = param_3 + 0x10;
LAB_1c001434d:
  *(undefined2 *)p_Var4 = 0xffff;
  if (param_2 == 2) {
    *(undefined4 *)(param_3 + 0x14) = 0xffffffff;
    *(undefined4 *)(param_3 + 0x18) = 0xffffffff;
  }
  else {
    if (param_2 != 3) {
      return;
    }
    *(undefined4 *)(param_3 + 0x14) = 0xffffffff;
    *(undefined2 *)(param_3 + 0x18) = 0xffff;
  }
  *(undefined2 *)(param_3 + 0x12) = 0xffff;
  return;
}



===== InsertResourceHubRecord @ 1c0014390 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_DEVICE::InsertResourceHubRecord(struct
   _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER const * __ptr64,union _LARGE_INTEGER * __ptr64)
   __ptr64 */

long __thiscall
RHP_DEVICE::InsertResourceHubRecord
          (RHP_DEVICE *this,_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *param_1,
          _LARGE_INTEGER *param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  WDFIOTARGET__ *pWVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined1 auStackY_d8 [32];
  undefined8 *puVar10;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar11;
  undefined1 uVar12;
  __uint64 local_88;
  _LARGE_INTEGER *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar5 = *(uint *)(param_1 + 4);
  uVar4 = uVar5;
  local_80 = param_2;
  if ((uVar5 == 0) || (uVar4 = 0, uVar5 == 1)) {
LAB_1c00146e6:
    lVar3 = -0x3fffff1b;
LAB_1c00146eb:
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDdq
                (uVar8,param_1,3,0x2b,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x81,(char)lVar3,
                 (char)param_1);
      uVar4 = (uint)uVar8;
    }
    _RhpLogDebug(uVar4);
  }
  else {
    uVar4 = uVar5 - 2;
    if (uVar4 == 0) {
      uVar1 = *(ushort *)(param_1 + 0x12);
      uVar4 = (uint)uVar1;
      if ((uVar1 == 0) && (*(int *)(param_1 + 0x14) == 0)) {
        if ((param_1[0x18] != (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0x0) ||
           ((param_1[0x19] != (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0x0 ||
            (param_1[0x1a] != (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0x0))))
        goto LAB_1c001440b;
        if (param_1[0x1b] == (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0x0) goto LAB_1c0014540;
      }
      if ((((*(int *)(param_1 + 0x14) == -1) && (uVar1 == 0xffff)) &&
          (param_1[0x18] == (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0xff)) &&
         ((param_1[0x19] == (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0xff &&
          (param_1[0x1a] == (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0xff)))) {
        bVar9 = param_1[0x1b] == (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER)0xff;
LAB_1c001453a:
        if (bVar9) {
LAB_1c0014540:
          lVar3 = -0x3ffffff3;
          goto LAB_1c00146eb;
        }
      }
    }
    else {
      if (uVar4 != 1) goto LAB_1c00146e6;
      uVar1 = *(ushort *)(param_1 + 0x12);
      uVar4 = (uint)uVar1;
      if (uVar1 == 0) {
        if ((*(int *)(param_1 + 0x14) == 0) && (*(short *)(param_1 + 0x18) == 0))
        goto LAB_1c0014540;
      }
      else if ((uVar1 == 0xffff) && (*(int *)(param_1 + 0x14) == -1)) {
        bVar9 = *(short *)(param_1 + 0x18) == -1;
        goto LAB_1c001453a;
      }
    }
LAB_1c001440b:
    local_88 = *(__uint64 *)(param_1 + 8);
    uVar12 = (undefined1)local_88;
    if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      uVar11 = 1;
      WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x2c,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x8b,uVar12);
    }
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    InitRhBufferForAllocation
              ((_LARGE_INTEGER *)&local_88,*(_RH_CONNECTION_PROPERTIES_INPUT_TYPE *)(param_1 + 4),
               (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
    pWVar6 = *(WDFIOTARGET__ **)(this + 0x18);
    uVar8 = CONCAT44(uVar11,0x10);
    puVar10 = &local_78;
    local_88 = 0;
    uStack_70 = 0;
    local_78 = 1;
    lVar3 = RhpSendIoctlSynchronously(pWVar6,0x2ac004,&local_68,0x20,puVar10,0x10,&local_88);
    uVar5 = (uint)pWVar6;
    if (lVar3 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDdi
                  (uVar8,2,3,0x2d,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xa4,(char)lVar3,uVar12);
        uVar5 = (uint)uVar8;
      }
    }
    else {
      if (local_88 == 0x10) {
        iVar2 = *(int *)(param_1 + 4);
        local_68 = *(undefined8 *)param_1;
        uStack_60 = *(undefined8 *)(param_1 + 8);
        puVar7 = (undefined8 *)0x0;
        local_58 = *(undefined8 *)(param_1 + 0x10);
        uStack_50 = *(undefined8 *)(param_1 + 0x18);
        if ((iVar2 == 0) || ((iVar2 != 1 && (((iVar2 == 2 || (iVar2 == 3)) || (iVar2 == 4)))))) {
          puVar7 = &uStack_60;
        }
        *puVar7 = uStack_70;
        lVar3 = UpdateResourceHubRecord
                          (this,(_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
        if (lVar3 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDii
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2f,puVar10,uVar8,0xc0,uVar12
                       ,(char)uStack_70);
          }
          RemoveResourceHubRecord(this,(_LARGE_INTEGER *)&uStack_70);
          return lVar3;
        }
        if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_sDii
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x30,puVar10,uVar8,199,uVar12,
                     (char)uStack_70);
        }
        *(undefined8 *)local_80 = uStack_70;
        return 0;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDPd(uVar8);
        uVar5 = (uint)uVar8;
      }
      lVar3 = -0x3fffffff;
    }
    _RhpLogDebug(uVar5);
  }
  return lVar3;
}



===== ProbeSpbConnectionResource @ 1c0014774 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_DEVICE::ProbeSpbConnectionResource(union _LARGE_INTEGER const & __ptr64)
   __ptr64 */

long __thiscall RHP_DEVICE::ProbeSpbConnectionResource(RHP_DEVICE *this,_LARGE_INTEGER *param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStackY_148 [32];
  longlong local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined1 local_88 [112];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d8 = local_88;
  local_e0 = 0x6c0000;
  lVar1 = RtlUnicodeStringPrintf
                    ((_UNICODE_STRING *)&local_e0,
                     (ushort *)L"\\Device\\RESOURCE_HUB\\%0*I64x\\rhproxy",0x10,
                     *(undefined8 *)param_1);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x37,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x7a,(char)lVar1);
    }
    uVar3 = 0xc00000e5;
  }
  else {
    local_c0 = &local_e0;
    local_d0 = 0x30;
    local_b8 = 0x200;
    local_c8 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    local_e8 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    iVar2 = ZwCreateFile(&local_e8,0xc0000000,&local_d0,&local_a0);
    uVar3 = -(uint)(iVar2 != -0x3fffffcd) & 0xc0000001;
    if (local_e8 != 0) {
      ZwClose();
    }
  }
  return uVar3;
}



===== QueryResourceHubRecord @ 1c00148e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_DEVICE::QueryResourceHubRecord(union _LARGE_INTEGER const &
   __ptr64,struct _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER * __ptr64 * __ptr64,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::QueryResourceHubRecord
          (RHP_DEVICE *this,_LARGE_INTEGER *param_1,
          _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER **param_2,ulong *param_3)

{
  int iVar1;
  _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *p_Var2;
  ulong uVar3;
  
  *param_2 = (_RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *)0x0;
  *param_3 = 0;
  uVar3 = 0x54;
  while( true ) {
    p_Var2 = (_RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *)
             ExAllocatePoolWithTag(1,uVar3,0x30504852);
    if (p_Var2 == (_RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x35,
                           &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x31);
      }
      return -0x3fffffe9;
    }
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x18),0,0x2ac000);
    if (iVar1 != -0x3fffffdd) break;
    uVar3 = *(int *)(p_Var2 + 4) + 8;
    ExFreePoolWithTag(p_Var2,0x30504852);
  }
  if (-1 < iVar1) {
    *param_2 = p_Var2;
    *param_3 = uVar3;
    return iVar1;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x36,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x50,(char)iVar1);
  }
  ExFreePoolWithTag(p_Var2,0x30504852);
  return iVar1;
}



===== RegisterController @ 1c0014ae8 =====

/* public: long __cdecl RHP_DEVICE::RegisterController(struct _UNICODE_STRING const & __ptr64,class
   RHP_CONTROLLER * __ptr64,struct _GUID const & __ptr64,unsigned long) __ptr64 */

long __thiscall
RHP_DEVICE::RegisterController
          (RHP_DEVICE *this,_UNICODE_STRING *param_1,RHP_CONTROLLER *param_2,_GUID *param_3,
          ulong param_4)

{
  long lVar1;
  void *local_18 [2];
  
  local_18[0] = (void *)0x0;
  lVar1 = RegisterController(this,param_1,param_2,local_18);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x20,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x86,(char)lVar1);
    }
  }
  else {
    lVar1 = CreateDeviceInterface(this,local_18[0],param_3,param_4);
    if (-1 < lVar1) {
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x21,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x95,(char)lVar1);
    }
    _CONTROLLER_REGISTRY::Remove((_CONTROLLER_REGISTRY *)(this + 0x20),local_18[0]);
  }
  return lVar1;
}



===== RegisterController @ 1c0014c04 =====

/* public: long __cdecl RHP_DEVICE::RegisterController(struct _UNICODE_STRING const & __ptr64,class
   RHP_CONTROLLER * __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::RegisterController
          (RHP_DEVICE *this,_UNICODE_STRING *param_1,RHP_CONTROLLER *param_2,void **param_3)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = (uint)(*(ushort *)param_1 >> 1);
  uVar2 = SUB81(this,0);
  if ((((uVar1 == 0) || (*(ushort *)(param_1 + 2) >> 1 <= uVar1)) ||
      ((*(short **)(param_1 + 8))[uVar1] != 0)) || (**(short **)(param_1 + 8) == 0x5c)) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      this = *(RHP_DEVICE **)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDi(this,2,3,0x22,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xba,uVar2);
    }
    _RhpLogDebug((uint)this);
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = _CONTROLLER_REGISTRY::Add((_CONTROLLER_REGISTRY *)(this + 0x20),param_1,param_2,param_3)
    ;
    if ((int)uVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0x23,
                   &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",199,uVar2,(char)uVar1);
      }
      if ((uVar1 != 0xc000009a) && (uVar1 != 0xc0000017)) {
        uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== RemoveResourceHubRecord @ 1c0014d48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_DEVICE::RemoveResourceHubRecord(union _LARGE_INTEGER const & __ptr64)
   __ptr64 */

long __thiscall RHP_DEVICE::RemoveResourceHubRecord(RHP_DEVICE *this,_LARGE_INTEGER *param_1)

{
  long lVar1;
  uint uVar2;
  WDFIOTARGET__ *pWVar3;
  undefined8 uVar4;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x33,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xf7,
                        (char)*(undefined8 *)param_1);
  }
  local_40 = *(undefined8 *)param_1;
  pWVar3 = *(WDFIOTARGET__ **)(this + 0x18);
  local_48 = 1;
  lVar1 = RhpSendIoctlSynchronously(pWVar3,0x2ac008,&local_48,0x10,(void *)0x0,0,(__uint64 *)0x0);
  uVar2 = (uint)pWVar3;
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDdi
                (uVar4,2,3,0x34,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",6,(char)lVar1,
                 (char)*(undefined8 *)param_1);
      uVar2 = (uint)uVar4;
    }
    _RhpLogDebug(uVar2);
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



===== UpdateResourceHubRecord @ 1c0014e7c =====

/* public: long __cdecl RHP_DEVICE::UpdateResourceHubRecord(struct
   _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER const * __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::UpdateResourceHubRecord
          (RHP_DEVICE *this,_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *param_1)

{
  int iVar1;
  long lVar2;
  _RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *p_Var3;
  uint uVar4;
  WDFIOTARGET__ *pWVar5;
  undefined8 uVar6;
  
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    iVar1 = *(int *)(param_1 + 4);
    if ((iVar1 == 0) || ((iVar1 != 1 && (((iVar1 == 2 || (iVar1 == 3)) || (iVar1 == 4)))))) {
      p_Var3 = param_1 + 8;
    }
    else {
      p_Var3 = (_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)0x0;
    }
    WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x31,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xdc,
                        (char)*(undefined8 *)p_Var3);
  }
  pWVar5 = *(WDFIOTARGET__ **)(this + 0x18);
  lVar2 = RhpSendIoctlSynchronously(pWVar5,0x2ac00c,param_1,0x20,(void *)0x0,0,(__uint64 *)0x0);
  uVar4 = (uint)pWVar5;
  if (lVar2 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDd(uVar6,2,3,0x32,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xe6,(char)lVar2);
      uVar4 = (uint)uVar6;
    }
    _RhpLogDebug(uVar4);
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}



===== evtDeviceFileCreate @ 1c0014fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtDeviceFileCreate(struct WDFDEVICE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) */

void __cdecl
RHP_DEVICE::evtDeviceFileCreate(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,WDFFILEOBJECT__ *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  RHP_DEVICE *this;
  _UNICODE_STRING *p_Var3;
  RHP_CONTROLLER *pRVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *local_res20;
  undefined8 in_stack_ffffffffffffff68;
  undefined8 in_stack_ffffffffffffff70;
  undefined1 uVar9;
  _UNICODE_STRING *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  this = GetFromWdfObject(param_1,true);
  local_68 = (_UNICODE_STRING *)0x0;
  uVar7 = WdfDriverGlobals;
  p_Var3 = (_UNICODE_STRING *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_3);
  uVar6 = (uint)uVar7;
  uVar9 = SUB81(this,0);
  if (p_Var3 == (_UNICODE_STRING *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqq
                (uVar7,2,3,0x3a,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xe6,uVar9,(char)param_3);
      uVar6 = (uint)uVar7;
    }
    _RhpLogDebug(uVar6);
  }
  else {
    pRVar4 = FindController(this,p_Var3,&local_68);
    if (pRVar4 == (RHP_CONTROLLER *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqS
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x3b,in_stack_ffffffffffffff68,
                   in_stack_ffffffffffffff70,0xf2,uVar9,*(wchar_t **)(p_Var3 + 8));
      }
      uVar7 = 0xc0000225;
      goto LAB_1c001506e;
    }
    local_res20 = (undefined8 *)0x0;
    puVar8 = &local_60;
    local_50 = 0;
    local_30 = PTR__WDF__RHP_DEVICE_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010050;
    uStack_58 = 0;
    local_60 = 0x38;
    local_40 = 0;
    uStack_38 = 0;
    uStack_48 = 0x100000001;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_3,puVar8,&local_res20);
    puVar1 = local_res20;
    if (-1 < iVar2) {
      local_res20[3] = 0;
      *local_res20 = this;
      local_res20[1] = pRVar4;
      local_res20[2] = local_68;
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,param_3);
      *(undefined8 **)(lVar5 + 0x18) = puVar1;
      (**(code **)(*(longlong *)pRVar4 + 0x38))(pRVar4,param_1,param_2,param_3);
      return;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar8,0x3c,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",8,uVar9,(char)iVar2);
    }
  }
  uVar7 = 0xc0000001;
LAB_1c001506e:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar7);
  return;
}



===== evtDevicePrepareHardware @ 1c0015220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl RHP_DEVICE::evtDevicePrepareHardware(struct WDFDEVICE__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __cdecl
RHP_DEVICE::evtDevicePrepareHardware
          (WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2,WDFCMRESLIST__ *param_3)

{
  long lVar1;
  RHP_DEVICE *this;
  RHP_CONTROLLER *pRVar2;
  ulong uVar3;
  
  this = GetFromWdfObject(param_1,true);
  lVar1 = parseResources(this,param_2,param_3);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x38,
                 &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xac,(char)this,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  else {
    uVar3 = 0;
    while (pRVar2 = _CONTROLLER_REGISTRY::GetAt
                              ((_CONTROLLER_REGISTRY *)(this + 0x20),uVar3,
                               (_UNICODE_STRING **)param_3), pRVar2 != (RHP_CONTROLLER *)0x0) {
      lVar1 = (**(code **)(*(longlong *)pRVar2 + 0x30))(pRVar2);
      if (lVar1 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqqL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x39,
                     &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xba,(char)this,
                     (char)pRVar2,(char)lVar1);
        }
        break;
      }
      uVar3 = uVar3 + 1;
    }
  }
  return lVar1;
}



===== evtDeviceReleaseHardware @ 1c0015370 =====

/* private: static long __cdecl RHP_DEVICE::evtDeviceReleaseHardware(struct WDFDEVICE__ *
   __ptr64,struct WDFCMRESLIST__ * __ptr64) */

long __thiscall
RHP_DEVICE::evtDeviceReleaseHardware(RHP_DEVICE *this,WDFDEVICE__ *param_1,WDFCMRESLIST__ *param_2)

{
  return 0;
}



===== evtFileClose @ 1c0015380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_DEVICE::evtFileClose(struct WDFFILEOBJECT__ * __ptr64) */

void __cdecl RHP_DEVICE::evtFileClose(WDFFILEOBJECT__ *param_1)

{
  void *pvVar1;
  RHP_DEVICE *this;
  _FILE_OBJECT_CONTEXT *p_Var2;
  
  pvVar1 = (void *)(**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  this = GetFromWdfObject(pvVar1,true);
  p_Var2 = getFileObjectContextFromWdfObject(this,param_1);
  (**(code **)(**(longlong **)(p_Var2 + 8) + 0x40))(*(longlong **)(p_Var2 + 8),param_1);
  return;
}



===== parseConnectionResource @ 1c00153dc =====

/* private: long __cdecl RHP_DEVICE::parseConnectionResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,struct _ACPI_EVAL_OUTPUT_BUFFER_V1 const *
   __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::parseConnectionResource
          (RHP_DEVICE *this,ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_3)

{
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var1;
  long lVar2;
  undefined4 in_register_00000014;
  undefined2 uVar3;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar4;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR _Var5;
  
  p_Var1 = param_2 + 5;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDLDD
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),CONCAT44(in_register_00000014,param_1),
               param_2,0x4a,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,0x5f,(char)param_1,
               param_2[4],*p_Var1);
  }
  if (param_2[4] == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x1) {
    lVar2 = RHP_GPIO_CONTROLLER::ParseConnectionResource(0,param_2,this,param_3);
    if (-1 < lVar2) {
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x4f,
                          &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x9f,(char)lVar2);
    }
    return -0x3fffffff;
  }
  if (param_2[4] != (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x2) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    _Var5 = *p_Var1;
    uVar3 = 0x50;
    uVar4 = 0xa7;
LAB_1c001547b:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar3,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar4,_Var5);
    return 0;
  }
  _Var5 = *p_Var1;
  if (_Var5 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x1) {
    lVar2 = RHP_I2C_CONTROLLER::ParseResource(param_1,param_2,this,param_3);
    if (-1 < lVar2) {
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = 0x4b;
    uVar4 = 0x6f;
  }
  else if (_Var5 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x2) {
    lVar2 = RHP_SPI_CONTROLLER::ParseResource(param_1,param_2,this,param_3);
    if (-1 < lVar2) {
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = 0x4c;
    uVar4 = 0x7d;
  }
  else {
    if (_Var5 != (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x3) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      uVar3 = 0x4e;
      uVar4 = 0x92;
      goto LAB_1c001547b;
    }
    lVar2 = RHP_UART_CONTROLLER::ParseResource(param_1,param_2,this,param_3);
    if (-1 < lVar2) {
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar2;
    }
    uVar3 = 0x4d;
    uVar4 = 0x8b;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                      &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                      "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",uVar4,(char)lVar2);
  return lVar2;
}



===== parseInterruptResource @ 1c0015654 =====

/* private: long __cdecl RHP_DEVICE::parseInterruptResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,struct _CM_PARTIAL_RESOURCE_DESCRIPTOR const *
   __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::parseInterruptResource
          (RHP_DEVICE *this,ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,
          _CM_PARTIAL_RESOURCE_DESCRIPTOR *param_3)

{
  long lVar1;
  undefined4 in_register_00000014;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    this = *(RHP_DEVICE **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDLDD
              (this,CONCAT44(in_register_00000014,param_1),param_2,0x51,in_stack_ffffffffffffffc8,
               in_stack_ffffffffffffffd0,0xbc,(char)param_1,param_3[4],param_3[5]);
  }
  if (RHP_GPIO_CONTROLLER::singletonPtr == (RHP_GPIO_CONTROLLER *)0x0) {
    lVar1 = -0x3ffffe7e;
  }
  else {
    lVar1 = RHP_GPIO_CONTROLLER::parseInterruptResource((RHP_GPIO_CONTROLLER *)this,param_2,param_3)
    ;
    if (-1 < lVar1) {
      return 0;
    }
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x52,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xc5,(char)lVar1);
  }
  return -0x3fffffff;
}



===== parseResources @ 1c0015738 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_DEVICE::parseResources(struct WDFCMRESLIST__ * __ptr64,struct
   WDFCMRESLIST__ * __ptr64) __ptr64 */

long __thiscall
RHP_DEVICE::parseResources(RHP_DEVICE *this,WDFCMRESLIST__ *param_1,WDFCMRESLIST__ *param_2)

{
  uint uVar1;
  long lVar2;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var3;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *p_Var4;
  uint uVar5;
  RHP_DEVICE *pRVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  WDFCMRESLIST__ *pWVar10;
  undefined2 uVar11;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *local_res20;
  undefined *in_stack_ffffffffffffff88;
  char *in_stack_ffffffffffffff90;
  undefined1 uVar12;
  undefined1 uVar13;
  
  pRVar6 = WdfDriverGlobals;
  pWVar10 = param_2;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_2);
  uVar9 = (uint)pRVar6;
  uVar13 = SUB81(this,0);
  if (uVar1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDi(uVar7,2,3,0x45,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xfe,uVar13);
      uVar9 = (uint)uVar7;
    }
    _RhpLogDebug(uVar9);
  }
  else {
    local_res20 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
    lVar2 = queryAcpiDsd(*(WDFDEVICE__ **)(this + 8),&local_res20);
    if (lVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffff90 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp";
        in_stack_ffffffffffffff88 = &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids;
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pWVar10,0x46,
                   &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",10,uVar13,(char)lVar2);
      }
      local_res20 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0;
    }
    uVar9 = 0;
    if (uVar1 != 0) {
      do {
        pRVar6 = WdfDriverGlobals;
        p_Var3 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)
                 (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,uVar9);
        uVar5 = (uint)pRVar6;
        if (p_Var3 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)0x0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            WPP_RECORDER_SF_sDqLL
                      (uVar7,2,3,0x47,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0x1b,uVar13,(char)uVar9
                       ,(char)uVar1);
            uVar5 = (uint)uVar7;
          }
          _RhpLogDebug(uVar5);
          goto LAB_1c00159e9;
        }
        if (*p_Var3 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x2) {
          pRVar6 = WdfDriverGlobals;
          p_Var4 = (_CM_PARTIAL_RESOURCE_DESCRIPTOR *)
                   (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_1,uVar9);
          uVar8 = (ulonglong)uVar9;
          lVar2 = parseInterruptResource(pRVar6,uVar9,p_Var4,p_Var3);
          if (lVar2 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c00159e9;
            uVar11 = 0x49;
            uVar12 = 0x41;
LAB_1c00158e2:
            WPP_RECORDER_SF_sDqdLq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,p_Var4,uVar11,
                       in_stack_ffffffffffffff88,in_stack_ffffffffffffff90,uVar12,uVar13,(char)lVar2
                       ,(char)uVar9,(char)p_Var3);
LAB_1c00159e9:
            if (local_res20 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
              ExFreePoolWithTag(local_res20,0x30504852);
            }
            return -0x3fffffff;
          }
        }
        else if (*p_Var3 == (_CM_PARTIAL_RESOURCE_DESCRIPTOR)0x84) {
          uVar8 = (ulonglong)uVar9;
          p_Var4 = p_Var3;
          lVar2 = parseConnectionResource(this,uVar9,p_Var3,local_res20);
          if (lVar2 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c00159e9;
            uVar11 = 0x48;
            uVar12 = 0x2c;
            goto LAB_1c00158e2;
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar1);
    }
    if (local_res20 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
      ExFreePoolWithTag(local_res20,0x30504852);
    }
  }
  return 0;
}



===== queryAcpiDsd @ 1c0015a18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl RHP_DEVICE::queryAcpiDsd(struct WDFDEVICE__ * __ptr64,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 * __ptr64 * __ptr64) */

long __cdecl RHP_DEVICE::queryAcpiDsd(WDFDEVICE__ *param_1,_ACPI_EVAL_OUTPUT_BUFFER_V1 **param_2)

{
  long lVar1;
  uint uVar2;
  WDFIOTARGET__ *pWVar3;
  _ACPI_EVAL_OUTPUT_BUFFER_V1 *p_Var4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_res18;
  undefined4 local_res1c;
  __uint64 local_res20;
  
  local_res18 = 0x42696541;
  local_res1c = 0x4453445f;
  iVar7 = 2;
  uVar6 = 0x414;
  while( true ) {
    p_Var4 = (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)ExAllocatePoolWithTag(1,uVar6,0x30504852);
    if (p_Var4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x41,
                            &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xb3,(char)uVar6);
      }
      return -0x3fffffe9;
    }
    local_res20 = 0;
    pWVar3 = (WDFIOTARGET__ *)(**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    puVar8 = &local_res18;
    lVar1 = RhpSendIoctlSynchronously(pWVar3,0x32c004,puVar8,8,p_Var4,uVar6,&local_res20);
    if (lVar1 != -0x7ffffffb) break;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) goto LAB_1c0015b6d;
    uVar2 = *(uint *)(p_Var4 + 4);
    if (*(uint *)(p_Var4 + 4) < uVar6) {
      uVar2 = uVar6;
    }
    ExFreePoolWithTag(p_Var4,0x30504852);
    uVar6 = uVar2;
  }
  if (-1 < lVar1) {
    uVar2 = *(uint *)(p_Var4 + 4);
    if (uVar2 <= local_res20) {
      if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) && (uVar6 < uVar2))
      {
        WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x44,
                            &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xdb,
                            "outputBufferSize >= outputBufferPtr->Length");
      }
      if (uVar6 < *(uint *)(p_Var4 + 4)) {
                    /* WARNING: Subroutine does not return */
        _RhpLogBugcheck();
      }
      *param_2 = p_Var4;
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDLL
                (uVar5,local_res20,puVar8,0x43,&WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xd3,(char)local_res20,
                 (char)uVar2);
      uVar2 = (uint)uVar5;
    }
    _RhpLogDebug(uVar2);
    goto LAB_1c0015bc2;
  }
LAB_1c0015b6d:
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x42,
                        &WPP_12471ad0837635bdbd6e4d029783429a_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdevice.cpp",0xca,(char)lVar1);
  }
  if (p_Var4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    return -0x3fffffff;
  }
LAB_1c0015bc2:
  ExFreePoolWithTag(p_Var4,0x30504852);
  return -0x3fffffff;
}



===== ~RHP_CONTROLLER @ 1c0015cc0 =====

/* protected: virtual __cdecl RHP_CONTROLLER::~RHP_CONTROLLER(void) __ptr64 */

void __thiscall RHP_CONTROLLER::~RHP_CONTROLLER(RHP_CONTROLLER *this)

{
  *(undefined ***)this = &_vftable_;
  return;
}



===== AllocateFriendlyName @ 1c0015cd4 =====

/* public: static long __cdecl RHP_CONTROLLER::AllocateFriendlyName(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
RHP_CONTROLLER::AllocateFriendlyName(_ACPI_METHOD_ARGUMENT_V1 *param_1,_UNICODE_STRING *param_2)

{
  long lVar1;
  char *_Str;
  char *pcVar2;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var3;
  uint uVar4;
  undefined2 uVar5;
  char *local_res8;
  undefined1 uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  
  p_Var3 = param_1;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)param_1 == 1) goto LAB_1c0015d60;
    p_Var3 = *(_ACPI_METHOD_ARGUMENT_V1 **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDs(p_Var3,2,3,0x26,&WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0xce,
                        "ArgumentPtr->Type == ACPI_METHOD_ARGUMENT_STRING");
  }
  if (*(short *)param_1 != 1) {
    _RhpLogDebug((uint)p_Var3);
  }
LAB_1c0015d60:
  _Str = (char *)ExAllocatePoolWithTag(1,(ulonglong)*(ushort *)(param_1 + 2) + 1,0x30504852);
  if (_Str == (char *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x27,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0xd4);
    }
    lVar1 = -0x3fffffe9;
  }
  else {
    lVar1 = ArgumentParseString(param_1,_Str,*(ushort *)(param_1 + 2) + 1);
    if (lVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar5 = 0x28;
        uVar6 = 0xe1;
LAB_1c0015eb6:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
                            &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar6,
                            (char)lVar1);
      }
    }
    else {
      local_res8 = (char *)0x0;
      uVar4 = 1;
      lVar1 = -0x3ffffddb;
      pcVar2 = strtok_s(_Str,"-",&local_res8);
      while( true ) {
        if ((pcVar2 == (char *)0x0) || (3 < uVar4)) goto LAB_1c0015ed5;
        if (uVar4 == 3) break;
        pcVar2 = strtok_s((char *)0x0,"-",&local_res8);
        uVar4 = uVar4 + 1;
      }
      local_38 = 0;
      uStack_30 = 0;
      RtlInitAnsiString(&local_38,pcVar2);
      lVar1 = RtlAnsiStringToUnicodeString(param_2,&local_38,1);
      if ((lVar1 < 0) && ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar5 = 0x29;
        uVar6 = 0xf8;
        goto LAB_1c0015eb6;
      }
    }
LAB_1c0015ed5:
    ExFreePoolWithTag(_Str,0);
  }
  return lVar1;
}



===== ArgumentParseString @ 1c0015f10 =====

/* public: static long __cdecl RHP_CONTROLLER::ArgumentParseString(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,char * __ptr64,unsigned long) */

long __cdecl
RHP_CONTROLLER::ArgumentParseString(_ACPI_METHOD_ARGUMENT_V1 *param_1,char *param_2,ulong param_3)

{
  ushort uVar1;
  long lVar2;
  undefined4 in_register_00000084;
  
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar1 < param_3) {
    memcpy(param_2,param_1 + 4,(ulonglong)uVar1);
    param_2[param_3 - 1] = '\0';
    lVar2 = 0;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,
                 CONCAT44(in_register_00000084,param_3),0x2f,
                 &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x7c,(char)param_3,
                 (char)uVar1);
    }
    lVar2 = -0x3fffffdd;
  }
  return lVar2;
}



===== ArgumentParseUlong @ 1c0015fa8 =====

/* public: static long __cdecl RHP_CONTROLLER::ArgumentParseUlong(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,unsigned long * __ptr64) */

long __cdecl RHP_CONTROLLER::ArgumentParseUlong(_ACPI_METHOD_ARGUMENT_V1 *param_1,ulong *param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (*(short *)param_1 == 0) {
    *param_2 = *(ulong *)(param_1 + 4);
    lVar1 = 0;
  }
  else {
    uVar2 = 0xc0010000;
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDd(uVar3,2,3,0x30,&WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x92,
                          (char)*(short *)param_1);
      uVar2 = (uint)uVar3;
    }
    _RhpLogDebug(uVar2);
    lVar1 = -0x3febfff8;
  }
  return lVar1;
}



===== CompareAsciiUnicode @ 1c0016024 =====

/* public: static bool __cdecl RHP_CONTROLLER::CompareAsciiUnicode(char const * __ptr64,struct
   _UNICODE_STRING const & __ptr64) */

bool __cdecl RHP_CONTROLLER::CompareAsciiUnicode(char *param_1,_UNICODE_STRING *param_2)

{
  char cVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitAnsiString(&local_18,param_1);
  local_28 = 0;
  uStack_20 = 0;
  cVar1 = '\0';
  iVar2 = RtlAnsiStringToUnicodeString(&local_28,&local_18,1);
  if (-1 < iVar2) {
    cVar1 = RtlEqualUnicodeString(&local_28,param_2,1);
    RtlFreeUnicodeString(&local_28);
  }
  return cVar1 != '\0';
}



===== EvtDeviceFileCreate @ 1c00160c0 =====

/* public: virtual void __cdecl RHP_CONTROLLER::EvtDeviceFileCreate(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
RHP_CONTROLLER::EvtDeviceFileCreate
          (RHP_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,WDFFILEOBJECT__ *param_3)

{
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0xf,
                       &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x2f);
  }
                    /* WARNING: Subroutine does not return */
  _RhpLogBugcheck();
}



===== EvtFileClose @ 1c0016120 =====

/* public: virtual void __cdecl RHP_CONTROLLER::EvtFileClose(struct WDFFILEOBJECT__ * __ptr64)
   __ptr64 */

void __thiscall RHP_CONTROLLER::EvtFileClose(RHP_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x10,
                       &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x3a);
  }
                    /* WARNING: Subroutine does not return */
  _RhpLogBugcheck();
}



===== IsArgumentMatchToken @ 1c001617c =====

/* public: static long __cdecl RHP_CONTROLLER::IsArgumentMatchToken(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,struct _UNICODE_STRING const & __ptr64,struct _UNICODE_STRING const &
   __ptr64,unsigned long,bool * __ptr64) */

long __cdecl
RHP_CONTROLLER::IsArgumentMatchToken
          (_ACPI_METHOD_ARGUMENT_V1 *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3,
          ulong param_4,bool *param_5)

{
  short sVar1;
  bool *pbVar2;
  bool bVar3;
  long lVar4;
  char *_Str;
  char *pcVar5;
  uint uVar6;
  
  pbVar2 = param_5;
  sVar1 = *(short *)param_1;
  *param_5 = false;
  if (sVar1 == 1) {
    _Str = (char *)ExAllocatePoolWithTag(1,(ulonglong)*(ushort *)(param_1 + 2) + 1,0x30504852);
    if (_Str == (char *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x21,
                           &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x65);
      }
      return -0x3fffffe9;
    }
    lVar4 = ArgumentParseString(param_1,_Str,*(ushort *)(param_1 + 2) + 1);
    if (lVar4 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x22,
                            &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x72,
                            (char)lVar4);
      }
      ExFreePoolWithTag(_Str,0);
      return lVar4;
    }
    param_5 = (bool *)0x0;
    uVar6 = 1;
    pcVar5 = strtok_s(_Str,"-",&param_5);
    if (pcVar5 != (char *)0x0) {
      do {
        if (((param_4 + 1 < uVar6) ||
            ((uVar6 == 1 && (bVar3 = CompareAsciiUnicode(pcVar5,param_2), !bVar3)))) ||
           ((uVar6 == 2 && (bVar3 = CompareAsciiUnicode(pcVar5,param_3), !bVar3)))) break;
        if (uVar6 == param_4) {
          *pbVar2 = true;
        }
        else if (param_4 < uVar6) {
          *pbVar2 = false;
          break;
        }
        pcVar5 = strtok_s((char *)0x0,"-",&param_5);
        uVar6 = uVar6 + 1;
      } while (pcVar5 != (char *)0x0);
    }
    ExFreePoolWithTag(_Str,0);
  }
  else if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x20,
                        &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x5b,(char)sVar1);
  }
  return 0;
}



===== LookForMatchingResource @ 1c00163dc =====

/* public: static long __cdecl RHP_CONTROLLER::LookForMatchingResource(struct
   _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64,unsigned long) */

long __cdecl
RHP_CONTROLLER::LookForMatchingResource(_ACPI_METHOD_ARGUMENT_V1 *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  ulonglong uVar4;
  byte bVar5;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var6;
  undefined2 uVar7;
  ulong local_res8 [2];
  undefined1 uVar8;
  
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar1 < 8) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x23,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x9a);
    }
    lVar3 = -0x3febfff1;
  }
  else {
    for (p_Var6 = param_1 + 4; p_Var6 < param_1 + (ulonglong)uVar1 + 4; p_Var6 = p_Var6 + uVar4 + 4)
    {
      if (*(ushort *)p_Var6 != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar2 = (uint)*(ushort *)p_Var6;
        uVar7 = 0x24;
        uVar8 = 0xaf;
        bVar5 = 4;
LAB_1c0016506:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,1,uVar7,
                            &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar8,
                            (char)uVar2);
        return -0x3ffffff3;
      }
      local_res8[0] = 0;
      uVar2 = ArgumentParseUlong(p_Var6,local_res8);
      if ((int)uVar2 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffff3;
        }
        uVar7 = 0x25;
        uVar8 = 0xb8;
        bVar5 = 2;
        goto LAB_1c0016506;
      }
      if (param_2 == local_res8[0]) {
        return 0;
      }
      uVar4 = (ulonglong)*(ushort *)(p_Var6 + 2);
      if (*(ushort *)(p_Var6 + 2) < 4) {
        uVar4 = 4;
      }
    }
    lVar3 = -0x3ffffddb;
  }
  return lVar3;
}



===== ParsePropertyUlong @ 1c0016544 =====

/* public: static long __cdecl RHP_CONTROLLER::ParsePropertyUlong(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,struct _UNICODE_STRING const & __ptr64,struct _UNICODE_STRING const &
   __ptr64,unsigned long * __ptr64) */

long __cdecl
RHP_CONTROLLER::ParsePropertyUlong
          (_ACPI_METHOD_ARGUMENT_V1 *param_1,_UNICODE_STRING *param_2,_UNICODE_STRING *param_3,
          ulong *param_4)

{
  long lVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  _ACPI_METHOD_ARGUMENT_V1 *local_18 [2];
  
  local_18[0] = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
  lVar1 = RetrieveArgumentWithMatchingToken
                    (param_1,(_ACPI_METHOD_ARGUMENT_V1 *)0x0,param_2,param_3,2,local_18);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00166d1;
    uVar3 = 0x2a;
    uVar4 = 0x20;
LAB_1c00165a4:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                        &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar4,(char)lVar1)
    ;
  }
  else {
    uVar2 = (ulonglong)*(ushort *)(local_18[0] + 6);
    if (param_1 + (ulonglong)*(ushort *)(param_1 + 2) + 4 < local_18[0] + uVar2 + 8) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = 0x2b;
        uVar4 = 0x28;
LAB_1c001665b:
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                           &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar4);
      }
    }
    else {
      if (*(ushort *)(local_18[0] + 6) < 4) {
        uVar2 = 4;
      }
      if (local_18[0] + (ulonglong)*(ushort *)(local_18[0] + uVar2 + 10) + uVar2 + 0xc <=
          param_1 + (ulonglong)*(ushort *)(param_1 + 2) + 4) {
        lVar1 = ArgumentParseUlong(local_18[0] + uVar2 + 8,param_4);
        if (-1 < lVar1) {
          return 0;
        }
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
        goto LAB_1c00166d1;
        uVar3 = 0x2d;
        uVar4 = 0x37;
        goto LAB_1c00165a4;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = 0x2c;
        uVar4 = 0x2f;
        goto LAB_1c001665b;
      }
    }
    lVar1 = -0x3febfff5;
  }
LAB_1c00166d1:
  return lVar1;
}



===== RetrieveArgumentWithMatchingToken @ 1c00166e8 =====

/* public: static long __cdecl RHP_CONTROLLER::RetrieveArgumentWithMatchingToken(struct
   _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64,struct _ACPI_METHOD_ARGUMENT_V1 __unaligned *
   __ptr64,struct _UNICODE_STRING const & __ptr64,struct _UNICODE_STRING const & __ptr64,unsigned
   long,struct _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64 * __ptr64) */

long __cdecl
RHP_CONTROLLER::RetrieveArgumentWithMatchingToken
          (_ACPI_METHOD_ARGUMENT_V1 *param_1,_ACPI_METHOD_ARGUMENT_V1 *param_2,
          _UNICODE_STRING *param_3,_UNICODE_STRING *param_4,ulong param_5,
          _ACPI_METHOD_ARGUMENT_V1 **param_6)

{
  ushort uVar1;
  short sVar2;
  _ACPI_METHOD_ARGUMENT_V1 **pp_Var3;
  long lVar4;
  ulonglong uVar5;
  
  pp_Var3 = param_6;
  uVar1 = *(ushort *)(param_1 + 2);
  *param_6 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
  if (uVar1 < 8) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1b,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",8);
    }
    lVar4 = -0x3febfff1;
  }
  else {
    if (param_2 == (_ACPI_METHOD_ARGUMENT_V1 *)0x0) {
      param_2 = param_1 + 4;
    }
    for (; param_2 < param_1 + (ulonglong)uVar1 + 4; param_2 = param_2 + uVar5 + 4) {
      if (*(short *)param_2 == 3) {
        if (*(ushort *)(param_2 + 2) < 8) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                               &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x24);
          }
          return -0x3febfff5;
        }
        sVar2 = *(short *)(param_2 + 4);
        if (sVar2 == 1) {
          param_6._0_1_ = '\0';
          lVar4 = IsArgumentMatchToken(param_2 + 4,param_3,param_4,param_5,(bool *)&param_6);
          if (lVar4 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
                                  &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x3c,
                                  (char)lVar4);
            }
            return lVar4;
          }
          if ((char)param_6 != '\0') {
            *pp_Var3 = param_2;
            return 0;
          }
        }
        else if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1e,
                              &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x2e,
                              (char)sVar2);
        }
      }
      else if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
                            &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x1f,
                            (char)*(short *)param_2);
      }
      uVar5 = (ulonglong)*(ushort *)(param_2 + 2);
      if (*(ushort *)(param_2 + 2) < 4) {
        uVar5 = 4;
      }
    }
    lVar4 = -0x3ffffddb;
  }
  return lVar4;
}



===== RetrieveBusFriendlyName @ 1c001697c =====

/* public: static long __cdecl RHP_CONTROLLER::RetrieveBusFriendlyName(struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64,unsigned long,struct _UNICODE_STRING const &
   __ptr64,struct _UNICODE_STRING * __ptr64) */

long __cdecl
RHP_CONTROLLER::RetrieveBusFriendlyName
          (_ACPI_EVAL_OUTPUT_BUFFER_V1 *param_1,ulong param_2,_UNICODE_STRING *param_3,
          _UNICODE_STRING *param_4)

{
  _ACPI_METHOD_ARGUMENT_V1 *p_Var1;
  long lVar2;
  ulonglong uVar3;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var4;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var5;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var6;
  undefined2 uVar7;
  _ACPI_METHOD_ARGUMENT_V1 *local_res8;
  undefined1 uVar8;
  
  if (*(int *)param_1 == 0x426f6541) {
    if (*(int *)(param_1 + 8) == 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x16;
        uVar8 = 0x8f;
LAB_1c0016c01:
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                           &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar8);
      }
LAB_1c0016c31:
      lVar2 = -0x3febfff5;
    }
    else {
      local_res8 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
      lVar2 = RetrieveDsdArguments
                        ((_ACPI_METHOD_ARGUMENT_V1 *)(param_1 + 0xc),*(int *)(param_1 + 4) - 0xc,
                         &local_res8);
      p_Var1 = local_res8;
      if (lVar2 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x17,
                              &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x9b,
                              (char)lVar2);
        }
      }
      else if (*(ushort *)(local_res8 + 2) < 8) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x18,
                             &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0xb6);
        }
        lVar2 = -0x3febfff1;
      }
      else {
        p_Var5 = local_res8 + (ulonglong)*(ushort *)(local_res8 + 2) + 4;
        for (p_Var4 = local_res8 + 4; p_Var4 < p_Var5; p_Var4 = p_Var4 + uVar3 + 4) {
          local_res8 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
          lVar2 = RetrieveArgumentWithMatchingToken
                            (p_Var1,p_Var4,(_UNICODE_STRING *)&DAT_1c000d1c0,param_3,3,&local_res8);
          if (-1 < lVar2) {
            if (*(ushort *)(local_res8 + 2) < 8) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0016c31;
              uVar7 = 0x19;
              uVar8 = 0xd7;
              goto LAB_1c0016c01;
            }
            p_Var6 = local_res8 + 4;
            if (*(ushort *)(local_res8 + 6) < 8) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_1c0016c31;
              uVar7 = 0x1a;
              uVar8 = 0xe1;
              goto LAB_1c0016c01;
            }
            lVar2 = LookForMatchingResource
                              (p_Var6 + (ulonglong)*(ushort *)(local_res8 + 6) + 4,param_2);
            if (-1 < lVar2) {
              lVar2 = AllocateFriendlyName(p_Var6,param_4);
              return lVar2;
            }
          }
          uVar3 = (ulonglong)*(ushort *)(p_Var4 + 2);
          if (*(ushort *)(p_Var4 + 2) < 4) {
            uVar3 = 4;
          }
        }
        lVar2 = -0x3ffffddb;
      }
    }
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x8a);
    }
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== RetrieveDsdArguments @ 1c0016c44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_CONTROLLER::RetrieveDsdArguments(struct _ACPI_METHOD_ARGUMENT_V1
   __unaligned * __ptr64,unsigned long,struct _ACPI_METHOD_ARGUMENT_V1 __unaligned * __ptr64 *
   __ptr64) */

long __cdecl
RHP_CONTROLLER::RetrieveDsdArguments
          (_ACPI_METHOD_ARGUMENT_V1 *param_1,ulong param_2,_ACPI_METHOD_ARGUMENT_V1 **param_3)

{
  ushort uVar1;
  long lVar2;
  ulonglong uVar3;
  byte bVar4;
  _ACPI_METHOD_ARGUMENT_V1 **pp_Var5;
  undefined2 uVar6;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var7;
  undefined1 auStackY_98 [32];
  undefined1 uVar8;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  if (param_2 < 8) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x11;
      uVar8 = 0x48;
LAB_1c0016e54:
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",uVar8);
    }
LAB_1c0016e76:
    lVar2 = -0x3febfff8;
  }
  else {
    bVar4 = 0;
    *param_3 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
    p_Var7 = param_1 + param_2;
    pp_Var5 = param_3;
    while( true ) {
      uVar1 = *(ushort *)(param_1 + 2);
      uVar3 = (ulonglong)uVar1;
      if (p_Var7 < param_1 + uVar3 + 4) break;
      if (((bool)(bVar4 & 1)) || (*(short *)param_1 != 2)) {
        if (uVar1 < 4) {
          uVar3 = 4;
        }
      }
      else {
        local_48 = 0;
        uStack_40 = 0;
        if (uVar1 != 0x10) {
          if (((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
             (WPP_RECORDER_SF_sDDD
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0x10,pp_Var5,0x2e,
                         &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x65,0x10,
                         (char)uVar1),
             (undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_1c0016e76;
          uVar6 = 0x12;
          uVar8 = 0x60;
          goto LAB_1c0016e54;
        }
        pp_Var5 = (_ACPI_METHOD_ARGUMENT_V1 **)0x10;
        memcpy(&local_48,param_1 + 4,0x10);
        if (((((int)local_48 == -0x250027ec) && (local_48._4_4_ == 0x4d8c6eba)) &&
            ((int)uStack_40 == -0x64436e76)) && (uStack_40._4_4_ == 0x1a34abf)) {
          if (p_Var7 < param_1 + (ulonglong)*(ushort *)(param_1 + 0x16) + 0x18) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                                 &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0x6e);
            }
            return -0x3febfff5;
          }
          if (*(short *)(param_1 + 0x14) == 3) {
            *param_3 = param_1 + 0x14;
            return 0;
          }
          if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0016e76;
          uVar6 = 0x14;
          uVar8 = 0x73;
          goto LAB_1c0016e54;
        }
      }
      param_1 = param_1 + uVar3 + 4;
      bVar4 = bVar4 + 1;
    }
    lVar2 = -0x3ffffddb;
  }
  return lVar2;
}



===== spbInitializeFileObjectForForwarding @ 1c0016eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: static long __cdecl RHP_CONTROLLER::spbInitializeFileObjectForForwarding(struct
   WDFFILEOBJECT__ * __ptr64,struct _FILE_OBJECT * __ptr64) */

long __cdecl
RHP_CONTROLLER::spbInitializeFileObjectForForwarding(WDFFILEOBJECT__ *param_1,_FILE_OBJECT *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,uVar2);
  uVar4 = IoGetRelatedDeviceObject(param_2);
  uVar5 = 0;
  uVar2 = uVar4;
  iVar1 = IoAdjustStackSizeForRedirection(uVar3);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDdqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,uVar5,0x31,
                 &WPP_25e05209bd953885408f2a09a4feac37_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpcontroller.cpp",0xcf,(char)iVar1,
                 (char)uVar3,(char)uVar4);
    }
  }
  else {
    RHP_DEVICE::EnableControllerWdmIrpPreprocess(param_1,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



===== RHP_GPIO_CONTROLLER @ 1c0016fc0 =====

/* private: __cdecl RHP_GPIO_CONTROLLER::RHP_GPIO_CONTROLLER(class RHP_DEVICE * __ptr64) __ptr64 */

RHP_GPIO_CONTROLLER * __thiscall
RHP_GPIO_CONTROLLER::RHP_GPIO_CONTROLLER(RHP_GPIO_CONTROLLER *this,RHP_DEVICE *param_1)

{
  *(RHP_DEVICE **)(this + 8) = param_1;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
  *(undefined4 *)(this + 0x10) = 1;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  this[0x28] = (RHP_GPIO_CONTROLLER)0x0;
  *(undefined2 *)(this + 0x2a) = 0;
  *(undefined4 *)(this + 0x2c) = 9;
  *(undefined8 *)(this + 0x30) = 0;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (singletonPtr == (RHP_GPIO_CONTROLLER *)0x0) {
      singletonPtr = this;
      return this;
    }
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x32,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xec,
                        "!this->singletonPtr");
  }
  if (singletonPtr != (RHP_GPIO_CONTROLLER *)0x0) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  singletonPtr = this;
  return this;
}



===== _PIN_DESCRIPTOR @ 1c0017098 =====

/* public: __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::_PIN_DESCRIPTOR(void) __ptr64 */

_PIN_DESCRIPTOR * __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::_PIN_DESCRIPTOR(_PIN_DESCRIPTOR *this)

{
  *(undefined8 *)(this + 0x78) = 0xffffffffffffffff;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x80) = 0xffffffff;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined2 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8a) = 0xffff;
  *(undefined2 *)(this + 0x8e) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  return this;
}



===== ~RHP_GPIO_CONTROLLER @ 1c0017128 =====

/* private: virtual __cdecl RHP_GPIO_CONTROLLER::~RHP_GPIO_CONTROLLER(void) __ptr64 */

void __thiscall RHP_GPIO_CONTROLLER::~RHP_GPIO_CONTROLLER(RHP_GPIO_CONTROLLER *this)

{
  *(undefined ***)this = &_vftable_;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (singletonPtr == this) goto LAB_1c00171a5;
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x33,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xf5,
                        "this->singletonPtr == this");
  }
  if (singletonPtr != this) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
LAB_1c00171a5:
  singletonPtr = (RHP_GPIO_CONTROLLER *)0x0;
  _PIN_DESCRIPTOR_INDEX::~_PIN_DESCRIPTOR_INDEX((_PIN_DESCRIPTOR_INDEX *)(this + 0x18));
  *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
  return;
}



===== ~_PIN_DESCRIPTOR_INDEX @ 1c00171d4 =====

/* public: __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::~_PIN_DESCRIPTOR_INDEX(void) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::~_PIN_DESCRIPTOR_INDEX(_PIN_DESCRIPTOR_INDEX *this)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  RHP_DRIVER *this_00;
  
  lVar2 = *(longlong *)(this + 8);
  if (lVar2 != 0) {
    plVar1 = (longlong *)(lVar2 + -8);
    lVar3 = *plVar1;
    this_00 = (RHP_DRIVER *)(lVar3 * 0x98 + lVar2);
    for (; lVar3 != 0; lVar3 = lVar3 + -1) {
      this_00 = this_00 + -0x98;
      RHP_DRIVER::evtCleanupCallback(this_00);
    }
    if (plVar1 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar1,0);
    }
  }
  return;
}



===== CompleteDevicePrepareHardware @ 1c0017250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl RHP_GPIO_CONTROLLER::CompleteDevicePrepareHardware(void) __ptr64 */

long __thiscall RHP_GPIO_CONTROLLER::CompleteDevicePrepareHardware(RHP_GPIO_CONTROLLER *this)

{
  long lVar1;
  int iVar2;
  _PIN_DESCRIPTOR *this_00;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  int iVar7;
  ushort uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
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
  code *local_60;
  
  uVar4 = 0;
  if (*(ushort *)(this + 0x1a) != 0) {
    do {
      uVar3 = (uint)uVar4;
      if ((*(longlong *)(uVar4 * 0x98 + 0x78 + *(longlong *)(this + 0x20)) == -1) ||
         (*(int *)(uVar4 * 0x98 + 0x80 + *(longlong *)(this + 0x20)) == -1)) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          WPP_RECORDER_SF_sDqLi(uVar5);
          uVar3 = (uint)uVar5;
        }
        _RhpLogDebug(uVar3);
        lVar1 = -0x3ffffe7e;
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffe7e;
        }
        uVar10 = 0x82;
        uVar6 = 0x20;
        uVar9 = 0x25;
        goto LAB_1c0017392;
      }
      uVar4 = (ulonglong)(uVar3 + 1);
    } while (uVar3 + 1 < (uint)*(ushort *)(this + 0x1a));
  }
  iVar7 = 0;
  uVar8 = 0;
  if (*(short *)(this + 0x1a) != 0) {
    do {
      this_00 = _PIN_DESCRIPTOR_INDEX::operator[]((_PIN_DESCRIPTOR_INDEX *)(this + 0x18),uVar8);
      lVar1 = createWdfIoTarget(this,this_00);
      if (lVar1 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdqHLi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        memset(&local_88,0,0x60);
        local_88 = 0x60;
        local_b8 = 0;
        local_80 = 2;
        local_60 = evtWaitInterruptBufferIoDeviceControl;
        local_84 = 1;
        local_98 = 0;
        uStack_c0 = 0;
        local_c8 = 0x38;
        local_a8 = 0;
        uStack_a0 = 0;
        uStack_b0 = 0x400000002;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(this + 8) + 8),&local_88,
                           &local_c8,this_00 + 0x70);
        if (iVar2 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x22,
                                &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x5a,(char)iVar2
                               );
          }
          _PIN_DESCRIPTOR::deleteWdfIoTarget(this_00);
          return iVar2;
        }
        iVar7 = iVar7 + 1;
        _PIN_DESCRIPTOR::deleteWdfIoTarget(this_00);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(ushort *)(this + 0x1a));
    if (iVar7 != 0) {
      lVar1 = RHP_DEVICE::CreateDeviceInterface
                        (*(RHP_DEVICE **)(this + 8),*(void **)(this + 0x30),
                         (_GUID *)&GUID_DEVINTERFACE_RHPROXY_GPIO,2);
      if ((lVar1 < 0) && ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        uVar10 = (undefined1)lVar1;
        uVar6 = 0x24;
        uVar9 = 0x74;
LAB_1c0017392:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar9,uVar10);
      }
      return lVar1;
    }
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x23,
                       &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",100);
  }
  RHP_DEVICE::_CONTROLLER_REGISTRY::Remove
            ((_CONTROLLER_REGISTRY *)(*(longlong *)(this + 8) + 0x20),*(void **)(this + 0x30));
  return 0;
}



===== ComputeBestEdgeMode @ 1c00175a0 =====

/* public: static enum _RHPROXY_GPIO_INTERRUPT_MODE __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::ComputeBestEdgeMode(union
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::_FLAGS) */

_RHPROXY_GPIO_INTERRUPT_MODE __cdecl
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::ComputeBestEdgeMode(uint param_1)

{
  _RHPROXY_GPIO_INTERRUPT_MODE _Var1;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var2;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var3;
  
  _Var1 = param_1 >> 2 & 3;
  _Var3 = param_1 >> 4 & 3;
  _Var2 = _Var1;
  if (_Var3 != 0) {
    if (_Var1 == 0) {
      _Var2 = _Var3;
    }
    else {
      _Var2 = 3;
      if (_Var3 == _Var1) {
        _Var2 = _Var3;
      }
    }
  }
  _Var1 = param_1 >> 6 & 3;
  if (_Var2 == 0) {
    _Var2 = _Var1;
  }
  else if ((_Var1 != 0) && (_Var2 != _Var1)) {
    _Var2 = 3;
  }
  return _Var2;
}



===== ConfigureInterrupt @ 1c00175f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::ConfigureInterrupt(enum
   _RHPROXY_GPIO_INTERRUPT_MODE,class RHP_GPIO_CONTROLLER * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::ConfigureInterrupt
          (_PIN_DESCRIPTOR *this,_RHPROXY_GPIO_INTERRUPT_MODE param_1,RHP_GPIO_CONTROLLER *param_2)

{
  longlong lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  RHP_GPIO_CONTROLLER *pRVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  undefined1 auStackY_b8 [32];
  undefined1 uVar8;
  long local_68 [2];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined1 local_51;
  _PIN_DESCRIPTOR local_50;
  undefined1 local_4f;
  undefined2 local_4e;
  undefined8 local_4c;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar1 = *(longlong *)(this + 0x60);
  local_4c = 0;
  local_44 = 0;
  local_4f = 0;
  local_60 = 1;
  local_5c = 1;
  local_58 = *(undefined4 *)(lVar1 + 0x50);
  local_54 = 0xffff;
  local_52 = 1;
  pRVar5 = param_2;
  local_51 = `anonymous_namespace'::pnpGpioIrqPolarityFromRhproxyInterruptMode(param_1);
  puVar6 = &local_60;
  uVar4 = 0x2ac00c;
  local_50 = this[0x8b];
  local_4e = *(undefined2 *)(this + 0x92);
  local_68[0] = 1;
  lVar3 = RhpSendIoctlSynchronously
                    (*(WDFIOTARGET__ **)(*(longlong *)(pRVar5 + 8) + 0x18),0x2ac00c,puVar6,0x20,
                     local_68,4,(__uint64 *)0x0);
  if (lVar3 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar6,0x8e,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x3a,(char)lVar3,(char)param_1)
      ;
    }
  }
  else {
    local_68[0] = 0;
    lVar3 = ReadPinValue(this,local_68);
    lVar2 = local_68[0];
    if (lVar3 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar3;
      }
      uVar7 = 0x8f;
      uVar8 = 0x44;
    }
    else {
      if ((param_1 != 3) ||
         (lVar3 = updateResHubInitialPolarity(param_2,this,(uint)(local_68[0] == 0)), -1 < lVar3)) {
        *(long *)(lVar1 + 4) = lVar2;
        return 0;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar3;
      }
      uVar8 = 0x51;
      uVar7 = 0x90;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar8,(char)lVar3);
  }
  return lVar3;
}



===== CreateDescriptor @ 1c00177e0 =====

/* public: struct RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR * __ptr64 __cdecl
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::CreateDescriptor(union _LARGE_INTEGER,unsigned long)
   __ptr64 */

_PIN_DESCRIPTOR * __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR_INDEX::CreateDescriptor
          (_PIN_DESCRIPTOR_INDEX *this,undefined8 param_2,int param_3)

{
  long lVar1;
  _PIN_DESCRIPTOR *p_Var2;
  uint uVar3;
  undefined8 uVar4;
  
  if (*(short *)(this + 2) != -1) {
    if (param_3 == -1) {
      param_3 = *(int *)(this + 4) + 1;
    }
    if (*(int *)(this + 4) < param_3) {
      lVar1 = reserve(this,*(short *)(this + 2) + 1);
      if (-1 < lVar1) {
        *(int *)(this + 4) = param_3;
        p_Var2 = (_PIN_DESCRIPTOR *)
                 ((ulonglong)*(ushort *)(this + 2) * 0x98 + *(longlong *)(this + 8));
        *(ushort *)(this + 2) = *(ushort *)(this + 2) + 1;
        *(undefined8 *)(p_Var2 + 0x78) = param_2;
        *(int *)(p_Var2 + 0x80) = param_3;
        return p_Var2;
      }
    }
    else {
      uVar3 = 0xc0010000;
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDqll(uVar4);
        uVar3 = (uint)uVar4;
      }
      _RhpLogDebug(uVar3);
    }
  }
  return (_PIN_DESCRIPTOR *)0x0;
}



===== DisableWdfInterrupt @ 1c00178a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::DisableWdfInterrupt(void) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::DisableWdfInterrupt(_INTERRUPT_CONTEXT *this)

{
  (**(code **)(WdfFunctions_01015 + 0x498))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  *(uint *)this = *(uint *)this & 0xfffffffc;
  return;
}



===== EnableWdfInterrupt @ 1c00178dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::EnableWdfInterrupt(enum
   _RHPROXY_GPIO_INTERRUPT_MODE) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::EnableWdfInterrupt
          (_INTERRUPT_CONTEXT *this,_RHPROXY_GPIO_INTERRUPT_MODE param_1)

{
  *(_RHPROXY_GPIO_INTERRUPT_MODE *)this =
       (*(_RHPROXY_GPIO_INTERRUPT_MODE *)this ^ param_1) & 3 ^ *(_RHPROXY_GPIO_INTERRUPT_MODE *)this
  ;
  (**(code **)(WdfFunctions_01015 + 0x490))(WdfDriverGlobals,*(undefined8 *)(this + 0x58));
  return;
}



===== EvtDeviceFileCreate @ 1c0017920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_GPIO_CONTROLLER::EvtDeviceFileCreate(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::EvtDeviceFileCreate
          (RHP_GPIO_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  _PIN_DESCRIPTOR _Var1;
  undefined4 *puVar2;
  undefined1 uVar3;
  ulong uVar4;
  ulong uVar5;
  longlong *plVar6;
  long lVar7;
  int iVar8;
  undefined4 uVar9;
  _PIN_DESCRIPTOR *p_Var10;
  ulonglong uVar11;
  longlong lVar12;
  code *pcVar13;
  uint uVar14;
  RHP_GPIO_CONTROLLER *this_00;
  _PIN_DESCRIPTOR *p_Var15;
  undefined8 uVar16;
  WDFFILEOBJECT__ *pWVar17;
  int iVar18;
  undefined8 *puVar19;
  int iVar20;
  undefined *in_stack_ffffffffffffff48;
  char *in_stack_ffffffffffffff50;
  undefined1 uVar21;
  undefined1 uVar23;
  undefined1 uVar22;
  ulong local_78;
  ulong local_74;
  ulong local_70 [2];
  longlong *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined *local_30;
  
  local_78 = 0;
  this_00 = this;
  lVar7 = parseWdfFileObjectFileName(this,param_3,&local_78);
  if (lVar7 < 0) {
LAB_1c001796a:
    pcVar13 = *(code **)(WdfFunctions_01015 + 0x838);
    goto LAB_1c0017ac5;
  }
  if (local_78 != 0xffffffff) {
    iVar20 = 0;
    iVar18 = *(ushort *)(this + 0x1a) - 1;
    if (-1 < iVar18) {
      do {
        iVar8 = (iVar18 + iVar20) / 2;
        uVar14 = *(uint *)((longlong)iVar8 * 0x98 + 0x80 + *(longlong *)(this + 0x20));
        if (uVar14 < local_78) {
          iVar20 = iVar8 + 1;
        }
        else {
          if (uVar14 <= local_78) goto LAB_1c001799a;
          iVar18 = iVar8 + -1;
        }
      } while (iVar20 <= iVar18);
    }
    lVar7 = -0x3ffffddb;
    goto LAB_1c0017ab7;
  }
  iVar8 = 0xffff;
LAB_1c001799a:
  local_74 = 0;
  local_70[0] = 0;
  lVar7 = getDesiredAndShareAccess(this_00,param_2,&local_74,local_70);
  if (lVar7 < 0) goto LAB_1c001796a;
  puVar19 = &local_60;
  local_30 = PTR__WDF__RHP_GPIO_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c00100f0;
  local_50 = 0;
  uStack_58 = 0;
  local_60 = 0x38;
  local_40 = 0;
  uStack_38 = 0;
  uStack_48 = 0x100000001;
  local_68 = (longlong *)0x0;
  iVar18 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_3,puVar19,&local_68);
  plVar6 = local_68;
  uVar21 = SUB81(this,0);
  if (iVar18 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar19,0x25,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xb6,uVar21,(char)iVar18);
    }
    lVar7 = -0x3fffffff;
  }
  else {
    if ((ushort)iVar8 == 0xffff) {
      p_Var10 = (_PIN_DESCRIPTOR *)0x0;
    }
    else {
      p_Var10 = _PIN_DESCRIPTOR_INDEX::operator[]
                          ((_PIN_DESCRIPTOR_INDEX *)(this + 0x18),(ushort)iVar8);
    }
    uVar5 = local_70[0];
    uVar4 = local_74;
    *plVar6 = (longlong)p_Var10;
    plVar6[1] = (longlong)this;
    *(ulong *)(plVar6 + 2) = local_74;
    *(ulong *)((longlong)plVar6 + 0x14) = local_70[0];
    plVar6[3] = 0;
    plVar6[4] = 0;
    plVar6[5] = 0;
    uVar22 = (undefined1)local_70[0];
    uVar23 = (undefined1)local_74;
    if (*plVar6 != 0) {
      pWVar17 = param_3;
      uVar11 = (**(code **)(WdfFunctions_01015 + 0x450))(WdfDriverGlobals);
      if (((uVar11 & 2) != 0) &&
         ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDqLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      uVar3 = (undefined1)iVar8;
      if ((uVar5 != 0) && (uVar5 != 1)) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqLL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x29,
                     &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xf8,uVar21,uVar3,uVar22);
        }
        goto LAB_1c0017b8b;
      }
      if (uVar4 != 0x80000000) {
        if (uVar4 != 0xc0000000) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqLLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar17,puVar19,0x2b,
                       in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,0x12,uVar21,uVar3,uVar23,
                       uVar22);
          }
          goto LAB_1c0017be5;
        }
        if (uVar5 != 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqLLL
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar17,puVar19,0x2a,
                       in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,7,uVar21,uVar3,0,uVar22);
          }
          goto LAB_1c0017b8b;
        }
      }
      p_Var10 = (_PIN_DESCRIPTOR *)*plVar6;
      p_Var15 = p_Var10;
      ExAcquirePushLockExclusiveEx(p_Var10,2);
      uVar14 = (uint)p_Var15;
      if (*(int *)(p_Var10 + 0x84) == 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
LAB_1c0017dd4:
          if (*(longlong *)(p_Var10 + 0x68) != 0) {
            _RhpLogDebug(uVar14);
          }
        }
        else if (*(longlong *)(p_Var10 + 0x68) != 0) {
          in_stack_ffffffffffffff50 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
          in_stack_ffffffffffffff48 = &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
          uVar16 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          WPP_RECORDER_SF_sDs(uVar16,2,3,0x2c,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x1b,
                              "!lockedPinDescriptor->WdfIoTarget");
          uVar14 = (uint)uVar16;
          goto LAB_1c0017dd4;
        }
        p_Var10[0x88] = (_PIN_DESCRIPTOR)(uVar5 == 0);
        puVar2 = *(undefined4 **)(p_Var10 + 0x60);
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = 0;
          *(undefined8 *)(puVar2 + 2) = 0;
        }
LAB_1c0017e8a:
        if (p_Var10[0x89] == (_PIN_DESCRIPTOR)0x0) {
          lVar7 = queryResHubPinProperties(this,p_Var10);
          if ((-1 < lVar7) &&
             ((*(longlong *)(p_Var10 + 0x60) == 0 ||
              (lVar7 = queryResHubInterruptProperties(this,p_Var10), -1 < lVar7)))) {
            p_Var10[0x89] = (_PIN_DESCRIPTOR)0x1;
            goto LAB_1c0017ed8;
          }
LAB_1c0017ea5:
          pcVar13 = *(code **)(WdfFunctions_01015 + 0x838);
          goto LAB_1c0018045;
        }
LAB_1c0017ed8:
        if (*(longlong *)(p_Var10 + 0x68) == 0) {
          lVar7 = createWdfIoTarget(this,p_Var10);
          if (lVar7 < 0) goto LAB_1c0017ea5;
          _Var1 = p_Var10[0x8b];
          if (_Var1 == (_PIN_DESCRIPTOR)0x0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x2e,
                                  &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x5e,
                                  (char)*(undefined8 *)(p_Var10 + 0x78));
            }
LAB_1c0017fa4:
            uVar9 = 1;
          }
          else if (_Var1 == (_PIN_DESCRIPTOR)0x1) {
            uVar9 = 2;
          }
          else {
            if (_Var1 != (_PIN_DESCRIPTOR)0x2) {
              if ((_Var1 != (_PIN_DESCRIPTOR)0x3) &&
                 ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_sDqi
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x2f,
                           in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,0x68,uVar21,
                           (char)*(undefined8 *)(p_Var10 + 0x78));
              }
              goto LAB_1c0017fa4;
            }
            uVar9 = 4;
          }
          *(undefined4 *)(p_Var10 + 8) = uVar9;
          *(undefined4 *)(p_Var10 + 0xc) = 1;
        }
        *(int *)(p_Var10 + 0x84) = *(int *)(p_Var10 + 0x84) + 1;
        uVar16 = WdfDriverGlobals;
        lVar12 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,param_3);
        uVar14 = (uint)uVar16;
        if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(longlong *)(lVar12 + 0x20) != 0)) {
          uVar16 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          WPP_RECORDER_SF_sDs(uVar16,2,3,0x30,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x7c,
                              "!fileObjectPtr->FsContext2");
          uVar14 = (uint)uVar16;
        }
        if (*(longlong *)(lVar12 + 0x20) != 0) {
          _RhpLogDebug(uVar14);
        }
        *(longlong **)(lVar12 + 0x20) = plVar6;
        lVar7 = 0;
      }
      else {
        if ((uVar5 != 0) && (p_Var10[0x88] == (_PIN_DESCRIPTOR)0x0)) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
LAB_1c0017e77:
            if (*(longlong *)(p_Var10 + 0x68) == 0) {
              _RhpLogDebug(uVar14);
            }
          }
          else if (*(longlong *)(p_Var10 + 0x68) == 0) {
            in_stack_ffffffffffffff50 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
            uVar16 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            in_stack_ffffffffffffff48 = &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
            WPP_RECORDER_SF_sDs(uVar16,2,3,0x2d,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x2a,
                                "lockedPinDescriptor->WdfIoTarget");
            uVar14 = (uint)uVar16;
            goto LAB_1c0017e77;
          }
          p_Var10[0x88] = (_PIN_DESCRIPTOR)0x0;
          goto LAB_1c0017e8a;
        }
        lVar7 = -0x3fffffbd;
      }
      pcVar13 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c0018045:
      (*pcVar13)(WdfDriverGlobals,param_2,lVar7);
      ExReleasePushLockExclusiveEx(p_Var10,2);
      return;
    }
    if (local_70[0] == 3) {
      if (((local_74 & 0x3fffffff) == 0) && (local_74 != 0)) {
        lVar7 = 0;
      }
      else {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar19,0x27,
                     in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,0xd9,uVar21,uVar23);
        }
LAB_1c0017be5:
        lVar7 = -0x3ffffbd9;
      }
    }
    else {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar19,0x26,
                   in_stack_ffffffffffffff48,in_stack_ffffffffffffff50,0xcb,uVar21,uVar22);
      }
LAB_1c0017b8b:
      lVar7 = -0x3fffffbd;
    }
  }
LAB_1c0017ab7:
  pcVar13 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c0017ac5:
  (*pcVar13)(WdfDriverGlobals,param_2,lVar7);
  return;
}



===== EvtFileClose @ 1c0018080 =====

/* public: virtual void __cdecl RHP_GPIO_CONTROLLER::EvtFileClose(struct WDFFILEOBJECT__ * __ptr64)
   __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::EvtFileClose(RHP_GPIO_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  _NOTIFICATION_ENTRY *p_Var1;
  _PIN_DESCRIPTOR *this_00;
  _INTERRUPT_CONTEXT *p_Var2;
  long lVar3;
  _FILE_OBJECT_CONTEXT *p_Var4;
  _PIN_DESCRIPTOR *p_Var5;
  _PIN_DESCRIPTOR _Var6;
  undefined7 in_register_00000081;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  p_Var4 = getFileObjectContextFromWdfObject(this,param_1);
  this_00 = *(_PIN_DESCRIPTOR **)p_Var4;
  if (this_00 != (_PIN_DESCRIPTOR *)0x0) {
    ExAcquirePushLockExclusiveEx(this_00,2);
    p_Var1 = (_NOTIFICATION_ENTRY *)(p_Var4 + 0x18);
    if (*(longlong *)p_Var1 != 0) {
      p_Var2 = *(_INTERRUPT_CONTEXT **)(this_00 + 0x60);
      _INTERRUPT_CONTEXT::_NOTIFICATION::Remove((_NOTIFICATION *)(p_Var2 + 0x60),p_Var1);
      *(undefined8 *)(p_Var4 + 0x20) = 0;
      *(undefined8 *)p_Var1 = 0;
      if (*(_INTERRUPT_CONTEXT **)(p_Var2 + 0x70) == p_Var2 + 0x70) {
        _INTERRUPT_CONTEXT::DisableNotificationSynchronized(p_Var2);
      }
    }
    p_Var2 = *(_INTERRUPT_CONTEXT **)(this_00 + 0x60);
    if (((p_Var2 != (_INTERRUPT_CONTEXT *)0x0) && ((*(uint *)p_Var2 & 3) != 0)) &&
       (*(_INTERRUPT_CONTEXT **)(p_Var2 + 0x70) == p_Var2 + 0x70)) {
      _INTERRUPT_CONTEXT::DisableWdfInterrupt(p_Var2);
    }
    if (*(longlong *)(p_Var4 + 0x28) != 0) {
      ObfDereferenceObjectWithTag(*(longlong *)(p_Var4 + 0x28),0x34504852);
      *(undefined8 *)(p_Var4 + 0x28) = 0;
    }
    p_Var5 = this_00 + 0x84;
    *(int *)p_Var5 = *(int *)p_Var5 + -1;
    if (*(int *)p_Var5 == 0) {
      *(undefined4 *)(this_00 + 8) = 0;
      if (*(longlong *)(this_00 + 0x68) != 0) {
        _PIN_DESCRIPTOR::deleteWdfIoTarget(this_00);
      }
      _Var6 = this_00[0x8a];
      p_Var5 = this_00;
      lVar3 = updateResHubPullConfiguration(this,this_00,(uchar)_Var6);
      if ((lVar3 < 0) && ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_sDDDd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var5,
                   CONCAT71(in_register_00000081,_Var6),0x31,in_stack_ffffffffffffffc8,
                   in_stack_ffffffffffffffd0,0xda,(char)*(undefined4 *)(this_00 + 0x80),
                   this_00[0x8a],(char)lVar3);
      }
    }
    ExReleasePushLockExclusiveEx(this_00,2);
  }
  return;
}



===== HandlePinValueChangedInterruptsDisabled @ 1c00181e4 =====

/* public: void __cdecl
   RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::HandlePinValueChangedInterruptsDisabled(long) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::_INTERRUPT_CONTEXT::HandlePinValueChangedInterruptsDisabled
          (_INTERRUPT_CONTEXT *this,long param_1)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  ulong local_res8 [2];
  
  uVar1 = *(uint *)this;
  lVar3 = param_1;
  bVar2 = `anonymous_namespace'::FilterEdge(uVar1 >> 2 & 3,param_1);
  if (bVar2) {
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
  }
  bVar2 = `anonymous_namespace'::FilterEdge(uVar1 >> 6 & 3,lVar3);
  if (bVar2) {
    local_res8[0] = 0;
    lVar3 = _INTERRUPT_BUFFER_CONTEXT::PushCurrentTimestamp
                      ((_INTERRUPT_BUFFER_CONTEXT *)(this + 0x10),lVar3,local_res8);
    if (lVar3 == -0x7ffffffb) {
      KeSetEvent(*(undefined8 *)(this + 0x28),1);
    }
    else if (((lVar3 == 0) && (*(longlong *)(this + 0x38) != 0)) &&
            (*(uint *)(this + 0x40) <= local_res8[0])) {
      _INTERRUPT_BUFFER_CONTEXT::SatisfyWaitInterruptsDisabled
                ((_INTERRUPT_BUFFER_CONTEXT *)(this + 0x10));
    }
  }
  bVar2 = `anonymous_namespace'::FilterEdge(uVar1 >> 4 & 3,param_1);
  if (bVar2) {
    _NOTIFICATION::Trigger((_NOTIFICATION *)(this + 0x60),param_1);
  }
  return;
}



===== ParseConnectionResource @ 1c00182b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_GPIO_CONTROLLER::ParseConnectionResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,class RHP_DEVICE * __ptr64,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64) */

long __cdecl
RHP_GPIO_CONTROLLER::ParseConnectionResource
          (ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,RHP_DEVICE *param_3,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_4)

{
  uint uVar1;
  long lVar2;
  RHP_GPIO_CONTROLLER *this;
  RHP_CONTROLLER *this_00;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined8 *local_40;
  undefined8 local_38;
  undefined2 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  if (singletonPtr == (RHP_GPIO_CONTROLLER *)0x0) {
    this = (RHP_GPIO_CONTROLLER *)ExAllocatePoolWithTag(0x200,0x38,0x33504852);
    if ((this == (RHP_GPIO_CONTROLLER *)0x0) ||
       (this_00 = (RHP_CONTROLLER *)RHP_GPIO_CONTROLLER(this,param_3),
       this_00 == (RHP_CONTROLLER *)0x0)) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                           &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xe5);
      }
      return -0x3fffffe9;
    }
    local_30 = 0;
    local_40 = &local_38;
    local_38 = 0x4f004900500047;
    local_48 = 0xa0008;
    uVar1 = RHP_DEVICE::RegisterController
                      (param_3,(_UNICODE_STRING *)&local_48,this_00,(void **)(this_00 + 0x30));
    if ((int)uVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1e,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xf5,(char)uVar1);
      }
      if ((uVar1 != 0xc000009a) && (uVar1 != 0xc0000017)) {
        uVar1 = (int)uVar1 >> 0x1f & 0xc0000001;
      }
      RHP_CONTROLLER::ReleaseReference(this_00);
      return uVar1;
    }
    RHP_CONTROLLER::ReleaseReference(this_00);
  }
  lVar2 = parseConnectionResource(singletonPtr,param_2,param_4);
  return lVar2;
}



===== ReadPinValue @ 1c001846c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::ReadPinValue(long * __ptr64) __ptr64
    */

long __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::ReadPinValue(_PIN_DESCRIPTOR *this,long *param_1)

{
  int iVar1;
  long *plVar2;
  undefined8 in_R8;
  uint local_res8 [2];
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined8 local_28;
  uint *local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = *(undefined8 *)(this + 0x30);
  local_14 = 0;
  local_res8[0] = 0;
  local_20 = local_res8;
  local_18 = 1;
  plVar2 = param_1;
  iVar1 = (**(code **)(this + 0x38))(&local_28);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDLd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar2,in_R8,0x92,
                 in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0xdb,(char)local_14,(char)iVar1
                );
    }
  }
  else {
    *param_1 = local_res8[0] & 1;
    iVar1 = 0;
  }
  return iVar1;
}



===== RegisterNotificationEntry @ 1c0018514 =====

/* public: long __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::RegisterNotificationEntry(struct
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT::_NOTIFICATION_ENTRY * __ptr64,class
   RHP_GPIO_CONTROLLER * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::RegisterNotificationEntry
          (_PIN_DESCRIPTOR *this,_NOTIFICATION_ENTRY *param_1,RHP_GPIO_CONTROLLER *param_2,
          ulong *param_3)

{
  int iVar1;
  _INTERRUPT_CONTEXT *this_00;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  this_00 = *(_INTERRUPT_CONTEXT **)(this + 0x60);
  if (*(_INTERRUPT_CONTEXT **)(this_00 + 0x70) == this_00 + 0x70) {
    iVar1 = *(int *)(this + 8);
    if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 4)) {
      *(undefined4 *)(this_00 + 0x60) = *(undefined4 *)(this + 0xc);
      uVar2 = _INTERRUPT_CONTEXT::_NOTIFICATION::Insert((_NOTIFICATION *)(this_00 + 0x60),param_1);
      *param_3 = uVar2;
      *(uint *)this_00 = *(uint *)this_00 | 0x30;
      return 0;
    }
    if ((*(uint *)this_00 & 3) != 3) {
      if ((*(uint *)this_00 & 3) != 0) {
        _INTERRUPT_CONTEXT::DisableWdfInterrupt(this_00);
      }
      uVar4 = 3;
      lVar3 = ConfigureInterrupt(this,3,param_2);
      if (-1 < lVar3) {
        *(uint *)this_00 = *(uint *)this_00 | 0x30;
        *(undefined4 *)(this_00 + 0x60) = *(undefined4 *)(this_00 + 4);
        uVar2 = _INTERRUPT_CONTEXT::_NOTIFICATION::Insert((_NOTIFICATION *)(this_00 + 0x60),param_1)
        ;
        *param_3 = uVar2;
        _INTERRUPT_CONTEXT::EnableWdfInterrupt(this_00,3);
        return 0;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDLd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_2,0x91,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,0x97,(char)lVar3,
                   (char)*(undefined4 *)(this + 0x80));
      }
      return lVar3;
    }
    _INTERRUPT_CONTEXT::_NOTIFICATION::Insert((_NOTIFICATION *)(this_00 + 0x60),param_1);
    uVar2 = _INTERRUPT_CONTEXT::EnableNotificationSynchronized(this_00);
  }
  else {
    uVar2 = _INTERRUPT_CONTEXT::_NOTIFICATION::Insert((_NOTIFICATION *)(this_00 + 0x60),param_1);
  }
  *param_3 = uVar2;
  return 0;
}



===== WritePinValue @ 1c0018660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::WritePinValue(long) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::WritePinValue(_PIN_DESCRIPTOR *this,long param_1)

{
  long lVar1;
  long local_res10 [6];
  
  *(long **)(this + 0x50) = local_res10;
  local_res10[0] = param_1;
  lVar1 = (**(code **)(this + 0x40))(this + 0x48);
  return lVar1;
}



===== createWdfIoTarget @ 1c001868c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0018829) */
/* WARNING: Removing unreachable block (ram,0x0001c00189dc) */
/* WARNING: Removing unreachable block (ram,0x0001c001894a) */
/* private: long __cdecl RHP_GPIO_CONTROLLER::createWdfIoTarget(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::createWdfIoTarget(RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  RHP_GPIO_CONTROLLER *pRVar5;
  __uint64 *p_Var6;
  short *psVar7;
  undefined8 uVar8;
  undefined1 auStackY_1d8 [32];
  char *in_stack_fffffffffffffe50;
  undefined1 uVar9;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 local_10c;
  undefined4 local_108;
  __uint64 local_c8 [6];
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  pRVar5 = this;
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(longlong *)(param_1 + 0x68) != 0)) {
    in_stack_fffffffffffffe50 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
    pRVar5 = *(RHP_GPIO_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDs(pRVar5,2,3,0x86,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x37,
                        "PinDescriptorPtr->WdfIoTarget == NULL");
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    _RhpLogDebug((uint)pRVar5);
  }
  uStack_170 = local_98;
  local_178 = 0x4c0000;
  local_180 = *(undefined4 *)(param_1 + 0x78);
  p_Var6 = local_c8;
  uStack_17c = *(undefined4 *)(param_1 + 0x7c);
  uVar3 = *(undefined8 *)(param_1 + 0x78);
  iVar1 = RESOURCE_HUB_STRING_PRINTF((ushort *)p_Var6,0x22,(ushort *)L"%0*I64x",(__uint64 *)0x10);
  uVar4 = (uint)p_Var6;
  uVar9 = SUB81(this,0);
  if (-1 < iVar1) {
    psVar7 = (short *)&local_178;
    iVar1 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                      (psVar7,(ushort *)L"%s%s",L"\\Device\\RESOURCE_HUB\\",local_c8);
    uVar4 = (uint)psVar7;
    if (-1 < iVar1) {
      uVar3 = *(undefined8 *)(*(longlong *)(this + 8) + 8);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x538))(WdfDriverGlobals,uVar3,0);
      if (iVar1 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqqL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x88,
                     &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x53,uVar9,(char)uVar3,
                     (char)iVar1);
        }
        return -0x3fffffff;
      }
      memset(&local_158,0,0x88);
      local_158 = 0x88;
      local_154 = 2;
      local_128 = (undefined4)local_178;
      uStack_124 = local_178._4_4_;
      uStack_120 = (undefined4)uStack_170;
      uStack_11c = uStack_170._4_4_;
      local_118 = 0xc0000000;
      local_108 = 0x40;
      local_10c = 1;
      uVar3 = PsGetHostSilo();
      uVar3 = PsAttachSiloToCurrentThread(uVar3);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x540))(WdfDriverGlobals,0);
      PsDetachSiloFromCurrentThread(uVar3);
      if (iVar1 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqqL
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x89,
                     &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x6b,uVar9,0,(char)iVar1);
        }
        return iVar1;
      }
      lVar2 = RhpSendIoctlSynchronously
                        ((WDFIOTARGET__ *)0x0,0x48000c,(void *)0x0,0,param_1 + 0x10,0x38,
                         (__uint64 *)&local_180);
      if (-1 < lVar2) {
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined8 *)(param_1 + 0x48) = 0;
        *(undefined8 *)(param_1 + 0x50) = 0;
        *(undefined8 *)(param_1 + 0x58) = 0;
        *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_1 + 0x30);
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x58) = 1;
        return 0;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDiLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      return lVar2;
    }
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDqi
              (uVar8,2,3,0x87,uVar3,in_stack_fffffffffffffe50,0x43,uVar9,
               (char)*(undefined8 *)(param_1 + 0x78));
    uVar4 = (uint)uVar8;
  }
  _RhpLogDebug(uVar4);
  return -0x3fffff1b;
}



===== deleteWdfIoTarget @ 1c0018aa8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::deleteWdfIoTarget(void) __ptr64 */

void __thiscall RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR::deleteWdfIoTarget(_PIN_DESCRIPTOR *this)

{
  (**(code **)(this + 0x28))(*(undefined8 *)(this + 0x30));
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0x68));
  *(undefined8 *)(this + 0x68) = 0;
  return;
}



===== dispatchIoControl @ 1c0018b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::dispatchIoControl(unsigned long,class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::dispatchIoControl
          (RHP_GPIO_CONTROLLER *this,ulong param_1,_FILE_OBJECT_CONTEXT *param_2,
          WDFREQUEST__ *param_3)

{
  undefined8 uVar1;
  int iVar2;
  WDFREQUEST__ *pWVar3;
  undefined8 uVar4;
  bool bVar5;
  long lVar6;
  
  if (param_1 < 0x2281b9) {
    if (param_1 == 0x2281b8) {
      bVar5 = true;
    }
    else {
      if (param_1 == 0x224190) {
        ioctlRhproxyGpioGetControllerInfo(this,param_2,param_3);
        return;
      }
      if (param_1 == 0x22419c) {
        ioctlRhproxyGpioPinGetDriveMode(this,param_2,param_3);
        return;
      }
      if (param_1 == 0x2241af) {
        ioctlRhproxyGpioPinRead(this,param_2,param_3);
        return;
      }
      if (param_1 != 0x2241b4) {
        if (param_1 == 0x22819b) {
          ioctlRhproxyGpioPinSetDriveMode(this,param_2,param_3);
          return;
        }
        if (param_1 == 0x2281a7) {
          lVar6 = 1;
LAB_1c0018b74:
          ioctlRhproxyGpioPinWrite(this,param_2,param_3,lVar6);
          return;
        }
        if (param_1 == 0x2281ab) {
          lVar6 = 0;
          goto LAB_1c0018b74;
        }
        goto LAB_1c0018c12;
      }
      bVar5 = false;
    }
    ioctlRhproxyGpioPinQueryInterruptCount(this,param_2,param_3,bVar5);
  }
  else {
    if (param_1 == 0x22c1b0) {
      ioctlRhproxyGpioPinStartInterruptCount(this,param_2,param_3);
      return;
    }
    if (param_1 == 0x22c1bc) {
      ioctlRhproxyGpioPinStopInterruptCount(param_2,param_3);
      return;
    }
    if (param_1 == 0x22c1c2) {
      ioctlRhproxyGpioPinRegisterInterruptBuffer(param_2,param_3);
      return;
    }
    if (param_1 == 0x22c1c4) {
      ioctlRhproxyGpioPinStartInterruptBuffer(this,param_2,param_3);
      return;
    }
    if (param_1 == 0x22c1c8) {
      ioctlRhproxyGpioPinStopInterruptBuffer(param_2,param_3);
      return;
    }
    if (param_1 == 0x22c1cc) {
      uVar1 = *(undefined8 *)(*(longlong *)param_2 + 0x70);
      pWVar3 = param_3;
      uVar4 = uVar1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals);
      if (-1 < iVar2) {
        return;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdqq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar3,uVar4,0x34,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x3f,(char)iVar2,
                   (char)param_3,(char)uVar1);
      }
    }
    else {
LAB_1c0018c12:
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqqL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x35,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x51,(char)this,(char)param_3
                   ,(char)param_1);
      }
      iVar2 = -0x3fffff45;
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_3,iVar2);
  }
  return;
}



===== evtCancelRegisterInterruptBufferWorkItem @ 1c0018d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtCancelRegisterInterruptBufferWorkItem(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::evtCancelRegisterInterruptBufferWorkItem(WDFWORKITEM__ *param_1)

{
  WDFREQUEST__ *pWVar1;
  
  pWVar1 = (WDFREQUEST__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  cancelRegisterInterruptBufferPassiveWorker(pWVar1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== evtCancelWaitInterruptBufferWorkItem @ 1c0018de0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtCancelWaitInterruptBufferWorkItem(struct
   WDFWORKITEM__ * __ptr64) */

void __cdecl RHP_GPIO_CONTROLLER::evtCancelWaitInterruptBufferWorkItem(WDFWORKITEM__ *param_1)

{
  WDFREQUEST__ *pWVar1;
  
  pWVar1 = (WDFREQUEST__ *)(**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  cancelWaitInterruptBufferPassiveWorker(pWVar1);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== evtWaitInterruptBufferIoDeviceControl @ 1c0018e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::evtWaitInterruptBufferIoDeviceControl(struct
   WDFQUEUE__ * __ptr64,struct WDFREQUEST__ * __ptr64,unsigned __int64,unsigned __int64,unsigned
   long) */

void __cdecl
RHP_GPIO_CONTROLLER::evtWaitInterruptBufferIoDeviceControl
          (WDFQUEUE__ *param_1,WDFREQUEST__ *param_2,__uint64 param_3,__uint64 param_4,ulong param_5
          )

{
  long lVar1;
  undefined8 uVar2;
  _FILE_OBJECT_CONTEXT *p_Var3;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals);
  p_Var3 = (_FILE_OBJECT_CONTEXT *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,uVar2,
                      PTR__WDF__RHP_GPIO_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c00100f0);
  lVar1 = ioctlRhproxyGpioPinWaitInterruptBuffer(p_Var3,param_2);
  if (lVar1 != 0x103) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  }
  return;
}



===== getDesiredAndShareAccess @ 1c0018ec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::getDesiredAndShareAccess(struct WDFREQUEST__ *
   __ptr64,unsigned long * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::getDesiredAndShareAccess
          (RHP_GPIO_CONTROLLER *this,WDFREQUEST__ *param_1,ulong *param_2,ulong *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  lStack_30 = 0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (local_38._4_4_ == 0) {
    iVar1 = *(int *)(lStack_30 + 0x10);
    if (iVar1 == 0x120089) {
      *param_2 = 0x80000000;
    }
    else if (iVar1 == 0x120116) {
      *param_2 = 0x40000000;
    }
    else {
      if (iVar1 != 0x12019f) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x75,
                              &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x5c,(char)iVar1);
        }
        return -0x3fffffde;
      }
      *param_2 = 0xc0000000;
    }
    uVar4 = (uint)uStack_20._2_2_;
    if (((uStack_20._2_2_ == 0) || (uVar4 == 1)) || (uVar4 == 3)) {
      *param_3 = uVar4;
      lVar2 = 0;
    }
    else {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x76,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x69,
                            (char)((ulonglong)uStack_20 >> 0x10));
      }
      lVar2 = -0x3ffffbd9;
    }
  }
  else {
    uVar4 = local_38._4_4_;
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDd(uVar3,2,3,0x74,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x4b,
                          (char)((ulonglong)local_38 >> 0x20));
      uVar4 = (uint)uVar3;
    }
    _RhpLogDebug(uVar4);
    lVar2 = -0x3fffff1b;
  }
  return lVar2;
}



===== ioctlRhproxyGpioGetControllerInfo @ 1c00190b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioGetControllerInfo(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioGetControllerInfo
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  short sVar1;
  long lVar2;
  code *pcVar3;
  _RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT *local_res10;
  
  if (*(longlong *)param_1 == 0) {
    local_res10 = (_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT *)0x0;
    lVar2 = RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_GET_CONTROLLER_INFO_OUTPUT>
                      (param_2,&local_res10,(__uint64)param_2);
    if (-1 < lVar2) {
      sVar1 = *(short *)(this + 0x2a);
      if (sVar1 == 0) {
        sVar1 = *(short *)(this + 0x1c) + 1;
      }
      *(short *)local_res10 = sVar1;
      *(undefined4 *)(local_res10 + 4) = *(undefined4 *)(this + 0x2c);
      KeQueryPerformanceCounter(local_res10 + 8);
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,lVar2,0x10);
      return;
    }
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x36,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",100,(char)this,(char)param_2);
    }
    lVar2 = -0x3fffff45;
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  (*pcVar3)(WdfDriverGlobals,param_2,lVar2);
  return;
}



===== ioctlRhproxyGpioPinGetDriveMode @ 1c00191e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinGetDriveMode(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinGetDriveMode
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  WDFREQUEST__ *pWVar7;
  _RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *local_res10;
  
  uVar4 = (uint)this;
  if (*(longlong *)param_1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x41,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x68,(char)this,(char)param_2);
    }
    lVar2 = -0x3fffff45;
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c001926d:
    (*pcVar3)(WdfDriverGlobals,param_2,lVar2);
    return;
  }
  pWVar7 = param_2;
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (-1 < *(int *)(param_1 + 0x10))) {
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    pWVar7 = (WDFREQUEST__ *)0x3;
    WPP_RECORDER_SF_sDs(uVar5,2,3,0x42,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x6d,
                        "FileObjectContextPtr->desiredAccess & GENERIC_READ");
    uVar4 = (uint)uVar5;
  }
  if (-1 < *(int *)(param_1 + 0x10)) {
    _RhpLogDebug(uVar4);
  }
  local_res10 = (_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *)0x0;
  lVar2 = RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT>
                    (param_2,&local_res10,(__uint64)pWVar7);
  if (lVar2 < 0) {
    pcVar3 = *(code **)(WdfFunctions_01015 + 0x838);
    goto LAB_1c001926d;
  }
  lVar1 = *(longlong *)param_1;
  lVar6 = lVar1;
  ExAcquirePushLockSharedEx(lVar1,2,lVar2);
  uVar4 = (uint)lVar6;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if ((*(uint *)(param_1 + 0x10) & 0x40000000) == 0) goto LAB_1c001939a;
    if (*(char *)(lVar1 + 0x88) == '\0') {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDs(uVar5,2,3,0x43,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x7d,
                          "(FileObjectContextPtr->desiredAccess & GENERIC_WRITE) ? lockedPinDescriptor->IsExclusive : true"
                         );
      uVar4 = (uint)uVar5;
    }
  }
  if (((*(uint *)(param_1 + 0x10) & 0x40000000) != 0) && (*(char *)(lVar1 + 0x88) == '\0')) {
    _RhpLogDebug(uVar4);
  }
LAB_1c001939a:
  if (*(longlong *)(lVar1 + 0x68) == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x44,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x82,
                          (char)*(undefined4 *)(lVar1 + 0x80));
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000184);
  }
  else {
    *(undefined4 *)local_res10 = *(undefined4 *)(lVar1 + 8);
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,4);
  }
  ExReleasePushLockSharedEx(lVar1,2);
  return;
}



===== ioctlRhproxyGpioPinRead @ 1c001946c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRead(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRead
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  long lVar1;
  code *pcVar2;
  long local_res10 [6];
  
  if (*(longlong *)param_1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x48,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",1,(char)this,(char)param_1);
    }
    lVar1 = -0x3fffff45;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    local_res10[0] = 0;
    lVar1 = readPinValue(param_1,local_res10);
    if (-1 < lVar1) {
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,(longlong)local_res10[0])
      ;
      return;
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  (*pcVar2)(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== ioctlRhproxyGpioPinRegisterInterruptBuffer @ 1c0019554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl
   RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRegisterInterruptBuffer(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRegisterInterruptBuffer
          (_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  code *pcVar5;
  ulonglong uVar6;
  int *local_res8 [2];
  ulonglong local_res18 [2];
  uint uStack_6c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  
  lVar1 = *(longlong *)param_1;
  ExAcquirePushLockExclusiveEx(lVar1,2);
  lVar2 = *(longlong *)(lVar1 + 0x60);
  if (lVar2 == 0) {
    iVar3 = -0x3fffff45;
LAB_1c0019598:
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    if (*(longlong *)(lVar2 + 0x20) != 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDi(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x50,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x48,
                            (char)*(longlong *)(lVar2 + 0x20));
      }
      iVar3 = -0x3fffffbc;
      goto LAB_1c0019598;
    }
    local_res8[0] = (int *)0x0;
    local_res18[0] = 0;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_2,0x38,local_res8,local_res18);
    if (-1 < iVar3) {
      iVar3 = *local_res8[0];
      uVar6 = (ulonglong)(((iVar3 + 0x40U >> 6) + iVar3) * 8 + 0x20);
      if (local_res18[0] < uVar6) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDPLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0xc0000023,uVar6);
      }
      else {
        local_res8[0][4] = 0;
        local_res8[0][5] = 0;
        puVar4 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,param_2,
                            PTR__WDF__RHP_GPIO_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT_TYPE_INFO_1c00100a0
                           );
        *(int **)(lVar2 + 0x10) = local_res8[0];
        *(int *)(lVar2 + 0x18) = iVar3;
        *(WDFREQUEST__ **)(lVar2 + 0x20) = param_2;
        *(undefined8 *)(lVar2 + 0x28) = *puVar4;
        *(undefined1 *)(lVar2 + 0x45) = 0;
        (**(code **)(WdfFunctions_01015 + 0x4d0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x70));
        pcVar5 = evtRegisterInterruptBufferRequestCancel;
        iVar3 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2);
        if (iVar3 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDqD
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar5,0x52,
                       &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x9f,(char)param_2,
                       (char)iVar3);
          }
          (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar3);
          uStack_50 = 0;
          local_48 = 0;
          uStack_44 = 0;
          KeInitializeSpinLock(&local_58);
          *(undefined8 *)(lVar2 + 0x10) = 0;
          *(ulonglong *)(lVar2 + 0x18) = (ulonglong)uStack_6c << 0x20;
          *(undefined8 *)(lVar2 + 0x20) = 0;
          *(undefined8 *)(lVar2 + 0x28) = 0;
          *(undefined8 *)(lVar2 + 0x30) = local_58;
          *(undefined8 *)(lVar2 + 0x38) = uStack_50;
          *(ulonglong *)(lVar2 + 0x40) = CONCAT26(uStack_42,CONCAT24(uStack_44,local_48));
        }
      }
      goto LAB_1c001985b;
    }
    pcVar5 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  (*pcVar5)(WdfDriverGlobals,param_2,iVar3);
LAB_1c001985b:
  ExReleasePushLockExclusiveEx(lVar1,2);
  return;
}



===== ioctlRhproxyGpioPinRegisterInterruptBufferInCallerContext @ 1c0019888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl
   RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRegisterInterruptBufferInCallerContext(struct WDFDEVICE__
   * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinRegisterInterruptBufferInCallerContext
          (RHP_GPIO_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  WDFREQUEST__ *pWVar4;
  undefined8 local_res20;
  _RHPROXY_GPIO_PIN_INTERRUPT_BUFFER *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined *local_20;
  
  local_58 = (_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER *)0x0;
  lVar1 = RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER>
                    (param_2,&local_58,(__uint64)param_2);
  if (-1 < lVar1) {
    local_res20 = 0;
    lVar1 = ObReferenceObjectByHandleWithTag
                      (*(undefined8 *)(local_58 + 8),0x1f0003,*(undefined8 *)ExEventObjectType_exref
                       ,1,0x34504852,&local_res20,0);
    if (-1 < lVar1) {
      local_4c = 0;
      local_40 = 0;
      local_58 = (_RHPROXY_GPIO_PIN_INTERRUPT_BUFFER *)0x0;
      local_20 = PTR__WDF__RHP_GPIO_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT_TYPE_INFO_1c00100a0;
      local_48 = _REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT::EvtCleanupCallback;
      local_30 = 0;
      uStack_28 = 0;
      local_50 = 0x38;
      local_38 = 1;
      local_34 = 1;
      pWVar4 = param_2;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_2,&local_50,&local_58);
      if (-1 < iVar2) {
        puVar3 = (undefined8 *)
                 (**(code **)(WdfFunctions_01015 + 0x650))
                           (WdfDriverGlobals,param_2,
                            PTR__WDF__RHP_GPIO_REGISTER_INTERRUPT_BUFFER_REQUEST_CONTEXT_TYPE_INFO_1c00100a0
                           );
        *puVar3 = local_res20;
        RHP_CONTROLLER::EvtIoInCallerContext((RHP_CONTROLLER *)this,param_1,param_2);
        return;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdq
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar4,1,0x4f,
                   &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x15,(char)iVar2,
                   (char)param_2);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
      ObfDereferenceObjectWithTag(local_res20,0x34504852);
      return;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== ioctlRhproxyGpioPinSetDriveMode @ 1c0019a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinSetDriveMode(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinSetDriveMode
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  int iVar2;
  _PIN_DESCRIPTOR *this_00;
  _INTERRUPT_CONTEXT *this_01;
  bool bVar3;
  uchar uVar4;
  long lVar5;
  int iVar6;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var7;
  longlong lVar8;
  code *pcVar9;
  uint uVar10;
  uint uVar11;
  _PIN_DESCRIPTOR *p_Var12;
  WDFREQUEST__ *pWVar13;
  long *plVar14;
  undefined8 uVar15;
  WDFREQUEST__ *pWVar16;
  int iVar17;
  long local_res10 [2];
  undefined *in_stack_ffffffffffffff98;
  char *in_stack_ffffffffffffffa0;
  
  uVar10 = 0xc000dda8;
  pWVar16 = param_2;
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     ((((*(uint *)(param_1 + 0x10) >> 0x1e & 1) == 0 || (*(int *)(param_1 + 0x14) != 0)) ||
      (*(longlong *)param_1 == 0)))) {
    in_stack_ffffffffffffffa0 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
    in_stack_ffffffffffffff98 = &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
    pWVar16 = (WDFREQUEST__ *)0x3;
    uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_sDs(uVar15,2,3,0x37,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x91,
                        "(FileObjectContextPtr->desiredAccess & GENERIC_WRITE) && !FileObjectContextPtr->shareAccess && !FileObjectContextPtr->isRootInterface()"
                       );
    uVar10 = (uint)uVar15;
  }
  if ((((*(uint *)(param_1 + 0x10) >> 0x1e & 1) == 0) || (*(int *)(param_1 + 0x14) != 0)) ||
     (*(longlong *)param_1 == 0)) {
    _RhpLogDebug(uVar10);
  }
  this_00 = *(_PIN_DESCRIPTOR **)param_1;
  p_Var12 = this_00;
  ExAcquirePushLockExclusiveEx(this_00,2);
  uVar10 = (uint)p_Var12;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
LAB_1c0019b94:
    if (this_00[0x88] == (_PIN_DESCRIPTOR)0x0) {
      _RhpLogDebug(uVar10);
    }
  }
  else if (this_00[0x88] == (_PIN_DESCRIPTOR)0x0) {
    in_stack_ffffffffffffffa0 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
    uVar15 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    pWVar16 = (WDFREQUEST__ *)0x3;
    in_stack_ffffffffffffff98 = &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
    WPP_RECORDER_SF_sDs(uVar15,2,3,0x38,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x96,
                        "lockedPinDescriptor->IsExclusive");
    uVar10 = (uint)uVar15;
    goto LAB_1c0019b94;
  }
  pWVar13 = param_2;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  uVar10 = *(uint *)(*(longlong *)(lVar8 + 0xb8) + 0x20);
  if (((uVar10 == 1) || (uVar10 == 2)) ||
     ((uVar10 == 4 ||
      ((((uVar10 == 8 || (uVar10 == 0x10)) || (uVar10 == 0x20)) ||
       ((uVar10 == 0x40 || (uVar10 == 0x80)))))))) {
    if ((uVar10 & *(uint *)(this + 0x2c)) == 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      uVar15 = 0xc00000bb;
    }
    else {
      uVar1 = *(uint *)(this_00 + 8);
      if (uVar1 == 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3b,
                              &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc9,
                              (char)*(undefined4 *)(this_00 + 0x80));
        }
        uVar15 = 0xc0000184;
      }
      else {
        if (uVar10 != uVar1) {
          if ((((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
              (uVar10 != 1)) &&
             (((uVar10 != 2 && ((uVar10 != 4 && (uVar10 != 8)))) &&
              ((uVar10 == 0x10 || (((uVar10 == 0x20 || (uVar10 == 0x40)) || (uVar10 == 0x80))))))))
          {
            in_stack_ffffffffffffffa0 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
            pWVar16 = (WDFREQUEST__ *)0x3;
            in_stack_ffffffffffffff98 = &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
            WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x3c,
                                &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd8,
                                "RhpGpioPinOutputDriveModeFromDriveMode(driveMode) == RHPROXY_GPIO_PIN_OUTPUT_DRIVE_MODE_CMOS"
                               );
          }
          if ((((uVar10 != 1) && (uVar10 != 2)) && ((uVar10 != 4 && (uVar10 != 8)))) &&
             (((uVar11 = 0, uVar10 == 0x10 || (uVar11 = 0, uVar10 == 0x20)) ||
              ((uVar11 = uVar10 - 0x40, uVar11 == 0 || (uVar11 == 0x40)))))) {
            _RhpLogDebug(uVar11);
          }
          this_01 = *(_INTERRUPT_CONTEXT **)(this_00 + 0x60);
          if ((this_01 != (_INTERRUPT_CONTEXT *)0x0) && ((*(uint *)this_01 & 3) != 0)) {
            _INTERRUPT_CONTEXT::DisableWdfInterrupt(this_01);
          }
          *(undefined4 *)(this_00 + 8) = 0;
          _PIN_DESCRIPTOR::deleteWdfIoTarget(this_00);
          if (((uVar10 == 1) || (uVar10 == 2)) || (uVar10 == 4)) {
            bVar3 = false;
            uVar4 = `anonymous_namespace'::acpiPullConfigFromRhproxyDriveMode(uVar10);
            pWVar16 = (WDFREQUEST__ *)CONCAT71((int7)((ulonglong)pWVar16 >> 8),uVar4);
            p_Var12 = this_00;
            lVar5 = updateResHubPullConfiguration(this,this_00,uVar4);
            if (-1 < lVar5) goto LAB_1c0019e95;
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDDDd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var12,pWVar16,0x3d,
                         in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,0xf3,
                         (char)*(undefined4 *)(this_00 + 0x80),(char)uVar10,(char)lVar5);
            }
          }
          else {
            bVar3 = true;
LAB_1c0019e95:
            p_Var12 = this_00;
            lVar5 = createWdfIoTarget(this,this_00);
            if (-1 < lVar5) {
              if ((((uVar1 == 1) || (uVar1 == 2)) || (uVar1 == 4)) &&
                 (this_01 != (_INTERRUPT_CONTEXT *)0x0)) {
                iVar17 = *(int *)(this_01 + 4);
              }
              else {
                iVar17 = *(int *)(this_00 + 0xc);
              }
              if (bVar3) {
                iVar2 = *(int *)(this_00 + 0xc);
                *(long **)(this_00 + 0x50) = local_res10;
                local_res10[0] = iVar2;
                iVar6 = (**(code **)(this_00 + 0x40))(this_00 + 0x48);
                if (-1 < iVar6) {
                  *(uint *)(this_00 + 8) = uVar10;
                  if ((this_01 != (_INTERRUPT_CONTEXT *)0x0) && (iVar2 != iVar17)) {
                    _INTERRUPT_CONTEXT::HandlePinValueChangedInterruptsDisabled(this_01,iVar2);
                  }
                  goto LAB_1c001a0a5;
                }
                if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDLd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var12,pWVar16,0x3f,
                             in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,0x1f,
                             (char)*(undefined4 *)(this_00 + 0x80),(char)iVar6);
                }
LAB_1c0019f80:
                pcVar9 = *(code **)(WdfFunctions_01015 + 0x838);
              }
              else {
                local_res10[0] = 0;
                plVar14 = local_res10;
                iVar6 = _PIN_DESCRIPTOR::ReadPinValue(this_00,plVar14);
                if (iVar6 < 0) {
                  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sDLd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar14,pWVar16,0x40,
                               in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,0x37,
                               (char)*(undefined4 *)(this_00 + 0x80),(char)iVar6);
                  }
                  goto LAB_1c0019f80;
                }
                *(uint *)(this_00 + 8) = uVar10;
                if ((this_01 == (_INTERRUPT_CONTEXT *)0x0) ||
                   (_Var7 = _INTERRUPT_CONTEXT::ComputeBestEdgeMode(*(undefined4 *)this_01),
                   _Var7 == 0)) {
LAB_1c001a0a5:
                  lVar5 = 0;
                  goto LAB_1c001a0a8;
                }
                iVar6 = _PIN_DESCRIPTOR::ConfigureInterrupt(this_00,_Var7,this);
                if (-1 < iVar6) {
                  if (local_res10[0] != iVar17) {
                    _INTERRUPT_CONTEXT::HandlePinValueChangedInterruptsDisabled
                              (this_01,local_res10[0]);
                  }
                  _INTERRUPT_CONTEXT::EnableWdfInterrupt(this_01,_Var7);
                  goto LAB_1c001a0a5;
                }
                pcVar9 = *(code **)(WdfFunctions_01015 + 0x838);
              }
              (*pcVar9)(WdfDriverGlobals,param_2,iVar6);
              *(undefined4 *)(this_00 + 8) = 0;
              _PIN_DESCRIPTOR::deleteWdfIoTarget(this_00);
              goto joined_r0x0001c001a0c8;
            }
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
          }
LAB_1c001a0a8:
          (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar5);
          goto joined_r0x0001c001a0c8;
        }
        uVar15 = 0;
      }
    }
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pWVar13,pWVar16,0x39,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xb3,
                 (char)*(undefined4 *)(this_00 + 0x80),(char)uVar10);
    }
    uVar15 = 0xc000000d;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar15);
joined_r0x0001c001a0c8:
  if (this_00 != (_PIN_DESCRIPTOR *)0x0) {
    ExReleasePushLockExclusiveEx(this_00,2);
  }
  return;
}



===== ioctlRhproxyGpioPinStartInterruptBuffer @ 1c001a100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStartInterruptBuffer(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStartInterruptBuffer
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  int iVar1;
  _PIN_DESCRIPTOR *this_00;
  _INTERRUPT_CONTEXT *this_01;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var5;
  ulonglong uVar6;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var7;
  _RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  
  local_res20 = (_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *)0x0;
  uVar2 = RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT>
                    (param_2,&local_res20,(__uint64)param_2);
  uVar6 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c001a148:
    (*pcVar4)(WdfDriverGlobals,param_2,uVar6);
    return;
  }
  iVar1 = *(int *)local_res20;
  if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 3)) {
    uVar6 = 0xc000000d;
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
    goto LAB_1c001a148;
  }
  this_00 = *(_PIN_DESCRIPTOR **)param_1;
  ExAcquirePushLockExclusiveEx(this_00,2);
  this_01 = *(_INTERRUPT_CONTEXT **)(this_00 + 0x60);
  if (this_01 == (_INTERRUPT_CONTEXT *)0x0) {
    lVar3 = -0x3fffff45;
  }
  else {
    uVar2 = *(uint *)this_01;
    if ((uVar2 & 0xc0) == 0) {
      if (*(longlong *)(this_01 + 0x20) != 0) {
        if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_sDLD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar2,uVar6,0x55,
                     in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0x17,
                     (char)*(undefined4 *)(this_00 + 0x80),(char)uVar2);
        }
        _Var5 = (iVar1 << 6 ^ *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01) & 0xc0 ^
                *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01;
        *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01 = _Var5;
        iVar1 = *(int *)(this_00 + 8);
        if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 4)) {
          _Var7 = _Var5 & 3;
          _Var5 = _INTERRUPT_CONTEXT::ComputeBestEdgeMode(_Var5);
          if (_Var5 != _Var7) {
            if (_Var7 != 0) {
              _INTERRUPT_CONTEXT::DisableWdfInterrupt(this_01);
            }
            lVar3 = _PIN_DESCRIPTOR::ConfigureInterrupt(this_00,_Var5,this);
            if (lVar3 < 0) {
              pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
              goto LAB_1c001a346;
            }
            _INTERRUPT_CONTEXT::EnableWdfInterrupt(this_01,_Var5);
          }
        }
        lVar3 = 0;
        goto LAB_1c001a338;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqL
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x54,in_stack_ffffffffffffffa8
                   ,in_stack_ffffffffffffffb0,0xe,(char)param_2,
                   (char)*(undefined4 *)(this_00 + 0x80));
      }
    }
    else if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x53,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",2,
                          (char)*(undefined4 *)(this_00 + 0x80));
    }
    lVar3 = -0x3ffffe7c;
  }
LAB_1c001a338:
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c001a346:
  (*pcVar4)(WdfDriverGlobals,param_2,lVar3);
  ExReleasePushLockExclusiveEx(this_00,2);
  return;
}



===== ioctlRhproxyGpioPinStartInterruptCount @ 1c001a388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStartInterruptCount(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStartInterruptCount
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  _RHPROXY_GPIO_INTERRUPT_MODE _Var1;
  int iVar2;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var3;
  _PIN_DESCRIPTOR *this_00;
  _INTERRUPT_CONTEXT *this_01;
  bool bVar4;
  uint uVar5;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var6;
  long lVar7;
  code *pcVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  _RHPROXY_GPIO_INTERRUPT_MODE _Var12;
  _RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 in_stack_ffffffffffffffb0;
  undefined1 uVar13;
  undefined1 uVar14;
  
  local_res20 = (_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT *)0x0;
  uVar5 = RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_START_INTERRUPT_BUFFER_INPUT>
                    (param_2,&local_res20,(__uint64)param_2);
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    pcVar8 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c001a3d4:
    (*pcVar8)(WdfDriverGlobals,param_2,uVar9);
    return;
  }
  _Var1 = *(_RHPROXY_GPIO_INTERRUPT_MODE *)local_res20;
  if (((_Var1 != 1) && (_Var1 != 2)) && (_Var1 != 3)) {
    uVar9 = 0xc000000d;
    pcVar8 = *(code **)(WdfFunctions_01015 + 0x838);
    goto LAB_1c001a3d4;
  }
  this_00 = *(_PIN_DESCRIPTOR **)param_1;
  ExAcquirePushLockExclusiveEx(this_00,2);
  this_01 = *(_INTERRUPT_CONTEXT **)(this_00 + 0x60);
  if (this_01 == (_INTERRUPT_CONTEXT *)0x0) {
    uVar10 = 0xc00000bb;
  }
  else {
    iVar2 = *(int *)(this_00 + 8);
    if (iVar2 == 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar14 = (undefined1)*(undefined4 *)(this_00 + 0x80);
        uVar11 = 0x4a;
        uVar13 = 0x5a;
LAB_1c001a49b:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar13,uVar14);
      }
    }
    else {
      if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 4)) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      _Var3 = *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01;
      if ((_Var3 & 0xc) == 0) {
        _Var12 = (_Var1 * 4 ^ _Var3) & 0xc ^ _Var3;
        if (bVar4) {
          *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01 = _Var12;
          uVar10 = 0;
          goto LAB_1c001a445;
        }
        _Var6 = _INTERRUPT_CONTEXT::ComputeBestEdgeMode(_Var12);
        if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_sDLD
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)*(uint *)(this_00 + 0x80)
                     ,uVar9,0x4c,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,0x85,
                     (char)*(uint *)(this_00 + 0x80),(char)_Var12);
        }
        if (_Var6 == (_Var3 & 3)) {
          _INTERRUPT_CONTEXT::SetInterruptCountModeSynchronized(this_01,_Var1);
LAB_1c001a604:
          lVar7 = 0;
          pcVar8 = *(code **)(WdfFunctions_01015 + 0x838);
        }
        else {
          if ((_Var3 & 3) != 0) {
            _INTERRUPT_CONTEXT::DisableWdfInterrupt(this_01);
          }
          *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01 =
               (*(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01 ^ _Var1 * 4) & 0xc ^
               *(_RHPROXY_GPIO_INTERRUPT_MODE *)this_01;
          lVar7 = _PIN_DESCRIPTOR::ConfigureInterrupt(this_00,_Var6,this);
          if (-1 < lVar7) {
            _INTERRUPT_CONTEXT::EnableWdfInterrupt(this_01,_Var6);
            goto LAB_1c001a604;
          }
          pcVar8 = *(code **)(WdfFunctions_01015 + 0x838);
        }
        (*pcVar8)(WdfDriverGlobals,param_2,lVar7);
        goto LAB_1c001a629;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar14 = (undefined1)*(undefined4 *)(this_00 + 0x80);
        uVar11 = 0x4b;
        uVar13 = 0x6b;
        goto LAB_1c001a49b;
      }
    }
    uVar10 = 0xc0000184;
  }
LAB_1c001a445:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar10);
LAB_1c001a629:
  ExReleasePushLockExclusiveEx(this_00,2);
  return;
}



===== ioctlRhproxyGpioPinStopInterruptBuffer @ 1c001a660 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStopInterruptBuffer(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStopInterruptBuffer
          (_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  _INTERRUPT_CONTEXT *this;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar2 = *(longlong *)param_1;
  ExAcquirePushLockExclusiveEx(lVar2,2);
  this = *(_INTERRUPT_CONTEXT **)(lVar2 + 0x60);
  if (this == (_INTERRUPT_CONTEXT *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar1 = *(uint *)this;
    if ((uVar1 & 0xc0) == 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x56,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x83,
                            (char)*(undefined4 *)(lVar2 + 0x80));
      }
      uVar3 = 0xc0000184;
    }
    else {
      if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_sDLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,0,0x57,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,0x8c,
                   (char)*(undefined4 *)(lVar2 + 0x80),(char)uVar1);
      }
      uVar1 = *(uint *)this;
      *(uint *)this = uVar1 & 0xffffff3f;
      if (((uVar1 & 3) != 0) && ((uVar1 & 0xffffff3c) == 0)) {
        _INTERRUPT_CONTEXT::DisableWdfInterrupt(this);
      }
      uVar3 = 0;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  ExReleasePushLockExclusiveEx(lVar2,2);
  return;
}



===== ioctlRhproxyGpioPinStopInterruptCount @ 1c001a7b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStopInterruptCount(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64) */

void __cdecl
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinStopInterruptCount
          (_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  uint uVar1;
  longlong lVar2;
  _INTERRUPT_CONTEXT *this;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar2 = *(longlong *)param_1;
  ExAcquirePushLockExclusiveEx(lVar2,2);
  this = *(_INTERRUPT_CONTEXT **)(lVar2 + 0x60);
  if (this == (_INTERRUPT_CONTEXT *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar1 = *(uint *)this;
    if ((uVar1 & 0xc) == 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x4d,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc0,
                            (char)*(undefined4 *)(lVar2 + 0x80));
      }
      uVar3 = 0xc0000184;
    }
    else {
      if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_sDLD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,0,0x4e,
                   in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,0xc9,
                   (char)*(undefined4 *)(lVar2 + 0x80),(char)uVar1);
      }
      uVar1 = *(uint *)this;
      *(uint *)this = uVar1 & 0xfffffff3;
      if (((uVar1 & 3) != 0) && ((uVar1 & 0xfffffff0) == 0)) {
        _INTERRUPT_CONTEXT::DisableWdfInterrupt(this);
      }
      uVar3 = 0;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  ExReleasePushLockExclusiveEx(lVar2,2);
  return;
}



===== ioctlRhproxyGpioPinValueRegisterNotification @ 1c001a908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinValueRegisterNotification(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT * __ptr64,struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinValueRegisterNotification
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2)

{
  _PIN_DESCRIPTOR *this_00;
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  RHP_GPIO_CONTROLLER *pRVar5;
  _NOTIFICATION_ENTRY *p_Var6;
  ulonglong uVar7;
  WDFREQUEST__ *pWVar8;
  _RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT *local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar10;
  undefined8 uVar9;
  undefined8 *puVar11;
  undefined8 local_28;
  _RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *local_20;
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  if (*(longlong *)param_1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x45,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x9c,(char)this,(char)param_2);
    }
    uVar7 = 0xc00000bb;
    pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
    goto LAB_1c001a995;
  }
  pRVar5 = this;
  pWVar8 = param_2;
  if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (-1 < *(int *)(param_1 + 0x10))) {
    pWVar8 = (WDFREQUEST__ *)0x3;
    pRVar5 = *(RHP_GPIO_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
    uVar10 = 1;
    WPP_RECORDER_SF_sDs(pRVar5,2,3,0x46,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xa1,
                        "FileObjectContextPtr->desiredAccess & GENERIC_READ");
  }
  if (-1 < *(int *)(param_1 + 0x10)) {
    _RhpLogDebug((uint)pRVar5);
  }
  local_res20 = (_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT *)0x0;
  uVar1 = RhpWdfRequestRetrieveInputBuffer<_RHPROXY_GPIO_PIN_VALUE_REGISTER_NOTIFICATION_INPUT>
                    (param_2,&local_res20,(__uint64)pWVar8);
  uVar7 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    local_20 = (_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT *)0x0;
    uVar1 = RhpWdfRequestRetrieveOutputBuffer<_RHPROXY_GPIO_PIN_GET_DRIVE_MODE_OUTPUT>
                      (param_2,&local_20,uVar7);
    uVar7 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      this_00 = *(_PIN_DESCRIPTOR **)param_1;
      ExAcquirePushLockExclusiveEx(this_00,2,uVar7);
      if (*(longlong *)(this_00 + 0x60) == 0) {
        iVar2 = -0x3fffff45;
LAB_1c001aa88:
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
      }
      else {
        if (*(longlong *)(param_1 + 0x28) != 0) {
          iVar2 = -0x3fffffbc;
          goto LAB_1c001aa88;
        }
        puVar11 = &local_28;
        local_28 = 0;
        uVar9 = CONCAT44(uVar10,0x34504852);
        iVar2 = ObReferenceObjectByHandleWithTag
                          (*(undefined8 *)local_res20,0x1f0003,
                           *(undefined8 *)ExSemaphoreObjectType_exref,1,uVar9,puVar11,0);
        if (-1 < iVar2) {
          p_Var6 = (_NOTIFICATION_ENTRY *)(param_1 + 0x18);
          *(undefined8 *)(param_1 + 0x28) = local_28;
          lVar3 = _PIN_DESCRIPTOR::RegisterNotificationEntry(this_00,p_Var6,this,(ulong *)local_20);
          if (lVar3 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDLd
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var6,this,0x47,uVar9,puVar11,
                         0xe8,(char)lVar3,(char)*(undefined4 *)(this_00 + 0x80));
            }
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar3);
            ObfDereferenceObjectWithTag(*(undefined8 *)(param_1 + 0x28),0x34504852);
            *(undefined8 *)(param_1 + 0x28) = 0;
          }
          else {
            (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,4);
          }
          goto LAB_1c001abd5;
        }
        pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
      }
      (*pcVar4)(WdfDriverGlobals,param_2,iVar2);
LAB_1c001abd5:
      ExReleasePushLockExclusiveEx(this_00,2);
      return;
    }
  }
  pcVar4 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_1c001a995:
  (*pcVar4)(WdfDriverGlobals,param_2,uVar7);
  return;
}



===== ioctlRhproxyGpioPinWrite @ 1c001ac08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinWrite(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,struct WDFREQUEST__ * __ptr64,long)
   __ptr64 */

void __thiscall
RHP_GPIO_CONTROLLER::ioctlRhproxyGpioPinWrite
          (RHP_GPIO_CONTROLLER *this,_FILE_OBJECT_CONTEXT *param_1,WDFREQUEST__ *param_2,
          long param_3)

{
  long lVar1;
  code *pcVar2;
  
  if (*(longlong *)param_1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x49,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x24,(char)this,(char)param_1);
    }
    lVar1 = -0x3fffff45;
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    lVar1 = writePinValue(param_1,param_3);
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  (*pcVar2)(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== parseConnectionResource @ 1c001acc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::parseConnectionResource(struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,struct _ACPI_EVAL_OUTPUT_BUFFER_V1 const *
   __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::parseConnectionResource
          (RHP_GPIO_CONTROLLER *this,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_1,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_2)

{
  RHP_GPIO_CONTROLLER *this_00;
  long lVar1;
  _PIN_DESCRIPTOR *p_Var2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined1 auStackY_f8 [32];
  ulonglong *in_stack_ffffffffffffff28;
  char *in_stack_ffffffffffffff30;
  undefined1 uVar7;
  ulonglong local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  wchar_t awStack_78 [7];
  undefined1 uStack_69;
  undefined1 uStack_68;
  undefined7 uStack_67;
  wchar_t local_60 [8];
  undefined8 local_50;
  undefined2 local_48;
  ulonglong local_40;
  
  this_00 = singletonPtr;
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  if ((*(short *)(singletonPtr + 0x1a) == 0) && (param_2 != (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0)) {
    local_48 = 0;
    local_50 = 0x4f004900500047;
    local_88 = &local_50;
    local_98 = &local_80;
    local_80._0_2_ = L'U';
    local_80._2_2_ = L's';
    local_80._4_2_ = L'e';
    local_80._6_2_ = L'D';
    awStack_78[0] = L'e';
    awStack_78[1] = L's';
    awStack_78[2] = L'c';
    awStack_78[3] = L'r';
    local_90 = 0xa0008;
    local_a0 = 0x30002e;
    awStack_78[4] = 0x69;
    stack0xffffffffffffff92 = 0x6f00740070;
    uStack_69 = 0;
    uStack_68 = 0x72;
    uStack_67 = 0x6e0069005000;
    local_a8 = local_a8 & 0xffffffff00000000;
    builtin_wcsncpy(local_60,L"Numbers",8);
    lVar1 = parseDsdPropertyULong
                      (this,param_2,(_UNICODE_STRING *)&local_90,(_UNICODE_STRING *)&local_a0,
                       (ulong *)&local_a8);
    if (lVar1 == -0x3ffffddb) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        if (this_00[0x28] == (RHP_GPIO_CONTROLLER)0x0) goto LAB_1c001ae3c;
        in_stack_ffffffffffffff30 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
        this = *(RHP_GPIO_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDs(this,2,3,0x5a,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xdc,
                            "this->useGpioIoDescriptorPinNumbers == false");
      }
      if (this_00[0x28] != (RHP_GPIO_CONTROLLER)0x0) {
        _RhpLogDebug((uint)this);
      }
    }
    else {
      if (lVar1 != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffffff;
        }
        uVar6 = 0x5b;
        uVar7 = 0xe1;
        goto LAB_1c001b15e;
      }
      this_00[0x28] = (RHP_GPIO_CONTROLLER)((int)local_a8 != 0);
    }
LAB_1c001ae3c:
    builtin_wcsncpy(awStack_78,L"ount",5);
    local_98 = &local_80;
    local_a0 = 0x120010;
    local_a8 = local_a8 & 0xffffffff00000000;
    local_80._0_2_ = L'P';
    local_80._2_2_ = L'i';
    local_80._4_2_ = L'n';
    local_80._6_2_ = L'C';
    lVar1 = parseDsdPropertyULong
                      (this,param_2,(_UNICODE_STRING *)&local_90,(_UNICODE_STRING *)&local_a0,
                       (ulong *)&local_a8);
    if (lVar1 == -0x3ffffddb) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        if (*(short *)(this_00 + 0x2a) == 0) goto LAB_1c001af3b;
        in_stack_ffffffffffffff30 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
        this = *(RHP_GPIO_CONTROLLER **)(WPP_GLOBAL_Control + 0x40);
        WPP_RECORDER_SF_sDs(this,2,3,0x5d,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xfb,
                            "this->dsdPinCount == 0");
      }
      if (*(short *)(this_00 + 0x2a) != 0) {
        _RhpLogDebug((uint)this);
      }
    }
    else {
      if (lVar1 != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffffff;
        }
        uVar6 = 0x5e;
        uVar7 = 0;
        goto LAB_1c001b15e;
      }
      this = (RHP_GPIO_CONTROLLER *)(local_a8 & 0xffffffff);
      if (0xfffe < (int)local_a8 - 1U) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffe7e;
        }
        uVar6 = 0x5c;
        uVar7 = 0xf5;
        goto LAB_1c001afe3;
      }
      *(short *)(this_00 + 0x2a) = (short)local_a8;
    }
LAB_1c001af3b:
    local_98 = &local_80;
    in_stack_ffffffffffffff28 = &local_a8;
    local_80._0_2_ = L'S';
    local_80._2_2_ = L'u';
    local_80._4_2_ = L'p';
    local_80._6_2_ = L'p';
    awStack_78[0] = L'o';
    awStack_78[1] = L'r';
    awStack_78[2] = L't';
    awStack_78[3] = L'e';
    local_a0 = 0x280026;
    builtin_wcsncpy(local_60,L"des",4);
    awStack_78[4] = 100;
    stack0xffffffffffffff92 = 0x6900720044;
    uStack_69 = 0;
    uStack_68 = 0x76;
    uStack_67 = 0x6f004d006500;
    local_a8 = local_a8 & 0xffffffff00000000;
    lVar1 = parseDsdPropertyULong
                      (this,param_2,(_UNICODE_STRING *)&local_90,(_UNICODE_STRING *)&local_a0,
                       (ulong *)in_stack_ffffffffffffff28);
    uVar3 = (uint)this;
    if (lVar1 == -0x3ffffddb) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        if (*(int *)(this_00 + 0x2c) == 9) goto LAB_1c001b0b4;
        in_stack_ffffffffffffff30 = "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp";
        uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        in_stack_ffffffffffffff28 = (ulonglong *)&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids;
        WPP_RECORDER_SF_sDs(uVar4,2,3,0x61,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x28,
                            "this->supportedDriveModes == _SUPPORTED_DRIVE_MODES_DEFAULT");
        uVar3 = (uint)uVar4;
      }
      if (*(int *)(this_00 + 0x2c) != 9) {
        _RhpLogDebug(uVar3);
      }
    }
    else {
      if (lVar1 != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3fffffff;
        }
        uVar6 = 0x62;
        uVar7 = 0x2d;
        goto LAB_1c001b15e;
      }
      if ((local_a8 & 0xffffff00) != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffe7e;
        }
        uVar6 = 0x5f;
        uVar7 = 0x16;
LAB_1c001afe3:
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar7,(char)local_a8
                           );
        return -0x3ffffe7e;
      }
      if ((local_a8 & 0xfffffff0) != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x60,
                              &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x21,
                              (char)local_a8);
        }
        return -0x3fffff45;
      }
      *(int *)(this_00 + 0x2c) = (int)local_a8;
    }
  }
LAB_1c001b0b4:
  local_a8 = *(ulonglong *)(param_1 + 8);
  if (this_00[0x28] == (RHP_GPIO_CONTROLLER)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    awStack_78[4] = 0;
    stack0xffffffffffffff92 = 0;
    uStack_69 = 0;
    uStack_68 = 0;
    local_80._0_2_ = L'\0';
    local_80._2_2_ = L'\0';
    local_80._4_2_ = L'\0';
    local_80._6_2_ = L'\0';
    awStack_78[0] = L'\0';
    awStack_78[1] = L'\0';
    awStack_78[2] = L'\0';
    awStack_78[3] = L'\0';
    lVar1 = queryResHubAcpiDescriptor
                      (this_00,(_LARGE_INTEGER *)&local_a8,
                       (SINGLE_PIN_PNP_GPIO_INTERRUPT_IO_DESCRIPTOR *)&local_80);
    if (lVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffff;
      }
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x66,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x60,(char)lVar1);
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffff;
      }
      lVar1 = -0x3fffffff;
      uVar6 = 99;
      uVar7 = 0x3c;
LAB_1c001b15e:
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar7,(char)lVar1);
      return -0x3fffffff;
    }
    uVar5 = (ulonglong)CONCAT11(uStack_68,uStack_69);
  }
  p_Var2 = _PIN_DESCRIPTOR_INDEX::CreateDescriptor
                     ((_PIN_DESCRIPTOR_INDEX *)(this_00 + 0x18),local_a8);
  if (p_Var2 == (_PIN_DESCRIPTOR *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffffff;
    }
    WPP_RECORDER_SF_sDqL
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,100,in_stack_ffffffffffffff28,
               in_stack_ffffffffffffff30,0x47,(char)this_00,(char)*(undefined2 *)(this_00 + 0x1a));
    return -0x3fffffff;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(this_00 + 0x1a) != -1) {
      return 0;
    }
    WPP_RECORDER_SF_sDs(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),1,4,0x65,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x4a,
                        "this->pinDescriptorsIndex.Count() < this->_PIN_ID_ROOT_INTERFACE");
  }
  if (*(short *)(this_00 + 0x1a) == -1) {
                    /* WARNING: Subroutine does not return */
    _RhpLogBugcheck();
  }
  return 0;
}



===== parseDsdPropertyULong @ 1c001b268 =====

/* private: long __cdecl RHP_GPIO_CONTROLLER::parseDsdPropertyULong(struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64,struct _UNICODE_STRING const & __ptr64,struct
   _UNICODE_STRING const & __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::parseDsdPropertyULong
          (RHP_GPIO_CONTROLLER *this,_ACPI_EVAL_OUTPUT_BUFFER_V1 *param_1,_UNICODE_STRING *param_2,
          _UNICODE_STRING *param_3,ulong *param_4)

{
  long lVar1;
  _ACPI_METHOD_ARGUMENT_V1 *local_res8;
  
  local_res8 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
  lVar1 = RHP_CONTROLLER::RetrieveDsdArguments
                    ((_ACPI_METHOD_ARGUMENT_V1 *)(param_1 + 0xc),*(int *)(param_1 + 4) - 0xc,
                     &local_res8);
  if (lVar1 == -0x3ffffddb) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x58,
                         &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xac);
    }
    lVar1 = -0x3ffffddb;
  }
  else if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x59,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xb1,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  else {
    lVar1 = RHP_CONTROLLER::ParsePropertyUlong(local_res8,param_2,param_3,param_4);
  }
  return lVar1;
}



===== parseInterruptResource @ 1c001b374 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_GPIO_CONTROLLER::parseInterruptResource(struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,struct _CM_PARTIAL_RESOURCE_DESCRIPTOR const *
   __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::parseInterruptResource
          (RHP_GPIO_CONTROLLER *this,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_1,
          _CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2)

{
  undefined4 uVar1;
  RHP_GPIO_CONTROLLER *pRVar2;
  int iVar3;
  _PIN_DESCRIPTOR *p_Var4;
  undefined8 *puVar5;
  RHP_GPIO_CONTROLLER *local_res8;
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
  code *local_78;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *local_58;
  _CM_PARTIAL_RESOURCE_DESCRIPTOR *local_50;
  undefined4 local_3c;
  
  pRVar2 = singletonPtr;
  if ((*(short *)(singletonPtr + 0x1a) == 0) ||
     (local_res8 = this,
     p_Var4 = _PIN_DESCRIPTOR_INDEX::operator[]
                        ((_PIN_DESCRIPTOR_INDEX *)(singletonPtr + 0x18),
                         *(short *)(singletonPtr + 0x1a) - 1), *(longlong *)(p_Var4 + 0x60) != 0)) {
    return -0x3ffffe7e;
  }
  memset(local_98,0,0x68);
  local_98[0] = 0x68;
  local_80 = evtInterruptIsr;
  local_88 = 2;
  local_c8 = 0;
  local_3c = 2;
  local_78 = evtInterruptDpc;
  local_a8 = PTR__WDF__RHP_GPIO_CONTROLLER_INTERRUPT_CONTEXT_TYPE_INFO_1c00100c8;
  uStack_d0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_d8 = 0x38;
  uStack_c0 = 0x100000001;
  local_res8 = (RHP_GPIO_CONTROLLER *)0x0;
  local_58 = param_1;
  local_50 = param_2;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x468))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(pRVar2 + 8) + 8),local_98,
                     &local_d8,&local_res8);
  if (-1 < iVar3) {
    (**(code **)(WdfFunctions_01015 + 0x498))(WdfDriverGlobals,local_res8);
    puVar5 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF__RHP_GPIO_CONTROLLER_INTERRUPT_CONTEXT_TYPE_INFO_1c00100c8);
    pRVar2 = local_res8;
    uVar1 = *(undefined4 *)(param_1 + 8);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *(undefined4 *)(puVar5 + 3) = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[7] = 0;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined2 *)((longlong)puVar5 + 0x44) = 0;
    KeInitializeSpinLock(puVar5 + 6);
    puVar5[9] = p_Var4;
    *(undefined4 *)(puVar5 + 10) = uVar1;
    puVar5[0xb] = pRVar2;
    _INTERRUPT_CONTEXT::_NOTIFICATION::_NOTIFICATION((_NOTIFICATION *)(puVar5 + 0xc));
    *(undefined8 **)(p_Var4 + 0x60) = puVar5;
    return 0;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x69,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x9e,(char)iVar3);
  }
  return -0x3fffffff;
}



===== parseWdfFileObjectFileName @ 1c001b59c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl RHP_GPIO_CONTROLLER::parseWdfFileObjectFileName(struct WDFFILEOBJECT__ *
   __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::parseWdfFileObjectFileName
          (RHP_GPIO_CONTROLLER *this,WDFFILEOBJECT__ *param_1,ulong *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  _UNICODE_STRING *p_Var5;
  uint uVar6;
  undefined8 uVar7;
  RHP_DEVICE *this_00;
  wchar_t *pwVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  undefined2 uVar11;
  longlong lVar12;
  undefined8 in_stack_ffffffffffffff98;
  undefined8 in_stack_ffffffffffffffa0;
  undefined1 uVar13;
  
  uVar7 = WdfDriverGlobals;
  puVar4 = (ushort *)(**(code **)(WdfFunctions_01015 + 0x448))();
  uVar6 = (uint)uVar7;
  lVar12 = 0;
  if (puVar4 == (ushort *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqq
                (uVar7,2,3,0x6a,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xbe,(char)this,(char)param_1);
      uVar6 = (uint)uVar7;
    }
    goto LAB_1c001b9f6;
  }
  this_00 = *(RHP_DEVICE **)(this + 8);
  p_Var5 = RHP_DEVICE::GetReferenceStringFromWdfFileObject(this_00,param_1);
  uVar6 = (uint)this_00;
  if (p_Var5 == (_UNICODE_STRING *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqqS(uVar7);
      uVar6 = (uint)uVar7;
    }
    goto LAB_1c001b9f6;
  }
  if ((*puVar4 < 2) || (**(short **)(puVar4 + 4) != 0x5c)) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDS(uVar7,2,3,0x6c,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd4,
                          *(wchar_t **)(puVar4 + 4));
      uVar6 = (uint)uVar7;
    }
    goto LAB_1c001b9f6;
  }
  pwVar10 = *(wchar_t **)(puVar4 + 4);
  uVar1 = (ushort)*(undefined4 *)puVar4;
  if ((1 < uVar1) && (*pwVar10 == L'\\')) {
    uVar1 = uVar1 - 2;
    pwVar10 = pwVar10 + 1;
  }
  uVar6 = (uint)(*(ushort *)p_Var5 >> 1);
  if (uVar1 >> 1 < uVar6) {
LAB_1c001b96f:
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001b9f6;
    pwVar10 = *(wchar_t **)(p_Var5 + 8);
    uVar11 = 0x6d;
    pwVar8 = *(wchar_t **)(puVar4 + 4);
    uVar13 = 0xde;
  }
  else {
    pwVar8 = pwVar10;
    iVar2 = _wcsnicmp(pwVar10,*(wchar_t **)(p_Var5 + 8),(ulonglong)uVar6);
    uVar6 = (uint)pwVar8;
    if (iVar2 != 0) goto LAB_1c001b96f;
    uVar6 = (*(uint *)p_Var5 & 0xffff) >> 1;
    uVar1 = uVar1 + (short)uVar6 * -2;
    if (uVar1 < 2) {
      *param_2 = 0xffffffff;
      return 0;
    }
    if (pwVar10[uVar6] == L'\\') {
      if (((uVar1 - 2 & 0xfffe) < 6) ||
         (iVar2 = _wcsnicmp(pwVar10 + (ulonglong)uVar6 + 1,L"PIN",3), iVar2 != 0)) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffddb;
        }
        pwVar10 = *(wchar_t **)(p_Var5 + 8);
        uVar11 = 0x6f;
        pwVar8 = *(wchar_t **)(puVar4 + 4);
        uVar13 = 1;
      }
      else if (((ushort)(uVar1 - 8) < 2) || (pwVar10[(ulonglong)uVar6 + 4] != L'\\')) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffddb;
        }
        pwVar10 = *(wchar_t **)(p_Var5 + 8);
        uVar11 = 0x70;
        pwVar8 = *(wchar_t **)(puVar4 + 4);
        uVar13 = 0xd;
      }
      else {
        if (1 < (ushort)(uVar1 - 10)) {
          uVar3 = (uint)((ushort)(uVar1 - 10) >> 1);
          if (uVar3 != 0) {
            lVar9 = 0;
            do {
              if (9 < (ushort)(pwVar10[(ulonglong)uVar6 + lVar9 + 5] + L'￐')) {
                if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return -0x3ffffddb;
                }
                pwVar10 = *(wchar_t **)(p_Var5 + 8);
                uVar11 = 0x72;
                pwVar8 = *(wchar_t **)(puVar4 + 4);
                uVar13 = 0x26;
                goto LAB_1c001b8fc;
              }
              lVar12 = (ulonglong)(ushort)pwVar10[(ulonglong)uVar6 + lVar9 + 5] +
                       (lVar12 * 5 + -0x18) * 2;
              if (*(int *)(this + 0x1c) < lVar12) {
                if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return -0x3ffffddb;
                }
                pwVar10 = *(wchar_t **)(p_Var5 + 8);
                uVar11 = 0x73;
                pwVar8 = *(wchar_t **)(puVar4 + 4);
                uVar13 = 0x30;
                goto LAB_1c001b8fc;
              }
              lVar9 = lVar9 + 1;
            } while (lVar9 < (longlong)(ulonglong)uVar3);
          }
          *param_2 = (ulong)lVar12;
          return 0;
        }
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3ffffddb;
        }
        pwVar10 = *(wchar_t **)(p_Var5 + 8);
        uVar11 = 0x71;
        pwVar8 = *(wchar_t **)(puVar4 + 4);
        uVar13 = 0x1b;
      }
LAB_1c001b8fc:
      WPP_RECORDER_SF_sDSS
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar11,in_stack_ffffffffffffff98,
                 in_stack_ffffffffffffffa0,uVar13,pwVar8,pwVar10);
      return -0x3ffffddb;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c001b9f6;
    pwVar10 = *(wchar_t **)(p_Var5 + 8);
    uVar11 = 0x6e;
    pwVar8 = *(wchar_t **)(puVar4 + 4);
    uVar13 = 0xf3;
  }
  uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  WPP_RECORDER_SF_sDSS
            (uVar7,2,3,uVar11,in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,uVar13,pwVar8,
             pwVar10);
  uVar6 = (uint)uVar7;
LAB_1c001b9f6:
  _RhpLogDebug(uVar6);
  return -0x3fffff1b;
}



===== queryResHubAcpiDescriptor @ 1c001ba28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::queryResHubAcpiDescriptor(union _LARGE_INTEGER const &
   __ptr64,struct SINGLE_PIN_PNP_GPIO_INTERRUPT_IO_DESCRIPTOR * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::queryResHubAcpiDescriptor
          (RHP_GPIO_CONTROLLER *this,_LARGE_INTEGER *param_1,
          SINGLE_PIN_PNP_GPIO_INTERRUPT_IO_DESCRIPTOR *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  void *pvVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 auStackY_a8 [32];
  __uint64 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_48 = *(undefined8 *)param_1;
  local_4c = 0;
  uVar11 = 0x97;
  local_50 = 1;
  iVar10 = 2;
  iVar8 = 0x9f;
  while( true ) {
    pvVar6 = (void *)ExAllocatePoolWithTag(1,iVar8,0x30504852);
    if (pvVar6 == (void *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x78,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xa9,
                            (char)uVar11 + '\b');
      }
      return -0x3fffffe9;
    }
    local_58 = 0;
    lVar5 = RhpSendIoctlSynchronously
                      (*(WDFIOTARGET__ **)(*(longlong *)(this + 8) + 0x18),0x2ac000,&local_50,0x10,
                       pvVar6,uVar11 + 8,&local_58);
    if (lVar5 != -0x3fffffdd) break;
    iVar10 = iVar10 + -1;
    if ((iVar10 == 0) || (local_58 < 8)) {
LAB_1c001bb88:
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x79,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xc6,(char)lVar5);
      }
      goto LAB_1c001bd01;
    }
    uVar9 = *(uint *)((longlong)pvVar6 + 4);
    if (*(uint *)((longlong)pvVar6 + 4) <= uVar11) {
      uVar9 = uVar11;
    }
    uVar11 = uVar9;
    ExFreePoolWithTag(pvVar6,0x30504852);
    iVar8 = uVar11 + 8;
  }
  if (lVar5 != 0) goto LAB_1c001bb88;
  uVar11 = *(uint *)((longlong)pvVar6 + 4);
  uVar9 = uVar11 + 8;
  if (local_58 < uVar9) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDLL
                (uVar7,(ulonglong)uVar9,local_58,0x7a,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd1,(char)local_58,(char)uVar9
                );
      uVar11 = (uint)uVar7;
    }
    _RhpLogDebug(uVar11);
    lVar5 = -0x3fffff1b;
    goto LAB_1c001bd06;
  }
  if (uVar11 < 0x19) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x7b,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xdc,(char)uVar11);
    }
  }
  else {
    uVar1 = *(ushort *)((longlong)pvVar6 + 0x16);
    if (uVar1 == 0x17) {
      uVar2 = *(undefined4 *)((longlong)pvVar6 + 0xc);
      uVar3 = *(undefined4 *)((longlong)pvVar6 + 0x10);
      uVar4 = *(undefined4 *)((longlong)pvVar6 + 0x14);
      *(undefined4 *)param_2 = *(undefined4 *)((longlong)pvVar6 + 8);
      *(undefined4 *)(param_2 + 4) = uVar2;
      *(undefined4 *)(param_2 + 8) = uVar3;
      *(undefined4 *)(param_2 + 0xc) = uVar4;
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)((longlong)pvVar6 + 0x18);
      param_2[0x18] = *(SINGLE_PIN_PNP_GPIO_INTERRUPT_IO_DESCRIPTOR *)((longlong)pvVar6 + 0x20);
      ExFreePoolWithTag(pvVar6,0x30504852);
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar1,local_58,0x7c,
                 &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xec,(char)uVar1,(char)uVar11);
    }
  }
LAB_1c001bd01:
  lVar5 = -0x3fffffff;
LAB_1c001bd06:
  ExFreePoolWithTag(pvVar6,0x30504852);
  return lVar5;
}



===== queryResHubInterruptProperties @ 1c001bd58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::queryResHubInterruptProperties(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::queryResHubInterruptProperties
          (RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1)

{
  uint uVar1;
  long lVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 auStackY_98 [32];
  __uint64 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  local_34 = 0;
  uVar4 = 0x97;
  local_40 = 1;
  local_3c = 1;
  iVar7 = 2;
  local_38 = *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x50);
  iVar6 = 0x9f;
  while( true ) {
    pvVar3 = (void *)ExAllocatePoolWithTag(1,iVar6,0x30504852);
    if (pvVar3 == (void *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x7d,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x15,
                            (char)uVar4 + '\b');
      }
      return -0x3fffffe9;
    }
    local_48 = 0;
    puVar8 = &local_40;
    lVar2 = RhpSendIoctlSynchronously
                      (*(WDFIOTARGET__ **)(*(longlong *)(this + 8) + 0x18),0x2ac000,puVar8,0x10,
                       pvVar3,uVar4 + 8,&local_48);
    if (lVar2 != -0x3fffffdd) break;
    iVar7 = iVar7 + -1;
    if ((iVar7 == 0) || (local_48 < 8)) {
LAB_1c001bed1:
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x7e,
                            &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x32,(char)lVar2);
      }
      goto LAB_1c001bfec;
    }
    uVar1 = *(uint *)((longlong)pvVar3 + 4);
    if (*(uint *)((longlong)pvVar3 + 4) <= uVar4) {
      uVar1 = uVar4;
    }
    uVar4 = uVar1;
    ExFreePoolWithTag(pvVar3,0x30504852);
    iVar6 = uVar4 + 8;
  }
  if (lVar2 != 0) goto LAB_1c001bed1;
  uVar4 = *(int *)((longlong)pvVar3 + 4) + 8;
  if (local_48 < uVar4) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDLL
                (uVar5,local_48,puVar8,0x7f,&WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x3d,(char)local_48,(char)uVar4
                );
      uVar4 = (uint)uVar5;
    }
    _RhpLogDebug(uVar4);
    lVar2 = -0x3fffff1b;
    goto LAB_1c001bff1;
  }
  if (*(char *)((longlong)pvVar3 + 0xc) == '\0') {
    param_1[0x90] = (_PIN_DESCRIPTOR)(*(byte *)((longlong)pvVar3 + 0xf) & 1);
    param_1[0x91] = (_PIN_DESCRIPTOR)(*(byte *)((longlong)pvVar3 + 0xf) & 6);
    *(undefined2 *)(param_1 + 0x92) = *(undefined2 *)((longlong)pvVar3 + 0x14);
    ExFreePoolWithTag(pvVar3,0x30504852);
    return 0;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x80,
                        &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x4e,
                        *(char *)((longlong)pvVar3 + 0xc));
  }
LAB_1c001bfec:
  lVar2 = -0x3fffffff;
LAB_1c001bff1:
  ExFreePoolWithTag(pvVar3,0x30504852);
  return lVar2;
}



===== queryResHubPinProperties @ 1c001c04c =====

/* private: long __cdecl RHP_GPIO_CONTROLLER::queryResHubPinProperties(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR * __ptr64) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::queryResHubPinProperties(RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1)

{
  long lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined1 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lVar1 = queryResHubAcpiDescriptor
                    (this,(_LARGE_INTEGER *)(param_1 + 0x78),
                     (SINGLE_PIN_PNP_GPIO_INTERRUPT_IO_DESCRIPTOR *)&local_28);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x77,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x7f,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  else {
    param_1[0x8a] = uStack_20._1_1_;
    param_1[0x8b] = uStack_20._1_1_;
    *(undefined2 *)(param_1 + 0x8c) = uStack_20._2_2_;
    *(undefined2 *)(param_1 + 0x8e) = uStack_20._4_2_;
    lVar1 = 0;
  }
  return lVar1;
}



===== readPinValue @ 1c001c108 =====

/* private: static long __cdecl RHP_GPIO_CONTROLLER::readPinValue(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,long * __ptr64) */

long __cdecl RHP_GPIO_CONTROLLER::readPinValue(_FILE_OBJECT_CONTEXT *param_1,long *param_2)

{
  int iVar1;
  _PIN_DESCRIPTOR *this;
  long lVar2;
  
  this = *(_PIN_DESCRIPTOR **)param_1;
  ExAcquirePushLockSharedEx(this,2);
  iVar1 = *(int *)(this + 8);
  lVar2 = 0;
  if (iVar1 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x8b,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xa1,
                          (char)*(undefined4 *)(this + 0x80));
    }
    lVar2 = -0x3ffffe7c;
  }
  else if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 4)) {
    lVar2 = _PIN_DESCRIPTOR::ReadPinValue(this,param_2);
  }
  else {
    *param_2 = *(long *)(this + 0xc);
  }
  ExReleasePushLockSharedEx(this,2);
  return lVar2;
}



===== updateResHubInitialPolarity @ 1c001c1f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::updateResHubInitialPolarity(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR const * __ptr64,long) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::updateResHubInitialPolarity
          (RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1,long param_2)

{
  long lVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 uStack_1c;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_18 = (uint)(param_2 != 0);
  _local_20 = CONCAT44(*(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x50),1);
  local_28[0] = 1;
  lVar1 = RhpSendIoctlSynchronously
                    (*(WDFIOTARGET__ **)(*(longlong *)(this + 8) + 0x18),0x2ac014,&local_20,0xc,
                     local_28,4,(__uint64 *)0x0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x85,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0x28,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  return lVar1;
}



===== updateResHubInterruptPullConfiguration @ 1c001c2e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::updateResHubInterruptPullConfiguration(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR const * __ptr64,unsigned char) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::updateResHubInterruptPullConfiguration
          (RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1,uchar param_2)

{
  long lVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_24;
  _PIN_DESCRIPTOR local_22;
  _PIN_DESCRIPTOR local_21;
  uchar local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined8 local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_1c = 0;
  local_14 = 0;
  local_1f = 0;
  local_30 = 1;
  local_2c = 1;
  local_28 = *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x50);
  local_24 = 0xffff;
  local_22 = param_1[0x90];
  local_21 = param_1[0x91];
  local_1e = *(undefined2 *)(param_1 + 0x92);
  local_38[0] = 1;
  local_20 = param_2;
  lVar1 = RhpSendIoctlSynchronously
                    (*(WDFIOTARGET__ **)(*(longlong *)(this + 8) + 0x18),0x2ac00c,&local_30,0x20,
                     local_38,4,(__uint64 *)0x0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x84,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xe1,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  return lVar1;
}



===== updateResHubIoPullConfiguration @ 1c001c3fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl RHP_GPIO_CONTROLLER::updateResHubIoPullConfiguration(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR const * __ptr64,unsigned char) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::updateResHubIoPullConfiguration
          (RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1,uchar param_2)

{
  long lVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined2 local_20;
  uchar local_1e;
  undefined1 local_1d;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_28 = *(undefined8 *)(param_1 + 0x78);
  local_18 = 0;
  local_2c = 0;
  local_20 = 0xffff;
  local_1c = *(undefined2 *)(param_1 + 0x8e);
  local_1a = *(undefined2 *)(param_1 + 0x8c);
  local_1d = 0;
  local_30 = 1;
  local_38[0] = 1;
  local_1e = param_2;
  lVar1 = RhpSendIoctlSynchronously
                    (*(WDFIOTARGET__ **)(*(longlong *)(this + 8) + 0x18),0x2ac00c,&local_30,0x20,
                     local_38,4,(__uint64 *)0x0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x83,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xb5,(char)lVar1);
    }
    lVar1 = -0x3fffffff;
  }
  return lVar1;
}



===== updateResHubPullConfiguration @ 1c001c504 =====

/* private: long __cdecl RHP_GPIO_CONTROLLER::updateResHubPullConfiguration(struct
   RHP_GPIO_CONTROLLER::_PIN_DESCRIPTOR * __ptr64,unsigned char) __ptr64 */

long __thiscall
RHP_GPIO_CONTROLLER::updateResHubPullConfiguration
          (RHP_GPIO_CONTROLLER *this,_PIN_DESCRIPTOR *param_1,uchar param_2)

{
  long lVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  
  if (param_1[0x8b] == (_PIN_DESCRIPTOR)param_2) {
    return 0;
  }
  lVar1 = updateResHubIoPullConfiguration(this,param_1,param_2);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar2 = 0x81;
    uVar3 = 0x80;
  }
  else {
    if ((*(longlong *)(param_1 + 0x60) == 0) ||
       (lVar1 = updateResHubInterruptPullConfiguration(this,param_1,param_2), -1 < lVar1)) {
      param_1[0x8b] = (_PIN_DESCRIPTOR)param_2;
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar2 = 0x82;
    uVar3 = 0x8b;
  }
  WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar2,
                      &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                      "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",uVar3,(char)lVar1);
  return lVar1;
}



===== writePinValue @ 1c001c5f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl RHP_GPIO_CONTROLLER::writePinValue(class
   RHP_GPIO_CONTROLLER::_FILE_OBJECT_CONTEXT const * __ptr64,long) */

long __cdecl RHP_GPIO_CONTROLLER::writePinValue(_FILE_OBJECT_CONTEXT *param_1,long param_2)

{
  int iVar1;
  longlong lVar2;
  _INTERRUPT_CONTEXT *this;
  int iVar3;
  undefined8 uVar4;
  undefined8 in_R8;
  long local_res8 [2];
  undefined8 in_stack_ffffffffffffffc8;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar2 = *(longlong *)param_1;
  uVar4 = 2;
  ExAcquirePushLockExclusiveEx(lVar2);
  iVar3 = *(int *)(lVar2 + 8);
  if (iVar3 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x8c,
                          &WPP_8500aaf3dfe93622d0e97ffc5f59ba68_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpgpio.cpp",0xd0,
                          (char)*(undefined4 *)(lVar2 + 0x80));
    }
    iVar3 = -0x3ffffe7c;
  }
  else {
    iVar1 = *(int *)(lVar2 + 0xc);
    *(long *)(lVar2 + 0xc) = param_2;
    if (((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 4)) {
      iVar3 = 0;
    }
    else {
      *(long **)(lVar2 + 0x50) = local_res8;
      local_res8[0] = param_2;
      iVar3 = (**(code **)(lVar2 + 0x40))(lVar2 + 0x48);
      if (iVar3 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDLd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,in_R8,0x8d,
                     in_stack_ffffffffffffffc8,in_stack_ffffffffffffffd0,0xe9,
                     (char)*(undefined4 *)(lVar2 + 0x80),(char)iVar3);
        }
      }
      else if (((param_2 != iVar1) &&
               (this = *(_INTERRUPT_CONTEXT **)(lVar2 + 0x60), this != (_INTERRUPT_CONTEXT *)0x0))
              && (*(int *)this != 0)) {
        _INTERRUPT_CONTEXT::HandlePinValueChangedInterruptsDisabled(this,param_2);
      }
    }
  }
  ExReleasePushLockExclusiveEx(lVar2,2);
  return iVar3;
}



===== ~RHP_SPI_CONTROLLER @ 1c001c764 =====

/* protected: virtual __cdecl RHP_SPI_CONTROLLER::~RHP_SPI_CONTROLLER(void) __ptr64 */

void __thiscall RHP_SPI_CONTROLLER::~RHP_SPI_CONTROLLER(RHP_SPI_CONTROLLER *this)

{
  longlong lVar1;
  
  *(undefined ***)this = &_vftable_;
  while( true ) {
    lVar1 = RtlLookupElementGenericTableAvl(this + 0x18,0);
    if (lVar1 == 0) break;
    RtlDeleteElementGenericTableAvl(this + 0x18);
  }
  *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
  return;
}



===== AcquireResource @ 1c001c7c8 =====

/* public: long __cdecl RHP_SPI_CONTROLLER::AcquireResource(unsigned short,enum
   _RHPROXY_SPI_SHARING_MODE,struct RHP_SPI_CONTROLLER::_SPI_RESOURCE * __ptr64 * __ptr64) __ptr64
    */

long __thiscall
RHP_SPI_CONTROLLER::AcquireResource
          (RHP_SPI_CONTROLLER *this,ushort param_1,_RHPROXY_SPI_SHARING_MODE param_2,
          _SPI_RESOURCE **param_3)

{
  _SPI_RESOURCE *p_Var1;
  long lVar2;
  _RHPROXY_SPI_SHARING_MODE _Var3;
  undefined4 in_register_00000084;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined8 local_38;
  ushort local_30;
  
  lVar2 = 0;
  *param_3 = (_SPI_RESOURCE *)0x0;
  local_38 = 0;
  _Var3 = param_2;
  local_30 = param_1;
  p_Var1 = (_SPI_RESOURCE *)RtlLookupElementGenericTableAvl(this + 0x18,&local_38);
  if (p_Var1 == (_SPI_RESOURCE *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,CONCAT44(in_register_00000084,_Var3),
                 0x35,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x93,(char)this,(char)param_1);
    }
    return -0x3ffffddb;
  }
  ExAcquirePushLockExclusiveEx(p_Var1,2);
  if (param_2 == 0) {
    if (*(int *)(p_Var1 + 0x18) != 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar4 = 0x36;
        uVar5 = 0xa2;
LAB_1c001c91d:
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,CONCAT44(in_register_00000084,_Var3)
                   ,uVar4,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",uVar5,(char)this,(char)param_1
                  );
      }
LAB_1c001c947:
      lVar2 = -0x3fffffbd;
      goto LAB_1c001c8c0;
    }
    *(undefined4 *)(p_Var1 + 0x1c) = 0;
  }
  else if (*(int *)(p_Var1 + 0x1c) == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x37;
      uVar5 = 0xaa;
      goto LAB_1c001c91d;
    }
    goto LAB_1c001c947;
  }
  LOCK();
  *(int *)(p_Var1 + 0x18) = *(int *)(p_Var1 + 0x18) + 1;
  UNLOCK();
  *param_3 = p_Var1;
LAB_1c001c8c0:
  ExReleasePushLockExclusiveEx(p_Var1,2);
  return lVar2;
}



===== AddResource @ 1c001c958 =====

/* public: long __cdecl RHP_SPI_CONTROLLER::AddResource(unsigned short,unsigned short,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64) __ptr64 */

long __thiscall
RHP_SPI_CONTROLLER::AddResource
          (RHP_SPI_CONTROLLER *this,ushort param_1,ushort param_2,
          _CM_PARTIAL_RESOURCE_DESCRIPTOR *param_3)

{
  long lVar1;
  longlong lVar2;
  undefined6 in_register_00000082;
  undefined8 uVar3;
  undefined8 local_28;
  ushort local_20;
  ushort local_1e;
  undefined8 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar3 = CONCAT62(in_register_00000082,param_2);
  if (*(int *)(this + 0x80) == 0xffff) {
    lVar1 = -0x3fffff66;
  }
  else {
    local_28 = 0;
    local_18 = *(undefined8 *)(param_3 + 8);
    local_10 = 0;
    local_c = 1;
    local_20 = param_1;
    local_1e = param_2;
    lVar2 = RtlLookupElementGenericTableAvl(this + 0x18,&local_28);
    if (lVar2 == 0) {
      uVar3 = 0x20;
      lVar2 = RtlInsertElementGenericTableAvl(this + 0x18,&local_28);
      if (lVar2 == 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x31,
                     &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x43,(char)this,
                     (char)&local_28);
        }
        lVar1 = -0x3fffffe9;
      }
      else {
        *(undefined4 *)(this + 0x40) = 0;
        *(undefined8 *)(this + 0x38) = 0;
        *(int *)(this + 0x80) = *(int *)(this + 0x80) + 1;
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDqdq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar3,0x32,
                     &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x4e,(char)&local_28,
                     (char)param_1,(char)this);
        }
        lVar1 = 0;
      }
    }
    else {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar3,0x30,
                   &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2e,(char)lVar2,
                   (char)local_20);
      }
      lVar1 = -0x3ffffdd6;
    }
  }
  return lVar1;
}



===== EvtDeviceFileCreate @ 1c001cb50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_SPI_CONTROLLER::EvtDeviceFileCreate(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
RHP_SPI_CONTROLLER::EvtDeviceFileCreate
          (RHP_SPI_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined *local_10;
  
  lVar1 = RHP_CONTROLLER::VerifyFileCreateRequestParameters(param_2);
  if (lVar1 < 0) {
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  else {
    local_48 = (undefined8 *)0x0;
    puVar3 = &local_40;
    local_30 = 0;
    uStack_28 = 0x100000001;
    local_10 = PTR__WDF__RHP_SPI_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010118;
    uStack_38 = 0;
    local_40 = 0x38;
    local_20 = 0;
    uStack_18 = 0;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_3,puVar3,&local_48);
    if (lVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDqD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,0x3c,
                   &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x42,(char)param_3,(char)lVar1
                  );
      }
    }
    else {
      local_48[2] = 0;
      local_48[3] = 0;
      local_48[4] = 0;
      local_48[5] = 0;
      *local_48 = 0;
      local_48[1] = 0;
      lVar1 = 0;
    }
    pcVar2 = *(code **)(WdfFunctions_01015 + 0x838);
  }
  (*pcVar2)(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== EvtFileClose @ 1c001ccb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_SPI_CONTROLLER::EvtFileClose(struct WDFFILEOBJECT__ * __ptr64)
   __ptr64 */

void __thiscall RHP_SPI_CONTROLLER::EvtFileClose(RHP_SPI_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF__RHP_SPI_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010118);
  if (*(longlong *)(lVar1 + 8) != 0) {
    ObfDereferenceObjectWithTag(*(longlong *)(lVar1 + 8),0x36504852);
    *(undefined8 *)(lVar1 + 8) = 0;
    RHP_DEVICE::RemoveResourceHubRecord(*(RHP_DEVICE **)(this + 8),(_LARGE_INTEGER *)(lVar1 + 0x18))
    ;
    ReleaseResource(this,*(ushort *)(*(longlong *)(lVar1 + 0x10) + 8));
  }
  if (*(longlong *)(lVar1 + 8) != 0) {
    ObfDereferenceObjectWithTag(*(longlong *)(lVar1 + 8),0x36504852);
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  return;
}



===== GetDeviceSelection @ 1c001cd50 =====

/* public: static long __cdecl RHP_SPI_CONTROLLER::GetDeviceSelection(union _LARGE_INTEGER const &
   __ptr64,class RHP_DEVICE * __ptr64,unsigned short * __ptr64) */

long __cdecl
RHP_SPI_CONTROLLER::GetDeviceSelection(_LARGE_INTEGER *param_1,RHP_DEVICE *param_2,ushort *param_3)

{
  long lVar1;
  ulong local_res20 [2];
  _RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *local_18 [2];
  
  local_res20[0] = 0;
  local_18[0] = (_RH_QUERY_CONNECTION_PROPERTIES_OUTPUT_BUFFER *)0x0;
  lVar1 = RHP_DEVICE::QueryResourceHubRecord(param_2,param_1,local_18,local_res20);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3b,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x12,(char)lVar1);
    }
  }
  else {
    *param_3 = *(ushort *)(local_18[0] + 0x1b);
    ExFreePoolWithTag(local_18[0],0x30504852);
  }
  return lVar1;
}



===== Init @ 1c001ce08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl RHP_SPI_CONTROLLER::Init(struct WDFDEVICE__ * __ptr64,struct _UNICODE_STRING
   const & __ptr64,struct _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64) __ptr64 */

long __thiscall
RHP_SPI_CONTROLLER::Init
          (RHP_SPI_CONTROLLER *this,WDFDEVICE__ *param_1,_UNICODE_STRING *param_2,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_3)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  ulonglong uVar4;
  _UNICODE_STRING *p_Var5;
  _UNICODE_STRING *p_Var6;
  undefined2 uVar7;
  _ACPI_METHOD_ARGUMENT_V1 *p_Var8;
  undefined1 auStackY_e8 [32];
  undefined1 uVar9;
  undefined8 local_98;
  undefined8 local_90;
  wchar_t *local_88;
  _UNICODE_STRING *local_80;
  _ACPI_METHOD_ARGUMENT_V1 *local_78;
  wchar_t local_70 [12];
  ulonglong uStack_58;
  wchar_t local_50 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  local_50[0] = L'\0';
  local_50[1] = L'\0';
  local_50[2] = L'\0';
  local_50[3] = L'\0';
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  local_78 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
  local_80 = param_2;
  lVar3 = RHP_CONTROLLER::RetrieveDsdArguments
                    ((_ACPI_METHOD_ARGUMENT_V1 *)(param_3 + 0xc),*(int *)(param_3 + 4) - 0xc,
                     &local_78);
  p_Var8 = local_78;
  if (lVar3 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x16,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xbc,(char)lVar3);
    }
    return 0;
  }
  builtin_wcsncpy(local_70,L"MinClockInHz",0xc);
  uStack_58 = uStack_58 & 0xffffffffffff0000;
  local_88 = local_70;
  local_90 = 0x1a0018;
  local_98 = (_ACPI_METHOD_ARGUMENT_V1 *)((ulonglong)local_98._4_4_ << 0x20);
  lVar3 = RHP_CONTROLLER::ParsePropertyUlong
                    (local_78,param_2,(_UNICODE_STRING *)&local_90,(ulong *)&local_98);
  if (lVar3 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar3;
    }
    uVar7 = 0x17;
    uVar9 = 0xcc;
LAB_1c001cf68:
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                        &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",uVar9,(char)lVar3);
    return lVar3;
  }
  uVar1 = (ulong)local_98;
  if ((ulong)local_98 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar7 = 0x18;
    uVar9 = 0xd1;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x19,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xd7,(char)local_98);
    }
    *(ulong *)(this + 0x84) = uVar1;
    p_Var6 = (_UNICODE_STRING *)&local_90;
    uStack_58 = uStack_58 & 0xffffffffffff0000;
    local_88 = local_70;
    builtin_wcsncpy(local_70,L"MaxClockInHz",0xc);
    local_98 = (_ACPI_METHOD_ARGUMENT_V1 *)((ulonglong)local_98 & 0xffffffff00000000);
    local_90 = 0x1a0018;
    p_Var5 = local_80;
    lVar3 = RHP_CONTROLLER::ParsePropertyUlong(p_Var8,local_80,p_Var6,(ulong *)&local_98);
    if (lVar3 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return lVar3;
      }
      uVar7 = 0x1a;
      uVar9 = 0xe7;
      goto LAB_1c001cf68;
    }
    uVar2 = (ulong)local_98;
    if ((ulong)local_98 <= *(uint *)(this + 0x84)) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      WPP_RECORDER_SF_sDDD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),p_Var5,p_Var6,0x1b,
                 &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xef,
                 (char)*(uint *)(this + 0x84),(char)local_98);
      return -0x3ffffff3;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1c,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xf5,(char)local_98);
    }
    local_88 = local_70;
    *(uint *)(this + 0x88) = uVar2;
    local_98 = (_ACPI_METHOD_ARGUMENT_V1 *)0x0;
    builtin_wcsncpy(local_70,L"SupportedDat",0xc);
    local_90 = 0x30002e;
    uStack_58._0_2_ = L'a';
    uStack_58._2_2_ = L'B';
    uStack_58._4_2_ = L'i';
    uStack_58._6_2_ = L't';
    builtin_wcsncpy(local_50,L"Lengths",8);
    lVar3 = RHP_CONTROLLER::RetrieveArgumentWithMatchingToken
                      (p_Var8,(_ACPI_METHOD_ARGUMENT_V1 *)0x0,local_80,(_UNICODE_STRING *)&local_90,
                       2,(_ACPI_METHOD_ARGUMENT_V1 **)&local_98);
    p_Var8 = local_98;
    if ((lVar3 < 0) || (local_98 == (_ACPI_METHOD_ARGUMENT_V1 *)0x0)) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1d,
                            &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",9,(char)lVar3);
      }
      if (p_Var8 == (_ACPI_METHOD_ARGUMENT_V1 *)0x0) {
        return -0x3ffffddb;
      }
      return lVar3;
    }
    uVar4 = (ulonglong)*(ushort *)(local_98 + 6);
    if (*(ushort *)(local_98 + 6) < 4) {
      uVar4 = 4;
    }
    if (local_78 + (ulonglong)*(ushort *)(local_78 + 2) + 4 <
        local_98 + (ulonglong)*(ushort *)(local_98 + uVar4 + 10) + uVar4 + 0xc) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1e,
                           &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x1a);
      }
      return -0x3febfff5;
    }
    RtlInitializeBitMap(this + 0xb0,this + 0x8c,0x100);
    local_80 = (_UNICODE_STRING *)
               (p_Var8 + (ulonglong)*(ushort *)(p_Var8 + uVar4 + 10) + uVar4 + 0xc);
    p_Var8 = p_Var8 + uVar4 + 0xc;
    while( true ) {
      if (local_80 < (_UNICODE_STRING *)(p_Var8 + (ulonglong)*(ushort *)(p_Var8 + 2) + 4)) {
        return 0;
      }
      if (*(short *)p_Var8 != 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1f,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x2f,
                              (char)*(short *)p_Var8);
        }
        return -0x3febfff8;
      }
      local_98 = (_ACPI_METHOD_ARGUMENT_V1 *)((ulonglong)local_98 & 0xffffffff00000000);
      lVar3 = RHP_CONTROLLER::ArgumentParseUlong(p_Var8,(ulong *)&local_98);
      if (lVar3 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x20,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x38,(char)lVar3);
        }
        return lVar3;
      }
      if (0xff < (ulong)local_98 - 1) break;
      RtlSetBits(this + 0xb0,(ulong)local_98 - 1,1);
      uVar4 = (ulonglong)*(ushort *)(p_Var8 + 2);
      if (*(ushort *)(p_Var8 + 2) < 4) {
        uVar4 = 4;
      }
      p_Var8 = p_Var8 + uVar4 + 4;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff3;
    }
    uVar7 = 0x21;
    uVar9 = 0x46;
  }
  WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar7,
                     &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",uVar9);
  return -0x3ffffff3;
}



===== ParseResource @ 1c001d420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_SPI_CONTROLLER::ParseResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,class RHP_DEVICE * __ptr64,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64) */

long __cdecl
RHP_SPI_CONTROLLER::ParseResource
          (ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,RHP_DEVICE *param_3,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_4)

{
  long lVar1;
  uint uVar2;
  RHP_CONTROLLER *this;
  uint uVar3;
  RHP_DEVICE *this_00;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined1 auStackY_118 [32];
  undefined1 uVar6;
  ushort local_c8 [4];
  undefined8 local_c0;
  ushort local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (param_4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x23,
                         &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x60);
    }
    return 0;
  }
  local_c0 = *(undefined8 *)(param_2 + 8);
  local_c8[0] = 0;
  lVar1 = GetDeviceSelection((_LARGE_INTEGER *)&local_c0,param_3,local_c8);
  uVar4 = local_c0;
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x24,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x6f,(char)lVar1);
    }
    return -0x3fffffff;
  }
  uStack_50 = 0x8000000;
  local_b8 = local_c8[0];
  local_68 = 0x200000001;
  uStack_60 = local_c0;
  local_58 = CONCAT44(4000000,CONCAT22(local_c8[0],0xffff));
  this_00 = param_3;
  lVar1 = RHP_DEVICE::UpdateResourceHubRecord
                    (param_3,(_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar5 = 0x25;
    uVar6 = 0x89;
LAB_1c001d5d2:
    WPP_RECORDER_SF_sDdi
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
               &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",uVar6,(char)lVar1,(char)uVar4);
    return lVar1;
  }
  lVar1 = RHP_DEVICE::ProbeSpbConnectionResource(this_00,(_LARGE_INTEGER *)&local_c0);
  uVar4 = local_c0;
  if (lVar1 < 0) {
    if (lVar1 == -0x3fffffff) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_sDdi
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x26,
                 &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0x94,1,(char)local_c0);
      return 0;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar5 = 0x27;
    uVar6 = 0x9a;
    goto LAB_1c001d5d2;
  }
  uStack_50 = 0;
  local_68 = 0x200000001;
  uStack_60 = local_c0;
  local_58 = 0xffff;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  lVar1 = RHP_DEVICE::UpdateResourceHubRecord
                    (param_3,(_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return lVar1;
    }
    uVar5 = 0x28;
    uVar6 = 0xab;
    goto LAB_1c001d5d2;
  }
  local_a0 = 0x80006;
  local_48 = 0x6900700073;
  local_98 = &local_48;
  local_b0 = 0;
  uStack_a8 = 0;
  lVar1 = RHP_CONTROLLER::RetrieveBusFriendlyName
                    (param_4,param_1,(_UNICODE_STRING *)&local_a0,(_UNICODE_STRING *)&local_b0);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x29,
                        &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                        "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xc0,(char)lVar1);
    return 0;
  }
  this = RHP_DEVICE::FindController(param_3,(_UNICODE_STRING *)&local_b0,(_UNICODE_STRING **)0x0);
  if (this == (RHP_CONTROLLER *)0x0) {
    this = (RHP_CONTROLLER *)ExAllocatePoolWithTag(0x200,0xc0,0x33504852);
    if (this == (RHP_CONTROLLER *)0x0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2a,
                           &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xd1);
      }
      uVar2 = 0xc0000017;
      goto LAB_1c001db3b;
    }
    *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
    *(RHP_DEVICE **)(this + 8) = param_3;
    *(undefined ***)this = &_vftable_;
    *(undefined4 *)(this + 0x10) = 1;
    RtlInitializeGenericTableAvl
              ((RHP_SPI_CONTROLLER *)(this + 0x18),rtlAvlResourceCompareRoutine,
               rtlAvlResourceAllocateRoutine,rtlAvlResourceFreeRoutine);
    lVar1 = Init((RHP_SPI_CONTROLLER *)this,*(WDFDEVICE__ **)(param_3 + 8),
                 (_UNICODE_STRING *)&local_b0,param_4);
    if (-1 < lVar1) {
      uVar2 = RHP_DEVICE::RegisterController
                        (param_3,(_UNICODE_STRING *)&local_b0,this,
                         (_GUID *)&GUID_DEVINTERFACE_RHPROXY_SPI,2);
      if ((int)uVar2 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2c,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xec,(char)uVar2);
        }
        if ((uVar2 != 0xc000009a) && (uVar2 != 0xc0000017)) {
          uVar2 = (int)uVar2 >> 0x1f & 0xc0000001;
        }
        RHP_CONTROLLER::ReleaseReference(this);
        goto LAB_1c001db3b;
      }
      RHP_CONTROLLER::ReleaseReference(this);
      goto LAB_1c001d969;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2b,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xe0,(char)lVar1);
    }
    RHP_CONTROLLER::ReleaseReference(this);
  }
  else {
LAB_1c001d969:
    if (*(uint *)(this + 0x80) < 0x10000) {
      uVar2 = AddResource((RHP_SPI_CONTROLLER *)this,(ushort)*(uint *)(this + 0x80),local_b8,param_2
                         );
      uVar3 = (uint)this;
      if ((int)uVar2 < 0) {
        if (uVar2 == 0xc000022a) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            WPP_RECORDER_SF_sD(uVar4,2,3,0x2e,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",6);
            uVar3 = (uint)uVar4;
          }
          _RhpLogDebug(uVar3);
          uVar2 = 0;
        }
        else if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2f,
                              &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xb,(char)uVar2);
        }
      }
      goto LAB_1c001db3b;
    }
    if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3a,
                            &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xf5,0x95),
       (undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2d,
                          &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xf9,0x95);
    }
  }
  uVar2 = 0xc0000001;
LAB_1c001db3b:
  RtlFreeUnicodeString(&local_b0);
  return uVar2;
}



===== ReleaseResource @ 1c001db7c =====

/* public: long __cdecl RHP_SPI_CONTROLLER::ReleaseResource(unsigned short) __ptr64 */

long __thiscall RHP_SPI_CONTROLLER::ReleaseResource(RHP_SPI_CONTROLLER *this,ushort param_1)

{
  long lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 in_R8;
  undefined8 local_28;
  ushort local_20;
  
  local_28 = 0;
  local_20 = param_1;
  lVar2 = RtlLookupElementGenericTableAvl(this + 0x18,&local_28);
  if (lVar2 == 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqD
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,in_R8,0x38,
                 &WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xc6,(char)this,(char)param_1);
    }
    lVar1 = -0x3ffffff3;
  }
  else {
    lVar4 = lVar2;
    ExAcquirePushLockExclusiveEx(lVar2,2);
    uVar3 = (uint)lVar4;
    if (((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       ((*(int *)(lVar2 + 0x18) == 0 ||
        ((*(int *)(lVar2 + 0x1c) != 1 &&
         ((*(int *)(lVar2 + 0x1c) != 0 || (*(int *)(lVar2 + 0x18) != 1)))))))) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDs(uVar5,2,3,0x39,&WPP_addd4454d90e31df54a650e922f747b5_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpspi.cpp",0xd1,
                          "(resourcePtr->RefCount != 0) && ((resourcePtr->SharingMode == RHPROXY_SPI_SHARING_MODE_SHARED) || ((resourcePtr->SharingMode == RHPROXY_SPI_SHARING_MODE_EXCLUSIVE) && (resourcePtr->RefCount == 1)))"
                         );
      uVar3 = (uint)uVar5;
    }
    if ((*(int *)(lVar2 + 0x18) == 0) ||
       ((*(int *)(lVar2 + 0x1c) != 1 &&
        ((*(int *)(lVar2 + 0x1c) != 0 || (*(int *)(lVar2 + 0x18) != 1)))))) {
      _RhpLogDebug(uVar3);
    }
    if (0 < *(int *)(lVar2 + 0x18)) {
      LOCK();
      *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + -1;
      UNLOCK();
    }
    *(undefined4 *)(lVar2 + 0x1c) = 1;
    ExReleasePushLockExclusiveEx(lVar2,2);
    lVar1 = 0;
  }
  return lVar1;
}



===== EvtDeviceFileCreate @ 1c001dd00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_I2C_CONTROLLER::EvtDeviceFileCreate(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
RHP_I2C_CONTROLLER::EvtDeviceFileCreate
          (RHP_I2C_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  long lVar1;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined *local_10;
  
  lVar1 = RHP_CONTROLLER::VerifyFileCreateRequestParameters(param_2);
  if (lVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x23,
                         &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x16);
    }
  }
  else {
    local_48 = (undefined8 *)0x0;
    local_30 = 0;
    local_10 = PTR__WDF__RHP_I2C_CONTROLLER_I2C_RESOURCE_TYPE_INFO_1c0010140;
    uStack_38 = 0;
    local_40 = 0x38;
    local_20 = 0;
    uStack_18 = 0;
    uStack_28 = 0x100000001;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x658))(WdfDriverGlobals,param_3,&local_40,&local_48);
    if (lVar1 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x24,
                            &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x28,(char)lVar1);
      }
    }
    else {
      local_48[2] = 0;
      local_48[3] = 0;
      local_48[4] = 0;
      *local_48 = 0;
      local_48[1] = 0;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,lVar1);
  return;
}



===== EvtFileClose @ 1c001de90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_I2C_CONTROLLER::EvtFileClose(struct WDFFILEOBJECT__ * __ptr64)
   __ptr64 */

void __thiscall RHP_I2C_CONTROLLER::EvtFileClose(RHP_I2C_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  longlong lVar1;
  ushort uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF__RHP_I2C_CONTROLLER_I2C_RESOURCE_TYPE_INFO_1c0010140);
  if (*(longlong *)(lVar1 + 8) != 0) {
    ObfDereferenceObjectWithTag(*(longlong *)(lVar1 + 8),0x35504852);
    *(undefined8 *)(lVar1 + 8) = 0;
    RHP_DEVICE::RemoveResourceHubRecord(*(RHP_DEVICE **)(this + 8),(_LARGE_INTEGER *)(lVar1 + 0x20))
    ;
    uVar2 = *(ushort *)(lVar1 + 0x10) + 0x80;
    if (*(int *)(lVar1 + 0x14) != 1) {
      uVar2 = *(ushort *)(lVar1 + 0x10);
    }
    if (*(int *)(lVar1 + 0x1c) == 1) {
      LOCK();
      *(short *)(this + (ulonglong)uVar2 * 2 + 0x30) =
           *(short *)(this + (ulonglong)uVar2 * 2 + 0x30) + -1;
      UNLOCK();
    }
    else {
      LOCK();
      *(ushort *)(this + (ulonglong)uVar2 * 2 + 0x30) =
           *(ushort *)(this + (ulonglong)uVar2 * 2 + 0x30) & 0x7fff;
      UNLOCK();
    }
  }
  if (*(longlong *)(lVar1 + 8) != 0) {
    ObfDereferenceObjectWithTag(*(longlong *)(lVar1 + 8),0x35504852);
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  return;
}



===== ParseResource @ 1c001df50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_I2C_CONTROLLER::ParseResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,class RHP_DEVICE * __ptr64,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64) */

long __cdecl
RHP_I2C_CONTROLLER::ParseResource
          (ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,RHP_DEVICE *param_3,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_4)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  RHP_CONTROLLER *this;
  RHP_DEVICE *this_00;
  undefined1 auStackY_108 [32];
  undefined1 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDLLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (param_4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x1b,
                         &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0x8f);
    }
  }
  else {
    local_b8 = *(undefined8 *)(param_2 + 8);
    local_68 = 0x300000001;
    local_58 = 0x186a00000ffff;
    uStack_50 = 0;
    this_00 = param_3;
    uStack_60 = local_b8;
    lVar2 = RHP_DEVICE::UpdateResourceHubRecord
                      (param_3,(_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
    if (lVar2 < 0) {
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1c,
                            &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xab,(char)lVar2);
      }
      return lVar2;
    }
    lVar2 = RHP_DEVICE::ProbeSpbConnectionResource(this_00,(_LARGE_INTEGER *)&local_b8);
    uVar1 = local_b8;
    uVar4 = (undefined1)local_b8;
    if (lVar2 < 0) {
      if (lVar2 != -0x3fffffff) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return lVar2;
        }
        WPP_RECORDER_SF_sDdi
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1e,
                   &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xbc,(char)lVar2,uVar4);
        return lVar2;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDdi
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x1d,
                   &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                   "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xb6,1,uVar4);
      }
    }
    else {
      uStack_50 = 0;
      local_68 = 0x300000001;
      uStack_60 = local_b8;
      local_58 = 0xffff;
      local_88 = 0;
      uStack_80 = 0;
      local_78 = 0;
      uStack_70 = 0;
      lVar2 = RHP_DEVICE::UpdateResourceHubRecord
                        (param_3,(_RH_ALLOCATE_UPDATE_CONNECTION_INPUT_BUFFER *)&local_68);
      if (lVar2 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDdi
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                     &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                     "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xce,(char)lVar2,uVar4);
        }
        return lVar2;
      }
      local_b0 = 0x80006;
      local_48 = 0x6300320069;
      local_a8 = &local_48;
      local_a0 = 0;
      uStack_98 = 0;
      lVar2 = RHP_CONTROLLER::RetrieveBusFriendlyName
                        (param_4,param_1,(_UNICODE_STRING *)&local_b0,(_UNICODE_STRING *)&local_a0);
      if (-1 < lVar2) {
        this = (RHP_CONTROLLER *)ExAllocatePoolWithTag(0x200,0x930,0x33504852);
        if (this == (RHP_CONTROLLER *)0x0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x21,
                               &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xec);
          }
          uVar3 = 0xc0000017;
        }
        else {
          *(RHP_DEVICE **)(this + 8) = param_3;
          *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
          *(undefined4 *)(this + 0x10) = 1;
          *(undefined ***)this = &_vftable_;
          memset(this + 0x30,0,0x900);
          *(undefined8 *)(this + 0x20) = 0;
          uVar3 = RHP_DEVICE::RegisterController
                            (param_3,(_UNICODE_STRING *)&local_a0,this,
                             (_GUID *)&GUID_DEVINTERFACE_RHPROXY_I2C,2);
          if ((int)uVar3 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x22,
                                  &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                                  "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xff,
                                  (char)uVar3);
            }
            if ((uVar3 != 0xc000009a) && (uVar3 != 0xc0000017)) {
              uVar3 = (int)uVar3 >> 0x1f & 0xc0000001;
            }
          }
          else {
            *(undefined8 *)(this + 0x18) = uVar1;
          }
          RHP_CONTROLLER::ReleaseReference(this);
        }
        RtlFreeUnicodeString(&local_a0);
        return uVar3;
      }
      if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x20,
                            &WPP_fe6787aaa3883fd7091bed13403fb858_Traceguids,
                            "onecore\\base\\basedrv\\rhproxy\\sys\\rhpi2c.cpp",0xe2,(char)lVar2);
      }
    }
  }
  return 0;
}



===== EvtDeviceFileCreate @ 1c001e410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c001e867) */
/* WARNING: Removing unreachable block (ram,0x0001c001e84b) */
/* WARNING: Removing unreachable block (ram,0x0001c001ec4e) */
/* WARNING: Removing unreachable block (ram,0x0001c001ec51) */
/* public: virtual void __cdecl RHP_UART_CONTROLLER::EvtDeviceFileCreate(struct WDFDEVICE__ *
   __ptr64,struct WDFREQUEST__ * __ptr64,struct WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
RHP_UART_CONTROLLER::EvtDeviceFileCreate
          (RHP_UART_CONTROLLER *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2,
          WDFFILEOBJECT__ *param_3)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auStackY_1b8 [32];
  longlong local_150;
  longlong *local_148;
  short local_140 [4];
  undefined1 *local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  WDFDEVICE__ *local_120;
  WDFFILEOBJECT__ *local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined *local_e0;
  __uint64 local_d8;
  longlong lStack_d0;
  short *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_b8 = 0;
  lStack_d0 = 0;
  local_d8 = 0x28;
  local_c8 = (short *)0x0;
  uStack_c0 = 0;
  local_120 = param_1;
  local_118 = param_3;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_d8);
  if (*(int *)(lStack_d0 + 0x10) == 0x12019f) {
    if (uStack_c0._2_2_ == 0) {
      local_e0 = PTR__WDF__RHP_UART_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010168;
      local_100 = 0;
      uStack_108 = 0;
      local_110 = 0x38;
      local_f0 = 0;
      uStack_e8 = 0;
      uStack_f8 = 0x100000001;
      local_148 = (longlong *)0x0;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x658))
                        (WdfDriverGlobals,param_3,&local_110,&local_148);
      plVar1 = local_148;
      if (iVar2 < 0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x12,
                              &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                              "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xc,(char)iVar2);
        }
      }
      else {
        local_148[1] = 0;
        *local_148 = 0;
        local_148[1] = *(longlong *)(this + 0x18);
        local_138 = local_98;
        local_140[0] = 0;
        local_140[1] = 0x4c;
        local_140[2] = 0;
        local_140[3] = 0;
        local_150 = local_148[1];
        iVar2 = RESOURCE_HUB_STRING_PRINTF
                          ((ushort *)&local_d8,0x22,(ushort *)L"%0*I64x",(__uint64 *)0x10);
        if (-1 < iVar2) {
          iVar2 = RESOURCE_HUB_UNICODE_STRING_PRINTF
                            (local_140,(ushort *)L"%s%s",L"\\Device\\RESOURCE_HUB\\",&local_d8);
        }
        if (-1 < iVar2) {
          local_c8 = local_140;
          local_b8 = 0;
          uStack_b0 = 0;
          local_d8 = 0x30;
          uStack_c0 = 0x200;
          lStack_d0 = 0;
          uVar4 = PsGetHostSilo();
          uVar4 = PsAttachSiloToCurrentThread(uVar4);
          local_150 = 0;
          local_130 = 0;
          uStack_128 = 0;
          iVar2 = ZwCreateFile(&local_150,0xc0000000,&local_d8,&local_130);
          PsDetachSiloFromCurrentThread(uVar4);
          if (iVar2 < 0) {
            if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_sDdi
                        (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                         &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x47,(char)iVar2,
                         (char)plVar1[1]);
            }
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
            if (local_150 == 0) {
              return;
            }
            ZwClose();
            return;
          }
          uVar4 = 0xc0000000;
          uVar3 = ObReferenceObjectByHandleWithTag
                            (local_150,0xc0000000,*(undefined8 *)IoFileObjectType_exref,0);
          if (-1 < (int)uVar3) {
            if (local_150 != 0) {
              ZwClose();
            }
            local_c8 = (short *)0x0;
            local_d8 = 0;
            lStack_d0 = 0;
            KeInitializeEvent(&local_d8,0,0);
            lVar5 = IoGetRelatedDeviceObject(0);
            local_a8 = 0;
            uStack_a0 = 0;
            local_130 = 0;
            uStack_128 = 0;
            local_150 = lVar5;
            lVar6 = IoBuildDeviceIoControlRequest(0x1b0064,lVar5,&local_a8,0x10);
            if (lVar6 == 0) {
              if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sDqq
                          (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x15,
                           &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                           "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x78,0,(char)lVar5);
              }
              uVar3 = 0xc000009a;
            }
            else {
              *(undefined8 *)(*(longlong *)(lVar6 + 0xb8) + -0x18) = 0;
              local_130 = CONCAT44(local_130._4_4_,0xc00000bb);
              uVar3 = IofCallDriver(lVar5,lVar6);
              if (uVar3 == 0x103) {
                KeWaitForSingleObject(&local_d8,0,0,0);
                uVar3 = (uint)local_130;
              }
              if ((int)uVar3 < 0) {
                if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_sDdqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                }
                if ((uVar3 != 0xc000009a) && (uVar3 != 0xc0000017)) {
                  uVar3 = (int)uVar3 >> 0x1f & 0xc0000001;
                }
              }
              else {
                uVar7 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,local_120);
                uVar8 = IoGetRelatedDeviceObject(0);
                uVar9 = 0;
                uVar4 = uVar8;
                uVar3 = IoAdjustStackSizeForRedirection(uVar7);
                if ((int)uVar3 < 0) {
                  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_sDdqq
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar9,0x17,
                               &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xaa,(char)uVar3,
                               (char)uVar7,(char)uVar8);
                  }
                  if ((uVar3 != 0xc000009a) && (uVar3 != 0xc0000017)) {
                    uVar3 = (int)uVar3 >> 0x1f & 0xc0000001;
                  }
                }
                else {
                  RHP_DEVICE::EnableControllerWdmIrpPreprocess(local_118,(void *)0x0);
                  if (*plVar1 != 0) {
                    ObfDereferenceObjectWithTag(*plVar1,0x37504852);
                  }
                  *plVar1 = 0;
                  uVar3 = 0;
                }
              }
            }
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
            return;
          }
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDdq
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0x14,
                       &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x58,(char)uVar3,
                       (char)local_150);
          }
          if ((uVar3 != 0xc000009a) && (uVar3 != 0xc0000017)) {
            uVar3 = (int)uVar3 >> 0x1f & 0xc0000001;
          }
          (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
          if (local_150 == 0) {
            return;
          }
          ZwClose();
          return;
        }
      }
      goto LAB_1c001e591;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x10,
                          &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xe6,
                          (char)((ulonglong)uStack_c0 >> 0x10));
    }
    iVar2 = -0x3fffffbd;
  }
  else {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xf,
                          &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xdf,
                          (char)*(int *)(lStack_d0 + 0x10));
    }
    iVar2 = -0x3fffffde;
  }
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x11,
                       &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                       "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xf8);
  }
LAB_1c001e591:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== EvtFileClose @ 1c001ec90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl RHP_UART_CONTROLLER::EvtFileClose(struct WDFFILEOBJECT__ * __ptr64)
   __ptr64 */

void __thiscall
RHP_UART_CONTROLLER::EvtFileClose(RHP_UART_CONTROLLER *this,WDFFILEOBJECT__ *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF__RHP_UART_CONTROLLER_FILE_OBJECT_CONTEXT_TYPE_INFO_1c0010168);
  if (*plVar1 != 0) {
    ObfDereferenceObjectWithTag(*plVar1,0x37504852);
    *plVar1 = 0;
  }
  return;
}



===== ParseResource @ 1c001ece4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl RHP_UART_CONTROLLER::ParseResource(unsigned long,struct
   _CM_PARTIAL_RESOURCE_DESCRIPTOR const * __ptr64,class RHP_DEVICE * __ptr64,struct
   _ACPI_EVAL_OUTPUT_BUFFER_V1 const * __ptr64) */

long __cdecl
RHP_UART_CONTROLLER::ParseResource
          (ulong param_1,_CM_PARTIAL_RESOURCE_DESCRIPTOR *param_2,RHP_DEVICE *param_3,
          _ACPI_EVAL_OUTPUT_BUFFER_V1 *param_4)

{
  undefined8 uVar1;
  long lVar2;
  RHP_CONTROLLER *this;
  undefined1 auStackY_c8 [32];
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_48;
  undefined2 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDDLq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (param_4 == (_ACPI_EVAL_OUTPUT_BUFFER_V1 *)0x0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                         &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                         "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0x87);
    }
  }
  else {
    uVar1 = *(undefined8 *)(param_2 + 8);
    local_40 = 0;
    local_68 = &local_48;
    local_60 = 0;
    uStack_58 = 0;
    local_70 = 0xa0008;
    local_48 = 0x74007200610075;
    lVar2 = RHP_CONTROLLER::RetrieveBusFriendlyName
                      (param_4,param_1,(_UNICODE_STRING *)&local_70,(_UNICODE_STRING *)&local_60);
    if (-1 < lVar2) {
      this = (RHP_CONTROLLER *)ExAllocatePoolWithTag(0x200,0x20,0x33504852);
      if (this == (RHP_CONTROLLER *)0x0) {
        if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xd,
                             &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                             "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xac);
        }
        lVar2 = -0x3fffffe9;
      }
      else {
        *(RHP_DEVICE **)(this + 8) = param_3;
        *(undefined ***)this = &RHP_CONTROLLER::_vftable_;
        *(undefined4 *)(this + 0x10) = 1;
        *(undefined ***)this = &_vftable_;
        lVar2 = RHP_DEVICE::RegisterController
                          (param_3,(_UNICODE_STRING *)&local_60,this,
                           (_GUID *)&GUID_DEVINTERFACE_COMPORT,5);
        if (lVar2 < 0) {
          if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xe,
                                &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                                "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xc0,(char)lVar2
                               );
          }
          RHP_CONTROLLER::ReleaseReference(this);
          lVar2 = -0x3fffffff;
        }
        else {
          *(undefined8 *)(this + 0x18) = uVar1;
          RHP_CONTROLLER::ReleaseReference(this);
        }
      }
      RtlFreeUnicodeString(&local_60);
      return lVar2;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
                          &WPP_3ff870efb3283585501589514d8bb436_Traceguids,
                          "onecore\\base\\basedrv\\rhproxy\\sys\\rhpuart.cpp",0xa1,(char)lVar2);
    }
  }
  return 0;
}



===== __security_init_cookie @ 1c001f008 =====

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



===== DriverEntry @ 1c001f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  RHP_DRIVER *this;
  int *piVar2;
  uint uVar3;
  undefined8 uVar4;
  _UNICODE_STRING *p_Var5;
  undefined1 auStackY_e8 [32];
  undefined1 uVar6;
  undefined1 uVar7;
  undefined8 local_78;
  code *local_70;
  code *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined *local_48;
  WDFDRIVER__ *local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  _DAT_1c00103c8 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c00103a8 = &WPP_ThisDir_CTLGUID_RHPROXY;
  DAT_1c00103b0 = 0;
  _DAT_1c00103c0 = 0;
  _DAT_1c00103e0 = 0;
  _DAT_1c00103e8 = 0;
  WppLoadTracingSupport();
  _DAT_1c00103c0 = 0;
  WppInitKm(param_1,param_2);
  local_40 = (WDFDRIVER__ *)0x100000010;
  uStack_38 = 0x200000002;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_40);
  uVar6 = (undefined1)param_1;
  uVar7 = (undefined1)param_2;
  if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sDqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xc,
               &WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,
               "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0x88,uVar6,uVar7);
  }
  local_48 = PTR__WDF_RHP_DRIVER_TYPE_INFO_1c0010028;
  local_70 = RHP_DRIVER::evtCleanupCallback;
  local_40 = (WDFDRIVER__ *)0x0;
  local_68 = RHP_DRIVER::evtDestroyCallback;
  local_78 = 0x38;
  local_5c = 1;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 2;
  uVar4 = WdfDriverGlobals;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,&local_78);
  uVar3 = (uint)uVar4;
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_sDqqL
                (uVar4,2,3,0xd,&WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0xa6,uVar6,uVar7,(char)iVar1)
      ;
      uVar3 = (uint)uVar4;
    }
    _RhpLogDebug(uVar3);
  }
  else {
    p_Var5 = (_UNICODE_STRING *)PTR__WDF_RHP_DRIVER_TYPE_INFO_1c0010028;
    this = (RHP_DRIVER *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,local_40);
    piVar2 = (int *)RHP_DRIVER::RHP_DRIVER(this,local_40,p_Var5);
    if ((piVar2 != (int *)0x0) && (*piVar2 == 0x52504852)) {
      _fastIoDispatch = 0xe0;
      _DAT_1c0010310 = RHP_GPIO_CONTROLLER::FastIoDeviceControl;
      *(_FAST_IO_DISPATCH **)(param_1 + 0x50) = &RHP_DRIVER::fastIoDispatch;
      if ((undefined8 **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_sDqqL
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xf,
                 &WPP_419322f9da1d39f2056fc5e71d51cd23_Traceguids,
                 "onecore\\base\\basedrv\\rhproxy\\sys\\rhpdriver.cpp",0xc4,uVar6,uVar7,(char)iVar1)
      ;
      return iVar1;
    }
    if ((undefined8 **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  return -0x3fffffff;
}


